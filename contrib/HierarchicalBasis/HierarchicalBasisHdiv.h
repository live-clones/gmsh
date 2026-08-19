// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Nawfel BENATIA (2025), based on Ismail Badia's contribution (2019).
//
// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_HDIV_H
#define HIERARCHICAL_BASIS_HDIV_H

#include "HierarchicalBasis.h"

class HierarchicalBasisHdiv : public HierarchicalBasis {
protected:
    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2, int const &flag3,
                               int const &faceNumber, std::vector<double> &faceFunctions,
                               std::string typeFunction) = 0;
    
    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2, int const &flag3,
                               int const &faceNumber, std::vector<std::vector<double> > &faceFunctions,
                               std::string typeFunction) = 0;

    HierarchicalBasisHdiv() = default;

public:
    virtual ~HierarchicalBasisHdiv() = default;
    
    virtual unsigned int getNumberOfOrientations() const = 0;

    virtual void generateBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &vertexBasis,
                               std::vector<std::vector<double> > &edgeBasis,
                               std::vector<std::vector<double> > &faceBasis,
                               std::vector<std::vector<double> > &bubbleBasis,
                               std::string typeFunction = "HdivLegendre") = 0;
    virtual void generateBasis(double const &u, double const &v, double const &w,
                               std::vector<double> &vertexBasis,
                               std::vector<double> &edgeBasis,
                               std::vector<double> &faceBasis,
                               std::vector<double> &bubbleBasis,
                               std::string typeFunction = "divHdivLegendre") = 0;

    virtual void orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions) = 0;
    virtual void orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions) = 0;

    virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                            std::vector<double> &edgeFunctions,
                            const std::vector<double> &eTablePositiveFlag,
                            const std::vector<double> &eTableNegativeFlag) = 0;
    virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                            std::vector<std::vector<double> > &edgeBasis,
                            const std::vector<std::vector<double> > &eTablePositiveFlag,
                            const std::vector<std::vector<double> > &eTableNegativeFlag) = 0;

    virtual void addAllOrientedFaceFunctions(double const &u, double const &v, double const &w,
                                             const std::vector<double> &faceFunctions,
                                             std::vector<double> &quadFaceFunctionsAllOrientations,
                                             std::vector<double> &triFaceFunctionsAllOrientations,
                                             std::string typeFunction);
    virtual void addAllOrientedFaceFunctions(double const &u, double const &v, double const &w,
                                             const std::vector<std::vector<double> > &faceFunctions,
                                             std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
                                             std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
                                             std::string typeFunction);
    
    virtual void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                            const std::vector<double> &quadFaceFunctionsAllOrientations,
                            const std::vector<double> &triFaceFunctionsAllOrientations,
                            std::vector<double> &fTableCopy) = 0;
    virtual void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                            const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
                            const std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
                            std::vector<std::vector<double> > &fTableCopy) = 0;
    
    virtual void getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo) = 0;
};

#endif
