// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_GLYPH_H
#define UI_GLYPH_H

#include <string>
#include <vector>

#include "Form.h"

// The little pictures a button may show instead of its label (Button::glyph,
// BarButton::glyph), described once as strokes and drawn by every interface:
// FLTK makes symbols of them, the others draw them with their painter; the
// terminal writes the character that looks most like each.
//
// A glyph is drawn in the square -1..1 as FLTK draws a symbol: x to the
// right, y down, the square set in the middle of the button, in the colour of
// the button's text unless a stroke says its own.

namespace Ui {

  struct Stroke {
    // an open line, a closed one, a filled shape
    enum Kind { Line, Loop, Fill };
    Kind kind;
    // x0, y0, x1, y1... ; arcs are already made of points
    std::vector<double> points;
    // in lines of the thinnest the interface draws
    double width;
    // of its own, not that of the text, when its alpha is not zero
    Colour colour;
    Stroke() : kind(Line), width(1.), colour(0, 0, 0, 0) {}
  };

  struct Glyph {
    std::string name;
    std::vector<Stroke> strokes;
    // what looks most like it in a line of text
    std::string text;
  };

  // null for a name no glyph has
  const Glyph *glyph(const std::string &name);
  // all of them, for an interface that makes them once
  const std::vector<Glyph> &glyphs();

} // namespace Ui

#endif
