// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PLUGIN_WINDOW_H
#define PLUGIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include "targetList.h"
#include "hintInput.h"

class GMSH_Plugin;

// One column: the plugins, found by name or by what they do, the options and
// the help of the one chosen, the views it runs on, and Run
class pluginWindow {
private:
  int _rowHeight, _fieldWidth, _listHeight, _cols[2];
  bool _helpOpen;
  // the plugin whose options are in the scroll
  GMSH_Plugin *_shown;
  searchFilter _filter;
  void _createDialogBox(GMSH_Plugin *p);
  // returns where what follows goes
  int _placeDialogBox(GMSH_Plugin *p, int x, int y, int w);
  void _fillScroll(GMSH_Plugin *p);

public:
  Fl_Window *win;
  Fl_Input *search;
  Fl_Hold_Browser *browser;
  Fl_Scroll *scroll;
  Fl_Button *helpHeader;
  Fl_Box *help;
  targetList *views;
  Fl_Check_Button *record;
  Fl_Return_Button *run;

public:
  pluginWindow(int deltaFontSize = 0);
  ~pluginWindow() { Fl::delete_widget(win); }
  void show(int viewIndex);
  void resetViewBrowser();
  // the plugin chosen in the list, if any
  GMSH_Plugin *selected() const;
  // shows only the plugins whose name or short help holds the search
  void filter();
  void toggleHelp();
  void updateCount();
  void layout();
};

void plugin_cb(Fl_Widget *w, void *data);

#endif
