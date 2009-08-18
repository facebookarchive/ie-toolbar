#ifndef STDAFX_H
#define STDAFX_H

// Exclude rarely-used stuff from Windows headers
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#include "targetver.h"

// Some CString constructors will be explicit
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

// MFC core and standard components
#include <afxwin.h>
//#include <afxwinappex.h>
//#include <afxtoolbar.h>

// MFC extensions
#include <afxext.h>

// MFC support for OLE
#ifndef _AFX_NO_OLE_SUPPORT
// MFC OLE classes
#include <afxole.h>
// MFC OLE dialog classes
#include <afxodlgs.h>
// MFC Automation classes
#include <afxdisp.h>
// MFC support for Internet Explorer 4 Common Controls
#include <afxdtctl.h>
#endif // _AFX_NO_OLE_SUPPORT

// MFC ODBC database classes
#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>
#endif // _AFX_NO_DB_SUPPORT

// MFC DAO database classes
#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>
#endif // _AFX_NO_DAO_SUPPORT

// MFC support for Windows Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <atlbase.h>
#include <atlcom.h>
#include <comdef.h>
#include <comdefsp.h>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <afxhtml.h>
#include <afxdhtml.h>

#endif // STDAFX_H
