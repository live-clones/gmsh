// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SPHERICAL_RAISE_H
#define SPHERICAL_RAISE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterSphericalRaisePlugin();
}

class GMSH_SphericalRaisePlugin : public GMSH_PostPlugin {
public:
  GMSH_SphericalRaisePlugin() {}
  std::string getName() const { return "SphericalRaise"; }
  std::string getShortHelp() const { return "Create spherical elevation plot"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
