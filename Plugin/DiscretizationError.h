// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETIZATION_ERROR_H
#define DISCRETIZATION_ERROR_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterDiscretizationErrorPlugin();
}

class GMSH_DiscretizationErrorPlugin : public GMSH_PostPlugin {
public:
  GMSH_DiscretizationErrorPlugin() {}
  std::string getName() const { return "DiscretizationError"; }
  std::string getShortHelp() const
  {
    return "Computes spline distance to the real geometry.";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "B. Gorissen, T. Bolemann"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
