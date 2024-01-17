// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MANIP_WINDOW_H
#define MANIP_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Value_Input.H>

class manipWindow {
public:
  Fl_Window *win;
  Fl_Value_Input *value[9];

public:
  manipWindow(int deltaFontSize);
  ~manipWindow() { Fl::delete_widget(win); }
  void update(bool force = false);
  void show();
};

void manip_cb(Fl_Widget *w, void *data);

#endif
