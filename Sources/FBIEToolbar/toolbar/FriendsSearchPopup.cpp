#include "StdAfx.h"
#include "FriendsSearchPopup.h"
#include "SearchPopupHtmlView.h"


#include "../Resource.h"

#include "../system/UserDataObserver.h"
#include "../../common/ToolbarMessages.h"

#include "../../util/JavaScriptUtils.h"
#include "../../util/LogUtils.h"
#include "../../util/ShellUtils.h"


namespace facebook{

// ---------------------------------------------------------------------
// class FriendsSearchPopup
// ---------------------------------------------------------------------

IMPLEMENT_DYNAMIC(FriendsSearchPopup, CWnd)

FriendsSearchPopup::FriendsSearchPopup(void) {
  parentWindow_ = NULL;
}

FriendsSearchPopup::FriendsSearchPopup(HWND parentHwnd) {
  parentWindow_ = parentHwnd;
}

FriendsSearchPopup::~FriendsSearchPopup(void) {

}

BEGIN_MESSAGE_MAP(FriendsSearchPopup, CWnd)
   ON_WM_KILLFOCUS()
   ON_WM_SETFOCUS()
   ON_WM_LBUTTONUP()
   ON_MESSAGE(TBM_FILTER_CHANGED, onChangeFriendsFilter)
   ON_MESSAGE(TBM_FOCUS_CHANGED, onFocusChange)
   ON_MESSAGE(TBM_CUSTOM_KEY_PRESSED, onNavigationKeyPressed)
END_MESSAGE_MAP()

BOOL FriendsSearchPopup::Create(CWnd* pParent, CPoint pt, IWebBrowser2Ptr browser) {
  CRect rect;  
  // Determine if MS Windows is right aligned and set shift of the search
  // popup
  int shift = isBiDi(LOCALE_SYSTEM_DEFAULT) ? 245 : 0;
  rect_.SetRect(pt.x - shift, pt.y, 390 + pt.x, kFriendsSearchPopupDefaultHeight + pt.y);
  initialLocation_.x = pt.x - shift;
  initialLocation_.y = pt.y;
  BOOL bRes = CWnd::CreateEx(WS_EX_NOACTIVATE, 
    AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW | CS_OWNDC, 
    LoadCursor(NULL, IDC_ARROW), NULL), 
    sFriendsSearchPopupWindowName.c_str(), WS_POPUP | WS_BORDER | WS_CHILD,
    rect_, pParent, 0);
  SetOwner(NULL);

  const CRect htmlViewRect = calculateWindowRect();

  friendsHtmlView_ = new SearchPopupHtmlView();
 
  friendsHtmlView_->addUIShowingFlags(DOCHOSTUIFLAG_NO3DBORDER | DOCHOSTUIFLAG_SCROLL_NO);
  // set the zero heigght - will resize after loading
  friendsHtmlView_->Create(0, 0, WS_CHILD, CRect(0, 0, htmlViewRect.Width(), 0), 
    this, AFX_IDW_PANE_FIRST);
  friendsHtmlView_->renderHtml();
  if (UserDataObserver::getInstance().isLoggedIn(false)) {
    friendsHtmlView_->loaded(UserDataObserver::getInstance().getFriends(false), 
      true);
  } else {
    friendsHtmlView_->loggedOut();
  }

  return bRes;
}

CRect FriendsSearchPopup::calculateWindowRect() const{
   CRect clientRect;
   GetClientRect(clientRect);
   return clientRect;
}

void FriendsSearchPopup::OnKillFocus(CWnd* wnd) {
   CWnd::OnKillFocus(wnd);
}

void FriendsSearchPopup::OnSetFocus(CWnd* wnd) {
  TRACE("\n***    FriendsSearchPopup::OnSetFocus     \n\n");
   CWnd::OnSetFocus(wnd);
}

void FriendsSearchPopup::closeIt() {
  ::PostMessage(parentWindow_, TBM_FOCUS_CHANGED, 0, 0);
}

bool FriendsSearchPopup::isWindowOurDescendant(const HWND descendantCandidate) const{
  if (GetSafeHwnd() == descendantCandidate) {
    return true;
  }
  if (!IsWindow(GetSafeHwnd())) {
    return false;
  }
  //return (GetSafeHwnd() == descendantCandidate);
  CWnd* childWindow = GetWindow(GW_CHILD);
  while(childWindow != NULL) {
    if (childWindow->GetSafeHwnd() == descendantCandidate) {
        return true;
    }
    if (!IsWindow(childWindow->GetSafeHwnd())) {
      return false;
    }
    childWindow = childWindow->GetWindow(GW_CHILD);
  }
  return false;
}

void FriendsSearchPopup::changeFilter(const String& filter) {
  CStringArray emptyParams;
  friendsHtmlView_->changeFilter(filter);
  int resultingHeight = kFriendsSearchPopupDefaultHeight;
  CComPtr<IHTMLDocument2> htmlDocument = friendsHtmlView_->getHTMLDoc();
  CComVariant result = callJSFunc(htmlDocument, 
    _T("externalGetHeight"), emptyParams);
  if (result.vt != VT_EMPTY && result.lVal != 0) {
    resultingHeight = result.lVal + 4; // add 4 px for borders
  }
  resize(resultingHeight);
}

void FriendsSearchPopup::resize(int height) {
  if (friendsHtmlView_->isLongListLoaded()) {
    // Determine if MS Windows is right aligned and set offset of the popup position
    // depending on it
    int offset = isBiDi(LOCALE_SYSTEM_DEFAULT) ? 80 : 0;
    SetWindowPos(NULL, initialLocation_.x + offset, initialLocation_.y, 310, height, 
      SWP_NOACTIVATE | SWP_NOZORDER);
  } else {
    SetWindowPos(NULL, initialLocation_.x, initialLocation_.y, 390, 
      kFriendsSearchPopupDefaultHeight, SWP_NOACTIVATE | SWP_NOZORDER);
  }
  const CRect htmlViewRect = calculateWindowRect();
  GetDlgItem(AFX_IDW_PANE_FIRST)->SetWindowPos(NULL, 
    htmlViewRect.left, htmlViewRect.top, 
    htmlViewRect.Width(), htmlViewRect.Height(), 
    SWP_NOZORDER | SWP_SHOWWINDOW);
  ShowWindow(SW_SHOWNOACTIVATE);
}

void FriendsSearchPopup::OnLButtonUp( UINT , CPoint) {
   closeIt();
}

LRESULT FriendsSearchPopup::onChangeFriendsFilter(WPARAM wParam, LPARAM lParam) {
   UNREFERENCED_PARAMETER(wParam);

   std::auto_ptr<String> filterText(reinterpret_cast<String*>(lParam));

   friendsHtmlView_->changeFilter(*filterText);

   return 0;
}

LRESULT FriendsSearchPopup::onFocusChange(WPARAM wParam, LPARAM lParam) {
  CRect windowRect = calculateWindowRect();
  ClientToScreen(windowRect);
  if (windowRect.PtInRect(CPoint(wParam, lParam))) {
    //SetFocus();
    return 0;
  }
  ::PostMessage(parentWindow_, TBM_FOCUS_CHANGED, wParam, lParam);
  return 0;
}

LRESULT FriendsSearchPopup::onNavigationKeyPressed(WPARAM wParam, LPARAM lParam) {
  // handle special keys for the javascript
  BOOL result = FALSE;
  if (friendsHtmlView_->isWindowOurDescendant((HWND)lParam) ||
    isWindowOurDescendant((HWND)lParam)) {
      // if escape was pressed - close the popup
      if (wParam == VK_ESCAPE) {
        closeIt();
        result = TRUE;
      }
      if (friendsHtmlView_->translateKeyCodeToJS(wParam)) {
        result = TRUE;
      }
  }
  return result;
}
} //!namespace facebook

