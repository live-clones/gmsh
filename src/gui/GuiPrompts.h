// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PROMPTS_H
#define GMSH_GUI_PROMPTS_H

#include <string>
#include <vector>

#include "GuiDialog.h"


// opened by the quick access menu on the entries that take a value rather than
// a switch
class GuiOptionValue : public GuiDialog {
  std::string category, name, title, applyTo;
  int index = 0;
  double minimum = 0., maximum = 0., step = 0.;
  void applied();
  void restore();

public:
  using GuiDialog::show;
  // the value applies as it is typed; applyTo "view" copies it to every visible
  // view
  void show(const std::string &category, int index, const std::string &name,
            const std::string &title, double minimum, double maximum,
            double step, const std::string &applyTo = "");

protected:
  Ui::Form build() override;
};

// edits a copy, seeded when it opens; Apply puts it back
class GuiArrow : public GuiDialog {
  double head = 0., stem = 0., radius = 0.;
  void apply();

protected:
  Ui::Form build() override;
  void load() override;
};

// the remote solver to start, or the pattern of the files to watch
class GuiHistory : public GuiDialog {
  std::string kind;
  std::string title, prompt, okLabel, fallback;
  std::string command;
  std::vector<std::string> before;
  void read();
  void write();
  void run();
  void ask(const std::string &kind, const std::string &title,
           const std::string &label, const std::string &okLabel,
           const std::string &fallback);

public:
  void showRemoteCommand();
  void showWatchPattern();

protected:
  Ui::Form build() override;
};

#endif
