// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// A described form, made afresh at every frame, translated as the page
// translates it (render(), lines(), cellOf() and cell() of
// src/browser/page.html): a box down is its lines, one across a line -- an
// hbox, what grows flex_grow, a gap filler() -- a grid a gridbox, tabs a row
// of names over the pane showing.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include "tuiCommon.h"
#include "Layout.h" // Ui::fills()
#include "MapEditor.h"

using namespace ftxui;

// --- a form, as the page writes it

namespace {

  bool _gap(const Ui::Item &it)
  {
    return it.kind == Ui::Item::AField && it.field.kind == Ui::Spacer;
  }

  struct maker {
    const Ui::Form &form;
    dialogTui &state;
    int count = 0;
    // the names before their fields are one column, as wide as the widest
    int before = 0;
    std::function<void()> after;
    maker(const Ui::Form &f, dialogTui &s) : form(f), state(s) {}

    std::string id() { return form.id + "#" + std::to_string(count++); }

    void widest(const Ui::Item &it)
    {
      if(!Ui::shown(it)) return;
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
        wide = tuiCells(f.widthEm);
      else if(f.widthShare > 0.)
        wide = tuiCells(10. * f.widthShare);
      else if(value)
        wide = tuiCells(10. / std::max(1, holds));
      std::string me = id();
      if(f.kind == Ui::Label) {
        if(f.align != Ui::Left || f.wraps) grows = true;
        return tuiFieldWidget(f, me, wide, after);
      }
      if(f.kind == Ui::Check && f.disclosure) {
        grows = true;
        return hbox({filler(), tuiFieldWidget(f, me, 0, after)});
      }
      Element what = tuiFieldWidget(f, me, wide, after);
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
        parts.push_back(tuiButtonWidget(f.trailing[t], me + "." + std::to_string(t),
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
        return render(item) | size(WIDTH, EQUAL, tuiCells(12.));
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
      if(!Ui::shown(item)) return text("");
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
          hotTui h;
          dialogTui *st = &state;
          std::string name = t.tabs[i].first;
          std::function<void(const std::string &)> chosen = t.chosen;
          h.mouse = [st, name, chosen](Mouse &m, int, int) {
            if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
            bool moved = st->pane != name;
            st->pane = name;
            if(moved && chosen) tuiLater([chosen, name]() { chosen(name); });
            tuiDirty();
            return true;
          };
          row.push_back(tuiHot(tab, h));
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
              if(Ui::shown(i)) rows.back().push_back(&i);
          }
          else
            for(const auto &i : b.items) {
              if(!Ui::shown(i)) continue;
              if(i.kind == Ui::Item::ABox &&
                 i.box->direction == Ui::Box::Across && !i.box->grid &&
                 !i.box->scrolling) {
                rows.emplace_back();
                for(const auto &j : i.box->items)
                  if(Ui::shown(j)) rows.back().push_back(&j);
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
          if(!Ui::shown(i)) continue;
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

Element tuiForm(const Ui::Form &f, dialogTui &state)
{
  maker m(f, state);
  const Ui::Form *which = &f;
  // a change looks at the whole form again: at the next frame, which asks
  m.after = []() { tuiDirty(); };
  (void)which;
  m.widest(f.content);
  return m.render(f.content);
}
