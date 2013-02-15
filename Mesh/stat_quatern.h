// -*-c++-*-
#ifndef IG_STAT_QUATERN_H
#define IG_STAT_QUATERN_H

// $Id: stat_quatern.h,v 1.1.2.8 2005/07/02 15:41:46 hkuiper Exp $

// CwMtx matrix and vector math library
// Copyright (C) 1999-2001  Harry Kuiper
// Copyright (C) 2000  Will DeVore (template conversion)
// Copyright (C) 2000  Jiri Ecer (constructor from exponential form)

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA

#ifndef IG_STAT_SVECTOR_H
#include "stat_svector.h"
#endif

namespace CwMtx
{
  using std::exp;
  using std::log;

  // prefix qtn
  template <class T = double>
  class CWTSQuaternion : public CWTSVector<4, T>
  {
  public:
    CWTSQuaternion(): CWTSVector<4, T>() {}
    CWTSQuaternion(const CWTSMatrix<4, 1, T> &mat): CWTSVector<4, T>(mat) {}
    // assumption: vec has four elements
    CWTSQuaternion(const CWTSVector<4, T> &vec): CWTSVector<4, T>(vec) {}
    CWTSQuaternion(const CWTSQuaternion &qtn): CWTSVector<4, T>(qtn) {}
    // the space vector will become the quaternion's imaginary part, T
    // will become its real part
    CWTSQuaternion(const CWTSSpaceVector<T> &, const T & = CWTSZero<T>());
    // creates a quaternion, index runs from left to right
    CWTSQuaternion(const T &, const T &, const T &, const T &);
    // creates a quaternion from a scalar
    CWTSQuaternion(const T &);

    // constructor from exponential form: q = r*exp(svec*angle), svec
    // should be a unity vector, angle is in radians
    CWTSQuaternion(const T &r, const CWTSSpaceVector<T> &svec, const T &angle);

    ~CWTSQuaternion() {}

    CWTSQuaternion operator +(const CWTSQuaternion &) const;
    CWTSQuaternion operator -(const CWTSQuaternion &) const;
    CWTSQuaternion operator -() const;
    CWTSQuaternion operator *(const T &) const;
    CWTSQuaternion operator *(const CWTSQuaternion &) const;
    CWTSQuaternion operator /(const T &value) const;
    CWTSQuaternion operator /(const CWTSQuaternion &) const;

    // not inherited
    CWTSQuaternion & operator =(const CWTSQuaternion &);
    CWTSQuaternion & operator +=(const CWTSQuaternion &);
    CWTSQuaternion & operator -=(const CWTSQuaternion &);
    CWTSQuaternion & operator *=(const T &);
    CWTSQuaternion & operator *=(const CWTSQuaternion &);
    CWTSQuaternion & operator /=(const T &);
    CWTSQuaternion & operator /=(const CWTSQuaternion &);

    // stores product of qtn*qtn in this
    void storeProduct(const CWTSQuaternion &, const CWTSQuaternion &);
    // stores conjugate of argument in this
    void storeConjugate(const CWTSQuaternion &);
    // makes this its own conjugate
    void makeConjugate();

    // returns a unit quaternion with same direction as this
    CWTSQuaternion unit() const { return (*this)/(this->norm()); }
  };

  template <class T>
  inline CWTSQuaternion<T>::CWTSQuaternion(const T &elemIm0,
					   const T &elemIm1,
					   const T &elemIm2,
					   const T &elemReal)
    :
    CWTSVector<4, T>()
  {
    (*this)[0] = elemIm0;
    (*this)[1] = elemIm1;
    (*this)[2] = elemIm2;
    (*this)[3] = elemReal;
  }

  template <class T>
  inline CWTSQuaternion<T>::CWTSQuaternion(const T &elemReal)
  {
    (*this)[0] = CWTSZero<T>();
    (*this)[1] = CWTSZero<T>();
    (*this)[2] = CWTSZero<T>();
    (*this)[3] = elemReal;
  }

  template <class T>
  inline CWTSQuaternion<T>::CWTSQuaternion(const CWTSSpaceVector<T> &svecIm,
					   const T &elemReal)
    :
    CWTSVector<4, T>()
  {
    (*this)[0] = svecIm[0];
    (*this)[1] = svecIm[1];
    (*this)[2] = svecIm[2];
    (*this)[3] = elemReal;
  }

  // NOTE: This only works with template arguments that can be
  // converted to floating point types due to the use of sin(3) and
  // cos(3).
  template <class T>
  CWTSQuaternion<T>::CWTSQuaternion(const T &r,
				    const CWTSSpaceVector<T> &svec,
				    const T &angle)
    :
    CWTSVector<4, T>()
  {
    T rsina = r*sin(angle);

    (*this)[0] = svec[0]*rsina;
    (*this)[1] = svec[1]*rsina;
    (*this)[2] = svec[2]*rsina;
    (*this)[3] = r*cos(angle);
  }

  // not inherited
  template <class T>
  inline CWTSQuaternion<T> &
  CWTSQuaternion<T>::operator =(const CWTSQuaternion<T> &qtn)
  {
    return static_cast<CWTSQuaternion &>(CWTSMatrix<4, 1, T>::operator=(qtn));
  }

  template <class T>
  inline CWTSQuaternion<T> &
  CWTSQuaternion<T>::operator +=(const CWTSQuaternion<T> &qtn)
  {
    return static_cast<CWTSQuaternion &>(CWTSMatrix<4, 1, T>::operator+=(qtn));
  }

  template <class T>
  inline CWTSQuaternion<T> &
  CWTSQuaternion<T>::operator -=(const CWTSQuaternion<T> &qtn)
  {
    return static_cast<CWTSQuaternion &>(CWTSMatrix<4, 1, T>::operator-=(qtn));
  }

  template <class T>
  inline CWTSQuaternion<T> &
  CWTSQuaternion<T>::operator *=(const T &value)
  {
    return
      static_cast<CWTSQuaternion &>(CWTSMatrix<4, 1, T>::operator*=(value));
  }

  template <class T>
  inline CWTSQuaternion<T> &
  CWTSQuaternion<T>::operator *=(const CWTSQuaternion<T> &qtn)
  {
    return (*this) = (*this)*qtn;
  }

  template <class T>
  inline CWTSQuaternion<T> &
  CWTSQuaternion<T>::operator /=(const T &value)
  {
    return (*this) *= CWTSUnity<T>()/value;
  }

  template <class T>
  inline CWTSQuaternion<T> &
  CWTSQuaternion<T>::operator /=(const CWTSQuaternion<T> &qtn)
  {
    return (*this) = (*this)/qtn;
  }

  template <class T>
  CWTSQuaternion<T>
  CWTSQuaternion<T>::operator +(const CWTSQuaternion<T> &qtn) const
  {
    return CWTSQuaternion(*this) += qtn;
  }

  template <class T>
  CWTSQuaternion<T>
  CWTSQuaternion<T>::operator -(const CWTSQuaternion<T> &qtn) const
  {
    return CWTSQuaternion(*this) -= qtn;
  }

  template <class T>
  CWTSQuaternion<T>
  CWTSQuaternion<T>::operator -() const
  {
    return (*this)*(CWTSZero<T>() - CWTSUnity<T>());
  }

  template <class T>
  CWTSQuaternion<T>
  CWTSQuaternion<T>::operator *(const T &value) const
  {
    return CWTSQuaternion(*this) *= value;
  }

  template <class T>
  inline CWTSQuaternion<T>
  CWTSQuaternion<T>::operator /(const T &value) const
  {
    return (*this)*(CWTSUnity<T>()/value);
  }

  template <class T>
  void
  CWTSQuaternion<T>::storeProduct(const CWTSQuaternion<T> &qtnLeft,
				  const CWTSQuaternion<T> &qtnRight)
  {
    // to reduce the number of calls to the subscript operator
    T qtnLeft0 = qtnLeft[0];
    T qtnLeft1 = qtnLeft[1];
    T qtnLeft2 = qtnLeft[2];
    T qtnLeft3 = qtnLeft[3];

    T qtnRight0 = qtnRight[0];
    T qtnRight1 = qtnRight[1];
    T qtnRight2 = qtnRight[2];
    T qtnRight3 = qtnRight[3];

    (*this)[0] =
      qtnLeft0*qtnRight3 + qtnLeft1*qtnRight2
      - qtnLeft2*qtnRight1 + qtnLeft3*qtnRight0;

    (*this)[1] =
      -qtnLeft0*qtnRight2 + qtnLeft1*qtnRight3
      + qtnLeft2*qtnRight0 + qtnLeft3*qtnRight1;

    (*this)[2] =
      qtnLeft0*qtnRight1 - qtnLeft1*qtnRight0
      + qtnLeft2*qtnRight3 + qtnLeft3*qtnRight2;

    (*this)[3] =
      -qtnLeft0*qtnRight0 - qtnLeft1*qtnRight1
      - qtnLeft2*qtnRight2 + qtnLeft3*qtnRight3;
  }

  template <class T>
  CWTSQuaternion<T>
  CWTSQuaternion<T>::operator *(const CWTSQuaternion<T> &qtn) const
  {
    CWTSQuaternion qtnResult;
    qtnResult.storeProduct(*this, qtn);
    return qtnResult;
  }

  template <class T>
  CWTSQuaternion<T>
  CWTSQuaternion<T>::operator /(const CWTSQuaternion<T> &qtn) const
  {
    return (*this)*inv(qtn);
  }

  // stores conjugate of argument in this
  template <class T>
  void
  CWTSQuaternion<T>::storeConjugate(const CWTSQuaternion<T> &qtn)
  {
    // copy argument into this
    (*this) = qtn;
    makeConjugate();
  }

  template <class T>
  void
  CWTSQuaternion<T>::makeConjugate()
  {
    T tmp = CWTSZero<T>() - CWTSUnity<T>();

    (*this)[0] *= tmp;
    (*this)[1] *= tmp;
    (*this)[2] *= tmp;
  }

  // template functions designed work with the Quaternion class.

  template <class T>
  inline CWTSQuaternion<T>
  operator *(const T &value, const CWTSQuaternion<T> &qtn)
  {
    return qtn*value;
  }

  // return real part of a quaternion
  template <class T>
  inline T
  re(const CWTSQuaternion<T> &qtn)
  {
    return qtn[3];
  }

  // returns imaginary (vector) part of a quaternion
  template <class T>
  CWTSSpaceVector<T>
  im(const CWTSQuaternion<T> &qtn)
  {
    return CWTSSpaceVector<T>(qtn[0], qtn[1], qtn[2]);
  }

  // the conjugate
  template <class T>
  CWTSQuaternion<T>
  conj(const CWTSQuaternion<T> &qtn)
  {
    // copy input quaternion
    CWTSQuaternion<T> qtnResult(qtn);
    qtnResult.makeConjugate();
    return qtnResult;
  }

  // the inverse
  template <class T>
  CWTSQuaternion<T>
  inv(const CWTSQuaternion<T> &qtn)
  {
    T qtn0 = qtn[0];
    T qtn1 = qtn[1];
    T qtn2 = qtn[2];
    T qtn3 = qtn[3];

    return conj(qtn)/static_cast<const T &>(qtn0*qtn0
                                            + qtn1*qtn1
                                            + qtn2*qtn2
                                            + qtn3*qtn3);
  }

  // the sign of a quaternion is a unit quaternion with the same
  // direction
  template <class T>
  inline CWTSQuaternion<T>
  sgn(const CWTSQuaternion<T> &qtn)
  {
    return qtn.unit();
  }

  // the argument of a quaternion is the angle between it and the
  // scalar number 1 (analogous to the argument of a complex number)
  template <class T>
  inline T
  arg(const CWTSQuaternion<T> &qtn)
  {
    return atan2(norm(im(qtn)), re(qtn));
  }

  // quaternion exponentiation
  template <class T>
  CWTSQuaternion<T>
  exp(const CWTSQuaternion<T> &qtn)
  {
    CWTSSpaceVector<T> svec = im(qtn);
    T len = norm(svec);

    if (len == CWTSZero<T>())
      {
        return exp(re(qtn))*CWTSQuaternion<T>(CWTSZero<T>(),
                                              CWTSZero<T>(),
                                              CWTSZero<T>(),
                                              cos(len));
      }
    else
      {
        return exp(re(qtn))*CWTSQuaternion<T>(sgn(svec)*sin(len), cos(len));
      }
  }

  // quaternion logarithm (with base e)
  template <class T>
  CWTSQuaternion<T>
  log(const CWTSQuaternion<T> &qtn)
  {
    CWTSSpaceVector<T> svec = im(qtn);
    T len = norm(svec);

    if (len == CWTSZero<T>())
      {
        return CWTSQuaternion<T>(CWTSZero<T>(),
                                 CWTSZero<T>(),
                                 CWTSZero<T>(),
                                 log(norm(qtn)));
      }
    else
      {
        return CWTSQuaternion<T>(sgn(svec)*arg(qtn), log(norm(qtn)));
      }
  }

  // quaternion power! raise qtn1 to the power qtn2
  template <class T>
  inline CWTSQuaternion<T>
  pow(const CWTSQuaternion<T> &qtn1, const CWTSQuaternion<T> &qtn2)
  {
    return exp(qtn2*log(qtn1));
  }
}

#endif // IG_STAT_QUATERN_H
