#include "RequestsComposer.h"
#include "ResponseParser.h"
#include "XMLRequest.h"


#include <boost/assign/list_inserter.hpp>

#include "../common/CommonConstants.h"
#include "../common/URLUtils.h"

#include "../util/md5.h"
#include "../util/LogUtils.h"
#include "../util/RegistryUtils.h"
#include "../util/XMLUtils.h"

#include "../../FBClientServiceUI/ClientServiceUI.h"


namespace facebook{

/**
 *
 * class CommunicationService
 *
 *  This class is a part of implementation of ClientServices
 *  it does not have header file and included to the ClientServiceImpl
 *  using #include "CommunicationService.cpp"
 *  His responsibility is to send requests to facebook
 *  and returns response. To understand what it actualy does
 *  you should be familiar with the way how facebook authentificates 
 *  users
 *
 */

class CommunicationService : private boost::noncopyable{
public:
    
   CommunicationService(const SessionInfo&  sessionInfo) :
         sessionInfo_(sessionInfo),
         callID_(0),
         httpRequest_(CLSID_XMLHTTPRequest) {
      
   }

  /*** trivial constructor */
   CommunicationService() :
      sessionInfo_(),
      callID_(0),
      httpRequest_(CLSID_XMLHTTPRequest) {
   }

  /**
   * Executes request to the server
   *
   * @param request to execute (by ref)
   * @param response from the server(by ref)
   */
   void CommunicationService::executeRequest(const XMLRequest& request, /*out*/ String& response) {
      if (!isLoggedIn())
         throw std::exception("attempt to execute request without login");

      doRequest(request, _T("XML"), response);
   }

   bool CommunicationService::isLoggedIn() const {
      return (!sessionInfo_.sessionKey_.empty());
   }

  /**
   * Stores token to the registry
   *
   * @param token to store (by ref)
   */
   void storeToken(const String& token) {
      RegStrEntry tokenEntry(HKEY_CURRENT_USER, 
         kFacebookSessionPath, _T("token"), token);
      tokenEntry.write();
   }

  /**
   * Restores token from the registry
   *
   * @param token to restore (by ref)
   */
   void restoreToken(String& token) {
      RegStrEntry tokenEntry(HKEY_CURRENT_USER, 
         kFacebookSessionPath, _T("token"), _T(""));
      tokenEntry.read();
      token = tokenEntry._value;
   }


   void CommunicationService::login(ULONG parentWindow, String& cookie) {
      sessionInfo_ = SessionInfo();

      obtainToken();
      doLogin(parentWindow, cookie);
      obtainSession();
   }

   
  SessionInfo getSessionInfo() { return sessionInfo_;}


   String CommunicationService::getToken() const {
      return token_;
   }

   void CommunicationService::logout() {
      if (!isLoggedIn()) {
         return;
      }

      const String logoutPage = _T("http://www.facebook.com/logout.php");

      String responseDummy;
      doPostRequest(_T("confirm=1"), logoutPage, responseDummy);
   }

   bool hasSetStatusPermission() {
      XMLRequest hasChangeStatusPersmisionResp = 
         RequestsComposer::composeHasPermissionRequest(_T("status_update"));
      String response;
      doRequest(hasChangeStatusPersmisionResp, _T("XML"), response);
      return ResponseParser::parseHasPermissionResponse(response);
   }

   bool isSessionStillValid() {
      bool res = true;
      try{
          hasSetStatusPermission();
      } 
      catch(ResponseParser::ErrorInResponse& err) {
        UNREFERENCED_PARAMETER(err);
        LOG4CPLUS_DEBUG(LogUtils::getLogger(), _T("ClientServiceImpl::isSessionStillValid() failed with ") << err.getDescr());
         res = false;
      }
      catch(...) {
         res = false;
      }

      return res;
   }

   // methods
private:

   void doLogin(ULONG parentWindow, String& cookie) {
      String loginUrl = kLoginUrl;
	    loginUrl.append( _T("?popup&v=1.0") );
      loginUrl.append( _T("&api_key=") );
      loginUrl.append( kApiKey);
      loginUrl.append( _T("&auth_token=") );
      loginUrl.append( token_ );
   
      String result;
      // need additional string and resize because
      // it shouldn't be allocated in dll -> may cause heap corruption
      result.resize(kCookiesSize);
      if (parentWindow != 0) {
        // no need to show login if we have no parent
        showLoginDialog(loginUrl, parentWindow, result);
      } else {
        //try silent login
        String response;
        doGetRequest(loginUrl, response);
      }
      cookie = result;
   }

   /**
    *  Obtains auth token see
    *
    *  http://wiki.developers.facebook.com/index.php/Auth.createToken 
    */ 
   void  CommunicationService::obtainToken() {
     if (isLoggedIn()) {
         return;
     }

      const XMLRequest createTokenRequest = RequestsComposer::composeCreateTokenRequest();
      String response;
      doRequest(createTokenRequest, _T("XML"), response);
      token_ = ResponseParser::parseCreateTokenResp(response);
   }

   
  /**
   *  Obtains session_key, users id, and expiration data
   *  see http://wiki.developers.facebook.com/index.php/Auth.getSession
   */ 
   void CommunicationService::obtainSession() {
      if (isLoggedIn()) {
         return;
      }

      const XMLRequest getSessionRequest = 
         RequestsComposer::composeCreateSessionRequest(token_);

      String response;
      doRequest(getSessionRequest, _T("XML"), response);
      sessionInfo_ = ResponseParser::parseCreateSessionResp(response);
   }

 
   String CommunicationService::getQueryString(const XMLRequest::RequestParams& params, 
         const String& separator) {
      String res;
      std::map<String, String>::const_iterator it = params.begin();
      const std::map<String, String>::const_iterator itEnd = params.end();

      for(;it!= itEnd; ++it) {
         String value = (*it).second;
           res += ((*it).first + _T("=") + value);
           res += separator; 
      }
      boost::erase_last(res, separator);
      return res;
   }

   String CommunicationService::generateMD5HashForParams(const std::map<String, String>& params,
     String secret) {
      String paramsString = getQueryString(params, _T(""));
      String strForHASH = paramsString + secret;

      return md5String(&strForHASH[0]);
   }

  void doRequest(const XMLRequest& request, const String& format, String& response) { 
    try {
      XMLRequest::RequestParams full_params = request.getRequestParams();

      // TODO: convert time to UTC here
      const String callID = boost::lexical_cast<String>(timeGetTime());

      using boost::assign::insert;

      insert( full_params )
            ( _T("call_id"), callID )
            ( _T("api_key"), kApiKey )
            ( _T("method"), request.getApiName())
            ( _T("format"), format)
            ( _T("v"), kApiVer);
      
      String secret = kSecret;
      const String sessionKey = sessionInfo_.sessionKey_;
      if( !sessionKey.empty()) {
         insert( full_params ) 
               (_T("session_key"), sessionKey);
         if (!sessionInfo_.sessionSecret_.empty()) {
           // set the needed secret for the desktop mode
           secret = sessionInfo_.sessionSecret_;
         }
      }
      String sig = generateMD5HashForParams(full_params, secret);

      insert( full_params ) 
            (_T("sig"), sig);
      const XMLRequest::RequestType requestType = request.getRequestType();
      if (requestType == XMLRequest::GET) {
        const String paramsString = kRestServer + _T("?") + getQueryString(full_params, _T("&"));
        doGetRequest(paramsString, response);
      } else if (requestType == XMLRequest::POST) {
        const String paramsString = getQueryString(full_params, _T("&"));      
        doPostRequest(paramsString, kRestServer, response);
      } else {
        throw std::exception("bad request");
      }
    }
    catch(...) {
      // catch added for handle error if LAN connection broken
    }
  }

   void doGetRequest(const String& paramsString, String& response) {
     try {
       const HRESULT openResult = httpRequest_->open(_T("GET"), 
         paramsString.c_str() , false);
       if FAILED(openResult) {
         _com_raise_error(openResult);
       }

       const HRESULT sendResult = httpRequest_->send();
       if FAILED(sendResult) {
         _com_raise_error(openResult);
       }

       response = toString(httpRequest_->responseText);
     }
     catch(...) {
       // catch added for handle error if LAN connection broken
     }
   }

   void doPostRequest(const String& paramsString, const String& targetURL, String& response) {
     try { 
       const HRESULT openResult = httpRequest_->open(_T("POST"), targetURL.c_str() , false);
       if FAILED(openResult) {
         _com_raise_error(openResult);
       }

       HRESULT setHeaderRes = httpRequest_->setRequestHeader(_T("Content-type"), 
            _T("application/x-www-form-urlencoded"));

       setHeaderRes = httpRequest_->setRequestHeader(_T("text/html,application/xhtml+xml"), 
            _T("application/xml;q=0.9,*/*;q=0.8"));

       const String contentLength = boost::lexical_cast<String>(paramsString.size());
       setHeaderRes = httpRequest_->setRequestHeader(_T("Content-length"),contentLength.c_str());

       const HRESULT sendResult = httpRequest_->send(paramsString.c_str());
       if FAILED(sendResult) {
         _com_raise_error(openResult);
       }

       response = toString(httpRequest_->responseText);
     }
     catch(...) {
       // catch added for handle error if LAN connection broken
     }
   }

  


private:
   SessionInfo sessionInfo_;
   String token_;
   unsigned int callID_;
   MSXML2::IXMLHTTPRequestPtr httpRequest_;

}; // class CommunicationService

} // namespace facebook