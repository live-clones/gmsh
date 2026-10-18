// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PALETTE_WINDOWH
#define PALETTE_WINDOWH

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "windowPlacement.h"

// Derive special windows from Fl_Double_Window to correctly process
// the OS-specific shorcuts (Esc & Cmd-w on Mac, Alt+F4 on Windows)
class paletteWindow : public Fl_Double_Window {
private:
  // position relative to the main graphic window, applied when shown
  int *_offset;

public:
  paletteWindow(int w, int h, bool nonModal, const char *l = nullptr,
                int *offset = nullptr)
    : Fl_Double_Window(w, h, l), _offset(offset)
  {
    if(nonModal) set_non_modal();
  }
  ~paletteWindow() { forgetWindow(this); }
  virtual int handle(int event)
  {
    switch(event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
#if defined(__APPLE__)
      if(Fl::test_shortcut(FL_META + 'w') || Fl::test_shortcut(FL_Escape)) {
#elif defined(WIN32)
      if(Fl::test_shortcut(FL_ALT + FL_F + 4) || Fl::test_shortcut(FL_Escape)) {
#else
      if(Fl::test_shortcut(FL_CTRL + 'w') || Fl::test_shortcut(FL_Escape)) {
#endif
        do_callback();
        return 1;
      }
      break;
    }
    return Fl_Double_Window::handle(event);
  }
  virtual void show()
  {
    if(_offset) placeWindow(this, _offset);
    if(non_modal() && !shown()) Fl_Double_Window::show(); // fix ordering
    Fl_Double_Window::show();
  }
};

#endif
