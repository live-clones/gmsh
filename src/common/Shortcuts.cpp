// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "Shortcuts.h"
#include "Context.h"

std::string Shortcut::label(const std::string &command) const
{
  if(key == KeyNone) return "";
  std::string s;
  if(mods & ModAlt) s += "Alt+";
  if(mods & ModShift) s += "Shift+";
  if(mods & ModCommand) {
    if(command.size())
      s += command;
    else
#if defined(__APPLE__)
      s += "Cmd+";
#else
      s += "Ctrl+";
#endif
  }
  if(key >= KeyF1 && key < KeyF1 + 12)
    s += "F" + std::to_string(key - KeyF1 + 1);
  else if(key == KeyEscape)
    s += "Escape";
  else if(key == KeyLeft)
    s += "Left arrow";
  else if(key == KeyRight)
    s += "Right arrow";
  else if(key == KeyUp)
    s += "Up arrow";
  else if(key == KeyDown)
    s += "Down arrow";
  else if(key == KeyPageUp)
    s += "Page up";
  else if(key == KeyPageDown)
    s += "Page down";
  else
    s += (char)key;
  if(mods & AnyModifiers) s += " (with any modifier)";
  return s;
}

// (GetShortcuts() is in Actions.cpp, with the items the keys are declared on)

std::vector<Shortcut> GetShortcutsOf(const std::string &action)
{
  std::vector<Shortcut> s;
  for(const ShortcutEntry &e : GetShortcuts())
    if(action == e.action) s.push_back(e.shortcut);
  return s;
}

std::vector<std::pair<std::string, std::string>>
GetShortcutsUsage(const std::string &command)
{
  std::vector<std::pair<std::string, std::string>> s;
  const std::vector<ShortcutEntry> &table = GetShortcuts();
  for(std::size_t i = 0; i < table.size(); i++) {
    const ShortcutEntry &e = table[i];
#if defined(__APPLE__)
    // the list of the FLTK interface (no command given), with the system menu
    // bar, whose Cmd+H is the system's
    if(command.empty() && (e.shortcut.flags & KeyInWindowBarOnly) &&
       CTX::instance()->systemMenuBar)
      continue;
#endif
    // keys that do the same, documented alike, on one line
    if(i && s.size() && table[i - 1].action == e.action &&
       table[i - 1].help == e.help) {
      s.back().first += " or " + e.shortcut.label(command);
      continue;
    }
    s.push_back(std::make_pair(e.shortcut.label(command), e.help));
  }
  return s;
}
