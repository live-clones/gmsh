// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Octree.h"
#include "OctreePost.h"
#include "PView.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "shapeFunctions.h"
#include "GModel.h"
#include "MElement.h"

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

void linBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4];
  minmax(2, X, Y, Z, min, max);
}

void triBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6];
  minmax(3, X, Y, Z, min, max);
}

void quaBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

void tetBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

void hexBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16];
  minmax(8, X, Y, Z, min, max);
}

void priBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12];
  minmax(6, X, Y, Z, min, max);
}

void pyrBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10];
  minmax(5, X, Y, Z, min, max);
}

int linInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4], uvw[3];
  line lin(X, Y, Z);
  lin.xyz2uvw(x, uvw);
  return lin.isInside(uvw[0], uvw[1], uvw[2]);
}

int triInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6], uvw[3];
  triangle tri(X, Y, Z);
  tri.xyz2uvw(x, uvw);
  return tri.isInside(uvw[0], uvw[1], uvw[2]);
}

int quaInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8], uvw[3];
  quadrangle qua(X, Y, Z);
  qua.xyz2uvw(x, uvw);
  return qua.isInside(uvw[0], uvw[1], uvw[2]);
}

int tetInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8], uvw[3];
  tetrahedron tet(X, Y, Z);
  tet.xyz2uvw(x, uvw);
  return tet.isInside(uvw[0], uvw[1], uvw[2]);
}

int hexInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16], uvw[3];
  hexahedron hex(X, Y, Z);
  hex.xyz2uvw(x, uvw);
  return hex.isInside(uvw[0], uvw[1], uvw[2]);
}

int priInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12], uvw[3];
  prism pri(X, Y, Z);
  pri.xyz2uvw(x, uvw);
  return pri.isInside(uvw[0], uvw[1], uvw[2]);
}

int pyrInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10], uvw[3];
  pyramid pyr(X, Y, Z);
  pyr.xyz2uvw(x, uvw);
  return pyr.isInside(uvw[0], uvw[1], uvw[2]);
}

void linCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4];
  centroid(2, X, Y, Z, x);
}

void triCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6];
  centroid(3, X, Y, Z, x);
}

void quaCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

void tetCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

void hexCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16];
  centroid(8, X, Y, Z, x);
}

void priCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12];
  centroid(6, X, Y, Z, x);
}

void pyrCentroid(void *a, double *x)
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
  Octree_Delete(_SL); Octree_Delete(_VL); Octree_Delete(_TL);
  Octree_Delete(_ST); Octree_Delete(_VT); Octree_Delete(_TT);
  Octree_Delete(_SQ); Octree_Delete(_VQ); Octree_Delete(_TQ);
  Octree_Delete(_SS); Octree_Delete(_VS); Octree_Delete(_TS);
  Octree_Delete(_SH); Octree_Delete(_VH); Octree_Delete(_TH);
  Octree_Delete(_SI); Octree_Delete(_VI); Octree_Delete(_TI);
  Octree_Delete(_SY); Octree_Delete(_VY); Octree_Delete(_TY);
}

OctreePost::OctreePost(PView *v) 
  : _SL(0), _VL(0), _TL(0), _ST(0), _VT(0), _TT(0), _SQ(0), _VQ(0), _TQ(0), 
    _SS(0), _VS(0), _TS(0), _SH(0), _VH(0), _TH(0), _SI(0), _VI(0), _TI(0),
    _SY(0), _VY(0), _TY(0),
    _theView(v), _theViewDataList(0), _theViewDataGModel(0)
{
  _theViewDataGModel = dynamic_cast<PViewDataGModel*>(_theView->getData());

  if(_theViewDataGModel) return; // the octree is already available in the model

  // use adaptive data if available
  _theViewDataList = dynamic_cast<PViewDataList*>(_theView->getData(true));

  if(_theViewDataList){
    PViewDataList *l = _theViewDataList;

    if(l->haveInterpolationMatrices() && !_theView->getData()->isAdaptive()){
      Msg::Error("Cannot create octree for non-adapted high-order view: you need");
      Msg::Error("to select 'Adapt visualization grid' first");
      return;
    }

    SBoundingBox3d bb = l->getBoundingBox();
    double min[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
    double size[3] = {bb.max().x() - bb.min().x(),
                      bb.max().y() - bb.min().y(),
                      bb.max().z() - bb.min().z()};                   
    const int maxElePerBucket = 100; // memory vs. speed trade-off
    
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

bool OctreePost::_getValue(void *in, int dim, int nbNod, int nbComp, 
                           double P[3], int step, double *values,
                           double *elementSize)
{
  if(!in) return false;

  double *X = (double*)in, *Y = &X[nbNod], *Z = &X[2*nbNod], *V = &X[3*nbNod], U[3];

  elementFactory factory;
  element *e = factory.create(nbNod, dim, X, Y, Z);
  if(!e) return false;

  e->xyz2uvw(P, U);
  if(step < 0){
    for(int i = 0; i < _theViewDataList->getNumTimeSteps(); i++)
      for(int j = 0; j < nbComp; j++)
        values[nbComp * i + j] = e->interpolate(&V[nbNod * nbComp * i + j], 
                                                U[0], U[1], U[2], nbComp);
  }
  else{
    for(int j = 0; j < nbComp; j++)
      values[j] = e->interpolate(&V[nbNod * nbComp * step + j], 
                                 U[0], U[1], U[2], nbComp);
  }

  if(elementSize) *elementSize = e->maxEdgeLength();

  delete e;
  return true;
} 

bool OctreePost::_getValue(void *in, int nbComp, double P[3], int timestep,
                           double *values, double *elementSize)
{
  if(!in) return false;

  if(_theViewDataGModel->getNumComponents(0, 0, 0) != nbComp) return false;

  MElement *e = (MElement*)in;

  int dataIndex[8];
  if(_theViewDataGModel->getType() == PViewDataGModel::NodeData)
    for(int i = 0; i < e->getNumVertices(); i++)
      dataIndex[i] = e->getVertex(i)->getNum();
  else
    for(int i = 0; i < e->getNumVertices(); i++)
      dataIndex[i] = e->getNum();
    
  double U[3];
  e->xyz2uvw(P, U);

  double nodeval[8 * 9];
  for(int step = 0; step < _theViewDataGModel->getNumTimeSteps(); step++){
    if(timestep < 0 || step == timestep){
      for(int nod = 0; nod < e->getNumVertices(); nod++){
        for(int comp = 0; comp < nbComp; comp++){
          if(!_theViewDataGModel->getValueByIndex(step, dataIndex[nod], nod, comp, 
                                                  nodeval[nod * nbComp + comp]))
            return false;
        }
      }
      for(int comp = 0; comp < nbComp; comp++){
        double val = e->interpolate(&nodeval[comp], U[0], U[1], U[2], nbComp);
        if(timestep < 0)
          values[nbComp * step + comp] = val;
        else
          values[comp] = val;
      }
    }
  }
  
  if(elementSize) *elementSize = e->maxEdge();
  return true;
} 

bool OctreePost::searchScalar(double x, double y, double z, double *values, 
                              int step, double *size)
{
  double P[3] = {x, y, z};

  if(step < 0)
    for(int i = 0; i < _theView->getData()->getNumTimeSteps(); i++)
      values[i] = 0.0; 
  else
    values[0] = 0.0;

  if(_theViewDataList){
    if(_getValue(Octree_Search(P, _SS), 3, 4, 1, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _SH), 3, 8, 1, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _SI), 3, 6, 1, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _SY), 3, 5, 1, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _ST), 2, 3, 1, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _SQ), 2, 4, 1, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _SL), 1, 2, 1, P, step, values, size)) return true;
  }
  else if(_theViewDataGModel){
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m){
      SPoint3 pt(P);
      if(_getValue(m->getMeshElementByCoord(pt), 1, P, step, values, size)) return true;
    }
  }
  
  return false;
}

bool OctreePost::searchScalarWithTol(double x, double y, double z, double *values, 
                                     int step, double *size, double tol)
{
  bool a = searchScalar(x, y, z, values, step, size);
  if(!a && tol != 0.){
    double oldtol1 = element::getTolerance();
    double oldtol2 = MElement::getTolerance();
    element::setTolerance(tol);
    MElement::setTolerance(tol);
    a = searchScalar(x, y, z, values, step, size);
    element::setTolerance(oldtol1);
    MElement::setTolerance(oldtol2);
  }    
  return a;
}

bool OctreePost::searchVector(double x, double y, double z, double *values, 
                              int step, double *size)
{
  double P[3] = {x, y, z};

  if(step < 0)
    for(int i = 0; i < 3 * _theView->getData()->getNumTimeSteps(); i++)
      values[i] = 0.0; 
  else
    for(int i = 0; i < 3; i++)
      values[i] = 0.0;

  if(_theViewDataList){
    if(_getValue(Octree_Search(P, _VS), 3, 4, 3, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _VH), 3, 8, 3, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _VI), 3, 6, 3, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _VY), 3, 5, 3, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _VT), 2, 3, 3, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _VQ), 2, 4, 3, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _VL), 1, 2, 3, P, step, values, size)) return true;
  }
  else if(_theViewDataGModel){
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m){
      SPoint3 pt(P);
      if(_getValue(m->getMeshElementByCoord(pt), 3, P, step, values, size)) return true;
    }
  }
  
  return false;
}

bool OctreePost::searchTensor(double x, double y, double z, double *values, 
                              int step, double *size)
{
  double P[3] = {x, y, z};

  if(step < 0)
    for(int i = 0; i < 9 * _theView->getData()->getNumTimeSteps(); i++)
      values[i] = 0.0; 
  else
    for(int i = 0; i < 9; i++)
      values[i] = 0.0;

  if(_theViewDataList){
    if(_getValue(Octree_Search(P, _TS), 3, 4, 9, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _TH), 3, 8, 9, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _TI), 3, 6, 9, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _TY), 3, 5, 9, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _TT), 2, 3, 9, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _TQ), 2, 4, 9, P, step, values, size)) return true;
    if(_getValue(Octree_Search(P, _TL), 1, 2, 9, P, step, values, size)) return true;
  }
  else if(_theViewDataGModel){
    GModel *m = _theViewDataGModel->getModel((step < 0) ? 0 : step);
    if(m){
      SPoint3 pt(P);
      if(_getValue(m->getMeshElementByCoord(pt), 9, P, step, values, size)) return true;
    }
  }
  
  return false;
}
