// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HINT_INPUT_H
#define HINT_INPUT_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>

// an input that says what it is for while it is empty
class hintInput : public Fl_Input {
private:
  const char *_hint;

public:
  hintInput(int x, int y, int w, int h, const char *label, const char *hint)
    : Fl_Input(x, y, w, h, label), _hint(hint)
  {
  }
  void draw()
  {
    Fl_Input::draw();
    if(size()) return;
    fl_font(textfont(), textsize());
    fl_color(fl_inactive(textcolor()));
    fl_draw(_hint, x() + 3, y(), w() - 6, h(), FL_ALIGN_LEFT | FL_ALIGN_CLIP);
  }
};

// a search field in a frame with the magnifier on its left, the frame added
// to the current group and the field its resizable; the field calls cb as it
// is typed in, and takes Enter (a search has no button to run)
inline hintInput *searchBox(int x, int y, int w, int h, const char *hint,
                            const char *tooltip, Fl_Callback *cb)
{
  Fl_Group *o = new Fl_Group(x, y, w, h);
  o->tooltip(tooltip);
  o->box(FL_DOWN_BOX);
  o->color(FL_BACKGROUND2_COLOR);
  hintInput *s =
    new hintInput(x + h, y + 2, w - h - 2, h - 4, "@gmsh_search", hint);
  s->box(FL_FLAT_BOX);
  s->callback(cb);
  s->when(FL_WHEN_CHANGED | FL_WHEN_ENTER_KEY_ALWAYS);
  o->resizable(s);
  o->end();
  return s;
}

#endif
