// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef WINDOW_PLACEMENT_H
#define WINDOW_PLACEMENT_H

#include <vector>
#include <algorithm>

class Fl_Window;

// Placement of the top-level windows on one or several screens. The dialogs
// are placed relative to the main graphic window, so that they follow it from
// one screen to another, and every position is checked against the screens
// that are currently connected before a window is shown.

// the usable area of a screen (without menu bar, dock or taskbar)
struct screenArea {
  int x, y, w, h;
};

// The area showing enough of the top of a window of width w, placed at (x, y),
// to grab it: at least 2 * grab pixels wide, with the top grab pixels inside
// the area. Returns the area showing most of that strip, or -1.
inline int visibleOn(const std::vector<screenArea> &areas, int x, int y, int w,
                     int grab = 32)
{
  int best = -1, bestOverlap = 0;
  for(std::size_t i = 0; i < areas.size(); i++) {
    const screenArea &a = areas[i];
    int overlap = std::min(x + w, a.x + a.w) - std::max(x, a.x);
    if(overlap < std::min(w, 2 * grab)) continue;
    if(y < a.y || y + grab > a.y + a.h) continue;
    if(overlap > bestOverlap) {
      best = i;
      bestOverlap = overlap;
    }
  }
  return best;
}

// move a window inside an area, shrinking it if it is larger than the area
inline void fitIn(const screenArea &a, int &x, int &y, int &w, int &h)
{
  w = std::min(w, a.w);
  h = std::min(h, a.h);
  x = std::max(a.x, std::min(x, a.x + a.w - w));
  y = std::max(a.y, std::min(y, a.y + a.h - h));
}

// the main graphic window, relative to which the dialogs are placed
void setReferenceWindow(Fl_Window *win);
// the screen showing (most of) a window, or the main screen
int windowScreen(Fl_Window *win);
// the usable area of the screen showing a window
void windowWorkArea(Fl_Window *win, int &X, int &Y, int &W, int &H);
// place a window at an absolute position if that is visible on some screen,
// otherwise inside the usable area of the screen of the reference window
void placeWindowAt(Fl_Window *win, int x, int y);
// place a window at an offset from the reference window; a window placed
// before keeps the position the user left it at, and the offset is updated
void placeWindow(Fl_Window *win, int offset[2]);
// store the offset of a window from the reference window, if it was placed
void storeWindowOffset(Fl_Window *win, int offset[2]);
// center a window on the screen of the reference window (the first time only)
void centerWindow(Fl_Window *win);
// forget about a window that is being deleted
void forgetWindow(Fl_Window *win);
// whether the primary mouse button is held, asked of the system: 1, 0, or -1
// where it cannot say (while the window manager drags a window by its title
// bar, FLTK gets no mouse events)
int mouseButtonDown();
// whether the Shift key is held, asked of the system likewise
bool shiftKeyDown();

// the title bar of a top-level window drawn dark or light as the interface,
// where the desktop needs telling (Windows); called when the window is shown
// and when the interface switches
void titleBarColor(Fl_Window *w);

// the moves of a floating tool window reported to paletteWindow::movedHook
// where a move is not a resize (Windows); called when the window is shown
class paletteWindow;
void watchMoves(paletteWindow *w);

#endif
