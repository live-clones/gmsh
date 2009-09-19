// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_CONVEX_H_
#define _GMSH_CONVEX_H_

#include "gmshTermOfFormulation.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "fullMatrix.h"

class gmshConvexCombinationTerm : public gmshNodalFemTerm<double> {
 protected:
  const simpleFunction<double> *_diffusivity;
  const int _iField ;
 public:
  virtual int sizeOfR(MElement *e) const { return e->getNumVertices(); }
  virtual int sizeOfC(MElement *e) const { return e->getNumVertices(); }
  void getLocalDofR(MElement *e, int iRow, MVertex **vR, int *iCompR, int *iFieldR) const
  {
    *vR = e->getVertex(iRow);
    *iCompR = 0;
    *iFieldR = _iField;
  }
 public:
  gmshConvexCombinationTerm(GModel *gm, simpleFunction<double> *diffusivity, int iField = 0) : 
    gmshNodalFemTerm<double>(gm), _diffusivity(diffusivity), _iField(iField){}
  virtual void elementMatrix(MElement *e, fullMatrix<double> &m) const;
};


#endif
