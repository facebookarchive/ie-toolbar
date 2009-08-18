#ifndef IFBCLIENTSERVICEEVENTS_CP_H
#define IFBCLIENTSERVICEEVENTS_CP_H

template<class T>
class CProxyIFBClientServiceEvents :
  public IConnectionPointImpl<T, &__uuidof(IFBClientServiceEvents)>{
public:
  HRESULT Fire_dataUpdated(ULONG dataId)
 {
    HRESULT hr = S_OK;
    T * pThis = static_cast<T *>(this);
    int cConnections = m_vec.GetSize();

    for (int iConnection = 0; iConnection < cConnections; iConnection++) {
      pThis->Lock();
      CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
      pThis->Unlock();

      IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

      if (pConnection) {
        CComVariant avarParams[1];
        avarParams[0] = dataId;
        avarParams[0].vt = VT_UI4;
        CComVariant varResult;

        DISPPARAMS params = { avarParams, NULL, 1, 0 };
        try{
          hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, 
            DISPATCH_METHOD, &params, &varResult, NULL, NULL);
        }
        catch(_com_error& e) {
          (e.Description());
        }
        catch(...) {
        }
      }
    }
    return hr;
  }
};

#endif

