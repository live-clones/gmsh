// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <map>
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

// The Bezier control points of a curved element, which bound it, as a linear
// combination of its nodes: the same for all the elements of a type, so
// computed once per type rather than by evaluating each element at the
// sampling points of its Bezier basis and converting them (MElement::
// getBezierVerticesCoord), which took 11 us per element, i.e. most of the 28 s
// the octree of 2.5 million second-order tetrahedra took to build. Kept per
// thread, as octrees can be built concurrently.
static const fullMatrix<double> *lagrangeToBezier(MElement *e)
{
  thread_local std::map<int, fullMatrix<double> > cache;
  int type = e->getTypeForMSH();
  auto it = cache.find(type);
  if(it != cache.end()) return &it->second;
  const bezierBasis *basis =
    BasisFactory::getBezierBasis(e->getType(), e->getPolynomialOrder());
  const fullMatrix<double> &uvw = basis->getSamplingPointsToComputeBezierCoeff();
  int n = e->getNumShapeFunctions();
  fullMatrix<double> sf(uvw.size1(), n);
  double f[1256];
  for(int i = 0; i < uvw.size1(); i++) {
    double p[3] = {0., 0., 0.};
    for(int j = 0; j < uvw.size2(); j++) p[j] = uvw(i, j);
    e->getShapeFunctions(p[0], p[1], p[2], f);
    for(int j = 0; j < n; j++) sf(i, j) = f[j];
  }
  // the conversion to Bezier coefficients is linear, column by column
  bezierCoeff b(e->getFuncSpaceData(e->getPolynomialOrder(), false), sf);
  fullMatrix<double> &m = cache[type];
  m.resize(b.getNumCoeff(), b.getNumColumns());
  for(int i = 0; i < m.size1(); i++)
    for(int j = 0; j < m.size2(); j++) m(i, j) = b(i, j);
  return &m;
}

void MElementBB(void *a, double *min, double *max)
{
  MElement *e = static_cast<MElement *>(a);

  const fullMatrix<double> *m = nullptr;
  int n = e->getNumShapeFunctions();
  if(e->getPolynomialOrder() > 1 && n <= 1256) {
    m = lagrangeToBezier(e);
    if(m->size2() != n || !m->size1()) m = nullptr;
  }

  if(m) {
    double x[3 * 1256];
    for(int j = 0; j < n; j++) {
      const MVertex *v = e->getShapeFunctionNode(j);
      x[3 * j] = v->x();
      x[3 * j + 1] = v->y();
      x[3 * j + 2] = v->z();
    }
    for(int i = 0; i < m->size1(); i++) {
      double p[3] = {0., 0., 0.};
      for(int j = 0; j < n; j++) {
        double c = (*m)(i, j);
        p[0] += c * x[3 * j];
        p[1] += c * x[3 * j + 1];
        p[2] += c * x[3 * j + 2];
      }
      for(int k = 0; k < 3; k++) {
        if(!i || p[k] < min[k]) min[k] = p[k];
        if(!i || p[k] > max[k]) max[k] = p[k];
      }
    }
  }
  else if(e->getPolynomialOrder() == 1) {
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

MElement *MElementOctree::findClosest(double x, double y, double z, int dim,
                                      double distance) const
{
  if(dim < 0 || dim > 3 || distance < 0.) return nullptr;
  double P[3] = {x, y, z};
  std::vector<void *> v;
  Octree_SearchAllWithin(P, _octree[dim], distance, &v);
  MElement *best = nullptr;
  double bestDistance = distance;
  const double tol = 1e-3;
  for(auto it = v.begin(); it != v.end(); ++it) {
    MElement *e = (MElement *)*it;
    // the coordinates of the point in the element, those across it (off a
    // curve or a surface) left out of the test and measured instead
    double uvw[3];
    e->xyz2uvw(P, uvw);
    for(int k = e->getDim(); k < 3; k++) uvw[k] = 0.;
    if(!e->isInside(uvw[0], uvw[1], uvw[2], tol)) continue;
    SPoint3 q;
    e->pnt(uvw[0], uvw[1], uvw[2], q);
    double d = std::sqrt((q.x() - x) * (q.x() - x) + (q.y() - y) * (q.y() - y) +
                         (q.z() - z) * (q.z() - z));
    if(d <= bestDistance) {
      best = e;
      bestDistance = d;
    }
  }
  return best;
}

MElement *MElementOctree::find(double x, double y, double z, int dim,
                               bool strict, double tol) const
{
  double P[3] = {x, y, z};
  std::vector<MElement *> e = _find(P, dim, tol, strict, _gm ? 1. : 0.1, true);
  return e.empty() ? nullptr : e[0];
}
