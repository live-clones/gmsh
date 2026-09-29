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

// a hierarchy whose lines are fields; a model rather than a list: asking for
// the children of what is open costs what is shown, not what exists

namespace Ui {

  struct Node {
    // a node is its path, "Mesh/Algorithm": nothing else identifies it, which
    // is what survives a rebuild
    std::string path;
    // empty takes the last component of the path
    std::string label;
    std::string tooltip;
    // a node without one is a heading, which may still be pressed
    bool hasField;
    Field field;
    std::function<void()> pressed;
    // picking a line that gathers others picks them too
    std::function<bool()> picked;
    std::function<void(bool)> pick;
    std::function<bool()> enabled;
    std::function<std::vector<MenuItem>()> menu;
    // four bytes for the reason Form.h gives for Colour
    Colour highlight;
    // folded when the tree is built; what is folded afterwards is the tree's
    bool closed;
    Node() : hasField(false), highlight(0, 0, 0, 0), closed(false) {}
  };

  struct Tree {
    // in the order drawn; the empty path is the root
    std::function<std::vector<std::string>(const std::string &parent)> children;
    std::function<Node(const std::string &path)> node;
    // changes with the shape of the tree; what a node shows is not a change of
    // shape
    std::function<unsigned()> generation;
    // survives a rebuild, is written to the option file, and a parameter may
    // arrive asking for it
    std::function<bool(const std::string &path)> closed;
    std::function<void(const std::string &path, bool closed)> setClosed;
    std::function<std::vector<Button>()> footer;
  };


} // namespace Ui

#endif
