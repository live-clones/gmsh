// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <string>
#include <utility>
#include <vector>

// The keyboard shortcuts of the GUI, in one table. The keys the GUI handles,
// the shortcuts shown in its menus, and the lists in the help window and in
// the documentation are all read from this table, so that they cannot drift
// apart. The table does not depend on a toolkit: the GUI translates the keys
// and runs the actions by their names, in snake case ("mesh_nodes"), as those
// of the action registry (see Actions.h), whose items show the shortcut of
// the same name ("mesh_1d", or "file_open" in the menu bar of the graphical
// interface).
// The titles of the menus must not have a mnemonic (an "&" letter) used by an
// Alt shortcut below, because the menu bar would open the menu before the
// shortcut is seen.

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
  // the shortcut as text, e.g. "Alt+Shift+Ctrl+x"; command is the name of the
  // Command key ("Ctrl+"), the one of this platform if empty
  std::string label(const std::string &command = "") const;
};

struct ShortcutEntry {
  const char *action; // the name of what the GUI does
  Shortcut shortcut;
  const char *help;
  // the key is also passed on to the widget under the mouse (as are the keys
  // of a selection)
  bool passOn;
  // not in the macOS system menu bar, where Cmd+H hides the application
  bool inWindowBarOnly;
  ShortcutEntry(const char *a, Shortcut s, const char *h, bool pass = false,
                bool inWindow = false)
    : action(a), shortcut(s), help(h), passOn(pass), inWindowBarOnly(inWindow)
  {
  }
};

// the table, in the order of the documentation
const std::vector<ShortcutEntry> &GetShortcuts();

// the shortcuts of an action (several keys may do the same)
std::vector<Shortcut> GetShortcutsOf(const std::string &action);

// Run an action of the table that only changes the scene: what is displayed,
// the views, the time steps and the point of view of ctx (ModShift in mods
// gives the opposite side). The graphical interface does the point of view,
// the time steps and the views with the buttons of its status bar instead
// (which also sync its viewports); the web page does all of them here.
// Returns 0 for an action not handled here, and 2 when the scene must be drawn
// again.
class drawContext;
int RunSceneShortcut(const std::string &action, unsigned mods,
                     drawContext *ctx);

// whether an action is one of RunSceneShortcut()
bool IsSceneShortcut(const std::string &action);

// each shortcut and what it does, for the help window and the documentation
// (the keys that do the same are joined with "or"; see Shortcut::label() for
// command)
std::vector<std::pair<std::string, std::string> >
GetShortcutsUsage(const std::string &command = "");

#endif
