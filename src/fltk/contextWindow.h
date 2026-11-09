// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CONTEXT_WINDOW_H
#define CONTEXT_WINDOW_H

#include <map>
#include <string>
#include <initializer_list>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>

// the value of a field of the operations on selected entities: the text of
// an input or of a choice, "1" or "0" for a check button
std::string fieldValue(Fl_Widget *w);

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
  // adds the entity of the pane to the script, unless a value it needs is
  // missing
  bool addShape(int pane);
};

class physicalContextWindow {
public:
  Fl_Window *win;
  Fl_Tabs *tab;
  Fl_Group *group[2];
  Fl_Box *box[2];
  Fl_Input_Choice *input[1];
  Fl_Check_Button *butt[1];
  Fl_Value_Input *value[1];
  Fl_Choice *choice[1];
  int selectedTag;
  std::string type, selectedName;
  std::map<int, std::string> physicalTags;
  std::map<std::string, int> physicalNames;

public:
  physicalContextWindow(int deltaFontSize = 0);
  ~physicalContextWindow() { Fl::delete_widget(win); }
  void show(const std::string &what, bool remove);
  void hide() { win->hide(); }
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
  // the widget of a field of the operations on selected entities, by its name
  // (see selectionDriver); the extrusion by a rotation has its own mesh fields
  Fl_Widget *field(const std::string &name, bool rotation = false);
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
  Fl_Widget *field(const std::string &name);
  ~meshContextWindow() { Fl::delete_widget(win); }
  void show(int pane);
  void hide() { win->hide(); }
};

#endif
