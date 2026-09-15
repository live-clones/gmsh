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

// A hierarchy one folds and unfolds, whose lines carry widgets: a form is a
// list of fields, a tree is a hierarchy whose lines are fields.
//
// It is a model rather than a list: asking for the children of what is open
// costs what is shown, not what exists, which matters for the entities of a
// large model and for a backend that is not in this process.

namespace Ui {

  struct Node {
    // Where it is, and what it is: a node is its path, "/" separated, as in
    // "Mesh/Algorithm". Nothing else identifies it, which is what lets what is
    // folded, and what is being edited, survive a tree that is built again.
    std::string path;
    // what it says; empty takes the last component of the path
    std::string label;
    std::string tooltip;
    // what it carries beside its label; a node without one is a heading, and
    // a heading may still be pressed
    bool hasField;
    Field field;
    std::function<void()> pressed;
    // a line one may pick, and whether it is picked; empty on a heading.
    // Picking a line that gathers others picks them too, which is the tree's to
    // say.
    std::function<bool()> picked;
    std::function<void(bool)> pick;
    // false greys the line out
    std::function<bool()> enabled;
    // a menu it drops, on a right click or on an arrow at the end of the line
    std::function<std::vector<MenuItem>()> menu;
    // drawn as something to be looked at, in this colour; four bytes for the
    // reason Form.h gives for Colour
    Colour highlight;
    // folded when the tree is built, for a node that arrives asking to be;
    // what is folded afterwards is the tree's, below
    bool closed;
    Node() : hasField(false), highlight(0, 0, 0, 0), closed(false) {}
  };

  struct Tree {
    // the children of a node, in the order they are to be drawn and not sorted
    // by the interface; the empty path is the root
    std::function<std::vector<std::string>(const std::string &parent)> children;
    // what one node holds, asked again every time it is drawn
    std::function<Node(const std::string &path)> node;
    // changes when the shape of the tree changed -- a line more or less --
    // for an interface holding real widgets; what a node shows is read again
    // every time and is not a change of shape
    std::function<unsigned()> generation;
    // which nodes are folded is the tree's own: it survives a rebuild, is
    // written to the option file, and a parameter may arrive asking for it
    std::function<bool(const std::string &path)> closed;
    std::function<void(const std::string &path, bool closed)> setClosed;
    // the buttons under it, which belong to the tree rather than to whatever
    // panel holds it
    std::function<std::vector<Button>()> footer;
  };


} // namespace Ui

#endif
