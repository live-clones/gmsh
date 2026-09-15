// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_ELEMENTARY_H
#define GMSH_GUI_ELEMENTARY_H

#include "GuiDialog.h"

// What to make, one shape per pane. A shape is known to the geometry actions
// by its number, which showShape() turns into the pane.
class GuiElementary : public GuiTabbed {
public:
  void showShape(int shape);

protected:
  Ui::Form build() override;
};

#endif
