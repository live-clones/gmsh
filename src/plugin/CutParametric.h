// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_PARAMETRIC_H
#define CUT_PARAMETRIC_H

#include <string>
#include <vector>
#include "Plugin.h"

class GMSH_CutParametricPlugin : public GMSH_PostPlugin {
private:
  double getU(int i);
  double getV(int i);
  // the points of the preview, to be computed again if an option changed
  int fillXYZ();
  bool _recompute = true;
  std::vector<double> x, y, z;

public:
  GMSH_CutParametricPlugin();
  std::string getName() const { return "CutParametric"; }
  std::string getShortHelp() const
  {
    return "Cut with the parametric curve (X(u,v), Y(u,v), Z(u,v))";
  }
  std::string getHelp() const;
  PView *execute(PView *);

  bool optionCallback(int iopt, int num, int action, double &value);
  bool optionStrCallback(int iopt, int num, int action, std::string &value);
  void drawPreview(void *context);
};

#endif
