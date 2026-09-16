// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_LAYOUT_H
#define UI_LAYOUT_H

#include <functional>
#include <string>
#include <vector>

#include "Form.h"

// How much room a form takes, worked out once for every interface.
//
// It speaks in em -- multiples of the size of the type -- the one unit the
// description speaks in, and knows nothing of what a field looks like: what
// a check box is wide, what a button adds around its text, how far a label
// stands from its field, are facts of a toolkit, said through Metrics.
//
// It measures width, counts lines, and places the fields of one list -- a
// pane, a header, the column down the side -- as boxes in em from the top
// left of that list. The pane itself, the row of tabs, the box that scrolls,
// stay the toolkit's.

namespace Ui {

  // what the toolkit knows and the solver does not, in em
  struct Metrics {
    // what an ordinary field is given: a line of text to edit
    double field;
    // between two fields packed on a line
    double gap;
    // between a field and the label written after it
    double labelGap;
    // what a column of a line shared out equally costs beyond the field and
    // its label
    double column;
    // what a field of a grid keeps after it, before the next column starts
    double after;
    // what a dropdown sharing a line takes on top of its share, for its arrow
    double arrow;
    // what the button offering what one may type takes beside a text field
    double offer;
    // how wide a piece of text is
    std::function<double(const std::string &)> textWidth;
    // the height of a line, which is what a field of one line is given
    double row;
    // the least length the toolkit places at, in em: one pixel for a toolkit
    // that places at whole pixels, zero for one that does not; what the solver
    // shares out is cut to it
    double pixel;
    // What the widget of a field is worth, drawn as it is drawn; below zero
    // for a field the toolkit sizes the ordinary way. It carries the text the
    // widget writes itself -- the word on a button, the name beside a check
    // box -- and nothing else.
    std::function<double(const Field &)> widgetWidth;
    // the width of a little button hung after a field
    std::function<double(const Button &)> trailingWidth;
    // What a field sharing its cell gives back out of its own width, so that
    // the eye can tell two frames that touch apart; zero for a toolkit that
    // draws a border around each. Never more than a quarter of the cell, and
    // never so much that one character no longer fits inside the frame.
    double courtesy;
    // what a frame keeps between its edge and its text, on each side
    double framePad;
    // how many lines a field that lays itself out takes, and below zero for
    // one whose height the description says
    std::function<double(const Field &)> naturalHeight;
    Metrics()
      : field(10.), gap(0.), labelGap(0.), column(0.), after(0.), arrow(0.),
        offer(0.), row(2.), pixel(0.), courtesy(0.), framePad(0.)
    {
    }
    // a length cut to what the toolkit places at
    double snap(double v) const;
  };

  // a rectangle in em, from the top left of the list being placed
  struct Rect {
    double x, y, w, h;
    Rect() : x(0.), y(0.), w(0.), h(0.) {}
    Rect(double px, double py, double pw, double ph)
      : x(px), y(py), w(pw), h(ph)
    {
    }
  };

  // where one field of the list went
  struct PlacedField {
    // which field, in the list given
    std::size_t index;
    // the line it is on, counted in lines from the top of the list; the
    // room left above a line that acts is not a line
    std::size_t row;
    // the widget itself, without the buttons hung after it
    Rect widget;
    // those buttons, in order
    std::vector<Rect> trailing;
    // Where the label is written when it is not the widget's to write: after
    // the buttons, for a field that carries some, or before the field, for
    // one that says so. w == 0 when the widget carries its own label.
    Rect label;
    PlacedField() : index(0), row(0) {}
  };

  struct Placed {
    std::vector<PlacedField> fields;
    // what the list takes, from the top of its first line
    double height;
    Placed() : height(0.) {}
  };

  // what the toolkit says of the room the list is given
  struct Room {
    // from the left of the first field to where nothing may reach
    double width;
    // from the top of the first line to where a field that fills what is
    // left of the list ends
    double height;
    // every field takes the whole width unless it says one
    bool wide;
    Room() : width(0.), height(0.), wide(false) {}
  };

  // how many lines a list of fields takes, once those that share one are put
  // together
  int neededRows(const std::vector<Field> &fields, const Metrics &m);

  // Where every field of a list goes, on a grid of that many columns or,
  // for zero, with each line shared out among what is on it: equally among
  // the fields that take an equal share, packed fields taking what they need
  // from where they stand, a spacer eating what is left, and a field that
  // fills what is left of the list ending where the room does.
  Placed place(const std::vector<Field> &fields, int columns, const Metrics &m,
               const Room &room);

  // whether the field at k shares its cell with the one after it:
  // consecutive fields that declare a share of a field's width are one cell,
  // which measures exactly what one field would
  bool sharesCell(const std::vector<Field> &fields, std::size_t k,
                  std::size_t to);

  // what a packed field needs, its label included
  double packedWidth(const Field &f, const Metrics &m);

  // how far the next field starts from this one, when this one is packed
  double packedStep(const std::vector<Field> &fields, std::size_t k,
                    std::size_t to, const Metrics &m);

  // how wide each column of a pane laid out on a grid is: as wide as the
  // widest thing in it, its label included
  std::vector<double> gridColumns(const std::vector<Field> &fields, int grid,
                                  const Metrics &m);

  // what a list of fields needs: the busiest of its lines
  double neededWidth(const std::vector<Field> &fields, int columns,
                     const Metrics &m);

} // namespace Ui

#endif
