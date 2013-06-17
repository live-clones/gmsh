// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef POINTSGENERATORS_H
#define POINTSGENERATORS_H

#include "fullMatrix.h"

 /*
  * Functions to generate point distributions on
  * the references elements, for all orders.
  * &
  * Functions generating exponents of Pascal monomials
  * in the same order than Gmsh Points.
  */

// Points

fullMatrix<double> gmshGeneratePointsLine(int order);

fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip);
fullMatrix<double> gmshGeneratePointsQuadrangle(int order, bool serendip);

fullMatrix<double> gmshGeneratePointsTetrahedron(int order, bool serendip);
fullMatrix<double> gmshGeneratePointsHexahedron(int order, bool serendip);
fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip);

fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip);


// Monomial exponents

fullMatrix<int> gmshGenerateMonomialsLine(int order, bool serendip = false);

fullMatrix<int> gmshGenerateMonomialsTriangle(int order, bool serendip = false);
fullMatrix<int> gmshGenerateMonomialsQuadrangle(int order, bool forSerendipPoints = false);
fullMatrix<int> gmshGenerateMonomialsQuadSerendipity(int order);

fullMatrix<int> gmshGenerateMonomialsTetrahedron(int order, bool serendip = false);
fullMatrix<int> gmshGenerateMonomialsHexahedron(int order, bool forSerendipPoints = false);
fullMatrix<int> gmshGenerateMonomialsHexaSerendipity(int order);
fullMatrix<int> gmshGenerateMonomialsPrism(int order, bool forSerendipPoints = false);
fullMatrix<int> gmshGenerateMonomialsPrismSerendipity(int order);

fullMatrix<int> gmshGenerateMonomialsPyramid(int order, bool forSerendipPoints = false);
//fullMatrix<int> gmshGenerateMonomialsPyramidSerendipity(int order); //TODO



#endif
