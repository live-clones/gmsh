// -*-c++-*-
#ifndef IG_STAT_SMATRIX_H
#define IG_STAT_SMATRIX_H

// $Id: stat_smatrix.h,v 1.1.2.7 2005/07/02 15:41:46 hkuiper Exp $

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

#ifndef IG_STAT_MATRIX_H
#include "stat_matrix.h"
#endif

namespace CwMtx
{
  // prefix smat
  template <unsigned r, class T = double>
  class CWTSSquareMatrix : public CWTSMatrix<r, r, T>
  {
  public:
    CWTSSquareMatrix(): CWTSMatrix<r, r, T>() {}
    CWTSSquareMatrix(const CWTSMatrix<r, r, T> &mat):
      CWTSMatrix<r, r, T>(mat) {}
    CWTSSquareMatrix(const CWTSSquareMatrix &smat):
      CWTSMatrix<r, r, T>(smat) {}

    ~CWTSSquareMatrix() {}

    CWTSSquareMatrix operator +(const CWTSSquareMatrix &) const;
    CWTSSquareMatrix operator -(const CWTSSquareMatrix &) const;
    CWTSSquareMatrix operator -() const;
    CWTSSquareMatrix operator *(const T &) const;
    CWTSSquareMatrix operator *(const CWTSSquareMatrix &) const;
    CWTSSquareMatrix operator /(const T &value) const;
    CWTSSquareMatrix operator /(const CWTSSquareMatrix &) const;

    // not inherited
    CWTSSquareMatrix & operator =(const CWTSSquareMatrix &smat);
    CWTSSquareMatrix & operator +=(const CWTSSquareMatrix &smat);
    CWTSSquareMatrix & operator -=(const CWTSSquareMatrix &smat);
    CWTSSquareMatrix & operator *=(const T &value);
    CWTSSquareMatrix & operator *=(const CWTSSquareMatrix &);
    CWTSSquareMatrix & operator /=(const T &value);
    CWTSSquareMatrix & operator /=(const CWTSSquareMatrix &);

    // stores the adjoint of argument in this
    void storeAdjoint(const CWTSSquareMatrix &);
    // stores the inverse of argument in this
    void storeInverse(const CWTSSquareMatrix &);
    // makes this its own adjoint
    void makeAdjoint();
    // makes this its own inverse
    void makeInverse();
    // makes this a unity matrix
    void makeUnity();
  };

  // not inherited
  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T> &
  CWTSSquareMatrix<r, T>::operator =(const CWTSSquareMatrix<r, T> &smat)
  {
    return
      static_cast<CWTSSquareMatrix<r, T> &>(CWTSMatrix<r, r, T>::
					    operator=(smat));
  }

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T> &
  CWTSSquareMatrix<r, T>::operator +=(const CWTSSquareMatrix<r, T> &smat)
  {
    return
      static_cast<CWTSSquareMatrix<r, T> &>(CWTSMatrix<r, r, T>::
					    operator+=(smat));
  }

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T> &
  CWTSSquareMatrix<r, T>::operator -=(const CWTSSquareMatrix &smat)
  {
    return
      static_cast<CWTSSquareMatrix<r, T> &>(CWTSMatrix<r, r, T>::
					    operator-=(smat));
  }

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T> &
  CWTSSquareMatrix<r, T>::operator *=(const T &value)
  {
    return
      static_cast<CWTSSquareMatrix<r, T> &>(CWTSMatrix<r, r, T>::
					    operator*=(value));
  }

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T> &
  CWTSSquareMatrix<r, T>::operator *=(const CWTSSquareMatrix<r, T> &smat)
  {
    return (*this) = (*this)*smat;
  }

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T> &
  CWTSSquareMatrix<r, T>::operator /=(const T &value)
  {
    return (*this) *= CWTSUnity<T>()/value;
  }

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T> &
  CWTSSquareMatrix<r, T>::operator /=(const CWTSSquareMatrix<r, T> &smat)
  {
    return (*this) = (*this)/smat;
  }

  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  CWTSSquareMatrix<r, T>::operator +(const CWTSSquareMatrix<r, T> &smat) const
  {
    return CWTSSquareMatrix(*this) += smat;
  }

  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  CWTSSquareMatrix<r, T>::operator -(const CWTSSquareMatrix<r, T> &smat) const
  {
    return CWTSSquareMatrix(*this) -= smat;
  }

  template <unsigned r, class T>
  CWTSSquareMatrix<r, T> CWTSSquareMatrix<r, T>::operator -() const
  {
    return (*this)*(CWTSZero<T>() - CWTSUnity<T>());
  }

  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  CWTSSquareMatrix<r, T>::operator *(const T &value) const
  {
    return CWTSSquareMatrix(*this) *= value;
  }

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T>
  CWTSSquareMatrix<r, T>::operator /(const T &value) const
  {
    return (*this)*(CWTSUnity<T>()/value);
  }

  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  CWTSSquareMatrix<r, T>::operator *(const CWTSSquareMatrix<r, T> &smat) const
  {
    CWTSSquareMatrix<r, T> smatResult;

    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < r; ++icol)
	  {
	    smatResult[irow][icol] = CWTSZero<T>();

	    for (unsigned icol2 = 0; icol2 < r; ++icol2)
	      {
		smatResult[irow][icol] +=
		  (*this)[irow][icol2]*smat[icol2][icol];
	      }
	  }
      }

    return smatResult;
  }

  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  CWTSSquareMatrix<r, T>::operator /(const CWTSSquareMatrix<r, T> &smat) const
  {
    return (*this)*inv(smat);
  }

  // stores inverse of argument in this
  template <unsigned r, class T>
  void
  CWTSSquareMatrix<r, T>::storeInverse(const CWTSSquareMatrix<r, T> &smat)
  {
    // copy input matrix in this
    (*this) = smat;
    makeInverse();
  }

  // makes this a unity matrix
  template <unsigned r, class T>
  void
  CWTSSquareMatrix<r, T>::makeUnity()
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < r; ++icol)
	  {
	    if (irow == icol)
	      {
		(*this)[irow][icol] = CWTSUnity<T>();
	      }
	    else
	      {
		(*this)[irow][icol] = CWTSZero<T>();
	      }
	  }
      }
  }

  // makes this its own adjoint
  template <unsigned r, class T>
  void
  CWTSSquareMatrix<r, T>::makeAdjoint()
  {
    // we need a copy of this
    CWTSSquareMatrix<r, T> smatCopy(*this);
    T elemTmp;
    // will eventually contain det(smatCopy)
    T elemDet = CWTSUnity<T>();

    // make this a unity matrix
    makeUnity();

    // start row reduction
    for (unsigned irow = 0; irow < r; ++irow)
      {
	// if element [irow][irow] is zero, add a row with non-zero
	// element at column irow
	if (smatCopy[irow][irow] == CWTSZero<T>())
	  {
	    for (unsigned irowTmp = irow; irowTmp < r; ++irowTmp)
	      {
		if (smatCopy[irowTmp][irow] != CWTSZero<T>())
		  {
		    // has no effect on adj(smat)
		    smatCopy.addRowToRow(irowTmp, irow);
		    // repeat action on this
		    this->addRowToRow(irowTmp, irow);
		    break;
		  }
	      }
	  }

	elemTmp = smatCopy[irow][irow];
        T tTmp = CWTSUnity<T>();
        tTmp /= elemTmp;
	smatCopy.multiplyRow(irow, tTmp);
	// repeat action on this
	multiplyRow(irow, tTmp);
	elemDet *= elemTmp;

	for (unsigned irowToAddTo = 0; irowToAddTo < r; ++irowToAddTo)
	  {
	    if (irowToAddTo != irow)
	      {
		elemTmp = -smatCopy[irowToAddTo][irow];
		smatCopy.addRowToRow(irow, irowToAddTo, elemTmp);
		// repeat action on this
		addRowToRow(irow, irowToAddTo, elemTmp);
	      }
	  }
      }

    // this now contains its adjoint
    (*this) *= elemDet;
  }

  // stores adjoint of input matrix in this
  template <unsigned r, class T>
  void
  CWTSSquareMatrix<r, T>::storeAdjoint(const CWTSSquareMatrix<r, T> &smat)
  {
    // copy input matrix in this
    (*this) = smat;
    makeAdjoint();
  }

  // makes this its own inverse
  template <unsigned r, class T>
  void
  CWTSSquareMatrix<r, T>::makeInverse()
  {
    // we need a copy of this
    CWTSSquareMatrix<r, T> smatCopy(*this);
    T elemTmp;

    // make this a unity matrix
    makeUnity();

    // start row reduction
    for (unsigned irow = 0; irow < r; ++irow)
      {
	// if element [irow][irow] is zero, add a row with non-zero
	// element at column irow
	if (smatCopy[irow][irow] == CWTSZero<T>())
	  {
	    for (unsigned irowTmp = irow; irowTmp < r; ++irowTmp)
	      {
		// has no effect on inv(smat)
		if (smatCopy[irowTmp][irow] != CWTSZero<T>())
		  {
		    smatCopy.addRowToRow(irowTmp, irow);
		    // repeat action on this
		    this->addRowToRow(irowTmp, irow);
		    break;
		  }
	      }
	  }

	elemTmp = smatCopy[irow][irow];
        T tTmp = CWTSUnity<T>();
        tTmp /= elemTmp;
	smatCopy.multiplyRow(irow, tTmp);
	multiplyRow(irow, tTmp);

	for (unsigned irowToAddTo = 0; irowToAddTo < r; ++irowToAddTo)
	  {
	    if (irowToAddTo != irow)
	      {
		elemTmp = -smatCopy[irowToAddTo][irow];
		smatCopy.addRowToRow(irow, irowToAddTo, elemTmp);
		// repeat action on this
		addRowToRow(irow, irowToAddTo, elemTmp);
	      }
	  }
      }

    // this now contains its inverse
  }

  // template functions designed work with the Square Matrix class.

  template <unsigned r, class T>
  inline CWTSSquareMatrix<r, T>
  operator *(const T &value, const CWTSSquareMatrix<r, T> &smat)
  {
    return smat*value;
  }

  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  transpose(const CWTSSquareMatrix<r, T> &smat)
  {
    CWTSSquareMatrix<r, T> smatTranspose;

    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < r; ++icol)
	  {
	    smatTranspose[irow][icol] = smat[icol][irow];
	  }
      }

    return smatTranspose;
  }

  // returns the adjoint of a square matrix
  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  adj(const CWTSSquareMatrix<r, T> &smat)
  {
    CWTSSquareMatrix<r, T> smatResult(smat);   // copy input matrix
    smatResult.makeAdjoint();
    return smatResult;
  }

  // calculates the inverse of a square matrix
  template <unsigned r, class T>
  CWTSSquareMatrix<r, T>
  inv(const CWTSSquareMatrix<r, T> &smat)
  {
    // copy input matrix
    CWTSSquareMatrix<r, T> smatResult(smat);
    smatResult.makeInverse();
    return smatResult;
  }

  // calculates the determinant of a square matrix
  template <unsigned r, class T>
  T
  det(const CWTSSquareMatrix<r, T> &smat)
  {
    // a copy of the input matrix
    CWTSSquareMatrix<r, T> smatCopy(smat);

    // start row reduction
    T elemTmp;
    // will eventually contain det(smatCopy)
    T elemDet = CWTSUnity<T>();

    for (unsigned irow = 0; irow < r; ++irow)
      {
	// if element [irow][irow] is zero, add a row with non-zero
	// element at column irow
	if (smatCopy[irow][irow] == CWTSZero<T>())
	  {
	    for (unsigned irowTmp = irow; irowTmp < r; ++irowTmp)
	      {
		// has no effect on inv(smat)
		if (smatCopy[irowTmp][irow] != CWTSZero<T>())
		  {
		    smatCopy.addRowToRow(irowTmp, irow);
		    break;
		  }
	      }
	  }

	elemTmp = smatCopy[irow][irow];
	elemDet *= elemTmp;

	if (elemDet == CWTSZero<T>())
	  {
	    // once elemDet is zero it will stay zero
	    return elemDet;
	  }

	smatCopy.multiplyRow(irow, CWTSUnity<T>()/elemTmp);

	for (unsigned irowToAddTo = 0; irowToAddTo < r; ++irowToAddTo)
	  {
	    if (irowToAddTo != irow)
	      {
		smatCopy.addRowToRow(irow,
				     irowToAddTo,
				     -smatCopy[irowToAddTo][irow]);
	      }
	  }
      }

    return elemDet;
  }

  // trace
  template <unsigned r, class T>
  T
  tr(const CWTSSquareMatrix<r, T> &smat)
  {
    T elemTmp = CWTSZero<T>();

    for (unsigned c = 0; c < r; c++)
      {
	elemTmp += smat[c][c];
      }

    return elemTmp;
  }

}

#endif // IG_STAT_SMATRIX_H
