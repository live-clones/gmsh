#include "luaFunction.h"
#if defined(HAVE_LUA)
#include <string>
#include <vector>
#include "function.h"
// function that is defined in Lua

class functionLua : public function {
  lua_State *_L;
  std::string _luaFunctionName;
  std::vector<std::string> _dependenciesName;
  int _nbCol;
 private:
  class data : public dataCacheDouble{
    private:    
    const functionLua *_function;
    std::vector<dataCacheDouble *> _dependencies;
    public:
    data(const functionLua *f, dataCacheMap *m):
      dataCacheDouble(m->getNbEvaluationPoints(),f->_nbCol),
      _function(f)    
    {
      _dependencies.resize ( _function->_dependenciesName.size());
      for (int i=0;i<_function->_dependenciesName.size();i++)
        _dependencies[i] = &m->get(_function->_dependenciesName[i],this);
    }
    void _eval()
    {
      lua_getfield(_function->_L, LUA_GLOBALSINDEX, _function->_luaFunctionName.c_str());
      for (int i=0;i< _dependencies.size();i++){
        const fullMatrix<double> *data = &(*_dependencies[i])();
        lua_pushlightuserdata (_function->_L, (void*) data);
      }
      lua_pushlightuserdata (_function->_L, &_value);
      lua_call(_function->_L,_dependencies.size()+1,0);  /* call Lua function */
    }
  };
 public:
  functionLua (int nbCol,
	       std::string &luaFunctionName,
	       std::vector<std::string> &dependenciesName,
	       lua_State *L)
    : _luaFunctionName(luaFunctionName), _dependenciesName(dependenciesName),_L(L),_nbCol(nbCol)
  {
  }

  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return new data(this,m);
  }
};

static int newLuaFunction (lua_State *L){
  int n = lua_gettop(L);  
  std::vector<std::string> dependenciesName;
  int nbFields = luaL_checkinteger(L, 1); 
  std::string luaFunctionName = std::string(luaL_checkstring(L, 2)); 
  for (int i=3;i<=n;i++)
    dependenciesName.push_back(std::string(luaL_checkstring(L, i)));
  int ITER = 1;
  std::string functionName = luaFunctionName;
  while (function::get(functionName, true)){
    char toto[256];
    sprintf(toto,"%d",ITER);
    functionName = luaFunctionName + toto;
  }
  function::add(functionName,new functionLua(nbFields,luaFunctionName,dependenciesName,L));   
  lua_pushstring(L, functionName.c_str());
  
  return 1;
}

static int newConstantFunction (lua_State *L){
  fullMatrix<double> * _ud = Luna<fullMatrix<double> >::check(L, 1);
  int ITER = 1;
  std::string functionName = "ConstantFunction";
  while (function::get(functionName, true)){
    char toto[256];
    sprintf(toto,"%d",ITER);
    functionName = functionName + toto;
  }  

  function::add(functionName,function::newFunctionConstant(*_ud));    
  lua_pushstring(L, functionName.c_str());  
  return 1;
}

int RegisterFunctions (lua_State *L) {
  luaL_reg fcts[] = {{"lua",   newLuaFunction },
		     {"constant",   newConstantFunction },
         {0,0}};
  luaL_register(L, "createFunction", fcts);  
};



#endif // HAVE LUA
