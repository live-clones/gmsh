#ifndef _HierarchicalBasisH1Tria_H_
#define _HierarchicalBasisH1Tria_H_

#include "HierarchicalBasisH1.h"
#include <algorithm>

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
 *  pe0,pe1,pe2<=pb
 *
 */
class HierarchicalBasisH1Tria : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Tria(int pb, int pe0, int pe1, int pe2);
  virtual ~HierarchicalBasisH1Tria(void);
  // vertexBasis=[v0,...,v2]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // bubbleBasis=[phieb_{1,1},...,phieb_{1,peb-2},phieb_{2,1},...,phieb_{2,peb2-3},phieb_{1,1}...]
  virtual void generateBasis(double const &u, double const & v, double const & w,double *vertexBasis,double *edgeBasis, double*faceBasis,double *bubbleBasis);
  virtual void generateGradientBasis(double const & u,double const & v, double const & w,double gradientVertex[][3],  double gradientEdge[][3], double gradientFace[][3], double gradientBubble[][3]);


  virtual void orientateEdge(int const &flagOrientation, int const &edgeNumber,
                     double *edgeBasis);
   virtual void orientateEdgeGrad(int const &flagOrientation, int const &edgeNumber,double gradientEdge[][3]);


private:
  int pb; // bubble function order
  int pOrderEdge[3]; // Edge functions order (pOrderEdge[0] matches the edge 0
                     // order)
  static double affineCoordinate(int j, double u,
                                 double v); // affine coordinate lambdaj j=1..3
};

#endif
