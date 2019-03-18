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
  HierarchicalBasisH1Quad(int order);
  virtual ~HierarchicalBasisH1Quad();
  // vertexBasis=[v0,...,v3]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // bubbleBasis=[phieb_{2,2},...,phieb_{2,pb2},phieb_{3,2},...,phieb_{3,pb2},...,phieb_{pb1,2},...,phieb_{pb1,pb2}]
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis);
  virtual void
  generateGradientBasis(double const &u, double const &v, double const &w,
                        std::vector<std::vector<double> > &gradientVertex,
                        std::vector<std::vector<double> > &gradientEdge,
                        std::vector<std::vector<double> > &gradientFace,
                        std::vector<std::vector<double> > &gradientBubble);
  virtual void orientateEdge(int const &flagOrientation, int const &edgeNumber,
                             std::vector<double> &edgeBasis);
  virtual void
  orientateEdgeGrad(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &gradientEdge);

 virtual void orientateFace(int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,std::vector<double> &faceBasis){};
 virtual void reverseFaceBubbleFor3D(const bool belongBoundary);
 virtual void reverseEdgeBubbleFor2D(const bool belongBoundary){};

private:
  int _pb1; // bubble function order in  direction u
  int _pb2; // bubble function order in  direction v
  int _pOrderEdge[4]; // Edge functions order (pOrderEdge[0] matches the edge 0
                     // order)
  static double
  _affineCoordinate(int const &j, double const &u,
                   double const &v); // affine coordinate lambdaj j=1..4
};

#endif
