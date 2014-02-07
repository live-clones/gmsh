// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
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

fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip = false);
fullMatrix<double> gmshGeneratePointsQuadrangle(int order, bool serendip = false);

fullMatrix<double> gmshGeneratePointsTetrahedron(int order, bool serendip = false);
fullMatrix<double> gmshGeneratePointsHexahedron(int order, bool serendip = false);
fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip = false);

fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip = false);


// Monomial exponents

fullMatrix<double> gmshGenerateMonomialsLine(int order, bool serendip = false);

fullMatrix<double> gmshGenerateMonomialsTriangle(int order, bool serendip = false);
fullMatrix<double> gmshGenerateMonomialsQuadrangle(int order, bool forSerendipPoints = false);
fullMatrix<double> gmshGenerateMonomialsQuadSerendipity(int order);

fullMatrix<double> gmshGenerateMonomialsTetrahedron(int order, bool serendip = false);
fullMatrix<double> gmshGenerateMonomialsHexahedron(int order, bool forSerendipPoints = false);
fullMatrix<double> gmshGenerateMonomialsHexaSerendipity(int order);
fullMatrix<double> gmshGenerateMonomialsPrism(int order, bool forSerendipPoints = false);
fullMatrix<double> gmshGenerateMonomialsPrismSerendipity(int order);

fullMatrix<double> gmshGenerateMonomialsPyramid(int order, bool forSerendipPoints = false);
//fullMatrix<double> gmshGenerateMonomialsPyramidSerendipity(int order); //TODO



#endif
