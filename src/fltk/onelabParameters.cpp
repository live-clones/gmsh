// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Return_Button.H>
#include <FL/fl_ask.H>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "inputRange.h"
#include "outputRange.h"
#include "FlGui.h"
#include "fileDialogs.h"
#include "editorWindow.h"
#include "onelabActions.h"
#include "onelabParameters.h"
#include "gmshScheme.h"
#include "Context.h"
#include "GModel.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "onelabUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "drawContext.h"
#include "PView.h"

// The widgets of the ONELAB parameters (see onelabParameters.h): what each
// does when changed, then how each kind is made.

bool getParameterColor(const std::string &str, Fl_Color &c)
{
  if(str == "1") {
    c = FL_YELLOW;
    return true;
  }
  int r, g, b;
  if(str.size() && GetRGBForString(str.c_str(), r, g, b)) {
    c = fl_rgb_color(r, g, b);
    return true;
  }
  c = FL_BLACK;
  return false;
}

// after a parameter changed in the tree (onelabUtils::setParameter(), which
// says what to do next)
static void parameterChanged(int what)
{
  if(!FlGui::available()) return;
  if(what & onelabUtils::ParameterRebuild) FlGui::instance()->rebuildTree();
  if(what & onelabUtils::ParameterOption) drawContext::global()->draw();
  if(what & onelabUtils::ParameterCheck) onelabCheck();
}

static void onelab_number_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    Fl_Check_Button *o = (Fl_Check_Button *)w;
    numbers[0].setValue(o->value());
    parameterChanged(onelabUtils::setParameter(numbers[0]));
  }
}

static void onelab_number_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    Fl_Choice *o = (Fl_Choice *)w;
    std::vector<double> choices = numbers[0].getChoices();
    if(o->value() >= 0 && o->value() < (int)choices.size())
      numbers[0].setValue(choices[o->value()]);
    parameterChanged(onelabUtils::setParameter(numbers[0]));
  }
}

static void onelab_number_input_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    inputRange *o = (inputRange *)w;
    if(o->doCallbackOnValues()) {
      numbers[0].setValue(o->value());
      numbers[0].setMin(o->minimum());
      numbers[0].setMax(o->maximum());
      numbers[0].setStep(o->step());
      numbers[0].setChoices(o->choices());
    }
    o->doCallbackOnValues(true);
    numbers[0].setAttribute("Loop", o->loop());
    numbers[0].setAttribute("Graph", o->graph());
    int what = onelabUtils::setParameter(numbers[0]);
    onelabUpdateGraphs();
    parameterChanged(what);
  }
}

static void onelab_number_output_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    outputRange *o = (outputRange *)w;
    numbers[0].setAttribute("Graph", o->graph());
    onelab::server::instance()->set(numbers[0]);
    onelabUpdateGraphs();
  }
}

Fl_Widget *addParameterWidget(onelab::number &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings)
{
  strings.push_back(ppath);
  const char *path = strings.back().c_str();

  // enumeration (display choices as value labels, not numbers)
  if(p.getChoices().size() &&
     p.getChoices().size() == p.getValueLabels().size()) {
    Fl_Choice *but = new Fl_Choice(xx, yy, ww, hh);
    std::vector<Fl_Menu_Item> menu;
    std::vector<double> choices = p.getChoices();
    std::map<double, std::string> labels(p.getValueLabels());
    for(std::size_t i = 0; i < choices.size(); i++) {
      strings.push_back(labels[choices[i]]);
      Fl_Menu_Item menuItem = {strings.back().c_str(), 0, nullptr, nullptr, 0};
      if(highlight) menuItem.labelcolor(adaptedText(c));
      menu.push_back(menuItem);
    }
    Fl_Menu_Item it = {nullptr};
    menu.push_back(it);
    but->copy(&menu[0]);
    for(std::size_t i = 0; i < choices.size(); i++) {
      if(p.getValue() == choices[i]) {
        but->value(i);
        break;
      }
    }
    but->callback(onelab_number_choice_cb, (void *)path);
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // check box (boolean choice)
  if(p.getChoices().size() == 2 && p.getChoices()[0] == 0 &&
     p.getChoices()[1] == 1) {
    // n->labelsize(FL_NORMAL_SIZE + 2);
    Fl_Check_Button *but = new Fl_Check_Button(xx, yy, ww / labelRatio, hh);
    but->box(FL_FLAT_BOX);
    but->color(bgc);
    but->value(p.getValue());
    but->callback(onelab_number_check_button_cb, (void *)path);
    but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    if(highlight) {
      but->color(adaptedFill(c));
      but->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
    }
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // non-editable value
  if(p.getReadOnly()) {
    outputRange *but = new outputRange(xx, yy, ww, hh,
                                       onelab::parameter::maxNumber());
    but->callback(onelab_number_output_range_cb, (void *)path);
    but->numberFormat(p.getAttribute("NumberFormat"));
    but->value(p.getValue());
    but->minimum(p.getMin());
    but->maximum(p.getMax());
    but->step(p.getStep());
    but->choices(p.getChoices());
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    but->graph(p.getAttribute("Graph"));
    if(highlight) but->color(adaptedFill(c));
    return but;
  }

  // general number input
  inputRange *but =
    new inputRange(xx, yy, ww, hh, onelab::parameter::maxNumber(),
                   p.getAttribute("ReadOnlyRange") == "1");
  but->numberFormat(p.getAttribute("NumberFormat"));
  but->value(p.getValue());
  but->minimum(p.getMin());
  but->maximum(p.getMax());
  // (the step is kept even when the input does not scroll: see inputRange)
  but->step(p.getStep());
  but->choices(p.getChoices());
  but->loop(p.getAttribute("Loop"));
  but->graph(p.getAttribute("Graph"));
  but->callback(onelab_number_input_range_cb, (void *)path);
  but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight) but->color(adaptedFill(c));
  return but;
}

static void onelab_string_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.empty()) return;
  // a script parsed or a file merged change the model: not during another
  // operation on it
  bool action = strings[0].getAttribute("Macro") == "Action";
  if(!action && modelBusy()) return;
  int what = onelabUtils::runMacro(name);
  if(action) return;
  parameterChanged(what);
  drawContext::global()->draw();
}

static void onelab_string_input_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()) {
    Fl_Input *o = (Fl_Input *)w;
    strings[0].setValue(o->value());
    parameterChanged(onelabUtils::setParameter(strings[0]));
  }
}

static void onelab_string_input_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()) {
    Fl_Input_Choice *o = (Fl_Input_Choice *)w;
    strings[0].setValue(o->value());
    std::string choices;
    for(int i = 0; i < o->menubutton()->menu()->size(); i++) {
      if(o->menubutton()->menu()[i].flags & FL_MENU_TOGGLE) {
        if(o->menubutton()->menu()[i].flags & FL_MENU_VALUE)
          choices += "1";
        else
          choices += "0";
      }
    }
    if(choices.size()) strings[0].setAttribute("MultipleSelection", choices);
    parameterChanged(onelabUtils::setParameter(strings[0]));
  }
}

static void onelab_input_choice_file_chooser_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)w->parent();
  if(fileChooser(FILE_CHOOSER_SINGLE, "Choose", "", but->value())) {
    but->value(fileChooserGetName(1).c_str());
    but->do_callback();
  }
}

static void onelab_input_choice_file_edit_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)w->parent();
  editFile(but->value());
}

static void onelab_input_choice_file_merge_cb(Fl_Widget *w, void *data)
{
  if(modelBusy()) return;
  Fl_Input_Choice *but = (Fl_Input_Choice *)w->parent();
  std::string file = FixWindowsPath(but->value());
  MergeFile(file);
  drawContext::global()->draw();
}

static void multiple_selection_menu_cb(Fl_Widget *w, void *data)
{
  Fl_Menu_Button *menu = (Fl_Menu_Button *)w;
  std::string val;
  for(int i = 0; i < menu->size() - 1; i++) {
    const Fl_Menu_Item &item = menu->menu()[i];
    if(item.value() && item.label()) {
      if(val.size()) val += ", ";
      val += item.label();
    }
  }
  Fl_Input_Choice *but = (Fl_Input_Choice *)data;
  but->value(val.c_str());
  but->do_callback();
}

static void multiple_selection_menu_all_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)data;
  Fl_Menu_Button *menu = but->menubutton();
  std::string val;
  for(int i = 0; i < menu->size() - 1; i++) {
    int mode = menu->mode(i);
    if(mode & FL_MENU_TOGGLE) {
      if(mode & FL_MENU_DIVIDER)
        menu->mode(i, FL_MENU_TOGGLE | FL_MENU_VALUE | FL_MENU_DIVIDER);
      else
        menu->mode(i, FL_MENU_TOGGLE | FL_MENU_VALUE);
      const Fl_Menu_Item &item = menu->menu()[i];
      if(item.label()) {
        if(val.size()) val += ", ";
        val += item.label();
      }
    }
  }
  but->value(val.c_str());
  but->do_callback();
}

static void multiple_selection_menu_none_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)data;
  Fl_Menu_Button *menu = but->menubutton();
  std::string val;
  for(int i = 0; i < menu->size() - 1; i++) {
    int mode = menu->mode(i);
    if(mode & FL_MENU_TOGGLE) {
      if(mode & FL_MENU_DIVIDER)
        menu->mode(i, FL_MENU_TOGGLE | FL_MENU_DIVIDER);
      else
        menu->mode(i, FL_MENU_TOGGLE);
    }
  }
  but->value("");
  but->do_callback();
}

Fl_Widget *addParameterWidget(onelab::string &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings)
{
  strings.push_back(ppath);
  const char *path = strings.back().c_str();

  // macro button
  if(p.getAttribute("Macro") == "Gmsh" ||
     p.getAttribute("Macro") == "GmshMergeFile" ||
     p.getAttribute("Macro") == "GmshParseString" ||
     p.getAttribute("Macro") == "Action") {
    Fl_Button *but;
    if(p.getAttribute("Aspect") == "Button" ||
       p.getAttribute("Aspect") == "LeftButton" ||
       p.getAttribute("Aspect") == "MiddleButton" ||
       p.getAttribute("Aspect") == "RightButton") {
      but = new Fl_Button(xx, yy, ww, hh);
      but->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    else if(p.getAttribute("Aspect") == "ReturnButton" ||
            p.getAttribute("Aspect") == "LeftReturnButton" ||
            p.getAttribute("Aspect") == "MiddleReturnButton" ||
            p.getAttribute("Aspect") == "RightReturnButton") {
      but = new Fl_Return_Button(xx, yy, ww, hh);
      but->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    else {
      but = new Fl_Button(xx, yy, ww / labelRatio, hh);
      but->box(FL_FLAT_BOX);
      but->color(bgc);
      but->selection_color(bgc);
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    but->callback(onelab_string_button_cb, (void *)path);
    if(highlight) {
      but->color(adaptedFill(c));
      but->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
    }
    return but;
  }

  // non-editable value
  if(p.getReadOnly() && p.getKind() != "file") {
    Fl_Output *but = new Fl_Output(xx, yy, ww, hh);
    but->value(p.getValue().c_str());
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    if(highlight) {
      but->color(adaptedFill(c));
      but->textcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
    }
    return but;
  }

  // simple string (no menu)
  if(p.getChoices().empty() && p.getKind() != "file") {
    Fl_Input *but = new Fl_Input(xx, yy, ww, hh);
    but->value(p.getValue().c_str());
    but->callback(onelab_string_input_cb, (void *)path);
    but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    if(highlight) {
      but->color(adaptedFill(c));
      but->textcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
    }
    return but;
  }

  // general string input
  Fl_Input_Choice *but = new Fl_Input_Choice(xx, yy, ww, hh);
  std::string multipleSelection = p.getAttribute("MultipleSelection");
  if(multipleSelection.size())
    but->menubutton()->callback(multiple_selection_menu_cb, but);
  std::vector<Fl_Menu_Item> menu;
  for(std::size_t j = 0; j < p.getChoices().size(); j++) {
    strings.push_back(p.getChoices()[j]);
    const char *str = strings.back().c_str();
    bool divider = ((p.getKind() == "file" || multipleSelection.size()) &&
                    j == p.getChoices().size() - 1);
    int choice = multipleSelection.size() ? FL_MENU_TOGGLE : 0;
    if(multipleSelection.size() > j && multipleSelection[j] == '1')
      choice |= FL_MENU_VALUE;
    Fl_Menu_Item it = {str, 0, nullptr, nullptr,
                       (int)(choice | (divider ? FL_MENU_DIVIDER : 0))};
    menu.push_back(it);
  }
  if(multipleSelection.size()) {
    Fl_Menu_Item it = {"Select All", 0, multiple_selection_menu_all_cb, but};
    menu.push_back(it);
    Fl_Menu_Item it2 = {"Select None", 0, multiple_selection_menu_none_cb, but};
    menu.push_back(it2);
  }
  if(p.getKind() == "file") {
    if(!p.getReadOnly()) {
      Fl_Menu_Item it = {"Choose File...", 0,
                         onelab_input_choice_file_chooser_cb};
      menu.push_back(it);
    }
    Fl_Menu_Item it2 = {"Edit Selected File...", 0,
                        onelab_input_choice_file_edit_cb};
    menu.push_back(it2);
    if(GuessFileFormatFromFileName(p.getValue()) >= 0) {
      Fl_Menu_Item it3 = {"Merge Selected File...", 0,
                          onelab_input_choice_file_merge_cb};
      menu.push_back(it3);
    }
  }
  Fl_Menu_Item it = {nullptr};
  menu.push_back(it);
  but->menubutton()->copy(&menu[0]);
  but->value(p.getValue().c_str());
  but->callback(onelab_string_input_choice_cb, (void *)path);
  but->input()->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  // and the widget calls back on both: FLTK 1.5 passes on an Enter only with
  // FL_WHEN_CHANGED (on the menu, its choices call back as before)
  but->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);
  but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight) {
    but->input()->color(adaptedFill(c));
    but->input()->textcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
  }
  return but;
}

