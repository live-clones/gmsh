// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "inputValue.h"
#include <FL/Fl_Group.H>
#include <stdlib.h>
#include <FL/math.h>

void inputValueFloat::new_input_cb(Fl_Widget *, void *v)
{
  inputValueFloat &t = *(inputValueFloat *)v;
  double nv = strtod(t.input.value(), nullptr);
  if(nv != t.value() || t.when() & FL_WHEN_NOT_CHANGED) {
    t.set_value(nv);
    t.set_changed();
    if(t.when()) t.do_callback();
  }
}

inputValueFloat::inputValueFloat(int x, int y, int w, int h, const char *l)
  : inputValue(x, y, w, h, l)
{
  input.type(FL_FLOAT_INPUT);
  input.callback(new_input_cb, this);
}

int inputValueFloat::handle(int event)
{
  double v;
  int delta;
  int mx = Fl::event_x_root();
  static int ix, drag;
  input.when(when());
  switch(event) {
  case FL_PUSH:
    if(!step()) goto DEFAULT;
    ix = mx;
    drag = Fl::event_button();
    handle_push();
    return 1;
  case FL_DRAG:
    if(!step()) goto DEFAULT;
    delta = mx - ix;
    if(delta > 5)
      delta -= 5;
    else if(delta < -5)
      delta += 5;
    else
      delta = 0;
    switch(drag) {
    case 3: v = increment(previous_value(), delta * 100); break;
    case 2: v = increment(previous_value(), delta * 10); break;
    default: v = increment(previous_value(), delta); break;
    }
    v = round(v);
    handle_drag(soft() ? softclamp(v) : clamp(v));
    ;
    return 1;
  case FL_RELEASE:
    if(!step()) goto DEFAULT;
    if(value() != previous_value() || !Fl::event_is_click())
      handle_release();
    else {
      Fl_Widget_Tracker wp(&input);
      input.handle(FL_PUSH);
      if(wp.exists()) input.handle(FL_RELEASE);
    }
    return 1;
  case FL_FOCUS: return input.take_focus();
  case FL_SHORTCUT: return input.handle(event);
  default:
  DEFAULT:
    return input.handle(event);
  }
}
