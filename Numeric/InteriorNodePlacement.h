//
// Created by Amaury Johnen on 13/02/18.
//

#ifndef GMSH_INTERIORNODEPLACEMENT_H
#define GMSH_INTERIORNODEPLACEMENT_H

#include "fullMatrix.h"

// Generate matrices M that allow to obtain a fair placement of high-order
// interior nodes when only boundary nodes are given.
// If x^b are x coordinate of boundary nodes, then x coordinate of interior
// nodes are given by M*x^b.
// The placement is obtained by analogy with linear transfinite interpolation.

// TODO Amaury: Create sparseMatrix

fullMatrix<double>* getInteriorNodePlacement(int type, int order);

fullMatrix<double> gmshGenerateInteriorNodePlacementTriangle(int order);
fullMatrix<double> gmshGenerateInteriorNodePlacementQuadrangle(int order);
fullMatrix<double> gmshGenerateInteriorNodePlacementTetrahedron(int order);
fullMatrix<double> gmshGenerateInteriorNodePlacementHexahedron(int order);
fullMatrix<double> gmshGenerateInteriorNodePlacementPrism(int order);
fullMatrix<double> gmshGenerateInteriorNodePlacementPyramid(int order);

fullMatrix<double> gmshGenerateInteriorNodePlacementTriangleLinear(int order,
                                                                   int dir);
fullMatrix<double> gmshGenerateInteriorNodePlacementQuadrangleLinear(int order);
fullMatrix<double> gmshGenerateInteriorNodePlacementTetrahedronLinear(int order, int dir);
fullMatrix<double> gmshGenerateInteriorNodePlacementHexahedronLinear(int order, int dir);
fullMatrix<double> gmshGenerateInteriorNodePlacementPrismLinear(int order, int dir);

#endif //GMSH_INTERIORNODEPLACEMENT_H
