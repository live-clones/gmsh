// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "paletteWindow.h"
#include "graphicWindow.h"

// What a tool window asks of the main window that docks it (paletteWindow::
// host, see toolDock.cpp)

void paletteWindow::dragToDock()
{
  if(!parent() && _dockable && host) host->dragToDock(this);
}

bool paletteWindow::dockByDoubleClick()
{
  if(!Fl::event_clicks() || Fl::event_button() != FL_LEFT_MOUSE || parent() ||
     !_dockable || !host || !host->takesTools())
    return false;
  Fl::event_clicks(0);
  dockToolLater(this);
  return true;
}

void paletteWindow::resize(int x, int y, int w, int h)
{
  bool sized = (w != this->w() || h != this->h());
  Fl_Double_Window::resize(x, y, w, h);
  if(!sized) { // only moved
    if(!parent() && _dockable && _floating && host) host->toolMoved(this);
    return;
  }
  if(!_rules.empty()) {
    _rules.apply(w - _width);
    init_sizes();
  }
  if(_resized) _resized(_resizedData);
  if(parent() && host) host->toolResized(this);
}

int paletteWindow::handle(int event)
{
  int up = dragEventUp(this, event);
  if(up >= 0) return up;
  switch(event) {
  case FL_PUSH:
    dragged = nullptr; // a drag that ended elsewhere, which Wayland hides
    if(Fl_Double_Window::handle(event)) return 1;
    if(Fl::event_button() != FL_LEFT_MOUSE || parent() || !_dockable)
      return 0;
    if(dockByDoubleClick()) return 1;
    _pushed = true;
    _pushX = Fl::event_x();
    _pushY = Fl::event_y();
    return 1;
  case FL_DRAG:
    if(!_pushed) break;
    if(abs(Fl::event_x() - _pushX) > 4 || abs(Fl::event_y() - _pushY) > 4) {
      _pushed = false;
      dragToDock();
    }
    return 1;
  case FL_RELEASE:
    if(!_pushed) break;
    _pushed = false;
    return 1;
  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // only when the focus is inside: FLTK also gives a key no one used to
    // the window under the pointer, which Escape must not close while the
    // scene has the focus (and the main window has keys of its own)
    if(!contains(Fl::focus())) break;
    // Escape stops the selection this window is for first, as in the
    // graphic window (a second one closes it, unless the end of the
    // selection did); the close key closes it, which ends the selection
    if(Fl::test_shortcut(FL_Escape) && sceneTool::owner() == ownerId()) {
      sceneTool::stop();
      return 1;
    }
    if(_closeKey() || Fl::test_shortcut(FL_Escape)) {
      do_callback();
      return 1;
    }
    break;
  }
  return Fl_Double_Window::handle(event);
}

void paletteWindow::show()
{
  if(_dockable && !_floating && host && host->takesTools()) {
    host->dockTool(this);
    return;
  }
  if(parent()) { // docked
    Fl_Double_Window::show();
    return;
  }
  _showOnDesktop();
  watchMoves(this);
  if(_dockable && host && host->takesTools()) floatingToolShown(this);
}

void paletteWindow::hide()
{
  // (hidden below, once: the end of the selection may hide it too)
  if(_endingTool) return;
  // FLTK also hides the subwindows of a window it hides: not a close
  bool docked = parent() && host && top_window()->shown();
  // closed (by any means): the selection it is for ends
  if((docked || !parent()) && sceneTool::owner() == ownerId()) {
    _endingTool = true;
    sceneTool::stop();
    _endingTool = false;
  }
  if(docked)
    host->toolHidden(this);
  else
    Fl_Double_Window::hide();
}
