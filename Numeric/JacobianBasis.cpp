// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "JacobianBasis.h"
#include <vector>
#include "polynomialBasis.h"

// Bezier Exposants
static fullMatrix<double> generate1DExposants(int order)
{
  fullMatrix<double> exposants(order + 1, 1);
  exposants(0, 0) = 0;
  if (order > 0) {
    exposants(1, 0) = order;
    for (int i = 2; i < order + 1; i++) exposants(i, 0) = i - 1;
  }

  return exposants;
}

static fullMatrix<double> generateExposantsTriangle(int order)
{
  int nbPoints = (order + 1) * (order + 2) / 2;
  fullMatrix<double> exposants(nbPoints, 2);

  exposants(0, 0) = 0;
  exposants(0, 1) = 0;

  if (order > 0) {
    exposants(1, 0) = order;
    exposants(1, 1) = 0;
    exposants(2, 0) = 0;
    exposants(2, 1) = order;

    if (order > 1) {
      int index = 3, ksi = 0, eta = 0;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi++;
        exposants(index, 0) = ksi;
        exposants(index, 1) = eta;
      }

      ksi = order;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi--;
        eta++;
        exposants(index, 0) = ksi;
        exposants(index, 1) = eta;
      }

      eta = order;
      ksi = 0;

      for (int i = 0; i < order - 1; i++, index++) {
        eta--;
        exposants(index, 0) = ksi;
        exposants(index, 1) = eta;
      }

      if (order > 2) {
        fullMatrix<double> inner = generateExposantsTriangle(order - 3);
        inner.add(1);
        exposants.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }

  return exposants;
}
static fullMatrix<double> generateExposantsQuad(int order)
{
  int nbPoints = (order+1)*(order+1);
  fullMatrix<double> exposants(nbPoints, 2);

  exposants(0, 0) = 0;
  exposants(0, 1) = 0;

  if (order > 0) {
    exposants(1, 0) = order;
    exposants(1, 1) = 0;
    exposants(2, 0) = order;
    exposants(2, 1) = order;
    exposants(3, 0) = 0;
    exposants(3, 1) = order;

    if (order > 1) {
      int index = 4;
      const static int edges[4][2]={{0,1},{1,2},{2,3},{3,0}};
      for (int iedge=0; iedge<4; iedge++) {
        int p0 = edges[iedge][0];
        int p1 = edges[iedge][1];
        for (int i = 1; i < order; i++, index++) {
          exposants(index, 0) = exposants(p0, 0) + i*(exposants(p1,0)-exposants(p0,0))/order;
          exposants(index, 1) = exposants(p0, 1) + i*(exposants(p1,1)-exposants(p0,1))/order;
        }
      }
      if (order > 2) {
        fullMatrix<double> inner = generateExposantsQuad(order - 2);
        inner.add(1);
        exposants.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }

  return exposants;
}
static int nbdoftriangle(int order) { return (order + 1) * (order + 2) / 2; }

static void nodepositionface0(int order, double *u, double *v, double *w)
{ // uv surface - orientation v0-v2-v1
  int ndofT = nbdoftriangle(order);
  if (order == 0) { u[0] = 0.; v[0] = 0.; w[0] = 0.; return; }

  u[0]= 0.;    v[0]= 0.;    w[0] = 0.;
  u[1]= 0.;    v[1]= order; w[1] = 0.;
  u[2]= order; v[2]= 0.;    w[2] = 0.;

  // edges
  for (int k = 0; k < (order - 1); k++){
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

  if (order > 2){
    int nbdoftemp = nbdoftriangle(order - 3);
    nodepositionface0(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order - 1)],
                      &w[3 + 3* (order - 1)]);
    for (int k = 0; k < nbdoftemp; k++){
      u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3);
    }
  }
  for (int k = 0; k < ndofT; k++){
    u[k] = u[k] / order;
    v[k] = v[k] / order;
    w[k] = w[k] / order;
  }
}

static void nodepositionface1(int order, double *u, double *v, double *w)
{ // uw surface - orientation v0-v1-v3
  int ndofT = nbdoftriangle(order);
  if (order == 0) { u[0] = 0.; v[0] = 0.; w[0] = 0.; return; }

  u[0] = 0.;    v[0]= 0.;  w[0] = 0.;
  u[1] = order; v[1]= 0.;  w[1] = 0.;
  u[2] = 0.;    v[2]= 0.;  w[2] = order;
  // edges
  for (int k = 0; k < (order - 1); k++){
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
  if (order > 2){
    int nbdoftemp = nbdoftriangle(order - 3);
    nodepositionface1(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order -1 )],
      &w[3 + 3 * (order - 1)]);
    for (int k = 0; k < nbdoftemp; k++){
      u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
      v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3);
      w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
    }
  }
  for (int k = 0; k < ndofT; k++){
    u[k] = u[k] / order;
    v[k] = v[k] / order;
    w[k] = w[k] / order;
  }
}

static void nodepositionface2(int order, double *u, double *v, double *w)
{ // vw surface - orientation v0-v3-v2
   int ndofT = nbdoftriangle(order);
   if (order == 0) { u[0] = 0.; v[0] = 0.; return; }

   u[0]= 0.; v[0]= 0.;    w[0] = 0.;
   u[1]= 0.; v[1]= 0.;    w[1] = order;
   u[2]= 0.; v[2]= order; w[2] = 0.;
   // edges
   for (int k = 0; k < (order - 1); k++){

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
   if (order > 2){
     int nbdoftemp = nbdoftriangle(order - 3);
     nodepositionface2(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order - 1)],
                       &w[3 + 3 * (order - 1)]);
     for (int k = 0; k < nbdoftemp; k++){
       u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3);
       v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
       w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
     }
   }
   for (int k = 0; k < ndofT; k++){
     u[k] = u[k] / order;
     v[k] = v[k] / order;
     w[k] = w[k] / order;
   }
}

static void nodepositionface3(int order,  double *u,  double *v,  double *w)
{ // uvw surface  - orientation v3-v1-v2
   int ndofT = nbdoftriangle(order);
   if (order == 0) { u[0] = 0.; v[0] = 0.; w[0] = 0.; return; }

   u[0]= 0.;    v[0]= 0.;    w[0] = order;
   u[1]= order; v[1]= 0.;    w[1] = 0.;
   u[2]= 0.;    v[2]= order; w[2] = 0.;
   // edges
   for (int k = 0; k < (order - 1); k++){

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
   if (order > 2){
     int nbdoftemp = nbdoftriangle(order - 3);
     nodepositionface3(order - 3, &u[3 + 3 * (order - 1)], &v[3 + 3 * (order - 1)],
                       &w[3 + 3 * (order - 1)]);
     for (int k = 0; k < nbdoftemp; k++){
       u[3 + k + 3 * (order - 1)] = u[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
       v[3 + k + 3 * (order - 1)] = v[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
       w[3 + k + 3 * (order - 1)] = w[3 + k + 3 * (order - 1)] * (order - 3) + 1.;
     }
   }
   for (int k = 0; k < ndofT; k++){
     u[k] = u[k] / order;
     v[k] = v[k] / order;
     w[k] = w[k] / order;
   }
}

static fullMatrix<double> generateExposantsTetrahedron(int order)
{
  int nbPoints = (order + 1) * (order + 2) * (order + 3) / 6;

  fullMatrix<double> exposants(nbPoints, 3);

  exposants(0, 0) = 0;
  exposants(0, 1) = 0;
  exposants(0, 2) = 0;

  if (order > 0) {
    exposants(1, 0) = order;
    exposants(1, 1) = 0;
    exposants(1, 2) = 0;

    exposants(2, 0) = 0;
    exposants(2, 1) = order;
    exposants(2, 2) = 0;

    exposants(3, 0) = 0;
    exposants(3, 1) = 0;
    exposants(3, 2) = order;

    // edges e5 and e6 switched in original version, opposite direction
    // the template has been defined in table edges_tetra and faces_tetra (MElement.h)

    if (order > 1) {
      for (int k = 0; k < (order - 1); k++) {
        exposants(4 + k, 0) = k + 1;
        exposants(4 +      order - 1  + k, 0) = order - 1 - k;
        exposants(4 + 2 * (order - 1) + k, 0) = 0;
        exposants(4 + 3 * (order - 1) + k, 0) = 0;
        // exposants(4 + 4 * (order - 1) + k, 0) = order - 1 - k;
        // exposants(4 + 5 * (order - 1) + k, 0) = 0.;
        exposants(4 + 4 * (order - 1) + k, 0) = 0;
        exposants(4 + 5 * (order - 1) + k, 0) = k+1;

        exposants(4 + k, 1) = 0;
        exposants(4 +      order - 1  + k, 1) = k + 1;
        exposants(4 + 2 * (order - 1) + k, 1) = order - 1 - k;
        exposants(4 + 3 * (order - 1) + k, 1) = 0;
        //         exposants(4 + 4 * (order - 1) + k, 1) = 0.;
        //         exposants(4 + 5 * (order - 1) + k, 1) = order - 1 - k;
        exposants(4 + 4 * (order - 1) + k, 1) = k+1;
        exposants(4 + 5 * (order - 1) + k, 1) = 0;

        exposants(4 + k, 2) = 0;
        exposants(4 +      order - 1  + k, 2) = 0;
        exposants(4 + 2 * (order - 1) + k, 2) = 0;
        exposants(4 + 3 * (order - 1) + k, 2) = order - 1 - k;
        exposants(4 + 4 * (order - 1) + k, 2) = order - 1 - k;
        exposants(4 + 5 * (order - 1) + k, 2) = order - 1 - k;
      }

      if (order > 2) {
        int ns = 4 + 6 * (order - 1);
        int nbdofface = nbdoftriangle(order - 3);

        double *u = new double[nbdofface];
        double *v = new double[nbdofface];
        double *w = new double[nbdofface];

        nodepositionface0(order - 3, u, v, w);

        // u-v plane

        for (int i = 0; i < nbdofface; i++){
          exposants(ns + i, 0) = u[i] * (order - 3) + 1;
          exposants(ns + i, 1) = v[i] * (order - 3) + 1;
          exposants(ns + i, 2) = w[i] * (order - 3);
        }

        ns = ns + nbdofface;

        // u-w plane

        nodepositionface1(order - 3, u, v, w);

        for (int i=0; i < nbdofface; i++){
          exposants(ns + i, 0) = u[i] * (order - 3) + 1;
          exposants(ns + i, 1) = v[i] * (order - 3) ;
          exposants(ns + i, 2) = w[i] * (order - 3) + 1;
        }

        // v-w plane

        ns = ns + nbdofface;

        nodepositionface2(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          exposants(ns + i, 0) = u[i] * (order - 3);
          exposants(ns + i, 1) = v[i] * (order - 3) + 1;
          exposants(ns + i, 2) = w[i] * (order - 3) + 1;
        }

        // u-v-w plane

        ns = ns + nbdofface;

        nodepositionface3(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          exposants(ns + i, 0) = u[i] * (order - 3) + 1;
          exposants(ns + i, 1) = v[i] * (order - 3) + 1;
          exposants(ns + i, 2) = w[i] * (order - 3) + 1;
        }

        ns = ns + nbdofface;

        delete [] u;
        delete [] v;
        delete [] w;

        if (order > 3) {

          fullMatrix<double> interior = generateExposantsTetrahedron(order - 4);
          for (int k = 0; k < interior.size1(); k++) {
            exposants(ns + k, 0) = 1 + interior(k, 0);
            exposants(ns + k, 1) = 1 + interior(k, 1);
            exposants(ns + k, 2) = 1 + interior(k, 2);
          }
        }
      }
    }
  }

  return exposants;
}

static fullMatrix<double> generateExposantsPrism(int order)
{
//  int nbMonomials = (order + 1) * (order + 1) * (order + 2) / 2;
//
//  fullMatrix<double> monomials(nbMonomials, 3);
//  int index = 0;
//  fullMatrix<double> lineMonoms = generate1DMonomials(order);
//  fullMatrix<double> triMonoms = generateExposantsTriangle(order);
//  // store monomials in right order
//  for (int currentOrder = 0; currentOrder <= order; currentOrder++) {
//    int orderT = currentOrder, orderL = currentOrder;
//    for (orderL = 0; orderL < currentOrder; orderL++) {
//      // do all permutations of monoms for orderL, orderT
//      int iL = orderL;
//      for (int iT = (orderT)*(orderT+1)/2; iT < (orderT+1)*(orderT+2)/2 ;iT++) {
//        monomials(index,0) = triMonoms(iT,0);
//        monomials(index,1) = triMonoms(iT,1);
//        monomials(index,2) = lineMonoms(iL,0);
//        index ++;
//      }
//    }
//    orderL = currentOrder;
//    for (orderT = 0; orderT <= currentOrder; orderT++) {
//      int iL = orderL;
//      for (int iT = (orderT)*(orderT+1)/2; iT < (orderT+1)*(orderT+2)/2 ;iT++) {
//        monomials(index,0) = triMonoms(iT,0);
//        monomials(index,1) = triMonoms(iT,1);
//        monomials(index,2) = lineMonoms(iL,0);
//        index ++;
//      }
//    }    
//  }
////   monomials.print("Pri monoms");
//  return monomials;

  //const double prism18Pts[18][3] = {
 //   {0, 0, -1}, // 0
 //   {1, 0, -1}, // 1
 //   {0, 1, -1}, // 2
 //   {0, 0, 1},  // 3
 //   {1, 0, 1},  // 4
 //   {0, 1, 1},  // 5
 //   {0.5, 0, -1},  // 6
 //   {0, 0.5, -1},  // 7
 //   {0, 0, 0},  // 8
 //   {0.5, 0.5, -1},  // 9
 //   {1, 0, 0},  // 10
 //   {0, 1, 0},  // 11
 //   {0.5, 0, 1},  // 12
 //   {0, 0.5, 1},  // 13
 //   {0.5, 0.5, 1},  // 14
 //   {0.5, 0, 0},  // 15
 //   {0, 0.5, 0},  // 16
 //   {0.5, 0.5, 0},  // 17
 // };

  int nbPoints = (order + 1)*(order + 1)*(order + 2)/2;
  fullMatrix<double> exposants(nbPoints, 3);

  int index = 0;
  fullMatrix<double> triExp = generateExposantsTriangle(order);
  fullMatrix<double> lineExp = generate1DExposants(order);

 /* if (order == 2)
    for (int i =0; i<18; i++)
      for (int j=0; j<3;j++)
        exposants(i,j) = prism18Pts[i][j];
  else*/
  {
    for (int i = 0; i < 3; i++) {
      exposants(index,0) = triExp(i,0);
      exposants(index,1) = triExp(i,1);
      exposants(index,2) = lineExp(0,0);
      index ++;
      exposants(index,0) = triExp(i,0);
      exposants(index,1) = triExp(i,1);
      exposants(index,2) = lineExp(1,0);
      index ++;
    }
    for (int i = 3; i < triExp.size1(); i++) {
      exposants(index,0) = triExp(i,0);
      exposants(index,1) = triExp(i,1);
      exposants(index,2) = lineExp(0,0);
      index ++;
      exposants(index,0) = triExp(i,0);
      exposants(index,1) = triExp(i,1);
      exposants(index,2) = lineExp(1,0);
      index ++;
    }
    for (int j = 2; j <lineExp.size1() ; j++) {
      for (int i = 0; i < triExp.size1(); i++) {
        exposants(index,0) = triExp(i,0);
        exposants(index,1) = triExp(i,1);
        exposants(index,2) = lineExp(j,0);
        index ++;
      }
    }
  }

  return exposants;
}

// Sampling Points
static fullMatrix<double> generate1DPoints(int order)
{
  fullMatrix<double> line(order + 1, 1);
  line(0,0) = 0;
  if (order > 0) {
    line(0, 0) = 0.;
    line(1, 0) = 1.;
    double dd = 1. / order;
    for (int i = 2; i < order + 1; i++) line(i, 0) = dd * (i - 1);
  }

  return line;
}

static fullMatrix<double> gmshGeneratePointsTetrahedron(int order, bool serendip)
{
  int nbPoints =
    (serendip ?
     4 +  6 * std::max(0, order - 1) + 4 * std::max(0, (order - 2) * (order - 1) / 2) :
     (order + 1) * (order + 2) * (order + 3) / 6);

  fullMatrix<double> point(nbPoints, 3);

  double overOrder = (order == 0 ? 1. : 1. / order);

  point(0, 0) = 0.;
  point(0, 1) = 0.;
  point(0, 2) = 0.;

  if (order > 0) {
    point(1, 0) = order;
    point(1, 1) = 0;
    point(1, 2) = 0;

    point(2, 0) = 0.;
    point(2, 1) = order;
    point(2, 2) = 0.;

    point(3, 0) = 0.;
    point(3, 1) = 0.;
    point(3, 2) = order;

    // edges e5 and e6 switched in original version, opposite direction
    // the template has been defined in table edges_tetra and faces_tetra (MElement.h)

    if (order > 1) {
      for (int k = 0; k < (order - 1); k++) {
        point(4 + k, 0) = k + 1;
        point(4 +      order - 1  + k, 0) = order - 1 - k;
        point(4 + 2 * (order - 1) + k, 0) = 0.;
        point(4 + 3 * (order - 1) + k, 0) = 0.;
        // point(4 + 4 * (order - 1) + k, 0) = order - 1 - k;
        // point(4 + 5 * (order - 1) + k, 0) = 0.;
        point(4 + 4 * (order - 1) + k, 0) = 0.;
        point(4 + 5 * (order - 1) + k, 0) = k+1;

        point(4 + k, 1) = 0.;
        point(4 +      order - 1  + k, 1) = k + 1;
        point(4 + 2 * (order - 1) + k, 1) = order - 1 - k;
        point(4 + 3 * (order - 1) + k, 1) = 0.;
        //         point(4 + 4 * (order - 1) + k, 1) = 0.;
        //         point(4 + 5 * (order - 1) + k, 1) = order - 1 - k;
        point(4 + 4 * (order - 1) + k, 1) = k+1;
        point(4 + 5 * (order - 1) + k, 1) = 0.;

        point(4 + k, 2) = 0.;
        point(4 +      order - 1  + k, 2) = 0.;
        point(4 + 2 * (order - 1) + k, 2) = 0.;
        point(4 + 3 * (order - 1) + k, 2) = order - 1 - k;
        point(4 + 4 * (order - 1) + k, 2) = order - 1 - k;
        point(4 + 5 * (order - 1) + k, 2) = order - 1 - k;
      }

      if (order > 2) {
        int ns = 4 + 6 * (order - 1);
        int nbdofface = nbdoftriangle(order - 3);

        double *u = new double[nbdofface];
        double *v = new double[nbdofface];
        double *w = new double[nbdofface];

        nodepositionface0(order - 3, u, v, w);

        // u-v plane

        for (int i = 0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3) + 1.;
          point(ns + i, 1) = v[i] * (order - 3) + 1.;
          point(ns + i, 2) = w[i] * (order - 3);
        }

        ns = ns + nbdofface;

        // u-w plane

        nodepositionface1(order - 3, u, v, w);

        for (int i=0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3) + 1.;
          point(ns + i, 1) = v[i] * (order - 3) ;
          point(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        // v-w plane

        ns = ns + nbdofface;

        nodepositionface2(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3);
          point(ns + i, 1) = v[i] * (order - 3) + 1.;
          point(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        // u-v-w plane

        ns = ns + nbdofface;

        nodepositionface3(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          point(ns + i, 0) = u[i] * (order - 3) + 1.;
          point(ns + i, 1) = v[i] * (order - 3) + 1.;
          point(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        ns = ns + nbdofface;

        delete [] u;
        delete [] v;
        delete [] w;

        if (!serendip && order > 3) {

          fullMatrix<double> interior = gmshGeneratePointsTetrahedron(order - 4, false);
          for (int k = 0; k < interior.size1(); k++) {
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

static fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip)
{
  int nbPoints = serendip ? 3 * order : (order + 1) * (order + 2) / 2;
  fullMatrix<double> point(nbPoints, 2);

  point(0, 0) = 0;
  point(0, 1) = 0;

  if (order > 0) {
    double dd = 1. / order;

    point(1, 0) = 1;
    point(1, 1) = 0;
    point(2, 0) = 0;
    point(2, 1) = 1;

    int index = 3;

    if (order > 1) {

      double ksi = 0;
      double eta = 0;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi += dd;
        point(index, 0) = ksi;
        point(index, 1) = eta;
      }

      ksi = 1.;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi -= dd;
        eta += dd;
        point(index, 0) = ksi;
        point(index, 1) = eta;
      }

      eta = 1.;
      ksi = 0.;

      for (int i = 0; i < order - 1; i++, index++) {
        eta -= dd;
        point(index, 0) = ksi;
        point(index, 1) = eta;
      }

      if (order > 2 && !serendip) {
        fullMatrix<double> inner = gmshGeneratePointsTriangle(order - 3, serendip);
        inner.scale(1. - 3. * dd);
        inner.add(dd);
        point.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }
  return point;
}

static fullMatrix<double> generatePointsPrism(int order, bool serendip)
{
  const double prism18Pts[18][3] = {
    {0, 0, 0}, // 0
    {1, 0, 0}, // 1
    {0, 1, 0}, // 2
    {0, 0, 1},  // 3
    {1, 0, 1},  // 4
    {0, 1, 1},  // 5
    {.5, 0, 0},  // 6
    {0, .5, 0},  // 7
    {0, 0, .5},  // 8
    {.5, .5, 0},  // 9
    {1, 0, .5},  // 10
    {0, 1, .5},  // 11
    {.5, 0, 1},  // 12
    {0, .5, 1},  // 13
    {.5, .5, 1},  // 14
    {.5, 0, .5},  // 15
    {0, .5, .5},  // 16
    {.5, .5, .5},  // 17
  };

  int nbPoints = (order + 1)*(order + 1)*(order + 2)/2;
  fullMatrix<double> point(nbPoints, 3);

  int index = 0;

  if (order == 2)
    for (int i =0; i<18; i++)
      for (int j=0; j<3;j++)
        point(i,j) = prism18Pts[i][j];
  else {
    fullMatrix<double> triPoints = gmshGeneratePointsTriangle(order,false);
    fullMatrix<double> linePoints = generate1DPoints(order);
    for (int j = 0; j <linePoints.size1() ; j++) {
      for (int i = 0; i < triPoints.size1(); i++) {
        point(index,0) = triPoints(i,0);
        point(index,1) = triPoints(i,1);
        point(index,2) = linePoints(j,0);
        index ++;
      }
    }
  }
  return point;
}

static fullMatrix<double> generatePointsQuad(int order, bool serendip)
{
  int nbPoints = serendip ? order*4 : (order+1)*(order+1);
  fullMatrix<double> point(nbPoints, 2);

  if (order > 0) {
    point(0, 0) = 0;
    point(0, 1) = 0;
    point(1, 0) = 1;
    point(1, 1) = 0;
    point(2, 0) = 1;
    point(2, 1) = 1;
    point(3, 0) = 0;
    point(3, 1) = 1;

    if (order > 1) {
      int index = 4;
      const static int edges[4][2]={{0,1},{1,2},{2,3},{3,0}};
      for (int iedge=0; iedge<4; iedge++) {
        int p0 = edges[iedge][0];
        int p1 = edges[iedge][1];
        for (int i = 1; i < order; i++, index++) {
          point(index, 0) = point(p0, 0) + i*(point(p1,0)-point(p0,0))/order;
          point(index, 1) = point(p0, 1) + i*(point(p1,1)-point(p0,1))/order;
        }
      }
      if (order > 2 && !serendip) {
        fullMatrix<double> inner = generatePointsQuad(order - 2, false);
        inner.scale(1. - 2./order);
        point.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }
  else {
    point(0, 0) = 0;
    point(0, 1) = 0;
  }
  return point;
}

// Sub Control Points
static std::vector< fullMatrix<double> > generateSubPointsLine(int order)
{
  std::vector< fullMatrix<double> > subPoints(2);
  fullMatrix<double> prox;
  
  subPoints[0] = generate1DPoints(order);
  subPoints[0].scale(.5);

  subPoints[1].copy(subPoints[0]);
  subPoints[1].add(.5);

  return subPoints;
}

static std::vector< fullMatrix<double> > generateSubPointsTriangle(int order)
{
  std::vector< fullMatrix<double> > subPoints(4);
  fullMatrix<double> prox;
  
  subPoints[0] = gmshGeneratePointsTriangle(order, false);
  subPoints[0].scale(.5);

  subPoints[1].copy(subPoints[0]);
  prox.setAsProxy(subPoints[1], 0, 1);
  prox.add(.5);

  subPoints[2].copy(subPoints[0]);
  prox.setAsProxy(subPoints[2], 1, 1);
  prox.add(.5);

  subPoints[3].copy(subPoints[0]);
  subPoints[3].scale(-1.);
  subPoints[3].add(.5);

  return subPoints;
}

static std::vector< fullMatrix<double> > generateSubPointsTetrahedron(int order)
{
  std::vector< fullMatrix<double> > subPoints(8);
  fullMatrix<double> prox1;
  fullMatrix<double> prox2;
  
  subPoints[0] = gmshGeneratePointsTetrahedron(order, false);
  subPoints[0].scale(.5);

  subPoints[1].copy(subPoints[0]);
  prox1.setAsProxy(subPoints[1], 0, 1);
  prox1.add(.5);

  subPoints[2].copy(subPoints[0]);
  prox1.setAsProxy(subPoints[2], 1, 1);
  prox1.add(.5);

  subPoints[3].copy(subPoints[0]);
  prox1.setAsProxy(subPoints[3], 2, 1);
  prox1.add(.5);

  // u := .5-u-w
  // v := .5-v-w
  // w := w
  subPoints[4].copy(subPoints[0]);
  prox1.setAsProxy(subPoints[4], 0, 2);
  prox1.scale(-1.);
  prox1.add(.5);
  prox1.setAsProxy(subPoints[4], 0, 1);
  prox2.setAsProxy(subPoints[4], 2, 1);
  prox1.add(prox2, -1.);
  prox1.setAsProxy(subPoints[4], 1, 1);
  prox1.add(prox2, -1.);

  // u := u
  // v := .5-v
  // w := w+v
  subPoints[5].copy(subPoints[0]);
  prox1.setAsProxy(subPoints[5], 2, 1);
  prox2.setAsProxy(subPoints[5], 1, 1);
  prox1.add(prox2);
  prox2.scale(-1.);
  prox2.add(.5);

  // u := .5-u
  // v := v
  // w := w+u
  subPoints[6].copy(subPoints[0]);
  prox1.setAsProxy(subPoints[6], 2, 1);
  prox2.setAsProxy(subPoints[6], 0, 1);
  prox1.add(prox2);
  prox2.scale(-1.);
  prox2.add(.5);

  // u := u+w
  // v := v+w
  // w := .5-w
  subPoints[7].copy(subPoints[0]);
  prox1.setAsProxy(subPoints[7], 0, 1);
  prox2.setAsProxy(subPoints[7], 2, 1);
  prox1.add(prox2);
  prox1.setAsProxy(subPoints[7], 1, 1);
  prox1.add(prox2);
  prox2.scale(-1.);
  prox2.add(.5);


  return subPoints;
}

static std::vector< fullMatrix<double> > generateSubPointsQuad(int order)
{
  std::vector< fullMatrix<double> > subPoints(4);
  fullMatrix<double> prox;
  
  subPoints[0] = generatePointsQuad(order, false);
  subPoints[0].scale(.5);

  subPoints[1].copy(subPoints[0]);
  prox.setAsProxy(subPoints[1], 0, 1);
  prox.add(.5);

  subPoints[2].copy(subPoints[0]);
  prox.setAsProxy(subPoints[2], 1, 1);
  prox.add(.5);

  subPoints[3].copy(subPoints[1]);
  prox.setAsProxy(subPoints[3], 1, 1);
  prox.add(.5);

  return subPoints;
}

static std::vector< fullMatrix<double> > generateSubPointsPrism(int order)
{
  std::vector< fullMatrix<double> > subPoints(8);
  fullMatrix<double> prox;
  
  subPoints[0] = generatePointsPrism(order, false);
  subPoints[0].scale(.5);

  subPoints[1].copy(subPoints[0]);
  prox.setAsProxy(subPoints[1], 0, 1);
  prox.add(.5);

  subPoints[2].copy(subPoints[0]);
  prox.setAsProxy(subPoints[2], 1, 1);
  prox.add(.5);

  subPoints[3].copy(subPoints[0]);
  prox.setAsProxy(subPoints[3], 0, 2);
  prox.scale(-1.);
  prox.add(.5);

  subPoints[4].copy(subPoints[0]);
  prox.setAsProxy(subPoints[4], 2, 1);
  prox.add(.5);

  subPoints[5].copy(subPoints[1]);
  prox.setAsProxy(subPoints[5], 2, 1);
  prox.add(.5);

  subPoints[6].copy(subPoints[2]);
  prox.setAsProxy(subPoints[6], 2, 1);
  prox.add(.5);

  subPoints[7].copy(subPoints[3]);
  prox.setAsProxy(subPoints[7], 2, 1);
  prox.add(.5);

  return subPoints;
}

// Matrices generation
static int nChoosek(int n, int k)
{
  if (n < k || k < 0) {
    Msg::Error("Wrong argument for combination.");
    return 1;
  }

  if (k > n/2) k = n-k;
  if (k == 1)
    return n;
  if (k == 0)
    return 1;

  int c = 1;
  for (int i = 1; i <= k; i++, n--) (c *= n) /= i;
  return c;
}


static fullMatrix<double> generateLag2BezMatrix
  (const fullMatrix<double> &exposant, const fullMatrix<double> &point,
   int order, int dimSimplex, bool invert = true)
{
  
  if(exposant.size1() != point.size1() || exposant.size2() != point.size2()){
    Msg::Fatal("Wrong sizes for Bezier coefficients generation %d %d -- %d %d",
      exposant.size1(),point.size1(),
      exposant.size2(),point.size2());
    return fullMatrix<double>(1, 1);
  }

  int ndofs = exposant.size1();
  int dim = exposant.size2();

  fullMatrix<double> Vandermonde(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      double dd = 1.;

      double pointCompl = 1.;
      int exposantCompl = order;
      for (int k = 0; k < dimSimplex; k++) {
        dd *= nChoosek(exposantCompl, (int) exposant(i, k))
          * pow(point(j, k), exposant(i, k));
        pointCompl -= point(j, k);
        exposantCompl -= (int) exposant(i, k);
      }
      dd *= pow(pointCompl, exposantCompl);

      for (int k = dimSimplex; k < dim; k++)
        dd *= nChoosek(order, (int) exposant(i, k))
            * pow(point(j, k), exposant(i, k))
            * pow(1. - point(j, k), order - exposant(i, k));

      Vandermonde(j, i) = dd;
    }
  }

  if (!invert) return Vandermonde;

  fullMatrix<double> coefficient(ndofs, ndofs);
  Vandermonde.invert(coefficient);
  return coefficient;
}



static fullMatrix<double> generateDivisor
  (const fullMatrix<double> &exposants, const std::vector< fullMatrix<double> > &subPoints,
   const fullMatrix<double> &lag2Bez, int order, int dimSimplex)
{
  if (exposants.size1() != lag2Bez.size1() || exposants.size1() != lag2Bez.size2()){
    Msg::Fatal("Wrong sizes for Bezier Divisor %d %d -- %d %d",
      exposants.size1(), lag2Bez.size1(),
      exposants.size1(), lag2Bez.size2());
    return fullMatrix<double>(1, 1);
  }

  int nbPts = lag2Bez.size1();
  int nbSubPts = nbPts * subPoints.size();

  fullMatrix<double> intermediate2(nbPts, nbPts);
  fullMatrix<double> divisor(nbSubPts, nbPts);

  for (unsigned int i = 0; i < subPoints.size(); i++) {
    fullMatrix<double> intermediate1 =
      generateLag2BezMatrix(exposants, subPoints[i], order, dimSimplex, false);
    lag2Bez.mult(intermediate1, intermediate2);
    divisor.copy(intermediate2, 0, nbPts, 0, nbPts, i*nbPts, 0);
  }
  return divisor;
}



static void generateGradShapes(JacobianBasis &jfs, const fullMatrix<double> &points
  , const fullMatrix<double> &monomials, const fullMatrix<double> &coefficients)
{

  /*{
    Msg::Info("Printing vector jacobian':");
    int ni = points.size1();
    int nj = points.size2();
    Msg::Info("  ");
    for(int I = 0; I < ni; I++){
        Msg::Info("%lf - %lf", points(I, 0), points(I, 1));
    }
    Msg::Info(" ");
  }
  {
    Msg::Info("Printing vector jacobian':");
    int ni = monomials.size1();
    int nj = monomials.size2();
    Msg::Info("  ");
    for(int I = 0; I < ni; I++){
        Msg::Info("%lf - %lf", monomials(I, 0), monomials(I, 1));
    }
    Msg::Info(" ");
  }
  {
    Msg::Info("Printing vector jacobian':");
    int ni = coefficients.size1();
    int nj = coefficients.size2();
    Msg::Info("  ");
    for(int I = 0; I < ni; I++){
      Msg::Info("  ");
      for(int J = 0; J < nj; J++){
        Msg::Info("%lf", coefficients(J, I));
      }
    }
    Msg::Info(" ");
  }*/

  int nbPts = points.size1();
  int nbDofs = monomials.size1();
  int dim = points.size2();
  
  switch (dim) {
    case 3 :
      jfs.gradShapeMatZ.resize(nbPts, nbDofs, true);
    case 2 :
      jfs.gradShapeMatY.resize(nbPts, nbDofs, true);
    case 1 :
      jfs.gradShapeMatX.resize(nbPts, nbDofs, true);
      break;
    default :
      return;
  }

  double dx, dy, dz;

  switch (dim) {
    case 3 :
      for (int i = 0; i < nbDofs; i++) {
        for (int k = 0; k < nbPts; k++) {

          if ((int) monomials(i, 0) > 0) {
            dx = pow( points(k, 0), monomials(i, 0)-1 ) * monomials(i, 0)
               * pow( points(k, 1), monomials(i, 1) )
               * pow( points(k, 2), monomials(i, 2) );
            for (int j = 0; j < nbDofs; j++)
              jfs.gradShapeMatX(k, j) += coefficients(j, i) * dx;
          }
          if ((int) monomials(i, 1) > 0.) {
            dy = pow( points(k, 0), monomials(i, 0) )
               * pow( points(k, 1), monomials(i, 1)-1 ) * monomials(i, 1)
               * pow( points(k, 2), monomials(i, 2) );
            for (int j = 0; j < nbDofs; j++)
              jfs.gradShapeMatY(k, j) += coefficients(j, i) * dy;
          }
          if ((int) monomials(i, 2) > 0.) {
            dz = pow( points(k, 0), monomials(i, 0) )
               * pow( points(k, 1), monomials(i, 1) )
               * pow( points(k, 2), monomials(i, 2)-1 ) * monomials(i, 2);
            for (int j = 0; j < nbDofs; j++)
              jfs.gradShapeMatZ(k, j) += coefficients(j, i) * dz;
          }
        }
      }
      return;

    case 2 :
      for (int i = 0; i < nbDofs; i++) {
        for (int k = 0; k < nbPts; k++) {

          if ((int) monomials(i, 0) > 0) {
            dx = pow( points(k, 0), (int) monomials(i, 0)-1 ) * monomials(i, 0)
               * pow( points(k, 1), (int) monomials(i, 1) );
            for (int j = 0; j < nbDofs; j++)
              jfs.gradShapeMatX(k, j) += coefficients(j, i) * dx;
          }
          if ((int) monomials(i, 1) > 0) {
            dy = pow( points(k, 0), (int) monomials(i, 0) )
               * pow( points(k, 1), (int) monomials(i, 1)-1 ) * monomials(i, 1);
            for (int j = 0; j < nbDofs; j++)
              jfs.gradShapeMatY(k, j) += coefficients(j, i) * dy;
          }
        }
      }
      return;

    case 1 :
      for (int i = 0; i < nbDofs; i++) {
        for (int k = 0; k < nbPts; k++) {

          if ((int) monomials(i, 0) > 0) {
            dx = pow( points(k, 0), (int) monomials(i, 0)-1 ) * monomials(i, 0);
            for (int j = 0; j < nbDofs; j++)
              jfs.gradShapeMatX(k, j) += coefficients(j, i) * dx;
          }
        }
      }
  }
  return;
}

std::map<int, JacobianBasis> JacobianBases::fs;

const JacobianBasis *JacobianBases::find(int tag)
{
  std::map<int, JacobianBasis>::const_iterator it = fs.find(tag);
  if (it != fs.end())     return &it->second;
  
  JacobianBasis B;
  B.numLagPts = -1;

  const polynomialBasis *F = polynomialBases::find(tag);
  int order = F->order;
  switch (F->parentType) {
    case TYPE_PNT :
      B.numLagPts = 1;
      B.exposants = generate1DExposants(0);
      B.points    = generate1DPoints(0);
      B.matrixLag2Bez = generateLag2BezMatrix(B.exposants, B.points, 0, 0);
      break;
    case TYPE_LIN : {
      int o = order - 1;
      B.numLagPts = 2;
      B.exposants = generate1DExposants(o);
      B.points    = generate1DPoints(o);
      B.matrixLag2Bez = generateLag2BezMatrix(B.exposants, B.points, o, 0);
      std::vector< fullMatrix<double> > subPoints = generateSubPointsLine(0);
      B.divisor   = generateDivisor(B.exposants, subPoints, B.matrixLag2Bez, o, 0);
      const polynomialBasis *F = polynomialBases::find(tag);
      generateGradShapes(B, B.points, F->monomials, F->coefficients);
      break;
    }
    case TYPE_TRI : {
      int o = 2 * (order - 1);
      B.numLagPts = 3;
      B.exposants = generateExposantsTriangle(o);
      B.points    = gmshGeneratePointsTriangle(o,false);
      B.matrixLag2Bez = generateLag2BezMatrix(B.exposants, B.points, o, 2);
      std::vector< fullMatrix<double> > subPoints = generateSubPointsTriangle(o);
      B.divisor   = generateDivisor(B.exposants, subPoints, B.matrixLag2Bez, o, 2);
      generateGradShapes(B, B.points, F->monomials, F->coefficients);
      break;
    }
    case TYPE_TET : {
      int o = 3 * (order - 1);
      B.numLagPts = 4;
      B.exposants = generateExposantsTetrahedron(o);
      B.points    = gmshGeneratePointsTetrahedron(o,false);
      B.matrixLag2Bez = generateLag2BezMatrix(B.exposants, B.points, o, 3);
      std::vector< fullMatrix<double> > subPoints = generateSubPointsTetrahedron(o);
      B.divisor   = generateDivisor(B.exposants, subPoints, B.matrixLag2Bez, o, 3);
      generateGradShapes(B, B.points, F->monomials, F->coefficients);
      break;
    }
    case TYPE_QUA : {
      int o = 2 * order - 1;
      B.numLagPts = 4;
      B.exposants = generateExposantsQuad(o);
      B.points    = generatePointsQuad(o,false);
      B.matrixLag2Bez = generateLag2BezMatrix(B.exposants, B.points, o, 0);
      std::vector< fullMatrix<double> > subPoints = generateSubPointsQuad(o);
      B.divisor   = generateDivisor(B.exposants, subPoints, B.matrixLag2Bez, o, 0);
      generateGradShapes(B, B.points, F->monomials, F->coefficients);
      break;
    }
    case TYPE_PRI : {
      int o = order * 3 - 1; // o=3*ord-2 on triangle base and =3*ord-1 for third dimension
      B.numLagPts = 4;
      B.exposants = generateExposantsPrism(o);
      B.points    = generatePointsPrism(o,false);
      B.matrixLag2Bez = generateLag2BezMatrix(B.exposants, B.points, o, 2);
      std::vector< fullMatrix<double> > subPoints = generateSubPointsPrism(o);
      B.divisor   = generateDivisor(B.exposants, subPoints, B.matrixLag2Bez, o, 2);
      generateGradShapes(B, B.points, F->monomials, F->coefficients);
      break;
    }
    default : {
      Msg::Error("Unknown function space %d: reverting to TET_4", tag);
      B.numLagPts = 4;
      B.exposants = generateExposantsTetrahedron(0);
      B.points    = gmshGeneratePointsTetrahedron(0,false);
      B.matrixLag2Bez = generateLag2BezMatrix(B.exposants, B.points, 0, 3);
      std::vector< fullMatrix<double> > subPoints = generateSubPointsTetrahedron(0);
      B.divisor   = generateDivisor(B.exposants, subPoints, B.matrixLag2Bez, 0, 3);
      F = polynomialBases::find(MSH_TET_4);
      generateGradShapes(B, B.points, F->monomials, F->coefficients);
    }
  }

  B.numDivisions = (int) pow(2., (int) B.points.size2());

  fs.insert(std::make_pair(tag, B));
  return &fs[tag];
}
