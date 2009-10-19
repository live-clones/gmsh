// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ELASTICITY_TERM_H_
#define _ELASTICITY_TERM_H_

#include "femTerm.h"
#include "Gmsh.h"
#include "GModel.h"
#include "SElement.h"
#include "fullMatrix.h"

class elasticityTerm : public femTerm<double, double> {
 protected:
  double _E, _nu;
  int _iFieldR, _iFieldC;
  SVector3 _volumeForce;
 public:
  void setFieldC(int i){_iFieldC = i;}
  void setFieldR(int i){_iFieldR = i;}
  // element matrix size : 3 dofs per vertex
  virtual int sizeOfR(SElement *se) const
  {
    return 3 * se->getMeshElement()->getNumVertices();
  }
  virtual int sizeOfC(SElement *se) const
  {
    return 3 * se->getMeshElement()->getNumVertices();
  }
  // order dofs in the local matrix :
  // dx1, dx2 ... dxn, dy1, ..., dyn, dz1, ... dzn 
  Dof getLocalDofR(SElement *se, int iRow) const
  {
    MElement *e = se->getMeshElement();
    int iCompR = iRow / e->getNumVertices();
    int ithLocalVertex = iRow % e->getNumVertices();
    return Dof(e->getVertex(ithLocalVertex)->getNum(),
               Dof::createTypeWithTwoInts(iCompR, _iFieldR));
  }
  Dof getLocalDofC(SElement *se, int iCol) const
  {
    MElement *e = se->getMeshElement();
    int iCompC = iCol / e->getNumVertices();
    int ithLocalVertex = iCol % e->getNumVertices();
    return Dof(e->getVertex(ithLocalVertex)->getNum(),
               Dof::createTypeWithTwoInts(iCompC, _iFieldC));
  }
 public:
 elasticityTerm(GModel *gm, double E, double nu, int fieldr, int fieldc)
   : femTerm<double, double>(gm), _E(E), _nu(nu), _iFieldR(fieldr),_iFieldC(fieldc) {}
 elasticityTerm(GModel *gm, double E, double nu, int fieldr)
   : femTerm<double, double>(gm), _E(E), _nu(nu), _iFieldR(fieldr),_iFieldC(fieldr) {}
  void setVector(const SVector3 &f) { _volumeForce = f; }
  void elementMatrix(SElement *se, fullMatrix<double> &m) const;
  void elementVector(SElement *se, fullVector<double> &m) const;
};

#endif
