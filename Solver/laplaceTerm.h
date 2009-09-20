// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LAPLACE_TERM_H_
#define _LAPLACE_TERM_H_

#include "helmholtzTerm.h"

// \nabla \cdot k \nabla U 
template<class scalar>
class laplaceTerm : public helmholtzTerm<scalar> {
 public:
  laplaceTerm(GModel *gm, int iField, simpleFunction<scalar> *k)
    : helmholtzTerm<scalar>(gm, iField, iField, k, 0) {}
};

#endif
