#include "TriLagrangeBasis.h"
#include "pointsGenerators.h"
//#include "TriReferenceSpace.h"
#include "ElementType.h"

TriLagrangeBasis::TriLagrangeBasis(unsigned int order){
  // If order 0 (Nedelec): use order 1
  if(order == 0)
    order = 1;

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 2;

  nVertex   = 3;
  nEdge     = 3 * (order - 1);
  nFace     =     (order - 1) * (order - 2) / 2;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Init polynomialBasis //
  lBasis = new polynomialBasis(ElementType::getTag(TYPE_TRI, order, false));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>
    (gmshGeneratePointsTriangle(order, false));

  // ReferenceSpace //
  // refSpace = new TriReferenceSpace;
  //  refSpace = new TriLagrangeReferenceSpace(order);
  //  std::cout << refSpace->toString() << std::endl;
}

TriLagrangeBasis::~TriLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
  // delete refSpace;
}
