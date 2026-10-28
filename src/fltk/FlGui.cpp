// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <algorithm>
#include <sstream>
#include <string.h>
#include <FL/Fl.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Icon.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "gmshScheme.h"
#include "desktop.h"
#include "mainWindow.h"
#include "icons.h"
#include "drawContextFltk.h"
#include "graphicWindow.h"
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
#include "colorbarWindow.h"
#include "fileDialogs.h"
#include "windowPlacement.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "OS.h"
#include "MElement.h"
#include "PView.h"
#include "Plugin.h"
#include "PluginManager.h"
#include "OpenFile.h"
#include "XpmIcon.h"
#include "Options.h"
#include "CommandLine.h"
#include "Shortcuts.h"
#include "Context.h"
#include "StringUtils.h"
#include "gl2ps.h"
#include "gmshPopplerWrapper.h"
#include "PixelBuffer.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

FlGui *FlGui::_instance = nullptr;
std::string FlGui::_openedThroughMacFinder = "";
bool FlGui::_finishedProcessingCommandLine = false;
std::atomic<int> FlGui::_locked(0);

// check (now!) if there are any pending events, and process them
void FlGui::check(bool rateLimited)
{
  if(Msg::GetThreadNum() > 0 || _locked > 0) return;

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
  if((Msg::GetThreadNum() > 0 || _locked > 0) && !force) return;
  Fl::wait();
}

// wait (at most time seconds) for any events, then process them
void FlGui::wait(double time, bool force)
{
  if((Msg::GetThreadNum() > 0 || _locked > 0) && !force) return;
  Fl::wait(time);
}

void FlGui::lock()
{
  _locked++;
  Fl::lock();
}

void FlGui::unlock()
{
  _locked--;
  Fl::unlock();
}

int FlGui::locked() { return _locked; }

static void awake_cb(void *data)
{
  if(data) FlGui::instance()->updateViews(true, false);
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

// Icons for the satus bar
#define vv(x, y) fl_vertex(x, y)
#define bl fl_begin_loop()
#define el fl_end_loop()

static void gmsh_play(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.3, 0.8);
  vv(0.5, 0.0);
  vv(-0.3, -0.8);
  el;
}

static void gmsh_pause(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.8);
  vv(-0.3, -0.8);
  vv(-0.3, 0.8);
  vv(-0.8, 0.8);
  el;
  bl;
  vv(0.0, -0.8);
  vv(0.5, -0.8);
  vv(0.5, 0.8);
  vv(0.0, 0.8);
  el;
}

static void gmsh_rewind(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.8);
  vv(-0.3, -0.8);
  vv(-0.3, 0.8);
  vv(-0.8, 0.8);
  el;
  bl;
  vv(-0.3, 0.0);
  vv(0.5, -0.8);
  vv(0.5, 0.8);
  el;
}

static void gmsh_forward(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(0.0, 0.8);
  vv(0.8, 0.0);
  vv(0.0, -0.8);
  el;
  bl;
  vv(-0.8, 0.8);
  vv(-0.3, 0.8);
  vv(-0.3, -0.8);
  vv(-0.8, -0.8);
  el;
}

static void gmsh_back(Fl_Color c)
{
  fl_rotate(180);
  gmsh_forward(c);
}

static void gmsh_rotate(Fl_Color c)
{
  fl_color(c);
  fl_begin_line();
  fl_arc(0.0, -0.1, 0.7, 0.0, 270.0);
  fl_end_line();
  fl_begin_polygon();
  vv(0.5, 0.6);
  vv(-0.1, 0.9);
  vv(-0.1, 0.3);
  fl_end_polygon();
}

// a crosshair over a target: the point of the model a query asks about
static void gmsh_query(Fl_Color c)
{
  fl_color(c);
  fl_begin_line();
  fl_arc(0.0, 0.0, 0.45, 0.0, 360.0);
  fl_end_line();
  bl;
  vv(-0.9, 0.0);
  vv(-0.2, 0.0);
  el;
  bl;
  vv(0.2, 0.0);
  vv(0.9, 0.0);
  el;
  bl;
  vv(0.0, -0.9);
  vv(0.0, -0.2);
  el;
  bl;
  vv(0.0, 0.2);
  vv(0.0, 0.9);
  el;
}

// a ruler: the line a measurement draws between the two points it is given
static void gmsh_measure(Fl_Color c)
{
  fl_color(c);
  bl; vv(-0.75, 0.55); vv(0.75, -0.55); el;   // the line
  bl; vv(-0.90, 0.35); vv(-0.60, 0.75); el;   // its ends
  bl; vv(0.60, -0.75); vv(0.90, -0.35); el;
  bl; vv(-0.38, 0.28); vv(-0.29, 0.40); el;   // graduations
  bl; vv(0.00, 0.00); vv(0.09, 0.12); el;
  bl; vv(0.38, -0.28); vv(0.46, -0.15); el;
}

// a window with its side pane filled: the tree, shown or hidden
static void gmsh_sidebar(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.8);
  vv(0.8, -0.8);
  vv(0.8, 0.8);
  vv(-0.8, 0.8);
  el;
  fl_begin_polygon();
  vv(-0.8, -0.8);
  vv(-0.3, -0.8);
  vv(-0.3, 0.8);
  vv(-0.8, 0.8);
  fl_end_polygon();
}

static void gmsh_models(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.7);
  vv(0.8, -0.7);
  el;
  bl;
  vv(-0.8, -0.2);
  vv(0.8, -0.2);
  el;
  bl;
  vv(-0.8, 0.3);
  vv(0.8, 0.3);
  el;
  bl;
  vv(-0.8, 0.8);
  vv(0.8, 0.8);
  el;
}

static void gmsh_gear(Fl_Color c)
{
  fl_color(c);
  double w = 0.12;
  double h1 = 0.5;
#if defined(WIN32)
  double h2 = 1.0;
#else
  double h2 = 1.05;
#endif
  fl_line_style(FL_SOLID, 3);
  fl_begin_line();
  fl_circle(0, 0, 0.5);
  fl_end_line();
  fl_line_style(FL_SOLID);
  for(int i = 0; i < 8; i++) {
    fl_rotate(45);
    fl_begin_polygon();
    fl_vertex(h1, -w);
    fl_vertex(h2, -w);
    fl_vertex(h2, w);
    fl_vertex(h1, w);
    fl_end_polygon();
  }
}

static void gmsh_graph(Fl_Color c)
{
  fl_color(c);
  fl_begin_line();
  vv(-0.8, -0.8);
  vv(-0.8, 0.8);
  vv(0.8, 0.8);
  fl_end_line();
  fl_begin_line();
  vv(-0.8, 0.3);
  vv(-0.2, -0.2);
  vv(0.3, 0.1);
  vv(0.8, -0.4);
  fl_end_line();
}

static void gmsh_search(Fl_Color col)
{
  double e = 0.5;
  fl_color(col);
  fl_begin_polygon();
  vv(.6 - e, .33);
  vv(1.2 - e, .93);
  vv(.93 - e, 1.2);
  vv(.33 - e, .6);
  fl_end_polygon();
  fl_line_style(FL_SOLID, 2);
  fl_begin_loop();
  fl_circle(0 - e, 0, .6);
  fl_end_loop();
  fl_line_style(FL_SOLID);
}

static void gmsh_colormap(Fl_Color col)
{
  fl_color(FL_RED);
  fl_begin_polygon();
  vv(-0.8, -0.8);
  vv(-0.3, -0.8);
  vv(-0.3, 0.8);
  vv(-0.8, 0.8);
  fl_end_polygon();
  fl_color(FL_GREEN);
  fl_begin_polygon();
  vv(-0.3, -0.8);
  vv(0.2, -0.8);
  vv(0.2, 0.8);
  vv(-0.3, 0.8);
  fl_end_polygon();
  fl_color(FL_BLUE);
  fl_begin_polygon();
  vv(0.2, -0.8);
  vv(0.7, -0.8);
  vv(0.7, 0.8);
  vv(0.2, 0.8);
  fl_end_polygon();
}

#undef vv
#undef bl
#undef el

// question presence of gamepad every 3. seconds
static void gamepad_handler(void *data)
{
  if(CTX::instance()->gamepad && CTX::instance()->gamepad->active) {
    CTX::instance()->gamepad->read_event();
    Fl::add_timeout(CTX::instance()->gamepad->frequency, gamepad_handler, data);
  }
  else {
    Fl::add_timeout(.5, gamepad_handler, data);
  }
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

  // thinner scrollbars
  Fl::scrollbar_size(std::max(10, FL_NORMAL_SIZE));

  if(redraw && available()) {
    gmshIconsRecolor();
    help->resetText();
    updateViews(true, true);
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
  if(CTX::instance()->guiColorScheme != 2 || !available()) return;
  bool dark = (desktopDark() == 1);
  if(dark == (bool)CTX::instance()->guiDark) return;
  applyColorScheme(true);
  // drawn now: the notification came while the loop waited for events, and
  // the windows inside the main one are only painted by a flush
  Fl::flush();
}

static void desktop_changed_cb() { FlGui::instance()->desktopChanged(); }

static void watchDesktop()
{
  watchDesktopAppearance(desktop_changed_cb);
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
  : _quitShouldExit(quitShouldExit), lastContextWindow(0)
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

  // tell fltk we're (potentially) in multi-threaded mode
  Fl::lock();

  // set X display
  if(CTX::instance()->display.size())
    Fl::display(CTX::instance()->display.c_str());

  // add new box types (dx dy dw dh)
  Fl::set_boxtype(GMSH_SIMPLE_RIGHT_BOX, simple_right_box_draw, 0, 0, 1, 0);
  Fl::set_boxtype(GMSH_SIMPLE_TOP_BOX, simple_top_box_draw, 0, 1, 0, 1);

  // apply color scheme before widget creation (noop if default color scheme is
  // selected), so that there's no color "flashing"
  applyColorScheme();

  // add gamepad handler
  if(CTX::instance()->gamepad)
    Fl::add_timeout(5., gamepad_handler, (void *)nullptr);

  // add global shortcuts
  Fl::add_handler(globalShortcut);

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

  // add our own icons
  fl_add_symbol("gmsh_rewind", gmsh_rewind, 1);
  fl_add_symbol("gmsh_back", gmsh_back, 1);
  fl_add_symbol("gmsh_play", gmsh_play, 1);
  fl_add_symbol("gmsh_pause", gmsh_pause, 1);
  fl_add_symbol("gmsh_forward", gmsh_forward, 1);
  fl_add_symbol("gmsh_rotate", gmsh_rotate, 1);
  fl_add_symbol("gmsh_sidebar", gmsh_sidebar, 1);
  fl_add_symbol("gmsh_models", gmsh_models, 1);
  fl_add_symbol("gmsh_query", gmsh_query, 1);
  fl_add_symbol("gmsh_measure", gmsh_measure, 1);
  fl_add_symbol("gmsh_gear", gmsh_gear, 1);
  fl_add_symbol("gmsh_graph", gmsh_graph, 1);
  fl_add_symbol("gmsh_search", gmsh_search, 1);
  fl_add_symbol("gmsh_colormap", gmsh_colormap, 1);

  // load default system icons (for file browser)
  Fl_File_Icon::load_system_icons();

  // FLTK >= 1.3.3 allows one to set a default global window icon
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

  for(std::size_t i = 0; i < graph.size(); i++) delete graph[i];
  delete options;
  delete fields;
  delete plugins;
  delete stats;
  delete visibility;
  delete highordertools;
  delete clipping;
  delete partition;
  delete classify;
  delete manip;
  delete elementaryContext;
  delete transformContext;
  delete physicalContext;
  delete onelabContext;
  delete meshContext;
  delete help;
  delete fullscreen;
}

bool FlGui::available() { return _instance != nullptr; }

FlGui *FlGui::instance(int argc, char **argv, bool quitShouldExit,
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
    _instance->updateViews(true, true);
    // set global bounding box in CTX (necessary if we run the gui without any
    // model/post-processing data)
    SetBoundingBox();
  }
  return _instance;
}

void FlGui::destroy()
{
  if(!_instance) return;

  _instance->onelabContext->disableRedraw();

  // hide all windows (in case they are not tracked by FlGui)...
  std::vector<Fl_Window *> wins;
  for(Fl_Window *win = Fl::first_window(); win; win = Fl::next_window(win))
    wins.push_back(win);
  for(std::size_t i = 0; i < wins.size(); i++) wins[i]->hide();

  // process remaining events
  Fl::check();

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

  int status = 0;
  if(graph[0]->runMenuShortcut()) {
    // a shortcut of the menus is its entry, also when the system menu bar
    // did not take it
    status = 1;
  }
  else {
    for(const ShortcutEntry &e : GetShortcuts()) {
      if(!fltkTest(e.shortcut)) continue;
      int st = runShortcut(e.action);
      if(!st) continue; // a menu entry, or not for this build
      // a key passed on is handled, but as if it had not been: what is
      // under the mouse reads it too
      status = e.passOn ? 0 : st;
      break;
    }
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
  // the keys the 3D view handles itself when it has the focus
  static const char *keys[] = {"time_step_prev", "time_step_next", "view_prev",
                               "view_next",      "page_prev",      "page_next"};
  for(const ShortcutEntry &e : GetShortcuts()) {
    bool arrow = false;
    for(const char *k : keys)
      if(!strcmp(e.action, k)) arrow = true;
    if(arrow && fltkTest(e.shortcut)) return runShortcut(e.action) ? 1 : 0;
  }
  return 0;
}

// what each action of the shortcut table does; the entries of the menus are
// run by the menus (see graphicWindow::runMenuShortcut()), those of the quick
// access menu of the status bar by its callback. Returns 0 for an action not
// handled here, 1 when done, 2 when the scene must be drawn again
int FlGui::runShortcut(const std::string &a)
{
  // --- reloading and meshing
  if(a == "geometry_reload") {
    geometry_reload_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "project_reload") {
    onelab_reload_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "mesh_1d") {
    mesh_1d_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "mesh_2d") {
    mesh_2d_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "mesh_3d") {
    mesh_3d_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "solver_run") {
    onelab_cb(nullptr, (void *)"compute");
    return 1;
  }
  if(a == "quit") {
    // only necessary when using the system menu bar, but hey, it cannot hurt
    file_quit_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "watch") {
    file_watch_cb(nullptr, nullptr);
    return 1;
  }
  // --- the modules of the tree
  if(a == "module_geometry") {
    FlGui::toggleModule("Geometry");
    return 1;
  }
  if(a == "module_mesh") {
    FlGui::toggleModule("Mesh");
    return 1;
  }
  if(a == "module_solver") {
    FlGui::toggleModule("Solver");
    return 1;
  }
  if(a == "module_post") {
    FlGui::toggleModule("Post-processing");
    return 1;
  }
  // --- a selection under way
  if(a == "selection_end" || a == "selection_undo" || a == "selection_invert" ||
     a == "selection_quit") {
    for(std::size_t i = 0; i < graph.size(); i++)
      for(std::size_t j = 0; j < graph[i]->gl.size(); j++) {
        openglWindow *gl = graph[i]->gl[j];
        if(a == "selection_end") gl->endSelection = 1;
        if(a == "selection_undo") gl->undoSelection = 1;
        if(a == "selection_invert") gl->invertSelection = 1;
        if(a == "selection_quit") gl->quitSelection = 1;
      }
    return 1;
  }
  // --- placing an elementary entity with the mouse: the axes it may move
  // along, one at a time or all but one
  if(a == "freeze_x" || a == "freeze_y" || a == "freeze_z") {
    int i = a[7] - 'x';
    elementaryContext->butt[i]->value(!elementaryContext->butt[i]->value());
    return 1;
  }
  if(a == "freeze_but_x" || a == "freeze_but_y" || a == "freeze_but_z") {
    int i = a[11] - 'x';
    for(int j = 0; j < 3; j++) elementaryContext->butt[j]->value(j != i);
    return 1;
  }
  if(a == "escape") {
    if(fullscreen->shown()) {
      window_cb(nullptr, (void *)"fullscreen");
      return 1;
    }
    bool lasso = false;
    for(std::size_t i = 0; i < graph.size(); i++)
      for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
        if(graph[i]->gl[j]->lassoMode) lasso = true;
    if(lasso) {
      for(std::size_t i = 0; i < graph.size(); i++)
        for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
          graph[i]->gl[j]->lassoMode = false;
      return 2;
    }
    status_options_cb(nullptr, (void *)"S");
    return 1;
  }
  // --- the windows
  if(a == "window_front") {
    window_cb(nullptr, (void *)"front");
    return 1;
  }
  if(a == "options_general") {
    general_options_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "options_geometry") {
    geometry_options_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "options_mesh") {
    mesh_options_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "options_solver") {
    solver_options_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "options_post") {
    post_options_cb(nullptr, nullptr);
    return 1;
  }
  if(a == "options_view") {
    view_options_cb(nullptr, (void *)-1);
    return 1;
  }
  if(a == "plugins_view") {
    if(PView::list.size()) {
      if(options->view.index >= 0 &&
         options->view.index < (int)PView::list.size())
        plugins->show(options->view.index);
      else
        plugins->show(0);
    }
    return 1;
  }
  // --- the display: what the quick access menu of the status bar does too
  if(a == "geometry_points" || a == "geometry_curves" ||
     a == "geometry_surfaces" || a == "geometry_volumes" || a == "mesh_nodes" ||
     a == "mesh_lines" || a == "mesh_surface_edges" ||
     a == "mesh_surface_faces" || a == "mesh_volume_edges" ||
     a == "mesh_volume_faces" || a == "mesh_toggle") {
    quick_access_cb(nullptr, (void *)a.c_str());
    return 2;
  }
  if(a == "fast_redraw") {
    opt_general_fast_redraw(0, GMSH_SET | GMSH_GUI,
                            !opt_general_fast_redraw(0, GMSH_GET, 0));
    return 2;
  }
  if(a == "bounding_boxes") {
    opt_general_draw_bounding_box(
      0, GMSH_SET | GMSH_GUI, !opt_general_draw_bounding_box(0, GMSH_GET, 0));
    return 2;
  }
  if(a == "view_scales") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_show_scale(i, GMSH_SET | GMSH_GUI,
                            !opt_view_show_scale(i, GMSH_GET, 0));
    return 2;
  }
  if(a == "color_scheme") {
    opt_general_color_scheme(0, GMSH_SET | GMSH_GUI,
                             opt_general_color_scheme(0, GMSH_GET, 0) + 1);
    return 2;
  }
  if(a == "colormaps") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_colormap_number(i, GMSH_SET | GMSH_GUI,
                                 opt_view_colormap_number(i, GMSH_GET, 0) + 1);
    return 2;
  }
  if(a == "lighting") {
    opt_geometry_light(0, GMSH_SET | GMSH_GUI,
                       !opt_geometry_light(0, GMSH_GET, 0));
    opt_mesh_light(0, GMSH_SET | GMSH_GUI, !opt_mesh_light(0, GMSH_GET, 0));
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_light(i, GMSH_SET | GMSH_GUI, !opt_view_light(i, GMSH_GET, 0));
    return 2;
  }
  // the view callback reads Shift and Ctrl itself (-X, reset, sync)
  if(a == "view_x" || a == "view_y" || a == "view_z") {
    status_xyz1p_cb(nullptr, (void *)(a == "view_x" ? "x" :
                                      a == "view_y" ? "y" :
                                                      "z"));
    return 1;
  }
  if(a == "view_1_1") {
    status_xyz1p_cb(nullptr, (void *)"1:1");
    return 1;
  }
  if(a == "projection") {
    status_options_cb(nullptr, (void *)"p");
    return 1;
  }
  if(a == "axes_loop") {
    opt_general_axes(0, GMSH_SET | GMSH_GUI,
                     opt_general_axes(0, GMSH_GET, 0) + 1);
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_axes(i, GMSH_SET | GMSH_GUI,
                      opt_view_axes(i, GMSH_GET, 0) + 1);
    return 2;
  }
  if(a == "small_axes") {
    opt_general_small_axes(0, GMSH_SET | GMSH_GUI,
                           !opt_general_small_axes(0, GMSH_GET, 0));
    return 2;
  }
  if(a == "surface_type") {
    opt_geometry_surface_type(0, GMSH_SET | GMSH_GUI,
                              opt_geometry_surface_type(0, GMSH_GET, 0) + 1);
    return 2;
  }
  if(a == "view_intervals" || a == "view_intervals_all") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0)) {
        int t = opt_view_intervals_type(i, GMSH_GET, 0) + 1;
        if(t == 4 && a == "view_intervals") t = 1; // skip numeric display
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, t);
      }
    return 2;
  }
  if(a == "view_range") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_range_type(i, GMSH_SET | GMSH_GUI,
                            opt_view_range_type(i, GMSH_GET, 0) + 1);
    return 2;
  }
  if(a == "view_annotations") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_draw_strings(i, GMSH_SET | GMSH_GUI,
                              !opt_view_draw_strings(i, GMSH_GET, 0));
    return 2;
  }
  if(a == "view_elements") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_show_element(i, GMSH_SET | GMSH_GUI,
                              !opt_view_show_element(i, GMSH_GET, 0));
    return 2;
  }
  if(a == "views_hide_show") {
    static int show = 0;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, show);
    show = !show;
    return 2;
  }
  // --- the time steps and the views, on the arrows
  if(a == "time_step_prev") {
    status_play_manual(1, -CTX::instance()->post.animStep);
    return 1;
  }
  if(a == "time_step_next") {
    status_play_manual(1, CTX::instance()->post.animStep);
    return 1;
  }
  if(a == "view_prev") {
    status_play_manual(0, -CTX::instance()->post.animStep);
    return 1;
  }
  if(a == "view_next") {
    status_play_manual(0, CTX::instance()->post.animStep);
    return 1;
  }
#if defined(HAVE_POPPLER)
  if(a == "page_prev") {
    gmshPopplerWrapper::setCurrentPageDown();
    return 2;
  }
  if(a == "page_next") {
    gmshPopplerWrapper::setCurrentPageUp();
    return 2;
  }
#endif
  return 0;
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

void FlGui::updateViews(bool numberOfViewsHasChanged, bool deleteWidgets)
{
  for(std::size_t i = 0; i < graph.size(); i++) graph[i]->checkAnimButtons();
  if(numberOfViewsHasChanged) {
    if(onelab) onelab->rebuildTree(deleteWidgets);
    if(onelabContext) onelabContext->rebuild(deleteWidgets);
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
#if defined(WIN32)
  GLint width = getCurrentOpenglWindow()->w();
  GLint height = getCurrentOpenglWindow()->h();

  // lines have to be 32 bytes aligned, suppose 24 bits per pixel; just crop it
  width -= width % 4;

  // get pixels
  PixelBuffer *buffer =
    new PixelBuffer(width, height, GL_RGB, GL_UNSIGNED_BYTE);
  buffer->fill();
  unsigned char *pixels = (unsigned char *)buffer->getPixels();

  // swap R and B since Windows bitmap format is BGR
  int nBytes = 3 * width * height;
  for(int i = 0; i < nBytes; i += 3) {
    unsigned char tmp = pixels[i];
    pixels[i] = pixels[i + 2];
    pixels[i + 2] = tmp;
  }

  // fill header
  BITMAPINFOHEADER header;
  header.biWidth = width;
  header.biHeight = height;
  header.biSizeImage = nBytes;
  header.biSize = 40;
  header.biPlanes = 1;
  header.biBitCount = 3 * 8;
  header.biCompression = BI_RGB;
  header.biXPelsPerMeter = 0;
  header.biYPelsPerMeter = 0;
  header.biClrUsed = 0;
  header.biClrImportant = 0;

  // generate handle
  HANDLE handle =
    (HANDLE)::GlobalAlloc(GHND, sizeof(BITMAPINFOHEADER) + nBytes);
  if(handle != nullptr) {
    // lock handle
    char *pData = (char *)::GlobalLock((HGLOBAL)handle);
    // copy header and data
    memcpy(pData, &header, sizeof(BITMAPINFOHEADER));
    memcpy(pData + sizeof(BITMAPINFOHEADER), pixels, nBytes);
    // unlock
    ::GlobalUnlock((HGLOBAL)handle);
    // push DIB in clipboard
    OpenClipboard(nullptr);
    EmptyClipboard();
    SetClipboardData(CF_DIB, handle);
    CloseClipboard();
  }

  delete buffer;
#endif
}

drawContext *FlGui::getCurrentDrawContext()
{
  return getCurrentOpenglWindow()->getDrawContext();
}

char FlGui::selectEntity(int type)
{
  return getCurrentOpenglWindow()->selectEntity(
    type, selectedVertices, selectedEdges, selectedFaces, selectedRegions,
    selectedElements, selectedPoints, selectedViews);
}

void FlGui::setStatus(const std::string &msg, bool opengl)
{
  if(Msg::GetThreadNum() > 0) return;
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
  if(Msg::GetThreadNum() > 0) return;
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
  if(Msg::GetThreadNum() > 0) return;
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

std::vector<Fl_Window *> FlGui::toolWindows()
{
  std::vector<Fl_Window *> tools = {
    options->win,         plugins->win,          fields->win,
    visibility->win,      clipping->win,         manip->win,
    stats->win,           highordertools->win,   elementaryContext->win,
    physicalContext->win, transformContext->win, meshContext->win,
    onelabContext->win,   classify->window};
  if(partition->win) tools.push_back(partition->win);
  return tools;
}

void FlGui::applyFloatingTools()
{
  std::string names = "," + CTX::instance()->floatingTools + ",";
  names.erase(std::remove(names.begin(), names.end(), ' '), names.end());
  for(auto w : toolWindows()) {
    paletteWindow *p = (paletteWindow *)w;
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
  for(auto w : toolWindows()) {
    paletteWindow *p = (paletteWindow *)w;
    if(!p->floating()) continue;
    names += (names.empty() ? "" : ",") + p->name();
  }
  CTX::instance()->floatingTools = names;
}

void FlGui::dockTools(bool dock)
{
  std::string names;
  if(!dock)
    for(auto w : toolWindows()) {
      paletteWindow *p = (paletteWindow *)w;
      names += (names.empty() ? "" : ",") + p->name();
    }
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
  Fl_Window *ctx = (lastContextWindow == 4) ? onelabContext->win :
                   (lastContextWindow == 3) ? physicalContext->win :
                   (lastContextWindow == 2) ? meshContext->win :
                   (lastContextWindow == 1) ? transformContext->win :
                                              elementaryContext->win;
  storeWindowOffset(ctx, CTX::instance()->ctxOffset);
#if defined(HAVE_3M)
  storeWindowPosition3M();
#endif
  fileChooserStoreOffset(CTX::instance()->fileChooserOffset);
}

// Callbacks

void redraw_cb(Fl_Widget *w, void *data) { drawContext::global()->draw(); }

void window_cb(Fl_Widget *w, void *data)
{
  static int oldx = 0, oldy = 0, oldw = 0, oldh = 0, zoom = 0, fullscreen = 0;

  std::string str((const char *)data);

  if(str == "minimize") {
    // the docked tool windows go with the main window
    auto iconize = [](Fl_Window *w) {
      if(w->shown() && !w->parent()) w->iconize();
    };
    FlGui *g = FlGui::instance();
    for(std::size_t i = 0; i < g->graph.size(); i++)
      iconize(g->graph[i]->getWindow());
    for(Fl_Window *w : g->toolWindows()) iconize(w);
  }
  else if(str == "zoom") {
    if(!zoom) {
      oldx = FlGui::instance()->graph[0]->getWindow()->x();
      oldy = FlGui::instance()->graph[0]->getWindow()->y();
      oldw = FlGui::instance()->graph[0]->getWindow()->w();
      oldh = FlGui::instance()->graph[0]->getWindow()->h();
      int x, y, w, h;
      windowWorkArea(FlGui::instance()->graph[0]->getWindow(), x, y, w, h);
      FlGui::instance()->graph[0]->getWindow()->resize(x, y, w, h);
      zoom = 1;
    }
    else {
      FlGui::instance()->graph[0]->getWindow()->resize(oldx, oldy, oldw, oldh);
      zoom = 0;
    }
  }
  else if(str == "fullscreen") {
    if(!fullscreen) {
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
      while(!FlGui::instance()->fullscreen->valid()) FlGui::wait();
      FlGui::instance()->fullscreen->getDrawContext()->copyViewAttributes(
        FlGui::instance()->getCurrentOpenglWindow()->getDrawContext());
      openglWindow::setLastHandled(FlGui::instance()->fullscreen);
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->getWindow()->hide();
      drawContext::global()->draw();
      fullscreen = 1;
    }
    else {
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->gl[0]->valid(0);
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->getWindow()->show();
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        while(!FlGui::instance()->graph[i]->gl[0]->valid()) FlGui::wait();
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->copyViewAttributes(
        FlGui::instance()->getCurrentOpenglWindow()->getDrawContext());
      openglWindow::setLastHandled(FlGui::instance()->graph[0]->gl[0]);
      FlGui::instance()->fullscreen->fullscreen_off();
      FlGui::instance()->fullscreen->hide();
      drawContext::global()->draw();
      fullscreen = 0;
    }
  }
  else if(str == "front") {
    // the order is important; the docked tool windows come with the main one
    FlGui *g = FlGui::instance();
    for(std::size_t i = 0; i < g->graph.size(); i++)
      g->graph[i]->getWindow()->show();
    for(Fl_Window *w : g->toolWindows())
      if(w->shown() && !w->parent()) w->show();
  }
}

void FlGui::addMessage(const char *msg)
{
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
    FlGui::instance()->graph[i]->addMessage(msg);
  }
}

void FlGui::saveMessages(const char *fileName)
{
  FlGui::instance()->graph[0]->saveMessages(fileName);
}

void FlGui::rebuildTree(bool deleteWidgets)
{
  if(onelab) onelab->rebuildTree(deleteWidgets);
  if(onelabContext) onelabContext->rebuild(deleteWidgets);
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
