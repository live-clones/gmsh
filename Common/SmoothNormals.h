#ifndef _SMOOTH_NORMALS_H_
#define _SMOOTH_NORMALS_H_

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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


using namespace std;

struct xyzv
{
  double x, y, z, *vals;
  int nbvals;
  int nboccurences;
  static double eps;
  void update(int nbVals, double *);
  xyzv(double x, double y, double z);
  ~xyzv();
  xyzv & operator =(const xyzv &);
  xyzv(const xyzv &);
};

struct lessthanxyzv
{
  bool operator () (const xyzv & p2, const xyzv & p1)const
  {
    if(p1.x - p2.x > xyzv::eps)
      return true;
    if(p1.x - p2.x < -xyzv::eps)
      return false;
    if(p1.y - p2.y > xyzv::eps)
      return true;
    if(p1.y - p2.y < -xyzv::eps)
      return false;
    if(p1.z - p2.z > xyzv::eps)
      return true;
    return false;
  }
};

#include <set>
typedef set < xyzv, lessthanxyzv > xyzcont;
typedef xyzcont::const_iterator xyziter;

class smooth_normals{
 private:
  double get_angle(double *aa, double *bb);
 public:
  xyzcont c;
  void add(double x, double y, double z,
	   double nx, double ny, double nz);
  bool get(double x, double y, double z,
	   double &nx, double &ny, double &nz, double angletol = 180.0);
};

#endif
