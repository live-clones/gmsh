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

// The menus of the graphical user interface, declared once and built by both
// interfaces. What used to be bar_table[] in src/fltk/graphicWindow.cpp on one
// side and a series of BeginMenu()/MenuItem() calls in src/imgui/menuBar.cpp on
// the other is now one description that each interface walks: same entries in
// the same order, same separators, and -- this is the part duplication could
// not keep honest -- the same shortcuts. A label saying "Ctrl+H" and a handler
// doing something else is a kind of drift no comparison of structures catches,
// because both structures look right.
//
// The description is rebuilt from scratch rather than mutated, so that what
// depends on the state of the application -- the recent files -- is simply read
// again while it is built. The interfaces rebuild when generation() changes.

namespace Menu {

  // The vocabulary a form, a menu and a bar are said in belongs to
  // src/gui and to neither side; what is left here is the catalogue of
  // the ones Gmsh has.
  using namespace Ui;




  // The menu bar. Whatever the running interface cannot honour is left out
  // rather than shown greyed: an interface with a single window has nothing to
  // bring to the front, and one that cannot reach the clipboard should not
  // offer to.
  std::vector<MenuItem> bar();

  // The models that are loaded, which the status bar drops on its first
  // button: picking one makes it the current model.
  std::vector<MenuItem> models();

  // The menu the status bar drops on its option button: what one reaches for
  // most often, gathered in one place. It is rebuilt every time it opens, so
  // the entries that only make sense with a post-processing view are simply
  // not there when there is none, which is what the FLTK menu did by hiding
  // them -- with the indices of the entries to hide written out by hand.
  std::vector<MenuItem> quickAccess();

  // The menu a post-processing view carries in the modules tree, on the view
  // of the given index: what to do to it, and what to do to every view at
  // once. The FLTK interface pops it up on the little arrow beside the view;
  // the Dear ImGui one on a right click.
  std::vector<MenuItem> viewActions(int index);
  // and the one a solver carries, in the same place
  std::vector<MenuItem> solverActions(int index);

  // The gear menu of the modules tree: the database, the eight things the
  // solver may do by itself, and adding another solver. The FLTK tree had all
  // thirteen and kept their check marks in step by hand, with the places of
  // the switchable ones written out as two indices; the Dear ImGui tree had
  // three of them, as buttons.
  std::vector<MenuItem> solverOptions();

  // The modules tree: the geometry and mesh commands, in the order the FLTK
  // tree has always shown them. It stops where the ONELAB parameters begin --
  // those are widgets, not entries, and each interface builds them itself.
  std::vector<MenuItem> modules();

  // Say that what the menus show has changed -- a file was opened, a model was
  // added -- so that the interfaces build them again.
  void invalidate();
  unsigned generation();

} // namespace Menu

#endif
