// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FL_GUI_H_
#define _FL_GUI_H_

#include <string>
#include <vector>

#define GMSH_WINDOW_BOX FL_FLAT_BOX
#define NB_BUTT_SCROLL 25
#define NB_HISTORY_MAX 1000
#define NB_SOLVER_MAX 5
#define IW (10 * FL_NORMAL_SIZE)    // input field width
#define BB (7 * FL_NORMAL_SIZE)     // width of a button with internal label
#define BH (2 * FL_NORMAL_SIZE + 1) // button height
#define WB (7)                      // window border

class graphicWindow;
class openglWindow;
class menuWindow;
class optionWindow;
class fieldWindow;
class pluginWindow;
class statisticsWindow;
class visibilityWindow;
class clippingWindow;
class manipWindow;
class geometryContextWindow;
class meshContextWindow;
class aboutWindow;
class onelabWindow;
class Fl_Widget;

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

class FlGui{
 private:
  static FlGui *_instance;
  bool _openedThroughMacFinder;
 public:
  std::vector<GVertex*> selectedVertices;
  std::vector<GEdge*> selectedEdges;
  std::vector<GFace*> selectedFaces;
  std::vector<GRegion*> selectedRegions;
  std::vector<MElement*> selectedElements;
 public:
  std::vector<graphicWindow*> graph;
  menuWindow *menu;
  optionWindow *options;
  fieldWindow *fields;
  pluginWindow *plugins;
  statisticsWindow *stats;
  visibilityWindow *visibility;
  clippingWindow *clipping;
  manipWindow *manip;
  geometryContextWindow *geoContext;
  meshContextWindow *meshContext;
  aboutWindow *about;
  onelabWindow *onelab;
 public:
  FlGui(int argc, char **argv);
  ~FlGui(){}
  // return the single static instance of the GUI
  static FlGui *instance(int argc=0, char **argv=0);
  // check if the GUI is available
  static bool available(){ return (_instance != 0); }
  // run the GUI until there's no window left
  static int run();
  // check (now!) if there are any pending events, and process them
  static void check();
  // wait (possibly indefinitely) for any events, then process them
  static void wait();
  // wait (at most time seconds) for any events, then process them
  static void wait(double time);
  // is a file opened through the Mac Finder?
  void setOpenedThroughMacFinder(bool val){ _openedThroughMacFinder = val; }
  bool getOpenedThroughMacFinder(){ return _openedThroughMacFinder; }
  // test application-level keyboard shortcuts
  int testGlobalShortcuts(int event);
  // test the arrow shortcuts (not in the application-level shortcuts)
  // since it is used elsewhere (where we want to override widget
  // navigation). This is necessary since FLTK 1.1.
  int testArrowShortcuts();
  // set the title of the graphic windows
  void setGraphicTitle(std::string title);
  // update the GUI when views get added or deleted
  void updateViews(bool numberOfViewsHasChanged=true);
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
  // select an entity in the most recent graphic window
  char selectEntity(int type);
  // display status message
  void setStatus(const char *msg, int num);
  // create the window for physical context dependant definitions
  void callForSolverPlugin(int dim);
  // add line in message console(s)
  void addMessage(const char *msg);
  // show the message console
  void showMessages();
  // add line in message console(s)
  void saveMessages(const char *fileName);
};

void redraw_cb(Fl_Widget *w, void *data);
void window_cb(Fl_Widget *w, void *data);

#endif
