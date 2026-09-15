// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What the layout solver promises, checked without a screen: given made up
// metrics and a text width of half an em a letter, what it measures is a
// number one can write down.

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

  // metrics that are easy to add up in one's head
  Metrics metrics()
  {
    Metrics m;
    m.field = 10.;
    m.gap = 0.5;
    m.labelGap = 1.;
    m.column = 0.5;
    m.after = 0.25;
    m.arrow = 2.;
    m.offer = 1.5;
    m.textWidth = [](const std::string &s) { return 0.5 * s.size(); };
    m.row = 2.5;
    m.widgetWidth = [](const Field &f) -> double {
      // what the widget draws, the text it writes itself included
      if(f.kind == Check) return 1.5 + 0.5 * f.label.size();
      if(f.kind == Action || f.kind == Menu) return 0.5 * f.label.size() + 2.;
      if(f.kind == Label) return 0.5 * f.getText().size();
      if(f.kind == Color) return 3.;
      return -1.;
    };
    m.trailingWidth = [](const Button &) { return 1.; };
    return m;
  }

  Room room(double width, double height = 0., bool wide = false)
  {
    Room r;
    r.width = width;
    r.height = height;
    r.wide = wide;
    return r;
  }

  Field action(const char *label)
  {
    Field f;
    f.kind = Action;
    f.label = label;
    return f;
  }

  // the box of the field at k
  const Box &boxOf(const Placed &p, std::size_t k)
  {
    static Box none;
    for(const auto &f : p.fields)
      if(f.index == k) return f.widget;
    return none;
  }

  // what every placing promises: nothing reaches past the room, and two
  // fields of one line do not overlap, unless one of them is a disc that
  // hangs over the lines under it
  void wellPlaced(const std::vector<Field> &fields, const Placed &p,
                  const Room &r, const char *what)
  {
    for(const auto &a : p.fields) {
      check(a.widget.x >= -1e-9 && a.widget.x + a.widget.w <= r.width + 1e-9,
            what, a.widget.x + a.widget.w, r.width);
      for(const auto &b : p.fields) {
        if(a.index >= b.index || a.row != b.row) continue;
        if(fields[a.index].kind == Direction ||
           fields[b.index].kind == Direction)
          continue;
        double aEnd = a.widget.x + a.widget.w;
        for(const auto &t : a.trailing) aEnd = std::max(aEnd, t.x + t.w);
        check(aEnd <= b.widget.x + 1e-9, what, aEnd, b.widget.x);
      }
    }
  }

  Field text(const char *label)
  {
    Field f;
    f.kind = Text;
    f.label = label;
    return f;
  }

  Field beside(Field f)
  {
    f.sameRow = true;
    return f;
  }

  Field packed(Field f)
  {
    f.packed = true;
    return f;
  }

  Field shared(Field f, double part)
  {
    f.widthShare = part;
    f.packed = true;
    return f;
  }

  Field spacer(double least)
  {
    Field f;
    f.kind = Spacer;
    f.widthEm = least;
    f.sameRow = true;
    return f;
  }

} // namespace

int main()
{
  Metrics m = metrics();

  // nothing takes no room
  same(neededWidth({}, 0, m), 0., "an empty list");

  // one ordinary field: the field, its label after it, and the column's due
  same(neededWidth({text("Name")}, 0, m), 10. + 1. + 2. + 0.5, "one field");

  // two sharing a line get half a field each, and the line is twice the
  // wider of the two
  same(neededWidth({text("Name"), beside(text("X"))}, 0, m),
       2. * (5. + 1. + 2. + 0.5), "two on a line");

  // a dropdown sharing a line takes its arrow on top of its share
  {
    Field c = text("");
    c.kind = Choice;
    same(neededWidth({text(""), beside(c)}, 0, m), 2. * (5. + 2. + 1. + 0.5),
         "a dropdown on a shared line");
  }

  // the button offering what one may type
  {
    Field t = text("");
    t.dynamicChoices = [](std::vector<std::string> &, std::vector<int> &) {};
    same(neededWidth({t}, 0, m), 10. + 1.5 + 1. + 0.5, "a text with offers");
  }

  // packed fields take what they need, and a gap each
  same(neededWidth({packed(text("A")), beside(packed(text("A")))}, 0, m),
       2. * (10. + 1. + 0.5 + 0.5), "a packed run");

  // two halves take exactly the room one field would
  same(neededWidth({shared(text(""), .5), beside(shared(text(""), .5))}, 0, m),
       neededWidth({packed(text(""))}, 0, m), "two halves are one field");

  // a declared width is honoured, and a line that wraps takes a field's
  {
    Field t = text("");
    t.widthEm = 3.;
    same(neededWidth({t}, 0, m), 3. + 1. + 0.5, "a declared width");
    Field l;
    l.kind = Label;
    l.readText = []() { return std::string("a long line of prose"); };
    l.wraps = true;
    same(packedWidth(l, m), 10., "a line that wraps");
    l.widthEm = 7.;
    same(packedWidth(l, m), 7., "a line of a declared width");
  }

  // A grid: a column is as wide as the widest thing in it, the label of the
  // last field of a row runs on past its column, and the pane is as wide as
  // its widest row.
  {
    std::vector<Field> fields = {text("AA"), beside(text("B")),
                                 text("CCCCCC"), beside(text("D"))};
    std::vector<double> column = gridColumns(fields, 2, m);
    same(column.size(), 2., "a grid has its columns");
    same(column[0], 10. + 1. + 3. + 0.25, "the first column is its widest");
    same(column[1], 10. + 0.25, "the last column keeps no label");
    double w = neededWidth(fields, 2, m);
    atLeast(w, column[0] + column[1], "a grid holds its columns");
    same(w, column[0] + 10. + 1. + 0.5 + 0.25, "a grid ends at its last label");
  }

  // a spacer in a grid keeps at least what it asks, and what it pushes to the
  // right stands after that
  {
    std::vector<Field> fields = {text("A"), spacer(1.), beside(packed(text("B")))};
    double w = neededWidth(fields, 2, m);
    atLeast(w, packedWidth(fields[0], m) + 1. + packedWidth(fields[2], m),
            "a spacer keeps its least");
  }

  // adding to a line never makes it narrower
  {
    std::vector<Field> fields = {text("Name")};
    double before = neededWidth(fields, 0, m);
    fields.push_back(beside(text("Other")));
    atLeast(neededWidth(fields, 0, m), before, "a line only grows");
    fields.push_back(beside(packed(text("More"))));
    atLeast(neededWidth(fields, 0, m), before, "a packed field only adds");
  }

  // --- placing

  // one field takes an ordinary width on the first line
  {
    std::vector<Field> fields = {text("Name")};
    Placed p = place(fields, 0, m, room(40.));
    same(p.fields.size(), 1., "one field is placed");
    same(boxOf(p, 0).x, 0., "one field starts at the left");
    same(boxOf(p, 0).w, 10., "one field is a field wide");
    same(boxOf(p, 0).h, 2.5, "one field is a line tall");
    same(p.height, 2.5, "one field takes a line");
    same(neededRows(fields, m), 1., "one field is one line");
  }

  // two sharing a line: half a field each, and the slack shared out equally
  {
    std::vector<Field> fields = {text("Name"), beside(text("X"))};
    Placed p = place(fields, 0, m, room(40.));
    // the busier column asks 5 + 2 + 1 + 0.5; the slack, 40 - 17, is shared
    same(boxOf(p, 0).w, 5., "a shared field is half a field");
    same(boxOf(p, 1).x, 8.5 + 11.5, "the second column starts after the first");
    same(p.height, 2.5, "two on a line take one line");
    wellPlaced(fields, p, room(40.), "two on a line");
  }

  // a toolkit that places at whole pixels gets the slack cut to them
  {
    Metrics q = m;
    q.pixel = 0.25;
    std::vector<Field> fields = {text("Name"), beside(text("X"))};
    Placed p = place(fields, 0, q, room(40.6));
    same(boxOf(p, 1).x, 8.5 + 11.75, "the slack is cut to the pixel");
  }

  // packed fields follow one another from where they stand
  {
    std::vector<Field> fields = {packed(text("A")), beside(packed(text("A")))};
    Placed p = place(fields, 0, m, room(40.));
    same(boxOf(p, 1).x, 10. + 1. + 0.5 + 0.5, "a packed field follows the last");
    wellPlaced(fields, p, room(40.), "a packed run");
  }

  // a spacer pushes what follows it to the right end of the line
  {
    std::vector<Field> fields = {packed(text("A")), spacer(1.),
                                 beside(packed(text("B")))};
    Placed p = place(fields, 0, m, room(40.));
    // 40 - (12 + 1.5 + 12) = 14.5 of slack, all of it to the spacer
    same(boxOf(p, 2).x, 12. + 1. + 0.5 + 14.5, "a spacer pushes right");
    wellPlaced(fields, p, room(40.), "a spacer");
  }

  // on a grid the columns of two lines line up
  {
    std::vector<Field> fields = {text("AA"), beside(text("B")),
                                 text("CCCCCC"), beside(text("D"))};
    Placed p = place(fields, 2, m, room(60.));
    std::vector<double> column = gridColumns(fields, 2, m);
    same(boxOf(p, 1).x, column[0], "the second column starts after the first");
    same(boxOf(p, 3).x, column[0], "the columns of a grid line up");
    same(boxOf(p, 2).y, 2.5, "the second line is under the first");
    same(boxOf(p, 2).w, 10., "a field of a grid is a field wide");
    wellPlaced(fields, p, room(60.), "a grid");
  }

  // a list that fills what is left leaves the lines under it their room
  {
    Field l;
    l.kind = List;
    l.rows = 0;
    std::vector<Field> fields = {l, text("After")};
    Placed p = place(fields, 0, m, room(40., 30.));
    same(boxOf(p, 0).h, 30. - 2.5, "a list fills what is left");
    same(boxOf(p, 0).w, 40., "a list runs to the edge");
    same(boxOf(p, 1).y, 27.5, "what follows a list is under it");
    same(p.height, 30., "a list that fills makes the list as tall as its room");
    same(neededRows(fields, m), 1., "a list that fills counts for no lines");
  }

  // a list that fills leaves the lines under it what they really take: the
  // room above a line of buttons included
  {
    Field l;
    l.kind = List;
    l.rows = 0;
    std::vector<Field> fields = {l, action("Delete")};
    Placed p = place(fields, 0, m, room(40., 30.));
    same(boxOf(p, 0).h, 30. - 2.5 - 0.5, "a list leaves a line of buttons its room");
    same(boxOf(p, 1).y, 30. - 2.5, "the buttons under a list stand at the bottom");
    // whatever the room comes to in lines, what follows the list is under
    // it and not over it
    for(double h = 20.; h < 32.; h += 0.7) {
      Placed q = place(fields, 0, m, room(40., h));
      atLeast(boxOf(q, 1).y, boxOf(q, 0).y + boxOf(q, 0).h,
              "a line under a list that fills is under it");
    }
  }

  // a page of prose is as tall as the toolkit lays it out, and what follows
  // it starts under that
  {
    Field page;
    page.kind = Prose;
    Metrics q = m;
    q.naturalHeight = [](const Field &f) { return f.kind == Prose ? 7. : -1.; };
    std::vector<Field> fields = {page, text("After")};
    Placed p = place(fields, 0, q, room(40.));
    same(boxOf(p, 0).h, 7. * 2.5, "a page is as tall as its words come to");
    same(boxOf(p, 1).y, 7. * 2.5, "what follows a page is under it");
    same(neededRows(fields, q), 8., "a page counts for its lines");
  }

  // a line that only acts is set apart from the values above it
  {
    std::vector<Field> fields = {text("A"), action("Go")};
    Placed p = place(fields, 0, m, room(40.));
    same(boxOf(p, 1).y, 2.5 + 0.5, "a line that acts stands apart");
    same(p.fields[1].row, 1., "it is still the next line");
    same(p.height, 5.5, "the room it leaves counts");
  }

  // a disc hangs over the lines under it rather than pushing them down
  {
    Field d;
    d.kind = Direction;
    d.rows = 3;
    std::vector<Field> fields = {d, text("X")};
    Placed p = place(fields, 0, m, room(40.));
    same(boxOf(p, 0).w, 7.5, "a disc is as wide as it is tall");
    same(boxOf(p, 0).h, 7.5, "a disc is as tall as it says");
    same(boxOf(p, 1).y, 2.5, "what follows a disc is on the next line");
  }

  // in the column down the side a field takes the whole width
  {
    std::vector<Field> fields = {text("")};
    Placed p = place(fields, 0, m, room(8., 0., true));
    same(boxOf(p, 0).w, 8., "a side field is as wide as the column");
  }

  // the buttons hung after a field take their room from it, and its label
  // is written after them
  {
    Field t = text("Value");
    t.trailing.resize(2);
    std::vector<Field> fields = {t};
    Placed p = place(fields, 0, m, room(40.));
    same(boxOf(p, 0).w, 10. - 2., "a field gives its buttons their room");
    same(p.fields[0].trailing[0].x, 8., "the first button follows the field");
    same(p.fields[0].trailing[1].x, 9., "the second follows the first");
    same(p.fields[0].label.x, 10., "the label follows the buttons");
    same(p.fields[0].label.w, 2.5 + 0.5, "the label is as wide as its text");
  }

  // a field that is not there takes no room and no line
  {
    Field gone = text("Gone");
    gone.visible = []() { return false; };
    std::vector<Field> fields = {gone, text("Here")};
    Placed p = place(fields, 0, m, room(40.));
    same(p.fields.size(), 1., "a hidden field is not placed");
    same(boxOf(p, 1).y, 0., "what follows a hidden field takes its line");
    same(neededRows(fields, m), 1., "a hidden field is no line");
  }

  // a label that comes before its field has its room, and its box
  {
    Field t = text("Name");
    t.labelBefore = true;
    std::vector<Field> fields = {t};
    Placed p = place(fields, 0, m, room(40.));
    same(boxOf(p, 0).x, 2. + 0.5, "a field starts after the label before it");
    same(p.fields[0].label.x, 0., "the label before a field starts the line");
    same(p.fields[0].label.w, 2.5, "the label before a field has its room");
  }

  // the courtesy of a split cell, for the toolkit that asks for it
  {
    std::vector<Field> fields = {shared(text(""), .5),
                                 beside(shared(text(""), .5))};
    Placed p = place(fields, 0, m, room(40.));
    same(boxOf(p, 0).w, 5., "a half is a half where no courtesy is asked");
    Metrics q = m;
    q.courtesy = 0.5;
    q.framePad = 0.25;
    p = place(fields, 0, q, room(40.));
    same(boxOf(p, 0).w, 4.5, "a half gives the courtesy back");
    same(boxOf(p, 1).x, 5., "and the next half still starts where it did");
    // never more than a quarter of the cell, and always room for a digit
    std::vector<Field> narrow = {shared(text(""), .1), beside(shared(text(""), .1))};
    q.framePad = 0.1;
    p = place(narrow, 0, q, room(40.));
    same(boxOf(p, 0).w, 1. - 0.25, "a narrow cell gives a quarter at most");
    q.framePad = 0.4;
    p = place(narrow, 0, q, room(40.));
    same(boxOf(p, 0).w, 1., "a cell keeps room for a digit");
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
