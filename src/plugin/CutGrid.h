// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_GRID_H
#define CUT_GRID_H

#include "PointGrid.h"

class GMSH_CutGridPlugin : public GMSH_PointGridPlugin {
  void addInView(int numsteps, int connect, int nbcomp, double ***pnts,
                 double ***vals, std::vector<double> &P, int *nP,
                 std::vector<double> &L, int *nL, std::vector<double> &Q,
                 int *nQ);
  PView *GenerateView(PView *v, int connectPoints);

public:
  GMSH_CutGridPlugin();
  std::string getName() const { return "CutGrid"; }
  std::string getShortHelp() const
  {
    return "Cut with a regular grid defined by 3 points";
  }
  std::string getHelp() const;
  PView *execute(PView *);

  bool optionCallback(int iopt, int num, int action, double &value);
  void drawPreview(void *context);
};

#endif
