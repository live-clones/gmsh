// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_H1_QUAD_H
#define HIERARCHICAL_BASIS_H1_QUAD_H

#include "HierarchicalBasisH1.h"

/*
 *
 *             ^ v
 *             |
 *             |
 *             |+1
 *       3---------->2
 *       ^     |     ^
 *       |     |     |
 *     -1|-----0-----|+1---> u
 *       |     |     |
 *       |     |     |
 *       0---------->1
 *  	       |-1
 *             |
 *
 * Oriented Edges:
 *      e0={v0;v1}     e1={v1;v2}     e2={v3;v2}     e3={v0;v3}
 * Minimum rule :
 *      pe0,pe2 <= pf1  &  pe1,pe3 <= pf2
 *
 */

class HierarchicalBasisH1Quad : public HierarchicalBasisH1 {
private:
    std::array<int, 4> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches the edge 0 order)
    std::array<int, 2> _pf; /* _pf[0] face function order in  direction u
                             & _pf[1] face function order in  direction v */

    // affine coordinate lambda_j, j=1,...,4
    static double _affineCoordinate(int const &j, double const &u, double const &v);

    void generateGradientBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &gradientVertex,
                               std::vector<std::vector<double> > &gradientEdge,
                               std::vector<std::vector<double> > &gradientFace,
                               std::vector<std::vector<double> > &gradientBubble);

    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2,
                               int const &flag3, int const &faceNumber,
                               std::vector<double> &faceBasis);
    
    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2,
                               int const &flag3, int const &faceNumber,
                               std::vector<std::vector<double> > &faceFunctions,
                               std::string typeFunction = "GradH1Legendre");
public:
    HierarchicalBasisH1Quad(int order);
    HierarchicalBasisH1Quad(int pf1, int pf2, int pe0, int pe1, int pe2, int pe3);
    ~HierarchicalBasisH1Quad() override = default;

    virtual unsigned int getNumberOfOrientations() const;
    
    // vertexBasis=[v0,...,v3]
    // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
    // faceBasis=[phif_{2,2},...,phif_{2,pf2},phif_{3,2},...,phif_{3,pf2},...,phif_{pf1,2},...,phif_{pf1,pf2}]
    virtual void generateBasis(double const &u, double const &v, double const &w,
                               std::vector<double> &vertexBasis,
                               std::vector<double> &edgeBasis,
                               std::vector<double> &faceBasis,
                               std::vector<double> &bubbleBasis,
                               std::string typeFunction);

    virtual void generateBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &vertexBasis,
                               std::vector<std::vector<double> > &edgeBasis,
                               std::vector<std::vector<double> > &faceBasis,
                               std::vector<std::vector<double> > &bubbleBasis,
                               std::string typeFunction) {
        generateGradientBasis(u, v, w, vertexBasis, edgeBasis, faceBasis, bubbleBasis);
    }

    virtual void orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions);
    virtual void orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions);

    virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                            std::vector<double> &edgeFunctions,
                            const std::vector<double> &eTablePositiveFlag,
                            const std::vector<double> &eTableNegativeFlag);
    virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                            std::vector<std::vector<double> > &edgeBasis,
                            const std::vector<std::vector<double> > &eTablePositiveFlag,
                            const std::vector<std::vector<double> > &eTableNegativeFlag);
  
    virtual void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                            const std::vector<double> &quadFaceFunctionsAllOrientation,
                            const std::vector<double> &triFaceFunctionsAllOrientation,
                            std::vector<double> &fTableCopy);
    virtual void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                            const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
                            const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
                            std::vector<std::vector<double> > &fTableCopy);

    virtual void getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo);
};

#endif
