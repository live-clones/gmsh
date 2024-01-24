// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PALETTE_WINDOWH
#define PALETTE_WINDOWH

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

// Derive special windows from Fl_Double_Window to correctly process
// the OS-specific shorcuts (Esc & Cmd-w on Mac, Alt+F4 on Windows)
class paletteWindow : public Fl_Double_Window {
public:
  paletteWindow(int w, int h, bool nonModal, const char *l = nullptr)
    : Fl_Double_Window(w, h, l)
  {
    if(nonModal) set_non_modal();
  }
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
    if(non_modal() && !shown()) Fl_Double_Window::show(); // fix ordering
    Fl_Double_Window::show();
  }
};

#endif
