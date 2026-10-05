// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_PARALLEL_OPTIMIZE_H
#define MESH_GREGION_PARALLEL_OPTIMIZE_H

// Parallel optimizer of the meshes of the parallel Delaunay mesher
// (meshGRegionParallelDelaunay.h): edge removal and node relocation on the
// flat arrays, each thread working on a piece of the Moore curve

#include <cstdint>
#include "meshGRegionParallelDelaunay.h"

namespace pdel3d {

  struct OptimizeOptions {
    int numThreads = 1;
    std::uint32_t numVolumes = 0; // only the tets of colors below are improved
    // the vertices below this index (the input mesh) are never moved
    std::size_t numFixedVertices = 0;
    double qualityMin = 0.3; // tets below are improved
    int maxPasses = 20;
    int verbosity = 0;
  };

  // improve the tets below the quality threshold by edge removal and node
  // relocation, in parallel
  void optimize(Mesh &m, OptimizeOptions &opt);

} // namespace pdel3d

#endif
