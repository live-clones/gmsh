// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MANIPULATOR_H
#define GMSH_GUI_MANIPULATOR_H

#include "GuiDialog.h"

// the rotation, translation and scale of the view
class GuiManipulator : public GuiDialog {
protected:
  Ui::Form build() override;
};

#endif
