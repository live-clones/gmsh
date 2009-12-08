#include "GmshConfig.h"
#ifndef _LUA_FUNCTION_H_
#define _LUA_FUNCTION_H_
#if defined(HAVE_LUA)
// include lua stuff
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
int RegisterFunctions (lua_State *L);
#endif // HAVE LUA
#endif // _LUA_FUNCTION_H_
