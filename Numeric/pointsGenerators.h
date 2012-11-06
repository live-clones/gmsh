// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef POINTSGENERATORS_H
#define POINTSGENERATORS_H

#include "fullMatrix.h"

 /*
  * Functions to generate point distributions on
  * the references elements, for all orders.
  */

/* --- Lines --- */

fullMatrix<double> gmshGeneratePointsLine(int order);

/* --- Triangles --- */

fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip);

/* --- Quadrangles --- */

fullMatrix<double> gmshGeneratePointsQuadrangle(int order, bool serendip);

/* --- Tetahedra --- */

fullMatrix<double> gmshGeneratePointsTetrahedron(int order, bool serendip);

/* --- Hexahedra --- */

fullMatrix<double> gmshGeneratePointsHexahedron(int order, bool serendip);

/* --- Prisms --- */

fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip);

/* --- Pyramids --- */

fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip);

#endif
