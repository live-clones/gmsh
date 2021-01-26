// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GAMEPAD_WINDOW_H
#define GAMEPAD_WINDOW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Box.H>

extern Fl_Menu_Item menu_font_names[];

// A small 2D widget to visualize the coordinates of a point on the unit
// circle.
class AxesPositionWidget : public Fl_Widget {
private:
  double _x, _y;
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

public:
  AxesPositionWidget(int x, int y, int w, const char *l = 0)
    : Fl_Widget(x, y, w, w, l), _x(0.), _y(0.)
  {
    box(FL_FLAT_BOX);
    align(FL_ALIGN_BOTTOM);
  }
  void setValue(double x, double y)
  {
    double norm = sqrt(x * x + y * y);
    if(norm) {
      _x = x / norm;
      _y = y / norm;
    }
    else {
      _x = _y = 0.;
    }
    redraw();
  }
};

class gamepadWindow {
public:
  Fl_Window *win;

  struct {
    Fl_Check_Button *butt[21];
    Fl_Check_Button *axe[21];
    Fl_Check_Button *cont[21];
    Fl_Value_Input *mapping[21];
    AxesPositionWidget *padL;
    AxesPositionWidget *padR;
    AxesPositionWidget *Dpad;
  } gamepad;

public:
  gamepadWindow();
  double frequency;
};

#endif
