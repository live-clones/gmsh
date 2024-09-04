// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MODIFY_COMPONENT_H
#define MODIFY_COMPONENT_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterModifyComponentsPlugin();
}

class GMSH_ModifyComponentsPlugin : public GMSH_PostPlugin {
public:
  GMSH_ModifyComponentsPlugin() {}
  std::string getName() const { return "ModifyComponents"; }
  std::string getShortHelp() const
  {
    return "Modify components in a view using mathematical expressions";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
