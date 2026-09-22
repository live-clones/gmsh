// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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

int MElementInEle(void *a, double *x)
{
  MElement *e = (MElement *)a;
  double uvw[3];
  e->xyz2uvw(x, uvw);
  return e->isInside(uvw[0], uvw[1], uvw[2]) ? 1 : 0;
}

void MElementOctree::_insert(MElement *e)
{
  int dim = e->getDim();
  if(dim < 0 || dim > 3) return;
  Octree_Insert(e, _octree[dim]);
  _maxOrder = std::max(_maxOrder, e->getPolynomialOrder());
}

MElementOctree::MElementOctree(GModel *m) : _gm(m), _maxOrder(1)
{
  for(int d = 0; d < 4; d++)
    _octree[d] = Octree_Create(MElementBB, MElementInEle);
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  // do not add Gvertex non-associated to any GEdge
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      if(entities[i]->dim() == 0) {
        GVertex *gv = dynamic_cast<GVertex *>(entities[i]);
        if(gv && gv->edges().size() > 0) {
          _insert(entities[i]->getMeshElement(j));
        }
      }
      else
        _insert(entities[i]->getMeshElement(j));
    }
  }
  for(int d = 0; d < 4; d++) Octree_Arrange(_octree[d]);
}

MElementOctree::MElementOctree(const std::vector<MElement *> &v)
  : _gm(nullptr), _maxOrder(1)
{
  for(int d = 0; d < 4; d++)
    _octree[d] = Octree_Create(MElementBB, MElementInEle);
  for(std::size_t i = 0; i < v.size(); i++) _insert(v[i]);
  for(int d = 0; d < 4; d++) Octree_Arrange(_octree[d]);
}

MElementOctree::~MElementOctree()
{
  for(int d = 0; d < 4; d++) Octree_Delete(_octree[d]);
}

// Get the elements of dimension dim (all if dim == -1) containing the point,
// in the reference element enlarged by tol: all of them, by increasing
// dimension, or only the first one, trying the highest dimension first.
std::vector<MElement *> MElementOctree::_find(double *P, int dim, double tol,
                                              bool onlyFirst) const
{
  std::vector<MElement *> e;
  int dmin = (dim < 0) ? 0 : dim, dmax = (dim < 0) ? 3 : dim;
  for(int i = dmin; i <= dmax; i++) {
    int d = onlyFirst ? dmax + dmin - i : i;
    // a point inside the reference element enlarged by tol lies within about
    // 4 tol times the element size of its bounding box (the enlarged reference
    // tetrahedron is the original one scaled by 1 + 4 tol); more for curved
    // elements
    std::vector<void *> v;
    Octree_SearchAllNear(P, _octree[d], 4. * _maxOrder * tol, &v);
    for(auto it = v.begin(); it != v.end(); ++it) {
      MElement *el = (MElement *)*it;
      double uvw[3];
      el->xyz2uvw(P, uvw);
      if(el->isInside(uvw[0], uvw[1], uvw[2], tol)) {
        e.push_back(el);
        if(onlyFirst) return e;
      }
    }
  }
  return e;
}

// Search with the tolerance tol (Mesh.ToleranceReferenceElement if negative),
// then, if nothing is found and not strict, with the tolerance multiplied by
// 10 until something is found or it reaches maxTol.
std::vector<MElement *> MElementOctree::_find(double *P, int dim, double tol,
                                              bool strict, double maxTol,
                                              bool onlyFirst) const
{
  if(dim > 3) return {};
  if(tol < 0) tol = CTX::instance()->mesh.toleranceReferenceElement;
  std::vector<MElement *> e = _find(P, dim, tol, onlyFirst);
  if(strict) return e;
  while(e.empty() && tol < maxTol) {
    tol *= 10.;
    e = _find(P, dim, tol, onlyFirst);
  }
  return e;
}

std::vector<MElement *> MElementOctree::findAll(double x, double y, double z,
                                                int dim, bool strict,
                                                double tol) const
{
  double P[3] = {x, y, z};
  return _find(P, dim, tol, strict, 1., false);
}

MElement *MElementOctree::find(double x, double y, double z, int dim,
                               bool strict, double tol) const
{
  double P[3] = {x, y, z};
  std::vector<MElement *> e = _find(P, dim, tol, strict, _gm ? 1. : 0.1, true);
  return e.empty() ? nullptr : e[0];
}
