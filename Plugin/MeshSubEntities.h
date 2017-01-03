// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_ENTITIES_H_
#define _MESH_ENTITIES_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterMeshSubEntitiesPlugin();
}

class GMSH_MeshSubEntitiesPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_MeshSubEntitiesPlugin(){}
  std::string getName() const { return "MeshSubEntities"; }
  std::string getShortHelp() const
  {
    return "Mesh subentities generator";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  PView *execute(PView *);
};

#endif
