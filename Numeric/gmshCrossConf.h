// THIS FILE WILL BE REMOVED AS SOON AS THE NEW SOLVER INTERFACE IS READY

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_CROSSCONF_H_
#define _GMSH_CROSSCONF_H_

#include "gmshTermOfFormulation.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "fullMatrix.h"

class gmshCrossConfTerm : public gmshNodalFemTerm<double> {
 protected:
  const simpleFunction<double> *_diffusivity;
  const int _iField;
  int _iFieldB ;
 public:
  virtual int sizeOfR(MElement *e) const { return e->getNumVertices(); }
  virtual int sizeOfC(MElement *e) const { return e->getNumVertices(); }
  void getLocalDofR(MElement *e, int iRow, MVertex **vR, int *iCompR, int *iFieldR) const
  {
    *vR = e->getVertex(iRow);
    *iCompR = 0;
    *iFieldR = _iField;
  }
  void getLocalDofC(MElement *e, int iRow, MVertex **vR, int *iCompR, int *iFieldR) const
  {
    *vR = e->getVertex(iRow);
    *iCompR = 0;
    *iFieldR = _iFieldB;
  }
 public:
  gmshCrossConfTerm(GModel *gm, simpleFunction<double> *diffusivity, int iField = 0, int iFieldB=-1) : 
    gmshNodalFemTerm<double>(gm), _diffusivity(diffusivity), _iField(iField)
    {
      _iFieldB = (iFieldB==-1) ? _iField : iFieldB;
    }
  virtual void elementMatrix(MElement *e, fullMatrix<double> &m) const;
};

class gmshCrossConfTerm2DParametric : gmshCrossConfTerm {
  GFace *_gf;
 public:
  gmshCrossConfTerm2DParametric(GFace *gf, simpleFunction<double> *diffusivity, int iField = 0) : 
    gmshCrossConfTerm(gf->model(), diffusivity, iField), _gf(gf) {}
  virtual void elementMatrix(MElement *e, fullMatrix<double> &m) const;
};


#endif
