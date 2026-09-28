// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_STATUS_H
#define GMSH_GUI_STATUS_H

#include <functional>
#include <string>
#include <vector>

#include "GmshConfig.h"
#include "GuiMenus.h"
#include "Bar.h"

// the bar along the bottom: buttons, then the last message and the progress of what is running

namespace StatusBar {

  using namespace Ui;



  std::vector<BarButton> bar();


  void setMessage(const std::string &text);
  void setColour(int colour); // one of Gui::StatusColor
  void setProgress(double value, double least, double most);


  BarMessage message();
  void messagePressed();
  std::string messageTooltip();

} // namespace StatusBar

#endif
