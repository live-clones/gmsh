// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "qualityMeasures.h"
#include "BDS.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "Numeric.h"
#include "polynomialBasis.h"
#include "GmshMessage.h"
#include <limits>
#include <string.h>

double qmTriangle(const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3,
                  const qualityMeasure4Triangle &cr)
{
  return qmTriangle(p1->X, p1->Y, p1->Z, p2->X, p2->Y, p2->Z, p3->X, p3->Y, p3->Z, cr);
}

double qmTriangle(BDS_Face *t, const qualityMeasure4Triangle &cr)
{
  BDS_Point *n[4];
  t->getNodes(n);
  return qmTriangle(n[0], n[1], n[2], cr);
}

double qmTriangle(MTriangle*t, const qualityMeasure4Triangle &cr)
{
  return qmTriangle(t->getVertex(0), t->getVertex(1), t->getVertex(2), cr);
}

double qmTriangle(const MVertex *v1, const MVertex *v2, const MVertex *v3,
                  const qualityMeasure4Triangle &cr)
{
  return qmTriangle(v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(),
                    v3->x(), v3->y(), v3->z(), cr);
}

// Triangle abc
// quality is between 0 and 1

double qmTriangle(const double &xa, const double &ya, const double &za,
                  const double &xb, const double &yb, const double &zb,
                  const double &xc, const double &yc, const double &zc,
                  const qualityMeasure4Triangle &cr)
{
  double quality;
  switch(cr){
  case QMTRI_RHO:
    {
      // quality = rho / R = 2 * inscribed radius / circumradius
      double a [3] = {xc - xb, yc - yb, zc - zb};
      double b [3] = {xa - xc, ya - yc, za - zc};
      double c [3] = {xb - xa, yb - ya, zb - za};
      norme(a);
      norme(b);
      norme(c);
      double pva [3]; prodve(b, c, pva); const double sina = norm3(pva);
      double pvb [3]; prodve(c, a, pvb); const double sinb = norm3(pvb);
      double pvc [3]; prodve(a, b, pvc); const double sinc = norm3(pvc);

      if (sina == 0.0 && sinb == 0.0 && sinc == 0.0) quality = 0.0;
      else quality = 2 * (2 * sina * sinb * sinc / (sina + sinb + sinc));
    }
    break;
    // condition number
  case QMTRI_COND:
    {
      /*
      double a [3] = {xc - xa, yc - ya, zc - za};
      double b [3] = {xb - xa, yb - ya, zb - za};
      double c [3] ; prodve(a, b, c); norme(c);
      double A[3][3] = {{a[0] , b[0] , c[0]} ,
                        {a[1] , b[1] , c[1]} ,
                        {a[2] , b[2] , c[2]}};
      */
      quality = -1;
    }
    break;
  default:
    Msg::Error("Unknown quality measure");
    return 0.;
  }

  return quality;
}

double qmTet(MTetrahedron *t, const qualityMeasure4Tet &cr, double *volume)
{
  return qmTet(t->getVertex(0), t->getVertex(1), t->getVertex(2), t->getVertex(3),
               cr, volume);
}

double qmTet(const MVertex *v1, const MVertex *v2, const MVertex *v3,
             const MVertex *v4, const qualityMeasure4Tet &cr, double *volume)
{
  return qmTet(v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(),
               v3->x(), v3->y(), v3->z(), v4->x(), v4->y(), v4->z(), cr, volume);
}

double qmTet(const double &x1, const double &y1, const double &z1,
             const double &x2, const double &y2, const double &z2,
             const double &x3, const double &y3, const double &z3,
             const double &x4, const double &y4, const double &z4,
             const qualityMeasure4Tet &cr, double *volume)
{
  switch(cr){
  case QMTET_ONE:
    return 1.0;
  case QMTET_3:
    {
      double mat[3][3];
      mat[0][0] = x2 - x1;
      mat[0][1] = x3 - x1;
      mat[0][2] = x4 - x1;
      mat[1][0] = y2 - y1;
      mat[1][1] = y3 - y1;
      mat[1][2] = y4 - y1;
      mat[2][0] = z2 - z1;
      mat[2][1] = z3 - z1;
      mat[2][2] = z4 - z1;
      *volume = fabs(det3x3(mat)) / 6.;
      double l = ((x2 - x1) * (x2 - x1) +
                  (y2 - y1) * (y2 - y1) +
                  (z2 - z1) * (z2 - z1));
      l += ((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) + (z3 - z1) * (z3 - z1));
      l += ((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) + (z4 - z1) * (z4 - z1));
      l += ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2));
      l += ((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2) + (z4 - z2) * (z4 - z2));
      l += ((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4) + (z3 - z4) * (z3 - z4));
      return 12. * pow(3 * fabs(*volume), 2. / 3.) / l;
    }
  case QMTET_2:
    {
      double mat[3][3];
      mat[0][0] = x2 - x1;
      mat[0][1] = x3 - x1;
      mat[0][2] = x4 - x1;
      mat[1][0] = y2 - y1;
      mat[1][1] = y3 - y1;
      mat[1][2] = y4 - y1;
      mat[2][0] = z2 - z1;
      mat[2][1] = z3 - z1;
      mat[2][2] = z4 - z1;
      *volume = fabs(det3x3(mat)) / 6.;
      double p0[3] = {x1, y1, z1};
      double p1[3] = {x2, y2, z2};
      double p2[3] = {x3, y3, z3};
      double p3[3] = {x4, y4, z4};
      double s1 = fabs(triangle_area(p0, p1, p2));
      double s2 = fabs(triangle_area(p0, p2, p3));
      double s3 = fabs(triangle_area(p0, p1, p3));
      double s4 = fabs(triangle_area(p1, p2, p3));
      double rhoin = 3. * fabs(*volume) / (s1 + s2 + s3 + s4);
      double l = sqrt((x2 - x1) * (x2 - x1) +
                      (y2 - y1) * (y2 - y1) +
                      (z2 - z1) * (z2 - z1));
      l = std::max(l, sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) +
                           (z3 - z1) * (z3 - z1)));
      l = std::max(l, sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) +
                           (z4 - z1) * (z4 - z1)));
      l = std::max(l, sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) +
                           (z3 - z2) * (z3 - z2)));
      l = std::max(l, sqrt((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2) +
                           (z4 - z2) * (z4 - z2)));
      l = std::max(l, sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4) +
                           (z3 - z4) * (z3 - z4)));
      return 2. * sqrt(6.) * rhoin / l;
    }
    break;
  case QMTET_COND:
    {
      /// condition number is defined as (see Knupp & Freitag in IJNME) 
      double INVW[3][3] = {{1,-1./sqrt(3.),-1./sqrt(6.)},{0,2/sqrt(3.),-1./sqrt(6.)},{0,0,sqrt(1.5)}};
      double A[3][3] = {{x2-x1,y2-y1,z2-z1},{x3-x1,y3-y1,z3-z1},{x4-x1,y4-y1,z4-z1}};
      double S[3][3],INVS[3][3];
      matmat(A,INVW,S);
      *volume = inv3x3(S,INVS) * 0.70710678118654762;//2/sqrt(2);
      double normS = norm2 (S);
      double normINVS = norm2 (INVS);
      return normS * normINVS;      
    }
  default:
    Msg::Error("Unknown quality measure");
    return 0.;
  }
}

/*
double conditionNumberAndDerivativeOfTet(const double &x1, const double &y1, const double &z1,
					 const double &x2, const double &y2, const double &z2,
					 const double &x3, const double &y3, const double &z3,
					 const double &x4, const double &y4, const double &z4){

  double INVW[3][3] = {{1,-1./sqrt(3.),-1./sqrt(6.)},{0,2/sqrt(3.),-1./sqrt(6.)},{0,0,sqrt(1.5)}};
      double A[3][3] = {{x2-x1,y2-y1,z2-z1},{x3-x1,y3-y1,z3-z1},{x4-x1,y4-y1,z4-z1}};
      double S[3][3],INVS[3][3];
      matmat(A,INVW,S);
      double sigma = inv3x3(S,INVS);
      double normS = norm2 (S);
      double normINVS = norm2 (INVS);
      conditionNumber = normS * normINVS;      
  
}
*/

double qmTriangleAngles (MTriangle *e) {
  double a = 500;
  double worst_quality = std::numeric_limits<double>::max();
  double mat[3][3];
  double mat2[3][3];
  double den = atan(a*(M_PI/9)) + atan(a*(M_PI/9));

  // This matrix is used to "rotate" the triangle to get each vertex
  // as the "origin" of the mapping in turn
  double rot[3][3];
  rot[0][0]=-1; rot[0][1]=1; rot[0][2]=0;
  rot[1][0]=-1; rot[1][1]=0; rot[1][2]=0;
  rot[2][0]= 0; rot[2][1]=0; rot[2][2]=1;
  double tmp[3][3];

  //double minAngle = 120.0;
  for (int i = 0; i < e->getNumPrimaryVertices(); i++) {
    const double u = i == 1 ? 1 : 0;
    const double v = i == 2 ? 1 : 0;
    const double w = 0;
    e->getJacobian(u, v, w, mat);
    e->getPrimaryJacobian(u,v,w,mat2);
    for (int j = 0; j < i; j++) {
      matmat(rot,mat,tmp);
      memcpy(mat, tmp, sizeof(mat));
    }
    //get angle
    double v1[3] = {mat[0][0],  mat[0][1],  mat[0][2] };
    double v2[3] = {mat[1][0],  mat[1][1],  mat[1][2] };
    double v3[3] = {mat2[0][0],  mat2[0][1],  mat2[0][2] };
    double v4[3] = {mat2[1][0],  mat2[1][1],  mat2[1][2] };
    norme(v1);
    norme(v2);
    norme(v3);
    norme(v4);
    double v12[3], v34[3];
    prodve(v1,v2,v12);
    prodve(v3,v4,v34);
    norme(v12);
    norme(v34);
    double orientation;
    prosca(v12,v34,&orientation);

    // If the triangle is "flipped" it's no good
    if (orientation < 0)
      return -std::numeric_limits<double>::max();

    double c;
    prosca(v1,v2,&c);
    double x = acos(c)-M_PI/3;
    //double angle = (x+M_PI/3)/M_PI*180;
    double quality = (atan(a*(x+M_PI/9)) + atan(a*(M_PI/9-x)))/den;
    worst_quality = std::min(worst_quality, quality);

    //minAngle = std::min(angle, minAngle);
    //printf("Angle %g ", angle);
    // printf("Quality %g\n",quality);
  }
  //printf("MinAngle %g \n", minAngle);
  //return minAngle;

  return worst_quality;
}


double qmQuadrangleAngles (MQuadrangle *e) {
  double a = 100;
  double worst_quality = std::numeric_limits<double>::max();
  double mat[3][3];
  double mat2[3][3];
  double den = atan(a*(M_PI/4)) + atan(a*(2*M_PI/4 - (M_PI/4)));

  // This matrix is used to "rotate" the triangle to get each vertex
  // as the "origin" of the mapping in turn
  //double rot[3][3];
  //rot[0][0]=-1; rot[0][1]=1; rot[0][2]=0;
  //rot[1][0]=-1; rot[1][1]=0; rot[1][2]=0;
  //rot[2][0]= 0; rot[2][1]=0; rot[2][2]=1;
  //double tmp[3][3];

  const double u[9] = {-1,-1, 1, 1, 0,0,1,-1,0};
  const double v[9] = {-1, 1, 1,-1, -1,1,0,0,0};

  for (int i = 0; i < 9; i++) {

    e->getJacobian(u[i], v[i], 0, mat);
    e->getPrimaryJacobian(u[i],v[i],0,mat2);
    //for (int j = 0; j < i; j++) {
    //  matmat(rot,mat,tmp);
    //  memcpy(mat, tmp, sizeof(mat));
    //}

    //get angle
    double v1[3] = {mat[0][0],  mat[0][1],  mat[0][2] };
    double v2[3] = {mat[1][0],  mat[1][1],  mat[1][2] };
    double v3[3] = {mat2[0][0],  mat2[0][1],  mat2[0][2] };
    double v4[3] = {mat2[1][0],  mat2[1][1],  mat2[1][2] };
    norme(v1);
    norme(v2);
    norme(v3);
    norme(v4);
    double v12[3], v34[3];
    prodve(v1,v2,v12);
    prodve(v3,v4,v34);
    norme(v12);
    norme(v34);
    double orientation;
    prosca(v12,v34,&orientation);

    // If the if the triangle is "flipped" it's no good
    //    if (orientation < 0)
    //      return -std::numeric_limits<double>::max();

    double c;
    prosca(v1,v2,&c);
    double x = fabs(acos(c))-M_PI/2;
    //double angle = fabs(acos(c))*180/M_PI;
    double quality = (atan(a*(x+M_PI/4)) + atan(a*(2*M_PI/4 - (x+M_PI/4))))/den;
    worst_quality = std::min(worst_quality, quality);
  }
  
  return worst_quality;

}


namespace {


// Compute unit vector
inline void unitVec(const double &x0, const double &y0, const double &z0,
                    const double &x1, const double &y1, const double &z1,
                    double &x01n, double &y01n, double &z01n)
{
  const double x01 = x1-x0, y01 = y1-y0, z01 = z1-z0;
  const double invL01 = 1./sqrt(x01*x01 + y01*y01 + z01*z01);
  x01n = x01*invL01; y01n = y01*invL01; z01n = z01*invL01;
}


// Compute unit vector and gradients w.r.t. x0, y0, z0, x1, y1, z1
inline void unitVecAndGrad(const double &x0, const double &y0, const double &z0,
                           const double &x1, const double &y1, const double &z1,
                           fullMatrix<double> &res)
{
  const double x01 = x1-x0, y01 = y1-y0, z01 = z1-z0;
  const double x01Sq = x01*x01, y01Sq = y01*y01, z01Sq = z01*z01;
  const double invL01Sq = 1./(x01Sq+y01Sq+z01Sq), invL01 = sqrt(invL01Sq);
  const double invL01Cu = invL01Sq*invL01;

  double &dx01ndx0 = res(0, 0), &dx01ndy0 = res(0, 1), &dx01ndz0 = res(0, 2),
          &dx01ndx1 = res(0, 3), &dx01ndy1 = res(0, 4), &dx01ndz1 = res(0, 5), &x01n = res(0, 6);
  double &dy01ndx0 = res(1, 0), &dy01ndy0 = res(1, 1), &dy01ndz0 = res(1, 2),
          &dy01ndx1 = res(1, 3), &dy01ndy1 = res(1, 4), &dy01ndz1 = res(1, 5), &y01n = res(1, 6);
  double &dz01ndx0 = res(2, 0), &dz01ndy0 = res(2, 1), &dz01ndz0 = res(2, 2),
          &dz01ndx1 = res(2, 3), &dz01ndy1 = res(2, 4), &dz01ndz1 = res(2, 5), &z01n = res(2, 6);

  dx01ndx0 = x01Sq*invL01Cu-invL01;
  dx01ndy0 = x01*y01*invL01Cu;
  dx01ndz0 = x01*z01*invL01Cu;
  dx01ndx1 = -dx01ndx0;
  dx01ndy1 = -dx01ndy0;
  dx01ndz1 = -dx01ndz0;
  x01n = x01*invL01;

  dy01ndx0 = dx01ndy0;
  dy01ndy0 = y01Sq*invL01Cu-invL01;
  dy01ndz0 = y01*z01*invL01Cu;
  dy01ndx1 = -dy01ndx0;
  dy01ndy1 = -dy01ndy0;
  dy01ndz1 = -dy01ndz0;
  y01n = y01*invL01;

  dz01ndx0 = dx01ndz0;
  dz01ndy0 = dy01ndz0;
  dz01ndz0 = z01Sq*invL01Cu-invL01;
  dz01ndx1 = -dx01ndz0;
  dz01ndy1 = -dz01ndy0;
  dz01ndz1 = -dz01ndz0;
  z01n = z01*invL01;
}


// Given vectors a and b, compute area of triangle defined by both vectors (times a factor)
inline double triArea(const double fact,
                      const double &xa, const double &ya, const double &za,
                      const double &xb, const double &yb, const double &zb)
{
  const double zn = xa*yb - xb*ya, yn = za*xb - xa*zb, xn = ya*zb - za*yb;
  return fact * sqrt(xn*xn + yn*yn + zn*zn);
}


// Given vectors (0, 1) and (0, 2) and their gradients, compute area of triangle
// defined by both vectors and grad. w.r.t. x0, y0, z0, x1, y1, z1, x2, y2, z2 (times a factor)
inline void triAreaAndGrad(const double fact, const fullMatrix<double> &vga,
                           const fullMatrix<double> &vgb, fullVector<double> &res)
{
  const double &dxadx0 = vga(0, 0), &dxady0 = vga(0, 1), &dxadz0 = vga(0, 2),
                &dxadx1 = vga(0, 3), &dxady1 = vga(0, 4), &dxadz1 = vga(0, 5), &xa = vga(0, 6);
  const double &dyadx0 = vga(1, 0), &dyady0 = vga(1, 1), &dyadz0 = vga(1, 2),
                &dyadx1 = vga(1, 3), &dyady1 = vga(1, 4), &dyadz1 = vga(1, 5), &ya = vga(1, 6);
  const double &dzadx0 = vga(2, 0), &dzady0 = vga(2, 1), &dzadz0 = vga(2, 2),
                &dzadx1 = vga(2, 3), &dzady1 = vga(2, 4), &dzadz1 = vga(2, 5), &za = vga(2, 6);

  const double &dxbdx0 = vgb(0, 0), &dxbdy0 = vgb(0, 1), &dxbdz0 = vgb(0, 2),
                &dxbdx2 = vgb(0, 3), &dxbdy2 = vgb(0, 4), &dxbdz2 = vgb(0, 5), &xb = vgb(0, 6);
  const double &dybdx0 = vgb(1, 0), &dybdy0 = vgb(1, 1), &dybdz0 = vgb(1, 2),
                &dybdx2 = vgb(1, 3), &dybdy2 = vgb(1, 4), &dybdz2 = vgb(1, 5), &yb = vgb(1, 6);
  const double &dzbdx0 = vgb(2, 0), &dzbdy0 = vgb(2, 1), &dzbdz0 = vgb(2, 2),
                &dzbdx2 = vgb(2, 3), &dzbdy2 = vgb(2, 4), &dzbdz2 = vgb(2, 5), &zb = vgb(2, 6);

  const double xn = ya*zb - za*yb;
  const double dxndx0 = ya*dzbdx0 + dyadx0*zb - yb*dzadx0 - dybdx0*za;
  const double dxndy0 = ya*dzbdy0 + dyady0*zb - yb*dzady0 - dybdy0*za;
  const double dxndz0 = ya*dzbdz0 + dyadz0*zb - yb*dzadz0 - dybdz0*za;
  const double dxndx1 = dyadx1*zb - yb*dzadx1;
  const double dxndy1 = dyady1*zb - yb*dzady1;
  const double dxndz1 = dyadz1*zb - yb*dzadz1;
  const double dxndx2 = ya*dzbdx2 - dybdx2*za;
  const double dxndy2 = ya*dzbdy2 - dybdy2*za;
  const double dxndz2 = ya*dzbdz2 - dybdz2*za;

  const double yn = za*xb - xa*zb;
  const double dyndx0 = -xa*dzbdx0 - dxadx0*zb + xb*dzadx0 + dxbdx0*za;
  const double dyndy0 = -xa*dzbdy0 - dxady0*zb + xb*dzady0 + dxbdy0*za;
  const double dyndz0 = -xa*dzbdz0 - dxadz0*zb + xb*dzadz0 + dxbdz0*za;
  const double dyndx1 = xb*dzadx1 - dxadx1*zb;
  const double dyndy1 = xb*dzady1 - dxady1*zb;
  const double dyndz1 = xb*dzadz1 - dxadz1*zb;
  const double dyndx2 = dxbdx2*za - xa*dzbdx2;
  const double dyndy2 = dxbdy2*za - xa*dzbdy2;
  const double dyndz2 = dxbdz2*za - xa*dzbdz2;

  const double zn = xa*yb - xb*ya;
  const double dzndx0 = xa*dybdx0 + dxadx0*yb - xb*dyadx0 - dxbdx0*ya;
  const double dzndy0 = xa*dybdy0 + dxady0*yb - xb*dyady0 - dxbdy0*ya;
  const double dzndz0 = xa*dybdz0 + dxadz0*yb - xb*dyadz0 - dxbdz0*ya;
  const double dzndx1 = dxadx1*yb - xb*dyadx1;
  const double dzndy1 = dxady1*yb - xb*dyady1;
  const double dzndz1 = dxadz1*yb - xb*dyadz1;
  const double dzndx2 = xa*dybdx2 - dxbdx2*ya;
  const double dzndy2 = xa*dybdy2 - dxbdy2*ya;
  const double dzndz2 = xa*dybdz2 - dxbdz2*ya;

  double &dNCJdx0 = res(0), &dNCJdy0 = res(1), &dNCJdz0 = res(2),
          &dNCJdx1 = res(3), &dNCJdy1 = res(4), &dNCJdz1 = res(5),
          &dNCJdx2 = res(6), &dNCJdy2 = res(7), &dNCJdz2 = res(8), &NCJ = res(9);

  const double n = sqrt(xn*xn + yn*yn + zn*zn), invN = 1./n, fact2 = fact*invN;
  dNCJdx0 = (dxndx0*xn + dyndx0*yn + dzndx0*zn) * fact2;
  dNCJdy0 = (dxndy0*xn + dyndy0*yn + dzndy0*zn) * fact2;
  dNCJdz0 = (dxndz0*xn + dyndz0*yn + dzndz0*zn) * fact2;
  dNCJdx1 = (dxndx1*xn + dyndx1*yn + dzndx1*zn) * fact2;
  dNCJdy1 = (dxndy1*xn + dyndy1*yn + dzndy1*zn) * fact2;
  dNCJdz1 = (dxndz1*xn + dyndz1*yn + dzndz1*zn) * fact2;
  dNCJdx2 = (dxndx2*xn + dyndx2*yn + dzndx2*zn) * fact2;
  dNCJdy2 = (dxndy2*xn + dyndy2*yn + dzndy2*zn) * fact2;
  dNCJdz2 = (dxndz2*xn + dyndz2*yn + dzndz2*zn) * fact2;
  NCJ = fact * n;
}


inline void revertVG(const fullMatrix<double> &vg, fullMatrix<double> &res)
{
  res(0, 0) = -vg(0, 3); res(0, 1) = -vg(0, 4); res(0, 2) = -vg(0, 5); res(0, 6) = -vg(0, 6);
  res(1, 0) = -vg(1, 3); res(1, 1) = -vg(1, 4); res(1, 2) = -vg(1, 5); res(1, 6) = -vg(1, 6);
  res(2, 0) = -vg(2, 3); res(2, 1) = -vg(2, 4); res(2, 2) = -vg(2, 5); res(2, 6) = -vg(2, 6);
}


}


void measuresTriangle::getNCJ(const double &x0, const double &y0, const double &z0,
                              const double &x1, const double &y1, const double &z1,
                              const double &x2, const double &y2, const double &z2,
                              fullVector<double> &ncj)
{
  // Compute unit vectors for each edge
  double x01n, y01n, z01n, x12n, y12n, z12n, x20n, y20n, z20n;
  unitVec(x0, y0, z0, x1, y1, z1, x01n, y01n, z01n);
  unitVec(x1, y1, z1, x2, y2, z2, x12n, y12n, z12n);
  unitVec(x2, y2, z2, x0, y0, z0, x20n, y20n, z20n);

  // Compute NCJ at vertex from unit vectors a and b as 0.5*||a^b||/A_equilateral
  // Factor = 2./sqrt(3.) = 0.5/A_equilateral
  static const double fact = 1.1547005383792517;
  ncj(0) = triArea(fact, x01n, y01n, z01n, -x20n, -y20n, -z20n);
  ncj(1) = triArea(fact, x12n, y12n, z12n, -x01n, -y01n, -z01n);
  ncj(2) = triArea(fact, x20n, y20n, z20n, -x12n, -y12n, -z12n);
}


void measuresTriangle::getNCJAndGradients(const double &x0, const double &y0, const double &z0,
                                          const double &x1, const double &y1, const double &z1,
                                          const double &x2, const double &y2, const double &z2,
                                          fullMatrix<double> &res)
{
  // Factor = 2./sqrt(3.) = 0.5/A_equilateral
  static const double fact = 1.1547005383792517;

  // Compute unit vector and its gradients for each edge
  fullMatrix<double> vg01(3,7);
  unitVecAndGrad(x0, y0, z0, x1, y1, z1, vg01);
  fullMatrix<double> vg12(3,7);
  unitVecAndGrad(x1, y1, z1, x2, y2, z2, vg12);
  fullMatrix<double> vg20(3,7);
  unitVecAndGrad(x2, y2, z2, x0, y0, z0, vg20);
  fullMatrix<double> vg10(3,7);
  revertVG(vg01, vg10);
  fullMatrix<double> vg21(3,7);
  revertVG(vg12, vg21);
  fullMatrix<double> vg02(3,7);
  revertVG(vg20, vg02);

  // Compute NCJ at vertex 0 as 0.5*||u01^u02||/A_triEqui
  // and gradients w.r.t. x0, y0, z0, x1, y1, z1, x2, y2, z2
  fullVector<double> res0(10);
  triAreaAndGrad(fact, vg01, vg02, res0);
  res(0, 0) = res0(0); res(0, 1) = res0(1); res(0, 2) = res0(2);
  res(0, 3) = res0(3); res(0, 4) = res0(4); res(0, 5) = res0(5);
  res(0, 6) = res0(6); res(0, 7) = res0(7); res(0, 8) = res0(8);
  res(0, 9) = res0(9);

  // Compute NCJ at vertex 1 as 0.5*||u12^u10||/A_triEqui
  // and gradients w.r.t. x1, y1, z1, x2, y2, z2, x0, y0, z0
  fullVector<double> res1(10);
  triAreaAndGrad(fact, vg12, vg10, res1);
  res(1, 0) = res1(6); res(1, 1) = res1(7); res(1, 2) = res1(8);
  res(1, 3) = res1(0); res(1, 4) = res1(1); res(1, 5) = res1(2);
  res(1, 6) = res1(3); res(1, 7) = res1(4); res(1, 8) = res1(5);
  res(1, 9) = res1(9);

  // Compute NCJ at vertex 2 as 0.5*||u20^u21||/A_triEqui
  // Compute NCJ at vertex 2 and gradients w.r.t. x2, y2, z2, x0, y0, z0, x1, y1, z1
  fullVector<double> res2(10);
  triAreaAndGrad(fact, vg20, vg21, res2);
  res(2, 0) = res2(3); res(2, 1) = res2(4); res(2, 2) = res2(5);
  res(2, 3) = res2(6); res(2, 4) = res2(7); res(2, 5) = res2(8);
  res(2, 6) = res2(0); res(2, 7) = res2(1); res(2, 8) = res2(2);
  res(2, 9) = res2(9);
}


void measuresQuadrangle::getNCJ(const double &x0, const double &y0, const double &z0,
                                const double &x1, const double &y1, const double &z1,
                                const double &x2, const double &y2, const double &z2,
                                const double &x3, const double &y3, const double &z3,
                                fullVector<double> &ncj)
{
  // Compute unit vectors for each edge
  double x01n, y01n, z01n, x12n, y12n, z12n, x23n, y23n, z23n, x30n, y30n, z30n;
  unitVec(x0, y0, z0, x1, y1, z1, x01n, y01n, z01n);
  unitVec(x1, y1, z1, x2, y2, z2, x12n, y12n, z12n);
  unitVec(x2, y2, z2, x3, y3, z3, x23n, y23n, z23n);
  unitVec(x3, y3, z3, x0, y0, z0, x30n, y30n, z30n);

  // Compute NCJ at vertex from unit vectors a and b as 0.5*||a^b||/A_triRect
  // Factor = 1. = 0.5/A_triRect
  static const double fact = 1.;
  ncj(0) = triArea(fact, x01n, y01n, z01n, -x30n, -y30n, -z30n);
  ncj(1) = triArea(fact, x12n, y12n, z12n, -x01n, -y01n, -z01n);
  ncj(2) = triArea(fact, x23n, y23n, z23n, -x12n, -y12n, -z12n);
  ncj(3) = triArea(fact, x30n, y30n, z30n, -x23n, -y23n, -z23n);
}


void measuresQuadrangle::getNCJAndGradients(const double &x0, const double &y0, const double &z0,
                                            const double &x1, const double &y1, const double &z1,
                                            const double &x2, const double &y2, const double &z2,
                                            const double &x3, const double &y3, const double &z3,
                                            fullMatrix<double> &res)
{
  // Factor = 1. = 0.5/A_triRect
  static const double fact = 1.;

  // Compute unit vector and its gradients for each edge
  fullMatrix<double> vg01(3,7);
  unitVecAndGrad(x0, y0, z0, x1, y1, z1, vg01);
  fullMatrix<double> vg12(3,7);
  unitVecAndGrad(x1, y1, z1, x2, y2, z2, vg12);
  fullMatrix<double> vg23(3,7);
  unitVecAndGrad(x2, y2, z2, x3, y3, z3, vg23);
  fullMatrix<double> vg30(3,7);
  unitVecAndGrad(x3, y3, z3, x0, y0, z0, vg30);
  fullMatrix<double> vg10(3,7);
  revertVG(vg01, vg10);
  fullMatrix<double> vg21(3,7);
  revertVG(vg12, vg21);
  fullMatrix<double> vg32(3,7);
  revertVG(vg23, vg32);
  fullMatrix<double> vg03(3,7);
  revertVG(vg30, vg03);

  // Compute NCJ at vertex 0 as 0.5*||u01^u03||/A_triRect
  // and gradients w.r.t. x0, y0, z0, x1, y1, z1, x3, y3, z3
  fullVector<double> res0(10);
  triAreaAndGrad(fact, vg01, vg03, res0);
  res(0, 0) = res0(0); res(0, 1) =  res0(1); res(0, 2) =  res0(2);
  res(0, 3) = res0(3); res(0, 4) =  res0(4); res(0, 5) =  res0(5);
  res(0, 6) =      0.; res(0, 7) =       0.; res(0, 8) =       0.;
  res(0, 9) = res0(6); res(0, 10) = res0(7); res(0, 11) = res0(8);
  res(0, 12) = res0(9);

  // Compute NCJ at vertex 1 as 0.5*||u12^u10||/A_triRect
  // and gradients w.r.t. x1, y1, z1, x2, y2, z2, x0, y0, z0
  fullVector<double> res1(10);
  triAreaAndGrad(fact, vg12, vg10, res1);
  res(1, 0) = res1(6); res(1, 1) = res1(7); res(1, 2) = res1(8);
  res(1, 3) = res1(0); res(1, 4) = res1(1); res(1, 5) = res1(2);
  res(1, 6) = res1(3); res(1, 7) = res1(4); res(1, 8) = res1(5);
  res(1, 9) =      0.; res(1, 10) =     0.; res(1, 11) =     0.;
  res(1, 12) = res1(9);

  // Compute NCJ at vertex 2 as 0.5*||u23^u21||/A_triRect
  // and gradients w.r.t. x2, y2, z2, x3, y3, z3, x1, y1, z1
  fullVector<double> res2(10);
  triAreaAndGrad(fact, vg23, vg21, res2);
  res(2, 0) =      0.; res(2, 1) =       0.; res(2, 2) =       0.;
  res(2, 3) = res2(6); res(2, 4) =  res2(7); res(2, 5) =  res2(8);
  res(2, 6) = res2(0); res(2, 7) =  res2(1); res(2, 8) =  res2(2);
  res(2, 9) = res2(3); res(2, 10) = res2(4); res(2, 11) = res2(5);
  res(2, 12) = res2(9);

  // Compute NCJ at vertex 3 as 0.5*||u30^u32||/A_triRect
  // and gradients w.r.t. x3, y3, z3, x0, y0, z0, x2, y2, z2
  fullVector<double> res3(10);
  triAreaAndGrad(fact, vg23, vg21, res3);
  res(3, 0) = res3(3); res(3, 1) =  res3(4); res(3, 2) =  res3(5);
  res(3, 3) =      0.; res(3, 4) =       0.; res(3, 5) =       0.;
  res(3, 6) = res3(6); res(3, 7) =  res3(7); res(3, 8) =  res3(8);
  res(3, 9) = res3(0); res(3, 10) = res3(1); res(3, 11) = res3(2);
  res(3, 12) = res3(9);
}
