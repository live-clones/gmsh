// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The Dear ImGui interface: one GLFW window with its OpenGL context and the
// Dear ImGui context -- the menu bar along the top, the dock space where the
// tree, the console and the forms are panels, the scene in its central node,
// the bar along the bottom -- drawn afresh at every frame. The loop is ours,
// so that check() and wait() can turn it from inside the mesher, and a
// question can run frames of its own.

#include "GmshConfig.h"

#include <algorithm>
#include <atomic>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <mutex>
#include <regex>
#include <string>
#include <thread>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <GLFW/glfw3.h>

#include "imgui_stdlib.h"
#include "imguiCommon.h"
#include "Console.h"
#include "Glyph.h"
#include "sceneView.h"
#include "sceneHost.h"
#include "sceneGamepad.h"
#include "drawContextGL.h"
#include "drawContext.h"
#include "OS.h"

namespace {

  // --- the thread it runs on: the mesher calls in from its worker threads,
  // and what comes from elsewhere is dropped

  std::thread::id _thread;
  bool _claimed = false;

  void _claimThread()
  {
    _thread = std::this_thread::get_id();
    _claimed = true;
  }

  // before anyone has claimed it, everything is on it: there is no interface
  // to be re-entered
  bool _onThread() { return !_claimed || std::this_thread::get_id() == _thread; }

  void _quit()
  {
    if(imguiHost().quitting) imguiHost().quitting();
  }

  // the posted work and the files dropped, handed over by the backend
  void _drainPosted();
  void _dropped(const std::vector<std::string> &paths);

  // --- the console: the lines Ui::Console keeps, the bar over them

  class console {
  private:
    Ui::Console _said;
    std::string _filter;
    bool _scrollToBottom;

  public:
    console() : _said(50000), _scrollToBottom(false) {}
    void add(const std::string &msg, int level)
    {
      if(_said.add(msg, level) && _said.autoScroll()) _scrollToBottom = true;
    }
    void clear() { _said.clear(); }
    // writing it to a file is the caller's
    void lines(std::vector<std::string> &out) const { out = _said.texts(); }
    std::size_t size() const { return _said.lines().size(); }
    void draw();
  };

static ImVec4 _colorForLevel(int level)
{
  switch(level) {
  case Ui::Backend::Error: return ImVec4(0.90f, 0.30f, 0.30f, 1.f);
  case Ui::Backend::Warning: return ImVec4(0.95f, 0.75f, 0.25f, 1.f);
  case Ui::Backend::Direct: return ImVec4(0.45f, 0.65f, 1.00f, 1.f);
  default: return ImGui::GetStyleColorVec4(ImGuiCol_Text);
  }
}

void console::draw()
{
  // the filter, Save, Clear, Copy, Autoscroll
  float side = ImGui::GetFrameHeight();
  ImGui::Dummy(ImVec2(side, side));
  imguiGlyph(Ui::Console::filterGlyph(), ImGui::GetItemRectMin(),
             ImGui::GetItemRectMax(), ImGui::GetColorU32(ImGuiCol_Text));
  ImGui::SameLine(0.f, 2.f);
  ImGui::SetNextItemWidth(15.f * ImGui::GetFontSize());
  if(ImGui::InputText("##filter", &_filter)) _said.setFilter(_filter);
  if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
    ImGui::SetTooltip("%s", Ui::Console::filterTip());
  ImGui::SameLine();
  if(ImGui::Button(Ui::Console::saveLabel()) && imguiSources().saveMessages)
    imguiLater(imguiSources().saveMessages);
  if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
    ImGui::SetTooltip("%s", Ui::Console::saveTip());
  ImGui::SameLine();
  if(ImGui::Button(Ui::Console::clearLabel())) clear();
  if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
    ImGui::SetTooltip("%s", Ui::Console::clearTip());
  ImGui::SameLine();
  if(ImGui::Button("Copy")) {
    std::string all;
    for(const Ui::Console::Line &l : _said.lines()) {
      all += l.text;
      all += "\n";
    }
    ImGui::SetClipboardText(all.c_str());
  }
  ImGui::SameLine();
  bool follow = _said.autoScroll();
  if(ImGui::Checkbox(Ui::Console::autoScrollLabel(), &follow)) {
    _said.setAutoScroll(follow);
    if(follow) _scrollToBottom = true;
  }
  ImGui::Separator();

  if(ImGui::BeginChild("##messages", ImVec2(0, 0), ImGuiChildFlags_None,
                       ImGuiWindowFlags_HorizontalScrollbar)) {
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));
    for(const Ui::Console::Line *l : _said.shown()) {
      ImGui::PushStyleColor(ImGuiCol_Text, _colorForLevel(l->level));
      ImGui::TextUnformatted(l->text.c_str());
      ImGui::PopStyleColor();
    }
    ImGui::PopStyleVar();
    if(_scrollToBottom) {
      ImGui::SetScrollHereY(1.f);
      _scrollToBottom = false;
    }
  }
  ImGui::EndChild();
}


  // --- the main window

class mainWindow {
private:
  static mainWindow *_instance;
  static std::string _openedThroughMacFinder;
  static bool _finishedProcessingCommandLine;
  static std::atomic<int> _locked;

  GLFWwindow *_window;
  // check() is called from deep inside the mesher
  bool _inFrame;
  double _lastRefresh;
  // how many more frames to draw whatever happens: sixty a second is too often
  // when nothing moves
  int _frames;
  bool _keepDrawing;
  console *_console;

  // only what is written into the 3D view is ours
  std::string _statusGl;

  bool _showConsole;


  // see _applyStyle()
  float _uiScale;
  float _uiScaleOverride;
  // what is left once the framebuffer scale of the backend is taken out
  float _styleScale;

  std::vector<std::string> _awakeActions;
  std::mutex _awakeMutex;

  // the frame is still pumped, the rest of the interface disabled
  int _modalDepth;

  // frames are not re-entrant: an action opening a blocking dialog or a
  // selection is run at the beginning of the next frame
  std::vector<std::function<void()> > _pendingActions;
  void _runPendingActions();

  struct modalState {
    bool active;
    bool isInput;
    bool done;
    std::string question;
    std::string choices[3];
    int answer;
    char buffer[1024];
    modalState() : active(false), isInput(false), done(false), answer(0)
    {
      buffer[0] = '\0';
    }
  };
  modalState _modal;
  void _drawModal();
  void _pumpModal();

  fileChooserImGui *_browser;

  void _applyStyle(float scale);
  float _framebufferScale() const;
  static bool _detachablePanels();
  bool _reportedDetachable;
  std::string _fontFile;
  // the line of the font over its em, see _lineOverEm
  float _fontLine = 1.f;
  void _handleShortcuts();

  void _buildDockSpace(int &sceneX, int &sceneY, int &sceneW, int &sceneH);
  void _drawPanels(int &sceneX, int &sceneY, int &sceneW, int &sceneH);
  void _drawStatusBar();
  // what "Zoom" and "Enter Full Screen" restore
  void _windowMinimize();
  void _windowZoom();
  void _windowFullScreen();
  bool _zoomed, _fullscreen;
  int _savedX, _savedY, _savedW, _savedH;
  void _processAwakeActions();

public:
  mainWindow(int argc, char **argv, bool quitShouldExit);
  ~mainWindow();

  static mainWindow *instance(int argc = 0, char **argv = nullptr,
                             bool quitShouldExit = true);
  static bool available() { return _instance != nullptr; }
  static void destroy();

  static void lock() { _locked++; }
  static void unlock() { _locked--; }
  static int locked() { return _locked; }

  static void setOpenedThroughMacFinder(const std::string &name)
  {
    _openedThroughMacFinder = name;
  }
  static std::string getOpenedThroughMacFinder()
  {
    return _openedThroughMacFinder;
  }
  static void setFinishedProcessingCommandLine()
  {
    _finishedProcessingCommandLine = true;
  }
  static bool getFinishedProcessingCommandLine()
  {
    return _finishedProcessingCommandLine;
  }

  void frame();
  int runLoop();
  static void wake();
  // rateLimited: at most once every 1 / General.GuiRefreshRate seconds
  void check(bool rateLimited);
  bool ready();
  // at most time seconds if time > 0
  void wait(bool force);
  void wait(double time, bool force);

  // what cannot happen inside a frame has to be posted
  bool inFrame() const { return _inFrame; }
  // run outside of the frame: what menu items and buttons must use
  void postAction(const std::function<void()> &action)
  {
    _pendingActions.push_back(action);
  }
  void requestFrame();
  void requestRedraw();
  // the one part that is not a described form
  void showConsole(bool show) { _showConsole = show; }
  bool consoleVisible() const { return _showConsole; }

  float uiScale() const { return _uiScale; }
  float styleScale() const { return _styleScale; }
  bool modal() const { return _modalDepth > 0; }
  void applyStyle();

  void windowAction(const std::string &what);

  console *messages() { return _console; }
  GLFWwindow *glfwWindow() { return _window; }
  void addMessage(const std::string &msg, int level);
  void setGraphicTitle(const std::string &title);

  bool inputDialog(const std::string &question, std::string &value);
  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two);

  // mode 0 opens, 1 saves; from an action posted with postAction()
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<fileChooserImGui::format> &formats,
                  std::string &fileName, int *chosenFormat);
};

mainWindow *mainWindow::_instance = nullptr;
std::string mainWindow::_openedThroughMacFinder = "";
bool mainWindow::_finishedProcessingCommandLine = false;
std::atomic<int> mainWindow::_locked(0);

// while probing the windowing systems a failure must not be reported:
// imguiReport(imguiError) makes the public API throw
static bool _glfwProbing = false;

static std::string _glfwProbeError;

static void _glfwErrorCallback(int error, const char *description)
{
  if(_glfwProbing) {
    imguiReport(imguiDebug, "GLFW: %s (error %d)", description, error);
    _glfwProbeError = description;
  }
  else
    imguiReport(imguiError, "GLFW error %d: %s", error, description);
}

static void _glfwDropCallback(GLFWwindow *window, int count, const char **paths)
{
  std::vector<std::string> said;
  for(int i = 0; i < count; i++) said.push_back(paths[i]);
  _dropped(said);
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
    imguiReport(imguiWarning, "Unknown GMSH_GUI_PLATFORM '%s': expected 'wayland', 'x11' or "
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
        imguiReport(imguiInfo, "Using the %s backend for the graphical interface",
                  platforms[i].name);
      return true;
    }
    if(i + 1 < num)
      imguiReport(imguiInfo, "Could not initialize the %s backend, trying %s",
                platforms[i].name, platforms[i + 1].name);
  }
  _glfwProbing = false;

  imguiReport(imguiError, "Could not initialize GLFW: no graphical interface available");
  return false;
}

mainWindow::mainWindow(int argc, char **argv, bool quitShouldExit)
  : _window(nullptr), _inFrame(false),
    _frames(3), _keepDrawing(false),
    _lastRefresh(0.), _console(nullptr),
    _showConsole(true),
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
    imguiReport(imguiError, "Could not create a window: no graphical interface available");
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(_window);
  glfwSwapInterval(1);
  // where the options say, where the windowing system lets it be put
  if(glfwGetPlatform() != GLFW_PLATFORM_WAYLAND &&
     (set.sceneX > 0 || set.sceneY > 0))
    glfwSetWindowPos(_window, set.sceneX, set.sceneY);

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
      imguiReport(imguiWarning, "Ignoring GMSH_GUI_SCALE='%s': expected a factor between "
                   "0.1 and 10", env);
  }
  _fontFile = imguiLoadFont(_fontLine);
  applyStyle();

  ImGui_ImplGlfw_InitForOpenGL(_window, true);
  ImGui_ImplOpenGL2_Init();

  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);

  _claimThread();
  _console = new console();
  _browser = new fileChooserImGui();
  if(imguiSources().settings().detachedTree) imguiDetachTree(true);
  // the scene, its host and its first view
  imguiSceneStart(_window);

  _instance = this;

  // messages reach the console only once _instance is set: what the interface
  // says about its start-up is said here
  switch(glfwGetPlatform()) {
  case GLFW_PLATFORM_WAYLAND: imguiReport(imguiInfo, "Running natively on Wayland"); break;
  case GLFW_PLATFORM_X11:
    imguiReport(imguiInfo, "Running on X11");
    // GLFW loads the Wayland client libraries with dlopen(): a session missing
    // them lands on XWayland silently
    {
    const char *forced = getenv("GMSH_GUI_PLATFORM");
    if(getenv("WAYLAND_DISPLAY") && !(forced && !strcmp(forced, "x11"))) {
      imguiReport(imguiWarning, "This is a Wayland session, but the native Wayland backend "
                   "could not be used%s%s",
                   _glfwProbeError.size() ? ": " : "",
                   _glfwProbeError.size() ? _glfwProbeError.c_str() : "");
      imguiReport(imguiWarning, "Gmsh is therefore going through XWayland; make sure "
                   "libwayland-client, libxkbcommon and libdecor are reachable "
                   "by the dynamic loader (LD_LIBRARY_PATH) to get a native "
                   "window");
    }
    }
    break;
  default: break;
  }
  imguiReport(imguiInfo, "Scaling the interface by %g (override it with the GMSH_GUI_SCALE "
            "environment variable)", _uiScale);
  if(_fontFile.size())
    imguiReport(imguiInfo, "Interface font: %s", _fontFile.c_str());
  else
    imguiReport(imguiInfo, "Interface font: the one embedded in Dear ImGui (no TrueType "
              "font found; set GMSH_GUI_FONT to choose one)");
}

mainWindow::~mainWindow()
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

mainWindow *mainWindow::instance(int argc, char **argv, bool quitShouldExit)
{
  if(!_instance) {
    mainWindow *w = new mainWindow(argc, argv, quitShouldExit);
    if(!w->_window) { // creation failed
      delete w;
      _instance = nullptr;
      return nullptr;
    }
  }
  return _instance;
}

void mainWindow::destroy()
{
  if(!_instance) return;
  mainWindow *w = _instance;
  _instance = nullptr;
  delete w;
}

void mainWindow::requestFrame()
{
  // a few frames rather than one: what changed often takes another to settle;
  // the empty event wakes the loop, from another thread too
  _frames = 3;
  if(_window) glfwPostEmptyEvent();
}

void mainWindow::requestRedraw()
{
  requestFrame();
  imguiSceneRedraw();
}

void mainWindow::addMessage(const std::string &msg, int level)
{
  if(_console) _console->add(msg, level);
  // a message from a mesher with nobody touching the interface would wait for
  // the next frame
  requestFrame();
}

void mainWindow::setGraphicTitle(const std::string &title)
{
  if(!_window) return;
  std::string t = title.empty() ? "Gmsh" : title;
  glfwSetWindowTitle(_window, t.c_str());
}

// the GLFW backend fills io.DisplayFramebufferScale on Wayland only; on X11 and
// Win32 the scaling is ours; reproduced here since it is only set once the
// first frame starts
float mainWindow::_framebufferScale() const
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
bool mainWindow::_detachablePanels()
{
  return (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0;
}

void mainWindow::_applyStyle(float scale)
{
  if(_uiScale > 0.f && fabs(scale - _uiScale) > 0.01f)
    imguiReport(imguiDebug, "Interface scale factor changed from %g to %g", _uiScale, scale);
  _uiScale = scale;
  // a Wayland session would otherwise be scaled twice
  float fb = _framebufferScale();
  _styleScale = (fb > 0.f) ? scale / fb : scale;
  imguiReport(imguiDebug, "Interface scale %g: %g from the framebuffer, %g from Dear ImGui",
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

void mainWindow::applyStyle()
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

void mainWindow::_processAwakeActions()
{
  _drainPosted();
}

void mainWindow::_buildDockSpace(int &sceneX, int &sceneY, int &sceneW,
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
      imguiSetTreeHome(left);
    }
  }

  // the tree attached again where it was, left of the scene, its node gone
  // when it was taken out
  if(imguiTreeNeedsHome()) {
    if(ImGuiDockNode *central = ImGui::DockBuilderGetCentralNode(rootId)) {
      ImGuiID centre = central->ID;
      float wide = std::max(1.f, central->Size.x);
      float ratio = std::min(.5f, std::max(.1f, 300.f / wide));
      ImGuiID left = ImGui::DockBuilderSplitNode(centre, ImGuiDir_Left, ratio,
                                                 nullptr, &centre);
      ImGui::DockBuilderDockWindow("Modules", left);
      ImGui::DockBuilderFinish(rootId);
      imguiSetTreeHomeNow(left);
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

void mainWindow::_runPendingActions()
{
  if(_pendingActions.empty()) return;
  std::vector<std::function<void()> > actions;
  actions.swap(_pendingActions);
  for(auto &a : actions) {
    a();
    if(!_instance) return; // the GUI was destroyed by the action
  }
}

void mainWindow::_drawPanels(int &sceneX, int &sceneY, int &sceneW, int &sceneH)
{
  _buildDockSpace(sceneX, sceneY, sceneW, sceneH);

  if(_showConsole) {
    if(ImGui::Begin("Messages", &_showConsole)) _console->draw();
    ImGui::End();
  }

  imguiDrawMenuBar();
  imguiDrawTree();
  imguiDrawForms();
  _drawStatusBar();
}

void mainWindow::frame()
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
    _quit();
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
      imguiReport(imguiDebug, "Panels can be dragged out of the main window");
    else
      imguiReport(imguiInfo, "Panels can only be moved inside the main window: this "
                "windowing system does not let an application place its own "
                "windows");
  }

  _inFrame = false;
}

void mainWindow::_drawModal()
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

void mainWindow::_pumpModal()
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

bool mainWindow::inputDialog(const std::string &question, std::string &value)
{
  if(!_window) return false;
  if(_inFrame) {
    // not from within a frame: widgets post their actions through postAction()
    imguiReport(imguiDebug, "Ignoring input dialog requested from within a frame");
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

int mainWindow::questionDialog(const std::string &question,
                              const std::string &zero, const std::string &one,
                              const std::string &two)
{
  if(!_window) return 0;
  if(_inFrame) {
    imguiReport(imguiDebug, "Ignoring question dialog requested from within a frame");
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

bool mainWindow::fileDialog(int mode, const std::string &title,
                           const std::vector<fileChooserImGui::format> &formats,
                           std::string &fileName, int *chosenFormat)
{
  if(!_window) return false;
  if(_inFrame) {
    imguiReport(imguiDebug, "Ignoring file dialog requested from within a frame");
    return false;
  }
  _browser->begin(mode ? fileChooserImGui::Save : fileChooserImGui::Open, title, formats,
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

void mainWindow::check(bool rateLimited)
{
  // GLFW and OpenGL are only valid on the thread that created the window
  if(!_onThread() || _locked > 0) return;
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

bool mainWindow::ready()
{
  return _window && !_inFrame;
}

void mainWindow::wait(bool force)
{
  if(!force && (!_onThread() || _locked > 0)) return;
  if(!_window) return;
  double next = Scene::nextTimer();
  if(next >= 0.)
    glfwWaitEventsTimeout(next);
  else
    glfwWaitEvents();
  frame();
}

void mainWindow::wait(double time, bool force)
{
  if(!force && (!_onThread() || _locked > 0)) return;
  if(!_window) return;
  if(time > 0.)
    glfwWaitEventsTimeout(time);
  else
    glfwPollEvents();
  frame();
}

int mainWindow::runLoop()
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

void mainWindow::wake()
{
  if(_instance && _instance->_window) glfwPostEmptyEvent();
}


void mainWindow::_drawStatusBar()
{
  const ImGuiViewport *viewport = ImGui::GetMainViewport();
  float height = ImGui::GetFrameHeightWithSpacing();
  // without ImGuiWindowFlags_MenuBar the bar draws empty
  ImGuiWindowFlags flags =
    ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;

  if(ImGui::BeginViewportSideBar("##gmshStatusBar", (ImGuiViewport *)viewport,
                                 ImGuiDir_Down, height, flags)) {
    if(ImGui::BeginMenuBar()) {
      static std::vector<Ui::BarButton> bar;
      bar = imguiSources().barButtons();
      for(std::size_t i = 0; i < bar.size(); i++) {
        const Ui::BarButton &b = bar[i];
        if(b.gapBefore) ImGui::Separator();
        bool enabled = b.enabled ? b.enabled() : true;
        ImGui::BeginDisabled(!enabled);
        bool on = b.on && b.on();
        std::string label = (on && b.labelOn.size()) ? b.labelOn : b.label;
        int painted = 0;
        if(b.alert && b.alert()) {
          ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(.62f, .13f, .13f, 1.f));
          ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(.98f, .94f, .94f, 1.f));
          painted = 2;
        }
        else if(on && b.onColour) {
          Ui::Colour c = b.onColour();
          ImGui::PushStyleColor(ImGuiCol_Button,
                                ImVec4(c.r / 255.f, c.g / 255.f, c.b / 255.f,
                                       1.f));
          painted = 1;
        }
        std::string glyph = (on && b.glyphOn.size()) ? b.glyphOn : b.glyph;
        bool pictured = Ui::glyph(glyph) != nullptr;
        ImU32 ink = ImGui::GetColorU32(ImGuiCol_Text);
        ImGui::PushID((int)i);
        if(b.menu) {
          // the picture over a name of blanks as wide as it
          if(ImGui::BeginMenu(pictured ? "   ##m" : label.c_str(), enabled)) {
            static std::vector<Ui::MenuItem> menu;
            menu = b.menu();
            imguiMenu(menu);
            ImGui::EndMenu();
          }
          if(pictured)
            imguiGlyph(glyph, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(),
                       ink);
        }
        else {
          float side = ImGui::GetFrameHeight();
          bool pressed = pictured ? ImGui::Button("##g", ImVec2(side, side)) :
                                    ImGui::Button(label.c_str());
          if(pictured)
            imguiGlyph(glyph, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(),
                       ink);
          if(pressed) {
            std::function<void(bool, bool)> what = b.action;
            bool reverse = ImGui::GetIO().KeyShift;
            bool sync = ImGui::GetIO().KeyCtrl;
            if(what)
              postAction([what, reverse, sync]() { what(reverse, sync); });
          }
        }
        ImGui::PopID();
        if(painted) ImGui::PopStyleColor(painted);
        ImGui::EndDisabled();
        if(b.tooltip.size() &&
           ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal |
                                ImGuiHoveredFlags_AllowWhenDisabled))
          ImGui::SetTooltip("%s", b.tooltip.c_str());
      }

      ImGui::Separator();

      // --- the message and the progress; clicking the whole strip shows or hides the console
      Ui::BarMessage m = imguiSources().barMessage();
      ImVec2 textPos = ImGui::GetCursorScreenPos();
      float avail = ImGui::GetContentRegionAvail().x;
      if(m.running) avail -= 200.f * _styleScale;
      if(avail < 1.f) avail = 1.f;
      if(ImGui::InvisibleButton("##statusMessage",
                                ImVec2(avail, ImGui::GetFrameHeight())))
        postAction(imguiSources().barPressed);
      if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("%s", imguiSources().barTooltip().c_str());
      ImGui::SetCursorScreenPos(textPos);

      if(m.weight == Ui::MessageError)
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.90f, 0.30f, 0.30f, 1.f));
      else if(m.weight == Ui::MessageWarning)
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.95f, 0.75f, 0.25f, 1.f));
      else
        ImGui::PushStyleColor(ImGuiCol_Text,
                              ImGui::GetStyleColorVec4(ImGuiCol_Text));
      ImGui::AlignTextToFramePadding();
      ImGui::TextUnformatted(m.text.c_str());
      ImGui::PopStyleColor();

      if(m.running) {
        float w = 200.f * _styleScale;
        ImGui::SameLine(ImGui::GetWindowWidth() - w -
                        ImGui::GetStyle().ItemSpacing.x);
        ImGui::ProgressBar((float)m.fraction, ImVec2(w, 0.f),
                           m.progressText.c_str());
      }
      ImGui::EndMenuBar();
    }
  }
  ImGui::End();
}



  // as Ui::Shortcut says it, 0 for none; Dear ImGui does not say which key went
  // down: each is asked
  int _uiKey()
  {
    for(int k = ImGuiKey_NamedKey_BEGIN; k < ImGuiKey_NamedKey_END; k++) {
      ImGuiKey key = (ImGuiKey)k;
      if(!ImGui::IsKeyPressed(key, false)) continue;
      if(key >= ImGuiKey_A && key <= ImGuiKey_Z) return 'A' + (key - ImGuiKey_A);
      if(key >= ImGuiKey_0 && key <= ImGuiKey_9) return '0' + (key - ImGuiKey_0);
      if(key >= ImGuiKey_Keypad0 && key <= ImGuiKey_Keypad9)
        return '0' + (key - ImGuiKey_Keypad0);
      if(key >= ImGuiKey_F1 && key <= ImGuiKey_F12)
        return Ui::KeyF1 + (key - ImGuiKey_F1);
      switch(key) {
      case ImGuiKey_LeftArrow: return Ui::KeyLeft;
      case ImGuiKey_RightArrow: return Ui::KeyRight;
      case ImGuiKey_UpArrow: return Ui::KeyUp;
      case ImGuiKey_DownArrow: return Ui::KeyDown;
      case ImGuiKey_Escape: return Ui::KeyEscape;
      case ImGuiKey_Home: return Ui::KeyHome;
      case ImGuiKey_PageUp: return Ui::KeyPageUp;
      case ImGuiKey_PageDown: return Ui::KeyPageDown;
      case ImGuiKey_Delete: return Ui::KeyDelete;
      case ImGuiKey_Minus:
      case ImGuiKey_KeypadSubtract: return '-';
      default: break;
      }
    }
    return 0;
  }


void mainWindow::_handleShortcuts()
{
  ImGuiIO &io = ImGui::GetIO();
  // WantTextInput, not WantCaptureKeyboard: with keyboard navigation on, the
  // latter is true as soon as any panel has the focus
  if(io.WantTextInput || _modalDepth > 0) return;

  int key = _uiKey();
  unsigned mods = 0;
  if(io.KeyCtrl || io.KeySuper) mods |= Ui::ModCommand;
  if(io.KeyShift) mods |= Ui::ModShift;
  if(io.KeyAlt) mods |= Ui::ModAlt;
  // a digit or a mark is the one typed, whatever key gives it on this
  // keyboard (Shift, on a French one)
  for(ImWchar c : io.InputQueueCharacters)
    if(c > ' ' && c < 127 && !isalpha((int)c)) {
      key = c;
      mods &= ~Ui::ModShift;
    }
  if(!key) return;

  if(key == Ui::KeyEscape && _fullscreen) {
    _windowFullScreen();
    return;
  }

  if(!imguiSources().keys) return;
  // queued with postAction(): it may open a dialog or start a picking
  for(const Ui::KeyBinding &k : imguiSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    if(k.action) postAction(k.action);
    if(k.spent) break;
  }
}


// --- the "Window" menu acts on the GLFW window of the application

void mainWindow::_windowMinimize() { glfwIconifyWindow(_window); }

void mainWindow::_windowZoom()
{
  if(_fullscreen) return;
  if(!_zoomed) {
    glfwMaximizeWindow(_window);
    _zoomed = true;
  }
  else {
    glfwRestoreWindow(_window);
    _zoomed = false;
  }
}

void mainWindow::_windowFullScreen()
{
  if(!_fullscreen) {
    glfwGetWindowPos(_window, &_savedX, &_savedY);
    glfwGetWindowSize(_window, &_savedW, &_savedH);
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    if(!monitor) {
      imguiReport(imguiError, "Cannot go full screen: no monitor found");
      return;
    }
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if(!mode) {
      imguiReport(imguiError, "Cannot go full screen: no video mode found");
      return;
    }
    glfwSetWindowMonitor(_window, monitor, 0, 0, mode->width, mode->height,
                         mode->refreshRate);
    _fullscreen = true;
  }
  else {
    if(_savedW <= 0 || _savedH <= 0) {
      _savedX = _savedY = 100;
      _savedW = 800;
      _savedH = 600;
    }
    glfwSetWindowMonitor(_window, nullptr, _savedX, _savedY, _savedW, _savedH,
                         GLFW_DONT_CARE);
    _fullscreen = false;
  }
}


void mainWindow::windowAction(const std::string &what)
{
  if(what == "minimize")
    _windowMinimize();
  else if(what == "zoom")
    _windowZoom();
  else if(what == "fullscreen")
    _windowFullScreen();
  else if(what == "show_hide_tree")
    imguiShowTree(!imguiTreeShown());
  else if(what == "attach_detach")
    imguiDetachTree(!imguiTreeDetached());
  else
    imguiReport(imguiError, "Unknown window action '%s'", what.c_str());
}


  // --- the backend

  class backendImGui : public Ui::Backend {
  public:
    std::string name() override
    {
      std::string s = "Dear ImGui ";
      s += IMGUI_VERSION;
      s += ", GLFW ";
      s += glfwGetVersionString();
      return s;
    }

    void setSources(const Sources &sources) override
    {
      _sources = sources;
    }

    const Sources &sources() const { return _sources; }
    const Host &host() const { return _host; }

    void setHost(const Host &host) override
    {
      _host = host;
    }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(mainWindow::available()) return true;
      mainWindow::instance(argc, argv, quitShouldExit);
      return mainWindow::available();
    }

    void destroy() override { mainWindow::destroy(); }

    int runLoop() override
    {
      return mainWindow::available() ? mainWindow::instance()->runLoop() : 0;
    }

    void check(bool rateLimited) override
    {
      if(mainWindow::available()) mainWindow::instance()->check(rateLimited);
    }

    bool ready() override
    {
      return mainWindow::available() && mainWindow::instance()->ready();
    }

    void wait(double seconds, bool force) override
    {
      if(!mainWindow::available()) return;
      if(seconds < 0.)
        mainWindow::instance()->wait(force);
      else
        mainWindow::instance()->wait(seconds, force);
    }

    void lock() override { mainWindow::lock(); }
    void unlock() override { mainWindow::unlock(); }
    int locked() override { return mainWindow::locked(); }

    void postFromThread(const std::function<void()> &what) override
    {
      {
        std::lock_guard<std::mutex> lock(_mutex);
        _posted.push_back(what);
      }
      mainWindow::wake();
    }

    void post(const std::function<void()> &what) override
    {
      // a frame is not re-entrant: what opens a window waits for it to be over
      mainWindow *a = mainWindow::instance();
      if(a && a->inFrame())
        a->postAction(what);
      else
        what();
    }

    void copyText(const std::string &text) override
    {
      ImGui::SetClipboardText(text.c_str());
    }

    void beep() override
    {
      fputc('\a', stderr);
      fflush(stderr);
    }

    // --- messages, the bar, and the questions that stop everything

    void addMessage(const std::string &text, int level) override
    {
      if(mainWindow::available())
        mainWindow::instance()->addMessage(text, level);
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(mainWindow::available() && mainWindow::instance()->messages())
        mainWindow::instance()->messages()->lines(lines);
    }

    void refreshBar() override
    {
      // the bar is drawn at every frame: only a frame to ask for
      if(mainWindow::available()) mainWindow::instance()->requestFrame();
    }
    void optionChanged(const std::string &) override
    {
      if(mainWindow::available()) mainWindow::instance()->requestRedraw();
    }

    int numWindows() override { return mainWindow::available() ? 1 : 0; }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(mainWindow::available())
        mainWindow::instance()->setGraphicTitle(title);
    }

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      if(!mainWindow::available()) return false;
      std::string ask = question;
      if(hint.size()) ask += "\n" + hint;
      if(readOnly) {
        mainWindow::instance()->inputDialog(ask + "\n\n" + value, value);
        return false;
      }
      return mainWindow::instance()->inputDialog(ask, value);
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      if(!mainWindow::available()) return 0;
      return mainWindow::instance()->questionDialog(question, zero, one, two);
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      if(!mainWindow::available()) return false;
      std::string fileName = names.empty() ? "" : names[0];
      std::vector<fileChooserImGui::format> say;
      for(const auto &f : formats) {
        fileChooserImGui::format one;
        one.name = f.name;
        one.pattern = f.pattern;
        say.push_back(one);
      }
      if(!mainWindow::instance()->fileDialog(mode == Create ? 1 : 0, title, say,
                                            fileName, chosenFormat))
        return false;
      names.assign(1, fileName);
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      if(mainWindow::available()) mainWindow::instance()->applyStyle();
    }

    // --- the things that are described: drawn at every frame, so what is here is what to show, and a request for a frame

    void showForm(const Ui::Form &form, bool show) override
    {
      imguiShowForm(form, show);
    }

    bool formVisible(const Ui::Form &form) override
    {
      return imguiFormVisible(form);
    }

    std::string formPane(const Ui::Form &form) override
    {
      return imguiFormPane(form);
    }

    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      imguiSetFormPane(form, pane);
    }

    void dropForm(const Ui::Form &form) override
    {
      imguiDropForm(form);
    }

    void showConsole(bool show) override
    {
      if(mainWindow::available()) mainWindow::instance()->showConsole(show);
    }

    bool consoleVisible() override
    {
      return mainWindow::available() &&
             mainWindow::instance()->consoleVisible();
    }

    void refreshTree(bool rebuild) override
    {
      if(mainWindow::available()) mainWindow::instance()->requestFrame();
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      imguiOpenTreeItem(name, open);
    }

    bool treeItemOpen(const std::string &name) override
    {
      return imguiTreeItemOpen(name);
    }

    void showTree() override
    {
      imguiShowTree(true);
    }

    void refreshMenus() override
    {
      if(mainWindow::available()) mainWindow::instance()->requestFrame();
    }

    void setSolverButtonMode(const std::string &button0,
                             const std::string &button1) override
    {
      imguiRequestFrame();
    }

    void windowAction(const std::string &what) override
    {
      if(!mainWindow::available()) return;
      mainWindow *a = mainWindow::instance();
      if(what == "new")
        imguiSceneNewWindow();
      else
        a->windowAction(what);
    }

    bool supports(const std::string &what) override
    {
      // the panels are not windows of their own; no image clipboard in GLFW
      if(what == "front" || what == "copy" || what == "3m") return false;
      return true;
    }

    void detachTree(bool detached) override { imguiDetachTree(detached); }

    Layout windowLayout() override
    {
      Layout l;
      GLFWwindow *main = mainWindow::available() ?
                           mainWindow::instance()->glfwWindow() :
                           nullptr;
      if(main && glfwGetPlatform() != GLFW_PLATFORM_WAYLAND)
        glfwGetWindowPos(main, &l.sceneX, &l.sceneY);
      imguiFormPosition(l.dialogX, l.dialogY);
      l.treeDetached = imguiTreeDetached() ? 1 : 0;
      imguiTreeFloating(l.treeX, l.treeY, l.treeHeight);
      return l;
    }

    void dropped(const std::vector<std::string> &paths)
    {
      if(_host.filesDropped) _host.filesDropped(paths);
    }

    void drain()
    {
      std::vector<std::function<void()> > work;
      {
        std::lock_guard<std::mutex> lock(_mutex);
        work.swap(_posted);
      }
      for(auto &w : work) w();
    }

  private:
    Sources _sources;
    Host _host;
    std::mutex _mutex;
    std::vector<std::function<void()> > _posted;
  };

  backendImGui *_the = nullptr;

  void _drainPosted()
  {
    if(_the) _the->drain();
  }

  void _dropped(const std::vector<std::string> &paths)
  {
    if(_the) _the->dropped(paths);
  }

} // namespace

const Ui::Backend::Sources &imguiSources()
{
  // before the interface was given anything, the settings are their defaults
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _the->sources() : none;
}

const Ui::Backend::Host &imguiHost()
{
  static const Ui::Backend::Host none;
  return _the ? _the->host() : none;
}

void imguiReport(int level, const char *format, ...)
{
  const Ui::Backend::Host &host = imguiHost();
  const std::function<void(const std::string &)> &say =
    level == imguiError   ? host.error :
    level == imguiWarning ? host.warning :
    level == imguiInfo    ? host.info :
                            host.debug;
  if(!say) return;
  char text[2048];
  va_list args;
  va_start(args, format);
  vsnprintf(text, sizeof(text), format, args);
  va_end(args);
  say(text);
}

void imguiLater(const std::function<void()> &what)
{
  if(mainWindow::available()) mainWindow::instance()->postAction(what);
}

bool imguiPlacesWindows()
{
  // the positions are on the screen once panels can be windows of their own;
  // Wayland does not say where a window is
  return glfwGetPlatform() != GLFW_PLATFORM_WAYLAND &&
         ImGui::GetCurrentContext() &&
         (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0;
}

bool imguiInFrame()
{
  return mainWindow::available() && mainWindow::instance()->inFrame();
}

void imguiRequestFrame()
{
  if(mainWindow::available()) mainWindow::instance()->requestFrame();
}

void imguiRequestRedraw()
{
  if(mainWindow::available()) mainWindow::instance()->requestRedraw();
}

void imguiWake() { mainWindow::wake(); }

float imguiUiScale()
{
  return mainWindow::available() ? mainWindow::instance()->uiScale() : 1.f;
}

float imguiStyleScale()
{
  return mainWindow::available() ? mainWindow::instance()->styleScale() : 1.f;
}

bool imguiModal()
{
  return mainWindow::available() && mainWindow::instance()->modal();
}

// made once
namespace {
  struct offeringImGui {
    offeringImGui()
    {
      Ui::offer("imgui", []() -> Ui::Backend * {
        if(!_the) _the = new backendImGui();
        return _the;
      });
    }
  };
  offeringImGui _offeringImGui;
}
