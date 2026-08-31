// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MODULES_H
#define GMSH_GUI_MODULES_H

#include "GmshConfig.h"
#include "Tree.h"

// The tree down the left side of the interface, as one thing.
//
// It is one widget in the interface it reproduces -- a single Fl_Tree holding
// the commands at the top and whatever a solver has published underneath --
// and it was described as two: the commands as a list of Menu::Item, which is
// an abuse since they are not menus, and the parameters not at all, each
// interface building them from the ONELAB database by hand. That is why the
// file that does it is the one that still knows the most about Gmsh.
//
// This is the whole of it, said as a Ui::Tree: a model rather than a list, so
// that what is asked for is what is open rather than what exists.

namespace Modules {

  Ui::Tree tree();

  // Say that its shape has changed -- a module gained an entry, a solver
  // published a parameter -- so that an interface holding real widgets builds
  // them again. What a node *says* is read every time it is drawn and is not
  // a change of shape.
  void invalidate();

} // namespace Modules

#endif
