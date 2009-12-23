#include "GmshConfig.h"
#ifndef _LUA_FUNCTION_H_
#define _LUA_FUNCTION_H_
#if defined(HAVE_LUA)
#include "function.h"
class lua_State;
#include <string>
#include <vector>
class binding;
class functionLua : public function {
  lua_State *_L;
  std::string _luaFunctionName;
  std::vector<std::string> _dependenciesName;
  int _nbCol;
  class data;
 public:
  functionLua (int nbCol, std::string luaFunctionName, std::vector<std::string> dependenciesName, lua_State *L);

  dataCacheDouble *newDataCache(dataCacheMap *m);
  static void registerBindings(binding *b);
};
#endif // HAVE LUA
#endif // _LUA_FUNCTION_H_
