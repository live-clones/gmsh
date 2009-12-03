#ifndef _DG_SYSTEM_OF_EQUATIONS_
#define _DG_SYSTEM_OF_EQUATIONS_
#include "GmshConfig.h"
#include "GModel.h"
#include "dgAlgorithm.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"

#if defined(HAVE_LUA)
// include lua stuff
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
// Use luna for c++ class member functions bindings
#include "luna.h"
#endif // HAVE LUA

class dgSystemOfEquations {
  // the mesh and the model
  GModel *_gm;
  // the algorithm that computes DG operators
  dgAlgorithm *_algo;
  // the conservation law
  dgConservationLaw *_claw;
  std::string _cLawName;
  // polynomial order (should be more general)
  int _order;
  // dimension of the problem
  int _dimension;
  // the solution
  fullMatrix<double> *_solution;
  // the right hand side (a temporary vector)
  fullMatrix<double> *_rightHandSide;
  // groups of elements (volume terms)
  std::vector<dgGroupOfElements*> _elementGroups;
  // groups of faces (interface terms)
  std::vector<dgGroupOfFaces*> _faceGroups;
  // groups of faces (boundary conditions)
  std::vector<dgGroupOfFaces*> _boundaryGroups;
  // sets up everything
  void setup(GModel *gm, dgConservationLaw *claw, int order);
  dgSystemOfEquations(const dgSystemOfEquations &) {}
public:
  // lua stuff
#if defined(HAVE_LUA)
  static const char className[];
  static Luna<dgSystemOfEquations>::RegType methods[];
  static void Register(lua_State *L);
  int computeRHS      (lua_State *L); // get the Right Hand
  int getRHS      (lua_State *L); // get the Right Hand
  int getSolution (lua_State *L); // get the Solution
  int exportSolution (lua_State *L); // export the solution
  int setOrder (lua_State *L); // set the polynomial order
  int setConservationLaw (lua_State *L); // set the conservationLaw
  int addBoundaryCondition (lua_State *L); // add a boundary condition : "physical name", "type", [options]
  int setup (lua_State *L); // setup the groups and allocate
  dgSystemOfEquations(lua_State *L);
#endif // HAVE LUA
  dgSystemOfEquations(GModel *gm, dgConservationLaw *claw, int order);
  ~dgSystemOfEquations();
  
private:
};

#endif // _DG_SYSTEM_OF_EQUATIONS_

