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
    // the small polyhedron reconnection of the tets that the edge removals
    // and relocations leave below sprQualityFactor * qualityMin: the size of
    // the cavity grown around them and the budget of the exhaustive search
    // (tets placed, over the life of the cavity). Larger values (HXT: every
    // tet below qualityMin, 32 points, 500 nodes) remove a few more bad tets
    // for ten to fifty times the cost, which failed searches dominate
    double sprQualityFactor = 0.5;
    int sprMaxPoints = 16;
    int sprMaxSearchNodes = 100;
    int verbosity = 0;
  };

  // improve the tets below the quality threshold by edge removal and node
  // relocation, then by reconnection of the cavities around those left over,
  // in parallel
  void optimize(Mesh &m, const OptimizeOptions &opt);

} // namespace pdel3d

#endif
