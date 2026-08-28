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

// The entries of the menu bar that need a dialog of their own, and are
// therefore neither a plain toolkit-independent action of GuiActions.h nor a
// simple flag. They live in menuBar.cpp, next to the menu that uses them, and
// are declared here because the keyboard accelerators of shortcuts.cpp trigger
// the same ones. Like every other menu action, they open blocking dialogs and
// must only be called from an action posted with appWindow::postAction().

void menuNew();
void menuOpen();
void menuMerge();
// open the file of the given index in General.RecentFile<i>
void menuOpenRecent(int index);
void menuRename();
void menuExport();
void menuWatchPattern();
#if defined(HAVE_ONELAB)
// what is "start", "merge", "clear" or "stop"; see remoteAction()
void menuRemote(const std::string &what);
#endif

#endif

#endif
