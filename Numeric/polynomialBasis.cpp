// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//   Jonathan Lambrechts
//

#include <stdlib.h>
#include <cmath>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "polynomialBasis.h"
#include "GaussIntegration.h"
#include "pointsGenerators.h"
#include <limits>

/*
static void printClosure(polynomialBasis::clCont &fullClosure,
                         std::vector<int> &closureRef,
                         polynomialBasis::clCont &closures)
{
  for (unsigned int i = 0; i < closures.size(); i++) {
    printf("%3i  (%2i): ", i, closureRef[i]);
    if(closureRef[i]==-1){
      printf("\n");
      continue;
    }
    for (unsigned int j = 0; j < fullClosure[i].size(); j++) {
      printf("%2i ", fullClosure[i][j]);
    }
    printf ("  --  ");
    for (unsigned int j = 0; j < closures[closureRef[i]].size(); j++) {
      std::string equalSign = "-";
      if (fullClosure[i][closures[closureRef[i]][j]] != closures[i][j])
        equalSign = "#";
      printf("%2i%s%2i ", fullClosure[i][closures[closureRef[i]][j]],equalSign.c_str(),
             closures[i][j]);
    }
    printf("\n");
  }
}
*/



fullMatrix<double> generate1DMonomials(int order)
{
  fullMatrix<double> monomials(order + 1, 1);
  for (int i = 0; i < order + 1; i++) monomials(i, 0) = i;
  return monomials;
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



// generate all monomials xi^m * eta^n with n and m <= order

static fullMatrix<double> generatePascalHex(int order, bool serendip)
{
  if (false && serendip) {
    fullMatrix<double> monomials( 8+(order-1)*12, 3);
    monomials(0,0)=0.;
    monomials(0,1)=0.;
    monomials(0,2)=0.;
    monomials(1,0)=1.;
    monomials(1,1)=0.;
    monomials(1,2)=0.;
    monomials(2,0)=0.;
    monomials(2,1)=1.;
    monomials(2,2)=0.;
    monomials(3,0)=1.;
    monomials(3,1)=1.;
    monomials(3,2)=0.;

    monomials(4,0)=0.;
    monomials(4,1)=0.;
    monomials(4,2)=1.;
    monomials(5,0)=1.;
    monomials(5,1)=0.;
    monomials(5,2)=1.;
    monomials(6,0)=0.;
    monomials(6,1)=1.;
    monomials(6,2)=1.;
    monomials(7,0)=1.;
    monomials(7,1)=1.;
    monomials(7,2)=1.;
    int index = 8;
    for (int p = 2; p <= order; p++) {
      monomials(index, 0) = p;
      monomials(index, 1) = 0;
      monomials(index, 2) = 0;
      index++;
      monomials(index, 0) = p;
      monomials(index, 1) = 1;
      monomials(index, 2) = 0;
      index++;
      monomials(index, 0) = p;
      monomials(index, 1) = 1;
      monomials(index, 2) = 1;
      index++;
      monomials(index, 0) = p;
      monomials(index, 1) = 0;
      monomials(index, 2) = 1;
      index++;
      monomials(index, 0) = 0;
      monomials(index, 1) = p;
      monomials(index, 2) = 0;
      index++;
      monomials(index, 0) = 1;
      monomials(index, 1) = p;
      monomials(index, 2) = 0;
      index++;
      monomials(index, 0) = 1;
      monomials(index, 1) = p;
      monomials(index, 2) = 1;
      index++;
      monomials(index, 0) = 0;
      monomials(index, 1) = p;
      monomials(index, 2) = 1;
      index++;
      monomials(index, 0) = 0;
      monomials(index, 1) = 0;
      monomials(index, 2) = p;
      index++;
      monomials(index, 0) = 1;
      monomials(index, 1) = 0;
      monomials(index, 2) = p;
      index++;
      monomials(index, 0) = 1;
      monomials(index, 1) = 1;
      monomials(index, 2) = p;
      index++;
      monomials(index, 0) = 0;
      monomials(index, 1) = 1;
      monomials(index, 2) = p;
      index++;
    }
    return monomials;
  }

  int siz = (order+1)*(order+1)*(order+1);
  if (serendip) siz -= (order-1)*(order-1)*(order-1);
  fullMatrix<double> monomials( siz, 3);
  int index = 0;
  for (int i = 0; i <= order; i++) {
    for (int j = 0; j <= order; j++) {
      for (int k = 0; k <= order; k++) {
	if (!serendip || i<2 || j<2 || k<2){
	  monomials(index,0) = i;
	  monomials(index,1) = j;
	  monomials(index,2) = k;
	  index++;
	}
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

  return monomials;
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

  fullMatrix<double> unity(ndofs, ndofs);
  Vandermonde.mult(coefficient, unity);
  double max = .0;
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      if (i == j) unity(i, j) -= 1.;
      //Msg::Info("   unity(%d, %d) = %.3e", i, j, unity(i, j));
      max = std::max(max, std::abs(unity(i, j)));
    }
  }
  if (max > 1e-10) Msg::Info("   max unity = %.3e", max);

  return coefficient;
}

static void copy(const fullMatrix<int> &orig, fullMatrix<double> &b)
{
  b.resize(orig.size1(), orig.size2());
  for (int i = 0; i < orig.size1(); ++i) {
    for (int j = 0; j < orig.size2(); ++j) {
      b(i, j) = static_cast<double>(orig(i, j));
    }
  }
}

polynomialBasis::polynomialBasis(int tag) : nodalBasis(tag)
{

  switch (parentType) {
  case TYPE_PNT :
    monomials = generate1DMonomials(0);
    break;
  case TYPE_LIN :
    monomials = generate1DMonomials(order);
    break;
  case TYPE_TRI :
    monomials = serendip ? generatePascalSerendipityTriangle(order) :
    generatePascalTriangle(order);
    break;
  case TYPE_QUA :
    monomials = serendip ? generatePascalQuadSerendip(order) :
    generatePascalQuad(order);
    break;
  case TYPE_TET :
    monomials = serendip ? generatePascalSerendipityTetrahedron(order) :
    generatePascalTetrahedron(order);
    break;
  case TYPE_PRI :
    monomials = generatePascalPrism(order);
    break;
  case TYPE_HEX :
    monomials = generatePascalHex(order, serendip);
    break;
  }

  coefficients = generateLagrangeMonomialCoefficients(monomials, points);


  // TEST NEW ALGO POINTS / MONOMIALS

  int rescale = 0;
  switch (parentType) {
  case TYPE_PNT :
    monomials_newAlgo = gmshGenerateMonomialsLine(0);
    break;
  case TYPE_LIN :
    monomials_newAlgo = gmshGenerateMonomialsLine(order);
    rescale = 1;
    break;
  case TYPE_TRI :
    monomials_newAlgo = gmshGenerateMonomialsTriangle(order, serendip);
    break;
  case TYPE_QUA :
    monomials_newAlgo = gmshGenerateMonomialsQuadrangle(order, serendip);
    rescale = 1;
    break;
  case TYPE_TET :
    monomials_newAlgo = gmshGenerateMonomialsTetrahedron(order, serendip);
    break;
  case TYPE_HEX :
    monomials_newAlgo = gmshGenerateMonomialsHexahedron(order, serendip);
    rescale = 1;
    break;
  case TYPE_PRI :
    monomials_newAlgo = gmshGenerateMonomialsPrism(order, serendip);
    rescale = 2;
    break;
  }
  copy(monomials_newAlgo, points_newAlgo);
  //if (order == 0) return;
  switch (rescale) {
    case 0 :
      points_newAlgo.scale(1./order);
      break;
    case 1 :
      points_newAlgo.scale(2./order);
      points_newAlgo.add(-1.);
      break;
    case 2 :
    {
      fullMatrix<double> tmp;
      tmp.setAsProxy(points_newAlgo, 0, 2);
      tmp.scale(1./order);

      tmp.setAsProxy(points_newAlgo, 2, 1);
      tmp.scale(2./order);
      tmp.add(-1.);
      break;
    }
    default :
      break;
  }

  fullMatrix<double> monDouble;
  switch (parentType) {
  case TYPE_PNT :
  case TYPE_LIN :
  case TYPE_TRI :
  case TYPE_TET :
    copy(monomials_newAlgo, monDouble);
    break;
  case TYPE_QUA :
  case TYPE_HEX :
  case TYPE_PRI :
    //if (serendip) monDouble = monomials;
    /*else*/ copy(monomials_newAlgo, monDouble);
    break;
  }
  coefficients_newAlgo = generateLagrangeMonomialCoefficients(monDouble, points_newAlgo);
}



polynomialBasis::~polynomialBasis()
{
}




inline void polynomialBasis::evaluateMonomialsNew(double u, double v, double w, double p[]) const
{
  for (int j = 0; j < monomials_newAlgo.size1(); ++j) {
    p[j] = 1.;
    switch (dimension) {
    case 3 :
      p[j] *= pow_int(w, monomials_newAlgo(j, 2));
    case 2 :
      p[j] *= pow_int(v, monomials_newAlgo(j, 1));
    case 1 :
      p[j] *= pow_int(u, monomials_newAlgo(j, 0));
    default :
      break;
    }
  }
}



void polynomialBasis::f(double u, double v, double w, double *sf) const
{
  double p[1256];
  evaluateMonomials(u, v, w, p);
  for (int i = 0; i < coefficients.size1(); i++) {
    sf[i] = 0.0;
    for (int j = 0; j < coefficients.size2(); j++) {
      sf[i] += coefficients(i, j) * p[j];
    }
  }
}
void polynomialBasis::fnew(double u, double v, double w, double *sf) const
{
  double p[1256];
  evaluateMonomialsNew(u, v, w, p);
  for (int i = 0; i < coefficients_newAlgo.size1(); i++) {
    sf[i] = 0.0;
    for (int j = 0; j < coefficients_newAlgo.size2(); j++) {
      sf[i] += coefficients_newAlgo(i, j) * p[j];
    }
  }
}



void polynomialBasis::f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const
{
  double p[1256];
  sf.resize (coord.size1(), coefficients.size1());
  for (int iPoint=0; iPoint< coord.size1(); iPoint++) {
    evaluateMonomials(coord(iPoint,0), coord(iPoint,1), coord.size2() > 2 ? coord(iPoint,2) : 0, p);
    for (int i = 0; i < coefficients.size1(); i++) {
      sf(iPoint,i) = 0.;
      for (int j = 0; j < coefficients.size2(); j++) sf(iPoint,i) += coefficients(i, j) * p[j];
    }
  }
}



void polynomialBasis::df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const
{
  double dfv[1256][3];
  dfm.resize (coefficients.size1(), coord.size1() * 3, false);
  int dimCoord = coord.size2();
  for (int iPoint=0; iPoint< coord.size1(); iPoint++) {
    df(coord(iPoint,0), dimCoord > 1 ? coord(iPoint, 1) : 0., dimCoord > 2 ? coord(iPoint, 2) : 0., dfv);
    for (int i = 0; i < coefficients.size1(); i++) {
      dfm(i, iPoint * 3 + 0) = dfv[i][0];
      dfm(i, iPoint * 3 + 1) = dfv[i][1];
      dfm(i, iPoint * 3 + 2) = dfv[i][2];
    }
  }
}



void polynomialBasis::df(double u, double v, double w, double grads[][3]) const
{
  switch (monomials.size2()) {
  case 1:
    for (int i = 0; i < coefficients.size1(); i++){
      grads[i][0] = 0;
      grads[i][1] = 0;
      grads[i][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 0)
          grads[i][0] += coefficients(i, j) *
            pow_int(u, (int)(monomials(j, 0) - 1)) * monomials(j, 0);
      }
    }
    break;
  case 2:
    for (int i = 0; i < coefficients.size1(); i++){
      grads[i][0] = 0;
      grads[i][1] = 0;
      grads[i][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 0)
          grads[i][0] += coefficients(i, j) *
            pow_int(u, (int)(monomials(j, 0) - 1)) * monomials(j, 0) *
            pow_int(v, (int)monomials(j, 1));
        if (monomials(j, 1) > 0)
          grads[i][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)(monomials(j, 1) - 1)) * monomials(j, 1);
      }
    }
    break;
  case 3:
    for (int i = 0; i < coefficients.size1(); i++){
      grads[i][0] = 0;
      grads[i][1] = 0;
      grads[i][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 0)
          grads[i][0] += coefficients(i, j) *
            pow_int(u, (int)(monomials(j, 0) - 1)) * monomials(j, 0) *
            pow_int(v, (int)monomials(j, 1)) *
            pow_int(w, (int)monomials(j, 2));
        if (monomials(j, 1) > 0)
          grads[i][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)(monomials(j, 1) - 1)) * monomials(j, 1) *
            pow_int(w, (int)monomials(j, 2));
        if (monomials(j, 2) > 0)
          grads[i][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1)) *
            pow_int(w, (int)(monomials(j, 2) - 1)) * monomials(j, 2);
      }
    }
    break;
  }
}



void polynomialBasis::ddf(double u, double v, double w, double hess[][3][3]) const
{
  switch (monomials.size2()) {
  case 1:
    for (int i = 0; i < coefficients.size1(); i++){
      hess[i][0][0] = hess[i][0][1] = hess[i][0][2] = 0;
      hess[i][1][0] = hess[i][1][1] = hess[i][1][2] = 0;
      hess[i][2][0] = hess[i][2][1] = hess[i][2][2] = 0;

      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 1) // second derivative !=0
          hess[i][0][0] += coefficients(i, j) * pow_int(u, (int)(monomials(j, 0) - 2)) *
            monomials(j, 0) * (monomials(j, 0) - 1);
      }
    }
    break;
  case 2:
    for (int i = 0; i < coefficients.size1(); i++){
      hess[i][0][0] = hess[i][0][1] = hess[i][0][2] = 0;
      hess[i][1][0] = hess[i][1][1] = hess[i][1][2] = 0;
      hess[i][2][0] = hess[i][2][1] = hess[i][2][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 1) // second derivative !=0
          hess[i][0][0] += coefficients(i, j) * pow_int(u, (int)(monomials(j, 0) - 2)) *
            monomials(j, 0) * (monomials(j, 0) - 1) * pow_int(v, (int)monomials(j, 1));
        if ((monomials(j, 1) > 0) && (monomials(j, 0) > 0))
          hess[i][0][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 1) * monomials(j, 0) *
            pow_int(v, (int)monomials(j, 1) - 1) * monomials(j, 1);
        if (monomials(j, 1) > 1)
          hess[i][1][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1) - 2) * monomials(j, 1) * (monomials(j, 1) - 1);
      }
      hess[i][1][0] = hess[i][0][1];
    }
    break;
  case 3:
    for (int i = 0; i < coefficients.size1(); i++){
      hess[i][0][0] = hess[i][0][1] = hess[i][0][2] = 0;
      hess[i][1][0] = hess[i][1][1] = hess[i][1][2] = 0;
      hess[i][2][0] = hess[i][2][1] = hess[i][2][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 1)
          hess[i][0][0] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 2) * monomials(j, 0) * (monomials(j, 0)-1) *
            pow_int(v, (int)monomials(j, 1)) *
            pow_int(w, (int)monomials(j, 2));

        if ((monomials(j, 0) > 0) && (monomials(j, 1) > 0))
          hess[i][0][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 1) * monomials(j, 0) *
            pow_int(v, (int)monomials(j, 1) - 1) * monomials(j, 1) *
            pow_int(w, (int)monomials(j, 2));
        if ((monomials(j, 0) > 0) && (monomials(j, 2) > 0))
          hess[i][0][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 1) * monomials(j, 0) *
            pow_int(v, (int)monomials(j, 1)) *
            pow_int(w, (int)monomials(j, 2) - 1) * monomials(j, 2);
        if (monomials(j, 1) > 1)
          hess[i][1][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1) - 2) * monomials(j, 1) * (monomials(j, 1)-1) *
            pow_int(w, (int)monomials(j, 2));
        if ((monomials(j, 1) > 0) && (monomials(j, 2) > 0))
          hess[i][1][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1) - 1) * monomials(j, 1) *
            pow_int(w, (int)monomials(j, 2) - 1) * monomials(j, 2);
        if (monomials(j, 2) > 1)
          hess[i][2][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1)) *
            pow_int(w, (int)monomials(j, 2) - 2) * monomials(j, 2) * (monomials(j, 2) - 1);
      }
      hess[i][1][0] = hess[i][0][1];
      hess[i][2][0] = hess[i][0][2];
      hess[i][2][1] = hess[i][1][2];
    }
    break;
  }
}



void polynomialBasis::dddf(double u, double v, double w, double third[][3][3][3]) const
{
  switch (monomials.size2()) {
  case 1:
    for (int i = 0; i < coefficients.size1(); i++){
      for (int p=0; p<3; p++)
        for (int q=0; q<3; q++)
          for (int r=0; r<3; r++)
            third[i][p][q][r] = 0.;

      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 2) // third derivative !=0
          third[i][0][0][0] += coefficients(i, j) * pow_int(u, (int)(monomials(j, 0) - 3)) *
            monomials(j, 0) * (monomials(j, 0) - 1)*(monomials(j, 0) - 2);
      }
    }
    break;
  case 2:
    for (int i = 0; i < coefficients.size1(); i++){
      for (int p=0; p<3; p++)
        for (int q=0; q<3; q++)
          for (int r=0; r<3; r++)
            third[i][p][q][r] = 0.;
      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 2) // second derivative !=0
          third[i][0][0][0] += coefficients(i, j) *
            pow_int(u, (int)(monomials(j, 0) - 3))*monomials(j, 0) * (monomials(j, 0) - 1) *(monomials(j, 0) - 2) *
            pow_int(v, (int)monomials(j, 1));
        if ((monomials(j, 0) > 1) && (monomials(j, 1) > 0))
          third[i][0][0][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 2) * monomials(j, 0)*(monomials(j, 0) - 1) *
            pow_int(v, (int)monomials(j, 1) - 1) * monomials(j, 1);
        if ((monomials(j, 0) > 0) && (monomials(j, 1) > 1))
          third[i][0][1][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 1) *monomials(j, 0)*
            pow_int(v, (int)monomials(j, 1) - 2) * monomials(j, 1) * (monomials(j, 1) - 1);
        if (monomials(j, 1) > 2)
          third[i][1][1][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1) - 3) * monomials(j, 1) * (monomials(j, 1) - 1)*(monomials(j, 1) - 2);
      }
      third[i][0][1][0] = third[i][0][0][1];
      third[i][1][0][0] = third[i][0][0][1];
      third[i][1][0][1] = third[i][0][1][1];
      third[i][1][1][0] = third[i][0][1][1];
    }
    break;
  case 3:
    for (int i = 0; i < coefficients.size1(); i++){
      for (int p=0; p<3; p++)
        for (int q=0; q<3; q++)
          for (int r=0; r<3; r++)
            third[i][p][q][r] = 0.;
      for(int j = 0; j < coefficients.size2(); j++){
        if (monomials(j, 0) > 2) // second derivative !=0
          third[i][0][0][0] += coefficients(i, j) *
            pow_int(u, (int)(monomials(j, 0) - 3)) *monomials(j, 0) * (monomials(j, 0) - 1)*(monomials(j, 0) - 2) *
            pow_int(v, (int)monomials(j, 1))*
            pow_int(w, (int)monomials(j, 2));

        if ((monomials(j, 0) > 1) && (monomials(j, 1) > 0))
          third[i][0][0][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 2) * monomials(j, 0)*(monomials(j, 0) - 1) *
            pow_int(v, (int)monomials(j, 1) - 1) * monomials(j, 1)*
            pow_int(w, (int)monomials(j, 2));

        if ((monomials(j, 0) > 1) && (monomials(j, 2) > 0))
          third[i][0][0][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 2) * monomials(j, 0)*(monomials(j, 0) - 1) *
            pow_int(v, (int)monomials(j, 1)) *
            pow_int(w, (int)monomials(j, 2) - 1)* monomials(j, 2);

        if ((monomials(j, 0) > 0) && (monomials(j, 1) > 1))
          third[i][0][1][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 1) *monomials(j, 0)*
            pow_int(v, (int)monomials(j, 1) - 2) * monomials(j, 1) * (monomials(j, 1) - 1)*
            pow_int(w, (int)monomials(j, 2));

        if ((monomials(j, 0) > 0) && (monomials(j, 1) > 0)&& (monomials(j, 2) > 0))
          third[i][0][1][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 1) *monomials(j, 0)*
            pow_int(v, (int)monomials(j, 1) - 1) *monomials(j, 1) *
            pow_int(w, (int)monomials(j, 2) - 1) *monomials(j, 2);

        if ((monomials(j, 0) > 0) && (monomials(j, 2) > 1))
          third[i][0][2][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0) - 1) *monomials(j, 0)*
            pow_int(v, (int)monomials(j, 1))*
            pow_int(w, (int)monomials(j, 2) - 2) * monomials(j, 2) * (monomials(j, 2) - 1);
        if ((monomials(j, 1) > 2))
          third[i][1][1][1] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1)-3) * monomials(j, 1) * (monomials(j, 1) - 1)*(monomials(j, 1) - 2)*
            pow_int(w, (int)monomials(j, 2));

        if ((monomials(j, 1) > 1) && (monomials(j, 2) > 0))
          third[i][1][1][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1)-2) * monomials(j, 1) * (monomials(j, 1) - 1)*
            pow_int(w, (int)monomials(j, 2) - 1) *monomials(j, 2) ;

        if ((monomials(j, 1) > 0) && (monomials(j, 2) > 1))
          third[i][1][2][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1)-1) *monomials(j, 1)*
            pow_int(w, (int)monomials(j, 2) - 2) * monomials(j, 2) * (monomials(j, 2) - 1) ;

        if ((monomials(j, 2) > 2))
          third[i][2][2][2] += coefficients(i, j) *
            pow_int(u, (int)monomials(j, 0)) *
            pow_int(v, (int)monomials(j, 1))*
            pow_int(w, (int)monomials(j, 2) - 3) * monomials(j, 2) * (monomials(j, 2) - 1)*(monomials(j, 2) - 2);


      }
      third[i][0][1][0] = third[i][0][0][1];
      third[i][1][0][0] = third[i][0][0][1];

      third[i][2][0][0] = third[i][0][0][2];
      third[i][0][2][0] = third[i][0][0][2];

      third[i][1][0][1] = third[i][0][1][1];
      third[i][1][1][0] = third[i][0][1][1];

      third[i][0][2][1] = third[i][0][1][2];
      third[i][1][0][2] = third[i][0][1][2];
      third[i][1][2][0] = third[i][0][1][2];
      third[i][2][1][0] = third[i][0][1][2];
      third[i][2][0][1] = third[i][0][1][2];

      third[i][2][2][0] = third[i][0][2][2];
      third[i][2][0][2] = third[i][0][2][2];

      third[i][1][2][1] = third[i][1][1][2];
      third[i][2][1][1] = third[i][1][1][2];

      third[i][2][2][1] = third[i][1][2][2];
      third[i][2][1][2] = third[i][1][2][2];
    }
    break;
  }
}
