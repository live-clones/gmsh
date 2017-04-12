// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _CONTEXT_WINDOW_H_
#define _CONTEXT_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>

class elementaryContextWindow{
 public:
  Fl_Window *win;
  Fl_Tabs *tab1, *tab2;
  Fl_Input *input[80];
  Fl_Value_Input *value[10];
  Fl_Group *group[20];
  Fl_Check_Button *butt[3];
 public:
  elementaryContextWindow(int deltaFontSize=0);
  void show(int pane);
  void hide(){ win->hide(); }
  void updatePoint(double pt[3], int which);
  bool frozenPointCoord(int coord);
};

class transformContextWindow{
 public:
  Fl_Window *win;
  Fl_Input *input[30];
  Fl_Value_Input *value[10];
  Fl_Group *group[10];
  Fl_Check_Button *butt[20];
  Fl_Choice *choice;
 public:
  transformContextWindow(int deltaFontSize=0);
  void show(int pane, bool extrude=false, bool selection=true);
  void hide(){ win->hide(); }
};

class physicalContextWindow{
 public:
  Fl_Window *win;
  Fl_Input_Choice *input[10];
  Fl_Check_Button *butt[10];
  Fl_Value_Input *value[10];
  std::string mode;
  bool append;
  Fl_Color color;
public:
  physicalContextWindow(int deltaFontSize=0);
  void show(bool remove);
  void hide(){ win->hide(); }
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
  void hide(){ win->hide(); }
};

#endif
