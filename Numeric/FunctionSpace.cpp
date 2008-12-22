// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//

#include "FunctionSpace.h"
#include "GmshDefines.h"
#include "GmshMessage.h"

Double_Matrix generate1DMonomials(int order)
{
  Double_Matrix monomials(order + 1, 1);
  for (int i = 0; i < order + 1; i++) monomials(i, 0) = i;
  return monomials;
}

Double_Matrix generate1DPoints(int order)
{
  Double_Matrix line(order + 1, 1);
  line(0, 0) = -1.;
  line(1, 0) =  1.;
  double dd = 2. / order;
  for (int i = 2; i < order+1; i++) line(i, 0) = -1. + dd * (i - 1);
  return line;
}

Double_Matrix generatePascalTriangle(int order)
{
  Double_Matrix monomials((order + 1) * (order + 2) / 2, 2);
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

Double_Matrix generatePascalSerendipityTriangle(int order)
{
  Double_Matrix monomials(3 * order, 2);

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

// generate the monomials subspace of all monomials of order exactly == p

Double_Matrix generateMonomialSubspace(int dim, int p)
{
  Double_Matrix monomials;
  
  switch (dim) {
  case 1:
    monomials = Double_Matrix(1, 1);
    monomials(0, 0) = p;
    break;
  case 2:
    monomials = Double_Matrix(p + 1, 2);
    for (int k = 0; k <= p; k++) {
      monomials(k, 0) = p - k;
      monomials(k, 1) = k;
    }
    break;
  case 3:
    monomials = Double_Matrix((p + 1) * (p + 2) / 2, 3);
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

Double_Matrix generatePascalSerendipityTetrahedron(int order)
{
  int nbMonomials = 4 + 6 * std::max(0, order - 1) + 
    4 * std::max(0, (order - 2) * (order - 1) / 2);
  Double_Matrix monomials(nbMonomials, 3);

  monomials.set_all(0);
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
  Double_Matrix monomialsMaxOrder = generateMonomialSubspace(3, order);
  int nbMaxOrder = monomialsMaxOrder.size1();
    
  monomials.submatrix(index, nbMaxOrder, 0, 3).memcpy(monomialsMaxOrder);
  return monomials;
}

// generate Pascal tetrahedron

Double_Matrix generatePascalTetrahedron(int order)
{
  int nbMonomials = (order + 1) * (order + 2) * (order + 3) / 6;

  Double_Matrix monomials(nbMonomials, 3);

  int index = 0;
  for (int p = 0; p <= order; p++) {
    Double_Matrix monOrder = generateMonomialSubspace(3, p);
    int nb = monOrder.size1();
    monomials.submatrix(index, nb, 0, 3).memcpy(monOrder);
    index += nb;
  }

  return monomials;
}  

int nbdoftriangle(int order) { return (order + 1) * (order + 2) / 2; }
int nbdoftriangleserendip(int order) { return 3 * order; }

//KH : caveat : node coordinates are not yet coherent with node numbering associated
//              to numbering of principal vertices of face !!!!

// uv surface - orientation v0-v2-v1
void nodepositionface0(int order, double *u, double *v, double *w)
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
void nodepositionface1(int order, double *u, double *v, double *w)
{
   int ndofT = nbdoftriangle(order);
   if (order == 0) { u[0] = 0.; v[0] = 0.; w[0] = 0.; return; }
   
   u[0]= 0.;    v[0]= 0.;  w[0] = 0.;
   u[1]= order; v[1]= 0;   w[1] = 0.;
   u[2]= 0.;    v[2]= 0.;  w[2] = order;
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
void nodepositionface2(int order, double *u, double *v, double *w)
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
void nodepositionface3(int order,  double *u,  double *v,  double *w)
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

Double_Matrix gmshGeneratePointsTetrahedron(int order, bool serendip) 
{
  int nbPoints = 
    (serendip ?
     4 +  6 * std::max(0, order - 1) + 4 * std::max(0, (order - 2) * (order - 1) / 2) :
     (order + 1) * (order + 2) * (order + 3) / 6);
  
  Double_Matrix point(nbPoints, 3);

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
  
          Double_Matrix interior = gmshGeneratePointsTetrahedron(order - 4, false);
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

Double_Matrix gmshGeneratePointsTriangle(int order, bool serendip) 
{
  int nbPoints = serendip ? 3 * order : (order + 1) * (order + 2) / 2;
  Double_Matrix point(nbPoints, 2);
  
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
        Double_Matrix inner = gmshGeneratePointsTriangle(order - 3, serendip);
        inner.scale(1. - 3. * dd);
        inner.add(dd);
        point.submatrix(index, nbPoints - index, 0, 2).memcpy(inner);
      }
    }
  }
  return point;  
}

Double_Matrix generateLagrangeMonomialCoefficients(const Double_Matrix& monomial,
                                                   const Double_Matrix& point) 
{
  if(monomial.size1() != point.size1() || monomial.size2() != point.size2()){
    Msg::Fatal("Wrong sizes for Lagrange coefficients generation");
    return Double_Matrix(1, 1);
  }
  
  int ndofs = monomial.size1();
  int dim = monomial.size2();
  
  Double_Matrix Vandermonde(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      double dd = 1.;
      for (int k = 0; k < dim; k++) dd *= pow(point(i, k), monomial(j, k));
      Vandermonde(i, j) = dd;
    }
  }

  double det = Vandermonde.determinant();

  if (det == 0.){
    Msg::Fatal("Vandermonde matrix has zero determinant!?");
    return Double_Matrix(1, 1);
  }
  Double_Matrix coefficient(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      int f = (i + j) % 2 == 0 ? 1 : -1;
      Double_Matrix cofactor = Vandermonde.cofactor(i, j);
      coefficient(i, j) = f * cofactor.determinant() / det;
    }
  }
  return coefficient;
}

std::map<int, gmshFunctionSpace> gmshFunctionSpaces::fs;

const gmshFunctionSpace &gmshFunctionSpaces::find(int tag) 
{
  std::map<int, gmshFunctionSpace>::const_iterator it = fs.find(tag);
  if (it != fs.end()) return it->second;
  
  gmshFunctionSpace F;
  
  switch (tag){
  case MSH_PNT:
    F.monomials = generate1DMonomials(0);
    F.points    = generate1DPoints(0);
    break;
  case MSH_LIN_2 :
    F.monomials = generate1DMonomials(1);
    F.points    = generate1DPoints(1);
    break;
  case MSH_LIN_3 :
    F.monomials = generate1DMonomials(2);
    F.points    = generate1DPoints(2);
    break;
  case MSH_LIN_4:
    F.monomials = generate1DMonomials(3);
    F.points    = generate1DPoints(3);
    break;
  case MSH_LIN_5:
    F.monomials = generate1DMonomials(4);
    F.points    = generate1DPoints(4);
    break;
  case MSH_LIN_6:
    F.monomials = generate1DMonomials(5);
    F.points    = generate1DPoints(5);
    break;  
  case MSH_TRI_3 :
    F.monomials = generatePascalTriangle(1);
    F.points =    gmshGeneratePointsTriangle(1, false);
    break;
  case MSH_TRI_6 :
    F.monomials = generatePascalTriangle(2);
    F.points =    gmshGeneratePointsTriangle(2, false);
    break;
  case MSH_TRI_9 :
    F.monomials = generatePascalSerendipityTriangle(3);
    F.points =    gmshGeneratePointsTriangle(3, true);
    break;
  case MSH_TRI_10 :
    F.monomials = generatePascalTriangle(3);
    F.points =    gmshGeneratePointsTriangle(3, false);
    break;
  case MSH_TRI_12 :
    F.monomials = generatePascalSerendipityTriangle(4);
    F.points =    gmshGeneratePointsTriangle(4, true);
    break;
  case MSH_TRI_15 :
    F.monomials = generatePascalTriangle(4);
    F.points =    gmshGeneratePointsTriangle(4, false);
    break;
  case MSH_TRI_15I :
    F.monomials = generatePascalSerendipityTriangle(5);
    F.points =    gmshGeneratePointsTriangle(5, true);
    break;
  case MSH_TRI_21 :
    F.monomials = generatePascalTriangle(5);
    F.points =    gmshGeneratePointsTriangle(5, false);
    break;
  case MSH_TET_4 :
    F.monomials = generatePascalTetrahedron(1);
    F.points =    gmshGeneratePointsTetrahedron(1, false);
    break;
  case MSH_TET_10 :
    F.monomials = generatePascalTetrahedron(2);
    F.points =    gmshGeneratePointsTetrahedron(2, false);
    break;
  case MSH_TET_20 :
    F.monomials = generatePascalTetrahedron(3);
    F.points =    gmshGeneratePointsTetrahedron(3, false);
    break;
  case MSH_TET_35 :
    F.monomials = generatePascalTetrahedron(4);
    F.points =    gmshGeneratePointsTetrahedron(4, false);
    break;
  case MSH_TET_34 :
    F.monomials = generatePascalSerendipityTetrahedron(4);
    F.points =    gmshGeneratePointsTetrahedron(4, true);
    break;
  case MSH_TET_52 :
    F.monomials = generatePascalSerendipityTetrahedron(5);
    F.points =    gmshGeneratePointsTetrahedron(5, true);
    break;
  case MSH_TET_56 :
    F.monomials = generatePascalTetrahedron(5);
    F.points =    gmshGeneratePointsTetrahedron(5, false);
    break;
  default :
    Msg::Error("Unknown function space %d: reverting to TET_4", tag);
    F.monomials = generatePascalTetrahedron(1);
    F.points =    gmshGeneratePointsTetrahedron(1, false);
    break;
  }  
  F.coefficients = generateLagrangeMonomialCoefficients(F.monomials, F.points);
  fs.insert(std::make_pair(tag, F));
  return fs[tag];
}

std::map<std::pair<int, int>, Double_Matrix> gmshFunctionSpaces::injector;

const Double_Matrix &gmshFunctionSpaces::findInjector(int tag1, int tag2)
{
  std::pair<int,int> key(tag1,tag2);
  std::map<std::pair<int, int>, Double_Matrix>::const_iterator it = injector.find(key);
  if (it != injector.end()) return it->second;

  const gmshFunctionSpace& fs1 = find(tag1);
  const gmshFunctionSpace& fs2 = find(tag2);

  Double_Matrix inj(fs1.points.size1(),fs2.points.size1());
  
  double sf[256];
  
  for (int i = 0; i < fs1.points.size1(); i++) {
    fs2.f(fs1.points(i, 0), fs1.points(i, 1), fs1.points(i, 2), sf);
    for (int j = 0; j < fs2.points.size1(); j++) inj(i, j) = sf[j];
  }

  injector.insert(std::make_pair(key, inj));
  return injector[key];
}
