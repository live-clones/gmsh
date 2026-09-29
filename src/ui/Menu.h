// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_MENU_H
#define UI_MENU_H

#include <functional>
#include <string>
#include <vector>

// the shortcut is said once, here, so that a label and a handler cannot drift
// apart

namespace Ui {

  // Command is Control on X11 and Windows, Command on macOS; ModAny matches
  // whatever is held
  enum {
    ModCommand = 1 << 0,
    ModShift = 1 << 1,
    ModAlt = 1 << 2,
    ModAny = 1 << 3
  };

  // an upper case letter, a digit or a mark, or one of these
  enum {
    KeyNone = 0,
    KeyF1 = 0x1000 /* .. KeyF1 + 11 */,
    KeyDelete = 0x1100,
    KeyLeft,
    KeyRight,
    KeyUp,
    KeyDown,
    KeyEscape,
    KeyHome,
    KeyPageUp,
    KeyPageDown
  };

  struct Shortcut {
    int key;
    unsigned mods;
    Shortcut(int k = KeyNone, unsigned m = 0) : key(k), mods(m) {}
    bool empty() const { return key == KeyNone; }
    // "Ctrl+Shift+O"
    std::string label() const;
    // the interfaces read their key events differently and compare here
    bool matches(int key, unsigned mods) const;
  };

  // walked in order on a key press, every match run up to the first that spends
  // the key
  struct KeyBinding {
    Shortcut shortcut;
    std::function<void()> action;
    bool spent;
    KeyBinding() : spent(true) {}
  };

  struct MenuItem {
    // inside: Action, Toggle and Submenu would clash with the kinds of Form.h
    enum Kind {
      Action, // run action()
      Toggle, // action() flips what checked() reports
      Submenu // has children, and does nothing of its own
    };
    Kind kind;
    std::string label;
    // not 'g', 'm', 's' or 'p', shortcuts of the 3D view
    char mnemonic;
    Shortcut shortcut;
    std::function<void()> action;
    std::function<bool()> checked; // Toggle only
    // null means always enabled
    std::function<bool()> enabled;
    bool dividerAfter;
    bool preferred;
    bool hideInSystemBar;
    std::vector<MenuItem> children;
    MenuItem()
      : kind(Action), mnemonic(0), dividerAfter(false), preferred(false),
        hideInSystemBar(false)
    {
    }
  };

} // namespace Ui

#endif
