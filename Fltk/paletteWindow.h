// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PALETTE_WINDOW_H
#define _PALETTE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

// Derive special windows from Fl_Double_Window to correctly process
// the OS-specific shorcuts (Esc & Cmd-w on Mac, Alt+F4 on Windows)
class paletteWindow : public Fl_Double_Window {
 private:
  int handle(int event)
  {
    switch (event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
#if defined(__APPLE__)
      if(Fl::test_shortcut(FL_META+'w') || Fl::test_shortcut(FL_Escape)){
#elif defined(WIN32)
      if(Fl::test_shortcut(FL_ALT+FL_F+4) || Fl::test_shortcut(FL_Escape)){
#else
      if(Fl::test_shortcut(FL_CTRL+'w') || Fl::test_shortcut(FL_Escape)){
#endif
        do_callback();
        return 1;
      }
      break;
    }
    return Fl_Double_Window::handle(event);
  }
 public:
  paletteWindow(int w, int h, int nonmodal=false, const char *l=0)
    : Fl_Double_Window(w, h, l) 
  {
    if(nonmodal) set_non_modal();
  }
  void show()
  {
    if(non_modal() && !shown()) Fl_Double_Window::show(); // fix ordering
    Fl_Double_Window::show();
  }
};

#endif
