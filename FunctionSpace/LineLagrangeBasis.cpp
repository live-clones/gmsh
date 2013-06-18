#include "Exception.h"
#include "LineLagrangeBasis.h"
#include "pointsGenerators.h"
#include "ElementType.h"

LineLagrangeBasis::LineLagrangeBasis(unsigned int order){
  // If order 0 (Nedelec): use order 1
  if(order == 0)
    order = 1;

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 1;

  nVertex   = 2;
  nEdge     = (order - 1);
  nFace     = 0;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Init polynomialBasis //
  lBasis = new polynomialBasis(getTag(order));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>
    (gmshGeneratePointsLine(order));
}

LineLagrangeBasis::~LineLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
}

unsigned int LineLagrangeBasis::getTag(unsigned int order){
  unsigned int tag = ElementType::getTag(TYPE_LIN, order, false);

  if(tag)
    return tag;

  else
    throw Exception
      ("Can't instanciate an order %d Lagrangian Basis for a Line",
       order);
}
