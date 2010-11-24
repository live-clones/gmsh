// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "Octree.h"
#include "Context.h"

static void MElementBB(void *a, double *min, double *max)
{
  MElement *e = (MElement*)a;
  MVertex *v = e->getVertex(0);
  min[0] = max[0] = v->x();
  min[1] = max[1] = v->y();
  min[2] = max[2] = v->z();
  for(int i = 1; i < e->getNumVertices(); i++){
    v = e->getVertex(i);
    min[0] = std::min(min[0], v->x()); max[0] = std::max(max[0], v->x());
    min[1] = std::min(min[1], v->y()); max[1] = std::max(max[1], v->y());
    min[2] = std::min(min[2], v->z()); max[2] = std::max(max[2], v->z());
  }

  // make bounding boxes larger up to (absolute) geometrical tolerance
  double eps = CTX::instance()->geom.tolerance;
  for(int i = 0; i < 3; i++){
    min[i] -= eps;
    max[i] += eps;
  }
}

static void MElementCentroid(void *a, double *x)
{
  MElement *e = (MElement*)a;
  MVertex *v = e->getVertex(0);
  int n = e->getNumVertices();
  x[0] = v->x(); x[1] = v->y(); x[2] = v->z();
  for(int i = 1; i < n; i++) {
    v = e->getVertex(i);
    x[0] += v->x(); x[1] += v->y(); x[2] += v->z();
  }
  double oc = 1. / (double)n;
  x[0] *= oc;
  x[1] *= oc;
  x[2] *= oc;
}

static int MElementInEle(void *a, double *x)
{
  MElement *e = (MElement*)a;
  double uvw[3];
  e->xyz2uvw(x, uvw);
  return e->isInside(uvw[0], uvw[1], uvw[2]) ? 1 : 0;
}

MElementOctree::MElementOctree(GModel *m) : _gm(m)
{
  SBoundingBox3d bb = m->bounds();
  // make bounding box larger up to (absolute) geometrical tolerance
  double eps = CTX::instance()->geom.tolerance;
  SPoint3 bbmin = bb.min(), bbmax = bb.max(), bbeps(eps, eps, eps);
  bbmin -= bbeps;
  bbmax += bbeps;
  double min[3] = {bbmin.x(), bbmin.y(), bbmin.z()};
  double size[3] = {bbmax.x() - bbmin.x(),
                    bbmax.y() - bbmin.y(),
                    bbmax.z() - bbmin.z()};
  const int maxElePerBucket = 100; // memory vs. speed trade-off
  _octree = Octree_Create(maxElePerBucket, min, size,
                          MElementBB, MElementCentroid, MElementInEle);
  std::vector<GEntity*> entities;
  m->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
      Octree_Insert(entities[i]->getMeshElement(j), _octree);
  Octree_Arrange(_octree);
}

MElementOctree::MElementOctree(std::vector<MElement*> &v)
{
  SBoundingBox3d bb;
  for (unsigned int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i]->getNumVertices(); j++){
      if (!_gm) _gm = v[i]->getVertex(j)->onWhat()->model();
      bb += SPoint3(v[i]->getVertex(j)->x(),
                    v[i]->getVertex(j)->y(),
                    v[i]->getVertex(j)->z());
    }
  }
  // make bounding box larger up to (absolute) geometrical tolerance
  double eps = CTX::instance()->geom.tolerance;
  SPoint3 bbmin = bb.min(), bbmax = bb.max(), bbeps(eps, eps, eps);
  bbmin -= bbeps;
  bbmax += bbeps;
  double min[3] = {bbmin.x(), bbmin.y(), bbmin.z()};
  double size[3] = {bbmax.x() - bbmin.x(),
                    bbmax.y() - bbmin.y(),
                    bbmax.z() - bbmin.z()};
  const int maxElePerBucket = 100; // memory vs. speed trade-off
  _octree = Octree_Create(maxElePerBucket, min, size,
                          MElementBB, MElementCentroid, MElementInEle);
  for (unsigned int i = 0; i < v.size(); i++)
    Octree_Insert(v[i], _octree);
  Octree_Arrange(_octree);
}

MElementOctree::~MElementOctree()
{
  Octree_Delete(_octree);
}

MElement *MElementOctree::find(double x, double y, double z, int dim)
{
  double P[3] = {x, y, z};
  MElement *e = (MElement*)Octree_Search(P, _octree);

  if (!e || (dim != -1 && e->getDim() != dim)){
    double initialTol = MElement::getTolerance();
    double tol = initialTol;
    while (tol < 1){
      tol *= 10;
      MElement::setTolerance(tol);      
      std::vector<GEntity*> entities;
      _gm->getEntities(entities);
      for(unsigned int i = 0; i < entities.size(); i++){
	for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
	  e = entities[i]->getMeshElement(j);
	  if (dim == -1 ||  e->getDim() == dim){
	    if (MElementInEle(e, P)){
	      //	      printf("coucou FOUND\n");
	      MElement::setTolerance(initialTol);
	      return e;
	    }	    
	  }
	}
      }
    }
    MElement::setTolerance(initialTol);
    Msg::Warning("Point %g %g %g not found",x,y,z);
  }
  

  if (dim == -1 || !e || e->getDim() == dim)
    return e;
  std::list<void*> l;
  Octree_SearchAll(P, _octree, &l);
  for (std::list<void*>::iterator it = l.begin(); it != l.end(); it++) {
    MElement *el = (MElement*) *it;
    if (el->getDim() == dim)
      return el;
  }
  return NULL;
}
