// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ELASTICITY_TERM_H_
#define _ELASTICITY_TERM_H_

#include "femTerm.h"
#include "Gmsh.h"
#include "GModel.h"
#include "polynomialBasis.h"
#include "SElement.h"
#include "fullMatrix.h"

class elasticityTerm : public femTerm<double> {
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
    return 3 * se->getMeshElement()->getNumShapeFunctions();
  }
  virtual int sizeOfC(SElement *se) const
  {
    return 3 * se->getMeshElement()->getNumShapeFunctions();
  }
  // order dofs in the local matrix :
  // dx1, dx2 ... dxn, dy1, ..., dyn, dz1, ... dzn 
  Dof getLocalDofR(SElement *se, int iRow) const
  {
    MElement *e = se->getMeshElement();
    int iCompR = iRow / e->getNumShapeFunctions();
    int ithLocalVertex = iRow % e->getNumShapeFunctions();
    return Dof(e->getShapeFunctionNode(ithLocalVertex)->getNum(),
               Dof::createTypeWithTwoInts(iCompR, _iFieldR));
  }
  Dof getLocalDofC(SElement *se, int iCol) const
  {
    MElement *e = se->getMeshElement();
    int iCompC = iCol / e->getNumShapeFunctions();
    int ithLocalVertex = iCol % e->getNumShapeFunctions();
    return Dof(e->getShapeFunctionNode(ithLocalVertex)->getNum(),
               Dof::createTypeWithTwoInts(iCompC, _iFieldC));
  }
 public:
 elasticityTerm(GModel *gm, double E, double nu, int fieldr, int fieldc)
   : femTerm<double>(gm), _E(E), _nu(nu), _iFieldR(fieldr),_iFieldC(fieldc) {}
 elasticityTerm(GModel *gm, double E, double nu, int fieldr)
   : femTerm<double>(gm), _E(E), _nu(nu), _iFieldR(fieldr),_iFieldC(fieldr) {}
  void setVector(const SVector3 &f) { _volumeForce = f; }
  void elementMatrix(SElement *se, fullMatrix<double> &m) const;
  void elementVector(SElement *se, fullVector<double> &m) const;
};

/*
  Formulation of elasticity with 3 fields
   -) displacement U
   -) lagrange multipliers p and g
  
   g = trace (epsilon) 
   p = trace (epsilon) 


*/

class elasticityMixedTerm : public femTerm<double> {
protected:
  double _E, _nu;
  mutable int _iField, _polyOrderN, _polyOrderM, _sizeN, _sizeM;
  mutable polynomialBasis *_pN,*_pM;
  void setPolynomialBasis (SElement *se) const{
    _polyOrderN =  se->getMeshElement()->getPolynomialOrder();
    _polyOrderM =  se->getMeshElement()->getPolynomialOrder();
    _pN =  (polynomialBasis*)se->getMeshElement()->getFunctionSpace(_polyOrderN);
    _pM =  (polynomialBasis*)se->getMeshElement()->getFunctionSpace(_polyOrderM);
    _sizeN = _pN->coefficients.size1();
    _sizeM = _pM->coefficients.size1();
  }
public:
  void setField(int i){_iField = i;}
  // element matrix size : 3 dofs per vertex
  virtual int sizeOfR(SElement *se) const
  {
    setPolynomialBasis(se);
    return 3 * _sizeN + 2 * _sizeM;
  }
  virtual int sizeOfC(SElement *se) const
  {
    return sizeOfR(se);
  }
  // order dofs in the local matrix :
  // dx1, dx2 ... dxn, dy1, ..., dyn, dz1, ... dzn , 
  // p1,p2,...,pm, g1,g2,...,gm
  Dof getLocalDofR(SElement *se, int iRow) const
  {
    setPolynomialBasis(se);
    MElement *e = se->getMeshElement();
    int iComp;
    int ithLocalVertex;
    if (iRow < 3 * _sizeN){
      iComp = iRow / _sizeN;
      ithLocalVertex = iRow % _sizeN;
    }
    else {
      iRow -= 3 * _sizeN;
      iComp = 3 + iRow / _sizeM;
      ithLocalVertex = iRow % _sizeM;      
    }
    return Dof(e->getShapeFunctionNode(ithLocalVertex)->getNum(),
               Dof::createTypeWithTwoInts(iComp, _iField));
  }
  Dof getLocalDofC(SElement *se, int iCol) const
  {
    return getLocalDofR(se,iCol);
  }
 public:
 elasticityMixedTerm(GModel *gm, double E, double nu, int field)
   : femTerm<double>(gm), _E(E), _nu(nu), _iField(field) {}
  void elementMatrix(SElement *se, fullMatrix<double> &m) const;
  void elementVector(SElement *se, fullVector<double> &m) const {}
  void setYoung (double E){_E = E;}
};


#endif
