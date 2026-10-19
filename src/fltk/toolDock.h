// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TOOL_DOCK_H
#define TOOL_DOCK_H

#include <map>
#include <vector>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>

class paletteWindow;

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
// click folds or unfolds the window, its cross closes it
class dockTitle : public Fl_Widget {
public:
  paletteWindow *win;
  // folded by a click, and folded as laid out, also for lack of room
  bool folded, shut;
  dockTitle(int x, int y, int w, int h, paletteWindow *win)
    : Fl_Widget(x, y, w, h), win(win), folded(false), shut(false)
  {
  }
  void draw();
  int handle(int event);
};

// A column of the main window where the tool windows are docked, as
// subwindows: those of fixed height stacked at the top under title bars, the
// others as tabs below, in the height left. A tool window shown is docked, and
// leaves when closed; the windows keep their own code: show(), hide() and
// shown() work as before.
class toolDock : public Fl_Group {
private:
  int _rowHeight;
  Fl_Tabs *_tabs;
  std::vector<dockTitle *> _stack; // from the top
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
  toolDock(int x, int y, int w, int h, int rowHeight);
  // docks the window, or brings it forward, and shows it
  void dock(paletteWindow *pw);
  // the docked window is hidden by its own code: closed
  void hidden(paletteWindow *pw);
  // a docked window changed its own size
  void resized(paletteWindow *pw);
  // folds or unfolds a stacked window
  void fold(dockTitle *t, bool folded);
  // gives all the windows back to the desktop, shown or not
  void undockAll(bool show = true);
  bool empty() const { return !_tabs->children() && _stack.empty(); }
  // closes the visible window used last, as its close button would
  bool closeCurrent();
  void resize(int x, int y, int w, int h);
};

// The edge between the tiles and the dock, a line like the edges of the tiles,
// dragged to change the width of the dock
class dockDivider : public Fl_Box {
public:
  dockDivider(int x, int y, int w, int h) : Fl_Box(x, y, w, h) {}
  int handle(int event);
  void draw();
};

#endif
