// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <string>
#include <utility>
#include <vector>

// The keyboard shortcuts of the interfaces. A key is declared on the item it
// runs, in the menus of Actions.cpp (action(...).key('2'), see Actions.h): the
// keys the interfaces handle, the shortcuts shown in their menus, and the lists
// in the help window and in the documentation are all read from the items, so
// that they cannot drift apart. Nothing here depends on a toolkit: each
// interface translates the keys and runs the items by their names, in snake
// case ("mesh_2d").
// The titles of the menus must not have a mnemonic (an "&" letter) used by an
// Alt shortcut, because the menu bar would open the menu before the shortcut
// is seen.

// the keys that are not a character
enum ShortcutKey {
  KeyNone = 0,
  KeyF1 = 0x1000, // .. KeyF1 + 11
  KeyEscape = 0x1100,
  KeyLeft,
  KeyRight,
  KeyUp,
  KeyDown,
  KeyPageUp,
  KeyPageDown
};

// the modifiers: Command is Control, or Command on macOS; AnyModifiers matches
// whatever is held
enum ShortcutModifier {
  ModCommand = 1 << 0,
  ModShift = 1 << 1,
  ModAlt = 1 << 2,
  AnyModifiers = 1 << 3
};

// how a key is handled: also passed on to the widget under the mouse (as the
// keys of a selection are), or not in the macOS system menu bar (where Cmd+H
// hides the application)
enum ShortcutFlag { KeyPassedOn = 1 << 0, KeyInWindowBarOnly = 1 << 1 };

struct Shortcut {
  int key; // a lower case letter, a digit, a mark, or a ShortcutKey
  unsigned mods;
  unsigned flags;
  Shortcut(int k = KeyNone, unsigned m = 0, unsigned f = 0)
    : key(k), mods(m), flags(f)
  {
  }
  // the shortcut as text, e.g. "Alt+Shift+Ctrl+x"; command is the name of the
  // Command key ("Ctrl+"), the one of this platform if empty
  std::string label(const std::string &command = "") const;
};

// a key and what it does: the name of its item, and the help of the item
struct ShortcutEntry {
  std::string action;
  Shortcut shortcut;
  std::string help;
};

// all the keys, from the items (see Actions.cpp), in the order of the
// documentation: the keys of an item together, the items by the modifiers of
// their first key (none, Shift, Command, Command+Shift, Alt, Alt+Shift,
// Alt+Command), then by that key
const std::vector<ShortcutEntry> &GetShortcuts();

// the shortcuts of an action (several keys may do the same)
std::vector<Shortcut> GetShortcutsOf(const std::string &action);

// each shortcut and what it does, for the help window and the documentation
// (the keys that do the same are joined with "or"; see Shortcut::label() for
// command)
std::vector<std::pair<std::string, std::string>>
GetShortcutsUsage(const std::string &command = "");

#endif
