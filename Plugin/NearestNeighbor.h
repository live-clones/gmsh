// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef NEAREST_NEIGHBOR_H
#define NEAREST_NEIGHBOR_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterNearestNeighborPlugin();
}

class GMSH_NearestNeighborPlugin : public GMSH_PostPlugin {
public:
  GMSH_NearestNeighborPlugin() {}
  std::string getName() const { return "NearestNeighbor"; }
  std::string getShortHelp() const
  {
    return "Compute distance to the nearest neighbor";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
