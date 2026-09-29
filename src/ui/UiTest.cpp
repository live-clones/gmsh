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

  if(failed) {
    std::printf("%d failed\n", failed);
    return 1;
  }
  std::printf("the helpers of src/ui say what they should\n");
  return 0;
}
