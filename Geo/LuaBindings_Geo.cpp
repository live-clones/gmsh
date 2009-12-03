#include "LuaBindings_Geo.h"
#include "OpenFile.h"
#include "CreateFile.h"
// define the name of the object that will be used
// in Lua

const char LuaGModel::className[] = "GModel";

// Define the methods we will expose to Lua
#define _method(class, name) {#name, &class::name}

Luna<LuaGModel>::RegType LuaGModel::methods[] = {
   _method(LuaGModel, mesh),
   _method(LuaGModel, load),
   _method(LuaGModel, save),
   {0,0}
};

LuaGModel::LuaGModel(lua_State *L){
  _gm = new GModel;
}

LuaGModel::~LuaGModel(){
  delete _gm;
}

void LuaGModel::Register (lua_State *L){
  Luna<LuaGModel>::Register(L);
}

int LuaGModel::load(lua_State *L){
  GModel *temp = GModel::current();
  GModel::setCurrent(_gm);
  MergeFile(luaL_checkstring(L, 1));
  GModel::setCurrent(temp);
  return 1;
}

int LuaGModel::mesh(lua_State *L){
  _gm -> mesh((int)luaL_checknumber(L, 1));
  return 1;
}

int LuaGModel::save(lua_State *L){
  GModel *temp = GModel::current();
  GModel::setCurrent(_gm);
  int guess = GuessFileFormatFromFileName(std::string(lua_tostring(L, 1)));
  CreateOutputFile (std::string(lua_tostring(L, 1)), guess);
  GModel::setCurrent(temp);
  return 1;
}
