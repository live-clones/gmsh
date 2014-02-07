// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "pointsGenerators.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"


// Points Generators

fullMatrix<double> gmshGeneratePointsLine(int order)
{
  fullMatrix<double> points = gmshGenerateMonomialsLine(order);
  if (order == 0) return points;

  points.scale(2./order);
  points.add(-1.);
  return points;
}

fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsTriangle(order, serendip);
  if (order == 0) return points;

  points.scale(1./order);
  return points;
}

fullMatrix<double> gmshGeneratePointsQuadrangle(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsQuadrangle(order, serendip);

  if (order == 0) return points;

  points.scale(2./order);
  points.add(-1.);
  return points;
}

fullMatrix<double> gmshGeneratePointsTetrahedron(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsTetrahedron(order, serendip);

  if (order == 0) return points;

  points.scale(1./order);
  return points;
}

fullMatrix<double> gmshGeneratePointsHexahedron(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsHexahedron(order, serendip);

  if (order == 0) return points;

  points.scale(2./order);
  points.add(-1.);
  return points;
}

fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsPrism(order, serendip);

  if (order == 0) return points;

  fullMatrix<double> tmp;
  tmp.setAsProxy(points, 0, 2);
  tmp.scale(1./order);

  tmp.setAsProxy(points, 2, 1);
  tmp.scale(2./order);
  tmp.add(-1.);

  return points;
}

fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip)
{
  fullMatrix<double> points = gmshGenerateMonomialsPyramid(order, serendip);

  if (order == 0) return points;

  for (int i = 0; i < points.size1(); ++i) {
    points(i, 2) = points(i, 2) / order;
    const double duv = -1. + points(i, 2);
    points(i, 0) = duv + points(i, 0) * 2. / order;
    points(i, 1) = duv + points(i, 1) * 2. / order;
  }
  return points;
}

// Monomials Generators

fullMatrix<double> gmshGenerateMonomialsLine(int order, bool serendip)
{
  fullMatrix<double> monomials(order + 1, 1);
  monomials(0,0) = 0;
  if (order > 0) {
    monomials(1, 0) = order;
    for (int i = 2; i < order + 1; i++) monomials(i, 0) = i-1;
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsTriangle(int order, bool serendip)
{
  int nbMonomials = serendip ? 3 * order : (order + 1) * (order + 2) / 2;
  if (serendip && !order) nbMonomials = 1;
  fullMatrix<double> monomials(nbMonomials, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = order;

    if (order > 1) {
      int index = 3;
      for (int iedge = 0; iedge < 3; ++iedge) {
        int i0 = MTriangle::edges_tri(iedge, 0);
        int i1 = MTriangle::edges_tri(iedge, 1);

        int u_0 = (monomials(i1,0)-monomials(i0,0)) / order;
        int u_1 = (monomials(i1,1)-monomials(i0,1)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u_0 * i;
          monomials(index, 1) = monomials(i0, 1) + u_1 * i;
        }
      }
      if (!serendip && order > 2) {
        fullMatrix<double> inner = gmshGenerateMonomialsTriangle(order-3);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 2, index, 0);
      }
    }
  }
  return monomials;
}

fullMatrix<double> gmshGenerateMonomialsQuadrangle(int order, bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? order*4 : (order+1)*(order+1);
  if (forSerendipPoints && !order) nbMonomials = 1;
  fullMatrix<double> monomials(nbMonomials, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;

    monomials(2, 0) = order;
    monomials(2, 1) = order;

    monomials(3, 0) = 0;
    monomials(3, 1) = order;

    if (order > 1) {
      int index = 4;
      for (int iedge = 0; iedge < 4; ++iedge) {
        int i0 = MQuadrangle::edges_quad(iedge, 0);
        int i1 = MQuadrangle::edges_quad(iedge, 1);

        int u_0 = (monomials(i1,0)-monomials(i0,0)) / order;
        int u_1 = (monomials(i1,1)-monomials(i0,1)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u_0 * i;
          monomials(index, 1) = monomials(i0, 1) + u_1 * i;
        }
      }

      if (!forSerendipPoints) {
        fullMatrix<double> inner = gmshGenerateMonomialsQuadrangle(order-2);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 2, index, 0);
      }
    }
  }
  return monomials;
}

/*
