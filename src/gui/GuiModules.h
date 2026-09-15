// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MODULES_H
#define GMSH_GUI_MODULES_H

#include "GmshConfig.h"
#include "Tree.h"

// The tree down the left side of the interface, as one thing: the
// commands at the top and whatever a solver has published underneath,
// said as a Ui::Tree -- a model rather than a list, so that what is asked
// for is what is open rather than what exists.

namespace Modules {

  Ui::Tree tree();

  // its shape has changed -- a module gained an entry, a solver published a
  // parameter -- so that an interface holding real widgets builds them
  // again; what a node says is read every time it is drawn
  void invalidate();

} // namespace Modules

#endif
