// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <cstdio>
#include <map>
#include <set>

#include "win32Common.h"

// The tree as a tree view of Windows: a branch is filled the first time it
// is opened, so that what is asked of the description is what is shown. A
// line of a tree view holds no control: a line with a field says its value
// after its name, and the field of the line picked is edited in a panel under
// the tree. A node is its path, which is what survives a rebuild.

class win32Tree {
public:
  Ui::Tree tree;
  bool picks = false;
  std::function<void()> after;
  HWND view = nullptr, editor = nullptr;
  win32Field *editing = nullptr;
  std::string editingPath;
  unsigned built = 0;
  bool everBuilt = false, quiet = false;
  // the path of each line, by the number the line carries
  std::vector<std::string> paths;
  std::map<std::string, HTREEITEM> items;
  std::set<std::string> filled;
  std::map<std::string, bool> wanted;
};

namespace {

  std::string _labelOf(const Ui::Node &node, const std::string &path)
  {
    if(node.label.size()) return node.label;
    std::size_t slash = path.find_last_of('/');
    return slash == std::string::npos ? path : path.substr(slash + 1);
  }

  // the name of a line, and after it what its field says
  std::string _say(const Ui::Node &node, const std::string &path)
  {
    std::string label = _labelOf(node, path);
    if(!node.hasField) return label;
    const Ui::Field &f = node.field;
    char v[64];
    switch(f.kind) {
    case Ui::Check:
      return std::string(f.getFlag() ? "☑ " : "☐ ") +
             (f.label.size() ? f.label : label);
    case Ui::Integer:
    case Ui::Number:
      snprintf(v, sizeof(v), "%g", f.getNumber());
      return label + ": " + v;
    case Ui::Text:
    case Ui::Output: return label + ": " + f.getText();
    case Ui::Choice: {
      std::vector<std::string> labels;
      std::vector<int> values;
      if(f.dynamicChoices)
        f.dynamicChoices(labels, values);
      else {
        labels = f.choices;
        values = f.values;
      }
      if(values.empty()) return label + ": " + f.getText();
      for(std::size_t k = 0; k < values.size() && k < labels.size(); k++)
        if(values[k] == (int)f.getNumber()) return label + ": " + labels[k];
      return label;
    }
    default: return label;
    }
  }

  std::string _pathOf(win32Tree *t, HTREEITEM item)
  {
    TVITEMW it;
    memset(&it, 0, sizeof(it));
    it.mask = TVIF_PARAM | TVIF_HANDLE;
    it.hItem = item;
    if(!SendMessageW(t->view, TVM_GETITEMW, 0, (LPARAM)&it)) return "";
    std::size_t k = (std::size_t)it.lParam;
    return k < t->paths.size() ? t->paths[k] : "";
  }

  void _branch(win32Tree *t, HTREEITEM parent, const std::string &path);

  // the lines of a branch, the first time it opens
  void _fill(win32Tree *t, HTREEITEM item, const std::string &path)
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

  void _branch(win32Tree *t, HTREEITEM parent, const std::string &path)
  {
    if(!t->tree.children || !t->tree.node) return;
    bool commands = win32Sources().settings().showModuleMenu;
    for(const std::string &child : t->tree.children(path)) {
      if(path.empty() && child == "0Modules" && !commands && !t->picks) continue;
      Ui::Node node = t->tree.node(child);
      bool branch = !t->tree.children(child).empty();
      std::wstring text = win32Wide(_say(node, child));
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

  void _build(win32Tree *t)
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
    TreeView_DeleteAllItems(t->view);
    t->paths.clear();
    t->items.clear();
    t->filled.clear();
    _branch(t, nullptr, "");
    SendMessageW(t->view, WM_SETREDRAW, TRUE, 0);
    InvalidateRect(t->view, nullptr, TRUE);
    t->quiet = false;
    t->wanted.clear();
  }

  // the field of the line picked, in the panel under the tree
  void _edit(win32Tree *t, const std::string &path)
  {
    if(!t->editor) return;
    if(t->editing && path == t->editingPath) return;
    if(t->editing) win32DropField(t->editing);
    t->editing = nullptr;
    t->editingPath.clear();
    Ui::Node node = t->tree.node ? t->tree.node(path) : Ui::Node();
    if(!node.hasField || node.field.kind == Ui::Action) {
      ShowWindow(t->editor, SW_HIDE);
      return;
    }
    win32Tree *self = t;
    t->editing = win32MakeField(t->editor, node.field, [self]() {
      if(self->after) self->after();
    });
    t->editingPath = path;
    RECT r;
    GetClientRect(t->editor, &r);
    int pad = win32Px(.3), row = win32Row();
    int w = r.right - 2 * pad;
    RECT widget = {pad, pad, pad + (node.field.kind == Ui::Check ? w : w / 2),
                   pad + row};
    RECT label = {pad + w / 2 + pad, pad, pad + w, pad + row};
    if(node.field.kind == Ui::Check) label = RECT{0, 0, 0, 0};
    win32PlaceField(t->editing, widget, label, std::vector<RECT>(), true);
    ShowWindow(t->editor, SW_SHOWNA);
  }

} // namespace

win32Tree *win32MakeTree(HWND parent, const Ui::Tree &tree, bool picks,
                         const std::function<void()> &after)
{
  win32Tree *t = new win32Tree;
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
  win32RefreshTree(t, true);
  return t;
}

void win32DropTree(win32Tree *t)
{
  if(!t) return;
  if(t->editing) win32DropField(t->editing);
  if(t->view) DestroyWindow(t->view);
  delete t;
}

HWND win32TreeWindow(win32Tree *t) { return t ? t->view : nullptr; }

void win32SetTree(win32Tree *t, const Ui::Tree &tree)
{
  if(t) t->tree = tree;
}

void win32SetTreeEditor(win32Tree *t, HWND panel)
{
  if(!t) return;
  t->editor = panel;
  ShowWindow(panel, SW_HIDE);
}

void win32RefreshTree(win32Tree *t, bool rebuild)
{
  if(!t) return;
  unsigned generation = t->tree.generation ? t->tree.generation() : 0;
  if(rebuild || !t->everBuilt || generation != t->built) {
    t->everBuilt = true;
    t->built = generation;
    if(t->editing) win32DropField(t->editing);
    t->editing = nullptr;
    t->editingPath.clear();
    if(t->editor) ShowWindow(t->editor, SW_HIDE);
    _build(t);
    return;
  }
  if(!t->tree.node) return;
  // what each line says now
  t->quiet = true;
  for(const auto &it : t->items) {
    Ui::Node node = t->tree.node(it.first);
    std::wstring text = win32Wide(_say(node, it.first));
    TVITEMW one;
    memset(&one, 0, sizeof(one));
    one.mask = TVIF_TEXT | TVIF_HANDLE;
    one.hItem = it.second;
    one.pszText = &text[0];
    SendMessageW(t->view, TVM_SETITEMW, 0, (LPARAM)&one);
    if(t->picks)
      TreeView_SetCheckState(t->view, it.second, node.picked && node.picked());
  }
  if(t->editing) {
    Ui::Node node = t->tree.node(t->editingPath);
    win32RebindField(t->editing, node.field);
    win32RefreshField(t->editing);
  }
  t->quiet = false;
  InvalidateRect(t->view, nullptr, FALSE);
}

void win32OpenTreeItem(win32Tree *t, const std::string &path, bool open)
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

bool win32TreeItemOpen(win32Tree *t, const std::string &path)
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

bool win32TreeNotify(win32Tree *t, NMHDR *n, LRESULT &result)
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
    return true;
  }
  case TVN_SELCHANGEDW: {
    if(t->quiet || t->picks) return true;
    NMTREEVIEWW *tv = (NMTREEVIEWW *)n;
    _edit(t, _pathOf(t, tv->itemNew.hItem));
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
      win32Tree *self = t;
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
      if(node.hasField && node.field.kind == Ui::Check) {
        // a switch flips where it is written
        Ui::Field f = node.field;
        std::function<void()> after = t->after;
        win32Later([f, after]() {
          const_cast<Ui::Field &>(f).setFlag(!f.getFlag());
          if(f.changed) f.changed();
          if(after) after();
        });
      }
      else if(node.pressed) {
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
