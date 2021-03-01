// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef COLORBAR_WINDOWH
#define COLORBAR_WINDOWH

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "ColorTable.h"

class colorbarWindow : public Fl_Window {
private:
  int font_height, marker_height, wedge_height;
  const char *label;
  double minval, maxval; // min and max data values
  int wedge_y; // top coord of color wedge
  int marker_y; // top coord of marker arrow
  int label_y; // y coord of text labels
  int help_flag; // if nonzero, print help message
  int marker_pos; // position of marker as index into table
  GmshColorTable *ct; // pointer to the color table (allocated in the view)
  bool *viewchanged; // pointer to changed bit in view
  Fl_Color color_bg;
  // convert window X coordinate to color table index
  int x_to_index(int x);
  // convert color table index to window X coordinate
  int index_to_x(int index);
  // convert a window Y coordinate to a color intensity
  int y_to_intensity(int y);
  // convert a color intensity to a window Y coordinate
  int intensity_to_y(int intensity);
  // redraw part of the colorbarWindow (between a and b)
  void redraw_range(int a, int b);
  // redraw the marker and the text
  void redraw_marker();

public:
  colorbarWindow(int x, int y, int w, int h, const char *l = nullptr);
  void draw();
  int handle(int);
  void update(const char *name, double min, double max, GmshColorTable *ct,
              bool *changed);
};

#endif
