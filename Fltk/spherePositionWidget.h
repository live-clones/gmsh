// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SPHERE_POSITION_WIDGET_H_
#define _SPHERE_POSITION_WIDGET_H_

#include <math.h>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl.H>

// A small 2D widget to set the coordinates of a point on the unit
// sphere.
class spherePositionWidget : public Fl_Widget {
 private:
  double _x, _y, _z;
  void draw()
  {
    draw_box(box(), color());
    int x1 = x() + 3;
    int y1 = y() + 3;
    int w1 = w() - 6;
    int h1 = h() - 6;
    fl_color(FL_FOREGROUND_COLOR);
    fl_arc(x1, y1, w1, h1, 0, 360);
    int px = int(x1 + 0.5 * w1 * (1 + _x));
    int py = int(y1 + 0.5 * h1 * (1 - _y));
    draw_box(FL_UP_BOX, px - 3, py - 3, 6, 6, FL_FOREGROUND_COLOR);
  }
  int handle(int event)
  {
    switch (event) {
    case FL_PUSH:
    case FL_DRAG:
    case FL_RELEASE: 
      {
        int x1 = x() + 3;
        int y1 = y() + 3;
        int w1 = w() - 6;
        int h1 = h() - 6;
        double xx = (Fl::event_x() - x1) / (0.5 * w1) - 1.;
        double yy = -((Fl::event_y() - y1) / (0.5 * h1) - 1.);
        if(xx != _x || yy != _y) {
          double norm = sqrt(xx * xx + yy * yy);
          if(norm > 1.){
            xx /= norm;
            yy /= norm;
            norm = 1.;
          }
          _x = xx; _y = yy; _z = sqrt(1. - norm);
          set_changed();
          redraw();
          do_callback();
        }
      }
      return 1;
    default:
      return 0;
    }
  }
 public:
  spherePositionWidget(int x, int y, int w, const char *l=0)
    : Fl_Widget(x, y, w, w, l), _x(0.), _y(0.), _z(0.)
  {
    box(FL_FLAT_BOX);
    align(FL_ALIGN_BOTTOM);
  }
  void getValue(double &x, double &y, double &z) const { x = _x; y = _y; z = _z; }
  void setValue(double x, double y, double z)
  {
    double norm = sqrt(x * x + y * y + z * z);
    if(norm){
      _x = x / norm; _y = y / norm; _z = z / norm;
    }
    else{
      _x = _y = _z = 0.;
    }
    redraw();
  }
};

#endif
