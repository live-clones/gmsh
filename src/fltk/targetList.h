// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TARGET_LIST_H
#define TARGET_LIST_H

#include <string>
#include <vector>
#include <FL/Fl_Group.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

// The list of what a tool applies to (views, or the geometry, the mesh and the
// views), several of which are chosen at once with Ctrl+click and
// Shift+click; below it, a line that says what is chosen and buttons that
// choose common sets
class targetList : public Fl_Group {
private:
  int _rowHeight;
  std::vector<Fl_Button *> _buttons;

public:
  Fl_Multi_Browser *browser;
  Fl_Box *count;
  // each button calls cb with its label as data
  targetList(int x, int y, int w, int rowHeight,
             const std::vector<const char *> &buttons, Fl_Callback *cb);
  // as tall as n entries, from 2 to 6 lines, with the line of buttons
  int heightFor(int n) const;
  void resize(int x, int y, int w, int h);
  // the name of view i in a list: "[i] name"
  static std::string viewName(int i);
  // chooses the lines for which = "All", "Visible" or anything else (none);
  // the views start at line first (the lines before are visible), and the
  // line of view keep, if any, is always chosen
  void selectViews(const std::string &which, int first = 0, int keep = -1);
  int selectedCount() const;
};

#endif
