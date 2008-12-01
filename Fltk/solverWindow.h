 // Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SOLVER_WINDOW_H_
#define _SOLVER_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Button.H>

class solverWindow{
 private:
  int _fontsize;
 public:
  Fl_Window *win;
  Fl_Input *input[50];
  Fl_Choice *choice[10];
  Fl_Check_Button *butt[10];
  Fl_Button *command[10];
 public:
  solverWindow(int solverIndex, int fontsize);
};

#endif
