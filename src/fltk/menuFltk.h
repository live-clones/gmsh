// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MENU_FLTK_H
#define MENU_FLTK_H

#include <functional>
#include <string>
#include <vector>

#include "GuiMenus.h"

#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>

// The FLTK side of the menu description of src/common/GuiMenus.h: it flattens
// the description into the Fl_Menu_Item[] that Fl_Menu_Bar wants, which is what
// bar_table[] and sysbar_table[] used to be, written by hand.

// Build, or build again, the menu bar of the main window. The table it returns
// stays valid until the next call, and only until then: pass it to menu()
// straight away. Set systemBar for the macOS menu bar, which has no mnemonics
// and provides its own Quit.
Fl_Menu_Item *fltkMenuBuild(bool systemBar);

// Bring the check marks and the greying up to date. Cheap, and only needed just
// before the menu is shown, which is what menuBarFltk does.
void fltkMenuRefresh();

// Pop up a menu built from a shared description at the given place on the
// screen, and run whatever the user picked. This is what the option button of
// the status bar drops. The menu opens under the entry that was picked last
// time, as the hand-written one did.
void fltkMenuPopup(const std::vector<Menu::Item> &tree, int x, int y);

// Walk the shared description of the modules tree and hand each leaf to add(),
// with the "0Modules/..." path the FLTK tree wants. The entries stay valid
// until the next call.
void fltkModulesBuild(
  const std::function<void(const std::string &path, Fl_Callback *cb,
                           void *data)> &add);

// A menu bar that refreshes itself before it opens. The check marks of the
// entries that show and hide a panel would otherwise show the state the panel
// had when the menu was last built.
class menuBarFltk : public Fl_Menu_Bar {
public:
  menuBarFltk(int x, int y, int w, int h) : Fl_Menu_Bar(x, y, w, h) {}
  int handle(int event) override
  {
    if(event == FL_PUSH || event == FL_SHORTCUT) fltkMenuRefresh();
    return Fl_Menu_Bar::handle(event);
  }
};

#endif
