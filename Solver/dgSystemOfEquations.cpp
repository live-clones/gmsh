#include "dgSystemOfEquations.h"
#include "LuaBindings_Geo.h"

#if defined(HAVE_LUA)
// define the name of the object that will be used in Lua
const char dgSystemOfEquations::className[] = "dgSystemOfEquations";
// Define the methods we will expose to Lua
#define _method(class, name) {#name, &class::name}
Luna<dgSystemOfEquations>::RegType dgSystemOfEquations::methods[] = {
   _method(dgSystemOfEquations, getRHS),
   _method(dgSystemOfEquations, computeRHS),
   _method(dgSystemOfEquations, getSolution),
   _method(dgSystemOfEquations, exportSolution),
   _method(dgSystemOfEquations, setConservationLaw),
   _method(dgSystemOfEquations, setOrder),
   _method(dgSystemOfEquations, setup),
   _method(dgSystemOfEquations, addBoundaryCondition),
   {0,0}
};

// this function has to be called in the main in order to register
// the names defined above
void dgSystemOfEquations::Register (lua_State *L){
  Luna<dgSystemOfEquations>::Register(L);
}

// system of equations is build using a mesh
dgSystemOfEquations::dgSystemOfEquations(lua_State *L){
  // get the number of arguments
  int n = lua_gettop(L);  
  if (n < 1)throw;
  LuaGModel *obj =Luna<LuaGModel>::check(L, 1);
  if (!obj)throw;
  _gm = obj->getGModel();
  _dimension = _gm->getNumRegions() ? 3 : 2;
}

// set the conservation law as a string (for now)
int dgSystemOfEquations::setConservationLaw(lua_State *L){
  _claw = 0;  
  _cLawName = std::string (luaL_checkstring(L, 1));
  if (_cLawName == "WaveEquation")
    _claw = dgNewConservationLawWaveEquation();
  else if  (_cLawName == "ShallowWater2d")
    _claw = dgNewConservationLawShallowWater2d(); 
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
  if (_cLawName == "WaveEquation"){
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
  else throw;
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
  //for now, we suppose there is only one group of elements
  int nbNodes    = _elementGroups[0]->getNbNodes();
  int nbElements = _elementGroups[0]->getNbElements();
  // allocate solution and RHS
  int nbFields = _claw->nbFields();
  _solution      = new fullMatrix<double>  (nbNodes,nbFields*nbElements);
  _rightHandSide = new fullMatrix<double>  (nbNodes,nbFields*nbElements);
}


int dgSystemOfEquations::getSolution(lua_State *L){
  lua_pushlightuserdata (L, _solution);
  return 1;
}

int dgSystemOfEquations::computeRHS(lua_State *L){
  _algo->residual(*_claw, _elementGroups, _faceGroups, _boundaryGroups, *_solution, *_rightHandSide);
  lua_pushlightuserdata (L, _solution);
  return 1;
}

int dgSystemOfEquations::getRHS(lua_State *L){
  lua_pushlightuserdata (L, _rightHandSide);
  return 1;
}

int dgSystemOfEquations::exportSolution(lua_State *L){
}
#endif // HAVE_LUA

dgSystemOfEquations::dgSystemOfEquations(GModel *obj, dgConservationLaw *claw,int order){
  setup(obj,claw,order);
}

dgSystemOfEquations::~dgSystemOfEquations(){
  delete _solution;
  delete _rightHandSide;
}

void dgSystemOfEquations::setup(GModel *obj, dgConservationLaw *claw, int order){
  _gm = obj;
  _claw = claw;
  _algo = new dgAlgorithm;
  _order= order;
  _dimension = _gm->getNumRegions() ? 3 : 2;
  _algo->buildGroups(_gm,
		     _dimension,
		     _order,
		     _elementGroups,
		     _faceGroups,
		     _boundaryGroups);
  //for now, we suppose there is only one group of elements
  int nbNodes    = _elementGroups[0]->getNbNodes();
  int nbElements = _elementGroups[0]->getNbElements();
  // allocate solution and RHS
  int nbFields = _claw->nbFields();
  _solution      = new fullMatrix<double>  (nbNodes,nbFields*nbElements);
  _rightHandSide = new fullMatrix<double>  (nbNodes,nbFields*nbElements);
}
