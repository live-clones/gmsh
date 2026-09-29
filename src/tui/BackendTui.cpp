// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <clocale>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fnmatch.h>
#include <mutex>
#include <thread>
#include <unistd.h>

#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/loop.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/terminal.hpp>

#include "tuiCommon.h"

using namespace ftxui;

// The terminal interface: the menu bar along the top, the tree down the left,
// the scene -- pictures drawn off screen, two pixels a cell in half blocks --
// with the console under it, the forms docked down the right as on the page,
// the bar along the bottom. Drawn afresh at every turn of FTXUI's loop, which
// is turned by hand, so that check() and wait() can turn it from inside the
// mesher; what the user does runs between two turns (tuiLater).

// the menu of the bar dropped, and a form put away, from the handlers below
void tuiOpenBarMenu(int i);
void tuiHideForm(const Ui::Form *f);

namespace {

  // --- what the interface keeps from one frame to the next

  struct state {
    Ui::Backend::Sources sources;
    Ui::Backend::Host host;
    std::unique_ptr<App> app;
    std::unique_ptr<Loop> loop;
    Component root;
    bool running = false, inTurn = false;
    std::atomic<int> locked{0};

    std::vector<hotTui> hots, drawn;
    // where the overlays start in the list: what is under them takes nothing
    std::size_t overlayStart = (std::size_t)-1, drawnOverlayStart = (std::size_t)-1;
    std::string focus;
    editTui edit;
    std::vector<std::function<void()> > later;

    // the menus open, the first one dropped from the bar or at a point
    struct popupState {
      std::vector<Ui::MenuItem> items;
      std::vector<std::string> labels;
      std::function<void(int)> picked;
      int x = 0, y = 0, selected = 0;
      bool fromBar = false;
      int barIndex = -1;
    };
    std::vector<popupState> popups;

    // a question that stops everything
    struct question {
      std::string text;
      std::vector<std::string> buttons;
      bool input = false, done = false;
      int answer = -1;
    };
    question *asking = nullptr;

    // the file chooser
    struct chooser {
      bool open = false, done = false, ok = false, create = false;
      std::filesystem::path dir;
      std::vector<Ui::Backend::FileFormat> formats;
      int format = 0;
      std::vector<std::string> entries;
      int selected = -1, scroll = 0;
      std::string title;
    };
    chooser files;

    // the main window
    treeTui tree;
    bool treeShown = true, consoleShown = true, fullscreen = false;
    int treeWidth = 34, consoleHeight = 8;
    std::vector<std::pair<std::string, int> > lines;
    int consoleScroll = 0;
    std::vector<const Ui::Form *> forms;
    std::map<const Ui::Form *, dialogTui> formStates;
    std::string title = "Gmsh";

    // the scene: the box it was given, and the picture shown in it
    std::shared_ptr<Box> sceneBox = std::make_shared<Box>();
    int pictureW = 0, pictureH = 0, askedW = 0, askedH = 0;
    std::vector<unsigned char> picture;
    int pointerButton = -1;
    // what was put on the terminal last, when it is not half blocks: shown
    // again when it changed or moved
    unsigned version = 0, shownVersion = (unsigned)-1;
    Box shownBox;
    bool drew = false, hidden = false;
    int cellW = 1, cellH = 1;
    double lastRefresh = 0., lastPicture = 0.;
    // the pointer moved: only where it went last is told, once a turn
    struct move {
      double x = 0., y = 0.;
      int button = 0;
      bool shift = false, ctrl = false, alt = false;
    };
    move pendingMove;
    bool movePending = false;
  };

  state &_s()
  {
    static state s;
    return s;
  }

  // --- the queue of what runs between two turns

  void _runLater()
  {
    state &s = _s();
    while(!s.later.empty()) {
      std::vector<std::function<void()> > now;
      now.swap(s.later);
      for(auto &w : now)
        if(w) w();
    }
  }

  double _clock()
  {
    return std::chrono::duration<double>(
             std::chrono::steady_clock::now().time_since_epoch())
      .count();
  }

  // a menu, a question or the chooser over the scene: the picture of the
  // terminal is taken away meanwhile, the half blocks show under them
  bool _covered()
  {
    const state &s = _s();
    return !s.popups.empty() || s.asking || s.files.open;
  }

  void _showPicture()
  {
    state &s = _s();
    if(tuiGraphics() == graphicsTui::Blocks || !s.drew) return;
    s.drew = false;
    if(_covered()) {
      if(!s.hidden) tuiHidePicture();
      s.hidden = true;
      return;
    }
    const Box &at = *s.sceneBox;
    if(s.hidden) {
      s.hidden = false;
      // the same picture where it was: placed again, not sent again
      bool same = s.version == s.shownVersion && at.x_min == s.shownBox.x_min &&
                  at.x_max == s.shownBox.x_max && at.y_min == s.shownBox.y_min &&
                  at.y_max == s.shownBox.y_max;
      if(same && tuiPlaceAgain(at.x_min, at.y_min, at.x_max - at.x_min + 1,
                                 at.y_max - at.y_min + 1))
        return;
      s.shownVersion = (unsigned)-1;
    }
    const Box &b = *s.sceneBox;
    bool moved = b.x_min != s.shownBox.x_min || b.x_max != s.shownBox.x_max ||
                 b.y_min != s.shownBox.y_min || b.y_max != s.shownBox.y_max;
    // the frame writes only the cells that changed, never those of the
    // scene: the picture stays until there is another
    if(!moved && s.version == s.shownVersion) return;
    // at most so many pictures a second; the one held back goes at a later
    // turn
    double now = _clock();
    if(!moved && now - s.lastPicture < 1. / 30.) {
      s.drew = true;
      return;
    }
    s.lastPicture = now;
    if(s.picture.size() <= 54) return;
    s.shownBox = b;
    s.shownVersion = s.version;
    tuiShowPicture(&s.picture[0], s.pictureW, s.pictureH, b.x_min, b.y_min,
                     b.x_max - b.x_min + 1, b.y_max - b.y_min + 1);
  }

  // one turn: what arrived, the timers of the scene, what the user asked
  // for; blocking waits until something happened, as long as a frame at
  // most, the scene asking for a new picture being something
  void _turn(bool blocking)
  {
    state &s = _s();
    if(!s.loop || s.inTurn) return;
    for(int k = 0;; k++) {
      s.inTurn = true;
      s.loop->RunOnce();
      s.inTurn = false;
      _showPicture();
      if(s.host.tick) s.host.tick();
      bool acted = !s.later.empty();
      _runLater();
      if(s.host.sceneMoved && s.host.sceneMoved()) tuiDirty();
      // what watches something, and the progress, looked at now and then
      double now = _clock();
      if(now - s.lastRefresh > 1.) {
        s.lastRefresh = now;
        tuiDirty();
      }
      if(!blocking || acted || !s.loop || s.loop->HasQuitted() || k > 30) break;
      std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
  }

} // namespace

// --- what the other file asks

const Ui::Backend::Sources &tuiSources() { return _s().sources; }
const Ui::Backend::Host &tuiHost() { return _s().host; }

void tuiLater(const std::function<void()> &what)
{
  _s().later.push_back(what);
  tuiDirty();
}

void tuiDirty()
{
  if(_s().app) _s().app->PostEvent(Event::Custom);
}

Element tuiHot(Element e, hotTui h)
{
  if(!h.box) h.box = std::make_shared<Box>();
  std::shared_ptr<Box> b = h.box;
  _s().hots.push_back(h);
  return e | reflect(*b);
}

bool tuiFocused(const std::string &id) { return !id.empty() && _s().focus == id; }

void tuiFocus(const std::string &id)
{
  state &s = _s();
  if(s.focus == id) return;
  // the line being typed is written as it is left
  if(s.edit.id.size() && s.edit.id != id) {
    std::function<void(bool)> commit = s.edit.commit;
    s.edit.id.clear();
    s.edit.commit = nullptr;
    if(commit) commit(false);
  }
  s.focus = id;
  tuiDirty();
}

editTui &tuiEdit() { return _s().edit; }

int tuiCells(double em) { return std::max(1, (int)(em * 1.2 + .5)); }

bool tuiEditKey(const Event &e, bool &enter)
{
  editTui &ed = tuiEdit();
  enter = false;
  std::string &t = ed.text;
  ed.cursor = std::min(ed.cursor, t.size());
  if(e == Event::Return) {
    enter = true;
    return true;
  }
  if(e == Event::ArrowLeft) {
    if(ed.cursor) ed.cursor--;
    return true;
  }
  if(e == Event::ArrowRight) {
    if(ed.cursor < t.size()) ed.cursor++;
    return true;
  }
  if(e == Event::Home) {
    ed.cursor = 0;
    return true;
  }
  if(e == Event::End) {
    ed.cursor = t.size();
    return true;
  }
  if(e == Event::Backspace) {
    if(ed.cursor) {
      t.erase(ed.cursor - 1, 1);
      ed.cursor--;
    }
    return true;
  }
  if(e == Event::Delete) {
    if(ed.cursor < t.size()) t.erase(ed.cursor, 1);
    return true;
  }
  if(e.is_character()) {
    std::string c = e.character();
    t.insert(ed.cursor, c);
    ed.cursor += c.size();
    return true;
  }
  return false;
}

bool tuiUiKey(const Event &e, int &key, unsigned &mods)
{
  key = 0;
  mods = 0;
  struct named {
    const Event &e;
    int key;
    unsigned mods;
  };
  static const named keys[] = {
    {Event::ArrowLeft, Ui::KeyLeft, 0},
    {Event::ArrowRight, Ui::KeyRight, 0},
    {Event::ArrowUp, Ui::KeyUp, 0},
    {Event::ArrowDown, Ui::KeyDown, 0},
    {Event::ArrowLeftCtrl, Ui::KeyLeft, Ui::ModCommand},
    {Event::ArrowRightCtrl, Ui::KeyRight, Ui::ModCommand},
    {Event::ArrowUpCtrl, Ui::KeyUp, Ui::ModCommand},
    {Event::ArrowDownCtrl, Ui::KeyDown, Ui::ModCommand},
    {Event::Escape, Ui::KeyEscape, 0},
    {Event::Home, Ui::KeyHome, 0},
    {Event::PageUp, Ui::KeyPageUp, 0},
    {Event::PageDown, Ui::KeyPageDown, 0},
    {Event::Delete, Ui::KeyDelete, 0},
    {Event::Backspace, Ui::KeyDelete, 0},
    {Event::F1, Ui::KeyF1, 0},
    {Event::F2, Ui::KeyF1 + 1, 0},
    {Event::F3, Ui::KeyF1 + 2, 0},
    {Event::F4, Ui::KeyF1 + 3, 0},
    {Event::F5, Ui::KeyF1 + 4, 0},
    {Event::F6, Ui::KeyF1 + 5, 0},
    {Event::F7, Ui::KeyF1 + 6, 0},
    {Event::F8, Ui::KeyF1 + 7, 0},
    {Event::F9, Ui::KeyF1 + 8, 0},
    {Event::F10, Ui::KeyF1 + 9, 0},
    {Event::F11, Ui::KeyF1 + 10, 0},
    {Event::F12, Ui::KeyF1 + 11, 0},
  };
  for(const auto &k : keys)
    if(e == k.e) {
      key = k.key;
      mods = k.mods;
      return true;
    }
  const std::string &in = e.input();
  if(e.is_mouse() || in.empty()) return false;
  std::string c = in;
  // Alt is Escape first
  if(c.size() == 2 && c[0] == 27) {
    mods |= Ui::ModAlt;
    c = c.substr(1);
  }
  if(c.size() != 1) return false;
  unsigned char ch = (unsigned char)c[0];
  if(ch == '\t' || ch == '\r' || ch == '\n') return false;
  if(ch >= 1 && ch <= 26) {
    key = 'A' + ch - 1;
    mods |= Ui::ModCommand;
    return true;
  }
  if(ch >= 'a' && ch <= 'z') {
    key = ch - 'a' + 'A';
    return true;
  }
  if(ch >= 'A' && ch <= 'Z') {
    key = ch;
    mods |= Ui::ModShift;
    return true;
  }
  if(ch > ' ' && ch < 127) {
    key = ch;
    return true;
  }
  return false;
}

void tuiPopupMenu(const std::vector<Ui::MenuItem> &items, int x, int y)
{
  if(items.empty()) return;
  state::popupState p;
  p.items = items;
  p.x = x;
  p.y = y;
  _s().popups.clear();
  _s().popups.push_back(p);
  tuiDirty();
}

void tuiChoose(const std::vector<std::string> &labels, int current, int x,
                 int y, const std::function<void(int)> &picked)
{
  if(labels.empty()) return;
  state::popupState p;
  p.labels = labels;
  p.picked = picked;
  p.selected = std::max(0, current);
  p.x = x;
  p.y = y;
  _s().popups.clear();
  _s().popups.push_back(p);
  tuiDirty();
}

bool tuiAsk(const std::string &question, std::string &value)
{
  state &s = _s();
  if(!s.loop || s.asking) return false;
  state::question q;
  q.text = question;
  q.input = true;
  q.buttons = {"Cancel", "OK"};
  s.asking = &q;
  s.edit.id = "ask";
  s.edit.text = value;
  s.edit.cursor = value.size();
  s.edit.commit = nullptr;
  s.focus = "ask";
  while(!q.done && s.loop && !s.loop->HasQuitted()) _turn(true);
  s.asking = nullptr;
  bool ok = q.answer == 1;
  if(ok) value = s.edit.text;
  s.edit.id.clear();
  s.focus.clear();
  tuiDirty();
  return ok;
}

namespace {

  // --- the scene: a picture, two pixels a cell

  class sceneNode : public Node {
  public:
    void ComputeRequirement() override
    {
      requirement_.min_x = 4;
      requirement_.min_y = 2;
      requirement_.flex_grow_x = requirement_.flex_grow_y = 1;
      requirement_.flex_shrink_x = requirement_.flex_shrink_y = 1;
    }
    void SetBox(Box b) override
    {
      Node::SetBox(b);
      *_s().sceneBox = b;
    }
    void Render(Screen &screen) override
    {
      state &s = _s();
      s.drew = true;
      if(tuiGraphics() != graphicsTui::Blocks && !_covered()) {
        // the picture goes over these, which say nothing
        for(int y = box_.y_min; y <= box_.y_max; y++)
          for(int x = box_.x_min; x <= box_.x_max; x++) {
            Cell &c = screen.CellAt(x, y);
            c.character = " ";
            c.foreground_color = c.background_color = Color::Default;
          }
        return;
      }
      int w = s.pictureW, h = s.pictureH;
      int stride = (w * 3 + 3) & ~3;
      // a pixel of the half blocks is the average of the pixels of the
      // picture it covers, at most four each way
      int cols = box_.x_max - box_.x_min + 1, rows = 2 * (box_.y_max - box_.y_min + 1);
      auto rgb = [&](int x, int y) {
        if(s.picture.empty() || cols < 1 || rows < 1) return Color::RGB(0, 0, 0);
        int sum[3] = {0, 0, 0}, n = 0;
        int i0 = x * w / cols, i1 = std::max(i0 + 1, (x + 1) * w / cols);
        int j0 = y * h / rows, j1 = std::max(j0 + 1, (y + 1) * h / rows);
        int si = std::max(1, (i1 - i0) / 4), sj = std::max(1, (j1 - j0) / 4);
        for(int j = j0; j < j1; j += sj)
          for(int i = i0; i < i1; i += si) {
            if(i < 0 || j < 0 || i >= w || j >= h) continue;
            // the rows go bottom up
            const unsigned char *p =
              &s.picture[54 + (std::size_t)stride * (h - 1 - j) + 3 * i];
            sum[0] += p[2];
            sum[1] += p[1];
            sum[2] += p[0];
            n++;
          }
        if(!n) return Color::RGB(0, 0, 0);
        return Color::RGB((uint8_t)(sum[0] / n), (uint8_t)(sum[1] / n),
                          (uint8_t)(sum[2] / n));
      };
      for(int y = box_.y_min; y <= box_.y_max; y++)
        for(int x = box_.x_min; x <= box_.x_max; x++) {
          Cell &c = screen.CellAt(x, y);
          int px = x - box_.x_min, py = 2 * (y - box_.y_min);
          c.character = "▀";
          c.foreground_color = rgb(px, py);
          c.background_color = rgb(px, py + 1);
        }
    }
  };

  // the picture the scene has for the room there is, read before the frame
  void _fetchPicture()
  {
    state &s = _s();
    const Box &b = *s.sceneBox;
    // at the resolution of the terminal; in half blocks two pixels a cell
    // down, then twice as many each way, averaged
    int cols = b.x_max - b.x_min + 1, rows = b.y_max - b.y_min + 1;
    int w = 2 * cols, h = 4 * rows;
    if(tuiGraphics() != graphicsTui::Blocks) {
      w = cols * s.cellW;
      h = rows * s.cellH;
    }
    if(w < 4 || h < 4) return;
    if(w != s.askedW || h != s.askedH) {
      s.askedW = w;
      s.askedH = h;
      if(s.host.sceneResize) s.host.sceneResize(w, h);
    }
    if(!s.host.sceneImage) return;
    int pw = 0, ph = 0;
    std::string bmp = s.host.sceneImage(pw, ph, s.picture.empty());
    if(bmp.size() > 54) {
      s.picture.assign(bmp.begin(), bmp.end());
      s.pictureW = pw;
      s.pictureH = ph;
      s.version++;
    }
  }

  Element _scene()
  {
    hotTui h;
    h.box = std::make_shared<Box>();
    h.mouse = [](Mouse &m, int x, int y) {
      state &s = _s();
      int button = m.button == Mouse::Left   ? 0 :
                   m.button == Mouse::Right  ? 1 :
                   m.button == Mouse::Middle ? 2 :
                                               -1;
      int what = 0;
      double wheel = 0.;
      if(m.button == Mouse::WheelUp || m.button == Mouse::WheelDown) {
        what = 3;
        wheel = m.button == Mouse::WheelUp ? 1. : -1.;
        button = 0;
      }
      else if(m.motion == Mouse::Pressed && button >= 0) {
        what = 1;
        s.pointerButton = button;
      }
      else if(m.motion == Mouse::Released) {
        what = 2;
        button = s.pointerButton >= 0 ? s.pointerButton : 0;
        s.pointerButton = -1;
      }
      else
        button = std::max(0, s.pointerButton);
      double px = 2. * x + 1., py = 4. * y + 1.;
      if(tuiGraphics() != graphicsTui::Blocks) {
        px = (x + .5) * s.cellW;
        py = (y + .5) * s.cellH;
      }
      bool shift = m.shift, ctrl = m.control, alt = m.meta;
      std::function<void(double, double, int, int, double, bool, bool, bool)>
        pointer = s.host.scenePointer;
      if(!pointer) return true;
      // a move says where the pointer is now: only the last of those that
      // arrive together is told, which is what the scene draws for
      auto tellMove = []() {
        state &s = _s();
        if(!s.movePending) return;
        s.movePending = false;
        const state::move &m = s.pendingMove;
        if(s.host.scenePointer)
          s.host.scenePointer(m.x, m.y, m.button, 0, 0., m.shift, m.ctrl, m.alt);
      };
      if(what == 0) {
        bool queued = s.movePending;
        s.pendingMove.x = px;
        s.pendingMove.y = py;
        s.pendingMove.button = button;
        s.pendingMove.shift = shift;
        s.pendingMove.ctrl = ctrl;
        s.pendingMove.alt = alt;
        s.movePending = true;
        if(!queued) tuiLater(tellMove);
      }
      else
        tuiLater([tellMove, pointer, px, py, button, what, wheel, shift, ctrl,
                    alt]() {
          tellMove();
          pointer(px, py, button, what, wheel, shift, ctrl, alt);
        });
      tuiFocus("");
      return true;
    };
    return tuiHot(std::make_shared<sceneNode>(), h);
  }

  // --- the menus

  std::string _menuLabel(const Ui::MenuItem &it)
  {
    std::string l = it.label;
    if(it.kind == Ui::MenuItem::Toggle)
      l = std::string(it.checked && it.checked() ? "[x] " : "[ ] ") + l;
    else
      l = "    " + l;
    return l;
  }

  int _popupWidth(const state::popupState &p)
  {
    int w = 8;
    if(p.labels.size()) {
      for(const auto &l : p.labels) w = std::max(w, (int)l.size() + 2);
      return w;
    }
    for(const auto &it : p.items) {
      int one = (int)_menuLabel(it).size() + 3;
      std::string sc = it.shortcut.label();
      if(sc.size()) one += (int)sc.size() + 2;
      w = std::max(w, one);
    }
    return w;
  }

  void _openSub(std::size_t level)
  {
    state &s = _s();
    if(level >= s.popups.size()) return;
    state::popupState &p = s.popups[level];
    if(p.selected < 0 || p.selected >= (int)p.items.size()) return;
    const Ui::MenuItem &it = p.items[(std::size_t)p.selected];
    if(it.kind != Ui::MenuItem::Submenu || it.children.empty()) return;
    if(it.enabled && !it.enabled()) return;
    state::popupState sub;
    sub.items = it.children;
    sub.x = p.x + _popupWidth(p) + 1;
    sub.y = p.y + p.selected;
    s.popups.resize(level + 1);
    s.popups.push_back(sub);
  }

  // the entry picked, run once the menus have gone
  void _activate(std::size_t level)
  {
    state &s = _s();
    if(level >= s.popups.size()) return;
    state::popupState &p = s.popups[level];
    if(p.labels.size()) {
      int i = p.selected;
      std::function<void(int)> picked = p.picked;
      s.popups.clear();
      if(picked && i >= 0) tuiLater([picked, i]() { picked(i); });
      return;
    }
    if(p.selected < 0 || p.selected >= (int)p.items.size()) return;
    const Ui::MenuItem &it = p.items[(std::size_t)p.selected];
    if(it.enabled && !it.enabled()) return;
    if(it.kind == Ui::MenuItem::Submenu) {
      _openSub(level);
      return;
    }
    std::function<void()> what = it.action;
    s.popups.clear();
    tuiLater(what);
  }

  Element _popupElement(std::size_t level)
  {
    state &s = _s();
    state::popupState &p = s.popups[level];
    int width = _popupWidth(p);
    Elements rows;
    std::size_t n = p.labels.size() ? p.labels.size() : p.items.size();
    for(std::size_t i = 0; i < n; i++) {
      Element row;
      bool enabled = true;
      if(p.labels.size())
        row = text(" " + p.labels[i]);
      else {
        const Ui::MenuItem &it = p.items[i];
        enabled = it.enabled ? it.enabled() : true;
        std::string sc = it.shortcut.label();
        row = hbox({text(_menuLabel(it)), filler(),
                    text(it.kind == Ui::MenuItem::Submenu ? " ▸" :
                         sc.size()                        ? "  " + sc :
                                                            "") |
                      dim});
      }
      row = row | size(WIDTH, EQUAL, width);
      if((int)i == p.selected) row = row | inverted;
      if(!enabled) row = row | dim;
      hotTui h;
      int k = (int)i;
      h.mouse = [level, k](Mouse &m, int, int) {
        state &s = _s();
        if(level >= s.popups.size()) return true;
        s.popups[level].selected = k;
        if(m.button == Mouse::Left && m.motion == Mouse::Released) _activate(level);
        else if(m.motion == Mouse::Moved || m.motion == Mouse::Pressed) {
          s.popups.resize(level + 1);
          _openSub(level);
        }
        tuiDirty();
        return true;
      };
      rows.push_back(tuiHot(row, h));
      if(p.labels.empty() && p.items[i].dividerAfter && i + 1 < n)
        rows.push_back(separator());
    }
    // at most the height of the terminal, from the one selected
    int room = std::max(3, Terminal::Size().dimy - p.y - 2);
    if((int)rows.size() > room) {
      int from = std::max(0, std::min(p.selected - room / 2, (int)rows.size() - room));
      rows = Elements(rows.begin() + from, rows.begin() + from + room);
    }
    // a background of its own: a picture shown under the cells that have one
    Element box = vbox(rows) | border | clear_under | bgcolor(Color::RGB(40, 40, 40)) |
                  color(Color::White);
    return vbox({text("") | size(HEIGHT, EQUAL, std::max(0, p.y)),
                 hbox({text("") | size(WIDTH, EQUAL, std::max(0, p.x)), box})});
  }

  bool _popupKey(const Event &e)
  {
    state &s = _s();
    if(s.popups.empty()) return false;
    std::size_t level = s.popups.size() - 1;
    state::popupState &p = s.popups[level];
    int n = (int)(p.labels.size() ? p.labels.size() : p.items.size());
    if(e == Event::Escape) {
      s.popups.pop_back();
      return true;
    }
    if(e == Event::ArrowDown) {
      p.selected = (p.selected + 1) % std::max(1, n);
      return true;
    }
    if(e == Event::ArrowUp) {
      p.selected = (p.selected + n - 1) % std::max(1, n);
      return true;
    }
    if(e == Event::ArrowRight) {
      if(p.items.size() && p.selected >= 0 && p.selected < n &&
         p.items[(std::size_t)p.selected].kind == Ui::MenuItem::Submenu) {
        _openSub(level);
        return true;
      }
      // the next menu of the bar
      if(s.popups[0].fromBar) {
        int next = s.popups[0].barIndex + 1;
        tuiOpenBarMenu(next);
      }
      return true;
    }
    if(e == Event::ArrowLeft) {
      if(level > 0) {
        s.popups.pop_back();
        return true;
      }
      if(s.popups[0].fromBar) {
        tuiOpenBarMenu(s.popups[0].barIndex - 1);
      }
      return true;
    }
    if(e == Event::Return || e == Event::Character(' ')) {
      _activate(level);
      return true;
    }
    // the letter an entry starts with
    if(e.is_character() && e.character().size() == 1) {
      char c = (char)std::tolower((unsigned char)e.character()[0]);
      for(int i = 0; i < n; i++) {
        std::string l = p.labels.size() ? p.labels[(std::size_t)i] :
                                          p.items[(std::size_t)i].label;
        if(l.size() && std::tolower((unsigned char)l[0]) == c) {
          p.selected = i;
          _activate(level);
          return true;
        }
      }
    }
    return true;
  }

  // --- the bar of menus

  std::vector<Ui::MenuItem> &_barMenus()
  {
    static std::vector<Ui::MenuItem> menus;
    static unsigned built = 0;
    static bool ever = false;
    const Ui::Backend::Sources &src = _s().sources;
    unsigned generation = src.menuGeneration ? src.menuGeneration() : 0;
    if(src.menuBar && (!ever || generation != built)) {
      ever = true;
      built = generation;
      menus = src.menuBar();
    }
    return menus;
  }

  std::vector<int> _barX;

} // namespace

void tuiOpenBarMenu(int i)
{
  std::vector<Ui::MenuItem> &menus = _barMenus();
  if(menus.empty()) return;
  i = (i + (int)menus.size()) % (int)menus.size();
  state::popupState p;
  p.items = menus[(std::size_t)i].children;
  p.x = i < (int)_barX.size() ? _barX[(std::size_t)i] : 0;
  p.y = 1;
  p.fromBar = true;
  p.barIndex = i;
  _s().popups.clear();
  _s().popups.push_back(p);
  tuiDirty();
}

namespace {

  Element _menuBar()
  {
    std::vector<Ui::MenuItem> &menus = _barMenus();
    Elements row;
    _barX.clear();
    int x = 0;
    for(std::size_t i = 0; i < menus.size(); i++) {
      std::string l = " " + menus[i].label + " ";
      _barX.push_back(x);
      x += (int)l.size();
      Element e = text(l);
      state &s = _s();
      if(s.popups.size() && s.popups[0].fromBar && s.popups[0].barIndex == (int)i)
        e = e | inverted;
      hotTui h;
      int k = (int)i;
      h.mouse = [k](Mouse &m, int, int) {
        state &s = _s();
        bool open = s.popups.size() && s.popups[0].fromBar;
        if(m.button == Mouse::Left && m.motion == Mouse::Pressed) {
          if(open && s.popups[0].barIndex == k)
            s.popups.clear();
          else
            tuiOpenBarMenu(k);
          return true;
        }
        // with a menu open, the one under the pointer drops instead
        if(open && m.motion == Mouse::Moved && s.popups[0].barIndex != k)
          tuiOpenBarMenu(k);
        return open;
      };
      row.push_back(tuiHot(e, h));
    }
    row.push_back(filler());
    row.push_back(text(" " + _s().title + " ") | dim);
    return hbox(row) | bgcolor(Color::GrayDark) | color(Color::White);
  }

  // --- the bar along the bottom

  Element _bar()
  {
    state &s = _s();
    Elements row;
    if(s.sources.barButtons) {
      std::vector<Ui::BarButton> bar = s.sources.barButtons();
      for(std::size_t i = 0; i < bar.size(); i++) {
        const Ui::BarButton &b = bar[i];
        if(b.gapBefore) row.push_back(text(" "));
        bool on = b.on && b.on();
        std::string label = (on && b.labelOn.size()) ? b.labelOn : b.label;
        Element e = text("[" + label + "]");
        if(b.alert && b.alert())
          e = e | bgcolor(Color::Red) | color(Color::White);
        else if(on && b.onColour) {
          Ui::Colour c = b.onColour();
          e = e | bgcolor(Color::RGB(c.r, c.g, c.b)) | color(Color::Black);
        }
        else if(on)
          e = e | bold;
        bool enabled = b.enabled ? b.enabled() : true;
        if(!enabled) {
          row.push_back(e | dim);
          continue;
        }
        hotTui h;
        std::size_t k = i;
        h.mouse = [k](Mouse &m, int, int) {
          if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
          std::vector<Ui::BarButton> now = _s().sources.barButtons();
          if(k >= now.size()) return true;
          if(now[k].menu) {
            tuiPopupMenu(now[k].menu(), m.x, std::max(0, m.y - 12));
            return true;
          }
          std::function<void(bool, bool)> what = now[k].action;
          bool reverse = m.shift, sync = m.control;
          tuiLater([what, reverse, sync]() {
            if(what) what(reverse, sync);
          });
          return true;
        };
        row.push_back(tuiHot(e, h));
      }
    }
    row.push_back(text(" "));
    if(s.sources.barMessage) {
      Ui::BarMessage m = s.sources.barMessage();
      Element say = text(m.text);
      if(m.weight == Ui::MessageError) say = say | color(Color::Red);
      if(m.weight == Ui::MessageWarning) say = say | color(Color::Yellow);
      hotTui h;
      h.mouse = [](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
        if(_s().sources.barPressed) tuiLater(_s().sources.barPressed);
        return true;
      };
      row.push_back(tuiHot(say, h) | flex);
      // the progress of what has finished stays said, at nought or at the end
      if(m.running && m.fraction > 0. && m.fraction < 1.)
        row.push_back(gauge((float)m.fraction) | size(WIDTH, EQUAL, 20));
    }
    return hbox(row);
  }

  // --- the console

  Element _console(int height)
  {
    state &s = _s();
    Elements rows;
    int n = (int)s.lines.size();
    s.consoleScroll = std::max(0, std::min(s.consoleScroll, n - height));
    int last = n - s.consoleScroll;
    for(int i = std::max(0, last - height); i < last; i++) {
      Element e = text(s.lines[(std::size_t)i].first);
      switch(s.lines[(std::size_t)i].second) {
      case Ui::Backend::Direct: e = e | color(Color::Cyan); break;
      case Ui::Backend::Warning: e = e | color(Color::Yellow); break;
      case Ui::Backend::Error: e = e | color(Color::Red); break;
      case Ui::Backend::Debug: e = e | dim; break;
      default: break;
      }
      rows.push_back(e);
    }
    hotTui h;
    h.mouse = [](Mouse &m, int, int) {
      if(m.button != Mouse::WheelUp && m.button != Mouse::WheelDown) return false;
      _s().consoleScroll += m.button == Mouse::WheelUp ? 3 : -3;
      if(_s().consoleScroll < 0) _s().consoleScroll = 0;
      tuiDirty();
      return true;
    };
    return tuiHot(vbox(rows) | size(HEIGHT, EQUAL, height), h);
  }

  // --- the forms, docked down the right as on the page

  Element _dock()
  {
    state &s = _s();
    Elements cards;
    for(const Ui::Form *f : s.forms) {
      hotTui h;
      h.mouse = [f](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
        tuiLater([f]() { tuiHideForm(f); });
        return true;
      };
      Element head = hbox({text(" " + f->title + " ") | bold, filler(),
                           tuiHot(text("[x]"), h)});
      cards.push_back(window(head, tuiForm(*f, s.formStates[f])));
    }
    if(cards.empty()) return text("");
    return vbox(cards) | size(WIDTH, LESS_THAN, 90);
  }

  // --- the questions and the file chooser, over everything

  Element _question()
  {
    state &s = _s();
    state::question &q = *s.asking;
    Elements body;
    body.push_back(paragraph(q.text) | size(WIDTH, LESS_THAN, 70));
    if(q.input) {
      editTui &ed = s.edit;
      std::string t = ed.text;
      std::size_t c = std::min(ed.cursor, t.size());
      body.push_back(hbox({text(t.substr(0, c)),
                           text(c < t.size() ? t.substr(c, 1) : " ") | inverted,
                           text(c < t.size() ? t.substr(c + 1) : ""), filler()}) |
                     bgcolor(Color::Blue) | color(Color::White) |
                     size(WIDTH, GREATER_THAN, 40));
    }
    Elements row;
    row.push_back(filler());
    for(std::size_t i = 0; i < q.buttons.size(); i++) {
      if(q.buttons[i].empty()) continue;
      Element b = text("[" + q.buttons[i] + "]");
      // Return presses the second, or the only one, as fl_choice() has it
      bool preferred = (int)i == (q.buttons.size() > 1 && q.buttons[1].size() ? 1 : 0);
      if(preferred) b = b | bold | inverted;
      hotTui h;
      int k = (int)i;
      h.mouse = [k](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Released) return false;
        state &s = _s();
        if(s.asking) {
          s.asking->answer = k;
          s.asking->done = true;
        }
        return true;
      };
      row.push_back(text(" "));
      row.push_back(tuiHot(b, h));
    }
    body.push_back(hbox(row));
    return window(text(" Gmsh "), vbox(body)) | clear_under |
           bgcolor(Color::RGB(40, 40, 40)) | color(Color::White) | center;
  }

  bool _questionKey(const Event &e)
  {
    state &s = _s();
    state::question &q = *s.asking;
    if(e == Event::Escape) {
      q.answer = q.input ? 0 : 0;
      q.done = true;
      return true;
    }
    if(e == Event::Return) {
      q.answer = q.buttons.size() > 1 && q.buttons[1].size() ? 1 : 0;
      q.done = true;
      return true;
    }
    bool enter = false;
    if(q.input) tuiEditKey(e, enter);
    return true;
  }

  void _listFiles()
  {
    state::chooser &f = _s().files;
    f.entries.clear();
    std::vector<std::string> dirs, files;
    std::vector<std::string> patterns;
    if(f.format >= 0 && f.format < (int)f.formats.size())
      patterns = f.formats[(std::size_t)f.format].patterns();
    std::error_code ec;
    for(const auto &e : std::filesystem::directory_iterator(f.dir, ec)) {
      std::string name = e.path().filename().string();
      if(name.size() && name[0] == '.') continue;
      if(e.is_directory(ec)) {
        dirs.push_back(name + "/");
        continue;
      }
      bool match = patterns.empty();
      for(const auto &p : patterns)
        if(!fnmatch(p.c_str(), name.c_str(), 0)) match = true;
      if(match) files.push_back(name);
    }
    std::sort(dirs.begin(), dirs.end());
    std::sort(files.begin(), files.end());
    f.entries.push_back("../");
    for(auto &d : dirs) f.entries.push_back(d);
    for(auto &n : files) f.entries.push_back(n);
    f.selected = -1;
    f.scroll = 0;
  }

  // the entry, into the name or into the folder it is
  void _pickEntry(int i, bool accept)
  {
    state &s = _s();
    state::chooser &f = s.files;
    if(i < 0 || i >= (int)f.entries.size()) return;
    std::string e = f.entries[(std::size_t)i];
    if(e.size() && e.back() == '/') {
      f.dir = std::filesystem::weakly_canonical(f.dir / e.substr(0, e.size() - 1));
      _listFiles();
      return;
    }
    f.selected = i;
    s.edit.text = e;
    s.edit.cursor = e.size();
    if(accept) {
      f.ok = true;
      f.done = true;
    }
  }

  Element _chooser()
  {
    state &s = _s();
    state::chooser &f = s.files;
    int rows = std::max(5, Terminal::Size().dimy - 12);
    Elements list;
    f.scroll = std::max(0, std::min(f.scroll, (int)f.entries.size() - rows));
    for(int i = f.scroll; i < (int)f.entries.size() && i < f.scroll + rows; i++) {
      Element e = text(" " + f.entries[(std::size_t)i] + " ");
      if(f.entries[(std::size_t)i].back() == '/') e = e | bold;
      if(i == f.selected) e = e | inverted;
      hotTui h;
      h.mouse = [i](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
        bool again = _s().files.selected == i;
        _pickEntry(i, again);
        tuiDirty();
        return true;
      };
      list.push_back(tuiHot(e, h));
    }
    while((int)list.size() < rows) list.push_back(text(""));
    hotTui wheel;
    wheel.mouse = [](Mouse &m, int, int) {
      if(m.button != Mouse::WheelUp && m.button != Mouse::WheelDown) return false;
      _s().files.scroll += m.button == Mouse::WheelUp ? -3 : 3;
      tuiDirty();
      return true;
    };
    editTui &ed = s.edit;
    std::string t = ed.text;
    std::size_t c = std::min(ed.cursor, t.size());
    Element name = hbox({text(t.substr(0, c)),
                         text(c < t.size() ? t.substr(c, 1) : " ") | inverted,
                         text(c < t.size() ? t.substr(c + 1) : ""), filler()}) |
                   bgcolor(Color::Blue) | color(Color::White);
    std::string format =
      f.format >= 0 && f.format < (int)f.formats.size() ?
        (f.formats[(std::size_t)f.format].name.size() ?
           f.formats[(std::size_t)f.format].name + " (" +
             f.formats[(std::size_t)f.format].pattern + ")" :
           f.formats[(std::size_t)f.format].pattern) :
        "*";
    hotTui formats;
    formats.mouse = [](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      state::chooser &f = _s().files;
      std::vector<std::string> labels;
      for(const auto &one : f.formats)
        labels.push_back(one.name.size() ? one.name + " (" + one.pattern + ")" :
                                           one.pattern);
      tuiChoose(labels, f.format, m.x, m.y + 1, [](int i) {
        _s().files.format = i;
        _listFiles();
      });
      return true;
    };
    auto answer = [](bool ok) {
      return [ok](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Released) return false;
        _s().files.ok = ok;
        _s().files.done = true;
        return true;
      };
    };
    hotTui cancel, accept;
    cancel.mouse = answer(false);
    accept.mouse = answer(true);
    Element body = vbox({
      text(f.dir.string()) | dim,
      tuiHot(vbox(list) | border, wheel),
      hbox({text("Name:   "), name | flex}),
      hbox({text("Format: "), tuiHot(text(format + " ▾"), formats), filler()}),
      hbox({filler(), tuiHot(text("[Cancel]"), cancel), text(" "),
            tuiHot(text(f.create ? "[Save]" : "[Open]") | bold | inverted, accept)}),
    });
    return window(text(" " + f.title + " "), body) |
           size(WIDTH, EQUAL, std::min(90, Terminal::Size().dimx - 4)) |
           clear_under | bgcolor(Color::RGB(40, 40, 40)) | color(Color::White) |
           center;
  }

  bool _chooserKey(const Event &e)
  {
    state &s = _s();
    state::chooser &f = s.files;
    if(e == Event::Escape) {
      f.ok = false;
      f.done = true;
      return true;
    }
    if(e == Event::ArrowDown || e == Event::ArrowUp) {
      int n = (int)f.entries.size();
      f.selected = std::max(0, std::min(n - 1, f.selected + (e == Event::ArrowDown ? 1 : -1)));
      int rows = std::max(5, Terminal::Size().dimy - 12);
      if(f.selected < f.scroll) f.scroll = f.selected;
      if(f.selected >= f.scroll + rows) f.scroll = f.selected - rows + 1;
      std::string en = f.entries[(std::size_t)f.selected];
      if(en.back() != '/') {
        s.edit.text = en;
        s.edit.cursor = en.size();
      }
      return true;
    }
    if(e == Event::Return) {
      std::string typed = s.edit.text;
      // a folder typed or picked is gone into
      std::filesystem::path p = f.dir / typed;
      std::error_code ec;
      if(typed.empty() && f.selected >= 0) {
        _pickEntry(f.selected, true);
        return true;
      }
      if(std::filesystem::is_directory(p, ec)) {
        f.dir = std::filesystem::weakly_canonical(p);
        s.edit.text.clear();
        s.edit.cursor = 0;
        _listFiles();
        return true;
      }
      f.ok = !typed.empty();
      f.done = true;
      return true;
    }
    bool enter = false;
    tuiEditKey(e, enter);
    return true;
  }

  // --- the whole of it

  Element _frame()
  {
    state &s = _s();
    s.hots.clear();
    s.overlayStart = (std::size_t)-1;
    _fetchPicture();
    Dimensions term = Terminal::Size();
    int consoleHeight = s.consoleShown ? s.consoleHeight : 0;
    Element main;
    if(s.fullscreen)
      main = _scene();
    else {
      Elements side;
      if(s.treeShown) {
        int treeHeight = std::max(3, term.dimy - 4);
        Elements footer;
        if(s.sources.tree.footer)
          for(const auto &b : s.sources.tree.footer()) {
            footer.push_back(tuiButtonWidget(b, "footer." + b.label, nullptr));
            footer.push_back(text(" "));
          }
        Element t = tuiTree(s.sources.tree, s.tree, false, "tree",
                              treeHeight - (footer.empty() ? 0 : 1), []() {
                                tuiDirty();
                              });
        side.push_back(vbox({t | flex, hbox(footer)}) |
                       size(WIDTH, EQUAL, s.treeWidth));
        side.push_back(separator());
      }
      Elements middle;
      middle.push_back(_scene() | flex);
      if(consoleHeight) {
        middle.push_back(separator());
        middle.push_back(_console(consoleHeight));
      }
      side.push_back(vbox(middle) | flex);
      Element dock = _dock();
      side.push_back(dock);
      main = vbox({_menuBar(), hbox(side) | flex, _bar()});
    }
    Elements layers = {main};
    s.overlayStart = s.hots.size();
    for(std::size_t i = 0; i < s.popups.size(); i++)
      layers.push_back(_popupElement(i));
    if(s.files.open) layers.push_back(_chooser());
    if(s.asking) layers.push_back(_question());
    if(!s.asking && !s.files.open && s.popups.empty())
      s.overlayStart = (std::size_t)-1;
    s.drawn = s.hots;
    s.drawnOverlayStart = s.overlayStart;
    return dbox(layers);
  }

  // --- what the user does

  bool _mouse(Mouse m)
  {
    state &s = _s();
    // the smallest of what is under the pointer takes it first; over an
    // overlay, only what the overlay holds
    std::vector<std::size_t> under;
    std::size_t from = s.drawnOverlayStart == (std::size_t)-1 ? 0 : s.drawnOverlayStart;
    for(std::size_t i = from; i < s.drawn.size(); i++)
      if(s.drawn[i].box && s.drawn[i].box->Contain(m.x, m.y)) under.push_back(i);
    std::sort(under.begin(), under.end(), [&s](std::size_t a, std::size_t b) {
      const Box &x = *s.drawn[a].box, &y = *s.drawn[b].box;
      long ax = (long)(x.x_max - x.x_min + 1) * (x.y_max - x.y_min + 1);
      long ay = (long)(y.x_max - y.x_min + 1) * (y.y_max - y.y_min + 1);
      if(ax != ay) return ax < ay;
      return a > b;
    });
    for(std::size_t i : under) {
      hotTui h = s.drawn[i];
      if(h.mouse && h.mouse(m, m.x - h.box->x_min, m.y - h.box->y_min)) {
        if(h.id.size() && m.motion == Mouse::Pressed) tuiFocus(h.id);
        return true;
      }
    }
    // a press outside the menus closes them
    if(m.motion == Mouse::Pressed && s.popups.size() && !s.asking && !s.files.open) {
      s.popups.clear();
      return true;
    }
    return false;
  }

  bool _event(Event e)
  {
    state &s = _s();
    if(e == Event::Custom) return false;
    if(e.is_mouse()) return _mouse(e.mouse());
    if(s.popups.size()) return _popupKey(e);
    if(s.asking) return _questionKey(e);
    if(s.files.open) return _chooserKey(e);
    // the one focused first
    for(const auto &h : s.drawn)
      if(h.id.size() && h.id == s.focus && h.key) {
        if(h.key(e)) {
          tuiDirty();
          return true;
        }
        break;
      }
    if(e == Event::Tab || e == Event::TabReverse) {
      std::vector<std::string> ids;
      for(const auto &h : s.drawn)
        if(h.id.size() && h.key) ids.push_back(h.id);
      if(ids.empty()) return true;
      auto at = std::find(ids.begin(), ids.end(), s.focus);
      std::size_t i = at == ids.end() ? 0 : (std::size_t)(at - ids.begin());
      if(at != ids.end())
        i = e == Event::Tab ? (i + 1) % ids.size() : (i + ids.size() - 1) % ids.size();
      tuiFocus(ids[i]);
      return true;
    }
    if(e == Event::Escape && s.focus.size()) {
      tuiFocus("");
      return true;
    }
    if(e == Event::Escape && s.fullscreen) {
      s.fullscreen = false;
      return true;
    }
    if(e == Event::F10) {
      tuiOpenBarMenu(0);
      return true;
    }
    int key = 0;
    unsigned mods = 0;
    if(!tuiUiKey(e, key, mods)) return false;
    // Alt and a letter drops the menu of the bar it marks
    if(mods == Ui::ModAlt && key >= 'A' && key <= 'Z') {
      std::vector<Ui::MenuItem> &menus = _barMenus();
      for(std::size_t i = 0; i < menus.size(); i++)
        if(menus[i].mnemonic &&
           std::toupper((unsigned char)menus[i].mnemonic) == key) {
          tuiOpenBarMenu((int)i);
          return true;
        }
    }
    if(!s.sources.keys) return false;
    bool taken = false;
    for(const Ui::KeyBinding &k : s.sources.keys()) {
      if(!k.shortcut.matches(key, mods)) continue;
      taken = true;
      if(k.action) tuiLater(k.action);
      if(k.spent) break;
    }
    return taken;
  }

  // the terminal back as it was, however Gmsh leaves
  void _restoreTerminal()
  {
    state &s = _s();
    if(s.loop) tuiClearPictures();
    s.loop.reset();
  }

} // namespace

void tuiHideForm(const Ui::Form *f)
{
  state &s = _s();
  auto it = std::find(s.forms.begin(), s.forms.end(), f);
  if(it == s.forms.end()) return;
  s.forms.erase(it);
  // closing a dialog undoes what it leaves behind
  if(f->closed) f->closed();
  if(s.host.formWasClosed) s.host.formWasClosed(*f);
  tuiDirty();
}

namespace {

  class backendTui : public Ui::Backend {
  public:
    std::string name() override { return "FTXUI 7.0.3 (terminal)"; }
    bool showsScene() override { return true; }

    void setSources(const Sources &sources) override { _s().sources = sources; }
    void setHost(const Host &host) override { _s().host = host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      state &s = _s();
      if(s.loop) return true;
      if(!isatty(0) || !isatty(1)) {
        if(s.host.error) s.host.error("The terminal interface needs a terminal");
        return false;
      }
      s.app.reset(new App(App::FullscreenAlternateScreen()));
      s.app->TrackMouse(true);
      s.root = Renderer([]() { return _frame(); }) | CatchEvent(_event);
      s.loop.reset(new Loop(s.app.get(), s.root));
      // the numbers are read and written the C way, whatever FTXUI set
      setlocale(LC_NUMERIC, "C");
      std::atexit(_restoreTerminal);
      // the text of the scene as big as it can be read
      if(tuiGraphics() != graphicsTui::Blocks && tuiCellPixels(s.cellW, s.cellH))
        tuiSceneScale(1.f, Terminal::Size().dimy * s.cellH);
      else
        tuiSceneScale(.6f, 700);
      const Settings set = s.sources.settings();
      s.treeShown = set.showModuleMenu;
      return true;
    }

    void destroy() override
    {
      state &s = _s();
      s.running = false;
      _restoreTerminal();
      s.app.reset();
      s.forms.clear();
    }

    int runLoop() override
    {
      state &s = _s();
      s.running = true;
      while(s.running && s.loop && !s.loop->HasQuitted()) _turn(true);
      if(s.loop && s.loop->HasQuitted() && s.host.quitting) s.host.quitting();
      return 0;
    }

    void check(bool rateLimited) override
    {
      state &s = _s();
      if(!s.loop || s.locked > 0 || s.inTurn) return;
      _turn(false);
    }

    bool ready() override { return _s().loop != nullptr; }

    void wait(double seconds, bool force) override
    {
      state &s = _s();
      if(!s.loop || s.inTurn) return;
      if(!force && s.locked > 0) return;
      // a turn waits a frame at most
      _turn(seconds != 0.);
    }

    void lock() override { _s().locked++; }
    void unlock() override { _s().locked--; }
    int locked() override { return _s().locked; }

    void post(const std::function<void()> &what) override { tuiLater(what); }

    void postFromThread(const std::function<void()> &what) override
    {
      if(!_s().app) return;
      std::function<void()> w = what;
      _s().app->Post([w]() { tuiLater(w); });
    }

    void copyText(const std::string &text) override {}
    void beep() override {}

    void addMessage(const std::string &text, int level) override
    {
      state &s = _s();
      // a message of several lines is several lines of the console
      std::size_t at = 0;
      while(at <= text.size()) {
        std::size_t nl = text.find('\n', at);
        s.lines.push_back(std::make_pair(
          text.substr(at, nl == std::string::npos ? std::string::npos : nl - at),
          level));
        if(nl == std::string::npos) break;
        at = nl + 1;
      }
      if(s.lines.size() > 20000) s.lines.erase(s.lines.begin(), s.lines.begin() + 5000);
      tuiDirty();
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      lines.clear();
      for(const auto &l : _s().lines) lines.push_back(l.first);
    }

    void refreshBar() override { tuiDirty(); }
    void refreshMenus() override { tuiDirty(); }
    void setWindowTitle(int which, const std::string &title) override
    {
      if(which == 0) _s().title = title;
      tuiDirty();
    }

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      std::string q = question + (hint.size() ? "\n" + hint : "");
      if(readOnly) {
        questionDialog(q + "\n\n" + value, "Close", "", "");
        return false;
      }
      return tuiAsk(q, value);
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      state &s = _s();
      if(!s.loop || s.asking) return 0;
      state::question q;
      q.text = question;
      q.buttons = {zero, one, two};
      s.asking = &q;
      while(!q.done && s.loop && !s.loop->HasQuitted()) _turn(true);
      s.asking = nullptr;
      tuiDirty();
      return q.answer < 0 ? 0 : q.answer;
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      state &s = _s();
      if(!s.loop || s.files.open) return false;
      state::chooser &f = s.files;
      f = state::chooser();
      f.open = true;
      f.create = mode == Create;
      f.title = title;
      f.formats = formats;
      std::error_code ec;
      std::string from = names.empty() ? "" : names[0];
      std::filesystem::path p = from.size() ? std::filesystem::path(from) :
                                              std::filesystem::current_path(ec);
      if(std::filesystem::is_directory(p, ec)) {
        f.dir = p;
        s.edit.text.clear();
      }
      else {
        f.dir = p.has_parent_path() ? p.parent_path() :
                                      std::filesystem::current_path(ec);
        s.edit.text = p.filename().string();
      }
      f.dir = std::filesystem::weakly_canonical(f.dir, ec);
      s.edit.id = "files";
      s.edit.cursor = s.edit.text.size();
      s.edit.commit = nullptr;
      _listFiles();
      while(!f.done && s.loop && !s.loop->HasQuitted()) _turn(true);
      f.open = false;
      std::string name = s.edit.text;
      s.edit.id.clear();
      tuiDirty();
      if(!f.ok || name.empty()) return false;
      std::filesystem::path chosen = std::filesystem::path(name).is_absolute() ?
                                       std::filesystem::path(name) :
                                       f.dir / name;
      names.assign(1, chosen.string());
      if(chosenFormat) *chosenFormat = f.format;
      return true;
    }

    void showForm(const Ui::Form &form, bool show) override
    {
      state &s = _s();
      auto it = std::find(s.forms.begin(), s.forms.end(), &form);
      if(show) {
        // the one asked for last is on top
        if(it != s.forms.end()) s.forms.erase(it);
        s.forms.insert(s.forms.begin(), &form);
      }
      else if(it != s.forms.end())
        tuiHideForm(&form);
      tuiDirty();
    }

    bool formVisible(const Ui::Form &form) override
    {
      const auto &f = _s().forms;
      return std::find(f.begin(), f.end(), &form) != f.end();
    }

    std::string formPane(const Ui::Form &form) override
    {
      return _s().formStates[&form].pane;
    }

    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      _s().formStates[&form].pane = pane;
      tuiDirty();
    }

    void dropForm(const Ui::Form &form) override
    {
      state &s = _s();
      auto it = std::find(s.forms.begin(), s.forms.end(), &form);
      if(it != s.forms.end()) s.forms.erase(it);
      s.formStates.erase(&form);
    }

    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &) override
    {
      const Box &b = *_s().sceneBox;
      tuiPopupMenu(items, (b.x_min + b.x_max) / 2, (b.y_min + b.y_max) / 2);
    }

    void refreshTree(bool rebuild) override
    {
      if(rebuild) _s().tree.open.erase(std::string());
      tuiDirty();
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      state &s = _s();
      // the branches on the way are opened first
      if(open) {
        std::size_t at = 0;
        while((at = name.find('/', at + 1)) != std::string::npos)
          s.tree.open[name.substr(0, at)] = true;
      }
      s.tree.open[name] = open;
      tuiDirty();
    }

    bool treeItemOpen(const std::string &name) override
    {
      auto it = _s().tree.open.find(name);
      return it != _s().tree.open.end() && it->second;
    }

    void showTree() override
    {
      _s().treeShown = true;
      tuiDirty();
    }

    void setSolverButtonMode(const std::string &, const std::string &) override
    {
      tuiDirty();
    }

    void showConsole(bool show) override
    {
      _s().consoleShown = show;
      tuiDirty();
    }

    bool consoleVisible() override { return _s().consoleShown; }

    void windowAction(const std::string &what) override
    {
      state &s = _s();
      if(what == "fullscreen")
        s.fullscreen = !s.fullscreen;
      else if(what == "show_hide_tree")
        s.treeShown = !s.treeShown;
      tuiDirty();
    }

    bool supports(const std::string &what) override
    {
      // one terminal, one view, no clipboard
      return what == "fullscreen";
    }
  };

  backendTui *_the = nullptr;

  struct offeringTui {
    offeringTui()
    {
      Ui::offer("tui", []() -> Ui::Backend * {
        if(!_the) _the = new backendTui();
        return _the;
      });
    }
  };
  offeringTui _offeringTui;

} // namespace
