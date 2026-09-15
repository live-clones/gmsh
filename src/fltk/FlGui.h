// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FL_GUI_H
#define FL_GUI_H

#include <string>
#include <vector>
#include <atomic>
#include "SPoint2.h"
#include "Backend.h"
#include "fltkMetrics.h"

// The state of the FLTK interface, held by its backend: the windows, the
// tree, what the user has picked in the scene, and the lock the threads
// share. What the interface does is the backend's, in BackendFltk.cpp; what
// is here is what the windows of this interface reach for in each other.

class graphicWindow;
class sceneViewFltk;

// say to the 3D scene who is holding it, once the windows it is drawn in
// exist; defined in SceneFltk.cpp
void fltkInstallSceneHost();
class onelabWindow;
class onelabGroup;
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
  static std::atomic<int> _locked;

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
  onelabGroup *onelab;
  sceneViewFltk *fullscreen;

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
  static int locked();
  // The keys of the application, from Menu::keys(), for the key FLTK is
  // reporting. The 3D view calls it on its own key events, so that the arrows
  // step the animation rather than move the focus; everything else reaches
  // it as a shortcut nothing else took.
  int runKeys();
  // where the windows ended up, for the option file
  Ui::Backend::Layout windowLayout();
  // get the last opengl window that received an event
  sceneViewFltk *getCurrentOpenglWindow();
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
  // add line in message console
  void addMessage(const char *msg);
  // save messages to file
  void messageLines(std::vector<std::string> &lines);
  // rebuild the tree
  void rebuildTree(bool deleteWidgets);
  // apply color scheme to widgets
  void applyColorScheme(bool redraw = false);
};

void redraw_cb(Fl_Widget *w, void *data);
void window_cb(Fl_Widget *w, void *data);

#endif
