// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// A random user of the FLTK graphical user interface: a model opened, then an
// action every few milliseconds, from a timer (never from main(): on macOS
// the GL contexts deleted from there leak), each logged with the seed so that
// a run can be repeated:
//   gui_fuzz model.geo [seconds] [seed]
// The actions: the keyboard shortcuts of the registry (but those that save,
// export, quit or open a file chooser), the buttons of the Geometry and Mesh
// modules (an operation or a shape picks and places with synthetic clicks in
// the scene, then 'e' ends it), the parameters of the ONELAB tree, Check and
// Run, the widgets of the option window and of the tools, the entries of the
// menu bar, the menus of the views, pointer moves, drags and wheels in the
// scene, the windows split and unsplit, hidden and shown (never the full
// screen window, never Minimize: FLTK's capture of the window for the Dock
// hangs). A modal window gets Escape, then its close callback. At the end
// the model's files are left where they are: run in a scratch copy.
// Without a model argument, 77: ctest skips it.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <random>
#include <set>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Window.H>
#include "gmsh.h"
#include "Actions.h"
#include "Context.h"
#include "FlGui.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "OS.h"
#include "Options.h"
#include "Shortcuts.h"
#include "fltkActions.h"
#include "graphicWindow.h"
#include "onelabActions.h"
#include "onelabGroup.h"
#include "openglWindow.h"
#include "optionWindow.h"
#include "visibilityWindow.h"
#include "clippingWindow.h"
#include "sceneTool.h"

static std::mt19937 rng;
static int actions = 0, depth = 0, modalTries = 0;
static double stopAt = 0;
static bool done = false;

static int pick(int n) { return n > 0 ? (int)(rng() % n) : 0; }
static double unit() { return (rng() % 10000) / 10000.; }
static void log(const std::string &what)
{
  printf("%6d %*s%s\n", ++actions, 2 * depth, "", what.c_str());
  fflush(stdout);
}

// every widget under g, g itself included
static void walk(Fl_Widget *w, std::vector<Fl_Widget *> &all)
{
  all.push_back(w);
  if(Fl_Group *g = w->as_group())
    for(int i = 0; i < g->children(); i++) walk(g->child(i), all);
}

// a click in the scene at a fraction of its size, as keys.cpp clicks
static void click(double fx, double fy, bool ctrl = false)
{
  openglWindow *g = FlGui::instance()->getCurrentOpenglWindow();
  if(!g || !g->visible_r()) return;
  g->redraw();
  Fl::flush();
  Fl::e_x = (int)(fx * g->w());
  Fl::e_y = (int)(fy * g->h());
  Fl::e_x_root = g->x_root() + Fl::e_x;
  Fl::e_y_root = g->y_root() + Fl::e_y;
  Fl::e_state = ctrl ? FL_CTRL : 0;
  ((Fl_Widget *)g)->handle(FL_MOVE);
  Fl::e_keysym = FL_Button + 1;
  Fl::e_state = FL_BUTTON1 | (ctrl ? FL_CTRL : 0);
  Fl::e_is_click = 1;
  Fl::e_clicks = 0;
  ((Fl_Widget *)g)->handle(FL_PUSH);
  Fl::e_state = ctrl ? FL_CTRL : 0;
  ((Fl_Widget *)g)->handle(FL_RELEASE);
  Fl::awake();
}

// the pointer moved, dragged (with a button) or the wheel turned in the scene
static void pointer(int what)
{
  openglWindow *g = FlGui::instance()->getCurrentOpenglWindow();
  if(!g || !g->visible_r()) return;
  Fl::e_x = pick(g->w());
  Fl::e_y = pick(g->h());
  Fl::e_x_root = g->x_root() + Fl::e_x;
  Fl::e_y_root = g->y_root() + Fl::e_y;
  if(what == 0) {
    Fl::e_state = 0;
    ((Fl_Widget *)g)->handle(FL_MOVE);
  }
  else if(what == 1) {
    int button = 1 + pick(3);
    Fl::e_keysym = FL_Button + button;
    Fl::e_state = FL_BUTTON1 << (button - 1);
    ((Fl_Widget *)g)->handle(FL_PUSH);
    for(int i = 0; i < 3; i++) {
      Fl::e_x += pick(40) - 20;
      Fl::e_y += pick(40) - 20;
      ((Fl_Widget *)g)->handle(FL_DRAG);
    }
    Fl::e_state = 0;
    ((Fl_Widget *)g)->handle(FL_RELEASE);
  }
  else {
    Fl::e_dy = pick(7) - 3;
    Fl::e_dx = 0;
    ((Fl_Widget *)g)->handle(FL_MOUSEWHEEL);
  }
  Fl::awake();
}

// Escape sent to a window, as keys.cpp sends it
static void escapeIn(Fl_Window *w)
{
  Fl::e_keysym = FL_Escape;
  Fl::e_state = 0;
  Fl::e_text = (char *)"\x1b";
  Fl::e_length = 1;
  Fl::handle(FL_KEYDOWN, w);
  Fl::e_text = (char *)"";
  Fl::e_length = 0;
}

// the keys that are safe to press: not those that save, export, quit, open
// a file chooser or an external program
static const std::vector<std::string> &safeKeys()
{
  static std::vector<std::string> keys;
  if(keys.empty()) {
    std::set<std::string> avoid = {
      "quit",          "file_new",    "file_open",     "file_merge",
      "file_export",   "mesh_save",   "options_save",  "watch",
      "file_rename",   "file_delete", "help_online",   "script_edit",
      "file_open_previous", "minimize", "window_new",  "window_copy",
      "window_full_screen", "project_reload", "script_reload"};
    for(const ShortcutEntry &e : GetShortcuts())
      if(!avoid.count(e.action) && e.action.compare(0, 11, "script_edit"))
        keys.push_back(e.action);
  }
  return keys;
}

// a random value given to a widget, then its callback
static bool poke(Fl_Widget *w)
{
  if(!w->active_r() || !w->visible_r()) return false;
  if(Fl_Value_Input *v = dynamic_cast<Fl_Value_Input *>(w)) {
    double lo = v->minimum(), hi = v->maximum();
    if(lo == hi) { lo = -10; hi = 10; }
    v->value(lo + unit() * (hi - lo));
  }
  else if(Fl_Choice *c = dynamic_cast<Fl_Choice *>(w)) {
    if(c->size() < 2) return false;
    c->value(pick(c->size() - 1));
  }
  else if(Fl_Input *in = dynamic_cast<Fl_Input *>(w)) {
    static const char *texts[] = {"1", "0.5", "a", "", "1e-3", "x+y"};
    in->value(texts[pick(6)]);
  }
  else if(Fl_Button *b = dynamic_cast<Fl_Button *>(w)) {
    if(b->type() == FL_TOGGLE_BUTTON || dynamic_cast<Fl_Light_Button *>(w))
      b->value(!b->value());
  }
  else
    return false;
  w->do_callback();
  return true;
}

// the entries of a menu picked at random (a submenu followed)
static void pickMenuItem(Fl_Menu_ *m)
{
  if(!m->size()) return;
  int i = pick(m->size());
  const Fl_Menu_Item *item = &m->menu()[i];
  if(!item->text || item->submenu() || !item->callback() ||
     !item->active())
    return;
  std::string label = item->label() ? item->label() : "";
  // an entry ending in "..." opens a file chooser or a dialog; the native
  // choosers of macOS run their own loop, where no timer of ours can end them
  if(label.size() >= 3 && !label.compare(label.size() - 3, 3, "...")) return;
  log("menu " + label);
  m->picked(item);
}

static void oneAction()
{
  FlGui *g = FlGui::instance();
  // a modal window (a dialog, a chooser) in the way: Escape, then closed
  if(Fl_Window *m = Fl::modal()) {
    if(m->shown() && m != g->graph[0]->getWindow()) {
      log(std::string("modal: ") + (modalTries < 10 ? "Escape" : "close"));
      if(modalTries++ < 10)
        escapeIn(m);
      else {
        m->do_callback();
        modalTries = 0;
      }
      return;
    }
  }
  modalTries = 0;
  int what = pick(100);
  if(what < 22) {
    const std::vector<std::string> &keys = safeKeys();
    const std::string &k = keys[pick(keys.size())];
    log("key " + k);
    g->runShortcut(k);
  }
  else if(what < 34) {
    // a button of a module: an action, or an operation or a shape, which the
    // clicks that follow feed
    const char *modules[2] = {"Geometry", "Mesh"};
    const actionItem &module = GetActionMenu(modules[pick(2)]);
    std::vector<const actionItem *> items;
    std::function<void(const actionItem &)> gather = [&](const actionItem &m) {
      for(const actionItem &i : m.items)
        if(i.kind == ItemMenu)
          gather(i);
        else if(i.kind != ItemAction || i.run)
          items.push_back(&i);
    };
    gather(module);
    const actionItem *i = items[pick(items.size())];
    if(i->name == "mesh_partition" || i->name == "mesh_reclassify") return;
    log("module " + i->name);
    runItem(*i);
    if(sceneTool::current()) {
      for(int k = 0, n = pick(4); k < n; k++) click(unit(), unit());
      if(pick(2)) click(0.5, 0.5, true);
      log("  then " + std::string(pick(3) ? "e" : "q"));
      g->runShortcut(pick(3) ? "selection_end" : "selection_quit");
    }
  }
  else if(what < 46) {
    // a parameter of the ONELAB tree, or Check or Run
    std::vector<Fl_Widget *> all;
    walk(g->onelab, all);
    std::vector<Fl_Widget *> fields;
    for(Fl_Widget *w : all)
      if(w->callback() && !w->as_group() &&
         !dynamic_cast<Fl_Tree *>(w))
        fields.push_back(w);
    if(fields.empty()) return;
    Fl_Widget *w = fields[pick(fields.size())];
    std::string label = w->label() ? w->label() : "";
    if(label == "Check" || label == "Run" || label == "Stop" || label == "Kill")
      return;
    if(pick(8) == 0) {
      log(pick(2) ? "onelab check" : "onelab compute");
      if(pick(2)) onelabCheck(); else onelabCompute();
      return;
    }
    if(poke(w)) log("tree " + label);
  }
  else if(what < 58) {
    // a widget of the option window, or of a tool window
    std::vector<Fl_Window *> windows = {g->options->win, g->visibility->win,
                                        g->clipping->win};
    Fl_Window *win = windows[pick(windows.size())];
    if(!win->shown()) {
      log("show " + std::string(win->label() ? win->label() : "window"));
      win->show();
      return;
    }
    std::vector<Fl_Widget *> all;
    walk(win, all);
    for(int tries = 0; tries < 10; tries++) {
      Fl_Widget *w = all[pick(all.size())];
      if(w->callback() && poke(w)) {
        log("widget " + std::string(w->label() ? w->label() : "") + " in " +
            (win->label() ? win->label() : "window"));
        break;
      }
    }
  }
  else if(what < 66) {
    // an entry of the menu bar, or of a menu button
    std::vector<Fl_Widget *> all;
    walk(g->graph[0]->getWindow(), all);
    std::vector<Fl_Menu_ *> menus;
    for(Fl_Widget *w : all)
      if(Fl_Menu_ *m = dynamic_cast<Fl_Menu_ *>(w))
        if(m->visible_r()) menus.push_back(m);
    if(!menus.empty()) pickMenuItem(menus[pick(menus.size())]);
  }
  else if(what < 86) {
    const char *kinds[3] = {"move", "drag", "wheel"};
    int k = pick(3);
    log(std::string("pointer ") + kinds[k]);
    pointer(k);
  }
  else if(what < 92) {
    const char *how = pick(2) ? "h" : "v";
    log(std::string("split ") + how);
    g->splitCurrentOpenglWindow(pick(3) ? how[0] : 'u', 0.3 + 0.4 * unit());
  }
  else if(what < 96) {
    // a top-level window closed through its callback (not the main one, not
    // the full screen scene, which is a top-level GL window)
    std::vector<Fl_Window *> windows;
    for(Fl_Window *w = Fl::first_window(); w; w = Fl::next_window(w))
      if(w != g->graph[0]->getWindow() && !dynamic_cast<openglWindow *>(w) &&
         !w->modal() && !w->parent() && w->callback())
        windows.push_back(w);
    if(windows.empty()) return;
    Fl_Window *w = windows[pick(windows.size())];
    log(std::string("close ") + (w->label() ? w->label() : "window"));
    w->do_callback();
  }
  else {
    log("views refreshed");
    g->updateViews(true);
  }
}

static void tick(void *)
{
  if(done) return;
  if(TimeOfDay() > stopAt) {
    done = true;
    log("time is up");
    // (a solver listening would wait forever)
    opt_solver_listen(0, GMSH_SET | GMSH_GUI, 0);
    return;
  }
  // the next tick is set first: an action may open a dialog that waits in a
  // loop of its own, and the next tick is what closes it
  Fl::repeat_timeout(0.05, tick);
  if(depth < 8) {
    depth++;
    oneAction();
    depth--;
  }
}

int main(int argc, char **argv)
{
  if(argc < 2) {
    printf("Usage: %s model.geo [seconds] [seed]\n", argv[0]);
    return 77;
  }
  double seconds = argc > 2 ? atof(argv[2]) : 60;
  unsigned seed = argc > 3 ? (unsigned)atoi(argv[3]) : 1;
  rng.seed(seed);
  printf("seed %u, %g s, %s\n", seed, seconds, argv[1]);
  std::vector<std::string> args = {"gui_fuzz", "-nopopup"};
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::option::setNumber("General.NativeFileChooser", 0);
  gmsh::option::setNumber("General.ConfirmOverwrite", 0);
  gmsh::fltk::initialize();
  // the model's own run of Gmsh (General.ExecutableFileName, which a script
  // may launch as a client) is the real one, not this program
  std::string exe = CTX::instance()->exeFileName;
  std::string::size_type slash = exe.find_last_of("/\\");
  if(slash != std::string::npos)
    CTX::instance()->exeFileName = exe.substr(0, slash + 1) + "gmsh";
  gmsh::open(argv[1]);
  stopAt = TimeOfDay() + seconds;
  Fl::add_timeout(0.5, tick);
  while(!done && FlGui::available()) Fl::wait(0.1);
  // the run goes on a little, so that what the last action started ends
  for(int i = 0; i < 20 && FlGui::available(); i++) Fl::wait(0.1);
  printf("%d actions, %d errors\n", actions, Msg::GetErrorCount());
  if(FlGui::available()) gmsh::fltk::finalize();
  gmsh::finalize();
  return 0;
}
