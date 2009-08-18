
#include "RequestsComposer.h"
#include "UpdatesComparator.h"

#include <queue>
#include <boost/bind.hpp>

#include "../../common/UrlUtils.h"

#include "../../util/ComWrappers.h"
#include "../../util/ScopeGuard.h"

namespace facebook{

using namespace ATL;

/**
 *
 * class CommunicationServiceLoop
 *
 * This class is a part of implementation of ClientServices
 * it does not have header file and included to the ClientServiceImpl
 * using #include "CommunicationServiceLoop.cpp"
 * This represents working thread speaks with facebook
 * Each specified period of time it requests facebook users list,
 * and notifications. After all of requested information 
 * is received. It sends it to the subscribers. 
 *
 */
class CommunicationServiceLoop: boost::noncopyable{
   // Construction/destruction
public:
   CommunicationServiceLoop(const DWORD period, 
      CommunicationService* communicator, const DWORD notifiedThread)
      : period_(period)
      , communicator_(communicator)
      , notifiedThread_(notifiedThread)
      , changesAnalyzer_()
      , lastCheckDataTime_(0) {
      using namespace RequestsComposer;

      const String logedInUserID = communicator_->getSessionInfo().uid_;
      getFriendsRequest_.reset(new XMLRequest(
            composeGetFriendsListRequest(logedInUserID)));

      notificationsRequest_.reset(new XMLRequest(
         composeGetNotificationsRequest()));

      const HRESULT initRes = customRequestsCriticalSection.Init();
      if (FAILED(initRes)) {
         _com_raise_error(initRes);
      }

      DWORD tid;
      eventStop_ = ::CreateEvent(0,TRUE,FALSE,NULL);
      eventCustomRequest_ = ::CreateEvent(0,TRUE,FALSE,NULL);
      eventLogout_ = ::CreateEvent(0,TRUE,FALSE,NULL);
      thread_  = ::CreateThread(0,0,thread_proc,this,0,&tid);     
   }

   ~CommunicationServiceLoop() {
      ::SetEvent(eventStop_);
      ::CloseHandle(eventStop_);
      ::CloseHandle(eventCustomRequest_);
      ::CloseHandle(thread_);
   }

   // methods
public:
   
   void postShutdown() {
      ::SetEvent(eventLogout_);
   }

   
   void postLogout() {
      ::SetEvent(eventLogout_);
   }
   
   bool hasSetStatusPermission() {
      // ensure that asker doesn't update the data now
      // and communication thread is sleeping
      ScopeGuard fbCritSectGuard(
         bind(&CComCriticalSection::Lock, ref(facebookDataCritSect)),
         bind(&CComCriticalSection::Unlock, ref(facebookDataCritSect)));

      return communicator_->hasSetStatusPermission();
   }


   void postCustomRequest(const XMLRequest& request) {
      ScopeGuard fbCritSectGuard(
         bind(&CComCriticalSection::Lock, ref(customRequestsCriticalSection)),
         bind(&CComCriticalSection::Unlock, ref(customRequestsCriticalSection)));

      requestsQueue_.push(request);
      ::SetEvent(eventCustomRequest_);
   }

private:

  /**
   * Main communication thread.
   *
   * @param lpParameter not used (by pointer)
   */
   
  static DWORD WINAPI thread_proc(LPVOID lpParameter) {

      CoInitialize(NULL);

      ScopeGuard coUninitializeGuard(boost::bind(CoUninitializeWrapper()));

      CommunicationServiceLoop* comparator_ =
            reinterpret_cast<CommunicationServiceLoop*>(lpParameter);

      // attach to object
      std::auto_ptr<CommunicationServiceLoop> this_(comparator_);
 
      // first time start immediately
      DWORD period = 0;

      const HANDLE waitHandles[3] = {this_->eventStop_, 
         this_->eventCustomRequest_, this_->eventLogout_};

        
      while(true) {
         const DWORD waitResult = ::MsgWaitForMultipleObjects(3,
            &waitHandles[0], FALSE, period, QS_ALLINPUT);

         const bool initialUpdate = period == 0;

         ScopeGuard fbCritSectGuard(
            bind(&CComCriticalSection::Lock, ref(facebookDataCritSect)),
            bind(&CComCriticalSection::Unlock, ref(facebookDataCritSect)));

         if (waitResult == WAIT_OBJECT_0) { // shutdown event
            break;
         }

         if (waitResult == WAIT_OBJECT_0 + 1) { // custom requests event
            ResetEvent(this_->eventCustomRequest_);
         }

         if (waitResult == WAIT_OBJECT_0 + 2) { // logout event
            ResetEvent(this_->eventLogout_);
            this_->communicator_->logout();
            break;
         }

         try{ 
            this_->processCustomRequests();

            const ServiceData newData = this_->retrieveData();
            
            UpdatesComparator& changesAnalyzer = this_->changesAnalyzer_;
            
            ChangeEventsQueue toolbarNotifications = 
               changesAnalyzer.getToolbarDataChanges(newData, _currentData);

            if (!initialUpdate) {

                FriendsChangeEventsQueue friendsChangesPopupNotifications = 
                     changesAnalyzer.getFriendsChanges(newData, _currentData);

                ChangeEventsQueue popupSelfNotifications = 
                     changesAnalyzer.getSelfChanges(newData, _currentData);

                EventsToAlbumsIDsQueue albumsPopupNotifications = 
                     changesAnalyzer.getAlbumsChanges(newData, _currentData);
            
                _popupSelfNotifications.swap(popupSelfNotifications);
                _friendsChangesPopupNotifications.swap(friendsChangesPopupNotifications);
                _albumsChanges.swap(albumsPopupNotifications);
            }

            if (initialUpdate) {
               toolbarNotifications.push_front(FBM_JUST_LOGGED_IN);
            }
			      //store the cookies if any
            String cookies = _currentData.getLoggedInUser().getLoginCookies();
            _currentData = newData;
            _currentData.setLoginCookies(cookies);

            _toolbarNotifications.swap(toolbarNotifications);

            this_->fireDataCollected();
         }
         catch(ResponseParser::ErrorInResponse) {
            // TODO : log it here
         }
         catch(XMLUtils::ParseError&) {
            // TODO : log it here
         }
         catch(_com_error e) {
            // TODO : log it here
         } 
         catch(...) {
            // TODO : log it here
         }

         // first pass completed. Use time period for all 
         // consequent iteration 
         period = this_->period_; 
      }

      return 0;
   }

   AlbumsList buildActualAlbumsList(const AlbumsList& newAlbums, 
     const AlbumsList& currentAlbums) {
      AlbumsList actualAlbums = currentAlbums;     
      AlbumsList::const_iterator itAlbums;
      const AlbumsList::const_iterator itAlbumsEnd = newAlbums.end();

      for (itAlbums = newAlbums.begin(); itAlbums != itAlbumsEnd; ++itAlbums) {
         const AlbumData& newAlbum = *itAlbums;  

         AlbumsList::iterator foundAlbum = 
            find_if(actualAlbums.begin(), actualAlbums.end(),
               bind(equal_to<String>(), bind(&facebook::AlbumData::id_, _1), newAlbum.id_));

         if (foundAlbum != actualAlbums.end()) { // album already existed
            (*foundAlbum) = newAlbum;
         } else { // new album
            actualAlbums.push_back(newAlbum);
         }
      }

      return actualAlbums;
   }

   void processCustomRequests() {
      ScopeGuard fbCritSectGuard(
         bind(&CComCriticalSection::Lock, ref(customRequestsCriticalSection)),
         bind(&CComCriticalSection::Unlock, ref(customRequestsCriticalSection)));

      while(!requestsQueue_.empty()) {
         XMLRequest req = requestsQueue_.front();
         
         String response;
         communicator_->executeRequest(req, response);
         requestsQueue_.pop();
      }
   }

   ServiceData retrieveData() {
      FriendsList newFriends = getFriends();

      const String userID = communicator_->getSessionInfo().uid_;

      const UserData loggedInUser = removeLoggedInUser(userID, newFriends);

      const NotificationsData nofiticationsData = getNotificationsData();

      AlbumsList newAlbums = getAlbums();
      
      const bool initialUpdate = period_ == 0;
      
      if (!initialUpdate) {
         newAlbums = buildActualAlbumsList(newAlbums,
            _currentData.getAlbumsList());
      }

      const UsersList usersRequestedFriendShip = getUsersRequestedFriendship(
         nofiticationsData.getUsersRequestedFriendShipIDs());
      
      return ServiceData(nofiticationsData, newFriends,
            loggedInUser, newAlbums, usersRequestedFriendShip);
   }

   void fireDataCollected() {
      if (!_toolbarNotifications.empty() ||
          !_friendsChangesPopupNotifications.empty() ||
          !_popupSelfNotifications.empty() ||
          !_albumsChanges.empty()) {
         ::PostThreadMessage(notifiedThread_, FCS_DATA_COLLECTED, 0, 0);
      }
   }

   UserData removeLoggedInUser(const String& logedInUserID, 
     FriendsList& friends) {
      FriendsList::iterator itLogedInUser = 
            find_if(friends.begin(), friends.end(),
               bind(equal_to<String>(), 
               bind(&facebook::UserData::getID, _1), 
                  logedInUserID));

      const UserData logedInUser = *itLogedInUser;
      friends.erase(itLogedInUser);
      return logedInUser;
   }

   NotificationsData getNotificationsData() {
      String resp;
      communicator_->executeRequest(*notificationsRequest_.get(), resp);
      return ResponseParser::parseGetNotificationsDataResponse(resp);
   }

   FriendsList getFriends() {
      String resp;
      communicator_->executeRequest(*getFriendsRequest_.get(), resp);
      return ResponseParser::parseFriendsListResp(resp);
   }

   FriendsList getUsersRequestedFriendship(const UsersIDs& usersIDs) {
     if (usersIDs.empty()) {
       return FriendsList();
     }

      String resp;
      XMLRequest usersInfoGetRequest = 
         RequestsComposer::composeGetUsersInfoRequest(usersIDs);

      communicator_->executeRequest(usersInfoGetRequest, resp);

      return ResponseParser::parseUsersInfoResp(resp);
   }

   AlbumsList getAlbums() {
      const String loggedInUserID = communicator_->getSessionInfo().uid_;

      DWORD interval = 0;
      DWORD now = timeGetTime();
      if (lastCheckDataTime_ > 0) {
        interval = (now - lastCheckDataTime_) / 1000;
      }

      lastCheckDataTime_ = now;

      XMLRequest getAlbumsRequest = RequestsComposer::composeGetAlbumsRequest(loggedInUserID, interval);

      String resp;
      communicator_->executeRequest(getAlbumsRequest, resp);

      return ResponseParser::parseGetAlbumsResponse(resp, 
         interval == 0);
   }

   // members 
private:

   static CComCriticalSection customRequestsCriticalSection;
   static std::queue<XMLRequest> requestsQueue_;
   
   DWORD  period_;
   HANDLE thread_;
   HANDLE eventStop_;
   HANDLE eventCustomRequest_;
   HANDLE eventLogout_;
   const DWORD notifiedThread_;
   
   //ClientServiceImpl::Observers observers_;
   std::auto_ptr<CommunicationService> communicator_;
   std::auto_ptr<XMLRequest> getFriendsRequest_;
   std::auto_ptr<XMLRequest> notificationsRequest_;
   UpdatesComparator changesAnalyzer_;
   DWORD lastCheckDataTime_;

};

CComCriticalSection CommunicationServiceLoop::customRequestsCriticalSection;
std::queue<XMLRequest> CommunicationServiceLoop::requestsQueue_;

} // !namespace facebook
