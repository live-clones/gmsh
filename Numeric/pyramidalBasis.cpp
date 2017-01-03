// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <cmath>
#include <algorithm>
#include "pyramidalBasis.h"
#include "pointsGenerators.h"

pyramidalBasis::pyramidalBasis(int tag) : nodalBasis(tag), bergot(0)
{
  if (serendip) {
    Msg::Warning("Serendipity pyramid not implemented yet");
    return;
  }

  bergot = new BergotBasis(order);

  int num_points = points.size1();

  bergotCoefficients.resize(num_points, num_points);
  double *fval = new double[num_points];

  // Invert the Vandermonde matrix
  fullMatrix<double> VDM(num_points, num_points);
  for (int j = 0; j < num_points; j++) {
    bergot->f(points(j,0), points(j,1), points(j, 2), fval);
    for (int i = 0; i < num_points; i++) VDM(i,j) = fval[i];
  }
  VDM.invert(bergotCoefficients);

  coefficients.resize(num_points,num_points);
  monomials.resize(num_points,3);

  int idx = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {
      for (int k=0;k<=order-std::max(i,j);k++,idx++) {
        monomials(idx,0) = i;
        monomials(idx,1) = j;
        monomials(idx,2) = k;

        for (int l=0;l<num_points;l++) {
          double oneMinW = std::max(1e-14,1-points(l,2));
          VDM(idx,l)  = std::pow(points(l,0),i);
          VDM(idx,l) *= std::pow(points(l,1),j);
          VDM(idx,l) *= std::pow(points(l,2),k);
          VDM(idx,l) *= std::pow(oneMinW,std::max(i,j)-i-j);
        }
      }
    }
  }
  VDM.invert(coefficients);

  delete[] fval;
}

pyramidalBasis::~pyramidalBasis()
{
  if(bergot) delete bergot;
}

int pyramidalBasis::getNumShapeFunctions() const { return points.size1(); }

void pyramidalBasis::f(double u, double v, double w, double *val) const
{
  if(!bergot) return;

  const int N = bergot->size();

  double *fval = new double[N];
  bergot->f(u, v, w, fval);

  for (int i = 0; i < N; i++) {
    val[i] = 0.;
    for (int j = 0; j < N; j++) val[i] += bergotCoefficients(i,j)*fval[j];
  }

  delete[] fval;
}

void pyramidalBasis::f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const
{
  if(!bergot) return;

  const int N = bergot->size(), NPts = coord.size1();

  sf.resize(NPts, N);
  double *fval = new double[N];

  for (int iPt=0; iPt<NPts; iPt++) {
    bergot->f(coord(iPt,0), coord(iPt,1), coord(iPt,2), fval);
    for (int i = 0; i < N; i++) {
      sf(iPt,i) = 0.;
      for (int j = 0; j < N; j++) sf(iPt,i) += bergotCoefficients(i,j)*fval[j];
    }
  }

  delete[] fval;
}

void pyramidalBasis::df(double u, double v, double w, double grads[][3]) const
{
  if(!bergot) return;

  const int N = bergot->size();

  double (*dfval)[3] = new double[N][3];
  bergot->df(u, v, w, dfval);

  for (int i = 0; i < N; i++) {
    grads[i][0] = 0.; grads[i][1] = 0.; grads[i][2] = 0.;
    for (int j = 0; j < N; j++) {
      grads[i][0] += bergotCoefficients(i,j)*dfval[j][0];
      grads[i][1] += bergotCoefficients(i,j)*dfval[j][1];
      grads[i][2] += bergotCoefficients(i,j)*dfval[j][2];
    }
  }

  delete[] dfval;
}

void pyramidalBasis::df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const
{
  if(!bergot) return;

  const int N = bergot->size(), NPts = coord.size1();

  double (*dfv)[3] = new double[N][3];
  dfm.resize (N, 3*NPts, false);

  for (int iPt=0; iPt<NPts; iPt++) {
    df(coord(iPt,0), coord(iPt,1), coord(iPt,2), dfv);
    for (int i = 0; i < N; i++) {
      dfm(i, 3*iPt) = dfv[i][0];
      dfm(i, 3*iPt+1) = dfv[i][1];
      dfm(i, 3*iPt+2) = dfv[i][2];
    }
  }

  delete[] dfv;
}
