// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "GModel.h"
#include "Context.h"
#include "Geo.h"
#include "FlGui.h"
#include "drawContext.h"
#include "paletteWindow.h"
#include "physicalGroupWindow.h"

static void physical_cb(Fl_Widget *w, void *data)
{
  std::string what;
  if(!data)
    what = "";
  else
    what = (const char *)data;

  std::string name = FlGui::instance()->physicalGroup->input[0]->value();
  int number = FlGui::instance()->physicalGroup->value[0]->value();

  std::string existingName = "";
  int existingNumber = 0;
  if(what != "Number") {
    for(GModel::piter it = GModel::current()->firstPhysicalName();
        it != GModel::current()->lastPhysicalName(); it++) {
      if(it->second == name) {
        existingName = name;
        existingNumber = it->first.second;
        break;
      }
    }
  }
  if(what != "Name") {
    std::map<int, std::vector<GEntity *> > groups[4];
    GModel::current()->getPhysicalGroups(groups);
    for(int i = 0; i < 4; i++) {
      for(std::map<int, std::vector<GEntity *> >::iterator it =
            groups[i].begin();
          it != groups[i].end(); it++) {
        if(it->first == number) {
          existingNumber = number;
          existingName = GModel::current()->getPhysicalName(i, number);
          break;
        }
      }
    }
  }

  if(existingName.size() || existingNumber) {
    FlGui::instance()->physicalGroup->input[0]->textcolor(
      FlGui::instance()->physicalGroup->color);
    FlGui::instance()->physicalGroup->value[0]->textcolor(
      FlGui::instance()->physicalGroup->color);
    if(what != "Name" &&
       !strlen(FlGui::instance()->physicalGroup->input[0]->value()))
      FlGui::instance()->physicalGroup->input[0]->value(existingName.c_str());
    if(what != "Number")
      FlGui::instance()->physicalGroup->value[0]->value(existingNumber);
    FlGui::instance()->physicalGroup->append = true;
  }
  else {
    FlGui::instance()->physicalGroup->input[0]->textcolor(
      FL_FOREGROUND_COLOR);
    FlGui::instance()->physicalGroup->value[0]->textcolor(
      FL_FOREGROUND_COLOR);
    if(what != "Number" && FlGui::instance()->physicalGroup->mode != "Remove")
      FlGui::instance()->physicalGroup->value[0]->value(NEWPHYSICAL());
    FlGui::instance()->physicalGroup->append = false;
  }

  if(FlGui::instance()->physicalGroup->butt[0]->active()) {
    if(FlGui::instance()->physicalGroup->butt[0]->value())
      FlGui::instance()->physicalGroup->value[0]->deactivate();
    else
      FlGui::instance()->physicalGroup->value[0]->activate();
  }

  FlGui::instance()->physicalGroup->input[0]->redraw();
  FlGui::instance()->physicalGroup->value[0]->redraw();
}

physicalGroupWindow::physicalGroupWindow(int deltaFontSize)
  : mode("Add"), append(false), color(FL_RED)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 28 * FL_NORMAL_SIZE;
  int height = 2 * WB + 3 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Physical Group Context");
  win->box(GMSH_WINDOW_BOX);
  {
    input[0] = new Fl_Input_Choice(WB, WB, (3 * width) / 4, BH, "Name");
    input[0]->value("");
    input[0]->align(FL_ALIGN_RIGHT);
    input[0]->callback(physical_cb, (void *)"Name");
    input[0]->when(FL_WHEN_CHANGED);

    butt[0] = new Fl_Check_Button(WB, WB + BH, width - 2 * WB, BH,
                                  "Automatic numbering");
    butt[0]->value(1);
    butt[0]->callback(physical_cb);

    value[0] =
      new Fl_Value_Input(WB, WB + 2 * BH, (3 * width) / 4, BH, "Number");
    value[0]->value(0);
    value[0]->deactivate();
    value[0]->align(FL_ALIGN_RIGHT);
    value[0]->callback(physical_cb, (void *)"Number");
    value[0]->when(FL_WHEN_CHANGED);
  }

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void physicalGroupWindow::show(bool remove)
{
  static std::vector<Fl_Menu_Item> menu;
  static std::vector<char *> names;
  for(std::size_t i = 0; i < menu.size(); i++) menu[i].text = "";
  for(std::size_t i = 0; i < names.size(); i++) free(names[i]);
  names.clear();
  menu.clear();
  for(GModel::piter it = GModel::current()->firstPhysicalName();
      it != GModel::current()->lastPhysicalName(); it++) {
    char *str = strdup(it->second.c_str());
    Fl_Menu_Item item = {str, 0, 0, 0, 0};
    names.push_back(str);
    menu.push_back(item);
  }
  Fl_Menu_Item item = {0};
  menu.push_back(item);
  input[0]->menubutton()->copy(&menu[0]);

  if(remove) {
    mode = "Remove";
    butt[0]->deactivate();
    value[0]->activate();
    color = (!CTX::instance()->guiColorScheme ? FL_DARK_GREEN : FL_GREEN);
  }
  else {
    mode = "Add";
    butt[0]->activate();
    if(butt[0]->value())
      value[0]->deactivate();
    else
      value[0]->activate();
    color = (!CTX::instance()->guiColorScheme ? FL_DARK_RED : FL_RED);
  }
  physical_cb(0, (void *)"Name");
  if(!win->shown()) win->show();
}
