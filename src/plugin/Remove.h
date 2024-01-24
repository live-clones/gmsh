// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef REMOVE_H
#define REMOVE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterRemovePlugin();
}

class GMSH_RemovePlugin : public GMSH_PostPlugin {
public:
  GMSH_RemovePlugin() {}
  std::string getName() const { return "Remove"; }
  std::string getShortHelp() const
  {
    return "Remove selected data from a view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
