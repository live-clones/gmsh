// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_HCURL_LINE_H
#define HIERARCHICAL_BASIS_HCURL_LINE_H

#include <stdexcept>
#include "HierarchicalBasisHcurl.h"

/*
 *
 *          ^ v
 *          |
 *          |
 *   0      |     1
 * --+------+-----+---> u
 *
 */

class HierarchicalBasisHcurlLine : public HierarchicalBasisHcurl {
private:
    int _pe; //  edge function order in  direction u
    
    static double _affineCoordinate(int j, double u); // affine coordinate lambda_j j={1,2}
  
    virtual void generateHcurlBasis(double const &u, double const &v, double const &w,
                                    std::vector<std::vector<double> > &edgeBasis,
                                    std::vector<std::vector<double> > &faceBasis,
                                    std::vector<std::vector<double> > &bubbleBasis);
    virtual void generateCurlBasis(double const &u, double const &v, double const &w,
                                   std::vector<std::vector<double> > &edgeBasis,
                                   std::vector<std::vector<double> > &faceBasis,
                                   std::vector<std::vector<double> > &bubbleBasis);

    static double dotProduct(const std::vector<double> &u, const std::vector<double> &v);
    
    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2, int const &flag3,
                               int const &faceNumber, std::vector<std::vector<double> > &faceFunctions,
                               std::string typeFunction){
        /* No operation needed for line basis */
    }
    
public:
    HierarchicalBasisHcurlLine(int order);
    
    virtual ~HierarchicalBasisHcurlLine() = default;
    
    virtual unsigned int getNumberOfOrientations() const;

    virtual void generateBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &vertexBasis,
                               std::vector<std::vector<double> > &edgeBasis,
                               std::vector<std::vector<double> > &faceBasis,
                               std::vector<std::vector<double> > &bubbleBasis,
                               std::string typeFunction) {
        if(typeFunction == "HcurlLegendre") {
            generateHcurlBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
        }
        else if("CurlHcurlLegendre" == typeFunction) {
            generateCurlBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
        }
        else {
            throw std::runtime_error("unknown typeFunction");
        }
    }
    
    virtual void orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions);

    virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                            std::vector<std::vector<double> > &edgeBasis,
                            const std::vector<std::vector<double> > &eTablePositiveFlag,
                            const std::vector<std::vector<double> > &eTableNegativeFlag);
  
    virtual void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                            const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
                            const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
                            std::vector<std::vector<double> > &fTableCopy){
        /* No operation needed for line basis */
    }
  
    virtual void getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo);
};

#endif
