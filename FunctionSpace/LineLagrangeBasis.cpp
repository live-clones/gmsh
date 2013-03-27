#include "Exception.h"
#include "LineLagrangeBasis.h"

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
  lPoint = new fullMatrix<double>(linePoint(order));
}

LineLagrangeBasis::~LineLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
}

unsigned int LineLagrangeBasis::getTag(unsigned int order){
  unsigned int tag = nodalBasis::getTag(TYPE_LIN, order, false);

  if(tag)
    return tag;

  else
    throw Exception
      ("Can't instanciate an order %d Lagrangian Basis for a Line",
       order);
}

fullMatrix<double> LineLagrangeBasis::
linePoint(unsigned int order){
  fullMatrix<double> line(order + 1, 1);
  line(0 ,0) = 0;

  if(order > 0){
    line(0, 0) = -1.;
    line(1, 0) =  1.;

    double dd = 2. / order;

    for(unsigned int i = 2; i < order + 1; i++)
      line(i, 0) = -1. + dd * (i - 1);
  }

  return line;
}
