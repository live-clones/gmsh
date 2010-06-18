// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _POLYNOMIAL_BASIS_H_
#define _POLYNOMIAL_BASIS_H_

#include <math.h>
#include <map>
#include <vector>
#include "fullMatrix.h"
#include <iostream>

inline double pow_int (const double &a , const int &n) {
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

class binding;

// presently those function spaces are only for simplices and quads;
// should be extended to other elements like hexes
class polynomialBasis 
{
 public:
  typedef std::vector<std::vector<int> > clCont;
  clCont closures;
  fullMatrix<double> points;
  fullMatrix<double> monomials;
  fullMatrix<double> coefficients;
  int numFaces;
  // for a given face/edge, with both a sign and a rotation,
  // give an ordered list of nodes on this face/edge
  inline const std::vector<int> &getClosure(int id) const // return the closure of dimension dim
  { 
    return closures[id];
  }
  inline int getClosureId(int iEl, int iSign=1, int iRot=0) const {
    return iEl + numFaces*(iSign == 1 ? 0 : 1) + 2*numFaces*iRot;
  }
  inline void evaluateMonomials(double u, double v, double w, double p[]) const
  {
    for (int j = 0; j < monomials.size1(); j++) {
      p[j] = pow_int(u, (int)monomials(j, 0));
      if (monomials.size2() > 1) p[j] *= pow_int(v, (int)monomials(j, 1));
      if (monomials.size2() > 2) p[j] *= pow_int(w, (int)monomials(j, 2));
    }
  }
  inline void f(double u, double v, double w, double *sf) const
  {
    double p[256];
    evaluateMonomials(u, v, w, p);
    for (int i = 0; i < coefficients.size1(); i++) {
      sf[i] = 0;
      for (int j = 0; j < coefficients.size2(); j++) {
        sf[i] += coefficients(i, j) * p[j];
      }
    }
  }
  // I would favour this interface that allows optimizations (not implemented) and is easier to bind
  inline void f(fullMatrix<double> &coord, fullMatrix<double> &sf) {
    double p[256];
    sf.resize (coefficients.size1(), coord.size1());
    for (int iPoint=0; iPoint< coord.size1(); iPoint++) {
      evaluateMonomials(coord(iPoint,0), coord(iPoint,1), coord(iPoint,2), p);
      for (int i = 0; i < coefficients.size1(); i++)
        for (int j = 0; j < coefficients.size2(); j++)
          sf(i,iPoint) += coefficients(i, j) * p[j];
    }
  }
  inline void df(double u, double v, double w, double grads[][3]) const
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
  inline void ddf(double u, double v, double w, double hess[][3][3]) const
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
  static void registerBindings(binding *b);
};

class polynomialBases
{
 private:
  static std::map<int, polynomialBasis> fs;
  static std::map<std::pair<int, int>, fullMatrix<double> > injector;
 public :
  static const polynomialBasis *find(int);
  static const fullMatrix<double> &findInjector(int, int);
};

#endif
