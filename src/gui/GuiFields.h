// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_FIELDS_H
#define GMSH_GUI_FIELDS_H

#include <map>
#include <string>

#include "GuiDialog.h"

// the mesh size fields, what each of them takes, and which is the background
class GuiFields : public GuiTabbed {
  int selected = -1; // the field being edited, -1 for none
  int loaded = -1; // the one the boxes below were filled from
  bool background = false; // whether it is the one the mesh is built from
  std::map<std::string, std::string> words;
  std::map<std::string, double> numbers;
  void fill(bool force);
  void apply();
  void create(int which);
  void remove();
  void visualize(int which);
  std::vector<Ui::Line> help();

protected:
  Ui::Form build() override;
};

#endif
