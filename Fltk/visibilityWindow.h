// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _VISIBILITY_WINDOW_H_
#define _VISIBILITY_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>

class visibilityWindow{
 private:
  int _fontsize;
 public:
  Fl_Window *win;
  Fl_Group *group[5];
  Fl_Choice *type;
  Fl_Browser *browser;
  Fl_Check_Button *butt[2];
  Fl_Button *push[2];
  Fl_Input *input[10];
 public:
  visibilityWindow(int fontsize);
  void show(bool redrawOnly);
};

void visibility_cb(Fl_Widget *w, void *data);

#endif
