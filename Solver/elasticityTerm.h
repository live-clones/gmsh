// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ELASTICITY_H_
#define _ELASTICITY_H_

#include "termOfFormulation.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "GmshMatrix.h"

namespace gsolver {
  class elasticityTerm : public femTerm<double,double> {
  protected:
    double _E, _nu;
    int _iField;
    SVector3 _volumeForce;
 public:
    // element matrix size : 3 dofs per vertex
    virtual int sizeOfR(MElement *e) const { return 3 * e->getNumVertices(); }
    virtual int sizeOfC(MElement *e) const { return 3 * e->getNumVertices(); }
    // order dofs in the local matrix :
    // dx1, dx2 ... dxn, dy1, ..., dyn, dz1, ... dzn 
    Dof getLocalDofR(MElement *e, int iRow) const 
    {
      int iCompR = iRow / e->getNumVertices();
      int ithLocalVertex = iRow % e->getNumVertices();
      return Dof (e->getVertex(ithLocalVertex)->getNum(),
		  Dof::createTypeWithTwoInts(iCompR, _iField));
    }
  public:
    elasticityTerm(GModel *gm, double E, double nu, int iField = 1) : 
      femTerm<double,double>(gm), _E(E), _nu(nu), _iField(iField){}
    void setVector(const SVector3 &f) {_volumeForce = f;}
    void elementMatrix(MElement *e, gmshMatrix<double> &m) const;
    void elementVector(MElement *e, gmshVector<double> &m) const;
  };
}

#endif
