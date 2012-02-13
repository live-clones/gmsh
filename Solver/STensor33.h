#ifndef _STENSOR33_H_
#define _STENSOR33_H_

#include "STensor3.h"
#include "fullMatrix.h"
#include "Numeric.h"


// concrete class for general 3rd-order tensor in three-dimensional space

class STensor33 {
 protected:
  // 000 001 002 010 ... 211 212 220 221 222
  double _val[27];
 public:
  inline int getIndex(int i, int j, int k) const
  {
    static int _index[3][3][3] = {{{0,1,2},{3,4,5},{6,7,8}},{{9,10,11},{12,13,14},{15,16,17}},{{18,19,20},{21,22,23},{24,25,26}}};
    return _index[i][j][k];
  }
  STensor33(const STensor33& other)
  {
    for (int i = 0; i < 27; i++) _val[i] = other._val[i];
  }
  // default constructor, null tensor
  STensor33(const double v = 0.0)
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
          _val[getIndex(i, j, k)]=v;
  }
  inline double &operator()(int i, int j,int k)
  {
    return _val[getIndex(i, j, k)];
  }
  inline double operator()(int i, int j, int k) const
  {
    return _val[getIndex(i, j, k)];
  }
  STensor33 operator + (const STensor33 &other) const
  {
    STensor33 res(*this);
    for (int i = 0; i < 27; i++) res._val[i] += other._val[i];
    return res;
  }
  STensor33& operator += (const STensor33 &other)
  {
    for (int i = 0; i < 27; i++) _val[i] += other._val[i];
    return *this;
  }
  STensor33& operator -= (const STensor33 &other)
  {
    for (int i = 0; i < 27; i++) _val[i] -= other._val[i];
    return *this;
  }
  STensor33& operator *= (const double &other)
  {
    for (int i = 0; i < 27; i++) _val[i] *= other;
    return *this;
  }
  STensor33 transpose (int n, int m) const
  {
    STensor33 ithis;
    if ((n==0 && m==1) || (n==1 && m==0))
    {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          for (int k = 0; k < 3; k++)
              ithis(i,j,k) = (*this)(j,i,k);
      return ithis;
    }
    if ((n==0 && m==2) || (n==2 && m==0))
    {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          for (int k = 0; k < 3; k++)
              ithis(i,j,k) = (*this)(k,j,i);
      return ithis;
    }
    if ((n==1 && m==2) || (n==2 && m==1))
    {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          for (int k = 0; k < 3; k++)
              ithis(i,j,k) = (*this)(i,k,j);
      return ithis;
    }
    return ithis+=(*this);
  }
/*  STensor33& operator *= (const STensor33 &other)
  {
// to be implemented
    return *this;
  }*/
  void print(const char *) const;
};

// tensor product
inline void tensprod(const SVector3 &a, const STensor3 &b, STensor33 &c)
{
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
            c(i,j,k)=a(i)*b(j,k);
}
inline void tensprod(const STensor3 &a, const SVector3 &b, STensor33 &c)
{
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
            c(i,j,k)=a(i,j)*b(k);
}

inline double dot(const STensor33 &a, const STensor33 &b)
{
  double prod=0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
      prod+=a(i,j,k)*b(i,j,k);
  return prod;
}

// full contracted product
inline STensor33 operator*(const STensor33 &t, double m)
{
  STensor33 val(t);
  val *= m;
  return val;
}
inline STensor33 operator*(double m,const STensor33 &t)
{
  STensor33 val(t);
  val *= m;
  return val;
}

inline STensor3 operator*(const STensor33 &t, const SVector3 &m)
{
  STensor3 val(0.);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        val(i,j)+=t(i,j,k)*m(k);
  return val;
}
inline STensor3 operator*( const SVector3 &m , const STensor33 &t)
{
  STensor3 val(0.);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        val(j,k)+=m(i)*t(i,j,k);
  return val;
}

inline SVector3 operator*(const STensor33 &t, const STensor3 &m)
{
  SVector3 val(0.);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        val(i)+=t(i,j,k)*m(k,j);
  return val;
}
inline SVector3 operator*( const STensor3 &m , const STensor33 &t)
{
  SVector3 val(0.);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        val(k)+=m(j,i)*t(i,j,k);
  return val;
}

inline double operator*(const STensor33 &m, const STensor33 &t)
{
  double val(0.);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        val+=m(i,j,k)*t(k,j,i);
  return val;
}



#endif

