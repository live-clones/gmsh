// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _MINI_BASIS_H_
#define _MINI_BASIS_H_

#include "polynomialBasis.h"
// mini is NOT a real nodal basis but in GMSH, only the nodal basis have closure
// and mini have closure so...

class miniBasisTri : public polynomialBasis {
public:
  miniBasisTri();
};
class miniBasisTet : public polynomialBasis {
public:
  miniBasisTet();
};

#endif
