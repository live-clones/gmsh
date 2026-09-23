// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PARTICLES_H
#define PARTICLES_H

#include "Plugin.h"

class GMSH_ParticlesPlugin : public GMSH_PostPlugin {
public:
  GMSH_ParticlesPlugin();
  std::string getName() const { return "Particles"; }
  std::string getShortHelp() const
  {
    return "Compute particle trajectories in force field";
  }
  std::string getHelp() const;
  PView *execute(PView *);

  int getNbU();
  int getNbV();
  void getPoint(int iU, int iV, double *X);

  bool optionCallback(int iopt, int num, int action, double &value);
  void drawPreview(void *context);
};

#endif
