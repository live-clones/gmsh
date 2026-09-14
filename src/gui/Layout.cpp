// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>

#include "Layout.h"

namespace Ui {

  namespace {

    double _text(const Metrics &m, const std::string &s)
    {
      return (m.textWidth && s.size()) ? m.textWidth(s) : 0.;
    }

    double _natural(const Metrics &m, const Field &f, bool packed)
    {
      return m.naturalWidth ? m.naturalWidth(f, packed) : -1.;
    }

    // A field that is not there takes no room: the tree of the visibility
    // window and the button offered instead of it when the model is too big
    // are never both shown, and the window is as wide as the one that is.
    bool _hidden(const Field &f) { return f.visible && !f.visible(); }

    // whether the field carries its label inside rather than after it: what
    // comes off the last cell of a grid row is then the whole field, not the
    // label alone
    bool _labelInside(const Field &f)
    {
      return f.kind == Check || f.kind == Action || f.kind == Menu ||
             f.kind == Label || f.kind == Direction ||
             (f.kind == Choice && f.multiple);
    }

    // how much of a line the packed fields take, spacing included
    double _packedTotal(const std::vector<Field> &fields, std::size_t from,
                        std::size_t to, const Metrics &m)
    {
      double total = 0.;
      for(std::size_t k = from; k < to; k++)
        if(fields[k].packed || fields[k].kind == Spacer)
          total += packedStep(fields, k, to, m);
      return total;
    }

    // What a field sharing its line out equally with the others on it needs:
    // one that sizes itself takes what it says, the others an ordinary
    // width -- half of one when the line is shared -- and their label after
    // it.
    double _cellWidth(const Field &f, int columns, const Metrics &m)
    {
      double w = _natural(m, f, false);
      if(w < 0.) {
        w = f.widthEm > 0. ? f.widthEm :
            columns > 1    ? m.field / 2. :
                             m.field;
        // A dropdown keeps its arrow inside the box, at the right end, and
        // the text has to fit beside it. One sharing a line takes the arrow
        // on top of its share rather than out of its text, which is what the
        // windows this replaces do -- alone on its line it has room already.
        if(f.kind == Choice && !f.multiple && columns > 1) w += m.arrow;
        // the button that offers what one may type
        if(f.kind == Text && f.dynamicChoices) w += m.offer;
        w += m.labelGap + _text(m, f.label);
      }
      return w + m.column;
    }

    // What one line needs, labels included: what is left of it once the
    // packed fields have taken theirs is shared out equally, so every column
    // has to be as wide as the one that needs the most.
    double _rowWidth(const std::vector<Field> &fields, std::size_t from,
                     std::size_t to, const Metrics &m)
    {
      int columns = 0;
      for(std::size_t k = from; k < to; k++)
        if(!fields[k].packed && fields[k].kind != Spacer) columns++;
      double widest = 0.;
      for(std::size_t k = from; k < to; k++) {
        const Field &f = fields[k];
        if(f.packed || f.kind == Spacer || _hidden(f)) continue;
        widest = std::max(widest, _cellWidth(f, columns, m));
      }
      return widest * columns + _packedTotal(fields, from, to, m);
    }

    // What a pane laid out on a grid needs: the columns together, and
    // whatever the last label of a row adds past its column.
    double _gridWidth(const std::vector<Field> &fields, int grid,
                      const Metrics &m)
    {
      std::vector<double> column = gridColumns(fields, grid, m);
      double widest = 0., at = 0.;
      int which = 0;
      for(std::size_t k = 0; k < fields.size(); k++) {
        const Field &f = fields[k];
        // what a spacer pushes to the right end of a line does not start at
        // a column: the line only has to be as wide as what is really on it
        bool loose = k && f.sameRow && fields[k - 1].kind == Spacer;
        if(!f.sameRow) {
          which = 0;
          at = 0.;
        }
        else if(loose) {
          // it goes on from where the field before the spacer ended
        }
        else if(!f.packed) {
          which++;
          at = 0.;
          for(int c = 0; c < which && c < grid; c++)
            at += column[(std::size_t)c];
        }
        // a spacer takes at least what it asks for, and what follows it
        // comes after that: a row ending in one is as wide as all of them
        // together
        if(f.kind == Spacer) {
          at += packedWidth(f, m) + m.gap;
          continue;
        }
        widest = std::max(widest, at + packedWidth(f, m) + m.after);
        // what follows it on the same line starts where it ends, whether it
        // is packed against it or pushed to the right end by a spacer
        bool more = k + 1 < fields.size() && fields[k + 1].sameRow;
        if(more && (f.packed || fields[k + 1].kind == Spacer))
          at += packedWidth(f, m) + m.gap;
      }
      return widest;
    }

  } // namespace

  bool sharesCell(const std::vector<Field> &fields, std::size_t k,
                  std::size_t to)
  {
    return fields[k].widthShare > 0. && k + 1 < to &&
           fields[k + 1].widthShare > 0.;
  }

  double packedWidth(const Field &f, const Metrics &m)
  {
    if(f.kind == Spacer) return f.widthEm > 0. ? f.widthEm : 2.;
    // A line that says how wide it is takes that, so that a column of keys
    // is a column; one that wraps takes the width of an ordinary field,
    // whatever it says.
    if(f.kind == Label) {
      if(f.widthEm > 0.) return f.widthEm;
      if(f.wraps) return m.field;
    }
    // one that carries its text inside and says how wide it is takes that
    if(f.kind == Action || f.kind == Menu ||
       (f.kind == Choice && f.multiple)) {
      if(f.widthShare > 0.) return f.widthShare * m.field;
      if(f.widthEm > 0.) return f.widthEm;
    }
    double natural = _natural(m, f, true);
    if(natural >= 0.) return natural;
    // a declared width, or the usual one, plus the label it carries
    double w = f.widthShare > 0. ? f.widthShare * m.field :
               f.widthEm > 0.    ? f.widthEm :
                                   m.field;
    return w + m.labelGap + _text(m, f.label);
  }

  double packedStep(const std::vector<Field> &fields, std::size_t k,
                    std::size_t to, const Metrics &m)
  {
    if(sharesCell(fields, k, to)) return fields[k].widthShare * m.field;
    return packedWidth(fields[k], m) + m.gap;
  }

  std::vector<double> gridColumns(const std::vector<Field> &fields, int grid,
                                  const Metrics &m)
  {
    std::vector<double> width((std::size_t)(grid > 0 ? grid : 1), 0.);
    int column = 0;
    for(std::size_t k = 0; k < fields.size(); k++) {
      const Field &f = fields[k];
      if(!f.sameRow)
        column = 0;
      else if(!f.packed)
        column++;
      if(column >= (int)width.size()) column = (int)width.size() - 1;
      if(f.kind == Spacer || _hidden(f)) continue;
      // where the line this field is on ends, so that the cells packed
      // against it can be stepped over the way they are placed
      std::size_t end = k + 1;
      while(end < fields.size() && fields[end].sameRow) end++;
      // What follows it inside the same column adds to it.
      double need = 0.;
      std::size_t j = k;
      while(j < fields.size() &&
            (j == k || (fields[j].sameRow && fields[j].packed))) {
        bool last = !(j + 1 < fields.size() && fields[j + 1].sameRow &&
                      fields[j + 1].packed);
        need += last ? packedWidth(fields[j], m) + m.after :
                       packedStep(fields, j, end, m);
        j++;
      }
      if(!(j < fields.size() && fields[j].sameRow)) {
        // Its label only needs room if another column follows on the same
        // row: the label of the last field of a row runs on into the space
        // no one else uses, which is what keeps the columns as narrow as the
        // window this replaces has them. One that carries its text inside
        // comes off whole -- a line of a pane that is nothing but a switch
        // is as wide as the switch says, and that is no reason to push the
        // second column of every other line across.
        const Field &l = fields[j - 1];
        if(_labelInside(l))
          need -= packedWidth(l, m) + m.after;
        else
          need -= _text(m, l.label) + m.labelGap;
      }
      width[(std::size_t)column] = std::max(width[(std::size_t)column], need);
    }
    return width;
  }

  double neededWidth(const std::vector<Field> &fields, int columns,
                     const Metrics &m)
  {
    if(columns > 0) return _gridWidth(fields, columns, m);
    double widest = 0.;
    std::size_t i = 0;
    while(i < fields.size()) {
      std::size_t last = i + 1;
      while(last < fields.size() && fields[last].sameRow) last++;
      widest = std::max(widest, _rowWidth(fields, i, last, m));
      i = last;
    }
    return widest;
  }

} // namespace Ui
