// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CONTEXT_WINDOW_H
#define CONTEXT_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>

class elementaryContextWindow {
public:
  Fl_Window *win;
  Fl_Tabs *tab1, *tab2;
  Fl_Input *input[80];
  Fl_Value_Input *value[10];
  Fl_Group *group[20];
  Fl_Check_Button *butt[3];

public:
  elementaryContextWindow(int deltaFontSize = 0);
  ~elementaryContextWindow() { Fl::delete_widget(win); }
  void show(int pane);
  void hide() { win->hide(); }
  void updatePoint(double pt[3], int which);
  bool frozenPointCoord(int coord);
};

class transformContextWindow {
public:
  Fl_Window *win;
  Fl_Input *input[30];
  Fl_Value_Input *value[10];
  Fl_Group *group[10];
  Fl_Check_Button *butt[20];
  Fl_Choice *choice;

public:
  transformContextWindow(int deltaFontSize = 0);
  ~transformContextWindow() { Fl::delete_widget(win); }
  void show(int pane, bool extrude = false, bool selection = true);
  void hide() { win->hide(); }
};

class meshContextWindow {
public:
  Fl_Window *win;
  Fl_Input *input[20];
  Fl_Choice *choice[20];
  Fl_Group *group[10];

public:
  meshContextWindow(int deltaFontSize = 0);
  ~meshContextWindow() { Fl::delete_widget(win); }
  void show(int pane);
  void hide() { win->hide(); }
};

#endif
