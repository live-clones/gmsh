#include "dgRungeKuttaMultirate.h"
#include "Bindings.h"
#include "dgResidual.h"
#include "dgConservationLaw.h"
#include "dgDofContainer.h"
#include "dgGroupOfElements.h"
#include <algorithm>
#include <limits.h>
#include <stdio.h>
//#define MULTIRATEVERBOSE

//Butcher tables for RK43 (Schlegel)
static double A43[4][4]={
     {0, 0, 0, 0},
     {1.0/2.0, 0, 0 ,0},
     {-1.0/6.0, 2.0/3.0, 0, 0},
     {1.0/3.0, -1.0/3.0, 1, 0}
  };
static double AInner43[10][10]={
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

  // Big step RK43
static double AOuter43[10][10]={
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

static double b43[4]={1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
static double c43[4]={0, 1.0/2.0, 1.0/2.0, 1};
static double bInner43[10]={1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0,1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0};
static double cInner43[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };
static double bOuter43[10]={1.0/6.0, 0 , 0 , 0 , 1.0/3.0,1.0/3.0, 0 , 0 , 0 , 1.0/6.0};
static double cOuter43[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };

// Butcher tables for Multirate RK22 (Constantinescu)
static double A22[2][2]={
		{0, 0},
		{1.0, 0}
	};
	// Small step RK22
static double AInner22[4][4]={
		{0,         0,         0,         0}, 
		{1.0/2.0,   0, 				 0,         0},
		{1.0/4.0,  1.0/4.0,    0,         0},
		{1.0/4.0,  1.0/4.0,   1.0/2.0,    0}
	};
	
	// Big step RK22
static double AOuter22[4][4]={
		{0,         0,         0,         0}, 
		{1.0,   		0, 				 0,         0},
		{0,  			  0,         0,         0},
		{0,  				0,   		 1.0,    			0}
	};
static double b22[2]={1.0/2.0,  1.0/2.0};
static double c22[2]={0, 1.0};
static double bInner22[4]={1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0};
static double cInner22[4]={0,  1.0/2.0, 1.0/2.0, 1.0};
static double bOuter22[4]={1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0};
static double cOuter22[4]={0, 1.0, 0, 1.0};

dgRungeKuttaMultirate::dgRungeKuttaMultirate(dgGroupCollection* gc,dgConservationLaw *law, int nStages){
  _law=law;
  _residualVolume=new dgResidualVolume(*_law);
  _residualInterface=new dgResidualInterface(*_law);
  _gc=gc;
  _K=new dgDofContainer*[nStages];
  for(int i=0;i<nStages;i++){
    _K[i]=new dgDofContainer(gc,_law->getNbFields());
    _K[i]->setAll(0.0);
  }
  _currentInput=new dgDofContainer(gc,_law->getNbFields());
  _currentInput->setAll(0.0);
  _residual=new dgDofContainer(gc,_law->getNbFields());
  _residual->setAll(0.0);
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
    for(int i=0;i<gf->getNbGroupOfConnections();i++){
      const dgGroupOfElements *ge = &gf->getGroupOfConnections(i).getGroupOfElements();
      if(ge->getIsInnerMultirateBuffer()){
        _innerBufferGroupsOfElements[ge->getMultirateExponent()].second.push_back(gf);
      }
      else if(ge->getIsOuterMultirateBuffer()){
        _outerBufferGroupsOfElements[ge->getMultirateExponent()].second.push_back(gf);
      }else{
        _bulkGroupsOfElements[ge->getMultirateExponent()].second.push_back(gf);
      }
    }
  }
  // Removing duplicate entries
  for(int iExp=0;iExp<=_maxExponent;iExp++){
    std::vector<dgGroupOfFaces*>*v[3];
    v[0]=&_innerBufferGroupsOfElements[iExp].second;
    v[1]=&_outerBufferGroupsOfElements[iExp].second;
    v[2]=&_bulkGroupsOfElements[iExp].second;
    for(int i=0;i<3;i++){
      sort(v[i]->begin(),v[i]->end());
      v[i]->erase(unique(v[i]->begin(),v[i]->end()),v[i]->end());
    }
  }
}
dgRungeKuttaMultirate::~dgRungeKuttaMultirate(){
  for(int i=0;i>10;i++){
    delete _K[i];
  }
  delete []_K;
  delete _residual;
  delete _currentInput;
  delete _residualVolume;
  delete _residualInterface;
}

void dgRungeKuttaMultirate::computeK(int iK,int exponent,bool isBuffer){
#ifdef MULTIRATEVERBOSE
  for(int i=0;i<exponent;i++)
    printf("\t");
  printf("Exponent %d, %s, compute K%d\n",exponent,isBuffer?"    Buffer":"Not buffer",iK);
#endif
  if(isBuffer){
    std::vector<dgGroupOfElements *>&vei=_innerBufferGroupsOfElements[exponent].first;
    std::vector<dgGroupOfElements *>&veo=_outerBufferGroupsOfElements[exponent].first;
    _residual->scale(vei,0.0);
    _residual->scale(veo,0.0);
    for(int i=0;i<vei.size();i++){
      _residualVolume->computeAndMap1Group(*vei[i], *_currentInput, *_residual);
    }
    for(int i=0;i<veo.size();i++){
      _residualVolume->computeAndMap1Group(*veo[i], *_currentInput, *_residual);
    }
    std::vector<dgGroupOfFaces *>& vfi=_innerBufferGroupsOfElements[exponent].second;
    std::vector<dgGroupOfFaces *>& vfo=_outerBufferGroupsOfElements[exponent].second;
    std::set<dgGroupOfFaces *>gOFSet;
    gOFSet.insert(vfo.begin(),vfo.end());
    gOFSet.insert(vfi.begin(),vfi.end());
    for(std::set<dgGroupOfFaces *>::iterator it=gOFSet.begin();it!=gOFSet.end();it++){
      dgGroupOfFaces *faces=*it;
      if(faces->getNbGroupOfConnections()==1){
        _residualInterface->computeAndMap1Group(*faces,*_currentInput,*_residual);
      }
      else{
        const dgGroupOfElements *gL = &faces->getGroupOfConnections(0).getGroupOfElements();
        const dgGroupOfElements *gR = &faces->getGroupOfConnections(1).getGroupOfElements();
        fullMatrix<double> solInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
        fullMatrix<double> residuInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
        std::vector<const fullMatrix<double>*> proxies(2);
        proxies[0] = &_currentInput->getGroupProxy(gL);
        proxies[1] = &_currentInput->getGroupProxy(gR);
        faces->mapToInterface(_law->getNbFields(), proxies, solInterface);
        _residualInterface->compute1Group(*faces,solInterface, proxies, residuInterface);
        if(gL->getMultirateExponent()==exponent && gL->getIsMultirateBuffer()){
          faces->mapLeftFromInterface(_law->getNbFields(), residuInterface,_residual->getGroupProxy(gL));
        }
        if(gR->getMultirateExponent()==exponent && gR->getIsMultirateBuffer()){
          faces->mapRightFromInterface(_law->getNbFields(), residuInterface,_residual->getGroupProxy(gR));
        }
      }
    }
    fullMatrix<double> iMassEl, KEl,residuEl;
    for(int iGroup=0;iGroup<vei.size();iGroup++){
      dgGroupOfElements *group=vei[iGroup];
      int nbNodes = group->getNbNodes();
      for(int iElem=0;iElem<group->getNbElements();iElem++){
        residuEl.setAsProxy(_residual->getGroupProxy(group),iElem*_law->getNbFields(),_law->getNbFields());
        KEl.setAsProxy(_K[iK]->getGroupProxy(group),iElem*_law->getNbFields(),_law->getNbFields());
        iMassEl.setAsProxy(group->getInverseMassMatrix(),iElem*nbNodes,nbNodes);
        iMassEl.mult(residuEl,KEl);
      }
    }
    for(int iGroup=0;iGroup<veo.size();iGroup++){
      dgGroupOfElements *group=veo[iGroup];
      int nbNodes = group->getNbNodes();
      for(int iElem=0;iElem<group->getNbElements();iElem++){
        residuEl.setAsProxy(_residual->getGroupProxy(group),iElem*_law->getNbFields(),_law->getNbFields());
        KEl.setAsProxy(_K[iK]->getGroupProxy(group),iElem*_law->getNbFields(),_law->getNbFields());
        iMassEl.setAsProxy(group->getInverseMassMatrix(),iElem*nbNodes,nbNodes);
        iMassEl.mult(residuEl,KEl);
      }
    }
  }
  else{
    std::vector<dgGroupOfElements *> &ve=_bulkGroupsOfElements[exponent].first;
    _residual->scale(ve,0.0);
    for(int i=0;i<ve.size();i++){
      _residualVolume->computeAndMap1Group(*ve[i], *_currentInput, *_residual);
    }
    std::vector<dgGroupOfFaces *> &vf=_bulkGroupsOfElements[exponent].second;
    for(int i=0;i<vf.size();i++){
      dgGroupOfFaces *faces=vf[i];
      if(faces->getNbGroupOfConnections()==1){
        _residualInterface->computeAndMap1Group(*faces,*_currentInput,*_residual);
      }
      else{
        const dgGroupOfElements *gL = &faces->getGroupOfConnections(0).getGroupOfElements();
        const dgGroupOfElements *gR = &faces->getGroupOfConnections(1).getGroupOfElements();
        fullMatrix<double> solInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
        fullMatrix<double> residuInterface(faces->getNbNodes(),faces->getNbElements()*2*_law->getNbFields());
        std::vector<const fullMatrix<double>*> proxies(2);
        proxies[0] = &_currentInput->getGroupProxy(gL);
        proxies[1] = &_currentInput->getGroupProxy(gR);
        faces->mapToInterface(_law->getNbFields(), proxies, solInterface);
        _residualInterface->compute1Group(*faces,solInterface, proxies, residuInterface);
        if(gL->getMultirateExponent()==exponent && !gL->getIsMultirateBuffer()){
          faces->mapLeftFromInterface(_law->getNbFields(), residuInterface,_residual->getGroupProxy(gL));
        }
        if(gR->getMultirateExponent()==exponent && !gR->getIsMultirateBuffer()){
          faces->mapRightFromInterface(_law->getNbFields(), residuInterface,_residual->getGroupProxy(gR));
        }
      }
    }
    fullMatrix<double> iMassEl, KEl,residuEl;
    for(int iGroup=0;iGroup<ve.size();iGroup++){
      dgGroupOfElements *group=ve[iGroup];
      int nbNodes = group->getNbNodes();
      for(int iElem=0;iElem<group->getNbElements();iElem++){
        residuEl.setAsProxy(_residual->getGroupProxy(group),iElem*_law->getNbFields(),_law->getNbFields());
        KEl.setAsProxy(_K[iK]->getGroupProxy(group),iElem*_law->getNbFields(),_law->getNbFields());
        iMassEl.setAsProxy(group->getInverseMassMatrix(),iElem*nbNodes,nbNodes);
        iMassEl.mult(residuEl,KEl);
      }
    }
  }
}

void dgRungeKuttaMultirate::registerBindings(binding *b) {
/*
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
  */
}

dgRungeKuttaMultirate43::dgRungeKuttaMultirate43(dgGroupCollection *gc,dgConservationLaw* law):dgRungeKuttaMultirate(gc,law,10){}


double dgRungeKuttaMultirate43::iterate(double dt, dgDofContainer *solution){
  _solution=solution;
  _dt=dt;
  computeInputForK(0,0,false);
  computeInputForK(1,0,false);
  computeInputForK(2,0,false);
  computeInputForK(3,0,false);
  
  return solution->norm();
}

void dgRungeKuttaMultirate43::computeInputForK(int iK,int exponent,bool isBuffer){
  if(exponent>_maxExponent){
    return;
  }
#ifdef MULTIRATEVERBOSE
  for(int i=0;i<exponent;i++)
    printf("\t");
  printf("Exponent %d, %s, input   K%d\n",exponent,isBuffer?"    Buffer":"Not buffer",iK);
#endif

  double localDt=_dt/pow(2.0,(double)exponent);

  if(!isBuffer){
    std::vector<dgGroupOfElements *> &gV=_bulkGroupsOfElements[exponent].first;
    _currentInput->scale(gV,0.0);
    _currentInput->axpy(gV,*_solution,1.0);
    for(int i=0;i<iK;i++){
      if(A43[iK][i]!=0.0){
        _currentInput->axpy(gV,*_K[i],A43[iK][i]*localDt);
      }
    }
  }
  else{
    std::vector<dgGroupOfElements *>&gVi=_innerBufferGroupsOfElements[exponent].first;
    std::vector<dgGroupOfElements *>&gVo=_outerBufferGroupsOfElements[exponent].first;
    _currentInput->scale(gVi,0.0);
    _currentInput->scale(gVo,0.0);
    _currentInput->axpy(gVi,*_solution,1.0);
    _currentInput->axpy(gVo,*_solution,1.0);
    for(int i=0;i<iK;i++){
      if(AInner43[iK][i]!=0.0)
        _currentInput->axpy(gVi,*_K[i],AInner43[iK][i]*localDt*2);
      if(AOuter43[iK][i]!=0.0)
        _currentInput->axpy(gVo,*_K[i],AOuter43[iK][i]*localDt*2);
    }
    /*
    NOT NEEDED
    // We need to update input for the neighboring elements with bigger time step.
    // if there is no corresponding K to be computed
    if( (iK>0 && iK<4) || (iK>5 && iK<9) ){
      std::vector<dgGroupOfElements *>&gVbigger=_bulkGroupsOfElements[exponent-1].first;
      _currentInput->scale(gVbigger,0.0);
      _currentInput->axpy(gVbigger,*_solution,1.0);
      int idOuter2Bulk[10]={0,0,0,0,1,2,2,2,2,3};
      for(int i=0;i<iK;i++){
        if(AOuter43[iK][i]!=0.0){
          // ON DIRAIT QUE CETTE LIGNE DE CODE NE FAIT RIEN ...
          _currentInput->axpy(gVbigger,*_K[idOuter2Bulk[i]],AOuter43[iK][i]*localDt*2);
        }
      }
      std::vector<dgGroupOfElements *>&gViBigger=_innerBufferGroupsOfElements[exponent-1].first;
      _currentInput->scale(gViBigger,0.0);
      _currentInput->axpy(gViBigger,*_solution,1.0);
      // shift
      int s=0;
      if(upperLeveliK>=5){
        for(int i=0;i<4;i++){
          _currentInput->axpy(gViBigger,*_K[i],b[i]*localDt*2);
        }
        s+=5;
      }
      for(int i=0;i<iK;i++){
        if(AOuter43[iK][i]!=0.0){
          _currentInput->axpy(gViBigger,*_K[idOuter2Bulk[i]+s],AOuter43[iK][i]*localDt*2);
        }
      }
    }
    */
  }

  if(!isBuffer){
    switch(iK){
      case 0:
        computeInputForK(0,exponent+1,true);
        break;
      case 1:
        computeInputForK(4,exponent+1,true);
        break;
      case 2:
        computeInputForK(5,exponent+1,true);
        break;
      case 3:
        computeInputForK(9,exponent+1,true);
        break;
    }
  }
  else{
    if( (iK%5)<4 ){
      computeInputForK(iK%5,exponent,false);
    }
  }
  if(exponent==0){
    computeK(iK,exponent,false);
    if(iK==3)
      updateSolution(exponent,false);
    switch(iK){
      case 0:
        for(int i=1;i<4;i++){
          computeInputForK(i,exponent+1,true);
        }
        break;
      case 2:
        for(int i=6;i<9;i++){
          computeInputForK(i,exponent+1,true);
        }
        break;
    }
  }
  if(isBuffer && exponent>0){
    if( (iK%5)<4)
      computeK(iK%5,exponent,false);
    computeK(iK,exponent,true);
    if( (iK%5)==3)
      updateSolution(exponent,false);
    if(iK==9)
      updateSolution(exponent,true);
    switch(iK%5){
      case 0:
        for(int i=1;i<4;i++){
          computeInputForK(i,exponent+1,true);
        }
        break;
      case 2:
        for(int i=6;i<9;i++){
          computeInputForK(i,exponent+1,true);
        }
        break;
    }
  }
}

void dgRungeKuttaMultirate43::updateSolution(int exponent,bool isBuffer){

#ifdef MULTIRATEVERBOSE
  for(int i=0;i<exponent;i++)
    printf("\t");
  printf("Updating solution at level %d %s\n",exponent,isBuffer?"Buffer":"Bulk");
#endif
  double localDt=_dt/pow(2.0,(double)exponent);
  if(isBuffer){
    std::vector<dgGroupOfElements *>&gVi=_innerBufferGroupsOfElements[exponent].first;
    std::vector<dgGroupOfElements *>&gVo=_outerBufferGroupsOfElements[exponent].first;
    for(int i=0;i<10;i++){
      if(bInner43[i]!=0.0)
        _solution->axpy(gVi,*_K[i],bInner43[i]*localDt*2);
      if(bOuter43[i]!=0.0)
        _solution->axpy(gVo,*_K[i],bOuter43[i]*localDt*2);
    }
  }
  else{
    std::vector<dgGroupOfElements *>&gV=_bulkGroupsOfElements[exponent].first;
    for(int i=0;i<4;i++){
      if(b43[i]!=0.0)
        _solution->axpy(gV,*_K[i],b43[i]*localDt);
    }
    _currentInput->scale(gV,0.0);
    _currentInput->axpy(gV,*_solution,1.0);
  }
}


void dgRungeKuttaMultirate43::registerBindings(binding *b) {
  classBinding *cb = b->addClass<dgRungeKuttaMultirate43>("dgRungeKuttaMultirate43");
  cb->setDescription("Multirate explicit Runge-Kutta with SchlegelJCAM2009 4 stages 3rd order method");
  methodBinding *cm;
  cm = cb->setConstructor<dgRungeKuttaMultirate43,dgGroupCollection *,dgConservationLaw*>();
  cm->setArgNames("groupCollection","law",NULL);
  cm->setDescription("A new multirate explicit runge kutta, pass parameters to the iterate function");
  cm = cb->addMethod("iterate",&dgRungeKuttaMultirate43::iterate);
  cm->setArgNames("dt","solution",NULL);
  cm->setDescription("update the solution by doing a multirate RK43 (from Schlegel et al. Journal of Computational and Applied Mathematics, 2009) step of base time step dt for the conservation law");
}

dgRungeKuttaMultirate22::dgRungeKuttaMultirate22(dgGroupCollection *gc,dgConservationLaw* law):dgRungeKuttaMultirate(gc,law,4){}


double dgRungeKuttaMultirate22::iterate(double dt, dgDofContainer *solution){
	_solution=solution;
	_dt=dt;
	computeInputForK(0,0,false,-1);
	computeInputForK(1,0,false,-1);
	
	return solution->norm();
}

void dgRungeKuttaMultirate22::computeInputForK(int iK,int exponent,bool isBuffer,int upperLeveliK){
	if(exponent>_maxExponent){
		return;
	}
#ifdef MULTIRATEVERBOSE
  for(int i=0;i<exponent;i++)
    printf("\t");
  printf("Exponent %d, %s, input   K%d\n",exponent,isBuffer?"    Buffer":"Not buffer",iK);
#endif
	double localDt=_dt/pow(2.0,(double)exponent);
	// compute K[iK] for this exponent and buffer
	
	if(!isBuffer){
		std::vector<dgGroupOfElements *> &gV=_bulkGroupsOfElements[exponent].first;
		_currentInput->scale(gV,0.0);
		_currentInput->axpy(gV,*_solution,1.0);
		for(int i=0;i<iK;i++){
			if(A22[iK][i]!=0.0){
				_currentInput->axpy(gV,*_K[i],A22[iK][i]*localDt);
			}
		}
	}
	else{
		std::vector<dgGroupOfElements *>&gVi=_innerBufferGroupsOfElements[exponent].first;
		std::vector<dgGroupOfElements *>&gVo=_outerBufferGroupsOfElements[exponent].first;
		_currentInput->scale(gVi,0.0);
		_currentInput->scale(gVo,0.0);
		_currentInput->axpy(gVi,*_solution,1.0);
		_currentInput->axpy(gVo,*_solution,1.0);
		for(int i=0;i<iK;i++){
			if(AInner22[iK][i]!=0.0){
				_currentInput->axpy(gVi,*_K[i],AInner22[iK][i]*localDt*2);}
			if(AOuter22[iK][i]!=0.0)
				_currentInput->axpy(gVo,*_K[i],AOuter22[iK][i]*localDt*2);
		}
    // We need to update input for the neighboring elements with bigger time step.
    // if there is no corresponding K to be computed
    if( (iK>0 && iK<3) ){
      std::vector<dgGroupOfElements *>&gVbigger=_bulkGroupsOfElements[exponent-1].first;
      _currentInput->scale(gVbigger,0.0);
      _currentInput->axpy(gVbigger,*_solution,1.0);
      int idOuter2Bulk[10]={0,0,0,1};
      for(int i=0;i<iK;i++){
        if(AOuter22[iK][i]!=0.0){
          _currentInput->axpy(gVbigger,*_K[idOuter2Bulk[i]],AOuter22[iK][i]*localDt*2);
        }
      }
      std::vector<dgGroupOfElements *>&gViBigger=_innerBufferGroupsOfElements[exponent-1].first;
      _currentInput->scale(gViBigger,0.0);
      _currentInput->axpy(gViBigger,*_solution,1.0);
      // shift
      int s=0;
      if(upperLeveliK>=2){
        for(int i=0;i<2;i++){
          _currentInput->axpy(gViBigger,*_K[i],b22[i]*localDt*2);
        }
        s+=2;
      }
      for(int i=0;i<iK;i++){
        if(AOuter22[iK][i]!=0.0){
          _currentInput->axpy(gViBigger,*_K[idOuter2Bulk[i]+s],AOuter22[iK][i]*localDt*2);
        }
      }
    }
	}
	
	if(!isBuffer){
		switch(iK){
			case 0:
				computeInputForK(0,exponent+1,true,iK);
				break;
			case 1:
				computeInputForK(3,exponent+1,true,iK);
				break;
		}
	}
	else{
		computeInputForK(iK%2,exponent,false,iK);
	}
	
	if(exponent==0){
		computeK(iK, exponent, false);
		switch(iK){
			case 0:
				for(int i=1;i<3;i++){
					computeInputForK(i,exponent+1,true,iK);
				}
				break;
			case 1:
				updateSolution(exponent, false);
				break;
		}
	}

	if(isBuffer && exponent>0){
		computeK(iK%2, exponent, false);
		computeK(iK, exponent, true);
		if(iK%2==1)
			updateSolution(exponent, false);
		if(iK==3)
			updateSolution(exponent, true);
    switch(iK%2){
      case 0:
        for(int i=1;i<3;i++){
          computeInputForK(i, exponent+1, true,iK);
        }
        break;
    }
 }
}

void dgRungeKuttaMultirate22::updateSolution(int exponent,bool isBuffer){
#ifdef MULTIRATEVERBOSE
  for(int i=0;i<exponent;i++)
    printf("\t");
  printf("Updating solution at level %d %s\n",exponent,isBuffer?"Buffer":"Bulk");
#endif
	double localDt=_dt/pow(2.0,(double)exponent);
	if(isBuffer){
		std::vector<dgGroupOfElements *>&gVi=_innerBufferGroupsOfElements[exponent].first;
		std::vector<dgGroupOfElements *>&gVo=_outerBufferGroupsOfElements[exponent].first;
		for(int i=0;i<4;i++){
			if(bInner22[i]!=0.0)
				_solution->axpy(gVi,*_K[i],bInner22[i]*localDt*2);
			if(bOuter22[i]!=0.0)
				_solution->axpy(gVo,*_K[i],bOuter22[i]*localDt*2);
		}
	}
	else{
		std::vector<dgGroupOfElements *>&gV=_bulkGroupsOfElements[exponent].first;
		for(int i=0;i<2;i++){
			if(b22[i]!=0.0)
				_solution->axpy(gV,*_K[i],b22[i]*localDt);
		}
	}
}

void dgRungeKuttaMultirate22::registerBindings(binding *b) {
	classBinding *cb = b->addClass<dgRungeKuttaMultirate22>("dgRungeKuttaMultirate22");
	cb->setDescription("Multirate explicit Runge-Kutta with Constantinescu 2 stages 2nd order method");
	methodBinding *cm;
	cm = cb->setConstructor<dgRungeKuttaMultirate22,dgGroupCollection *,dgConservationLaw*>();
	cm->setArgNames("groupCollection","law",NULL);
	cm->setDescription("A new multirate explicit runge kutta, pass parameters to the iterate function");
	cm = cb->addMethod("iterate",&dgRungeKuttaMultirate22::iterate);
	cm->setArgNames("dt","solution",NULL);
	cm->setDescription("update the solution by doing a multirate RK2a (from Constantinescu and Sandu,  'Update on Multirate Timestepping Methods for Hyperbolic Conservation Laws', Computer Sciance Technical Report,  2007) step of base time step dt for the conservation law");
}
