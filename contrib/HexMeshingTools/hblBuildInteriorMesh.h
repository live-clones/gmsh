// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>

#include "hblSolveAllHexLayer.h"

namespace hbl {

  bool buildInteriorHexdomMesh(
      const HblOptions& opt,
      HblOutput& output);


  bool checkTriangleIntersections(
      std::vector<vec3>& points,
      const std::vector<std::array<int32_t,3> >& triangles,
      std::vector<id2>& intersections,
      bool earlyStop = false);

}
