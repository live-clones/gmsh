// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _STATISTICS_WINDOW_H_
#define _STATISTICS_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>

class statisticsWindow{
 public:
  Fl_Window *win;
  Fl_Output *value[50];
  Fl_Button *butt[8];
  Fl_Group *group[3];
  Fl_Box *memUsage;
  double quality[4][100];
 public:
  statisticsWindow(int deltaFontSize);
  void compute(bool elementQuality);
  void show();
};

void statistics_cb(Fl_Widget *w, void *data);

#endif
