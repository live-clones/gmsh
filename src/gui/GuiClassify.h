// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_CLASSIFY_H
#define GMSH_GUI_CLASSIFY_H

#include "GuiDialog.h"

// turning a triangulation into a model: what to detect the edges on, which
// of them to keep, and the reclassification itself
class GuiClassify : public GuiDialog {
protected:
  Ui::Form build() override;
  void load() override;
};

#endif
