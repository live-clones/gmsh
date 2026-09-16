// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>

#include "Layout.h"

namespace Ui {

  namespace {

    double _text(const Metrics &m, const std::string &s)
    {
      return (m.textWidth && s.size()) ? m.textWidth(s) : 0.;
    }

    // whether the field carries its label inside rather than after it
    bool _labelInside(const Field &f)
    {
      return f.kind == Check || f.kind == Action || f.kind == Menu ||
             f.kind == Label || f.kind == Direction ||
             (f.kind == Choice && f.multiple);
    }

    double _widget(const Metrics &m, const Field &f)
    {
      return m.widgetWidth ? m.widgetWidth(f) : -1.;
    }

    // a field that is not there takes no room
    bool _hidden(const Field &f) { return f.visible && !f.visible(); }

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

    // what a field sharing its line out equally with the others on it needs:
    // one that sizes itself takes what it says, the others an ordinary width
    // -- half of one when the line is shared -- and their label after it
    double _cellWidth(const Field &f, int columns, const Metrics &m)
    {
      double w = _widget(m, f);
      if(w < 0.) {
        w = f.widthEm > 0. ? f.widthEm :
            columns > 1    ? m.field / 2. :
                             m.field;
        // a dropdown sharing a line takes its arrow on top of its share rather
        // than out of its text; alone on its line it has room already
        if(f.kind == Choice && !f.multiple && columns > 1) w += m.arrow;
        // the button that offers what one may type
        if(f.kind == Text && f.dynamicChoices) w += m.offer;
      }
      // and what it is called, unless the widget writes that itself
      if(!_labelInside(f)) w += m.labelGap + _text(m, f.label);
      return w + m.column;
    }

    // what one line needs, labels included: what is left once the packed
    // fields have taken theirs is shared out equally, so every column has to
    // be as wide as the one that needs the most
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
        // what a spacer pushes to the right end of a line does not start at a
        // column
        bool loose = k && f.sameRow && fields[k - 1].kind == Spacer;
        if(!f.sameRow) {
          which = 0;
          at = 0.;
        }
        else if(loose) {
        }
        else if(!f.packed) {
          which++;
          at = 0.;
          for(int c = 0; c < which && c < grid; c++)
            at += column[(std::size_t)c];
        }
        // a spacer takes at least what it asks for
        if(f.kind == Spacer) {
          at += packedWidth(f, m) + m.gap;
          continue;
        }
        widest = std::max(widest, at + packedWidth(f, m) + m.after);
        bool more = k + 1 < fields.size() && fields[k + 1].sameRow;
        if(more && (f.packed || fields[k + 1].kind == Spacer))
          at += packedWidth(f, m) + m.gap;
      }
      return widest;
    }

    bool _tallKind(const Field &f)
    {
      return f.kind == List || f.kind == Hierarchy || f.kind == ColorMap ||
             (f.kind == Label && f.wraps);
    }

    // how many lines a field takes
    int _linesOf(const Field &f, const Metrics &m)
    {
      if(f.kind == Prose) {
        double tall = m.naturalHeight ? m.naturalHeight(f) : -1.;
        return tall >= 1. ? (int)tall : 1;
      }
      return _tallKind(f) ? std::max(f.rows, 1) : 1;
    }

    // how wide the widget of a field is before what the field itself
    // declares: what the toolkit says for the kinds that size themselves, an
    // ordinary width for the others, half of one on a shared line
    double _kindWidth(const Field &f, int columns, const Metrics &m)
    {
      if(f.kind == Spacer) return 0.;
      if(f.kind == ColorMap) return m.field;
      if(f.kind == Label) {
        if(f.widthEm > 0.) return m.snap(f.widthEm);
        if(f.wraps) return m.field;
      }
      // a declared width overrides what the toolkit says, except for the kinds
      // whose width is not a length of text: the disc is square
      if(f.kind != Direction && f.widthEm > 0. && f.kind != Label &&
         f.kind != Action && f.kind != Menu && f.kind != Check &&
         !f.disclosure)
        return m.snap(f.widthEm);
      double w = _widget(m, f);
      if(w >= 0.) return w;
      if(f.kind == Direction) return f.rows * m.row;
      double usual = (columns == 1) ? m.field : m.field / 2.;
      if(f.kind == Choice && !f.multiple && columns > 1) usual += m.arrow;
      return usual;
    }

    double _widgetWidth(const Field &f, int columns, const Metrics &m)
    {
      if(f.widthShare > 0.) return m.snap(f.widthShare * m.field);
      if(f.widthEm > 0.) return m.snap(f.widthEm);
      return _kindWidth(f, columns, m);
    }

    // what a line asks of each of the columns it is shared out in; hidden
    // fields still hold their share of the line
    double _columnWidth(const std::vector<Field> &fields, std::size_t from,
                        std::size_t to, const Metrics &m, int &columns)
    {
      columns = 0;
      for(std::size_t k = from; k < to; k++)
        if(!fields[k].packed && fields[k].kind != Spacer) columns++;
      double widest = 0.;
      for(std::size_t k = from; k < to; k++) {
        const Field &f = fields[k];
        if(f.packed || f.kind == Spacer || _hidden(f)) continue;
        double w = _kindWidth(f, columns ? columns : 1, m);
        // and what it is called, unless the widget writes that itself
        if(!_labelInside(f)) w += m.labelGap + _text(m, f.label);
        widest = std::max(widest, w + m.column);
      }
      return widest;
    }

    // how much room the labels written before their field take, column by
    // column: the fields of a column line up after the widest of them
    std::vector<double> _labelsBefore(const std::vector<Field> &fields,
                                      int grid, const Metrics &m)
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
        if(!f.labelBefore || f.label.empty()) continue;
        width[(std::size_t)column] =
          std::max(width[(std::size_t)column], _text(m, f.label) + m.gap);
      }
      return width;
    }

    // whether a line only does something: buttons, and the room around them
    bool _acts(const std::vector<Field> &fields, std::size_t from,
               std::size_t to)
    {
      for(std::size_t k = from; k < to; k++)
        if(fields[k].kind != Action && fields[k].kind != Menu &&
           fields[k].kind != Spacer)
          return false;
      return true;
    }

    // whether nothing on the line is there
    bool _empty(const std::vector<Field> &fields, std::size_t from,
                std::size_t to)
    {
      for(std::size_t k = from; k < to; k++)
        if(!_hidden(fields[k])) return false;
      return true;
    }

    // what the lines under this one take, for a field that fills what is left
    // of the list and has to leave them their room
    double _roomUnder(const std::vector<Field> &fields, std::size_t from,
                      const Metrics &m)
    {
      double under = 0.;
      bool wasValues = true;
      std::size_t i = from;
      while(i < fields.size()) {
        std::size_t last = i + 1;
        while(last < fields.size() && fields[last].sameRow) last++;
        if(!_empty(fields, i, last)) {
          bool acts = _acts(fields, i, last);
          if(acts && wasValues) under += m.gap;
          wasValues = !acts;
          int tall = 1;
          for(std::size_t k = i; k < last; k++)
            tall = std::max(tall, _linesOf(fields[k], m));
          under += tall * m.row;
        }
        i = last;
      }
      return under;
    }

  } // namespace

  double Metrics::snap(double v) const
  {
    if(pixel <= 0.) return v;
    return std::floor(v / pixel + 1e-9) * pixel;
  }

  bool sharesCell(const std::vector<Field> &fields, std::size_t k,
                  std::size_t to)
  {
    return fields[k].widthShare > 0. && k + 1 < to &&
           fields[k + 1].widthShare > 0.;
  }

  // whether a field is a cell of a line with nothing between its cells
  static bool _cell(const Field &f)
  {
    return f.widthShare > 0. || f.flush;
  }

  double packedWidth(const Field &f, const Metrics &m)
  {
    // a spacer with a share is an empty cell of that width
    if(f.kind == Spacer)
      return f.widthShare > 0. ? f.widthShare * m.field :
             f.widthEm > 0.    ? f.widthEm :
                                 2.;
    // a label that says how wide it is takes that; one that wraps takes the
    // width of an ordinary field, whatever it says
    if(f.kind == Label) {
      if(f.widthShare > 0.) return f.widthShare * m.field;
      if(f.widthEm > 0.) return f.widthEm;
      if(f.wraps) return m.field;
    }
    if(f.kind == Action || f.kind == Menu ||
       (f.kind == Choice && f.multiple)) {
      if(f.widthShare > 0.) return f.widthShare * m.field;
      if(f.widthEm > 0.) return f.widthEm;
    }
    double w = _widget(m, f);
    if(w < 0.)
      w = f.widthShare > 0. ? f.widthShare * m.field :
          f.widthEm > 0.    ? f.widthEm :
                              m.field;
    // and what it is called, unless the widget writes that itself; a cell
    // with nothing between it and the next has no room for a name it has
    // not got
    if(!_labelInside(f) && !(f.flush && f.label.empty()))
      w += m.labelGap + _text(m, f.label);
    return w;
  }

  double packedStep(const std::vector<Field> &fields, std::size_t k,
                    std::size_t to, const Metrics &m)
  {
    if(sharesCell(fields, k, to)) return fields[k].widthShare * m.field;
    if(fields[k].flush) return packedWidth(fields[k], m);
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
      // where the line this field is on ends
      std::size_t end = k + 1;
      while(end < fields.size() && fields[end].sameRow) end++;
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
        // Its label only needs room if another column follows on the same row:
        // the label of the last field of a row runs on into the space no one else
        // uses. One that carries its text inside comes off whole.
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

  int neededRows(const std::vector<Field> &fields, const Metrics &m)
  {
    int rows = 0;
    for(std::size_t i = 0; i < fields.size(); i++) {
      const Field &f = fields[i];
      if(f.sameRow && i) continue;
      if(_hidden(f)) continue;
      // the kinds that are as tall as they say are worth as many lines as they
      // show, and one that fills what is left counts for none
      if(_tallKind(f) && !f.rows) continue;
      rows += _linesOf(f, m);
    }
    return rows;
  }

  Placed place(const std::vector<Field> &fields, int grid, const Metrics &m,
               const Room &room)
  {
    Placed out;
    double y = 0.;
    std::size_t row = 0;
    bool wasValues = false;
    std::vector<double> before = _labelsBefore(fields, grid, m);
    std::vector<double> gridW;
    if(grid > 0) gridW = gridColumns(fields, grid, m);
    std::size_t i = 0;
    while(i < fields.size()) {
      std::size_t last = i + 1;
      while(last < fields.size() && fields[last].sameRow) last++;
      // a line with nothing on it is not there, and neither is its room
      if(_empty(fields, i, last)) {
        i = last;
        continue;
      }
      // a line that only does something is set apart from the values above it:
      // pressed by mistake it acts
      bool acts = _acts(fields, i, last);
      if(acts && wasValues) y += m.gap;
      wasValues = !acts;
      // a packed field takes what it needs from where it stands, a spacer eats
      // what is left; with no spacer, the columns share the slack
      int columns = 0, spacers = 0;
      double columnW = _columnWidth(fields, i, last, m, columns);
      // a spacer with a share is an empty cell, not a spring
      for(std::size_t k = i; k < last; k++)
        if(fields[k].kind == Spacer && !_cell(fields[k])) spacers++;
      double packed = _packedTotal(fields, i, last, m);
      double slack = room.width - packed - columns * columnW;
      if(slack < 0.) slack = 0.;
      if(!spacers && columns) columnW += m.snap(slack / columns);
      double spacerW = spacers ? m.snap(slack / spacers) : 0.;
      double at = 0.;
      int gridColumn = 0; // the column the next field goes in, on this line
      for(std::size_t k = i; k < last; k++) {
        const Field &f = fields[k];
        if(_hidden(f)) continue;
        if(f.kind == Spacer) {
          if(_cell(f))
            at += packedStep(fields, k, last, m);
          else if(grid > 0) {
            // what a spacer pushes to the right end of a line is not in a column: it
            // is against the right edge, and the columns are for what comes before it
            double tail = -m.gap;
            for(std::size_t j = k + 1; j < last; j++) {
              if(fields[j].kind == Spacer || _hidden(fields[j])) continue;
              tail += packedWidth(fields[j], m) + m.gap;
            }
            double least = at + packedWidth(f, m) + m.gap;
            at = std::max(room.width - tail, least);
          }
          else
            at += packedWidth(f, m) + m.gap + spacerW;
          continue;
        }
        double fieldW = _widgetWidth(f, (grid > 0) ? 1 : (columns ? columns : 1), m);
        // a packed button is as wide as its text and no wider
        if(f.packed && (f.kind == Action || f.kind == Menu))
          fieldW = packedWidth(f, m);
        // On a grid, a cell is a field and whatever is packed against it. A field
        // that begins a cell goes where its column starts, except what a spacer
        // has pushed to the right end of the line.
        bool loose = k > i && fields[k - 1].kind == Spacer;
        if(grid > 0) {
          if(k == i)
            gridColumn = 0;
          else if(!f.packed)
            gridColumn++;
          if(gridColumn >= grid) gridColumn = grid - 1;
        }
        double fx = at;
        if(grid > 0 && !loose && (k == i || !f.packed)) {
          fx = 0.;
          for(int c = 0; c < gridColumn && c < grid; c++)
            fx += gridW[(std::size_t)c];
        }
        // a label written before its field: the field starts after the widest
        // such label of its column
        double labelBefore = 0.;
        if(f.labelBefore && f.label.size()) {
          labelBefore = before[(std::size_t)(grid > 0 ? gridColumn : 0)];
          fx += labelBefore;
        }
        if(room.wide && f.widthEm <= 0. && !_cell(f)) fieldW = room.width - fx;
        if(grid > 0)
          at = fx + (f.packed ? packedStep(fields, k, last, m) :
                                packedWidth(f, m) + m.gap);
        else if(f.packed)
          at += packedStep(fields, k, last, m);
        else
          at += columnW;

        PlacedField p;
        p.index = k;
        p.row = row;
        // the little buttons hung after it take their room out of the field
        for(const auto &t : f.trailing) {
          double wide = m.trailingWidth ? m.trailingWidth(t) : 0.;
          p.trailing.push_back(Rect(0., y, wide, m.row));
          fieldW -= wide;
        }
        // nothing runs into the edge, and nothing is narrower than an em
        if(fx + fieldW > room.width) fieldW = room.width - fx;
        if(fieldW < 1.) fieldW = 1.;
        // Two frames that touch read as one box: a field that shares its cell
        // gives some of its width back, for the toolkit that asks for it. Never
        // more than a quarter of the cell, and never so much that one character
        // no longer fits in the frame.
        if(m.courtesy > 0. && sharesCell(fields, k, last)) {
          double give = std::min(m.courtesy, fieldW * .25);
          double least = _text(m, "0") + 2. * m.framePad;
          if(fieldW - give < least) give = std::max(0., fieldW - least);
          fieldW -= give;
        }

        Rect b(fx, y, fieldW, m.row);
        switch(f.kind) {
        case Check:
          if(!f.disclosure)
            b.w = f.packed ? packedWidth(f, m) : columnW - m.gap;
          break;
        case Label:
          // On a grid, or when it says how wide it is, no wider than that;
          // on its own line it runs to the edge; one that wraps is worth the
          // lines it says.
          b.w = ((grid > 0 || f.packed || f.widthEm > 0. || _cell(f)) &&
                 !f.wraps) ?
                  fieldW :
                  room.width - fx;
          b.h = (f.wraps && f.rows > 1) ? f.rows * m.row : m.row;
          break;
        case Prose: {
          double tall = m.naturalHeight ? m.naturalHeight(f) : -1.;
          b.h = (tall >= 0. ? (int)tall : 1) * m.row;
        } break;
        case List:
        case Hierarchy: {
          // as tall as it says or, saying nothing, as there is room for under what
          // comes after it
          double tall = f.rows * m.row;
          if(!f.rows) {
            tall = room.height - y - _roomUnder(fields, last, m);
            if(tall < m.row) tall = m.row;
          }
          b.h = tall;
          if(f.kind == Hierarchy || (f.widthEm <= 0. && f.widthShare <= 0.))
            b.w = room.width - fx;
        } break;
        case ColorMap: {
          double tall = f.rows ? f.rows * m.row : room.height - y;
          if(tall < m.row) tall = m.row;
          b.h = tall;
          b.w = room.width - fx;
        } break;
        case Direction:
          // the disc is square, as tall as the lines it hangs over
          b.w = b.h = f.rows * m.row;
          break;
        default: break;
        }
        p.widget = b;
        double tx = fx + fieldW;
        for(auto &t : p.trailing) {
          t.x = tx;
          tx += t.w;
        }
        // a field that carries buttons has its label written after them, on a box
        // of its own; one that says its label comes first has it written before
        if(f.trailing.size() && f.label.size() && !f.labelBefore)
          p.label = Rect(tx, y, _text(m, f.label) + m.gap, m.row);
        else if(labelBefore > 0.)
          p.label = Rect(fx - labelBefore, y, labelBefore, m.row);
        out.fields.push_back(p);
      }
      int tall = 1;
      double advance = 0.;
      for(std::size_t k = i; k < last; k++) {
        const Field &f = fields[k];
        if(f.kind == Prose) tall = std::max(tall, _linesOf(f, m));
        if(!_tallKind(f)) continue;
        if(f.rows > tall) tall = f.rows;
        if(!f.rows) {
          // one that fills what it is in ends where the room does
          double fill = room.height - y - _roomUnder(fields, last, m);
          advance = std::max(advance, fill);
        }
      }
      advance = std::max(advance, tall * m.row);
      y += advance;
      row += (std::size_t)std::ceil(advance / m.row - 1e-9);
      i = last;
    }
    out.height = y;
    return out;
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
