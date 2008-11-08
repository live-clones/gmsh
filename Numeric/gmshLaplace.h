#ifndef _GMSH_LAPLACE_H_
#define _GMSH_LAPLACE_H_
#include "gmshTermOfFormulation.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "GmshMatrix.h"

class gmshLaplaceTerm : public gmshNodalFemTerm {
  const double _diffusivity;
  const int _iField ;
 protected:
  virtual int sizeOfR (MElement *e) const { return e->getNumVertices(); }
  virtual int sizeOfC (MElement *e) const { return e->getNumVertices(); }
  void getLocalDofR (MElement *e, int iRow, MVertex **vR, int *iCompR, int *iFieldR) const
  {
    *vR = e->getVertex (iRow);
    *iCompR = 0;
    *iFieldR = _iField;
  }
 public:
  gmshLaplaceTerm (GModel *gm, double diffusivity = 1.0, int iField = 0) : 
    gmshNodalFemTerm(gm),_diffusivity (diffusivity),_iField(iField){}
  void elementMatrix ( MElement *e, Double_Matrix & m) const;
  double getDiffusivity () const { return _diffusivity; }
};
#endif
