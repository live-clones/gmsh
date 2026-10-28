// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MAIN_WINDOWH
#define MAIN_WINDOWH

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_ask.H>
#include "windowPlacement.h"

// Derive the main window from Fl_Window (it shows up faster that way)
class mainWindow : public Fl_Window {
private:
  // position relative to the main graphic window, applied when shown
  int *_offset;

public:
  // set while tool windows are docked: closes the one shown in window w, or
  // returns false
  inline static bool (*closeToolHook)(Fl_Window *w) = nullptr;
  // called when a window gets the focus (the desktop may have switched
  // between light and dark meanwhile, see FlGui)
  inline static void (*focusHook)() = nullptr;
  mainWindow(int w, int h, bool nonModal, const char *l = nullptr,
             int *offset = nullptr)
    : Fl_Window(w, h, l), _offset(offset)
  {
    if(nonModal) set_non_modal();
  }
  ~mainWindow() { forgetWindow(this); }
  virtual int handle(int event)
  {
    switch(event) {
    case FL_FOCUS:
      if(focusHook) focusHook();
      break;
    case FL_SHORTCUT:
    case FL_KEYBOARD:
#if defined(__APPLE__)
      if(Fl::test_shortcut(FL_META + 'w')) {
#elif defined(WIN32)
      if(Fl::test_shortcut(FL_ALT + FL_F + 4)) {
#else
      if(Fl::test_shortcut(FL_CTRL + 'w')) {
#endif
#if !defined(WIN32) // Cmd-W or Ctrl-W, not Alt-F4
        if(closeToolHook && closeToolHook(this)) return 1;
#endif
        if(fl_choice("Do you really want to quit?", "Cancel", "Quit", nullptr))
          do_callback();
        return 1;
      }
      break;
    }
    return Fl_Window::handle(event);
  }
  virtual void resize(int X, int Y, int W, int H)
  {
    Fl_Window::resize(X, Y, W, H);
  }
  virtual void show()
  {
    if(_offset) placeWindow(this, _offset);
    if(non_modal() && !shown()) Fl_Window::show(); // fix ordering
    Fl_Window::show();
    titleBarColor(this);
  }
};

#endif
