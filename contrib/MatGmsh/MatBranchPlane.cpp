// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
// See LICENSE.txt in the Gmsh root directory for license information.
//
// Extension of one branch of a MAT mesh in its plane. The branch is replaced
// by the part of its plane that the skin and the other branches bound around
// it:
//
//   branch --fit--> plane
//   T: a triangulation of a rectangle of the plane
//   T, the skin and the other branches that reach the plane --co-refine-->
//     T cut along them into fragments
//   the fragments that hold a triangle of the branch replace the branch
//
// This is done twice: with two triangles around the whole skin, to find the
// fragments, then with a grid of the size asked around these fragments only,
// to mesh them. Nothing is moved: the skin and the other branches only cut T.

#include "MatPipeline.h"
#include "DiscreteCADArrangement.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <Eigen/Dense>

namespace matgmsh_native {
namespace {

using Vec = std::array<double, 3>;

Vec point(const Mesh &m, int vertex)
{
  return {m.xyz[3 * std::size_t(vertex)], m.xyz[3 * std::size_t(vertex) + 1],
          m.xyz[3 * std::size_t(vertex) + 2]};
}
Vec sub(const Vec &a, const Vec &b) { return {a[0] - b[0], a[1] - b[1], a[2] - b[2]}; }
double dot(const Vec &a, const Vec &b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
Vec cross(const Vec &a, const Vec &b)
{
  return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
}
double norm(const Vec &a) { return std::sqrt(dot(a, a)); }

// the area of a triangle and its centroid
double triangle(const Mesh &m, std::size_t t, Vec &centroid, Vec *normal = nullptr)
{
  const Vec a = point(m, m.triangles[3 * t]), b = point(m, m.triangles[3 * t + 1]),
            c = point(m, m.triangles[3 * t + 2]);
  for(int k = 0; k < 3; ++k) centroid[k] = (a[k] + b[k] + c[k]) / 3.;
  const Vec n = cross(sub(b, a), sub(c, a));
  if(normal) *normal = n;
  return .5 * norm(n);
}

// the value below which the given fraction of the weight lies
double quantile(std::vector<std::pair<double, double> > &valueWeight, double fraction)
{
  if(valueWeight.empty()) return 0.;
  std::sort(valueWeight.begin(), valueWeight.end());
  double total = 0., sum = 0.;
  for(const auto &x : valueWeight) total += x.second;
  for(const auto &x : valueWeight) {
    sum += x.second;
    if(sum >= fraction * total) return x.first;
  }
  return valueWeight.back().first;
}

std::uint64_t edgeKey(int a, int b)
{
  if(a > b) std::swap(a, b);
  return (std::uint64_t(std::uint32_t(a)) << 32) | std::uint32_t(b);
}

struct Frame {
  Vec o, n, u, v;
  Frame(const BranchPlane &p)
  {
    o = {p.origin[0], p.origin[1], p.origin[2]};
    n = {p.normal[0], p.normal[1], p.normal[2]};
    const double length = norm(n);
    for(double &x : n) x /= length;
    int smallest = 0;
    for(int k = 1; k < 3; ++k)
      if(std::abs(n[k]) < std::abs(n[smallest])) smallest = k;
    Vec axis = {0., 0., 0.};
    axis[smallest] = 1.;
    u = cross(n, axis);
    const double lu = norm(u);
    for(double &x : u) x /= lu;
    v = cross(n, u);
  }
  double distance(const Vec &x) const { return dot(sub(x, o), n); }
  std::array<double, 2> uv(const Vec &x) const
  {
    const Vec d = sub(x, o);
    return {dot(d, u), dot(d, v)};
  }
  Vec at(double a, double b) const
  {
    return {o[0] + a * u[0] + b * v[0], o[1] + a * u[1] + b * v[1], o[2] + a * u[2] + b * v[2]};
  }
};

// whether the point is in the triangle, in the plane
bool inside(const std::array<double, 2> &p, const std::array<double, 2> &a,
            const std::array<double, 2> &b, const std::array<double, 2> &c)
{
  const auto side = [](const std::array<double, 2> &p, const std::array<double, 2> &q,
                       const std::array<double, 2> &r) {
    return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]);
  };
  const double s0 = side(a, b, p), s1 = side(b, c, p), s2 = side(c, a, p);
  return (s0 >= 0. && s1 >= 0. && s2 >= 0.) || (s0 <= 0. && s1 <= 0. && s2 <= 0.);
}

// the point of the triangle that is closest to p
Vec closestOnTriangle(const Vec &p, const Vec &a, const Vec &b, const Vec &c)
{
  const Vec ab = sub(b, a), ac = sub(c, a), ap = sub(p, a);
  const double d1 = dot(ab, ap), d2 = dot(ac, ap);
  if(d1 <= 0. && d2 <= 0.) return a;
  const Vec bp = sub(p, b);
  const double d3 = dot(ab, bp), d4 = dot(ac, bp);
  if(d3 >= 0. && d4 <= d3) return b;
  const auto along = [](const Vec &from, const Vec &direction, double s) {
    return Vec{from[0] + s * direction[0], from[1] + s * direction[1], from[2] + s * direction[2]};
  };
  const double vc = d1 * d4 - d3 * d2;
  if(vc <= 0. && d1 >= 0. && d3 <= 0.) return along(a, ab, d1 == d3 ? 0. : d1 / (d1 - d3));
  const Vec cp = sub(p, c);
  const double d5 = dot(ab, cp), d6 = dot(ac, cp);
  if(d6 >= 0. && d5 <= d6) return c;
  const double vb = d5 * d2 - d1 * d6;
  if(vb <= 0. && d2 >= 0. && d6 <= 0.) return along(a, ac, d2 == d6 ? 0. : d2 / (d2 - d6));
  const double va = d3 * d6 - d5 * d4;
  if(va <= 0. && d4 - d3 >= 0. && d5 - d6 >= 0.) {
    const double s = (d4 - d3) + (d5 - d6);
    return along(b, sub(c, b), s == 0. ? 0. : (d4 - d3) / s);
  }
  const double sum = va + vb + vc;
  if(!(sum != 0.)) return a;
  const double v = vb / sum, w = vc / sum;
  return {a[0] + v * ab[0] + w * ac[0], a[1] + v * ab[1] + w * ac[1], a[2] + v * ab[2] + w * ac[2]};
}

} // namespace

std::vector<BranchPlane> branchPlanes(const Mesh &mesh)
{
  const std::size_t count = mesh.triangles.size() / 3;
  std::map<int, std::vector<std::size_t> > byBranch;
  for(std::size_t t = 0; t < count; ++t) byBranch[t < mesh.branch.size() ? mesh.branch[t] : 0].push_back(t);
  std::vector<BranchPlane> planes;
  for(const auto &entry : byBranch) {
    const std::vector<std::size_t> &triangles = entry.second;
    std::vector<double> area(triangles.size());
    std::vector<Vec> centroid(triangles.size());
    BranchPlane p;
    p.branch = entry.first;
    p.triangles = triangles.size();
    for(std::size_t i = 0; i < triangles.size(); ++i) {
      area[i] = triangle(mesh, triangles[i], centroid[i]);
      p.area += area[i];
    }
    if(!(p.area > 0.)) continue;
    // Least squares on the centroids, weighted by area; fitted again twice
    // without the tenth of the area that is farthest (the cusp of a sheet
    // next to a junction).
    std::vector<unsigned char> used(triangles.size(), 1);
    std::vector<double> distance(triangles.size(), 0.);
    Vec origin = {0., 0., 0.}, normal = {0., 0., 1.};
    for(int pass = 0; pass < 3; ++pass) {
      double weight = 0.;
      origin = {0., 0., 0.};
      for(std::size_t i = 0; i < triangles.size(); ++i) {
        if(!used[i]) continue;
        weight += area[i];
        for(int k = 0; k < 3; ++k) origin[k] += area[i] * centroid[i][k];
      }
      for(double &x : origin) x /= weight;
      Eigen::Matrix3d covariance = Eigen::Matrix3d::Zero();
      for(std::size_t i = 0; i < triangles.size(); ++i) {
        if(!used[i]) continue;
        const Vec d = sub(centroid[i], origin);
        for(int r = 0; r < 3; ++r)
          for(int c = 0; c < 3; ++c) covariance(r, c) += area[i] * d[r] * d[c];
      }
      const Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> solver(covariance);
      const Eigen::Vector3d smallest = solver.eigenvectors().col(0);
      normal = {smallest[0], smallest[1], smallest[2]};
      std::vector<std::pair<double, double> > valueWeight(triangles.size());
      for(std::size_t i = 0; i < triangles.size(); ++i) {
        distance[i] = std::abs(dot(sub(centroid[i], origin), normal));
        valueWeight[i] = {distance[i], area[i]};
      }
      const double limit = quantile(valueWeight, .9);
      for(std::size_t i = 0; i < triangles.size(); ++i) used[i] = distance[i] <= limit;
    }
    std::vector<std::pair<double, double> > valueWeight(triangles.size());
    for(std::size_t i = 0; i < triangles.size(); ++i) {
      valueWeight[i] = {distance[i], area[i]};
      p.maxDeviation = std::max(p.maxDeviation, distance[i]);
    }
    p.deviation = quantile(valueWeight, .95);
    for(int k = 0; k < 3; ++k) {
      p.origin[k] = origin[k];
      p.normal[k] = normal[k];
    }
    planes.push_back(p);
  }
  std::sort(planes.begin(), planes.end(),
            [](const BranchPlane &a, const BranchPlane &b) { return a.area > b.area; });
  return planes;
}

namespace {

// T, a grid of nx by ny cells over a rectangle of the plane, cut by the
// cutters: its triangles after the co-refinement, in fragments.
struct PlaneCut {
  std::vector<double> xyz;
  std::vector<int> triangles;       // all the triangles of the co-refinement
  std::vector<int> pieces;          // those of T
  std::vector<int> fragment;        // of each piece
  std::vector<std::array<double, 2> > uv;
  double lo[2], hi[2];

  bool compute(const Frame &frame, const double low[2], const double high[2], int nx, int ny,
               const std::vector<double> &cutterXyz, const std::vector<int> &cutterTriangles,
               std::string &error)
  {
    for(int k = 0; k < 2; ++k) {
      lo[k] = low[k];
      hi[k] = high[k];
    }
    std::vector<double> in;
    std::vector<int> tri;
    in.reserve(3 * std::size_t(nx + 1) * (ny + 1) + cutterXyz.size());
    for(int j = 0; j <= ny; ++j)
      for(int i = 0; i <= nx; ++i) {
        // the ends exactly on the rectangle
        const double a = i == nx ? hi[0] : lo[0] + (hi[0] - lo[0]) * i / nx;
        const double b = j == ny ? hi[1] : lo[1] + (hi[1] - lo[1]) * j / ny;
        const Vec p = frame.at(a, b);
        in.insert(in.end(), p.begin(), p.end());
      }
    for(int j = 0; j < ny; ++j)
      for(int i = 0; i < nx; ++i) {
        const int a = j * (nx + 1) + i, b = a + 1, c = a + nx + 2, d = a + nx + 1;
        if((i + j) % 2 == 0)
          tri.insert(tri.end(), {a, b, c, a, c, d});
        else
          tri.insert(tri.end(), {a, b, d, b, c, d});
      }
    const int own = int(tri.size() / 3), offset = int(in.size() / 3);
    in.insert(in.end(), cutterXyz.begin(), cutterXyz.end());
    for(int v : cutterTriangles) tri.push_back(offset + v);
    std::vector<int> birth;
    if(!meshCoRefine(in, tri, xyz, triangles, birth, error)) return false;
    // the edges of T that a cutter also has
    std::unordered_set<std::uint64_t> cut;
    pieces.clear();
    for(std::size_t t = 0; t < triangles.size() / 3; ++t) {
      if(birth[t] < own)
        pieces.push_back(int(t));
      else
        for(int k = 0; k < 3; ++k)
          cut.insert(edgeKey(triangles[3 * t + k], triangles[3 * t + (k + 1) % 3]));
    }
    if(pieces.empty()) {
      error = "The plane of the branch was lost in the co-refinement";
      return false;
    }
    // fragments: triangles of T connected across the edges that are not cut
    std::vector<int> parent(pieces.size());
    std::iota(parent.begin(), parent.end(), 0);
    const auto find = [&](int i) {
      while(parent[i] != i) i = parent[i] = parent[parent[i]];
      return i;
    };
    std::unordered_map<std::uint64_t, int> first;
    for(std::size_t i = 0; i < pieces.size(); ++i)
      for(int k = 0; k < 3; ++k) {
        const std::uint64_t key =
          edgeKey(triangles[3 * pieces[i] + k], triangles[3 * pieces[i] + (k + 1) % 3]);
        if(cut.count(key)) continue;
        const auto inserted = first.emplace(key, int(i));
        if(!inserted.second) {
          const int a = find(inserted.first->second), b = find(int(i));
          if(a != b) parent[std::max(a, b)] = std::min(a, b);
        }
      }
    fragment.resize(pieces.size());
    for(std::size_t i = 0; i < pieces.size(); ++i) fragment[i] = find(int(i));
    uv.resize(xyz.size() / 3);
    for(std::size_t i = 0; i < uv.size(); ++i)
      uv[i] = frame.uv({xyz[3 * i], xyz[3 * i + 1], xyz[3 * i + 2]});
    return true;
  }
  const int *piece(std::size_t i) const { return &triangles[3 * std::size_t(pieces[i])]; }
  // (a piece without area holds no point: one whose three vertices became
  // the same would hold them all)
  int fragmentAt(const std::array<double, 2> &p) const
  {
    for(std::size_t i = 0; i < pieces.size(); ++i) {
      const int *t = piece(i);
      if(inside(p, uv[t[0]], uv[t[1]], uv[t[2]]) && area(i) > 0.) return fragment[i];
    }
    return -1;
  }
  double area(std::size_t i) const
  {
    const int *t = piece(i);
    return .5 * std::abs((uv[t[1]][0] - uv[t[0]][0]) * (uv[t[2]][1] - uv[t[0]][1]) -
                         (uv[t[1]][1] - uv[t[0]][1]) * (uv[t[2]][0] - uv[t[0]][0]));
  }
  // once its exact vertices are rounded a triangle can have no area left: it
  // still joins its neighbours, and is left out of the meshes
  bool flat(std::size_t i) const
  {
    const int *t = piece(i);
    if(t[0] == t[1] || t[1] == t[2] || t[0] == t[2]) return true;
    const Vec a = {xyz[3 * t[0]], xyz[3 * t[0] + 1], xyz[3 * t[0] + 2]},
              b = {xyz[3 * t[1]], xyz[3 * t[1] + 1], xyz[3 * t[1] + 2]},
              c = {xyz[3 * t[2]], xyz[3 * t[2] + 1], xyz[3 * t[2] + 2]};
    return !(norm(cross(sub(b, a), sub(c, a))) > 0.);
  }
  // the fragments that hold one of the points, with the number of points
  std::map<int, std::size_t> holding(const std::vector<std::array<double, 2> > &points) const
  {
    std::map<int, std::size_t> found;
    for(const auto &p : points) {
      const int f = fragmentAt(p);
      if(f >= 0) ++found[f];
    }
    return found;
  }
  bool onRectangle(std::size_t i) const
  {
    const double eps = 1.e-9 * std::max(hi[0] - lo[0], hi[1] - lo[1]);
    const int *t = piece(i);
    for(int k = 0; k < 3; ++k)
      for(int c = 0; c < 2; ++c)
        if(uv[t[k]][c] <= lo[c] + eps || uv[t[k]][c] >= hi[c] - eps) return true;
    return false;
  }
};

} // namespace

namespace {

// The triangles of the MAT that lie in a plane, to tell whether a point of
// the plane is on one of them.
class Footprint {
public:
  explicit Footprint(double cell) : _cell(cell) {}
  void add(const std::array<double, 2> &a, const std::array<double, 2> &b,
           const std::array<double, 2> &c)
  {
    const int index = int(_triangles.size());
    _triangles.push_back({a, b, c});
    std::int64_t lo[2], hi[2];
    for(int k = 0; k < 2; ++k) {
      lo[k] = std::int64_t(std::floor(std::min({a[k], b[k], c[k]}) / _cell));
      hi[k] = std::int64_t(std::floor(std::max({a[k], b[k], c[k]}) / _cell));
    }
    if((hi[0] - lo[0] + 1) * (hi[1] - lo[1] + 1) > 4096) {
      _large.push_back(index);
      return;
    }
    for(std::int64_t i = lo[0]; i <= hi[0]; ++i)
      for(std::int64_t j = lo[1]; j <= hi[1]; ++j) _cells[key(i, j)].push_back(index);
  }
  bool holds(const std::array<double, 2> &p) const
  {
    const auto on = [&](int index) {
      const auto &t = _triangles[index];
      return inside(p, t[0], t[1], t[2]);
    };
    const auto found = _cells.find(key(std::int64_t(std::floor(p[0] / _cell)),
                                       std::int64_t(std::floor(p[1] / _cell))));
    if(found != _cells.end() && std::any_of(found->second.begin(), found->second.end(), on))
      return true;
    return std::any_of(_large.begin(), _large.end(), on);
  }

private:
  static std::uint64_t key(std::int64_t i, std::int64_t j)
  {
    return (std::uint64_t(std::uint32_t(i)) << 32) | std::uint32_t(j);
  }
  double _cell;
  std::vector<std::array<std::array<double, 2>, 3> > _triangles;
  std::unordered_map<std::uint64_t, std::vector<int> > _cells;
  std::vector<int> _large;
};

// The section of the skin by the plane is made of closed lines. At a
// reentrant corner of one of them (two faces of the part with the void inside
// the turn: the end face of a rib and the face of the wall it stands on), the
// faces are prolonged into the material by fences, small strips across the
// plane, up to the mid-surface of the wall: the fragment of the plane around
// a branch then stops where the faces of the branch stop, instead of going on
// inside the wall along it.
//
// A face is a stretch of a line that keeps its direction within 5 degrees. A
// corner is where two faces that follow each other make 40 to 135 degrees:
// faces as short as the tolerance when they touch, faces of half the reach or
// more when a fillet of at most twice the reach of line is between them.
//
// Of the two faces of a corner, the one that bounds the branch is prolonged,
// not the one the branch stands on: a fence is made only if it meets the
// sheet of another branch within the reach (the mid-surface of the wall, one
// of the segments of crossings, in the plane), and if less than a tenth of it
// until there runs on a sheet of the MAT lying in the plane (onSheet). It is
// not made either if the sheet of another branch runs along it within half
// the reach, on the side of the other face of the corner: the branch ends on
// a wall there, and has to reach its mid-surface. It stops a little after the
// sheet it meets. Returns the number of fences.
std::size_t reentrantFences(const Mesh &skin, const Frame &frame, double reach, double tolerance,
                            const std::function<bool(const std::array<double, 2> &)> &onSheet,
                            const std::vector<std::array<double, 4> > &crossings,
                            std::size_t &corners, std::vector<double> &xyz,
                            std::vector<int> &triangles)
{
  corners = 0;
  if(!(reach > 0.) || crossings.empty()) return 0;
  const std::size_t count = skin.triangles.size() / 3;
  // nodes: the edges of the skin that cross the plane; each triangle that
  // crosses it joins two of them
  std::unordered_map<std::uint64_t, int> nodeOf;
  std::vector<Vec> position;
  std::vector<std::array<int, 2> > next;
  const auto side = [&](int v) { return frame.distance(point(skin, v)) >= 0.; };
  const auto node = [&](int a, int b) {
    const auto inserted = nodeOf.emplace(edgeKey(a, b), int(position.size()));
    if(inserted.second) {
      const Vec pa = point(skin, a), pb = point(skin, b);
      const double da = frame.distance(pa), db = frame.distance(pb);
      const double s = da == db ? .5 : da / (da - db);
      position.push_back(
        {pa[0] + s * (pb[0] - pa[0]), pa[1] + s * (pb[1] - pa[1]), pa[2] + s * (pb[2] - pa[2])});
      next.push_back({-1, -1});
    }
    return inserted.first->second;
  };
  for(std::size_t t = 0; t < count; ++t) {
    const int *v = &skin.triangles[3 * t];
    const bool s[3] = {side(v[0]), side(v[1]), side(v[2])};
    if(s[0] == s[1] && s[1] == s[2]) continue;
    int ends[2], found = 0;
    for(int k = 0; k < 3 && found < 2; ++k)
      if(s[k] != s[(k + 1) % 3]) ends[found++] = node(v[k], v[(k + 1) % 3]);
    if(found != 2) continue;
    for(int k = 0; k < 2; ++k) {
      std::array<int, 2> &slot = next[ends[k]];
      (slot[0] < 0 ? slot[0] : slot[1]) = ends[1 - k];
    }
  }
  if(position.empty()) return 0;

  // the closed lines, without the nodes that fall on the previous one
  std::vector<std::vector<Vec> > lines;
  {
    std::vector<unsigned char> seen(position.size(), 0);
    for(std::size_t start = 0; start < position.size(); ++start) {
      if(seen[start] || next[start][0] < 0 || next[start][1] < 0) continue;
      std::vector<Vec> line;
      int previous = -1, current = int(start);
      while(current >= 0 && !seen[current]) {
        seen[current] = 1;
        if(line.empty() || norm(sub(position[current], line.back())) > 1.e-9 * reach)
          line.push_back(position[current]);
        const int following = next[current][0] != previous ? next[current][0] : next[current][1];
        previous = current;
        current = following;
      }
      while(line.size() > 3 && norm(sub(line.front(), line.back())) <= 1.e-9 * reach)
        line.pop_back();
      if(line.size() >= 3) lines.push_back(std::move(line));
    }
  }
  // a point of the plane is in the material if a half-line from it crosses
  // the lines an odd number of times
  std::vector<std::vector<std::array<double, 2> > > outline(lines.size());
  for(std::size_t l = 0; l < lines.size(); ++l)
    for(const Vec &q : lines[l]) outline[l].push_back(frame.uv(q));
  const auto inMaterial = [&](const Vec &point3) {
    const std::array<double, 2> q = frame.uv(point3);
    bool in = false;
    for(const auto &loop : outline)
      for(std::size_t i = 0, j = loop.size() - 1; i < loop.size(); j = i++)
        if((loop[i][1] > q[1]) != (loop[j][1] > q[1]) &&
           q[0] < loop[i][0] + (q[1] - loop[i][1]) * (loop[j][0] - loop[i][0]) /
                                 (loop[j][1] - loop[i][1]))
          in = !in;
    return in;
  };
  const auto strip = [&](const Vec &a, const Vec &b) {
    const int first = int(xyz.size() / 3);
    for(const Vec *end : {&a, &b})
      for(int up = -1; up <= 1; up += 2)
        for(int k = 0; k < 3; ++k) xyz.push_back((*end)[k] + up * tolerance * frame.n[k]);
    triangles.insert(triangles.end(), {first, first + 1, first + 3, first, first + 3, first + 2});
  };
  // from a point of the void next to the corner to the face, then along the
  // face prolonged: the fence crosses the skin, it does not only touch it
  std::vector<std::array<double, 4> > made;
  // where the half-line from o along d first meets the sheet of another
  // branch
  const auto meeting = [&](const std::array<double, 2> &o, const std::array<double, 2> &d) {
    double meets = std::numeric_limits<double>::infinity();
    for(const std::array<double, 4> &c : crossings) {
      const double ex = c[2] - c[0], ey = c[3] - c[1];
      const double det = d[0] * ey - d[1] * ex;
      if(det == 0.) continue;
      const double ax = c[0] - o[0], ay = c[1] - o[1];
      const double s = (ax * ey - ay * ex) / det, r = (ax * d[1] - ay * d[0]) / det;
      if(r >= 0. && r <= 1. && s > 0. && s < meets) meets = s;
    }
    return meets;
  };
  const auto fence = [&](const Vec &inVoid, const Vec &from, const Vec &direction,
                         const Vec &otherFace) {
    const std::array<double, 2> o = frame.uv(from);
    const std::array<double, 2> d = {dot(direction, frame.u), dot(direction, frame.v)};
    const double meets = meeting(o, d);
    if(!(meets <= reach)) return;
    const int samples = 16;
    int count = 0;
    for(int i = 0; i < samples; ++i) {
      const double s = (i + .5) * meets / samples;
      if(onSheet({o[0] + s * d[0], o[1] + s * d[1]})) ++count;
    }
    if(10 * count > samples) return;
    // a sheet along it, on the side of the other face
    std::array<double, 2> side = {dot(otherFace, frame.u), dot(otherFace, frame.v)};
    const double along = side[0] * d[0] + side[1] * d[1];
    for(int k = 0; k < 2; ++k) side[k] -= along * d[k];
    const double sideLength = std::hypot(side[0], side[1]);
    if(sideLength > 0.) {
      for(double &c : side) c /= sideLength;
      const int probes = 8;
      int faced = 0;
      for(int i = 0; i < probes; ++i) {
        const double s = (i + .5) * meets / probes;
        if(meeting({o[0] + s * d[0], o[1] + s * d[1]}, side) <= .5 * reach) ++faced;
      }
      if(2 * faced >= probes) return;
    }
    for(const std::array<double, 4> &m : made)
      if(std::hypot(m[0] - o[0], m[1] - o[1]) <= 1.e-6 * reach &&
         m[2] * d[0] + m[3] * d[1] > 1. - 1.e-9)
        return;
    made.push_back({o[0], o[1], d[0], d[1]});
    const double length = std::min(reach, meets + tolerance);
    strip(inVoid, from);
    strip(from, {from[0] + length * direction[0], from[1] + length * direction[1],
                 from[2] + length * direction[2]});
  };

  const double degree = 3.14159265358979323846 / 180.;
  for(const std::vector<Vec> &line : lines) {
    const int n = int(line.size());
    if(n < 4) continue;
    const auto at = [&](int i) -> const Vec & { return line[((i % n) + n) % n]; };
    // segment i goes from node i to node i + 1; the line starts after its
    // sharpest turn, so that no face is split there
    std::vector<double> turn(n);
    int sharpest = 0;
    for(int i = 0; i < n; ++i) {
      const Vec in = sub(at(i), at(i - 1)), outward = sub(at(i + 1), at(i));
      turn[i] = std::atan2(dot(cross(in, outward), frame.n), dot(in, outward));
      if(std::abs(turn[i]) > std::abs(turn[sharpest])) sharpest = i;
    }
    // the stretches: segments first to last, of direction within 5 degrees
    // of the first one
    struct Stretch {
      int first, last;
      double angle, length;
    };
    std::vector<Stretch> stretches;
    {
      double angle = 0.;
      for(int i = sharpest; i < sharpest + n; ++i) {
        const double length = norm(sub(at(i + 1), at(i)));
        if(i > sharpest) angle += turn[((i % n) + n) % n];
        if(stretches.empty() || std::abs(angle - stretches.back().angle) > 5. * degree)
          stretches.push_back({i, i, angle, 0.});
        stretches.back().last = i;
        stretches.back().length += length;
      }
    }
    // the line of a face: the chord of its middle half (its ends may be the
    // ends of fillets)
    const auto lineOf = [&](const Stretch &x, Vec &origin, Vec &direction) {
      int a = x.last + 1, b = x.first;
      double run = 0.;
      for(int j = x.first; j <= x.last + 1; ++j) {
        if(j > x.first) run += norm(sub(at(j), at(j - 1)));
        if(run >= .25 * x.length && j < a) a = j;
        if(run <= .75 * x.length) b = j;
      }
      if(a >= b) {
        a = x.first;
        b = x.last + 1;
      }
      origin = at(a);
      direction = sub(at(b), at(a));
      const double length = norm(direction);
      if(!(length > 0.)) return false;
      for(double &c : direction) c /= length;
      return true;
    };
    const auto onLine = [](const Vec &q, const Vec &origin, const Vec &direction) {
      const double s = dot(sub(q, origin), direction);
      return Vec{origin[0] + s * direction[0], origin[1] + s * direction[1],
                 origin[2] + s * direction[2]};
    };
    // the corners between the faces of at least the length given that follow
    // each other with more than least and at most most of the line between
    const auto cornersBetween = [&](double length, double least, double most) {
      std::vector<int> faces;
      for(std::size_t i = 0; i < stretches.size(); ++i)
        if(stretches[i].length >= length) faces.push_back(int(i));
      if(faces.size() < 2) return;
      for(std::size_t i = 0; i < faces.size(); ++i) {
        const Stretch &a = stretches[faces[i]];
        const Stretch &b = stretches[faces[(i + 1) % faces.size()]];
        // from the end of a to the start of b (b is a turn of the line
        // further when it is the first face again)
        const int from = a.last + 1, to = i + 1 < faces.size() ? b.first : b.first + n;
        double between = 0.;
        for(int j = from; j < to; ++j) between += norm(sub(at(j + 1), at(j)));
        if(between > most || !(between > least)) continue;
        Vec originA, in, originB, outward;
        if(!lineOf(a, originA, in) || !lineOf(b, originB, outward)) continue;
        const double angle = std::atan2(norm(cross(in, outward)), dot(in, outward));
        if(angle < 40. * degree || angle > 135. * degree) continue;
        const Vec endA = onLine(at(from), originA, in), startB = onLine(at(to), originB, outward);
        // between a point just before the corner and one just after: in the
        // void if the corner is reentrant
        const double step = std::min(.1 * reach, .5 * std::min(a.length, b.length));
        Vec middle;
        for(int k = 0; k < 3; ++k)
          middle[k] = .5 * ((endA[k] - step * in[k]) + (startB[k] + step * outward[k]));
        if(inMaterial(middle)) continue;
        ++corners;
        Vec toVoid = sub(outward, in);
        const double scale = .2 * step / norm(toVoid);
        for(double &c : toVoid) c *= scale;
        fence({at(from)[0] + toVoid[0], at(from)[1] + toVoid[1], at(from)[2] + toVoid[2]}, endA,
              in, outward);
        fence({at(to)[0] + toVoid[0], at(to)[1] + toVoid[1], at(to)[2] + toVoid[2]}, startB,
              {-outward[0], -outward[1], -outward[2]}, {-in[0], -in[1], -in[2]});
      }
    };
    cornersBetween(tolerance, -1., tolerance);
    cornersBetween(.5 * reach, tolerance, 2. * reach);
  }
  return made.size();
}

} // namespace

bool extendBranchInPlane(const Mesh &mesh, const Mesh &skin, const BranchPlane &plane,
                         double tolerance, double size, double reach, PlaneExtension &out,
                         std::string &error)
{
  const auto start = std::chrono::steady_clock::now();
  out = PlaneExtension{};
  error.clear();
  if(!(tolerance > 0.) || !std::isfinite(tolerance) || !(size >= 0.) || !std::isfinite(size)) {
    error = "The flatness tolerance must be positive and the size nonnegative";
    return false;
  }
  const double normalLength =
    std::sqrt(plane.normal[0] * plane.normal[0] + plane.normal[1] * plane.normal[1] +
              plane.normal[2] * plane.normal[2]);
  if(!(normalLength > 0.) || skin.triangles.empty() || mesh.triangles.empty()) {
    error = "A plane, a skin and a MAT are needed";
    return false;
  }
  const Frame frame(plane);
  const std::size_t count = mesh.triangles.size() / 3;

  // The triangles of the skin and of the other branches that reach the plane,
  // without those that lie in it (another sheet of the same wall).
  const double parallel = std::cos(15. * 3.14159265358979323846 / 180.);
  std::vector<double> cutterXyz;
  std::vector<int> cutterTriangles;
  const auto cutters = [&](const Mesh &m, bool otherBranchesOnly) {
    std::vector<int> index(m.xyz.size() / 3, -1);
    for(std::size_t t = 0; t < m.triangles.size() / 3; ++t) {
      if(otherBranchesOnly && t < m.branch.size() && m.branch[t] == plane.branch) continue;
      double least = std::numeric_limits<double>::infinity(), most = -least;
      for(int k = 0; k < 3; ++k) {
        const double d = frame.distance(point(m, m.triangles[3 * t + k]));
        least = std::min(least, d);
        most = std::max(most, d);
      }
      if(least > 0. || most < 0.) continue;
      Vec centroid, normal;
      const double area = triangle(m, t, centroid, &normal);
      if(!(area > 0.)) continue;
      if(std::max(-least, most) <= tolerance && std::abs(dot(normal, frame.n)) >= parallel * 2. * area)
        continue;
      for(int k = 0; k < 3; ++k) {
        const int vertex = m.triangles[3 * t + k];
        if(index[vertex] < 0) {
          index[vertex] = int(cutterXyz.size() / 3);
          const Vec p = point(m, vertex);
          cutterXyz.insert(cutterXyz.end(), p.begin(), p.end());
        }
        cutterTriangles.push_back(index[vertex]);
      }
      ++out.cutters;
    }
  };
  cutters(skin, false);
  cutters(mesh, true);

  // The triangles of the branch that are in the plane (not its cusp next to a
  // junction): the fragments that hold one of them are kept.
  std::vector<std::array<double, 2> > seeds;
  {
    std::vector<std::size_t> own;
    for(std::size_t t = 0; t < count; ++t) {
      if(t >= mesh.branch.size() || mesh.branch[t] != plane.branch) continue;
      Vec centroid;
      if(triangle(mesh, t, centroid) > 0. && std::abs(frame.distance(centroid)) <= tolerance)
        own.push_back(t);
    }
    if(own.empty()) {
      error = "No triangle of the branch is within the tolerance of its plane";
      return false;
    }
    const std::size_t step = std::max<std::size_t>(1, own.size() / 400);
    for(std::size_t i = step / 2; i < own.size(); i += step) {
      Vec centroid;
      triangle(mesh, own[i], centroid);
      seeds.push_back(frame.uv(centroid));
    }
  }

  // First with two triangles around the whole skin.
  double lo[2] = {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()};
  double hi[2] = {-lo[0], -lo[1]};
  for(std::size_t i = 0; i < skin.xyz.size() / 3; ++i) {
    const auto p = frame.uv(point(skin, int(i)));
    for(int k = 0; k < 2; ++k) {
      lo[k] = std::min(lo[k], p[k]);
      hi[k] = std::max(hi[k], p[k]);
    }
  }
  const double margin = .05 * std::max(hi[0] - lo[0], hi[1] - lo[1]) + tolerance;
  for(int k = 0; k < 2; ++k) {
    lo[k] -= margin;
    hi[k] += margin;
  }
  // The branches lying in the plane inside a kept fragment are the same wall:
  // they go with the branch.
  struct Other {
    double area = 0., inPlane = 0.;
    std::vector<std::size_t> samples;
  };
  std::map<int, Other> others;
  for(std::size_t t = 0; t < count; ++t) {
    const int b = t < mesh.branch.size() ? mesh.branch[t] : 0;
    if(b == plane.branch) continue;
    Vec centroid, normal;
    const double area = triangle(mesh, t, centroid, &normal);
    Other &o = others[b];
    o.area += area;
    if(area > 0. && std::abs(frame.distance(centroid)) <= tolerance &&
       std::abs(dot(normal, frame.n)) >= parallel * 2. * area) {
      o.inPlane += area;
      o.samples.push_back(t);
    }
  }
  PlaneCut cut;
  std::map<int, std::size_t> kept;
  const auto firstPass = [&]() {
    out.merged.clear();
    out.reachesFrame = false;
    if(!cut.compute(frame, lo, hi, 1, 1, cutterXyz, cutterTriangles, error)) return false;
    kept = cut.holding(seeds);
    if(kept.empty()) {
      error = "No fragment of the plane holds a triangle of the branch";
      return false;
    }
    // The rectangle is far outside the skin: a kept fragment that touches it
    // is not closed by the skin.
    for(std::size_t i = 0; i < cut.pieces.size(); ++i)
      if(kept.count(cut.fragment[i]) && cut.onRectangle(i)) out.reachesFrame = true;
    for(const auto &entry : others) {
      const Other &o = entry.second;
      if(!(o.area > 0.) || o.inPlane < .9 * o.area) continue;
      const std::size_t stride = std::max<std::size_t>(1, o.samples.size() / 16);
      for(std::size_t i = stride / 2; i < o.samples.size(); i += stride) {
        Vec centroid;
        triangle(mesh, o.samples[i], centroid);
        const int fragment = cut.fragmentAt(frame.uv(centroid));
        if(fragment >= 0 && kept.count(fragment)) {
          out.merged.push_back(entry.first);
          break;
        }
      }
    }
    return true;
  };
  if(!firstPass()) return false;

  // The fragment of a plane goes on inside the walls that the branch stands
  // on, along them. The faces of the part are prolonged at its reentrant
  // corners to stop it there, where they do not run on the branch or on a
  // branch that went with it; then the fragments are found again.
  if(reach > 0. && !out.reachesFrame) {
    const std::unordered_set<int> together(out.merged.begin(), out.merged.end());
    // the sheets of the branch and of those that went with it, in the plane
    // (found when a fence asks)
    Footprint sheets(.125 * reach);
    bool sheetsFound = false;
    const auto onSheet = [&](const std::array<double, 2> &q) {
      if(!sheetsFound) {
        sheetsFound = true;
        for(std::size_t t = 0; t < count; ++t) {
          const int b = t < mesh.branch.size() ? mesh.branch[t] : 0;
          if(b != plane.branch && !together.count(b)) continue;
          Vec centroid, normal;
          const double area = triangle(mesh, t, centroid, &normal);
          if(!(area > 0.) || std::abs(frame.distance(centroid)) > tolerance ||
             std::abs(dot(normal, frame.n)) < parallel * 2. * area)
            continue;
          sheets.add(frame.uv(point(mesh, mesh.triangles[3 * t])),
                     frame.uv(point(mesh, mesh.triangles[3 * t + 1])),
                     frame.uv(point(mesh, mesh.triangles[3 * t + 2])));
        }
      }
      return sheets.holds(q);
    };
    // where the sheets of the other branches cross the plane
    std::vector<std::array<double, 4> > crossings;
    for(std::size_t t = 0; t < count; ++t) {
      const int b = t < mesh.branch.size() ? mesh.branch[t] : 0;
      if(b == plane.branch || together.count(b)) continue;
      Vec corner[3];
      double d[3];
      for(int k = 0; k < 3; ++k) {
        corner[k] = point(mesh, mesh.triangles[3 * t + k]);
        d[k] = frame.distance(corner[k]);
      }
      std::array<double, 2> ends[2];
      int found = 0;
      for(int k = 0; k < 3 && found < 2; ++k) {
        const int l = (k + 1) % 3;
        if((d[k] >= 0.) == (d[l] >= 0.)) continue;
        const double w = d[k] / (d[k] - d[l]);
        ends[found++] = frame.uv({corner[k][0] + w * (corner[l][0] - corner[k][0]),
                                  corner[k][1] + w * (corner[l][1] - corner[k][1]),
                                  corner[k][2] + w * (corner[l][2] - corner[k][2])});
      }
      if(found == 2) crossings.push_back({ends[0][0], ends[0][1], ends[1][0], ends[1][1]});
    }
    const std::size_t before = cutterTriangles.size();
    out.fences = reentrantFences(skin, frame, reach, tolerance, onSheet, crossings, out.corners,
                                 cutterXyz, cutterTriangles);
    if(out.fences) {
      const PlaneCut without = cut;
      const std::map<int, std::size_t> keptWithout = kept;
      const std::vector<int> mergedWithout = out.merged;
      if(!firstPass()) {
        // (the fences are given up rather than the extension)
        cutterTriangles.resize(before);
        out.fences = 0;
        cut = without;
        kept = keptWithout;
        out.merged = mergedWithout;
        out.reachesFrame = false;
        error.clear();
      }
    }
  }

  // The fragments for display: 0 on the kept ones, then by decreasing area.
  {
    std::map<int, double> areaOf;
    for(std::size_t i = 0; i < cut.pieces.size(); ++i) areaOf[cut.fragment[i]] += cut.area(i);
    std::vector<std::pair<double, int> > ranked;
    for(const auto &entry : areaOf)
      if(!kept.count(entry.first)) ranked.push_back({-entry.second, entry.first});
    std::sort(ranked.begin(), ranked.end());
    std::map<int, int> number;
    for(const auto &entry : kept) {
      number.emplace(entry.first, 0);
      out.keptArea += areaOf[entry.first];
    }
    for(std::size_t i = 0; i < ranked.size(); ++i) number.emplace(ranked[i].second, int(i) + 1);
    out.fragments = areaOf.size();
    out.keptFragments = kept.size();
    std::vector<int> vertex(cut.xyz.size() / 3, -1);
    for(std::size_t i = 0; i < cut.pieces.size(); ++i) {
      if(cut.flat(i)) continue;
      for(int k = 0; k < 3; ++k) {
        const int v = cut.piece(i)[k];
        if(vertex[v] < 0) {
          vertex[v] = int(out.plane.xyz.size() / 3);
          out.plane.xyz.insert(out.plane.xyz.end(), cut.xyz.begin() + 3 * v, cut.xyz.begin() + 3 * v + 3);
        }
        out.plane.triangles.push_back(vertex[v]);
      }
      out.plane.branch.push_back(number[cut.fragment[i]]);
      out.plane.parent.push_back(-1);
    }
  }

  // Then, to mesh the kept fragments, with a grid of the size asked around
  // them only (coarser if it would have more than 400 cells a side).
  if(size > 0. && !out.reachesFrame) {
    double flo[2] = {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()};
    double fhi[2] = {-flo[0], -flo[1]};
    for(std::size_t i = 0; i < cut.pieces.size(); ++i) {
      if(!kept.count(cut.fragment[i])) continue;
      for(int k = 0; k < 3; ++k)
        for(int c = 0; c < 2; ++c) {
          flo[c] = std::min(flo[c], cut.uv[cut.piece(i)[k]][c]);
          fhi[c] = std::max(fhi[c], cut.uv[cut.piece(i)[k]][c]);
        }
    }
    const double spacing = std::max(size, std::max(fhi[0] - flo[0], fhi[1] - flo[1]) / 400.);
    int cells[2];
    for(int c = 0; c < 2; ++c) {
      flo[c] -= 1.5 * spacing;
      fhi[c] += 1.5 * spacing;
      cells[c] = std::max(1, int(std::ceil((fhi[c] - flo[c]) / spacing)));
    }
    PlaneCut fine;
    if(!fine.compute(frame, flo, fhi, cells[0], cells[1], cutterXyz, cutterTriangles, error))
      return false;
    const std::map<int, std::size_t> again = fine.holding(seeds);
    bool closed = !again.empty();
    for(std::size_t i = 0; i < fine.pieces.size() && closed; ++i)
      if(again.count(fine.fragment[i]) && fine.onRectangle(i)) closed = false;
    if(closed) {
      cut = std::move(fine);
      kept = again;
      out.gridSize = spacing;
    }
  }

  // The MAT with the branch replaced.
  std::unordered_set<int> removed(out.merged.begin(), out.merged.end());
  removed.insert(plane.branch);
  // The fragment of a plane goes on inside the walls that the branch stands
  // on, along them: only what is within reach of the branch (and of the
  // branches that go with it) is kept.
  std::unordered_set<std::uint64_t> near;
  const auto cellOf = [&](const std::array<double, 2> &p, int di, int dj) {
    const std::int64_t i = std::int64_t(std::floor(p[0] / reach)) + di,
                       j = std::int64_t(std::floor(p[1] / reach)) + dj;
    return (std::uint64_t(std::uint32_t(i)) << 32) | std::uint32_t(j);
  };
  if(reach > 0.)
    for(std::size_t t = 0; t < count; ++t) {
      if(!removed.count(t < mesh.branch.size() ? mesh.branch[t] : 0)) continue;
      Vec centroid;
      triangle(mesh, t, centroid);
      const auto p = frame.uv(centroid);
      for(int di = -1; di <= 1; ++di)
        for(int dj = -1; dj <= 1; ++dj) near.insert(cellOf(p, di, dj));
    }
  const auto within = [&](std::size_t i) {
    if(!(reach > 0.)) return true;
    const int *t = cut.piece(i);
    const std::array<double, 2> c = {(cut.uv[t[0]][0] + cut.uv[t[1]][0] + cut.uv[t[2]][0]) / 3.,
                                     (cut.uv[t[0]][1] + cut.uv[t[1]][1] + cut.uv[t[2]][1]) / 3.};
    return near.count(cellOf(c, 0, 0)) != 0;
  };
  // (the vertices keep their numbers: those of the branch stay, unused)
  out.result.xyz = mesh.xyz;
  for(std::size_t t = 0; t < count; ++t) {
    const int b = t < mesh.branch.size() ? mesh.branch[t] : 0;
    if(removed.count(b)) continue;
    for(int k = 0; k < 3; ++k) out.result.triangles.push_back(mesh.triangles[3 * t + k]);
    out.result.branch.push_back(b);
    out.result.parent.push_back(t < mesh.parent.size() ? mesh.parent[t] : -1);
  }
  std::vector<int> keptVertex(cut.xyz.size() / 3, -1);
  for(std::size_t i = 0; i < cut.pieces.size(); ++i) {
    if(!kept.count(cut.fragment[i]) || cut.flat(i) || !within(i)) continue;
    for(int k = 0; k < 3; ++k) {
      const int v = cut.piece(i)[k];
      if(keptVertex[v] < 0) {
        keptVertex[v] = int(out.result.xyz.size() / 3);
        out.result.xyz.insert(out.result.xyz.end(), cut.xyz.begin() + 3 * v, cut.xyz.begin() + 3 * v + 3);
      }
      out.result.triangles.push_back(keptVertex[v]);
    }
    out.result.branch.push_back(plane.branch);
    out.result.parent.push_back(-1);
    ++out.addedTriangles;
    out.addedArea += cut.area(i);
  }
  out.seconds = std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
  return true;
}

// ---------------------------------------------------------------------------
// Ribbon along the free boundary of a branch.

namespace {

// the edges of the mesh with the number of triangles on each
std::unordered_map<std::uint64_t, int> edgeCounts(const Mesh &mesh)
{
  std::unordered_map<std::uint64_t, int> counts;
  counts.reserve(mesh.triangles.size());
  for(std::size_t t = 0; t < mesh.triangles.size() / 3; ++t)
    for(int k = 0; k < 3; ++k)
      ++counts[edgeKey(mesh.triangles[3 * t + k], mesh.triangles[3 * t + (k + 1) % 3])];
  return counts;
}

} // namespace

bool branchRibbon(const Mesh &mesh, int branch, double length, int layers, Ribbon &out,
                  std::string &error, const Mesh *original)
{
  out = Ribbon{};
  error.clear();
  if(!(length > 0.) || !std::isfinite(length) || layers < 1) {
    error = "The ribbon needs a positive length and at least one layer";
    return false;
  }
  std::vector<std::size_t> own;
  for(std::size_t t = 0; t < mesh.triangles.size() / 3; ++t)
    if((t < mesh.branch.size() ? mesh.branch[t] : 0) == branch) own.push_back(t);
  if(own.empty()) {
    error = "The branch has no triangle";
    return false;
  }
  // The triangles of the branch, oriented alike across the edges they share
  // two by two.
  std::vector<std::array<int, 3> > tri(own.size());
  for(std::size_t i = 0; i < own.size(); ++i)
    for(int k = 0; k < 3; ++k) tri[i][k] = mesh.triangles[3 * own[i] + k];
  std::unordered_map<std::uint64_t, std::vector<int> > around;
  for(std::size_t i = 0; i < tri.size(); ++i)
    for(int k = 0; k < 3; ++k) around[edgeKey(tri[i][k], tri[i][(k + 1) % 3])].push_back(int(i));
  {
    std::vector<unsigned char> seen(tri.size(), 0);
    std::vector<int> stack;
    for(std::size_t first = 0; first < tri.size(); ++first) {
      if(seen[first]) continue;
      seen[first] = 1;
      stack.push_back(int(first));
      while(!stack.empty()) {
        const int i = stack.back();
        stack.pop_back();
        for(int k = 0; k < 3; ++k) {
          const int a = tri[i][k], b = tri[i][(k + 1) % 3];
          const std::vector<int> &pair = around[edgeKey(a, b)];
          if(pair.size() != 2) continue;
          const int j = pair[0] == i ? pair[1] : pair[0];
          if(seen[j]) continue;
          // the neighbour must run along the shared edge the other way
          for(int m = 0; m < 3; ++m)
            if(tri[j][m] == a && tri[j][(m + 1) % 3] == b) std::swap(tri[j][0], tri[j][1]);
          seen[j] = 1;
          stack.push_back(j);
        }
      }
    }
  }
  // Normals at the vertices of the branch, smoothed over its edges.
  std::unordered_map<int, int> local;
  std::vector<int> global;
  const auto id = [&](int v) {
    const auto inserted = local.emplace(v, int(global.size()));
    if(inserted.second) global.push_back(v);
    return inserted.first->second;
  };
  for(auto &t : tri)
    for(int k = 0; k < 3; ++k) t[k] = id(t[k]);
  std::vector<Vec> x(global.size()), normal(global.size(), Vec{0., 0., 0.});
  for(std::size_t i = 0; i < global.size(); ++i) x[i] = point(mesh, global[i]);
  std::vector<std::vector<int> > neighbours(global.size());
  for(const auto &t : tri) {
    const Vec n = cross(sub(x[t[1]], x[t[0]]), sub(x[t[2]], x[t[0]]));
    for(int k = 0; k < 3; ++k) {
      for(int c = 0; c < 3; ++c) normal[t[k]][c] += n[c];
      neighbours[t[k]].push_back(t[(k + 1) % 3]);
      neighbours[t[k]].push_back(t[(k + 2) % 3]);
    }
  }
  const auto unit = [](Vec &a) {
    const double l = norm(a);
    if(l > 0.)
      for(double &c : a) c /= l;
  };
  for(Vec &n : normal) unit(n);
  for(int pass = 0; pass < 8; ++pass) {
    std::vector<Vec> next(normal);
    for(std::size_t i = 0; i < normal.size(); ++i) {
      for(int j : neighbours[i])
        for(int c = 0; c < 3; ++c) next[i][c] += normal[j][c];
      unit(next[i]);
    }
    normal.swap(next);
  }
  // The free boundary: the edges of the branch that no other triangle of the
  // whole mesh shares, as the oriented triangles run along them.
  const std::unordered_map<std::uint64_t, int> counts = edgeCounts(mesh);
  // an edge that was shared in the original MAT is a junction, even if the
  // branch on its other side has been replaced since
  std::unordered_map<std::uint64_t, int> before;
  const int originalVertices = original ? int(original->xyz.size() / 3) : 0;
  if(original) before = edgeCounts(*original);
  std::unordered_map<int, std::pair<int, int> > after; // start -> (end, third vertex)
  for(const auto &t : tri)
    for(int k = 0; k < 3; ++k) {
      const int a = t[k], b = t[(k + 1) % 3];
      const std::uint64_t key = edgeKey(global[a], global[b]);
      const std::size_t inBranch = around[key].size();
      if(inBranch != 1) continue;
      ++out.boundaryEdges;
      if(counts.at(key) != 1) continue;
      if(original && global[a] < originalVertices && global[b] < originalVertices) {
        const auto was = before.find(key);
        if(was != before.end() && was->second != 1) continue;
      }
      ++out.freeEdges;
      after[a] = {b, t[(k + 2) % 3]};
    }
  if(after.empty()) {
    error = "The branch has no free boundary";
    return false;
  }
  // Chains of free edges, each from a vertex that no free edge reaches (or
  // around a loop).
  std::unordered_set<int> reached;
  for(const auto &e : after) reached.insert(e.second.first);
  std::vector<std::vector<int> > chains;
  std::vector<unsigned char> closed;
  std::unordered_set<int> used;
  const auto follow = [&](int startVertex) {
    std::vector<int> chain = {startVertex};
    int v = startVertex;
    bool loop = false;
    while(true) {
      const auto e = after.find(v);
      if(e == after.end() || used.count(v)) break;
      used.insert(v);
      v = e->second.first;
      if(v == startVertex) {
        loop = true;
        break;
      }
      chain.push_back(v);
    }
    if(chain.size() >= 2) {
      chains.push_back(chain);
      closed.push_back(loop);
    }
  };
  for(const auto &e : after)
    if(!reached.count(e.first)) follow(e.first);
  for(const auto &e : after)
    if(!used.count(e.first)) follow(e.first);
  out.loops = chains.size();

  for(std::size_t c = 0; c < chains.size(); ++c) {
    const std::vector<int> &chain = chains[c];
    const int n = int(chain.size());
    const bool loop = closed[c];
    const auto at = [&](int i) {
      if(loop) return chain[((i % n) + n) % n];
      return chain[std::min(n - 1, std::max(0, i))];
    };
    // The boundary of a MAT zigzags at the scale of its polygons: tangents
    // and folds are measured over a span of several edges, about a quarter of
    // the length of the ribbon.
    double chainLength = 0.;
    for(int i = 1; i < n; ++i) chainLength += norm(sub(x[chain[i]], x[chain[i - 1]]));
    const int span = std::max(2, std::min(std::max(2, n / 4),
                                          int(std::lround(.25 * length * (n - 1) / std::max(chainLength, 1.e-300)))));
    // direction of the extension: tangent x normal, away from the branch
    std::vector<Vec> direction(n);
    double outward = 0.;
    for(int i = 0; i < n; ++i) {
      Vec tangent = sub(x[at(i + span)], x[at(i - span)]);
      unit(tangent);
      direction[i] = cross(tangent, normal[chain[i]]);
      unit(direction[i]);
      const auto e = after.find(chain[i]);
      if(e != after.end()) outward -= dot(direction[i], sub(x[e->second.second], x[chain[i]]));
    }
    if(outward < 0.)
      for(Vec &d : direction)
        for(double &k : d) k = -k;
    for(int pass = 0; pass < 4; ++pass) {
      std::vector<Vec> next(direction);
      for(int i = 0; i < n; ++i) {
        for(int o : {-1, 1}) {
          const int j = loop ? ((i + o) % n + n) % n : std::min(n - 1, std::max(0, i + o));
          for(int k = 0; k < 3; ++k) next[i][k] += direction[j][k];
        }
        unit(next[i]);
      }
      direction.swap(next);
    }
    // The map (u, v) -> x(u) + v d(u) folds where the directions turn towards
    // each other faster than the boundary advances: between two points of
    // the boundary a span apart, where the far chord x' + (v d)' no longer
    // runs like the near chord x' (in the plane, 1 - v k < 0 for normal
    // directions, k the curvature of the boundary). Where it folds the
    // directions are smoothed, over a neighbourhood that grows; where that is
    // not enough (around a hole smaller than the length, no direction field
    // avoids the fold) the ribbon is made shorter.
    std::vector<double> reach(n, length);
    {
      const int edges = loop ? n : std::max(0, n - span);
      const auto wrap = [&](int i) {
        return loop ? ((i % n) + n) % n : std::min(n - 1, std::max(0, i));
      };
      const auto folded = [&](int i) {
        const int j = wrap(i + span);
        const Vec near = sub(x[chain[j]], x[chain[i]]);
        Vec far = near;
        for(int k = 0; k < 3; ++k) far[k] += reach[j] * direction[j][k] - reach[i] * direction[i][k];
        return dot(far, near) <= .25 * dot(near, near);
      };
      std::vector<unsigned char> turned(n, 0), shortened(n, 0);
      int passes = 0;
      for(int round = 0; round < 40; ++round) {
        std::vector<unsigned char> active(n, 0);
        bool any = false;
        for(int pass = 0; pass < 200; ++pass, ++passes) {
          any = false;
          for(int i = 0; i < edges; ++i)
            if(folded(i)) {
              for(int k = 0; k <= span; ++k) active[wrap(i + k)] = 1;
              any = true;
            }
          if(!any) break;
          std::vector<unsigned char> grown(active);
          for(int i = 0; i < n; ++i)
            if(active[i]) grown[wrap(i - 1)] = grown[wrap(i + 1)] = 1;
          active.swap(grown);
          std::vector<Vec> next(direction);
          for(int i = 0; i < n; ++i) {
            if(!active[i]) continue;
            turned[i] = 1;
            for(int o : {-1, 1})
              for(int k = 0; k < 3; ++k) next[i][k] += direction[wrap(i + o)][k];
            unit(next[i]);
          }
          direction.swap(next);
        }
        if(!any) break;
        // still folding after 200 passes: shorter there, smoothly
        std::vector<double> next(reach);
        for(int i = 0; i < edges; ++i)
          if(folded(i))
            for(int k = 0; k <= span; ++k) {
              next[wrap(i + k)] = std::min(next[wrap(i + k)], .8 * reach[wrap(i + k)]);
              shortened[wrap(i + k)] = 1;
            }
        reach.swap(next);
        for(int smooth = 0; smooth < span; ++smooth) {
          std::vector<double> lower(reach);
          for(int i = 0; i < n; ++i)
            lower[i] = std::min(reach[i], (reach[wrap(i - 1)] + reach[i] + reach[wrap(i + 1)]) / 3.);
          reach.swap(lower);
        }
      }
      out.smoothingPasses = std::max(out.smoothingPasses, passes);
      for(int i = 0; i < n; ++i) {
        out.smoothedVertices += turned[i];
        out.shortenedVertices += shortened[i];
      }
      for(int i = 0; i < edges; ++i) out.foldedEdges += folded(i);
    }
    // the ribbon: u along the boundary, v away from it
    const int first = int(out.mesh.xyz.size() / 3);
    double u = 0.;
    for(int i = 0; i < n; ++i) {
      if(i) u += norm(sub(x[chain[i]], x[chain[i - 1]]));
      for(int j = 0; j <= layers; ++j) {
        const double v = reach[i] * j / layers;
        for(int k = 0; k < 3; ++k) out.mesh.xyz.push_back(x[chain[i]][k] + v * direction[i][k]);
        out.u.push_back(u);
        out.v.push_back(v);
        out.source.push_back(j == 0 ? global[chain[i]] : -1);
      }
    }
    out.boundaryLength += u;
    const int columns = loop ? n : n - 1;
    for(int i = 0; i < columns; ++i) {
      const int a = first + i * (layers + 1), b = first + ((i + 1) % n) * (layers + 1);
      for(int j = 0; j < layers; ++j) {
        out.mesh.triangles.insert(out.mesh.triangles.end(), {a + j, b + j, b + j + 1});
        out.mesh.triangles.insert(out.mesh.triangles.end(), {a + j, b + j + 1, a + j + 1});
        for(int k = 0; k < 2; ++k) {
          out.mesh.branch.push_back(int(c));
          out.mesh.parent.push_back(-1);
        }
      }
    }
  }
  return true;
}

bool extendBranchByRibbon(const Mesh &mesh, const Mesh &skin, int branch, const Ribbon &ribbon,
                          PlaneExtension &out, std::string &error)
{
  const auto start = std::chrono::steady_clock::now();
  out = PlaneExtension{};
  error.clear();
  const std::size_t own = ribbon.mesh.triangles.size() / 3;
  if(!own) {
    error = "The ribbon is empty";
    return false;
  }
  // Boxes of the triangles of the ribbon, in a grid: only the triangles of the
  // skin and of the other branches near one of them can cut it.
  double lo[3] = {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
                  std::numeric_limits<double>::infinity()};
  double hi[3] = {-lo[0], -lo[1], -lo[2]};
  for(std::size_t i = 0; i < ribbon.mesh.xyz.size(); ++i) {
    lo[i % 3] = std::min(lo[i % 3], ribbon.mesh.xyz[i]);
    hi[i % 3] = std::max(hi[i % 3], ribbon.mesh.xyz[i]);
  }
  double cell = 0.;
  for(int k = 0; k < 3; ++k) cell = std::max(cell, hi[k] - lo[k]);
  cell = std::max(cell / 64., 1.e-12);
  const auto cellOf = [&](double value, int k) { return int(std::floor((value - lo[k]) / cell)); };
  const auto boxOf = [](const Mesh &m, std::size_t t, double bl[3], double bh[3]) {
    for(int k = 0; k < 3; ++k) {
      bl[k] = std::numeric_limits<double>::infinity();
      bh[k] = -bl[k];
    }
    for(int c = 0; c < 3; ++c)
      for(int k = 0; k < 3; ++k) {
        const double value = m.xyz[3 * std::size_t(m.triangles[3 * t + c]) + k];
        bl[k] = std::min(bl[k], value);
        bh[k] = std::max(bh[k], value);
      }
  };
  std::unordered_set<std::uint64_t> occupied;
  const auto cellKey = [](int i, int j, int k) {
    return (std::uint64_t(std::uint32_t(i) & 0x1fffff) << 42) |
           (std::uint64_t(std::uint32_t(j) & 0x1fffff) << 21) | (std::uint32_t(k) & 0x1fffff);
  };
  for(std::size_t t = 0; t < own; ++t) {
    double bl[3], bh[3];
    boxOf(ribbon.mesh, t, bl, bh);
    for(int i = cellOf(bl[0], 0); i <= cellOf(bh[0], 0); ++i)
      for(int j = cellOf(bl[1], 1); j <= cellOf(bh[1], 1); ++j)
        for(int k = cellOf(bl[2], 2); k <= cellOf(bh[2], 2); ++k) occupied.insert(cellKey(i, j, k));
  }
  std::vector<double> xyz = ribbon.mesh.xyz;
  std::vector<int> triangles = ribbon.mesh.triangles;
  const auto cutters = [&](const Mesh &m, bool otherBranchesOnly) {
    std::vector<int> index(m.xyz.size() / 3, -1);
    for(std::size_t t = 0; t < m.triangles.size() / 3; ++t) {
      if(otherBranchesOnly && (t < m.branch.size() ? m.branch[t] : 0) == branch) continue;
      double bl[3], bh[3];
      boxOf(m, t, bl, bh);
      bool near = true;
      for(int k = 0; k < 3; ++k) near = near && bh[k] >= lo[k] && bl[k] <= hi[k];
      if(!near) continue;
      near = false;
      for(int i = cellOf(bl[0], 0); i <= cellOf(bh[0], 0) && !near; ++i)
        for(int j = cellOf(bl[1], 1); j <= cellOf(bh[1], 1) && !near; ++j)
          for(int k = cellOf(bl[2], 2); k <= cellOf(bh[2], 2) && !near; ++k)
            near = occupied.count(cellKey(i, j, k)) != 0;
      if(!near) continue;
      for(int c = 0; c < 3; ++c) {
        const int vertex = m.triangles[3 * t + c];
        if(index[vertex] < 0) {
          index[vertex] = int(xyz.size() / 3);
          xyz.insert(xyz.end(), m.xyz.begin() + 3 * std::size_t(vertex), m.xyz.begin() + 3 * std::size_t(vertex) + 3);
        }
        triangles.push_back(index[vertex]);
      }
      ++out.cutters;
    }
  };
  cutters(skin, false);
  const std::size_t skinCutters = out.cutters;
  cutters(mesh, true);

  // A row of the ribbon that does not end on the skin may go on inside a wall
  // that the branch stands on, along it. The face of the skin that stops the
  // nearest row that does end on the skin (within the length of the row along
  // the boundary) is prolonged into the wall: the row stops where it crosses
  // the plane of that face, unless it ends before on the sheet of another
  // branch, or shortly after on one that faces it (a wall the branch ends on:
  // the row has to reach its mid-surface).
  std::vector<int> rowStart;
  for(std::size_t i = 0; i < ribbon.source.size(); ++i)
    if(ribbon.source[i] >= 0) rowStart.push_back(int(i));
  const int rows = int(rowStart.size());
  rowStart.push_back(int(ribbon.source.size()));
  std::vector<unsigned char> shortened(rows, 0);
  {
    const auto at = [&](int vertex) {
      return Vec{xyz[3 * std::size_t(vertex)], xyz[3 * std::size_t(vertex) + 1],
                 xyz[3 * std::size_t(vertex) + 2]};
    };
    // the cutters by cell
    std::unordered_map<std::uint64_t, std::vector<int> > byCell;
    std::vector<int> large;
    for(std::size_t t = own; t < triangles.size() / 3; ++t) {
      int cl[3], ch[3];
      for(int k = 0; k < 3; ++k) {
        double least = std::numeric_limits<double>::infinity(), most = -least;
        for(int c = 0; c < 3; ++c) {
          least = std::min(least, xyz[3 * std::size_t(triangles[3 * t + c]) + k]);
          most = std::max(most, xyz[3 * std::size_t(triangles[3 * t + c]) + k]);
        }
        cl[k] = cellOf(least, k);
        ch[k] = cellOf(most, k);
      }
      if(double(ch[0] - cl[0] + 1) * (ch[1] - cl[1] + 1) * (ch[2] - cl[2] + 1) > 512.) {
        large.push_back(int(t));
        continue;
      }
      for(int i = cl[0]; i <= ch[0]; ++i)
        for(int j = cl[1]; j <= ch[1]; ++j)
          for(int k = cl[2]; k <= ch[2]; ++k) byCell[cellKey(i, j, k)].push_back(int(t));
    }
    const auto normalOf = [&](int t) {
      const Vec a = at(triangles[3 * std::size_t(t)]);
      return cross(sub(at(triangles[3 * std::size_t(t) + 1]), a),
                   sub(at(triangles[3 * std::size_t(t) + 2]), a));
    };
    // where each row first meets one (as a fraction of its length), and which
    std::vector<double> length(rows, 0.), meets(rows, std::numeric_limits<double>::infinity());
    std::vector<int> met(rows, -1);
    for(int r = 0; r < rows; ++r) {
      const Vec base = at(rowStart[r]), far = at(rowStart[r + 1] - 1);
      const Vec d = sub(far, base);
      length[r] = norm(d);
      if(!(length[r] > 0.)) continue;
      const auto test = [&](int t) {
        const Vec a = at(triangles[3 * std::size_t(t)]),
                  e1 = sub(at(triangles[3 * std::size_t(t) + 1]), a),
                  e2 = sub(at(triangles[3 * std::size_t(t) + 2]), a);
        const Vec h = cross(d, e2);
        const double det = dot(e1, h);
        if(det == 0.) return;
        const Vec w = sub(base, a);
        const double u = dot(w, h) / det;
        if(u < 0. || u > 1.) return;
        const Vec q = cross(w, e1);
        const double v = dot(d, q) / det;
        if(v < 0. || u + v > 1.) return;
        const double s = dot(e2, q) / det;
        if(s > 1.e-9 && s <= 1. && s < meets[r]) {
          meets[r] = s;
          met[r] = t;
        }
      };
      int cl[3], ch[3];
      for(int k = 0; k < 3; ++k) {
        cl[k] = cellOf(std::min(base[k], far[k]), k);
        ch[k] = cellOf(std::max(base[k], far[k]), k);
      }
      for(int i = cl[0]; i <= ch[0]; ++i)
        for(int j = cl[1]; j <= ch[1]; ++j)
          for(int k = cl[2]; k <= ch[2]; ++k) {
            const auto found = byCell.find(cellKey(i, j, k));
            if(found != byCell.end())
              for(int t : found->second) test(t);
          }
      for(int t : large) test(t);
    }
    // the nearest row that ends on the skin, along the boundary
    const int skinEnd = int(own + skinCutters);
    std::vector<int> rowOf(ribbon.source.size(), 0);
    for(int r = 0; r < rows; ++r)
      for(int i = rowStart[r]; i < rowStart[r + 1]; ++i) rowOf[i] = r;
    std::vector<std::vector<int> > beside(rows);
    for(std::size_t t = 0; t < own; ++t)
      for(int k = 0; k < 3; ++k) {
        const int a = rowOf[ribbon.mesh.triangles[3 * t + k]],
                  b = rowOf[ribbon.mesh.triangles[3 * t + (k + 1) % 3]];
        if(a == b) continue;
        if(std::find(beside[a].begin(), beside[a].end(), b) == beside[a].end()) beside[a].push_back(b);
        if(std::find(beside[b].begin(), beside[b].end(), a) == beside[b].end()) beside[b].push_back(a);
      }
    std::vector<double> away(rows, std::numeric_limits<double>::infinity());
    std::vector<int> nearest(rows, -1);
    std::vector<std::pair<double, int> > heap;
    for(int r = 0; r < rows; ++r)
      if(met[r] >= 0 && met[r] < skinEnd) {
        away[r] = 0.;
        nearest[r] = r;
        heap.push_back({0., r});
      }
    std::make_heap(heap.begin(), heap.end(), std::greater<std::pair<double, int> >());
    while(!heap.empty()) {
      std::pop_heap(heap.begin(), heap.end(), std::greater<std::pair<double, int> >());
      const std::pair<double, int> top = heap.back();
      heap.pop_back();
      if(top.first > away[top.second]) continue;
      for(int b : beside[top.second]) {
        const double there = top.first + norm(sub(at(rowStart[b]), at(rowStart[top.second])));
        if(there >= away[b]) continue;
        away[b] = there;
        nearest[b] = nearest[top.second];
        heap.push_back({there, b});
        std::push_heap(heap.begin(), heap.end(), std::greater<std::pair<double, int> >());
      }
    }
    // where each row ends, as a length: on the skin, where it is stopped, or
    // at its far end
    const double facing = std::cos(30. * 3.14159265358979323846 / 180.);
    std::vector<double> end(rows);
    std::vector<unsigned char> stopped(rows, 0);
    for(int r = 0; r < rows; ++r) {
      const bool onSkin = met[r] >= 0 && met[r] < skinEnd;
      end[r] = onSkin ? meets[r] * length[r] : length[r];
      if(onSkin || !(length[r] > 0.) || nearest[r] < 0 || away[r] > length[r]) continue;
      const int k = nearest[r];
      const Vec base = at(rowStart[r]), d = sub(at(rowStart[r + 1] - 1), base);
      const Vec baseK = at(rowStart[k]), dK = sub(at(rowStart[k + 1] - 1), baseK);
      const Vec on = {baseK[0] + meets[k] * dK[0], baseK[1] + meets[k] * dK[1],
                      baseK[2] + meets[k] * dK[2]};
      const Vec n = normalOf(met[k]);
      const double across = dot(d, n);
      if(across == 0.) continue;
      const double s = dot(sub(on, base), n) / across;
      if(!(s > 1.e-9) || s >= 1.) continue;
      // (a row that starts on the sheet of another branch, at the end of a
      // junction, is not stopped by it: it runs along it)
      const bool touches = met[r] >= 0 && meets[r] < .02;
      if(!touches && met[r] >= 0) {
        if(s >= meets[r]) continue;
        if(meets[r] - s <= .5) {
          const Vec m = normalOf(met[r]);
          if(std::abs(dot(m, n)) >= facing * norm(m) * norm(n)) continue;
        }
      }
      end[r] = s * length[r];
      stopped[r] = 1;
      ++out.stoppedRows;
    }
    // A row that ends on the skin is cut a little after the farthest of its
    // end and of the ends of the rows beside it: what is beyond is outside
    // the part, or back in it further on (in the wall the branch stands on).
    for(int r = 0; r < rows; ++r) {
      double to = length[r];
      if(stopped[r])
        to = end[r];
      else if(met[r] >= 0 && met[r] < skinEnd) {
        double most = end[r];
        for(int b : beside[r]) most = std::max(most, end[b]);
        to = std::min(length[r], most + .01 * length[r]);
      }
      if(!(to < length[r])) continue;
      const Vec base = at(rowStart[r]);
      const double scale = to / length[r];
      for(int i = rowStart[r] + 1; i < rowStart[r + 1]; ++i)
        for(int c = 0; c < 3; ++c)
          xyz[3 * std::size_t(i) + c] = base[c] + scale * (xyz[3 * std::size_t(i) + c] - base[c]);
      shortened[r] = 1;
    }
  }

  std::vector<double> oxyz;
  std::vector<int> otri, birth, inputVertex;
  if(!meshCoRefine(xyz, triangles, oxyz, otri, birth, error, &inputVertex)) return false;
  // The pieces of the ribbon; an edge is cut if a cutter has it, or more than
  // two pieces (the ribbon crossing itself).
  std::vector<int> pieces;
  std::unordered_set<std::uint64_t> cut;
  std::unordered_map<std::uint64_t, int> shared;
  for(std::size_t t = 0; t < otri.size() / 3; ++t) {
    const bool piece = std::size_t(birth[t]) < own;
    if(piece) pieces.push_back(int(t));
    for(int k = 0; k < 3; ++k) {
      const std::uint64_t key = edgeKey(otri[3 * t + k], otri[3 * t + (k + 1) % 3]);
      if(piece)
        ++shared[key];
      else
        cut.insert(key);
    }
  }
  std::vector<int> parent(pieces.size());
  std::iota(parent.begin(), parent.end(), 0);
  const auto find = [&](int i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  {
    std::unordered_map<std::uint64_t, int> first;
    for(std::size_t i = 0; i < pieces.size(); ++i)
      for(int k = 0; k < 3; ++k) {
        const std::uint64_t key =
          edgeKey(otri[3 * pieces[i] + k], otri[3 * pieces[i] + (k + 1) % 3]);
        if(cut.count(key) || shared[key] != 2) continue;
        const auto inserted = first.emplace(key, int(i));
        if(!inserted.second) {
          const int a = find(inserted.first->second), b = find(int(i));
          if(a != b) parent[std::max(a, b)] = std::min(a, b);
        }
      }
  }
  // Kept: the fragments with an edge on the boundary of the branch. A kept
  // fragment that holds the far end of the ribbon met nothing (the rows cut
  // above apart).
  std::unordered_set<int> onBoundary, farEnd;
  for(int r = 0; r < rows; ++r) {
    onBoundary.insert(inputVertex[rowStart[r]]);
    if(!shortened[r]) farEnd.insert(inputVertex[rowStart[r + 1] - 1]);
  }
  std::unordered_set<int> kept;
  for(std::size_t i = 0; i < pieces.size(); ++i) {
    int on = 0;
    for(int k = 0; k < 3; ++k) on += onBoundary.count(otri[3 * pieces[i] + k]) != 0;
    if(on >= 2) kept.insert(find(int(i)));
  }
  if(kept.empty()) {
    error = "No fragment of the ribbon is attached to the branch";
    return false;
  }
  std::unordered_set<int> all;
  for(std::size_t i = 0; i < pieces.size(); ++i) all.insert(find(int(i)));
  out.fragments = all.size();
  out.keptFragments = kept.size();

  const auto flat = [&](const int *t) {
    if(t[0] == t[1] || t[1] == t[2] || t[0] == t[2]) return true;
    const Vec a = {oxyz[3 * t[0]], oxyz[3 * t[0] + 1], oxyz[3 * t[0] + 2]},
              b = {oxyz[3 * t[1]], oxyz[3 * t[1] + 1], oxyz[3 * t[1] + 2]},
              c = {oxyz[3 * t[2]], oxyz[3 * t[2] + 1], oxyz[3 * t[2] + 2]};
    return !(norm(cross(sub(b, a), sub(c, a))) > 0.);
  };
  // for display: 0 on what is kept, 1 on the rest
  std::vector<int> vertex(oxyz.size() / 3, -1);
  out.result = mesh;
  // the vertices of the ribbon on the boundary are those of the branch
  std::vector<int> added(oxyz.size() / 3, -1);
  for(std::size_t i = 0; i < ribbon.source.size(); ++i)
    if(ribbon.source[i] >= 0) added[inputVertex[i]] = ribbon.source[i];
  for(std::size_t i = 0; i < pieces.size(); ++i) {
    const int *t = &otri[3 * pieces[i]];
    if(flat(t)) continue;
    const bool keep = kept.count(find(int(i))) != 0;
    for(int k = 0; k < 3; ++k) {
      if(vertex[t[k]] < 0) {
        vertex[t[k]] = int(out.plane.xyz.size() / 3);
        out.plane.xyz.insert(out.plane.xyz.end(), oxyz.begin() + 3 * t[k], oxyz.begin() + 3 * t[k] + 3);
      }
      out.plane.triangles.push_back(vertex[t[k]]);
    }
    out.plane.branch.push_back(keep ? 0 : 1);
    out.plane.parent.push_back(-1);
    if(!keep) continue;
    for(int k = 0; k < 3; ++k) {
      if(farEnd.count(t[k])) out.reachesFrame = true;
      if(added[t[k]] < 0) {
        added[t[k]] = int(out.result.xyz.size() / 3);
        out.result.xyz.insert(out.result.xyz.end(), oxyz.begin() + 3 * t[k], oxyz.begin() + 3 * t[k] + 3);
      }
      out.result.triangles.push_back(added[t[k]]);
    }
    out.result.branch.push_back(branch);
    out.result.parent.push_back(-1);
    ++out.addedTriangles;
    const Vec a = {oxyz[3 * t[0]], oxyz[3 * t[0] + 1], oxyz[3 * t[0] + 2]},
              b = {oxyz[3 * t[1]], oxyz[3 * t[1] + 1], oxyz[3 * t[1] + 2]},
              c = {oxyz[3 * t[2]], oxyz[3 * t[2] + 1], oxyz[3 * t[2] + 2]};
    out.keptArea += .5 * norm(cross(sub(b, a), sub(c, a)));
  }
  out.seconds = std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
  return true;
}

// ---------------------------------------------------------------------------
// The mid-surface as a mesh with its branches and its classified edges.

bool writeClassifiedMesh(const Mesh &mesh, const Mesh &skin, const std::string &filename,
                         ClassifiedEdges &counts, std::string &error)
{
  counts = ClassifiedEdges{};
  error.clear();
  const std::size_t count = mesh.triangles.size() / 3;
  if(!count) {
    error = "No triangle to write";
    return false;
  }
  // The edges with the branches of their triangles.
  struct Edge {
    int a, b, triangles = 0, first = -1;
    bool several = false;
  };
  std::unordered_map<std::uint64_t, Edge> edges;
  edges.reserve(3 * count);
  for(std::size_t t = 0; t < count; ++t) {
    const int branch = t < mesh.branch.size() ? mesh.branch[t] : 0;
    for(int k = 0; k < 3; ++k) {
      const int a = mesh.triangles[3 * t + k], b = mesh.triangles[3 * t + (k + 1) % 3];
      if(a == b) continue;
      Edge &e = edges[edgeKey(a, b)];
      if(!e.triangles) {
        e.a = std::min(a, b);
        e.b = std::max(a, b);
        e.first = branch;
      }
      else if(e.first != branch)
        e.several = true;
      ++e.triangles;
    }
  }
  // An edge of one triangle is on the skin if a node of the skin is within one
  // and a half times the usual length of the edges of the skin from its middle.
  double usual = 0.;
  {
    std::vector<double> lengths;
    const std::size_t skinTriangles = skin.triangles.size() / 3;
    const std::size_t step = std::max<std::size_t>(1, skinTriangles / 20000);
    for(std::size_t t = 0; t < skinTriangles; t += step)
      lengths.push_back(norm(sub(point(skin, skin.triangles[3 * t]), point(skin, skin.triangles[3 * t + 1]))));
    if(!lengths.empty()) {
      std::nth_element(lengths.begin(), lengths.begin() + lengths.size() / 2, lengths.end());
      usual = lengths[lengths.size() / 2];
    }
  }
  const double cell = std::max(2. * usual, 1.e-300), close = 1.5 * usual;
  const auto cellKey = [&](const Vec &p, int di, int dj, int dk) {
    const std::int64_t i = std::int64_t(std::floor(p[0] / cell)) + di,
                       j = std::int64_t(std::floor(p[1] / cell)) + dj,
                       k = std::int64_t(std::floor(p[2] / cell)) + dk;
    return (std::uint64_t(i & 0x1fffff) << 42) | (std::uint64_t(j & 0x1fffff) << 21) |
           std::uint64_t(k & 0x1fffff);
  };
  std::unordered_map<std::uint64_t, std::vector<int> > grid;
  for(std::size_t v = 0; v < skin.xyz.size() / 3; ++v) grid[cellKey(point(skin, int(v)), 0, 0, 0)].push_back(int(v));
  const auto onSkin = [&](const Vec &p) {
    for(int di = -1; di <= 1; ++di)
      for(int dj = -1; dj <= 1; ++dj)
        for(int dk = -1; dk <= 1; ++dk) {
          const auto found = grid.find(cellKey(p, di, dj, dk));
          if(found == grid.end()) continue;
          for(int v : found->second)
            if(norm(sub(point(skin, v), p)) <= close) return true;
        }
    return false;
  };
  // An edge of one triangle lies along another branch if a triangle of
  // another branch is within half the usual length from its middle: an
  // extended branch stops on the sheets it meets without sharing their
  // vertices.
  const double along = .5 * usual;
  std::unordered_map<std::uint64_t, std::vector<int> > sheetGrid;
  std::vector<int> large;
  const auto cellsOf = [&](std::size_t t, std::int64_t lo[3], std::int64_t hi[3]) {
    for(int c = 0; c < 3; ++c) {
      double least = std::numeric_limits<double>::infinity(), most = -least;
      for(int k = 0; k < 3; ++k) {
        const double x = mesh.xyz[3 * std::size_t(mesh.triangles[3 * t + k]) + c];
        least = std::min(least, x);
        most = std::max(most, x);
      }
      lo[c] = std::int64_t(std::floor((least - along) / cell));
      hi[c] = std::int64_t(std::floor((most + along) / cell));
    }
  };
  const auto key3 = [](std::int64_t i, std::int64_t j, std::int64_t k) {
    return (std::uint64_t(i & 0x1fffff) << 42) | (std::uint64_t(j & 0x1fffff) << 21) |
           std::uint64_t(k & 0x1fffff);
  };
  bool sheetsFound = false;
  const auto alongAnother = [&](const Vec &p, int branch) {
    if(!sheetsFound) {
      sheetsFound = true;
      for(std::size_t t = 0; t < count; ++t) {
        std::int64_t lo[3], hi[3];
        cellsOf(t, lo, hi);
        if((hi[0] - lo[0] + 1) * (hi[1] - lo[1] + 1) * (hi[2] - lo[2] + 1) > 512) {
          large.push_back(int(t));
          continue;
        }
        for(std::int64_t i = lo[0]; i <= hi[0]; ++i)
          for(std::int64_t j = lo[1]; j <= hi[1]; ++j)
            for(std::int64_t k = lo[2]; k <= hi[2]; ++k) sheetGrid[key3(i, j, k)].push_back(int(t));
      }
    }
    const auto close = [&](int t) {
      if((std::size_t(t) < mesh.branch.size() ? mesh.branch[t] : 0) == branch) return false;
      const Vec a = point(mesh, mesh.triangles[3 * std::size_t(t)]),
                b = point(mesh, mesh.triangles[3 * std::size_t(t) + 1]),
                c = point(mesh, mesh.triangles[3 * std::size_t(t) + 2]);
      return norm(sub(p, closestOnTriangle(p, a, b, c))) <= along;
    };
    const auto found = sheetGrid.find(key3(std::int64_t(std::floor(p[0] / cell)),
                                           std::int64_t(std::floor(p[1] / cell)),
                                           std::int64_t(std::floor(p[2] / cell))));
    if(found != sheetGrid.end() && std::any_of(found->second.begin(), found->second.end(), close))
      return true;
    return std::any_of(large.begin(), large.end(), close);
  };
  // Lines: 1 on the skin, 2 a boundary inside the part, 3 a junction, 4 along
  // another branch; one curve per kind and per branch (the first one of a
  // junction).
  struct Line {
    int a, b, kind, branch;
  };
  std::vector<Line> lines;
  for(const auto &entry : edges) {
    const Edge &e = entry.second;
    int kind = 0;
    if(e.triangles >= 3 || (e.triangles == 2 && e.several))
      kind = 3;
    else if(e.triangles == 1) {
      const Vec a = point(mesh, e.a), b = point(mesh, e.b);
      const Vec middle = {.5 * (a[0] + b[0]), .5 * (a[1] + b[1]), .5 * (a[2] + b[2])};
      kind = alongAnother(middle, e.first) ? 4 : onSkin(middle) ? 1 : 2;
    }
    if(!kind) continue;
    lines.push_back({e.a, e.b, kind, e.first});
    ++(kind == 1 ? counts.onSkin : kind == 2 ? counts.inside : kind == 3 ? counts.junction : counts.along);
  }
  std::sort(lines.begin(), lines.end(), [](const Line &x, const Line &y) {
    if(x.kind != y.kind) return x.kind < y.kind;
    if(x.branch != y.branch) return x.branch < y.branch;
    if(x.a != y.a) return x.a < y.a;
    return x.b < y.b;
  });
  std::map<std::pair<int, int>, int> curve;
  for(const Line &l : lines) curve.emplace(std::make_pair(l.kind, l.branch), int(curve.size()) + 1);
  // Nodes in use, and the branches.
  std::vector<int> node(mesh.xyz.size() / 3, 0);
  int nodes = 0;
  std::map<int, std::size_t> branches;
  for(std::size_t t = 0; t < count; ++t) {
    ++branches[t < mesh.branch.size() ? mesh.branch[t] : 0];
    for(int k = 0; k < 3; ++k)
      if(!node[mesh.triangles[3 * t + k]]) node[mesh.triangles[3 * t + k]] = ++nodes;
  }
  counts.branches = branches.size();
  std::ofstream f(filename);
  if(!f) {
    error = "Cannot open " + filename;
    return false;
  }
  f << std::setprecision(17) << "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$PhysicalNames\n"
    << branches.size() + 4 << '\n'
    << "1 1 \"boundary on the skin\"\n1 2 \"boundary inside the part\"\n1 3 \"junction\"\n"
    << "1 4 \"boundary along another branch\"\n";
  for(const auto &b : branches) f << "2 " << b.first + 1 << " \"branch " << b.first << "\"\n";
  f << "$EndPhysicalNames\n$Nodes\n" << nodes << '\n';
  {
    std::vector<int> order(nodes, -1);
    for(std::size_t v = 0; v < node.size(); ++v)
      if(node[v]) order[node[v] - 1] = int(v);
    for(int i = 0; i < nodes; ++i)
      f << i + 1 << ' ' << mesh.xyz[3 * std::size_t(order[i])] << ' ' << mesh.xyz[3 * std::size_t(order[i]) + 1]
        << ' ' << mesh.xyz[3 * std::size_t(order[i]) + 2] << '\n';
  }
  f << "$EndNodes\n$Elements\n" << lines.size() + count << '\n';
  std::size_t element = 0;
  for(const Line &l : lines)
    f << ++element << " 1 2 " << l.kind << ' ' << curve[{l.kind, l.branch}] << ' ' << node[l.a] << ' '
      << node[l.b] << '\n';
  for(std::size_t t = 0; t < count; ++t) {
    const int branch = (t < mesh.branch.size() ? mesh.branch[t] : 0) + 1;
    f << ++element << " 2 2 " << branch << ' ' << branch << ' ' << node[mesh.triangles[3 * t]] << ' '
      << node[mesh.triangles[3 * t + 1]] << ' ' << node[mesh.triangles[3 * t + 2]] << '\n';
  }
  f << "$EndElements\n";
  if(!f) {
    error = "Failed to write " + filename;
    return false;
  }
  return true;
}

} // namespace matgmsh_native
