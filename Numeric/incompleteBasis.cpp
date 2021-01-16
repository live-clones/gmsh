// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Amaury Johnen
//

#include "incompleteBasis.h"
#include "BasisFactory.h"
#include "ElementType.h"

void incompleteBasis::_computeCoefficientsTriangle()
{
  if(order < 3) {
    coefficients.resize(0, 0);
    return;
  }

  int szInc = getNumShapeFunctions();
  int szComp = completeBasis->getNumShapeFunctions();
  coefficients.resize(szComp - szInc, szInc, true);

  std::map<std::pair<int, int>, int> coord2idx;
  for(int i = 0; i < szInc; ++i) {
    int u = static_cast<int>(points(i, 0) * order + .5);
    int v = static_cast<int>(points(i, 1) * order + .5);
    coord2idx[std::make_pair(u, v)] = i;
  }

  int &n = order;
  fullMatrix<double> pts = completeBasis->getReferenceNodes();
  for(int i = 0; i < szComp - szInc; ++i) {
    double xi = pts(szInc + i, 0);
    double eta = pts(szInc + i, 1);
    int u = static_cast<int>(xi * order + .5);
    int v = static_cast<int>(eta * order + .5);

    coefficients(i, coord2idx[std::make_pair(u + v, 0)]) = xi;
    coefficients(i, coord2idx[std::make_pair(n, 0)]) = -xi;
    coefficients(i, coord2idx[std::make_pair(n - v, v)]) = xi;
    coefficients(i, coord2idx[std::make_pair(u, n - u)]) = eta;
    coefficients(i, coord2idx[std::make_pair(0, n)]) = -eta;
    coefficients(i, coord2idx[std::make_pair(0, u + v)]) = eta;
    coefficients(i, coord2idx[std::make_pair(0, v)]) = 1 - xi - eta;
    coefficients(i, coord2idx[std::make_pair(0, 0)]) = -(1 - xi - eta);
    coefficients(i, coord2idx[std::make_pair(u, 0)]) = 1 - xi - eta;
  }

  coefficients.print("coefficients");
}

incompleteBasis::incompleteBasis(int tag)
  // If the element is complete, compute the incomplete basis anyway
  : nodalBasis(ElementType::getType(ElementType::getParentType(tag),
                                    ElementType::getOrder(tag), true)),
    completeBasis(nullptr), polyBasis(nullptr)
{
  int tagComplete = ElementType::getType(parentType, order, false);
  switch(parentType) {
  case TYPE_LIN:
  case TYPE_PNT:
  case TYPE_QUA:
  case TYPE_HEX: polyBasis = new polynomialBasis(type); break;
  case TYPE_TET:
  case TYPE_PRI:
  case TYPE_PYR:
    completeBasis = BasisFactory::getNodalBasis(tagComplete);
    break;
  case TYPE_TRI:
    completeBasis = BasisFactory::getNodalBasis(tagComplete);
    _computeCoefficientsTriangle();
    break;
  }
}

incompleteBasis::~incompleteBasis() { delete polyBasis; }

void incompleteBasis::f(double u, double v, double w, double *sf) const
{
  if(polyBasis)
    polyBasis->f(u, v, w, sf);
  else {
    double csf[1331];
    completeBasis->f(u, v, w, csf);
    int szInc = getNumShapeFunctions();
    for(int i = 0; i < szInc; ++i) {
      sf[i] = csf[i];
      for(int j = 0; j < coefficients.size1(); ++j) {
        sf[i] += csf[szInc + j] * coefficients(j, i);
      }
    }
  }
}

void incompleteBasis::f(const fullMatrix<double> &coord,
                        fullMatrix<double> &sf) const
{
  if(polyBasis)
    polyBasis->f(coord, sf);
  else {
    completeBasis->f(coord, sf);
    int szInc = getNumShapeFunctions();
    for(int k = 0; k < sf.size1(); ++k) {
      for(int i = 0; i < szInc; ++i) {
        for(int j = 0; j < coefficients.size1(); ++j) {
          sf(k, i) += sf(k, szInc + j) * coefficients(j, i);
        }
      }
    }
    sf.resize(sf.size1(), szInc, false);
  }
}

void incompleteBasis::df(const fullMatrix<double> &coord,
                         fullMatrix<double> &dfm) const
{
  if(polyBasis)
    polyBasis->df(coord, dfm);
  else {
    completeBasis->df(coord, dfm);
    int szInc = getNumShapeFunctions();
    for(int k = 0; k < dfm.size1(); ++k) {
      for(int i = 0; i < szInc; ++i) {
        for(int j = 0; j < coefficients.size1(); ++j) {
          dfm(k, i) += dfm(k, szInc + j) * coefficients(j, i);
        }
      }
    }
    dfm.resize(dfm.size1(), szInc, false);
  }
}

void incompleteBasis::df(double u, double v, double w, double grads[][3]) const
{
  if(polyBasis)
    polyBasis->df(u, v, w, grads);
  else {
    double cgrads[1331][3];
    completeBasis->df(u, v, w, cgrads);
    int szInc = getNumShapeFunctions();
    for(int i = 0; i < szInc; ++i) {
      grads[i][0] = cgrads[i][0];
      grads[i][1] = cgrads[i][1];
      grads[i][2] = cgrads[i][2];
      for(int j = 0; j < coefficients.size1(); ++j) {
        grads[i][0] = cgrads[szInc + j][0] * coefficients(j, i);
        grads[i][1] = cgrads[szInc + j][1] * coefficients(j, i);
        grads[i][2] = cgrads[szInc + j][2] * coefficients(j, i);
      }
    }
  }
}

void incompleteBasis::ddf(double u, double v, double w,
                          double hess[][3][3]) const
{
  if(polyBasis)
    polyBasis->ddf(u, v, w, hess);
  else {
    double chess[1331][3][3];
    completeBasis->ddf(u, v, w, chess);
    int szInc = getNumShapeFunctions();
    for(int i = 0; i < szInc; ++i) {
      for(int k = 0; k < 3; ++k) {
        for(int l = 0; l < 3; ++l) { hess[i][k][l] = chess[i][k][l]; }
      }
      for(int j = 0; j < coefficients.size1(); ++j) {
        for(int k = 0; k < 3; ++k) {
          for(int l = 0; l < 3; ++l) {
            hess[i][k][l] = chess[szInc + j][k][l] * coefficients(j, i);
          }
        }
      }
    }
  }
}

void incompleteBasis::dddf(double u, double v, double w,
                           double third[][3][3][3]) const
{
  if(polyBasis)
    polyBasis->dddf(u, v, w, third);
  else {
    double cthird[1331][3][3][3];
    completeBasis->dddf(u, v, w, cthird);
    int szInc = getNumShapeFunctions();
    for(int i = 0; i < szInc; ++i) {
      for(int k = 0; k < 3; ++k) {
        for(int l = 0; l < 3; ++l) {
          for(int m = 0; m < 3; ++m) { third[i][k][l][m] = cthird[i][k][l][m]; }
        }
      }
      for(int j = 0; j < coefficients.size1(); ++j) {
        for(int k = 0; k < 3; ++k) {
          for(int l = 0; l < 3; ++l) {
            for(int m = 0; m < 3; ++m) {
              third[i][k][l][m] =
                cthird[szInc + j][k][l][m] * coefficients(j, i);
            }
          }
        }
      }
    }
  }
}
