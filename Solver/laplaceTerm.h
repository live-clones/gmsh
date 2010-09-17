// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LAPLACE_TERM_H_
#define _LAPLACE_TERM_H_

#include "helmholtzTerm.h"

// \nabla \cdot k \nabla U 
class laplaceTerm : public helmholtzTerm<double> {
 public:
 laplaceTerm(GModel *gm, int iField, simpleFunction<double> *k, dofManager<double> *dofView=NULL)
    : helmholtzTerm<double>(gm, iField, iField, k, 0) {}
 void elementVector(SElement *se, fullVector<double> &m) const
  {
    //adding here rhs
    printf("implment  rhs laplace term here\n");
  }
};

// a \nabla U 
class massTerm : public helmholtzTerm<double> {
 public:
  massTerm(GModel *gm, int iField, simpleFunction<double> *a)
    : helmholtzTerm<double>(gm, iField, iField, 0, a) {}
};


#endif
