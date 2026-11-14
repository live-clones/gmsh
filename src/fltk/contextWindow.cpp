// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <FL/Fl_Tabs.H>
#include "FlGui.h"
#include "accentTabs.h"
#include "drawContext.h"
#include "contextWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "Parser.h"
#include "GModel.h"
#ifdef Convex // can be defined by Xlib
#undef Convex
#endif
#include "GModelIO_OCC.h"
#include "scriptStringInterface.h"
#include "shapePlacement.h"
#include "sceneView.h"
#include "selectionDriver.h"
#include "OpenFile.h"
#include "Context.h"
#include "StringUtils.h"
#include "Geo.h"
#include "VertexArray.h"
#include "mathEvaluator.h"
#include "GmshMessage.h"

// the inputs of each pane of the elementary context window, one for each field
// of its shape (see scriptShapes()): the first one, and how many
static int paneSize(int pane) { return scriptShapes()[pane].fields.size(); }
static int paneFirst(int pane)
{
  int first = 0;
  for(int p = 0; p < pane; p++) first += paneSize(p);
  return first;
}

std::vector<std::string> elementaryContextWindow::paneValues(int pane)
{
  std::vector<std::string> v;
  for(int i = 0; i < paneSize(pane); i++)
    v.push_back(input[paneFirst(pane) + i]->value());
  return v;
}

// The shape of a pane placed (see shapePlacement): its fields, its locks and
// the work plane are those of the placement, the window showing them again
// when the scene changes them
void elementaryContextWindow::startPlacement(int pane)
{
  shapePlacement::start(pane, paneValues(pane), [this] { showPlacement(); });
  if(shapePlacement *p = shapePlacement::current()) {
    for(int i = 0; i < 3; i++) p->setLocked(i, butt[i]->value());
    p->setPlane((shapePlacement::Plane)plane->value());
  }
}

void elementaryContextWindow::showPlacement()
{
  shapePlacement *p = shapePlacement::current();
  if(!p) return;
  int pane = p->shape();
  for(int i = 0; i < paneSize(pane) && i < (int)p->values().size(); i++)
    input[paneFirst(pane) + i]->value(p->values()[i].c_str());
  for(int i = 0; i < 3; i++) butt[i]->value(p->locked(i));
}

// the pane shown, while a shape is placed: the placement goes on with it
static int shownPane(elementaryContextWindow *e)
{
  for(int k = 1; k < 12; k++)
    if(e->group[k]->visible()) return k;
  return -1;
}

static void redrawScenes()
{
  for(sceneView *v : sceneView::all()) v->askRedraw();
}

static void elementary_tab_cb(Fl_Widget *w, void *data)
{
  elementaryContextWindow *e = FlGui::instance()->elementaryContext;
  int pane = shownPane(e);
  if(shapePlacement::current() && pane > 0 &&
     pane != shapePlacement::current()->shape()) {
    e->startPlacement(pane);
    redrawScenes();
  }
}

// a field typed: the placement takes it (a coordinate of the position typed
// is locked)
static void elementary_value_cb(Fl_Widget *w, void *data)
{
  elementaryContextWindow *e = FlGui::instance()->elementaryContext;
  shapePlacement *p = shapePlacement::current();
  if(!p) return;
  int pane = p->shape();
  for(int i = 0; i < paneSize(pane); i++) {
    if(e->input[paneFirst(pane) + i] != w) continue;
    p->setValue(i, e->input[paneFirst(pane) + i]->value());
    e->showPlacement();
    redrawScenes();
  }
}

static void elementary_lock_cb(Fl_Widget *w, void *data)
{
  elementaryContextWindow *e = FlGui::instance()->elementaryContext;
  if(shapePlacement *p = shapePlacement::current()) {
    for(int i = 0; i < 3; i++) p->setLocked(i, e->butt[i]->value());
    redrawScenes();
  }
}

static void elementary_plane_cb(Fl_Widget *w, void *data)
{
  elementaryContextWindow *e = FlGui::instance()->elementaryContext;
  if(shapePlacement *p = shapePlacement::current()) {
    p->setPlane((shapePlacement::Plane)e->plane->value());
    redrawScenes();
  }
}

bool elementaryContextWindow::addShape(int pane)
{
  return scriptAddShape(scriptShapes()[pane].name, paneValues(pane),
                        GModel::current()->getFileName());
}

static void elementary_add_cb(Fl_Widget *w, void *data)
{
  int pane = (int)(intptr_t)data;
  shapePlacement *p = shapePlacement::current();
  if(p && p->shape() == pane) {
    if(!p->add()) return;
  }
  else if(!FlGui::instance()->elementaryContext->addShape(pane))
    return;
  FlGui::instance()->resetVisibility();
  if(pane == 0) {
    FlGui::instance()->rebuildTree();
    return;
  }
  GModel::current()->setSelection(0);
  SetBoundingBox();
  drawContext::global()->draw();
}

static void elementary_switch_tabs_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->elementaryContext->tab1->visible()) {
    FlGui::instance()->elementaryContext->tab1->hide();
    FlGui::instance()->elementaryContext->tab2->show();
  }
  else {
    FlGui::instance()->elementaryContext->tab2->hide();
    FlGui::instance()->elementaryContext->tab1->show();
  }
}

static void elementary_snap_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->geom.snap[0] =
    FlGui::instance()->elementaryContext->value[0]->value();
  CTX::instance()->geom.snap[1] =
    FlGui::instance()->elementaryContext->value[1]->value();
  CTX::instance()->geom.snap[2] =
    FlGui::instance()->elementaryContext->value[2]->value();
}

elementaryContextWindow::elementaryContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = TW;
  // (a row under the tabs for the work plane)
  int height = 6 * WB + 11 * BH, tabH = height - 4 * WB - 2 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Elementary Entity Context",
                          CTX::instance()->ctxOffset);
  win->box(GMSH_WINDOW_BOX);
  // the panes of the shapes, in two sets of tabs: the fields of each (see
  // scriptShapes()) in a column, those of the Cone after its axis in a second
  // one, and the button that adds it
  tab1 = new accentTabs(WB, WB, width - 2 * WB, tabH);
  for(int pane = 0, k = 0; pane < 12; pane++) {
    if(pane == 6) {
      tab1->end();
      tab2 = new accentTabs(WB, WB, width - 2 * WB, tabH);
    }
    const scriptShape &shape = scriptShapes()[pane];
    group[pane] = new Fl_Group(WB, WB + BH, width - 2 * WB, tabH - BH,
                               shape.label.c_str());
    for(std::size_t i = 0; i < shape.fields.size(); i++, k++) {
      int x = 2 * WB, row = i + 1;
      if(shape.name == "add_cone" && i >= 6) {
        x += (width - 2 * WB) / 2;
        row -= 3;
      }
      input[k] = new Fl_Input(x, 2 * WB + row * BH, IW, BH,
                              shape.fields[i].first.c_str());
      input[k]->value(shape.fields[i].second.c_str());
      input[k]->align(FL_ALIGN_RIGHT);
      if(pane) input[k]->callback(elementary_value_cb);
    }
    Fl_Button *o =
      new Fl_Button(width - BB - 2 * WB, tabH - BH, BB, BH, "Add");
    o->callback(elementary_add_cb, (void *)(intptr_t)pane);
    group[pane]->end();
  }
  tab2->end();

  {
    Fl_Button *o = new Fl_Button(width - 4 * WB, WB, 3 * WB, 3 * WB, "...");
    o->callback(elementary_switch_tabs_cb);
  }
  {
    // the snap fields on the left (3 em each, an em for X and Y), the freeze
    // check buttons on the right, WB apart or their focus boxes touch
    int sw = 3 * FL_NORMAL_SIZE, sp = sw + 2 * WB + FL_NORMAL_SIZE;
    value[0] = new Fl_Value_Input(WB, height - WB - BH, sw, BH, "X");
    value[1] = new Fl_Value_Input(WB + sp, height - WB - BH, sw, BH, "Y");
    value[2] =
      new Fl_Value_Input(WB + 2 * sp, height - WB - BH, sw, BH, "Z snap");
    for(int i = 0; i < 3; i++) {
      value[i]->align(FL_ALIGN_RIGHT);
      value[i]->callback(elementary_snap_cb);
    }
    int cw = 1.2 * BH, zw = 3 * BH, bx = width - WB - 2 * cw - 2 * WB - zw;
    butt[0] = new Fl_Check_Button(bx, height - WB - BH, cw, BH, "X");
    butt[0]->tooltip("Keep the x coordinate as it is when clicking: toggle "
                     "(x), or keep all but it (Shift+x); a coordinate typed "
                     "is kept");
    butt[1] = new Fl_Check_Button(bx + cw + WB, height - WB - BH, cw, BH, "Y");
    butt[1]->tooltip("Keep the y coordinate as it is when clicking: toggle "
                     "(y), or keep all but it (Shift+y); a coordinate typed "
                     "is kept");
    butt[2] = new Fl_Check_Button(bx + 2 * (cw + WB), height - WB - BH, zw, BH,
                                  "Z lock");
    butt[2]->tooltip("Keep the z coordinate as it is when clicking: toggle "
                     "(z), or keep all but it (Shift+z); a coordinate typed "
                     "is kept");
    for(int i = 0; i < 3; i++) butt[i]->callback(elementary_lock_cb);
  }
  {
    // the plane a click places the shape on, off the model
    static Fl_Menu_Item planes[] = {
      {"XY", 0, nullptr}, {"YZ", 0, nullptr}, {"XZ", 0, nullptr},
      {"Facing the view", 0, nullptr}, {nullptr}};
    plane = new Fl_Choice(WB, height - 2 * WB - 2 * BH, IW, BH, "Work plane");
    plane->menu(planes);
    plane->align(FL_ALIGN_RIGHT);
    plane->tooltip("The plane a click places the shape on, off the model");
    plane->callback(elementary_plane_cb);
  }

  tab1->callback(elementary_tab_cb);
  tab2->callback(elementary_tab_cb);
  tab1->show();
  tab2->hide();

  win->end();
  // of fixed height, as narrow as the option window, wider as one likes
  ((paletteWindow *)win)->fixedLayout(width, height, 2 * WB);

  FL_NORMAL_SIZE += deltaFontSize;
}

void elementaryContextWindow::show(int pane)
{

  if(pane < 0 || pane > 11) return;

  for(int i = 0; i < 12; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }

  if(pane < 6) {
    tab1->show();
    tab2->hide();
  }
  else {
    tab1->hide();
    tab2->show();
  }

  group[pane]->show();
  group[pane]->activate();
  win->show();
}

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
    Fl_Color c = (!CTX::instance()->guiDark ? FL_DARK_BLUE : FL_BLUE);
    pc->input[0]->textcolor(c);
    pc->value[0]->textcolor(c);
    if(what != "Name" && !strlen(pc->input[0]->value()))
      pc->input[0]->value(existingName.c_str());
    if(what != "Tag") pc->value[0]->value(existingTag);
  }
  else {
    pc->input[0]->textcolor(FL_FOREGROUND_COLOR);
    pc->value[0]->textcolor(FL_FOREGROUND_COLOR);
    if(what != "Tag") pc->value[0]->value(NEWPHYSICAL());
  }

  if(pc->butt[0]->active()) {
    if(pc->butt[0]->value())
      pc->value[0]->deactivate();
    else
      pc->value[0]->activate();
  }

  // a tag is a positive integer (0 while none is given): what is typed
  // otherwise is shown in red, and the nearest one used
  double typed = pc->value[0]->value();
  int used = typed ? std::max(1, (int)std::lround(typed)) : 0;
  if(what == "Tag" && used != typed) pc->value[0]->textcolor(FL_RED);

  pc->input[0]->redraw();
  pc->value[0]->redraw();

  pc->selectedName = pc->input[0]->value();
  pc->selectedTag = used;
}

static void physical_remove_cb(Fl_Widget *w, void *data)
{
  physicalContextWindow *pc = FlGui::instance()->physicalContext;
  int tag = 0;
  std::string name = "";
  if(pc->choice[0]->text()) {
    std::vector<std::string> tmp = SplitString(pc->choice[0]->text(), ':');
    tag = (tmp.size() > 0) ? atoi(tmp[0].c_str()) : 0;
    name = (tmp.size() > 1) ? tmp[1] : "";
  }

  pc->selectedName = name;
  pc->selectedTag = tag;
}

physicalContextWindow::physicalContextWindow(int deltaFontSize)
  : selectedTag(0), type(""), selectedName("")
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = TW;
  int height = 5 * WB + 4 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Physical Group Context",
                          CTX::instance()->ctxOffset);
  win->box(GMSH_WINDOW_BOX);

  {
    tab = new accentTabs(WB, WB, width - 2 * WB, 4 * BH + 3 * WB);
    // 0: Add
    {
      group[0] =
        new Fl_Group(WB, WB + BH, width - 2 * WB, 3 * BH + 3 * WB, "Add");

      box[0] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, width - 4 * WB, BH);
      box[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      input[0] = new Fl_Input_Choice(2 * WB, 2 * WB + 2 * BH,
                                     (int)(0.6 * width), BH, "Name");
      input[0]->value("");
      input[0]->align(FL_ALIGN_RIGHT);
      input[0]->callback(physical_add_cb, (void *)"Name");
      input[0]->when(FL_WHEN_CHANGED);

      value[0] = new Fl_Value_Input(2 * WB, 2 * WB + 3 * BH, (int)(0.6 * width),
                                    BH, "Tag");
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
      group[1] =
        new Fl_Group(WB, WB + BH, width - 2 * WB, 3 * BH + 3 * WB, "Remove");

      box[1] = new Fl_Box(2 * WB, 2 * WB + 1 * BH, width - 4 * WB, BH);
      box[1]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      choice[0] =
        new Fl_Choice(2 * WB, 2 * WB + 2 * BH, (int)(0.6 * width), BH);
      choice[0]->align(FL_ALIGN_RIGHT);
      choice[0]->callback(physical_remove_cb);

      group[1]->end();
    }
    tab->end();
  }

  win->end();
  // of fixed height, as narrow as the option window, wider as one likes
  ((paletteWindow *)win)->fixedLayout(width, height, 2 * WB);

  FL_NORMAL_SIZE += deltaFontSize;
}

void physicalContextWindow::show(const std::string &what, bool remove)
{

  // update window title and labels
  type = what;
  int dim;
  if(type == "Volume")
    dim = 3;
  else if(type == "Surface")
    dim = 2;
  else if(type == "Curve")
    dim = 1;
  else if(type == "Point")
    dim = 0;
  else {
    Msg::Error("Unknown physical context '%s'", type.c_str());
    return;
  }
  win->copy_label(std::string("Physical " + type + " Context").c_str());
  std::string s(" and select " + type + "(s) to ");
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  box[0]->copy_label(
    std::string("Create or choose group," + s + "add").c_str());
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
      Fl_Menu_Item item = {str, 0, nullptr, nullptr, 0};
      toFree.push_back(str);
      menuAdd.push_back(item);
    }
    Fl_Menu_Item item = {nullptr};
    menuAdd.push_back(item);
    input[0]->menubutton()->copy(&menuAdd[0]);
  }
  {
    for(auto &p : physicalTags) {
      std::string label = std::to_string(p.first);
      if(p.second.size()) label += ": " + p.second;
      char *str = strdup(label.c_str());
      Fl_Menu_Item item = {str, 0, nullptr, nullptr, 0};
      toFree.push_back(str);
      menuRemove.push_back(item);
    }
    Fl_Menu_Item item = {nullptr};
    menuRemove.push_back(item);
    choice[0]->copy(&menuRemove[0]);
  }

  // activate the relevant tabs and widgets
  for(int i = 0; i < 2; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }
  if(remove) {
    group[1]->show();
    group[1]->activate();
    physical_remove_cb(nullptr, nullptr);
  }
  else {
    group[0]->show();
    group[0]->activate();
    if(butt[0]->value())
      value[0]->deactivate();
    else
      value[0]->activate();
    physical_add_cb(nullptr, (void *)"Name");
  }

  if(!win->shown()) win->show();
}

// The fields of the operations on selected entities (see selectionDriver),
// their values, and their defaults and choices, from the driver's list
std::string fieldValue(Fl_Widget *w)
{
  if(auto *i = dynamic_cast<Fl_Input *>(w)) return i->value();
  if(auto *b = dynamic_cast<Fl_Check_Button *>(w)) return b->value() ? "1" : "0";
  if(auto *c = dynamic_cast<Fl_Choice *>(w)) return c->text() ? c->text() : "";
  return "";
}

static void setFieldDefault(Fl_Widget *w, const selectionDriver::field &f)
{
  if(auto *i = dynamic_cast<Fl_Input *>(w)) i->value(f.value.c_str());
  else if(auto *b = dynamic_cast<Fl_Check_Button *>(w)) b->value(f.value == "1");
  else if(auto *c = dynamic_cast<Fl_Choice *>(w)) {
    if(!c->size()) c->add(f.kind.c_str());
    c->value(c->find_index(f.value.c_str()));
  }
}

Fl_Widget *transformContextWindow::field(const std::string &name,
                                         bool rotation)
{
  // the widget labelled with the name (the fields of the axis by their
  // tooltip), first in the tab of the rotation or of the translation, which
  // have the same fields of the extrusion
  if(name == "Selection mode") return choice;
  int first = rotation ? 1 : 0;
  for(int g : {first, 1 - first, 2, 3, 4, 5, 6}) {
    for(int i = 0; i < group[g]->children(); i++) {
      Fl_Widget *w = group[g]->child(i);
      if((w->label() && name == w->label()) ||
         (w->tooltip() && name == w->tooltip()))
        return w;
    }
  }
  return nullptr;
}

Fl_Widget *meshContextWindow::field(const std::string &name)
{
  if(name == "Element size") return input[0];
  if(name == "Number of points") return input[1];
  if(name == "Parameter") return input[2];
  if(name == "Type") return choice[0];
  if(name == "Arrangement") return choice[1];
  return nullptr;
}

static void selection_mode_cb(Fl_Widget *w, void *data)
{
  int mode = selectionDriver::selectionMode(fieldValue(w));
  if(mode != ENT_ALL) selectionDriver::show(mode);
  for(openglWindow *gl : FlGui::instance()->openglWindows())
    gl->changeSelection = mode;
  drawContext::global()->draw();
}

transformContextWindow::transformContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = TW;
  int height = 5 * WB + 10 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Elementary Operation Context",
                          CTX::instance()->ctxOffset);
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new accentTabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    // 0: Translate
    {
      group[0] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Translate");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Translation X");
      input[1] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Translation Y");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Translation Z");
      for(int i = 0; i < 3; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      butt[0] = new Fl_Check_Button(2 * WB, 2 * WB + 4 * BH, width - 4 * WB, BH,
                                    "Apply translation on copy");
      butt[7] = new Fl_Check_Button(2 * WB, 2 * WB + 5 * BH, width - 4 * WB, BH,
                                    "Extrude mesh");
      input[21] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Mesh layers");
      input[21]->align(FL_ALIGN_RIGHT);
      // on a row of its own, as the label of the layers takes half the width
      butt[8] = new Fl_Check_Button(2 * WB, 2 * WB + 7 * BH, width - 4 * WB, BH,
                                    "Recombine");
      group[0]->end();
    }
    // 1: Rotate
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Rotate");
      // the axis point and direction, each as one row of three fields
      static const char *tips[6] = {"Axis point X",      "Axis point Y",
                                    "Axis point Z",      "Axis direction DX",
                                    "Axis direction DY", "Axis direction DZ"};
      for(int i = 0; i < 6; i++) {
        int row = i / 3, col = i % 3;
        int x = 2 * WB + col * IW / 3;
        int w = (col < 2) ? IW / 3 : IW - 2 * (IW / 3);
        input[3 + i] = new Fl_Input(
          x, 2 * WB + (1 + row) * BH, w, BH,
          (col < 2) ? nullptr : (row ? "Axis direction" : "Axis point"));
        input[3 + i]->tooltip(tips[i]);
      }
      input[9] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Angle");
      for(int i = 3; i < 10; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      butt[1] = new Fl_Check_Button(2 * WB, 2 * WB + 4 * BH, width - 4 * WB, BH,
                                    "Apply rotation on copy");
      butt[9] = new Fl_Check_Button(2 * WB, 2 * WB + 5 * BH, width - 4 * WB, BH,
                                    "Extrude mesh");
      input[22] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Mesh layers");
      input[22]->align(FL_ALIGN_RIGHT);
      // on a row of its own, as the label of the layers takes half the width
      butt[10] = new Fl_Check_Button(2 * WB, 2 * WB + 7 * BH, width - 4 * WB,
                                     BH, "Recombine");
      group[1]->end();
    }
    // 2: Scale
    {
      group[2] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Scale");
      input[10] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Center X");
      input[11] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Center Y");
      input[12] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Center Z");
      input[13] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Scaling X");
      input[14] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Scaling Y");
      input[15] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Scaling Z");
      for(int i = 10; i < 16; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      butt[2] = new Fl_Check_Button(2 * WB, 2 * WB + 7 * BH, width - 4 * WB, BH,
                                    "Apply scaling on copy");
      group[2]->end();
    }
    // 3: Symmetry
    {
      group[3] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Symmetry");
      input[16] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Symmetry plane coefficient A");
      input[17] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Symmetry plane coefficient B");
      input[18] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Symmetry plane coefficient C");
      input[19] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Symmetry plane coefficient D");
      for(int i = 16; i < 20; i++) {
        input[i]->align(FL_ALIGN_RIGHT);
        input[i]->tooltip("A * X + B * Y + C * Z + D = 0");
      }
      butt[3] = new Fl_Check_Button(2 * WB, 2 * WB + 5 * BH, width - 4 * WB, BH,
                                    "Apply symmetry on copy");
      group[3]->end();
    }
    // 4: Boolean
    {
      group[4] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Boolean");
      butt[4] = new Fl_Check_Button(2 * WB, 2 * WB + 1 * BH, width - 4 * WB, BH,
                                    "Delete object");
      butt[5] = new Fl_Check_Button(2 * WB, 2 * WB + 2 * BH, width - 4 * WB, BH,
                                    "Delete tool");
      group[4]->end();
    }
    // 5: Fillet
    {
      group[5] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Fillet");
      input[20] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Radius");
      input[20]->align(FL_ALIGN_RIGHT);
      group[5]->end();
    }
    // 6: Delete
    {
      group[6] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Delete");
      butt[6] = new Fl_Check_Button(2 * WB, 2 * WB + 1 * BH, width - 4 * WB, BH,
                                    "Recursive");
      group[6]->end();
    }
    o->end();
  }

  choice = new Fl_Choice(WB, height - WB - BH, IW, BH, "Selection mode");
  choice->align(FL_ALIGN_RIGHT);
  choice->callback(selection_mode_cb);

  // the defaults of the fields, and the choices, of the operations
  for(auto &f : selectionDriver::allFields()) {
    setFieldDefault(field(f.name, false), f);
    setFieldDefault(field(f.name, true), f);
  }

  win->end();
  // of fixed height, as narrow as the option window, wider as one likes
  ((paletteWindow *)win)->fixedLayout(width, height, 2 * WB);

  FL_NORMAL_SIZE += deltaFontSize;
}

void transformContextWindow::show(int pane, bool extrude, bool selection)
{

  for(int i = 0; i < 7; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }
  for(int i = 0; i < 4; i++) {
    if(extrude)
      butt[i]->deactivate();
    else
      butt[i]->activate();
  }
  for(int i = 7; i < 11; i++) {
    if(!extrude)
      butt[i]->deactivate();
    else
      butt[i]->activate();
  }
  for(int i = 21; i < 23; i++) {
    if(!extrude)
      input[i]->deactivate();
    else
      input[i]->activate();
  }
  if(selection)
    choice->activate();
  else
    choice->deactivate();
  if(pane < 0 || pane > 6) { group[0]->show(); }
  else {
    group[pane]->show();
    group[pane]->activate();
  }
  win->show();
}

meshContextWindow::meshContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = TW;
  int height = 4 * WB + 4 * BH;

  win = new paletteWindow(width, height, CTX::instance()->nonModalWindows,
                          "Mesh Context",
                          CTX::instance()->ctxOffset);
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new accentTabs(WB, WB, width - 2 * WB, height - 2 * WB);
    // 0: Element size at points
    {
      group[0] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Element size");
      input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Value");
      input[0]->align(FL_ALIGN_RIGHT);
      group[0]->end();
    }
    // 1: Transfinite line
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Transfinite curve");
      input[1] =
        new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Number of points");
      input[2] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Parameter");
      for(int i = 1; i < 3; i++) { input[i]->align(FL_ALIGN_RIGHT); }
      choice[0] = new Fl_Choice(2 * WB, 2 * WB + 2 * BH, IW, BH, "Type");
      choice[0]->align(FL_ALIGN_RIGHT);
      group[1]->end();
    }

    // 2: Transfinite surface
    {
      group[2] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 2 * WB - BH,
                              "Transfinite Surface");

      choice[1] = new Fl_Choice(2 * WB, 2 * WB + 1 * BH, IW, BH,
                                "Transfinite Arrangement");
      choice[1]->align(FL_ALIGN_RIGHT);

      group[2]->end();
    }
    o->end();
  }

  // the defaults of the fields, and the choices, of the operations
  for(auto &f : selectionDriver::allFields()) setFieldDefault(field(f.name), f);

  win->end();
  // of fixed height, as narrow as the option window, wider as one likes
  ((paletteWindow *)win)->fixedLayout(width, height, 2 * WB);

  FL_NORMAL_SIZE += deltaFontSize;
}

void meshContextWindow::show(int pane)
{

  for(int i = 0; i < 3; i++) {
    group[i]->hide();
    group[i]->deactivate();
  }
  group[pane]->show();
  group[pane]->activate();
  win->show();
}
