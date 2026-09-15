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
#include "GuiActions.h"
#include "GuiDeclare.h"
#include "Gui.h"
#include "GmshDefines.h"
#include "drawContext.h"
#include "GModel.h"
#include "GEntity.h"

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

    // the tree, flattened: what is under each path, in the order it is drawn,
    // and what each path holds; built again when the shape changes, while
    // what a node says is asked of the description every time
    struct store {
      std::map<std::string, std::vector<std::string> > under;
      std::map<std::string, Ui::Node> nodes;
      // the branches whose lines are put in order by their name: the digits a
      // parameter carries in front of its short name are there for that
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

    // pressing the name of a group of views shows or hides every view of the
    // group; the group is what follows "Post-processing/" in the path
    std::function<void()> _toggleViews(const std::string &path)
    {
      const std::string root = "0Modules/Post-processing";
      if(path.compare(0, root.size(), root) != 0) return nullptr;
      std::string group = path.substr(root.size());
      while(group.size() && group[0] == '/') group = group.substr(1);
      return [group]() {
#if defined(HAVE_POST)
        for(std::size_t i = 0; i < PView::list.size(); i++) {
          PViewOptions *opt = PView::list[i]->getOptions();
          if(opt->group.find(group) == 0)
            opt_view_visible(i, GMSH_SET | GMSH_GUI, !opt->visible);
        }
        drawContext::global()->draw();
#endif
      };
    }

    // pressing the name of a physical group highlights its entities, or takes
    // the highlight off: a parameter published under "Physical group: <name>"
    // is about that group
    std::function<void()> _highlightGroup(const std::string &label)
    {
      const std::string mark = "Physical group: ";
      if(label.compare(0, mark.size(), mark) != 0) return nullptr;
      std::string group = label.substr(mark.size());
      return [group]() {
        if(group.empty()) return;
        GModel *m = GModel::current();
        int dim = -1, num = -1;
        if(group.find("Physical Point") != std::string::npos) {
          dim = 0;
          num = atoi(group.substr(15).c_str());
        }
        else if(group.find("Physical Curve") != std::string::npos) {
          dim = 1;
          num = atoi(group.substr(15).c_str());
        }
        else if(group.find("Physical Surface") != std::string::npos) {
          dim = 2;
          num = atoi(group.substr(17).c_str());
        }
        else if(group.find("Physical Volume") != std::string::npos) {
          dim = 3;
          num = atoi(group.substr(16).c_str());
        }
        else {
          for(dim = 3; dim >= 0; dim--) {
            num = m->getPhysicalNumber(dim, group);
            if(num > 0) break;
          }
        }
        if(dim < 0 || num < 0) return;
        std::map<int, std::vector<GEntity *> > groups;
        m->getPhysicalGroups(dim, groups);
        for(GEntity *e : groups[num]) {
          e->setVisibility(1);
          e->setSelection(e->getSelection() ? 0 : 2);
        }
        drawContext::global()->draw();
      };
    }

    // the commands are a list of MenuItem in GuiMenus.cpp; this is where the
    // list becomes a place in a tree
    void _flatten(const std::vector<Ui::MenuItem> &items,
                  const std::string &path, store &s)
    {
      for(const auto &it : items) {
        std::string here = path + "/" + it.label;
        Ui::Node n;
        n.path = here;
        n.label = it.label;
        if(it.kind == Ui::MenuItem::Submenu) {
          n.pressed = _toggleViews(here);
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
      n.pressed = _toggleViews(parent);
      if(!n.pressed) n.pressed = _highlightGroup(n.label);
      s.under[above == std::string::npos ? "" : parent.substr(0, above)]
        .push_back(parent);
      s.nodes[parent] = n;
    }

    // --- what is folded
    //
    // Three things say it: the branches the user folded by hand, the "Closed"
    // attribute of the parameters under a branch, and the closed flag of the
    // views under one.

    std::set<std::string> &_foldedByHand()
    {
      static std::set<std::string> folded;
      return folded;
    }

#if defined(HAVE_POST)
    std::string _viewBranch(std::size_t i)
    {
      PViewOptions *opt = PView::list[i]->getOptions();
      std::string path = "0Modules/Post-processing";
      if(opt->group.size()) path += "/" + opt->group;
      return path;
    }
#endif

    bool _closed(const std::string &path)
    {
      if(_foldedByHand().count(path)) return true;
#if defined(HAVE_ONELAB)
      std::vector<onelab::number> numbers;
      onelab::server::instance()->get(numbers);
      for(const auto &p : numbers)
        if(p.getPath() == path && p.getAttribute("Closed") == "1") return true;
      std::vector<onelab::string> strings;
      onelab::server::instance()->get(strings);
      for(const auto &p : strings)
        if(p.getPath() == path && p.getAttribute("Closed") == "1") return true;
#endif
#if defined(HAVE_POST)
      for(std::size_t i = 0; i < PView::list.size(); i++)
        if(_viewBranch(i) == path && PView::list[i]->getOptions()->closed)
          return true;
#endif
      return false;
    }

    template <class T>
    void _setClosedAttribute(const std::string &path, bool closed)
    {
#if defined(HAVE_ONELAB)
      std::vector<T> ps;
      onelab::server::instance()->get(ps);
      for(auto &p : ps) {
        if(p.getPath() != path) continue;
        p.setAttribute("Closed", closed ? "1" : "0");
        onelab::server::instance()->set(p);
      }
#endif
    }

    void _setClosed(const std::string &path, bool closed)
    {
      if(closed)
        _foldedByHand().insert(path);
      else
        _foldedByHand().erase(path);
#if defined(HAVE_ONELAB)
      _setClosedAttribute<onelab::number>(path, closed);
      _setClosedAttribute<onelab::string>(path, closed);
#endif
#if defined(HAVE_POST)
      for(std::size_t i = 0; i < PView::list.size(); i++)
        if(_viewBranch(i) == path)
          PView::list[i]->getOptions()->closed = closed ? 1 : 0;
#endif
    }

    // what a parameter says of itself when the pointer rests on it
    std::string _help(const onelab::parameter &p)
    {
      std::string help = p.getHelp();
      if(help.empty()) help = p.getLabel();
      if(help.empty()) help = p.getShortName();
      return help;
    }

    // what it asks to be drawn as, when it asks to be looked at: "1" is
    // yellow, anything else is a colour by name; an alpha of zero is an
    // ordinary line
    Ui::Colour _highlight(const std::string &say)
    {
      if(say.empty()) return Ui::Colour(0, 0, 0, 0);
      int r = 255, g = 255, b = 0;
      if(say != "1" && !GetRGBForString(say.c_str(), r, g, b))
        return Ui::Colour(0, 0, 0, 0);
      return Ui::Colour((unsigned char)r, (unsigned char)g, (unsigned char)b);
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

    // a line under a branch the commands already made: the solvers under
    // Solver and the views under Post-processing
    void _put(const std::string &path, const Ui::Node &n, store &s)
    {
      std::string::size_type cut = path.find_last_of('/');
      s.under[cut == std::string::npos ? "" : path.substr(0, cut)]
        .push_back(path);
      s.nodes[path] = n;
    }

    // the solvers that are registered: pressing one runs it
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

    // the post-processing views: a switch that shows or hides one, its name
    // beside it, and the menu of what to do to it; a view may say which group
    // it belongs to, which is a branch of its own
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
        Declare::bindOption(n.field, "View", "Visible", index);
        n.field.changed = []() { drawContext::global()->draw(); };
        // clicking the name opens the colour map of that view, which is a tab
        // of the option window rather than a window of its own
        n.pressed = [index]() { Gui::instance().options.showForView(index, "Map"); };
        n.menu = [index]() { return Menu::viewActions(index); };
        _put(path, n, s);
      }
#endif
    }

    // what a solver has published, under the commands
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

      // the root; the leading zero of its path is what puts the modules first
      // for an interface that sorts its lines
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
    t.closed = _closed;
    t.setClosed = _setClosed;
    // the row under it: what to run, what to forget, and the gear that says
    // what the solver may do by itself
    t.footer = []() {
      std::vector<Ui::Button> row;
#if defined(HAVE_ONELAB)
      // a solver may put a button of its own there in place of Check and Run
      std::vector<onelab::string> custom;
      onelab::server::instance()->get(custom, "ONELAB/Button");
      if(custom.size() && custom[0].getValues().size() == 2) {
        Ui::Button own;
        own.label = custom[0].getValues()[0];
        std::string does = custom[0].getValues()[1];
        own.action = [does]() { onelabRun(does); };
        row.push_back(own);
      }
      else {
        // what the two say: "check" and "compute" while nothing runs, "stop" or
        // "kill" once something does; Run only when there is something to run,
        // Check not when checking is automatic
        std::string b0, b1;
        Gui::instance().solverButtons(b0, b1);
        if(b1.empty()) b1 = "compute";
        bool anything = onelab::server::instance()->getNumClients() > 1;
        if(!anything) {
          std::vector<onelab::number> numbers;
          onelab::server::instance()->get(numbers);
          for(const auto &p : numbers)
            if(p.getVisible()) {
              anything = true;
              break;
            }
        }
        bool running = b1 == "stop" || b1 == "kill";
        if(b0.size() && !CTX::instance()->solver.autoCheck && !running) {
          Ui::Button check;
          check.label = "Check";
          check.action = [b0]() { onelabRun(b0); };
          row.push_back(check);
        }
        if(anything || running) {
          Ui::Button run;
          run.label = b1 == "stop" ? "Stop" : b1 == "kill" ? "Kill" : "Run";
          run.action = [b1]() { onelabRun(b1); };
          row.push_back(run);
        }
      }
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
