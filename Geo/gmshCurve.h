#ifndef _GMSH_CURVE_
#define _GMSH_CURVE_
#include <vector>
#include "SVector3.h"
#include "SPoint3.h"
#include "SPoint2.h"

class Curve;

class gmshCurve {
 public :
  virtual SPoint3 point (double t) const = 0;
  virtual SVector3 firstDer (double t) const = 0;
  virtual SVector3 secondDer (double t) const = 0;
  SVector3 curvature (double t) const;
};

class gmshCubicSpline : public gmshCurve 
{
  Curve *c;
 public:
  gmshCubicSpline (std::vector<SPoint3> & data); 
  gmshCubicSpline (std::vector<SPoint2> & data); 
  ~gmshCubicSpline();
  virtual SPoint3 point (double t) const;
  virtual SVector3 firstDer (double t) const;
  virtual SVector3 secondDer (double t) const;
};


#endif
