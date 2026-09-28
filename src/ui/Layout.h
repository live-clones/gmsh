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

// Where the items of a form go, in em from the top left, for a toolkit that
// places its widgets itself: a flex/grid engine reduced to what the
// translation at the top of Form.h uses -- rows and columns with a gap and a
// padding, cells that grow, shrink or keep their size, grids of max-content
// columns, panes stacked on one cell. What a widget is worth on its own is
// the toolkit's, said through Metrics.

namespace Ui {

  struct Size {
    double w, h;
    Size(double width = 0., double height = 0.) : w(width), h(height) {}
  };

  struct Rect {
    double x, y, w, h;
    Rect() : x(0.), y(0.), w(0.), h(0.) {}
    Rect(double px, double py, double pw, double ph)
      : x(px), y(py), w(pw), h(ph)
    {
    }
  };

  // in em; the numbers are those of the page's stylesheet, at its font
  struct Metrics {
    // an ordinary value widget, and the height of a line of widgets
    double field, row;
    // a line of text
    double line;
    // between the cells of a line, between the parts of a cell, around a
    // line -- as much across as down -- and between the lines of a grid
    double gap, cellGap, linePad, gridRowGap;
    // a rule with the room about it; the row of tabs, what a tab takes
    // beyond its name, what a pane is set in from the tabs; the scrollbar of
    // a box that scrolls
    double rule, tabBar, tab, tabPad, scrollbar;
    std::function<double(const std::string &)> textWidth;
    // the widget of a field that sizes itself -- a button, a check, a colour,
    // a menu, a disc, a line of text -- without its name; a width below zero
    // for a value widget, which the description sizes
    std::function<Size(const Field &)> widget;
    // a page of prose, that wide
    std::function<double(const Field &, double width)> proseHeight;
    Metrics()
      : field(10.), row(2.), line(1.5), gap(.6), cellGap(.45), linePad(.15),
        gridRowGap(.3), rule(.7), tabBar(2.), tab(1.), tabPad(0.),
        scrollbar(1.)
    {
    }
  };

  // one item of the tree where it went: a field's widget, with its name and
  // the buttons after it, or the room of a box, of tabs, of a rule or a
  // heading. The field carries what the description said of it.
  struct PlacedItem {
    const Item *item;
    Field field;
    Rect box;
    std::vector<Rect> trailing;
    // w == 0 when the widget carries its own name
    Rect label;
    // Tabs: the room of each pane, under the row of tabs
    std::vector<Rect> panes;
    // the box or tabs this one is placed inside, as an index in the list
    // (npos at the top), and which pane of the tabs
    std::size_t parent;
    int pane;
    // folded away, or in a box that is: the list keeps the same items
    // whatever shows, so that a toolkit can move its widgets rather than make
    // them again
    bool hidden;
    // in a column beside the rest of its line
    bool aside;
    PlacedItem()
      : item(nullptr), parent((std::size_t)-1), pane(-1), hidden(false),
        aside(false)
    {
    }
  };
  struct Placement {
    std::vector<PlacedItem> items;
    double width, height;
    Placement() : width(0.), height(0.) {}
  };

  // what the tree asks for: its width, and its height at that width, with
  // what fills at least leastRows lines
  Size treeSize(const Item &root, const Metrics &m, int leastRows);
  // placed in that much room, which is at least what it asks for: what
  // fills takes what is left
  Placement placeTree(const Item &root, const Metrics &m, double width,
                      double height, int leastRows);
  // as tall as there is room: a list with no rows, a box that scrolls or
  // holds one; in a line, such a cell is a column, the rest beside it
  bool fills(const Item &it);
  // the column beside the rest holds nothing but its list, which may then
  // run to the edges of the window
  bool aloneInColumn(const Placement &p);

} // namespace Ui

#endif
