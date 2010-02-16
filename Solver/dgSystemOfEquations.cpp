#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "dgSystemOfEquations.h"
#include "dgAlgorithm.h"
#include "function.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "dgLimiter.h"
#include "dgRungeKutta.h"
#ifdef HAVE_MPI
#include "mpi.h"
#endif
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
  methodBinding *cm;
  cm = cb->setConstructor<dgSystemOfEquations,GModel*>();
  cm->setArgNames("model",NULL);
  cm->setDescription("A new system of equation on the domain described by 'model'");
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
  cm->setArgNames("dt",NULL);
  cm->setDescription("Do a runge-kuta temporal iteration with 4 sub-steps and a precision order of 4 with a time step \"dt\". This function returns the sum of the nodal residuals.");
  cm = cb->addMethod("ForwardEuler",&dgSystemOfEquations::ForwardEuler);
  cm->setArgNames("dt",NULL);
  cm->setDescription("do a forward euler temporal iteration with a time step \"dt\" and return the sum of the nodal residuals");
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
  ////cm = cb->addMethod("multirateRK43",&dgSystemOfEquations::multirateRK43);
  //cm->setArgNames("dt",NULL);
  //cm->setDescription("Do a runge-kuta temporal iteration with 4 sub-steps and a precision order of 3 using different time-step depending on the element size. This function returns the sum of the nodal residuals.");
  cm = cb->addMethod("saveSolution",&dgSystemOfEquations::saveSolution);
  cm->setArgNames("filename",NULL);
  cm->setDescription("dump the solution in binary format");
  cm = cb->addMethod("loadSolution",&dgSystemOfEquations::loadSolution);
  cm->setArgNames("filename",NULL);
  cm->setDescription("reload a solution in binary format");
}

// do a L2 projection
void dgSystemOfEquations::L2Projection (std::string functionName){
  _solution->L2Projection(functionName);
}

// ok, we can setup the groups and create solution vectors
void dgSystemOfEquations::setup(){
  if (!_claw) throw;
	_groups.buildGroupsOfElements(_gm,_dimension,_order);
	_groups.buildGroupsOfInterfaces();
  _solution = new dgDofContainer(&_groups,_claw->getNbFields());
  _rightHandSide = new dgDofContainer(&_groups,_claw->getNbFields());
}


double dgSystemOfEquations::RK44(double dt){
  dgRungeKutta rk;
  rk.iterate44(_claw, dt, _solution);
  return _solution->norm();
}

double dgSystemOfEquations::computeInvSpectralRadius(){   
  double sr = 1.e22;
  for (int i=0;i<_groups.getNbElementGroups();i++){
    std::vector<double> DTS;
    dgAlgorithm::computeElementaryTimeSteps(*_claw, *_groups.getElementGroup(i), _solution->getGroupProxy(i), DTS);
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

double dgSystemOfEquations::RK44_limiter(double dt){
  dgLimiter *sl = new dgSlopeLimiter(_claw);
  dgRungeKutta rk;
  rk.setLimiter(sl);
  rk.iterate44(_claw, dt, _solution);
  delete sl;
  return _solution->norm();
}

double dgSystemOfEquations::ForwardEuler(double dt){
  dgRungeKutta rk;
  rk.iterateEuler(_claw, dt, _solution);
  return _solution->norm();
}
//double dgSystemOfEquations::multirateRK43(double dt){
  //dgAlgorithm::multirateRungeKutta(*_claw, _groups, dt,  *_solution, *_rightHandSide);
  //return _solution->norm();
//}

void dgSystemOfEquations::exportSolution(std::string outputFile){
  _solution->exportMsh(outputFile);
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
  _solution->save(name);
}

void dgSystemOfEquations::loadSolution (std::string name){
  _solution->load(name);
}
