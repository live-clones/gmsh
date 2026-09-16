// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>

#include "Form.h"

namespace Ui {

  double Field::getNumber() const { return readNumber ? readNumber() : 0.; }
  void Field::setNumber(double v)
  {
    if(writeNumber) writeNumber(v);
  }
  std::string Field::getText() const { return readText ? readText() : ""; }
  void Field::setText(const std::string &v)
  {
    if(writeText) writeText(v);
  }
  bool Field::getFlag() const { return getNumber() != 0.; }
  void Field::setFlag(bool v) { setNumber(v ? 1. : 0.); }
  Colour Field::getColour() const { return readColour ? readColour() : Colour(); }
  void Field::setColour(Colour v)
  {
    if(writeColour) writeColour(v);
  }
  void Field::getVector(double &x, double &y, double &z) const
  {
    x = y = z = 0.;
    if(readVector) readVector(x, y, z);
  }
  void Field::setVector(double x, double y, double z)
  {
    if(writeVector) writeVector(x, y, z);
  }

  // --- the tree of a form, as the panes the interfaces read

  namespace {
    // the fields of one line or one cell, flagged the way the box shares them
    void _cells(const Box &b, std::vector<Field> &into, bool &first)
    {
      for(const Item &it : b.items) {
        if(it.kind == Item::ABox && it.box->direction == Box::Across) {
          _cells(*it.box, into, first);
          continue;
        }
        if(it.kind != Item::AField) continue;
        Field f = it.field;
        if(b.padding == 0.) f.packed = f.flush = true;
        f.sameRow = !first;
        first = false;
        into.push_back(f);
      }
    }

    // how many cells the widest line of a grid has
    int _widestRow(const Box &b)
    {
      int widest = 0;
      for(const Item &it : b.items)
        if(it.kind == Item::ABox && it.box->direction == Box::Across)
          widest = std::max(widest, (int)it.box->items.size());
      return widest;
    }

    // the lines of a box, one under another; a rule goes over the line that
    // follows it, or under the pane when nothing does
    void _lines(const Item &it, Pane &p, bool &rule)
    {
      switch(it.kind) {
      case Item::AField: {
        Box one;
        one.items.push_back(it);
        bool first = true;
        _cells(one, p.fields, first);
        if(rule) p.fields[p.fields.size() - 1].rule = true;
        rule = false;
      } break;
      case Item::ABox:
        if(it.box->direction == Box::Across) {
          std::size_t from = p.fields.size();
          bool first = true;
          _cells(*it.box, p.fields, first);
          if(rule && p.fields.size() > from) p.fields[from].rule = true;
          rule = false;
        }
        else if(it.box->visible) {
          Pane s;
          bool inner = false;
          for(const Item &i : it.box->items) _lines(i, s, inner);
          s.separatorAfter = inner;
          s.visible = it.box->visible;
          p.sections.push_back(s);
        }
        else {
          if(it.box->scrolling) p.scrolling = true;
          if(it.box->grid) p.columns = _widestRow(*it.box);
          for(const Item &i : it.box->items) _lines(i, p, rule);
        }
        break;
      case Item::AHeading: {
        Field f;
        f.kind = Label;
        f.heading = true;
        std::string text = it.text;
        f.readText = [text]() { return text; };
        f.rule = rule;
        rule = false;
        p.fields.push_back(f);
      } break;
      case Item::ARule: rule = true; break;
      default: break;
      }
    }

    Pane _pane(const Item &it, const std::string &label)
    {
      Pane p;
      p.label = label;
      bool rule = false;
      _lines(it, p, rule);
      p.separatorAfter = rule;
      return p;
    }

    bool _buttonRow(const Item &it)
    {
      if(it.kind != Item::ABox || it.box->direction != Box::Across) return false;
      for(const Item &i : it.box->items)
        if(i.kind != Item::AButton &&
           !(i.kind == Item::AField && i.field.kind == Spacer))
          return false;
      return true;
    }
  } // namespace

  void lower(Form &f)
  {
    if(f.content.kind == Item::Nothing) return;
    f.panes.clear();
    f.buttons.clear();
    f.tabbed = false;
    const Box *top = f.content.kind == Item::ABox ? f.content.box.get() : nullptr;
    if(!top || top->direction != Box::Down) {
      f.panes.push_back(_pane(f.content, ""));
      return;
    }
    // Under tabs a rule is a line of its pane; between stacked panes it is
    // the edge of one.
    Pane current;
    bool rule = false;
    auto close = [&]() {
      if(current.fields.empty() && current.sections.empty() && !rule) return;
      current.separatorAfter = rule;
      f.panes.push_back(current);
      current = Pane();
      rule = false;
    };
    for(const Item &it : top->items) {
      if(it.kind == Item::ATabs) {
        close();
        f.tabbed = true;
        for(const auto &t : it.tabs->tabs) {
          Pane p = _pane(t.second, t.first);
          if(it.tabs->chosen) {
            std::function<void(const std::string &)> chosen = it.tabs->chosen;
            std::string name = t.first;
            p.chosen = [chosen, name]() { chosen(name); };
          }
          f.panes.push_back(p);
        }
      }
      else if(_buttonRow(it)) {
        close();
        // the buttons before a gap stand apart, at the far left
        for(const Item &i : it.box->items) {
          if(i.kind == Item::AField)
            for(Button &b : f.buttons) b.apart = true;
          else
            f.buttons.push_back(i.button);
        }
      }
      else if(f.tabbed) {
        // fields after the tabs, whichever one is showing
        bool r = false;
        Pane foot;
        _lines(it, foot, r);
        f.footer.insert(f.footer.end(), foot.fields.begin(), foot.fields.end());
      }
      else if(it.kind == Item::ARule) {
        rule = true;
        close();
      }
      else if(it.kind == Item::ABox && it.box->direction == Box::Down &&
              it.box->grid) {
        close();
        _lines(it, current, rule);
        close();
      }
      else if(it.kind == Item::ABox && it.box->direction == Box::Down &&
              it.box->visible) {
        close();
        Pane p;
        bool r = false;
        for(const Item &i : it.box->items) _lines(i, p, r);
        p.separatorAfter = r;
        p.visible = it.box->visible;
        f.panes.push_back(p);
      }
      else
        _lines(it, current, rule);
    }
    close();
  }

  // --- raising and lowering one of the numbers a colour map is computed from

  void ColourMap::adjust(const Parameter &p, bool up) const
  {
    if(!parameter || !setParameter) return;
    double v = parameter(p.name);
    if(p.toggle) {
      setParameter(p.name, v != 0. ? 0. : 1.);
      return;
    }
    v += up ? p.step : -p.step;
    if(p.most > p.least) {
      if(p.wraps) {
        // past an end it comes back by a period, once
        if(v > p.most) v -= p.period;
        if(v < p.least) v += p.period;
      }
      else {
        if(v > p.most) v = p.most;
        if(v < p.least) v = p.least;
      }
    }
    setParameter(p.name, v);
  }

  // --- hue, saturation and value
  //
  // The hexcone, the hue running over six sectors; all three from 0 to 255.

  void toHsv(const Colour &c, int &h, int &s, int &v)
  {
    double r = c.r / 255., g = c.g / 255., b = c.b / 255.;
    double most = std::max(r, std::max(g, b));
    double least = std::min(r, std::min(g, b));
    double range = most - least;
    double hue = 0.;
    if(range > 0.) {
      if(most == r)
        hue = (g - b) / range;
      else if(most == g)
        hue = 2. + (b - r) / range;
      else
        hue = 4. + (r - g) / range;
      if(hue < 0.) hue += 6.;
    }
    h = (int)(hue / 6. * 255.);
    s = (int)((most > 0. ? range / most : 0.) * 255.);
    v = (int)(most * 255.);
  }

  Colour fromHsv(int h, int s, int v, unsigned char alpha)
  {
    double hue = 6. * h / 255., sat = s / 255., val = v / 255.;
    double r = val, g = val, b = val;
    if(sat > 0.) {
      if(hue >= 6.) hue = 0.;
      int sector = (int)hue;
      double f = hue - sector;
      double p = val * (1. - sat);
      double q = val * (1. - sat * f);
      double t = val * (1. - sat * (1. - f));
      switch(sector) {
      case 0: r = val; g = t; b = p; break;
      case 1: r = q; g = val; b = p; break;
      case 2: r = p; g = val; b = t; break;
      case 3: r = p; g = q; b = val; break;
      case 4: r = t; g = p; b = val; break;
      default: r = val; g = p; b = q; break;
      }
    }
    return Colour((unsigned char)(r * 255. + .5), (unsigned char)(g * 255. + .5),
                  (unsigned char)(b * 255. + .5), alpha);
  }


} // namespace Ui
