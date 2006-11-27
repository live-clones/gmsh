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
  SVector3(const SPoint3 &p1, const SPoint3 &p2) : P(p2-p1) {}
  // Construct from a single SPoint, vector from origin to p1
  SVector3(const SPoint3 &p1) : P(p1) {}
  SVector3(double x, double y, double z) : P(x,y,z) {}
  SVector3(double v) : P(v,v,v) {}
  SVector3(const double *array) : P(array) {}
  inline double x(void) const { return P.x(); }
  inline double y(void) const { return P.y(); }
  inline double z(void) const { return P.z(); }
  double normalize();
  // why both [] and (), why not
  double &operator[](int);
  double operator[](int) const;
  double &operator()(int);
  double operator()(int) const;
  SVector3 & operator += (const SVector3 &);
  SVector3 & operator -= (const SVector3 &);
  SVector3 & operator *= (const SVector3 &);
  SVector3 & operator = (double);
  operator double *() { return P; }
 protected:
  SPoint3 P;
};

double norm(const SVector3 &v);
double dot(const SVector3 &a, const SVector3 &b);
SVector3 crossprod(const SVector3 &a, const SVector3 &b);
double angle(const SVector3 &a, const SVector3 &b, const SVector3 &n);
SVector3 operator*(double m,const SVector3 &v);
SVector3 operator*(const SVector3 &v, double m);
SVector3 operator*(const SVector3 &v1, const SVector3 &v2);
SVector3 operator+(const SVector3 &a,const SVector3 &b);
SVector3 operator-(const SVector3 &a,const SVector3 &b);

inline double &SVector3::operator[](int i)
{ return P[i]; }

inline double SVector3::operator[](int i) const
{ return P[i]; }

inline double &SVector3::operator()(int i)
{ return P[i]; }

inline double SVector3::operator()(int i) const
{ return P[i]; }

#endif
