// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DIVERGENCE_H
#define DIVERGENCE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterDivergencePlugin();
}

class GMSH_DivergencePlugin : public GMSH_PostPlugin {
public:
  GMSH_DivergencePlugin() {}
  std::string getName() const { return "Divergence"; }
  std::string getShortHelp() const
  {
    return "Compute the divergence of a vector view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
