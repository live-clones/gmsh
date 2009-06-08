// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GPOINT_H_
#define _GPOINT_H_

#include <math.h>

class GEntity;

class GPoint
{
 private:
  double X, Y, Z;
  const GEntity *e;
  double par[2];
  bool success;
 public:
  inline double x() const { return X; }
  inline double y() const { return Y; }
  inline double z() const { return Z; }
  inline double &x() { return X; }
  inline double &y() { return Y; }
  inline double &z() { return Z; }
  inline double u() const { return par[0]; }
  inline double v() const { return par[1]; }
  inline const GEntity* g() const { return e; }
  GPoint (double _x=0, double _y=0, double _z=0, const GEntity *onwhat=0)
    : X(_x), Y(_y), Z(_z), e(onwhat) ,success(true)
  {
  }
  GPoint (double _x, double _y, double _z, const GEntity *onwhat, double p)
    : X(_x), Y(_y), Z(_z), e(onwhat),success(true)
  {
    par[0] = p;
  }
  GPoint (double _x, double _y, double _z, const GEntity *onwhat, double p[2])
    : X(_x), Y(_y), Z(_z), e(onwhat),success(true)
  {
    par[0] = p[0];
    par[1] = p[1];
  }
  double distance(GPoint &p)
  {
    double dx = X - p.x();
    double dy = Y - p.y();
    double dz = Z - p.z();
    return sqrt(dx * dx + dy * dy + dz * dz);
  }
  bool succeeded () const{
    return success;
  }
  bool setNoSuccess (){
    success = false;
    return success;
  }
};

#endif
