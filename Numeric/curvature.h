// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CURVATURE_H
#define CURVATURE_H

#include <vector>
#include "SPoint3.h"
#include "SVector3.h"

bool CurvatureRusinkiewicz(
  const std::vector<int> &triangles, const std::vector<SPoint3> &nodes,
  std::vector<std::pair<SVector3, SVector3> > &nodalCurvatures);
bool CurvatureRusinkiewicz(
  const std::vector<int> &triangles, const std::vector<SPoint3> &nodes,
  std::vector<std::pair<SVector3, SVector3> > &nodalCurvatures,
  std::vector<double> &nodeNormals);

#endif
