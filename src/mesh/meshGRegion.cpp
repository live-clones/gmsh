// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshGRegion.h"
#include "meshGRegionHxt.h"
#include "meshGRegionNetgen.h"
#include "meshGRegionMMG.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "meshGRegionBoundaryRecovery.h"
#include "meshGRegionDelaunayInsertion.h"
#include "meshRelocateVertex.h"
#include "meshUntangle.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "ExtrudeParams.h"
#include "OS.h"
#include "Context.h"

void splitQuadRecovery::add(const MFace &f, MVertex *v, GFace *gf)
{
  _quad[f] = v;
  MFace f0(f.getVertex(0), f.getVertex(1), v);
  MFace f1(f.getVertex(1), f.getVertex(2), v);
  MFace f2(f.getVertex(2), f.getVertex(3), v);
  MFace f3(f.getVertex(3), f.getVertex(0), v);
  _tri[f0] = gf;
  _tri[f1] = gf;
  _tri[f2] = gf;
  _tri[f3] = gf;
}

int splitQuadRecovery::buildPyramids(GModel *gm)
{
  if(_quad.empty()) return 0;

  Msg::Info("Generating pyramids for hybrid mesh...");
  int npyram = 0;
  for(auto it = gm->firstRegion(); it != gm->lastRegion(); it++) {
    GRegion *gr = *it;
    if(gr->meshAttributes.method == MESH_TRANSFINITE) continue;
    if(gr->isFullyDiscrete()) continue;
    ExtrudeParams *ep = gr->meshAttributes.extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) continue;

    std::vector<GFace *> faces = gr->faces();
    for(std::size_t i = 0; i < faces.size(); i++) {
      GFace *gf = faces[i];
      for(std::size_t j = 0; j < gf->quadrangles.size(); j++) {
        auto it2 = _quad.find(gf->quadrangles[j]->getFace(0));
        if(it2 != _quad.end()) {
          npyram++;
          gr->pyramids.push_back(new MPyramid(
            it2->first.getVertex(0), it2->first.getVertex(1),
            it2->first.getVertex(2), it2->first.getVertex(3), it2->second));
          gr->mesh_vertices.push_back(it2->second);
          if(it2->second->onWhat()->dim() == 3) {
            Msg::Error(
              "Pyramid top vertex already classified on volume %d (!= %d) - "
              "non-manifold quad boundaries not supported yet",
              it2->second->onWhat()->tag(), gr->tag());
          }
          else {
            it2->second->setEntity(gr);
          }
        }
      }
    }
  }
  Msg::Info("Done generating %d pyramids for hybrid mesh", npyram);
  return npyram;
}

void MeshDelaunayVolume(std::vector<GRegion *> &regions)
{
  if(regions.empty()) return;

  if(CTX::instance()->mesh.algo3d == ALGO_3D_HXT) {
    if(meshGRegionHxt(regions) != 0) { Msg::Error("HXT 3D mesh failed"); }
    return;
  }

  if(CTX::instance()->mesh.algo3d != ALGO_3D_RTREE &&
     CTX::instance()->mesh.algo3d != ALGO_3D_DELAUNAY &&
     CTX::instance()->mesh.algo3d != ALGO_3D_INITIAL_ONLY &&
     CTX::instance()->mesh.algo3d != ALGO_3D_MMG3D)
    return;

  GRegion *gr = regions[0];
  std::vector<GFace *> faces = gr->faces();

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

  std::vector<GFace *> allFaces(allFacesSet.begin(), allFacesSet.end());
  gr->set(allFaces);

  std::set<GEdge *, GEntityPtrLessThan> allEmbEdgesSet;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GEdge *> const &e = regions[i]->embeddedEdges();
    allEmbEdgesSet.insert(e.begin(), e.end());
  }
  std::vector<GEdge *> allEmbEdges(allEmbEdgesSet.begin(),
                                   allEmbEdgesSet.end());
  std::vector<GEdge *> oldEmbEdges = gr->embeddedEdges();
  gr->embeddedEdges() = allEmbEdges;

  std::set<GVertex *> allEmbVerticesSet;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GVertex *> const &e = regions[i]->embeddedVertices();
    allEmbVerticesSet.insert(e.begin(), e.end());
  }
  std::vector<GVertex *> allEmbVertices(allEmbVerticesSet.begin(),
                                        allEmbVerticesSet.end());
  std::vector<GVertex *> oldEmbVertices = gr->embeddedVertices();
  gr->embeddedVertices() = allEmbVertices;

  splitQuadRecovery sqr;
  bool success = meshGRegionBoundaryRecovery(gr, &sqr);

  // sort triangles in all model faces in order to be able to search in vectors
  auto itf = allFaces.begin();
  while(itf != allFaces.end()) {
    std::sort((*itf)->triangles.begin(), (*itf)->triangles.end(),
              compareMTriangleLexicographic());
    ++itf;
  }

  // restore set of faces and embedded edges/vertices
  if(CTX::instance()->mesh.compoundClassify == 0) {
    std::set<GFace *, GEntityPtrLessThan> comp;
    for(std::size_t i = 0; i < faces.size(); i++) {
      GFace *gf = faces[i];
      if(!gf->compoundSurface)
        comp.insert(gf);
      else if(gf->compoundSurface)
        comp.insert(gf->compoundSurface);
    }
    std::vector<GFace *> lcomp(comp.begin(), comp.end());
    gr->set(lcomp);
  }
  else {
    gr->set(faces);
  }
  gr->embeddedEdges() = oldEmbEdges;
  gr->embeddedVertices() = oldEmbVertices;

  if(!success) return;

  // now do insertion of points
  if(CTX::instance()->mesh.algo3d == ALGO_3D_MMG3D) {
    for(std::size_t i = 0; i < regions.size(); i++) {
      refineMeshMMG(regions[i]);
    }
  }
  else if(CTX::instance()->mesh.algo3d != ALGO_3D_INITIAL_ONLY &&
	  CTX::instance()->mesh.algo3d != ALGO_3D_RTREE) {
    insertVerticesInRegion(gr, CTX::instance()->mesh.maxIterDelaunay3D, 1.,
                           true, &sqr);

    if(sqr.buildPyramids(gr->model())) {
      Msg::Info("Optimizing pyramids for hybrid mesh...");
      gr->model()->setAllVolumesPositive();
      RelocateVerticesOfPyramids(regions, 3);
      // RelocateVertices(regions, 3);
      Msg::Info("Done optimizing pyramids for hybrid mesh");
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

void untangleMeshGRegion::operator()(GRegion *gr, bool always)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(!always && gr->isFullyDiscrete()) return;

  // don't optimize extruded meshes
  if(gr->meshAttributes.method == MESH_TRANSFINITE) return;
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;

  Msg::Info("Untangling volume %d", gr->tag());
  untangleMesh(gr);
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
