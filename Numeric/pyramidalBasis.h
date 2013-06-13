// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef PYRAMIDALBASIS_H
#define PYRAMIDALBASIS_H

#include "fullMatrix.h"

#include "nodalBasis.h"
#include "BergotBasis.h"



class pyramidalBasis: public nodalBasis
{
 private:
  // Inverse of the Vandermonde matrix
  fullMatrix<double> VDMinv;

  // Orthogonal basis for the pyramid
  BergotBasis *bergot;

 public:
  pyramidalBasis(int tag);
  ~pyramidalBasis();

  virtual void f(double u, double v, double w, double *val) const;
  virtual void fnew(double u, double v, double w, double *val) const;
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const;
  virtual void df(double u, double v, double w, double grads[][3]) const;
  virtual void df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const;

  virtual int getNumShapeFunctions() const;

  inline void evaluateMonomialsNew(double u, double v, double w, double p[]) const {
    w = 1-w;
    if (w != .0) {
      u = u/w;
      v = v/w;
    }
    for (int j = 0; j < monomials_newAlgo.size1(); j++) {
      p[j] = pow_int(u, monomials_newAlgo(j, 0));
      if (dimension > 1) p[j] *= pow_int(v, monomials_newAlgo(j, 1));
      if (dimension > 2) p[j] *= pow_int(w, monomials_newAlgo(j, 2));
    }
  }
};



#endif
