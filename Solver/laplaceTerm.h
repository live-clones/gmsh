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
  gmshFunction<scalar> *ONE;
 public:
  laplaceTerm(GModel *gm, int iFieldR) : 
    helmholtzTerm<scalar>(gm, iFieldR, iFieldR, 0, 0)
  {
    ONE = new  gmshFunction<scalar>(1.0);
    _k = ONE;
  }
  laplaceTerm(GModel *gm, int iFieldR, gmshFunction<scalar> *k) : 
    helmholtzTerm<scalar>(gm, iFieldR, iFieldR, k, 0), ONE(0)
  {}
  laplaceTerm(GModel *gm, int iFieldR, int iFieldC, gmshFunction<scalar> *k) : 
    helmholtzTerm<scalar>(gm, iFieldR, iFieldC, k, 0), ONE(0)
  {}
  virtual ~laplaceTerm()
  {
    if(ONE) delete ONE;
  } 
};

#endif
