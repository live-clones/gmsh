// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_H1_TRIA_H
#define HIERARCHICAL_BASIS_H1_TRIA_H

#include "HierarchicalBasisH1.h"

/* MTriangle
 *
 *
 *   ^ v
 *   |
 *   |
 *   |
 *   |
 *   v2
 *   |`\
 *   |  `\
 *   |    `\
 *   v      `\
 *   |        `\
 *   |          `\
 *   v0----->-----v1-------> u
 *
 *
 * Oriented Edges:
 *      e0={v0;v1}     e1={v1;v2}     e2={v2;v0}
 * Minimum rule :
 *      pe0,pe1,pe2 <= pf
 *
 */

class HierarchicalBasisH1Tria : public HierarchicalBasisH1 {
private:
    std::array<int, 3> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches the edge 0 order)
    int _pf; // face function order
    
    static double _affineCoordinate(int const &j, double const &u, double const &v); // affine coordinate lambda_j;  j=1,2,3

    void generateGradientBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &gradientVertex,
                               std::vector<std::vector<double> > &gradientEdge,
                               std::vector<std::vector<double> > &gradientFace,
                               std::vector<std::vector<double> > &gradientBubble);
    
    std::pair<int, int> computeEdgeFunctionRange(int edgeNumber) const;
    
    void orientOneFace(double const &u, double const &v, double const &w,
                       int const &flag1, int const &flag2, int const &flag3,
                       int const &faceNumber, std::vector<double> &faceBasis) override;
    void orientOneFace(double const &u, double const &v, double const &w,
                       int const &flag1, int const &flag2, int const &flag3,
                       int const &faceNumber, std::vector<std::vector<double> > &faceFunctions,
                       std::string typeFunction = "GradH1Legendre") override;
    
public:
    HierarchicalBasisH1Tria(int order);
    HierarchicalBasisH1Tria(int pf, int pe0, int pe1, int pe2);
    ~HierarchicalBasisH1Tria() override = default;
  
    unsigned int getNumberOfOrientations() const override;
  
    // vertexBasis = [v0,...,v2]
    // edgeBasis   = [phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
    // faceBasis   = [phif_{1,1},...,phif_{1,pf-2},phif_{2,1},...,phif_{2,pf2-3},phif_{1,1}...]
    void generateBasis(double const &u, double const &v, double const &w,
                       std::vector<double> &vertexBasis,
                       std::vector<double> &edgeBasis,
                       std::vector<double> &faceBasis,
                       std::vector<double> &bubbleBasis,
                       std::string typeFunction) override;
    void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<std::vector<double> > &vertexBasis,
                             std::vector<std::vector<double> > &edgeBasis,
                             std::vector<std::vector<double> > &faceBasis,
                             std::vector<std::vector<double> > &bubbleBasis,
                             std::string typeFunction) override {
        generateGradientBasis(u, v, w, vertexBasis, edgeBasis, faceBasis, bubbleBasis);
    }

    void orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions);
    void orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions);

    void orientEdge(int const &flagOrientation, int const &edgeNumber,
                    std::vector<double> &edgeFunctions,
                    const std::vector<double> &eTablePositiveFlag,
                    const std::vector<double> &eTableNegativeFlag) override;
    void orientEdge(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &edgeBasis,
                    const std::vector<std::vector<double> > &eTablePositiveFlag,
                    const std::vector<std::vector<double> > &eTableNegativeFlag) override;

    void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                    const std::vector<double> &quadFaceFunctionsAllOrientation,
                    const std::vector<double> &triFaceFunctionsAllOrientation,
                    std::vector<double> &fTableCopy) override;
    void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
                    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
                    std::vector<std::vector<double> > &fTableCopy) override;

    void getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo) override;
};

#endif
