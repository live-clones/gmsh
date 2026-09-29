// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "win32Common.h"
#include "MapEditor.h"

#include <commdlg.h>
#include <windowsx.h>

// The controls of one field. Each is told where its field is by a property
// of its window, which the panel holding it looks up when the control tells
// it something: a change the user makes is written through the field, then
// told, then `after` runs; a refresh reads the field and puts the value back,
// quietly.

struct win32Field {
  Ui::Field field;
  std::function<void()> after;
  HWND parent = nullptr, widget = nullptr, label = nullptr;
  // the number of a slider
  HWND number = nullptr;
  std::vector<HWND> trailing;
  std::vector<Ui::Button> buttons;
  bool quiet = false, dragging = false;
  std::string was, shown;
  std::vector<std::string> labels;
  std::vector<int> values;
  Ui::MapEditor mapEdit;
  win32Tree *tree = nullptr;
  // the links of a page of prose
  std::vector<std::function<void()> > follow;
};

namespace {

  const wchar_t *Prop = L"gmshField";

  win32Field *_of(HWND w)
  {
    return w ? (win32Field *)GetPropW(w, Prop) : nullptr;
  }

  void _bind(HWND w, win32Field *f)
  {
    if(w) SetPropW(w, Prop, (HANDLE)f);
  }

  // a change the user made: the done() of a choosing that ended, the
  // changed() of a step, then what the holder does, once the message is over
  void _told(win32Field *f, bool ends)
  {
    if(f->quiet) return;
    Ui::Field g = f->field;
    std::function<void()> after = f->after;
    win32Later([g, ends, after]() {
      if(g.done && ends)
        g.done();
      else if(g.changed)
        g.changed();
      if(after) after();
    });
  }

  std::string _joined(const std::vector<std::string> &labels)
  {
    std::string s;
    for(const auto &l : labels) s += l + '\n';
    return s;
  }

  // with the decimals of its step when values are dragged
  std::string _number(const Ui::Field &f, double v)
  {
    return Ui::numberText(v, win32Sources().settings().inputScrolling ? f.step : 0.);
  }

  bool _isNumber(const Ui::Field &f)
  {
    return f.kind == Ui::Integer || f.kind == Ui::Number;
  }

  // what is typed, written through the field; ends says Return or the field
  // left
  void _commit(win32Field *f, bool ends)
  {
    if(f->quiet) return;
    HWND e = f->number ? f->number : f->widget;
    std::string now = win32Text(e);
    if(_isNumber(f->field)) {
      if(now == f->shown) {
        // Return says the value is the one, even as it was
        if(ends && f->field.done) _told(f, true);
        return;
      }
      double v = 0.;
      if(!Ui::readNumber(now, v)) {
        win32RefreshField(f);
        return;
      }
      v = Ui::bounded(f->field, v);
      f->field.setNumber(v);
      f->shown = _number(f->field, v);
      _told(f, true);
      return;
    }
    if(now == f->shown && !ends) return;
    f->shown = now;
    f->field.setText(now);
    _told(f, true);
  }

  // an edit control that tells Return, and steps a number with the wheel
  LRESULT CALLBACK _editProc(HWND w, UINT msg, WPARAM wp, LPARAM lp,
                             UINT_PTR, DWORD_PTR data)
  {
    win32Field *f = (win32Field *)data;
    switch(msg) {
    case WM_GETDLGCODE:
      // Return is the field's, not the window's default button
      if(lp && ((MSG *)lp)->message == WM_KEYDOWN && ((MSG *)lp)->wParam == VK_RETURN)
        return DLGC_WANTALLKEYS;
      break;
    case WM_KEYDOWN:
      if(wp == VK_RETURN) {
        _commit(f, true);
        return 0;
      }
      if(_isNumber(f->field) && f->field.step > 0. &&
         (wp == VK_UP || wp == VK_DOWN)) {
        double v = Ui::bounded(f->field, f->field.getNumber() +
                                        (wp == VK_UP ? f->field.step :
                                                       -f->field.step));
        f->field.setNumber(v);
        win32RefreshField(f);
        _told(f, false);
        return 0;
      }
      break;
    case WM_CHAR:
      // no beep for the Return taken above
      if(wp == L'\r' || wp == L'\n') return 0;
      break;
    case WM_MOUSEWHEEL:
      if(_isNumber(f->field) && f->field.step > 0. &&
         win32Sources().settings().inputScrolling && IsWindowEnabled(w)) {
        int dz = GET_WHEEL_DELTA_WPARAM(wp);
        double v = Ui::bounded(f->field, f->field.getNumber() +
                                        (dz > 0 ? f->field.step :
                                                  -f->field.step));
        f->field.setNumber(v);
        win32RefreshField(f);
        _told(f, false);
        return 0;
      }
      break;
    default: break;
    }
    return DefSubclassProc(w, msg, wp, lp);
  }

  HWND _make(const wchar_t *cls, DWORD style, HWND parent, DWORD ex = 0,
             const std::wstring &text = L"")
  {
    HWND w = CreateWindowExW(ex, cls, text.c_str(), WS_CHILD | style, 0, 0, 10,
                             10, parent, nullptr, GetModuleHandleW(nullptr),
                             nullptr);
    SendMessageW(w, WM_SETFONT, (WPARAM)win32Font(), TRUE);
    return w;
  }

  HWND _edit(win32Field *f, HWND parent, bool readOnly)
  {
    HWND e = _make(L"EDIT", WS_TABSTOP | ES_AUTOHSCROLL | (readOnly ? ES_READONLY : 0),
                   parent, WS_EX_CLIENTEDGE);
    SetWindowSubclass(e, _editProc, 1, (DWORD_PTR)f);
    _bind(e, f);
    return e;
  }

  // --- the disc of a direction and the colour map: drawn with GDI

  void _discAt(win32Field *f, HWND w, int px, int py)
  {
    if(!IsWindowEnabled(w)) return;
    RECT r;
    GetClientRect(w, &r);
    double radius = .5 * std::min(r.right, r.bottom) - 3.;
    if(radius <= 0.) return;
    double xx = (px - .5 * r.right) / radius, yy = -(py - .5 * r.bottom) / radius;
    double norm = std::sqrt(xx * xx + yy * yy);
    if(norm > 1.) {
      xx /= norm;
      yy /= norm;
      norm = 1.;
    }
    f->field.setVector(xx, yy, std::sqrt(std::max(0., 1. - norm * norm)));
    InvalidateRect(w, nullptr, TRUE);
    _told(f, false);
  }

  LRESULT CALLBACK _discProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    win32Field *f = _of(w);
    switch(msg) {
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC dc = BeginPaint(w, &ps);
      RECT r;
      GetClientRect(w, &r);
      FillRect(dc, &r, GetSysColorBrush(COLOR_BTNFACE));
      if(f) {
        double x = 0., y = 0., z = 0.;
        f->field.getVector(x, y, z);
        double length = std::sqrt(x * x + y * y + z * z);
        if(length > 0.) {
          x /= length;
          y /= length;
        }
        int side = std::min(r.right, r.bottom);
        double radius = .5 * side - 3., cx = .5 * r.right, cy = .5 * r.bottom;
        HPEN pen = CreatePen(PS_SOLID, 1, GetSysColor(IsWindowEnabled(w) ?
                                                        COLOR_WINDOWTEXT :
                                                        COLOR_GRAYTEXT));
        HGDIOBJ oldPen = SelectObject(dc, pen);
        HGDIOBJ oldBrush = SelectObject(dc, GetStockObject(NULL_BRUSH));
        Ellipse(dc, (int)(cx - radius), (int)(cy - radius), (int)(cx + radius),
                (int)(cy + radius));
        RECT dot = {(LONG)(cx + radius * x - 3), (LONG)(cy - radius * y - 3),
                    (LONG)(cx + radius * x + 3), (LONG)(cy - radius * y + 3)};
        FillRect(dc, &dot, GetSysColorBrush(COLOR_WINDOWTEXT));
        SelectObject(dc, oldBrush);
        SelectObject(dc, oldPen);
        DeleteObject(pen);
      }
      EndPaint(w, &ps);
      return 0;
    }
    case WM_LBUTTONDOWN:
      SetCapture(w);
      if(f) _discAt(f, w, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
      return 0;
    case WM_MOUSEMOVE:
      if(f && (wp & MK_LBUTTON)) _discAt(f, w, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
      return 0;
    case WM_LBUTTONUP:
      ReleaseCapture();
      if(f) _told(f, true);
      return 0;
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

  LRESULT CALLBACK _mapProc(HWND w, UINT msg, WPARAM wp, LPARAM lp)
  {
    win32Field *f = _of(w);
    if(!f) return DefWindowProcW(w, msg, wp, lp);
    const Ui::ColourMap &map = f->field.map;
    int line = (int)(win32Em() * 1.4);
    RECT r;
    GetClientRect(w, &r);
    int wedgeY = r.bottom - 5 - 3 * line;
    switch(msg) {
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC dc = BeginPaint(w, &ps);
      FillRect(dc, &r, GetSysColorBrush(COLOR_WINDOW));
      if(!map.empty() && map.size() >= 2 && wedgeY > 4) {
        int size = map.size();
        bool hsv = map.hsv ? map.hsv() : false;
        COLORREF inks[4] = {RGB(255, 0, 0), RGB(0, 200, 0), RGB(0, 0, 255),
                            GetSysColor(COLOR_WINDOWTEXT)};
        for(int channel = 0; channel < 4; channel++) {
          HPEN pen = CreatePen(PS_SOLID, 1, inks[channel]);
          HGDIOBJ was = SelectObject(dc, pen);
          for(int i = 0; i < size; i++) {
            int x = (int)((double)r.right * i / (size - 1));
            int y = (int)(wedgeY * (1. - Ui::mapChannel(map, i, channel, hsv) / 255.));
            if(i == 0)
              MoveToEx(dc, x, y, nullptr);
            else
              LineTo(dc, x, y);
          }
          SelectObject(dc, was);
          DeleteObject(pen);
        }
        for(int x = 0; x < r.right; x++) {
          Ui::Colour c = map.colour(std::min(size - 1, x * size / std::max(1, (int)r.right)));
          HBRUSH b = CreateSolidBrush(RGB(c.r, c.g, c.b));
          RECT one = {x, wedgeY, x + 1, wedgeY + line};
          FillRect(dc, &one, b);
          DeleteObject(b);
        }
        std::string name;
        double least = 0., most = 0.;
        map.about(name, least, most);
        HGDIOBJ was = SelectObject(dc, win32Font());
        SetBkMode(dc, TRANSPARENT);
        SetTextColor(dc, GetSysColor(COLOR_WINDOWTEXT));
        std::wstring s;
        if(f->mapEdit.help()) {
          // what the keys and the buttons do, as tall as the curves allow
          const auto &keys = Ui::MapEditor::helpLines();
          int step = std::max(1, (wedgeY - 8) / ((int)keys.size() + 1));
          for(std::size_t i = 0; i < keys.size(); i++) {
            int y = 4 + (int)i * step;
            s = win32Wide(keys[i].first);
            TextOutW(dc, 6, y, s.c_str(), (int)s.size());
            s = win32Wide(keys[i].second);
            TextOutW(dc, 6 + win32Px(12.), y, s.c_str(), (int)s.size());
          }
        }
        else {
          s = win32Wide(Ui::MapEditor::title(map));
          TextOutW(dc, 6, 4, s.c_str(), (int)s.size());
        }
        // the marker below the wedge, and the value of the map there
        int size = map.empty() ? 0 : map.size();
        if(size > 1) {
          int mx = (int)(r.right * (double)f->mapEdit.marker() / (size - 1));
          int my = wedgeY + line;
          HPEN pen = CreatePen(PS_SOLID, 1, GetSysColor(COLOR_WINDOWTEXT));
          HGDIOBJ old = SelectObject(dc, pen);
          MoveToEx(dc, mx, my + line * 6 / 10, nullptr);
          LineTo(dc, mx, my);
          LineTo(dc, mx - 3, my + 6);
          MoveToEx(dc, mx, my, nullptr);
          LineTo(dc, mx + 3, my + 6);
          SelectObject(dc, old);
          DeleteObject(pen);
        }
        char said[64];
        s = win32Wide(Ui::MapEditor::markerText(map, f->mapEdit.marker()));
        TextOutW(dc, 10, r.bottom - 5 - line, s.c_str(), (int)s.size());
        snprintf(said, sizeof(said), "%g", most);
        s = win32Wide(said);
        SIZE sz;
        GetTextExtentPoint32W(dc, s.c_str(), (int)s.size(), &sz);
        TextOutW(dc, r.right - 10 - sz.cx, r.bottom - 5 - line, s.c_str(),
                 (int)s.size());
        SelectObject(dc, was);
      }
      EndPaint(w, &ps);
      return 0;
    }
    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
      SetFocus(w);
      SetCapture(w);
      {
        if(map.empty() || r.right < 1) return 0;
        int px = GET_X_LPARAM(lp), py = GET_Y_LPARAM(lp);
        unsigned mods = 0;
        if(wp & MK_CONTROL) mods |= Ui::ModCommand;
        if(wp & MK_SHIFT) mods |= Ui::ModShift;
        if(GetKeyState(VK_MENU) < 0) mods |= Ui::ModAlt;
        Ui::MapEditor::Answer said = f->mapEdit.press(
          map, Ui::MapEditor::entryAt(map, px, r.right),
          Ui::MapEditor::valueAt(py, wedgeY),
          msg == WM_RBUTTONDOWN ? 2 :
          msg == WM_MBUTTONDOWN ? 1 :
                                  0,
          mods, py >= wedgeY);
        InvalidateRect(w, nullptr, FALSE);
        if(said == Ui::MapEditor::Changed) _told(f, false);
        return 0;
      }
    case WM_MOUSEMOVE: {
      if(!f->mapEdit.drawing() || map.empty() || r.right < 1) return 0;
      int px = GET_X_LPARAM(lp), py = GET_Y_LPARAM(lp);
      Ui::MapEditor::Answer said =
        f->mapEdit.drag(map, Ui::MapEditor::entryAt(map, px, r.right),
                        Ui::MapEditor::valueAt(py, wedgeY));
      InvalidateRect(w, nullptr, FALSE);
      if(said == Ui::MapEditor::Changed) _told(f, false);
      return 0;
    }
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
      ReleaseCapture();
      f->mapEdit.release();
      return 0;
    case WM_GETDLGCODE: return DLGC_WANTALLKEYS;
    case WM_KEYDOWN: {
      int key = 0;
      unsigned mods = 0;
      if(map.empty() || !win32UiKey(wp, lp, key, mods)) break;
      Ui::MapEditor::Answer said = f->mapEdit.key(map, key, mods);
      if(said == Ui::MapEditor::NotMine) break;
      InvalidateRect(w, nullptr, FALSE);
      if(said == Ui::MapEditor::Changed) _told(f, true);
      return 0;
    }
    default: break;
    }
    return DefWindowProcW(w, msg, wp, lp);
  }

  const wchar_t *_class(const wchar_t *name, WNDPROC proc)
  {
    WNDCLASSEXW wc;
    if(GetClassInfoExW(GetModuleHandleW(nullptr), name, &wc)) return name;
    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = proc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = name;
    RegisterClassExW(&wc);
    return name;
  }

  // --- a page of prose, as a SysLink: its links are numbered

  void _prose(win32Field *f)
  {
    std::vector<Ui::Line> page =
      f->field.prose ? f->field.prose() : std::vector<Ui::Line>();
    std::string said;
    for(const Ui::Line &l : page) {
      for(const Ui::Words &w : l.words) said += w.text + (w.italic ? "/" : "|");
      said += '\n';
    }
    if(said == f->was) return;
    f->was = said;
    f->follow.clear();
    std::string text;
    for(const Ui::Line &l : page) {
      if(l.bullet) text += "• ";
      for(const Ui::Words &w : l.words) {
        if(w.follow) {
          text += "<a id=\"" + std::to_string(f->follow.size()) + "\">" + w.text +
                  "</a>";
          f->follow.push_back(w.follow);
        }
        else
          text += w.text;
      }
      text += "\n";
    }
    SetWindowTextW(f->widget, win32Wide(text).c_str());
  }

  void _setChoiceItems(HWND combo, const std::vector<std::string> &labels,
                       UINT reset, UINT add)
  {
    SendMessageW(combo, reset, 0, 0);
    for(const auto &l : labels)
      SendMessageW(combo, add, 0, (LPARAM)win32Wide(l).c_str());
  }

} // namespace

// --- making the controls

win32Field *win32MakeField(HWND parent, const Ui::Field &field,
                           const std::function<void()> &after)
{
  win32Field *f = new win32Field;
  f->field = field;
  f->after = after;
  f->parent = parent;
  const Ui::Field &g = field;
  switch(g.kind) {
  case Ui::Text:
    if(g.dynamicChoices) {
      f->widget = _make(L"COMBOBOX", WS_TABSTOP | WS_VSCROLL | CBS_DROPDOWN |
                                       CBS_AUTOHSCROLL,
                        parent);
      _bind(f->widget, f);
      // the edit inside tells Return and the wheel
      COMBOBOXINFO info;
      info.cbSize = sizeof(info);
      if(GetComboBoxInfo(f->widget, &info) && info.hwndItem) {
        SetWindowSubclass(info.hwndItem, _editProc, 1, (DWORD_PTR)f);
        _bind(info.hwndItem, f);
      }
    }
    else
      f->widget = _edit(f, parent, false);
    break;
  case Ui::Integer:
  case Ui::Number:
    if(g.slider && g.maximum > g.minimum) {
      f->number = _edit(f, parent, false);
      f->widget = _make(TRACKBAR_CLASSW, WS_TABSTOP | TBS_HORZ | TBS_NOTICKS,
                        parent);
      SendMessageW(f->widget, TBM_SETRANGE, TRUE, MAKELPARAM(0, 1000));
      _bind(f->widget, f);
    }
    else
      f->widget = _edit(f, parent, false);
    break;
  case Ui::Check:
    f->widget = _make(L"BUTTON", WS_TABSTOP | (g.disclosure ? BS_AUTOCHECKBOX | BS_PUSHLIKE :
                                                              BS_AUTOCHECKBOX),
                      parent, 0, win32Wide(g.label));
    _bind(f->widget, f);
    break;
  case Ui::Choice:
    if(g.multiple) {
      f->widget = _make(L"BUTTON", WS_TABSTOP | BS_PUSHBUTTON, parent, 0,
                        win32Wide(g.label + " ▾"));
      _bind(f->widget, f);
    }
    else {
      f->widget = _make(L"COMBOBOX", WS_TABSTOP | WS_VSCROLL | CBS_DROPDOWNLIST,
                        parent);
      _bind(f->widget, f);
    }
    break;
  case Ui::Label: {
    DWORD align = g.align == Ui::Centre ? SS_CENTER :
                  g.align == Ui::Right  ? SS_RIGHT :
                                          SS_LEFT;
    if(!g.wraps && g.align == Ui::Left) align = SS_LEFTNOWORDWRAP | SS_ENDELLIPSIS;
    f->widget = _make(L"STATIC", align | SS_NOPREFIX, parent);
    if(g.heading) SendMessageW(f->widget, WM_SETFONT, (WPARAM)win32Font(true), TRUE);
    _bind(f->widget, f);
  } break;
  case Ui::Output: f->widget = _edit(f, parent, true); break;
  case Ui::Prose:
    f->widget = _make(WC_LINK, 0, parent);
    _bind(f->widget, f);
    break;
  case Ui::Action:
    f->widget = _make(L"BUTTON", WS_TABSTOP | (g.isDefault ? BS_DEFPUSHBUTTON :
                                                             BS_PUSHBUTTON),
                      parent, 0, win32Wide(g.label));
    _bind(f->widget, f);
    break;
  case Ui::Color:
    f->widget = _make(L"BUTTON", WS_TABSTOP | BS_OWNERDRAW, parent);
    _bind(f->widget, f);
    break;
  case Ui::Direction:
    f->widget = _make(_class(L"GmshDisc", _discProc), 0, parent);
    _bind(f->widget, f);
    break;
  case Ui::ColorMap:
    f->widget = _make(_class(L"GmshMap", _mapProc), WS_TABSTOP, parent,
                      WS_EX_CLIENTEDGE);
    _bind(f->widget, f);
    break;
  case Ui::Hierarchy: {
    Ui::Tree none;
    f->tree = win32MakeTree(parent, g.hierarchy ? *g.hierarchy : none, true,
                            after);
    f->widget = win32TreeWindow(f->tree);
    _bind(f->widget, f);
  } break;
  case Ui::Menu:
    f->widget = _make(L"BUTTON", WS_TABSTOP | BS_PUSHBUTTON, parent, 0,
                      win32Wide(g.label + " ▾"));
    _bind(f->widget, f);
    break;
  case Ui::List:
    f->widget = _make(L"LISTBOX", WS_TABSTOP | WS_VSCROLL | LBS_NOTIFY |
                                    LBS_NOINTEGRALHEIGHT | LBS_USETABSTOPS |
                                    (g.multiple ? LBS_EXTENDEDSEL : 0),
                      parent, WS_EX_CLIENTEDGE);
    if(g.isCode) SendMessageW(f->widget, WM_SETFONT, (WPARAM)win32FixedFont(), TRUE);
    // the columns, in dialog units of a quarter of the average character
    if(g.columnsEm.size()) {
      std::vector<INT> stops;
      double at = 0.;
      for(double em : g.columnsEm) {
        at += em;
        stops.push_back((INT)(at * 8.));
      }
      SendMessageW(f->widget, LB_SETTABSTOPS, stops.size(), (LPARAM)stops.data());
    }
    _bind(f->widget, f);
    break;
  case Ui::Spacer: break;
  }
  // the name, when the widget does not carry its own
  bool named = g.label.size() && g.kind != Ui::Check && g.kind != Ui::Action &&
               g.kind != Ui::Menu && g.kind != Ui::Label &&
               !(g.kind == Ui::Choice && g.multiple);
  if(named) {
    f->label = _make(L"STATIC", SS_NOPREFIX | SS_LEFTNOWORDWRAP |
                                  (g.labelBefore ? SS_RIGHT : 0),
                     parent, 0, win32Wide(g.label));
    _bind(f->label, f);
  }
  for(std::size_t t = 0; t < g.trailing.size(); t++) {
    const Ui::Button &b = g.trailing[t];
    std::string label = b.label.size() ? b.label : b.menu ? "▾" : b.glyph;
    HWND w = _make(L"BUTTON", WS_TABSTOP | BS_PUSHBUTTON, parent, 0,
                   win32Wide(label));
    _bind(w, f);
    SetPropW(w, L"gmshButton", (HANDLE)(INT_PTR)(t + 1));
    f->trailing.push_back(w);
    f->buttons.push_back(b);
  }
  win32RefreshField(f);
  return f;
}

void win32DropField(win32Field *f)
{
  if(!f) return;
  if(f->tree) win32DropTree(f->tree);
  else if(f->widget) DestroyWindow(f->widget);
  if(f->number) DestroyWindow(f->number);
  if(f->label) DestroyWindow(f->label);
  for(HWND w : f->trailing) DestroyWindow(w);
  delete f;
}

HWND win32FieldWindow(win32Field *f) { return f ? f->widget : nullptr; }

void win32PlaceField(win32Field *f, const RECT &widget, const RECT &label,
                     const std::vector<RECT> &trailing, bool shown)
{
  int show = shown ? SW_SHOWNA : SW_HIDE;
  int w = widget.right - widget.left, h = widget.bottom - widget.top;
  if(f->widget) {
    if(f->number) {
      // the number at the left end and the scale beside it
      int n = std::min(w / 2, win32Px(3.6));
      MoveWindow(f->number, widget.left, widget.top, n, h, TRUE);
      MoveWindow(f->widget, widget.left + n + 2, widget.top, w - n - 2, h, TRUE);
      ShowWindow(f->number, show);
    }
    else {
      // a list that drops is as tall as what it drops
      bool combo = f->field.kind == Ui::Choice && !f->field.multiple;
      combo = combo || (f->field.kind == Ui::Text && f->field.dynamicChoices);
      MoveWindow(f->widget, widget.left, widget.top, w, combo ? h + 300 : h, TRUE);
    }
    ShowWindow(f->widget, show);
  }
  if(f->label) {
    if(label.right > label.left) {
      int lh = label.bottom - label.top;
      // written in the middle of its line
      int th = (int)(win32Em() * 1.3);
      MoveWindow(f->label, label.left, label.top + std::max(0, (lh - th) / 2),
                 label.right - label.left, th, TRUE);
      ShowWindow(f->label, show);
    }
    else
      ShowWindow(f->label, SW_HIDE);
  }
  for(std::size_t t = 0; t < f->trailing.size(); t++) {
    if(t < trailing.size()) {
      const RECT &r = trailing[t];
      MoveWindow(f->trailing[t], r.left, r.top, r.right - r.left,
                 r.bottom - r.top, TRUE);
      ShowWindow(f->trailing[t], show);
    }
    else
      ShowWindow(f->trailing[t], SW_HIDE);
  }
}

void win32RebindField(win32Field *f, const Ui::Field &field)
{
  if(!f || f->field.kind != field.kind) return;
  f->field = field;
  if(f->tree && field.hierarchy) win32SetTree(f->tree, *field.hierarchy);
}

void win32RefreshField(win32Field *f)
{
  if(!f) return;
  const Ui::Field &g = f->field;
  f->quiet = true;
  HWND focus = GetFocus();
  switch(g.kind) {
  case Ui::Text:
  case Ui::Output: {
    std::string value = g.getText();
    HWND e = f->widget;
    if(g.kind == Ui::Text && g.dynamicChoices) {
      std::vector<std::string> labels;
      std::vector<int> values;
      g.dynamicChoices(labels, values);
      if(_joined(labels) != f->was) {
        f->was = _joined(labels);
        std::string keep = win32Text(e);
        _setChoiceItems(e, labels, CB_RESETCONTENT, CB_ADDSTRING);
        SetWindowTextW(e, win32Wide(keep).c_str());
      }
    }
    // not while the user is typing in it
    bool typing = g.kind == Ui::Text && (focus == e || GetParent(focus) == e) &&
                  win32Text(e) != f->shown;
    if(!typing) {
      if(win32Text(e) != value) SetWindowTextW(e, win32Wide(value).c_str());
      f->shown = value;
    }
  } break;
  case Ui::Integer:
  case Ui::Number: {
    HWND e = f->number ? f->number : f->widget;
    std::string value = _number(g, g.getNumber());
    bool typing = focus == e && win32Text(e) != f->shown;
    if(!typing) {
      if(win32Text(e) != value) SetWindowTextW(e, win32Wide(value).c_str());
      f->shown = value;
    }
    if(f->number && !f->dragging && g.maximum > g.minimum)
      SendMessageW(f->widget, TBM_SETPOS, TRUE,
                   (LPARAM)std::floor(1000. * (g.getNumber() - g.minimum) /
                                        (g.maximum - g.minimum) +
                                      .5));
  } break;
  case Ui::Check: {
    bool on = g.getFlag();
    SendMessageW(f->widget, BM_SETCHECK, on ? BST_CHECKED : BST_UNCHECKED, 0);
    if(g.disclosure)
      SetWindowTextW(f->widget,
                     win32Wide(g.label + (on ? " ▴" : " ▾")).c_str());
  } break;
  case Ui::Choice: {
    if(g.multiple) break; // its menu is made when it drops
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(g, labels, values);
    if(_joined(labels) != f->was) {
      f->was = _joined(labels);
      _setChoiceItems(f->widget, labels, CB_RESETCONTENT, CB_ADDSTRING);
    }
    f->labels = labels;
    f->values = values;
    int which = -1;
    std::string current = values.empty() ? g.getText() : "";
    for(std::size_t k = 0; k < labels.size(); k++) {
      if(values.empty()) {
        if(labels[k] == current) which = (int)k;
      }
      else if(k < values.size() && values[k] == (int)g.getNumber())
        which = (int)k;
    }
    if(which < 0 && labels.size() && !values.empty()) which = 0;
    if((int)SendMessageW(f->widget, CB_GETCURSEL, 0, 0) != which)
      SendMessageW(f->widget, CB_SETCURSEL, (WPARAM)which, 0);
  } break;
  case Ui::Label: {
    std::string value = g.getText();
    if(value.empty()) value = g.label;
    if(win32Text(f->widget) != value)
      SetWindowTextW(f->widget, win32Wide(value).c_str());
  } break;
  case Ui::Prose: _prose(f); break;
  case Ui::Action: break;
  case Ui::Color:
  case Ui::Direction:
  case Ui::ColorMap: InvalidateRect(f->widget, nullptr, FALSE); break;
  case Ui::Hierarchy:
    if(f->tree) win32RefreshTree(f->tree, false);
    break;
  case Ui::Menu:
    SetWindowTextW(f->widget, win32Wide(g.label + " ▾").c_str());
    break;
  case Ui::List: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(g, labels, values);
    if(_joined(labels) != f->was) {
      f->was = _joined(labels);
      _setChoiceItems(f->widget, labels, LB_RESETCONTENT, LB_ADDSTRING);
    }
    if(g.chosen)
      for(int k = 0; k < (int)labels.size(); k++) {
        bool on = g.chosen(k);
        if(g.multiple)
          SendMessageW(f->widget, LB_SETSEL, on, k);
        else if(on)
          SendMessageW(f->widget, LB_SETCURSEL, k, 0);
      }
  } break;
  case Ui::Spacer: break;
  }
  if(g.enabled) {
    BOOL on = g.enabled() ? TRUE : FALSE;
    if(f->widget) EnableWindow(f->widget, on);
    if(f->number) EnableWindow(f->number, on);
  }
  for(std::size_t t = 0; t < f->buttons.size(); t++)
    if(f->buttons[t].enabled)
      EnableWindow(f->trailing[t], f->buttons[t].enabled());
  f->quiet = false;
}

// --- what the controls tell

bool win32FieldMessage(HWND panel, UINT msg, WPARAM wp, LPARAM lp,
                       LRESULT &result)
{
  result = 0;
  if(msg == WM_DRAWITEM) {
    DRAWITEMSTRUCT *d = (DRAWITEMSTRUCT *)lp;
    win32Field *f = _of(d->hwndItem);
    if(!f || f->field.kind != Ui::Color) return false;
    // the swatch, in a sunken frame
    RECT r = d->rcItem;
    DrawEdge(d->hDC, &r, EDGE_SUNKEN, BF_RECT | BF_ADJUST);
    Ui::Colour c = f->field.getColour();
    HBRUSH b = CreateSolidBrush(RGB(c.r, c.g, c.b));
    FillRect(d->hDC, &r, b);
    DeleteObject(b);
    if(d->itemState & ODS_FOCUS) DrawFocusRect(d->hDC, &r);
    result = TRUE;
    return true;
  }
  if(msg == WM_CTLCOLORSTATIC) {
    win32Field *f = _of((HWND)lp);
    if(!f || !f->field.alert) return false;
    SetTextColor((HDC)wp, RGB(176, 0, 0));
    SetBkMode((HDC)wp, TRANSPARENT);
    result = (LRESULT)GetSysColorBrush(COLOR_BTNFACE);
    return true;
  }
  if(msg == WM_NOTIFY) {
    NMHDR *n = (NMHDR *)lp;
    if(win32Tree *t = (win32Tree *)GetPropW(n->hwndFrom, L"gmshTree"))
      return win32TreeNotify(t, n, result);
    win32Field *f = _of(n->hwndFrom);
    if(!f) return false;
    if(f->tree) return win32TreeNotify(f->tree, n, result);
    if(f->field.kind == Ui::Prose && (n->code == NM_CLICK || n->code == NM_RETURN)) {
      int i = ((NMLINK *)lp)->item.iLink;
      int id = _wtoi(((NMLINK *)lp)->item.szID);
      if(id >= 0 && id < (int)f->follow.size()) win32Later(f->follow[(std::size_t)id]);
      (void)i;
      return true;
    }
    return false;
  }
  if(msg == WM_HSCROLL) {
    win32Field *f = _of((HWND)lp);
    if(!f || !f->number || f->quiet) return false;
    int code = LOWORD(wp);
    int k = (int)SendMessageW(f->widget, TBM_GETPOS, 0, 0);
    const Ui::Field &g = f->field;
    double v = g.minimum + (g.maximum - g.minimum) * k / 1000.;
    if(g.step > 0.) v = g.minimum + std::floor((v - g.minimum) / g.step + .5) * g.step;
    v = Ui::bounded(g, v);
    f->dragging = code == TB_THUMBTRACK;
    f->field.setNumber(v);
    f->shown = _number(g, v);
    f->quiet = true;
    SetWindowTextW(f->number, win32Wide(f->shown).c_str());
    f->quiet = false;
    _told(f, code == TB_ENDTRACK || code == TB_THUMBPOSITION);
    return true;
  }
  if(msg != WM_COMMAND) return false;
  HWND ctl = (HWND)lp;
  win32Field *f = _of(ctl);
  if(!f || f->quiet) return false;
  int code = HIWORD(wp);
  const Ui::Field &g = f->field;
  // a button after the field
  if(INT_PTR t = (INT_PTR)GetPropW(ctl, L"gmshButton")) {
    if(code != BN_CLICKED) return true;
    const Ui::Button &b = f->buttons[(std::size_t)(t - 1)];
    if(b.menu) {
      RECT r;
      GetWindowRect(ctl, &r);
      win32PopupMenu(b.menu(), panel, r.left, r.bottom);
      return true;
    }
    std::function<void()> what = b.action, after = f->after;
    win32Later([what, after]() {
      if(what) what();
      if(after) after();
    });
    return true;
  }
  switch(g.kind) {
  case Ui::Text:
    if(g.dynamicChoices && ctl == f->widget) {
      if(code == CBN_SELCHANGE) {
        int i = (int)SendMessageW(ctl, CB_GETCURSEL, 0, 0);
        int n = (int)SendMessageW(ctl, CB_GETLBTEXTLEN, i, 0);
        if(i >= 0 && n >= 0) {
          std::wstring t(n + 1, L'\0');
          SendMessageW(ctl, CB_GETLBTEXT, i, (LPARAM)&t[0]);
          t.resize(n);
          f->shown = win32Utf8(t);
          f->field.setText(f->shown);
          _told(f, true);
        }
      }
      else if(code == CBN_EDITCHANGE && !g.commitsWhenDone) {
        f->shown = win32Text(ctl);
        f->field.setText(f->shown);
        _told(f, false);
      }
      else if(code == CBN_KILLFOCUS)
        _commit(f, false);
      return true;
    }
    if(code == EN_CHANGE && !g.commitsWhenDone) {
      f->shown = win32Text(ctl);
      f->field.setText(f->shown);
      _told(f, false);
    }
    else if(code == EN_KILLFOCUS && g.commitsWhenDone)
      _commit(f, false);
    return true;
  case Ui::Integer:
  case Ui::Number:
    if(code == EN_KILLFOCUS) _commit(f, true);
    return true;
  case Ui::Check:
    if(code == BN_CLICKED) {
      bool on = SendMessageW(ctl, BM_GETCHECK, 0, 0) == BST_CHECKED;
      f->field.setFlag(on);
      if(g.disclosure)
        SetWindowTextW(ctl, win32Wide(g.label + (on ? " ▴" : " ▾")).c_str());
      _told(f, true);
    }
    return true;
  case Ui::Choice:
    if(g.multiple) {
      if(code != BN_CLICKED) return true;
      // switches in the menu it drops
      std::vector<std::string> labels;
      std::vector<int> values;
      Ui::choices(g, labels, values);
      std::vector<Ui::MenuItem> items;
      std::function<void()> after = f->after;
      for(std::size_t k = 0; k < labels.size(); k++) {
        Ui::MenuItem it;
        it.kind = Ui::MenuItem::Toggle;
        it.label = labels[k];
        int i = (int)k;
        Ui::Field c = g;
        it.checked = [c, i]() { return c.chosen && c.chosen(i); };
        it.action = [c, i, after]() {
          if(c.choose) c.choose(i, !(c.chosen && c.chosen(i)));
          if(c.done)
            c.done();
          else if(c.changed)
            c.changed();
          if(after) after();
        };
        items.push_back(it);
      }
      RECT r;
      GetWindowRect(ctl, &r);
      win32PopupMenu(items, panel, r.left, r.bottom);
      return true;
    }
    if(code == CBN_SELCHANGE) {
      int i = (int)SendMessageW(ctl, CB_GETCURSEL, 0, 0);
      if(i >= 0 && i < (int)f->labels.size()) {
        if(f->values.empty())
          f->field.setText(f->labels[(std::size_t)i]);
        else if(i < (int)f->values.size())
          f->field.setNumber(f->values[(std::size_t)i]);
        _told(f, true);
      }
    }
    return true;
  case Ui::Action:
    if(code == BN_CLICKED) {
      Ui::Field c = g;
      std::function<void()> after = f->after;
      win32Later([c, after]() {
        if(c.changed) c.changed();
        if(after) after();
      });
    }
    return true;
  case Ui::Color:
    if(code == BN_CLICKED) {
      static COLORREF custom[16];
      Ui::Colour was = g.getColour();
      CHOOSECOLORW cc;
      memset(&cc, 0, sizeof(cc));
      cc.lStructSize = sizeof(cc);
      cc.hwndOwner = GetAncestor(ctl, GA_ROOT);
      cc.rgbResult = RGB(was.r, was.g, was.b);
      cc.lpCustColors = custom;
      cc.Flags = CC_RGBINIT | CC_FULLOPEN;
      if(ChooseColorW(&cc)) {
        f->field.setColour(Ui::Colour(GetRValue(cc.rgbResult),
                                      GetGValue(cc.rgbResult),
                                      GetBValue(cc.rgbResult), was.a));
        InvalidateRect(ctl, nullptr, FALSE);
        _told(f, true);
      }
    }
    return true;
  case Ui::Menu:
    if(code == BN_CLICKED) {
      // the list is made when the button is pressed
      std::vector<std::string> labels;
      std::vector<int> values;
      Ui::choices(g, labels, values);
      std::vector<Ui::MenuItem> items;
      std::function<void()> after = f->after;
      for(std::size_t k = 0; k < labels.size(); k++) {
        Ui::MenuItem it;
        it.label = labels[k];
        int i = (int)k;
        Ui::Field c = g;
        it.action = [c, i, after]() {
          if(c.choose) c.choose(i, true);
          if(c.done)
            c.done();
          else if(c.changed)
            c.changed();
          if(after) after();
        };
        items.push_back(it);
      }
      RECT r;
      GetWindowRect(ctl, &r);
      win32PopupMenu(items, panel, r.left, r.bottom);
    }
    return true;
  case Ui::List:
    if(code == LBN_SELCHANGE) {
      int n = (int)SendMessageW(ctl, LB_GETCOUNT, 0, 0);
      if(g.choose) {
        Ui::Field c = g;
        for(int i = 0; i < n; i++)
          c.choose(i, SendMessageW(ctl, LB_GETSEL, i, 0) > 0);
        _told(f, true);
      }
      else if(g.removeItem) {
        // a line one clicks is one to be rid of
        int i = (int)SendMessageW(ctl, LB_GETCURSEL, 0, 0);
        Ui::Field c = g;
        std::function<void()> after = f->after;
        if(i >= 0)
          win32Later([c, i, after]() {
            c.removeItem(i);
            if(c.changed) c.changed();
            if(after) after();
          });
      }
    }
    return true;
  default: return false;
  }
}
