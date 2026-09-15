// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_BAR_H
#define UI_BAR_H

#include <functional>
#include <string>
#include <vector>

#include "Menu.h"

// The bar along the bottom: a row of little buttons, then the last message
// and the progress of what is running.

namespace Ui {

  struct BarButton {
    // what it says, and the picture an interface that has one draws instead
    std::string label, glyph;
    // and what it says while it is on, for the one button that changes: the
    // play button says pause while it plays
    std::string labelOn, glyphOn;
    std::string tooltip;
    // what pressing it does; `reverse` is Shift and `sync` is Control
    std::function<void(bool reverse, bool sync)> action;
    // a menu it drops rather than doing something, built when it is opened
    std::function<std::vector<MenuItem>()> menu;
    // false greys it out
    std::function<bool()> enabled;
    // it is doing something rather than waiting to be asked
    std::function<bool()> on;
    // it is worth looking at
    std::function<bool()> alert;
    // a gap before it
    bool gapBefore;
    // wider than the square the others are, in multiples of the font size
    double widthEm;
    BarButton() : gapBefore(false), widthEm(0.) {}
  };

  // and what takes the rest of the bar: how a message is to be read, the
  // colour being the interface's
  enum MessageWeight { MessageOrdinary = 0, MessageWarning, MessageError };

  struct BarMessage {
    // the message, with what went wrong appended when the console is hidden
    std::string text;
    MessageWeight weight;
    // is something running? and how far along, between 0 and 1
    bool running;
    double fraction;
    // it says the file it is working on, or how many are done
    std::string progressText;
  };

} // namespace Ui

#endif
