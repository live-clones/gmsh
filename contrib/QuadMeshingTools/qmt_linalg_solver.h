// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once
#include <vector>

namespace QMT {

  bool solve_sparse_linear_system(
      const std::vector<std::vector<size_t>>& columns,
      const std::vector<std::vector<double>>& values,
      const std::vector<double>& rhs,
      std::vector<double>& x);

}
