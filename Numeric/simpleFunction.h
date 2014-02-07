// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _SIMPLE_FUNCTION_H_
#define _SIMPLE_FUNCTION_H_

// FIXME: Numeric/ should not depend on Geo/
class MElement;

template <class scalar>
class simpleFunction {
 protected:
  scalar _val;
  bool _hasDerivatives;
 public :
 simpleFunction(scalar val =0.0) : _val(val), _hasDerivatives(false){}
  virtual ~simpleFunction(){}
  virtual bool hasDerivatives() {return _hasDerivatives;};
  virtual scalar operator () (double x, double y, double z) const { return _val; }
  virtual void gradient (double x, double y, double z,
			 scalar & dfdx, scalar & dfdy, scalar & dfdz) const
  { dfdx = dfdy = dfdz = 0.0; }
  virtual void hessian (double x, double y, double z,
			scalar & dfdxx, scalar & dfdxy, scalar & dfdxz, 
			scalar & dfdyx, scalar & dfdyy, scalar & dfdyz,
			scalar & dfdzx, scalar & dfdzy, scalar & dfdzz	) const
  { dfdxx = dfdxy = dfdxz = 0.0;
    dfdyx = dfdyy = dfdyz = 0.0;
    dfdzx = dfdzy = dfdzz = 0.0; }
};

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
