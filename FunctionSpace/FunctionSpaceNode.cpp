#include "FunctionSpaceNode.h"

FunctionSpaceNode::FunctionSpaceNode(const GroupOfElement& goe,
				     int order){
  // Build 0Form Basis //
  build(goe, 0, order); 
}
    
FunctionSpaceNode::~FunctionSpaceNode(void){
}

double FunctionSpaceNode::
interpolate(const MElement& element, 
	    const std::vector<double>& coef,
	    const fullVector<double>& xyz) const{

  return 42;
}
