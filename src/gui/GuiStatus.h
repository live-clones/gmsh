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

// The bar along the bottom of the graphic window: a row of little
// buttons, then whatever is left is the last message and the progress of
// what is running.

namespace StatusBar {

  using namespace Ui;



  // the buttons, in the order they are drawn
  std::vector<BarButton> bar();

  // --- and what takes the rest of the bar: the last message, and the
  // progress of whatever is running

  // what Gui::instance().setStatus(), setLastStatus() and setProgress() come down to
  void setMessage(const std::string &text);
  void setColour(int colour); // one of Gui::StatusColor
  void setProgress(double value, double least, double most);


  // what the bar is to draw right now
  BarMessage message();
  // and what clicking it does: show the messages it is telling one to look
  // at
  void messagePressed();
  std::string messageTooltip();

} // namespace StatusBar

#endif
