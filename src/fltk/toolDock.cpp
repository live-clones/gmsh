// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdlib>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include "paletteWindow.h"
#include "toolDock.h"
#include "FlGui.h" // for WB
#include "gmshScheme.h"
#include "graphicWindow.h"
#include "onelabGroup.h"
#include "Context.h"

void dragGhost::follow(const char *label, int rowHeight, int xroot, int yroot)
{
  _label = label ? label : "";
  fl_font(FL_HELVETICA_BOLD, FL_NORMAL_SIZE);
  int w = 0, h = 0;
  fl_measure(_label.c_str(), w, h, 0);
  w += 2 * WB;
  // under the pointer, as the title bar of the window will be
  resize(xroot - w / 2, yroot - rowHeight / 2, w, rowHeight);
  if(!shown()) show();
  redraw();
}

void dragGhost::draw()
{
  // from the origin: x() and y() of a window are its place on the screen
  fl_draw_box(FL_THIN_UP_BOX, 0, 0, w(), h(), FL_BACKGROUND_COLOR);
  fl_font(FL_HELVETICA_BOLD, FL_NORMAL_SIZE);
  fl_color(FL_FOREGROUND_COLOR);
  fl_draw(_label.c_str(), 0, 0, w(), h(), FL_ALIGN_CENTER);
}

void dockTitle::draw()
{
  // as the folding sections of the option window, with the close cross of
  // the tabs
  draw_box(FL_THIN_UP_BOX, hoverHighlight(this, FL_BACKGROUND_COLOR));
  std::string l =
    std::string(shut ? "@-2> " : "@-22> ") + (win->label() ? win->label() : "");
  fl_font(FL_HELVETICA_BOLD, FL_NORMAL_SIZE);
  fl_color(FL_FOREGROUND_COLOR);
  fl_draw(l.c_str(), x() + 5, y(), w() - h() - 5, h(),
          FL_ALIGN_LEFT | FL_ALIGN_CLIP);
  int s = FL_NORMAL_SIZE / 2;
  fl_draw_symbol("@3+", x() + w() - (h() + s) / 2, y() + (h() - s) / 2, s, s,
                 FL_FOREGROUND_COLOR);
}

int dockTitle::handle(int event)
{
  toolDock *dock = (toolDock *)parent();
  switch(event) {
  case FL_ENTER:
  case FL_LEAVE: redraw(); return 1; // highlighted under the pointer
  case FL_PUSH:
    _pushX = Fl::event_x();
    _pushY = Fl::event_y();
    _dragging = false;
    return 1;
  case FL_DRAG:
    if(!_dragging &&
       dock->dragged(_pushX, _pushY, Fl::event_x(), Fl::event_y())) {
      _dragging = true;
      window()->cursor(FL_CURSOR_MOVE);
    }
    if(_dragging) {
      // read before the chip moves: moving a window lets the system report
      // the pointer, which overwrites the event
      int ex = Fl::event_x(), ey = Fl::event_y();
      dock->dragging(win, Fl::event_x_root(), Fl::event_y_root());
      dock->stackTarget(ex, ey);
    }
    return 1;
  case FL_RELEASE:
    if(_dragging) {
      _dragging = false;
      window()->cursor(FL_CURSOR_DEFAULT);
      if(dock->outside(Fl::event_x(), Fl::event_y())) {
        dock->dragEnded(win, Fl::event_x_root(), Fl::event_y_root(), true);
      }
      else {
        dock->dropInStack(this);
        dock->dragEnded(win, 0, 0, false);
      }
      return 1;
    }
    if(!Fl::event_inside(this)) return 1;
    if(Fl::event_x() >= x() + w() - h())
      win->do_callback(); // as the close button of the window
    else
      dock->fold(this, !shut);
    return 1;
  }
  return Fl_Widget::handle(event);
}

int dockTabs::handle(int event)
{
  toolDock *dock = (toolDock *)parent();
  switch(event) {
  case FL_PUSH:
    _pressed = which(Fl::event_x(), Fl::event_y());
    _pushX = Fl::event_x();
    _pushY = Fl::event_y();
    _dragging = false;
    break;
  case FL_DRAG:
    if(_pressed && !_dragging &&
       dock->dragged(_pushX, _pushY, Fl::event_x(), Fl::event_y())) {
      _dragging = true;
      push(nullptr); // the tab is no longer being chosen
      window()->cursor(FL_CURSOR_MOVE);
    }
    if(_dragging) {
      // read before the chip moves (see dockTitle::handle())
      int at = _indexAt(Fl::event_x(), Fl::event_y());
      dock->dragging(((dockTab *)_pressed)->win, Fl::event_x_root(),
                     Fl::event_y_root());
      if(at != _dropAt) {
        _dropAt = at;
        redraw();
      }
      return 1;
    }
    break;
  case FL_RELEASE:
    if(_dragging) {
      _dragging = false;
      window()->cursor(FL_CURSOR_DEFAULT);
      Fl_Widget *t = _pressed;
      paletteWindow *pw = ((dockTab *)t)->win;
      _pressed = nullptr;
      if(dock->outside(Fl::event_x(), Fl::event_y())) {
        _dropAt = -1;
        dock->dragEnded(pw, Fl::event_x_root(), Fl::event_y_root(), true);
        return 1;
      }
      // put down where it was dragged along the row, and chosen: the dock
      // shows its window from the callback
      if(_dropAt >= 0) insert(*t, _dropAt);
      _dropAt = -1;
      if(value(t)) do_callback();
      redraw();
      dock->dragEnded(pw, 0, 0, false);
      return 1;
    }
    _pressed = nullptr;
    break;
  }
  return Fl_Tabs::handle(event);
}

int dockTabs::_indexAt(int x, int y)
{
  // the place in the row a tab dropped at (x, y) takes: before the tab whose
  // middle is after x, else at the end
  int nc = children();
  if(!nc || y < this->y() || y >= this->y() + tab_height()) return -1;
  tab_positions();
  for(int i = 0; i < nc; i++)
    if(x < this->x() + tab_offset + (tab_pos[i] + tab_pos[i + 1]) / 2) return i;
  return nc;
}

void dockTabs::draw()
{
  Fl_Tabs::draw();
  if(_dropAt < 0) return;
  // the marker of the place, a bar between the tabs
  tab_positions();
  int xx = x() + tab_offset + tab_pos[_dropAt];
  fl_color(gmshAccent());
  fl_rectf(xx - 1, y() + 2, 3, tab_height() - 2);
}

toolDock::toolDock(int x, int y, int w, int h, int rowHeight)
  : Fl_Group(x, y, w, h), _rowHeight(rowHeight), _ghost(nullptr),
    _dropHint(false), _dropAt(-1), _clock(0), _layingOut(false),
    _requested(nullptr)
{
  // FLTK 1.5 tabs draw their row with the box of their parent: without one, a
  // closed tab stays drawn
  box(FL_FLAT_BOX);
  _tabs = new dockTabs(x, y, w, h);
  _tabs->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
  _tabs->when(FL_WHEN_CHANGED);
  _tabs->callback(_tabs_cb, this);
  _tabs->end();
  _tabs->hide();
  end();
}

// the ghost of a drag is a window of its own
toolDock::~toolDock() { delete _ghost; }

// the label of a tab: FLTK draws the close cross right before it, so it
// starts with a space
static std::string tabLabel(paletteWindow *pw)
{ return std::string(" ") + (pw->label() ? pw->label() : ""); }

dockTab *toolDock::_tabOf(paletteWindow *pw)
{
  for(int i = 0; i < _tabs->children(); i++) {
    dockTab *t = (dockTab *)_tabs->child(i);
    if(t->win == pw) return t;
  }
  return nullptr;
}

dockTitle *toolDock::_titleOf(paletteWindow *pw)
{
  for(dockTitle *t : _stack)
    if(t->win == pw) return t;
  return nullptr;
}

bool toolDock::_place(paletteWindow *pw)
{
  // inside the frame of the tabs, under their row, if there is room for the
  // least size of the window: smaller, its layout would be lost, and a
  // subwindow is not clipped by the main window on macOS
  Fl_Boxtype b = _tabs->box();
  int w = _tabs->w() - Fl::box_dw(b);
  int h = _tabs->h() - _rowHeight - Fl::box_dh(b);
  if(w < pw->leastWidth() || h < pw->leastHeight()) return false;
  pw->resize(_tabs->x() + Fl::box_dx(b),
             _tabs->y() + _rowHeight + Fl::box_dy(b), w, h);
  pw->keepPosition();
  return true;
}

void toolDock::_showCurrent()
{
  // the window of the tab shown, the others hidden
  bool old = _layingOut;
  _layingOut = true; // the resizes are ours
  Fl_Widget *v = _tabs->value();
  paletteWindow *shown = nullptr;
  for(int i = 0; i < _tabs->children(); i++) {
    dockTab *t = (dockTab *)_tabs->child(i);
    if(t == v)
      shown = t->win;
    else if(t->win->visible())
      t->win->Fl_Double_Window::hide();
  }
  // hidden while there is no room for it
  if(shown && _place(shown))
    _show(shown);
  else if(shown && shown->visible())
    shown->Fl_Double_Window::hide();
  _layingOut = old;
}

void toolDock::_layout()
{
  // the stacked windows on top, the tabs below in the height left; when room
  // lacks, the stacked windows used least recently are shut (until there is
  // room again), the window used last keeping its room
  bool old = _layingOut;
  _layingOut = true;
  int X = x(), W = w(), H = h(), th = _rowHeight;
  int tabsMin = 0;
  unsigned long tabUsed = 0;
  if(dockTab *v = (dockTab *)_tabs->value()) {
    tabUsed = _used[v->win];
    bool last = true;
    for(dockTitle *t : _stack)
      if(_used[t->win] > tabUsed) last = false;
    tabsMin = v->win->leastHeight() + _rowHeight + Fl::box_dh(_tabs->box());
    tabsMin = std::min(tabsMin, last ? H : H / 2);
  }
  for(dockTitle *t : _stack) t->shut = t->folded;
  while(true) {
    int sh = 0, open = 0;
    dockTitle *oldest = nullptr;
    for(dockTitle *t : _stack) {
      sh += th + (t->shut ? 0 : t->win->h());
      if(t->shut) continue;
      open++;
      if(!oldest || _used[t->win] < _used[oldest->win]) oldest = t;
    }
    if(sh <= H - tabsMin || !oldest) break;
    // the one left, if used last, folds only if it does not fit at all
    if(open == 1 && _used[oldest->win] > tabUsed && sh <= H) break;
    oldest->shut = true;
  }

  int yy = y();
  for(dockTitle *t : _stack) {
    t->resize(X, yy, W, th);
    t->redraw();
    yy += th;
    paletteWindow *pw = t->win;
    if(t->shut) {
      if(pw->visible()) pw->Fl_Double_Window::hide();
      continue;
    }
    pw->resize(X, yy, W, pw->h());
    pw->keepPosition();
    _show(pw);
    yy += pw->h();
  }
  // the tabs in the height left, if there is room for their row at least:
  // the main window is sometimes shorter than the titles alone
  int ht = y() + H - yy;
  if(_tabs->children() && ht >= 2 * _rowHeight) {
    _tabs->Fl_Widget::resize(X, yy, W, ht);
    for(int i = 0; i < _tabs->children(); i++)
      _tabs->child(i)->resize(X, yy + _rowHeight, W, ht - _rowHeight);
    // the row starts from its first tab again: FLTK scrolls it to keep the
    // tab chosen in view, from the width the tabs had then (0 before their
    // first layout), and never scrolls back
    _tabs->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
    if(Fl_Widget *v = _tabs->value()) _tabs->value(v);
    _tabs->show();
    _showCurrent();
  }
  else {
    _tabs->hide();
    for(int i = 0; i < _tabs->children(); i++) {
      paletteWindow *pw = ((dockTab *)_tabs->child(i))->win;
      if(pw->visible()) pw->Fl_Double_Window::hide();
    }
  }
  redraw();
  _layingOut = old;
}

void toolDock::_tabs_cb(Fl_Widget *w, void *data)
{
  toolDock *d = (toolDock *)data;
  if(dockTab *t = (dockTab *)d->_tabs->value()) d->_use(t->win);
  d->_layout(); // the tab used last may fold stacked windows
}

void toolDock::_close_cb(Fl_Widget *w, void *data)
{
  // the close button of a tab acts as the one of the window
  ((dockTab *)w)->win->do_callback();
}

paletteWindow *toolDock::current()
{
  paletteWindow *last = nullptr;
  for(auto &u : _used)
    if(u.first->visible() && (!last || u.second > _used[last])) last = u.first;
  return last;
}

bool toolDock::closeCurrent()
{
  paletteWindow *last = current();
  if(!last) return false;
  last->do_callback();
  return true;
}

void toolDock::_show(paletteWindow *pw)
{
  // shown again but not by its tool: it may need a refresh
  bool again = !pw->visible() && pw != _requested;
  pw->Fl_Double_Window::show();
  if(again) pw->revealed();
}

void toolDock::dock(paletteWindow *pw)
{
  _use(pw);
  _requested = pw;
  if(dockTitle *t = _titleOf(pw)) {
    t->folded = false; // shown again: open, where it is in the stack
  }
  else if(dockTab *t = _tabOf(pw)) {
    t->copy_label(tabLabel(pw).c_str()); // some windows change their label
    _tabs->value(t);
  }
  else {
    // a window of the desktop becomes a subwindow
    pw->leaveDesktop();
    if(pw->shown()) pw->Fl_Double_Window::hide();
    Fl_Group *current = Fl_Group::current();
    Fl_Group::current(nullptr);
    if(pw->fixedHeight()) {
      dockTitle *t = new dockTitle(x(), y(), w(), _rowHeight, pw);
      add(t);
      _stack.insert(_stack.begin(), t);
    }
    else {
      dockTab *t = new dockTab(x(), y(), w(), h(), pw);
      // a close button on the tab
      t->when(FL_WHEN_CLOSED);
      t->callback(_close_cb);
      t->copy_label(tabLabel(pw).c_str());
      t->labelfont(FL_BOLD); // as the titles of the stacked windows
      _tabs->add(t);
      _tabs->value(t);
    }
    Fl_Group::current(current);
    add(pw);
  }
  _layout();
  _tabs->redraw();
  _requested = nullptr;
}

void toolDock::hidden(paletteWindow *pw)
{
  // closed: the window and its tab or title leave the dock, the tab or title
  // deleted later, as we may be in its callback
  pw->Fl_Double_Window::hide();
  if(dockTab *t = _tabOf(pw)) {
    _tabs->remove(t);
    Fl::delete_widget(t);
  }
  else if(dockTitle *t = _titleOf(pw)) {
    _stack.erase(std::find(_stack.begin(), _stack.end(), t));
    remove(t);
    Fl::delete_widget(t);
  }
  remove(pw);
  pw->backToDesktop();
  _used.erase(pw);
  _layout();
}

void toolDock::resized(paletteWindow *pw)
{
  // a stacked window changes its height itself; the one shown in the tabs is
  // placed again, or hidden if it no longer fits (it can grow taller)
  if(_layingOut) return;
  if(_titleOf(pw))
    _layout();
  else if(dockTab *t = _tabOf(pw))
    if(t == _tabs->value()) _showCurrent();
}

void toolDock::fold(dockTitle *t, bool folded)
{
  t->folded = folded;
  if(!folded) _use(t->win);
  _layout();
}

void toolDock::undockAll(bool show)
{
  // the tabs in order, then the stack from the bottom: docked again in this
  // order, each stacked window going on top, they come back as they were
  std::vector<paletteWindow *> all;
  for(int i = 0; i < _tabs->children(); i++)
    all.push_back(((dockTab *)_tabs->child(i))->win);
  for(auto t = _stack.rbegin(); t != _stack.rend(); ++t)
    all.push_back((*t)->win);
  for(paletteWindow *pw : all) hidden(pw);
  if(show)
    for(paletteWindow *pw : all) pw->show(); // where it was placed last
}

void toolDock::resize(int x, int y, int w, int h)
{
  // the windows are placed here, not scaled
  Fl_Widget::resize(x, y, w, h);
  _layout();
}

bool toolDock::dragged(int fromX, int fromY, int x, int y) const
{
  // a few pixels: a click wobbles less
  return abs(x - fromX) > 4 || abs(y - fromY) > 4;
}

bool toolDock::outside(int x, int y) const
{
  return x < this->x() || x >= this->x() + w() || y < this->y() ||
         y >= this->y() + h();
}

void toolDock::dragging(paletteWindow *pw, int x, int y)
{
  if(!_ghost) {
    Fl_Group *current = Fl_Group::current();
    Fl_Group::current(nullptr);
    _ghost = new dragGhost();
    Fl_Group::current(current);
  }
  _ghost->follow(pw->label(), _rowHeight, x, y);
}

int toolDock::_stackIndexAt(int y) const
{
  // the place in the stack a title dropped at y takes: before the stacked
  // window whose middle is below y, else at the end
  for(std::size_t i = 0; i < _stack.size(); i++) {
    dockTitle *t = _stack[i];
    int hh = t->h() + (t->shut ? 0 : t->win->h());
    if(y < t->y() + hh / 2) return (int)i;
  }
  return (int)_stack.size();
}

void toolDock::stackTarget(int x, int y)
{
  int at = outside(x, y) ? -1 : _stackIndexAt(y);
  if(at == _dropAt) return;
  _dropAt = at;
  redraw();
}

void toolDock::dropInStack(dockTitle *t)
{
  if(_dropAt < 0) return;
  auto it = std::find(_stack.begin(), _stack.end(), t);
  int from = (int)(it - _stack.begin()), to = _dropAt;
  _dropAt = -1;
  _stack.erase(it);
  if(to > from) to--;
  _stack.insert(_stack.begin() + to, t);
  _layout();
}

void toolDock::dragEnded(paletteWindow *pw, int x, int y, bool tearOut)
{
  if(_ghost) _ghost->hide();
  if(_dropAt >= 0) {
    _dropAt = -1;
    redraw();
  }
  if(!tearOut) return;
  pw->floating(true);
  hidden(pw);
  if(paletteWindow::host) paletteWindow::host->toolTornOut(pw, x, y);
}

void toolDock::dropHint(bool on)
{
  if(on == _dropHint) return;
  _dropHint = on;
  redraw();
}

void toolDock::draw()
{
  // the target of a window dragged over the dock is said by the divider,
  // which the docked windows never cover, and by a highlight of the column
  // while it is empty
  if(_dropHint && empty()) {
    fl_color(fl_color_average(gmshAccent(), FL_BACKGROUND_COLOR, 0.2));
    fl_rectf(x(), y(), w(), h());
    return;
  }
  Fl_Group::draw();
  if(_dropAt < 0) return;
  // the marker of the place a dragged title would take: a bar on the top
  // edge of the stacked window it would go before, or under the last
  int yy = y();
  if(_dropAt < (int)_stack.size())
    yy = _stack[_dropAt]->y();
  else if(!_stack.empty()) {
    dockTitle *t = _stack.back();
    yy = t->y() + t->h() + (t->shut ? 0 : t->win->h());
  }
  fl_color(gmshAccent());
  fl_rectf(x(), yy - 1, w(), 3);
}

int dockDivider::handle(int event)
{
  switch(event) {
  case FL_ENTER: window()->cursor(FL_CURSOR_WE); return 1;
  case FL_LEAVE: window()->cursor(FL_CURSOR_DEFAULT); return 1;
  case FL_PUSH: return 1;
  case FL_DRAG:
  case FL_RELEASE: do_callback(); return 1;
  }
  return Fl_Box::handle(event);
}

void dockDivider::draw()
{
  fl_color(color());
  fl_rectf(x(), y(), w(), h());
  fl_color(FL_DARK2);
  fl_line(x(), y(), x(), y() + h());
  // the target of a window dragged over the dock: its edge lights up, as
  // wide as the marker between the tabs
  if(highlight) {
    fl_color(gmshAccent());
    fl_rectf(x() + w() - 3, y(), 3, h());
  }
}

// The docking of the tool windows in the main window (graphicWindow), which
// the tool windows reach as their dockHost (paletteWindow::host)

bool graphicWindow::closeTool(Fl_Window *w)
{
  // Cmd-W in the main window closes the tool shown in the dock, if any
  return getWindow() == w && closeDockedTool();
}

bool graphicWindow::isDockShown() { return _dock && _dock->visible(); }

// the least width of the tool windows, in the frame of the dock tabs
static int leastDockWidth() { return TW + Fl::box_dw(FL_THIN_UP_BOX); }

int graphicWindow::getDockWidth()
{ return std::max(CTX::instance()->dockWidth, leastDockWidth()); }

int graphicWindow::_leastTileWidth()
{
  // the tree, and some room for the graphics
  int tw = (_onelab && !_menuwin) ? _onelab->w() : 0;
  return std::max(_minWidth, tw + BB);
}

int graphicWindow::_fitDockWidth(int w)
{
  w = std::min(w, _win->w() - WB - _leastTileWidth());
  return std::max(w, leastDockWidth());
}

void graphicWindow::setDockWidth(int w)
{
  if(!isDockShown()) return;
  w = _fitDockWidth(w);
  CTX::instance()->dockWidth = w;
  _layoutDock(w);
}

void graphicWindow::setDocking(bool docking)
{
  if(!_dock) return;
  if(docking) {
    paletteWindow::host = this;
    // the tool windows open on the desktop join the dock, in the order they
    // were shown (the list of FLTK starts with the newest)
    std::vector<paletteWindow *> open;
    for(Fl_Window *w = Fl::first_window(); w; w = Fl::next_window(w)) {
      paletteWindow *p = dynamic_cast<paletteWindow *>(w);
      if(p && p->dockable() && !p->parent()) open.push_back(p);
    }
    std::reverse(open.begin(), open.end());
    for(auto p : open) p->show();
  }
  else {
    // the windows let go are shown on the desktop, not docked again
    _undocking = true;
    _dock->undockAll();
    _undocking = false;
    paletteWindow::dragged = nullptr;
    if(paletteWindow::host == this) paletteWindow::host = nullptr;
    _layoutDock(0);
  }
}

void graphicWindow::toolTornOut(paletteWindow *w, int x, int y)
{
  if(_dock->empty()) _layoutDock(0);
  // the title bar under the pointer, which held the tab or the title
  placeWindowAt(w, x - w->w() / 2, y + BH / 2);
  w->show();
  FlGui::instance()->storeFloatingTools();
}

bool graphicWindow::_overDock(paletteWindow *w)
{
  // Wayland hides where the windows are on the screen: there a tool is docked
  // by dragging a tab or its background, not its title bar (see toolDrop())
  if(!screenPositionsKnown()) return false;
  // the middle of the title bar of the tool over the dock, or over where the
  // dock would be while none is docked: the right of the tiles
  int th = w->decorated_h() - w->h();
  int cx = w->x() + w->w() / 2, cy = w->y() - th / 2;
  int X = _win->x() + _win->w() - getDockWidth(), W = getDockWidth();
  if(isDockShown()) {
    X = _win->x() + _dock->x();
    W = _dock->w();
  }
  int Y = _win->y() + _tile->y(), H = _tile->h();
  return cx >= X && cx < X + W && cy >= Y && cy < Y + H;
}

void graphicWindow::toolMoved(paletteWindow *w)
{
  if(!w->shown() || !_win->shown()) return;
  if(_overDock(w)) {
    if(_dropping != w) {
      _dropping = w;
      _dropTarget(true);
      // docked when the button is released: the system is asked for it
      Fl::add_timeout(0.05, _drop_cb, this);
    }
  }
  else if(_dropping == w) {
    Fl::remove_timeout(_drop_cb, this);
    _dropping = nullptr;
    _dropTarget(false);
  }
}

void graphicWindow::_dropTarget(bool on)
{
  // the dock as the target of a drop, shown empty while none is docked
  if(on && !isDockShown()) _layoutDock(_fitDockWidth(getDockWidth()));
  _dropHint(on);
  if(!on && _dock->empty()) _layoutDock(0);
}

void graphicWindow::_dropHint(bool on)
{
  _dock->dropHint(on);
  if(on == _divider->highlight) return;
  _divider->highlight = on;
  _divider->redraw();
}

// a tool dropped on the dock: docked, and no longer floating
void dropped_cb(void *data)
{
  paletteWindow *w = (paletteWindow *)data;
  w->floating(false);
  w->show(); // docks it
  FlGui::instance()->storeFloatingTools();
}

void graphicWindow::_drop_cb(void *data)
{
  graphicWindow *g = (graphicWindow *)data;
  paletteWindow *w = g->_dropping;
  if(!w) return;
  // Shift held keeps the tool out of the dock, to leave it over the dock
  // (Alt would tile the window on macOS): no hint while it is
  bool shift = shiftKeyDown();
  g->_dropHint(!shift);
  int down = mouseButtonDown();
  if(down == 1) {
    Fl::repeat_timeout(0.05, _drop_cb, data);
    return;
  }
  g->_dropping = nullptr;
  g->_dropTarget(false);
  // kept out when Shift is held, or where the system cannot say
  if(shift || down == -1) return;
  dropped_cb(w);
}

void graphicWindow::dragToDock(paletteWindow *w)
{
  // an FLTK drag and drop of the label of the tool, which the system shows
  // along the pointer; the drop lands in toolDrop()
  const char *label = w->label() ? w->label() : "";
  paletteWindow::dragged = w;
  Fl::copy(label, strlen(label), 0);
  Fl::dnd();
}

int graphicWindow::toolDrop(int event)
{
  paletteWindow *w = paletteWindow::dragged;
  switch(event) {
  case FL_DND_ENTER:
  case FL_DND_DRAG: {
    // over the dock, or where it would be while none is docked: the right of
    // the tiles
    int X = isDockShown() ? _dock->x() : _win->w() - getDockWidth();
    bool over = Fl::event_x() >= X && Fl::event_y() >= _tile->y() &&
                Fl::event_y() < _tile->y() + _tile->h();
    _dropTarget(over);
    // the release and the text dropped go to the widget below the mouse
    if(over) Fl::belowmouse(_win);
    return over;
  }
  case FL_DND_LEAVE: _dropTarget(false); return 1;
  case FL_DND_RELEASE: return _dock->dropHint();
  case FL_PASTE:
    paletteWindow::dragged = nullptr;
    _dropTarget(false);
    // ours, by its text; docked once the drag is over
    if(w->label() && Fl::event_text() && !strcmp(Fl::event_text(), w->label()))
      Fl::add_timeout(0., dropped_cb, w);
    return 1;
  }
  return 0;
}

void graphicWindow::toolResized(paletteWindow *w) { _dock->resized(w); }

paletteWindow *graphicWindow::currentDockedTool()
{ return isDockShown() ? _dock->current() : nullptr; }

bool graphicWindow::closeDockedTool()
{ return isDockShown() && _dock->closeCurrent(); }

void graphicWindow::dockTool(paletteWindow *w)
{
  if(!isDockShown()) {
    // the window widened if the graphics would get narrower than their least,
    // within the screen
    int need = _leastTileWidth() + getDockWidth() + WB;
    if(_win->w() < need) {
      int sx, sy, sw, sh;
      windowWorkArea(_win, sx, sy, sw, sh);
      _win->size(std::min(need, sw), _win->h());
    }
    _layoutDock(_fitDockWidth(getDockWidth()));
  }
  _dock->dock(w);
}

void graphicWindow::toolHidden(paletteWindow *w)
{
  _dock->hidden(w);
  if(_dock->empty()) _layoutDock(0);
}

void graphicWindow::_layoutDock(int width)
{
  // the tiles take what the dock leaves
  int ww = _win->w(), y = _tile->y(), h = _tile->h();
  int dw = width ? width + WB : 0;
  _tile->resize(0, y, ww - dw, h);
  if(width) {
    _divider->resize(ww - dw, y, WB, h);
    _divider->show();
    _dock->resize(ww - width, y, width, h);
    _dock->show();
  }
  else {
    _divider->hide();
    _dock->hide();
  }
  // the dock keeps its width when the window is resized, and the window keeps
  // room for it
  _win->size_range((width ? _leastTileWidth() : _minWidth) + dw, _minHeight);
  _resbox->resize(_minWidth, _resbox->y(), std::max(1, ww - dw - _minWidth),
                  _resbox->h());
  _win->init_sizes();
  _win->redraw();
}
