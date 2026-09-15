// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PLUGINS_H
#define GMSH_GUI_PLUGINS_H

#include "GuiDialog.h"

// the plugins, what each of them takes, and what it is run on
class GuiPlugins : public GuiTabbed {
public:
  using GuiTabbed::show;
  // with that view picked, as the button of a view does
  void showForView(int view);

protected:
  Ui::Form build() override;
};

#endif
