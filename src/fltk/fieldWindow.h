// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FIELD_WINDOW_H
#define FIELD_WINDOW_H

#include <list>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Button.H>

class Field;

// One column: the fields, the options and the help of the one chosen, Apply
class fieldWindow {
private:
  int _deltaFontSize;
  bool _helpOpen;

public:
  Fl_Window *win;
  Fl_Hold_Browser *browser;
  std::list<Fl_Widget *> options_widget;
  // the options of the field chosen, then its help, in the scroll
  Fl_Scroll *options_scroll;
  Fl_Group *options_group, *editor_group;
  Fl_Box *title, *empty_message;
  Fl_Button *background_btn;
  Fl_Menu_Button *put_on_view_btn;
  Fl_Button *help_header;
  Fl_Box *help;
  Fl_Button *delete_btn;
  int selected_id;

public:
  fieldWindow(int deltaFontSize = 0);
  ~fieldWindow() { Fl::delete_widget(win); }
  void loadFieldViewList();
  void loadFieldList();
  void saveFieldOptions();
  void loadFieldOptions();
  void editField(Field *f);
  void toggleHelp();
  void layout();
};

void field_cb(Fl_Widget *w, void *data);

#endif
