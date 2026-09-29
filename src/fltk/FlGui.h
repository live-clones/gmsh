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

// the state of the FLTK interface: what its windows reach for in each other;
// what it does is in BackendFltk.cpp

class graphicWindow;
class sceneViewFltk;

// defined in SceneFltk.cpp: the scene's views on GuiPanes, from before the
// first window is made to after the last is gone; the text engine the
// options say
void fltkSceneStart();
void fltkSceneStop();
void fltkFontEngine();
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
  // the 3D view calls it on its own key events, so that the arrows step the
  // animation rather than move the focus
  int runKeys();
  // the key of the event being handled as Ui::Shortcut says it: false for
  // one no shortcut could name. A digit or a mark is the one typed, whatever
  // key gives it on this keyboard (Shift, on a French one)
  static bool eventKey(int &key, unsigned &mods);
  Ui::Backend::Layout windowLayout();
  // get the last opengl window that received an event
  sceneViewFltk *getCurrentOpenglWindow();
  // get the draw context from the last opengl window that received an event
  drawContext *getCurrentDrawContext();
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
