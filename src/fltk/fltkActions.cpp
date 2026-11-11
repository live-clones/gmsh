// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The actions of the registry (see Actions.h) as the FLTK graphical user
// interface does them. In this file, in order:
// - the table of the actions the FLTK interface does, by name, in the order of
//   the menus of Actions.cpp: what each does, and its check mark if it has one;
// - how an item runs, clicked or by its key (runItem()), and how a menu of the
//   registry becomes an FLTK menu (addMenuItems());
// - the operations on the entities picked in the scene and the shapes placed
//   with the mouse, which the items of those kinds start.
// To add an action the FLTK interface does: its item in Actions.cpp (a
// guiAction()), and a line in the table below.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <type_traits>
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "fltkActions.h"
#include "fileActions.h"
#include "GmshMessage.h"
#include "Shortcuts.h"
#include "graphicWindow.h"
#include "gmshScheme.h"
#include "optionWindow.h"
#include "contextWindow.h"
#include "highOrderToolsWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "statisticsWindow.h"
#include "visibilityWindow.h"
#include "clippingWindow.h"
#include "manipWindow.h"
#include "classificationEditor.h"
#include "partitionDialog.h"
#include "openglWindow.h"
#include "viewButton.h"
#include "onelabContextWindow.h"
#include "onelabGroup.h"
#include "editorWindow.h"
#include "GModel.h"
#include "PView.h"
#include "OpenFile.h"
#include "scriptStringInterface.h"
#include "Options.h"
#include "Context.h"
#include "selectionDriver.h"
#include "sceneTool.h"
#include "Actions.h"
#include "gmshPopplerWrapper.h"

#if defined(HAVE_3M)
#include "3M.h"
#endif

// An action of the table: what it does, as a function without argument or
// with the index of the view whose menu the item is in, and its check mark
// (none without one; else 0 or 1, for a check box or a radio item)
struct fltkAction {
  std::function<void(int view)> run;
  std::function<int()> check;
  template <class F>
  fltkAction(F f, std::function<int()> c = nullptr) : check(c)
  {
    if constexpr(std::is_invocable_v<F, int>)
      run = f;
    else
      run = [f](int) { f(); };
  }
};

// the rotation centre, the keys of a selection, of a point placed with the
// mouse, Escape and the plugins of a view, below the table
static void pickRotationCenter();
static void endSelection();
static void undoSelection();
static void quitSelection();
static void freezeAxis(int i, bool allBut);
static void escape();
static void pluginsOfView();

// The actions the FLTK interface does, by name, in the order of the menus of
// Actions.cpp (an item whose name is not here is not shown). What they call
// is declared in the headers of the windows and in fileActions.h.
static const std::map<std::string, fltkAction> &actions()
{
  static const std::map<std::string, fltkAction> table = {
    // Geometry: the script (the programs written next to it are added by
    // fltkActions())
    {"script_reload", reloadScript},
    {"script_edit", editScript},
#if defined(HAVE_MESH)
    // Mesh
    {"mesh_reclassify", [] { FlGui::instance()->classify->show(); }},
    {"mesh_save", saveMesh},
    {"mesh_size_fields", [] { FlGui::instance()->fields->show(); }},
    {"mesh_high_order_tools",
     [] { FlGui::instance()->highordertools->show(false); }},
#if defined(HAVE_METIS)
    {"mesh_partition", partition_dialog},
#endif
#endif
    // Quick access: the scene
    {"scene_rotation_center", pickRotationCenter},
    {"query", {[] { toggleTool("Query"); }, [] { return (int)queryMode(); }}},
    {"measure",
     {[] { toggleTool("Measure"); }, [] { return (int)measureMode(); }}},
    {"window_full_screen",
     {toggleFullScreen, [] { return (int)isFullScreen(); }}},
    {"window_split_horizontal",
     [] { FlGui::instance()->splitCurrentOpenglWindow('h'); }},
    {"window_split_vertical",
     [] { FlGui::instance()->splitCurrentOpenglWindow('v'); }},
    {"window_unsplit",
     [] { FlGui::instance()->splitCurrentOpenglWindow('u'); }},
    {"options_general", [] { FlGui::instance()->options->showGroup(1); }},
    {"options_geometry", [] { FlGui::instance()->options->showGroup(2); }},
    {"options_mesh", [] { FlGui::instance()->options->showGroup(3); }},
    {"options_views", [] { showViewOptions(-1); }},
    // View: the menu of a view
    {"view_options", [](int view) { showViewOptions(view); }},
    {"view_plugins", [](int view) { FlGui::instance()->plugins->show(view); }},
    {"view_export", [](int view) { saveView(view); }},
    // Menu bar: File
    {"file_new", fileNew},
    {"file_open", fileOpen},
    {"file_open_previous", [] { fileOpenRecent(1); }},
    {"file_merge", fileMerge},
    {"watch", fileWatch},
    {"file_clear", fileClear},
    {"file_rename", fileRename},
    {"file_delete", fileDelete},
    {"remote_start", remoteStart},
    {"remote_merge", remoteMerge},
    {"remote_clear", remoteClear},
    {"remote_stop", remoteStop},
    {"options_save", saveModelOptions},
    {"options_save_default", saveDefaultOptions},
    {"file_export", fileExport},
    {"quit", fileQuit},
    // Tools
    {"options", [] { FlGui::instance()->options->win->show(); }},
    {"plugins", [] { FlGui::instance()->plugins->show(-1); }},
    {"visibility", showVisibility},
    {"clipping", [] { FlGui::instance()->clipping->show(); }},
    {"manipulator", [] { FlGui::instance()->manip->show(); }},
#if defined(HAVE_3M)
    {"window_3m", [] { window3M_cb(nullptr, nullptr); }},
#endif
    {"statistics", [] { FlGui::instance()->stats->show(); }},
    {"console", showHideMessages},
    // Window
    {"window_new", newGraphicWindow},
    {"window_copy",
     [] { FlGui::instance()->copyCurrentOpenglWindowToClipboard(); }},
    {"minimize", minimizeWindows},
    {"window_zoom", zoomMainWindow},
    {"menu_show_hide", showHideMenu},
    {"menu_attach_detach", attachDetachMenu},
    {"dock", dockCurrentTool},
    {"dock_all", dockAllTools},
    {"window_front", bringAllToFront},
    // Help
    {"help_online", helpOnline},
    {"help_keys", helpKeys},
    {"help_options", helpCurrentOptions},
    {"options_restore_defaults",
     [] { options_restore_defaults_cb(nullptr, nullptr); }},
    {"help_about", helpAbout},
    // Status bar
    {"models", modelsMenu},
    {"quick_access", quickAccessMenu},
    // the point of view of the window of the button clicked, or the current
    // one (Shift and Ctrl read: the other side, reset, sync the viewports)
    {"view_x", [] { setPointOfView("x", statusBarWindow()); }},
    {"view_y", [] { setPointOfView("y", statusBarWindow()); }},
    {"view_z", [] { setPointOfView("z", statusBarWindow()); }},
    {"view_3d", [] { setPointOfView("3d", statusBarWindow()); }},
    {"view_rotate", [] { setPointOfView("r", statusBarWindow()); }},
    {"view_1_1", [] { setPointOfView("1:1", statusBarWindow()); }},
    {"mouse_selection", toggleMouseSelection},
    // the animation: the time steps, or the views
    // (PostProcessing.AnimationCycle)
    {"anim_rewind", rewindAnimation},
    {"anim_play",
     {playOrPauseAnimation, [] { return (int)animationPlaying(); }}},
    {"time_step_prev",
     [] {
       stepAnimation(!CTX::instance()->post.animCycle,
                     -CTX::instance()->post.animStep);
     }},
    {"time_step_next",
     [] {
       stepAnimation(!CTX::instance()->post.animCycle,
                     CTX::instance()->post.animStep);
     }},
    // Keys: the keys in no menu
    {"project_reload", reloadProject},
    {"solver_run", onelabCompute},
    {"module_geometry", [] { FlGui::instance()->toggleModule("Geometry"); }},
    {"module_mesh", [] { FlGui::instance()->toggleModule("Mesh"); }},
    {"module_solver", [] { FlGui::instance()->toggleModule("Solver"); }},
    {"module_post", [] { FlGui::instance()->toggleModule("Post-processing"); }},
    {"selection_end", endSelection},
    {"selection_undo", undoSelection},
    {"selection_quit", quitSelection},
    {"freeze_x", [] { freezeAxis(0, false); }},
    {"freeze_y", [] { freezeAxis(1, false); }},
    {"freeze_z", [] { freezeAxis(2, false); }},
    {"freeze_but_x", [] { freezeAxis(0, true); }},
    {"freeze_but_y", [] { freezeAxis(1, true); }},
    {"freeze_but_z", [] { freezeAxis(2, true); }},
    {"escape", escape},
    {"options_solver", [] { FlGui::instance()->options->showGroup(4); }},
    {"options_post", [] { FlGui::instance()->options->showGroup(5); }},
    {"plugins_view", pluginsOfView},
    // the views, on the arrows
    {"view_prev", [] { stepAnimation(0, -CTX::instance()->post.animStep); }},
    {"view_next", [] { stepAnimation(0, CTX::instance()->post.animStep); }},
#if defined(HAVE_POPPLER)
    {"page_prev", [] { gmshPopplerWrapper::setCurrentPageDown(); }},
    {"page_next", [] { gmshPopplerWrapper::setCurrentPageUp(); }},
#endif
  };
  return table;
}

// The actions of the table given to their items once (see SetItemRun()), and
// the edition of the programs written next to the script (see
// scriptLanguages()), one per language
void fltkActions()
{
  static bool done = false;
  if(done) return;
  done = true;
  for(auto &a : actions()) SetItemRun(a.first, a.second.run, a.second.check);
  for(auto &l : scriptLanguages()) {
    std::string lang = l.name;
    SetItemRun("script_edit_" + lang, [lang](int) {
      editFile(scriptProgram(GModel::current()->getFileName(), lang));
    });
  }
}

// the rotation centre picked in the scene: the rotation about the pseudo
// centre of mass turned off, then a click (see optionWindow.cpp)
static void pickRotationCenter()
{
  opt_general_rotation_center_cg(0, GMSH_SET | GMSH_GUI, 0);
  general_rotation_center_cg_cb(nullptr, nullptr);
  general_options_rotation_center_select_cb(nullptr, nullptr);
}

// a selection flag of all the scenes (see sceneView::selectionStep()): the
// tool under way takes it now; without one, the API waiting for a selection
// reads it (see openglWindow::selectEntity())
static void setSelectionFlag(int sceneView::*flag)
{
  for(openglWindow *gl : FlGui::instance()->openglWindows()) gl->*flag = 1;
  sceneTool::step();
}
static void endSelection() { setSelectionFlag(&sceneView::endSelection); }
static void undoSelection() { setSelectionFlag(&sceneView::undoSelection); }
static void quitSelection() { setSelectionFlag(&sceneView::quitSelection); }

// placing an elementary entity with the mouse: the axis i frozen or not, or
// all the axes but i frozen
static void freezeAxis(int i, bool allBut)
{
  elementaryContextWindow *e = FlGui::instance()->elementaryContext;
  if(allBut)
    for(int j = 0; j < 3; j++) e->butt[j]->value(j != i);
  else
    e->butt[i]->value(!e->butt[i]->value());
}

// Escape cancels what is under way, one thing at a time: a lasso, then the
// selection (a tool, or the API waiting for one: as 'q'), then full screen
// (picking is switched off and on by Shift+Escape, see "mouse_selection")
static void escape()
{
  bool lasso = false, selection = sceneTool::current() != nullptr;
  for(openglWindow *gl : FlGui::instance()->openglWindows()) {
    if(gl->lassoMode) lasso = true;
    if(gl->selectionMode) selection = true;
  }
  if(lasso) {
    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->lassoMode = false;
    drawContext::global()->draw();
    return;
  }
  if(selection) {
    quitSelection();
    return;
  }
  if(isFullScreen()) toggleFullScreen();
}

// the plugins of the view shown in the options window
static void pluginsOfView()
{
  int view = FlGui::instance()->options->view.index;
  if(PView::list.size())
    FlGui::instance()->plugins->show(
      (view >= 0 && view < (int)PView::list.size()) ? view : 0);
}

// How an item runs

static void startOperation(const std::string &op);
static void startShape(const std::string &shape);

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

// whether a menu has an item the FLTK interface has now
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

// the check mark of an item: a check box, or a radio item for an option
// given a value, when marks are shown (not asked for otherwise: a menu that
// stays is built with the interface, which the marks of the interface's
// actions read)
static int itemFlags(const actionItem &item, bool marks)
{
  int check = (marks && item.check) ? item.check() : -1;
  if(check < 0) return 0;
  int flags =
    item.name.find('=') == std::string::npos ? FL_MENU_TOGGLE : FL_MENU_RADIO;
  return check ? flags | FL_MENU_VALUE : flags;
}

// the shortcut an action shows: the one of its name
static int itemShortcut(const actionItem &item)
{
  if(item.kind != ItemAction || GetShortcutsOf(item.name).empty()) return 0;
  return fltkShortcut(item.name.c_str());
}

static int addItems(Fl_Menu_ *m, const actionItem &menu,
                    const std::string &prefix, bool marks);

// a submenu added under prefix; the index of its title
static int addSubmenu(Fl_Menu_ *m, const actionItem &menu,
                      const std::string &prefix, bool marks)
{
  addItems(m, menu, prefix + menu.label + "/", marks);
  return m->find_index((prefix + menu.label).c_str());
}

// an item (not a menu) added under prefix; its index, or -1 if the FLTK
// interface does not have it
static int addItem(Fl_Menu_ *m, const actionItem &item,
                   const std::string &prefix, bool marks)
{
  if(item.name == "file_open_recent") { // a submenu the interface fills
    addRecentFiles(m, prefix + item.label);
    return m->find_index((prefix + item.label).c_str());
  }
  if(!canRunItem(item)) return -1;
  return m->add((prefix + menuLabel(item.label)).c_str(), itemShortcut(item),
                item_cb, (void *)&item, itemFlags(item, marks));
}

// the items of menu added under prefix (the path of a submenu), each group
// set apart by a divider; the index of the last one added at the level of
// prefix, or -1
static int addItems(Fl_Menu_ *m, const actionItem &menu,
                    const std::string &prefix, bool marks)
{
  int last = -1;
  for(const actionItem &item : menu.items) {
    int l;
    if(item.kind != ItemMenu)
      l = addItem(m, item, prefix, marks);
    else if(!canRunAnyItem(item))
      l = -1;
    else if(!item.label.empty())
      l = addSubmenu(m, item, prefix, marks);
    else { // a group
      if(last >= 0) m->mode(last, m->mode(last) | FL_MENU_DIVIDER);
      l = addItems(m, item, prefix, marks);
    }
    if(l >= 0) last = l;
  }
  return last;
}

void addMenuItems(Fl_Menu_ *m, const actionItem &menu, int view, bool marks)
{
  m->user_data((void *)(intptr_t)view);
  addItems(m, menu, "", marks);
}

// The operations on the entities picked in the scene and the shapes placed
// with the mouse

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
  onelabCheck();
  if(!FlGui::available()) return false;
  std::vector<std::string> param;
  onelab::server::instance()->getParameterNames(param, "ONELAB Context/" +
                                                         what + " Template");
  const std::vector<std::pair<int, int>> &picked = d.done()[0];
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
