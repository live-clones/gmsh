#include "Exception.h"
#include "TriLagrangeBasis.h"

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
  lBasis = new polynomialBasis(getTag(order));

  // Init Lagrange Point //
  lPoint = new fullMatrix<double>(triPoint(order));
}

TriLagrangeBasis::~TriLagrangeBasis(void){
  delete lBasis;
  delete lPoint;
}

unsigned int TriLagrangeBasis::getTag(unsigned int order){
  unsigned int tag = nodalBasis::getTag(TYPE_TRI, order, false);

  if(tag)
    return tag;

  else
    throw Exception
      ("Can't instanciate an order %d Lagrangian Basis for a Triangle",
       order);
}

fullMatrix<double> TriLagrangeBasis::
triPoint(unsigned int order){
  unsigned int       nbPoints = (order + 1) * (order + 2) / 2;
  fullMatrix<double> point(nbPoints, 3);

  point(0, 0) = 0;
  point(0, 1) = 0;
  point(0, 2) = 0;

  if(order > 0){
    double dd = 1. / order;

    point(1, 0) = 1;
    point(1, 1) = 0;
    point(1, 2) = 0;

    point(2, 0) = 0;
    point(2, 1) = 1;
    point(2, 2) = 0;

    unsigned int index = 3;

    if(order > 1){
      double ksi = 0;
      double eta = 0;

      for(unsigned int i = 0; i < order - 1; i++, index++){
        ksi += dd;

        point(index, 0) = ksi;
        point(index, 1) = eta;
        point(index, 2) = 0;
      }

      ksi = 1.;

      for(unsigned int i = 0; i < order - 1; i++, index++){
        ksi -= dd;
        eta += dd;

        point(index, 0) = ksi;
        point(index, 1) = eta;
        point(index, 2) = 0;
      }

      eta = 1.;
      ksi = 0.;

      for(unsigned int i = 0; i < order - 1; i++, index++){
        eta -= dd;

        point(index, 0) = ksi;
        point(index, 1) = eta;
        point(index, 2) = 0;
      }

      if(order > 2){
        fullMatrix<double> inner = triPoint(order - 3);

	inner.scale(1. - 3. * dd);
        inner.add(dd);
        point.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }

  return point;
}
