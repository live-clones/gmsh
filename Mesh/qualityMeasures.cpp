// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "qualityMeasures.h"
#include "BDS.h"
#include "MVertex.h"
#include "MElement.h"
#include "Numeric.h"
#include "FunctionSpace.h"
#include "GmshMessage.h"

double qmTriangle(const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3, 
                  const gmshQualityMeasure4Triangle &cr)
{
  return qmTriangle(p1->X, p1->Y, p1->Z, p2->X, p2->Y, p2->Z, p3->X, p3->Y, p3->Z, cr);
}

double qmTriangle(BDS_Face *t, const gmshQualityMeasure4Triangle &cr)
{
  BDS_Point *n[4];
  t->getNodes(n);
  return qmTriangle(n[0], n[1], n[2], cr);
}

double qmTriangle(MTriangle*t, const gmshQualityMeasure4Triangle &cr)
{
  return qmTriangle(t->getVertex(0), t->getVertex(1), t->getVertex(2), cr);
}

double qmTriangle(const MVertex *v1, const MVertex *v2, const MVertex *v3, 
                  const gmshQualityMeasure4Triangle &cr)
{
  return qmTriangle(v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(),
                    v3->x(), v3->y(), v3->z(), cr);
}

// Triangle abc
// quality is between 0 and 1

double qmTriangle(const double &xa, const double &ya, const double &za, 
                  const double &xb, const double &yb, const double &zb, 
                  const double &xc, const double &yc, const double &zc, 
                  const gmshQualityMeasure4Triangle &cr)
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
      double a [3] = {xc - xa, yc - ya, zc - za};
      double b [3] = {xb - xa, yb - ya, zb - za};
      double c [3] ; prodve(a, b, c); norme(c);
      double A[3][3] = {{a[0] , b[0] , c[0]} ,
                        {a[1] , b[1] , c[1]} ,
                        {a[2] , b[2] , c[2]}};
      quality = -1;
    }
    break;
  default:
    Msg::Error("Unknown quality measure");
    return 0.;
  }  

  return quality;
}

double qmTet(MTetrahedron *t, const gmshQualityMeasure4Tet &cr, double *volume)
{
  return qmTet(t->getVertex(0), t->getVertex(1), t->getVertex(2), t->getVertex(3),
               cr, volume);
}

double qmTet(const MVertex *v1, const MVertex *v2, const MVertex *v3,
             const MVertex *v4, const gmshQualityMeasure4Tet &cr, double *volume)
{
  return qmTet(v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(), 
               v3->x(), v3->y(), v3->z(), v4->x(), v4->y(), v4->z(), cr, volume);
}

double qmTet(const double &x1, const double &y1, const double &z1, 
             const double &x2, const double &y2, const double &z2, 
             const double &x3, const double &y3, const double &z3, 
             const double &x4, const double &y4, const double &z4, 
             const gmshQualityMeasure4Tet &cr, double *volume)
{
  double quality;
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
  default:
    Msg::Error("Unknown quality measure");
    return 0.;
  }
}


double mesh_functional_distorsion(MTriangle *t, double u, double v)
{
  // compute uncurved element jacobian d_u x and d_v x
  double mat[3][3];  
  double d1 = t->getPrimaryJacobian(u,v,0,mat);
  
   //double d1 = t->getJacobian(u,v,0,mat);
  double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal1[3];
  prodve(v1, v2, normal1);
  double nn = sqrt(normal1[0]*normal1[0] + 
  		   normal1[1]*normal1[1] + 
  		   normal1[2]*normal1[2]);
  
  // compute uncurved element jacobian d_u x and d_v x
  
  double d2 = t->getJacobian(u, v, 0, mat);
  
  double v1b[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2b[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal[3];
  prodve(v1b, v2b, normal);
  
  double sign;
  prosca(normal1, normal, &sign);
  double det = norm3(normal) * (sign > 0 ? 1. : -1.) / nn;  

  // compute distorsion
  double dist = std::min(1. / det, det); 
  return dist;
}


double qmDistorsionOfMapping (MTriangle *e)
{
  //  return 1.0;
  if (e->getPolynomialOrder() == 1)return 1.0;
  IntPt *pts;
  int npts;
  e->getIntegrationPoints(e->getPolynomialOrder(),&npts, &pts);
  double dmin;
  for (int i=0;i<npts;i++){
    const double u = pts[i].pt[0];
    const double v = pts[i].pt[1];
    const double w = pts[i].pt[2];
    const double di  = mesh_functional_distorsion (e,u,v);
    dmin = (i==0)? di : std::min(dmin,di);
  }
  const Double_Matrix& points = e->getFunctionSpace()->points;

  for (int i=0;i<e->getNumPrimaryVertices();i++) {
    const double u = points(i,0);
    const double v = points(i,1);
    const double di  = mesh_functional_distorsion (e,u,v);
    dmin = std::min(dmin,di);
  }
  return dmin;
}

static double mesh_functional_distorsion(MTetrahedron *t, double u, double v, double w)
{
  // compute uncurved element jacobian d_u x and d_v x
  double mat[3][3];  
  t->getPrimaryJacobian(u,v,w, mat);
  
  const double det1 = det3x3(mat);

   //const double det1 = t->getJacobian(u,v,w,mat);
  // const double det1 = det3x3(mat);
  t->getJacobian(u,v,w,mat);
  const double detN = det3x3(mat);
  // const double detN = det3x3(mat);

  //  printf("%g %g %g = %g %g\n",u,v,w,det1,detN);

  if (det1 == 0 || detN == 0) return 0;
  double dist = std::min(detN/det1, det1/detN); 
  return dist;
}


double qmDistorsionOfMapping (MTetrahedron *e)
{
  if (e->getPolynomialOrder() == 1)return 1.0;
  IntPt *pts;
  int npts;
  e->getIntegrationPoints(e->getPolynomialOrder(),&npts, &pts);
  double dmin;
  for (int i=0;i<npts;i++){
    const double u = pts[i].pt[0];
    const double v = pts[i].pt[1];
    const double w = pts[i].pt[2];
    const double di  = mesh_functional_distorsion (e,u,v,w);
    dmin = (i==0)? di : std::min(dmin,di);
  }
  
  const Double_Matrix& points = e->getFunctionSpace()->points;

  for (int i=0;i<e->getNumPrimaryVertices();i++) {
    const double u = points(i,0);
    const double v = points(i,1);
    const double w = points(i,2);
    const double di  = mesh_functional_distorsion (e,u,v,w);
    dmin = std::min(dmin,di);
  }
  //  printf("DMIN = %g\n\n",dmin);

  return dmin< 0 ? 0 :dmin;
}
