// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <map>
#include <set>

#include "win32Common.h"

// A described form as a window of Windows: every item where Layout.h puts it
// -- the flex and grid translation of Form.h, Win32 placing its controls
// itself as FLTK does -- tabs a tab control over a panel for each pane,
// a box that scrolls a panel scrolling another. Built again when the shape
// changed, the controls moved when what is folded away changed, the values
// put back otherwise.

namespace {

  const int ScrollStep = 30;

} // namespace

class dialogWin32 {
public:
  const Ui::Form *which = nullptr;
  Ui::Form panel;
  HWND win = nullptr;
  std::string built, pane, folding;
  bool forcePane = false, dropping = false;
  std::vector<Ui::PlacedItem> placed;
  // where the children of each placed item go: the panel, and the place in
  // the form, in em, of its corner
  struct holder {
    HWND panel = nullptr;
    double ox = 0., oy = 0.;
    int pad = 0;
  };
  std::vector<holder> holders;
  // the window made for an item that is not a field: tabs, a scroll, a rule
  std::vector<HWND> groups;
  struct paneGroup {
    std::string label;
    HWND page, tabs;
    int n;
    std::size_t index;
  };
  std::vector<paneGroup> panes;
  // the panel that scrolls, the panel it moves, how far it has moved
  struct scroller {
    HWND view, content;
    int height, at;
  };
  std::vector<scroller> scrollers;
  struct bound {
    fieldWin32 *field;
    std::size_t index;
  };
  std::vector<bound> fields;
  std::set<std::string> options;
  int widest = 0;
  bool timer = false;

  ~dialogWin32();
  void build();
  void reshape();
  void refresh();
  void show();
  void hide();
  bool shown() const { return win && IsWindowVisible(win); }
  void applyPane();
  bool relayout(bool always);
  void scroll(HWND view, int to);

private:
  Ui::Placement _placement(const Ui::Form &p);
  void _clear();
  HWND _container(const Ui::PlacedItem &p, int &dx, int &dy);
  void _place(bound &b);
};

namespace {

  std::map<const Ui::Form *, dialogWin32 *> &_dialogs()
  {
    static std::map<const Ui::Form *, dialogWin32 *> dialogs;
    return dialogs;
  }

  bool _closingDown = false;
  HWND _main = nullptr;

  dialogWin32 *_find(const Ui::Form *which)
  {
    auto it = _dialogs().find(which);
    return it == _dialogs().end() ? nullptr : it->second;
  }

  dialogWin32 *_ofWindow(HWND w)
  {
    HWND root = GetAncestor(w, GA_ROOT);
    return root ? (dialogWin32 *)GetPropW(root, L"gmshDialog") : nullptr;
  }

  // once the message is over, the forms changed are looked at again: what
  // changed may have been the shape
  std::set<const Ui::Form *> _pending;

  void _askReshape(const Ui::Form *which)
  {
    if(_pending.empty())
      win32Later([]() {
        std::set<const Ui::Form *> now;
        now.swap(_pending);
        for(const Ui::Form *w : now)
          if(dialogWin32 *d = _find(w))
            if(d->shown()) d->reshape();
      });
    _pending.insert(which);
  }

  int _px(double em) { return (int)std::floor(em * win32Em() + 0.5); }

  // what the panels of a dialog do with what their controls do not take
  LRESULT _hook(HWND w, UINT msg, WPARAM wp, LPARAM lp, bool &taken)
  {
    dialogWin32 *d = _ofWindow(w);
    taken = false;
    if(!d) return 0;
    switch(msg) {
    case WM_CLOSE:
      if(w == d->win) {
        taken = true;
        d->hide();
      }
      return 0;
    case WM_COMMAND:
      // Escape, as IsDialogMessage() tells it
      if(w == d->win && LOWORD(wp) == IDCANCEL) {
        taken = true;
        d->hide();
      }
      return 0;
    case WM_NOTIFY: {
      NMHDR *n = (NMHDR *)lp;
      if(n->code != TCN_SELCHANGE) return 0;
      taken = true;
      int sel = TabCtrl_GetCurSel(n->hwndFrom);
      for(const auto &p : d->panes) {
        if(p.tabs != n->hwndFrom || p.n != sel) continue;
        bool moved = d->pane != p.label;
        d->pane = p.label;
        std::function<void(const std::string &)> chosen =
          d->placed[p.index].item->tabs->chosen;
        std::string label = p.label;
        d->refresh();
        // told once the message is over: what it does may make the window
        // again
        if(moved && chosen) win32Later([chosen, label]() { chosen(label); });
        break;
      }
      return 0;
    }
    case WM_VSCROLL:
    case WM_MOUSEWHEEL: {
      for(auto &s : d->scrollers) {
        if(msg == WM_VSCROLL && s.view != w) continue;
        if(msg == WM_MOUSEWHEEL) {
          // the wheel scrolls the box under the pointer
          POINT p = {(short)LOWORD(lp), (short)HIWORD(lp)};
          RECT r;
          GetWindowRect(s.view, &r);
          if(!PtInRect(&r, p)) continue;
        }
        taken = true;
        int to = s.at;
        if(msg == WM_MOUSEWHEEL)
          to -= GET_WHEEL_DELTA_WPARAM(wp) / WHEEL_DELTA * ScrollStep;
        else {
          switch(LOWORD(wp)) {
          case SB_LINEUP: to -= ScrollStep; break;
          case SB_LINEDOWN: to += ScrollStep; break;
          case SB_PAGEUP: to -= 5 * ScrollStep; break;
          case SB_PAGEDOWN: to += 5 * ScrollStep; break;
          case SB_THUMBTRACK:
          case SB_THUMBPOSITION: {
            SCROLLINFO si;
            si.cbSize = sizeof(si);
            si.fMask = SIF_TRACKPOS;
            GetScrollInfo(s.view, SB_VERT, &si);
            to = si.nTrackPos;
          } break;
          default: break;
          }
        }
        d->scroll(s.view, to);
        break;
      }
      return 0;
    }
    case WM_TIMER:
      if(w == d->win) {
        taken = true;
        if(d->shown()) d->reshape();
      }
      return 0;
    default: return 0;
    }
  }

} // namespace

dialogWin32::~dialogWin32()
{
  dropping = true;
  _clear();
  if(win) DestroyWindow(win);
}

void dialogWin32::_clear()
{
  for(auto &b : fields) win32DropField(b.field);
  fields.clear();
  for(HWND g : groups)
    if(g) DestroyWindow(g);
  groups.clear();
  holders.clear();
  panes.clear();
  scrollers.clear();
  options.clear();
}

Ui::Placement dialogWin32::_placement(const Ui::Form &p)
{
  Ui::Metrics m = win32Metrics();
  Ui::Size need = Ui::treeSize(p.content, m, p.leastRows);
  // never so narrow that a dialog with little in it looks starved
  double width = std::max(need.w, 12.);
  int pixels = _px(width);
  // keeps the widest width asked for, so that it sits still
  if(pixels > widest)
    widest = pixels;
  else
    width = widest / win32Em();
  return Ui::placeTree(p.content, m, width, need.h, p.leastRows);
}

// the panel an item goes into, and where that panel's corner is in the
// pixels of the form
HWND dialogWin32::_container(const Ui::PlacedItem &p, int &dx, int &dy)
{
  const holder *h = nullptr;
  if(p.parent != (std::size_t)-1 && p.parent < holders.size()) {
    if(p.pane >= 0) {
      for(const auto &pg : panes)
        if(pg.index == p.parent && pg.n == p.pane) {
          dx = _px(placed[p.parent].panes[(std::size_t)p.pane].x);
          dy = _px(placed[p.parent].panes[(std::size_t)p.pane].y);
          return pg.page;
        }
    }
    h = &holders[p.parent];
  }
  if(!h || !h->panel) {
    int pad = _px(.5);
    dx = -pad;
    dy = -pad;
    return win;
  }
  dx = _px(h->ox) - h->pad;
  dy = _px(h->oy) - h->pad;
  return h->panel;
}

void dialogWin32::_place(bound &b)
{
  const Ui::PlacedItem &p = placed[b.index];
  int dx = 0, dy = 0;
  _container(p, dx, dy);
  const Ui::Field &f = p.field;
  int row = win32Row();
  int x = _px(p.box.x) - dx, y = _px(p.box.y) - dy;
  int w = _px(p.box.w), h = _px(p.box.h);
  bool tall = f.kind == Ui::Prose || f.kind == Ui::List ||
              f.kind == Ui::Hierarchy || f.kind == Ui::ColorMap ||
              f.kind == Ui::Direction || f.hangs ||
              (f.kind == Ui::Label && f.wraps);
  int wh = tall ? h : std::min(h, row);
  // a line of widgets in the middle of the room it has
  int wy = tall ? y : y + std::max(0, (h - wh) / 2);
  RECT widget = {x, wy, x + w, wy + wh};
  RECT label = {0, 0, 0, 0};
  if(p.label.w > 0.)
    label = RECT{_px(p.label.x) - dx, wy, _px(p.label.x + p.label.w) - dx,
                 wy + std::min(h, row)};
  std::vector<RECT> trailing;
  for(const Ui::Rect &t : p.trailing)
    trailing.push_back(RECT{_px(t.x) - dx, wy, _px(t.x + t.w) - dx, wy + row});
  win32PlaceField(b.field, widget, label, trailing, !p.hidden);
}

void dialogWin32::build()
{
  bool again = win != nullptr;
  _clear();
  panel = *which;
  built = Ui::signature(panel);
  folding = Ui::folding(panel);
  forcePane = true;

  Ui::Placement placement = _placement(panel);
  placed = placement.items;
  int pad = _px(.5);
  int cw = _px(placement.width) + 2 * pad, ch = _px(placement.height) + 2 * pad;
  DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX |
                WS_CLIPCHILDREN;
  DWORD ex = WS_EX_CONTROLPARENT | WS_EX_DLGMODALFRAME;
  RECT r = {0, 0, cw, ch};
  AdjustWindowRectEx(&r, style, FALSE, ex);
  std::wstring title = win32Wide(panel.title);
  if(!again) {
    win = CreateWindowExW(ex, win32PanelClass(), title.c_str(), style,
                          CW_USEDEFAULT, CW_USEDEFAULT, r.right - r.left,
                          r.bottom - r.top, _main, nullptr,
                          GetModuleHandleW(nullptr), nullptr);
    SetPropW(win, L"gmshDialog", (HANDLE)this);
    win32SetPanelHook(win, _hook);
    const Ui::Backend::Settings set = win32Sources().settings();
    if(set.dialogX > 0 || set.dialogY > 0)
      SetWindowPos(win, nullptr, set.dialogX, set.dialogY, 0, 0,
                   SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
  }
  else {
    SetWindowTextW(win, title.c_str());
    SetWindowPos(win, nullptr, 0, 0, r.right - r.left, r.bottom - r.top,
                 SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
  }

  // the containers first, then every item into the one it is placed in
  holders.assign(placed.size(), holder());
  groups.assign(placed.size(), nullptr);
  const Ui::Metrics m = win32Metrics();
  const Ui::Form *form = which;
  for(std::size_t i = 0; i < placed.size(); i++) {
    const Ui::PlacedItem &p = placed[i];
    int dx = 0, dy = 0;
    HWND into = _container(p, dx, dy);
    int x = _px(p.box.x) - dx, y = _px(p.box.y) - dy;
    int w = _px(p.box.w), h = _px(p.box.h);
    if(p.item->kind == Ui::Item::ATabs) {
      HWND tabs = CreateWindowExW(0, WC_TABCONTROLW, L"",
                                  WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                                    WS_TABSTOP,
                                  x, y, w, h, into, nullptr,
                                  GetModuleHandleW(nullptr), nullptr);
      SendMessageW(tabs, WM_SETFONT, (WPARAM)win32Font(), TRUE);
      groups[i] = tabs;
      int n = 0;
      for(const auto &t : p.item->tabs->tabs) {
        std::wstring label = win32Wide(t.first.size() ? t.first : "·");
        TCITEMW ti;
        memset(&ti, 0, sizeof(ti));
        ti.mask = TCIF_TEXT;
        ti.pszText = &label[0];
        SendMessageW(tabs, TCM_INSERTITEMW, (WPARAM)n, (LPARAM)&ti);
        const Ui::Rect &pr = p.panes[(std::size_t)n];
        HWND page = win32Panel(into, _px(pr.x) - dx, _px(pr.y) - dy, _px(pr.w),
                               _px(pr.h));
        win32SetPanelHook(page, _hook);
        // over the tab control, which is its sibling
        SetWindowPos(page, HWND_TOP, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        panes.push_back({t.first, page, tabs, n, i});
        n++;
      }
      holders[i].panel = into;
      continue;
    }
    if(p.item->kind == Ui::Item::ABox && p.item->box->scrolling) {
      HWND view = win32Panel(into, x, y, w, h);
      SetWindowLongW(view, GWL_STYLE, GetWindowLongW(view, GWL_STYLE) | WS_VSCROLL);
      SetWindowPos(view, nullptr, 0, 0, 0, 0,
                   SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
      win32SetPanelHook(view, _hook);
      // what it holds runs as far down as its last item
      double bottom = p.box.y + p.box.h;
      for(std::size_t k = i + 1; k < placed.size(); k++) {
        std::size_t up = placed[k].parent;
        bool inside = false;
        while(up != (std::size_t)-1 && up < placed.size()) {
          if(up == i) inside = true;
          up = placed[up].parent;
        }
        if(inside) bottom = std::max(bottom, placed[k].box.y + placed[k].box.h);
      }
      int height = _px(bottom - p.box.y) + _px(.3);
      HWND content = win32Panel(view, 0, 0, w - (int)(m.scrollbar * win32Em()),
                                height);
      win32SetPanelHook(content, _hook);
      groups[i] = view;
      holders[i].panel = content;
      holders[i].ox = p.box.x;
      holders[i].oy = p.box.y;
      scrollers.push_back({view, content, height, 0});
      SCROLLINFO si;
      si.cbSize = sizeof(si);
      si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
      si.nMin = 0;
      si.nMax = height;
      si.nPage = (UINT)h;
      si.nPos = 0;
      SetScrollInfo(view, SB_VERT, &si, TRUE);
      continue;
    }
    if(p.item->kind == Ui::Item::ABox) {
      // no window of its own: its items go where it goes
      int ddx = 0, ddy = 0;
      holders[i].panel = _container(p, ddx, ddy);
      holders[i].ox = ddx / win32Em();
      holders[i].oy = ddy / win32Em();
      holders[i].pad = 0;
      if(holders[i].panel == win) {
        holders[i].ox = 0.;
        holders[i].oy = 0.;
        holders[i].pad = pad;
      }
      continue;
    }
    if(p.item->kind == Ui::Item::ARule) {
      HWND line = CreateWindowExW(0, L"STATIC", L"",
                                  WS_CHILD | WS_VISIBLE | SS_ETCHEDHORZ, x,
                                  y + h / 2, w, 2, into, nullptr,
                                  GetModuleHandleW(nullptr), nullptr);
      groups[i] = line;
      continue;
    }
    fieldWin32 *f = win32MakeField(into, p.field, [form]() { _askReshape(form); });
    bound b = {f, i};
    fields.push_back(b);
    if(p.field.option.size()) options.insert(p.field.option);
    _place(fields.back());
  }
  for(std::size_t i = 0; i < placed.size(); i++)
    if(groups[i] && placed[i].hidden) ShowWindow(groups[i], SW_HIDE);
  applyPane();
}

void dialogWin32::scroll(HWND view, int to)
{
  for(auto &s : scrollers) {
    if(s.view != view) continue;
    RECT r;
    GetClientRect(view, &r);
    to = std::max(0, std::min(to, s.height - (int)r.bottom));
    if(to == s.at) return;
    s.at = to;
    SetScrollPos(view, SB_VERT, to, TRUE);
    SetWindowPos(s.content, nullptr, 0, -to, 0, 0,
                 SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
    return;
  }
}

// the controls moved to where the form now puts them: what folded away
// takes no room; false when the form is not the shape they were made for
bool dialogWin32::relayout(bool always)
{
  if(!win) return true;
  std::string folded = Ui::folding(panel);
  if(!always && folded == folding) return true;
  folding = folded;
  Ui::Placement placement = _placement(panel);
  if(placement.items.size() != placed.size()) return false;
  placed = placement.items;
  int pad = _px(.5);
  int cw = _px(placement.width) + 2 * pad, ch = _px(placement.height) + 2 * pad;
  RECT r = {0, 0, cw, ch};
  AdjustWindowRectEx(&r, (DWORD)GetWindowLongW(win, GWL_STYLE), FALSE,
                     (DWORD)GetWindowLongW(win, GWL_EXSTYLE));
  SetWindowPos(win, nullptr, 0, 0, r.right - r.left, r.bottom - r.top,
               SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
  for(std::size_t i = 0; i < placed.size(); i++) {
    const Ui::PlacedItem &p = placed[i];
    if(!groups[i]) continue;
    int dx = 0, dy = 0;
    _container(p, dx, dy);
    int x = _px(p.box.x) - dx, y = _px(p.box.y) - dy;
    int w = _px(p.box.w), h = _px(p.box.h);
    if(p.item->kind == Ui::Item::ARule)
      MoveWindow(groups[i], x, y + h / 2, w, 2, TRUE);
    else
      MoveWindow(groups[i], x, y, w, h, TRUE);
    ShowWindow(groups[i], p.hidden ? SW_HIDE : SW_SHOWNA);
  }
  for(auto &b : fields) {
    const Ui::PlacedItem &p = placed[b.index];
    win32RebindField(b.field, p.field);
    _place(b);
  }
  return true;
}

void dialogWin32::applyPane()
{
  if(forcePane) {
    forcePane = false;
    for(const auto &p : panes) {
      if(p.label != pane) continue;
      TabCtrl_SetCurSel(p.tabs, p.n);
      // and the tabs the pane's are in, for tabs under tabs
      for(const auto &o : panes)
        if(IsChild(o.page, p.tabs)) TabCtrl_SetCurSel(o.tabs, o.n);
    }
  }
  for(const auto &p : panes) {
    bool on = TabCtrl_GetCurSel(p.tabs) == p.n;
    // and every row of tabs above it showing its own
    for(const auto &o : panes)
      if(IsChild(o.page, p.page) && TabCtrl_GetCurSel(o.tabs) != o.n) on = false;
    if(placed[p.index].hidden) on = false;
    ShowWindow(p.page, on ? SW_SHOWNA : SW_HIDE);
  }
}

void dialogWin32::refresh()
{
  relayout(false);
  applyPane();
  for(auto &b : fields) win32RefreshField(b.field);
}

void dialogWin32::reshape()
{
  if(!which) return;
  Ui::Form now = *which;
  if(win && Ui::signature(now) == built) {
    panel = now;
    if(relayout(true)) {
      refresh();
      return;
    }
  }
  build();
  refresh();
}

void dialogWin32::show()
{
  Ui::Form now = *which;
  if(!win || Ui::signature(now) != built)
    build();
  else
    panel = now;
  forcePane = true;
  refresh();
  ShowWindow(win, IsWindowVisible(win) ? SW_SHOWNA : SW_SHOW);
  SetForegroundWindow(win);
  if(panel.refreshEvery > 0. && !timer) {
    SetTimer(win, 1, (UINT)(panel.refreshEvery * 1000.), nullptr);
    timer = true;
  }
}

void dialogWin32::hide()
{
  if(!win || !IsWindowVisible(win)) return;
  ShowWindow(win, SW_HIDE);
  if(timer) KillTimer(win, 1);
  timer = false;
  // hiding a dialog undoes what it leaves behind
  if(!_closingDown && !dropping && panel.closed) win32Later(panel.closed);
}

// --- what the backend asks

namespace {
  dialogWin32 *_dialog(const Ui::Form &form)
  {
    dialogWin32 *d = _find(&form);
    if(d) return d;
    d = new dialogWin32;
    d->which = &form;
    _dialogs()[&form] = d;
    return d;
  }
} // namespace

void win32ShowForm(const Ui::Form &form, bool show)
{
  if(!show) {
    if(dialogWin32 *d = _find(&form)) d->hide();
    return;
  }
  _dialog(form)->show();
}

bool win32FormVisible(const Ui::Form &form)
{
  dialogWin32 *d = _find(&form);
  return d && d->shown();
}

std::string win32FormPane(const Ui::Form &form)
{
  dialogWin32 *d = _find(&form);
  return d ? d->pane : "";
}

void win32SetFormPane(const Ui::Form &form, const std::string &pane)
{
  dialogWin32 *d = _dialog(form);
  d->pane = pane;
  d->forcePane = true;
  if(d->shown()) d->applyPane();
}

void win32ReloadForm(const Ui::Form &form)
{
  dialogWin32 *d = _find(&form);
  if(d && d->shown()) d->reshape();
}

void win32DropForm(const Ui::Form &form)
{
  auto it = _dialogs().find(&form);
  if(it == _dialogs().end()) return;
  dialogWin32 *d = it->second;
  _dialogs().erase(it);
  _pending.erase(&form);
  delete d;
}

void win32FormOptionChanged(const std::string &name)
{
  for(auto &it : _dialogs()) {
    dialogWin32 *d = it.second;
    if(!d->shown() || !d->options.count(name)) continue;
    for(auto &b : d->fields) win32RefreshField(b.field);
  }
}

void win32FormsClosingDown()
{
  _closingDown = true;
  for(auto &it : _dialogs()) delete it.second;
  _dialogs().clear();
  _pending.clear();
}

void win32SetMainWindow(HWND window) { _main = window; }

HWND win32MainWindow() { return _main; }

bool win32FormDialogMessage(MSG &m)
{
  // the keys that move between controls, in the window of a form
  HWND root = GetAncestor(m.hwnd, GA_ROOT);
  if(!root || !GetPropW(root, L"gmshDialog")) return false;
  return IsDialogMessageW(root, &m) != 0;
}
