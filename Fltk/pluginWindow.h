// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PLUGIN_WINDOW_H
#define PLUGIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Check_Button.H>

class GMSH_Plugin;

class pluginWindow {
public:
  Fl_Window *win;
  Fl_Hold_Browser *browser;
  Fl_Multi_Browser *view_browser;
  Fl_Check_Button *record;
  void _createDialogBox(GMSH_Plugin *p, int x, int y, int width, int height);

public:
  pluginWindow(int deltaFontSize = 0);
  ~pluginWindow() { Fl::delete_widget(win); }
  void show(int viewIndex);
  void resetViewBrowser();
};

void plugin_cb(Fl_Widget *w, void *data);

#endif
