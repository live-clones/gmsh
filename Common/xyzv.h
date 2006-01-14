#ifndef _XYZV_H_
#define _XYZV_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include <set>

using namespace std;

struct xyzv
{
  double x, y, z, *vals;
  int nbvals;
  int nboccurences;
  static double eps;
  xyzv(double xx, double yy, double zz)
    : x(xx), y(yy), z(zz), vals(0), nbvals(0), nboccurences(0)
  {
  }
  ~xyzv()
  { 
    if(vals) delete [] vals; 
  }
  xyzv(const xyzv & other)
  {
    x = other.x;
    y = other.y;
    z = other.z;
    nbvals = other.nbvals;
    nboccurences = other.nboccurences;
    if(other.vals && other.nbvals) {
      vals = new double[other.nbvals];
      for(int i = 0; i < nbvals; i++)
	vals[i] = other.vals[i];
    }
  }
  xyzv & operator =(const xyzv &other)
  {
    if(this != &other) {
      x = other.x;
      y = other.y;
      z = other.z;
      nbvals = other.nbvals;
      nboccurences = other.nboccurences;
      if(other.vals && other.nbvals) {
	vals = new double[other.nbvals];
	for(int i = 0; i < nbvals; i++)
	  vals[i] = other.vals[i];
      }
    }
    return *this;
  }
  void update(int n, double *v)
  {
    if(!vals) {
      vals = new double[n];
      for(int i = 0; i < n; i++)
	vals[i] = 0.0;
      nbvals = n;
      nboccurences = 0;
    }
    else if(nbvals != n) {
      throw n;
    }
    double x1 = (double)(nboccurences) / (double)(nboccurences + 1);
    double x2 = 1. / (double)(nboccurences + 1);
    for(int i = 0; i < nbvals; i++)
      vals[i] = (x1 * vals[i] + x2 * v[i]);
    nboccurences++;
  }
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

typedef set < xyzv, lessthanxyzv > xyzv_cont;
typedef xyzv_cont::const_iterator xyzv_iter;

#endif
