// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <atomic>
#include <cstdio>

#include "win32Common.h"
#include "Console.h"

#include <dwmapi.h>
#include <richedit.h>
#include <shellapi.h>
#include <shobjidl.h>
#include <windowsx.h>

// The native Windows interface: one main window -- the menu bar, the tree
// down the left with the field of the line picked under it, the scene and the
// console beside it, the bar along the bottom -- and a window for each
// described form (dialogWin32.cpp). The loop is the message loop of Windows,
// turned by hand, so that check() and wait() can turn it from inside the
// mesher, and a question can run a loop of its own.

namespace {

  struct mainWindow {
    HWND win = nullptr, treeBox = nullptr, editor = nullptr, footer = nullptr,
         scene = nullptr, console = nullptr, bar = nullptr, message = nullptr,
         progress = nullptr;
    // the tree taken out of the main window into one of its own
    HWND treeWin = nullptr;
    // the bar over the lines: the filter, Save, Clear, Autoscroll
    HWND consoleBar = nullptr, look = nullptr, filter = nullptr, save = nullptr,
         clear = nullptr, follow = nullptr;
    treeWin32 *tree = nullptr;
    std::vector<HWND> buttons, footerButtons;
    std::vector<Ui::Button> footerSaid;
    std::string barBuilt, footerBuilt;
    // the lines, what the filter lets through, whether the last is kept in
    // view
    Ui::Console said;
    int treeWidth = 300, consoleHeight = 150;
    bool treeShown = true, consoleShown = true, fullscreen = false;
    // the gap being dragged: 1 the one by the tree, 2 the one over the console
    int dragging = 0;
    WINDOWPLACEMENT beforeFullscreen;
    LONG styleBeforeFullscreen = 0;
    HMENU menuBeforeFullscreen = nullptr;
  };

  mainWindow *_w = nullptr;
  bool _running = false, _quitShouldExit = true;
  std::atomic<int> _locked(0);
  Ui::Backend::Sources _sources;
  Ui::Backend::Host _host;
  const int Gap = 5;

  int _barHeight() { return win32Row() + 6; }

  // --- the parts of the main window where they go

  // what the box of the tree holds: the tree, the field of the line picked,
  // the buttons of the solver
  void _layoutTree(int tw, int th)
  {
    int row = win32Row(), pad = win32Px(.3);
    int footerH = _w->footerButtons.empty() ? 0 : row + 2 * pad;
    int editorH = row + 2 * pad;
    bool editing = IsWindowVisible(_w->editor) != 0;
    int treeH = th - footerH - (editing ? editorH : 0);
    MoveWindow(win32TreeWindow(_w->tree), 0, 0, tw, std::max(10, treeH), TRUE);
    MoveWindow(_w->editor, 0, treeH, tw, editorH, TRUE);
    MoveWindow(_w->footer, 0, treeH + (editing ? editorH : 0), tw, footerH, TRUE);
    int n = (int)_w->footerButtons.size();
    for(int i = 0; i < n; i++) {
      int bw = (tw - (n + 1) * pad) / std::max(1, n);
      MoveWindow(_w->footerButtons[(std::size_t)i], pad + i * (bw + pad), pad,
                 bw, row, TRUE);
    }
  }

  void _layout()
  {
    if(!_w) return;
    RECT r;
    GetClientRect(_w->win, &r);
    int bh = _w->fullscreen ? 0 : _barHeight();
    int top = 0, bottom = r.bottom - bh;
    int left = 0;
    // the tree is the main window's when it is not in one of its own
    bool tree = _w->treeShown && !_w->fullscreen && !_w->treeWin;
    bool console = _w->consoleShown && !_w->fullscreen;
    if(tree) {
      int tw = std::max(80, std::min(_w->treeWidth, (int)r.right - 100));
      MoveWindow(_w->treeBox, 0, top, tw, bottom - top, TRUE);
      _layoutTree(tw, bottom - top);
      left = tw + Gap;
    }
    if(!_w->treeWin)
      ShowWindow(_w->treeBox, tree ? SW_SHOWNA : SW_HIDE);
    else {
      RECT c;
      GetClientRect(_w->treeWin, &c);
      _layoutTree(c.right, c.bottom);
    }
    int ch = console ? std::max(20, std::min(_w->consoleHeight,
                                             bottom - top - 100)) :
                       0;
    int sceneBottom = console ? bottom - ch - Gap : bottom;
    MoveWindow(_w->scene, left, top, r.right - left, sceneBottom - top, TRUE);
    if(console) {
      int row = win32Row(), pad = 2, bar = std::min(ch, row + 2 * pad);
      MoveWindow(_w->consoleBar, left, bottom - ch, r.right - left, bar, TRUE);
      int x = pad, side = win32Px(1.);
      MoveWindow(_w->look, x, pad + (row - side) / 2, side, side, TRUE);
      x += side + pad;
      int fw = win32Px(15.), bw = win32Px(4.5);
      MoveWindow(_w->filter, x, pad, fw, row, TRUE);
      x += fw + 2 * pad;
      MoveWindow(_w->save, x, pad, bw, row, TRUE);
      x += bw + pad;
      MoveWindow(_w->clear, x, pad, bw, row, TRUE);
      x += bw + 2 * pad;
      MoveWindow(_w->follow, x, pad, win32Px(12.), row, TRUE);
      MoveWindow(_w->console, left, bottom - ch + bar, r.right - left, ch - bar,
                 TRUE);
    }
    ShowWindow(_w->consoleBar, console ? SW_SHOWNA : SW_HIDE);
    ShowWindow(_w->console, console ? SW_SHOWNA : SW_HIDE);
    MoveWindow(_w->bar, 0, bottom, r.right, bh, TRUE);
    ShowWindow(_w->bar, bh ? SW_SHOWNA : SW_HIDE);
    // the bar: its buttons, the message, the progress
    int x = 2, row = win32Row();
    for(HWND b : _w->buttons) {
      int bw = (int)(INT_PTR)GetPropW(b, L"gmshWidth");
      MoveWindow(b, x, 3, bw, row, TRUE);
      x += bw + ((INT_PTR)GetPropW(b, L"gmshGapAfter") ? win32Px(.6) : 0);
    }
    int pw = IsWindowVisible(_w->progress) ? 200 : 0;
    MoveWindow(_w->message, x + win32Px(.6), 3,
               std::max(10, (int)r.right - x - win32Px(1.2) - pw), row, TRUE);
    MoveWindow(_w->progress, r.right - pw - 4, 5, pw, row - 4, TRUE);
  }

  // the gap under the pointer: 1 by the tree, 2 over the console
  int _gapAt(int x, int y)
  {
    if(!_w || _w->fullscreen) return 0;
    RECT r;
    GetClientRect(_w->win, &r);
    int bottom = r.bottom - _barHeight();
    bool tree = _w->treeShown && !_w->treeWin;
    if(tree && x >= _w->treeWidth && x < _w->treeWidth + Gap && y < bottom)
      return 1;
    if(_w->consoleShown) {
      int ch = std::max(20, std::min(_w->consoleHeight, bottom - 100));
      int at = bottom - ch - Gap;
      int left = tree ? _w->treeWidth + Gap : 0;
      if(x >= left && y >= at && y < at + Gap) return 2;
    }
    return 0;
  }

  // --- the console: a line in its colour, the lines again when the filter
  // changed, what the bar over them tells

  void _consoleLine(const std::string &text, int level)
  {
    static const COLORREF ink[] = {RGB(26, 79, 160), 0, RGB(160, 90, 0),
                                   RGB(176, 0, 0), RGB(112, 112, 112)};
    // where the view is, when it is not to follow the last line
    int first = _w->said.autoScroll() ?
                  0 :
                  (int)SendMessageW(_w->console, EM_GETFIRSTVISIBLELINE, 0, 0);
    CHARFORMAT2W cf;
    memset(&cf, 0, sizeof(cf));
    cf.cbSize = sizeof(cf);
    cf.dwMask = CFM_COLOR;
    if(level >= 0 && level <= 4 && level != Ui::Backend::Info)
      cf.crTextColor = ink[level];
    else
      cf.dwEffects = CFE_AUTOCOLOR;
    SendMessageW(_w->console, EM_SETSEL, (WPARAM)-1, (LPARAM)-1);
    SendMessageW(_w->console, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);
    std::wstring line = win32Wide(text + "\r\n");
    SendMessageW(_w->console, EM_REPLACESEL, FALSE, (LPARAM)line.c_str());
    // the caret after the last line break: at the bottom, on the left
    SendMessageW(_w->console, EM_SETSEL, (WPARAM)-1, (LPARAM)-1);
    if(_w->said.autoScroll())
      SendMessageW(_w->console, EM_SCROLLCARET, 0, 0);
    else {
      int now = (int)SendMessageW(_w->console, EM_GETFIRSTVISIBLELINE, 0, 0);
      SendMessageW(_w->console, EM_LINESCROLL, 0, first - now);
    }
  }

  void _consoleRefill()
  {
    SendMessageW(_w->console, WM_SETREDRAW, FALSE, 0);
    SetWindowTextW(_w->console, L"");
    for(const Ui::Console::Line *l : _w->said.shown())
      _consoleLine(l->text, l->level);
    SendMessageW(_w->console, WM_SETREDRAW, TRUE, 0);
    InvalidateRect(_w->console, nullptr, TRUE);
  }

  void _consoleClear()
  {
    if(!_w) return;
    _w->said.clear();
    SetWindowTextW(_w->console, L"");
  }

  LRESULT _consoleBarHook(HWND w, UINT msg, WPARAM wp, LPARAM lp, bool &taken)
  {
    taken = false;
    if(msg != WM_COMMAND || !_w) return 0;
    HWND from = (HWND)lp;
    if(from == _w->filter && HIWORD(wp) == EN_CHANGE) {
      if(_w->said.setFilter(win32Text(_w->filter))) _consoleRefill();
      taken = true;
    }
    else if(HIWORD(wp) == BN_CLICKED) {
      if(from == _w->save) {
        if(_sources.saveMessages) win32Later(_sources.saveMessages);
      }
      else if(from == _w->clear)
        _consoleClear();
      else if(from == _w->follow) {
        _w->said.setAutoScroll(
          SendMessageW(_w->follow, BM_GETCHECK, 0, 0) == BST_CHECKED);
        if(_w->said.autoScroll()) {
          SendMessageW(_w->console, EM_SETSEL, (WPARAM)-1, (LPARAM)-1);
          SendMessageW(_w->console, EM_SCROLLCARET, 0, 0);
        }
      }
      else
        return 0;
      taken = true;
    }
    return 0;
  }

  void _makeConsoleBar()
  {
    _w->consoleBar = win32Panel(_w->win, 0, 0, 10, 10);
    win32SetPanelHook(_w->consoleBar, _consoleBarHook);
    HINSTANCE app = GetModuleHandleW(nullptr);
    auto make = [app](const wchar_t *cls, DWORD style, const char *text) {
      HWND c = CreateWindowExW(0, cls, win32Wide(text).c_str(),
                               WS_CHILD | WS_VISIBLE | style, 0, 0, 10, 10,
                               _w->consoleBar, nullptr, app, nullptr);
      SendMessageW(c, WM_SETFONT, (WPARAM)win32Font(), TRUE);
      return c;
    };
    _w->look = make(L"STATIC", SS_ICON | SS_CENTERIMAGE | SS_REALSIZEIMAGE, "");
    if(HICON icon = win32Glyph(Ui::Console::filterGlyph(), win32Px(1.)))
      SendMessageW(_w->look, STM_SETICON, (WPARAM)icon, 0);
    _w->filter = make(L"EDIT", WS_TABSTOP | WS_BORDER | ES_AUTOHSCROLL, "");
    _w->save = make(L"BUTTON", WS_TABSTOP | BS_PUSHBUTTON,
                    Ui::Console::saveLabel());
    _w->clear = make(L"BUTTON", WS_TABSTOP | BS_PUSHBUTTON,
                     Ui::Console::clearLabel());
    _w->follow = make(L"BUTTON", WS_TABSTOP | BS_AUTOCHECKBOX,
                      Ui::Console::autoScrollLabel());
    SendMessageW(_w->follow, BM_SETCHECK,
                 _w->said.autoScroll() ? BST_CHECKED : BST_UNCHECKED, 0);
  }

  // --- the bar along the bottom

  LRESULT _barHook(HWND w, UINT msg, WPARAM wp, LPARAM lp, bool &taken)
  {
    taken = false;
    if(msg != WM_COMMAND || !_w) return 0;
    HWND ctl = (HWND)lp;
    if(ctl == _w->message && HIWORD(wp) == STN_CLICKED) {
      taken = true;
      if(_sources.barPressed) win32Later(_sources.barPressed);
      return 0;
    }
    INT_PTR k = (INT_PTR)GetPropW(ctl, L"gmshBar");
    if(!k || HIWORD(wp) != BN_CLICKED) return 0;
    taken = true;
    std::vector<Ui::BarButton> bar = _sources.barButtons();
    if((std::size_t)k > bar.size()) return 0;
    const Ui::BarButton &b = bar[(std::size_t)k - 1];
    // what shows it on or off is the refresh's to say
    SendMessageW(ctl, BM_SETCHECK, b.on && b.on() ? BST_CHECKED : BST_UNCHECKED, 0);
    if(b.menu) {
      RECT r;
      GetWindowRect(ctl, &r);
      std::vector<Ui::MenuItem> items = b.menu();
      win32PopupMenu(items, _w->win, r.left, r.top);
      return 0;
    }
    bool reverse = GetKeyState(VK_SHIFT) < 0, sync = GetKeyState(VK_CONTROL) < 0;
    std::function<void(bool, bool)> what = b.action;
    win32Later([what, reverse, sync]() {
      if(what) what(reverse, sync);
      win32RefreshBar();
    });
    return 0;
  }

  // --- the buttons under the tree

  LRESULT _footerHook(HWND w, UINT msg, WPARAM wp, LPARAM lp, bool &taken)
  {
    taken = false;
    if(msg != WM_COMMAND || !_w || HIWORD(wp) != BN_CLICKED) return 0;
    INT_PTR k = (INT_PTR)GetPropW((HWND)lp, L"gmshFooter");
    if(!k || (std::size_t)k > _w->footerSaid.size()) return 0;
    taken = true;
    const Ui::Button &b = _w->footerSaid[(std::size_t)k - 1];
    if(b.menu) {
      RECT r;
      GetWindowRect((HWND)lp, &r);
      win32PopupMenu(b.menu(), _w->win, r.left, r.bottom);
      return 0;
    }
    std::function<void()> what = b.action;
    win32Later([what]() {
      if(what) what();
      if(_w && _w->tree) win32RefreshTree(_w->tree, false);
    });
    return 0;
  }

  void _refreshFooter()
  {
    if(!_w) return;
    std::vector<Ui::Button> row =
      _sources.tree.footer ? _sources.tree.footer() : std::vector<Ui::Button>();
    std::string shape = Ui::signature(row);
    if(shape == _w->footerBuilt) return;
    _w->footerBuilt = shape;
    for(HWND b : _w->footerButtons) DestroyWindow(b);
    _w->footerButtons.clear();
    _w->footerSaid = row;
    for(std::size_t i = 0; i < row.size(); i++) {
      std::string label = row[i].label.size() ? row[i].label : "▾";
      HWND b = CreateWindowExW(0, L"BUTTON", win32Wide(label).c_str(),
                               WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
                               0, 0, 10, 10, _w->footer, nullptr,
                               GetModuleHandleW(nullptr), nullptr);
      SendMessageW(b, WM_SETFONT, (WPARAM)win32Font(), TRUE);
      SetPropW(b, L"gmshFooter", (HANDLE)(INT_PTR)(i + 1));
      win32ButtonShows(b, label, row[i].glyph);
      if(row[i].enabled) EnableWindow(b, row[i].enabled());
      _w->footerButtons.push_back(b);
    }
    _layout();
  }

  void _fullscreen(bool on)
  {
    if(!_w || on == _w->fullscreen) return;
    _w->fullscreen = on;
    if(on) {
      _w->beforeFullscreen.length = sizeof(WINDOWPLACEMENT);
      GetWindowPlacement(_w->win, &_w->beforeFullscreen);
      _w->styleBeforeFullscreen = GetWindowLongW(_w->win, GWL_STYLE);
      MONITORINFO mi = {sizeof(mi)};
      GetMonitorInfoW(MonitorFromWindow(_w->win, MONITOR_DEFAULTTONEAREST), &mi);
      SetWindowLongW(_w->win, GWL_STYLE,
                     _w->styleBeforeFullscreen & ~WS_OVERLAPPEDWINDOW);
      _w->menuBeforeFullscreen = GetMenu(_w->win);
      SetMenu(_w->win, nullptr);
      SetWindowPos(_w->win, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top,
                   mi.rcMonitor.right - mi.rcMonitor.left,
                   mi.rcMonitor.bottom - mi.rcMonitor.top,
                   SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
    }
    else {
      SetWindowLongW(_w->win, GWL_STYLE, _w->styleBeforeFullscreen);
      SetWindowPlacement(_w->win, &_w->beforeFullscreen);
      SetWindowPos(_w->win, nullptr, 0, 0, 0, 0,
                   SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER |
                     SWP_FRAMECHANGED);
      SetMenu(_w->win, _w->menuBeforeFullscreen);
      _w->menuBeforeFullscreen = nullptr;
    }
    _layout();
  }

  // --- the main window

  LRESULT CALLBACK _mainProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    switch(msg) {
    case WM_GMSH_LATER: win32RunLater(); return 0;
    case WM_SIZE: _layout(); return 0;
    case WM_COMMAND:
      if(HIWORD(wp) == 0 && !lp && win32MenuCommand(LOWORD(wp))) return 0;
      break;
    case WM_INITMENUPOPUP: win32MenuOpens((HMENU)wp); return 0;
    case WM_NOTIFY: {
      NMHDR *n = (NMHDR *)lp;
      LRESULT result = 0;
      if(_w && _w->tree && win32TreeNotify(_w->tree, n, result)) return result;
      break;
    }
    case WM_CONTEXTMENU:
      // the messages: saved, or forgotten
      if(_w && (HWND)wp == _w->console) {
        std::vector<Ui::MenuItem> items(2);
        items[0].label = "Save Messages As...";
        items[0].action = []() {
          if(_sources.saveMessages) _sources.saveMessages();
        };
        items[1].label = "Clear Messages";
        items[1].action = []() { _consoleClear(); };
        win32PopupMenu(items, w, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
        return 0;
      }
      break;
    case WM_SETCURSOR:
      if(LOWORD(lp) == HTCLIENT && _w) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(w, &p);
        int g = _w->dragging ? _w->dragging : _gapAt(p.x, p.y);
        if(g) {
          SetCursor(LoadCursor(nullptr, g == 1 ? IDC_SIZEWE : IDC_SIZENS));
          return TRUE;
        }
      }
      break;
    case WM_LBUTTONDOWN:
      if(_w && (_w->dragging = _gapAt(GET_X_LPARAM(lp), GET_Y_LPARAM(lp))))
        SetCapture(w);
      return 0;
    case WM_MOUSEMOVE:
      if(_w && _w->dragging) {
        RECT r;
        GetClientRect(w, &r);
        if(_w->dragging == 1)
          _w->treeWidth = std::max(80, (int)GET_X_LPARAM(lp));
        else
          _w->consoleHeight =
            std::max(20, (int)(r.bottom - _barHeight() - GET_Y_LPARAM(lp)));
        _layout();
      }
      return 0;
    case WM_LBUTTONUP:
      if(_w && _w->dragging) {
        _w->dragging = 0;
        ReleaseCapture();
      }
      return 0;
    case WM_DROPFILES: {
      HDROP drop = (HDROP)wp;
      std::vector<std::string> paths;
      UINT n = DragQueryFileW(drop, 0xFFFFFFFF, nullptr, 0);
      for(UINT i = 0; i < n; i++) {
        wchar_t path[MAX_PATH * 4];
        if(DragQueryFileW(drop, i, path, MAX_PATH * 4))
          paths.push_back(win32Utf8(path));
      }
      DragFinish(drop);
      std::function<void(const std::vector<std::string> &)> open = _host.filesDropped;
      if(open && paths.size()) win32Later([open, paths]() { open(paths); });
      return 0;
    }
    case WM_CLOSE: {
      std::function<void()> quit = _host.quitting;
      if(quit)
        win32Later(quit);
      else
        _running = false;
      return 0;
    }
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

  // --- the tree in a window of its own

  void _detachTree(bool detached);

  LRESULT CALLBACK _treeProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    switch(msg) {
    case WM_GMSH_LATER: win32RunLater(); return 0;
    case WM_SIZE:
      if(_w && _w->treeWin == w) {
        RECT r;
        GetClientRect(w, &r);
        MoveWindow(_w->treeBox, 0, 0, r.right, r.bottom, TRUE);
        _layoutTree(r.right, r.bottom);
      }
      return 0;
    case WM_COMMAND:
      if(HIWORD(wp) == 0 && !lp && win32MenuCommand(LOWORD(wp))) return 0;
      break;
    case WM_INITMENUPOPUP: win32MenuOpens((HMENU)wp); return 0;
    case WM_CLOSE:
      // closed from its frame, it goes back in the main window: closed, it
      // could not be had back
      win32Later([]() { _detachTree(false); });
      return 0;
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

  void _detachTree(bool detached)
  {
    if(!_w || detached == (_w->treeWin != nullptr)) return;
    if(detached) {
      static bool registered = false;
      if(!registered) {
        registered = true;
        WNDCLASSEXW wc;
        memset(&wc, 0, sizeof(wc));
        wc.cbSize = sizeof(wc);
        wc.lpfnWndProc = _treeProc;
        wc.hInstance = GetModuleHandleW(nullptr);
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
        wc.hIcon = LoadIconW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(1));
        wc.lpszClassName = L"GmshTree";
        RegisterClassExW(&wc);
      }
      const Ui::Backend::Settings set = _sources.settings();
      RECT want = {0, 0, _w->treeWidth, set.treeHeight > 0 ? set.treeHeight : 600};
      AdjustWindowRectEx(&want, WS_OVERLAPPEDWINDOW, FALSE, 0);
      bool placed = set.treeX > 0 || set.treeY > 0;
      _w->treeWin = CreateWindowExW(
        0, L"GmshTree", L"Gmsh", WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
        placed ? set.treeX : CW_USEDEFAULT, placed ? set.treeY : CW_USEDEFAULT,
        want.right - want.left, want.bottom - want.top, nullptr, nullptr,
        GetModuleHandleW(nullptr), nullptr);
      if(!_w->treeWin) return;
      SetParent(_w->treeBox, _w->treeWin);
      ShowWindow(_w->treeBox, SW_SHOWNA);
      ShowWindow(_w->treeWin, SW_SHOWNORMAL);
      RECT r;
      GetClientRect(_w->treeWin, &r);
      MoveWindow(_w->treeBox, 0, 0, r.right, r.bottom, TRUE);
      _layoutTree(r.right, r.bottom);
      _layout();
      return;
    }
    RECT r;
    if(GetWindowRect(_w->treeWin, &r) && _host.layoutChanged) {
      Ui::Backend::Layout l;
      l.treeX = r.left;
      l.treeY = r.top;
      RECT c;
      GetClientRect(_w->treeWin, &c);
      l.treeHeight = c.bottom;
      _host.layoutChanged(l);
    }
    SetParent(_w->treeBox, _w->win);
    HWND was = _w->treeWin;
    _w->treeWin = nullptr;
    DestroyWindow(was);
    _layout();
  }

  bool _build()
  {
    const Ui::Backend::Settings set = _sources.settings();
    WNDCLASSEXW wc;
    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = _mainProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
    wc.hIcon = LoadIconW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(1));
    wc.lpszClassName = L"GmshMain";
    RegisterClassExW(&wc);
    _w = new mainWindow;
    _w->treeWidth = set.treeWidth > 50 ? set.treeWidth : 300;
    _w->consoleHeight = set.consoleHeight > 0 ? set.consoleHeight : 150;
    _w->treeShown = set.showModuleMenu;
    int width = (set.sceneWidth > 100 ? set.sceneWidth : 700) + _w->treeWidth;
    int height = (set.sceneHeight > 100 ? set.sceneHeight : 600) +
                 _w->consoleHeight + 80;
    _w->win = CreateWindowExW(WS_EX_ACCEPTFILES, L"GmshMain", L"Gmsh",
                              WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
                              CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                              nullptr, nullptr, GetModuleHandleW(nullptr),
                              nullptr);
    if(!_w->win) return false;
    win32SetMainWindow(_w->win);
    if(set.darkScheme) {
      BOOL dark = TRUE;
      DwmSetWindowAttribute(_w->win, 20 /* DWMWA_USE_IMMERSIVE_DARK_MODE */,
                            &dark, sizeof(dark));
    }

    // the tree, the field of the line picked, the buttons of the solver
    _w->treeBox = win32Panel(_w->win, 0, 0, 10, 10);
    _w->tree = win32MakeTree(_w->treeBox, _sources.tree, false, []() {
      win32Later([]() {
        if(_w && _w->tree) win32RefreshTree(_w->tree, false);
        _layout();
      });
    });
    _w->editor = win32Panel(_w->treeBox, 0, 0, 10, 10);
    win32SetTreeEditor(_w->tree, _w->editor);
    _w->footer = win32Panel(_w->treeBox, 0, 0, 10, 10);
    win32SetPanelHook(_w->footer, _footerHook);

    _w->scene = win32SceneWindow(_w->win);

    // the console, in colours
    LoadLibraryW(L"Msftedit.dll");
    _w->console = CreateWindowExW(
      WS_EX_CLIENTEDGE, MSFTEDIT_CLASS, L"",
      WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE |
        ES_READONLY | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_NOHIDESEL,
      0, 0, 10, 10, _w->win, nullptr, GetModuleHandleW(nullptr), nullptr);
    SendMessageW(_w->console, WM_SETFONT, (WPARAM)win32FixedFont(), TRUE);
    SendMessageW(_w->console, EM_EXLIMITTEXT, 0, 64 * 1024 * 1024);
    _makeConsoleBar();

    // the bar
    _w->bar = win32Panel(_w->win, 0, 0, 10, 10);
    win32SetPanelHook(_w->bar, _barHook);
    _w->message = CreateWindowExW(0, L"STATIC", L"",
                                  WS_CHILD | WS_VISIBLE | SS_NOTIFY |
                                    SS_NOPREFIX | SS_LEFTNOWORDWRAP |
                                    SS_ENDELLIPSIS | SS_CENTERIMAGE,
                                  0, 0, 10, 10, _w->bar, nullptr,
                                  GetModuleHandleW(nullptr), nullptr);
    SendMessageW(_w->message, WM_SETFONT, (WPARAM)win32Font(), TRUE);
    _w->progress = CreateWindowExW(0, PROGRESS_CLASSW, L"", WS_CHILD, 0, 0, 10,
                                   10, _w->bar, nullptr,
                                   GetModuleHandleW(nullptr), nullptr);
    SendMessageW(_w->progress, PBM_SETRANGE32, 0, 1000);

    win32RefreshMenuBar(_w->win);
    _refreshFooter();
    win32RefreshBar();
    ShowWindow(_w->win, SW_SHOW);
    UpdateWindow(_w->win);
    _layout();
    if(set.detachedTree) _detachTree(true);
    return true;
  }

  // --- the loop

  void _dispatch(MSG &m)
  {
    if((m.message == WM_KEYDOWN || m.message == WM_SYSKEYDOWN) &&
       win32MainKey(m))
      return;
    if(win32FormDialogMessage(m)) return;
    TranslateMessage(&m);
    DispatchMessageW(&m);
  }

  void _pump()
  {
    MSG m;
    while(PeekMessageW(&m, nullptr, 0, 0, PM_REMOVE)) {
      if(m.message == WM_QUIT) {
        _running = false;
        break;
      }
      _dispatch(m);
    }
    win32ScenePump();
  }

  // at most that many seconds, below zero as long as nothing happens
  void _waitAndPump(double seconds)
  {
    double next = win32SceneNextTimer();
    if(next >= 0. && (seconds < 0. || next < seconds)) seconds = next;
    DWORD ms = seconds < 0. ? INFINITE : (DWORD)(seconds * 1000.);
    MsgWaitForMultipleObjectsEx(0, nullptr, ms, QS_ALLINPUT,
                                MWMO_INPUTAVAILABLE);
    _pump();
  }

  // --- asking the user

  struct asking {
    bool done = false;
    int answer = 0;
  };

  LRESULT _askHook(HWND w, UINT msg, WPARAM wp, LPARAM lp, bool &taken)
  {
    asking *a = (asking *)GetPropW(GetAncestor(w, GA_ROOT), L"gmshAsking");
    taken = false;
    if(!a) return 0;
    if(msg == WM_CLOSE) {
      taken = true;
      a->answer = 0;
      a->done = true;
    }
    else if(msg == WM_COMMAND && (LOWORD(wp) == IDOK || LOWORD(wp) == IDCANCEL)) {
      taken = true;
      a->answer = LOWORD(wp) == IDOK ? 1 : 0;
      a->done = true;
    }
    return 0;
  }

  bool _runModal(HWND dialog, asking &a)
  {
    HWND owner = _w ? _w->win : nullptr;
    if(owner) EnableWindow(owner, FALSE);
    while(!a.done) {
      MSG m;
      if(!GetMessageW(&m, nullptr, 0, 0)) {
        _running = false;
        break;
      }
      if(IsDialogMessageW(dialog, &m)) continue;
      TranslateMessage(&m);
      DispatchMessageW(&m);
    }
    if(owner) {
      EnableWindow(owner, TRUE);
      SetForegroundWindow(owner);
    }
    return a.answer == 1;
  }

  // as Windows writes a filter: the patterns separated by ';'
  std::wstring _patterns(const Ui::Backend::FileFormat &f)
  {
    std::string out;
    for(const auto &p : f.patterns()) out += (out.size() ? ";" : "") + p;
    return win32Wide(out.empty() ? "*" : out);
  }

  std::string _path(IShellItem *item)
  {
    wchar_t *name = nullptr;
    std::string out;
    if(SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &name)) && name) {
      out = win32Utf8(name);
      CoTaskMemFree(name);
    }
    return out;
  }

  // --- the backend

  class backendWin32 : public Ui::Backend {
  public:
    std::string name() override { return "Win32"; }

    void setSources(const Sources &sources) override { _sources = sources; }
    void setHost(const Host &host) override { _host = host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(_w) return true;
      _quitShouldExit = quitShouldExit;
      INITCOMMONCONTROLSEX icc = {sizeof(icc), ICC_WIN95_CLASSES |
                                                 ICC_STANDARD_CLASSES |
                                                 ICC_TAB_CLASSES |
                                                 ICC_LINK_CLASS |
                                                 ICC_PROGRESS_CLASS |
                                                 ICC_BAR_CLASSES};
      InitCommonControlsEx(&icc);
      CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
      if(!_build()) {
        if(_host.error) _host.error("Could not create the main window");
        return false;
      }
      return true;
    }

    void destroy() override
    {
      _running = false;
      if(!_w) return;
      win32FormsClosingDown();
      win32DropTree(_w->tree);
      _w->tree = nullptr;
      win32SceneDestroy();
      HWND win = _w->win, treeWin = _w->treeWin;
      delete _w;
      _w = nullptr;
      win32SetMainWindow(nullptr);
      DestroyWindow(win);
      if(treeWin) DestroyWindow(treeWin);
    }

    int runLoop() override
    {
      _running = true;
      while(_running && _w) _waitAndPump(-1.);
      return 0;
    }

    void check(bool rateLimited) override
    {
      if(!_w || _locked > 0 || win32SceneDrawing()) return;
      _pump();
    }

    bool ready() override { return _w != nullptr; }

    void wait(double seconds, bool force) override
    {
      if(!_w || win32SceneDrawing()) return;
      if(!force && _locked > 0) return;
      _waitAndPump(seconds);
    }

    void lock() override { _locked++; }
    void unlock() override { _locked--; }
    int locked() override { return _locked; }

    // win32Later() posts to the main window, which any thread may do
    void postFromThread(const std::function<void()> &what) override
    {
      win32Later(what);
    }

    void copyText(const std::string &text) override
    {
      if(!_w || !OpenClipboard(_w->win)) return;
      std::wstring w = win32Wide(text);
      HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, (w.size() + 1) * sizeof(wchar_t));
      if(mem) {
        memcpy(GlobalLock(mem), w.c_str(), (w.size() + 1) * sizeof(wchar_t));
        GlobalUnlock(mem);
        EmptyClipboard();
        SetClipboardData(CF_UNICODETEXT, mem);
      }
      CloseClipboard();
    }

    void beep() override { MessageBeep(MB_OK); }

    // --- messages, the bar

    void addMessage(const std::string &text, int level) override
    {
      if(_w && _w->said.add(text, level)) _consoleLine(text, level);
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(_w) lines = _w->said.texts();
    }

    void refreshBar() override { win32RefreshBar(); }

    void optionChanged(const std::string &name) override
    {
      win32FormOptionChanged(name);
    }

    int numWindows() override { return _w ? 1 : 0; }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(_w && which == 0) SetWindowTextW(_w->win, win32Wide(title).c_str());
    }

    // --- the questions that stop everything

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      asking a;
      bool lines = readOnly || hint.size() || value.find('\n') != std::string::npos;
      int em = (int)win32Em(), row = win32Row(), pad = em;
      int w = 36 * em, textH = lines ? (readOnly ? 20 : 8) * em : row;
      std::string ask = question + (hint.size() ? "\n" + hint : "");
      // the question, as tall as it needs
      HDC dc = GetDC(nullptr);
      HGDIOBJ was = SelectObject(dc, win32Font());
      std::wstring q = win32Wide(ask);
      RECT qr = {0, 0, w - 2 * pad, 0};
      DrawTextW(dc, q.c_str(), (int)q.size(), &qr, DT_CALCRECT | DT_WORDBREAK);
      SelectObject(dc, was);
      ReleaseDC(nullptr, dc);
      int qh = qr.bottom - qr.top;
      int ch = pad + qh + pad + textH + pad + row + pad;
      RECT r = {0, 0, w, ch};
      DWORD style = WS_POPUP | WS_CAPTION | WS_SYSMENU;
      AdjustWindowRectEx(&r, style, FALSE, WS_EX_DLGMODALFRAME);
      HWND d = CreateWindowExW(WS_EX_DLGMODALFRAME | WS_EX_CONTROLPARENT,
                               win32PanelClass(), L"Gmsh", style, CW_USEDEFAULT,
                               CW_USEDEFAULT, r.right - r.left, r.bottom - r.top,
                               _w ? _w->win : nullptr, nullptr,
                               GetModuleHandleW(nullptr), nullptr);
      SetPropW(d, L"gmshAsking", (HANDLE)&a);
      win32SetPanelHook(d, _askHook);
      auto make = [d](const wchar_t *cls, DWORD style, int x, int y, int w,
                      int h, const std::wstring &text, int id,
                      DWORD ex = 0) {
        HWND c = CreateWindowExW(ex, cls, text.c_str(), WS_CHILD | WS_VISIBLE | style,
                                 x, y, w, h, d, (HMENU)(INT_PTR)id,
                                 GetModuleHandleW(nullptr), nullptr);
        SendMessageW(c, WM_SETFONT, (WPARAM)win32Font(), TRUE);
        return c;
      };
      make(L"STATIC", SS_NOPREFIX, pad, pad, w - 2 * pad, qh, q, -1);
      std::wstring v = win32Wide(value);
      if(lines) {
        // Windows ends a line with a carriage return and a line feed
        std::wstring crlf;
        for(wchar_t c : v) {
          if(c == L'\n') crlf += L'\r';
          crlf += c;
        }
        v = crlf;
      }
      HWND edit = make(L"EDIT",
                       WS_TABSTOP | ES_AUTOHSCROLL |
                         (lines ? ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL |
                                    ES_WANTRETURN :
                                  0) |
                         (readOnly ? ES_READONLY : 0),
                       pad, 2 * pad + qh, w - 2 * pad, textH, v, 100,
                       WS_EX_CLIENTEDGE);
      if(lines) SendMessageW(edit, WM_SETFONT, (WPARAM)win32FixedFont(), TRUE);
      int bw = 75 * (int)win32Em() / 12, by = 3 * pad + qh + textH;
      if(readOnly)
        make(L"BUTTON", WS_TABSTOP | BS_DEFPUSHBUTTON, w - pad - bw, by, bw, row,
             L"Close", IDCANCEL);
      else {
        make(L"BUTTON", WS_TABSTOP | BS_PUSHBUTTON, w - 2 * pad - 2 * bw, by, bw,
             row, L"Cancel", IDCANCEL);
        make(L"BUTTON", WS_TABSTOP | BS_DEFPUSHBUTTON, w - pad - bw, by, bw, row,
             L"OK", IDOK);
      }
      ShowWindow(d, SW_SHOW);
      SetFocus(edit);
      if(!lines) SendMessageW(edit, EM_SETSEL, 0, -1);
      bool ok = _runModal(d, a) && !readOnly;
      if(ok) {
        std::string said = win32Text(edit), out;
        for(char c : said)
          if(c != '\r') out += c;
        value = out;
      }
      DestroyWindow(d);
      return ok;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      const std::string *said[3] = {&zero, &one, &two};
      std::vector<std::wstring> labels;
      std::vector<TASKDIALOG_BUTTON> buttons;
      for(int i = 0; i < 3; i++)
        if(said[i]->size()) labels.push_back(win32Wide(*said[i]));
      int k = 0;
      for(int i = 0; i < 3; i++)
        if(said[i]->size()) {
          TASKDIALOG_BUTTON b = {100 + i, labels[(std::size_t)k++].c_str()};
          buttons.push_back(b);
        }
      std::wstring text = win32Wide(question);
      TASKDIALOGCONFIG c;
      memset(&c, 0, sizeof(c));
      c.cbSize = sizeof(c);
      c.hwndParent = _w ? _w->win : nullptr;
      c.dwFlags = TDF_ALLOW_DIALOG_CANCELLATION | TDF_POSITION_RELATIVE_TO_WINDOW;
      c.pszWindowTitle = L"Gmsh";
      c.pszContent = text.c_str();
      c.cButtons = (UINT)buttons.size();
      c.pButtons = buttons.data();
      // Return presses the second, or the only one, as fl_choice() has it
      c.nDefaultButton = one.size() ? 101 : 100;
      // through the common controls of version 6, which the manifest asks for
      typedef HRESULT(WINAPI * taskDialog)(const TASKDIALOGCONFIG *, int *, int *,
                                           BOOL *);
      HMODULE comctl = GetModuleHandleW(L"comctl32.dll");
      taskDialog show =
        comctl ? (taskDialog)(void *)GetProcAddress(comctl, "TaskDialogIndirect") :
                 nullptr;
      int pressed = 0;
      if(show && SUCCEEDED(show(&c, &pressed, nullptr, nullptr)))
        return pressed >= 100 && pressed < 103 ? pressed - 100 : 0;
      // no task dialog: the question, and Yes for the second answer
      int r = MessageBoxW(c.hwndParent, text.c_str(), L"Gmsh",
                          one.size() ? MB_YESNO : MB_OK);
      return r == IDYES ? 1 : 0;
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      IFileDialog *d = nullptr;
      HRESULT hr = CoCreateInstance(mode == Create ? CLSID_FileSaveDialog :
                                                     CLSID_FileOpenDialog,
                                    nullptr, CLSCTX_INPROC_SERVER,
                                    mode == Create ? IID_IFileSaveDialog :
                                                     IID_IFileOpenDialog,
                                    (void **)&d);
      if(FAILED(hr) || !d) return false;
      std::vector<std::wstring> keep;
      std::vector<COMDLG_FILTERSPEC> specs;
      keep.reserve(2 * formats.size());
      for(const auto &f : formats) {
        keep.push_back(win32Wide(f.name.size() ? f.name : f.pattern));
        keep.push_back(_patterns(f));
      }
      for(std::size_t i = 0; i < formats.size(); i++)
        specs.push_back({keep[2 * i].c_str(), keep[2 * i + 1].c_str()});
      if(specs.size()) {
        d->SetFileTypes((UINT)specs.size(), specs.data());
        d->SetFileTypeIndex(1);
      }
      d->SetTitle(win32Wide(title).c_str());
      FILEOPENDIALOGOPTIONS options = 0;
      d->GetOptions(&options);
      options |= FOS_FORCEFILESYSTEM | FOS_NOCHANGEDIR;
      // Gmsh asks itself before a file is overwritten
      if(mode == Create) options &= ~FOS_OVERWRITEPROMPT;
      if(mode == OpenSeveral) options |= FOS_ALLOWMULTISELECT;
      d->SetOptions(options);
      std::string from = names.empty() ? "" : names[0];
      if(from.size()) {
        std::string dir = from, base;
        DWORD attributes = GetFileAttributesW(win32Wide(from).c_str());
        if(attributes == INVALID_FILE_ATTRIBUTES ||
           !(attributes & FILE_ATTRIBUTE_DIRECTORY)) {
          std::size_t slash = from.find_last_of("/\\");
          dir = slash == std::string::npos ? "" : from.substr(0, slash);
          base = slash == std::string::npos ? from : from.substr(slash + 1);
        }
        IShellItem *folder = nullptr;
        if(dir.size() &&
           SUCCEEDED(SHCreateItemFromParsingName(win32Wide(dir).c_str(), nullptr,
                                                 IID_IShellItem,
                                                 (void **)&folder))) {
          d->SetFolder(folder);
          folder->Release();
        }
        if(base.size() && mode == Create) d->SetFileName(win32Wide(base).c_str());
      }
      std::vector<std::string> out;
      if(SUCCEEDED(d->Show(_w ? _w->win : nullptr))) {
        if(mode == OpenSeveral) {
          IShellItemArray *items = nullptr;
          if(SUCCEEDED(((IFileOpenDialog *)d)->GetResults(&items)) && items) {
            DWORD n = 0;
            items->GetCount(&n);
            for(DWORD i = 0; i < n; i++) {
              IShellItem *item = nullptr;
              if(SUCCEEDED(items->GetItemAt(i, &item)) && item) {
                out.push_back(_path(item));
                item->Release();
              }
            }
            items->Release();
          }
        }
        else {
          IShellItem *item = nullptr;
          if(SUCCEEDED(d->GetResult(&item)) && item) {
            out.push_back(_path(item));
            item->Release();
          }
        }
        // several formats may share an extension: the one picked is said
        UINT index = 0;
        if(chosenFormat && SUCCEEDED(d->GetFileTypeIndex(&index)))
          *chosenFormat = index > 0 ? (int)index - 1 : -1;
      }
      d->Release();
      if(out.empty()) return false;
      names = out;
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      if(!_w) return;
      BOOL on = dark ? TRUE : FALSE;
      DwmSetWindowAttribute(_w->win, 20 /* DWMWA_USE_IMMERSIVE_DARK_MODE */, &on,
                            sizeof(on));
    }

    // --- the things that are described

    void showForm(const Ui::Form &form, bool show) override
    {
      win32ShowForm(form, show);
    }
    bool formVisible(const Ui::Form &form) override
    {
      return win32FormVisible(form);
    }
    std::string formPane(const Ui::Form &form) override
    {
      return win32FormPane(form);
    }
    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      win32SetFormPane(form, pane);
    }
    void reloadForm(const Ui::Form &form) override { win32ReloadForm(form); }
    void rebuildForm(const Ui::Form &form) override { win32ReloadForm(form); }
    void dropForm(const Ui::Form &form) override { win32DropForm(form); }

    void refreshMenus() override
    {
      if(_w && !_w->fullscreen) win32RefreshMenuBar(_w->win);
    }

    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &) override
    {
      win32PopupMenu(items, _w ? _w->win : nullptr);
    }

    void refreshTree(bool rebuild) override
    {
      if(!_w || !_w->tree) return;
      win32SetTree(_w->tree, _sources.tree);
      win32RefreshTree(_w->tree, rebuild);
      _refreshFooter();
      _layout();
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      if(_w && _w->tree) win32OpenTreeItem(_w->tree, name, open);
    }

    bool treeItemOpen(const std::string &name) override
    {
      return _w && _w->tree && win32TreeItemOpen(_w->tree, name);
    }

    void showTree() override
    {
      if(!_w) return;
      _w->treeShown = true;
      _layout();
    }

    void setSolverButtonMode(const std::string &, const std::string &) override
    {
      _refreshFooter();
    }

    void showConsole(bool show) override
    {
      if(!_w) return;
      _w->consoleShown = show;
      _layout();
    }

    bool consoleVisible() override { return _w && _w->consoleShown; }

    void windowAction(const std::string &what) override
    {
      if(!_w) return;
      if(what == "new")
        win32SceneNewWindow();
      else if(what == "minimize")
        ShowWindow(_w->win, SW_MINIMIZE);
      else if(what == "zoom")
        ShowWindow(_w->win, IsZoomed(_w->win) ? SW_RESTORE : SW_MAXIMIZE);
      else if(what == "fullscreen")
        _fullscreen(!_w->fullscreen);
      else if(what == "front")
        SetForegroundWindow(_w->win);
      else if(what == "show_hide_tree") {
        _w->treeShown = !_w->treeShown;
        if(_w->treeWin)
          ShowWindow(_w->treeWin, _w->treeShown ? SW_SHOWNA : SW_HIDE);
        _layout();
      }
      else if(what == "attach_detach")
        _detachTree(!_w->treeWin);
      else if(_host.error)
        _host.error("Unknown window action '" + what + "'");
    }

    void detachTree(bool detached) override { _detachTree(detached); }

    Layout windowLayout() override
    {
      Layout l;
      if(!_w || _w->fullscreen) return l;
      win32SceneSize(l.sceneWidth, l.sceneHeight);
      if(_w->treeShown && !_w->treeWin) l.treeWidth = _w->treeWidth;
      if(_w->consoleShown) l.consoleHeight = _w->consoleHeight;
      l.treeDetached = _w->treeWin ? 1 : 0;
      RECT t;
      if(_w->treeWin && GetWindowRect(_w->treeWin, &t)) {
        l.treeX = t.left;
        l.treeY = t.top;
        RECT c;
        GetClientRect(_w->treeWin, &c);
        l.treeHeight = c.bottom;
      }
      RECT r;
      if(GetWindowRect(_w->win, &r)) {
        l.sceneX = r.left;
        l.sceneY = r.top;
      }
      return l;
    }

    void setSceneSize(int width, int height) override
    {
      if(!_w) return;
      int sw = 0, sh = 0;
      win32SceneSize(sw, sh);
      RECT r;
      GetWindowRect(_w->win, &r);
      int ww = r.right - r.left, wh = r.bottom - r.top;
      if(width >= 0) ww += width - sw;
      if(height >= 0) wh += height - sh;
      SetWindowPos(_w->win, nullptr, 0, 0, ww, wh, SWP_NOMOVE | SWP_NOZORDER);
    }

    void setConsoleFontSize(int size) override {}

    void setTreeWidth(int width) override
    {
      if(!_w || width < 0) return;
      _w->treeWidth = width;
      if(_w->treeWin) {
        RECT r;
        GetWindowRect(_w->treeWin, &r);
        RECT c;
        GetClientRect(_w->treeWin, &c);
        SetWindowPos(_w->treeWin, nullptr, 0, 0,
                     (r.right - r.left) - c.right + width, r.bottom - r.top,
                     SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
      }
      _layout();
    }

    void enableTooltips(bool on) override {}
  };

  backendWin32 *_the = nullptr;

} // namespace

void win32RefreshBar()
{
  if(!_w || !_sources.barButtons) return;
  std::vector<Ui::BarButton> bar = _sources.barButtons();
  std::string shape = Ui::signature(bar);
  if(shape != _w->barBuilt) {
    _w->barBuilt = shape;
    for(HWND b : _w->buttons) DestroyWindow(b);
    _w->buttons.clear();
    for(std::size_t i = 0; i < bar.size(); i++) {
      // pushed in while it is on
      HWND b = CreateWindowExW(0, L"BUTTON", win32Wide(bar[i].label).c_str(),
                               WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX |
                                 BS_PUSHLIKE,
                               0, 0, 10, 10, _w->bar, nullptr,
                               GetModuleHandleW(nullptr), nullptr);
      SendMessageW(b, WM_SETFONT, (WPARAM)win32Font(), TRUE);
      SetPropW(b, L"gmshBar", (HANDLE)(INT_PTR)(i + 1));
      int width = std::max(win32Px(bar[i].widthEm > 0. ? bar[i].widthEm : 1.6),
                           win32Px(.8) + (int)(win32Em() * .6 *
                                               std::max(bar[i].label.size(),
                                                        bar[i].labelOn.size())));
      SetPropW(b, L"gmshWidth", (HANDLE)(INT_PTR)width);
      if(i + 1 < bar.size() && bar[i + 1].gapBefore)
        SetPropW(b, L"gmshGapAfter", (HANDLE)(INT_PTR)1);
      _w->buttons.push_back(b);
    }
  }
  for(std::size_t i = 0; i < bar.size() && i < _w->buttons.size(); i++) {
    const Ui::BarButton &b = bar[i];
    HWND w = _w->buttons[i];
    bool on = b.on && b.on();
    std::string label = (on && b.labelOn.size()) ? b.labelOn : b.label;
    std::string glyph = (on && b.glyphOn.size()) ? b.glyphOn : b.glyph;
    // what warns is said so, the button being unable to take a colour
    if(b.alert && b.alert()) label = "!" + label;
    win32ButtonShows(w, label, glyph);
    SendMessageW(w, BM_SETCHECK, on ? BST_CHECKED : BST_UNCHECKED, 0);
    EnableWindow(w, b.enabled ? b.enabled() : TRUE);
  }
  if(_sources.barMessage) {
    Ui::BarMessage m = _sources.barMessage();
    if(win32Text(_w->message) != m.text)
      SetWindowTextW(_w->message, win32Wide(m.text).c_str());
    // the progress of what has finished stays said, at nought or at the end
    bool going = m.running && m.fraction > 0. && m.fraction < 1.;
    if(going != (IsWindowVisible(_w->progress) != 0)) {
      ShowWindow(_w->progress, going ? SW_SHOWNA : SW_HIDE);
      _layout();
    }
    if(going) SendMessageW(_w->progress, PBM_SETPOS, (WPARAM)(1000. * m.fraction), 0);
  }
}

bool win32MainKey(const MSG &m)
{
  switch(m.wParam) {
  case VK_SHIFT:
  case VK_CONTROL:
  case VK_MENU:
  case VK_LWIN:
  case VK_RWIN: return false;
  default: break;
  }
  // what is typed in a line of text is the line's
  HWND focus = GetFocus();
  wchar_t cls[32] = L"";
  if(focus) GetClassNameW(focus, cls, 32);
  bool typing = !_wcsicmp(cls, L"Edit") &&
                !(GetWindowLongW(focus, GWL_STYLE) & ES_READONLY);
  bool command = GetKeyState(VK_CONTROL) < 0 || GetKeyState(VK_MENU) < 0;
  if(typing && !command && m.wParam != VK_F1 && !(m.wParam >= VK_F2 && m.wParam <= VK_F12))
    return false;
  // Escape and Return in a window of a form are its own
  HWND root = GetAncestor(m.hwnd, GA_ROOT);
  if(root && GetPropW(root, L"gmshDialog") &&
     (m.wParam == VK_ESCAPE || m.wParam == VK_RETURN || m.wParam == VK_TAB))
    return false;
  int key = 0;
  unsigned mods = 0;
  if(!win32UiKey(m.wParam, m.lParam, key, mods)) return false;
  if(key == Ui::KeyEscape && _w && _w->fullscreen) {
    _fullscreen(false);
    return true;
  }
  if(!_sources.keys) return false;
  bool taken = false;
  for(const Ui::KeyBinding &k : _sources.keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    taken = true;
    if(k.action) win32Later(k.action);
    if(k.spent) break;
  }
  if(taken) win32Later([]() { win32RefreshBar(); });
  return taken;
}

const Ui::Backend::Sources &win32Sources()
{
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _sources : none;
}

const Ui::Backend::Host &win32Host() { return _host; }

// made once
namespace {
  struct offeringWin32 {
    offeringWin32()
    {
      Ui::offer("win32", []() -> Ui::Backend * {
        if(!_the) _the = new backendWin32();
        return _the;
      });
    }
  };
  offeringWin32 _offeringWin32;
} // namespace
