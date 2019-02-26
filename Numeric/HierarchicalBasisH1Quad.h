#ifndef _HierarchicalBasisH1Quad_H_
#define _HierarchicalBasisH1Quad_H_

#include "HierarchicalBasisH1.h"
#include <algorithm>
/*
 *
 *         v
 *         ^
 *         |+1
 *   3<----------2
 *   |     |     ^
 *   |     |     |
 * -1|     +---- |+1 --> u
 *   |           |
 *   v           |
 *   0---------->1
 *	   -1
 *
 * Oriented Edges:
 *  e0={v0;v1}    e1={v1;v2}  e2={v2;v3}  e3={v3;v4}
 *  pe3,pe1<=pb2       pe0,pe2<=pb1
 *
 */
class HierarchicalBasisH1Quad : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Quad(int pb1, int pb2, int pe0, int pe1, int pe2, int pe3);
  virtual ~HierarchicalBasisH1Quad(void);
  // vertexBasis=[v0,...,v3]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // bubbleBasis=[phieb_{2,2},...,phieb_{2,peb2},phieb_{3,2},...,phieb_{3,peb2},...,phieb_{peb1,2},...,phieb_{peb1,peb2}]
 virtual void generateBasis(double const &u, double const & v, double const & w,double *vertexBasis,double *edgeBasis, double*faceBasis,double *bubbleBasis);
 virtual void generateGradientBasis(double const & u,double const & v, double const & w,double gradientVertex[][3],  double gradientEdge[][3], double gradientFace[][3], double gradientBubble[][3]);
  virtual void orientateEdge(int const &flagOrientation, int const &edgeNumber,
                     double *edgeBasis);
  virtual void orientateEdgeGrad(int const &flagOrientation, int const &edgeNumber,double gradientEdge[][3]);


private:
  int pb1; // bubble function order in  direction u
  int pb2; // bubble function order in  direction v
  int pOrderEdge[4]; // Edge functions order (pOrderEdge[0] matches the edge 0
                     // order)
  static double affineCoordinate(int j, double u,
                                 double v); // affine coordinate lambdaj j=1..4
};

#endif
