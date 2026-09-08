// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Menu.h"

namespace Ui {

  std::string Shortcut::label() const
  {
    if(empty()) return "";
    std::string s;
    if(mods & ModCommand) {
#if defined(__APPLE__)
      s += "Cmd+";
#else
      s += "Ctrl+";
#endif
    }
    if(mods & ModShift) s += "Shift+";
    if(mods & ModAlt) s += "Alt+";
    if(key >= KeyF1 && key < KeyF1 + 12)
      s += "F" + std::to_string(key - KeyF1 + 1);
    else if(key == KeyDelete)
      s += "Del";
    // The arrows have to be named as well. Falling through to the cast below
    // truncated them to a control character, which is not a label anyone can
    // read and not one anything can match against -- and the colour map gives
    // four of its eight numbers to the arrows.
    else if(key == KeyLeft)
      s += "Left";
    else if(key == KeyRight)
      s += "Right";
    else if(key == KeyUp)
      s += "Up";
    else if(key == KeyDown)
      s += "Down";
    else if(key == KeyEscape)
      s += "Esc";
    else if(key == KeyHome)
      s += "Home";
    else if(key == KeyPageUp)
      s += "PgUp";
    else if(key == KeyPageDown)
      s += "PgDn";
    else
      s += (char)key;
    return s;
  }

  bool Shortcut::matches(int k, unsigned m) const
  {
    if(empty() || k != key) return false;
    if(mods & ModAny) return true;
    const unsigned held = ModCommand | ModShift | ModAlt;
    return (mods & held) == (m & held);
  }

} // namespace Ui
