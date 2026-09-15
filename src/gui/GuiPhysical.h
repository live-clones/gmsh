// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PHYSICAL_H
#define GMSH_GUI_PHYSICAL_H

#include <string>

#include "GuiDialog.h"

// The physical group context: what kind of entity the group gathers, and
// whether it is being added to or removed from -- the action that opens the
// dialog says.
class GuiPhysical : public GuiTabbed {
public:
  std::string type = "Point";
  bool remove = false;
  using GuiTabbed::show;
  void show(const std::string &type, bool remove);

protected:
  Ui::Form build() override;
  void load() override;
};

#endif
