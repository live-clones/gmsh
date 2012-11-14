// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_ask.H>

// Derive the main window from Fl_Window (it shows up faster that way)
class mainWindow : public Fl_Window {
 private:
  int handle(int event)
  {
    switch (event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
#if defined(__APPLE__)
      if(Fl::test_shortcut(FL_META+'w')){
#elif defined(WIN32)
      if(Fl::test_shortcut(FL_ALT+FL_F+4)){
#else
      if(Fl::test_shortcut(FL_CTRL+'w')){
#endif
        if(fl_choice("Do you really want to quit?", "Cancel", "Quit", 0))
          do_callback();
        return 1;
      }
      break;
    }
    return Fl_Window::handle(event);
  }
 public:
  mainWindow(int w, int h, bool nonModal, const char *l=0) 
    : Fl_Window(w, h, l) 
  {
    if(nonModal) set_non_modal();
  }
  void show()
  {
    if(non_modal() && !shown()) Fl_Window::show(); // fix ordering
    Fl_Window::show();
  }
};

#endif
