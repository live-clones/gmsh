// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _ABOUT_WINDOW_H_
#define _ABOUT_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>

class aboutWindow{
 public:
  Fl_Window *win, *winhelp;
 public:
  aboutWindow();
};

#endif
