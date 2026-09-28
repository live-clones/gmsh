// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// ordinary dialogs, not modal: the value applies as it is given

#include "GmshConfig.h"

#include <algorithm>
#include <string>
#include <vector>

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

using namespace Ui;
using namespace Declare;

// --- one option, asked for on its own

// the menu entry that asked means every view that is drawn
void GuiOptionValue::applied()
{
  drawContext::global()->draw();
#if defined(HAVE_POST)
  if(applyTo != "view") return;
  double v = 0.;
  if(!NumberOption(GMSH_GET, category.c_str(), index, name.c_str(), v, false))
    return;
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if((int)i != index && opt_view_visible(i, GMSH_GET, 0))
      NumberOption(GMSH_SET | GMSH_GUI, "View", (int)i, name.c_str(), v, false);
  drawContext::global()->draw();
#endif
}

void GuiOptionValue::restore()
{
  double v = 0.;
  if(!NumberOption(GMSH_GET_DEFAULT, category.c_str(), index, name.c_str(), v,
                   false))
    return;
  NumberOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(), v,
               false);
  applied();
}

Form GuiOptionValue::build()
{
  std::string full =
    index ? category + "[" + std::to_string(index) + "]." + name :
            category + "." + name;
  return {"optionValue", title.size() ? title : "Number Chooser",
          vbox({number("", full)
                  .within(minimum, maximum, step)
                  .sized(17.)
                  .tip(category + "." + name)
                  .onChanged([this]() { applied(); }),
                hbox({gap(), button("OK", [this]() { hide(); }).byDefault(),
                      button("Default", [this]() { restore(); })})})};
}

void GuiOptionValue::show(const std::string &category_, int index_,
                          const std::string &name_, const std::string &title_,
                          double minimum_, double maximum_, double step_,
                          const std::string &applyTo_)
{
  category = category_;
  index = index_;
  name = name_;
  title = title_;
  minimum = minimum_;
  maximum = maximum_;
  step = step_;
  applyTo = applyTo_;
  show();
}

// --- the shape of an arrow

void GuiArrow::load()
{
  head = opt_general_arrow_head_radius(0, GMSH_GET, 0);
  stem = opt_general_arrow_stem_length(0, GMSH_GET, 0);
  radius = opt_general_arrow_stem_radius(0, GMSH_GET, 0);
}

void GuiArrow::apply()
{
  opt_general_arrow_head_radius(0, GMSH_SET | GMSH_GUI, head);
  opt_general_arrow_stem_length(0, GMSH_SET | GMSH_GUI, stem);
  opt_general_arrow_stem_radius(0, GMSH_SET | GMSH_GUI, radius);
  CTX::instance()->meshChanged();
  drawContext::global()->draw();
}

Form GuiArrow::build()
{
  // three proportions set by eye
  auto scale = [](const char *said, double *held, const char *option) {
    return number(said, held).tip(option).within(0., 1., .01).slid().sized(7.);
  };
  return {"arrow", "Arrow Editor",
          vbox({scale("Head radius", &head, "General.ArrowHeadRadius"),
                scale("Stem length", &stem, "General.ArrowStemLength"),
                scale("Stem radius", &radius, "General.ArrowStemRadius"),
                hbox({button("Apply", [this]() { apply(); }).byDefault().sized(7.),
                      button("Cancel", [this]() { hide(); }).sized(7.)})})};
}

// --- a command, with the ones given before it

// a file beside the session file, one line per entry, the most recent first,
// under a line naming the list
static std::string _historyFile()
{
  return CTX::instance()->homeDir + ".gmsh-history";
}

void GuiHistory::read()
{
  before.clear();
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
      if(in == kind && s.size() && before.size() < 100) before.push_back(s);
    }
    fclose(fp);
  }
  command = before.size() ? before[0] : fallback;
}

// the file holds both lists and only one is in memory: the other is carried
// over
void GuiHistory::write()
{
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
    if(l.first == kind) {
      l.second = before;
      found = true;
    }
  if(!found) lists.push_back(std::make_pair(kind, before));

  fp = Fopen(_historyFile().c_str(), "w");
  if(!fp) return;
  for(const auto &l : lists) {
    fprintf(fp, "[%s]\n", l.first.c_str());
    for(const auto &e : l.second) fprintf(fp, "%s\n", e.c_str());
  }
  fclose(fp);
}

void GuiHistory::run()
{
  if(command.size()) {
    before.erase(std::remove(before.begin(), before.end(), command),
                 before.end());
    before.insert(before.begin(), command);
    if(before.size() > 100) before.resize(100);
    write();
  }
  hide();
  if(kind == "pattern") {
    CTX::instance()->watchFilePattern = command;
    watchFiles();
  }
  else
    remoteAction("start", command);
}

Form GuiHistory::build()
{
  Form f = {
    "history", title.size() ? title : "Command",
    vbox({label(prompt), text("", &command).sized(21.), label("History:"),
          // picking a line copies it into the field rather than running it
          chooseFrom(
            [this](std::vector<std::string> &labels, std::vector<int> &values) {
              for(std::size_t i = 0; i < before.size(); i++) {
                labels.push_back(before[i]);
                values.push_back((int)i);
              }
            },
            [this](int i) {
              return i >= 0 && i < (int)before.size() && before[i] == command;
            },
            [this](int i, bool on) {
              if(on && i >= 0 && i < (int)before.size()) command = before[i];
            },
            false)
            .fills()
            .sized(21.),
          hbox({gap(),
                button(okLabel.size() ? okLabel : "Run", [this]() { run(); })
                  .byDefault(),
                button("Cancel", [this]() {
                  write();
                  hide();
                })})})};
  f.leastRows = 6;
  return f;
}

void GuiHistory::ask(const std::string &kind_, const std::string &title_,
                     const std::string &label, const std::string &okLabel_,
                     const std::string &fallback_)
{
  kind = kind_;
  title = title_;
  prompt = label;
  okLabel = okLabel_;
  fallback = fallback_;
  read();
  show();
}

void GuiHistory::showRemoteCommand()
{
  ask("connection", "Remote Start", "Command:", "Run",
      "./gmsh ../tutorials/view3.pos");
}

void GuiHistory::showWatchPattern()
{
  ask("pattern", "Watch Pattern", "Pattern:", "Watch", "output/*.msh");
}
