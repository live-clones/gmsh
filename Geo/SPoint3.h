#ifndef _SPOINT3_H_
#define _SPOINT3_H_

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

// A point in 3-space
class SPoint3 {
 protected:
  double P[3];
 public:
  SPoint3() {}
  SPoint3(double x, double y, double z) {P[0] = x; P[1] = y; P[2] = z;}
  SPoint3(const double *p) {P[0] = p[0]; P[1] = p[1]; P[2] = p[2];}
  SPoint3(const SPoint3 &pt) {P[0] = pt.P[0]; P[1] = pt.P[1]; P[2] = pt.P[2]; }
  virtual ~SPoint3() {}
  void setPosition(double xx, double yy, double zz);
  void getPosition(double *xx, double *yy, double *zz) const;
  void position(double *) const;
  inline double x(void) const;
  inline double y(void) const;
  inline double z(void) const;
  double &operator[](int);
  double operator[](int) const;
  SPoint3 &operator=(const SPoint3 &p);
  void operator+=(const SPoint3 &p);
  void operator-=(const SPoint3 &p);
  void operator*=(double mult);
  SPoint3 operator*(double mult);
  operator double *() { return P; }
};

inline SPoint3 operator + (const SPoint3 &a, const SPoint3 &b)
{ return SPoint3(a.x()+b.x(),a.y()+b.y(),a.z()+b.z()); }

inline SPoint3 operator - (const SPoint3 &a, const SPoint3 &b)
{ return SPoint3(a.x()-b.x(),a.y()-b.y(),a.z()-b.z()); }

inline void SPoint3::setPosition(double xx, double yy, double zz)
{ P[0] = xx;  P[1] = yy;  P[2] = zz; }

inline void SPoint3::getPosition(double *xx, double *yy, double *zz) const
{ *xx = P[0];  *yy = P[1];  *zz = P[2]; }

inline void SPoint3::position(double *p) const
{ p[0] = P[0]; p[1] = P[1]; p[2] = P[2]; }

inline double SPoint3::x(void) const
{ return P[0]; }

inline double SPoint3::y(void) const
{ return P[1]; }

inline double SPoint3::z(void) const
{ return P[2]; }

inline SPoint3 & SPoint3::operator=(const SPoint3 &p)
{ P[0] = p.P[0]; P[1]=p.P[1]; P[2]=p.P[2]; return *this; }

inline void SPoint3::operator+=(const SPoint3 &p)
{ P[0] += p.P[0]; P[1] += p.P[1]; P[2] += p.P[2];}

inline void SPoint3::operator-=(const SPoint3 &p)
{ P[0] -= p.P[0]; P[1] -= p.P[1]; P[2] -= p.P[2];}

inline void SPoint3::operator*=(double mult)
{ P[0] *= mult; P[1] *= mult; P[2] *= mult; }

inline SPoint3 SPoint3::operator*(double mult)
{ return SPoint3(P[0]*mult, P[1]*mult, P[2] *= mult); }

inline double &SPoint3::operator[](int i)
{ return P[i]; }

inline double SPoint3::operator[](int i) const
{ return P[i]; }

#endif
