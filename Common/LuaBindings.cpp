#include "GmshConfig.h"
#ifdef HAVE_LUA
#include <iostream>
#include "Gmsh.h"
#include "Bindings.h"
#include "dgSystemOfEquations.h"
#include "luaFunction.h"
#include "function.h"
#include "dgGroupOfElements.h"
#include "dgConservationLawShallowWater2d.h"
#include "dgConservationLawAdvection.h"
#include "dgConservationLawPerfectGas.h"
#include "dgConservationLawWaveEquation.h"
extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}
void report_errors(lua_State *L, int status)
{
  if ( status!=0 ) {
    std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1); // remove error message
  }
}
int read_lua(const char *filename)
{
  lua_State *L = lua_open();
  luaopen_base(L);
  luaopen_table(L);
  luaopen_os(L);
  //luaopen_io(L);
  luaopen_string(L);
  luaopen_math(L);
  luaopen_debug(L);
  binding b;
  b.L=L;

  // Register Lua bindings
  GModel::registerBindings(&b);
  dgSystemOfEquations::registerBindings(&b);
  dgBoundaryCondition::registerBindings(&b);
  dgConservationLaw::registerBindings(&b);
  dgConservationLawShallowWater2dRegisterBindings(&b);
  dgConservationLawWaveEquationRegisterBindings(&b);
  dgConservationLawAdvectionRegisterBindings(&b);
  dgPerfectGasLaw2dRegisterBindings(&b);
  fullMatrix<double>::registerBindings(&b);
  function::registerBindings(&b);
  functionLua::registerBindings(&b);
  function::registerDefaultFunctions();

  int s = luaL_loadfile(L, filename);

  if ( s==0 ) {
    printf("lua executes %s\n",filename);
    s = lua_pcall(L, 0, LUA_MULTRET, 0);
  }
  report_errors(L, s);

  lua_close(L);
  return (s==0);
}
#endif
