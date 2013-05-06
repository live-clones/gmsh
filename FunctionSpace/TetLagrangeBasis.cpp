#include "Exception.h"
#include "TetLagrangeBasis.h"
#include "pointsGenerators.h"

TetLagrangeBasis::TetLagrangeBasis(unsigned int order){
  // If order 0 (Nedelec): use order 1
  if(order == 0)
    order = 1;

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 3;

  nVertex   = 4;
  nEdge     = 6 * (order - 1);
  nFace     = 2 * (order - 1) * (order - 2);
  nCell     =     (order - 1) * (order - 2) * (order - 3) / 6;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Init polynomialBasis //
  lBasis = new polynomialBasis(getTag(order));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>
    (gmshGeneratePointsTetrahedron(order, false));
}

TetLagrangeBasis::~TetLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
}

unsigned int TetLagrangeBasis::getTag(unsigned int order){
  unsigned int tag = nodalBasis::getTag(TYPE_TET, order, false);

  if(tag)
    return tag;

  else
    throw Exception
      ("Can't instanciate an order %d Lagrangian Basis for a Tetrahedron",
       order);
}
