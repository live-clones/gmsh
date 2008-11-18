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
