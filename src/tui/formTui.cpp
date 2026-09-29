// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_TUI)

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include "tuiCommon.h"
#include "Layout.h" // Ui::fills()

using namespace ftxui;

// The widgets of the fields, the forms and the trees, made afresh at every
// frame. A form is translated as the page translates it (render(), lines(),
// cellOf() and cell() of src/browser/page.html): a box down is its lines, one
// across a line -- an hbox, what grows flex_grow, a gap filler() -- a grid a
// gridbox, tabs a row of names over the pane showing.

namespace {

  // what is typed over, the text shown by a field of that width
  std::string _fit(const std::string &s, int width)
  {
    if(width <= 0) return s;
    // counted in bytes: what Gmsh says is mostly ASCII
    if((int)s.size() > width) return s.substr(0, std::max(0, width - 1)) + "…";
    return s + std::string(width - s.size(), ' ');
  }

  Decorator _valueStyle(bool on)
  {
    return on ? (bgcolor(Color::Blue) | color(Color::White)) :
                (bgcolor(Color::GrayDark) | color(Color::White));
  }

  // --- numbers

  std::string _number(const Ui::Field &f, double v)
  {
    char s[64];
    if(f.step > 0. && Tui::sources().settings().inputScrolling) {
      int decimals = 0;
      while(decimals < 10 &&
            std::fabs(f.step * std::pow(10., decimals) -
                      std::floor(f.step * std::pow(10., decimals) + .5)) > 1e-9)
        decimals++;
      snprintf(s, sizeof(s), "%.*f", decimals, v);
      if(v != 0. && std::fabs(atof(s) - v) > 1e-9 * std::fabs(v))
        snprintf(s, sizeof(s), "%g", v);
    }
    else
      snprintf(s, sizeof(s), "%g", v);
    return s;
  }

  double _bounded(const Ui::Field &f, double v)
  {
    if(f.maximum > f.minimum) v = std::max(f.minimum, std::min(f.maximum, v));
    if(f.kind == Ui::Integer) v = std::floor(v + .5);
    return v;
  }

  // a change the user made: the done() of a choosing that ended, the
  // changed() of a step, then what the holder does
  void _told(const Ui::Field &f, bool ends, const std::function<void()> &after)
  {
    Ui::Field g = f;
    Tui::later([g, ends, after]() {
      if(g.done && ends)
        g.done();
      else if(g.changed)
        g.changed();
      if(after) after();
    });
  }

  void _choicesOf(const Ui::Field &f, std::vector<std::string> &labels,
                  std::vector<int> &values)
  {
    labels.clear();
    values.clear();
    if(f.dynamicChoices)
      f.dynamicChoices(labels, values);
    else if(f.list && f.itemLabel)
      for(std::size_t i = 0; i < f.list->size(); i++)
        labels.push_back(f.itemLabel((int)i));
    else if(f.list)
      for(std::size_t i = 0; i < f.list->size(); i++)
        labels.push_back(std::to_string((*f.list)[i]));
    else {
      labels = f.choices;
      values = f.values;
    }
  }

  // --- a line one types in: the text of the field, or what is being typed

  Element _line(const Ui::Field &f, const std::string &id, int width,
                const std::function<void()> &after, bool editable)
  {
    bool number = f.kind == Ui::Integer || f.kind == Ui::Number;
    std::string value = number ? _number(f, f.getNumber()) : f.getText();
    bool on = Tui::focused(id);
    Tui::Edit &ed = Tui::edit();
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
              size(WIDTH, EQUAL, w) | _valueStyle(true);
    }
    else
      shown = text(_fit(value, width > 0 ? width : (int)value.size())) |
              _valueStyle(on);
    if(!editable) return shown | dim;
    Ui::Field g = f;
    Tui::Hot h;
    h.id = id;
    auto begin = [g, id, number, after]() {
      Tui::Edit &e = Tui::edit();
      if(e.id == id) return;
      e.id = id;
      e.text = number ? _number(g, g.getNumber()) : g.getText();
      e.cursor = e.text.size();
      std::string was = e.text;
      e.commit = [g, number, after, was](bool enter) {
        std::string now = Tui::edit().text;
        if(now == was && !enter) return;
        if(number) {
          char *end = nullptr;
          double v = strtod(now.c_str(), &end);
          if(end == now.c_str()) return;
          const_cast<Ui::Field &>(g).setNumber(_bounded(g, v));
        }
        else if(now != was || !g.commitsWhenDone)
          const_cast<Ui::Field &>(g).setText(now);
        _told(g, true, after);
      };
    };
    h.mouse = [begin, g, id, number, after](Mouse &m, int, int) {
      if(m.button == Mouse::Left && m.motion == Mouse::Pressed) {
        Tui::focus(id);
        begin();
        return true;
      }
      // the wheel steps a number that has a step
      if(number && g.step > 0. && Tui::sources().settings().inputScrolling &&
         (m.button == Mouse::WheelUp || m.button == Mouse::WheelDown)) {
        double v = _bounded(g, g.getNumber() + (m.button == Mouse::WheelUp ?
                                                  g.step : -g.step));
        const_cast<Ui::Field &>(g).setNumber(v);
        Tui::edit().id.clear();
        _told(g, false, after);
        return true;
      }
      return false;
    };
    h.key = [begin, g, number, after](const Event &e) {
      begin();
      if(number && g.step > 0. &&
         (e == Event::ArrowUp || e == Event::ArrowDown)) {
        double v = _bounded(g, g.getNumber() +
                                 (e == Event::ArrowUp ? g.step : -g.step));
        const_cast<Ui::Field &>(g).setNumber(v);
        Tui::edit().text = _number(g, v);
        Tui::edit().cursor = Tui::edit().text.size();
        _told(g, false, after);
        return true;
      }
      bool enter = false;
      if(!Tui::editKey(e, enter)) return false;
      if(enter && Tui::edit().commit) {
        Tui::edit().commit(true);
        // what it says now, as the field has it
        Tui::edit().id.clear();
      }
      else if(!enter && !number && !g.commitsWhenDone) {
        // written at every letter, as the other interfaces do
        const_cast<Ui::Field &>(g).setText(Tui::edit().text);
        _told(g, false, after);
      }
      return true;
    };
    return Tui::hot(shown, h);
  }

  // a button: [ label ]
  Element _press(const std::string &label, const std::string &id, bool strong,
                 const std::function<void()> &what)
  {
    bool on = Tui::focused(id);
    Element e = text("[" + label + "]");
    if(strong) e = e | bold;
    if(on) e = e | inverted;
    Tui::Hot h;
    h.id = id;
    h.mouse = [what, id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Released) return false;
      Tui::focus(id);
      Tui::later(what);
      return true;
    };
    h.key = [what](const Event &e) {
      if(e != Event::Return && e != Event::Character(' ')) return false;
      Tui::later(what);
      return true;
    };
    return Tui::hot(e, h);
  }

  // the colour map: the wedge as a row of blocks, the channels over it as
  // bars of half blocks, and the keys of the other interfaces
  Element _map(const Ui::Field &f, const std::string &id,
               const std::function<void()> &after)
  {
    const Ui::ColourMap &map = f.map;
    if(map.empty()) return text("");
    std::string name;
    double least = 0., most = 0.;
    map.about(name, least, most);
    int size = map.size(), width = 40;
    Elements wedge;
    for(int x = 0; x < width; x++) {
      int i = std::min(size - 1, x * size / width);
      Ui::Colour c = map.colour(i);
      wedge.push_back(text("█") | color(Color::RGB(c.r, c.g, c.b)));
    }
    char said[64];
    bool hsv = map.hsv ? map.hsv() : false;
    snprintf(said, sizeof(said), "Colormap %d (%s)", map.preset ? map.preset() : 0,
             hsv ? "HSV" : "RGB");
    char lo[32], hi[32];
    snprintf(lo, sizeof(lo), "%g", least);
    snprintf(hi, sizeof(hi), "%g", most);
    bool on = Tui::focused(id);
    Element e = vbox({text(said) | (on ? inverted : nothing), hbox(wedge),
                      hbox({text(lo), filler(), text(hi)})});
    Ui::Field g = f;
    Tui::Hot h;
    h.id = id;
    h.mouse = [id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      Tui::focus(id);
      return true;
    };
    h.key = [g, after](const Event &e) {
      const Ui::ColourMap &map = g.map;
      int key = 0;
      unsigned mods = 0;
      if(!Tui::uiKey(e, key, mods)) return false;
      bool ctrl = (mods & Ui::ModCommand) != 0, changed = false;
      int presets = map.numPresets ? map.numPresets() : 0, preset = -1;
      if(key >= '0' && key <= '9') preset = (key - '0') + (ctrl ? 10 : 0);
      if(key >= Ui::KeyF1 && key < Ui::KeyF1 + 7) preset = 20 + key - Ui::KeyF1;
      if(preset >= 0 && preset < presets) {
        map.choosePreset(preset);
        changed = true;
      }
      else if(key == 'M' && !ctrl && map.setHsv) {
        map.setHsv(!map.hsv());
        changed = true;
      }
      else if(key == 'R' && !ctrl) {
        if(map.preset) map.choosePreset(map.preset());
        changed = true;
      }
      else if(key == 'C' && ctrl) {
        if(map.copy) map.copy();
        return true;
      }
      else if(key == 'V' && ctrl) {
        if(map.paste) map.paste();
        changed = true;
      }
      else if(map.parameters) {
        for(const auto &p : map.parameters()) {
          if(!p.up.empty() && p.up.matches(key, mods)) {
            map.adjust(p, true);
            changed = true;
            break;
          }
          if(!p.down.empty() && p.down.matches(key, mods)) {
            map.adjust(p, false);
            changed = true;
            break;
          }
        }
      }
      if(changed) _told(g, true, after);
      return changed;
    };
    return Tui::hot(e, h);
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
    _choicesOf(f, labels, values);
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
            part = _fit(part, Tui::cells(f.columnsEm[column]));
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
    Tui::Hot h;
    h.id = id;
    int count = (int)labels.size();
    h.mouse = [g, id, after, count](Mouse &m, int, int y) {
      int &scroll = _scrolls()[id];
      if(m.button == Mouse::WheelUp || m.button == Mouse::WheelDown) {
        scroll += m.button == Mouse::WheelUp ? -3 : 3;
        Tui::dirty();
        return true;
      }
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      Tui::focus(id);
      int k = scroll + y - 1;
      if(k < 0 || k >= count) return true;
      if(!g.choose) {
        // a line one clicks is one to be rid of
        if(g.removeItem) {
          Ui::Field c = g;
          Tui::later([c, k, after]() {
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
    return Tui::hot(e, h);
  }

} // namespace

// --- a field

Element Tui::field(const Ui::Field &f, const std::string &id, int width,
                   const std::function<void()> &after)
{
  bool enabled = f.enabled ? f.enabled() : true;
  Element e;
  Ui::Field g = f;
  switch(f.kind) {
  case Ui::Text:
  case Ui::Integer:
  case Ui::Number:
    e = _line(f, id, width > 0 ? width : cells(10.), after, enabled);
    if(f.kind == Ui::Text && f.dynamicChoices && enabled) {
      // the choices of a line of text, dropped from a mark after it
      Tui::Hot h;
      h.mouse = [g, after](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
        std::vector<std::string> labels;
        std::vector<int> values;
        g.dynamicChoices(labels, values);
        Tui::choose(labels, -1, m.x, m.y + 1, [g, labels, after](int i) {
          const_cast<Ui::Field &>(g).setText(labels[(std::size_t)i]);
          Tui::edit().id.clear();
          _told(g, true, after);
        });
        return true;
      };
      e = hbox({e, Tui::hot(text("▾") | _valueStyle(false), h)});
    }
    break;
  case Ui::Output: e = _line(f, id, width > 0 ? width : cells(10.), after, false); break;
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
    bool on = focused(id);
    e = hbox({text(v ? "[x] " : "[ ] ") | (on ? inverted : nothing),
              text(f.label)});
    if(f.alert) e = e | color(Color::Red);
    Tui::Hot h;
    h.id = id;
    auto flip = [g, after]() {
      const_cast<Ui::Field &>(g).setFlag(!g.getFlag());
      _told(g, true, after);
    };
    h.mouse = [flip, id](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      focus(id);
      flip();
      return true;
    };
    h.key = [flip](const Event &ev) {
      if(ev != Event::Return && ev != Event::Character(' ')) return false;
      flip();
      return true;
    };
    if(enabled) e = hot(e, h);
  } break;
  case Ui::Choice: {
    std::vector<std::string> labels;
    std::vector<int> values;
    _choicesOf(f, labels, values);
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
      bool on = focused(id);
      e = text("[" + f.label + " ▾]") | (on ? inverted : nothing);
      Tui::Hot h;
      h.id = id;
      h.mouse = [items, id](Mouse &m, int, int) {
        if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
        focus(id);
        popup(items, m.x, m.y + 1);
        return true;
      };
      if(enabled) e = hot(e, h);
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
    int w = width > 0 ? width - 1 : cells(10.) - 1;
    bool on = focused(id);
    e = hbox({text(_fit(shown, w)), text("▾")}) | _valueStyle(on);
    Tui::Hot h;
    h.id = id;
    auto pick = [g, labels, values, which, after](int x, int y) {
      choose(labels, which, x, y, [g, labels, values, after](int i) {
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
      focus(id);
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
      e = hot(e, h);
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
            Tui::Hot h;
            std::function<void()> follow = w.follow;
            h.mouse = [follow](Mouse &m, int, int) {
              if(m.button != Mouse::Left || m.motion != Mouse::Pressed)
                return false;
              later(follow);
              return true;
            };
            word = hot(word | underlined | color(Color::Cyan), h);
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
    bool on = focused(id);
    e = hbox({text("██") | color(Color::RGB(c.r, c.g, c.b)),
              text(std::string(" ") + hex) | (on ? inverted : nothing)});
    Tui::Hot h;
    h.id = id;
    auto change = [g, after]() {
      Ui::Colour was = g.getColour();
      char said[16];
      snprintf(said, sizeof(said), "#%02x%02x%02x", was.r, was.g, was.b);
      std::string value = said;
      if(!ask("Colour, as #rrggbb", value)) return;
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
      focus(id);
      later(change);
      return true;
    };
    h.key = [change](const Event &ev) {
      if(ev != Event::Return) return false;
      later(change);
      return true;
    };
    if(enabled) e = hot(e, h);
  } break;
  case Ui::Direction: {
    double x = 0., y = 0., z = 0.;
    f.getVector(x, y, z);
    char said[96];
    snprintf(said, sizeof(said), "(%.3g, %.3g, %.3g)", x, y, z);
    bool on = focused(id);
    e = text(said) | _valueStyle(on);
    Tui::Hot h;
    h.id = id;
    auto change = [g, after]() {
      double x = 0., y = 0., z = 0.;
      g.getVector(x, y, z);
      char was[96];
      snprintf(was, sizeof(was), "%g %g %g", x, y, z);
      std::string value = was;
      if(!ask("Direction, as x y z", value)) return;
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
      focus(id);
      later(change);
      return true;
    };
    if(enabled) e = hot(e, h);
  } break;
  case Ui::ColorMap: e = _map(f, id, after); break;
  case Ui::Hierarchy: {
    static std::map<std::string, TreeState> states;
    Ui::Tree none;
    e = tree(f.hierarchy ? *f.hierarchy : none, states[id], true, id,
             f.rows ? f.rows : 12, after) |
        border;
  } break;
  case Ui::Menu: {
    bool on = focused(id);
    e = text("[" + f.label + " ▾]") | (on ? inverted : nothing);
    Tui::Hot h;
    h.id = id;
    h.mouse = [g, id, after](Mouse &m, int, int) {
      if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
      focus(id);
      std::vector<std::string> labels;
      std::vector<int> values;
      _choicesOf(g, labels, values);
      choose(labels, -1, m.x, m.y + 1, [g, after](int i) {
        if(g.choose) g.choose(i, true);
        if(g.done)
          g.done();
        else if(g.changed)
          g.changed();
        if(after) after();
      });
      return true;
    };
    if(enabled) e = hot(e, h);
  } break;
  case Ui::List: e = _list(f, id, width, after); break;
  case Ui::Spacer: e = filler(); break;
  }
  if(!enabled && f.kind != Ui::Text && f.kind != Ui::Number &&
     f.kind != Ui::Integer)
    e = e | dim;
  return e;
}

Element Tui::button(const Ui::Button &b, const std::string &id,
                    const std::function<void()> &after)
{
  std::string label = b.label.size() ? b.label : b.menu ? "▾" : b.glyph;
  Ui::Button c = b;
  Element e = text("[" + label + "]");
  if(b.on && b.on()) e = e | bold | color(Color::Green);
  bool enabled = b.enabled ? b.enabled() : true;
  if(!enabled) return e | dim;
  Tui::Hot h;
  h.id = id;
  h.mouse = [c, after, id](Mouse &m, int, int) {
    if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
    focus(id);
    if(c.menu) {
      popup(c.menu(), m.x, m.y + 1);
      return true;
    }
    std::function<void()> what = c.action;
    later([what, after]() {
      if(what) what();
      if(after) after();
    });
    return true;
  };
  return hot(e, h);
}

// --- a tree: its lines, those of the branches open, in a scroll of its own

namespace {

  std::string _labelOf(const Ui::Node &node, const std::string &path)
  {
    if(node.label.size()) return node.label;
    std::size_t slash = path.find_last_of('/');
    return slash == std::string::npos ? path : path.substr(slash + 1);
  }

  void _lines(const Ui::Tree &t, Tui::TreeState &state, bool picks,
              const std::string &id, const std::string &parent, int depth,
              Elements &out, const std::function<void()> &after)
  {
    bool commands = Tui::sources().settings().showModuleMenu;
    for(const std::string &path : t.children(parent)) {
      if(parent.empty() && path == "0Modules" && !commands && !picks) continue;
      Ui::Node node = t.node(path);
      std::string label = _labelOf(node, path);
      bool branch = !t.children(path).empty();
      bool enabled = node.enabled ? node.enabled() : true;
      std::string indent(2 * depth, ' ');
      Elements row;
      row.push_back(text(indent));
      if(branch) {
        auto it = state.open.find(path);
        if(it == state.open.end()) {
          // as the FLTK tree has it: the modules folded under their root, the
          // rest open unless the description folds it; the tree of a field
          // folded
          bool open = !node.closed && !(t.closed && t.closed(path)) && !picks &&
                      path.compare(0, 9, "0Modules/") != 0;
          it = state.open.insert(std::make_pair(path, open)).first;
        }
        bool open = it->second;
        Tui::Hot h;
        Ui::Tree tree = t;
        Tui::TreeState *st = &state;
        h.mouse = [tree, st, path](Mouse &m, int, int) {
          if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
          bool now = !st->open[path];
          st->open[path] = now;
          if(tree.setClosed) tree.setClosed(path, !now);
          Tui::dirty();
          return true;
        };
        row.push_back(Tui::hot(text(open ? "▾ " : "▸ "), h));
      }
      else
        row.push_back(text("  "));
      if(picks && node.pick) {
        bool on = node.picked && node.picked();
        Tui::Hot h;
        std::function<void(bool)> pick = node.pick;
        h.mouse = [pick, on, after](Mouse &m, int, int) {
          if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
          pick(!on);
          if(after) Tui::later(after);
          Tui::dirty();
          return true;
        };
        row.push_back(Tui::hot(text(std::string(on ? "[x] " : "[ ] ") + label), h));
      }
      else if(!branch && node.hasField) {
        std::string fid = id + ":" + path;
        int width = node.field.kind == Ui::Check || node.field.kind == Ui::Action ?
                      0 :
                      Tui::cells(8.);
        row.push_back(Tui::field(node.field, fid, width, after));
        if(node.label.size()) {
          row.push_back(text(" "));
          Element name = text(label);
          if(node.pressed) {
            Tui::Hot h;
            std::function<void()> what = node.pressed;
            h.mouse = [what, after](Mouse &m, int, int) {
              if(m.button != Mouse::Left || m.motion != Mouse::Pressed)
                return false;
              Tui::later([what, after]() {
                what();
                if(after) after();
              });
              return true;
            };
            name = Tui::hot(name, h);
          }
          row.push_back(name);
        }
      }
      else {
        Element name = text(label);
        if(branch) {
          // a branch is opened by its name as well
          Tui::Hot h;
          Ui::Tree tree = t;
          Tui::TreeState *st = &state;
          std::function<void()> what = node.pressed;
          h.mouse = [tree, st, path, what](Mouse &m, int, int) {
            if(m.button != Mouse::Left || m.motion != Mouse::Pressed)
              return false;
            if(what) {
              Tui::later(what);
              return true;
            }
            bool now = !st->open[path];
            st->open[path] = now;
            if(tree.setClosed) tree.setClosed(path, !now);
            Tui::dirty();
            return true;
          };
          name = Tui::hot(name, h);
        }
        else if(node.pressed) {
          Tui::Hot h;
          std::function<void()> what = node.pressed;
          h.mouse = [what, after](Mouse &m, int, int) {
            if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
            Tui::later([what, after]() {
              what();
              if(after) after();
            });
            return true;
          };
          name = Tui::hot(name, h);
        }
        row.push_back(name);
      }
      Element line = hbox(row);
      if(node.highlight.a)
        line = line | bgcolor(Color::RGB(node.highlight.r, node.highlight.g,
                                         node.highlight.b));
      if(!enabled) line = line | dim;
      if(node.menu) {
        Tui::Hot h;
        std::function<std::vector<Ui::MenuItem>()> menu = node.menu;
        h.mouse = [menu](Mouse &m, int, int) {
          if(m.button != Mouse::Right || m.motion != Mouse::Pressed) return false;
          Tui::popup(menu(), m.x, m.y + 1);
          return true;
        };
        line = Tui::hot(line, h);
      }
      out.push_back(line);
      if(branch && state.open[path])
        _lines(t, state, picks, id, path, depth + 1, out, after);
    }
  }

} // namespace

Element Tui::tree(const Ui::Tree &t, TreeState &state, bool picks,
                  const std::string &id, int height,
                  const std::function<void()> &after)
{
  if(!t.children || !t.node) return text("");
  Elements lines;
  _lines(t, state, picks, id, "", 0, lines, after);
  int count = (int)lines.size();
  if(height > 0) {
    state.scroll = std::max(0, std::min(state.scroll, count - height));
    Elements shown(lines.begin() + std::min(state.scroll, count), lines.end());
    lines = shown;
  }
  Element e = vbox(lines);
  if(height > 0) e = e | size(HEIGHT, EQUAL, height);
  // the wheel scrolls what is under the lines' own clicks
  Tui::Hot h;
  TreeState *st = &state;
  h.mouse = [st](Mouse &m, int, int) {
    if(m.button != Mouse::WheelUp && m.button != Mouse::WheelDown) return false;
    st->scroll += m.button == Mouse::WheelUp ? -3 : 3;
    if(st->scroll < 0) st->scroll = 0;
    Tui::dirty();
    return true;
  };
  return hot(e, h);
}

// --- a form, as the page writes it

namespace {

  bool _shown(const Ui::Item &it)
  {
    if(it.kind == Ui::Item::AField)
      return !it.field.visible || it.field.visible();
    if(it.kind == Ui::Item::ABox) return !it.box->visible || it.box->visible();
    return it.kind != Ui::Item::Nothing;
  }

  bool _gap(const Ui::Item &it)
  {
    return it.kind == Ui::Item::AField && it.field.kind == Ui::Spacer;
  }

  struct maker {
    const Ui::Form &form;
    Tui::FormState &state;
    int count = 0;
    // the names before their fields are one column, as wide as the widest
    int before = 0;
    std::function<void()> after;
    maker(const Ui::Form &f, Tui::FormState &s) : form(f), state(s) {}

    std::string id() { return form.id + "#" + std::to_string(count++); }

    void widest(const Ui::Item &it)
    {
      if(!_shown(it)) return;
      if(it.kind == Ui::Item::AField && it.field.labelBefore)
        before = std::max(before, (int)it.field.label.size());
      if(it.kind == Ui::Item::ABox)
        for(const auto &i : it.box->items) widest(i);
      if(it.kind == Ui::Item::ATabs)
        for(const auto &t : it.tabs->tabs) widest(t.second);
    }

    // the cell of a field: its widget, the buttons after it, its name
    Element cell(const Ui::Field &f, int holds, bool &grows)
    {
      grows = (f.kind == Ui::List || f.kind == Ui::Hierarchy ||
               f.kind == Ui::Prose || f.kind == Ui::ColorMap) &&
              !(f.widthEm > 0.) && !(f.widthShare > 0.);
      if(f.kind == Ui::Spacer) {
        grows = true;
        return filler();
      }
      bool value = f.kind == Ui::Text || f.kind == Ui::Integer ||
                   f.kind == Ui::Number || f.kind == Ui::Output ||
                   (f.kind == Ui::Choice && !f.multiple);
      int wide = 0;
      if(f.widthEm > 0.)
        wide = Tui::cells(f.widthEm);
      else if(f.widthShare > 0.)
        wide = Tui::cells(10. * f.widthShare);
      else if(value)
        wide = Tui::cells(10. / std::max(1, holds));
      std::string me = id();
      if(f.kind == Ui::Label) {
        if(f.align != Ui::Left || f.wraps) grows = true;
        return Tui::field(f, me, wide, after);
      }
      if(f.kind == Ui::Check && f.disclosure) {
        grows = true;
        return hbox({filler(), Tui::field(f, me, 0, after)});
      }
      Element what = Tui::field(f, me, wide, after);
      Elements parts;
      bool named = f.label.size() && f.kind != Ui::Check && f.kind != Ui::Action &&
                   f.kind != Ui::Menu && !(f.kind == Ui::Choice && f.multiple);
      Element say = text(named ? f.label : "");
      if(named && f.alert) say = say | color(Color::Red);
      if(f.labelBefore && named) {
        parts.push_back(hbox({filler(), say}) | size(WIDTH, EQUAL, before));
        parts.push_back(text(" "));
      }
      parts.push_back(grows ? (what | flex) : what);
      for(std::size_t t = 0; t < f.trailing.size(); t++) {
        parts.push_back(text(" "));
        parts.push_back(Tui::button(f.trailing[t], me + "." + std::to_string(t),
                                    after));
      }
      if(!f.labelBefore && named) {
        parts.push_back(text(" "));
        parts.push_back(say);
      }
      return hbox(parts);
    }

    Element cellOf(const Ui::Item &item, bool column, int holds, bool &grows)
    {
      if(column && Ui::fills(item)) {
        grows = false;
        return render(item) | size(WIDTH, EQUAL, Tui::cells(12.));
      }
      if(item.kind == Ui::Item::ABox || item.kind == Ui::Item::ATabs) {
        grows = true;
        return render(item);
      }
      return cell(item.field, holds, grows);
    }

    // one line of cells for each row, or a box's rows on one grid
    Elements lines(const std::vector<std::vector<const Ui::Item *> > &rows,
                   int columns, bool flush)
    {
      Elements out;
      std::vector<Elements> grid;
      auto flushGrid = [&]() {
        if(grid.empty()) return;
        for(auto &r : grid)
          while((int)r.size() < 2 * columns - 1) r.push_back(text(""));
        out.push_back(gridbox(grid));
        grid.clear();
      };
      for(const auto &row : rows) {
        bool grows = false, spaced = false, others = false;
        int holds = 0;
        for(const Ui::Item *i : row) {
          if(Ui::fills(*i))
            grows = true;
          else if(!_gap(*i))
            others = true;
          if(_gap(*i)) spaced = true;
          if(i->kind == Ui::Item::AField) {
            const Ui::Field &f = i->field;
            if(f.kind != Ui::Label && f.kind != Ui::Spacer &&
               f.kind != Ui::Action && f.kind != Ui::List &&
               f.kind != Ui::Hierarchy && f.kind != Ui::Check &&
               f.kind != Ui::ColorMap && !(f.widthEm > 0.) &&
               !(f.widthShare > 0.))
              holds++;
          }
        }
        bool column = grows && others;
        Elements parts;
        std::vector<bool> partGrows;
        Elements run;
        bool said = false;
        auto endRun = [&]() {
          if(run.empty()) return;
          parts.push_back(hbox(run));
          partGrows.push_back(false);
          run.clear();
        };
        for(const Ui::Item *i : row) {
          bool g = false;
          Element one = cellOf(*i, column, holds, g);
          bool packed = i->kind == Ui::Item::AField && i->field.packed &&
                        !_gap(*i) && !i->field.disclosure;
          if(packed) {
            // flush only where it is one value split in two
            if(said) run.push_back(text(" "));
            said = !i->field.label.empty();
            run.push_back(one);
            continue;
          }
          said = false;
          endRun();
          parts.push_back(one);
          partGrows.push_back(spaced ? _gap(*i) : g);
        }
        endRun();
        if(columns > 1 && !grows) {
          Elements r;
          for(std::size_t k = 0; k < parts.size(); k++) {
            if(k) r.push_back(text(" "));
            r.push_back(parts[k]);
          }
          grid.push_back(r);
          continue;
        }
        flushGrid();
        Elements line;
        for(std::size_t k = 0; k < parts.size(); k++) {
          if(k && !flush) line.push_back(text(" "));
          line.push_back(partGrows[k] ? (parts[k] | flex) : parts[k]);
        }
        out.push_back(hbox(line));
      }
      flushGrid();
      return out;
    }

    Element render(const Ui::Item &item)
    {
      if(!_shown(item)) return text("");
      switch(item.kind) {
      case Ui::Item::ATabs: {
        const Ui::Tabs &t = *item.tabs;
        // the pane asked for, or the first
        std::size_t on = 0;
        for(std::size_t i = 0; i < t.tabs.size(); i++)
          if(t.tabs[i].first == state.pane) on = i;
        Elements row;
        for(std::size_t i = 0; i < t.tabs.size(); i++) {
          std::string label = t.tabs[i].first.size() ? t.tabs[i].first : "·";
          Element tab = text(" " + label + " ");
          if(i == on) tab = tab | inverted | bold;
          Tui::Hot h;
          Tui::FormState *st = &state;
          std::string name = t.tabs[i].first;
          std::function<void(const std::string &)> chosen = t.chosen;
          h.mouse = [st, name, chosen](Mouse &m, int, int) {
            if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
            bool moved = st->pane != name;
            st->pane = name;
            if(moved && chosen) Tui::later([chosen, name]() { chosen(name); });
            Tui::dirty();
            return true;
          };
          row.push_back(Tui::hot(tab, h));
        }
        // the panes are all made, so that the fields keep their numbers,
        // but only the one showing is shown
        Element shown;
        for(std::size_t i = 0; i < t.tabs.size(); i++) {
          Element pane = render(t.tabs[i].second);
          if(i == on) shown = pane;
        }
        return vbox({flexbox(row), separator(), shown ? shown : text("")});
      }
      case Ui::Item::AHeading: return text(item.text) | bold;
      case Ui::Item::ARule: return separator();
      case Ui::Item::AField:
        if(_gap(item)) return filler();
        return vbox(lines({{&item}}, 0, false));
      case Ui::Item::ABox: {
        const Ui::Box &b = *item.box;
        if(b.direction == Ui::Box::Across || b.grid) {
          std::vector<std::vector<const Ui::Item *> > rows;
          if(b.direction == Ui::Box::Across) {
            rows.emplace_back();
            for(const auto &i : b.items)
              if(_shown(i)) rows.back().push_back(&i);
          }
          else
            for(const auto &i : b.items) {
              if(!_shown(i)) continue;
              if(i.kind == Ui::Item::ABox &&
                 i.box->direction == Ui::Box::Across && !i.box->grid &&
                 !i.box->scrolling) {
                rows.emplace_back();
                for(const auto &j : i.box->items)
                  if(_shown(j)) rows.back().push_back(&j);
              }
              else
                rows.push_back({&i});
            }
          int columns = 0;
          if(b.grid)
            for(const auto &r : rows) columns = std::max(columns, (int)r.size());
          return vbox(lines(rows, b.grid ? std::max(1, columns) : 0,
                            b.padding == 0.));
        }
        Elements down;
        for(const auto &i : b.items) {
          if(!_shown(i)) continue;
          Element one = render(i);
          down.push_back(Ui::fills(i) || _gap(i) ? (one | flex) : one);
        }
        return vbox(down);
      }
      default: return text("");
      }
    }
  };

} // namespace

Element Tui::form(const Ui::Form &f, FormState &state)
{
  maker m(f, state);
  const Ui::Form *which = &f;
  // a change looks at the whole form again: at the next frame, which asks
  m.after = []() { Tui::dirty(); };
  (void)which;
  m.widest(f.content);
  return m.render(f.content);
}

#endif
