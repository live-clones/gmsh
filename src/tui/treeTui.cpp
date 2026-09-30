// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// A tree whose lines are fields (Tree.h): its lines, those of the branches
// open, in a scroll of its own; the modules, and a Hierarchy field.

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

// --- a tree: its lines, those of the branches open, in a scroll of its own

namespace {

  std::string _labelOf(const Ui::Node &node, const std::string &path)
  {
    if(node.label.size()) return node.label;
    std::size_t slash = path.find_last_of('/');
    return slash == std::string::npos ? path : path.substr(slash + 1);
  }

  void _lines(const Ui::Tree &t, treeTui &state, bool picks,
              const std::string &id, const std::string &parent, int depth,
              Elements &out, const std::function<void()> &after)
  {
    bool commands = tuiSources().settings().showModuleMenu;
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
        hotTui h;
        Ui::Tree tree = t;
        treeTui *st = &state;
        h.mouse = [tree, st, path](Mouse &m, int, int) {
          if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
          bool now = !st->open[path];
          st->open[path] = now;
          if(tree.setClosed) tree.setClosed(path, !now);
          tuiDirty();
          return true;
        };
        row.push_back(tuiHot(text(open ? "▾ " : "▸ "), h));
      }
      else
        row.push_back(text("  "));
      if(picks && node.pick) {
        bool on = node.picked && node.picked();
        hotTui h;
        std::function<void(bool)> pick = node.pick;
        h.mouse = [pick, on, after](Mouse &m, int, int) {
          if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
          pick(!on);
          if(after) tuiLater(after);
          tuiDirty();
          return true;
        };
        row.push_back(tuiHot(text(std::string(on ? "[x] " : "[ ] ") + label), h));
      }
      else if(!branch && node.hasField) {
        // the widget, the buttons after it, then its name (Ui::lineField)
        std::string fid = id + ":" + path, said;
        Ui::Field f = Ui::lineField(node, path, said);
        int width = f.kind == Ui::Check || f.kind == Ui::Action ? 0 : tuiCells(8.);
        row.push_back(tuiFieldWidget(f, fid, width, after));
        for(std::size_t k = 0; k < f.trailing.size(); k++)
          row.push_back(tuiButtonWidget(f.trailing[k],
                                        fid + ".b" + std::to_string(k), after));
        if(said.size()) {
          row.push_back(text(" "));
          Element name = text(said);
          if(node.pressed) {
            hotTui h;
            std::function<void()> what = node.pressed;
            h.mouse = [what, after](Mouse &m, int, int) {
              if(m.button != Mouse::Left || m.motion != Mouse::Pressed)
                return false;
              tuiLater([what, after]() {
                what();
                if(after) after();
              });
              return true;
            };
            name = tuiHot(name, h);
          }
          row.push_back(name);
        }
      }
      else {
        Element name = text(label);
        if(branch) {
          // a branch is opened by its name as well
          hotTui h;
          Ui::Tree tree = t;
          treeTui *st = &state;
          std::function<void()> what = node.pressed;
          h.mouse = [tree, st, path, what](Mouse &m, int, int) {
            if(m.button != Mouse::Left || m.motion != Mouse::Pressed)
              return false;
            if(what) {
              tuiLater(what);
              return true;
            }
            bool now = !st->open[path];
            st->open[path] = now;
            if(tree.setClosed) tree.setClosed(path, !now);
            tuiDirty();
            return true;
          };
          name = tuiHot(name, h);
        }
        else if(node.pressed) {
          hotTui h;
          std::function<void()> what = node.pressed;
          h.mouse = [what, after](Mouse &m, int, int) {
            if(m.button != Mouse::Left || m.motion != Mouse::Pressed) return false;
            tuiLater([what, after]() {
              what();
              if(after) after();
            });
            return true;
          };
          name = tuiHot(name, h);
        }
        row.push_back(name);
      }
      Element line = hbox(row);
      if(node.highlight.a)
        line = line | bgcolor(Color::RGB(node.highlight.r, node.highlight.g,
                                         node.highlight.b));
      if(!enabled) line = line | dim;
      if(node.menu) {
        hotTui h;
        std::function<std::vector<Ui::MenuItem>()> menu = node.menu;
        h.mouse = [menu](Mouse &m, int, int) {
          if(m.button != Mouse::Right || m.motion != Mouse::Pressed) return false;
          tuiPopupMenu(menu(), m.x, m.y + 1);
          return true;
        };
        line = tuiHot(line, h);
      }
      out.push_back(line);
      if(branch && state.open[path])
        _lines(t, state, picks, id, path, depth + 1, out, after);
    }
  }

} // namespace

Element tuiTree(const Ui::Tree &t, treeTui &state, bool picks,
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
  hotTui h;
  treeTui *st = &state;
  h.mouse = [st](Mouse &m, int, int) {
    if(m.button != Mouse::WheelUp && m.button != Mouse::WheelDown) return false;
    st->scroll += m.button == Mouse::WheelUp ? -3 : 3;
    if(st->scroll < 0) st->scroll = 0;
    tuiDirty();
    return true;
  };
  return tuiHot(e, h);
}
