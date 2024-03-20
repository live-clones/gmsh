// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OPTION_WINDOW_H
#define OPTION_WINDOW_H

#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Box.H>
#include "spherePositionWidget.h"
#include "colorbarWindow.h"
#include "gamepadWindow.h"

#define NUM_FONTS 15
extern Fl_Menu_Item menu_font_names[];

class optionWindow {
public:
  Fl_Window *win;
  Fl_Multi_Browser *browser;
  Fl_Return_Button *redraw;
  gamepadWindow *gmpdoption;

  struct {
    Fl_Group *group;
    std::vector<Fl_Check_Button *> butt;
    std::vector<Fl_Button *> push;
    std::vector<Fl_Value_Input *> value;
    std::vector<Fl_Button *> color;
    std::vector<Fl_Input *> input;
    std::vector<Fl_Choice *> choice;
    Fl_Button *gamepadconfig;
    spherePositionWidget *sphere;
  } general;
  struct {
    Fl_Group *group;
    std::vector<Fl_Check_Button *> butt;
    std::vector<Fl_Value_Input *> value;
    std::vector<Fl_Button *> color;
    std::vector<Fl_Choice *> choice;
  } geo;
  struct {
    Fl_Group *group;
    std::vector<Fl_Check_Button *> butt;
    std::vector<Fl_Return_Button *> retbutt;
    std::vector<Fl_Input *> input;
    std::vector<Fl_Value_Input *> value;
    std::vector<Fl_Button *> color;
    std::vector<Fl_Choice *> choice;
    Fl_Menu_Button *menu;
  } mesh;
  struct {
    Fl_Group *group;
    std::vector<Fl_Check_Button *> butt;
    std::vector<Fl_Value_Input *> value;
    std::vector<Fl_Input *> input;
  } solver;
  struct {
    Fl_Group *group;
    std::vector<Fl_Check_Button *> butt;
    std::vector<Fl_Value_Input *> value;
    std::vector<Fl_Choice *> choice;
  } post;
  struct {
    int index;
    Fl_Group *group, *range;
    std::vector<Fl_Check_Button *> butt;
    std::vector<Fl_Value_Input *> value;
    std::vector<Fl_Input *> input;
    std::vector<Fl_Button *> push;
    std::vector<Fl_Choice *> choice;
    std::vector<Fl_Button *> color;
    std::vector<Fl_Box *> label;
    std::vector<Fl_Menu_Button *> menu;
    colorbarWindow *colorbar;
    Fl_Return_Button *ok;
  } view;

public:
  optionWindow(int deltaFontSize = 0);
  ~optionWindow() { Fl::delete_widget(win); }
  void showGroup(int num, bool showWindow = true,
                 bool allowMultipleSelections = false);
  void resetBrowser();
  void resetExternalViewList();
  void updateViewGroup(int index);
  void activate(const char *what);
};

void options_cb(Fl_Widget *w, void *data);
void options_restore_defaults_cb(Fl_Widget *w, void *data);
void general_options_cb(Fl_Widget *w, void *data);
void geometry_options_cb(Fl_Widget *w, void *data);
void mesh_options_cb(Fl_Widget *w, void *data);
void solver_options_cb(Fl_Widget *w, void *data);
void post_options_cb(Fl_Widget *w, void *data);
void view_options_cb(Fl_Widget *w, void *data);
void general_gmpdcf_cb(Fl_Widget *w, void *data);
void general_options_ok_cb(Fl_Widget *w, void *data);
void general_options_rotation_center_select_cb(Fl_Widget *w, void *data);
void general_options_axes_fit_cb(Fl_Widget *w, void *data);

#endif
