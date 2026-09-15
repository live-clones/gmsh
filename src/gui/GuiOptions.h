// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_OPTIONS_H
#define GMSH_GUI_OPTIONS_H

#include <string>

#include "GuiDialog.h"

// Every option there is, laid out by hand in GuiOptions.cpp: a tab per
// category, and one per post-processing view after them.
class GuiOptions : public GuiTabbed {
public:
  // which category it is showing, so that a menu can open it on the one it
  // is about rather than on whichever was last looked at
  int category = 0;
  // and which post-processing view its View options are editing: what an
  // option of a view asks to know whether it is the one on screen
  int view = 0;
  using GuiTabbed::show;
  // Show it on a view: the one given, or the one it is already on when that
  // is -1. The categories before the views are not for anyone else to
  // count. `pane` names the tab to open it on -- "Map" for the colour map
  // of a view -- and shows whichever was last looked at when it is empty.
  void showForView(int view, const std::string &pane = "");

protected:
  Ui::Form build() override;
};

#endif
