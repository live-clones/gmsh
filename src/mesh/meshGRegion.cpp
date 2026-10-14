// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshGRegion.h"
#include "meshGRegionHxt.h"
#include "meshGRegionParallelDelaunay.h"
#include "meshGRegionNetgen.h"
#include "meshGRegionMMG.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "meshGRegionBoundaryRecovery.h"
#include "meshGRegionDelaunay.h"
#include "meshRelocateVertex.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "ExtrudeParams.h"
#include "OS.h"
#include "Context.h"

bool orientRegionBoundary(GRegion *gr, std::map<GFace *, int> &inward)
{
  inward.clear();
  std::vector<GFace *> faces = gr->faces();
  const std::size_t nf = faces.size();
  if(!nf) return false;
  // the edges of the surface elements on the model curves, with the surface
  // and the direction of each use (the other edges are interior to a surface)
  struct Use {
    std::size_t face;
    int dir;
  };
  std::map<std::pair<MVertex *, MVertex *>, std::vector<Use>> edges;
  for(std::size_t i = 0; i < nf; i++) {
    auto addElement = [&](MElement *e) {
      const int n = e->getNumPrimaryVertices();
      for(int k = 0; k < n; k++) {
        MVertex *a = e->getVertex(k), *b = e->getVertex((k + 1) % n);
        if(a->onWhat()->dim() > 1 || b->onWhat()->dim() > 1) continue;
        if(a < b)
          edges[{a, b}].push_back({i, 1});
        else
          edges[{b, a}].push_back({i, -1});
      }
    };
    for(MTriangle *t : faces[i]->triangles) addElement(t);
    for(MQuadrangle *q : faces[i]->quadrangles) addElement(q);
  }
  // the surfaces sharing an edge must traverse it in opposite directions
  std::vector<std::vector<std::pair<std::size_t, int>>> adjacent(nf);
  for(auto &e : edges) {
    if(e.second.size() != 2 || e.second[0].face == e.second[1].face) continue;
    const int rel = -e.second[0].dir * e.second[1].dir;
    adjacent[e.second[0].face].push_back({e.second[1].face, rel});
    adjacent[e.second[1].face].push_back({e.second[0].face, rel});
  }
  std::vector<int> sign(nf, 0), shell(nf, -1);
  std::vector<double> volume;
  for(std::size_t i = 0; i < nf; i++) {
    if(sign[i]) continue;
    const int c = (int)volume.size();
    volume.push_back(0.);
    sign[i] = 1;
    shell[i] = c;
    std::vector<std::size_t> stack = {i};
    while(!stack.empty()) {
      const std::size_t f = stack.back();
      stack.pop_back();
      for(auto &a : adjacent[f]) {
        const int want = sign[f] * a.second;
        if(!sign[a.first]) {
          sign[a.first] = want;
          shell[a.first] = c;
          stack.push_back(a.first);
        }
        else if(sign[a.first] != want) {
          return false;
        }
      }
    }
  }
  // the volume enclosed by each shell, from its oriented elements
  for(std::size_t i = 0; i < nf; i++) {
    double v = 0.;
    auto addTriangle = [&](MVertex *a, MVertex *b, MVertex *c) {
      SVector3 pa(a->point()), pb(b->point()), pc(c->point());
      v += dot(pa, crossprod(pb, pc)) / 6.;
    };
    for(MTriangle *t : faces[i]->triangles)
      addTriangle(t->getVertex(0), t->getVertex(1), t->getVertex(2));
    for(MQuadrangle *q : faces[i]->quadrangles) {
      addTriangle(q->getVertex(0), q->getVertex(1), q->getVertex(2));
      addTriangle(q->getVertex(0), q->getVertex(2), q->getVertex(3));
    }
    volume[shell[i]] += sign[i] * v;
  }
  int outer = 0;
  for(int c = 1; c < (int)volume.size(); c++)
    if(std::abs(volume[c]) > std::abs(volume[outer])) outer = c;
  if(volume[outer] == 0.) return false;
  for(std::size_t i = 0; i < nf; i++) {
    const double v = volume[shell[i]];
    if(v == 0.) return false;
    // a positive volume: the oriented shell points away from what it
    // encloses, the volume itself for the outer shell, a cavity otherwise
    const int out = (sign[i] * v > 0.) ? 1 : -1;
    inward[faces[i]] = (shell[i] == outer) ? -out : out;
  }
  return true;
}

void splitQuadRecovery::add(const MFace &f, MVertex *v, GFace *gf)
{
  _quad[f] = v;
  if(v) {
    MFace f0(f.getVertex(0), f.getVertex(1), v);
    MFace f1(f.getVertex(1), f.getVertex(2), v);
    MFace f2(f.getVertex(2), f.getVertex(3), v);
    MFace f3(f.getVertex(3), f.getVertex(0), v);
    _tri[f0] = gf;
    _tri[f1] = gf;
    _tri[f2] = gf;
    _tri[f3] = gf;
  }
  else {
    MTriangle t0(f.getVertex(0), f.getVertex(1), f.getVertex(2));
    MTriangle t1(f.getVertex(0), f.getVertex(2), f.getVertex(3));
    double qual01 = std::min(t0.gammaShapeMeasure(), t1.gammaShapeMeasure());
    MTriangle t2(f.getVertex(1), f.getVertex(2), f.getVertex(3));
    MTriangle t3(f.getVertex(0), f.getVertex(1), f.getVertex(3));
    double qual23 = std::min(t2.gammaShapeMeasure(), t3.gammaShapeMeasure());
    if (qual01 > qual23) {
      MFace f0(f.getVertex(0), f.getVertex(1), f.getVertex(2));
      MFace f1(f.getVertex(0), f.getVertex(2), f.getVertex(3));
      _tri[f0] = gf;
      _tri[f1] = gf;
    }
    else {
      MFace f0(f.getVertex(1), f.getVertex(2), f.getVertex(3));
      MFace f1(f.getVertex(0), f.getVertex(1), f.getVertex(3));
      _tri[f0] = gf;
      _tri[f1] = gf;
    }
  }
}

int splitQuadRecovery::buildPyramids(GModel *gm)
{
  if(_quad.empty()) return 0;

  Msg::Info("Generating pyramids for hybrid mesh...");
  int npyram = 0;
  int ntrihedra = 0;
  for(auto it = gm->firstRegion(); it != gm->lastRegion(); it++) {
    GRegion *gr = *it;
    if(gr->meshAttributes.method == MESH_TRANSFINITE) continue;
    if(gr->isFullyDiscrete()) {
      continue;
    }
    ExtrudeParams *ep = gr->meshAttributes.extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) continue;

    std::vector<GFace *> faces = gr->faces();
    for(std::size_t i = 0; i < faces.size(); i++) {
      GFace *gf = faces[i];
      bool reported = false;
      for(std::size_t j = 0; j < gf->quadrangles.size(); j++) {
        auto it2 = _quad.find(gf->quadrangles[j]->getFace(0));
        if(it2 != _quad.end()) {
          if(it2->second) {
            if(it2->second->onWhat()->dim() == 3) {
              // the apex is already in the volume on the other side of the
              // quadrangle: it cannot be the apex of a second pyramid (nor
              // be owned, and deleted, by two volumes)
              if(!reported)
                Msg::Error("Surface %d with quadrangles bounds volumes %d and "
                           "%d: non-manifold quadrangle boundaries are not "
                           "supported, no pyramids in volume %d",
                           gf->tag(), it2->second->onWhat()->tag(), gr->tag(),
                           gr->tag());
              reported = true;
              continue;
            }
            npyram++;
            gr->pyramids.push_back(new MPyramid(
              it2->first.getVertex(0), it2->first.getVertex(1),
              it2->first.getVertex(2), it2->first.getVertex(3), it2->second));
            gr->mesh_vertices.push_back(it2->second);
            it2->second->setEntity(gr);
          }
          else {
            ntrihedra++;
            gr->trihedra.push_back(new MTrihedron(
              it2->first.getVertex(1), it2->first.getVertex(2),
              it2->first.getVertex(3), it2->first.getVertex(0)));
          }
        }
      }
    }
  }
  Msg::Info("Done generating %d pyramids and %d trihedra for hybrid mesh",
            npyram, ntrihedra);
  return npyram + ntrihedra;
}

static void _deleteUnusedVertices(GRegion *gr)
{
  // deduplicate the tet corners first (through the vertex indices set by the
  // refinement), so that only the unique vertices need to be sorted - on
  // inline keys, as sorting pointers with MVertexPtrLessThan reads the
  // vertex numbers through the pointers at each comparison
  std::vector<std::pair<std::size_t, MVertex *> > allverts;
  std::vector<std::uint8_t> seen;
  bool haveIndices = true;
  for(std::size_t i = 0; i < gr->tetrahedra.size() && haveIndices; i++) {
    for(int j = 0; j < 4; j++) {
      MVertex *v = gr->tetrahedra[i]->getVertex(j);
      if(v->onWhat() != gr) continue;
      const long idx = v->getIndex();
      if(idx < 0) {
        haveIndices = false;
        break;
      }
      if((std::size_t)idx >= seen.size()) seen.resize(idx + 1, 0);
      if(!seen[idx]) {
        seen[idx] = 1;
        allverts.push_back(std::make_pair(v->getNum(), v));
      }
    }
  }
  if(!haveIndices) {
    allverts.clear();
    allverts.reserve(4 * gr->tetrahedra.size());
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
      for(int j = 0; j < 4; j++) {
        MVertex *v = gr->tetrahedra[i]->getVertex(j);
        if(v->onWhat() == gr)
          allverts.push_back(std::make_pair(v->getNum(), v));
      }
    }
  }
  std::sort(allverts.begin(), allverts.end());
  allverts.erase(std::unique(allverts.begin(), allverts.end()),
                 allverts.end());
  // FIXME: investigate crash on exit if we delete the unused vertices
  // (e.g. t16.geo)
  gr->mesh_vertices.clear();
  gr->mesh_vertices.reserve(allverts.size());
  for(auto &p : allverts) gr->mesh_vertices.push_back(p.second);
}

regionGroupBoundary::regionGroupBoundary(std::vector<GRegion *> &regions)
  : _gr(regions[0])
{
  _faces = _gr->faces();
  _embEdges = _gr->embeddedEdges();
  _embVertices = _gr->embeddedVertices();

  std::set<GFace *, GEntityPtrLessThan> allFacesSet;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    allFacesSet.insert(f.begin(), f.end());
    allFacesSet.insert(f_e.begin(), f_e.end());
  }

  // replace faces with compounds if elements from compound surface meshes are
  // not reclassified on the original surfaces
  if(CTX::instance()->mesh.compoundClassify == 0) {
    std::set<GFace *, GEntityPtrLessThan> comp;
    for(auto it = allFacesSet.begin(); it != allFacesSet.end(); it++) {
      GFace *gf = *it;
      if(!gf->compoundSurface)
        comp.insert(gf);
      else if(gf->compoundSurface)
        comp.insert(gf->compoundSurface);
    }
    allFacesSet = comp;
  }

  allFaces.assign(allFacesSet.begin(), allFacesSet.end());
  _gr->set(allFaces);

  std::set<GEdge *, GEntityPtrLessThan> allEmbEdgesSet;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GEdge *> const &e = regions[i]->embeddedEdges();
    allEmbEdgesSet.insert(e.begin(), e.end());
  }
  _gr->embeddedEdges().assign(allEmbEdgesSet.begin(), allEmbEdgesSet.end());

  std::set<GVertex *> allEmbVerticesSet;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GVertex *> const &e = regions[i]->embeddedVertices();
    allEmbVerticesSet.insert(e.begin(), e.end());
  }
  _gr->embeddedVertices().assign(allEmbVerticesSet.begin(),
                                 allEmbVerticesSet.end());
}

regionGroupBoundary::~regionGroupBoundary()
{
  // restore set of faces and embedded edges/vertices
  if(CTX::instance()->mesh.compoundClassify == 0) {
    std::set<GFace *, GEntityPtrLessThan> comp;
    for(std::size_t i = 0; i < _faces.size(); i++) {
      GFace *gf = _faces[i];
      if(!gf->compoundSurface)
        comp.insert(gf);
      else if(gf->compoundSurface)
        comp.insert(gf->compoundSurface);
    }
    std::vector<GFace *> lcomp(comp.begin(), comp.end());
    _gr->set(lcomp);
  }
  else {
    _gr->set(_faces);
  }
  _gr->embeddedEdges() = _embEdges;
  _gr->embeddedVertices() = _embVertices;
}

void MeshDelaunayVolume(std::vector<GRegion *> &regions)
{
  if(regions.empty()) return;

  if(CTX::instance()->mesh.algo3d == ALGO_3D_HXT) {
    if(meshGRegionHxt(regions) != 0) { Msg::Error("HXT 3D mesh failed"); }
    return;
  }

  if(CTX::instance()->mesh.algo3d == ALGO_3D_PDEL3D) {
    int ret = meshGRegionParallelDelaunay(regions);
    if(ret == 1) Msg::Error("Parallel Delaunay 3D mesh failed");
    if(ret != 2) return;
    Msg::Warning("Falling back to Delaunay (del3d)");
  }
  if(CTX::instance()->mesh.algo3d != ALGO_3D_RTREE &&
     CTX::instance()->mesh.algo3d != ALGO_3D_DELAUNAY &&
     CTX::instance()->mesh.algo3d != ALGO_3D_PDEL3D &&
     CTX::instance()->mesh.algo3d != ALGO_3D_INITIAL_ONLY &&
     CTX::instance()->mesh.algo3d != ALGO_3D_MMG3D)
    return;

  GRegion *gr = regions[0];
  splitQuadRecovery sqr(CTX::instance()->mesh.optimizePyramids >= -2);
  std::vector<GFace *> allFaces;
  bool success;
  {
    // the recovery works on regions[0] with the boundary of the whole group
    regionGroupBoundary group(regions);
    allFaces = group.allFaces;
    success = meshGRegionBoundaryRecovery(gr, &sqr);
  }

  // sort triangles in all model faces in order to be able to search in vectors
  auto itf = allFaces.begin();
  while(itf != allFaces.end()) {
    std::sort((*itf)->triangles.begin(), (*itf)->triangles.end(),
              compareMTriangleLexicographic());
    ++itf;
  }

  if(!success) return;

  // now do insertion of points
  if(CTX::instance()->mesh.algo3d == ALGO_3D_MMG3D) {
    // boundary recovery on a connected group of regions leaves every
    // tetrahedron in regions[0]->tetrahedra; distribute them to their true
    // owning region before invoking MMG3D
    classifyTetrahedraInRegions(regions, &sqr);
    if(regions.size() > 1 && CTX::instance()->mesh.mmg3dCombineDomains) {
      refineMeshMMGGroup(regions, allFaces);
    }
    else {
      // must stay sequential: MMG3D is not safe to call concurrently from
      // multiple threads (two threads independently running
      // MMG3D_mmg3dlib segfault reliably). This is not affected by
      // General.NumThreads, which never parallelizes this loop or the
      // per-region-group loop above it -- only the 1D/2D meshing phases
      // and the (mutually exclusive) HXT 3D algorithm honor it.
      for(std::size_t i = 0; i < regions.size(); i++) {
        refineMeshMMG(regions[i]);
      }
    }
  }
  else if(CTX::instance()->mesh.algo3d != ALGO_3D_INITIAL_ONLY &&
          CTX::instance()->mesh.algo3d != ALGO_3D_RTREE) {
    insertVerticesInRegion(gr, CTX::instance()->mesh.maxIterDelaunay3D, 1.,
                           true, &sqr);
    for(auto gr : regions) _deleteUnusedVertices(gr);

    int nHybrid = sqr.buildPyramids(gr->model());
    if(nHybrid && sqr.doWeCreatePyramids()) {
      //      Msg::Info("Optimizing pyramids for hybrid mesh...");
      gr->model()->setAllVolumesPositive();
      RelocateVerticesOfPyramids(regions, 3);
      // RelocateVertices(regions, 3);
      //      Msg::Info("Done optimizing pyramids for hybrid mesh");
    }

    // the mesh generator leaves the optimization of pdel3d meshes to pdel3d:
    // optimize the ones it gave up on here
    if(CTX::instance()->mesh.algo3d == ALGO_3D_PDEL3D) {
      for(int i = 0; i < CTX::instance()->mesh.optimize; i++)
        for(auto r : regions) optimizeMeshGRegion()(r);
    }

    // test:
    // bool createBoundaryLayerOneLayer(GRegion *gr, std::vector<GFace *> &
    // bls); createBoundaryLayerOneLayer(gr, allFaces);
  }
}

void deMeshGRegion::operator()(GRegion *gr)
{
  if(gr->isFullyDiscrete()) return;
  gr->deleteMesh();
}

void meshGRegion::operator()(GRegion *gr)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(gr->isFullyDiscrete()) return;
  if(gr->meshAttributes.method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !gr->getVisibility()) return;
  if(CTX::instance()->mesh.meshOnlyEmpty && gr->getNumMeshElements()) return;

  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh) return;

  // destroy the mesh if it exists
  deMeshGRegion dem;
  dem(gr);

  if(MeshTransfiniteVolume(gr)) return;

  if(CTX::instance()->mesh.algo3d != ALGO_3D_FRONTAL) {
    delaunay.push_back(gr);
  }
  else if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL) {
    meshGRegionNetgen(gr);
  }
}


void optimizeMeshGRegion::operator()(GRegion *gr, bool always)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(!always && gr->isFullyDiscrete()) return;

  // don't optimize extruded meshes
  if(gr->meshAttributes.method == MESH_TRANSFINITE) return;
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;

  Msg::Info("Optimizing volume %d", gr->tag());
  optimizeMesh(gr, qmTetrahedron::QMTET_GAMMA);
}

bool buildFaceSearchStructure(GModel *model, fs_cont &search,
                              bool onlyTriangles)
{
  search.clear();

  std::set<GFace *> faces_to_consider;
  auto rit = model->firstRegion();
  while(rit != model->lastRegion()) {
    std::vector<GFace *> _faces = (*rit)->faces();
    faces_to_consider.insert(_faces.begin(), _faces.end());
    rit++;
  }

  auto fit = faces_to_consider.begin();
  while(fit != faces_to_consider.end()) {
    for(std::size_t i = 0; i < (*fit)->getNumMeshElements(); i++) {
      MFace ff = (*fit)->getMeshElement(i)->getFace(0);
      if(!onlyTriangles || ff.getNumVertices() == 3) search[ff] = *fit;
    }
    ++fit;
  }
  return true;
}

bool buildEdgeSearchStructure(GModel *model, es_cont &search)
{
  search.clear();

  auto eit = model->firstEdge();
  while(eit != model->lastEdge()) {
    for(std::size_t i = 0; i < (*eit)->lines.size(); i++) {
      MVertex *p1 = (*eit)->lines[i]->getVertex(0);
      MVertex *p2 = (*eit)->lines[i]->getVertex(1);
      MVertex *p = std::min(p1, p2);
      search.insert(std::pair<MVertex *, std::pair<MLine *, GEdge *> >(
        p, std::pair<MLine *, GEdge *>((*eit)->lines[i], *eit)));
    }
    ++eit;
  }
  return true;
}

GFace *findInFaceSearchStructure(MVertex *p1, MVertex *p2, MVertex *p3,
                                 const fs_cont &search)
{
  MFace ff(p1, p2, p3);
  auto it = search.find(ff);
  if(it == search.end()) return nullptr;
  return it->second;
}

GFace *findInFaceSearchStructure(const MFace &ff, const fs_cont &search)
{
  auto it = search.find(ff);
  if(it == search.end()) return nullptr;
  return it->second;
}

GEdge *findInEdgeSearchStructure(MVertex *p1, MVertex *p2,
                                 const es_cont &search)
{
  MVertex *p = std::min(p1, p2);

  for(auto it = search.lower_bound(p); it != search.upper_bound(p); ++it) {
    MLine *l = it->second.first;
    GEdge *ge = it->second.second;
    if((l->getVertex(0) == p1 || l->getVertex(0) == p2) &&
       (l->getVertex(1) == p1 || l->getVertex(1) == p2))
      return ge;
  }
  return nullptr;
}
