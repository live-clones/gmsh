// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_HELP_H
#define GMSH_GUI_HELP_H

#include "GuiDialog.h"

// what the keyboard and the mouse do, and what the command line takes
class GuiShortcuts : public GuiDialog {
protected:
  Ui::Form build() override;
};

// what every option is worth right now, and what one may change it to
class GuiCurrentOptions : public GuiDialog {
protected:
  Ui::Form build() override;
};

// what this Gmsh is
class GuiAbout : public GuiDialog {
protected:
  Ui::Form build() override;
};

#endif
