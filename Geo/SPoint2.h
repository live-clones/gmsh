#ifndef _SPOINT2_H_
#define _SPOINT2_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

// A point in 2-space
class SPoint2 {
 protected:
  double P[2];
 public:
  SPoint2(double x=0.0, double y=0.0) {P[0] = x; P[1] = y;}
  SPoint2(double *p) {P[0] = p[0]; P[1] = p[1];}
  SPoint2(const SPoint2 &pt) {P[0] = pt.P[0]; P[1] = pt.P[1]; }
  virtual ~SPoint2() {}
  void setPosition(double xx, double yy);
  void getPosition(double *xx, double *yy) const;
  void position(double *) const;
  inline double x(void) const;
  inline double y(void) const;
  double &operator[](int);
  double operator[](int) const;
  SPoint2 &operator=(const SPoint2 &p);
  void operator+=(const SPoint2 &p);
  void operator-=(const SPoint2 &p);
  void operator*=(double mult);
  SPoint2 operator*(double mult);
  operator double *() { return P; }
};

inline SPoint2 operator + (const SPoint2 &a, const SPoint2 &b)
{ return SPoint2(a.x()+b.x(),a.y()+b.y()); }

inline SPoint2 operator - (const SPoint2 &a, const SPoint2 &b)
{ return SPoint2(a.x()-b.x(),a.y()-b.y()); }

inline void SPoint2::setPosition(double xx, double yy)
{ P[0] = xx;  P[1] = yy; }

inline void SPoint2::getPosition(double *xx, double *yy) const
{ *xx = P[0];  *yy = P[1]; }

inline void SPoint2::position(double *p) const
{ p[0] = P[0]; p[1] = P[1]; }

inline double SPoint2::x(void) const
{ return P[0]; }

inline double SPoint2::y(void) const
{ return P[1]; }

inline SPoint2 & SPoint2::operator=(const SPoint2 &p)
{ P[0] = p.P[0]; P[1]=p.P[1]; return *this; }

inline double &SPoint2::operator[](int i)
{ return P[i]; }

inline double SPoint2::operator[](int i) const
{ return P[i]; }

inline void SPoint2::operator+=(const SPoint2 &p)
{ P[0] += p.P[0]; P[1] += p.P[1];}

inline void SPoint2::operator-=(const SPoint2 &p)
{ P[0] -= p.P[0]; P[1] -= p.P[1];}

inline void SPoint2::operator*=(double mult)
{ P[0] *= mult; P[1] *= mult; }

inline SPoint2 SPoint2::operator*(double mult)
{ return SPoint2(P[0]*mult, P[1]*mult); }

#endif
