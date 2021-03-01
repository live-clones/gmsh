// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  bb.thicken(0.01); // make 1% thicker
  max[0] = bb.max().x();
  max[1] = bb.max().y();
  max[2] = bb.max().z();
  min[0] = bb.min().x();
  min[1] = bb.min().y();
  min[2] = bb.min().z();
}

static void centroid(int n, double *X, double *Y, double *Z, double *c)
{
  const double oc = 1. / (double)n;
  c[0] = X[0];
  c[1] = Y[0];
  c[2] = Z[0];
  for(int i = 1; i < n; i++) {
    c[0] += X[i];
    c[1] += Y[i];
    c[2] += Z[i];
  }
  c[0] *= oc;
  c[1] *= oc;
  c[2] *= oc;
}

static void pntBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[1], *Z = &X[2];
  minmax(1, X, Y, Z, min, max);
}

static void linBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[2], *Z = &X[4];
  minmax(2, X, Y, Z, min, max);
}

static void triBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[3], *Z = &X[6];
  minmax(3, X, Y, Z, min, max);
}

static void quaBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

static void tetBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

static void hexBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[8], *Z = &X[16];
  minmax(8, X, Y, Z, min, max);
}

static void priBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[6], *Z = &X[12];
  minmax(6, X, Y, Z, min, max);
}

static void pyrBB(void *a, double *min, double *max)
{
  double *X = (double *)a, *Y = &X[5], *Z = &X[10];
  minmax(5, X, Y, Z, min, max);
}

static int pntInEle(void *a, double *x) { return 1; }

static int linInEle(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[2], *Z = &X[4], uvw[3];
  line lin(X, Y, Z);
  lin.xyz2uvw(x, uvw);
  return lin.isInside(uvw[0], uvw[1], uvw[2]);
}

static int triInEle(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[3], *Z = &X[6], uvw[3];
  triangle tri(X, Y, Z);
  tri.xyz2uvw(x, uvw);
  return tri.isInside(uvw[0], uvw[1], uvw[2]);
}

static int quaInEle(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[4], *Z = &X[8], uvw[3];
  quadrangle qua(X, Y, Z);
  qua.xyz2uvw(x, uvw);
  return qua.isInside(uvw[0], uvw[1], uvw[2]);
}

static int tetInEle(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[4], *Z = &X[8], uvw[3];
  tetrahedron tet(X, Y, Z);
  tet.xyz2uvw(x, uvw);
  return tet.isInside(uvw[0], uvw[1], uvw[2]);
}

static int hexInEle(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[8], *Z = &X[16], uvw[3];
  hexahedron hex(X, Y, Z);
  hex.xyz2uvw(x, uvw);
  return hex.isInside(uvw[0], uvw[1], uvw[2]);
}

static int priInEle(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[6], *Z = &X[12], uvw[3];
  prism pri(X, Y, Z);
  pri.xyz2uvw(x, uvw);
  return pri.isInside(uvw[0], uvw[1], uvw[2]);
}

static int pyrInEle(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[5], *Z = &X[10], uvw[3];
  pyramid pyr(X, Y, Z);
  pyr.xyz2uvw(x, uvw);
  return pyr.isInside(uvw[0], uvw[1], uvw[2]);
}

static void pntCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[1], *Z = &X[2];
  centroid(1, X, Y, Z, x);
}

static void linCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[2], *Z = &X[4];
  centroid(2, X, Y, Z, x);
}

static void triCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[3], *Z = &X[6];
  centroid(3, X, Y, Z, x);
}

static void quaCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

static void tetCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

static void hexCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[8], *Z = &X[16];
  centroid(8, X, Y, Z, x);
}

static void priCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[6], *Z = &X[12];
  centroid(6, X, Y, Z, x);
}

static void pyrCentroid(void *a, double *x)
{
  double *X = (double *)a, *Y = &X[5], *Z = &X[10];
  centroid(5, X, Y, Z, x);
}

static void addListOfStuff(Octree *o, std::vector<double> &l, int nbelm)
{
  for(std::size_t i = 0; i < l.size(); i += nbelm) Octree_Insert(&l[i], o);
}

// OctreePost implementation

OctreePost::~OctreePost()
{
  Octree_Delete(_sp);
  Octree_Delete(_vp);
  Octree_Delete(_tp);
  Octree_Delete(_sl);
  Octree_Delete(_vl);
  Octree_Delete(_tl);
  Octree_Delete(_st);
  Octree_Delete(_vt);
  Octree_Delete(_tt);
  Octree_Delete(_sq);
  Octree_Delete(_vq);
  Octree_Delete(_tq);
  Octree_Delete(_ss);
  Octree_Delete(_vs);
  Octree_Delete(_ts);
  Octree_Delete(_sh);
  Octree_Delete(_vh);
  Octree_Delete(_th);
  Octree_Delete(_si);
  Octree_Delete(_vi);
  Octree_Delete(_ti);
  Octree_Delete(_sy);
  Octree_Delete(_vy);
  Octree_Delete(_ty);
}

OctreePost::OctreePost(PView *v)
{
  _create(v->getData(true)); // use adaptive data if available
}

OctreePost::OctreePost(PViewData *data) { _create(data); }

void OctreePost::_create(PViewData *data)
{
  _sp = _vp = _tp = _sl = _vl = _tl = _st = _vt = _tt = nullptr;
  _sq = _vq = _tq = _ss = _vs = _ts = _sh = _vh = _th = nullptr;
  _si = _vi = _ti = _sy = _vy = _ty = nullptr;
  _theViewDataList = nullptr;
  _theViewDataGModel = nullptr;

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

    SBoundingBox3d bb = l->getBoundingBox();
    bb.thicken(0.01); // make 1% thicker
    SPoint3 bbmin = bb.min(), bbmax = bb.max();
    double min[3] = {bbmin.x(), bbmin.y(), bbmin.z()};
    double size[3] = {bbmax.x() - bbmin.x(), bbmax.y() - bbmin.y(),
                      bbmax.z() - bbmin.z()};
    const int maxElePerBucket = 100; // memory vs. speed trade-off

    _sp =
      Octree_Create(maxElePerBucket, min, size, pntBB, pntCentroid, pntInEle);
    addListOfStuff(_sp, l->SP, 3 + 1 * l->getNumTimeSteps());
    Octree_Arrange(_sp);
    _vp =
      Octree_Create(maxElePerBucket, min, size, pntBB, pntCentroid, pntInEle);
    addListOfStuff(_vp, l->VP, 3 + 3 * l->getNumTimeSteps());
    Octree_Arrange(_vp);
    _tp =
      Octree_Create(maxElePerBucket, min, size, pntBB, pntCentroid, pntInEle);
    addListOfStuff(_tp, l->TP, 3 + 9 * l->getNumTimeSteps());
    Octree_Arrange(_tp);

    _sl =
      Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
    addListOfStuff(_sl, l->SL, 6 + 2 * l->getNumTimeSteps());
    Octree_Arrange(_sl);
    _vl =
      Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
    addListOfStuff(_vl, l->VL, 6 + 6 * l->getNumTimeSteps());
    Octree_Arrange(_vl);
    _tl =
      Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
    addListOfStuff(_tl, l->TL, 6 + 18 * l->getNumTimeSteps());
    Octree_Arrange(_tl);

    _st =
      Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
    addListOfStuff(_st, l->ST, 9 + 3 * l->getNumTimeSteps());
    Octree_Arrange(_st);
    _vt =
      Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
    addListOfStuff(_vt, l->VT, 9 + 9 * l->getNumTimeSteps());
    Octree_Arrange(_vt);
    _tt =
      Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
    addListOfStuff(_tt, l->TT, 9 + 27 * l->getNumTimeSteps());
    Octree_Arrange(_tt);

    _sq =
      Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
    addListOfStuff(_sq, l->SQ, 12 + 4 * l->getNumTimeSteps());
    Octree_Arrange(_sq);
    _vq =
      Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
    addListOfStuff(_vq, l->VQ, 12 + 12 * l->getNumTimeSteps());
    Octree_Arrange(_vq);
    _tq =
      Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
    addListOfStuff(_tq, l->TQ, 12 + 36 * l->getNumTimeSteps());
    Octree_Arrange(_tq);

    _ss =
      Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
    addListOfStuff(_ss, l->SS, 12 + 4 * l->getNumTimeSteps());
    Octree_Arrange(_ss);
    _vs =
      Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
    addListOfStuff(_vs, l->VS, 12 + 12 * l->getNumTimeSteps());
    Octree_Arrange(_vs);
    _ts =
      Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
    addListOfStuff(_ts, l->TS, 12 + 36 * l->getNumTimeSteps());
    Octree_Arrange(_ts);

    _sh =
      Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
    addListOfStuff(_sh, l->SH, 24 + 8 * l->getNumTimeSteps());
    Octree_Arrange(_sh);
    _vh =
      Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
    addListOfStuff(_vh, l->VH, 24 + 24 * l->getNumTimeSteps());
    Octree_Arrange(_vh);
    _th =
      Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
    addListOfStuff(_th, l->TH, 24 + 72 * l->getNumTimeSteps());
    Octree_Arrange(_th);

    _si =
      Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
    addListOfStuff(_si, l->SI, 18 + 6 * l->getNumTimeSteps());
    Octree_Arrange(_si);
    _vi =
      Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
    addListOfStuff(_vi, l->VI, 18 + 18 * l->getNumTimeSteps());
    Octree_Arrange(_vi);
    _ti =
      Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
    addListOfStuff(_ti, l->TI, 18 + 54 * l->getNumTimeSteps());
    Octree_Arrange(_ti);

    _sy =
      Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
    addListOfStuff(_sy, l->SY, 15 + 5 * l->getNumTimeSteps());
    Octree_Arrange(_sy);
    _vy =
      Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
    addListOfStuff(_vy, l->VY, 15 + 15 * l->getNumTimeSteps());
    Octree_Arrange(_vy);
    _ty =
      Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
    addListOfStuff(_ty, l->TY, 15 + 45 * l->getNumTimeSteps());
    Octree_Arrange(_ty);
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

bool OctreePost::searchScalar(double x, double y, double z, double *values,
                              int step, double *size, int qn, double *qx,
                              double *qy, double *qz, bool grad, int dim)
{
  double P[3] = {x, y, z};
  int mult = grad ? 3 : 1;

  if(step < 0) {
    int numSteps = 1;
    if(_theViewDataList)
      numSteps = _theViewDataList->getNumTimeSteps();
    else if(_theViewDataGModel)
      numSteps = _theViewDataGModel->getNumTimeSteps();
    for(int i = 0; i < numSteps * mult; i++) { values[i] = 0.; }
  }
  else {
    for(int i = 0; i < mult; i++) values[i] = 0.;
  }

  if(_theViewDataList) {
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _ss, 4, qn, qx, qy, qz),
                                          3, 4, 1, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _sh, 8, qn, qx, qy, qz),
                                          3, 8, 1, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _si, 6, qn, qx, qy, qz),
                                          3, 6, 1, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _sy, 5, qn, qx, qy, qz),
                                          3, 5, 1, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 2) && _getValue(getElement(P, _st, 3, qn, qx, qy, qz),
                                          2, 3, 1, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 2) && _getValue(getElement(P, _sq, 4, qn, qx, qy, qz),
                                          2, 4, 1, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 1) && _getValue(getElement(P, _sl, 2, qn, qx, qy, qz),
                                          1, 2, 1, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 0) && _getValue(getElement(P, _sp, 1, qn, qx, qy, qz),
                                          0, 1, 1, P, step, values, size, grad))
      return true;
  }
  else if(_theViewDataGModel) {
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m) {
      MElement *e = getElement(P, m, qn, qx, qy, qz, dim);
      if(_getValue(e, 1, P, step, values, size, grad)) { return true; }
    }
  }

  return false;
}

bool OctreePost::searchScalarWithTol(double x, double y, double z,
                                     double *values, int step, double *size,
                                     double tol, int qn, double *qx, double *qy,
                                     double *qz, bool grad, int dim)
{
  bool a = searchScalar(x, y, z, values, step, size, qn, qx, qy, qz, grad, dim);
  if(!a && tol != 0.) {
    double oldtol1 = element::getTolerance();
    double oldtol2 = MElement::getTolerance();
    element::setTolerance(tol);
    MElement::setTolerance(tol);
    a = searchScalar(x, y, z, values, step, size, qn, qx, qy, qz, grad, dim);
    element::setTolerance(oldtol1);
    MElement::setTolerance(oldtol2);
  }
  return a;
}

bool OctreePost::searchVector(double x, double y, double z, double *values,
                              int step, double *size, int qn, double *qx,
                              double *qy, double *qz, bool grad, int dim)
{
  double P[3] = {x, y, z};
  int mult = grad ? 3 : 1;

  if(step < 0) {
    int numSteps = 1;
    if(_theViewDataList)
      numSteps = _theViewDataList->getNumTimeSteps();
    else if(_theViewDataGModel)
      numSteps = _theViewDataGModel->getNumTimeSteps();
    for(int i = 0; i < 3 * numSteps * mult; i++) values[i] = 0.;
  }
  else {
    for(int i = 0; i < 3 * mult; i++) values[i] = 0.;
  }

  if(_theViewDataList) {
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _vs, 4, qn, qx, qy, qz),
                                          3, 4, 3, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _vh, 8, qn, qx, qy, qz),
                                          3, 8, 3, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _vi, 6, qn, qx, qy, qz),
                                          3, 6, 3, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _vy, 5, qn, qx, qy, qz),
                                          3, 5, 3, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 2) && _getValue(getElement(P, _vt, 3, qn, qx, qy, qz),
                                          2, 3, 3, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 2) && _getValue(getElement(P, _vq, 4, qn, qx, qy, qz),
                                          2, 4, 3, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 1) && _getValue(getElement(P, _vl, 2, qn, qx, qy, qz),
                                          1, 2, 3, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 0) && _getValue(getElement(P, _vp, 1, qn, qx, qy, qz),
                                          0, 1, 3, P, step, values, size, grad))
      return true;
  }
  else if(_theViewDataGModel) {
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m) {
      MElement *e = getElement(P, m, qn, qx, qy, qz, dim);
      if(_getValue(e, 3, P, step, values, size, grad)) { return true; }
    }
  }

  return false;
}

bool OctreePost::searchVectorWithTol(double x, double y, double z,
                                     double *values, int step, double *size,
                                     double tol, int qn, double *qx, double *qy,
                                     double *qz, bool grad, int dim)
{
  bool a = searchVector(x, y, z, values, step, size, qn, qx, qy, qz, grad, dim);
  if(!a && tol != 0.) {
    double oldtol1 = element::getTolerance();
    double oldtol2 = MElement::getTolerance();
    element::setTolerance(tol);
    MElement::setTolerance(tol);
    a = searchVector(x, y, z, values, step, size, qn, qx, qy, qz, grad, dim);
    element::setTolerance(oldtol1);
    MElement::setTolerance(oldtol2);
  }
  return a;
}

bool OctreePost::searchTensor(double x, double y, double z, double *values,
                              int step, double *size, int qn, double *qx,
                              double *qy, double *qz, bool grad, int dim)
{
  double P[3] = {x, y, z};
  int mult = grad ? 3 : 1;

  if(step < 0) {
    int numSteps = 1;
    if(_theViewDataList)
      numSteps = _theViewDataList->getNumTimeSteps();
    else if(_theViewDataGModel)
      numSteps = _theViewDataGModel->getNumTimeSteps();
    for(int i = 0; i < 9 * numSteps * mult; i++) values[i] = 0.;
  }
  else {
    for(int i = 0; i < 9 * mult; i++) values[i] = 0.;
  }

  if(_theViewDataList) {
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _ts, 4, qn, qx, qy, qz),
                                          3, 4, 9, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _th, 8, qn, qx, qy, qz),
                                          3, 8, 9, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _ti, 6, qn, qx, qy, qz),
                                          3, 6, 9, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 3) && _getValue(getElement(P, _ty, 5, qn, qx, qy, qz),
                                          3, 5, 9, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 2) && _getValue(getElement(P, _tt, 3, qn, qx, qy, qz),
                                          2, 3, 9, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 2) && _getValue(getElement(P, _tq, 4, qn, qx, qy, qz),
                                          2, 4, 9, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 1) && _getValue(getElement(P, _tl, 2, qn, qx, qy, qz),
                                          1, 2, 9, P, step, values, size, grad))
      return true;
    if((dim < 0 || dim == 0) && _getValue(getElement(P, _tp, 1, qn, qx, qy, qz),
                                          0, 1, 9, P, step, values, size, grad))
      return true;
  }
  else if(_theViewDataGModel) {
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m) {
      MElement *e = getElement(P, m, qn, qx, qy, qz, dim);
      if(_getValue(e, 9, P, step, values, size, grad)) { return true; }
    }
  }

  return false;
}

bool OctreePost::searchTensorWithTol(double x, double y, double z,
                                     double *values, int step, double *size,
                                     double tol, int qn, double *qx, double *qy,
                                     double *qz, bool grad, int dim)
{
  bool a = searchTensor(x, y, z, values, step, size, qn, qx, qy, qz, grad, dim);
  if(!a && tol != 0.) {
    double oldtol1 = element::getTolerance();
    double oldtol2 = MElement::getTolerance();
    element::setTolerance(tol);
    MElement::setTolerance(tol);
    a = searchTensor(x, y, z, values, step, size, qn, qx, qy, qz, grad, dim);
    element::setTolerance(oldtol1);
    MElement::setTolerance(oldtol2);
  }
  return a;
}
