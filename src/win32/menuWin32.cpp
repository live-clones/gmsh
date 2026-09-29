// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <cctype>

#include "win32Common.h"

// The menus are menus of Windows made from the description, each entry a
// command whose number is its place in the list of the entries of the bar.
// The shortcut is written after a tab, which Windows shows at the right of
// the entry without making it one: the keys are read by the loop, off
// Sources::keys, as in the other interfaces. What is checked and greyed is
// read again as each menu opens.

namespace {

  // the entries of the bar, by the number of their command
  const WORD BarFirst = 0x1000, PopupFirst = 0x8000;
  std::vector<Ui::MenuItem> _bar;

  std::wstring _label(const Ui::MenuItem &it)
  {
    std::string out;
    bool marked = false;
    for(char c : it.label) {
      if(c == '&') {
        out += "&&";
        continue;
      }
      if(!marked && it.mnemonic &&
         std::tolower((unsigned char)c) ==
           std::tolower((unsigned char)it.mnemonic)) {
        out += '&';
        marked = true;
      }
      out += c;
    }
    std::string shortcut = it.shortcut.label();
    if(shortcut.size()) out += "\t" + shortcut;
    return win32Wide(out);
  }

  // the entries into the menu, their commands numbered from `first` in the
  // order of `into`
  void _fill(HMENU menu, const std::vector<Ui::MenuItem> &items,
             std::vector<Ui::MenuItem> &into, WORD first)
  {
    for(const auto &it : items) {
      std::wstring label = _label(it);
      bool enabled = it.enabled ? it.enabled() : true;
      if(it.kind == Ui::MenuItem::Submenu) {
        HMENU sub = CreatePopupMenu();
        _fill(sub, it.children, into, first);
        AppendMenuW(menu, MF_POPUP | MF_STRING | (enabled ? 0 : MF_GRAYED),
                    (UINT_PTR)sub, label.c_str());
      }
      else {
        WORD id = (WORD)(first + into.size());
        into.push_back(it);
        UINT flags = MF_STRING | (enabled ? 0 : MF_GRAYED);
        if(it.kind == Ui::MenuItem::Toggle && it.checked && it.checked())
          flags |= MF_CHECKED;
        AppendMenuW(menu, flags, id, label.c_str());
      }
      if(it.dividerAfter) AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    }
  }

} // namespace

void win32RefreshMenuBar(HWND window)
{
  static unsigned built = 0;
  static bool ever = false;
  if(!window || !win32Sources().menuBar) return;
  unsigned generation =
    win32Sources().menuGeneration ? win32Sources().menuGeneration() : 0;
  if(ever && generation == built) return;
  ever = true;
  built = generation;
  _bar.clear();
  HMENU bar = CreateMenu();
  for(const auto &it : win32Sources().menuBar()) {
    if(it.kind != Ui::MenuItem::Submenu) continue;
    HMENU sub = CreatePopupMenu();
    _fill(sub, it.children, _bar, BarFirst);
    AppendMenuW(bar, MF_POPUP | MF_STRING, (UINT_PTR)sub, _label(it).c_str());
  }
  HMENU was = GetMenu(window);
  SetMenu(window, bar);
  if(was) DestroyMenu(was);
  DrawMenuBar(window);
}

void win32MenuOpens(HMENU menu)
{
  int n = GetMenuItemCount(menu);
  for(int i = 0; i < n; i++) {
    UINT id = GetMenuItemID(menu, i);
    if(id < BarFirst || id >= BarFirst + _bar.size()) continue;
    const Ui::MenuItem &it = _bar[id - BarFirst];
    bool enabled = it.enabled ? it.enabled() : true;
    EnableMenuItem(menu, id, MF_BYCOMMAND | (enabled ? MF_ENABLED : MF_GRAYED));
    if(it.kind == Ui::MenuItem::Toggle)
      CheckMenuItem(menu, id,
                    MF_BYCOMMAND |
                      (it.checked && it.checked() ? MF_CHECKED : MF_UNCHECKED));
  }
}

bool win32MenuCommand(WORD id)
{
  if(id < BarFirst || id >= BarFirst + _bar.size()) return false;
  // a copy: the bar may be made again before it runs
  std::function<void()> what = _bar[id - BarFirst].action;
  win32Later([what]() {
    if(what) what();
    win32RefreshBar();
  });
  return true;
}

void win32PopupMenu(const std::vector<Ui::MenuItem> &items, HWND owner, int x,
                    int y)
{
  if(items.empty()) return;
  std::vector<Ui::MenuItem> entries;
  HMENU menu = CreatePopupMenu();
  _fill(menu, items, entries, PopupFirst);
  if(x < 0 || y < 0) {
    POINT p;
    GetCursorPos(&p);
    x = p.x;
    y = p.y;
  }
  HWND at = owner ? owner : win32MainWindow();
  SetForegroundWindow(at);
  UINT id = (UINT)TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, x, y, 0,
                                 at, nullptr);
  DestroyMenu(menu);
  if(id >= PopupFirst && id < PopupFirst + entries.size()) {
    std::function<void()> what = entries[id - PopupFirst].action;
    win32Later([what]() {
      if(what) what();
      win32RefreshBar();
    });
  }
}
