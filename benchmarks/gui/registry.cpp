// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Every item of the action registry (see Actions.h) resolves: the items of a
// name agree on what they do, every key names an item, every operation is
// known to selectionDriver, every icon has strokes; the items the FLTK
// graphical user interface does not have are listed. Every entry of the pages
// of the option window (see OptionPages.h) is an option of its kind.
#include <cstdio>
#include <cstdlib>
#include <map>
#include "gmsh.h"
#include "GmshMessage.h"
#include "Options.h"
#include "Actions.h"
#include "Shortcuts.h"
#include "IconStrokes.h"
#include "OptionPages.h"
#include "fltkActions.h"
#include "selectionDriver.h"

// no display: the test is skipped (ctest reads 77 as skipped)
static bool noDisplay()
{
#if defined(__linux__)
  return !getenv("DISPLAY") && !getenv("WAYLAND_DISPLAY");
#else
  return false;
#endif
}

static int fails = 0, items = 0;
static std::map<std::string, bool> hasRun;

static void fail(const std::string &what)
{
  printf("FAIL %s\n", what.c_str());
  fails++;
}

static void walk(const actionItem &m, const std::string &menu)
{
  for(auto &i : m.items) {
    if(i.kind == ItemMenu) {
      walk(i, menu + "/" + i.label);
      continue;
    }
    items++;
    if(i.kind == ItemAction) {
      auto it = hasRun.find(i.name);
      if(it != hasRun.end() && it->second != (bool)i.run)
        fail(i.name + ": items of the same name disagree on run");
      hasRun[i.name] = (bool)i.run;
      if(!FindItem(i.name)) fail("FindItem " + i.name);
      if(!i.run)
        printf("     %-28s not in the FLTK interface (%s)\n", i.name.c_str(),
               menu.c_str());
    }
    if(i.kind == ItemOperation) {
      selectionDriver d(i.name, nullptr);
      if(!d.active()) fail("operation " + i.name + " not known");
    }
    if(i.icon.size() && !*IconStrokes(i.icon))
      fail(i.name + ": no strokes for icon " + i.icon);
    if(menu == "Status bar" && i.icon.empty() && i.label.empty())
      fail(i.name + ": a status bar button without icon or label");
  }
}

int main(int argc, char **argv)
{
  if(noDisplay()) return 77;
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::fltk::initialize();
  gmsh::model::occ::addBox(0, 0, 0, 1, 1, 1);
  gmsh::model::occ::synchronize();
  for(auto n : {"Geometry", "Mesh", "Quick access", "View", "Menu bar",
                "Status bar", "Keys"})
    walk(GetActionMenu(n), n);
  for(const ShortcutEntry &e : GetShortcuts()) {
    const actionItem *i = FindItem(e.action);
    if(!i)
      fail("shortcut " + e.action + " names no item");
    else if(i->kind == ItemAction && !i->run)
      printf("     key %s: no run in the FLTK interface\n", e.action.c_str());
  }
  // (asked of the options themselves: with the interface up, the API only
  // reports an unknown option, it does not throw)
  int entries = 0;
  for(const optionPage &p : OptionPages())
    for(const optionSection &s : p.sections)
      for(const optionRow &row : s.rows)
        for(const optionEntry &f : row) {
          if(f.kind == EntryCustom || f.kind == EntryHeading) continue;
          entries++;
          std::string cat = f.option.substr(0, f.option.find('.'));
          std::string name = f.option.substr(f.option.find('.') + 1);
          double v;
          std::string s;
          bool ok = (f.kind == EntryText) ?
                      StringOption(GMSH_GET, cat.c_str(), 0, name.c_str(), s,
                                   false) :
                      NumberOption(GMSH_GET, cat.c_str(), 0, name.c_str(), v,
                                   false);
          if(!ok)
            fail(p.name + " page: " + f.option +
                 " is not an option of its kind");
          if(f.kind == EntryChoice && GetOptionChoices(f.option).empty())
            fail(p.name + " page: " + f.option + " has no table of choices");
        }
  // what Gmsh reported while the registry and the windows were built (an
  // unknown name in a table, a key on two items, a custom row with no
  // builder): errors, which do not throw with the interface up
  if(Msg::GetErrorCount())
    fail(std::to_string(Msg::GetErrorCount()) +
         " errors reported while building the interface");
  printf("%d items, %d option entries, %d failures\n", items, entries, fails);
  gmsh::fltk::finalize();
  gmsh::finalize();
  return fails ? 1 : 0;
}
