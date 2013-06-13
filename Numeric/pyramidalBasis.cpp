// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include <cmath>


static void copy(const fullMatrix<int> &orig, fullMatrix<double> &b)
{
  b.resize(orig.size1(), orig.size2());
  for (int i = 0; i < orig.size1(); ++i) {
    for (int j = 0; j < orig.size2(); ++j) {
      b(i, j) = static_cast<double>(orig(i, j));
    }
  }
}

static fullMatrix<double> generateLagrangeMonomialCoefficientsPyr
  (const fullMatrix<double>& monomial, const fullMatrix<double>& point)
{
  if(monomial.size1() != point.size1() || monomial.size2() != point.size2()){
    Msg::Fatal("Wrong sizes for Lagrange coefficients generation %d %d -- %d %d",
         monomial.size1(),point.size1(),
         monomial.size2(),point.size2() );
    return fullMatrix<double>(1, 1);
  }

  int ndofs = monomial.size1();
  int dim = monomial.size2();
  fullMatrix<double> ppoint(point.size1(), point.size2());

  for (int i = 0; i < ndofs; ++i) {
    ppoint(i, 2) = 1. - point(i, 2);
    if (ppoint(i, 2) != .0) {
      ppoint(i, 0) = point(i, 0) / ppoint(i, 2);
      ppoint(i, 1) = point(i, 1) / ppoint(i, 2);
    }
  }

  fullMatrix<double> Vandermonde(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      double dd = 1.;
      for (int k = 0; k < dim; k++) dd *= pow(ppoint(j, k), monomial(i, k));
      Vandermonde(i, j) = dd;
    }
  }

  fullMatrix<double> coefficient(ndofs, ndofs);
  Vandermonde.invert(coefficient);

  fullMatrix<double> unity(ndofs, ndofs);
  Vandermonde.mult(coefficient, unity);
  double max = .0;
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      if (i == j) unity(i, j) -= 1.;
      //Msg::Info("   unity(%d, %d) = %.3e", i, j, unity(i, j));
      max = std::max(max, std::abs(unity(i, j)));
    }
  }
  if (max > 1e-10) Msg::Info("mon   max unity = %.3e", max);

  return coefficient;
}

pyramidalBasis::pyramidalBasis(int tag) : nodalBasis(tag)
{

  bergot = new BergotBasis(order);

  int num_points = points.size1();

  VDMinv.resize(num_points, num_points);
  double *fval = new double[num_points];

  // Invert the Vandermonde matrix
  fullMatrix<double> VDM(num_points, num_points);
  for (int j = 0; j < num_points; j++) {
    bergot->f(points(j,0), points(j,1), points(j, 2), fval);
    for (int i = 0; i < num_points; i++) VDM(i,j) = fval[i];
  }
  VDM.invert(VDMinv);

  delete[] fval;


  fullMatrix<double> unity(num_points, num_points);
  VDM.mult(VDMinv, unity);
  double max = .0;
  for (int i = 0; i < num_points; i++) {
    for (int j = 0; j < num_points; j++) {
      if (i == j) unity(i, j) -= 1.;
      //Msg::Info("   unity(%d, %d) = %.3e", i, j, unity(i, j));
      max = std::max(max, std::abs(unity(i, j)));
    }
  }
  if (max > 1e-10) Msg::Info("leg   max unity = %.3e", max);


  // TEST NEW ALGO POINTS / MONOMIAL

  monomials_newAlgo = gmshGenerateMonomialsPyramid(order, serendip);
  copy(monomials_newAlgo, points_newAlgo);
  if (order == 0) return;

  for (int i = 0; i < points_newAlgo.size1(); ++i) {
    points_newAlgo(i, 2) = points_newAlgo(i, 2) / order;
    if (i != 4) {
      const double duv = -1. + points_newAlgo(i, 2);
      points_newAlgo(i, 0) = duv + points_newAlgo(i, 0) * 2. / order;
      points_newAlgo(i, 1) = duv + points_newAlgo(i, 1) * 2. / order;
    }
  }

  fullMatrix<double> monDouble;
  copy(monomials_newAlgo, monDouble);
  coefficients_newAlgo = generateLagrangeMonomialCoefficientsPyr(monDouble, points_newAlgo);
}



pyramidalBasis::~pyramidalBasis()
{
  delete bergot;
}



int pyramidalBasis::getNumShapeFunctions() const { return points.size1(); }



void pyramidalBasis::f(double u, double v, double w, double *val) const
{

  const int N = bergot->size();

  double *fval = new double[N];
  bergot->f(u, v, w, fval);

  for (int i = 0; i < N; i++) {
    val[i] = 0.;
    for (int j = 0; j < N; j++) val[i] += VDMinv(i,j)*fval[j];
  }

  delete[] fval;

}
void pyramidalBasis::fnew(double u, double v, double w, double *sf) const
{
  double p[1256];
  evaluateMonomialsNew(u, v, w, p);
  for (int i = 0; i < coefficients_newAlgo.size1(); i++) {
    sf[i] = 0.0;
    for (int j = 0; j < coefficients_newAlgo.size2(); j++) {
      sf[i] += coefficients_newAlgo(i, j) * p[j];
    }
  }
}



void pyramidalBasis::f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const
{

  const int N = bergot->size(), NPts = coord.size1();

  sf.resize(NPts, N);
  double *fval = new double[N];

  for (int iPt=0; iPt<NPts; iPt++) {
    bergot->f(coord(iPt,0), coord(iPt,1), coord(iPt,2), fval);
    for (int i = 0; i < N; i++) {
      sf(iPt,i) = 0.;
      for (int j = 0; j < N; j++) sf(iPt,i) += VDMinv(i,j)*fval[j];
    }
  }

  delete[] fval;

}



void pyramidalBasis::df(double u, double v, double w, double grads[][3]) const
{

  const int N = bergot->size();

  double (*dfval)[3] = new double[N][3];
  bergot->df(u, v, w, dfval);

  for (int i = 0; i < N; i++) {
    grads[i][0] = 0.; grads[i][1] = 0.; grads[i][2] = 0.;
    for (int j = 0; j < N; j++) {
      grads[i][0] += VDMinv(i,j)*dfval[j][0];
      grads[i][1] += VDMinv(i,j)*dfval[j][1];
      grads[i][2] += VDMinv(i,j)*dfval[j][2];
    }
  }

  delete[] dfval;

}



void pyramidalBasis::df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const
{

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
