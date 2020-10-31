// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_VOL_HEX_PERCENTAGE_H
#define MESH_VOL_HEX_PERCENTAGE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterMeshVolHexPercentagePlugin();
}

class GMSH_MeshVolHexPercentagePlugin : public GMSH_PostPlugin {
public:
  GMSH_MeshVolHexPercentagePlugin() {}
  std::string getName() const { return "MeshVolHexPercentage"; }
  std::string getShortHelp() const { return "Volume of a mesh"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "N. Marsic"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
