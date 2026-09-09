// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Business-logic half of the octree-based automatic mesh size field: HXT/CAD
// glue, curvature computation, medial-axis-based feature size (Dey-Zhao via
// Voronoi poles), refinement/coarsening/assignment predicates, and the
// overall orchestration. Pure tree mechanics (splitting, 2:1 balancing,
// gradient limitation, point evaluation) live in SizeOctree.{h,cpp} and are
// used here purely as a container for the scalar field h(x); this file knows
// nothing about how the octree is implemented internally.
//
// This is a direct port of the algorithm previously implemented in
// src/mesh/automaticMeshSizeField.cpp (contributed by Arthur Bawin) on top of
// p4est. The isotropic 3D path is ported essentially unchanged; the
// anisotropic path (SMetric3, curvature-direction interpolation) and the
// unfinished 2D path are out of scope and have been dropped, along with
// every p4est-specific data structure and every debug/scratch .pos file
// writer that used to live alongside the algorithm.

#include "OctreeSizeField.h"
#include "GmshMessage.h"

#if defined(HAVE_HXT)

#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEntity.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MEdge.h"
#include "MFace.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "curvature.h"
#include "Numeric.h"
#include "robustPredicates.h"
#include "rtree.h"

extern "C" {
#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_bbox.h"
#include "hxt_tetMesh.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetRefine.h"
}

#include <cfloat>
#include <cmath>
#include <map>
#include <set>
#include <vector>

/* ==========================================================================
   Small helpers (ported unchanged from automaticMeshSizeField.cpp)
   ========================================================================== */

static inline void norme2(double v[3], double *n)
{
  *n = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

static inline bool isPoint(double x1, double y1, double z1, double x2,
                           double y2, double z2, double tol)
{
  return (fabs(x2 - x1) < tol && fabs(y2 - y1) < tol && fabs(z2 - z1) < tol);
}

static bool rtreeCallback(uint64_t id, void *ctx)
{
  std::vector<uint64_t> *vec = reinterpret_cast<std::vector<uint64_t> *>(ctx);
  vec->push_back(id);
  return true;
}

/* ==========================================================================
   Gmsh -> HXT glue (ported unchanged)
   ========================================================================== */

static HXTStatus getAllFacesOfAllRegions(std::vector<GRegion *> &regions,
                                         HXTMesh *m,
                                         std::vector<GFace *> &allFaces)
{
  std::set<GFace *, GEntityPtrLessThan> allFacesSet;
  if(m) {
    m->brep.numVolumes = regions.size();
    HXT_CHECK(hxtAlignedMalloc(&m->brep.numSurfacesPerVolume,
                               m->brep.numVolumes * sizeof(uint32_t)));
  }
  uint32_t to_alloc = 0;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    if(m) {
      m->brep.numSurfacesPerVolume[i] = f.size() + f_e.size();
      to_alloc += m->brep.numSurfacesPerVolume[i];
    }
    allFacesSet.insert(f.begin(), f.end());
    allFacesSet.insert(f_e.begin(), f_e.end());
  }
  allFaces.insert(allFaces.begin(), allFacesSet.begin(), allFacesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.surfacesPerVolume, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    for(size_t j = 0; j < f.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f[j]->tag();
    for(size_t j = 0; j < f_e.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f_e[j]->tag();
  }

  return HXT_STATUS_OK;
}

static HXTStatus getAllEdgesOfAllFaces(std::vector<GFace *> &faces, HXTMesh *m,
                                       std::vector<GEdge *> &allEdges)
{
  if(m) {
    m->brep.numSurfaces = faces.size();
    HXT_CHECK(hxtAlignedMalloc(&m->brep.numCurvesPerSurface,
                               m->brep.numSurfaces * sizeof(uint32_t)));
  }
  uint32_t to_alloc = 0;

  std::set<GEdge *, GEntityPtrLessThan> allEdgesSet;
  for(std::size_t i = 0; i < faces.size(); i++) {
    std::vector<GEdge *> const &f = faces[i]->edges();
    std::vector<GEdge *> const &f_e = faces[i]->embeddedEdges();
    if(m) {
      m->brep.numCurvesPerSurface[i] = f.size() + f_e.size();
      to_alloc += m->brep.numCurvesPerSurface[i];
    }
    allEdgesSet.insert(f.begin(), f.end());
    allEdgesSet.insert(f_e.begin(), f_e.end());
  }
  allEdges.insert(allEdges.begin(), allEdgesSet.begin(), allEdgesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.curvesPerSurface, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < faces.size(); i++) {
    std::vector<GEdge *> const &f = faces[i]->edges();
    std::vector<GEdge *> const &f_e = faces[i]->embeddedEdges();
    for(size_t j = 0; j < f.size(); j++)
      m->brep.curvesPerSurface[counter++] = f[j]->tag();
    for(size_t j = 0; j < f_e.size(); j++)
      m->brep.curvesPerSurface[counter++] = f_e[j]->tag();
  }
  return HXT_STATUS_OK;
}

// Builds a single global HXTMesh (vertices/lines/triangles) from the given
// GFaces.
static HXTStatus Gmsh2Hxt(std::vector<GFace *> &faces, HXTMesh *m,
                          std::map<MVertex *, uint32_t> &v2c,
                          std::vector<MVertex *> &c2v)
{
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t ntri = 0;
  uint64_t nedg = 0;

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    nedg += ge->lines.size();
    for(size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    ntri += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(MVertex *v : all) {
    m->vertices.coord[4 * count + 0] = v->x();
    m->vertices.coord[4 * count + 1] = v->y();
    m->vertices.coord[4 * count + 2] = v->z();
    m->vertices.coord[4 * count + 3] = 0;
    v2c[v] = count;
    c2v[count++] = v;
  }
  all.clear();

  m->lines.num = m->lines.size = nedg;
  uint64_t index = 0;

  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint32_t)));

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      m->lines.node[2 * index + 0] = v2c[ge->lines[i]->getVertex(0)];
      m->lines.node[2 * index + 1] = v2c[ge->lines[i]->getVertex(1)];
      m->lines.color[index] = ge->tag();
      index++;
    }
  }

  m->triangles.num = m->triangles.size = ntri;
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.color,
                             (m->triangles.num) * sizeof(uint32_t)));

  index = 0;
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.color[index] = gf->tag();
      index++;
    }
  }
  return HXT_STATUS_OK;
}

// Same as Gmsh2Hxt, but for a single GFace at a time (used to compute
// curvature face-by-face with a local vertex numbering).
static HXTStatus Gmsh2HxtLocal(std::vector<GFace *> &faces, HXTMesh *m,
                               std::map<MVertex *, uint32_t> &v2c,
                               std::vector<MVertex *> &c2v)
{
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t ntri = 0;
  uint64_t nedg = 0;

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    nedg += ge->lines.size();
  }

  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    ntri += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(auto it = all.begin(); it != all.end(); it++) {
    m->vertices.coord[4 * count + 0] = (*it)->x();
    m->vertices.coord[4 * count + 1] = (*it)->y();
    m->vertices.coord[4 * count + 2] = (*it)->z();
    m->vertices.coord[4 * count + 3] = 0.0;
    v2c[*it] = count;
    c2v[count++] = *it;
  }
  all.clear();

  m->lines.num = m->lines.size = nedg;
  uint64_t index = 0;

  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint32_t)));

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      m->lines.node[2 * index + 0] = v2c[ge->lines[i]->getVertex(0)];
      m->lines.node[2 * index + 1] = v2c[ge->lines[i]->getVertex(1)];
      m->lines.color[index] = ge->tag();
      index++;
    }
  }

  m->triangles.num = m->triangles.size = ntri;
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.color,
                             (m->triangles.num) * sizeof(uint32_t)));

  index = 0;
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.color[index] = gf->tag();
      index++;
    }
  }
  return HXT_STATUS_OK;
}

// Builds, face by face, the v2c mapping from the *local* per-face vertex
// index (as used by Gmsh2HxtLocal) to a running global index that matches
// the order in which faces are visited by GModel::firstFace()..lastFace().
// Used to relate a per-face curvature computation back into the global
// nodalCurvature array indexed like the global HXTMesh built by Gmsh2Hxt.
static HXTStatus Gmsh2HxtGlobal(std::vector<GFace *> &faces, HXTMesh *m,
                                std::map<MVertex *, uint32_t> &v2c,
                                std::vector<MVertex *> &c2v)
{
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t cumsum = 0;
  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    cumsum += ge->lines.size();
  }
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    cumsum += gf->triangles.size();
  }

  c2v.resize(cumsum);
  all.clear();

  size_t count_c2v2 = 0;
  for(size_t j = 0; j < faces.size(); ++j) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
    size_t count = 0;
    for(auto it = all.begin(); it != all.end(); it++) {
      v2c[*it] = count++;
      c2v[count_c2v2++] = *it;
    }
    all.clear();
  }

  return HXT_STATUS_OK;
}

/* ==========================================================================
   Context closed over by the refinement/assignment predicates and by
   computeFeatureSize(): the successor of ForestOptions, without anything
   p4est- or anisotropy-specific.
   ========================================================================== */

namespace {

struct SizeFieldContext {
  double hmin = -1.;
  double hmax = -1.;
  double hbulk = -1.;
  double gradation = 1.1;
  int nodePerTwoPi = 20;
  int nodePerGap = 0;
  RTree<uint64_t, double, 3> *triRTree = nullptr;
  HXTMesh *mesh = nullptr;
  std::vector<double> nodalCurvature; // 6 doubles per vertex: 2 principal
                                       // curvature vectors
  std::vector<double> nodeNormals; // 3 doubles per vertex
  std::vector<double> featureSizeAtVertices; // 1 double per vertex, DBL_MAX
                                              // where no feature constraint
};

} // namespace

/* ==========================================================================
   Medial axis / feature size (Dey-Zhao via Voronoi poles) -- ported nearly
   unchanged from automaticMeshSizeField.cpp's featureSize(); only the
   debug .pos file writes and the (pure drawing) sortClockwise/facet-ordering
   code have been dropped.
   ========================================================================== */

// To quickly sort 4 integers
static void sort4(int *d)
{
#define SWAP(x, y)                                                            \
  if(d[y] < d[x]) {                                                           \
    int tmp = d[x];                                                          \
    d[x] = d[y];                                                             \
    d[y] = tmp;                                                              \
  }
  SWAP(0, 1);
  SWAP(2, 3);
  SWAP(0, 2);
  SWAP(1, 3);
  SWAP(1, 2);
#undef SWAP
}

// Checks whether two MTetrahedra have a common face without creating MFaces
// (slow). Returns the index of the common face in t1 if any, -1 otherwise.
static int commonFaceTetFast(MTetrahedron *t1, MTetrahedron *t2)
{
  int t10 = t1->getVertex(0)->getNum();
  int t11 = t1->getVertex(1)->getNum();
  int t12 = t1->getVertex(2)->getNum();
  int t13 = t1->getVertex(3)->getNum();
  int t20 = t2->getVertex(0)->getNum();
  int t21 = t2->getVertex(1)->getNum();
  int t22 = t2->getVertex(2)->getNum();
  int t23 = t2->getVertex(3)->getNum();

  bool b0 = (t10 == t20) || (t10 == t21) || (t10 == t22) || (t10 == t23);
  bool b1 = (t11 == t20) || (t11 == t21) || (t11 == t22) || (t11 == t23);
  bool b2 = (t12 == t20) || (t12 == t21) || (t12 == t22) || (t12 == t23);
  bool b3 = (t13 == t20) || (t13 == t21) || (t13 == t22) || (t13 == t23);

  if(b0 + b1 + b2 + b3 < 3) { return -1; }
  else {
    int v1[4] = {t10, t11, t12, t13};
    int v1cpy[4] = {t10, t11, t12, t13};
    int v2[4] = {t20, t21, t22, t23};
    sort4(v1);
    sort4(v2);
    t10 = v1[0];
    t11 = v1[1];
    t12 = v1[2];
    t13 = v1[3];
    t20 = v2[0];
    t21 = v2[1];
    t22 = v2[2];
    t23 = v2[3];

    bool b00 = (t11 == t21) && (t12 == t22) && (t13 == t23);
    bool b01 = (t11 == t20) && (t12 == t22) && (t13 == t23);
    bool b02 = (t11 == t20) && (t12 == t21) && (t13 == t23);
    bool b03 = (t11 == t20) && (t12 == t21) && (t13 == t22);

    bool b10 = (t10 == t21) && (t12 == t22) && (t13 == t23);
    bool b11 = (t10 == t20) && (t12 == t22) && (t13 == t23);
    bool b12 = (t10 == t20) && (t12 == t21) && (t13 == t23);
    bool b13 = (t10 == t20) && (t12 == t21) && (t13 == t22);

    bool b20 = (t10 == t21) && (t11 == t22) && (t12 == t23);
    bool b21 = (t10 == t20) && (t11 == t22) && (t12 == t23);
    bool b22 = (t10 == t20) && (t11 == t21) && (t12 == t23);
    bool b23 = (t10 == t20) && (t11 == t21) && (t12 == t22);

    bool b30 = (t10 == t21) && (t11 == t22) && (t13 == t23);
    bool b31 = (t10 == t20) && (t11 == t22) && (t13 == t23);
    bool b32 = (t10 == t20) && (t11 == t21) && (t13 == t23);
    bool b33 = (t10 == t20) && (t11 == t21) && (t13 == t22);

    int missing = -1; // The vertex that is missing from the common face
    if(b00 || b01 || b02 || b03)
      missing = 0;
    else if(b10 || b11 || b12 || b13)
      missing = 1;
    else if(b20 || b21 || b22 || b23)
      missing = 3;
    else if(b30 || b31 || b32 || b33)
      missing = 2;

    if(missing >= 0) {
      if(v1cpy[0] == v1[missing])
        return 3;
      else if(v1cpy[1] == v1[missing])
        return 2;
      else if(v1cpy[2] == v1[missing])
        return 1;
      else if(v1cpy[3] == v1[missing])
        return 0;
    }

    return -1;
  }
}

// Computes the (approximate) medial axis of the geometry from the Delaunay
// tetrahedralization of the surface mesh vertices (ctx.mesh), and fills
// ctx.featureSizeAtVertices with a feature size hf at every mesh vertex
// bounding a thin gap (DBL_MAX elsewhere).
static void computeFeatureSize(SizeFieldContext &ctx)
{
  HXTMesh *mesh = ctx.mesh;
  int nLayersPerGap = ctx.nodePerGap;
  double hmin = ctx.hmin;
  double hmax = ctx.hmax;

  std::vector<MVertex *> allVertices;
  allVertices.reserve(mesh->vertices.num);
  std::vector<double> sizeAtVertices(mesh->vertices.num, DBL_MAX);
  for(size_t i = 0; i < mesh->vertices.num; ++i) {
    allVertices.push_back(new MVertex(mesh->vertices.coord[4 * i + 0],
                                      mesh->vertices.coord[4 * i + 1],
                                      mesh->vertices.coord[4 * i + 2]));
  }

  int firstVertex = allVertices[0]->getNum();

  // All (non-ghost) tets, and vertex -> incident-tet / incident-edge maps
  uint64_t count = 0;
  std::vector<MTetrahedron *> allTets;
  std::vector<std::vector<uint64_t> > tetIncidents(mesh->vertices.num);
  std::vector<std::vector<MEdge> > edgIncidents(mesh->vertices.num);

  for(size_t i = 0; i < mesh->tetrahedra.num; ++i) {
    if(mesh->tetrahedra.node[4 * i + 3] != HXT_GHOST_VERTEX) {
      allTets.push_back(
        new MTetrahedron(allVertices[mesh->tetrahedra.node[4 * i + 0]],
                         allVertices[mesh->tetrahedra.node[4 * i + 1]],
                         allVertices[mesh->tetrahedra.node[4 * i + 2]],
                         allVertices[mesh->tetrahedra.node[4 * i + 3]]));

      for(size_t j = 0; j < 4; ++j) {
        tetIncidents[mesh->tetrahedra.node[4 * i + j]].push_back(count);
      }
      for(size_t j = 0; j < 6; ++j) {
        MEdge e = allTets[count]->getEdge(j);
        edgIncidents[allTets[count]->getEdge(j).getVertex(0)->getNum() -
                     firstVertex]
          .push_back(e);
        edgIncidents[allTets[count]->getEdge(j).getVertex(1)->getNum() -
                     firstVertex]
          .push_back(e);
      }
      ++count;
    }
  }

  std::set<MEdge, MEdgeLessThan> axis;

  for(size_t i = 0; i < mesh->vertices.num; ++i) {
    // Pole of p: farthest circumcenter among the tets incident to p.
    SPoint3 pole(0., 0., 0.), tmp(0., 0., 0.),
      p(mesh->vertices.coord[4 * i + 0], mesh->vertices.coord[4 * i + 1],
        mesh->vertices.coord[4 * i + 2]);
    double d = 0.;

    for(size_t j = 0; j < tetIncidents[i].size(); ++j) {
      tmp = allTets[tetIncidents[i][j]]->circumcenter();
      if(p.distance(tmp) > d) pole = tmp;
      d = fmax(d, p.distance(tmp));
    }

    // Pole vector and the plane through p normal to it.
    SPoint3 vp = pole - p;
    double D = -(vp[0] * p[0] + vp[1] * p[1] + vp[2] * p[2]);
    SPoint3 p1(0., 0., -D / vp[2]);
    SPoint3 p2(0., -D / vp[1], 0.);

    std::vector<MFace> up; // umbrella
    double orientj, orientk;
    for(size_t j = 0; j < tetIncidents[i].size(); ++j) {
      uint64_t tetj = tetIncidents[i][j];
      SPoint3 cj = allTets[tetj]->circumcenter();
      for(size_t k = j; k < tetIncidents[i].size(); ++k) {
        uint64_t tetk = tetIncidents[i][k];
        if(tetj != tetk) {
          int indFace = commonFaceTetFast(allTets[tetj], allTets[tetk]);
          if(indFace >= 0) {
            SPoint3 ck = allTets[tetk]->circumcenter();
            orientj = robustPredicates::orient3d((double *)p, (double *)p1,
                                                 (double *)p2, (double *)cj);
            orientk = robustPredicates::orient3d((double *)p, (double *)p1,
                                                 (double *)p2, (double *)ck);
            if(orientj * orientk < 0) {
              up.push_back(allTets[tetj]->getFace(indFace));
            }
          }
        }
      }
    }

    double theta = M_PI / 8., rho = 8., maxAngle, minRatio, localAngle,
           alpha0, alpha1;
    std::vector<MEdge> checkedEdges;
    for(size_t j = 0; j < edgIncidents[i].size(); ++j) {
      MEdge e = edgIncidents[i][j];
      bool checked = false;
      for(size_t k = 0; k < checkedEdges.size(); ++k) {
        if(e == checkedEdges[k]) {
          checked = true;
          break;
        }
      }
      if(checked) continue;
      checkedEdges.push_back(e);

      maxAngle = 0.0;
      minRatio = DBL_MAX;

      uint32_t v0 = e.getVertex(0)->getNum() - firstVertex;
      uint32_t v1 = e.getVertex(1)->getNum() - firstVertex;
      if(v0 == i || v1 == i) {
        for(size_t l = 0; l < up.size(); ++l) {
          // Angle condition
          localAngle = angle(e.tangent(), up[l].normal());
          localAngle = fmin(localAngle, fabs(M_PI - localAngle));
          maxAngle = fmax(maxAngle, localAngle);

          // Ratio condition
          MTriangle tri(up[l].getVertex(0), up[l].getVertex(1),
                        up[l].getVertex(2));
          minRatio = fmin(minRatio, e.length() / tri.getOuterRadius());
        }

        if(maxAngle < M_PI / 2. - theta || minRatio > rho) {
          double *n0 = &ctx.nodeNormals[3 * v0];
          double *n1 = &ctx.nodeNormals[3 * v1];
          alpha0 = angle(SVector3(n0), e.tangent());
          alpha1 = angle(SVector3(n1), e.tangent());

          if(fmin(alpha0, fabs(M_PI - alpha0)) < M_PI / 8. &&
             fmin(alpha1, fabs(M_PI - alpha1)) < M_PI / 8.) {
            // Edge bounds a thin gap: constrain the size at its endpoints.
            auto ret = axis.insert(e);
            if(ret.second) {
              double h = e.length() / nLayersPerGap;
              h = fmax(h, hmin);
              h = fmin(h, hmax);
              sizeAtVertices[v0] = fmin(h, sizeAtVertices[v0]);
              sizeAtVertices[v1] = fmin(h, sizeAtVertices[v1]);
            }
          }
        }
      }
    }
  }

  ctx.featureSizeAtVertices = std::move(sizeAtVertices);

  for(MTetrahedron *t : allTets) delete t;
  for(MVertex *v : allVertices) delete v;
}

/* ==========================================================================
   Orchestration: OctreeSizeField::updateHXT()
   ========================================================================== */

HXTStatus OctreeSizeField::updateHXT()
{
  if(!updateNeeded) return HXT_STATUS_OK;

  if(_octree) {
    delete _octree;
    _octree = nullptr;
  }
  updateNeeded = false;

  GModel *gm = GModel::current();

  if(gm->getDim() != 3) {
    Msg::Error("OctreeSizeField (AutomaticMeshSizeField) is only "
               "implemented for 3D models");
    return HXT_STATUS_OK;
  }

  Msg::Info("Gradation = %f", _gradation);
  Msg::Info("Node density = %d", _nPointsPerCircle);
  if(_features && _nPointsPerGap > 0)
    Msg::Info("Layers per gap = %d", _nPointsPerGap);
  else
    Msg::Info("Layers per gap = %d : not detecting features.", _nPointsPerGap);

  std::vector<GRegion *> regions;
  for(auto it = gm->firstRegion(); it != gm->lastRegion(); ++it)
    regions.push_back(*it);

  if(regions.empty()) {
    Msg::Error("No volume in the model: OctreeSizeField needs at least one "
               "volume");
    return HXT_STATUS_OK;
  }

  std::vector<GFace *> faces;
  HXT_CHECK(getAllFacesOfAllRegions(regions, nullptr, faces));

  // Create global HXT mesh structure (surface mesh only, at this point)
  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));
  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  HXT_CHECK(Gmsh2Hxt(faces, mesh, v2c, c2v));

  if(mesh->vertices.num == 0) {
    Msg::Error("Surface mesh is empty");
    HXT_CHECK(hxtMeshDelete(&mesh));
    return HXT_STATUS_OK;
  }

  SizeFieldContext ctx;
  ctx.nodalCurvature.assign(6 * mesh->vertices.num, NAN);

  // Create a local HXT mesh for each GFace, and use it to compute curvature
  // per face, then assemble the result into the global nodalCurvature array
  std::vector<HXTMesh *> faceMeshes;
  faceMeshes.reserve(faces.size());
  for(size_t i = 0; i < faces.size(); ++i) {
    HXTMesh *meshFace;
    HXT_CHECK(hxtMeshCreate(&meshFace));
    std::vector<GFace *> oneFace;
    oneFace.push_back(faces[i]);
    std::map<MVertex *, uint32_t> v2cLoc;
    std::vector<MVertex *> c2vLoc;
    HXT_CHECK(Gmsh2HxtLocal(oneFace, meshFace, v2cLoc, c2vLoc));
    faceMeshes.push_back(meshFace);
  }

  std::map<MVertex *, uint32_t> v2c2;
  std::vector<MVertex *> c2v2;
  HXT_CHECK(Gmsh2HxtGlobal(faces, nullptr, v2c2, c2v2));

  size_t nVertices = 0;
  int counter = 0;
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    HXTMesh *meshFace = faceMeshes[counter++];
    if(meshFace == nullptr) {
      Msg::Error("meshFace == NULL");
      continue;
    }

    GFace *gf = *it;
    if(gf->triangles.empty()) continue;

    std::vector<SPoint3> nodes(meshFace->vertices.num);
    for(size_t i = 0; i < meshFace->vertices.num; ++i) {
      nodes[i] = SPoint3(meshFace->vertices.coord[(size_t)4 * i + 0],
                         meshFace->vertices.coord[(size_t)4 * i + 1],
                         meshFace->vertices.coord[(size_t)4 * i + 2]);
    }

    std::vector<int> tris(3 * meshFace->triangles.num);
    for(size_t i = 0; i < meshFace->triangles.num; ++i) {
      tris[3 * i + 0] = meshFace->triangles.node[3 * i + 0];
      tris[3 * i + 1] = meshFace->triangles.node[3 * i + 1];
      tris[3 * i + 2] = meshFace->triangles.node[3 * i + 2];
    }

    std::vector<std::pair<SVector3, SVector3> > curv;
    CurvatureRusinkiewicz(tris, nodes, curv);

    // Assemble curvature vectors of the face in the global nodalCurvature
    // array
    for(uint64_t i = 0; i < meshFace->vertices.num; ++i) {
      uint64_t nodeGlobal = v2c[c2v2[nVertices + i]];

      // Sanity check: the vertex of the face mesh and the corresponding
      // global vertex must be the same point.
      double x1 = meshFace->vertices.coord[(size_t)4 * i + 0];
      double y1 = meshFace->vertices.coord[(size_t)4 * i + 1];
      double z1 = meshFace->vertices.coord[(size_t)4 * i + 2];
      double x2 = mesh->vertices.coord[(size_t)4 * nodeGlobal + 0];
      double y2 = mesh->vertices.coord[(size_t)4 * nodeGlobal + 1];
      double z2 = mesh->vertices.coord[(size_t)4 * nodeGlobal + 2];
      if(!isPoint(x1, y1, z1, x2, y2, z2, 1e-12)) {
        Msg::Warning("OctreeSizeField: vertex mismatch while assembling "
                     "curvature (%.12e,%.12e,%.12e) vs (%.12e,%.12e,%.12e)",
                     x1, y1, z1, x2, y2, z2);
      }

      ctx.nodalCurvature[6 * nodeGlobal + 0] = curv[i].first[0];
      ctx.nodalCurvature[6 * nodeGlobal + 1] = curv[i].first[1];
      ctx.nodalCurvature[6 * nodeGlobal + 2] = curv[i].first[2];
      ctx.nodalCurvature[6 * nodeGlobal + 3] = curv[i].second[0];
      ctx.nodalCurvature[6 * nodeGlobal + 4] = curv[i].second[1];
      ctx.nodalCurvature[6 * nodeGlobal + 5] = curv[i].second[2];
    }

    nVertices += meshFace->vertices.num;
  }

  for(HXTMesh *fm : faceMeshes) HXT_CHECK(hxtMeshDelete(&fm));

  // Compute Delaunay tetrahedralization of the (empty) surface mesh
  HXTDelaunayOptions delaunayOptions = {nullptr, nullptr, 0, 0, 0, 2, 1, 0};
  HXT_CHECK(hxtEmptyMesh(mesh, &delaunayOptions));

  // Compute normal vectors (needed by the feature size / medial axis step)
  std::vector<int> tris(3 * mesh->triangles.num, 0);
  for(std::size_t i = 0; i < mesh->triangles.num; ++i) {
    tris[3 * i + 0] = mesh->triangles.node[3 * i + 0];
    tris[3 * i + 1] = mesh->triangles.node[3 * i + 1];
    tris[3 * i + 2] = mesh->triangles.node[3 * i + 2];
  }

  std::vector<SPoint3> nodes(mesh->vertices.num);
  for(size_t i = 0; i < mesh->vertices.num; ++i) {
    nodes[i] = SPoint3(mesh->vertices.coord[(size_t)4 * i + 0],
                       mesh->vertices.coord[(size_t)4 * i + 1],
                       mesh->vertices.coord[(size_t)4 * i + 2]);
  }

  std::vector<std::pair<SVector3, SVector3> > curv;
  // CurvatureRusinkiewicz's 4-argument overload indexes nodeNormals[] up to
  // 3*nVertices-1 without resizing it itself, so it must be pre-sized here.
  ctx.nodeNormals.assign(3 * mesh->vertices.num, 0.0);
  CurvatureRusinkiewicz(tris, nodes, curv, ctx.nodeNormals);

  // Bounding box of the triangles, added to an RTree for fast spatial
  // queries during refinement/coarsening/assignment
  RTree<uint64_t, double, 3> triRTree;
  HXTBbox bbox_triangle;
  for(uint64_t i = 0; i < mesh->triangles.num; ++i) {
    hxtBboxInit(&bbox_triangle);
    for(uint64_t j = 0; j < 3; ++j) {
      double coord[3];
      uint32_t node = mesh->triangles.node[3 * i + j];
      for(uint32_t k = 0; k < 3; ++k)
        coord[k] = mesh->vertices.coord[(size_t)4 * node + k];
      hxtBboxAddOne(&bbox_triangle, coord);
    }
    SBoundingBox3d cube_bbox(bbox_triangle.min[0], bbox_triangle.min[1],
                             bbox_triangle.min[2], bbox_triangle.max[0],
                             bbox_triangle.max[1], bbox_triangle.max[2]);
    triRTree.Insert((double *)(cube_bbox.min()), (double *)(cube_bbox.max()),
                    i);
  }

  // Bounding box of the mesh
  HXTBbox bbox_mesh;
  hxtBboxInit(&bbox_mesh);
  hxtBboxAdd(&bbox_mesh, mesh->vertices.coord, mesh->vertices.num);
  SBoundingBox3d meshBBox(bbox_mesh.min[0], bbox_mesh.min[1], bbox_mesh.min[2],
                          bbox_mesh.max[0], bbox_mesh.max[1],
                          bbox_mesh.max[2]);

  // Set the bulk size and the min/max size from the bbox, if not
  // user-specified
  if(_hbulk < 0 || _hmin < 0) {
    double L = -1.0;
    for(int i = 0; i < 3; ++i)
      L = fmax(L, meshBBox.max()[i] - meshBBox.min()[i]);
    if(_hbulk < 0) _hbulk = L / 20.;
    if(_hmin < 0) _hmin = L / 1000.;
    Msg::Info("Bulk size is set to %f", _hbulk);
    Msg::Info("Min  size is set to %f", _hmin);
  }
  if(_hmax < 0) _hmax = _hbulk;

  ctx.hmin = _hmin;
  ctx.hmax = _hmax;
  ctx.hbulk = _hbulk;
  ctx.gradation = _gradation;
  ctx.nodePerTwoPi = _nPointsPerCircle;
  ctx.nodePerGap = _nPointsPerGap;
  ctx.triRTree = &triRTree;
  ctx.mesh = mesh;
  ctx.featureSizeAtVertices.assign(mesh->vertices.num, DBL_MAX);

  // Build the octree over the (enlarged) bounding box of the mesh. The
  // paper stretches the bbox by 1.5x in every direction before building the
  // tree; SizeOctree's constructor further cubifies it internally.
  SBoundingBox3d octreeBBox = meshBBox;
  octreeBBox *= 1.5;
  _octree = new SizeOctree(octreeBBox);
  // Cells with no intersection with the surface mesh inherit this starting
  // value through refinement/balancing, mirroring the old bulkSize()
  // callback used to initialize every p4est cell.
  _octree->root()->h = _hbulk;

  if(_features && _nPointsPerGap > 0) {
    Msg::Info("Detecting features...");
    computeFeatureSize(ctx);
  }

  if(_nPointsPerCircle > 0) {
    Msg::Info("Refining octree...");

    SizeOctree &octree = *_octree;

    // Refine down to at least hbulk everywhere.
    octree.refineWhile([&](const SizeOctant *o) -> bool {
      return 2. * o->halfWidth > ctx.hbulk;
    });

    // Refine further according to curvature and feature size near the
    // surface mesh.
    octree.refineWhile([&](const SizeOctant *o) -> bool {
      double h = 2. * o->halfWidth;
      SBoundingBox3d bb = octree.bbox(o);
      double minB[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
      double maxB[3] = {bb.max().x(), bb.max().y(), bb.max().z()};

      std::vector<uint64_t> candidates;
      ctx.triRTree->Search(minB, maxB, rtreeCallback, &candidates);
      if(candidates.empty()) return false;

      double kmax = -1.e22;
      double hf = DBL_MAX;
      for(uint64_t tri : candidates) {
        for(int i = 0; i < 3; ++i) {
          uint32_t node = ctx.mesh->triangles.node[(size_t)3 * tri + i];
          double *v1 = &ctx.nodalCurvature[6 * node];
          double *v2 = &ctx.nodalCurvature[6 * node + 3];
          double k1, k2;
          norme2(v1, &k1);
          norme2(v2, &k2);
          kmax = fmax(kmax, fmax(k1, k2));
          hf = fmin(hf, ctx.featureSizeAtVertices[node]);
        }
      }

      double hc = 2 * M_PI / (ctx.nodePerTwoPi * kmax);
      double nElemPerCell = 2;
      return h > fmin(hc / nElemPerCell, hf) && h >= ctx.hmin;
    });

    // Coarsen back cells that do not touch the surface mesh and whose
    // merged size would still be <= hbulk.
    octree.coarsenWhile([&](const SizeOctant *cand) -> bool {
      SBoundingBox3d bb = octree.bbox(cand);
      double minB[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
      double maxB[3] = {bb.max().x(), bb.max().y(), bb.max().z()};
      std::vector<uint64_t> candidates;
      ctx.triRTree->Search(minB, maxB, rtreeCallback, &candidates);
      if(!candidates.empty()) return false;
      double mergedH = 2. * cand->halfWidth;
      return mergedH <= ctx.hbulk;
    });

    // Restore the 2:1 balance invariant before assigning final sizes, so
    // that newly-balanced octants also get a correct size below.
    octree.balance();

    // Assign the final size on every (post-balance) leaf.
    octree.assignSizes([&](const SizeOctant *o) -> double {
      SBoundingBox3d bb = octree.bbox(o);
      double minB[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
      double maxB[3] = {bb.max().x(), bb.max().y(), bb.max().z()};

      std::vector<uint64_t> candidates;
      ctx.triRTree->Search(minB, maxB, rtreeCallback, &candidates);

      if(!candidates.empty()) {
        double kmax = -1.0e22;
        double hf = DBL_MAX;
        for(uint64_t tri : candidates) {
          for(int i = 0; i < 3; ++i) {
            uint32_t node = ctx.mesh->triangles.node[(size_t)3 * tri + i];
            double *v1 = &ctx.nodalCurvature[6 * node];
            double *v2 = &ctx.nodalCurvature[6 * node + 3];
            double k1, k2;
            norme2(v1, &k1);
            norme2(v2, &k2);
            kmax = fmax(kmax, fmax(k1, k2));
            hf = fmin(hf, ctx.featureSizeAtVertices[node]);
          }
        }
        return fmax(ctx.hmin,
                    fmin(ctx.hmax,
                         fmin(hf, 2 * M_PI / (ctx.nodePerTwoPi * kmax))));
      }
      else {
        return fmax(ctx.hmin, fmin(ctx.hmax, o->h));
      }
    });
  }

  if(_smoothing) {
    Msg::Info("Smoothing size gradient...");
    _octree->sizeSmoothing(_gradation - 1.0, 100);
  }

  double elemEstimation = _octree->estimateElementCount();
  Msg::Info("Estimated number of tetrahedra in the bounding box : %ld",
            (long)ceil(elemEstimation));

  if(_exportPos) {
    std::string posFile = GModel::current()->getName() + ".pos";
    _octree->exportPos(posFile);
  }

  HXT_CHECK(hxtMeshDelete(&mesh));

  return HXT_STATUS_OK;
}

void OctreeSizeField::update()
{
  HXTStatus s = updateHXT();
  if(s != HXT_STATUS_OK)
    Msg::Error("Something went wrong when computing the octree size field");
}

double OctreeSizeField::operator()(double X, double Y, double Z, GEntity *ge)
{
  if(!_octree) return MAX_LC;
  double val = _octree->eval(SPoint3(X, Y, Z));
  return fmax(_hmin, fmin(_hmax, val));
}

OctreeSizeField::~OctreeSizeField()
{
  if(_octree) delete _octree;
}

#else

void OctreeSizeField::update()
{
  Msg::Error("Gmsh has to be compiled with HXT to use the "
             "AutomaticMeshSizeField (OctreeSizeField)");
}

double OctreeSizeField::operator()(double X, double Y, double Z, GEntity *ge)
{
  Msg::Error("Gmsh has to be compiled with HXT to use the "
             "AutomaticMeshSizeField (OctreeSizeField)");
  return 1.e22;
}

OctreeSizeField::~OctreeSizeField() {}

#endif
