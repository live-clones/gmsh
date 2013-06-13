// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "pointsGenerators.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"

/* --- Lines --- */

fullMatrix<double> gmshGeneratePointsLine(int order)
{
  fullMatrix<double> points(order + 1, 1);
  points(0,0) = 0;
  if (order > 0) {
    points(0, 0) = -1.;
    points(1, 0) =  1.;
    double dd = 2. / order;
    for (int i = 2; i < order + 1; i++) points(i, 0) = -1. + dd * (i - 1);
  }
  return points;
}

/* --- Triangles --- */

fullMatrix<double> gmshGeneratePointsTriangle(int order, bool serendip)
{
  int nbPoints = serendip ? 3 * order : (order + 1) * (order + 2) / 2;
  fullMatrix<double> points(nbPoints, 2);

  points(0, 0) = 0;
  points(0, 1) = 0;

  if (order > 0) {
    double dd = 1. / order;

    points(1, 0) = 1;
    points(1, 1) = 0;
    points(2, 0) = 0;
    points(2, 1) = 1;

    int index = 3;

    if (order > 1) {

      double ksi = 0;
      double eta = 0;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi += dd;
        points(index, 0) = ksi;
        points(index, 1) = eta;
      }

      ksi = 1.;

      for (int i = 0; i < order - 1; i++, index++) {
        ksi -= dd;
        eta += dd;
        points(index, 0) = ksi;
        points(index, 1) = eta;
      }

      eta = 1.;
      ksi = 0.;

      for (int i = 0; i < order - 1; i++, index++) {
        eta -= dd;
        points(index, 0) = ksi;
        points(index, 1) = eta;
      }

      if (order > 2 && !serendip) {
        fullMatrix<double> inner = gmshGeneratePointsTriangle(order - 3, serendip);
        inner.scale(1. - 3. * dd);
        inner.add(dd);
        points.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }
  return points;
}

/* --- Quadrangles --- */

fullMatrix<double> gmshGeneratePointsQuadrangle(int order, bool serendip)
{
  int nbPoints = serendip ? order*4 : (order+1)*(order+1);
  fullMatrix<double> points(nbPoints, 2);

  if (order > 0) {
    points(0, 0) = -1;
    points(0, 1) = -1;
    points(1, 0) = 1;
    points(1, 1) = -1;
    points(2, 0) = 1;
    points(2, 1) = 1;
    points(3, 0) = -1;
    points(3, 1) = 1;

    if (order > 1) {
      int index = 4;
      const static int edges[4][2]={{0,1},{1,2},{2,3},{3,0}};
      for (int iedge=0; iedge<4; iedge++) {
        int p0 = edges[iedge][0];
        int p1 = edges[iedge][1];
        for (int i = 1; i < order; i++, index++) {
          points(index, 0) = points(p0, 0) + i*(points(p1,0)-points(p0,0))/order;
          points(index, 1) = points(p0, 1) + i*(points(p1,1)-points(p0,1))/order;
        }
      }
      if (order >= 2 && !serendip) {
        fullMatrix<double> inner = gmshGeneratePointsQuadrangle(order-2, false);
        inner.scale(1. - 2./order);
        points.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }
  else {
    points(0, 0) = 0;
    points(0, 1) = 0;
  }
  return points;


}

/* --- Tetahedra --- */

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


fullMatrix<double> gmshGeneratePointsTetrahedron(int order, bool serendip)
{

  int nbPoints =
    (serendip ?
     4 +  6 * std::max(0, order - 1) + 4 * std::max(0, (order - 2) * (order - 1) / 2) :
     (order + 1) * (order + 2) * (order + 3) / 6);

  fullMatrix<double> points(nbPoints, 3);

  double overOrder = (order == 0 ? 1. : 1. / order);

  points(0, 0) = 0.;
  points(0, 1) = 0.;
  points(0, 2) = 0.;

  if (order > 0) {
    points(1, 0) = order;
    points(1, 1) = 0;
    points(1, 2) = 0;

    points(2, 0) = 0.;
    points(2, 1) = order;
    points(2, 2) = 0.;

    points(3, 0) = 0.;
    points(3, 1) = 0.;
    points(3, 2) = order;

    // edges e5 and e6 switched in original version, opposite direction
    // the template has been defined in table edges_tetra and faces_tetra (MElement.h)

    if (order > 1) {
      for (int k = 0; k < (order - 1); k++) {
        points(4 + k, 0) = k + 1;
        points(4 +      order - 1  + k, 0) = order - 1 - k;
        points(4 + 2 * (order - 1) + k, 0) = 0.;
        points(4 + 3 * (order - 1) + k, 0) = 0.;
        // points(4 + 4 * (order - 1) + k, 0) = order - 1 - k;
        // points(4 + 5 * (order - 1) + k, 0) = 0.;
        points(4 + 4 * (order - 1) + k, 0) = 0.;
        points(4 + 5 * (order - 1) + k, 0) = k+1;

        points(4 + k, 1) = 0.;
        points(4 +      order - 1  + k, 1) = k + 1;
        points(4 + 2 * (order - 1) + k, 1) = order - 1 - k;
        points(4 + 3 * (order - 1) + k, 1) = 0.;
        //         points(4 + 4 * (order - 1) + k, 1) = 0.;
        //         points(4 + 5 * (order - 1) + k, 1) = order - 1 - k;
        points(4 + 4 * (order - 1) + k, 1) = k+1;
        points(4 + 5 * (order - 1) + k, 1) = 0.;

        points(4 + k, 2) = 0.;
        points(4 +      order - 1  + k, 2) = 0.;
        points(4 + 2 * (order - 1) + k, 2) = 0.;
        points(4 + 3 * (order - 1) + k, 2) = order - 1 - k;
        points(4 + 4 * (order - 1) + k, 2) = order - 1 - k;
        points(4 + 5 * (order - 1) + k, 2) = order - 1 - k;
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
          points(ns + i, 0) = u[i] * (order - 3) + 1.;
          points(ns + i, 1) = v[i] * (order - 3) + 1.;
          points(ns + i, 2) = w[i] * (order - 3);
        }

        ns = ns + nbdofface;

        // u-w plane

        nodepositionface1(order - 3, u, v, w);

        for (int i=0; i < nbdofface; i++){
          points(ns + i, 0) = u[i] * (order - 3) + 1.;
          points(ns + i, 1) = v[i] * (order - 3) ;
          points(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        // v-w plane

        ns = ns + nbdofface;

        nodepositionface2(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          points(ns + i, 0) = u[i] * (order - 3);
          points(ns + i, 1) = v[i] * (order - 3) + 1.;
          points(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        // u-v-w plane

        ns = ns + nbdofface;

        nodepositionface3(order - 3, u, v, w);

        for (int i = 0; i < nbdofface; i++){
          points(ns + i, 0) = u[i] * (order - 3) + 1.;
          points(ns + i, 1) = v[i] * (order - 3) + 1.;
          points(ns + i, 2) = w[i] * (order - 3) + 1.;
        }

        ns = ns + nbdofface;

        delete [] u;
        delete [] v;
        delete [] w;

        if (!serendip && order > 3) {

          fullMatrix<double> interior = gmshGeneratePointsTetrahedron(order - 4, false);
          for (int k = 0; k < interior.size1(); k++) {
            points(ns + k, 0) = 1. + interior(k, 0) * (order - 4);
            points(ns + k, 1) = 1. + interior(k, 1) * (order - 4);
            points(ns + k, 2) = 1. + interior(k, 2) * (order - 4);
          }
        }
      }
    }
  }

  points.scale(overOrder);
  return points;

}



/* --- Hexahedra --- */

fullMatrix<double> gmshGeneratePointsHexahedron(int order, bool serendip)
{
  int nbPoints = (order+1)*(order+1)*(order+1);
  if (serendip) nbPoints -= (order-1)*(order-1)*(order-1);
  fullMatrix<double> points(nbPoints, 3);

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
    points(0, 0) = -1;
    points(0, 1) = -1;
    points(0, 2) = -1;
    points(1, 0) = 1;
    points(1, 1) = -1;
    points(1, 2) = -1;
    points(2, 0) = 1;
    points(2, 1) = 1;
    points(2, 2) = -1;
    points(3, 0) = -1;
    points(3, 1) = 1;
    points(3, 2) = -1;

    points(4, 0) = -1;
    points(4, 1) = -1;
    points(4, 2) = 1;
    points(5, 0) = 1;
    points(5, 1) = -1;
    points(5, 2) = 1;
    points(6, 0) = 1;
    points(6, 1) = 1;
    points(6, 2) = 1;
    points(7, 0) = -1;
    points(7, 1) = 1;
    points(7, 2) = 1;

    if (order > 1) {
      int index = 8;
      for (int iedge=0; iedge<12; iedge++) {
        int p0 = edges[iedge][0];
        int p1 = edges[iedge][1];
        for (int i = 1; i < order; i++, index++) {
          points(index, 0) = points(p0, 0) + i*(points(p1,0)-points(p0,0))/order;
          points(index, 1) = points(p0, 1) + i*(points(p1,1)-points(p0,1))/order;
          points(index, 2) = points(p0, 2) + i*(points(p1,2)-points(p0,2))/order;
        }
      }

      fullMatrix<double> fp = gmshGeneratePointsQuadrangle(order - 2, false);
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
      0.25*(1.-u)*(1.-v)*points(p0,0) +
      0.25*(1.+u)*(1.-v)*points(p1,0) +
      0.25*(1.+u)*(1.+v)*points(p2,0) +
      0.25*(1.-u)*(1.+v)*points(p3,0) ;
    const double newV =
      0.25*(1.-u)*(1.-v)*points(p0,1) +
      0.25*(1.+u)*(1.-v)*points(p1,1) +
      0.25*(1.+u)*(1.+v)*points(p2,1) +
      0.25*(1.-u)*(1.+v)*points(p3,1) ;
    const double newW =
      0.25*(1.-u)*(1.-v)*points(p0,2) +
      0.25*(1.+u)*(1.-v)*points(p1,2) +
      0.25*(1.+u)*(1.+v)*points(p2,2) +
      0.25*(1.-u)*(1.+v)*points(p3,2) ;
    points(index, 0) = newU;
    points(index, 1) = newV;
    points(index, 2) = newW;
  }
      }
      if (!serendip) {
        fullMatrix<double> inner = gmshGeneratePointsHexahedron(order - 2, false);
        inner.scale(1. - 2./order);
        points.copy(inner, 0, nbPoints - index, 0, 3, index, 0);
      }
    }
  }
  else if (order == 0){
    points(0, 0) = 0;
    points(0, 1) = 0;
    points(0, 2) = 0;
  }
  return points;
}

/* --- Prisms --- */

fullMatrix<double> gmshGeneratePointsPrism(int order, bool serendip)
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
  fullMatrix<double> points(nbPoints, 3);

  int index = 0;
  fullMatrix<double> triPoints = gmshGeneratePointsTriangle(order,false);
  fullMatrix<double> linePoints = gmshGeneratePointsLine(order);

  if (order == 2)
    for (int i =0; i<18; i++)
      for (int j=0; j<3;j++)
        points(i,j) = prism18Pts[i][j];
  else
    for (int j = 0; j <linePoints.size1() ; j++) {
      for (int i = 0; i < triPoints.size1(); i++) {
        points(index,0) = triPoints(i,0);
        points(index,1) = triPoints(i,1);
        points(index,2) = linePoints(j,0);
        index ++;
      }
    }

  return points;

}

/* --- Pyramids --- */

fullMatrix<double> gmshGeneratePointsPyramid(int order, bool serendip)
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

      fullMatrix<double> fpq = gmshGeneratePointsQuadrangle(order-2, false);
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
      if (!serendip && order > 2) {
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

fullMatrix<int> gmshGenerateMonomialsLine(int order)
{
  fullMatrix<int> monomials(order + 1, 1);
  monomials(0,0) = 0;
  if (order > 0) {
    monomials(1, 0) = order;
    for (int i = 2; i < order + 1; i++) monomials(i, 0) = i-1;
  }
  return monomials;
}

fullMatrix<int> gmshGenerateMonomialsTriangle(int order, bool serendip)
{
  int nbMonomials = serendip ? 3 * order : (order + 1) * (order + 2) / 2;
  fullMatrix<int> monomials(nbMonomials, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = order;

    if (order > 1) {
      int index = 3;
      for (int iedge = 0; iedge < 3; ++iedge) {
        int i0 = MTriangle::edges_tri(iedge, 0);
        int i1 = MTriangle::edges_tri(iedge, 1);

        int u_0 = (monomials(i1,0)-monomials(i0,0)) / order;
        int u_1 = (monomials(i1,1)-monomials(i0,1)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u_0 * i;
          monomials(index, 1) = monomials(i0, 1) + u_1 * i;
        }
      }
      if (!serendip) {
        fullMatrix<int> inner = gmshGenerateMonomialsTriangle(order-3);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 2, index, 0);
      }
    }
  }
  return monomials;
}

fullMatrix<int> gmshGenerateMonomialsQuadrangle(int order, bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? order*4 : (order+1)*(order+1);
  fullMatrix<int> monomials(nbMonomials, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;

    monomials(2, 0) = order;
    monomials(2, 1) = order;

    monomials(3, 0) = 0;
    monomials(3, 1) = order;

    if (order > 1) {
      int index = 4;
      for (int iedge = 0; iedge < 4; ++iedge) {
        int i0 = MQuadrangle::edges_quad(iedge, 0);
        int i1 = MQuadrangle::edges_quad(iedge, 1);

        int u_0 = (monomials(i1,0)-monomials(i0,0)) / order;
        int u_1 = (monomials(i1,1)-monomials(i0,1)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u_0 * i;
          monomials(index, 1) = monomials(i0, 1) + u_1 * i;
        }
      }

      if (!forSerendipPoints) {
        fullMatrix<int> inner = gmshGenerateMonomialsQuadrangle(order-2);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 2, index, 0);
      }
    }
  }
  return monomials;
}

//KH : caveat : node coordinates are not yet coherent with node numbering associated
//              to numbering of principal vertices of face !!!!
fullMatrix<int> gmshGenerateMonomialsTetrahedron(int order, bool serendip)
{
  int nbMonomials =
    (serendip ?
     4 +  6 * std::max(0, order - 1) + 4 * std::max(0, (order - 2) * (order - 1) / 2) :
     (order + 1) * (order + 2) * (order + 3) / 6);

  fullMatrix<int> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = order;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = 0;
    monomials(3, 2) = order;

    // the template has been defined in table edges_tetra and faces_tetra (MElement.h)

    if (order > 1) {
      int index = 4;
      for (int iedge = 0; iedge < 6; ++iedge) {
        int i0 = MTetrahedron::edges_tetra(iedge, 0);
        int i1 = MTetrahedron::edges_tetra(iedge, 1);

        int u[3];
        u[0] = (monomials(i1,0)-monomials(i0,0)) / order;
        u[1] = (monomials(i1,1)-monomials(i0,1)) / order;
        u[2] = (monomials(i1,2)-monomials(i0,2)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + u[0] * i;
          monomials(index, 1) = monomials(i0, 1) + u[1] * i;
          monomials(index, 2) = monomials(i0, 2) + u[2] * i;
        }
      }

      if (order > 2) {
        fullMatrix<int> dudv = gmshGenerateMonomialsTriangle(order - 3);
        dudv.add(1);

        for (int iface = 0; iface < 4; ++iface) {
          int i0 = MTetrahedron::faces_tetra(iface, 0);
          int i1 = MTetrahedron::faces_tetra(iface, 1);
          int i2 = MTetrahedron::faces_tetra(iface, 2);

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i2, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i2, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i2, 2) - monomials(i0, 2)) / order;

          for (int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) = monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) = monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) = monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        if (!serendip && order > 3) {
          fullMatrix<int> inner = gmshGenerateMonomialsTetrahedron(order - 4);
          inner.add(1);
          monomials.copy(inner, 0, nbMonomials - index, 0, 3, index, 0);
        }
      }
    }
  }
  return monomials;
}

fullMatrix<int> gmshGenerateMonomialsPrism(int order, bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? 6 + (order-1)*9 :
                                        (order + 1) * (order + 1)*(order + 2)/2;
  fullMatrix<int> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = 0;
    monomials(2, 1) = order;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = 0;
    monomials(3, 2) = order;

    monomials(4, 0) = order;
    monomials(4, 1) = 0;
    monomials(4, 2) = order;

    monomials(5, 0) = 0;
    monomials(5, 1) = order;
    monomials(5, 2) = order;

    if (order > 1) {
      int index = 6;
      for (int iedge = 0; iedge < 9; ++iedge) {
        int i0 = MPrism::edges_prism(iedge, 0);
        int i1 = MPrism::edges_prism(iedge, 1);

        int u_1 = (monomials(i1,0)-monomials(i0,0)) / order;
        int u_2 = (monomials(i1,1)-monomials(i0,1)) / order;
        int u_3 = (monomials(i1,2)-monomials(i0,2)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + i * u_1;
          monomials(index, 1) = monomials(i0, 1) + i * u_2;
          monomials(index, 2) = monomials(i0, 2) + i * u_3;
        }
      }

      if (!forSerendipPoints) {
        fullMatrix<int> dudvQ = gmshGenerateMonomialsQuadrangle(order - 2);
        dudvQ.add(1);

        fullMatrix<int> dudvT;
        if (order > 2)  dudvT = gmshGenerateMonomialsTriangle(order - 3);
        dudvT.add(1);

        for (int iface = 0; iface < 5; ++iface) {
          int i0, i1, i2;
          i0 = MPrism::faces_prism(iface, 0);
          i1 = MPrism::faces_prism(iface, 1);
          fullMatrix<int> dudv;
          if (MPrism::faces_prism(iface, 3) != -1) {
            i2 = MPrism::faces_prism(iface, 3);
            dudv.setAsProxy(dudvQ);
          }
          else if (order > 2) {
            i2 = MPrism::faces_prism(iface, 2);
            dudv.setAsProxy(dudvT);
          }
          else continue;

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i2, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i2, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i2, 2) - monomials(i0, 2)) / order;

          for (int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) = monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) = monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) = monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        if (order > 2) {
          fullMatrix<int> triMonomials  = gmshGenerateMonomialsTriangle(order - 3);
          fullMatrix<int> lineMonomials = gmshGenerateMonomialsLine(order - 2);

          for (int i = 0; i < triMonomials.size1(); ++i) {
            for (int j = 0; j < lineMonomials.size1(); ++j, ++index) {
              monomials(index, 0) = 1 + triMonomials(i, 0);
              monomials(index, 1) = 1 + triMonomials(i, 1);
              monomials(index, 2) = 1 + lineMonomials(j, 0);
            }
          }
        }
      }
    }
  }
  return monomials;
}

fullMatrix<int> gmshGenerateMonomialsHexahedron(int order, bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? 8 + (order-1)*12 :
                                        (order+1)*(order+1)*(order+1);
  fullMatrix<int> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = order;
    monomials(2, 1) = order;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = order;
    monomials(3, 2) = 0;

    monomials(4, 0) = 0;
    monomials(4, 1) = 0;
    monomials(4, 2) = order;

    monomials(5, 0) = order;
    monomials(5, 1) = 0;
    monomials(5, 2) = order;

    monomials(6, 0) = order;
    monomials(6, 1) = order;
    monomials(6, 2) = order;

    monomials(7, 0) = 0;
    monomials(7, 1) = order;
    monomials(7, 2) = order;

    if (order > 1) {
      int index = 8;
      for (int iedge = 0; iedge < 12; ++iedge) {
        int i0 = MHexahedron::edges_hexa(iedge, 0);
        int i1 = MHexahedron::edges_hexa(iedge, 1);

        int u_1 = (monomials(i1,0)-monomials(i0,0)) / order;
        int u_2 = (monomials(i1,1)-monomials(i0,1)) / order;
        int u_3 = (monomials(i1,2)-monomials(i0,2)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + i * u_1;
          monomials(index, 1) = monomials(i0, 1) + i * u_2;
          monomials(index, 2) = monomials(i0, 2) + i * u_3;
        }
      }

      if (!forSerendipPoints) {
        fullMatrix<int> dudv = gmshGenerateMonomialsQuadrangle(order - 2);
        dudv.add(1);

        for (int iface = 0; iface < 6; ++iface) {
          int i0 = MHexahedron::faces_hexa(iface, 0);
          int i1 = MHexahedron::faces_hexa(iface, 1);
          int i3 = MHexahedron::faces_hexa(iface, 3);

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i3, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i3, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i3, 2) - monomials(i0, 2)) / order;

          for (int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) = monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) = monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) = monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        fullMatrix<int> inner = gmshGenerateMonomialsHexahedron(order - 2);
        inner.add(1);
        monomials.copy(inner, 0, nbMonomials - index, 0, 3, index, 0);
      }
    }
  }
  return monomials;
}

fullMatrix<int> gmshGenerateMonomialsPyramid(int order, bool forSerendipPoints)
{
  int nbMonomials = forSerendipPoints ? 5 + (order-1)*8 :
                                        (order+1)*((order+1)+1)*(2*(order+1)+1)/6;
  fullMatrix<int> monomials(nbMonomials, 3);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  monomials(0, 2) = 0;

  if (order > 0) {
    monomials(1, 0) = order;
    monomials(1, 1) = 0;
    monomials(1, 2) = 0;

    monomials(2, 0) = order;
    monomials(2, 1) = order;
    monomials(2, 2) = 0;

    monomials(3, 0) = 0;
    monomials(3, 1) = order;
    monomials(3, 2) = 0;

    monomials(4, 0) = 0;
    monomials(4, 1) = 0;
    monomials(4, 2) = order;

    if (order > 1) {
      int index = 5;
      for (int iedge = 0; iedge < 8; ++iedge) {
        int i0 = MPyramid::edges_pyramid(iedge, 0);
        int i1 = MPyramid::edges_pyramid(iedge, 1);

        int u_1 = (monomials(i1,0)-monomials(i0,0)) / order;
        int u_2 = (monomials(i1,1)-monomials(i0,1)) / order;
        int u_3 = (monomials(i1,2)-monomials(i0,2)) / order;

        for (int i = 1; i < order; ++i, ++index) {
          monomials(index, 0) = monomials(i0, 0) + i * u_1;
          monomials(index, 1) = monomials(i0, 1) + i * u_2;
          monomials(index, 2) = monomials(i0, 2) + i * u_3;
        }
      }

      if (!forSerendipPoints) {
        fullMatrix<int> dudvQ = gmshGenerateMonomialsQuadrangle(order - 2);
        dudvQ.add(1);

        fullMatrix<int> dudvT;
        if (order > 2)  dudvT = gmshGenerateMonomialsTriangle(order - 3);
        dudvT.add(1);

        for (int iface = 0; iface < 5; ++iface) {
          int i0, i1, i2;
          i0 = MPyramid::faces_pyramid(iface, 0);
          i1 = MPyramid::faces_pyramid(iface, 1);
          fullMatrix<int> dudv;
          if (MPyramid::faces_pyramid(iface, 3) != -1) {
            i2 = MPyramid::faces_pyramid(iface, 3);
            dudv.setAsProxy(dudvQ);
          }
          else if (order > 2) {
            i2 = MPyramid::faces_pyramid(iface, 2);
            dudv.setAsProxy(dudvT);
          }
          else continue;

          int u[3];
          u[0] = (monomials(i1, 0) - monomials(i0, 0)) / order;
          u[1] = (monomials(i1, 1) - monomials(i0, 1)) / order;
          u[2] = (monomials(i1, 2) - monomials(i0, 2)) / order;
          int v[3];
          v[0] = (monomials(i2, 0) - monomials(i0, 0)) / order;
          v[1] = (monomials(i2, 1) - monomials(i0, 1)) / order;
          v[2] = (monomials(i2, 2) - monomials(i0, 2)) / order;

          for (int i = 0; i < dudv.size1(); ++i, ++index) {
            monomials(index, 0) = monomials(i0, 0) + u[0] * dudv(i, 0) + v[0] * dudv(i, 1);
            monomials(index, 1) = monomials(i0, 1) + u[1] * dudv(i, 0) + v[1] * dudv(i, 1);
            monomials(index, 2) = monomials(i0, 2) + u[2] * dudv(i, 0) + v[2] * dudv(i, 1);
          }
        }

        if (order > 2) {
          fullMatrix<int> inner = gmshGenerateMonomialsPyramid(order - 3);
          inner.add(1);
          monomials.copy(inner, 0, nbMonomials - index, 0, 3, index, 0);
        }
      }
    }
  }
  return monomials;
}

