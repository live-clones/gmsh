// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_HIGH_ORDER_H
#define GMSH_GUI_HIGH_ORDER_H

#include "GuiDialog.h"

// the high order tools, two sections one under the other
class GuiHighOrder : public GuiDialog {
protected:
  Ui::Form build() override;
  void load() override;
};

#endif
