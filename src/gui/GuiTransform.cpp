// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>

#include "GuiTransform.h"
#include "GuiDeclare.h"

using namespace Ui;
using namespace Declare;

Form GuiTransform::build()
{
  auto extruding = [this]() { return extrude; };
  auto meshed = [this]() { return extrude && extrudeMesh; };
  // only when the action extrudes; "on copy" is then meaningless
  auto extrusion = [&]() {
    return vbox({check("Extrude mesh", &extrudeMesh).enabledWhen(extruding),
                 hbox({text("Mesh layers", &layers).enabledWhen(meshed),
                       check("Recombine", &recombineMesh).enabledWhen(meshed)})});
  };
  auto onCopy = [this](const std::string &label) {
    return check(label, &duplicate).enabledWhen([this]() { return !extrude; });
  };
  auto axis = [&](const char *c, std::string &point, std::string &direction) {
    return hbox({text(std::string("Axis point ") + c, &point).sized(10.),
                 text(std::string("Axis direction D") + c, &direction)
                   .sized(5.)});
  };
  const char *plane = "A * X + B * Y + C * Z + D = 0";

  return {"transform", "Elementary Operation Context",
          vbox({tabs({{"Translate",
                       vbox({text("DX", &tx), text("DY", &ty),
                             text("DZ", &tz),
                             onCopy("Apply translation on copy"), extrusion()})},
                      {"Rotate",
                       vbox({axis("X", px, ax), axis("Y", py, ay),
                             axis("Z", pz, az), text("Angle", &angle),
                             onCopy("Apply rotation on copy"), extrusion()})},
                      {"Scale",
                       vbox({text("Center X", &cx),
                             text("Center Y", &cy),
                             text("Center Z", &cz),
                             text("Scaling X", &sx),
                             text("Scaling Y", &sy),
                             text("Scaling Z", &sz),
                             onCopy("Apply scaling on copy")})},
                      {"Symmetry",
                       vbox({text("Symmetry plane coefficient A", &sa).tip(plane),
                             text("Symmetry plane coefficient B", &sb).tip(plane),
                             text("Symmetry plane coefficient C", &sc).tip(plane),
                             text("Symmetry plane coefficient D", &sd).tip(plane),
                             onCopy("Apply symmetry on copy")})},
                      {"Boolean", vbox({check("Delete object", &deleteObject),
                                        check("Delete tool", &deleteTool)})},
                      {"Fillet", text("Radius", &radius)},
                      {"Delete", check("Recursive", &recursive)}}),
                // filleting asks for volumes then curves: nothing to choose
                choice("Selection mode", &selection,
                       {"All entities", "Points", "Curves", "Surfaces", "Volumes"},
                       {ENT_ALL, ENT_POINT, ENT_CURVE, ENT_SURFACE, ENT_VOLUME})
                  .enabledWhen([this]() { return pane() != "Fillet"; })})};
}

void GuiTransform::show(const std::string &pane, bool extrude_)
{
  extrude = extrude_;
  show(pane);
}

#endif
