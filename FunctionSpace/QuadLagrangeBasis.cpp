#include "QuadLagrangeBasis.h"
#include "QuadReferenceSpace.h"
#include "pointsGenerators.h"
#include "ElementType.h"

QuadLagrangeBasis::QuadLagrangeBasis(size_t order){
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
  lBasis = new polynomialBasis(ElementType::getTag(TYPE_QUA, order, false));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>(gmshGeneratePointsQuadrangle(order, false));

  // Reference Space //
  refSpace  = new QuadReferenceSpace;
  nRefSpace = getReferenceSpace().getNReferenceSpace();
}

QuadLagrangeBasis::~QuadLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
  delete refSpace;
}
