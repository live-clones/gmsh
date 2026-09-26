// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PARTICLES_H
#define PARTICLES_H

#include "PointGrid.h"

class GMSH_ParticlesPlugin : public GMSH_PointGridPlugin {
public:
  GMSH_ParticlesPlugin();
  std::string getName() const { return "Particles"; }
  std::string getShortHelp() const
  {
    return "Compute particle trajectories in force field";
  }
  std::string getHelp() const;
  PView *execute(PView *);
};

#endif
