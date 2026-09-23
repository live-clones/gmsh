// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Octree.h"
#include "OctreePost.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "shapeFunctions.h"
#include "GModel.h"
#include "MElement.h"
#include "Context.h"
#include "SBoundingBox3d.h"

// helper routines for list-based views

static void minmax(int n, double *X, double *Y, double *Z, double *min,
                   double *max)
{
  min[0] = X[0];
  min[1] = Y[0];
  min[2] = Z[0];
  max[0] = X[0];
  max[1] = Y[0];
  max[2] = Z[0];
  for(int i = 1; i < n; i++) {
    min[0] = (X[i] < min[0]) ? X[i] : min[0];
    min[1] = (Y[i] < min[1]) ? Y[i] : min[1];
    min[2] = (Z[i] < min[2]) ? Z[i] : min[2];
    max[0] = (X[i] > max[0]) ? X[i] : max[0];
    max[1] = (Y[i] > max[1]) ? Y[i] : max[1];
    max[2] = (Z[i] > max[2]) ? Z[i] : max[2];
  }

  SBoundingBox3d bb(min[0], min[1], min[2], max[0], max[1], max[2]);

  if(CTX::instance()->mesh.algo2d == ALGO_2D_PACK_PRLGRMS ||
     CTX::instance()->mesh.algo2d == ALGO_2D_QUAD_QUASI_STRUCT) {
    /* TODO FIXME: ugly temporary fix, but we need larger bbox for the
     * guiding field sampling on curved surfaces, thicken is not sufficient */
    bb *= 1.1;
    bb.makeCube();
  }
  else {
    bb.thicken(0.01); // make 1% thicker
  }

  max[0] = bb.max().x();
  max[1] = bb.max().y();
  max[2] = bb.max().z();
  min[0] = bb.min().x();
  min[1] = bb.min().y();
  min[2] = bb.min().z();
}

// the bounding box of an element of N nodes, and whether a point is in it
template <int N> static void elementBB(void *a, double *min, double *max)
{
  double *X = (double *)a;
  minmax(N, X, X + N, X + 2 * N, min, max);
}

template <class E, int N> static int inElement(void *a, double *x)
{
  double *X = (double *)a, uvw[3];
  E e(X, X + N, X + 2 * N);
  e.xyz2uvw(x, uvw);
  return e.isInside(uvw[0], uvw[1], uvw[2]);
}

static int inPoint(void *a, double *x) { return 1; }

// the kinds of elements of list data, in the order of their lists in
// PViewDataList::getListPointers() (3 lists each, for 1, 3 and 9 components)
static const struct {
  int numNodes, dim;
  void (*bb)(void *, double *, double *);
  int (*in)(void *, double *);
} listElement[8] = {{1, 0, elementBB<1>, inPoint},
                    {2, 1, elementBB<2>, inElement<line, 2>},
                    {3, 2, elementBB<3>, inElement<triangle, 3>},
                    {4, 2, elementBB<4>, inElement<quadrangle, 4>},
                    {4, 3, elementBB<4>, inElement<tetrahedron, 4>},
                    {8, 3, elementBB<8>, inElement<hexahedron, 8>},
                    {6, 3, elementBB<6>, inElement<prism, 6>},
                    {5, 3, elementBB<5>, inElement<pyramid, 5>}};

// the order in which they are searched: volumes first
static const int searchOrder[8] = {4, 5, 6, 7, 2, 3, 1, 0};

static int componentIndex(int numComp)
{ return (numComp == 1) ? 0 : (numComp == 3) ? 1 : 2; }

// OctreePost implementation

OctreePost::~OctreePost()
{
  for(int c = 0; c < 3; c++)
    for(int k = 0; k < 8; k++) Octree_Delete(_trees[c][k]);
}

OctreePost::OctreePost(PView *v)
{
  _create(v->getData(true)); // use adaptive data if available
}

OctreePost::OctreePost(PViewData *data) { _create(data); }

void OctreePost::_create(PViewData *data)
{
  for(int c = 0; c < 3; c++)
    for(int k = 0; k < 8; k++) _trees[c][k] = nullptr;
  _theViewDataList = nullptr;

  _theViewDataGModel = dynamic_cast<PViewDataGModel *>(data);

  if(_theViewDataGModel) return; // the octree is already available in the model

  _theViewDataList = dynamic_cast<PViewDataList *>(data);

  if(_theViewDataList) {
    PViewDataList *l = _theViewDataList;

    if(l->haveInterpolationMatrices() && !l->isAdapted()) {
      Msg::Error("Cannot create octree for non-adapted high-order list-based "
                 "view: you need");
      Msg::Error("to select 'Adapt visualization grid' first");
      return;
    }

    int N[24];
    std::vector<double> *V[24];
    l->getListPointers(N, V);
    const int numComp[3] = {1, 3, 9};
    for(int k = 0; k < 8; k++) {
      for(int c = 0; c < 3; c++) {
        Octree *o = Octree_Create(listElement[k].bb, listElement[k].in);
        // an element: its coordinates, then its values at each step
        int n = listElement[k].numNodes;
        std::size_t size = n * (3 + numComp[c] * l->getNumTimeSteps());
        std::vector<double> &list = *V[3 * k + c];
        for(std::size_t i = 0; i < list.size(); i += size)
          Octree_Insert(&list[i], o);
        Octree_Arrange(o);
        _trees[c][k] = o;
      }
    }
  }
}

static void *getElement(double P[3], Octree *octree, int nbNod, int qn,
                        double *qx, double *qy, double *qz)
{
  if(qn && qx && qy && qz) {
    std::vector<void *> v;
    Octree_SearchAll(P, octree, &v);
    if(nbNod == qn) {
      // try to use the value from the same geometrical element as the one
      // provided in qx/y/z
      double eps = CTX::instance()->geom.tolerance;
      for(std::size_t i = 0; i < v.size(); i++) {
        double *X = (double *)v[i], *Y = &X[qn], *Z = &X[2 * qn];
        bool ok = true;
        for(int j = 0; j < qn; j++) {
          ok &= (fabs(X[j] - qx[j]) < eps && fabs(Y[j] - qy[j]) < eps &&
                 fabs(Z[j] - qz[j]) < eps);
        }
        if(ok) return v[i];
      }
    }
    if(v.size()) return v[0];
  }
  else {
    return Octree_Search(P, octree);
  }
  return nullptr;
}

static MElement *getElement(double P[3], GModel *m, int qn, double *qx,
                            double *qy, double *qz, int dim)
{
  SPoint3 pt(P);
  if(qn && qx && qy && qz) {
    // try to use the value from the same geometrical element as the one
    // provided in qx/y/z
    double eps = CTX::instance()->geom.tolerance;
    std::vector<MElement *> elements = m->getMeshElementsByCoord(pt, dim);
    for(std::size_t i = 0; i < elements.size(); i++) {
      if(qn == static_cast<int>(elements[i]->getNumVertices())) {
        bool ok = true;
        for(int j = 0; j < qn; j++) {
          MVertex *v = elements[i]->getVertex(j);
          ok &=
            (std::abs(v->x() - qx[j]) < eps && std::abs(v->y() - qy[j]) < eps &&
             std::abs(v->z() - qz[j]) < eps);
        }
        if(ok) return elements[i];
      }
    }
    if(elements.size()) return elements[0];
  }
  else {
    // TODO sort the elements by decreasing dimension and return the first match
    //- this will be consistent with what we do for list-based datasets
    //
    // std::vector<MElement *> elements = m->getMeshElementsByCoord(pt, dim);
    SPoint3 uvw;
    return m->getMeshElementByCoord(pt, uvw, dim);
  }
  return nullptr;
}

bool OctreePost::_getValue(void *in, int dim, int nbNod, int nbComp,
                           double P[3], int step, double *values,
                           double *elementSize, bool grad)
{
  if(!in) return false;

  double *X = (double *)in, *Y = &X[nbNod], *Z = &X[2 * nbNod],
         *V = &X[3 * nbNod], U[3];

  elementFactory factory;
  element *e = factory.create(nbNod, dim, X, Y, Z);
  if(!e) return false;

  e->xyz2uvw(P, U);
  if(step < 0) {
    for(int i = 0; i < _theViewDataList->getNumTimeSteps(); i++) {
      for(int j = 0; j < nbComp; j++) {
        if(!grad) {
          values[nbComp * i + j] = e->interpolate(&V[nbNod * nbComp * i + j],
                                                  U[0], U[1], U[2], nbComp);
        }
        else {
          e->interpolateGrad(&V[nbNod * nbComp * i + j], U[0], U[1], U[2],
                             &values[3 * (nbComp * i + j)], nbComp);
        }
      }
    }
  }
  else {
    for(int j = 0; j < nbComp; j++) {
      if(!grad) {
        values[j] = e->interpolate(&V[nbNod * nbComp * step + j], U[0], U[1],
                                   U[2], nbComp);
      }
      else
        e->interpolateGrad(&V[nbNod * nbComp * step + j], U[0], U[1], U[2],
                           &values[3 * j], nbComp);
    }
  }

  if(elementSize) *elementSize = e->maxEdgeLength();

  delete e;
  return true;
}

bool OctreePost::_getValue(void *in, int nbComp, double P[3], int timestep,
                           double *values, double *elementSize, bool grad)
{
  if(!in) return false;

  if(_theViewDataGModel->getNumComponents(0, 0, 0) != nbComp) return false;

  MElement *e = (MElement *)in;

  std::vector<int> dataIndex(e->getNumVertices());
  if(_theViewDataGModel->getType() == PViewDataGModel::NodeData)
    for(std::size_t i = 0; i < e->getNumVertices(); i++)
      dataIndex[i] = e->getVertex(i)->getNum();
  else
    for(std::size_t i = 0; i < e->getNumVertices(); i++)
      dataIndex[i] = e->getNum();

  double U[3];
  e->xyz2uvw(P, U);

  std::vector<double> nodeval(e->getNumVertices() * 9);
  for(int step = 0; step < _theViewDataGModel->getNumTimeSteps(); step++) {
    if(!_theViewDataGModel->hasTimeStep(step)) continue;
    if(timestep < 0 || step == timestep) {
      for(std::size_t nod = 0; nod < e->getNumVertices(); nod++) {
        for(int comp = 0; comp < nbComp; comp++)
          _theViewDataGModel->getValueByIndex(step, dataIndex[nod], nod, comp,
                                              nodeval[nod * nbComp + comp]);
      }
      for(int comp = 0; comp < nbComp; comp++) {
        if(!grad) {
          double val = e->interpolate(&nodeval[comp], U[0], U[1], U[2], nbComp);
          if(timestep < 0)
            values[nbComp * step + comp] = val;
          else
            values[comp] = val;
        }
        else {
          if(timestep < 0)
            e->interpolateGrad(&nodeval[comp], U[0], U[1], U[2],
                               &values[3 * (nbComp * step + comp)], nbComp);
          else
            e->interpolateGrad(&nodeval[comp], U[0], U[1], U[2],
                               &values[3 * comp], nbComp);
        }
      }
    }
  }

  if(elementSize) *elementSize = e->maxEdge();
  return true;
}

bool OctreePost::_search(int numComp, double x, double y, double z,
                         double *values, int step, double *size, int qn,
                         double *qx, double *qy, double *qz, bool grad, int dim)
{
  double P[3] = {x, y, z};
  int mult = grad ? 3 : 1;

  int numSteps = 1;
  if(step < 0) {
    if(_theViewDataList)
      numSteps = _theViewDataList->getNumTimeSteps();
    else if(_theViewDataGModel)
      numSteps = _theViewDataGModel->getNumTimeSteps();
  }
  for(int i = 0; i < numComp * numSteps * mult; i++) values[i] = 0.;

  if(_theViewDataList) {
    int c = componentIndex(numComp);
    for(int k : searchOrder) {
      int n = listElement[k].numNodes, d = listElement[k].dim;
      if((dim < 0 || dim == d) &&
         _getValue(getElement(P, _trees[c][k], n, qn, qx, qy, qz), d, n,
                   numComp, P, step, values, size, grad))
        return true;
    }
  }
  else if(_theViewDataGModel) {
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m) {
      MElement *e = getElement(P, m, qn, qx, qy, qz, dim);
      if(_getValue(e, numComp, P, step, values, size, grad)) return true;
    }
  }

  return false;
}

bool OctreePost::searchScalar(double x, double y, double z, double *values,
                              int step, double *size, int qn, double *qx,
                              double *qy, double *qz, bool grad, int dim)
{ return _search(1, x, y, z, values, step, size, qn, qx, qy, qz, grad, dim); }

bool OctreePost::searchVector(double x, double y, double z, double *values,
                              int step, double *size, int qn, double *qx,
                              double *qy, double *qz, bool grad, int dim)
{ return _search(3, x, y, z, values, step, size, qn, qx, qy, qz, grad, dim); }

bool OctreePost::searchTensor(double x, double y, double z, double *values,
                              int step, double *size, int qn, double *qx,
                              double *qy, double *qz, bool grad, int dim)
{ return _search(9, x, y, z, values, step, size, qn, qx, qy, qz, grad, dim); }
