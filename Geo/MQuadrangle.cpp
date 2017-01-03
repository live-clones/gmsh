// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#include "MQuadrangle.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "Numeric.h"
#include "BasisFactory.h"

#if defined(HAVE_MESH)
#include "qualityMeasures.h"
#endif

#include <cstring>

#define SQU(a)      ((a)*(a))

void MQuadrangle::getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                             SVector3 *n)
{
  // don't use MElement::_getEdgeRep: it's slow due to the creation of MFace
  MVertex *v0 = _v[edges_quad(num, 0)];
  MVertex *v1 = _v[edges_quad(num, 1)];
  x[0] = v0->x(); y[0] = v0->y(); z[0] = v0->z();
  x[1] = v1->x(); y[1] = v1->y(); z[1] = v1->z();
  if(CTX::instance()->mesh.lightLines){
    static const int vv[4] = {2, 3, 0, 1};
    MVertex *v2 = _v[vv[num]];
    SVector3 t1(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
    SVector3 t2(v2->x() - x[0], v2->y() - y[0], v2->z() - z[0]);
    SVector3 normal = crossprod(t1, t2);
    normal.normalize();
    n[0] = n[1] = normal;
  }
  else{
    n[0] = n[1] = SVector3(0., 0., 1.);
  }
}

int MQuadrangleN::getNumEdgesRep(bool curved)
{
  return curved ? 4 * CTX::instance()->mesh.numSubEdges : 4;
}

int MQuadrangle8::getNumEdgesRep(bool curved)
{
  return curved ? 4 * CTX::instance()->mesh.numSubEdges : 4;
}

int MQuadrangle9::getNumEdgesRep(bool curved)
{
  return curved ? 4 * CTX::instance()->mesh.numSubEdges : 4;
}

double MQuadrangle::getVolume()
{
  if(getNumVertices() > 4)
    return MElement::getVolume();
  double a = _v[0]->distance(_v[1]);
  double b = _v[1]->distance(_v[2]);
  double c = _v[2]->distance(_v[3]);
  double d = _v[3]->distance(_v[0]);
  double m = _v[0]->distance(_v[2]);
  double n = _v[1]->distance(_v[3]);
  double mn = 2. * m * n;
  double abcd = a*a - b*b + c*c - d*d;
  return sqrt( mn*mn - abcd*abcd ) / 4.;
}

static void _myGetEdgeRep(MQuadrangle *q, int num, double *x, double *y, double *z,
                          SVector3 *n, int numSubEdges)
{
  n[0] = n[1] = q->getFace(0).normal();
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

void MQuadrangleN::getEdgeRep(bool curved, int num,
                              double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MQuadrangle::getEdgeRep(false, num, x, y, z, n);
}

void MQuadrangle8::getEdgeRep(bool curved, int num,
                              double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MQuadrangle::getEdgeRep(false, num, x, y, z, n);
}

void MQuadrangle9::getEdgeRep(bool curved, int num,
                              double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MQuadrangle::getEdgeRep(false, num, x, y, z, n);
}

int MQuadrangleN::getNumFacesRep(bool curved)
{
  return curved ? 2*SQU(CTX::instance()->mesh.numSubEdges) : 2;
}

int MQuadrangle8::getNumFacesRep(bool curved)
{
  return curved ? 2*SQU(CTX::instance()->mesh.numSubEdges) : 2;
}

int MQuadrangle9::getNumFacesRep(bool curved)
{
  return curved ? 2*SQU(CTX::instance()->mesh.numSubEdges) : 2;
}

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

void MQuadrangleN::getFaceRep(bool curved, int num,
                              double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MQuadrangle::getFaceRep(false, num, x, y, z, n);
}

void MQuadrangle8::getFaceRep(bool curved, int num,
                              double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MQuadrangle::getFaceRep(false, num, x, y, z, n);
}

void MQuadrangle9::getFaceRep(bool curved, int num,
                              double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MQuadrangle::getFaceRep(false, num, x, y, z, n);
}

void MQuadrangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQQPts(pOrder);
  *pts = getGQQPts(pOrder);
}

double  MQuadrangle::etaShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmQuadrangle::eta(this);
#else
  return 0.;
#endif
}

double MQuadrangle::gammaShapeMeasure(){
#if defined(HAVE_MESH)
  return qmQuadrangle::gamma(this);
#else
  return 0.;
#endif
}

double MQuadrangle::angleShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmQuadrangle::angles(this);
#else
  return 1.;
#endif
}

double MQuadrangle::getOuterRadius()
{
  // FIXME: TODO! (BRUNO SENY)
  return 1.0;
}

double MQuadrangle::getInnerRadius()
{
#if defined(HAVE_LAPACK)
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
#else // HAVE_LAPACK
  // Default implementation. Not sure that the following give exactly
  // the same value as the HAVE_LAPACK case !
  // but same value for a square

  // Mid-point of each edge of the quadrangle
  SPoint3 A(_v[0]->x()+_v[1]->x(),_v[0]->y()+_v[1]->y(),_v[0]->z()+_v[1]->z());
  SPoint3 B(_v[1]->x()+_v[2]->x(),_v[1]->y()+_v[2]->y(),_v[1]->z()+_v[2]->z());
  SPoint3 C(_v[2]->x()+_v[3]->x(),_v[2]->y()+_v[3]->y(),_v[2]->z()+_v[3]->z());
  SPoint3 D(_v[3]->x()+_v[0]->x(),_v[3]->y()+_v[0]->y(),_v[3]->z()+_v[0]->z());
  A*=0.5; B*=0.5; C*=0.5; D*=0.5;

  // compute the length of the side
  double a = A.distance(B);
  double b = B.distance(C);
  double c = C.distance(D);
  double d = D.distance(A);

  // perimeter
  double s = a+b+c+d;
  double halfs = 0.5*s;

  return 0.25*sqrt( (a*c+b*d)*(a*d+b*c)*(a*b+c*d)/
                   ((halfs-a)*(halfs-b)*(halfs-c)*(halfs-d))
                  );
#endif // HAVE_LAPACK
}


void MQuadrangle::reorient(int rot, bool swap) {
  MVertex* tmp[4];
  if (swap) for (int i=0;i<4;i++) tmp[i] = _v[(4-i+rot)%4];
  else      for (int i=0;i<4;i++) tmp[i] = _v[(4+i-rot)%4];
  std::memcpy(_v,tmp,4*sizeof(MVertex*));
}

void MQuadrangle8::reorient(int rot, bool swap) {

  if (rot == 0 && !swap) return;

  MQuadrangle::reorient(rot,swap);
  MVertex* tmp[4];
  if (swap) for (int i=0;i<4;i++) tmp[i] = _vs[(7-i+rot)%4];
  else      for (int i=0;i<4;i++) tmp[i] = _vs[(4+i-rot)%4];
  std::memcpy(_vs,tmp,4*sizeof(MVertex*));
}

void MQuadrangle9::reorient(int rot, bool swap) {

  if (rot == 0 && !swap) return;

  MQuadrangle::reorient(rot,swap);
  MVertex* tmp[4];
  if (swap) for (int i=0;i<4;i++) tmp[i] = _vs[(7-i+rot)%4]; // edge swapped
  else      for (int i=0;i<4;i++) tmp[i] = _vs[(4+i-rot)%4];
  std::memcpy(_vs,tmp,4*sizeof(MVertex*));
}

void MQuadrangleN::reorient(int rot, bool swap) {

  if (rot == 0 && !swap) return;

  MQuadrangle::reorient(rot,swap);
  int order  = getPolynomialOrder();
  int nbEdgePts = order - 1;
  unsigned int idx = 0;

  std::vector<MVertex*> tmp;

  if (swap) {
    for (int iEdge=0;iEdge<4;iEdge++) {
      int edgeIdx = ((7-iEdge+rot)%4)*nbEdgePts;
      for (int i=nbEdgePts-1;i>=0;i--) tmp.push_back(_vs[edgeIdx+i]);
    }
  }
  else {
    for (int iEdge=0;iEdge<4;iEdge++) {
      int edgeIdx = ((4+iEdge-rot)%4)*nbEdgePts;
      for (int i=0;i<nbEdgePts;i++)    tmp.push_back(_vs[edgeIdx+i]);
    }
  }

  idx += 4*nbEdgePts;

  if (_vs.size() >= idx) {
    nbEdgePts = order - 3;
    if (order > 2) {
      if (swap) for (int i=0;i<4;i++) tmp.push_back(_vs[idx + (4-i+rot)%4]);
      else      for (int i=0;i<4;i++) tmp.push_back(_vs[idx + (4+i-rot)%4]);
      idx += 4;
      if (order > 3) {
        if (swap) for (int i=0;i<4;i++) tmp.push_back(_vs[idx + (7-i+rot)%4]);
        else      for (int i=0;i<4;i++) tmp.push_back(_vs[idx + (4+i-rot)%4]);
        idx += 4;
        if (order > 4) Msg::Error("Reorientation of quad not supported above order 4");
      }
    }
    tmp.push_back(_vs[idx]);
  }
  _vs = tmp;
}
