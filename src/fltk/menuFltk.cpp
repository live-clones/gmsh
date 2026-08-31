// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "uiSources.h"
#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <cctype>
#include <cstdint>
#include <cstring>
#include <deque>
#include <map>
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
    std::vector<Ui::MenuItem> tree;
    // the labels, in a deque so that the pointers Fl_Menu_Item holds stay valid
    // as more are added
    std::deque<std::string> labels;
    std::vector<Fl_Menu_Item> items;
    // the entry each Fl_Menu_Item stands for, found through its user_data_
    std::vector<const Ui::MenuItem *> byId;
  };

  fltkMenu _menu;

  void _dispatch(Fl_Widget *, void *data)
  {
    std::size_t id = (std::size_t)(intptr_t)data;
    if(!id || id > _menu.byId.size()) return;
    const Ui::MenuItem *item = _menu.byId[id - 1];
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

  int _shortcut(const Ui::Shortcut &s)
  {
    if(s.empty()) return 0;
    int key;
    if(s.key >= Ui::KeyF1 && s.key < Ui::KeyF1 + 12)
      key = FL_F + (s.key - Ui::KeyF1 + 1);
    else if(s.key == Ui::KeyDelete)
      key = FL_Delete;
    else
      key = tolower(s.key);
    int mods = 0;
    // FL_COMMAND is FL_CTRL everywhere but on macOS, where it is the Command
    // key: the pair of tables this replaces spelled that out twice
    if(s.mods & Ui::ModCommand) mods |= FL_COMMAND;
    if(s.mods & Ui::ModShift) mods |= FL_SHIFT;
    if(s.mods & Ui::ModAlt) mods |= FL_ALT;
    return mods + key;
  }

  void _blank(Fl_Menu_Item &m) { memset(&m, 0, sizeof(Fl_Menu_Item)); }

  void _append(const std::vector<Ui::MenuItem> &items, bool systemBar)
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

      if(it.kind == Ui::MenuItem::Submenu) {
        m.flags |= FL_SUBMENU;
        _menu.items.push_back(m);
        _append(it.children, systemBar);
        Fl_Menu_Item end;
        _blank(end);
        _menu.items.push_back(end); // closes the submenu
        continue;
      }

      if(it.kind == Ui::MenuItem::Toggle) m.flags |= FL_MENU_TOGGLE;
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
  // What the tree holds, kept while its widgets are alive: Fl_Tree carries a
  // void* to each line, so the thing it points at has to outlive the walk.
  struct fltkModules {
    std::vector<Ui::Node> byId;
  };

  fltkModules _modules;

  void _dispatchModule(Fl_Widget *, void *data)
  {
    std::size_t id = (std::size_t)(intptr_t)data;
    if(!id || id > _modules.byId.size()) return;
    const Ui::Node &node = _modules.byId[id - 1];
    if(node.pressed) node.pressed();
  }

  // Down the model, asking for the children of what is open rather than being
  // handed the whole of it. A line with children is a branch and Fl_Tree makes
  // it as the path of a child names it; a line without is one to press.
  void _walkModules(
    const Ui::Tree &tree, const std::string &path,
    const std::function<void(const std::string &, Fl_Callback *, void *)> &add)
  {
    for(const auto &child : tree.children(path)) {
      if(!tree.children(child).empty()) {
        _walkModules(tree, child, add);
        continue;
      }
      Ui::Node node = tree.node(child);
      // A line that carries a widget or a menu of its own -- a solver, a view,
      // a parameter -- is one this interface still builds itself: it cannot
      // put a described field on a line of its tree yet.
      if(node.hasField || node.menu) continue;
      _modules.byId.push_back(node);
      add(child, (Fl_Callback *)_dispatchModule,
          (void *)(intptr_t)_modules.byId.size());
    }
  }

} // namespace

void fltkModulesBuild(
  const std::function<void(const std::string &path, Fl_Callback *cb,
                           void *data)> &add)
{
  _modules.byId.clear();
  _walkModules(uiSources().tree, "0Modules", add);
}

namespace {

  // The popup has a store of its own too: it is built while the menu bar is
  // alive, and it must not walk over what the bar points at.
  struct fltkPopup {
    std::vector<Ui::MenuItem> tree;
    std::deque<std::string> labels;
    std::vector<Fl_Menu_Item> items;
    std::vector<const Ui::MenuItem *> byId;
    // where each of them opened last time, so that it opens there again; a
    // menu is named by the key its caller gives it
    std::map<std::string, std::string> last;
  };

  fltkPopup _popup;
  // the entry the description prefers, found while the table is built
  std::string _preferred;

  void _appendPopup(const std::vector<Ui::MenuItem> &items)
  {
    for(const auto &it : items) {
      Fl_Menu_Item m;
      _blank(m);
      _popup.labels.push_back(it.label);
      m.text = _popup.labels.back().c_str();
      m.shortcut_ = _shortcut(it.shortcut);
      if(it.dividerAfter) m.flags |= FL_MENU_DIVIDER;
      if(it.kind == Ui::MenuItem::Submenu) {
        m.flags |= FL_SUBMENU;
        _popup.items.push_back(m);
        _appendPopup(it.children);
        Fl_Menu_Item end;
        _blank(end);
        _popup.items.push_back(end);
        continue;
      }
      if(it.kind == Ui::MenuItem::Toggle) {
        m.flags |= FL_MENU_TOGGLE;
        if(it.checked && it.checked()) m.flags |= FL_MENU_VALUE;
      }
      if(it.enabled && !it.enabled()) m.flags |= FL_MENU_INACTIVE;
      if(it.preferred && _preferred.empty()) _preferred = it.label;
      _popup.byId.push_back(&it);
      m.user_data_ = (void *)(intptr_t)_popup.byId.size();
      _popup.items.push_back(m);
    }
  }

} // namespace

void fltkMenuPopup(const std::vector<Ui::MenuItem> &tree, int x, int y,
                   const std::string &key)
{
  std::string &last = _popup.last[key];
  _popup.labels.clear();
  _popup.items.clear();
  _popup.byId.clear();
  _preferred.clear();
  // moved in first: what follows takes pointers into it
  _popup.tree = tree;
  _appendPopup(_popup.tree);
  Fl_Menu_Item end;
  _blank(end);
  _popup.items.push_back(end);

  // the entry it opened on last time, or the one the description prefers
  if(last.empty()) last = _preferred;
  Fl_Menu_Item *at = nullptr;
  for(std::size_t i = 0; i < _popup.items.size(); i++) {
    if(!_popup.items[i].text) continue;
    if(last == _popup.items[i].text) {
      at = &_popup.items[i];
      break;
    }
  }

  const Fl_Menu_Item *picked = _popup.items[0].popup(x, y, nullptr, at, nullptr);
  if(!picked || !picked->user_data_) return;
  last = picked->text ? picked->text : "";
  std::size_t id = (std::size_t)(intptr_t)picked->user_data_;
  if(!id || id > _popup.byId.size()) return;
  const Ui::MenuItem *item = _popup.byId[id - 1];
  if(item && item->action) item->action();
}

Fl_Menu_Item *fltkMenuBuild(bool systemBar)
{
  _menu.labels.clear();
  _menu.items.clear();
  _menu.byId.clear();
  // moved in first: what follows takes pointers into it
  _menu.tree = uiSources().menuBar();

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
    const Ui::MenuItem *it = _menu.byId[id - 1];
    if(!it) continue;
    if(it->kind == Ui::MenuItem::Toggle && it->checked) {
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
