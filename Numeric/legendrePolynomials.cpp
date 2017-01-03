// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "legendrePolynomials.h"



LegendrePolynomials::LegendrePolynomials(int o): n(o) {}



LegendrePolynomials::~LegendrePolynomials() {}



void LegendrePolynomials::f(double u, double *val) const
{
  val[0] = 1;

  for (int i=0;i<n;i++) {

    double a1i = i+1;
    double a3i = 2.*i+1;
    double a4i = i;

    val[i+1] = a3i * u * val[i];
    if (i>0) val[i+1] -= a4i * val[i-1];
    val[i+1] /= a1i;
  }
}



void LegendrePolynomials::df(double u, double *val) const
{

  // Indeterminate form for u == -1 and u == 1
  if ((u == 1.) || (u == -1.)) {

    for (int k=0;k<=n;k++) val[k] = 0.5*k*(k+1);
    if ((u == -1.) && (n >= 2)) for (int k=2;k<=n;k+=2) val[k] = -val[k];

    return;

  }

  // Now general case

  // Values of the Legendre polynomials
  std::vector<double> tmp(n+1);
  f(u,&(tmp[0]));

  // First value of the derivative
  val[0] = 0;
  double g2 = (1.-u*u);

  // Values of the derivative for orders > 1 computed from the values of the polynomials
  for (int i=1;i<=n;i++) {
    double g1 = - u*i;
    double g0 = (double) i;
    val[i] = (g1 * tmp[i] + g0 * tmp[i-1])/g2;
  }

}
