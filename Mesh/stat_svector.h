// -*-c++-*-
#ifndef IG_STAT_SVECTOR_H
#define IG_STAT_SVECTOR_H

// $Id: stat_svector.h,v 1.1.2.7 2005/07/02 15:41:46 hkuiper Exp $

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

#ifndef IG_STAT_VECTOR_H
#include "stat_vector.h"
#endif

#ifndef IG_STAT_SMATRIX_H
#include "stat_smatrix.h"
#endif

namespace CwMtx
{

  // prefix svec
  template <class T = double>
  class CWTSSpaceVector: public CWTSVector<3, T>
  {
  public:
    CWTSSpaceVector(): CWTSVector<3, T>() {}
    CWTSSpaceVector(const CWTSMatrix<3, 1, T> &mat): CWTSVector<3, T>(mat) {}
    CWTSSpaceVector(const CWTSVector<3, T> &vec): CWTSVector<3, T>(vec) {}
    CWTSSpaceVector(const CWTSSpaceVector &svec): CWTSVector<3, T>(svec) {}
    // construct from 3 elements
    CWTSSpaceVector(const T &, const T &, const T &);

    ~CWTSSpaceVector() {}

    CWTSSpaceVector operator +(const CWTSSpaceVector &) const;
    CWTSSpaceVector operator -(const CWTSSpaceVector &) const;
    CWTSSpaceVector operator -() const;
    CWTSSpaceVector operator *(const T &) const;
    // inner product
    T operator *(const CWTSSpaceVector &) const;
    // outer product
    CWTSSpaceVector operator %(const CWTSSpaceVector &) const;
    CWTSSpaceVector operator /(const T &value) const;

    // not inherited
    CWTSSpaceVector & operator =(const CWTSSpaceVector &);
    CWTSSpaceVector & operator +=(const CWTSSpaceVector &);
    CWTSSpaceVector & operator -=(const CWTSSpaceVector &);
    CWTSSpaceVector & operator *=(const T &);
    // outer product
    CWTSSpaceVector & operator %=(const CWTSSpaceVector &);
    CWTSSpaceVector & operator /=(const T &value);

    void storeOuterProduct(const CWTSSpaceVector &, const CWTSSpaceVector &);

    // returns a unit vector with same direction as this
    CWTSSpaceVector unit() const { return (*this)/(this->norm()); }
  };

  template <class T>
  inline CWTSSpaceVector<T>::CWTSSpaceVector(const T &elem1,
					     const T &elem2,
					     const T &elem3)
    :
    CWTSVector<3, T>()
  {
    (*this)[0] = elem1;
    (*this)[1] = elem2;
    (*this)[2] = elem3;
  }

  template <class T>
  inline CWTSSpaceVector<T>
  CWTSSpaceVector<T>::operator /(const T &value) const
  {
    return (*this)*(CWTSUnity<T>()/value);
  }

  // not inherited
  template <class T>
  inline CWTSSpaceVector<T> &
  CWTSSpaceVector<T>::operator =(const CWTSSpaceVector<T> &svec)
  {
    return
      static_cast<CWTSSpaceVector &>(CWTSMatrix<3, 1, T>::operator=(svec));
  }

  template <class T>
  inline CWTSSpaceVector<T> &
  CWTSSpaceVector<T>::operator +=(const CWTSSpaceVector<T> &svec)
  {
    return
      static_cast<CWTSSpaceVector &>(CWTSMatrix<3, 1, T>::operator+=(svec));
  }

  template <class T>
  inline CWTSSpaceVector<T> &
  CWTSSpaceVector<T>::operator -=(const CWTSSpaceVector<T> &svec)
  {
    return
      static_cast<CWTSSpaceVector &>(CWTSMatrix<3, 1, T>::operator-=(svec));
  }

  template <class T>
  inline CWTSSpaceVector<T> &
  CWTSSpaceVector<T>::operator *=(const T &value)
  {
    return
      static_cast<CWTSSpaceVector &>(
				     CWTSMatrix<3, 1, T>::operator*=(value));
  }

  template <class T>
  inline CWTSSpaceVector<T> &
  CWTSSpaceVector<T>::operator /=(const T &value)
  {
    return (*this) *= CWTSUnity<T>()/value;
  }

  // outer product
  template <class T>
  inline CWTSSpaceVector<T> &
  CWTSSpaceVector<T>::operator %=(const CWTSSpaceVector<T> &vec)
  {
    return (*this) = (*this)%vec;
  }

  template <class T>
  CWTSSpaceVector<T>
  CWTSSpaceVector<T>::operator +(const CWTSSpaceVector<T> &svec) const
  {
    return CWTSSpaceVector(*this) += svec;
  }

  template <class T>
  CWTSSpaceVector<T>
  CWTSSpaceVector<T>::operator -(const CWTSSpaceVector<T> &svec) const
  {
    return CWTSSpaceVector(*this) -= svec;
  }

  template <class T>
  CWTSSpaceVector<T>
  CWTSSpaceVector<T>::operator -() const
  {
    return (*this)*(CWTSZero<T>() - CWTSUnity<T>());
  }

  template <class T>
  CWTSSpaceVector<T>
  CWTSSpaceVector<T>::operator *(const T &value) const
  {
    return CWTSSpaceVector(*this) *= value;
  }

  // inner product
  template <class T>
  T
  CWTSSpaceVector<T>::operator *(const CWTSSpaceVector<T> &vec) const
  {
    return CWTSVector<3, T>::operator*(vec);
  }

  template <class T>
  void
  CWTSSpaceVector<T>::storeOuterProduct(const CWTSSpaceVector<T> &svecLeft,
					const CWTSSpaceVector<T> &svecRight)
  {
    // to reduce the number of calls to the subscript operator
    T svecLeft0 = svecLeft[0];
    T svecLeft1 = svecLeft[1];
    T svecLeft2 = svecLeft[2];

    T svecRight0 = svecRight[0];
    T svecRight1 = svecRight[1];
    T svecRight2 = svecRight[2];

    (*this)[0] = svecLeft1*svecRight2 - svecLeft2*svecRight1;
    (*this)[1] = svecLeft2*svecRight0 - svecLeft0*svecRight2;
    (*this)[2] = svecLeft0*svecRight1 - svecLeft1*svecRight0;
  }

  template <class T>
  CWTSSpaceVector<T>
  CWTSSpaceVector<T>::operator %(const CWTSSpaceVector<T> &svec) const
  {
    CWTSSpaceVector<T> svecResult;
    svecResult.storeOuterProduct(*this, svec);
    return svecResult;
  }

  // template functions designed work with the base matrix class.

  template <class T>
  inline CWTSSpaceVector<T>
  operator *(const T &value, const CWTSSpaceVector<T> &svec)
  {
    return svec*value;
  }

  // (square matrix)*(space vector) must yield a space vector
  template <class T>
  CWTSSpaceVector<T>
  operator *(const CWTSSquareMatrix<3, T> &smat,
	     const CWTSSpaceVector<T> &svec)
  {
    CWTSSpaceVector<T> svecResult;

    for (unsigned irow = 0; irow < 3; ++irow)
      {
	svecResult[irow] = CWTSZero<T>();

	for (unsigned icol = 0; icol < 3; ++icol)
	  {
	    svecResult[irow] += smat[irow][icol]*svec[icol];
	  }
      }

    return svecResult;
  }

  // the sign of a vector is a unit vector with the same direction
  template <class T>
  inline CWTSSpaceVector<T>
  sgn(const CWTSSpaceVector<T> &svec)
  {
    return svec.unit();
  }
}

#endif // IG_STAT_SVECTOR_H
