#include "FunctionSpaceNode.h"
#include "Polynomial.h"
#include "BasisScalar.h"
#include "fullMatrix.h"
#include "Mapper.h"
#include "Exception.h"

using namespace std;

FunctionSpaceNode::FunctionSpaceNode(const GroupOfElement& goe, int order):
FunctionSpaceScalar(goe, 0, order){
  // Just Call Super Constructor with basisType = 0
}


FunctionSpaceNode::~FunctionSpaceNode(void){
}

void FunctionSpaceNode::
interpolateAtNodes(const MElement& elem, 
		   const vector<double>& coef,
		   std::vector<double>& nodeValue) const{
  // Check
  unsigned int wS = coef.size();
  unsigned int bS = basis->getSize();

  if(wS < bS)
    throw Exception
      ("Not enough coefs for interpolation:\nBasis: %d -- coefs: %d",
       bS, wS);

  if(wS > bS)
    throw Exception
      ("Too much coefs for interpolation:\nBasis: %d -- coefs: %d",
       bS, wS);

  // Get Nodes
  MElement& element = const_cast<MElement&>(elem);

  vector<MVertex*> node;
  element.getVertices(node);
  unsigned int N = node.size();

  // Get Functions
  const vector<Polynomial>& fun = 
    static_cast<const BasisScalar*>(basis)->getBasis();

  // Init some stuff
  fullMatrix<double> invJac(3, 3);
  fullVector<double> xyz(3);
  fullVector<double> origin(3);
  
  origin(0) = node[0]->x();
  origin(1) = node[0]->y();
  origin(2) = node[0]->z();

  // Interpolate
  for(unsigned int n = 0; n < N; n++){
    // Map from physical to reference space 
    xyz(0) = node[n]->x();
    xyz(1) = node[n]->y();
    xyz(2) = node[n]->z();

    element.getJacobian(xyz(0), xyz(1), xyz(2), invJac);
    invJac.invertInPlace();
    
    const fullVector<double> uvw = 
      Mapper::invMap(xyz, origin, invJac);


    // Interpolate
    const int id = node[n]->getNum();

    for(unsigned int i = 0; i < bS; i++)
      nodeValue[id] += fun[i].at(uvw(0), uvw(1), uvw(2)) * coef[i];
  }
}
