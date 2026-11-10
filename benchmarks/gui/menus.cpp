// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The menu bar and the status bar of the FLTK graphical user interface are
// built from the registry (see Actions.h): every item the interface has gets
// its entry, with its shortcut, or its button, with its help as tooltip
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include "gmsh.h"
#include "Actions.h"
#include "Shortcuts.h"
#include "FlGui.h"
#include "graphicWindow.h"
#include "fltkActions.h"

// no display: the test is skipped (ctest reads 77 as skipped)
static bool noDisplay()
{
#if defined(__linux__)
  return !getenv("DISPLAY") && !getenv("WAYLAND_DISPLAY");
#else
  return false;
#endif
}

static int fails = 0, entries = 0, buttons = 0;

static void fail(const std::string &what)
{
  printf("FAIL %s\n", what.c_str());
  fails++;
}

// the menu bar of the main window (a child of it, or of a group in it)
static Fl_Menu_Bar *findBar(Fl_Group *g)
{
  for(int i = 0; i < g->children(); i++) {
    Fl_Widget *c = g->child(i);
    if(Fl_Menu_Bar *b = dynamic_cast<Fl_Menu_Bar *>(c)) return b;
    if(Fl_Group *gg = c->as_group())
      if(Fl_Menu_Bar *b = findBar(gg)) return b;
  }
  return nullptr;
}

// the entries of the menu bar by their path, the labels joined by a character
// no label has (a label may hold a slash)
static const char SEP = '\x1f';

static std::map<std::string, const Fl_Menu_Item *> entries_of(Fl_Menu_Bar *bar)
{
  std::map<std::string, const Fl_Menu_Item *> all;
  std::vector<std::string> path;
  const Fl_Menu_Item *m = bar->menu();
  for(int i = 0; i < bar->size(); i++) {
    const Fl_Menu_Item &it = m[i];
    if(!it.text) { // the end of a submenu (or of the menu)
      if(!path.empty()) path.pop_back();
      continue;
    }
    std::string p;
    for(const std::string &l : path) p += l + SEP;
    p += it.text;
    all[p] = &it;
    if(it.flags & FL_SUBMENU) path.push_back(it.text);
  }
  return all;
}

// the items of a menu of the registry, under path, in the menu bar
static void checkMenu(const std::map<std::string, const Fl_Menu_Item *> &all,
                      const actionItem &menu, const std::string &path)
{
  for(const actionItem &i : menu.items) {
    if(i.kind == ItemMenu) {
      checkMenu(all, i, i.label.empty() ? path : path + i.label + SEP);
      continue;
    }
    if(!canRunItem(i)) continue;
    if(i.name == "file_open_recent") continue; // a submenu the interface fills
    std::string p = path + i.label;
    auto it = all.find(p);
    if(it == all.end()) {
      fail("no entry " + p);
      continue;
    }
    entries++;
    int key = GetShortcutsOf(i.name).empty() ? 0 : fltkShortcut(i.name.c_str());
    if(it->second->shortcut() != key)
      fail("entry " + p + ": shortcut differs from the key of " + i.name);
  }
}

int main(int argc, char **argv)
{
  if(noDisplay()) return 77;
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);
  // (the menu bar in the window, not the system's, to read it)
  gmsh::option::setNumber("General.SystemMenuBar", 0);
  gmsh::fltk::initialize();
  graphicWindow *g = FlGui::instance()->graph[0];
  Fl_Menu_Bar *bar = findBar(g->getWindow());
  if(!bar)
    fail("no menu bar");
  else
    checkMenu(entries_of(bar), GetActionMenu("Menu bar"), "");
  for(const actionItem &group : GetActionMenu("Status bar").items) {
    for(const actionItem &i : group.items) {
      if(!canRunItem(i)) continue;
      Fl_Button *b = g->statusButton(i.name);
      if(!b) {
        fail("no status bar button " + i.name);
        continue;
      }
      buttons++;
      std::string tip = b->tooltip() ? b->tooltip() : "";
      if(tip.compare(0, i.help.size(), i.help))
        fail("button " + i.name + ": tooltip without its help");
    }
  }
  printf("%d menu entries, %d status bar buttons, %d failures\n", entries,
         buttons, fails);
  gmsh::fltk::finalize();
  gmsh::finalize();
  return fails ? 1 : 0;
}
