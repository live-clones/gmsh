// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ACTIONS_H
#define ACTIONS_H

#include <functional>
#include <string>
#include <vector>
#include "Shortcuts.h"

class drawContext;

// The menus of Gmsh's two interfaces, the FLTK graphical user interface
// (src/fltk) and the web page (contrib/webapp), each item with what it does,
// in one place: Actions.cpp. The Geometry and Mesh modules are menus too,
// shown as rows of buttons.
//
// A click on an item, or a key (which runs the item of its name), goes to one
// function of each interface (fltkActions.cpp for the FLTK interface,
// onelab.html for the web page), runItem(), which does what the item is:
//
//   click ─┐
//   key   ─┴─> runItem(item)
//               ├─ an operation      startOperation()
//               ├─ a shape           startShape()
//               └─ an action         item.run, then the interface shows what
//                                    it changed (RunItem() in the FLTK
//                                    interface)
//
// The run of an action is Gmsh's, written in its item in Actions.cpp, or the
// interface's: each gives its own actions their run when it starts (with
// SetItemRun()), from one table of names, the FLTK interface's at the top of
// fltkActions.cpp, the web page's pageActions in onelab.html. An item without
// run is not shown.
//
// The items, as Actions.cpp makes them:
//   action("2D", "mesh_2d", "Mesh the surfaces",     Gmsh does it
//          [](int view, drawContext *ctx) { ... })
//   guiAction("Size fields", "mesh_size_fields")     the interfaces do it
//   option("Nodes", "Mesh.Nodes")                    a check box
//   option("Iso-values", "View.IntervalsType=1")     a radio item
//   operation("Union", "boolean_union")              on entities picked
//   shape("Box", "add_box")                          from the values of a form
//   menu("Delete", "help", {...}), group({...})      a submenu, a group
//   action(...).key('2').key(KeyF1 + 1)              its keyboard shortcuts
//
// Names are keys, in snake case, starting with what they act on ("mesh_2d",
// "views_remove_all", "boolean_union", "add_box"; an option is named as the
// option). The keys of an item (see Shortcuts.h) are declared on one of the
// items of its name, and every item of that name shows them. What the user
// reads is the label of an item, never its name.
//
// How to add...
// - Something Gmsh does: an action() in its menu in Actions.cpp, or in
//   keysOnly() for a key in no menu. Nothing else to do.
// - Something an interface shows (a window, a file chooser): a guiAction() in
//   its menu (in keysOnly() for a key in no menu), and a line in the table of
//   each interface that has it: the FLTK interface's in fltkActions.cpp, the
//   web page's pageActions in onelab.html. An interface without it does not
//   show the item.
// - An option: option(), or presets() for a submenu of its values.
// - A key: .key('2') on the item it runs (modifiers and flags as in
//   Shortcuts.h); the help of the item says what the key does in the help
//   window and the documentation. A key that is in no menu: an item of
//   keysOnly(), whose help is that text.
// - An operation: what it picks and writes in the script, in the constructor
//   of selectionDriver, then its operation() item. The web page makes its
//   form from its fields; the FLTK interface reads them from its context
//   windows (dialogValue() in fltkActions.cpp), where a new field needs a
//   widget.
// - A shape: in scriptShapes() and scriptAddShape()
//   (scriptStringInterface.cpp), then its shape() item. The desktop places it
//   with the mouse or from a pane of its elementary context window
//   (contextWindow.cpp), the web page from a form.

// The kind of an item: a menu (or, without label, a group set apart), an
// action (its run), an operation on the entities picked in the scene (see
// selectionDriver), or a shape added from the values of its fields (see
// scriptShapes()); the interface starts the last two
enum itemKind { ItemMenu, ItemAction, ItemOperation, ItemShape };

// An item of a menu
struct actionItem {
  std::string label;
  itemKind kind;
  // the name of the action, operation, shape or option
  std::string name;
  // the items of a menu
  std::vector<actionItem> items;
  // the tooltip
  std::string help;
  // for an action: what it does (empty if no interface gave it one yet; view
  // is the index of the view whose menu it is in, ctx the scene whose point
  // of view it changes), when it applies (always if empty), and its check
  // mark (none if empty; else 0 or 1, for a check box or a radio item)
  std::function<void(int view, drawContext *ctx)> run;
  std::function<bool()> available;
  std::function<int()> check;
  // the keyboard shortcuts of an action (see Shortcuts.h)
  std::vector<Shortcut> keys;
  // the item with a key added: action(...).key('2').key(KeyF1 + 1)
  actionItem key(int k, unsigned mods = 0, unsigned flags = 0) const
  {
    actionItem i = *this;
    i.keys.push_back(Shortcut(k, mods, flags));
    return i;
  }
};

// The menu with the given name: "Geometry" and "Mesh" (the modules), "Quick
// access" (the menu of the scene), "View" (the menu of a view), "Menu bar"
// (the menu bar of the FLTK interface), or "Keys" (the actions of the
// keys in no menu, which no interface shows; GetShortcuts() in Shortcuts.h
// lists the keys of every menu)
const actionItem &GetActionMenu(const std::string &name);

// The item of the given name in the menus (that of a key), or null
const actionItem *FindItem(const std::string &name);

// Give the action items of the given name, in all the menus, the run and the
// check mark of the interface (once, when it starts)
void SetItemRun(const std::string &name, std::function<void(int view)> run,
                std::function<int()> check = nullptr);

// What RunItem() returns: what the action changed, as bits (found by
// RunItem(), not told by the action), for the interface to show it: views
// added, removed or read again, entities added or removed
enum actionResult { ActionViewsChanged = 1, ActionModelChanged = 2 };

// Run an action (nothing for another item). For the menu of a view, view is
// the index of that view; ctx is the scene whose point of view the action
// changes.
int RunItem(const actionItem &item, int view = -1, drawContext *ctx = nullptr);

#endif
