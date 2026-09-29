// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

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
#include "glfwScreen.h"

#include "appWindow.h"
#include "uiSources.h"
#include "toolkit.h"
#include "sceneView.h"
#include "sceneHost.h"
#include "sceneGamepad.h"
#include "messageConsole.h"
#include "fileBrowser.h"
#include "drawContextGL.h"
#include "OS.h"
#include "drawContext.h"

appWindow *appWindow::_instance = nullptr;
std::string appWindow::_openedThroughMacFinder = "";
bool appWindow::_finishedProcessingCommandLine = false;
std::atomic<int> appWindow::_locked(0);

// while probing the windowing systems a failure must not be reported:
// Toolkit::report(Error) makes the public API throw
static bool _glfwProbing = false;

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
  std::vector<std::string> said;
  for(int i = 0; i < count; i++) said.push_back(paths[i]);
  imguiDropped(said);
}

// on Linux GLFW selects Wayland when available; GMSH_GUI_PLATFORM ("wayland",
// "x11", "any") forces it, with a fallback when the client libraries are
// missing
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
  : _window(nullptr), _inFrame(false),
    _frames(3), _keepDrawing(false), _sceneWanted(true), _sceneCopy(0),
    _lastRefresh(0.), _currentPane(nullptr), _console(nullptr),
    _showConsole(true),
    _showModules(true),
    _paneRoot(nullptr), _uiScale(0.f),
    _uiScaleOverride(0.f), _styleScale(0.f), _reportedDetachable(false),
    _animating(false), _zoomed(false), _fullscreen(false), _savedX(0), _savedY(0), _savedW(0), _savedH(0), _captureW(0), _captureH(0), _captureComposite(false), _modalDepth(0),
    _browser(nullptr)
{
  glfwSetErrorCallback(_glfwErrorCallback);
  if(!_initGlfw()) return;

  // a compatibility profile: the fixed pipeline, GLU and imgui_impl_opengl2
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
  glfwWindowHint(GLFW_DEPTH_BITS, 24);
  const Ui::Backend::Settings set = imguiSources().settings();
  if(set.antialiasing) glfwWindowHint(GLFW_SAMPLES, 4);

  // the Wayland app id and the X11 WM_CLASS, which window rules key on: the
  // base name of utils/freedesktop/info.gmsh.gmsh.desktop, and its
  // StartupWMClass
  glfwWindowHintString(GLFW_WAYLAND_APP_ID, "info.gmsh.gmsh");
  glfwWindowHintString(GLFW_X11_CLASS_NAME, "Gmsh");
  glfwWindowHintString(GLFW_X11_INSTANCE_NAME, "gmsh");

  int w = set.sceneWidth + set.treeWidth;
  int h = set.sceneHeight + set.consoleHeight;
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
  // Dear ImGui drops the flag by itself where the backend cannot, as on Wayland
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
  static std::string iniFile = set.homeDir + ".gmsh-imgui.ini";
  io.IniFilename = iniFile.c_str();

  // GMSH_GUI_SCALE overrides the scale factor of the windowing system
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

  {
    Scene::Host held;
    held.redraw = []() {
      if(appWindow::available()) appWindow::instance()->requestRedraw();
    };
    held.check = [](bool rateLimited) {
      if(appWindow::available()) appWindow::instance()->check(rateLimited);
    };
    held.wait = [](double seconds, bool force) {
      if(!appWindow::available()) return;
      if(seconds < 0.)
        appWindow::instance()->wait(force);
      else
        appWindow::instance()->wait(seconds, force);
    };
    held.drawCurrent = []() {
      if(appWindow::available()) appWindow::instance()->drawCurrentPane();
    };
    held.uiScale = []() {
      return appWindow::available() ? appWindow::instance()->uiScale() : 1.f;
    };
    held.screen = glfwScreen;
    held.numViews = []() {
      return appWindow::available() ? appWindow::instance()->numPanes() : 0;
    };
    held.cursor = [](Scene::Cursor kind) {
      if(kind == Scene::Picking) ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
    };
    held.current = []() -> sceneView * {
      return appWindow::available() ? appWindow::instance()->currentPane() :
                                      nullptr;
    };
    held.setCurrent = [](sceneView *view) {
      if(appWindow::available()) appWindow::instance()->setCurrentPane(view);
    };
    held.later = Scene::later;
    held.buttonDown = []() {
      return ImGui::GetCurrentContext() &&
             (ImGui::IsMouseDown(ImGuiMouseButton_Left) ||
              ImGui::IsMouseDown(ImGuiMouseButton_Right) ||
              ImGui::IsMouseDown(ImGuiMouseButton_Middle));
    };
    held.context = []() -> void * { return glfwGetCurrentContext(); };
    held.makeCurrent = [](sceneView *view) {
      if(appWindow::available()) appWindow::instance()->makeCurrent(view);
    };
    Scene::setHost(held);
  }

  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);

  Toolkit::claimThread();
  _console = new messageConsole();
  _browser = new fileBrowser();
  _panes.push_back(new sceneView());
  _currentPane = _panes[0];
  _paneRoot = new paneNode(_panes[0]);
  _panes[0]->contextChanged();

  _instance = this;

  // messages reach the console only once _instance is set: what the interface
  // says about its start-up is said here
  switch(glfwGetPlatform()) {
  case GLFW_PLATFORM_WAYLAND: Toolkit::report(Toolkit::Info, "Running natively on Wayland"); break;
  case GLFW_PLATFORM_X11:
    Toolkit::report(Toolkit::Info, "Running on X11");
    // GLFW loads the Wayland client libraries with dlopen(): a session missing
    // them lands on XWayland silently
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

appWindow::paneNode *appWindow::_findPaneNode(paneNode *node, sceneView *pane)
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

bool appWindow::_isTiled(sceneView *p) const
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

// --- the extra graphic windows: a window of its own, sharing the OpenGL context of the main one, with no Dear ImGui in it -- which is what works on Wayland, where Dear ImGui cannot place a viewport

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
  sceneView *dead = _extraViews[i].pane;
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

  // sharing the context: the same textures, the atlas in particular
  glfwDefaultWindowHints();
  GLFWwindow *w = glfwCreateWindow(600, 500, "Gmsh", nullptr, _window);
  if(!w) {
    Toolkit::report(Toolkit::Error, "Could not open a new graphic window");
    return;
  }

  sceneView *fresh = new sceneView();
  if(_currentPane)
    fresh->getDrawContext()->copyViewAttributes(_currentPane->getDrawContext());
  _panes.push_back(fresh);
  glfwMakeContextCurrent(w);
  fresh->contextChanged();
  glfwMakeContextCurrent(_window);

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

  // the extra windows are not part of the tiling
  sceneView *current = _isTiled(_currentPane) ? _currentPane : nullptr;

  if(how == 'u') {
    sceneView *keep = current;
    if(!keep) { // find any tiled pane to keep
      for(auto p : _panes)
        if(_isTiled(p)) {
          keep = p;
          break;
        }
    }
    if(!keep) return;
    std::vector<sceneView *> tiled;
    for(auto p : _panes)
      if(_isTiled(p)) tiled.push_back(p);
    _deletePaneTree(_paneRoot);
    std::vector<sceneView *> left;
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

  sceneView *fresh = new sceneView();
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

sceneView *appWindow::pane(int i)
{
  if(i >= 0 && i < (int)_panes.size()) return _panes[i];
  return nullptr;
}

void appWindow::setCurrentPane(sceneView *p)
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

void appWindow::requestFrame()
{
  // a few frames rather than one: what changed often takes another to settle;
  // the empty event wakes the loop, from another thread too
  _frames = 3;
  if(_window) glfwPostEmptyEvent();
}

void appWindow::requestRedraw()
{
  requestFrame();
  _sceneWanted = true;
}

void appWindow::addMessage(const std::string &msg, int level)
{
  if(_console) _console->add(msg, level);
  // a message from a mesher with nobody touching the interface would wait for
  // the next frame
  requestFrame();
}

void appWindow::setGraphicTitle(const std::string &title)
{
  if(!_window) return;
  std::string t = title.empty() ? "Gmsh" : title;
  glfwSetWindowTitle(_window, t.c_str());
}

// the GLFW backend fills io.DisplayFramebufferScale on Wayland only; on X11 and
// Win32 the scaling is ours; reproduced here since it is only set once the
// first frame starts
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

// Dear ImGui clears the flag during the first frame when the platform cannot:
// only meaningful once running
bool appWindow::_detachablePanels()
{
  return (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0;
}

void appWindow::_applyStyle(float scale)
{
  if(_uiScale > 0.f && fabs(scale - _uiScale) > 0.01f)
    Toolkit::report(Toolkit::Debug, "Interface scale factor changed from %g to %g", _uiScale, scale);
  _uiScale = scale;
  // a Wayland session would otherwise be scaled twice
  float fb = _framebufferScale();
  _styleScale = (fb > 0.f) ? scale / fb : scale;
  Toolkit::report(Toolkit::Debug, "Interface scale %g: %g from the framebuffer, %g from Dear ImGui",
             scale, fb, _styleScale);

  const Ui::Backend::Settings set = imguiSources().settings();
  ImGuiStyle fresh;
  if(set.darkScheme)
    ImGui::StyleColorsDark(&fresh);
  else
    ImGui::StyleColorsLight(&fresh);

  // as the page has it: frames white with a light border and barely rounded,
  // what is chosen in the colour of the tab showing, rules light
  fresh.FrameBorderSize = 1.f;
  fresh.FrameRounding = 2.f;
  fresh.GrabRounding = 2.f;
  if(!set.darkScheme) {
    ImVec4 chosen(152 / 255.f, 186 / 255.f, 225 / 255.f, 1.f);
    ImVec4 rule(204 / 255.f, 204 / 255.f, 204 / 255.f, 1.f);
    fresh.Colors[ImGuiCol_Border] = rule;
    fresh.Colors[ImGuiCol_Separator] = rule;
    fresh.Colors[ImGuiCol_Header] = chosen;
  }
  fresh.ScaleAllSizes(_styleScale);
  // General.FontSize stays a size in points, of the em as in FLTK and the
  // page, where Dear ImGui sizes the line
  fresh.FontSizeBase =
    ((set.fontSize > 0) ? (float)set.fontSize : 13.f) * _fontLine;
  fresh.FontScaleDpi = _styleScale;
  if(_detachablePanels()) {
    // no rounded corners nor translucent background on a panel that became a
    // window
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
  drainPostedFromThread();
}

void appWindow::_buildDockSpace(int &sceneX, int &sceneY, int &sceneW,
                                int &sceneH)
{
  // the central node is pass-through: the scene is drawn there, and Dear ImGui
  // does not capture the mouse over it
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

  // the id stack is relative to the current window
  const ImGuiID rootId = ImGui::GetID("##gmshDockSpace");
  ImGui::DockSpace(rootId, ImVec2(0.f, 0.f),
                   ImGuiDockNodeFlags_PassthruCentralNode);

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

// imgui_impl_opengl2 does not push GL_TEXTURE_BIT: the atlas stays bound and
// the environment set to GL_MODULATE
void appWindow::_drawScene()
{
  _resetGLState();
  double f = pixelFactor();
  int wh = 0, ww = 0;
  glfwGetWindowSize(_window, &ww, &wh);
  if(_fullscreen) {
    sceneView *p = _fullScreenPane();
    if(p) p->draw(f, wh);
    return;
  }
  for(auto p : _panes)
    if(_isTiled(p)) p->draw(f, wh);
}

void appWindow::_keepSceneCopy(const int rect[4])
{
  if(rect[2] < 1 || rect[3] < 1) {
    if(_sceneCopy) glDeleteTextures(1, &_sceneCopy);
    _sceneCopy = 0;
    return;
  }
  if(!_sceneCopy) {
    glGenTextures(1, &_sceneCopy);
    glBindTexture(GL_TEXTURE_2D, _sceneCopy);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  }
  else
    glBindTexture(GL_TEXTURE_2D, _sceneCopy);
  glReadBuffer(GL_BACK);
  glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, rect[0], rect[1], rect[2], rect[3],
                   0);
  glBindTexture(GL_TEXTURE_2D, 0);
  memcpy(_sceneCopyRect, rect, sizeof(_sceneCopyRect));
}

void appWindow::_showSceneCopy()
{
  const int *r = _sceneCopyRect;
  int fw = 0, fh = 0;
  glfwGetFramebufferSize(_window, &fw, &fh);
  Scene::plainPipeline();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., fw, 0., fh, -1., 1.);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glDisable(GL_BLEND);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, _sceneCopy);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glColor4f(1.f, 1.f, 1.f, 1.f);
  glBegin(GL_QUADS);
  glTexCoord2f(0.f, 0.f);
  glVertex2f((float)r[0], (float)r[1]);
  glTexCoord2f(1.f, 0.f);
  glVertex2f((float)(r[0] + r[2]), (float)r[1]);
  glTexCoord2f(1.f, 1.f);
  glVertex2f((float)(r[0] + r[2]), (float)(r[1] + r[3]));
  glTexCoord2f(0.f, 1.f);
  glVertex2f((float)r[0], (float)(r[1] + r[3]));
  glEnd();
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
}

// the current view, unless it belongs to an extra window, which stays as it is
sceneView *appWindow::_fullScreenPane()
{
  if(_isTiled(_currentPane)) return _currentPane;
  for(auto p : _panes)
    if(_isTiled(p)) return p;
  return nullptr;
}

void appWindow::_handleInput()
{
  ImGuiIO &io = ImGui::GetIO();
  // the scene gets its events over the pass-through central node
  bool outside = io.WantCaptureMouse || _modalDepth > 0 ||
                 io.MousePos.x == -FLT_MAX || io.MousePos.y == -FLT_MAX;
  // the pane the pointer left forgets what it was over
  sceneView *over = nullptr;
  for(auto p : _panes)
    if(!outside && _isTiled(p) && p->contains(io.MousePos.x, io.MousePos.y))
      over = p;
  if(over != _pointerPane) {
    if(std::find(_panes.begin(), _panes.end(), _pointerPane) != _panes.end())
      _pointerPane->pointerLeft();
    _pointerPane = over;
  }
  if(outside) return;

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

void appWindow::_drawPanels(int &sceneX, int &sceneY, int &sceneW, int &sceneH)
{
  _buildDockSpace(sceneX, sceneY, sceneW, sceneH);

  if(_showConsole) {
    if(ImGui::Begin("Messages", &_showConsole)) _console->draw();
    ImGui::End();
  }

  _drawMenuBar();
  _drawModulesPanel();
  // off a copy: drawing one may ask for another to be made
  std::vector<const Ui::Form *> dialogs;
  for(const auto &it : _dialogs) dialogs.push_back(it.first);
  for(const Ui::Form *which : dialogs) _drawDialog(which);
  _drawStatusBar();
}

void appWindow::frame()
{
  if(!_window) return;
  // the mesher calls check() from inside a draw: never re-enter
  if(_inFrame) return;

  // outside of NewFrame()/Render(): they may open a blocking dialog or a
  // selection, which pump frames of their own
  _runPendingActions();
  if(!_instance || !_window || _inFrame) return;

  _inFrame = true;
  Scene::fireTimers();

  glfwMakeContextCurrent(_window);
  glfwPollEvents();

  if(glfwWindowShouldClose(_window)) {
    glfwSetWindowShouldClose(_window, GLFW_FALSE);
    _inFrame = false;
    Toolkit::quit();
    return;
  }

  _processAwakeActions();

  // the scale changes with the display, the base size with General.FontSize
  {
    float want = _uiScaleOverride;
    if(want <= 0.f) {
      float sx = 1.f, sy = 1.f;
      glfwGetWindowContentScale(_window, &sx, &sy);
      want = (sx > 0.f) ? sx : 1.f;
    }
    int said = imguiSources().settings().fontSize;
    float base = ((said > 0) ? (float)said : 13.f) * _fontLine;
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

  // full screen draws nothing but the 3D view
  if(_fullscreen) {
    const ImGuiViewport *viewport = ImGui::GetMainViewport();
    sw = (int)viewport->Size.x;
    sh = (int)viewport->Size.y;
  }
  else
    _drawPanels(sx, sy, sw, sh);

  _stepAnimation();
  _drawModal();
  _browser->draw();

  if(_fullscreen) {
    sceneView *p = _fullScreenPane();
    if(p) p->setRect(sx, sy, sw, sh);
  }
  else
    _layoutPanes(_paneRoot, sx, sy, sw, sh);
  int wh = 0, ww = 0;
  glfwGetWindowSize(_window, &ww, &wh);
  {
    // where the main window is on the screen turns io.MousePos into pane
    // coordinates
    const ImGuiViewport *vp = ImGui::GetMainViewport();
    for(auto p : _panes)
      if(_isTiled(p)) p->setOrigin(vp->Pos.x, vp->Pos.y, wh, pixelFactor());
  }
  _handleInput();
  _handleShortcuts();
  // the frame that follows is the picture the gamepad asked for
  Scene::gamepadTurn(currentPane());

  // whatever the user is in the middle of needs the next frame now
  {
    ImGuiIO &io = ImGui::GetIO();
    _keepDrawing = io.WantTextInput || ImGui::IsAnyItemActive() ||
                   ImGui::IsAnyItemHovered() || io.MouseDown[0] ||
                   io.MouseDown[1] || io.MouseDown[2] || _modal.active;
  }
  if(_frames > 0) _frames--;

  ImGui::Render();

  int fw = 0, fh = 0;
  glfwGetFramebufferSize(_window, &fw, &fh);
  glViewport(0, 0, fw, fh);
  glDisable(GL_SCISSOR_TEST);
  glClearColor(0.f, 0.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  double f = pixelFactor();
  int rect[4] = {(int)(sx * f + 0.5), (int)((wh - sy - sh) * f + 0.5),
                 (int)(sw * f + 0.5), (int)(sh * f + 0.5)};
  bool kept = _sceneCopy && !_sceneWanted && !memcmp(rect, _sceneCopyRect, sizeof(rect));
  if(kept)
    _showSceneCopy();
  else {
    _drawScene();
    _keepSceneCopy(rect);
    _sceneWanted = false;
  }
  Scene::plainPipeline();

  ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

  // the panels in windows of their own have their own context: the scene's is
  // put back
  if(_detachablePanels()) {
    GLFWwindow *current = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(current);
  }

  glfwSwapBuffers(_window);

  // rendered once the main window is done, each with its own context
  _drawExtraViews();

  // settled during the first frame only
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
    // not from within a frame: widgets post their actions through postAction()
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
  // GLFW and OpenGL are only valid on the thread that created the window
  if(!Toolkit::onThread() || _locked > 0) return;
  double start = TimeOfDay();
  double rate = imguiSources().settings().refreshRate;
  if(rateLimited && rate > 0) {
    if(start - _lastRefresh > 1. / rate) {
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
  double next = Scene::nextTimer();
  if(next >= 0.)
    glfwWaitEventsTimeout(next);
  else
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

void appWindow::makeCurrent(sceneView *view)
{
  for(const auto &v : _extraViews)
    if(v.pane == view && v.window) {
      glfwMakeContextCurrent(v.window);
      return;
    }
  if(_window) glfwMakeContextCurrent(_window);
}

void appWindow::drawCurrentPane()
{
  if(!_window || !_currentPane) return;
  glfwMakeContextCurrent(_window);
  int wh = 0, ww = 0;
  glfwGetWindowSize(_window, &ww, &wh);
  double f = pixelFactor();

  if(_captureW > 0 && _captureH > 0) {
    // in the bottom-left corner, everything else cleared so that no widget ends
    // up in it
    int lw = (int)(_captureW / f + 0.5), lh = (int)(_captureH / f + 0.5);
    int fw = 0, fh = 0;
    glfwGetFramebufferSize(_window, &fw, &fh);
    glDisable(GL_SCISSOR_TEST);
    glViewport(0, 0, fw, fh);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
  while(_instance && _window && !glfwWindowShouldClose(_window)) {
    // every event wakes this, and what is still moving says so through
    // _keepDrawing; the timeout catches what nobody announced, as rarely as a
    // stale window allows; a gamepad wakes it at the rate the scene asks
    double pad = Scene::gamepadPeriod(), next = Scene::nextTimer();
    if(pad > 0.)
      glfwWaitEventsTimeout(next >= 0. ? std::min(pad, next) : pad);
    else if(next >= 0.)
      glfwWaitEventsTimeout(next);
    else if(!_keepDrawing && _frames <= 0)
      glfwWaitEventsTimeout(2.);
    frame();
  }
  return 0;
}

void appWindow::wake()
{
  if(_instance && _instance->_window) glfwPostEmptyEvent();
}
