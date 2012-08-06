// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
      *volume = inv3x3(S,INVS) * 2 / sqrt(2);
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

double mesh_functional_distorsion(MElement *t, double u, double v)
{
  // compute uncurved element jacobian d_u x and d_v x
  double mat[3][3];
  t->getPrimaryJacobian(u, v, 0, mat);
  // t->getJacobian(u,v,0,mat);
  double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal1[3];
  prodve(v1, v2, normal1);
  double nn = norm3(normal1);

  // compute uncurved element jacobian d_u x and d_v x

  t->getJacobian(u, v, 0, mat);
  double v1b[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2b[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal[3];
  prodve(v1b, v2b, normal);

  //  printf("%g %g %g -- %g %g %g - %g\n",mat[0][0], mat[0][1], mat[0][2],mat[1][0], mat[1][1], mat[1][2],nn);

  double sign = 1.0;
  prosca(normal1, normal, &sign);
  //  double det = (norm3(normal) / nn)  * (sign > 0 ? 1. : -1.);

  //  printf("%g %g : %g : %g n1 (%g,%g,%g)\n",u,v,sign,det, normal1[0], normal1[1], normal1[2]);
  //  for (int i=0;i<t->getNumVertices();i++){
  //    printf("COORD (%d) = %g %g %g\n",i,t->getVertex(i)->x(),t->getVertex(i)->y(),t->getVertex(i)->z());
  //  }
  //  printf("n (%g,%g,%g)\n", normal1[0], normal1[1], normal1[2]);

  return sign/(nn*nn);
}

static double MINQ (double a, double b, double c){
  if (a == 0) return std::min(a+b+c,c);
  double xmin = -b/(2*a);
  if (xmin < 0 || xmin > 1)return std::min(c,a+b+c);
  return std::min(c,std::min(a+b+c,a * xmin * xmin + b * xmin + c));
}


double mesh_functional_distorsion_p2_bezier_refined(MTriangle *t)
{
  double J1 =mesh_functional_distorsion(t,0.0,0.0);
  double J2 =mesh_functional_distorsion(t,1.0,0.0);
  double J3 =mesh_functional_distorsion(t,0.0,1.0);
  double J4 =mesh_functional_distorsion(t,0.5,0.0);
  double J5 =mesh_functional_distorsion(t,0.5,0.5);
  double J6 =mesh_functional_distorsion(t,0.0,0.5);

  double J36 =mesh_functional_distorsion(t,0.0,.75);
  double J35 =mesh_functional_distorsion(t,0.25,.75);
  double J56 =mesh_functional_distorsion(t,0.25,.5);

  double J16 =mesh_functional_distorsion(t,0.0,.25);
  double J14 =mesh_functional_distorsion(t,0.25,.0);
  double J46 =mesh_functional_distorsion(t,0.25,.25);


  double J45 =mesh_functional_distorsion(t,0.5,.25);
  double J52 =mesh_functional_distorsion(t,0.75,.25);
  double J24 =mesh_functional_distorsion(t,0.75,.0);

  double d[15] = {
    J1,J6,J4,2*J16-0.5*(J1+J6),2*J14-0.5*(J1+J4),2*J46-0.5*(J6+J4),
    J3,J5,2*J36-0.5*(J3+J6),2*J35-0.5*(J3+J5),2*J56-0.5*(J5+J6),
    J2,2*J45-0.5*(J4+J5),2*J52-0.5*(J5+J2),2*J24-0.5*(J2+J4)};
  return  *std::min_element(d,d+15);
}

double mesh_functional_distorsion_p2_exact(MTriangle *t)
{
  double J1 =mesh_functional_distorsion(t,0.0,0.0);
  double J2 =mesh_functional_distorsion(t,1.0,0.0);
  double J3 =mesh_functional_distorsion(t,0.0,1.0);
  double J4 =mesh_functional_distorsion(t,0.5,0.0);
  double J5 =mesh_functional_distorsion(t,0.5,0.5);
  double J6 =mesh_functional_distorsion(t,0.0,0.5);

  const double a = J1;
  const double b = -3*J1-J2+4*J4;
  const double c = -3*J1-J3+4*J6;
  const double d = 4*(J1-J4+J5-J6);
  const double e = 2*(J1+J2-2*J4);
  const double f = 2*(J1+J3-2*J6);

  double js[3] = {
    MINQ (2*(J1+J2-2*J4), -3*J1-J2+4*J4, J1),
    MINQ (2*(J1+J3-2*J6), -3*J1-J3+4*J6, J1),
    MINQ (2*(J3+J2-2*J5), -3*J2-J3+4*J5, J2)
  };
  double min_interm =  *std::min_element(js,js+3);

  double mat[2][2] = {{2*e,d},{d,2*f}};
  double x[2], rhs[2] = {-b,-c};

  if (!sys2x2(mat,rhs,x))return min_interm;

  const double ximin = x[0];
  const double etamin  = x[1];

  if (ximin> 0 && etamin > 0 && 1-ximin-etamin>0){
    const double m4 = a+b*ximin+c*etamin+d*ximin*etamin+
      e*ximin*ximin + f*etamin*etamin;
    /*
    if (m4 < min_interm && (m4 < .9 || m4 > 1.1)){
      printf("m4  = %g xi = %g eta  = %g min_interm = %g min_edges = %g %g %g\n",m4,ximin,etamin,min_interm, MINQ (e,b,a), MINQ (f,c,a), MINQ (-d+e+f,b-c+d-2*f,a+c+f));
      FILE *f = fopen ("t.pos","w");
      fprintf(f,"ST2(%g,%g,0,%g,%g,0,%g,%g,0,%g,%g,0,%g,%g,0,%g,%g,0){%g,%g,%g,%g,%g,%g}\n",
	      t->getVertex(0)->x(),t->getVertex(0)->y(),
	      t->getVertex(1)->x(),t->getVertex(1)->y(),
	      t->getVertex(2)->x(),t->getVertex(2)->y(),
	      t->getVertex(3)->x(),t->getVertex(3)->y(),
	      t->getVertex(4)->x(),t->getVertex(4)->y(),
	      t->getVertex(5)->x(),t->getVertex(5)->y(),
	    J1,J2,J3,J4,J5,J6);
      fclose(f);
      getchar();
    }
    */
    return std::min(m4, min_interm);
  }
  return min_interm;
}

double mesh_functional_distorsion_pN(MElement *t)
{
  const bezierBasis *jac = t->getJacobianFuncSpace()->bezier;
  fullVector<double>Ji(jac->points.size1());
  for (int i=0;i<jac->points.size1();i++){
    double u = jac->points(i,0);
    double v = jac->points(i,1);
    if (t->getType() == TYPE_QUA){
      u = -1 + 2*u;
      v = -1 + 2*v;
    }

    Ji(i) = mesh_functional_distorsion(t,u,v);
  }

  fullVector<double> Bi( jac->matrixLag2Bez.size1() );
  jac->matrixLag2Bez.mult(Ji,Bi);
  return *std::min_element(Bi.getDataPtr(),Bi.getDataPtr()+Bi.size());
}

double qmDistorsionOfMapping (MTriangle *e)
{
  //  return 1.0;
  if (e->getPolynomialOrder() == 1) return 1.0;
  else if  (e->getPolynomialOrder() == 2) {
    //    const double exact = mesh_functional_distorsion_p2_exact(e);
    const double bezier= mesh_functional_distorsion_pN(e);
    //    if (bezier < .1){
    //      const double bezier_refined= mesh_functional_distorsion_p2_bezier_refined(e);
    //      return bezier_refined;
    //    }
    /*
    if (exact < .99 || exact > 1.01){
      FILE *f = fopen ("statistics.dat","a");
      fprintf(f,"%12.5E %12.5E %12.5E\n",exact,bezier,bezier_refined);
      fclose(f);

      if (exact > 0 && bezier < 0){
	f = fopen ("t.pos","w");
	double J1 =mesh_functional_distorsion(e,0.0,0.0);
	double J2 =mesh_functional_distorsion(e,1.0,0.0);
	double J3 =mesh_functional_distorsion(e,0.0,1.0);
	double J4 =mesh_functional_distorsion(e,0.5,0.0);
	double J5 =mesh_functional_distorsion(e,0.5,0.5);
	double J6 =mesh_functional_distorsion(e,0.0,0.5);
	fprintf(f,"ST2(%g,%g,0,%g,%g,0,%g,%g,0,%g,%g,0,%g,%g,0,%g,%g,0){%g,%g,%g,%g,%g,%g}\n",
		e->getVertex(0)->x(),e->getVertex(0)->y(),
		e->getVertex(1)->x(),e->getVertex(1)->y(),
		e->getVertex(2)->x(),e->getVertex(2)->y(),
		e->getVertex(3)->x(),e->getVertex(3)->y(),
		e->getVertex(4)->x(),e->getVertex(4)->y(),
		e->getVertex(5)->x(),e->getVertex(5)->y(),
		J1,J2,J3,J4,J5,J6);
	fclose(f);
	getchar();
      }
    }
  */
    return bezier;
  }
  else return  mesh_functional_distorsion_pN(e);
}

double qmDistorsionOfMapping (MQuadrangle *e)
{
  //  return 1.0;
  if (e->getPolynomialOrder() == 1) return 1.0;
  else return mesh_functional_distorsion_pN(e);
}


static double mesh_functional_distorsion(MTetrahedron *t, double u, double v, double w)
{
  // compute uncurved element jacobian d_u x and d_v x
  double mat[3][3];
  t->getPrimaryJacobian(u, v, w, mat);
  const double det1 = det3x3(mat);
  t->getJacobian(u, v, w, mat);
  const double detN = det3x3(mat);
  if (det1 == 0 || detN == 0) return 0;
  double dist = det1 / detN;
  return dist;
}

double qmDistorsionOfMapping(MTetrahedron *t)
{
  const bezierBasis *jac = t->getJacobianFuncSpace()->bezier;
  fullVector<double>Ji(jac->points.size1());
  for (int i=0;i<jac->points.size1();i++){
    const double u = jac->points(i,0);
    const double v = jac->points(i,1);
    const double w = jac->points(i,2);
    Ji(i) = mesh_functional_distorsion(t,u,v,w);
  }

  fullVector<double> Bi( jac->matrixLag2Bez.size1() );
  jac->matrixLag2Bez.mult(Ji,Bi);
  /*
     jac->matrixLag2Bez.print("Lag2Bez");

      jac->points.print("Points");
      t->getFunctionSpace(t->getPolynomialOrder())->points.print("lagrangianNodes");
      t->getFunctionSpace(t->getPolynomialOrder())->monomials.print("Monomials");
      t->getFunctionSpace(t->getPolynomialOrder())->coefficients.print("Coefficients");
  */

  return *std::min_element(Bi.getDataPtr(),Bi.getDataPtr()+Bi.size());
}

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
  double rot[3][3];
  rot[0][0]=-1; rot[0][1]=1; rot[0][2]=0;
  rot[1][0]=-1; rot[1][1]=0; rot[1][2]=0;
  rot[2][0]= 0; rot[2][1]=0; rot[2][2]=1;
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

