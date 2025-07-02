// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SIMPLE_FUNCTION_H
#define SIMPLE_FUNCTION_H

#include <map>

// FIXME: src/numeric/ should not depend on src/geo/
class MElement;

template <class scalar> class simpleFunction {
protected:
  scalar _val;
  bool _hasDerivatives;

public:
  simpleFunction(scalar val = 0.0) : _val(val), _hasDerivatives(false) {}
  virtual ~simpleFunction() {}
  virtual bool hasDerivatives() { return _hasDerivatives; };
  virtual scalar operator()(double x, double y, double z) const { return _val; }
  virtual void setElement(MElement *e) const {}
  virtual void gradient(double x, double y, double z, scalar &dfdx,
                        scalar &dfdy, scalar &dfdz) const
  {
    dfdx = dfdy = dfdz = 0.0;
  }
  virtual void hessian(double x, double y, double z, scalar &dfdxx,
                       scalar &dfdxy, scalar &dfdxz, scalar &dfdyx,
                       scalar &dfdyy, scalar &dfdyz, scalar &dfdzx,
                       scalar &dfdzy, scalar &dfdzz) const
  {
    dfdxx = dfdxy = dfdxz = 0.0;
    dfdyx = dfdyy = dfdyz = 0.0;
    dfdzx = dfdzy = dfdzz = 0.0;
  }
};

template <class scalar>
class constantPerElement : public simpleFunction<scalar> {
  std::map<MElement *, scalar> _data;
  mutable MElement *_e;

public:
  constantPerElement() : _e(nullptr) {}
  void set(MElement *e, scalar v) { _data[e] = v; }
  void setElement(MElement *e) const { _e = e; }
  virtual scalar operator()(double x, double y, double z) const
  {
    if(!_e) return 0.0;
    typename std::map<MElement *, scalar>::const_iterator it = _data.find(_e);
    if(it == _data.end()) return 0.0;
    return it->second;
  }
};

template <class scalar>
class simpleFunctionOnElement : public simpleFunction<scalar> {
  mutable MElement *_e;

public:
  simpleFunctionOnElement(scalar val = 0) : simpleFunction<scalar>(val), _e(nullptr)
  {
  }
  virtual ~simpleFunctionOnElement() {}
  void setElement(MElement *e) const { _e = e; }
  MElement *getElement(void) const { return _e; }
  MElement *getElement(double x, double y, double z) const
  {
    if(_e)
      return _e;
    else { // search
    }
  }
};

#endif
