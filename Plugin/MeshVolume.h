// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_VOLUME_H
#define MESH_VOLUME_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterMeshVolumePlugin();
}

class GMSH_MeshVolumePlugin : public GMSH_PostPlugin {
public:
  GMSH_MeshVolumePlugin() {}
  std::string getName() const { return "MeshVolume"; }
  std::string getShortHelp() const { return "Volume of a mesh"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "N. Marsic"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
