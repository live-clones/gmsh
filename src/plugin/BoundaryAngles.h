// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BOUNDARY_ANGLES_H
#define BOUNDARY_ANGLES_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryAnglesPlugin();
}

class GMSH_BoundaryAnglesPlugin : public GMSH_PostPlugin {
  double levelset(double x, double y, double z, double val) const;
  static double callback(int num, int action, double value, double *opt);
  static int iview;

public:
  GMSH_BoundaryAnglesPlugin() {}
  std::string getName() const { return "BoundaryAngles"; }
  std::string getShortHelp() const
  {
    return "Compute angles on boundaries of 2D surface meshes";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Bertrand Thierry"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
