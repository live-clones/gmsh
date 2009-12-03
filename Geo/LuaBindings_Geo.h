#ifndef _LUA_BINDINGS_GEO_
#define _LUA_BINDINGS_GEO_
#include "GmshConfig.h"

#if defined(HAVE_LUA)
// include lua stuff
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
// Use luna for bindings
#include "luna.h"
// The header file for the GModel
#include "GModel.h"

// we do not use the GModel::current() 
// this should not be a class anyway ...
// this should be removed !!!!!! and be put
// inside GModel itself
class LuaGModel{
  GModel *_gm;
public:
  static const char className[];
  static Luna<LuaGModel>::RegType methods[];
  static void Register(lua_State *L);
  LuaGModel(lua_State *L);
  ~LuaGModel();
  // Methods we will bind
  int load (lua_State *L); // load a file
  int mesh (lua_State *L); // make the mesh
  int save (lua_State *L); // save a file
  GModel * getGModel () const {return _gm;}
private:
};

#endif // HAVE LUA

#endif // _LUA_BINDINGS_GEO_
