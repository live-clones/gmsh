// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SPOINT3_H_
#define _SPOINT3_H_

#include <math.h>

// A point in 3-space
class SPoint3 {
 protected:
  double P[3];
 public:
  SPoint3() { P[0] = P[1] = P[2] = 0.; }
  SPoint3(double x, double y, double z) { P[0] = x; P[1] = y; P[2] = z; }
  SPoint3(const double *p) { P[0] = p[0]; P[1] = p[1]; P[2] = p[2]; }
  SPoint3(const SPoint3 &pt) { P[0] = pt.P[0]; P[1] = pt.P[1]; P[2] = pt.P[2]; }
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
  void operator/=(double mult);
  SPoint3 operator*(double mult);
  operator double *() { return P; }
  double distance(const SPoint3 &p)const;
  // lexicographic
  bool operator < (const SPoint3 &p) const
  {
    if (P[0] < p.P[0]) return true;
    if (P[0] > p.P[0]) return false;
    if (P[1] < p.P[1]) return true;
    if (P[1] > p.P[1]) return false;
    if (P[2] < p.P[2]) return true;
    return false;
  }
};

inline SPoint3 operator + (const SPoint3 &a, const SPoint3 &b)
{ return SPoint3(a.x() + b.x(), a.y() + b.y(), a.z() + b.z()); }

inline SPoint3 operator - (const SPoint3 &a, const SPoint3 &b)
{ return SPoint3(a.x() - b.x(), a.y() - b.y(), a.z() - b.z()); }

inline void SPoint3::setPosition(double xx, double yy, double zz)
{ P[0] = xx; P[1] = yy; P[2] = zz; }

inline void SPoint3::getPosition(double *xx, double *yy, double *zz) const
{ *xx = P[0]; *yy = P[1]; *zz = P[2]; }

inline void SPoint3::position(double *p) const
{ p[0] = P[0]; p[1] = P[1]; p[2] = P[2]; }

inline double SPoint3::x(void) const
{ return P[0]; }

inline double SPoint3::y(void) const
{ return P[1]; }

inline double SPoint3::z(void) const
{ return P[2]; }

inline SPoint3 & SPoint3::operator=(const SPoint3 &p)
{ P[0] = p.P[0]; P[1] = p.P[1]; P[2] = p.P[2]; return *this; }

inline void SPoint3::operator+=(const SPoint3 &p)
{ P[0] += p.P[0]; P[1] += p.P[1]; P[2] += p.P[2]; }

inline void SPoint3::operator-=(const SPoint3 &p)
{ P[0] -= p.P[0]; P[1] -= p.P[1]; P[2] -= p.P[2]; }

inline void SPoint3::operator*=(double mult)
{ P[0] *= mult; P[1] *= mult; P[2] *= mult; }

inline void SPoint3::operator/=(double div)
{ P[0] /= div; P[1] /= div; P[2] /= div; }

inline SPoint3 SPoint3::operator*(double mult)
{ return SPoint3(P[0] * mult, P[1] * mult, P[2] * mult); }

inline double &SPoint3::operator[](int i)
{ return P[i]; }

inline double SPoint3::operator[](int i) const
{ return P[i]; }

inline double SPoint3::distance(const SPoint3 &p)const
{ 
  double x = P[0] - p.P[0], y = P[1] - p.P[1], z = P[2] - p.P[2];
  return sqrt(x * x + y * y + z * z);
}

#endif
