// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <vector>
#include <array>

#include "hblTypes.hpp"

namespace hbl {


  /**
   * WARNING: not working yet, in progress
   *
   * @brief Apply edge swaps to minimize the sum of
   * the absolute of the tetrahedra volumes (i.e. min sum(|vol|))
   *
   * @param points 3D coordinates of the vertices
   * @param tets tetrahedral mesh to optimize
   *
   * @return true if success
   */
  bool optimizeTetMeshVolumeWithSwaps(std::vector<ArrayGeometry::vec3>& points, std::vector<id4>& tets); 

}
