// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CLIPPING_WINDOW_H
#define CLIPPING_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>

class clippingWindow {
public:
  Fl_Window *win;
  Fl_Choice *choice;
  Fl_Multi_Browser *browser;
  Fl_Value_Input *plane[4];
  Fl_Value_Input *box[6];
  Fl_Check_Button *butt[3];
  Fl_Group *group[2];
  void fillBoxValuesFromPlaneValues();

public:
  clippingWindow(int deltaFontSize = 0);
  ~clippingWindow() { Fl::delete_widget(win); }
  void resetBrowser();
  void show();
};

void clip_cb(Fl_Widget *w, void *data);

#endif
