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

// The bar along the bottom: a row of little buttons, then whatever is left is
// the last message and the progress of what is running.

namespace Ui {

  struct BarButton {
    // What it says. FLTK has pictures of its own for a few of them -- the
    // stack of models, the arrows of the animation -- so the description names
    // the picture as well as the text: an interface that has it draws it, and
    // one that has not falls back on the text.
    std::string label, glyph;
    // and what it says while it is on, for the one button that changes: the
    // play button says pause while it plays
    std::string labelOn, glyphOn;
    std::string tooltip;
    // What pressing it does. `reverse` is Shift and `sync` is Control, which
    // the buttons that orient the view read; the others ignore them.
    std::function<void(bool reverse, bool sync)> action;
    // A menu it drops rather than doing something. Built when it is opened, as
    // every menu of GuiMenus.h is.
    std::function<std::vector<MenuItem>()> menu;
    // false greys it out: there is nothing to animate until a view has several
    // time steps
    std::function<bool()> enabled;
    // it is doing something rather than waiting to be asked
    std::function<bool()> on;
    // it is worth looking at: the button that picks with the mouse says so
    // when picking is off, which is not what one usually wants
    std::function<bool()> alert;
    // a gap before it, as the bar leaves one before the animation
    bool gapBefore;
    // wider than the square the others are, in multiples of the font size:
    // "1:1" does not fit in a square
    double widthEm;
    BarButton() : gapBefore(false), widthEm(0.) {}
  };

  // and what takes the rest of the bar
  struct BarMessage {
    // the message, with what went wrong appended when the console is hidden
    std::string text;
    int colour;
    // is something running? and how far along, between 0 and 1
    bool running;
    double fraction;
    // it says the file it is working on, or how many are done
    std::string progressText;
  };

} // namespace Ui

#endif
