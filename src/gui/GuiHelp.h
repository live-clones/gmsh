// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_HELP_H
#define GMSH_GUI_HELP_H

#include <set>
#include <string>
#include <vector>

#include "GuiDialog.h"

// what the keyboard and the mouse do, and what the command line takes
class GuiShortcuts : public GuiDialog {
protected:
  Ui::Form build() override;
};

// what every option is worth right now, and what one may change it to
class GuiCurrentOptions : public GuiDialog {
  // not read again at every frame: PrintOptions() writes out every option
  std::vector<std::string> lines;
  std::vector<std::string> types; // "number", "string", "color" or nothing
  // by the name of the option: changing a value has the listing read again, and
  // the line moves
  std::set<std::string> picked;
  std::string last; // the option whose value is offered below the listing
  bool modifiedOnly = false, withHelp = false;
  std::string filter;
  bool stale = true;
  void read();
  bool optionOf(const std::string &key, std::string &category, int &index,
                std::string &name, std::string &type);

protected:
  Ui::Form build() override;
};

// what this Gmsh is
class GuiAbout : public GuiDialog {
protected:
  Ui::Form build() override;
};

#endif
