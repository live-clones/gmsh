// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_CLIPPING_H
#define GMSH_GUI_CLIPPING_H

#include "GuiDialog.h"

// the six planes that cut what is drawn
class GuiClipping : public GuiTabbed {
protected:
  Ui::Form build() override;
  void load() override;
};

#endif
