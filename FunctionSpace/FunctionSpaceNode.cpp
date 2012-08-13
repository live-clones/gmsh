#include <vector>

#include "BasisScalar.h"
#include "Mapper.h"
#include "FunctionSpaceNode.h"

using namespace std;

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

  // Const Cast For MElement //
  MElement& eelement = 
    const_cast<MElement&>(element);
  
  // Get Basis Functions //
 const vector<Polynomial>& fun = getBasis(element).getFunctions();
  const unsigned int nFun       = fun.size();
  
  // Get Jacobian //  
  fullMatrix<double> invJac(3, 3);        
  eelement.getJacobian(xyz(0), xyz(1), xyz(2), invJac);

  invJac.invertInPlace();

  // Get First Vertex of Element (Physical Space) //
  fullVector<double> origin(3);
  origin(0) = eelement.getVertex(0)->x();
  origin(1) = eelement.getVertex(0)->y();
  origin(2) = eelement.getVertex(0)->z();

  // Map XYZ to Reference Plane (UVW) //
  fullVector<double> uvw = Mapper::invMap(xyz, origin, invJac);

  // Interpolate (in Reference Place) //
  double val = 0; 

  for(unsigned int i = 0; i < nFun; i++)
    val += 
      fun[i].at(uvw(0), uvw(1), uvw(2)) * coef[i];

  // Return Interpolated Value //
  return val;
}
