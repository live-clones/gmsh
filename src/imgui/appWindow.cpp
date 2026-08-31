// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <GLFW/glfw3.h>

#include "appWindow.h"
#include "toolkit.h"
#include "scenePane.h"
#include "messageConsole.h"
#include "fileBrowser.h"
#include "drawContextImGui.h"
#include "Gui.h"
#include "GuiStatus.h"
#include "GmshGlobal.h"
#include "Context.h"
#include "StringUtils.h"
#include "Options.h"
#include "OpenFile.h"
#include "OS.h"
#include "GModel.h"
#include "drawContext.h"

appWindow *appWindow::_instance = nullptr;
std::string appWindow::_openedThroughMacFinder = "";
bool appWindow::_finishedProcessingCommandLine = false;
std::atomic<int> appWindow::_locked(0);

// While we are probing the windowing systems, a backend failing to initialize
// is expected and must not be reported as an error: Toolkit::report(Toolkit::Error, ) records the
// last error, which makes the public API throw. Only a failure once a backend
// has been chosen is a real error.
static bool _glfwProbing = false;

// why the last backend we probed refused to start, kept to explain an
// unexpected fallback once the choice is made
static std::string _glfwProbeError;

static void _glfwErrorCallback(int error, const char *description)
{
  if(_glfwProbing) {
    Toolkit::report(Toolkit::Debug, "GLFW: %s (error %d)", description, error);
    _glfwProbeError = description;
  }
  else
    Toolkit::report(Toolkit::Error, "GLFW error %d: %s", error, description);
}

static void _glfwDropCallback(GLFWwindow *window, int count, const char **paths)
{
  for(int i = 0; i < count; i++) {
    if(i == 0)
      OpenProject(paths[i]);
    else
      MergeFile(paths[i]);
  }
  drawContext::global()->draw();
}

// Initialize GLFW, picking the windowing system to talk to. On Linux, GLFW is
// built with both the native Wayland backend and the X11 one and normally
// selects Wayland when a Wayland display is available. That choice can be
// forced with the GMSH_GUI_PLATFORM environment variable ("wayland", "x11" or
// "any"), and we fall back to the other backend when the preferred one cannot
// be initialized, which typically happens when the client libraries of the
// running session are not installed.
static bool _initGlfw()
{
  struct { const char *name; int id; } platforms[3];
  int num = 0;

  const char *want = getenv("GMSH_GUI_PLATFORM");
  if(want && !strcmp(want, "wayland")) {
#if defined(GLFW_PLATFORM_WAYLAND)
    platforms[num++] = {"Wayland", GLFW_PLATFORM_WAYLAND};
#endif
  }
  else if(want && !strcmp(want, "x11")) {
#if defined(GLFW_PLATFORM_X11)
    platforms[num++] = {"X11", GLFW_PLATFORM_X11};
#endif
  }
  else if(want && strcmp(want, "any")) {
    Toolkit::report(Toolkit::Warning, "Unknown GMSH_GUI_PLATFORM '%s': expected 'wayland', 'x11' or "
                 "'any'", want);
  }

  // let GLFW choose first, then try the backends one by one
  platforms[num++] = {"default", GLFW_ANY_PLATFORM};
#if defined(GLFW_PLATFORM_X11)
  if(!want || !strcmp(want, "any")) platforms[num++] = {"X11", GLFW_PLATFORM_X11};
#endif

  _glfwProbing = true;
  for(int i = 0; i < num; i++) {
    glfwInitHint(GLFW_PLATFORM, platforms[i].id);
    if(glfwInit()) {
      _glfwProbing = false;
      if(i > 0)
        Toolkit::report(Toolkit::Info, "Using the %s backend for the graphical interface",
                  platforms[i].name);
      return true;
    }
    if(i + 1 < num)
      Toolkit::report(Toolkit::Info, "Could not initialize the %s backend, trying %s",
                platforms[i].name, platforms[i + 1].name);
  }
  _glfwProbing = false;

  Toolkit::report(Toolkit::Error, "Could not initialize GLFW: no graphical interface available");
  return false;
}

appWindow::appWindow(int argc, char **argv, bool quitShouldExit)
  : _window(nullptr), _quitShouldExit(quitShouldExit), _inFrame(false),
    _lastRefresh(0.), _currentPane(nullptr), _console(nullptr),
    _showConsole(true),
    _showModules(true),
    _paneRoot(nullptr), _uiScale(0.f),
    _uiScaleOverride(0.f), _styleScale(0.f), _reportedDetachable(false),
    _animating(false), _animLastStep(0.), _zoomed(false), _fullscreen(false), _savedX(0), _savedY(0), _savedW(0), _savedH(0), _captureW(0), _captureH(0), _captureComposite(false), _modalDepth(0),
    _browser(nullptr), _exportActive(false), _exportDone(false),
    _exportAccepted(false), _exportFormat(-1)
{
  for(int i = 0; i < Dialog::NumDialogs; i++) {
    _showDialog[i] = _focusDialog[i] = false;
    _sizedDialog[i] = false;
    _estimatedHeight[i] = 0.f;
    _wantedPane[i] = -1;
    _lastPane[i] = -1;
  }
  glfwSetErrorCallback(_glfwErrorCallback);
  if(!_initGlfw()) return;

  // a plain, compatibility-profile context: Gmsh renders with the OpenGL 1.x
  // fixed pipeline and GLU, and so does the imgui_impl_opengl2 backend
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
  glfwWindowHint(GLFW_DEPTH_BITS, 24);
  if(CTX::instance()->antialiasing) glfwWindowHint(GLFW_SAMPLES, 4);

  // Identify the window to the desktop. Left alone, GLFW leaves the Wayland app
  // id empty and derives the X11 WM_CLASS from the window title, which follows
  // the project file. The desktop then cannot tell which application the window
  // belongs to, and window rules key on exactly that: a tiling extension
  // typically drops a window it cannot resolve to an application.
  //
  // The resolution goes through the installed desktop entry
  // (utils/freedesktop/info.gmsh.gmsh.desktop). On Wayland the app id must be
  // its base name; on X11 the class name is compared with its StartupWMClass.
  glfwWindowHintString(GLFW_WAYLAND_APP_ID, "info.gmsh.gmsh");
  glfwWindowHintString(GLFW_X11_CLASS_NAME, "Gmsh");
  glfwWindowHintString(GLFW_X11_INSTANCE_NAME, "gmsh");

  int w = CTX::instance()->glSize[0] + CTX::instance()->menuSize[0];
  int h = CTX::instance()->glSize[1] + CTX::instance()->msgSize;
  if(w < 640) w = 1024;
  if(h < 480) h = 768;

  _window = glfwCreateWindow(w, h, "Gmsh", nullptr, nullptr);
  if(!_window) {
    Toolkit::report(Toolkit::Error, "Could not create a window: no graphical interface available");
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(_window);
  glfwSwapInterval(1);

  glfwSetDropCallback(_window, _glfwDropCallback);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  // Let a panel dragged out of the main window become a window of its own, the
  // way the palette windows of the FLTK interface are. Dear ImGui drops the
  // flag by itself when the backend cannot do it -- which is the case on
  // Wayland, whose protocol has no client-side window positioning -- so it is
  // always safe to ask for it here; _detachablePanels() reports what we got.
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
  // the layout is saved next to the other Gmsh configuration files
  static std::string iniFile = CTX::instance()->homeDir + ".gmsh-imgui.ini";
  io.IniFilename = iniFile.c_str();

  // GMSH_GUI_SCALE overrides the scale factor reported by the windowing system,
  // for the cases where it gets it wrong
  if(const char *env = getenv("GMSH_GUI_SCALE")) {
    double v = atof(env);
    if(v > 0.1 && v < 10.)
      _uiScaleOverride = (float)v;
    else
      Toolkit::report(Toolkit::Warning, "Ignoring GMSH_GUI_SCALE='%s': expected a factor between "
                   "0.1 and 10", env);
  }
  _loadFont();
  applyStyle();

  ImGui_ImplGlfw_InitForOpenGL(_window, true);
  ImGui_ImplOpenGL2_Init();

  if(!drawContext::global() ||
     drawContext::global()->getName() != "ImGui")
    drawContext::setGlobal(new drawContextImGui);

  // from here on, what does not come from this thread is not drawn
  Toolkit::claimThread();
  _console = new messageConsole();
  _browser = new fileBrowser();
  fileBrowser::setHome(CTX::instance()->homeDir);
  _panes.push_back(new scenePane());
  _currentPane = _panes[0];
  _paneRoot = new paneNode(_panes[0]);

  _instance = this;

  // Only now can messages reach the console: Toolkit::report(Toolkit::Info, ) checks
  // Gui::available(), which tests _instance, and in a GUI build nothing goes to
  // the terminal. Everything the interface wants to say about how it started up
  // is therefore said here.
  switch(glfwGetPlatform()) {
  case GLFW_PLATFORM_WAYLAND: Toolkit::report(Toolkit::Info, "Running natively on Wayland"); break;
  case GLFW_PLATFORM_X11:
    Toolkit::report(Toolkit::Info, "Running on X11");
    // Falling back to X11 inside a Wayland session is silent otherwise: GLFW
    // loads the Wayland client libraries with dlopen(), so a session that has
    // them somewhere the dynamic loader does not look ends up on XWayland
    // without anything being obviously wrong.
    {
    const char *forced = getenv("GMSH_GUI_PLATFORM");
    if(getenv("WAYLAND_DISPLAY") && !(forced && !strcmp(forced, "x11"))) {
      Toolkit::report(Toolkit::Warning, "This is a Wayland session, but the native Wayland backend "
                   "could not be used%s%s",
                   _glfwProbeError.size() ? ": " : "",
                   _glfwProbeError.size() ? _glfwProbeError.c_str() : "");
      Toolkit::report(Toolkit::Warning, "Gmsh is therefore going through XWayland; make sure "
                   "libwayland-client, libxkbcommon and libdecor are reachable "
                   "by the dynamic loader (LD_LIBRARY_PATH) to get a native "
                   "window");
    }
    }
    break;
  default: break;
  }
  Toolkit::report(Toolkit::Info, "Scaling the interface by %g (override it with the GMSH_GUI_SCALE "
            "environment variable)", _uiScale);
  if(_fontFile.size())
    Toolkit::report(Toolkit::Info, "Interface font: %s", _fontFile.c_str());
  else
    Toolkit::report(Toolkit::Info, "Interface font: the one embedded in Dear ImGui (no TrueType "
              "font found; set GMSH_GUI_FONT to choose one)");
}

appWindow::~appWindow()
{
  _deletePaneTree(_paneRoot);
  _paneRoot = nullptr;
  for(auto p : _panes) delete p;
  _panes.clear();
  delete _console;
  delete _browser;

  if(_window) {
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(_window);
  }
  glfwTerminate();
}

appWindow *appWindow::instance(int argc, char **argv, bool quitShouldExit)
{
  if(!_instance) {
    appWindow *w = new appWindow(argc, argv, quitShouldExit);
    if(!w->_window) { // creation failed
      delete w;
      _instance = nullptr;
      return nullptr;
    }
  }
  return _instance;
}

void appWindow::destroy()
{
  if(!_instance) return;
  appWindow *w = _instance;
  _instance = nullptr;
  delete w;
}

void appWindow::_deletePaneTree(paneNode *node)
{
  if(!node) return;
  _deletePaneTree(node->child[0]);
  _deletePaneTree(node->child[1]);
  delete node;
}

appWindow::paneNode *appWindow::_findPaneNode(paneNode *node, scenePane *pane)
{
  if(!node) return nullptr;
  if(node->pane == pane) return node;
  if(paneNode *n = _findPaneNode(node->child[0], pane)) return n;
  return _findPaneNode(node->child[1], pane);
}

void appWindow::_layoutPanes(paneNode *node, int x, int y, int w, int h)
{
  if(!node) return;
  if(node->pane) {
    node->pane->setRect(x, y, w, h);
    return;
  }
  double f = node->ratio;
  if(f < 0.01) f = 0.01;
  if(f > 0.99) f = 0.99;
  if(node->split == 'h') {
    int w1 = (int)(w * f);
    _layoutPanes(node->child[0], x, y, w1, h);
    _layoutPanes(node->child[1], x + w1, y, w - w1, h);
  }
  else {
    int h1 = (int)(h * f);
    _layoutPanes(node->child[0], x, y, w, h1);
    _layoutPanes(node->child[1], x, y + h1, w, h - h1);
  }
}

bool appWindow::_isTiled(scenePane *p) const
{
  return p && _paneRoot &&
         const_cast<appWindow *>(this)->_findPaneNode(_paneRoot, p) != nullptr;
}

static void _resetGLState()
{
  glDisable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisable(GL_BLEND);
  glDisable(GL_LIGHTING);
  glDisable(GL_COLOR_MATERIAL);
  glDisable(GL_LINE_STIPPLE);
  glDisable(GL_POLYGON_STIPPLE);
  glShadeModel(GL_SMOOTH);
  glColor4f(1.f, 1.f, 1.f, 1.f);
  glLineWidth(1.f);
  glPointSize(1.f);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

// --- the extra graphic windows
//
// A window of its own, sharing the OpenGL context of the main one so that the
// textures and the display lists are the same, and carrying no Dear ImGui at
// all: the scene is rendered straight into it and the events come from the GLFW
// callbacks below. That is what makes it work on Wayland too, where Dear ImGui
// cannot place a viewport of its own.

appWindow::extraView *appWindow::findExtraView(GLFWwindow *w)
{
  for(auto &v : _extraViews)
    if(v.window == w) return &v;
  return nullptr;
}

static void _extraCursorPos(GLFWwindow *w, double x, double y)
{
  if(!appWindow::available()) return;
  appWindow::extraView *v = appWindow::instance()->findExtraView(w);
  if(!v) return;
  v->input.dx = v->everMoved ? x - v->lastX : 0.;
  v->input.dy = v->everMoved ? y - v->lastY : 0.;
  v->lastX = x;
  v->lastY = y;
  v->everMoved = true;
  v->input.x = x;
  v->input.y = y;
  appWindow::instance()->requestRedraw();
}

static void _extraModifiers(paneInput &in, int mods)
{
  in.shift = (mods & GLFW_MOD_SHIFT) != 0;
  in.ctrl = (mods & GLFW_MOD_CONTROL) != 0;
  in.alt = (mods & GLFW_MOD_ALT) != 0;
  in.super = (mods & GLFW_MOD_SUPER) != 0;
}

// GLFW numbers the buttons left, right, middle; so does Dear ImGui, and so does
// paneInput
static int _extraButton(int glfwButton)
{
  switch(glfwButton) {
  case GLFW_MOUSE_BUTTON_LEFT: return 0;
  case GLFW_MOUSE_BUTTON_RIGHT: return 1;
  case GLFW_MOUSE_BUTTON_MIDDLE: return 2;
  default: return -1;
  }
}

static void _extraMouseButton(GLFWwindow *w, int button, int action, int mods)
{
  if(!appWindow::available()) return;
  appWindow::extraView *v = appWindow::instance()->findExtraView(w);
  if(!v) return;
  int b = _extraButton(button);
  if(b < 0) return;
  _extraModifiers(v->input, mods);
  if(action == GLFW_PRESS) {
    v->input.clicked[b] = true;
    v->input.dragging[b] = true;
    // GLFW does not report double clicks, so they are timed here
    double now = TimeOfDay();
    v->input.doubleClicked = (b == 0 && now - v->lastPress < 0.25);
    v->lastPress = now;
  }
  else {
    v->input.released[b] = true;
    v->input.dragging[b] = false;
  }
  appWindow::instance()->requestRedraw();
}

static void _extraScroll(GLFWwindow *w, double, double dy)
{
  if(!appWindow::available()) return;
  appWindow::extraView *v = appWindow::instance()->findExtraView(w);
  if(!v) return;
  v->input.wheel = dy;
  appWindow::instance()->requestRedraw();
}

static void _extraKey(GLFWwindow *w, int key, int, int action, int mods)
{
  if(action != GLFW_PRESS || !appWindow::available()) return;
  appWindow::extraView *v = appWindow::instance()->findExtraView(w);
  if(!v) return;
  _extraModifiers(v->input, mods);
  // the keys that drive an interactive selection, as in the main window
  if(!v->pane->selectionMode) return;
  switch(key) {
  case GLFW_KEY_E: v->pane->endSelection = 1; break;
  case GLFW_KEY_U: v->pane->undoSelection = 1; break;
  case GLFW_KEY_I:
  case GLFW_KEY_MINUS: v->pane->invertSelection = 1; break;
  case GLFW_KEY_Q:
  case GLFW_KEY_ESCAPE: v->pane->quitSelection = 1; break;
  default: break;
  }
  appWindow::instance()->requestRedraw();
}

void appWindow::_closeExtraView(std::size_t i)
{
  scenePane *dead = _extraViews[i].pane;
  GLFWwindow *w = _extraViews[i].window;
  _extraViews.erase(_extraViews.begin() + i);
  for(auto it = _panes.begin(); it != _panes.end(); it++)
    if(*it == dead) {
      _panes.erase(it);
      break;
    }
  if(_currentPane == dead) _currentPane = _panes.empty() ? nullptr : _panes[0];
  delete dead;
  glfwDestroyWindow(w);
  requestRedraw();
}

void appWindow::_drawExtraViews()
{
  if(_extraViews.empty()) return;

  GLFWwindow *main = glfwGetCurrentContext();
  for(std::size_t i = 0; i < _extraViews.size();) {
    extraView &v = _extraViews[i];
    if(glfwWindowShouldClose(v.window)) {
      _closeExtraView(i);
      continue;
    }

    glfwMakeContextCurrent(v.window);
    int ww = 0, wh = 0, fw = 0, fh = 0;
    glfwGetWindowSize(v.window, &ww, &wh);
    glfwGetFramebufferSize(v.window, &fw, &fh);
    if(ww > 0 && wh > 0) {
      double f = (double)fw / (double)ww;
      v.pane->setRect(0, 0, ww, wh);
      v.pane->setOrigin(0., 0., wh, f);
      _resetGLState();
      v.pane->handleMouse(v.input);
      // the events are one-shot: what has been acted on must not be seen again
      for(int b = 0; b < 3; b++)
        v.input.clicked[b] = v.input.released[b] = false;
      v.input.doubleClicked = false;
      v.input.wheel = 0.;
      v.input.dx = v.input.dy = 0.;

      v.pane->draw(f, wh);

    }
    glfwSwapBuffers(v.window);
    i++;
  }
  glfwMakeContextCurrent(main);
}

void appWindow::newGraphicWindow()
{
  if(!_window) return;

  // sharing the context is what lets the new window use the same textures, in
  // particular the atlas the text of the scene is drawn from
  glfwDefaultWindowHints();
  GLFWwindow *w = glfwCreateWindow(600, 500, "Gmsh", nullptr, _window);
  if(!w) {
    Toolkit::report(Toolkit::Error, "Could not open a new graphic window");
    return;
  }

  scenePane *fresh = new scenePane();
  if(_currentPane)
    fresh->getDrawContext()->copyViewAttributes(_currentPane->getDrawContext());
  _panes.push_back(fresh);

  extraView v;
  v.window = w;
  v.pane = fresh;
  v.number = (int)_extraViews.size() + 2; // window 1 is the main one
  v.lastX = v.lastY = 0.;
  v.lastPress = 0.;
  v.everMoved = false;
  _extraViews.push_back(v);

  char title[64];
  snprintf(title, sizeof(title), "Gmsh - Graphic window %d", v.number);
  glfwSetWindowTitle(w, title);

  glfwSetCursorPosCallback(w, _extraCursorPos);
  glfwSetMouseButtonCallback(w, _extraMouseButton);
  glfwSetScrollCallback(w, _extraScroll);
  glfwSetKeyCallback(w, _extraKey);

  _currentPane = fresh;
  requestRedraw();
}

void appWindow::splitCurrentPane(char how, double ratio)
{
  if(!_currentPane || !_paneRoot) return;

  // The extra graphic windows are not part of the tiling, so they are neither
  // split nor swallowed by "Unsplit": splitting acts on the panes of the main
  // window, whichever one is current.
  scenePane *current = _isTiled(_currentPane) ? _currentPane : nullptr;

  if(how == 'u') {
    scenePane *keep = current;
    if(!keep) { // find any tiled pane to keep
      for(auto p : _panes)
        if(_isTiled(p)) {
          keep = p;
          break;
        }
    }
    if(!keep) return;
    // which panes are tiled has to be known before the tree goes away
    std::vector<scenePane *> tiled;
    for(auto p : _panes)
      if(_isTiled(p)) tiled.push_back(p);
    _deletePaneTree(_paneRoot);
    std::vector<scenePane *> left;
    for(auto p : _panes) {
      bool isTiled =
        std::find(tiled.begin(), tiled.end(), p) != tiled.end();
      if(p == keep || !isTiled)
        left.push_back(p);
      else
        delete p;
    }
    _panes = left;
    _paneRoot = new paneNode(keep);
    if(!_currentPane || _currentPane == keep) _currentPane = keep;
    requestRedraw();
    return;
  }

  if(!current) {
    Toolkit::report(Toolkit::Error, "Only the graphic windows of the main window can be split");
    return;
  }

  if(how != 'h' && how != 'v') {
    Toolkit::report(Toolkit::Error, "Unknown window splitting method '%c'", how);
    return;
  }

  paneNode *node = _findPaneNode(_paneRoot, current);
  if(!node) return;

  scenePane *fresh = new scenePane();
  // the new pane looks at the same thing as the one it was split from
  fresh->getDrawContext()->copyViewAttributes(current->getDrawContext());
  _panes.push_back(fresh);

  node->child[0] = new paneNode(node->pane);
  node->child[1] = new paneNode(fresh);
  node->pane = nullptr;
  node->split = how;
  node->ratio = (ratio <= 0. || ratio >= 1.) ? 0.5 : ratio;

  _currentPane = fresh;
  requestRedraw();
}

scenePane *appWindow::pane(int i)
{
  if(i >= 0 && i < (int)_panes.size()) return _panes[i];
  return nullptr;
}

void appWindow::setCurrentPane(scenePane *p)
{
  if(p) _currentPane = p;
}

void appWindow::setCurrentPane(int index)
{
  if(index >= 0 && index < (int)_panes.size()) _currentPane = _panes[index];
}

drawContext *appWindow::currentDrawContext()
{
  return _currentPane ? _currentPane->getDrawContext() : nullptr;
}

double appWindow::pixelFactor()
{
  if(!_window) return 1.;
  int ww = 0, wh = 0, fw = 0, fh = 0;
  glfwGetWindowSize(_window, &ww, &wh);
  glfwGetFramebufferSize(_window, &fw, &fh);
  return (ww > 0) ? (double)fw / (double)ww : 1.;
}

void appWindow::currentPixelSize(int &w, int &h)
{
  double f = pixelFactor();
  if(_currentPane) {
    w = (int)(_currentPane->w() * f + 0.5);
    h = (int)(_currentPane->h() * f + 0.5);
  }
  else {
    w = h = 0;
  }
}

void appWindow::requestRedraw()
{
  // rendering is done every frame, so there is nothing to mark dirty; waking up
  // the event loop is however needed when it is blocked in glfwWaitEvents()
  if(_window) glfwPostEmptyEvent();
}

void appWindow::addMessage(const std::string &msg, int level)
{
  if(_console) _console->add(msg, level);
}

void appWindow::setStatus(const std::string &msg, bool graphics)
{
  if(!Toolkit::onThread()) return;
  if(graphics) {
    // the message is written on two lines in the view, as in the FLTK backend:
    // what to do, then which keys end or abort it
    if(_currentPane) {
      std::vector<std::string> m = SplitString(msg, '\n');
      _currentPane->screenMessage[0] = (m.size() > 0) ? m[0] : "";
      _currentPane->screenMessage[1] = (m.size() > 1) ? m[1] : "";
    }
    drawContext::global()->draw();
  }
  else
    StatusBar::setMessage(msg);
}

void appWindow::setLastStatus(int color)
{
  if(!Toolkit::onThread()) return;
  StatusBar::setColour(color);
}

void appWindow::setProgress(const std::string &msg, double val, double min,
                            double max)
{
  if(!Toolkit::onThread()) return;
  StatusBar::setProgress(val, min, max);
  StatusBar::setMessage(msg);
}

void appWindow::setGraphicTitle(const std::string &title)
{
  if(!_window) return;
  std::string t = title.empty() ? "Gmsh" : title;
  glfwSetWindowTitle(_window, t.c_str());
}

// Dear ImGui expresses everything it draws in logical pixels and lets the
// backend multiply them by io.DisplayFramebufferScale. Its GLFW backend only
// fills that in on Wayland, where the compositor hands out a framebuffer
// already sized for the display; on X11 and Win32 it forces 1 and the whole
// scaling is ours to do. Reproduce that rule here rather than reading
// io.DisplayFramebufferScale, which is only set once the first frame starts.
float appWindow::_framebufferScale() const
{
  if(!_window) return 1.f;
#if defined(GLFW_PLATFORM_WAYLAND)
  if(glfwGetPlatform() != GLFW_PLATFORM_WAYLAND) return 1.f;
  int ww = 0, wh = 0, fw = 0, fh = 0;
  glfwGetWindowSize(_window, &ww, &wh);
  glfwGetFramebufferSize(_window, &fw, &fh);
  return (ww > 0) ? (float)fw / (float)ww : 1.f;
#else
  return 1.f;
#endif
}

// Whether a panel can be dragged out of the main window into a window of its
// own. Dear ImGui clears the flag we asked for during the first frame when the
// platform cannot do it, so this is only meaningful once running.
bool appWindow::_detachablePanels()
{
  return (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0;
}

void appWindow::_applyStyle(float scale)
{
  if(_uiScale > 0.f && fabs(scale - _uiScale) > 0.01f)
    Toolkit::report(Toolkit::Debug, "Interface scale factor changed from %g to %g", _uiScale, scale);
  _uiScale = scale;
  // what is left for Dear ImGui to apply once the backend has had its share;
  // this is where a Wayland session would otherwise be scaled twice
  float fb = _framebufferScale();
  _styleScale = (fb > 0.f) ? scale / fb : scale;
  Toolkit::report(Toolkit::Debug, "Interface scale %g: %g from the framebuffer, %g from Dear ImGui",
             scale, fb, _styleScale);

  ImGuiStyle fresh;
  if(CTX::instance()->guiColorScheme)
    ImGui::StyleColorsDark(&fresh);
  else
    ImGui::StyleColorsLight(&fresh);

  // spacing, padding and border thickness, all expressed in pixels
  fresh.ScaleAllSizes(_styleScale);
  // Dear ImGui applies FontScaleDpi on top of FontSizeBase; General.FontSize
  // keeps its usual meaning of a size in points, independent of the display
  fresh.FontSizeBase = (CTX::instance()->fontSize > 0) ?
                         (float)CTX::instance()->fontSize :
                         13.f;
  fresh.FontScaleDpi = _styleScale;
  if(_detachablePanels()) {
    // a panel that became a window of its own must not show the rounded
    // corners and the translucent background of a panel floating over the scene
    fresh.WindowRounding = 0.f;
    fresh.Colors[ImGuiCol_WindowBg].w = 1.f;
  }
  ImGui::GetStyle() = fresh;
}

void appWindow::applyStyle()
{
  float scale = _uiScaleOverride;
  if(scale <= 0.f) {
    float sx = 1.f, sy = 1.f;
    if(_window)
      glfwGetWindowContentScale(_window, &sx, &sy);
    else if(GLFWmonitor *m = glfwGetPrimaryMonitor())
      glfwGetMonitorContentScale(m, &sx, &sy);
    scale = (sx > 0.f) ? sx : 1.f;
  }
  _applyStyle(scale);
}

void appWindow::_processAwakeActions()
{
  // what came in from a thread that is not the one drawing; what it means is
  // the caller's, and is said once in src/common/Gui.cpp
  drainPostedFromThread();
}

void appWindow::_buildDockSpace(int &sceneX, int &sceneY, int &sceneW,
                                int &sceneH)
{
  // A full-viewport, invisible host window holds the dock space. The central
  // node is left empty ("pass-through"), which is where the 3D scene is drawn:
  // Dear ImGui does not paint it and does not capture the mouse over it.
  const ImGuiViewport *viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);
  ImGui::SetNextWindowViewport(viewport->ID);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
  ImGuiWindowFlags flags =
    ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
    ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
    ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;
  ImGui::Begin("##gmshDockSpaceHost", nullptr, flags);
  ImGui::PopStyleVar(3);

  // the dock space id must be computed inside its host window: the Dear ImGui
  // id stack is relative to the current window
  const ImGuiID rootId = ImGui::GetID("##gmshDockSpace");
  ImGui::DockSpace(rootId, ImVec2(0.f, 0.f),
                   ImGuiDockNodeFlags_PassthruCentralNode);

  // first run: put the message console at the bottom
  static bool firstTime = true;
  if(firstTime) {
    firstTime = false;
    ImGuiDockNode *node = ImGui::DockBuilderGetNode(rootId);
    if(!node || !node->IsSplitNode()) {
      ImGui::DockBuilderRemoveNode(rootId);
      ImGui::DockBuilderAddNode(rootId, ImGuiDockNodeFlags_DockSpace);
      ImGui::DockBuilderSetNodeSize(rootId, viewport->WorkSize);
      ImGuiID centre = rootId;
      ImGuiID bottom = ImGui::DockBuilderSplitNode(rootId, ImGuiDir_Down, 0.25f,
                                                   nullptr, &centre);
      ImGuiID left = ImGui::DockBuilderSplitNode(centre, ImGuiDir_Left, 0.22f,
                                                 nullptr, &centre);
      ImGui::DockBuilderDockWindow("Messages", bottom);
      ImGui::DockBuilderDockWindow("Modules", left);
      ImGui::DockBuilderFinish(rootId);
    }
  }

  ImGui::End();

  // the central node is where the scene goes
  ImGuiDockNode *central = ImGui::DockBuilderGetCentralNode(rootId);
  if(central) {
    sceneX = (int)(central->Pos.x - viewport->Pos.x);
    sceneY = (int)(central->Pos.y - viewport->Pos.y);
    sceneW = (int)central->Size.x;
    sceneH = (int)central->Size.y;
  }
  else {
    sceneX = (int)(viewport->WorkPos.x - viewport->Pos.x);
    sceneY = (int)(viewport->WorkPos.y - viewport->Pos.y);
    sceneW = (int)viewport->WorkSize.x;
    sceneH = (int)viewport->WorkSize.y;
  }
}

// Dear ImGui and Gmsh share the same fixed-pipeline OpenGL context, and the
// imgui_impl_opengl2 backend does not push GL_TEXTURE_BIT: it leaves its font
// atlas bound and the texture environment set to GL_MODULATE. Put the state
// back to what the Gmsh drawing routines expect before handing the context
// over to them.
void appWindow::_drawScene()
{
  _resetGLState();
  double f = pixelFactor();
  int wh = 0, ww = 0;
  glfwGetWindowSize(_window, &ww, &wh);
  if(_fullscreen) {
    scenePane *p = _fullScreenPane();
    if(p) p->draw(f, wh);
    return;
  }
  // the panes of the extra graphic windows are drawn from their own draw
  // callback instead, see _drawExtraViews()
  for(auto p : _panes)
    if(_isTiled(p)) p->draw(f, wh);
}

// The view that is shown full screen: the current one, unless it belongs to an
// extra graphic window, which is a window of its own and stays as it is.
scenePane *appWindow::_fullScreenPane()
{
  if(_isTiled(_currentPane)) return _currentPane;
  for(auto p : _panes)
    if(_isTiled(p)) return p;
  return nullptr;
}

void appWindow::_handleInput()
{
  ImGuiIO &io = ImGui::GetIO();
  // Dear ImGui does not capture the mouse over the pass-through central node,
  // so this is where the scene gets its events
  if(io.WantCaptureMouse || _modalDepth > 0) {
    // what the pointer was hovering over is no longer under it
    if(io.WantCaptureMouse) setTooltip("");
    return;
  }
  if(io.MousePos.x == -FLT_MAX || io.MousePos.y == -FLT_MAX) return;

  paneInput in;
  in.x = io.MousePos.x;
  in.y = io.MousePos.y;
  in.dx = io.MouseDelta.x;
  in.dy = io.MouseDelta.y;
  in.wheel = io.MouseWheel;
  in.shift = io.KeyShift;
  in.ctrl = io.KeyCtrl;
  in.alt = io.KeyAlt;
  in.super = io.KeySuper;
  for(int b = 0; b < 3; b++) {
    in.clicked[b] = ImGui::IsMouseClicked(b);
    in.released[b] = ImGui::IsMouseReleased(b);
    in.dragging[b] = ImGui::IsMouseDragging(b, 0.f);
  }
  in.doubleClicked = ImGui::IsMouseDoubleClicked(0);

  // the extra graphic windows have their own events, see _drawExtraViews()
  for(auto p : _panes) {
    if(!_isTiled(p)) continue;
    if(p->contains(in.x, in.y) || p == _currentPane) p->handleMouse(in);
  }
}

void appWindow::_runPendingActions()
{
  if(_pendingActions.empty()) return;
  std::vector<std::function<void()> > actions;
  actions.swap(_pendingActions);
  for(auto &a : actions) {
    a();
    if(!_instance) return; // the GUI was destroyed by the action
  }
}

// Everything the interface draws around the 3D view: the dock space, the two
// bars and the panels. Full screen skips it altogether, which is what leaves
// nothing but the view, as in the FLTK interface.
void appWindow::_drawPanels(int &sceneX, int &sceneY, int &sceneW, int &sceneH)
{
  _buildDockSpace(sceneX, sceneY, sceneW, sceneH);

  if(_showConsole) {
    if(ImGui::Begin("Messages", &_showConsole)) _console->draw();
    ImGui::End();
  }

  _drawTooltip();
  _drawMenuBar();
  _drawModulesPanel();
  for(int i = 0; i < Dialog::NumDialogs; i++) _drawDialog(i);
  _drawStatusBar();
}

void appWindow::frame()
{
  if(!_window) return;
  // the mesher calls check() from all over the place, including from inside a
  // draw: never re-enter
  if(_inFrame) return;

  // widget actions run here, outside of NewFrame()/Render(), so that they are
  // free to open a blocking dialog or start an interactive selection, both of
  // which pump frames of their own
  _runPendingActions();
  if(!_instance || !_window || _inFrame) return;

  _inFrame = true;

  glfwMakeContextCurrent(_window);
  glfwPollEvents();

  if(glfwWindowShouldClose(_window)) {
    glfwSetWindowShouldClose(_window, GLFW_FALSE);
    _inFrame = false;
    if(_quitShouldExit)
      Toolkit::quit();
    else
      destroy();
    return;
  }

  _processAwakeActions();

  // the scale can change when the window is moved to another display, and the
  // base font size when the user edits General.FontSize
  {
    float want = _uiScaleOverride;
    if(want <= 0.f) {
      float sx = 1.f, sy = 1.f;
      glfwGetWindowContentScale(_window, &sx, &sy);
      want = (sx > 0.f) ? sx : 1.f;
    }
    float base = (CTX::instance()->fontSize > 0) ?
                   (float)CTX::instance()->fontSize :
                   13.f;
    float fb = _framebufferScale();
    if(fabs(want - _uiScale) > 0.01f ||
       fabs((fb > 0.f ? want / fb : want) - _styleScale) > 0.01f ||
       fabs(base - ImGui::GetStyle().FontSizeBase) > 0.01f)
      _applyStyle(want);
  }

  ImGui_ImplOpenGL2_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  int sx = 0, sy = 0, sw = 1, sh = 1;

  // Full screen keeps nothing but the 3D view, as the FLTK interface does:
  // there it shows a graphic window of its own and hides everything else, so
  // here the dock space, the two bars and the panels are simply not drawn.
  // Nothing has to be saved and restored, because nothing is changed: Ctrl+F
  // again brings the interface back exactly as it was, which is the one thing
  // an immediate-mode interface makes easy.
  if(_fullscreen) {
    const ImGuiViewport *viewport = ImGui::GetMainViewport();
    sw = (int)viewport->Size.x;
    sh = (int)viewport->Size.y;
  }
  else
    _drawPanels(sx, sy, sw, sh);

  // these stay in both: a blocking dialog must be usable full screen too
  _stepAnimation();
  _drawModal();
  _browser->draw();
  _drawExportDialog();

  if(_fullscreen) {
    // one view, filling the window
    scenePane *p = _fullScreenPane();
    if(p) p->setRect(sx, sy, sw, sh);
  }
  else
    _layoutPanes(_paneRoot, sx, sy, sw, sh);
  {
    // the tiled panes live in the main window; telling them where it is on the
    // screen is what lets them turn io.MousePos into their own coordinates
    const ImGuiViewport *vp = ImGui::GetMainViewport();
    int wh = 0, ww = 0;
    glfwGetWindowSize(_window, &ww, &wh);
    for(auto p : _panes)
      if(_isTiled(p)) p->setOrigin(vp->Pos.x, vp->Pos.y, wh, pixelFactor());
  }
  _handleInput();
  _handleShortcuts();

  ImGui::Render();

  int fw = 0, fh = 0;
  glfwGetFramebufferSize(_window, &fw, &fh);
  glViewport(0, 0, fw, fh);
  glDisable(GL_SCISSOR_TEST);
  glClearColor(0.f, 0.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _drawScene();

  ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

  // draw the panels that live in a window of their own; they have their own
  // OpenGL context, so the one the scene is drawn in has to be put back
  if(_detachablePanels()) {
    GLFWwindow *current = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(current);
  }

  glfwSwapBuffers(_window);

  // the extra graphic windows are windows of their own: they are rendered once
  // the main one is done, each with its own context made current
  _drawExtraViews();

  // Dear ImGui only settles this during the first frame, so it cannot be said
  // along with the other startup messages
  if(!_reportedDetachable) {
    _reportedDetachable = true;
    if(_detachablePanels())
      Toolkit::report(Toolkit::Debug, "Panels can be dragged out of the main window");
    else
      Toolkit::report(Toolkit::Info, "Panels can only be moved inside the main window: this "
                "windowing system does not let an application place its own "
                "windows");
  }

  _inFrame = false;
}

// The picking actions report what is under the pointer through
// Gui::drawTooltip(); the FLTK interface has a small window following the mouse
// for that, here it is a plain Dear ImGui tooltip. The action clears it by
// passing an empty text when it is done.
void appWindow::_drawTooltip()
{
  if(_tooltip.empty()) return;
  ImGui::SetNextWindowBgAlpha(0.9f);
  if(ImGui::BeginTooltip()) {
    ImGui::TextUnformatted(_tooltip.c_str());
    ImGui::EndTooltip();
  }
}

void appWindow::_drawModal()
{
  if(!_modal.active) return;

  const char *title = _modal.isInput ? "Gmsh##input" : "Gmsh##question";
  if(!ImGui::IsPopupOpen(title)) ImGui::OpenPopup(title);

  ImVec2 center = ImGui::GetMainViewport()->GetCenter();
  ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
  if(ImGui::BeginPopupModal(title, nullptr,
                            ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::TextUnformatted(_modal.question.c_str());
    ImGui::Separator();
    if(_modal.isInput) {
      ImGui::SetNextItemWidth(400.f);
      if(ImGui::IsWindowAppearing()) ImGui::SetKeyboardFocusHere();
      bool enter = ImGui::InputText("##value", _modal.buffer,
                                    sizeof(_modal.buffer),
                                    ImGuiInputTextFlags_EnterReturnsTrue);
      if(enter || ImGui::Button("OK")) {
        _modal.answer = 1;
        _modal.done = true;
      }
      ImGui::SameLine();
      if(ImGui::Button("Cancel") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
        _modal.answer = 0;
        _modal.done = true;
      }
    }
    else {
      // same order as fl_choice(): button 0 on the right, then 1, then 2
      for(int i = 2; i >= 0; i--) {
        if(_modal.choices[i].empty()) continue;
        if(ImGui::Button(_modal.choices[i].c_str())) {
          _modal.answer = i;
          _modal.done = true;
        }
        ImGui::SameLine();
      }
      ImGui::NewLine();
    }
    if(_modal.done) ImGui::CloseCurrentPopup();
    ImGui::EndPopup();
  }
}

void appWindow::_pumpModal()
{
  _modalDepth++;
  while(!_modal.done && _instance && _window &&
        !glfwWindowShouldClose(_window)) {
    glfwWaitEventsTimeout(0.05);
    frame();
  }
  _modalDepth--;
  _modal.active = false;
}

bool appWindow::inputDialog(const std::string &question, std::string &value)
{
  if(!_window) return false;
  if(_inFrame) {
    // a dialog cannot be opened from within a frame: this would mean nesting
    // Dear ImGui frames. Widgets must post their actions through postAction().
    Toolkit::report(Toolkit::Debug, "Ignoring input dialog requested from within a frame");
    return false;
  }
  _modal = modalState();
  _modal.active = true;
  _modal.isInput = true;
  _modal.question = question;
  strncpy(_modal.buffer, value.c_str(), sizeof(_modal.buffer) - 1);
  _modal.buffer[sizeof(_modal.buffer) - 1] = '\0';
  _pumpModal();
  if(_modal.answer != 1) return false;
  value = _modal.buffer;
  return true;
}

int appWindow::questionDialog(const std::string &question,
                              const std::string &zero, const std::string &one,
                              const std::string &two)
{
  if(!_window) return 0;
  if(_inFrame) {
    Toolkit::report(Toolkit::Debug, "Ignoring question dialog requested from within a frame");
    return 0;
  }
  _modal = modalState();
  _modal.active = true;
  _modal.isInput = false;
  _modal.question = question;
  _modal.choices[0] = zero;
  _modal.choices[1] = one;
  _modal.choices[2] = two;
  _pumpModal();
  return _modal.answer;
}

bool appWindow::fileDialog(int mode, const std::string &title,
                           const std::vector<fileBrowser::format> &formats,
                           std::string &fileName, int *chosenFormat)
{
  if(!_window) return false;
  if(_inFrame) {
    Toolkit::report(Toolkit::Debug, "Ignoring file dialog requested from within a frame");
    return false;
  }
  _browser->begin(mode ? fileBrowser::Save : fileBrowser::Open, title, formats,
                  fileName);
  _modalDepth++;
  while(!_browser->done() && _instance && _window &&
        !glfwWindowShouldClose(_window)) {
    glfwWaitEventsTimeout(0.05);
    frame();
  }
  _modalDepth--;
  bool ok = _browser->accepted();
  if(ok) fileName = _browser->result();
  if(chosenFormat) *chosenFormat = _browser->chosen();
  _browser->finish();
  return ok && !fileName.empty();
}

void appWindow::check(bool rateLimited)
{
  // never pump events from a worker thread: GLFW and OpenGL are only valid on
  // the thread that created the window
  if(!Toolkit::onThread() || _locked > 0) return;
  double start = TimeOfDay();
  if(rateLimited && CTX::instance()->guiRefreshRate > 0) {
    if(start - _lastRefresh > 1. / CTX::instance()->guiRefreshRate) {
      _lastRefresh = start;
      frame();
    }
  }
  else {
    _lastRefresh = start;
    frame();
  }
}

bool appWindow::ready()
{
  return _window && !_inFrame;
}

void appWindow::wait(bool force)
{
  if(!force && (!Toolkit::onThread() || _locked > 0)) return;
  if(!_window) return;
  glfwWaitEvents();
  frame();
}

void appWindow::wait(double time, bool force)
{
  if(!force && (!Toolkit::onThread() || _locked > 0)) return;
  if(!_window) return;
  if(time > 0.)
    glfwWaitEventsTimeout(time);
  else
    glfwPollEvents();
  frame();
}

void appWindow::drawCurrentPane()
{
  if(!_window || !_currentPane) return;
  glfwMakeContextCurrent(_window);
  int wh = 0, ww = 0;
  glfwGetWindowSize(_window, &ww, &wh);
  double f = pixelFactor();

  if(_captureW > 0 && _captureH > 0) {
    // put the picture in the bottom-left corner of the frame buffer, at the
    // requested size, and clear everything else so that no left-over widget
    // ends up in it
    int lw = (int)(_captureW / f + 0.5), lh = (int)(_captureH / f + 0.5);
    int fw = 0, fh = 0;
    glfwGetFramebufferSize(_window, &fw, &fh);
    glDisable(GL_SCISSOR_TEST);
    glViewport(0, 0, fw, fh);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // remember the on-screen layout, draw into the capture rectangle, restore
    std::vector<int> saved(_panes.size() * 4);
    for(std::size_t i = 0; i < _panes.size(); i++) {
      saved[4 * i + 0] = _panes[i]->x();
      saved[4 * i + 1] = _panes[i]->y();
      saved[4 * i + 2] = _panes[i]->w();
      saved[4 * i + 3] = _panes[i]->h();
    }
    if(_captureComposite && _panes.size() > 1) {
      // General.PrintCompositeWindows: keep the tiling of the panes
      _layoutPanes(_paneRoot, 0, wh - lh, lw, lh);
      for(auto p : _panes) p->draw(f, wh);
    }
    else {
      _currentPane->setRect(0, wh - lh, lw, lh);
      _currentPane->draw(f, wh);
    }
    for(std::size_t i = 0; i < _panes.size(); i++)
      _panes[i]->setRect(saved[4 * i + 0], saved[4 * i + 1], saved[4 * i + 2],
                         saved[4 * i + 3]);
  }
  else {
    _currentPane->draw(f, wh);
  }
  glFlush();
}

void appWindow::beginCapture(int &width, int &height, bool composite)
{
  _captureComposite = composite;
  int fw = 0, fh = 0;
  if(_window) glfwGetFramebufferSize(_window, &fw, &fh);
  if(width > fw || height > fh) {
    Toolkit::report(Toolkit::Warning, "The ImGui interface cannot render a picture larger than the "
                 "window (%d x %d): clamping", fw, fh);
    width = std::min(width, fw);
    height = std::min(height, fh);
  }
  if(width < 1) width = 1;
  if(height < 1) height = 1;
  _captureW = width;
  _captureH = height;
}

void appWindow::endCapture()
{
  _captureW = _captureH = 0;
  _captureComposite = false;
}

int appWindow::runLoop()
{
  if(!_window) return 0;
  // the scene is drawn once before the loop, which is what makes a window
  // that has just come up show something
  drawContext::global()->draw(false);
  while(_instance && _window && !glfwWindowShouldClose(_window)) frame();
  return 0;
}

void appWindow::wake()
{
  if(_instance && _instance->_window) glfwPostEmptyEvent();
}

#endif
