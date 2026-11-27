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
#include <set>
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
// The smallest value at which the weights of the values up to it reach the
// fraction of their total. By selection: the half that has it is kept until a
// few values are left, which are sorted (the values are reordered).
double quantile(std::vector<std::pair<double, double> > &valueWeight, double fraction)
{
  if(valueWeight.empty()) return 0.;
  double total = 0.;
  for(const auto &x : valueWeight) total += x.second;
  const double target = fraction * total;
  auto first = valueWeight.begin(), last = valueWeight.end();
  double before = 0.; // the weight of the values before first
  while(last - first > 32) {
    const auto middle = first + (last - first) / 2;
    std::nth_element(first, middle, last);
    double upTo = before;
    for(auto x = first; x <= middle; ++x) upTo += x->second;
    if(upTo >= target)
      last = middle + 1;
    else {
      before = upTo;
      first = middle + 1;
    }
  }
  std::sort(first, last);
  for(auto x = first; x != last; ++x) {
    before += x->second;
    if(before >= target) return x->first;
  }
  return (last - 1)->first;
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

// Where triangles cross a plane (those that skip leaves out): the points
// where their edges cross it, joined across the triangles. The lines of a
// second set of triangles can be added to those of a first one.
void planeTraces(const std::vector<double> &xyz, const std::vector<int> &triangles,
                 const Frame &frame, const std::function<bool(std::size_t)> &skip,
                 std::vector<std::array<double, 2> > &node,
                 std::vector<std::array<int, 2> > &segment)
{
  std::unordered_map<std::uint64_t, int> nodeOf;
  for(std::size_t t = 0; t < triangles.size() / 3; ++t) {
    if(skip(t)) continue;
    Vec corner[3];
    double d[3];
    for(int k = 0; k < 3; ++k) {
      const double *q = &xyz[3 * std::size_t(triangles[3 * t + k])];
      corner[k] = {q[0], q[1], q[2]};
      d[k] = frame.distance(corner[k]);
    }
    int ends[2], found = 0;
    for(int k = 0; k < 3 && found < 2; ++k) {
      const int l = (k + 1) % 3;
      if((d[k] >= 0.) == (d[l] >= 0.)) continue;
      const auto inserted =
        nodeOf.emplace(edgeKey(triangles[3 * t + k], triangles[3 * t + l]), int(node.size()));
      if(inserted.second) {
        const double w = d[k] / (d[k] - d[l]);
        node.push_back(frame.uv({corner[k][0] + w * (corner[l][0] - corner[k][0]),
                                 corner[k][1] + w * (corner[l][1] - corner[k][1]),
                                 corner[k][2] + w * (corner[l][2] - corner[k][2])}));
      }
      ends[found++] = inserted.first->second;
    }
    if(found == 2 && ends[0] != ends[1]) segment.push_back({ends[0], ends[1]});
  }
}

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
// of the lines below, in the plane), and if less than a tenth of it until
// there runs on a sheet of the MAT lying in the plane (onSheet). It is
// not made either if the sheet of another branch runs along it within half
// the reach, on the side of the other face of the corner: the branch ends on
// a wall there, and has to reach its mid-surface. It stops a little after the
// sheet it meets. Returns the number of fences.
//
// The sheets of the other branches are given by where they cross the plane:
// points (traceNode) joined by segments (traceSegment). Where such a line
// ends just short of another one or of the skin (the branch it ended on was
// replaced by its plane, which is not exactly where its sheet was), the
// fragment of the branch would go around its end, across that surface. The
// line is prolonged straight to the first sheet or face of the skin it meets
// within twice the tolerance, in the material and with less than a tenth of
// the way on a sheet lying in the plane: closures counts these. (Prolonged
// further, to anything within the reach, the lines of the sheets of a
// junction with fillets cut the plane under the junction from the branch.)
std::size_t reentrantFences(const Mesh &skin, const Frame &frame, double reach, double tolerance,
                            const std::function<bool(const std::array<double, 2> &)> &onSheet,
                            const std::vector<std::array<double, 2> > &traceNode,
                            const std::vector<std::array<int, 2> > &traceSegment,
                            std::size_t &corners, std::size_t &closures,
                            std::vector<double> &xyz, std::vector<int> &triangles,
                            bool prolongLines = true, bool atCorners = true)
{
  corners = closures = 0;
  if(!(reach > 0.) || traceSegment.empty()) return 0;
  std::vector<std::array<double, 4> > crossings(traceSegment.size());
  for(std::size_t i = 0; i < traceSegment.size(); ++i) {
    const std::array<double, 2> &a = traceNode[traceSegment[i][0]], &b = traceNode[traceSegment[i][1]];
    crossings[i] = {a[0], a[1], b[0], b[1]};
  }
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
  const auto inMaterialAt = [&](const std::array<double, 2> &q) {
    bool in = false;
    for(const auto &loop : outline)
      for(std::size_t i = 0, j = loop.size() - 1; i < loop.size(); j = i++)
        if((loop[i][1] > q[1]) != (loop[j][1] > q[1]) &&
           q[0] < loop[i][0] + (q[1] - loop[i][1]) * (loop[j][0] - loop[i][0]) /
                                 (loop[j][1] - loop[i][1]))
          in = !in;
    return in;
  };
  const auto inMaterial = [&](const Vec &point3) { return inMaterialAt(frame.uv(point3)); };
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
  const auto meetingSegment = [](const std::array<double, 2> &o, const std::array<double, 2> &d,
                                 const std::array<double, 2> &a, const std::array<double, 2> &b,
                                 double after, double &meets) {
    const double ex = b[0] - a[0], ey = b[1] - a[1];
    const double det = d[0] * ey - d[1] * ex;
    if(det == 0.) return;
    const double ax = a[0] - o[0], ay = a[1] - o[1];
    const double s = (ax * ey - ay * ex) / det, r = (ax * d[1] - ay * d[0]) / det;
    if(r >= 0. && r <= 1. && s > after && s < meets) meets = s;
  };
  const auto meeting = [&](const std::array<double, 2> &o, const std::array<double, 2> &d,
                           double after = 0.) {
    double meets = std::numeric_limits<double>::infinity();
    for(const std::array<double, 4> &c : crossings)
      meetingSegment(o, d, {c[0], c[1]}, {c[2], c[3]}, after, meets);
    return meets;
  };
  // (the same with the skin)
  const auto meetingSkin = [&](const std::array<double, 2> &o, const std::array<double, 2> &d,
                               double after) {
    double meets = std::numeric_limits<double>::infinity();
    for(const auto &loop : outline)
      for(std::size_t i = 0, j = loop.size() - 1; i < loop.size(); j = i++)
        meetingSegment(o, d, loop[j], loop[i], after, meets);
    return meets;
  };
  // whether more than a tenth of the way from o along d, over the length
  // given, runs on a sheet lying in the plane: with the sheet on its two
  // sides, the border of a sheet does not count
  const auto runsOnSheet = [&](const std::array<double, 2> &o, const std::array<double, 2> &d,
                               double length) {
    const int samples = 16;
    const double aside = .25 * tolerance;
    int count = 0;
    for(int i = 0; i < samples; ++i) {
      const double s = (i + .5) * length / samples;
      const std::array<double, 2> q = {o[0] + s * d[0], o[1] + s * d[1]};
      if(onSheet({q[0] - aside * d[1], q[1] + aside * d[0]}) &&
         onSheet({q[0] + aside * d[1], q[1] - aside * d[0]}))
        ++count;
    }
    return 10 * count > samples;
  };
  const auto fence = [&](const Vec &inVoid, const Vec &from, const Vec &direction,
                         const Vec &otherFace) {
    const std::array<double, 2> o = frame.uv(from);
    const std::array<double, 2> d = {dot(direction, frame.u), dot(direction, frame.v)};
    const double meets = meeting(o, d);
    if(!(meets <= reach)) return;
    if(runsOnSheet(o, d, meets)) return;
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
    const double length = std::min(reach, meets + 2. * tolerance);
    strip(inVoid, from);
    strip(from, {from[0] + length * direction[0], from[1] + length * direction[1],
                 from[2] + length * direction[2]});
  };

  const double degree = 3.14159265358979323846 / 180.;
  for(const std::vector<Vec> &line : lines) {
    const int n = int(line.size());
    if(n < 4 || !atCorners) continue;
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

  // The ends of the lines of the other sheets.
  if(prolongLines) {
    std::vector<std::vector<int> > beside(traceNode.size());
    for(const std::array<int, 2> &segment : traceSegment) {
      beside[segment[0]].push_back(segment[1]);
      beside[segment[1]].push_back(segment[0]);
    }
    const auto between = [&](int a, int b) {
      return std::hypot(traceNode[a][0] - traceNode[b][0], traceNode[a][1] - traceNode[b][1]);
    };
    for(std::size_t end = 0; end < traceNode.size(); ++end) {
      if(beside[end].size() != 1) continue;
      // its direction, over twice the tolerance of the line at least
      int previous = int(end), current = beside[end][0];
      double length = between(previous, current);
      while(length < 2. * tolerance && beside[current].size() == 2) {
        const int following = beside[current][0] != previous ? beside[current][0] : beside[current][1];
        length += between(current, following);
        previous = current;
        current = following;
      }
      if(length < 2. * tolerance) continue;
      const std::array<double, 2> o = traceNode[end];
      std::array<double, 2> d = {o[0] - traceNode[current][0], o[1] - traceNode[current][1]};
      const double dLength = std::hypot(d[0], d[1]);
      if(!(dLength > 0.)) continue;
      for(double &c : d) c /= dLength;
      const double after = 1.e-9 * reach;
      const double meets = std::min(meeting(o, d, after), meetingSkin(o, d, after));
      if(!(meets <= 2. * tolerance)) continue;
      if(!inMaterialAt({o[0] + .5 * meets * d[0], o[1] + .5 * meets * d[1]})) continue;
      if(runsOnSheet(o, d, meets)) continue;
      // a bar across the line a little before its end, and a stem across the
      // bar to a little after what is met: the line and the stem both cross
      // the bar (a stem that started on the bar could stop just short of it,
      // and leave a way around the end of the line)
      const double back = std::min(.5 * tolerance, .25 * length);
      const std::array<double, 2> middle = {o[0] - back * d[0], o[1] - back * d[1]};
      strip(frame.at(middle[0] + back * d[1], middle[1] - back * d[0]),
            frame.at(middle[0] - back * d[1], middle[1] + back * d[0]));
      const double to = meets + tolerance;
      strip(frame.at(middle[0] - .5 * back * d[0], middle[1] - .5 * back * d[1]),
            frame.at(o[0] + to * d[0], o[1] + to * d[1]));
      ++closures;
    }
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
    std::vector<std::array<double, 2> > traceNode;
    std::vector<std::array<int, 2> > traceSegment;
    planeTraces(mesh.xyz, mesh.triangles, frame,
                [&](std::size_t t) {
                  const int b = t < mesh.branch.size() ? mesh.branch[t] : 0;
                  return b == plane.branch || together.count(b) != 0;
                },
                traceNode, traceSegment);
    const std::size_t before = cutterTriangles.size();
    out.fences = reentrantFences(skin, frame, reach, tolerance, onSheet, traceNode, traceSegment,
                                 out.corners, out.closures, cutterXyz, cutterTriangles);
    if(out.fences + out.closures) {
      const PlaneCut without = cut;
      const std::map<int, std::size_t> keptWithout = kept;
      const std::vector<int> mergedWithout = out.merged;
      if(!firstPass()) {
        // (the fences are given up rather than the extension)
        cutterTriangles.resize(before);
        out.fences = out.closures = 0;
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
    // (the chain, for extendFront)
    out.chainStart.push_back(int(out.normal.size() / 3));
    out.chainClosed.push_back(loop ? 1 : 0);
    out.chainSign.push_back(outward < 0. ? -1. : 1.);
    for(int i = 0; i < n; ++i)
      for(int k = 0; k < 3; ++k) out.normal.push_back(normal[chain[i]][k]);
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

bool extendFront(const Ribbon &rows, double length, int layers, const std::vector<double> *limit,
                 Ribbon &out)
{
  out = Ribbon{};
  out.boundaryEdges = rows.boundaryEdges;
  out.freeEdges = rows.freeEdges;
  out.loops = rows.loops;
  out.boundaryLength = rows.boundaryLength;
  std::vector<int> base;
  for(std::size_t i = 0; i < rows.source.size(); ++i)
    if(rows.source[i] >= 0) base.push_back(int(i));
  const int chains = int(rows.chainStart.size());
  if(!(length > 0.) || layers < 1 || !chains || rows.normal.size() != 3 * base.size() ||
     (limit && limit->size() != base.size()))
    return false;
  const auto unit = [](Vec a) {
    const double l = norm(a);
    if(l > 0.)
      for(double &c : a) c /= l;
    return a;
  };
  const auto along = [](const Vec &a, const Vec &d, double s) {
    return Vec{a[0] + s * d[0], a[1] + s * d[1], a[2] + s * d[2]};
  };
  const double hmax = length / layers, full = length * (1. - 1.e-9);

  // the nodes of the free boundary, in cells, for the distance to it
  const double cell = length / 4.;
  const auto cellOf = [&](double x) { return std::int64_t(std::floor(x / cell)); };
  const auto cellKey = [](std::int64_t i, std::int64_t j, std::int64_t k) {
    return (std::uint64_t(i & 0x1fffff) << 42) | (std::uint64_t(j & 0x1fffff) << 21) |
           std::uint64_t(k & 0x1fffff);
  };
  std::vector<Vec> boundary(base.size());
  std::unordered_map<std::uint64_t, std::vector<int> > grid;
  for(std::size_t r = 0; r < base.size(); ++r) {
    boundary[r] = point(rows.mesh, base[r]);
    grid[cellKey(cellOf(boundary[r][0]), cellOf(boundary[r][1]), cellOf(boundary[r][2]))].push_back(int(r));
  }
  const auto tooClose = [&](const Vec &q, double radius) {
    const double r2 = radius * radius;
    for(std::int64_t i = cellOf(q[0] - radius); i <= cellOf(q[0] + radius); ++i)
      for(std::int64_t j = cellOf(q[1] - radius); j <= cellOf(q[1] + radius); ++j)
        for(std::int64_t k = cellOf(q[2] - radius); k <= cellOf(q[2] + radius); ++k) {
          const auto found = grid.find(cellKey(i, j, k));
          if(found == grid.end()) continue;
          for(int r : found->second) {
            const Vec d = sub(boundary[r], q);
            if(dot(d, d) < r2) return true;
          }
        }
    return false;
  };

  struct Node {
    Vec p, n;
    int id;
    double lim;
  };
  struct Front {
    std::vector<Node> nodes;
    bool closed;
    double D, h, orient;
    int chain;
  };
  const auto vertex = [&](const Vec &p, int source, double u, double v) {
    const int id = int(out.mesh.xyz.size() / 3);
    out.mesh.xyz.insert(out.mesh.xyz.end(), p.begin(), p.end());
    out.u.push_back(u);
    out.v.push_back(v);
    out.source.push_back(source);
    out.far.push_back(0);
    return id;
  };
  const auto triangle = [&](int a, int b, int c, int chain) {
    out.mesh.triangles.insert(out.mesh.triangles.end(), {a, b, c});
    out.mesh.branch.push_back(chain);
    out.mesh.parent.push_back(-1);
  };
  std::vector<Front> work;
  for(int c = 0; c < chains; ++c) {
    const int first = rows.chainStart[c],
              last = c + 1 < chains ? rows.chainStart[c + 1] : int(base.size());
    Front f;
    f.closed = rows.chainClosed[c] != 0;
    f.D = 0.;
    f.chain = c;
    f.orient = -rows.chainSign[c];
    double u = 0.;
    for(int r = first; r < last; ++r) {
      if(r > first) u += norm(sub(boundary[r], boundary[r - 1]));
      Node node;
      node.p = boundary[r];
      node.n = unit(Vec{rows.normal[3 * r], rows.normal[3 * r + 1], rows.normal[3 * r + 2]});
      node.lim = limit ? std::min((*limit)[r], length) : length;
      node.id = vertex(node.p, rows.source[base[r]], u, 0.);
      f.nodes.push_back(node);
    }
    const int n = int(f.nodes.size());
    if(n < 2) continue;
    f.h = std::min(hmax, std::max(2. * u / (n - 1), length / 64.));
    work.push_back(std::move(f));
  }

  while(!work.empty()) {
    Front f = std::move(work.back());
    work.pop_back();
    const double o = f.orient;
    // turned like the surface: the triangle of an edge of the front and a
    // point on the side of the extension
    const auto valid = [&](const Node &x, const Node &y, const Node &z) {
      const Vec e1 = sub(y.p, x.p), e2 = sub(z.p, x.p);
      const Vec m = {x.n[0] + z.n[0], x.n[1] + z.n[1], x.n[2] + z.n[2]};
      return o * dot(cross(e1, e2), m) > 1.e-9 * norm(e1) * norm(e2) * norm(m);
    };
    double h = std::min(f.h, length - f.D);
    if(length - f.D - h < .25 * h) h = length - f.D;
    // the notches of the boundary narrower than the step, filled by ears
    if(f.D == 0.) {
      std::vector<Node> kept;
      for(const Node &w : f.nodes) {
        while(kept.size() >= 2) {
          const Node &u = kept[kept.size() - 2], &v = kept.back();
          const Vec e1 = sub(v.p, u.p), e2 = sub(w.p, v.p);
          const double l = norm(e1) * norm(e2);
          const double sine = o * dot(cross(e1, e2), v.n), cosine = dot(e1, e2);
          if(!(sine > 1.e-9 * l && cosine < .866 * l) || norm(sub(w.p, u.p)) >= h) break;
          triangle(u.id, v.id, w.id, f.chain);
          kept.pop_back();
        }
        kept.push_back(w);
      }
      f.nodes.swap(kept);
    }
    const int n = int(f.nodes.size());
    if(n < 2 || (f.closed && n < 3)) continue;
    const auto wrap = [&](int i) {
      return f.closed ? ((i % n) + n) % n : std::min(n - 1, std::max(0, i));
    };
    // the front smoothed, over half the step
    double total = 0.;
    for(int i = 0; i + 1 < n; ++i) total += norm(sub(f.nodes[i + 1].p, f.nodes[i].p));
    const double mean = total / (n - 1);
    const int w = std::max(1, std::min(std::max(1, n / 6), int(.5 * h / std::max(mean, 1.e-300) + .5)));
    std::vector<Vec> S(n);
    for(int i = 0; i < n; ++i) S[i] = f.nodes[i].p;
    for(int pass = 0; pass < 2; ++pass) {
      std::vector<Vec> next(S);
      for(int i = 0; i < n; ++i) {
        const int reach = f.closed ? w : std::min(w, std::min(i, n - 1 - i));
        if(!reach) continue;
        Vec sum = {0., 0., 0.};
        for(int k = -reach; k <= reach; ++k)
          for(int c = 0; c < 3; ++c) sum[c] += S[wrap(i + k)][c];
        for(int c = 0; c < 3; ++c) next[i][c] = sum[c] / (2 * reach + 1);
      }
      S.swap(next);
    }
    // its offset, beyond its own bumps; the points at their limit, or closer
    // to another part of the boundary than to their own, end their part of
    // the front
    std::vector<Vec> O(n);
    std::vector<unsigned char> state(n, 0); // 1 turned back (left out), 2 ended
    bool anyEnded = false;
    for(int i = 0; i < n; ++i) {
      const double remain = f.nodes[i].lim - f.D;
      if(remain < .25 * h) {
        state[i] = 2;
        anyEnded = true;
        continue;
      }
      const double step = std::min(h, remain);
      Vec d = unit(cross(sub(S[wrap(i + 1)], S[wrap(i - 1)]), f.nodes[i].n));
      for(double &c : d) c *= -o;
      double bump = 0.;
      for(int k = -w - 1; k <= w + 1; ++k) {
        const int j = wrap(i + k);
        bump = std::max(bump, dot(sub(f.nodes[j].p, S[j]), d));
      }
      O[i] = along(S[i], d, step + bump);
      if(tooClose(O[i], .9 * (f.D + step))) {
        state[i] = 2;
        anyEnded = true;
      }
    }
    const bool loop = f.closed && !anyEnded;
    int start = 0;
    if(f.closed && anyEnded)
      for(int i = 0; i < n; ++i)
        if(state[i] == 2) {
          start = (i + 1) % n;
          break;
        }
    for(int at = 0; at < n;) {
      if(state[(start + at) % n] == 2) {
        ++at;
        continue;
      }
      int end = at;
      while(end + 1 < n && state[(start + end + 1) % n] != 2) ++end;
      std::vector<int> R;
      for(int k = at; k <= end; ++k) R.push_back((start + k) % n);
      at = end + 1;
      const int nA = int(R.size());
      if(nA < 2) continue;
      // where the offset turns back, its points are left out
      bool drop = false;
      for(bool changed = true; changed && !drop;) {
        changed = false;
        int prev = -1;
        for(int k = 0; k < nA + (loop ? 1 : 0) && !drop; ++k) {
          const int i = R[k % nA];
          if(state[i]) continue;
          if(prev >= 0 && prev != i) {
            const Vec cs = sub(S[i], S[prev]), co = sub(O[i], O[prev]);
            if(dot(co, cs) <= .1 * dot(cs, cs)) {
              const bool ep = !loop && (prev == R.front() || prev == R.back()),
                         ei = !loop && (i == R.front() || i == R.back());
              if(ep && ei)
                drop = true;
              else {
                if(!ep) state[prev] = 1;
                if(!ei) state[i] = 1;
                changed = true;
              }
            }
          }
          prev = state[i] ? (state[prev < 0 ? i : prev] ? -1 : prev) : i;
        }
      }
      if(loop) { // from a point of the offset that stays
        int first = 0;
        while(first < nA && state[R[first]]) ++first;
        if(first < nA) std::rotate(R.begin(), R.begin() + first, R.end());
      }
      std::vector<int> live;
      for(int k = 0; k < nA; ++k)
        if(!state[R[k]]) live.push_back(k);
      const auto A = [&](int k) -> const Node & { return f.nodes[R[k % nA]]; };
      // a loop that closes: filled from its centre
      const auto fan = [&]() {
        Node c;
        c.p = {0., 0., 0.};
        c.n = {0., 0., 0.};
        for(int k = 0; k < nA; ++k)
          for(int x = 0; x < 3; ++x) {
            c.p[x] += A(k).p[x] / nA;
            c.n[x] += A(k).n[x];
          }
        c.n = unit(c.n);
        for(int k = 0; k < nA; ++k)
          if(!valid(A(k), A(k + 1), c)) return;
        c.id = vertex(c.p, -1, 0., f.D + h);
        for(int k = 0; k < nA; ++k) triangle(A(k).id, A(k + 1).id, c.id, f.chain);
      };
      const int q = int(live.size());
      if(drop || q < (loop ? 3 : 2)) {
        if(loop && !drop) fan();
        continue;
      }
      // the parameters of the nodes along the smoothed front, and the new
      // front: the offset sampled again
      std::vector<double> sA(nA + 1, 0.);
      for(int k = 1; k < nA; ++k) sA[k] = sA[k - 1] + norm(sub(S[R[k]], S[R[k - 1]]));
      sA[nA] = sA[nA - 1] + norm(sub(S[R[0]], S[R[nA - 1]]));
      const int segments = loop ? q : q - 1;
      std::vector<double> tO(1, 0.);
      for(int e = 0; e < segments; ++e)
        tO.push_back(tO.back() + norm(sub(O[R[live[(e + 1) % q]]], O[R[live[e]]])));
      const double lengthO = tO.back();
      if(!(lengthO > 1.e-12 * length)) {
        if(loop) fan();
        continue;
      }
      const double spacing = std::max(mean, std::min(h, .5 * hmax));
      const int m = loop ? std::max(3, int(lengthO / spacing + .5)) :
                           std::max(2, int(lengthO / spacing + .5) + 1);
      std::vector<Node> B(m);
      std::vector<double> uB(m + 1, 0.);
      for(int j = 0, e = 0; j < m; ++j) {
        const double t = loop ? lengthO * j / m : lengthO * j / (m - 1);
        while(e + 1 < segments && tO[e + 1] < t) ++e;
        const int ka = live[e], kb = live[(e + 1) % q];
        const double span = tO[e + 1] - tO[e], x = span > 0. ? std::min(1., (t - tO[e]) / span) : 0.;
        const Node &a = f.nodes[R[ka]], &b = f.nodes[R[kb]];
        Node node;
        for(int c = 0; c < 3; ++c) {
          node.p[c] = (1. - x) * O[R[ka]][c] + x * O[R[kb]][c];
          node.n[c] = (1. - x) * a.n[c] + x * b.n[c];
        }
        node.n = unit(node.n);
        node.lim = std::min(a.lim, b.lim);
        const double pa = sA[ka], pb = (loop && e + 1 == q) ? sA[nA] : sA[kb];
        uB[j] = pa + x * (pb - pa);
        node.id = vertex(node.p, -1, uB[j], f.D + h);
        B[j] = node;
      }
      uB[m] = loop ? uB[0] + sA[nA] : uB[m - 1];
      // the strip: along both lines at once, each triangle turned like the
      // surface
      const auto Bn = [&](int k) -> const Node & { return B[k % m]; };
      const int endA = loop ? nA : nA - 1, endB = loop ? m : m - 1;
      for(int i = 0, j = 0; i < endA || j < endB;) {
        const bool canA = i < endA, canB = j < endB;
        const bool vA = canA && valid(A(i), A(i + 1), Bn(j));
        const bool vB = canB && valid(A(i), Bn(j + 1), Bn(j));
        bool takeA, made = true;
        if(vA != vB)
          takeA = vA;
        else if(vA) // (the edge of the front first if the next point no longer sees it)
          takeA = !valid(A(i), A(i + 1), Bn(j + 1)) || sA[i + 1] <= uB[j + 1];
        else {
          made = false;
          takeA = canA && (!canB || sA[i + 1] <= uB[j + 1]);
          ++out.foldedEdges;
        }
        if(takeA) {
          if(made) triangle(A(i).id, A(i + 1).id, Bn(j).id, f.chain);
          ++i;
        }
        else {
          if(made) triangle(A(i).id, Bn(j + 1).id, Bn(j).id, f.chain);
          ++j;
        }
      }
      Front g;
      g.nodes = std::move(B);
      g.closed = loop;
      g.D = f.D + h;
      g.h = std::min(2. * f.h, hmax);
      g.orient = o;
      g.chain = f.chain;
      if(g.D >= full) {
        for(const Node &b : g.nodes)
          if(b.lim >= full) out.far[b.id] = 1;
      }
      else
        work.push_back(std::move(g));
    }
  }
  return true;
}

namespace {

// A ribbon ready to be cut: its vertices, with the rows shortened, then those
// of the triangles of the skin and of the other branches near it.
struct RibbonCut {
  std::vector<double> xyz;
  std::vector<int> triangles; // of the ribbon first
  std::size_t cutters = 0, stoppedRows = 0;
  std::vector<int> rowStart; // rows + 1 entries
  std::vector<unsigned char> shortened; // one per row
};

void prepareRibbon(const Mesh &mesh, const Mesh &skin, int branch, const Ribbon &ribbon,
                   RibbonCut &ready)
{
  const std::size_t own = ribbon.mesh.triangles.size() / 3;
  std::vector<double> &xyz = ready.xyz;
  std::vector<int> &triangles = ready.triangles;
  std::vector<int> &rowStart = ready.rowStart;
  std::vector<unsigned char> &shortened = ready.shortened;
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
  xyz = ribbon.mesh.xyz;
  triangles = ribbon.mesh.triangles;
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
      ++ready.cutters;
    }
  };
  cutters(skin, false);
  const std::size_t skinCutters = ready.cutters;
  cutters(mesh, true);

  // A row of the ribbon that does not end on the skin may go on inside a wall
  // that the branch stands on, along it. The face of the skin that stops the
  // nearest row that does end on the skin (within the length of the row along
  // the boundary) is prolonged into the wall: the row stops where it crosses
  // the plane of that face, unless it ends before on the sheet of another
  // branch, or shortly after on one that faces it (a wall the branch ends on:
  // the row has to reach its mid-surface).
  rowStart.clear();
  for(std::size_t i = 0; i < ribbon.source.size(); ++i)
    if(ribbon.source[i] >= 0) rowStart.push_back(int(i));
  const int rows = int(rowStart.size());
  rowStart.push_back(int(ribbon.source.size()));
  shortened.assign(rows, 0);
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
      ++ready.stoppedRows;
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

}

} // namespace

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
  RibbonCut prepared;
  prepareRibbon(mesh, skin, branch, ribbon, prepared);
  out.cutters = prepared.cutters;
  out.stoppedRows = prepared.stoppedRows;
  const std::vector<double> &xyz = prepared.xyz;
  const std::vector<int> &triangles = prepared.triangles;
  const std::vector<int> &rowStart = prepared.rowStart;
  const std::vector<unsigned char> &shortened = prepared.shortened;
  const int rows = int(rowStart.size()) - 1;

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
// All the branches at once.

namespace {

// The plane of a branch fitted on its triangles that are within the tolerance
// of it only, starting from the plane given: the branch of a wall with the
// cusps it has along its junctions (its sheet leaves its mid-plane there, to
// meet the sheets of the other walls where the fillets put the junction).
// Returns the share of its area within the tolerance of the plane found, with
// the share within an eighth of it (the flat part itself: a curved sheet has
// little of its area that close to any plane) and the largest distance to it.
double planeOfTheFlatPart(const Mesh &mesh, const std::vector<std::size_t> &triangles,
                          double tolerance, BranchPlane &plane, double &flatShare,
                          double &farthest)
{
  flatShare = farthest = 0.;
  std::vector<double> area(triangles.size());
  std::vector<Vec> centroid(triangles.size());
  double all = 0.;
  for(std::size_t i = 0; i < triangles.size(); ++i) {
    area[i] = triangle(mesh, triangles[i], centroid[i]);
    all += area[i];
  }
  if(!(all > 0.)) return 0.;
  Vec origin = {plane.origin[0], plane.origin[1], plane.origin[2]};
  Vec normal = {plane.normal[0], plane.normal[1], plane.normal[2]};
  const double length = norm(normal);
  for(double &x : normal) x /= length;
  // Fitted on what is within the tolerance, then within a half, a quarter and
  // an eighth of it (as long as that is a third of the area): the start of a
  // cusp is within the tolerance too, and tilts the plane towards it.
  double within = tolerance;
  for(int pass = 0; pass < 6; ++pass) {
    double weight = 0.;
    Vec mean = {0., 0., 0.};
    for(std::size_t i = 0; i < triangles.size(); ++i) {
      if(std::abs(dot(sub(centroid[i], origin), normal)) > within) continue;
      weight += area[i];
      for(int k = 0; k < 3; ++k) mean[k] += area[i] * centroid[i][k];
    }
    if(3. * weight < all) {
      if(pass == 0) return 0.;
      break;
    }
    for(double &x : mean) x /= weight;
    Eigen::Matrix3d covariance = Eigen::Matrix3d::Zero();
    for(std::size_t i = 0; i < triangles.size(); ++i) {
      if(std::abs(dot(sub(centroid[i], origin), normal)) > within) continue;
      const Vec d = sub(centroid[i], mean);
      for(int r = 0; r < 3; ++r)
        for(int c = 0; c < 3; ++c) covariance(r, c) += area[i] * d[r] * d[c];
    }
    const Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> solver(covariance);
    const Eigen::Vector3d smallest = solver.eigenvectors().col(0);
    origin = mean;
    normal = {smallest[0], smallest[1], smallest[2]};
    if(pass >= 2 && within > .2 * tolerance) within *= .5;
  }
  double in = 0., flat = 0.;
  for(std::size_t i = 0; i < triangles.size(); ++i) {
    const double distance = std::abs(dot(sub(centroid[i], origin), normal));
    if(distance <= tolerance) in += area[i];
    if(distance <= .125 * tolerance) flat += area[i];
  }
  flatShare = flat / all;
  farthest = 0.;
  for(std::size_t i = 0; i < triangles.size(); ++i)
    farthest = std::max(farthest, std::abs(dot(sub(centroid[i], origin), normal)));
  for(int k = 0; k < 3; ++k) {
    plane.origin[k] = origin[k];
    plane.normal[k] = normal[k];
  }
  return in / all;
}

} // namespace

bool extendAllBranches(const Mesh &mesh, const Mesh &skin, double tolerance, double size,
                       double reach, int layers, double minArea, const std::set<int> &fixed,
                       GlobalExtension &out, std::string &error, const Mesh *original,
                       const std::vector<BranchPlane> *planes)
{
  const auto start = std::chrono::steady_clock::now();
  out = GlobalExtension{};
  error.clear();
  if(!(tolerance > 0.) || !(size > 0.) || !(reach > 0.) || layers < 1 || !std::isfinite(tolerance) ||
     !std::isfinite(size) || !std::isfinite(reach)) {
    error = "The tolerance, the size and the reach must be positive, with at least one layer";
    return false;
  }
  if(skin.triangles.empty() || mesh.triangles.empty()) {
    error = "A skin and a MAT are needed";
    return false;
  }
  const std::size_t count = mesh.triangles.size() / 3;
  const auto branchOf = [&](std::size_t t) { return t < mesh.branch.size() ? mesh.branch[t] : 0; };
  std::map<int, std::vector<std::size_t> > trianglesOf;
  for(std::size_t t = 0; t < count; ++t) trianglesOf[branchOf(t)].push_back(t);
  const double parallel = std::cos(15. * 3.14159265358979323846 / 180.);
  // whether a triangle of the MAT lies in a plane
  const auto lies = [&](const Frame &frame, std::size_t t) {
    Vec centroid, normal;
    const double area = triangle(mesh, t, centroid, &normal);
    return area > 0. && std::abs(frame.distance(centroid)) <= tolerance &&
           std::abs(dot(normal, frame.n)) >= parallel * 2. * area;
  };

  // The surfaces: one per plane, for the flat branches lying in it, and one
  // per other branch with a free boundary.
  struct Surface {
    bool planar = true;
    int branch = 0;
    std::vector<int> members;
    BranchPlane plane;
    Ribbon ribbon;
    std::vector<int> rowStart;
    std::vector<unsigned char> shortened;
    std::size_t firstVertex = 0, firstTriangle = 0, triangles = 0;
    std::vector<std::array<double, 2> > seeds;
    std::vector<int> seedBranch;
    std::vector<int> pieces; // of the cut
    ExtensionSurface report;
  };
  std::vector<Surface> surfaces;
  std::map<int, int> planeOf; // of a flat branch
  std::set<int> speck, curved;
  // The vertices of the junctions of the MAT (edges of three triangles or
  // more, or of two branches), in cells of the size of the reach: the cusp of
  // a wall is along one of them.
  std::unordered_map<std::uint64_t, std::vector<int> > junctionCells;
  bool junctionsFound = false;
  const Mesh &whole = original ? *original : mesh;
  const auto cell3 = [&](const Vec &q, int di, int dj, int dk) {
    const std::int64_t i = std::int64_t(std::floor(q[0] / reach)) + di,
                       j = std::int64_t(std::floor(q[1] / reach)) + dj,
                       k = std::int64_t(std::floor(q[2] / reach)) + dk;
    return (std::uint64_t(i & 0x1fffff) << 42) | (std::uint64_t(j & 0x1fffff) << 21) |
           std::uint64_t(k & 0x1fffff);
  };
  const auto nearJunction = [&](const Vec &q) {
    if(!junctionsFound) {
      junctionsFound = true;
      std::unordered_map<std::uint64_t, std::pair<int, int> > seen; // triangles, first branch (-2: several)
      const std::size_t n = whole.triangles.size() / 3;
      seen.reserve(3 * n / 2);
      for(std::size_t t = 0; t < n; ++t) {
        const int b = t < whole.branch.size() ? whole.branch[t] : 0;
        for(int c = 0; c < 3; ++c) {
          std::pair<int, int> &e =
            seen.emplace(edgeKey(whole.triangles[3 * t + c], whole.triangles[3 * t + (c + 1) % 3]),
                         std::make_pair(0, b)).first->second;
          if(e.second != b) e.second = -2;
          ++e.first;
        }
      }
      std::vector<unsigned char> marked(whole.xyz.size() / 3, 0);
      for(const auto &e : seen) {
        if(e.second.first < 3 && e.second.second != -2) continue;
        for(const int v : {int(e.first >> 32), int(e.first & 0xffffffffu)}) {
          if(marked[v]) continue;
          marked[v] = 1;
          junctionCells[cell3(point(whole, v), 0, 0, 0)].push_back(v);
        }
      }
    }
    for(int di = -1; di <= 1; ++di)
      for(int dj = -1; dj <= 1; ++dj)
        for(int dk = -1; dk <= 1; ++dk) {
          const auto found = junctionCells.find(cell3(q, di, dj, dk));
          if(found == junctionCells.end()) continue;
          for(int v : found->second)
            if(norm(sub(point(whole, v), q)) <= reach) return true;
        }
    return false;
  };
  const std::vector<BranchPlane> computed = planes ? std::vector<BranchPlane>() : branchPlanes(mesh);
  for(const BranchPlane &listed : planes ? *planes : computed) { // largest first
    BranchPlane p = listed;
    if(fixed.count(p.branch)) continue;
    if(p.area < minArea) {
      speck.insert(p.branch);
      ++out.specks;
      continue;
    }
    // Flat, or flat but for the cusps it has along its junctions: at least
    // half of its area within an eighth of the tolerance of a plane (really
    // flat: a curved sheet does not have that), nothing further from it than
    // half the reach, and what is off the plane within the reach of a
    // junction of the MAT. Such a branch is replaced whole by its plane.
    bool flat = p.deviation <= tolerance;
    double cusps = 0.;
    if(!flat) {
      double farthest = 0., flatShare = 0.;
      BranchPlane fitted = p;
      planeOfTheFlatPart(mesh, trianglesOf[p.branch], tolerance, fitted, flatShare, farthest);
      if(flatShare >= .5 && farthest <= .5 * reach) {
        const Frame frame(fitted);
        flat = true;
        for(std::size_t t : trianglesOf[p.branch]) {
          Vec centroid;
          const double area = triangle(mesh, t, centroid);
          if(!(area > 0.) || std::abs(frame.distance(centroid)) <= tolerance) continue;
          cusps += area;
          if(!nearJunction(centroid)) {
            flat = false;
            break;
          }
        }
        if(flat) p = fitted;
      }
    }
    if(flat) {
      // (the plane of another branch already there, if its flat part lies in it)
      int joined = -1;
      const Frame own(p);
      for(std::size_t s = 0; s < surfaces.size() && joined < 0; ++s) {
        if(!surfaces[s].planar) continue;
        const Frame frame(surfaces[s].plane);
        double all = 0., in = 0.;
        for(std::size_t t : trianglesOf[p.branch]) {
          Vec centroid;
          const double area = triangle(mesh, t, centroid);
          if(std::abs(own.distance(centroid)) > tolerance) continue;
          all += area;
          if(lies(frame, t)) in += area;
        }
        if(all > 0. && in >= .9 * all) joined = int(s);
      }
      if(joined < 0) {
        joined = int(surfaces.size());
        surfaces.emplace_back();
        surfaces.back().plane = p;
        surfaces.back().branch = p.branch;
      }
      surfaces[joined].members.push_back(p.branch);
      surfaces[joined].report.area += p.area;
      surfaces[joined].report.cusps += cusps;
      planeOf[p.branch] = joined;
    }
    else {
      Surface s;
      s.planar = false;
      s.branch = p.branch;
      s.members = {p.branch};
      s.report.area = p.area;
      std::string why;
      // (its rows, one layer: where each one is stopped; the band is made
      // from them below)
      if(!branchRibbon(mesh, p.branch, reach, 1, s.ribbon, why, original)) {
        ++out.unextended; // no free boundary: nothing to extend
        continue;
      }
      curved.insert(p.branch);
      surfaces.push_back(std::move(s));
    }
  }
  if(surfaces.empty()) {
    error = "No branch to extend";
    return false;
  }
  const int surfaceCount = int(surfaces.size());

  // What is cut together: triangles with their kind and their owner (the
  // surface of a patch, of a ribbon or of a fence; the branch of a sheet).
  enum Kind { Skin, Sheet, Patch, Strip, Fence };
  std::vector<double> in;
  std::vector<int> tri, kind, owner;
  // of a sheet that is cut: its triangle in the mesh, by its index in tri,
  // and its vertices in the mesh, by their index in in
  std::unordered_map<int, int> sheetTriangle, sheetVertex;
  // the strips that prolong a sheet to a plane, by their index in tri: the
  // surface of the plane, and the side of it the sheet is on
  struct Prolonged {
    int surface;
    double side;
  };
  std::unordered_map<int, Prolonged> stripOf;
  const auto add = [&](const std::vector<double> &xyz, const std::vector<int> &triangles, int k,
                       int o) {
    const int first = int(in.size() / 3);
    in.insert(in.end(), xyz.begin(), xyz.end());
    for(int v : triangles) tri.push_back(first + v);
    kind.insert(kind.end(), triangles.size() / 3, k);
    owner.insert(owner.end(), triangles.size() / 3, o);
    return first;
  };
  for(int s = 0; s < surfaceCount; ++s) {
    Surface &f = surfaces[s];
    f.report.branch = f.branch;
    f.report.branches = f.members;
    f.report.planar = f.planar;
    std::vector<double> xyz;
    std::vector<int> triangles;
    if(!f.planar) {
      RibbonCut ready;
      prepareRibbon(mesh, skin, f.branch, f.ribbon, ready);
      // the band that extends the branch without folds, each row as far as
      // it was stopped
      const int rows = int(ready.rowStart.size()) - 1;
      std::vector<double> limit(rows, reach);
      for(int r = 0; r < rows; ++r) {
        if(!ready.shortened[r]) continue;
        const std::size_t a = std::size_t(ready.rowStart[r]), b = std::size_t(ready.rowStart[r + 1]) - 1;
        limit[r] = norm(sub(Vec{ready.xyz[3 * b], ready.xyz[3 * b + 1], ready.xyz[3 * b + 2]},
                            Vec{ready.xyz[3 * a], ready.xyz[3 * a + 1], ready.xyz[3 * a + 2]}));
      }
      Ribbon band;
      const auto before = std::chrono::steady_clock::now();
      const bool made = extendFront(f.ribbon, reach, layers, &limit, band);
      out.bandSeconds += std::chrono::duration<double>(std::chrono::steady_clock::now() - before).count();
      if(!made) {
        error = "The band of branch " + std::to_string(f.branch) + " could not be made";
        return false;
      }
      out.unfolded += band.foldedEdges;
      f.ribbon = std::move(band);
      xyz = f.ribbon.mesh.xyz;
      triangles = f.ribbon.mesh.triangles;
      f.report.stoppedRows = ready.stoppedRows;
    }
    else {
      // The part of the plane within the reach of its branches, and the
      // triangles of the branches that the kept pieces have to hold.
      const Frame frame(f.plane);
      std::unordered_set<std::uint64_t> near;
      const auto cellOf = [&](const std::array<double, 2> &q, int di, int dj) {
        const std::int64_t i = std::int64_t(std::floor(q[0] / reach)) + di,
                           j = std::int64_t(std::floor(q[1] / reach)) + dj;
        return (std::uint64_t(std::uint32_t(i)) << 32) | std::uint32_t(j);
      };
      double lo[2] = {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()};
      double hi[2] = {-lo[0], -lo[1]};
      for(int b : f.members) {
        std::vector<std::size_t> inPlane;
        for(std::size_t t : trianglesOf[b]) {
          Vec centroid;
          if(!(triangle(mesh, t, centroid) > 0.) || std::abs(frame.distance(centroid)) > tolerance)
            continue;
          inPlane.push_back(t);
          const std::array<double, 2> q = frame.uv(centroid);
          for(int c = 0; c < 2; ++c) {
            lo[c] = std::min(lo[c], q[c]);
            hi[c] = std::max(hi[c], q[c]);
          }
          for(int di = -1; di <= 1; ++di)
            for(int dj = -1; dj <= 1; ++dj) near.insert(cellOf(q, di, dj));
        }
        const std::size_t step = std::max<std::size_t>(1, inPlane.size() / 200);
        for(std::size_t i = step / 2; i < inPlane.size(); i += step) {
          Vec centroid;
          triangle(mesh, inPlane[i], centroid);
          f.seeds.push_back(frame.uv(centroid));
          f.seedBranch.push_back(b);
        }
      }
      if(f.seeds.empty()) continue; // (nothing of it in its plane: left as it is)
      const double spacing = std::max(size, std::max(hi[0] - lo[0], hi[1] - lo[1]) / 400.);
      for(int c = 0; c < 2; ++c) {
        lo[c] -= 2. * reach + spacing;
        hi[c] += 2. * reach + spacing;
      }
      const int nx = std::max(1, int(std::ceil((hi[0] - lo[0]) / spacing))),
                ny = std::max(1, int(std::ceil((hi[1] - lo[1]) / spacing)));
      std::unordered_map<std::uint64_t, int> vertexOf;
      const auto vertex = [&](int i, int j) {
        const auto inserted =
          vertexOf.emplace((std::uint64_t(std::uint32_t(i)) << 32) | std::uint32_t(j), int(xyz.size() / 3));
        if(inserted.second) {
          const Vec q = frame.at(lo[0] + i * spacing, lo[1] + j * spacing);
          xyz.insert(xyz.end(), q.begin(), q.end());
        }
        return inserted.first->second;
      };
      for(int j = 0; j < ny; ++j)
        for(int i = 0; i < nx; ++i) {
          if(!near.count(cellOf({lo[0] + (i + .5) * spacing, lo[1] + (j + .5) * spacing}, 0, 0)))
            continue;
          const int a = vertex(i, j), b = vertex(i + 1, j), c = vertex(i + 1, j + 1),
                    d = vertex(i, j + 1);
          if((i + j) % 2 == 0)
            triangles.insert(triangles.end(), {a, b, c, a, c, d});
          else
            triangles.insert(triangles.end(), {a, b, d, b, c, d});
        }
    }
    f.firstTriangle = tri.size() / 3;
    f.triangles = triangles.size() / 3;
    f.firstVertex = std::size_t(add(xyz, triangles, f.planar ? Patch : Strip, s));
    // (for the view of the surfaces before the cut)
    const int first = int(out.surfaces.xyz.size() / 3);
    out.surfaces.xyz.insert(out.surfaces.xyz.end(), xyz.begin(), xyz.end());
    for(int v : triangles) out.surfaces.triangles.push_back(first + v);
    out.surfaces.branch.insert(out.surfaces.branch.end(), triangles.size() / 3, f.branch);
    out.surfaces.parent.insert(out.surfaces.parent.end(), triangles.size() / 3, -1);
  }
  const std::size_t surfaceTriangles = tri.size() / 3;
  if(!surfaceTriangles) {
    error = "No branch to extend";
    return false;
  }
  // The faces of the part prolonged at its reentrant corners, for each plane.
  for(int s = 0; s < surfaceCount; ++s) {
    Surface &f = surfaces[s];
    if(!f.planar || !f.triangles) continue;
    const Frame frame(f.plane);
    const std::set<int> members(f.members.begin(), f.members.end());
    Footprint sheets(.125 * reach);
    bool sheetsFound = false;
    const auto onSheet = [&](const std::array<double, 2> &q) {
      if(!sheetsFound) {
        sheetsFound = true;
        for(int b : f.members)
          for(std::size_t t : trianglesOf[b])
            if(lies(frame, t))
              sheets.add(frame.uv(point(mesh, mesh.triangles[3 * t])),
                         frame.uv(point(mesh, mesh.triangles[3 * t + 1])),
                         frame.uv(point(mesh, mesh.triangles[3 * t + 2])));
      }
      return sheets.holds(q);
    };
    std::vector<double> xyz;
    std::vector<int> triangles;
    {
      // the faces, prolonged to the sheets of the other branches as the MAT
      // has them
      std::vector<std::array<double, 2> > traceNode;
      std::vector<std::array<int, 2> > traceSegment;
      planeTraces(mesh.xyz, mesh.triangles, frame,
                  [&](std::size_t t) {
                    const int b = branchOf(t);
                    return members.count(b) != 0 || speck.count(b) != 0;
                  },
                  traceNode, traceSegment);
      std::size_t none = 0;
      f.report.fences = reentrantFences(skin, frame, reach, tolerance, onSheet, traceNode,
                                        traceSegment, f.report.corners, none, xyz, triangles,
                                        false, true);
    }
    {
      // The sheets that stay end a little short of the planes that replace
      // the branches they ended on: the lines of what cuts the plane in the
      // end (these sheets and the surfaces of the other branches) are
      // prolonged where they stop just short of each other.
      std::vector<std::array<double, 2> > traceNode;
      std::vector<std::array<int, 2> > traceSegment;
      planeTraces(mesh.xyz, mesh.triangles, frame,
                  [&](std::size_t t) {
                    const int b = branchOf(t);
                    return planeOf.count(b) != 0 || speck.count(b) != 0;
                  },
                  traceNode, traceSegment);
      planeTraces(in, tri, frame,
                  [&](std::size_t t) { return (kind[t] != Patch && kind[t] != Strip) || owner[t] == s; },
                  traceNode, traceSegment);
      std::size_t none = 0;
      reentrantFences(skin, frame, reach, tolerance, onSheet, traceNode, traceSegment, none,
                      f.report.closures, xyz, triangles, true, false);
    }
    if(!triangles.empty()) add(xyz, triangles, Fence, s);
  }
  // The triangles of the skin, and of the sheets that stay, near the surfaces
  // (the sheets lying in one of the planes left out, like the specks).
  {
    double lo[3] = {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
                    std::numeric_limits<double>::infinity()};
    double hi[3] = {-lo[0], -lo[1], -lo[2]};
    for(std::size_t i = 0; i < in.size(); ++i) {
      lo[i % 3] = std::min(lo[i % 3], in[i]);
      hi[i % 3] = std::max(hi[i % 3], in[i]);
    }
    double cell = 0.;
    for(int k = 0; k < 3; ++k) cell = std::max(cell, hi[k] - lo[k]);
    cell = std::max(cell / 128., 1.e-12);
    const auto cellOf = [&](double value, int k) { return int(std::floor((value - lo[k]) / cell)); };
    const auto cellKey = [](int i, int j, int k) {
      return (std::uint64_t(std::uint32_t(i) & 0x1fffff) << 42) |
             (std::uint64_t(std::uint32_t(j) & 0x1fffff) << 21) | (std::uint32_t(k) & 0x1fffff);
    };
    std::unordered_set<std::uint64_t> occupied;
    for(std::size_t t = 0; t < surfaceTriangles; ++t) {
      int cl[3], ch[3];
      for(int k = 0; k < 3; ++k) {
        double least = std::numeric_limits<double>::infinity(), most = -least;
        for(int c = 0; c < 3; ++c) {
          least = std::min(least, in[3 * std::size_t(tri[3 * t + c]) + k]);
          most = std::max(most, in[3 * std::size_t(tri[3 * t + c]) + k]);
        }
        cl[k] = cellOf(least, k);
        ch[k] = cellOf(most, k);
      }
      for(int i = cl[0]; i <= ch[0]; ++i)
        for(int j = cl[1]; j <= ch[1]; ++j)
          for(int k = cl[2]; k <= ch[2]; ++k) occupied.insert(cellKey(i, j, k));
    }
    const auto cutters = [&](const Mesh &m, bool sheets) {
      std::vector<int> index(m.xyz.size() / 3, -1);
      for(std::size_t t = 0; t < m.triangles.size() / 3; ++t) {
        int b = -1;
        if(sheets) {
          b = branchOf(t);
          if(planeOf.count(b) || speck.count(b)) continue;
          bool inPlane = false;
          for(int s = 0; s < surfaceCount && !inPlane; ++s)
            inPlane = surfaces[s].planar && surfaces[s].triangles && lies(Frame(surfaces[s].plane), t);
          if(inPlane) continue;
        }
        bool near = true;
        int cl[3], ch[3];
        for(int k = 0; k < 3; ++k) {
          double least = std::numeric_limits<double>::infinity(), most = -least;
          for(int c = 0; c < 3; ++c) {
            least = std::min(least, m.xyz[3 * std::size_t(m.triangles[3 * t + c]) + k]);
            most = std::max(most, m.xyz[3 * std::size_t(m.triangles[3 * t + c]) + k]);
          }
          near = near && most >= lo[k] && least <= hi[k];
          cl[k] = cellOf(least, k);
          ch[k] = cellOf(most, k);
        }
        if(!near) continue;
        near = false;
        for(int i = cl[0]; i <= ch[0] && !near; ++i)
          for(int j = cl[1]; j <= ch[1] && !near; ++j)
            for(int k = cl[2]; k <= ch[2] && !near; ++k) near = occupied.count(cellKey(i, j, k)) != 0;
        if(!near) continue;
        for(int c = 0; c < 3; ++c) {
          const int vertex = m.triangles[3 * t + c];
          if(index[vertex] < 0) {
            index[vertex] = int(in.size() / 3);
            in.insert(in.end(), m.xyz.begin() + 3 * std::size_t(vertex),
                      m.xyz.begin() + 3 * std::size_t(vertex) + 3);
          }
          tri.push_back(index[vertex]);
          if(sheets) sheetVertex[index[vertex]] = vertex;
        }
        if(sheets) sheetTriangle[int(kind.size())] = int(t);
        kind.push_back(sheets ? Sheet : Skin);
        owner.push_back(b);
        ++out.cutters;
      }
      if(!sheets) return;
      // A sheet that stays ends a little short of (or beyond) the plane that
      // replaces the branch it ended on: the walls of the Doghouse 0.01 to 0.1
      // above the plane of its base, so that they share nothing with it. It is
      // prolonged there by a strip across the plane, from the edges of its
      // boundary that were a junction with that branch, along it (the
      // tolerance beyond the plane); the cut gives their common line, and the
      // part of the strip beyond the plane is left out (see stripOf).
      std::unordered_map<std::uint64_t, std::vector<std::size_t> > around;
      for(std::size_t t = 0; t < m.triangles.size() / 3; ++t)
        for(int c = 0; c < 3; ++c)
          around[edgeKey(m.triangles[3 * t + c], m.triangles[3 * t + (c + 1) % 3])].push_back(t);
      struct Edge {
        int a, b, surface;
        Vec out;
        double side, length;
        int branch;
      };
      std::vector<Edge> edges;
      for(const auto &e : around) {
        int sheet = -1, plane = -1;
        std::size_t of = 0, onSheet = 0;
        for(std::size_t t : e.second) {
          const int b = branchOf(t);
          if(speck.count(b)) continue;
          const auto p = planeOf.find(b);
          if(p != planeOf.end())
            plane = p->second;
          else {
            ++onSheet;
            sheet = b;
            of = t;
          }
        }
        // (an edge of the boundary of the sheet, on a branch replaced)
        if(onSheet != 1 || plane < 0 || !surfaces[plane].planar || !surfaces[plane].triangles) continue;
        const int a = int(e.first >> 32), b = int(e.first & 0xffffffffu);
        int c = -1;
        for(int k = 0; k < 3; ++k) {
          const int v = m.triangles[3 * of + k];
          if(v != a && v != b) c = v;
        }
        if(c < 0) continue;
        const Vec pa = point(m, a), pb = point(m, b), pc = point(m, c);
        const Vec normal = cross(sub(pb, pa), sub(pc, pa));
        Vec out = cross(sub(pb, pa), normal);
        const double length = norm(out);
        if(!(length > 0.)) continue;
        for(double &x : out) x /= length;
        if(dot(out, sub(pc, pa)) > 0.)
          for(double &x : out) x = -x;
        const Frame frame(surfaces[plane].plane);
        const double da = frame.distance(pa), db = frame.distance(pb);
        const double far = std::max(std::abs(da), std::abs(db));
        const double rate = dot(out, frame.n);
        const double side = std::abs(da) > std::abs(db) ? da : db;
        // near the plane, and going to it
        if(far > tolerance || !(side != 0.) || side * rate >= 0. || std::abs(rate) < .2) continue;
        edges.push_back({a, b, plane, out, side > 0. ? 1. : -1., std::min(reach, (far + tolerance) / std::abs(rate)),
                         sheet});
      }
      // the strips, a vertex across the plane for each vertex of their edges
      // (the directions of its edges averaged, the longest length)
      std::map<std::pair<int, int>, std::pair<Vec, double> > across; // (vertex, surface)
      for(const Edge &e : edges)
        for(int v : {e.a, e.b}) {
          auto &x = across[{v, e.surface}];
          for(int k = 0; k < 3; ++k) x.first[k] += e.out[k];
          x.second = std::max(x.second, e.length);
        }
      std::map<std::pair<int, int>, int> acrossIndex;
      const auto inIndex = [&](int v) {
        if(index[v] < 0) {
          index[v] = int(in.size() / 3);
          in.insert(in.end(), m.xyz.begin() + 3 * std::size_t(v), m.xyz.begin() + 3 * std::size_t(v) + 3);
          sheetVertex[index[v]] = v;
        }
        return index[v];
      };
      const auto acrossOf = [&](int v, int surface) {
        const auto found = acrossIndex.find({v, surface});
        if(found != acrossIndex.end()) return found->second;
        const auto &x = across[{v, surface}];
        Vec d = x.first;
        const double l = norm(d);
        if(l > 0.)
          for(double &y : d) y /= l;
        const Vec p = point(m, v);
        const int i = int(in.size() / 3);
        for(int k = 0; k < 3; ++k) in.push_back(p[k] + x.second * d[k]);
        acrossIndex[{v, surface}] = i;
        return i;
      };
      for(const Edge &e : edges) {
        const int a = inIndex(e.a), b = inIndex(e.b), a2 = acrossOf(e.a, e.surface),
                  b2 = acrossOf(e.b, e.surface);
        for(const std::array<int, 3> &t : {std::array<int, 3>{a, b, b2}, std::array<int, 3>{a, b2, a2}}) {
          stripOf[int(kind.size())] = {e.surface, e.side};
          tri.insert(tri.end(), t.begin(), t.end());
          kind.push_back(Sheet);
          owner.push_back(e.branch);
          ++out.cutters;
        }
      }
      out.prolonged += edges.size();
    };
    cutters(skin, false);
    cutters(mesh, true);
  }

  // One cut of it all.
  std::vector<double> oxyz;
  std::vector<int> otri, birth, inputVertex;
  {
    const auto before = std::chrono::steady_clock::now();
    if(!meshCoRefine(in, tri, oxyz, otri, birth, error, &inputVertex)) return false;
    out.cutSeconds =
      std::chrono::duration<double>(std::chrono::steady_clock::now() - before).count();
  }
  const std::size_t pieces = otri.size() / 3;
  const auto at = [&](int v) {
    return Vec{oxyz[3 * std::size_t(v)], oxyz[3 * std::size_t(v) + 1], oxyz[3 * std::size_t(v) + 2]};
  };
  const auto areaOf = [&](std::size_t t) {
    const Vec a = at(otri[3 * t]);
    return .5 * norm(cross(sub(at(otri[3 * t + 1]), a), sub(at(otri[3 * t + 2]), a)));
  };
  // The pieces of each surface, and on each of their edges what else is there.
  struct OnEdge {
    std::vector<int> pieces; // of the surfaces
    std::vector<int> sheets, fences; // their branches, their surfaces
    bool skin = false;
  };
  std::unordered_map<std::uint64_t, OnEdge> edges;
  std::vector<int> surfaceOf(pieces, -1), localOf(pieces, -1);
  for(std::size_t t = 0; t < pieces; ++t) {
    const int k = kind[birth[t]];
    if(k != Patch && k != Strip) continue;
    Surface &f = surfaces[owner[birth[t]]];
    surfaceOf[t] = owner[birth[t]];
    localOf[t] = int(f.pieces.size());
    f.pieces.push_back(int(t));
    for(int c = 0; c < 3; ++c)
      edges[edgeKey(otri[3 * t + c], otri[3 * t + (c + 1) % 3])].pieces.push_back(int(t));
  }
  for(std::size_t t = 0; t < pieces; ++t) {
    const int k = kind[birth[t]], o = owner[birth[t]];
    if(k == Patch || k == Strip) continue;
    for(int c = 0; c < 3; ++c) {
      const auto found = edges.find(edgeKey(otri[3 * t + c], otri[3 * t + (c + 1) % 3]));
      if(found == edges.end()) continue;
      OnEdge &e = found->second;
      if(k == Skin)
        e.skin = true;
      else {
        std::vector<int> &list = k == Sheet ? e.sheets : e.fences;
        if(std::find(list.begin(), list.end(), o) == list.end()) list.push_back(o);
      }
    }
  }
  // Where the triangles of the branches of each plane are, and the vertices
  // of each ribbon on the boundary of its branch and at its far end.
  std::vector<std::vector<int> > seedPiece(surfaceCount);
  std::vector<std::unordered_set<int> > onBoundary(surfaceCount), farEnd(surfaceCount);
  for(int s = 0; s < surfaceCount; ++s) {
    Surface &f = surfaces[s];
    if(f.planar) {
      const Frame frame(f.plane);
      std::vector<std::array<std::array<double, 2>, 3> > uv(f.pieces.size());
      std::vector<unsigned char> flat(f.pieces.size(), 0);
      for(std::size_t i = 0; i < f.pieces.size(); ++i) {
        for(int c = 0; c < 3; ++c) uv[i][c] = frame.uv(at(otri[3 * std::size_t(f.pieces[i]) + c]));
        flat[i] = !(std::abs((uv[i][1][0] - uv[i][0][0]) * (uv[i][2][1] - uv[i][0][1]) -
                             (uv[i][1][1] - uv[i][0][1]) * (uv[i][2][0] - uv[i][0][0])) > 0.);
      }
      seedPiece[s].assign(f.seeds.size(), -1);
      for(std::size_t q = 0; q < f.seeds.size(); ++q)
        for(std::size_t i = 0; i < f.pieces.size(); ++i)
          if(!flat[i] && inside(f.seeds[q], uv[i][0], uv[i][1], uv[i][2])) {
            seedPiece[s][q] = f.pieces[i];
            break;
          }
    }
    else {
      for(std::size_t i = 0; i < f.ribbon.source.size(); ++i) {
        if(f.ribbon.source[i] >= 0) onBoundary[s].insert(inputVertex[f.firstVertex + i]);
        if(f.ribbon.far[i]) farEnd[s].insert(inputVertex[f.firstVertex + i]);
      }
    }
  }
  // The kept pieces: first with every piece of the other surfaces as a cut,
  // then with those that were kept, until they stop changing.
  // (With more cuts a surface keeps less, so the sets of the rounds 0, 2, 4...
  // grow and those of the rounds 1, 3, 5... shrink, the first ones inside the
  // second ones: they meet, or end on two sets that give each other. The
  // smaller one is then taken: it never crosses a kept piece.)
  std::vector<unsigned char> kept(pieces, 1), next(pieces, 0), older;
  std::vector<int> pieceBranch(pieces, -1), nextBranch(pieces, -1);
  std::vector<ExtensionSurface> previousReport(surfaceCount);
  const int maxRounds = 12;
  bool done = false;
  for(out.rounds = 0; out.rounds < maxRounds && !done; ++out.rounds) {
    std::fill(next.begin(), next.end(), 0);
    std::fill(nextBranch.begin(), nextBranch.end(), -1);
    for(int s = 0; s < surfaceCount; ++s) {
      Surface &f = surfaces[s];
      std::vector<int> parent(f.pieces.size());
      std::iota(parent.begin(), parent.end(), 0);
      const auto find = [&](int i) {
        while(parent[i] != i) i = parent[i] = parent[parent[i]];
        return i;
      };
      f.report.reachesEnd = false;
      std::vector<unsigned char> border(f.pieces.size(), 0);
      for(std::size_t i = 0; i < f.pieces.size(); ++i) {
        const int t = f.pieces[i];
        for(int c = 0; c < 3; ++c) {
          const OnEdge &e = edges[edgeKey(otri[3 * std::size_t(t) + c], otri[3 * std::size_t(t) + (c + 1) % 3])];
          bool cut = e.skin;
          int same = 0, other = -1;
          for(int q : e.pieces) {
            if(surfaceOf[q] == s) {
              ++same;
              if(q != t) other = q;
            }
            else if(kept[q])
              cut = true;
          }
          for(int b : e.sheets) cut = cut || f.planar || b != f.branch;
          for(int o : e.fences) cut = cut || o == s;
          if(same == 1 && !cut) border[i] = 1; // the end of the surface itself
          if(same != 2 || cut || other < 0) continue;
          const int a = find(int(i)), b = find(localOf[other]);
          if(a != b) parent[std::max(a, b)] = std::min(a, b);
        }
      }
      std::map<int, std::map<int, int> > votes; // of the kept fragments: branch, triangles of it held
      if(f.planar) {
        for(std::size_t q = 0; q < f.seeds.size(); ++q)
          if(seedPiece[s][q] >= 0) ++votes[find(localOf[seedPiece[s][q]])][f.seedBranch[q]];
      }
      else {
        for(std::size_t i = 0; i < f.pieces.size(); ++i) {
          int on = 0;
          for(int c = 0; c < 3; ++c) on += onBoundary[s].count(otri[3 * std::size_t(f.pieces[i]) + c]) != 0;
          if(on >= 2) ++votes[find(int(i))][f.branch];
        }
      }
      std::set<int> all;
      for(std::size_t i = 0; i < f.pieces.size(); ++i) {
        const int fragment = find(int(i));
        all.insert(fragment);
        const auto found = votes.find(fragment);
        if(found == votes.end()) continue;
        const int t = f.pieces[i];
        next[t] = 1;
        int best = f.branch, most = -1;
        for(const auto &vote : found->second)
          if(vote.second > most) {
            most = vote.second;
            best = vote.first;
          }
        nextBranch[t] = best;
        if(f.planar)
          f.report.reachesEnd = f.report.reachesEnd || border[i];
        else
          for(int c = 0; c < 3; ++c)
            f.report.reachesEnd = f.report.reachesEnd || farEnd[s].count(otri[3 * std::size_t(t) + c]) != 0;
      }
      f.report.fragments = all.size();
      f.report.keptFragments = votes.size();
    }
    if(out.rounds > 0 && next == kept)
      out.settled = done = true;
    else if(out.rounds > 1 && next == older)
      done = true;
    if(done && !out.settled && out.rounds % 2 == 1) {
      // the last round gave the larger set again: the one before stays
      for(int s = 0; s < surfaceCount; ++s) surfaces[s].report = previousReport[s];
      continue;
    }
    for(int s = 0; s < surfaceCount; ++s) previousReport[s] = surfaces[s].report;
    older = kept;
    kept.swap(next);
    pieceBranch.swap(nextBranch);
  }

  // The MAT with its branches extended: the sheets that stay, then the kept
  // pieces, which share their vertices where they meet. A triangle of a sheet
  // that was cut is replaced by its pieces: the branches that stop on it share
  // their vertices with it (a junction along the line where they meet,
  // instead of a branch that stops on a sheet without being joined to it).
  std::set<int> replaced;
  for(int s = 0; s < surfaceCount; ++s) {
    Surface &f = surfaces[s];
    bool any = false;
    for(int t : f.pieces) any = any || kept[t];
    if(!any) continue;
    for(int b : f.members) {
      if(f.planar) replaced.insert(b);
      out.extended.push_back(b);
    }
  }
  std::vector<unsigned char> cutSheet(count, 0);
  for(std::size_t t = 0; t < pieces; ++t) {
    if(kind[birth[t]] != Sheet) continue;
    const auto found = sheetTriangle.find(birth[t]);
    if(found != sheetTriangle.end()) cutSheet[found->second] = 1;
  }
  out.result.xyz = mesh.xyz;
  for(std::size_t t = 0; t < count; ++t) {
    if(replaced.count(branchOf(t)) || cutSheet[t]) continue;
    for(int c = 0; c < 3; ++c) out.result.triangles.push_back(mesh.triangles[3 * t + c]);
    out.result.branch.push_back(branchOf(t));
    out.result.parent.push_back(t < mesh.parent.size() ? mesh.parent[t] : -1);
  }
  std::vector<int> added(oxyz.size() / 3, -1), shown(oxyz.size() / 3, -1);
  // the vertices of the sheets are theirs in the mesh, and their pieces go
  // in their place
  for(const auto &v : sheetVertex) added[inputVertex[v.first]] = v.second;
  // the pieces of the strips that prolong the sheets, on the side of the
  // plane the sheet is on
  for(std::size_t t = 0; t < pieces; ++t) {
    const auto found = stripOf.find(birth[t]);
    if(found == stripOf.end()) continue;
    const int *v = &otri[3 * t];
    if(v[0] == v[1] || v[1] == v[2] || v[0] == v[2] || !(areaOf(t) > 0.)) continue;
    const Frame frame(surfaces[found->second.surface].plane);
    const Vec g = {(oxyz[3 * std::size_t(v[0])] + oxyz[3 * std::size_t(v[1])] + oxyz[3 * std::size_t(v[2])]) / 3.,
                   (oxyz[3 * std::size_t(v[0]) + 1] + oxyz[3 * std::size_t(v[1]) + 1] + oxyz[3 * std::size_t(v[2]) + 1]) / 3.,
                   (oxyz[3 * std::size_t(v[0]) + 2] + oxyz[3 * std::size_t(v[1]) + 2] + oxyz[3 * std::size_t(v[2]) + 2]) / 3.};
    if(frame.distance(g) * found->second.side <= 0.) continue;
    for(int c = 0; c < 3; ++c) {
      if(added[v[c]] < 0) {
        added[v[c]] = int(out.result.xyz.size() / 3);
        out.result.xyz.insert(out.result.xyz.end(), oxyz.begin() + 3 * std::size_t(v[c]),
                              oxyz.begin() + 3 * std::size_t(v[c]) + 3);
      }
      out.result.triangles.push_back(added[v[c]]);
    }
    out.result.branch.push_back(owner[birth[t]]);
    out.result.parent.push_back(-1);
  }
  for(std::size_t t = 0; t < pieces; ++t) {
    if(kind[birth[t]] != Sheet) continue;
    const auto found = sheetTriangle.find(birth[t]);
    if(found == sheetTriangle.end() || replaced.count(branchOf(std::size_t(found->second)))) continue;
    const int *v = &otri[3 * t];
    if(v[0] == v[1] || v[1] == v[2] || v[0] == v[2] || !(areaOf(t) > 0.)) continue;
    for(int c = 0; c < 3; ++c) {
      if(added[v[c]] < 0) {
        added[v[c]] = int(out.result.xyz.size() / 3);
        out.result.xyz.insert(out.result.xyz.end(), oxyz.begin() + 3 * std::size_t(v[c]),
                              oxyz.begin() + 3 * std::size_t(v[c]) + 3);
      }
      out.result.triangles.push_back(added[v[c]]);
    }
    const std::size_t m = std::size_t(found->second);
    out.result.branch.push_back(branchOf(m));
    out.result.parent.push_back(m < mesh.parent.size() ? mesh.parent[m] : -1);
  }
  for(int s = 0; s < surfaceCount; ++s) {
    const Surface &f = surfaces[s];
    if(f.planar) continue;
    // the vertices of a ribbon on the boundary are those of its branch
    for(std::size_t i = 0; i < f.ribbon.source.size(); ++i)
      if(f.ribbon.source[i] >= 0) added[inputVertex[f.firstVertex + i]] = f.ribbon.source[i];
  }
  for(int s = 0; s < surfaceCount; ++s) {
    Surface &f = surfaces[s];
    for(int t : f.pieces) {
      const int *v = &otri[3 * std::size_t(t)];
      if(v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) continue;
      const double area = areaOf(std::size_t(t));
      if(!(area > 0.)) continue;
      for(int c = 0; c < 3; ++c) {
        if(shown[v[c]] < 0) {
          shown[v[c]] = int(out.pieces.xyz.size() / 3);
          out.pieces.xyz.insert(out.pieces.xyz.end(), oxyz.begin() + 3 * std::size_t(v[c]),
                                oxyz.begin() + 3 * std::size_t(v[c]) + 3);
        }
        out.pieces.triangles.push_back(shown[v[c]]);
      }
      out.pieces.branch.push_back(kept[t] ? pieceBranch[t] : -1);
      out.pieces.parent.push_back(-1);
      if(!kept[t]) continue;
      for(int c = 0; c < 3; ++c) {
        if(added[v[c]] < 0) {
          added[v[c]] = int(out.result.xyz.size() / 3);
          out.result.xyz.insert(out.result.xyz.end(), oxyz.begin() + 3 * std::size_t(v[c]),
                                oxyz.begin() + 3 * std::size_t(v[c]) + 3);
        }
        out.result.triangles.push_back(added[v[c]]);
      }
      out.result.branch.push_back(pieceBranch[t]);
      out.result.parent.push_back(-1);
      ++f.report.addedTriangles;
      f.report.addedArea += area;
    }
    out.report.push_back(f.report);
  }
  // A ribbon that runs back over the sheet of its branch (from a notch of its
  // boundary, which zigzags) gives, cut with it, the same triangles twice:
  // the first one is kept, that of the sheet (added first).
  {
    Mesh &r = out.result;
    // (the vertices at the same coordinates first made one, as the discrete
    // CAD modeler does: a piece of the cut and a vertex of the mesh can be
    // the same point under two numbers)
    {
      std::map<std::array<double, 3>, int> first;
      std::vector<int> same(r.xyz.size() / 3);
      for(std::size_t v = 0; v < same.size(); ++v)
        same[v] = first.insert({{r.xyz[3 * v], r.xyz[3 * v + 1], r.xyz[3 * v + 2]}, int(v)}).first->second;
      for(int &v : r.triangles) v = same[std::size_t(v)];
    }
    std::set<std::array<int, 3> > seen;
    std::size_t kept = 0;
    for(std::size_t t = 0; t < r.triangles.size() / 3; ++t) {
      std::array<int, 3> key = {r.triangles[3 * t], r.triangles[3 * t + 1], r.triangles[3 * t + 2]};
      std::sort(key.begin(), key.end());
      if(key[0] == key[1] || key[1] == key[2]) continue; // (made degenerate)
      if(!seen.insert(key).second) {
        ++out.duplicates;
        continue;
      }
      for(int c = 0; c < 3; ++c) r.triangles[3 * kept + c] = r.triangles[3 * t + c];
      r.branch[kept] = r.branch[t];
      r.parent[kept] = r.parent[t];
      ++kept;
    }
    r.triangles.resize(3 * kept);
    r.branch.resize(kept);
    r.parent.resize(kept);
  }
  // (the sheets kept whole, those lying in a plane, next to those cut: a node
  // of the cut on the edge of the one, not of the other)
  out.slits = closeSlits(out.result);
  out.seconds = std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
  return true;
}

std::size_t closeSlits(Mesh &mesh)
{
  std::size_t closed = 0;
  const auto at = [&](int v) { return point(mesh, v); };
  for(int pass = 0; pass < 10; ++pass) {
    const std::size_t count = mesh.triangles.size() / 3;
    std::unordered_map<std::uint64_t, std::vector<std::size_t> > uses;
    for(std::size_t t = 0; t < count; ++t)
      for(int c = 0; c < 3; ++c)
        uses[edgeKey(mesh.triangles[3 * t + c], mesh.triangles[3 * t + (c + 1) % 3])].push_back(t);
    std::unordered_map<int, std::vector<int> > boundary;
    for(const auto &u : uses)
      if(u.second.size() == 1) {
        const int a = int(u.first >> 32), b = int(u.first & 0xffffffffu);
        boundary[a].push_back(b);
        boundary[b].push_back(a);
      }
    std::vector<unsigned char> split(count, 0);
    std::size_t now = 0;
    for(const auto &u : uses) {
      if(u.second.size() != 1 || split[u.second[0]]) continue;
      const int a = int(u.first >> 32), b = int(u.first & 0xffffffffu);
      const Vec pa = at(a), ab = sub(at(b), pa);
      const double l2 = dot(ab, ab);
      if(!(l2 > 0.)) continue;
      // the nodes on the edge, from a to b along other edges of one triangle
      const auto along = [&](int v, double &s) {
        const Vec d = sub(at(v), pa);
        s = dot(d, ab) / l2;
        const Vec h = {d[0] - s * ab[0], d[1] - s * ab[1], d[2] - s * ab[2]};
        // (within a hundredth of its length: a slit along a circle cut, its
        // nodes on the arc, the sagitta L^2 / 8R from the chord)
        return s > 0. && s < 1. && dot(h, h) <= 1e-4 * l2;
      };
      std::vector<int> chain(1, a);
      double last = 0.;
      bool reached = false;
      for(int step = 0; step < 64 && !reached; ++step) {
        int next = -1;
        double best = 2.;
        for(int w : boundary[chain.back()]) {
          if(w == b && chain.size() > 1) {
            reached = true;
            break;
          }
          double sw;
          if(w != a && w != b && along(w, sw) && sw > last && sw < best) {
            best = sw;
            next = w;
          }
        }
        if(reached || next < 0) break;
        chain.push_back(next);
        last = best;
      }
      if(!reached) continue;
      // the triangle along the edge, as a fan from its third node
      const std::size_t t = u.second[0];
      int *w = &mesh.triangles[3 * t];
      int i = 0;
      while(i < 3 && !((w[i] == a && w[(i + 1) % 3] == b) || (w[i] == b && w[(i + 1) % 3] == a))) ++i;
      if(i == 3) continue;
      const int from = w[i], to = w[(i + 1) % 3], d = w[(i + 2) % 3];
      if(from == b) std::reverse(chain.begin() + 1, chain.end());
      chain.push_back(to);
      chain[0] = from;
      split[t] = 1;
      const int branch = t < mesh.branch.size() ? mesh.branch[t] : 0;
      const int parent = t < mesh.parent.size() ? mesh.parent[t] : -1;
      w[0] = chain[0];
      w[1] = chain[1];
      w[2] = d;
      for(std::size_t k = 1; k + 1 < chain.size(); ++k) {
        mesh.triangles.insert(mesh.triangles.end(), {chain[k], chain[k + 1], d});
        mesh.branch.push_back(branch);
        mesh.parent.push_back(parent);
      }
      ++now;
    }
    closed += now;
    if(!now) break;
  }
  return closed;
}

// ---------------------------------------------------------------------------
// The mid-surface as a mesh with its branches and its classified edges.

bool writeClassifiedMesh(const Mesh &mesh, const Mesh &skin, const std::string &filename,
                         ClassifiedEdges &counts, std::string &error,
                         const std::vector<double> *nodeData, const std::string &dataName)
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
  // the values at the nodes written, the finite ones
  if(nodeData && nodeData->size() == node.size()) {
    std::size_t finite = 0;
    for(std::size_t v = 0; v < node.size(); ++v) finite += node[v] && std::isfinite((*nodeData)[v]);
    f << "$NodeData\n1\n\"" << dataName << "\"\n1\n0\n3\n0\n1\n" << finite << '\n';
    for(std::size_t v = 0; v < node.size(); ++v)
      if(node[v] && std::isfinite((*nodeData)[v])) f << node[v] << ' ' << (*nodeData)[v] << '\n';
    f << "$EndNodeData\n";
  }
  if(!f) {
    error = "Failed to write " + filename;
    return false;
  }
  return true;
}

} // namespace matgmsh_native
