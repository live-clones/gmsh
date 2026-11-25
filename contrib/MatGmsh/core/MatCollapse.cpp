#include "MatCollapse.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <stdexcept>
#include <utility>

namespace matgmsh {
namespace tet {
namespace {
struct UnionFind {
  std::vector<std::uint32_t> parent;
  explicit UnionFind(std::size_t n) : parent(n) { std::iota(parent.begin(), parent.end(), 0u); }
  std::uint32_t find(std::uint32_t v)
  {
    while(parent[v] != v) {
      parent[v] = parent[parent[v]];
      v = parent[v];
    }
    return v;
  }
  void join(std::uint32_t a, std::uint32_t b)
  {
    a = find(a);
    b = find(b);
    if(a != b) parent[std::max(a, b)] = std::min(a, b);
  }
};

std::uint64_t pairKey(int a, int b)
{
  return (std::uint64_t(std::min(a, b)) << 32) | std::uint32_t(std::max(a, b));
}
std::pair<int, int> sortedPair(int a, int b) { return std::minmax(a, b); }
double dot(const double *a, const double *b) { return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2]; }
void cross(const double *a, const double *b, double *c)
{
  c[0] = a[1] * b[2] - a[2] * b[1];
  c[1] = a[2] * b[0] - a[0] * b[2];
  c[2] = a[0] * b[1] - a[1] * b[0];
}
} // namespace

SkinSegments skinSegments(const std::vector<double> &xyz, const std::vector<int> &skin,
                          const std::vector<int> &trianglePatch,
                          const std::vector<std::array<int, 2> > &curves,
                          const std::vector<signed char> &side)
{
  const std::size_t count = skin.size() / 3, sites = xyz.size() / 3;
  if(skin.size() % 3 || xyz.size() % 3 || trianglePatch.size() != count ||
     (!side.empty() && side.size() != count))
    throw std::runtime_error("MAT skin segments: inconsistent arrays");
  for(int v : skin)
    if(v < 0 || std::size_t(v) >= sites)
      throw std::runtime_error("MAT skin segments: a triangle uses an unknown site");
  // Directed sides of the skin triangles under their undirected edge.
  struct Use {
    std::uint64_t key;
    int triangle, first, last;
  };
  std::vector<Use> uses;
  uses.reserve(skin.size());
  for(std::size_t t = 0; t < count; ++t)
    for(int k = 0; k < 3; ++k) {
      const int a = skin[3 * t + k], b = skin[3 * t + (k + 1) % 3];
      uses.push_back({pairKey(a, b), int(t), a, b});
    }
  std::sort(uses.begin(), uses.end(), [](const Use &x, const Use &y) {
    return x.key != y.key ? x.key < y.key : x.triangle < y.triangle;
  });
  UnionFind shells(count);
  std::size_t defects = 0;
  for(std::size_t i = 0, j = 0; i < uses.size(); i = j) {
    for(j = i; j < uses.size() && uses[j].key == uses[i].key; ++j)
      shells.join(std::uint32_t(uses[i].triangle), std::uint32_t(uses[j].triangle));
    if(j - i != 2 || (uses[i].first == uses[i + 1].first && uses[i].last == uses[i + 1].last))
      ++defects;
  }
  std::size_t components = 0;
  for(std::size_t t = 0; t < count; ++t) components += shells.find(std::uint32_t(t)) == t;

  double lo[3] = {0., 0., 0.}, hi[3] = {0., 0., 0.};
  for(std::size_t v = 0; v < sites; ++v)
    for(int k = 0; k < 3; ++k) {
      lo[k] = v ? std::min(lo[k], xyz[3 * v + k]) : xyz[k];
      hi[k] = v ? std::max(hi[k], xyz[3 * v + k]) : xyz[k];
    }
  const double reference[3] = {(lo[0] + hi[0]) / 2, (lo[1] + hi[1]) / 2, (lo[2] + hi[2]) / 2};
  std::vector<double> normals(3 * count, 0.), norms(count);
  double volume = 0.;
  for(std::size_t t = 0; t < count; ++t) {
    const double *p[3] = {&xyz[3 * std::size_t(skin[3 * t])], &xyz[3 * std::size_t(skin[3 * t + 1])],
                          &xyz[3 * std::size_t(skin[3 * t + 2])]};
    double u[3], w[3], n[3], r[3][3];
    for(int k = 0; k < 3; ++k) {
      u[k] = p[1][k] - p[0][k];
      w[k] = p[2][k] - p[0][k];
      for(int c = 0; c < 3; ++c) r[c][k] = p[c][k] - reference[k];
    }
    cross(u, w, n);
    norms[t] = std::sqrt(dot(n, n));
    if(norms[t] > 0.)
      for(int k = 0; k < 3; ++k) normals[3 * t + k] = n[k] / norms[t];
    cross(r[1], r[2], n);
    volume += dot(r[0], n) / 6;
  }
  // Orientation of each shell with respect to the material, at its root:
  // +1 outward, -1 inward, anything else unknown.
  SkinSegments result;
  std::vector<signed char> shell(count, 0);
  if(side.empty()) {
    result.materialSide = components == 1 && !defects && volume != 0.;
    if(result.materialSide) shell[shells.find(0)] = volume > 0. ? 1 : -1;
  }
  else if(!defects) {
    for(std::size_t t = 0; t < count; ++t) {
      if(!side[t]) continue;
      signed char &known = shell[shells.find(std::uint32_t(t))];
      known = !known || known == side[t] ? side[t] : 2;
    }
    result.materialSide = count > 0;
    for(std::size_t t = 0; t < count; ++t)
      if(shells.find(std::uint32_t(t)) == t && shell[t] != 1 && shell[t] != -1)
        result.materialSide = false;
  }

  std::vector<std::pair<std::uint64_t, std::size_t> > order;
  order.reserve(curves.size());
  for(std::size_t i = 0; i < curves.size(); ++i) {
    if(curves[i][0] < 0 || curves[i][1] < 0 || std::size_t(curves[i][0]) >= sites ||
       std::size_t(curves[i][1]) >= sites)
      throw std::runtime_error("MAT skin segments: a curve uses an unknown site");
    order.emplace_back(pairKey(curves[i][0], curves[i][1]), i);
  }
  std::sort(order.begin(), order.end());
  result.segments.reserve(order.size());
  for(const auto &item : order) {
    Segment s;
    s.a = int(item.first >> 32);
    s.b = int(std::uint32_t(item.first));
    const auto begin = std::lower_bound(
      uses.begin(), uses.end(), item.first,
      [](const Use &use, std::uint64_t key) { return use.key < key; });
    auto end = begin;
    while(end != uses.end() && end->key == item.first) ++end;
    if(end - begin == 2) {
      const Use &first = *begin, &second = *(begin + 1);
      const std::size_t ta = first.triangle, tb = second.triangle;
      s.patchA = trianglePatch[ta];
      s.patchB = trianglePatch[tb];
      double tangent[3];
      for(int k = 0; k < 3; ++k)
        tangent[k] = xyz[3 * std::size_t(first.last) + k] - xyz[3 * std::size_t(first.first) + k];
      const double length = std::sqrt(dot(tangent, tangent));
      const bool conflict = first.first == second.first && first.last == second.last;
      const double factor = shell[shells.find(std::uint32_t(ta))];
      if(!conflict && norms[ta] != 0. && norms[tb] != 0. && length != 0. &&
         (factor == 1. || factor == -1.)) {
        // delta = atan2(t . (nA x nB), nA . nB) with outward normals and the
        // tangent induced by A: positive is convex.
        double na[3], nb[3], t[3], n[3];
        for(int k = 0; k < 3; ++k) {
          na[k] = factor * normals[3 * ta + k];
          nb[k] = factor * normals[3 * tb + k];
          t[k] = factor * tangent[k] / length;
        }
        cross(na, nb, n);
        const double sine = dot(t, n), cosine = dot(na, nb);
        if(sine != 0. || cosine >= 0.) s.sign = sine > 0. ? 1 : sine < 0. ? -1 : 0;
      }
    }
    result.segments.push_back(s);
  }
  return result;
}

Wings wings(const Dual &dual, const Adjacency &graph, const Geometry &geometry,
            const std::vector<double> &sites, const std::vector<std::size_t> &patchOffsets,
            const std::vector<int> &patchValues, const std::vector<Segment> &segments,
            const std::vector<int> &tets)
{
  const std::size_t count = dual.size(), siteCount = sites.size() / 3;
  if(patchOffsets.size() != siteCount + 1 || patchOffsets.back() != patchValues.size())
    throw std::runtime_error("MAT wings: one patch list per site is expected");
  Wings w;
  w.convex.assign(count, 0);
  w.wing.assign(count, 0);
  // Sites with the same patches share one support id.
  std::map<std::vector<int>, int> supportIds;
  std::vector<std::vector<int> > supports;
  std::vector<int> support(siteCount);
  for(std::size_t s = 0; s < siteCount; ++s) {
    std::vector<int> patches(patchValues.begin() + patchOffsets[s],
                             patchValues.begin() + patchOffsets[s + 1]);
    const auto inserted = supportIds.emplace(patches, int(supports.size()));
    if(inserted.second) supports.push_back(std::move(patches));
    support[s] = inserted.first->second;
  }
  // Segments between two distinct known patches, by patch pair.
  std::map<std::pair<int, int>, std::vector<int> > byPatches;
  for(std::size_t i = 0; i < segments.size(); ++i) {
    const Segment &s = segments[i];
    if(s.patchA >= 0 && s.patchB >= 0 && s.patchA != s.patchB)
      byPatches[sortedPair(s.patchA, s.patchB)].push_back(int(i));
  }
  std::map<std::pair<int, int>, std::vector<int> > candidatesBySupports;
  const auto candidates = [&](int first, int second) -> const std::vector<int> & {
    const auto key = sortedPair(first, second);
    const auto found = candidatesBySupports.find(key);
    if(found != candidatesBySupports.end()) return found->second;
    std::vector<int> list;
    for(int a : supports[first])
      for(int b : supports[second]) {
        if(a == b) continue;
        const auto group = byPatches.find(sortedPair(a, b));
        if(group != byPatches.end())
          list.insert(list.end(), group->second.begin(), group->second.end());
      }
    std::sort(list.begin(), list.end());
    list.erase(std::unique(list.begin(), list.end()), list.end());
    return candidatesBySupports.emplace(key, std::move(list)).first->second;
  };
  // Nearest common CAD segment of each polygon; an exact tie between segments
  // of different or unknown signs stays unknown.
  std::vector<std::pair<int, int> > patchPair(count, {-1, -1});
  for(std::size_t p = 0; p < count; ++p) {
    const std::vector<int> &list =
      candidates(support[dual.sitePair[p][0]], support[dual.sitePair[p][1]]);
    if(list.empty()) continue;
    const double *c = &geometry.centroid[3 * p];
    if(!std::isfinite(c[0]) || !std::isfinite(c[1]) || !std::isfinite(c[2])) continue;
    double best = std::numeric_limits<double>::infinity();
    int selected = -1;
    bool conflict = false;
    for(int index : list) {
      const Segment &s = segments[index];
      const double *a = &sites[3 * std::size_t(s.a)], *b = &sites[3 * std::size_t(s.b)];
      double delta[3], relative[3], residual[3];
      for(int k = 0; k < 3; ++k) {
        delta[k] = b[k] - a[k];
        relative[k] = c[k] - a[k];
      }
      const double length2 = dot(delta, delta);
      double fraction = length2 > 0. ? dot(relative, delta) / length2 : 0.;
      fraction = std::min(1., std::max(0., fraction));
      for(int k = 0; k < 3; ++k) residual[k] = relative[k] - fraction * delta[k];
      const double distance2 = dot(residual, residual);
      if(distance2 < best) {
        best = distance2;
        selected = index;
        conflict = false;
      }
      else if(distance2 == best && (s.sign == 2 || s.sign != segments[selected].sign))
        conflict = true;
    }
    if(selected < 0 || conflict || segments[selected].sign != 1) continue;
    w.convex[p] = 1;
    patchPair[p] = sortedPair(segments[selected].patchA, segments[selected].patchB);
  }
  // Convex polygons of the same patch pair across a shared edge form a wing.
  UnionFind parts(count);
  for(std::size_t e = 0; e < graph.edges(); ++e)
    for(std::size_t i = graph.edgeOffsets[e]; i < graph.edgeOffsets[e + 1]; ++i) {
      const int p = graph.edgePolygons[i];
      if(!w.convex[p]) continue;
      for(std::size_t j = i + 1; j < graph.edgeOffsets[e + 1]; ++j) {
        const int q = graph.edgePolygons[j];
        if(w.convex[q] && patchPair[q] == patchPair[p])
          parts.join(std::uint32_t(p), std::uint32_t(q));
      }
    }
  // A wing is anchored when an end of one of its free edges is the dual of a
  // tetrahedron that contains a convex CAD segment of its patch pair.
  std::map<std::uint64_t, std::vector<int> > convexSegments;
  for(std::size_t i = 0; i < segments.size(); ++i) {
    const Segment &s = segments[i];
    if(s.sign == 1 && s.patchA >= 0 && s.patchB >= 0 && s.patchA != s.patchB)
      convexSegments[pairKey(s.a, s.b)].push_back(int(i));
  }
  std::vector<unsigned char> anchored(count, 0);
  for(std::size_t e = 0; e < graph.edges(); ++e) {
    if(graph.valence(e) != 1) continue;
    const int p = graph.edgePolygons[graph.edgeOffsets[e]];
    if(!w.convex[p]) continue;
    for(int vertex : graph.edgeVertices[e]) {
      if(4 * std::size_t(vertex) + 3 >= tets.size())
        throw std::runtime_error("MAT wings: one tetrahedron per dual vertex is expected");
      const int *t = &tets[4 * std::size_t(vertex)];
      for(int i = 0; i < 4; ++i)
        for(int j = i + 1; j < 4; ++j) {
          const auto found = convexSegments.find(pairKey(t[i], t[j]));
          if(found == convexSegments.end()) continue;
          for(int index : found->second)
            if(patchPair[p] == sortedPair(segments[index].patchA, segments[index].patchB))
              anchored[parts.find(std::uint32_t(p))] = 1;
        }
    }
  }
  for(std::size_t p = 0; p < count; ++p) {
    if(!w.convex[p]) continue;
    const std::uint32_t root = parts.find(std::uint32_t(p));
    w.wing[p] = anchored[root];
    if(root == p) {
      ++w.components;
      w.anchored += anchored[root];
    }
  }
  return w;
}

Collapse collapse(const Dual &dual, const Adjacency &graph, const std::vector<double> &et,
                  const std::vector<unsigned char> &wing, double threshold)
{
  const std::size_t count = dual.size();
  if(et.size() != count || wing.size() != count)
    throw std::runtime_error("MAT collapse: one erosion thickness and wing flag per polygon");
  Collapse r;
  r.keep.assign(count, 1);
  std::vector<unsigned char> eligible(count), queued(count, 0), activeEdge(graph.edges(), 1);
  std::vector<std::uint32_t> remaining(graph.edges());
  for(std::size_t p = 0; p < count; ++p) {
    eligible[p] = (wing[p] || et[p] < threshold) && !std::isnan(et[p]);
    r.eligible += eligible[p];
  }
  using Item = std::pair<double, int>;
  std::priority_queue<Item, std::vector<Item>, std::greater<Item> > queue;
  const auto push = [&](int p) {
    if(!eligible[p] || !r.keep[p] || queued[p]) return;
    queue.emplace(et[p], p);
    queued[p] = 1;
  };
  for(std::size_t e = 0; e < graph.edges(); ++e) remaining[e] = std::uint32_t(graph.valence(e));
  for(std::size_t e = 0; e < graph.edges(); ++e)
    if(remaining[e] == 1) push(graph.edgePolygons[graph.edgeOffsets[e]]);
  while(!queue.empty()) {
    const int p = queue.top().second;
    queue.pop();
    queued[p] = 0;
    if(!r.keep[p]) continue;
    // The polygon leaves with its smallest free edge.
    int free = -1;
    for(std::size_t i = dual.offsets[p]; i < dual.offsets[p + 1] && free < 0; ++i) {
      const int e = graph.polygonEdges[i];
      if(activeEdge[e] && remaining[e] == 1) free = e;
    }
    if(free < 0) throw std::logic_error("MAT collapse: a queued polygon lost its free edge");
    r.keep[p] = 0;
    activeEdge[free] = 0;
    ++r.removed;
    for(std::size_t i = dual.offsets[p]; i < dual.offsets[p + 1]; ++i) {
      const int e = graph.polygonEdges[i];
      if(--remaining[e] != 1) continue;
      for(std::size_t j = graph.edgeOffsets[e]; j < graph.edgeOffsets[e + 1]; ++j)
        if(r.keep[graph.edgePolygons[j]]) push(graph.edgePolygons[j]);
    }
  }
  for(std::size_t p = 0; p < count; ++p) {
    r.blocked += eligible[p] && r.keep[p];
    r.wingsBlocked += wing[p] && r.keep[p];
  }
  // Prune the trees of edges left without polygon: a vertex that belongs to
  // no kept polygon and to one edge leaves with that edge.
  int top = -1;
  for(int v : dual.cycles) top = std::max(top, v);
  const std::size_t vertices = std::size_t(top + 1);
  std::vector<unsigned char> onSurface(vertices, 0);
  for(std::size_t p = 0; p < count; ++p)
    if(r.keep[p])
      for(std::size_t i = dual.offsets[p]; i < dual.offsets[p + 1]; ++i)
        onSurface[dual.cycles[i]] = 1;
  std::vector<std::size_t> first(vertices + 1, 0);
  for(std::size_t e = 0; e < graph.edges(); ++e)
    if(activeEdge[e])
      for(int v : graph.edgeVertices[e]) ++first[std::size_t(v) + 1];
  for(std::size_t v = 0; v < vertices; ++v) first[v + 1] += first[v];
  std::vector<int> incident(first[vertices]);
  std::vector<std::uint32_t> degree(vertices, 0);
  for(std::size_t e = 0; e < graph.edges(); ++e)
    if(activeEdge[e])
      for(int v : graph.edgeVertices[e]) incident[first[v] + degree[v]++] = int(e);
  std::vector<int> stack;
  for(std::size_t v = 0; v < vertices; ++v)
    if(!onSurface[v] && degree[v] == 1) stack.push_back(int(v));
  while(!stack.empty()) {
    const int v = stack.back();
    stack.pop_back();
    if(onSurface[v] || degree[v] != 1) continue;
    int edge = -1;
    for(std::size_t i = first[v]; i < first[v + 1]; ++i)
      if(activeEdge[incident[i]]) edge = incident[i];
    if(edge < 0) throw std::logic_error("MAT collapse: inconsistent free vertex");
    const int other = graph.edgeVertices[edge][0] == v ? graph.edgeVertices[edge][1] :
                                                        graph.edgeVertices[edge][0];
    activeEdge[edge] = 0;
    --degree[v];
    --degree[other];
    if(!onSurface[other] && degree[other] == 1) stack.push_back(other);
  }
  for(std::size_t e = 0; e < graph.edges(); ++e) r.wireEdges += activeEdge[e] && !remaining[e];
  return r;
}

Filtered filter(const Dual &dual, const FilterInput &in)
{
  if(!in.sites || !in.vertices || !in.skin || !in.tetrahedra)
    throw std::runtime_error("MAT filter: missing input arrays");
  if(!(in.thickness > 0.) || !std::isfinite(in.thickness) || !std::isfinite(in.threshold))
    throw std::runtime_error("MAT filter: invalid thickness or threshold");
  Filtered f;
  CollapseReport &r = f.report;
  r.computed = true;
  r.thickness = in.thickness;
  r.threshold = in.threshold;
  const Adjacency graph = adjacency(dual);
  f.geometry = geometry(dual, *in.vertices, *in.sites);
  r.zeroAreaPolygons = f.geometry.zeroArea;
  const std::vector<double> times = burnTimes(dual, graph, f.geometry);
  f.erosionOverThickness.resize(dual.size());
  for(std::size_t p = 0; p < dual.size(); ++p) {
    f.erosionOverThickness[p] = (times[p] - f.geometry.radius[p]) / in.thickness;
    r.unreachedPolygons += std::isinf(times[p]);
  }
  const SkinSegments skin =
    skinSegments(*in.sites, *in.skin, in.trianglePatch, in.curves, in.skinSide);
  r.materialSide = skin.materialSide;
  r.curveSegments = skin.segments.size();
  for(const Segment &s : skin.segments) r.convexSegments += s.sign == 1;
  Wings w = wings(dual, graph, f.geometry, *in.sites, in.patchOffsets, in.patchValues,
                  skin.segments, *in.tetrahedra);
  r.wingComponents = w.components;
  r.anchoredWingComponents = w.anchored;
  for(std::size_t p = 0; p < dual.size(); ++p) {
    r.convexPolygons += w.convex[p];
    r.wingPolygons += w.wing[p];
  }
  Collapse c = collapse(dual, graph, f.erosionOverThickness, w.wing, in.threshold);
  r.eligible = c.eligible;
  r.removed = c.removed;
  r.blocked = c.blocked;
  r.wingsBlocked = c.wingsBlocked;
  r.wireEdges = c.wireEdges;
  f.keep = std::move(c.keep);
  f.wing = std::move(w.wing);
  r.surface = topology(dual, &f.keep);
  return f;
}

} // namespace tet
} // namespace matgmsh
