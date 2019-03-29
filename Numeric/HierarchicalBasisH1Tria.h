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
 *  pe0,pe1,pe2<=pf
 *
 */
class HierarchicalBasisH1Tria : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Tria(int pf, int pe0, int pe1, int pe2);
  HierarchicalBasisH1Tria(int order);
  virtual ~HierarchicalBasisH1Tria();
  // vertexBasis=[v0,...,v2]
  // edgeBasis=[phie0_{2},...phie0_{pe0-1},phie1_{2},...phie1_{pe1-1}...]
  // faceBasis=[phief_{1,1},...,phief_{1,pf-2},phief_{2,1},...,phief_{2,pf2-3},phief_{1,1}...]
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

  virtual void orientateFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceBasis){};

  virtual void
  orientateFaceGrad(double const &u, double const &v, double const &w,
                    int const &flag1, int const &flag2, int const &flag3,
                    int const &faceNumber,
                    std::vector<std::vector<double> > &gradientFace){};

private:
  int _pf; // face function order
  int _pOrderEdge[3]; // Edge functions order (pOrderEdge[0] matches the edge 0
                      // order)
  static double
  _affineCoordinate(int const &j, double const &u,
                    double const &v); // affine coordinate lambdaj j=1..3
};

#endif
