// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _FL_GUI_H_
#define _FL_GUI_H_

#include <string>
#include <vector>
#include "SPoint2.h"

#define GMSH_WINDOW_BOX FL_FLAT_BOX
#define GMSH_SIMPLE_RIGHT_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE+1)
#define GMSH_SIMPLE_TOP_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE+2)

#define IW (10 * FL_NORMAL_SIZE)    // input field width
#define BB (7 * FL_NORMAL_SIZE)     // width of a button with internal label
#define BH (2 * FL_NORMAL_SIZE + 1) // button height
#define WB (5)                      // window border

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
class physicalContextWindow;
class meshContextWindow;
class helpWindow;
class onelabGroup;
class Fl_Widget;

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

class FlGui{
 private:
  static FlGui *_instance;
  static std::string _openedThroughMacFinder;
  std::string _lastStatus;
 public:
  std::vector<GVertex*> selectedVertices;
  std::vector<GEdge*> selectedEdges;
  std::vector<GFace*> selectedFaces;
  std::vector<GRegion*> selectedRegions;
  std::vector<MElement*> selectedElements;
  std::vector<SPoint2> selectedPoints;
  std::vector<PView*> selectedViews;
 public:
  std::vector<graphicWindow*> graph;
  optionWindow *options;
  onelabWindow *onelab2;
  fieldWindow *fields;
  pluginWindow *plugins;
  statisticsWindow *stats;
  visibilityWindow *visibility;
  highOrderToolsWindow *highordertools;
  clippingWindow *clipping;
  manipWindow *manip;
  elementaryContextWindow *elementaryContext;
  physicalContextWindow *physicalContext;
  meshContextWindow *meshContext;
  helpWindow *help;
  onelabGroup *onelab;
  openglWindow *fullscreen;
 public:
  FlGui(int argc, char **argv);
  ~FlGui(){}
  // return the single static instance of the GUI
  static FlGui *instance(int argc=0, char **argv=0);
  // check if the GUI is available
  static bool available();
  // run the GUI until there's no window left
  static int run();
  // check (now!) if there are any pending events, and process them
  static void check();
  // wait (possibly indefinitely) for any events, then process them
  static void wait();
  // wait (at most time seconds) for any events, then process them
  static void wait(double time);
  // lock/unlock child threads
  static void lock();
  static void unlock();
  // is a file opened through the Mac Finder?
  static void setOpenedThroughMacFinder(const std::string &name);
  static std::string getOpenedThroughMacFinder();
  // test application-level keyboard shortcuts
  int testGlobalShortcuts(int event);
  // test the arrow shortcuts (not in the application-level shortcuts)
  // since it is used elsewhere (where we want to override widget
  // navigation). This is necessary since FLTK 1.1.
  int testArrowShortcuts();
  // set the title of the graphic windows
  void setGraphicTitle(std::string title);
  // update the GUI when views get modified, added or deleted
  void updateViews(bool numberOfViewsHasChanged, bool deleteWidgets);
  // update the GUI when fields change
  void updateFields();
  // reset the visibility window
  void resetVisibility();
  // store current window positions and sizes in CTX
  void storeCurrentWindowsInfo();
  // get the last opengl window that received an event
  openglWindow *getCurrentOpenglWindow();
  // split the current opengl window
  void splitCurrentOpenglWindow(char how);
  // copy the current opengl window to the clipboard
  void copyCurrentOpenglWindowToClipboard();
  // select an entity in the most recent graphic window
  char selectEntity(int type);
  // display status message
  void setStatus(const std::string &msg, bool opengl=false);
  // redisplay last status message
  void setLastStatus(int col=-1);
  // display status message and update progress bar
  void setProgress(const std::string &msg, double val, double min, double max);
  // create the window for physical context dependant definitions
  void callForSolverPlugin(int dim);
  // add line in message console
  void addMessage(const char *msg);
  // save messages to file
  void saveMessages(const char *fileName);
  // rebuild the tree
  void rebuildTree(bool deleteWidgets);
  // open module in tree
  void openModule(const std::string &name);
  // apply color scheme to widgets
  void applyColorScheme();
};

void redraw_cb(Fl_Widget *w, void *data);
void window_cb(Fl_Widget *w, void *data);

#endif
