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

  // The pages, from the table of OptionPages.h: the widgets bound to an
  // option are reached by its name (see widget()); here the others
  struct {
    Fl_Group *group;
    // the buttons that act on other options, and the ball of the light
    Fl_Button *selectRotationCenter, *fitAxes, *gamepadconfig;
    spherePositionWidget *sphere;
  } general;
  struct {
    Fl_Group *group;
  } geo, mesh, solver, post;
  struct {
    int index; // the view shown
    bool hasElements; // the view shown has elements: its range applies
    Fl_Group *group;
    // the range taken from the values
    Fl_Button *rangeMin, *rangeMax;
    // the views to choose from, listed as they come
    Fl_Choice *externalView, *generalizedRaiseView;
    Fl_Choice *colormap;
    colorbarWindow *colorbar;
  } view;

public:
  optionWindow(int deltaFontSize = 0);
  ~optionWindow()
  {
    delete gmpdoption;
    Fl::delete_widget(win);
  }
  void showGroup(int num, bool showWindow = true,
                 bool allowMultipleSelections = false);
  void resetBrowser();
  void resetExternalViewList();
  void updateViewGroup(int index);
  // the widget bound to an option (the first, if several), or null
  Fl_Widget *widget(const std::string &option) const;
  // the widgets bound to an option show its value (an option of the views:
  // only for the view shown, num)
  void showOption(const std::string &category, int num,
                  const std::string &name);
  // all the widgets show the values of their options (only those of the
  // category shown, and not the one being edited, if shownOnly)
  void showOptions(bool shownOnly = false);
  // the widgets active or not as the options they depend on are set
  void updateActive();
  void toggleSection(int category, int section);
  // the tab clicked
  void categoryChosen();
  void selectViews(const std::string &which);
  void updateViewTargets();
  // keepPosition keeps the scroll where it is, e.g. when a section is folded
  void layout(bool keepPosition);
};

// the value a check button gives an option that may hold more than 0 and 1
// (as General.SaveOptions = 2): the value it has while the button shows it as
// it is, on or off
double checkValue(Fl_Button *b, double value);
// the range of a value from the table of the ranges of its option (see
// GetOptionRange()), and the step of its scrolling (when
// General.InputScrolling is set)
void optionRange(Fl_Valuator *v, const std::string &option);
// the items of a choice from the table of the choices of its option (see
// GetOptionChoices()), and their values; none if the option has no table
std::vector<double> choiceItems(Fl_Choice *c, const std::string &option);

void options_restore_defaults_cb(Fl_Widget *w, void *data);
// the options of the view of index num shown (of the view shown last, or
// the first, if num is negative)
void showViewOptions(int num);
void general_gmpdcf_cb(Fl_Widget *w, void *data);
void general_rotation_center_cg_cb(Fl_Widget *w, void *data);
void general_options_rotation_center_select_cb(Fl_Widget *w, void *data);
void general_options_axes_fit_cb(Fl_Widget *w, void *data);

#endif
