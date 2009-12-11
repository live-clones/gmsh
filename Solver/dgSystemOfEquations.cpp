#include <stdio.h>
#include <stdlib.h>
#include "dgSystemOfEquations.h"
#include "LuaBindings_Geo.h"
#include "function.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"

#if defined(HAVE_LUA)
// define the name of the object that will be used in Lua
const char dgSystemOfEquations::className[] = "dgSystemOfEquations";
// Define the methods we will expose to Lua
#define _method(class, name) {#name, &class::name}
Luna<dgSystemOfEquations>::RegType dgSystemOfEquations::methods[] = {
   _method(dgSystemOfEquations, RK44),
   _method(dgSystemOfEquations, exportSolution),
   _method(dgSystemOfEquations, setConservationLaw),
   _method(dgSystemOfEquations, setOrder),
   _method(dgSystemOfEquations, setup),
   _method(dgSystemOfEquations, addBoundaryCondition),
   _method(dgSystemOfEquations, L2Projection),
   {0,0}
};

// this function has to be called in the main in order to register
// the names defined above
void dgSystemOfEquations::Register (lua_State *L){
  Luna<dgSystemOfEquations>::Register(L);
}

class dgConservationLawL2Projection : public dgConservationLaw {
  std::string _functionName;
public:
  dgConservationLawL2Projection(const std::string & functionName,
				dgConservationLaw &_claw) :
    _functionName(functionName)
  {
    _nbf =_claw.nbFields();
  }
  dataCacheDouble *newSourceTerm(dataCacheMap &cacheMap)const {
    //return new gaussian(cacheMap,0.2,0.3);
    return &cacheMap.get(_functionName);
  }
};


// system of equations is build using a mesh
dgSystemOfEquations::dgSystemOfEquations(lua_State *L){
  // get the number of arguments
  int n = lua_gettop(L);  
  if (n < 1)throw;
  LuaGModel *obj =Luna<LuaGModel>::check(L, 1);
  if (!obj)throw;
  _gm = obj->getGModel();
  _dimension = _gm->getNumRegions() ? 3 : 2;
  _solution = 0;
}

// set the conservation law as a string (for now)
int dgSystemOfEquations::setConservationLaw(lua_State *L){
  _claw = 0;  
  //int argc = (int)luaL_checknumber(L,0);
  _cLawName = std::string (luaL_checkstring(L, 1));
  if (_cLawName == "WaveEquation")
    _claw = dgNewConservationLawWaveEquation();
  else if (_cLawName == "ShallowWater2d")
    _claw = dgNewConservationLawShallowWater2d(); 
  else if  (_cLawName == "PerfectGas2d")
    _claw = dgNewPerfectGasLaw2d(); 
  else if (_cLawName == "AdvectionDiffusion"){
    _claw = dgNewConservationLawAdvection(luaL_checkstring(L,2),luaL_checkstring(L,3));
  }
  if (!_claw)throw;
  return 0;
}

// set the order of interpolation
int dgSystemOfEquations::setOrder(lua_State *L){
  _order = luaL_checkint(L, 1);
}

// add a boundary Condition
int dgSystemOfEquations::addBoundaryCondition (lua_State *L){
  std::string physicalName(luaL_checkstring(L, 1));
  std::string bcName(luaL_checkstring(L, 2));
  //generic boundary conditions
  if (bcName == "0Flux"){
    _claw->addBoundaryCondition(physicalName,dgBoundaryCondition::new0FluxCondition(*_claw));
  }
  else if (bcName == "OutsideValues"){
    _claw->addBoundaryCondition(physicalName,dgBoundaryCondition::newOutsideValueCondition(*_claw,luaL_checkstring(L,3)));
  }
  //specific boundary conditions
  else if (_cLawName == "WaveEquation"){
    if (bcName == "Wall"){
      _claw->addBoundaryCondition(physicalName,dgNewBoundaryConditionWaveEquationWall());
    }
    else throw;
  }
  else if (_cLawName == "ShallowWater2d"){
    if (bcName == "Wall"){
      _claw->addBoundaryCondition(physicalName,dgNewBoundaryConditionShallowWater2dWall());
    }
    else throw;
  }
  else if (_cLawName == "PerfectGas2d"){
    if (bcName == "Wall"){
      _claw->addBoundaryCondition(physicalName,dgNewBoundaryConditionPerfectGasLaw2dWall());
    }
    else if (bcName == "FreeStream"){
      std::string freeStreamName(luaL_checkstring(L, 3));
      _claw->addBoundaryCondition(physicalName,
				  dgNewBoundaryConditionPerfectGasLaw2dFreeStream(freeStreamName));
    }
    else throw;
  }
  else throw;
}

// do a L2 projection
int dgSystemOfEquations::L2Projection (lua_State *L){
  dgConservationLawL2Projection Law(std::string(luaL_checkstring(L, 1)),*_claw);
  for (int i=0;i<_elementGroups.size();i++){
    _algo->residualVolume(Law,*_elementGroups[i],*_solution->_dataProxys[i],*_rightHandSide->_dataProxys[i]);
    _algo->multAddInverseMassMatrix(*_elementGroups[i],*_rightHandSide->_dataProxys[i],*_solution->_dataProxys[i]);
  }
  return 0;
}

// ok, we can setup the groups and create solution vectors
int dgSystemOfEquations::setup(lua_State *L){
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


int dgSystemOfEquations::RK44(lua_State *L){
  double dt = luaL_checknumber(L, 1);
  _algo->rungeKutta(*_claw, _elementGroups, _faceGroups, _boundaryGroups, dt,  *_solution, *_rightHandSide);
  double normSolution = _solution->_data->norm();
  lua_pushnumber (L, normSolution);
  return 1;
}

int dgSystemOfEquations::exportSolution(lua_State *L){
  std::string outputFile(luaL_checkstring(L, 1));
  export_solution_as_is(outputFile);
  return 0;
}
#endif // HAVE_LUA

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
	  fprintf(f,"%12.5E ",sol(k,ICOMP));
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
  int nbFields = claw.nbFields();
  for (int i=0;i<elementGroups.size();i++){
    int nbNodes    = elementGroups[i]->getNbNodes();
    int nbElements = elementGroups[i]->getNbElements();
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
    _dataProxys[i] = new fullMatrix<double> (&(*_data)(offset*sizeof(double)),nbNodes, nbFields*nbElements);
    offset += nbNodes*nbFields*nbElements;
  }  
  //  printf("datasize = %d\n",_dataSize);
}

dgDofContainer::~dgDofContainer (){
  if (!_dataSize)return;
  for (int i=0;i<_dataProxys.size();++i) delete _dataProxys[i];
  delete _data;
}
