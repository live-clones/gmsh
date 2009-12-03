#include <iostream>
#include "Gmsh.h"
#include "LuaBindings_Geo.h"
#include "dgSystemOfEquations.h"
#include "function.h"

void report_errors(lua_State *L, int status)
{
  if ( status!=0 ) {
    std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1); // remove error message
  }
}

int main(int argc, char *argv[])
{
  GmshInitialize(argc,argv);
  lua_State *L = lua_open();
  luaopen_base(L);
  luaopen_table(L);
  //luaopen_io(L);
  luaopen_string(L);
  luaopen_math(L);
  luaopen_debug(L);

  // Register GModel bindings
  LuaGModel::Register(L);
  dgSystemOfEquations::Register(L);
  fullMatrix<double>::Register(L);
  function::registerDefaultFunctions();

  int s = luaL_loadfile(L, argv[1]);

  if ( s==0 ) {
    printf("lua executes %s\n",argv[1]);
    s = lua_pcall(L, 0, LUA_MULTRET, 0);
  }
  report_errors(L, s);

  lua_close(L);
  return 0;
}
