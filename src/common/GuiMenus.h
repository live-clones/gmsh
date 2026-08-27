// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_MENUS_H
#define GMSH_GUI_MENUS_H

#include <functional>
#include <string>
#include <vector>

#include "GmshConfig.h"

// The menus of the graphical user interface, declared once and built by both
// interfaces. What used to be bar_table[] in src/fltk/graphicWindow.cpp on one
// side and a series of BeginMenu()/MenuItem() calls in src/imgui/menuBar.cpp on
// the other is now one description that each interface walks: same entries in
// the same order, same separators, and -- this is the part duplication could
// not keep honest -- the same shortcuts. A label saying "Ctrl+H" and a handler
// doing something else is a kind of drift no comparison of structures catches,
// because both structures look right.
//
// The description is rebuilt from scratch rather than mutated, so that what
// depends on the state of the application -- the recent files -- is simply read
// again while it is built. The interfaces rebuild when generation() changes.

namespace Menu {

  // Modifiers of a shortcut. Command is the Control key on X11 and Windows and
  // the Command key on macOS, which is what both toolkits expect and what the
  // FLTK bar_table[]/sysbar_table[] pair used to spell out twice.
  enum { ModCommand = 1 << 0, ModShift = 1 << 1, ModAlt = 1 << 2 };

  // The key of a shortcut: an upper case letter or a digit for the printable
  // ones, or one of these.
  enum { KeyNone = 0, KeyF1 = 0x1000 /* .. KeyF1 + 11 */ };

  struct Shortcut {
    int key;
    unsigned mods;
    Shortcut(int k = KeyNone, unsigned m = 0) : key(k), mods(m) {}
    bool empty() const { return key == KeyNone; }
    // "Ctrl+Shift+O", for the interface that has to draw it itself
    std::string label() const;
  };

  enum Kind {
    Action, // run action()
    Toggle, // action() flips what checked() reports
    Submenu // has children, and does nothing of its own
  };

  struct Item {
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
    // the macOS system menu bar provides its own Quit
    bool hideInSystemBar;
    std::vector<Item> children;
    Item()
      : kind(Action), mnemonic(0), dividerAfter(false), hideInSystemBar(false)
    {
    }
  };

  // The menu bar. Whatever the running interface cannot honour is left out
  // rather than shown greyed: an interface with a single window has nothing to
  // bring to the front, and one that cannot reach the clipboard should not
  // offer to.
  std::vector<Item> bar();

  // The modules tree: the geometry and mesh commands, in the order the FLTK
  // tree has always shown them. It stops where the ONELAB parameters begin --
  // those are widgets, not entries, and each interface builds them itself.
  std::vector<Item> modules();

  // Say that what the menus show has changed -- a file was opened, a model was
  // added -- so that the interfaces build them again.
  void invalidate();
  unsigned generation();

} // namespace Menu

#endif
