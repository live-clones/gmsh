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
// A description says which fields share a line, which are packed against
// their neighbours, which take a declared width and which a share of an
// ordinary one; and each interface was reading those same few notions and
// adding them up in its own arithmetic -- the same walk over the same
// fields, written three times, and drifting apart wherever one of them was
// corrected. This is that walk, written once. It speaks in em -- multiples of
// the size of the type -- because that is the one unit the description
// speaks in, and it knows nothing of what a field looks like: what a check
// box is wide, what a button adds around its text, how far a label stands
// from its field, are facts of a toolkit, and the toolkit says them through
// Metrics.
//
// What it knows is the layout Form.h can say, and no more than that: the
// notions are listed in the plan (§2.1) and the list is closed. The day one
// wants text that reflows, a width in percent of the parent, or a pane inside
// a pane at any depth, what is wanted is a layout engine, and this is not the
// beginning of one.
//
// For now it measures width only, which is the part the interfaces disagreed
// about; the height, and then the placing of every box, follow in the order
// the plan gives (§2.4).

namespace Ui {

  // What the toolkit knows and the solver does not, in em.
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
    // The width of a field that sizes itself -- a button, a check box, a
    // swatch, a line of text -- label included when it carries one; below
    // zero for a field that is given an ordinary width and its label after
    // it. Whether the field is packed is passed because the interfaces
    // measure some kinds differently packed and not; the solver does not,
    // and the argument goes when their placers do (plan §2.4.3-4).
    std::function<double(const Field &, bool packed)> naturalWidth;
    Metrics()
      : field(10.), gap(0.), labelGap(0.), column(0.), after(0.), arrow(0.),
        offer(0.)
    {
    }
  };

  // Whether the field at k shares its cell with the one after it: consecutive
  // fields that declare a share of a field's width are one cell, and all but
  // the last of them sit flush against the next, so that the cell measures
  // exactly what one field would.
  bool sharesCell(const std::vector<Field> &fields, std::size_t k,
                  std::size_t to);

  // what a packed field needs, its label included
  double packedWidth(const Field &f, const Metrics &m);

  // how far the next field starts from this one, when this one is packed
  double packedStep(const std::vector<Field> &fields, std::size_t k,
                    std::size_t to, const Metrics &m);

  // How wide each column of a pane laid out on a grid is: a column is as wide
  // as the widest thing in it, its label included, and not as wide as the
  // widest thing in the pane.
  std::vector<double> gridColumns(const std::vector<Field> &fields, int grid,
                                  const Metrics &m);

  // What a list of fields needs: the busiest of its lines, on a grid of that
  // many columns or, for zero, with each line shared out among what is on it.
  double neededWidth(const std::vector<Field> &fields, int columns,
                     const Metrics &m);

} // namespace Ui

#endif
