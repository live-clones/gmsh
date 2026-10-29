// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OPTION_WINDOW_H
#define OPTION_WINDOW_H

#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
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
#include "widthRules.h"
#include "targetList.h"
#include "hintInput.h"

extern Fl_Menu_Item menu_font_names[];

class optionWindow {
private:
  // rows of overlapping widgets of a section, which the search shows or hides
  // together; y and h are relative to the top of the section, as built
  struct block {
    int y, h;
    std::vector<Fl_Widget *> widgets;
    std::vector<int> dy; // offset of each widget below the top of the block
  };
  // the tabs of the categories are folding sections
  struct section {
    std::string name;
    Fl_Button *header;
    Fl_Group *group;
    bool open;
    std::vector<block> blocks;
    // how its widgets follow a wider window
    widthRules rules;
  };
  std::vector<section> _sections[6];
  Fl_Group *_category[6];
  // the tabs of the categories: empty, the view list and the scroll lie in
  // their frame
  Fl_Tabs *_tabs;
  Fl_Group *_categoryTab[6];
  // _width is the width the sections are laid out for, the least there is
  int _current, _rowHeight, _width, _buttonWidth;
  std::vector<Fl_Widget *> _hiddenBySearch;
  searchFilter _filter;
  void _makeSections(int category);
  bool _searching();

public:
  Fl_Window *win;
  Fl_Input *search;
  Fl_Scroll *scroll;
  targetList *viewList;
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
  void toggleSection(int category, int section);
  // the tab clicked
  void categoryChosen();
  void selectViews(const std::string &which);
  void updateViewTargets();
  // keepPosition keeps the scroll where it is, e.g. when a section is folded
  void layout(bool keepPosition);
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
