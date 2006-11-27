// $Id: SVector3.cpp,v 1.5 2006-11-27 22:22:14 geuzaine Exp $
//
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

#include "SVector3.h"
#include "math.h"


SVector3 crossprod(const SVector3 &a, const SVector3 &b)
{
  return SVector3(a.y()*b.z()-b.y()*a.z(),
		 -(a.x()*b.z()-b.x()*a.z()),
		 a.x()*b.y()-b.x()*a.y());
}

double dot(const SVector3 &a, const SVector3 &b)
{
  return( a.x()*b.x()+a.y()*b.y()+a.z()*b.z() );
}

double angle(const SVector3 &a, const SVector3 &b, const SVector3 &n)
{
  double ddot = dot(a,b)/(norm(a)*norm(b));
  if(ddot>1.0)
    ddot = 1.0;
  if(ddot<-1.0)
    ddot = -1.0;
  double dang = acos(ddot);
  // check if we just found the angle or 2*PI-angle
  SVector3 check = crossprod(a,b);
  // ***** check this below ******
  if( norm(check) > 0.0000001*(norm(a)+norm(b))){  // check if a,b are colinear
    double dir = dot(check,n);
    dang = dir < 0 ? 2*M_PI-dang : dang;
  } else {
    if( ddot > 0)
      dang = 2*M_PI;
  }
  return dang;

}

double norm(const SVector3 &v)
{ return sqrt(dot(v,v)); }

double SVector3::normalize()
{ 
  double n = norm(*this);
  if(n){
    P[0] /= n; P[1]/= n; P[2] /= n;
  }
  return n;
}

SVector3 operator*(double m,const SVector3 &v)
{
  return SVector3(v[0]*m,v[1]*m,v[2]*m);
}

SVector3 operator*(const SVector3 &v, double m)
{
  return SVector3(v[0]*m,v[1]*m,v[2]*m);
}

SVector3 operator*(const SVector3 &v1, const SVector3 &v2)
{
  return SVector3(v1[0]*v2[0],v1[1]*v2[1],v1[2]*v2[2]);
}

SVector3 operator+(const SVector3 &a,const SVector3 &b)
{
  return SVector3(a[0]+b[0],a[1]+b[1],a[2]+b[2]);
}

SVector3 operator-(const SVector3 &a,const SVector3 &b)
{
  return SVector3(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
}

SVector3 & SVector3::operator += (const SVector3 &a)
{ 
  for(int i = 0; i < 3; i++)
    P[i] += a[i];
  return *this;
}

SVector3 & SVector3::operator -= (const SVector3 &a)
{ 
  for(int i = 0; i < 3; i++)
    P[i] -= a[i];
  return *this;
}

SVector3 & SVector3::operator *= (const SVector3 &a)
{ 
  for(int i = 0; i < 3; i++)
    P[i] *= a[i];
  return *this;
}

SVector3 & SVector3::operator = (double v)
{
  P[0] = v; P[1] = v; P[2] = v;
  return *this;
}
