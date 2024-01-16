// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Koen Hillewaert
//   Jonathan Lambrechts
//

#include <stdlib.h>
#include <cmath>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "polynomialBasis.h"
#include "GaussIntegration.h"
#include "pointsGenerators.h"
#include "Numeric.h"
#include <limits>

namespace {
  fullMatrix<double>
  generateLagrangeMonomialCoefficients(const fullMatrix<double> &monomial,
                                       const fullMatrix<double> &point)
  {
    if(monomial.size1() != point.size1() || monomial.size2() != point.size2()) {
      Msg::Error(
        "Wrong sizes for Lagrange coefficients generation %d %d -- %d %d",
        monomial.size1(), point.size1(), monomial.size2(), point.size2());
      return fullMatrix<double>(1, 1);
    }

    int ndofs = monomial.size1();
    int dim = monomial.size2();

    fullMatrix<double> Vandermonde(ndofs, ndofs);
    for(int i = 0; i < ndofs; i++) {
      for(int j = 0; j < ndofs; j++) {
        double dd = 1.;
        for(int k = 0; k < dim; k++) dd *= pow_int(point(j, k), monomial(i, k));
        Vandermonde(i, j) = dd;
      }
    }

    fullMatrix<double> coefficient(ndofs, ndofs);
    Vandermonde.invert(coefficient);

    return coefficient;
  }

  /*
  void printClosure(polynomialBasis::clCont &fullClosure,
                           std::vector<int> &closureRef,
                           polynomialBasis::clCont &closures)
  {
    for(std::size_t i = 0; i < closures.size(); i++){
      printf("%3i  (%2i): ", i, closureRef[i]);
      if(closureRef[i]==-1){
        printf("\n");
        continue;
      }
      for(std::size_t j = 0; j < fullClosure[i].size(); j++){
        printf("%2i ", fullClosure[i][j]);
      }
      printf ("  --  ");
      for(std::size_t j = 0; j < closures[closureRef[i]].size(); j++){
        std::string equalSign = "-";
        if(fullClosure[i][closures[closureRef[i]][j]] != closures[i][j])
          equalSign = "#";
        printf("%2i%s%2i ",
  fullClosure[i][closures[closureRef[i]][j]],equalSign.c_str(), closures[i][j]);
      }
      printf("\n");
    }
  }
  */
} // namespace

polynomialBasis::polynomialBasis(int tag) : nodalBasis(tag)
{
  switch(parentType) {
  case TYPE_PNT: monomials = gmshGenerateMonomialsLine(0); break;
  case TYPE_LIN: monomials = gmshGenerateMonomialsLine(order); break;
  case TYPE_TRI:
    monomials = gmshGenerateMonomialsTriangle(order, serendip);
    break;
  case TYPE_QUA:
    monomials = serendip ? gmshGenerateMonomialsQuadSerendipity(order) :
                           gmshGenerateMonomialsQuadrangle(order);
    break;
  case TYPE_TET:
    monomials = gmshGenerateMonomialsTetrahedron(order, serendip);
    break;
  case TYPE_PRI:
    monomials = serendip ? gmshGenerateMonomialsPrismSerendipity(order) :
                           gmshGenerateMonomialsPrism(order);
    break;
  case TYPE_HEX:
    monomials = serendip ? gmshGenerateMonomialsHexaSerendipity(order) :
                           gmshGenerateMonomialsHexahedron(order);
    break;
  }

  coefficients = generateLagrangeMonomialCoefficients(monomials, points);
}

polynomialBasis::~polynomialBasis() {}

void polynomialBasis::evaluateMonomials(double u, double v, double w,
                                        double p[]) const
{
  for(int j = 0; j < monomials.size1(); ++j) {
    p[j] = 1.;
    switch(dimension) {
    case 3: p[j] *= pow_int(w, monomials(j, 2));
    case 2: p[j] *= pow_int(v, monomials(j, 1));
    case 1: p[j] *= pow_int(u, monomials(j, 0));
    default: break;
    }
  }
}

void polynomialBasis::f(double u, double v, double w, double *sf) const
{
  double p[1256];
  evaluateMonomials(u, v, w, p);
  for(int i = 0; i < coefficients.size1(); i++) {
    sf[i] = 0.0;
    for(int j = 0; j < coefficients.size2(); j++) {
      sf[i] += coefficients(i, j) * p[j];
    }
  }
}

void polynomialBasis::f(const fullMatrix<double> &coord,
                        fullMatrix<double> &sf) const
{
  double p[1256];
  sf.resize(coord.size1(), coefficients.size1());
  for(int iPoint = 0; iPoint < coord.size1(); iPoint++) {
    evaluateMonomials(coord(iPoint, 0),
                      coord.size2() > 1 ? coord(iPoint, 1) : 0,
                      coord.size2() > 2 ? coord(iPoint, 2) : 0, p);
    for(int i = 0; i < coefficients.size1(); i++) {
      sf(iPoint, i) = 0.;
      for(int j = 0; j < coefficients.size2(); j++)
        sf(iPoint, i) += coefficients(i, j) * p[j];
    }
  }
}

void polynomialBasis::f(double u, double v, double w, int i, double *sf) const
{
  if(i < 0 || i >= coefficients.size1()) {
    Msg::Error("Node out of range for polynomial basis");
    return;
  }

  double p[1256];
  evaluateMonomials(u, v, w, p);
  *sf = 0.0;
  for(int j = 0; j < coefficients.size2(); j++) {
    *sf += coefficients(i, j) * p[j];
  }
}

void polynomialBasis::df(const fullMatrix<double> &coord,
                         fullMatrix<double> &dfm) const
{
  double dfv[1256][3];
  dfm.resize(coord.size1() * 3, coefficients.size1(), false);
  int dimCoord = coord.size2();
  for(int iPoint = 0; iPoint < coord.size1(); iPoint++) {
    df(coord(iPoint, 0), dimCoord > 1 ? coord(iPoint, 1) : 0.,
       dimCoord > 2 ? coord(iPoint, 2) : 0., dfv);
    for(int i = 0; i < coefficients.size1(); i++) {
      dfm(iPoint * 3 + 0, i) = dfv[i][0];
      dfm(iPoint * 3 + 1, i) = dfv[i][1];
      dfm(iPoint * 3 + 2, i) = dfv[i][2];
    }
  }
}

void polynomialBasis::df(double u, double v, double w, double grads[][3]) const
{
  switch(monomials.size2()) {
  case 1:
    for(int i = 0; i < coefficients.size1(); i++) {
      grads[i][0] = 0;
      grads[i][1] = 0;
      grads[i][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 0)
          grads[i][0] += coefficients(i, j) *
                         pow_int(u, (monomials(j, 0) - 1)) * monomials(j, 0);
      }
    }
    break;
  case 2:
    for(int i = 0; i < coefficients.size1(); i++) {
      grads[i][0] = 0;
      grads[i][1] = 0;
      grads[i][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 0)
          grads[i][0] += coefficients(i, j) *
                         pow_int(u, (monomials(j, 0) - 1)) * monomials(j, 0) *
                         pow_int(v, monomials(j, 1));
        if(monomials(j, 1) > 0)
          grads[i][1] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                         pow_int(v, (monomials(j, 1) - 1)) * monomials(j, 1);
      }
    }
    break;
  case 3:
    for(int i = 0; i < coefficients.size1(); i++) {
      grads[i][0] = 0;
      grads[i][1] = 0;
      grads[i][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 0)
          grads[i][0] += coefficients(i, j) *
                         pow_int(u, (monomials(j, 0) - 1)) * monomials(j, 0) *
                         pow_int(v, monomials(j, 1)) *
                         pow_int(w, monomials(j, 2));
        if(monomials(j, 1) > 0)
          grads[i][1] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                         pow_int(v, (monomials(j, 1) - 1)) * monomials(j, 1) *
                         pow_int(w, monomials(j, 2));
        if(monomials(j, 2) > 0)
          grads[i][2] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                         pow_int(v, monomials(j, 1)) *
                         pow_int(w, (monomials(j, 2) - 1)) * monomials(j, 2);
      }
    }
    break;
  }
}

void polynomialBasis::df(double u, double v, double w, int i,
                         double grad[3]) const
{
  if(i < 0 || i >= coefficients.size1()) {
    Msg::Error("Node out of range for polynomial basis gradient");
    return;
  }

  switch(monomials.size2()) {
  case 1:
    grad[0] = 0;
    grad[1] = 0;
    grad[2] = 0;
    for(int j = 0; j < coefficients.size2(); j++) {
      if(monomials(j, 0) > 0)
        grad[0] += coefficients(i, j) * pow_int(u, (monomials(j, 0) - 1)) *
                   monomials(j, 0);
    }
    break;
  case 2:
    grad[0] = 0;
    grad[1] = 0;
    grad[2] = 0;
    for(int j = 0; j < coefficients.size2(); j++) {
      if(monomials(j, 0) > 0)
        grad[0] += coefficients(i, j) * pow_int(u, (monomials(j, 0) - 1)) *
                   monomials(j, 0) * pow_int(v, monomials(j, 1));
      if(monomials(j, 1) > 0)
        grad[1] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                   pow_int(v, (monomials(j, 1) - 1)) * monomials(j, 1);
    }
    break;
  case 3:
    grad[0] = 0;
    grad[1] = 0;
    grad[2] = 0;
    for(int j = 0; j < coefficients.size2(); j++) {
      if(monomials(j, 0) > 0)
        grad[0] += coefficients(i, j) * pow_int(u, (monomials(j, 0) - 1)) *
                   monomials(j, 0) * pow_int(v, monomials(j, 1)) *
                   pow_int(w, monomials(j, 2));
      if(monomials(j, 1) > 0)
        grad[1] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                   pow_int(v, (monomials(j, 1) - 1)) * monomials(j, 1) *
                   pow_int(w, monomials(j, 2));
      if(monomials(j, 2) > 0)
        grad[2] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                   pow_int(v, monomials(j, 1)) *
                   pow_int(w, (monomials(j, 2) - 1)) * monomials(j, 2);
    }
    break;
  }
}

void polynomialBasis::ddf(double u, double v, double w,
                          double hess[][3][3]) const
{
  switch(monomials.size2()) {
  case 1:
    for(int i = 0; i < coefficients.size1(); i++) {
      hess[i][0][0] = hess[i][0][1] = hess[i][0][2] = 0;
      hess[i][1][0] = hess[i][1][1] = hess[i][1][2] = 0;
      hess[i][2][0] = hess[i][2][1] = hess[i][2][2] = 0;

      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 1) // second derivative !=0
          hess[i][0][0] += coefficients(i, j) *
                           pow_int(u, (monomials(j, 0) - 2)) * monomials(j, 0) *
                           (monomials(j, 0) - 1);
      }
    }
    break;
  case 2:
    for(int i = 0; i < coefficients.size1(); i++) {
      hess[i][0][0] = hess[i][0][1] = hess[i][0][2] = 0;
      hess[i][1][0] = hess[i][1][1] = hess[i][1][2] = 0;
      hess[i][2][0] = hess[i][2][1] = hess[i][2][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 1) // second derivative !=0
          hess[i][0][0] += coefficients(i, j) *
                           pow_int(u, (monomials(j, 0) - 2)) * monomials(j, 0) *
                           (monomials(j, 0) - 1) * pow_int(v, monomials(j, 1));
        if((monomials(j, 1) > 0) && (monomials(j, 0) > 0))
          hess[i][0][1] += coefficients(i, j) *
                           pow_int(u, monomials(j, 0) - 1) * monomials(j, 0) *
                           pow_int(v, monomials(j, 1) - 1) * monomials(j, 1);
        if(monomials(j, 1) > 1)
          hess[i][1][1] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                           pow_int(v, monomials(j, 1) - 2) * monomials(j, 1) *
                           (monomials(j, 1) - 1);
      }
      hess[i][1][0] = hess[i][0][1];
    }
    break;
  case 3:
    for(int i = 0; i < coefficients.size1(); i++) {
      hess[i][0][0] = hess[i][0][1] = hess[i][0][2] = 0;
      hess[i][1][0] = hess[i][1][1] = hess[i][1][2] = 0;
      hess[i][2][0] = hess[i][2][1] = hess[i][2][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 1)
          hess[i][0][0] += coefficients(i, j) *
                           pow_int(u, monomials(j, 0) - 2) * monomials(j, 0) *
                           (monomials(j, 0) - 1) * pow_int(v, monomials(j, 1)) *
                           pow_int(w, monomials(j, 2));

        if((monomials(j, 0) > 0) && (monomials(j, 1) > 0))
          hess[i][0][1] += coefficients(i, j) *
                           pow_int(u, monomials(j, 0) - 1) * monomials(j, 0) *
                           pow_int(v, monomials(j, 1) - 1) * monomials(j, 1) *
                           pow_int(w, monomials(j, 2));
        if((monomials(j, 0) > 0) && (monomials(j, 2) > 0))
          hess[i][0][2] += coefficients(i, j) *
                           pow_int(u, monomials(j, 0) - 1) * monomials(j, 0) *
                           pow_int(v, monomials(j, 1)) *
                           pow_int(w, monomials(j, 2) - 1) * monomials(j, 2);
        if(monomials(j, 1) > 1)
          hess[i][1][1] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                           pow_int(v, monomials(j, 1) - 2) * monomials(j, 1) *
                           (monomials(j, 1) - 1) * pow_int(w, monomials(j, 2));
        if((monomials(j, 1) > 0) && (monomials(j, 2) > 0))
          hess[i][1][2] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                           pow_int(v, monomials(j, 1) - 1) * monomials(j, 1) *
                           pow_int(w, monomials(j, 2) - 1) * monomials(j, 2);
        if(monomials(j, 2) > 1)
          hess[i][2][2] += coefficients(i, j) * pow_int(u, monomials(j, 0)) *
                           pow_int(v, monomials(j, 1)) *
                           pow_int(w, monomials(j, 2) - 2) * monomials(j, 2) *
                           (monomials(j, 2) - 1);
      }
      hess[i][1][0] = hess[i][0][1];
      hess[i][2][0] = hess[i][0][2];
      hess[i][2][1] = hess[i][1][2];
    }
    break;
  }
}

void polynomialBasis::dddf(double u, double v, double w,
                           double third[][3][3][3]) const
{
  switch(monomials.size2()) {
  case 1:
    for(int i = 0; i < coefficients.size1(); i++) {
      for(int p = 0; p < 3; p++)
        for(int q = 0; q < 3; q++)
          for(int r = 0; r < 3; r++) third[i][p][q][r] = 0.;

      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 2) // third derivative !=0
          third[i][0][0][0] +=
            coefficients(i, j) * pow_int(u, (monomials(j, 0) - 3)) *
            monomials(j, 0) * (monomials(j, 0) - 1) * (monomials(j, 0) - 2);
      }
    }
    break;
  case 2:
    for(int i = 0; i < coefficients.size1(); i++) {
      for(int p = 0; p < 3; p++)
        for(int q = 0; q < 3; q++)
          for(int r = 0; r < 3; r++) third[i][p][q][r] = 0.;
      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 2) // second derivative !=0
          third[i][0][0][0] +=
            coefficients(i, j) * pow_int(u, (monomials(j, 0) - 3)) *
            monomials(j, 0) * (monomials(j, 0) - 1) * (monomials(j, 0) - 2) *
            pow_int(v, monomials(j, 1));
        if((monomials(j, 0) > 1) && (monomials(j, 1) > 0))
          third[i][0][0][1] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0) - 2) *
            monomials(j, 0) * (monomials(j, 0) - 1) *
            pow_int(v, monomials(j, 1) - 1) * monomials(j, 1);
        if((monomials(j, 0) > 0) && (monomials(j, 1) > 1))
          third[i][0][1][1] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0) - 1) *
            monomials(j, 0) * pow_int(v, monomials(j, 1) - 2) *
            monomials(j, 1) * (monomials(j, 1) - 1);
        if(monomials(j, 1) > 2)
          third[i][1][1][1] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0)) *
            pow_int(v, monomials(j, 1) - 3) * monomials(j, 1) *
            (monomials(j, 1) - 1) * (monomials(j, 1) - 2);
      }
      third[i][0][1][0] = third[i][0][0][1];
      third[i][1][0][0] = third[i][0][0][1];
      third[i][1][0][1] = third[i][0][1][1];
      third[i][1][1][0] = third[i][0][1][1];
    }
    break;
  case 3:
    for(int i = 0; i < coefficients.size1(); i++) {
      for(int p = 0; p < 3; p++)
        for(int q = 0; q < 3; q++)
          for(int r = 0; r < 3; r++) third[i][p][q][r] = 0.;
      for(int j = 0; j < coefficients.size2(); j++) {
        if(monomials(j, 0) > 2) // second derivative !=0
          third[i][0][0][0] +=
            coefficients(i, j) * pow_int(u, (monomials(j, 0) - 3)) *
            monomials(j, 0) * (monomials(j, 0) - 1) * (monomials(j, 0) - 2) *
            pow_int(v, monomials(j, 1)) * pow_int(w, monomials(j, 2));

        if((monomials(j, 0) > 1) && (monomials(j, 1) > 0))
          third[i][0][0][1] += coefficients(i, j) *
                               pow_int(u, monomials(j, 0) - 2) *
                               monomials(j, 0) * (monomials(j, 0) - 1) *
                               pow_int(v, monomials(j, 1) - 1) *
                               monomials(j, 1) * pow_int(w, monomials(j, 2));

        if((monomials(j, 0) > 1) && (monomials(j, 2) > 0))
          third[i][0][0][2] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0) - 2) *
            monomials(j, 0) * (monomials(j, 0) - 1) *
            pow_int(v, monomials(j, 1)) * pow_int(w, monomials(j, 2) - 1) *
            monomials(j, 2);

        if((monomials(j, 0) > 0) && (monomials(j, 1) > 1))
          third[i][0][1][1] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0) - 1) *
            monomials(j, 0) * pow_int(v, monomials(j, 1) - 2) *
            monomials(j, 1) * (monomials(j, 1) - 1) *
            pow_int(w, monomials(j, 2));

        if((monomials(j, 0) > 0) && (monomials(j, 1) > 0) &&
           (monomials(j, 2) > 0))
          third[i][0][1][2] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0) - 1) *
            monomials(j, 0) * pow_int(v, monomials(j, 1) - 1) *
            monomials(j, 1) * pow_int(w, monomials(j, 2) - 1) * monomials(j, 2);

        if((monomials(j, 0) > 0) && (monomials(j, 2) > 1))
          third[i][0][2][2] += coefficients(i, j) *
                               pow_int(u, monomials(j, 0) - 1) *
                               monomials(j, 0) * pow_int(v, monomials(j, 1)) *
                               pow_int(w, monomials(j, 2) - 2) *
                               monomials(j, 2) * (monomials(j, 2) - 1);
        if((monomials(j, 1) > 2))
          third[i][1][1][1] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0)) *
            pow_int(v, monomials(j, 1) - 3) * monomials(j, 1) *
            (monomials(j, 1) - 1) * (monomials(j, 1) - 2) *
            pow_int(w, monomials(j, 2));

        if((monomials(j, 1) > 1) && (monomials(j, 2) > 0))
          third[i][1][1][2] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0)) *
            pow_int(v, monomials(j, 1) - 2) * monomials(j, 1) *
            (monomials(j, 1) - 1) * pow_int(w, monomials(j, 2) - 1) *
            monomials(j, 2);

        if((monomials(j, 1) > 0) && (monomials(j, 2) > 1))
          third[i][1][2][2] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0)) *
            pow_int(v, monomials(j, 1) - 1) * monomials(j, 1) *
            pow_int(w, monomials(j, 2) - 2) * monomials(j, 2) *
            (monomials(j, 2) - 1);

        if((monomials(j, 2) > 2))
          third[i][2][2][2] +=
            coefficients(i, j) * pow_int(u, monomials(j, 0)) *
            pow_int(v, monomials(j, 1)) * pow_int(w, monomials(j, 2) - 3) *
            monomials(j, 2) * (monomials(j, 2) - 1) * (monomials(j, 2) - 2);
      }
      third[i][0][1][0] = third[i][0][0][1];
      third[i][1][0][0] = third[i][0][0][1];

      third[i][2][0][0] = third[i][0][0][2];
      third[i][0][2][0] = third[i][0][0][2];

      third[i][1][0][1] = third[i][0][1][1];
      third[i][1][1][0] = third[i][0][1][1];

      third[i][0][2][1] = third[i][0][1][2];
      third[i][1][0][2] = third[i][0][1][2];
      third[i][1][2][0] = third[i][0][1][2];
      third[i][2][1][0] = third[i][0][1][2];
      third[i][2][0][1] = third[i][0][1][2];

      third[i][2][2][0] = third[i][0][2][2];
      third[i][2][0][2] = third[i][0][2][2];

      third[i][1][2][1] = third[i][1][1][2];
      third[i][2][1][1] = third[i][1][1][2];

      third[i][2][2][1] = third[i][1][2][2];
      third[i][2][1][2] = third[i][1][2][2];
    }
    break;
  }
}
