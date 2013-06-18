#include "Exception.h"
#include "QuadLagrangeBasis.h"
#include "pointsGenerators.h"
#include "ElementType.h"

QuadLagrangeBasis::QuadLagrangeBasis(unsigned int order){
  // If order 0 (Nedelec): use order 1
  if(order == 0)
    order = 1;

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 2;

  nVertex   = 4;
  nEdge     = 4 * (order - 1);
  nFace     =     (order - 1) * (order - 1);
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Init polynomialBasis //
  lBasis = new polynomialBasis(getTag(order));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>
    (gmshGeneratePointsQuadrangle(order, false));
}

QuadLagrangeBasis::~QuadLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
}

unsigned int QuadLagrangeBasis::getTag(unsigned int order){
  unsigned int tag = ElementType::getTag(TYPE_QUA, order, false);

  if(tag)
    return tag;

  else
    throw Exception
      ("Can't instanciate an order %d Lagrangian Basis for a Quadrangle",
       order);
}
