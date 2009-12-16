#ifndef _BINDINGS_H_
#define _BINDINGS_H_

#ifndef HAVE_LUA //no bindings

class methodBinding{};
class constructorBinding{};
template <class objectType, class returnType=void, class arg0Type=void, class arg1Type=void, class arg2Type=void, class arg3Type=void>
class methodBindingTemplate:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type,arg1Type,arg2Type,arg3Type);
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType, class returnType, class arg0Type, class arg1Type, class arg2Type>
class methodBindingTemplate<objectType,returnType,arg0Type,arg1Type,arg2Type,void>:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type,arg1Type,arg2Type);
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType, class returnType, class arg0Type, class arg1Type>
class methodBindingTemplate<objectType,returnType,arg0Type,arg1Type,void,void>:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type,arg1Type);
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType, class returnType, class arg0Type>
class methodBindingTemplate<objectType,returnType,arg0Type,void,void,void>:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type);
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType, class returnType>
class methodBindingTemplate<objectType,returnType,void,void,void,void>:public methodBinding {
  typedef returnType (objectType::*callback)();
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType, class arg0Type, class arg1Type, class arg2Type>
class methodBindingTemplate<objectType,void,arg0Type,arg1Type,arg2Type,void>:public methodBinding {
  typedef void (objectType::*callback)(arg0Type,arg1Type,arg2Type);
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType, class arg0Type, class arg1Type>
class methodBindingTemplate<objectType,void,arg0Type,arg1Type,void,void>:public methodBinding {
  typedef void (objectType::*callback)(arg0Type,arg1Type);
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType, class arg0Type>
class methodBindingTemplate<objectType,void,arg0Type,void,void,void>:public methodBinding {
  typedef void (objectType::*callback)(arg0Type);
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template <class objectType>
class methodBindingTemplate<objectType,void,void,void,void,void>:public methodBinding {
  typedef void (objectType::*callback)();
  public:
  methodBindingTemplate(const std::string luaname,callback f){}
};
template<class objectType, class arg0Type=void, class arg1Type=void, class arg2Type=void, class arg3Type=void>
class constructorBindingTemplate:public constructorBinding {};

#else // HAVE_LUA

extern "C" {
#include "lua.h"
#include "lauxlib.h"
}
#include <vector>


class methodBinding {
  public:
  std::string _luaname;
  virtual int call (lua_State *L)=0;
  methodBinding(const std::string luaname){
    _luaname=luaname;
  }
};

class constructorBinding {
  public:
  virtual int call (lua_State *L)=0;
};


// this class is largely copied from luna
// todo : add  reference to luna and check luna  licence
template <typename T> class classBinding {
  typedef struct { T *pT; bool owned;} userdataType;
public:
  static void push(lua_State *L, T* obj, bool owned) {
    userdataType *ud = static_cast<userdataType*>(lua_newuserdata(L, sizeof(userdataType)));
    ud->pT=obj;
    ud->owned=owned;
    luaL_getmetatable(L, T::className);  // lookup metatable in Lua registry
    lua_setmetatable(L, -2);
  }
  static void Register(lua_State *L) {
    lua_newtable(L);              
    int methods = lua_gettop(L); //-- create methods , i.e. the class itself

    luaL_newmetatable(L, T::className); 
    int metatable = lua_gettop(L);     // -- create metatable of methods

    // store method table in globals so that
    // scripts can add functions written in Lua.
    lua_pushstring(L, T::className);
    lua_pushvalue(L, methods);
    lua_settable(L, LUA_GLOBALSINDEX); // -- global[T::className] = methods

//    lua_pushliteral(L, "__metatable");
//    lua_pushvalue(L, methods);
//    lua_settable(L, metatable);  // hide metatable from Lua getmetatable()

    lua_pushliteral(L, "__index");
    lua_pushvalue(L, methods);
    lua_settable(L, metatable);  // metatable.__index=methods

    lua_pushliteral(L, "__tostring");
    lua_pushcfunction(L, tostring_T);
    lua_settable(L, metatable);

    lua_pushliteral(L, "__gc");
    lua_pushcfunction(L, gc_T);
    lua_settable(L, metatable);

    lua_newtable(L);                // mt for method table
    int mt = lua_gettop(L);
    lua_pushliteral(L, "__call");
    lua_pushlightuserdata(L,(void*)T::constructorMethod);
    lua_pushcclosure(L, callConstructor, 1);

    lua_pushliteral(L, "new");
    lua_pushvalue(L, -2);           // dup new_T function
    lua_settable(L, methods);       // add new_T to method table
    lua_settable(L, mt);            // mt.__call = new_T

    if(T::parentClassName!=std::string("")){
      lua_pushliteral(L,"__index");
      lua_pushstring(L,T::parentClassName);
      lua_gettable(L,LUA_GLOBALSINDEX);
      lua_settable(L,mt);           // mt.__index = global[T::parentClassName] // this is the inheritance bit
    }
    lua_setmetatable(L, methods); // setmetatable(methods, mt)

    // fill method table with methods from class T
    for (methodBinding **l = T::methods; *l; l++) {
      lua_pushstring(L, (*l)->_luaname.c_str());
      lua_pushlightuserdata(L, (void*)*l);
      lua_pushcclosure(L, callMethod, 1);
      lua_settable(L, methods); //methods.(l->name) = callMethod(l)
    } 
    lua_pop(L, 2);  // drop metatable and method table
  }

  // get userdata from Lua stack and return pointer to T object
  static T *check(lua_State *L, int narg) {
    userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, narg));
    if(!ud) luaL_typerror(L, narg, T::className);
    return ud->pT;  // pointer to T object*/
  }

private:
  classBinding();  // hide default constructor

  // member function dispatcher
  static int callMethod(lua_State *L) {
    methodBinding *l = static_cast<methodBinding*>(lua_touserdata(L, lua_upvalueindex(1)));
    return l->call(L);  // call member function
  }
  static int callConstructor(lua_State *L) {
    constructorBinding *l = static_cast<constructorBinding*>(lua_touserdata(L, lua_upvalueindex(1)));
    if(!l){
      printf("this class does not have constructor\n");
      //throw();
    }
    return l->call(L);  // call member function
  }

  // garbage collection metamethod
  static int gc_T(lua_State *L) {
    userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
    /*if(ud->owned) //disable gc 
      delete ud->pT;  // call destructor for T objects*/
    return 0;
  }

  static int tostring_T (lua_State *L) {
    char buff[32];
    userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
    T *t = static_cast<T*>(lua_touserdata(L, 1));
    sprintf(buff, "%p", ud->pT);
    lua_pushfstring(L, "%s (%s)", T::className, buff);
    return 1;
  }
};

template<class type>
class lua_template {
  public:
  static type get(lua_State *L, int ia){
    printf("error cannot get generic class in lua, only pointers are implemented\n");
  }
  static void push(lua_State *L, type obj){
    printf("error cannot push generic class in lua, only pointers are implemented\n");
  }
};

template <class type>
class lua_template<type*>{
  public:
  static type* get(lua_State *L, int ia){
    type *a=classBinding<type>::check(L,ia);
    return a;

  }
  static void push(lua_State *L, type *obj){
    classBinding<type>::push(L,obj,false);
  }
};

template<>
class lua_template<lua_State *>{
  public:
  static lua_State *get(lua_State *L, int ia){
    return L;
  }
  static void push(lua_State *L, int i){
    printf("error cannot push a lua_State in lua\n");
  }
};

template<>
class lua_template<int>{
  public:
  static int get(lua_State *L, int ia){
    int a= luaL_checkint(L,ia);
    return a;
  }
  static void push(lua_State *L, int i){
    lua_pushinteger(L,i);
  }
};

template<class type>
class lua_template<std::vector<type > >{
  public:
  static std::vector<type>  get(lua_State *L, int ia){
    std::vector<type> v;
    size_t size=lua_objlen(L,ia);
    v.resize(size);
    for(size_t i=0;i<size;i++){
      lua_pushinteger(L,i+1);
      lua_gettable(L,ia);
      v[i]=lua_template<type>::get(L,-1);
      lua_pop(L,1);
    }
    return v;
  }
  static void push(lua_State *L, std::vector<type> a){
  }
};

template<>
class lua_template<double>{
  public:
  static double get(lua_State *L, int ia){
    return luaL_checknumber(L,ia);
  }
  static void push(lua_State *L, double v){
    lua_pushnumber(L,v);
  }
};

template<>
class lua_template<std::string>{
  public:
  static std::string get(lua_State *L, int ia){
    return luaL_checkstring(L,ia);
  }
  static void push(lua_State *L, std::string s){
    lua_pushstring(L,s.c_str());
  }
};

//full : 4 args with return
template <class objectType, class returnType=void, class arg0Type=void, class arg1Type=void, class arg2Type=void, class arg3Type=void>
class methodBindingTemplate:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type,arg1Type,arg2Type,arg3Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    arg1Type a1 = lua_template<arg1Type>::get(L,3);
    arg2Type a2 = lua_template<arg2Type>::get(L,4);
    arg3Type a3 = lua_template<arg3Type>::get(L,5);
    returnType r=(obj->*(_f))(a0,a1,a2,a3);
    lua_template<returnType>::push(L,r);
    return 1;
  }
};
//3 args with return
template <class objectType, class returnType, class arg0Type, class arg1Type, class arg2Type>
class methodBindingTemplate<objectType,returnType,arg0Type,arg1Type,arg2Type,void>:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type,arg1Type,arg2Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    arg1Type a1 = lua_template<arg1Type>::get(L,3);
    arg2Type a2 = lua_template<arg2Type>::get(L,4);
    returnType r=(obj->*(_f))(a0,a1,a2);
    lua_template<returnType>::push(L,r);
    return 1;
  }
};
//2 args with return
template <class objectType, class returnType, class arg0Type, class arg1Type>
class methodBindingTemplate<objectType,returnType,arg0Type,arg1Type,void,void>:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type,arg1Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    arg1Type a1 = lua_template<arg1Type>::get(L,3);
    returnType r=(obj->*(_f))(a0,a1);
    lua_template<returnType>::push(L,r);
    return 1;
  }
};
//1 arg with return
template <class objectType, class returnType, class arg0Type>
class methodBindingTemplate<objectType,returnType,arg0Type,void,void,void>:public methodBinding {
  typedef returnType (objectType::*callback)(arg0Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    returnType r=(obj->*(_f))(a0);
    lua_template<returnType>::push(L,r);
    return 1;
  }
};
//0 arg with return
template <class objectType, class returnType>
class methodBindingTemplate<objectType,returnType,void,void,void,void>:public methodBinding {
  typedef returnType (objectType::*callback)();
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    returnType r=(obj->*(_f))();
    lua_template<returnType>::push(L,r);
    return 1;
  }
};
//4 args without return
template <class objectType, class arg0Type, class arg1Type, class arg2Type, class arg3Type>
class methodBindingTemplate<objectType,void,arg0Type,arg1Type,arg2Type,arg3Type>:public methodBinding {
  typedef void (objectType::*callback)(arg0Type,arg1Type,arg2Type,arg3Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    arg1Type a1 = lua_template<arg1Type>::get(L,3);
    arg2Type a2 = lua_template<arg2Type>::get(L,4);
    arg3Type a3 = lua_template<arg3Type>::get(L,5);
    (obj->*(_f))(a0,a1,a2,a3);
    return 0;
  }
};
//3 args without return
template <class objectType, class arg0Type, class arg1Type, class arg2Type>
class methodBindingTemplate<objectType,void,arg0Type,arg1Type,arg2Type,void>:public methodBinding {
  typedef void (objectType::*callback)(arg0Type,arg1Type,arg2Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    arg1Type a1 = lua_template<arg1Type>::get(L,3);
    arg2Type a2 = lua_template<arg2Type>::get(L,4);
    (obj->*(_f))(a0,a1,a2);
    return 0;
  }
};
//2 args without return
template <class objectType, class arg0Type, class arg1Type>
class methodBindingTemplate<objectType,void,arg0Type,arg1Type,void,void>:public methodBinding {
  typedef void (objectType::*callback)(arg0Type,arg1Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    arg1Type a1 = lua_template<arg1Type>::get(L,3);
    (obj->*(_f))(a0,a1);
    return 0;
  }
};
//1 arg without return
template <class objectType, class arg0Type>
class methodBindingTemplate<objectType,void,arg0Type,void,void,void>:public methodBinding {
  typedef void (objectType::*callback)(arg0Type);
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,2);
    (obj->*(_f))(a0);
    return 0;
  }
};
//0 arg without return
template <class objectType>
class methodBindingTemplate<objectType,void,void,void,void,void>:public methodBinding {
  typedef void (objectType::*callback)();
  callback _f;
  public:
  methodBindingTemplate(const std::string luaname,callback f):methodBinding(luaname){
    _f=f;
  }
  int call (lua_State *L) {
    objectType *obj = classBinding<objectType>::check(L,1);
    (obj->*(_f))();
    return 0;
  }
};

//constructor 4 args
template<class objectType, class arg0Type=void, class arg1Type=void, class arg2Type=void, class arg3Type=void>
class constructorBindingTemplate:public constructorBinding {
  int call (lua_State *L){
    lua_remove(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,1);
    arg1Type a1 = lua_template<arg1Type>::get(L,2);
    arg2Type a2 = lua_template<arg2Type>::get(L,3);
    arg3Type a3 = lua_template<arg3Type>::get(L,4);
    classBinding<objectType>::push(L, new objectType(a0,a1,a2,a3),true);
    return 1;
  }
};
//constructor 3 args
template<class objectType, class arg0Type, class arg1Type, class arg2Type>
class constructorBindingTemplate<objectType,arg0Type,arg1Type,arg2Type,void>:public constructorBinding {
  int call (lua_State *L){
    lua_remove(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,1);
    arg1Type a1 = lua_template<arg1Type>::get(L,2);
    arg2Type a2 = lua_template<arg2Type>::get(L,3);
    classBinding<objectType>::push(L, new objectType(a0,a1,a2),true);
    return 1;
  }
};
//constructor 2 args
template<class objectType, class arg0Type, class arg1Type>
class constructorBindingTemplate<objectType,arg0Type,arg1Type,void,void>:public constructorBinding {
  int call (lua_State *L){
    lua_remove(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,1);
    arg1Type a1 = lua_template<arg1Type>::get(L,2);
    classBinding<objectType>::push(L,new objectType(a0,a1),true);
    return 1;
  }
};
//constructor 1 args
template<class objectType, class arg0Type>
class constructorBindingTemplate<objectType,arg0Type,void,void,void>:public constructorBinding {
  int call (lua_State *L){
    lua_remove(L,1);
    arg0Type a0 = lua_template<arg0Type>::get(L,1);
    classBinding<objectType>::push(L, new objectType(a0),true);
    return 1;
  }
};
//constructor 0 args
template<class objectType>
class constructorBindingTemplate<objectType,void,void,void,void>:public constructorBinding {
  int call (lua_State *L){
    lua_remove(L,1);
    classBinding<objectType>::push(L, new objectType(),true);
    return 1;
  }
};
#endif
#endif
