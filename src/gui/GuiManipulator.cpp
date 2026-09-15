// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "Gui.h"
#include "GuiDeclare.h"
#include "drawContext.h"

// The manipulator: a three by three grid, the rotation, the translation
// and the scale of the view, one row each, X Y and Z across. The values are
// Gmsh options, and setting one reaches the draw context of the window
// that has the focus, so there is nothing of our own to hold.

namespace {

  using namespace Ui;
  using namespace Declare;

  static Form describeManipulator()
  {
    Form p;
    p.title = "Manipulator";
    p.tabbed = false;

    auto axis = [](const char *name, int i, double lo, double hi, double step) {
      std::string full = std::string(name) + (char)('X' + i);
      Field f = within(option(Number, "", "General", full), lo, hi, step);
      f.tooltip = "General." + full;
      f.changed = []() {
        // The rotation is kept as a quaternion and the three angles are read
        // back from it. Without this, an angle that has just been given is
        // recomputed away before it is ever drawn.
        if(drawContext *ctx = Gui::instance().getCurrentDrawContext())
          ctx->setQuaternionFromEulerAngles();
        drawContext::global()->draw();
      };
      f.sameRow = true;
      // three narrow boxes across
      f.widthEm = 7.;
      return f;
    };

    Pane grid;
    // A grid, and not three lines that each share themselves out: the columns
    // of one row have to line up with the columns of the next, and "Rotation"
    // is not as wide as "Translation".
    grid.columns = 4;
    // the heading of each column, over nothing in the first
    grid.fields.push_back(says([]() { return std::string(""); }));
    for(int i = 0; i < 3; i++) {
      Field h = says([i]() { return std::string(1, (char)('X' + i)); });
      h.sameRow = true;
      grid.fields.push_back(h);
    }
    struct row {
      const char *name;
      double lo, hi, step;
    };
    // the translation is left unbounded
    const row rows[] = {{"Rotation", -360., 360., 1.},
                        {"Translation", 0., 0., 0.},
                        {"Scale", 0.01, 100., 0.01}};
    for(const auto &r : rows) {
      std::string label = r.name;
      grid.fields.push_back(says([label]() { return label; }));
      for(int i = 0; i < 3; i++)
        grid.fields.push_back(axis(r.name, i, r.lo, r.hi, r.step));
    }
    p.panes.push_back(grid);

    Button reset;
    reset.label = "Reset";
    // not the default button: resetting the view is not what pressing Enter
    // in one of these boxes should do
    reset.action = []() {
      if(drawContext *ctx = Gui::instance().getCurrentDrawContext())
        viewSetOrientation(ctx, "reset", false);
      drawContext::global()->draw();
    };
    p.buttons.push_back(reset);
    return p;
  }

} // namespace

Ui::Form GuiManipulator::build()
{
  Ui::Form f = describeManipulator();
  f.id = "manipulator";
  return f;
}


#endif
