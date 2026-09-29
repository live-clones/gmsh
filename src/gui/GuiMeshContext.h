// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MESH_CONTEXT_H
#define GMSH_GUI_MESH_CONTEXT_H

#include <string>
#include "GuiDialog.h"

// the size and the transfinite constraints of what one then selects
class GuiMeshContext : public GuiTabbed {
public:
  std::string meshSize = "0.1";
  std::string transfinitePoints = "10";
  std::string transfiniteType = "Progression";
  std::string transfiniteParameter = "1";
  std::string transfiniteArrangement = "Left";

private:
  Ui::Form build() override;
};

#endif
