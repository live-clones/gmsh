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
#include "Context.h"
#include "drawContext.h"

using namespace Declare;

Form GuiManipulator::build()
{
  constexpr double w = 7.; // the width of an input
  bool steps = CTX::instance()->inputScrolling;
  auto axis = [&](const char *name, char c, double lo, double hi, double step) {
    std::string option = std::string("General.") + name + c;
    return number("", option)
      .within(lo, hi, steps ? step : 0.)
      .tip(option)
      .sized(w)
      .onChanged([]() {
        // or the angle just given is recomputed away from the quaternion
        if(drawContext *ctx = Gui::instance().getCurrentDrawContext())
          ctx->setQuaternionFromEulerAngles();
        drawContext::global()->draw();
      });
  };
  auto axes = [&](const char *name, double lo, double hi, double step) {
    return hbox({label(name, Centre).sized(w), axis(name, 'X', lo, hi, step),
                 axis(name, 'Y', lo, hi, step), axis(name, 'Z', lo, hi, step)},
                0.);
  };
  auto reset = []() {
    if(drawContext *ctx = Gui::instance().getCurrentDrawContext())
      viewSetOrientation(ctx, "reset", false);
    drawContext::global()->draw();
  };

  double lc = CTX::instance()->lc;
  return {"manipulator", "Manipulator",
          vbox({hbox({gap(), label("X", Centre).sized(w),
                      label("Y", Centre).sized(w), label("Z", Centre).sized(w)},
                     0.),
                axes("Rotation", -360., 360., 1.),
                axes("Translation", -lc, lc, lc / 200.),
                axes("Scale", 0.01, 100., 0.01),
                hbox({gap(), button("Reset", reset).sized(w)}, 0.)})};
}

#endif
