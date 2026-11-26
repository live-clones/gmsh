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
  int fragmentAt(const std::array<double, 2> &p) const
  {
    for(std::size_t i = 0; i < pieces.size(); ++i) {
      const int *t = piece(i);
      if(inside(p, uv[t[0]], uv[t[1]], uv[t[2]])) return fragment[i];
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
    const std::size_t step = std::max<std::size_t>(1, own.size() / 64);
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
  PlaneCut cut;
  if(!cut.compute(frame, lo, hi, 1, 1, cutterXyz, cutterTriangles, error)) return false;
  std::map<int, std::size_t> kept = cut.holding(seeds);
  if(kept.empty()) {
    error = "No fragment of the plane holds a triangle of the branch";
    return false;
  }
  // The rectangle is far outside the skin: a kept fragment that touches it is
  // not closed by the skin.
  for(std::size_t i = 0; i < cut.pieces.size(); ++i)
    if(kept.count(cut.fragment[i]) && cut.onRectangle(i)) out.reachesFrame = true;

  // The branches lying in the plane inside a kept fragment are the same wall:
  // they go with the branch.
  {
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
    // direction of the extension: tangent x normal, away from the branch
    std::vector<Vec> direction(n);
    double outward = 0.;
    for(int i = 0; i < n; ++i) {
      Vec tangent = sub(x[at(i + 2)], x[at(i - 2)]);
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
    // the ribbon: u along the boundary, v away from it
    const int first = int(out.mesh.xyz.size() / 3);
    double u = 0.;
    for(int i = 0; i < n; ++i) {
      if(i) u += norm(sub(x[chain[i]], x[chain[i - 1]]));
      for(int j = 0; j <= layers; ++j) {
        const double v = length * j / layers;
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
  cutters(mesh, true);

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
  // fragment that holds the far end of the ribbon met nothing.
  std::unordered_set<int> onBoundary, farEnd;
  for(std::size_t i = 0; i < ribbon.v.size(); ++i) {
    if(ribbon.v[i] == 0.) onBoundary.insert(inputVertex[i]);
    if(i + 1 == ribbon.v.size() || ribbon.v[i + 1] == 0.) farEnd.insert(inputVertex[i]);
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

} // namespace matgmsh_native
