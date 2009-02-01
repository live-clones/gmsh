 // Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SOLVER_WINDOW_H_
#define _SOLVER_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Button.H>

class solverWindow{
 public:
  Fl_Window *win;
  Fl_Input *input[50];
  Fl_Choice *choice[10];
  Fl_Menu_Button *menu;
  Fl_Button *command[10];
 public:
  solverWindow(int solverIndex, int deltaFontSize=0);
};

void solver_cb(Fl_Widget *w, void *data);

#endif
