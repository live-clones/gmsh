// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_H1_BRICK_H
#define HIERARCHICAL_BASIS_H1_BRICK_H

#include "HierarchicalBasisH1.h"

/*
 * MHexahedron
 *
 *          v
 *   3----------2
 *   |\     ^   |\
 *   | \    |   | \
 *   |  \   |   |  \
 *   |   7------+---6
 *   |   |  +-- |-- | -> u
 *   0---+---\--1   |
 *    \  |    \  \  |
 *     \ |     \  \ |
 *      \|      w  \|
 *       4----------5
 *
 *  Oriented Edges:
 * e0={0, 1}, e1={0, 3}, e2={0, 4}, e3={1, 2}, e4 ={1, 5}, e5={3, 2},e6={2, 6},
 * e7={3, 7},e8={4, 5}, e9= {4, 7}, e10={5, 6}, e11={7, 6}
 *
 * Oritented Surface:
 *  s0={0, 1, 3, 2}, s1={0, 1, 4, 5}, s2={0, 3, 4, 7},
 *  s3={1, 2, 5, 6}, s4={3,2,7,6}, s5={4, 5, 7, 6}
 * Local (directional) orders on mesh faces are not allowed to exceed the mini-
 * mum of the (appropriate directional) orders of approximation associated with
 * the interior of the adjacent elements. Local orders of approximation on mesh
 * edges are limited by the minimum of all (appropriate directional) orders cor-
 * responding to faces sharing that edge
 */

class HierarchicalBasisH1Brick : public HierarchicalBasisH1 {
private:
    std::array<int, 3> _pb; /*
                            * _pb[0] : bubble function order in the u-direction
                            * _pb[1] : bubble function order in the v-direction
                            * _pb[2] : bubble function order in the w-direction
                            */
    std::array<int, 12> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches the order of the edge 0)
    
    std::array<std::array<int, 6>, 2> _pOrderFace; /*
                                                    * _pOrderFace[0] : Orders of face functions in the u-direction
                                                    *    (_pOrderFace[0][i] corresponds to the u-order of face i)
                                                    * _pOrderFace[1] : Orders of face functions in the v-direction
                                                    *    (_pOrderFace[1][i] corresponds to the v-order of face i)
                                                    */
    
    // affine coordinate lambda_j : j=1,...,6
    static double _affineCoordinate(const int &j, const double &u, const double &v, const double &w);
  
    inline void _computeLambda(double u, double v, double w, std::array<double, 6>& lambda) const {
        for (int i = 0; i < 6; ++i) {
            lambda[i] = _affineCoordinate(i + 1, u, v, w);
        }
    }

    void _someProduct(double u, double v, double w,
                      std::vector<double>& product,
                      std::vector<double>& lambda);

    
    void _someProductGrad(double const &u, double const &v, double const &w,
                          std::vector<double> &product,
                          std::vector<std::vector<double> > &gradientProduct,
                          std::vector<double> &lambda,
                          std::vector<std::vector<double> > &gradientLambda); // compute some product and fill the vector gradientVertex
  
    void _someProductGrad(double u, double v, double w,
                          std::array<double, 12>& product,
                          std::array<std::array<double, 3>, 12>& gradientProduct,
                          std::array<double, 6>& lambda,
                          std::array<std::array<double, 3>, 6>& gradientLambda) const;
    
    void generateGradientBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &gradientVertex,
                               std::vector<std::vector<double> > &gradientEdge,
                               std::vector<std::vector<double> > &gradientFace,
                               std::vector<std::vector<double> > &gradientBubble);
    
    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2,
                               int const &flag3, int const &faceNumber,
                               std::vector<double> &faceBasis,
                               std::string typeFunction = "H1Legendre");
    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2,
                               int const &flag3, int const &faceNumber,
                               std::vector<std::vector<double> > &faceFunctions,
                               std::string typeFunction = "GradH1Legendre");
public:
    HierarchicalBasisH1Brick(int order);
    ~HierarchicalBasisH1Brick() override = default;
    
    virtual unsigned int getNumberOfOrientations() const;
    
    // vertexBasis=[v0,...,v12]
    // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
    // faceBasis=[phif0_{2,2},...,phif0_{2,pF0_2},...,phif0_{pF0_1,2},...,phief0_{pF0_1,pF0_2},phif1_{2,2}...}]
    // bubbleBasis=[phieb_{2,2,2},...,phieb_{2,,2,pb3},phieb_{2,3,2},...,phieb_{2,3,pe3},...}]
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
        generateGradientBasis(u, v, w, vertexBasis, edgeBasis, faceBasis,bubbleBasis);
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
