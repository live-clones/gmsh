#include "function.h"
#include "dgFunctionIntegrator.h"
#include "dgDofContainer.h"
#include "fullMatrix.h"
#include "dgGroupOfElements.h"

#include <stdio.h>

dgFunctionIntegrator::dgFunctionIntegrator(const function *f):_f(f){}

void dgFunctionIntegrator::compute(dgDofContainer *sol,fullMatrix<double> &result){
  int nbFields=sol->getNbFields();
  dataCacheMap cacheMap;
  dataCacheDouble &UVW=cacheMap.get(function::getParametricCoordinates(),NULL);
  dataCacheDouble &solutionQPe=cacheMap.get(function::getSolution(),NULL);
  dataCacheDouble &F=cacheMap.get(_f);
  int nbRowResult=result.size1();
  result.scale(0.0);
  for(int iGroup=0;iGroup<sol->getGroups()->getNbElementGroups();iGroup++){
    dgGroupOfElements &group=*sol->getGroups()->getElementGroup(iGroup);
    fullMatrix<double> &solProxy=sol->getGroupProxy(&group);
    cacheMap.setNbEvaluationPoints(group.getNbIntegrationPoints());
    UVW.set()=group.getIntegrationPointsMatrix();
    fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * nbFields);
    group.getCollocationMatrix().mult(solProxy  , solutionQP); 
    fullMatrix<double> IPMatrix = group.getIntegrationPointsMatrix();
    for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
      cacheMap.setElement(group.getElement(iElement));
      solutionQPe.set().setAsProxy(solutionQP, iElement*nbFields, nbFields );
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iElement, iPt);
        for (int k=0;k<nbRowResult;k++){
          result(0,k) += F(iPt,k)*detJ*IPMatrix(iPt,3);
        }
      }
    }
  }
}

#include "Bindings.h"
void dgFunctionIntegrator::registerBindings(binding *b){
  classBinding *cb = b->addClass<dgFunctionIntegrator>("dgFunctionIntegrator");
  cb->setDescription("Integrates a function, using the compute function");
  methodBinding *mb;
  mb = cb->setConstructor<dgFunctionIntegrator,const function*>();
  mb->setArgNames("function",NULL);
  mb->setDescription("a new dgFunctionIntegrator, get the solution using the compute method");
  mb = cb->addMethod("compute", &dgFunctionIntegrator::compute);
  mb->setArgNames("dofContainer","result",NULL);
  mb->setDescription("compute the integral of the function");
}
