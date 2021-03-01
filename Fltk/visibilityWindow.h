// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VISIBILITY_WINDOW_H
#define VISIBILITY_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Tree.H>

class visibilityWindow {
public:
  Fl_Window *win;
  Fl_Choice *browser_type;
  Fl_Browser *browser;
  Fl_Multi_Browser *per_window;
  Fl_Tree *tree;
  Fl_Button *tree_create;
  Fl_Check_Button *butt[2];
  Fl_Button *push[2];
  Fl_Input *input[10];
  Fl_Input *search;

public:
  visibilityWindow(int deltaFontSize = 0);
  ~visibilityWindow() { Fl::delete_widget(win); }
  void show(bool redrawOnly);
  void updatePerWindow(bool force = false);
};

void visibility_cb(Fl_Widget *w, void *data);

#endif
