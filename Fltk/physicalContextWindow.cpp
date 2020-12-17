// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "GModel.h"
#include "Context.h"
#include "StringUtils.h"
#include "Geo.h"
#include "FlGui.h"
#include "drawContext.h"
#include "paletteWindow.h"
#include "physicalContextWindow.h"
#include "onelab.h"
#include "onelabGroup.h"

// callbacks for the widgets in the "Add" and "Remove" tabs, which select a
// physical group based on its name and/or tag

static void physical_add_cb(Fl_Widget *w, void *data)
{
  std::string what = data ? (const char *)data : "";

  physicalContextWindow *pc = FlGui::instance()->physicalContext;
  std::string name = pc->input[0]->value();
  int tag = pc->value[0]->value();
  std::string existingName = "";
  int existingTag = 0;
  if(what != "Tag") {
    auto it = pc->physicalNames.find(name);
    if(it != pc->physicalNames.end()) {
      existingName = name;
      existingTag = it->second;
    }
  }
  if(what != "Name") {
    auto it = pc->physicalTags.find(tag);
    if(it != pc->physicalTags.end()) {
      existingTag = tag;
      existingName = it->second;
    }
  }

  if(existingName.size() || existingTag) {
    // change color to warn that the group exists
    Fl_Color c = (!CTX::instance()->guiColorScheme ? FL_DARK_BLUE : FL_BLUE);
    pc->input[0]->textcolor(c);
    pc->value[0]->textcolor(c);
    if(what != "Name" && !strlen(pc->input[0]->value()))
      pc->input[0]->value(existingName.c_str());
    if(what != "Tag") pc->value[0]->value(existingTag);
    pc->append = true;
  }
  else {
    pc->input[0]->textcolor(FL_FOREGROUND_COLOR);
    pc->value[0]->textcolor(FL_FOREGROUND_COLOR);
    if(what != "Tag") pc->value[0]->value(NEWPHYSICAL());
    pc->append = false;
  }

  if(pc->butt[0]->active()) {
    if(pc->butt[0]->value())
      pc->value[0]->deactivate();
    else
      pc->value[0]->activate();
  }

  pc->input[0]->redraw();
  pc->value[0]->redraw();

  pc->selectedTag = pc->value[0]->value();
  pc->selectedName = pc->input[0]->value();
}

static void physical_remove_cb(Fl_Widget *w, void *data)
{
  physicalContextWindow *pc = FlGui::instance()->physicalContext;
  if(pc->choice[0]->text()) {
    std::vector<std::string> tmp = SplitString(pc->choice[0]->text(), ':');
    pc->selectedTag = (tmp.size() > 0) ? atoi(tmp[0].c_str()) : 0;
    pc->selectedName = (tmp.size() > 1) ? tmp[1] : "";
  }
  else {
    pc->selectedTag = 0;
    pc->selectedName = "";
  }
}

physicalContextWindow::physicalContextWindow(int deltaFontSize)
  : dim(-1), selectedTag(0), mode("Add"), selectedName(""), append(false)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  _width = 30 * FL_NORMAL_SIZE;
  _height = 5 * WB + 4 * BH;

  win = new paletteWindow(_width, _height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Physical Group Context");
  win->box(GMSH_WINDOW_BOX);

  {
    tab = new Fl_Tabs(WB, WB, _width - 2 * WB, 4 * BH + 3 * WB);
    // 0: Add
    {
      group[0] =
        new Fl_Group(WB, WB + BH, _width - 2 * WB, 3 * BH + 3 * WB, "Add");

      box[0] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, _width, BH);
      box[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      input[0] = new Fl_Input_Choice(2 * WB, 2 * WB + 2 * BH,
                                     (int)(0.6 * _width), BH, "Name");
      input[0]->value("");
      input[0]->align(FL_ALIGN_RIGHT);
      input[0]->callback(physical_add_cb, (void *)"Name");
      input[0]->when(FL_WHEN_CHANGED);

      value[0] = new Fl_Value_Input(2 * WB, 2 * WB + 3 * BH,
                                    (int)(0.6 * _width), BH, "Tag");
      value[0]->value(0);
      value[0]->deactivate();
      value[0]->align(FL_ALIGN_RIGHT);
      value[0]->callback(physical_add_cb, (void *)"Tag");
      value[0]->when(FL_WHEN_CHANGED);

      butt[0] = new Fl_Check_Button(_width - _width / 4, 2 * WB + 3 * BH,
                                    _width / 4 - 2 * WB, BH, "Automatic");
      butt[0]->value(1);
      butt[0]->callback(physical_add_cb);

      group[0]->end();
    }
    // 1: Remove
    {
      group[1] =
        new Fl_Group(WB, WB + BH, _width - 2 * WB, 3 * BH + 3 * WB, "Remove");

      box[1] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, _width, BH);
      box[1]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      choice[0] =
        new Fl_Choice(2 * WB, 2 * WB + 2 * BH, (int)(0.6 * _width), BH);
      choice[0]->align(FL_ALIGN_RIGHT);
      choice[0]->callback(physical_remove_cb);

      group[1]->end();
    }
    tab->end();
  }

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void physicalContextWindow::show(const std::string &what, bool remove)
{
  FlGui::instance()->lastContextWindow = 3;

  // update window title and labels
  if(what == "Volume") dim = 3;
  else if(what == "Surface") dim = 2;
  else if(what == "Curve") dim = 1;
  else if(what == "Point") dim = 0;
  else {
    Msg::Error("Unknown physical context '%s'", what.c_str());
    return;
  }
  win->copy_label(std::string("Physical " + what + " Context").c_str());
  std::string s(" and select " + what + "(s) to ");
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  box[0]->copy_label(std::string("Create or choose group," + s + "add").c_str());
  box[1]->copy_label(std::string("Choose group" + s + "remove").c_str());

  // get all physical group tags and names (this is relatively expensive - so we
  // shouldn't do it in the callbacks)
  std::map<int, std::vector<GEntity *> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  physicalTags.clear();
  physicalNames.clear();
  for(auto &p : groups) {
    std::string name = GModel::current()->getPhysicalName(dim, p.first);
    physicalTags[p.first] = name;
    if(name.size()) physicalNames[name] = p.first;
  }

  // create menus with existing physicals
  std::vector<Fl_Menu_Item> menuAdd, menuRemove;
  static std::vector<char *> toFree;
  for(std::size_t i = 0; i < toFree.size(); i++) free(toFree[i]);
  toFree.clear();
  {
    for(auto &p : physicalNames) {
      char *str = strdup(p.first.c_str());
      Fl_Menu_Item item = {str, 0, 0, 0, 0};
      toFree.push_back(str);
      menuAdd.push_back(item);
    }
    Fl_Menu_Item item = {0};
    menuAdd.push_back(item);
    input[0]->menubutton()->copy(&menuAdd[0]);
  }
  {
    for(auto &p : physicalTags) {
      std::string label = std::to_string(p.first);
      if(p.second.size()) label += ": " + p.second;
      char *str = strdup(label.c_str());
      Fl_Menu_Item item = {str, 0, 0, 0, 0};
      toFree.push_back(str);
      menuRemove.push_back(item);
    }
    Fl_Menu_Item item = {0};
    menuRemove.push_back(item);
    choice[0]->copy(&menuRemove[0]);
  }

  // activate the relevant tabs and widgets
  for(int i = 0; i < 2; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }
  if(remove) {
    mode = "Remove";
    group[1]->show();
    group[1]->activate();
    physical_remove_cb(0, 0);
  }
  else {
    mode = "Add";
    group[0]->show();
    group[0]->activate();
    if(butt[0]->value())
      value[0]->deactivate();
    else
      value[0]->activate();
    physical_add_cb(0, (void *)"Name");
  }

  // create the ONELAB widgets (if any)
  updateOnelabWidgets(true);

  if(!win->shown()) win->show();
}

void physicalContextWindow::updateOnelabWidgets(bool deleteWidgets)
{
  // delete widgets if requested (as this is called every time the main ONELAB
  // tree is rebuilt)
  static std::vector<char *> toFree;
  for(auto &w : onelabWidgets) w->hide();
  if(deleteWidgets) {
    for(auto &w : onelabWidgets) Fl::delete_widget(w);
    onelabWidgets.clear();
    for(std::size_t i = 0; i < toFree.size(); i++) free(toFree[i]);
    toFree.clear();
  }

  // TODO: get all ONELAB parameters matching some "template" name or attribute,
  // for the given dimension
  std::vector<onelab::number> pn;
  onelab::server::instance()->get(pn);
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps);

  // TODO: check if the parameters exist for the currently selected physical
  // group: if they do, show the current values; if not, create and add the
  // parameter in the ONELAB server

  // TODO: we should use a widget container that allows to sort them according
  // to their name (path)

  int h = _height;
  for(auto &p : pn) {
    Fl_Widget *w =
      addParameterWidget(p, WB, h, _width / 2, BH, 1., p.getName(), false,
                         FL_FOREGROUND_COLOR, FL_BACKGROUND_COLOR, toFree);
    w->copy_label(p.getShortName().c_str());
    std::string help = p.getHelp();
    if(help.empty()) help = p.getLabel();
    if(help.empty()) help = p.getShortName();
    w->copy_tooltip(help.c_str());

    h += BH;
    onelabWidgets.push_back(w);
    win->add(w);
  }
  if(pn.size()) h += WB;

  win->resize(win->x(), win->y(), win->w(), h);
}
