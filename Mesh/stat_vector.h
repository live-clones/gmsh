// -*-c++-*-
#ifndef IG_STAT_VECTOR_H
#define IG_STAT_VECTOR_H

// $Id: stat_vector.h,v 1.1.2.6 2005/05/30 09:14:25 hkuiper Exp $

// CwMtx matrix and vector math library
// Copyright (C) 1999-2001  Harry Kuiper
// Copyright (C) 2000  Will DeVore (template conversion)

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

#include <cmath>

#ifndef IG_STAT_MATRIX_H
#include "stat_matrix.h"
#endif

namespace CwMtx
{

  template <unsigned r, class T = double>
  class CWTSVector : public CWTSMatrix<r, 1, T>
  {
  public:
    CWTSVector(): CWTSMatrix<r, 1, T>() {}
    CWTSVector(const CWTSMatrix<r, 1, T>& mat): CWTSMatrix<r, 1, T>(mat) {}
    CWTSVector(const CWTSVector& vec): CWTSMatrix<r, 1, T>(vec) {}

    ~CWTSVector() {}

    T & operator [](unsigned irow);
    const T & operator [](unsigned irow) const;

    CWTSVector operator +(const CWTSVector &) const;
    CWTSVector operator -(const CWTSVector &) const;
    CWTSVector operator -() const;
    CWTSVector operator *(const T &) const;
    CWTSVector operator /(const T &value) const;
    // CWTSVector*CWTSVector, inner product
    T operator *(const CWTSVector &) const;

    // not inherited
    CWTSVector & operator =(const CWTSVector &vec);
    CWTSVector & operator +=(const CWTSVector &vec);
    CWTSVector & operator -=(const CWTSVector &vec);
    CWTSVector & operator *=(const T &value);
    CWTSVector & operator /=(const T &value);

    // CWTSVector norm
    T operator !() const { return (*this).norm(); }
    // returns vector norm (length)
    T norm() const;
    // returns a unit vector with same direction as this
    CWTSVector unit() const { return (*this)/norm(); }

    // make this a unit vector
    void makeUnit() { (*this) /= norm(); }

    template <unsigned r2>
    void storeAtRow(unsigned, const CWTSVector<r2, T> &);
  };

  template <unsigned r, class T>
  inline T &
  CWTSVector<r, T>::operator [](unsigned irow)
  {
    return this->CWTSMatrix<r, 1, T>::operator[](irow)[0];
  }

  template <unsigned r, class T>
  inline const T &
  CWTSVector<r, T>::operator [](unsigned irow) const
  {
    return this->CWTSMatrix<r, 1, T>::operator[](irow)[0];
  }

  // not inherited
  template <unsigned r, class T>
  inline CWTSVector<r, T> &
  CWTSVector<r, T>::operator =(const CWTSVector<r, T> &vec)
  {
    return static_cast<CWTSVector &>(CWTSMatrix<r, 1, T>::operator=(vec));
  }

  template <unsigned r, class T>
  inline CWTSVector<r, T> &
  CWTSVector<r, T>::operator +=(const CWTSVector<r, T> &vec)
  {
    return static_cast<CWTSVector &>(CWTSMatrix<r, 1, T>::operator+=(vec));
  }

  template <unsigned r, class T>
  inline CWTSVector<r, T> &
  CWTSVector<r, T>::operator -=(const CWTSVector<r, T> &vec)
  {
    return static_cast<CWTSVector &>(CWTSMatrix<r, 1, T>::operator-=(vec));
  }

  template <unsigned r, class T>
  inline CWTSVector<r, T> &
  CWTSVector<r, T>::operator *=(const T &value)
  {
    return static_cast<CWTSVector &>(CWTSMatrix<r, 1, T>::operator*=(value));
  }

  template <unsigned r, class T>
  inline CWTSVector<r, T> &
  CWTSVector<r, T>::operator /=(const T &value)
  {
    return (*this) *= CWTSUnity<T>()/value;
  }

  template <unsigned r, class T>
  CWTSVector<r, T>
  CWTSVector<r, T>::operator +(const CWTSVector<r, T> &vec) const
  {
    return CWTSVector<r, T>(*this) += vec;
  }

  template <unsigned r, class T>
  CWTSVector<r, T>
  CWTSVector<r, T>::operator -(const CWTSVector<r, T> &vec) const
  {
    return CWTSVector<r, T>(*this) -= vec;
  }

  template <unsigned r, class T>
  CWTSVector<r, T>
  CWTSVector<r, T>::operator -() const
  {
    return (*this)*(CWTSZero<T>() - CWTSUnity<T>());
  }

  template <unsigned r, class T>
  CWTSVector<r, T>
  CWTSVector<r, T>::operator *(const T &value) const
  {
    return CWTSVector<r, T>(*this) *= value;
  }

  template <unsigned r, class T>
  CWTSVector<r, T>
  CWTSVector<r, T>::operator /(const T &value) const
  {
    return (*this)*(CWTSUnity<T>()/value);
  }

  template <unsigned r, class T>
  T
  CWTSVector<r, T>::operator *(const CWTSVector<r, T> &vec) const
  {
    T elemResult = CWTSZero<T>();

    for (unsigned irow = 0; irow < r; ++irow)
      {
	elemResult += (*this)[irow]*vec[irow];
      }

    return elemResult;
  }

  // length of vector
  template <unsigned r, class T>
  T
  CWTSVector<r, T>::norm() const
  {
    T elemResult = CWTSZero<T>();

    elemResult = (*this)*(*this);

    return sqrt(elemResult);
  }

  template <unsigned r, class T>
  template <unsigned r2>
  inline void
  CWTSVector<r, T>::storeAtRow(unsigned irowStart,
			       const CWTSVector<r2, T> &vec)
  {
    CWTSMatrix<r, 1, T>::storeAtPosition(irowStart, 0, vec);
  }

  // template functions designed work with the vector class.

  template <unsigned r, class T>
  inline CWTSVector<r, T>
  operator *(const T &value, const CWTSVector<r, T> &vec)
  {
    return vec*value;
  }

  // matrix*vector must yield a vector
  template <unsigned r, unsigned c, class T>
  CWTSVector<r, T>
  operator *(const CWTSMatrix<r, c, T> &mat, const CWTSVector<r, T> &vec)
  {
    CWTSVector<r, T> vecResult;

    for (unsigned irow = 0; irow < r; ++irow)
      {
	vecResult[irow] = CWTSZero<T>();

	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    vecResult[irow] += mat[irow][icol]*vec[icol];
	  }
      }

    return vecResult;
  }

  // norm computation as a function
  template <unsigned r, class T>
  inline T
  norm(const CWTSVector<r, T> &vec)
  {
    return vec.norm();
  }

  // the sign of a vector is a unit vector with the same direction
  template <unsigned r, class T>
  inline CWTSVector<r, T>
  sgn(const CWTSVector<r, T> &vec)
  {
    return vec.unit();
  }
}

#endif // IG_STAT_VECTOR_H
