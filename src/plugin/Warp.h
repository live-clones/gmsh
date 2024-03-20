// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef WARP_H
#define WARP_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterWarpPlugin();
}

class GMSH_WarpPlugin : public GMSH_PostPlugin {
public:
  GMSH_WarpPlugin() {}
  std::string getName() const { return "Warp"; }
  std::string getShortHelp() const
  {
    return "Deform view using a vector field";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
