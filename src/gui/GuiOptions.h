// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_OPTIONS_H
#define GMSH_GUI_OPTIONS_H

#include <string>

#include "GuiDialog.h"

// laid out by hand in GuiOptions.cpp
class GuiOptions : public GuiTabbed {
public:
  int category = 0;
  int view = 0;
  using GuiTabbed::show;
  // -1 is the view it is already on; pane names the tab, "Map" for the colour
  // map
  void showForView(int view, const std::string &pane = "");

protected:
  Ui::Form build() override;
};

#endif
