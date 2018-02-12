// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Amaury Johnen
//

#include "incompleteBasis.h"
#include "BasisFactory.h"
#include "ElementType.h"


incompleteBasis::incompleteBasis(int tag)
    : nodalBasis(ElementType::getTag(ElementType::ParentTypeFromTag(tag),
                                     ElementType::OrderFromTag(tag), true)),
      polyBasis(NULL), completeBasis(NULL)
  // If the element is complete, compute the incomplete basis anyway
{
  int tagComplete = ElementType::getTag(parentType, order, false);
  switch (parentType) {
    case TYPE_PNT:
    case TYPE_QUA:
    case TYPE_HEX:
      polyBasis = new polynomialBasis(type);
      break;
    case TYPE_LIN:
    case TYPE_TRI:
    case TYPE_TET:
    case TYPE_PRI:
      completeBasis = BasisFactory::getNodalBasis(tagComplete);
      break;
  }
}

incompleteBasis::~incompleteBasis()
{
  delete polyBasis;
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
    completeBasis->df(coord, dfm);
    int szInc = getNumShapeFunctions();
    for (int k = 0; k < dfm.size1(); ++k) {
      for (int i = 0; i < szInc; ++i) {
        for (int j = 0; j < coefficients.size1(); ++j) {
          dfm(k, i) += dfm(k, szInc+j) * coefficients(j, i);
        }
      }
    }
    dfm.resize(dfm.size1(), szInc);
  }
}

void incompleteBasis::df(double u, double v, double w, double grads[][3]) const
{
  if (polyBasis) polyBasis->df(u, v, w, grads);
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
  if (polyBasis) polyBasis->ddf(u, v, w, hess);
  else {
    double chess[1331][3][3];
    completeBasis->ddf(u, v, w, chess);
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
  if (polyBasis) polyBasis->dddf(u, v, w, third);
  else {
    double cthird[1331][3][3][3];
    completeBasis->dddf(u, v, w, cthird);
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
