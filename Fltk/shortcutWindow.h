// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SHORTCUT_WINDOW_H
#define _SHORTCUT_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_ask.H>

// Derive special windows from Fl_Double_Window to correctly process
// the OS-specific shorcuts (Cmd-w on Mac, Alt+F4 on Windows)

class dialogWindow : public Fl_Double_Window {
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
  dialogWindow(int w, int h, int nonmodal=false, const char *l=0)
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

// Do the same for the main windows, but ask if we really want to quit
// before closing. Also, derive the main windows from Fl_Window: they
// show up faster that way, and they only contain either buttons that
// are recreated each time, or the big (already double-buffered)
// OpenGL area anyway.

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
  mainWindow(int w, int h, bool nonmodal=false, const char *l=0) 
    : Fl_Window(w, h, l) 
  {
    if(nonmodal) set_non_modal();
  }
  void show()
  {
    if(non_modal() && !shown()) Fl_Window::show(); // fix ordering
    Fl_Window::show();
  }
};

#endif
