//#include <fenv.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include "OptHomRun.h"
#include "GModel.h"
#include "Gmsh.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "highOrderTools.h"
#include "OptHomMesh.h"
#include "OptHOM.h"

std::set<MVertex*> filter2D(GFace *gf, int nbLayers, double _qual, bool onlytheworst = false)
{
  std::set<MVertex*> touched;
  std::set<MVertex*> not_touched;
  std::set<MTriangle *> ts;
  std::set<MQuadrangle *> qs;

  if (onlytheworst) {
    double minQ = 1.e22;
    MQuadrangle *worst;
    for (int i = 0; i < gf->quadrangles.size(); i++) {
      MQuadrangle *q = gf->quadrangles[i];
      double Q = q->distoShapeMeasure();
      if (Q < minQ) {
        worst = q;
        minQ = Q;
      }
    }
    qs.insert(worst);
    for (int j = 0; j < worst->getNumVertices(); j++)
      touched.insert(worst->getVertex(j));
  }

  else {
    for (int i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      double Q = t->distoShapeMeasure();
      if (Q < _qual || Q > 1.01) {
        ts.insert(t);
        for (int j = 0; j < t->getNumVertices(); j++)
          touched.insert(t->getVertex(j));
      }
    }
    for (int i = 0; i < gf->quadrangles.size(); i++) {
      MQuadrangle *q = gf->quadrangles[i];
      double Q = q->distoShapeMeasure();
      if (Q < _qual || Q > 1.0) {
        qs.insert(q);
        for (int j = 0; j < q->getNumVertices(); j++)
          touched.insert(q->getVertex(j));
      }
    }
  }
  //  printf("FILTER2D : %d bad triangles found among %6d\n", ts.size(), gf->triangles.size());
  //  printf("FILTER2D : %d bad quads     found among %6d\n", qs.size(), gf->quadrangles.size());

  // add layers of elements around bad elements
  for (int layer = 0; layer < nbLayers; layer++) {
    for (int i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      bool add_ = false;
      for (int j = 0; j < t->getNumVertices(); j++) {
        if (touched.find(t->getVertex(j)) != touched.end()) {
          add_ = true;
        }
      }
      if (add_) ts.insert(t);
    }
    for (int i = 0; i < gf->quadrangles.size(); i++) {
      bool add_ = false;
      MQuadrangle *q = gf->quadrangles[i];
      for (int j = 0; j < q->getNumVertices(); j++) {
        if (touched.find(q->getVertex(j)) != touched.end()) {
          add_ = true;
        }
      }
      if (add_) qs.insert(q);
    }

    for (std::set<MTriangle*>::iterator it = ts.begin(); it != ts.end(); ++it) {
      for (int j = 0; j < (*it)->getNumVertices(); j++) {
        touched.insert((*it)->getVertex(j));
      }
    }
    for (std::set<MQuadrangle*>::iterator it = qs.begin(); it != qs.end(); ++it) {
      for (int j = 0; j < (*it)->getNumVertices(); j++) {
        touched.insert((*it)->getVertex(j));
      }
    }
  }

  for (int i = 0; i < gf->triangles.size(); i++) {
    if (ts.find(gf->triangles[i]) == ts.end()) {
      for (int j = 0; j < gf->triangles[i]->getNumVertices(); j++) {
        if (touched.find(gf->triangles[i]->getVertex(j)) != touched.end()) not_touched.insert(gf->triangles[i]->getVertex(j));
      }
    }
  }
  for (int i = 0; i < gf->quadrangles.size(); i++) {
    if (qs.find(gf->quadrangles[i]) == qs.end()) {
      for (int j = 0; j < gf->quadrangles[i]->getNumVertices(); j++) {
        if (touched.find(gf->quadrangles[i]->getVertex(j)) != touched.end()) not_touched.insert(gf->quadrangles[i]->getVertex(j));
      }
    }
  }

  gf->triangles.clear();
  gf->quadrangles.clear();
  gf->triangles.insert(gf->triangles.begin(), ts.begin(), ts.end());
  gf->quadrangles.insert(gf->quadrangles.begin(), qs.begin(), qs.end());

  //  printf("FILTER2D : AFTER FILTERING %d triangles %d quads remain %d nodes on the boundary\n", gf->triangles.size(), gf->quadrangles.size(), not_touched.size());
  return not_touched;
}

std::set<MVertex*> filter3D(GRegion *gr, int nbLayers, double _qual)
{
  std::set<MVertex*> touched;
  std::set<MVertex*> not_touched;
  std::set<MTetrahedron *> ts;
  for (int i = 0; i < gr->tetrahedra.size(); i++) {
    MTetrahedron *t = gr->tetrahedra[i];
    if (t->distoShapeMeasure() < _qual) {
      ts.insert(t);
      for (int j = 0; j < t->getNumVertices(); j++)
        touched.insert(t->getVertex(j));
    }
    if (ts.size() == 1) break;
  }

  //  printf("FILTER3D : %d bad tets found among %6d\n", ts.size(), gr->tetrahedra.size());

  // add layers of elements around bad elements
  for (int layer = 0; layer < nbLayers; layer++) {
    for (int i = 0; i < gr->tetrahedra.size(); i++) {
      MTetrahedron *t = gr->tetrahedra[i];
      bool add_ = false;
      for (int j = 0; j < t->getNumVertices(); j++) {
        if (touched.find(t->getVertex(j)) != touched.end()) {
          add_ = true;
        }
      }
      if (add_) ts.insert(t);
    }

    for (std::set<MTetrahedron*>::iterator it = ts.begin(); it != ts.end(); ++it) {
      for (int j = 0; j < (*it)->getNumVertices(); j++) {
        touched.insert((*it)->getVertex(j));
      }
    }
  }

  for (int i = 0; i < gr->tetrahedra.size(); i++) {
    if (ts.find(gr->tetrahedra[i]) == ts.end()) {
      for (int j = 0; j < gr->tetrahedra[i]->getNumVertices(); j++) {
        if (touched.find(gr->tetrahedra[i]->getVertex(j)) != touched.end()) not_touched.insert(gr->tetrahedra[i]->getVertex(j));
      }
    }
  }

  gr->tetrahedra.clear();
  gr->tetrahedra.insert(gr->tetrahedra.begin(), ts.begin(), ts.end());

  //  printf("FILTER3D : AFTER FILTERING %d tets remain %d nodes on the boundary\n", gr->tetrahedra.size(), not_touched.size());
  return not_touched;
}

void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p)
{
  int samples = 30;

//  int method = Mesh::METHOD_RELAXBND | Mesh::METHOD_PHYSCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_FIXBND | Mesh::METHOD_PHYSCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_FIXBND | Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_FIXBND;
//  int method = Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
//  int method = Mesh::METHOD_RELAXBND | Mesh::METHOD_SURFCOORD | Mesh::METHOD_PROJJAC;
  int method = Mesh::METHOD_PROJJAC;

  SVector3 BND(gm->bounds().max(), gm->bounds().min());
  double SIZE = BND.norm();

  if (p.dim == 2) {
    for (GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {

      if (p.onlyVisible && !(*itf)->getVisibility())continue;
      std::vector<MTriangle*> tris = (*itf)->triangles;
      std::vector<MQuadrangle*> quas = (*itf)->quadrangles;
      std::set<MVertex*> toFix = filter2D(*itf, p.nbLayers, p.BARRIER);
      OptHOM *temp = new OptHOM(*itf, toFix, method);
      (*itf)->triangles = tris;
      (*itf)->quadrangles = quas;

      double distMaxBND, distAvgBND, minJac, maxJac;
      temp->getDistances(distMaxBND, distAvgBND, minJac, maxJac);
      //      std::ostringstream ossI;
      //      ossI << "initial_" << (*itf)->tag() << ".msh";
      //      temp->mesh.writeMSH(ossI.str().c_str());
      //      printf("--> Mesh Loaded for GFace %d :  minJ %12.5E -- maxJ %12.5E\n", (*itf)->tag(), minJac, maxJac);
      if (distMaxBND < 1.e-8 * SIZE && minJac > p.BARRIER) continue;
      p.SUCCESS = temp->optimize(p.weightFixed, p.weightFree, p.BARRIER, samples, p.itMax, p.minJac, p.maxJac);
      temp->mesh.updateGEntityPositions();
      //      std::ostringstream ossF;
      //      ossF << "final_" << (*itf)->tag() << ".msh";
      //      temp->mesh.writeMSH(ossF.str().c_str());
    }
  }
  else if (p.dim == 3) {
    for (GModel::riter itr = gm->firstRegion(); itr != gm->lastRegion(); ++itr) {
      if (p.onlyVisible && !(*itr)->getVisibility())continue;
      std::vector<MTetrahedron*> tets = (*itr)->tetrahedra;
      std::set<MVertex*> toFix;
      filter3D(*itr, p.nbLayers, p.BARRIER);
      OptHOM *temp = new OptHOM(*itr, toFix, method);
      double distMaxBND, distAvgBND, minJac, maxJac;
      temp->getDistances(distMaxBND, distAvgBND, minJac, maxJac);
      //      temp->mesh.writeMSH("initial.msh");
      //      printf("--> Mesh Loaded for GRegion %d :  minJ %12.5E -- maxJ %12.5E\n", (*itr)->tag(), minJac, maxJac);
      if (distMaxBND < 1.e-8 * SIZE && minJac > p.BARRIER) continue;
      p.SUCCESS = temp->optimize(p.weightFixed, p.weightFree, p.BARRIER, samples, p.itMax, p.minJac, p.maxJac);
      temp->mesh.updateGEntityPositions();
      (*itr)->tetrahedra = tets;
      //      temp->mesh.writeMSH("final.msh");
    }
  }  
}
