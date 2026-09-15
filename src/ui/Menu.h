// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_MENU_H
#define UI_MENU_H

#include <functional>
#include <string>
#include <vector>

// A menu: a list of entries, each of which may hold a list of its own. The
// shortcut is said here, once, so that a label and a handler cannot drift
// apart.

namespace Ui {

  // Modifiers of a shortcut. Command is the Control key on X11 and Windows
  // and the Command key on macOS. ModAny says the key is the shortcut
  // whatever else is held, or nothing.
  enum {
    ModCommand = 1 << 0,
    ModShift = 1 << 1,
    ModAlt = 1 << 2,
    ModAny = 1 << 3
  };

  // the key of a shortcut: an upper case letter, a digit or a punctuation
  // mark for the printable ones, or one of these
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
    // whether a key struck with these modifiers held is this shortcut: the
    // interfaces read their key events differently and compare here
    bool matches(int key, unsigned mods) const;
  };

  // A key that does something wherever the pointer is, outside any menu.
  // The interfaces walk the list on a key press, in order, and run every
  // binding that matches up to the first one that spends the key.
  struct KeyBinding {
    Shortcut shortcut;
    std::function<void()> action;
    bool spent;
    KeyBinding() : spent(true) {}
  };

  struct MenuItem {
    // inside the item: Action, Toggle and Submenu would otherwise clash with
    // the field kinds of Form.h
    enum Kind {
      Action, // run action()
      Toggle, // action() flips what checked() reports
      Submenu // has children, and does nothing of its own
    };
    Kind kind;
    std::string label;
    // the letter underlined and bound to Alt, 0 for none; not 'g', 'm', 's'
    // or 'p', which are shortcuts of the 3D view
    char mnemonic;
    Shortcut shortcut;
    std::function<void()> action;
    std::function<bool()> checked; // Toggle only
    // null means always enabled; asked again every time the menu is about to
    // be shown
    std::function<bool()> enabled;
    bool dividerAfter;
    // the entry a popup menu opens under until the user has picked another
    bool preferred;
    // the macOS system menu bar provides its own Quit
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
