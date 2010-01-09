#include "GmshConfig.h"
#ifdef HAVE_LUA
#include <iostream>
#include <string>
#include "Gmsh.h"
#include "MVertex.h"
#include "MElement.h"
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

#ifdef HAVE_READLINE
#include "readline.h"
#include "history.h"
#endif

static void report_errors(lua_State *L, int status)
{
  if ( status!=0 ) {
    std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1); // remove error message
  }
}

const char *colorRed = "\033[1;31m";
const char *colorGreen = "\033[1;32m";
const char *colorBlue = "\033[1;34m";
const char *colorDefault = "\033[0m";
const char *colorBold = "\033[1m";

static void list_methods(classBinding *cb){
  if(cb->methods.size())
    std::cout<<colorBold<<"Methods from "<<cb->getClassName()<<colorDefault<<"\n";
  for(std::map<std::string,luaMethodBinding *>::iterator it = cb->methods.begin(); it!=cb->methods.end(); it++){
    std::cout<<colorBlue<<"  "<<it->first<<colorDefault<<" : ";
    const std::string description=it->second->getDescription();
    std::cout<<(description.empty()?"no help available":description) <<"\n";
  }
  if(cb->getParent())
    list_methods(cb->getParent());
}

static int lua_help (lua_State *L){
  int argc = lua_gettop(L);
  binding *b = binding::instance();
  if (argc==0){
    std::cout<<"this is the gmsh help\n";
    for(std::map<std::string,classBinding *>::iterator it = b->classes.begin(); it!=b->classes.end(); it++){
      if(it->second->getParent())
        continue;
      std::cout<<colorBlue<<"  "<<it->first<<colorDefault<<" : ";
      const std::string description=it->second->getDescription();
      std::cout<<(description.empty()?"no help available":description) <<"\n";
    }
  }else{
    const char *className = luaL_checkstring(L,1);
    if(b->classes.find(className)==b->classes.end()){
      std::cout<<"Class "<<colorBold<<className<<colorDefault<<" does not exist.\n";
      return 0;
    }
    classBinding *cb = b->classes[className];
    std::cout<<"\n"<<colorRed<<className<<colorDefault<<"\n";
    const std::string description=cb->getDescription();
    std::cout<<(description.empty()?"no help available":description) <<"\n";
    std::cout<<"\n";
    list_methods(cb);
    std::cout<<"\n";
    if(cb->children.size()){
      std::cout<<colorBold<<"Children of "<<cb->getClassName()<<colorDefault<<"\n";
      for(std::set<classBinding *>::iterator it = cb->children.begin(); it!=cb->children.end(); it++){
        std::cout<<"  "<<colorGreen<<(*it)->getClassName()<<colorDefault<<" : ";
        const std::string description=(*it)->getDescription();
        std::cout<<(description.empty()?"no help available":description) <<"\n";
      }
      std::cout<<"\n";
    }
  }
  return 0;
}
#ifdef HAVE_READLINE
static int lua_save (lua_State *L){
  const char *filename = luaL_checkstring(L,1);
  write_history(filename);
  return 0;
}
static int lua_clear (lua_State *L){
  clear_history();
  return 0;
}
#endif

int binding::readFile(const char *filename)
{
  int s = luaL_loadfile(L, filename);
  if ( s==0 ) {
    Msg::Info("lua executes %s\n",filename);
    s = lua_pcall(L, 0, LUA_MULTRET, 0);
  }
  report_errors(L, s);
  lua_close(L);
  return (s==0);
}

void binding::interactiveSession(){
  Msg::Info("Starting interactive lua session, press Ctrl-D to exit"); 
  #ifdef HAVE_READLINE
  using_history();
  while (const char *line=readline("lua> ")){
    char *expansion;
    int r=history_expand((char*)line,&expansion);
    if(r)
      std::cout<<expansion<<"\n";
    if(r==0 || r==1){
      add_history(expansion);
      report_errors(L, luaL_dostring(L, expansion));
    }
    if(expansion)
      free(expansion);
  }
  clear_history();
  #else
  std::string line;
  while(std::cout<<"lua> ",
        getline(std::cin,line) ){
    report_errors(L, luaL_dostring(L, line.c_str()));
  }
  #endif
}

binding::binding(){
  if(_instance){
    Msg::Error("Only one instance of lua bindings is allowed");
  }
  _instance=this;
  L = lua_open();
  luaopen_base(L);
  luaopen_table(L);
  luaopen_os(L);
  //luaopen_io(L);
  luaopen_string(L);
  luaopen_math(L);
  luaopen_debug(L);

  lua_register(L,"help",lua_help);
  #ifdef HAVE_READLINE
  lua_register(L,"saveHistory",lua_save);
  lua_register(L,"clearHistory",lua_clear);
  #endif

  // Register Lua bindings
  GModel::registerBindings(this);
  dgSystemOfEquations::registerBindings(this);
  dgBoundaryCondition::registerBindings(this);
  dgConservationLaw::registerBindings(this);
  dgConservationLawShallowWater2dRegisterBindings(this);
  dgConservationLawWaveEquationRegisterBindings(this);
  dgConservationLawAdvectionRegisterBindings(this);
  dgPerfectGasLaw2dRegisterBindings(this);
  fullMatrix<double>::registerBindings(this);
  function::registerBindings(this);
  functionLua::registerBindings(this);
  function::registerDefaultFunctions();
  MVertex::registerBindings(this);
}
binding *binding::_instance=NULL;
#endif
