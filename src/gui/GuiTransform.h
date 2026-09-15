// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_TRANSFORM_H
#define GMSH_GUI_TRANSFORM_H

#include <string>

#include "GuiDialog.h"

// The elementary operation context: translate, rotate, scale, symmetry,
// boolean, fillet, delete. The mesh extrusion fields are offered only when
// the action that opened the dialog extrudes.
class GuiTransform : public GuiTabbed {
public:
  bool extrude = false;
  using GuiTabbed::show;
  void show(const std::string &pane, bool extrude);

protected:
  Ui::Form build() override;
};

#endif
