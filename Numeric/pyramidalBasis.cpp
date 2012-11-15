// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "pyramidalBasis.h"
#include "pointsGenerators.h"



pyramidalBasis::pyramidalBasis(int tag) : nodalBasis(tag)
{

  bergot = new BergotBasis(order);

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
    bergot->f(points(j,0), points(j,1), points(j, 2), f);
    for (int i = 0; i < num_points; i++) {
      VDM(i,j) = f[i];
    }
  }
  VDM.invert(*VDMinv);

}



pyramidalBasis::~pyramidalBasis()
{
  delete bergot;
}



inline void pyramidalBasis::f(double u, double v, double w, double *val) const
{

  const int N = bergot->size();

  double f[N];
  bergot->f(u, v, w, f);

  for (int i = 0; i < N; i++) {
    val[i] = 0.;
    for (int j = 0; j < N; j++) val[i] += (*VDMinv)(i,j)*f[j];
  }

}



inline void pyramidalBasis::f(fullMatrix<double> &coord, fullMatrix<double> &sf)
{

  const int N = bergot->size(), NPts = coord.size1();

  sf.resize(NPts, N);
  double f[N];
  fullVector<double> fVect(f,N);

  for (int iPt=0; iPt<NPts; iPt++) {
    bergot->f(coord(iPt,0), coord(iPt,0), coord(iPt,0), f);
    for (int i = 0; i < N; i++) {
      sf(iPt,i) = 0.;
      for (int j = 0; j < N; j++) sf(iPt,i) += (*VDMinv)(i,j)*f[j];
    }
  }

}



inline void pyramidalBasis::df(double u, double v, double w, double grads[][3]) const
{

  const int N = bergot->size();

  double df[N][3];
  bergot->df(u, v, w, df);

  for (int i = 0; i < N; i++) {
    grads[i][0] = 0.; grads[i][1] = 0.; grads[i][2] = 0.;
    for (int j = 0; j < N; j++) {
      grads[i][0] += (*VDMinv)(i,j)*df[j][0];
      grads[i][1] += (*VDMinv)(i,j)*df[j][1];
      grads[i][2] += (*VDMinv)(i,j)*df[j][2];
    }
  }

}



inline void pyramidalBasis::df(fullMatrix<double> &coord, fullMatrix<double> &dfm) const
{

  const int N = bergot->size(), NPts = coord.size1();

  double dfv[N][3];
  dfm.resize (NPts, 3*N, false);

  for (int iPt=0; iPt<NPts; iPt++) {
    df(coord(iPt,0), coord(iPt,1), coord(iPt,2), dfv);
    for (int i = 0; i < N; i++) {
      dfm(i, 3*iPt+0) = dfv[i][0];
      dfm(i, 3*iPt+1) = dfv[i][1];
      dfm(i, 3*iPt+2) = dfv[i][2];
    }
  }

}
