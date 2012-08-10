#include <vector>

#include "BasisVector.h"
#include "Mapper.h"
#include "FunctionSpaceEdge.h"

using namespace std;

FunctionSpaceEdge::FunctionSpaceEdge(const GroupOfElement& goe,
				     int order){
  // Build 1Form Basis //
  build(goe, 1, order); 
}
    
FunctionSpaceEdge::~FunctionSpaceEdge(void){
}

#include <cstdio>

fullVector<double> FunctionSpaceEdge::
interpolate(const MElement& element, 
	    const std::vector<double>& coef,
	    const fullVector<double>& xyz) const{
 
  MElement& eelement = 
    const_cast<MElement&>(element);
  
  const vector<vector<Polynomial> >& fun = 
    static_cast<const BasisVector&>(*basis).getBasis();
  
  const unsigned int nFun = fun.size();

  fullVector<double> val(3);

  fullMatrix<double>  invJac(3, 3);        
  eelement.getJacobian(xyz(0), xyz(1), xyz(2), invJac);
  invJac.invertInPlace();

  fullVector<double> origin(3);
  origin(0) = eelement.getVertex(0)->x();
  origin(1) = eelement.getVertex(0)->y();
  origin(2) = eelement.getVertex(0)->z();

  fullVector<double> uvw = Mapper::invMap(xyz, origin, invJac);
  
  printf("%g, %g, %g\n", uvw(0), uvw(1), uvw(2));
  
  //val(0) = 1; val(1) = 1; val(2) = 0;
  
  
  for(unsigned int i = 0; i < nFun; i++){
    fullVector<double> vi = 
      Mapper::grad(Polynomial::at(fun[i], uvw(0), uvw(1), uvw(2)),
		   invJac);
    
    vi.scale(coef[i]);
    val.axpy(vi, 1);
  }

  return val;
}
