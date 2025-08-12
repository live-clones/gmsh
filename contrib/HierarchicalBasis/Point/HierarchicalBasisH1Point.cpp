// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "HierarchicalBasisH1Point.h"

HierarchicalBasisH1Point::HierarchicalBasisH1Point() {
    _numVertex = 1;
    _numEdge = 0;
    _numQuadFace = 0;
    _numTriFace = 0;
    _numVertexFunction = 1;
    _numEdgeFunction = 0;
    _numQuadFaceFunction = 0;
    _numTriFaceFunction = 0;
    _numBubbleFunction = 0;
}

unsigned int HierarchicalBasisH1Point::getNumberOfOrientations() const {
    return 1; // factorial 1
}

void HierarchicalBasisH1Point::generateBasis(double const &u, double const &v, double const &w,
                                             std::vector<double> &vertexBasis,
                                             std::vector<double> &edgeBasis,
                                             std::vector<double> &faceBasis,
                                             std::vector<double> &bubbleBasis,
                                             std::string typeFunction) {
    vertexBasis[0] = 1;
}

void HierarchicalBasisH1Point::generateGradientBasis(double const &u, double const &v, double const &w,
                                                     std::vector<std::vector<double> > &gradientVertex,
                                                     std::vector<std::vector<double> > &gradientEdge,
                                                     std::vector<std::vector<double> > &gradientFace,
                                                     std::vector<std::vector<double> > &gradientBubble) {
    gradientVertex[0][0] = 1;
}

void HierarchicalBasisH1Point::getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo) {
    functionTypeInfo[0] = 0;
    orderInfo[0] = 0;
}
