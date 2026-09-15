// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_STATISTICS_H
#define GMSH_GUI_STATISTICS_H

#include <string>

#include "GuiDialog.h"

// What the model is made of, and how good the mesh is. Counted when it
// opens, and opened on the pane with something in it.
class GuiStatistics : public GuiTabbed {
public:
  void show(const std::string &pane = "");

protected:
  Ui::Form build() override;
};

#endif
