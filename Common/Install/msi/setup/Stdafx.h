#ifndef STDAFX_H
#define STDAFX_H

#undef _AFXDLL

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

// Exclude rarely-used stuff from Windows headers
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#include "Targetver.h"

// some CString constructors will be explicit
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

// MFC core and standard components
#include <afxwin.h>
// MFC extensions
#include <afxext.h>
// MFC Automation classes
#include <afxdisp.h>


// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>
#endif

// MFC support for Windows Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>
#endif // _AFX_NO_AFXCMN_SUPPORT

// MFC support for ribbons and control bars
#include <afxcontrolbars.h>

#endif // STDAFX_H
