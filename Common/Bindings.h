#ifndef _BINDINGS_H_
#define _BINDINGS_H_
#include <string>
#include <list>
#include <typeinfo>

class methodBinding{
  public:
  void setArgNames(std::string arg1, ...){}
  void setDescription(std::string description){}
};

// c++ does not allow to take pointer to constructor. We wrap the constructor with those function so that pointer to constructor-function are available.
template <typename tObj, typename t0, typename t1, typename t2, typename t3> 
tObj *constructorPtr(t0 a0, t1 a1, t2 a2, t3 a3){
  return new tObj(a0,a1,a2,a3);
}
template <typename tObj, typename t0, typename t1, typename t2> 
tObj *constructorPtr(t0 a0, t1 a1, t2 a2){
  return new tObj(a0,a1,a2);
}
template <typename tObj, typename t0, typename t1> 
tObj *constructorPtr(t0 a0, t1 a1){
  return new tObj(a0,a1);
}
template <typename tObj, typename t0> 
tObj *constructorPtr(t0 a0){
  return new tObj(a0);
}
template <typename tObj> 
tObj *constructorPtr(){
  return new tObj();
}

#ifdef HAVE_LUA //no bindings
#include "LuaBindings.h"
#else
#include "DummyBindings.h"
#endif

#endif
