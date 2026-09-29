// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_BAR_H
#define UI_BAR_H

#include <functional>
#include <string>
#include <vector>

#include "Form.h"
#include "Menu.h"


namespace Ui {

  struct BarButton {
    // glyph names a picture of Glyph.h, shown instead of the label
    std::string label, glyph;
    // the play button says pause while it plays
    std::string labelOn, glyphOn;
    std::string tooltip;
    // reverse is Shift, sync is Control
    std::function<void(bool reverse, bool sync)> action;
    std::function<std::vector<MenuItem>()> menu;
    std::function<bool()> enabled;
    std::function<bool()> on;
    // while on, painted in a colour of its own: the colour of what it leaves
    // on the picture
    std::function<Colour()> onColour;
    std::function<bool()> alert;
    bool gapBefore;
    double widthEm;
    BarButton() : gapBefore(false), widthEm(0.) {}
  };

  // the colour is the interface's
  enum MessageWeight { MessageOrdinary = 0, MessageWarning, MessageError };

  struct BarMessage {
    std::string text;
    MessageWeight weight;
    bool running;
    double fraction;
    std::string progressText;
  };

  // what makes the buttons of the bar be made again: their labels, their
  // gaps and which have a menu (what is on and enabled is only refreshed)
  std::string signature(const std::vector<BarButton> &buttons);

} // namespace Ui

#endif
