// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "Octree.h"
#include "Context.h"
#include "fullMatrix.h"
#include "bezierBasis.h"
#include "BasisFactory.h"
#include "SBoundingBox3d.h"
#include "Context.h"

void MElementBB(void *a, double *min, double *max)
{
  MElement *e = static_cast<MElement *>(a);

  if(e->getPolynomialOrder() == 1) {
    MVertex *v = e->getVertex(0);
    min[0] = max[0] = v->x();
    min[1] = max[1] = v->y();
    min[2] = max[2] = v->z();
    for(std::size_t i = 1; i < e->getNumVertices(); i++) {
      v = e->getVertex(i);
      min[0] = std::min(min[0], v->x());
      max[0] = std::max(max[0], v->x());
      min[1] = std::min(min[1], v->y());
      max[1] = std::max(max[1], v->y());
      min[2] = std::min(min[2], v->z());
      max[2] = std::max(max[2], v->z());
    }
  }
  else {
    bezierCoeff &bezNodes = *e->getBezierVerticesCoord();

    min[0] = max[0] = bezNodes(0, 0);
    min[1] = max[1] = bezNodes(0, 1);
    min[2] = max[2] = bezNodes(0, 2);
    for(int i = 1; i < bezNodes.getNumCoeff(); i++) {
      min[0] = std::min(min[0], bezNodes(i, 0));
      max[0] = std::max(max[0], bezNodes(i, 0));
      min[1] = std::min(min[1], bezNodes(i, 1));
      max[1] = std::max(max[1], bezNodes(i, 1));
      min[2] = std::min(min[2], bezNodes(i, 2));
      max[2] = std::max(max[2], bezNodes(i, 2));
    }

    delete &bezNodes;
  }

  SBoundingBox3d bb(min[0], min[1], min[2], max[0], max[1], max[2]);
  bb.thicken(0.01); // make 1% thicker
  max[0] = bb.max().x();
  max[1] = bb.max().y();
  max[2] = bb.max().z();
  min[0] = bb.min().x();
  min[1] = bb.min().y();
  min[2] = bb.min().z();
}

static void MElementCentroid(void *a, double *x)
{
  MElement *e = (MElement *)a;
  MVertex *v = e->getVertex(0);
  int n = e->getNumVertices();
  x[0] = v->x();
  x[1] = v->y();
  x[2] = v->z();
  for(int i = 1; i < n; i++) {
    v = e->getVertex(i);
    x[0] += v->x();
    x[1] += v->y();
    x[2] += v->z();
  }
  double oc = 1. / (double)n;
  x[0] *= oc;
  x[1] *= oc;
  x[2] *= oc;
}

int MElementInEle(void *a, double *x)
{
  MElement *e = (MElement *)a;
  double uvw[3];
  e->xyz2uvw(x, uvw);
  return e->isInside(uvw[0], uvw[1], uvw[2]) ? 1 : 0;
}

MElementOctree::MElementOctree(GModel *m) : _gm(m)
{
  SBoundingBox3d bb = m->bounds();
  bb.thicken(0.01); // make 1% thicker
  SPoint3 bbmin = bb.min(), bbmax = bb.max();
  double min[3] = {bbmin.x(), bbmin.y(), bbmin.z()};
  double size[3] = {bbmax.x() - bbmin.x(), bbmax.y() - bbmin.y(),
                    bbmax.z() - bbmin.z()};
  const int maxElePerBucket = 100; // memory vs. speed trade-off
  _octree = Octree_Create(maxElePerBucket, min, size, MElementBB,
                          MElementCentroid, MElementInEle);
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  // do not add Gvertex non-associated to any GEdge
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      if(entities[i]->dim() == 0) {
        GVertex *gv = dynamic_cast<GVertex *>(entities[i]);
        if(gv && gv->edges().size() > 0) {
          Octree_Insert(entities[i]->getMeshElement(j), _octree);
        }
      }
      else
        Octree_Insert(entities[i]->getMeshElement(j), _octree);
    }
  }
  Octree_Arrange(_octree);
}

MElementOctree::MElementOctree(const std::vector<MElement *> &v)
  : _gm(nullptr), _elems(v)
{
  SBoundingBox3d bb;
  for(std::size_t i = 0; i < v.size(); i++) {
    for(std::size_t j = 0; j < v[i]->getNumVertices(); j++) {
      bb += SPoint3(v[i]->getVertex(j)->x(), v[i]->getVertex(j)->y(),
                    v[i]->getVertex(j)->z());
    }
  }
  bb.thicken(0.01); // make 1% thicker
  SPoint3 bbmin = bb.min(), bbmax = bb.max();
  double min[3] = {bbmin.x(), bbmin.y(), bbmin.z()};
  double size[3] = {bbmax.x() - bbmin.x(), bbmax.y() - bbmin.y(),
                    bbmax.z() - bbmin.z()};
  const int maxElePerBucket = 100; // memory vs. speed trade-off
  _octree = Octree_Create(maxElePerBucket, min, size, MElementBB,
                          MElementCentroid, MElementInEle);
  for(std::size_t i = 0; i < v.size(); i++) Octree_Insert(v[i], _octree);
  Octree_Arrange(_octree);
}

MElementOctree::~MElementOctree() { Octree_Delete(_octree); }

std::vector<MElement *> MElementOctree::findAll(double x, double y, double z,
                                                int dim, bool strict) const
{
  double maxTol = 1.;
  double tolIncr = 10.;

  double P[3] = {x, y, z};
  std::vector<void *> v;
  std::vector<MElement *> e;
  Octree_SearchAll(P, _octree, &v);
  for(auto it = v.begin(); it != v.end(); ++it) {
    MElement *el = (MElement *)*it;
    if(dim == -1 || el->getDim() == dim) e.push_back(el);
  }
  if(e.empty() && !strict && _gm) {
    double initialTol = CTX::instance()->mesh.toleranceReferenceElement;
    double tol = initialTol;
    while(tol < maxTol) {
      tol *= tolIncr;
      CTX::instance()->mesh.toleranceReferenceElement = tol;
      std::vector<GEntity *> entities;
      _gm->getEntities(entities);
      for(std::size_t i = 0; i < entities.size(); i++) {
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          MElement *el = entities[i]->getMeshElement(j);
          if(dim == -1 || el->getDim() == dim) {
            if(MElementInEle(el, P)) { e.push_back(el); }
          }
        }
      }
      if(!e.empty()) {
        CTX::instance()->mesh.toleranceReferenceElement = initialTol;
        return e;
      }
    }
    CTX::instance()->mesh.toleranceReferenceElement = initialTol;
  }
  else if(e.empty() && !strict && !_gm) {
    double initialTol = CTX::instance()->mesh.toleranceReferenceElement;
    double tol = initialTol;
    while(tol < maxTol) {
      tol *= tolIncr;
      CTX::instance()->mesh.toleranceReferenceElement = tol;
      for(std::size_t i = 0; i < _elems.size(); i++) {
        MElement *el = _elems[i];
        if(dim == -1 || el->getDim() == dim) {
          if(MElementInEle(el, P)) { e.push_back(el); }
        }
      }
      if(!e.empty()) {
        CTX::instance()->mesh.toleranceReferenceElement = initialTol;
        return e;
      }
    }
    CTX::instance()->mesh.toleranceReferenceElement = initialTol;
    // Msg::Warning("Point %g %g %g not found",x,y,z);
  }
  return e;
}

MElement *MElementOctree::find(double x, double y, double z, int dim,
                               bool strict) const
{
  double P[3] = {x, y, z};
  MElement *e = (MElement *)Octree_Search(P, _octree);
  if(e && (dim == -1 || e->getDim() == dim)) return e;
  std::vector<void *> l;
  if(e && e->getDim() != dim) {
    Octree_SearchAll(P, _octree, &l);
    for(auto it = l.begin(); it != l.end(); it++) {
      MElement *el = (MElement *)*it;
      if(el->getDim() == dim) { return el; }
    }
  }
  if(!strict && _gm) {
    double initialTol = CTX::instance()->mesh.toleranceReferenceElement;
    double tol = initialTol;
    while(tol < 1.) {
      tol *= 10;
      CTX::instance()->mesh.toleranceReferenceElement = tol;
      std::vector<GEntity *> entities;
      _gm->getEntities(entities);
      for(std::size_t i = 0; i < entities.size(); i++) {
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          e = entities[i]->getMeshElement(j);
          if(dim == -1 || e->getDim() == dim) {
            if(MElementInEle(e, P)) {
              CTX::instance()->mesh.toleranceReferenceElement = initialTol;
              return e;
            }
          }
        }
      }
    }
    CTX::instance()->mesh.toleranceReferenceElement = initialTol;
    // Msg::Warning("Point %g %g %g not found",x,y,z);
  }
  else if(!strict && !_gm) {
    double initialTol = CTX::instance()->mesh.toleranceReferenceElement;
    double tol = initialTol;
    while(tol < 0.1) {
      tol *= 10.0;
      CTX::instance()->mesh.toleranceReferenceElement = tol;
      for(std::size_t i = 0; i < _elems.size(); i++) {
        e = _elems[i];
        if(dim == -1 || e->getDim() == dim) {
          if(MElementInEle(e, P)) {
            CTX::instance()->mesh.toleranceReferenceElement = initialTol;
            return e;
          }
        }
      }
    }
    CTX::instance()->mesh.toleranceReferenceElement = initialTol;
    // Msg::Warning("Point %g %g %g not found",x,y,z);
  }
  return nullptr;
}
