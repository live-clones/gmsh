// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _HELMHOLTZ_TERM_H_
#define _HELMHOLTZ_TERM_H_

#include <assert.h>
#include "femTerm.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "SElement.h"
#include "fullMatrix.h"
#include "Numeric.h"

// \nabla \cdot k \nabla U - a U 
template<class scalar>
class helmholtzTerm : public femTerm<scalar> {
 protected:
  const simpleFunction<scalar> *_k, *_a;
  const int _iFieldR;
  int _iFieldC ;
 public:
  helmholtzTerm(GModel *gm, int iFieldR, int iFieldC, simpleFunction<scalar> *k,
                simpleFunction<scalar> *a) 
    : femTerm<scalar>(gm), _k(k), _a(a), _iFieldR(iFieldR), _iFieldC(iFieldC) {}
  // one dof per vertex (nodal fem)
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
               Dof::createTypeWithTwoInts(0, _iFieldR));
  }
  Dof getLocalDofC(SElement *se, int iRow) const
  {
    return Dof(se->getMeshElement()->getShapeFunctionNode(iRow)->getNum(),
               Dof::createTypeWithTwoInts(0, _iFieldC));
  }
  virtual void elementMatrix(SElement *se, fullMatrix<scalar> &m) const
  {

    MElement *e = se->getMeshElement();
    // compute integration rule
    // const int integrationOrder = (_a) ? 2 * e->getPolynomialOrder() : 
    //2 * (e->getPolynomialOrder() - 1);
       const int integrationOrder = 2 * e->getPolynomialOrder() + 1; 

    int npts; IntPt *GP;
    e->getIntegrationPoints(integrationOrder, &npts, &GP);
    // get the number of nodes
    const int nbSF = e->getNumShapeFunctions();
    // assume a maximum of 100 nodes
    assert(nbSF < 100);
    double jac[3][3];
    double invjac[3][3];
    double Grads[100][3], grads[100][3];  
    double sf[100];
    // set the local matrix to 0 
    m.setAll(0.);
    // loop over integration points
    for (int i = 0; i < npts; i++){
      // compute stuff at this point
      const double u = GP[i].pt[0];
      const double v = GP[i].pt[1];
      const double w = GP[i].pt[2];
      const double weightDetJ = GP[i].weight * e->getJacobian(u, v, w, jac);   
      SPoint3 p; e->pnt(u, v, w, p);
      const scalar K = _k ? (*_k)(p.x(), p.y(), p.z()) : 0.0;
      const scalar A = _a ? (*_a)(p.x(), p.y(), p.z()) : 0.0;
      inv3x3(jac, invjac) ;
      e->getGradShapeFunctions(u, v, w, grads);
      if (_a) e->getShapeFunctions(u, v, w, sf);
      for (int j = 0; j < nbSF; j++){
        Grads[j][0] = invjac[0][0] * grads[j][0] + invjac[0][1] * grads[j][1] + 
          invjac[0][2] * grads[j][2];
        Grads[j][1] = invjac[1][0] * grads[j][0] + invjac[1][1] * grads[j][1] + 
          invjac[1][2] * grads[j][2];
        Grads[j][2] = invjac[2][0] * grads[j][0] + invjac[2][1] * grads[j][1] +
          invjac[2][2] * grads[j][2];
        if (!_a) sf[j] = 0;
      }
      for (int j = 0; j < nbSF; j++){
        for (int k = 0; k <= j; k++){
          m(j, k) += (K * (Grads[j][0] * Grads[k][0] +
                           Grads[j][1] * Grads[k][1] +
                           Grads[j][2] * Grads[k][2]) + A * sf[j] * sf[k]) * weightDetJ;
        }
      }
    }
    for (int j = 0; j < nbSF; j++)
      for (int k = 0; k < j; k++)
        m(k, j) = m(j, k);

  }
};

#endif
