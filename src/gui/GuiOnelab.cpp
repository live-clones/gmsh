// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The parameters a solver attached to one entity, instantiated from the
// templates "ONELAB Context/<Dim> Template/..." for the entity double-clicked;
// first, what a ONELAB parameter does when someone changes it.

#include "GmshConfig.h"

#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GuiOnelab.h"
#include "GmshMessage.h"
#include "GmshGlobal.h"
#include "GModel.h"
#include "GEntity.h"
#include "Context.h"
#include "OpenFile.h"
#include "StringUtils.h"
#include "drawContext.h"
#include "OS.h"
#include "CreateFile.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#include "onelabUtils.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_ONELAB)

// --- what a parameter does when it changes

namespace {

  bool _serverActionMatch(const std::string &action, const std::string &match)
  {
    std::vector<std::string> names;
    onelab::server::instance()->getParameterNames(names, match);

    for(auto &var : names) {
      Msg::Debug("Performing action '%s' on variable '%s'", action.c_str(),
                 var.c_str());
      if(action == "ResetMatch") { onelab::server::instance()->clear(var); }
      else {
        std::vector<onelab::string> ps;
        onelab::server::instance()->get(ps, var);
        if(ps.size()) {
          if(action == "HideMatch")
            ps[0].setVisible(false);
          else if(action == "ShowMatch")
            ps[0].setVisible(true);
          else if(action == "ReadOnlyMatch")
            ps[0].setReadOnly(true);
          else if(action == "ReadWriteMatch")
            ps[0].setReadOnly(false);
        }
        std::vector<onelab::number> pn;
        onelab::server::instance()->get(pn, var);
        if(pn.size()) {
          if(action == "HideMatch")
            pn[0].setVisible(false);
          else if(action == "ShowMatch")
            pn[0].setVisible(true);
          else if(action == "ReadOnlyMatch")
            pn[0].setReadOnly(true);
          else if(action == "ReadWriteMatch")
            pn[0].setReadOnly(false);
          onelab::server::instance()->set(pn[0]);
        }
      }
    }

    // don't rebuild the tree here: leave it to the normal event loop to
    // perform a "check" if necessary, once every change has been made
    return !names.empty();
  }

  bool _serverActionList(const std::string &path, const std::string &action,
                         const std::string &data)
  {
    std::vector<std::string> what = onelab::parameter::split(data, ',');

    if(action == "Set" && (what.size() < 2 || what.size() % 2)) {
      Msg::Warning("Bad data for ServerActionSet");
      return false;
    }

    for(std::size_t i = 0; i < what.size(); i++) {
      std::string var = onelab::parameter::trim(what[i]);
      // a name starting with '%' is taken relative to the parameter that
      // carries the attribute
      if(var.size() && var[0] == '%') {
        var.erase(0, 1);
        var = path + "/" + var;
      }
      Msg::Debug("Performing action '%s' on variable '%s'", action.c_str(),
                 var.c_str());
      if(action == "Reset") { onelab::server::instance()->clear(var); }
      else {
        std::string val;
        if(action == "Set") {
          val = onelab::parameter::trim(what[i + 1]);
          i++;
        }
        std::vector<onelab::string> ps;
        onelab::server::instance()->get(ps, var);
        if(ps.size()) {
          if(action == "Set")
            ps[0].setValue(val);
          else if(action == "Show")
            ps[0].setVisible(true);
          else if(action == "Hide")
            ps[0].setVisible(false);
          else if(action == "ReadOnly")
            ps[0].setReadOnly(true);
          else if(action == "ReadWrite")
            ps[0].setReadOnly(false);
          onelab::server::instance()->set(ps[0]);
        }
        std::vector<onelab::number> pn;
        onelab::server::instance()->get(pn, var);
        if(pn.size()) {
          if(action == "Set")
            pn[0].setValue(atof(val.c_str()));
          else if(action == "Show")
            pn[0].setVisible(true);
          else if(action == "Hide")
            pn[0].setVisible(false);
          else if(action == "ReadOnly")
            pn[0].setReadOnly(true);
          else if(action == "ReadWrite")
            pn[0].setReadOnly(false);
          onelab::server::instance()->set(pn[0]);
        }
      }
    }

    return true;
  }

  template <class T> void _setGmshOption(T &n)
  {
    std::string opt = n.getAttribute("GmshOption");
    if(opt.empty()) return;
    if(GuiOnelab::serverAction(opt)) return; // for backward compatibility
    std::string::size_type dot = opt.find('.');
    if(dot == std::string::npos) return;
    GmshSetOption(opt.substr(0, dot), opt.substr(dot + 1), n.getValue());
    drawContext::global()->draw();
  }

  template <class T> void _performServerAction(T &n)
  {
    if(n.getAttributes().empty()) return;

    // global unconditional actions, triggering a tree rebuild
    std::string action = n.getAttribute("ServerAction");
    if(action.size()) GuiOnelab::serverAction(action);

    // actions not triggering a tree rebuild (that should happen once every
    // parameter has been changed on the server side):

    // * actions using one variable or a list of variables
    std::vector<std::string> list = {"Reset", "Hide",     "Show",
                                     "Set",   "ReadOnly", "ReadWrite"};
    for(auto &a : list) {
      // global
      std::string data = n.getAttribute("ServerAction" + a);
      if(data.size()) _serverActionList(n.getPath(), a, data);
      // only for a given value
      data = n.getAttribute("ServerAction" + a + " " + n.getValueAsString());
      if(data.size()) _serverActionList(n.getPath(), a, data);
    }

    // * actions using a regex
    std::vector<std::string> regex = {"ResetMatch", "HideMatch", "ShowMatch",
                                      "ReadOnlyMatch", "ReadWriteMatch"};
    for(auto &a : regex) {
      // global
      std::string data = n.getAttribute("ServerAction" + a);
      if(data.size()) _serverActionMatch(a, data);
      // only for a given value
      data = n.getAttribute("ServerAction" + a + " " + n.getValueAsString());
      if(data.size()) _serverActionMatch(a, data);
    }
  }

  template <class T>
  void _autoCheck(const T &before, const T &after, bool force = false)
  {
    if(onelabUtils::getFirstComputationFlag()) {
      if(before.getValue() != after.getValue())
        onelabUtils::setFirstComputationFlag(false);
    }

    if((CTX::instance()->solver.autoCheck &&
        after.getAttribute("AutoCheck") != "0") ||
       after.getAttribute("AutoCheck") == "1") {
      if(force || before.getValue() != after.getValue())
        Gui::instance().onelabAction("check");
    }
  }

  template <class T> void _changed(const T &before, T &after, bool graphs)
  {
    _setGmshOption(after);
    _performServerAction(after);
    onelab::server::instance()->set(after);
    if(graphs) onelabUtils::updateGraphs();
    _autoCheck(before, after);
  }

} // namespace

namespace GuiOnelab {

  bool serverAction(const std::string &action)
  {
    if(action == "ResetDatabase") {
      // reset the onelab db
      onelabUtils::resetDb(false);
      Gui::instance().rebuildTree(false);
      return true;
    }
    else if(action == "Reset") {
      // reset the onelab db + views + models (except the current model)
      onelabUtils::resetDb(false);
#if defined(HAVE_POST)
      for(int i = PView::list.size() - 1; i >= 0; i--) delete PView::list[i];
#endif
      for(int i = GModel::list.size() - 1; i >= 0; i--)
        if(GModel::list[i] != GModel::current()) delete GModel::list[i];
      Gui::instance().rebuildTree(false);
      return true;
    }
    else if(!action.compare(0, 5, "Reset")) {
      // reset some variables
      std::vector<std::string> what =
        onelab::parameter::split(action.substr(5), ',');
      for(std::size_t i = 0; i < what.size(); i++) {
        std::string var = onelab::parameter::trim(what[i]);
        Msg::Debug("Clearing variable '%s'", var.c_str());
        onelab::server::instance()->clear(var);
      }
      Gui::instance().rebuildTree(false);
      return true;
    }
    return false;
  }

  void changed(const onelab::number &before, onelab::number &after, bool graphs)
  { _changed(before, after, graphs); }

  void changed(const onelab::string &before, onelab::string &after, bool graphs)
  { _changed(before, after, graphs); }

  void runMacro(onelab::string &p)
  {
    if(p.getAttribute("Macro") == "GmshParseString") {
      // parse the string directly
      ParseString(p.getValue());
    }
    else if(p.getAttribute("Macro") == "Action") {
      // set the ONELAB action, for custom interfaces
      onelab::string o("ONELAB/Action", p.getValue());
      o.setVisible(false);
      o.setNeverChanged(true);
      o.setAttribute("Persistent", "1");
      onelab::server::instance()->set(o);
      return; // otherwise the check below would set Action to "check"
    }
    else {
      // merge the file it names
      std::string tmp =
        FixRelativePath(GModel::current()->getFileName(), p.getValue());
      MergeFile(tmp);
    }
    _setGmshOption(p);
    _performServerAction(p);
    _autoCheck(p, p, true);
    drawContext::global()->draw();
  }

} // namespace GuiOnelab

#endif

// --- and the dialog itself

namespace {

#if defined(HAVE_ONELAB)

  std::string _dimName(int dim)
  {
    switch(dim) {
    case 0: return "Point";
    case 1: return "Curve";
    case 2: return "Surface";
    case 3: return "Volume";
    }
    return "";
  }

  std::string _help(const onelab::parameter &p)
  {
    std::string help = p.getHelp();
    if(help.empty()) help = p.getLabel();
    if(help.empty()) help = p.getShortName();
    return help;
  }

  void _trailing(const GuiOnelab::getNumber &get, const onelab::number &p,
                 Ui::Field &f);
  void _trailing(const GuiOnelab::getString &get, const onelab::string &p,
                 Ui::Field &f);

  // an enumeration, a check box, something read, or a value typed
  Ui::Field _numberField(const GuiOnelab::getNumber &get,
                         const onelab::number &p)
  {
    using namespace Ui;
    using namespace Declare;
    std::string label = p.getShortName();
    const std::vector<double> &choices = p.getChoices();
    Field f;

    if(p.getReadOnly()) {
      f = output(label, [get]() {
        onelab::number q;
        return get(q) ? q.getValueAsString() : std::string();
      });
    }
    else if(choices.size() && choices.size() == p.getValueLabels().size()) {
      // the choice stands for the place of the value in the list: a value that
      // is not a whole number would not survive being carried as one
      f = choice(
            label,
            [get]() -> double {
              onelab::number q;
              if(!get(q)) return 0.;
              const std::vector<double> &c = q.getChoices();
              for(std::size_t k = 0; k < c.size(); k++)
                if(c[k] == q.getValue()) return (double)k;
              return 0.;
            },
            [get](double v) {
              onelab::number q;
              if(!get(q)) return;
              const std::vector<double> &c = q.getChoices();
              int k = (int)v;
              if(k < 0 || k >= (int)c.size()) return;
              onelab::number before = q;
              q.setValue(c[k]);
              GuiOnelab::changed(before, q);
            })
            .offering([get](std::vector<std::string> &labels,
                            std::vector<int> &values) {
              onelab::number q;
              if(!get(q)) return;
              const std::map<double, std::string> &named = q.getValueLabels();
              const std::vector<double> &c = q.getChoices();
              for(std::size_t k = 0; k < c.size(); k++) {
                auto it = named.find(c[k]);
                labels.push_back(it != named.end() ? it->second :
                                                     std::to_string(c[k]));
                values.push_back((int)k);
              }
            });
    }
    else {
      auto value = [get]() -> double {
        onelab::number q;
        return get(q) ? q.getValue() : 0.;
      };
      auto set = [get](double v) {
        onelab::number q;
        if(!get(q)) return;
        onelab::number before = q;
        q.setValue(v);
        GuiOnelab::changed(before, q);
      };
      if(choices.size() == 2 && choices[0] == 0. && choices[1] == 1.)
        f = check(
          label, [value]() { return value() != 0.; },
          [set](bool on) { set(on ? 1. : 0.); });
      else {
        // acted upon once, not once per letter typed
        bool bounded = p.getMax() > p.getMin() &&
                       p.getMin() != -onelab::parameter::maxNumber() &&
                       p.getMax() != onelab::parameter::maxNumber();
        f = number(label, value, set)
              .within(bounded ? p.getMin() : 0., bounded ? p.getMax() : 0.,
                      p.getStep())
              .whenDone();
        _trailing(get, p, f);
      }
    }
    return f;
  }

  // "min : max", "min : max : step", or the values it may take
  std::string _rangeSays(const onelab::number &p)
  {
    std::ostringstream say;
    say.precision(12);
    const std::vector<double> &choices = p.getChoices();
    if(choices.size()) {
      for(std::size_t i = 0; i < choices.size(); i++) {
        if(i) say << ", ";
        say << choices[i];
      }
    }
    else if(p.getMin() != -onelab::parameter::maxNumber() &&
            p.getMax() != onelab::parameter::maxNumber()) {
      say << p.getMin() << " : " << p.getMax();
      if(p.getStep()) say << " : " << p.getStep();
    }
    return say.str();
  }

  void _rangeHeard(const std::string &said, onelab::number &p)
  {
    if(said.find(',') != std::string::npos) {
      std::vector<double> choices;
      for(auto &v : onelab::parameter::split(said, ','))
        choices.push_back(atof(v.c_str()));
      p.setChoices(choices);
      p.setStep(0.);
      return;
    }
    std::vector<std::string> part = onelab::parameter::split(said, ':');
    if(part.size() < 2) return;
    p.setChoices(std::vector<double>());
    p.setMin(atof(part[0].c_str()));
    p.setMax(atof(part[1].c_str()));
    p.setStep(part.size() > 2 ? atof(part[2].c_str()) : 0.);
  }

  // nine places, four slots each: a string of thirty-six characters, one per
  // slot
  const char *const _graphPlaces[] = {
    "Top Left", "Top Right", "Bottom Left", "Bottom Right", "Top",
    "Bottom",   "Left",      "Right",       "Full"};
  const char *const _graphSlots[] = {"X ", "Y ", "X ' ", "Y ' "};

  void _trailing(const GuiOnelab::getNumber &get, const onelab::number &p,
                 Ui::Field &f)
  {
    bool readOnlyRange = p.getAttribute("ReadOnlyRange") == "1";

    Ui::Button range;
    range.label = ":";
    range.tooltip =
      readOnlyRange ? "Show range or choices" : "Edit range or choices";
    range.action = [get, readOnlyRange]() {
      onelab::number q;
      if(!get(q)) return;
      std::string said = _rangeSays(q);
      if(readOnlyRange) {
        Gui::instance().inputDialog("Range or choices", said, "", true);
        return;
      }
      if(!Gui::instance().inputDialog(
           "Edit range or choices", said,
           "[min : max], [min : max : step], or [val1, val2, ...]"))
        return;
      onelab::number before = q;
      _rangeHeard(said, q);
      GuiOnelab::changed(before, q);
    };
    f.trailing.push_back(range);

    Ui::Button loop;
    loop.glyph = "rotate";
    loop.tooltip = "Loop over range or choices (loop level 1, 2 or 3)";
    loop.on = [get]() {
      onelab::number q;
      if(!get(q)) return 0;
      return atoi(q.getAttribute("Loop").c_str());
    };
    loop.action = [get]() {
      onelab::number q;
      if(!get(q)) return;
      int level = atoi(q.getAttribute("Loop").c_str());
      onelab::number before = q;
      q.setAttribute("Loop", std::to_string(level >= 3 ? 0 : level + 1));
      GuiOnelab::changed(before, q);
    };
    f.trailing.push_back(loop);

    Ui::Button graph;
    graph.glyph = "graph";
    graph.tooltip = "Draw range or choices on X-Y graph(s)";
    graph.menu = [get]() {
      std::vector<Ui::MenuItem> menu;
      onelab::number q;
      if(!get(q)) return menu;
      std::string on = q.getAttribute("Graph");
      on.resize(36, '0');
      auto flip = [get](int slot) {
        onelab::number q;
        if(!get(q)) return;
        std::string on = q.getAttribute("Graph");
        on.resize(36, '0');
        on[slot] = on[slot] == '0' ? '3' : '0';
        onelab::number before = q;
        q.setAttribute("Graph", on);
        GuiOnelab::changed(before, q);
      };
      for(int place = 0; place < 9; place++) {
        Ui::MenuItem where;
        where.kind = Ui::MenuItem::Submenu;
        where.label = _graphPlaces[place];
        for(int slot = 0; slot < 4; slot++) {
          int which = place * 4 + slot;
          Ui::MenuItem it;
          it.kind = Ui::MenuItem::Toggle;
          it.label = _graphSlots[slot];
          it.checked = [get, which]() {
            onelab::number q;
            if(!get(q)) return false;
            std::string on = q.getAttribute("Graph");
            on.resize(36, '0');
            return on[which] != '0';
          };
          it.action = [flip, which]() { flip(which); };
          where.children.push_back(it);
        }
        menu.push_back(where);
      }
      Ui::MenuItem none;
      none.label = "None";
      none.action = [get]() {
        onelab::number q;
        if(!get(q)) return;
        onelab::number before = q;
        q.setAttribute("Graph", std::string(36, '0'));
        GuiOnelab::changed(before, q);
      };
      menu.push_back(none);
      return menu;
    };
    f.trailing.push_back(graph);
  }

  void _write(const GuiOnelab::getString &get, const std::string &v)
  {
    onelab::string q;
    if(!get(q)) return;
    onelab::string before = q;
    q.setValue(v);
    GuiOnelab::changed(before, q);
  }

  void _trailing(const GuiOnelab::getString &get, const onelab::string &p,
                 Ui::Field &f)
  {
    std::string many = p.getAttribute("MultipleSelection");
    if(p.getKind() == "file") {
      Ui::Button b;
      bool readOnly = p.getReadOnly();
      b.tooltip = "What to do with this file";
      b.menu = [get, readOnly]() {
        std::vector<Ui::MenuItem> menu;
        onelab::string q;
        if(!get(q)) return menu;
        std::string name = q.getValue();
        if(!readOnly) {
          Ui::MenuItem choose;
          choose.label = "Choose File...";
          choose.action = [get]() {
            onelab::string q;
            if(!get(q)) return;
            std::string name = q.getValue();
            if(Gui::instance().fileDialog(0, "Choose", "", name))
              _write(get, name);
          };
          menu.push_back(choose);
        }
        Ui::MenuItem edit;
        edit.label = "Edit Selected File...";
        edit.action = [name]() {
          std::string prog = FixWindowsPath(CTX::instance()->editor);
          SystemCall(ReplaceSubString("%s", FixWindowsPath(name), prog));
        };
        menu.push_back(edit);
        if(GuessFileFormatFromFileName(name) >= 0) {
          Ui::MenuItem merge;
          merge.label = "Merge Selected File...";
          merge.action = [name]() {
            MergeFile(FixWindowsPath(name));
            drawContext::global()->draw();
          };
          menu.push_back(merge);
        }
        return menu;
      };
      f.trailing.push_back(b);
      return;
    }
    if(many.size()) {
      // several choices at once: the value is what is on, comma separated
      Ui::Button b;
      b.tooltip = "Which of them are on";
      b.menu = [get]() {
        std::vector<Ui::MenuItem> menu;
        onelab::string q;
        if(!get(q)) return menu;
        std::vector<std::string> on =
          onelab::parameter::split(q.getValue(), ',');
        auto isOn = [on](const std::string &c) {
          for(auto &o : on) {
            std::string t = o;
            while(t.size() && t[0] == ' ') t.erase(0, 1);
            while(t.size() && t[t.size() - 1] == ' ') t.erase(t.size() - 1);
            if(t == c) return true;
          }
          return false;
        };
        auto say = [get](const std::vector<std::string> &chosen) {
          std::string v;
          for(auto &c : chosen) {
            if(v.size()) v += ", ";
            v += c;
          }
          _write(get, v);
        };
        std::vector<std::string> choices = q.getChoices();
        for(auto &c : choices) {
          Ui::MenuItem it;
          it.kind = Ui::MenuItem::Toggle;
          it.label = c;
          it.checked = [isOn, c]() { return isOn(c); };
          it.action = [get, choices, isOn, say, c]() {
            std::vector<std::string> chosen;
            for(auto &other : choices)
              if(other == c ? !isOn(c) : isOn(other)) chosen.push_back(other);
            say(chosen);
          };
          menu.push_back(it);
        }
        if(menu.size()) menu.back().dividerAfter = true;
        Ui::MenuItem all;
        all.label = "Select All";
        all.action = [choices, say]() { say(choices); };
        menu.push_back(all);
        Ui::MenuItem none;
        none.label = "Select None";
        none.action = [say]() { say(std::vector<std::string>()); };
        menu.push_back(none);
        return menu;
      };
      f.trailing.push_back(b);
    }
  }

  // a button for a macro, something read, or a value typed with what one may
  // want to type behind an arrow
  Ui::Field _stringField(const GuiOnelab::getString &get,
                         const onelab::string &p)
  {
    using namespace Ui;
    using namespace Declare;
    std::string label = p.getShortName();
    std::string macro = p.getAttribute("Macro");
    if(macro == "Gmsh" || macro == "GmshMergeFile" ||
       macro == "GmshParseString" || macro == "Action") {
      return button(label, [get]() {
        onelab::string q;
        if(get(q)) GuiOnelab::runMacro(q);
      });
    }
    if(p.getReadOnly() && p.getKind() != "file") {
      return output(label, [get]() {
        onelab::string q;
        return get(q) ? q.getValue() : std::string();
      });
    }
    Field f = text(
      label,
      [get]() {
        onelab::string q;
        return get(q) ? q.getValue() : std::string();
      },
      [get](const std::string &v) {
        onelab::string q;
        if(!get(q)) return;
        onelab::string before = q;
        q.setValue(v);
        GuiOnelab::changed(before, q);
      });
    if(p.getChoices().size())
      f.offering([get](std::vector<std::string> &labels, std::vector<int> &) {
        onelab::string q;
        if(!get(q)) return;
        for(auto &c : q.getChoices()) labels.push_back(c);
      });
    f.whenDone();
    _trailing(get, p, f);
    return f;
  }

  // the "Aspect" attribute: a line of its own, or shared with the two beside it
  bool _startsRow(const onelab::parameter &p)
  {
    std::string aspect = p.getAttribute("Aspect");
    return aspect.find("Middle") == std::string::npos &&
           aspect.find("Right") == std::string::npos;
  }

#endif

} // namespace

namespace GuiOnelab {

  Ui::Field numberField(const getNumber &get, const onelab::number &p)
  {
#if defined(HAVE_ONELAB)
    return _numberField(get, p);
#else
    return Ui::Field();
#endif
  }

  Ui::Field stringField(const getString &get, const onelab::string &p)
  {
#if defined(HAVE_ONELAB)
    return _stringField(get, p);
#else
    return Ui::Field();
#endif
  }

} // namespace GuiOnelab

using namespace Ui;
using namespace Declare;

#if defined(HAVE_ONELAB)

void GuiOnelabContext::look()
{
  groups.clear();
  groupEntities.clear();
  GEntity *e = GModel::current()->getEntityByTag(dim, tag);
  if(!e) return;
  std::map<int, std::vector<GEntity *>> found;
  GModel::current()->getPhysicalGroups(dim, found);
  for(auto &p : e->physicals) {
    int n = std::abs(p); // it can be negative, to turn the orientation round
    groups.push_back(
      std::make_pair(n, GModel::current()->getPhysicalName(dim, n)));
    groupEntities.push_back(found[n]);
  }
}

void GuiOnelabContext::entries(std::vector<std::string> &labels,
                               std::vector<int> &values)
{
  if(dim < 0 || dim > 3) return;
  std::string label = _dimName(dim) + " " + std::to_string(tag);
  std::string name = GModel::current()->getElementaryName(dim, tag);
  if(name.size()) label += ": " + name;
  labels.push_back(label);
  values.push_back(0);
  for(std::size_t i = 0; i < groups.size(); i++) {
    std::string l =
      "Physical " + _dimName(dim) + " " + std::to_string(groups[i].first);
    if(groups[i].second.size()) l += ": " + groups[i].second;
    labels.push_back(l);
    values.push_back((int)i + 1);
  }
}

void GuiOnelabContext::highlight()
{
  GEntity *e = GModel::current()->getEntityByTag(dim, tag);
  if(!e) return;
  GModel::current()->setSelection(0);
  if(which == 0) {
    e->setVisibility(1);
    e->setSelection(2);
  }
  else if(which - 1 < (int)groupEntities.size()) {
    for(auto g : groupEntities[which - 1]) {
      g->setVisibility(1);
      g->setSelection(2);
    }
  }
  drawContext::global()->draw();
}

// made from the templates when not on the server yet, sorted by name
void GuiOnelabContext::instantiate()
{
  names.clear();
  if(dim < 0 || dim > 3) return;
  bool physical = (which > 0 && which - 1 < (int)groups.size());
  onelabContextInstantiate(dim, tag, physical,
                           physical ? groups[which - 1].first : 0, names);
  std::sort(names.begin(), names.end());
}

bool GuiOnelabContext::number(int i, onelab::number &p)
{
  if(i < 0 || i >= (int)names.size()) return false;
  std::vector<onelab::number> pn;
  onelab::server::instance()->get(pn, names[i]);
  if(pn.empty()) return false;
  p = pn[0];
  return true;
}

bool GuiOnelabContext::string(int i, onelab::string &p)
{
  if(i < 0 || i >= (int)names.size()) return false;
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps, names[i]);
  if(ps.empty()) return false;
  p = ps[0];
  return true;
}

#endif

Form GuiOnelabContext::build()
{
#if defined(HAVE_ONELAB)
  instantiate();
  // as wide as the window: it holds the name of a physical group
  std::vector<Item> lines = {
    choice("", &which)
      .offering([this](std::vector<std::string> &labels,
                       std::vector<int> &values) { entries(labels, values); })
      .sized(24.)
      .onChanged([this]() {
        highlight();
        rebuild();
        if(CTX::instance()->solver.autoCheck)
          Gui::instance().onelabAction("check");
      })};
  std::vector<std::vector<Item>> rows;
  for(std::size_t i = 0; i < names.size(); i++) {
    Ui::Field f;
    bool starts = true;
    onelab::number pn;
    onelab::string ps;
    if(number((int)i, pn)) {
      if(!pn.getVisible()) continue;
      f = _numberField(
            [this, i](onelab::number &q) { return number((int)i, q); }, pn)
            .tip(_help(pn));
      if(pn.getAttribute("Highlight").size()) f.warns();
      starts = _startsRow(pn);
    }
    else if(string((int)i, ps)) {
      if(!ps.getVisible()) continue;
      f = _stringField(
            [this, i](onelab::string &q) { return string((int)i, q); }, ps)
            .tip(_help(ps));
      if(ps.getAttribute("Highlight").size()) f.warns();
      starts = _startsRow(ps);
    }
    else
      continue;
    if(starts || rows.empty()) rows.push_back({});
    rows.back().push_back(f);
  }
  for(const auto &row : rows)
    lines.push_back(row.size() == 1 ? row[0] : Item(hbox(row)));
  if(rows.empty()) lines.push_back(label("No parameters"));
  Form f = {"onelabContext", "Parameters", vbox(lines)};
  f.closed = []() {
    GModel::current()->setSelection(0);
    drawContext::global()->draw();
  };
  return f;
#else
  return {"onelabContext", "Parameters",
          label("Gmsh was compiled without ONELAB support")};
#endif
}

void GuiOnelabContext::show(int dim_, int tag_)
{
#if defined(HAVE_ONELAB)
  dim = dim_;
  tag = tag_;
  look();
  // the last physical group, or the entity itself when in none
  which = (int)groups.size();
  instantiate();
  highlight();
#endif
  show();
}
