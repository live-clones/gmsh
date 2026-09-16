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

// "Mesh Context": what the mesh of an entity is told -- its size, its
// transfinite constraints -- on what one then selects.

namespace {

  using namespace Ui;
  using namespace Declare;

  static Form describeMesh()
  {
    geometryParameters &g = geometryStore();
    Form p;
    p.title = "Mesh Context";
    p.panes.push_back(pane({text("Value", &g.meshSize)}, "Element size"));
    p.panes.push_back(
      pane({text("Number of points", &g.transfinitePoints),
            choice("Type", &g.transfiniteType,
                   {"Progression", "Bump", "Beta", "Progression_HWall",
                    "Bump_HWall", "Beta_HWall"}),
            text("Parameter", &g.transfiniteParameter)},
           "Transfinite curve"));
    p.panes.push_back(
      pane({choice("Transfinite Arrangement", &g.transfiniteArrangement,
                   {"Left", "Right", "Alternated"})},
           "Transfinite Surface"));
    return p;
  }

} // namespace

Ui::Form GuiMeshContext::build()
{
  Ui::Form f = describeMesh();
  f.id = "mesh";
  return f;
}

#endif
