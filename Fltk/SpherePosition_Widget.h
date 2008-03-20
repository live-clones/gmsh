#ifndef _SPHERE_POSITION_WIDGET_H_
#define _SPHERE_POSITION_WIDGET_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include <math.h>
#include <FL/Fl_Widget.H>

// A small 2D widget to set the coordinates of a point on the unit
// sphere.
class SpherePosition_Widget : public Fl_Widget {
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
  SpherePosition_Widget(int x,int y,int w, const char *l=0)
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
