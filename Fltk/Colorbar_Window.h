#ifndef _COLORBAR_WINDOW_H
#define _COLORBAR_WINDOW_H

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GmshUI.h"
#include "ColorTable.h"

class Colorbar_Window : public Fl_Window {
  void draw();
  int  handle(int);

  // new
  int  x_to_index(int x);
  int  index_to_x(int index);
  int  y_to_intensity(int y);
  int  intensity_to_y(int intensity);
  void redraw_range(int a, int b);
  void redraw_marker();

  int font_height, marker_height, wedge_height;
  char *label;

  double minval, maxval;  // min and max data values
  int wedge_y;     // top coord of color wedge
  int marker_y;    // top coord of marker arrow
  int label_y;     // y coord of text labels
  int help_flag;   // if nonzero, print help message
  int marker_pos;  // position of marker as index into table
  
  GmshColorTable *ct; // pointer to the color table (allocated in Post_View)
  int *viewchanged;   // pointer to changed bit in view
  Fl_Color color_bg;

public:

  Colorbar_Window(int x,int y,int w,int h,const char *l=0);
  void update(char *name, double min, double max, GmshColorTable *ct, int *changed);

};

#endif
