// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <sstream>
#include <string.h>
#include <FL/Fl.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Icon.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "drawContextFltk.h"
#include "drawContextFltkCairo.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "statisticsWindow.h"
#include "visibilityWindow.h"
#include "highOrderToolsWindow.h"
#include "clippingWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "onelabContextWindow.h"
#include "onelabGroup.h"
#include "helpWindow.h"
#include "colorbarWindow.h"
#include "fileDialogs.h"
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
#include "Context.h"
#include "StringUtils.h"
#include "gl2ps.h"
#include "gmshPopplerWrapper.h"
#include "PixelBuffer.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_TOUCHBAR)
#include "touchBar.h"
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

void FlGui::applyColorScheme(bool redraw)
{
  static int first = true;
  int N = 4 + FL_NUM_GRAY;
  static std::vector<unsigned char> r(N, 0), g(N, 0), b(N, 0);

  if(first) {
    // store default (OS-dependent) interface colors:
    Fl::get_system_colors();
    Fl::get_color(FL_BACKGROUND_COLOR, r[0], g[0], b[0]);
    Fl::get_color(FL_BACKGROUND2_COLOR, r[1], g[1], b[1]);
    Fl::get_color(FL_FOREGROUND_COLOR, r[2], g[2], b[2]);
    Fl::get_color(FL_SELECTION_COLOR, r[3], g[3], b[3]);
    for(int i = 0; i < FL_NUM_GRAY; i++) {
      Fl::get_color(fl_gray_ramp(i), r[4 + i], g[4 + i], b[4 + i]);
    }
  }

  if(CTX::instance()->guiColorScheme == 1) { // dark mode
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
  else if(!first && available() && CTX::instance()->guiColorScheme == 0) {
    // retore default colors (only if not calling the routine from the
    // constructor)
    Fl::set_color(FL_BACKGROUND_COLOR, r[0], g[0], b[0]);
    Fl::set_color(FL_BACKGROUND2_COLOR, r[1], g[1], b[1]);
    Fl::set_color(FL_FOREGROUND_COLOR, r[2], g[2], b[2]);
    for(int i = 0; i < FL_NUM_GRAY; i++) {
      Fl::set_color(fl_gray_ramp(i), r[4 + i], g[4 + i], b[4 + i]);
    }
    Fl::set_color(FL_SELECTION_COLOR, r[3], g[3], b[3]);
  }

  first = false;

  // also change default box type here (to thin versions)
  Fl::set_boxtype(FL_UP_BOX, FL_THIN_UP_BOX);
  Fl::set_boxtype(FL_DOWN_BOX, FL_THIN_DOWN_BOX);
  Fl::set_boxtype(FL_UP_FRAME, FL_THIN_UP_FRAME);
  Fl::set_boxtype(FL_DOWN_FRAME, FL_THIN_DOWN_FRAME);

  // thinner scrollbars
  Fl::scrollbar_size(std::max(10, FL_NORMAL_SIZE));

  if(redraw && available()) {
    updateViews(true, true);
    for(Fl_Window *win = Fl::first_window(); win; win = Fl::next_window(win)) {
      win->redraw();
    }
  }
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
  if(CTX::instance()->guiTheme.size())
    Fl::scheme(CTX::instance()->guiTheme.c_str());
  Fl_Tooltip::size(FL_NORMAL_SIZE);

  // use retina resolution if available
#if(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3) && (FL_PATCH_VERSION >= 4)
  Fl::use_high_res_GL(CTX::instance()->highResolutionGraphics);
#elif(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
  Fl::use_high_res_GL(CTX::instance()->highResolutionGraphics);
#endif

  // register image formats not in core fltk library (jpeg/png)
  fl_register_images();

  // add our own icons
  fl_add_symbol("gmsh_rewind", gmsh_rewind, 1);
  fl_add_symbol("gmsh_back", gmsh_back, 1);
  fl_add_symbol("gmsh_play", gmsh_play, 1);
  fl_add_symbol("gmsh_pause", gmsh_pause, 1);
  fl_add_symbol("gmsh_forward", gmsh_forward, 1);
  fl_add_symbol("gmsh_rotate", gmsh_rotate, 1);
  fl_add_symbol("gmsh_models", gmsh_models, 1);
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

  graph[0]->getWindow()->show(argc > 0 ? 1 : 0, argv);
  if(graph[0]->getMenuWindow()) graph[0]->getMenuWindow()->show();

  // re-apply color scheme (necessary after open_display to get the selection
  // color and boxtypes right)
  applyColorScheme();

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
  int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
  if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
  if(CTX::instance()->stereo) {
    mode |= FL_DOUBLE;
    mode |= FL_STEREO;
  }
  fullscreen->mode(mode);
  fullscreen->end();

  // create all other windows
  options = new optionWindow(CTX::instance()->deltaFontSize);
  fields = new fieldWindow(CTX::instance()->deltaFontSize);
  plugins = new pluginWindow(CTX::instance()->deltaFontSize);
  stats = new statisticsWindow(CTX::instance()->deltaFontSize);
  visibility = new visibilityWindow(CTX::instance()->deltaFontSize);
  highordertools = new highOrderToolsWindow(CTX::instance()->deltaFontSize);
  clipping = new clippingWindow(CTX::instance()->deltaFontSize);
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

  if(CTX::instance()->showOptionsOnStartup) options->win->show();
  if(CTX::instance()->showMessagesOnStartup) graph[0]->showMessages();

#if defined(HAVE_TOUCHBAR)
  showTouchBar();
#endif
}

FlGui::~FlGui()
{
  for(std::size_t i = 0; i < graph.size(); i++) delete graph[i];
  delete options;
  delete fields;
  delete plugins;
  delete stats;
  delete visibility;
  delete highordertools;
  delete clipping;
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

int FlGui::run()
{
  // draw the scene
  drawContext::global()->draw(false);

#if defined(HAVE_TOUCHBAR)
  updateTouchBar();
#endif

  return Fl::run();
}

int FlGui::testGlobalShortcuts(int event)
{
  // we only handle shortcuts here
  if(event != FL_SHORTCUT) return 0;

  int status = 0;

  if(Fl::test_shortcut('0')) {
    geometry_reload_cb(nullptr, nullptr);
    status = 1;
  }
  if(Fl::test_shortcut(FL_CTRL + '0') || Fl::test_shortcut(FL_META + '0') ||
     Fl::test_shortcut('9')) { // for Bruno
    onelab_reload_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut('1') || Fl::test_shortcut(FL_F + 1)) {
    mesh_1d_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut('2') || Fl::test_shortcut(FL_F + 2)) {
    mesh_2d_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut('3') || Fl::test_shortcut(FL_F + 3)) {
    mesh_3d_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_CTRL + 'q') ||
          Fl::test_shortcut(FL_META + 'q')) {
    // only necessary when using the system menu bar, but hey, it cannot hurt...
    file_quit_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_CTRL + 't') ||
          Fl::test_shortcut(FL_META + 't')) {
    show_hide_menu_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut('g')) {
    FlGui::toggleModule("Geometry");
    status = 1;
  }
  else if(Fl::test_shortcut('m')) {
    FlGui::toggleModule("Mesh");
    status = 1;
  }
  else if(Fl::test_shortcut('s')) {
    FlGui::toggleModule("Solver");
    status = 1;
  }
  else if(Fl::test_shortcut('p')) {
    FlGui::toggleModule("Post-processing");
    status = 1;
  }
  else if(Fl::test_shortcut('w')) {
    file_watch_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut('e')) {
    for(std::size_t i = 0; i < graph.size(); i++)
      for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
        graph[i]->gl[j]->endSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('u')) {
    for(std::size_t i = 0; i < graph.size(); i++)
      for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
        graph[i]->gl[j]->undoSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('i')) {
    for(std::size_t i = 0; i < graph.size(); i++)
      for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
        graph[i]->gl[j]->invertSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('q')) {
    for(std::size_t i = 0; i < graph.size(); i++)
      for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
        graph[i]->gl[j]->quitSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('-')) {
    for(std::size_t i = 0; i < graph.size(); i++)
      for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
        graph[i]->gl[j]->invertSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('x')) {
    elementaryContext->butt[0]->value(!elementaryContext->butt[0]->value());
    status = 1;
  }
  else if(Fl::test_shortcut('y')) {
    elementaryContext->butt[1]->value(!elementaryContext->butt[1]->value());
    status = 1;
  }
  else if(Fl::test_shortcut('z')) {
    elementaryContext->butt[2]->value(!elementaryContext->butt[2]->value());
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'x')) {
    elementaryContext->butt[0]->value(0);
    elementaryContext->butt[1]->value(1);
    elementaryContext->butt[2]->value(1);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'y')) {
    elementaryContext->butt[0]->value(1);
    elementaryContext->butt[1]->value(0);
    elementaryContext->butt[2]->value(1);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'z')) {
    elementaryContext->butt[0]->value(1);
    elementaryContext->butt[1]->value(1);
    elementaryContext->butt[2]->value(0);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_Escape) ||
          Fl::test_shortcut(FL_META + FL_Escape) ||
          Fl::test_shortcut(FL_SHIFT + FL_Escape) ||
          Fl::test_shortcut(FL_CTRL + FL_Escape) ||
          Fl::test_shortcut(FL_ALT + FL_Escape)) {
    if(fullscreen->shown()) {
      window_cb(nullptr, (void *)"fullscreen");
      status = 1;
    }
    else {
      bool lasso = false;
      for(std::size_t i = 0; i < graph.size(); i++)
        for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
          if(graph[i]->gl[j]->lassoMode) lasso = true;
      if(lasso) {
        for(std::size_t i = 0; i < graph.size(); i++)
          for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
            graph[i]->gl[j]->lassoMode = false;
        status = 2;
      }
      else {
        status_options_cb(nullptr, (void *)"S");
        status = 1;
      }
    }
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'a')) {
    window_cb(nullptr, (void *)"front");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'o')) {
    general_options_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'g')) {
    geometry_options_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'm')) {
    mesh_options_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 's')) {
    solver_options_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'p')) {
    post_options_cb(nullptr, nullptr);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'w')) {
    view_options_cb(nullptr, (void *)-1);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'u')) {
    if(PView::list.size()) {
      if(options->view.index >= 0 &&
         options->view.index < (int)PView::list.size())
        plugins->show(options->view.index);
      else
        plugins->show(0);
    }
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'f')) {
    opt_general_fast_redraw(0, GMSH_SET | GMSH_GUI,
                            !opt_general_fast_redraw(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'b')) {
    opt_general_draw_bounding_box(
      0, GMSH_SET | GMSH_GUI, !opt_general_draw_bounding_box(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'i')) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_show_scale(i, GMSH_SET | GMSH_GUI,
                            !opt_view_show_scale(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'c')) {
    opt_general_color_scheme(0, GMSH_SET | GMSH_GUI,
                             opt_general_color_scheme(0, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'c')) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_colormap_number(i, GMSH_SET | GMSH_GUI,
                                 opt_view_colormap_number(i, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'w')) {
    opt_geometry_light(0, GMSH_SET | GMSH_GUI,
                       !opt_geometry_light(0, GMSH_GET, 0));
    opt_mesh_light(0, GMSH_SET | GMSH_GUI, !opt_mesh_light(0, GMSH_GET, 0));
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_light(i, GMSH_SET | GMSH_GUI, !opt_view_light(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'x') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'x')) {
    status_xyz1p_cb(nullptr, (void *)"x");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'y') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'y')) {
    status_xyz1p_cb(nullptr, (void *)"y");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'z') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'z')) {
    status_xyz1p_cb(nullptr, (void *)"z");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + '1') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + '1') ||
          Fl::test_shortcut(FL_ALT + FL_CTRL + '1') ||
          Fl::test_shortcut(FL_ALT + FL_META + '1')) {
    status_xyz1p_cb(nullptr, (void *)"1:1");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'o')) {
    status_options_cb(nullptr, (void *)"p");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'a')) {
    opt_general_axes(0, GMSH_SET | GMSH_GUI,
                     opt_general_axes(0, GMSH_GET, 0) + 1);
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_axes(i, GMSH_SET | GMSH_GUI,
                      opt_view_axes(i, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'a')) {
    opt_general_small_axes(0, GMSH_SET | GMSH_GUI,
                           !opt_general_small_axes(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'p')) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI,
                        !opt_geometry_points(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'l')) {
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI,
                        !opt_geometry_curves(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 's')) {
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI,
                          !opt_geometry_surfaces(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'v')) {
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI,
                         !opt_geometry_volumes(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'p')) {
    opt_mesh_nodes(0, GMSH_SET | GMSH_GUI, !opt_mesh_nodes(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'l')) {
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, !opt_mesh_lines(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 's')) {
    opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI,
                           !opt_mesh_surface_edges(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'v')) {
    opt_mesh_volume_edges(0, GMSH_SET | GMSH_GUI,
                          !opt_mesh_volume_edges(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'd')) {
    opt_geometry_surface_type(0, GMSH_SET | GMSH_GUI,
                              opt_geometry_surface_type(0, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'd')) {
    opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI,
                           !opt_mesh_surface_faces(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'b')) {
    opt_mesh_volume_faces(0, GMSH_SET | GMSH_GUI,
                          !opt_mesh_volume_faces(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'm')) {
    quick_access_cb(nullptr, (void *)"mesh_toggle");
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 't')) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0)) {
        int t = opt_view_intervals_type(i, GMSH_GET, 0) + 1;
        if(t == 4) t = 1; // skip numeric display
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, t);
      }
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 't')) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI,
                                opt_view_intervals_type(i, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'r')) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_range_type(i, GMSH_SET | GMSH_GUI,
                            opt_view_range_type(i, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'n')) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_draw_strings(i, GMSH_SET | GMSH_GUI,
                              !opt_view_draw_strings(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'e') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'e')) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_show_element(i, GMSH_SET | GMSH_GUI,
                              !opt_view_show_element(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'h')) {
    static int show = 0;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, show);
    show = !show;
    status = 2;
  }
  else if(testArrowShortcuts()) {
    status = 1;
  }

#if defined(HAVE_TOUCHBAR)
  updateTouchBar();
#endif

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
  if(Fl::test_shortcut(FL_Left)) {
    status_play_manual(1, -CTX::instance()->post.animStep);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Right)) {
    status_play_manual(1, CTX::instance()->post.animStep);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Up)) {
    status_play_manual(0, -CTX::instance()->post.animStep);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Down)) {
    status_play_manual(0, CTX::instance()->post.animStep);
    return 1;
  }
#if defined(HAVE_POPPLER)
  else if(Fl::test_shortcut('u') || Fl::test_shortcut(FL_Page_Up)) {
    gmshPopplerWrapper::setCurrentPageDown();
    drawContext::global()->draw();
    return 1;
  }
  else if(Fl::test_shortcut('d') || Fl::test_shortcut(FL_Page_Down)) {
    gmshPopplerWrapper::setCurrentPageUp();
    drawContext::global()->draw();
    return 1;
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
  buffer->fill(0);
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
      if(CTX::instance()->guiColorScheme) // dark
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
    CTX::instance()->menuPosition[0] = graph[0]->getMenuPositionX();
    CTX::instance()->menuPosition[1] = graph[0]->getMenuPositionY();
  }
  else
    CTX::instance()->detachedMenu = 0;
  CTX::instance()->optPosition[0] = options->win->x();
  CTX::instance()->optPosition[1] = options->win->y();
  CTX::instance()->pluginPosition[0] = plugins->win->x();
  CTX::instance()->pluginPosition[1] = plugins->win->y();
  CTX::instance()->pluginSize[0] = plugins->win->w();
  CTX::instance()->pluginSize[1] = plugins->win->h();
  CTX::instance()->fieldPosition[0] = fields->win->x();
  CTX::instance()->fieldPosition[1] = fields->win->y();
  CTX::instance()->fieldSize[0] = fields->win->w();
  CTX::instance()->fieldSize[1] = fields->win->h();
  CTX::instance()->statPosition[0] = stats->win->x();
  CTX::instance()->statPosition[1] = stats->win->y();
  CTX::instance()->visPosition[0] = visibility->win->x();
  CTX::instance()->visPosition[1] = visibility->win->y();
  CTX::instance()->hotPosition[0] = highordertools->win->x();
  CTX::instance()->hotPosition[1] = highordertools->win->y();
  CTX::instance()->clipPosition[0] = clipping->win->x();
  CTX::instance()->clipPosition[1] = clipping->win->y();
  CTX::instance()->manipPosition[0] = manip->win->x();
  CTX::instance()->manipPosition[1] = manip->win->y();
  if(lastContextWindow == 4) {
    CTX::instance()->ctxPosition[0] = onelabContext->win->x();
    CTX::instance()->ctxPosition[1] = onelabContext->win->y();
  }
  else if(lastContextWindow == 3) {
    CTX::instance()->ctxPosition[0] = physicalContext->win->x();
    CTX::instance()->ctxPosition[1] = physicalContext->win->y();
  }
  else if(lastContextWindow == 2) {
    CTX::instance()->ctxPosition[0] = meshContext->win->x();
    CTX::instance()->ctxPosition[1] = meshContext->win->y();
  }
  else if(lastContextWindow == 1) {
    CTX::instance()->ctxPosition[0] = transformContext->win->x();
    CTX::instance()->ctxPosition[1] = transformContext->win->y();
  }
  else {
    CTX::instance()->ctxPosition[0] = elementaryContext->win->x();
    CTX::instance()->ctxPosition[1] = elementaryContext->win->y();
  }
#if defined(HAVE_3M)
  storeWindowPosition3M();
#endif

  fileChooserGetPosition(&CTX::instance()->fileChooserPosition[0],
                         &CTX::instance()->fileChooserPosition[1]);
}

// Callbacks

void redraw_cb(Fl_Widget *w, void *data) { drawContext::global()->draw(); }

void window_cb(Fl_Widget *w, void *data)
{
  static int oldx = 0, oldy = 0, oldw = 0, oldh = 0, zoom = 0, fullscreen = 0;

  std::string str((const char *)data);

  if(str == "minimize") {
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      if(FlGui::instance()->graph[i]->getWindow()->shown())
        FlGui::instance()->graph[i]->getWindow()->iconize();
    if(FlGui::instance()->options->win->shown())
      FlGui::instance()->options->win->iconize();
    if(FlGui::instance()->plugins->win->shown())
      FlGui::instance()->plugins->win->iconize();
    if(FlGui::instance()->fields->win->shown())
      FlGui::instance()->fields->win->iconize();
    if(FlGui::instance()->visibility->win->shown())
      FlGui::instance()->visibility->win->iconize();
    if(FlGui::instance()->highordertools->win->shown())
      FlGui::instance()->highordertools->win->iconize();
    if(FlGui::instance()->clipping->win->shown())
      FlGui::instance()->clipping->win->iconize();
    if(FlGui::instance()->manip->win->shown())
      FlGui::instance()->manip->win->iconize();
    if(FlGui::instance()->stats->win->shown())
      FlGui::instance()->stats->win->iconize();
  }
  else if(str == "zoom") {
    if(!zoom) {
      oldx = FlGui::instance()->graph[0]->getWindow()->x();
      oldy = FlGui::instance()->graph[0]->getWindow()->y();
      oldw = FlGui::instance()->graph[0]->getWindow()->w();
      oldh = FlGui::instance()->graph[0]->getWindow()->h();
      FlGui::instance()->graph[0]->getWindow()->resize(Fl::x(), Fl::y(),
                                                       Fl::w(), Fl::h());
      zoom = 1;
    }
    else {
      FlGui::instance()->graph[0]->getWindow()->resize(oldx, oldy, oldw, oldh);
      zoom = 0;
    }
  }
  else if(str == "fullscreen") {
    if(!fullscreen) {
      int x, y, w, h;
      Fl::screen_xywh(x, y, w, h);
      FlGui::instance()->fullscreen->resize(x, y, w, h);
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
    // the order is important!
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->getWindow()->show();
    if(FlGui::instance()->options->win->shown())
      FlGui::instance()->options->win->show();
    if(FlGui::instance()->plugins->win->shown())
      FlGui::instance()->plugins->win->show();
    if(FlGui::instance()->fields->win->shown())
      FlGui::instance()->fields->win->show();
    if(FlGui::instance()->elementaryContext->win->shown())
      FlGui::instance()->elementaryContext->win->show();
    if(FlGui::instance()->transformContext->win->shown())
      FlGui::instance()->transformContext->win->show();
    if(FlGui::instance()->physicalContext->win->shown())
      FlGui::instance()->physicalContext->win->show();
    if(FlGui::instance()->onelabContext->win->shown())
      FlGui::instance()->onelabContext->win->show();
    if(FlGui::instance()->meshContext->win->shown())
      FlGui::instance()->meshContext->win->show();
    if(FlGui::instance()->visibility->win->shown())
      FlGui::instance()->visibility->win->show();
    if(FlGui::instance()->highordertools->win->shown())
      FlGui::instance()->highordertools->win->show();
    if(FlGui::instance()->clipping->win->shown())
      FlGui::instance()->clipping->win->show();
    if(FlGui::instance()->manip->win->shown())
      FlGui::instance()->manip->win->show();
    if(FlGui::instance()->stats->win->shown())
      FlGui::instance()->stats->win->show();
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
