// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>

#include "Layout.h"

namespace Ui {

  bool fills(const Item &it)
  {
    if(it.kind == Item::AField)
      return (it.field.kind == List || it.field.kind == Hierarchy ||
              it.field.kind == ColorMap) &&
             !it.field.rows;
    if(it.kind != Item::ABox) return false;
    if(it.box->scrolling) return true;
    for(const Item &i : it.box->items)
      if(fills(i)) return true;
    return false;
  }

  bool aloneInColumn(const Placement &p)
  {
    int shown = 0;
    for(const PlacedItem &q : p.items)
      if(q.aside && !q.hidden) shown++;
    return shown == 1;
  }

  namespace {

    // what a heading is to a toolkit: a line of text in its heading font
    Field _heading(const std::string &text)
    {
      Field f;
      f.kind = Label;
      f.heading = true;
      f.readText = [text]() { return text; };
      return f;
    }

    // the tree as flex and grid see it: containers of cells, each a flex
    // item with what it grows, shrinks and starts from
    struct Node {
      enum Kind { Row, Column, Grid, Stack, Widget, Text, Trailing, Rule, Space };
      Kind kind;
      // what it stands for, and for the parts of a field's cell which part
      enum Part { Whole, TheWidget, TheLabel, TheTrailing };
      const Item *item;
      Part part;
      std::size_t trailing;
      // as a flex item: basis below zero is its content
      double grow, shrink, basis;
      bool stretch;
      // as a container; a grid has a gap between its rows too
      double gap, rowGap, padX, padY;
      int columns;
      // a column that scrolls, and the scrollbar it keeps at its right
      bool scrolls;
      double bar;
      double least;
      bool hidden;
      // a column beside the rest of its line
      bool aside;
      std::vector<Node> kids;
      Size content;
      Rect at;
      Node(Kind k = Row)
        : kind(k), item(nullptr), part(Whole), trailing(0), grow(0.),
          shrink(1.), basis(-1.), stretch(false), gap(0.), rowGap(0.), padX(0.),
          padY(0.), columns(0), scrolls(false), bar(0.), least(0.),
          hidden(false), aside(false)
      {
      }
    };

    bool _value(const Field &f)
    {
      return f.kind == Text || f.kind == Integer || f.kind == Number ||
             f.kind == Output || (f.kind == Choice && !f.multiple);
    }

    bool _whole(const Field &f)
    {
      return f.kind == List || f.kind == Hierarchy || f.kind == Prose ||
             f.kind == ColorMap;
    }

    bool _hidden(const Field &f) { return f.visible && !f.visible(); }

    // the widget writes its own name
    bool _labelInside(const Field &f)
    {
      return f.kind == Check || f.kind == Action || f.kind == Menu ||
             f.kind == Label || f.kind == Direction || f.kind == ColorMap ||
             f.kind == Hierarchy || f.kind == Prose ||
             (f.kind == Choice && f.multiple);
    }

    // --- the tree, built

    struct Builder {
      const Metrics &m;
      double least;
      Builder(const Metrics &metrics, int leastRows)
        : m(metrics), least(leastRows * (metrics.row + 2. * metrics.linePad))
      {
      }

      // the widget of a field, in a line where `sharing` values share the
      // width of one
      Node widget(const Field &f, const Item &it, int sharing)
      {
        Node n(Node::Widget);
        n.item = &it;
        n.part = Node::TheWidget;
        Size own = m.widget ? m.widget(f) : Size(-1., m.row);
        double w = f.widthEm > 0.      ? f.widthEm :
                   f.widthShare > 0.   ? f.widthShare * m.field :
                   own.w >= 0.         ? own.w :
                   sharing > 1         ? m.field / sharing :
                                         m.field;
        if(f.kind == Choice && !f.multiple && sharing > 1 && f.widthEm <= 0. &&
           f.widthShare <= 0.)
          w += 1.8;
        double h = own.h > 0. ? own.h : m.row;
        switch(f.kind) {
        case List:
        case Hierarchy:
          h = f.rows ? f.rows * m.line : 5. * m.line;
          if(f.widthEm <= 0. && f.widthShare <= 0.) n.grow = 1.;
          if(!f.rows) n.stretch = true;
          break;
        case ColorMap:
          h = f.rows ? f.rows * m.row : 8.;
          n.grow = 1.;
          if(!f.rows) n.stretch = true;
          break;
        case Prose:
          if(f.widthEm <= 0.) w = m.field;
          h = m.proseHeight ? m.proseHeight(f, w) : m.row;
          break;
        // a line of text, as tall as one, as on the page
        case Label:
          if(f.wraps && f.widthEm <= 0. && f.widthShare <= 0.) w = m.field;
          h = std::max(f.wraps ? f.rows : 1, 1) * m.line;
          break;
        case Direction: h = w = std::max(f.rows, 1) * m.row; break;
        case Action:
          if(f.hangs) n.stretch = true;
          break;
        default: break;
        }
        n.content = Size(w, h);
        return n;
      }

      Node text(const std::string &said, const Item &it, Node::Part part)
      {
        Node n(Node::Text);
        n.item = &it;
        n.part = part;
        n.content = Size(m.textWidth ? m.textWidth(said) : 0., m.row);
        return n;
      }

      // [widget][buttons after][name], or the name first
      Node cell(const Item &it, int sharing)
      {
        const Field &f = it.field;
        Node c(Node::Row);
        c.item = &it;
        c.gap = m.cellGap;
        c.hidden = _hidden(f);
        if(f.kind == Spacer) {
          c.kind = Node::Space;
          c.grow = c.shrink = 1.;
          c.basis = f.widthEm > 0. ? f.widthEm : 2.;
          return c;
        }
        if(f.packed) c.shrink = 0.;
        bool whole = _whole(f) && f.widthEm <= 0. && f.widthShare <= 0.;
        if(whole) c.grow = 1.;
        Node w = widget(f, it, sharing);
        // and what it holds with it
        if(whole) w.grow = 1.;
        // a label set in the middle or at the end of its line runs the width
        // of it
        if(f.kind == Label && f.align != Left && f.widthEm <= 0. &&
           f.widthShare <= 0.)
          c.grow = w.grow = 1.;
        if(w.stretch) c.stretch = true;
        bool named = f.label.size() && !_labelInside(f);
        if(named && f.labelBefore) c.kids.push_back(text(f.label, it, Node::TheLabel));
        c.kids.push_back(w);
        for(std::size_t k = 0; k < f.trailing.size(); k++) {
          Node t(Node::Trailing);
          t.item = &it;
          t.part = Node::TheTrailing;
          t.trailing = k;
          t.content = Size(m.row, m.row);
          c.kids.push_back(t);
        }
        if(named && !f.labelBefore) c.kids.push_back(text(f.label, it, Node::TheLabel));
        return c;
      }

      // how many values of a line share the width of one
      static int sharing(const std::vector<const Item *> &cells)
      {
        int n = 0;
        for(const Item *c : cells)
          if(c->kind == Item::AField && _value(c->field) &&
             c->field.widthEm <= 0. && c->field.widthShare <= 0. &&
             !_hidden(c->field))
            n++;
        return n;
      }

      // the cells of an across box, those of one inside it with them
      static void cellsOf(const Box &b, std::vector<const Item *> &cells)
      {
        for(const Item &i : b.items) {
          if(i.kind == Item::ABox && i.box->direction == Box::Across &&
             !i.box->grid && !i.box->scrolling && !i.box->visible &&
             !fills(i))
            cellsOf(*i.box, cells);
          else
            cells.push_back(&i);
        }
      }

      // a run of tight cells is one thing, glued together -- a gap only
      // after one that says what it is, so that three snaps each named
      // after its axis stand off from one another
      static bool tight(const Item *c)
      {
        return c->kind == Item::AField && c->field.packed &&
               c->field.kind != Spacer && !c->field.disclosure;
      }

      void runs(const std::vector<const Item *> &cells, int share,
                std::vector<Node> &out)
      {
        Node *run = nullptr;
        bool said = false;
        for(const Item *c : cells) {
          if(!tight(c)) {
            run = nullptr;
            out.push_back(cell(*c, share));
            continue;
          }
          if(!run) {
            out.push_back(Node(Node::Row));
            run = &out.back();
            run->shrink = 0.;
            said = false;
          }
          if(said) {
            Node space(Node::Space);
            space.basis = m.gap;
            space.grow = space.shrink = 0.;
            run->kids.push_back(space);
          }
          said = c->field.label.size() > 0;
          run->kids.push_back(cell(*c, share));
        }
      }

      // one line: a row of cells, padded like the page's lines; a cell that
      // fills the height is a column, and the line runs the height beside it
      Node line(const std::vector<const Item *> &cells, double gap, bool hidden)
      {
        Node l(Node::Row);
        l.gap = gap;
        l.padX = l.padY = m.linePad;
        l.hidden = hidden;
        bool grows = false, column = false, spaced = false;
        for(const Item *c : cells) {
          if(fills(*c)) grows = true;
          if(c->kind == Item::AField && c->field.kind == Spacer) spaced = true;
        }
        for(const Item *c : cells)
          if(grows && !fills(*c) &&
             !(c->kind == Item::AField && c->field.kind == Spacer))
            column = true;
        if(grows) {
          l.grow = 1.;
          l.least = least;
        }
        // a column runs to the edges; what is beside it stands off from it by
        // the room a line keeps
        if(column) {
          l.padX = l.padY = 0.;
          l.gap = std::min(gap, m.linePad);
        }
        int share = sharing(cells);
        std::vector<const Item *> plain;
        auto flush = [&]() {
          runs(plain, share, l.kids);
          plain.clear();
        };
        for(const Item *c : cells) {
          if(c->kind == Item::AField && !(column && fills(*c))) {
            plain.push_back(c);
            continue;
          }
          flush();
          Node k = box(*c);
          if(column && fills(*c)) {
            // a column: as wide as its lines, the height of the line, its
            // buttons as wide as it
            k.grow = k.shrink = 0.;
            k.stretch = true;
            k.aside = true;
            widen(k);
          }
          else {
            // what is left of the line, unless a gap takes it
            k.grow = spaced ? 0. : 1.;
            k.shrink = 0.;
          }
          l.kids.push_back(k);
        }
        flush();
        if(column)
          for(Node &k : l.kids) k.stretch = true;
        return l;
      }

      // the lines of a down box, one under another; a box inside that is
      // only lines adds its own
      void lines(const Box &b, Node &into, bool hidden)
      {
        for(const Item &i : b.items) {
          switch(i.kind) {
          case Item::AField: lineOf(i, into, hidden); break;
          case Item::ABox: {
            const Box &box = *i.box;
            bool folded = hidden || (box.visible && !box.visible());
            if(box.direction == Box::Across && !box.grid && !box.scrolling) {
              std::vector<const Item *> cells;
              cellsOf(box, cells);
              Node l = line(cells, box.padding == 0. ? 0. : m.gap, folded);
              into.kids.push_back(l);
            }
            else if(box.direction == Box::Down && !box.grid && !box.scrolling)
              lines(box, into, folded);
            else {
              Node k = this->box(i);
              k.hidden = folded;
              into.kids.push_back(k);
            }
          } break;
          case Item::ATabs: {
            Node k = tabs(i);
            k.hidden = hidden;
            into.kids.push_back(k);
          } break;
          case Item::AHeading:
          case Item::ARule: into.kids.push_back(said(i, hidden)); break;
          default: break;
          }
        }
      }

      // a heading, a line of its own, or a rule, the room between two
      // lines; either runs the width of what it is in
      Node said(const Item &i, bool hidden)
      {
        if(i.kind == Item::ARule) {
          Node r(Node::Rule);
          r.item = &i;
          r.hidden = hidden;
          r.content = Size(0., m.rule);
          return r;
        }
        Node l(Node::Row);
        l.padX = l.padY = m.linePad;
        l.hidden = hidden;
        Node t(Node::Text);
        t.item = &i;
        double w = m.widget ? m.widget(_heading(i.text)).w : -1.;
        if(w < 0.) w = m.textWidth ? m.textWidth(i.text) : 0.;
        t.content = Size(w, m.line);
        l.kids.push_back(t);
        return l;
      }

      // a field alone on a line; a gap down a column eats what is left of its
      // height
      void lineOf(const Item &i, Node &into, bool hidden)
      {
        if(i.kind == Item::AHeading || i.kind == Item::ARule) {
          into.kids.push_back(said(i, hidden));
          return;
        }
        if(i.field.kind == Spacer) {
          Node c = cell(i, 0);
          c.basis = 0.;
          c.hidden = c.hidden || hidden;
          into.kids.push_back(c);
          return;
        }
        std::vector<const Item *> cells(1, &i);
        into.kids.push_back(line(cells, m.gap, hidden));
      }

      // what is inside a box: its lines down, or the one line it is across
      Node inside(const Item &i)
      {
        Node c(Node::Column);
        if(i.kind != Item::ABox) {
          lineOf(i, c, false);
          return c;
        }
        const Box &b = *i.box;
        c.hidden = b.visible && !b.visible();
        if(b.direction == Box::Across) {
          std::vector<const Item *> cells;
          cellsOf(b, cells);
          c.kids.push_back(line(cells, b.padding == 0. ? 0. : m.gap, c.hidden));
        }
        else {
          lines(b, c, c.hidden);
          alignNames(c);
        }
        return c;
      }

      // the buttons of a column take its width
      static void widen(Node &column)
      {
        for(Node &l : column.kids) {
          if(l.kind != Node::Row) continue;
          for(Node &c : l.kids) {
            if(c.kind != Node::Row || c.kids.size() != 1) continue;
            Node &w = c.kids[0];
            if(w.part != Node::TheWidget || !w.item) continue;
            FieldKind kind = w.item->field.kind;
            if(kind != Action && kind != Menu) continue;
            c.grow = w.grow = 1.;
          }
        }
      }

      // the names before their widgets, one under another, are one column
      static void alignNames(Node &column)
      {
        auto named = [](const Node &l) {
          return l.kind == Node::Row && l.kids.size() &&
                 l.kids[0].kids.size() &&
                 l.kids[0].kids[0].part == Node::TheLabel;
        };
        double widest = 0.;
        for(const Node &l : column.kids)
          if(named(l)) widest = std::max(widest, l.kids[0].kids[0].content.w);
        for(Node &l : column.kids)
          if(named(l)) l.kids[0].kids[0].content.w = widest;
      }

      // a box as a container: tabs, a grid, what scrolls, or its inside
      Node box(const Item &i)
      {
        if(i.kind == Item::ATabs) return tabs(i);
        if(i.kind != Item::ABox) return inside(i);
        const Box &b = *i.box;
        Node c;
        if(b.grid) {
          Node g = grid(b);
          g.hidden = b.visible && !b.visible();
          if(!b.scrolling) return g;
          c = Node(Node::Column);
          c.hidden = g.hidden;
          c.kids.push_back(g);
        }
        else
          c = inside(i);
        if(b.scrolling) {
          c.item = &i;
          c.scrolls = true;
          c.bar = m.scrollbar;
          c.grow = 1.;
          c.least = least;
        }
        return c;
      }

      // the rows of a grid, each column as wide as its widest cell
      Node grid(const Box &b)
      {
        Node g(Node::Grid);
        g.gap = m.gap;
        g.rowGap = m.gridRowGap;
        g.padX = g.padY = m.linePad;
        for(const Item &r : b.items) {
          Node row(Node::Row);
          // a heading or a rule is a row of its own, running to the end
          if(r.kind == Item::AHeading || r.kind == Item::ARule) {
            row.kids.push_back(said(r, false));
            g.kids.push_back(row);
            continue;
          }
          std::vector<const Item *> cells;
          if(r.kind == Item::ABox && r.box->direction == Box::Across)
            cellsOf(*r.box, cells);
          else
            cells.push_back(&r);
          int share = sharing(cells);
          std::vector<const Item *> plain;
          auto flush = [&]() {
            runs(plain, share, row.kids);
            plain.clear();
          };
          for(const Item *c : cells) {
            if(c->kind == Item::AField) {
              plain.push_back(c);
              continue;
            }
            flush();
            row.kids.push_back(box(*c));
          }
          flush();
          g.columns = std::max(g.columns, (int)row.kids.size());
          g.kids.push_back(row);
        }
        return g;
      }

      // a row of tabs over the panes, stacked on one cell: the tallest
      // gives the height, or the least
      Node tabs(const Item &i)
      {
        Node t(Node::Column);
        t.item = &i;
        t.grow = 1.;
        Node bar(Node::Text);
        bar.content = Size(m.tab, m.tabBar);
        for(const auto &p : i.tabs->tabs)
          bar.content.w += (m.textWidth ? m.textWidth(p.first) : 0.) + m.tab;
        t.kids.push_back(bar);
        Node stack(Node::Stack);
        stack.grow = 1.;
        stack.least = least;
        for(const auto &p : i.tabs->tabs) {
          Node pane = box(p.second);
          if(p.second.kind != Item::ATabs)
            pane.padX = pane.padY = m.tabPad;
          else {
            // tabs under tabs are a second row of them, their frame that of
            // the pane: not set in, only stood off from the row above by
            // the room between two lines
            Node room(Node::Text);
            room.content = Size(0., 2. * m.linePad);
            Node under(Node::Column);
            under.grow = pane.grow;
            under.kids.push_back(room);
            under.kids.push_back(pane);
            pane = under;
          }
          stack.kids.push_back(pane);
        }
        t.kids.push_back(stack);
        return t;
      }
    };

    // --- measured: what each node asks for

    // the widths of the columns of a grid, as CSS grid has them: first as
    // wide as the cells in one of them; then the last cell of a row, which
    // runs to the end, widens the columns it runs over, alike, only when they
    // are too narrow together
    std::vector<double> _columns(const Node &n)
    {
      std::vector<double> col((std::size_t)std::max(n.columns, 1), 0.);
      auto runs = [&](const Node &r, std::size_t j) {
        return j + 1 == r.kids.size() && j + 1 < col.size();
      };
      for(const Node &r : n.kids) {
        if(r.hidden) continue;
        for(std::size_t j = 0; j < r.kids.size(); j++)
          if(!r.kids[j].hidden && !runs(r, j))
            col[j] = std::max(col[j], r.kids[j].content.w);
      }
      for(const Node &r : n.kids) {
        if(r.hidden) continue;
        for(std::size_t j = 0; j < r.kids.size(); j++) {
          const Node &k = r.kids[j];
          if(k.hidden || !runs(r, j)) continue;
          double have = 0.;
          for(std::size_t c = j; c < col.size(); c++) have += col[c];
          have += (col.size() - 1 - j) * n.gap;
          if(k.content.w <= have) continue;
          double each = (k.content.w - have) / (double)(col.size() - j);
          for(std::size_t c = j; c < col.size(); c++) col[c] += each;
        }
      }
      return col;
    }

    void _measure(Node &n)
    {
      if(n.hidden) {
        n.content = Size();
        return;
      }
      for(Node &k : n.kids) _measure(k);
      switch(n.kind) {
      case Node::Row: {
        double w = 0., h = 0.;
        int shown = 0;
        for(const Node &k : n.kids) {
          if(k.hidden) continue;
          w += k.basis >= 0. ? k.basis : k.content.w;
          h = std::max(h, k.content.h);
          shown++;
        }
        if(shown > 1) w += (shown - 1) * n.gap;
        n.content = Size(w + 2. * n.padX, std::max(h + 2. * n.padY, n.least));
      } break;
      case Node::Column: {
        double w = 0., h = 0.;
        int shown = 0;
        for(const Node &k : n.kids) {
          if(k.hidden) continue;
          w = std::max(w, k.content.w);
          h += k.content.h;
          shown++;
        }
        if(shown > 1) h += (shown - 1) * n.gap;
        n.content = Size(w + 2. * n.padX, h + 2. * n.padY);
        if(n.scrolls) {
          n.content.h = n.least;
          n.content.w += n.bar;
        }
      } break;
      case Node::Grid: {
        std::vector<double> col = _columns(n);
        double h = 0.;
        int shown = 0;
        for(Node &r : n.kids) {
          if(r.hidden) continue;
          double tall = 0.;
          for(const Node &k : r.kids)
            if(!k.hidden) tall = std::max(tall, k.content.h);
          r.content.h = tall;
          h += tall;
          shown++;
        }
        double w = 0.;
        for(double c : col) w += c;
        if(col.size() > 1) w += (col.size() - 1) * n.gap;
        if(shown > 1) h += (shown - 1) * n.rowGap;
        n.content = Size(w + 2. * n.padX, h + 2. * n.padY);
      } break;
      case Node::Stack: {
        double w = 0., h = n.least;
        for(const Node &k : n.kids) {
          w = std::max(w, k.content.w);
          h = std::max(h, k.content.h);
        }
        n.content = Size(w, h);
      } break;
      case Node::Space: n.content = Size(n.basis, 0.); break;
      default: break;
      }
    }

    // --- placed: each node given its rectangle

    void _place(Node &n, const Rect &at);

    // the free room of a line shared out by grow, or taken back by shrink
    void _flex(std::vector<Node> &kids, double avail, bool across,
               std::vector<double> &size)
    {
      double sum = 0., grow = 0., scaled = 0.;
      for(const Node &k : kids) {
        if(k.hidden) continue;
        double hyp = k.basis >= 0. ? k.basis :
                     across         ? k.content.w :
                                      k.content.h;
        sum += hyp;
        grow += k.grow;
        scaled += k.shrink * hyp;
      }
      double free = avail - sum;
      size.clear();
      for(const Node &k : kids) {
        if(k.hidden) {
          size.push_back(0.);
          continue;
        }
        double hyp = k.basis >= 0. ? k.basis :
                     across         ? k.content.w :
                                      k.content.h;
        double s = hyp;
        if(free > 0. && grow > 0.)
          s += free * k.grow / grow;
        else if(free < 0. && scaled > 0.)
          s += free * k.shrink * hyp / scaled;
        size.push_back(std::max(s, 0.));
      }
    }

    void _place(Node &n, const Rect &at)
    {
      n.at = at;
      if(n.hidden) {
        for(Node &k : n.kids) _place(k, Rect());
        return;
      }
      std::vector<double> size;
      switch(n.kind) {
      case Node::Row: {
        int shown = 0;
        for(const Node &k : n.kids)
          if(!k.hidden) shown++;
        double inner = at.w - 2. * n.padX - std::max(shown - 1, 0) * n.gap;
        double tall = at.h - 2. * n.padY;
        _flex(n.kids, inner, true, size);
        double x = at.x + n.padX;
        for(std::size_t i = 0; i < n.kids.size(); i++) {
          Node &k = n.kids[i];
          if(k.hidden) {
            _place(k, Rect());
            continue;
          }
          double h = k.stretch ? tall : std::min(k.content.h, tall);
          double y = at.y + n.padY + (k.stretch ? 0. : (tall - h) / 2.);
          _place(k, Rect(x, y, size[i], h));
          x += size[i] + n.gap;
        }
      } break;
      case Node::Column: {
        int shown = 0;
        for(const Node &k : n.kids)
          if(!k.hidden) shown++;
        // what scrolls is laid out at the height it asks for, in a box that
        // shows the least: the toolkit scrolls the rest
        double wide = at.w - 2. * n.padX - n.bar;
        double inner = at.h - 2. * n.padY - std::max(shown - 1, 0) * n.gap;
        if(n.scrolls) {
          double need = 0.;
          for(const Node &k : n.kids)
            if(!k.hidden) need += k.content.h;
          need += std::max(shown - 1, 0) * n.gap;
          inner = std::max(inner, need);
        }
        _flex(n.kids, inner, false, size);
        double y = at.y + n.padY;
        for(std::size_t i = 0; i < n.kids.size(); i++) {
          Node &k = n.kids[i];
          if(k.hidden) {
            _place(k, Rect());
            continue;
          }
          _place(k, Rect(at.x + n.padX, y, wide, size[i]));
          y += size[i] + n.gap;
        }
      } break;
      case Node::Grid: {
        std::vector<double> col = _columns(n);
        double y = at.y + n.padY;
        double right = at.x + at.w - n.padX;
        for(Node &r : n.kids) {
          if(r.hidden) {
            _place(r, Rect());
            continue;
          }
          r.at = Rect(at.x + n.padX, y, at.w - 2. * n.padX, r.content.h);
          double x = at.x + n.padX;
          for(std::size_t j = 0; j < r.kids.size(); j++) {
            Node &k = r.kids[j];
            double w = j + 1 < r.kids.size() ? col[j] : right - x;
            if(k.hidden) {
              _place(k, Rect());
              continue;
            }
            double h = k.stretch ? r.content.h : std::min(k.content.h, r.content.h);
            _place(k, Rect(x, y + (r.content.h - h) / 2., w, h));
            x += col[j] + n.gap;
          }
          y += r.content.h + n.rowGap;
        }
      } break;
      case Node::Stack:
        for(Node &k : n.kids) _place(k, at);
        break;
      default: break;
      }
    }

    // --- read off: one placed item per item of the tree

    struct Reader {
      Placement &out;
      Reader(Placement &p) : out(p) {}

      void read(const Node &n, std::size_t parent, int pane, bool hidden,
                bool aside)
      {
        hidden = hidden || n.hidden;
        aside = aside || n.aside;
        // a field's cell: its parts make one item
        if(n.item && n.item->kind == Item::AField && n.kind != Node::Widget) {
          PlacedItem p;
          p.item = n.item;
          p.field = n.item->field;
          p.parent = parent;
          p.pane = pane;
          p.hidden = hidden;
          p.aside = aside;
          if(n.kind == Node::Space)
            p.box = n.at;
          for(const Node &k : n.kids) {
            if(k.part == Node::TheWidget) p.box = k.at;
            if(k.part == Node::TheLabel) p.label = k.at;
            if(k.part == Node::TheTrailing) p.trailing.push_back(k.at);
          }
          if(hidden) p.box = p.label = Rect(), p.trailing.clear();
          out.items.push_back(p);
          return;
        }
        if(n.item && n.item->kind == Item::ATabs) {
          PlacedItem p;
          p.item = n.item;
          p.parent = parent;
          p.pane = pane;
          p.hidden = hidden;
          p.box = hidden ? Rect() : n.at;
          std::size_t at = out.items.size();
          out.items.push_back(p);
          const Node &stack = n.kids[1];
          for(std::size_t k = 0; k < stack.kids.size(); k++) {
            out.items[at].panes.push_back(hidden ? Rect() : stack.kids[k].at);
            read(stack.kids[k], at, (int)k, hidden, aside);
          }
          return;
        }
        if(n.item && n.item->kind == Item::ABox && n.scrolls) {
          PlacedItem p;
          p.item = n.item;
          p.parent = parent;
          p.pane = pane;
          p.hidden = hidden;
          p.box = hidden ? Rect() : n.at;
          std::size_t at = out.items.size();
          out.items.push_back(p);
          for(const Node &k : n.kids) read(k, at, -1, hidden, aside);
          return;
        }
        if(n.item && (n.item->kind == Item::ARule ||
                      n.item->kind == Item::AHeading)) {
          PlacedItem p;
          p.item = n.item;
          p.parent = parent;
          p.pane = pane;
          p.hidden = hidden;
          p.box = hidden ? Rect() : n.at;
          if(n.item->kind == Item::AHeading) p.field = _heading(n.item->text);
          out.items.push_back(p);
          return;
        }
        for(const Node &k : n.kids) read(k, parent, pane, hidden, aside);
      }
    };

    Node _build(const Item &root, const Metrics &m, int leastRows)
    {
      Builder b(m, leastRows);
      Node n = b.box(root);
      _measure(n);
      return n;
    }

  } // namespace

  Size treeSize(const Item &root, const Metrics &m, int leastRows)
  {
    Node n = _build(root, m, leastRows);
    return n.content;
  }

  Placement placeTree(const Item &root, const Metrics &m, double width,
                      double height, int leastRows)
  {
    Node n = _build(root, m, leastRows);
    Placement out;
    out.width = std::max(width, n.content.w);
    out.height = std::max(height, n.content.h);
    _place(n, Rect(0., 0., out.width, out.height));
    Reader r(out);
    r.read(n, (std::size_t)-1, -1, false, false);
    return out;
  }

} // namespace Ui
