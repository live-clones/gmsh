//
// Created by Amaury Johnen on 13/02/18.
//

#ifndef GMSH_INTERIORVERTEXPLACEMENT_H
#define GMSH_INTERIORVERTEXPLACEMENT_H

#include "fullMatrix.h"

// Generate matrices M that allow to obtain a fair placement of high-order
// interior nodes when only boundary nodes are given.
// If x^b are x coordinate of boundary nodes, then x coordinate of interior
// nodes are given by M*x^b.
// The placement is obtained by analogy with linear transfinite interpolation.

// TODO Amaury: Create sparseMatrix?

fullMatrix<double>* getInnerVertexPlacement(int type, int order);

fullMatrix<double> gmshGenerateInnerVertexPlacementTriangle(int order);
fullMatrix<double> gmshGenerateInnerVertexPlacementQuadrangle(int order);
fullMatrix<double> gmshGenerateInnerVertexPlacementTetrahedron(int order);
fullMatrix<double> gmshGenerateInnerVertexPlacementHexahedron(int order);
fullMatrix<double> gmshGenerateInnerVertexPlacementPrism(int order);
fullMatrix<double> gmshGenerateInnerVertexPlacementPyramid(int order);

fullMatrix<double> gmshGenerateInnerVertexPlacementTriangleLinear(int order, int dir);
fullMatrix<double> gmshGenerateInnerVertexPlacementQuadrangleLinear(int order);
fullMatrix<double> gmshGenerateInnerVertexPlacementTetrahedronLinear(int order, int dir);
fullMatrix<double> gmshGenerateInnerVertexPlacementHexahedronLinear(int order, int dir);
fullMatrix<double> gmshGenerateInnerVertexPlacementPrismLinear(int order, int dir);

#endif //GMSH_INTERIORVERTEXPLACEMENT_H
