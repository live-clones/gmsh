// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the layout engine checked without a screen: made up metrics, half an em a
// letter, every number below worked out by hand from the translation at the
// top of Form.h

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

#include "Layout.h"

using namespace Ui;

namespace {

  int failed = 0;

  void check(bool ok, const char *what, double got, double wanted)
  {
    if(ok) return;
    failed++;
    std::printf("FAIL %s: got %g, wanted %g\n", what, got, wanted);
  }

  void same(double got, double wanted, const char *what)
  {
    check(std::fabs(got - wanted) < 1e-9, what, got, wanted);
  }

  void atLeast(double got, double wanted, const char *what)
  {
    check(got >= wanted - 1e-9, what, got, wanted);
  }

  // a line is padded 1 all round, the cells of a line stand 1 apart, the
  // parts of a cell 0.5; a field is 10 wide, a row 2 tall
  Metrics metrics()
  {
    Metrics m;
    m.field = 10.;
    m.row = 2.;
    m.line = 1.;
    m.gap = 1.;
    m.cellGap = .5;
    m.linePad = 1.;
    m.gridRowGap = 0.;
    m.rule = 1.;
    m.tabBar = 2.;
    m.tab = 1.;
    m.tabPad = .5;
    m.scrollbar = 1.;
    m.textWidth = [](const std::string &s) { return 0.5 * s.size(); };
    m.widget = [](const Field &f) -> Size {
      if(f.kind == Check) return Size(1.5 + 0.5 * f.label.size(), 2.);
      if(f.kind == Action || f.kind == Menu)
        return Size(0.5 * f.label.size() + 2., 2.);
      if(f.kind == Label) return Size(0.5 * f.getText().size(), 2.);
      if(f.kind == Color) return Size(3., 2.);
      return Size(-1., 2.);
    };
    return m;
  }

  Field text(const char *label)
  {
    Field f;
    f.kind = Text;
    f.label = label;
    return f;
  }

  Field button(const char *label)
  {
    Field f;
    f.kind = Action;
    f.label = label;
    return f;
  }

  Field gap()
  {
    Field f;
    f.kind = Spacer;
    return f;
  }

  Item down(std::vector<Item> items)
  {
    Box b;
    b.items = items;
    return Item(b);
  }

  Item across(std::vector<Item> items, double padding = -1.)
  {
    Box b;
    b.direction = Box::Across;
    b.padding = padding;
    b.items = items;
    return Item(b);
  }

  // the placed item of the k-th item with a widget
  const PlacedItem &placed(const Placement &p, std::size_t k)
  {
    std::size_t seen = 0;
    for(const PlacedItem &it : p.items) {
      if(it.item->kind != Item::AField) continue;
      if(seen++ == k) return it;
    }
    return p.items.back();
  }

  Placement place(const Item &root, const Metrics &m, int leastRows = 0)
  {
    Size need = treeSize(root, m, leastRows);
    return placeTree(root, m, need.w, need.h, leastRows);
  }

} // namespace

int main()
{
  Metrics m = metrics();

  // one field on a line: padded, the widget one field wide, its name after
  // it half an em on
  {
    Placement p = place(down({Item(text("Name"))}), m);
    same(p.width, 1. + 10. + .5 + 2. + 1., "one field: the line is padded");
    same(p.height, 1. + 2. + 1., "one field: one row, padded");
    same(placed(p, 0).box.x, 1., "the widget starts after the padding");
    same(placed(p, 0).box.w, 10., "the widget is one field wide");
    same(placed(p, 0).label.x, 11.5, "the name half an em after the widget");
  }

  // two values on a line share the width of one field, the cells stand a
  // gap apart and keep their content: the line is the sum
  {
    Placement p =
      place(down({across({Item(text("X")), Item(text("Y"))})}), m);
    same(placed(p, 0).box.w, 5., "two values: half a field each");
    same(placed(p, 1).box.x, 1. + 5. + .5 + .5 + 1., "the second after the gap");
    same(p.width, 2. * (5. + .5 + .5) + 1. + 2., "the line is its cells");
  }

  // a wider line decides the width; the cells of a narrower one do not grow
  {
    Placement p = place(
      down({Item(text("A long name here")), across({Item(text("X")), Item(text("Y"))})}), m);
    same(p.width, 1. + 10. + .5 + 8. + 1., "the widest line");
    same(placed(p, 1).box.w, 5., "a value does not grow with the window");
    same(placed(p, 2).box.x, 8., "nor moves");
  }

  // sized and shared widths; tight cells keep their content when the line
  // is short of room
  {
    Field a = text("");
    a.widthEm = 3.;
    Field b = text("");
    b.widthShare = .5;
    Placement p = place(down({across({Item(a), Item(b)})}), m);
    same(placed(p, 0).box.w, 3., "sized: that wide");
    same(placed(p, 1).box.w, 5., "share: that part of a field");
  }

  // a gap eats what is left of the line, and the cells about it keep their
  // width: a button after a gap stands at the right end
  {
    Item form =
      down({Item(text("A long name here")), across({Item(gap()), Item(button("OK"))})});
    Placement p = place(form, m);
    same(p.width, 20.5, "the widest line");
    same(placed(p, 2).box.x, 20.5 - 1. - 3., "the button at the right end");
    same(placed(p, 2).box.w, 3., "a button is its word");
  }

  // down a column a gap takes none of the height it asks for, and all that
  // is left of what it is given
  {
    Item form = down({Item(text("A")), Item(gap()), Item(text("B"))});
    Size need = treeSize(form, m, 0);
    same(need.h, 4. + 4., "a gap down a column asks for no height");
    Placement p = placeTree(form, m, need.w, need.h + 6., 0);
    same(placed(p, 2).box.y, 4. + 6. + 1.,
         "what follows the gap is pushed down");
  }

  // a box in a line takes what is left of it; a list with no rows beside it
  // is a column running the height of the line
  {
    Field list = text("");
    list.kind = List;
    list.rows = 0;
    list.widthEm = 6.;
    Item rest = down({Item(text("A")), Item(text("B")), Item(text("C"))});
    Placement p = place(across({Item(list), rest}), m);
    same(p.height, 3. * 4., "the line is as tall as the box beside the column");
    // the column is a box of its own: its list is padded inside it
    same(placed(p, 0).box.h, 12. - 2., "the column runs the height of the line");
    same(placed(p, 0).box.w, 6., "the column is as wide as it says");
    same(placed(p, 1).box.x, 6. + 2. + 1. + 1.,
         "the rest starts a line's room after the column");
  }

  // a rule takes its room, a heading a line of text; what is folded away takes
  // none and stays in the list
  {
    Item rule;
    rule.kind = Item::ARule;
    Item heading;
    heading.kind = Item::AHeading;
    heading.text = "Part";
    Box folded;
    folded.items.push_back(Item(text("Gone")));
    folded.visible = []() { return false; };
    Item form = down({Item(text("A")), rule, heading, Item(folded), Item(text("B"))});
    Placement p = place(form, m);
    same(p.height, 4. + 1. + 3. + 4., "a rule and a heading between two lines");
    same(p.items.size(), 5., "every item is placed, the folded one too");
    check(p.items[3].hidden, "what is folded away is hidden", 0., 1.);
    same(placed(p, 2).box.y, 4. + 1. + 3. + 1.,
         "the line after starts under the heading");
  }

  // in a grid, a rule and a heading are rows of their own, the rule running
  // to the end
  {
    Item rule;
    rule.kind = Item::ARule;
    Item heading;
    heading.kind = Item::AHeading;
    heading.text = "Part";
    Box g;
    g.grid = true;
    g.items = {Item(text("A")), rule, heading, Item(text("B"))};
    Placement p = place(Item(g), m);
    same(p.items.size(), 4., "a rule and a heading in a grid are placed");
    same(p.items[1].box.w, 10. + .5 + .5,
         "the rule runs the width of the grid");
  }

  // tabs: a row of them, then the panes stacked, the tallest giving the
  // height, or the least; each pane set in by the pad
  {
    Tabs t;
    t.tabs.push_back(std::make_pair("One", Item(text("A"))));
    t.tabs.push_back(std::make_pair("Two", down({Item(text("B")), Item(text("C"))})));
    Placement p = place(Item(t), m);
    same(p.height, 2. + .5 + 8. + .5, "tabs: the bar and the tallest pane");
    same(p.items[0].panes.size(), 2., "one room per pane");
    same(placed(p, 0).box.y, 2. + .5 + 1., "a pane starts under the bar, set in");
    same(placed(p, 0).box.x, .5 + 1., "and in from the side");
    Placement q = place(Item(t), m, 5);
    same(q.height, 2. + 20., "tabs are at least what they are told, in lines");
  }

  // a box that scrolls shows the least, and what is inside it is laid out
  // at the height it asks for
  {
    Box b;
    for(int i = 0; i < 6; i++) b.items.push_back(Item(text("L")));
    b.scrolling = true;
    Placement p = place(Item(b), m, 2);
    same(p.height, 8., "what scrolls shows the least, in lines");
    same(placed(p, 5).box.y, 5. * 4. + 1., "the lines inside go on under the box");
    same(placed(p, 0).box.w, 10., "a widget keeps its width beside the scrollbar");
  }

  // a grid: each column as wide as its widest cell, the last cell of a row
  // running to the end
  {
    Box g;
    g.grid = true;
    g.items.push_back(across({Item(text("A")), Item(text("Long name"))}));
    g.items.push_back(across({Item(text("Bb")), Item(text("C"))}));
    g.items.push_back(Item(button("Go")));
    Placement p = place(Item(g), m);
    // the cells of a row of two values are half a field each
    same(placed(p, 0).box.x, 1., "the first column starts at the padding");
    same(placed(p, 2).box.x, 1., "under it the next row's first cell");
    same(placed(p, 1).box.x, 1. + 5. + .5 + 1. + 1., "the second column after the widest first");
    same(placed(p, 3).box.x, placed(p, 1).box.x, "the columns line up");
    same(placed(p, 4).box.y, 1. + 2. * 2., "a row of one is a row");
  }

  // the names before their widgets, one under another, line up
  {
    Field a = text("Short");
    a.labelBefore = true;
    Field b = text("A longer name");
    b.labelBefore = true;
    Placement p = place(down({Item(a), Item(b)}), m);
    same(placed(p, 0).box.x, placed(p, 1).box.x, "the widgets line up");
    same(placed(p, 0).box.x, 1. + 6.5 + .5, "after the widest name");
  }

  // --- the vocabulary beside the solver: what Form.cpp and Menu.cpp
  // promise, which is the same kind of arithmetic

  // a number of a colour map is raised by its step, stops at its ends, and
  // the one that wraps comes back by its period
  {
    double held = 0.;
    ColourMap map;
    map.parameter = [&held](const std::string &) { return held; };
    map.setParameter = [&held](const std::string &, double v) { held = v; };
    ColourMap::Parameter p;
    p.name = "n";
    p.least = 0.;
    p.most = 10.;
    p.step = 4.;
    map.adjust(p, true);
    same(held, 4., "a number goes up by its step");
    map.adjust(p, true);
    map.adjust(p, true);
    same(held, 10., "a number stops at its most");
    map.adjust(p, false);
    map.adjust(p, false);
    map.adjust(p, false);
    same(held, 0., "a number stops at its least");
    p.wraps = true;
    p.period = 10.;
    held = 8.;
    map.adjust(p, true);
    same(held, 2., "a number that wraps comes back by its period");
    held = 1.;
    map.adjust(p, false);
    same(held, 7., "and the other way too");
    ColourMap::Parameter t;
    t.name = "t";
    t.toggle = true;
    held = 0.;
    map.adjust(t, true);
    same(held, 1., "a toggle turns on");
    map.adjust(t, true);
    same(held, 0., "and off again");
  }

  // A colour survives the trip to hue, saturation and value and back, to
  // what the quantisation costs: the hue runs over six sectors in 255 steps,
  // as the colour map widget draws it, so a channel may come back six off.
  {
    const unsigned char samples[][3] = {{255, 0, 0},    {0, 255, 0},
                                        {0, 0, 255},    {255, 255, 0},
                                        {0, 255, 255},  {255, 0, 255},
                                        {0, 0, 0},      {255, 255, 255},
                                        {128, 64, 32},  {17, 200, 90},
                                        {200, 200, 200}, {3, 3, 250}};
    for(const auto &c : samples) {
      int h = 0, s = 0, v = 0;
      toHsv(Colour(c[0], c[1], c[2], 77), h, s, v);
      Colour back = fromHsv(h, s, v, 77);
      atLeast(6., std::fabs((double)back.r - c[0]), "red survives the trip");
      atLeast(6., std::fabs((double)back.g - c[1]), "green survives the trip");
      atLeast(6., std::fabs((double)back.b - c[2]), "blue survives the trip");
      same(back.a, 77., "alpha is carried through");
      check(h >= 0 && h <= 255 && s >= 0 && s <= 255 && v >= 0 && v <= 255,
            "the channels stay in a byte", h, 0.);
    }
    int h = 0, s = 0, v = 0;
    toHsv(Colour(0, 0, 0), h, s, v);
    same(s, 0., "black has no saturation");
    same(v, 0., "black has no value");
    toHsv(Colour(255, 255, 255), h, s, v);
    same(s, 0., "white has no saturation");
    same(v, 255., "white has full value");
  }

  // a shortcut is labelled the way the menus write it, and matches what was
  // struck with the modifiers held, and only that
  {
    check(Shortcut().label() == "", "no shortcut has no label", 0., 0.);
    check(Shortcut('O', ModCommand | ModShift).label() ==
#if defined(__APPLE__)
            "Cmd+Shift+O",
#else
            "Ctrl+Shift+O",
#endif
          "a chord is named with its modifiers first", 0., 0.);
    check(Shortcut(KeyF1 + 4).label() == "F5", "a function key is named",
          0., 0.);
    check(Shortcut(KeyLeft, ModCommand).label().find("Left") !=
            std::string::npos,
          "an arrow is named", 0., 0.);
    check(Shortcut(KeyEscape).label() == "Esc", "escape is named", 0., 0.);
    Shortcut o('O', ModCommand);
    check(o.matches('O', ModCommand), "a chord matches itself", 0., 0.);
    check(!o.matches('O', 0), "a chord wants its modifiers", 0., 0.);
    check(!o.matches('O', ModCommand | ModShift),
          "a chord refuses one modifier too many", 0., 0.);
    check(!o.matches('P', ModCommand), "a chord is its key", 0., 0.);
    check(!Shortcut().matches(0, 0), "no shortcut matches nothing", 0., 0.);
    Shortcut any('G', ModAny);
    check(any.matches('G', 0) && any.matches('G', ModShift),
          "a key that takes any modifier takes them all", 0., 0.);
  }

  if(failed) {
    std::printf("%d layout checks failed\n", failed);
    return 1;
  }
  std::printf("the layout solver adds up\n");
  return 0;
}
