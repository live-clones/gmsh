// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SIMPLE_FUNCTION_H_
#define _SIMPLE_FUNCTION_H_

template <class scalar>
class simpleFunction {
  scalar _val;
 public :
  simpleFunction(scalar val=0) : _val(val) {}
  virtual ~simpleFunction(){}
  virtual scalar operator () (double x, double y, double z) const { return _val; }
  virtual void gradient (double x, double y, double z,
			 scalar & dfdx, scalar & dfdy, scalar & dfdz) const 
  { dfdx = dfdy = dfdz = 0.0; }
};

#endif
