// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FL_GUI_H
#define FL_GUI_H

#include <memory>
#include <list>
#include <string>
#include <vector>
#include <thread>
#include "SPoint2.h"
#include "gmshScheme.h"
#include "GuiListener.h"

#define GMSH_WINDOW_BOX FL_FLAT_BOX
#define GMSH_SIMPLE_RIGHT_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 1)
#define GMSH_SIMPLE_TOP_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 2)
// the thumb and the track of the scrollbars of the gmsh theme (see
// gmshScheme.cpp)
#define GMSH_THUMB_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 3)
#define GMSH_TRACK_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 4)

#define IW (10 * FL_NORMAL_SIZE) // input field width
#define BB (7 * FL_NORMAL_SIZE) // width of a button with internal label
// the button height and the window border, a little larger under the gmsh
// theme (see gmshScheme.h): the air between the widgets
#define BH (2 * FL_NORMAL_SIZE + 1 + gmshAir())
#define WB (5 + gmshAir())
// least width of the tool windows: that of the option window, i.e. 28 em of
// fields with a scrollbar beside them
#define TW (28 * FL_NORMAL_SIZE + 2 * WB + Fl::scrollbar_size())

class paletteWindow;
class Fl_Window;
class graphicWindow;

// the FLTK code of the shortcut of an action (see GetShortcuts() in
// Shortcuts.h: the keys declared on the items of Actions.cpp), for the menus;
// 0 for one not bound on the macOS system menu bar
int fltkShortcut(const char *action, bool systemBar = false);
class openglWindow;
class optionWindow;
class onelabWindow;
class fieldWindow;
class pluginWindow;
class statisticsWindow;
class visibilityWindow;
class highOrderToolsWindow;
class clippingWindow;
class partitionWindow;
class classificationEditor;
class manipWindow;
class elementaryContextWindow;
class transformContextWindow;
class meshContextWindow;
class physicalContextWindow;
class onelabContextWindow;
class onelabGroup;
class helpWindow;
class Fl_Widget;
class Fl_Box;
class drawContext;

// the height of the label of a box wrapped on lines w wide, as FLTK draws a
// label inside its box, plus a border below
int wrappedHeight(Fl_Box *b, int w);

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

// The FLTK graphical user interface: a guiListener, the core tells it what
// changed (see GuiListener.h)
class FlGui : public guiListener {
private:
  static FlGui *_instance;
  static std::string _openedThroughMacFinder;
  static bool _finishedProcessingCommandLine;
  // the thread that created the GUI, the only one that may touch it
  static std::thread::id _mainThread;
  // the widgets the events being handled were sent to (see _dispatch() and
  // the comment at the top of FlGui.cpp)
  static std::vector<Fl_Widget **> _eventWidgets;
  static int _dispatch(int event, Fl_Window *win);
  // the widgets retired by retireInEvent(), with the strings they show
  struct _retired {
    Fl_Widget *widget;
    std::shared_ptr<std::list<std::string>> strings;
  };
  static std::vector<_retired> _retiredWidgets;
  // those no event targets any more deleted (all of them if all)
  static void _deleteRetired(bool all);
  std::string _lastStatus;
  bool _quitShouldExit;
  // the tool windows, named for General.FloatingTools
  std::vector<paletteWindow *> _tools;

public:
  std::vector<GVertex *> selectedVertices;
  std::vector<GEdge *> selectedEdges;
  std::vector<GFace *> selectedFaces;
  std::vector<GRegion *> selectedRegions;
  std::vector<MElement *> selectedElements;
  std::vector<SPoint2> selectedPoints;
  std::vector<PView *> selectedViews;

public:
  std::vector<graphicWindow *> graph;
  optionWindow *options;
  fieldWindow *fields;
  pluginWindow *plugins;
  statisticsWindow *stats;
  visibilityWindow *visibility;
  highOrderToolsWindow *highordertools;
  clippingWindow *clipping;
  partitionWindow *partition;
  classificationEditor *classify;
  // the tool windows, docked while the main window has a dock
  const std::vector<paletteWindow *> &toolWindows() const { return _tools; }
  // the ones kept on the desktop, from and to General.FloatingTools: the
  // open ones move when the option changes
  void applyFloatingTools();
  void storeFloatingTools();
  // a tool kept on the desktop or docked, moved if open
  void setToolFloating(paletteWindow *p, bool floating);
  // docks or undocks every tool, or the one holding the focus (else the one
  // shown in the dock)
  void dockTools(bool dock);
  void toggleCurrentTool();
  manipWindow *manip;
  elementaryContextWindow *elementaryContext;
  transformContextWindow *transformContext;
  meshContextWindow *meshContext;
  physicalContextWindow *physicalContext;
  onelabContextWindow *onelabContext;
  helpWindow *help;
  onelabGroup *onelab;
  openglWindow *fullscreen;

public:
  FlGui(int argc, char **argv, bool quitShouldExit,
        void (*error_handler)(const char *fmt, ...) = nullptr);
  ~FlGui();
  // the GUI created, with these arguments, if there is none yet (at startup,
  // and by gmsh::fltk::initialize())
  static FlGui *create(int argc = 0, char **argv = nullptr,
                       bool quitShouldExit = true,
                       void (*error_handler)(const char *fmt, ...) = nullptr);
  // the GUI, which must exist (see available()): this never creates it, as
  // code outside the GUI (a script read in batch mode) must not
  static FlGui *instance() { return _instance; }
  // close all windows and destroy instance
  static void destroy();
  // check if the GUI is available
  static bool available();
  // whether the caller is the thread that runs the GUI: the others (OpenMP
  // workers, the threads of an API program) must not touch it
  static bool onMainThread();
  // whether w is or holds a widget an event being handled was sent to, or one
  // it has moved to since (a click gives the focus to an input, whose code
  // goes on once the input that had it has run its callback): its code may be
  // running (see onelabGroup::_rebuildTree())
  static bool inEvent(Fl_Widget *w);
  // Of widgets about to be deleted (the rows of a list made again), those an
  // event being handled was sent to are retired: their code may still be
  // running, so they are kept, hidden by the caller, with the strings they
  // show (moved out of strings), until no event targets them. Returns the
  // others, to delete. To call before hiding them, which takes the focus away.
  static std::vector<Fl_Widget *>
  retireInEvent(const std::vector<Fl_Widget *> &widgets,
                std::list<std::string> &strings);
  // whether an event is being handled: the code of its widgets is running
  static bool handlingEvent() { return !_eventWidgets.empty(); }
  // a graphic window draws or runs a picking pass: the messages it prints do
  // not process events meanwhile, which could delete what it draws
  static int drawing;
  // run the GUI until there's no window left
  static int run(const std::string &optionFileName="");
  // check if there are any pending events, and process them (if rateLimited is
  // set, only perform the check if one has not been made in the last 1 /
  // General.FltkRefreshRate seconds)
  static void check(bool rateLimited = false);
  // wait (possibly indefinitely) for any events, then process them
  static void wait(bool force = false);
  // wait (at most time seconds) for any events, then process them
  static void wait(double time, bool force = false);
  // lock/unlock child threads (FLTK's lock: the thread of the GUI holds it
  // except while it waits for events)
  static void lock();
  static void unlock();
  // trigger event loop in main thread
  static void awake(const std::string &action);
  // is a file opened through the Mac Finder?
  static void setOpenedThroughMacFinder(const std::string &name);
  static std::string getOpenedThroughMacFinder();
  static void setFinishedProcessingCommandLine();
  static bool getFinishedProcessingCommandLine();
  // test application-level keyboard shortcuts
  int testGlobalShortcuts(int event);
  // runs the item of the registry named by a shortcut (see Actions.h), as a
  // click on it does; 0 if there is none or it is not available now
  int runShortcut(const std::string &action);
  // test the shortcuts of the arrows and Page Up/Down, where they override
  // the navigation between widgets (the 3D view)
  int testArrowShortcuts();
  // set the title of the graphic windows
  void setGraphicTitle(const std::string &title);
  // update the GUI when views get modified, added or deleted
  void updateViews(bool numberOfViewsHasChanged);
  // update the GUI when fields change
  void updateFields();
  // reset the visibility window
  void resetVisibility();
  // update the statistics window
  void updateStatistics(bool qualities = false);
  // store current window positions and sizes in CTX
  void storeCurrentWindowsInfo();
  // every graphic window, the fullscreen one included
  std::vector<openglWindow *> openglWindows();
  // get the last opengl window that received an event
  openglWindow *getCurrentOpenglWindow();
  // get the draw context from the last opengl window that received an event
  drawContext *getCurrentDrawContext();
  // override which opengl window should be considered as current, by given an
  // absolute index amongst all the existing opengl windows
  void setCurrentOpenglWindow(int which);
  // split the current opengl window
  void splitCurrentOpenglWindow(char how, double ratio = 0.5);
  // copy the current opengl window to the clipboard
  void copyCurrentOpenglWindowToClipboard();
  // wait for a selection in the most recent graphic window (the API's: the
  // interface's own picks are tools, see sceneTool)
  char selectEntity(int type, bool pickElements = false);
  // display status message
  void setStatus(const std::string &msg, bool opengl = false);
  // redisplay last status message
  void setLastStatus(int col = -1);
  // display status message and update progress bar
  void setProgress(const std::string &msg, double val, double min, double max);
  // add line in message console; from another thread than the GUI's, the line
  // is queued and added by the GUI's thread when it next processes events
  static void addMessage(const char *msg);
  // save messages to file
  void saveMessages(const char *fileName);
  // rebuild the tree
  void rebuildTree();
  // toggles the module open or closed based on its current state
  void toggleModule(const std::string &name);
  // open module in tree
  void openModule(const std::string &name) override;
  // open tree item
  void openTreeItem(const std::string &name);
  // close tree item
  void closeTreeItem(const std::string &name);
  // apply color scheme to widgets
  void applyColorScheme(bool redraw = false);
  // the interface follows the desktop between light and dark when asked to
  void desktopChanged();
  // should the quit callback exit the app, or just close all windows?
  bool quitShouldExit() { return _quitShouldExit; }
  // show onelab context window for the given entity
  void showOnelabContext(int dim, int tag);

  // what the core tells the interface (see GuiListener.h)
  bool running() override;
  drawContext *scene() override;
  int desktopDark() override;
  void optionChanged(const std::string &category, int num,
                     const std::string &name) override;
  void optionsChanged() override;
  void beforeOptionsSaved() override;
  void backgroundImageChanged() override;
  void floatingToolsChanged() override;
  void colorSchemeChanged() override;
  void openglModeChanged() override;
  void shadersChanged() override;
  void tooltipsChanged() override;
  void mouseSelectionChanged() override;
  void graphicSizeChanged() override;
  void messageFontSizeChanged() override;
  void menuAttachedChanged() override;
  void menuWidthChanged() override;
  void sceneTransformChanged() override;
  void clippingChanged() override;
  void lightChanged() override;
  void snapChanged() override;
  void animationChanged() override;
  void viewTimeStepChanged(int num) override;
  void viewRenamed(int num) override;
  void viewVisibilityChanged(int num) override;
  void viewOpenedOrClosed(int num) override;
  void viewColorMapChanged(int num) override;
  void viewsChanged(bool numberChanged) override;
  void fieldsChanged() override;
  void entitiesChanged() override;
  void parametersChanged() override;
  void setCurrentWindow(int index) override;
  void splitCurrentWindow(char how, double ratio) override;
};

// the engine that draws text, chosen by name (General.GraphicsFontEngine):
// given to the core at startup (see GmshGlobal.cpp), as a batch run draws too
void fltkFontEngine(const std::string &engine);

void redraw_cb(Fl_Widget *w, void *data);
// The windows, as the Window menu has them (see fltkActions.cpp): all of
// them minimized (the docked tools with the main window), the main window
// maximized or back, the scene full screen or back (and whether it is), and
// all of them brought to the front
void minimizeWindows();
void zoomMainWindow();
void toggleFullScreen();
bool isFullScreen();
void bringAllToFront();

#endif
