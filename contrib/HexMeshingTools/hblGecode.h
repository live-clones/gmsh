// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include "hblTypes.hpp"

namespace hbl {

  constexpr int VAL_MIN = 1;
  constexpr int VAL_MAX = 5;

  bool solve_with_gecode(
      size_t N,
      const std::vector<std::vector<id>>& polygons,
      const std::vector<double>& x_ideal,
      const std::vector<id2>& n_min_max,
      const std::vector<id>& n_priority,
      std::vector<id>& solution,
      bool& stopped,
      std::vector<double>& iterTime,
      double timeMaxInit = 100e3, /* 100 seconds */
      double timeMaxImprove = 10 /* 10 seconds */
      );

  bool solve_with_gecode_many_solutions(
      size_t N,
      const std::vector<std::vector<id>>& polygons,
      const std::vector<double>& x_ideal,
      const std::vector<id2>& n_min_max,
      size_t nb_slt_max,
      std::vector<std::vector<id>>& solutions);
}
