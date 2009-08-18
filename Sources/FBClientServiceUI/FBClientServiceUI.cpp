// FBClientServiceUI.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "FBClientServiceUI.h"

#include "../common/ResourceMessages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFBClientServiceUIApp

BEGIN_MESSAGE_MAP(CFBClientServiceUIApp, CWinApp)
END_MESSAGE_MAP()


// CFBClientServiceUIApp construction

CFBClientServiceUIApp::CFBClientServiceUIApp() {
}


// The one and only CFBClientServiceUIApp object

CFBClientServiceUIApp theApp;


// CFBClientServiceUIApp initialization

BOOL CFBClientServiceUIApp::InitInstance() {
  // load the cultures. need this here because automatic 
    // loading is made too early and we have no acees to the resources
  facebook::ResourceMessages::getInstance().load();
  CWinApp::InitInstance();
  return TRUE;
}
