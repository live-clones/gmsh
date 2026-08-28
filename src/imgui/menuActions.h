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

#include "GuiMenus.h"

class appWindow;

// Draw a shared menu description: the menu bar itself, and the quick access
// menu the status bar drops. Every entry queues its action with
// appWindow::postAction(), so that it runs outside of the frame.
void menuWalk(const std::vector<Menu::Item> &items, appWindow *app);

#endif

#endif
