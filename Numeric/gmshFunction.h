// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_FUNCTION_H_
#define _GMSH_FUNCTION_H_

class gmshFunction {
  double _val;
 public :
  gmshFunction(double val = 0) : _val(val) {}
  virtual ~gmshFunction(){}
  virtual double operator () (double x, double y, double z) const { return _val; }
};

#endif
