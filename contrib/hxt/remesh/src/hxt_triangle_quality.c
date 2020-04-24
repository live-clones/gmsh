#include "predicates.h"
#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"
#include <math.h>

static inline void prodve(double a[3], double b[3], double c[3])
{
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

static inline double norm3(double a[3])
{
  return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

static inline double norme(double a[3])
{
  const double mod = norm3(a);
  if(mod != 0.0) {
    const double one_over_mod = 1. / mod;
    a[0] *= one_over_mod;
    a[1] *= one_over_mod;
    a[2] *= one_over_mod;
  }
  return mod;
}

static void _Bez2Lag (double *xa, double *xb, double *xab, double *xabL){
  double xmidab[2] = {0.5*(xa[0]+xb[0]),0.5*(xa[1]+xb[1])};
  xabL[0] = 0.5*(xab[0] + xmidab[0]);
  xabL[1] = 0.5*(xab[1] + xmidab[1]);  
}


static void _derivativeP2 (double u, double v, double dfdu[6], double dfdv[6]){

  dfdu[0] = -3 +   4*v   + 4*u;
  dfdu[1] = -1           + 4*u;
  dfdu[2] =  0                ;
  dfdu[3] =  4    -4*v   - 8*u;
  dfdu[4] =        4*v        ;
  dfdu[5] =       -4*v ;

  dfdv[0] = -3 +   4*u   + 4*v;
  dfdv[1] =  0                ;
  dfdv[2] = -1           + 4*v;
  dfdv[3] =       -4*u        ;
  dfdv[4] =        4*u        ;
  dfdv[5] =  4    -4*u   - 8*v;

  
}


static void _jac_corners_p2 (double *xa, double *xb, double *xc, double *xab, double *xbc, double *xca, double J[6])
{
  double *x[6] = {xa, xb, xc, xab, xbc, xca};
  double nodes[6][2] = { {0, 0}, {1, 0}, {0, 1}, {0.5, 0}, {0.5, 0.5}, {0, 0.5} };
  for (int i=0; i<6; i++){
    double u = nodes[i][0];
    double v = nodes[i][1];
    double dfdu[6],dfdv[6];
    _derivativeP2 (u, v, dfdu, dfdv);
    double dxdu = 0, dxdv = 0, dydu=0, dydv=0;
    for (int j=0; j<6; j++){
      dxdu += x[j][0] * dfdu[j];
      dxdv += x[j][0] * dfdv[j];
      dydu += x[j][1] * dfdu[j];
      dydv += x[j][1] * dfdv[j];
    }
    J[i] = dxdu * dydv - dydu * dxdv;      
  }
}

static double _interpolateTriangle2 (double xi, double eta, double v0, double v1, double v2, double v3, double v4, double v5)
{
  double L0 = (1-xi-eta)*(1-2*xi-2*eta);
  double L1 = xi*(2*xi-1);
  double L2 = eta*(2*eta-1);
  double L3 = 4*xi*(1-xi-eta);
  double L4 = 4*xi*eta;
  double L5 = 4*eta*(1-xi-eta);

  return L0*v0+L1*v1+L2*v2+L3*v3+L4*v4+L5*v5;
}

static double _squareLength3D (double * xa, double *xb) {
  const double dx = xb[0] - xa[0];
  const double dy = xb[1] - xa[1];
  const double dz = xb[2] - xa[2];
  return (dx*dx+dy*dy+dz*dz);
}

// VISIBLE FUNCTIONS 



void hxtJacBoundsP2PlanarTriangle (double *xa, double *xb, double *xc, double *xabB, double *xbcB, double *xcaB, double bounds[2])
{
  double J[6],xab[2],xbc[2],xca[2];
  _Bez2Lag (xa, xb, xabB, xab);
  _Bez2Lag (xb, xc, xbcB, xbc);
  _Bez2Lag (xc, xa, xcaB, xca);
  _jac_corners_p2 (xa, xb, xc, xab, xbc, xca, J);
  double bez[6] = {J[0],J[1],J[2], 2*J[3] - 0.5*(J[0]+J[1]) , 2*J[4] - 0.5*(J[1]+J[2]) , 2*J[5] - 0.5*(J[0]+J[2])};
  double _MIN =  1.e22;
  double _MAX = -1.e22;
  for (int i=0;i<6;i++)_MIN = bez[i] < _MIN ? bez[i] : _MIN;
  for (int i=0;i<6;i++)_MAX = bez[i] > _MAX ? bez[i] : _MAX;
  bounds[0] = _MIN;
  bounds[1] = _MAX;
}

double  hxtAreaP1PlanarTriangle  (double *xa, double *xb, double *xc) {
  return orient2d (xa,xb,xc);   
}

double  hxtQualityMetricP2PlanarTriangle (double *xa, double *xb, double *xc, double *xabB, double *xbcB, double *xcaB,
					  void (*metric)(double *x, void *data, double *m), void *data ) {
  double xab[3];
  double xbc[3];
  double xca[3];

  double l2 = xabB[3]*xabB[3] + xbcB[3]*xbcB[3] + xcaB[3]*xcaB[3];

  _Bez2Lag (xa, xb, xabB, xab);
  _Bez2Lag (xb, xc, xbcB, xbc);
  _Bez2Lag (xc, xa, xcaB, xca);
  
  double M_sum = 0.;

  double xis[6] =  {0,1,0,0.5, 0.5, 0  };
  double etas[6] = {0,0,1,0. , 0.5, 0.5};
  double ws[6]   = {1./12. , 1./12., 1./12.,1./12. , 1./12., 1./12.};
  double J[6];
  _jac_corners_p2 (xa, xb, xc, xab, xbc, xca, J);
  //double js[3]   = {J[3], J[4], J[5]};
  
  for(uint32_t j=0; j<6; j++){
    double xi = xis[j];
    double eta = etas[j];
    double w = ws[j] * J[j];
    double x[3] = { _interpolateTriangle2 (xi, eta, xa[0], xb[0], xc[0], xab[0], xbc[0], xca[0]),
                    _interpolateTriangle2 (xi, eta, xa[1], xb[1], xc[1], xab[1], xbc[1], xca[1]),
                    _interpolateTriangle2 (xi, eta, xa[2], xb[2], xc[2], xab[2], xbc[2], xca[2]) };
    double M[3] = {0, 0, 0};
    metric (x, data, M);
    //    printf("j %d M_sum = %g det %g \n",j,M_sum,M[0]*M[1] - M[2]*M[2]);
    M_sum += sqrt( M[0]*M[1] - M[2]*M[2] ) * w;
 }
  return (12*M_sum  / l2 / sqrt(3));
}


double  hxtQualityMetricP1lanarTriangle  (double *xa, double *xb, double *xc, void (*metric)(double *x, void *data, double *m), void *data)
{
  double Ma[3]={1,1,0},Mb[3]={1,1,0},Mc[3]={1,1,0};

  metric (xa, data, Ma);
  metric (xb, data, Mb);
  metric (xc, data, Mc);

  double area = fabs(orient2d (xa,xb,xc));
    
  double deta = sqrt(Ma[0]*Ma[1]-Ma[2]*Ma[2]);
  double detb = sqrt(Mb[0]*Mb[1]-Mb[2]*Mb[2]);
  double detc = sqrt(Mc[0]*Mc[1]-Mc[2]*Mc[2]);

  double d1[2] = {xb[0] - xa[0], xb[1] - xa[1]};
  double d2[2] = {xc[0] - xb[0], xc[1] - xb[1]};
  double d3[2] = {xa[0] - xc[0], xa[1] - xc[1]};

  double tmp1 = d1[0]*d1[0]+d2[0]*d2[0]+d3[0]*d3[0];
  double tmp2 = d1[1]*d1[1]+d2[1]*d2[1]+d3[1]*d3[1];
  double tmp3 = 2*(d1[0]*d1[1]+d2[0]*d2[1]+d3[0]*d3[1]);
  
  double l2a = (tmp1 * Ma[0] + tmp2 * Ma[1]  + tmp3 * Ma[2]);
  double l2b = (tmp1 * Mb[0] + tmp2 * Mb[1]  + tmp3 * Mb[2]);
  double l2c = (tmp1 * Mc[0] + tmp2 * Mc[1]  + tmp3 * Mc[2]);

  double qa = area*deta/ l2a;
  double qb = area*detb/ l2b;
  double qc = area*detc/ l2c;
  
  if (qa < qb && qa < qc)return qa;
  if (qb < qc)return qb;
  return qc;  
}

// functions that can be used in 3D
double  hxtValidityP1Triangle            (double *xa, double *xb, double *xc, double *n)
{
  double xd[3] = {xa[0] + n[0] , xa[1] + n[1] , xa[2] + n[2] };
  return orient3d (xa,xb,xc,xd);
}

double hxtQualityP1Triangle             (double *xa, double *xb, double *xc) {

  const double A =  hxtTriangleArea3D (xa,xb,xc);
  const double L2 = _squareLength3D (xa,xb) +
    _squareLength3D (xa,xc)+ _squareLength3D (xc,xb);
  
  return (12*A  / L2 / sqrt(3));
  
}

// Triangle abc
// quality is between 0 and 1
double hxtGammaTriangleQuality(double *xa, double *xb, double *xc)
{
  // quality = rho / R = 2 * inscribed radius / circumradius
  double a[3] = {xc[0] - xb[0], xc[1] - xb[1], xc[2] - xc[2]};
  double b[3] = {xa[0] - xc[0], xa[1] - xc[1], xa[2] - xc[2]};
  double c[3] = {xb[0] - xa[0], xb[1] - xa[1], xb[2] - xa[2]};
  norme(a);
  norme(b);
  norme(c);
  double pva[3];
  prodve(b, c, pva);
  const double sina = norm3(pva);
  double pvb[3];
  prodve(c, a, pvb);
  const double sinb = norm3(pvb);
  double pvc[3];
  prodve(a, b, pvc);
  const double sinc = norm3(pvc);

  if(sina == 0.0 && sinb == 0.0 && sinc == 0.0)
    return 0.0;
  else
    return 2 * (2 * sina * sinb * sinc / (sina + sinb + sinc));
}



double hxtRightAngledQualitySimple(double *xa, double *xb, double *xc)
{
  double uv[2];
  double cc[3];
  HXT_CHECK(hxtCircumCenterXYZ(xa,xb,xc,cc,uv));
  
  double min = 10e12;
  double *xi, *xj, mid[3];
  for (uint32_t j=0; j<3; j++){
    if (j==0){ xi = xa; xj = xb;} 
    if (j==1){ xi = xb; xj = xc;} 
    if (j==2){ xi = xc; xj = xa;} 
    mid[0] = (xi[0]+xj[0])/2.;
    mid[1] = (xi[1]+xj[1])/2.;
    mid[2] = (xi[2]+xj[2])/2.;
    double dist = distance(mid,cc);
    if (dist < min) min = dist;
  }
  double quality = 1-sqrt(min);

  return quality;
}


