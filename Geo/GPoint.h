#ifndef _GPOINT_H_
#define _GPOINT_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <math.h>

class GEntity;

class GPoint 
{
 private:
  double X, Y, Z;
  const GEntity *e;  
  double par[2];
 public:
  inline double x() const { return X; }
  inline double y() const { return Y; }
  inline double z() const { return Z; }
  inline double &x() { return X; }
  inline double &y() { return Y; }
  inline double &z() { return Z; }
  inline double u() const { return par[0]; }
  inline double v() const { return par[1]; }
  GPoint (double _x=0, double _y=0, double _z=0, const GEntity *onwhat=0)
    : X(_x), Y(_y), Z(_z), e(onwhat) 
  {
  }
  GPoint (double _x, double _y, double _z, const GEntity *onwhat, double p)
    : X(_x), Y(_y), Z(_z), e(onwhat)
  {
    par[0] = p;
  }
  GPoint (double _x, double _y, double _z, const GEntity *onwhat, double p[2])
    : X(_x), Y(_y), Z(_z), e(onwhat)
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
};

#endif
