// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _POLYNOMIAL_BASIS_H_
#define _POLYNOMIAL_BASIS_H_

#include <math.h>
#include <map>
#include <vector>
#include "fullMatrix.h"
#include "nodalBasis.h"
#include <iostream>

#define SQU(a)  ((a)*(a))

inline double pow_int(const double &a, const int &n)
{
  switch (n) {
  case 0 : return 1.0;
  case 1 : return a;
  case 2 : return a*a;
  case 3 : return a*a*a;
  case 4 :
    {
      const double a2 = a*a;
      return a2*a2;
    }
  case 5 :
    {
      const double a2 = a*a;
      const double a3 = a*a*a;
      return a2*a3;
    }
  case 6 :
    {
      const double a3 = a*a*a;
      return a3*a3;
    }
  case 7 :
    {
      const double a3 = a*a*a;
      return a3*a3*a;
    }
  case 8 :
    {
      const double a2 = a*a;
      const double a4 = a2*a2;
      return a4*a4;
    }
  case 9 :
    {
      const double a2 = a*a;
      const double a4 = a2*a2;
      return a4*a4*a;
    }
  case 10 :
    {
      const double a2 = a*a;
      const double a4 = a2*a2;
      return a4*a4*a2;
    }
  default :
    return pow_int(a,n-1)*a;
  }
}

fullMatrix<double> generate1DMonomials(int order);




class polynomialBasis : public nodalBasis
{
  // integrationOrder, closureId => df/dXi
//  mutable std::map<int,std::vector<fullMatrix<double> > > _dfAtFace;
 public:
  // for now the only implemented polynomial basis are nodal poly
  // basis, we use the type of the corresponding gmsh element as type
  //int type, parentType, order, dimension;
  //bool serendip;

  //fullMatrix<double> points;
  fullMatrix<double> monomials;
  fullMatrix<double> coefficients;

  polynomialBasis(int tag);
  ~polynomialBasis();

  virtual void f(double u, double v, double w, double *sf) const;
  virtual void f(fullMatrix<double> &coord, fullMatrix<double> &sf) const;
  virtual void df(fullMatrix<double> &coord, fullMatrix<double> &dfm) const;
  virtual void df(double u, double v, double w, double grads[][3]) const;
  virtual void ddf(double u, double v, double w, double hess[][3][3]) const;
  virtual  void dddf(double u, double v, double w, double third[][3][3][3]) const;

  virtual int getNumShapeFunctions() const;

  inline void evaluateMonomials(double u, double v, double w, double p[]) const;

};



inline void polynomialBasis::evaluateMonomials(double u, double v, double w, double p[]) const
{
  for (int j = 0; j < monomials.size1(); j++) {
    p[j] = pow_int(u, (int)monomials(j, 0));
    if (monomials.size2() > 1) p[j] *= pow_int(v, (int)monomials(j, 1));
    if (monomials.size2() > 2) p[j] *= pow_int(w, (int)monomials(j, 2));
  }
}



#endif
