// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PROMPTS_H
#define GMSH_GUI_PROMPTS_H

#include <string>

#include "GuiDialog.h"

// The little windows that ask one thing: a value, a shape, a command.

// One option, asked for on its own: the quick access menu of the status bar
// opens it on the entries that take a value rather than a switch -- the
// clipping factor, the mesh size factor, the number of intervals of a view.
class GuiOptionValue : public GuiDialog {
public:
  using GuiDialog::show;
  // On that option, between those bounds. `title` is what the window is
  // called; the value applies as it is typed, and `applyTo` "view" copies
  // it to every visible view, which is what the menu entries that act on
  // the views mean.
  void show(const std::string &category, int index, const std::string &name,
            const std::string &title, double minimum, double maximum,
            double step, const std::string &applyTo = "");

protected:
  Ui::Form build() override;
};

// the shape of the arrows a vector view is drawn with
class GuiArrow : public GuiDialog {
protected:
  Ui::Form build() override;
};

// A command, with the ones given before it: the remote solver to start and
// the pattern of the files to watch are both asked for that way.
class GuiHistory : public GuiDialog {
public:
  void showRemoteCommand();
  void showWatchPattern();

protected:
  Ui::Form build() override;
};

#endif
