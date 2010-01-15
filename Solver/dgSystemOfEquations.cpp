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
  for (int i=0;i<_groups.getNbElementGroups();i++){
    dgGroupOfElements *group = _groups.getElementGroup(i);
    _algo->residualVolume(Law,*group,*_solution->_dataProxys[i],*_rightHandSide->_dataProxys[i]);
    _algo->multAddInverseMassMatrix(*group,*_rightHandSide->_dataProxys[i],*_solution->_dataProxys[i]);
  }
}

// ok, we can setup the groups and create solution vectors
void dgSystemOfEquations::setup(){
  if (!_claw) throw;
  _groups.buildGroups(_gm,_dimension,_order);
  _solution = new dgDofContainer(_groups,_claw->nbFields());
  _rightHandSide = new dgDofContainer(_groups,_claw->nbFields());
}


double dgSystemOfEquations::RK44(double dt){
  _algo->rungeKutta(*_claw,_groups, dt,  *_solution, *_rightHandSide);
  return _solution->_data->norm();
}

double dgSystemOfEquations::computeInvSpectralRadius(){   
  double sr = 1.e22;
  for (int i=0;i<_groups.getNbElementGroups();i++){
    std::vector<double> DTS;
    _algo->computeElementaryTimeSteps(*_claw, *_groups.getElementGroup(i), *_solution->_dataProxys[i], DTS);
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
  _algo->rungeKutta(*_claw,_groups, dt,  *_solution, *_rightHandSide, sl);
  delete sl;
  return _solution->_data->norm();
}

double dgSystemOfEquations::ForwardEuler(double dt){
  _algo->rungeKutta(*_claw, _groups, dt,  *_solution, *_rightHandSide, NULL,1);
  return _solution->_data->norm();
}
double dgSystemOfEquations::multirateRK43(double dt){
  _algo->multirateRungeKutta(*_claw, _groups, dt,  *_solution, *_rightHandSide);
  return _solution->_data->norm();
}

void dgSystemOfEquations::exportSolution(std::string outputFile){
  export_solution_as_is(outputFile);
}

void dgSystemOfEquations::limitSolution(){
  dgLimiter *sl = new dgSlopeLimiter(_claw);
  sl->apply(*_solution,_groups);

  delete sl;
}

dgSystemOfEquations::~dgSystemOfEquations(){
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
    for (int i=0;i < _groups.getNbElementGroups() ;i++){
      COUNT += _groups.getElementGroup(i)->getNbElements();
    }
    fprintf(f,"$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");  
    fprintf(f,"$ElementNodeData\n");
    fprintf(f,"1\n");
    fprintf(f,"\"%s\"\n",name.c_str());
    fprintf(f,"1\n");
    fprintf(f,"0.0\n");
    fprintf(f,"3\n");
    fprintf(f,"0\n 1\n %d\n",COUNT);
    for (int i=0;i < _groups.getNbElementGroups()  ;i++){
      dgGroupOfElements *group = _groups.getElementGroup(i);
      for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
        MElement *e = group->getElement(iElement);
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
  
  for (int i=0;i < _groups.getNbElementGroups() ;i++){
    dgGroupOfElements *group = _groups.getElementGroup(i);
    for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
      MElement *e = group->getElement(iElement);
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



