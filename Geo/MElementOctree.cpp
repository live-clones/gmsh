// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MElement.h"
#include "GModel.h"
#include "Octree.h"
#include "MVertex.h"

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

Octree *buildMElementOctree(GModel *m)
{
  SBoundingBox3d bb = m->bounds();
  double min[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
  double size[3] = {bb.max().x() - bb.min().x(),
                    bb.max().y() - bb.min().y(),
                    bb.max().z() - bb.min().z()};
  const int maxElePerBucket = 100; // memory vs. speed trade-off
  Octree *_octree = Octree_Create(maxElePerBucket, min, size,
                                  MElementBB, MElementCentroid, MElementInEle);
  std::vector<GEntity*> entities;
  m->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
      Octree_Insert(entities[i]->getMeshElement(j), _octree);
  Octree_Arrange(_octree);
  return _octree;
}

Octree *buildMElementOctree(std::vector<MElement*> &v)
{
  SBoundingBox3d bb;
  for (unsigned int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i]->getNumVertices(); j++){
      bb += SPoint3(v[i]->getVertex(j)->x(),
                    v[i]->getVertex(j)->y(),
                    v[i]->getVertex(j)->z());
    }
  }
  double min[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
  double size[3] = {bb.max().x() - bb.min().x(),
                    bb.max().y() - bb.min().y(),
                    bb.max().z() - bb.min().z()};
  const int maxElePerBucket = 100; // memory vs. speed trade-off
  Octree *_octree = Octree_Create(maxElePerBucket, min, size,
                                  MElementBB, MElementCentroid, MElementInEle);
  for (unsigned int i = 0; i < v.size(); i++)
    Octree_Insert(v[i], _octree);
  Octree_Arrange(_octree);
  return _octree;
}
