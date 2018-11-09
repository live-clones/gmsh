// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#include <stdlib.h>
#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshGRegion.h"
#include "meshGRegionHxt.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "boundaryLayersData.h"
#include "meshGRegionBoundaryRecovery.h"
#include "meshGRegionDelaunayInsertion.h"
#include "meshGRegionRelocateVertex.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "gmshRegion.h"
#include "MLine.h"
#include "MPoint.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "BDS.h"
#include "OS.h"
#include "Context.h"
#include "meshGRegionMMG3D.h"
#include "simple3D.h"
#include "directions3D.h"
#include "pointInsertion.h"
#include "Levy3D.h"
#include "discreteFace.h"
#include "filterElements.h"
#include "ExtrudeParams.h"

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
  for(GModel::riter it = gm->firstRegion(); it != gm->lastRegion(); it++){
    GRegion *gr = *it;
    std::vector<GFace*> faces = gr->faces();
    for(unsigned int i = 0; i < faces.size(); i++){
      GFace *gf = faces[i];
      for(unsigned int j = 0; j < gf->quadrangles.size(); j++){
        std::map<MFace, MVertex *, Less_Face>::iterator it2 =
          _quad.find(gf->quadrangles[j]->getFace(0));
        if(it2 != _quad.end()){
          npyram++;
          gr->pyramids.push_back
            (new MPyramid(it2->first.getVertex(0), it2->first.getVertex(1),
                          it2->first.getVertex(2), it2->first.getVertex(3),
                          it2->second));
          gr->mesh_vertices.push_back(it2->second);
          if(it2->second->onWhat()->dim() == 3){
            Msg::Error("Pyramid top vertex already classified on volume %d (!= %d) - "
                       "non-manifold quad boundaries not supported yet",
                       it2->second->onWhat()->tag(), gr->tag());
          }
          else{
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
    if (meshGRegionHxt (regions) != 0){
      Msg::Error ("HXT 3D mesh failed");
    }
    return;
  }

  if(CTX::instance()->mesh.algo3d != ALGO_3D_DELAUNAY &&
     CTX::instance()->mesh.algo3d != ALGO_3D_MMG3D)
    return;

  GRegion *gr = regions[0];
  std::vector<GFace *> faces = gr->faces();
  std::set<GFace *, GEntityLessThan> allFacesSet;
  for(unsigned int i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    allFacesSet.insert(f.begin(), f.end());
    allFacesSet.insert(f_e.begin(), f_e.end());
  }
  std::vector<GFace *> allFaces(allFacesSet.begin(), allFacesSet.end());
  gr->set(allFaces);

  std::set<GEdge *> allEmbEdgesSet;
  for(unsigned int i = 0; i < regions.size(); i++) {
    std::vector<GEdge *> const &e = regions[i]->embeddedEdges();
    allEmbEdgesSet.insert(e.begin(), e.end());
  }
  std::vector<GEdge *> allEmbEdges(allEmbEdgesSet.begin(),
                                   allEmbEdgesSet.end());
  std::vector<GEdge *> oldEmbEdges = gr->embeddedEdges();
  gr->embeddedEdges() = allEmbEdges;

  std::set<GVertex *> allEmbVerticesSet;
  for(unsigned int i = 0; i < regions.size(); i++) {
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
  std::vector<GFace *>::iterator itf = allFaces.begin();
  while(itf != allFaces.end()) {
    std::sort((*itf)->triangles.begin(), (*itf)->triangles.end(),
              compareMTriangleLexicographic());
    ++itf;
  }

  // restore the initial set of faces and embedded edges/vertices
  gr->set(faces);
  gr->embeddedEdges() = oldEmbEdges;
  gr->embeddedVertices() = oldEmbVertices;

  if(!success) return;

  // now do insertion of points

  if(CTX::instance()->mesh.algo3d == ALGO_3D_MMG3D) {
    refineMeshMMG(gr);
  }
  else if(CTX::instance()->mesh.oldRefinement) {
    insertVerticesInRegion(gr, 2000000000, true, &sqr);
  }
  else {
    void edgeBasedRefinement(const int numThreads, const int nptsatonce,
                             GRegion *gr);
    // just to remove tets that are not to be meshed
    insertVerticesInRegion(gr, 0, true, &sqr);
    for(unsigned int i = 0; i < regions.size(); i++) {
      Msg::Info("Refining volume %d with %d threads", regions[i]->tag(),
                Msg::GetMaxThreads());
      edgeBasedRefinement(Msg::GetMaxThreads(), 1, regions[i]);
    }
    // RelocateVertices(regions, -1);
  }

  if(sqr.buildPyramids(gr->model())){
    Msg::Info("Optimizing pyramids for hybrid mesh...");
    RelocateVertices(regions, 3);
    Msg::Info("Done optimizing pyramids for hybrid mesh");
  }
}

#if defined(HAVE_NETGEN)

namespace nglib {
#include "nglib_gmsh.h"
}
using namespace nglib;

static void getAllBoundingVertices(
  GRegion *gr, std::set<MVertex *, MVertexLessThanNum> &allBoundingVertices)
{
  std::vector<GFace *> faces = gr->faces();
  std::vector<GFace *>::iterator it = faces.begin();

  while(it != faces.end()) {
    GFace *gf = (*it);
    for(unsigned int i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      for(int k = 0; k < 3; k++)
        if(allBoundingVertices.find(t->getVertex(k)) ==
           allBoundingVertices.end())
          allBoundingVertices.insert(t->getVertex(k));
    }
    ++it;
  }
}

Ng_Mesh *buildNetgenStructure(GRegion *gr, bool importVolumeMesh,
                              std::vector<MVertex *> &numberedV)
{
  Ng_Init();
  Ng_Mesh *ngmesh = Ng_NewMesh();

  std::set<MVertex *, MVertexLessThanNum> allBoundingVertices;
  getAllBoundingVertices(gr, allBoundingVertices);

  std::set<MVertex *, MVertexLessThanNum>::iterator itv =
    allBoundingVertices.begin();
  int I = 1;
  while(itv != allBoundingVertices.end()) {
    double tmp[3];
    tmp[0] = (*itv)->x();
    tmp[1] = (*itv)->y();
    tmp[2] = (*itv)->z();
    (*itv)->setIndex(I++);
    numberedV.push_back(*itv);
    Ng_AddPoint(ngmesh, tmp);
    ++itv;
  }

  if(importVolumeMesh) {
    for(unsigned int i = 0; i < gr->mesh_vertices.size(); i++) {
      double tmp[3];
      tmp[0] = gr->mesh_vertices[i]->x();
      tmp[1] = gr->mesh_vertices[i]->y();
      tmp[2] = gr->mesh_vertices[i]->z();
      gr->mesh_vertices[i]->setIndex(I++);
      Ng_AddPoint(ngmesh, tmp);
    }
  }
  std::vector<GFace *> faces = gr->faces();
  std::vector<GFace *>::iterator it = faces.begin();
  while(it != faces.end()) {
    GFace *gf = (*it);
    for(unsigned int i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      int tmp[3];
      tmp[0] = t->getVertex(0)->getIndex();
      tmp[1] = t->getVertex(1)->getIndex();
      tmp[2] = t->getVertex(2)->getIndex();
      Ng_AddSurfaceElement(ngmesh, NG_TRIG, tmp);
    }
    ++it;
  }

  if(importVolumeMesh) {
    for(unsigned int i = 0; i < gr->tetrahedra.size(); i++) {
      MTetrahedron *t = gr->tetrahedra[i];
      // netgen expects tet with negative volume
      if(t->getVolumeSign() > 0) t->reverse();
      int tmp[4];
      tmp[0] = t->getVertex(0)->getIndex();
      tmp[1] = t->getVertex(1)->getIndex();
      tmp[2] = t->getVertex(2)->getIndex();
      tmp[3] = t->getVertex(3)->getIndex();
      Ng_AddVolumeElement(ngmesh, NG_TET, tmp);
    }
  }

  return ngmesh;
}

void TransferVolumeMesh(GRegion *gr, Ng_Mesh *ngmesh,
                        std::vector<MVertex *> &numberedV)
{
  // Gets total number of vertices of Netgen's mesh
  int nbv = Ng_GetNP(ngmesh);
  if(!nbv) return;

  int nbpts = numberedV.size();

  // Create new volume vertices
  for(int i = nbpts; i < nbv; i++) {
    double tmp[3];
    Ng_GetPoint(ngmesh, i + 1, tmp);
    MVertex *v = new MVertex(tmp[0], tmp[1], tmp[2], gr);
    numberedV.push_back(v);
    gr->mesh_vertices.push_back(v);
  }

  // Get total number of simplices of Netgen's mesh
  int nbe = Ng_GetNE(ngmesh);

  // Create new volume simplices
  for(int i = 0; i < nbe; i++) {
    int tmp[4];
    Ng_GetVolumeElement(ngmesh, i + 1, tmp);
    MTetrahedron *t =
      new MTetrahedron(numberedV[tmp[0] - 1], numberedV[tmp[1] - 1],
                       numberedV[tmp[2] - 1], numberedV[tmp[3] - 1]);
    gr->tetrahedra.push_back(t);
  }
}

#endif

void deMeshGRegion::operator()(GRegion *gr)
{
  if(gr->geomType() == GEntity::DiscreteVolume) return;
  gr->deleteMesh();
}

// X_1 (1-u-v) + X_2 u + X_3 v = P_x + t N_x
// Y_1 (1-u-v) + Y_2 u + Y_3 v = P_y + t N_y
// Z_1 (1-u-v) + Z_2 u + Z_3 v = P_z + t N_z

int intersect_line_triangle(double X[3], double Y[3], double Z[3], double P[3],
                            double N[3], const double eps_prec)
{
  double mat[3][3], det;
  double b[3], res[3];

  mat[0][0] = X[1] - X[0];
  mat[0][1] = X[2] - X[0];
  mat[0][2] = N[0];

  mat[1][0] = Y[1] - Y[0];
  mat[1][1] = Y[2] - Y[0];
  mat[1][2] = N[1];

  mat[2][0] = Z[1] - Z[0];
  mat[2][1] = Z[2] - Z[0];
  mat[2][2] = N[2];

  b[0] = P[0] - X[0];
  b[1] = P[1] - Y[0];
  b[2] = P[2] - Z[0];

  if(!sys3x3_with_tol(mat, b, res, &det)) {
    return 0;
  }
  //  printf("coucou %g %g %g\n",res[0],res[1],res[2]);
  if(res[0] >= eps_prec && res[0] <= 1.0 - eps_prec && res[1] >= eps_prec &&
     res[1] <= 1.0 - eps_prec && 1 - res[0] - res[1] >= eps_prec &&
     1 - res[0] - res[1] <= 1.0 - eps_prec) {
    // the line clearly intersects the triangle
    return (res[2] > 0) ? 1 : 0;
  }
  else if(res[0] < -eps_prec || res[0] > 1.0 + eps_prec || res[1] < -eps_prec ||
          res[1] > 1.0 + eps_prec || 1 - res[0] - res[1] < -eps_prec ||
          1 - res[0] - res[1] > 1.0 + eps_prec) {
    // the line clearly does NOT intersect the triangle
    return 0;
  }
  else {
    // printf("non robust stuff\n");
    // the intersection is not robust, try another triangle
    return -10000;
  }
}

static void setRand(double r[6])
{
  for(int i = 0; i < 6; i++)
    r[i] = 0.0001 * ((double)rand() / (double)RAND_MAX);
}

void meshNormalsPointOutOfTheRegion(GRegion *gr)
{
  std::vector<GFace *> faces = gr->faces();
  std::vector<GFace *>::iterator it = faces.begin();

  // perform intersection check in normalized coordinates
  SBoundingBox3d bbox = gr->bounds();
  double scaling = norm(SVector3(bbox.max(), bbox.min()));
  if(!scaling) {
    Msg::Warning("Bad scaling in meshNormalsPointOutOfTheRegion");
    scaling = 1.;
  }

  double rrr[6];
  setRand(rrr);

  while(it != faces.end()) {
    GFace *gf = (*it);
    int nb_intersect = 0;
    for(unsigned int i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      double X[3] = {t->getVertex(0)->x(), t->getVertex(1)->x(),
                     t->getVertex(2)->x()};
      double Y[3] = {t->getVertex(0)->y(), t->getVertex(1)->y(),
                     t->getVertex(2)->y()};
      double Z[3] = {t->getVertex(0)->z(), t->getVertex(1)->z(),
                     t->getVertex(2)->z()};
      for(int j = 0; j < 3; j++) {
        X[j] /= scaling;
        Y[j] /= scaling;
        Z[j] /= scaling;
      }

      double P[3] = {(X[0] + X[1] + X[2]) / 3., (Y[0] + Y[1] + Y[2]) / 3.,
                     (Z[0] + Z[1] + Z[2]) / 3.};
      double v1[3] = {X[0] - X[1], Y[0] - Y[1], Z[0] - Z[1]};
      double v2[3] = {X[2] - X[1], Y[2] - Y[1], Z[2] - Z[1]};
      double N[3];
      prodve(v1, v2, N);
      norme(v1);
      norme(v2);
      norme(N);
      N[0] += rrr[0] * v1[0] + rrr[1] * v2[0];
      N[1] += rrr[2] * v1[1] + rrr[3] * v2[1];
      N[2] += rrr[4] * v1[2] + rrr[5] * v2[2];
      norme(N);
      std::vector<GFace *>::iterator it_b = faces.begin();
      while(it_b != faces.end()) {
        GFace *gf_b = (*it_b);
        for(unsigned int i_b = 0; i_b < gf_b->triangles.size(); i_b++) {
          MTriangle *t_b = gf_b->triangles[i_b];
          if(t_b != t) {
            double X_b[3] = {t_b->getVertex(0)->x(), t_b->getVertex(1)->x(),
                             t_b->getVertex(2)->x()};
            double Y_b[3] = {t_b->getVertex(0)->y(), t_b->getVertex(1)->y(),
                             t_b->getVertex(2)->y()};
            double Z_b[3] = {t_b->getVertex(0)->z(), t_b->getVertex(1)->z(),
                             t_b->getVertex(2)->z()};
            for(int j = 0; j < 3; j++) {
              X_b[j] /= scaling;
              Y_b[j] /= scaling;
              Z_b[j] /= scaling;
            }
            int inters = intersect_line_triangle(X_b, Y_b, Z_b, P, N, 1.e-9);
            nb_intersect += inters;
          }
        }
        ++it_b;
      }
      Msg::Info("Region %d Face %d, %d intersect", gr->tag(), gf->tag(),
                nb_intersect);
      if(nb_intersect >= 0)
        break; // negative value means intersection is not "robust"
    }

    if(nb_intersect < 0) {
      setRand(rrr);
    }
    else {
      if(nb_intersect % 2 == 1) {
        // odd nb of intersections: the normal points inside the region
        for(unsigned int i = 0; i < gf->triangles.size(); i++) {
          gf->triangles[i]->reverse();
        }
      }
      ++it;
    }
  }

  // FILE *fp = Fopen("debug.pos", "w");
  // if(fp){
  //   fprintf(fp, "View \"debug\" {\n");
  //   for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end();
  //   it++)
  //     for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
  //       (*it)->triangles[i]->writePOS(fp, 1., (*it)->tag());
  //   fprintf(fp, "};\n");
  //   fclose(fp);
  // }
}

void meshGRegion::operator()(GRegion *gr)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(gr->geomType() == GEntity::DiscreteVolume) return;
  if(gr->meshAttributes.method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !gr->getVisibility()) return;

  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh) return;

  // destroy the mesh if it exists
  deMeshGRegion dem;
  dem(gr);

  if(MeshTransfiniteVolume(gr)) return;

  std::vector<GFace *> faces = gr->faces();

  // sanity check for frontal algo
  if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL) {
    for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
        it++) {
      if((*it)->quadrangles.size()) {
        Msg::Error(
          "Cannot use frontal 3D algorithm with quadrangles on boundary");
        return;
      }
    }
  }

  if(CTX::instance()->mesh.algo3d != ALGO_3D_FRONTAL) {
    delaunay.push_back(gr);
  }
  else if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL) {
#if !defined(HAVE_NETGEN)
    Msg::Error("Frontal algorithm requires Netgen");
#else
    Msg::Info("Meshing volume %d (Frontal)", gr->tag());
    // orient the triangles of with respect to this region
    meshNormalsPointOutOfTheRegion(gr);
    std::vector<MVertex *> numberedV;
    Ng_Mesh *ngmesh = buildNetgenStructure(gr, false, numberedV);
    Ng_GenerateVolumeMesh(ngmesh, CTX::instance()->mesh.lcMax);
    TransferVolumeMesh(gr, ngmesh, numberedV);
    Ng_DeleteMesh(ngmesh);
    Ng_Exit();
#endif
  }
}

void optimizeMeshGRegionNetgen::operator()(GRegion *gr, bool always)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(!always && gr->geomType() == GEntity::DiscreteVolume) return;

  // don't optimize transfinite or extruded meshes
  if(gr->meshAttributes.method == MESH_TRANSFINITE) return;
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;

#if !defined(HAVE_NETGEN)
  Msg::Error("Netgen optimizer is not compiled in this version of Gmsh");
#else
  Msg::Info("Optimizing volume %d", gr->tag());
  // import mesh into netgen, including volume tets
  std::vector<MVertex *> numberedV;
  Ng_Mesh *ngmesh = buildNetgenStructure(gr, true, numberedV);
  // delete volume vertices and tets
  deMeshGRegion dem;
  dem(gr);
  // optimize mesh
  Ng_OptimizeVolumeMesh(ngmesh, CTX::instance()->mesh.lcMax);
  TransferVolumeMesh(gr, ngmesh, numberedV);
  Ng_DeleteMesh(ngmesh);
  Ng_Exit();
#endif
}

void optimizeMeshGRegionGmsh::operator()(GRegion *gr, bool always)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(!always && gr->geomType() == GEntity::DiscreteVolume) return;

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
  GModel::riter rit = model->firstRegion();
  while(rit != model->lastRegion()) {
    std::vector<GFace *> _faces = (*rit)->faces();
    faces_to_consider.insert(_faces.begin(), _faces.end());
    rit++;
  }

  std::set<GFace *>::iterator fit = faces_to_consider.begin();
  while(fit != faces_to_consider.end()) {
    for(unsigned int i = 0; i < (*fit)->getNumMeshElements(); i++) {
      MFace ff = (*fit)->getMeshElement(i)->getFace(0);
      if(!onlyTriangles || ff.getNumVertices() == 3)
        search[ff] = *fit;
    }
    ++fit;
  }
  return true;
}

bool buildEdgeSearchStructure(GModel *model, es_cont &search)
{
  search.clear();

  GModel::eiter eit = model->firstEdge();
  while(eit != model->lastEdge()) {
    for(unsigned int i = 0; i < (*eit)->lines.size(); i++) {
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
  fs_cont::const_iterator it = search.find(ff);
  if(it == search.end()) return 0;
  return it->second;
}

GFace *findInFaceSearchStructure(const MFace &ff, const fs_cont &search)
{
  fs_cont::const_iterator it = search.find(ff);
  if(it == search.end()) return 0;
  return it->second;
}

GEdge *findInEdgeSearchStructure(MVertex *p1, MVertex *p2,
                                 const es_cont &search)
{
  MVertex *p = std::min(p1, p2);

  for(es_cont::const_iterator it = search.lower_bound(p);
      it != search.upper_bound(p); ++it) {
    MLine *l = it->second.first;
    GEdge *ge = it->second.second;
    if((l->getVertex(0) == p1 || l->getVertex(0) == p2) &&
       (l->getVertex(1) == p1 || l->getVertex(1) == p2))
      return ge;
  }
  return 0;
}
