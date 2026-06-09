// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#pragma once

#include <array>
#include <cstdint>
#include <vector>

bool untangle_triangles_2D_GMSH(
  std::vector<std::array<double, 2>> &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3>> &triangles,
  const std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes,
  double lambda = 1., int iterMaxInner = 300, int iterMaxOuter = 100,
  int iterFailMax = 10, double timeMax = 9999.);

bool untangle_tetrahedra_GMSH(
  std::vector<std::array<double, 3>> &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 4>> &tets,
  const std::vector<std::array<std::array<double, 3>, 4>> &tetIdealShapes,
  double lambda = 1., int iterMaxInner = 300, int iterMaxOuter = 100,
  int iterFailMax = 10, double timeMax = 9999.);
