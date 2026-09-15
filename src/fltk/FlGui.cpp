// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <sstream>
#include <string.h>
#include <cctype>
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
#include "Gui.h"
#include "dialogFltk.h"
#include "uiSources.h"
#include "onelabGroup.h"
#include "colorbarWindow.h"
#include "fileDialogs.h"
#include "GmshMessage.h"
#include "OS.h"
#include "OpenFile.h"
#include "XpmIcon.h"
#include "Options.h"
#include "Context.h"
#include "PixelBuffer.h"

#if defined(HAVE_TOUCHBAR)
#include "touchBar.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

FlGui *FlGui::_instance = nullptr;
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

static int globalShortcut(int event)
{
  // we only handle shortcuts here
  if(!FlGui::available() || event != FL_SHORTCUT) return 0;
  return FlGui::instance()->runKeys();
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
    // the tree carries the colour of its lines: built again
    Gui::instance().updateViews(true, true);
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

  // Identify the windows to the desktop. Left alone FLTK announces its own name
  // as the X11 class, so the desktop cannot tell which application a window
  // belongs to -- and window rules (tiling extensions, "always on this
  // workspace", ...) key on exactly that. The name matches the StartupWMClass
  // of utils/freedesktop/info.gmsh.gmsh.desktop.
  Fl_Window::default_xclass("Gmsh");

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

  // add global shortcuts
  Fl::add_handler(globalShortcut);

  // the draw context that writes in the scene, with the engine the option
  // asks for
  Gui::instance().sceneSettingChanged("font_engine");
  if(drawContext::global()->getName() == "None")
    drawContext::setGlobal(new drawContextFltk);

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

  // the scene draws itself in those windows and asks them for what a window
  // has and it has not, so it is told who they are before the first one is
  // made
  fltkInstallSceneHost();

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
  // create window that will be used for fullscreen display
  fullscreen = new sceneViewFltk(100, 100, 100, 100);
  int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
  if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
  if(CTX::instance()->stereo) {
    mode |= FL_DOUBLE;
    mode |= FL_STEREO;
  }
  fullscreen->mode(mode);
  fullscreen->end();

  // draw
  for(std::size_t i = 0; i < graph.size(); i++)
    for(std::size_t j = 0; j < graph[i]->gl.size(); j++)
      graph[i]->gl[j]->redraw();

  if(CTX::instance()->showOptionsOnStartup) Gui::instance().options.show();
  if(CTX::instance()->showMessagesOnStartup) graph[0]->showMessages();

#if defined(HAVE_TOUCHBAR)
  showTouchBar();
#endif
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
  delete fullscreen;
}

bool FlGui::available() { return _instance != nullptr; }

FlGui *FlGui::instance(int argc, char **argv, bool quitShouldExit,
                       void (*error_handler)(const char *fmt, ...))
{
  // only the windows: what the application does once an interface is up is
  // Gui::instance().create()'s
  if(!_instance) _instance = new FlGui(argc, argv, quitShouldExit, error_handler);
  return _instance;
}

void FlGui::destroy()
{
  if(!_instance) return;

  // from now on, hiding a dialog is the interface going away rather than
  // the user closing it
  fltkDialogsClosingDown();

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

namespace {

  // The key FLTK reports, said as Ui::Shortcut says it: an upper case letter,
  // a digit or a punctuation mark, or one of the named keys. 0 for a key no
  // shortcut could name.
  int _uiKey(int key)
  {
    if(key >= 'a' && key <= 'z') return toupper(key);
    if(key >= FL_F + 1 && key <= FL_F + 12) return Ui::KeyF1 + key - FL_F - 1;
    switch(key) {
    case FL_Left: return Ui::KeyLeft;
    case FL_Right: return Ui::KeyRight;
    case FL_Up: return Ui::KeyUp;
    case FL_Down: return Ui::KeyDown;
    case FL_Escape: return Ui::KeyEscape;
    case FL_Home: return Ui::KeyHome;
    case FL_Page_Up: return Ui::KeyPageUp;
    case FL_Page_Down: return Ui::KeyPageDown;
    case FL_Delete: return Ui::KeyDelete;
    default: break;
    }
    if(key > ' ' && key < 127) return key;
    return 0;
  }

  // FL_COMMAND is FL_CTRL everywhere but on macOS, where it is the Command
  // key, which is what Ui::ModCommand means
  unsigned _uiMods()
  {
    unsigned mods = 0;
    if(Fl::event_state(FL_COMMAND)) mods |= Ui::ModCommand;
    if(Fl::event_state(FL_SHIFT)) mods |= Ui::ModShift;
    if(Fl::event_state(FL_ALT)) mods |= Ui::ModAlt;
    return mods;
  }

} // namespace

// the keys, read off the one list the interfaces share; what is left here
// is FLTK's own reading of a key event
int FlGui::runKeys()
{
  if(Fl::event_key() == FL_Escape && fullscreen && fullscreen->shown()) {
    window_cb(nullptr, (void *)"fullscreen");
    return 1;
  }
  int key = _uiKey(Fl::event_key());
  if(!key || !fltkSources().keys) return 0;
  unsigned mods = _uiMods();
  int status = 0;
  for(const Ui::KeyBinding &k : fltkSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    if(k.action) k.action();
    status = 1;
    if(k.spent) break;
  }
#if defined(HAVE_TOUCHBAR)
  updateTouchBar();
#endif
  return status;
}

sceneViewFltk *FlGui::getCurrentOpenglWindow()
{
  if(sceneViewFltk::lastHandled())
    return sceneViewFltk::lastHandled();
  else
    return graph[0]->gl[0];
}

void FlGui::setCurrentOpenglWindow(int which)
{
  int ii = 0;
  for(std::size_t i = 0; i < graph.size(); i++) {
    for(std::size_t j = 0; j < graph[i]->gl.size(); j++) {
      if(which == ii++) {
        sceneViewFltk::setLastHandled(graph[i]->gl[j]);
        return;
      }
    }
  }
  sceneViewFltk::setLastHandled(graph[0]->gl[0]);
}

void FlGui::splitCurrentOpenglWindow(char how, double ratio)
{
  sceneViewFltk *g = getCurrentOpenglWindow();
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
  return getCurrentOpenglWindow()->scene()->selectEntity(
    type, selectedVertices, selectedEdges, selectedFaces, selectedRegions,
    selectedElements, selectedPoints, selectedViews);
}

// where the windows ended up, for the option file
Ui::Backend::Layout FlGui::windowLayout()
{
  Ui::Backend::Layout l;
  if(graph.empty()) return l;
  l = graph[0]->layout();
  // the context dialogs share one remembered position
  bool placed = false;
  fltkEachDialog([&placed, &l](dialogFltk *d) {
    if(placed || !d->shown()) return;
    l.dialogX = d->window()->x();
    l.dialogY = d->window()->y();
    placed = true;
  });
#if defined(HAVE_3M)
  storeWindowPosition3M();
#endif
  fileChooserGetPosition(&l.chooserX, &l.chooserY);
  return l;
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
      // resize to screen size first, in case fullscreen does not work
      int x, y, w, h;
      Fl::screen_xywh(x, y, w, h);
      FlGui::instance()->fullscreen->resize(x, y, w, h);
      // setting resizable() is necessary with recent FLTK versions (1.4)
      FlGui::instance()->fullscreen->resizable(FlGui::instance()->fullscreen);
      FlGui::instance()->fullscreen->valid(0);
      FlGui::instance()->fullscreen->show();
      FlGui::instance()->fullscreen->fullscreen();
      while(!FlGui::instance()->fullscreen->valid()) FlGui::wait();
      FlGui::instance()->fullscreen->getDrawContext()->copyViewAttributes(
        FlGui::instance()->getCurrentOpenglWindow()->getDrawContext());
      sceneViewFltk::setLastHandled(FlGui::instance()->fullscreen);
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
      sceneViewFltk::setLastHandled(FlGui::instance()->graph[0]->gl[0]);
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
    fltkEachDialog([](dialogFltk *d) {
      if(d->shown()) d->window()->show();
    });
  }
}

void FlGui::addMessage(const char *msg)
{
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
    FlGui::instance()->graph[i]->addMessage(msg);
  }
}

void FlGui::messageLines(std::vector<std::string> &lines)
{
  FlGui::instance()->graph[0]->messageLines(lines);
}

void FlGui::rebuildTree(bool deleteWidgets)
{
  if(onelab) onelab->rebuildTree(deleteWidgets);
}
