// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HIGHORDERTOOLS_WINDOW_H
#define HIGHORDERTOOLS_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Output.H>

class highOrderToolsWindow {
public:
  bool CAD, complete;
  int meshOrder;
  Fl_Window *win;
  Fl_Box *box;
  Fl_Check_Button *butt[4];
  Fl_Value_Input *value[12];
  Fl_Choice *choice[4];
  Fl_Button *push[2];

public:
  highOrderToolsWindow(int deltaFontSize = 0);
  ~highOrderToolsWindow() { Fl::delete_widget(win); }
  void show(bool redrawOnly);
};

void highordertools_cb(Fl_Widget *w, void *data);

#endif
