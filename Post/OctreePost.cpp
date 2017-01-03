// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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

// helper routines for list-based views

static void minmax(int n, double *X, double *Y, double *Z,
                   double *min, double *max)
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

  // make bounding boxes larger up to (absolute) geometrical tolerance
  double eps = CTX::instance()->geom.tolerance;
  for(int i = 0; i < 3; i++){
    min[i] -= eps;
    max[i] += eps;
  }
}

static void centroid(int n, double *X, double *Y, double *Z, double *c)
{
  const double oc = 1./(double)n;
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
  double *X = (double*) a, *Y = &X[1], *Z = &X[2];
  minmax(1, X, Y, Z, min, max);
}

static void linBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4];
  minmax(2, X, Y, Z, min, max);
}

static void triBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6];
  minmax(3, X, Y, Z, min, max);
}

static void quaBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

static void tetBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

static void hexBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16];
  minmax(8, X, Y, Z, min, max);
}

static void priBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12];
  minmax(6, X, Y, Z, min, max);
}

static void pyrBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10];
  minmax(5, X, Y, Z, min, max);
}

static int pntInEle(void *a, double *x)
{
  return 1;
}

static int linInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4], uvw[3];
  line lin(X, Y, Z);
  lin.xyz2uvw(x, uvw);
  return lin.isInside(uvw[0], uvw[1], uvw[2]);
}

static int triInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6], uvw[3];
  triangle tri(X, Y, Z);
  tri.xyz2uvw(x, uvw);
  return tri.isInside(uvw[0], uvw[1], uvw[2]);
}

static int quaInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8], uvw[3];
  quadrangle qua(X, Y, Z);
  qua.xyz2uvw(x, uvw);
  return qua.isInside(uvw[0], uvw[1], uvw[2]);
}

static int tetInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8], uvw[3];
  tetrahedron tet(X, Y, Z);
  tet.xyz2uvw(x, uvw);
  return tet.isInside(uvw[0], uvw[1], uvw[2]);
}

static int hexInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16], uvw[3];
  hexahedron hex(X, Y, Z);
  hex.xyz2uvw(x, uvw);
  return hex.isInside(uvw[0], uvw[1], uvw[2]);
}

static int priInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12], uvw[3];
  prism pri(X, Y, Z);
  pri.xyz2uvw(x, uvw);
  return pri.isInside(uvw[0], uvw[1], uvw[2]);
}

static int pyrInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10], uvw[3];
  pyramid pyr(X, Y, Z);
  pyr.xyz2uvw(x, uvw);
  return pyr.isInside(uvw[0], uvw[1], uvw[2]);
}

static void pntCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[1], *Z = &X[2];
  centroid(1, X, Y, Z, x);
}

static void linCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4];
  centroid(2, X, Y, Z, x);
}

static void triCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6];
  centroid(3, X, Y, Z, x);
}

static void quaCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

static void tetCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

static void hexCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16];
  centroid(8, X, Y, Z, x);
}

static void priCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12];
  centroid(6, X, Y, Z, x);
}

static void pyrCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10];
  centroid(5, X, Y, Z, x);
}

static void addListOfStuff(Octree *o, std::vector<double> &l, int nbelm)
{
  for(unsigned int i = 0; i < l.size(); i += nbelm)
    Octree_Insert(&l[i], o);
}

// OctreePost implementation

OctreePost::~OctreePost()
{
  Octree_Delete(_SPP); Octree_Delete(_VPP); Octree_Delete(_TPP);
  Octree_Delete(_SL); Octree_Delete(_VL); Octree_Delete(_TL);
  Octree_Delete(_ST); Octree_Delete(_VT); Octree_Delete(_TT);
  Octree_Delete(_SQ); Octree_Delete(_VQ); Octree_Delete(_TQ);
  Octree_Delete(_SS); Octree_Delete(_VS); Octree_Delete(_TS);
  Octree_Delete(_SH); Octree_Delete(_VH); Octree_Delete(_TH);
  Octree_Delete(_SI); Octree_Delete(_VI); Octree_Delete(_TI);
  Octree_Delete(_SY); Octree_Delete(_VY); Octree_Delete(_TY);
}

OctreePost::OctreePost(PView *v)
{
  _create(v->getData(true)); // use adaptive data if available
}

OctreePost::OctreePost(PViewData *data)
{
  _create(data);
}

void OctreePost::_create(PViewData *data)
{
  _SPP = _VPP = _TPP = _SL = _VL = _TL = _ST = _VT = _TT = 0;
  _SQ = _VQ = _TQ = _SS = _VS = _TS = _SH = _VH = _TH = 0;
  _SI = _VI = _TI = _SY = _VY = _TY = 0;
  _theViewDataList = 0;
  _theViewDataGModel = 0;

  _theViewDataGModel = dynamic_cast<PViewDataGModel*>(data);

  if(_theViewDataGModel) return; // the octree is already available in the model

  _theViewDataList = dynamic_cast<PViewDataList*>(data);

  if(_theViewDataList){
    PViewDataList *l = _theViewDataList;

    if(l->haveInterpolationMatrices() && !l->isAdapted()){
      Msg::Error("Cannot create octree for non-adapted high-order list-based view: you need");
      Msg::Error("to select 'Adapt visualization grid' first");
      return;
    }

    SBoundingBox3d bb = l->getBoundingBox();
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

    _SPP = Octree_Create(maxElePerBucket, min, size, pntBB, pntCentroid, pntInEle);
    addListOfStuff(_SPP, l->SP, 3 + 1 * l->getNumTimeSteps());
    Octree_Arrange(_SPP);
    _VPP = Octree_Create(maxElePerBucket, min, size, pntBB, pntCentroid, pntInEle);
    addListOfStuff(_VPP, l->VP, 3 + 3 * l->getNumTimeSteps());
    Octree_Arrange(_VPP);
    _TPP = Octree_Create(maxElePerBucket, min, size, pntBB, pntCentroid, pntInEle);
    addListOfStuff(_TPP, l->TP, 3 + 9 * l->getNumTimeSteps());
    Octree_Arrange(_TPP);

    _SL = Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
    addListOfStuff(_SL, l->SL, 6 + 2 * l->getNumTimeSteps());
    Octree_Arrange(_SL);
    _VL = Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
    addListOfStuff(_VL, l->VL, 6 + 6 * l->getNumTimeSteps());
    Octree_Arrange(_VL);
    _TL = Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
    addListOfStuff(_TL, l->TL, 6 + 18 * l->getNumTimeSteps());
    Octree_Arrange(_TL);

    _ST = Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
    addListOfStuff(_ST, l->ST, 9 + 3 * l->getNumTimeSteps());
    Octree_Arrange(_ST);
    _VT = Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
    addListOfStuff(_VT, l->VT, 9 + 9 * l->getNumTimeSteps());
    Octree_Arrange(_VT);
    _TT = Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
    addListOfStuff(_TT, l->TT, 9 + 27 * l->getNumTimeSteps());
    Octree_Arrange(_TT);

    _SQ = Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
    addListOfStuff(_SQ, l->SQ, 12 + 4 * l->getNumTimeSteps());
    Octree_Arrange(_SQ);
    _VQ = Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
    addListOfStuff(_VQ, l->VQ, 12 + 12 * l->getNumTimeSteps());
    Octree_Arrange(_VQ);
    _TQ = Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
    addListOfStuff(_TQ, l->TQ, 12 + 36 * l->getNumTimeSteps());
    Octree_Arrange(_TQ);

    _SS = Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
    addListOfStuff(_SS, l->SS, 12 + 4 * l->getNumTimeSteps());
    Octree_Arrange(_SS);
    _VS = Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
    addListOfStuff(_VS, l->VS, 12 + 12 * l->getNumTimeSteps());
    Octree_Arrange(_VS);
    _TS = Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
    addListOfStuff(_TS, l->TS, 12 + 36 * l->getNumTimeSteps());
    Octree_Arrange(_TS);

    _SH = Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
    addListOfStuff(_SH, l->SH, 24 + 8 * l->getNumTimeSteps());
    Octree_Arrange(_SH);
    _VH = Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
    addListOfStuff(_VH, l->VH, 24 + 24 * l->getNumTimeSteps());
    Octree_Arrange(_VH);
    _TH = Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
    addListOfStuff(_TH, l->TH, 24 + 72 * l->getNumTimeSteps());
    Octree_Arrange(_TH);

    _SI = Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
    addListOfStuff(_SI, l->SI, 18 + 6 * l->getNumTimeSteps());
    Octree_Arrange(_SI);
    _VI = Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
    addListOfStuff(_VI, l->VI, 18 + 18 * l->getNumTimeSteps());
    Octree_Arrange(_VI);
    _TI = Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
    addListOfStuff(_TI, l->TI, 18 + 54 * l->getNumTimeSteps());
    Octree_Arrange(_TI);

    _SY = Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
    addListOfStuff(_SY, l->SY, 15 + 5 * l->getNumTimeSteps());
    Octree_Arrange(_SY);
    _VY = Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
    addListOfStuff(_VY, l->VY, 15 + 15 * l->getNumTimeSteps());
    Octree_Arrange(_VY);
    _TY = Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
    addListOfStuff(_TY, l->TY, 15 + 45 * l->getNumTimeSteps());
    Octree_Arrange(_TY);
  }
}

static void *getElement(double P[3], Octree *octree, int nbNod,
                        int qn, double *qx, double *qy, double *qz)
{
  if(qn && qx && qy && qz){
    std::vector<void*> v;
    Octree_SearchAll(P, octree, &v);
    if(nbNod == qn){
      // try to use the value from the same geometrical element as the one
      // provided in qx/y/z
      double eps = CTX::instance()->geom.tolerance;
      for(unsigned int i = 0; i < v.size(); i++){
        double *X = (double*)v[i], *Y = &X[qn], *Z = &X[2 * qn];
        bool ok = true;
        for(int j = 0; j < qn; j++){
          ok &= (fabs(X[j] - qx[j]) < eps &&
                 fabs(Y[j] - qy[j]) < eps &&
                 fabs(Z[j] - qz[j]) < eps);
        }
        if(ok) return v[i];
      }
    }
    if(v.size()) return v[0];
  }
  else{
    return Octree_Search(P, octree);
  }
  return 0;
}

static MElement *getElement(double P[3], GModel *m,
                            int qn, double *qx, double *qy, double *qz)
{
  SPoint3 pt(P);
  if(qn && qx && qy && qz){
    // try to use the value from the same geometrical element as the one
    // provided in qx/y/z
    double eps = CTX::instance()->geom.tolerance;
    std::vector<MElement*> elements = m->getMeshElementsByCoord(pt);
    for(unsigned int i = 0; i < elements.size(); i++){
      if(qn == elements[i]->getNumVertices()){
        bool ok = true;
        for(int j = 0; j < qn; j++){
          MVertex *v = elements[i]->getVertex(j);
          ok &= (fabs(v->x() - qx[j]) < eps &&
                 fabs(v->y() - qy[j]) < eps &&
                 fabs(v->z() - qz[j]) < eps);
        }
        if(ok) return elements[i];
      }
    }
    if(elements.size()) return elements[0];
  }
  else{
    return m->getMeshElementByCoord(pt);
  }
  return 0;
}

bool OctreePost::_getValue(void *in, int dim, int nbNod, int nbComp,
                           double P[3], int step, double *values,
                           double *elementSize, bool grad)
{
  if(!in) return false;

  double *X = (double*)in, *Y = &X[nbNod], *Z = &X[2*nbNod], *V = &X[3*nbNod], U[3];

  elementFactory factory;
  element *e = factory.create(nbNod, dim, X, Y, Z);
  if(!e) return false;

  e->xyz2uvw(P, U);
  if(step < 0){
    for(int i = 0; i < _theViewDataList->getNumTimeSteps(); i++){
      for(int j = 0; j < nbComp; j++){
        if(!grad){
          values[nbComp * i + j] = e->interpolate(&V[nbNod * nbComp * i + j],
                                                  U[0], U[1], U[2], nbComp);
        }
        else{
          e->interpolateGrad(&V[nbNod * nbComp * i + j], U[0], U[1], U[2],
                             &values[3 * (nbComp * i + j)], nbComp);
        }
      }
    }
  }
  else{
    for(int j = 0; j < nbComp; j++){
      if(!grad)
        values[j] = e->interpolate(&V[nbNod * nbComp * step + j],
                                   U[0], U[1], U[2], nbComp);
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

  MElement *e = (MElement*)in;

  std::vector<int> dataIndex(e->getNumVertices());
  if(_theViewDataGModel->getType() == PViewDataGModel::NodeData)
    for(int i = 0; i < e->getNumVertices(); i++)
      dataIndex[i] = e->getVertex(i)->getNum();
  else
    for(int i = 0; i < e->getNumVertices(); i++)
      dataIndex[i] = e->getNum();

  double U[3];
  e->xyz2uvw(P, U);

  std::vector<double> nodeval(e->getNumVertices() * 9);
  for(int step = 0; step < _theViewDataGModel->getNumTimeSteps(); step++){
    if(!_theViewDataGModel->hasTimeStep(step)) continue;
    if(timestep < 0 || step == timestep){
      for(int nod = 0; nod < e->getNumVertices(); nod++){
        for(int comp = 0; comp < nbComp; comp++)
          _theViewDataGModel->getValueByIndex(step, dataIndex[nod], nod, comp,
                                              nodeval[nod * nbComp + comp]);
      }
      for(int comp = 0; comp < nbComp; comp++){
        if(!grad){
          double val = e->interpolate(&nodeval[comp], U[0], U[1], U[2], nbComp);
          if(timestep < 0)
            values[nbComp * step + comp] = val;
          else
            values[comp] = val;
        }
        else{
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
                              int step, double *size,
                              int qn, double *qx, double *qy, double *qz,
                              bool grad)
{
  double P[3] = {x, y, z};
  int mult = grad ? 3 : 1;

  if(step < 0){
    int numSteps = 1;
    if(_theViewDataList) numSteps = _theViewDataList->getNumTimeSteps();
    else if(_theViewDataGModel) numSteps = _theViewDataGModel->getNumTimeSteps();
    for(int i = 0; i < numSteps * mult; i++){
      values[i] = 0.;
    }
  }
  else{
    for(int i = 0; i < mult; i++)
      values[i] = 0.;
  }

  if(_theViewDataList){
    if(_getValue(getElement(P, _SS, 4, qn, qx, qy, qz),
                 3, 4, 1, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _SH, 8, qn, qx, qy, qz),
                 3, 8, 1, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _SI, 6, qn, qx, qy, qz),
                 3, 6, 1, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _SY, 5, qn, qx, qy, qz),
                 3, 5, 1, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _ST, 3, qn, qx, qy, qz),
                 2, 3, 1, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _SQ, 4, qn, qx, qy, qz),
                 2, 4, 1, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _SL, 2, qn, qx, qy, qz),
                 1, 2, 1, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _SPP, 1, qn, qx, qy, qz),
                 0, 1, 1, P, step, values, size, grad)) return true;
  }
  else if(_theViewDataGModel){
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m){
      if(_getValue(getElement(P, m, qn, qx, qy, qz),
                   1, P, step, values, size, grad)) return true;
    }
  }

  return false;
}

bool OctreePost::searchScalarWithTol(double x, double y, double z, double *values,
                                     int step, double *size, double tol,
                                     int qn, double *qx, double *qy, double *qz,
                                     bool grad)
{
  bool a = searchScalar(x, y, z, values, step, size, qn, qx, qy, qz, grad);
  if(!a && tol != 0.){
    double oldtol1 = element::getTolerance();
    double oldtol2 = MElement::getTolerance();
    element::setTolerance(tol);
    MElement::setTolerance(tol);
    a = searchScalar(x, y, z, values, step, size, qn, qx, qy, qz, grad);
    element::setTolerance(oldtol1);
    MElement::setTolerance(oldtol2);
  }
  return a;
}

bool OctreePost::searchVector(double x, double y, double z, double *values,
                              int step, double *size,
                              int qn, double *qx, double *qy, double *qz,
                              bool grad)
{
  double P[3] = {x, y, z};
  int mult = grad ? 3 : 1;

  if(step < 0){
    int numSteps = 1;
    if(_theViewDataList) numSteps = _theViewDataList->getNumTimeSteps();
    else if(_theViewDataGModel) numSteps = _theViewDataGModel->getNumTimeSteps();
    for(int i = 0; i < 3 * numSteps * mult; i++)
      values[i] = 0.;
  }
  else{
    for(int i = 0; i < 3 * mult; i++)
      values[i] = 0.;
  }

  if(_theViewDataList){
    if(_getValue(getElement(P, _VS, 4, qn, qx, qy, qz),
                 3, 4, 3, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _VH, 8, qn, qx, qy, qz),
                 3, 8, 3, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _VI, 6, qn, qx, qy, qz),
                 3, 6, 3, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _VY, 5, qn, qx, qy, qz),
                 3, 5, 3, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _VT, 3, qn, qx, qy, qz),
                 2, 3, 3, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _VQ, 4, qn, qx, qy, qz),
                 2, 4, 3, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _VL, 2, qn, qx, qy, qz),
                 1, 2, 3, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _VPP, 1, qn, qx, qy, qz),
                 0, 1, 3, P, step, values, size, grad)) return true;
  }
  else if(_theViewDataGModel){
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m){
      if(_getValue(getElement(P, m, qn, qx, qy, qz),
                   3, P, step, values, size, grad)) return true;
    }
  }

  return false;
}

bool OctreePost::searchVectorWithTol(double x, double y, double z, double *values,
                                     int step, double *size, double tol,
                                     int qn, double *qx, double *qy, double *qz,
                                     bool grad)
{
  bool a = searchVector(x, y, z, values, step, size, qn, qx, qy, qz, grad);
  if(!a && tol != 0.){
    double oldtol1 = element::getTolerance();
    double oldtol2 = MElement::getTolerance();
    element::setTolerance(tol);
    MElement::setTolerance(tol);
    a = searchVector(x, y, z, values, step, size, qn, qx, qy, qz, grad);
    element::setTolerance(oldtol1);
    MElement::setTolerance(oldtol2);
  }
  return a;
}

bool OctreePost::searchTensor(double x, double y, double z, double *values,
                              int step, double *size,
                              int qn, double *qx, double *qy, double *qz,
                              bool grad)
{
  double P[3] = {x, y, z};
  int mult = grad ? 3 : 1;

  if(step < 0){
    int numSteps = 1;
    if(_theViewDataList) numSteps = _theViewDataList->getNumTimeSteps();
    else if(_theViewDataGModel) numSteps = _theViewDataGModel->getNumTimeSteps();
    for(int i = 0; i < 9 * numSteps * mult; i++)
      values[i] = 0.;
  }
  else{
    for(int i = 0; i < 9 * mult; i++)
      values[i] = 0.;
  }

  if(_theViewDataList){
    if(_getValue(getElement(P, _TS, 4, qn, qx, qy, qz),
                 3, 4, 9, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _TH, 8, qn, qx, qy, qz),
                 3, 8, 9, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _TI, 6, qn, qx, qy, qz),
                 3, 6, 9, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _TY, 5, qn, qx, qy, qz),
                 3, 5, 9, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _TT, 3, qn, qx, qy, qz),
                 2, 3, 9, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _TQ, 4, qn, qx, qy, qz),
                 2, 4, 9, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _TL, 2, qn, qx, qy, qz),
                 1, 2, 9, P, step, values, size, grad)) return true;
    if(_getValue(getElement(P, _TPP, 1, qn, qx, qy, qz),
                 0, 1, 9, P, step, values, size, grad)) return true;
  }
  else if(_theViewDataGModel){
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m){
      if(_getValue(getElement(P, m, qn, qx, qy, qz),
                   9, P, step, values, size, grad)) return true;
    }
  }

  return false;
}

bool OctreePost::searchTensorWithTol(double x, double y, double z, double *values,
                                     int step, double *size, double tol,
                                     int qn, double *qx, double *qy, double *qz,
                                     bool grad)
{
  bool a = searchTensor(x, y, z, values, step, size, qn, qx, qy, qz, grad);
  if(!a && tol != 0.){
    double oldtol1 = element::getTolerance();
    double oldtol2 = MElement::getTolerance();
    element::setTolerance(tol);
    MElement::setTolerance(tol);
    a = searchTensor(x, y, z, values, step, size, qn, qx, qy, qz, grad);
    element::setTolerance(oldtol1);
    MElement::setTolerance(oldtol2);
  }
  return a;
}
