// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_ENTITIES_H
#define MESH_ENTITIES_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterMeshSubEntitiesPlugin();
}

class GMSH_MeshSubEntitiesPlugin : public GMSH_PostPlugin {
public:
  GMSH_MeshSubEntitiesPlugin() {}
  std::string getName() const { return "MeshSubEntities"; }
  std::string getShortHelp() const { return "Mesh subentities generator"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
