// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "pointInsertionFlat.h"

#include <cmath>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "MVertex.h"
#include "meshGRegion.h"
#include "directions3D.h"
#include "Context.h"
#include "Geo.h"
#include "gmshVertex.h"
#include "GmshMessage.h"
#include "OS.h"

namespace {

// k1*h is the minimal distance between two accepted points, k2*h the
// minimal distance to the boundary (unused here, see below -- disabled
// upstream too).
const double k1 = 0.7;

// One accepted (or candidate) point, everything a plain double/int: no
// Node/MVertex/GVertex allocated per point during the fill itself.
struct FlatPoint {
  double x, y, z;
  double h;
  // the local frame, row-major 3x3 (m[0..2]=row1, m[3..5]=row2, m[6..8]=row3)
  double m[9];
  int layer;
  int limit; // -1: unbounded
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
  void collectWithin(double x, double y, double z, double radius,
                     std::vector<uint32_t> &out) const
  {
    int64_t cx = cellOf(x), cy = cellOf(y), cz = cellOf(z);
    int reach = (int)std::ceil(radius / _cell) + 1;
    for(int dx = -reach; dx <= reach; dx++) {
      for(int dy = -reach; dy <= reach; dy++) {
        for(int dz = -reach; dz <= reach; dz++) {
          auto it = _grid.find(pack(cx + dx, cy + dy, cz + dz));
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
bool farFromBoundary(MElementOctree *octree, double x, double y, double z,
                      double h)
{
  const double k2 = 0.5;
  double box = k2 * h;
  double probes[6][3] = {
    {x + box, y, z}, {x - box, y, z}, {x, y + box, z},
    {x, y - box, z}, {x, y, z + box}, {x, y, z - box},
  };
  for(auto &p : probes)
    if(!octree->find(p[0], p[1], p[2], 3, true)) return false;
  return true;
}

} // namespace

void fillRegionFlat(GRegion *gr)
{
  int numSmooth = CTX::instance()->mesh.smoothCrossField;
  if(numSmooth && gr->dim() == 3) {
    Frame_field::initRegion(gr, numSmooth);
    Frame_field::smoothRegion(gr, numSmooth);
  }

  Frame_field::init_region(gr);
  Size_field::init_region(gr);
  Size_field::solve(gr);

  MElementOctree *octree = new MElementOctree(gr->model());

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
    for(int dim = 0; dim <= 2; dim++)
      for(MVertex *v : temp)
        if(v->onWhat()->dim() == dim) boundaryVertices.push_back(v);
  }

  std::vector<FlatPoint> pts;
  pts.reserve(boundaryVertices.size() * 8 + 1024);
  std::vector<uint32_t> queue;
  queue.reserve(pts.capacity());

  double h0 = Size_field::search(gr->bounds().center().x(),
                                 gr->bounds().center().y(),
                                 gr->bounds().center().z());
  if(h0 <= 0.) h0 = gr->bounds().diag() * 0.05;
  SpatialHash hash(std::max(h0, 1e-12));

  for(MVertex *v : boundaryVertices) {
    FlatPoint p;
    p.x = v->x(); p.y = v->y(); p.z = v->z();
    p.h = Size_field::search(p.x, p.y, p.z);
    metricAt(p.x, p.y, p.z, p.m);
    p.layer = 0;
    p.limit = limitOf[v];
    uint32_t idx = (uint32_t)pts.size();
    pts.push_back(p);
    hash.insert(idx, p.x, p.y, p.z);
    queue.push_back(idx);
  }

  double t0 = Cpu();
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

      MElement *e = octree->find(x, y, z, 3, true);
      if(!e) continue;

      FlatPoint cand;
      cand.x = x; cand.y = y; cand.z = z;
      cand.h = Size_field::search(x, y, z);
      metricAt(x, y, z, cand.m);
      cand.layer = parent.layer + 1;
      cand.limit = parent.limit;

      if(!farFromBoundary(octree, x, y, z, cand.h)) continue;

      double radius = k1 * cand.h;
      if(hash.hasNeighborWithin(pts, x, y, z, radius, cand.m, parentIdx))
        continue;

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

  // hand the points to the Delaunay tetrahedralizer, same embedded-vertex
  // mechanism as Filler::treat_region.
  deMeshGRegion deleter;
  deleter(gr);

  std::vector<GVertex *> oldEmbedded = gr->embeddedVertices();
  std::vector<Vertex *> newVertex;
  newVertex.reserve(pts.size());
  for(const FlatPoint &p : pts) {
    // Layer-0 points are the boundary vertices this fill started from
    // (seeded straight from the GFace meshes, see above): they are
    // already part of the domain's boundary mesh/PLC, so only genuinely
    // new interior points (layer > 0) should be embedded here -- matching
    // Filler::treat_region, which only ever pushes accepted *spawns* into
    // new_vertices, never the boundary seeds themselves (simple3D.cpp).
    // Re-embedding a boundary vertex as a second, separate point produces
    // an exact or near-coincident duplicate wherever two independently
    // meshed adjacent GFaces (e.g. across a small/sharp shared feature)
    // happen to place their own boundary nodes close together in real
    // space -- confirmed directly: with a strongly graded size field,
    // ~1100 point pairs ended up far closer than the k1*h spacing the
    // frontal acceptance test is supposed to guarantee, and *every one*
    // of them involved a layer-0 point (never two candidate points),
    // which is exactly this. That degenerate local configuration is what
    // was corrupting TetGen's boundary recovery downstream.
    if(p.layer == 0) continue;
    MVertex *v = new MVertex(p.x, p.y, p.z, gr, 0);
    Vertex *vv = new Vertex(p.x, p.y, p.z);
    newVertex.push_back(vv);
    gmshVertex *newV = new gmshVertex(gr->model(), vv);
    newV->mesh_vertices.push_back(v);
    v->setEntity(gr);
    gr->mesh_vertices.push_back(v);
    gr->addEmbeddedVertex(newV);
  }

  // NOTE: kept on the legacy (non-HXT) embedded-vertex insertion here.
  // HXT's embedded-vertex path (Gmsh2Hxt) only picks up GVertex::points
  // (MPoint elements), not GVertex::mesh_vertices -- the same field both
  // this code and the original Filler populate -- so routing through HXT
  // silently drops the large majority of the generated points (verified:
  // 305286 generated, only 176490 survived). It was tried again after
  // fixing the TetGen point2tetorg/recoveredgebyflips crash (see
  // src/mesh/tetgenBR.{h,cxx}) since HXT's boundary recovery ends up
  // calling the exact same (now-fixed) TetGen code anyway -- but HXT
  // still failed to recover the boundary even for a plain uniform-size
  // mesh with this many embedded points, which the legacy path has always
  // handled correctly. Stay on the legacy path.
  std::vector<GRegion *> regions;
  regions.push_back(gr);
  MeshDelaunayVolume(regions);

  gr->embeddedVertices() = oldEmbedded;

  for(Vertex *vv : newVertex) delete vv;

  delete octree;
  Size_field::clear();
  Frame_field::clear();
}
