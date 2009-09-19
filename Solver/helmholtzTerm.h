// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _HELMHOLTZ_TERM_H_
#define _HELMHOLTZ_TERM_H_

#include <assert.h>
#include "femTerm.h"
#include "gmshFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "fullMatrix.h"
#include "Numeric.h"

// \nabla \cdot k \nabla U + a U 
template<class scalar>
class helmoltzTerm : public femTerm<scalar, scalar> {
 protected:
  const gmshFunction<scalar> *_k, *_a;
  const int _iFieldR;
  int _iFieldC ;
 public:
  // one dof per vertex (nodal fem)
  virtual int sizeOfR(MElement *e) const { return e->getNumVertices(); }
  virtual int sizeOfC(MElement *e) const { return e->getNumVertices(); }
  Dof getLocalDofR(MElement *e, int iRow) const
  {
    return Dof(e->getVertex(iRow)->getNum(), _iFieldR);
  }
  Dof getLocalDofC(MElement *e, int iRow) const
  {
    return Dof(e->getVertex(iRow)->getNum(), _iFieldC);
  }
  public:
  helmoltzTerm(GModel *gm, int iFieldR, int iFieldC, 
               gmshFunction<scalar> *k, 
               gmshFunction<scalar> *a) : 
    femTerm<scalar,scalar>(gm), _k(k), _a(a), _iFieldR(iFieldR), _iFieldC(iFieldC){}
  virtual void elementMatrix(MElement *e, fullMatrix<scalar> &m) const
  {
    // compute integration rule
    const int integrationOrder = (_a) ? 2 * e->getPolynomialOrder() : 
      2 * (e->getPolynomialOrder() - 1);
    int npts;IntPt *GP;
    e->getIntegrationPoints(integrationOrder, &npts, &GP);
    // get the number of nodes
    const int nbNodes = e->getNumVertices();
    // assume a maximum of 100 nodes
    assert (nbNodes < 100);
    double jac[3][3];
    double invjac[3][3];
    double Grads[100][3], grads[100][3];  
    double sf[100];
    // set the local matrix to 0 
    m.set_all(0.);
    // loop over integration points
    for (int i = 0; i < npts; i++){
      // compute stuff at this point
      const double u = GP[i].pt[0];
      const double v = GP[i].pt[1];
      const double w = GP[i].pt[2];
      const double weightDetJ = GP[i].weight * e->getJacobian(u, v, w, jac);   
      SPoint3 p; e->pnt(u, v, w, p);
      const scalar K = (*_k)(p.x(), p.y(), p.z());
      const scalar A = _a ? (*_a)(p.x(), p.y(), p.z()) : 0.0;
      inv3x3(jac, invjac) ;
      e->getGradShapeFunctions(u, v, w, grads);
      if (_a) e->getShapeFunctions(u, v, w, sf);
      for (int j = 0; j < nbNodes; j++){
        Grads[j][0] = invjac[0][0] * grads[j][0] + invjac[0][1] * grads[j][1] + 
          invjac[0][2] * grads[j][2];
        Grads[j][1] = invjac[1][0] * grads[j][0] + invjac[1][1] * grads[j][1] + 
          invjac[1][2] * grads[j][2];
        Grads[j][2] = invjac[2][0] * grads[j][0] + invjac[2][1] * grads[j][1] +
          invjac[2][2] * grads[j][2];
        if (!_a) sf[j] = 0;
      }
      for (int j = 0; j < nbNodes; j++){
        for (int k = 0; k <= j; k++){
          m(j, k) += (K * (Grads[j][0] * Grads[k][0] +
                           Grads[j][1] * Grads[k][1] +
                           Grads[j][2] * Grads[k][2]) + A * sf[j] * sf[k]) * 
            weightDetJ;
        }
      }
    }
    for (int j = 0; j < nbNodes; j++)
      for (int k = 0; k < j; k++)
        m(k, j) = m(j, k);
  }
};

#endif
