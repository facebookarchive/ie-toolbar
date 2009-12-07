

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __FBClientService_i_h__
#define __FBClientService_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFBClientService_FWD_DEFINED__
#define __IFBClientService_FWD_DEFINED__
typedef interface IFBClientService IFBClientService;
#endif 	/* __IFBClientService_FWD_DEFINED__ */


#ifndef __IFBClientServiceEvents_FWD_DEFINED__
#define __IFBClientServiceEvents_FWD_DEFINED__
typedef interface IFBClientServiceEvents IFBClientServiceEvents;
#endif 	/* __IFBClientServiceEvents_FWD_DEFINED__ */


#ifndef __FBClientService_FWD_DEFINED__
#define __FBClientService_FWD_DEFINED__

#ifdef __cplusplus
typedef class FBClientService FBClientService;
#else
typedef struct FBClientService FBClientService;
#endif /* __cplusplus */

#endif 	/* __FBClientService_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_FBClientService_0000_0000 */
/* [local] */ 

typedef /* [helpstring][version][uuid] */  DECLSPEC_UUID("C74DDA8C-4B3D-4ca2-A4F2-5250AA9459DB") struct FBUserData
    {
    BSTR id;
    BSTR name;
    BSTR pic;
    BSTR pic_sq;
    BSTR status;
    ULONG ptime;
    ULONG stime;
    ULONG notes;
    ULONG wall;
    BSTR cookies;
    } 	FBUserData;



extern RPC_IF_HANDLE __MIDL_itf_FBClientService_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_FBClientService_0000_0000_v0_0_s_ifspec;

#ifndef __IFBClientService_INTERFACE_DEFINED__
#define __IFBClientService_INTERFACE_DEFINED__

/* interface IFBClientService */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFBClientService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72E79C06-3ABF-4C54-91CE-5DD63EE67006")
    IFBClientService : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getPokesCount( 
            /* [retval][out] */ ULONG *pokesCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getUser( 
            /* [retval][out] */ FBUserData *userData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getFriends( 
            /* [retval][out] */ SAFEARRAY * *usersData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getMessagesCount( 
            /* [out] */ ULONG *messagesCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getRequestsCount( 
            /* [out] */ ULONG *requestsCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getEventsCount( 
            /* [out] */ ULONG *eventsCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getGroupsInvsCount( 
            /* [out] */ ULONG *groupsInvsCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE login( 
            /* [in] */ ULONG parentWindow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE logout( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE isLoggedIn( 
            /* [out] */ USHORT *loggedIn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setStatus( 
            /* [in] */ BSTR statusMessage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE canChangeStatus( 
            /* [retval][out] */ USHORT *allowed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE updateView( 
            /* [in] */ ULONG changeId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setSession( 
            /* [in] */ BSTR session) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFBClientServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFBClientService * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFBClientService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFBClientService * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFBClientService * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFBClientService * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFBClientService * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFBClientService * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getPokesCount )( 
            IFBClientService * This,
            /* [retval][out] */ ULONG *pokesCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getUser )( 
            IFBClientService * This,
            /* [retval][out] */ FBUserData *userData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getFriends )( 
            IFBClientService * This,
            /* [retval][out] */ SAFEARRAY * *usersData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getMessagesCount )( 
            IFBClientService * This,
            /* [out] */ ULONG *messagesCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getRequestsCount )( 
            IFBClientService * This,
            /* [out] */ ULONG *requestsCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getEventsCount )( 
            IFBClientService * This,
            /* [out] */ ULONG *eventsCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getGroupsInvsCount )( 
            IFBClientService * This,
            /* [out] */ ULONG *groupsInvsCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *login )( 
            IFBClientService * This,
            /* [in] */ ULONG parentWindow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *logout )( 
            IFBClientService * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *isLoggedIn )( 
            IFBClientService * This,
            /* [out] */ USHORT *loggedIn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setStatus )( 
            IFBClientService * This,
            /* [in] */ BSTR statusMessage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *canChangeStatus )( 
            IFBClientService * This,
            /* [retval][out] */ USHORT *allowed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *updateView )( 
            IFBClientService * This,
            /* [in] */ ULONG changeId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setSession )( 
            IFBClientService * This,
            /* [in] */ BSTR session);
        
        END_INTERFACE
    } IFBClientServiceVtbl;

    interface IFBClientService
    {
        CONST_VTBL struct IFBClientServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFBClientService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFBClientService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFBClientService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFBClientService_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFBClientService_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFBClientService_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFBClientService_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFBClientService_getPokesCount(This,pokesCount)	\
    ( (This)->lpVtbl -> getPokesCount(This,pokesCount) ) 

#define IFBClientService_getUser(This,userData)	\
    ( (This)->lpVtbl -> getUser(This,userData) ) 

#define IFBClientService_getFriends(This,usersData)	\
    ( (This)->lpVtbl -> getFriends(This,usersData) ) 

#define IFBClientService_getMessagesCount(This,messagesCount)	\
    ( (This)->lpVtbl -> getMessagesCount(This,messagesCount) ) 

#define IFBClientService_getRequestsCount(This,requestsCount)	\
    ( (This)->lpVtbl -> getRequestsCount(This,requestsCount) ) 

#define IFBClientService_getEventsCount(This,eventsCount)	\
    ( (This)->lpVtbl -> getEventsCount(This,eventsCount) ) 

#define IFBClientService_getGroupsInvsCount(This,groupsInvsCount)	\
    ( (This)->lpVtbl -> getGroupsInvsCount(This,groupsInvsCount) ) 

#define IFBClientService_login(This,parentWindow)	\
    ( (This)->lpVtbl -> login(This,parentWindow) ) 

#define IFBClientService_logout(This)	\
    ( (This)->lpVtbl -> logout(This) ) 

#define IFBClientService_isLoggedIn(This,loggedIn)	\
    ( (This)->lpVtbl -> isLoggedIn(This,loggedIn) ) 

#define IFBClientService_setStatus(This,statusMessage)	\
    ( (This)->lpVtbl -> setStatus(This,statusMessage) ) 

#define IFBClientService_canChangeStatus(This,allowed)	\
    ( (This)->lpVtbl -> canChangeStatus(This,allowed) ) 

#define IFBClientService_updateView(This,changeId)	\
    ( (This)->lpVtbl -> updateView(This,changeId) ) 

#define IFBClientService_setSession(This,session)	\
    ( (This)->lpVtbl -> setSession(This,session) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFBClientService_INTERFACE_DEFINED__ */



#ifndef __FBClientServiceLib_LIBRARY_DEFINED__
#define __FBClientServiceLib_LIBRARY_DEFINED__

/* library FBClientServiceLib */
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_FBClientServiceLib;

#ifndef __IFBClientServiceEvents_DISPINTERFACE_DEFINED__
#define __IFBClientServiceEvents_DISPINTERFACE_DEFINED__

/* dispinterface IFBClientServiceEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IFBClientServiceEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A821A7CC-ABC7-4A90-896B-EA7710C57B77")
    IFBClientServiceEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFBClientServiceEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFBClientServiceEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFBClientServiceEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFBClientServiceEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFBClientServiceEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFBClientServiceEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFBClientServiceEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFBClientServiceEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFBClientServiceEventsVtbl;

    interface IFBClientServiceEvents
    {
        CONST_VTBL struct IFBClientServiceEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFBClientServiceEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFBClientServiceEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFBClientServiceEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFBClientServiceEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFBClientServiceEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFBClientServiceEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFBClientServiceEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFBClientServiceEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FBClientService;

#ifdef __cplusplus

class DECLSPEC_UUID("E051840E-5790-4795-B3C8-DCBFCFE303D8")
FBClientService;
#endif
#endif /* __FBClientServiceLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


