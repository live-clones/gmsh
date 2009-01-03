// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GRAPHIC_WINDOW_H_
#define _GRAPHIC_WINDOW_H_

#include <vector>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tile.H>
#include "openglWindow.h"

class graphicWindow{
 public:
  Fl_Window *win;
  Fl_Tile *tile;
  std::vector<openglWindow*> gl;
  Fl_Box *bottom;
  Fl_Button *butt[12];
  Fl_Box *label[2];
 public:
  graphicWindow(int numTiles=1);
  ~graphicWindow();
  void split(openglWindow *g, char how);
  void setAnimButtons(int mode);
  void checkAnimButtons();
};

void status_xyz1p_cb(Fl_Widget *w, void *data);
void status_options_cb(Fl_Widget *w, void *data);
void status_play_manual(int time, int step);

#endif
