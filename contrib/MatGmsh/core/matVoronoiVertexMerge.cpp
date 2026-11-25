#include "matVoronoiVertexMerge.h"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <stdexcept>

namespace matVoronoiVertexMerge {

AdjacentVertexMerger::AdjacentVertexMerger(
    const std::vector<double> &vertices, double referenceLength,
    double relativeTolerance)
    : vertices_(vertices), parent_(vertices.size() / 3)
{
  if(vertices.size() % 3 != 0)
    throw std::invalid_argument("Invalid Voronoi vertex coordinate array");
  if(!std::isfinite(referenceLength) || referenceLength < 0.0)
    throw std::invalid_argument("Invalid Voronoi merge reference length");
  if(!std::isfinite(relativeTolerance) || relativeTolerance < 0.0)
    throw std::invalid_argument("Invalid Voronoi merge relative tolerance");

  std::iota(parent_.begin(), parent_.end(), 0);
  statistics_.absoluteTolerance =
      relativeTolerance * (referenceLength > 0.0 ? referenceLength : 1.0);
}

int AdjacentVertexMerger::findRoot(int vertex)
{
  int root = vertex;
  while(parent_[root] != root) root = parent_[root];
  while(parent_[vertex] != vertex) {
    const int next = parent_[vertex];
    parent_[vertex] = root;
    vertex = next;
  }
  return root;
}

int AdjacentVertexMerger::representative(int vertex)
{
  if(vertex < 0 || static_cast<std::size_t>(vertex) >= parent_.size())
    return vertex;
  return findRoot(vertex);
}

void AdjacentVertexMerger::considerEdge(int first, int second)
{
  if(first < 0 || second < 0 || first == second ||
     static_cast<std::size_t>(first) >= parent_.size() ||
     static_cast<std::size_t>(second) >= parent_.size())
    return;

  const double dx = vertices_[3 * first] - vertices_[3 * second];
  const double dy = vertices_[3 * first + 1] - vertices_[3 * second + 1];
  const double dz = vertices_[3 * first + 2] - vertices_[3 * second + 2];
  const double tolerance2 = statistics_.absoluteTolerance *
                            statistics_.absoluteTolerance;
  if(dx * dx + dy * dy + dz * dz > tolerance2) return;

  ++statistics_.shortEdgeCount;
  int firstRoot = findRoot(first);
  int secondRoot = findRoot(second);
  if(firstRoot == secondRoot) return;

  // Keeping the smallest tetrahedron id makes the result deterministic and
  // leaves every per-tetrahedron array untouched.  Only MAT connectivity is
  // rewritten by canonicalizeClosedFace().
  if(secondRoot < firstRoot) std::swap(firstRoot, secondRoot);
  parent_[secondRoot] = firstRoot;
  ++statistics_.mergedVertexCount;
}

std::size_t canonicalizeClosedFace(std::vector<int> &vertices,
                                   AdjacentVertexMerger &merger)
{
  const std::size_t originalSize = vertices.size();
  std::vector<int> canonical;
  canonical.reserve(originalSize);
  std::set<int> seen;
  for(int vertex : vertices) {
    const int root = merger.representative(vertex);
    if(root < 0 || !seen.insert(root).second) continue;
    canonical.push_back(root);
  }
  vertices = std::move(canonical);
  return originalSize - vertices.size();
}

} // namespace matVoronoiVertexMerge
