// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Eric Bechet
//

#ifndef STENSOR43_H
#define STENSOR43_H

#include "STensor33.h"
#include "fullMatrix.h"
#include "Numeric.h"

// concrete class for general 3rd-order tensor in three-dimensional space

class STensor43 {
protected:
  // 0000 0001 0002 0010 ... 2211 2212 2220 2221 2222
  double _val[81];

public:
  inline int getIndex(int i, int j, int k, int l) const
  {
    static int _index[3][3][3][3] = {
      {{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}},
       {{9, 10, 11}, {12, 13, 14}, {15, 16, 17}},
       {{18, 19, 20}, {21, 22, 23}, {24, 25, 26}}},
      {{{27, 28, 29}, {30, 31, 32}, {33, 34, 35}},
       {{36, 37, 38}, {39, 40, 41}, {42, 43, 44}},
       {{45, 46, 47}, {48, 49, 50}, {51, 52, 53}}},
      {{{54, 55, 56}, {57, 58, 59}, {60, 61, 62}},
       {{63, 64, 65}, {66, 67, 68}, {69, 70, 71}},
       {{72, 73, 74}, {75, 76, 77}, {78, 79, 80}}}};
    return _index[i][j][k][l];
  }
  STensor43(const STensor43 &other)
  {
    for(int i = 0; i < 81; i++) _val[i] = other._val[i];
  }
  // default constructor, null tensor
  STensor43(const double v = 0.0)
  {
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        for(int k = 0; k < 3; k++)
          for(int l = 0; l < 3; l++)
            if((i == k) && (j == l))
              _val[getIndex(i, j, k, l)] = v;
            else
              _val[getIndex(i, j, k, l)] = 0.0;
  }
  // Symmetric identity tensor
  STensor43(const double vik, const double vil)
  {
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        for(int k = 0; k < 3; k++)
          for(int l = 0; l < 3; l++) {
            _val[getIndex(i, j, k, l)] = 0.;
            if((i == k) && (j == l)) _val[getIndex(i, j, k, l)] += 0.5 * vik;
            if((i == l) && (j == k)) _val[getIndex(i, j, k, l)] += 0.5 * vil;
          }
  }
  inline double &operator()(int i, int j, int k, int l)
  {
    return _val[getIndex(i, j, k, l)];
  }
  inline double operator()(int i, int j, int k, int l) const
  {
    return _val[getIndex(i, j, k, l)];
  }
  STensor43 operator+(const STensor43 &other) const
  {
    STensor43 res(*this);
    for(int i = 0; i < 81; i++) res._val[i] += other._val[i];
    return res;
  }
  STensor43 &operator+=(const STensor43 &other)
  {
    for(int i = 0; i < 81; i++) _val[i] += other._val[i];
    return *this;
  }
  STensor43 &operator-=(const STensor43 &other)
  {
    for(int i = 0; i < 81; i++) _val[i] -= other._val[i];
    return *this;
  }
  STensor43 &operator=(const STensor43 &other)
  {
    for(int i = 0; i < 81; i++) _val[i] = other._val[i];
    return *this;
  }
  STensor43 &operator*=(const double &other)
  {
    for(int i = 0; i < 81; i++) _val[i] *= other;
    return *this;
  }

  STensor43 transpose(int n, int m) const
  {
    STensor43 ithis;
    if((n == 0 && m == 1) || (n == 1 && m == 0)) {
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) ithis(i, j, k, l) = (*this)(j, i, k, l);
      return ithis;
    }
    if((n == 0 && m == 2) || (n == 2 && m == 0)) {
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) ithis(i, j, k, l) = (*this)(k, j, i, l);
      return ithis;
    }
    if((n == 0 && m == 3) || (n == 3 && m == 0)) {
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) ithis(i, j, k, l) = (*this)(l, j, k, i);
      return ithis;
    }
    if((n == 1 && m == 2) || (n == 2 && m == 1)) {
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) ithis(i, j, k, l) = (*this)(i, k, j, l);
      return ithis;
    }
    if((n == 1 && m == 3) || (n == 3 && m == 1)) {
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) ithis(i, j, k, l) = (*this)(i, l, k, j);
      return ithis;
    }
    if((n == 2 && m == 3) || (n == 3 && m == 2)) {
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) ithis(i, j, k, l) = (*this)(i, j, l, k);
      return ithis;
    }
    return ithis += (*this);
  }
  /*  STensor43& operator *= (const STensor43 &other)
    {
  // to be implemented
      return *this;
    }*/
  void print(const char *) const;
  const double *data() const { return _val; }
  double *data() { return _val; }

  void axpy(const double a, const STensor43 &other)
  {
    for(int i = 0; i < 81; i++) _val[i] += a * other._val[i];
  }
};

// tensor product
inline void tensprod(const STensor3 &a, const STensor3 &b, STensor43 &c)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) c(i, j, k, l) = a(i, j) * b(k, l);
}

inline void tensprod(const SVector3 &a, const STensor33 &b, STensor43 &c)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) c(i, j, k, l) = a(i) * b(j, k, l);
}
inline void tensprod(const STensor33 &a, const SVector3 &b, STensor43 &c)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) c(i, j, k, l) = a(i, j, k) * b(l);
}

inline double dot(const STensor43 &a, const STensor43 &b)
{
  double prod = 0;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) prod += a(i, j, k, l) * b(i, j, k, l);
  return prod;
}

// full contracted product
inline STensor43 operator*(const STensor43 &t, double m)
{
  STensor43 val(t);
  val *= m;
  return val;
}
inline STensor43 operator*(double m, const STensor43 &t)
{
  STensor43 val(t);
  val *= m;
  return val;
}

inline STensor33 operator*(const STensor43 &t, const SVector3 &m)
{
  STensor33 val(0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) val(i, j, k) += t(i, j, k, l) * m(l);
  return val;
}
inline STensor33 operator*(const SVector3 &m, const STensor43 &t)
{
  STensor33 val(0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) val(j, k, l) += m(i) * t(i, j, k, l);
  return val;
}

inline STensor3 operator*(const STensor43 &t, const STensor3 &m)
{
  STensor3 val(0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) val(i, j) += t(i, j, k, l) * m(l, k);
  return val;
}
inline STensor3 operator*(const STensor3 &m, const STensor43 &t)
{
  STensor3 val(0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) val(k, l) += m(j, i) * t(i, j, k, l);
  return val;
}

inline SVector3 operator*(const STensor43 &t, const STensor33 &m)
{
  SVector3 val(0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) val(i) += t(i, j, k, l) * m(l, k, j);
  return val;
}
inline SVector3 operator*(const STensor33 &m, const STensor43 &t)
{
  SVector3 val(0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) val(l) += m(k, j, i) * t(i, j, k, l);
  return val;
}

inline double operator*(const STensor43 &m, const STensor43 &t)
{
  double val(0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++) val += m(i, j, k, l) * t(l, k, j, i);
  return val;
}

#endif
