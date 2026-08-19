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

#ifndef HIERARCHICAL_BASIS_HDIV_TRIA_H
#define HIERARCHICAL_BASIS_HDIV_TRIA_H

#include <stdexcept>
#include <math.h>
#include "HierarchicalBasisHdiv.h"

/*
 * MTriangle
 *
 *   v
 *   ^
 *   |
 *   2
 *   |`\
 *   |  `\
 *   |    `\
 *   |      `\
 *   v        `\
 *   0---------->1 --> u
 *
 *
 * Oriented Edges:
 *  e0={v0;v1}    e1={v1;v2}  e2={v2;v0}
 *  pe0,pe1,pe2<=pf
 *
 */
class HierarchicalBasisHdivTria : public HierarchicalBasisHdiv {
private:
    int _pf; // face function order
    std::array<int, 3> _pOrderEdge; // Edge functions order (pOrderEdge[0] matches the edge 0 order)
        
    // affine coordinate lambda_j j=1..3
    static double _affineCoordinate(int const &j, double const &u, double const &v);

    // edgeBasis=[phie0_{0},...phie0_{pe0},phie1_{0},...phie1_{pe1}...; edge-based
    // bubble functions ] faceBasis=[ genuine bubble functions]
    virtual void generateHdivBasis(double const &u, double const &v, double const &w,
                                    std::vector<std::vector<double> > &edgeBasis,
                                    std::vector<std::vector<double> > &faceBasis,
                                    std::vector<std::vector<double> > &bubbleBasis);
    
    virtual void generateDivBasis(double const &u, double const &v, double const &w,
                                  std::vector<double> &edgeBasis,
                                  std::vector<double> &faceBasis,
                                  std::vector<double> &bubbleBasis);

    static double dotProduct(const std::vector<double> &u, const std::vector<double> &v);

    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2, int const &flag3,
                               int const &faceNumber, std::vector<double> &faceFunctions,
                               std::string typeFunction);

    virtual void orientOneFace(double const &u, double const &v, double const &w,
                               int const &flag1, int const &flag2, int const &flag3,
                               int const &faceNumber, std::vector<std::vector<double> > &faceFunctions,
                               std::string typeFunction);
    
public:
    HierarchicalBasisHdivTria(int order);
    
    virtual ~HierarchicalBasisHdivTria() = default;
    
    virtual unsigned int getNumberOfOrientations() const;
    
    virtual void generateBasis(double const &u, double const &v, double const &w,
                               std::vector<std::vector<double> > &vertexBasis,
                               std::vector<std::vector<double> > &edgeBasis,
                               std::vector<std::vector<double> > &faceBasis,
                               std::vector<std::vector<double> > &bubbleBasis,
                               std::string typeFunction) {
        if(typeFunction == "HdivLegendre") {
            generateHdivBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
        }
        else {
            throw std::runtime_error("unknown typeFunction");
        }
    }

    virtual void generateBasis(double const &u, double const &v, double const &w,
                               std::vector<double> &vertexBasis,
                               std::vector<double> &edgeBasis,
                               std::vector<double> &faceBasis,
                               std::vector<double> &bubbleBasis,
                               std::string typeFunction) {
        if("DivHdivLegendre" == typeFunction) {
            generateDivBasis(u, v, w, edgeBasis, faceBasis, bubbleBasis);
        }
        else {
            throw std::runtime_error("unknown typeFunction");
        }
    }
    

    virtual void orientEdgeFunctionsForNegativeFlag(std::vector<std::vector<double> > &edgeFunctions);
    virtual void orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions);
    
    virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                            std::vector<std::vector<double> > &edgeBasis,
                            const std::vector<std::vector<double> > &eTablePositiveFlag,
                            const std::vector<std::vector<double> > &eTableNegativeFlag);
    virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                            std::vector<double> &edgeBasis,
                            const std::vector<double> &eTablePositiveFlag,
                            const std::vector<double> &eTableNegativeFlag);
    
    virtual void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                            const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
                            const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
                            std::vector<std::vector<double> > &fTableCopy);
    virtual void orientFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
                            const std::vector<double> &quadFaceFunctionsAllOrientation,
                            const std::vector<double> &triFaceFunctionsAllOrientation,
                            std::vector<double> &fTableCopy);
    
    virtual void getKeysInfo(std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo);

};

#endif

