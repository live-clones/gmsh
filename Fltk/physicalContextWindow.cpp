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
#include "physicalContextWindow.h"
#include "onelab.h"

static void getExistingPhysicalTagName(const std::string &what,
                                       const std::string &name,
                                       const int tag,
                                       std::string &existingName,
                                       int &existingTag)
{
  existingName = "";
  existingTag = 0;
  if(what != "Tag") {
    for(GModel::piter it = GModel::current()->firstPhysicalName();
        it != GModel::current()->lastPhysicalName(); it++) {
      if(it->second == name) {
        existingName = name;
        existingTag = it->first.second;
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
        if(it->first == tag) {
          existingTag = tag;
          existingName = GModel::current()->getPhysicalName(i, tag);
          break;
        }
      }
    }
  }
}

static void physical_cb(Fl_Widget *w, void *data)
{
  std::string what;
  if(!data)
    what = "";
  else
    what = (const char *)data;

  std::string name = FlGui::instance()->physicalContext->input[0]->value();
  int tag = FlGui::instance()->physicalContext->value[0]->value();

  std::string existingName;
  int existingTag;
  getExistingPhysicalTagName(what, name, tag, existingName, existingTag);

  if(existingName.size() || existingTag) {
    FlGui::instance()->physicalContext->input[0]->textcolor(
      FlGui::instance()->physicalContext->color);
    FlGui::instance()->physicalContext->value[0]->textcolor(
      FlGui::instance()->physicalContext->color);
    if(what != "Name" &&
       !strlen(FlGui::instance()->physicalContext->input[0]->value()))
      FlGui::instance()->physicalContext->input[0]->value(existingName.c_str());
    if(what != "Tag")
      FlGui::instance()->physicalContext->value[0]->value(existingTag);
    FlGui::instance()->physicalContext->append = true;
  }
  else {
    FlGui::instance()->physicalContext->input[0]->textcolor(
      FL_FOREGROUND_COLOR);
    FlGui::instance()->physicalContext->value[0]->textcolor(
      FL_FOREGROUND_COLOR);
    if(what != "Tag" && FlGui::instance()->physicalContext->mode != "Remove")
      FlGui::instance()->physicalContext->value[0]->value(NEWPHYSICAL());
    FlGui::instance()->physicalContext->append = false;
  }

  if(FlGui::instance()->physicalContext->butt[0]->active()) {
    if(FlGui::instance()->physicalContext->butt[0]->value())
      FlGui::instance()->physicalContext->value[0]->deactivate();
    else
      FlGui::instance()->physicalContext->value[0]->activate();
  }

  FlGui::instance()->physicalContext->input[0]->redraw();
  FlGui::instance()->physicalContext->value[0]->redraw();
}

void physicalContextWindow::updateOnelabWidgets()
{
  printf("updating onelab widgets\n");

  //win->resize(win->x(), win->y(), win->w(), win->h() + 10);
}

physicalContextWindow::physicalContextWindow(int deltaFontSize)
  : mode("Add"), append(false), color(FL_RED)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 34 * FL_NORMAL_SIZE;
  int height = 5 * WB + 6 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Physical Group Context");
  win->box(GMSH_WINDOW_BOX);
  {
    tab = new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
    // 0: Add
    {
      group[0] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 2 * WB - 1 * BH, "Add");

      input[0] = new Fl_Input_Choice(2 * WB, 2 * WB + 1 * BH,
                                     (int)(0.6 * width), BH, "Name");
      input[0]->value("");
      input[0]->align(FL_ALIGN_RIGHT);
      input[0]->callback(physical_cb, (void *)"Name");
      input[0]->when(FL_WHEN_CHANGED);

      value[0] =
        new Fl_Value_Input(2 * WB, 2 * WB + 2 * BH, (int)(0.6 * width), BH, "Tag");
      value[0]->value(0);
      value[0]->deactivate();
      value[0]->align(FL_ALIGN_RIGHT);
      value[0]->callback(physical_cb, (void *)"Tag");
      value[0]->when(FL_WHEN_CHANGED);

      butt[0] = new Fl_Check_Button(width - width / 4, 2 * WB + 2 * BH,
                                    width / 4 - 2 * WB, BH, "Automatic");
      butt[0]->value(1);
      butt[0]->callback(physical_cb);

      group[0]->end();
    }
    // 1: Remove
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 2 * WB - 1 * BH, "Remove");

      // TODO

      group[1]->end();
    }

  }

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void physicalContextWindow::show(const std::string &what, bool remove)
{
  FlGui::instance()->lastContextWindow = 3;

  // update window title
  int dim = (what == "Volume") ? 3 : (what == "Surface") ? 2 :
    (what == "Curve") ? 1 : (what == "Point") ? 0 : -1;
  if(dim < 0) {
    Msg::Error("Unknown physical context '%s'", what.c_str());
    return;
  }
  win->copy_label(std::string("Physical " + what + " Context").c_str());

  // create menu with existing physical names for the given dimension
  static std::vector<Fl_Menu_Item> menu;
  static std::vector<char *> names;
  for(std::size_t i = 0; i < menu.size(); i++) menu[i].text = "";
  for(std::size_t i = 0; i < names.size(); i++) free(names[i]);
  names.clear();
  menu.clear();
  for(GModel::piter it = GModel::current()->firstPhysicalName();
      it != GModel::current()->lastPhysicalName(); it++) {
    if(it->first.first == dim) {
      char *str = strdup(it->second.c_str());
      Fl_Menu_Item item = {str, 0, 0, 0, 0};
      names.push_back(str);
      menu.push_back(item);
    }
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

  updateOnelabWidgets();

  if(!win->shown()) win->show();
}
