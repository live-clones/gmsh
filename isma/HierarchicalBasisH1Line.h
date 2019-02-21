#ifndef _HierarchicalBasisH1Line_H_
#define _HierarchicalBasisH1Line_H_


#include "HierarchicalBasisH1.h"
#include <algorithm>

#include<vector>
/*
 *
 *   
 *      
 *      
 *   0          +1    
 * --+-----------+---> u
 *
 *	   
 *
 * 
 *  
 *    
 *
 */
  class HierarchicalBasisH1Line : public HierarchicalBasisH1{
  public:
    HierarchicalBasisH1Line(int pb1); 
    virtual ~HierarchicalBasisH1Line(void);
    void generateBasis( double u,double* vertexBasis, double* bubbleBasis,int sizeVertexBasis, int sizeBubbleBasis);
    void generateGradientBasis( double u,double* vertexGradientU, double *bubbleGradientU ,int sizeVertexBasis, int sizeBubbleBasis); 

  private:

    int pb1;// bubble function order in  direction u
    static double affineCoordinate(int j, double u );//affine coordinate lambdaj j={1,2}
    double getDetJacobian();// for transformation [-1;1] -> [0,1]
    };



#endif
