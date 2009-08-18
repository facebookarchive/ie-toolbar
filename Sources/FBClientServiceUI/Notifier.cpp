#include "StdAfx.h"

#include "Notifier.h"
#include "NotifierPopup.h"


#include "resource.h"

#include <algorithm>
#include <functional>

#pragma warning(disable : 4180)
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>

#include "../common/ResourceMessages.h"
#include "../common/UrlUtils.h"
#include "../data/ToolbarSettings.h"
#include "../util/ModuleUtils.h"


using namespace std;
using boost::bind;

namespace facebook{
using namespace boost;
using boost::replace_all;

const String GAP = _T(" ");
const String QUOTE = _T("\"");
const String kParamFirst = _T("{1}");
const String kParamSecond = _T("{2}");
// ---------------------------------------------------------------------
// class Notifier
// ---------------------------------------------------------------------
                 

String Notifier::getSquarePicUrl(const UserData& userData) {
  String result = userData.getSquarePicUrl();

  // if user has no picture to display
  // use dafault from resources...

  if (result.empty()) {
    result = buildHtmlResourceUrl(getModuleFileName(AfxGetInstanceHandle())
      , IDR_TDEFAULT);
  }
  return result;
}

void Notifier::showFriendsChangePopup(const DataChangeEvents& changeID,
                                             const FriendsIDs& friendsIds, 
                                             const ServiceData& sourceData) {
  FriendsIDs::const_iterator itFriendIds;
  const FriendsIDs::const_iterator itFriendIdsEnd = friendsIds.end();

  // iterate over friends, and create
  // corresponding popup windows based 
  // on change id

  for(itFriendIds = friendsIds.begin();  itFriendIds != itFriendIdsEnd; ++itFriendIds) {
    String friendID = *itFriendIds;
    FriendsList friendList = sourceData.getFriends();

    FriendsList::const_iterator it = 
      find_if(friendList.begin(), friendList.end(),
      bind(equal_to<String>(), 
      bind(&facebook::UserData::getID, _1), friendID));

    if (it != friendList.end()) {
       switch (changeID) {

      //Note: before create popup with notificaton
      // we should check is corresponding notificatin option
      // is selected by user
         case FBM_FRIEND_UPDATED_STATUS: {
            if (ToolbarSettings::getInstance().readValue(TO_FRIENDUPDATEDSTATUS, false)) {
               Notifier::notifyFriendStatusChanged(it->getName(),
                                                          it->getID(),
                                                          it->getStatusMessage() ,
                                                          getSquarePicUrl(*it));
            }
            break;
           }
         case FBM_I_HAVE_NEW_FRIEND: {
            if (ToolbarSettings::getInstance().readValue(TO_NEWFRIEND, false)) {
            Notifier::notifySoMyFriend(it->getName(),
                                              it->getID(),
                                              getSquarePicUrl(*it));
            }
            break;
           }
         case FBM_SOMEONE_WROTE_ON_A_FRIENDS_WALL: {
            if (ToolbarSettings::getInstance().readValue(TO_FRIENDUPDATEDWALL, false)) {
            Notifier::notifyFriendWallSoWrote(it->getName(), 
                                                     it->getID(),
                                                     getSquarePicUrl(*it));
            }
            break;
           }
         case FBM_FRIEND_WROTE_NOTE: {
            if (ToolbarSettings::getInstance().readValue(TO_FRIENDWROTENOTE, false)) {
            Notifier::notifyFriendWroteNote(it->getName(), 
                                                   it->getID(),
                                                   getSquarePicUrl(*it));
            }
            break;         
           }
         case FBM_FRIEND_UPDATED_PROFILE: {
            if (ToolbarSettings::getInstance().readValue(TO_FRIENDUPDATEDUPROFILE, false)) {
            Notifier::notifyFriendUpdateProfile(it->getName(), 
                                                       it->getID(),
                                                       getSquarePicUrl(*it));
            }
            break;         
           }
         }
      }
   }
}

void Notifier::showAlbumsChangePopup(const DataChangeEvents& changeID,
                                            const AlbumsIDs& albumsIds, 
                                            const ServiceData& sourceData) {
  if (ToolbarSettings::getInstance().readValue(TO_FRIENDUPDATEDALBUMS, false) &&
     (changeID == FBM_FRIEND_ADDED_PHOTO_TO_ALBUM ||
      changeID == FBM_FRIEND_CREATED_ALBUM)) {
    AlbumsIDs::const_iterator itAlbumsIds;
    const AlbumsIDs::const_iterator itAlbumsIdsEnd = albumsIds.end();

    for(itAlbumsIds = albumsIds.begin();  itAlbumsIds != itAlbumsIdsEnd; ++itAlbumsIds) {
      String albumID = *itAlbumsIds;
      AlbumsList albumList = sourceData.getAlbumsList();
      AlbumsList::const_iterator it = 
        find_if(albumList.begin(), albumList.end(),
        bind(equal_to<String>(), bind(&facebook::AlbumData::id_, _1), albumID));

      if (it != albumList.end()) {
        FriendsList friendList = sourceData.getFriends();
        FriendsList::const_iterator itFriend = 
          find_if(friendList.begin(), friendList.end(),
          bind(equal_to<String>(), bind(&facebook::UserData::getID, _1), it->owner_));

          if (itFriend != friendList.end()) {
            Notifier::notifyAlbums(it->name_, 
                                          itFriend->getName(), 
                                          it->link_, 
                                          changeID);
          }
       }
    }
  }
}

void Notifier::showSelfNotification(const DataChangeEvents& changeID, 
                                           const ServiceData& sourceData) {
   switch(changeID) {
    case FBM_I_HAVE_NEW_WALL_POST: {
       if(ToolbarSettings::getInstance().readValue(TO_NEWSMONEWROTEWALL, true)) {
          Notifier::notifyWall(sourceData.getLoggedInUser().getID());
       }
       break;
      }
    case FBM_I_HAVE_NEW_FRIEND_REQUEST: {
      if (ToolbarSettings::getInstance().readValue(TO_NEWFRIENDREQUEST, true)) {

         UsersList userlist = sourceData.getUsersRequestedFriendship();
         UsersList::const_iterator itUserList;
         const UsersList::const_iterator itUserListEnd = userlist.end();

         for (itUserList = userlist.begin();  itUserList != itUserListEnd; ++itUserList) {
            Notifier::notifyFriendsRequest((*itUserList).getName(), 
               getSquarePicUrl(*itUserList));
         }
      }

      break;
     }
   case FBM_I_HAVE_NEW_MESSAGE: {

      if (ToolbarSettings::getInstance().readValue(TO_NEWMESSAGE, true)) {
         // new message notification
         const long messageCount = sourceData.getNotificationsData().getMessageCount();
         Notifier::notifyMessage(messageCount);
      }

      break;
     }

   case FBM_I_HAVE_NEW_POKE: {

      if (ToolbarSettings::getInstance().readValue(TO_NEWPOKE, false)) {

         // new poke notification
         // pokes count
         const long pokeCount = sourceData.getNotificationsData().getPokesCount();
         Notifier::notifyPoke(pokeCount);
      }
      break;
    }

   case FBM_MY_STATUS_UPDATED: {
      // status updated notification
      // status message
      const String text = sourceData.getLoggedInUser().getStatusMessage();
      // current user id
      const String id = sourceData.getLoggedInUser().getID();
      // small pic of current user
      const String userPic = getSquarePicUrl(sourceData.getLoggedInUser());
      Notifier::notifyMyStatus(text, id, userPic);
      break;
    }
   }
}

void Notifier::notifyMyStatus(const String& text, 
                                     const String& id, 
                                     const String& userPic) {
  // read from resources message for notifier
  String msg;
  if (text.size() > 0) {
    msg = ResourceMessages::getMessage(kNotifierYourStatusWasSet, true);
  } else {
    msg = ResourceMessages::getMessage(kNotifierYourStatusWasCleared, true);
  }
  NotifierPopup::addInstance(buildUserStatusUrl(id), 
   userPic, msg);
}

void Notifier::notifyMessage(long msgCount) {

  String msg;
  if (msgCount == 1) {
    msg = ResourceMessages::getMessage(kNotifierYouHaveANewMessage, true);
  } else {
    msg = ResourceMessages::getMessage(kNotifierYouHaveNewMessages, true);
  }
  // source for picture
  const String src = buildHtmlResourceUrl(getModuleFileName(AfxGetInstanceHandle()), 
   IDR_MAIL_REQUEST);

  NotifierPopup::addInstance(buildUserInboxUrl(), src, msg);
}

void Notifier::notifyPoke(long pokeCount) {
   // build from message for notifier
  String msg;

   if (pokeCount > 0) {
      if (1 == pokeCount) {
         msg = ResourceMessages::getMessage(kNotifierYouHaveBeenPoked, true);
      } else if(4 >= pokeCount) {
        msg = ResourceMessages::getMessage(kNotifierYouHaveBeenPokedTimes, true);
        String pokeCountStr = lexical_cast<String>(pokeCount);
        replace_all(msg, kParamFirst, pokeCountStr);
      } else {
        msg = ResourceMessages::getMessage(kNotifierYouHaveBeenPokedManyTimes, true);
      }
   }

   // source for picture
   const String src = buildHtmlResourceUrl(getModuleFileName(AfxGetInstanceHandle()), 
     IDR_POKE);

   NotifierPopup::addInstance(buildPokeFriendUrl(), src, msg);
}

void Notifier::notifyFriendsRequest(const String& userName, const String& userpicPath) {
  // message in notifier
  String msg = ResourceMessages::getMessage(kNotifierSmWantsToBeYourFriend, true);
  replace_all(msg, kParamFirst, userName);

  NotifierPopup::addInstance(buildFriendsRequestUrl(), 
    userpicPath, msg);
}

void Notifier::notifyAlbums(const String& album, 
                                   const String& albumOwner, 
                                   const String& link, 
                                   const DataChangeEvents& changeID) {
  String msg;
  switch(changeID) {
    case FBM_FRIEND_ADDED_PHOTO_TO_ALBUM: {
      msg = ResourceMessages::getMessage(kNotifierSmAddedNewPhotosTo, true);  
      break;
    }
    case FBM_FRIEND_CREATED_ALBUM: {
     msg = ResourceMessages::getMessage(kNotifierSmCreatedTheAlbum, true);  
      break;
    }
   }
   replace_all(msg, kParamFirst, albumOwner);
   replace_all(msg, kParamSecond, QUOTE + album + QUOTE);
   const String src = buildHtmlResourceUrl(getModuleFileName(AfxGetInstanceHandle()), 
     IDR_PHOTO);

   NotifierPopup::addInstance(link, src, msg);
}

void Notifier::notifyWall(const String& userID) {
  const String msg = ResourceMessages::getMessage(kNotifierSmWroteOnYourWall, true);

  // source for picture
  const String src = buildHtmlResourceUrl(getModuleFileName(AfxGetInstanceHandle()), 
    IDR_WALL_POST);

  NotifierPopup::addInstance(buildUserWallUrl(userID), src, msg);
}

void Notifier::notifySoMyFriend(const String& friendName, 
                                       const String& userID, 
                                       const String& friendPic) {
  String msg = ResourceMessages::getMessage(kNotifierSmIsNowYourFriend, true);
  replace_all(msg, kParamFirst, friendName);

  NotifierPopup::addInstance(buildUserProfileUrl(userID), 
    friendPic, msg);
}

void Notifier::notifyFriendStatusChanged(const String& friendName, 
                                                const String& friendID, 
                                                const String& status, 
                                                const String& friendPic) {
  const String msg = friendName + GAP + status;

  NotifierPopup::addInstance(buildUserProfileUrl(friendID), 
    friendPic, msg);
}

void Notifier::notifyFriendWallSoWrote(const String& friendName, 
                                              const String& friendID,
                                              const String& friendPic) {
  String msg = ResourceMessages::getMessage(kNotifierSmWroteOnSmWall, true);
  replace_all(msg, kParamFirst, friendName);

  NotifierPopup::addInstance(buildUserProfileUrl(friendID), 
    friendPic, msg);
}

void Notifier::notifyFriendWroteNote(const String& friendName, 
                                            const String& friendID,
                                            const String& friendPic) {
  String msg = ResourceMessages::getMessage(kNotifierSmWroteANote, true);
  replace_all(msg, kParamFirst, friendName);
  NotifierPopup::addInstance(buildUserNotesUrl(friendID), 
    friendPic, msg);
}


void Notifier::notifyFriendUpdateProfile(const String& friendName, 
                                                const String& friendID,
                                                const String& friendPic) {
  String msg = ResourceMessages::getMessage(kNotifierSmUpdatedHisHerProfile, true);
  replace_all(msg, kParamFirst, friendName);

  NotifierPopup::addInstance(buildUserProfileUrl(friendID), 
    friendPic, msg);
}

} // !namespace facebook
