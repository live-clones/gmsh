// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_MENU_H
#define UI_MENU_H

#include <functional>
#include <string>
#include <vector>

// A menu: a list of entries, each of which may hold a list of its own.
//
// The part of it that duplication could never keep honest is the shortcut. A
// label saying "Ctrl+H" and a handler doing something else is a kind of drift
// that no comparison of two structures catches, because both structures look
// right.

namespace Ui {

  // Modifiers of a shortcut. Command is the Control key on X11 and Windows and
  // the Command key on macOS, which is what both toolkits expect and what the
  // FLTK bar_table[]/sysbar_table[] pair used to spell out twice. ModAny says
  // the key is the shortcut whatever else is held, or nothing: Escape is
  // Escape with a modifier down.
  enum {
    ModCommand = 1 << 0,
    ModShift = 1 << 1,
    ModAlt = 1 << 2,
    ModAny = 1 << 3
  };

  // The key of a shortcut: an upper case letter, a digit or a punctuation
  // mark for the printable ones, or one of these.
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
    // "Ctrl+Shift+O", for the interface that has to draw it itself
    std::string label() const;
    // Whether a key struck with these modifiers held is this shortcut. The
    // interfaces read their key events differently and compare the same
    // way: here, once, so that none of them compares labels.
    bool matches(int key, unsigned mods) const;
  };

  // A key that does something wherever the pointer is, outside any menu:
  // 'g' folds the geometry module, an arrow steps the animation, Escape
  // gives up a picking. The interfaces walk the list on a key press, in
  // order, and run every binding that matches up to the first one that
  // spends the key. One that does not spend it does its work and leaves the
  // key to whatever else was listening -- the keys a picking reads are
  // heard by the picking as well.
  struct KeyBinding {
    Shortcut shortcut;
    std::function<void()> action;
    bool spent;
    KeyBinding() : spent(true) {}
  };

  struct MenuItem {
    // Inside the item, and not beside it: Action, Toggle and Submenu would
    // otherwise clash with the field kinds of Form.h, which share this
    // namespace.
    enum Kind {
      Action, // run action()
      Toggle, // action() flips what checked() reports
      Submenu // has children, and does nothing of its own
    };
    Kind kind;
    std::string label;
    // The letter FLTK underlines and binds to Alt, 0 for none. It cannot be
    // 'g', 'm', 's' or 'p': those are global shortcuts of the 3D view.
    char mnemonic;
    Shortcut shortcut;
    std::function<void()> action;
    std::function<bool()> checked; // Toggle only
    // null means always enabled; it is asked again every time the menu is about
    // to be shown
    std::function<bool()> enabled;
    bool dividerAfter;
    // The entry a popup menu opens under until the user has picked another:
    // the quick access menu of the status bar opens under the one it is most
    // often reached for, so that it takes one click and no aim.
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
