// Erosion thickness of the polygons of the unmerged dual complex: the time at
// which a fire lit on the free boundary reaches a polygon, minus its radius.
#pragma once
#include "MatTetInterior.h"

namespace matgmsh {
namespace tet {

// Edges of the dual complex, sorted by vertex pair. A polygon is a simple
// cycle: it has as many edges as vertices, and dual.offsets indexes both.
struct Adjacency {
  std::vector<std::array<int, 2> > edgeVertices; // tetrahedron ids, first < second
  std::vector<std::size_t> edgeOffsets;          // edges + 1 entries
  std::vector<int> edgePolygons;                 // by increasing polygon
  std::vector<int> polygonEdges;                 // by increasing edge
  std::size_t edges() const { return edgeVertices.size(); }
  std::size_t valence(std::size_t edge) const { return edgeOffsets[edge + 1] - edgeOffsets[edge]; }
};

struct Geometry {
  // Area-weighted centroid of the fan around the vertex mean, the vertex mean
  // itself for a polygon of zero area; mean distance to the two sites.
  std::vector<double> centroid, area, radius;
  std::size_t zeroArea = 0;
};

GMSH_API Adjacency adjacency(const Dual &dual);
GMSH_API Geometry geometry(const Dual &dual, const std::vector<double> &vertices,
                           const std::vector<double> &sites);

// Burn time of every polygon (infinite if the fire never reaches it). The
// polygons with a free edge start at their radius. An edge of valence k lets
// the fire through to its last polygon once the k - 1 others have burned, at
// the latest of their arrivals (burn time plus distance between centroids).
GMSH_API std::vector<double> burnTimes(const Dual &dual, const Adjacency &graph,
                                       const Geometry &geometry);

} // namespace tet
} // namespace matgmsh
