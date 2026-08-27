// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <cctype>
#include <cstdint>
#include <cstring>
#include <deque>
#include <string>
#include <vector>

#include <FL/Fl.H>

#include "menuFltk.h"
#include "GuiMenus.h"

namespace {

  // Everything the menu bar points at. Only the main window has one, so a
  // single instance is enough; building again replaces it wholesale, which is
  // why the caller must hand the new table to menu() before anything else runs.
  struct fltkMenu {
    // the description, kept alive because the entries below point into it
    std::vector<Menu::Item> tree;
    // the labels, in a deque so that the pointers Fl_Menu_Item holds stay valid
    // as more are added
    std::deque<std::string> labels;
    std::vector<Fl_Menu_Item> items;
    // the entry each Fl_Menu_Item stands for, found through its user_data_
    std::vector<const Menu::Item *> byId;
  };

  fltkMenu _menu;

  void _dispatch(Fl_Widget *, void *data)
  {
    std::size_t id = (std::size_t)(intptr_t)data;
    if(!id || id > _menu.byId.size()) return;
    const Menu::Item *item = _menu.byId[id - 1];
    if(item && item->action) item->action();
  }

  // FLTK underlines the letter that follows an ampersand
  std::string _withMnemonic(const std::string &label, char mnemonic)
  {
    if(!mnemonic) return label;
    std::size_t i = label.find(mnemonic);
    if(i == std::string::npos) return label;
    return label.substr(0, i) + "&" + label.substr(i);
  }

  int _shortcut(const Menu::Shortcut &s)
  {
    if(s.empty()) return 0;
    int key;
    if(s.key >= Menu::KeyF1 && s.key < Menu::KeyF1 + 12)
      key = FL_F + (s.key - Menu::KeyF1 + 1);
    else
      key = tolower(s.key);
    int mods = 0;
    // FL_COMMAND is FL_CTRL everywhere but on macOS, where it is the Command
    // key: the pair of tables this replaces spelled that out twice
    if(s.mods & Menu::ModCommand) mods |= FL_COMMAND;
    if(s.mods & Menu::ModShift) mods |= FL_SHIFT;
    if(s.mods & Menu::ModAlt) mods |= FL_ALT;
    return mods + key;
  }

  void _blank(Fl_Menu_Item &m) { memset(&m, 0, sizeof(Fl_Menu_Item)); }

  void _append(const std::vector<Menu::Item> &items, bool systemBar)
  {
    for(const auto &it : items) {
      if(systemBar && it.hideInSystemBar) continue;

      Fl_Menu_Item m;
      _blank(m);
      _menu.labels.push_back(systemBar ? it.label :
                                         _withMnemonic(it.label, it.mnemonic));
      m.text = _menu.labels.back().c_str();
      m.shortcut_ = _shortcut(it.shortcut);
      if(it.dividerAfter) m.flags |= FL_MENU_DIVIDER;

      if(it.kind == Menu::Submenu) {
        m.flags |= FL_SUBMENU;
        _menu.items.push_back(m);
        _append(it.children, systemBar);
        Fl_Menu_Item end;
        _blank(end);
        _menu.items.push_back(end); // closes the submenu
        continue;
      }

      if(it.kind == Menu::Toggle) m.flags |= FL_MENU_TOGGLE;
      m.callback_ = (Fl_Callback *)_dispatch;
      _menu.byId.push_back(&it);
      // zero would be indistinguishable from "no data"
      m.user_data_ = (void *)(intptr_t)_menu.byId.size();
      _menu.items.push_back(m);
    }
  }

} // namespace

namespace {

  // The modules tree has a store of its own: both it and the menu bar are alive
  // at the same time.
  struct fltkModules {
    std::vector<Menu::Item> tree;
    std::vector<const Menu::Item *> byId;
  };

  fltkModules _modules;

  void _dispatchModule(Fl_Widget *, void *data)
  {
    std::size_t id = (std::size_t)(intptr_t)data;
    if(!id || id > _modules.byId.size()) return;
    const Menu::Item *item = _modules.byId[id - 1];
    if(item && item->action) item->action();
  }

  void _walkModules(
    const std::vector<Menu::Item> &items, const std::string &path,
    const std::function<void(const std::string &, Fl_Callback *, void *)> &add)
  {
    for(const auto &it : items) {
      std::string here = path + "/" + it.label;
      if(it.kind == Menu::Submenu) {
        _walkModules(it.children, here, add);
        continue;
      }
      _modules.byId.push_back(&it);
      add(here, (Fl_Callback *)_dispatchModule,
          (void *)(intptr_t)_modules.byId.size());
    }
  }

} // namespace

void fltkModulesBuild(
  const std::function<void(const std::string &path, Fl_Callback *cb,
                           void *data)> &add)
{
  // moved in first: what follows takes pointers into it
  _modules.tree = Menu::modules();
  _modules.byId.clear();
  _walkModules(_modules.tree, "0Modules", add);
}

Fl_Menu_Item *fltkMenuBuild(bool systemBar)
{
  _menu.labels.clear();
  _menu.items.clear();
  _menu.byId.clear();
  // moved in first: what follows takes pointers into it
  _menu.tree = Menu::bar();

  _append(_menu.tree, systemBar);
  Fl_Menu_Item end;
  _blank(end);
  _menu.items.push_back(end);

  fltkMenuRefresh();

  return &_menu.items[0];
}

void fltkMenuRefresh()
{
  for(auto &m : _menu.items) {
    if(!m.user_data_) continue;
    std::size_t id = (std::size_t)(intptr_t)m.user_data_;
    if(!id || id > _menu.byId.size()) continue;
    const Menu::Item *it = _menu.byId[id - 1];
    if(!it) continue;
    if(it->kind == Menu::Toggle && it->checked) {
      if(it->checked())
        m.flags |= FL_MENU_VALUE;
      else
        m.flags &= ~FL_MENU_VALUE;
    }
    if(it->enabled) {
      if(it->enabled())
        m.flags &= ~FL_MENU_INACTIVE;
      else
        m.flags |= FL_MENU_INACTIVE;
    }
  }
}

#endif
