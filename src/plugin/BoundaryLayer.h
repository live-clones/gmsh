// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BOUNDARY_LAYER_H
#define BOUNDARY_LAYER_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryLayerPlugin();
}

class GMSH_BoundaryLayerPlugin : public GMSH_PostPlugin {
public:
  GMSH_BoundaryLayerPlugin() {}
  std::string getName() const { return "BoundaryLayer"; }
  std::string getShortHelp() const { return "Create boundary layer meshes"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
