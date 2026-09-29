// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Win32 interface, see GuiScene.h: each view a child window
// with an OpenGL context of its own (WGL), sharing what can be shared with the
// others; the views of the main window split as the Dear ImGui interface
// splits its panes, a new graphic window a window holding one more

#include "GmshConfig.h"

#include <algorithm>
#include <cstring>

#include "win32Common.h"
#include <windowsx.h>

#include "glApi.h"
#include "Gui.h"
#include "GuiScene.h"
#include "GuiActions.h"
#include "sceneView.h"
#include "sceneHost.h"
#include "sceneGamepad.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"
#include "PixelBuffer.h"
#include "OS.h"

namespace {

  struct pane {
    HWND hwnd = nullptr;
    HDC dc = nullptr;
    HGLRC gl = nullptr;
    sceneView *view = nullptr;
    // a graphic window of its own, not tiled in the main one
    HWND window = nullptr;
    paneInput input;
    double lastX = 0., lastY = 0., lastPress = 0.;
    bool moved = false, tracking = false;
  };

  // how the tiled panes share the room, as the Dear ImGui interface has it
  struct node {
    pane *leaf = nullptr;
    char split = 0; // 'h' side by side, 'v' one above the other
    double ratio = .5;
    node *child[2] = {nullptr, nullptr};
  };

  std::vector<pane *> _panes;
  pane *_current = nullptr;
  node *_root = nullptr;
  HWND _box = nullptr;
  HGLRC _shared = nullptr;
  int _captureW = 0, _captureH = 0;
  bool _animating = false, _drawing = false;
  double _lastAnimation = 0., _lastPad = 0.;

  std::vector<GVertex *> _vertices;
  std::vector<GEdge *> _edges;
  std::vector<GFace *> _faces;
  std::vector<GRegion *> _regions;
  std::vector<MElement *> _elements;
  std::vector<SPoint2> _points;
  std::vector<PView *> _views;

  void _clearSelected()
  {
    _vertices.clear();
    _edges.clear();
    _faces.clear();
    _regions.clear();
    _elements.clear();
    _points.clear();
    _views.clear();
  }

  pane *_paneOf(HWND w)
  {
    return w ? (pane *)GetPropW(w, L"gmshPane") : nullptr;
  }

  pane *_paneOf(sceneView *view)
  {
    for(pane *p : _panes)
      if(p->view == view) return p;
    return nullptr;
  }

  bool _prepare(pane *p)
  {
    if(!p || !p->gl) return false;
    if(!wglMakeCurrent(p->dc, p->gl)) return false;
    glShader::setWindowFramebuffer(0);
    return true;
  }

  void _size(pane *p, int &w, int &h)
  {
    RECT r;
    GetClientRect(p->hwnd, &r);
    w = r.right;
    h = r.bottom;
  }

  void _place(pane *p)
  {
    int w = 0, h = 0;
    _size(p, w, h);
    p->view->setRect(0, 0, w, h);
    p->view->setOrigin(0., 0., h, 1.);
  }

  void _draw(pane *p)
  {
    int w = 0, h = 0;
    _size(p, w, h);
    if(w < 1 || h < 1) return;
    if(_captureW > 0 && _captureH > 0) {
      // in the bottom-left corner, where PixelBuffer::fill() reads
      glDisable(GL_SCISSOR_TEST);
      glViewport(0, 0, w, h);
      glClearColor(0.f, 0.f, 0.f, 1.f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      p->view->setRect(0, h - _captureH, _captureW, _captureH);
      p->view->setOrigin(0., 0., h, 1.);
      p->view->draw(1., h);
      _place(p);
    }
    else {
      _place(p);
      p->view->draw(1., h);
    }
    glShader::release();
  }

  void _handle(pane *p)
  {
    if(!_prepare(p)) return;
    _place(p);
    p->view->handleMouse(p->input);
    for(int b = 0; b < 3; b++) p->input.clicked[b] = p->input.released[b] = false;
    p->input.doubleClicked = false;
    p->input.wheel = 0.;
    p->input.dx = p->input.dy = 0.;
    // the view asks for the draws it needs: one it did not ask for would
    // start the studio frames over
  }

  void _modifiers(pane *p, WPARAM wp)
  {
    p->input.shift = (wp & MK_SHIFT) != 0;
    p->input.ctrl = (wp & MK_CONTROL) != 0;
    p->input.alt = GetKeyState(VK_MENU) < 0;
    p->input.super = GetKeyState(VK_LWIN) < 0 || GetKeyState(VK_RWIN) < 0;
  }

  void _at(pane *p, int x, int y)
  {
    p->input.dx = p->moved ? x - p->lastX : 0.;
    p->input.dy = p->moved ? y - p->lastY : 0.;
    p->lastX = p->input.x = x;
    p->lastY = p->input.y = y;
    p->moved = true;
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
        _drawing = true;
        _draw(p);
        _drawing = false;
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
      _current = p;
      _modifiers(p, wp);
      _at(p, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
      _handle(p);
      return 0;
    case WM_MOUSELEAVE:
      p->tracking = false;
      p->moved = false;
      p->view->pointerLeft();
      return 0;
    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_LBUTTONDBLCLK: {
      int b = (msg == WM_RBUTTONDOWN) ? 1 : (msg == WM_MBUTTONDOWN) ? 2 : 0;
      SetFocus(w);
      SetCapture(w);
      _current = p;
      _modifiers(p, wp);
      _at(p, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
      p->input.clicked[b] = p->input.dragging[b] = true;
      double now = TimeOfDay();
      p->input.doubleClicked =
        b == 0 && now - p->lastPress < GetDoubleClickTime() / 1000.;
      if(b == 0) p->lastPress = p->input.doubleClicked ? 0. : now;
      _handle(p);
      return 0;
    }
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP: {
      int b = (msg == WM_RBUTTONUP) ? 1 : (msg == WM_MBUTTONUP) ? 2 : 0;
      _modifiers(p, wp);
      _at(p, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
      p->input.released[b] = true;
      p->input.dragging[b] = false;
      if(!(wp & (MK_LBUTTON | MK_RBUTTON | MK_MBUTTON))) ReleaseCapture();
      _handle(p);
      return 0;
    }
    case WM_MOUSEWHEEL: {
      _modifiers(p, GET_KEYSTATE_WPARAM(wp));
      POINT at = {GET_X_LPARAM(lp), GET_Y_LPARAM(lp)};
      ScreenToClient(w, &at);
      _at(p, at.x, at.y);
      p->input.wheel = GET_WHEEL_DELTA_WPARAM(wp) / (double)WHEEL_DELTA;
      _handle(p);
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

  pane *_newPane(HWND parent, pane *from)
  {
    pane *p = new pane;
    p->view = new sceneView();
    if(from)
      p->view->getDrawContext()->copyViewAttributes(from->view->getDrawContext());
    p->hwnd = CreateWindowExW(0, _paneClass(), L"",
                              WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                                WS_CLIPCHILDREN,
                              0, 0, 100, 100, parent, nullptr,
                              GetModuleHandleW(nullptr), nullptr);
    SetPropW(p->hwnd, L"gmshPane", (HANDLE)p);
    _makeContext(p);
    _panes.push_back(p);
    return p;
  }

  void _dropPane(pane *p)
  {
    auto it = std::find(_panes.begin(), _panes.end(), p);
    if(it != _panes.end()) _panes.erase(it);
    if(_current == p) _current = _panes.empty() ? nullptr : _panes[0];
    if(p->gl) {
      wglMakeCurrent(nullptr, nullptr);
      if(p->gl != _shared) wglDeleteContext(p->gl);
    }
    RemovePropW(p->hwnd, L"gmshPane");
    DestroyWindow(p->hwnd);
    delete p->view;
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

  void _redrawAll()
  {
    for(pane *p : _panes) InvalidateRect(p->hwnd, nullptr, FALSE);
  }

  void _setHost()
  {
    Scene::Host held;
    held.redraw = []() { _redrawAll(); };
    held.redrawView = [](sceneView *view) {
      if(pane *p = _paneOf(view)) InvalidateRect(p->hwnd, nullptr, FALSE);
    };
    held.check = [](bool rateLimited) { Gui::instance().check(rateLimited); };
    held.wait = [](double seconds, bool force) {
      if(seconds < 0.)
        Gui::instance().wait(force);
      else
        Gui::instance().wait(seconds, force);
    };
    held.drawCurrent = []() {
      // into the back buffer, which glReadPixels() reads
      if(_prepare(_current)) {
        _draw(_current);
        glFlush();
      }
    };
    held.uiScale = []() { return 1.f; };
    held.numViews = []() { return (int)_panes.size(); };
    held.cursor = [](Scene::Cursor kind) {
      HCURSOR c = kind == Scene::Picking ? LoadCursor(nullptr, IDC_HAND) : nullptr;
      for(pane *p : _panes) SetPropW(p->hwnd, L"gmshCursor", (HANDLE)c);
      POINT at;
      GetCursorPos(&at);
      HWND under = WindowFromPoint(at);
      if(_paneOf(under)) SetCursor(c ? c : LoadCursor(nullptr, IDC_ARROW));
    };
    held.current = []() -> sceneView * {
      return _current ? _current->view : nullptr;
    };
    held.setCurrent = [](sceneView *view) {
      if(pane *p = _paneOf(view)) _current = p;
    };
    held.later = Scene::later;
    held.buttonDown = []() { return win32ButtonDown(); };
    held.context = []() -> void * { return (void *)wglGetCurrentContext(); };
    held.makeCurrent = [](sceneView *view) { _prepare(_paneOf(view)); };
    held.screen = [](int &height, float &scale) {
      height = GetSystemMetrics(SM_CYSCREEN);
      scale = 1.f;
    };
    Scene::setHost(held);
  }

} // namespace

HWND win32SceneWindow(HWND parent)
{
  if(_box) return _box;
  _setHost();
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
  _current = _newPane(_box, nullptr);
  _root = new node;
  _root->leaf = _current;
  _relayout();
  return _box;
}

void win32SceneRedraw() { _redrawAll(); }

bool win32SceneDrawing() { return _drawing; }

void win32SceneSize(int &width, int &height)
{
  width = height = 0;
  if(!_box) return;
  RECT r;
  GetClientRect(_box, &r);
  width = r.right;
  height = r.bottom;
}

void win32SceneSplit(char how, double ratio)
{
  if(!_current || !_root) return;
  if(how == 'u') {
    pane *keep = (_current && !_current->window) ? _current : nullptr;
    for(pane *p : _panes)
      if(!keep && !p->window) keep = p;
    if(!keep) return;
    std::vector<pane *> gone;
    for(pane *p : _panes)
      if(p != keep && !p->window) gone.push_back(p);
    for(pane *p : gone) _dropPane(p);
    _deleteNodes(_root);
    _root = new node;
    _root->leaf = keep;
    _current = keep;
    _relayout();
    _redrawAll();
    return;
  }
  if(how != 'h' && how != 'v') {
    Msg::Error("Unknown window splitting method '%c'", how);
    return;
  }
  node *n = _nodeOf(_root, _current);
  if(!n) {
    Msg::Error("Only the graphic windows of the main window can be split");
    return;
  }
  pane *fresh = _newPane(_box, _current);
  n->child[0] = new node;
  n->child[0]->leaf = n->leaf;
  n->child[1] = new node;
  n->child[1]->leaf = fresh;
  n->leaf = nullptr;
  n->split = how;
  n->ratio = (ratio <= 0. || ratio >= 1.) ? .5 : ratio;
  _current = fresh;
  _relayout();
  _redrawAll();
}

namespace {
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
        p->window = nullptr;
        _dropPane(p);
      }
      DestroyWindow(w);
      return 0;
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }
} // namespace

void win32SceneNewWindow()
{
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
  swprintf(title, 64, L"Gmsh - Graphic window %d", (int)_panes.size() + 1);
  HWND w = CreateWindowExW(0, L"GmshSceneWindow", title,
                           WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN, CW_USEDEFAULT,
                           CW_USEDEFAULT, 600, 500, win32MainWindow(), nullptr,
                           GetModuleHandleW(nullptr), nullptr);
  pane *fresh = _newPane(w, _current);
  fresh->window = w;
  SetPropW(w, L"gmshHeld", (HANDLE)fresh);
  RECT r;
  GetClientRect(w, &r);
  MoveWindow(fresh->hwnd, 0, 0, r.right, r.bottom, TRUE);
  _current = fresh;
  ShowWindow(w, SW_SHOW);
}

void win32SceneDestroy()
{
  while(!_panes.empty()) {
    pane *p = _panes.back();
    if(p->window) {
      RemovePropW(p->window, L"gmshHeld");
      DestroyWindow(p->window);
    }
    _dropPane(p);
  }
  if(_shared) {
    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(_shared);
  }
  _shared = nullptr;
  _deleteNodes(_root);
  _root = nullptr;
  _current = nullptr;
  _box = nullptr;
}

void win32ScenePump()
{
  Scene::fireTimers();
  double now = TimeOfDay();
  if(_animating && now - _lastAnimation > .01) {
    _lastAnimation = now;
    animationTick();
  }
  double pad = Scene::gamepadPeriod();
  if(pad > 0. && now - _lastPad > pad && _current) {
    _lastPad = now;
    if(Scene::gamepadTurn(_current->view)) InvalidateRect(_current->hwnd, nullptr, FALSE);
  }
}

double win32SceneNextTimer()
{
  double next = Scene::nextTimer();
  auto sooner = [&next](double t) {
    if(t >= 0. && (next < 0. || t < next)) next = t;
  };
  if(_animating) sooner(.01);
  double pad = Scene::gamepadPeriod();
  if(pad > 0.) sooner(pad);
  return next;
}

namespace Win32Scene {

  void pumpScene(bool rateLimited) {}
  void sceneShownElsewhere() {}
  std::string scenePicture(int &width, int &height, bool always) { return ""; }
  bool sceneMoved() { return false; }
  void sceneResize(int width, int height) {}
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
  }

  bool sceneKey(char key)
  {
    bool taken = false;
    for(pane *p : _panes)
      if(p->view->key(key)) {
        taken = true;
        InvalidateRect(p->hwnd, nullptr, FALSE);
      }
    return taken;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    if(!_current) return;
    _current->view->screenMessage[0] = first;
    _current->view->screenMessage[1] = second;
    InvalidateRect(_current->hwnd, nullptr, FALSE);
  }

  drawContext *getCurrentDrawContext()
  {
    return _current ? _current->view->getDrawContext() : nullptr;
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    if(_current) _size(_current, width, height);
  }

  void setCurrentOpenglWindow(int which)
  {
    if(which >= 0 && which < (int)_panes.size()) _current = _panes[which];
  }

  void showAllInEveryWindow()
  {
    for(pane *p : _panes)
      if(drawContext *ctx = p->view->getDrawContext()) ctx->showAll();
    _redrawAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  {
    win32SceneSplit(how, ratio);
  }

  void copyCurrentOpenglWindowToClipboard()
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(w < 1 || h < 1 || !_prepare(_current)) return;
    _draw(_current);
    // a bitmap of Windows, bottom up as glReadPixels() gives it
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
    glFinish();
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    glReadPixels(0, 0, w, h, 0x80E0 /* GL_BGR */, GL_UNSIGNED_BYTE, bits);
    GlobalUnlock(mem);
    if(OpenClipboard(win32MainWindow())) {
      EmptyClipboard();
      SetClipboardData(CF_DIB, mem);
      CloseClipboard();
    }
    else
      GlobalFree(mem);
    InvalidateRect(_current->hwnd, nullptr, FALSE);
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(width > w || height > h) {
      Msg::Warning("The Win32 interface cannot render a picture larger than "
                   "the graphic window (%d x %d): clamping", w, h);
      width = std::min(width, w);
      height = std::min(height, h);
    }
    if(width < 1) width = 1;
    if(height < 1) height = 1;
    _captureW = width;
    _captureH = height;
  }

  void endGraphicCapture()
  {
    _captureW = _captureH = 0;
    _redrawAll();
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    int width = 0, height = 0;
    getCurrentPixelSize(width, height);
    if(width < 1 || height < 1) return nullptr;
    CTX *c = CTX::instance();
    if(c->print.width > 0 || c->print.height > 0) {
      if(c->print.width <= 0) {
        width = (int)(width * c->print.height / (double)height);
        height = c->print.height;
      }
      else if(c->print.height <= 0) {
        height = (int)(height * c->print.width / (double)width);
        width = c->print.width;
      }
      else {
        width = c->print.width;
        height = c->print.height;
      }
    }
    beginGraphicCapture(width, height, c->print.compositeWindows ? true : false);
    PixelBuffer *buffer =
      new PixelBuffer(width, height, (GLenum)format, (GLenum)type);
    buffer->fill();
    endGraphicCapture();
    return buffer;
  }

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    std::vector<sceneView *> views;
    for(pane *p : _panes)
      if(!p->window) views.push_back(p->view);
    if(views.empty() && _current) views.push_back(_current->view);
    Scene::orientViews(views, what, reverse, sync);
    _redrawAll();
  }

  void setMouseSelection(bool on) {}
  void toggleAnimation() { _animating = !_animating; }
  bool animating() { return _animating; }

  void abortSelection()
  {
    if(!_current) return;
    _current->view->quitSelection = 1;
    _current->view->selectionMode = false;
  }

  void setAddPointMode(bool on)
  {
    for(pane *p : _panes) p->view->addPointMode = on;
  }

  void sceneSettingChanged(const std::string &what)
  {
    if(what == "background_image")
      for(pane *p : _panes)
        if(p->view->getDrawContext())
          p->view->getDrawContext()->invalidateBgImageTexture();
    _redrawAll();
  }

  char selectEntity(int type)
  {
    _clearSelected();
    if(!_current) return 'q';
    return _current->view->selectEntity(type, _vertices, _edges, _faces,
                                        _regions, _elements, _points, _views);
  }

  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h)
  {
    _clearSelected();
    if(!_prepare(_current)) return false;
    _place(_current);
    return _current->view->pick(type, mesh, post, x, y, w, h, _vertices,
                                _edges, _faces, _regions, _elements, _points,
                                _views);
  }

  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    if(!_prepare(_current)) return false;
    bool ok = _current->view->printTo(width, height, supersampling, format,
                                      type, pixels);
    InvalidateRect(_current->hwnd, nullptr, FALSE);
    return ok;
  }

  const std::vector<GVertex *> &selectedVertices() { return _vertices; }
  const std::vector<GEdge *> &selectedEdges() { return _edges; }
  const std::vector<GFace *> &selectedFaces() { return _faces; }
  const std::vector<GRegion *> &selectedRegions() { return _regions; }
  const std::vector<MElement *> &selectedElements() { return _elements; }
  const std::vector<SPoint2> &selectedPoints() { return _points; }
  const std::vector<PView *> &selectedViews() { return _views; }

  // filled from the list in GuiSceneOps.h
  namespace {
    struct offering {
      offering()
      {
        GuiSceneOps ops;
#define GUI_SCENE_TAKE(name, args, call) ops.name = name;
        GUI_SCENE_VOID(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(ret, name, args, call, none) ops.name = name;
        GUI_SCENE_VALUE(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(type, name) ops.name = name;
        GUI_SCENE_LIST(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
        Gui::offerScene("win32", ops);
      }
    };
    offering _offering;
  } // namespace

} // namespace Win32Scene

void win32SceneCopy() { Win32Scene::copyCurrentOpenglWindowToClipboard(); }
