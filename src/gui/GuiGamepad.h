// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_GAMEPAD_H
#define GMSH_GUI_GAMEPAD_H

#include "GuiDialog.h"

// what the gamepad is doing and what each of its buttons and axes is for
class GuiGamepad : public GuiDialog {
protected:
  Ui::Form build() override;
};

#endif
