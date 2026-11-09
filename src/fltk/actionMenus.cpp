// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The items of the action registry (see Actions.h) as the graphical interface
// does them: the operations on the entities picked in the scene (see
// selectionDriver), the shapes added from their fields, the actions of the
// table that show a window, and the items of a menu added to an FLTK menu

#include "GmshConfig.h"
#include "GmshDefines.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "Shortcuts.h"
#include "graphicWindow.h"
#include "gmshScheme.h"
#include "icons.h"
#include "optionWindow.h"
#include "contextWindow.h"
#include "highOrderToolsWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "helpWindow.h"
#include "openglWindow.h"
#include "viewButton.h"
#include "onelabContextWindow.h"
#include "onelabGroup.h"
#include "extraDialogs.h"
#include "partitionDialog.h"
#include "classificationEditor.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "OpenFile.h"
#include "scriptStringInterface.h"
#include "Options.h"
#include "Context.h"
#include "selectionDriver.h"
#include "Actions.h"

#if defined(HAVE_MESH)
#include "gmshCrossFields.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

// The value of a field of the operations on selected entities (see
// selectionDriver), by its name, from the context windows
static std::string dialogValue(const std::string &operation,
                               const std::string &name)
{
  FlGui *g = FlGui::instance();
  if(name == "Name") return g->physicalContext->selectedName;
  if(name == "Tag") return std::to_string(g->physicalContext->selectedTag);
  Fl_Widget *w =
    g->transformContext->field(name, operation == "Extrude rotate");
  return fieldValue(w ? w : g->meshContext->field(name));
}

// After a physical group is added or removed: the clients are told, and the
// ONELAB parameters of the group are shown if it has any, which stops the
// selection (so that outside codes can process events through the API); or
// the dialog is shown again, with the new group. False if the selection stops
static bool physicalGroupChanged(const selectionDriver &d)
{
  selectionDriver::kind k = selectionDriver::kindOf(d.operation());
  const std::string &what = k.what;
  bool remove = k.remove;
  onelab_cb(nullptr, (void *)"check");
  if(!FlGui::available()) return false;
  std::vector<std::string> param;
  onelab::server::instance()->getParameterNames(
    param, "ONELAB Context/" + what + " Template");
  const std::vector<std::pair<int, int> > &picked = d.done()[0];
  if(picked.size() && param.size() && !remove) {
    FlGui::instance()->getCurrentOpenglWindow()->quitSelection = 1;
    GModel::current()->setSelection(0);
    FlGui::instance()->onelabContext->show(picked[0].first, picked[0].second);
    return false;
  }
  FlGui::instance()->physicalContext->show(what, remove);
  return true;
}

// An operation on selected entities (see selectionDriver): the clicks and the
// keys are waited for until it is over
static void runSelection(const std::string &operation)
{
  selectionDriver d(operation, [operation](const std::string &name) {
    return dialogValue(operation, name);
  });
  while(d.active()) {
    if(!FlGui::available()) return;
    Msg::StatusGl("%s", d.status().c_str());
    char ib = FlGui::instance()->selectEntity(d.type());
    if(!FlGui::available()) return;
    FlGui *g = FlGui::instance();
    if(d.step(ib, g->selectedVertices, g->selectedEdges, g->selectedFaces,
              g->selectedRegions, g->selectedElements)) {
      g->resetVisibility();
      if(selectionDriver::kindOf(operation).on == selectionDriver::OnPhysical &&
         !physicalGroupChanged(d))
        break;
    }
    drawContext::global()->draw();
  }
  if(FlGui::available()) Msg::StatusGl("");
}

static void add_new_point_based_entity(const std::string &what, int pane)
{
  opt_general_axes(0, GMSH_SET | GMSH_GUI, 3);
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  FlGui::instance()->elementaryContext->show(pane);

  while(1) {
    if(!FlGui::available()) return;

    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->addPointMode = 1;
    std::string name = what;
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    Msg::StatusGl(
      "Move mouse and/or enter coordinates\n"
      "[Press 'Shift' to hold position, 'e' to add %s or 'q' to abort]",
      name.c_str());
    char ib = FlGui::instance()->selectEntity(ENT_NONE);
    if(!FlGui::available()) return;
    if(ib == 'e') {
      FlGui::instance()->elementaryContext->addShape(pane);
      FlGui::instance()->resetVisibility();
      drawContext::global()->draw();
    }
    if(ib == 'q') {
      for(openglWindow *gl : FlGui::instance()->openglWindows())
        gl->addPointMode = 0;
      break;
    }
  }

  drawContext::setDrawGeomTransientFunction(nullptr);
  if(!FlGui::available()) return;
  FlGui::instance()->elementaryContext->hide();

  // at the end, not during creation to avoid having things jumping around
  SetBoundingBox();
  Msg::StatusGl("");
}

// after an operation on the mesh, which processes events: the GUI may have
// been closed meanwhile
static void afterMeshOperation()
{
  if(!FlGui::available()) return;
  // (before the drawing, which processes events)
  FlGui::instance()->updateStatistics();
  drawContext::global()->draw();
}

// The actions of the registry (see Actions.h) as this interface does them

// an operation, with the context window that holds its fields, if it has one
static void runOperation(const std::string &op)
{
  FlGui *g = FlGui::instance();
  selectionDriver::kind k = selectionDriver::kindOf(op);
  // the mesh parts picked deleted or reversed: not during another operation
  // on the model (nor the picking mode changed then)
  if(k.on == selectionDriver::OnMeshParts) {
    if(modelBusy()) return;
    runSelection(op);
    afterMeshOperation();
    return;
  }
  // the pane of the transform context window, and whether it extrudes
  static const std::map<std::string, std::pair<int, bool>> transforms = {
    {"Translate", {0, false}},
    {"Rotate", {1, false}},
    {"Scale", {2, false}},
    {"Symmetry", {3, false}},
    {"Fillet", {5, false}},
    {"Delete", {6, false}},
    {"Extrude translate", {0, true}},
    {"Extrude rotate", {1, true}},
    {"Pipe", {-1, true}}};
  // the pane of the mesh context window
  static const std::map<std::string, int> meshPanes = {
    {"Size at points", 0},
    {"Transfinite Curve", 1},
    {"Transfinite Surface", 2}};
  auto t = transforms.find(op);
  auto m = meshPanes.find(op);
  std::function<void()> hide = [] {};
  if(k.on == selectionDriver::OnPhysical) {
    g->physicalContext->show(k.what, k.remove);
    hide = [] { FlGui::instance()->physicalContext->hide(); };
  }
  else if(t != transforms.end() || k.on == selectionDriver::OnBoolean) {
    if(t != transforms.end())
      g->transformContext->show(t->second.first, t->second.second,
                                op != "Fillet");
    else
      g->transformContext->show(4);
    hide = [] { FlGui::instance()->transformContext->hide(); };
  }
  else if(m != meshPanes.end()) {
    g->meshContext->show(m->second);
    hide = [] { FlGui::instance()->meshContext->hide(); };
  }
  runSelection(op);
  if(FlGui::available()) hide();
}

// a shape: placed with the mouse, or from the values of its fields
static void addShape(const std::string &shape)
{
  if(shape == "Parameter") {
    FlGui::instance()->elementaryContext->show(0);
    return;
  }
  // (by pane of the elementary context window)
  for(int pane = 1; pane < 12; pane++)
    if(shape == scriptShapes()[pane].name)
      add_new_point_based_entity(shape, pane);
}

// the actions of the registry this interface does, but those of the menu bar
// (see menuBarActions())
static const std::map<std::string, fltkAction> &fltkActions()
{
  static const std::map<std::string, fltkAction> actions = {
    // the modules
    {"Reload script", {[](int) { geometry_reload_cb(nullptr, nullptr); }}},
    {"Edit script", {[](int) { geometry_edit_cb(nullptr, nullptr); }}},
#if defined(HAVE_MESH)
    {"Reclassify surfaces", {[](int) { mesh_classify_cb(nullptr, nullptr); }}},
    {"Save mesh", {[](int) { mesh_save_cb(nullptr, nullptr); }}},
    {"Size fields", {[](int) { field_cb(nullptr, nullptr); }}},
    {"High-order tools", {[](int) { highordertools_cb(nullptr, nullptr); }}},
#if defined(HAVE_METIS)
    {"Partition mesh", {[](int) { partition_dialog(); }}},
#endif
#endif
    // the quick access menu
    {"Select rotation center", {[](int) {
       opt_general_rotation_center_cg(0, GMSH_SET | GMSH_GUI, 0);
       general_rotation_center_cg_cb(nullptr, nullptr);
       general_options_rotation_center_select_cb(nullptr, nullptr);
     }}},
    {"Query",
     {[](int) { status_query_cb(nullptr, nullptr); },
      [] { return (int)queryMode(); }}},
    {"Measure",
     {[](int) { status_measure_cb(nullptr, nullptr); },
      [] { return (int)measureMode(); }}},
    {"Full screen",
     {[](int) { window_cb(nullptr, (void *)"fullscreen"); },
      [] { return (int)FlGui::instance()->fullscreen->shown(); }}},
    {"Split window horizontally",
     {[](int) { file_window_cb(nullptr, (void *)"split_h"); }}},
    {"Split window vertically",
     {[](int) { file_window_cb(nullptr, (void *)"split_v"); }}},
    {"Unsplit window",
     {[](int) { file_window_cb(nullptr, (void *)"split_u"); }}},
    {"General options", {[](int) { general_options_cb(nullptr, nullptr); }}},
    {"Geometry options", {[](int) { geometry_options_cb(nullptr, nullptr); }}},
    {"Mesh options", {[](int) { mesh_options_cb(nullptr, nullptr); }}},
    {"All view options", {[](int) { view_options_cb(nullptr, (void *)-1); }}},
    // the menu of a view
    {"View options",
     {[](int view) { view_options_cb(nullptr, (void *)(intptr_t)view); }}},
    {"View plugins",
     {[](int view) { plugin_cb(nullptr, (void *)(intptr_t)view); }}},
    {"Export view",
     {[](int view) { view_save_cb(nullptr, (void *)(intptr_t)view); }}},
  };
  return actions;
}

// the action this interface does with this name, or null
static const fltkAction *findAction(const std::string &name)
{
  for(auto *table : {&fltkActions(), &menuBarActions()}) {
    auto it = table->find(name);
    if(it != table->end()) return &it->second;
  }
  return nullptr;
}

bool canRunItem(const actionItem &item)
{
  if(!IsActionAvailable(item)) return false;
  if(item.kind != ActionRun || !IsDoneByInterface(item)) return true;
  return findAction(item.what) != nullptr;
}

// the value an item asks for, with a slider
static void askFor(const actionItem &item)
{
  double min, max, step, value;
  GetActionAsk(item.ask, min, max, step, value);
  std::string::size_type dot = item.ask.option.find('.');
  std::string category = item.ask.option.substr(0, dot);
  int index = (category == "View") ? firstVisibleView() : 0;
  if(index < 0) return;
  drawContext::global()->draw();
  double v = numberOrStringOptionChooser(category, index,
                                         item.ask.option.substr(dot + 1), true,
                                         item.label, true, min, max, step);
  SetActionOption(item.ask.option, v);
}

void runItem(const actionItem &item, int view)
{
  if(IsDoneByInterface(item)) {
    if(item.kind == ActionOperation)
      runOperation(item.what);
    else if(item.kind == ActionShape)
      addShape(item.what);
    else if(const fltkAction *a = findAction(item.what)) {
      if(a->run) a->run(view);
    }
  }
  else {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    int ret = RunAction(item, view, gl ? gl->getDrawContext() : nullptr);
    // the interface may have been closed meanwhile
    if(!FlGui::available()) return;
    if(ret & ActionViewsChanged) FlGui::instance()->updateViews(true);
    if(ret & ActionModelChanged) FlGui::instance()->resetVisibility();
    // (before the drawing, which processes events)
    FlGui::instance()->updateStatistics();
  }
  if(!FlGui::available()) return;
  if(!item.ask.option.empty()) askFor(item);
  drawContext::global()->draw();
}

void runAction(const std::string &name)
{ runItem(actionItem{"", ActionRun, name, {}, "", "", {}}); }

static void item_cb(Fl_Widget *w, void *data)
{
  // (the menu of a view keeps its index)
  int view = w ? (int)(intptr_t)w->user_data() : -1;
  runItem(*(const actionItem *)data, view);
}

// whether a menu has an item this interface has now
bool canRunAnyItem(const actionItem &menu)
{
  for(const actionItem &item : menu.items)
    if(item.kind == ActionMenu ? canRunAnyItem(item) : canRunItem(item)) return true;
  return false;
}

// a label as Fl_Menu_::add() reads it, where '/' separates submenus
static std::string menuLabel(const std::string &label)
{
  std::string s;
  for(char c : label) {
    if(c == '/' || c == '\\') s += '\\';
    s += c;
  }
  return s;
}

// the items of menu added to an FLTK menu under prefix (the path of a
// submenu), a group set apart by a divider; the index of the last one added
// at the level of prefix, or -1
static int addItems(Fl_Menu_ *m, const actionItem &menu,
                    const std::string &prefix, bool marks)
{
  int last = -1;
  for(const actionItem &item : menu.items) {
    if(item.kind == ActionMenu) {
      if(!canRunAnyItem(item)) continue;
      if(item.label.empty()) { // a group
        if(last >= 0) m->mode(last, m->mode(last) | FL_MENU_DIVIDER);
        int l = addItems(m, item, prefix, marks);
        if(l >= 0) last = l;
      }
      else { // a submenu
        addItems(m, item, prefix + item.label + "/", marks);
        last = m->find_index((prefix + item.label).c_str());
      }
      continue;
    }
    if(!canRunItem(item)) continue;
    // (not asked for when not shown: a menu that stays is built with the
    // interface, which the marks of the interface's actions read)
    int check = marks ? GetActionCheck(item) : -1;
    const fltkAction *a = nullptr;
    if(IsDoneByInterface(item) && item.kind == ActionRun) {
      a = findAction(item.what);
      check = (marks && a->check) ? a->check() : -1;
    }
    if(a && a->fill) { // a submenu the interface fills
      a->fill(m, prefix + item.label);
      last = m->find_index((prefix + item.label).c_str());
      continue;
    }
    int flags = 0;
    if(check >= 0)
      flags = (item.what.find('=') == std::string::npos ? FL_MENU_TOGGLE :
                                                          FL_MENU_RADIO) |
              (check ? FL_MENU_VALUE : 0);
    // the shortcut shown: the item's, or the one of the same name as its
    // action
    std::string key = item.key;
    if(key.empty() && item.kind == ActionRun &&
       !GetShortcutsOf(item.what).empty())
      key = item.what;
    last = m->add((prefix + menuLabel(item.label)).c_str(),
                  key.empty() ? 0 : fltkShortcut(key.c_str()), item_cb,
                  (void *)&item, flags);
  }
  return last;
}

void addActionItems(Fl_Menu_ *m, const actionItem &menu, int view, bool marks)
{
  m->user_data((void *)(intptr_t)view);
  addItems(m, menu, "", marks);
}
