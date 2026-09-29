// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_GROUP_H
#define ONELAB_GROUP_H

#include <deque>
#include <functional>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Button.H>

#include "Tree.h"

// The modules tree of this interface, read from Ui::Tree: it knows the
// tree only as Tree.h says it, and puts a widget on every line the
// description gives one to.

class onelabGroup : public Fl_Group {
private:
  Fl_Tree *_tree;
  std::vector<Fl_Widget *> _treeWidgets;
  // the buttons under the tree, made again from the description each time
  std::vector<Fl_Widget *> _footer;
  double _baseWidth, _indent;
  int _minWindowWidth, _minWindowHeight;
  double _widgetLabelRatio;
  bool _enableTreeWidgetResize;
  bool _firstBuild;
  void _computeWidths();
  // what one line holds: the field the description gives it, or a button
  // that presses it, and the menu it drops at its right end
  void _addLine(const std::string &path, const Ui::Node &node, bool branch);
  void _addFooter();
  static void _treeCallback(Fl_Widget *w, void *data);

public:
  onelabGroup(int x, int y, int w, int h, const char *l = nullptr);
  void rebuildTree(bool deleteWidgets);
  void rebuildFooter();
  void enableTreeWidgetResize(bool value) { _enableTreeWidgetResize = value; }
  void redrawTree() { _tree->redraw(); }
  void openTreeItem(const std::string &name);
  void closeTreeItem(const std::string &name);
  bool isTreeItemOpen(const std::string &name);
  int getMinWindowWidth() { return _minWindowWidth; }
  int getMinWindowHeight() { return _minWindowHeight; }
  std::string getPath(Fl_Tree_Item *item);
};

#endif
