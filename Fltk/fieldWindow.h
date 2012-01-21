// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FIELD_WINDOW_H_
#define _FIELD_WINDOW_H_

#include <list>
#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Button.H>

class Field;

class fieldWindow{
 private:
  int _deltaFontSize;
 public:
  Fl_Window *win;
  Fl_Hold_Browser *browser;
  std::list<Fl_Widget*> options_widget;
  Fl_Scroll *options_scroll;
  Fl_Group *editor_group;
  Fl_Box *title, *empty_message;
  Fl_Button *background_btn;
  Fl_Menu_Button *put_on_view_btn;
  Fl_Help_View *help_display;
  Fl_Button *delete_btn;
  int selected_id;
 public:
  fieldWindow(int deltaFontSize=0);
  void loadFieldViewList();
  void loadFieldList();
  void saveFieldOptions();
  void loadFieldOptions();
  void editField(Field *f);
};

void field_cb(Fl_Widget *w, void *data);

#endif
