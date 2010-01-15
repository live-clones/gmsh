#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "dgSystemOfEquations.h"
#include "function.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "dgLimiter.h"
#ifdef HAVE_MPI
#include "mpi.h"
#endif

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

void dgSystemOfEquations::registerBindings(binding *b) {
  classBinding *cb = b->addClass<dgSystemOfEquations>("dgSystemOfEquations");
  cb->setDescription("a class to rule them all :-) -- bad description, this class will be removed anyway");
  cb->setConstructor<dgSystemOfEquations,GModel*>();
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
  cm = cb->addMethod("ForwardEuler",&dgSystemOfEquations::ForwardEuler);
  cm->setArgNames("norm","dt",NULL);
  cm->setDescription("do a runge-kuta temporal iteration with a time step \"dt\" and return the sum of the nodal residuals");
  cm = cb->addMethod("setOrder",&dgSystemOfEquations::setOrder);
  cm->setArgNames("order",NULL);
  cm->setDescription("set the polynpolynomialomial order of the lagrange shape functions");
  cm = cb->addMethod("limitSolution",&dgSystemOfEquations::limitSolution);
  cm->setDescription("apply a slope limiter to the solution (only if polynomial order p = 1 for now).");
  cm = cb->addMethod("computeInvSpectralRadius",&dgSystemOfEquations::computeInvSpectralRadius);
  cm->setDescription("returns the inverse of the spectral radius (largest eigenvalue) of L(u). Useful for computing stable explicit time step");
  cm = cb->addMethod("RK44_limiter",&dgSystemOfEquations::RK44_limiter);
  cm->setArgNames("dt",NULL);
  cm->setDescription("do one RK44 time step with the slope limiter (only for p=1)");
  cm = cb->addMethod("multirateRK43",&dgSystemOfEquations::multirateRK43);
  cm = cb->addMethod("saveSolution",&dgSystemOfEquations::saveSolution);
  cm->setArgNames("filename",NULL);
  cm->setDescription("dump the solution in binary format");
  cm = cb->addMethod("loadSolution",&dgSystemOfEquations::loadSolution);
  cm->setArgNames("filename",NULL);
  cm->setDescription("reload a solution in binary format");
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
		     _boundaryGroups,
         _ghostGroups
         );
  // build the ghosts structure
  int *nGhostElements = new int[Msg::GetCommSize()];
  int *nParentElements = new int[Msg::GetCommSize()];
  for (int i=0;i<Msg::GetCommSize();i++) {
    nGhostElements[i]=0;
  }
  for (size_t i = 0; i< _ghostGroups.size(); i++){
    nGhostElements[_ghostGroups[i]->getGhostPartition()] += _ghostGroups[i]->getNbElements();
  }
  #ifdef HAVE_MPI
  MPI_Alltoall(nGhostElements,1,MPI_INT,nParentElements,1,MPI_INT,MPI_COMM_WORLD); 
  #else
  nParentElements[0]=nGhostElements[0];
  #endif
  shiftSend = new int[Msg::GetCommSize()];
  shiftRecv = new int[Msg::GetCommSize()];
  int *curShiftSend = new int[Msg::GetCommSize()];
  totalSend=0,totalRecv=0;
  for(int i= 0; i<Msg::GetCommSize();i++){
    shiftSend[i] = (i==0 ? 0 : shiftSend[i-1]+nGhostElements[i-1]);
    curShiftSend[i] = shiftSend[i];
    shiftRecv[i] = (i==0 ? 0 : shiftRecv[i-1]+nParentElements[i-1]);
    totalSend+=nGhostElements[i];
    totalRecv+=nParentElements[i];
  }

  int *idSend = new int[totalSend];
  int *idRecv = new int[totalRecv];
  for (size_t i = 0; i< _ghostGroups.size(); i++){
    int part = _ghostGroups[i]->getGhostPartition();
    for (int j=0; j< _ghostGroups[i]->getNbElements() ; j++){
      idSend[curShiftSend[part]++] = _ghostGroups[i]->getElement(j)->getNum();
    }
  }
  MPI_Alltoallv(idSend,nGhostElements,shiftSend,MPI_INT,idRecv,nParentElements,shiftRecv,MPI_INT,MPI_COMM_WORLD);
  //create a Map elementNum :: group, position in group
  std::map<int, std::pair<int,int> > elementMap;
  for(size_t i = 0; i<_elementGroups.size(); i++) {
    for(int j=0; j<_elementGroups[i]->getNbElements(); j++){
      elementMap[_elementGroups[i]->getElement(j)->getNum()]=std::pair<int,int>(i,j);
    }
  }
  _elementsToSend.resize(Msg::GetCommSize());
  for(int i = 0; i<Msg::GetCommSize();i++){
    _elementsToSend[i].resize(nParentElements[i]);
    for(int j=0;j<nParentElements[i];j++){
      int num = idRecv[shiftRecv[i]+j];
      _elementsToSend[i][j]=elementMap[num];
    }
  }
  // compute the total size of the soution
  delete curShiftSend;
  _solution = new dgDofContainer(_elementGroups,_ghostGroups,*_claw);
  _rightHandSide = new dgDofContainer(_elementGroups,_ghostGroups,*_claw);
}


double dgSystemOfEquations::RK44(double dt){
  _algo->rungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups,_ghostGroups, dt,  *_solution, *_rightHandSide, this);
  return _solution->_data->norm();
}

double dgSystemOfEquations::computeInvSpectralRadius(){   
  double sr = 1.e22;
  for (int i=0;i<_elementGroups.size();i++){
    std::vector<double> DTS;
    _algo->computeElementaryTimeSteps(*_claw, *_elementGroups[i], *_solution->_dataProxys[i], DTS);
    for (int k=0;k<DTS.size();k++) sr = std::min(sr,DTS[k]);
  }
  #ifdef HAVE_MPI
  double sr_min;
  MPI_Allreduce((void *)&sr, &sr_min, 1, MPI_DOUBLE, MPI_MIN,
                MPI_COMM_WORLD);
  return sr_min;
  #else
  return sr
  #endif
}

double dgSystemOfEquations::RK44_limiter(double dt){
  dgLimiter *sl = new dgSlopeLimiter(_claw);
  _algo->rungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups,_ghostGroups, dt,  *_solution, *_rightHandSide,this, sl);
  delete sl;
  return _solution->_data->norm();
}

double dgSystemOfEquations::ForwardEuler(double dt){
  _algo->rungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups,_ghostGroups, dt,  *_solution, *_rightHandSide,this, NULL,1);
  return _solution->_data->norm();
}
double dgSystemOfEquations::multirateRK43(double dt){
  _algo->multirateRungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups,_ghostGroups, dt,  *_solution, *_rightHandSide);
  return _solution->_data->norm();
}

void dgSystemOfEquations::exportSolution(std::string outputFile){
  export_solution_as_is(outputFile);
}

void dgSystemOfEquations::limitSolution(){
  dgLimiter *sl = new dgSlopeLimiter(_claw);
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

void dgSystemOfEquations::saveSolution (std::string name) {
  FILE *f = fopen (name.c_str(),"wb");
  _solution->_data->binarySave(f);
  fclose(f);
}

void dgSystemOfEquations::loadSolution (std::string name){
  FILE *f = fopen (name.c_str(),"rb");
  _solution->_data->binaryLoad(f);
  fclose(f);
}

void dgSystemOfEquations::export_solution_as_is (const std::string &name){
  // the elementnodedata::export does not work !!

  for (int ICOMP = 0; ICOMP<_claw->nbFields();++ICOMP){
    std::ostringstream name_oss;
    name_oss<<name<<"_COMP_"<<ICOMP<<".msh";
    if(Msg::GetCommSize()>1)
      name_oss<<"_"<<Msg::GetCommRank();
    FILE *f = fopen (name_oss.str().c_str(),"w");
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

dgDofContainer::dgDofContainer (std::vector<dgGroupOfElements*> &elementGroups,std::vector<dgGroupOfElements*> ghostGroups, const dgConservationLaw &claw){
  _dataSize = 0;
  _dataSizeGhost=0;
  totalNbElements = 0;
  int totalNbElementsGhost =0;
  nbFields = claw.nbFields();
  for (int i=0;i<elementGroups.size();i++){
    int nbNodes    = elementGroups[i]->getNbNodes();
    int nbElements = elementGroups[i]->getNbElements();
    totalNbElements +=nbElements;
    _dataSize += nbNodes*nbFields*nbElements;
  }
  for (int i=0;i<ghostGroups.size();i++){
    int nbNodes    = ghostGroups[i]->getNbNodes();
    int nbElements = ghostGroups[i]->getNbElements();
    totalNbElementsGhost +=nbElements;
    _dataSizeGhost += nbNodes*nbFields*nbElements;
  }

  // allocate the big vectors
  _data      = new fullVector<double>(_dataSize);
  _ghostData = new fullVector<double>(_dataSizeGhost);
  // create proxys for each group
  int offset = 0;
  _dataProxys.resize(elementGroups.size()+ghostGroups.size());
  for (int i=0;i<elementGroups.size();i++){    
    dgGroupOfElements *group=elementGroups[i];
    int nbNodes    = group->getNbNodes();
    int nbElements = group->getNbElements();
    _dataProxys[i] = new fullMatrix<double> (&(*_data)(offset),nbNodes, nbFields*nbElements);
    offset += nbNodes*nbFields*nbElements;
  }  
  offset=0;
  for (int i=0;i<ghostGroups.size();i++){    
    dgGroupOfElements *group=ghostGroups[i];
    int nbNodes    = group->getNbNodes();
    int nbElements = group->getNbElements();
    _dataProxys[i+elementGroups.size()] = new fullMatrix<double> (&(*_ghostData)(offset),nbNodes, nbFields*nbElements);
    offset += nbNodes*nbFields*nbElements;
  }  
  //  printf("datasize = %d\n",_dataSize);
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
    dgGroupOfElements *group=elementGroups[i];
    int nbNodes    = group->getNbNodes();
    int nbElements = group->getNbElements();
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

void dgSystemOfEquations::scatter(dgDofContainer *vector){
  //1) count
  int *countS=new int[Msg::GetCommSize()];
  int *shiftS=new int[Msg::GetCommSize()];
  int *countR=new int[Msg::GetCommSize()];
  int *shiftR=new int[Msg::GetCommSize()];
  for(int i=0;i<Msg::GetCommSize();i++){
    countS[i]=0;
    countR[i]=0;
    for(size_t j=0;j<_elementsToSend[i].size();j++){
      countS[i] += _elementGroups[_elementsToSend[i][j].first]->getNbNodes()*_claw->nbFields();
    }
  }
  for(size_t i=0; i<_ghostGroups.size(); i++){
    dgGroupOfElements *group=_ghostGroups[i];
    countR[group->getGhostPartition()]+=group->getNbElements()*group->getNbNodes()*_claw->nbFields();
  }
  shiftS[0]=shiftR[0]=0;
  int totalS=countS[0];
  int totalR=countR[0];
  for(size_t i=1; i<Msg::GetCommSize(); i++){
    shiftS[i]=shiftS[i-1]+countS[i-1];
    shiftR[i]=shiftR[i-1]+countR[i-1];
    totalS+=countS[i];
    totalR+=countR[i];
  }
  double *send=new double[totalS];
  double *recv=new double[totalR];
  //2) fill
  int index=0;
  for(int i=0;i<Msg::GetCommSize();i++){
    for(size_t j=0;j<_elementsToSend[i].size();j++){
      int gid = _elementsToSend[i][j].first;
      int eid = _elementsToSend[i][j].second;
      fullMatrix<double> &sol=vector->getGroupProxy(gid);
      for(int l=0;l<_claw->nbFields();l++){
        for(int k=0;k<sol.size1();k++){
          send[index++] = sol(k,eid*_claw->nbFields()+l);
//          send[index++] = _elementGroups[gid]->getElement(eid)->getNum()*9+l*3+k;
        }
      }
    }
  }
  
  //3) send
  MPI_Alltoallv(send,countS,shiftS,MPI_DOUBLE,recv,countR,shiftR,MPI_DOUBLE,MPI_COMM_WORLD);
  //4) distribute
  for(int i=0; i< _ghostGroups.size();i++){
    fullMatrix<double>&sol = vector->getGroupProxy(i+_elementGroups.size());
    int part = _ghostGroups[i]->getGhostPartition();
    int ndof = sol.size1()*sol.size2();
    for(int j=0;j<sol.size2();j++){
      for(int k=0;k<sol.size1();k++){
        sol(k,j)=recv[shiftR[part]++];
/*        int a=(int)recv[shiftR[part]++];
        int b= _ghostGroups[i]->getElement(j/3)->getNum()*9+3*(j%3)+k;
        if(a!=b)printf("%i %i\n",a,b);*/
      }
    }
  }
  delete countS;
  delete countR;
  delete shiftS;
  delete shiftR;
  delete send;
  delete recv;
}

