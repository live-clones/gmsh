// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TETRAHEDRALIZE_H
#define TETRAHEDRALIZE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterTetrahedralizePlugin();
}

class GMSH_TetrahedralizePlugin : public GMSH_PostPlugin {
public:
  GMSH_TetrahedralizePlugin() {}
  std::string getName() const { return "Tetrahedralize"; }
  std::string getShortHelp() const { return "Mesh 3D point cloud"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
