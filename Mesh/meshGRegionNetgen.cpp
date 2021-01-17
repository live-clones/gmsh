// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshGRegion.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "ExtrudeParams.h"
#include "BackgroundMeshTools.h"
#include "Context.h"

#if defined(HAVE_NETGEN)

namespace nglib {
#include "nglib_gmsh.h"
}
using namespace nglib;

static void getAllBoundingVertices(
  GRegion *gr, std::set<MVertex *, MVertexPtrLessThan> &allBoundingVertices)
{
  std::vector<GFace *> faces = gr->faces();
  auto it = faces.begin();

  while(it != faces.end()) {
    GFace *gf = (*it);
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      for(int k = 0; k < 3; k++)
        if(allBoundingVertices.find(t->getVertex(k)) ==
           allBoundingVertices.end())
          allBoundingVertices.insert(t->getVertex(k));
    }
    ++it;
  }
}

static Ng_Mesh *buildNetgenStructure(GRegion *gr, bool importVolumeMesh,
                                     std::vector<MVertex *> &numberedV)
{
  Ng_Init();
  Ng_Mesh *ngmesh = Ng_NewMesh();

  std::set<MVertex *, MVertexPtrLessThan> allBoundingVertices;
  getAllBoundingVertices(gr, allBoundingVertices);

  auto itv = allBoundingVertices.begin();
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
    for(std::size_t i = 0; i < gr->mesh_vertices.size(); i++) {
      double tmp[3];
      tmp[0] = gr->mesh_vertices[i]->x();
      tmp[1] = gr->mesh_vertices[i]->y();
      tmp[2] = gr->mesh_vertices[i]->z();
      gr->mesh_vertices[i]->setIndex(I++);
      Ng_AddPoint(ngmesh, tmp);
    }
  }
  std::vector<GFace *> faces = gr->faces();
  auto it = faces.begin();
  while(it != faces.end()) {
    GFace *gf = (*it);
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
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
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
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

static void TransferVolumeMesh(GRegion *gr, Ng_Mesh *ngmesh,
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

// X_1 (1-u-v) + X_2 u + X_3 v = P_x + t N_x
// Y_1 (1-u-v) + Y_2 u + Y_3 v = P_y + t N_y
// Z_1 (1-u-v) + Z_2 u + Z_3 v = P_z + t N_z

static int intersectLineTriangle(double X[3], double Y[3], double Z[3],
                                 double P[3], double N[3],
                                 const double eps_prec)
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

  if(!sys3x3_with_tol(mat, b, res, &det)) { return 0; }
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

static void meshNormalsPointOutOfTheRegion(GRegion *gr)
{
  std::vector<GFace *> faces = gr->faces();
  auto it = faces.begin();

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
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
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
      auto it_b = faces.begin();
      while(it_b != faces.end()) {
        GFace *gf_b = (*it_b);
        for(std::size_t i_b = 0; i_b < gf_b->triangles.size(); i_b++) {
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
            int inters = intersectLineTriangle(X_b, Y_b, Z_b, P, N, 1.e-9);
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

    if(nb_intersect < 0) { setRand(rrr); }
    else {
      if(nb_intersect % 2 == 1) {
        // odd nb of intersections: the normal points inside the region
        for(std::size_t i = 0; i < gf->triangles.size(); i++) {
          gf->triangles[i]->reverse();
        }
      }
      ++it;
    }
  }

  // FILE *fp = Fopen("debug.pos", "w");
  // if(fp){
  //   fprintf(fp, "View \"debug\" {\n");
  //   for(auto it = faces.begin(); it != faces.end(); it++)
  //     for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
  //       (*it)->triangles[i]->writePOS(fp, 1., (*it)->tag());
  //   fprintf(fp, "};\n");
  //   fclose(fp);
  // }
}

#endif

void meshGRegionNetgen(GRegion *gr)
{
#if !defined(HAVE_NETGEN)
  Msg::Error("Frontal algorithm requires Netgen");
#else
  // sanity check for frontal algo
  std::vector<GFace *> faces = gr->faces();
  for(auto it = faces.begin(); it != faces.end(); it++) {
    if((*it)->quadrangles.size()) {
      Msg::Error(
        "Cannot use frontal 3D algorithm with quadrangles on boundary");
      return;
    }
  }

  Msg::Info("Meshing volume %d (Frontal)", gr->tag());
  // orient the triangles of with respect to this region
  meshNormalsPointOutOfTheRegion(gr);
  std::vector<MVertex *> numberedV;
  Ng_Mesh *ngmesh = buildNetgenStructure(gr, false, numberedV);
  SPoint3 pt = gr->bounds().center();
  double lc = BGM_MeshSize(gr, 0, 0, pt.x(), pt.y(), pt.z());
  Ng_GenerateVolumeMesh(ngmesh, lc);
  TransferVolumeMesh(gr, ngmesh, numberedV);
  Ng_DeleteMesh(ngmesh);
  Ng_Exit();
#endif
}

void optimizeMeshGRegionNetgen::operator()(GRegion *gr, bool always)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(!always && gr->geomType() == GEntity::DiscreteVolume) return;

  // don't optimize transfinite or extruded meshes
  if(gr->meshAttributes.method == MESH_TRANSFINITE) return;
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;

  if(gr->prisms.size() || gr->hexahedra.size() || gr->pyramids.size()) {
    Msg::Info("Skipping Netgen optimizer for hybrid mesh");
    return;
  }

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
  SPoint3 pt = gr->bounds().center();
  double lc = BGM_MeshSize(gr, 0, 0, pt.x(), pt.y(), pt.z());
  Ng_OptimizeVolumeMesh(ngmesh, lc);
  TransferVolumeMesh(gr, ngmesh, numberedV);
  Ng_DeleteMesh(ngmesh);
  Ng_Exit();
#endif
}
