// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SIMPLE_FUNCTION_H_
#define _SIMPLE_FUNCTION_H_

// FIXME: Numeric/ should not depend on Geo/
#include "MElement.h"

template <class scalar>
class simpleFunction {
 protected:
  scalar _val;
 public :
  simpleFunction(scalar val=0.0) : _val(val) {}
  virtual ~simpleFunction(){}
  virtual scalar operator () (double x, double y, double z) const { return _val; }
  virtual void gradient (double x, double y, double z,
			 scalar & dfdx, scalar & dfdy, scalar & dfdz) const
  { dfdx = dfdy = dfdz = 0.0; }
/*  virtual scalar operator () (double x, double y, double z,MElement *e) const { return _val; }
  virtual void gradient (double x, double y, double z,
			 scalar & dfdx, scalar & dfdy, scalar & dfdz, MElement *e) const
  { dfdx = dfdy = dfdz = 0.0; }*/
};

#include "GmshConfig.h"
#ifdef HAVE_LUA
#include "LuaBindings.h"
template <class scalar>
class simpleFunctionLua : public simpleFunction<scalar> {
  lua_State *_L;
  std::string _luaFunctionName;
 public:
  scalar operator () (double x, double y, double z) const
  {
    lua_getfield(_L, LUA_GLOBALSINDEX, _luaFunctionName.c_str());
    luaStack<double>::push(_L, x);
    luaStack<double>::push(_L, y);
    luaStack<double>::push(_L, z);
    lua_call(_L, 3, 1);
    return luaStack<scalar>::get(_L,-1);
  }
  simpleFunctionLua (lua_State *L, const std::string luaFunctionName, scalar s)
    : simpleFunction<scalar>(s)
  {
    _L = L;
    _luaFunctionName = luaFunctionName;
  }
};
#endif

template <class scalar>
class simpleFunctionOnElement : public simpleFunction<scalar>
{
  MElement *_e;
 public :
  simpleFunctionOnElement(scalar val=0) : simpleFunction<scalar>(val),_e(0) {}
  virtual ~simpleFunctionOnElement(){}
  void setElement(MElement *e) { _e = e; }
  MElement * getElement(void) const { return _e; }
  MElement * getElement(double x, double y, double z) const
  {
    if (_e) return _e;
    else
    {// search
    }
  }
};

#endif
