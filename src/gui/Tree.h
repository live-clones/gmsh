// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_TREE_H
#define UI_TREE_H

#include <functional>
#include <string>
#include <vector>

#include "Form.h"
#include "Menu.h"

// A hierarchy one folds and unfolds, whose lines carry widgets.
//
// It is the second container of this vocabulary, beside Form, and it shares
// its atom: a form is a list of fields, a tree is a hierarchy whose lines are
// fields. Which is the whole point -- the three trees of Gmsh are described
// three different ways today, and are one widget in the interface that has
// them:
//
//   the modules tree, whose upper half is written as a list of Menu::Item,
//   which is an abuse: they are not menus, they only happened to look like
//   entries with an action;
//
//   the ONELAB parameters under it, which are not described at all -- the
//   interfaces build them from the database by hand, which is why the file
//   that does it is the one that still knows the most about Gmsh;
//
//   the entities of the visibility panel, written as a flat list of lines
//   carrying a depth, which is a tree with its shape thrown away.
//
// It is a model rather than a list, and that is deliberate. A list means the
// whole tree is handed over every time it is drawn, and the tree of the
// entities of a large model has more lines than anyone wants to hand over
// sixty times a second -- let alone push through a socket, which is what a
// backend that is not in this process would have to do. Asking for the
// children of what is open costs what is shown, not what exists.

namespace Ui {

  struct Node {
    // Where it is, and what it is: a node is its path, "/" separated, as in
    // "0Modules/Mesh/Define" or "Mesh/Algorithm". Nothing else identifies it,
    // which is what lets what is folded, and what is being edited, survive a
    // tree that is built again from nothing.
    std::string path;
    // What it says. Empty takes the last component of the path, which is what
    // nearly every node wants.
    std::string label;
    std::string tooltip;
    // What it carries beside its label. A node without one is a heading --
    // and a heading may still be pressed, which is how the tree toggles a
    // whole group of views, or highlights a physical group.
    bool hasField;
    Field field;
    std::function<void()> pressed;
    // A menu it drops: on a right click, or on the little arrow the FLTK tree
    // draws at the end of its line. A post-processing view carries what to do
    // to it that way, and a solver what to run.
    std::function<std::vector<MenuItem>()> menu;
    // Drawn as something to be looked at rather than as an ordinary line, in
    // the colour packed here; zero for an ordinary one. A solver says which
    // parameters it is waiting on that way, through the Highlight attribute.
    unsigned int highlight;
    // Folded when the tree is built, for a node that arrives asking to be:
    // what is folded afterwards is the tree's, below, not the node's.
    bool closed;
    Node() : hasField(false), highlight(0), closed(false) {}
  };

  struct Tree {
    // The children of a node, in the order they are to be drawn; the empty
    // path is the root. In the order they are drawn, and not sorted by the
    // interface: the FLTK tree sorts its lines alphabetically, which is why
    // the modules of Gmsh are called "0Modules" -- a hack that can go once the
    // order is said rather than arranged.
    std::function<std::vector<std::string>(const std::string &parent)> children;
    // what one node holds, asked again every time it is drawn
    std::function<Node(const std::string &path)> node;
    // Changes when the *shape* of the tree changed -- a parameter appeared, a
    // view was loaded, a model was opened -- so that an interface holding real
    // widgets knows when to build them again instead of doing it at every
    // frame. What a node *shows* is read again every time and is not a change
    // of shape.
    std::function<unsigned()> generation;
    // Which nodes are folded is the tree's own and not the interface's: it has
    // to survive a rebuild, it is written to the option file, and a parameter
    // may arrive asking for it.
    std::function<bool(const std::string &path)> closed;
    std::function<void(const std::string &path, bool closed)> setClosed;
  };

  // What Form.h has to gain for a node to be able to carry a ONELAB
  // parameter, which is the case that decides whether Field is the right
  // atom. Going through addParameterWidget() in both of its overloads, a
  // parameter is a value -- which Field already says, as a Number, a Choice,
  // a Check or an Output -- with up to three little controls after it:
  //
  //   the range button, which edits the least, the most and the step;
  //   the loop toggle, at one of three levels, for a parameter sweep;
  //   the graph menu, saying which of the nine plots the value is reported in;
  //
  // and a string parameter has two more of the same shape: the menu of a file
  // -- choose, edit, merge -- and the toggles of a multiple selection.
  //
  // Five controls, one shape: a little button after the field, which may drop
  // a menu and may be on. So Field gains one member rather than five flags,
  //
  //   std::vector<Button> trailing;
  //
  // and Button, which is a label and an action today, gains the two things
  // those five need: a menu it drops instead of acting, and whether it is on.
  // Nothing else in the description of a ONELAB parameter is missing, which
  // is the answer to the question this file was written to settle.

} // namespace Ui

#endif
