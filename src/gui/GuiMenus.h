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

// The menus of the graphical user interface, declared once and walked by
// every interface: same entries in the same order, same separators, same
// shortcuts.
//
// The description is rebuilt from scratch rather than mutated, so that what
// depends on the state of the application -- the recent files -- is simply
// read again while it is built. The interfaces rebuild when generation()
// changes.

namespace Menu {

  using namespace Ui;




  // the menu bar; whatever the running interface cannot honour is left out
  // rather than shown greyed
  std::vector<MenuItem> bar();

  // the models that are loaded, which the status bar drops on its first
  // button: picking one makes it the current model
  std::vector<MenuItem> models();

  // the menu the status bar drops on its option button, rebuilt every time
  // it opens so that the entries that only make sense with a view are not
  // there when there is none
  std::vector<MenuItem> quickAccess();

  // the menu a post-processing view carries in the modules tree, on the
  // view of the given index: what to do to it, and what to do to every view
  // at once
  std::vector<MenuItem> viewActions(int index);
  // and the one a solver carries, in the same place
  std::vector<MenuItem> solverActions(int index);

  // the gear menu of the modules tree: the database, the eight things the
  // solver may do by itself, and adding another solver
  std::vector<MenuItem> solverOptions();

  // the modules tree: the geometry and mesh commands; it stops where the
  // ONELAB parameters begin, which are widgets rather than entries
  std::vector<MenuItem> modules();

  // the keys, wherever the pointer is: what the bar and the quick access
  // menu bind, and after them the keys of the 3D view that are in no menu;
  // in the order they are tried, see Ui::KeyBinding
  std::vector<KeyBinding> keys();

  // what the menus show has changed -- a file was opened, a model was added
  // -- so the interfaces build them again
  void invalidate();
  unsigned generation();

} // namespace Menu

#endif
