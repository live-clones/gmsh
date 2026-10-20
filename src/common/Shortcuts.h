// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <string>
#include <utility>
#include <vector>

// The keyboard shortcuts of the GUI, said once: the keys the GUI handles, the
// shortcuts its menus show and the list of the help window and of the
// documentation are all read from this table, so that they cannot drift
// apart. The table knows no toolkit: the GUI maps its keys and runs its
// actions by name. The titles of the menus must not carry a mnemonic (an
// "&" letter) that an Alt shortcut below uses: the menu bar opens the menu
// before the shortcut is seen.

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

struct Shortcut {
  int key; // a lower case letter, a digit, a mark, or a ShortcutKey
  unsigned mods;
  Shortcut(int k = KeyNone, unsigned m = 0) : key(k), mods(m) {}
  // "Alt+Shift+Ctrl+x", with command the name of the Command key ("Ctrl+"),
  // or the one of this platform when empty
  std::string label(const std::string &command = "") const;
};

struct ShortcutEntry {
  const char *action; // what the GUI does with it, by name
  Shortcut shortcut;
  const char *help;
  // the key is also left to what is under the mouse (the keys of a selection)
  bool passOn;
  // not bound on the macOS system menu bar, where Cmd+H hides the application
  bool inWindowBarOnly;
  ShortcutEntry(const char *a, Shortcut s, const char *h, bool pass = false,
                bool inWindow = false)
    : action(a), shortcut(s), help(h), passOn(pass), inWindowBarOnly(inWindow)
  {
  }
};

// the table, in the order of the documentation
const std::vector<ShortcutEntry> &GetShortcuts();

// the shortcuts of an action: several keys may do the same
std::vector<Shortcut> GetShortcutsOf(const std::string &action);

// each shortcut (keys that do the same joined with "or") and what it does, for
// the help window and the documentation; see Shortcut::label() for command
std::vector<std::pair<std::string, std::string> >
GetShortcutsUsage(const std::string &command = "");

#endif
