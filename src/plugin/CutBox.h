// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CUT_BOX_H
#define CUT_BOX_H

#include "Plugin.h"

class GMSH_CutBoxPlugin : public GMSH_PostPlugin {
  void addInView(int connect, int boundary, int numsteps, int nbcomp,
                 double ****pnts, double ****vals, PViewDataList *data);
  PView *GenerateView(PView *v, int connectPoints, int boundary);

public:
  GMSH_CutBoxPlugin();
  std::string getName() const { return "CutBox"; }
  std::string getShortHelp() const
  {
    return "Cut with a regular box defined by 4 points";
  }
  std::string getHelp() const;
  PView *execute(PView *);

  int getNbU();
  int getNbV();
  int getNbW();
  void getPoint(int iU, int iV, int iW, double *X);

  bool optionCallback(int iopt, int num, int action, double &value);
  void drawPreview(void *context);
};

#endif
