// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>

#include "GuiManipulator.h"
#include "GuiDeclare.h"
#include "Gui.h"
#include "GuiActions.h"
#include "drawContext.h"

// The manipulator: the rotation, the translation and the scale of the view,
// one row each, X Y and Z across. The values are Gmsh options, and setting
// one reaches the draw context of the window that has the focus, so there
// is nothing of our own to hold.

using namespace Declare;

Form GuiManipulator::build()
{
  // the cells of the table are as wide as a button, which is what master
  // gives them
  constexpr double w = 7.;
  auto cell = [](Field f) { return sized(f, w); };
  auto said = [&](const std::string &text) {
    return cell(centred(says([text]() { return text; })));
  };
  auto axis = [&](const char *name, int i, double lo, double hi, double step) {
    std::string full = std::string(name) + (char)('X' + i);
    Field f = within(number("General." + full), lo, hi, step);
    f.tooltip = "General." + full;
    f.changed = []() {
      // The rotation is kept as a quaternion and the three angles are read
      // back from it. Without this, an angle that has just been given is
      // recomputed away before it is ever drawn.
      if(drawContext *ctx = Gui::instance().getCurrentDrawContext())
        ctx->setQuaternionFromEulerAngles();
      drawContext::global()->draw();
    };
    return cell(f);
  };
  auto axisLine = [&](const char *name, double lo, double hi, double step) {
    return hbox({said(name), axis(name, 0, lo, hi, step),
                 axis(name, 1, lo, hi, step), axis(name, 2, lo, hi, step)},
                0.);
  };
  auto reset = []() {
    if(drawContext *ctx = Gui::instance().getCurrentDrawContext())
      viewSetOrientation(ctx, "reset", false);
    drawContext::global()->draw();
  };

  return {"manipulator", "Manipulator",
          vbox({hbox({cell(gap()), said("X"), said("Y"), said("Z")}, 0.),
                axisLine("Rotation", -360., 360., 1.),
                axisLine("Translation", 0., 0., 0.),
                axisLine("Scale", 0.01, 100., 0.01),
                hbox({sized(gap(), 3 * w), cell(does("Reset", reset))}, 0.)})};
}

#endif
