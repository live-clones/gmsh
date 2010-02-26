#include "GmshConfig.h"
#ifdef HAVE_LUA
#include <iostream>
#include <string>
#include "Gmsh.h"
#include "Context.h"
#include "MVertex.h"
#include "MElement.h"
#include "GFace.h"
#include "DivideAndConquer.h"
#include "Bindings.h"
#include "luaFunction.h"
#include "function.h"
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgDofContainer.h"
#include "dgConservationLawShallowWater2d.h"
#include "dgConservationLawAdvection.h"
#include "dgConservationLawPerfectGas.h"
#include "dgConservationLawWaveEquation.h"
#include "dgConservationLawMaxwell.h"
#include "dgRungeKutta.h"
#include "dgSystemOfEquations.h"
#include "dgLimiter.h"
#include "Bindings.h"
#include "dgResidual.h"

extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

#ifdef HAVE_READLINE
#include "readline.h"
#include "history.h"
#endif

//trivial class to bind options
class gmshOptions {
  public:
  gmshOptions(){};
  void colorSet(std::string category, int index, std::string name, int value) {
    GmshSetOption(category,name,(unsigned int)(value), index);
  }
  int colorGet(std::string category, int index, std::string name) {
    unsigned int value;
    GmshGetOption(category, name, value, index);
    return value;
  }
  double numberGet(std::string category, int index, std::string name) {
    double value;
    GmshGetOption(category, name, value, index);
    return value;
  }
  void numberSet(std::string category, int index, std::string name, double value) {
    GmshSetOption(category, name, value, index);
  }
  std::string stringGet(std::string category, int index, std::string name) {
    std::string value;
    GmshGetOption(category, name, value, index);
    return value;
  }
  void stringSet(std::string category, int index, std::string name, double value) {
    GmshSetOption(category, name, value, index);
  }
  static void registerBindings(binding *b) {
    classBinding *cb = b->addClass<gmshOptions>("gmshOptions");
    cb->setDescription("access the gmsh option database");
    methodBinding *mb;
    mb = cb->addMethod("colorSet", &gmshOptions::colorSet);
    mb->setDescription("set the value of a color (unsigned int) option. This is equivalent to category[index].name = value");
    mb->setArgNames("category","index","name","value",NULL);
    mb = cb->addMethod("colorGet", &gmshOptions::colorGet);
    mb->setDescription("return the value of a color (unsigned int) option. This is equivalent to category[index].name");
    mb->setArgNames("category","index","name",NULL);
    mb = cb->addMethod("numberSet", &gmshOptions::numberSet);
    mb->setDescription("set the value of a number option. This is equivalent to category[index].name = value");
    mb->setArgNames("category","index","name","value",NULL);
    mb = cb->addMethod("numberGet", &gmshOptions::numberGet);
    mb->setDescription("return the value of a number option. This is equivalent to category[index].name");
    mb->setArgNames("category","index","name",NULL);
    mb = cb->addMethod("srtingSet", &gmshOptions::stringSet);
    mb->setDescription("set the value of a string option. This is equivalent to category[index].name = \"value\"");
    mb->setArgNames("category","index","name","value",NULL);
    mb = cb->addMethod("srtingGet", &gmshOptions::stringGet);
    mb->setDescription("return the value of a string option. This is equivalent to category[index].name");
    mb->setArgNames("category","index","name",NULL);
    mb = cb->setConstructor<gmshOptions>();
    mb->setDescription("an instance of gmshOptions is needed to access the database");
  }
};

static void reportErrors(lua_State *L, int status)
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

static void printMethod(std::string name, luaMethodBinding *mb, bool isConstructor=false) {
  std::vector<std::string> argTypeNames;
  mb->getArgTypeNames(argTypeNames);
  std::cout<<"  ";
  if(!isConstructor)
    std::cout<<colorBold<<argTypeNames[0];
  std::cout<<colorBlue<<" "<<name<<colorDefault<<colorBold<<" (";
  int count=0;
  for(int i=1;i< argTypeNames.size(); i++){
    if(argTypeNames[i]=="-1")
      continue;
    if(count!=0)
      std::cout<<", ";
    std::cout<<colorBold<<argTypeNames[i]<<colorDefault;
    if(mb->getArgNames().size()>count)
      std::cout<<" "<<mb->getArgNames()[count];
    count++;
  }
  std::cout<<colorBold<<")\n"<<colorDefault;
  const std::string description=mb->getDescription();
  std::cout<<(description.empty()?"no help available":description) <<"\n";

}
static void listMethods(classBinding *cb){
  if(cb->methods.size())
    std::cout<<colorGreen<<"Methods from "<<cb->getClassName()<<colorDefault<<"\n";
  for(std::map<std::string,luaMethodBinding *>::iterator it = cb->methods.begin(); it!=cb->methods.end(); it++){
    printMethod(it->first,it->second);
  }
  if(cb->getParent())
    listMethods(cb->getParent());
}

static int luaHelp (lua_State *L){
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
    if(cb->getConstructor()){
      std::cout<<colorGreen<<"Constructor"<<colorDefault<<"\n";
      printMethod(className,cb->getConstructor(),true);
      std::cout<<"\n";
    }
    listMethods(cb);
    std::cout<<"\n";
    if(cb->children.size()){
      std::cout<<colorGreen<<"Children of "<<cb->getClassName()<<colorDefault<<"\n";
      for(std::set<classBinding *>::iterator it = cb->children.begin(); it!=cb->children.end(); it++){
        std::cout<<"  "<<colorBlue<<(*it)->getClassName()<<colorDefault<<" : ";
        const std::string description=(*it)->getDescription();
        std::cout<<(description.empty()?"no help available":description) <<"\n";
      }
      std::cout<<"\n";
    }
  }
  return 0;
}


#ifdef HAVE_READLINE
static int luaSave (lua_State *L){
  const char *filename = luaL_checkstring(L,1);
  write_history(filename);
  return 0;
}
static int luaClear (lua_State *L){
  clear_history();
  return 0;
}
#endif

int binding::readFile(const char *filename)
{
  int lock = CTX::instance()->lock;
  CTX::instance()->lock = 0;
  checkDocCompleteness();
  int s = luaL_loadfile(L, filename);
  if ( s==0 ) {
    Msg::Info("lua executes %s",filename);
    s = lua_pcall(L, 0, LUA_MULTRET, 0);
  }
  reportErrors(L, s);
  lua_close(L);
  CTX::instance()->lock = lock;
  return (s==0);
}

static int countInArguments(const std::vector<std::string> &types){
  int c=0;
  for(int i=1;i<types.size();i++)
    c+=(types[i]!="-1");
  return c;
}

void binding::checkDocCompleteness(){
  int nBad = 0;
  for(std::map<std::string,classBinding *>::iterator cb = classes.begin(); cb!=classes.end();cb++) {
    if(cb->second->getDescription().empty()){
      Msg::Error("binded class %s has no description.", cb->first.c_str());
      nBad++;
    }
    luaMethodBinding *constructor = cb->second->getConstructor();
    if(constructor){
      if(constructor->getDescription().empty()){
        Msg::Error("binded constructor of class %s has no description.", cb->first.c_str());
        nBad++;
      }
      std::vector<std::string> argTypeNames;
      constructor->getArgTypeNames(argTypeNames);
      int nTypeArg = countInArguments(argTypeNames);
      int nDocArg = constructor->getArgNames().size();
      if(nTypeArg != nDocArg){
        Msg::Error("binded constructor of class %s takes %i arguments but %i are documented.",
          cb->first.c_str(), nTypeArg, nDocArg);
        nBad++;
      }
    }
    for(std::map<std::string,luaMethodBinding*>::iterator mb = cb->second->methods.begin(); mb != cb->second->methods.end(); mb++){
      if(mb->second->getDescription().empty()){
        Msg::Error("binded method %s.%s has no description.", cb->first.c_str(),mb->first.c_str());
        nBad++;
      }
      std::vector<std::string> argTypeNames;
      mb->second->getArgTypeNames(argTypeNames);
      int nTypeArg = countInArguments(argTypeNames);
      int nDocArg = mb->second->getArgNames().size();
      if(nTypeArg != nDocArg){
        Msg::Error("binded method %s.%s takes %i arguments but %i are documented.",
          cb->first.c_str(),mb->first.c_str(), nTypeArg, nDocArg);
        nBad++;
      }
    }
  }
  if(nBad!=0){
    Msg::Error("Bindings documentation is not complete (%i error(s) ). To enforce documentation completeness, I will exit now. Please complete the documentation and run gmsh again ;-) .\n",nBad);
    exit(1);
  }
    
}

void binding::interactiveSession()
{
  int lock = CTX::instance()->lock;
  CTX::instance()->lock = 0;
  checkDocCompleteness();

  Msg::Info("Starting interactive lua session, press Ctrl-D to exit"); 
#ifdef HAVE_READLINE
  using_history();
  while (const char *line=readline("lua> ")){
    char *expansion=NULL;
    int r=history_expand((char*)line,&expansion);
    if(r)
      std::cout<<expansion<<"\n";
    if((r==0 || r==1)&& expansion){
      add_history(expansion);
      reportErrors(L, luaL_dostring(L, expansion));
    }
    if(expansion)
      free(expansion);
  }
  clear_history();
#else
  std::string line;
  while(std::cout<<"lua> ",
        getline(std::cin,line) ){
    reportErrors(L, luaL_dostring(L, line.c_str()));
  }
#endif
  CTX::instance()->lock = lock;
}

binding::binding(){
  if(_instance){
    Msg::Error("Only one instance of lua bindings is allowed");
  }
  _instance=this;
  L = lua_open();
  /*
  luaopen_base(L);
  luaopen_table(L);
  luaopen_os(L);
  //luaopen_io(L);
  luaopen_string(L);
  luaopen_math(L);
  luaopen_debug(L);
  */
  luaL_openlibs(L);

  lua_register(L,"help",luaHelp);
  #ifdef HAVE_READLINE
  lua_register(L,"saveHistory",luaSave);
  lua_register(L,"clearHistory",luaClear);
  #endif

  //  lua_pushcfunction(L, luaopen_io);
  //  lua_call(L, 0, 0);

  // Register Lua bindings
  DocRecord::registerBindings(this);
  GEntity::registerBindings(this);
  GEdge::registerBindings(this);
  GFace::registerBindings(this);
  GModel::registerBindings(this);
  GRegion::registerBindings(this);
  GVertex::registerBindings(this);
  MElement::registerBindings(this);
  MVertex::registerBindings(this);
  dgBoundaryCondition::registerBindings(this);
  dgConservationLaw::registerBindings(this);
  dgConservationLawAdvectionDiffusionRegisterBindings(this);
   dgConservationLawMaxwellRegisterBindings(this);
  dgConservationLawShallowWater2dRegisterBindings(this);
  dgConservationLawWaveEquationRegisterBindings(this);
  dgDofContainer::registerBindings(this);
  dgGroupCollection::registerBindings(this);
  dgLimiter::registerBindings(this);
  dgPerfectGasLaw2dRegisterBindings(this);
  dgResidual::registerBindings(this);
  dgRungeKutta::registerBindings(this);
  dgSlopeLimiterRegisterBindings(this);
  dgSystemOfEquations::registerBindings(this);
  fullMatrix<double>::registerBindings(this);
  function::registerBindings(this);
  function::registerDefaultFunctions();
  functionLua::registerBindings(this);
  gmshOptions::registerBindings(this);
}
binding *binding::_instance=NULL;
#endif
