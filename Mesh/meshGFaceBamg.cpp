// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <iostream>
#include "meshGFaceBamg.h"
#include "meshGFaceLloyd.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include <list>
#include <map>
#include "BackgroundMesh.h"

#if defined(HAVE_BAMG)

long verbosity = 0;
#include "Mesh2d.hpp"
#include "Mesh2.h"
Mesh2 *Bamg(Mesh2 *Thh, double * args,double *mm11,double *mm12,double *mm22, bool);

static void computeMeshMetricsForBamg(GFace *gf, int numV,
                                      Vertex2 *bamgVertices,  
                                      double *mm11, double *mm12, double *mm22,
                                      int iter)
{
  //  char name[245];
  //  sprintf(name,"bgmBamg-%d-%d.pos",gf->tag(),iter);
  //  if (iter < 2){
  //    backgroundMesh::set(gf);
  //    backgroundMesh::current()->print(name, 0);
  //  }

  fullMatrix<double> J(2,3), JT(3,2),M(3,3),R(2,2),W(2,3);
  for (int i = 0; i < numV; ++i){
    double u = bamgVertices[i][0];
    double v = bamgVertices[i][1];
    GPoint gp = gf->point(SPoint2(u, v));
    SMetric3 m = BGM_MeshMetric(gf, u, v, gp.x(), gp.y(), gp.z());
    
    // compute the derivatives of the parametrization
    Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(u, v));

    J(0,0) = JT(0,0) = der.first().x();
    J(0,1) = JT(1,0) = der.first().y();
    J(0,2) = JT(2,0) = der.first().z();
    J(1,0) = JT(0,1) = der.second().x();
    J(1,1) = JT(1,1) = der.second().y();
    J(1,2) = JT(2,1) = der.second().z();

    m.getMat(M);
    J.mult(M,W);
    W.mult(JT,R);
    bamg::Metric M1(R(0,0),R(1,0),R(1,1));
    mm11[i] = M1.a11;
    mm12[i] = M1.a21;
    mm22[i] = M1.a22;    
  }
}

static void meshGFaceBamg_(GFace *gf, int iter, bool initialMesh)
{
  std::set<MVertex*> all;
  std::map<int,MVertex*> recover;
  for (unsigned int i = 0; i < gf->triangles.size(); i++){
    for (unsigned int j = 0; j < 3; j++) 
      all.insert(gf->triangles[i]->getVertex(j));
  }
  Vertex2 *bamgVertices = new Vertex2[all.size()];
  int index = 0;
  for(std::set<MVertex*>::iterator it = all.begin(); it!=all.end(); ++it){
    if ((*it)->onWhat()->dim() < 2){
      SPoint2 p;
      bool success = reparamMeshVertexOnFace(*it, gf, p);
      bamgVertices[index][0] = p.x();
      bamgVertices[index][1] = p.y();
      bamgVertices[index].lab = index;
      recover[index] = *it;
      (*it)->setIndex(index++);
    }
  }
  int nbFixedVertices = index;
  for(std::set<MVertex*>::iterator it = all.begin(); it!=all.end(); ++it){
    // FIXME : SEAMS should have to be taken into account here !!!
    if ((*it)->onWhat()->dim() >= 2){
      SPoint2 p;
      bool success = reparamMeshVertexOnFace(*it, gf, p);
      bamgVertices[index][0] = p.x();
      bamgVertices[index][1] = p.y();
      recover[index] = *it;
      (*it)->setIndex(index++);
    }
  }

  Triangle2 *bamgTriangles = new Triangle2[gf->triangles.size()];
  for (unsigned int i = 0; i < gf->triangles.size(); i++){    
    int nodes [3] = {gf->triangles[i]->getVertex(0)->getIndex(),
		     gf->triangles[i]->getVertex(1)->getIndex(),
		     gf->triangles[i]->getVertex(2)->getIndex()};
    double u1(bamgVertices[nodes[0]][0]);
    double u2(bamgVertices[nodes[1]][0]);
    double u3(bamgVertices[nodes[2]][0]);
    double v1(bamgVertices[nodes[0]][1]);
    double v2(bamgVertices[nodes[1]][1]);
    double v3(bamgVertices[nodes[2]][1]);
    double sign = (u2-u1)*(v3-v1) - (u3-u1)*(v2-v1);
    if (sign < 0){
      int temp = nodes[0];
      nodes[0] = nodes[1];
      nodes[1] = temp;
    }
    bamgTriangles[i].init(bamgVertices, nodes, gf->tag());
  }
  std::list<GEdge*> edges = gf->edges();
  int numEdges = 0;
  for (std::list<GEdge*>::iterator it = edges.begin(); it != edges.end(); ++it){
    numEdges += (*it)->lines.size();
  }

  Seg *bamgBoundary = new Seg[numEdges];

  int count = 0;
  for (std::list<GEdge*>::iterator it = edges.begin(); it != edges.end(); ++it){
    for (unsigned int i = 0; i < (*it)->lines.size(); ++i){
      int nodes [2] = {(*it)->lines[i]->getVertex(0)->getIndex(),
		       (*it)->lines[i]->getVertex(1)->getIndex()};      
      bamgBoundary[count].init (bamgVertices, nodes, (*it)->tag());
      bamgBoundary[count++].lab = count;
    }
  }
  Mesh2 bamgMesh ( all.size(), gf->triangles.size(), numEdges,
		   bamgVertices, bamgTriangles, bamgBoundary);
  double *mm11 = new double[all.size()];
  double *mm12 = new double[all.size()];
  double *mm22 = new double[all.size()];
  double args[256];
  computeMeshMetricsForBamg(gf, all.size(), bamgVertices, mm11, mm12, mm22, iter);
  for (int i = 0; i < 256; i++) args[i] = -1.1e100;
  Mesh2 *refinedBamgMesh = 0;
  try{
    refinedBamgMesh = Bamg(&bamgMesh, args, mm11, mm12, mm22, initialMesh);
    Msg::Info("bamg succeeded %d vertices %d triangles",
              refinedBamgMesh->nv, refinedBamgMesh->nt);
  }
  catch(...){
    Msg::Error("bamg failed");
    return;
  }
  delete [] mm11;
  delete [] mm12;
  delete [] mm22;
  std::map<int,MVertex*> yetAnother;
  for (int i = 0; i < refinedBamgMesh->nv; i++){
    Vertex2 &v = refinedBamgMesh->vertices[i];
    if (i >= nbFixedVertices){
      GPoint gp = gf->point(SPoint2(v[0], v[1]));
      MFaceVertex *x = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, v[0], v[1]);
      yetAnother[i] = x;
      gf->mesh_vertices.push_back(x);
    }
    else {
      yetAnother[i] = recover[i];
    }
  }

  for (unsigned int i = 0; i < gf->triangles.size(); i++){    
    delete gf->triangles[i];
  }
  gf->triangles.clear();
  for (int i = 0; i < refinedBamgMesh->nt; i++){
    Triangle2 &t = refinedBamgMesh->triangles[i];
    Vertex2 &v1 = t[0];
    Vertex2 &v2 = t[1];
    Vertex2 &v3 = t[2];
    gf->triangles.push_back(new MTriangle(yetAnother[(*refinedBamgMesh)(v1)],
					  yetAnother[(*refinedBamgMesh)(v2)],
					  yetAnother[(*refinedBamgMesh)(v3)]));    
  }
  
  if (refinedBamgMesh) delete refinedBamgMesh;
}

void meshGFaceBamg(GFace *gf)
{
  int nT = gf->triangles.size();
  //  meshGFaceBamg_ ( gf , 0, true);
  for (int i = 1; i < 14; i++){
    //    char name[245];
    //    sprintf(name,"hop%d.msh",i);
    //    GModel::current()->writeMSH(name);
    meshGFaceBamg_(gf, i, false);
    //    sprintf(name,"hap%d.msh",i);
    //    GModel::current()->writeMSH(name);
    
    int nTnow = gf->triangles.size();
    if (fabs((double)(nTnow - nT)) < 0.01 * nT) break;
    nT = nTnow;
  }
  //  lloydAlgorithm lloyd (20);
  //  lloyd(gf);
}

#else

void meshGFaceBamg(GFace *gf)
{
  Msg::Error("Gmsh msust be compiled with the Bidimensional Anisotropic Mesh "
             "Generator (Bamg) in order to support that option");
}

#endif
