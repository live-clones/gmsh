#include "jacobiPolynomials.h"

inline double Pochhammer(double x,int n) {
  double result(1.);
  for (int i=0;i<n;i++) result *= (x+i);
  return result;
}


JacobiPolynomials::JacobiPolynomials(double a, double b, int o):
  alpha(a),beta(b),n(o),alphaPlusBeta(a+b),a2MinusB2(a*a-b*b) {}
JacobiPolynomials::~JacobiPolynomials() {;}

void JacobiPolynomials::f(double u, double *val) const {

  val[0] = 1.;
  if (n>=1) val[1] = 0.5*(2.*(alpha+1.) + (alphaPlusBeta + 2.)*(u-1.));
  
  for (int i=1;i<n;i++) {
    
    double ii = (double) i;
    double twoI = 2.*ii;
    
    double a1i = 2.*(ii+1.)*(ii+alphaPlusBeta+1.)*(twoI+alphaPlusBeta);
    double a2i = (twoI+alphaPlusBeta+1.)*(a2MinusB2);
    double a3i = Pochhammer(twoI+alphaPlusBeta,3);
    double a4i = 2.*(ii+alpha)*(ii+beta)*(twoI+alphaPlusBeta+2.);
    
    val[i+1] = ((a2i + a3i * u)* val[i] - a4i * val[i-1])/a1i;
    
  }

}

void JacobiPolynomials::f(fullMatrix<double> &coord, fullMatrix<double> &val) const {}

void JacobiPolynomials::df(double u, double *val) const {

  double tmp[n+1];
  f(u,tmp);
  
  val[0] = 0;
  if (n>=1) val[1] = 0.5*(alphaPlusBeta + 2.);

  for (int i=2;i<=n;i++) {
    double ii = (double) i;
    double aa = (2.*ii + alphaPlusBeta);
    double g2 = aa*(1.-u*u);
    double g1 = ii*(alpha - beta - aa*u);
    double g0 = 2.*(ii+alpha)*(ii+beta);
  
    val[i] = (g1 * tmp[i] + g0 * tmp[i-1])/g2;
  }
}

void JacobiPolynomials::df(fullMatrix<double> &coord, fullMatrix<double> &val) const {}
