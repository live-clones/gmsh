// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SMOOTH_H
#define SMOOTH_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterSmoothPlugin();
}

class GMSH_SmoothPlugin : public GMSH_PostPlugin {
public:
  GMSH_SmoothPlugin() {}
  std::string getName() const { return "Smooth"; }
  std::string getShortHelp() const { return "Apply nodal smoothing"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
