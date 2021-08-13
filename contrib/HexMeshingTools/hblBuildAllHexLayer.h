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

  bool buildAllHexBoundaryLayer(
      const HblInput& input,
      const HblOptions& opt,
      HblOutput& output);

  bool extrudeBoundary(BrepMesh& M, std::vector<id>& newCells,
      const std::vector<vec3>* vNormals = nullptr,
      const HexToBoundaryMeshMatching* h2q = nullptr);


  struct ElementMesh {
    std::vector<vec3> points;
    std::vector<GEntity*> pEntities;

    std::vector<std::vector<id> > faces;
    std::vector<int> faceData;

    std::vector<std::vector<id> > cells;
    std::vector<int> cellData;
  };


  bool subdivide_hex_boundary_layer_anistropic(
      BrepMesh& H, 
      HexToBoundaryMeshMatching& h2q,
      int N,
      ElementMesh& A);
}
