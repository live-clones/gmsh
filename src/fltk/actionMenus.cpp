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
#include "GmshMessage.h"
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
#include "editorWindow.h"
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
#include "sceneTool.h"
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
    g->transformContext->field(name, operation == "extrude_rotate");
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
    GModel::current()->setSelection(0);
    FlGui::instance()->onelabContext->show(picked[0].first, picked[0].second);
    return false;
  }
  FlGui::instance()->physicalContext->show(what, remove);
  return true;
}

// An operation on selected entities (see selectionDriver), as a tool of the
// current window (see sceneTool), for the dialog window if there is one (its
// owner); finished() once it is over
static void runSelection(const std::string &operation,
                         std::function<void()> finished,
                         Fl_Window *window = nullptr)
{
  auto *t = new operationTool(
    operation,
    [operation](const std::string &name) {
      return dialogValue(operation, name);
    },
    [operation](const selectionDriver &d) {
      if(!FlGui::available()) return false;
      FlGui::instance()->resetVisibility();
      if(selectionDriver::kindOf(operation).on == selectionDriver::OnPhysical)
        return physicalGroupChanged(d);
      return true;
    },
    [finished]() {
      if(FlGui::available() && finished) finished();
    });
  if(!t->active()) {
    delete t;
    if(finished) finished();
    return;
  }
  sceneTool::start(t, FlGui::instance()->getCurrentOpenglWindow(), window);
}

// a point, or a shape placed at points, following the mouse (and the values
// of the dialog) until 'e' adds it, as a tool of the current window
static void add_new_point_based_entity(const std::string &what, int pane)
{
  opt_general_axes(0, GMSH_SET | GMSH_GUI, 3);
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();

  FlGui::instance()->elementaryContext->show(pane);

  std::string name = what;
  std::transform(name.begin(), name.end(), name.begin(), ::tolower);
  auto pointMode = [](int mode) {
    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->addPointMode = mode;
  };
  sceneTool::start(
    new functionTool(
      "Add " + what, ENT_NONE, false,
      [name](sceneView *) {
        return "Move mouse and/or enter coordinates\n[Press 'Shift' to hold "
               "position, 'e' to add " +
               name + " or Escape to abort]";
      },
      [pane, pointMode](char ib, sceneView *, const scenePicks &) {
        if(ib == 'q') return false;
        if(ib == 'e') {
          FlGui::instance()->elementaryContext->addShape(pane);
          FlGui::instance()->resetVisibility();
        }
        // (the point follows the mouse again)
        pointMode(1);
        return true;
      },
      [pointMode]() {
        drawContext::setDrawGeomTransientFunction(nullptr);
        if(!FlGui::available()) return;
        pointMode(0);
        FlGui::instance()->elementaryContext->hide();
        // at the end, not during creation to avoid having things jumping
        // around
        SetBoundingBox();
        drawContext::global()->draw();
      }),
    FlGui::instance()->getCurrentOpenglWindow(),
    (Fl_Window *)FlGui::instance()->elementaryContext->win);
  pointMode(1);
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
static void startOperation(const std::string &op)
{
  FlGui *g = FlGui::instance();
  selectionDriver::kind k = selectionDriver::kindOf(op);
  // the mesh parts picked deleted or reversed: not during another operation
  // on the model (nor the picking mode changed then)
  if(k.on == selectionDriver::OnMeshParts) {
    if(modelBusy()) return;
    runSelection(op, afterMeshOperation);
    return;
  }
  // the pane of the transform context window, and whether it extrudes
  static const std::map<std::string, std::pair<int, bool>> transforms = {
    {"translate", {0, false}},
    {"rotate", {1, false}},
    {"scale", {2, false}},
    {"symmetry", {3, false}},
    {"fillet", {5, false}},
    {"delete", {6, false}},
    {"extrude_translate", {0, true}},
    {"extrude_rotate", {1, true}},
    {"extrude_pipe", {-1, true}}};
  // the pane of the mesh context window
  static const std::map<std::string, int> meshPanes = {
    {"define_size_at_points", 0},
    {"define_transfinite_curve", 1},
    {"define_transfinite_surface", 2}};
  auto t = transforms.find(op);
  auto m = meshPanes.find(op);
  std::function<void()> hide = [] {};
  Fl_Window *window = nullptr;
  if(k.on == selectionDriver::OnPhysical) {
    g->physicalContext->show(k.what, k.remove);
    hide = [] { FlGui::instance()->physicalContext->hide(); };
    window = g->physicalContext->win;
  }
  else if(t != transforms.end() || k.on == selectionDriver::OnBoolean) {
    if(t != transforms.end())
      g->transformContext->show(t->second.first, t->second.second,
                                op != "fillet");
    else
      g->transformContext->show(4);
    hide = [] { FlGui::instance()->transformContext->hide(); };
    window = g->transformContext->win;
  }
  else if(m != meshPanes.end()) {
    g->meshContext->show(m->second);
    hide = [] { FlGui::instance()->meshContext->hide(); };
    window = g->meshContext->win;
  }
  runSelection(op, hide, window);
}

// a shape: placed with the mouse, or from the values of its fields
static void startShape(const std::string &shape)
{
  if(shape == "add_parameter") {
    FlGui::instance()->elementaryContext->show(0);
    return;
  }
  // (by pane of the elementary context window)
  for(int pane = 1; pane < (int)scriptShapes().size(); pane++)
    if(shape == scriptShapes()[pane].name)
      add_new_point_based_entity(scriptShapes()[pane].label, pane);
}

// the actions of the modules and of the scene menus this interface does
static const std::map<std::string, fltkAction> &listedFltkActions()
{
  static const std::map<std::string, fltkAction> actions = {
    // the modules
    {"script_reload", {[](int) { geometry_reload_cb(nullptr, nullptr); }}},
    {"script_edit", {[](int) { geometry_edit_cb(nullptr, nullptr); }}},
#if defined(HAVE_MESH)
    {"mesh_reclassify", {[](int) { mesh_classify_cb(nullptr, nullptr); }}},
    {"mesh_save", {[](int) { mesh_save_cb(nullptr, nullptr); }}},
    {"mesh_size_fields", {[](int) { field_cb(nullptr, nullptr); }}},
    {"mesh_high_order_tools",
     {[](int) { highordertools_cb(nullptr, nullptr); }}},
#if defined(HAVE_METIS)
    {"mesh_partition", {[](int) { partition_dialog(); }}},
#endif
#endif
    // the quick access menu
    {"scene_rotation_center", {[](int) {
       opt_general_rotation_center_cg(0, GMSH_SET | GMSH_GUI, 0);
       general_rotation_center_cg_cb(nullptr, nullptr);
       general_options_rotation_center_select_cb(nullptr, nullptr);
     }}},
    {"query",
     {[](int) { status_query_cb(nullptr, nullptr); },
      [] { return (int)queryMode(); }}},
    {"measure",
     {[](int) { status_measure_cb(nullptr, nullptr); },
      [] { return (int)measureMode(); }}},
    {"window_full_screen",
     {[](int) { window_cb(nullptr, (void *)"fullscreen"); },
      [] { return (int)FlGui::instance()->fullscreen->shown(); }}},
    {"window_split_horizontal",
     {[](int) { file_window_cb(nullptr, (void *)"split_h"); }}},
    {"window_split_vertical",
     {[](int) { file_window_cb(nullptr, (void *)"split_v"); }}},
    {"window_unsplit",
     {[](int) { file_window_cb(nullptr, (void *)"split_u"); }}},
    {"options_general", {[](int) { general_options_cb(nullptr, nullptr); }}},
    {"options_geometry", {[](int) { geometry_options_cb(nullptr, nullptr); }}},
    {"options_mesh", {[](int) { mesh_options_cb(nullptr, nullptr); }}},
    {"options_views", {[](int) { view_options_cb(nullptr, (void *)-1); }}},
    // the menu of a view
    {"view_options",
     {[](int view) { view_options_cb(nullptr, (void *)(intptr_t)view); }}},
    {"view_plugins",
     {[](int view) { plugin_cb(nullptr, (void *)(intptr_t)view); }}},
    {"view_export",
     {[](int view) { view_save_cb(nullptr, (void *)(intptr_t)view); }}},
  };
  return actions;
}

// The actions this interface does, given to their items once (see
// SetItemRun()): those of the modules and of the scene menus above, of the
// menu bar (graphicWindow.cpp) and of the keys not in a menu (FlGui.cpp),
// each next to the code it calls, and the programs written next to the
// script, in the script editor
void fltkActions()
{
  static bool done = false;
  if(done) return;
  done = true;
  for(auto *part :
      {&listedFltkActions(), &menuBarActions(), &keyboardActions()})
    for(auto &a : *part) SetItemRun(a.first, a.second.run, a.second.check);
  for(auto &l : scriptLanguages()) {
    std::string lang = l.name;
    SetItemRun("script_edit_" + lang, [lang](int) {
      editFile(scriptProgram(GModel::current()->getFileName(), lang));
    });
  }
}

bool canRunItem(const actionItem &item)
{
  if(item.available && !item.available()) return false;
  return item.kind != ItemAction || item.run;
}

void runItem(const actionItem &item, int view)
{
  if(item.kind == ItemOperation)
    startOperation(item.name);
  else if(item.kind == ItemShape)
    startShape(item.name);
  else {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    int ret = RunItem(item, view, gl ? gl->getDrawContext() : nullptr);
    // the interface may have been closed meanwhile
    if(!FlGui::available()) return;
    if(ret & ActionViewsChanged) FlGui::instance()->updateViews(true);
    if(ret & ActionModelChanged) FlGui::instance()->resetVisibility();
    // (before the drawing, which processes events)
    FlGui::instance()->updateStatistics();
  }
  if(!FlGui::available()) return;
  drawContext::global()->draw();
}

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
    if(item.kind == ItemMenu ? canRunAnyItem(item) : canRunItem(item))
      return true;
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
    if(item.kind == ItemMenu) {
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
    if(item.name == "file_open_recent") { // a submenu the interface fills
      addRecentFiles(m, prefix + item.label);
      last = m->find_index((prefix + item.label).c_str());
      continue;
    }
    if(!canRunItem(item)) continue;
    // the check mark (not asked for when not shown: a menu that stays is
    // built with the interface, which the marks of the interface's actions
    // read)
    int check = (marks && item.check) ? item.check() : -1;
    int flags = 0;
    if(check >= 0)
      flags = (item.name.find('=') == std::string::npos ? FL_MENU_TOGGLE :
                                                          FL_MENU_RADIO) |
              (check ? FL_MENU_VALUE : 0);
    // the shortcut shown: the one of the same name as its action
    bool key = item.kind == ItemAction && !GetShortcutsOf(item.name).empty();
    last = m->add((prefix + menuLabel(item.label)).c_str(),
                  key ? fltkShortcut(item.name.c_str()) : 0, item_cb,
                  (void *)&item, flags);
  }
  return last;
}

void addMenuItems(Fl_Menu_ *m, const actionItem &menu, int view, bool marks)
{
  m->user_data((void *)(intptr_t)view);
  addItems(m, menu, "", marks);
}
