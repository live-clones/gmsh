// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PLUGINS_H
#define GMSH_GUI_PLUGINS_H

#include <string>
#include <vector>

#include "GuiDialog.h"

// the plugins, what each of them takes, and what it is run on
class GuiPlugins : public GuiTabbed {
  std::string plugin;
  std::vector<char> views;
  bool record = false;
  void run();

public:
  using GuiTabbed::show;
  void showForView(int view);

protected:
  Ui::Form build() override;
};

#endif
