// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cstdio>
#include <map>
#include <set>

#include "win32Common.h"

#include <commctrl.h>

// The tree as a tree view of Windows: a branch is filled the first time it
// is opened, so that what is asked of the description is what is shown. A
// line with a field carries its controls, as the other interfaces have it:
// children of the tree view, put back over their line whenever the lines
// move (a scroll, a branch opened or closed, the view resized). The tree view
// is given what they tell, and hands it to the fields. A node is its path,
// which is what survives a rebuild.

namespace {
  // the controls a line carries: its field, and the arrow that drops its
  // menu
  struct lineWin32 {
    fieldWin32 *field = nullptr;
    HWND arrow = nullptr;
    Ui::Colour highlight;
    bool enabled = true;
  };
} // namespace

class treeWin32 {
public:
  Ui::Tree tree;
  bool picks = false;
  std::function<void()> after;
  HWND view = nullptr;
  unsigned built = 0;
  bool everBuilt = false, quiet = false, placing = false;
  // the path of each line, by the number the line carries
  std::vector<std::string> paths;
  std::map<std::string, HTREEITEM> items;
  std::set<std::string> filled;
  std::map<std::string, bool> wanted;
  std::map<std::string, lineWin32> lines;
};

namespace {

  std::string _labelOf(const Ui::Node &node, const std::string &path)
  {
    if(node.label.size()) return node.label;
    std::size_t slash = path.find_last_of('/');
    return slash == std::string::npos ? path : path.substr(slash + 1);
  }

  // the name of a line; a line with a field has its controls instead
  std::string _say(const Ui::Node &node, const std::string &path, bool carries)
  {
    return carries ? std::string() : _labelOf(node, path);
  }

  std::string _pathOf(treeWin32 *t, HTREEITEM item)
  {
    TVITEMW it;
    memset(&it, 0, sizeof(it));
    it.mask = TVIF_PARAM | TVIF_HANDLE;
    it.hItem = item;
    if(!SendMessageW(t->view, TVM_GETITEMW, 0, (LPARAM)&it)) return "";
    std::size_t k = (std::size_t)it.lParam;
    return k < t->paths.size() ? t->paths[k] : "";
  }

  void _branch(treeWin32 *t, HTREEITEM parent, const std::string &path);
  void _place(treeWin32 *t);

  bool _carries(treeWin32 *t, const Ui::Node &node)
  {
    return !t->picks && node.hasField && node.field.kind != Ui::Spacer;
  }

  void _dropLine(lineWin32 &l)
  {
    if(l.field) win32DropField(l.field);
    if(l.arrow) DestroyWindow(l.arrow);
    l = lineWin32();
  }

  // the controls of a line, made hidden; _place() puts them over it
  void _makeLine(treeWin32 *t, const std::string &path, const Ui::Node &node)
  {
    lineWin32 &l = t->lines[path];
    _dropLine(l);
    Ui::Field f = node.field;
    // a switch that says nothing itself is named by the line
    if(f.label.empty() && (f.kind == Ui::Check || f.kind == Ui::Action))
      f.label = _labelOf(node, path);
    treeWin32 *self = t;
    l.field = win32MakeField(t->view, f, [self]() {
      if(self->after) self->after();
    });
    l.highlight = node.highlight;
    l.enabled = !node.enabled || node.enabled();
    if(node.menu) {
      l.arrow = CreateWindowExW(0, L"BUTTON", L">",
                                WS_CHILD | BS_PUSHBUTTON, 0, 0, 10, 10,
                                t->view, nullptr, GetModuleHandleW(nullptr),
                                nullptr);
      SendMessageW(l.arrow, WM_SETFONT, (WPARAM)win32Font(), TRUE);
    }
    if(!l.enabled) {
      EnableWindow(win32FieldWindow(l.field), FALSE);
      if(l.arrow) EnableWindow(l.arrow, FALSE);
    }
  }

  // the lines of a branch, the first time it opens
  void _fill(treeWin32 *t, HTREEITEM item, const std::string &path)
  {
    if(t->filled.count(path)) return;
    t->filled.insert(path);
    // the placeholder that gave it its button goes
    HTREEITEM child = TreeView_GetChild(t->view, item);
    while(child) {
      HTREEITEM next = TreeView_GetNextSibling(t->view, child);
      TreeView_DeleteItem(t->view, child);
      child = next;
    }
    _branch(t, item, path);
  }

  void _branch(treeWin32 *t, HTREEITEM parent, const std::string &path)
  {
    if(!t->tree.children || !t->tree.node) return;
    bool commands = win32Sources().settings().showModuleMenu;
    for(const std::string &child : t->tree.children(path)) {
      if(path.empty() && child == "0Modules" && !commands && !t->picks) continue;
      Ui::Node node = t->tree.node(child);
      bool branch = !t->tree.children(child).empty();
      bool carries = !branch && _carries(t, node);
      std::wstring text = win32Wide(_say(node, child, carries));
      TVINSERTSTRUCTW ins;
      memset(&ins, 0, sizeof(ins));
      ins.hParent = parent ? parent : TVI_ROOT;
      ins.hInsertAfter = TVI_LAST;
      ins.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_CHILDREN;
      ins.item.pszText = &text[0];
      ins.item.lParam = (LPARAM)t->paths.size();
      ins.item.cChildren = branch ? 1 : 0;
      t->paths.push_back(child);
      HTREEITEM item = (HTREEITEM)SendMessageW(t->view, TVM_INSERTITEMW, 0,
                                               (LPARAM)&ins);
      t->items[child] = item;
      if(carries) _makeLine(t, child, node);
      if(t->picks)
        TreeView_SetCheckState(t->view, item, node.picked && node.picked());
      if(!branch) continue;
      // as the FLTK tree has it: the modules folded under their root, the
      // rest open unless the description folds it; the tree of a field folded
      bool open = !node.closed && !(t->tree.closed && t->tree.closed(child)) &&
                  !t->picks && child.compare(0, 9, "0Modules/") != 0;
      auto w = t->wanted.find(child);
      if(w != t->wanted.end()) {
        open = w->second;
        t->wanted.erase(w);
      }
      if(open) {
        _fill(t, item, child);
        TreeView_Expand(t->view, item, TVE_EXPAND);
      }
      else {
        // a placeholder, for the button that opens it
        TVINSERTSTRUCTW none;
        memset(&none, 0, sizeof(none));
        none.hParent = item;
        none.hInsertAfter = TVI_LAST;
        none.item.mask = TVIF_TEXT;
        none.item.pszText = (LPWSTR)L"";
        SendMessageW(t->view, TVM_INSERTITEMW, 0, (LPARAM)&none);
      }
    }
  }

  void _build(treeWin32 *t)
  {
    // what was open stays open
    for(const auto &it : t->items) {
      TVITEMW one;
      memset(&one, 0, sizeof(one));
      one.mask = TVIF_STATE | TVIF_HANDLE;
      one.hItem = it.second;
      one.stateMask = TVIS_EXPANDED;
      if(t->filled.count(it.first) &&
         SendMessageW(t->view, TVM_GETITEMW, 0, (LPARAM)&one) &&
         !t->wanted.count(it.first))
        t->wanted[it.first] = (one.state & TVIS_EXPANDED) != 0;
    }
    t->quiet = true;
    SendMessageW(t->view, WM_SETREDRAW, FALSE, 0);
    for(auto &l : t->lines) _dropLine(l.second);
    t->lines.clear();
    TreeView_DeleteAllItems(t->view);
    t->paths.clear();
    t->items.clear();
    t->filled.clear();
    _branch(t, nullptr, "");
    SendMessageW(t->view, WM_SETREDRAW, TRUE, 0);
    InvalidateRect(t->view, nullptr, TRUE);
    t->quiet = false;
    t->wanted.clear();
    _place(t);
  }

  // --- the controls put over their line: the value, the buttons after it,
  // then its name, as FLTK lays them out; the arrow of its menu at the end

  void _place(treeWin32 *t)
  {
    if(t->placing || t->lines.empty()) return;
    t->placing = true;
    RECT client;
    GetClientRect(t->view, &client);
    int row = win32Row();
    for(auto &it : t->lines) {
      lineWin32 &l = it.second;
      if(!l.field) continue;
      auto item = t->items.find(it.first);
      RECT r;
      bool shown = false;
      if(item != t->items.end()) {
        *(HTREEITEM *)&r = item->second;
        shown = SendMessageW(t->view, TVM_GETITEMRECT, TRUE, (LPARAM)&r) &&
                r.bottom > client.top && r.top < client.bottom;
      }
      if(!shown) {
        win32PlaceField(l.field, RECT{0, 0, 0, 0}, RECT{0, 0, 0, 0},
                        std::vector<RECT>(), false);
        if(l.arrow) ShowWindow(l.arrow, SW_HIDE);
        continue;
      }
      const Ui::Field &f = win32FieldOf(l.field);
      int y = r.top + std::max(0, (int)(r.bottom - r.top - row) / 2);
      int x = r.left, right = client.right - 2;
      if(l.arrow) {
        int aw = row;
        MoveWindow(l.arrow, right - aw, y, aw, row, TRUE);
        ShowWindow(l.arrow, SW_SHOWNA);
        right -= aw + 2;
      }
      int w = std::max(row, right - x);
      bool nameInside = f.kind == Ui::Check || f.kind == Ui::Action;
      int lineW = nameInside ? w : w / 2;
      // a narrow one for the range, two wider for the loop and the plots
      std::vector<RECT> trailing;
      int room = 0;
      for(const auto &b : f.trailing) room += b.label == ":" ? row / 2 : row;
      int valueW = std::max(row, lineW - room);
      RECT widget = {x, y, x + valueW, y + row};
      int at = x + valueW;
      for(const auto &b : f.trailing) {
        int wide = b.label == ":" ? row / 2 : row;
        trailing.push_back(RECT{at, y, at + wide, y + row});
        at += wide;
      }
      RECT label = {0, 0, 0, 0};
      if(!nameInside) label = RECT{at + 4, y, right, y + row};
      win32PlaceField(l.field, widget, label, trailing, true);
    }
    t->placing = false;
  }

  // once the message that moved the lines is over, where they are now
  void _placeLater(treeWin32 *t)
  {
    HWND view = t->view;
    win32Later([view]() {
      if(treeWin32 *u = (treeWin32 *)GetPropW(view, L"gmshTree")) _place(u);
    });
  }

  // what the controls on the lines tell goes to their fields; the lines
  // moved, the controls follow
  LRESULT CALLBACK _viewProc(HWND w, UINT msg, WPARAM wp, LPARAM lp,
                             UINT_PTR, DWORD_PTR data)
  {
    treeWin32 *t = (treeWin32 *)data;
    switch(msg) {
    case WM_COMMAND: {
      HWND from = (HWND)lp;
      for(auto &it : t->lines)
        if(it.second.arrow && it.second.arrow == from) {
          if(HIWORD(wp) == BN_CLICKED && t->tree.node) {
            Ui::Node node = t->tree.node(it.first);
            RECT r;
            GetWindowRect(from, &r);
            if(node.menu) win32PopupMenu(node.menu(), w, r.left, r.bottom);
          }
          return 0;
        }
    } // fall through
    case WM_DRAWITEM:
    case WM_CTLCOLOREDIT: {
      LRESULT result = 0;
      if(win32FieldMessage(w, msg, wp, lp, result)) return result;
      break;
    }
    case WM_NOTIFY:
      if(((NMHDR *)lp)->hwndFrom != w) {
        LRESULT result = 0;
        if(win32FieldMessage(w, msg, wp, lp, result)) return result;
      }
      break;
    case WM_HSCROLL:
      if(lp) {
        LRESULT result = 0;
        if(win32FieldMessage(w, msg, wp, lp, result)) return result;
        return 0;
      }
      break;
    case WM_CTLCOLORSTATIC:
    case WM_CTLCOLORBTN: {
      LRESULT result = 0;
      if(win32FieldMessage(w, msg, wp, lp, result)) return result;
      // on the colour of the line: the tree's, or the one it is lit in
      static std::map<COLORREF, HBRUSH> brushes;
      COLORREF back = GetSysColor(COLOR_WINDOW);
      for(auto &it : t->lines)
        if(it.second.highlight.a && it.second.field &&
           win32FieldLabel(it.second.field) == (HWND)lp) {
          const Ui::Colour &c = it.second.highlight;
          back = RGB(c.r, c.g, c.b);
        }
      HBRUSH &b = brushes[back];
      if(!b) b = CreateSolidBrush(back);
      SetBkColor((HDC)wp, back);
      SetBkMode((HDC)wp, TRANSPARENT);
      return (LRESULT)b;
    }
    case WM_NCDESTROY:
      RemoveWindowSubclass(w, _viewProc, 1);
      break;
    default: break;
    }
    LRESULT r = DefSubclassProc(w, msg, wp, lp);
    switch(msg) {
    case WM_VSCROLL:
    case WM_HSCROLL:
    case WM_MOUSEWHEEL:
    case WM_SIZE:
    case WM_KEYDOWN:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
    case TVM_EXPAND:
    case TVM_ENSUREVISIBLE:
    case TVM_SELECTITEM: _place(t); break;
    default: break;
    }
    return r;
  }

} // namespace

treeWin32 *win32MakeTree(HWND parent, const Ui::Tree &tree, bool picks,
                         const std::function<void()> &after)
{
  treeWin32 *t = new treeWin32;
  t->tree = tree;
  t->picks = picks;
  t->after = after;
  t->view = CreateWindowExW(
    WS_EX_CLIENTEDGE, WC_TREEVIEWW, L"",
    WS_CHILD | WS_VISIBLE | WS_TABSTOP | TVS_HASBUTTONS | TVS_HASLINES |
      TVS_LINESATROOT | TVS_SHOWSELALWAYS | (picks ? TVS_CHECKBOXES : 0),
    0, 0, 10, 10, parent, nullptr, GetModuleHandleW(nullptr), nullptr);
  SendMessageW(t->view, WM_SETFONT, (WPARAM)win32Font(), TRUE);
  SetPropW(t->view, L"gmshTree", (HANDLE)t);
  if(!picks) {
    // a line as tall as the controls it carries, which it does not paint
    // over
    SetWindowLongW(t->view, GWL_STYLE,
                   GetWindowLongW(t->view, GWL_STYLE) | WS_CLIPCHILDREN);
    TreeView_SetItemHeight(t->view, win32Row() + 2);
    SetWindowSubclass(t->view, _viewProc, 1, (DWORD_PTR)t);
  }
  win32RefreshTree(t, true);
  return t;
}

void win32DropTree(treeWin32 *t)
{
  if(!t) return;
  for(auto &l : t->lines) _dropLine(l.second);
  if(t->view) {
    RemoveWindowSubclass(t->view, _viewProc, 1);
    DestroyWindow(t->view);
  }
  delete t;
}

HWND win32TreeWindow(treeWin32 *t) { return t ? t->view : nullptr; }

void win32SetTree(treeWin32 *t, const Ui::Tree &tree)
{
  if(t) t->tree = tree;
}

void win32RefreshTree(treeWin32 *t, bool rebuild)
{
  if(!t) return;
  unsigned generation = t->tree.generation ? t->tree.generation() : 0;
  if(rebuild || !t->everBuilt || generation != t->built) {
    t->everBuilt = true;
    t->built = generation;
    _build(t);
    return;
  }
  if(!t->tree.node) return;
  // what each line says now
  t->quiet = true;
  for(const auto &it : t->items) {
    Ui::Node node = t->tree.node(it.first);
    auto line = t->lines.find(it.first);
    if(line != t->lines.end() && line->second.field) {
      // the controls read the field again
      lineWin32 &l = line->second;
      Ui::Field f = node.field;
      if(f.label.empty() && (f.kind == Ui::Check || f.kind == Ui::Action))
        f.label = _labelOf(node, it.first);
      win32RebindField(l.field, f);
      win32RefreshField(l.field);
      l.highlight = node.highlight;
      bool enabled = !node.enabled || node.enabled();
      if(!enabled) EnableWindow(win32FieldWindow(l.field), FALSE);
      if(l.arrow) EnableWindow(l.arrow, enabled);
      continue;
    }
    std::wstring text = win32Wide(_say(node, it.first, false));
    TVITEMW one;
    memset(&one, 0, sizeof(one));
    one.mask = TVIF_TEXT | TVIF_HANDLE;
    one.hItem = it.second;
    one.pszText = &text[0];
    SendMessageW(t->view, TVM_SETITEMW, 0, (LPARAM)&one);
    if(t->picks)
      TreeView_SetCheckState(t->view, it.second, node.picked && node.picked());
  }
  t->quiet = false;
  InvalidateRect(t->view, nullptr, FALSE);
}

void win32OpenTreeItem(treeWin32 *t, const std::string &path, bool open)
{
  if(!t) return;
  // the branches on the way are opened first, which fills them
  if(open) {
    std::size_t at = 0;
    while((at = path.find('/', at + 1)) != std::string::npos) {
      std::string up = path.substr(0, at);
      auto it = t->items.find(up);
      if(it != t->items.end()) {
        _fill(t, it->second, up);
        TreeView_Expand(t->view, it->second, TVE_EXPAND);
      }
    }
  }
  auto it = t->items.find(path);
  if(it == t->items.end()) {
    t->wanted[path] = open;
    return;
  }
  if(open) _fill(t, it->second, path);
  TreeView_Expand(t->view, it->second, open ? TVE_EXPAND : TVE_COLLAPSE);
}

bool win32TreeItemOpen(treeWin32 *t, const std::string &path)
{
  if(!t) return false;
  auto it = t->items.find(path);
  if(it == t->items.end()) {
    auto w = t->wanted.find(path);
    return w != t->wanted.end() && w->second;
  }
  return (TreeView_GetItemState(t->view, it->second, TVIS_EXPANDED) &
          TVIS_EXPANDED) != 0;
}

bool win32TreeNotify(treeWin32 *t, NMHDR *n, LRESULT &result)
{
  result = 0;
  if(!t || n->hwndFrom != t->view) return false;
  switch(n->code) {
  case TVN_ITEMEXPANDINGW: {
    NMTREEVIEWW *tv = (NMTREEVIEWW *)n;
    if(tv->action & TVE_EXPAND)
      _fill(t, tv->itemNew.hItem, _pathOf(t, tv->itemNew.hItem));
    return true;
  }
  case TVN_ITEMEXPANDEDW: {
    NMTREEVIEWW *tv = (NMTREEVIEWW *)n;
    if(!t->quiet && t->tree.setClosed)
      t->tree.setClosed(_pathOf(t, tv->itemNew.hItem),
                        !(tv->action & TVE_EXPAND));
    // the lines under it moved
    _place(t);
    _placeLater(t);
    return true;
  }
  case NM_CLICK:
  case NM_RCLICK: {
    DWORD pos = GetMessagePos();
    TVHITTESTINFO hit;
    memset(&hit, 0, sizeof(hit));
    hit.pt.x = (short)LOWORD(pos);
    hit.pt.y = (short)HIWORD(pos);
    ScreenToClient(t->view, &hit.pt);
    HTREEITEM item = TreeView_HitTest(t->view, &hit);
    if(!item || !t->tree.node) return true;
    std::string path = _pathOf(t, item);
    Ui::Node node = t->tree.node(path);
    if(n->code == NM_RCLICK) {
      if(node.menu) win32PopupMenu(node.menu(), t->view);
      result = 1;
      return true;
    }
    if(t->picks && (hit.flags & TVHT_ONITEMSTATEICON)) {
      // the box changes once the click is over: read then
      treeWin32 *self = t;
      win32Later([self, path, item]() {
        if(!self->tree.node) return;
        Ui::Node now = self->tree.node(path);
        bool on = TreeView_GetCheckState(self->view, item) == 1;
        if(now.pick) now.pick(on);
        if(self->after) self->after();
      });
      return true;
    }
    if(!t->picks && (hit.flags & TVHT_ONITEMLABEL)) {
      if(node.pressed && !_carries(t, node)) {
        std::function<void()> what = node.pressed, after = t->after;
        win32Later([what, after]() {
          what();
          if(after) after();
        });
      }
    }
    return true;
  }
  case NM_CUSTOMDRAW: {
    NMTVCUSTOMDRAW *cd = (NMTVCUSTOMDRAW *)n;
    if(cd->nmcd.dwDrawStage == CDDS_PREPAINT) {
      result = CDRF_NOTIFYITEMDRAW;
      return true;
    }
    if(cd->nmcd.dwDrawStage == CDDS_ITEMPREPAINT && t->tree.node) {
      std::size_t k = (std::size_t)cd->nmcd.lItemlParam;
      if(k < t->paths.size()) {
        Ui::Node node = t->tree.node(t->paths[k]);
        if(node.highlight.a && !(cd->nmcd.uItemState & CDIS_SELECTED))
          cd->clrTextBk = RGB(node.highlight.r, node.highlight.g, node.highlight.b);
        if(node.enabled && !node.enabled()) cd->clrText = GetSysColor(COLOR_GRAYTEXT);
      }
      result = CDRF_DODEFAULT;
      return true;
    }
    return true;
  }
  default: return false;
  }
}
