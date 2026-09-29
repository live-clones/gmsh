// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include "GmshConfig.h"

#include <atomic>
#include <functional>
#include <mutex>
#include <map>
#include <string>
#include <vector>

#include "Form.h"
#include "fileBrowser.h"
#include "sceneView.h"

struct GLFWwindow;
struct ImFont;
class messageConsole;
class fileBrowser;
class drawContext;

// the main window: the GLFW window and its context, the Dear ImGui context, and
// everything drawn inside. One frame(): poll the events, build the widgets,
// draw the views of the scene that asked for it into their framebuffers, put
// them in the central node, submit the draw lists on top

// the scene (SceneImGui.cpp): its views on GuiPanes, started with the main
// window; placed in the central node, or alone in it in full screen
void imguiSceneStart(GLFWwindow *main);
void imguiSceneStop();
void imguiScenePlace(int x, int y, int w, int h, bool fullscreen);
// the pointer, unless outside the scene, from the state of Dear ImGui
void imguiScenePointer(bool outside);
// the views asked for drawn, all of them put on the window
void imguiSceneDraw();
// the graphic windows of their own
void imguiSceneWindows();
void imguiSceneRedraw();
sceneView *imguiSceneCurrent();
void imguiSceneSplit(char how, double ratio);
void imguiSceneNewWindow();

// from another thread, drained by the frame loop
void drainPostedFromThread();
void imguiDropped(const std::vector<std::string> &paths);
// the bold face of the interface font, for the headings; null without one
ImFont *imguiBoldFont();
// the slanted one, for the words of prose that are; null without one
ImFont *imguiItalicFont();
// the one of fixed width, for lines of code; null without one
ImFont *imguiFixedFont();

class appWindow {
private:
  static appWindow *_instance;
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
  messageConsole *_console;

  // only what is written into the 3D view is ours
  std::string _statusGl;

  bool _showConsole;
  bool _showModules;
  // a map, since how many there are is nobody's to count
  struct dialogState {
    // the key of the saved layout
    std::string name;
    const Ui::Form *form = nullptr;
    // whether it has just been asked for and must be brought forward
    bool show = false, focus = false;
    // the size given to the window, so that it is given again only when what
    // it holds changes
    bool sized = false;
    float width = 0.f, height = 0.f;
    // so that it sits still from one category to the next
    float widest = 0.f;
    // the pane showing, by its label, and whether it has just been asked
    // for: forced until it has come up, not after, or it would fight the tab
    // the user picks
    std::string pane;
    bool forcePane = false;
  };
  std::map<const Ui::Form *, dialogState> _dialogs;
  std::string _solverButton0, _solverButton1;

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

  fileBrowser *_browser;

  void _drawMenuBar();
  void _applyStyle(float scale);
  float _framebufferScale() const;
  static bool _detachablePanels();
  bool _reportedDetachable;
  void _loadFont();
  std::string _fontFile;
  // the line of the font over its em, see _lineOverEm
  float _fontLine = 1.f;
  void _drawModulesPanel();
  void _walkModules(const std::string &path, int depth);
  // by path, "0Modules/Geometry/..."; a request waits until the branch is
  // drawn, so that a chain unfolds in one go
  std::map<std::string, bool> _treeWanted;
  // what each branch was the last time it was drawn
  std::map<std::string, bool> _treeOpen;

public:
  void openTreeItem(const std::string &name) { _treeWanted[name] = true; }
  void closeTreeItem(const std::string &name) { _treeWanted[name] = false; }
  bool treeItemOpen(const std::string &name) const
  {
    auto wanted = _treeWanted.find(name);
    if(wanted != _treeWanted.end()) return wanted->second;
    auto open = _treeOpen.find(name);
    return open != _treeOpen.end() && open->second;
  }

private:
  void _drawDialog(const Ui::Form *which);
  dialogState &_dialog(const Ui::Form &which);
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
  appWindow(int argc, char **argv, bool quitShouldExit);
  ~appWindow();

  static appWindow *instance(int argc = 0, char **argv = nullptr,
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
  void showModulesPanel() { _showModules = true; }

  float uiScale() const { return _uiScale; }
  void applyStyle();

  void windowAction(const std::string &what);

  messageConsole *console() { return _console; }
  void addMessage(const std::string &msg, int level);
  void setGraphicTitle(const std::string &title);

  bool inputDialog(const std::string &question, std::string &value);
  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two);
  void setSolverButtonMode(const std::string &b0, const std::string &b1)
  {
    _solverButton0 = b0;
    _solverButton1 = b1;
  }

  // mode 0 opens, 1 saves; from an action posted with postAction()
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<fileBrowser::format> &formats,
                  std::string &fileName, int *chosenFormat);
  // see Ui::Backend::showForm(); what a dialog is made of is asked at every
  // frame
  void showDialog(const Ui::Form &which);
  void hideDialog(const Ui::Form &which);
  void dropDialog(const Ui::Form &which);
  bool dialogVisible(const Ui::Form &which) const;
  std::string dialogPane(const Ui::Form &which) const;
  void setDialogPane(const Ui::Form &which, const std::string &pane);
};

#endif
