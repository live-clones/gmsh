// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_WIN32_GUI)

#include <algorithm>
#include <cmath>
#include <mutex>

#include "win32Common.h"

// What every file of the interface uses: the strings of Windows, the queue of
// what runs once the message is over, the keys, the font and the metrics, and
// the window class that holds controls.

// --- strings

std::wstring win32Wide(const std::string &s)
{
  if(s.empty()) return std::wstring();
  int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), nullptr, 0);
  std::wstring w(n, L'\0');
  MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), &w[0], n);
  return w;
}

std::string win32Utf8(const std::wstring &w)
{
  if(w.empty()) return std::string();
  int n = WideCharToMultiByte(CP_UTF8, 0, w.data(), (int)w.size(), nullptr, 0,
                              nullptr, nullptr);
  std::string s(n, '\0');
  WideCharToMultiByte(CP_UTF8, 0, w.data(), (int)w.size(), &s[0], n, nullptr,
                      nullptr);
  return s;
}

std::string win32Text(HWND w)
{
  int n = GetWindowTextLengthW(w);
  std::wstring t(n + 1, L'\0');
  GetWindowTextW(w, &t[0], n + 1);
  t.resize(n);
  return win32Utf8(t);
}

// --- what runs once the message is over

namespace {
  std::vector<std::function<void()> > _later;
  std::mutex _laterMutex;
} // namespace

void win32Later(const std::function<void()> &what)
{
  {
    std::lock_guard<std::mutex> lock(_laterMutex);
    _later.push_back(what);
  }
  if(HWND w = win32MainWindow()) PostMessageW(w, WM_GMSH_LATER, 0, 0);
}

void win32RunLater()
{
  while(true) {
    std::vector<std::function<void()> > now;
    {
      std::lock_guard<std::mutex> lock(_laterMutex);
      now.swap(_later);
    }
    if(now.empty()) return;
    for(auto &w : now)
      if(w) w();
  }
}

bool win32ButtonDown()
{
  return (GetAsyncKeyState(VK_LBUTTON) & 0x8000) ||
         (GetAsyncKeyState(VK_RBUTTON) & 0x8000) ||
         (GetAsyncKeyState(VK_MBUTTON) & 0x8000);
}

// --- keys

bool win32UiKey(WPARAM vk, LPARAM lp, int &key, unsigned &mods)
{
  key = 0;
  mods = 0;
  bool ctrl = GetKeyState(VK_CONTROL) < 0, alt = GetKeyState(VK_MENU) < 0;
  bool shift = GetKeyState(VK_SHIFT) < 0;
  if(ctrl) mods |= Ui::ModCommand;
  if(shift) mods |= Ui::ModShift;
  if(alt) mods |= Ui::ModAlt;
  if(vk >= VK_F1 && vk <= VK_F12) {
    key = Ui::KeyF1 + (int)(vk - VK_F1);
    return true;
  }
  switch(vk) {
  case VK_LEFT: key = Ui::KeyLeft; return true;
  case VK_RIGHT: key = Ui::KeyRight; return true;
  case VK_UP: key = Ui::KeyUp; return true;
  case VK_DOWN: key = Ui::KeyDown; return true;
  case VK_ESCAPE: key = Ui::KeyEscape; return true;
  case VK_HOME: key = Ui::KeyHome; return true;
  case VK_PRIOR: key = Ui::KeyPageUp; return true;
  case VK_NEXT: key = Ui::KeyPageDown; return true;
  case VK_DELETE:
  case VK_BACK: key = Ui::KeyDelete; return true;
  default: break;
  }
  if(vk >= 'A' && vk <= 'Z') {
    key = (int)vk;
    return true;
  }
  // a digit or a mark is the one typed, whatever key gives it on this
  // keyboard (Shift, on a French one; AltGr, which is Control and Alt)
  BYTE state[256];
  if(!GetKeyboardState(state)) return false;
  state[VK_CONTROL] = state[VK_LCONTROL] = state[VK_RCONTROL] = 0;
  if(ctrl && alt) state[VK_MENU] = state[VK_LMENU] = state[VK_RMENU] = 0;
  wchar_t out[4];
  UINT scan = (UINT)((lp >> 16) & 0xff);
  int n = ToUnicode((UINT)vk, scan, state, out, 4, 4);
  if(n == 1 && out[0] > L' ' && out[0] < 127) {
    key = (int)out[0];
    mods &= ~Ui::ModShift;
    return true;
  }
  return false;
}

// --- the font and the metrics

namespace {

  HFONT _font = nullptr, _bold = nullptr, _fixed = nullptr;
  double _em = 0.;
  int _row = 0;
  Ui::Metrics _metrics;
  bool _measured = false;

  UINT _dpi()
  {
    HMODULE user = GetModuleHandleW(L"user32.dll");
    typedef UINT(WINAPI * forSystem)(void);
    forSystem get =
      user ? (forSystem)(void *)GetProcAddress(user, "GetDpiForSystem") : nullptr;
    if(get) return get();
    HDC dc = GetDC(nullptr);
    UINT d = (UINT)GetDeviceCaps(dc, LOGPIXELSY);
    ReleaseDC(nullptr, dc);
    return d ? d : 96;
  }

  void _makeFonts()
  {
    if(_font) return;
    NONCLIENTMETRICSW ncm;
    memset(&ncm, 0, sizeof(ncm));
    ncm.cbSize = sizeof(ncm);
    // at the DPI of the system, which a process aware of it is not scaled to
    HMODULE user = GetModuleHandleW(L"user32.dll");
    typedef BOOL(WINAPI * forDpi)(UINT, UINT, PVOID, UINT, UINT);
    forDpi get = user ? (forDpi)(void *)GetProcAddress(
                          user, "SystemParametersInfoForDpi") :
                        nullptr;
    if(!(get && get(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0, _dpi())))
      SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0);
    LOGFONTW lf = ncm.lfMessageFont;
    int said = win32Sources().settings ? win32Sources().settings().fontSize : 0;
    if(said > 0) lf.lfHeight = -MulDiv(said, (int)_dpi(), 72);
    _font = CreateFontIndirectW(&lf);
    lf.lfWeight = FW_BOLD;
    _bold = CreateFontIndirectW(&lf);
    LOGFONTW fixed = ncm.lfMessageFont;
    wcscpy(fixed.lfFaceName, L"Consolas");
    fixed.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
    _fixed = CreateFontIndirectW(&fixed);
  }

  // the width of a text in the font of the interface, in pixels
  int _textPx(const std::string &s, bool bold = false)
  {
    HDC dc = GetDC(nullptr);
    HGDIOBJ was = SelectObject(dc, bold ? _bold : _font);
    std::wstring w = win32Wide(s);
    SIZE size = {0, 0};
    GetTextExtentPoint32W(dc, w.c_str(), (int)w.size(), &size);
    SelectObject(dc, was);
    ReleaseDC(nullptr, dc);
    return size.cx;
  }

  void _measure()
  {
    if(_measured) return;
    _measured = true;
    _makeFonts();
    HDC dc = GetDC(nullptr);
    HGDIOBJ was = SelectObject(dc, _font);
    TEXTMETRICW tm;
    GetTextMetricsW(dc, &tm);
    SelectObject(dc, was);
    ReleaseDC(nullptr, dc);
    _em = tm.tmHeight - tm.tmInternalLeading;
    if(_em < 6.) _em = 12.;
    // an edit control and a push button as Windows draws them
    _row = tm.tmHeight + 2 * GetSystemMetrics(SM_CYEDGE) + 6;
    const double em = _em;
    const int row = _row;
    Ui::Metrics m;
    m.field = 10.;
    m.row = row / em;
    m.line = tm.tmHeight / em;
    m.gap = .6;
    m.cellGap = .45;
    m.linePad = 2. / em;
    m.gridRowGap = .3;
    m.rule = .7;
    // the row of a tab control, and what a tab takes beyond its name
    m.tabBar = (tm.tmHeight + 10) / em;
    m.tab = 16. / em;
    m.tabPad = 4. / em;
    m.scrollbar = GetSystemMetrics(SM_CXVSCROLL) / em;
    m.textWidth = [em](const std::string &s) { return (_textPx(s) + 4) / em; };
    m.widget = [em, row](const Ui::Field &f) -> Ui::Size {
      double text = _textPx(f.label, f.heading) / em;
      double check = (GetSystemMetrics(SM_CXMENUCHECK) + 6) / em;
      switch(f.kind) {
      case Ui::Check:
        if(f.disclosure) return Ui::Size(text + 2.5, row / em);
        return Ui::Size(text + check, row / em);
      // never narrower than a button of Windows, 75 pixels at 96 DPI
      case Ui::Action:
        return Ui::Size(std::max(text + 1.6, 75. * _dpi() / 96. / em), row / em);
      case Ui::Menu: return Ui::Size(text + 2.6, row / em);
      case Ui::Choice:
        if(f.multiple) return Ui::Size(text + 2.6, row / em);
        break;
      case Ui::Label:
        return Ui::Size(_textPx(f.getText(), f.heading) / em + .4, row / em);
      case Ui::Color: return Ui::Size(3., row / em);
      default: break;
      }
      return Ui::Size(-1., row / em);
    };
    m.proseHeight = [em, row](const Ui::Field &f, double width) -> double {
      if(!f.prose) return row / em;
      std::string all;
      for(const Ui::Line &l : f.prose()) {
        for(const Ui::Words &w : l.words) all += w.text;
        all += "\n";
      }
      std::wstring w = win32Wide(all);
      HDC dc = GetDC(nullptr);
      HGDIOBJ was = SelectObject(dc, _font);
      RECT r = {0, 0, (LONG)(width * em), 0};
      DrawTextW(dc, w.c_str(), (int)w.size(), &r,
                DT_CALCRECT | DT_WORDBREAK | DT_NOPREFIX);
      SelectObject(dc, was);
      ReleaseDC(nullptr, dc);
      return (r.bottom - r.top) / em;
    };
    _metrics = m;
  }

} // namespace

HFONT win32Font(bool bold)
{
  _makeFonts();
  return bold ? _bold : _font;
}

HFONT win32FixedFont()
{
  _makeFonts();
  return _fixed;
}

double win32Em()
{
  _measure();
  return _em;
}

int win32Px(double em) { return (int)std::floor(em * win32Em() + 0.5); }

int win32Row()
{
  _measure();
  return _row;
}

Ui::Metrics win32Metrics()
{
  _measure();
  return _metrics;
}

void win32ForgetMetrics()
{
  _measured = false;
  if(_font) DeleteObject(_font);
  if(_bold) DeleteObject(_bold);
  if(_fixed) DeleteObject(_fixed);
  _font = _bold = _fixed = nullptr;
}

// --- the window that holds controls

namespace {

  LRESULT CALLBACK _panelProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    switch(msg) {
    case WM_COMMAND:
    case WM_NOTIFY:
    case WM_HSCROLL:
    case WM_VSCROLL:
    case WM_DRAWITEM:
    case WM_CTLCOLORSTATIC:
    case WM_CTLCOLORBTN: {
      // a scroll bar of the panel's own is not a control's
      if((msg == WM_VSCROLL || msg == WM_HSCROLL) && !lp) break;
      LRESULT result = 0;
      if(win32FieldMessage(w, msg, wp, lp, result)) return result;
      break;
    }
    case WM_ERASEBKGND: {
      RECT r;
      GetClientRect(w, &r);
      FillRect((HDC)wp, &r, GetSysColorBrush(COLOR_BTNFACE));
      return 1;
    }
    default: break;
    }
    if(win32PanelHook hook = (win32PanelHook)GetPropW(w, L"gmshHook")) {
      bool taken = false;
      LRESULT r = hook(w, msg, wp, lp, taken);
      if(taken) return r;
    }
    if(msg == WM_CTLCOLORSTATIC || msg == WM_CTLCOLORBTN) {
      // on the colour of the panel
      SetBkMode((HDC)wp, TRANSPARENT);
      return (LRESULT)GetSysColorBrush(COLOR_BTNFACE);
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

} // namespace

const wchar_t *win32PanelClass()
{
  static bool registered = false;
  if(!registered) {
    registered = true;
    WNDCLASSEXW wc;
    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = _panelProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
    wc.lpszClassName = L"GmshPanel";
    RegisterClassExW(&wc);
  }
  return L"GmshPanel";
}

void win32SetPanelHook(HWND panel, win32PanelHook hook)
{
  SetPropW(panel, L"gmshHook", (HANDLE)(void *)hook);
}

HWND win32Panel(HWND parent, int x, int y, int w, int h, bool border)
{
  // what it holds is reached with Tab, as the controls of a dialog are
  return CreateWindowExW(WS_EX_CONTROLPARENT | (border ? WS_EX_CLIENTEDGE : 0),
                         win32PanelClass(), L"",
                         WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN |
                           WS_CLIPSIBLINGS,
                         x, y, w, h, parent, nullptr, GetModuleHandleW(nullptr),
                         nullptr);
}

#endif
