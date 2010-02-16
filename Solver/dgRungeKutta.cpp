#include "dgRungeKutta.h"
#include "dgConservationLaw.h"
#include "dgDofContainer.h"
#include "dgLimiter.h"
#include "dgAlgorithm.h"
#include "dgGroupOfElements.h"
#include "bindings.h"

double dgRungeKutta::iterateEuler(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  double A[] = {0};
  double b[] = {1};
  return diagonalRK(claw, dt, solution, 1, A, b);
}

double dgRungeKutta::iterate44(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  double A[] = {0, 0.5, 0.5, 1};
  double b[] = {1./6, 1./3, 1./3, 1./6};
  return diagonalRK(claw, dt, solution, 4, A, b);
}

double dgRungeKutta::iterate22(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  double A[] = {0, 1};
  double b[] = {1./2, 1./2};
  return diagonalRK(claw, dt, solution, 2, A, b);
}

double dgRungeKutta::diagonalRK (const dgConservationLaw *claw,
			      double dt,				         // time-step
			      dgDofContainer *sol,
			      int nStages, double *A, double *b) { 
  // U_{n+1}=U_n+h*(SUM_i dt*b_i*K_i)
  // K_i=M^(-1)R(U_n+dt*A_i*K_{i-1})
  fullMatrix<double> residuEl, KEl;
  fullMatrix<double> iMassEl;

  int nbFields = claw->getNbFields();
  dgGroupCollection *groups = sol->getGroups();

  dgDofContainer K   (groups, nbFields);
  dgDofContainer Unp (groups, nbFields);
  dgDofContainer resd(groups, nbFields);
  K.scale(0.);
  K.axpy(*sol);
  Unp.scale(0.);
  Unp.axpy(*sol);

  for(int j=0; j<nStages;j++){
    if(j){
      K.scale(A[j]*dt);
      K.axpy(*sol);
    }

    if (_limiter) _limiter->apply(K, *groups);
    dgAlgorithm::residual(*claw,*groups,K,resd);
    K.scale(0.);
    for(int k=0; k < groups->getNbElementGroups(); k++) {
      dgGroupOfElements *group = groups->getElementGroup(k);
      int nbNodes = group->getNbNodes();
      for(int i=0;i<group->getNbElements();i++) {
        residuEl.setAsProxy(resd.getGroupProxy(k),i*nbFields,nbFields);
        KEl.setAsProxy(K.getGroupProxy(k),i*nbFields,nbFields);
        iMassEl.setAsProxy(group->getInverseMassMatrix(),i*nbNodes,nbNodes);
        iMassEl.mult(residuEl,KEl);
      }
    }
    Unp.axpy(K,b[j]*dt);
  }
  if (_limiter) _limiter->apply(Unp, *groups);
  sol->scale(0.);
  sol->axpy(Unp);
}

dgRungeKutta::dgRungeKutta():_limiter(NULL) {}

void dgRungeKutta::registerBindings(binding *b) {
  classBinding *cb = b->addClass<dgRungeKutta>("dgRungeKutta");
  cb->setDescription("various explicit Runge-Kutta time stepping schemes");
  methodBinding *cm;
  cm = cb->setConstructor<dgRungeKutta>();
  cm->setDescription("A new explicit runge kutta, pass parameters to the iterate function");
  cm = cb->addMethod("iterateEuler",&dgRungeKutta::iterateEuler);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing a forward euler step of time step dt for the conservation law");
  cm = cb->addMethod("iterate22",&dgRungeKutta::iterate22);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing Heun second order runge-kutta step of time step dt for the conservation law");
  cm = cb->addMethod("iterate44",&dgRungeKutta::iterate44);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing classical fourth order runge-kutta step of time step dt for the conservation law");
}
