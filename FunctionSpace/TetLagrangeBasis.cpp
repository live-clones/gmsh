#include "ElementType.h"
#include "GmshDefines.h"
#include "pointsGenerators.h"

#include "TetLagrangeBasis.h"

TetLagrangeBasis::TetLagrangeBasis(size_t order){
  // If order 0 (Nedelec): use order 1
  if(order == 0)
    order = 1;

  // Set Basis Type //
  this->order = order;

  type = TYPE_TET;
  dim  = 3;

  nVertex   = 4;
  nEdge     = 6 * (order - 1);
  nFace     = 2 * (order - 1) * (order - 2);
  nCell     =     (order - 1) * (order - 2) * (order - 3) / 6;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Init polynomialBasis //
  lBasis = new polynomialBasis(ElementType::getTag(TYPE_TET, order, false));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>(gmshGeneratePointsTetrahedron(order, false));
}

TetLagrangeBasis::~TetLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
}
