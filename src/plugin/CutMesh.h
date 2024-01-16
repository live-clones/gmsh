// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUTMESH_H
#define CUTMESH_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterCutMeshPlugin();
}

class GMSH_CutMeshPlugin : public GMSH_MeshPlugin {
public:
  GMSH_CutMeshPlugin() {}
  std::string getName() const { return "CutMesh"; }
  std::string getShortHelp() const { return "Cut mesh along a levelset"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "G. Bricteux"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int run();
};

#endif
