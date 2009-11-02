// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PLUGIN_WINDOW_H_
#define _PLUGIN_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Check_Button.H>

class GMSH_Plugin;

class pluginWindow{
 public:
  Fl_Window *win;
  Fl_Hold_Browser *browser;
  Fl_Multi_Browser *view_browser;
  Fl_Check_Button *record;
  void _createDialogBox(GMSH_Plugin *p, int x, int y, int width, int height);
 public:
  pluginWindow(int deltaFontSize=0);
  void show(int viewIndex);
  void resetViewBrowser();
};

void plugin_cb(Fl_Widget *w, void *data);

#endif
