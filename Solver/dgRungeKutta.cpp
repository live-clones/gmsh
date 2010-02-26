#include "dgRungeKutta.h"
#include "dgConservationLaw.h"
#include "dgDofContainer.h"
#include "dgLimiter.h"
#include "dgResidual.h"
#include "dgGroupOfElements.h"

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
  K.scale(0.);
  K.axpy(*sol);
  Unp.scale(0.);
  Unp.axpy(*sol);
  dgResidual residual(claw);

  for(int j=0; j<nStages;j++){
    if(j){
      K.scale(A[j]*dt);
      K.axpy(*sol);
    }

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
  sol->scale(0.);
  sol->axpy(Unp);
  return sol->norm();
}

double dgRungeKutta::nonDiagonalRK(const dgConservationLaw *claw,
  double dt, 
  dgDofContainer *solution, 
  int nStages, 
  fullMatrix<double>&A, //                                     c | A
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


double dgRungeKutta::iterate43Multirate(const dgConservationLaw *claw, double dt, dgDofContainer *solution){
  double A[4][4]={
     {0, 0, 0, 0},
     {1.0/2.0, 0, 0 ,0},
     {-1.0/6.0, 2.0/3.0, 0, 0},
     {1.0/3.0, -1.0/3.0, 1, 0}
  };
  double b[4]={1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
  double c[4]={0, 1.0/2.0, 1.0/2.0, 1};

  dgGroupCollection *groups=solution->getGroups();
  int dtMaxExponent=groups->getDtMaxExponent();
  int nSmallSteps=1;
  {
    int i=0;
    while(i<dtMaxExponent){
      nSmallSteps*=2;
      i++;
    }
  }

  int nbFields = claw->getNbFields();
  dgDofContainer **K;
  K=new dgDofContainer*[4];
  for(int i=0;i<4;i++){
    K[i]=new dgDofContainer(groups,nbFields);
    K[i]->scale(0.);
  }
  dgDofContainer Unp (groups,nbFields);
  dgDofContainer tmp (groups,nbFields);
  dgDofContainer resd(groups,nbFields);

// axpy for each group to build the right input vector for the residual
// At each stage, update the residual for a std::vector of groups, using residualForSomeGroups

// K0 for everyone
// K1 K2 K3 for the smallestDt group and its corresponding buffer
// smallestDt can be updated for the first smallset time step
// K4 for the smallest Dt and the buffer and K1 for the larger Dt
// K0 for the smallest Dt, K5 for the buffer, and K2 for the larger Dt
// K1 K2 K3 for the smallestDt and K6 K7 K8 for the buffer
// K4 for the smallest Dt and K9 for the buffer, K3 for the larger Dt
// update for everyone



/*
  for(int iStep=0;iStep<nSmallSteps;iStep++){
    for(int iGroup=0; iGroup < groups->getNbElementGroups(); iGroup++) {
      for(int iStage=0;iStage<4;iStage++){
        dgGroupOfElements *group=groups->getElementGroup(iGroup);
        int groupDtExponent=group->getMultirateExponent();
      }
      tmp.scale(0.0);
      tmp.axpy(*solution);
      for(int j=0;j<i;j++){
        if(fabs(A(i,j))>1e-12){
          tmp.axpy(*K[j],dt*A(i,j));
        }
      }
      if (_limiter) _limiter->apply(&tmp);
      dgAlgorithm::residual(*claw,*groups,tmp,resd);

      // Multiply the spatial residual by the inverse of the mass matrix
      int nbNodes = group->getNbNodes();
      for(int j=0;j<group->getNbElements();j++) {
        residuEl.setAsProxy(resd.getGroupProxy(k),j*nbFields,nbFields);
        KEl.setAsProxy(K[i]->getGroupProxy(k),j*nbFields,nbFields);
        iMassEl.setAsProxy(group->getInverseMassMatrix(),j*nbNodes,nbNodes);
        iMassEl.mult(residuEl,KEl);
      }
      }
      Unp.axpy(*K[i],dt*b[i]);
    }
  }
  */
/*
  int nStages=10;
  // Small step RK43
  double _A1[10][10]={
    {0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/4.0   ,0,         0,         0,         0,         0,         0,         0,         0,         0},
    {-1.0/12.0, 1.0/3.0,   0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/6.0,   -1.0/6.0,  1.0/2.0,   0,         0,         0,         0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         0,         0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         0,         0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/4.0,   0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         -1.0/12.0, 1.0/3.0,   0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/6.0,   -1.0/6.0,  1.0/2.0,   0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0, 0}
  };
  double b1[10]={1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0,1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0};
  double c1[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };

  // Big step RK43
  double _A2[10][10]={
    {0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {-1.0/6.0,  0,         0,         0,         2.0/3.0,   0,         0,         0,         0,         0},
    {1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
    {1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
    {1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
    {1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
  };
  double b2[10]={1.0/6.0, 0 , 0 , 0 , 1.0/3.0,1.0/3.0, 0 , 0 , 0 , 1.0/6.0};
  double c2[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };
  fullMatrix<double> A1(10,10);
  fullMatrix<double> A2(10,10);
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      A1(i,j)=_A1[i][j];
      A2(i,j)=_A2[i][j];
    }
  }


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
  for(int i=0; i<nStages;i++){
    tmp.scale(0.0);
    tmp.axpy(*solution);
    for(int j=0;j<i;j++){
      if(fabs(A(i,j))>1e-12){
        tmp.axpy(*K[j],dt*A(i,j));
      }
    }
    if (_limiter) _limiter->apply(&tmp);
    dgAlgorithm::residual(*claw,*groups,tmp,resd);

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
*/
}


dgRungeKutta::dgRungeKutta():_limiter(NULL) {}


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
  cm = cb->addMethod("iterate43Multirate",&dgRungeKutta::iterate43Multirate);
  cm->setArgNames("law","dt","solution",NULL);
  cm->setDescription("update solution by doing a multirate RK43 (from Schlegel et al. Journal of Computational and Applied Mathematics, 2009) step of base time step dt for the conservation law");
  cm = cb->addMethod("setLimiter",&dgRungeKutta::setLimiter);
  cm->setArgNames("limiter",NULL);
  cm->setDescription("if a limiter is set, it is applied after each RK stage");
}

dgRungeKuttaMultirate::dgRungeKuttaMultirate(dgGroupCollection* gc,dgConservationLaw *law){
  _law=law;
  _residualVolume=new dgResidualVolume(*_law);
  _residualInterface=new dgResidualInterface(*_law);
  _K=new dgDofContainer*[10];
  for(int i=0;i>10;i++){
    _K[i]=new dgDofContainer(gc,_law->getNbFields());
    _K[i]->setAll(0.0);
  }
  _currentInput=new dgDofContainer(gc,_law->getNbFields());
  _currentInput->setAll(0.0);
  _minExponent=INT_MAX;
  _maxExponent=0;
  for(int iGroup=0;iGroup<gc->getNbElementGroups();iGroup++){
    dgGroupOfElements *ge=gc->getElementGroup(iGroup);
    _minExponent=std::min(_minExponent,ge->getMultirateExponent());
    _maxExponent=std::max(_maxExponent,ge->getMultirateExponent());
    _innerBufferGroupsOfElements.resize(_maxExponent+1);
    _outerBufferGroupsOfElements.resize(_maxExponent+1);
    _bulkGroupsOfElements.resize(_maxExponent+1);
    if(ge->getIsInnerMultirateBuffer()){
      _innerBufferGroupsOfElements[ge->getMultirateExponent()].first.push_back(ge);
    }
    else if(ge->getIsOuterMultirateBuffer()){
      _outerBufferGroupsOfElements[ge->getMultirateExponent()].first.push_back(ge);
    }
    else{
      _bulkGroupsOfElements[ge->getMultirateExponent()].first.push_back(ge);
    }
  }
  for(int iGroup=0;iGroup<gc->getNbFaceGroups();iGroup++){
    dgGroupOfFaces *gf=gc->getFaceGroup(iGroup);
    const dgGroupOfElements *ge[2];
    ge[0]=&gf->getGroupLeft();
    ge[1]=&gf->getGroupRight();
    if(ge[0]==ge[1]){
      _bulkGroupsOfElements[ge[0]->getMultirateExponent()].second.push_back(gf);
    }
    for(int i=0;i<2;i++){
      if(ge[i]->getIsInnerMultirateBuffer()){
        _innerBufferGroupsOfElements[ge[i]->getMultirateExponent()].second.push_back(gf);
      }
      else if(ge[i]->getIsOuterMultirateBuffer()){
        _outerBufferGroupsOfElements[ge[i]->getMultirateExponent()].second.push_back(gf);
      }else{
        _bulkGroupsOfElements[ge[i]->getMultirateExponent()].second.push_back(gf);
      }
    }
  }
}
dgRungeKuttaMultirate::~dgRungeKuttaMultirate(){
  for(int i=0;i>10;i++){
    delete _K[i];
  }
  delete []_K;
}

void dgRungeKuttaMultirate::computeK(int iK,int exponent,bool isBuffer){
  double _A[4][4]={
     {0, 0, 0, 0},
     {1.0/2.0, 0, 0 ,0},
     {-1.0/6.0, 2.0/3.0, 0, 0},
     {1.0/3.0, -1.0/3.0, 1, 0}
  };
  double _AInner[10][10]={
    {0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/4.0   ,0,         0,         0,         0,         0,         0,         0,         0,         0},
    {-1.0/12.0, 1.0/3.0,   0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/6.0,   -1.0/6.0,  1.0/2.0,   0,         0,         0,         0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         0,         0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         0,         0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/4.0,   0,         0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         -1.0/12.0, 1.0/3.0,   0,         0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/6.0,   -1.0/6.0,  1.0/2.0,   0,         0},
    {1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0, 0}
  };
  double bInner[10]={1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0,1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0};
  double cInner[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };

  // Big step RK43
  double _AOuter[10][10]={
    {0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
    {-1.0/6.0,  0,         0,         0,         2.0/3.0,   0,         0,         0,         0,         0},
    {1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
    {1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
    {1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
    {1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
  };
  double bOuter[10]={1.0/6.0, 0 , 0 , 0 , 1.0/3.0,1.0/3.0, 0 , 0 , 0 , 1.0/6.0};
  double cOuter[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };
  if(exponent>_maxExponent)
    return;
  // compute K[iK] for this exponent and buffer
  _currentInput->scale(0.0);
  if(isBuffer){
    std::vector<dgGroupOfElements *>gVi=_innerBufferGroupsOfElements[exponent].first;
    std::vector<dgGroupOfElements *>gVo=_outerBufferGroupsOfElements[exponent].first;
    _currentInput->axpy(gVi,*_solution,1.0);
    _currentInput->axpy(gVo,*_solution,1.0);
    for(int i=0;i<iK;i++){
      _currentInput->axpy(gVi,*_K[i],_AInner[iK][i]);
      _currentInput->axpy(gVo,*_K[i],_AOuter[iK][i]);
    }
  }
  else{
    std::vector<dgGroupOfElements *>gV=_bulkGroupsOfElements[exponent].first;
    _currentInput->axpy(gV,*_solution,1.0);
    for(int i=0;i<iK;i++){
      _currentInput->axpy(gV,*_K[i],_A[iK][i]);
    }
  }
  if(!isBuffer){
    switch(iK){
      case 0:
        for(int i=0;i<4;i++){
          computeK(i,exponent+1,true);
        }
        break;
      case 1:
        computeK(4,exponent+1,true);
        break;
      case 2:
        for(int i=5;i<9;i++){
          computeK(i,exponent+1,true);
        }
        break;
      case 3:
        computeK(9,exponent+1,true);
        break;
    }
  }
  else{
    if( (iK%5)<4 ){
      computeK(iK%5,exponent+1,false);
    }
  }
  if( (iK==3 && !isBuffer) || (iK==9 && isBuffer) ){
    updateSolution(exponent,isBuffer);
  }
}
void dgRungeKuttaMultirate::updateSolution(int exponent,bool isBuffer){}
void dgRungeKuttaMultirate::computeResidual(int exponent,bool isBuffer,dgDofContainer *solution, dgDofContainer *residual){
  if(isBuffer){
    std::vector<dgGroupOfElements *>*vei=&_innerBufferGroupsOfElements[exponent].first;
    std::vector<dgGroupOfElements *>*veo=&_outerBufferGroupsOfElements[exponent].first;
    for(int i=0;i<vei->size();i++){
      _residualVolume->computeAndMap1Group(*(*vei)[i], *solution, *residual);
    }
    for(int i=0;i<veo->size();i++){
      _residualVolume->computeAndMap1Group(*(*veo)[i], *solution, *residual);
    }
    std::vector<dgGroupOfFaces *>* vfi=&_innerBufferGroupsOfElements[exponent].second;
    std::vector<dgGroupOfFaces *>* vfo=&_outerBufferGroupsOfElements[exponent].second;
    std::set<dgGroupOfFaces *>gOFSet;
    gOFSet.insert(vfo->begin(),vfo->end());
    for(std::set<dgGroupOfFaces *>::iterator it=gOFSet.begin();it!=gOFSet.end();it++){
      dgGroupOfFaces *faces=*it;
      const dgGroupOfElements *gL=&faces->getGroupLeft();
      const dgGroupOfElements *gR=&faces->getGroupRight();
      fullMatrix<double> solInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
      fullMatrix<double> residuInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
      faces->mapToInterface(_law->getNbFields(), solution->getGroupProxy(gL), solution->getGroupProxy(gR), solInterface);
      _residualInterface->compute1Group(*faces,solInterface,solution->getGroupProxy(gL), solution->getGroupProxy(gR),residuInterface);
      if(gL->getMultirateExponent()==exponent && gL->getIsMultirateBuffer())
        faces->mapLeftFromInterface(_law->getNbFields(), residuInterface,residual->getGroupProxy(gL));
      if(gL->getMultirateExponent()==exponent && gL->getIsMultirateBuffer())
        faces->mapRightFromInterface(_law->getNbFields(), residuInterface,residual->getGroupProxy(gR));
    }
  }
  else{
    std::vector<dgGroupOfElements *> *ve=&_bulkGroupsOfElements[exponent].first;
    for(int i=0;i<ve->size();i++){
      _residualVolume->computeAndMap1Group(*(*ve)[i], *solution, *residual);
    }
    std::vector<dgGroupOfFaces *> *vf=&_bulkGroupsOfElements[exponent].second;
    for(int i=0;i<vf->size();i++){
      dgGroupOfFaces *faces=(*vf)[i];
      const dgGroupOfElements *gL=&faces->getGroupLeft();
      const dgGroupOfElements *gR=&faces->getGroupRight();
      fullMatrix<double> solInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
      fullMatrix<double> residuInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
      faces->mapToInterface(_law->getNbFields(), solution->getGroupProxy(gL), solution->getGroupProxy(gR), solInterface);
      _residualInterface->compute1Group(*faces,solInterface,solution->getGroupProxy(gL), solution->getGroupProxy(gR),residuInterface);
      if(gL->getMultirateExponent()==exponent && !gL->getIsMultirateBuffer())
        faces->mapLeftFromInterface(_law->getNbFields(), residuInterface,residual->getGroupProxy(gL));
      if(gL->getMultirateExponent()==exponent && !gL->getIsMultirateBuffer())
        faces->mapRightFromInterface(_law->getNbFields(), residuInterface,residual->getGroupProxy(gR));
    }
  }
}

double dgRungeKuttaMultirate::iterate(double dt, dgDofContainer *solution){
  _solution=solution;
  computeK(0,0,false);
  computeK(1,0,false);
  computeK(2,0,false);
  computeK(3,0,false);
  updateSolution(0,false);
  
  return solution->norm();
}

void dgRungeKuttaMultirate::registerBindings(binding *b) {
  classBinding *cb = b->addClass<dgRungeKuttaMultirate>("dgRungeKuttaMultirate");
  cb->setDescription("Multirate explicit Runge-Kutta");
  methodBinding *cm;
  cm = cb->setConstructor<dgRungeKuttaMultirate,dgGroupCollection *,dgConservationLaw*>();
  cm->setArgNames("groupCollection","law",NULL);
  cm->setDescription("A new multirate explicit runge kutta, pass parameters to the iterate function");
  cm = cb->addMethod("iterate",&dgRungeKuttaMultirate::iterate);
  cm->setArgNames("dt","solution",NULL);
  cm->setDescription("update solution by doing a multirate RK43 (from Schlegel et al. Journal of Computational and Applied Mathematics, 2009) step of base time step dt for the conservation law");
  cb->setParentClass<dgRungeKutta>();
}
