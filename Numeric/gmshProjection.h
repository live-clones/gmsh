// THIS FILE WILL BE REMOVED AS SOON AS THE NEW SOLVER INTERFACE IS READY

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_PROJECTION_H_
#define _GMSH_PROJECTION_H_

#include "gmshTermOfFormulation.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "fullMatrix.h"

class gmshProjectionTerm : public gmshNodalFemTerm<double> {
 private:
  const int _iField ;
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
  gmshProjectionTerm(GModel *gm, int iField = 0) : 
    gmshNodalFemTerm<double>(gm), _iField(iField){}
  virtual void elementMatrix(MElement *e, fullMatrix<double> &m) const;
};

#endif
