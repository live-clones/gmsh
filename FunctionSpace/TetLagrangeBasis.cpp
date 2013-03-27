#include "Exception.h"
#include "TetLagrangeBasis.h"

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
  lPoint = new fullMatrix<double>(tetPoint(order));
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

fullMatrix<double> TetLagrangeBasis::
tetPoint(unsigned int order){
  unsigned int nbPoints = (order + 1) * (order + 2) * (order + 3) / 6;
  fullMatrix<double> point(nbPoints, 3);

  double overOrder = (order == 0 ? 1. : 1. / order);

  point(0, 0) = 0.;
  point(0, 1) = 0.;
  point(0, 2) = 0.;

  if(order > 0){
    point(1, 0) = order;
    point(1, 1) = 0;
    point(1, 2) = 0;

    point(2, 0) = 0.;
    point(2, 1) = order;
    point(2, 2) = 0.;

    point(3, 0) = 0.;
    point(3, 1) = 0.;
    point(3, 2) = order;

    if(order > 1){
      for(unsigned int k = 0; k < (order - 1); k++){
        point(4 + k,                   0) = k + 1;
        point(4 +      order - 1  + k, 0) = order - 1 - k;
        point(4 + 2 * (order - 1) + k, 0) = 0.;
        point(4 + 3 * (order - 1) + k, 0) = 0.;
        point(4 + 4 * (order - 1) + k, 0) = 0.;
        point(4 + 5 * (order - 1) + k, 0) = k+1;

        point(4 + k,                   1) = 0.;
        point(4 +      order - 1  + k, 1) = k + 1;
        point(4 + 2 * (order - 1) + k, 1) = order - 1 - k;
        point(4 + 3 * (order - 1) + k, 1) = 0.;
        point(4 + 4 * (order - 1) + k, 1) = k+1;
        point(4 + 5 * (order - 1) + k, 1) = 0.;

        point(4 + k,                   2) = 0.;
        point(4 +      order - 1  + k, 2) = 0.;
        point(4 + 2 * (order - 1) + k, 2) = 0.;
        point(4 + 3 * (order - 1) + k, 2) = order - 1 - k;
        point(4 + 4 * (order - 1) + k, 2) = order - 1 - k;
        point(4 + 5 * (order - 1) + k, 2) = order - 1 - k;
      }

      if(order > 2){
        unsigned int ns = 4 + 6 * (order - 1);
        unsigned int nbdofface = nbdoftriangle(order - 3);

        double *u = new double[nbdofface];
        double *v = new double[nbdofface];
        double *w = new double[nbdofface];

        nodepositionface0(order - 3, u, v, w);

        // u-v plane

        for(unsigned int i = 0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3) + 1.;
          point(ns + i, 1) = v[i] * (order - 3) + 1.;
          point(ns + i, 2) = w[i] * (order - 3);
        }

        ns = ns + nbdofface;

        // u-w plane

        nodepositionface1(order - 3, u, v, w);

        for(unsigned int i=0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3) + 1.;
          point(ns + i, 1) = v[i] * (order - 3) ;
          point(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        // v-w plane

        ns = ns + nbdofface;

        nodepositionface2(order - 3, u, v, w);

        for(unsigned int i = 0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3);
          point(ns + i, 1) = v[i] * (order - 3) + 1.;
          point(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        // u-v-w plane

        ns = ns + nbdofface;

        nodepositionface3(order - 3, u, v, w);

        for(unsigned int i = 0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3) + 1.;
          point(ns + i, 1) = v[i] * (order - 3) + 1.;
          point(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        ns = ns + nbdofface;

        delete [] u;
        delete [] v;
        delete [] w;

        if(order > 3){
          fullMatrix<double> interior = tetPoint(order - 4);

          for(int k = 0; k < interior.size1(); k++){
            point(ns + k, 0) = 1. + interior(k, 0) * (order - 4);
            point(ns + k, 1) = 1. + interior(k, 1) * (order - 4);
            point(ns + k, 2) = 1. + interior(k, 2) * (order - 4);
          }
        }
      }
    }
  }

  point.scale(overOrder);
  return point;
}

unsigned int TetLagrangeBasis::nbdoftriangle(unsigned int order){
  return (order + 1) * (order + 2) / 2;
}

void TetLagrangeBasis::
nodepositionface0(unsigned int order, double *u, double *v, double *w){

  unsigned int ndofT = nbdoftriangle(order);

  if(order == 0){
    u[0] = 0.;
    v[0] = 0.;
    w[0] = 0.;
    return;
  }

  u[0]= 0.;    v[0]= 0.;    w[0] = 0.;
  u[1]= 0.;    v[1]= order; w[1] = 0.;
  u[2]= order; v[2]= 0.;    w[2] = 0.;

  // edges
  for(unsigned int k = 0; k < (order - 1); k++){
    u[3 + k] = 0.;
    v[3 + k] = k + 1;
    w[3 + k] = 0.;

    u[3 + order - 1 + k] = k + 1;
    v[3 + order - 1 + k] = order - 1 - k ;
    w[3 + order - 1 + k] = 0.;

    u[3 + 2 * (order - 1) + k] = order - 1 - k;
    v[3 + 2 * (order - 1) + k] = 0.;
    w[3 + 2 * (order - 1) + k] = 0.;
  }

  if(order > 2){
    unsigned int nbdoftemp = nbdoftriangle(order - 3);

    nodepositionface0(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order - 1)],
                      &w[3 + 3* (order - 1)]);

    for(unsigned int k = 0; k < nbdoftemp; k++){
      u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3);
    }
  }

  for(unsigned int k = 0; k < ndofT; k++){
    u[k] = u[k] / order;
    v[k] = v[k] / order;
    w[k] = w[k] / order;
  }
}

void TetLagrangeBasis::nodepositionface1
(unsigned int order, double *u, double *v, double *w){

  unsigned int ndofT = nbdoftriangle(order);

  if(order == 0){
    u[0] = 0.;
    v[0] = 0.;
    w[0] = 0.;
    return;
  }

  u[0] = 0.;    v[0]= 0.;  w[0] = 0.;
  u[1] = order; v[1]= 0.;  w[1] = 0.;
  u[2] = 0.;    v[2]= 0.;  w[2] = order;

  // edges
  for(unsigned int k = 0; k < (order - 1); k++){
    u[3 + k] = k + 1;
    v[3 + k] = 0.;
    w[3 + k] = 0.;

    u[3 + order - 1 + k] = order - 1 - k;
    v[3 + order - 1 + k] = 0.;
    w[3 + order - 1+ k ] = k + 1;

    u[3 + 2 * (order - 1) + k] = 0. ;
    v[3 + 2 * (order - 1) + k] = 0.;
    w[3 + 2 * (order - 1) + k] = order - 1 - k;
  }

  if(order > 2){
    unsigned int nbdoftemp = nbdoftriangle(order - 3);

    nodepositionface1(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order -1 )],
                      &w[3 + 3 * (order - 1)]);

    for(unsigned int k = 0; k < nbdoftemp; k++){
      u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3);
      w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
    }
  }

  for (unsigned int k = 0; k < ndofT; k++){
    u[k] = u[k] / order;
    v[k] = v[k] / order;
    w[k] = w[k] / order;
  }
}

void TetLagrangeBasis::
nodepositionface2(unsigned int order, double *u, double *v, double *w){

  unsigned int ndofT = nbdoftriangle(order);

  if(order == 0){
    u[0] = 0.;
    v[0] = 0.;
    w[0] = 0.;
    return;
  }

  u[0]= 0.; v[0]= 0.;    w[0] = 0.;
  u[1]= 0.; v[1]= 0.;    w[1] = order;
  u[2]= 0.; v[2]= order; w[2] = 0.;

  // edges
  for(unsigned int k = 0; k < (order - 1); k++){
    u[3 + k] = 0.;
    v[3 + k] = 0.;
    w[3 + k] = k + 1;

    u[3 + order - 1 + k] = 0.;
    v[3 + order - 1 + k] = k + 1;
    w[3 + order - 1 + k] = order - 1 - k;

    u[3 + 2 * (order - 1) + k] = 0.;
    v[3 + 2 * (order - 1) + k] = order - 1 - k;
    w[3 + 2 * (order - 1) + k] = 0.;
  }

  if(order > 2){
    unsigned int nbdoftemp = nbdoftriangle(order - 3);

    nodepositionface2(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order - 1)],
                      &w[3 + 3 * (order - 1)]);

    for(unsigned int k = 0; k < nbdoftemp; k++){
      u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3);
      v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
    }
  }

  for(unsigned int k = 0; k < ndofT; k++){
    u[k] = u[k] / order;
    v[k] = v[k] / order;
    w[k] = w[k] / order;
  }
}

void TetLagrangeBasis::
nodepositionface3(unsigned int order,  double *u,  double *v,  double *w){

  unsigned int ndofT = nbdoftriangle(order);

  if(order == 0){
    u[0] = 0.;
    v[0] = 0.;
    w[0] = 0.;
    return;
  }

  u[0]= 0.;    v[0]= 0.;    w[0] = order;
  u[1]= order; v[1]= 0.;    w[1] = 0.;
  u[2]= 0.;    v[2]= order; w[2] = 0.;

  // edges
  for(unsigned int k = 0; k < (order - 1); k++){
    u[3 + k] = k + 1;
    v[3 + k] = 0.;
    w[3 + k] = order - 1 - k;

    u[3 + order - 1 + k] = order - 1 - k;
    v[3 + order - 1 + k] = k + 1;
    w[3 + order - 1 + k] = 0.;

    u[3 + 2 * (order - 1) + k] = 0.;
    v[3 + 2 * (order - 1) + k] = order - 1 - k;
    w[3 + 2 * (order - 1) + k] = k + 1;
  }

  if(order > 2){
    unsigned int nbdoftemp = nbdoftriangle(order - 3);

    nodepositionface3(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order - 1)],
                       &w[3 + 3 * (order - 1)]);

    for(unsigned int k = 0; k < nbdoftemp; k++){
      u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
    }
  }

  for (unsigned int k = 0; k < ndofT; k++){
    u[k] = u[k] / order;
    v[k] = v[k] / order;
    w[k] = w[k] / order;
  }
}
