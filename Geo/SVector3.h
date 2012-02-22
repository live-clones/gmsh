// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SVECTOR3_H_
#define _SVECTOR3_H_

#include "SPoint3.h"
#include <string>
#include <stdio.h>
#include "GmshMessage.h"

// concrete class for vector of size 3
class SVector3 {
 protected:
  SPoint3 P;
 public:
  SVector3():P() {}
  // Construct from 2 SPoints, vector from p1 to p2
  SVector3(const SPoint3 &p1, const SPoint3 &p2) : P(p2 - p1) {}
  // Construct from a single SPoint, vector from origin to p1
  SVector3(const SPoint3 &p1) : P(p1) {}
  SVector3(double x, double y, double z) : P(x, y, z) {}
  SVector3(double v) : P(v, v, v) {}
  SVector3(const double *array) : P(array) {}
  SVector3(const SVector3& v) : P(v.P) {}
  inline double x(void) const { return P.x(); }
  inline double y(void) const { return P.y(); }
  inline double z(void) const { return P.z(); }
  inline double norm() const { return sqrt(P[0] * P[0] + P[1] * P[1] + P[2] * P[2]); }
  inline double normSq() { return (P[0] * P[0] + P[1] * P[1] + P[2] * P[2]); }
  double normalize()
  {
    double n = norm(); if(n){ P[0] /= n; P[1] /= n; P[2] /= n; }
    return n;
  }
  void negate() { P[0] = -P[0]; P[1] = -P[1]; P[2] = -P[2]; }
  // why both [] and (), why not
  double &operator[](int i){ return P[i]; }
  double operator[](int i) const { return P[i]; }
  double &operator()(int i){ return P[i]; }
  double operator()(int i) const { return P[i]; }
  SVector3 & operator += (const SVector3 &a)
  {
    P[0] += a[0];  P[1] += a[1];  P[2] += a[2];
    return *this;
  }
  SVector3 & operator -= (const SVector3 &a)
  {
    P[0] -= a[0];  P[1] -= a[1];  P[2] -= a[2];
    return *this;
  }
  SVector3 & operator *= (const SVector3 &a)
  {
    P[0] *= a[0]; P[1] *= a[1]; P[2] *= a[2];
    return *this;
  }
  SVector3 & operator *= (const double v)
  {
    P[0] *= v; P[1] *= v; P[2] *= v;
    return *this;
  }
  SVector3 & operator = (double v)
  {
    P[0] = v; P[1] = v; P[2] = v;
    return *this;
  }
  operator double *() { return P; }
  void print(std::string name="") const
  { printf("Vector \'%s\':  %f  %f  %f\n",name.c_str(),P[0],P[1],P[2]); }

  // Needed to allow the initialization of a SPoint3 from a SPoint3, a distance and a direction
  SPoint3 point() const{return P;}

};

inline double dot(const SVector3 &a, const SVector3 &b)
{ return a.x() * b.x() + a.y() * b.y() + a.z() * b.z(); }

inline double norm(const SVector3 &v)
{ return sqrt(dot(v, v)); }

inline double normSq(const SVector3 &v)
{ return dot(v, v); }

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

inline void buildOrthoBasis_naive(SVector3 &dir, SVector3 &dir1, SVector3 &dir2)
{
  dir.normalize();
  if (dir[1]!=0.0 && dir[2]!=0.0){
     dir1 = SVector3(1.0, 0.0, -dir[0]/dir[2]);
     dir2 = SVector3 (dir[0]/dir[2], -(dir[0]*dir[0]+dir[2]*dir[2])/(dir[1]*dir[2]), 1.0);
   }
   else if (dir[0]!=0.0 && dir[2]!=0.0){
     dir1 = SVector3(-dir[1]/dir[0], 1.0, 0.0);
     dir2 = SVector3(1.0, dir[1]/dir[0], -(dir[1]*dir[1]+dir[0]*dir[0])/(dir[0]*dir[2]));
   }
   else if (dir[0]!=0.0 && dir[1]!=0.0){
     dir1 = SVector3(0.0, -dir[2]/dir[1], 1.0);
     dir2 = SVector3(-(dir[1]*dir[1]+dir[2]*dir[2])/(dir[0]*dir[1]), 1.0, dir[2]/dir[1]);
   }
   else if (dir[0]==0.0 && dir[1]==0.0){
     dir1 = SVector3(0.0, 1.0, 0.0);
     dir2 = SVector3(1.0, 0.0, 0.0);
   }
   else if (dir[1]==0.0 && dir[2]==0.0){
     dir1 = SVector3(0.0, 1.0, 0.0);
     dir2 = SVector3(0.0, 0.0, 1.0);
   }
   else if (dir[0]==0.0 && dir[2]==0.0){
     dir1 = SVector3(1.0, 0.0, 0.0);
     dir2 = SVector3(0.0, 0.0, 1.0);
   }
   else{
       Msg::Error("Problem with computing orthoBasis");
       Msg::Exit(1);
   }
   // printf("XYZ =%g %g %g r=%g dir0 = %g %g %g dir1 = %g %g %g dir2 =%g %g %g\n", 
   // 	  x,y,z,d, dir[0], dir[1], dir[2], dir1[0], dir1[1], dir1[2],  dir2[0], dir2[1], dir2[2] );
   // printf("0x1 =%g 1x2=%g 2x1=%g \n", dot(dir, dir1), dot(dir1,dir2), dot(dir2,dir));
   dir1.normalize();
   dir2.normalize();
}

inline void buildOrthoBasis(SVector3 &normal, SVector3 &tangent, SVector3 &binormal)
{
  //pick any Unit-Vector that's not parallel to normal:
  normal.normalize();
  if (fabs(normal[0]) > fabs(normal[1]) )
    tangent = SVector3(0.0, 1.0, 0.0);
  else
    tangent = SVector3(1.0, 0.0, 0.0);

  //build a binormal from tangent and normal:
  binormal = crossprod(tangent, normal);
  double t1 = binormal.normalize();
  
  //and correct the tangent from the binormal and the normal.
  tangent = crossprod(normal, binormal);
  double t2 = tangent.normalize();
  
  if (t1 == 0.0 || t2 == 0.0) 
    buildOrthoBasis_naive(normal, tangent, binormal);

}

#endif
