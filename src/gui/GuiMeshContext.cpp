// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include "GuiMeshContext.h"
#include "GuiDeclare.h"

using namespace Declare;

Form GuiMeshContext::build()
{
  return {
    "mesh", "Mesh Context",
    tabs({{"Element size", text("Value", &meshSize)},
          {"Transfinite curve",
           vbox({text("Number of points", &transfinitePoints),
                 choice("Type", &transfiniteType,
                        {"Progression", "Bump", "Beta", "Progression_HWall",
                         "Bump_HWall", "Beta_HWall"}),
                 text("Parameter", &transfiniteParameter)})},
          {"Transfinite Surface",
           choice("Transfinite Arrangement", &transfiniteArrangement, {"Left", "Right", "Alternated"})}})};
}

#endif
