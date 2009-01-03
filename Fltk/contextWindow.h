// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CONTEXT_WINDOW_H_
#define _CONTEXT_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Group.H>

class geometryContextWindow{
 public:
  Fl_Window *win;
  Fl_Input *input[30];
  Fl_Value_Input *value[10];
  Fl_Group *group[10];
 public:
  geometryContextWindow(int deltaFontSize=0);
  void show(int pane);
};

class meshContextWindow{
 public:
  Fl_Window *win;
  Fl_Input *input[20];
  Fl_Choice *choice[20];
  Fl_Group *group[10];
 public:
  meshContextWindow(int deltaFontSize=0);
  void show(int pane);
};

#endif
