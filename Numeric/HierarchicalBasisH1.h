#ifndef _HierarchicalBasisH1_H_
#define _HierarchicalBasisH1_H_  

//Hierarchical Basis of the master Element 
#include <string>
#include <iostream>
#include "OrthogonalPoly.h"
class HierarchicalBasisH1 {
	protected:
	    int nvertex;
	    int nedge;
	    int nface;
	    int nVertexFunction;
	    int nEdgeFunction;
	    int nFaceFunction;
	    int nBubbleFunction;
	public:

	      HierarchicalBasisH1(int nvertex,int nedge, int nface,int nVertexFunction, int nEdgeFunction, int nFaceFunction , int nBubbleFunction);
	      virtual ~HierarchicalBasisH1();
              int getnVertexFunction() const; 
  	      int getnEdgeFunction() const;
              int getnFaceFunction() const;
              int getnBubbleFunction() const; 
};		


#endif
