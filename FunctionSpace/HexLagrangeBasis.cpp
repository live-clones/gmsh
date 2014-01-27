#include "ElementType.h"
#include "GmshDefines.h"
#include "pointsGenerators.h"

#include "HexLagrangeBasis.h"

HexLagrangeBasis::HexLagrangeBasis(size_t order){
  // If order 0 (Nedelec): use order 1
  if(order == 0)
    order = 1;

  // Set Basis Type //
  this->order = order;

  type = TYPE_HEX;
  dim  = 3;

  nVertex   =  8;
  nEdge     = 12 * (order - 1);
  nFace     =  6 * (order - 1) * (order - 1);
  nCell     =      (order - 1) * (order - 1) * (order - 1);
  nFunction = nVertex + nEdge + nFace + nCell;

  // Init polynomialBasis //
  lBasis = new polynomialBasis(ElementType::getTag(TYPE_HEX, order, false));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>(gmshGeneratePointsHexahedron(order, false));
}

HexLagrangeBasis::~HexLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
}
