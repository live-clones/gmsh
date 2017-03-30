// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "FlGui.h"
#include "drawContext.h"
#include "contextWindow.h"
#include "paletteWindow.h"
#include "GModel.h"
#include "Parser.h"
#include "GeoStringInterface.h"
#include "OpenFile.h"
#include "Context.h"
#include "MallocUtils.h"

static void elementary_add_parameter_cb(Fl_Widget *w, void *data)
{
  add_param(FlGui::instance()->elementaryContext->input[0]->value(),
            FlGui::instance()->elementaryContext->input[1]->value(),
            FlGui::instance()->elementaryContext->input[2]->value(),
            FlGui::instance()->elementaryContext->input[3]->value(),
            GModel::current()->getFileName());
  FlGui::instance()->resetVisibility();
  FlGui::instance()->rebuildTree(true);
}

static void elementary_add_point_cb(Fl_Widget *w, void *data)
{
  add_point(GModel::current()->getFileName(),
            FlGui::instance()->elementaryContext->input[4]->value(),
            FlGui::instance()->elementaryContext->input[5]->value(),
            FlGui::instance()->elementaryContext->input[6]->value(),
            FlGui::instance()->elementaryContext->input[7]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void elementary_add_circle_cb(Fl_Widget *w, void *data)
{
  add_circle(GModel::current()->getFileName(),
             FlGui::instance()->elementaryContext->input[8]->value(),
             FlGui::instance()->elementaryContext->input[9]->value(),
             FlGui::instance()->elementaryContext->input[10]->value(),
             FlGui::instance()->elementaryContext->input[11]->value(),
             FlGui::instance()->elementaryContext->input[12]->value(),
             FlGui::instance()->elementaryContext->input[13]->value());
  FlGui::instance()->resetVisibility();
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void elementary_switch_tabs_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->elementaryContext->tab1->visible()){
    FlGui::instance()->elementaryContext->tab1->hide();
    FlGui::instance()->elementaryContext->tab2->show();
  }
  else{
    FlGui::instance()->elementaryContext->tab2->hide();
    FlGui::instance()->elementaryContext->tab1->show();
  }
}

static void elementary_snap_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->geom.snap[0] = FlGui::instance()->elementaryContext->value[0]->value();
  CTX::instance()->geom.snap[1] = FlGui::instance()->elementaryContext->value[1]->value();
  CTX::instance()->geom.snap[2] = FlGui::instance()->elementaryContext->value[2]->value();
}

elementaryContextWindow::elementaryContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 31 * FL_NORMAL_SIZE;
  int height = 4 * WB + 8 * BH;

  win = new paletteWindow(width, height, CTX::instance()->nonModalWindows ? true : false,
                          "Elementary Entity Context");
  win->box(GMSH_WINDOW_BOX);
  {
    tab1 = new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
    // 0: Parameter
    {
      group[0] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Parameter");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Name");
      input[0]->value("lc");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Value");
      input[1]->value("0.1");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Label");
      input[2]->value("");
      input[3] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Path");
      input[3]->value("Parameters");
      for(int i = 0; i < 4; i++)   input[i]->align(FL_ALIGN_RIGHT);
      {
        Fl_Return_Button *o = new Fl_Return_Button
          (width - BB - 2 * WB, 2 * WB + 7 * BH, BB, BH, "Add");
        o->callback(elementary_add_parameter_cb);
      }
      group[0]->end();
    }
    // 1: Point
    {
      group[1] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Point");
      input[4] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X coordinate");
      input[4]->value("0");
      input[5] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y coordinate");
      input[5]->value("0");
      input[6] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z coordinate");
      input[6]->value("0");
      input[7] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH,
                              "Prescribed mesh element size at point");
      input[7]->value("1.0");
      for(int i = 4; i < 8; i++)
        input[i]->align(FL_ALIGN_RIGHT);

      for(int i = 0; i < 3; i++)
        _butt[i] = new Fl_Check_Button
          (width - 2 * WB - IW, 2 * WB + (i+1) * BH, IW, BH, "Freeze");

      value[0] = new Fl_Value_Input(2 * WB, 2 * WB + 5 * BH, IW/3, BH);
      value[1] = new Fl_Value_Input(2 * WB + IW/3, 2 * WB + 5 * BH, IW/3, BH);
      value[2] = new Fl_Value_Input(2 * WB + 2*IW/3, 2 * WB + 5 * BH, IW/3, BH,
                                    "Snapping grid spacing");
      for(int i = 0; i < 3; i++) {
        value[i]->align(FL_ALIGN_RIGHT);
        value[i]->callback(elementary_snap_cb);
      }
      {
        Fl_Return_Button *o = new Fl_Return_Button
          (width - BB - 2 * WB, 2 * WB + 7 * BH, BB, BH, "Add");
        o->callback(elementary_add_point_cb);
      }
      group[1]->end();
    }
    // 2: Circle
    {
      group[2] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Circle");
      input[8] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X coordinate");
      input[8]->value("0");
      input[9] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y coordinate");
      input[9]->value("0");
      input[10] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z coordinate");
      input[10]->value("0");
      input[11] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Radius");
      input[11]->value("1");
      input[12] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Angle 1");
      input[12]->value("");
      input[13] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Angle 2");
      input[13]->value("");
      for(int i = 8; i < 14; i++)
        input[i]->align(FL_ALIGN_RIGHT);
      {
        Fl_Return_Button *o = new Fl_Return_Button
          (width - BB - 2 * WB, 2 * WB + 7 * BH, BB, BH, "Add");
        o->callback(elementary_add_circle_cb);
      }
      group[2]->end();
    }
    // 3: Ellipse
    {
      group[3] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Ellipse");
      input[14] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X coordinate");
      input[14]->value("0");
      input[15] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y coordinate");
      input[15]->value("0");
      input[16] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z coordinate");
      input[16]->value("0");
      input[17] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "X radius");
      input[17]->value("1");
      input[18] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Y radius");
      input[18]->value("0.5");
      input[19] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Angle 1");
      input[19]->value("");
      input[20] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Angle 2");
      input[20]->value("");
      for(int i = 14; i < 21; i++)
        input[i]->align(FL_ALIGN_RIGHT);
      group[3]->end();
    }
    // 4: Disk
    {
      group[4] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Disk");
      input[21] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X coordinate");
      input[21]->value("0");
      input[22] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y coordinate");
      input[22]->value("0");
      input[23] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z coordinate");
      input[23]->value("0");
      input[24] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "X radius");
      input[24]->value("1");
      input[25] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Y radius");
      input[25]->value("0.5");
      for(int i = 21; i < 26; i++)
        input[i]->align(FL_ALIGN_RIGHT);
      group[4]->end();
    }
    // 5: Rectangle
    {
      group[5] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Rectangle");
      input[26] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Bottom left X coordinate");
      input[26]->value("0");
      input[27] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Bottom left Y coordinate");
      input[27]->value("0");
      input[28] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Bottom left Z coordinate");
      input[28]->value("0");
      input[29] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Width");
      input[29]->value("1");
      input[30] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Height");
      input[30]->value("0.5");
      input[31] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Rounded radius");
      input[31]->value("");
      for(int i = 26; i < 32; i++)
        input[i]->align(FL_ALIGN_RIGHT);
      group[5]->end();
    }
    tab1->end();
  }
  {
    tab2 = new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
    // 6: Sphere
    {
      group[6] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Sphere");
      group[6]->end();
    }
    // 7: Cylinder
    {
      group[7] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Wedge");
      group[7]->end();
    }
    // 8: Block
    {
      group[8] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Block");
      group[8]->end();
    }
    // 9: Torus
    {
      group[9] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Torus");
      group[9]->end();
    }
    // 10: Cone
    {
      group[10] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Cone");
      group[10]->end();
    }
    // 11: Wedge
    {
      group[11] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Wedge");
      group[11]->end();
    }
    tab2->end();
  }

  {
    Fl_Button *o = new Fl_Button(width - 4 * WB, WB, 3*WB, 3*WB, "...");
    o->callback(elementary_switch_tabs_cb);
  }

  tab1->show();
  tab2->hide();

  win->position(CTX::instance()->ctxPosition[0], CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

bool elementaryContextWindow::frozenPointCoord(int coord)
{
  if(coord < 0 || coord > 2) return false;
  return _butt[coord]->value() ? true : false;
}

void elementaryContextWindow::updatePoint(double pt[3], int which)
{
  for(int i = 0; i < 3; i++){
    if(!frozenPointCoord(i)){
      char str[32];
      sprintf(str, "%g", pt[i]);
      if(which == 1){
        input[4 + i]->value(str);
        input[8 + i]->value(str);
      }
    }
  }
}

void elementaryContextWindow::show(int pane)
{
  if(pane < 0 || pane > 10) return;

  for(int i = 0; i < 11; i++)
    group[i]->hide();

  if(pane < 6){
    tab1->show();
    tab2->hide();
  }
  else{
    tab1->hide();
    tab2->show();
  }

  group[pane]->show();
  win->show();
}

transformContextWindow::transformContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 31 * FL_NORMAL_SIZE;
  int height = 4 * WB + 8 * BH;

  win = new paletteWindow(width, height, CTX::instance()->nonModalWindows ? true : false,
                          "Transformation Context");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
    // 0: Translation
    {
      group[0] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Translation");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X component");
      input[0]->value("0");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y component");
      input[1]->value("0");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z component");
      input[2]->value("1");
      for(int i = 0; i < 3; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[0]->end();
    }
    // 1: Rotation
    {
      group[1] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Rotation");
      input[3] = new Fl_Input
        (2 * WB, 2 * WB + 1 * BH, IW, BH, "X coordinate of an axis point");
      input[3]->value("0");
      input[4] = new Fl_Input
        (2 * WB, 2 * WB + 2 * BH, IW, BH, "Y coordinate of an axis point");
      input[4]->value("0");
      input[5] = new Fl_Input
        (2 * WB, 2 * WB + 3 * BH, IW, BH, "Z coordinate of an axis point");
      input[5]->value("0");
      input[6] = new Fl_Input
        (2 * WB, 2 * WB + 4 * BH, IW, BH, "X component of axis direction");
      input[6]->value("0");
      input[7] = new Fl_Input
        (2 * WB, 2 * WB + 5 * BH, IW, BH, "Y component of axis direction");
      input[7]->value("1");
      input[8] = new Fl_Input
        (2 * WB, 2 * WB + 6 * BH, IW, BH, "Z component of axis direction");
      input[8]->value("0");
      input[9] = new Fl_Input
        (2 * WB, 2 * WB + 7 * BH, IW, BH, "Angle in radians");
      input[9]->value("Pi/4");
      for(int i = 3; i < 10; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[1]->end();
    }
    // 2: Scale
    {
      group[2] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Scale");
      input[10] = new Fl_Input
        (2 * WB, 2 * WB + 1 * BH, IW, BH, "X component of direction");
      input[10]->value("0");
      input[11] = new Fl_Input
        (2 * WB, 2 * WB + 2 * BH, IW, BH, "Y component of direction");
      input[11]->value("0");
      input[12] = new Fl_Input
        (2 * WB, 2 * WB + 3 * BH, IW, BH, "Z component of direction");
      input[12]->value("0");
      input[13] = new Fl_Input
        (2 * WB, 2 * WB + 4 * BH, IW, BH, "Factor");
      input[13]->value("0.5");
      for(int i = 10; i < 14; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[2]->end();
    }
    // 3: Symmetry
    {
      group[3] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Symmetry");
      input[14] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "A");
      input[14]->value("1");
      input[15] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "B");
      input[15]->value("0");
      input[16] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "C");
      input[16]->value("0");
      input[17] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "D");
      input[17]->value("1");
      for(int i = 14; i < 18; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      group[3]->end();
    }
    o->end();
  }

  win->position(CTX::instance()->ctxPosition[0], CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void transformContextWindow::show(int pane)
{
  if(pane < 0 || pane > 3) return;
  for(int i = 0; i < 4; i++)
    group[i]->hide();
  group[pane]->show();
  win->show();
}

static void physical_cb(Fl_Widget *w, void *data)
{
  std::string what;
  if(!data) what = "";
  else what = (const char*)data;

  std::string name = FlGui::instance()->physicalContext->input[0]->value();
  int number = FlGui::instance()->physicalContext->value[0]->value();

  std::string existingName = "";
  int existingNumber = 0;
  if(what != "Number"){
    for(GModel::piter it = GModel::current()->firstPhysicalName();
        it != GModel::current()->lastPhysicalName(); it++){
      if(it->second == name){
        existingName = name;
        existingNumber = it->first.second;
        break;
      }
    }
  }
  if(what != "Name"){
    std::map<int, std::vector<GEntity*> > groups[4];
    GModel::current()->getPhysicalGroups(groups);
    for(int i = 0; i < 4; i++){
      for(std::map<int, std::vector<GEntity*> >::iterator it = groups[i].begin();
          it != groups[i].end(); it++){
        if(it->first == number){
          existingNumber = number;
          existingName = GModel::current()->getPhysicalName(i, number);
          break;
        }
      }
    }
  }

  if(existingName.size() || existingNumber){
    FlGui::instance()->physicalContext->input[0]->textcolor
      (FlGui::instance()->physicalContext->color);
    FlGui::instance()->physicalContext->value[0]->textcolor
      (FlGui::instance()->physicalContext->color);
    if(what != "Name" && !strlen(FlGui::instance()->physicalContext->input[0]->value()))
      FlGui::instance()->physicalContext->input[0]->value(existingName.c_str());
    if(what != "Number")
      FlGui::instance()->physicalContext->value[0]->value(existingNumber);
    FlGui::instance()->physicalContext->append = true;
  }
  else{
    FlGui::instance()->physicalContext->input[0]->textcolor(FL_FOREGROUND_COLOR);
    FlGui::instance()->physicalContext->value[0]->textcolor(FL_FOREGROUND_COLOR);
    if(what != "Number" && FlGui::instance()->physicalContext->mode != "Remove")
      FlGui::instance()->physicalContext->value[0]->value(NEWPHYSICAL());
    FlGui::instance()->physicalContext->append = false;
  }

  if(FlGui::instance()->physicalContext->butt[0]->active()){
    if(FlGui::instance()->physicalContext->butt[0]->value())
      FlGui::instance()->physicalContext->value[0]->deactivate();
    else
      FlGui::instance()->physicalContext->value[0]->activate();
  }

  FlGui::instance()->physicalContext->input[0]->redraw();
  FlGui::instance()->physicalContext->value[0]->redraw();
}

physicalContextWindow::physicalContextWindow(int deltaFontSize)
  : mode("Add"), append(false), color(FL_RED)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 28 * FL_NORMAL_SIZE;
  int height = 2 * WB + 3 * BH;

  win = new paletteWindow(width, height, CTX::instance()->nonModalWindows ? true : false,
                          "Physical Group Context");
  win->box(GMSH_WINDOW_BOX);
  {
    input[0] = new Fl_Input_Choice(WB, WB, (3 * width) / 4, BH, "Name");
    input[0]->value("");
    input[0]->align(FL_ALIGN_RIGHT);
    input[0]->callback(physical_cb, (void*)"Name");
    input[0]->when(FL_WHEN_CHANGED);

    butt[0] = new Fl_Check_Button(WB, WB + BH, width - 2 * WB, BH, "Automatic numbering");
    butt[0]->value(1);
    butt[0]->callback(physical_cb);

    value[0] = new Fl_Value_Input(WB, WB + 2 * BH, (3 * width) / 4, BH, "Number");
    value[0]->value(0);
    value[0]->deactivate();
    value[0]->align(FL_ALIGN_RIGHT);
    value[0]->callback(physical_cb, (void*)"Number");
    value[0]->when(FL_WHEN_CHANGED);
  }

  win->position(CTX::instance()->ctxPosition[0], CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void physicalContextWindow::show(bool remove)
{
  static std::vector<Fl_Menu_Item> menu;
  static std::vector<char*> names;
  for(unsigned int i = 0; i < menu.size(); i++)
    menu[i].text = "";
  for(unsigned int i = 0; i < names.size(); i++)
    free(names[i]);
  names.clear();
  menu.clear();
  for(GModel::piter it = GModel::current()->firstPhysicalName();
      it != GModel::current()->lastPhysicalName(); it++){
    char *str = strdup(it->second.c_str());
    Fl_Menu_Item item = {str, 0, 0, 0, 0};
    names.push_back(str);
    menu.push_back(item);
  }
  Fl_Menu_Item item = {0};
  menu.push_back(item);
  input[0]->menubutton()->copy(&menu[0]);

  if(remove){
    mode = "Remove";
    butt[0]->deactivate();
    value[0]->activate();
    color = (!CTX::instance()->guiColorScheme ? FL_DARK_GREEN : FL_GREEN);
  }
  else{
    mode = "Add";
    butt[0]->activate();
    if(butt[0]->value())
      value[0]->deactivate();
    else
      value[0]->activate();
    color = (!CTX::instance()->guiColorScheme ? FL_DARK_RED : FL_RED);
  }
  physical_cb(0, (void*)"Name");
  if(!win->shown()) win->show();
}

meshContextWindow::meshContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  static Fl_Menu menu_transfinite_dir[] = {
    {"Left", 0, 0, 0},
    {"Right", 0, 0, 0},
    {"Alternated", 0, 0, 0},
    {0}
  };

  int width = 29 * FL_NORMAL_SIZE;
  int height = 4 * WB + 4 * BH;

  win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows, "Mesh Context");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
    // 0: Element size at points
    {
      group[0] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Element size");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Value");
      input[0]->value("0.1");
      input[0]->align(FL_ALIGN_RIGHT);
      group[0]->end();
    }
    // 1: Transfinite line
    {
      group[1] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Transfinite Line");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Number of points");
      input[1]->value("10");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Parameter");
      input[2]->value("1");
      for(int i = 1; i < 3; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
      }
      static Fl_Menu_Item menu_trsf_mesh[] = {
        {"Progression", 0, 0, 0},
        {"Bump", 0, 0, 0},
        {0}
      };
      choice[0] = new Fl_Choice(2 * WB, 2 * WB + 2 * BH, IW, BH, "Type");
      choice[0]->menu(menu_trsf_mesh);
      choice[0]->align(FL_ALIGN_RIGHT);
      group[1]->end();
    }

    // 2: Transfinite surface
    {
      group[2] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Transfinite Surface");

      choice[1] = new Fl_Choice
        (2 * WB, 2 * WB + 1 * BH, IW, BH, "Transfinite Arrangement");
      choice[1]->menu(menu_transfinite_dir);
      choice[1]->align(FL_ALIGN_RIGHT);

      group[2]->end();
    }
    o->end();
  }

  win->position(CTX::instance()->ctxPosition[0], CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void meshContextWindow::show(int pane)
{
  for(int i = 0; i < 3; i++)
    group[i]->hide();
  group[pane]->show();
  win->show();
}
