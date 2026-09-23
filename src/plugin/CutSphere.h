// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_SPHERE_H
#define CUT_SPHERE_H

#include "Levelset.h"

class GMSH_CutSpherePlugin : public GMSH_LevelsetPlugin {
  double levelset(double x, double y, double z, double val) const;

public:
  GMSH_CutSpherePlugin();
  std::string getName() const { return "CutSphere"; }
  std::string getShortHelp() const
  {
    return "Cut with a sphere centered at (Xc, Yc, Zc)";
  }
  std::string getHelp() const;
  PView *execute(PView *);

  bool optionCallback(int iopt, int num, int action, double &value);
  void drawPreview(void *context);
};

#endif
