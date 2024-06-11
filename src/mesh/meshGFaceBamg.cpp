// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <numeric>
#include <iostream>
#include "meshGFaceBamg.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include "BackgroundMeshTools.h"
#include "meshGFaceDelaunayInsertion.h"
#include "Options.h"
#include "meshGFace.h"
#include "MElementOctree.h"
#include "fullMatrix.h"

#if defined(HAVE_BAMG)

long verbosity = 0;
#include "Mesh2d.hpp"
#include "Mesh2.h"
Mesh2 *Bamg(Mesh2 *Thh, double *args, double *mm11, double *mm12, double *mm22,
            bool);

static void computeMeshMetricsForBamg(GFace *gf, int numV,
                                      Vertex2 *bamgVertices, double *mm11,
                                      double *mm12, double *mm22)
{
  //  char name[245];
  //  sprintf(name,"bgmBamg-%d-%d.pos",gf->tag(),iter);
  //  if (iter < 2){
  //    backgroundMesh::set(gf);
  //    backgroundMesh::current()->print(name, 0);
  //  }

  fullMatrix<double> J(2, 3), JT(3, 2), M(3, 3), R(2, 2), W(2, 3);
  for(int i = 0; i < numV; ++i) {
    double u = bamgVertices[i][0];
    double v = bamgVertices[i][1];
    GPoint gp = gf->point(SPoint2(u, v));
    SMetric3 m = BGM_MeshMetric(gf, u, v, gp.x(), gp.y(), gp.z());

    // compute the derivatives of the parametrization
    Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(u, v));

    J(0, 0) = JT(0, 0) = der.first().x();
    J(0, 1) = JT(1, 0) = der.first().y();
    J(0, 2) = JT(2, 0) = der.first().z();
    J(1, 0) = JT(0, 1) = der.second().x();
    J(1, 1) = JT(1, 1) = der.second().y();
    J(1, 2) = JT(2, 1) = der.second().z();

    m.getMat(M);
    J.mult(M, W);
    W.mult(JT, R);

    mm11[i] = R(0, 0);
    mm12[i] = R(1, 0);
    mm22[i] = R(1, 1);
  }
}

void meshGFaceBamg(GFace *gf)
{
  std::vector<GEdge *> const &edges = gf->edges();
  std::set<MVertex *> bcVertex;
  for(auto it = edges.begin(); it != edges.end(); it++) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      bcVertex.insert((*it)->lines[i]->getVertex(0));
      bcVertex.insert((*it)->lines[i]->getVertex(1));
    }
  }

  // fill mesh data fo bamg (bamgVertices, bamgTriangles, bamgBoundary)
  std::set<MVertex *> all;
  std::map<int, MVertex *> recover;
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    for(std::size_t j = 0; j < 3; j++)
      all.insert(gf->triangles[i]->getVertex(j));
  }

  Vertex2 *bamgVertices = new Vertex2[all.size()];
  int index = 0;
  for(auto it = all.begin(); it != all.end(); ++it) {
    if((*it)->onWhat()->dim() <= 1) {
      SPoint2 p;
      reparamMeshVertexOnFace(*it, gf, p);
      bamgVertices[index][0] = p.x();
      bamgVertices[index][1] = p.y();
      bamgVertices[index].lab = index;
      recover[index] = *it;
      (*it)->setIndex(index++);
    }
  }
  // exit(1);
  int nbFixedVertices = index;
  for(auto it = all.begin(); it != all.end(); ++it) {
    // FIXME : SEAMS should have to be taken into account here !!!
    if((*it)->onWhat()->dim() >= 2) {
      SPoint2 p;
      reparamMeshVertexOnFace(*it, gf, p);
      bamgVertices[index][0] = p.x();
      bamgVertices[index][1] = p.y();
      recover[index] = *it;
      (*it)->setIndex(index++);
    }
  }

  std::vector<MElement *> myParamElems;
  std::vector<MVertex *> newVert;
  Triangle2 *bamgTriangles = new Triangle2[gf->triangles.size()];
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    int nodes[3] = {(int)gf->triangles[i]->getVertex(0)->getIndex(),
                    (int)gf->triangles[i]->getVertex(1)->getIndex(),
                    (int)gf->triangles[i]->getVertex(2)->getIndex()};
    double u1(bamgVertices[nodes[0]][0]);
    double u2(bamgVertices[nodes[1]][0]);
    double u3(bamgVertices[nodes[2]][0]);
    double v1(bamgVertices[nodes[0]][1]);
    double v2(bamgVertices[nodes[1]][1]);
    double v3(bamgVertices[nodes[2]][1]);
    double sign = (u2 - u1) * (v3 - v1) - (u3 - u1) * (v2 - v1);
    if(sign < 0) {
      int temp = nodes[0];
      nodes[0] = nodes[1];
      nodes[1] = temp;
    }
    bamgTriangles[i].init(bamgVertices, nodes, gf->tag());
  }

  const auto numEdges =
    std::accumulate(begin(edges), end(edges), std::size_t(0),
                    [](std::size_t const partial_sum, const GEdge *const edge) {
                      return partial_sum + edge->lines.size();
                    });

  Seg *bamgBoundary = new Seg[numEdges];
  int count = 0;
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); ++i) {
      int nodes[2] = {(int)(*it)->lines[i]->getVertex(0)->getIndex(),
                      (int)(*it)->lines[i]->getVertex(1)->getIndex()};
      bamgBoundary[count].init(bamgVertices, nodes, (*it)->tag());
      bamgBoundary[count].lab = count;
      count++;
    }
  }

  Mesh2 *bamgMesh = new Mesh2(all.size(), gf->triangles.size(), numEdges,
                              bamgVertices, bamgTriangles, bamgBoundary);

  MElementOctree *_octree = nullptr;

  Mesh2 *refinedBamgMesh = nullptr;
  int iterMax = 41;
  for(int k = 0; k < iterMax; k++) {
    int nbVert = bamgMesh->nv;

    double *mm11 = new double[nbVert];
    double *mm12 = new double[nbVert];
    double *mm22 = new double[nbVert];
    double args[256];
    for(int i = 0; i < 256; i++) args[i] = -1.1e100;
    args[16] = CTX::instance()->mesh.anisoMax;
    args[7] = CTX::instance()->mesh.smoothRatio;
    // args[ 21] = 90.0;//cutoffrad = 90 degree
    computeMeshMetricsForBamg(gf, nbVert, bamgMesh->vertices, mm11, mm12, mm22);

    try {
      refinedBamgMesh = Bamg(bamgMesh, args, mm11, mm12, mm22, false);
      Msg::Info("BAMG succeeded %d vertices %d triangles", refinedBamgMesh->nv,
                refinedBamgMesh->nt);
    } catch(...) {
      Msg::Error("BAMG failed");
      return;
    }
    delete[] mm11;
    delete[] mm12;
    delete[] mm22;

    int nT = bamgMesh->nt;
    int nTnow = refinedBamgMesh->nt;

    delete bamgMesh;
    bamgMesh = refinedBamgMesh;
    if(fabs((double)(nTnow - nT)) < 0.01 * nT) break;
  }

  std::map<int, MVertex *> yetAnother;
  for(int i = 0; i < refinedBamgMesh->nv; i++) {
    Vertex2 &v = refinedBamgMesh->vertices[i];
    if(i >= nbFixedVertices) {
      GPoint gp = gf->point(SPoint2(v[0], v[1]));
      // if (gp.x() > 2.){
      //  printf("wrong vertex index=%d %g %g %g (%g %g)\n",
      //         i, gp.x(), gp.y(), gp.z(), v[0], v[1]);
      // }
      // If point not found because compound edges have been remeshed and
      // boundary triangles have changed then we call our new octree
      MFaceVertex *x = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, v[0], v[1]);
      yetAnother[i] = x;
      gf->mesh_vertices.push_back(x);
    }
    else {
      MVertex *v = recover[i];
      yetAnother[i] = v;
    }
  }

  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    delete gf->triangles[i];
  }
  gf->triangles.clear();
  for(int i = 0; i < refinedBamgMesh->nt; i++) {
    Triangle2 &t = refinedBamgMesh->triangles[i];
    Vertex2 &v1 = t[0];
    Vertex2 &v2 = t[1];
    Vertex2 &v3 = t[2];
    gf->triangles.push_back(new MTriangle(yetAnother[(*refinedBamgMesh)(v1)],
                                          yetAnother[(*refinedBamgMesh)(v2)],
                                          yetAnother[(*refinedBamgMesh)(v3)]));
  }

  // delete pointers
  if(refinedBamgMesh) delete refinedBamgMesh;
  if(_octree) delete _octree;
  for(auto it = myParamElems.begin(); it != myParamElems.end(); it++)
    delete *it;
  for(auto it = newVert.begin(); it != newVert.end(); it++) delete *it;
}

#else

void meshGFaceBamg(GFace *gf)
{
  Msg::Error("This version of Gmsh is not compiled with BAMG support");
}

#endif
