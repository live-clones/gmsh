// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Octree.h"
#include "GModel.h"
#include "MVertex.h"
#include "MVertexOctree.h"
#include "SBoundingBox3d.h"

static void MVertexBB(void *a, double *min, double *max)
{
  MVertex *v = (MVertex*)a;
  double tol = MVertexLessThanLexicographic::tolerance;
  min[0] = v->x() - tol;
  max[0] = v->x() + tol;
  min[1] = v->y() - tol;
  max[1] = v->y() + tol;
  min[2] = v->z() - tol;
  max[2] = v->z() + tol;
}

static void MVertexCentroid(void *a, double *x)
{
  MVertex *v = (MVertex*)a;
  x[0] = v->x();
  x[1] = v->y();
  x[2] = v->z();
}

static int MVertexInEle(void *a, double *x)
{
  MVertex *v = (MVertex*)a;
  double d = sqrt((x[0] - v->x()) * (x[0] - v->x()) +
                  (x[1] - v->y()) * (x[1] - v->y()) +
                  (x[2] - v->z()) * (x[2] - v->z()));
  return (d < MVertexLessThanLexicographic::tolerance);
}

MVertexOctree::MVertexOctree(GModel *m)
{
  SBoundingBox3d bb = m->bounds();
  double min[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
  double size[3] = {bb.max().x() - bb.min().x(),
                    bb.max().y() - bb.min().y(),
                    bb.max().z() - bb.min().z()};
  const int maxElePerBucket = 100; // memory vs. speed trade-off
  _octree = Octree_Create(maxElePerBucket, min, size,
                          MVertexBB, MVertexCentroid, MVertexInEle);
}

MVertexOctree::~MVertexOctree()
{
  Octree_Delete(_octree);
}

void MVertexOctree::insert(MVertex *v)
{
  Octree_Insert(v, _octree);
}

void MVertexOctree::finalize()
{
  Octree_Arrange(_octree);
}

MVertex *MVertexOctree::find(double x, double y, double z)
{
  double P[3] = {x, y, z};
  return (MVertex*)Octree_Search(P, _octree);
}
