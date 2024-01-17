// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FL_GUI_H
#define FL_GUI_H

#include <string>
#include <vector>
#include <atomic>
#include "SPoint2.h"

#define GMSH_WINDOW_BOX FL_FLAT_BOX
#define GMSH_SIMPLE_RIGHT_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 1)
#define GMSH_SIMPLE_TOP_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 2)

#define IW (10 * FL_NORMAL_SIZE) // input field width
#define BB (7 * FL_NORMAL_SIZE) // width of a button with internal label
#define BH (2 * FL_NORMAL_SIZE + 1) // button height
#define WB (5) // window border

class graphicWindow;
class openglWindow;
class optionWindow;
class onelabWindow;
class fieldWindow;
class pluginWindow;
class statisticsWindow;
class visibilityWindow;
class highOrderToolsWindow;
class clippingWindow;
class manipWindow;
class elementaryContextWindow;
class transformContextWindow;
class meshContextWindow;
class physicalContextWindow;
class onelabContextWindow;
class onelabGroup;
class helpWindow;
class Fl_Widget;
class drawContext;

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

class FlGui {
private:
  static FlGui *_instance;
  static std::string _openedThroughMacFinder;
  static bool _finishedProcessingCommandLine;
  static std::atomic<int> _locked;
  std::string _lastStatus;
  bool _quitShouldExit;

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
  manipWindow *manip;
  elementaryContextWindow *elementaryContext;
  transformContextWindow *transformContext;
  meshContextWindow *meshContext;
  physicalContextWindow *physicalContext;
  onelabContextWindow *onelabContext;
  int lastContextWindow;
  helpWindow *help;
  onelabGroup *onelab;
  openglWindow *fullscreen;

public:
  FlGui(int argc, char **argv, bool quitShouldExit,
        void (*error_handler)(const char *fmt, ...) = nullptr);
  ~FlGui();
  // return the single static instance of the GUI
  static FlGui *instance(int argc = 0, char **argv = nullptr,
                         bool quitShouldExit = true,
                         void (*error_handler)(const char *fmt, ...) = nullptr);
  // close all windows and destroy instance
  static void destroy();
  // check if the GUI is available
  static bool available();
  // run the GUI until there's no window left
  static int run();
  // check if there are any pending events, and process them (if rateLimited is
  // set, only perform the check if one has not been made in the last 1 /
  // General.FltkRefreshRate seconds)
  static void check(bool rateLimited = false);
  // wait (possibly indefinitely) for any events, then process them
  static void wait(bool force = false);
  // wait (at most time seconds) for any events, then process them
  static void wait(double time, bool force = false);
  // lock/unlock child threads
  static void lock();
  static void unlock();
  // trigger event loop in main thread
  static void awake(const std::string &action);
  // is locked
  static int locked();
  // is a file opened through the Mac Finder?
  static void setOpenedThroughMacFinder(const std::string &name);
  static std::string getOpenedThroughMacFinder();
  static void setFinishedProcessingCommandLine();
  static bool getFinishedProcessingCommandLine();
  // test application-level keyboard shortcuts
  int testGlobalShortcuts(int event);
  // test the arrow shortcuts (not in the application-level shortcuts)
  // since it is used elsewhere (where we want to override widget
  // navigation). This is necessary since FLTK 1.1.
  int testArrowShortcuts();
  // set the title of the graphic windows
  void setGraphicTitle(const std::string &title);
  // update the GUI when views get modified, added or deleted
  void updateViews(bool numberOfViewsHasChanged, bool deleteWidgets);
  // update the GUI when fields change
  void updateFields();
  // reset the visibility window
  void resetVisibility();
  // update the statistics window
  void updateStatistics(bool qualities = false);
  // store current window positions and sizes in CTX
  void storeCurrentWindowsInfo();
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
  // select an entity in the most recent graphic window
  char selectEntity(int type);
  // display status message
  void setStatus(const std::string &msg, bool opengl = false);
  // redisplay last status message
  void setLastStatus(int col = -1);
  // display status message and update progress bar
  void setProgress(const std::string &msg, double val, double min, double max);
  // add line in message console
  void addMessage(const char *msg);
  // save messages to file
  void saveMessages(const char *fileName);
  // rebuild the tree
  void rebuildTree(bool deleteWidgets);
  // toggles the module open or closed based on its current state
  void toggleModule(const std::string &name);
  // open module in tree
  void openModule(const std::string &name);
  // open tree item
  void openTreeItem(const std::string &name);
  // close tree item
  void closeTreeItem(const std::string &name);
  // apply color scheme to widgets
  void applyColorScheme(bool redraw = false);
  // should the quit callback exit the app, or just close all windows?
  bool quitShouldExit() { return _quitShouldExit; }
  // show onelab context window for the given entity
  void showOnelabContext(int dim, int tag);
};

void redraw_cb(Fl_Widget *w, void *data);
void window_cb(Fl_Widget *w, void *data);

#endif
