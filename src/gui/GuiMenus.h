// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MENUS_H
#define GMSH_GUI_MENUS_H

#include <functional>
#include <string>
#include <vector>

#include "GmshConfig.h"
#include "Menu.h"

// the menus, declared once and walked by every interface; rebuilt from scratch
// when generation() changes, so that what depends on the state is simply read
// again

namespace Menu {

  using namespace Ui;




  // what the interface cannot honour is left out rather than greyed
  std::vector<MenuItem> bar();

  std::vector<MenuItem> models();

  // rebuilt every time it opens: the entries that need a view are not there
  // without one
  std::vector<MenuItem> quickAccess();

  std::vector<MenuItem> viewActions(int index);
  std::vector<MenuItem> solverActions(int index);

  std::vector<MenuItem> solverOptions();

  // stops where the ONELAB parameters begin, which are widgets rather than
  // entries
  std::vector<MenuItem> modules();

  // in the order they are tried, see Ui::KeyBinding
  std::vector<KeyBinding> keys();

  void invalidate();
  unsigned generation();

} // namespace Menu

#endif
