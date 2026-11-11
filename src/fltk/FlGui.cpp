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
#include "drawContextFltkStringTexture.h"
#include "drawContextFltkEmbedded.h"
#include "viewButton.h"
#include "graphicWindow.h"
#include "fltkActions.h"
#include "fileActions.h"
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
#include "PViewOptions.h"
#include "Plugin.h"
#include "OpenFile.h"
#include "XpmIcon.h"
#include "Options.h"
#include "CommandLine.h"
#include "Shortcuts.h"
#include "Actions.h"
#include "Context.h"
#include "StringUtils.h"
#include "PixelBuffer.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

// The FLTK graphical user interface of Gmsh (the web page, contrib/webapp, is
// the other interface). Where things are:
//
// - FlGui (this file): the interface as a whole, made at startup (the
//   constructor creates every window), its event loop, the rules on the
//   lifetime of its widgets (below) and the keys it handles.
// - graphicWindow.cpp: the main window, with its menu bar, the tiles of the
//   scene, the tree of the modules and of the ONELAB parameters
//   (onelabGroup.cpp; the widgets of the parameters in onelabParameters.cpp,
//   what Check and Run do in onelabActions.cpp), the messages and the status
//   bar; toolDock.cpp docks the tool windows in it.
// - openglWindow.cpp: a scene, drawn by src/graphics (drawContext); what the
//   mouse does in it is sceneView (src/graphics), shared with the web page.
// - the tool windows, one file each (optionWindow.cpp, fieldWindow.cpp,
//   pluginWindow.cpp, statisticsWindow.cpp, visibilityWindow.cpp,
//   clippingWindow.cpp, manipWindow.cpp, highOrderToolsWindow.cpp, the
//   context windows of the operations and shapes in contextWindow.cpp,
//   onelabContextWindow.cpp, helpWindow.cpp), all on paletteWindow.
// - fltkActions.cpp: what the items of the menus and the buttons of the
//   modules do in the FLTK interface, in one table; fileActions.cpp: what the
//   File and Help menus do.
// - fileDialogs.cpp and extraDialogs.cpp: the dialogs; gmshScheme.cpp,
//   desktop.cpp, icons.cpp and windowPlacement.cpp: the look, the colours of
//   the desktop, the icons, where the windows go.
//
// The core knows no toolkit: what an option changes in the interface, it
// tells through guiListener (src/common/GuiListener.h), which FlGui
// implements at the end of this file.
//
// The menus, the buttons of the modules and the keyboard shortcuts are shared
// with the web page (contrib/webapp) and live in src/common: Actions.cpp (the
// items, with what Gmsh does and the keys that run them) and Shortcuts.cpp (the
// key codes, their labels and the listing of the keys). The operations on
// the entities picked in the scene are selectionDriver, stepped by sceneTool
// (src/graphics).
//
// How to add...
// - A menu item or a button of a module: see "How to add" in Actions.h. When
//   the FLTK interface does it: one line in the table of
//   fltkActions.cpp.
// - A tool window: a class on paletteWindow in a file of its own, created in
//   the constructor below, which names it for General.FloatingTools; then a
//   guiAction() in the Tools menu of Actions.cpp and its line in
//   fltkActions.cpp.
// - A key: .key() on the item it runs in Actions.cpp (an item of keysOnly()
//   for a key in no menu).
// - A button of the status bar: an item of the "Status bar" menu of
//   Actions.cpp, with its icon (IconStrokes.cpp), and its line in fltkActions.cpp.
// - An entry of the option window: a row of the table of OptionPages.cpp
//   (src/common), shown by both interfaces.
// Then run the tests of benchmarks/gui (see its README.txt), which check the
// registry, the menus and the selection workflows of the FLTK interface.

// Widget lifetime and nested event loops: the rules of the FLTK interface.
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
  // without a GUI, nothing to update
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

  // the actions the FLTK interface does, given to the items of the menus
  fltkActions();

  // set X display
  if(CTX::instance()->display.size())
    Fl::display(CTX::instance()->display.c_str());

  // add new box types (dx dy dw dh)
  Fl::set_boxtype(GMSH_SIMPLE_RIGHT_BOX, simple_right_box_draw, 0, 0, 1, 0);
  Fl::set_boxtype(GMSH_SIMPLE_TOP_BOX, simple_top_box_draw, 0, 1, 0, 1);

  // the graphics leave the colours used without a GUI, if they follow the desktop
  if(CTX::instance()->colorScheme == 3)
    followDesktopColorScheme(desktopDark() == 1);

  // the colour scheme before the widgets are made, so that none flashes
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
  fl_mac_set_about([](Fl_Widget *, void *) { helpAbout(); }, nullptr);
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
    [](Fl_Widget *, void *) { toggleFullScreen(); });

  // the tool windows, which dock, each named for General.FloatingTools, and
  // the help windows
  int delta = CTX::instance()->deltaFontSize;
  auto tool = [this](auto *w, const char *name) {
    paletteWindow *p = (paletteWindow *)w->win;
    p->dockable(true);
    p->name(name);
    _tools.push_back(p);
    return w;
  };
  options = tool(new optionWindow(delta), "options");
  plugins = tool(new pluginWindow(delta), "plugins");
  fields = tool(new fieldWindow(delta), "fields");
  visibility = tool(new visibilityWindow(delta), "visibility");
  clipping = tool(new clippingWindow(delta), "clipping");
  manip = tool(new manipWindow(delta), "manipulator");
  stats = tool(new statisticsWindow(delta), "statistics");
  highordertools = tool(new highOrderToolsWindow(delta), "highorder");
  elementaryContext = tool(new elementaryContextWindow(delta), "elementary");
  physicalContext = tool(new physicalContextWindow(delta), "physical");
  transformContext = tool(new transformContextWindow(delta), "transform");
  meshContext = tool(new meshContextWindow(delta), "mesh");
  onelabContext = tool(new onelabContextWindow(delta), "onelab");
  classify = tool(new classificationEditor(delta), "reclassify");
  partition = tool(new partitionWindow(delta), "partition");
  help = new helpWindow();

  // draw
  for(std::size_t i = 0; i < graph.size(); i++)
    for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
      graph[i]->gl[j]->redraw();

  applyFloatingTools();
  // what docked tools skip while hidden, refreshed when shown again
  ((paletteWindow *)visibility->win)
    ->whenRevealed(
      [](void *) { updateVisibility(); }, nullptr);
  ((paletteWindow *)stats->win)
    ->whenRevealed([](void *) { FlGui::instance()->stats->compute(false); },
                   nullptr);
  ((paletteWindow *)manip->win)
    ->whenRevealed([](void *) { FlGui::instance()->manip->update(); }, nullptr);

  if(CTX::instance()->showOptionsOnStartup) options->win->show();
  if(CTX::instance()->showMessagesOnStartup) graph[0]->showMessages();

  // the core tells this interface what changes from now on
  SetGuiListener(this);
}

FlGui::~FlGui()
{
  SetGuiListener(nullptr);

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
    if(e.action == action)
      return (systemBar && (e.shortcut.flags & KeyInWindowBarOnly)) ?
               0 :
               fltkCode(e.shortcut);
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
  // the shortcuts with the modifiers held, before those taking any modifier
  // (Shift+Escape before Escape)
  int status = 0;
  for(bool any : {false, true}) {
    for(const ShortcutEntry &e : GetShortcuts()) {
      if((bool)(e.shortcut.mods & AnyModifiers) != any) continue;
      if(!fltkTest(e.shortcut)) continue;
#if defined(__APPLE__)
      // (Cmd+H hides the application)
      if((e.shortcut.flags & KeyInWindowBarOnly) && graph[0]->hasSystemMenuBar())
        continue;
#endif
      int st = runShortcut(e.action);
      if(!st) continue; // not for this build
      // a key passed on is handled, but as if it had not been: what is under
      // the mouse reads it too
      status = (e.shortcut.flags & KeyPassedOn) ? 0 : st;
      break;
    }
    if(status) break;
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

// What each action of the shortcut table does: the item of its name in the
// registry (see Actions.h) runs, as a click on it does. Returns 0 for an
// action not handled here (or not available now: the key then goes on, as if
// it had no shortcut), 1 when done.
int FlGui::runShortcut(const std::string &a)
{
  const actionItem *item = FindItem(a);
  if(!item || !canRunItem(*item)) return 0;
  runItem(*item);
  return 1;
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
  if(visibility->win->shown()) showVisibility();
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
  storeWindowOffset(classify->win, CTX::instance()->reclassifyOffset);
  storeWindowOffset(manip->win, CTX::instance()->manipOffset);
  storeWindowOffset(lastContextWindow ? lastContextWindow :
                                        elementaryContext->win,
                    CTX::instance()->ctxOffset);
#if defined(HAVE_3M)
  storeWindowPosition3M();
#endif
  fileChooserStoreOffset(CTX::instance()->fileChooserOffset);
}

void redraw_cb(Fl_Widget *w, void *data) { drawContext::global()->draw(); }

// What the core tells the interface (see GuiListener.h): each option that
// changes something beyond its widgets says so, and the interface follows

bool FlGui::running() { return available(); }

drawContext *FlGui::scene() { return getCurrentDrawContext(); }

int FlGui::desktopDark() { return ::desktopDark() == 1 ? 1 : 0; }

void FlGui::optionChanged(const std::string &category, int num,
                          const std::string &name)
{
  options->showOption(category, num, name);
}

void FlGui::optionsChanged() { options->showOptions(); }

void FlGui::beforeOptionsSaved() { storeCurrentWindowsInfo(); }

void FlGui::backgroundImageChanged()
{
  for(openglWindow *gl : openglWindows())
    gl->getDrawContext()->invalidateBgImageTexture();
}

void FlGui::floatingToolsChanged() { applyFloatingTools(); }

void FlGui::colorSchemeChanged() { applyColorScheme(true); }

void FlGui::openglModeChanged() { resetOpenglMode(); }

void FlGui::shadersChanged() { resetOpenglMode(); }

void FlGui::tooltipsChanged()
{
  if(CTX::instance()->tooltips)
    Fl_Tooltip::enable();
  else
    Fl_Tooltip::disable();
}

void FlGui::mouseSelectionChanged() { updateModeButtons(); }

void FlGui::graphicSizeChanged()
{
  graph[0]->setGlWidth(CTX::instance()->glSize[0]);
  graph[0]->setGlHeight(CTX::instance()->glSize[1]);
}

void FlGui::messageFontSizeChanged()
{
  graph[0]->setMessageFontSize(CTX::instance()->msgFontSize);
}

void FlGui::menuAttachedChanged()
{
  if(CTX::instance()->detachedMenu)
    graph[0]->detachMenu();
  else
    graph[0]->attachMenu();
}

void FlGui::menuWidthChanged()
{
  if(CTX::instance()->menuSize[0] > 0)
    graph[0]->setMenuWidth(CTX::instance()->menuSize[0]);
  else
    graph[0]->hideMenu();
}

void FlGui::sceneTransformChanged() { manip->update(); }

void FlGui::clippingChanged()
{
  CTX *c = CTX::instance();
  clipping->butt[0]->value(c->clipCapping);
  clipping->butt[1]->value(c->clipWholeElements);
  clipping->butt[2]->value(c->clipOnlyDrawIntersectingVolume);
  clipping->butt[3]->value(c->clipOnlyVolume);
  clipping->activateButtons();
  clipping->resetBrowser();
}

void FlGui::lightChanged()
{
  options->general.sphere->setValue(CTX::instance()->lightPosition[0][0],
                                    CTX::instance()->lightPosition[0][1],
                                    CTX::instance()->lightPosition[0][2]);
}

void FlGui::snapChanged()
{
  for(int i = 0; i < 3; i++)
    elementaryContext->value[i]->value(CTX::instance()->geom.snap[i]);
}

void FlGui::animationChanged()
{
  for(std::size_t i = 0; i < graph.size(); i++) graph[i]->checkAnimButtons();
}

void FlGui::viewTimeStepChanged(int num)
{
  // (the time step field shows the view of the option window)
  if(num != options->view.index) return;
  ((Fl_Valuator *)options->widget("View.TimeStep"))
    ->maximum(PView::list[num]->getData()->getNumTimeSteps() - 1);
}

void FlGui::viewRenamed(int num)
{
  // the view and its aliases
  PView *view = PView::list[num];
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if((i == num || PView::list[i]->getAliasOf() == view->getTag() ||
        PView::list[i]->getTag() == view->getAliasOf()) &&
       onelab->getViewButton(i)) {
      onelab->getViewButton(i)->copy_label("[" + std::to_string(i) + "] " +
                                           view->getData()->getName());
      onelab->getViewButton(i)->redraw();
    }
  }
}

void FlGui::viewVisibilityChanged(int num)
{
  if(onelab->getViewButton(num))
    onelab->getViewButton(num)->value(PView::list[num]->getOptions()->visible);
}

void FlGui::viewOpenedOrClosed(int num) { onelab->openCloseViewButton(num); }

void FlGui::viewColorMapChanged(int num)
{
  if(num < 0 || num == options->view.index) options->view.colorbar->redraw();
}

void FlGui::viewsChanged(bool numberChanged) { updateViews(numberChanged); }

void FlGui::fieldsChanged() { updateFields(); }

// (the tree and the visibility window are touched by the thread of the
// interface only)
void FlGui::entitiesChanged()
{
  if(onMainThread()) resetVisibility();
}

void FlGui::parametersChanged()
{
  if(onMainThread()) rebuildTree();
}

void FlGui::setCurrentWindow(int index) { setCurrentOpenglWindow(index); }

void FlGui::splitCurrentWindow(char how, double ratio)
{
  splitCurrentOpenglWindow(how, ratio);
}

void fltkFontEngine(const std::string &engine)
{
  drawContextGlobal *old = drawContext::global();
  if(old && old->getName() == engine) return;
  if(engine == "StringTexture")
    drawContext::setGlobal(new drawContextFltkStringTexture);
  else if(engine == "Embedded")
    drawContext::setGlobal(new drawContextFltkEmbedded);
  else
    drawContext::setGlobal(new drawContextFltk);
  if(old) delete old;
}

// The windows, as the Window menu has them (see fltkActions.cpp)

void minimizeWindows()
{
  // the docked tool windows go with the main window
  auto iconize = [](Fl_Window *w) {
    if(w->shown() && !w->parent()) w->iconize();
  };
  FlGui *g = FlGui::instance();
  for(std::size_t i = 0; i < g->graph.size(); i++)
    iconize(g->graph[i]->getWindow());
  for(paletteWindow *p : g->toolWindows()) iconize(p);
}

void zoomMainWindow()
{
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

bool isFullScreen()
{
  return FlGui::instance()->fullscreen->shown();
}

void toggleFullScreen()
{
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

void bringAllToFront()
{
  // the order is important; the docked tool windows come with the main one
  FlGui *g = FlGui::instance();
  for(std::size_t i = 0; i < g->graph.size(); i++)
    g->graph[i]->getWindow()->show();
  for(paletteWindow *p : g->toolWindows())
    if(p->shown() && !p->parent()) p->show();
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
