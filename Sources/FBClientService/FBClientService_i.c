

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0499 */
/* at Sat Nov 28 15:28:43 2009
 */
/* Compiler settings for .\FBClientService.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IFBClientService,0x72E79C06,0x3ABF,0x4C54,0x91,0xCE,0x5D,0xD6,0x3E,0xE6,0x70,0x06);


MIDL_DEFINE_GUID(IID, LIBID_FBClientServiceLib,0x457BCC59,0xE8CE,0x44BD,0xB1,0x97,0x0F,0xAD,0x2B,0x87,0x5F,0xCF);


MIDL_DEFINE_GUID(IID, DIID_IFBClientServiceEvents,0xA821A7CC,0xABC7,0x4A90,0x89,0x6B,0xEA,0x77,0x10,0xC5,0x7B,0x77);


MIDL_DEFINE_GUID(CLSID, CLSID_FBClientService,0xE051840E,0x5790,0x4795,0xB3,0xC8,0xDC,0xBF,0xCF,0xE3,0x03,0xD8);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



