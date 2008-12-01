// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PLUGIN_WINDOW_H_
#define _PLUGIN_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Input.H>

class GMSH_Plugin;

#define MAX_PLUGIN_OPTIONS 50
struct PluginDialogBox{
  Fl_Group *group;
  Fl_Value_Input *value[MAX_PLUGIN_OPTIONS];
  Fl_Input *input[MAX_PLUGIN_OPTIONS];
};

class pluginWindow{
 private:
  int _fontsize;
 public:
  Fl_Window *win;
  Fl_Hold_Browser *browser;
  Fl_Multi_Browser *view_browser;
  Fl_Return_Button *run;
 public:
  pluginWindow(int fontsize);
  void show(int viewIndex);
  void createDialogBox(GMSH_Plugin *p, int x, int y, int width, int height);
  void resetViewBrowser();
};

void plugin_cb(Fl_Widget *w, void *data);

#endif
