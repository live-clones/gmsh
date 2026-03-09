// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DUPLICATE_NODES_H
#define DUPLICATE_NODES_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterDuplicateNodesPlugin();
}

class GMSH_DuplicateNodesPlugin : public GMSH_PostPlugin {
public:
  GMSH_DuplicateNodesPlugin() {}
  std::string getName() const { return "DuplicateNodes"; }
  std::string getShortHelp() const { return "Duplicate nodes"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
