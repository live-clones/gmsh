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

dgRungeKuttaMultirate::dgRungeKuttaMultirate(dgGroupCollection* gc,dgConservationLaw *law){
  _law=law;
  _residualVolume=new dgResidualVolume(*_law);
  _residualInterface=new dgResidualInterface(*_law);
  _gc=gc;
	_init=false;
}
void dgRungeKuttaMultirate::initialize(int nStages){
	if(_init==false){
  _K=new dgDofContainer*[nStages];
  for(int i=0;i<nStages;i++){
    _K[i]=new dgDofContainer(_gc,_law->getNbFields());
    _K[i]->setAll(0.0);
  }
  _currentInput=new dgDofContainer(_gc,_law->getNbFields());
  _currentInput->setAll(0.0);
  _residual=new dgDofContainer(_gc,_law->getNbFields());
  _residual->setAll(0.0);
  _minExponent=INT_MAX;
  _maxExponent=0;
  for(int iGroup=0;iGroup<_gc->getNbElementGroups();iGroup++){
    dgGroupOfElements *ge=_gc->getElementGroup(iGroup);
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
  for(int iGroup=0;iGroup<_gc->getNbFaceGroups();iGroup++){
    dgGroupOfFaces *gf=_gc->getFaceGroup(iGroup);
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
	_init=true;
	}
	else
		return;

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

dgRungeKuttaMultirate43::dgRungeKuttaMultirate43(dgGroupCollection *gc,dgConservationLaw* law): dgRungeKuttaMultirate(gc,law){}


double dgRungeKuttaMultirate43::iterate(double dt, dgDofContainer *solution){
  initialize(10);
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

dgRungeKuttaMultirate22::dgRungeKuttaMultirate22(dgGroupCollection *gc,dgConservationLaw* law): dgRungeKuttaMultirate(gc,law){}


double dgRungeKuttaMultirate22::iterate(double dt, dgDofContainer *solution){
	initialize(4);
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

dgRungeKuttaMultirateConservative::dgRungeKuttaMultirateConservative(dgGroupCollection *gc, dgConservationLaw *law,  fullMatrix<double> *A,  fullMatrix<double> *b, fullMatrix<double> *c):  _A(A), _b(b), _c(c), dgRungeKuttaMultirate(gc, law){
	if(A->size1()!=A->size2() || A->size1()!=b->size2() || A->size1()!=c->size2())
		Msg::Error("The base method's Butcher tables have incompatible sizes");
	//Number of stages of the base method
	int bStages = A->size1();
	
	//Compute Butcher Table for Outer Buffer
	_AOuter=new fullMatrix<double> (2*bStages,2*bStages);
	_bOuter=new fullMatrix<double> (1,2*bStages);
	_cOuter=new fullMatrix<double> (1,2*bStages);

	//Compute Butcher Table for Inner Buffer
	_AInner=new fullMatrix<double> (2*bStages,2*bStages);
	_bInner=new fullMatrix<double> (1,2*bStages);
	_cInner=new fullMatrix<double> (1,2*bStages);
	for(int i=0;i<bStages;i++){
		for(int j=0;j<bStages;j++){
			
			(*_AOuter)(i, j)=(*_A)(i, j);
			(*_AOuter)(bStages+i,bStages+j)=(*_A)(i, j);
			(*_bOuter)(0, i)=0.5*(*_b)(0, i);
			(*_bOuter)(0,bStages+i)=0.5*(*_b)(0, i);
			(*_cOuter)(0, i)=(*_c)(0, i);
			(*_cOuter)(0,bStages+i)=(*_c)(0, i);
			
			(*_AInner)(i, j)=0.5*(*_A)(i, j);
			(*_AInner)(bStages+i,bStages+j)=0.5*(*_A)(i, j);
			(*_AInner)(bStages+i,j)=0.5*(*_b)(0, j);
			(*_bInner)(0, i)=0.5*(*_b)(0, i);
			(*_bInner)(0,bStages+i)=0.5*(*_b)(0, i);
			(*_cInner)(0, i)=0.5*(*_c)(0, i);
			(*_cInner)(0,bStages+i)=0.5+0.5*(*_c)(0, i);

		}
	}
}
void dgRungeKuttaMultirateConservative::printButcher(){
	Msg::Info("------- Printing Inner Butcher Tables --------");
	printf("\n ************************************************** \n");
	_AInner->print("A_inner");
	printf("\n ********************* \n");
	_bInner->print("b_inner");
	printf("\n ********************* \n");
	_cInner->print("c_inner");
	Msg::Info("------- Printing Outer Butcher Tables --------");
	printf("\n ************************************************** \n");
	_AOuter->print("A_outer");
	printf("\n ********************* \n");
	_bOuter->print("b_outer");
	printf("\n ********************* \n");
	_cOuter->print("c_outer");


}
double dgRungeKuttaMultirateConservative::iterate(double dt, dgDofContainer *solution){
	initialize(4);
	_solution=solution;
	_dt=dt;
	computeInputForK(0,0,false,-1);
	computeInputForK(1,0,false,-1);
	
	return solution->norm();
}

void dgRungeKuttaMultirateConservative::computeInputForK(int iK,int exponent,bool isBuffer,int upperLeveliK){
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
			if((*_A)(iK, i)!=0.0){
				_currentInput->axpy(gV,*_K[i],(*_A)(iK, i)*localDt);
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
			if((*_AInner)(iK, i)!=0.0){
				_currentInput->axpy(gVi,*_K[i],(*_AInner)(iK, i)*localDt*2);}
			if((*_AOuter)(iK, i)!=0.0)
				_currentInput->axpy(gVo,*_K[i],(*_AOuter)(iK, i)*localDt*2);
		}
    // We need to update input for the neighboring elements with bigger time step.
    // if there is no corresponding K to be computed
    if( (iK>0 && iK<3) ){
      std::vector<dgGroupOfElements *>&gVbigger=_bulkGroupsOfElements[exponent-1].first;
      _currentInput->scale(gVbigger,0.0);
      _currentInput->axpy(gVbigger,*_solution,1.0);
      int idOuter2Bulk[10]={0,0,0,1};
      for(int i=0;i<iK;i++){
        if((*_AOuter)(iK, i)!=0.0){
          _currentInput->axpy(gVbigger,*_K[idOuter2Bulk[i]],(*_AOuter)(iK, i)*localDt*2);
        }
      }
      std::vector<dgGroupOfElements *>&gViBigger=_innerBufferGroupsOfElements[exponent-1].first;
      _currentInput->scale(gViBigger,0.0);
      _currentInput->axpy(gViBigger,*_solution,1.0);
      // shift
      int s=0;
      if(upperLeveliK>=2){
        for(int i=0;i<2;i++){
          _currentInput->axpy(gViBigger,*_K[i],(*_b)(0, i)*localDt*2);
        }
        s+=2;
      }
      for(int i=0;i<iK;i++){
        if((*_AOuter)(iK, i)!=0.0){
          _currentInput->axpy(gViBigger,*_K[idOuter2Bulk[i]+s],(*_AOuter)(iK, i)*localDt*2);
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

void dgRungeKuttaMultirateConservative::updateSolution(int exponent,bool isBuffer){
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
			if((*_bInner)(0, i)!=0.0)
				_solution->axpy(gVi,*_K[i],(*_bInner)(0, i)*localDt*2);
			if((*_bOuter)(0, i)!=0.0)
				_solution->axpy(gVo,*_K[i],(*_bOuter)(0, i)*localDt*2);
		}
	}
	else{
		std::vector<dgGroupOfElements *>&gV=_bulkGroupsOfElements[exponent].first;
		for(int i=0;i<2;i++){
			if((*_b)(0, i)!=0.0)
				_solution->axpy(gV,*_K[i],(*_b)(0, i)*localDt);
		}
	}
}

dgRungeKuttaMultirateConservative* dgRungeKuttaMultirateConservative::new44(dgGroupCollection *gc,  dgConservationLaw *law){
	Msg::Error("---- Generic Multirate of Constantinescu doesn't work yet for this standard Butcher tables --------");
	fullMatrix<double> *A=new fullMatrix<double>(4, 4);
	fullMatrix<double> *b=new fullMatrix<double>(1, 4);
	fullMatrix<double> *c=new fullMatrix<double>(1, 4);

  double At[4][4]={
		{0, 0, 0, 0}, 
		{1.0/2.0, 0, 0, 0}, 
		{0, 1.0/2.0, 0, 0}, 
		{0, 0, 1, 0}
	};
  double bt[4]={1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
	double ct[4]={0, 1.0/2.0, 1.0/2.0, 1};

	for(int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			(*A)(i, j)=At[i][j];
		}
		(*b)(0, i)=bt[i];
		(*c)(0, i)=ct[i];
	}

	return new dgRungeKuttaMultirateConservative(gc, law, A, b, c);
}
dgRungeKuttaMultirateConservative* dgRungeKuttaMultirateConservative::new43(dgGroupCollection *gc,  dgConservationLaw *law){
	Msg::Error("---- Generic Multirate of Constantinescu doesn't work yet for this standard Butcher tables --------");
	fullMatrix<double> *A=new fullMatrix<double>(4, 4);
	fullMatrix<double> *b=new fullMatrix<double>(1, 4);
	fullMatrix<double> *c=new fullMatrix<double>(1, 4);

  double At[4][4]={
		{0, 0, 0, 0}, 
		{1.0/2.0, 0, 0, 0}, 
		{-1.0/6.0, 2.0/3.0, 0, 0}, 
		{1.0/3.0, -1.0/3.0, 1, 0}
	};
  double bt[4]={1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
	double ct[4]={0, 1.0/2.0, 1.0/2.0, 1};

	for(int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			(*A)(i, j)=At[i][j];
		}
		(*b)(0, i)=bt[i];
		(*c)(0, i)=ct[i];
	}

	return new dgRungeKuttaMultirateConservative(gc, law, A, b, c);
}
dgRungeKuttaMultirateConservative* dgRungeKuttaMultirateConservative::new2a(dgGroupCollection *gc,  dgConservationLaw *law){
	
	fullMatrix<double> *A=new fullMatrix<double>(2, 2);
	fullMatrix<double> *b=new fullMatrix<double>(1, 2);
	fullMatrix<double> *c=new fullMatrix<double>(1, 2);

  double At[2][2]={
		{0, 0}, 
		{1, 0}
	};
  double bt[2]={0.5, 0.5};
	double ct[2]={0, 1};

	for(int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			(*A)(i, j)=At[i][j];
		}
		(*b)(0, i)=bt[i];
		(*c)(0, i)=ct[i];
	}

	return new dgRungeKuttaMultirateConservative(gc, law, A, b, c);
}
dgRungeKuttaMultirateConservative* dgRungeKuttaMultirateConservative::new2b(dgGroupCollection *gc,  dgConservationLaw *law){
	
	fullMatrix<double> *A=new fullMatrix<double>(2, 2);
	fullMatrix<double> *b=new fullMatrix<double>(1, 2);
	fullMatrix<double> *c=new fullMatrix<double>(1, 2);

  double At[2][2]={
		{0, 0}, 
		{1.0/2.0, 0}
	};
  double bt[2]={0, 1};
	double ct[2]={0, 1.0/2.0};

	for(int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			(*A)(i, j)=At[i][j];
		}
		(*b)(0, i)=bt[i];
		(*c)(0, i)=ct[i];
	}

	return new dgRungeKuttaMultirateConservative(gc, law, A, b, c);
}

void dgRungeKuttaMultirateConservative::registerBindings(binding *b) {
	classBinding *cb = b->addClass<dgRungeKuttaMultirateConservative>("dgRungeKuttaMultirateConservative");
	cb->setDescription("Multirate explicit Runge-Kutta with Constantinescu n (base method) stages 2nd order method");
	methodBinding *cm;
	cm = cb->setConstructor<dgRungeKuttaMultirateConservative,dgGroupCollection*,dgConservationLaw* , fullMatrix<double>*, fullMatrix<double>*, fullMatrix<double>* >();
	cm->setArgNames("groupCollection","law","A","b","c",NULL);
	cm->setDescription("A new multirate explicit runge kutta, pass parameters to the iterate function");
	cm = cb->addMethod("iterate",&dgRungeKuttaMultirateConservative::iterate);
	cm->setArgNames("dt","solution",NULL);
	cm->setDescription("update the solution by doing a multirate RK constructed from the given Butcher tables (from Constantinescu and Sandu, 'Update on Multirate Timestepping Methods for Hyperbolic Conservation Laws', Computer Sciance Technical Report,  2007) step of base time step dt for the conservation law");
  cm = cb->addMethod("new44", &dgRungeKuttaMultirateConservative::new43);
	cm->setDescription("Creates a new Conservative Runge-Kutta scheme based on the base method RK44");
	cm->setArgNames("groupCollection", "law", NULL);
  cm = cb->addMethod("new43", &dgRungeKuttaMultirateConservative::new43);
	cm->setDescription("Creates a new Conservative Runge-Kutta scheme based on the base method RK43");
	cm->setArgNames("groupCollection", "law", NULL);
  cm = cb->addMethod("new2a", &dgRungeKuttaMultirateConservative::new2a);
	cm->setDescription("Creates a new Conservative Runge-Kutta scheme based on the base method RK2a");
	cm->setArgNames("groupCollection", "law", NULL);
  cm = cb->addMethod("new2b", &dgRungeKuttaMultirateConservative::new2b);
	cm->setDescription("Creates a new Conservative Runge-Kutta scheme based on the base method RK2b");
	cm->setArgNames("groupCollection", "law", NULL);
  cm = cb->addMethod("printButcher", &dgRungeKuttaMultirateConservative::printButcher);
	cm->setDescription("Print the Butcher Tables for Buffers");
	cm->setArgNames(NULL);
}

