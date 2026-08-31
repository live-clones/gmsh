// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "GuiModules.h"
#include "GuiMenus.h"
#include "GuiOnelab.h"
#include "GuiDialogs.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshDefines.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif
#include "Context.h"
#include "Options.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

namespace Modules {

  namespace {

    // The tree, flattened: what is under each path, in the order it is drawn,
    // and what each path holds. It is built again when the shape changes, and
    // read as often as anyone likes -- what a node says is asked of the
    // description every time, not kept here.
    struct store {
      std::map<std::string, std::vector<std::string> > under;
      std::map<std::string, Ui::Node> nodes;
      // the branches whose lines are put in order by their name, which is how
      // a parameter says where it goes: the tree this reproduces sorts every
      // line, and the digits a parameter carries in front of its short name
      // are there for that
      std::set<std::string> sorted;
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

    // Every branch of a path exists, whether or not anything named it: a
    // parameter called "Solver/Steps" puts a "Solver" above itself.
    void _makeBranches(const std::string &path, store &s)
    {
      std::string::size_type cut = path.find_last_of('/');
      if(cut == std::string::npos) return;
      std::string parent = path.substr(0, cut);
      if(s.nodes.count(parent)) return;
      _makeBranches(parent, s);
      std::string::size_type above = parent.find_last_of('/');
      Ui::Node n;
      n.path = parent;
      n.label = above == std::string::npos ? parent : parent.substr(above + 1);
      s.under[above == std::string::npos ? "" : parent.substr(0, above)]
        .push_back(parent);
      s.nodes[parent] = n;
    }

    // What a parameter says of itself when the pointer rests on it, as the
    // tree this reproduces chooses it
    std::string _help(const onelab::parameter &p)
    {
      std::string help = p.getHelp();
      if(help.empty()) help = p.getLabel();
      if(help.empty()) help = p.getShortName();
      return help;
    }

    // What it asks to be drawn as, when it asks to be looked at: "1" is the
    // yellow the tree this reproduces uses, and anything else is a colour by
    // name. Zero is an ordinary line.
    unsigned int _highlight(const std::string &say)
    {
      if(say.empty()) return 0;
      int r = 255, g = 255, b = 0;
      if(say != "1" && !GetRGBForString(say.c_str(), r, g, b)) return 0;
      return CTX::instance()->packColor(r, g, b, 255);
    }

    // and the parameter itself, on the line its name gives it
    void _add(const std::string &name, const Ui::Field &f,
              const std::string &help, const std::string &highlight, store &s)
    {
      _makeBranches(name, s);
      Ui::Node n;
      n.path = name;
      n.hasField = true;
      n.field = f;
      n.tooltip = help;
      n.highlight = _highlight(highlight);
      std::string::size_type cut = name.find_last_of('/');
      std::string parent = cut == std::string::npos ? "" : name.substr(0, cut);
      s.under[parent].push_back(name);
      s.sorted.insert(parent);
      s.nodes[name] = n;
    }

    // A line under a branch the commands already made, which is where the
    // tree this reproduces puts them: the solvers under Solver and the views
    // under Post-processing.
    void _put(const std::string &path, const Ui::Node &n, store &s)
    {
      std::string::size_type cut = path.find_last_of('/');
      s.under[cut == std::string::npos ? "" : path.substr(0, cut)]
        .push_back(path);
      s.nodes[path] = n;
    }

    // The solvers that are registered: pressing one runs it, and what else
    // one may do to it is described beside the menus.
    void _solvers(store &s)
    {
#if defined(HAVE_ONELAB)
      for(int i = 0; i < NUM_SOLVERS; i++) {
        std::string name = opt_solver_name(i, GMSH_GET, "");
        if(name.empty()) continue;
        Ui::Node n;
        n.path = "0Modules/Solver/Solver" + std::to_string(i);
        n.label = name;
        n.tooltip = opt_solver_executable(i, GMSH_GET, "");
        n.pressed = [i]() { solverStart(i); };
        n.menu = [i]() { return Menu::solverActions(i); };
        _makeBranches(n.path, s);
        _put(n.path, n, s);
      }
#endif
    }

    // The post-processing views: a switch that shows or hides one, its name
    // beside it, and the menu of what to do to it. A view may say which group
    // it belongs to, which is a branch of its own.
    void _views(store &s)
    {
#if defined(HAVE_POST)
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        PViewOptions *opt = PView::list[i]->getOptions();
        std::string path = "0Modules/Post-processing/";
        if(opt->group.size()) path += opt->group + "/";
        path += "View" + std::to_string(i);
        _makeBranches(path, s);

        int index = (int)i;
        Ui::Node n;
        n.path = path;
        n.hasField = true;
        n.field.kind = Ui::Check;
        // the switch says nothing itself: the name beside it is the line,
        // and pressing the name is what opens the colour map
        n.label = "[" + std::to_string(index) + "] " +
                  PView::list[i]->getData()->getName();
        n.field.storeCategory = "View";
        n.field.storeName = "Visible";
        n.field.storeIndex = index;
        n.field.changed = []() { drawContext::global()->draw(); };
        // clicking the name opens the colour map of that view, which is a tab
        // of the option window rather than a window of its own
        n.pressed = [index]() { Dialog::showOptionsForView(index, "Map"); };
        n.menu = [index]() { return Menu::viewActions(index); };
        _put(path, n, s);
      }
#endif
    }

    // What a solver has published, under the commands: the tree of the
    // interface this reproduces holds both, and only one of them was ever
    // described.
    void _parameters(store &s)
    {
#if defined(HAVE_ONELAB)
      bool showInvisible = CTX::instance()->solver.showInvisibleParameters;
      auto wanted = [&](const onelab::parameter &p) {
        if(showInvisible) return true;
        if(!p.getVisible()) return false;
        // the templates of the per-entity window, which are its own
        return p.getName().find("ONELAB Context/") == std::string::npos;
      };

      std::vector<onelab::number> numbers;
      onelab::server::instance()->get(numbers);
      for(auto &p : numbers) {
        if(!wanted(p)) continue;
        std::string name = p.getName();
        _add(name,
             GuiOnelab::numberField(
               [name](onelab::number &q) {
                 std::vector<onelab::number> got;
                 onelab::server::instance()->get(got, name);
                 if(got.empty()) return false;
                 q = got[0];
                 return true;
               },
               p),
             _help(p), p.getAttribute("Highlight"), s);
      }

      std::vector<onelab::string> strings;
      onelab::server::instance()->get(strings);
      for(auto &p : strings) {
        if(!wanted(p)) continue;
        std::string name = p.getName();
        _add(name,
             GuiOnelab::stringField(
               [name](onelab::string &q) {
                 std::vector<onelab::string> got;
                 onelab::server::instance()->get(got, name);
                 if(got.empty()) return false;
                 q = got[0];
                 return true;
               },
               p),
             _help(p), p.getAttribute("Highlight"), s);
      }
#endif
    }

    void _build()
    {
      store &s = _store();
      unsigned now = Menu::generation() + _generation;
      if(s.ever && s.built == now) return;
      s.under.clear();
      s.nodes.clear();
      s.sorted.clear();
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
      _solvers(s);
      _views(s);
      _parameters(s);
      for(const auto &parent : s.sorted) {
        auto &lines = s.under[parent];
        std::sort(lines.begin(), lines.end());
      }
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
    // The row under it: what to run, what to forget, and the gear that says
    // what the solver may do by itself. The tree this reproduces has them at
    // the bottom, and one interface had three of the gear's thirteen entries
    // as buttons of its own instead.
    t.footer = []() {
      std::vector<Ui::Button> row;
#if defined(HAVE_ONELAB)
      std::string b0, b1;
      Gui::solverButtons(b0, b1);
      if(b1.empty()) b1 = "compute";
      if(b0.size()) {
        Ui::Button check;
        check.label = b0;
        check.action = [b0]() { onelabRun(b0); };
        row.push_back(check);
      }
      Ui::Button run;
      run.label = b1;
      run.action = [b1]() { onelabRun(b1); };
      row.push_back(run);
      Ui::Button reset;
      reset.label = "Reset";
      reset.tooltip = "Forget what the solver has published";
      reset.action = []() { onelabRun("reset"); };
      row.push_back(reset);
      Ui::Button gear;
      gear.label = "Options";
      gear.tooltip = "What the solver may do by itself";
      gear.menu = []() { return Menu::solverOptions(); };
      row.push_back(gear);
#endif
      return row;
    };
    return t;
  }

} // namespace Modules

#endif
