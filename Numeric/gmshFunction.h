// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_FUNCTION_H_
#define _GMSH_FUNCTION_H_

template <class scalar>
class gmshFunction {
  scalar _val;
 public :
  gmshFunction(scalar val=0) : _val(val) {}
  virtual ~gmshFunction(){}
  virtual scalar operator () (double x, double y, double z) const { return _val; }
};

#endif
