// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_ELEMENTARY_H
#define GMSH_GUI_ELEMENTARY_H

#include <string>
#include <vector>

#include "GuiDialog.h"

// a shape by number: 0 Parameter, 1 Point, 2 Circle, 3 Ellipse, 4 Disk, 5
// Rectangle, 6 Sphere, 7 Cylinder, 8 Box, 9 Torus, 10 Cone, 11 Wedge, then the
// nine picked in the view
class GuiElementary : public GuiTabbed {
public:
  // for every shape but the parameter, the first three are the X, Y and Z the
  // mouse drives
  std::string value[12][9];
  int shape = 0;
  bool frozen[3] = {false, false, false};
  static int fields(int shape);
  std::vector<std::string> values() const;

  GuiElementary();
  void showShape(int shape);

protected:
  Ui::Form build() override;
};

#endif
