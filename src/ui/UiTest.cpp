// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// what src/ui works out for every interface, checked without a screen: the
// patterns of a file format, and what makes a form or a row of buttons be
// built again

#include <cstdio>
#include <string>
#include <vector>

#include "Backend.h"
#include "Console.h"
#include "Glyph.h"
#include "MapEditor.h"

using namespace Ui;

namespace {

  int failed = 0;

  void same(const std::string &got, const std::string &wanted, const char *what)
  {
    if(got == wanted) return;
    failed++;
    std::printf("FAIL %s: got '%s', wanted '%s'\n", what, got.c_str(),
                wanted.c_str());
  }

  void differ(const std::string &a, const std::string &b, const char *what)
  {
    if(a != b) return;
    failed++;
    std::printf("FAIL %s: both '%s'\n", what, a.c_str());
  }

  std::string joined(const std::vector<std::string> &v)
  {
    std::string s;
    for(const auto &x : v) s += (s.size() ? " " : "") + x;
    return s;
  }

  std::string patterns(const char *said)
  {
    return joined(Backend::FileFormat("", said).patterns());
  }

  Field field(const char *label, FieldKind kind)
  {
    Field f;
    f.kind = kind;
    f.label = label;
    return f;
  }

  Form form(std::vector<Item> items)
  {
    Box b;
    b.items = items;
    Form f;
    f.title = "Options";
    f.content = Item(b);
    return f;
  }

} // namespace

int main()
{
  // --- the patterns of a file format
  same(patterns("*.geo"), "*.geo", "one pattern");
  same(patterns("*.{geo,msh}"), "*.geo *.msh", "the braces");
  same(patterns("*.{geo,msh} *.pos;*.brep"), "*.geo *.msh *.pos *.brep",
       "blanks and ';'");
  same(patterns("*.*"), "*", "anything");
  same(patterns("mesh.{msh,msh4}.gz"), "mesh.msh.gz mesh.msh4.gz",
       "what follows the braces");
  same(patterns("  "), "", "nothing");

  // --- a form is built again when its shape changes, not its values
  bool visible = true;
  auto shaped = [&visible](FieldKind kind) {
    Field a = field("Size", kind);
    Field b = field("Name", Text);
    b.visibleWhen(visible);
    return form({Item(a), Item(b)});
  };
  std::string placed = signature(shaped(Number));
  std::string boxed = signature(shaped(Number), true);
  differ(placed, signature(shaped(Text)), "the kind of a field");
  Form valued = shaped(Number);
  valued.content.box->items[0].field.minimum = 3.;
  same(signature(valued), placed, "a bound is not the shape");
  visible = false;
  same(signature(shaped(Number)), placed,
       "a placing interface keeps what is hidden");
  differ(signature(shaped(Number), true), boxed,
         "an interface of boxes builds what is shown");
  std::string folded = folding(shaped(Number));
  visible = true;
  differ(folding(shaped(Number)), folded, "what is folded away");

  // --- the buttons of the bar, and under the tree
  std::vector<BarButton> bar(2);
  bar[0].label = "X";
  bar[1].label = "Y";
  std::string row = signature(bar);
  bar[1].gapBefore = true;
  differ(signature(bar), row, "a gap in the bar");
  std::vector<Button> footer(1);
  footer[0].label = "Run";
  bool running = false;
  footer[0].enabled = [&running]() { return !running; };
  std::string idle = signature(footer);
  running = true;
  differ(signature(footer), idle, "a button greyed");

  // --- the value of a field
  same(numberText(0.5, 0.), "0.5", "no step: as %g");
  same(numberText(0.5, 0.25), "0.50", "the decimals of the step");
  same(numberText(3., 1.), "3", "a whole step");
  same(numberText(1e-6, 1e-4), "1e-06", "off the grid of the step");
  same(numberText(-0., 0.1), "0.0", "no negative zero");
  same(std::to_string(decimals(0.125)), "3", "the decimals of 0.125");
  Field n = field("Size", Number);
  n.minimum = 0.;
  n.maximum = 10.;
  same(numberText(bounded(n, 12.), 0.), "10", "within the bounds");
  Field k = field("Count", Integer);
  same(numberText(bounded(k, 2.6), 0.), "3", "whole for an Integer");
  double read = -1.;
  same(readNumber("abc", read) ? "read" : "not", "not", "not a number");
  same(readNumber(" 2.5e1", read) ? numberText(read, 0.) : "not", "25",
       "a number typed");
  Field c = field("Mode", Choice);
  c.choices = {"one", "two"};
  c.values = {1, 2};
  std::vector<std::string> labels;
  std::vector<int> values;
  choices(c, labels, values);
  same(joined(labels) + std::to_string(values.size()), "one two2",
       "the choices and their values");
  c.dynamicChoices = [](std::vector<std::string> &l, std::vector<int> &) {
    l = {"three"};
  };
  choices(c, labels, values);
  same(joined(labels) + std::to_string(values.size()), "three0",
       "the choices said as it goes");

  // --- the channels of a colour map
  Colour stored(10, 20, 30, 255);
  ColourMap map;
  map.colour = [&stored](int) { return stored; };
  map.setColour = [&stored](int, const Colour &c) { stored = c; };
  same(std::to_string(mapChannel(map, 0, 1, false)), "20", "green");
  setMapChannel(map, 0, 3, 128, false);
  same(std::to_string(stored.a), "128", "alpha set");
  int v = mapChannel(map, 0, 2, true);
  setMapChannel(map, 0, 2, v, true);
  same(std::to_string(stored.b), "30", "value set back as it was");

  // --- editing a colour map
  std::vector<Colour> table(8, Colour(0, 0, 0, 255));
  int chosen = -1;
  ColourMap edited;
  edited.size = [&table]() { return (int)table.size(); };
  edited.colour = [&table](int i) { return table[(std::size_t)i]; };
  edited.setColour = [&table](int i, const Colour &c) { table[(std::size_t)i] = c; };
  edited.numPresets = []() { return 27; };
  edited.preset = [&chosen]() { return chosen; };
  edited.choosePreset = [&chosen](int p) { chosen = p; };
  edited.hsv = []() { return false; };
  MapEditor editor;
  // the answer first: the operands of + are read in any order
  int answer = editor.key(edited, '3', ModCommand);
  same(std::to_string(answer) + std::to_string(chosen),
       std::to_string(MapEditor::Changed) + "13", "Ctrl+3 is preset 13");
  answer = editor.key(edited, KeyF1 + 1, 0);
  same(std::to_string(answer) + std::to_string(chosen),
       std::to_string(MapEditor::Changed) + "21", "F2 is preset 21");
  answer = editor.key(edited, 'H', 0);
  same(std::to_string(answer) + (editor.help() ? "+" : "-"),
       std::to_string(MapEditor::Redraw) + "+", "h shows the help");
  same(std::to_string(editor.key(edited, 'Q', 0)), std::to_string(MapEditor::NotMine),
       "a key the map has no use for");
  editor.press(edited, 1, 200, 0, ModShift);
  same(editor.help() ? "help" : "none", "none", "a click puts the help away");
  editor.drag(edited, 4, 100);
  editor.release();
  same(std::to_string(table[1].g) + " " + std::to_string(table[3].g) + " " +
         std::to_string(table[4].g) + " " + std::to_string(table[5].g) + " " +
         std::to_string(table[1].r),
       "100 100 100 0 0",
       "Shift+left draws green, a drag fills what it passed, from where it was");
  editor.press(edited, 6, 50, 2, ModCommand);
  same(std::to_string(table[6].a), "50", "Command draws alpha");
  edited.about = [](std::string &name, double &least, double &most) {
    least = 0.;
    most = 7.;
  };
  int before = table[2].r;
  answer = editor.press(edited, 2, 255, 0, 0, true);
  editor.drag(edited, 3, 255);
  editor.release();
  same(std::to_string(answer) + " " + std::to_string(editor.marker()) + " " +
         MapEditor::markerText(edited, editor.marker()) + " " +
         std::to_string(table[2].r - before),
       std::to_string(MapEditor::Redraw) + " 3 3 0",
       "on the wedge, the marker follows and the colours stay");
  same(std::to_string(MapEditor::entryAt(edited, 99., 100.)) + " " +
         std::to_string(MapEditor::valueAt(0., 10.)),
       "7 255", "the entry and the intensity under the pointer");

  // --- the console: what the filter lets through, how many lines are kept
  Console console(3);
  console.add("Info    : Reading 'a.geo'", 1);
  console.add("Warning : Unknown option", 2);
  bool through = console.setFilter("warn") && !console.add("Info    : Done", 1);
  same(std::to_string(console.shown().size()) + " " +
         std::to_string(console.lines().size()) + (through ? " yes" : " no"),
       "1 3 yes", "a filter, case ignored, and a line it keeps out");
  console.setFilter("(");
  same(std::to_string(console.shown().size()), "0",
       "an expression that does not parse lets nothing through");
  console.setFilter("");
  console.add("Info    : Four", 1);
  same(console.lines().front().text + " " + std::to_string(console.shown().size()),
       "Warning : Unknown option 3", "the oldest forgotten, all shown");

  // --- the glyphs: every one the descriptions name, in the square, with a
  // character for the terminal
  std::string missing, outside;
  for(const char *name : {"play", "pause", "rewind", "back", "forward", "rotate",
                          "query", "measure", "models", "gear", "graph",
                          "search", "colormap"}) {
    const Glyph *g = glyph(name);
    if(!g || g->strokes.empty() || g->text.empty()) {
      missing += std::string(" ") + name;
      continue;
    }
    for(const Stroke &k : g->strokes)
      for(double v : k.points)
        if(v < -1.25 || v > 1.25) outside = name;
  }
  same(missing, "", "the glyphs the descriptions name");
  same(outside, "", "the glyphs stay about their square");
  same(glyph("nothing") ? "a glyph" : "none", "none", "an unknown name");

  if(failed) {
    std::printf("%d failed\n", failed);
    return 1;
  }
  std::printf("the helpers of src/ui say what they should\n");
  return 0;
}
