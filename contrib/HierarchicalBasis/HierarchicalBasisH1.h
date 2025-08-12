// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_H1_H
#define HIERARCHICAL_BASIS_H1_H

#include "HierarchicalBasis.h"

class HierarchicalBasisH1 : public HierarchicalBasis {
protected:
    void orientOneFace(double const &u, double const &v, double const &w,
                       int const &flag1, int const &flag2, int const &flag3,
                       int const &faceNumber, std::vector<double> &faceFunctions) override = 0;
    void orientOneFace(double const &u, double const &v, double const &w,
                       int const &flag1, int const &flag2,
                       int const &flag3, int const &faceNumber,
                       std::vector<std::vector<double> > &faceFunctions,
                       std::string typeFunction = "GradH1Legendre") override = 0;
    
    HierarchicalBasisH1() = default;

public:
    ~HierarchicalBasisH1() override = default;
    
    unsigned int getNumberOfOrientations() const override = 0;

    void generateBasis(double const &u, double const &v, double const &w,
                       std::vector<double> &vertexBasis,
                       std::vector<double> &edgeBasis,
                       std::vector<double> &faceBasis,
                       std::vector<double> &bubbleBasis,
                       std::string typeFunction = "H1Legendre") override = 0;
    void generateBasis(double const &u, double const &v, double const &w,
                       std::vector<std::vector<double> > &vertexBasis,
                       std::vector<std::vector<double> > &edgeBasis,
                       std::vector<std::vector<double> > &faceBasis,
                       std::vector<std::vector<double> > &bubbleBasis,
                       std::string typeFunction = "GradH1Legendre") override = 0;

    void orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions) override = 0;
    void orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions) override = 0;

    void orientEdge(int const &flagOrientation, int const &edgeNumber,
                    std::vector<double> &edgeFunctions,
                    const std::vector<double> &eTablePositiveFlag,
                    const std::vector<double> &eTableNegativeFlag) override = 0;
    void orientEdge(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &edgeBasis,
                    const std::vector<std::vector<double> > &eTablePositiveFlag,
                    const std::vector<std::vector<double> > &eTableNegativeFlag) override = 0;
    
    void addAllOrientedFaceFunctions(double const &u, double const &v, double const &w,
                                     const std::vector<double> &faceFunctions,
                                     std::vector<double> &quadFaceFunctionsAllOrientations,
                                     std::vector<double> &triFaceFunctionsAllOrientations) override;
    void addAllOrientedFaceFunctions(double const &u, double const &v, double const &w,
                                     const std::vector<std::vector<double> > &faceFunctions,
                                     std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
                                     std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
                                     std::string typeFunction = "GradH1Legendre") override;
    
    void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                    const std::vector<double> &quadFaceFunctionsAllOrientations,
                    const std::vector<double> &triFaceFunctionsAllOrientations,
                    std::vector<double> &fTableCopy) override = 0;
    void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
                    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
                    std::vector<std::vector<double> > &fTableCopy) override = 0;
          
    void getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo) override = 0;
};

#endif
