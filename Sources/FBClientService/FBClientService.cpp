#include "StdAfx.h"

#pragma warning(disable : 4146)
#pragma warning(disable : 4278) 
#include <boost/bind.hpp>

#include "FBClientService_i.h"
#include "ClientServiceMessages.h"

#include "../common/CommonConstants.h"

#include "../util/BitsUtils.h"
#include "../util/COMWrappers.h"
#include "../util/ModuleUtils.h"
#include "../util/RegistryUtils.h"
#include "../util/ScopeGuard.h"
#include "../util/ShellUtils.h"
#include "../util/SessionUtils.h"
#include "../util/StringUtils.h"

using namespace ATL;

#include "ClientService.h"
#include "comdef.h"

extern facebook::ClientService* clientService;

namespace facebook {

class ClientServiceModule :
      public ATL::CAtlExeModuleT<ClientServiceModule> {

public :

  DECLARE_LIBID(LIBID_FBClientServiceLib)

  DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FBCLIENTSERVICE,
         "{4972D2C4-98FF-46A6-B39C-12A01345E7E8}")
  
   void RunMessageLoop() throw() {
      MSG msg;
      while (GetMessage(&msg, 0, 0, 0) > 0) {

         if (msg.message  == FCS_DATA_COLLECTED) {

            if (clientService != NULL) {
              try {
               clientService->fireUpdates();
               continue;
              }
              catch (...) {
                 break;
              }
            }
         }
         TranslateMessage(&msg);
         DispatchMessage(&msg);
      }
      terminateAllProcesses(getModuleFileNameOnly());
   }
};

}



facebook::ClientServiceModule atlModule;
typedef std::vector<facebook::RegStrEntry> RegStrEntriesVector;

void deletePostSetupEntries() {
  using namespace facebook;
  RegStrEntriesVector entries;
  entries.push_back(RegStrEntry(HKEY_CLASSES_ROOT, 
    _T("Component Categories\\{00021493-0000-0000-C000-000000000046}\\Enum"), 
    _T(""), _T("")));
  entries.push_back(RegStrEntry(HKEY_CLASSES_ROOT, 
    _T("Component Categories\\{00021494-0000-0000-C000-000000000046}\\Enum"), 
    _T(""), _T("")));
  entries.push_back(RegStrEntry(HKEY_CURRENT_USER, 
    _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Discardable\\PostSetup\\Component Categories\\{00021493-0000-0000-C000-000000000046}\\Enum"), 
    _T(""), _T("")));
  entries.push_back(RegStrEntry(HKEY_CURRENT_USER, 
    _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Discardable\\PostSetup\\Component Categories\\{00021494-0000-0000-C000-000000000046}\\Enum"), 
    _T(""), _T("")));

  bool result = false;
  for (unsigned int i = 0; i < entries.size(); ++i) {
     result = entries[i].removeKey();
  }
}

extern "C"
int WINAPI _tWinMain(HINSTANCE, HINSTANCE,
      LPTSTR commandLine, int showCmd) {
  using namespace facebook;

  String parameters = commandLine;
  // if there is a register call - just register and exit
  if (parameters.find(_T("-register")) != facebook::String.npos) {
    atlModule.RegisterAppId();
    atlModule.RegisterServer(TRUE);
    //clear all updates that were downloaded previously
    //TODO: move to AutoupdateManager
    CoInitialize(0);
    ScopeGuard coUninitializeGuard(
    boost::bind(CoUninitializeWrapper()));
    BitsUtils bits;
    bits.cancelDownload(kFacebookUpdateJobName);
	  deletePostSetupEntries();
    terminateAllProcesses(getModuleFileNameOnly());

    return 0;
  }
  // if there is a unregister call - just register and exit
  if (parameters.find(_T("-unregister")) != facebook::String.npos) {
    atlModule.UnregisterAppId();
    atlModule.UnregisterServer(TRUE);
    //clear all updates that were downloaded previously
    //TODO: move to AutoupdateManager
    CoInitialize(0);
    ScopeGuard coUninitializeGuard(
    boost::bind(CoUninitializeWrapper()));
    BitsUtils bits;
    bits.cancelDownload(kFacebookUpdateJobName);
    terminateAllProcesses(getModuleFileNameOnly());

    return 0;
  }
  // if there is an closeall call - just close all the exes and exit
  if (parameters.find(_T("-closeall")) != facebook::String.npos) {
    terminateAllProcesses(getModuleFileNameOnly());
    return 0;
  }

  // keep updating the registration information during each call
  atlModule.UpdateRegistryAppId(TRUE); 
  atlModule.RegisterServer(TRUE);
  return atlModule.WinMain(showCmd);
}
