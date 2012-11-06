// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "pyramidalBasis.h"

pyramidalBasis::pyramidalBasis()
{

}

void pyramidalBasis::initialize()
{

  BergotBasis bb(order);
  bergot = bb;

  int n = order+1;
  int num_points = n*(n+1)*(2*n+1)/6;
  if (serendip and order > 2) {
    num_points -= (order-2)*((order-2)+1)*(2*(order-2)+1)/6;
  }

  VDMinv = new fullMatrix<double>(num_points, num_points);

  // Invert the Vandermonde matrix
  fullMatrix<double> VDM = fullMatrix<double>(num_points, num_points);
  for (int j = 0; j < num_points; j++) {
    double f[num_points];
    bergot.f(points(j,0), points(j,1), points(j, 2), f);
    for (int i = 0; i < num_points; i++) {
      VDM(i,j) = f[i];
    }
  }
  VDM.invert(*VDMinv);
}

inline void pyramidalBasis::f(double u, double v, double w, double *val) const
{
  int n = order+1;
  int num_points = n*(n+1)*(2*n+1)/6;

  double f[n*n*n];
  bergot.f(u,v,w, f);

  for (int i = 0; i < num_points; i++) {
    val[i] = 0.0;
    for (int j = 0; j < num_points; j++) {
      val[i] += (*VDMinv)(i,j)*f[j];
    }
  }
}

inline void pyramidalBasis::df(double u, double v, double w, double grads[][3]) const
{

}
