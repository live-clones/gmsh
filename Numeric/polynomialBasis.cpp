// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "polynomialBasis.h"

static fullMatrix<double> generate1DMonomials(int order)
{
  fullMatrix<double> monomials(order + 1, 1);
  for (int i = 0; i < order + 1; i++) monomials(i, 0) = i;
  return monomials;
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

static fullMatrix<double> generatePascalTriangle(int order)
{
  fullMatrix<double> monomials((order + 1) * (order + 2) / 2, 2);
  int index = 0;
  for (int i = 0; i <= order; i++) {
    for (int j = 0; j <= i; j++) {
      monomials(index, 0) = i - j;
      monomials(index, 1) = j;
      index++;
    }
  }
  return monomials;
}

// generate the exterior hull of the Pascal triangle for Serendipity element

static fullMatrix<double> generatePascalSerendipityTriangle(int order)
{
  fullMatrix<double> monomials(3 * order, 2);

  monomials(0, 0) = 0;
  monomials(0, 1) = 0;
  
  int index = 1;
  for (int i = 1; i <= order; i++) {
    if (i == order) {
      for (int j = 0; j <= i; j++) {
        monomials(index, 0) = i - j;
        monomials(index, 1) = j;
        index++;
      }
    }
    else {
      monomials(index, 0) = i;
      monomials(index, 1) = 0;
      index++;
      monomials(index, 0) = 0;
      monomials(index, 1) = i;
      index++;
    }
  }
  return monomials;
}

// generate all monomials xi^m * eta^n with n and m <= order
static fullMatrix<double> generatePascalQuad(int order)
{

  fullMatrix<double> monomials( (order+1)*(order+1), 2);
  int index = 0;
  for (int p = 0; p <= order; p++) {
    for(int i = 0; i < p; i++, index++) {
      monomials(index, 0) = p;
      monomials(index, 1) = i;
    }
    for(int i = 0; i <= p; i++, index++) {
      monomials(index, 0) = p-i;
      monomials(index, 1) = p;
    }
  }
  return monomials;
}  
/*
00 10 20 30 40 ⋯
01 11 21 31 41 ⋯
02 12
03 13
04 14
⋮  ⋮
*/
static fullMatrix<double> generatePascalQuadSerendip(int order)
{
  fullMatrix<double> monomials( (order)*4, 2);
  monomials(0,0)=0.;
  monomials(0,1)=0.;
  monomials(1,0)=1.;
  monomials(1,1)=0.;
  monomials(2,0)=0.;
  monomials(2,1)=1.;
  monomials(3,0)=1.;
  monomials(3,1)=1.;
  int index = 4;
  for (int p = 2; p <= order; p++) {
    monomials(index, 0) = p;
    monomials(index, 1) = 0;
    index++;
    monomials(index, 0) = 0;
    monomials(index, 1) = p;
    index++;
    monomials(index, 0) = p;
    monomials(index, 1) = 1;
    index++;
    monomials(index, 0) = 1;
    monomials(index, 1) = p;
    index++;
  }
  return monomials;
}

/*static fullMatrix<double> generatePascalQuadSerendip(int order)
{

  fullMatrix<double> monomials( order*4, 2);
  int index = 0;
  for (int p = 0; p < order; p++) {
    monomials(p, 0) = p;
    monomials(p, 1) = 0;

    monomials(p+order, 0) = order;
    monomials(p+order, 1) = p;

    monomials(p+3*order, 0) = order-p;
    monomials(p+3*order, 1) = order;

    monomials(p+2*order, 0) = 0;
    monomials(p+2*order, 1) = order-p;
  }
  monomials.print();
  return monomials;
}*/

// generate the monomials subspace of all monomials of order exactly == p

static fullMatrix<double> generateMonomialSubspace(int dim, int p)
{
  fullMatrix<double> monomials;
  
  switch (dim) {
  case 1:
    monomials = fullMatrix<double>(1, 1);
    monomials(0, 0) = p;
    break;
  case 2:
    monomials = fullMatrix<double>(p + 1, 2);
    for (int k = 0; k <= p; k++) {
      monomials(k, 0) = p - k;
      monomials(k, 1) = k;
    }
    break;
  case 3:
    monomials = fullMatrix<double>((p + 1) * (p + 2) / 2, 3);
    int index = 0;
    for (int i = 0; i <= p; i++) {
      for (int k = 0; k <= p - i; k++) {
        monomials(index, 0) = p - i - k;
        monomials(index, 1) = k;
        monomials(index, 2) = i;
        index++;
      }
    }
    break;
  }
  return monomials;
}

// generate external hull of the Pascal tetrahedron

static fullMatrix<double> generatePascalSerendipityTetrahedron(int order)
{
  int nbMonomials = 4 + 6 * std::max(0, order - 1) + 
    4 * std::max(0, (order - 2) * (order - 1) / 2);
  fullMatrix<double> monomials(nbMonomials, 3);

  monomials.setAll(0);
  int index = 1;
  for (int p = 1; p < order; p++) {
    for (int i = 0; i < 3; i++) {
      int j = (i + 1) % 3;
      int k = (i + 2) % 3;
      for (int ii = 0; ii < p; ii++) {
        monomials(index, i) = p - ii;
        monomials(index, j) = ii;
        monomials(index, k) = 0;
        index++;
      }
    }
  }
  fullMatrix<double> monomialsMaxOrder = generateMonomialSubspace(3, order);
  int nbMaxOrder = monomialsMaxOrder.size1();
  monomials.copy(monomialsMaxOrder, 0, nbMaxOrder, 0, 3, index, 0);
  return monomials;
}

// generate Pascal tetrahedron

static fullMatrix<double> generatePascalTetrahedron(int order)
{
  int nbMonomials = (order + 1) * (order + 2) * (order + 3) / 6;

  fullMatrix<double> monomials(nbMonomials, 3);

  int index = 0;
  for (int p = 0; p <= order; p++) {
    fullMatrix<double> monOrder = generateMonomialSubspace(3, p);
    int nb = monOrder.size1();
    monomials.copy(monOrder, 0, nb, 0, 3, index, 0);
    index += nb;
  }

  return monomials;
}  

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
  
  double dd = 1. / order;

  if (order > 0) {
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

static fullMatrix<double> gmshGeneratePointsQuad(int order, bool serendip) 
{
  int nbPoints = serendip ? order*4 : (order+1)*(order+1);
  fullMatrix<double> point(nbPoints, 2);
  
  double dd = 1. / order;

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

static fullMatrix<double> generateLagrangeMonomialCoefficients
  (const fullMatrix<double>& monomial, const fullMatrix<double>& point) 
{
  if(monomial.size1() != point.size1() || monomial.size2() != point.size2()){
    Msg::Fatal("Wrong sizes for Lagrange coefficients generation");
    return fullMatrix<double>(1, 1);
  }
  
  int ndofs = monomial.size1();
  int dim = monomial.size2();
  
  fullMatrix<double> Vandermonde(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      double dd = 1.;
      for (int k = 0; k < dim; k++) dd *= pow(point(j, k), monomial(i, k));
      Vandermonde(i, j) = dd;
    }
  }

  fullMatrix<double> coefficient(ndofs, ndofs);
  Vandermonde.invert(coefficient);
  return coefficient;
}

static void getFaceClosure(int iFace, int iSign, int iRotate, std::vector<int> &closure,
                           int order)
{

  closure.clear();
  closure.resize((order + 1) * (order + 2) / 2);
  switch (order){
  case 0:
    closure[0] = 0;
    break;
  default:
    int face[4][3] = {{0, 1, 2}, {0, 4, -3}, {1, 5, -4}, {-2, 5, -3}};
    int order1node[4][3] = {{0, 1, 2}, {0, 1, 3}, {1, 2, 3}, {0, 2, 3}};
    // int facedofstmp[200];
    // face 0 | 0 1 2
    // face 1 | 0 4 -3
    // face 2 | 1 5 -4
    // face 3 | -2 5 -3
    // edge 0   |  4 -> 4+order-2
    // edge 1   |  4+order-1 -> 4 + 2*(order-1)-1
    // edge 2   |  4+2*(order-1)-> 4+ 3*(order-1)-1
    // edge k   |  4+k*(order-1) -> 4+(k+1)*(order-1)-1
    for (int i = 0; i < 3; ++i){
      int k = (3 + (iSign * i) + iRotate) % 3;
      closure[i] = order1node[iFace][k];
    }
    for (int i = 0;i < 3; ++i){
      int edgenumber = iSign * 
        face[iFace][(6 + i * iSign + (-1 + iSign) / 2 + iRotate) % 3];
      for (int k = 0; k < (order - 1); k++){
	if (edgenumber > 0 || ((edgenumber == 0) && (iSign > 0)))
	  closure[3 + i * (order - 1) + k] =
            4 + edgenumber * (order - 1) + k;
	else
	  closure[3 + i * (order - 1) + k] =
            4 + (1 - edgenumber) * (order - 1) - 1 - k; 
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
	  int  shift = (3 + iSign * ci + iRotate) % 3;
	  closure[fi + ci] = ti + shift;
	}
	fi = fi + 3; ti = ti + 3;
	for (int l = 0; l < orderint - 1; l++){
	  for (int ei = 0; ei < 3; ei++){
            int edgenumber = (6 + ei * iSign + (-1 + iSign) / 2 + iRotate) % 3;
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

static void generate3dFaceClosure(polynomialBasis::clCont &closure, int order)
{

  for (int iRotate = 0; iRotate < 3; iRotate++){
    for (int iSign = 1; iSign >= -1; iSign -= 2){
      for (int iFace = 0; iFace < 4; iFace++){
	std::vector<int> closure_face;
	getFaceClosure(iFace, iSign, iRotate, closure_face, order);
	closure.push_back(closure_face);
      }
    }
  }
}

static void generate2dEdgeClosure(polynomialBasis::clCont &closure, int order, int nNod = 3)
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
  }
}



static void generate1dVertexClosure(polynomialBasis::clCont &closure)
{
  closure.clear();
  closure.resize(2);
  closure[0].push_back(0);
  closure[1].push_back(1);
  }
std::map<int, polynomialBasis> polynomialBases::fs;

const polynomialBasis &polynomialBases::find(int tag) 
{
  std::map<int, polynomialBasis>::const_iterator it = fs.find(tag);
  if (it != fs.end()) return it->second;
  
  polynomialBasis F;
  
  switch (tag){
  case MSH_PNT:
    F.monomials = generate1DMonomials(0);
    F.points    = generate1DPoints(0);
    break;
  case MSH_LIN_2 :
    F.monomials = generate1DMonomials(1);
    F.points    = generate1DPoints(1);
    generate1dVertexClosure(F.vertexClosure);
    break;
  case MSH_LIN_3 :
    F.monomials = generate1DMonomials(2);
    F.points    = generate1DPoints(2);
    generate1dVertexClosure(F.vertexClosure);
    break;
  case MSH_LIN_4:
    F.monomials = generate1DMonomials(3);
    F.points    = generate1DPoints(3);
    generate1dVertexClosure(F.vertexClosure);
    break;
  case MSH_LIN_5:
    F.monomials = generate1DMonomials(4);
    F.points    = generate1DPoints(4);
    generate1dVertexClosure(F.vertexClosure);
    break;
  case MSH_LIN_6:
    F.monomials = generate1DMonomials(5);
    F.points    = generate1DPoints(5);
    generate1dVertexClosure(F.vertexClosure);
    break;  
  case MSH_TRI_3 :
    F.monomials = generatePascalTriangle(1);
    F.points =    gmshGeneratePointsTriangle(1, false);
    generate2dEdgeClosure(F.edgeClosure, 1);
    break;
  case MSH_TRI_6 :
    F.monomials = generatePascalTriangle(2);
    F.points =    gmshGeneratePointsTriangle(2, false);
    generate2dEdgeClosure(F.edgeClosure, 2);
    break;
  case MSH_TRI_9 :
    F.monomials = generatePascalSerendipityTriangle(3);
    F.points =    gmshGeneratePointsTriangle(3, true);
    generate2dEdgeClosure(F.edgeClosure, 3);
    break;
  case MSH_TRI_10 :
    F.monomials = generatePascalTriangle(3);
    F.points =    gmshGeneratePointsTriangle(3, false);
    generate2dEdgeClosure(F.edgeClosure, 3);
    break;
  case MSH_TRI_12 :
    F.monomials = generatePascalSerendipityTriangle(4);
    F.points =    gmshGeneratePointsTriangle(4, true);
    generate2dEdgeClosure(F.edgeClosure, 4);
    break;
  case MSH_TRI_15 :
    F.monomials = generatePascalTriangle(4);
    F.points =    gmshGeneratePointsTriangle(4, false);
    generate2dEdgeClosure(F.edgeClosure, 4);
    break;
  case MSH_TRI_15I :
    F.monomials = generatePascalSerendipityTriangle(5);
    F.points =    gmshGeneratePointsTriangle(5, true);
    generate2dEdgeClosure(F.edgeClosure, 5);
    break;
  case MSH_TRI_21 :
    F.monomials = generatePascalTriangle(5);
    F.points =    gmshGeneratePointsTriangle(5, false);
    generate2dEdgeClosure(F.edgeClosure, 5);
    break;
  case MSH_TET_4 :
    F.monomials = generatePascalTetrahedron(1);
    F.points =    gmshGeneratePointsTetrahedron(1, false);
    generate3dFaceClosure(F.faceClosure, 1);
    break;
  case MSH_TET_10 :
    F.monomials = generatePascalTetrahedron(2);
    F.points =    gmshGeneratePointsTetrahedron(2, false);
    generate3dFaceClosure(F.faceClosure, 2);
    break;
  case MSH_TET_20 :
    F.monomials = generatePascalTetrahedron(3);
    F.points =    gmshGeneratePointsTetrahedron(3, false);
    generate3dFaceClosure(F.faceClosure, 3);
    break;
  case MSH_TET_35 :
    F.monomials = generatePascalTetrahedron(4);
    F.points =    gmshGeneratePointsTetrahedron(4, false);
    generate3dFaceClosure(F.faceClosure, 4);
    break;
  case MSH_TET_34 :
    F.monomials = generatePascalSerendipityTetrahedron(4);
    F.points =    gmshGeneratePointsTetrahedron(4, true);
    generate3dFaceClosure(F.faceClosure, 4);
    break;
  case MSH_TET_52 :
    F.monomials = generatePascalSerendipityTetrahedron(5);
    F.points =    gmshGeneratePointsTetrahedron(5, true);
    generate3dFaceClosure(F.faceClosure, 5);
    break;
  case MSH_TET_56 :
    F.monomials = generatePascalTetrahedron(5);
    F.points =    gmshGeneratePointsTetrahedron(5, false);
    generate3dFaceClosure(F.faceClosure, 5);
    break;
  case MSH_QUA_4 :
    F.monomials = generatePascalQuad(1);
    F.points =    gmshGeneratePointsQuad(1,false);
    generate2dEdgeClosure(F.edgeClosure, 1, 4);
    break;
  case MSH_QUA_9 :
    F.monomials = generatePascalQuad(2);
    F.points =    gmshGeneratePointsQuad(2,false);
    generate2dEdgeClosure(F.edgeClosure, 2, 4);
    break;
  case MSH_QUA_16 :
    F.monomials = generatePascalQuad(3);
    F.points =    gmshGeneratePointsQuad(3,false);
    generate2dEdgeClosure(F.edgeClosure, 3, 4);
    break;
  case MSH_QUA_25 :
    F.monomials = generatePascalQuad(4);
    F.points =    gmshGeneratePointsQuad(4,false);
    generate2dEdgeClosure(F.edgeClosure, 4, 4);
    break;
  case MSH_QUA_36 :
    F.monomials = generatePascalQuad(5);
    F.points =    gmshGeneratePointsQuad(5,false);
    generate2dEdgeClosure(F.edgeClosure, 5, 4);
    break;
  case MSH_QUA_8 :
    F.monomials = generatePascalQuadSerendip(2);
    F.points =    gmshGeneratePointsQuad(2,true);
    generate2dEdgeClosure(F.edgeClosure, 2, 4);
    break;
  case MSH_QUA_12 :
    F.monomials = generatePascalQuadSerendip(3);
    F.points =    gmshGeneratePointsQuad(3,true);
    generate2dEdgeClosure(F.edgeClosure, 3, 4);
    break;
  case MSH_QUA_16I :
    F.monomials = generatePascalQuadSerendip(4);
    F.points =    gmshGeneratePointsQuad(4,true);
    generate2dEdgeClosure(F.edgeClosure, 4, 4);
    break;
  case MSH_QUA_20 :
    F.monomials = generatePascalQuadSerendip(5);
    F.points =    gmshGeneratePointsQuad(5,true);
    generate2dEdgeClosure(F.edgeClosure, 5, 4);
    break;
  default :
    Msg::Error("Unknown function space %d: reverting to TET_4", tag);
    F.monomials = generatePascalTetrahedron(1);
    F.points =    gmshGeneratePointsTetrahedron(1, false);
    generate3dFaceClosure(F.faceClosure, 1);
    break;
  }  
  F.coefficients = generateLagrangeMonomialCoefficients(F.monomials, F.points);
  fs.insert(std::make_pair(tag, F));
  return fs[tag];
}

std::map<std::pair<int, int>, fullMatrix<double> > polynomialBases::injector;

const fullMatrix<double> &polynomialBases::findInjector(int tag1, int tag2)
{
  std::pair<int,int> key(tag1,tag2);
  std::map<std::pair<int, int>, fullMatrix<double> >::const_iterator it = injector.find(key);
  if (it != injector.end()) return it->second;

  const polynomialBasis& fs1 = find(tag1);
  const polynomialBasis& fs2 = find(tag2);

  fullMatrix<double> inj(fs1.points.size1(), fs2.points.size1());
  
  double sf[256];
  
  for (int i = 0; i < fs1.points.size1(); i++) {
    fs2.f(fs1.points(i, 0), fs1.points(i, 1), fs1.points(i, 2), sf);
    for (int j = 0; j < fs2.points.size1(); j++) inj(i, j) = sf[j];
  }

  injector.insert(std::make_pair(key, inj));
  return injector[key];
}
