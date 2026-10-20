// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include "paletteWindow.h"
#include "toolDock.h"

void dockTitle::draw()
{
  // as the folding sections of the option window, with the close cross of
  // the tabs
  draw_box(FL_THIN_UP_BOX, FL_BACKGROUND_COLOR);
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
  switch(event) {
  case FL_PUSH: return 1;
  case FL_RELEASE:
    if(!Fl::event_inside(this)) return 1;
    if(Fl::event_x() >= x() + w() - h())
      win->do_callback(); // as the close button of the window
    else
      ((toolDock *)parent())->fold(this, !shut);
    return 1;
  }
  return Fl_Widget::handle(event);
}

toolDock::toolDock(int x, int y, int w, int h, int rowHeight)
  : Fl_Group(x, y, w, h), _rowHeight(rowHeight), _clock(0), _layingOut(false),
    _requested(nullptr)
{
  // FLTK 1.5 tabs draw their row with the box of their parent: without one, a
  // closed tab stays drawn
  box(FL_FLAT_BOX);
  _tabs = new Fl_Tabs(x, y, w, h);
  _tabs->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
  _tabs->when(FL_WHEN_CHANGED);
  _tabs->callback(_tabs_cb, this);
  _tabs->end();
  _tabs->hide();
  end();
}

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

bool toolDock::closeCurrent()
{
  // the visible one used last: open in the stack, or the tab shown
  paletteWindow *last = nullptr;
  for(auto &u : _used)
    if(u.first->visible() && (!last || u.second > _used[last])) last = u.first;
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
    // shown again: open, at the top
    _stack.erase(std::find(_stack.begin(), _stack.end(), t));
    _stack.insert(_stack.begin(), t);
    t->folded = false;
  }
  else if(dockTab *t = _tabOf(pw)) {
    t->copy_label(pw->label()); // some windows change their label
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
      t->copy_label(pw->label());
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
}
