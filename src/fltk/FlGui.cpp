// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <algorithm>
#include <functional>
#include <map>
#include <mutex>
#include <sstream>
#include <string.h>
#include <FL/Fl.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Icon.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Copy_Surface.H>
#include <FL/Fl_Image.H>
#include "FlGui.h"
#include "sceneTool.h"
#include "gmshScheme.h"
#include "desktop.h"
#include "mainWindow.h"
#include "icons.h"
#include "drawContextFltk.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "gamepadWindow.h"
#include "GamePad.h"
#include "optionWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "statisticsWindow.h"
#include "visibilityWindow.h"
#include "highOrderToolsWindow.h"
#include "clippingWindow.h"
#include "partitionDialog.h"
#include "paletteWindow.h"
#include "classificationEditor.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "onelabContextWindow.h"
#include "onelabGroup.h"
#include "helpWindow.h"
#include "fileDialogs.h"
#include "windowPlacement.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "OS.h"
#include "MElement.h"
#include "PView.h"
#include "Plugin.h"
#include "OpenFile.h"
#include "XpmIcon.h"
#include "Options.h"
#include "CommandLine.h"
#include "Shortcuts.h"
#include "Actions.h"
#include "Context.h"
#include "StringUtils.h"
#include "gmshPopplerWrapper.h"
#include "PixelBuffer.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

// Widget lifetime and nested event loops: the rules of this interface.
//
// 1. Every event goes through FlGui::_dispatch(), which records the widgets
//    it is sent to (the one with the focus, the pushed one, the one under the
//    pointer) while it is handled.
// 2. Callbacks run nested event loops: meshing and solvers handle events
//    while they run (FlGui::check()), dialogs and popup menus have loops of
//    their own, and so does the API waiting for a selection
//    (FlGui::selectEntity()); the picks of the interface do not wait, they
//    are tools stepped by the events (see sceneTool). The events handled in
//    a nested loop may delete widgets, close windows, or close the whole
//    interface. So code that runs one checks after it that what it uses
//    still exists: FlGui::available() for the interface (FlGui::instance()
//    is null once it is gone), an Fl_Widget_Tracker for a widget.
// 3. A widget whose code may still be running (an event being handled was
//    sent to it) is never deleted directly: the lists made again (the ONELAB
//    tree, the context window) retire such rows with FlGui::retireInEvent(),
//    and they are deleted once no event targets them.

FlGui *FlGui::_instance = nullptr;
std::string FlGui::_openedThroughMacFinder = "";
bool FlGui::_finishedProcessingCommandLine = false;
std::thread::id FlGui::_mainThread;
int FlGui::drawing = 0;

bool FlGui::onMainThread() { return std::this_thread::get_id() == _mainThread; }

// check (now!) if there are any pending events, and process them
void FlGui::check(bool rateLimited)
{
  if(!onMainThread() || drawing > 0) return;

  static double lastRefresh = 0.;
  double start = TimeOfDay();
  if(rateLimited && CTX::instance()->guiRefreshRate > 0) {
    if(start - lastRefresh > 1. / CTX::instance()->guiRefreshRate) {
      lastRefresh = start;
      Fl::check();
    }
  }
  else {
    lastRefresh = start;
    Fl::check();
  }
}

// wait (possibly indefinitely) for any events, then process them
void FlGui::wait(bool force)
{
  if((!onMainThread() || drawing > 0) && !force) return;
  Fl::wait();
}

// wait (at most time seconds) for any events, then process them
void FlGui::wait(double time, bool force)
{
  if((!onMainThread() || drawing > 0) && !force) return;
  Fl::wait(time);
}

void FlGui::lock() { Fl::lock(); }

void FlGui::unlock() { Fl::unlock(); }

static void awake_cb(void *data)
{
  // without a GUI, nothing to update (instance() would create one)
  if(data && FlGui::available()) FlGui::instance()->updateViews(true);
}

void FlGui::awake(const std::string &action)
{
  if(action.empty())
    Fl::awake(awake_cb, nullptr);
  else
    Fl::awake(awake_cb, (void *)"update");
}

void FlGui::setOpenedThroughMacFinder(const std::string &name)
{
  _openedThroughMacFinder = name;
}

std::string FlGui::getOpenedThroughMacFinder()
{
  return _openedThroughMacFinder;
}

void FlGui::setFinishedProcessingCommandLine()
{
  _finishedProcessingCommandLine = true;
}

bool FlGui::getFinishedProcessingCommandLine()
{
  return _finishedProcessingCommandLine;
}

static int globalShortcut(int event)
{
  if(!FlGui::available()) return 0;
  return FlGui::instance()->testGlobalShortcuts(event);
}

static void simple_right_box_draw(int x, int y, int w, int h, Fl_Color c)
{
  fl_color(c);
  fl_rectf(x, y, w, h);
  fl_color(FL_DARK2);
  fl_line(x + w - 1, y, x + w - 1, y + h);
}

static void simple_top_box_draw(int x, int y, int w, int h, Fl_Color c)
{
  fl_color(c);
  fl_rectf(x, y, w, h);
  fl_color(FL_DARK2);
  fl_line(x, y, x + w, y);
}

// The one timer of the gamepad: its events read while it is active, then the
// graphic windows moved by it and its window of options updated; every half
// second while it is not active, to notice when it is
static void gamepad_handler(void *data)
{
  GamePad *pad = CTX::instance()->gamepad;
  if(!pad) return;
  if(pad->active) pad->read_event();
  if(FlGui::available()) {
    FlGui *gui = FlGui::instance();
    // (the fullscreen window included)
    for(openglWindow *gl : gui->openglWindows()) gl->gamepadStep();
    if(gui->options && gui->options->gmpdoption)
      gui->options->gmpdoption->update();
  }
  Fl::add_timeout(pad->active ? pad->frequency : .5, gamepad_handler, data);
}

// the windows inside a window (the docked tools, the graphics), which a
// redraw of the window does not reach
static void redrawWindowsIn(Fl_Group *g)
{
  for(int i = 0; i < g->children(); i++) {
    Fl_Widget *c = g->child(i);
    if(Fl_Window *w = c->as_window()) {
      w->redraw();
      redrawWindowsIn(w);
    }
    else if(Fl_Group *gg = c->as_group()) {
      redrawWindowsIn(gg);
    }
  }
}

void FlGui::applyColorScheme(bool redraw)
{
  static int first = true;
  static unsigned char r[3], g[3], b[3];

  if(first) {
    // store default (OS-dependent) interface colors:
    Fl::get_system_colors();
    Fl::get_color(FL_BACKGROUND2_COLOR, r[0], g[0], b[0]);
    Fl::get_color(FL_FOREGROUND_COLOR, r[1], g[1], b[1]);
    Fl::get_color(FL_SELECTION_COLOR, r[2], g[2], b[2]);
  }

  // the tooltips of FLTK, pale yellow with black text; the gmsh theme sets
  // its own
  Fl_Tooltip::color(
    fl_color_cube(FL_NUM_RED - 1, FL_NUM_GREEN - 1, FL_NUM_BLUE - 2));
  Fl_Tooltip::textcolor(FL_BLACK);

  // the interface drawn dark: asked for, or the desktop's when following it
  int scheme = CTX::instance()->guiColorScheme;
  CTX::instance()->guiDark =
    (scheme == 1) || (scheme == 2 && desktopDark() == 1);

  if(gmshScheme()) { applyGmshColors(CTX::instance()->guiDark); }
  else if(CTX::instance()->guiDark) { // dark mode
    Fl::set_color(FL_BACKGROUND_COLOR, 20, 20, 20);
    Fl::set_color(FL_BACKGROUND2_COLOR, 70, 70, 70);
    Fl::set_color(FL_FOREGROUND_COLOR, 220, 220, 220);
    for(int i = 0; i < FL_NUM_GRAY; i++) {
      double min = 0., max = 70.;
      int d = (int)(min + i * (max - min) / (FL_NUM_GRAY - 1.));
      Fl::set_color(fl_gray_ramp(i), d, d, d);
    }
    Fl::set_color(FL_SELECTION_COLOR, 200, 200, 200);
  }
  else { // light mode
    Fl::set_color(FL_BACKGROUND2_COLOR, r[0], g[0], b[0]);
    Fl::set_color(FL_FOREGROUND_COLOR, r[1], g[1], b[1]);
    Fl::set_color(FL_SELECTION_COLOR, r[2], g[2], b[2]);
    // the grey of the desktop (macOS, Qt), lighter than the one FLTK gives;
    // the ramp of greys for the frames follows
    Fl::background(236, 236, 236);
  }

  first = false;

  if(gmshScheme()) applyGmshScheme();

  // also change default box type here (to thin versions)
  Fl::set_boxtype(FL_UP_BOX, FL_THIN_UP_BOX);
  Fl::set_boxtype(FL_DOWN_BOX, FL_THIN_DOWN_BOX);
  Fl::set_boxtype(FL_UP_FRAME, FL_THIN_UP_FRAME);
  Fl::set_boxtype(FL_DOWN_FRAME, FL_THIN_DOWN_FRAME);

  // thinner scrollbars; in the gmsh theme thinner than FLTK draws the arrow
  // buttons at either end (see applyGmshScheme())
  Fl::scrollbar_size(gmshScheme() ? gmshScrollbarSize :
                                    std::max(10, FL_NORMAL_SIZE));

  if(redraw && available()) {
    gmshIconsRecolor();
    updateModeButtons();
    help->resetText();
    updateViews(true);
    for(Fl_Window *win = Fl::first_window(); win; win = Fl::next_window(win)) {
      win->redraw();
      redrawWindowsIn(win);
      titleBarColor(win);
    }
  }
}

// The desktop switched between light and dark, or may have: the interface
// follows when asked to (General.FltkColorScheme = 2)
void FlGui::desktopChanged()
{
  if(!available()) return;
  CTX *c = CTX::instance();
  if(c->guiColorScheme != 2 && c->colorScheme != 3) return;
  bool dark = (desktopDark() == 1);
  bool gui = (c->guiColorScheme == 2 && dark != (bool)c->guiDark);
  bool graphics = followDesktopColorScheme(dark);
  if(!gui && !graphics) return;
  if(gui) applyColorScheme(true);
  if(graphics) drawContext::global()->draw();
  // drawn now: the notification came while the loop waited for events, and
  // the windows inside the main one are only painted by a flush
  Fl::flush();
}

// the GUI may be gone when the desktop switches: not brought back by this
static void desktop_changed_cb()
{
  if(FlGui::available()) FlGui::instance()->desktopChanged();
}

static void watchDesktop()
{
  // the system is asked once, whatever the number of GUIs created
  static bool watched = false;
  if(!watched) watchDesktopAppearance(desktop_changed_cb);
  watched = true;
  // and whenever a window of Gmsh gets the focus back, where the system does
  // not tell (Linux)
  mainWindow::focusHook = desktop_changed_cb;
}

static void default_error_handler(const char *fmt, ...)
{
  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  if(!strcmp(str, "Insufficient GL support")) { // this should be fatal
    CTX::instance()->terminal = 1;
    Msg::Error("%s (FLTK internal error)", str);
    Msg::Error("Your system does not seem to support OpenGL - aborting");
    Msg::Exit(1);
  }
  else {
    Msg::Error("%s (FLTK internal error)", str);
  }
}

static void default_fatal_error_handler(const char *fmt, ...)
{
  char str[5000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  Msg::Error("%s (FLTK internal error)", str);
  Msg::Exit(1);
}

FlGui::FlGui(int argc, char **argv, bool quitShouldExit,
             void (*error_handler)(const char *fmt, ...))
  : _quitShouldExit(quitShouldExit), lastContextWindow(nullptr),
    fullscreen(nullptr)
{
  if(error_handler) {
    Fl::error = error_handler;
    Fl::fatal = error_handler;
  }
  else {
    Fl::error = default_error_handler;
    Fl::fatal = default_fatal_error_handler;
  }

#if defined(__APPLE__)
  // the defaults use %@, which leads to (lowercase) gmsh
  Fl_Mac_App_Menu::about = "About Gmsh";
  Fl_Mac_App_Menu::hide = "Hide Gmsh";
  Fl_Mac_App_Menu::quit = "Quit Gmsh";
  Fl_Mac_App_Menu::print = ""; // this sometimes crashes
#endif

  // tell fltk we're (potentially) in multi-threaded mode, once: the lock is
  // recursive, and Fl::wait() only releases one level of it
  static bool locked = false;
  if(!locked) Fl::lock();
  locked = true;
  _mainThread = std::this_thread::get_id();

  // set X display
  if(CTX::instance()->display.size())
    Fl::display(CTX::instance()->display.c_str());

  // add new box types (dx dy dw dh)
  Fl::set_boxtype(GMSH_SIMPLE_RIGHT_BOX, simple_right_box_draw, 0, 0, 1, 0);
  Fl::set_boxtype(GMSH_SIMPLE_TOP_BOX, simple_top_box_draw, 0, 1, 0, 1);

  // the graphics leave the colours used without a GUI, if they follow the desktop
  if(CTX::instance()->colorScheme == 3)
    followDesktopColorScheme(desktopDark() == 1);

  // apply color scheme before widget creation (noop if default color scheme is
  // selected), so that there's no color "flashing"
  applyColorScheme();

  // add gamepad handler
  if(CTX::instance()->gamepad)
    Fl::add_timeout(5., gamepad_handler, (void *)nullptr);

  // add global shortcuts
  Fl::add_handler(globalShortcut);
  // the buttons of the query and the measurement follow the tools
  sceneTool::changed = updateModeButtons;

  Fl::event_dispatch(_dispatch);

  // make sure a global drawing context is setup
  if(!drawContext::global()) drawContext::setGlobal(new drawContextFltk);

  // set default font size
  FL_NORMAL_SIZE = drawContext::global()->getFontSize();

  // handle themes and tooltip options
  // the gmsh scheme is ours, not one of FLTK (see gmshScheme.h)
  // one of the schemes of FLTK, or its stock look ("fltk")
  if(!gmshScheme())
    Fl::scheme(CTX::instance()->guiTheme == "fltk" ?
                 "base" :
                 CTX::instance()->guiTheme.c_str());
  Fl_Tooltip::size(FL_NORMAL_SIZE);

  // use retina resolution if available
  Fl::use_high_res_GL(CTX::instance()->highResolutionGraphics);

  // register image formats not in core fltk library (jpeg/png)
  fl_register_images();

  // load default system icons (for file browser)
  Fl_File_Icon::load_system_icons();

  // the icon of all the windows
  Fl_RGB_Image icon(&gmsh_icon_pixmap);
  Fl_Window::default_icon(&icon);

  // add callback to respond to Mac Finder
#if defined(__APPLE__)
  fl_open_callback(OpenProjectMacFinder);
  fl_mac_set_about(help_about_cb, nullptr);
#endif

  // don't move input dialogs to follow mouse
  fl_message_hotspot(0);

  // create main graphic window (note that we create all the windows even if
  // some are not displayed, since the shortcuts should be valid even for hidden
  // windows, and we don't want to test for widget existence every time)
  graph.push_back(
    new graphicWindow(true, CTX::instance()->numTiles,
                      CTX::instance()->detachedMenu ? true : false));

  if (argc > 0 && argv && argv[0]) {
    graph[0]->getWindow()->show(1, argv);
  }
  else {
    graph[0]->getWindow()->show();
  }
  if(graph[0]->getMenuWindow()) graph[0]->getMenuWindow()->show();

  // re-apply color scheme (necessary after open_display to get the selection
  // color and boxtypes right)
  applyColorScheme();
  // the interface follows the desktop between light and dark when asked to
  watchDesktop();

  // graphic window should have the initial focus (so we can e.g. directly loop
  // through time steps with the keyboard)
  Fl::focus(graph[0]->gl[0]);

  // get onelab tree group (FIXME: should clean this up)
  onelab = graph.back()->getMenu();

  // create additional graphic windows
  for(int i = 1; i < CTX::instance()->numWindows; i++) {
    graphicWindow *g = new graphicWindow(false, CTX::instance()->numTiles);
    g->getWindow()->resize(
      graph.back()->getWindow()->x() + 10, graph.back()->getWindow()->y() + 10,
      graph.back()->getWindow()->w(), graph.back()->getWindow()->h());
    g->getWindow()->show();
    graph.push_back(g);
  }
  setGraphicTitle(GModel::current()->getFileName());

  // create window that will be used for fullscreen display
  fullscreen = new openglWindow(100, 100, 100, 100);
  fullscreen->mode(openglWindowMode());
  fullscreen->end();
  // closed by the window manager (Alt+F4, the close button of X11): back to
  // the graphic windows, which the default callback would leave hidden, the
  // program then ending without asking
  fullscreen->callback(
    [](Fl_Widget *, void *) { window_cb(nullptr, (void *)"fullscreen"); });

  // create all other windows
  options = new optionWindow(CTX::instance()->deltaFontSize);
  fields = new fieldWindow(CTX::instance()->deltaFontSize);
  plugins = new pluginWindow(CTX::instance()->deltaFontSize);
  stats = new statisticsWindow(CTX::instance()->deltaFontSize);
  visibility = new visibilityWindow(CTX::instance()->deltaFontSize);
  highordertools = new highOrderToolsWindow(CTX::instance()->deltaFontSize);
  clipping = new clippingWindow(CTX::instance()->deltaFontSize);
  partition = new partitionWindow(CTX::instance()->deltaFontSize);
  classify = new classificationEditor(CTX::instance()->deltaFontSize);
  manip = new manipWindow(CTX::instance()->deltaFontSize);
  elementaryContext =
    new elementaryContextWindow(CTX::instance()->deltaFontSize);
  transformContext = new transformContextWindow(CTX::instance()->deltaFontSize);
  meshContext = new meshContextWindow(CTX::instance()->deltaFontSize);
  physicalContext = new physicalContextWindow(CTX::instance()->deltaFontSize);
  onelabContext = new onelabContextWindow(CTX::instance()->deltaFontSize);
  help = new helpWindow();

  // draw
  for(std::size_t i = 0; i < graph.size(); i++)
    for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
      graph[i]->gl[j]->redraw();

  // the tool windows dock, and are named for General.FloatingTools
  const std::pair<Fl_Window *, const char *> tools[] = {
    {options->win, "options"},
    {plugins->win, "plugins"},
    {fields->win, "fields"},
    {visibility->win, "visibility"},
    {clipping->win, "clipping"},
    {manip->win, "manipulator"},
    {stats->win, "statistics"},
    {highordertools->win, "highorder"},
    {elementaryContext->win, "elementary"},
    {physicalContext->win, "physical"},
    {transformContext->win, "transform"},
    {meshContext->win, "mesh"},
    {onelabContext->win, "onelab"},
    {classify->window, "reclassify"},
    {partition->win, "partition"}};
  for(auto &t : tools) {
    if(!t.first) continue;
    paletteWindow *p = (paletteWindow *)t.first;
    p->dockable(true);
    p->name(t.second);
    _tools.push_back(p);
  }
  applyFloatingTools();
  // what docked tools skip while hidden, refreshed when shown again
  ((paletteWindow *)visibility->win)
    ->whenRevealed(
      [](void *) { visibility_cb(nullptr, (void *)"redraw_only"); }, nullptr);
  ((paletteWindow *)stats->win)
    ->whenRevealed([](void *) { FlGui::instance()->stats->compute(false); },
                   nullptr);
  ((paletteWindow *)manip->win)
    ->whenRevealed([](void *) { FlGui::instance()->manip->update(); }, nullptr);

  if(CTX::instance()->showOptionsOnStartup) options->win->show();
  if(CTX::instance()->showMessagesOnStartup) graph[0]->showMessages();
}

FlGui::~FlGui()
{
  // the retired widgets go with their windows
  _retiredWidgets.clear();

  // copy back to temp values, in case we'd like to retrieve them after the GUI
  // has been closed
  drawContext *c = getCurrentDrawContext();
  if(c) {
    for(int i = 0; i < 3; i++) {
      CTX::instance()->tmpRotation[i] = c->r[i];
      CTX::instance()->tmpTranslation[i] = c->t[i];
      CTX::instance()->tmpScale[i] = c->s[i];
    }
    for(int i = 0; i < 4; i++) {
      CTX::instance()->tmpQuaternion[i] = c->quaternion[i];
    }
  }

  // what was registered for this GUI, which a new one registers again
  Fl::remove_handler(globalShortcut);
  Fl::event_dispatch(nullptr);
  sceneTool::changed = nullptr;
  Fl::remove_timeout(gamepad_handler);
  drawContext::setDrawGeomTransientFunction(nullptr);

  // each window off the GUI as it goes, so that none is reached once freed
  // (the graphic windows first, which give the docked tools back)
  while(graph.size()) {
    graphicWindow *g = graph.back();
    graph.pop_back();
    delete g;
  }
  auto gone = [](auto *&w) {
    delete w;
    w = nullptr;
  };
  gone(options);
  gone(fields);
  gone(plugins);
  gone(stats);
  gone(visibility);
  gone(highordertools);
  gone(clipping);
  gone(partition);
  gone(classify);
  gone(manip);
  gone(elementaryContext);
  gone(transformContext);
  gone(physicalContext);
  gone(onelabContext);
  gone(meshContext);
  gone(help);
  gone(fullscreen);
}

bool FlGui::available() { return _instance != nullptr; }

bool FlGui::inEvent(Fl_Widget *w)
{
  if(_eventWidgets.empty()) return false;
  for(Fl_Widget *t : {Fl::focus(), Fl::pushed(), Fl::belowmouse()})
    if(t && w->contains(t)) return true;
  for(Fl_Widget **targets : _eventWidgets)
    for(int i = 0; i < 3; i++)
      if(targets[i] && w->contains(targets[i])) return true;
  return false;
}

std::vector<Fl_Widget **> FlGui::_eventWidgets;
std::vector<FlGui::_retired> FlGui::_retiredWidgets;

std::vector<Fl_Widget *>
FlGui::retireInEvent(const std::vector<Fl_Widget *> &widgets,
                     std::list<std::string> &strings)
{
  // the widgets retired before, which no event targets any more, deleted
  // first (a long computation, whose event lasts, would otherwise keep one
  // set per refresh)
  _deleteRetired(false);
  std::vector<Fl_Widget *> free;
  std::shared_ptr<std::list<std::string>> kept;
  for(Fl_Widget *w : widgets) {
    if(!inEvent(w)) {
      free.push_back(w);
      continue;
    }
    if(!kept) {
      kept = std::make_shared<std::list<std::string>>();
      kept->splice(kept->end(), strings);
    }
    _retiredWidgets.push_back({w, kept});
  }
  return free;
}

void FlGui::_deleteRetired(bool all)
{
  std::vector<_retired> keep;
  for(_retired &r : _retiredWidgets) {
    if(!all && inEvent(r.widget))
      keep.push_back(r);
    else
      Fl::delete_widget(r.widget);
  }
  _retiredWidgets.swap(keep);
}

int FlGui::_dispatch(int event, Fl_Window *win)
{
  Fl_Widget *targets[3] = {Fl::focus(), Fl::pushed(), Fl::belowmouse()};
  // however the event ends, e.g. by an exception the API catches
  struct handled {
    Fl_Widget **targets;
    handled(Fl_Widget **t) : targets(t)
    {
      for(int i = 0; i < 3; i++) Fl::watch_widget_pointer(targets[i]);
      _eventWidgets.push_back(targets);
    }
    ~handled()
    {
      _eventWidgets.pop_back();
      for(int i = 0; i < 3; i++) Fl::release_widget_pointer(targets[i]);
    }
  };
  int ret;
  {
    handled h(targets);
    ret = gmshScheme() ? gmshSchemeHandle(event, win) : Fl::handle_(event, win);
  }
  // no widget code is running once the first event is handled
  if(_eventWidgets.empty()) _deleteRetired(true);
  return ret;
}

FlGui *FlGui::create(int argc, char **argv, bool quitShouldExit,
                     void (*error_handler)(const char *fmt, ...))
{
  if(!_instance) {
    _instance = new FlGui(argc, argv, quitShouldExit, error_handler);
    // set all options in the new GUI
    InitOptionsGUI(0);
    // say welcome!
    Msg::ResetErrorCounter();
    Msg::StatusBar(false, "Gmsh %s", GetGmshVersion());
    // log the following for bug reports
    Msg::Direct("-------------------------------------------------------");
    PrintBuildInfo();
    Msg::Direct("-------------------------------------------------------");
    // update views (in case the GUI is created after some data has been loaded)
    _instance->updateViews(true);
    // set global bounding box in CTX (necessary if we run the gui without any
    // model/post-processing data)
    SetBoundingBox();
  }
  return _instance;
}

void FlGui::destroy()
{
  if(!_instance) return;

  // the tool under way ends while its windows are there
  sceneTool::stop();
  _instance->onelabContext->disableRedraw();

  // hide all windows (in case they are not tracked by FlGui)...
  std::vector<Fl_Window *> wins;
  for(Fl_Window *win = Fl::first_window(); win; win = Fl::next_window(win))
    wins.push_back(win);
  for(std::size_t i = 0; i < wins.size(); i++) wins[i]->hide();

  // process remaining events
  Fl::check();
  // then delete the widgets they scheduled for deletion, as the windows,
  // deleting their children, would not take them off the list
  Fl::do_widget_deletion();

  delete _instance;
  _instance = nullptr;
}

int FlGui::run(const std::string &optionFileName)
{
  // if optionFileName is given, we load the file before entering the event
  // loop, and we automatically save the options when it ends
  if(optionFileName.size()) {
    MergeFile(optionFileName, false);
  }

  // draw the scene
  drawContext::global()->draw(false);

  int ret = Fl::run();

  if(optionFileName.size()) {
    PrintOptions(0, GMSH_FULLRC, 1, 0, optionFileName.c_str());
    int old = CTX::instance()->expertMode;
    CTX::instance()->expertMode = 1; // disable warning if non-geo file
    visibility_save(optionFileName);
    CTX::instance()->expertMode = old;
  }

  return ret;
}

// the FLTK code of a shortcut of the table
static int fltkCode(const Shortcut &s)
{
  int k = s.key;
  if(k >= KeyF1 && k < KeyF1 + 12)
    k = FL_F + 1 + (k - KeyF1);
  else if(k == KeyEscape)
    k = FL_Escape;
  else if(k == KeyLeft)
    k = FL_Left;
  else if(k == KeyRight)
    k = FL_Right;
  else if(k == KeyUp)
    k = FL_Up;
  else if(k == KeyDown)
    k = FL_Down;
  else if(k == KeyPageUp)
    k = FL_Page_Up;
  else if(k == KeyPageDown)
    k = FL_Page_Down;
  if(s.mods & ModCommand) k += FL_COMMAND;
  if(s.mods & ModShift) k += FL_SHIFT;
  if(s.mods & ModAlt) k += FL_ALT;
  return k;
}

int wrappedHeight(Fl_Box *b, int w)
{
  fl_font(b->labelfont(), b->labelsize());
  int tw = w - 6, th = 0;
  fl_measure(b->label(), tw, th, 0);
  return th + WB;
}

int fltkShortcut(const char *action, bool systemBar)
{
  for(const ShortcutEntry &e : GetShortcuts())
    if(!strcmp(e.action, action))
      return (systemBar && e.inWindowBarOnly) ? 0 : fltkCode(e.shortcut);
  Msg::Error("Unknown shortcut action '%s'", action);
  return 0;
}

// the event is this shortcut
static bool fltkTest(const Shortcut &s)
{
  if(s.mods & AnyModifiers)
    return Fl::event_key() == (fltkCode(s) & FL_KEY_MASK);
  return Fl::test_shortcut(fltkCode(s));
}

int FlGui::testGlobalShortcuts(int event)
{
  // we only handle shortcuts here
  if(event != FL_SHORTCUT) return 0;

  // (a key of the menu bar runs its action here too, also when the system
  // menu bar of macOS did not take it)
  int status = 0;
  for(const ShortcutEntry &e : GetShortcuts()) {
    if(!fltkTest(e.shortcut)) continue;
#if defined(__APPLE__)
    // (Cmd+H hides the application)
    if(e.inWindowBarOnly && graph[0]->hasSystemMenuBar()) continue;
#endif
    int st = runShortcut(e.action);
    if(!st) continue; // not for this build
    // a key passed on is handled, but as if it had not been: what is under
    // the mouse reads it too
    status = e.passOn ? 0 : st;
    break;
  }

  if(status == 2) {
    drawContext::global()->draw();
    return 1;
  }
  else if(status == 1)
    return 1;
  else
    return 0;
}

int FlGui::testArrowShortcuts()
{
  // the keys the 3D view handles itself when it has the focus, before FLTK
  // moves the focus with them: the arrows and Page Up/Down
  for(const ShortcutEntry &e : GetShortcuts()) {
    int key = e.shortcut.key;
    if(key >= KeyLeft && key <= KeyPageDown && fltkTest(e.shortcut))
      return runShortcut(e.action) ? 1 : 0;
  }
  return 0;
}

// the selection flags of all the scenes (see sceneView::selectionStep())
static void setSelectionFlag(int sceneView::*flag)
{
  for(openglWindow *gl : FlGui::instance()->openglWindows()) gl->*flag = 1;
  // the tool under way takes it now; without one, the API waiting for a
  // selection reads it (see openglWindow::selectEntity())
  sceneTool::step();
}

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

// Escape leaves the full screen, or cancels a lasso, or toggles the mouse
// selection
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
    setSelectionFlag(&sceneView::quitSelection);
    return;
  }
  if(FlGui::instance()->fullscreen->shown())
    window_cb(nullptr, (void *)"fullscreen");
}

// the plugins of the view shown in the options window
static void plugins_view()
{
  int view = FlGui::instance()->options->view.index;
  if(PView::list.size())
    FlGui::instance()->plugins->show(
      (view >= 0 && view < (int)PView::list.size()) ? view : 0);
}

const std::map<std::string, fltkAction> &keyboardActions()
{
  static const std::map<std::string, fltkAction> actions = {
    // reloading and running
    {"project_reload", {[](int) { onelab_reload_cb(nullptr, nullptr); }}},
    {"solver_run", {[](int) { onelab_cb(nullptr, (void *)"compute"); }}},
    // the modules of the tree
    {"module_geometry",
     {[](int) { FlGui::instance()->toggleModule("Geometry"); }}},
    {"module_mesh", {[](int) { FlGui::instance()->toggleModule("Mesh"); }}},
    {"module_solver", {[](int) { FlGui::instance()->toggleModule("Solver"); }}},
    {"module_post",
     {[](int) { FlGui::instance()->toggleModule("Post-processing"); }}},
    // a selection under way
    {"selection_end",
     {[](int) { setSelectionFlag(&sceneView::endSelection); }}},
    {"selection_undo",
     {[](int) { setSelectionFlag(&sceneView::undoSelection); }}},
    {"selection_quit",
     {[](int) { setSelectionFlag(&sceneView::quitSelection); }}},
    // placing an elementary entity with the mouse
    {"freeze_x", {[](int) { freezeAxis(0, false); }}},
    {"freeze_y", {[](int) { freezeAxis(1, false); }}},
    {"freeze_z", {[](int) { freezeAxis(2, false); }}},
    {"freeze_but_x", {[](int) { freezeAxis(0, true); }}},
    {"freeze_but_y", {[](int) { freezeAxis(1, true); }}},
    {"freeze_but_z", {[](int) { freezeAxis(2, true); }}},
    {"escape", {[](int) { escape(); }}},
    {"mouse_selection", {[](int) { mouse_selection_cb(nullptr, nullptr); }}},
    // the windows
    {"options_solver", {[](int) { solver_options_cb(nullptr, nullptr); }}},
    {"options_post", {[](int) { post_options_cb(nullptr, nullptr); }}},
    {"plugins_view", {[](int) { plugins_view(); }}},
    // the point of view, as the buttons of the status bar (which read Shift
    // and Ctrl: the other side, reset, sync the viewports); the web page does
    // it in RunSceneShortcut()
    {"view_x", {[](int) { status_xyz1p_cb(nullptr, (void *)"x"); }}},
    {"view_y", {[](int) { status_xyz1p_cb(nullptr, (void *)"y"); }}},
    {"view_z", {[](int) { status_xyz1p_cb(nullptr, (void *)"z"); }}},
    {"view_1_1", {[](int) { status_xyz1p_cb(nullptr, (void *)"1:1"); }}},
    {"view_3d", {[](int) { status_xyz1p_cb(nullptr, (void *)"3d"); }}},
    // the time steps and the views, on the arrows
    {"time_step_prev",
     {[](int) { status_play_manual(1, -CTX::instance()->post.animStep); }}},
    {"time_step_next",
     {[](int) { status_play_manual(1, CTX::instance()->post.animStep); }}},
    {"view_prev",
     {[](int) { status_play_manual(0, -CTX::instance()->post.animStep); }}},
    {"view_next",
     {[](int) { status_play_manual(0, CTX::instance()->post.animStep); }}},
#if defined(HAVE_POPPLER)
    {"page_prev", {[](int) {
       gmshPopplerWrapper::setCurrentPageDown();
       drawContext::global()->draw();
     }}},
    {"page_next", {[](int) {
       gmshPopplerWrapper::setCurrentPageUp();
       drawContext::global()->draw();
     }}},
#endif
  };
  return actions;
}

// What each action of the shortcut table does: an action of the registry (see
// Actions.h) or one the interface does (see findAction() in actionMenus.cpp:
// the modules, the menu bar and the keys above) runs as its items do; those
// that only change the scene are those of RunSceneShortcut(), shared with the
// web page. Returns 0 for an action not handled here (or not available now:
// the key then goes on, as if it had no shortcut), 1 when done, 2 when the
// scene must be drawn again.
int FlGui::runShortcut(const std::string &a)
{
  actionItem item{"", ActionRun, a, {}, "", "", {}};
  if(canRunItem(item)) {
    runItem(item);
    return 1;
  }
  if(IsAction(a)) return 0;
  // the display, the views and the time steps, as in the web page
  return RunSceneShortcut(a, 0, nullptr);
}

void FlGui::setGraphicTitle(const std::string &title)
{
  for(std::size_t i = 0; i < graph.size(); i++) {
    std::ostringstream sstream;
    if(title.empty())
      sstream << "Gmsh";
    else if(!i)
      sstream << "Gmsh - " << title;
    else
      sstream << "Gmsh - " << title << " [" << i << "]";
    graph[i]->setTitle(sstream.str());
  }
}

void FlGui::updateViews(bool numberOfViewsHasChanged)
{
  for(std::size_t i = 0; i < graph.size(); i++) graph[i]->checkAnimButtons();
  if(numberOfViewsHasChanged) {
    rebuildTree();
    // this GUI may have been destroyed by the events the rebuild processed
    if(_instance != this) return;
    visibility->updatePerWindow();
    options->resetBrowser();
    options->resetExternalViewList();
    fields->loadFieldViewList();
    plugins->resetViewBrowser();
    clipping->resetBrowser();
    updateStatistics(false);
  }
}

void FlGui::updateFields()
{
#if defined(HAVE_MESH)
  fields->editField(GModel::current()->getFields()->get(fields->selected_id));
#endif
}

void FlGui::resetVisibility()
{
  if(visibility->win->shown()) visibility_cb(nullptr, nullptr);
  if(help->options->shown()) help_options_cb(nullptr, nullptr);
  updateStatistics(false);
}

void FlGui::updateStatistics(bool qualities)
{
  if(stats->win->shown()) stats->compute(qualities);
}

std::vector<openglWindow *> FlGui::openglWindows()
{
  std::vector<openglWindow *> all;
  for(auto g : graph) all.insert(all.end(), g->gl.begin(), g->gl.end());
  if(fullscreen) all.push_back(fullscreen);
  return all;
}

openglWindow *FlGui::getCurrentOpenglWindow()
{
  if(openglWindow::getLastHandled())
    return openglWindow::getLastHandled();
  else
    return graph[0]->gl[0];
}

void FlGui::setCurrentOpenglWindow(int which)
{
  int ii = 0;
  for(std::size_t i = 0; i < graph.size(); i++) {
    for(std::size_t j = 0; j < graph[i]->gl.size(); j++) {
      if(which == ii++) {
        openglWindow::setLastHandled(graph[i]->gl[j]);
        return;
      }
    }
  }
  openglWindow::setLastHandled(graph[0]->gl[0]);
}

void FlGui::splitCurrentOpenglWindow(char how, double ratio)
{
  openglWindow *g = getCurrentOpenglWindow();
  for(std::size_t i = 0; i < graph.size(); i++) {
    if(graph[i]->split(g, how, ratio)) break;
  }
}

void FlGui::copyCurrentOpenglWindowToClipboard()
{
  // the scene as it is drawn, at the resolution of the screen, given to the
  // clipboard as a picture of the size of the window (FLTK makes the formats
  // of each platform)
  // (the sizes read first: drawing may process events, and the pane go)
  openglWindow *gl = getCurrentOpenglWindow();
  int w = gl->pixel_w(), h = gl->pixel_h(), sw = gl->w(), sh = gl->h();
  PixelBuffer buffer(w, h, GL_RGB, GL_UNSIGNED_BYTE);
  buffer.fill();
  // (the rows of the picture from the top, those of OpenGL from the bottom)
  std::vector<unsigned char> rows(3 * w * h);
  unsigned char *pixels = (unsigned char *)buffer.getPixels();
  for(int j = 0; j < h; j++)
    memcpy(&rows[3 * w * j], pixels + 3 * w * (h - 1 - j), 3 * w);
  Fl_RGB_Image image(rows.data(), w, h, 3);
  image.scale(sw, sh, 0, 1);
  Fl_Copy_Surface *surface = new Fl_Copy_Surface(sw, sh);
  Fl_Surface_Device::push_current(surface);
  image.draw(0, 0);
  Fl_Surface_Device::pop_current();
  delete surface; // which loads the clipboard
}

drawContext *FlGui::getCurrentDrawContext()
{
  return getCurrentOpenglWindow()->getDrawContext();
}

char FlGui::selectEntity(int type, bool pickElements)
{
  return getCurrentOpenglWindow()->selectEntity(
    type, pickElements, selectedVertices, selectedEdges, selectedFaces,
    selectedRegions, selectedElements, selectedPoints, selectedViews);
}

void FlGui::setStatus(const std::string &msg, bool opengl)
{
  if(!onMainThread()) return;
  if(!opengl) {
    _lastStatus = msg;
    static char buff[1024];
    std::string tmp = std::string(" ") + msg;
    int ne = Msg::GetErrorCount(), nw = Msg::GetWarningCount();
    if((ne || nw) && graph[0]->getMessageHeight() < FL_NORMAL_SIZE) {
      tmp += "  -  ";
      char n[128];
      sprintf(n, "%d", ne ? ne : nw);
      tmp += n;
      tmp += (ne > 1) ? " Errors" :
             ne       ? " Error" :
             (nw > 1) ? " Warnings" :
                        " Warning";
      tmp += " : Click to show messages [ ... ";
      tmp += (ne ? Msg::GetFirstError() : Msg::GetFirstWarning());
      tmp += " ... ]";
    }
    strncpy(buff, tmp.c_str(), sizeof(buff) - 1);
    buff[sizeof(buff) - 1] = '\0';
    for(std::size_t i = 0; i < graph.size(); i++) {
      graph[i]->getProgress()->label(buff);
      graph[i]->getProgress()->redraw();
    }
  }
  else {
    openglWindow *gl = getCurrentOpenglWindow();
    std::vector<std::string> m = SplitString(msg, '\n');
    if(m.size() > 0)
      gl->screenMessage[0] = m[0];
    else
      gl->screenMessage[0].clear();
    if(m.size() > 1)
      gl->screenMessage[1] = m[1];
    else
      gl->screenMessage[1].clear();
    drawContext::global()->draw();
  }
}

void FlGui::setLastStatus(int col)
{
  if(!onMainThread()) return;
  for(std::size_t i = 0; i < graph.size(); i++) {
    if(col >= 0 && graph[0]->getMessageHeight() < FL_NORMAL_SIZE) {
      if(CTX::instance()->guiDark) // dark
        graph[i]->getProgress()->color(col);
      else
        graph[i]->getProgress()->labelcolor(col);
    }
    else {
      graph[i]->getProgress()->color(FL_BACKGROUND_COLOR);
      graph[i]->getProgress()->labelcolor(FL_FOREGROUND_COLOR);
    }
  }
  setStatus(_lastStatus);
}

void FlGui::setProgress(const std::string &msg, double val, double min,
                        double max)
{
  if(!onMainThread()) return;
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
    if(FlGui::instance()->graph[i]->getProgress()->value() != val)
      FlGui::instance()->graph[i]->getProgress()->value(val);
    if(FlGui::instance()->graph[i]->getProgress()->minimum() != min)
      FlGui::instance()->graph[i]->getProgress()->minimum(min);
    if(FlGui::instance()->graph[i]->getProgress()->maximum() != max)
      FlGui::instance()->graph[i]->getProgress()->maximum(max);
  }
  setStatus(msg);
}

void FlGui::applyFloatingTools()
{
  std::string names = "," + CTX::instance()->floatingTools + ",";
  names.erase(std::remove(names.begin(), names.end(), ' '), names.end());
  for(paletteWindow *p : toolWindows()) {
    bool floating = names.find("," + p->name() + ",") != std::string::npos;
    if(floating != p->floating()) setToolFloating(p, floating);
  }
}

void FlGui::setToolFloating(paletteWindow *p, bool floating)
{
  p->floating(floating);
  if(!p->isOpen()) return;
  // an open tool moves: a docked one leaves the dock when hidden, and a tool
  // on the desktop joins it when shown
  if(floating && p->parent()) p->hide();
  p->show();
}

void FlGui::toggleCurrentTool()
{
  // the tool holding the focus, else the one shown in the dock used last
  paletteWindow *p = nullptr;
  for(Fl_Widget *w = Fl::focus(); w && !p; w = w->parent()) {
    p = dynamic_cast<paletteWindow *>(w);
    if(p && !p->dockable()) p = nullptr;
  }
  if(!p) p = graph[0]->currentDockedTool();
  if(!p || !p->isOpen()) return;
  setToolFloating(p, p->parent() != nullptr);
  storeFloatingTools();
}

void FlGui::storeFloatingTools()
{
  std::string names;
  for(paletteWindow *p : toolWindows()) {
    if(!p->floating()) continue;
    names += (names.empty() ? "" : ",") + p->name();
  }
  CTX::instance()->floatingTools = names;
}

void FlGui::dockTools(bool dock)
{
  std::string names;
  if(!dock)
    for(paletteWindow *p : toolWindows())
      names += (names.empty() ? "" : ",") + p->name();
  opt_general_floating_tools(0, GMSH_SET | GMSH_GUI, names);
}

void FlGui::storeCurrentWindowsInfo()
{
  CTX::instance()->glPosition[0] = graph[0]->getWindow()->x();
  CTX::instance()->glPosition[1] = graph[0]->getWindow()->y();
  CTX::instance()->glSize[0] = graph[0]->getGlWidth();
  CTX::instance()->glSize[1] = graph[0]->getGlHeight();
  CTX::instance()->msgSize = graph[0]->getMessageHeight() ?
                               graph[0]->getMessageHeight() :
                               CTX::instance()->msgSize;
  CTX::instance()->menuSize[0] = graph[0]->getMenuWidth();
  if(graph[0]->isMenuDetached()) {
    CTX::instance()->detachedMenu = 1;
    CTX::instance()->menuSize[1] = graph[0]->getMenuHeight();
    storeWindowOffset(graph[0]->getMenuWindow(), CTX::instance()->menuOffset);
  }
  else
    CTX::instance()->detachedMenu = 0;
  storeWindowOffset(options->win, CTX::instance()->optOffset);
  CTX::instance()->optHeight = ((paletteWindow *)options->win)->desktopH();
  storeWindowOffset(plugins->win, CTX::instance()->pluginOffset);
  CTX::instance()->pluginSize[0] = ((paletteWindow *)plugins->win)->desktopW();
  CTX::instance()->pluginSize[1] = ((paletteWindow *)plugins->win)->desktopH();
  storeWindowOffset(fields->win, CTX::instance()->fieldOffset);
  CTX::instance()->fieldSize[0] = ((paletteWindow *)fields->win)->desktopW();
  CTX::instance()->fieldSize[1] = ((paletteWindow *)fields->win)->desktopH();
  storeWindowOffset(stats->win, CTX::instance()->statOffset);
  storeWindowOffset(visibility->win, CTX::instance()->visOffset);
  storeWindowOffset(highordertools->win, CTX::instance()->hotOffset);
  storeWindowOffset(clipping->win, CTX::instance()->clipOffset);
  if(partition->win)
    storeWindowOffset(partition->win, CTX::instance()->partOffset);
  storeWindowOffset(classify->window, CTX::instance()->reclassifyOffset);
  storeWindowOffset(manip->win, CTX::instance()->manipOffset);
  storeWindowOffset(lastContextWindow ? lastContextWindow :
                                        elementaryContext->win,
                    CTX::instance()->ctxOffset);
#if defined(HAVE_3M)
  storeWindowPosition3M();
#endif
  fileChooserStoreOffset(CTX::instance()->fileChooserOffset);
}

// Callbacks

void redraw_cb(Fl_Widget *w, void *data) { drawContext::global()->draw(); }

void window_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);

  if(str == "minimize") {
    // the docked tool windows go with the main window
    auto iconize = [](Fl_Window *w) {
      if(w->shown() && !w->parent()) w->iconize();
    };
    FlGui *g = FlGui::instance();
    for(std::size_t i = 0; i < g->graph.size(); i++)
      iconize(g->graph[i]->getWindow());
    for(paletteWindow *p : g->toolWindows()) iconize(p);
  }
  else if(str == "zoom") {
    // the window manager's maximization: it fills the work area title bar
    // included (a resize to the work area sizes the inside of the window, and
    // the title bar then pushes its bottom off the screen), and it remembers
    // the size to go back to
    Fl_Window *win = FlGui::instance()->graph[0]->getWindow();
    if(win->maximize_active())
      win->un_maximize();
    else
      win->maximize();
  }
  else if(str == "fullscreen") {
    // a switch waits for the windows to be drawn, processing events: another
    // one asked for meanwhile is ignored
    static bool switching = false;
    if(switching) return;
    struct switched {
      ~switched() { switching = false; }
    } switched;
    switching = true;
    if(!FlGui::instance()->fullscreen->shown()) {
      // resize to the size of the screen of the current graphic window first,
      // in case fullscreen does not work
      int x, y, w, h;
      Fl::screen_xywh(
        x, y, w, h,
        windowScreen(FlGui::instance()->getCurrentOpenglWindow()->top_window()));
      FlGui::instance()->fullscreen->resize(x, y, w, h);
      // setting resizable() is necessary with recent FLTK versions (1.4)
      FlGui::instance()->fullscreen->resizable(FlGui::instance()->fullscreen);
      FlGui::instance()->fullscreen->valid(0);
      FlGui::instance()->fullscreen->show();
      FlGui::instance()->fullscreen->fullscreen();
      // (not drawn at all if closed meanwhile, nor ever if the window manager
      // does not show it: 2 s at most)
      double start = TimeOfDay();
      while(FlGui::available() && FlGui::instance()->fullscreen->shown() &&
            !FlGui::instance()->fullscreen->valid() && TimeOfDay() - start < 2.)
        FlGui::wait(0.05);
      if(!FlGui::available() || !FlGui::instance()->fullscreen->shown()) return;
      FlGui::instance()->fullscreen->getDrawContext()->copyViewAttributes(
        FlGui::instance()->getCurrentOpenglWindow()->getDrawContext());
      openglWindow::setLastHandled(FlGui::instance()->fullscreen);
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->getWindow()->hide();
      drawContext::global()->draw();
    }
    else {
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->gl[0]->valid(0);
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->getWindow()->show();
      // (a graphic window may be closed meanwhile; its first pane is never
      // drawn if hidden, nor the window if the window manager keeps it
      // minimized: 2 s at most)
      auto waiting = [](std::size_t i) {
        FlGui *g = FlGui::instance();
        return i < g->graph.size() && g->graph[i]->getWindow()->shown() &&
               g->graph[i]->gl[0]->visible_r() && !g->graph[i]->gl[0]->valid();
      };
      double start = TimeOfDay();
      for(std::size_t i = 0;
          FlGui::available() && i < FlGui::instance()->graph.size(); i++)
        while(FlGui::available() && waiting(i) && TimeOfDay() - start < 2.)
          FlGui::wait(0.05);
      if(!FlGui::available()) return;
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->copyViewAttributes(
        FlGui::instance()->getCurrentOpenglWindow()->getDrawContext());
      openglWindow::setLastHandled(FlGui::instance()->graph[0]->gl[0]);
      FlGui::instance()->fullscreen->fullscreen_off();
      FlGui::instance()->fullscreen->hide();
      drawContext::global()->draw();
    }
  }
  else if(str == "front") {
    // the order is important; the docked tool windows come with the main one
    FlGui *g = FlGui::instance();
    for(std::size_t i = 0; i < g->graph.size(); i++)
      g->graph[i]->getWindow()->show();
    for(paletteWindow *p : g->toolWindows())
      if(p->shown() && !p->parent()) p->show();
  }
}

// The lines of the other threads, waiting for the GUI's thread to add them
// to the consoles, and whether it has been asked to (Fl::awake())
static std::mutex pendingMutex;
static std::vector<std::string> pendingMessages;
static bool pendingAsked = false;

static void addPendingMessages(void *)
{
  std::vector<std::string> msgs;
  {
    std::lock_guard<std::mutex> lock(pendingMutex);
    msgs.swap(pendingMessages);
    pendingAsked = false;
  }
  for(auto &m : msgs) FlGui::addMessage(m.c_str());
}

void FlGui::addMessage(const char *msg)
{
  if(!onMainThread()) {
    std::lock_guard<std::mutex> lock(pendingMutex);
    // no more than the consoles keep (see graphicWindow::addMessage()), the
    // oldest tenth going
    const std::size_t maxPending = 50000;
    if(pendingMessages.size() >= maxPending)
      pendingMessages.erase(pendingMessages.begin(),
                            pendingMessages.begin() + maxPending / 10);
    pendingMessages.push_back(msg);
    if(!pendingAsked) pendingAsked = (Fl::awake(addPendingMessages) == 0);
    return;
  }
  if(!_instance) return;
  for(std::size_t i = 0; i < _instance->graph.size(); i++)
    _instance->graph[i]->addMessage(msg);
}

void FlGui::saveMessages(const char *fileName)
{
  FlGui::instance()->graph[0]->saveMessages(fileName);
}

void FlGui::rebuildTree()
{
  if(onelab) onelab->rebuildTree();
  // this GUI may have been destroyed by the events the rebuild processed
  if(_instance != this) return;
  if(onelabContext) onelabContext->rebuild();
}

void FlGui::toggleModule(const std::string &name)
{
  if(FlGui::instance()->onelab){
    if(FlGui::instance()->onelab->isTreeItemOpen("0Modules/" + name)){
      FlGui::instance()->onelab->closeTreeItem("0Modules/" + name);
    } else {
      FlGui::instance()->onelab->openTreeItem("0Modules/" + name);
    }
  }
}

void FlGui::openModule(const std::string &name)
{
  if(!onelab) return;
  if(!onelab->isManuallyClosed("0Modules/" + name))
    onelab->openTreeItem("0Modules/" + name);
}

void FlGui::openTreeItem(const std::string &name)
{
  if(!onelab) return;
  onelab->openTreeItem(name);
}

void FlGui::closeTreeItem(const std::string &name)
{
  if(!onelab) return;
  onelab->closeTreeItem(name);
}

void FlGui::showOnelabContext(int dim, int tag)
{
  if(!onelabContext) return;
  onelabContext->show(dim, tag);
}
