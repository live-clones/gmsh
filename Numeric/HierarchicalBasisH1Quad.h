#ifndef _HierarchicalBasisH1Quad_H_
#define _HierarchicalBasisH1Quad_H_


#include "HierarchicalBasisH1.h"
#include <algorithm>
#include <vector>
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
  class HierarchicalBasisH1Quad : public HierarchicalBasisH1{
  public:
    HierarchicalBasisH1Quad(int pb1,int pb2,int pe0,int pe1,int pe2,int pe3); 
    virtual ~HierarchicalBasisH1Quad(void);
   void generateBasis( double const& u, double const& v, double* vertexBasis,double* edgeBasis,double* bubbleBasis,int sizeVertexBasis, int sizeEdgeBasis,int sizeBubbleBasis);
    void generateGradientBasis( double const& u, double const& v, double* gradientVertexU,double* gradientVertexV,double* gradientEdgeU,double* gradientEdgeV, double* gradientBubbleU, double* gradientBubbleV,int sizeVertexBasis, int sizeEdgeBasis,int sizeBubbleBasis);
/*Each physical mesh edge will  be assigned a unique orientation,and all edges of physical mesh quadrilaterals will be equipped with an orientation flag 
 *, indicating whether the image of the corresponding edge of the reference domain through the reference map has the same or opposite orientation.
 */
    void edgeOrientation( int const& flagOrientation, int const& edgeNumber,double* edgeBasis,double* gradientEdgeU, double* gradientEdgeV);
 
  private:

    int pb1;// bubble function order in  direction u
    int pb2;// bubble function order in  direction v
    int pOrderEdge[4]; // Edge functions order (pOrderEdge[0] matches the edge 0 order)
    static double affineCoordinate(int j, double u ,  double v);//affine coordinate lambdaj j=1..4
    };



#endif
