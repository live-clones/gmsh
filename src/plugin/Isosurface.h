// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ISOSURFACE_H
#define ISOSURFACE_H

#include "Levelset.h"

class GMSH_IsosurfacePlugin : public GMSH_LevelsetPlugin {
  double levelset(double x, double y, double z, double val) const;

public:
  GMSH_IsosurfacePlugin();
  std::string getShortHelp() const { return "Extract a single isosurface"; }
  std::string getName() const { return "Isosurface"; }
  std::string getHelp() const;
  PView *execute(PView *);
  bool optionCallback(int iopt, int num, int action, double &value);
};

#endif
