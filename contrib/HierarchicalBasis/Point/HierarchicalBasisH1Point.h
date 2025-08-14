// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_H1_POINT_H
#define HIERARCHICAL_BASIS_H1_POINT_H

#include "HierarchicalBasisH1.h"

/*
 *
 *              *
 *
 */

class HierarchicalBasisH1Point : public HierarchicalBasisH1 {
private:
    void generateGradientBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &gradientVertex,
                               std::vector<std::vector<double> > &gradientEdge,
                               std::vector<std::vector<double> > &gradientFace,
                               std::vector<std::vector<double> > &gradientBubble);

    void orientOneFace(double const &u, double const &v, double const &w,
                       int const &flag1, int const &flag2, int const &flag3,
                       int const &faceNumber, std::vector<double> &faceFunctions, std::string typeFunction = "H1Legendre") override {
        /* No operation needed for point basis */
    }
    void orientOneFace(double const &u, double const &v, double const &w,
                       int const &flag1, int const &flag2, int const &flag3,
                       int const &faceNumber, std::vector<std::vector<double> > &faceFunctions,
                       std::string typeFunction = "GradH1Legendre") override {
        /* No operation needed for point basis */
    }
    
public:
    HierarchicalBasisH1Point();
    ~HierarchicalBasisH1Point() override = default;
    
    unsigned int getNumberOfOrientations() const override;
  
    // vertexBasis=[v0]
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

    void orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions) override {
        /* No operation needed for point basis */
    }
    void orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions) override {
        /* No operation needed for point basis */
    }
    
    void orientEdge(int const &flagOrientation, int const &edgeNumber,
                    std::vector<double> &edgeFunctions,
                    const std::vector<double> &eTablePositiveFlag,
                    const std::vector<double> &eTableNegativeFlag) override {
        /* No operation needed for point basis */
    }
    void orientEdge(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &edgeBasis,
                    const std::vector<std::vector<double> > &eTablePositiveFlag,
                    const std::vector<std::vector<double> > &eTableNegativeFlag) override {
        /* No operation needed for point basis */
    }
    
    void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                    const std::vector<double> &quadFaceFunctionsAllOrientation,
                    const std::vector<double> &triFaceFunctionsAllOrientation,
                    std::vector<double> &fTableCopy) override {
        /* No operation needed for point basis */
    }
    void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
                    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
                    std::vector<std::vector<double> > &fTableCopy) override {
        /* No operation needed for point basis */
    }

   void getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo) override;
};

#endif
