// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef BERGOTBASIS_H
#define BERGOTBASIS_H

#include "nodalBasis.h"
#include "polynomialBasis.h"
#include "jacobiPolynomials.h"
#include "legendrePolynomials.h"

class BergotBasis : public nodalBasis {
 public:

  BergotBasis() {};
  BergotBasis(int p);
  ~BergotBasis();

  void f(double u, double v, double w, double *val) const;
  inline void df(double u, double v, double w, double grads[][3]) const;

  void initialize() {};

 private:
  int order; //!< maximal order of surrounding functional spaces (on triangle / quad)

  int *iOrder; //!< order of \f$\hat \xi \f$ polynomial
  int *jOrder; //!< order of \f$\hat \eta \f$ polynomial
  int *kOrder; //!< order of \f$\hat \zeta \f$ polynomial

  //! list of Legendre polynomials up to order p
  LegendrePolynomials legendre;

  //! list of Jacobi polynomials up to order p in function of index i (\f$ \alpha = 2*i + 2\f$)
  std::map<int,JacobiPolynomials> jacobi;

  int size() const;

};

#endif
