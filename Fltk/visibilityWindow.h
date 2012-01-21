// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _VISIBILITY_WINDOW_H_
#define _VISIBILITY_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include "GmshConfig.h"

#if defined(HAVE_FL_TREE)
#include "FL/Fl_Tree.H"
#endif

class visibilityWindow{
 public:
  Fl_Window *win;
  Fl_Choice *browser_type;
  Fl_Browser *browser;
  Fl_Multi_Browser *per_window;
#if defined(HAVE_FL_TREE)
  Fl_Tree *tree;
  Fl_Button *tree_create;
#endif
  Fl_Check_Button *butt[2];
  Fl_Button *push[2];
  Fl_Input *input[10];
 public:
  visibilityWindow(int deltaFontSize=0);
  void show(bool redrawOnly);
  void updatePerWindow(bool force=false);
};

void visibility_cb(Fl_Widget *w, void *data);

#endif
