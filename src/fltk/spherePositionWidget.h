// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SPHERE_POSITION_WIDGET_H
#define SPHERE_POSITION_WIDGET_H

#include <cmath>
#include <algorithm>
#include <vector>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl.H>

// A ball lit from a point of the unit sphere, dragged around to set the
// coordinates of the point (the light direction)
class spherePositionWidget : public Fl_Widget {
private:
  double _x, _y, _z;
  // the ball, as large as fits
  int _d() const { return std::min(w(), h()) - 4; }
  int _x0() const { return x() + (w() - _d()) / 2; }
  int _y0() const { return y() + (h() - _d()) / 2; }
  void draw()
  {
    draw_box(box(), color());
    int d = _d(), x0 = _x0(), y0 = _y0();
    if(d <= 0) return; // no room for the ball
    // the ball shaded pixel by pixel: ambient, diffuse and a highlight
    unsigned char r, g, b;
    Fl::get_color(color(), r, g, b);
    std::vector<unsigned char> img(3 * d * d);
    for(int j = 0; j < d; j++) {
      for(int i = 0; i < d; i++) {
        unsigned char *p = &img[3 * (j * d + i)];
        double X = (i + 0.5) / (0.5 * d) - 1., Y = 1. - (j + 0.5) / (0.5 * d);
        double rr = X * X + Y * Y;
        if(rr > 1.) {
          p[0] = r, p[1] = g, p[2] = b;
          continue;
        }
        double s = std::max(0., X * _x + Y * _y + sqrt(1. - rr) * _z);
        double v = 0.2 + 0.6 * s + 0.2 * pow(s, 32);
        p[0] = p[1] = p[2] = (unsigned char)(40 + 200 * v);
      }
    }
    fl_draw_image(&img[0], x0, y0, d, d, 3);
    fl_color(FL_FOREGROUND_COLOR);
    fl_arc(x0, y0, d, d, 0, 360);
    // the light
    int px = int(x0 + 0.5 * d * (1 + _x)), py = int(y0 + 0.5 * d * (1 - _y));
    fl_color(FL_SELECTION_COLOR);
    fl_pie(px - 4, py - 4, 8, 8, 0, 360);
    fl_color(FL_BACKGROUND2_COLOR);
    fl_arc(px - 4, py - 4, 8, 8, 0, 360);
  }
  int handle(int event)
  {
    switch(event) {
    case FL_PUSH:
    case FL_DRAG:
    case FL_RELEASE: {
      int d = _d();
      if(d <= 0) return 1;
      double xx = (Fl::event_x() - _x0()) / (0.5 * d) - 1.;
      double yy = -((Fl::event_y() - _y0()) / (0.5 * d) - 1.);
      if(xx != _x || yy != _y) {
        double norm = sqrt(xx * xx + yy * yy);
        if(norm > 1.) {
          xx /= norm;
          yy /= norm;
          norm = 1.;
        }
        _x = xx;
        _y = yy;
        _z = sqrt(1. - norm * norm);
        set_changed();
        redraw();
        do_callback();
      }
    }
      return 1;
    default: return 0;
    }
  }

public:
  spherePositionWidget(int x, int y, int w, const char *l = nullptr)
    : Fl_Widget(x, y, w, w, l), _x(0.), _y(0.), _z(0.)
  {
    box(FL_FLAT_BOX);
    align(FL_ALIGN_BOTTOM);
    tooltip("Drag the light around the ball");
  }
  void getValue(double &x, double &y, double &z) const
  {
    x = _x;
    y = _y;
    z = _z;
  }
  void setValue(double x, double y, double z)
  {
    double norm = sqrt(x * x + y * y + z * z);
    if(norm) {
      _x = x / norm;
      _y = y / norm;
      _z = z / norm;
    }
    else {
      _x = _y = _z = 0.;
    }
    redraw();
  }
};

#endif
