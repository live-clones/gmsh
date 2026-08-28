// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <atomic>
#include <functional>
#include <mutex>
#include <map>
#include <string>
#include <vector>

#include "GuiActions.h"
#include "GuiMenus.h"
#include "GuiDialogs.h"
#include "scenePane.h"

struct GLFWwindow;
class messageConsole;
class fileBrowser;
class drawContext;

// The main window of the Dear ImGui interface: it owns the GLFW window and its
// OpenGL context, the Dear ImGui context, and everything drawn inside. This is
// the counterpart of FlGui + mainWindow + graphicWindow.
//
// One frame() does, in this order: poll the events, build the Dear ImGui
// widgets, render the 3D scene into the central node of the dock space, then
// submit the Dear ImGui draw lists on top. The scene is therefore drawn
// directly into the main framebuffer, with no intermediate frame buffer object,
// which keeps the whole rendering path in plain OpenGL 1.x + GLU, exactly as in
// the FLTK backend.

class appWindow {
private:
  static appWindow *_instance;
  static std::string _openedThroughMacFinder;
  static bool _finishedProcessingCommandLine;
  static std::atomic<int> _locked;

  GLFWwindow *_window;
  bool _quitShouldExit;
  // guards against re-entering frame(), which can happen because check() is
  // called from deep inside the mesher
  bool _inFrame;
  double _lastRefresh;

  // The graphic panes tile the central node of the dock space. _panes is the
  // flat list, in creation order, which is what SetCurrentWindow of the .geo
  // files and gmsh::fltk::setCurrentWindow index into; _paneRoot is the binary
  // tree that says how they share the rectangle.
  std::vector<scenePane *> _panes;
  struct paneNode {
    scenePane *pane; // non-null for a leaf
    char split; // 'h' (side by side) or 'v' (one above the other)
    double ratio;
    paneNode *child[2];
    paneNode(scenePane *p)
      : pane(p), split(0), ratio(0.5)
    {
      child[0] = child[1] = nullptr;
    }
  };
  paneNode *_paneRoot;
  scenePane *_currentPane;

  // The extra graphic windows of "Window > New Window". Each one is a real
  // window of its own -- a GLFW window sharing the OpenGL context of the main
  // one, with no Dear ImGui inside, just the scene. That is what makes them
  // work everywhere, Wayland included: an application may open as many toplevel
  // windows as it likes there, it simply may not place them, which a window
  // that carries nothing but a 3D view does not need to do.
  //
  // Their pane is in _panes like any other, so the API and the status bar count
  // it, but it is not in _paneRoot: it is not tiled, and Split/Unsplit leave it
  // alone.
public:
  struct extraView {
    GLFWwindow *window;
    scenePane *pane;
    int number;
    // the pointer state of that window, kept between the GLFW callbacks
    paneInput input;
    double lastX, lastY, lastPress;
    bool everMoved;
  };
  // the GLFW callbacks of the extra windows land here
  extraView *findExtraView(GLFWwindow *w);

private:
  std::vector<extraView> _extraViews;
  void _drawExtraViews();
  void _closeExtraView(std::size_t i);
  bool _isTiled(scenePane *p) const;
  // the single view shown while full screen
  scenePane *_fullScreenPane();

  paneNode *_findPaneNode(paneNode *node, scenePane *pane);
  void _layoutPanes(paneNode *node, int x, int y, int w, int h);
  void _deletePaneTree(paneNode *node);
  messageConsole *_console;

  // status bar
  std::string _status, _lastStatus, _statusGl;
  int _statusColor;
  std::string _progressMsg;
  double _progressValue, _progressMin, _progressMax;

  bool _showConsole;
  bool _showModules;
  // the four context dialogs of GuiDialogs.h, and which of them has just been
  // asked for and must be brought forward
  bool _showDialog[Dialog::NumDialogs], _focusDialog[Dialog::NumDialogs];
  // whether it has been given its size since it was last opened
  bool _sizedDialog[Dialog::NumDialogs];
  // the height its rows say it needs, which changes when a dialog is shown
  // another set of panes -- the option window, on another category
  float _estimatedHeight[Dialog::NumDialogs];
  // the pane a dialog has just been asked to show, -1 once it has been
  int _wantedPane[Dialog::NumDialogs];
  // the pane each dialog was showing at the end of the last frame, to tell a
  // tab the user picked from one that came up because it was asked for
  int _lastPane[Dialog::NumDialogs];
  // the FLTK interface has three separate help windows, and so does this one
  bool _showHelpBasic, _showHelpOptions, _showAbout;
  bool _showClassify;
  bool _showOnelabContext;
  int _contextDim, _contextTag, _contextChoice;
  std::string _solverButton0, _solverButton1;

  // scale factor of the display, so that the interface has the same physical
  // size whatever the resolution; see _applyStyle()
  float _uiScale;
  float _uiScaleOverride;
  // the part of _uiScale that Dear ImGui has to apply itself, i.e. what is left
  // once the framebuffer scale of the backend is taken out; see _applyStyle()
  float _styleScale;

  // non-zero while grabbing the pixels of the scene, see beginCapture()
  int _captureW, _captureH;
  bool _captureComposite;

  // actions posted by other threads through awake()
  std::vector<std::string> _awakeActions;
  std::mutex _awakeMutex;

  // a modal dialog is being shown: the frame is still pumped, but the rest of
  // the interface is disabled
  int _modalDepth;

  // Actions triggered by a widget cannot run while the frame is being built:
  // Dear ImGui frames are not re-entrant, so an action that opens a blocking
  // dialog (Msg::GetAnswer()) or an interactive selection would deadlock. They
  // are therefore queued here and run at the beginning of the next frame,
  // outside of NewFrame()/Render().
  std::vector<std::function<void()> > _pendingActions;
  void _runPendingActions();

  // state of the blocking modal dialog currently being shown, if any
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

  // state of the per-format export options dialog
  bool _exportActive, _exportDone, _exportAccepted;
  int _exportFormat;
  std::string _exportFileName;
  void _drawExportDialog();
  void _drawMenuBar();
  void _applyStyle(float scale);
  // how much the backend already enlarges what Dear ImGui draws
  float _framebufferScale() const;
  // whether panels can be dragged out of the main window
  static bool _detachablePanels();
  bool _reportedDetachable;
  // category the options panel opens on, so that the quick access menu can
  // jump straight to the right one
  // the animation runs from the frame loop, see _stepAnimation()
  bool _animating;
  double _animLastStep;
  std::string _tooltip;
  void _drawTooltip();
  void _loadFont();
  // the TrueType file the interface font came from, empty for the built-in one
  std::string _fontFile;
  void _drawModulesPanel();
  void _walkModules(const std::vector<Menu::Item> &items, int depth,
                    const std::string &path);
  // Branches the API has asked to unfold or fold, by the path the FLTK tree
  // names them with ("0Modules/Geometry/..."). A request waits until the
  // branch is actually drawn, so that unfolding a whole chain in one go works
  // whatever was open before.
  std::map<std::string, bool> _treeWanted;

public:
  void openTreeItem(const std::string &name) { _treeWanted[name] = true; }
  void closeTreeItem(const std::string &name) { _treeWanted[name] = false; }

private:
  void _drawDialog(int which);
  void _drawHelpPanel();
  void _drawAboutPanel();
  void _drawClassifyPanel();
  void _drawOnelabContextPanel();
  void _handleShortcuts();

  void _buildDockSpace(int &sceneX, int &sceneY, int &sceneW, int &sceneH);
  void _drawPanels(int &sceneX, int &sceneY, int &sceneW, int &sceneH);
  void _drawStatusBar();
  // "Window" menu: the counterpart of the FLTK window_cb(). The geometry saved
  // here is what "Zoom" and "Enter Full Screen" restore.
  void _windowMinimize();
  void _windowZoom();
  void _windowFullScreen();
  bool _zoomed, _fullscreen;
  int _savedX, _savedY, _savedW, _savedH;
  void _drawQuickAccessMenu();
  void _stepAnimation();
  void _drawScene();
  void _handleInput();
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

  // draw one frame
  void frame();
  // main loop
  int run(const std::string &optionFileName);
  // pump the events, at most once every 1 / General.GuiRefreshRate seconds when
  // rateLimited is set
  void check(bool rateLimited);
  // are there events waiting to be processed?
  bool ready();
  // wait for events (at most time seconds if time > 0), then process them
  void wait(bool force);
  void wait(double time, bool force);
  void awake(const std::string &action);
  // queue an action to be run outside of the Dear ImGui frame; this is what
  // menu items and buttons must use
  void postAction(const std::function<void()> &action)
  {
    _pendingActions.push_back(action);
  }
  // ask for a new frame to be drawn
  void requestRedraw();
  // draw the current pane immediately (used for vector output and for grabbing
  // the pixels of the scene)
  void drawCurrentPane();
  // While capturing, drawCurrentPane() renders the current pane into the
  // bottom-left corner of the frame buffer, at the requested size in pixels,
  // which is where PixelBuffer::fill() reads from. Returns the size that could
  // actually be used: without a frame buffer object the scene cannot be
  // rendered larger than the window.
  void beginCapture(int &width, int &height, bool composite = false);
  void endCapture();

  bool quitShouldExit() const { return _quitShouldExit; }

  // scale factor currently applied to the interface (1 on a standard display,
  // 2 on a "retina" one, 1.5 with a 150% desktop scaling, ...)
  // transient text shown next to the pointer, cleared when set to empty
  void setTooltip(const std::string &text) { _tooltip = text; }

  float uiScale() const { return _uiScale; }
  // rebuild the style: colour scheme and scale factor
  void applyStyle();

  // panes
  scenePane *currentPane() { return _currentPane; }
  void setCurrentPane(scenePane *p);
  void setCurrentPane(int index);
  // split the current pane in two ('h' or 'v'), or bring everything back to a
  // single pane ('u')
  void splitCurrentPane(char how, double ratio);
  // open another graphic window, as "Window > New Window" does in FLTK
  void newGraphicWindow();
  // the panels the menus show and hide, see Gui::Panel
  bool panelVisible(int panel) const;
  void showPanel(int panel, bool show);
  // "minimize", "zoom" or "fullscreen"
  void windowAction(const std::string &what);
  int numPanes() const { return (int)_panes.size(); }
  scenePane *pane(int i);
  drawContext *currentDrawContext();
  void currentPixelSize(int &w, int &h);
  double pixelFactor();

  // messages and status
  messageConsole *console() { return _console; }
  void addMessage(const std::string &msg, int level);
  void setStatus(const std::string &msg, bool graphics);
  void setLastStatus(int color);
  void setProgress(const std::string &msg, double val, double min, double max);
  void setGraphicTitle(const std::string &title);

  // blocking modal dialogs
  bool inputDialog(const std::string &question, std::string &value);
  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two);
  void setSolverButtonMode(const std::string &b0, const std::string &b1)
  {
    _solverButton0 = b0;
    _solverButton1 = b1;
  }

  // show the file chooser and wait for the user; mode is 0 to open an existing
  // file and 1 to save one. Like the other blocking dialogs, this must be
  // called from an action posted with postAction()
  bool fileDialog(int mode, const std::string &title, const std::string &filter,
                  std::string &fileName);
  // ask for the options of the given output format; returns false if the user
  // cancelled. Like the other blocking dialogs, only from a posted action
  bool exportOptionsDialog(int format, const std::string &fileName);

  // not implemented yet, kept so that the rest of Gmsh has something to call
  void showContextWindow(int dim, int tag);

  // raise one of the context dialogs, see Gui::showDialog()
  void showDialog(int which);
  void hideDialog(int which);
  bool dialogVisible(int which) const;
};

#endif

#endif
