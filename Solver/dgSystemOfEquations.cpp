#include <stdio.h>
#include <stdlib.h>
#include "dgSystemOfEquations.h"
#include "function.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "dgLimiter.h"

class dgConservationLawL2Projection : public dgConservationLaw {
  std::string _functionName;
public:
  dgConservationLawL2Projection(const std::string & functionName, dgConservationLaw &_claw) :
    _functionName(functionName)
  {
    _nbf =_claw.nbFields();
  }
  dataCacheDouble *newSourceTerm(dataCacheMap &cacheMap)const {
    return &cacheMap.get(_functionName);
  }
};

dgSystemOfEquations::dgSystemOfEquations(GModel *gm){
  _gm=gm;
  _dimension = _gm->getNumRegions() ? 3 : _gm->getNumFaces() ? 2 : 1 ;
  _solution = 0;
}


// set the order of interpolation
void dgSystemOfEquations::setOrder(int o){
  _order = o;
}

// add a boundary Condition
void dgSystemOfEquations::setConservationLaw (dgConservationLaw *law){
  _claw=law;
}

#include "Bindings.h"

static dgSystemOfEquations *myConstructorPtr(GModel* gm){
  return new dgSystemOfEquations(gm);
}

void dgSystemOfEquations::registerBindings(binding *b){
  classBinding *cb = b->addClass<dgSystemOfEquations>("dgSystemOfEquations");
  cb->setDescription("a class to rule them all :-) -- bad description, this class will be removed anyway");
  cb->setConstructor(myConstructorPtr);
  methodBinding *cm;
  cm = cb->addMethod("setConservationLaw",&dgSystemOfEquations::setConservationLaw);
  cm->setArgNames("law",NULL);
  cm->setDescription("set the conservation law this system solves");
  cm = cb->addMethod("setup",&dgSystemOfEquations::setup);
  cm->setDescription("allocate and init internal stuff, call this function after setOrder and setLaw and before anything else on this instance");
  cm = cb->addMethod("exportSolution",&dgSystemOfEquations::exportSolution);
  cm->setArgNames("filename",NULL);
  cm->setDescription("Print the solution into a file. This file does not contain the mesh. To visualize the solution in gmsh you have to open the mesh file first.");
  cm= cb->addMethod("L2Projection",&dgSystemOfEquations::L2Projection);
  cm->setArgNames("functionName",NULL);
  cm->setDescription("project the function \"functionName\" on the solution vector");
  cm = cb->addMethod("RK44",&dgSystemOfEquations::RK44);
  cm->setArgNames("norm","dt",NULL);
  cm->setDescription("do a runge-kuta temporal iteration with a time step \"dt\" and return the sum of the nodal residuals");
  cm = cb->addMethod("setOrder",&dgSystemOfEquations::setOrder);
  cm->setArgNames("order",NULL);
  cm->setDescription("set the polynpolynomialomial order of the lagrange shape functions");
  cb->addMethod("limitSolution",&dgSystemOfEquations::limitSolution);
  cb->addMethod("computeInvSpectralRadius",&dgSystemOfEquations::computeInvSpectralRadius);
  cb->addMethod("RK44_limiter",&dgSystemOfEquations::RK44_limiter);
  cb->addMethod("multirateRK43",&dgSystemOfEquations::multirateRK43);
}

// do a L2 projection
void dgSystemOfEquations::L2Projection (std::string functionName){
  dgConservationLawL2Projection Law(functionName,*_claw);
  for (int i=0;i<_elementGroups.size();i++){
    _algo->residualVolume(Law,*_elementGroups[i],*_solution->_dataProxys[i],*_rightHandSide->_dataProxys[i]);
    _algo->multAddInverseMassMatrix(*_elementGroups[i],*_rightHandSide->_dataProxys[i],*_solution->_dataProxys[i]);
  }
}

// ok, we can setup the groups and create solution vectors
void dgSystemOfEquations::setup(){
  if (!_claw) throw;
  _algo->buildGroups(_gm,
		     _dimension,
		     _order,
		     _elementGroups,
		     _faceGroups,
		     _boundaryGroups);
  // compute the total size of the soution
  _solution = new dgDofContainer(_elementGroups,*_claw);
  _rightHandSide = new dgDofContainer(_elementGroups,*_claw);
}


double dgSystemOfEquations::RK44(double dt){
  _algo->rungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups, dt,  *_solution, *_rightHandSide, NULL);
  return _solution->_data->norm();
}

double dgSystemOfEquations::computeInvSpectralRadius(){  
  
  double sr = 1.e22;
  for (int i=0;i<_elementGroups.size();i++){
    std::vector<double> DTS;
    _algo->computeElementaryTimeSteps(*_claw, *_elementGroups[i], *_solution->_dataProxys[i], DTS);
    for (int k=0;k<DTS.size();k++) sr = std::min(sr,DTS[k]);
  }
  return sr;
}

double dgSystemOfEquations::RK44_limiter(double dt){
	dgLimiter *sl = new dgSlopeLimiter();
	_algo->rungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups, dt,  *_solution, *_rightHandSide, sl);
	return _solution->_data->norm();
}

double dgSystemOfEquations::multirateRK43(double dt){
  _algo->multirateRungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups, dt,  *_solution, *_rightHandSide);
  return _solution->_data->norm();
}

void dgSystemOfEquations::exportSolution(std::string outputFile){
  export_solution_as_is(outputFile);
}

void dgSystemOfEquations::limitSolution(){
	dgLimiter *sl = new dgSlopeLimiter();
  sl->apply(*_solution,_elementGroups,_faceGroups);

  delete sl;
}

dgSystemOfEquations::~dgSystemOfEquations(){
  for (int i=0;i<_elementGroups.size();i++){
    delete _elementGroups[i];
  }
  if (_solution){
    delete _solution;
    delete _rightHandSide;
  }
}

void dgSystemOfEquations::export_solution_as_is (const std::string &name){
  // the elementnodedata::export does not work !!

  for (int ICOMP = 0; ICOMP<_claw->nbFields();++ICOMP){
    char aaa[245];
    sprintf(aaa,"%s_COMP_%d.msh",name.c_str(),ICOMP);
    FILE *f = fopen (aaa,"w");
    int COUNT = 0;
    for (int i=0;i < _elementGroups.size() ;i++){
      COUNT += _elementGroups[i]->getNbElements();
    }
    fprintf(f,"$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");  
    fprintf(f,"$ElementNodeData\n");
    fprintf(f,"1\n");
    fprintf(f,"\"%s\"\n",name.c_str());
    fprintf(f,"1\n");
    fprintf(f,"0.0\n");
    fprintf(f,"3\n");
    fprintf(f,"0\n 1\n %d\n",COUNT);
    for (int i=0;i < _elementGroups.size() ;i++){
      for (int iElement=0 ; iElement<_elementGroups[i]->getNbElements() ;++iElement) {
	MElement *e = _elementGroups[i]->getElement(iElement);
	int num = e->getNum();
	fullMatrix<double> sol = getSolutionProxy (i, iElement);      
	fprintf(f,"%d %d",num,sol.size1());
	for (int k=0;k<sol.size1();++k) {
	  fprintf(f," %12.5E ",sol(k,ICOMP));
	}
	fprintf(f,"\n");
      }
    }
    fprintf(f,"$EndElementNodeData\n");
    fclose(f);
  }
  return;
  // we should discuss that : we do a copy of the solution, this should
  // be avoided !

  std::map<int, std::vector<double> > data;
  
  for (int i=0;i < _elementGroups.size() ;i++){
    for (int iElement=0 ; iElement<_elementGroups[i]->getNbElements() ;++iElement) {
      MElement *e = _elementGroups[i]->getElement(iElement);
      int num = e->getNum();
      fullMatrix<double> sol = getSolutionProxy (i, iElement);      
      std::vector<double> val;
      //      val.resize(sol.size2()*sol.size1());
      val.resize(sol.size1());
      int counter = 0;
      //      for (int iC=0;iC<sol.size2();iC++)
      printf("%g %g %g\n",sol(0,0),sol(1,0),sol(2,0));
      for (int iR=0;iR<sol.size1();iR++)val[counter++] = sol(iR,0);
      data[num] = val;
    }
  }

  PView *pv = new PView (name, "ElementNodeData", _gm, data, 0.0, 1);
  pv->getData()->writeMSH(name+".msh", false); 
  delete pv;
}

dgDofContainer::dgDofContainer (std::vector<dgGroupOfElements*> &elementGroups, const dgConservationLaw &claw){
  _dataSize = 0;
  totalNbElements = 0;
  nbFields = claw.nbFields();
  for (int i=0;i<elementGroups.size();i++){
    int nbNodes    = elementGroups[i]->getNbNodes();
    int nbElements = elementGroups[i]->getNbElements();
    totalNbElements +=nbElements;
    _dataSize += nbNodes*nbFields*nbElements;
  }

  // allocate the big vectors
  _data      = new fullVector<double>(_dataSize);
  // create proxys for each group
  int offset = 0;
  _dataProxys.resize(elementGroups.size());
  for (int i=0;i<elementGroups.size();i++){    
    int nbNodes    = elementGroups[i]->getNbNodes();
    int nbElements = elementGroups[i]->getNbElements();
    _dataProxys[i] = new fullMatrix<double> (&(*_data)(offset),nbNodes, nbFields*nbElements);
    offset += nbNodes*nbFields*nbElements;
  }  
  //  printf("datasize = %d\n",_dataSize);
}

dgDofContainer::~dgDofContainer (){
  if (!_dataSize)return;
  for (int i=0;i<_dataProxys.size();++i) delete _dataProxys[i];
  delete _data;
}
