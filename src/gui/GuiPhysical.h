// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PHYSICAL_H
#define GMSH_GUI_PHYSICAL_H

#include <map>
#include <string>

#include "GuiDialog.h"

// the action that opens the dialog says what kind of entity, and whether adding
// or removing
class GuiPhysical : public GuiTabbed {
public:
  std::string type = "Point";
  bool remove = false;
  std::string name;
  int tag = 0;
  bool append = false; // add to the group of that name instead of replacing it
  bool automatic = true; // let Gmsh choose the tag of the group
  using GuiTabbed::show;
  void show(const std::string &type, bool remove);

protected:
  Ui::Form build() override;
  void load() override;

private:
  int dimension() const;
  void groups(std::map<int, std::string> &tags,
              std::map<std::string, int> &names) const;
  void changed();
};

#endif
