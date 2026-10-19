// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HINT_INPUT_H
#define HINT_INPUT_H

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

#endif
