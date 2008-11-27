// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_LAPLACE_H_
#define _GMSH_LAPLACE_H_

#include "gmshTermOfFormulation.h"
#include "gmshFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "GmshMatrix.h"

class gmshLaplaceTerm : public gmshNodalFemTerm {
  const int _iField ;
  const gmshFunction * _diffusivity;
 protected:
  virtual int sizeOfR(MElement *e) const { return e->getNumVertices(); }
  virtual int sizeOfC(MElement *e) const { return e->getNumVertices(); }
  void getLocalDofR(MElement *e, int iRow, MVertex **vR, int *iCompR, int *iFieldR) const
  {
    *vR = e->getVertex(iRow);
    *iCompR = 0;
    *iFieldR = _iField;
  }
 public:
  gmshLaplaceTerm(GModel *gm, gmshFunction *diffusivity, int iField = 0) : 
    gmshNodalFemTerm(gm),_diffusivity(diffusivity), _iField(iField){}
  virtual void elementMatrix(MElement *e, Double_Matrix &m) const;
};


#endif
