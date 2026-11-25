#pragma once

#include <cstddef>
#include <vector>

namespace matVoronoiVertexMerge {

struct Statistics {
  double absoluteTolerance = 0.0;
  std::size_t shortEdgeCount = 0;
  std::size_t mergedVertexCount = 0;
};

// Numerically coincident Voronoi vertices must only be identified when an
// actual MAT polygon edge connects them.  A global point-cloud weld could
// incorrectly join distinct sheets that happen to cross in space.
class AdjacentVertexMerger {
public:
  AdjacentVertexMerger(const std::vector<double> &vertices,
                       double referenceLength,
                       double relativeTolerance = 1.e-12);

  void considerEdge(int first, int second);
  int representative(int vertex);
  const Statistics &statistics() const { return statistics_; }

private:
  int findRoot(int vertex);

  const std::vector<double> &vertices_;
  std::vector<int> parent_;
  Statistics statistics_;
};

// Rewrites a closed Voronoi polygon with the representatives selected above.
// Repeated vertices are removed while preserving cyclic order.  The return
// value is the number of removed entries.
std::size_t canonicalizeClosedFace(std::vector<int> &vertices,
                                   AdjacentVertexMerger &merger);

} // namespace matVoronoiVertexMerge
