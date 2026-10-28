// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "windowPlacement.h"
#include "paletteWindow.h"
#include "desktop.h"
#include "Context.h"
#include <FL/platform.H>
#if defined(__APPLE__)
#include <ApplicationServices/ApplicationServices.h>
#elif defined(WIN32)
#include <windows.h>
#elif defined(FLTK_USE_X11)
#include <FL/platform.H>
#endif

bool screenPositionsKnown()
{
#if defined(FLTK_USE_WAYLAND)
  if(fl_wl_display()) return false;
#endif
  return true;
}

int mouseButtonDown()
{
#if defined(__APPLE__)
  return CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState,
                                  kCGMouseButtonLeft) ?
           1 :
           0;
#elif defined(WIN32)
  return (GetAsyncKeyState(VK_LBUTTON) & 0x8000) ? 1 : 0;
#elif defined(FLTK_USE_X11)
  Display *d = fl_x11_display();
  if(!d) return -1; // Wayland
  Window root, child;
  int rx, ry, x, y;
  unsigned int mask;
  if(!XQueryPointer(d, DefaultRootWindow(d), &root, &child, &rx, &ry, &x, &y,
                    &mask))
    return -1;
  return (mask & Button1Mask) ? 1 : 0;
#else
  return -1;
#endif
}

bool shiftKeyDown()
{
#if defined(__APPLE__)
  return CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState) &
         kCGEventFlagMaskShift;
#elif defined(WIN32)
  return (GetAsyncKeyState(VK_SHIFT) & 0x8000) ? true : false;
#elif defined(FLTK_USE_X11)
  Display *d = fl_x11_display();
  if(!d) return false;
  Window root, child;
  int rx, ry, x, y;
  unsigned int mask;
  if(!XQueryPointer(d, DefaultRootWindow(d), &root, &child, &rx, &ry, &x, &y,
                    &mask))
    return false;
  return (mask & ShiftMask) ? true : false;
#else
  return false;
#endif
}

static Fl_Window *reference = nullptr;
static std::set<Fl_Window *> placed;

static std::vector<screenArea> screenAreas()
{
  std::vector<screenArea> areas;
  for(int n = 0; n < Fl::screen_count(); n++) {
    screenArea a;
    Fl::screen_work_area(a.x, a.y, a.w, a.h, n);
    areas.push_back(a);
  }
  if(areas.empty()) { // should not happen, but let's be safe
    screenArea a;
    Fl::screen_work_area(a.x, a.y, a.w, a.h);
    areas.push_back(a);
  }
  return areas;
}

void setReferenceWindow(Fl_Window *win) { reference = win; }

int windowScreen(Fl_Window *win)
{
  int n = visibleOn(screenAreas(), win->x(), win->y(), win->w());
  return (n < 0) ? 0 : n;
}

void windowWorkArea(Fl_Window *win, int &X, int &Y, int &W, int &H)
{
  Fl::screen_work_area(X, Y, W, H, windowScreen(win));
}

void placeWindowAt(Fl_Window *win, int x, int y)
{
  std::vector<screenArea> areas = screenAreas();
  int w = win->w(), h = win->h();
  int n = visibleOn(areas, x, y, w);
  if(n < 0) {
    n = (reference && reference != win) ? windowScreen(reference) : 0;
    fitIn(areas[n], x, y, w, h);
  }
  if(w != win->w() || h != win->h())
    win->resize(x, y, w, h);
  else
    win->position(x, y);
#if FL_API_VERSION > 10400
  // with several screens of different scale factors, a position alone does not
  // identify the screen (the setter appeared during the development of 1.4.0,
  // so 1.4.0 itself is left out: a version check cannot tell its snapshots
  // apart)
  win->screen_num(n);
#endif
  placed.insert(win);
}

void placeWindow(Fl_Window *win, int offset[2])
{
  if(win->shown()) return;
  if(!reference) {
    placeWindowAt(win, offset[0], offset[1]);
    return;
  }
  storeWindowOffset(win, offset);
  placeWindowAt(win, reference->x() + offset[0], reference->y() + offset[1]);
}

void storeWindowOffset(Fl_Window *win, int offset[2])
{
  // a docked window keeps the offset it had on the desktop
  if(!reference || !placed.count(win) || win->parent()) return;
  offset[0] = win->x() - reference->x();
  offset[1] = win->y() - reference->y();
}

void centerWindow(Fl_Window *win)
{
  if(win->shown()) return;
  if(placed.count(win)) { // keep it where the user left it, if visible
    placeWindowAt(win, win->x(), win->y());
    return;
  }
  int X, Y, W, H;
  if(reference)
    windowWorkArea(reference, X, Y, W, H);
  else
    Fl::screen_work_area(X, Y, W, H);
  placeWindowAt(win, X + (W - win->w()) / 2, Y + (H - win->h()) / 2);
}

void forgetWindow(Fl_Window *win)
{
  placed.erase(win);
  if(reference == win) reference = nullptr;
}

void titleBarColor(Fl_Window *w)
{
#if defined(WIN32)
  if(!w->parent() && w->shown())
    desktopTitleBar((void *)fl_xid(w), CTX::instance()->guiDark);
#endif
}

#if defined(WIN32)
static void window_moved(void *hwnd)
{
  paletteWindow *w = dynamic_cast<paletteWindow *>(fl_find((HWND)hwnd));
  if(w && !w->parent() && w->dockable() && w->floating() &&
     paletteWindow::movedHook)
    paletteWindow::movedHook(w);
}
#endif

void watchMoves(paletteWindow *w)
{
#if defined(WIN32)
  if(!w->parent() && w->shown())
    watchWindowMoves((void *)fl_xid(w), window_moved);
#endif
}
