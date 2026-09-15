// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MESH_CONTEXT_H
#define GMSH_GUI_MESH_CONTEXT_H

#include "GuiDialog.h"

// "Mesh Context": what the mesh of an entity is told -- its size, its
// transfinite constraints -- on what one then selects.
class GuiMeshContext : public GuiTabbed {
protected:
  Ui::Form build() override;
};

#endif
