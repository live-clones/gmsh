#include "MatTetInterior.h"
#include "robustPredicates.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <string>
#include <thread>
#include <utility>

namespace matgmsh {
namespace tet {
namespace {
using Point = std::array<double, 3>;

// Integer winding of an oriented closed triangle mesh by signed ray crossings.
// Every triangle test is an exact-sign predicate; the query is never perturbed.
class IntegerWinding {
  struct Node {
    Point lo, hi;
    int left = -1, right = -1;
    std::size_t start = 0, count = 0;
  };
  std::vector<Point> vertices;
  std::vector<std::array<int, 3> > triangles;
  std::vector<std::size_t> order;
  std::vector<Node> nodes;
  std::array<Point, 16> endpoints;

  int build(std::size_t start, std::size_t count)
  {
    const int index = int(nodes.size());
    nodes.emplace_back();
    Node n;
    n.start = start;
    n.count = count;
    n.lo.fill(std::numeric_limits<double>::infinity());
    n.hi.fill(-std::numeric_limits<double>::infinity());
    for(std::size_t i = start; i < start + count; ++i)
      for(int vertex : triangles[order[i]])
        for(int k = 0; k < 3; ++k) {
          n.lo[k] = std::min(n.lo[k], vertices[vertex][k]);
          n.hi[k] = std::max(n.hi[k], vertices[vertex][k]);
        }
    if(count > 12) {
      int axis = 0;
      for(int k = 1; k < 3; ++k)
        if(n.hi[k] - n.lo[k] > n.hi[axis] - n.lo[axis]) axis = k;
      const auto center = [&](std::size_t t) {
        const auto &tr = triangles[t];
        return (static_cast<long double>(vertices[tr[0]][axis]) + vertices[tr[1]][axis] +
                vertices[tr[2]][axis]) / 3.L;
      };
      const std::size_t half = count / 2;
      std::nth_element(order.begin() + start, order.begin() + start + half,
                       order.begin() + start + count,
                       [&](std::size_t a, std::size_t b) { return center(a) < center(b); });
      n.left = build(start, half);
      n.right = build(start + half, count - half);
    }
    nodes[index] = n;
    return index;
  }
  static int sign(double v) { return v > 0. ? 1 : v < 0. ? -1 : 0; }
  static double orient(const Point &a, const Point &b, const Point &c, const Point &d)
  {
    return robustPredicates::orient3dDynamic(a.data(), b.data(), c.data(), d.data());
  }
  static bool rayBox(const Node &n, const Point &q, const Point &r)
  {
    long double begin = 0.L, end = 1.L;
    const long double infinity = std::numeric_limits<long double>::infinity();
    for(int k = 0; k < 3; ++k) {
      const long double d = static_cast<long double>(r[k]) - q[k];
      if(r[k] == q[k]) {
        if(q[k] < n.lo[k] || q[k] > n.hi[k]) return false;
        continue;
      }
      const long double dl = std::nextafter(d, -infinity), dh = std::nextafter(d, infinity);
      // Every subtraction and division is enclosed, not only the final ratio.
      // A denominator interval crossing zero cannot exclude this node.
      if(dl <= 0.L && dh >= 0.L) continue;
      long double a = infinity, b = -infinity;
      for(double bound : {n.lo[k], n.hi[k]}) {
        const long double numerator = static_cast<long double>(bound) - q[k];
        const long double nl = std::nextafter(numerator, -infinity),
                          nh = std::nextafter(numerator, infinity);
        for(long double num : {nl, nh})
          for(long double den : {dl, dh}) {
            const long double quotient = num / den;
            a = std::min(a, std::nextafter(quotient, -infinity));
            b = std::max(b, std::nextafter(quotient, infinity));
          }
      }
      begin = std::max(begin, a);
      end = std::min(end, b);
      if(begin > end) return false;
    }
    return true;
  }
  static bool pointBox(const Node &n, const Point &q, const Point &error)
  {
    const long double infinity = std::numeric_limits<long double>::infinity();
    for(int k = 0; k < 3; ++k)
      if(std::nextafter(static_cast<long double>(q[k]) + error[k], infinity) < n.lo[k] ||
         std::nextafter(static_cast<long double>(q[k]) - error[k], -infinity) > n.hi[k])
        return false;
    return true;
  }
  // A ray along a coordinate axis needs no quotient and no intersection
  // coordinate: projected side tests and forward crossings are exact.
  bool axial(const Point &q, int axis, int &count, std::vector<int> &stack) const
  {
    const int j = (axis + 1) % 3, k = (axis + 2) % 3;
    const double query[2] = {q[j], q[k]};
    count = 0;
    stack.assign(1, 0);
    while(!stack.empty()) {
      const Node &n = nodes[stack.back()];
      stack.pop_back();
      if(n.hi[axis] < q[axis] || q[j] < n.lo[j] || q[j] > n.hi[j] || q[k] < n.lo[k] ||
         q[k] > n.hi[k])
        continue;
      if(n.left >= 0) {
        stack.push_back(n.left);
        stack.push_back(n.right);
        continue;
      }
      for(std::size_t i = n.start; i < n.start + n.count; ++i) {
        const auto &t = triangles[order[i]];
        const Point &a = vertices[t[0]], &b = vertices[t[1]], &c = vertices[t[2]];
        if(std::max({a[axis], b[axis], c[axis]}) < q[axis] ||
           q[j] < std::min({a[j], b[j], c[j]}) || q[j] > std::max({a[j], b[j], c[j]}) ||
           q[k] < std::min({a[k], b[k], c[k]}) || q[k] > std::max({a[k], b[k], c[k]}))
          continue;
        const double p[3][2] = {{a[j], a[k]}, {b[j], b[k]}, {c[j], c[k]}};
        const int normal = sign(robustPredicates::orient2d(p[0], p[1], p[2]));
        const int e0 = sign(robustPredicates::orient2d(p[0], p[1], query));
        const int e1 = sign(robustPredicates::orient2d(p[1], p[2], query));
        const int e2 = sign(robustPredicates::orient2d(p[2], p[0], query));
        if(!normal) {
          if(!e0 && !e1 && !e2) return false; // ray in the triangle plane: other direction
          continue;
        }
        if((e0 && e0 != normal) || (e1 && e1 != normal) || (e2 && e2 != normal)) continue;
        const int plane = sign(orient(a, b, c, q));
        if(!plane) return false; // contact was tested before; no crossing is invented
        if(plane != normal) continue; // the crossing is behind the query
        if(!e0 || !e1 || !e2) return false; // through an edge or a vertex
        count += normal;
      }
    }
    return true;
  }
  int contact(const Point &q, const Point &error, const std::array<int, 3> &t) const
  {
    const Point &a = vertices[t[0]], &b = vertices[t[1]], &c = vertices[t[2]];
    const double plane = orient(a, b, c, q);
    long double u[3], v[3], normalBound[3];
    for(int k = 0; k < 3; ++k) {
      u[k] = static_cast<long double>(b[k]) - a[k];
      v[k] = static_cast<long double>(c[k]) - a[k];
    }
    for(int k = 0; k < 3; ++k) {
      const int j = (k + 1) % 3, l = (k + 2) % 3;
      normalBound[k] = std::abs(u[j] * v[l]) + std::abs(u[l] * v[j]);
    }
    const long double bound =
      normalBound[0] * error[0] + normalBound[1] * error[1] + normalBound[2] * error[2];
    if(std::abs(static_cast<long double>(plane)) > bound) return 0;
    for(int axis = 0; axis < 3; ++axis) {
      const int j = (axis + 1) % 3, k = (axis + 2) % 3;
      const double p[3][2] = {{a[j], a[k]}, {b[j], b[k]}, {c[j], c[k]}};
      const double query[2] = {q[j], q[k]};
      const int normal = sign(robustPredicates::orient2d(p[0], p[1], p[2]));
      if(!normal) continue;
      bool exactInside = true, possibleInside = true;
      for(int e = 0; e < 3; ++e) {
        const int next = (e + 1) % 3;
        const double value = robustPredicates::orient2d(p[e], p[next], query);
        if(sign(value) != 0 && sign(value) != normal) {
          exactInside = false;
          const long double edgeBound =
            std::abs(static_cast<long double>(p[next][0]) - p[e][0]) * error[k] +
            std::abs(static_cast<long double>(p[next][1]) - p[e][1]) * error[j];
          if(std::abs(static_cast<long double>(value)) > edgeBound) possibleInside = false;
        }
      }
      if(plane == 0. && exactInside) return 1;
      if(possibleInside) return 2;
      return 0;
    }
    return 0; // a flat skin triangle bounds nothing
  }

public:
  IntegerWinding(const std::vector<double> &xyz, const std::vector<int> &tri)
    : vertices(xyz.size() / 3), triangles(tri.size() / 3), order(tri.size() / 3)
  {
    for(std::size_t i = 0; i < vertices.size(); ++i)
      for(int k = 0; k < 3; ++k) vertices[i][k] = xyz[3 * i + k];
    for(std::size_t i = 0; i < triangles.size(); ++i)
      for(int k = 0; k < 3; ++k) triangles[i][k] = tri[3 * i + k];
    std::iota(order.begin(), order.end(), 0);
    nodes.reserve(triangles.size() / 3 + 1);
    build(0, triangles.size());
    const Node &root = nodes[0];
    double span = 0.;
    for(int k = 0; k < 3; ++k) span = std::max(span, root.hi[k] - root.lo[k]);
    if(span == 0.) span = 1.;
    static const int directions[16][3] = {
      {2, 3, 5},    {3, 7, 2},    {5, 2, 11},   {7, 11, 3},   {11, 5, 7},   {13, 3, 17},
      {17, 19, 5},  {19, 7, 23},  {23, 29, 11}, {29, 13, 31}, {31, 37, 17}, {37, 19, 41},
      {41, 43, 23}, {43, 29, 47}, {47, 53, 31}, {53, 37, 59}};
    for(int ray = 0; ray < 16; ++ray)
      for(int k = 0; k < 3; ++k) endpoints[ray][k] = root.hi[k] + span * directions[ray][k];
  }
  void query(const Point &q, const Point &error, int &winding, std::uint8_t &status) const
  {
    winding = 0;
    status = Resolved;
    std::vector<int> stack(1, 0);
    bool ambiguous = false;
    while(!stack.empty()) {
      const Node &n = nodes[stack.back()];
      stack.pop_back();
      if(!pointBox(n, q, error)) continue;
      if(n.left >= 0) {
        stack.push_back(n.left);
        stack.push_back(n.right);
        continue;
      }
      for(std::size_t i = n.start; i < n.start + n.count; ++i) {
        const int result = contact(q, error, triangles[order[i]]);
        if(result == 1) {
          status = ExactContact;
          return;
        }
        if(result == 2) ambiguous = true;
      }
    }
    if(ambiguous) {
      status = NumericalContact;
      return;
    }
    for(int axis = 0; axis < 3; ++axis) {
      int count = 0;
      if(axial(q, axis, count, stack)) {
        winding = count;
        return;
      }
    }
    for(int ray = 0; ray < 16; ++ray) {
      const Point &r = endpoints[ray];
      bool degenerate = false;
      int count = 0;
      stack.assign(1, 0);
      while(!stack.empty() && !degenerate) {
        const Node &n = nodes[stack.back()];
        stack.pop_back();
        if(!rayBox(n, q, r)) continue;
        if(n.left >= 0) {
          stack.push_back(n.left);
          stack.push_back(n.right);
          continue;
        }
        for(std::size_t i = n.start; i < n.start + n.count; ++i) {
          const auto &t = triangles[order[i]];
          const Point &a = vertices[t[0]], &b = vertices[t[1]], &c = vertices[t[2]];
          const int sq = sign(orient(a, b, c, q)), sr = sign(orient(a, b, c, r));
          if(sq == sr && sq != 0) continue;
          if(!sq && !sr) {
            degenerate = true;
            break;
          }
          // The query is off the skin and r is beyond the box of the whole
          // skin: a single endpoint in this plane cannot touch the triangle.
          if(!sq || !sr) continue;
          const int e0 = sign(orient(q, r, a, b));
          const int e1 = sign(orient(q, r, b, c));
          const int e2 = sign(orient(q, r, c, a));
          const bool positive = e0 >= 0 && e1 >= 0 && e2 >= 0;
          const bool negative = e0 <= 0 && e1 <= 0 && e2 <= 0;
          if(!positive && !negative) continue;
          if(!e0 || !e1 || !e2) {
            degenerate = true;
            break;
          }
          count += sq;
        }
      }
      if(!degenerate) {
        winding = count;
        return;
      }
    }
    status = Unresolved;
  }
};

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

void checkIndices(const std::vector<int> &indices, std::size_t sites, const char *what)
{
  for(int v : indices)
    if(v < 0 || std::size_t(v) >= sites)
      throw std::runtime_error(std::string("MAT: ") + what + " uses an unknown site");
}
} // namespace

Surface certifySurface(const std::vector<int> &tri, std::size_t sites)
{
  if(tri.size() % 3) throw std::runtime_error("MAT: incomplete triangle in a surface");
  checkIndices(tri, sites, "a surface triangle");
  Surface s;
  s.faces = tri.size() / 3;
  s.missingSites = sites;
  if(!s.faces) return s;
  // One record per triangle side, under its undirected edge. A corner is one
  // edge of the link of its vertex; corners are glued across shared edges.
  struct Half {
    std::uint32_t a, b, low, high;
    int sign;
  };
  std::vector<Half> halves;
  halves.reserve(tri.size());
  for(std::size_t c = 0; c < tri.size(); ++c) {
    const std::size_t next = c - c % 3 + (c + 1) % 3;
    const std::uint32_t x = tri[c], y = tri[next];
    if(x < y)
      halves.push_back({x, y, std::uint32_t(c), std::uint32_t(next), 1});
    else
      halves.push_back({y, x, std::uint32_t(next), std::uint32_t(c), -1});
  }
  std::sort(halves.begin(), halves.end(),
            [](const Half &p, const Half &q) { return p.a != q.a ? p.a < q.a : p.b < q.b; });
  UnionFind corners(tri.size()), nodes(sites);
  std::vector<unsigned char> bad(sites, 0), used(sites, 0);
  for(std::size_t i = 0, j = 0; i < halves.size(); i = j) {
    int sum = 0;
    for(j = i; j < halves.size() && halves[j].a == halves[i].a && halves[j].b == halves[i].b; ++j) {
      sum += halves[j].sign;
      corners.join(halves[i].low, halves[j].low);
      corners.join(halves[i].high, halves[j].high);
    }
    ++s.edges;
    if(j - i != 2) {
      ++s.badEdges;
      bad[halves[i].a] = bad[halves[i].b] = 1;
    }
    if(sum) ++s.badOrientations;
    nodes.join(halves[i].a, halves[i].b);
  }
  // The link of a vertex is one circle iff all its corners are glued together.
  const std::uint32_t none = std::numeric_limits<std::uint32_t>::max();
  std::vector<std::uint32_t> link(sites, none);
  for(std::size_t c = 0; c < tri.size(); ++c) {
    const int v = tri[c];
    used[v] = 1;
    const std::uint32_t root = corners.find(std::uint32_t(c));
    if(link[v] == none)
      link[v] = root;
    else if(link[v] != root)
      bad[v] = 1;
  }
  for(std::size_t v = 0; v < sites; ++v) {
    if(!used[v]) continue;
    ++s.vertices;
    s.badVertices += bad[v];
    if(nodes.find(std::uint32_t(v)) == v) ++s.components;
  }
  s.missingSites = sites - s.vertices;
  s.euler = static_cast<long long>(s.vertices) - static_cast<long long>(s.edges) +
            static_cast<long long>(s.faces);
  s.closedManifold = !s.badEdges && !s.badVertices;
  s.oriented = !s.badOrientations;
  return s;
}

Classification classify(const std::vector<double> &xyz, const std::vector<int> &skin,
                        const std::vector<int> &tets, unsigned threads)
{
  const std::size_t sites = xyz.size() / 3, count = tets.size() / 4;
  if(xyz.size() % 3 || tets.size() % 4)
    throw std::runtime_error("MAT classification: inconsistent arrays");
  checkIndices(tets, sites, "a tetrahedron");
  const Surface surface = certifySurface(skin, sites);
  if(!surface.closedManifold || !surface.oriented)
    throw std::runtime_error(
      "MAT classification needs a closed oriented manifold skin: " +
      std::to_string(surface.badEdges) + " edges not shared by two triangles, " +
      std::to_string(surface.badVertices) + " singular vertices, " +
      std::to_string(surface.badOrientations) + " edges with inconsistent orientation");
  Classification r;
  r.interior.assign(count, 0);
  r.volumeSign.assign(count, 0);
  r.winding.assign(count, 0);
  r.status.assign(count, ZeroVolume);
  const IntegerWinding tree(xyz, skin);
  // Roundoff of the three additions of the barycentre (gamma_3 bound).
  const double u = std::numeric_limits<double>::epsilon() / 2., gamma3 = 3. * u / (1. - 3. * u),
               factor = gamma3 / (1. - gamma3);
  const auto work = [&](std::size_t begin, std::size_t end) {
    for(std::size_t t = begin; t < end; ++t) {
      const double *p[4];
      for(int k = 0; k < 4; ++k) p[k] = &xyz[3 * std::size_t(tets[4 * t + k])];
      const double volume = robustPredicates::orient3dDynamic(p[0], p[1], p[2], p[3]);
      r.volumeSign[t] = volume > 0. ? 1 : volume < 0. ? -1 : 0;
      if(!r.volumeSign[t]) continue;
      Point center, error;
      for(int k = 0; k < 3; ++k) {
        center[k] = (((p[0][k] + p[1][k]) + p[2][k]) + p[3][k]) * .25;
        const double magnitude =
          (((std::abs(p[0][k]) + std::abs(p[1][k])) + std::abs(p[2][k])) + std::abs(p[3][k])) * .25;
        error[k] = std::nextafter(factor * magnitude, std::numeric_limits<double>::infinity());
      }
      tree.query(center, error, r.winding[t], r.status[t]);
      // Odd, not merely nonzero: see the header.
      r.interior[t] = r.status[t] == Resolved && (r.winding[t] & 1);
    }
  };
  threads = std::max(1u, std::min(threads, unsigned(count / 256 + 1)));
  if(threads == 1)
    work(0, count);
  else {
    // Every tetrahedron is an independent query writing its own entries.
    std::vector<std::thread> pool;
    std::vector<std::string> failures(threads);
    for(unsigned i = 0; i < threads; ++i)
      pool.emplace_back([&, i] {
        try {
          work(count * i / threads, count * (i + 1) / threads);
        }
        catch(const std::exception &e) {
          failures[i] = e.what();
        }
      });
    for(auto &thread : pool) thread.join();
    for(const auto &failure : failures)
      if(!failure.empty()) throw std::runtime_error(failure);
  }
  return r;
}

Dual buildDual(const std::vector<int> &tets, const std::vector<unsigned char> &interior,
               std::size_t sites)
{
  const std::size_t count = tets.size() / 4;
  if(tets.size() % 4 || interior.size() != count)
    throw std::runtime_error("MAT dual: one interior flag per tetrahedron is expected");
  checkIndices(tets, sites, "a tetrahedron");
  for(std::size_t t = 0; t < count; ++t)
    for(int i = 0; i < 4; ++i)
      for(int j = i + 1; j < 4; ++j)
        if(tets[4 * t + i] == tets[4 * t + j])
          throw std::runtime_error("MAT dual: tetrahedron with a repeated site");
  // Tetrahedra around each site, by increasing id.
  std::vector<std::size_t> first(sites + 1, 0);
  for(int v : tets) ++first[std::size_t(v) + 1];
  for(std::size_t s = 0; s < sites; ++s) first[s + 1] += first[s];
  std::vector<std::uint32_t> incident(tets.size());
  {
    std::vector<std::size_t> fill(first.begin(), first.end() - 1);
    for(std::size_t t = 0; t < count; ++t)
      for(int k = 0; k < 4; ++k) incident[fill[tets[4 * t + k]]++] = std::uint32_t(t);
  }
  Dual dual;
  dual.offsets.push_back(0);
  struct End {
    int vertex;
    std::uint32_t local, side;
  };
  std::vector<std::pair<int, std::uint32_t> > around; // (other site, tetrahedron)
  std::vector<std::array<int, 2> > opposite;
  std::vector<std::array<std::uint32_t, 2> > next;
  std::vector<End> ends;
  std::vector<unsigned char> seen;
  std::vector<int> ordered;
  for(std::size_t a = 0; a < sites; ++a) {
    around.clear();
    for(std::size_t i = first[a]; i < first[a + 1]; ++i)
      for(int k = 0; k < 4; ++k) {
        const int b = tets[4 * std::size_t(incident[i]) + k];
        if(std::size_t(b) > a) around.emplace_back(b, incident[i]);
      }
    std::sort(around.begin(), around.end());
    for(std::size_t i = 0, j = 0; i < around.size(); i = j) {
      const int b = around[i].first;
      bool allInterior = true;
      for(j = i; j < around.size() && around[j].first == b; ++j)
        allInterior = allInterior && interior[around[j].second];
      if(!allInterior) continue;
      // The link of the edge (a, b): one edge per tetrahedron, joining its
      // two other sites. A link vertex of degree one is a convex hull face.
      const std::size_t n = j - i;
      opposite.assign(n, {{-1, -1}});
      ends.clear();
      for(std::size_t l = 0; l < n; ++l) {
        const int *v = &tets[4 * std::size_t(around[i + l].second)];
        int m = 0;
        for(int k = 0; k < 4; ++k)
          if(std::size_t(v[k]) != a && v[k] != b) opposite[l][m++] = v[k];
        if(opposite[l][0] > opposite[l][1]) std::swap(opposite[l][0], opposite[l][1]);
        ends.push_back({opposite[l][0], std::uint32_t(l), 0});
        ends.push_back({opposite[l][1], std::uint32_t(l), 1});
      }
      std::sort(ends.begin(), ends.end(),
                [](const End &p, const End &q) { return p.vertex < q.vertex; });
      next.assign(n, {{0, 0}});
      bool hull = false, simple = n >= 3;
      for(std::size_t e = 0, f = 0; e < ends.size(); e = f) {
        for(f = e; f < ends.size() && ends[f].vertex == ends[e].vertex; ++f) {}
        if(f - e == 1)
          hull = true;
        else if(f - e != 2)
          simple = false;
        else {
          next[ends[e].local][ends[e].side] = ends[e + 1].local;
          next[ends[e + 1].local][ends[e + 1].side] = ends[e].local;
        }
      }
      if(hull) {
        ++dual.hullEdges;
        continue;
      }
      if(simple) {
        // From the smallest tetrahedron, entered through its smaller site.
        seen.assign(n, 0);
        ordered.clear();
        std::uint32_t current = 0, entered = 0;
        while(!seen[current]) {
          seen[current] = 1;
          ordered.push_back(int(around[i + current].second));
          const std::uint32_t leaving = 1 - entered;
          const int shared = opposite[current][leaving];
          current = next[current][leaving];
          entered = opposite[current][0] == shared ? 0 : 1;
        }
        simple = current == 0 && ordered.size() == n;
      }
      if(!simple) {
        ++dual.invalidLinks;
        continue;
      }
      dual.sitePair.push_back({{int(a), b}});
      dual.cycles.insert(dual.cycles.end(), ordered.begin(), ordered.end());
      dual.offsets.push_back(dual.cycles.size());
    }
  }
  return dual;
}

ComplexTopology topology(const Dual &dual, const std::vector<unsigned char> *keep)
{
  if(keep && keep->size() != dual.size())
    throw std::runtime_error("MAT dual: one selection flag per polygon is expected");
  ComplexTopology r;
  std::vector<std::uint64_t> edges;
  int top = -1;
  for(std::size_t p = 0; p < dual.size(); ++p) {
    if(keep && !(*keep)[p]) continue;
    ++r.faces;
    const std::size_t begin = dual.offsets[p], end = dual.offsets[p + 1];
    for(std::size_t i = begin; i < end; ++i) {
      const int a = dual.cycles[i], b = dual.cycles[i + 1 == end ? begin : i + 1];
      edges.push_back((std::uint64_t(std::min(a, b)) << 32) | std::uint32_t(std::max(a, b)));
      top = std::max(top, a);
    }
  }
  if(!r.faces) return r;
  std::sort(edges.begin(), edges.end());
  UnionFind nodes(std::size_t(top) + 1);
  std::vector<unsigned char> used(std::size_t(top) + 1, 0);
  for(std::size_t i = 0, j = 0; i < edges.size(); i = j) {
    for(j = i; j < edges.size() && edges[j] == edges[i]; ++j) {}
    ++r.edges;
    r.freeEdges += j - i == 1;
    r.junctionEdges += j - i > 2;
    const std::uint32_t a = std::uint32_t(edges[i] >> 32), b = std::uint32_t(edges[i]);
    used[a] = used[b] = 1;
    nodes.join(a, b);
  }
  for(std::size_t v = 0; v < used.size(); ++v) {
    if(!used[v]) continue;
    ++r.vertices;
    if(nodes.find(std::uint32_t(v)) == v) ++r.components;
  }
  r.euler = static_cast<long long>(r.vertices) - static_cast<long long>(r.edges) +
            static_cast<long long>(r.faces);
  return r;
}

Report certify(const std::vector<int> &skin, const std::vector<int> &tets,
               const Classification &c, const Dual &dual, std::size_t sites)
{
  const std::size_t count = tets.size() / 4;
  if(tets.size() % 4 || c.interior.size() != count || c.status.size() != count ||
     c.volumeSign.size() != count)
    throw std::runtime_error("MAT certificate: inconsistent classification");
  Report r;
  r.computed = true;
  r.sites = sites;
  r.tetrahedra = count;
  for(std::size_t t = 0; t < count; ++t) {
    r.interior += c.interior[t] != 0;
    r.zeroVolume += c.status[t] == ZeroVolume;
    r.exactContact += c.status[t] == ExactContact;
    r.numericalContact += c.status[t] == NumericalContact;
    r.unresolved += c.status[t] == Unresolved;
  }
  r.polygons = dual.size();
  r.hullEdges = dual.hullEdges;
  r.invalidLinks = dual.invalidLinks;
  // Outward faces of the interior tetrahedra under their sorted sites; the top
  // bit of the last one records an odd permutation. A face used once is on
  // the boundary of their union.
  const std::uint32_t oddBit = 0x80000000u;
  std::vector<std::array<std::uint32_t, 3> > faces;
  faces.reserve(4 * r.interior);
  static const int corner[4][3] = {{1, 2, 3}, {0, 3, 2}, {0, 1, 3}, {0, 2, 1}};
  for(std::size_t t = 0; t < count; ++t) {
    if(!c.interior[t]) continue;
    int a[4] = {tets[4 * t], tets[4 * t + 1], tets[4 * t + 2], tets[4 * t + 3]};
    if(c.volumeSign[t] > 0) std::swap(a[0], a[1]);
    for(const auto &f : corner) {
      std::uint32_t x = a[f[0]], y = a[f[1]], z = a[f[2]];
      bool odd = false;
      if(x > y) { std::swap(x, y); odd = !odd; }
      if(y > z) { std::swap(y, z); odd = !odd; }
      if(x > y) { std::swap(x, y); odd = !odd; }
      faces.push_back({{x, y, odd ? z | oddBit : z}});
    }
  }
  const auto same = [&](const std::array<std::uint32_t, 3> &p,
                        const std::array<std::uint32_t, 3> &q) {
    return p[0] == q[0] && p[1] == q[1] && (p[2] & ~oddBit) == (q[2] & ~oddBit);
  };
  std::sort(faces.begin(), faces.end(),
            [&](const std::array<std::uint32_t, 3> &p, const std::array<std::uint32_t, 3> &q) {
              if(p[0] != q[0]) return p[0] < q[0];
              if(p[1] != q[1]) return p[1] < q[1];
              return (p[2] & ~oddBit) < (q[2] & ~oddBit);
            });
  std::vector<int> boundary;
  for(std::size_t i = 0, j = 0; i < faces.size(); i = j) {
    for(j = i; j < faces.size() && same(faces[j], faces[i]); ++j) {}
    r.boundaryFacesOverValenceTwo += j - i > 2;
    if(j - i != 1) continue;
    const int x = int(faces[i][0]), y = int(faces[i][1]), z = int(faces[i][2] & ~oddBit);
    if(faces[i][2] & oddBit)
      boundary.insert(boundary.end(), {x, z, y});
    else
      boundary.insert(boundary.end(), {x, y, z});
  }
  faces = {};
  r.skin = certifySurface(skin, sites);
  r.boundary = certifySurface(boundary, sites);
  r.dual = topology(dual);
  r.certified = r.boundary.closedManifold && r.boundary.oriented && !r.boundary.missingSites &&
                r.boundary.euler == r.skin.euler && !r.invalidLinks &&
                2 * r.dual.euler == r.skin.euler;
  return r;
}

} // namespace tet
} // namespace matgmsh
