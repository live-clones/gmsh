// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FLTK_ACTIONS_H
#define FLTK_ACTIONS_H

// The items of the action registry (see Actions.h) in the FLTK graphical user
// interface, whose actions are in the table at the top of fltkActions.cpp:
// - fltkActions() gives the actions the FLTK interface does their run, once,
//   before its menus are made;
// - canRunItem() says whether an item can be used now, canRunAnyItem()
//   whether a menu has such an item;
// - runItem() does what an item does (view is the index of the view, for the
//   menu of a view);
// - addMenuItems() adds the items of a menu to an FLTK menu, where they act
//   on the given view; with marks, the items that toggle or set an option
//   show its value (not in a menu that stays, which would not follow it).

struct actionItem;
class Fl_Menu_;

void fltkActions();
bool canRunItem(const actionItem &item);
bool canRunAnyItem(const actionItem &menu);
void runItem(const actionItem &item, int view = -1);
void addMenuItems(Fl_Menu_ *m, const actionItem &menu, int view,
                  bool marks = true);

#endif
