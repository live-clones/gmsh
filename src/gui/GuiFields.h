// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_FIELDS_H
#define GMSH_GUI_FIELDS_H

#include "GuiDialog.h"

// the mesh size fields, what each of them takes, and which is the background
class GuiFields : public GuiTabbed {
protected:
  Ui::Form build() override;
};

#endif
