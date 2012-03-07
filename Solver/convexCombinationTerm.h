
// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CONVEX_COMBINATION_TERM_H_
#define _CONVEX_COMBINATION_TERM_H_

#include <assert.h>
#include "femTerm.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "SElement.h"
#include "fullMatrix.h"
#include "Numeric.h"

class convexCombinationTerm : public femTerm<double> {
 protected:
  const simpleFunction<double> *_k;
  const int _iField;
 public:
  convexCombinationTerm(GModel *gm, int iField, simpleFunction<double> *k)
    : femTerm<double>(gm), _k(k), _iField(iField) {}
  virtual int sizeOfR(SElement *se) const
  {
    return se->getMeshElement()->getNumShapeFunctions();
  }
  virtual int sizeOfC(SElement *se) const 
  { 
    return se->getMeshElement()->getNumShapeFunctions();
  }
  Dof getLocalDofR(SElement *se, int iRow) const
  {
    return Dof(se->getMeshElement()->getShapeFunctionNode(iRow)->getNum(),
               Dof::createTypeWithTwoInts(0, _iField));
  }
  virtual void elementMatrix(SElement *se, fullMatrix<double> &m) const
  {

    MElement *e = se->getMeshElement();
    m.setAll(0.);
    const int nbSF = e->getNumShapeFunctions();
    for (int j = 0; j < nbSF; j++){
      MVertex *vj = e->getShapeFunctionNode(j);
      double diag = 0.0;
      for (int k = 0; k < nbSF; k++){
	MVertex *vk = e->getShapeFunctionNode(k);
	MVertex *vl = NULL;
	SVector3 a, b;
	double tan = 0.0;
	if ( k!=j && 3-j-k >= 0 && 3-j-k <=2) {
	  vl = e->getShapeFunctionNode(3-j-k);
	  a = SVector3(vk->x()-vj->x(),vk->y()-vj->y(),vk->z()-vj->z());
	  b = SVector3(vl->x()-vj->x(),vl->y()-vj->y(),vl->z()-vj->z());
	  double angle = myacos(dot(a,b)/(norm(a)*norm(b)));
	  tan = sin(angle*0.5)/cos(angle*0.5); 
	}
	double length  = vj->distance(vk);
	m(j, k) = -tan/length;
	//m(j, k) = -1; 
      }
      for (int k = 0; k < nbSF; k++){
	if (k != j) diag += (-m(j,k));
      }
      m(j, j) = diag;
    }
  }

};

#endif
