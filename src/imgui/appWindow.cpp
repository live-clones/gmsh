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
    _frames(3), _keepDrawing(false),
    _lastRefresh(0.), _console(nullptr),
    _showConsole(true),
    _showModules(true),
    _uiScale(0.f),
    _uiScaleOverride(0.f), _styleScale(0.f), _reportedDetachable(false),
    _zoomed(false), _fullscreen(false), _savedX(0), _savedY(0), _savedW(0), _savedH(0), _modalDepth(0),
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

  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);

  Toolkit::claimThread();
  _console = new messageConsole();
  _browser = new fileBrowser();
  // the scene, its host and its first view
  imguiSceneStart(_window);

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
  if(_window) {
    glfwMakeContextCurrent(_window);
    imguiSceneStop();
  }
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
  imguiSceneRedraw();
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

  _drawModal();
  _browser->draw();

  imguiScenePlace(sx, sy, sw, sh, _fullscreen);
  // the scene gets its events over the pass-through central node
  imguiScenePointer(ImGui::GetIO().WantCaptureMouse || _modalDepth > 0);
  _handleShortcuts();

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

  imguiSceneDraw();
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
  imguiSceneWindows();

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
