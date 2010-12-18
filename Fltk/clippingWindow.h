// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CLIPPING_WINDOW_H_
#define _CLIPPING_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>

class clippingWindow{
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
  clippingWindow(int deltaFontSize=0);
  void resetBrowser();
  void show();
};

void clip_cb(Fl_Widget *w, void *data);

#endif
