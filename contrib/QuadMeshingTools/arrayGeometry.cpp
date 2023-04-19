// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "arrayGeometry.h"

/* System includes */
#include <vector>
#include <array>
#include <unordered_map>
#include <cstdint>
#include <cmath>
#include <algorithm>

namespace ArrayGeometry {

  double bboxDiag(const std::vector<vec3> &points)
  {
    vec3 mi = {DBL_MAX, DBL_MAX, DBL_MAX};
    vec3 ma = {-DBL_MAX, -DBL_MAX, -DBL_MAX};
    for(size_t i = 0; i < points.size(); ++i)
      for(size_t d = 0; d < 3; ++d) {
        mi[d] = std::min(points[i][d], mi[d]);
        ma[d] = std::max(points[i][d], ma[d]);
      }
    return length(ma - mi);
  }

} // namespace ArrayGeometry
