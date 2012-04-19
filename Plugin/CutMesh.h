// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CUTMESH_H_
#define _CUTMESH_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMeshPlugin();
}

class GMSH_CutMeshPlugin : public GMSH_MeshPlugin
{
 public:
  GMSH_CutMeshPlugin(){}
  std::string getName() const { return "CutMesh"; }
  std::string getShortHelp() const
  {
    return "Cut mesh along a levelset";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "G. Bricteux"; }
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  void run();
};

#endif
