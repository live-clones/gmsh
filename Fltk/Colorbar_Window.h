#ifndef _COLORBAR_WINDOW_H
#define _COLORBAR_WINDOW_H

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

  float minval, maxval;  // min and max data values
  int wedge_y;     // top coord of color wedge
  int marker_y;    // top coord of marker arrow
  int label_y;     // y coord of text labels
  int help_flag;   // if nonzero, print help message
  int marker_pos;  // position of marker as index into table
  
  ColorTable *ct;  // pointer to the color table (allocated in Post_View)
  int *viewchanged;// pointer to changed bit in view

public:

  Colorbar_Window(int x,int y,int w,int h,const char *l=0);
  void update(char *name, float min, float max, ColorTable *ct, int *changed);

};

#endif
