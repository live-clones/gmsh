// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CONVEX_COMBINATION_TERM_H_
#define _CONVEX_COMBINATION_TERM_H_

#include "femTerm.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "SElement.h"
#include "fullMatrix.h"

class convexCombinationTerm : public femTerm<double, double> {
 protected:
  const simpleFunction<double> *_diffusivity;
  const int _iField;
 public:
  convexCombinationTerm(GModel *gm, int iField, simpleFunction<double> *diffusivity)
    : femTerm<double, double>(gm), _iField(iField), _diffusivity(diffusivity) {}
  virtual int sizeOfR(SElement *se) const
  {
    return se->getMeshElement()->getNumVertices();
  }
  virtual int sizeOfC(SElement *se) const 
  { 
    return se->getMeshElement()->getNumVertices();
  }
  Dof getLocalDofR(SElement *se, int iRow) const
  {
    return Dof(se->getMeshElement()->getVertex(iRow)->getNum(), _iField);
  }
  virtual void elementMatrix(SElement *e, fullMatrix<double> &m) const
  {
    m.set_all(0.);
    int nbNodes = e->getMeshElement()->getNumVertices();
    //double x = 0.3*(e->getVertex(0)->x()+e->getVertex(1)->x()+e->getVertex(2)->x());
    //double y = 0.3*(e->getVertex(0)->y()+e->getVertex(1)->y()+e->getVertex(2)->y());
    //double z = 0.3*(e->getVertex(0)->z()+e->getVertex(1)->z()+e->getVertex(2)->z());
    const double _diff = 1.0; 
    for (int j = 0; j < nbNodes; j++){
      for (int k = 0; k < nbNodes; k++){
        m(j,k) = -1.*_diff;
      }
      m(j,j) = (nbNodes - 1) * _diff;
    }
  }
};

#endif
