// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include <stdexcept>
#include "HierarchicalBasisHcurlLine.h"

HierarchicalBasisHcurlLine::HierarchicalBasisHcurlLine(int order) {
    _pe = order;
    _numVertex = 2;
    _numEdge = 1;
    _numQuadFace = 0;
    _numTriFace = 0;
    _numVertexFunction = 0;
    _numEdgeFunction = order + 1;
    _numQuadFaceFunction = 0;
    _numTriFaceFunction = 0;
    _numBubbleFunction = 0;
}

unsigned int HierarchicalBasisHcurlLine::getNumberOfOrientations() const {
    return 2; // factorial 2
}

double HierarchicalBasisHcurlLine::_affineCoordinate(int j, double u) {
    switch(j) {
        case(1):
            return 0.5 * (1 + u);
        case(2):
            return 0.5 * (1 - u);
        default:
            throw std::runtime_error("j must be : 1<=j<=2");
    }
}

double HierarchicalBasisHcurlLine::dotProduct(const std::vector<double> &u, const std::vector<double> &v) {
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

void HierarchicalBasisHcurlLine::generateHcurlBasis(double const &u, double const &v, double const &w,
                                                    std::vector<std::vector<double> > &edgeBasis,
                                                    std::vector<std::vector<double> > &faceBasis,
                                                    std::vector<std::vector<double> > &bubbleBasis) {
    double lambda1 = _affineCoordinate(1, u);
    double lambda2 = _affineCoordinate(2, u);
    
    std::vector<double> t1 = {1, 0, 0};
    std::vector<double> n1 = {1, 0, 0};
    std::vector<double> n2 = {-1, 0, 0};
    
    // Whitney functions
    std::vector<double> psie_0(3, 0);
    std::vector<double> psie_1(3, 0);
    
    double d1 = dotProduct(n1, t1);
    double d2 = dotProduct(n2, t1);
    for(int i = 0; i < 3; i++) {
        psie_0[i] = lambda1 * n2[i] / d2 + lambda2 * n1[i] / d1;
        psie_1[i] = lambda1 * n2[i] / d2 - lambda2 * n1[i] / d1;
    }
    double sub = lambda1 - lambda2;
    
    std::vector<double> legendreVector(_pe, 0);
    
    for(unsigned int k = 0; k < legendreVector.size(); k++) {
        legendreVector[k] = OrthogonalPoly::EvalLegendre(k, sub);
    }
    
    int edgeIt = 0;
    for(int j = 0; j < 3; j++) {
        edgeBasis[edgeIt][j] = psie_0[j];
    }
    edgeIt++;
    if(_pe >= 1) {
        for(int j = 0; j < 3; j++) {
            edgeBasis[edgeIt][j] = psie_1[j];
        }
        edgeIt++;
        for(int iedge = 2; iedge <= _pe; iedge++) {
            float a = 2.0f - 1.0f / float(iedge);
            float b = 1.0f - 1.0f / float(iedge);
            float Lnm1 = legendreVector[iedge - 1];
            float Lnm2 = legendreVector[iedge - 2];
            for(int j = 0; j < 3; j++) {
                edgeBasis[edgeIt][j] = a * Lnm1 * psie_1[j] - b * Lnm2 * psie_0[j];
            }
            edgeIt++;
        }
    }
}

void HierarchicalBasisHcurlLine::generateCurlBasis( double const &u, double const &v, double const &w,
                                                   std::vector<std::vector<double> > &edgeBasis,
                                                   std::vector<std::vector<double> > &faceBasis,
                                                   std::vector<std::vector<double> > &bubbleBasis)
{
    // For 1D line elements, the curl of H(curl) basis functions is zero.
    for (auto &vec : edgeBasis)
        std::fill(vec.begin(), vec.end(), 0.0);
}

void HierarchicalBasisHcurlLine::orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions) {
    for(int k = 0; k <= _pe; k++) {
        if(k % 2 == 0) {
            edgeFunctions[k][0] = edgeFunctions[k][0] * (-1);
            edgeFunctions[k][1] = edgeFunctions[k][1] * (-1);
            edgeFunctions[k][2] = edgeFunctions[k][2] * (-1);
        }
    }
}

void HierarchicalBasisHcurlLine::orientEdge(int const &flagOrientation, int const &edgeNumber,
                                            std::vector<std::vector<double> > &edgeFunctions,
                                            const std::vector<std::vector<double> > &eTablePositiveFlag,
                                            const std::vector<std::vector<double> > &eTableNegativeFlag) {
    if(flagOrientation == -1) {
        for(int k = 0; k <= _pe; k++) {
            edgeFunctions[k][0] = eTableNegativeFlag[k][0];
            edgeFunctions[k][1] = eTableNegativeFlag[k][1];
            edgeFunctions[k][2] = eTableNegativeFlag[k][2];
        }
    }
    else {
        for(int k = 0; k <= _pe; k++) {
            edgeFunctions[k][0] = eTablePositiveFlag[k][0];
            edgeFunctions[k][1] = eTablePositiveFlag[k][1];
            edgeFunctions[k][2] = eTablePositiveFlag[k][2];
        }
    }
}

void HierarchicalBasisHcurlLine::getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo) {
    for(int k = 0; k <= _pe; k++) {
        orderInfo[k] = k;
        functionTypeInfo[k] = 1;
    }
}
