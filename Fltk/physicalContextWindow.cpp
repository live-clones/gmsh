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

static void physical_add_cb(Fl_Widget *w, void *data)
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

  physicalContextWindow *pc = FlGui::instance()->physicalContext;

  if(existingName.size() || existingTag) {
    // change color to warn that the group exists
    Fl_Color c = (!CTX::instance()->guiColorScheme ? FL_DARK_BLUE : FL_BLUE);
    pc->input[0]->textcolor(c);
    pc->value[0]->textcolor(c);
    if(what != "Name" && !strlen(pc->input[0]->value()))
      pc->input[0]->value(existingName.c_str());
    if(what != "Tag")
      pc->value[0]->value(existingTag);
    pc->append = true;
  }
  else {
    pc->input[0]->textcolor(FL_FOREGROUND_COLOR);
    pc->value[0]->textcolor(FL_FOREGROUND_COLOR);
    if(what != "Tag")
      pc->value[0]->value(NEWPHYSICAL());
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
}

void physicalContextWindow::updateOnelabWidgets()
{
  // TOOD

  //win->resize(win->x(), win->y(), win->w(), win->h() + 10);
}

physicalContextWindow::physicalContextWindow(int deltaFontSize)
  : mode("Add"), append(false)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 30 * FL_NORMAL_SIZE;
  int height = 5 * WB + 4 * BH;

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

      box[0] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, width, BH);
      box[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      input[0] = new Fl_Input_Choice(2 * WB, 2 * WB + 2 * BH,
                                     (int)(0.6 * width), BH, "Name");
      input[0]->value("");
      input[0]->align(FL_ALIGN_RIGHT);
      input[0]->callback(physical_add_cb, (void *)"Name");
      input[0]->when(FL_WHEN_CHANGED);

      value[0] =
        new Fl_Value_Input(2 * WB, 2 * WB + 3 * BH, (int)(0.6 * width), BH, "Tag");
      value[0]->value(0);
      value[0]->deactivate();
      value[0]->align(FL_ALIGN_RIGHT);
      value[0]->callback(physical_add_cb, (void *)"Tag");
      value[0]->when(FL_WHEN_CHANGED);

      butt[0] = new Fl_Check_Button(width - width / 4, 2 * WB + 3 * BH,
                                    width / 4 - 2 * WB, BH, "Automatic");
      butt[0]->value(1);
      butt[0]->callback(physical_add_cb);

      group[0]->end();
    }
    // 1: Remove
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 2 * WB - 1 * BH, "Remove");

      box[1] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, width, BH);
      box[1]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      choice[0] = new Fl_Choice(2 * WB, 2 * WB + 2 * BH,
                                (int)(0.6 * width), BH, "Group");
      choice[0]->align(FL_ALIGN_RIGHT);
      //choice[0]->callback(physical_remove_cb, (void *)"Name");

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

  // update window title and labels
  int dim = (what == "Volume") ? 3 : (what == "Surface") ? 2 :
    (what == "Curve") ? 1 : (what == "Point") ? 0 : -1;
  if(dim < 0) {
    Msg::Error("Unknown physical context '%s'", what.c_str());
    return;
  }
  win->copy_label(std::string("Physical " + what + " Context").c_str());
  std::string ent(what + "(s)");
  std::transform(ent.begin(), ent.end(), ent.begin(), ::tolower);
  box[0]->copy_label
    (std::string("Create or choose group, and select " + ent + " to add").c_str());
  box[1]->copy_label
    (std::string("Choose group and select " + ent + " to remove").c_str());

  // get all physical group tags and names (this is relatively expensive - so we
  // shouldn't do it in the callback)
  std::map<int, std::vector<GEntity *> > groups[4];
  GModel::current()->getPhysicalGroups(groups);
  physicalTags.clear();
  physicalNames.clear();
  for(int dim = 0; dim < 4; dim++) {
    for(auto &p : groups[dim]) {
      std::pair<int, int> dimTag(dim, p.first);
      std::string name = GModel::current()->getPhysicalName(dim, p.first);
      physicalTags[dimTag] = name;
      if(name.size()) physicalNames[name] = dimTag;
    }
  }

  // create menu with existing physical names for the given dimension
  std::vector<Fl_Menu_Item> menuAdd, menuRemove;
  static std::vector<char *> toFree;
  for(std::size_t i = 0; i < toFree.size(); i++) free(toFree[i]);
  toFree.clear();
  {
    for(auto &p : physicalNames) {
      if(p.second.first == dim) {
        char *str = strdup(p.first.c_str());
        Fl_Menu_Item item = {str, 0, 0, 0, 0};
        toFree.push_back(str);
        menuAdd.push_back(item);
      }
    }
    Fl_Menu_Item item = {0};
    menuAdd.push_back(item);
    input[0]->menubutton()->copy(&menuAdd[0]);
  }
  {
    for(auto &p : physicalTags) {
      if(p.first.first == dim) {
        std::string label = std::to_string(p.first.second);
        if(p.second.size()) label += ": " + p.second;
        char *str = strdup(label.c_str());
        Fl_Menu_Item item = {str, 0, 0, 0, 0};
        toFree.push_back(str);
        menuRemove.push_back(item);
      }
    }
    Fl_Menu_Item item = {0};
    menuRemove.push_back(item);
    choice[0]->copy(&menuRemove[0]);
  }

  for(int i = 0; i < 2; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }

  if(remove) {
    mode = "Remove";
    group[1]->show();
    group[1]->activate();
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

  updateOnelabWidgets();

  if(!win->shown()) win->show();
}
