#ifndef _HierarchicalBasisH1Tria_H_
#define _HierarchicalBasisH1Tria_H_


#include "HierarchicalBasisH1.h"
#include <algorithm>
#include <vector>

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
  class HierarchicalBasisH1Tria : public HierarchicalBasisH1{
  public:
    HierarchicalBasisH1Tria(int pb,int pe0,int pe1,int pe2); 
    virtual ~HierarchicalBasisH1Tria(void);
    void generateBasis( double  u, double  v, double* vertexBasis,double* edgeBasis, double* bubbleBasis,int sizeVertexBasis,int sizeEdgeBasis,int sizeBubbleBasis);
  //  void generateGradientBasis( double  u, double  v,double* gradientU,double * gradientV, int size);
/*Each physical mesh edge will  be assigned a unique orientation,and all edges of physical mesh quadrilaterals will be equipped with an orientation flag 
 *, indicating whether the image of the corresponding edge of the reference domain through the reference map has the same or opposite orientation.
 */
    //void edgeOrientation( int const& flagOrientation, int const& edgeNumber,double* HierarchicalBasis,double* gradientU, double* gradientV);
 
  private:
    
    int pb;// bubble function order 
    int pOrderEdge[3]; // Edge functions order (pOrderEdge[0] matches the edge 0 order)
    static double affineCoordinate(int j, double u ,  double v);//affine coordinate lambdaj j=1..3
    };



#endif
