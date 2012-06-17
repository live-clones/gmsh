// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ORTHOGONAL_TERM_H_
#define _ORTHOGONAL_TERM_H_

#include "helmholtzTerm.h"
#include "dofManager.h"

class orthogonalTerm : public helmholtzTerm<double> {
 protected:
  PView *_pview;
  dofManager<double> *_dofView;
  bool withDof;
  std::map<MVertex*, double > *_distance_map;
 public:
 orthogonalTerm(GModel *gm, int iField, simpleFunction<double> *k,
                std::map<MVertex*, double > *distance_map)
   : helmholtzTerm<double>(gm, iField, iField, k, 0), withDof(false),
     _distance_map(distance_map) {}
  orthogonalTerm(GModel *gm, int iField, simpleFunction<double> *k, PView *pview)
    : helmholtzTerm<double>(gm, iField, iField, k, 0), _pview(pview), withDof(false) {}
 orthogonalTerm(GModel *gm, int iField, simpleFunction<double> *k,
                dofManager<double> *dofView)
   : helmholtzTerm<double>(gm, iField, iField, k, 0), _dofView(dofView), withDof(true) {}
  void elementVector(SElement *se, fullVector<double> &m) const
  {
    MElement *e = se->getMeshElement();
    int nbSF = e->getNumShapeFunctions();

    //fill elementary matrix mat(i,j)
    int integrationOrder = 2 * (e->getPolynomialOrder() - 1);
    int npts;
    IntPt *GP;
    double jac[3][3];
    double invjac[3][3];
    SVector3 Grads [256];
    double grads[256][3];
    e->getIntegrationPoints(integrationOrder, &npts, &GP);
    fullMatrix<double> mat(nbSF, nbSF);
    mat.setAll(0.);

    for(int i = 0; i < npts; i++){
      const double u = GP[i].pt[0];
      const double v = GP[i].pt[1];
      const double w = GP[i].pt[2];
      const double weight = GP[i].weight;
      const double detJ = e->getJacobian(u, v, w, jac);
      SPoint3 p; e->pnt(u, v, w, p);
      inv3x3(jac, invjac);
      e->getGradShapeFunctions(u, v, w, grads);
      for(int j = 0; j < nbSF; j++){
        Grads[j] = SVector3(invjac[0][0] * grads[j][0] + invjac[0][1] * grads[j][1] +
                            invjac[0][2] * grads[j][2],
                            invjac[1][0] * grads[j][0] + invjac[1][1] * grads[j][1] +
                            invjac[1][2] * grads[j][2],
                            invjac[2][0] * grads[j][0] + invjac[2][1] * grads[j][1] +
                            invjac[2][2] * grads[j][2]);
      }
      SVector3 N (jac[2][0], jac[2][1], jac[2][2]);
      for(int j = 0; j < nbSF; j++)
        for(int k = 0; k <= j; k++)
          mat(j, k) += dot(crossprod(Grads[j], Grads[k]), N) * weight * detJ;
    }
    for(int j = 0; j < nbSF; j++)
      for(int k = 0; k < j; k++)
        mat(k, j) = -1.* mat(j, k);

    //2) compute vector m(i) = mat(i,j)*val(j)
    fullVector<double> val(nbSF);
    val.scale(0.);

    for(int i = 0; i < nbSF; i++){
      std::map<MVertex*, double>::iterator it = _distance_map->find(e->getShapeFunctionNode(i));
      val(i) = it->second;
    }

    /* if( withDof){ */
    /*   for (int i = 0; i < nbSF; i++){ */
    /* 	_dofView->getDofValue( e->getShapeFunctionNode(i), 0, 1, val(i)); */
    /* 	 printf("val=%g \n", val(i)); */
    /*   } */
    /* } */
    /* else{ */
    /*   printf("with no dof \n"); */
    /*   exit(1); */
    /*   /\* PViewData *data = view->getData(); *\/ */
    /*   /\* for (int i = 0; i < nbSF; i++){ *\/ */
    /*   /\* 	data->getValue(0, e->, e->getNum(), e->getShapeFunctionNode(i)->getNum(), nod, 0, val(i)); *\/ */
    /*   /\* } *\/ */
    /* } */

    m.scale(0.);
    for(int i = 0; i < nbSF; i++)
      for(int j = 0; j < nbSF; j++)
	m(i) += -mat(i, j) * val(j);
  }
};

#endif
