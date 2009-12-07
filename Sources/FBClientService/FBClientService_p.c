

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "FBClientService_i.h"

#define TYPE_FORMAT_STRING_SIZE   1125                              
#define PROC_FORMAT_STRING_SIZE   499                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _FBClientService_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } FBClientService_MIDL_TYPE_FORMAT_STRING;

typedef struct _FBClientService_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } FBClientService_MIDL_PROC_FORMAT_STRING;

typedef struct _FBClientService_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } FBClientService_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const FBClientService_MIDL_TYPE_FORMAT_STRING FBClientService__MIDL_TypeFormatString;
extern const FBClientService_MIDL_PROC_FORMAT_STRING FBClientService__MIDL_ProcFormatString;
extern const FBClientService_MIDL_EXPR_FORMAT_STRING FBClientService__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFBClientService_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFBClientService_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const FBClientService_MIDL_PROC_FORMAT_STRING FBClientService__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure getPokesCount */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x24 ),	/* 36 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pokesCount */

/* 24 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure getUser */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 54 */	NdrFcShort( 0x15 ),	/* 21 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter userData */

/* 60 */	NdrFcShort( 0xa113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=40 */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure getFriends */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 88 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 90 */	NdrFcShort( 0x20 ),	/* 32 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usersData */

/* 96 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	NdrFcShort( 0x448 ),	/* Type Offset=1096 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure getMessagesCount */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0xa ),	/* 10 */
/* 116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x24 ),	/* 36 */
/* 122 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 124 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter messagesCount */

/* 132 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure getRequestsCount */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0xb ),	/* 11 */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x24 ),	/* 36 */
/* 158 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter requestsCount */

/* 168 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure getEventsCount */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xc ),	/* 12 */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x24 ),	/* 36 */
/* 194 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter eventsCount */

/* 204 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure getGroupsInvsCount */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0xd ),	/* 13 */
/* 224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x24 ),	/* 36 */
/* 230 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 232 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter groupsInvsCount */

/* 240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure login */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0xe ),	/* 14 */
/* 260 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 268 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter parentWindow */

/* 276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure logout */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0xf ),	/* 15 */
/* 296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure isLoggedIn */

/* 318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x10 ),	/* 16 */
/* 326 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x22 ),	/* 34 */
/* 332 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 334 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter loggedIn */

/* 342 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 344 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 346 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure setStatus */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x11 ),	/* 17 */
/* 362 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 370 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x1 ),	/* 1 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter statusMessage */

/* 378 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 380 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 382 */	NdrFcShort( 0x45a ),	/* Type Offset=1114 */

	/* Return value */

/* 384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 386 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure canChangeStatus */

/* 390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x12 ),	/* 18 */
/* 398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x22 ),	/* 34 */
/* 404 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 406 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter allowed */

/* 414 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 416 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 418 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure updateView */

/* 426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x13 ),	/* 19 */
/* 434 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 440 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 442 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter changeId */

/* 450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 458 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure setSession */

/* 462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x14 ),	/* 20 */
/* 470 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 476 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 478 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x5 ),	/* 5 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter session */

/* 486 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 488 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 490 */	NdrFcShort( 0x45a ),	/* Type Offset=1114 */

	/* Return value */

/* 492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const FBClientService_MIDL_TYPE_FORMAT_STRING FBClientService__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  8 */	NdrFcShort( 0x26 ),	/* Offset= 38 (46) */
/* 10 */	
			0x13, 0x0,	/* FC_OP */
/* 12 */	NdrFcShort( 0xe ),	/* Offset= 14 (26) */
/* 14 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 16 */	NdrFcShort( 0x2 ),	/* 2 */
/* 18 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 20 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 22 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 24 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 26 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
/* 30 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (14) */
/* 32 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 34 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 36 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x4 ),	/* 4 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0xffde ),	/* Offset= -34 (10) */
/* 46 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 48 */	NdrFcShort( 0x28 ),	/* 40 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* Offset= 0 (52) */
/* 54 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 56 */	NdrFcShort( 0xffec ),	/* Offset= -20 (36) */
/* 58 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 60 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (36) */
/* 62 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 64 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (36) */
/* 66 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 68 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (36) */
/* 70 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 72 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (36) */
/* 74 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 76 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 78 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 80 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (36) */
/* 82 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 84 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 86 */	NdrFcShort( 0x3f2 ),	/* Offset= 1010 (1096) */
/* 88 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 90 */	NdrFcShort( 0x2 ),	/* Offset= 2 (92) */
/* 92 */	
			0x13, 0x0,	/* FC_OP */
/* 94 */	NdrFcShort( 0x3d8 ),	/* Offset= 984 (1078) */
/* 96 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 98 */	NdrFcShort( 0x18 ),	/* 24 */
/* 100 */	NdrFcShort( 0xa ),	/* 10 */
/* 102 */	NdrFcLong( 0x8 ),	/* 8 */
/* 106 */	NdrFcShort( 0x5a ),	/* Offset= 90 (196) */
/* 108 */	NdrFcLong( 0xd ),	/* 13 */
/* 112 */	NdrFcShort( 0x90 ),	/* Offset= 144 (256) */
/* 114 */	NdrFcLong( 0x9 ),	/* 9 */
/* 118 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (312) */
/* 120 */	NdrFcLong( 0xc ),	/* 12 */
/* 124 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (824) */
/* 126 */	NdrFcLong( 0x24 ),	/* 36 */
/* 130 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (872) */
/* 132 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 136 */	NdrFcShort( 0x302 ),	/* Offset= 770 (906) */
/* 138 */	NdrFcLong( 0x10 ),	/* 16 */
/* 142 */	NdrFcShort( 0x31c ),	/* Offset= 796 (938) */
/* 144 */	NdrFcLong( 0x2 ),	/* 2 */
/* 148 */	NdrFcShort( 0x336 ),	/* Offset= 822 (970) */
/* 150 */	NdrFcLong( 0x3 ),	/* 3 */
/* 154 */	NdrFcShort( 0x350 ),	/* Offset= 848 (1002) */
/* 156 */	NdrFcLong( 0x14 ),	/* 20 */
/* 160 */	NdrFcShort( 0x36a ),	/* Offset= 874 (1034) */
/* 162 */	NdrFcShort( 0xffff ),	/* Offset= -1 (161) */
/* 164 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 166 */	NdrFcShort( 0x4 ),	/* 4 */
/* 168 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 174 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 176 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 178 */	NdrFcShort( 0x4 ),	/* 4 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x1 ),	/* 1 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	0x13, 0x0,	/* FC_OP */
/* 190 */	NdrFcShort( 0xff5c ),	/* Offset= -164 (26) */
/* 192 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 194 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 196 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 200 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 202 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 204 */	NdrFcShort( 0x4 ),	/* 4 */
/* 206 */	NdrFcShort( 0x4 ),	/* 4 */
/* 208 */	0x11, 0x0,	/* FC_RP */
/* 210 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (164) */
/* 212 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 214 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 216 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 228 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 230 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 232 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 234 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 244 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 248 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 250 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 252 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (216) */
/* 254 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 256 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x6 ),	/* Offset= 6 (268) */
/* 264 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 266 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 268 */	
			0x11, 0x0,	/* FC_RP */
/* 270 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (234) */
/* 272 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 274 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 282 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 284 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 286 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 288 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 290 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 300 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 304 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 306 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 308 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (272) */
/* 310 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 312 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x6 ),	/* Offset= 6 (324) */
/* 320 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 322 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 324 */	
			0x11, 0x0,	/* FC_RP */
/* 326 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (290) */
/* 328 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 330 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 332 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 334 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 336 */	NdrFcShort( 0x2 ),	/* Offset= 2 (338) */
/* 338 */	NdrFcShort( 0x10 ),	/* 16 */
/* 340 */	NdrFcShort( 0x2f ),	/* 47 */
/* 342 */	NdrFcLong( 0x14 ),	/* 20 */
/* 346 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 348 */	NdrFcLong( 0x3 ),	/* 3 */
/* 352 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 354 */	NdrFcLong( 0x11 ),	/* 17 */
/* 358 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 360 */	NdrFcLong( 0x2 ),	/* 2 */
/* 364 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 366 */	NdrFcLong( 0x4 ),	/* 4 */
/* 370 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 372 */	NdrFcLong( 0x5 ),	/* 5 */
/* 376 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 378 */	NdrFcLong( 0xb ),	/* 11 */
/* 382 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 384 */	NdrFcLong( 0xa ),	/* 10 */
/* 388 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 390 */	NdrFcLong( 0x6 ),	/* 6 */
/* 394 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (626) */
/* 396 */	NdrFcLong( 0x7 ),	/* 7 */
/* 400 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 402 */	NdrFcLong( 0x8 ),	/* 8 */
/* 406 */	NdrFcShort( 0xfe74 ),	/* Offset= -396 (10) */
/* 408 */	NdrFcLong( 0xd ),	/* 13 */
/* 412 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (216) */
/* 414 */	NdrFcLong( 0x9 ),	/* 9 */
/* 418 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (272) */
/* 420 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 424 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (632) */
/* 426 */	NdrFcLong( 0x24 ),	/* 36 */
/* 430 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (640) */
/* 432 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 436 */	NdrFcShort( 0xcc ),	/* Offset= 204 (640) */
/* 438 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 442 */	NdrFcShort( 0xfc ),	/* Offset= 252 (694) */
/* 444 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 448 */	NdrFcShort( 0xfa ),	/* Offset= 250 (698) */
/* 450 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 454 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (702) */
/* 456 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 460 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (706) */
/* 462 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 466 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (710) */
/* 468 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 472 */	NdrFcShort( 0xf2 ),	/* Offset= 242 (714) */
/* 474 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 478 */	NdrFcShort( 0xdc ),	/* Offset= 220 (698) */
/* 480 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 484 */	NdrFcShort( 0xda ),	/* Offset= 218 (702) */
/* 486 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 490 */	NdrFcShort( 0xe4 ),	/* Offset= 228 (718) */
/* 492 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 496 */	NdrFcShort( 0xda ),	/* Offset= 218 (714) */
/* 498 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 502 */	NdrFcShort( 0xdc ),	/* Offset= 220 (722) */
/* 504 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 508 */	NdrFcShort( 0xda ),	/* Offset= 218 (726) */
/* 510 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 514 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (730) */
/* 516 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 520 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (734) */
/* 522 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 526 */	NdrFcShort( 0xdc ),	/* Offset= 220 (746) */
/* 528 */	NdrFcLong( 0x10 ),	/* 16 */
/* 532 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 534 */	NdrFcLong( 0x12 ),	/* 18 */
/* 538 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 540 */	NdrFcLong( 0x13 ),	/* 19 */
/* 544 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 546 */	NdrFcLong( 0x15 ),	/* 21 */
/* 550 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 552 */	NdrFcLong( 0x16 ),	/* 22 */
/* 556 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 558 */	NdrFcLong( 0x17 ),	/* 23 */
/* 562 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 564 */	NdrFcLong( 0xe ),	/* 14 */
/* 568 */	NdrFcShort( 0xba ),	/* Offset= 186 (754) */
/* 570 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 574 */	NdrFcShort( 0xbe ),	/* Offset= 190 (764) */
/* 576 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 580 */	NdrFcShort( 0xbc ),	/* Offset= 188 (768) */
/* 582 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 586 */	NdrFcShort( 0x70 ),	/* Offset= 112 (698) */
/* 588 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 592 */	NdrFcShort( 0x6e ),	/* Offset= 110 (702) */
/* 594 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 598 */	NdrFcShort( 0x6c ),	/* Offset= 108 (706) */
/* 600 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 604 */	NdrFcShort( 0x62 ),	/* Offset= 98 (702) */
/* 606 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 610 */	NdrFcShort( 0x5c ),	/* Offset= 92 (702) */
/* 612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x0 ),	/* Offset= 0 (616) */
/* 618 */	NdrFcLong( 0x1 ),	/* 1 */
/* 622 */	NdrFcShort( 0x0 ),	/* Offset= 0 (622) */
/* 624 */	NdrFcShort( 0xffff ),	/* Offset= -1 (623) */
/* 626 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 632 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 634 */	NdrFcShort( 0x2 ),	/* Offset= 2 (636) */
/* 636 */	
			0x13, 0x0,	/* FC_OP */
/* 638 */	NdrFcShort( 0x1b8 ),	/* Offset= 440 (1078) */
/* 640 */	
			0x13, 0x0,	/* FC_OP */
/* 642 */	NdrFcShort( 0x20 ),	/* Offset= 32 (674) */
/* 644 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 646 */	NdrFcLong( 0x2f ),	/* 47 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 656 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 658 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 660 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 662 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 664 */	NdrFcShort( 0x1 ),	/* 1 */
/* 666 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 668 */	NdrFcShort( 0x4 ),	/* 4 */
/* 670 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 672 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 674 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 676 */	NdrFcShort( 0x10 ),	/* 16 */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0xa ),	/* Offset= 10 (690) */
/* 682 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 684 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 686 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (644) */
/* 688 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 690 */	
			0x13, 0x0,	/* FC_OP */
/* 692 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (662) */
/* 694 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 696 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 698 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 700 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 702 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 704 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 706 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 708 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 710 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 712 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 714 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 716 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 718 */	
			0x13, 0x0,	/* FC_OP */
/* 720 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (626) */
/* 722 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 724 */	NdrFcShort( 0xfd36 ),	/* Offset= -714 (10) */
/* 726 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 728 */	NdrFcShort( 0xfe00 ),	/* Offset= -512 (216) */
/* 730 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 732 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (272) */
/* 734 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 736 */	NdrFcShort( 0x2 ),	/* Offset= 2 (738) */
/* 738 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 740 */	NdrFcShort( 0x2 ),	/* Offset= 2 (742) */
/* 742 */	
			0x13, 0x0,	/* FC_OP */
/* 744 */	NdrFcShort( 0x14e ),	/* Offset= 334 (1078) */
/* 746 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 748 */	NdrFcShort( 0x2 ),	/* Offset= 2 (750) */
/* 750 */	
			0x13, 0x0,	/* FC_OP */
/* 752 */	NdrFcShort( 0x14 ),	/* Offset= 20 (772) */
/* 754 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 756 */	NdrFcShort( 0x10 ),	/* 16 */
/* 758 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 760 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 762 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 764 */	
			0x13, 0x0,	/* FC_OP */
/* 766 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (754) */
/* 768 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 770 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 772 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 774 */	NdrFcShort( 0x20 ),	/* 32 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* Offset= 0 (778) */
/* 780 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 782 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 784 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 786 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 788 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (328) */
/* 790 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 792 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 794 */	NdrFcShort( 0x4 ),	/* 4 */
/* 796 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 802 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 804 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 806 */	NdrFcShort( 0x4 ),	/* 4 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	0x13, 0x0,	/* FC_OP */
/* 818 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (772) */
/* 820 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 822 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 824 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x6 ),	/* Offset= 6 (836) */
/* 832 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 834 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 836 */	
			0x11, 0x0,	/* FC_RP */
/* 838 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (792) */
/* 840 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 842 */	NdrFcShort( 0x4 ),	/* 4 */
/* 844 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 850 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 852 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 854 */	NdrFcShort( 0x4 ),	/* 4 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x1 ),	/* 1 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	0x13, 0x0,	/* FC_OP */
/* 866 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (674) */
/* 868 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 870 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 872 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x6 ),	/* Offset= 6 (884) */
/* 880 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 882 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 884 */	
			0x11, 0x0,	/* FC_RP */
/* 886 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (840) */
/* 888 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 892 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 894 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x10 ),	/* 16 */
/* 898 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 900 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 902 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (888) */
			0x5b,		/* FC_END */
/* 906 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 908 */	NdrFcShort( 0x18 ),	/* 24 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0xa ),	/* Offset= 10 (922) */
/* 914 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 916 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 918 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (894) */
/* 920 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 922 */	
			0x11, 0x0,	/* FC_RP */
/* 924 */	NdrFcShort( 0xfd4e ),	/* Offset= -690 (234) */
/* 926 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 928 */	NdrFcShort( 0x1 ),	/* 1 */
/* 930 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 936 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 938 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 942 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 944 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 946 */	NdrFcShort( 0x4 ),	/* 4 */
/* 948 */	NdrFcShort( 0x4 ),	/* 4 */
/* 950 */	0x13, 0x0,	/* FC_OP */
/* 952 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (926) */
/* 954 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 956 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 958 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 960 */	NdrFcShort( 0x2 ),	/* 2 */
/* 962 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 968 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 970 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 976 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 978 */	NdrFcShort( 0x4 ),	/* 4 */
/* 980 */	NdrFcShort( 0x4 ),	/* 4 */
/* 982 */	0x13, 0x0,	/* FC_OP */
/* 984 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (958) */
/* 986 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 988 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 990 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 992 */	NdrFcShort( 0x4 ),	/* 4 */
/* 994 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1000 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1002 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1006 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1008 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1010 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1012 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1014 */	0x13, 0x0,	/* FC_OP */
/* 1016 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (990) */
/* 1018 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1020 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1022 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1026 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1032 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1034 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1040 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1042 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1044 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1046 */	0x13, 0x0,	/* FC_OP */
/* 1048 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1022) */
/* 1050 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1052 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1054 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1058 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1060 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1062 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1066 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1068 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1070 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1072 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1074 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1054) */
/* 1076 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1078 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1080 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1082 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1062) */
/* 1084 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1084) */
/* 1086 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1088 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1090 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1092 */	NdrFcShort( 0xfc1c ),	/* Offset= -996 (96) */
/* 1094 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1096 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1098 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1100 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0xfc08 ),	/* Offset= -1016 (88) */
/* 1106 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1108 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1110 */	
			0x12, 0x0,	/* FC_UP */
/* 1112 */	NdrFcShort( 0xfbc2 ),	/* Offset= -1086 (26) */
/* 1114 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1110) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            }

        };



/* Standard interface: __MIDL_itf_FBClientService_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IFBClientService, ver. 0.0,
   GUID={0x72E79C06,0x3ABF,0x4C54,{0x91,0xCE,0x5D,0xD6,0x3E,0xE6,0x70,0x06}} */

#pragma code_seg(".orpc")
static const unsigned short IFBClientService_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108,
    144,
    180,
    216,
    252,
    288,
    318,
    354,
    390,
    426,
    462
    };

static const MIDL_STUBLESS_PROXY_INFO IFBClientService_ProxyInfo =
    {
    &Object_StubDesc,
    FBClientService__MIDL_ProcFormatString.Format,
    &IFBClientService_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFBClientService_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FBClientService__MIDL_ProcFormatString.Format,
    &IFBClientService_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(21) _IFBClientServiceProxyVtbl = 
{
    &IFBClientService_ProxyInfo,
    &IID_IFBClientService,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::getPokesCount */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::getUser */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::getFriends */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::getMessagesCount */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::getRequestsCount */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::getEventsCount */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::getGroupsInvsCount */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::login */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::logout */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::isLoggedIn */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::setStatus */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::canChangeStatus */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::updateView */ ,
    (void *) (INT_PTR) -1 /* IFBClientService::setSession */
};


static const PRPC_STUB_FUNCTION IFBClientService_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFBClientServiceStubVtbl =
{
    &IID_IFBClientService,
    &IFBClientService_ServerInfo,
    21,
    &IFBClientService_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    FBClientService__MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f3, /* MIDL Version 7.0.499 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _FBClientService_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFBClientServiceProxyVtbl,
    0
};

const CInterfaceStubVtbl * _FBClientService_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFBClientServiceStubVtbl,
    0
};

PCInterfaceName const _FBClientService_InterfaceNamesList[] = 
{
    "IFBClientService",
    0
};

const IID *  _FBClientService_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _FBClientService_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _FBClientService, pIID, n)

int __stdcall _FBClientService_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_FBClientService_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo FBClientService_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _FBClientService_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _FBClientService_StubVtblList,
    (const PCInterfaceName * ) & _FBClientService_InterfaceNamesList,
    (const IID ** ) & _FBClientService_BaseIIDList,
    & _FBClientService_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

