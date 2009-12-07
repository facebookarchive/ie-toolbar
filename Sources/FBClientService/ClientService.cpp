#include "StdAfx.h"

using namespace ATL;

#include "ClientService.h"
#include "ClientServiceImpl.h"

#include <comdef.h>
#include <comdefsp.h>
#include <boost/bind.hpp>

#include "../FBClientServiceUI/ClientServiceUI.h"

#include "../data/ToolbarSettings.h"

#include "../common/CommonConstants.h"
#include "../common/DataChangeEvents.h"
#include "../util/ScopeGuard.h"
#include "../util/COMWrappers.h"

using namespace facebook;


namespace{
   /**
   *  Helper method initialize instance of FBUserData
   *  base on UserData
   */
void initializeFBUserData(const UserData& userData, FBUserData& fbUsr) {
  const _bstr_t friendID = toBSTR(userData.getID());
  const _bstr_t name = toBSTR(userData.getName());
  const _bstr_t picSmall = toBSTR(userData.getSmallPicUrl());
  const _bstr_t picSq = toBSTR(userData.getSquarePicUrl() );
  const _bstr_t status = toBSTR(userData.getStatusMessage());
  const _bstr_t cookies = toBSTR(userData.getLoginCookies());

  fbUsr.id = SysAllocString(friendID);

  if (!fbUsr.name)
     SysFreeString(fbUsr.name);

  fbUsr.name = SysAllocString(name);

  if (!fbUsr.pic)
     SysFreeString(fbUsr.pic);
  fbUsr.pic = SysAllocString(picSmall);

  if (!fbUsr.pic_sq)
     SysFreeString(fbUsr.pic_sq);
  fbUsr.pic_sq = SysAllocString(picSq);

  if (!fbUsr.status)
     SysFreeString(fbUsr.status);
  fbUsr.status = SysAllocString(status);

  if (!fbUsr.cookies)
     SysFreeString(fbUsr.cookies);
  fbUsr.cookies = SysAllocString(cookies);

  fbUsr.notes = userData.getNotesCount();
  fbUsr.wall = userData.getWallPostsCount();
  fbUsr.stime = userData.getStatusUpdateTime();
  fbUsr.ptime = userData.getProfileUdatedTime();
}

}


// do no change the name of this variable to 
// do not violate one definition rule. clientService
// is used by FBClientServiceModule

facebook::ClientService* clientService;

DWORD WINAPI threadCheckForUpdatesHandler(LPVOID lpParameter) {
  UNREFERENCED_PARAMETER(lpParameter);
  showNewVersionAvailablePopup();
  return 0;
}

void checkForUpdates() {
  DWORD threadId;
  CloseHandle(CreateThread(NULL, NULL, threadCheckForUpdatesHandler, NULL, NULL, &threadId));  
}

ClientService::ClientService():
   service_(new ClientServiceImpl()) {
   clientService = this;
   checkForUpdates();
}


ClientService::~ClientService() {
}


HRESULT ClientService::FinalConstruct() {
   return S_OK;
}


void ClientService::FinalRelease() {
}


STDMETHODIMP ClientService::InterfaceSupportsErrorInfo(REFIID interfaceId) {
  static const IID* arr[] = {
    &IID_IFBClientService
  };

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
 {
    if (InlineIsEqualGUID(*arr[i], interfaceId))
      return S_OK;
  }

  return S_FALSE;
}


// C74DDA8C-4B3D-4ca2-A4F2-5250AA9459DB
const IID IID_FBUserData = 
     {0xc74dda8c, 0x4b3d, 0x4ca2,
     {0xa4, 0xf2, 0x52, 0x50, 0xaa, 0x94, 0x59, 0xdb}};


// TODO: add exception processing to each STDMETHODIMP below
STDMETHODIMP ClientService::getPokesCount(ULONG* pokesCount) {
  try{
    *pokesCount = service_->getPokesCount();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }
  return S_OK;
}


STDMETHODIMP facebook::ClientService::getMessagesCount(ULONG* messagesCount) {
  try{
    *messagesCount = service_->getMessageCount();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }
  return S_OK;
}

STDMETHODIMP facebook::ClientService::getRequestsCount(ULONG* requestsCount) {
  try{
    *requestsCount = service_->getRequestsCount();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}

STDMETHODIMP facebook::ClientService::getEventsCount(ULONG* eventsCount) {
  try{
    *eventsCount = service_->getEventsCount();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}


STDMETHODIMP facebook::ClientService::getGroupsInvsCount(ULONG* groupsInvsCount) {
  try{
     *groupsInvsCount = service_->getGroupsInvsCount();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }
  return S_OK;
}


STDMETHODIMP ClientService::getUser(FBUserData* userData) {
  try{
    FBUserData& data = *userData;

    UserData loggedInUser = service_->getLoggedInUser();

    initializeFBUserData(loggedInUser, data);

  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}


STDMETHODIMP ClientService::getFriends(SAFEARRAY** friendsData) {
  try{
    const FriendsList friends = service_->getFriends();
    const size_t friensNumber = friends.size();

    IRecordInfoPtr recordInfo;
    const HRESULT getRecordInfoRes = GetRecordInfoFromGuids(LIBID_FBClientServiceLib, 1, 0, 0,
       IID_FBUserData, &recordInfo);
    if (FAILED(recordInfo)) {
       _com_raise_error(getRecordInfoRes);
    }

    SAFEARRAYBOUND bound[1];
    bound[0].lLbound = 0;
    bound[0].cElements = friensNumber;
    *friendsData = SafeArrayCreateEx(VT_RECORD, 1, bound, recordInfo);

    FBUserData* friendDataPtr = 0;
    const HRESULT safeArrayAccessDataRes = SafeArrayAccessData(*friendsData,
       reinterpret_cast<void**>(&friendDataPtr));

    ScopeGuard safeUnacessGuard(boost::bind(SafeArrayUnaccessDataWrapper(),
       boost::ref(*friendsData)));

    if (FAILED(safeArrayAccessDataRes)) {
       _com_raise_error(safeArrayAccessDataRes);
    }

    for (size_t i = 0; i < friensNumber; ++i, ++friendDataPtr) {
       FBUserData& friendData = *friendDataPtr;
       initializeFBUserData(friends[i], friendData);
    }
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}


STDMETHODIMP facebook::ClientService::setStatus(BSTR statusMessage) {
  try{
    _bstr_t statusMessageHolder(statusMessage, false);
    service_->setStatus(toString(statusMessageHolder) );
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}


STDMETHODIMP facebook::ClientService::login(ULONG parentWindow) {
  try{
    service_->login(parentWindow);
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}


STDMETHODIMP facebook::ClientService::logout(void) {
  try{
    service_->logout();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;

}


STDMETHODIMP facebook::ClientService::isLoggedIn(USHORT* loggedIn) {
  try{
    *loggedIn = service_->isLoggedIn();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}


void ClientService::fireUpdates() {
   service_->FireUpdates(this);
}


STDMETHODIMP facebook::ClientService::canChangeStatus(USHORT* allowed) {
  try{
    *allowed = service_->canChangeStatus();
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}

STDMETHODIMP facebook::ClientService::updateView(ULONG changeId)
{
  try{
    service_->updateView(changeId);
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}

STDMETHODIMP facebook::ClientService::setSession(BSTR session) {
  try{
    _bstr_t sessionHolder(session, false);
    service_->setSession(toString(sessionHolder) );
  }
  catch(_com_error& e) {
    return e.Error();
  }
  catch(...) {
    return E_FAIL;
  }

  return S_OK;
}
