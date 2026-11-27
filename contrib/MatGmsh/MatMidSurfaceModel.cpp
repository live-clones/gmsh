// The mid-surface as a discrete model of Gmsh, meshed by Gmsh (see
// buildMidSurfaceModel in MatPipeline.h).
#include "MatPipeline.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <unordered_map>
#include "Context.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "SVector3.h"
#include "SPoint3KDTree.h"
#include "DiscreteCADModeler.h"

namespace matgmsh_native {

namespace {

double since(const std::chrono::steady_clock::time_point &start)
{
  return std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
}

bool inList(const GModel *m)
{
  return m && std::find(GModel::list.begin(), GModel::list.end(), m) != GModel::list.end();
}

// the current model and the visibility of the models, put back on exit
struct KeepCurrent {
  GModel *current;
  std::vector<std::pair<GModel *, char> > visible;
  KeepCurrent() : current(GModel::current())
  {
    for(GModel *m : GModel::list) visible.push_back({m, m->getVisibility()});
  }
  ~KeepCurrent()
  {
    if(inList(current)) GModel::setCurrent(current);
    for(auto &v : visible)
      if(inList(v.first)) v.first->setVisibility(v.second);
  }
};

// a point by its coordinates, exactly
struct Point {
  std::array<std::uint64_t, 3> bits;
  Point(double x, double y, double z)
  {
    const double c[3] = {x, y, z};
    for(int k = 0; k < 3; ++k) std::memcpy(&bits[k], &c[k], sizeof(double));
  }
  bool operator==(const Point &p) const { return bits == p.bits; }
  bool operator<(const Point &p) const { return bits < p.bits; }
};
struct PointHash {
  std::size_t operator()(const Point &p) const
  {
    std::uint64_t h = 1469598103934665603ull;
    for(std::uint64_t b : p.bits) h = (h ^ b) * 1099511628211ull;
    return std::size_t(h ^ (h >> 29));
  }
};
// a triangle by its three points, in order
struct Triangle {
  std::array<Point, 3> p;
  Triangle(Point a, Point b, Point c) : p{{a, b, c}} { std::sort(p.begin(), p.end()); }
  bool operator==(const Triangle &t) const { return p == t.p; }
};
struct TriangleHash {
  std::size_t operator()(const Triangle &t) const
  {
    PointHash h;
    return h(t.p[0]) ^ (h(t.p[1]) * 31) ^ (h(t.p[2]) * 1009);
  }
};

} // namespace

bool buildMidSurfaceModel(const Mesh &mesh, const std::string &name, double angle,
                          double curveAngle, double minArea, MidSurfaceModel &out,
                          std::string &error)
{
  const auto start = std::chrono::steady_clock::now();
  out = MidSurfaceModel{};
  error.clear();
  const std::size_t count = mesh.triangles.size() / 3, nodes = mesh.xyz.size() / 3;
  if(!count) {
    error = "The mid-surface has no triangle";
    return false;
  }
  for(int n : mesh.triangles)
    if(n < 0 || std::size_t(n) >= nodes) {
      error = "A triangle of the mid-surface has an unknown node";
      return false;
    }
  // The triangles on the nodes of the modeler: the nodes at the same
  // coordinates merged, and the triangles then degenerate left out, as
  // DiscreteCAD_Internals::addTriangulation does.
  std::vector<std::size_t> triangles;
  std::vector<int> pieces;
  std::set<int> branches;
  {
    std::unordered_map<Point, std::size_t, PointHash> first;
    std::vector<std::size_t> same(nodes);
    for(std::size_t n = 0; n < nodes; ++n)
      same[n] = first.insert({Point(mesh.xyz[3 * n], mesh.xyz[3 * n + 1], mesh.xyz[3 * n + 2]), n})
                  .first->second;
    for(std::size_t t = 0; t < count; ++t) {
      const std::size_t a = same[mesh.triangles[3 * t]], b = same[mesh.triangles[3 * t + 1]],
                        c = same[mesh.triangles[3 * t + 2]];
      if(a == b || b == c || c == a) continue;
      triangles.insert(triangles.end(), {a, b, c});
      pieces.push_back(t < mesh.branch.size() ? mesh.branch[t] : 0);
      branches.insert(pieces.back());
    }
  }
  out.branches = branches.size();
  // The slits closed: a hole bounded by three edges of one triangle each,
  // not a triangle, whose third node is on the longest edge (within a
  // hundredth of its length; the cut of the extension leaves some, 1e-14
  // wide), the triangle along that edge split at that node. Meshed as it is,
  // such a hole is a closed curve, whose 1D mesh has at least three elements
  // on its three sides, one of them as short as the slit is narrow, and the
  // surface takes that size.
  {
    auto key = [](std::size_t a, std::size_t b) {
      if(a > b) std::swap(a, b);
      return (std::uint64_t(a) << 32) | std::uint64_t(b);
    };
    auto at = [&](std::size_t n) {
      return std::array<double, 3>{mesh.xyz[3 * n], mesh.xyz[3 * n + 1], mesh.xyz[3 * n + 2]};
    };
    for(int pass = 0; pass < 10; ++pass) {
      std::unordered_map<std::uint64_t, std::vector<std::size_t> > uses;
      std::set<std::array<std::size_t, 3> > existing;
      for(std::size_t t = 0; t < triangles.size() / 3; ++t) {
        std::array<std::size_t, 3> v = {triangles[3 * t], triangles[3 * t + 1], triangles[3 * t + 2]};
        for(int k = 0; k < 3; ++k) uses[key(v[k], v[(k + 1) % 3])].push_back(t);
        std::sort(v.begin(), v.end());
        existing.insert(v);
      }
      std::map<std::size_t, std::set<std::size_t> > boundary;
      for(const auto &u : uses)
        if(u.second.size() == 1) {
          const std::size_t a = u.first >> 32, b = u.first & 0xffffffffu;
          boundary[a].insert(b);
          boundary[b].insert(a);
        }
      std::set<std::size_t> splitThisPass;
      std::size_t split = 0;
      for(const auto &na : boundary) {
        const std::size_t a = na.first;
        for(std::size_t b : na.second) {
          if(b < a) continue;
          for(std::size_t c : boundary[b]) {
            if(c < b || !na.second.count(c)) continue;
            if(existing.count({a, b, c})) continue;
            // the longest edge (p, q), the node r of the hole off it
            std::array<std::size_t, 3> v = {a, b, c};
            double longest = -1.;
            int e = 0;
            for(int k = 0; k < 3; ++k) {
              const auto x = at(v[k]), y = at(v[(k + 1) % 3]);
              const double l = std::sqrt((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]) +
                                         (x[2] - y[2]) * (x[2] - y[2]));
              if(l > longest) {
                longest = l;
                e = k;
              }
            }
            const std::size_t p = v[e], q = v[(e + 1) % 3], r = v[(e + 2) % 3];
            const auto x = at(p), y = at(q), z = at(r);
            double pq[3], pr[3], s = 0., l2 = 0.;
            for(int k = 0; k < 3; ++k) {
              pq[k] = y[k] - x[k];
              pr[k] = z[k] - x[k];
              s += pq[k] * pr[k];
              l2 += pq[k] * pq[k];
            }
            if(!(l2 > 0.)) continue;
            s /= l2;
            double h2 = 0.;
            for(int k = 0; k < 3; ++k) h2 += (pr[k] - s * pq[k]) * (pr[k] - s * pq[k]);
            if(!(s > 0. && s < 1.) || h2 > 1e-4 * l2) continue;
            const auto along = uses.find(key(p, q));
            if(along == uses.end() || along->second.size() != 1) continue;
            const std::size_t t = along->second[0];
            if(!splitThisPass.insert(t).second) continue;
            std::size_t *w = &triangles[3 * t];
            int i = 0;
            while(i < 3 && !((w[i] == p && w[(i + 1) % 3] == q) || (w[i] == q && w[(i + 1) % 3] == p))) ++i;
            if(i == 3) continue;
            // (w[i], r, d) in its place and (r, w[i + 1], d) added: same orientation
            const std::size_t from = w[i], to = w[(i + 1) % 3], d = w[(i + 2) % 3];
            w[0] = from;
            w[1] = r;
            w[2] = d;
            triangles.insert(triangles.end(), {r, to, d});
            pieces.push_back(pieces[t]);
            ++split;
          }
        }
      }
      out.slits += split;
      if(!split) break;
    }
  }
  if(out.slits)
    Msg::Info("Mid-surface model: %zu slits closed (a node on the edge of the "
              "triangle across a hole of zero area: the triangle split at it)",
              out.slits);
  // The holes of less than minArea in a piece larger than ten times their
  // area filled (a fan of triangles from one of their nodes): the cut of the
  // extension leaves some, a few micrometres wide, whose 1D mesh would have
  // elements as small, and the surface that size around them.
  if(minArea > 0.) {
    auto key = [](std::size_t a, std::size_t b) {
      if(a > b) std::swap(a, b);
      return (std::uint64_t(a) << 32) | std::uint64_t(b);
    };
    const std::size_t nt = triangles.size() / 3;
    std::unordered_map<std::uint64_t, std::vector<std::size_t> > uses;
    for(std::size_t t = 0; t < nt; ++t)
      for(int k = 0; k < 3; ++k) uses[key(triangles[3 * t + k], triangles[3 * t + (k + 1) % 3])].push_back(t);
    // the pieces (triangles of a branch connected across edges of two
    // triangles) and their areas
    auto area = [&](std::size_t a, std::size_t b, std::size_t c) {
      const double *x = &mesh.xyz[3 * a], *y = &mesh.xyz[3 * b], *z = &mesh.xyz[3 * c];
      const double u[3] = {y[0] - x[0], y[1] - x[1], y[2] - x[2]},
                   v[3] = {z[0] - x[0], z[1] - x[1], z[2] - x[2]};
      const double n[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]};
      return .5 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    };
    std::vector<int> piece(nt, -1);
    std::vector<double> pieceArea;
    for(std::size_t s0 = 0; s0 < nt; ++s0) {
      if(piece[s0] >= 0) continue;
      const int p = int(pieceArea.size());
      pieceArea.push_back(0.);
      std::vector<std::size_t> stack(1, s0);
      piece[s0] = p;
      while(!stack.empty()) {
        const std::size_t t = stack.back();
        stack.pop_back();
        pieceArea[p] += area(triangles[3 * t], triangles[3 * t + 1], triangles[3 * t + 2]);
        for(int k = 0; k < 3; ++k) {
          const auto &u = uses[key(triangles[3 * t + k], triangles[3 * t + (k + 1) % 3])];
          if(u.size() != 2) continue;
          for(std::size_t o : u)
            if(piece[o] < 0 && pieces[o] == pieces[t]) {
              piece[o] = p;
              stack.push_back(o);
            }
        }
      }
    }
    // the boundary edges at each node, and the loops through nodes of two of
    // them (the triangles of the MAT are not oriented alike)
    std::unordered_map<std::size_t, std::vector<std::pair<std::size_t, std::size_t> > > around;
    for(const auto &u : uses) {
      if(u.second.size() != 1) continue;
      const std::size_t a = u.first >> 32, b = u.first & 0xffffffffu;
      around[a].push_back({b, u.second[0]});
      around[b].push_back({a, u.second[0]});
    }
    std::set<std::size_t> visited;
    std::size_t filled = 0;
    for(const auto &o : around) {
      const std::size_t start = o.first;
      if(visited.count(start) || o.second.size() != 2) continue;
      std::vector<std::size_t> loop(1, start);
      visited.insert(start);
      const std::size_t t0 = o.second[0].second;
      std::size_t previous = start, cur = o.second[0].first;
      bool simple = true;
      while(cur != start) {
        auto it = around.find(cur);
        if(it == around.end() || it->second.size() != 2 || visited.count(cur) || loop.size() > 64) {
          simple = false;
          break;
        }
        visited.insert(cur);
        loop.push_back(cur);
        const std::size_t next =
          it->second[0].first == previous ? it->second[1].first : it->second[0].first;
        previous = cur;
        cur = next;
      }
      if(!simple || loop.size() < 3) continue;
      // its area (of the fan), and the piece it is a hole of
      double area0 = 0.;
      for(std::size_t i = 1; i + 1 < loop.size(); ++i) area0 += area(loop[0], loop[i], loop[i + 1]);
      const int p = piece[t0];
      if(!(area0 < minArea) || !(pieceArea[p] > 10. * area0 + minArea)) continue;
      for(std::size_t i = 1; i + 1 < loop.size(); ++i) {
        triangles.insert(triangles.end(), {loop[0], loop[i], loop[i + 1]});
        pieces.push_back(pieces[t0]);
      }
      ++filled;
    }
    out.holes = filled;
    if(filled)
      Msg::Info("Mid-surface model: %zu holes of less than %g filled", filled, minArea);
  }

  KeepCurrent keep;
  GModel *m = new GModel(name);
  GModel::setCurrent(m); // (the nodes are numbered in the current model)
  bool ok = false;
  try {
    m->createDiscreteCADInternals();
    DiscreteCAD_Internals *cad = m->getDiscreteCADInternals();
    std::vector<std::pair<int, int> > outDimTags;
    ok = cad->addTriangulation(mesh.xyz, triangles, pieces, angle, curveAngle, -1., outDimTags);
    if(ok) cad->synchronize(m);
    // the surfaces under minArea (specks: folds and needles left by the cut
    // of the extension) removed, with their curves and points that no other
    // surface uses
    if(ok && minArea > 0.) {
      std::vector<std::pair<int, int> > specks;
      for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
        const std::vector<SPoint3> &x = (*it)->stl_vertices_xyz;
        const std::vector<int> &tri = (*it)->stl_triangles;
        double area = 0.;
        for(std::size_t i = 0; i + 2 < tri.size(); i += 3) {
          const SVector3 u(x[tri[i]], x[tri[i + 1]]), v(x[tri[i]], x[tri[i + 2]]);
          area += .5 * crossprod(u, v).norm();
        }
        if(area < minArea) {
          specks.push_back({2, (*it)->tag()});
          out.speckArea += area;
        }
      }
      if(!specks.empty() && specks.size() < m->getNumFaces()) {
        out.specks = specks.size();
        cad->remove(specks, true);
        cad->synchronize(m);
      }
    }
  }
  catch(const std::exception &e) {
    error = e.what();
    ok = false;
  }
  if(!ok || !m->getNumFaces()) {
    if(error.empty())
      error = "The discrete CAD modeler could not build the topology of the mid-surface "
              "(see the messages)";
    delete m;
    return false;
  }

  // The branch of each surface: that of its triangles found among those of
  // the mesh (by their coordinates; the nodes moved onto the intersection of
  // two analytic surfaces are not found), the most frequent one, or else the
  // most frequent branch of its nodes.
  std::unordered_map<Triangle, int, TriangleHash> branchOfTriangle;
  std::unordered_map<Point, std::vector<int>, PointHash> branchesAt;
  auto point = [&](std::size_t n) {
    return Point(mesh.xyz[3 * n], mesh.xyz[3 * n + 1], mesh.xyz[3 * n + 2]);
  };
  for(std::size_t t = 0; t < triangles.size() / 3; ++t) {
    branchOfTriangle.insert(
      {Triangle(point(triangles[3 * t]), point(triangles[3 * t + 1]), point(triangles[3 * t + 2])),
       pieces[t]});
    for(int k = 0; k < 3; ++k) {
      std::vector<int> &b = branchesAt[point(triangles[3 * t + k])];
      if(std::find(b.begin(), b.end(), pieces[t]) == b.end()) b.push_back(pieces[t]);
    }
  }
  std::map<int, std::vector<int> > surfacesOf;
  std::map<GFace *, int> branchOf;
  std::size_t unknown = 0;
  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *gf = *it;
    const std::vector<SPoint3> &xyz = gf->stl_vertices_xyz;
    const std::vector<int> &tri = gf->stl_triangles;
    auto at = [&](int i) { return Point(xyz[i].x(), xyz[i].y(), xyz[i].z()); };
    std::map<int, std::size_t> votes;
    for(std::size_t i = 0; i + 2 < tri.size(); i += 3) {
      auto found = branchOfTriangle.find(Triangle(at(tri[i]), at(tri[i + 1]), at(tri[i + 2])));
      if(found != branchOfTriangle.end()) ++votes[found->second];
    }
    if(votes.empty())
      for(std::size_t i = 0; i < xyz.size(); ++i) {
        auto found = branchesAt.find(at(int(i)));
        if(found == branchesAt.end()) continue;
        for(int b : found->second) ++votes[b];
      }
    gf->setMeshingAlgo(ALGO_2D_FRONTAL_SCAFFOLD);
    if(votes.empty()) {
      ++unknown;
      continue;
    }
    const int b = std::max_element(votes.begin(), votes.end(),
                                   [](const std::pair<const int, std::size_t> &x,
                                      const std::pair<const int, std::size_t> &y) {
                                     return x.second < y.second;
                                   })->first;
    surfacesOf[b].push_back(gf->tag());
    branchOf[gf] = b;
    out.branchOfSurface[gf->tag()] = b;
  }
  if(unknown)
    Msg::Warning("Mid-surface model: %zu surfaces of no known branch (in no physical group)",
                 unknown);
  for(const auto &s : surfacesOf) {
    m->addPhysicalGroup(2, s.first + 1, s.second);
    m->setPhysicalName("branch " + std::to_string(s.first), 2, s.first + 1);
  }
  // the curves between surfaces of different branches, or of more than two
  // surfaces, and those of one surface (not a seam of it)
  std::vector<int> junctions, boundaries;
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    GEdge *ge = *it;
    const std::vector<GFace *> faces = ge->faces();
    std::set<int> of;
    for(GFace *gf : faces) of.insert(branchOf.count(gf) ? branchOf[gf] : -1);
    if(faces.size() > 2 || of.size() > 1)
      junctions.push_back(ge->tag());
    else if(faces.size() == 1 && !ge->isSeam(faces[0]))
      boundaries.push_back(ge->tag());
  }
  if(!junctions.empty()) {
    m->addPhysicalGroup(1, 1, junctions);
    m->setPhysicalName("junction", 1, 1);
  }
  if(!boundaries.empty()) {
    m->addPhysicalGroup(1, 2, boundaries);
    m->setPhysicalName("boundary", 1, 2);
  }
  out.model = m;
  out.surfaces = m->getNumFaces();
  out.curves = m->getNumEdges();
  out.points = m->getNumVertices();
  out.volumes = m->getNumRegions();
  out.junctions = junctions.size();
  out.boundaries = boundaries.size();
  m->setVisibility(0);
  out.buildSeconds = since(start);
  return true;
}

void localThickness(const Mesh &original, const std::vector<double> &xyz,
                    const std::vector<int> &branch, std::vector<double> &thickness)
{
  const std::size_t points = xyz.size() / 3, nodes = original.xyz.size() / 3;
  thickness.assign(points, std::numeric_limits<double>::quiet_NaN());
  if(original.radius.size() != nodes || original.triangles.empty()) return;
  // the nodes of each branch with a radius, and of all of them, in kd-trees
  struct Search {
    SPoint3Search tree;
    std::vector<std::size_t> node;
  };
  std::map<int, std::unique_ptr<Search> > of;
  Search all;
  const std::size_t count = original.triangles.size() / 3;
  std::vector<std::set<int> > branchesAt(nodes);
  for(std::size_t t = 0; t < count; ++t)
    for(int k = 0; k < 3; ++k)
      branchesAt[original.triangles[3 * t + k]].insert(t < original.branch.size() ? original.branch[t] : 0);
  auto add = [&](Search &s, std::size_t n) {
    s.tree.points().push_back(SPoint3(original.xyz[3 * n], original.xyz[3 * n + 1], original.xyz[3 * n + 2]));
    s.node.push_back(n);
  };
  for(std::size_t n = 0; n < nodes; ++n) {
    if(branchesAt[n].empty() || !std::isfinite(original.radius[n])) continue;
    add(all, n);
    for(int b : branchesAt[n]) {
      std::unique_ptr<Search> &s = of[b];
      if(!s) s.reset(new Search);
      add(*s, n);
    }
  }
  if(!all.node.size()) return;
  all.tree.build();
  for(auto &s : of) s.second->tree.build();
  for(std::size_t i = 0; i < points; ++i) {
    auto it = of.find(i < branch.size() ? branch[i] : 0);
    const Search &s = it != of.end() ? *it->second : all;
    std::size_t found;
    double d2;
    if(s.tree.nearest(SPoint3(xyz[3 * i], xyz[3 * i + 1], xyz[3 * i + 2]), 1, &found, &d2))
      thickness[i] = 2. * original.radius[s.node[found]];
  }
}

std::vector<double> localThickness(const Mesh &mesh, const Mesh &original)
{
  // the branch of each node: that of its first triangle
  std::vector<int> branch(mesh.xyz.size() / 3, 0);
  std::vector<char> seen(branch.size(), 0);
  for(std::size_t t = 0; t < mesh.triangles.size() / 3; ++t)
    for(int k = 0; k < 3; ++k) {
      const int n = mesh.triangles[3 * t + k];
      if(n < 0 || std::size_t(n) >= branch.size() || seen[n]) continue;
      seen[n] = 1;
      branch[n] = t < mesh.branch.size() ? mesh.branch[t] : 0;
    }
  std::vector<double> thickness;
  localThickness(original, mesh.xyz, branch, thickness);
  for(std::size_t n = 0; n < seen.size(); ++n)
    if(!seen[n]) thickness[n] = std::numeric_limits<double>::quiet_NaN();
  return thickness;
}

void midSurfaceThickness(const MidSurfaceModel &m, const Mesh &original,
                         std::vector<std::size_t> &nodes, std::vector<double> &thickness)
{
  nodes.clear();
  thickness.clear();
  if(!inList(m.model)) return;
  std::vector<double> xyz;
  std::vector<int> branch;
  std::set<MVertex *> seen;
  for(auto it = m.model->firstFace(); it != m.model->lastFace(); ++it) {
    auto b = m.branchOfSurface.find((*it)->tag());
    for(MTriangle *t : (*it)->triangles)
      for(int k = 0; k < 3; ++k) {
        MVertex *v = t->getVertex(k);
        if(!seen.insert(v).second) continue;
        nodes.push_back(v->getNum());
        xyz.insert(xyz.end(), {v->x(), v->y(), v->z()});
        branch.push_back(b != m.branchOfSurface.end() ? b->second : -1);
      }
  }
  localThickness(original, xyz, branch, thickness);
}

bool meshMidSurfaceModel(MidSurfaceModel &m, double size, std::string &error)
{
  error.clear();
  if(!inList(m.model)) {
    error = "The mid-surface model is gone";
    return false;
  }
  const auto start = std::chrono::steady_clock::now();
  KeepCurrent keep;
  GModel::setCurrent(m.model);
  contextMeshOptions &o = CTX::instance()->mesh;
  const double lcMax = o.lcMax;
  if(size > 0.) o.lcMax = size;
  bool ok = true;
  try {
    m.model->deleteMesh();
    // (nested: the caller may hold the lock on the models)
    ok = m.model->mesh(2, true);
  }
  catch(const std::exception &e) {
    error = e.what();
    ok = false;
  }
  o.lcMax = lcMax;
  CTX::instance()->meshChanged();
  m.triangles = m.failed = 0;
  for(auto it = m.model->firstFace(); it != m.model->lastFace(); ++it) {
    m.triangles += (*it)->triangles.size();
    m.failed += (*it)->triangles.empty();
  }
  m.nodes = m.model->getNumMeshVertices();
  m.meshSeconds = since(start);
  if(!ok && error.empty()) error = "Gmsh could not mesh the mid-surface";
  return ok;
}

bool writeMidSurfaceMesh(const MidSurfaceModel &m, const std::string &filename,
                         std::string &error, const std::vector<std::size_t> *nodes,
                         const std::vector<double> *values, const std::string &name)
{
  error.clear();
  if(!inList(m.model)) {
    error = "The mid-surface model is gone";
    return false;
  }
  KeepCurrent keep;
  GModel::setCurrent(m.model);
  if(!m.model->writeMSH(filename, 4.1, false, false)) {
    error = "Cannot write " + filename;
    return false;
  }
  if(nodes && values && nodes->size() == values->size() && !nodes->empty()) {
    FILE *fp = std::fopen(filename.c_str(), "a");
    if(!fp) {
      error = "Cannot write " + filename;
      return false;
    }
    std::fprintf(fp, "$NodeData\n1\n\"%s\"\n1\n0\n3\n0\n1\n%zu\n", name.c_str(), nodes->size());
    for(std::size_t i = 0; i < nodes->size(); ++i)
      std::fprintf(fp, "%zu %.17g\n", (*nodes)[i], (*values)[i]);
    std::fprintf(fp, "$EndNodeData\n");
    std::fclose(fp);
  }
  return true;
}

} // namespace matgmsh_native
