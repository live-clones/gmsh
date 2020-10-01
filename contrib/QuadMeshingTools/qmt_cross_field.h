// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol
//
#pragma once

#include <string>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>

namespace QMT {
  bool compute_cross_field_with_multilevel_diffusion(
      const std::vector<std::array<double,3> >& points,
      const std::vector<std::array<size_t,2> >& lines,
      const std::vector<std::array<size_t,3> >& triangles,
      std::map<std::array<size_t,2>,double>& edgeTheta,
      int nbDiffusionLevels = 10,
      double thresholdNormConvergence = 1.e-2,
      int nbBoundaryExtensionLayer = 1,
      int verbosity = 3);
}
