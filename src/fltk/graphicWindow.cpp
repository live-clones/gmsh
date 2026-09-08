// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/filename.H>
#include <FL/Fl_Tree.H>
#include "FlGui.h"
#include "uiSources.h"
#include "mainWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "Gui.h"
#include "menuFltk.h"
#include "sceneViewFltk.h"
#include "onelabGroup.h"
#include "messageBrowser.h"
#include "extraDialogs.h"
#include "OS.h"

#if defined(HAVE_3M)
#include "3M.h"
#endif

#if defined(HAVE_TOUCHBAR)
#include "touchBar.h"
#endif





static void file_window_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  if(str == "new") {
    graphicWindow *g1 = FlGui::instance()->graph.back();
    graphicWindow *g2 =
      new graphicWindow(false, fltkSources().settings().sceneTiles);
    FlGui::instance()->graph.push_back(g2);
    g2->getWindow()->resize(g1->getWindow()->x() + 10,
                            g1->getWindow()->y() + 10, g1->getWindow()->w(),
                            g1->getWindow()->h());
    // named after the first window, numbered, as every window after the
    // first is
    const char *first = FlGui::instance()->graph[0]->getWindow()->label();
    g2->setTitle(std::string(first ? first : "Gmsh") + " [" +
                 std::to_string(FlGui::instance()->graph.size() - 1) + "]");
    g2->getWindow()->show();
  }
  else if(str == "split_h") {
    FlGui::instance()->splitCurrentOpenglWindow('h', 0.5);
  }
  else if(str == "split_v") {
    FlGui::instance()->splitCurrentOpenglWindow('v', 0.5);
  }
  else if(str == "split_u") {
    FlGui::instance()->splitCurrentOpenglWindow('u');
  }
  else if(str == "copy") {
    FlGui::instance()->copyCurrentOpenglWindowToClipboard();
  }
  drawContext::global()->draw();
}



// the close button of the window: what follows is the application's
void file_quit_cb(Fl_Widget *w, void *data)
{
  if(fltkHost().quitting) fltkHost().quitting();
}

void help_about_cb(Fl_Widget *w, void *data)
{
  Gui::showPanel(Gui::PanelAbout, true);
}

// The menu description of src/common/GuiMenus.h names these actions rather than
// naming FLTK callbacks, because the file chooser and the windows are the one
// part of a menu entry that is genuinely toolkit business.


bool fltkWindowAction(const std::string &what)
{
  if(what == "new" || what == "split_h" || what == "split_v" ||
     what == "split_u" || what == "copy")
    file_window_cb(nullptr, (void *)what.c_str());
  else if(what == "attach_detach")
    attach_detach_menu_cb(nullptr, nullptr);
  else if(what == "show_hide_tree")
    show_hide_menu_cb(nullptr, nullptr);
  else if(what == "minimize" || what == "zoom" || what == "fullscreen" ||
          what == "front")
    window_cb(nullptr, (void *)what.c_str());
#if defined(HAVE_3M)
  else if(what == "3m")
    window3M_cb(nullptr, nullptr);
#endif
  else
    return false;
  return true;
}

static graphicWindow *getGraphicWindow(Fl_Widget *w)
{
  if(!w || !w->parent()) return FlGui::instance()->graph[0];
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    if(FlGui::instance()->graph[i]->getWindow() == w->parent())
      return FlGui::instance()->graph[i];
  return FlGui::instance()->graph[0];
}

std::vector<sceneView *> fltkViewsBeside(sceneViewFltk *view)
{
  std::vector<sceneView *> views;
  if(!view) return views;
  if(view->parent())
    for(auto *gl : getGraphicWindow(view->parent())->gl)
      views.push_back(gl->scene());
  else
    views.push_back(view->scene());
  return views;
}

// The views the status bar acts upon are the panes of the graphic window the
// pointer is over, which is what makes this the interface's; what is done
// to them is the scene's.
void fltkOrientViews(const std::string &what, bool reverse, bool sync)
{
  Scene::orientViews(
    fltkViewsBeside(FlGui::instance()->getCurrentOpenglWindow()), what,
    reverse, sync);
}

// Picking with the mouse, on or off. The option is set by whoever asks;
// turning it off puts the pointer back to what it was, and it is the
// interface that has the pointers, which is why Gui::setMouseSelection()
// comes here.
void fltkSetMouseSelection(bool on)
{
  if(!on)
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->cursor(FL_CURSOR_DEFAULT, FL_BLACK,
                                                   FL_WHITE);
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    FlGui::instance()->graph[i]->refreshStatusButtons();
}

static void remove_graphic_window_cb(Fl_Widget *w, void *data)
{
  std::vector<graphicWindow *> graph2;
  graphicWindow *deleteMe = nullptr;
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
    if(FlGui::instance()->graph[i]->getWindow() == w)
      deleteMe = FlGui::instance()->graph[i];
    else
      graph2.push_back(FlGui::instance()->graph[i]);
  }
  if(deleteMe) {
    sceneViewFltk::setLastHandled(nullptr);
    FlGui::instance()->graph = graph2;
    delete deleteMe;
  }
}

void show_hide_menu_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g =
    getGraphicWindow(FlGui::instance()->getCurrentOpenglWindow()->parent());
  g->showHideMenu();
  FlGui::check();
}

void attach_detach_menu_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g =
    getGraphicWindow(FlGui::instance()->getCurrentOpenglWindow()->parent());
  g->attachDetachMenu();
  FlGui::check();
}

static void message_menu_autoscroll_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->setAutoScroll(!g->getAutoScroll());
}

static void message_menu_clear_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->clearMessages();
}

static void message_menu_save_cb(Fl_Widget *w, void *data)
{
  if(fltkSources().saveMessages) fltkSources().saveMessages();
}

static void message_browser_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->copySelectedMessagesToClipboard();
}

static void message_menu_search_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->getMessageBrowser()->clear();
  for(int i = 0; i < (int)g->getMessages().size(); i++)
    g->getMessageBrowser()->add(g->getMessages()[i].c_str());
}

static void tile_cb(Fl_Widget *w, void *data)
{
  if(Fl::event() == FL_RELEASE) {
    // rebuild the tree when we relase the mouse after resizing
    FlGui::instance()->rebuildTree(true);
  }
}

// This dummy box class permits to define a box widget that will not eat the
// FL_ENTER/FL_LEAVE events (the box widget in fltk > 1.1 does that, so that
// gl->handle() was not called when the mouse moved)
class dummyBox : public Fl_Box {
private:
  int handle(int) { return 0; } // always!
public:
  dummyBox(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Box(x, y, w, h, l)
  {
  }
};

// The main graphic window has a special resize behaviour forcing the message
// tile to always keep its height
class mainWindowSpecialResize : public mainWindow {
public:
  mainWindowSpecialResize(int w, int h, bool nonModal, const char *l = nullptr)
    : mainWindow(w, h, nonModal, l)
  {
  }
  virtual void resize(int X, int Y, int W, int H)
  {
    bool special = (FlGui::available() && shown() &&
                    this == FlGui::instance()->graph[0]->getWindow());
    int mh = 0;
    if(special) mh = FlGui::instance()->graph[0]->getMessageHeight();
    Fl_Window::resize(X, Y, W, H);
    const int minimum_non_message_height = 100;
    if(special && mh < h() - minimum_non_message_height)
      FlGui::instance()->graph[0]->setMessageHeight(mh);
  }
};

// The rest of the status bar: the last message and the progress of whatever is
// running, both read from src/common/GuiStatus.h as it draws rather than
// pushed into the widget -- which is what keeps the two bars saying the same
// thing.
class mainWindowProgress : public Fl_Progress {
public:
  mainWindowProgress(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Progress(x, y, w, h, l)
  {
  }
  void draw() override
  {
    const Ui::Backend::Sources &sources = fltkSources();
    Ui::BarMessage m = sources.barMessage ? sources.barMessage() : Ui::BarMessage();
    if(!label() || m.text != label()) copy_label(m.text.c_str());
    minimum(0.);
    maximum(m.running ? 1. : 0.);
    value(m.running ? (float)m.fraction : 0.f);
    bool dark = sources.settings().darkScheme;
    int col = (m.weight == Ui::MessageError) ? (dark ? FL_DARK_RED : FL_RED) :
              (m.weight == Ui::MessageWarning) ?
                                              (dark ? FL_DARK_YELLOW : FL_YELLOW) :
                                              -1;
    if(col >= 0) {
      if(dark)
        color(col);
      else
        labelcolor(col);
    }
    else {
      color(FL_BACKGROUND_COLOR);
      labelcolor(FL_FOREGROUND_COLOR);
    }
    Fl_Progress::draw();
  }
  int handle(int event)
  {
    if(event == FL_PUSH) {
      if(fltkSources().barPressed) fltkSources().barPressed();
      return 1;
    }
    return Fl_Progress::handle(event);
  }
};

graphicWindow::graphicWindow(bool main, int numTiles, bool detachedMenu)
  : _autoScrollMessages(true)
{
  // What the window is to be made of, as the settings say it. Clamped to
  // the screen here and not written back: what the window turned out to be
  // is asked of it when the option file is written, see layout().
  const Ui::Backend::Settings settings = fltkSources().settings();

  int mh = main ? BH : 0; // menu bar height
#if defined(__APPLE__)
  if(settings.systemMenuBar) mh = 0;
#endif
  int sh = 2 * FL_NORMAL_SIZE - 3; // status bar height
  int sw = FL_NORMAL_SIZE + 2; // status button width

  int mheight = main ? 2 * BH /* nonzero! */ : 0;
  int sceneHeight = settings.sceneHeight;
  int glheight = sceneHeight - mheight;
  // make sure glheight is positive
  if(glheight <= 0) {
    sceneHeight = 600;
    glheight = sceneHeight - mheight;
  }
  int height = mh + glheight + mheight + sh;
  // make sure height < screen height
  if(height > Fl::h()) {
    height = Fl::h();
    glheight = height - mh - mheight - sh;
    sceneHeight = glheight + mheight;
  }

  int twidth = (main && !detachedMenu) ? 14 * sw : 0;
  int sceneWidth = settings.sceneWidth;
  int glwidth = sceneWidth - twidth;
  // make sure glwidth is positive
  if(glwidth <= 0) {
    sceneWidth = 600;
    glwidth = sceneWidth - twidth;
  }
  int width = glwidth + twidth;
  // make sure width < screen width
  if(width > Fl::w()) {
    width = Fl::w();
    glwidth = width - twidth;
  }

  // the graphic window should be a "normal" window (neither modal nor
  // non-modal)
  if(main) {
    _win = new mainWindowSpecialResize(width, height, false);
    _win->callback(file_quit_cb);
  }
  else {
    _win = new paletteWindow(width, height, false);
    _win->callback(remove_graphic_window_cb);
  }

#if defined(__APPLE__)
  _sysbar = nullptr;
#endif
  _bar = nullptr;
  if(main) {
#if defined(__APPLE__)
    if(settings.systemMenuBar) {
      _sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
      _sysbar->menu(fltkMenuBuild(true));
      _sysbar->global();
    }
    else {
#endif
      _bar = new menuBarFltk(0, 0, width, BH);
      _bar->menu(fltkMenuBuild(false));
      _bar->global();
#if defined(__APPLE__)
    }
#endif
  }

  // minimum width should be exactly the width of the status bar buttons (see
  // below)
  _minWidth = 10 + 11 * sw + 1.75 * FL_NORMAL_SIZE;
  _minHeight = 100;
  _win->size_range(_minWidth, _minHeight);

  // a dummy resizable box that won't eat events
  dummyBox *resbox = new dummyBox(_minWidth, mh, width - _minWidth, glheight);
  _win->resizable(resbox);

  // tiled windows (tree menu, opengl, messages)
  _tile = new Fl_Tile(0, mh, glwidth + twidth, glheight + mheight);

  int w2 = glwidth / 2, h2 = glheight / 2;
  if(numTiles == 2) {
    gl.push_back(new sceneViewFltk(twidth, mh, w2, glheight));
    gl.back()->end();
    gl.push_back(new sceneViewFltk(twidth + w2, mh, glwidth - w2, glheight));
    gl.back()->end();
  }
  else if(numTiles == 3) {
    gl.push_back(new sceneViewFltk(twidth, mh, w2, glheight));
    gl.back()->end();
    gl.push_back(new sceneViewFltk(twidth + w2, mh, glwidth - w2, h2));
    gl.back()->end();
    gl.push_back(
      new sceneViewFltk(twidth + w2, mh + h2, glwidth - w2, glheight - h2));
    gl.back()->end();
  }
  else if(numTiles == 4) {
    gl.push_back(new sceneViewFltk(twidth, mh, w2, h2));
    gl.back()->end();
    gl.push_back(new sceneViewFltk(twidth + w2, mh, glwidth - w2, h2));
    gl.back()->end();
    gl.push_back(new sceneViewFltk(twidth, mh + h2, w2, glheight - h2));
    gl.back()->end();
    gl.push_back(
      new sceneViewFltk(twidth + w2, mh + h2, glwidth - w2, glheight - h2));
    gl.back()->end();
  }
  else {
    gl.push_back(new sceneViewFltk(twidth, mh, glwidth, glheight));
    gl.back()->end();
  }

  int mode = FL_RGB | FL_DEPTH | (settings.doubleBuffer ? FL_DOUBLE : FL_SINGLE);
  if(settings.antialiasing) mode |= FL_MULTISAMPLE;
  if(settings.stereo) {
    mode |= FL_DOUBLE;
    mode |= FL_STEREO;
  }
  for(std::size_t i = 0; i < gl.size(); i++) gl[i]->mode(mode);

  if(main) {
    _browser = new messageBrowser(twidth, mh + glheight, glwidth, mheight);
    int s = settings.consoleFontSize;
    _browser->textsize(s <= 0 ? FL_NORMAL_SIZE - 2 : s);
    _browser->callback(message_browser_cb, this);
    _browser->search_callback(message_menu_search_cb, this);
    _browser->autoscroll_callback(message_menu_autoscroll_cb, this);
    _browser->save_callback(message_menu_save_cb, this);
    _browser->clear_callback(message_menu_clear_cb, this);
  }
  else {
    _browser = nullptr;
  }

  if(main && !detachedMenu) {
    _onelab = new onelabGroup(0, mh, twidth, height - mh - sh);
    _onelab->enableTreeWidgetResize(false);
  }
  else {
    _onelab = nullptr;
  }

  _tile->callback(tile_cb);
  _tile->end();

  // resize the tiles to match the prescribed sizes
  _tile->position(0, mh + glheight, 0, mh + sceneHeight);

  // if the tree widget is too small it will not be rebuilt correctly (probably
  // a bug)... so impose minimum width -- and say so, since the tree is shown
  // again at the width the settings say
  int treeWidth = settings.treeWidth;
  int minw = 3 * BB / 2 + 4 * WB;
  if(treeWidth < minw) {
    treeWidth = minw;
    Ui::Backend::Layout l;
    l.treeWidth = treeWidth;
    _forgetting(l);
  }
  _tile->position(twidth, 0, treeWidth, 0);

  // bottom button bar
  _bottom = new Fl_Box(0, mh + glheight + mheight, width, sh);
  _bottom->box(GMSH_SIMPLE_TOP_BOX);

  int x = 2;
  int sht = sh - 4; // leave a 2 pixel border at the bottom

  // The buttons, as src/common/GuiStatus.h describes them: what they say,
  // what they do, and what they say about themselves. They used to be twelve
  // of them built here by hand, indexed in the order they happened to be
  // declared rather than the order they are drawn in.
  {
    std::vector<Ui::BarButton> wanted =
      fltkSources().barButtons ? fltkSources().barButtons() :
                                 std::vector<Ui::BarButton>();
    for(const auto &b : wanted) {
      if(b.gapBefore) x += 4;
      int bw = b.widthEm > 0. ? (int)(b.widthEm * FL_NORMAL_SIZE) : sw;
      statusButtonFltk *button =
        new statusButtonFltk(x, mh + glheight + mheight + 2, bw, sht);
      button->what = b;
      button->copy_label(button->shown().c_str());
      button->copy_tooltip(b.tooltip.c_str());
      if(b.action) {
        // Shift and Control are read when it is pressed, not described: what
        // they mean is the button's business
        button->callback(
          [](Fl_Widget *w, void *) {
            statusButtonFltk *b = (statusButtonFltk *)w;
            if(b->what.action)
              b->what.action(Fl::event_state(FL_SHIFT) ? true : false,
                             Fl::event_state(FL_CTRL) ||
                               Fl::event_state(FL_META));
          },
          nullptr);
      }
      button->box(FL_FLAT_BOX);
      button->selection_color(FL_WHITE);
      button->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      _butt.push_back(button);
      x += bw;
    }
  }

  x += 4;
  _label =
    new mainWindowProgress(x, mh + glheight + mheight + 2, width - x - 2, sht);
  _label->box(FL_FLAT_BOX);
  _label->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  if(settings.darkScheme)
    _label->color(FL_BACKGROUND_COLOR, FL_LIGHT3);
  else
    _label->color(FL_BACKGROUND_COLOR, FL_DARK2);

  _win->position(settings.sceneX, settings.sceneY);
  _win->end();

  if(main && detachedMenu) {
    _menuwin = new mainWindow(treeWidth, settings.treeHeight,
                              settings.nonModalWindows, "Gmsh");
    _menuwin->callback(file_quit_cb);
    _menuwin->box(GMSH_WINDOW_BOX);
    _onelab = new onelabGroup(0, 0, _menuwin->w(), _menuwin->h());
    _onelab->enableTreeWidgetResize(true);
    _menuwin->position(settings.treeX, settings.treeY);
    _menuwin->resizable(_onelab);
    _menuwin->size_range(_onelab->getMinWindowWidth(),
                         _onelab->getMinWindowHeight());
    _menuwin->end();
  }
  else {
    _menuwin = nullptr;
  }
}

graphicWindow::~graphicWindow()
{
  sceneViewFltk::setLastHandled(nullptr);
  _tile->clear();
  _win->clear();
  Fl::delete_widget(_win);
  if(_menuwin) {
    _menuwin->clear();
    Fl::delete_widget(_menuwin);
  }
}

void graphicWindow::setTitle(const std::string &str)
{
  _win->copy_label(str.c_str());
}

void graphicWindow::detachMenu()
{
  if(_menuwin || !_onelab || !_browser) return;
  if(_browser->h() == 0) setMessageHeight(1);
  int w = _onelab->w();
  _tile->remove(_onelab);
  _browser->resize(0, _browser->y(), _browser->w() + w, _browser->h());
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->x() == w) {
      gl[i]->resize(0, gl[i]->y(), gl[i]->w() + w, gl[i]->h());
    }
  }
  _tile->redraw();

  const Ui::Backend::Settings settings = fltkSources().settings();
  _menuwin = new mainWindow(_onelab->w(), settings.treeHeight,
                            settings.nonModalWindows, "Gmsh");
  _menuwin->callback(file_quit_cb);
  _menuwin->box(GMSH_WINDOW_BOX);
  _onelab->box(FL_FLAT_BOX);
  _menuwin->add(_onelab);
  _onelab->resize(0, 0, _menuwin->w(), _menuwin->h());
  _menuwin->position(settings.treeX, settings.treeY);
  _menuwin->resizable(_onelab);
  _menuwin->size_range(_onelab->getMinWindowWidth(),
                       _onelab->getMinWindowHeight());
  _menuwin->end();
  _menuwin->show();

  _onelab->enableTreeWidgetResize(true);
  _onelab->rebuildTree(true);
}

void graphicWindow::attachMenu()
{
  if(!_menuwin || !_onelab || !_browser) return;
  {
    // where it stood, for the next time it is detached
    Ui::Backend::Layout l;
    l.treeX = _menuwin->x();
    l.treeY = _menuwin->y();
    l.treeHeight = _menuwin->h();
    _forgetting(l);
  }
  _menuwin->remove(_onelab);
  _menuwin->hide();
  delete _menuwin;
  _menuwin = nullptr;
  if(_browser->h() == 0) setMessageHeight(1);
  int w = _onelab->w();
  if(_browser->w() - w < 0) w = _browser->w() / 2;
  _browser->resize(w, _browser->y(), _browser->w() - w, _browser->h());
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->x() == 0) {
      gl[i]->resize(w, gl[i]->y(), gl[i]->w() - w, gl[i]->h());
    }
  }
  _onelab->box(GMSH_SIMPLE_RIGHT_BOX);
  _tile->add(_onelab);
  _onelab->resize(_tile->x(), _tile->y(), w, _tile->h());
  _tile->redraw();

  _onelab->enableTreeWidgetResize(false);
  _onelab->rebuildTree(true);
}

void graphicWindow::attachDetachMenu()
{
  if(_menuwin)
    attachMenu();
  else
    detachMenu();
}

void graphicWindow::showMenu()
{
  if(_menuwin || !_onelab || !_win->shown()) return;
  if(_onelab->w() < FL_NORMAL_SIZE) {
    int width = fltkSources().settings().treeWidth;
    if(width < FL_NORMAL_SIZE) width = _onelab->getMinWindowWidth();
    int maxw = _win->w();
    if(width > maxw) width = maxw / 2;
    setMenuWidth(width);
    // necessary until resizing of 0-sized groups works
    _onelab->rebuildTree(true);
  }
}

void graphicWindow::hideMenu()
{
  if(_menuwin || !_onelab) return;
  Ui::Backend::Layout l;
  l.treeWidth = _onelab->w();
  _forgetting(l);
  setMenuWidth(0);
}

void graphicWindow::showHideMenu()
{
  if(_menuwin || !_onelab) return;
  if(_onelab->w() < FL_NORMAL_SIZE)
    showMenu();
  else
    hideMenu();
}

int graphicWindow::getMenuWidth()
{
  if(!_onelab) return 0;
  return _onelab->w();
}

int graphicWindow::getMenuHeight()
{
  if(!_menuwin) return 0;
  return _menuwin->h();
}

int graphicWindow::getMenuPositionX()
{
  if(!_menuwin) return 0;
  return _menuwin->x();
}

int graphicWindow::getMenuPositionY()
{
  if(!_menuwin) return 0;
  return _menuwin->y();
}

void graphicWindow::_forgetting(const Ui::Backend::Layout &what)
{
  if(fltkHost().layoutChanged) fltkHost().layoutChanged(what);
}

Ui::Backend::Layout graphicWindow::layout()
{
  Ui::Backend::Layout l;
  l.sceneX = _win->x();
  l.sceneY = _win->y();
  l.sceneWidth = getGlWidth();
  l.sceneHeight = getGlHeight();
  // a hidden console has nothing to say: what it measured when it was
  // hidden was said then
  if(getMessageHeight()) l.consoleHeight = getMessageHeight();
  l.treeWidth = getMenuWidth();
  l.treeDetached = _menuwin ? 1 : 0;
  if(_menuwin) {
    l.treeX = _menuwin->x();
    l.treeY = _menuwin->y();
    l.treeHeight = _menuwin->h();
  }
  return l;
}

bool graphicWindow::split(sceneViewFltk *g, char how, double ratio)
{
  if(_tile->find(g) == _tile->children()) return false; // not found

  if(how == 'u') {
    // after many tries I cannot figure out how to do this cleanly, so let's be
    // brutal :-)
    int mode = g->mode();
    sceneViewFltk::setLastHandled(nullptr);
    for(std::size_t i = 0; i < gl.size(); i++) {
      _tile->remove(gl[i]);
      delete gl[i];
    }
    gl.clear();
    sceneViewFltk *g2 = new sceneViewFltk(
      _tile->x() + (_onelab && !_menuwin ? _onelab->w() : 0), _tile->y(),
      _tile->w() - (_onelab && !_menuwin ? _onelab->w() : 0),
      _tile->h() - (_browser ? _browser->h() : 0));
    g2->end();
    g2->mode(mode);
    gl.push_back(g2);
    _tile->add(g2);
    g2->show();
    sceneViewFltk::setLastHandled(g2);
  }
  else {
    double fact = (ratio <= 0.) ? 0.01 : (ratio >= 1.) ? 0.99 : ratio;
    // make sure browser is not zero-size when adding children
    if(_browser && _browser->h() == 0) setMessageHeight(1);
    int x1 = g->x();
    int y1 = g->y();
    int w1 = (how == 'h') ? (int)(g->w() * fact) : g->w();
    int h1 = (how == 'h') ? g->h() : (int)(g->h() * fact);

    int x2 = (how == 'h') ? (g->x() + w1) : g->x();
    int y2 = (how == 'h') ? g->y() : (g->y() + h1);
    int w2 = (how == 'h') ? (g->w() - w1) : g->w();
    int h2 = (how == 'h') ? g->h() : (g->h() - h1);

    g->resize(x1, y1, w1, h1);
    sceneViewFltk *g2 = new sceneViewFltk(x2, y2, w2, h2);
    g2->end();
    g2->mode(g->mode());
    gl.push_back(g2);
    _tile->add(g2);
    g2->show();
    sceneViewFltk::setLastHandled(g2);
  }
  return true;
}

void graphicWindow::setStereo(bool st)
{
  sceneViewFltk::setLastHandled(nullptr);
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(st) { gl[i]->mode(FL_RGB | FL_DEPTH | FL_DOUBLE | FL_STEREO); }
    else {
      gl[i]->mode(FL_RGB | FL_DEPTH | FL_DOUBLE);
    }
    gl[i]->show();
  }
}

void graphicWindow::refreshStatusButtons()
{
  for(auto *b : _butt) b->refresh();
}

// What a button of the status bar is worth right now, asked of the description
// rather than remembered: an option changed from a script cannot leave it
// showing the wrong thing.
void statusButtonFltk::refresh()
{
  std::string text = shown();
  if(!label() || text != label()) copy_label(text.c_str());
  bool enabled = what.enabled ? what.enabled() : true;
  if(enabled != (active() ? true : false)) {
    if(enabled)
      activate();
    else
      deactivate();
  }
  // it is worth looking at: red, as the bar this reproduces paints the one
  // that says the mouse does not pick
  Fl_Color want = (what.alert && what.alert()) ? FL_RED : FL_BACKGROUND_COLOR;
  if(color() != want) color(want);
}

void graphicWindow::setMenuWidth(int w)
{
  if(!_onelab) return;
  if(_menuwin) {
    _menuwin->size(std::max(w, _onelab->getMinWindowWidth()), _menuwin->h());
    _menuwin->redraw();
    return;
  }
  if(!_browser) return;
  double dw = w - _onelab->w();
  if(!dw) return;
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->x() == _onelab->x() + _onelab->w()) {
      gl[i]->resize(gl[i]->x() + dw, gl[i]->y(), gl[i]->w() - dw, gl[i]->h());
    }
  }
  _browser->resize(_browser->x() + dw, _browser->y(), _browser->w() - dw,
                   _browser->h());
  _onelab->resize(_onelab->x(), _onelab->y(), _onelab->w() + dw, _onelab->h());
  _tile->redraw();
}

int graphicWindow::getGlHeight()
{
  int h = _win->h() - _bottom->h(); // yes, ignore message browser
  if(_bar) h -= _bar->h();
  return h;
}

int graphicWindow::getGlWidth() { return _win->w(); }

void graphicWindow::setGlWidth(int w)
{
  if(w == _win->w()) return;
  _win->size(std::max(w, _minWidth), _win->h());
  _win->redraw();
}

void graphicWindow::setGlHeight(int h)
{
  int hh = h + _bottom->h();
  if(_bar) hh += _bar->h();
  if(hh == _win->h()) return;
  _win->size(_win->w(), std::max(hh, _minHeight));
  _win->redraw();
}

void graphicWindow::setMessageHeight(int h)
{
  if(!_browser) return;
  int dh = h - _browser->h();
  if(!dh) return;
  for(std::size_t i = 0; i < gl.size(); i++) {
    if(gl[i]->y() + gl[i]->h() == _browser->y()) {
      gl[i]->resize(gl[i]->x(), gl[i]->y(), gl[i]->w(), gl[i]->h() - dh);
    }
  }
  _browser->resize(_browser->x(), _browser->y() - dh, _browser->w(),
                   _browser->h() + dh);
  _tile->redraw();
}

void graphicWindow::showMessages()
{
  if(!_browser || !_win->shown()) return;
  if(_browser->h() < FL_NORMAL_SIZE) {
    int height = fltkSources().settings().consoleHeight;
    if(height < FL_NORMAL_SIZE) height = 10 * FL_NORMAL_SIZE;
    int maxh = _win->h() - _bottom->h();
    if(height > maxh) height = maxh / 2;
    setMessageHeight(height);
  }
  if(_autoScrollMessages) _browser->bottomline(_browser->size());
}

void graphicWindow::hideMessages()
{
  if(!_browser) return;
  Ui::Backend::Layout l;
  l.consoleHeight = _browser->h();
  _forgetting(l);
  setMessageHeight(0);
}

void graphicWindow::showHideMessages()
{
  if(!_browser) return;
  if(_browser->h() < FL_NORMAL_SIZE)
    showMessages();
  else
    hideMessages();
}

int graphicWindow::getMessageHeight()
{
  if(!_browser) return 0;
  return _browser->h();
}

void graphicWindow::addMessage(const char *msg)
{
  if(!_browser) return;

    // this routine can be called from multiple threads, e.g. via Msg::Info
    // calls in meshGFace(). We should use FlGui::lock/unlock, but currently
    // this does not seem to work (17/02/2017)
#pragma omp critical(addMessage)
  {
    _messages.push_back(msg);
    _browser->add(msg);
    if(_autoScrollMessages && _win->shown() && _browser->h() >= FL_NORMAL_SIZE)
      _browser->bottomline(_browser->size());
  }
}

void graphicWindow::clearMessages()
{
  _messages.clear();
  if(!_browser) return;
  _browser->clear();
}

void graphicWindow::messageLines(std::vector<std::string> &lines)
{
  lines.clear();
  if(!_browser) return;
  for(int i = 1; i <= _browser->size(); i++) {
    const char *c = _browser->text(i);
    // a line the browser colours carries its colour in the first five
    // characters, which are none of the message
    lines.push_back((c[0] == '@') ? &c[5] : c);
  }
}

void graphicWindow::copySelectedMessagesToClipboard()
{
  if(!_browser) return;

  std::string buff;
  for(int i = 1; i <= _browser->size(); i++) {
    if(_browser->selected(i)) {
      const char *c = _browser->text(i);
      if(strlen(c) > 5 && c[0] == '@')
        buff += std::string(&c[5]);
      else
        buff += std::string(c);
      buff += "\n";
    }
  }
  // bof bof bof
  Fl::copy(buff.c_str(), buff.size(), 0);
  Fl::copy(buff.c_str(), buff.size(), 1);
}

void graphicWindow::setMessageFontSize(int size)
{
  if(!_browser) return;
  _browser->textsize(size <= 0 ? FL_NORMAL_SIZE - 2 : size);
  _browser->redraw();
}

void graphicWindow::changeMessageFontSize(int incr)
{
  if(!_browser) return;
  setMessageFontSize(_browser->textsize() + incr);
}

void graphicWindow::fillRecentHistoryMenu()
{
  // the recent files are read while the menu description is built, so there is
  // nothing to patch in place any more: the menu is simply built again
  Menu::invalidate();
#if defined(__APPLE__)
  if(fltkSources().settings().systemMenuBar) {
    if(_sysbar) _sysbar->menu(fltkMenuBuild(true));
    return;
  }
#endif
  if(_bar) _bar->menu(fltkMenuBuild(false));
}
