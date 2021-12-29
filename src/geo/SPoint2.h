// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SPOINT2_H
#define SPOINT2_H

#include <cmath>

// A point in 2-space
class SPoint2 {
protected:
  double P[2];

public:
  SPoint2(double x = 0.0, double y = 0.0)
  {
    P[0] = x;
    P[1] = y;
  }
  SPoint2(double *p)
  {
    P[0] = p[0];
    P[1] = p[1];
  }
  SPoint2(const SPoint2 &pt)
  {
    P[0] = pt.P[0];
    P[1] = pt.P[1];
  }
  virtual ~SPoint2() {}
  void setPosition(double xx, double yy);
  void getPosition(double *xx, double *yy) const;
  void position(double *) const;
  inline double x(void) const;
  inline double y(void) const;
  double &operator[](int);
  double operator[](int) const;
  double distance(const SPoint2 &p) const;
  SPoint2 &operator=(const SPoint2 &p);
  void operator+=(const SPoint2 &p);
  void operator-=(const SPoint2 &p);
  void operator*=(double mult);
  SPoint2 operator*(double mult) const;
  operator double *() { return P; }
  bool operator<(const SPoint2 &other) const
  {
    if(other.P[0] < P[0]) return true;
    if(other.P[0] > P[0]) return false;
    if(other.P[1] < P[1]) return true;
    return false;
  }
  const double *data() const { return P; }
  double *data() { return P; }
};

inline SPoint2 operator+(const SPoint2 &a, const SPoint2 &b)
{
  return SPoint2(a.x() + b.x(), a.y() + b.y());
}

inline SPoint2 operator-(const SPoint2 &a, const SPoint2 &b)
{
  return SPoint2(a.x() - b.x(), a.y() - b.y());
}

inline void SPoint2::setPosition(double xx, double yy)
{
  P[0] = xx;
  P[1] = yy;
}

inline void SPoint2::getPosition(double *xx, double *yy) const
{
  *xx = P[0];
  *yy = P[1];
}

inline void SPoint2::position(double *p) const
{
  p[0] = P[0];
  p[1] = P[1];
}

inline double SPoint2::x(void) const { return P[0]; }

inline double SPoint2::y(void) const { return P[1]; }

inline SPoint2 &SPoint2::operator=(const SPoint2 &p)
{
  P[0] = p.P[0];
  P[1] = p.P[1];
  return *this;
}

inline double &SPoint2::operator[](int i) { return P[i]; }

inline double SPoint2::operator[](int i) const { return P[i]; }

inline void SPoint2::operator+=(const SPoint2 &p)
{
  P[0] += p.P[0];
  P[1] += p.P[1];
}

inline void SPoint2::operator-=(const SPoint2 &p)
{
  P[0] -= p.P[0];
  P[1] -= p.P[1];
}

inline void SPoint2::operator*=(double mult)
{
  P[0] *= mult;
  P[1] *= mult;
}

inline SPoint2 SPoint2::operator*(double mult) const
{
  return SPoint2(P[0] * mult, P[1] * mult);
}

inline double SPoint2::distance(const SPoint2 &p) const
{
  double x = P[0] - p.P[0], y = P[1] - p.P[1];
  return std::sqrt(x * x + y * y);
}

#endif
