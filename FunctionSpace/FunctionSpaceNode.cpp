#include "FunctionSpaceNode.h"
#include "Polynomial.h"
#include "BasisScalar.h"
#include "Exception.h"

using namespace std;

FunctionSpaceNode::FunctionSpaceNode(const GroupOfElement& goe, int order):
FunctionSpace(goe, 0, order){
  // Just Call Super Constructor with basisType = 0
}


FunctionSpaceNode::~FunctionSpaceNode(void){
}

vector<double> FunctionSpaceNode::
interpolateAtNodes(const MElement& elem, 
		   const vector<double>& coef) const{
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

  // Init Vector
  vector<double> value(N);

  // Interpolate
  for(unsigned int n = 0; n < N; n++){
    const double x = node[n]->x();
    const double y = node[n]->y();
    const double z = node[n]->z();

    value[n] = 0;

    for(unsigned int i = 0; i < bS; i++)
      value[n] += fun[i].at(x, y, z) * coef[i];
  }

  return value;
}
