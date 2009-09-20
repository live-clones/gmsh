// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LAPLACE_TERM_H_
#define _LAPLACE_TERM_H_

#include "helmholtzTerm.h"

// \nabla \cdot k \nabla U 
class laplaceTerm : public helmholtzTerm<double> {
 public:
  laplaceTerm(GModel *gm, int iField, simpleFunction<double> *k)
    : helmholtzTerm<double>(gm, iField, iField, k, 0) {}
};

#endif
