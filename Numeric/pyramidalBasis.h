// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef PYRAMIDALBASIS_H
#define PYRAMIDALBASIS_H

#include "fullMatrix.h"

#include "nodalBasis.h"
#include "BergotBasis.h"



class pyramidalBasis: public nodalBasis
{
 private:
  // Inverse of the Vandermonde matrix
  fullMatrix<double>* VDMinv;

  // Orthogonal basis for the pyramid
  BergotBasis *bergot;

 public:
  pyramidalBasis(int tag);
  ~pyramidalBasis();

  virtual void f(double u, double v, double w, double *val) const;
  virtual void f(fullMatrix<double> &coord, fullMatrix<double> &sf);
  virtual void df(double u, double v, double w, double grads[][3]) const;
  virtual void df(fullMatrix<double> &coord, fullMatrix<double> &dfm) const;

};



#endif
