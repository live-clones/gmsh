// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PARTITION_H
#define GMSH_GUI_PARTITION_H

#include "GuiDialog.h"

// the mesh partitioner: the Mesh.Partition* and Mesh.Metis* options, and
// the button that runs it
class GuiPartition : public GuiDialog {
  bool advanced = false;
  Ui::Form build() override;
};

#endif
