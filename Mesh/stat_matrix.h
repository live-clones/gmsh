// -*-c++-*-
#ifndef IG_STAT_MATRIX_H
#define IG_STAT_MATRIX_H

// $Id: stat_matrix.h,v 1.1.2.12 2005/07/02 15:41:46 hkuiper Exp $

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

#include <iostream>

// CWMatrix class

// This library was designed to mirror as closely as possible the
// notation used in mathematical writing. A matrix is indexed:
// matMatrixName[row][col].

// CAUTION!!!

// This matrix library was implemented with emphasis on
// speed. Consequently no attempts were made to trap and report
// errors. It is left entirely to the user to write code that does not
// cause errors within the matrix routines.

namespace CwMtx
{
  using std::ostream;
  
  // forward declarations

  template <unsigned r, unsigned c, class T>
  class CWTSMatrix;

  template <unsigned r, class T>
  class CWTSSquareMatrix;

  template <unsigned r, class T>
  class CWTSVector;

  template <class T>
  class CWTSSpaceVector;

  template <class T>
  class CWTSQuaternion;

  // Template classes that create zero "objects".

  template <class T>
  class CWTSZero
  {
  public:
    operator T() { return 0; }
  };

  template <unsigned r, unsigned c, class T>
  class CWTSZero< CWTSMatrix<r, c, T> >:
    public CWTSMatrix<r, c, T>
  {
  public:
    CWTSZero() { fill(CWTSZero<T>()); }
  };

  template <unsigned r, class T>
  class CWTSZero< CWTSSquareMatrix<r, T> >:
    public CWTSSquareMatrix<r, T>
  {
  public:
    CWTSZero() { fill(CWTSZero<T>()); }
  };

  template <unsigned r, class T>
  class CWTSZero< CWTSVector<r, T> >:
    public CWTSVector<r, T>
  {
  public:
    CWTSZero() { fill(CWTSZero<T>()); }
  };

  template <class T>
  class CWTSZero< CWTSSpaceVector<T> >:
    public CWTSSpaceVector<T>
  {
  public:
    CWTSZero() { fill(CWTSZero<T>()); }
  };

  template <class T>
  class CWTSZero< CWTSQuaternion<T> >:
    public CWTSQuaternion<T>
  {
  public:
    CWTSZero() { fill(CWTSZero<T>()); }
  };

  // Template classes that create unity "objects".

  template <class T>
  class CWTSUnity
  {
  public:
    operator T() { return 1; }
  };

  // NOTE: Only a matrix with an equal number of rows and columns can
  // be a unity matrix.
  template <unsigned r, class T>
  class CWTSUnity< CWTSMatrix<r, r, T> >:
    public CWTSSquareMatrix<r, T>
  {
  public:
    CWTSUnity() { this->makeUnity(); }
  };

  template <unsigned r, class T>
  class CWTSUnity< CWTSSquareMatrix<r, T> >:
    public CWTSSquareMatrix<r, T>
  {
  public:
    CWTSUnity() { this->makeUnity(); }
  };

  template <class T>
  class CWTSUnity< CWTSQuaternion<T> >:
    public CWTSQuaternion<T>
  {
  public:
    CWTSUnity()
    {
      (*this)[0] = (*this)[1] = (*this)[2] = CWTSZero<T>();
      (*this)[3] = CWTSUnity<T>();
    }
  };

  // This template defaults to double. Most of the time this template
  // will be working with math functions that only work with
  // doubles. For example, the transcendental function sin(x) takes
  // and returns a double which would force the compiler to convert
  // back and forth from some other data type to a double.

  // prefix mat
  template <unsigned r, unsigned c, class T = double>
  class CWTSMatrix
  {
  public:
    typedef T element;

    CWTSMatrix() {}
    CWTSMatrix(const CWTSMatrix &);

    ~CWTSMatrix() {}

    unsigned getRows() const { return r; }
    unsigned getCols() const { return c; }

    // basic matrix operations

    // returns a row of modifyable elements
    T* operator [](unsigned irow) { return m_rgrow[irow]; }
    // returns a row of non-modifyable elements
    const T* operator [](unsigned irow) const { return m_rgrow[irow]; }

    CWTSMatrix operator +(const CWTSMatrix &) const;
    CWTSMatrix operator -(const CWTSMatrix &) const;
    CWTSMatrix operator -() const;
    CWTSMatrix operator *(const T &) const;
    CWTSMatrix operator /(const T &value) const;

    // not inherited
    CWTSMatrix & operator =(const CWTSMatrix &);
    CWTSMatrix & operator +=(const CWTSMatrix &);
    CWTSMatrix & operator -=(const CWTSMatrix &);
    CWTSMatrix & operator *=(const T &);
    CWTSMatrix & operator /=(const T &value);

    bool operator ==(const CWTSMatrix &) const;
    bool operator !=(const CWTSMatrix &mat) const;

    void interchangeRows(unsigned, unsigned);
    void addRowToRow(unsigned, unsigned, const T & = CWTSUnity<T>());
    void multiplyRow(unsigned, const T &);

    // fills the whole array with a value.
    void fill(const T &);
    // stores matrix + matrix in this
    void storeSum(const CWTSMatrix &, const CWTSMatrix &);
    // stores CWMatrix at indicated position in this
    template <unsigned r2, unsigned c2>
    void storeAtPosition(unsigned, unsigned, const CWTSMatrix<r2, c2, T> &);

  private:
    // an array of rows
    T m_rgrow[r][c];
  };

  template <unsigned r, unsigned c, class T >
  inline CWTSMatrix<r, c, T>::CWTSMatrix(const CWTSMatrix<r, c, T> &mat)
  {
    // copy contents of input matrix
    (*this) = mat;
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T> 
  CWTSMatrix<r, c, T>::operator +(const CWTSMatrix<r, c, T> &mat) const
  {
    // copy this and add argument
    return CWTSMatrix(*this) += mat;
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T> 
  CWTSMatrix<r, c, T>::operator -(const CWTSMatrix<r, c, T> &mat) const
  {
    // copy this and subtract argument
    return CWTSMatrix(*this) -= mat;
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T>
  CWTSMatrix<r, c, T>::operator -() const
  {
    return (*this)*(CWTSZero<T>() - CWTSUnity<T>());
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T>
  CWTSMatrix<r, c, T>::operator *(const T &value) const
  {
    // copy this and multiply by argument
    return CWTSMatrix(*this) *= value;
  }

  template <unsigned r, unsigned c, class T>
  inline CWTSMatrix<r, c, T>
  CWTSMatrix<r, c, T>::operator /(const T &value) const
  {
    return (*this)*(CWTSUnity<T>()/value);
  }

  // assignment operator
  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T> & 
  CWTSMatrix<r, c, T>::operator =(const CWTSMatrix<r, c, T> &mat)
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    m_rgrow[irow][icol] = mat.m_rgrow[irow][icol];
	  }
      }

    return (*this);
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T> & 
  CWTSMatrix<r, c, T>::operator +=(const CWTSMatrix<r, c, T> &mat)
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    m_rgrow[irow][icol] += mat.m_rgrow[irow][icol];
	  }
      }

    return (*this);
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T> & 
  CWTSMatrix<r, c, T>::operator -=(const CWTSMatrix<r, c, T> &mat)
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    m_rgrow[irow][icol] -= mat.m_rgrow[irow][icol];
	  }
      }

    return (*this);
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T> &
  CWTSMatrix<r, c, T>::operator *=(const T &value)
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    m_rgrow[irow][icol] *= value;
	  }
      }

    return (*this);
  }

  template <unsigned r, unsigned c, class T>
  inline CWTSMatrix<r, c, T> &
  CWTSMatrix<r, c, T>::operator /=(const T &value)
  {
    return (*this) *= CWTSUnity<T>()/value;
  }

  template <unsigned r, unsigned c, class T>
  bool
  CWTSMatrix<r, c, T>::operator ==(const CWTSMatrix<r, c, T> &mat) const
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    if (m_rgrow[irow][icol] != mat.m_rgrow[irow][icol])
	      {
		return false;
	      }
	  }
      }

    return true;
  }

  template <unsigned r, unsigned c, class T>
  inline bool
  CWTSMatrix<r, c, T>::operator !=(const CWTSMatrix &mat) const
  {
    return !( (*this) == mat );
  }

  template <unsigned r, unsigned c, class T>
  void
  CWTSMatrix<r, c, T>::fill(const T &elemFill)
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    m_rgrow[irow][icol] = elemFill;
	  }
      }
  }

  // stores mat1 + mat2 in this
  template <unsigned r, unsigned c, class T>
  void
  CWTSMatrix<r, c, T>::storeSum(const CWTSMatrix<r, c, T> &mat1,
				const CWTSMatrix<r, c, T> &mat2)
  {
    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    m_rgrow[irow][icol] = 
	      mat1.m_rgrow[irow][icol] + mat2.m_rgrow[irow][icol];
	  }
      }
  }

  template <unsigned r, unsigned c, class T>
  template <unsigned r2, unsigned c2>
  void
  CWTSMatrix<r, c, T>::storeAtPosition(unsigned irowStart,
				       unsigned icolStart,
				       const CWTSMatrix<r2, c2, T> &mat)
  {
    for (unsigned irow = 0; irow < r2; ++irow)
      {
	for (unsigned icol = 0; icol < c2; ++icol)
	  {
	    m_rgrow[irow + irowStart][icol + icolStart] = mat[irow][icol];
	  }
      }
  }

  template <unsigned r, unsigned c, class T>
  void
  CWTSMatrix<r, c, T>::interchangeRows(unsigned irow1, unsigned irow2)
  {
    T elemTmp;

    for (unsigned icol = 0; icol < c; ++icol)
      {
	elemTmp = m_rgrow[irow1][icol];
	m_rgrow[irow1][icol] = m_rgrow[irow2][icol];
	m_rgrow[irow2][icol] = elemTmp;
      }
  }

  template <unsigned r, unsigned c, class T>
  void
  CWTSMatrix<r, c, T>::multiplyRow(unsigned irow, const T &value)
  {
    for (unsigned icol = 0; icol < c; ++icol)
      {
	m_rgrow[irow][icol] *= value;
      }
  }

  template <unsigned r, unsigned c, class T>
  void
  CWTSMatrix<r, c, T>::addRowToRow(unsigned irowSrc,
				   unsigned irowDest,
				   const T &value)
  {
    for (unsigned icol = 0; icol < c; ++icol)
      {
	m_rgrow[irowDest][icol] += m_rgrow[irowSrc][icol]*value;
      }
  }

  // template functions designed to work with the base matrix class

  template <unsigned r, unsigned c, class T>
  inline CWTSMatrix<r, c, T>
  operator *(const T &value, const CWTSMatrix<r, c, T> &mat)
  {
    return (mat*value);
  }

  template <unsigned r, unsigned c, unsigned c2, class T>
  CWTSMatrix<r, c2, T>
  operator *(CWTSMatrix<r, c, T> mat1, const CWTSMatrix<c, c2, T> &mat2)
  {
    CWTSMatrix<r, c2, T> matResult;

    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c2; ++icol)
	  {
	    matResult[irow][icol] = CWTSZero<T>();

	    for (unsigned icol2 = 0; icol2 < c; ++icol2)
	      {
		matResult[irow][icol] += mat1[irow][icol2]*mat2[icol2][icol];
	      }
	  }
      }

    return matResult;
  }

  template <unsigned r, unsigned c, class T>
  CWTSMatrix<r, c, T>
  transpose(const CWTSMatrix<c, r, T> &mat)
  {
    CWTSMatrix<r, c, T> matTranspose;

    for (unsigned irow = 0; irow < r; ++irow)
      {
	for (unsigned icol = 0; icol < c; ++icol)
	  {
	    matTranspose[irow][icol] = mat[icol][irow];
	  }
      }

    return matTranspose;
  }

  template <unsigned r, unsigned c, class T>
  ostream &
  operator <<(ostream &os, const CWTSMatrix<r, c, T> &mtx)
  {
    os << "[" ;

    for (unsigned i = 0; i < r; i++)
      {
	if (i > 0)
	  {
	    os << "; ";
	  }

        os << mtx[i][0];

	for (unsigned j = 1; j < c; j++)
	  {
	    os << ", " << mtx[i][j];
	  }
      }

    os << "]";

    return os;
  }

}

#endif // IG_STAT_MATRIX_H

