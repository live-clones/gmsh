// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DIAGBC_TERM_H_
#define _DIAGBC_TERM_H_

#include <assert.h>
#include "femTerm.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "SElement.h"
#include "fullMatrix.h"
#include "Numeric.h"

class diagBCTerm : public femTerm<double> {
 protected:
  const simpleFunction<double> *_k;
  const int _iField;
 public:
  diagBCTerm(GModel *gm, int iField, simpleFunction<double> *k)
    : femTerm<double>(gm), _k(k), _iField(iField) {}
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
    return Dof(se->getMeshElement()->getVertex(iRow)->getNum(), 
               Dof::createTypeWithTwoInts(0, _iField));
  }

  virtual void elementMatrix(SElement *se, fullMatrix<double> &m) const
  {

    MElement *e = se->getMeshElement();
    m.setAll(0.);
    const int nbNodes = e->getNumVertices();
    for (int j = 0; j < nbNodes; j++){
      for (int k = 0; k < nbNodes; k++) {
        m(j,k) = 0.0;
        m(k,j) = 0.0;
      }
      MVertex *v = e->getVertex(j);
      if( v->onWhat()->dim() < 2 ) m(j,j) = 1.0; 
      else m(j,j) = 0.0;
    }
  } 
  

};

#endif
