#ifndef _MINI_BASIS_H_
#define _MINI_BASIS_H_
#include "polynomialBasis.h"
class miniBasis : public polynomialBasis { // mini is NOT a real nodal basis but in GMSH, only the nodal basis have closure and mini have closure so...
  public:
    miniBasis();
};
#endif
