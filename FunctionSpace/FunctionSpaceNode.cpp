#include <vector>

#include "BasisScalar.h"
#include "Mapper.h"
#include "FunctionSpaceNode.h"

using namespace std;

FunctionSpaceNode::FunctionSpaceNode(const GroupOfElement& goe,
				     int order){
  // Build 0Form Basis //
  build(goe, 0, order); 

  // Init BasisScalar //
  basisScalar = 
    static_cast<const BasisScalar*>(basis);
}
    
FunctionSpaceNode::~FunctionSpaceNode(void){
}

double FunctionSpaceNode::
interpolate(const MElement& element, 
	    const std::vector<double>& coef,
	    const fullVector<double>& xyz) const{

  // Const Cast For MElement //
  MElement& eelement = 
    const_cast<MElement&>(element);
  
  // Get Basis Functions //
  const vector<const Polynomial*> fun = getLocalFunctions(element);
  const unsigned int nFun             = fun.size();
  
  // Get Reference coordinate //
  double phys[3] = {xyz(0), xyz(1), xyz(2)};
  double uvw[3];

  eelement.xyz2uvw(phys, uvw);

  // Interpolate (in Reference Place) //
  double val = 0; 

  for(unsigned int i = 0; i < nFun; i++)
    val += 
      fun[i]->at(uvw[0], uvw[1], uvw[2]) * coef[i];

  // Return Interpolated Value //
  return val;
}
