// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What the layout solver promises, checked without a screen.
//
// The solver is C++ with neither a toolkit nor Gmsh in it, so it is the one
// part of the interfaces that a test can hold to its word: given metrics that
// are made up and a text width that is half an em a letter, what it measures
// is a number one can write down. The bench (utils/guicompare) stays what
// checks the drawing; this checks the arithmetic, which is what the bench
// could only show as a window that came out wrong.

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
    m.naturalWidth = [](const Field &f, bool) -> double {
      if(f.kind == Check) return 1.5 + 0.5 * f.label.size();
      if(f.kind == Action || f.kind == Menu) return 0.5 * f.label.size() + 2.;
      if(f.kind == Label) return 0.5 * f.getText().size();
      return -1.;
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

  if(failed) {
    std::printf("%d layout checks failed\n", failed);
    return 1;
  }
  std::printf("the layout solver adds up\n");
  return 0;
}
