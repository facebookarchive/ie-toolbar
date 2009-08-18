#include "StdAfx.h"
#include "ObjectsServer.h"
#include "ClassFactory.h"
#include "ClassIds.h"


using namespace facebook;


STDAPI DllCanUnloadNow(){
   return ObjectsServer().isLocked() ? S_FALSE : S_OK;
}


STDAPI DllGetClassObject(REFCLSID classId, REFIID interfaceId,
                         LPVOID* interfacePointer){
   *interfacePointer = 0;

   if (!IsEqualCLSID(classId, CLSID_IEToolbar) &&
         !IsEqualCLSID(classId, CLSID_IESidebar)){
      return CLASS_E_CLASSNOTAVAILABLE;
   }

   std::auto_ptr<IClassFactory> classFactory(new ClassFactory(classId));

   const HRESULT queryInterfaceResult =
         classFactory->QueryInterface(interfaceId, interfacePointer);
   if (FAILED(queryInterfaceResult)){
      return queryInterfaceResult;
   }

   classFactory.release();

   return S_OK;
}


STDAPI DllRegisterServer(){
   try {
      ObjectsServer().registerServer();
      return S_OK;
   } catch (...){
      return E_FAIL;
   }
}


STDAPI DllUnregisterServer() {
   try {
      ObjectsServer().unregisterServer();
      return S_OK;
   } catch (...){
      return E_FAIL;
   }
}
