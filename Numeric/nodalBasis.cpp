// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <limits>
#include "nodalBasis.h"
#include "BasisFactory.h"
//#include "pointsGenerators.h"



static int nbdoftriangle(int order) { return (order + 1) * (order + 2) / 2; }

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
      // FIXIT it was > 2 and I beleive it is >= 2 !!
      if (order >= 2 && !serendip) {
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



static fullMatrix<double> gmshGeneratePointsHex(int order, bool serendip)
{
  int nbPoints = (order+1)*(order+1)*(order+1);
  if (serendip) nbPoints -= (order-1)*(order-1)*(order-1);
  fullMatrix<double> point(nbPoints, 3);

  // should be a public member of MHexahedron, just copied
  static const int edges[12][2] = {
    {0, 1},
    {0, 3},
    {0, 4},
    {1, 2},
    {1, 5},
    {2, 3},
    {2, 6},
    {3, 7},
    {4, 5},
    {4, 7},
    {5, 6},
    {6, 7}
  };
  static const int faces[6][4] = {
    {0, 3, 2, 1},
    {0, 1, 5, 4},
    {0, 4, 7, 3},
    {1, 2, 6, 5},
    {2, 3, 7, 6},
    {4, 5, 6, 7}
  };

  if (order > 0) {
    point(0, 0) = -1;
    point(0, 1) = -1;
    point(0, 2) = -1;
    point(1, 0) = 1;
    point(1, 1) = -1;
    point(1, 2) = -1;
    point(2, 0) = 1;
    point(2, 1) = 1;
    point(2, 2) = -1;
    point(3, 0) = -1;
    point(3, 1) = 1;
    point(3, 2) = -1;

    point(4, 0) = -1;
    point(4, 1) = -1;
    point(4, 2) = 1;
    point(5, 0) = 1;
    point(5, 1) = -1;
    point(5, 2) = 1;
    point(6, 0) = 1;
    point(6, 1) = 1;
    point(6, 2) = 1;
    point(7, 0) = -1;
    point(7, 1) = 1;
    point(7, 2) = 1;

    if (order > 1) {
      int index = 8;
      for (int iedge=0; iedge<12; iedge++) {
        int p0 = edges[iedge][0];
        int p1 = edges[iedge][1];
        for (int i = 1; i < order; i++, index++) {
          point(index, 0) = point(p0, 0) + i*(point(p1,0)-point(p0,0))/order;
          point(index, 1) = point(p0, 1) + i*(point(p1,1)-point(p0,1))/order;
          point(index, 2) = point(p0, 2) + i*(point(p1,2)-point(p0,2))/order;
        }
      }

      fullMatrix<double> fp = gmshGeneratePointsQuad(order - 2, false);
      fp.scale(1. - 2./order);
      for (int iface=0; iface<6; iface++) {
  int p0 = faces[iface][0];
  int p1 = faces[iface][1];
  int p2 = faces[iface][2];
  int p3 = faces[iface][3];
  for (int i=0;i<fp.size1();i++, index++){
    const double u = fp(i,0);
    const double v = fp(i,1);
    const double newU =
      0.25*(1.-u)*(1.-v)*point(p0,0) +
      0.25*(1.+u)*(1.-v)*point(p1,0) +
      0.25*(1.+u)*(1.+v)*point(p2,0) +
      0.25*(1.-u)*(1.+v)*point(p3,0) ;
    const double newV =
      0.25*(1.-u)*(1.-v)*point(p0,1) +
      0.25*(1.+u)*(1.-v)*point(p1,1) +
      0.25*(1.+u)*(1.+v)*point(p2,1) +
      0.25*(1.-u)*(1.+v)*point(p3,1) ;
    const double newW =
      0.25*(1.-u)*(1.-v)*point(p0,2) +
      0.25*(1.+u)*(1.-v)*point(p1,2) +
      0.25*(1.+u)*(1.+v)*point(p2,2) +
      0.25*(1.-u)*(1.+v)*point(p3,2) ;
    point(index, 0) = newU;
    point(index, 1) = newV;
    point(index, 2) = newW;
  }
      }
      if (!serendip) {
        fullMatrix<double> inner = gmshGeneratePointsHex(order - 2, false);
        inner.scale(1. - 2./order);
        point.copy(inner, 0, nbPoints - index, 0, 3, index, 0);
      }
    }
  }
  else if (order == 0){
    point(0, 0) = 0;
    point(0, 1) = 0;
    point(0, 2) = 0;
  }
  return point;
}



static fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip)
{
  int nbPoints = (order+1)*((order+1)+1)*(2*(order+1)+1)/6;

  // Remove volume points if incomplete basis
  if (serendip && order > 2) nbPoints -= (order-2)*((order-2)+1)*(2*(order-2)+1)/6;

  fullMatrix<double> points(nbPoints, 3);

  static const int edges[8][2] = {
    {0, 1},
    {0, 3},
    {0, 4},
    {1, 2},
    {1, 4},
    {2, 3},
    {2, 4},
    {3, 4},
  };
    static const int faces[5][4] = {
      {0, 1, 4, -1},
      {3, 0, 4, -1},
      {1, 2, 4, -1},
      {2, 3, 4, -1},
      {0, 3, 2, 1}
    };

    if (order == 0) {
      points(0,0) = 0.0;
      points(0,1) = 0.0;
      points(0,2) = 0.0;
      return points;
    }

    // Principal vertices of the pyramid
    points(0,0) = -1.0; points(0,1) = -1.0; points(0,2) =  0.0;
    points(1,0) =  1.0; points(1,1) = -1.0; points(1,2) =  0.0;
    points(2,0) =  1.0; points(2,1) =  1.0; points(2,2) =  0.0;
    points(3,0) = -1.0; points(3,1) =  1.0; points(3,2) =  0.0;
    points(4,0) =  0.0; points(4,1) =  0.0; points(4,2) =  1.0;

    if (order > 1) {
      int p = 5;

      // Edges
      for (int e = 0; e < 8; e++) {
        double vec[3];
        vec[0] = points(edges[e][1],0) - points(edges[e][0],0);
        vec[1] = points(edges[e][1],1) - points(edges[e][0],1);
        vec[2] = points(edges[e][1],2) - points(edges[e][0],2);
        for (int i = 0; i < order - 1; i++) {
          points(p,0) = points(edges[e][0],0) + vec[0]/order * (i+1);
          points(p,1) = points(edges[e][0],1) + vec[1]/order * (i+1);
          points(p,2) = points(edges[e][0],2) + vec[2]/order * (i+1);
          p++;
        }
      }

      // Faces
      for (int f = 0; f < 4; f++) {
        fullMatrix<double> fp = gmshGeneratePointsTriangle(order, false);

        fullVector<double> u(4);
        fullVector<double> v(4);
        fullVector<double> w(4);
        fullVector<double> y(4);

        fullVector<double> up(4);
        fullVector<double> vp(4);
        fullVector<double> wp(4);
        fullVector<double> yp(4);

        for (int c = 0; c < 3; c++) {
          u(c) = fp(0,c);
          v(c) = fp(1,c);
          w(c) = fp(2,c);
          up(c) = points(faces[f][0],c);
          vp(c) = points(faces[f][1],c);
          wp(c) = points(faces[f][2],c);
        }

        u(2) = 0.0;
        v(2) = 0.0;
        w(2) = 0.0;
        u(3) = 1.0;
        v(3) = 1.0;
        w(3) = 1.0;

        y(0) = u(0) + ((v(1)-u(1))*(w(2)-u(2)) - (v(2)-u(2))*(w(1)-u(1)));
        y(1) = u(1) + ((v(2)-u(2))*(w(0)-u(0)) - (v(0)-u(0))*(w(2)-u(2)));
        y(2) = u(2) + ((v(0)-u(0))*(w(1)-u(1)) - (v(1)-u(1))*(w(0)-u(0)));
        y(3) = 1.0;

        up(3) = 1.0;
        vp(3) = 1.0;
        wp(3) = 1.0;

        yp(0) = up(0) + ((vp(1)-up(1))*(wp(2)-up(2)) - (vp(2)-up(2))*(wp(1)-up(1)));
        yp(1) = up(1) + ((vp(2)-up(2))*(wp(0)-up(0)) - (vp(0)-up(0))*(wp(2)-up(2)));
        yp(2) = up(2) + ((vp(0)-up(0))*(wp(1)-up(1)) - (vp(1)-up(1))*(wp(0)-up(0)));
        yp(3) = 1.0;

        fullMatrix<double> M(4,4);
        fullMatrix<double> Mp(4,4);

        M(0,0) = u(0); M(0,1) = v(0); M(0,2) = w(0); M(0,3) = y(0);
        M(1,0) = u(1); M(1,1) = v(1); M(1,2) = w(1); M(1,3) = y(1);
        M(2,0) = u(2); M(2,1) = v(2); M(2,2) = w(2); M(2,3) = y(2);
        M(3,0) = u(3); M(3,1) = v(3); M(3,2) = w(3); M(3,3) = y(3);

        Mp(0,0) = up(0); Mp(0,1) = vp(0); Mp(0,2) = wp(0); Mp(0,3) = yp(0);
        Mp(1,0) = up(1); Mp(1,1) = vp(1); Mp(1,2) = wp(1); Mp(1,3) = yp(1);
        Mp(2,0) = up(2); Mp(2,1) = vp(2); Mp(2,2) = wp(2); Mp(2,3) = yp(2);
        Mp(3,0) = up(3); Mp(3,1) = vp(3); Mp(3,2) = wp(3); Mp(3,3) = yp(3);


        M.invertInPlace();
        fullMatrix<double> T(4,4);
        Mp.mult(M, T);

        for(int k = 3*order; k < fp.size1(); k++) {
          fullVector<double> pnt(4);
          pnt(0) = fp(k,0);
          pnt(1) = fp(k,1);
          pnt(2) = 0.0;
          pnt(3) = 1.0;

          fullVector<double> res(4);
          T.mult(pnt, res);

          points(p, 0) = res(0);
          points(p, 1) = res(1);
          points(p, 2) = res(2);

          p++;

        }
      }

      fullMatrix<double> fpq = gmshGeneratePointsQuad(order-2, false);
      fullMatrix<double> transform(2,2);
      fullMatrix<double> scaled(fpq.size1(), fpq.size2());
      transform(0,0) = (order-2)/(double)order; transform(0,1) = 0.0;
      transform(1,0) = 0.0; transform(1,1) = (order-2)/(double)order;
      fpq.mult(transform, scaled);

      for (int i = 0; i < scaled.size1(); i++) {
        points(p, 0) = scaled(i, 1);
        points(p, 1) = scaled(i, 0);
        points(p, 2) = 0.0;
        p++;
      }

      // Volume
      if (!serendip and order > 2) {
        fullMatrix<double> volume_points = gmshGeneratePointsPyramid(order - 3, false);
        // scale to order-3/order
        fullMatrix<double> T(3,3);
        T(0,0) = (order - 3.0) / order; T(0,1) = 0.0;                   T(0,2) = 0.0;
        T(1,0) = 0.0;                   T(1,1) = (order - 3.0) / order; T(1,2) = 0.0;
        T(2,0) = 0.0;                   T(2,1) = 0.0;                   T(2,2) = (order - 3.0) / order;
        fullMatrix<double> scaled(volume_points.size1(), volume_points.size2());
        volume_points.mult(T, scaled);

        // translate 1/order
        for (int i = 0; i < scaled.size1(); i++) {
          points(p, 0) = scaled(i,0);
          points(p, 1) = scaled(i,1);
          points(p, 2) = scaled(i,2) + 1.0/order;
          p++;
        }
      }
    }
    return points;
}



static void generate1dVertexClosure(nodalBasis::clCont &closure, int order)
{
  closure.clear();
  closure.resize(2);
  closure[0].push_back(0);
  closure[1].push_back(order == 0 ? 0 : 1);
  closure[0].type = MSH_PNT;
  closure[1].type = MSH_PNT;
}



static void generate1dVertexClosureFull(nodalBasis::clCont &closure,
                                        std::vector<int> &closureRef, int order)
{
  closure.clear();
  closure.resize(2);
  closure[0].push_back(0);
  if (order != 0) {
    closure[0].push_back(1);
    closure[1].push_back(1);
  }
  closure[1].push_back(0);
  for (int i = 0; i < order - 1; i++) {
    closure[0].push_back(2 + i);
    closure[1].push_back(2 + order - 2 - i);
  }
  closureRef.resize(2);
  closureRef[0] = 0;
  closureRef[1] = 0;
}



static void getFaceClosureTet(int iFace, int iSign, int iRotate,
                              nodalBasis::closure &closure, int order)
{
  closure.clear();
  closure.resize((order + 1) * (order + 2) / 2);
  closure.type = nodalBasis::getTag(TYPE_TRI, order, false);

  switch (order){
  case 0:
    closure[0] = 0;
    break;
  default:
    int face[4][3] = {{-3, -2, -1}, {1, -6, 4}, {-4, 5, 3}, {6, 2, -5}};
    int order1node[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
    for (int i = 0; i < 3; ++i){
      int k = (3 + (iSign * i) + iRotate) % 3;  //- iSign * iRotate
      closure[i] = order1node[iFace][k];
    }
    for (int i = 0;i < 3; ++i){
      int edgenumber = iSign *
        face[iFace][(6 + i * iSign + (-1 + iSign) / 2 + iRotate) % 3];  //- iSign * iRotate
      for (int k = 0; k < (order - 1); k++){
        if (edgenumber > 0)
          closure[3 + i * (order - 1) + k] =
            4 + (edgenumber - 1) * (order - 1) + k;
        else
          closure[3 + i * (order - 1) + k] =
            4 + (-edgenumber) * (order - 1) - 1 - k;
      }
    }
    int fi = 3 + 3 * (order - 1);
    int ti = 4 + 6 * (order - 1);
    int ndofff = (order - 3 + 2) * (order - 3 + 1) / 2;
    ti = ti + iFace * ndofff;
    for (int k = 0; k < order / 3; k++){
      int orderint = order - 3 - k * 3;
      if (orderint > 0){
        for (int ci = 0; ci < 3 ; ci++){
          int  shift = (3 + iSign * ci + iRotate) % 3;  //- iSign * iRotate
          closure[fi + ci] = ti + shift;
        }
        fi = fi + 3; ti = ti + 3;
        for (int l = 0; l < orderint - 1; l++){
          for (int ei = 0; ei < 3; ei++){
            int edgenumber = (6 + ei * iSign + (-1 + iSign) / 2 + iRotate) % 3;
                     //- iSign * iRotate
            if (iSign > 0)
              closure[fi + ei * (orderint - 1) + l] =
                ti + edgenumber * (orderint - 1) + l;
            else
              closure[fi + ei * (orderint - 1) + l] =
                ti + (1 + edgenumber) * (orderint - 1) - 1 - l;
          }
        }
        fi = fi + 3 * (orderint - 1); ti = ti + 3 * (orderint - 1);
      }
      else {
        closure[fi] = ti;
        ti++;
        fi++;
      }
    }
    break;
  }
}



static void generate2dEdgeClosureFull(nodalBasis::clCont &closure,
                                      std::vector<int> &closureRef,
                                      int order, int nNod, bool serendip)
{
  closure.clear();
  closure.resize(2*nNod);
  closureRef.resize(2*nNod);
  int shift = 0;
  for (int corder = order; corder>=0; corder -= (nNod == 3 ? 3 : 2)) {
    if (corder == 0) {
      for (int r = 0; r < nNod ; r++){
        closure[r].push_back(shift);
        closure[r+nNod].push_back(shift);
      }
      break;
    }
    for (int r = 0; r < nNod ; r++){
      for (int j = 0; j < nNod; j++) {
        closure[r].push_back(shift + (r + j) % nNod);
        closure[r + nNod].push_back(shift + (r - j + 1 + nNod) % nNod);
      }
    }
    shift += nNod;
    int n = nNod*(corder-1);
    for (int r = 0; r < nNod ; r++){
      for (int j = 0; j < n; j++){
        closure[r].push_back(shift + (j + (corder - 1) * r) % n);
        closure[r + nNod].push_back(shift + (n - j - 1 + (corder - 1) * (r + 1)) % n);
      }
    }
    shift += n;
    if (serendip) break;
  }
  for (int r = 0; r < nNod*2 ; r++) {
    closure[r].type = nodalBasis::getTag(TYPE_LIN, order);
    closureRef[r] = 0;
  }
}



static void addEdgeNodes(nodalBasis::clCont &closureFull, const int *edges, int order)
{
  if (order < 2)
    return;
  int numNodes = 0;
  for (int i = 0; edges[i] >= 0; ++i) {
    numNodes = std::max(numNodes, edges[i] + 1);
  }
  std::vector<std::vector<int> > nodes2edges(numNodes, std::vector<int>(numNodes, -1));
  for (int i = 0; edges[i] >= 0; i += 2) {
    nodes2edges[edges[i]][edges[i + 1]] = i;
    nodes2edges[edges[i + 1]][edges[i]] = i + 1;
  }
  for (unsigned int iClosure = 0; iClosure < closureFull.size(); iClosure++) {
    std::vector<int> &cl = closureFull[iClosure];
    for (int iEdge = 0; edges[iEdge] >= 0; iEdge += 2) {
      if (cl.empty())
        continue;
      int n0 = cl[edges[iEdge]];
      int n1 = cl[edges[iEdge + 1]];
      int oEdge = nodes2edges[n0][n1];
      if (oEdge == -1)
        Msg::Error("invalid p1 closure or invalid edges list");
      for (int i = 0 ; i < order - 1; i++)
        cl.push_back(numNodes + oEdge/2 * (order - 1) + ((oEdge % 2) ?  order - 2 - i : i));
    }
  }
}



static void generateFaceClosureTet(nodalBasis::clCont &closure, int order)
{
  closure.clear();
  for (int iRotate = 0; iRotate < 3; iRotate++){
    for (int iSign = 1; iSign >= -1; iSign -= 2){
      for (int iFace = 0; iFace < 4; iFace++){
        nodalBasis::closure closure_face;
        getFaceClosureTet(iFace, iSign, iRotate, closure_face, order);
        closure.push_back(closure_face);
      }
    }
  }
}



static void generateFaceClosureTetFull(nodalBasis::clCont &closureFull,
                                       std::vector<int> &closureRef,
                                       int order, bool serendip)
{
  closureFull.clear();
  //input :
  static const short int faces[4][3] = {{0,1,2}, {0,3,1}, {0,2,3}, {3,2,1}};
  static const int edges[] = {0, 1,  1, 2,  2, 0,  3, 0,  3, 2,  3, 1,  -1};
  static const int faceOrientation[6] = {0,1,2,5,3,4};
  closureFull.resize(24);
  closureRef.resize(24);
  for (int i = 0; i < 24; i ++)
    closureRef[i] = 0;
  if (order == 0) {
    for (int i = 0; i < 24; i ++) {
      closureFull[i].push_back(0);
    }
    return;
  }
  //Mapping for the p1 nodes
  nodalBasis::clCont closure;
  generateFaceClosureTet(closure, 1);
  for (unsigned int i = 0; i < closureFull.size(); i++) {
    std::vector<int> &clFull = closureFull[i];
    std::vector<int> &cl = closure[i];
    clFull.resize(4, -1);
    closureRef[i] = 0;
    for (unsigned int j = 0; j < cl.size(); j ++)
      clFull[closure[0][j]] = cl[j];
    for (int j = 0; j < 4; j ++)
      if (clFull[j] == -1)
        clFull[j] = (6 - clFull[(j + 1) % 4] - clFull[(j + 2) % 4] - clFull[(j + 3) % 4]);
  }
  int nodes2Faces[4][4][4];
  for (int i = 0; i < 4; i++) {
    for (int iRotate = 0; iRotate < 3; iRotate ++) {
      short int n0 = faces[i][(3 - iRotate) % 3];
      short int n1 = faces[i][(4 - iRotate) % 3];
      short int n2 = faces[i][(5 - iRotate) % 3];
      nodes2Faces[n0][n1][n2] = i * 6 + iRotate;
      nodes2Faces[n0][n2][n1] = i * 6 + iRotate + 3;
    }
  }
  nodalBasis::clCont closureTriangles;
  std::vector<int> closureTrianglesRef;
  if (order >= 3)
    generate2dEdgeClosureFull(closureTriangles, closureTrianglesRef, order - 3, 3, false);
  addEdgeNodes(closureFull, edges, order);
  for (unsigned int iClosure = 0; iClosure < closureFull.size(); iClosure++) {
    //faces
    std::vector<int> &cl = closureFull[iClosure];
    if (order >= 3) {
      for (int iFace = 0; iFace < 4; iFace ++) {
        int n0 = cl[faces[iFace][0]];
        int n1 = cl[faces[iFace][1]];
        int n2 = cl[faces[iFace][2]];
        short int id = nodes2Faces[n0][n1][n2];
        short int iTriClosure = faceOrientation [id % 6];
        short int idFace = id/6;
        int nOnFace = closureTriangles[iTriClosure].size();
        for (int i = 0; i < nOnFace; i++) {
          cl.push_back(4 + 6 * (order - 1) + idFace * nOnFace +
                       closureTriangles[iTriClosure][i]);
        }
      }
    }
  }
  if (order >= 4 && !serendip) {
    nodalBasis::clCont insideClosure;
    std::vector<int> fakeClosureRef;
    generateFaceClosureTetFull(insideClosure, fakeClosureRef, order - 4, false);
    for (unsigned int i = 0; i < closureFull.size(); i ++) {
      unsigned int shift = closureFull[i].size();
      for (unsigned int j = 0; j < insideClosure[i].size(); j++)
        closureFull[i].push_back(insideClosure[i][j] + shift);
    }
  }
}



void rotateHex(int iFace, int iRot, int iSign, double uI, double vI,
               double &uO, double &vO, double &wO)
{
  if (iSign<0){
    double tmp=uI;
    uI=vI;
    vI=tmp;
  }
  for (int i=0; i < iRot; i++){
    double tmp=uI;
    uI=-vI;
    vI=tmp;
  }
  switch (iFace) {
    case 0: uO = vI; vO = uI; wO=-1; break;
    case 1: uO = uI; vO = -1; wO=vI; break;
    case 2: uO =-1;  vO = vI; wO=uI; break;
    case 3: uO = 1;  vO = uI; wO=vI; break;
    case 4: uO =-uI; vO = 1;  wO=vI; break;
    case 5: uO =uI;  vO = vI; wO=1; break;
  }
}



void rotateHexFull(int iFace, int iRot, int iSign, double uI, double vI, double wI, double &uO, double &vO, double &wO)
{
  switch (iFace) {
    case 0: uO = uI; vO = vI; wO = wI; break;
    case 1: uO = wI; vO = uI; wO = vI; break;
    case 2: uO = vI; vO = wI; wO = uI; break;
    case 3: uO = wI; vO = vI; wO =-uI; break;
    case 4: uO = wI; vO =-uI; wO =-vI; break;
    case 5: uO = vI; vO = uI; wO =-wI; break;
  }
  for (int i = 0; i < iRot; i++){
    double tmp = uO;
    uO = -vO;
    vO = tmp;
  }
  if (iSign<0){
    double tmp = uO;
    uO = vO;
    vO = tmp;
  }
}



inline static double pow2(double x)
{
  return x * x;
}

/*
static void checkClosure(int tag) {
  printf("TYPE = %i\n", tag);
  const nodalBasis &fs = *nodalBases::find(tag);
  for (int i = 0; i < fs.closures.size(); ++i) {
    const std::vector<int> &clRef = fs.closures[fs.closureRef[i]];
    const std::vector<int> &cl = fs.closures[i];
    const std::vector<int> &clFull = fs.fullClosures[i];
    printf("i = %i\n", i);
    for (int j = 0; j < cl.size(); ++j) {
      printf("%3i ", clFull[clRef[j]]);
    }
    printf("\n");
    for (int j = 0; j < cl.size(); ++j) {
      printf("%3i ", cl[j]);
    }
    printf("\n");
  }
}
*/



static void generateFaceClosureHex(nodalBasis::clCont &closure, int order,
                                   bool serendip, const fullMatrix<double> &points)
{
  closure.clear();
  const nodalBasis &fsFace = *BasisFactory::create(nodalBasis::getTag(TYPE_QUA, order, serendip));
  for (int iRotate = 0; iRotate < 4; iRotate++){
    for (int iSign = 1; iSign >= -1; iSign -= 2){
      for (int iFace = 0; iFace < 6; iFace++) {
        nodalBasis::closure cl;
        cl.type = fsFace.type;
        cl.resize(fsFace.points.size1());
        for (unsigned int iNode = 0; iNode < cl.size(); ++iNode) {
          double u,v,w;
          rotateHex(iFace, iRotate, iSign, fsFace.points(iNode, 0),
                    fsFace.points(iNode, 1), u, v, w);
          cl[iNode] = 0;
          double D = std::numeric_limits<double>::max();
          for (int jNode = 0; jNode < points.size1(); ++jNode) {
            double d = pow2(points(jNode, 0) - u) + pow2(points(jNode, 1) - v) +
              pow2(points(jNode, 2) - w);
            if (d < D) {
              cl[iNode] = jNode;
              D = d;
            }
          }
        }
        closure.push_back(cl);
      }
    }
  }
}



static void generateFaceClosureHexFull(nodalBasis::clCont &closure,
                                       std::vector<int> &closureRef,
                                       int order, bool serendip,
                                       const fullMatrix<double> &points)
{
  closure.clear();
  int clId = 0;
  for (int iRotate = 0; iRotate < 4; iRotate++){
    for (int iSign = 1; iSign >= -1; iSign -= 2){
      for (int iFace = 0; iFace < 6; iFace++) {
        nodalBasis::closure cl;
        cl.resize(points.size1());
        for (int iNode = 0; iNode < points.size1(); ++iNode) {
          double u,v,w;
          rotateHexFull(iFace, iRotate, iSign, points(iNode, 0), points(iNode, 1),
                        points(iNode, 2), u, v, w);
          int J = 0;
          double D = std::numeric_limits<double>::max();
          for (int jNode = 0; jNode < points.size1(); ++jNode) {
            double d = pow2(points(jNode, 0) - u) + pow2(points(jNode, 1) - v) +
              pow2(points(jNode, 2) - w);
            if (d < D) {
              J = jNode;
              D = d;
            }
          }
          cl[J] = iNode;
        }
        closure.push_back(cl);
        closureRef.push_back(0);
        clId ++;
      }
    }
  }
}



static void getFaceClosurePrism(int iFace, int iSign, int iRotate,
                                nodalBasis::closure &closure, int order)
{
  if (order > 2)
    Msg::Error("FaceClosure not implemented for prisms of order %d",order);
  bool isTriangle = iFace<2;
  int nNodes = isTriangle ? (order+1)*(order+2)/2 : (order+1)*(order+1);
  closure.clear();
  if (isTriangle && iRotate > 2) return;
  closure.resize(nNodes);
  if (order==0) {
    closure[0] = 0;
    return;
  }
  int order1node[5][4] = {{0, 2, 1, -1}, {3, 4, 5, -1}, {0, 1, 4, 3}, {0, 3, 5, 2},
                          {1, 2, 5, 4}};
  int order2node[5][5] = {{7, 9, 6, -1, -1}, {12, 14, 13, -1, -1}, {6, 10, 12, 8, 15},
                          {8, 13, 11, 7, 16}, {9, 11, 14, 10, 17}};
  // int order2node[5][4] = {{7, 9, 6, -1}, {12, 14, 13, -1}, {6, 10, 12, 8},
  //                         {8, 13, 11, 7}, {9, 11, 14, 10}};
  int nVertex = isTriangle ? 3 : 4;
  closure.type = nodalBasis::getTag(isTriangle ? TYPE_TRI : TYPE_QUA, order);
  for (int i = 0; i < nVertex; ++i){
    int k = (nVertex + (iSign * i) + iRotate) % nVertex;  //- iSign * iRotate
    closure[i] = order1node[iFace][k];
  }
  if (order==2) {
    for (int i = 0; i < nVertex; ++i){
      int k = (nVertex + (iSign==-1?-1:0) + (iSign * i) + iRotate) % nVertex;
                //- iSign * iRotate
      closure[nVertex+i] = order2node[iFace][k];
    }
    if (!isTriangle)
      closure[nNodes-1] = order2node[iFace][4]; // center
  }
}



static void generateFaceClosurePrism(nodalBasis::clCont &closure, int order)
{
  closure.clear();
  for (int iRotate = 0; iRotate < 4; iRotate++){
    for (int iSign = 1; iSign >= -1; iSign -= 2){
      for (int iFace = 0; iFace < 5; iFace++){
        nodalBasis::closure closure_face;
        getFaceClosurePrism(iFace, iSign, iRotate, closure_face, order);
        closure.push_back(closure_face);
      }
    }
  }
}



static void generateFaceClosurePrismFull(nodalBasis::clCont &closureFull,
                                         std::vector<int> &closureRef, int order)
{
  nodalBasis::clCont closure;
  closureFull.clear();
  closureFull.resize(40);
  closureRef.resize(40);
  generateFaceClosurePrism(closure, 1);
  int ref3 = -1, ref4a = -1, ref4b = -1;
  for (unsigned int i = 0; i < closure.size(); i++) {
    std::vector<int> &clFull = closureFull[i];
    std::vector<int> &cl = closure[i];
    if (cl.size() == 0)
      continue;
    clFull.resize(6, -1);
    int &ref = cl.size() == 3 ? ref3 : (cl[0] / 3 + cl[1] / 3) % 2 ? ref4b : ref4a;
    if (ref == -1)
      ref = i;
    closureRef[i] = ref;
    for (unsigned int j = 0; j < cl.size(); j ++)
      clFull[closure[ref][j]] = cl[j];
    for (int j = 0; j < 6; j ++) {
      if (clFull[j] == -1) {
        int k = ((j / 3) + 1) % 2 * 3;
        int sum = (clFull[k + (j + 1) % 3] + clFull[k + (j + 2) % 3]);
        clFull[j] = ((sum / 6 + 1) % 2) * 3 + (12 - sum) % 3;
      }
    }
  }
  static const int edges[] = {0, 1,  0, 2,  0, 3,  1, 2,  1, 4,  2, 5,
                              3, 4,  3, 5,  4, 5,  -1};
  addEdgeNodes(closureFull, edges, order);
  if ( order < 2 )
    return;
  // face center nodes for p2 prism
  static const int faces[5][4] = {{0, 2, 1, -1}, {3, 4, 5, -1}, {0, 1, 4,  3},
                                  {0, 3, 5,  2}, {1, 2, 5,  4}};

  if ( order == 2 ) {
    int nextFaceNode = 15;
    int numFaces = 5;
    int numFaceNodes = 4;
    std::map<int,int> nodeSum2Face;
    for (int iFace = 0; iFace < numFaces ; iFace ++) {
      int nodeSum = 0;
      for (int iNode = 0; iNode < numFaceNodes; iNode++ ) {
        nodeSum += faces[iFace][iNode];
      }
      nodeSum2Face[nodeSum] = iFace;
    }
    for (unsigned int i = 0; i < closureFull.size(); i++ ) {
      if (closureFull[i].empty())
        continue;
      for (int iFace = 0; iFace < numFaces; iFace++ ) {
        int nodeSum = 0;
        for (int iNode = 0; iNode < numFaceNodes; iNode++)
          nodeSum += faces[iFace][iNode] < 0 ? faces[iFace][iNode] :
            closureFull[i][ faces[iFace][iNode] ];
        std::map<int,int>::iterator it = nodeSum2Face.find(nodeSum);
        if (it == nodeSum2Face.end() )
          Msg::Error("Prism face not found");
        int mappedFaceId = it->second;
        if ( mappedFaceId > 1) {
          closureFull[i].push_back(nextFaceNode + mappedFaceId - 2);
        }
      }
    }
  } else {
    Msg::Error("FaceClosureFull not implemented for prisms of order %d",order);
  }

}



static void generate2dEdgeClosure(nodalBasis::clCont &closure, int order, int nNod = 3)
{
  closure.clear();
  closure.resize(2*nNod);
  for (int j = 0; j < nNod ; j++){
    closure[j].push_back(j);
    closure[j].push_back((j+1)%nNod);
    closure[nNod+j].push_back((j+1)%nNod);
    closure[nNod+j].push_back(j);
    for (int i=0; i < order-1; i++){
      closure[j].push_back( nNod + (order-1)*j + i );
      closure[nNod+j].push_back(nNod + (order-1)*(j+1) -i -1);
    }
    closure[j].type = closure[nNod+j].type = nodalBasis::getTag(TYPE_LIN, order);
  }
}



static void generateClosureOrder0(nodalBasis::clCont &closure, int nb)
{
  closure.clear();
  closure.resize(nb);
  for (int i=0; i < nb; i++) {
    closure[i].push_back(0);
    closure[i].type = MSH_PNT;
  }
}



nodalBasis::nodalBasis(int tag)
{

  type = tag;

  switch (tag) {
  case MSH_PNT     : parentType = TYPE_PNT; order = 0; serendip = false; break;
  case MSH_LIN_1   : parentType = TYPE_LIN; order = 0; serendip = false; break;
  case MSH_LIN_2   : parentType = TYPE_LIN; order = 1; serendip = false; break;
  case MSH_LIN_3   : parentType = TYPE_LIN; order = 2; serendip = false; break;
  case MSH_LIN_4   : parentType = TYPE_LIN; order = 3; serendip = false; break;
  case MSH_LIN_5   : parentType = TYPE_LIN; order = 4; serendip = false; break;
  case MSH_LIN_6   : parentType = TYPE_LIN; order = 5; serendip = false; break;
  case MSH_LIN_7   : parentType = TYPE_LIN; order = 6; serendip = false; break;
  case MSH_LIN_8   : parentType = TYPE_LIN; order = 7; serendip = false; break;
  case MSH_LIN_9   : parentType = TYPE_LIN; order = 8; serendip = false; break;
  case MSH_LIN_10  : parentType = TYPE_LIN; order = 9; serendip = false; break;
  case MSH_LIN_11  : parentType = TYPE_LIN; order = 10;serendip = false; break;
  case MSH_TRI_1   : parentType = TYPE_TRI; order = 0; serendip = false; break;
  case MSH_TRI_3   : parentType = TYPE_TRI; order = 1; serendip = false; break;
  case MSH_TRI_6   : parentType = TYPE_TRI; order = 2; serendip = false; break;
  case MSH_TRI_10  : parentType = TYPE_TRI; order = 3; serendip = false; break;
  case MSH_TRI_15  : parentType = TYPE_TRI; order = 4; serendip = false; break;
  case MSH_TRI_21  : parentType = TYPE_TRI; order = 5; serendip = false; break;
  case MSH_TRI_28  : parentType = TYPE_TRI; order = 6; serendip = false; break;
  case MSH_TRI_36  : parentType = TYPE_TRI; order = 7; serendip = false; break;
  case MSH_TRI_45  : parentType = TYPE_TRI; order = 8; serendip = false; break;
  case MSH_TRI_55  : parentType = TYPE_TRI; order = 9; serendip = false; break;
  case MSH_TRI_66  : parentType = TYPE_TRI; order = 10;serendip = false; break;
  case MSH_TRI_9   : parentType = TYPE_TRI; order = 3; serendip = true;  break;
  case MSH_TRI_12  : parentType = TYPE_TRI; order = 4; serendip = true;  break;
  case MSH_TRI_15I : parentType = TYPE_TRI; order = 5; serendip = true;  break;
  case MSH_TRI_18  : parentType = TYPE_TRI; order = 6; serendip = true;  break;
  case MSH_TRI_21I : parentType = TYPE_TRI; order = 7; serendip = true;  break;
  case MSH_TRI_24  : parentType = TYPE_TRI; order = 8; serendip = true;  break;
  case MSH_TRI_27  : parentType = TYPE_TRI; order = 9; serendip = true;  break;
  case MSH_TRI_30  : parentType = TYPE_TRI; order = 10;serendip = true;  break;
  case MSH_TET_1   : parentType = TYPE_TET; order = 0; serendip = false; break;
  case MSH_TET_4   : parentType = TYPE_TET; order = 1; serendip = false; break;
  case MSH_TET_10  : parentType = TYPE_TET; order = 2; serendip = false; break;
  case MSH_TET_20  : parentType = TYPE_TET; order = 3; serendip = false; break;
  case MSH_TET_35  : parentType = TYPE_TET; order = 4; serendip = false; break;
  case MSH_TET_56  : parentType = TYPE_TET; order = 5; serendip = false; break;
  case MSH_TET_84  : parentType = TYPE_TET; order = 6; serendip = false; break;
  case MSH_TET_120 : parentType = TYPE_TET; order = 7; serendip = false; break;
  case MSH_TET_165 : parentType = TYPE_TET; order = 8; serendip = false; break;
  case MSH_TET_220 : parentType = TYPE_TET; order = 9; serendip = false; break;
  case MSH_TET_286 : parentType = TYPE_TET; order = 10;serendip = false; break;
  case MSH_TET_34  : parentType = TYPE_TET; order = 4; serendip = true;  break;
  case MSH_TET_52  : parentType = TYPE_TET; order = 5; serendip = true;  break;
  case MSH_TET_74  : parentType = TYPE_TET; order = 6; serendip = true;  break;
  case MSH_TET_100 : parentType = TYPE_TET; order = 7; serendip = true;  break;
  case MSH_TET_130 : parentType = TYPE_TET; order = 8; serendip = true;  break;
  case MSH_TET_164 : parentType = TYPE_TET; order = 9; serendip = true;  break;
  case MSH_TET_202 : parentType = TYPE_TET; order = 10;serendip = true;  break;
  case MSH_QUA_1   : parentType = TYPE_QUA; order = 0; serendip = false; break;
  case MSH_QUA_4   : parentType = TYPE_QUA; order = 1; serendip = false; break;
  case MSH_QUA_9   : parentType = TYPE_QUA; order = 2; serendip = false; break;
  case MSH_QUA_16  : parentType = TYPE_QUA; order = 3; serendip = false; break;
  case MSH_QUA_25  : parentType = TYPE_QUA; order = 4; serendip = false; break;
  case MSH_QUA_36  : parentType = TYPE_QUA; order = 5; serendip = false; break;
  case MSH_QUA_49  : parentType = TYPE_QUA; order = 6; serendip = false; break;
  case MSH_QUA_64  : parentType = TYPE_QUA; order = 7; serendip = false; break;
  case MSH_QUA_81  : parentType = TYPE_QUA; order = 8; serendip = false; break;
  case MSH_QUA_100 : parentType = TYPE_QUA; order = 9; serendip = false; break;
  case MSH_QUA_121 : parentType = TYPE_QUA; order = 10;serendip = false; break;
  case MSH_QUA_8   : parentType = TYPE_QUA; order = 2; serendip = true;  break;
  case MSH_QUA_12  : parentType = TYPE_QUA; order = 3; serendip = true;  break;
  case MSH_QUA_16I : parentType = TYPE_QUA; order = 4; serendip = true;  break;
  case MSH_QUA_20  : parentType = TYPE_QUA; order = 5; serendip = true;  break;
  case MSH_QUA_24  : parentType = TYPE_QUA; order = 6; serendip = true;  break;
  case MSH_QUA_28  : parentType = TYPE_QUA; order = 7; serendip = true;  break;
  case MSH_QUA_32  : parentType = TYPE_QUA; order = 8; serendip = true;  break;
  case MSH_QUA_36I : parentType = TYPE_QUA; order = 9; serendip = true;  break;
  case MSH_QUA_40  : parentType = TYPE_QUA; order = 10;serendip = true;  break;
  case MSH_PRI_1   : parentType = TYPE_PRI; order = 0; serendip = false; break;
  case MSH_PRI_6   : parentType = TYPE_PRI; order = 1; serendip = false; break;
  case MSH_PRI_18  : parentType = TYPE_PRI; order = 2; serendip = false; break;
  case MSH_PRI_40  : parentType = TYPE_PRI; order = 3; serendip = false; break;
  case MSH_PRI_75  : parentType = TYPE_PRI; order = 4; serendip = false; break;
  case MSH_PRI_126 : parentType = TYPE_PRI; order = 5; serendip = false; break;
  case MSH_PRI_196 : parentType = TYPE_PRI; order = 6; serendip = false; break;
  case MSH_PRI_288 : parentType = TYPE_PRI; order = 7; serendip = false; break;
  case MSH_PRI_405 : parentType = TYPE_PRI; order = 8; serendip = false; break;
  case MSH_PRI_550 : parentType = TYPE_PRI; order = 9; serendip = false; break;
  case MSH_PRI_15  : parentType = TYPE_PRI; order = 2; serendip = true; break;
  case MSH_PRI_38  : parentType = TYPE_PRI; order = 3; serendip = true; break;
  case MSH_PRI_66  : parentType = TYPE_PRI; order = 4; serendip = true; break;
  case MSH_PRI_102 : parentType = TYPE_PRI; order = 5; serendip = true; break;
  case MSH_PRI_146 : parentType = TYPE_PRI; order = 6; serendip = true; break;
  case MSH_PRI_198 : parentType = TYPE_PRI; order = 7; serendip = true; break;
  case MSH_PRI_258 : parentType = TYPE_PRI; order = 8; serendip = true; break;
  case MSH_PRI_326 : parentType = TYPE_PRI; order = 9; serendip = true; break;
  case MSH_HEX_8   : parentType = TYPE_HEX; order = 1; serendip = false; break;
  case MSH_HEX_27  : parentType = TYPE_HEX; order = 2; serendip = false; break;
  case MSH_HEX_64  : parentType = TYPE_HEX; order = 3; serendip = false; break;
  case MSH_HEX_125 : parentType = TYPE_HEX; order = 4; serendip = false; break;
  case MSH_HEX_216 : parentType = TYPE_HEX; order = 5; serendip = false; break;
  case MSH_HEX_343 : parentType = TYPE_HEX; order = 6; serendip = false; break;
  case MSH_HEX_512 : parentType = TYPE_HEX; order = 7; serendip = false; break;
  case MSH_HEX_729 : parentType = TYPE_HEX; order = 8; serendip = false; break;
  case MSH_HEX_1000: parentType = TYPE_HEX; order = 9; serendip = false; break;
  case MSH_HEX_20  : parentType = TYPE_HEX; order = 2; serendip = false; break;
  case MSH_HEX_56  : parentType = TYPE_HEX; order = 3; serendip = true; break;
  case MSH_HEX_98  : parentType = TYPE_HEX; order = 4; serendip = true; break;
  case MSH_HEX_152 : parentType = TYPE_HEX; order = 5; serendip = true; break;
  case MSH_HEX_222 : parentType = TYPE_HEX; order = 6; serendip = true; break;
  case MSH_HEX_296 : parentType = TYPE_HEX; order = 7; serendip = true; break;
  case MSH_HEX_386 : parentType = TYPE_HEX; order = 8; serendip = true; break;
  case MSH_HEX_488 : parentType = TYPE_HEX; order = 9; serendip = true; break;
  case MSH_PYR_5   : parentType = TYPE_PYR; order = 1; serendip = false; break;
  case MSH_PYR_14  : parentType = TYPE_PYR; order = 2; serendip = false; break;
  case MSH_PYR_30  : parentType = TYPE_PYR; order = 3; serendip = false; break;
  case MSH_PYR_55  : parentType = TYPE_PYR; order = 4; serendip = false; break;
  case MSH_PYR_91  : parentType = TYPE_PYR; order = 5; serendip = false; break;
  case MSH_PYR_140 : parentType = TYPE_PYR; order = 6; serendip = false; break;
  case MSH_PYR_204 : parentType = TYPE_PYR; order = 7; serendip = false; break;
  case MSH_PYR_285 : parentType = TYPE_PYR; order = 8; serendip = false; break;
  case MSH_PYR_385 : parentType = TYPE_PYR; order = 9; serendip = false; break;
  case MSH_PYR_13  : parentType = TYPE_PYR; order = 2; serendip = false; break;
  case MSH_PYR_29  : parentType = TYPE_PYR; order = 3; serendip = true; break;
  case MSH_PYR_50  : parentType = TYPE_PYR; order = 4; serendip = true; break;
  case MSH_PYR_77  : parentType = TYPE_PYR; order = 5; serendip = true; break;
  case MSH_PYR_110 : parentType = TYPE_PYR; order = 6; serendip = true; break;
  case MSH_PYR_149 : parentType = TYPE_PYR; order = 7; serendip = true; break;
  case MSH_PYR_194 : parentType = TYPE_PYR; order = 8; serendip = true; break;
  case MSH_PYR_245 : parentType = TYPE_PYR; order = 9; serendip = true; break;
  default :
    Msg::Error("Unknown function space %d: reverting to TET_4", tag);
    parentType = TYPE_TET; order = 1; serendip = false; break;
  }


  switch (parentType) {
  case TYPE_PNT :
    numFaces = 1;
    dimension = 0;
    points = generate1DPoints(0);
    break;
  case TYPE_LIN :
    numFaces = 2;
    dimension = 1;
    points = generate1DPoints(order);
    generate1dVertexClosure(closures, order);
    generate1dVertexClosureFull(fullClosures, closureRef, order);
    break;
  case TYPE_TRI :
    numFaces = 3;
    dimension = 2;
    points = gmshGeneratePointsTriangle(order, serendip);
    if (order == 0) {
      generateClosureOrder0(closures, 6);
      generateClosureOrder0(fullClosures, 6);
      closureRef.resize(6, 0);
    }
    else {
      generate2dEdgeClosure(closures, order);
      generate2dEdgeClosureFull(fullClosures, closureRef, order, 3, serendip);
    }
    break;
  case TYPE_QUA :
    numFaces = 4;
    dimension = 2;
    points = gmshGeneratePointsQuad(order, serendip);
    if (order == 0) {
      generateClosureOrder0(closures, 8);
      generateClosureOrder0(fullClosures, 8);
      closureRef.resize(8, 0);
    }
    else {
      generate2dEdgeClosure(closures, order, 4);
      generate2dEdgeClosureFull(fullClosures, closureRef, order, 4, serendip);
    }
    break;
  case TYPE_TET :
    numFaces = 4;
    dimension = 3;
    points = gmshGeneratePointsTetrahedron(order, serendip);
    if (order == 0) {
      generateClosureOrder0(closures,24);
      generateClosureOrder0(fullClosures, 24);
      closureRef.resize(24, 0);
    }
    else {
      generateFaceClosureTet(closures, order);
      generateFaceClosureTetFull(fullClosures, closureRef, order, serendip);
    }
    break;
  case TYPE_PRI :
    numFaces = 5;
    dimension = 3;
    points = gmshGeneratePointsPrism(order, serendip);
    if (order == 0) {
      generateClosureOrder0(closures,48);
      generateClosureOrder0(fullClosures,48);
      closureRef.resize(48, 0);
    }
    else {
      generateFaceClosurePrism(closures, order);
      generateFaceClosurePrismFull(fullClosures, closureRef, order);
    }
    break;
  case TYPE_HEX :
    numFaces = 6;
    dimension = 3;
    points = gmshGeneratePointsHex(order, serendip);
    generateFaceClosureHex(closures, order, serendip, points);
    generateFaceClosureHexFull(fullClosures, closureRef, order, serendip, points);
    break;
  case TYPE_PYR :
    numFaces = 5;
    dimension = 3;
    points = gmshGeneratePointsPyramid(order, serendip);
    break;
  }

}
