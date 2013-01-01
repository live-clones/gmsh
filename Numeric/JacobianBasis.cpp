// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "JacobianBasis.h"
#include <vector>
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "Numeric.h"

// Bezier Exponents
static fullMatrix<double> generate1DExponents(int order)
{
  fullMatrix<double> exponents(order + 1, 1);
  exponents(0, 0) = 0;
  if (order > 0) {
    exponents(1, 0) = order;
    for (int i = 2; i < order + 1; i++) exponents(i, 0) = i - 1;
  }

  return exponents;
}

static fullMatrix<double> generateExponentsTriangle(int order)
{
  int nbPoints = (order + 1) * (order + 2) / 2;
  fullMatrix<double> exponents(nbPoints, 2);

  exponents(0, 0) = 0;
  exponents(0, 1) = 0;

  if (order > 0) {
    exponents(1, 0) = order;
    exponents(1, 1) = 0;
    exponents(2, 0) = 0;
    exponents(2, 1) = order;

    if (order > 1) {
      int index = 3, ksi = 0, eta = 0;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi++;
        exponents(index, 0) = ksi;
        exponents(index, 1) = eta;
      }

      ksi = order;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi--;
        eta++;
        exponents(index, 0) = ksi;
        exponents(index, 1) = eta;
      }

      eta = order;
      ksi = 0;

      for (int i = 0; i < order - 1; i++, index++) {
        eta--;
        exponents(index, 0) = ksi;
        exponents(index, 1) = eta;
      }

      if (order > 2) {
        fullMatrix<double> inner = generateExponentsTriangle(order - 3);
        inner.add(1);
        exponents.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }

  return exponents;
}
static fullMatrix<double> generateExponentsQuad(int order)
{
  int nbPoints = (order+1)*(order+1);
  fullMatrix<double> exponents(nbPoints, 2);

  exponents(0, 0) = 0;
  exponents(0, 1) = 0;

  if (order > 0) {
    exponents(1, 0) = order;
    exponents(1, 1) = 0;
    exponents(2, 0) = order;
    exponents(2, 1) = order;
    exponents(3, 0) = 0;
    exponents(3, 1) = order;

    if (order > 1) {
      int index = 4;
      const static int edges[4][2]={{0,1},{1,2},{2,3},{3,0}};
      for (int iedge=0; iedge<4; iedge++) {
        int p0 = edges[iedge][0];
        int p1 = edges[iedge][1];
        for (int i = 1; i < order; i++, index++) {
          exponents(index, 0) = exponents(p0, 0) + i*(exponents(p1,0)-exponents(p0,0))/order;
          exponents(index, 1) = exponents(p0, 1) + i*(exponents(p1,1)-exponents(p0,1))/order;
        }
      }
      if (order > 2) {
        fullMatrix<double> inner = generateExponentsQuad(order - 2);
        inner.add(1);
        exponents.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }

  //  exponents.print("expq");

  return exponents;
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

static fullMatrix<double> generateExponentsTetrahedron(int order)
{
  int nbPoints = (order + 1) * (order + 2) * (order + 3) / 6;

  fullMatrix<double> exponents(nbPoints, 3);

  exponents(0, 0) = 0;
  exponents(0, 1) = 0;
  exponents(0, 2) = 0;

  if (order > 0) {
    exponents(1, 0) = order;
    exponents(1, 1) = 0;
    exponents(1, 2) = 0;

    exponents(2, 0) = 0;
    exponents(2, 1) = order;
    exponents(2, 2) = 0;

    exponents(3, 0) = 0;
    exponents(3, 1) = 0;
    exponents(3, 2) = order;

    // edges e5 and e6 switched in original version, opposite direction
    // the template has been defined in table edges_tetra and faces_tetra (MElement.h)

    if (order > 1) {
      for (int k = 0; k < (order - 1); k++) {
        exponents(4 + k, 0) = k + 1;
        exponents(4 +      order - 1  + k, 0) = order - 1 - k;
        exponents(4 + 2 * (order - 1) + k, 0) = 0;
        exponents(4 + 3 * (order - 1) + k, 0) = 0;
        // exponents(4 + 4 * (order - 1) + k, 0) = order - 1 - k;
        // exponents(4 + 5 * (order - 1) + k, 0) = 0.;
        exponents(4 + 4 * (order - 1) + k, 0) = 0;
        exponents(4 + 5 * (order - 1) + k, 0) = k+1;

        exponents(4 + k, 1) = 0;
        exponents(4 +      order - 1  + k, 1) = k + 1;
        exponents(4 + 2 * (order - 1) + k, 1) = order - 1 - k;
        exponents(4 + 3 * (order - 1) + k, 1) = 0;
        //         exponents(4 + 4 * (order - 1) + k, 1) = 0.;
        //         exponents(4 + 5 * (order - 1) + k, 1) = order - 1 - k;
        exponents(4 + 4 * (order - 1) + k, 1) = k+1;
        exponents(4 + 5 * (order - 1) + k, 1) = 0;

        exponents(4 + k, 2) = 0;
        exponents(4 +      order - 1  + k, 2) = 0;
        exponents(4 + 2 * (order - 1) + k, 2) = 0;
        exponents(4 + 3 * (order - 1) + k, 2) = order - 1 - k;
        exponents(4 + 4 * (order - 1) + k, 2) = order - 1 - k;
        exponents(4 + 5 * (order - 1) + k, 2) = order - 1 - k;
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
          exponents(ns + i, 0) = u[i] * (order - 3) + 1;
          exponents(ns + i, 1) = v[i] * (order - 3) + 1;
          exponents(ns + i, 2) = w[i] * (order - 3);
        }

        ns = ns + nbdofface;

        // u-w plane

        nodepositionface1(order - 3, u, v, w);

        for (int i=0; i < nbdofface; i++){
          exponents(ns + i, 0) = u[i] * (order - 3) + 1;
          exponents(ns + i, 1) = v[i] * (order - 3) ;
          exponents(ns + i, 2) = w[i] * (order - 3) + 1;
        }

        // v-w plane

        ns = ns + nbdofface;

        nodepositionface2(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          exponents(ns + i, 0) = u[i] * (order - 3);
          exponents(ns + i, 1) = v[i] * (order - 3) + 1;
          exponents(ns + i, 2) = w[i] * (order - 3) + 1;
        }

        // u-v-w plane

        ns = ns + nbdofface;

        nodepositionface3(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          exponents(ns + i, 0) = u[i] * (order - 3) + 1;
          exponents(ns + i, 1) = v[i] * (order - 3) + 1;
          exponents(ns + i, 2) = w[i] * (order - 3) + 1;
        }

        ns = ns + nbdofface;

        delete [] u;
        delete [] v;
        delete [] w;

        if (order > 3) {

          fullMatrix<double> interior = generateExponentsTetrahedron(order - 4);
          for (int k = 0; k < interior.size1(); k++) {
            exponents(ns + k, 0) = 1 + interior(k, 0);
            exponents(ns + k, 1) = 1 + interior(k, 1);
            exponents(ns + k, 2) = 1 + interior(k, 2);
          }
        }
      }
    }
  }

  return exponents;
}

static fullMatrix<double> generateExponentsPrism(int order)
{
  int nbPoints = (order + 1)*(order + 1)*(order + 2)/2;
  fullMatrix<double> exponents(nbPoints, 3);

  int index = 0;
  fullMatrix<double> triExp = generateExponentsTriangle(order);
  fullMatrix<double> lineExp = generate1DExponents(order);
  // First exponents (i < 3) must relate to corner
  for (int i = 0; i < triExp.size1(); i++) {
    exponents(index,0) = triExp(i,0);
    exponents(index,1) = triExp(i,1);
    exponents(index,2) = lineExp(0,0);
    index ++;
    exponents(index,0) = triExp(i,0);
    exponents(index,1) = triExp(i,1);
    exponents(index,2) = lineExp(1,0);
    index ++;
  }
  for (int j = 2; j <lineExp.size1() ; j++) {
    for (int i = 0; i < triExp.size1(); i++) {
      exponents(index,0) = triExp(i,0);
      exponents(index,1) = triExp(i,1);
      exponents(index,2) = lineExp(j,0);
      index ++;
    }
  }

  return exponents;
}

static fullMatrix<double> generateExponentsHex(int order)
{
  int nbPoints = (order+1) * (order+1) * (order+1);
  fullMatrix<double> exponents(nbPoints, 3);
  
  if (order == 0) {
    exponents(0, 0) = .0;
    return exponents;
  }

  int index = 0;
  fullMatrix<double> lineExp = generate1DExponents(order);

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        exponents(index, 0) = lineExp(i, 0);
        exponents(index, 1) = lineExp(j, 0);
        exponents(index, 2) = lineExp(k, 0);
        ++index;
      }
    }
  }
  
  for (int i = 2; i < lineExp.size1(); ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        exponents(index, 0) = lineExp(i, 0);
        exponents(index, 1) = lineExp(j, 0);
        exponents(index, 2) = lineExp(k, 0);
        ++index;
      }
    }
  }
  for (int i = 0; i < lineExp.size1(); ++i) {
    for (int j = 2; j < lineExp.size1(); ++j) {
      for (int k = 0; k < 2; ++k) {
        exponents(index, 0) = lineExp(i, 0);
        exponents(index, 1) = lineExp(j, 0);
        exponents(index, 2) = lineExp(k, 0);
        ++index;
      }
    }
  }
  for (int i = 0; i < lineExp.size1(); ++i) {
    for (int j = 0; j < lineExp.size1(); ++j) {
      for (int k = 2; k < lineExp.size1(); ++k) {
        exponents(index, 0) = lineExp(i, 0);
        exponents(index, 1) = lineExp(j, 0);
        exponents(index, 2) = lineExp(k, 0);
        ++index;
      }
    }
  }

  return exponents;
}

// Sampling Points
static fullMatrix<double> generate1DPoints(int order)
{
  fullMatrix<double> line(order + 1, 1);
  line(0,0) = .0;
  if (order > 0) {
    line(1, 0) = 1.;
    double dd = 1. / order;
    for (int i = 2; i < order + 1; i++) line(i, 0) = dd * (i - 1);
  }

  return line;
}

static fullMatrix<double> generatePointsQuadRecur(int order, bool serendip)
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
      if (order >= 2 && !serendip) {
        fullMatrix<double> inner = generatePointsQuadRecur(order - 2, false);
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

static fullMatrix<double> generatePointsQuad(int order, bool serendip)
{
  fullMatrix<double>  point = generatePointsQuadRecur(order, serendip);
  // rescale to [0,1] x [0,1]
  for (int i=0;i<point.size1();i++){
    point(i,0) = (1.+point(i,0))*.5;
    point(i,1) = (1.+point(i,1))*.5;
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

static fullMatrix<double> generatePointsHex(int order, bool serendip)
{
  int nbPoints = (order+1) * (order+1) * (order+1);
  fullMatrix<double> point(nbPoints, 3);
  
  fullMatrix<double> linePoints = generate1DPoints(order);
  int index = 0;
    
  for (int i = 0; i < linePoints.size1(); ++i) {
    for (int j = 0; j < linePoints.size1(); ++j) {
      for (int k = 0; k < linePoints.size1(); ++k) {
        point(index, 0) = linePoints(i, 0);
        point(index, 1) = linePoints(j, 0);
        point(index, 2) = linePoints(k, 0);
        ++index;
      }
    }
  }

  return point;
}

// Sub Control Points
static std::vector< fullMatrix<double> > generateSubPointsLine(int order)
{
  std::vector< fullMatrix<double> > subPoints(2);
  
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

static std::vector< fullMatrix<double> > generateSubPointsHex(int order)
{
  std::vector< fullMatrix<double> > subPoints(8);
  fullMatrix<double> prox;
  
  subPoints[0] = generatePointsHex(order, false);
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


static fullMatrix<double> generateBez2LagMatrix
  (const fullMatrix<double> &exponent, const fullMatrix<double> &point,
   int order, int dimSimplex)
{
  
  if(exponent.size1() != point.size1() || exponent.size2() != point.size2()){
    Msg::Fatal("Wrong sizes for Bezier coefficients generation %d %d -- %d %d",
      exponent.size1(),point.size1(),
      exponent.size2(),point.size2());
    return fullMatrix<double>(1, 1);
  }

  int ndofs = exponent.size1();
  int dim = exponent.size2();

  fullMatrix<double> bez2Lag(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      double dd = 1.;
      
      {
        double pointCompl = 1.;
        int exponentCompl = order;
        for (int k = 0; k < dimSimplex; k++) {
          dd *= nChoosek(exponentCompl, (int) exponent(i, k))
            * pow(point(j, k), exponent(i, k));
          pointCompl -= point(j, k);
          exponentCompl -= (int) exponent(i, k);
        }
        dd *= pow(pointCompl, exponentCompl);
      }
      
      for (int k = dimSimplex; k < dim; k++)
        dd *= nChoosek(order, (int) exponent(i, k))
            * pow(point(j, k), exponent(i, k))
            * pow(1. - point(j, k), order - exponent(i, k));
      
      bez2Lag(j, i) = dd;
    }
  }
  return bez2Lag;
}



static fullMatrix<double> generateSubDivisor
  (const fullMatrix<double> &exponents, const std::vector< fullMatrix<double> > &subPoints,
   const fullMatrix<double> &lag2Bez, int order, int dimSimplex)
{
  if (exponents.size1() != lag2Bez.size1() || exponents.size1() != lag2Bez.size2()){
    Msg::Fatal("Wrong sizes for Bezier Divisor %d %d -- %d %d",
      exponents.size1(), lag2Bez.size1(),
      exponents.size1(), lag2Bez.size2());
    return fullMatrix<double>(1, 1);
  }

  int nbPts = lag2Bez.size1();
  int nbSubPts = nbPts * subPoints.size();

  fullMatrix<double> intermediate2(nbPts, nbPts);
  fullMatrix<double> subDivisor(nbSubPts, nbPts);

  for (unsigned int i = 0; i < subPoints.size(); i++) {
    fullMatrix<double> intermediate1 =
      generateBez2LagMatrix(exponents, subPoints[i], order, dimSimplex);
    lag2Bez.mult(intermediate1, intermediate2);
    subDivisor.copy(intermediate2, 0, nbPts, 0, nbPts, i*nbPts, 0);
  }
  return subDivisor;
}



// Convert Bezier points to Lagrange points
static fullMatrix<double> bez2LagPoints(bool dim1, bool dim2, bool dim3, const fullMatrix<double> &bezierPoints)
{

  const int numPt = bezierPoints.size1();
  fullMatrix<double> lagPoints(numPt,3);

  for (int i=0; i<numPt; i++) {
    lagPoints(i,0) = dim1 ? -1. + 2*bezierPoints(i,0) : bezierPoints(i,0);
    lagPoints(i,1) = dim2 ? -1. + 2*bezierPoints(i,1) : bezierPoints(i,1);
    lagPoints(i,2) = dim3 ? -1. + 2*bezierPoints(i,2) : bezierPoints(i,2);
  }

  return lagPoints;

}



std::map<int, bezierBasis> bezierBasis::_bbs;
const bezierBasis *bezierBasis::find(int tag)
{
  std::map<int, bezierBasis>::const_iterator it = _bbs.find(tag);
  if (it != _bbs.end())
    return &it->second;

  bezierBasis &B = _bbs[tag];
  B.order = MElement::OrderFromTag(tag);

  if (MElement::ParentTypeFromTag(tag) == TYPE_PYR) {
    B.dim = 3;
    B.numLagPts = 5;
    B.bezierPoints = gmshGeneratePointsPyramid(B.order,false);
    B.lagPoints = B.bezierPoints;
    B.matrixLag2Bez.resize(B.bezierPoints.size1(),B.bezierPoints.size1(),0.);
    B.matrixBez2Lag.resize(B.bezierPoints.size1(),B.bezierPoints.size1(),0.);
    for (int i=0; i<B.matrixBez2Lag.size1(); ++i) {
      B.matrixLag2Bez(i,i) = 1.;
      B.matrixBez2Lag(i,i) = 1.;
    }
    // TODO: Implement subdidivsor
  }
  else {
    int dimSimplex;
    std::vector< fullMatrix<double> > subPoints;
    switch (MElement::ParentTypeFromTag(tag)) {
      case TYPE_PNT :
        B.dim = 0;
        B.numLagPts = 1;
        B.exponents = generate1DExponents(0);
        B.bezierPoints = generate1DPoints(0);
        B.lagPoints = B.bezierPoints;
        dimSimplex = 0;
        break;
      case TYPE_LIN : {
        B.dim = 1;
        B.numLagPts = 2;
        B.exponents = generate1DExponents(B.order);
        B.bezierPoints = generate1DPoints(B.order);
        B.lagPoints = bez2LagPoints(true,false,false,B.bezierPoints);
        dimSimplex = 0;
        subPoints = generateSubPointsLine(0);
        break;
      }
      case TYPE_TRI : {
        B.dim = 2;
        B.numLagPts = 3;
        B.exponents = generateExponentsTriangle(B.order);
        B.bezierPoints = gmshGeneratePointsTriangle(B.order,false);
        B.lagPoints = B.bezierPoints;
        dimSimplex = 2;
        subPoints = generateSubPointsTriangle(B.order);
        break;
      }
      case TYPE_QUA : {
        B.dim = 2;
        B.numLagPts = 4;
        B.exponents = generateExponentsQuad(B.order);
        B.bezierPoints = generatePointsQuad(B.order,false);
        B.lagPoints = bez2LagPoints(true,true,false,B.bezierPoints);
        dimSimplex = 0;
        subPoints = generateSubPointsQuad(B.order);
        //      B.points.print("points");
        break;
      }
      case TYPE_TET : {
        B.dim = 3;
        B.numLagPts = 4;
        B.exponents = generateExponentsTetrahedron(B.order);
        B.bezierPoints = gmshGeneratePointsTetrahedron(B.order,false);
        B.lagPoints = B.bezierPoints;
        dimSimplex = 3;
        subPoints = generateSubPointsTetrahedron(B.order);
        break;
      }
      case TYPE_PRI : {
        B.dim = 3;
        B.numLagPts = 6;
        B.exponents = generateExponentsPrism(B.order);
        B.bezierPoints = generatePointsPrism(B.order, false);
        B.lagPoints = bez2LagPoints(false,false,true,B.bezierPoints);
        dimSimplex = 2;
        subPoints = generateSubPointsPrism(B.order);
        break;
      }
      case TYPE_HEX : {
        B.dim = 3;
        B.numLagPts = 8;
        B.exponents = generateExponentsHex(B.order);
        B.bezierPoints = generatePointsHex(B.order, false);
        B.lagPoints = bez2LagPoints(true,true,true,B.bezierPoints);
        dimSimplex = 0;
        subPoints = generateSubPointsHex(B.order);
        break;
      }
      default : {
        Msg::Error("Unknown function space %d: reverting to TET_1", tag);
        B.dim = 3;
        B.numLagPts = 4;
        B.exponents = generateExponentsTetrahedron(0);
        B.bezierPoints = gmshGeneratePointsTetrahedron(0, false);
        B.lagPoints = B.bezierPoints;
        dimSimplex = 3;
        subPoints = generateSubPointsTetrahedron(0);
        break;
      }
    }
    B.matrixBez2Lag = generateBez2LagMatrix(B.exponents, B.bezierPoints, B.order, dimSimplex);
    B.matrixBez2Lag.invert(B.matrixLag2Bez);
    B.subDivisor = generateSubDivisor(B.exponents, subPoints, B.matrixLag2Bez, B.order, dimSimplex);
    B.numDivisions = (int) pow(2., (int) B.bezierPoints.size2());
  }

  return &B;
}



JacobianBasis::JacobianBasis(int tag)
{

  const int parentType = MElement::ParentTypeFromTag(tag);
  int jacType = 0, primJacType = 0;

  if (parentType == TYPE_PYR) {
    switch (tag) {
    case MSH_PYR_5 : jacType = MSH_PYR_14; primJacType = MSH_PYR_14; break;   // TODO: Order 1, Jac. "order" 2, check this
    case MSH_PYR_14 : jacType = MSH_PYR_91; primJacType = MSH_PYR_14; break;  // TODO: Order 2, Jac. "order" 5, check this
    case MSH_PYR_30 : jacType = MSH_PYR_285; primJacType = MSH_PYR_14; break; // TODO: Order 3, Jac. "order" 8, check this
    default :
      Msg::Error("Unknown Jacobian function space for element type %d", tag);
      break;
    }
  }
  else {
    const int order = MElement::OrderFromTag(tag);
    int jacobianOrder, primJacobianOrder;
    switch (parentType) {
      case TYPE_PNT : jacobianOrder = 0; primJacobianOrder = 0; break;
      case TYPE_LIN : jacobianOrder = order - 1; primJacobianOrder = 0; break;
      case TYPE_TRI : jacobianOrder = 2 * (order - 1); primJacobianOrder = 0; break;
      case TYPE_QUA : jacobianOrder = 2 * order - 1; primJacobianOrder = 1; break;
      case TYPE_TET : jacobianOrder = 3 * (order - 1); primJacobianOrder = 0; break;
      case TYPE_PRI : jacobianOrder = 3 * order - 1; primJacobianOrder = 2; break;
      case TYPE_HEX : jacobianOrder = 3 * order - 1; primJacobianOrder = 2; break;
      default :
        Msg::Error("Unknown Jacobian function space for element type %d", tag);
        jacobianOrder = 0;
        break;
    }
    jacType = polynomialBasis::getTag(parentType, jacobianOrder, false);
    primJacType = polynomialBasis::getTag(parentType, primJacobianOrder, false);
  }

  // Store Bezier basis
  bezier = bezierBasis::find(jacType);

  // Store shape function gradients of mapping at Jacobian nodes
  const nodalBasis *mapBasis = BasisFactory::create(tag);
  fullMatrix<double> allDPsi;
  mapBasis->df(getPoints(), allDPsi);
  numJacNodes = getPoints().size1();
  numMapNodes = allDPsi.size1();
  gradShapeMatX.resize(numJacNodes,numMapNodes);
  gradShapeMatY.resize(numJacNodes,numMapNodes);
  gradShapeMatZ.resize(numJacNodes,numMapNodes);
  for (int i=0; i<numJacNodes; i++)
    for (int j=0; j<numMapNodes; j++) {
      gradShapeMatX(i,j) = allDPsi(j,3*i);
      gradShapeMatY(i,j) = allDPsi(j,3*i+1);
      gradShapeMatZ(i,j) = allDPsi(j,3*i+2);
    }

  // Compute matrix for lifting from primary Jacobian basis to Jacobian basis
  const nodalBasis *primJacBasis = BasisFactory::create(primJacType);
  numPrimJacNodes = primJacBasis->getNumShapeFunctions();
  matrixPrimJac2Jac.resize(numJacNodes,numPrimJacNodes);
  primJacBasis->f(getPoints(),matrixPrimJac2Jac);

  // Compute shape function gradients of primary mapping at barycenter,
  // in order to compute normal to straight element
  const int primMapType = polynomialBasis::getTag(parentType, 1, false);
  const nodalBasis *primMapBasis = BasisFactory::create(primMapType);
  numPrimMapNodes = primMapBasis->getNumShapeFunctions();
  double xBar = 0., yBar = 0., zBar = 0.;
  for (int i=0; i<numPrimMapNodes; i++) {
    xBar += primMapBasis->points(i,0);
    yBar += primMapBasis->points(i,1);
    zBar += primMapBasis->points(i,2);
  }
  xBar /= numPrimMapNodes;
  yBar /= numPrimMapNodes;
  zBar /= numPrimMapNodes;
  double (*barDPsi)[3] = new double[numPrimMapNodes][3];
  primMapBasis->df(xBar, yBar, zBar, barDPsi);
  primGradShapeBarX.resize(numPrimMapNodes);
  primGradShapeBarY.resize(numPrimMapNodes);
  primGradShapeBarZ.resize(numPrimMapNodes);
  for (int j=0; j<numPrimMapNodes; j++) {
    primGradShapeBarX(j) = barDPsi[j][0];
    primGradShapeBarY(j) = barDPsi[j][1];
    primGradShapeBarZ(j) = barDPsi[j][2];
  }
  delete[] barDPsi;

}



std::map<int, JacobianBasis*> JacobianBasis::_fs;
const JacobianBasis *JacobianBasis::find(int tag)
{

  std::map<int, JacobianBasis*>::const_iterator it = _fs.find(tag);
  if (it != _fs.end()) return it->second;

  JacobianBasis *B = new JacobianBasis(tag);
  _fs.insert(std::make_pair(tag, B));
  return B;

}



// Computes (unit) normals to straight line element
void JacobianBasis::getPrimNormals1D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const
{

  fullVector<double> dxyzdXbar(3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdXbar(0) += primGradShapeBarX(j)*nodesXYZ(j,0);
    dxyzdXbar(1) += primGradShapeBarX(j)*nodesXYZ(j,1);
    dxyzdXbar(2) += primGradShapeBarX(j)*nodesXYZ(j,2);
  }

  if((fabs(dxyzdXbar(0)) >= fabs(dxyzdXbar(1)) && fabs(dxyzdXbar(0)) >= fabs(dxyzdXbar(2))) ||
     (fabs(dxyzdXbar(1)) >= fabs(dxyzdXbar(0)) && fabs(dxyzdXbar(1)) >= fabs(dxyzdXbar(2)))) {
    result(0,0) = dxyzdXbar(1); result(0,1) = -dxyzdXbar(0); result(0,2) = 0.;
  }
  else {
    result(0,0) = 0.; result(0,1) = dxyzdXbar(2); result(0,2) = -dxyzdXbar(1);
  }
  const double norm0 = sqrt(result(0,0)*result(0,0)+result(0,1)*result(0,1)+result(0,2)*result(0,2));
  result(0,0) /= norm0; result(0,1) /= norm0; result(0,2) /= norm0;

  result(1,2) = dxyzdXbar(0) * result(0,1) - dxyzdXbar(1) * result(0,0);
  result(1,1) = -dxyzdXbar(0) * result(0,2) + dxyzdXbar(2) * result(0,0);
  result(1,0) = dxyzdXbar(1) * result(0,2) - dxyzdXbar(2) * result(0,1);
  const double norm1 = sqrt(result(1,0)*result(1,0)+result(1,1)*result(1,1)+result(1,2)*result(1,2));
  result(1,0) /= norm1; result(1,1) /= norm1; result(1,2) /= norm1;

}



// Computes (unit) normal to straight surface element (with norm as return value)
double JacobianBasis::getPrimNormal2D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const
{

  fullVector<double> dxyzdXbar(3), dxyzdYbar(3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdXbar(0) += primGradShapeBarX(j)*nodesXYZ(j,0);
    dxyzdXbar(1) += primGradShapeBarX(j)*nodesXYZ(j,1);
    dxyzdXbar(2) += primGradShapeBarX(j)*nodesXYZ(j,2);
    dxyzdYbar(0) += primGradShapeBarY(j)*nodesXYZ(j,0);
    dxyzdYbar(1) += primGradShapeBarY(j)*nodesXYZ(j,1);
    dxyzdYbar(2) += primGradShapeBarY(j)*nodesXYZ(j,2);
  }

  result(0,2) = dxyzdXbar(0) * dxyzdYbar(1) - dxyzdXbar(1) * dxyzdYbar(0);
  result(0,1) = -dxyzdXbar(0) * dxyzdYbar(2) + dxyzdXbar(2) * dxyzdYbar(0);
  result(0,0) = dxyzdXbar(1) * dxyzdYbar(2) - dxyzdXbar(2) * dxyzdYbar(1);
  const double norm0 = sqrt(result(0,0)*result(0,0)+result(0,1)*result(0,1)+result(0,2)*result(0,2));
  result(0,0) /= norm0; result(0,1) /= norm0; result(0,2) /= norm0;

  return norm0;

}



inline double calcDet3D(double dxdX, double dydX, double dzdX,
                        double dxdY, double dydY, double dzdY,
                        double dxdZ, double dydZ, double dzdZ)
{
  return dxdX*dydY*dzdZ + dxdY*dydZ*dzdX + dydX*dzdY*dxdZ
       - dxdZ*dydY*dzdX - dxdY*dydX*dzdZ - dydZ*dzdY*dxdX;
}



// Calculate (signed) Jacobian at mapping's nodes for one element, with normal vectors to
// straight element for regularization
void JacobianBasis::getSignedJacobian(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const
{

  switch (bezier->dim) {

    case 1 : {
      fullMatrix<double> normals(2,3);
      getPrimNormals1D(nodesXYZ,normals);
      getSignedJacobian(nodesXYZ,normals,jacobian);
      break;
    }

    case 2 : {
      fullMatrix<double> normal(1,3);
      getPrimNormal2D(nodesXYZ,normal);
      getSignedJacobian(nodesXYZ,normal,jacobian);
      break;
    }

    case 0 :
    case 3 : {
      fullMatrix<double> dum;
      getSignedJacobian(nodesXYZ,dum,jacobian);
      break;
    }

  }

}



// Calculate (signed) Jacobian at mapping's nodes for one element, given vectors for regularization
// of line and surface Jacobians in 3D
void JacobianBasis::getSignedJacobian(const fullMatrix<double> &nodesXYZ,
                                      const fullMatrix<double> &normals, fullVector<double> &jacobian) const
{

  switch (bezier->dim) {

    case 0 : {
      for (int i = 0; i < numJacNodes; i++) jacobian(i) = 1.;
      break;
    }

    case 1 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        jacobian(i) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normals(0,0), &dydZ = normals(0,1), &dzdZ = normals(0,2);
        jacobian(i) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3), dxyzdZ(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      gradShapeMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        jacobian(i) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

  }

}



// Calculate (signed) Jacobian at mapping's nodes for one element, given vectors for regularization
// of line and surface Jacobians in 3D
void JacobianBasis::getSignedJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                             const fullMatrix<double> &normals,
                                             fullMatrix<double> &JDJ) const
{

  switch (bezier->dim) {

    case 0 : {
      for (int i = 0; i < numJacNodes; i++) {
        for (int j = 0; j < numMapNodes; j++) {
          JDJ (i,j) = 0.;
          JDJ (i,j+1*numMapNodes) = 0.;
          JDJ (i,j+2*numMapNodes) = 0.;
        }
        JDJ(i,3*numMapNodes) = 1.;
      }
      break;
    }

    case 1 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        for (int j = 0; j < numMapNodes; j++) {
          const double &dPhidX = gradShapeMatX(i,j);
          JDJ (i,j) = dPhidX * dydY * dzdZ + dPhidX * dzdY * dydZ;
          JDJ (i,j+1*numMapNodes) = dPhidX * dzdY * dxdZ - dPhidX * dxdY * dzdZ;
          JDJ (i,j+2*numMapNodes) = dPhidX * dxdY * dydZ - dPhidX * dydY * dxdZ;
        }
        JDJ(i,3*numMapNodes) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normals(0,0), &dydZ = normals(0,1), &dzdZ = normals(0,2);
        for (int j = 0; j < numMapNodes; j++) {
          const double &dPhidX = gradShapeMatX(i,j);
          const double &dPhidY = gradShapeMatY(i,j);
          JDJ (i,j) =
            dPhidX * dydY * dzdZ + dzdX * dPhidY * dydZ +
            dPhidX * dzdY * dydZ - dydX * dPhidY * dzdZ;
          JDJ (i,j+1*numMapNodes) =
            dxdX * dPhidY * dzdZ +
            dPhidX * dzdY * dxdZ - dzdX * dPhidY * dxdZ
                                 - dPhidX * dxdY * dzdZ;
          JDJ (i,j+2*numMapNodes) =
                                   dPhidX * dxdY * dydZ +
            dydX * dPhidY * dxdZ - dPhidX * dydY * dxdZ -
            dxdX * dPhidY * dydZ;
        }
        JDJ(i,3*numMapNodes) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3), dxyzdZ(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      gradShapeMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        for (int j = 0; j < numMapNodes; j++) {
          const double &dPhidX = gradShapeMatX(i,j);
          const double &dPhidY = gradShapeMatY(i,j);
          const double &dPhidZ = gradShapeMatZ(i,j);
          JDJ (i,j) =
            dPhidX * dydY * dzdZ + dzdX * dPhidY * dydZ +
            dydX * dzdY * dPhidZ - dzdX * dydY * dPhidZ -
            dPhidX * dzdY * dydZ - dydX * dPhidY * dzdZ;
          JDJ (i,j+1*numMapNodes) =
            dxdX * dPhidY * dzdZ + dzdX * dxdY * dPhidZ +
            dPhidX * dzdY * dxdZ - dzdX * dPhidY * dxdZ -
            dxdX * dzdY * dPhidZ - dPhidX * dxdY * dzdZ;
          JDJ (i,j+2*numMapNodes) =
            dxdX * dydY * dPhidZ + dPhidX * dxdY * dydZ +
            dydX * dPhidY * dxdZ - dPhidX * dydY * dxdZ -
            dxdX * dPhidY * dydZ - dydX * dxdY * dPhidZ;
        }
        JDJ(i,3*numMapNodes) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

  }

}



void JacobianBasis::getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                             const fullMatrix<double> &nodesXYZStraight,
                                             fullVector<double> &lambdaJ , fullMatrix<double> &gradLambdaJ) const
{

  // jacobian of the straight elements (only triangles for now)
  SPoint3 v0(nodesXYZ(0,0),nodesXYZ(0,1),nodesXYZ(0,2));
  SPoint3 v1(nodesXYZ(1,0),nodesXYZ(1,1),nodesXYZ(1,2));
  SPoint3 v2(nodesXYZ(2,0),nodesXYZ(2,1),nodesXYZ(2,2));
  SPoint3 *IXYZ[3] = {&v0, &v1, &v2};
  double jaci[2][2] = {
    {IXYZ[1]->x() - IXYZ[0]->x(), IXYZ[2]->x() - IXYZ[0]->x()},
    {IXYZ[1]->y() - IXYZ[0]->y(), IXYZ[2]->y() - IXYZ[0]->y()}
  };
  double invJaci[2][2];
  inv2x2(jaci, invJaci);

  for (int l = 0; l < numJacNodes; l++) {
    double jac[2][2] = {{0., 0.}, {0., 0.}};
    for (int i = 0; i < numMapNodes; i++) {
      const double &dPhidX = gradShapeMatX(l,i);
      const double &dPhidY = gradShapeMatY(l,i);
      const double dpsidx = dPhidX * invJaci[0][0] + dPhidY * invJaci[1][0];
      const double dpsidy = dPhidX * invJaci[0][1] + dPhidY * invJaci[1][1];
      jac[0][0] += nodesXYZ(i,0) * dpsidx;
      jac[0][1] += nodesXYZ(i,0) * dpsidy;
      jac[1][0] += nodesXYZ(i,1) * dpsidx;
      jac[1][1] += nodesXYZ(i,1) * dpsidy;
    }
    const double dxdx = jac[0][0] * jac[0][0] + jac[0][1] * jac[0][1];
    const double dydy = jac[1][0] * jac[1][0] + jac[1][1] * jac[1][1];
    const double dxdy = jac[0][0] * jac[1][0] + jac[0][1] * jac[1][1];
    const double sqr = sqrt((dxdx - dydy) * (dxdx - dydy) + 4 * dxdy * dxdy);
    const double osqr = sqr > 1e-8 ? 1/sqr : 0;
    lambdaJ(l) = 0.5 * (dxdx + dydy - sqr);
    const double axx = (1 - (dxdx - dydy) * osqr) * jac[0][0] - 2 * dxdy * osqr * jac[1][0];
    const double axy = (1 - (dxdx - dydy) * osqr) * jac[0][1] - 2 * dxdy * osqr * jac[1][1];
    const double ayx = -2 * dxdy * osqr * jac[0][0] + (1 - (dydy - dxdx) * osqr) * jac[1][0];
    const double ayy = -2 * dxdy * osqr * jac[0][1] + (1 - (dydy - dxdx) * osqr) * jac[1][1];
    const double axixi   = axx * invJaci[0][0] + axy * invJaci[0][1];
    const double aetaeta = ayx * invJaci[1][0] + ayy * invJaci[1][1];
    const double aetaxi  = ayx * invJaci[0][0] + ayy * invJaci[0][1];
    const double axieta  = axx * invJaci[1][0] + axy * invJaci[1][1];
    for (int i = 0; i < numMapNodes; i++) {
      const double &dPhidX = gradShapeMatX(l,i);
      const double &dPhidY = gradShapeMatY(l,i);
      gradLambdaJ(l, i + 0 * numMapNodes) = axixi * dPhidX + axieta * dPhidY;
      gradLambdaJ(l, i + 1 * numMapNodes) = aetaxi * dPhidX + aetaeta * dPhidY;
    }
  }

}



// Calculate (signed) Jacobian at mapping's nodes for several elements
// TODO: Optimize and test 1D & 2D
void JacobianBasis::getSignedJacobian(const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                      const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const
{

  switch (bezier->dim) {

    case 0 : {
      const int numEl = nodesX.size2();
      for (int iEl = 0; iEl < numEl; iEl++)
        for (int i = 0; i < numJacNodes; i++) jacobian(i,iEl) = 1.;
      break;
    }

    case 1 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(numJacNodes,numEl), dydX(numJacNodes,numEl), dzdX(numJacNodes,numEl);
      gradShapeMatX.mult(nodesX, dxdX); gradShapeMatX.mult(nodesY, dydX); gradShapeMatX.mult(nodesZ, dzdX);
      for (int iEl = 0; iEl < numEl; iEl++) {
        fullMatrix<double> nodesXYZ(numPrimJacNodes,3);
        for (int i = 0; i < numPrimJacNodes; i++) {
          nodesXYZ(i,0) = nodesX(i,iEl);
          nodesXYZ(i,1) = nodesY(i,iEl);
          nodesXYZ(i,2) = nodesZ(i,iEl);
        }
        fullMatrix<double> normals(2,3);
        getPrimNormals1D(nodesXYZ,normals);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        for (int i = 0; i < numJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl),dydX(i,iEl),dzdX(i,iEl),
                                      dxdY,dydY,dzdY,
                                      dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 2 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(numJacNodes,numEl), dydX(numJacNodes,numEl), dzdX(numJacNodes,numEl);
      fullMatrix<double> dxdY(numJacNodes,numEl), dydY(numJacNodes,numEl), dzdY(numJacNodes,numEl);
      gradShapeMatX.mult(nodesX, dxdX); gradShapeMatX.mult(nodesY, dydX); gradShapeMatX.mult(nodesZ, dzdX);
      gradShapeMatY.mult(nodesX, dxdY); gradShapeMatY.mult(nodesY, dydY); gradShapeMatY.mult(nodesZ, dzdY);
      for (int iEl = 0; iEl < numEl; iEl++) {
        fullMatrix<double> nodesXYZ(numPrimJacNodes,3);
        for (int i = 0; i < numPrimJacNodes; i++) {
          nodesXYZ(i,0) = nodesX(i,iEl);
          nodesXYZ(i,1) = nodesY(i,iEl);
          nodesXYZ(i,2) = nodesZ(i,iEl);
        }
        fullMatrix<double> normal(1,3);
        getPrimNormal2D(nodesXYZ,normal);
        const double &dxdZ = normal(0,0), &dydZ = normal(0,1), &dzdZ = normal(0,2);
        for (int i = 0; i < numJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl),dydX(i,iEl),dzdX(i,iEl),
                                      dxdY(i,iEl),dydY(i,iEl),dzdY(i,iEl),
                                      dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 3 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(numJacNodes,numEl), dydX(numJacNodes,numEl), dzdX(numJacNodes,numEl);
      fullMatrix<double> dxdY(numJacNodes,numEl), dydY(numJacNodes,numEl), dzdY(numJacNodes,numEl);
      fullMatrix<double> dxdZ(numJacNodes,numEl), dydZ(numJacNodes,numEl), dzdZ(numJacNodes,numEl);
      gradShapeMatX.mult(nodesX, dxdX); gradShapeMatX.mult(nodesY, dydX); gradShapeMatX.mult(nodesZ, dzdX);
      gradShapeMatY.mult(nodesX, dxdY); gradShapeMatY.mult(nodesY, dydY); gradShapeMatY.mult(nodesZ, dzdY);
      gradShapeMatZ.mult(nodesX, dxdZ); gradShapeMatZ.mult(nodesY, dydZ); gradShapeMatZ.mult(nodesZ, dzdZ);
      for (int iEl = 0; iEl < numEl; iEl++)
        for (int i = 0; i < numJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl),dydX(i,iEl),dzdX(i,iEl),
                                      dxdY(i,iEl),dydY(i,iEl),dzdY(i,iEl),
                                      dxdZ(i,iEl),dydZ(i,iEl),dzdZ(i,iEl));
      break;
    }

  }

}
