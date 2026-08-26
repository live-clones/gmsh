// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <array>
#include <cstdint>
#include <vector>

class GFace;

bool untangle_triangles_parametric_GMSH(
  GFace *gf, std::vector<std::array<double, 2>> &parametricPoints,
  const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3>> &triangles,
  const std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes,
  double lambda = 1., int iterMax = 300, double timeMax = 9999.,
  int quadraturePoints = 3);
