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


  /* Decomposed functions for more efficient usage */
  bool create_linear_system(size_t nb_rows, void** data);
  bool destroy_linear_system(void** data);
  bool add_sparse_coefficients(
      const std::vector<std::vector<size_t>>& columns,
      const std::vector<std::vector<double>>& values,
      void* data);
  bool set_rhs_values(
      const std::vector<double>& rhs,
      void* data);
  bool solve(std::vector<double>& x, void* data);

  bool factorize(void* data); /* only with custom MUMPS */
}
