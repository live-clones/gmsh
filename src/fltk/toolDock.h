// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TOOL_DOCK_H
#define TOOL_DOCK_H

#include <map>
#include <vector>
#include <FL/Fl_Group.H>
#include "accentTabs.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Window.H>

class paletteWindow;

// The name of the window being torn out of the dock, in a chip that follows
// the pointer, as the tab or title held: a window of its own, over everything
class dragGhost : public Fl_Menu_Window {
  std::string _label;

public:
  dragGhost() : Fl_Menu_Window(1, 1) { set_override(); }
  void follow(const char *label, int rowHeight, int xroot, int yroot);
  void draw();
};

// The tab of a docked window of free height: an empty group, which the tabs
// show and hide as they please; the window lies over it and is shown by the
// dock
class dockTab : public Fl_Group {
public:
  paletteWindow *win;
  dockTab(int x, int y, int w, int h, paletteWindow *win)
    : Fl_Group(x, y, w, h), win(win)
  { end(); }
};

// The title bar of a docked window of fixed height, stacked above the tabs: a
// click folds or unfolds the window, its cross closes it, a drag out of the
// dock tears the window out of it
class dockTitle : public Fl_Widget {
  // where the button went down, and whether it has been dragged since
  int _pushX, _pushY;
  bool _dragging;

public:
  paletteWindow *win;
  // folded by a click, and folded as laid out, also for lack of room
  bool folded, shut;
  dockTitle(int x, int y, int w, int h, paletteWindow *win)
    : Fl_Widget(x, y, w, h), _pushX(0), _pushY(0), _dragging(false), win(win),
      folded(false), shut(false)
  {
  }
  void draw();
  int handle(int event);
};

// The tabs of the docked windows of free height: a tab dragged along the row
// is put down where it is released, a tab dragged out of the dock tears its
// window out of it
class dockTabs : public accentTabs {
  // the tab the button went down on, where, whether it has been dragged, and
  // where in the row a release would put it (-1: not over the row)
  Fl_Widget *_pressed;
  int _pushX, _pushY;
  bool _dragging;
  int _dropAt;
  int _indexAt(int x, int y);

public:
  dockTabs(int x, int y, int w, int h)
    : accentTabs(x, y, w, h), _pressed(nullptr), _pushX(0), _pushY(0),
      _dragging(false), _dropAt(-1)
  {
  }
  int handle(int event);
  void draw();
};

// A column of the main window where the tool windows are docked, as
// subwindows: those of fixed height stacked at the top under title bars, the
// others as tabs below, in the height left. A tool window shown is docked, and
// leaves when closed; the windows keep their own code: show(), hide() and
// shown() work as before.
class toolDock : public Fl_Group {
private:
  int _rowHeight;
  dockTabs *_tabs;
  dragGhost *_ghost;
  // drawn as the target of a window dragged over it (see draw())
  bool _dropHint;
  std::vector<dockTitle *> _stack; // from the top
  // where in the stack a release of the title being dragged would put it
  // (-1: not over the dock)
  int _dropAt;
  int _stackIndexAt(int y) const;
  // when each window was last used, to fold and to close
  std::map<paletteWindow *, unsigned long> _used;
  unsigned long _clock;
  bool _layingOut;
  // the window docked or brought forward by its tool, which refreshes it
  paletteWindow *_requested;
  void _show(paletteWindow *pw);
  dockTab *_tabOf(paletteWindow *pw);
  dockTitle *_titleOf(paletteWindow *pw);
  void _use(paletteWindow *pw) { _used[pw] = ++_clock; }
  bool _place(paletteWindow *pw);
  void _showCurrent();
  void _layout();
  static void _tabs_cb(Fl_Widget *w, void *data);
  static void _close_cb(Fl_Widget *w, void *data);

public:
  // set by the main window: a window torn out of the dock, to be shown on
  // the desktop under the pointer (root coordinates)
  inline static void (*tornOutHook)(paletteWindow *w, int x, int y) = nullptr;
  toolDock(int x, int y, int w, int h, int rowHeight);
  // docks the window, or brings it forward, and shows it
  void dock(paletteWindow *pw);
  // a tab or title dragged: whether the drag from (fromX, fromY) to (x, y)
  // is one, the chip of its window at the pointer (root coordinates), and
  // whether a release at (x, y) is out of the dock
  bool dragged(int fromX, int fromY, int x, int y) const;
  void dragging(paletteWindow *pw, int x, int y);
  bool outside(int x, int y) const;
  // a title dragged to (x, y) in the dock: the marker of where it would go,
  // and its move there on the release
  void stackTarget(int x, int y);
  void dropInStack(dockTitle *t);
  // the drag over: the chip goes, and the window leaves the dock for the
  // desktop under the pointer if asked, staying there until dragged back
  // (see paletteWindow::floating())
  void dragEnded(paletteWindow *pw, int x, int y, bool tearOut);
  void dropHint(bool on);
  bool dropHint() const { return _dropHint; }
  // the docked window is hidden by its own code: closed
  void hidden(paletteWindow *pw);
  // a docked window changed its own size
  void resized(paletteWindow *pw);
  // folds or unfolds a stacked window
  void fold(dockTitle *t, bool folded);
  // gives all the windows back to the desktop, shown or not
  void undockAll(bool show = true);
  bool empty() const { return !_tabs->children() && _stack.empty(); }
  // the visible window used last: open in the stack, or the tab shown
  paletteWindow *current();
  // closes it, as its close button would
  bool closeCurrent();
  void resize(int x, int y, int w, int h);
  void draw();
};

// The edge between the tiles and the dock, a line like the edges of the tiles,
// dragged to change the width of the dock
class dockDivider : public Fl_Box {
public:
  // drawn in the selection colour with the drop hint of the dock
  bool highlight;
  dockDivider(int x, int y, int w, int h) : Fl_Box(x, y, w, h), highlight(false)
  {
  }
  int handle(int event);
  void draw();
};

#endif
