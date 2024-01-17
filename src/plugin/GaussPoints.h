// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GAUSS_POINTS_H
#define GAUSS_POINTS_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterGaussPointsPlugin();
}

class GMSH_GaussPointsPlugin : public GMSH_PostPlugin {
public:
  GMSH_GaussPointsPlugin() {}
  std::string getName() const { return "GaussPoints"; }
  std::string getShortHelp() const { return "Gauss points"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
