// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PHYSICAL_GROUP_WINDOW_H
#define PHYSICAL_GROUP_WINDOW_H

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>

class physicalGroupWindow {
public:
  Fl_Window *win;
  Fl_Input_Choice *input[10];
  Fl_Check_Button *butt[10];
  Fl_Value_Input *value[10];
  std::string mode;
  bool append;
  Fl_Color color;

public:
  physicalGroupWindow(int deltaFontSize = 0);
  ~physicalGroupWindow() { Fl::delete_widget(win); }
  void show(bool remove);
  void hide() { win->hide(); }
};

#endif
