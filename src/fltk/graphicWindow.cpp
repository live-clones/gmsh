// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The main window of the FLTK graphical user interface (graphicWindow): its
// menu bar, the tiles of the scene, the tree of the modules (onelabGroup), the
// messages and the status bar. In this file, in order:
// - the status bar: the points of view, the models, the query and the measure
//   (the tools that take the clicks), the quick access menu, the mouse
//   selection and the animation of the views;
// - the console, the menu and the docked tools shown or hidden, a window
//   added or closed;
// - the small widget classes of the window (its tile, menu bar, resizing,
//   progress bar), what a status bar button does and its tooltip (the buttons
//   come from the "Status bar" menu of the registry), the constructor, and
//   the methods that size and split the window, the menu and the messages.
// Elsewhere: what the menu bar does (its items from Actions.cpp, run through
// the table of fltkActions.cpp; the File and Help menus in fileActions.cpp),
// the docking of the tool windows
// (toolDock.cpp), the rows of the modules (onelabGroup.cpp).

#include "GmshConfig.h"
#include "GmshDefines.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Button.H>
#include "FlGui.h"
#include "Shortcuts.h"
#include "mainWindow.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "fltkActions.h"
#include "fileActions.h"
#include "sceneTool.h"
#include "toolDock.h"
#include "gmshScheme.h"
#include "icons.h"
#include "optionWindow.h"
#include "statisticsWindow.h"
#include "visibilityWindow.h"
#include "clippingWindow.h"
#include "manipWindow.h"
#include "pluginWindow.h"
#include "helpWindow.h"
#include "windowPlacement.h"
#include "openglWindow.h"
#include "onelabGroup.h"
#include "messageBrowser.h"
#include "fileDialogs.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "OpenFile.h"
#include "Options.h"
#include "Context.h"
#include "OS.h"
#include "Actions.h"

static graphicWindow *getGraphicWindow(Fl_Widget *w)
{
  if(!w || !w->parent()) return FlGui::instance()->graph[0];
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    if(FlGui::instance()->graph[i]->getWindow() == w->parent())
      return FlGui::instance()->graph[i];
  return FlGui::instance()->graph[0];
}

void setPointOfView(const char *str, graphicWindow *g)
{
  // the viewports of the window of the button; from a key the current one,
  // or all those of its window to sync them (Ctrl)
  std::vector<openglWindow *> gls;
  openglWindow *current = FlGui::instance()->getCurrentOpenglWindow();
  bool sync = Fl::event_state(FL_CTRL) || Fl::event_state(FL_META);
  if(g)
    gls = g->gl;
  else if(sync) {
    for(graphicWindow *g : FlGui::instance()->graph)
      if(std::find(g->gl.begin(), g->gl.end(), current) != g->gl.end())
        gls = g->gl;
  }
  if(gls.empty()) gls.push_back(current);

  for(std::size_t i = 0; i < gls.size(); i++) {
    drawContext *ctx = gls[i]->getDrawContext();
    if(!strcmp(str, "r")) {
      // rotate +90 or -90 (shift) degress around axis perp to the
      // screen, or sync rotation with first window (Ctrl)
      double axis[3] = {0., 0., 1.};
      if(Fl::event_state(FL_CTRL) || Fl::event_state(FL_META)) {
        if(i != 0) {
          drawContext *ctx0 = gls[0]->getDrawContext();
          ctx->setQuaternion(ctx0->quaternion[0], ctx0->quaternion[1],
                             ctx0->quaternion[2], ctx0->quaternion[3]);
        }
      }
      else if(!Fl::event_state(FL_SHIFT)) {
        ctx->addQuaternionFromAxisAndAngle(axis, -90.);
        if(CTX::instance()->camera) ctx->camera.tiltHeadRight();
      }
      else {
        ctx->addQuaternionFromAxisAndAngle(axis, 90.);
        if(CTX::instance()->camera) ctx->camera.tiltHeadLeft();
      }
    }
    else if(!strcmp(str, "1:1")) {
      // if Shift is pressed, reset bounding box around visible entities
      if(Fl::event_state(FL_SHIFT)) SetBoundingBox(true);
      // fit the model in the window, or sync translation and scaling with the
      // first window (Ctrl)
      if(!CTX::instance()->camera &&
         (Fl::event_state(FL_CTRL) || Fl::event_state(FL_META))) {
        if(i != 0) {
          drawContext *ctx0 = gls[0]->getDrawContext();
          for(int j = 0; j < 3; j++) {
            ctx->t[j] = ctx0->t[j];
            ctx->s[j] = ctx0->s[j];
          }
        }
      }
      else
        ctx->standardView(str, false);
    }
    else {
      // an axis pointing out of the screen, or into it (Shift), the
      // isometric view, or no rotation, translation or scaling
      ctx->standardView(str, Fl::event_state(FL_SHIFT));
    }
  }
  drawContext::global()->draw();
  FlGui::instance()->manip->update();
}

static void model_switch_cb(Fl_Widget *w, void *data)
{
  int index = (intptr_t)data;
  GModel::current(index);
  SetBoundingBox();
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    GModel::list[i]->setVisibility(0);
  GModel::current()->setVisibility(1);
  CTX::instance()->meshChanged();
  Msg::SetWindowTitle(GModel::current()->getFileName());
  FlGui::instance()->resetVisibility();
  drawContext::global()->draw();
}

// The two tools that take the clicks on the model, until asked to stop (their
// button again, or Escape), shared with the web page (see sceneTool):
// - in query mode, every click says what the model holds where it hit: the
//   entity, the mesh element and the node there, and the value of every
//   visible view. A click replaces what the queries before it left on the
//   picture, a Ctrl+click adds to it. (The first query of a large mesh or view
//   builds a search structure that the ones after it reuse.)
// - in measure mode, two clicks give the distance between the points they hit,
//   drawn on the picture and printed.
// Starting one stops the other.
bool queryMode() { return sceneTool::running("Query"); }

bool measureMode() { return sceneTool::running("Measure"); }

void toggleTool(const std::string &name)
{
  if(!FlGui::available()) return;
  if(sceneTool::running(name)) {
    sceneTool::stop();
    return;
  }
  sceneTool::start(name == "Query" ? newQueryTool() : newMeasureTool(),
                   FlGui::instance()->getCurrentOpenglWindow());
}

void updateModeButtons()
{
  if(!FlGui::available()) return;
  // a query and a measurement in yellow, as what they leave on the picture by
  // default (see General.Color.Query)
  Fl_Color col = gmshIndicator(IndicatorYellow);
  auto colour = [](Fl_Button *b, bool on, Fl_Color c) {
    if(!b) return;
    b->color(on ? c : FL_BACKGROUND_COLOR);
    b->redraw();
  };
  for(graphicWindow *g : FlGui::instance()->graph) {
    colour(g->statusButton("query"), queryMode(), col);
    colour(g->statusButton("measure"), measureMode(), col);
    colour(g->statusButton("mouse_selection"), !CTX::instance()->mouseSelection,
           gmshIndicator(IndicatorRed));
  }
}

void modelsMenu()
{
  std::vector<char *> tofree;
  std::vector<Fl_Menu_Item> menu;
  int selected = 0;
  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    std::ostringstream sstream;
    sstream << "Model " << i;
    if(GModel::list[i]->getName().size())
      sstream << " - " << GModel::list[i]->getName();
    sstream << " ";
    char *str = strdup(sstream.str().c_str());
    Fl_Menu_Item menuItem = {str, 0, model_switch_cb, (void *)(intptr_t)i,
                             FL_MENU_RADIO};
    if(GModel::list[i] == GModel::current()) {
      selected = i;
      menuItem.flags |= FL_MENU_VALUE;
    }
    menu.push_back(menuItem);
    tofree.push_back(str);
  }
  Fl_Menu_Item it = {nullptr};
  menu.push_back(it);
  Fl_Menu_Item *m = (Fl_Menu_Item *)(&menu[0])->popup(
    Fl::event_x(), Fl::event_y(), nullptr, &menu[selected], gmshPopupStyle());
  if(m) m->do_callback(nullptr);
  for(std::size_t i = 0; i < tofree.size(); i++) free(tofree[i]);
  drawContext::global()->draw();
}

// the shortcuts of the main menu, whatever window has the focus: as
// Fl_Menu_::global(), but undone when the menu goes (FLTK's cannot be)
static Fl_Menu_ *globalMenu = nullptr;

static int globalMenuHandler(int e)
{
  if(e != FL_SHORTCUT || Fl::modal() || !globalMenu) return 0;
  Fl::first_window(globalMenu->window());
  return globalMenu->handle(e);
}

void quickAccessMenu()
{
  // the menu (see Actions.cpp), opened on the item picked last
  static Fl_Menu_Button *menu = nullptr;
  static const void *last = nullptr;
  if(!menu) {
    Fl_Group::current(nullptr);
    menu = new Fl_Menu_Button(0, 0, 0, 0);
  }
  menu->clear();
  addMenuItems(menu, GetActionMenu("Quick access"), -1);
  // (the display of the mesh toggled, at first)
  const Fl_Menu_Item *initial = nullptr;
  for(int i = 0; i < menu->size(); i++) {
    const actionItem *item = (const actionItem *)menu->menu()[i].user_data();
    if(item && (last ? item == last : item->name == "mesh_toggle"))
      initial = &menu->menu()[i];
  }
  const Fl_Menu_Item *picked = menu->menu()->popup(
    Fl::event_x(), Fl::event_y(), nullptr, initial, gmshPopupStyle());
  if(picked && picked->callback()) {
    last = picked->user_data();
    // run once the event is over: an item may delete the pane double-clicked
    // (Unsplit), whose handle() is still running
    static Fl_Callback *cb;
    static void *data;
    cb = picked->callback();
    data = picked->user_data();
    Fl::add_timeout(0., [](void *) {
      cb(menu, data);
      drawContext::global()->draw();
    });
  }
  drawContext::global()->draw();
}

void toggleMouseSelection()
{
  if(CTX::instance()->mouseSelection) {
    opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
  }
  else
    opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
}

void stepAnimation(int time, int incr, bool redraw)
{
  // avoid firing this routine recursively (can happen e.g when
  // keeping the finger down on the arrow key: if the system generates
  // too many events, we can overflow the stack--that happened on my
  // powerbook with the new, optimzed FLTK event handler)
  static bool busy = false;
  if(busy) return;
  busy = true;

  // if we watch some files this is a good time to check for new data
  mergeWatchedFiles();

  PView::animate(time, incr);
  if(redraw) drawContext::global()->draw();
  busy = false;
}

// the animation: a step every PostProcessing.AnimationDelay seconds, from a
// timer, the events being processed by the event loop between the steps;
// playing until paused (a pause handled while a step runs cannot remove the
// timer, which re-arms itself)
static bool animPlaying = false;

static void animate_cb(void *)
{
  if(!FlGui::available() || !animPlaying) return;
  // no step during another operation (the timer runs in its event loops too),
  // e.g. an export of the animation, which steps the views itself, as the
  // animation paused when it ran its own loop
  if(!CTX::instance()->lock && !FlGui::handlingEvent())
    stepAnimation(!CTX::instance()->post.animCycle,
                  CTX::instance()->post.animStep);
  // not again if a pause then a play during the step started another timer
  if(animPlaying && !Fl::has_timeout(animate_cb))
    Fl::repeat_timeout(CTX::instance()->post.animDelay, animate_cb);
}

void rewindAnimation()
{
  if(!CTX::instance()->post.animCycle) {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      int step = PView::list[i]->getData()->getFirstNonEmptyTimeStep();
      opt_view_timestep(i, GMSH_SET | GMSH_GUI, step);
    }
  }
  else
    PView::animate(false, 0);
  drawContext::global()->draw();
}

bool animationPlaying() { return animPlaying; }

void playOrPauseAnimation()
{
  animPlaying = !animPlaying;
  if(animPlaying)
    Fl::add_timeout(CTX::instance()->post.animDelay, animate_cb);
  else
    Fl::remove_timeout(animate_cb);
  for(graphicWindow *g : FlGui::instance()->graph)
    g->setAnimButtons(animPlaying);
}

void newGraphicWindow()
{
  graphicWindow *g1 = FlGui::instance()->graph.back();
  graphicWindow *g2 = new graphicWindow(false, CTX::instance()->numTiles);
  FlGui::instance()->graph.push_back(g2);
  g2->getWindow()->resize(g1->getWindow()->x() + 10, g1->getWindow()->y() + 10,
                          g1->getWindow()->w(), g1->getWindow()->h());
  g2->getWindow()->show();
  FlGui::instance()->setGraphicTitle(GModel::current()->getFileName());
}

// the main window closed: the program ends (see fileQuit())
static void quit_cb(Fl_Widget *w, void *data) { fileQuit(); }

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
    openglWindow::setLastHandled(nullptr);
    FlGui::instance()->graph = graph2;
    delete deleteMe;
  }
}

void showHideMessages()
{
  graphicWindow *g =
    getGraphicWindow(FlGui::instance()->getCurrentOpenglWindow()->parent());
  g->showHideMessages();
  FlGui::check();
}

void showHideMenu()
{
  graphicWindow *g =
    getGraphicWindow(FlGui::instance()->getCurrentOpenglWindow()->parent());
  g->showHideMenu();
  FlGui::check();
}

void dockCurrentTool()
{
  FlGui::instance()->toggleCurrentTool();
  FlGui::check();
}

void dockAllTools()
{
  // docks every tool when any is open on the desktop, undocks every one
  // when all the open ones are docked; with none open, the list is flipped
  bool open = false, floating = false;
  for(paletteWindow *p : FlGui::instance()->toolWindows()) {
    if(!p->isOpen()) continue;
    open = true;
    if(p->floating()) floating = true;
  }
  bool dock = open ? floating : !CTX::instance()->floatingTools.empty();
  FlGui::instance()->dockTools(dock);
  FlGui::check();
}

static void dock_divider_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->setDockWidth(g->getWindow()->w() - Fl::event_x() - WB / 2);
}

void attachDetachMenu()
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
  graphicWindow *g = (graphicWindow *)data;
  if(fileChooser(FILE_CHOOSER_CREATE, "Save Messages", ""))
    g->saveMessages(fileChooserGetName(1).c_str());
}

static void message_browser_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->copySelectedMessagesToClipboard();
}

static void message_menu_search_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->getMessageBrowser()->rebuild(g->getMessages());
}

static void message_menu_copy_cb(Fl_Widget *w, void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  g->copySelectedMessagesToClipboard();
}

// the tiles of the main window, which also call their callback when pressed,
// as Fl_Tile does only when an edge moves and when it is released
class mainTile : public Fl_Tile {
public:
  mainTile(int x, int y, int w, int h) : Fl_Tile(x, y, w, h) {}
  int handle(int event)
  {
    if(event == FL_PUSH) do_callback(FL_REASON_SELECTED);
    return Fl_Tile::handle(event);
  }
};

static void tile_cb(Fl_Widget *w, void *data)
{
  if(Fl::callback_reason() == FL_REASON_SELECTED) {
    getGraphicWindow(w)->tilePushed();
    return;
  }
  if(Fl::event() == FL_RELEASE) {
    getGraphicWindow(w)->tileReleased();
    // rebuild the tree when we release the mouse after resizing
    FlGui::instance()->rebuildTree();
  }
}

// the least sizes of the menu and the messages in the tiles: their edges
// could not be grabbed again at the border of the tile, where the graphics,
// subwindows, take the events; the menu as wide as its Check, Run and gear
// buttons (see onelabGroup)
static int minMenuWidth() { return 3 * (BB / 2 + 4) + 4 * WB; }
static int minMessageHeight() { return 2 * BH; }

// The menu bar of the window, when it is not the system's: the title under
// the pointer is highlighted, as the bars of the desktops do (FLTK draws the
// titles without a box of their own, so the bar draws them itself, laid out
// as Fl_Menu_Bar lays them out)
class hoverMenuBar : public Fl_Menu_Bar {
  int _hot; // the title under the pointer, or -1
  int _titleAt(int px)
  {
    int X = x() + 6, i = 0;
    for(const Fl_Menu_Item *m = menu()->first(); m->text; m = m->next(), i++) {
      int W = m->measure(0, this) + 16;
      if(px >= X && px < X + W) return i;
      X += W;
    }
    return -1;
  }

public:
  hoverMenuBar(int x, int y, int w, int h) : Fl_Menu_Bar(x, y, w, h), _hot(-1)
  {
  }
  int handle(int event)
  {
    if(menu() && (event == FL_ENTER || event == FL_MOVE || event == FL_LEAVE)) {
      int hot = (event == FL_LEAVE) ? -1 : _titleAt(Fl::event_x());
      if(hot != _hot) {
        _hot = hot;
        redraw();
      }
    }
    // a click opens a menu, which runs in a loop of its own where the bar
    // sees no move: no highlight while it is open, nor after, until the
    // pointer moves over the bar again
    if(event == FL_PUSH && _hot >= 0) {
      _hot = -1;
      redraw();
    }
    int ret = Fl_Menu_Bar::handle(event);
    if(event == FL_PUSH && _hot >= 0) {
      _hot = -1;
      redraw();
    }
    return ret;
  }
  void draw()
  {
    // the open title and the items of its menu in a neutral grey (see
    // gmshMenuHighlight())
    if(gmshScheme()) selection_color(gmshMenuHighlight());
    draw_box();
    if(!menu() || !menu()->text) return;
    int X = x() + 6, i = 0;
    for(const Fl_Menu_Item *m = menu()->first(); m->text; m = m->next(), i++) {
      int tw = m->measure(0, this), W = tw + 16;
      if(i == _hot) {
        // the text, drawn 3 pixels into its slot, with the same margin on
        // both sides
        fl_color(hoverHighlight(color()));
        fl_rectf(X - 2, y() + 1, tw + 10, h() - 2);
      }
      m->draw(X, y(), W, h(), this);
      X += W;
    }
  }
};

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

// A graphic window other than the main one: closed by the key that closes a
// window, and Escape left to the scene and the global shortcuts, as in the
// main window (a tool window would close on it)
class secondaryGraphicWindow : public gmshWindow {
public:
  secondaryGraphicWindow(int w, int h)
    : gmshWindow(w, h, false, nullptr, nullptr)
  {
  }
  virtual int handle(int event)
  {
    if((event == FL_SHORTCUT || event == FL_KEYBOARD) && _closeKey()) {
      do_callback();
      return 1;
    }
    return Fl_Double_Window::handle(event);
  }
  virtual void show() { _showOnDesktop(); }
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
    // not Fl_Window::resize(): Fl_Double_Window::resize() drops the offscreen
    // buffer when the window grows (on Windows the parts out of the old buffer
    // stay black otherwise)
    mainWindow::resize(X, Y, W, H);
    const int minimum_non_message_height = 100;
    if(special && mh < h() - minimum_non_message_height)
      FlGui::instance()->graph[0]->setMessageHeight(mh);
  }
};

// the message of the status bar, a progress bar while something runs; a click
// on it shows or hides the message console, and it is tinted under the
// pointer like the other controls of the bar (the theme does not take a
// progress bar for one)
class mainWindowProgress : public Fl_Progress {
public:
  mainWindowProgress(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Progress(x, y, w, h, l)
  { tooltip("Show or hide the message console"); }
  void draw()
  {
    Fl_Color c = color();
    color(hoverHighlight(this, c));
    Fl_Progress::draw();
    color(c);
  }
  int handle(int event)
  {
    switch(event) {
    case FL_ENTER:
    case FL_LEAVE: redraw(); return 1;
    case FL_PUSH:
      if(FlGui::available()) {
        for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
          FlGui::instance()->graph[i]->showHideMessages();
      }
      return 1;
    }
    return Fl_Progress::handle(event);
  }
};

// The buttons of the status bar come from the "Status bar" menu of the
// registry (see Actions.cpp): a click runs its item, for the window of the
// button (see statusBarWindow())
static graphicWindow *statusWindow = nullptr;

graphicWindow *statusBarWindow() { return statusWindow; }

static void status_item_cb(Fl_Widget *w, void *data)
{
  statusWindow = getGraphicWindow(w);
  runItem(*(const actionItem *)data);
  statusWindow = nullptr;
}

// the tooltip of a button: the help of its item, with its keys
static std::string statusTooltip(const actionItem &item)
{
  std::string keys;
  // (without "with any modifier", a detail of how the key is matched)
  for(const Shortcut &s : GetShortcutsOf(item.name))
    keys += (keys.empty() ? "" : ", ") +
            Shortcut(s.key, s.mods & ~AnyModifiers).label();
  return keys.empty() ? item.help : item.help + " (" + keys + ")";
}

graphicWindow::graphicWindow(bool main, int numTiles, bool detachedMenu)
  : _autoScrollMessages(true), _pushX(0), _pushY(0), _pushMenuWidth(0),
    _pushMessageHeight(0)
{
  int mh = main ? BH : 0; // menu bar height
#if defined(__APPLE__)
  if(CTX::instance()->systemMenuBar) mh = 0;
#endif
  // the status bar and its buttons: as tall as the menu bar, and wide enough
  // for their icons
  int sh = BH;
  int sw = 1.7 * FL_NORMAL_SIZE + 1;
  _iconSize = FL_NORMAL_SIZE + 1; // the icons on the scale of the letters

  // the usable area of the screen that will show the window
  int screenX, screenY, screenW, screenH;
  Fl::screen_work_area(screenX, screenY, screenW, screenH,
                       Fl::screen_num(CTX::instance()->glPosition[0],
                                      CTX::instance()->glPosition[1]));

  int mheight = main ? 2 * BH /* nonzero! */ : 0;
  int glheight = CTX::instance()->glSize[1] - mheight;
  // make sure glheight is positive
  if(glheight <= 0) {
    CTX::instance()->glSize[1] = 600;
    glheight = CTX::instance()->glSize[1] - mheight;
  }
  int height = mh + glheight + mheight + sh;
  // make sure height < screen height
  if(height > screenH) {
    height = screenH;
    glheight = height - mh - mheight - sh;
    CTX::instance()->glSize[1] = glheight + mheight;
  }

  int twidth = (main && !detachedMenu) ? 14 * (FL_NORMAL_SIZE + 2) : 0;
  int glwidth = CTX::instance()->glSize[0] - twidth;
  // make sure glwidth is positive
  if(glwidth <= 0) {
    CTX::instance()->glSize[0] = 600;
    glwidth = CTX::instance()->glSize[0] - twidth;
  }
  int width = glwidth + twidth;
  // make sure width < screen width
  if(width > screenW) {
    width = screenW;
    glwidth = width - twidth;
    CTX::instance()->glSize[0] = glwidth + twidth;
  }

  // the graphic window should be a "normal" window (neither modal nor
  // non-modal)
  if(main) {
    _win = new mainWindowSpecialResize(width, height, false);
    _win->callback(quit_cb);
  }
  else {
    _win = new secondaryGraphicWindow(width, height);
    _win->callback(remove_graphic_window_cb);
  }

#if defined(__APPLE__)
  _sysbar = nullptr;
#endif
  _bar = nullptr;
  if(main) {
#if defined(__APPLE__)
    if(CTX::instance()->systemMenuBar)
      _sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
    else
#endif
      _bar = new hoverMenuBar(0, 0, width, BH);
    Fl_Menu_ *m = _menuBar();
    addMenuItems(m, GetActionMenu("Menu bar"), -1, false);
#if defined(__APPLE__)
    if(_sysbar) {
      // Quit and About are in the application menu, and Cmd+H hides the
      // application: the keyboard help has another shortcut
      for(const char *path : {"File/Quit", "Help/About Gmsh"}) {
        int i = m->find_index(path);
        if(i < 1) continue;
        m->remove(i);
        // (the last of its menu: no divider above it then)
        m->mode(i - 1, m->mode(i - 1) & ~FL_MENU_DIVIDER);
      }
      int i = m->find_index("Help/Keyboard and Mouse Usage");
      if(i >= 0) m->shortcut(i, fltkShortcut("help_keys", true));
    }
#endif
    Fl::remove_handler(globalMenuHandler);
    Fl::add_handler(globalMenuHandler);
    globalMenu = m;
    fillRecentHistoryMenu();
  }

  // a dummy resizable box that won't eat events, created before the tile so
  // that FLTK does not find it first when it looks for the widget under the
  // mouse (which would turn every move over the graphic windows into a leave
  // and an enter, and no move at all); its place is set below, once the
  // status bar says where the resizing part of the window starts
  dummyBox *resbox = new dummyBox(0, mh, width, glheight);
  _win->resizable(resbox);
  _resbox = resbox;

  // tiled windows (tree menu, opengl, messages)
  _tile = new mainTile(0, mh, glwidth + twidth, glheight + mheight);

  int w2 = glwidth / 2, h2 = glheight / 2;
  if(numTiles == 2) {
    gl.push_back(new openglWindow(twidth, mh, w2, glheight));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth + w2, mh, glwidth - w2, glheight));
    gl.back()->end();
  }
  else if(numTiles == 3) {
    gl.push_back(new openglWindow(twidth, mh, w2, glheight));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth + w2, mh, glwidth - w2, h2));
    gl.back()->end();
    gl.push_back(
      new openglWindow(twidth + w2, mh + h2, glwidth - w2, glheight - h2));
    gl.back()->end();
  }
  else if(numTiles == 4) {
    gl.push_back(new openglWindow(twidth, mh, w2, h2));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth + w2, mh, glwidth - w2, h2));
    gl.back()->end();
    gl.push_back(new openglWindow(twidth, mh + h2, w2, glheight - h2));
    gl.back()->end();
    gl.push_back(
      new openglWindow(twidth + w2, mh + h2, glwidth - w2, glheight - h2));
    gl.back()->end();
  }
  else {
    gl.push_back(new openglWindow(twidth, mh, glwidth, glheight));
    gl.back()->end();
  }

  int mode = openglWindowMode();
  for(std::size_t i = 0; i < gl.size(); i++) gl[i]->mode(mode);

  if(main) {
    _browser = new messageBrowser(twidth, mh + glheight, glwidth, mheight);
    int s = CTX::instance()->msgFontSize;
    _browser->textsize(s <= 0 ? FL_NORMAL_SIZE - 2 : s);
    _browser->callback(message_browser_cb, this);
    _browser->search_callback(message_menu_search_cb, this);
    _browser->autoscroll_callback(message_menu_autoscroll_cb, this);
    _browser->copy_callback(message_menu_copy_cb, this);
    _browser->save_callback(message_menu_save_cb, this);
    _browser->clear_callback(message_menu_clear_cb, this);
  }
  else {
    _browser = nullptr;
  }

  if(main && !detachedMenu) {
    _onelab = new onelabGroup(0, mh, twidth, height - mh - sh);
  }
  else {
    _onelab = nullptr;
  }

  // the edges are dragged within the resizable box: the tree and the messages
  // keep their least size, and are hidden when released well past it (see
  // tileReleased())
  {
    int minw = _onelab ? minMenuWidth() : 0;
    int minh = _browser ? minMessageHeight() : 0;
    dummyBox *drag =
      new dummyBox(minw, mh, _tile->w() - minw, _tile->h() - minh);
    _tile->insert(*drag, 0);
    _tile->resizable(drag);
  }
  _tile->callback(tile_cb);
  _tile->end();

  // the dock of the tool windows, shown while one is docked
  _dropping = nullptr;
  if(main) {
    _divider = new dockDivider(0, mh, 0, glheight + mheight);
    _divider->callback(dock_divider_cb, this);
    _divider->hide();
    _dock = new toolDock(0, mh, 0, glheight + mheight, BH);
    _dock->hide();
  }
  else {
    _divider = nullptr;
    _dock = nullptr;
  }

  // resize the tiles to match the prescribed sizes
  _tile->position(0, mh + glheight, 0, mh + CTX::instance()->glSize[1]);

  // the menu at least at its least width; a width of 0 means that the menu is
  // hidden: built at its least width, hidden at the end
  int minw = minMenuWidth();
  int mw = CTX::instance()->menuSize[0];
  bool hiddenMenu = (mw <= 0);
  if(mw < minw) mw = minw;
  if(!hiddenMenu) CTX::instance()->menuSize[0] = mw;
  _menuWidth = mw;
  _tile->position(twidth, 0, mw, 0);

  // bottom button bar
  _bottom = new Fl_Box(0, mh + glheight + mheight, width, sh);
  _bottom->box(GMSH_SIMPLE_TOP_BOX);

  int x = 2;
  int sht = sh - 4; // leave a 2 pixel border at the bottom
  const actionItem &bar = GetActionMenu("Status bar");
  for(std::size_t g = 0; g < bar.items.size(); g++) {
    if(g) x += 4; // the groups set apart
    for(const actionItem &item : bar.items[g].items) {
      if(!canRunItem(item)) continue;
      // (a label of several letters, "1:1", takes a wider button)
      bool wide = item.label.size() > 1;
      int bw = wide ? 2 * FL_NORMAL_SIZE : sw;
      Fl_Button *b = new Fl_Button(x, mh + glheight + mheight + 2, bw, sht);
      b->copy_label(item.label.c_str());
      b->callback(status_item_cb, (void *)&item);
      b->copy_tooltip(statusTooltip(item).c_str());
      b->box(FL_FLAT_BOX);
      b->selection_color(FL_BACKGROUND2_COLOR);
      b->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      if(item.icon.size()) gmshIcon(b, item.icon.c_str(), _iconSize);
      _statusButtons[item.name] = b;
      x += wide ? (int)(1.75 * FL_NORMAL_SIZE) : sw;
    }
  }
  x += 4;
  // (the animation buttons wait for views with time steps)
  checkAnimButtons();

  // the least width of the window is what the status bar buttons take, and
  // the part of the window that resizes starts after them, so that they stay
  // in place
  _minWidth = x;
  _minHeight = 100;
  _win->size_range(_minWidth, _minHeight);
  resbox->resize(_minWidth, mh, std::max(1, width - _minWidth), glheight);

  _label =
    new mainWindowProgress(x, mh + glheight + mheight + 2, width - x - 2, sht);
  _label->box(FL_FLAT_BOX);
  _label->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  if(CTX::instance()->guiDark)
    _label->color(FL_BACKGROUND_COLOR, FL_LIGHT3);
  else
    _label->color(FL_BACKGROUND_COLOR, FL_DARK2);
  // a saved width below the least one
  if(_win->w() < _minWidth) _win->size(_minWidth, _win->h());

  if(main) {
    // the other windows are placed relative to the main graphic window
    setReferenceWindow(_win);
    placeWindowAt(_win, CTX::instance()->glPosition[0],
                  CTX::instance()->glPosition[1]);
  }
  else {
    _win->position(CTX::instance()->glPosition[0],
                   CTX::instance()->glPosition[1]);
  }
  _win->end();

  if(main && detachedMenu) {
    _menuwin = new mainWindow(std::max(CTX::instance()->menuSize[0], minw),
                              CTX::instance()->menuSize[1],
                              CTX::instance()->nonModalWindows ? true : false,
                              "Gmsh", CTX::instance()->menuOffset);
    _menuwin->callback(quit_cb);
    _menuwin->box(GMSH_WINDOW_BOX);
    _onelab = new onelabGroup(0, 0, _menuwin->w(), _menuwin->h());
    _menuwin->resizable(_onelab);
    _menuwin->size_range(_onelab->getMinWindowWidth(),
                         _onelab->getMinWindowHeight());
    _menuwin->end();
  }
  else {
    _menuwin = nullptr;
  }

  if(main) setDocking(true);
  if(main && hiddenMenu) {
    hideMenu();
    _menuWidth = 0; // shown again at its default width (see showMenu())
  }
}

// a tool dropped on the dock, docked at the next event (see toolDock.cpp)
void dropped_cb(void *data);

graphicWindow::~graphicWindow()
{
  // the main window: a tool dropped on its dock, docked at the next event,
  // and the animation go with it, and the docked tool windows are not its to
  // delete
  if(_dock) {
    Fl::remove_timeout(dropped_cb);
    animPlaying = false;
    Fl::remove_timeout(animate_cb);
    Fl::remove_timeout(_drop_cb, this);
    _dock->undockAll(false);
    setDocking(false);
  }
  // (as on unsplit, see split())
  for(openglWindow *w : gl)
    if(sceneTool::scene() == w) sceneTool::stop();
  openglWindow::setLastHandled(nullptr);
  if(globalMenu && globalMenu == _menuBar()) {
    Fl::remove_handler(globalMenuHandler);
    globalMenu = nullptr;
  }
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

  _menuwin =
    new mainWindow(std::max(_onelab->w(), _onelab->getMinWindowWidth()),
                   CTX::instance()->menuSize[1],
                   CTX::instance()->nonModalWindows ? true : false, "Gmsh",
                   CTX::instance()->menuOffset);
  _menuwin->callback(quit_cb);
  _menuwin->box(GMSH_WINDOW_BOX);
  _onelab->box(FL_FLAT_BOX);
  _menuwin->add(_onelab);
  _onelab->resize(0, 0, _menuwin->w(), _menuwin->h());
  _menuwin->resizable(_onelab);
  _menuwin->size_range(_onelab->getMinWindowWidth(),
                       _onelab->getMinWindowHeight());
  _menuwin->end();
  _menuwin->show();

  _onelab->rebuildTree();
}

void graphicWindow::attachMenu()
{
  if(!_menuwin || !_onelab || !_browser) return;
  CTX::instance()->menuSize[1] = _menuwin->h();
  storeWindowOffset(_menuwin, CTX::instance()->menuOffset);
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

  _onelab->rebuildTree();
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
    // the width set, or the one the menu had when it was hidden
    int width = CTX::instance()->menuSize[0];
    if(width < FL_NORMAL_SIZE) width = _menuWidth;
    if(width < FL_NORMAL_SIZE) width = _onelab->getMinWindowWidth();
    int maxw = _tile->w(); // without the dock
    if(width > maxw) width = maxw / 2;
    setMenuWidth(width);
    CTX::instance()->menuSize[0] = width;
    // necessary until resizing of 0-sized groups works
    _onelab->rebuildTree();
  }
}

void graphicWindow::hideMenu()
{
  if(_menuwin || !_onelab) return;
  // hidden, the menu has no width (saved as such); the width it had is kept
  // to show it again
  if(_onelab->w() > 0) _menuWidth = _onelab->w();
  CTX::instance()->menuSize[0] = 0;
  setMenuWidth(0);
}

void graphicWindow::tilePushed()
{
  _pushX = Fl::event_x();
  _pushY = Fl::event_y();
  _pushMenuWidth = getMenuWidth();
  _pushMessageHeight = getMessageHeight();
}

// an edge of the tiles released: a menu or messages dragged well past their
// least size, towards the border of the tile, are hidden as their toggles
// hide them, and the toggles show them again at the size they had before the
// drag
void graphicWindow::tileReleased()
{
  int mx = Fl::event_x(), my = Fl::event_y();
  const int grab = 5; // the grab area of Fl_Tile, and a pixel
  int minw = minMenuWidth(), minh = minMessageHeight();
  // a menu or messages shown when pressed (else Fl_Tile may take a press at
  // the border for their edge)
  if(_onelab && !_menuwin && _pushMenuWidth >= FL_NORMAL_SIZE &&
     _onelab->w() <= minw &&
     std::abs(_pushX - (_onelab->x() + _pushMenuWidth)) <= grab &&
     mx < _onelab->x() + minw / 2) {
    hideMenu();
    _menuWidth = (_pushMenuWidth > minw) ? _pushMenuWidth : 0;
  }
  if(_browser && _pushMessageHeight >= FL_NORMAL_SIZE &&
     _browser->h() <= minh) {
    int bottom = _browser->y() + _browser->h();
    if(std::abs(_pushY - (bottom - _pushMessageHeight)) <= grab &&
       my > bottom - minh / 2) {
      hideMessages();
      CTX::instance()->msgSize =
        (_pushMessageHeight > minh) ? _pushMessageHeight : 0;
    }
  }
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

bool graphicWindow::split(openglWindow *g, char how, double ratio)
{
  if(_tile->find(g) == _tile->children()) return false; // not found

  if(how == 'u') {
    // after many tries I cannot figure out how to do this cleanly, so let's be
    // brutal :-)
    int mode = g->mode();
    // the tool on one of the panes ends while they are all there (its end
    // may draw them, or say so in the current one)
    for(openglWindow *w : gl)
      if(sceneTool::scene() == w) sceneTool::stop();
    openglWindow::setLastHandled(nullptr);
    // hidden first, all of them whole: hiding moves the focus, which may
    // commit an edited value whose callback draws every pane
    for(std::size_t i = 0; i < gl.size(); i++) gl[i]->hide();
    for(std::size_t i = 0; i < gl.size(); i++) {
      _tile->remove(gl[i]);
      delete gl[i];
    }
    gl.clear();
    openglWindow *g2 = new openglWindow(
      _tile->x() + (_onelab && !_menuwin ? _onelab->w() : 0), _tile->y(),
      _tile->w() - (_onelab && !_menuwin ? _onelab->w() : 0),
      _tile->h() - (_browser ? _browser->h() : 0));
    g2->end();
    g2->mode(mode);
    gl.push_back(g2);
    _tile->add(g2);
    g2->show();
    openglWindow::setLastHandled(g2);
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
    openglWindow *g2 = new openglWindow(x2, y2, w2, h2);
    g2->end();
    g2->mode(g->mode());
    gl.push_back(g2);
    _tile->add(g2);
    g2->show();
    openglWindow::setLastHandled(g2);
  }
  return true;
}

void graphicWindow::setAnimButtons(bool playing)
{
  Fl_Button *b = statusButton("anim_play");
  if(b) gmshIcon(b, playing ? "pause" : "play", _iconSize);
}

void graphicWindow::checkAnimButtons()
{
  bool play = false;
  if(CTX::instance()->post.animCycle) { play = true; }
  else {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(PView::list[i]->getData()->getNumTimeSteps() > 1) {
        play = true;
        break;
      }
    }
  }
  for(const char *name :
      {"anim_rewind", "time_step_prev", "anim_play", "time_step_next"}) {
    Fl_Button *b = statusButton(name);
    if(!b) continue;
    if(play)
      b->activate();
    else
      b->deactivate();
  }
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

// the width of the window, the dock taking its room from the graphics, as the
// tree does, so that the size saved at exit does not depend on the tools open
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
  Msg::ResetErrorCounter();
  if(_browser->h() < FL_NORMAL_SIZE) {
    int height = CTX::instance()->msgSize;
    if(height < FL_NORMAL_SIZE) height = 10 * FL_NORMAL_SIZE;
    int maxh = _win->h() - _bottom->h();
    if(height > maxh) height = maxh / 2;
    setMessageHeight(height);
  }
  if(_autoScrollMessages) _browser->scrollToEnd();
}

void graphicWindow::hideMessages()
{
  if(!_browser) return;
  CTX::instance()->msgSize = _browser->h();
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

// on the GUI's thread only: the other threads' lines are queued for it by
// FlGui::addMessage()
void graphicWindow::addMessage(const char *msg)
{
  if(!_browser) return;
  // the console keeps the last 50000 messages: beyond, the oldest tenth goes
  const std::size_t maxMessages = 50000;
  if(_messages.size() >= maxMessages) {
    _messages.erase(_messages.begin(), _messages.begin() + maxMessages / 10);
    _browser->removeFirst(maxMessages / 10);
  }
  _messages.push_back(msg);
  _browser->add(msg);
  if(_autoScrollMessages && _win->shown() && _browser->h() >= FL_NORMAL_SIZE)
    _browser->scrollToEnd();
}

void graphicWindow::clearMessages()
{
  _messages.clear();
  if(!_browser) return;
  _browser->clear();
}

// a line of the console without its colour: the codes FLTK reads at its start,
// up to "@." (e.g. "@C1@." or, in dark mode, "@B152@.")
static const char *withoutFormat(const char *c)
{
  if(c[0] != '@') return c;
  const char *end = strstr(c, "@.");
  return end ? end + 2 : c;
}

void graphicWindow::saveMessages(const char *filename)
{
  if(!_browser) return;

  FILE *fp = Fopen(filename, "w");

  if(!fp) {
    Msg::Error("Unable to open file '%s'", filename);
    return;
  }

  Msg::StatusBar(true, "Writing '%s'...", filename);
  for(int i = 1; i <= _browser->size(); i++) {
    fprintf(fp, "%s\n", withoutFormat(_browser->text(i)));
  }
  Msg::StatusBar(true, "Done writing '%s'", filename);
  fclose(fp);
}

void graphicWindow::copySelectedMessagesToClipboard()
{
  if(!_browser) return;

  // the lines selected, or all of them
  bool any = false;
  for(int i = 1; i <= _browser->size(); i++)
    if(_browser->selected(i)) any = true;
  std::string buff;
  for(int i = 1; i <= _browser->size(); i++) {
    if(!any || _browser->selected(i)) {
      buff += std::string(withoutFormat(_browser->text(i))) + "\n";
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

void graphicWindow::fillRecentHistoryMenu()
{
  Fl_Menu_ *m = _menuBar();
  if(!m) return;
  int i = m->find_index("File/Open Recent");
  if(i >= 0) {
    m->clear_submenu(i);
    addRecentFiles(m, "File/Open Recent");
  }
#if defined(__APPLE__)
  // the system menu bar is made from the items only when asked: its add(),
  // mode()... are not virtual, and those of Fl_Menu_ are the ones called here
  // and when the menu is built
  if(_sysbar) _sysbar->update();
#endif
}
