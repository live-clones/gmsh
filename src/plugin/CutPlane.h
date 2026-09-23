// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_PLANE_H
#define CUT_PLANE_H

#include "Levelset.h"

class GMSH_CutPlanePlugin : public GMSH_LevelsetPlugin {
  double levelset(double x, double y, double z, double val) const;
  int _iview = 0; // the view of the preview

public:
  GMSH_CutPlanePlugin();
  std::string getName() const { return "CutPlane"; }
  std::string getShortHelp() const
  {
    return "Cut with the plane A*X + B*Y + C*Z + D = 0";
  }
  std::string getHelp() const;
  PView *execute(PView *);

  bool optionCallback(int iopt, int num, int action, double &value);
  void drawPreview(void *context);
};

#endif
