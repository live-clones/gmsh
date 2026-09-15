// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_VISIBILITY_H
#define GMSH_GUI_VISIBILITY_H

#include "GuiDialog.h"

// what of the model is drawn: the list of entities, by number, by picking,
// and per graphic window
class GuiVisibility : public GuiTabbed {
protected:
  Ui::Form build() override;
};

#endif
