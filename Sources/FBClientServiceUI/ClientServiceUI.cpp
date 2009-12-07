#include "StdAfx.h"

#pragma warning(disable : 4146)
#pragma warning(disable : 4278) 

#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <boost/algorithm/string/replace.hpp>

#include "CheckUpdatesDlg.h"
#include "LoginDlg.h"
#include "Notifier.h"


#include "../data/ServiceData.h"
#include "../data/NotificationsData.h"
#include "../data/ChangesTypes.h"
#include "../data/ToolbarSettings.h"

#include "../common/CommonConstants.h"
#include "../common/ResourceMessages.h"
#include "../common/URLUtils.h"

#include "../util/BitsUtils.h"
#include "../util/BrowserUtils.h"
#include "../util/COMWrappers.h"
#include "../util/HttpUtils.h"
#include "../util/ModuleUtils.h"
#include "../util/ScopeGuard.h"
#include "../util/StringUtils.h"
#include "../util/ShellUtils.h"


// Note: the functions below are exported and used by
// communication service to display UI based on some events


namespace facebook{

CComModule _Module;

__declspec(dllexport)
void showLoginDialog(const String& loginUrl, ULONG parentWindow, String& cookies) {    

  CWnd *parent = CWnd::FromHandle((HWND)parentWindow);
  // initialize COM for this thread
  CoInitialize(0);
  ScopeGuard coUninitializeGuard(
    boost::bind(CoUninitializeWrapper()));
  if (::IsWindow((HWND)parentWindow)) {
    LoginDlg login(loginUrl, parent);
    login.DoModal();
    cookies = login.getCookies();
  }
}

__declspec(dllexport)
void showSelfNotification(const DataChangeEvents& changeID, 
                          const ServiceData& sourceData) {
  if (ToolbarSettings::getInstance().isPopupEnabled()) {
    Notifier::showSelfNotification(changeID, sourceData);
  }
}

__declspec(dllexport)
void showFriendsChangePopup(const DataChangeEvents& changeID,
                            const FriendsIDs& friendsIds, 
                            const ServiceData& sourceData) {
  if (ToolbarSettings::getInstance().isPopupEnabled()) {
    Notifier::showFriendsChangePopup(changeID, friendsIds, sourceData);
  }
}

__declspec(dllexport)
void showAlbumsChangePopup(const DataChangeEvents& changeID,
                           const AlbumsIDs& albumsIds, 
                           const ServiceData& sourceData) {
  if (ToolbarSettings::getInstance().isPopupEnabled()) {
    Notifier::showAlbumsChangePopup(changeID, albumsIds, sourceData);
  }
}

/**
 * gets the url to the new version
 *
 * @return url to the new version
 */
String getUpdateUrl() {
  using boost::replace_all;
  String updateUrl;
  try {
    String facebookUpdatesUrl = kFacebookUpdatesUrl;
    //get the prefix for debug mode from registry if any
    String updateUrlPrefix = ToolbarSettings::getInstance().readStringValue(TO_UPDATEURLPREFIX);
    if (!updateUrlPrefix.empty()) {
      replace_all(facebookUpdatesUrl, _T("http://www"), updateUrlPrefix);
    }
    String version = getModuleVersion(NULL);
    HttpUtils::doGetRequest(facebookUpdatesUrl + version, updateUrl);
  }
  catch(...) {
  }

  if (updateUrl.empty() ||
    !isCorrectUrl(updateUrl)) {
    // no service available or old version 
      updateUrl = String();
  }
  return updateUrl;
}

__declspec(dllexport)
void showNewVersionAvailablePopup() {
  if (!ToolbarSettings::getInstance().readValue(TO_CHECKUPDATES, true)) {
    // check for updates is disabled
    return;
  }
  CoInitialize(0);
  ScopeGuard coUninitializeGuard(
    boost::bind(CoUninitializeWrapper()));
  String updateUrl = getUpdateUrl();
  String updateFile = getApplicationDataDir() + _T("update.exe"); // temporary name
  if (updateUrl.empty()) {
    // if no new versions available but there are old updates - delete them
    if (PathFileExists(updateFile.c_str())) {
      DeleteFile(updateFile.c_str());
    }
    // no new version available.
    return;
  }
  int updatesCount = 
    ToolbarSettings::getInstance().readIntValue(TO_UPDATESCOUNTER, 0);
  int updatesTimeout =
    ToolbarSettings::getInstance().readIntValue(TO_UPDATESTIMEOUT, kUpdatesTimeoutDefault);
  //if someone set 0
  if (updatesTimeout == 0) {
    updatesTimeout = kUpdatesTimeoutDefault;
  }
  
  BitsUtils bits;
  //check wherer we'are already in progress of download
  BitsUtils::BitsDownloadStatus bitsStatus = 
    bits.checkDownloadStatus(kFacebookUpdateJobName);
  BOOL userResult;

  switch (bitsStatus) {
     case BitsUtils::DOWNLOAD_COMPLETED:
      // show form to install; 
      userResult = CheckUpdatesDlg().DoModal();
      if (userResult == TRUE) {
        if (bits.completeDownload(kFacebookUpdateJobName)) {
          // terminate all Internet Explorer processes
          terminateAllProcesses(kIeProcessName);
          // reset the updates tries
          ToolbarSettings::getInstance().writeValue(
            TO_UPDATESCOUNTER, 0);
          // run the installation file
          execute(updateFile, String());
        } else {
          // if bits completion failed - open in UI
          bits.cancelDownload(kFacebookUpdateJobName);
          BrowserUtils::openUrlNewWindow(updateUrl);
        }
      }
      break;
    case BitsUtils::DOWNLOAD_IN_PROGRESS:
      // check for timeout
      if (bits.isDownloadExpired(kFacebookUpdateJobName, updatesTimeout)) {
          if (updatesCount < kMaxUpdatesTries) {
            ToolbarSettings::getInstance().writeValue(
              TO_UPDATESCOUNTER, ++updatesCount);
            // create new download
          }
          // it won't create download, but open new window
      } else {
        // do nothing - wait for completion
        break;
      }
    case BitsUtils::NO_DOWNLOAD:
      if (updatesCount < kMaxUpdatesTries) {
        // start the updates process
        bool bitsResult = bits.createDownload(kFacebookUpdateJobName, 
                                              updateUrl, 
                                              updateFile);
        if (!bitsResult) {
          ToolbarSettings::getInstance().writeValue(
            TO_UPDATESCOUNTER, ++updatesCount);
        } 
        break;
      }
      // if not created task then cancel download and open in browser
    case BitsUtils::DOWNLOAD_FAILED: 
      // cancel download
      bits.cancelDownload(kFacebookUpdateJobName);
      if (updatesCount < kMaxUpdatesTries) {
        break;
      }
      // open the link with url
      userResult = CheckUpdatesDlg().DoModal();
      if (userResult == TRUE) {
        //if yes then redirect to the url with new version
        BrowserUtils::openUrlNewWindow(updateUrl);
        // maybe following downloads will be sucessfull
        ToolbarSettings::getInstance().writeValue(
            TO_UPDATESCOUNTER, 0);
      }
      break;
  }
}

} // !namespace facebook


