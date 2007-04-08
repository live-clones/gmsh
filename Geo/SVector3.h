#ifndef _SVECTOR3_H_
#define _SVECTOR3_H_

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

#include "SPoint3.h"

// concrete class for vector of size 3
class SVector3 {
 public:
  SVector3() {}
  // Construct from 2 SPoints, vector from p1 to p2
  SVector3(const SPoint3 &p1, const SPoint3 &p2) : P(p2 - p1) {}
  // Construct from a single SPoint, vector from origin to p1
  SVector3(const SPoint3 &p1) : P(p1) {}
  SVector3(double x, double y, double z) : P(x, y, z) {}
  SVector3(double v) : P(v, v, v) {}
  SVector3(const double *array) : P(array) {}
  inline double x(void) const { return P.x(); }
  inline double y(void) const { return P.y(); }
  inline double z(void) const { return P.z(); }
  inline double norm() { return sqrt(P[0] * P[0] + P[1] * P[1] + P[2] * P[2]); }
  double normalize() 
  { 
    double n = norm(); if(n){ P[0] /= n; P[1] /= n; P[2] /= n; }
    return n;
  }
  // why both [] and (), why not
  double &operator[](int i){ return P[i]; }
  double operator[](int i) const { return P[i]; }
  double &operator()(int i){ return P[i]; }
  double operator()(int i) const { return P[i]; }
  SVector3 & operator += (const SVector3 &a)
  {
    for(int i = 0; i < 3; i++)
      P[i] += a[i];
    return *this;
  }
  SVector3 & operator -= (const SVector3 &a)
  { 
    for(int i = 0; i < 3; i++)
      P[i] -= a[i];
    return *this;
  }
  SVector3 & operator *= (const SVector3 &a)
  { 
    for(int i = 0; i < 3; i++)
      P[i] *= a[i];
    return *this;
  }
  SVector3 & operator = (double v)
  {
    P[0] = v; P[1] = v; P[2] = v;
    return *this;
  }
  operator double *() { return P; }
 protected:
  SPoint3 P;
};

inline double dot(const SVector3 &a, const SVector3 &b)
{ return a.x() * b.x() + a.y() * b.y() + a.z() * b.z(); }

inline double norm(const SVector3 &v)
{ return sqrt(dot(v, v)); }

inline SVector3 crossprod(const SVector3 &a, const SVector3 &b)
{ return SVector3(a.y() * b.z() - b.y() * a.z(), 
		  -(a.x() * b.z() - b.x() * a.z()), 
		  a.x() * b.y() - b.x() * a.y()); }

inline SVector3 operator*(double m,const SVector3 &v)
{ return SVector3(v[0] * m, v[1] * m, v[2] * m); }

inline SVector3 operator*(const SVector3 &v, double m)
{ return SVector3(v[0] * m, v[1] * m, v[2] * m); }

inline SVector3 operator*(const SVector3 &v1, const SVector3 &v2)
{ return SVector3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]); }

inline SVector3 operator+(const SVector3 &a,const SVector3 &b)
{ return SVector3(a[0] + b[0], a[1] + b[1], a[2] + b[2]); }

inline SVector3 operator-(const SVector3 &a,const SVector3 &b)
{ return SVector3(a[0] - b[0], a[1] - b[1], a[2] - b[2]); }

#endif
