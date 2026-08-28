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

// The bar along the bottom of the graphic window: a row of little buttons,
// then whatever is left is the last message and the progress of what is
// running. It was twelve buttons built by hand in src/fltk/graphicWindow.cpp,
// indexed in the order they happened to be declared rather than the order they
// are drawn in, and a second row written out again in src/imgui/statusBar.cpp
// -- with different labels, different tooltips and, for the button that says
// whether the mouse picks, the opposite meaning: FLTK paints it red when
// picking is *off*, and the Dear ImGui bar highlighted it when it was on.

namespace StatusBar {

  struct Button {
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
    std::function<std::vector<Menu::Item>()> menu;
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
    Button() : gapBefore(false), widthEm(0.) {}
  };

  // the buttons, in the order they are drawn
  std::vector<Button> bar();

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

  struct Message {
    // the message, with what went wrong appended when the console is hidden
    std::string text;
    int colour;
    // is something running? and how far along, between 0 and 1
    bool running;
    double fraction;
    // it says the file it is working on, or how many are done
    std::string progressText;
  };

  // what the bar is to draw right now
  Message message();
  // and what clicking it does, which is to show the messages it is telling one
  // to look at
  void messagePressed();
  std::string messageTooltip();

} // namespace StatusBar

#endif
