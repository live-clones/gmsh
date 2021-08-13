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

  class HblInput;
  class HblOutput;
  class HblOptions;
  class HblStats;
  class BrepMesh;
  class HexToBoundaryMeshMatching;

  /* Must be called one time,
   * fill the hexahedra in HblOutput
   * with the right orientation */
  bool initializeHexLayerGeometry(
      const HblInput& input,
      const HblOptions& opt, 
      HblOutput& output);

  bool optimizeHexLayerGeometry(
      const HblInput& input,
      const HblOptions& opt, 
      HblOutput& output);


  bool extract_interior_quad_meshes(
      const BrepMesh& H, 
      const HexToBoundaryMeshMatching& h2q,
      std::vector<std::vector<id> >& quadMeshFaces
    );


  /* Smooth quad mesh without respecting CAD entities.
   * WARNING: will change the positions of vertices in the GModel !
   * vertices may no longer be on CAD entities !! */
  bool smoothGModelSurfaceMesh(const BrepMesh& Q, const std::vector<id>& QvertTangled);


  enum class QualityMetric {SIGE, SICN};

  std::array<double,5> computeQualityStatsMinMedAvgMaxInv(const BrepMesh& M, QualityMetric m = QualityMetric::SIGE);
}
