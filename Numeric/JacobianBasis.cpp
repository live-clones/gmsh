// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "JacobianBasis.h"



#include "polynomialBasis.h"

static fullMatrix<double> generate1DExposants(int order)
{
  fullMatrix<double> exposants(order + 1, 1);
	exposants(0, 0) = 0;
	if (order > 0) {
		exposants(1, 0) = order;
		for (int i = 2; i < order + 1; i++) exposants(i, 0) = i - 1;
	}
	exposants.print("1DExp");
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
	exposants.print("ExpTriangle");
  return exposants;
}
//
//// generate the exterior hull of the Exposants triangle for Serendipity element
//
//static fullMatrix<double> generateExposantsSerendipityTriangle(int order)
//{
//  fullMatrix<double> monomials(3 * order, 2);
//
//  monomials(0, 0) = 0;
//  monomials(0, 1) = 0;
//
//  int index = 1;
//  for (int i = 1; i <= order; i++) {
//    if (i == order) {
//      for (int j = 0; j <= i; j++) {
//        monomials(index, 0) = i - j;
//        monomials(index, 1) = j;
//        index++;
//      }
//    }
//    else {
//      monomials(index, 0) = i;
//      monomials(index, 1) = 0;
//      index++;
//      monomials(index, 0) = 0;
//      monomials(index, 1) = i;
//      index++;
//    }
//  }
//  return monomials;
//}

// generate all monomials xi^m * eta^n with n and m <= order
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
	exposants.print("ExpQuad");

  return exposants;
}
///*
//00 10 20 30 40 ⋯
//01 11 21 31 41 ⋯
//02 12
//03 13
//04 14
//⋮  ⋮
//*/
//static fullMatrix<double> generateExposantsQuadSerendip(int order)
//{
//  fullMatrix<double> monomials( (order)*4, 2);
//  monomials(0,0)=0.;
//  monomials(0,1)=0.;
//  monomials(1,0)=1.;
//  monomials(1,1)=0.;
//  monomials(2,0)=0.;
//  monomials(2,1)=1.;
//  monomials(3,0)=1.;
//  monomials(3,1)=1.;
//  int index = 4;
//  for (int p = 2; p <= order; p++) {
//    monomials(index, 0) = p;
//    monomials(index, 1) = 0;
//    index++;
//    monomials(index, 0) = 0;
//    monomials(index, 1) = p;
//    index++;
//    monomials(index, 0) = p;
//    monomials(index, 1) = 1;
//    index++;
//    monomials(index, 0) = 1;
//    monomials(index, 1) = p;
//    index++;
//  }
//  return monomials;
//}
//
///*static fullMatrix<double> generateExposantsQuadSerendip(int order)
//{
//
//  fullMatrix<double> monomials( order*4, 2);
//  int index = 0;
//  for (int p = 0; p < order; p++) {
//    monomials(p, 0) = p;
//    monomials(p, 1) = 0;
//
//    monomials(p+order, 0) = order;
//    monomials(p+order, 1) = p;
//
//    monomials(p+3*order, 0) = order-p;
//    monomials(p+3*order, 1) = order;
//
//    monomials(p+2*order, 0) = 0;
//    monomials(p+2*order, 1) = order-p;
//  }
//  monomials.print();
//  return monomials;
//}*/
//
//// generate the monomials subspace of all monomials of order exactly == p
//
//static fullMatrix<double> generateMonomialSubspace(int dim, int p)
//{
//  fullMatrix<double> monomials;
//
//  switch (dim) {
//  case 1:
//    monomials = fullMatrix<double>(1, 1);
//    monomials(0, 0) = p;
//    break;
//  case 2:
//    monomials = fullMatrix<double>(p + 1, 2);
//    for (int k = 0; k <= p; k++) {
//      monomials(k, 0) = p - k;
//      monomials(k, 1) = k;
//    }
//    break;
//  case 3:
//    monomials = fullMatrix<double>((p + 1) * (p + 2) / 2, 3);
//    int index = 0;
//    for (int i = 0; i <= p; i++) {
//      for (int k = 0; k <= p - i; k++) {
//        monomials(index, 0) = p - i - k;
//        monomials(index, 1) = k;
//        monomials(index, 2) = i;
//        index++;
//      }
//    }
//    break;
//  }
//  return monomials;
//}
//
//// generate external hull of the Exposants tetrahedron
//
//static fullMatrix<double> generateExposantsSerendipityTetrahedron(int order)
//{
//  int nbMonomials = 4 + 6 * std::max(0, order - 1) +
//    4 * std::max(0, (order - 2) * (order - 1) / 2);
//  fullMatrix<double> monomials(nbMonomials, 3);
//
//  monomials.setAll(0);
//  int index = 1;
//  for (int p = 1; p < order; p++) {
//    for (int i = 0; i < 3; i++) {
//      int j = (i + 1) % 3;
//      int k = (i + 2) % 3;
//      for (int ii = 0; ii < p; ii++) {
//        monomials(index, i) = p - ii;
//        monomials(index, j) = ii;
//        monomials(index, k) = 0;
//        index++;
//      }
//    }
//  }
//  fullMatrix<double> monomialsMaxOrder = generateMonomialSubspace(3, order);
//  int nbMaxOrder = monomialsMaxOrder.size1();
//  monomials.copy(monomialsMaxOrder, 0, nbMaxOrder, 0, 3, index, 0);
//  return monomials;
//}
//
static int nbdoftriangle(int order) { return (order + 1) * (order + 2) / 2; }
//static int nbdoftriangleserendip(int order) { return 3 * order; }

//KH : caveat : node coordinates are not yet coherent with node numbering associated
//              to numbering of principal vertices of face !!!!

// uv surface - orientation v0-v2-v1
static void nodepositionface0(int order, double *u, double *v, double *w)
{
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

// uw surface - orientation v0-v1-v3
static void nodepositionface1(int order, double *u, double *v, double *w)
{
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

// vw surface - orientation v0-v3-v2
static void nodepositionface2(int order, double *u, double *v, double *w)
{
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

// uvw surface  - orientation v3-v1-v2
static void nodepositionface3(int order,  double *u,  double *v,  double *w)
{
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

// generate Exposants tetrahedron
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
	exposants.print("ExpTet");

  return exposants;
}

// generate Exposants prism

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
		int i, j;
		for (i = 0; i < 3; i++) {
      exposants(index,0) = triExp(i,0);
      exposants(index,1) = triExp(i,1);
      exposants(index,2) = lineExp(0,0);
      index ++;
      exposants(index,0) = triExp(i,0);
      exposants(index,1) = triExp(i,1);
      exposants(index,2) = lineExp(1,0);
      index ++;
		}
		for (i = 3; i < triExp.size1(); i++) {
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

//   exposants.print("Pri ipts");
	exposants.print("ExpPrism");

  return exposants;

}

static fullMatrix<double> generate1DPoints(int order)
{
  fullMatrix<double> line(order + 1, 1);
  line(0,0) = 0;
  if (order > 0) {
    line(0, 0) = -1.;
    line(1, 0) =  1.;
    double dd = 2. / order;
    for (int i = 2; i < order + 1; i++) line(i, 0) = -1. + dd * (i - 1);
  }
	line.print("Line");
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

static fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip)
{
  const double prism18Pts[18][3] = {
    {0, 0, -1}, // 0
    {1, 0, -1}, // 1
    {0, 1, -1}, // 2
    {0, 0, 1},  // 3
    {1, 0, 1},  // 4
    {0, 1, 1},  // 5
    {0.5, 0, -1},  // 6
    {0, 0.5, -1},  // 7
    {0, 0, 0},  // 8
    {0.5, 0.5, -1},  // 9
    {1, 0, 0},  // 10
    {0, 1, 0},  // 11
    {0.5, 0, 1},  // 12
    {0, 0.5, 1},  // 13
    {0.5, 0.5, 1},  // 14
    {0.5, 0, 0},  // 15
    {0, 0.5, 0},  // 16
    {0.5, 0.5, 0},  // 17
  };

  int nbPoints = (order + 1)*(order + 1)*(order + 2)/2;
  fullMatrix<double> point(nbPoints, 3);

  int index = 0;
  fullMatrix<double> triPoints = gmshGeneratePointsTriangle(order,false);
  fullMatrix<double> linePoints = generate1DPoints(order);

  if (order == 2)
    for (int i =0; i<18; i++)
      for (int j=0; j<3;j++)
        point(i,j) = prism18Pts[i][j];
  else
    for (int j = 0; j <linePoints.size1() ; j++) {
      for (int i = 0; i < triPoints.size1(); i++) {
        point(index,0) = triPoints(i,0);
        point(index,1) = triPoints(i,1);
        point(index,2) = linePoints(j,0);
        index ++;
      }
    }

//   point.print("Pri ipts");

  return point;
}

static fullMatrix<double> gmshGeneratePointsQuad(int order, bool serendip)
{
  int nbPoints = serendip ? order*4 : (order+1)*(order+1);
  fullMatrix<double> point(nbPoints, 2);

  if (order > 0) {
    point(0, 0) = -1;
    point(0, 1) = -1;
    point(1, 0) = 1;
    point(1, 1) = -1;
    point(2, 0) = 1;
    point(2, 1) = 1;
    point(3, 0) = -1;
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
        fullMatrix<double> inner = gmshGeneratePointsQuad(order - 2, false);
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
	// attention, c*n est toujours multiple de i mais
	// n/i n'est pas entier ! Vérifier ordre des opérations.
	return c;
}

static fullMatrix<double> generateBezierFFCoefficientsSimplex
  (const fullMatrix<double>& monomial, const fullMatrix<double>& point, int order)
{ // A simplex is a generalization of the notion of a triangle to arbitrary dimension
  
	if(monomial.size1() != point.size1() || monomial.size2() != point.size2()){
		Msg::Fatal("Wrong sizes for Bezier coefficients generation %d %d -- %d %d",
			monomial.size1(),point.size1(),
			monomial.size2(),point.size2());
		return fullMatrix<double>(1, 1);
	}

	int ndofs = monomial.size1();
	int dim = monomial.size2();

	fullMatrix<double> Vandermonde(ndofs, ndofs);
	for (int i = 0; i < ndofs; i++) {
		for (int j = 0; j < ndofs; j++) {
			double dd = 1.;
			double pointCompl = 1.;
			int monomialCompl = order;
			for (int k = 0; k < dim; k++) {
				dd *= nChoosek(monomialCompl, (int) monomial(i, k)) * pow(point(j, k), monomial(i, k));
				pointCompl -= point(j, k);
				monomialCompl -= (int) monomial(i, k);
			}
			Vandermonde(j, i) = dd * pow(pointCompl, monomialCompl);
		}
	}

	fullMatrix<double> coefficient(ndofs, ndofs);
	Vandermonde.invert(coefficient);
	return coefficient;
}
//
//static void getFaceClosure(int iFace, int iSign, int iRotate, std::vector<int> &closure,
//                           int order)
//{
//
//  closure.clear();
//  closure.resize((order + 1) * (order + 2) / 2);
//  switch (order){
//  case 0:
//    closure[0] = 0;
//    break;
//  default:
//    int face[4][3] = {{-3, -2, -1}, {1, -6, 4}, {-4, 5, 3}, {6, 2, -5}};
//    int order1node[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
//    for (int i = 0; i < 3; ++i){
//      int k = (3 + (iSign * i) + iRotate) % 3;  //- iSign * iRotate
//      closure[i] = order1node[iFace][k];
//    }
//    for (int i = 0;i < 3; ++i){
//      int edgenumber = iSign *
//        face[iFace][(6 + i * iSign + (-1 + iSign) / 2 + iRotate) % 3];  //- iSign * iRotate
//      for (int k = 0; k < (order - 1); k++){
//        if (edgenumber > 0)
//          closure[3 + i * (order - 1) + k] =
//            4 + (edgenumber - 1) * (order - 1) + k;
//        else
//          closure[3 + i * (order - 1) + k] =
//            4 + (-edgenumber) * (order - 1) - 1 - k;
//      }
//    }
//    int fi = 3 + 3 * (order - 1);
//    int ti = 4 + 6 * (order - 1);
//    int ndofff = (order - 3 + 2) * (order - 3 + 1) / 2;
//    ti = ti + iFace * ndofff;
//    for (int k = 0; k < order / 3; k++){
//      int orderint = order - 3 - k * 3;
//      if (orderint > 0){
//        for (int ci = 0; ci < 3 ; ci++){
//          int  shift = (3 + iSign * ci + iRotate) % 3;  //- iSign * iRotate
//          closure[fi + ci] = ti + shift;
//        }
//        fi = fi + 3; ti = ti + 3;
//        for (int l = 0; l < orderint - 1; l++){
//          for (int ei = 0; ei < 3; ei++){
//            int edgenumber = (6 + ei * iSign + (-1 + iSign) / 2 + iRotate) % 3; //- iSign * iRotate
//            if (iSign > 0)
//              closure[fi + ei * (orderint - 1) + l] =
//                ti + edgenumber * (orderint - 1) + l;
//            else
//              closure[fi + ei * (orderint - 1) + l] =
//                ti + (1 + edgenumber) * (orderint - 1) - 1 - l;
//          }
//        }
//        fi = fi + 3 * (orderint - 1); ti = ti + 3 * (orderint - 1);
//      }
//      else {
//        closure[fi] = ti;
//        ti++;
//        fi++;
//      }
//    }
//    break;
//  }
//
//}
//
//static void generate3dFaceClosure(polynomialBasis::clCont &closure, int order)
//{
//
//  closure.clear();
//  for (int iRotate = 0; iRotate < 3; iRotate++){
//    for (int iSign = 1; iSign >= -1; iSign -= 2){
//      for (int iFace = 0; iFace < 4; iFace++){
//        std::vector<int> closure_face;
//        getFaceClosure(iFace, iSign, iRotate, closure_face, order);
//        closure.push_back(closure_face);
//      }
//    }
//  }
//}
//
//static void getFaceClosurePrism(int iFace, int iSign, int iRotate, std::vector<int> &closure,
//                           int order)
//{
//  if (order > 2)
//    Msg::Error("FaceClosure not implemented for prisms of order %d",order);
//  bool isTriangle = iFace<2;
//  int nNodes = isTriangle ? (order+1)*(order+2)/2 : (order+1)*(order+1);
//  closure.clear();
//  closure.resize(nNodes);
//  if (order==0) {
//    closure[0] = 0;
//    return;
//  }
//  int order1node[5][4] = {{0, 2, 1, -1}, {3, 4, 5, -1}, {0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
//  int order2node[5][5] = {{7, 9, 6, -1, -1}, {12, 14, 13, -1, -1}, {6, 10, 12, 8, 15}, {8, 13, 11, 7, 16}, {9, 11, 14, 10, 17}};
////   int order2node[5][4] = {{7, 9, 6, -1}, {12, 14, 13, -1}, {6, 10, 12, 8}, {8, 13, 11, 7}, {9, 11, 14, 10}};
//  int nVertex = isTriangle ? 3 : 4;
//  for (int i = 0; i < nVertex; ++i){
//    int k = (nVertex + (iSign * i) + iRotate) % nVertex;  //- iSign * iRotate
//    closure[i] = order1node[iFace][k];
//  }
//  if (order==2) {
//    for (int i = 0; i < nVertex; ++i){
//      int k = (nVertex + (iSign==-1?-1:0) + (iSign * i) + iRotate) % nVertex;  //- iSign * iRotate
//      closure[nVertex+i] = order2node[iFace][k];
//    }
//    if (!isTriangle)
//      closure[nNodes-1] = order2node[iFace][4]; // center
//  }
//}
//
//static void generate3dFaceClosurePrism(polynomialBasis::clCont &closure, int order)
//{
//
//  closure.clear();
//  for (int iRotate = 0; iRotate < 4; iRotate++){
//    for (int iSign = 1; iSign >= -1; iSign -= 2){
//      for (int iFace = 0; iFace < 5; iFace++){
//        std::vector<int> closure_face;
//        getFaceClosurePrism(iFace, iSign, iRotate, closure_face, order);
//        closure.push_back(closure_face);
//      }
//    }
//  }
//}
//
//
//static void generate2dEdgeClosure(polynomialBasis::clCont &closure, int order, int nNod = 3)
//{
//  closure.clear();
//  closure.resize(2*nNod);
//  for (int j = 0; j < nNod ; j++){
//    closure[j].push_back(j);
//    closure[j].push_back((j+1)%nNod);
//    closure[nNod+j].push_back((j+1)%nNod);
//    closure[nNod+j].push_back(j);
//    for (int i=0; i < order-1; i++){
//      closure[j].push_back( nNod + (order-1)*j + i );
//      closure[nNod+j].push_back(nNod + (order-1)*(j+1) -i -1);
//    }
//  }
//}
//
//static void generate1dVertexClosure(polynomialBasis::clCont &closure)
//{
//
//  closure.clear();
//  closure.resize(2);
//  closure[0].push_back(0);
//  closure[1].push_back(1);
//
//}
//
//  F.coefficients = generateLagrangeMonomialCoefficients(F.monomials, F.points);
////   printf("Case: %d coeffs:\n",tag);
////   for (int i = 0; i<F.coefficients.size1(); i++) {
////     for (int j = 0; j<F.coefficients.size2(); j++) {
////       printf("%4.1f ",F.coefficients(i,j));
////     }
////     printf("\n");
////   }
//
//  fs.insert(std::make_pair(tag, F));
//  return &fs[tag];
//}



// A faire : 
// - getjacobianFunctionSpace for point, line, quad, tet, prism, hexa
// generateBezierCoeff for quad, prism, hexa

std::map<int, JacobianBasis> JacobianBases::fs;

const JacobianBasis *JacobianBases::find(int tag)
{
  std::map<int, JacobianBasis>::const_iterator it = fs.find(tag);
  if (it != fs.end())     return &it->second;
  JacobianBasis B;
  //B.numFaces = -1;

  switch (tag){
  case MSH_PNT:
    //B.numFaces = 1;
    B.exposants = generate1DExposants(0);
    B.points    = generate1DPoints(0);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 0);
    break;
  case MSH_LIN_2 :
    //B.numFaces = 2;
    B.exposants = generate1DExposants(0);
    B.points    = generate1DPoints(0);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 0);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_3 :
    //B.numFaces = 2;
    B.exposants = generate1DExposants(1);
    B.points    = generate1DPoints(1);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 1);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_4:
    //B.numFaces = 2;
    B.exposants = generate1DExposants(2);
    B.points    = generate1DPoints(2);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 2);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_5:
    //B.numFaces = 2;
    B.exposants = generate1DExposants(3);
    B.points    = generate1DPoints(3);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 3);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_6:
    //B.numFaces = 2;
		B.exposants = generate1DExposants(4);
    B.points    = generate1DPoints(4);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 4);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_7:
    //B.numFaces = 2;
    B.exposants = generate1DExposants(5);
    B.points    = generate1DPoints(5);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 5);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_8:
    //B.numFaces = 2;
    B.exposants = generate1DExposants(6);
    B.points    = generate1DPoints(6);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 6);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_9:
    //B.numFaces = 2;
    B.exposants = generate1DExposants(7);
    B.points    = generate1DPoints(7);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 7);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_10:
    //B.numFaces = 2;
    B.exposants = generate1DExposants(8);
    B.points    = generate1DPoints(8);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 8);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_LIN_11:
    //B.numFaces = 2;
    B.exposants = generate1DExposants(9);
    B.points    = generate1DPoints(9);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 9);
    //generate1dVertexClosure(B.closures);
    break;
  case MSH_TRI_3 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(0);
    B.points =    gmshGeneratePointsTriangle(0, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 0);
    //generate2dEdgeClosure(B.closures, 1);
    break;
  case MSH_TRI_6 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(2);
    B.points =    gmshGeneratePointsTriangle(2, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 2);
    //generate2dEdgeClosure(B.closures, 2);
    break;
  case MSH_TRI_9 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(4);
    B.points =    gmshGeneratePointsTriangle(4, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 4);
    //generate2dEdgeClosure(B.closures, 3);
    break;
  case MSH_TRI_10 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(4);
    B.points =    gmshGeneratePointsTriangle(4, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 4);
    //generate2dEdgeClosure(B.closures, 3);
    break;
  case MSH_TRI_12 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(6);
    B.points =    gmshGeneratePointsTriangle(6, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 6);
    //generate2dEdgeClosure(B.closures, 4);
    break;
  case MSH_TRI_15 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(6);
    B.points =    gmshGeneratePointsTriangle(6, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 6);
    //generate2dEdgeClosure(B.closures, 4);
    break;
  case MSH_TRI_15I :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(8);
    B.points =    gmshGeneratePointsTriangle(8, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 8);
    //generate2dEdgeClosure(B.closures, 5);
    break;
  case MSH_TRI_21 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(8);
    B.points =    gmshGeneratePointsTriangle(8, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 8);
    //generate2dEdgeClosure(B.closures, 5);
    break;
  case MSH_TRI_28 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(10);
    B.points =    gmshGeneratePointsTriangle(10, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 10);    
    //generate2dEdgeClosure(B.closures, 6);
    break;
  case MSH_TRI_36 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(12);
    B.points =    gmshGeneratePointsTriangle(12, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 12);
    //generate2dEdgeClosure(B.closures, 7);
    break;
  case MSH_TRI_45 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(14);
    B.points =    gmshGeneratePointsTriangle(14, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 14);
    //generate2dEdgeClosure(B.closures, 8);
    break;
  case MSH_TRI_55 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(16);
    B.points =    gmshGeneratePointsTriangle(16, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 16);
    //generate2dEdgeClosure(B.closures, 9);
    break;
  case MSH_TRI_66 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(18);
    B.points =    gmshGeneratePointsTriangle(18, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 18);
    //generate2dEdgeClosure(B.closures, 10);
    break;
  case MSH_TRI_18 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(10);
    B.points =    gmshGeneratePointsTriangle(10, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 10);
    //generate2dEdgeClosure(B.closures, 6);
    break;
  case MSH_TRI_21I :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(12);
    B.points =    gmshGeneratePointsTriangle(12, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 12);
    //generate2dEdgeClosure(B.closures, 7);
    break;
  case MSH_TRI_24 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(14);
    B.points =    gmshGeneratePointsTriangle(14, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 14);
    //generate2dEdgeClosure(B.closures, 8);
    break;
  case MSH_TRI_27 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(16);
    B.points =    gmshGeneratePointsTriangle(16, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 16);
    //generate2dEdgeClosure(B.closures, 9);
    break;
  case MSH_TRI_30 :
    //B.numFaces = 3;
    B.exposants = generateExposantsTriangle(18);
    B.points =    gmshGeneratePointsTriangle(18, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 18);
    //generate2dEdgeClosure(B.closures, 10);
    break;
  case MSH_TET_4 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(0);
    B.points =    gmshGeneratePointsTetrahedron(0, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 0);
    //generate3dFaceClosure(B.closures, 1);
    break;
  case MSH_TET_10 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(3);
    B.points =    gmshGeneratePointsTetrahedron(3, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 3);
    //generate3dFaceClosure(B.closures, 2);
    break;
  case MSH_TET_20 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(6);
    B.points =    gmshGeneratePointsTetrahedron(6, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 6);
    //generate3dFaceClosure(B.closures, 3);
    break;
  case MSH_TET_35 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(9);
    B.points =    gmshGeneratePointsTetrahedron(9, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 9);
    //generate3dFaceClosure(B.closures, 4);
    break;
  case MSH_TET_34 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(9);
    B.points =    gmshGeneratePointsTetrahedron(9, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 9);
    //generate3dFaceClosure(B.closures, 4);
    break;
  case MSH_TET_52 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(12);
    B.points =    gmshGeneratePointsTetrahedron(12, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 12);
    //generate3dFaceClosure(B.closures, 5);
    break;
  case MSH_TET_56 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(12);
    B.points =    gmshGeneratePointsTetrahedron(12, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 12);
    //generate3dFaceClosure(B.closures, 5);
    break;
  case MSH_TET_84 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(15);
    B.points =    gmshGeneratePointsTetrahedron(15, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 15);
    //generate3dFaceClosure(B.closures, 6);
    break;
  case MSH_TET_120 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(18);
    B.points =    gmshGeneratePointsTetrahedron(18, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 18);
    //generate3dFaceClosure(B.closures, 7);
    break;
  case MSH_TET_165 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(21);
    B.points =    gmshGeneratePointsTetrahedron(21, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 21);
    //generate3dFaceClosure(B.closures, 8);
    break;
  case MSH_TET_220 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(24);
    B.points =    gmshGeneratePointsTetrahedron(24, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 24);
    //generate3dFaceClosure(B.closures, 9);
    break;
  case MSH_TET_286 :
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(27);
    B.points =    gmshGeneratePointsTetrahedron(27, false);
		B.matrixLag2Bez = generateBezierFFCoefficientsSimplex(B.exposants, B.points, 27);
    //generate3dFaceClosure(B.closures, 10);
    break;
  case MSH_QUA_4 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(1);
    B.points =    gmshGeneratePointsQuad(1,false);
    //generate2dEdgeClosure(B.closures, 1, 4);
    break;
  case MSH_QUA_9 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(3);
    B.points =    gmshGeneratePointsQuad(3,false);
    //generate2dEdgeClosure(B.closures, 2, 4);
    break;
  case MSH_QUA_16 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(5);
    B.points =    gmshGeneratePointsQuad(5,false);
    //generate2dEdgeClosure(B.closures, 3, 4);
    break;
  case MSH_QUA_25 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(7);
    B.points =    gmshGeneratePointsQuad(7,false);
    //generate2dEdgeClosure(B.closures, 4, 4);
    break;
  case MSH_QUA_36 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(9);
    B.points =    gmshGeneratePointsQuad(9,false);
    //generate2dEdgeClosure(B.closures, 5, 4);
    break;
  case MSH_QUA_49 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(11);
    B.points =    gmshGeneratePointsQuad(11,false);
    //generate2dEdgeClosure(B.closures, 6, 4);
    break;
  case MSH_QUA_64 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(13);
    B.points =    gmshGeneratePointsQuad(13,false);
    //generate2dEdgeClosure(B.closures, 7, 4);
    break;
  case MSH_QUA_81 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(15);
    B.points =    gmshGeneratePointsQuad(15,false);
    //generate2dEdgeClosure(B.closures, 8, 4);
    break;
  case MSH_QUA_100 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(17);
    B.points =    gmshGeneratePointsQuad(17,false);
    //generate2dEdgeClosure(B.closures, 9, 4);
    break;
  case MSH_QUA_121 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(19);
    B.points =    gmshGeneratePointsQuad(19,false);
    //generate2dEdgeClosure(B.closures, 10, 4);
    break;
  case MSH_QUA_8 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(3);
    B.points =    gmshGeneratePointsQuad(3,false);
    //generate2dEdgeClosure(B.closures, 2, 4);
    break;
  case MSH_QUA_12 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(5);
    B.points =    gmshGeneratePointsQuad(5,false);
    //generate2dEdgeClosure(B.closures, 3, 4);
    break;
  case MSH_QUA_16I :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(7);
    B.points =    gmshGeneratePointsQuad(7,false);
    //generate2dEdgeClosure(B.closures, 4, 4);
    break;
  case MSH_QUA_20 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(9);
    B.points =    gmshGeneratePointsQuad(9,false);
    //generate2dEdgeClosure(B.closures, 5, 4);
    break;
  case MSH_QUA_24 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(11);
    B.points =    gmshGeneratePointsQuad(11,false);
    //generate2dEdgeClosure(B.closures, 6, 4);
    break;
  case MSH_QUA_28 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(13);
    B.points =    gmshGeneratePointsQuad(13,false);
    //generate2dEdgeClosure(B.closures, 7, 4);
    break;
  case MSH_QUA_32 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(15);
    B.points =    gmshGeneratePointsQuad(15,false);
    //generate2dEdgeClosure(B.closures, 8, 4);
    break;
  case MSH_QUA_36I :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(17);
    B.points =    gmshGeneratePointsQuad(17,false);
    //generate2dEdgeClosure(B.closures, 9, 4);
    break;
  case MSH_QUA_40 :
    //B.numFaces = 4;
    B.exposants = generateExposantsQuad(19);
    B.points =    gmshGeneratePointsQuad(19,false);
    //generate2dEdgeClosure(B.closures, 10, 4);
    break;
  case MSH_PRI_6 : // first order
    //B.numFaces = 5;
    B.exposants = generateExposantsPrism(1);
    B.points =    gmshGeneratePointsPrism(1, false);
    //generate3dFaceClosurePrism(B.closures, 1);
    break;
  case MSH_PRI_18 : // second order
    //B.numFaces = 5;
    B.exposants = generateExposantsPrism(4);
    B.points =    gmshGeneratePointsPrism(4, false);
    //generate3dFaceClosurePrism(B.closures, 2);
    break;

  default :
    Msg::Error("Unknown function space %d: reverting to TET_4", tag);
    //B.numFaces = 4;
    B.exposants = generateExposantsTetrahedron(0);
    B.points =    gmshGeneratePointsTetrahedron(0, false);
    //generate3dFaceClosure(B.closures, 1);
    break;
  }

  //B.matrixLag2Bez = generateLagrangeMonomialCoefficients(B.monomials, B.points);

  fs.insert(std::make_pair(tag, B));
  return &fs[tag];
}
//
//
//std::map<std::pair<int, int>, fullMatrix<double> > polynomialBases::injector;
//
//const fullMatrix<double> &polynomialBases::findInjector(int tag1, int tag2)
//{
//  std::pair<int,int> key(tag1,tag2);
//  std::map<std::pair<int, int>, fullMatrix<double> >::const_iterator it = injector.find(key);
//  if (it != injector.end()) return it->second;
//
//  const polynomialBasis& fs1 = *find(tag1);
//  const polynomialBasis& fs2 = *find(tag2);
//
//  fullMatrix<double> inj(fs1.points.size1(), fs2.points.size1());
//
//  double sf[256];
//
//  for (int i = 0; i < fs1.points.size1(); i++) {
//    fs2.f(fs1.points(i, 0), fs1.points(i, 1), fs1.points(i, 2), sf);
//    for (int j = 0; j < fs2.points.size1(); j++) inj(i, j) = sf[j];
//  }
//
//  injector.insert(std::make_pair(key, inj));
//  return injector[key];
//}
//
//#include "Bindings.h"
//void polynomialBasis::registerBindings(binding *b) {
//  classBinding *cb = b->addClass<polynomialBasis>("polynomialBasis");
//  cb->setDescription("polynomial shape functions for elements");
//  methodBinding *mb = cb->addMethod("f",(void (polynomialBasis::*)(fullMatrix<double>&, fullMatrix<double>&))&polynomialBasis::f);
//  mb->setDescription("evaluate the shape functions");
//  mb->setArgNames("nodes","values",NULL);
//  mb = cb->addMethod("find",&polynomialBases::find);
//  mb->setDescription("return the polynomial basis corresponding to an element type");
//  mb->setArgNames("elementType",NULL);
//}