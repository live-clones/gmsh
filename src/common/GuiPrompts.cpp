// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The three little windows that ask for one thing: the counterpart of the
// choosers of src/fltk/extraDialogs.cpp, described once and built by both
// interfaces. They used to be windows the FLTK interface pumped its own event
// loop in, which is why the Dear ImGui one had none of them -- the arrow
// editor was a TODO, and the pattern and the command were plain text prompts
// with no memory of what had been typed before.
//
// They are ordinary dialogs here rather than modal windows: the value applies
// as it is given, so there is nothing to wait for, and a window one cannot
// leave to look at what it changed is a window that answers its own question
// badly.

#include "GmshConfig.h"

#include <algorithm>
#include <string>
#include <vector>

#include "GuiDialogs.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

namespace {

  // --- one option, asked for on its own

  struct optionState {
    std::string category, name, title, applyTo;
    int index = 0;
    double minimum = 0., maximum = 0., step = 0.;
  };

  optionState &_option()
  {
    static optionState state;
    return state;
  }

  // The value has just been given: it belongs to one view, and the menu entry
  // that asked for it means every view that is drawn. The window this
  // reproduces copies it over once the window is closed; doing it at every
  // change is the same thing, seen sooner.
  void _optionApplied()
  {
    optionState &s = _option();
    drawContext::global()->draw();
#if defined(HAVE_POST)
    if(s.applyTo != "view") return;
    double v = 0.;
    if(!NumberOption(GMSH_GET, s.category.c_str(), s.index, s.name.c_str(), v,
                     false))
      return;
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if((int)i != s.index && opt_view_visible(i, GMSH_GET, 0))
        NumberOption(GMSH_SET | GMSH_GUI, "View", (int)i, s.name.c_str(), v,
                     false);
    drawContext::global()->draw();
#endif
  }

  // and back to what Gmsh was built with
  void _optionDefault()
  {
    optionState &s = _option();
    double v = 0.;
    if(!NumberOption(GMSH_GET_DEFAULT, s.category.c_str(), s.index,
                     s.name.c_str(), v, false))
      return;
    NumberOption(GMSH_SET | GMSH_GUI, s.category.c_str(), s.index,
                 s.name.c_str(), v, false);
    _optionApplied();
  }

  // --- the shape of an arrow

  struct arrowState {
    double head = 0., stem = 0., radius = 0.;
    bool read = false;
  };

  arrowState &_arrow()
  {
    static arrowState state;
    return state;
  }

  void _arrowRead()
  {
    arrowState &a = _arrow();
    a.head = opt_general_arrow_head_radius(0, GMSH_GET, 0);
    a.stem = opt_general_arrow_stem_length(0, GMSH_GET, 0);
    a.radius = opt_general_arrow_stem_radius(0, GMSH_GET, 0);
    a.read = true;
  }

  // Apply rather than close: the window this reproduces hands the three
  // numbers back and is asked again, so that one may try a shape, look at it,
  // and try another without opening it afresh.
  void _arrowApply()
  {
    arrowState &a = _arrow();
    opt_general_arrow_head_radius(0, GMSH_SET | GMSH_GUI, a.head);
    opt_general_arrow_stem_length(0, GMSH_SET | GMSH_GUI, a.stem);
    opt_general_arrow_stem_radius(0, GMSH_SET | GMSH_GUI, a.radius);
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
  }

  // --- a command, with the ones given before it

  struct historyState {
    // "connection" for the remote solver, "pattern" for the files to watch
    std::string kind;
    std::string title, label, okLabel, fallback;
    std::string command;
    std::vector<std::string> before;
    bool read = false;
  };

  historyState &_history()
  {
    static historyState state;
    return state;
  }

  // Where the commands given before are kept. The window this reproduces used
  // Fl_Preferences, which is FLTK's; a file of our own beside the session file
  // is what both interfaces can read. One line per entry, the most recent
  // first, under a line naming which list it is.
  std::string _historyFile()
  {
    return CTX::instance()->homeDir + ".gmsh-history";
  }

  void _historyRead()
  {
    historyState &h = _history();
    h.before.clear();
    FILE *fp = Fopen(_historyFile().c_str(), "r");
    if(fp) {
      char line[4096];
      std::string in;
      while(fgets(line, sizeof(line), fp)) {
        std::string s(line);
        while(s.size() && (s.back() == '\n' || s.back() == '\r')) s.pop_back();
        if(s.size() && s[0] == '[') {
          in = s.substr(1, s.size() - 2);
          continue;
        }
        if(in == h.kind && s.size() && h.before.size() < 100)
          h.before.push_back(s);
      }
      fclose(fp);
    }
    h.command = h.before.size() ? h.before[0] : h.fallback;
    h.read = true;
  }

  // Written back whole: the file holds both lists, and only one of them is in
  // memory, so the other has to be carried over.
  void _historyWrite()
  {
    historyState &h = _history();
    std::vector<std::pair<std::string, std::vector<std::string> > > lists;
    FILE *fp = Fopen(_historyFile().c_str(), "r");
    if(fp) {
      char line[4096];
      while(fgets(line, sizeof(line), fp)) {
        std::string s(line);
        while(s.size() && (s.back() == '\n' || s.back() == '\r')) s.pop_back();
        if(s.size() && s[0] == '[') {
          lists.push_back(std::make_pair(s.substr(1, s.size() - 2),
                                         std::vector<std::string>()));
          continue;
        }
        if(s.size() && lists.size()) lists.back().second.push_back(s);
      }
      fclose(fp);
    }
    bool found = false;
    for(auto &l : lists)
      if(l.first == h.kind) {
        l.second = h.before;
        found = true;
      }
    if(!found) lists.push_back(std::make_pair(h.kind, h.before));

    fp = Fopen(_historyFile().c_str(), "w");
    if(!fp) return;
    for(const auto &l : lists) {
      fprintf(fp, "[%s]\n", l.first.c_str());
      for(const auto &e : l.second) fprintf(fp, "%s\n", e.c_str());
    }
    fclose(fp);
  }

  // the command that was just used goes to the top of the list
  void _historyKeep()
  {
    historyState &h = _history();
    if(h.command.empty()) return;
    h.before.erase(std::remove(h.before.begin(), h.before.end(), h.command),
                   h.before.end());
    h.before.insert(h.before.begin(), h.command);
    if(h.before.size() > 100) h.before.resize(100);
    _historyWrite();
  }

  void _historyRun()
  {
    historyState &h = _history();
    _historyKeep();
    Gui::showDialog(Dialog::History, false);
    if(h.kind == "pattern") {
      CTX::instance()->watchFilePattern = h.command;
      watchFiles();
    }
    else
      remoteAction("start", h.command);
  }

  void _historyShow(const std::string &kind, const std::string &title,
                    const std::string &label, const std::string &okLabel,
                    const std::string &fallback)
  {
    historyState &h = _history();
    h.kind = kind;
    h.title = title;
    h.label = label;
    h.okLabel = okLabel;
    h.fallback = fallback;
    _historyRead();
    Dialog::show(Dialog::History, -1);
  }

} // namespace

namespace Dialog {

  void showOptionValue(const std::string &category, int index,
                       const std::string &name, const std::string &title,
                       double minimum, double maximum, double step,
                       const std::string &applyTo)
  {
    optionState &s = _option();
    s.category = category;
    s.index = index;
    s.name = name;
    s.title = title;
    s.minimum = minimum;
    s.maximum = maximum;
    s.step = step;
    s.applyTo = applyTo;
    show(OptionValue, -1);
  }

  Form optionValue()
  {
    optionState &s = _option();
    Form p;
    p.title = s.title.size() ? s.title : "Number Chooser";
    p.tabbed = false;

    Pane q;
    Field value = option(Number, "", s.category, s.name);
    value.storeIndex = s.index;
    if(s.maximum > s.minimum) {
      value.minimum = s.minimum;
      value.maximum = s.maximum;
    }
    value.step = s.step;
    // as wide as the window this reproduces makes it: two buttons across
    value.widthEm = 17.;
    value.changed = _optionApplied;
    value.tooltip = s.category + "." + s.name;
    q.fields.push_back(value);
    p.panes.push_back(q);

    // in the order the window this reproduces has them: what one came for
    // first, and what undoes it after
    Button ok;
    ok.label = "OK";
    ok.isDefault = true;
    ok.action = []() { Gui::showDialog(OptionValue, false); };
    p.buttons.push_back(ok);
    Button def;
    def.label = "Default";
    def.action = _optionDefault;
    p.buttons.push_back(def);
    return p;
  }

  Form arrow()
  {
    arrowState &a = _arrow();
    // Seeded from the options every time the window opens: it edits a copy,
    // and Apply is what puts it back. While it is up it must not be seeded
    // again, or the numbers one is typing would be written over.
    if(!a.read || !Gui::dialogVisible(Arrow)) _arrowRead();

    Form p;
    p.title = "Arrow Editor";
    p.tabbed = false;

    Pane q;
    q.fields.push_back(
      within(number("Head radius", &a.head,
                    "General.ArrowHeadRadius"), 0., 1., .01));
    q.fields.push_back(
      within(number("Stem length", &a.stem,
                    "General.ArrowStemLength"), 0., 1., .01));
    q.fields.push_back(
      within(number("Stem radius", &a.radius,
                    "General.ArrowStemRadius"), 0., 1., .01));
    p.panes.push_back(q);

    Button apply;
    apply.label = "Apply";
    apply.isDefault = true;
    apply.action = _arrowApply;
    p.buttons.push_back(apply);
    Button cancel;
    cancel.label = "Cancel";
    cancel.action = []() { Gui::showDialog(Arrow, false); };
    p.buttons.push_back(cancel);
    return p;
  }

  void showRemoteCommand()
  {
    _historyShow("connection", "Remote Start", "Command:", "Run",
                 "./gmsh ../tutorials/view3.pos");
  }

  void showWatchPattern()
  {
    _historyShow("pattern", "Watch Pattern", "Pattern:", "Watch",
                 "output/*.msh");
  }

  Form history()
  {
    historyState &h = _history();
    if(!h.read) _historyRead();

    Form p;
    p.title = h.title.size() ? h.title : "Command";
    p.tabbed = false;
    p.leastRows = 9;

    Pane q;
    {
      std::string label = h.label;
      q.fields.push_back(says([label]() { return label; }));
      Field command = text("", &h.command);
      command.widthEm = 21.;
      q.fields.push_back(command);
      q.fields.push_back(says([]() { return std::string("History:"); }));
      // Picking a line copies it into the field rather than running it: the
      // window this reproduces lets one correct what was typed before.
      Field before = chooseFrom(
        [](std::vector<std::string> &labels, std::vector<int> &values) {
          for(std::size_t i = 0; i < _history().before.size(); i++) {
            labels.push_back(_history().before[i]);
            values.push_back((int)i);
          }
        },
        [](int i) {
          return i >= 0 && i < (int)_history().before.size() &&
                 _history().before[i] == _history().command;
        },
        [](int i, bool on) {
          if(on && i >= 0 && i < (int)_history().before.size())
            _history().command = _history().before[i];
        },
        false);
      before.rows = 0;
      before.widthEm = 21.;
      q.fields.push_back(before);
    }
    p.panes.push_back(q);

    Button run;
    run.label = h.okLabel.size() ? h.okLabel : "Run";
    run.isDefault = true;
    run.action = _historyRun;
    p.buttons.push_back(run);
    Button cancel;
    cancel.label = "Cancel";
    cancel.action = []() {
      // what was given before is kept whether or not it was used, as the
      // window this reproduces keeps it
      _historyWrite();
      Gui::showDialog(History, false);
    };
    p.buttons.push_back(cancel);
    return p;
  }

} // namespace Dialog
