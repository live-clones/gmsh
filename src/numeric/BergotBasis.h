// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BERGOTBASIS_H
#define BERGOTBASIS_H

#include "nodalBasis.h"
#include "polynomialBasis.h"

// Basis functios for pyramidal elements: cf. M. Bergot, G. Cohen, M. Durufle,
// HIGHER-ORDER FINITE ELEMENTS FOR HYBRID MESHES USING NEW NODAL PYRAMIDAL
// ELEMENTS, J. Sci. Comput. 42, 3 (2010) 345-381", DOI:
// 10.1007/s10915-009-9334-9

class BergotBasis {
public:
  BergotBasis(int p, bool incpl = false);
  virtual ~BergotBasis();

  void f(double u, double v, double w, double *val) const;
  void df(double u, double v, double w, double grads[][3]) const;

  void initialize(){};

  bool validIJ(int i, int j) const;

private:
  int order; //!< maximal order of surrounding functional spaces (on triangle /
             //!< quad)
  bool incomplete; //!< serendipity interpolation
};

#endif
