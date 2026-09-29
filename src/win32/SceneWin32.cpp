// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Win32 interface, see GuiPanes.h: each view a child window
// with an OpenGL context of its own (WGL), sharing what can be shared with the
// others; the views of the main window split as the Dear ImGui interface
// splits its panes, a new graphic window a window holding one more

#include "GmshConfig.h"

#include <algorithm>
#include <cstring>

#include "win32Common.h"
#include <windowsx.h>

#include "Gui.h"
#include "GuiPanes.h"
#include "sceneHost.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"

namespace {

  struct pane : public GuiPanes::Pane {
    HWND hwnd = nullptr;
    HDC dc = nullptr;
    HGLRC gl = nullptr;
    // the window of a graphic window of its own
    HWND top = nullptr;
    bool tracking = false;
  };

  // how the tiled panes share the room, as the Dear ImGui interface has it
  struct node {
    pane *leaf = nullptr;
    char split = 0; // 'h' side by side, 'v' one above the other
    double ratio = .5;
    node *child[2] = {nullptr, nullptr};
  };

  node *_root = nullptr;
  HWND _box = nullptr;
  HGLRC _shared = nullptr;

  GuiPanes &_all() { return GuiPanes::instance(); }

  pane *_pane(GuiPanes::Pane *p) { return static_cast<pane *>(p); }

  pane *_paneOf(HWND w) { return w ? (pane *)GetPropW(w, L"gmshPane") : nullptr; }

  bool _prepare(pane *p)
  {
    if(!p || !p->gl) return false;
    if(!wglMakeCurrent(p->dc, p->gl)) return false;
    glShader::setWindowFramebuffer(0);
    return true;
  }

  void _modifiers(pane *p, WPARAM wp)
  {
    p->modifiers((wp & MK_SHIFT) != 0, (wp & MK_CONTROL) != 0,
                 GetKeyState(VK_MENU) < 0,
                 GetKeyState(VK_LWIN) < 0 || GetKeyState(VK_RWIN) < 0);
  }

  LRESULT CALLBACK _paneProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    pane *p = _paneOf(w);
    if(!p) return DefWindowProcW(w, msg, wp, lp);
    switch(msg) {
    case WM_ERASEBKGND: return 1;
    case WM_PAINT: {
      PAINTSTRUCT ps;
      BeginPaint(w, &ps);
      if(_prepare(p)) {
        _all().draw(p);
        SwapBuffers(p->dc);
      }
      EndPaint(w, &ps);
      return 0;
    }
    case WM_MOUSEMOVE:
      if(!p->tracking) {
        TRACKMOUSEEVENT t = {sizeof(t), TME_LEAVE, w, 0};
        TrackMouseEvent(&t);
        p->tracking = true;
      }
      _all().setCurrent(p);
      _modifiers(p, wp);
      p->moved(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
      return 0;
    case WM_MOUSELEAVE:
      p->tracking = false;
      p->left();
      return 0;
    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_LBUTTONDBLCLK: {
      int b = (msg == WM_RBUTTONDOWN) ? 1 : (msg == WM_MBUTTONDOWN) ? 2 : 0;
      SetFocus(w);
      SetCapture(w);
      _modifiers(p, wp);
      p->pressed(b, GET_X_LPARAM(lp), GET_Y_LPARAM(lp),
                 GetDoubleClickTime() / 1000.);
      return 0;
    }
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP: {
      int b = (msg == WM_RBUTTONUP) ? 1 : (msg == WM_MBUTTONUP) ? 2 : 0;
      _modifiers(p, wp);
      if(!(wp & (MK_LBUTTON | MK_RBUTTON | MK_MBUTTON))) ReleaseCapture();
      p->released(b, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
      return 0;
    }
    case WM_MOUSEWHEEL: {
      _modifiers(p, GET_KEYSTATE_WPARAM(wp));
      POINT at = {GET_X_LPARAM(lp), GET_Y_LPARAM(lp)};
      ScreenToClient(w, &at);
      p->wheel(GET_WHEEL_DELTA_WPARAM(wp) / (double)WHEEL_DELTA, at.x, at.y);
      return 0;
    }
    case WM_SYSKEYDOWN:
    case WM_KEYDOWN:
      // Alt and the arrows step through what is stacked under the pointer;
      // the other keys are the loop's
      if(GetKeyState(VK_MENU) < 0 && (wp == VK_UP || wp == VK_DOWN) &&
         CTX::instance()->mouseSelection && !p->view->lasso() &&
         !p->view->addPointMode) {
        if(_prepare(p)) p->view->stepPick(wp == VK_DOWN ? 1 : -1);
        return 0;
      }
      break;
    case WM_SETCURSOR:
      if(LOWORD(lp) == HTCLIENT) {
        SetCursor((HCURSOR)GetPropW(w, L"gmshCursor") ?
                    (HCURSOR)GetPropW(w, L"gmshCursor") :
                    LoadCursor(nullptr, IDC_ARROW));
        return TRUE;
      }
      break;
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

  const wchar_t *_paneClass()
  {
    static bool registered = false;
    if(!registered) {
      registered = true;
      WNDCLASSEXW wc;
      memset(&wc, 0, sizeof(wc));
      wc.cbSize = sizeof(wc);
      // a device context of its own, which the OpenGL context is bound to
      wc.style = CS_OWNDC | CS_DBLCLKS;
      wc.lpfnWndProc = _paneProc;
      wc.hInstance = GetModuleHandleW(nullptr);
      wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
      wc.lpszClassName = L"GmshScene";
      RegisterClassExW(&wc);
    }
    return L"GmshScene";
  }

  bool _makeContext(pane *p)
  {
    p->dc = GetDC(p->hwnd);
    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cAlphaBits = 8;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int format = ChoosePixelFormat(p->dc, &pfd);
    if(!format || !SetPixelFormat(p->dc, format, &pfd)) {
      Msg::Warning("Could not set a pixel format for OpenGL");
      return false;
    }
    // the driver's own: a compatibility profile of the latest version it
    // has, which serves the shaders and the fixed function pipeline alike
    p->gl = wglCreateContext(p->dc);
    if(!p->gl) {
      Msg::Warning("Could not create an OpenGL context");
      return false;
    }
    if(_shared)
      wglShareLists(_shared, p->gl);
    else
      _shared = p->gl;
    wglMakeCurrent(p->dc, p->gl);
    glShader::setContext(p->gl);
    p->view->contextChanged();
    return true;
  }

  // the window of a pane is made in the box; one of its own is moved into
  // its window afterwards
  pane *_newPane()
  {
    pane *p = new pane;
    p->hwnd = CreateWindowExW(0, _paneClass(), L"",
                              WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                                WS_CLIPCHILDREN,
                              0, 0, 100, 100, _box, nullptr,
                              GetModuleHandleW(nullptr), nullptr);
    SetPropW(p->hwnd, L"gmshPane", (HANDLE)p);
    _makeContext(p);
    return p;
  }

  void _destroy(pane *p)
  {
    if(p->gl) {
      wglMakeCurrent(nullptr, nullptr);
      if(p->gl != _shared) wglDeleteContext(p->gl);
    }
    RemovePropW(p->hwnd, L"gmshPane");
    DestroyWindow(p->hwnd);
    if(p->top) {
      RemovePropW(p->top, L"gmshHeld");
      DestroyWindow(p->top);
    }
    delete p;
  }

  // the room of the box shared between the panes, a gap between two
  void _layout(node *n, int x, int y, int w, int h)
  {
    if(!n) return;
    if(n->leaf) {
      MoveWindow(n->leaf->hwnd, x, y, std::max(1, w), std::max(1, h), TRUE);
      return;
    }
    const int gap = 4;
    double f = std::max(.05, std::min(.95, n->ratio));
    if(n->split == 'h') {
      int w1 = (int)(w * f);
      _layout(n->child[0], x, y, w1 - gap / 2, h);
      _layout(n->child[1], x + w1 + gap / 2, y, w - w1 - gap / 2, h);
    }
    else {
      int h1 = (int)(h * f);
      _layout(n->child[0], x, y, w, h1 - gap / 2);
      _layout(n->child[1], x, y + h1 + gap / 2, w, h - h1 - gap / 2);
    }
  }

  node *_nodeOf(node *n, pane *p)
  {
    if(!n) return nullptr;
    if(n->leaf == p) return n;
    if(node *c = _nodeOf(n->child[0], p)) return c;
    return _nodeOf(n->child[1], p);
  }

  void _deleteNodes(node *n)
  {
    if(!n) return;
    _deleteNodes(n->child[0]);
    _deleteNodes(n->child[1]);
    delete n;
  }

  void _relayout()
  {
    if(!_box) return;
    RECT r;
    GetClientRect(_box, &r);
    _layout(_root, 0, 0, r.right, r.bottom);
  }

  LRESULT CALLBACK _boxProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    switch(msg) {
    case WM_SIZE: _relayout(); return 0;
    case WM_ERASEBKGND: {
      RECT r;
      GetClientRect(w, &r);
      FillRect((HDC)wp, &r, GetSysColorBrush(COLOR_BTNSHADOW));
      return 1;
    }
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

  LRESULT CALLBACK _windowProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    pane *p = (pane *)GetPropW(w, L"gmshHeld");
    switch(msg) {
    case WM_SIZE:
      if(p) {
        RECT r;
        GetClientRect(w, &r);
        MoveWindow(p->hwnd, 0, 0, r.right, r.bottom, TRUE);
      }
      return 0;
    case WM_CLOSE:
      // its view goes with it
      if(p) {
        RemovePropW(w, L"gmshHeld");
        p->top = nullptr;
        _all().dropped(p);
        _destroy(p);
      }
      DestroyWindow(w);
      return 0;
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

  GuiPanes::Toolkit _toolkit()
  {
    GuiPanes::Toolkit t;
    t.makePane = [](GuiPanes::Pane *) -> GuiPanes::Pane * { return _newPane(); };
    t.redraw = [](GuiPanes::Pane *p) {
      InvalidateRect(_pane(p)->hwnd, nullptr, FALSE);
    };
    t.prepare = [](GuiPanes::Pane *p) { return _prepare(_pane(p)); };
    t.size = [](GuiPanes::Pane *p, int &w, int &h, double &f) {
      RECT r;
      GetClientRect(_pane(p)->hwnd, &r);
      w = r.right;
      h = r.bottom;
      f = 1.;
    };
    t.origin = [](GuiPanes::Pane *p, int &x, int &y) {
      POINT o = {0, 0};
      HWND w = _pane(p)->hwnd;
      MapWindowPoints(w, GetAncestor(w, GA_ROOT), &o, 1);
      x = o.x;
      y = o.y;
    };
    t.drawNow = [](GuiPanes::Pane *p) {
      // into the back buffer, which glReadPixels() reads
      if(!_prepare(_pane(p))) return;
      _all().draw(p);
      glFlush();
    };
    t.split = [](GuiPanes::Pane *was, GuiPanes::Pane *fresh, char how,
                 double ratio) {
      node *n = _nodeOf(_root, _pane(was));
      if(!n) return;
      n->child[0] = new node;
      n->child[0]->leaf = n->leaf;
      n->child[1] = new node;
      n->child[1]->leaf = _pane(fresh);
      n->leaf = nullptr;
      n->split = how;
      n->ratio = ratio;
      _relayout();
    };
    t.unsplit = [](GuiPanes::Pane *keep,
                   const std::vector<GuiPanes::Pane *> &gone) {
      for(GuiPanes::Pane *p : gone) _destroy(_pane(p));
      _deleteNodes(_root);
      _root = new node;
      _root->leaf = _pane(keep);
      _relayout();
    };
    t.newWindow = [](GuiPanes::Pane *fresh) {
      WNDCLASSEXW wc;
      memset(&wc, 0, sizeof(wc));
      wc.cbSize = sizeof(wc);
      wc.lpfnWndProc = _windowProc;
      wc.hInstance = GetModuleHandleW(nullptr);
      wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
      wc.hIcon = LoadIconW(GetModuleHandleW(nullptr), MAKEINTRESOURCEW(1));
      wc.lpszClassName = L"GmshSceneWindow";
      RegisterClassExW(&wc);
      wchar_t title[64];
      swprintf(title, 64, L"Gmsh - Graphic window %d",
               (int)_all().panes().size());
      HWND w = CreateWindowExW(0, L"GmshSceneWindow", title,
                               WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
                               CW_USEDEFAULT, CW_USEDEFAULT, 600, 500,
                               win32MainWindow(), nullptr,
                               GetModuleHandleW(nullptr), nullptr);
      pane *p = _pane(fresh);
      p->top = w;
      SetParent(p->hwnd, w);
      SetPropW(w, L"gmshHeld", (HANDLE)p);
      RECT r;
      GetClientRect(w, &r);
      MoveWindow(p->hwnd, 0, 0, r.right, r.bottom, TRUE);
      ShowWindow(w, SW_SHOW);
    };
    t.cursor = [](bool picking) {
      HCURSOR c = picking ? LoadCursor(nullptr, IDC_HAND) : nullptr;
      for(GuiPanes::Pane *p : _all().panes())
        SetPropW(_pane(p)->hwnd, L"gmshCursor", (HANDLE)c);
      POINT at;
      GetCursorPos(&at);
      if(_paneOf(WindowFromPoint(at)))
        SetCursor(c ? c : LoadCursor(nullptr, IDC_ARROW));
    };
    t.clipboard = [](int w, int h, const std::vector<unsigned char> &rgba) {
      // a bitmap of Windows: bottom up, as the rows come, blue green red,
      // each row a multiple of 4 bytes
      int stride = (w * 3 + 3) & ~3;
      HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, sizeof(BITMAPINFOHEADER) +
                                                 (SIZE_T)stride * h);
      if(!mem) return;
      BITMAPINFOHEADER *bi = (BITMAPINFOHEADER *)GlobalLock(mem);
      memset(bi, 0, sizeof(*bi));
      bi->biSize = sizeof(*bi);
      bi->biWidth = w;
      bi->biHeight = h;
      bi->biPlanes = 1;
      bi->biBitCount = 24;
      bi->biCompression = BI_RGB;
      unsigned char *bits = (unsigned char *)(bi + 1);
      for(int y = 0; y < h; y++)
        for(int x = 0; x < w; x++) {
          const unsigned char *s = &rgba[((std::size_t)y * w + x) * 4];
          unsigned char *d = bits + (std::size_t)y * stride + 3 * x;
          d[0] = s[2];
          d[1] = s[1];
          d[2] = s[0];
        }
      GlobalUnlock(mem);
      if(OpenClipboard(win32MainWindow())) {
        EmptyClipboard();
        SetClipboardData(CF_DIB, mem);
        CloseClipboard();
      }
      else
        GlobalFree(mem);
    };
    t.later = Scene::later;
    t.buttonDown = []() { return win32ButtonDown(); };
    t.context = []() -> void * { return (void *)wglGetCurrentContext(); };
    t.screen = [](int &height, float &scale) {
      height = GetSystemMetrics(SM_CYSCREEN);
      scale = 1.f;
    };
    return t;
  }

  struct offering {
    offering() { GuiPanes::offer("win32"); }
  };
  offering _offering;

} // namespace

HWND win32SceneWindow(HWND parent)
{
  if(_box) return _box;
  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);
  WNDCLASSEXW wc;
  memset(&wc, 0, sizeof(wc));
  wc.cbSize = sizeof(wc);
  wc.lpfnWndProc = _boxProc;
  wc.hInstance = GetModuleHandleW(nullptr);
  wc.lpszClassName = L"GmshSceneBox";
  RegisterClassExW(&wc);
  _box = CreateWindowExW(0, L"GmshSceneBox", L"",
                         WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, 0, 0, 100, 100,
                         parent, nullptr, GetModuleHandleW(nullptr), nullptr);
  _root = new node;
  _root->leaf = _pane(_all().start(_toolkit()));
  _relayout();
  return _box;
}

void win32SceneRedraw() { _all().redrawAll(); }

bool win32SceneDrawing() { return _all().drawing(); }

void win32SceneSize(int &width, int &height)
{
  width = height = 0;
  if(!_box) return;
  RECT r;
  GetClientRect(_box, &r);
  width = r.right;
  height = r.bottom;
}

void win32SceneSplit(char how, double ratio) { _all().split(how, ratio); }

void win32SceneNewWindow() { _all().newWindow(); }

void win32SceneCopy() { Gui::instance().copyCurrentOpenglWindowToClipboard(); }

void win32SceneDestroy()
{
  std::vector<GuiPanes::Pane *> panes = _all().panes();
  _all().stop();
  for(GuiPanes::Pane *p : panes) _destroy(_pane(p));
  if(_shared) {
    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(_shared);
  }
  _shared = nullptr;
  _deleteNodes(_root);
  _root = nullptr;
  _box = nullptr;
}

// the timers of the scene, the animation and the gamepad among them
void win32ScenePump() { Scene::fireTimers(); }

double win32SceneNextTimer() { return Scene::nextTimer(); }
