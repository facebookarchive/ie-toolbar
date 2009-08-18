// FBClientServiceUI.h : main header file for the FBClientServiceUI DLL
//
#ifndef FBCLIENTSERVICEUI_H
#define FBCLIENTSERVICEUI_H

#ifndef __AFXWIN_H__
  #error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"    // main symbols


// CFBClientServiceUIApp
// See FBClientServiceUI.cpp for the implementation of this class
//

class CFBClientServiceUIApp : public CWinApp {
public:
  CFBClientServiceUIApp();

// Overrides
public:
  virtual BOOL InitInstance();

  DECLARE_MESSAGE_MAP()
};

#endif
