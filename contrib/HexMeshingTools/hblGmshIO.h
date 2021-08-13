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

class GRegion;

namespace hbl {
  class BrepMesh;
  class HblInput;
  class HblOutput;

  bool buildBoundaryMeshFromGRegion(GRegion* gr, BrepMesh& Q);

  bool prepareHexblInput(GRegion* gr, HblInput& input, HblOutput& output);

  bool appendTetMeshBuiltFromQuadBoundary(
      BrepMesh& H,
      const std::vector<std::vector<id> >& quadMeshFaces);

}
