// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CROSS_CONF_TERM_H_
#define _CROSS_CONF_TERM_H_

#include "femTerm.h"
#include "simpleFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "SElement.h"
#include "fullMatrix.h"
#include "Numeric.h"

class crossConfTerm : public femTerm<double> {
 protected:
  const simpleFunction<double> *_diffusivity;
  const int _iFieldR;
  int _iFieldC;
 public:
  crossConfTerm(GModel *gm, int iFieldR, int iFieldC, 
                simpleFunction<double> *diffusivity, dofManager<double> *dofView=NULL)
    : femTerm<double>(gm), _diffusivity(diffusivity), _iFieldR(iFieldR), 
      _iFieldC(iFieldC) {}

  virtual int sizeOfR(SElement *se) const 
  {
    return se->getMeshElement()->getNumVertices(); 
  }
  virtual int sizeOfC(SElement *se) const
  {
    return se->getMeshElement()->getNumVertices(); 
  }
  Dof getLocalDofR(SElement *se, int iRow) const
  {
     return Dof(se->getMeshElement()->getVertex(iRow)->getNum(), 
               Dof::createTypeWithTwoInts(0, _iFieldR));
  }
  Dof getLocalDofC(SElement *se, int iRow) const
  {
    return Dof(se->getMeshElement()->getVertex(iRow)->getNum(),
               Dof::createTypeWithTwoInts(0, _iFieldC));
  }
  virtual void elementMatrix(SElement *se, fullMatrix<double> &m) const
  {
    MElement *e = se->getMeshElement();
    int nbNodes = e->getNumVertices();
    int integrationOrder = 2 * (e->getPolynomialOrder() - 1); 
    int npts;
    IntPt *GP;
    double jac[3][3];
    double invjac[3][3];
    SVector3 Grads [256];
    double grads[256][3];
    e->getIntegrationPoints(integrationOrder, &npts, &GP);

    m.setAll(0.);
    
    for (int i = 0; i < npts; i++){
      const double u = GP[i].pt[0];
      const double v = GP[i].pt[1];
      const double w = GP[i].pt[2];
      const double weight = GP[i].weight;
      const double detJ = e->getJacobian(u, v, w, jac);   
      SPoint3 p; e->pnt(u, v, w, p);
      const double _diff = (*_diffusivity)(p.x(), p.y(), p.z());
      inv3x3(jac, invjac); 
      e->getGradShapeFunctions(u, v, w, grads);
      for (int j = 0; j < nbNodes; j++){
        Grads[j] = SVector3(invjac[0][0] * grads[j][0] + invjac[0][1] * grads[j][1] + 
                            invjac[0][2] * grads[j][2],
                            invjac[1][0] * grads[j][0] + invjac[1][1] * grads[j][1] + 
                            invjac[1][2] * grads[j][2],
                            invjac[2][0] * grads[j][0] + invjac[2][1] * grads[j][1] +
                            invjac[2][2] * grads[j][2]);
      }
      SVector3 N (jac[2][0], jac[2][1], jac[2][2]);
      for (int j = 0; j < nbNodes; j++){
        for (int k = 0; k <= j; k++){
          m(j, k) += dot(crossprod(Grads[j], Grads[k]), N) * weight * detJ * _diff;
        }
      }
    }
    for (int j = 0; j < nbNodes; j++)
      for (int k = 0; k < j; k++)
        m(k, j) = -1.* m(j, k);
  }
 void elementVector(SElement *se, fullVector<double> &m) const
  {
    //adding here rhs
    printf("implment  rhs cross term here\n");
  }
};

#endif
