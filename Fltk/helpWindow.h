// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _HELP_WINDOW_H_
#define _HELP_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>

class helpWindow{
 public:
  Fl_Window *about, *basic, *options;
  Fl_Check_Button *modified, *showhelp;
  Fl_Input *search;
  Fl_Browser *browser;
 public:
  helpWindow();
};

void help_options_cb(Fl_Widget *w, void *data);
double numberOrStringOptionChooser(const std::string &category, int index,
                                   const std::string &name, bool isNumber=true,
                                   const std::string &title="",
                                   bool isInteractive=false, double minimum=0.,
                                   double maximum=0., double step=0.);

#endif
