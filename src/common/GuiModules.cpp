// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <map>
#include <string>
#include <vector>

#include "GuiModules.h"
#include "GuiMenus.h"

namespace Modules {

  namespace {

    // The tree, flattened: what is under each path, in the order it is drawn,
    // and what each path holds. It is built again when the shape changes, and
    // read as often as anyone likes -- what a node says is asked of the
    // description every time, not kept here.
    struct store {
      std::map<std::string, std::vector<std::string> > under;
      std::map<std::string, Ui::Node> nodes;
      unsigned built = 0;
      bool ever = false;
    };

    store &_store()
    {
      static store s;
      return s;
    }

    unsigned _generation = 1;

    // The commands are still written as a list of Menu::Item in GuiMenus.cpp,
    // which is a description like any other; this is where it stops being a
    // list and becomes a place in a tree.
    void _flatten(const std::vector<Ui::MenuItem> &items,
                  const std::string &path, store &s)
    {
      for(const auto &it : items) {
        std::string here = path + "/" + it.label;
        Ui::Node n;
        n.path = here;
        n.label = it.label;
        if(it.kind == Ui::MenuItem::Submenu) {
          s.under[path].push_back(here);
          s.nodes[here] = n;
          _flatten(it.children, here, s);
          continue;
        }
        // a line one presses rather than unfolds
        n.pressed = it.action;
        n.enabled = it.enabled;
        s.under[path].push_back(here);
        s.nodes[here] = n;
      }
    }

    void _build()
    {
      store &s = _store();
      unsigned now = Menu::generation() + _generation;
      if(s.ever && s.built == now) return;
      s.under.clear();
      s.nodes.clear();
      s.built = now;
      s.ever = true;

      // The root, whose path keeps the leading zero it has always had: the
      // FLTK tree sorts its lines and that is what puts the modules first.
      // Once nothing sorts, the zero can go.
      Ui::Node root;
      root.path = "0Modules";
      root.label = "Modules";
      s.under[""].push_back(root.path);
      s.nodes[root.path] = root;

      _flatten(Menu::modules(), root.path, s);
    }

  } // namespace

  void invalidate() { _generation++; }

  Ui::Tree tree()
  {
    Ui::Tree t;
    t.children = [](const std::string &parent) {
      _build();
      auto it = _store().under.find(parent);
      return it == _store().under.end() ? std::vector<std::string>() :
                                          it->second;
    };
    t.node = [](const std::string &path) {
      _build();
      auto it = _store().nodes.find(path);
      return it == _store().nodes.end() ? Ui::Node() : it->second;
    };
    t.generation = []() { return Menu::generation() + _generation; };
    return t;
  }

} // namespace Modules

#endif
