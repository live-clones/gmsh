// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_CLIPPING_H
#define GMSH_GUI_CLIPPING_H

#include "GuiDialog.h"

// the six planes that cut what is drawn, or the box they make
class GuiClipping : public GuiTabbed {
  // which of the six the Planes tab edits
  int plane = 0;
  // whether a value is still being chosen, and what was asked for meanwhile
  bool adjusting = false;
  int capping = 0, wholeElements = 0;
  int settles = 0;
  void update(bool adjusting);
  void invert();
  void reset();
  Ui::Form build() override;
};

#endif
