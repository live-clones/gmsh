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
    else
      s += (char)key;
    return s;
  }

} // namespace Ui
