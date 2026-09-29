// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MODULES_H
#define GMSH_GUI_MODULES_H

#include "GmshConfig.h"
#include "Tree.h"

// the commands and what a solver has published, as a Ui::Tree: what is asked
// for is what is open rather than what exists

namespace Modules {

  Ui::Tree tree();

  // the shape changed; what a node says is read every time it is drawn
  void invalidate();

} // namespace Modules

#endif
