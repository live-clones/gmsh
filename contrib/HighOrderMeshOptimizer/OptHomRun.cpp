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
#include <stack>

static std::set<MVertex*> filter(GEntity *gf, int nbLayers, double _qual, std::set<MElement*> &elements, bool onlytheworst = false)
{
  elements.clear();
  std::set<MVertex*> touched;
  std::set<MVertex*> not_touched;
  double minQ = 1e22;
  MElement *worst;
  for (unsigned int i = 0; i < gf->getNumMeshElements(); ++i) {
    MElement *el = gf->getMeshElement(i);
    double Q = el->distoShapeMeasure();
    if (Q < _qual || Q > 1.01) {
      if (Q < minQ) {
        worst = el;
        minQ = Q;
      }
      if (!onlytheworst) {
        elements.insert(el);
      }
    }
  }
  if (onlytheworst) {
    elements.insert(worst);
  }
  for (std::set<MElement*>::iterator it = elements.begin(); it != elements.end(); ++it) {
    MElement &el = **it;
    for (int j = 0; j < el.getNumVertices(); j++)
      touched.insert(el.getVertex(j));
  }
  Msg::Info("FILTER2D : %d bad elements found among %6d\n", elements.size(), gf->getNumMeshElements());

  // add layers of elements around bad elements
  for (int layer = 0; layer < nbLayers; layer++) {
    for (unsigned int i = 0; i < gf->getNumMeshElements(); ++i) {
      MElement *el = gf->getMeshElement(i);
      for (int j = 0; j < el->getNumVertices(); ++j) {
        if (touched.find(el->getVertex(j)) != touched.end()) {
          elements.insert(el);
          break;
        }
      }
    }
    for (std::set<MElement *>::iterator it = elements.begin(); it != elements.end(); ++it) {
      MElement &el = **it;
      for (int j = 0; j < el.getNumVertices(); ++j) {
        touched.insert(el.getVertex(j));
      }
    }
  }
  for (unsigned int i = 0; i < gf->getNumMeshElements(); ++i) {
    MElement &el = *gf->getMeshElement(i);
    for (int j = 0; j < el.getNumVertices(); ++j) {
      if (touched.find(el.getVertex(j)) == touched.end()) {
        not_touched.insert(el.getVertex(j));
      }
    }
  }

  //  printf("FILTER2D : AFTER FILTERING %d triangles %d quads remain %d nodes on the boundary\n", gf->triangles.size(), gf->quadrangles.size(), not_touched.size());
  return not_touched;
}

static std::vector<std::set<MElement*> > splitConnex(const std::set<MElement*> &in)
{
  std::map<int, std::vector<int> > vertex2elements;
  std::vector<MElement *> elements(in.begin(), in.end());
  for (size_t i = 0; i < elements.size(); ++i) {
    for (int j = 0; j < elements[i]->getNumPrimaryVertices(); ++j) {
      vertex2elements[elements[i]->getVertex(j)->getNum()].push_back(i);
    }
  }
  std::vector<int> colors(elements.size(), -1);
  int color = 0;
  for (size_t i = 0; i < elements.size(); ++i) {
    if (colors[i] == -1) {
      colors[i] = color;
      std::stack<int> todo;
      todo.push(i);
      while (! todo.empty()) {
        int top = todo.top();
        todo.pop();
        for (int j = 0; j < elements[top]->getNumPrimaryVertices(); ++j) {
          const std::vector<int> &neighbours = vertex2elements[elements[top]->getVertex(j)->getNum()];
          for (size_t k = 0; k < neighbours.size(); ++k) {
            if (colors[neighbours[k]] == -1) {
              colors[neighbours[k]] = color;
              todo.push(neighbours[k]);
            }
          }
        }
      }
      color ++;
    }
  }
  std::vector<std::set<MElement*> > splitted(color);
  for (size_t i = 0; i < elements.size(); ++i) {
    splitted[colors[i]].insert(elements[i]);
  }
  return splitted;
}

void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p)
{
  int samples = 20;

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
      std::set<MElement*> elements;
      std::set<MVertex*> toFix = filter(*itf, p.nbLayers, p.BARRIER, elements);
      std::vector<std::set<MElement*> > splitted = splitConnex(elements);
      for (size_t i = 0; i < splitted.size(); ++i) {
        OptHOM *temp = new OptHOM(*itf, splitted[i], toFix, method);
        double distMaxBND, distAvgBND, minJac, maxJac;
        temp->recalcJacDist();
        temp->getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
        if (distMaxBND < 1.e-8 * SIZE && minJac > p.BARRIER) continue;
        p.SUCCESS = temp->optimize(p.weightFixed, p.weightFree, p.BARRIER, samples, p.itMax);
        temp->getJacDist(p.minJac, p.maxJac, distMaxBND, distAvgBND);
        temp->mesh.updateGEntityPositions();
        delete temp;
      }
    }
  }
  else if (p.dim == 3) {
    for (GModel::riter itr = gm->firstRegion(); itr != gm->lastRegion(); ++itr) {
      if (p.onlyVisible && !(*itr)->getVisibility())continue;
      std::vector<MTetrahedron*> tets = (*itr)->tetrahedra;
      std::set<MElement*> elements;
      std::set<MVertex*> toFix = filter(*itr, p.nbLayers, p.BARRIER, elements);
      OptHOM *temp = new OptHOM(*itr, elements, toFix, method);
      double distMaxBND, distAvgBND, minJac, maxJac;
      temp->recalcJacDist();
      temp->getJacDist(minJac, maxJac, distMaxBND, distAvgBND);
      //      temp->mesh.writeMSH("initial.msh");
      //      printf("--> Mesh Loaded for GRegion %d :  minJ %12.5E -- maxJ %12.5E\n", (*itr)->tag(), minJac, maxJac);
      if (distMaxBND < 1.e-8 * SIZE && minJac > p.BARRIER) continue;
      p.SUCCESS = temp->optimize(p.weightFixed, p.weightFree, p.BARRIER, samples, p.itMax);
      temp->getJacDist(p.minJac, p.maxJac, distMaxBND, distAvgBND);
      temp->mesh.updateGEntityPositions();
      (*itr)->tetrahedra = tets;
      //      temp->mesh.writeMSH("final.msh");
    }
  }  
}
