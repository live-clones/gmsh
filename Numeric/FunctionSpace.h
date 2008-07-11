// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FUNCTION_SPACE_H_
#define _FUNCTION_SPACE_H_

#include <math.h>
#include <map>
#include "GmshMatrix.h"

struct gmshFunctionSpace 
{
  Double_Matrix points;
  Double_Matrix monomials;
  Double_Matrix coefficients;
  inline void computePows(double uu, double vv, double p[][2]) const
  {
    for(int j = 0; j < coefficients.size2(); j++){
      p[j][0] = pow(uu,monomials(j, 0));
      p[j][1] = pow(vv,monomials(j, 1));
    }
  }
  inline void f(double u, double v, double w, double *sf) const
  {
    for(int i = 0; i < coefficients.size1(); i++){
      sf[i] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        sf[i] += coefficients(i, j) * pow(u, monomials(j, 0)) * 
          pow(v, monomials(j, 1)) * pow(w, monomials(j, 2));
      }
    }
  }
  inline void f(double u, double v, double *sf) const
  {
    double p[256][2];
    computePows(u, v, p);
    for (int i = 0; i < coefficients.size1(); i++){
      sf[i] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        sf[i] += coefficients(i, j) * p[j][0] * p[j][1];
      }
    }
  }
  inline void df(double u, double v, double w, double grads[][3]) const
  {
    for (int i = 0; i < coefficients.size1(); i++){
      grads[i][0] = 0;
      grads[i][1] = 0;
      grads[i][2] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        if ((monomials)(j, 0) > 0)
          grads[i][0] += (coefficients)(i, j) * pow(u, (monomials)(j, 0) - 1) *
            (monomials)(j, 0) * pow(v, (monomials)(j, 1)) * 
            pow(w, (monomials)(j, 2));
        if ((monomials)(j, 1) > 0)
          grads[i][1] += (coefficients)(i, j) * pow(u,(monomials)(j, 0)) * 
            pow(v, (monomials)(j, 1) - 1) * (monomials)(j, 1) * 
            pow(w, (monomials)(j, 2));
        if ((monomials)(j, 2) > 0)
          grads[i][2] += (coefficients)(i, j) * pow(u, (monomials)(j, 0)) *
            pow(v, (monomials)(j, 1)) * pow(w, (monomials)(j, 2) - 1) * 
            (monomials)(j, 2);
      }
    }
  }
  inline void df(double u, double v, double w,double grads[][2]) const
  {
    double p[256][2];
    computePows(u, v, p);
    for (int i = 0; i < coefficients.size1(); i++){
      grads[i][0] = 0;
      grads[i][1] = 0;
      for(int j = 0; j < coefficients.size2(); j++){
        if ((monomials)(j, 0)  > 0)
          grads[i][0] += (coefficients)(i, j) * 
            pow(u, (monomials)(j, 0) - 1) * (monomials)(j, 0) * p[j][1];
        if ((monomials)(j, 1)  > 0)
          grads[i][1] += (coefficients)(i, j) * p[j][0] *
            pow(v, (monomials)(j, 1) - 1) * (monomials)(j, 1);
      }
    }
  }
};

class gmshFunctionSpaces 
{
  static std::map<int, gmshFunctionSpace> fs;
 public :
  static const gmshFunctionSpace &find(int); 
};

#endif
