// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef STATISTICS_WINDOW_H
#define STATISTICS_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Check_Button.H>

class statisticsWindow {
public:
  Fl_Window *win;
  Fl_Output *value[50];
  Fl_Button *butt[8];
  Fl_Group *group[3];
  Fl_Box *memUsage;
  Fl_Check_Button *visible;
  double quality[3][100];

public:
  statisticsWindow(int deltaFontSize);
  ~statisticsWindow() { Fl::delete_widget(win); }
  void compute(bool elementQuality);
  void show();
};

void statistics_cb(Fl_Widget *w, void *data);

#endif
