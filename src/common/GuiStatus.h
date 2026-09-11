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

// The bar along the bottom of the graphic window: a row of little buttons,
// then whatever is left is the last message and the progress of what is
// running. It was twelve buttons built by hand in src/fltk/graphicWindow.cpp,
// indexed in the order they happened to be declared rather than the order they
// are drawn in, and a second row written out again in src/imgui/statusBar.cpp
// -- with different labels, different tooltips and, for the button that says
// whether the mouse picks, the opposite meaning: FLTK paints it red when
// picking is *off*, and the Dear ImGui bar highlighted it when it was on.

namespace StatusBar {

  // The vocabulary a form, a menu and a bar are said in belongs to
  // src/gui and to neither side; what is left here is the catalogue of
  // the ones Gmsh has.
  using namespace Ui;



  // the buttons, in the order they are drawn
  std::vector<BarButton> bar();

  // --- and what takes the rest of the bar: the last message, and the progress
  // of whatever is running
  //
  // It was held in the widgets on one side and in members of appWindow on the
  // other, which is why the sentence the FLTK bar adds when something has gone
  // wrong -- "3 Errors : Click to show messages [ ... ]" -- was in one bar and
  // not the other. There is one copy of it now, and both bars draw it.

  // what Gui::setStatus(), setLastStatus() and setProgress() come down to
  void setMessage(const std::string &text);
  void setColour(int colour); // one of Gui::StatusColor
  void setProgress(double value, double least, double most);


  // what the bar is to draw right now
  BarMessage message();
  // and what clicking it does, which is to show the messages it is telling one
  // to look at
  void messagePressed();
  std::string messageTooltip();

} // namespace StatusBar

#endif
