#include <stdlib.h>
#include "dgRungeKutta.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "dgDofContainer.h"
#include "dgLimiter.h"
#include "dgTransformNodalValue.h"
#include "dgResidual.h"
#include "dgGroupOfElements.h"
#include <limits.h>
#include <stdio.h>
#ifdef HAVE_MPI
#include "mpi.h"
#endif

double dgRungeKutta::iterateEuler(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  double A[] = {0};
  double b[] = {1};
  return diagonalRK(claw, dt, solution, 1, A, b);
}

double dgRungeKutta::iterate22(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  double A[] = {0, 1};
  double b[] = {1./2, 1./2};
  return diagonalRK(claw, dt, solution, 2, A, b);
}
double dgRungeKutta::iterate33(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  double A[] = {0, 1./3, 2./3};
  double b[] = {1./4,0, 3./4};
  return diagonalRK(claw, dt, solution, 3, A, b);
}
double dgRungeKutta::iterate44(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  double A[] = {0, 0.5, 0.5, 1};
  double b[] = {1./6, 1./3, 1./3, 1./6};
  return diagonalRK(claw, dt, solution, 4, A, b);
}


double dgRungeKutta::iterate44ThreeEight(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  // 3/8 RK44
  double A[4][4]={
     {0, 0, 0, 0},
     {1.0/3.0, 0, 0 ,0},
     {-1.0/3.0, 1.0, 0, 0},
     {1, -1, 1, 0}
  };
  fullMatrix<double> Afm(4,4);
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      Afm(i,j)=A[i][j];
    }
  }
  double b[4]={1.0/8.0, 3.0/8.0, 3.0/8.0, 1.0/8.0};
  double c[4]={0, 1.0/3.0, 2.0/3.0, 1};
  return nonDiagonalRK(claw, dt, solution, 4, Afm, b, c);
}

double dgRungeKutta::iterateRKFehlberg45(const dgConservationLaw *claw, double dt, dgDofContainer *solution){
  double A[6][6]={
    {0,0,0,0,0,0},
    {1.0/4,0,0,0,0,0},
    {3.0/32,9.0/32,0,0,0,0},
    {1932.0/2197,-7200.0/2197,7296.0/2197,0,0,0},
    {439.0/216,-8,3680.0/513,-845.0/4104,0,0},
    {8.0/27,2,-3544.0/2565,-1859.0/4104,-11.0/40,0},
  };
  double c[6];
  fullMatrix<double> Afm(6,6);
  for(int i=0;i<6;i++){
    c[i]=0;
    for(int j=0;j<6;j++){
      Afm(i,j)=A[i][j];
      c[i]+=A[i][j];
    }
  }
  double b[6]={16.0/235,6656.0/12825,28561.0/56430,-9.0/50,2.0/55};
  return nonDiagonalRK(claw, dt, solution, 6, Afm, b, c);
}


double dgRungeKutta::iterate43SchlegelJCAM2009(const dgConservationLaw *claw, double dt, dgDofContainer *solution) {
  // RK43 from Schlegel et al. JCAM 2009
  double A[4][4]={
     {0, 0, 0, 0},
     {1.0/2.0, 0, 0 ,0},
     {-1.0/6.0, 2.0/3.0, 0, 0},
     {1.0/3.0, -1.0/3.0, 1, 0}
  };
  fullMatrix<double> Afm(4,4);
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      Afm(i,j)=A[i][j];
    }
  }
  double b[4]={1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
  double c[4]={0, 1.0/2.0, 1.0/2.0, 1};
  return nonDiagonalRK(claw, dt, solution, 4, Afm, b, c);
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
  Unp.scale(0.);
  Unp.axpy(*sol);
   
   if (_TransformNodalValue) _TransformNodalValue->apply(&Unp);
 
   K.scale(0.);
   K.axpy(Unp);

  dgResidual residual(claw);

  for(int j=0; j<nStages;j++){
    if(j){
      K.scale(A[j]*dt);
      K.axpy(*sol);
    }
    if (_TransformNodalValue) _TransformNodalValue->apply_Inverse(&K);
    if (_limiter) _limiter->apply(&K);
    residual.compute(*groups,K,resd);
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
  if (_limiter) _limiter->apply(&Unp);
  if (_TransformNodalValue) _TransformNodalValue->apply_Inverse(&Unp);
  sol->scale(0.);
  sol->axpy(Unp);
  return sol->norm();
}

double dgRungeKutta::nonDiagonalRK(const dgConservationLaw *claw,
  double dt, 
  dgDofContainer *solution, 
  int nStages, 
  fullMatrix<double> &A, //                          c | A
  double *b, // Standard Butcher tableau notation :___|__
  double *c  //                                       |b^T  
  )
{
  dgGroupCollection *groups=solution->getGroups();
  fullMatrix<double> residuEl, KEl;
  fullMatrix<double> iMassEl;

  int nbFields = claw->getNbFields();

  dgDofContainer **K;
  K=new dgDofContainer*[nStages];
  for(int i=0;i<nStages;i++){
    K[i]=new dgDofContainer(groups,nbFields);
    K[i]->scale(0.);
  }
  dgDofContainer Unp (groups,nbFields);
  dgDofContainer tmp (groups,nbFields);
  dgDofContainer resd(groups,nbFields);

  Unp.scale(0.0);
  Unp.axpy(*solution);
  dgResidual residual(claw);
  for(int i=0; i<nStages;i++){
    tmp.scale(0.0);
    tmp.axpy(*solution);
    for(int j=0;j<i;j++){
      if(fabs(A(i,j))>1e-12){
        tmp.axpy(*K[j],dt*A(i,j));
      }
    }
    if (_limiter) _limiter->apply(&tmp);
    residual.compute(*groups,tmp,resd);

    // Multiply the spatial residual by the inverse of the mass matrix
    for(int k=0; k < groups->getNbElementGroups(); k++) {
      dgGroupOfElements *group = groups->getElementGroup(k);
      int nbNodes = group->getNbNodes();
      for(int j=0;j<group->getNbElements();j++) {
        residuEl.setAsProxy(resd.getGroupProxy(k),j*nbFields,nbFields);
        KEl.setAsProxy(K[i]->getGroupProxy(k),j*nbFields,nbFields);
        iMassEl.setAsProxy(group->getInverseMassMatrix(),j*nbNodes,nbNodes);
        iMassEl.mult(residuEl,KEl);
      }
    }
    //Msg::Info("norm %d %0.16e",i,K[i]->norm());
    Unp.axpy(*K[i],dt*b[i]);
  }
  if (_limiter) _limiter->apply(&Unp);
  solution->scale(0.);
  solution->axpy(Unp);

  for(int i=0;i<nStages;i++){
    delete K[i];
  }
  delete []K;
  return solution->norm();
}

double dgRungeKutta::computeInvSpectralRadius(const dgConservationLaw *claw, 
					      dgDofContainer *solution){   
  double sr = 1.e22;
  dgGroupCollection *groups=solution->getGroups();
  for (int i=0;i<groups->getNbElementGroups();i++){
    std::vector<double> DTS;
    dgAlgorithm::computeElementaryTimeSteps(*claw, *(groups->getElementGroup(i)), solution->getGroupProxy(i), DTS);
    for (int k=0;k<DTS.size();k++) sr = std::min(sr,DTS[k]);
  }
  #ifdef HAVE_MPI
  double sr_min;
  MPI_Allreduce((void *)&sr, &sr_min, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);
  return sr_min;
  #else
  return sr;
  #endif
}


dgRungeKutta::dgRungeKutta():_limiter(NULL),_TransformNodalValue(NULL){}


#include "Bindings.h"

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
  cm = cb->addMethod("iterate33",&dgRungeKutta::iterate33);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing classical third order runge-kutta step of time step dt for the conservation law");
  cm = cb->addMethod("iterate44",&dgRungeKutta::iterate44);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing classical fourth order runge-kutta step of time step dt for the conservation law");
  cm = cb->addMethod("iterate44ThreeEight",&dgRungeKutta::iterate44ThreeEight);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing a fourth order runge-kutta (3/8 rule, not the classical one, see Hairer & Wanner book) step of time step dt for the conservation law");
  cm = cb->addMethod("iterate43SchlegelJCAM2009",&dgRungeKutta::iterate43SchlegelJCAM2009);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing a four stage third order runge-kutta (from Schlegel et al. Journal of Computational and Applied Mathematics, 2009) step of time step dt for the conservation law");
  cm = cb->addMethod("iterateRKFehlberg45",&dgRungeKutta::iterateRKFehlberg45);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing a six stage fifth order Runge-Kutta-Fehlberg step of time step dt for the conservation law");
  cm = cb->addMethod("setLimiter",&dgRungeKutta::setLimiter);
  cm->setArgNames("limiter",NULL);
  cm->setDescription("if a limiter is set, it is applied after each RK stage");
  cm = cb->addMethod("computeInvSpectralRadius",&dgRungeKutta::computeInvSpectralRadius);
  cm->setArgNames("law","solution",NULL);
  cm->setDescription("Returns the inverse of the spectral radius of L(U). Useful for computing stable explicit time step.");
 cm = cb->addMethod("setTransformNodalValue",&dgRungeKutta::setTransformNodalValue);
   cm->setArgNames("TransformNodalValue",NULL);
   cm->setDescription("if the Nodal values is transformed in first step of RK");

}

