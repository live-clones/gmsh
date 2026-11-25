#include "MatErosion.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <queue>
#include <stdexcept>
#include <utility>

namespace matgmsh {
namespace tet {

Adjacency adjacency(const Dual &dual)
{
  struct Side {
    std::uint64_t key;
    int polygon;
  };
  std::vector<Side> sides;
  sides.reserve(dual.cycles.size());
  for(std::size_t p = 0; p < dual.size(); ++p) {
    const std::size_t begin = dual.offsets[p], end = dual.offsets[p + 1];
    if(end - begin < 3) throw std::runtime_error("MAT dual: polygon with fewer than three vertices");
    for(std::size_t i = begin; i < end; ++i) {
      const int a = dual.cycles[i], b = dual.cycles[i + 1 == end ? begin : i + 1];
      if(a < 0 || b < 0 || a == b) throw std::runtime_error("MAT dual: invalid polygon side");
      sides.push_back(
        {(std::uint64_t(std::min(a, b)) << 32) | std::uint32_t(std::max(a, b)), int(p)});
    }
  }
  std::sort(sides.begin(), sides.end(), [](const Side &x, const Side &y) {
    return x.key != y.key ? x.key < y.key : x.polygon < y.polygon;
  });
  Adjacency g;
  g.edgeOffsets.push_back(0);
  g.edgePolygons.reserve(sides.size());
  g.polygonEdges.resize(sides.size());
  std::vector<std::size_t> fill(dual.offsets.begin(), dual.offsets.end() - 1);
  for(std::size_t i = 0, j = 0; i < sides.size(); i = j) {
    const int edge = int(g.edgeVertices.size());
    for(j = i; j < sides.size() && sides[j].key == sides[i].key; ++j) {
      if(j > i && sides[j].polygon == sides[j - 1].polygon)
        throw std::runtime_error("MAT dual: a polygon uses the same edge twice");
      g.edgePolygons.push_back(sides[j].polygon);
      g.polygonEdges[fill[sides[j].polygon]++] = edge;
    }
    g.edgeVertices.push_back({{int(sides[i].key >> 32), int(std::uint32_t(sides[i].key))}});
    g.edgeOffsets.push_back(g.edgePolygons.size());
  }
  return g;
}

Geometry geometry(const Dual &dual, const std::vector<double> &vertices,
                  const std::vector<double> &sites)
{
  const std::size_t count = dual.size();
  Geometry g;
  g.centroid.resize(3 * count);
  g.area.resize(count);
  g.radius.resize(count);
  const auto point = [&](std::size_t i) { return &vertices[3 * std::size_t(dual.cycles[i])]; };
  for(std::size_t p = 0; p < count; ++p) {
    const std::size_t begin = dual.offsets[p], end = dual.offsets[p + 1];
    double mean[3] = {0., 0., 0.};
    for(std::size_t i = begin; i < end; ++i)
      for(int k = 0; k < 3; ++k) mean[k] += point(i)[k];
    for(int k = 0; k < 3; ++k) mean[k] /= double(end - begin);
    double area = 0., weighted[3] = {0., 0., 0.};
    for(std::size_t i = begin; i < end; ++i) {
      const double *a = point(i), *b = point(i + 1 == end ? begin : i + 1);
      double u[3], w[3];
      for(int k = 0; k < 3; ++k) {
        u[k] = a[k] - mean[k];
        w[k] = b[k] - mean[k];
      }
      const double n[3] = {u[1] * w[2] - u[2] * w[1], u[2] * w[0] - u[0] * w[2],
                           u[0] * w[1] - u[1] * w[0]};
      const double triangle = .5 * std::sqrt((n[0] * n[0] + n[1] * n[1]) + n[2] * n[2]);
      area += triangle;
      for(int k = 0; k < 3; ++k) weighted[k] += ((mean[k] + a[k]) + b[k]) / 3. * triangle;
    }
    g.area[p] = area;
    double *c = &g.centroid[3 * p];
    if(area > 0. && std::isfinite(area))
      for(int k = 0; k < 3; ++k) c[k] = weighted[k] / area;
    else {
      ++g.zeroArea;
      for(int k = 0; k < 3; ++k) c[k] = mean[k];
    }
    double distance[2];
    for(int s = 0; s < 2; ++s) {
      const double *site = &sites[3 * std::size_t(dual.sitePair[p][s])];
      const double d[3] = {site[0] - c[0], site[1] - c[1], site[2] - c[2]};
      distance[s] = std::sqrt((d[0] * d[0] + d[1] * d[1]) + d[2] * d[2]);
    }
    g.radius[p] = (distance[0] + distance[1]) / 2.;
  }
  return g;
}

std::vector<double> burnTimes(const Dual &dual, const Adjacency &graph, const Geometry &geometry)
{
  const std::size_t count = dual.size();
  const double infinity = std::numeric_limits<double>::infinity();
  std::vector<double> times(count, infinity);
  std::vector<unsigned char> valid(count), done(count, 0);
  for(std::size_t p = 0; p < count; ++p) {
    const double *c = &geometry.centroid[3 * p];
    valid[p] = std::isfinite(c[0]) && std::isfinite(c[1]) && std::isfinite(c[2]) &&
               std::isfinite(geometry.radius[p]);
  }
  using Item = std::pair<double, int>;
  std::priority_queue<Item, std::vector<Item>, std::greater<Item> > queue;
  std::vector<std::uint32_t> remaining(graph.edges());
  for(std::size_t e = 0; e < graph.edges(); ++e) {
    remaining[e] = std::uint32_t(graph.valence(e));
    if(remaining[e] != 1) continue;
    const int p = graph.edgePolygons[graph.edgeOffsets[e]];
    if(!valid[p] || times[p] != infinity) continue;
    times[p] = geometry.radius[p];
    queue.emplace(times[p], p);
  }
  while(!queue.empty()) {
    const Item item = queue.top();
    queue.pop();
    const int polygon = item.second;
    if(done[polygon] || item.first != times[polygon]) continue;
    done[polygon] = 1;
    for(std::size_t i = dual.offsets[polygon]; i < dual.offsets[polygon + 1]; ++i) {
      const int edge = graph.polygonEdges[i];
      if(--remaining[edge] != 1) continue;
      // One polygon is left around this edge: the fire reaches it when the
      // last of the others has arrived.
      int target = -1;
      for(std::size_t j = graph.edgeOffsets[edge]; j < graph.edgeOffsets[edge + 1]; ++j)
        if(!done[graph.edgePolygons[j]]) target = graph.edgePolygons[j];
      if(target < 0) throw std::logic_error("MAT erosion: inconsistent edge count");
      if(!valid[target]) continue;
      const double *c = &geometry.centroid[3 * std::size_t(target)];
      double candidate = -infinity;
      for(std::size_t j = graph.edgeOffsets[edge]; j < graph.edgeOffsets[edge + 1]; ++j) {
        const int burned = graph.edgePolygons[j];
        if(burned == target) continue;
        const double *b = &geometry.centroid[3 * std::size_t(burned)];
        const double d[3] = {b[0] - c[0], b[1] - c[1], b[2] - c[2]};
        candidate = std::max(
          candidate, times[burned] + std::sqrt((d[0] * d[0] + d[1] * d[1]) + d[2] * d[2]));
      }
      if(!std::isfinite(candidate)) throw std::overflow_error("MAT erosion: burn time overflow");
      if(candidate < times[target]) {
        times[target] = candidate;
        queue.emplace(candidate, target);
      }
    }
  }
  return times;
}

} // namespace tet
} // namespace matgmsh
