#ifndef _GMSH_ELASTICITY_H_
#define _GMSH_ELASTICITY_H_
#include "gmshTermOfFormulation.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "GmshMatrix.h"

class gmshElasticityTerm : public gmshNodalFemTerm {
  double _E,_nu;
  int _iField;
 protected:
  virtual int sizeOfR (MElement *e) const {return 3*e->getNumVertices();}
  virtual int sizeOfC (MElement *e) const {return 3*e->getNumVertices();}
  void getLocalDofR (MElement *e, int iRow, MVertex **vR, int *iCompR, int *iFieldR) const
  {
    *iCompR = iRow/e->getNumVertices();
    int ithLocalVertex = iRow%e->getNumVertices();
    *vR = e->getVertex (ithLocalVertex);
    *iFieldR = _iField;
  }
public:
  gmshElasticityTerm (GModel *gm, double E, double nu, int iField = 1) : 
    gmshNodalFemTerm(gm),_E(E),_nu(nu),_iField(iField){}
  void elementMatrix ( MElement *e, Double_Matrix & m) const;
};

#endif
