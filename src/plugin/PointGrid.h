// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef POINT_GRID_H
#define POINT_GRID_H

#include "Plugin.h"

// The base class of the plugins working on a grid of points (CutGrid, the
// seeds of StreamLines and Particles): points (X0, Y0, Z0) + u (X1 - X0, Y1 -
// Y0, Z1 - Z0) + v (X2 - X0, Y2 - Y0, Z2 - Z0), NumPointsU values of u and
// NumPointsV values of v in [0, 1]. These are its first 11 options, in this
// order: X0, Y0, Z0, X1, Y1, Z1, X2, Y2, Z2, NumPointsU, NumPointsV.
class GMSH_PointGridPlugin : public GMSH_PostPlugin {
public:
  using GMSH_PostPlugin::GMSH_PostPlugin;
  int getNbU();
  int getNbV();
  void getPoint(int iU, int iV, double *X);
  // the grid options edited with sliders: the coordinates in [-2 lc, 2 lc],
  // from 1 to 100 points
  bool optionCallback(int iopt, int num, int action, double &value);
  // a sphere at each point
  void drawPreview(void *context);
};

#endif
