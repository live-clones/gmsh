// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HINT_INPUT_H
#define HINT_INPUT_H

#include <regex>
#include <string>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>
#include "gmshScheme.h"
#include "icons.h"

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

// what a search box asks for: a regular expression, compiled once and matched
// without case; one that does not parse yet is shown in red and lets
// everything through, as an empty box does
class searchFilter {
private:
  std::regex _regex;
  bool _active, _valid;

public:
  searchFilter() : _active(false), _valid(true) {}
  // reads the box, and colours it
  void set(Fl_Input *box)
  {
    std::string s = box->value();
    _active = !s.empty();
    _valid = true;
    if(_active) {
      try {
        _regex = std::regex(s, std::regex_constants::icase);
      } catch(...) {
        _valid = false;
      }
    }
    box->textcolor(_valid ? FL_FOREGROUND_COLOR : FL_RED);
    box->redraw();
  }
  // nothing is filtered out
  bool empty() const { return !_active || !_valid; }
  bool matches(const std::string &text) const
  { return empty() || std::regex_search(text, _regex); }
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
  if(gmshScheme()) gmshIcon(s, "search", FL_NORMAL_SIZE);
  s->box(FL_FLAT_BOX);
  s->callback(cb);
  s->when(FL_WHEN_CHANGED | FL_WHEN_ENTER_KEY_ALWAYS);
  o->resizable(s);
  o->end();
  return s;
}

#endif
