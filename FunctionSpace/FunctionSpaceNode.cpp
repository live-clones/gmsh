#include <vector>

#include "BasisLocalScalar.h"
#include "Mapper.h"
#include "FunctionSpaceNode.h"

using namespace std;

FunctionSpaceNode::FunctionSpaceNode(const GroupOfElement& goe,
				     int order){
  // Build 0Form Basis //
  build(goe, 0, order); 

  // Init BasisScalar //
  localBasisScalar = 
    static_cast<const BasisLocalScalar*>(localBasis);
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
    
  // Get Reference coordinate //
  double phys[3] = {xyz(0), xyz(1), xyz(2)};
  double uvw[3];

  eelement.xyz2uvw(phys, uvw);

  // Get Basis Functions //
  fullMatrix<double>* fun = 
    localBasisScalar->getFunctions(element, uvw[0], uvw[1], uvw[2]);

  const unsigned int nFun = fun->size1();

  // Interpolate (in Reference Place) //
  double val = 0; 

  for(unsigned int i = 0; i < nFun; i++)
    val += (*fun)(i, 0) * coef[i];

  // Return Interpolated Value //
  delete fun;
  return val;
}

double FunctionSpaceNode::
interpolateInRefSpace(const MElement& element, 
		      const std::vector<double>& coef,
		      const fullVector<double>& uvw) const{

  // Get Basis Functions //
  fullMatrix<double>* fun = 
    localBasisScalar->getFunctions(element, uvw(0), uvw(1), uvw(2));

  const unsigned int nFun = fun->size1();
  
  // Interpolate (in Reference Place) //
  double val = 0; 

  for(unsigned int i = 0; i < nFun; i++)
    val += (*fun)(i, 0) * coef[i];

  // Return Interpolated Value //
  delete fun;
  return val;
}
