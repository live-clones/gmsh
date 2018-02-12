// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Amaury Johnen
//

//#include <stdlib.h>
//#include <cmath>
//#include "GmshDefines.h"
//#include "GmshMessage.h"
#include "incompleteBasis.h"
//#include "GaussIntegration.h"
//#include "pointsGenerators.h"
//#include <limits>
#include "BasisFactory.h"
#include "ElementType.h"
#include "polynomialBasis.h"

namespace {
  fullMatrix<double> generateLagrangeMonomialCoefficients
    (const fullMatrix<double>& monomial, const fullMatrix<double>& point)
  {
    if(monomial.size1() != point.size1() || monomial.size2() != point.size2()){
      Msg::Fatal("Wrong sizes for Lagrange coefficients generation %d %d -- %d %d",
           monomial.size1(), point.size1(),
           monomial.size2(), point.size2() );
      return fullMatrix<double>(1, 1);
    }

    int ndofs = monomial.size1();
    int dim = monomial.size2();

    fullMatrix<double> Vandermonde(ndofs, ndofs);
    for (int i = 0; i < ndofs; i++) {
      for (int j = 0; j < ndofs; j++) {
        double dd = 1.;
        for (int k = 0; k < dim; k++) dd *= pow_int(point(j, k), monomial(i, k));
        Vandermonde(i, j) = dd;
      }
    }

    fullMatrix<double> coefficient(ndofs, ndofs);
    Vandermonde.invert(coefficient);

    return coefficient;
  }

  /*
  void printClosure(incompleteBasis::clCont &fullClosure,
                           std::vector<int> &closureRef,
                           incompleteBasis::clCont &closures)
  {
    for (unsigned int i = 0; i < closures.size(); i++) {
      printf("%3i  (%2i): ", i, closureRef[i]);
      if(closureRef[i]==-1){
        printf("\n");
        continue;
      }
      for (unsigned int j = 0; j < fullClosure[i].size(); j++) {
        printf("%2i ", fullClosure[i][j]);
      }
      printf ("  --  ");
      for (unsigned int j = 0; j < closures[closureRef[i]].size(); j++) {
        std::string equalSign = "-";
        if (fullClosure[i][closures[closureRef[i]][j]] != closures[i][j])
          equalSign = "#";
        printf("%2i%s%2i ", fullClosure[i][closures[closureRef[i]][j]],equalSign.c_str(),
               closures[i][j]);
      }
      printf("\n");
    }
  }
  */
}

incompleteBasis::incompleteBasis(int tag)
    : nodalBasis(ElementType::getTag(ElementType::ParentTypeFromTag(tag),
                                     ElementType::OrderFromTag(tag), true)),
      polyBasis(NULL), completeBasis(NULL)
  // If the element is complete, compute the incomplete basis anyway
{
  int tagComplete = ElementType::getTag(parentType, order, false);
  switch (parentType) {
    case TYPE_PNT:
      polyBasis = new polynomialBasis(type);
      break;
    case TYPE_LIN:
      completeBasis = BasisFactory::getNodalBasis(tagComplete);
      break;
    case TYPE_TRI:
      completeBasis = BasisFactory::getNodalBasis(tagComplete);
      break;
    case TYPE_QUA:
      polyBasis = new polynomialBasis(type);
      break;
    case TYPE_TET:
      completeBasis = BasisFactory::getNodalBasis(tagComplete);
      break;
    case TYPE_PRI:
      completeBasis = BasisFactory::getNodalBasis(tagComplete);
      break;
    case TYPE_HEX:
      polyBasis = new polynomialBasis(type);
      break;
  }
}

incompleteBasis::~incompleteBasis()
{
  delete polyBasis;
}

void incompleteBasis::evaluateMonomials(double u, double v, double w, double p[]) const
{
  for (int j = 0; j < monomials.size1(); ++j) {
    p[j] = 1.;
    switch (dimension) {
    case 3 : p[j] *= pow_int(w, monomials(j, 2));
    case 2 : p[j] *= pow_int(v, monomials(j, 1));
    case 1 : p[j] *= pow_int(u, monomials(j, 0));
    default :
      break;
    }
  }
}

void incompleteBasis::f(double u, double v, double w, double *sf) const
{
  if (polyBasis) polyBasis->f(u, v, w, sf);
  else {
    double csf[1331];
    completeBasis->f(u, v, w, csf);
    int szInc = getNumShapeFunctions();
    for (int i = 0; i < szInc; ++i) {
      sf[i] = csf[i];
      for (int j = 0; j < coefficients.size1(); ++j) {
        sf[i] += csf[szInc+j] * coefficients(j, i);
      }
    }
  }
}

void incompleteBasis::f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const
{
  if (polyBasis) polyBasis->f(coord, sf);
  else {
    completeBasis->f(coord, sf);
    int szInc = getNumShapeFunctions();
    for (int k = 0; k < sf.size1(); ++k) {
      for (int i = 0; i < szInc; ++i) {
        for (int j = 0; j < coefficients.size1(); ++j) {
          sf(k, i) += sf(k, szInc+j) * coefficients(j, i);
        }
      }
    }
    sf.resize(sf.size1(), szInc);
  }
}

void incompleteBasis::df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const
{
  if (polyBasis) polyBasis->df(coord, dfm);
  else {
    completeBasis->df(coord, sf);
    int szInc = getNumShapeFunctions();
    for (int k = 0; k < sf.size1(); ++k) {
      for (int i = 0; i < szInc; ++i) {
        for (int j = 0; j < coefficients.size1(); ++j) {
          sf(k, i) += sf(k, szInc+j) * coefficients(j, i);
        }
      }
    }
    sf.resize(sf.size1(), szInc);
  }
}

void incompleteBasis::df(double u, double v, double w, double grads[][3]) const
{
  if (polyBasis) polyBasis->df(u, v, w, sf);
  else {
    double cgrads[1331][3];
    completeBasis->df(u, v, w, cgrads);
    int szInc = getNumShapeFunctions();
    for (int i = 0; i < szInc; ++i) {
      grads[i][0] = cgrads[i][0];
      grads[i][1] = cgrads[i][1];
      grads[i][2] = cgrads[i][2];
      for (int j = 0; j < coefficients.size1(); ++j) {
        grads[i][0] = cgrads[szInc+j][0] * coefficients(j, i);
        grads[i][1] = cgrads[szInc+j][1] * coefficients(j, i);
        grads[i][2] = cgrads[szInc+j][2] * coefficients(j, i);
      }
    }
  }
}

void incompleteBasis::ddf(double u, double v, double w, double hess[][3][3]) const
{
  if (polyBasis) polyBasis->ddf(u, v, w, sf);
  else {
    double chess[1331][3][3];
    completeBasis->df(u, v, w, chess);
    int szInc = getNumShapeFunctions();
    for (int i = 0; i < szInc; ++i) {
      for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
          hess[i][k][l] = chess[i][k][l];
        }
      }
      for (int j = 0; j < coefficients.size1(); ++j) {
        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            hess[i][k][l] = chess[szInc+j][k][l] * coefficients(j, i);
          }
        }
      }
    }
  }
}

void incompleteBasis::dddf(double u, double v, double w, double third[][3][3][3]) const
{
  if (polyBasis) polyBasis->dddf(u, v, w, sf);
  else {
    double cthird[1331][3][3];
    completeBasis->df(u, v, w, cthird);
    int szInc = getNumShapeFunctions();
    for (int i = 0; i < szInc; ++i) {
      for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
          for (int m = 0; m < 3; ++m) {
            third[i][k][l][m] = cthird[i][k][l][m];
          }
        }
      }
      for (int j = 0; j < coefficients.size1(); ++j) {
        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            for (int m = 0; m < 3; ++m) {
              third[i][k][l][m] =
                  cthird[szInc + j][k][l][m] * coefficients(j, i);
            }
          }
        }
      }
    }
  }
}
