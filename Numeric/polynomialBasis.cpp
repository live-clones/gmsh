// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//   Jonathan Lambrechts
//

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "polynomialBasis.h"
#include "Gauss.h"

#include "stdlib.h"
static void printClosure(polynomialBasis::clCont &fullClosure, std::vector<int> &closureRef, polynomialBasis::clCont &closures) {
  for (int i = 0; i <closures.size(); i++) {
    printf("%3i  (%2i): ", i, closureRef[i]);
    if(closureRef[i]==-1){
      printf("\n");
      continue;
    }
    for (int j = 0; j < fullClosure[i].size(); j++) {
      printf("%2i ", fullClosure[i][j]);
    }
    printf ("  --  ");
    for (int j = 0; j < closures[closureRef[i]].size(); j++) {
      std::string equalSign = "-";
      if (fullClosure[i][closures[closureRef[i]][j]] != closures[i][j])
        equalSign = "#";
      printf("%2i%s%2i ", fullClosure[i][closures[closureRef[i]][j]],equalSign.c_str(), closures[i][j]);
    }
    printf("\n");
  }
}

static int getTriangleType (int order) {
  switch(order) {
    case 0 : return MSH_TRI_1;
    case 1 : return MSH_TRI_3;
    case 2 : return MSH_TRI_6;
    case 3 : return MSH_TRI_10;
    case 4 : return MSH_TRI_15;
    case 5 : return MSH_TRI_21;
    case 6 : return MSH_TRI_28;
    case 7 : return MSH_TRI_36;
    case 8 : return MSH_TRI_45;
    case 9 : return MSH_TRI_55;
    case 10 : return MSH_TRI_66;
    default : Msg::Error("triangle order %i unknown", order);
  }
}
static int getQuadType (int order) {
  switch(order) {
    case 0 : return MSH_QUA_1;
    case 1 : return MSH_QUA_4;
    case 2 : return MSH_QUA_9;
    case 3 : return MSH_QUA_16;
    case 4 : return MSH_QUA_25;
    case 5 : return MSH_QUA_36;
    case 6 : return MSH_QUA_49;
    case 7 : return MSH_QUA_64;
    case 8 : return MSH_QUA_81;
    case 9 : return MSH_QUA_100;
    case 10 : return MSH_QUA_121;
    default : Msg::Error("quad order %i unknown", order);
  }
}
static int getLineType (int order) {
  switch(order) {
    case 0 : return MSH_LIN_1;
    case 1 : return MSH_LIN_2;
    case 2 : return MSH_LIN_3;
    case 3 : return MSH_LIN_4;
    case 4 : return MSH_LIN_5;
    case 5 : return MSH_LIN_6;
    case 6 : return MSH_LIN_7;
    case 7 : return MSH_LIN_8;
    case 8 : return MSH_LIN_9;
    case 9 : return MSH_LIN_10;
    case 10 : return MSH_LIN_11;
    default : Msg::Error("line order %i unknown", order);
  }
}


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

const fullMatrix<double> &polynomialBasis::getGradientAtFaceIntegrationPoints(int integrationOrder, int closureId) const{
  std::vector<fullMatrix<double> > &dfAtFace = _dfAtFace[integrationOrder];
  if (dfAtFace.empty()) {
    dfAtFace.resize(closures.size());
    int nbPsi = points.size1();
    for (int iClosure=0; iClosure< closures.size(); iClosure++) {
      fullMatrix<double> integrationFace, weight;
      const polynomialBasis *fsFace = polynomialBases::find(closures[iClosure].type);
      gaussIntegration::get(fsFace->parentType, integrationOrder, integrationFace, weight);
      fullMatrix<double> integration(integrationFace.size1(), 3);
      double f[256];
      for (int i = 0; i < integrationFace.size1(); i++){
        fsFace->f(integrationFace(i,0),integrationFace(i,1),integrationFace(i,2),f);
        for(size_t j=0; j<closures[iClosure].size(); j++) {
          int jNod = closures[iClosure][j];
          for(int k = 0; k < points.size2(); k++)
            integration(i,k) += f[j] * points(jNod,k);
        }
      }
      fullMatrix<double> &v = dfAtFace[iClosure];
      v.resize(nbPsi, integration.size1()*3);
      double g[256][3];
      for (size_t xi = 0; xi< integration.size1(); xi++) {
        df(integration(xi,0 ), integration(xi,1), integration(xi,2), g);
        for (int j = 0; j < nbPsi; j++) {
          v(j, xi*3) = g[j][0];
          v(j, xi*3+1) = g[j][1];
          v(j, xi*3+2) = g[j][2];
        }
      }
    }
  }
  return dfAtFace[closureId];
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

// generate all monomials xi^m * eta^n with n and m <= order
static fullMatrix<double> generatePascalHex(int order)
{

  fullMatrix<double> monomials( (order+1)*(order+1)*(order+1), 3);
  int index = 0;
  for (int p = 0; p <= order; p++) {
    for(int i = 0; i < p; i++) {
      for(int j = 0; j < i; j++, index++) {
	monomials(index, 0) = p;
	monomials(index, 1) = i;
	monomials(index, 2) = j;
      }
    }
    for(int i = 0; i <= p; i++, index++) {
      for(int j = 0; j <= p; i++, index++) {
	monomials(index, 0) = p-i;
	monomials(index, 1) = p;
      }
    }
  }
  return monomials;
}

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

// generate Pascal prism

static fullMatrix<double> generatePascalPrism(int order)
{
  int nbMonomials = (order + 1) * (order + 1) * (order + 2) / 2;

  fullMatrix<double> monomials(nbMonomials, 3);
  int index = 0;
  fullMatrix<double> lineMonoms = generate1DMonomials(order);
  fullMatrix<double> triMonoms = generatePascalTriangle(order);
  // store monomials in right order
  for (int currentOrder = 0; currentOrder <= order; currentOrder++) {
    int orderT = currentOrder, orderL = currentOrder;
    for (orderL = 0; orderL < currentOrder; orderL++) {
      // do all permutations of monoms for orderL, orderT
      int iL = orderL;
      for (int iT = (orderT)*(orderT+1)/2; iT < (orderT+1)*(orderT+2)/2 ;iT++) {
        monomials(index,0) = triMonoms(iT,0);
        monomials(index,1) = triMonoms(iT,1);
        monomials(index,2) = lineMonoms(iL,0);
        index ++;
      }
    }
    orderL = currentOrder;
    for (orderT = 0; orderT <= currentOrder; orderT++) {
      int iL = orderL;
      for (int iT = (orderT)*(orderT+1)/2; iT < (orderT+1)*(orderT+2)/2 ;iT++) {
        monomials(index,0) = triMonoms(iT,0);
        monomials(index,1) = triMonoms(iT,1);
        monomials(index,2) = lineMonoms(iL,0);
        index ++;
      }
    }    
  }
//   monomials.print("Pri monoms");
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
    Msg::Fatal("Wrong sizes for Lagrange coefficients generation %d %d -- %d %d",
         monomial.size1(),point.size1(),
         monomial.size2(),point.size2() );
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

static void generate1dVertexClosure(polynomialBasis::clCont &closure)
{
  closure.clear();
  closure.resize(2);
  closure[0].push_back(0);
  closure[1].push_back(1);
  closure[0].type = MSH_PNT;
  closure[1].type = MSH_PNT;
}

static void generate1dVertexClosureFull(polynomialBasis::clCont &closure, std::vector<int> &closureRef, int order)
{
  closure.clear();
  closure.resize(2);
  closure[0].push_back(0);
  closure[0].push_back(1);
  closure[1].push_back(1);
  closure[1].push_back(0);
  for (int i = 0; i < order - 1; i++) {
    closure[0].push_back(2 + i);
    closure[1].push_back(2 + order - 2 - i);
  }
  closureRef.resize(2);
  closureRef[0] = 0;
  closureRef[1] = 0;
}

static void getFaceClosureTet(int iFace, int iSign, int iRotate, polynomialBasis::closure &closure,
                           int order)
{

  closure.clear();
  closure.resize((order + 1) * (order + 2) / 2);
  closure.type = getTriangleType(order);

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
static void generate2dEdgeClosureFull(polynomialBasis::clCont &closure, std::vector<int> &closureRef, int order, int nNod, bool serendip)
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
    closure[r].type = getLineType(order);
    closureRef[r] = 0;
  }
}

static void addEdgeNodes(polynomialBasis::clCont &closureFull, const int *edges, int order) 
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
  for (int iClosure = 0; iClosure < closureFull.size(); iClosure++) {
    std::vector<int> &cl = closureFull[iClosure];
    for (int iEdge = 0; edges[iEdge] >= 0; iEdge += 2) {
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

static void generateFaceClosureTet(polynomialBasis::clCont &closure, int order)
{
  closure.clear();
  for (int iRotate = 0; iRotate < 3; iRotate++){
    for (int iSign = 1; iSign >= -1; iSign -= 2){
      for (int iFace = 0; iFace < 4; iFace++){
        polynomialBasis::closure closure_face;
        getFaceClosureTet(iFace, iSign, iRotate, closure_face, order);
        closure.push_back(closure_face);
      }
    }
  }
}

static void generateFaceClosureTetFull(polynomialBasis::clCont &closureFull, std::vector<int> &closureRef, int order, bool serendip)
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
  polynomialBasis::clCont closure;
  generateFaceClosureTet(closure, 1);
  for (int i = 0; i < closureFull.size(); i++) {
    std::vector<int> &clFull = closureFull[i];
    std::vector<int> &cl = closure[i];
    clFull.resize(4, -1);
    closureRef[i] = 0;
    for (int j = 0; j < cl.size(); j ++)
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
  polynomialBasis::clCont closureTriangles;
  std::vector<int> closureTrianglesRef;
  if (order >= 3)
    generate2dEdgeClosureFull(closureTriangles, closureTrianglesRef, order - 3, 3, false); 
  addEdgeNodes(closureFull, edges, order);
  for (int iClosure = 0; iClosure < closureFull.size(); iClosure++) {
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
          cl.push_back(4 + 6 * (order - 1) + idFace * nOnFace + closureTriangles[iTriClosure][i]);
        }
      }
    }
  }
  if (order >= 4 && !serendip) {
    polynomialBasis::clCont insideClosure;
    std::vector<int> fakeClosureRef;
    generateFaceClosureTetFull(insideClosure, fakeClosureRef, order - 4, false);
    for (int i = 0; i < closureFull.size(); i ++) {
      int shift = closureFull[i].size();
      for (int j = 0; j < insideClosure[i].size(); j++)
        closureFull[i].push_back(insideClosure[i][j] + shift);
    }
  }
}

static void getFaceClosurePrism(int iFace, int iSign, int iRotate,
                                polynomialBasis::closure &closure, int order)
{
  if (order > 2)
    Msg::Error("FaceClosure not implemented for prisms of order %d",order);
  bool isTriangle = iFace<2;
  int nNodes = isTriangle ? (order+1)*(order+2)/2 : (order+1)*(order+1);
  closure.clear();
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
  closure.type = isTriangle ? getTriangleType(order) : getQuadType(order);
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

static void generateFaceClosurePrism(polynomialBasis::clCont &closure, int order)
{
  closure.clear();
  for (int iRotate = 0; iRotate < 4; iRotate++){
    for (int iSign = 1; iSign >= -1; iSign -= 2){
      for (int iFace = 0; iFace < 5; iFace++){
        polynomialBasis::closure closure_face;
        getFaceClosurePrism(iFace, iSign, iRotate, closure_face, order);
        closure.push_back(closure_face);
      }
    }
  }
}

static void generateFaceClosurePrismFull(polynomialBasis::clCont &closureFull, std::vector<int> &closureRef, int order) 
{
  polynomialBasis::clCont closure;
  closureFull.clear();
  closureFull.resize(40);
  closureRef.resize(40);
  generateFaceClosurePrism(closure, 1);
  int ref3 = -1, ref4a = -1, ref4b = -1;
  for (int i = 0; i < closure.size(); i++) {
    std::vector<int> &clFull = closureFull[i];
    std::vector<int> &cl = closure[i];
    clFull.resize(6, -1);
    int &ref = cl.size() == 3 ? ref3 : (cl[0] / 3 + cl[1] / 3) % 2 ? ref4b : ref4a;
    if (ref == -1)
      ref = i;
    closureRef[i] = ref;
    for (int j = 0; j < cl.size(); j ++)
      clFull[closure[ref][j]] = cl[j];
    for (int j = 0; j < 6; j ++) {
      if (clFull[j] == -1) {
        int k = ((j / 3) + 1) % 2 * 3;
        int sum = (clFull[k + (j + 1) % 3] + clFull[k + (j + 2) % 3]);
        clFull[j] = ((sum / 6 + 1) % 2) * 3 + (12 - sum) % 3;
      }
    }
  }
  static const int edges[] = {0, 1,  0, 2,  0, 3,  1, 2,  1, 4,  2, 5,  3, 4,  3, 5,  4, 5,  -1};
  addEdgeNodes(closureFull, edges, order);
  if ( order < 2 )
    return;
  // face center nodes for p2 prism
  static const int faces[5][4] = {{0, 2, 1, -1}, {3, 4, 5, -1}, {0, 1, 4,  3}, {0, 3, 5,  2}, {1, 2, 5,  4}};

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
    for (int i = 0; i < closureFull.size(); i++ ) {
      for (int iFace = 0; iFace < numFaces; iFace++ ) {
        int nodeSum = 0;
        for (int iNode = 0; iNode < numFaceNodes; iNode++)
          nodeSum += faces[iFace][iNode] < 0 ? faces[iFace][iNode] : closureFull[i][ faces[iFace][iNode] ];
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
    Msg::Error("Prisms of order %d not implemented",order);
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
    closure[j].type = closure[nNod+j].type = getLineType(order);
  }
}

static void generateClosureOrder0(polynomialBasis::clCont &closure, int nb)
{
  closure.clear();
  closure.resize(nb);
  for (int i=0; i < nb; i++) { 
    closure[i].push_back(0);
    closure[i].type = MSH_PNT;
  }
}

std::map<int, polynomialBasis> polynomialBases::fs;

const polynomialBasis *polynomialBases::find(int tag)
{
  std::map<int, polynomialBasis>::const_iterator it = fs.find(tag);
  if (it != fs.end())     return &it->second;
  polynomialBasis F;
  F.numFaces = -1;
  switch (tag){
  case MSH_PNT:
    F.numFaces = 1;
    F.monomials = generate1DMonomials(0);
    F.points    = generate1DPoints(0);
    F.parentType = TYPE_PNT;
    break;
  case MSH_LIN_1 :
    F.numFaces = 2;
    F.monomials = generate1DMonomials(0);
    F.points    = generate1DPoints(0);
    generateClosureOrder0(F.closures,2);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 0);
    F.parentType = TYPE_LIN;
    break;
  case MSH_LIN_2 :
    F.numFaces = 2;
    F.monomials = generate1DMonomials(1);
    F.points    = generate1DPoints(1);
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 1);
    F.parentType = TYPE_LIN;
    break;
  case MSH_LIN_3 :
    F.numFaces = 2;
    F.monomials = generate1DMonomials(2);
    F.points    = generate1DPoints(2);
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 2);
    F.parentType = TYPE_LIN;
    break;
  case MSH_LIN_4:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(3);
    F.points    = generate1DPoints(3);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 3);
    break;
  case MSH_LIN_5:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(4);
    F.points    = generate1DPoints(4);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 4);
    break;
  case MSH_LIN_6:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(5);
    F.points    = generate1DPoints(5);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 5);
    break;
  case MSH_LIN_7:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(6);
    F.points    = generate1DPoints(6);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 6);
    break;
  case MSH_LIN_8:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(7);
    F.points    = generate1DPoints(7);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 7);
    break;
  case MSH_LIN_9:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(8);
    F.points    = generate1DPoints(8);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 8);
    break;
  case MSH_LIN_10:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(9);
    F.points    = generate1DPoints(9);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 9);
    break;
  case MSH_LIN_11:
    F.numFaces = 2;
    F.monomials = generate1DMonomials(10);
    F.points    = generate1DPoints(10);
    F.parentType = TYPE_LIN;
    generate1dVertexClosure(F.closures);
    generate1dVertexClosureFull(F.fullClosures, F.closureRef, 10);
    break;
  case MSH_TRI_1 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(0);
    F.points =    gmshGeneratePointsTriangle(0, false);
    F.parentType = TYPE_TRI;
    generateClosureOrder0(F.closures, 6);
    generateClosureOrder0(F.fullClosures, 6);
    F.closureRef.resize(6, 0);
    break;
  case MSH_TRI_3 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(1);
    F.points =    gmshGeneratePointsTriangle(1, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 1);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 1, 3, false);
    break;
  case MSH_TRI_6 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(2);
    F.points =    gmshGeneratePointsTriangle(2, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 2);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 2, 3, false);
    break;
  case MSH_TRI_9 :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(3);
    F.points =    gmshGeneratePointsTriangle(3, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 3);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 3, 3, true);
    break;
  case MSH_TRI_10 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(3);
    F.points =    gmshGeneratePointsTriangle(3, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 3);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 3, 3, false);
    break;
  case MSH_TRI_12 :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(4);
    F.points =    gmshGeneratePointsTriangle(4, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 4, 3, true);
    break;
  case MSH_TRI_15 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(4);
    F.points =    gmshGeneratePointsTriangle(4, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 4, 3, false);
    break;
  case MSH_TRI_15I :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(5);
    F.points =    gmshGeneratePointsTriangle(5, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 5);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 5, 3, true);
    break;
  case MSH_TRI_21 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(5);
    F.points =    gmshGeneratePointsTriangle(5, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 5);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 5, 3, false);
    break;
  case MSH_TRI_28 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(6);
    F.points =    gmshGeneratePointsTriangle(6, false);    
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 6);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 6, 3, false);
    break;
  case MSH_TRI_36 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(7);
    F.points =    gmshGeneratePointsTriangle(7, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 7);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 7, 3, false);
    break;
  case MSH_TRI_45 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(8);
    F.points =    gmshGeneratePointsTriangle(8, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 8);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 8, 3, false);
    break;
  case MSH_TRI_55 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(9);
    F.points =    gmshGeneratePointsTriangle(9, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 9);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 9, 3, false);
    break;
  case MSH_TRI_66 :
    F.numFaces = 3;
    F.monomials = generatePascalTriangle(10);
    F.points =    gmshGeneratePointsTriangle(10, false);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 10);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 10, 3, false);
    break;
  case MSH_TRI_18 :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(6);
    F.points =    gmshGeneratePointsTriangle(6, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 6);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 6, 3, true);
    break;
  case MSH_TRI_21I :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(7);
    F.points =    gmshGeneratePointsTriangle(7, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 7);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 7, 3, true);
    break;
  case MSH_TRI_24 :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(8);
    F.points =    gmshGeneratePointsTriangle(8, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 8);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 8, 3, true);
    break;
  case MSH_TRI_27 :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(9);
    F.points =    gmshGeneratePointsTriangle(9, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 9);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 9, 3, true);
    break;
  case MSH_TRI_30 :
    F.numFaces = 3;
    F.monomials = generatePascalSerendipityTriangle(10);
    F.points =    gmshGeneratePointsTriangle(10, true);
    F.parentType = TYPE_TRI;
    generate2dEdgeClosure(F.closures, 10);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 10, 3, true);
    break;
  case MSH_TET_1 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(0);
    F.points =    gmshGeneratePointsTetrahedron(0, false);
    F.parentType = TYPE_TET;
    generateClosureOrder0(F.closures,24);
    generateClosureOrder0(F.fullClosures, 24);
    F.closureRef.resize(24, 0);
    break;
  case MSH_TET_4 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(1);
    F.points =    gmshGeneratePointsTetrahedron(1, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 1);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 1, false);
    break;
  case MSH_TET_10 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(2);
    F.points =    gmshGeneratePointsTetrahedron(2, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 2);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 2, false);
    break;
  case MSH_TET_20 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(3);
    F.points =    gmshGeneratePointsTetrahedron(3, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 3);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 3, false);
    break;
  case MSH_TET_35 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(4);
    F.points =    gmshGeneratePointsTetrahedron(4, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 4);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 4, false);
    break;
  case MSH_TET_34 :
    F.numFaces = 4;
    F.monomials = generatePascalSerendipityTetrahedron(4);
    F.points =    gmshGeneratePointsTetrahedron(4, true);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 4);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 4, true);
    break;
  case MSH_TET_52 :
    F.numFaces = 4;
    F.monomials = generatePascalSerendipityTetrahedron(5);
    F.points =    gmshGeneratePointsTetrahedron(5, true);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 5);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 5, true);
    break;
  case MSH_TET_56 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(5);
    F.points =    gmshGeneratePointsTetrahedron(5, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 5);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 5, false);
    break;
  case MSH_TET_74 :
    F.numFaces = 4;
    F.monomials = generatePascalSerendipityTetrahedron(6);
    F.points =    gmshGeneratePointsTetrahedron(6, true);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 6);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 6, true);
    break;
  case MSH_TET_84 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(6);
    F.points =    gmshGeneratePointsTetrahedron(6, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 6);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 6, false);
    break;
  case MSH_TET_100 :
    F.numFaces = 4;
    F.monomials = generatePascalSerendipityTetrahedron(7);
    F.points =    gmshGeneratePointsTetrahedron(7, true);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 7);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 7, true);
    break;
  case MSH_TET_120 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(7);
    F.points =    gmshGeneratePointsTetrahedron(7, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 7);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 7, false);
    break;
  case MSH_TET_130 :
    F.numFaces = 4;
    F.monomials = generatePascalSerendipityTetrahedron(8);
    F.points =    gmshGeneratePointsTetrahedron(8, true);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 8);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 8, true);
    break;
  case MSH_TET_164 :
    F.numFaces = 4;
    F.monomials = generatePascalSerendipityTetrahedron(9);
    F.points =    gmshGeneratePointsTetrahedron(9, true);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 9);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 9, true);
    break;
  case MSH_TET_165 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(8);
    F.points =    gmshGeneratePointsTetrahedron(8, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 8);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 8, false);
    break;
  case MSH_TET_202 :
    F.numFaces = 4;
    F.monomials = generatePascalSerendipityTetrahedron(10);
    F.points =    gmshGeneratePointsTetrahedron(10, true);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 10);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 10, true);
    break;
  case MSH_TET_220 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(9);
    F.points =    gmshGeneratePointsTetrahedron(9, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 9);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 9, false);
    break;
  case MSH_TET_286 :
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(10);
    F.points =    gmshGeneratePointsTetrahedron(10, false);
    F.parentType = TYPE_TET;
    generateFaceClosureTet(F.closures, 10);
    generateFaceClosureTetFull(F.fullClosures, F.closureRef, 10, false);
    break;
  case MSH_QUA_1 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(0);
    F.points =    gmshGeneratePointsQuad(0,false);
    F.parentType = TYPE_QUA;
    generateClosureOrder0(F.closures,8);
    generateClosureOrder0(F.fullClosures,8);
    F.closureRef.resize(8, 0);
    break;
  case MSH_QUA_4 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(1);
    F.points =    gmshGeneratePointsQuad(1,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 1, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 1, 4, false);
    break;
  case MSH_QUA_9 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(2);
    F.points =    gmshGeneratePointsQuad(2,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 2, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 2, 4, false);
    break;
  case MSH_QUA_16 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(3);
    F.points =    gmshGeneratePointsQuad(3,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 3, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 3, 4, false);
    break;
  case MSH_QUA_25 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(4);
    F.points =    gmshGeneratePointsQuad(4,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 4, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 4, 4, false);
    break;
  case MSH_QUA_36 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(5);
    F.points =    gmshGeneratePointsQuad(5,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 5, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 5, 4, false);
    break;
  case MSH_QUA_49 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(6);
    F.points =    gmshGeneratePointsQuad(6,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 6, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 6, 4, false);
    break;
  case MSH_QUA_64 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(7);
    F.points =    gmshGeneratePointsQuad(7,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 7, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 7, 4, false);
    break;
  case MSH_QUA_81 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(8);
    F.points =    gmshGeneratePointsQuad(8,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 8, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 8, 4, false);
    break;
  case MSH_QUA_100 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(9);
    F.points =    gmshGeneratePointsQuad(9,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 9, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 9, 4, false);
    break;
  case MSH_QUA_121 :
    F.numFaces = 4;
    F.monomials = generatePascalQuad(10);
    F.points =    gmshGeneratePointsQuad(10,false);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 10, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 10, 4, false);
    break;
  case MSH_QUA_8 :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(2);
    F.points =    gmshGeneratePointsQuad(2,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 2, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 2, 4, true);
    break;
  case MSH_QUA_12 :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(3);
    F.points =    gmshGeneratePointsQuad(3,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 3, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 3, 4, true);
    break;
  case MSH_QUA_16I :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(4);
    F.points =    gmshGeneratePointsQuad(4,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 4, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 4, 4, true);
    break;
  case MSH_QUA_20 :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(5);
    F.points =    gmshGeneratePointsQuad(5,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 5, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 5, 4, true);
    break;
  case MSH_QUA_24 :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(6);
    F.points =    gmshGeneratePointsQuad(6,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 6, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 6, 4, true);
    break;
  case MSH_QUA_28 :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(7);
    F.points =    gmshGeneratePointsQuad(7,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 7, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 7, 4, true);
    break;
  case MSH_QUA_32 :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(8);
    F.points =    gmshGeneratePointsQuad(8,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 8, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 8, 4, true);
    break;
  case MSH_QUA_36I :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(9);
    F.points =    gmshGeneratePointsQuad(9,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 9, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 9, 4, true);
    break;
  case MSH_QUA_40 :
    F.numFaces = 4;
    F.monomials = generatePascalQuadSerendip(10);
    F.points =    gmshGeneratePointsQuad(10,true);
    F.parentType = TYPE_QUA;
    generate2dEdgeClosure(F.closures, 10, 4);
    generate2dEdgeClosureFull(F.fullClosures, F.closureRef, 10, 4, true);
    break;
  case MSH_PRI_1 :
    F.numFaces = 5;
    F.monomials = generatePascalPrism(0);
    F.points =    gmshGeneratePointsPrism(0, false);
    F.parentType = TYPE_PRI;
    generateClosureOrder0(F.closures,48);
    generateClosureOrder0(F.fullClosures,48);
    F.closureRef.resize(48, 0);
    break;
  case MSH_PRI_6 :
    F.numFaces = 5;
    F.monomials = generatePascalPrism(1);
    F.points =    gmshGeneratePointsPrism(1, false);
    F.parentType = TYPE_PRI;
    generateFaceClosurePrism(F.closures, 1);
    generateFaceClosurePrismFull(F.fullClosures, F.closureRef, 1);
    break;
  case MSH_PRI_18 :
    F.numFaces = 5;
    F.monomials = generatePascalPrism(2);
    F.points =    gmshGeneratePointsPrism(2, false);
    F.parentType = TYPE_PRI;
    generateFaceClosurePrism(F.closures, 2);
    generateFaceClosurePrismFull(F.fullClosures, F.closureRef, 2);
    break;
  default :
    Msg::Error("Unknown function space %d: reverting to TET_4", tag);
    F.numFaces = 4;
    F.monomials = generatePascalTetrahedron(1);
    F.parentType = TYPE_TET;
    F.points =    gmshGeneratePointsTetrahedron(1, false);
    generateFaceClosureTet(F.closures, 1);
    break;
  }
  F.type = tag;

  F.coefficients = generateLagrangeMonomialCoefficients(F.monomials, F.points);

  // printf("Case: %d coeffs:\n",tag);
  // for (int i = 0; i<F.coefficients.size1(); i++) {
  //   for (int j = 0; j<F.coefficients.size2(); j++) {
  //     printf("%4.1f ",F.coefficients(i,j));
  //   }
  //   printf("\n");
  // }

  fs.insert(std::make_pair(tag, F));
  return &fs[tag];
}


std::map<std::pair<int, int>, fullMatrix<double> > polynomialBases::injector;

const fullMatrix<double> &polynomialBases::findInjector(int tag1, int tag2)
{
  std::pair<int,int> key(tag1,tag2);
  std::map<std::pair<int, int>, fullMatrix<double> >::const_iterator it =
    injector.find(key);
  if (it != injector.end()) return it->second;

  const polynomialBasis& fs1 = *find(tag1);
  const polynomialBasis& fs2 = *find(tag2);

  fullMatrix<double> inj(fs1.points.size1(), fs2.points.size1());

  double sf[256];

  for (int i = 0; i < fs1.points.size1(); i++) {
    fs2.f(fs1.points(i, 0), fs1.points(i, 1), fs1.points(i, 2), sf);
    for (int j = 0; j < fs2.points.size1(); j++) inj(i, j) = sf[j];
  }

  injector.insert(std::make_pair(key, inj));
  return injector[key];
}

#include "Bindings.h"
void polynomialBasis::registerBindings(binding *b) 
{
  classBinding *cb = b->addClass<polynomialBasis>("polynomialBasis");
  cb->setDescription("polynomial shape functions for elements");
  methodBinding *mb = cb->addMethod
    ("f", (void (polynomialBasis::*)(fullMatrix<double>&, fullMatrix<double>&))
     &polynomialBasis::f);
  mb->setDescription("evaluate the shape functions");
  mb->setArgNames("nodes","values",NULL);
  mb = cb->addMethod("find",&polynomialBases::find);
  mb->setDescription("return the polynomial basis corresponding to an element type");
  mb->setArgNames("elementType",NULL);
}
