// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESSAGE_WINDOW_H_
#define _MESSAGE_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Check_Button.H>

class messageWindow{
 public:
  Fl_Window *win;
  Fl_Browser *browser;
  Fl_Check_Button *butt;
 public:
  messageWindow(int deltaFontSize);
  void show(bool redrawOnly=false);
  void add(const char *msg);
  void save(const char *filename);
};

void message_cb(Fl_Widget *w, void *data);

#endif
