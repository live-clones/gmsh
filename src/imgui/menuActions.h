// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MENU_ACTIONS_H
#define MENU_ACTIONS_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <string>
#include <vector>

#include "Menu.h"

class appWindow;

// the menu bar and the quick access menu; every entry queues its action with
// postAction()
void menuWalk(const std::vector<Ui::MenuItem> &items, appWindow *app);

#endif

#endif
