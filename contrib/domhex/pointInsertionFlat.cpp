// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "pointInsertionFlat.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

#include "GmshConfig.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "MTetrahedron.h"
#include "BackgroundMeshTools.h"
#include "meshGRegionDelaunay.h"
#include "MVertex.h"
#include "meshGRegion.h"
#include "directions3D.h"
#include "Context.h"
#include "Geo.h"
#include "gmshVertex.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "OS.h"
#include "robustPredicates.h"
#include "meshGRegionHxt.h"
#include "meshGRegionParallelDelaunay.h"

namespace {

// k1*h is the minimal distance between two accepted points, k2*h the
// minimal distance to the boundary (unused here, see below -- disabled
// upstream too).
const double k1 = 0.61;

// One accepted (or candidate) point, everything a plain double/int: no
// Node/MVertex/GVertex allocated per point during the fill itself.
struct FlatPoint {
  double x, y, z;
  double h;
  // the local frame, row-major 3x3 (m[0..2]=row1, m[3..5]=row2, m[6..8]=row3)
  double m[9];
  int layer;
  int limit; // -1: unbounded
  int tet; // a tet of the region holding the point (-1: unknown)
  MVertex *v; // the boundary vertex of a seed, null for the spawns
};

// Point location in the region's tets by walking from a nearby tet across
// the face opposite to its most negative barycentric coordinate. The spawns
// land a distance h from their parent, a few tets away, whereas the octree
// returns hundreds of overlapping boxes in the long tets of the boundary-only
// Delaunay mesh of a thin region (most of the fill time in a spherical
// shell). A tet is accepted with the octree's own test (xyz2uvw and isInside
// with the same tolerance), so the walk finds a tet exactly when the octree
// does, except when it leaves a non-convex region or meets a flat tet: it
// then gives up and the caller falls back to the octree.
class TetWalker {
public:
  TetWalker(const std::vector<MTetrahedron *> &tets, double tol)
    : _tets(tets), _tol(tol), _neighbors(4 * tets.size(), -1),
      _flat(tets.size(), false)
  {
    struct Facet {
      std::array<std::size_t, 3> key;
      int tetFace;
    };
    std::vector<Facet> facets(4 * tets.size());
    for(std::size_t t = 0; t < tets.size(); t++) {
      double mat[3][3];
      tets[t]->getMat(mat);
      _flat[t] = (det3x3(mat) == 0.);
      for(int i = 0; i < 4; i++) {
        Facet &f = facets[4 * t + i];
        for(int j = 0, k = 0; j < 4; j++)
          if(j != i) f.key[k++] = tets[t]->getVertex(j)->getNum();
        std::sort(f.key.begin(), f.key.end());
        f.tetFace = (int)(4 * t + i);
      }
      for(int i = 0; i < 4; i++) {
        MVertex *v = tets[t]->getVertex(i);
        if(!_tetOf.count(v)) _tetOf[v] = (int)t;
      }
    }
    std::sort(facets.begin(), facets.end(),
              [](const Facet &a, const Facet &b) {
                return a.key != b.key ? a.key < b.key : a.tetFace < b.tetFace;
              });
    for(std::size_t i = 0; i + 1 < facets.size(); i++) {
      if(facets[i].key != facets[i + 1].key) continue;
      _neighbors[facets[i].tetFace] = facets[i + 1].tetFace / 4;
      _neighbors[facets[i + 1].tetFace] = facets[i].tetFace / 4;
      i++;
    }
    for(std::size_t t = 0; t < tets.size(); t++) _index[tets[t]] = (int)t;
  }

  // the first tet holding v, or -1
  int tetOf(MVertex *v) const
  {
    auto it = _tetOf.find(v);
    return it == _tetOf.end() ? -1 : it->second;
  }

  // the index of e, or -1
  int indexOf(MElement *e) const
  {
    auto it = _index.find(e);
    return it == _index.end() ? -1 : it->second;
  }

  // a tet holding (x,y,z) reached from start, or -1 if the walk gives up
  int walk(int start, double x, double y, double z) const
  {
    const int maxSteps = 10000;
    double xyz[3] = {x, y, z}, uvw[3];
    int t = start;
    for(int step = 0; t >= 0 && step < maxSteps; step++) {
      if(_flat[t]) return -1;
      _tets[t]->xyz2uvw(xyz, uvw);
      if(_tets[t]->isInside(uvw[0], uvw[1], uvw[2], _tol)) return t;
      double lambda[4] = {1. - uvw[0] - uvw[1] - uvw[2], uvw[0], uvw[1],
                          uvw[2]};
      int worst = 0;
      for(int i = 1; i < 4; i++)
        if(lambda[i] < lambda[worst]) worst = i;
      t = _neighbors[4 * t + worst];
    }
    return -1;
  }

private:
  const std::vector<MTetrahedron *> &_tets;
  double _tol;
  std::vector<int> _neighbors; // across the face opposite to each vertex
  std::vector<bool> _flat;
  std::unordered_map<MVertex *, int> _tetOf;
  std::unordered_map<MElement *, int> _index;
};

// A uniform grid over the region's bounding box, cell size fixed once from
// the boundary's characteristic point spacing. Coarser or finer than the
// true (metric-scaled) spacing locally, but the query below widens its
// search radius from the candidate's own h, so it stays correct -- just
// O(1) amortized instead of the RTree's O(log n) per insert/query.
class SpatialHash {
public:
  explicit SpatialHash(double cellSize) : _cell(cellSize > 0. ? cellSize : 1.)
  {
  }

  void insert(uint32_t idx, double x, double y, double z)
  {
    _grid[key(x, y, z)].push_back(idx);
  }

  // true if some accepted point other than `skip` lies within `radius` of
  // (x,y,z) in the metric-weighted infinity norm defined by m (same test as
  // the original rtree_callback/infinity_distance)
  bool hasNeighborWithin(const std::vector<FlatPoint> &pts, double x,
                         double y, double z, double radius, const double m[9],
                         uint32_t skip) const
  {
    int64_t cx = cellOf(x), cy = cellOf(y), cz = cellOf(z);
    int reach = (int)std::ceil(radius / _cell) + 1;
    for(int dx = -reach; dx <= reach; dx++) {
      for(int dy = -reach; dy <= reach; dy++) {
        for(int dz = -reach; dz <= reach; dz++) {
          auto it = _grid.find(pack(cx + dx, cy + dy, cz + dz));
          if(it == _grid.end()) continue;
          for(uint32_t idx : it->second) {
            if(idx == skip) continue;
            const FlatPoint &p = pts[idx];
            double dxp = p.x - x, dyp = p.y - y, dzp = p.z - z;
            // infinity_distance(individual, neighbour, m): both points
            // pulled through the candidate's own local frame
            double ax = m[0] * dxp + m[1] * dyp + m[2] * dzp;
            double ay = m[3] * dxp + m[4] * dyp + m[5] * dzp;
            double az = m[6] * dxp + m[7] * dyp + m[8] * dzp;
            double d =
              std::max(std::fabs(ax), std::max(std::fabs(ay), std::fabs(az)));
            if(d < radius) return true;
          }
        }
      }
    }
    return false;
  }

  // plain Euclidean-radius collection, for the exact-duplicate cleanup pass
  // below (unlike hasNeighborWithin, no metric weighting, no early-out)
  // the cells meeting the box of half-width radius around (x,y,z): one for
  // most points when radius is small
  void collectWithin(double x, double y, double z, double radius,
                     std::vector<uint32_t> &out) const
  {
    for(int64_t cx = cellOf(x - radius); cx <= cellOf(x + radius); cx++) {
      for(int64_t cy = cellOf(y - radius); cy <= cellOf(y + radius); cy++) {
        for(int64_t cz = cellOf(z - radius); cz <= cellOf(z + radius); cz++) {
          auto it = _grid.find(pack(cx, cy, cz));
          if(it == _grid.end()) continue;
          for(uint32_t idx : it->second) out.push_back(idx);
        }
      }
    }
  }

private:
  double _cell;
  std::unordered_map<int64_t, std::vector<uint32_t> > _grid;

  int64_t cellOf(double v) const
  {
    return (int64_t)std::floor(v / _cell);
  }
  static int64_t pack(int64_t cx, int64_t cy, int64_t cz)
  {
    // 21 bits per axis (+-1M cells, plenty), offset to stay positive
    const int64_t off = 1 << 20;
    return ((cx + off) & 0x1FFFFF) | (((cy + off) & 0x1FFFFF) << 21) |
           (((cz + off) & 0x1FFFFF) << 42);
  }
  int64_t key(double x, double y, double z) const
  {
    return pack(cellOf(x), cellOf(y), cellOf(z));
  }
};

// The cells of a uniform grid over a region, inside it, outside, or across
// its boundary: a point of an inside or an outside cell is located without
// walking across the tets of the region.
class InsideGrid {
public:
  enum : unsigned char { UNKNOWN = 0, OUTSIDE = 1, INSIDE = 2, BOUNDARY = 3 };
  InsideGrid(const SBoundingBox3d &box, double cell)
  {
    const double maxCells = 2.e8;
    const SVector3 size = box.max() - box.min();
    _cell = cell;
    while((size.x() / _cell + 3) * (size.y() / _cell + 3) * (size.z() / _cell + 3) > maxCells)
      _cell *= 1.25;
    // one cell of margin around the box
    for(int k = 0; k < 3; k++) {
      _origin[k] = box.min()[k] - _cell;
      _n[k] = (int64_t)std::ceil(size[k] / _cell) + 3;
    }
    _state.assign(_n[0] * _n[1] * _n[2], UNKNOWN);
  }
  double cellSize() const { return _cell; }
  double originX() const { return _origin[0]; }
  int64_t nbCells() const { return (int64_t)_state.size(); }
  // the cell of (x,y,z), -1 if out of the grid
  int64_t cellOf(double x, double y, double z) const
  {
    const double p[3] = {x, y, z};
    int64_t c[3];
    for(int k = 0; k < 3; k++) {
      const double u = std::floor((p[k] - _origin[k]) / _cell);
      if(!(u >= 0 && u < (double)_n[k])) return -1;
      c[k] = (int64_t)u;
    }
    return (c[2] * _n[1] + c[1]) * _n[0] + c[0];
  }
  void centerOf(int64_t c, double p[3]) const
  {
    p[0] = _origin[0] + (c % _n[0] + .5) * _cell;
    p[1] = _origin[1] + ((c / _n[0]) % _n[1] + .5) * _cell;
    p[2] = _origin[2] + (c / (_n[0] * _n[1]) + .5) * _cell;
  }
  unsigned char state(int64_t c) const { return _state[c]; }
  // f(c) for the cells overlapping the box [lo, hi]
  template <class F> void forEachCell(const double lo[3], const double hi[3], const F &f) const
  {
    int64_t a[3], b[3];
    for(int k = 0; k < 3; k++) {
      a[k] = std::max((int64_t)0, (int64_t)std::floor((lo[k] - _origin[k]) / _cell));
      b[k] = std::min(_n[k] - 1, (int64_t)std::floor((hi[k] - _origin[k]) / _cell));
    }
    for(int64_t k = a[2]; k <= b[2]; k++)
      for(int64_t j = a[1]; j <= b[1]; j++)
        for(int64_t i = a[0]; i <= b[0]; i++) f((k * _n[1] + j) * _n[0] + i);
  }
  void setBoundary(int64_t c) { _state[c] = BOUNDARY; }
  // The cells not across the boundary, by connected components, each one
  // inside or outside as one of its cells for isInside(center): a component
  // does not cross the boundary, which would overlap one of two neighbouring
  // cells it separates.
  template <class IsInside> void classify(const IsInside &isInside)
  {
    std::vector<int64_t> component;
    for(int64_t c0 = 0; c0 < nbCells(); c0++) {
      if(_state[c0] != UNKNOWN) continue;
      double p[3];
      centerOf(c0, p);
      const unsigned char s = isInside(p[0], p[1], p[2]) ? INSIDE : OUTSIDE;
      component.assign(1, c0);
      _state[c0] = s;
      while(!component.empty()) {
        const int64_t c = component.back();
        component.pop_back();
        const int64_t i = c % _n[0], j = (c / _n[0]) % _n[1], k = c / (_n[0] * _n[1]);
        const int64_t next[6] = {i > 0 ? c - 1 : -1, i + 1 < _n[0] ? c + 1 : -1,
                                 j > 0 ? c - _n[0] : -1, j + 1 < _n[1] ? c + _n[0] : -1,
                                 k > 0 ? c - _n[0] * _n[1] : -1,
                                 k + 1 < _n[2] ? c + _n[0] * _n[1] : -1};
        for(int64_t d : next)
          if(d >= 0 && _state[d] == UNKNOWN) {
            _state[d] = s;
            component.push_back(d);
          }
      }
    }
  }
private:
  double _cell;
  double _origin[3];
  int64_t _n[3];
  std::vector<unsigned char> _state;
};

void setIdentity(double m[9])
{
  m[0] = 1.; m[1] = 0.; m[2] = 0.;
  m[3] = 0.; m[4] = 1.; m[5] = 0.;
  m[6] = 0.; m[7] = 0.; m[8] = 1.;
}

void metricAt(double x, double y, double z, double m[9])
{
  if(CTX::instance()->mesh.smoothCrossField) {
    STensor3 t = Frame_field::findCross(x, y, z);
    m[0] = t.get_m11(); m[1] = t.get_m21(); m[2] = t.get_m31();
    m[3] = t.get_m12(); m[4] = t.get_m22(); m[5] = t.get_m32();
    m[6] = t.get_m13(); m[7] = t.get_m23(); m[8] = t.get_m33();
  }
  else {
    STensor3 t = Frame_field::search(x, y, z);
    m[0] = t.get_m11(); m[1] = t.get_m21(); m[2] = t.get_m31();
    m[3] = t.get_m12(); m[4] = t.get_m22(); m[5] = t.get_m32();
    m[6] = t.get_m13(); m[7] = t.get_m23(); m[8] = t.get_m33();
  }
}

// same magic-tag-prefix convention as Filler::code()
int layerLimit(int tag)
{
  std::string s = std::to_string(tag);
  if(s.size() >= 5) {
    if(s[0] == '1' && s[1] == '1' && s[2] == '1' && s[3] == '1' &&
       s[4] == '1')
      return 0;
    if(s[0] == '2' && s[1] == '2' && s[2] == '2' && s[3] == '2' &&
       s[4] == '2')
      return 1;
  }
  return -1;
}

// A box of half-width k2*h centered on (x,y,z) must stay fully inside the
// volume mesh's element octree. Both Filler::treat_region
// (simple3D.cpp:far_from_boundary) and the dead Filler3D
// (pointInsertionRTreeTools.cpp:far_from_boundary_3D) hardcode this check
// to always accept ("return 1;"/"return true;"); enabling it here removed
// the last source of TetGen boundary-recovery failures once boundary
// points were no longer re-embedded as duplicates (see the layer==0 skip
// below): candidates landing too close to a boundary facet -- without
// necessarily being close to any single boundary *vertex*, which the
// point-to-point spacing check alone cannot catch -- were still producing
// degenerate local configurations. Verified: 35/35 clean runs with this
// enabled vs. roughly half failing (cleanly, no crash) without it.
template <class Locate>
bool farFromBoundary(const Locate &locate, int hint, double x, double y,
                     double z, double h)
{
  const double k2 = 0.5;
  double box = k2 * h;
  double probes[6][3] = {
    {x + box, y, z}, {x - box, y, z}, {x, y + box, z},
    {x, y - box, z}, {x, y, z + box}, {x, y, z - box},
  };
  for(auto &p : probes)
    if(locate(hint, p[0], p[1], p[2]) == -1) return false;
  return true;
}

// A degenerate cross-field/size query (e.g. a zero-length edge feeding a
// division in Frame_field's smoothing) has been seen to return a NaN
// metric or size. Since any comparison with NaN is false, the spacing
// rejection test below would then never consider such a point "too close"
// to anything -- so it (and its own spawned children, equally NaN) get
// accepted unconditionally, forever: an unbounded point-count runaway
// rather than a clean failure. Reject non-finite points outright instead.
bool isFinitePoint(double h, const double m[9])
{
  if(!std::isfinite(h)) return false;
  for(int i = 0; i < 9; i++)
    if(!std::isfinite(m[i])) return false;
  return true;
}

} // namespace

void fillRegionFlat(GRegion *gr, CombineFrames *frames)
{
  int numSmooth = CTX::instance()->mesh.smoothCrossField;
  if(numSmooth && gr->dim() == 3) {
    Frame_field::initRegion(gr, numSmooth);
    Frame_field::smoothRegion(gr, numSmooth);
  }

  Frame_field::init_region(gr);

  // Sizes follow gmsh's general 3D scheme (as in insertVerticesInRegion):
  // the background size, clamped by the sizes extended from the boundary
  // mesh and interpolated on the current tets.
  const bool extend = Extend2dMeshIn3dVolumes();
  std::unordered_map<MVertex *, double> vSizes;
  if(extend) computeMeshSizesFromBoundary(gr, vSizes);
  auto sizeAt = [&](MElement *e, double x, double y, double z) {
    double lc = BGM_MeshSize(gr, 0, 0, x, y, z);
    if(!extend || !e) return lc;
    double xyz[3] = {x, y, z}, uvw[3];
    e->xyz2uvw(xyz, uvw);
    double w[4] = {1. - uvw[0] - uvw[1] - uvw[2], uvw[0], uvw[1], uvw[2]};
    double lcb = 0.;
    for(int i = 0; i < 4; i++) {
      auto it = vSizes.find(e->getVertex(i));
      if(it == vSizes.end()) return lc;
      lcb += w[i] * it->second;
    }
    return std::min(lc, lcb);
  };
  auto sizeAtVertex = [&](MVertex *v) {
    double lc = BGM_MeshSize(gr, 0, 0, v->x(), v->y(), v->z());
    if(!extend) return lc;
    auto it = vSizes.find(v);
    return it == vSizes.end() ? lc : std::min(lc, it->second);
  };

  // Only this region's own tets: a model-wide octree lets the front leak
  // into neighbouring, already-meshed regions.
  std::vector<MElement *> regionElements(gr->tetrahedra.begin(),
                                         gr->tetrahedra.end());
  MElementOctree *octree =
    regionElements.empty() ? nullptr : new MElementOctree(regionElements);
  TetWalker walker(gr->tetrahedra,
                   CTX::instance()->mesh.toleranceReferenceElement);
  // the index of a tet holding (x,y,z), or -1: by a walk from the tet hint,
  // else by the octree (with the same tolerance)
  auto locate = [&](int hint, double x, double y, double z) {
    if(hint >= 0) {
      int t = walker.walk(hint, x, y, z);
      if(t >= 0) return t;
    }
    MElement *e = octree ? octree->find(x, y, z, 3, true) : nullptr;
    return e ? walker.indexOf(e) : -1;
  };

  // seed the front from the boundary mesh (points, then curves, then
  // surfaces, matching Filler::treat_region's ordering)
  std::vector<GFace *> faces = gr->faces();
  std::vector<MVertex *> boundaryVertices;
  std::unordered_map<MVertex *, int> limitOf;
  {
    std::vector<MVertex *> temp;
    std::unordered_map<MVertex *, bool> seen;
    for(GFace *gf : faces) {
      int limit = layerLimit(gf->tag());
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *elt = gf->getMeshElement(i);
        for(std::size_t j = 0; j < elt->getNumVertices(); j++) {
          MVertex *v = elt->getVertex(j);
          if(!seen[v]) {
            seen[v] = true;
            temp.push_back(v);
          }
          limitOf[v] = limit;
        }
      }
    }
    // In space filling (Morton) order: the order of the seeds is the one in
    // which the front settles its conflicts, and the faces one after the
    // other leave more tets between the hexes (+1% hexes, -30% tets on a
    // pipe junction)
    {
      const SBoundingBox3d box = gr->bounds();
      auto key = [&](MVertex *v) {
        const double p[3] = {v->x(), v->y(), v->z()};
        uint32_t c[3];
        for(int i = 0; i < 3; i++) {
          const double u = (p[i] - box.min()[i]) / (box.max()[i] - box.min()[i] + 1e-300);
          c[i] = (uint32_t)std::min(2097151., std::max(0., u * 2097151.));
        }
        uint64_t k = 0;
        for(int bit = 20; bit >= 0; bit--)
          for(int i = 0; i < 3; i++) k = (k << 1) | ((c[i] >> bit) & 1);
        return k;
      };
      std::vector<std::pair<uint64_t, std::size_t> > keys(temp.size());
      for(std::size_t i = 0; i < temp.size(); i++) keys[i] = {key(temp[i]), i};
      std::sort(keys.begin(), keys.end());
      std::vector<MVertex *> sorted(temp.size());
      for(std::size_t i = 0; i < temp.size(); i++) sorted[i] = temp[keys[i].second];
      temp.swap(sorted);
    }
    for(int dim = 0; dim <= 2; dim++)
      for(MVertex *v : temp)
        if(v->onWhat()->dim() == dim) boundaryVertices.push_back(v);
  }

  std::vector<FlatPoint> pts;
  pts.reserve(boundaryVertices.size() * 8 + 1024);
  std::vector<uint32_t> queue;
  queue.reserve(pts.capacity());

  std::vector<FlatPoint> seeds;
  seeds.reserve(boundaryVertices.size());
  double h0 = 0.;
  for(MVertex *v : boundaryVertices) {
    FlatPoint p;
    p.x = v->x(); p.y = v->y(); p.z = v->z();
    p.h = sizeAtVertex(v);
    metricAt(p.x, p.y, p.z, p.m);
    if(!isFinitePoint(p.h, p.m)) continue;
    p.layer = 0;
    p.limit = limitOf[v];
    p.tet = walker.tetOf(v);
    p.v = v;
    seeds.push_back(p);
    h0 += p.h;
  }
  h0 = seeds.empty() ? gr->bounds().diag() * 0.05 : h0 / seeds.size();
  SpatialHash hash(std::max(h0, 1e-12));

  // The grid of the cells inside the region, outside, or across its
  // boundary (overlapped by a boundary triangle, widened), and the
  // triangles overlapping each cell across it. Away from the boundary, the
  // walks are long across the tets of the boundary points only, the more so
  // as the mesh is finer. Near it, the tets are needed only to interpolate
  // the sizes extended from the boundary: otherwise, a point is inside if
  // a segment to a point of known side crosses the boundary triangles an
  // even number of times (or an odd one from outside).
  const bool withTets = extend;
  InsideGrid grid(gr->bounds(), std::max(h0, 1e-12));
  std::vector<std::array<double, 9> > triangles;
  std::unordered_map<int64_t, uint32_t> rowOf; // the boundary cells
  std::vector<std::size_t> rowStart;
  std::vector<uint32_t> rowTriangles;
  std::unordered_map<int64_t, int> startTet;
  {
    const double margin =
      std::max(1.e-2 * grid.cellSize(), 1.e-5 * gr->bounds().diag());
    // the triangles of the boundary (a face on both sides of the region
    // twice: it is crossed twice), quads split
    std::vector<MVertex *> starts;
    for(GFace *gf : faces)
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        const std::size_t n = e->getNumPrimaryVertices();
        for(std::size_t k = 1; k + 1 < n; k++) {
          std::array<double, 9> t;
          MVertex *v[3] = {e->getVertex(0), e->getVertex(k), e->getVertex(k + 1)};
          for(int j = 0; j < 3; j++) {
            t[3 * j] = v[j]->x();
            t[3 * j + 1] = v[j]->y();
            t[3 * j + 2] = v[j]->z();
          }
          triangles.push_back(t);
          starts.push_back(v[0]);
        }
      }
    auto boxOf = [&](const std::array<double, 9> &t, double lo[3], double hi[3]) {
      for(int k = 0; k < 3; k++) {
        lo[k] = std::min({t[k], t[3 + k], t[6 + k]}) - margin;
        hi[k] = std::max({t[k], t[3 + k], t[6 + k]}) + margin;
      }
    };
    std::vector<std::size_t> count;
    for(std::size_t i = 0; i < triangles.size(); i++) {
      double lo[3], hi[3];
      boxOf(triangles[i], lo, hi);
      const int t = withTets ? walker.tetOf(starts[i]) : -1;
      grid.forEachCell(lo, hi, [&](int64_t c) {
        grid.setBoundary(c);
        auto it = rowOf.emplace(c, (uint32_t)count.size());
        if(it.second) count.push_back(0);
        count[it.first->second]++;
        if(t >= 0) startTet.emplace(c, t);
      });
    }
    rowStart.assign(count.size() + 1, 0);
    for(std::size_t r = 0; r < count.size(); r++) rowStart[r + 1] = rowStart[r] + count[r];
    rowTriangles.resize(rowStart.back());
    std::vector<std::size_t> next(rowStart.begin(), rowStart.end() - 1);
    for(std::size_t i = 0; i < triangles.size(); i++) {
      double lo[3], hi[3];
      boxOf(triangles[i], lo, hi);
      grid.forEachCell(lo, hi, [&](int64_t c) {
        rowTriangles[next[rowOf[c]]++] = (uint32_t)i;
      });
    }
  }
  // the static filter of the predicates for the coordinates of the grid
  {
    const SBoundingBox3d box = gr->bounds();
    const double d = 2. * grid.cellSize();
    robustPredicates::exactinit(
      std::max(std::fabs(box.min().x()), std::fabs(box.max().x())) + d,
      std::max(std::fabs(box.min().y()), std::fabs(box.max().y())) + d,
      std::max(std::fabs(box.min().z()), std::fabs(box.max().z())) + d);
  }
  // The parity of the crossings of the segment [q, r] with the boundary
  // triangles of the cells c1 and c2 (the only ones it can cross if it lies
  // in them), -1 if it touches one at a vertex, an edge, or in its plane
  std::vector<uint32_t> seen(triangles.size(), 0);
  uint32_t stamp = 0;
  auto crossingsIn = [&](const double q[3], const double r[3],
                         const std::vector<int64_t> &cells) {
    ++stamp;
    int parity = 0;
    for(int64_t c : cells) {
      if(c < 0 || grid.state(c) != InsideGrid::BOUNDARY) continue;
      const uint32_t row = rowOf[c];
      for(std::size_t k = rowStart[row]; k < rowStart[row + 1]; k++) {
        const uint32_t i = rowTriangles[k];
        if(seen[i] == stamp) continue;
        seen[i] = stamp;
        const double *a = &triangles[i][0], *b = &triangles[i][3], *c3 = &triangles[i][6];
        const double s1 = robustPredicates::orient3d(a, b, c3, q);
        const double s2 = robustPredicates::orient3d(a, b, c3, r);
        if((s1 > 0 && s2 > 0) || (s1 < 0 && s2 < 0)) continue;
        const double t1 = robustPredicates::orient3d(q, r, a, b);
        const double t2 = robustPredicates::orient3d(q, r, b, c3);
        const double t3 = robustPredicates::orient3d(q, r, c3, a);
        if((t1 > 0 && t2 > 0 && t3 > 0) || (t1 < 0 && t2 < 0 && t3 < 0)) {
          if(s1 == 0 || s2 == 0) return -1;
          parity ^= 1;
        }
        else if((t1 == 0 || t2 == 0 || t3 == 0) &&
                !((t1 > 0 || t2 > 0 || t3 > 0) && (t1 < 0 || t2 < 0 || t3 < 0)))
          return -1;
      }
    }
    return parity;
  };
  std::vector<int64_t> pair(2);
  auto crossings = [&](const double q[3], const double r[3], int64_t c1, int64_t c2) {
    pair[0] = c1;
    pair[1] = c2;
    return crossingsIn(q, r, pair);
  };
  if(withTets)
    grid.classify(
      [&](double x, double y, double z) { return locate(-1, x, y, z) >= 0; });
  else
    // from a point of the margin of the grid, outside, on the same row:
    // the segment lies in the cells of the row
    grid.classify([&](double x, double y, double z) {
      const double h = grid.cellSize();
      for(int k = 0; k < 9; k++) {
        const double q[3] = {x, y + (k % 3 - 1) * .1 * h, z + (k / 3 - 1) * .1 * h};
        const double r[3] = {grid.originX() + .5 * h, q[1], q[2]};
        std::vector<int64_t> row;
        double lo[3] = {r[0], q[1], q[2]}, hi[3] = {q[0], q[1], q[2]};
        grid.forEachCell(lo, hi, [&](int64_t c) { row.push_back(c); });
        const int parity = crossingsIn(q, r, row);
        if(parity >= 0) return parity == 1;
      }
      return false;
    });
  // In each cell across the boundary, a point of known side: its center (or
  // a point near it off the planes of the triangles), from a neighbouring
  // cell of known side, the segment lying in the two cells
  std::vector<std::array<double, 3> > reference(withTets ? 0 : rowStart.size() - 1);
  std::vector<char> referenceSide(reference.size(), -1); // -1: unknown
  if(!withTets) {
    std::vector<int64_t> cellOfRow(reference.size());
    for(const auto &it : rowOf) cellOfRow[it.second] = it.first;
    auto neighbours = [&](int64_t c, int64_t next[6]) {
      double p[3];
      grid.centerOf(c, p);
      const double h = grid.cellSize();
      const double d[6][3] = {{h, 0, 0}, {-h, 0, 0}, {0, h, 0}, {0, -h, 0}, {0, 0, h}, {0, 0, -h}};
      for(int k = 0; k < 6; k++) next[k] = grid.cellOf(p[0] + d[k][0], p[1] + d[k][1], p[2] + d[k][2]);
    };
    // the side of a point of a neighbour, -1 if unknown
    auto known = [&](int64_t c, double r[3]) {
      const unsigned char state = grid.state(c);
      if(state == InsideGrid::INSIDE || state == InsideGrid::OUTSIDE) {
        grid.centerOf(c, r);
        return state == InsideGrid::INSIDE ? 1 : 0;
      }
      const uint32_t row = rowOf[c];
      if(referenceSide[row] < 0) return -1;
      for(int k = 0; k < 3; k++) r[k] = reference[row][k];
      return (int)referenceSide[row];
    };
    auto resolve = [&](uint32_t row) {
      const int64_t c = cellOfRow[row];
      int64_t next[6];
      neighbours(c, next);
      double center[3];
      grid.centerOf(c, center);
      const double h = grid.cellSize();
      const double nudge[4][3] = {{0, 0, 0}, {.11, .07, .03}, {-.05, .13, -.09}, {.08, -.12, .1}};
      for(int64_t n : next) {
        if(n < 0) continue;
        double r[3];
        const int side = known(n, r);
        if(side < 0) continue;
        for(auto &u : nudge) {
          const double q[3] = {center[0] + u[0] * h, center[1] + u[1] * h, center[2] + u[2] * h};
          const int parity = crossings(q, r, c, n);
          if(parity < 0) continue;
          reference[row] = {q[0], q[1], q[2]};
          referenceSide[row] = side != parity;
          return true;
        }
      }
      return false;
    };
    // breadth first from the cells of known side
    std::vector<uint32_t> front, nextFront;
    for(uint32_t row = 0; row < reference.size(); row++) front.push_back(row);
    while(!front.empty()) {
      nextFront.clear();
      for(uint32_t row : front)
        if(referenceSide[row] < 0 && !resolve(row)) nextFront.push_back(row);
      if(nextFront.size() == front.size()) break; // no progress
      front.swap(nextFront);
    }
  }
  // inside, by the parity from the reference of the cell (an endpoint in the
  // plane of a triangle crossing it is on the boundary: inside, as for the
  // tets and their tolerance)
  auto insideByParity = [&](double x, double y, double z) {
    const int64_t c = grid.cellOf(x, y, z);
    const uint32_t row = rowOf[c];
    if(referenceSide[row] < 0) return true;
    const double q[3] = {x, y, z};
    const int parity = crossings(q, &reference[row][0], c, -1);
    if(parity < 0) return true;
    return (referenceSide[row] == 1) != (parity == 1);
  };
  // the index of a tet holding (x,y,z) near the boundary (-2 without tets),
  // -2 if it is inside away from it, -1 if outside
  auto locateInGrid = [&](int hint, double x, double y, double z) {
    const int64_t c = grid.cellOf(x, y, z);
    if(c < 0) return -1;
    const unsigned char state = grid.state(c);
    if(state == InsideGrid::INSIDE) return -2;
    if(state == InsideGrid::OUTSIDE) return -1;
    if(!withTets) return insideByParity(x, y, z) ? -2 : -1;
    if(hint < 0) {
      auto it = startTet.find(c);
      if(it != startTet.end()) hint = it->second;
    }
    return locate(hint, x, y, z);
  };

  double t0 = Cpu();
  for(const FlatPoint &p : seeds) {
    uint32_t idx = (uint32_t)pts.size();
    pts.push_back(p);
    hash.insert(idx, p.x, p.y, p.z);
    queue.push_back(idx);
  }

  std::size_t qhead = 0;
  long count = 1;
  while(qhead < queue.size()) {
    uint32_t parentIdx = queue[qhead++];
    // snapshot: pts may reallocate as we push new points below
    FlatPoint parent = pts[parentIdx];

    if(parent.limit != -1 && parent.layer >= parent.limit) continue;

    if(count % 1000 == 0)
      Msg::Info("%d points inserted -- queue size %d", (int)pts.size(),
                (int)(queue.size() - qhead));
    count++;

    // 6 candidate spawns along +-(local frame axes), exactly as
    // Filler::create_spawns
    double dir[6][3] = {
      {parent.m[0], parent.m[1], parent.m[2]},
      {-parent.m[0], -parent.m[1], -parent.m[2]},
      {parent.m[3], parent.m[4], parent.m[5]},
      {-parent.m[3], -parent.m[4], -parent.m[5]},
      {parent.m[6], parent.m[7], parent.m[8]},
      {-parent.m[6], -parent.m[7], -parent.m[8]},
    };

    for(int i = 0; i < 6; i++) {
      double x = parent.x + parent.h * dir[i][0];
      double y = parent.y + parent.h * dir[i][1];
      double z = parent.z + parent.h * dir[i][2];

      // the sizes extended from the boundary are interpolated in a tet
      const int t = extend ? locate(parent.tet, x, y, z) :
                             locateInGrid(parent.tet, x, y, z);
      if(t == -1) continue;
      MElement *e = t >= 0 ? gr->tetrahedra[t] : nullptr;

      FlatPoint cand;
      cand.x = x; cand.y = y; cand.z = z;
      cand.h = sizeAt(e, x, y, z);
      metricAt(x, y, z, cand.m);
      if(!isFinitePoint(cand.h, cand.m)) continue;
      cand.layer = parent.layer + 1;
      cand.limit = parent.limit;
      cand.tet = t >= 0 ? t : -1;
      cand.v = nullptr;

      // cheap spacing test first: most spawns land on an existing point,
      // and farFromBoundary costs 6 point locations
      double radius = k1 * cand.h;
      if(hash.hasNeighborWithin(pts, x, y, z, radius, cand.m, parentIdx))
        continue;

      if(!farFromBoundary(locateInGrid, cand.tet, x, y, z, cand.h)) continue;

      uint32_t idx = (uint32_t)pts.size();
      pts.push_back(cand);
      hash.insert(idx, x, y, z);
      queue.push_back(idx);
    }
  }

  Msg::Info("- Region %i: flat filler inserted %d points (%.3f seconds)",
            gr->tag(), (int)pts.size(), Cpu() - t0);

  // Defensive near-duplicate cleanup: the spacing check above rejects
  // candidates closer than k1*h to an existing point, but a handful of
  // numerically-coincident points have been observed to slip through
  // (intermittently, likely from two frontal directions converging on
  // the same spot within floating-point noise); a degenerate/duplicate
  // vertex in the tet mesh has been seen to crash HXTCombine's surface
  // extraction downstream, so catch it here rather than there.
  {
    double eps = std::max(gr->bounds().diag() * 1e-9, 1e-10);
    std::vector<bool> dropped(pts.size(), false);
    std::vector<uint32_t> nearby;
    int ndup = 0;
    for(std::size_t i = 0; i < pts.size(); i++) {
      if(dropped[i]) continue;
      nearby.clear();
      hash.collectWithin(pts[i].x, pts[i].y, pts[i].z, eps, nearby);
      for(uint32_t j : nearby) {
        if(j <= i || dropped[j]) continue;
        double dx = pts[j].x - pts[i].x, dy = pts[j].y - pts[i].y,
               dz = pts[j].z - pts[i].z;
        if(dx * dx + dy * dy + dz * dz < eps * eps) {
          dropped[j] = true;
          ndup++;
        }
      }
    }
    if(ndup > 0) {
      Msg::Info("- Region %i: dropped %d near-duplicate point(s)", gr->tag(),
                ndup);
      std::vector<FlatPoint> kept;
      kept.reserve(pts.size() - ndup);
      for(std::size_t i = 0; i < pts.size(); i++)
        if(!dropped[i]) kept.push_back(pts[i]);
      pts.swap(kept);
    }
  }

  delete octree;

  deMeshGRegion deleter;
  deleter(gr);

  auto keepFrame = [&](MVertex *v, const FlatPoint &p) {
    if(!frames || !v) return;
    CombineFrame &f = (*frames)[v];
    std::copy(p.m, p.m + 9, f.axes);
    f.size = p.h;
  };
  // Layer-0 points are the boundary vertices this fill started from
  // (seeded straight from the GFace meshes, see above): they are already
  // part of the boundary mesh, so only the new interior points (layer > 0)
  // are inserted -- re-inserting a boundary vertex as a second point gives
  // near-coincident duplicates wherever two adjacent GFaces place their
  // nodes close together, which corrupts the boundary recovery.
  if(frames) frames->reserve(frames->size() + pts.size());
  std::vector<std::size_t> interior;
  interior.reserve(pts.size());
  for(std::size_t i = 0; i < pts.size(); i++) {
    if(pts[i].layer == 0) keepFrame(pts[i].v, pts[i]);
    else interior.push_back(i);
  }

#if defined(HAVE_HXT)
  // the boundary and the points tetrahedralized as they are, in parallel
  // (all the cores, as the combination, unless Mesh.MaxNumThreads3D), by HXT
  // or pdel3d (Mesh.Recombine3DDelaunay)
  {
    std::vector<double> xyz(3 * interior.size());
    for(std::size_t i = 0; i < interior.size(); i++) {
      xyz[3 * i] = pts[interior[i]].x;
      xyz[3 * i + 1] = pts[interior[i]].y;
      xyz[3 * i + 2] = pts[interior[i]].z;
    }
    const int nthreads = CTX::instance()->mesh.maxNumThreads3D > 0 ?
                           CTX::instance()->mesh.maxNumThreads3D :
                           Msg::GetMaxThreads();
    std::vector<MVertex *> vertices;
    const int algo = CTX::instance()->mesh.recombine3DDelaunay;
    if(algo ? !meshGRegionParallelDelaunayWithPoints(gr, xyz, vertices,
                                                     algo == 2) :
              !meshGRegionHxtWithPoints(gr, xyz, nthreads, vertices)) {
      for(std::size_t i = 0; i < interior.size(); i++)
        keepFrame(vertices[i], pts[interior[i]]);
      Frame_field::clear();
      return;
    }
    Msg::Warning("%s could not tetrahedralize region %d with its points, "
                 "legacy Delaunay instead", algo ? "pdel3d" : "HXT", gr->tag());
    deleter(gr);
  }
#endif

  // the legacy Delaunay, the points as embedded vertices
  std::vector<GVertex *> oldEmbedded = gr->embeddedVertices();
  std::vector<Vertex *> newVertex;
  newVertex.reserve(interior.size());
  for(std::size_t i : interior) {
    const FlatPoint &p = pts[i];
    MVertex *v = new MVertex(p.x, p.y, p.z, gr, 0);
    keepFrame(v, p);
    Vertex *vv = new Vertex(p.x, p.y, p.z);
    newVertex.push_back(vv);
    gmshVertex *newV = new gmshVertex(gr->model(), vv);
    newV->mesh_vertices.push_back(v);
    v->setEntity(gr);
    gr->mesh_vertices.push_back(v);
    gr->addEmbeddedVertex(newV);
  }
  std::vector<GRegion *> regions;
  regions.push_back(gr);
  MeshDelaunayVolume(regions);

  gr->embeddedVertices() = oldEmbedded;

  for(Vertex *vv : newVertex) delete vv;

  Frame_field::clear();
}
