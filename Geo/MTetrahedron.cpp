// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "MTetrahedron.h"
#include "Numeric.h"
#include "Context.h"

#if defined(HAVE_MESH)
#include "qualityMeasures.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGRegionDelaunayInsertion.h"
#endif

#define SQU(a)      ((a)*(a))

SPoint3 MTetrahedron::circumcenter()
{
#if defined(HAVE_MESH)
  MTet4 t(this, 0);
  double res[3];
  t.circumcenter(res);
  return SPoint3(res[0], res[1], res[2]);
#else
  return SPoint3(0., 0., 0.);
#endif
}

double MTetrahedron::getCircumRadius()
{
#if defined(HAVE_MESH)
  SPoint3 center = circumcenter();
  const double dx = getVertex(0)->x() - center.x();
  const double dy = getVertex(0)->y() - center.y();
  const double dz = getVertex(0)->z() - center.z();
  double circum_radius = sqrt(dx * dx + dy * dy + dz * dz);
  return circum_radius;
#else
  return 0.0;
#endif
}

double MTetrahedron::distoShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmDistorsionOfMapping(this);
#else
  return 0.;
#endif
}

double MTetrahedronN::distoShapeMeasure()
{
#if defined(HAVE_MESH)
  _disto = qmDistorsionOfMapping(this);
#else
  _disto = 0.;
#endif
  return _disto;
}

double MTetrahedron::getInnerRadius()
{
  // radius of inscribed sphere = 3 * Volume / sum(Area_i)
  double dist[3], face_area = 0.;
  double vol = getVolume();
  for(int i = 0; i < 4; i++){  
    MFace f = getFace(i);
    for (int j = 0; j < 3; j++){
      MEdge e = f.getEdge(j);
      dist[j] = e.getVertex(0)->distance(e.getVertex(1));
    }
    face_area += 0.25 * sqrt((dist[0] + dist[1] + dist[2]) * 
                             (-dist[0] + dist[1] + dist[2]) * 
                             (dist[0] - dist[1] + dist[2]) * 
                             (dist[0] + dist[1] - dist[2]));
  }
  return 3 * vol / face_area;
}

double MTetrahedron::gammaShapeMeasure()
{
#if defined(HAVE_MESH)
  double vol;
  return qmTet(this, QMTET_2, &vol);
#else
  return 0.;
#endif
}

double MTetrahedron::etaShapeMeasure()
{
#if defined(HAVE_MESH)
  double vol;
  return qmTet(this, QMTET_3, &vol);
#else
  return 0.;
#endif
}

double MTetrahedron::getVolume()
{
  double mat[3][3];
  getMat(mat);
  return det3x3(mat) / 6.;
}

void MTetrahedron::xyz2uvw(double xyz[3], double uvw[3])
{
  double mat[3][3], b[3], det;
  getMat(mat);
  b[0] = xyz[0] - getVertex(0)->x();
  b[1] = xyz[1] - getVertex(0)->y();
  b[2] = xyz[2] - getVertex(0)->z();
  sys3x3(mat, b, uvw, &det);
}

const polynomialBasis* MTetrahedron::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;

  int nv = getNumVolumeVertices();
  
  if ((nv == 0) && (o == -1)) {
    switch (order) {
    case 1: return polynomialBases::find(MSH_TET_4);
    case 2: return polynomialBases::find(MSH_TET_10);
    case 3: return polynomialBases::find(MSH_TET_20);
    case 4: return polynomialBases::find(MSH_TET_34);
    case 5: return polynomialBases::find(MSH_TET_52);
    default: Msg::Error("Order %d tetrahedron function space not implemented", order);
    }
  }
  else { 
    switch (order) {
    case 1: return polynomialBases::find(MSH_TET_4);
    case 2: return polynomialBases::find(MSH_TET_10);
    case 3: return polynomialBases::find(MSH_TET_20);
    case 4: return polynomialBases::find(MSH_TET_35);
    case 5: return polynomialBases::find(MSH_TET_56);
    case 6: return polynomialBases::find(MSH_TET_84);
    case 7: return polynomialBases::find(MSH_TET_120);
    case 8: return polynomialBases::find(MSH_TET_165);
    case 9: return polynomialBases::find(MSH_TET_220);
    case 10: return polynomialBases::find(MSH_TET_286);
    default: Msg::Error("Order %d tetrahedron function space not implemented", order);
    }
  }
  return 0;
}

const JacobianBasis* MTetrahedron::getJacobianFuncSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;

  int nv = getNumVolumeVertices();
  
  if ((nv == 0) && (o == -1)) {
    switch (order) {
    case 1: return JacobianBases::find(MSH_TET_4);
    case 2: return JacobianBases::find(MSH_TET_10);
    case 3: return JacobianBases::find(MSH_TET_20);
    case 4: return JacobianBases::find(MSH_TET_34);
    case 5: return JacobianBases::find(MSH_TET_52);
    default: Msg::Error("Order %d tetrahedron function space not implemented", order);
    }
  }
  else { 
    switch (order) {
    case 1: return JacobianBases::find(MSH_TET_4);
    case 2: return JacobianBases::find(MSH_TET_10);
    case 3: return JacobianBases::find(MSH_TET_20);
    case 4: return JacobianBases::find(MSH_TET_35);
    case 5: return JacobianBases::find(MSH_TET_56);
    case 6: return JacobianBases::find(MSH_TET_84);
    case 7: return JacobianBases::find(MSH_TET_120);
    case 8: return JacobianBases::find(MSH_TET_165);
    case 9: return JacobianBases::find(MSH_TET_220);
    case 10: return JacobianBases::find(MSH_TET_286);
    default: Msg::Error("Order %d tetrahedron function space not implemented", order);
    }
  }
  return 0;
}

int MTetrahedron10::getNumEdgesRep(){ return 6 * CTX::instance()->mesh.numSubEdges; }
int MTetrahedronN::getNumEdgesRep(){ return 6 * CTX::instance()->mesh.numSubEdges; }

static void _myGetEdgeRep(MTetrahedron *tet, int num, double *x, double *y, double *z,
                          SVector3 *n, int numSubEdges)
{
  static double pp[4][3] = {{0,0,0},{1,0,0},{0,1,0},{0,0,1}};
  static int ed [6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  int iEdge = num / numSubEdges;
  int iSubEdge = num % numSubEdges;  

  int iVertex1 = ed [iEdge][0];
  int iVertex2 = ed [iEdge][1];
  double t1 = (double) iSubEdge / (double) numSubEdges;
  double u1 = pp[iVertex1][0] * (1.-t1) + pp[iVertex2][0] * t1;
  double v1 = pp[iVertex1][1] * (1.-t1) + pp[iVertex2][1] * t1;
  double w1 = pp[iVertex1][2] * (1.-t1) + pp[iVertex2][2] * t1;

  double t2 = (double) (iSubEdge+1) / (double) numSubEdges;
  double u2 = pp[iVertex1][0] * (1.-t2) + pp[iVertex2][0] * t2;
  double v2 = pp[iVertex1][1] * (1.-t2) + pp[iVertex2][1] * t2;
  double w2 = pp[iVertex1][2] * (1.-t2) + pp[iVertex2][2] * t2;

  SPoint3 pnt1, pnt2;
  tet->pnt(u1,v1,w1,pnt1);
  tet->pnt(u2,v2,w2,pnt2);
  x[0] = pnt1.x(); x[1] = pnt2.x(); 
  y[0] = pnt1.y(); y[1] = pnt2.y();
  z[0] = pnt1.z(); z[1] = pnt2.z();

  // not great, but better than nothing
  static const int f[6] = {0, 0, 0, 1, 2, 3};
  n[0] = n[1] = tet->getFace(f[iEdge]).normal();
}

void MTetrahedron10::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

void MTetrahedronN::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

int MTetrahedronN::getNumFacesRep(){ return 4 * SQU(CTX::instance()->mesh.numSubEdges); }
int MTetrahedron10::getNumFacesRep(){ return 4 * SQU(CTX::instance()->mesh.numSubEdges); }

static void _myGetFaceRep(MTetrahedron *tet, int num, double *x, double *y, double *z, 
                          SVector3 *n, int numSubEdges)
{
  static double pp[4][3] = {{0,0,0},{1,0,0},{0,1,0},{0,0,1}};
  static int fak [4][3] = {{0,1,2},{0,1,3},{0,2,3},{1,2,3}};
  int iFace    = num / (numSubEdges * numSubEdges);
  int iSubFace = num % (numSubEdges * numSubEdges);  
  
  int iVertex1 = fak[iFace][0];
  int iVertex2 = fak[iFace][1];
  int iVertex3 = fak[iFace][2];

  /*
    0
    0 1
    0 1 2
    0 1 2 3
    0 1 2 3 4
    0 1 2 3 4 5
  */

  // on the first layer, we have (numSubEdges-1) * 2 + 1 triangles
  // on the second layer, we have (numSubEdges-2) * 2 + 1 triangles
  // on the ith layer, we have (numSubEdges-1-i) * 2 + 1 triangles
  int ix = 0, iy = 0;
  int nbt = 0;
  for (int i = 0; i < numSubEdges; i++){
    int nbl = (numSubEdges - i - 1) * 2 + 1;
    nbt += nbl;
    if (nbt > iSubFace){
      iy = i;
      ix = nbl - (nbt - iSubFace);
      break;
    }
  }

  const double d = 1. / numSubEdges;

  SPoint3 pnt1, pnt2, pnt3;
  double u1, v1, u2, v2, u3, v3;
  if (ix % 2 == 0){
    u1 = ix / 2 * d; v1= iy*d;
    u2 = (ix / 2 + 1) * d ; v2 =  iy * d;
    u3 = ix / 2 * d ; v3 =  (iy+1) * d;
  }
  else{
    u1 = (ix / 2 + 1) * d; v1= iy * d;
    u2 = (ix / 2 + 1) * d; v2= (iy + 1) * d;
    u3 = ix / 2 * d ; v3 =  (iy + 1) * d;
  }

  double U1 = pp[iVertex1][0] * (1.-u1-v1) + pp[iVertex2][0] * u1 + pp[iVertex3][0] * v1;
  double U2 = pp[iVertex1][0] * (1.-u2-v2) + pp[iVertex2][0] * u2 + pp[iVertex3][0] * v2;
  double U3 = pp[iVertex1][0] * (1.-u3-v3) + pp[iVertex2][0] * u3 + pp[iVertex3][0] * v3;

  double V1 = pp[iVertex1][1] * (1.-u1-v1) + pp[iVertex2][1] * u1 + pp[iVertex3][1] * v1;
  double V2 = pp[iVertex1][1] * (1.-u2-v2) + pp[iVertex2][1] * u2 + pp[iVertex3][1] * v2;
  double V3 = pp[iVertex1][1] * (1.-u3-v3) + pp[iVertex2][1] * u3 + pp[iVertex3][1] * v3;

  double W1 = pp[iVertex1][2] * (1.-u1-v1) + pp[iVertex2][2] * u1 + pp[iVertex3][2] * v1;
  double W2 = pp[iVertex1][2] * (1.-u2-v2) + pp[iVertex2][2] * u2 + pp[iVertex3][2] * v2;
  double W3 = pp[iVertex1][2] * (1.-u3-v3) + pp[iVertex2][2] * u3 + pp[iVertex3][2] * v3;

  tet->pnt(U1, V1, W1, pnt1);
  tet->pnt(U2, V2, W2, pnt2);
  tet->pnt(U3, V3, W3, pnt3);

  x[0] = pnt1.x(); x[1] = pnt2.x(); x[2] = pnt3.x();
  y[0] = pnt1.y(); y[1] = pnt2.y(); y[2] = pnt3.y();
  z[0] = pnt1.z(); z[1] = pnt2.z(); z[2] = pnt3.z();

  SVector3 d1(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
  SVector3 d2(x[2] - x[0], y[2] - y[0], z[2] - z[0]);
  n[0] = crossprod(d1, d2);
  n[0].normalize();
  n[1] = n[0];
  n[2] = n[0];
}

void MTetrahedronN::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

void MTetrahedron10::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

void MTetrahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQTetPts(pOrder);
  *pts = getGQTetPts(pOrder);
}

void MTetrahedron::getFaceInfo(const MFace &face, int &ithFace, int &sign, int &rot) const
{
  for (ithFace = 0; ithFace < 4; ithFace++){
    MVertex *v0 = _v[faces_tetra(ithFace, 0)];
    MVertex *v1 = _v[faces_tetra(ithFace, 1)];
    MVertex *v2 = _v[faces_tetra(ithFace, 2)];

    if (v0 == face.getVertex(0) && v1 == face.getVertex(1) && v2 == face.getVertex(2)){
      sign = 1; rot = 0; return;
    }
    if (v0 == face.getVertex(1) && v1 == face.getVertex(2) && v2 == face.getVertex(0)){
      sign = 1; rot = 1; return;
    }
    if (v0 == face.getVertex(2) && v1 == face.getVertex(0) && v2 == face.getVertex(1)){
      sign = 1; rot = 2; return;
    }
    if (v0 == face.getVertex(0) && v1 == face.getVertex(2) && v2 == face.getVertex(1)){
      sign = -1; rot = 0; return;
    }
    if (v0 == face.getVertex(1) && v1 == face.getVertex(0) && v2 == face.getVertex(2)){
      sign = -1; rot = 1; return;
    }
    if (v0 == face.getVertex(2) && v1 == face.getVertex(1) && v2 == face.getVertex(0)){
      sign = -1; rot = 2; return;
    }
  }
  Msg::Error("Could not get face information for tetrahedron %d", getNum());
}
