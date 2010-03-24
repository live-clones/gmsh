#include "GmshConfig.h"
#ifndef _LUA_FUNCTION_H_
#define _LUA_FUNCTION_H_
#if defined(HAVE_LUA)
class binding;
void functionLuaRegisterBindings(binding *b);
#endif // HAVE LUA
#endif // _LUA_FUNCTION_H_
