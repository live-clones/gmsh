// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef POINTSGENERATORS_H
#define POINTSGENERATORS_H

#include "fullMatrix.h"

class FuncSpaceData;

// Functions to generate point distributions on the references elements, for all
// orders and functions generating exponents of Pascal monomials in the same
// order than Gmsh Points.

// Points

void gmshGeneratePoints(FuncSpaceData, fullMatrix<double> &);

fullMatrix<double> gmshGeneratePointsLine(int order);

fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip = false);
fullMatrix<double> gmshGeneratePointsQuadrangle(int order,
                                                bool serendip = false);

fullMatrix<double> gmshGeneratePointsTetrahedron(int order,
                                                 bool serendip = false);
fullMatrix<double> gmshGeneratePointsHexahedron(int order,
                                                bool serendip = false);
fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip = false);

fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip = false);
fullMatrix<double> gmshGeneratePointsPyramidGeneral(bool pyr, int nij, int nk,
                                                    bool serendip = false);

// Monomial exponents

void gmshGenerateMonomials(FuncSpaceData, fullMatrix<double> &);

fullMatrix<double> gmshGenerateMonomialsLine(int order, bool serendip = false);

fullMatrix<double> gmshGenerateMonomialsTriangle(int order,
                                                 bool serendip = false);
fullMatrix<double>
gmshGenerateMonomialsQuadrangle(int order, bool forSerendipPoints = false);
fullMatrix<double> gmshGenerateMonomialsQuadSerendipity(int order);

fullMatrix<double> gmshGenerateMonomialsTetrahedron(int order,
                                                    bool serendip = false);
fullMatrix<double>
gmshGenerateMonomialsHexahedron(int order, bool forSerendipPoints = false);
fullMatrix<double> gmshGenerateMonomialsHexaSerendipity(int order);
fullMatrix<double> gmshGenerateMonomialsPrism(int order,
                                              bool forSerendipPoints = false);
fullMatrix<double> gmshGenerateMonomialsPrismSerendipity(int order);

// Generate monomials of pyramidal nodal space {X^i Y^j Z^k | i,j <= k, k <=
// 'order'},
fullMatrix<double> gmshGenerateMonomialsPyramid(int order,
                                                bool forSerendipPoints = false);
fullMatrix<double> gmshGenerateMonomialsPyramidSerendipity(int order);
// If 'serendip' == true,
//   generate monomials of serendipity pyramid at order 'nk',
// else if 'pyr' == true,
//   generate monomials of space {X^i Y^j Z^k | i,j <= k+'nij', k <= 'nk'},
// else if 'pyr' == false,
//   generate monomials of space {X^i Y^j Z^k | i,j <= 'nij', k <= 'nk'}
fullMatrix<double>
gmshGenerateMonomialsPyramidGeneral(bool pyr, int nij, int nk,
                                    bool forSerendipPoints = false);

// Ordered points and monomials

void gmshGenerateOrderedPointsLine(int order, fullVector<double> &);

void gmshGenerateOrderedPoints(FuncSpaceData data, fullMatrix<double> &points,
                               bool bezierSpace = false);

void gmshGenerateOrderedMonomials(FuncSpaceData, fullMatrix<double> &);

#endif
