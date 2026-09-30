// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The widget of a field, made afresh at every frame from its description,
// for the forms and for the lines of the tree.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include "tuiCommon.h"
#include "Glyph.h"
#include "Layout.h" // Ui::fills()
#include "MapEditor.h"

using namespace ftxui;

namespace {

  // what is typed over, the text shown by a field of that width
  std::string _fit(const std::string &s, int width)
  {
    if(width <= 0) return s;
    // counted in bytes: what Gmsh says is mostly ASCII
    if((int)s.size() > width) return s.substr(0, std::max(0, width - 1)) + "…";
    return s + std::string(width - s.size(), ' ');
  }

  // what warns is written in red
  Decorator _valueStyle(bool on, bool alert = false)
  {
    Color ink = alert ? Color::RedLight : Color::White;
    return on ? (bgcolor(Color::Blue) | color(ink)) :
                (bgcolor(Color::GrayDark) | color(ink));
  }

  // --- numbers

  // with the decimals of its step when values are dragged
  std::string _number(const Ui::Field &f, double v)
  {
    return Ui::numberText(v, tuiSources().settings().inputScrolling ? f.step : 0.);
  }

  // a change the user made: the done() of a choosing that ended, the
  // changed() of a step, then what the holder does
  void _told(const Ui::Field &f, bool ends, const std::function<void()> &after)
  {
    Ui::Field g = f;
    tuiLater([g, ends, after]() {
      if(g.done && ends)
        g.done();
      else if(g.changed)
        g.changed();
      if(after) after();
    });
  }

  // --- a line one types in: the text of the field, or what is being typed

  Element _line(const Ui::Field &f, const std::string &id, int width,
                const std::function<void()> &after, bool editable)
  {
    bool number = f.kind == Ui::Integer || f.kind == Ui::Number;
    std::string value = number ? _number(f, f.getNumber()) : f.getText();
    bool on = tuiFocused(id);
    editTui &ed = tuiEdit();
    Element shown;
    if(on && editable && ed.id == id) {
      // the cursor as a block over the character it is on
      std::string t = ed.text;
      std::size_t c = std::min(ed.cursor, t.size());
      std::string head = t.substr(0, c), at = c < t.size() ? t.substr(c, 1) : " ",
                  tail = c < t.size() ? t.substr(c + 1) : "";
      int w = width > 0 ? width : (int)t.size() + 1;
      int left = std::max(0, w - (int)head.size() - 1 - (int)tail.size());
      shown = hbox({text(head), text(at) | inverted, text(tail),
                    text(std::string(left, ' '))}) |
              size(WIDTH, EQUAL, w) | _valueStyle(true, f.alert);
    }
    else
      shown = text(_fit(value, width > 0 ? width : (int)value.size())) |
              _valueStyle(on, f.alert);
    if(!editable) return shown | dim;
    Ui::Field g = f;
    hotTui h;
    h.id = id;
    auto begin = [g, id, number, after]() {
      editTui &e = tuiEdit();
      if(e.id == id) return;
      e.id = id;
      e.text = number ? _number(g, g.getNumber()) : g.getText();
      e.cursor = e.text.size();
      std::string was = e.text;
      e.commit = [g, number, after, was](bool enter) {
        std::string now = tuiEdit().text;
        if(now == was && !enter) return;
        if(number) {
          double v = 0.;
          if(!Ui::readNumber(now, v)) return;
          const_cast<Ui::Field &>(g).setNumber(Ui::bounded(g, v));
        }
        else if(now != was || !g.commitsWhenDone)
          const_cast<Ui::Field &>(g).setText(now);
        _told(g, true, after);
      };
    };
    h.mouse = [begin, g, id, number, after](Mouse &m, int, int) {
      if(m.button == Mouse::Left && m.motion == Mouse::Pressed) {
        tuiFocus(id);
        begin();
        return true;
      }
      // the wheel steps a number that has a step
      if(number && g.step > 0. && tuiSources().settings().inputScrolling &&
         (m.button == Mouse::WheelUp || m.button == Mouse::WheelDown)) {
        double v = Ui::bounded(g, g.getNumber() + (m.button == Mouse::WheelUp ?
                                                  g.step : -g.step));
        const_cast<Ui::Field &>(g).setNumber(v);
        tuiEdit().id.clear();
        _told(g, false, after);
        return true;
      }
      return false;
    };
    h.key = [begin, g, number, after](const Event &e) {
      begin();
      if(number && g.step > 0. &&
         (e == Event::ArrowUp || e == Event::ArrowDown)) {
        double v = Ui::bounded(g, g.getNumber() +
                                 (e == Event::ArrowUp ? g.step : -g.step));
        const_cast<Ui::Field &>(g).setNumber(v);
        tuiEdit().text = _number(g, v);
        tuiEdit().cursor = tuiEdit().text.size();
        _told(g, false, after);
        return true;
      }
      bool enter = false;
      if(!tuiEditKey(e, enter)) return false;
      if(enter && tuiEdit().commit) {
        tuiEdit().commit(true);
        // what it says now, as the field has it
        tuiEdit().id.clear();
      }
      else if(!enter && !number && !g.commitsWhenDone) {
        // written at every letter, as the other interfaces do
        const_cast<Ui::Field &>(g).setText(tuiEdit().text);
        _told(g, false, after);
      }
      return true;
    };
    return tuiHot(shown, h);
  }

  // a button: [ label ]
  Element _press(const std::string &label, const std::string &id, bool strong,
                 const std::function<void()> &what)
  {
    bool on = tuiFocused(id);
    Element e = text("[" + label + "]");
    if(strong) e = e | bold;
    if(on) e = e | inverted;
    hotTui h;
    h.id = id;
    h.mouse = [what, id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Released) return false;
      tuiFocus(id);
      tuiLater(what);
      return true;
    };
    h.key = [what](const Event &e) {
      if(e != Event::Return && e != Event::Character(' ')) return false;
      tuiLater(what);
      return true;
    };
    return tuiHot(e, h);
  }

  // the colour map: the wedge as a row of blocks, the channels over it as
  // bars of half blocks, and the keys of the other interfaces
  // what editing each map shows: its help, by the id of the map
  std::map<std::string, Ui::MapEditor> &_mapEditors()
  {
    static std::map<std::string, Ui::MapEditor> m;
    return m;
  }

  // what Ui::MapEditor::picture() says, in half blocks: a column of the
  // terminal a pixel wide, a line two pixels tall and a line of text tall;
  // the help, which cannot be made smaller there, in lines of its own above
  Element _map(const Ui::Field &f, const std::string &id,
               const std::function<void()> &after)
  {
    const Ui::ColourMap &map = f.map;
    if(map.empty()) return text("");
    const int width = 40, rows = 10;
    Ui::MapEditor &edit = _mapEditors()[id];
    Ui::MapEditor plain = edit;
    plain.setHelp(false);
    // with the margin of the last line (.3 of a line) added, the wedge, the
    // marker and the values fall on whole lines
    const double tall = 2. * rows + .6;
    Ui::MapEditor::Picture pic = plain.picture(map, width, tall, 2.);
    // over what is behind the model, as master has it
    Ui::Colour bg = tuiSources().settings().background;
    bool dark = bg.r * 299 + bg.g * 587 + bg.b * 114 < 128000;
    Ui::Colour ink = dark ? Ui::Colour(255, 255, 255) : Ui::Colour(0, 0, 0);
    std::vector<unsigned char> px =
      Ui::MapEditor::raster(pic, width, 2 * rows, bg, ink);
    auto rgb = [&](int x, int y) {
      const unsigned char *p = &px[((std::size_t)y * width + x) * 4];
      return Color::RGB(p[0], p[1], p[2]);
    };
    // the characters of the texts over the cells they fall in
    std::vector<std::string> said((std::size_t)rows * width);
    for(const auto &t : pic.texts) {
      int row = std::min(rows - 1, std::max(0, (int)(t.y / 2. + .5)));
      int col = (int)(t.right ? t.x - t.text.size() : t.x);
      for(std::size_t k = 0; k < t.text.size(); k++)
        if(col + (int)k >= 0 && col + (int)k < width)
          said[(std::size_t)row * width + col + k] = std::string(1, t.text[k]);
    }
    bool on = tuiFocused(id);
    Elements lines;
    if(edit.help())
      for(const auto &k : Ui::MapEditor::helpLines())
        lines.push_back(hbox({text(k.first) | ftxui::size(WIDTH, EQUAL, 24),
                              text(k.second)}) | dim);
    for(int r = 0; r < rows; r++) {
      Elements cells;
      for(int x = 0; x < width; x++) {
        const std::string &c = said[(std::size_t)r * width + x];
        if(c.size())
          cells.push_back(text(c) | color(Color::RGB(ink.r, ink.g, ink.b)) |
                          bgcolor(rgb(x, 2 * r + 1)) | (on ? bold : nothing));
        else
          cells.push_back(text("▀") | color(rgb(x, 2 * r)) |
                          bgcolor(rgb(x, 2 * r + 1)));
      }
      lines.push_back(hbox(std::move(cells)));
    }
    Element e = vbox(std::move(lines));
    Ui::Field g = f;
    hotTui h;
    h.id = id;
    // the picture starts after the help
    int top = edit.help() ? (int)Ui::MapEditor::helpLines().size() : 0;
    h.mouse = [id, g, after, top](Mouse &m, int x, int y) {
      Ui::MapEditor &edit = _mapEditors()[id];
      const Ui::ColourMap &map = g.map;
      int entry = 0, value = 0;
      bool onWedge = false;
      Ui::MapEditor::at(map, x + .5, 2. * (y - top) + 1., width,
                        2. * rows + .6, 2., entry, value, onWedge);
      Ui::MapEditor::Answer answer = Ui::MapEditor::NotMine;
      if(m.motion == Mouse::Pressed &&
         (m.button == Mouse::Left || m.button == Mouse::Middle ||
          m.button == Mouse::Right)) {
        tuiFocus(id);
        if(y < top) return true;
        unsigned mods = (m.control ? Ui::ModCommand : 0u) |
                        (m.shift ? Ui::ModShift : 0u) |
                        (m.meta ? Ui::ModAlt : 0u);
        answer = edit.press(map, entry, value,
                            m.button == Mouse::Right  ? 2 :
                            m.button == Mouse::Middle ? 1 :
                                                        0,
                            mods, onWedge);
      }
      else if(m.motion == Mouse::Released) {
        bool was = edit.drawing();
        edit.release();
        return was;
      }
      else if(edit.drawing())
        answer = edit.drag(map, entry, value);
      else
        return false;
      if(answer == Ui::MapEditor::Changed) _told(g, false, after);
      tuiDirty();
      return true;
    };
    h.key = [g, after, id](const Event &e) {
      const Ui::ColourMap &map = g.map;
      int key = 0;
      unsigned mods = 0;
      if(!tuiUiKey(e, key, mods)) return false;
      Ui::MapEditor::Answer said = _mapEditors()[id].key(map, key, mods);
      if(said == Ui::MapEditor::Changed) _told(g, true, after);
      if(said != Ui::MapEditor::NotMine) tuiDirty();
      return said != Ui::MapEditor::NotMine;
    };
    return tuiHot(e, h);
  }

  // the list one picks from, rows lines tall, with a scroll of its own
  std::map<std::string, int> &_scrolls()
  {
    static std::map<std::string, int> s;
    return s;
  }
  std::map<std::string, int> &_anchors()
  {
    static std::map<std::string, int> s;
    return s;
  }

  Element _list(const Ui::Field &f, const std::string &id, int width,
                const std::function<void()> &after)
  {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    int rows = f.rows ? f.rows : 8;
    int &scroll = _scrolls()[id];
    scroll = std::max(0, std::min(scroll, (int)labels.size() - rows));
    Elements lines;
    for(int k = scroll; k < (int)labels.size() && k < scroll + rows; k++) {
      std::string l = labels[(std::size_t)k];
      // tab-separated columns, each as wide as the description says
      if(f.columnsEm.size() && l.find('\t') != std::string::npos) {
        std::string out;
        std::size_t at = 0, column = 0;
        while(true) {
          std::size_t tab = l.find('\t', at);
          std::string part =
            l.substr(at, tab == std::string::npos ? std::string::npos : tab - at);
          if(tab != std::string::npos && column < f.columnsEm.size())
            part = _fit(part, tuiCells(f.columnsEm[column]));
          out += part;
          if(tab == std::string::npos) break;
          at = tab + 1;
          column++;
        }
        l = out;
      }
      Element line = text(" " + l + " ");
      if(f.chosen && f.chosen(k)) line = line | inverted;
      lines.push_back(line);
    }
    while((int)lines.size() < rows) lines.push_back(text(""));
    Element e = vbox(lines) | border;
    if(width > 0) e = e | size(WIDTH, GREATER_THAN, width);
    Ui::Field g = f;
    hotTui h;
    h.id = id;
    int count = (int)labels.size();
    h.mouse = [g, id, after, count](Mouse &m, int, int y) {
      int &scroll = _scrolls()[id];
      if(m.button == Mouse::WheelUp || m.button == Mouse::WheelDown) {
        scroll += m.button == Mouse::WheelUp ? -3 : 3;
        tuiDirty();
        return true;
      }
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      tuiFocus(id);
      int k = scroll + y - 1;
      if(k < 0 || k >= count) return true;
      if(!g.choose) {
        // a line one clicks is one to be rid of
        if(g.removeItem) {
          Ui::Field c = g;
          tuiLater([c, k, after]() {
            c.removeItem(k);
            if(c.changed) c.changed();
            if(after) after();
          });
        }
        return true;
      }
      // as in a file manager: that line, Control adds or takes one away,
      // Shift runs from the last one clicked
      int &anchor = _anchors()[id];
      for(int i = 0; i < count; i++) {
        bool was = g.chosen && g.chosen(i), now;
        if(g.multiple && m.control)
          now = i == k ? !was : was;
        else if(g.multiple && m.shift && anchor >= 0)
          now = i >= std::min(anchor, k) && i <= std::max(anchor, k);
        else
          now = i == k;
        if(now != was || !g.multiple) g.choose(i, now);
      }
      if(!m.shift) anchor = k;
      _told(g, true, after);
      return true;
    };
    return tuiHot(e, h);
  }

} // namespace

// --- a field

Element tuiFieldWidget(const Ui::Field &f, const std::string &id, int width,
                   const std::function<void()> &after)
{
  bool enabled = f.enabled ? f.enabled() : true;
  Element e;
  Ui::Field g = f;
  switch(f.kind) {
  case Ui::Text:
  case Ui::Integer:
  case Ui::Number:
    e = _line(f, id, width > 0 ? width : tuiCells(10.), after, enabled);
    if(f.kind == Ui::Text && f.dynamicChoices && enabled) {
      // the choices of a line of text, dropped from a mark after it
      hotTui h;
      h.mouse = [g, after](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
        std::vector<std::string> labels;
        std::vector<int> values;
        g.dynamicChoices(labels, values);
        tuiChoose(labels, -1, m.x, m.y + 1, [g, labels, after](int i) {
          const_cast<Ui::Field &>(g).setText(labels[(std::size_t)i]);
          tuiEdit().id.clear();
          _told(g, true, after);
        });
        return true;
      };
      e = hbox({e, tuiHot(text("▾") | _valueStyle(false), h)});
    }
    break;
  case Ui::Output: e = _line(f, id, width > 0 ? width : tuiCells(10.), after, false); break;
  case Ui::Check: {
    bool v = f.getFlag();
    if(f.disclosure) {
      e = _press(f.label + (v ? " ▴" : " ▾"), id, false,
                 [g, v, after]() {
                   const_cast<Ui::Field &>(g).setFlag(!v);
                   if(g.done)
                     g.done();
                   else if(g.changed)
                     g.changed();
                   if(after) after();
                 });
      break;
    }
    bool on = tuiFocused(id);
    e = hbox({text(v ? "[x] " : "[ ] ") | (on ? inverted : nothing),
              text(f.label)});
    if(f.alert) e = e | color(Color::Red);
    hotTui h;
    h.id = id;
    auto flip = [g, after]() {
      const_cast<Ui::Field &>(g).setFlag(!g.getFlag());
      _told(g, true, after);
    };
    h.mouse = [flip, id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      tuiFocus(id);
      flip();
      return true;
    };
    h.key = [flip](const Event &ev) {
      if(ev != Event::Return && ev != Event::Character(' ')) return false;
      flip();
      return true;
    };
    if(enabled) e = tuiHot(e, h);
  } break;
  case Ui::Choice: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    if(f.multiple) {
      // switches in the menu it drops
      std::vector<Ui::MenuItem> items;
      for(std::size_t k = 0; k < labels.size(); k++) {
        Ui::MenuItem it;
        it.kind = Ui::MenuItem::Toggle;
        it.label = labels[k];
        int i = (int)k;
        it.checked = [g, i]() { return g.chosen && g.chosen(i); };
        it.action = [g, i, after]() {
          if(g.choose) g.choose(i, !(g.chosen && g.chosen(i)));
          if(g.done)
            g.done();
          else if(g.changed)
            g.changed();
          if(after) after();
        };
        items.push_back(it);
      }
      bool on = tuiFocused(id);
      e = text("[" + f.label + " ▾]") | (on ? inverted : nothing);
      hotTui h;
      h.id = id;
      h.mouse = [items, id](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
        tuiFocus(id);
        tuiPopupMenu(items, m.x, m.y + 1);
        return true;
      };
      if(enabled) e = tuiHot(e, h);
      break;
    }
    int which = -1;
    std::string current = values.empty() ? f.getText() : "";
    for(std::size_t k = 0; k < labels.size(); k++) {
      if(values.empty()) {
        if(labels[k] == current) which = (int)k;
      }
      else if(k < values.size() && values[k] == (int)f.getNumber())
        which = (int)k;
    }
    std::string shown = which >= 0 ? labels[(std::size_t)which] : current;
    int w = width > 0 ? width - 1 : tuiCells(10.) - 1;
    bool on = tuiFocused(id);
    e = hbox({text(_fit(shown, w)), text("▾")}) | _valueStyle(on);
    hotTui h;
    h.id = id;
    auto pick = [g, labels, values, which, after](int x, int y) {
      tuiChoose(labels, which, x, y, [g, labels, values, after](int i) {
        if(values.empty())
          const_cast<Ui::Field &>(g).setText(labels[(std::size_t)i]);
        else if(i < (int)values.size())
          const_cast<Ui::Field &>(g).setNumber(values[(std::size_t)i]);
        _told(g, true, after);
      });
    };
    std::shared_ptr<Box> where = std::make_shared<Box>();
    h.mouse = [pick, id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      tuiFocus(id);
      pick(m.x, m.y + 1);
      return true;
    };
    h.box = where;
    h.key = [pick, where](const Event &ev) {
      if(ev != Event::Return && ev != Event::Character(' ')) return false;
      pick(where->x_min, where->y_max + 1);
      return true;
    };
    if(enabled)
      e = tuiHot(e, h);
    else
      e = e | dim;
  } break;
  case Ui::Label: {
    std::string v = f.getText();
    if(v.empty()) v = f.label;
    e = f.wraps ? paragraph(v) : text(v);
    if(f.heading) e = e | bold;
    if(f.alert) e = e | color(Color::Red);
    if(width > 0) e = e | size(WIDTH, EQUAL, width);
    if(f.align == Ui::Centre) e = e | center;
    if(f.align == Ui::Right) e = hbox({filler(), e});
  } break;
  case Ui::Prose: {
    Elements lines;
    std::vector<Ui::Line> page = f.prose ? f.prose() : std::vector<Ui::Line>();
    for(const Ui::Line &l : page) {
      Elements words;
      if(l.bullet) words.push_back(text("• "));
      for(const Ui::Words &w : l.words) {
        // a word at a time, so that the line wraps between them
        std::size_t at = 0;
        while(at < w.text.size()) {
          std::size_t sp = w.text.find(' ', at);
          std::string one = w.text.substr(at, sp == std::string::npos ?
                                                std::string::npos :
                                                sp - at + 1);
          at = sp == std::string::npos ? w.text.size() : sp + 1;
          Element word = text(one);
          if(w.italic) word = word | italic;
          if(l.heading) word = word | bold;
          if(w.follow) {
            hotTui h;
            std::function<void()> follow = w.follow;
            h.mouse = [follow](Mouse &m, int, int) {
              if(m.button != Mouse::Left || m.motion != Mouse::Pressed)
                return false;
              tuiLater(follow);
              return true;
            };
            word = tuiHot(word | underlined | color(Color::Cyan), h);
          }
          words.push_back(word);
        }
      }
      if(words.empty()) words.push_back(text(" "));
      FlexboxConfig c;
      if(l.centred) c.justify_content = FlexboxConfig::JustifyContent::Center;
      lines.push_back(flexbox(words, c));
    }
    e = vbox(lines);
    if(width > 0) e = e | size(WIDTH, GREATER_THAN, width);
  } break;
  case Ui::Action: {
    std::function<void()> what = [g, after]() {
      if(g.changed) g.changed();
      if(after) after();
    };
    e = _press(f.label, id, f.isDefault, what);
    if(f.alert) e = e | color(Color::Red);
    if(!enabled) e = e | dim;
  } break;
  case Ui::Color: {
    Ui::Colour c = f.getColour();
    char hex[16];
    snprintf(hex, sizeof(hex), "#%02x%02x%02x", c.r, c.g, c.b);
    bool on = tuiFocused(id);
    e = hbox({text("██") | color(Color::RGB(c.r, c.g, c.b)),
              text(std::string(" ") + hex) | (on ? inverted : nothing)});
    hotTui h;
    h.id = id;
    auto change = [g, after]() {
      Ui::Colour was = g.getColour();
      char said[16];
      snprintf(said, sizeof(said), "#%02x%02x%02x", was.r, was.g, was.b);
      std::string value = said;
      if(!tuiAsk("Colour, as #rrggbb", value)) return;
      unsigned int r = 0, gr = 0, b = 0;
      if(sscanf(value.c_str(), "#%02x%02x%02x", &r, &gr, &b) != 3) return;
      const_cast<Ui::Field &>(g).setColour(
        Ui::Colour((unsigned char)r, (unsigned char)gr, (unsigned char)b, was.a));
      if(g.done)
        g.done();
      else if(g.changed)
        g.changed();
      if(after) after();
    };
    h.mouse = [change, id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      tuiFocus(id);
      tuiLater(change);
      return true;
    };
    h.key = [change](const Event &ev) {
      if(ev != Event::Return) return false;
      tuiLater(change);
      return true;
    };
    if(enabled) e = tuiHot(e, h);
  } break;
  case Ui::Direction: {
    double x = 0., y = 0., z = 0.;
    f.getVector(x, y, z);
    char said[96];
    snprintf(said, sizeof(said), "(%.3g, %.3g, %.3g)", x, y, z);
    bool on = tuiFocused(id);
    e = text(said) | _valueStyle(on);
    hotTui h;
    h.id = id;
    auto change = [g, after]() {
      double x = 0., y = 0., z = 0.;
      g.getVector(x, y, z);
      char was[96];
      snprintf(was, sizeof(was), "%g %g %g", x, y, z);
      std::string value = was;
      if(!tuiAsk("Direction, as x y z", value)) return;
      if(sscanf(value.c_str(), "%lf %lf %lf", &x, &y, &z) != 3) return;
      const_cast<Ui::Field &>(g).setVector(x, y, z);
      if(g.done)
        g.done();
      else if(g.changed)
        g.changed();
      if(after) after();
    };
    h.mouse = [change, id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      tuiFocus(id);
      tuiLater(change);
      return true;
    };
    if(enabled) e = tuiHot(e, h);
  } break;
  case Ui::ColorMap: e = _map(f, id, after); break;
  case Ui::Hierarchy: {
    static std::map<std::string, treeTui> states;
    Ui::Tree none;
    e = tuiTree(f.hierarchy ? *f.hierarchy : none, states[id], true, id,
             f.rows ? f.rows : 12, after) |
        border;
  } break;
  case Ui::Menu: {
    bool on = tuiFocused(id);
    e = text("[" + f.label + " ▾]") | (on ? inverted : nothing);
    hotTui h;
    h.id = id;
    h.mouse = [g, id, after](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      tuiFocus(id);
      std::vector<std::string> labels;
      std::vector<int> values;
      Ui::choices(g, labels, values);
      tuiChoose(labels, -1, m.x, m.y + 1, [g, after](int i) {
        if(g.choose) g.choose(i, true);
        if(g.done)
          g.done();
        else if(g.changed)
          g.changed();
        if(after) after();
      });
      return true;
    };
    if(enabled) e = tuiHot(e, h);
  } break;
  case Ui::List: e = _list(f, id, width, after); break;
  case Ui::Spacer: e = filler(); break;
  }
  if(!enabled && f.kind != Ui::Text && f.kind != Ui::Number &&
     f.kind != Ui::Integer)
    e = e | dim;
  return e;
}

Element tuiButtonWidget(const Ui::Button &b, const std::string &id,
                    const std::function<void()> &after)
{
  const Ui::Glyph *g = Ui::glyph(b.glyph);
  std::string label = g ? g->text : b.label.size() ? b.label : b.menu ? "▾" : "";
  Ui::Button c = b;
  Element e = text("[" + label + "]");
  if(b.on && b.on()) e = e | bold | color(Color::Green);
  bool enabled = b.enabled ? b.enabled() : true;
  if(!enabled) return e | dim;
  hotTui h;
  h.id = id;
  h.mouse = [c, after, id](Mouse &m, int, int) {
    if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
    tuiFocus(id);
    if(c.menu) {
      tuiPopupMenu(c.menu(), m.x, m.y + 1);
      return true;
    }
    std::function<void()> what = c.action;
    tuiLater([what, after]() {
      if(what) what();
      if(after) after();
    });
    return true;
  };
  return tuiHot(e, h);
}
