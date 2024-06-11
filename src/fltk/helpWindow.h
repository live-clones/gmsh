// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HELP_WINDOW_H
#define HELP_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>

class helpWindow {
public:
  Fl_Window *about, *basic, *options;
  Fl_Check_Button *modified, *showhelp;
  Fl_Input *search;
  Fl_Browser *browser;

public:
  helpWindow();
  ~helpWindow()
  {
    Fl::delete_widget(about);
    Fl::delete_widget(basic);
    Fl::delete_widget(options);
  }
};

void help_options_cb(Fl_Widget *w, void *data);
double numberOrStringOptionChooser(const std::string &category, int index,
                                   const std::string &name,
                                   bool isNumber = true,
                                   const std::string &title = "",
                                   bool isInteractive = false,
                                   double minimum = 0., double maximum = 0.,
                                   double step = 0.);

#endif
