// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GRADIENT_H
#define GRADIENT_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterGradientPlugin();
}

class GMSH_GradientPlugin : public GMSH_PostPlugin {
public:
  GMSH_GradientPlugin() {}
  std::string getName() const { return "Gradient"; }
  std::string getShortHelp() const
  {
    return "Compute the gradient of a scalar view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
