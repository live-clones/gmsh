// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "MQuadrangle.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "qualityMeasures.h"
#include "Numeric.h"

#if defined(HAVE_MESH)
#include "qualityMeasures.h"
#endif

#define SQU(a)      ((a)*(a))

const polynomialBasis* MQuadrangle::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;

  int nf = getNumFaceVertices();  

  if ((nf == 0) && (o == -1)) {
    switch (order) {
      case 1: return &polynomialBases::find(MSH_QUA_4);
      case 2: return &polynomialBases::find(MSH_QUA_8);
      case 3: return &polynomialBases::find(MSH_QUA_12);
      case 4: return &polynomialBases::find(MSH_QUA_16I);
      case 5: return &polynomialBases::find(MSH_QUA_20);
    }
  }
  switch (order) {
    case 1: return &polynomialBases::find(MSH_QUA_4);
    case 2: return &polynomialBases::find(MSH_QUA_9);
    case 3: return &polynomialBases::find(MSH_QUA_16);
    case 4: return &polynomialBases::find(MSH_QUA_25);
    case 5: return &polynomialBases::find(MSH_QUA_36);
    default: Msg::Error("Order %d triangle function space not implemented", order);
  }
  return 0;
}

int MQuadrangleN::getNumEdgesRep(){ return 4 * CTX::instance()->mesh.numSubEdges; }
int MQuadrangle8::getNumEdgesRep(){ return 4 * CTX::instance()->mesh.numSubEdges; }
int MQuadrangle9::getNumEdgesRep(){ return 4 * CTX::instance()->mesh.numSubEdges; }



static void _myGetEdgeRep(MQuadrangle *q, int num, double *x, double *y, double *z,
                          SVector3 *n, int numSubEdges)
{
  n[0] = n[1] = n[2] = n[3] = q->getFace(0).normal();
  int ie = num/numSubEdges;
  int isub = num%numSubEdges;
  double xi1 = -1. + (2.*isub)/numSubEdges;
  double xi2 = -1. + (2.*(isub+1))/numSubEdges;
  SPoint3 pnt1, pnt2;
  switch(ie){
    case 0: 
      q->pnt( xi1, -1., 0., pnt1);
      q->pnt( xi2, -1., 0., pnt2);
      break;
    case 1:
      q->pnt( 1., xi1, 0., pnt1);
      q->pnt( 1., xi2, 0., pnt2);
      break;
    case 2:
      q->pnt( xi1, 1., 0., pnt1);
      q->pnt( xi2, 1., 0., pnt2);
      break;
    case 3:
      q->pnt(-1., xi1, 0., pnt1);
      q->pnt(-1., xi2, 0., pnt2);
      break;
  }
  x[0] = pnt1.x(); x[1] = pnt2.x();
  y[0] = pnt1.y(); y[1] = pnt2.y();
  z[0] = pnt1.z(); z[1] = pnt2.z();
}

void MQuadrangleN::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}
void MQuadrangle8::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}
void MQuadrangle9::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}


int MQuadrangleN::getNumFacesRep(){ return 2*SQU(CTX::instance()->mesh.numSubEdges); }
int MQuadrangle8::getNumFacesRep(){ return 2*SQU(CTX::instance()->mesh.numSubEdges); }
int MQuadrangle9::getNumFacesRep(){ return 2*SQU(CTX::instance()->mesh.numSubEdges); }

static void _myGetFaceRep(MQuadrangle *t, int num, double *x, double *y, double *z,
                          SVector3 *n, int numSubEdges)
{
  int io = num%2;
  int ix = (num/2)/numSubEdges;
  int iy = (num/2)%numSubEdges;

  const double d = 2. / numSubEdges;
  const double ox = -1. + d*ix;
  const double oy = -1. + d*iy;

  SPoint3 pnt1, pnt2, pnt3;
  double J1[3][3], J2[3][3], J3[3][3];
  if (io == 0){
    t->pnt(ox, oy, 0, pnt1);
    t->pnt(ox + d, oy, 0, pnt2);
    t->pnt(ox + d, oy + d, 0, pnt3);
    t->getJacobian(ox, oy, 0, J1);
    t->getJacobian(ox + d, oy, 0, J2);
    t->getJacobian(ox + d, oy + d, 0, J3);
  } else{
    t->pnt(ox, oy, 0, pnt1);
    t->pnt(ox + d, oy + d, 0, pnt2);
    t->pnt(ox, oy + d, 0, pnt3);
    t->getJacobian(ox, oy, 0, J1);
    t->getJacobian(ox + d, oy + d, 0, J2);
    t->getJacobian(ox, oy + d, 0, J3);
  }
  {
    SVector3 d1(J1[0][0], J1[0][1], J1[0][2]);
    SVector3 d2(J1[1][0], J1[1][1], J1[1][2]);
    n[0] = crossprod(d1, d2);
    n[0].normalize();
  }
  {
    SVector3 d1(J2[0][0], J2[0][1], J2[0][2]);
    SVector3 d2(J2[1][0], J2[1][1], J2[1][2]);
    n[1] = crossprod(d1, d2);
    n[1].normalize();
  }
  {
    SVector3 d1(J3[0][0], J3[0][1], J3[0][2]);
    SVector3 d2(J3[1][0], J3[1][1], J3[1][2]);
    n[2] = crossprod(d1, d2);
    n[2].normalize();
  }

  x[0] = pnt1.x(); x[1] = pnt2.x(); x[2] = pnt3.x();
  y[0] = pnt1.y(); y[1] = pnt2.y(); y[2] = pnt3.y();
  z[0] = pnt1.z(); z[1] = pnt2.z(); z[2] = pnt3.z();
}

void MQuadrangleN::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}
void MQuadrangle8::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}
void MQuadrangle9::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

void MQuadrangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQQPts(pOrder);
  *pts = getGQQPts(pOrder);
}

double MQuadrangle::distoShapeMeasure()
{
#if defined(HAVE_MESH)
  //  return qmTriangleAngles(this);
  return qmDistorsionOfMapping(this);
#else
  return 0.;
#endif
}


double MQuadrangle::angleShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmQuadrangleAngles(this);
#else
  return 1.;
#endif
}

double MQuadrangle::getInnerRadius()
{
  // get the coordinates (x, y, z) of the 4 points defining the Quad
  double x[4] = {_v[0]->x(), _v[1]->x(), _v[2]->x(), _v[3]->x()};
  double y[4] = {_v[0]->y(), _v[1]->y(), _v[2]->y(), _v[3]->y()};
  double z[4] = {_v[0]->z(), _v[1]->z(), _v[2]->z(), _v[3]->z()};
                
  // get the coefficient (a,b,c,d) of the mean plane - least square!
  // the plane has for equation " a*x+b*y+c*z+d=0 "

  // compute the centroid of the 4 points
  double xm = (x[0] + x[1] + x[2] + x[3]) / 4;
  double ym = (y[0] + y[1] + y[2] + y[3]) / 4;
  double zm = (z[0] + z[1] + z[2] + z[3]) / 4;
        
  // using svd decomposition
  fullMatrix<double> U(4,3), V(3,3);
  fullVector<double> sigma(3);
  for (int i = 0; i < 4; i++) {
    U(i, 0) = x[i] - xm;
    U(i, 1) = y[i] - ym;
    U(i, 2) = z[i] - zm;
  }
  
  U.svd(V, sigma);
  double svd[3];
  svd[0] = sigma(0);
  svd[1] = sigma(1);
  svd[2] = sigma(2);
  int min;
  if(fabs(svd[0]) < fabs(svd[1]) && fabs(svd[0]) < fabs(svd[2]))
    min = 0;
  else if(fabs(svd[1]) < fabs(svd[0]) && fabs(svd[1]) < fabs(svd[2]))
    min = 1;
  else
    min = 2;
  double a = V(0, min);
  double b = V(1, min);
  double c = V(2, min);
  
  double d = -(xm * a + ym * b + zm * c);
  
  double norm = sqrt(a*a+b*b+c*c);
  
  // projection of the 4 original points on the mean_plane
  
  double xp[4], yp[4], zp[4];
  
  for (int i = 0; i < 4; i++) {
    xp[i] = ((b*b+c*c)*x[i]-a*b*y[i]-a*c*z[i]-d*a)/norm;
    yp[i] = (-a*b*x[i]+(a*a+c*c)*y[i]-b*c*z[i]-d*b)/norm;
    zp[i] = (-a*c*x[i]-b*c*y[i]+(a*a+b*b)*z[i]-d*c)/norm;
  }
  
  // go from XYZ-plane to XY-plane
  
  // 4 points, 4 edges => 4 inner radii of circles tangent to (at
  // least) 3 of the four edges!
  double xn[4], yn[4], r[4];
  
  planarQuad_xyz2xy(xp, yp, zp, xn, yn);
  
  // compute for each of the 4 possibilities the incircle radius,
  // keeping the minimum
  double R = 1.e22;
  for (int j = 0; j < 4; j++){
    r[j] = computeInnerRadiusForQuad(xn, yn, j);
    if(r[j] < R){
      R = r[j];
    }
  }
  return R;
}
