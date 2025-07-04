/*************************************************************************
Copyright (c) Sergey Bochkanov (ALGLIB project).

>>> SOURCE LICENSE >>>
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation (www.fsf.org); either version 2 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

A copy of the GNU General Public License is available at
http://www.fsf.org/licensing/licenses
>>> END OF LICENSE >>>
*************************************************************************/
#include "stdafx.h"
#include "linalg.h"

// disable some irrelevant warnings
#if (AE_COMPILER==AE_MSVC)
#pragma warning(disable:4100)
#pragma warning(disable:4127)
#pragma warning(disable:4702)
#pragma warning(disable:4996)
#endif
using namespace std;

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS IMPLEMENTATION OF C++ INTERFACE
//
/////////////////////////////////////////////////////////////////////////
namespace alglib
{


/*************************************************************************
Cache-oblivous complex "copy-and-transpose"

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    A   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void cmatrixtranspose(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, complex_2d_array &b, const ae_int_t ib, const ae_int_t jb)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixtranspose(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), ib, jb, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Cache-oblivous real "copy-and-transpose"

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    A   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void rmatrixtranspose(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, real_2d_array &b, const ae_int_t ib, const ae_int_t jb)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixtranspose(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), ib, jb, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Copy

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    B   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void cmatrixcopy(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, complex_2d_array &b, const ae_int_t ib, const ae_int_t jb)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixcopy(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), ib, jb, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Copy

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    B   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void rmatrixcopy(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, real_2d_array &b, const ae_int_t ib, const ae_int_t jb)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixcopy(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), ib, jb, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Rank-1 correction: A := A + u*v'

INPUT PARAMETERS:
    M   -   number of rows
    N   -   number of columns
    A   -   target matrix, MxN submatrix is updated
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    U   -   vector #1
    IU  -   subvector offset
    V   -   vector #2
    IV  -   subvector offset
*************************************************************************/
void cmatrixrank1(const ae_int_t m, const ae_int_t n, complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, complex_1d_array &u, const ae_int_t iu, complex_1d_array &v, const ae_int_t iv)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixrank1(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, const_cast<alglib_impl::ae_vector*>(u.c_ptr()), iu, const_cast<alglib_impl::ae_vector*>(v.c_ptr()), iv, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Rank-1 correction: A := A + u*v'

INPUT PARAMETERS:
    M   -   number of rows
    N   -   number of columns
    A   -   target matrix, MxN submatrix is updated
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    U   -   vector #1
    IU  -   subvector offset
    V   -   vector #2
    IV  -   subvector offset
*************************************************************************/
void rmatrixrank1(const ae_int_t m, const ae_int_t n, real_2d_array &a, const ae_int_t ia, const ae_int_t ja, real_1d_array &u, const ae_int_t iu, real_1d_array &v, const ae_int_t iv)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixrank1(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, const_cast<alglib_impl::ae_vector*>(u.c_ptr()), iu, const_cast<alglib_impl::ae_vector*>(v.c_ptr()), iv, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Matrix-vector product: y := op(A)*x

INPUT PARAMETERS:
    M   -   number of rows of op(A)
            M>=0
    N   -   number of columns of op(A)
            N>=0
    A   -   target matrix
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    OpA -   operation type:
            * OpA=0     =>  op(A) = A
            * OpA=1     =>  op(A) = A^T
            * OpA=2     =>  op(A) = A^H
    X   -   input vector
    IX  -   subvector offset
    IY  -   subvector offset

OUTPUT PARAMETERS:
    Y   -   vector which stores result

if M=0, then subroutine does nothing.
if N=0, Y is filled by zeros.


  -- ALGLIB routine --

     28.01.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixmv(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t opa, const complex_1d_array &x, const ae_int_t ix, complex_1d_array &y, const ae_int_t iy)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixmv(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, opa, const_cast<alglib_impl::ae_vector*>(x.c_ptr()), ix, const_cast<alglib_impl::ae_vector*>(y.c_ptr()), iy, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Matrix-vector product: y := op(A)*x

INPUT PARAMETERS:
    M   -   number of rows of op(A)
    N   -   number of columns of op(A)
    A   -   target matrix
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    OpA -   operation type:
            * OpA=0     =>  op(A) = A
            * OpA=1     =>  op(A) = A^T
    X   -   input vector
    IX  -   subvector offset
    IY  -   subvector offset

OUTPUT PARAMETERS:
    Y   -   vector which stores result

if M=0, then subroutine does nothing.
if N=0, Y is filled by zeros.


  -- ALGLIB routine --

     28.01.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixmv(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t opa, const real_1d_array &x, const ae_int_t ix, real_1d_array &y, const ae_int_t iy)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixmv(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, opa, const_cast<alglib_impl::ae_vector*>(x.c_ptr()), ix, const_cast<alglib_impl::ae_vector*>(y.c_ptr()), iy, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
This subroutine calculates X*op(A^-1) where:
* X is MxN general matrix
* A is NxN upper/lower triangular/unitriangular matrix
* "op" may be identity transformation, transposition, conjugate transposition

Multiplication result replaces X.
Cache-oblivious algorithm is used.

INPUT PARAMETERS
    N   -   matrix size, N>=0
    M   -   matrix size, N>=0
    A       -   matrix, actial matrix is stored in A[I1:I1+N-1,J1:J1+N-1]
    I1      -   submatrix offset
    J1      -   submatrix offset
    IsUpper -   whether matrix is upper triangular
    IsUnit  -   whether matrix is unitriangular
    OpType  -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    C   -   matrix, actial matrix is stored in C[I2:I2+M-1,J2:J2+N-1]
    I2  -   submatrix offset
    J2  -   submatrix offset

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrighttrsm(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, complex_2d_array &x, const ae_int_t i2, const ae_int_t j2)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixrighttrsm(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), i1, j1, isupper, isunit, optype, const_cast<alglib_impl::ae_matrix*>(x.c_ptr()), i2, j2, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
This subroutine calculates op(A^-1)*X where:
* X is MxN general matrix
* A is MxM upper/lower triangular/unitriangular matrix
* "op" may be identity transformation, transposition, conjugate transposition

Multiplication result replaces X.
Cache-oblivious algorithm is used.

INPUT PARAMETERS
    N   -   matrix size, N>=0
    M   -   matrix size, N>=0
    A       -   matrix, actial matrix is stored in A[I1:I1+M-1,J1:J1+M-1]
    I1      -   submatrix offset
    J1      -   submatrix offset
    IsUpper -   whether matrix is upper triangular
    IsUnit  -   whether matrix is unitriangular
    OpType  -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    C   -   matrix, actial matrix is stored in C[I2:I2+M-1,J2:J2+N-1]
    I2  -   submatrix offset
    J2  -   submatrix offset

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixlefttrsm(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, complex_2d_array &x, const ae_int_t i2, const ae_int_t j2)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixlefttrsm(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), i1, j1, isupper, isunit, optype, const_cast<alglib_impl::ae_matrix*>(x.c_ptr()), i2, j2, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Same as CMatrixRightTRSM, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrighttrsm(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, real_2d_array &x, const ae_int_t i2, const ae_int_t j2)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixrighttrsm(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), i1, j1, isupper, isunit, optype, const_cast<alglib_impl::ae_matrix*>(x.c_ptr()), i2, j2, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Same as CMatrixLeftTRSM, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixlefttrsm(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, real_2d_array &x, const ae_int_t i2, const ae_int_t j2)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixlefttrsm(m, n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), i1, j1, isupper, isunit, optype, const_cast<alglib_impl::ae_matrix*>(x.c_ptr()), i2, j2, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
This subroutine calculates  C=alpha*A*A^H+beta*C  or  C=alpha*A^H*A+beta*C
where:
* C is NxN Hermitian matrix given by its upper/lower triangle
* A is NxK matrix when A*A^H is calculated, KxN matrix otherwise

Additional info:
* cache-oblivious algorithm is used.
* multiplication result replaces C. If Beta=0, C elements are not used in
  calculations (not multiplied by zero - just not referenced)
* if Alpha=0, A is not used (not multiplied by zero - just not referenced)
* if both Beta and Alpha are zero, C is filled by zeros.

INPUT PARAMETERS
    N       -   matrix size, N>=0
    K       -   matrix size, K>=0
    Alpha   -   coefficient
    A       -   matrix
    IA      -   submatrix offset
    JA      -   submatrix offset
    OpTypeA -   multiplication type:
                * 0 - A*A^H is calculated
                * 2 - A^H*A is calculated
    Beta    -   coefficient
    C       -   matrix
    IC      -   submatrix offset
    JC      -   submatrix offset
    IsUpper -   whether C is upper triangular or lower triangular

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixsyrk(const ae_int_t n, const ae_int_t k, const double alpha, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const double beta, complex_2d_array &c, const ae_int_t ic, const ae_int_t jc, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixsyrk(n, k, alpha, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, optypea, beta, const_cast<alglib_impl::ae_matrix*>(c.c_ptr()), ic, jc, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Same as CMatrixSYRK, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixsyrk(const ae_int_t n, const ae_int_t k, const double alpha, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const double beta, real_2d_array &c, const ae_int_t ic, const ae_int_t jc, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixsyrk(n, k, alpha, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, optypea, beta, const_cast<alglib_impl::ae_matrix*>(c.c_ptr()), ic, jc, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
This subroutine calculates C = alpha*op1(A)*op2(B) +beta*C where:
* C is MxN general matrix
* op1(A) is MxK matrix
* op2(B) is KxN matrix
* "op" may be identity transformation, transposition, conjugate transposition

Additional info:
* cache-oblivious algorithm is used.
* multiplication result replaces C. If Beta=0, C elements are not used in
  calculations (not multiplied by zero - just not referenced)
* if Alpha=0, A is not used (not multiplied by zero - just not referenced)
* if both Beta and Alpha are zero, C is filled by zeros.

INPUT PARAMETERS
    N       -   matrix size, N>0
    M       -   matrix size, N>0
    K       -   matrix size, K>0
    Alpha   -   coefficient
    A       -   matrix
    IA      -   submatrix offset
    JA      -   submatrix offset
    OpTypeA -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    B       -   matrix
    IB      -   submatrix offset
    JB      -   submatrix offset
    OpTypeB -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    Beta    -   coefficient
    C       -   matrix
    IC      -   submatrix offset
    JC      -   submatrix offset

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixgemm(const ae_int_t m, const ae_int_t n, const ae_int_t k, const alglib::complex alpha, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const complex_2d_array &b, const ae_int_t ib, const ae_int_t jb, const ae_int_t optypeb, const alglib::complex beta, complex_2d_array &c, const ae_int_t ic, const ae_int_t jc)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixgemm(m, n, k, *alpha.c_ptr(), const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, optypea, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), ib, jb, optypeb, *beta.c_ptr(), const_cast<alglib_impl::ae_matrix*>(c.c_ptr()), ic, jc, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Same as CMatrixGEMM, but for real numbers.
OpType may be only 0 or 1.

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixgemm(const ae_int_t m, const ae_int_t n, const ae_int_t k, const double alpha, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const real_2d_array &b, const ae_int_t ib, const ae_int_t jb, const ae_int_t optypeb, const double beta, real_2d_array &c, const ae_int_t ic, const ae_int_t jc)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixgemm(m, n, k, alpha, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), ia, ja, optypea, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), ib, jb, optypeb, beta, const_cast<alglib_impl::ae_matrix*>(c.c_ptr()), ic, jc, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
QR decomposition of a rectangular matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1].
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices Q and R in compact form (see below).
    Tau -   array of scalar factors which are used to form
            matrix Q. Array whose index ranges within [0.. Min(M-1,N-1)].

Matrix A is represented as A = QR, where Q is an orthogonal matrix of size
MxM, R - upper triangular (or upper trapezoid) matrix of size M x N.

The elements of matrix R are located on and above the main diagonal of
matrix A. The elements which are located in Tau array and below the main
diagonal of matrix A are used to form matrix Q as follows:

Matrix Q is represented as a product of elementary reflections

Q = H(0)*H(2)*...*H(k-1),

where k = min(m,n), and each H(i) is in the form

H(i) = 1 - tau * v * (v^T)

where tau is a scalar stored in Tau[I]; v - real vector,
so that v(0:i-1) = 0, v(i) = 1, v(i+1:m-1) stored in A(i+1:m-1,i).

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixqr(real_2d_array &a, const ae_int_t m, const ae_int_t n, real_1d_array &tau)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixqr(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
LQ decomposition of a rectangular matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1].
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices L and Q in compact form (see below)
    Tau -   array of scalar factors which are used to form
            matrix Q. Array whose index ranges within [0..Min(M,N)-1].

Matrix A is represented as A = LQ, where Q is an orthogonal matrix of size
MxM, L - lower triangular (or lower trapezoid) matrix of size M x N.

The elements of matrix L are located on and below  the  main  diagonal  of
matrix A. The elements which are located in Tau array and above  the  main
diagonal of matrix A are used to form matrix Q as follows:

Matrix Q is represented as a product of elementary reflections

Q = H(k-1)*H(k-2)*...*H(1)*H(0),

where k = min(m,n), and each H(i) is of the form

H(i) = 1 - tau * v * (v^T)

where tau is a scalar stored in Tau[I]; v - real vector, so that v(0:i-1)=0,
v(i) = 1, v(i+1:n-1) stored in A(i,i+1:n-1).

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlq(real_2d_array &a, const ae_int_t m, const ae_int_t n, real_1d_array &tau)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixlq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
QR decomposition of a rectangular complex matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1]
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices Q and R in compact form
    Tau -   array of scalar factors which are used to form matrix Q. Array
            whose indexes range within [0.. Min(M,N)-1]

Matrix A is represented as A = QR, where Q is an orthogonal matrix of size
MxM, R - upper triangular (or upper trapezoid) matrix of size MxN.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994
*************************************************************************/
void cmatrixqr(complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_1d_array &tau)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixqr(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
LQ decomposition of a rectangular complex matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1]
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices Q and L in compact form
    Tau -   array of scalar factors which are used to form matrix Q. Array
            whose indexes range within [0.. Min(M,N)-1]

Matrix A is represented as A = LQ, where Q is an orthogonal matrix of size
MxM, L - lower triangular (or lower trapezoid) matrix of size MxN.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994
*************************************************************************/
void cmatrixlq(complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_1d_array &tau)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixlq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Partial unpacking of matrix Q from the QR decomposition of a matrix A

Input parameters:
    A       -   matrices Q and R in compact form.
                Output of RMatrixQR subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.
    Tau     -   scalar factors which are used to form Q.
                Output of the RMatrixQR subroutine.
    QColumns -  required number of columns of matrix Q. M>=QColumns>=0.

Output parameters:
    Q       -   first QColumns columns of matrix Q.
                Array whose indexes range within [0..M-1, 0..QColumns-1].
                If QColumns=0, the array remains unchanged.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixqrunpackq(const real_2d_array &a, const ae_int_t m, const ae_int_t n, const real_1d_array &tau, const ae_int_t qcolumns, real_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixqrunpackq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), qcolumns, const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking of matrix R from the QR decomposition of a matrix A

Input parameters:
    A       -   matrices Q and R in compact form.
                Output of RMatrixQR subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    R       -   matrix R, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixqrunpackr(const real_2d_array &a, const ae_int_t m, const ae_int_t n, real_2d_array &r)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixqrunpackr(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_matrix*>(r.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Partial unpacking of matrix Q from the LQ decomposition of a matrix A

Input parameters:
    A       -   matrices L and Q in compact form.
                Output of RMatrixLQ subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.
    Tau     -   scalar factors which are used to form Q.
                Output of the RMatrixLQ subroutine.
    QRows   -   required number of rows in matrix Q. N>=QRows>=0.

Output parameters:
    Q       -   first QRows rows of matrix Q. Array whose indexes range
                within [0..QRows-1, 0..N-1]. If QRows=0, the array remains
                unchanged.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlqunpackq(const real_2d_array &a, const ae_int_t m, const ae_int_t n, const real_1d_array &tau, const ae_int_t qrows, real_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixlqunpackq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), qrows, const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking of matrix L from the LQ decomposition of a matrix A

Input parameters:
    A       -   matrices Q and L in compact form.
                Output of RMatrixLQ subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    L       -   matrix L, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlqunpackl(const real_2d_array &a, const ae_int_t m, const ae_int_t n, real_2d_array &l)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixlqunpackl(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_matrix*>(l.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Partial unpacking of matrix Q from QR decomposition of a complex matrix A.

Input parameters:
    A           -   matrices Q and R in compact form.
                    Output of CMatrixQR subroutine .
    M           -   number of rows in matrix A. M>=0.
    N           -   number of columns in matrix A. N>=0.
    Tau         -   scalar factors which are used to form Q.
                    Output of CMatrixQR subroutine .
    QColumns    -   required number of columns in matrix Q. M>=QColumns>=0.

Output parameters:
    Q           -   first QColumns columns of matrix Q.
                    Array whose index ranges within [0..M-1, 0..QColumns-1].
                    If QColumns=0, array isn't changed.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixqrunpackq(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, const complex_1d_array &tau, const ae_int_t qcolumns, complex_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixqrunpackq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), qcolumns, const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking of matrix R from the QR decomposition of a matrix A

Input parameters:
    A       -   matrices Q and R in compact form.
                Output of CMatrixQR subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    R       -   matrix R, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixqrunpackr(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_2d_array &r)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixqrunpackr(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_matrix*>(r.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Partial unpacking of matrix Q from LQ decomposition of a complex matrix A.

Input parameters:
    A           -   matrices Q and R in compact form.
                    Output of CMatrixLQ subroutine .
    M           -   number of rows in matrix A. M>=0.
    N           -   number of columns in matrix A. N>=0.
    Tau         -   scalar factors which are used to form Q.
                    Output of CMatrixLQ subroutine .
    QRows       -   required number of rows in matrix Q. N>=QColumns>=0.

Output parameters:
    Q           -   first QRows rows of matrix Q.
                    Array whose index ranges within [0..QRows-1, 0..N-1].
                    If QRows=0, array isn't changed.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixlqunpackq(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, const complex_1d_array &tau, const ae_int_t qrows, complex_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixlqunpackq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), qrows, const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking of matrix L from the LQ decomposition of a matrix A

Input parameters:
    A       -   matrices Q and L in compact form.
                Output of CMatrixLQ subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    L       -   matrix L, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixlqunpackl(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_2d_array &l)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixlqunpackl(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_matrix*>(l.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Reduction of a rectangular matrix to  bidiagonal form

The algorithm reduces the rectangular matrix A to  bidiagonal form by
orthogonal transformations P and Q: A = Q*B*P.

Input parameters:
    A       -   source matrix. array[0..M-1, 0..N-1]
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.

Output parameters:
    A       -   matrices Q, B, P in compact form (see below).
    TauQ    -   scalar factors which are used to form matrix Q.
    TauP    -   scalar factors which are used to form matrix P.

The main diagonal and one of the  secondary  diagonals  of  matrix  A  are
replaced with bidiagonal  matrix  B.  Other  elements  contain  elementary
reflections which form MxM matrix Q and NxN matrix P, respectively.

If M>=N, B is the upper  bidiagonal  MxN  matrix  and  is  stored  in  the
corresponding  elements  of  matrix  A.  Matrix  Q  is  represented  as  a
product   of   elementary   reflections   Q = H(0)*H(1)*...*H(n-1),  where
H(i) = 1-tau*v*v'. Here tau is a scalar which is stored  in  TauQ[i],  and
vector v has the following  structure:  v(0:i-1)=0, v(i)=1, v(i+1:m-1)  is
stored   in   elements   A(i+1:m-1,i).   Matrix   P  is  as  follows:  P =
G(0)*G(1)*...*G(n-2), where G(i) = 1 - tau*u*u'. Tau is stored in TauP[i],
u(0:i)=0, u(i+1)=1, u(i+2:n-1) is stored in elements A(i,i+2:n-1).

If M<N, B is the  lower  bidiagonal  MxN  matrix  and  is  stored  in  the
corresponding   elements  of  matrix  A.  Q = H(0)*H(1)*...*H(m-2),  where
H(i) = 1 - tau*v*v', tau is stored in TauQ, v(0:i)=0, v(i+1)=1, v(i+2:m-1)
is    stored    in   elements   A(i+2:m-1,i).    P = G(0)*G(1)*...*G(m-1),
G(i) = 1-tau*u*u', tau is stored in  TauP,  u(0:i-1)=0, u(i)=1, u(i+1:n-1)
is stored in A(i,i+1:n-1).

EXAMPLE:

m=6, n=5 (m > n):               m=5, n=6 (m < n):

(  d   e   u1  u1  u1 )         (  d   u1  u1  u1  u1  u1 )
(  v1  d   e   u2  u2 )         (  e   d   u2  u2  u2  u2 )
(  v1  v2  d   e   u3 )         (  v1  e   d   u3  u3  u3 )
(  v1  v2  v3  d   e  )         (  v1  v2  e   d   u4  u4 )
(  v1  v2  v3  v4  d  )         (  v1  v2  v3  e   d   u5 )
(  v1  v2  v3  v4  v5 )

Here vi and ui are vectors which form H(i) and G(i), and d and e -
are the diagonal and off-diagonal elements of matrix B.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994.
     Sergey Bochkanov, ALGLIB project, translation from FORTRAN to
     pseudocode, 2007-2010.
*************************************************************************/
void rmatrixbd(real_2d_array &a, const ae_int_t m, const ae_int_t n, real_1d_array &tauq, real_1d_array &taup)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixbd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tauq.c_ptr()), const_cast<alglib_impl::ae_vector*>(taup.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking matrix Q which reduces a matrix to bidiagonal form.

Input parameters:
    QP          -   matrices Q and P in compact form.
                    Output of ToBidiagonal subroutine.
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    TAUQ        -   scalar factors which are used to form Q.
                    Output of ToBidiagonal subroutine.
    QColumns    -   required number of columns in matrix Q.
                    M>=QColumns>=0.

Output parameters:
    Q           -   first QColumns columns of matrix Q.
                    Array[0..M-1, 0..QColumns-1]
                    If QColumns=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdunpackq(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &tauq, const ae_int_t qcolumns, real_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixbdunpackq(const_cast<alglib_impl::ae_matrix*>(qp.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tauq.c_ptr()), qcolumns, const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Multiplication by matrix Q which reduces matrix A to  bidiagonal form.

The algorithm allows pre- or post-multiply by Q or Q'.

Input parameters:
    QP          -   matrices Q and P in compact form.
                    Output of ToBidiagonal subroutine.
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    TAUQ        -   scalar factors which are used to form Q.
                    Output of ToBidiagonal subroutine.
    Z           -   multiplied matrix.
                    array[0..ZRows-1,0..ZColumns-1]
    ZRows       -   number of rows in matrix Z. If FromTheRight=False,
                    ZRows=M, otherwise ZRows can be arbitrary.
    ZColumns    -   number of columns in matrix Z. If FromTheRight=True,
                    ZColumns=M, otherwise ZColumns can be arbitrary.
    FromTheRight -  pre- or post-multiply.
    DoTranspose -   multiply by Q or Q'.

Output parameters:
    Z           -   product of Z and Q.
                    Array[0..ZRows-1,0..ZColumns-1]
                    If ZRows=0 or ZColumns=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdmultiplybyq(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &tauq, real_2d_array &z, const ae_int_t zrows, const ae_int_t zcolumns, const bool fromtheright, const bool dotranspose)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixbdmultiplybyq(const_cast<alglib_impl::ae_matrix*>(qp.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(tauq.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), zrows, zcolumns, fromtheright, dotranspose, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking matrix P which reduces matrix A to bidiagonal form.
The subroutine returns transposed matrix P.

Input parameters:
    QP      -   matrices Q and P in compact form.
                Output of ToBidiagonal subroutine.
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.
    TAUP    -   scalar factors which are used to form P.
                Output of ToBidiagonal subroutine.
    PTRows  -   required number of rows of matrix P^T. N >= PTRows >= 0.

Output parameters:
    PT      -   first PTRows columns of matrix P^T
                Array[0..PTRows-1, 0..N-1]
                If PTRows=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdunpackpt(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &taup, const ae_int_t ptrows, real_2d_array &pt)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixbdunpackpt(const_cast<alglib_impl::ae_matrix*>(qp.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(taup.c_ptr()), ptrows, const_cast<alglib_impl::ae_matrix*>(pt.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Multiplication by matrix P which reduces matrix A to  bidiagonal form.

The algorithm allows pre- or post-multiply by P or P'.

Input parameters:
    QP          -   matrices Q and P in compact form.
                    Output of RMatrixBD subroutine.
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    TAUP        -   scalar factors which are used to form P.
                    Output of RMatrixBD subroutine.
    Z           -   multiplied matrix.
                    Array whose indexes range within [0..ZRows-1,0..ZColumns-1].
    ZRows       -   number of rows in matrix Z. If FromTheRight=False,
                    ZRows=N, otherwise ZRows can be arbitrary.
    ZColumns    -   number of columns in matrix Z. If FromTheRight=True,
                    ZColumns=N, otherwise ZColumns can be arbitrary.
    FromTheRight -  pre- or post-multiply.
    DoTranspose -   multiply by P or P'.

Output parameters:
    Z - product of Z and P.
                Array whose indexes range within [0..ZRows-1,0..ZColumns-1].
                If ZRows=0 or ZColumns=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdmultiplybyp(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &taup, real_2d_array &z, const ae_int_t zrows, const ae_int_t zcolumns, const bool fromtheright, const bool dotranspose)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixbdmultiplybyp(const_cast<alglib_impl::ae_matrix*>(qp.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(taup.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), zrows, zcolumns, fromtheright, dotranspose, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking of the main and secondary diagonals of bidiagonal decomposition
of matrix A.

Input parameters:
    B   -   output of RMatrixBD subroutine.
    M   -   number of rows in matrix B.
    N   -   number of columns in matrix B.

Output parameters:
    IsUpper -   True, if the matrix is upper bidiagonal.
                otherwise IsUpper is False.
    D       -   the main diagonal.
                Array whose index ranges within [0..Min(M,N)-1].
    E       -   the secondary diagonal (upper or lower, depending on
                the value of IsUpper).
                Array index ranges within [0..Min(M,N)-1], the last
                element is not used.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdunpackdiagonals(const real_2d_array &b, const ae_int_t m, const ae_int_t n, bool &isupper, real_1d_array &d, real_1d_array &e)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixbdunpackdiagonals(const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), m, n, &isupper, const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_vector*>(e.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Reduction of a square matrix to  upper Hessenberg form: Q'*A*Q = H,
where Q is an orthogonal matrix, H - Hessenberg matrix.

Input parameters:
    A       -   matrix A with elements [0..N-1, 0..N-1]
    N       -   size of matrix A.

Output parameters:
    A       -   matrices Q and P in  compact form (see below).
    Tau     -   array of scalar factors which are used to form matrix Q.
                Array whose index ranges within [0..N-2]

Matrix H is located on the main diagonal, on the lower secondary  diagonal
and above the main diagonal of matrix A. The elements which are used to
form matrix Q are situated in array Tau and below the lower secondary
diagonal of matrix A as follows:

Matrix Q is represented as a product of elementary reflections

Q = H(0)*H(2)*...*H(n-2),

where each H(i) is given by

H(i) = 1 - tau * v * (v^T)

where tau is a scalar stored in Tau[I]; v - is a real vector,
so that v(0:i) = 0, v(i+1) = 1, v(i+2:n-1) stored in A(i+2:n-1,i).

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
void rmatrixhessenberg(real_2d_array &a, const ae_int_t n, real_1d_array &tau)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixhessenberg(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking matrix Q which reduces matrix A to upper Hessenberg form

Input parameters:
    A   -   output of RMatrixHessenberg subroutine.
    N   -   size of matrix A.
    Tau -   scalar factors which are used to form Q.
            Output of RMatrixHessenberg subroutine.

Output parameters:
    Q   -   matrix Q.
            Array whose indexes range within [0..N-1, 0..N-1].

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixhessenbergunpackq(const real_2d_array &a, const ae_int_t n, const real_1d_array &tau, real_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixhessenbergunpackq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking matrix H (the result of matrix A reduction to upper Hessenberg form)

Input parameters:
    A   -   output of RMatrixHessenberg subroutine.
    N   -   size of matrix A.

Output parameters:
    H   -   matrix H. Array whose indexes range within [0..N-1, 0..N-1].

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixhessenbergunpackh(const real_2d_array &a, const ae_int_t n, real_2d_array &h)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixhessenbergunpackh(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, const_cast<alglib_impl::ae_matrix*>(h.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Reduction of a symmetric matrix which is given by its higher or lower
triangular part to a tridiagonal matrix using orthogonal similarity
transformation: Q'*A*Q=T.

Input parameters:
    A       -   matrix to be transformed
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format. If IsUpper = True, then matrix A is given
                by its upper triangle, and the lower triangle is not used
                and not modified by the algorithm, and vice versa
                if IsUpper = False.

Output parameters:
    A       -   matrices T and Q in  compact form (see lower)
    Tau     -   array of factors which are forming matrices H(i)
                array with elements [0..N-2].
    D       -   main diagonal of symmetric matrix T.
                array with elements [0..N-1].
    E       -   secondary diagonal of symmetric matrix T.
                array with elements [0..N-2].


  If IsUpper=True, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(n-2) . . . H(2) H(0).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a real scalar, and v is a real vector with
  v(i+1:n-1) = 0, v(i) = 1, v(0:i-1) is stored on exit in
  A(0:i-1,i+1), and tau in TAU(i).

  If IsUpper=False, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(0) H(2) . . . H(n-2).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a real scalar, and v is a real vector with
  v(0:i) = 0, v(i+1) = 1, v(i+2:n-1) is stored on exit in A(i+2:n-1,i),
  and tau in TAU(i).

  The contents of A on exit are illustrated by the following examples
  with n = 5:

  if UPLO = 'U':                       if UPLO = 'L':

    (  d   e   v1  v2  v3 )              (  d                  )
    (      d   e   v2  v3 )              (  e   d              )
    (          d   e   v3 )              (  v0  e   d          )
    (              d   e  )              (  v0  v1  e   d      )
    (                  d  )              (  v0  v1  v2  e   d  )

  where d and e denote diagonal and off-diagonal elements of T, and vi
  denotes an element of the vector defining H(i).

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
void smatrixtd(real_2d_array &a, const ae_int_t n, const bool isupper, real_1d_array &tau, real_1d_array &d, real_1d_array &e)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::smatrixtd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_vector*>(e.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking matrix Q which reduces symmetric matrix to a tridiagonal
form.

Input parameters:
    A       -   the result of a SMatrixTD subroutine
    N       -   size of matrix A.
    IsUpper -   storage format (a parameter of SMatrixTD subroutine)
    Tau     -   the result of a SMatrixTD subroutine

Output parameters:
    Q       -   transformation matrix.
                array with elements [0..N-1, 0..N-1].

  -- ALGLIB --
     Copyright 2005-2010 by Bochkanov Sergey
*************************************************************************/
void smatrixtdunpackq(const real_2d_array &a, const ae_int_t n, const bool isupper, const real_1d_array &tau, real_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::smatrixtdunpackq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Reduction of a Hermitian matrix which is given  by  its  higher  or  lower
triangular part to a real  tridiagonal  matrix  using  unitary  similarity
transformation: Q'*A*Q = T.

Input parameters:
    A       -   matrix to be transformed
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format. If IsUpper = True, then matrix A is  given
                by its upper triangle, and the lower triangle is not  used
                and not modified by the algorithm, and vice versa
                if IsUpper = False.

Output parameters:
    A       -   matrices T and Q in  compact form (see lower)
    Tau     -   array of factors which are forming matrices H(i)
                array with elements [0..N-2].
    D       -   main diagonal of real symmetric matrix T.
                array with elements [0..N-1].
    E       -   secondary diagonal of real symmetric matrix T.
                array with elements [0..N-2].


  If IsUpper=True, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(n-2) . . . H(2) H(0).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a complex scalar, and v is a complex vector with
  v(i+1:n-1) = 0, v(i) = 1, v(0:i-1) is stored on exit in
  A(0:i-1,i+1), and tau in TAU(i).

  If IsUpper=False, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(0) H(2) . . . H(n-2).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a complex scalar, and v is a complex vector with
  v(0:i) = 0, v(i+1) = 1, v(i+2:n-1) is stored on exit in A(i+2:n-1,i),
  and tau in TAU(i).

  The contents of A on exit are illustrated by the following examples
  with n = 5:

  if UPLO = 'U':                       if UPLO = 'L':

    (  d   e   v1  v2  v3 )              (  d                  )
    (      d   e   v2  v3 )              (  e   d              )
    (          d   e   v3 )              (  v0  e   d          )
    (              d   e  )              (  v0  v1  e   d      )
    (                  d  )              (  v0  v1  v2  e   d  )

where d and e denote diagonal and off-diagonal elements of T, and vi
denotes an element of the vector defining H(i).

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
void hmatrixtd(complex_2d_array &a, const ae_int_t n, const bool isupper, complex_1d_array &tau, real_1d_array &d, real_1d_array &e)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hmatrixtd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_vector*>(e.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Unpacking matrix Q which reduces a Hermitian matrix to a real  tridiagonal
form.

Input parameters:
    A       -   the result of a HMatrixTD subroutine
    N       -   size of matrix A.
    IsUpper -   storage format (a parameter of HMatrixTD subroutine)
    Tau     -   the result of a HMatrixTD subroutine

Output parameters:
    Q       -   transformation matrix.
                array with elements [0..N-1, 0..N-1].

  -- ALGLIB --
     Copyright 2005-2010 by Bochkanov Sergey
*************************************************************************/
void hmatrixtdunpackq(const complex_2d_array &a, const ae_int_t n, const bool isupper, const complex_1d_array &tau, complex_2d_array &q)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hmatrixtdunpackq(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, const_cast<alglib_impl::ae_vector*>(tau.c_ptr()), const_cast<alglib_impl::ae_matrix*>(q.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Finding the eigenvalues and eigenvectors of a symmetric matrix

The algorithm finds eigen pairs of a symmetric matrix by reducing it to
tridiagonal form and using the QL/QR algorithm.

Input parameters:
    A       -   symmetric matrix which is given by its upper or lower
                triangular part.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpper -   storage format.

Output parameters:
    D       -   eigenvalues in ascending order.
                Array whose index ranges within [0..N-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains the eigenvectors.
                Array whose indexes range within [0..N-1, 0..N-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged (rare case).

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
bool smatrixevd(const real_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, real_1d_array &d, real_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixevd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, zneeded, isupper, const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Subroutine for finding the eigenvalues (and eigenvectors) of  a  symmetric
matrix  in  a  given half open interval (A, B] by using  a  bisection  and
inverse iteration

Input parameters:
    A       -   symmetric matrix which is given by its upper or lower
                triangular part. Array [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    B1, B2 -    half open interval (B1, B2] to search eigenvalues in.

Output parameters:
    M       -   number of eigenvalues found in a given half-interval (M>=0).
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..M-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..M-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if successful. M contains the number of eigenvalues in the given
    half-interval (could be equal to 0), W contains the eigenvalues,
    Z contains the eigenvectors (if needed).

    False, if the bisection method subroutine wasn't able to find the
    eigenvalues in the given interval or if the inverse iteration subroutine
    wasn't able to find all the corresponding eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned,
    M is equal to 0.

  -- ALGLIB --
     Copyright 07.01.2006 by Bochkanov Sergey
*************************************************************************/
bool smatrixevdr(const real_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const double b1, const double b2, ae_int_t &m, real_1d_array &w, real_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixevdr(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, zneeded, isupper, b1, b2, &m, const_cast<alglib_impl::ae_vector*>(w.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Subroutine for finding the eigenvalues and  eigenvectors  of  a  symmetric
matrix with given indexes by using bisection and inverse iteration methods.

Input parameters:
    A       -   symmetric matrix which is given by its upper or lower
                triangular part. Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    I1, I2 -    index interval for searching (from I1 to I2).
                0 <= I1 <= I2 <= N-1.

Output parameters:
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..I2-I1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..I2-I1].
                In that case, the eigenvectors are stored in the matrix columns.

Result:
    True, if successful. W contains the eigenvalues, Z contains the
    eigenvectors (if needed).

    False, if the bisection method subroutine wasn't able to find the
    eigenvalues in the given interval or if the inverse iteration subroutine
    wasn't able to find all the corresponding eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned.

  -- ALGLIB --
     Copyright 07.01.2006 by Bochkanov Sergey
*************************************************************************/
bool smatrixevdi(const real_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const ae_int_t i1, const ae_int_t i2, real_1d_array &w, real_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixevdi(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, zneeded, isupper, i1, i2, const_cast<alglib_impl::ae_vector*>(w.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Finding the eigenvalues and eigenvectors of a Hermitian matrix

The algorithm finds eigen pairs of a Hermitian matrix by  reducing  it  to
real tridiagonal form and using the QL/QR algorithm.

Input parameters:
    A       -   Hermitian matrix which is given  by  its  upper  or  lower
                triangular part.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format.
    ZNeeded -   flag controlling whether the eigenvectors  are  needed  or
                not. If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.

Output parameters:
    D       -   eigenvalues in ascending order.
                Array whose index ranges within [0..N-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains the eigenvectors.
                Array whose indexes range within [0..N-1, 0..N-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged (rare case).

Note:
    eigenvectors of Hermitian matrix are defined up to  multiplication  by
    a complex number L, such that |L|=1.

  -- ALGLIB --
     Copyright 2005, 23 March 2007 by Bochkanov Sergey
*************************************************************************/
bool hmatrixevd(const complex_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, real_1d_array &d, complex_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::hmatrixevd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, zneeded, isupper, const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Subroutine for finding the eigenvalues (and eigenvectors) of  a  Hermitian
matrix  in  a  given half-interval (A, B] by using a bisection and inverse
iteration

Input parameters:
    A       -   Hermitian matrix which is given  by  its  upper  or  lower
                triangular  part.  Array  whose   indexes   range   within
                [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors  are  needed  or
                not. If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    B1, B2 -    half-interval (B1, B2] to search eigenvalues in.

Output parameters:
    M       -   number of eigenvalues found in a given half-interval, M>=0
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..M-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..M-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if successful. M contains the number of eigenvalues in the given
    half-interval (could be equal to 0), W contains the eigenvalues,
    Z contains the eigenvectors (if needed).

    False, if the bisection method subroutine  wasn't  able  to  find  the
    eigenvalues  in  the  given  interval  or  if  the  inverse  iteration
    subroutine  wasn't  able  to  find all the corresponding eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned, M  is
    equal to 0.

Note:
    eigen vectors of Hermitian matrix are defined up to multiplication  by
    a complex number L, such as |L|=1.

  -- ALGLIB --
     Copyright 07.01.2006, 24.03.2007 by Bochkanov Sergey.
*************************************************************************/
bool hmatrixevdr(const complex_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const double b1, const double b2, ae_int_t &m, real_1d_array &w, complex_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::hmatrixevdr(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, zneeded, isupper, b1, b2, &m, const_cast<alglib_impl::ae_vector*>(w.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Subroutine for finding the eigenvalues and  eigenvectors  of  a  Hermitian
matrix with given indexes by using bisection and inverse iteration methods

Input parameters:
    A       -   Hermitian matrix which is given  by  its  upper  or  lower
                triangular part.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors  are  needed  or
                not. If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    I1, I2 -    index interval for searching (from I1 to I2).
                0 <= I1 <= I2 <= N-1.

Output parameters:
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..I2-I1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..I2-I1].
                In  that  case,  the eigenvectors are stored in the matrix
                columns.

Result:
    True, if successful. W contains the eigenvalues, Z contains the
    eigenvectors (if needed).

    False, if the bisection method subroutine  wasn't  able  to  find  the
    eigenvalues  in  the  given  interval  or  if  the  inverse  iteration
    subroutine wasn't able to find  all  the  corresponding  eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned.

Note:
    eigen vectors of Hermitian matrix are defined up to multiplication  by
    a complex number L, such as |L|=1.

  -- ALGLIB --
     Copyright 07.01.2006, 24.03.2007 by Bochkanov Sergey.
*************************************************************************/
bool hmatrixevdi(const complex_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const ae_int_t i1, const ae_int_t i2, real_1d_array &w, complex_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::hmatrixevdi(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, zneeded, isupper, i1, i2, const_cast<alglib_impl::ae_vector*>(w.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Finding the eigenvalues and eigenvectors of a tridiagonal symmetric matrix

The algorithm finds the eigen pairs of a tridiagonal symmetric matrix by
using an QL/QR algorithm with implicit shifts.

Input parameters:
    D       -   the main diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-1].
    E       -   the secondary diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not needed;
                 * 1, the eigenvectors of a tridiagonal matrix
                   are multiplied by the square matrix Z. It is used if the
                   tridiagonal matrix is obtained by the similarity
                   transformation of a symmetric matrix;
                 * 2, the eigenvectors of a tridiagonal matrix replace the
                   square matrix Z;
                 * 3, matrix Z contains the first row of the eigenvectors
                   matrix.
    Z       -   if ZNeeded=1, Z contains the square matrix by which the
                eigenvectors are multiplied.
                Array whose indexes range within [0..N-1, 0..N-1].

Output parameters:
    D       -   eigenvalues in ascending order.
                Array whose index ranges within [0..N-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains the product of a given matrix (from the left)
                   and the eigenvectors matrix (from the right);
                 * 2, Z contains the eigenvectors.
                 * 3, Z contains the first row of the eigenvectors matrix.
                If ZNeeded<3, Z is the array whose indexes range within [0..N-1, 0..N-1].
                In that case, the eigenvectors are stored in the matrix columns.
                If ZNeeded=3, Z is the array whose indexes range within [0..0, 0..N-1].

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994
*************************************************************************/
bool smatrixtdevd(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const ae_int_t zneeded, real_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixtdevd(const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_vector*>(e.c_ptr()), n, zneeded, const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Subroutine for finding the tridiagonal matrix eigenvalues/vectors in a
given half-interval (A, B] by using bisection and inverse iteration.

Input parameters:
    D       -   the main diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-1].
    E       -   the secondary diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix, N>=0.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not needed;
                 * 1, the eigenvectors of a tridiagonal matrix are multiplied
                   by the square matrix Z. It is used if the tridiagonal
                   matrix is obtained by the similarity transformation
                   of a symmetric matrix.
                 * 2, the eigenvectors of a tridiagonal matrix replace matrix Z.
    A, B    -   half-interval (A, B] to search eigenvalues in.
    Z       -   if ZNeeded is equal to:
                 * 0, Z isn't used and remains unchanged;
                 * 1, Z contains the square matrix (array whose indexes range
                   within [0..N-1, 0..N-1]) which reduces the given symmetric
                   matrix to tridiagonal form;
                 * 2, Z isn't used (but changed on the exit).

Output parameters:
    D       -   array of the eigenvalues found.
                Array whose index ranges within [0..M-1].
    M       -   number of eigenvalues found in the given half-interval (M>=0).
    Z       -   if ZNeeded is equal to:
                 * 0, doesn't contain any information;
                 * 1, contains the product of a given NxN matrix Z (from the
                   left) and NxM matrix of the eigenvectors found (from the
                   right). Array whose indexes range within [0..N-1, 0..M-1].
                 * 2, contains the matrix of the eigenvectors found.
                   Array whose indexes range within [0..N-1, 0..M-1].

Result:

    True, if successful. In that case, M contains the number of eigenvalues
    in the given half-interval (could be equal to 0), D contains the eigenvalues,
    Z contains the eigenvectors (if needed).
    It should be noted that the subroutine changes the size of arrays D and Z.

    False, if the bisection method subroutine wasn't able to find the
    eigenvalues in the given interval or if the inverse iteration subroutine
    wasn't able to find all the corresponding eigenvectors. In that case,
    the eigenvalues and eigenvectors are not returned, M is equal to 0.

  -- ALGLIB --
     Copyright 31.03.2008 by Bochkanov Sergey
*************************************************************************/
bool smatrixtdevdr(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const ae_int_t zneeded, const double a, const double b, ae_int_t &m, real_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixtdevdr(const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_vector*>(e.c_ptr()), n, zneeded, a, b, &m, const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Subroutine for finding tridiagonal matrix eigenvalues/vectors with given
indexes (in ascending order) by using the bisection and inverse iteraion.

Input parameters:
    D       -   the main diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-1].
    E       -   the secondary diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix. N>=0.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not needed;
                 * 1, the eigenvectors of a tridiagonal matrix are multiplied
                   by the square matrix Z. It is used if the
                   tridiagonal matrix is obtained by the similarity transformation
                   of a symmetric matrix.
                 * 2, the eigenvectors of a tridiagonal matrix replace
                   matrix Z.
    I1, I2  -   index interval for searching (from I1 to I2).
                0 <= I1 <= I2 <= N-1.
    Z       -   if ZNeeded is equal to:
                 * 0, Z isn't used and remains unchanged;
                 * 1, Z contains the square matrix (array whose indexes range within [0..N-1, 0..N-1])
                   which reduces the given symmetric matrix to  tridiagonal form;
                 * 2, Z isn't used (but changed on the exit).

Output parameters:
    D       -   array of the eigenvalues found.
                Array whose index ranges within [0..I2-I1].
    Z       -   if ZNeeded is equal to:
                 * 0, doesn't contain any information;
                 * 1, contains the product of a given NxN matrix Z (from the left) and
                   Nx(I2-I1) matrix of the eigenvectors found (from the right).
                   Array whose indexes range within [0..N-1, 0..I2-I1].
                 * 2, contains the matrix of the eigenvalues found.
                   Array whose indexes range within [0..N-1, 0..I2-I1].


Result:

    True, if successful. In that case, D contains the eigenvalues,
    Z contains the eigenvectors (if needed).
    It should be noted that the subroutine changes the size of arrays D and Z.

    False, if the bisection method subroutine wasn't able to find the eigenvalues
    in the given interval or if the inverse iteration subroutine wasn't able
    to find all the corresponding eigenvectors. In that case, the eigenvalues
    and eigenvectors are not returned.

  -- ALGLIB --
     Copyright 25.12.2005 by Bochkanov Sergey
*************************************************************************/
bool smatrixtdevdi(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const ae_int_t zneeded, const ae_int_t i1, const ae_int_t i2, real_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixtdevdi(const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_vector*>(e.c_ptr()), n, zneeded, i1, i2, const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Finding eigenvalues and eigenvectors of a general matrix

The algorithm finds eigenvalues and eigenvectors of a general matrix by
using the QR algorithm with multiple shifts. The algorithm can find
eigenvalues and both left and right eigenvectors.

The right eigenvector is a vector x such that A*x = w*x, and the left
eigenvector is a vector y such that y'*A = w*y' (here y' implies a complex
conjugate transposition of vector y).

Input parameters:
    A       -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    VNeeded -   flag controlling whether eigenvectors are needed or not.
                If VNeeded is equal to:
                 * 0, eigenvectors are not returned;
                 * 1, right eigenvectors are returned;
                 * 2, left eigenvectors are returned;
                 * 3, both left and right eigenvectors are returned.

Output parameters:
    WR      -   real parts of eigenvalues.
                Array whose index ranges within [0..N-1].
    WR      -   imaginary parts of eigenvalues.
                Array whose index ranges within [0..N-1].
    VL, VR  -   arrays of left and right eigenvectors (if they are needed).
                If WI[i]=0, the respective eigenvalue is a real number,
                and it corresponds to the column number I of matrices VL/VR.
                If WI[i]>0, we have a pair of complex conjugate numbers with
                positive and negative imaginary parts:
                    the first eigenvalue WR[i] + sqrt(-1)*WI[i];
                    the second eigenvalue WR[i+1] + sqrt(-1)*WI[i+1];
                    WI[i]>0
                    WI[i+1] = -WI[i] < 0
                In that case, the eigenvector  corresponding to the first
                eigenvalue is located in i and i+1 columns of matrices
                VL/VR (the column number i contains the real part, and the
                column number i+1 contains the imaginary part), and the vector
                corresponding to the second eigenvalue is a complex conjugate to
                the first vector.
                Arrays whose indexes range within [0..N-1, 0..N-1].

Result:
    True, if the algorithm has converged.
    False, if the algorithm has not converged.

Note 1:
    Some users may ask the following question: what if WI[N-1]>0?
    WI[N] must contain an eigenvalue which is complex conjugate to the
    N-th eigenvalue, but the array has only size N?
    The answer is as follows: such a situation cannot occur because the
    algorithm finds a pairs of eigenvalues, therefore, if WI[i]>0, I is
    strictly less than N-1.

Note 2:
    The algorithm performance depends on the value of the internal parameter
    NS of the InternalSchurDecomposition subroutine which defines the number
    of shifts in the QR algorithm (similarly to the block width in block-matrix
    algorithms of linear algebra). If you require maximum performance
    on your machine, it is recommended to adjust this parameter manually.


See also the InternalTREVC subroutine.

The algorithm is based on the LAPACK 3.0 library.
*************************************************************************/
bool rmatrixevd(const real_2d_array &a, const ae_int_t n, const ae_int_t vneeded, real_1d_array &wr, real_1d_array &wi, real_2d_array &vl, real_2d_array &vr)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::rmatrixevd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, vneeded, const_cast<alglib_impl::ae_vector*>(wr.c_ptr()), const_cast<alglib_impl::ae_vector*>(wi.c_ptr()), const_cast<alglib_impl::ae_matrix*>(vl.c_ptr()), const_cast<alglib_impl::ae_matrix*>(vr.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of a random uniformly distributed (Haar) orthogonal matrix

INPUT PARAMETERS:
    N   -   matrix size, N>=1

OUTPUT PARAMETERS:
    A   -   orthogonal NxN matrix, array[0..N-1,0..N-1]

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndorthogonal(const ae_int_t n, real_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixrndorthogonal(n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of random NxN matrix with given condition number and norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndcond(const ae_int_t n, const double c, real_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixrndcond(n, c, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of a random Haar distributed orthogonal complex matrix

INPUT PARAMETERS:
    N   -   matrix size, N>=1

OUTPUT PARAMETERS:
    A   -   orthogonal NxN matrix, array[0..N-1,0..N-1]

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndorthogonal(const ae_int_t n, complex_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixrndorthogonal(n, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of random NxN complex matrix with given condition number C and
norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndcond(const ae_int_t n, const double c, complex_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixrndcond(n, c, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of random NxN symmetric matrix with given condition number  and
norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void smatrixrndcond(const ae_int_t n, const double c, real_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::smatrixrndcond(n, c, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of random NxN symmetric positive definite matrix with given
condition number and norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random SPD matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void spdmatrixrndcond(const ae_int_t n, const double c, real_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::spdmatrixrndcond(n, c, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of random NxN Hermitian matrix with given condition number  and
norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void hmatrixrndcond(const ae_int_t n, const double c, complex_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hmatrixrndcond(n, c, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Generation of random NxN Hermitian positive definite matrix with given
condition number and norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random HPD matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixrndcond(const ae_int_t n, const double c, complex_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hpdmatrixrndcond(n, c, const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Multiplication of MxN matrix by NxN random Haar distributed orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndorthogonalfromtheright(real_2d_array &a, const ae_int_t m, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixrndorthogonalfromtheright(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Multiplication of MxN matrix by MxM random Haar distributed orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   Q*A, where Q is random MxM orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndorthogonalfromtheleft(real_2d_array &a, const ae_int_t m, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixrndorthogonalfromtheleft(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Multiplication of MxN complex matrix by NxN random Haar distributed
complex orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndorthogonalfromtheright(complex_2d_array &a, const ae_int_t m, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixrndorthogonalfromtheright(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Multiplication of MxN complex matrix by MxM random Haar distributed
complex orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   Q*A, where Q is random MxM orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndorthogonalfromtheleft(complex_2d_array &a, const ae_int_t m, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixrndorthogonalfromtheleft(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Symmetric multiplication of NxN matrix by random Haar distributed
orthogonal  matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..N-1, 0..N-1]
    N   -   matrix size

OUTPUT PARAMETERS:
    A   -   Q'*A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void smatrixrndmultiply(real_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::smatrixrndmultiply(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Hermitian multiplication of NxN matrix by random Haar distributed
complex orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..N-1, 0..N-1]
    N   -   matrix size

OUTPUT PARAMETERS:
    A   -   Q^H*A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void hmatrixrndmultiply(complex_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hmatrixrndmultiply(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
LU decomposition of a general real matrix with row pivoting

A is represented as A = P*L*U, where:
* L is lower unitriangular matrix
* U is upper triangular matrix
* P = P0*P1*...*PK, K=min(M,N)-1,
  Pi - permutation matrix for I and Pivots[I]

This is cache-oblivous implementation of LU decomposition.
It is optimized for square matrices. As for rectangular matrices:
* best case - M>>N
* worst case - N>>M, small M, large N, matrix does not fit in CPU cache

INPUT PARAMETERS:
    A       -   array[0..M-1, 0..N-1].
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.


OUTPUT PARAMETERS:
    A       -   matrices L and U in compact form:
                * L is stored under main diagonal
                * U is stored on and above main diagonal
    Pivots  -   permutation matrix in compact form.
                array[0..Min(M-1,N-1)].

  -- ALGLIB routine --
     10.01.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlu(real_2d_array &a, const ae_int_t m, const ae_int_t n, integer_1d_array &pivots)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixlu(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
LU decomposition of a general complex matrix with row pivoting

A is represented as A = P*L*U, where:
* L is lower unitriangular matrix
* U is upper triangular matrix
* P = P0*P1*...*PK, K=min(M,N)-1,
  Pi - permutation matrix for I and Pivots[I]

This is cache-oblivous implementation of LU decomposition. It is optimized
for square matrices. As for rectangular matrices:
* best case - M>>N
* worst case - N>>M, small M, large N, matrix does not fit in CPU cache

INPUT PARAMETERS:
    A       -   array[0..M-1, 0..N-1].
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.


OUTPUT PARAMETERS:
    A       -   matrices L and U in compact form:
                * L is stored under main diagonal
                * U is stored on and above main diagonal
    Pivots  -   permutation matrix in compact form.
                array[0..Min(M-1,N-1)].

  -- ALGLIB routine --
     10.01.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixlu(complex_2d_array &a, const ae_int_t m, const ae_int_t n, integer_1d_array &pivots)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixlu(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Cache-oblivious Cholesky decomposition

The algorithm computes Cholesky decomposition  of  a  Hermitian  positive-
definite matrix. The result of an algorithm is a representation  of  A  as
A=U'*U  or A=L*L' (here X' detones conj(X^T)).

INPUT PARAMETERS:
    A       -   upper or lower triangle of a factorized matrix.
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   if IsUpper=True, then A contains an upper triangle of
                a symmetric matrix, otherwise A contains a lower one.

OUTPUT PARAMETERS:
    A       -   the result of factorization. If IsUpper=True, then
                the upper triangle contains matrix U, so that A = U'*U,
                and the elements below the main diagonal are not modified.
                Similarly, if IsUpper = False.

RESULT:
    If  the  matrix  is  positive-definite,  the  function  returns  True.
    Otherwise, the function returns False. Contents of A is not determined
    in such case.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
bool hpdmatrixcholesky(complex_2d_array &a, const ae_int_t n, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::hpdmatrixcholesky(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Cache-oblivious Cholesky decomposition

The algorithm computes Cholesky decomposition  of  a  symmetric  positive-
definite matrix. The result of an algorithm is a representation  of  A  as
A=U^T*U  or A=L*L^T

INPUT PARAMETERS:
    A       -   upper or lower triangle of a factorized matrix.
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   if IsUpper=True, then A contains an upper triangle of
                a symmetric matrix, otherwise A contains a lower one.

OUTPUT PARAMETERS:
    A       -   the result of factorization. If IsUpper=True, then
                the upper triangle contains matrix U, so that A = U^T*U,
                and the elements below the main diagonal are not modified.
                Similarly, if IsUpper = False.

RESULT:
    If  the  matrix  is  positive-definite,  the  function  returns  True.
    Otherwise, the function returns False. Contents of A is not determined
    in such case.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
bool spdmatrixcholesky(real_2d_array &a, const ae_int_t n, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::spdmatrixcholesky(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of a matrix condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixrcond1(const real_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixrcond1(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixrcondinf(const real_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixrcondinf(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Condition number estimate of a symmetric positive definite matrix.

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm of condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    A       -   symmetric positive definite matrix which is given by its
                upper or lower triangle depending on the value of
                IsUpper. Array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format.

Result:
    1/LowerBound(cond(A)), if matrix A is positive definite,
   -1, if matrix A is not positive definite, and its condition number
    could not be found by this algorithm.

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double spdmatrixrcond(const real_2d_array &a, const ae_int_t n, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::spdmatrixrcond(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix: estimate of a condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A       -   matrix. Array[0..N-1, 0..N-1].
    N       -   size of A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixtrrcond1(const real_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixtrrcond1(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix: estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixtrrcondinf(const real_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixtrrcondinf(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Condition number estimate of a Hermitian positive definite matrix.

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm of condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    A       -   Hermitian positive definite matrix which is given by its
                upper or lower triangle depending on the value of
                IsUpper. Array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format.

Result:
    1/LowerBound(cond(A)), if matrix A is positive definite,
   -1, if matrix A is not positive definite, and its condition number
    could not be found by this algorithm.

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double hpdmatrixrcond(const complex_2d_array &a, const ae_int_t n, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::hpdmatrixrcond(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of a matrix condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixrcond1(const complex_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::cmatrixrcond1(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixrcondinf(const complex_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::cmatrixrcondinf(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA         -   LU decomposition of a matrix in compact form. Output of
                    the RMatrixLU subroutine.
    N           -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixlurcond1(const real_2d_array &lua, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixlurcond1(const_cast<alglib_impl::ae_matrix*>(lua.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition
(infinity norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA     -   LU decomposition of a matrix in compact form. Output of
                the RMatrixLU subroutine.
    N       -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixlurcondinf(const real_2d_array &lua, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixlurcondinf(const_cast<alglib_impl::ae_matrix*>(lua.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Condition number estimate of a symmetric positive definite matrix given by
Cholesky decomposition.

The algorithm calculates a lower bound of the condition number. In this
case, the algorithm does not return a lower bound of the condition number,
but an inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    CD  - Cholesky decomposition of matrix A,
          output of SMatrixCholesky subroutine.
    N   - size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double spdmatrixcholeskyrcond(const real_2d_array &a, const ae_int_t n, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::spdmatrixcholeskyrcond(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Condition number estimate of a Hermitian positive definite matrix given by
Cholesky decomposition.

The algorithm calculates a lower bound of the condition number. In this
case, the algorithm does not return a lower bound of the condition number,
but an inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    CD  - Cholesky decomposition of matrix A,
          output of SMatrixCholesky subroutine.
    N   - size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double hpdmatrixcholeskyrcond(const complex_2d_array &a, const ae_int_t n, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::hpdmatrixcholeskyrcond(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA         -   LU decomposition of a matrix in compact form. Output of
                    the CMatrixLU subroutine.
    N           -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixlurcond1(const complex_2d_array &lua, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::cmatrixlurcond1(const_cast<alglib_impl::ae_matrix*>(lua.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition
(infinity norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA     -   LU decomposition of a matrix in compact form. Output of
                the CMatrixLU subroutine.
    N       -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixlurcondinf(const complex_2d_array &lua, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::cmatrixlurcondinf(const_cast<alglib_impl::ae_matrix*>(lua.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix: estimate of a condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A       -   matrix. Array[0..N-1, 0..N-1].
    N       -   size of A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixtrrcond1(const complex_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::cmatrixtrrcond1(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix: estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixtrrcondinf(const complex_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::cmatrixtrrcondinf(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Matrix inverse report:
* R1    reciprocal of condition number in 1-norm
* RInf  reciprocal of condition number in inf-norm
*************************************************************************/
_matinvreport_owner::_matinvreport_owner()
{
    p_struct = (alglib_impl::matinvreport*)alglib_impl::ae_malloc(sizeof(alglib_impl::matinvreport), NULL);
    if( p_struct==NULL )
        throw ap_error("ALGLIB: malloc error");
    if( !alglib_impl::_matinvreport_init(p_struct, NULL, ae_false) )
        throw ap_error("ALGLIB: malloc error");
}

_matinvreport_owner::_matinvreport_owner(const _matinvreport_owner &rhs)
{
    p_struct = (alglib_impl::matinvreport*)alglib_impl::ae_malloc(sizeof(alglib_impl::matinvreport), NULL);
    if( p_struct==NULL )
        throw ap_error("ALGLIB: malloc error");
    if( !alglib_impl::_matinvreport_init_copy(p_struct, const_cast<alglib_impl::matinvreport*>(rhs.p_struct), NULL, ae_false) )
        throw ap_error("ALGLIB: malloc error");
}

_matinvreport_owner& _matinvreport_owner::operator=(const _matinvreport_owner &rhs)
{
    if( this==&rhs )
        return *this;
    alglib_impl::_matinvreport_clear(p_struct);
    if( !alglib_impl::_matinvreport_init_copy(p_struct, const_cast<alglib_impl::matinvreport*>(rhs.p_struct), NULL, ae_false) )
        throw ap_error("ALGLIB: malloc error");
    return *this;
}

_matinvreport_owner::~_matinvreport_owner()
{
    alglib_impl::_matinvreport_clear(p_struct);
    ae_free(p_struct);
}

alglib_impl::matinvreport* _matinvreport_owner::c_ptr()
{
    return p_struct;
}

alglib_impl::matinvreport* _matinvreport_owner::c_ptr() const
{
    return const_cast<alglib_impl::matinvreport*>(p_struct);
}
matinvreport::matinvreport() : _matinvreport_owner() ,r1(p_struct->r1),rinf(p_struct->rinf)
{
}

matinvreport::matinvreport(const matinvreport &rhs):_matinvreport_owner(rhs) ,r1(p_struct->r1),rinf(p_struct->rinf)
{
}

matinvreport& matinvreport::operator=(const matinvreport &rhs)
{
    if( this==&rhs )
        return *this;
    _matinvreport_owner::operator=(rhs);
    return *this;
}

matinvreport::~matinvreport()
{
}

/*************************************************************************
Inversion of a matrix given by its LU decomposition.

INPUT PARAMETERS:
    A       -   LU decomposition of the matrix
                (output of RMatrixLU subroutine).
    Pivots  -   table of permutations
                (the output of RMatrixLU subroutine).
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

OUTPUT PARAMETERS:
    Info    -   return code:
                * -3    A is singular, or VERY close to singular.
                        it is filled by zeros in such cases.
                *  1    task is solved (but matrix A may be ill-conditioned,
                        check R1/RInf parameters for condition numbers).
    Rep     -   solver report, see below for more info
    A       -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].

SOLVER REPORT

Subroutine sets following fields of the Rep structure:
* R1        reciprocal of condition number: 1/cond(A), 1-norm.
* RInf      reciprocal of condition number: 1/cond(A), inf-norm.

  -- ALGLIB routine --
     05.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixluinverse(real_2d_array &a, const integer_1d_array &pivots, const ae_int_t n, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixluinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a matrix given by its LU decomposition.

INPUT PARAMETERS:
    A       -   LU decomposition of the matrix
                (output of RMatrixLU subroutine).
    Pivots  -   table of permutations
                (the output of RMatrixLU subroutine).
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

OUTPUT PARAMETERS:
    Info    -   return code:
                * -3    A is singular, or VERY close to singular.
                        it is filled by zeros in such cases.
                *  1    task is solved (but matrix A may be ill-conditioned,
                        check R1/RInf parameters for condition numbers).
    Rep     -   solver report, see below for more info
    A       -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].

SOLVER REPORT

Subroutine sets following fields of the Rep structure:
* R1        reciprocal of condition number: 1/cond(A), 1-norm.
* RInf      reciprocal of condition number: 1/cond(A), inf-norm.

  -- ALGLIB routine --
     05.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixluinverse(real_2d_array &a, const integer_1d_array &pivots, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.cols()!=a.rows()) || (a.cols()!=pivots.length()))
        throw ap_error("Error while calling 'rmatrixluinverse': looks like one of arguments has wrong size");
    n = a.cols();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixluinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a general matrix.

Input parameters:
    A       -   matrix.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

Result:
    True, if the matrix is not singular.
    False, if the matrix is singular.

  -- ALGLIB --
     Copyright 2005-2010 by Bochkanov Sergey
*************************************************************************/
void rmatrixinverse(real_2d_array &a, const ae_int_t n, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a general matrix.

Input parameters:
    A       -   matrix.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

Result:
    True, if the matrix is not singular.
    False, if the matrix is singular.

  -- ALGLIB --
     Copyright 2005-2010 by Bochkanov Sergey
*************************************************************************/
void rmatrixinverse(real_2d_array &a, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'rmatrixinverse': looks like one of arguments has wrong size");
    n = a.cols();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a matrix given by its LU decomposition.

INPUT PARAMETERS:
    A       -   LU decomposition of the matrix
                (output of CMatrixLU subroutine).
    Pivots  -   table of permutations
                (the output of CMatrixLU subroutine).
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

OUTPUT PARAMETERS:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     05.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixluinverse(complex_2d_array &a, const integer_1d_array &pivots, const ae_int_t n, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixluinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a matrix given by its LU decomposition.

INPUT PARAMETERS:
    A       -   LU decomposition of the matrix
                (output of CMatrixLU subroutine).
    Pivots  -   table of permutations
                (the output of CMatrixLU subroutine).
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

OUTPUT PARAMETERS:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     05.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixluinverse(complex_2d_array &a, const integer_1d_array &pivots, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.cols()!=a.rows()) || (a.cols()!=pivots.length()))
        throw ap_error("Error while calling 'cmatrixluinverse': looks like one of arguments has wrong size");
    n = a.cols();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixluinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a general matrix.

Input parameters:
    A       -   matrix
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void cmatrixinverse(complex_2d_array &a, const ae_int_t n, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a general matrix.

Input parameters:
    A       -   matrix
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void cmatrixinverse(complex_2d_array &a, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'cmatrixinverse': looks like one of arguments has wrong size");
    n = a.cols();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a symmetric positive definite matrix which is given
by Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition of the matrix to be inverted:
                A=U�*U or A = L*L'.
                Output of  SPDMatrixCholesky subroutine.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given, lower half is used.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void spdmatrixcholeskyinverse(real_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::spdmatrixcholeskyinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a symmetric positive definite matrix which is given
by Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition of the matrix to be inverted:
                A=U�*U or A = L*L'.
                Output of  SPDMatrixCholesky subroutine.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given, lower half is used.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void spdmatrixcholeskyinverse(real_2d_array &a, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    bool isupper;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'spdmatrixcholeskyinverse': looks like one of arguments has wrong size");
    n = a.cols();
    isupper = false;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::spdmatrixcholeskyinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a symmetric positive definite matrix.

Given an upper or lower triangle of a symmetric positive definite matrix,
the algorithm generates matrix A^-1 and saves the upper or lower triangle
depending on the input.

Input parameters:
    A       -   matrix to be inverted (upper or lower triangle).
                Array with elements [0..N-1,0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given,  both lower and upper  triangles  must  be
                  filled.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void spdmatrixinverse(real_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::spdmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a symmetric positive definite matrix.

Given an upper or lower triangle of a symmetric positive definite matrix,
the algorithm generates matrix A^-1 and saves the upper or lower triangle
depending on the input.

Input parameters:
    A       -   matrix to be inverted (upper or lower triangle).
                Array with elements [0..N-1,0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given,  both lower and upper  triangles  must  be
                  filled.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void spdmatrixinverse(real_2d_array &a, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    bool isupper;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'spdmatrixinverse': looks like one of arguments has wrong size");
    if( !alglib_impl::ae_is_symmetric(const_cast<alglib_impl::ae_matrix*>(a.c_ptr())) )
        throw ap_error("'a' parameter is not symmetric matrix");
    n = a.cols();
    isupper = false;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::spdmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        if( !alglib_impl::ae_force_symmetric(const_cast<alglib_impl::ae_matrix*>(a.c_ptr())) )
            throw ap_error("Internal error while forcing symmetricity of 'a' parameter");
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a Hermitian positive definite matrix which is given
by Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition of the matrix to be inverted:
                A=U�*U or A = L*L'.
                Output of  HPDMatrixCholesky subroutine.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given, lower half is used.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixcholeskyinverse(complex_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hpdmatrixcholeskyinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a Hermitian positive definite matrix which is given
by Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition of the matrix to be inverted:
                A=U�*U or A = L*L'.
                Output of  HPDMatrixCholesky subroutine.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given, lower half is used.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixcholeskyinverse(complex_2d_array &a, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    bool isupper;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'hpdmatrixcholeskyinverse': looks like one of arguments has wrong size");
    n = a.cols();
    isupper = false;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hpdmatrixcholeskyinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a Hermitian positive definite matrix.

Given an upper or lower triangle of a Hermitian positive definite matrix,
the algorithm generates matrix A^-1 and saves the upper or lower triangle
depending on the input.

Input parameters:
    A       -   matrix to be inverted (upper or lower triangle).
                Array with elements [0..N-1,0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given,  both lower and upper  triangles  must  be
                  filled.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixinverse(complex_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hpdmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inversion of a Hermitian positive definite matrix.

Given an upper or lower triangle of a Hermitian positive definite matrix,
the algorithm generates matrix A^-1 and saves the upper or lower triangle
depending on the input.

Input parameters:
    A       -   matrix to be inverted (upper or lower triangle).
                Array with elements [0..N-1,0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given,  both lower and upper  triangles  must  be
                  filled.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixinverse(complex_2d_array &a, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    bool isupper;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'hpdmatrixinverse': looks like one of arguments has wrong size");
    if( !alglib_impl::ae_is_hermitian(const_cast<alglib_impl::ae_matrix*>(a.c_ptr())) )
        throw ap_error("'a' parameter is not Hermitian matrix");
    n = a.cols();
    isupper = false;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::hpdmatrixinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        if( !alglib_impl::ae_force_hermitian(const_cast<alglib_impl::ae_matrix*>(a.c_ptr())) )
            throw ap_error("Internal error while forcing Hermitian properties of 'a' parameter");
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix inverse (real)

The subroutine inverts the following types of matrices:
    * upper triangular
    * upper triangular with unit diagonal
    * lower triangular
    * lower triangular with unit diagonal

In case of an upper (lower) triangular matrix,  the  inverse  matrix  will
also be upper (lower) triangular, and after the end of the algorithm,  the
inverse matrix replaces the source matrix. The elements  below (above) the
main diagonal are not changed by the algorithm.

If  the matrix  has a unit diagonal, the inverse matrix also  has  a  unit
diagonal, and the diagonal elements are not passed to the algorithm.

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   diagonal type (optional):
                * if True, matrix has unit diagonal (a[i,i] are NOT used)
                * if False, matrix diagonal is arbitrary
                * if not given, False is assumed

Output parameters:
    Info    -   same as for RMatrixLUInverse
    Rep     -   same as for RMatrixLUInverse
    A       -   same as for RMatrixLUInverse.

  -- ALGLIB --
     Copyright 05.02.2010 by Bochkanov Sergey
*************************************************************************/
void rmatrixtrinverse(real_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixtrinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix inverse (real)

The subroutine inverts the following types of matrices:
    * upper triangular
    * upper triangular with unit diagonal
    * lower triangular
    * lower triangular with unit diagonal

In case of an upper (lower) triangular matrix,  the  inverse  matrix  will
also be upper (lower) triangular, and after the end of the algorithm,  the
inverse matrix replaces the source matrix. The elements  below (above) the
main diagonal are not changed by the algorithm.

If  the matrix  has a unit diagonal, the inverse matrix also  has  a  unit
diagonal, and the diagonal elements are not passed to the algorithm.

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   diagonal type (optional):
                * if True, matrix has unit diagonal (a[i,i] are NOT used)
                * if False, matrix diagonal is arbitrary
                * if not given, False is assumed

Output parameters:
    Info    -   same as for RMatrixLUInverse
    Rep     -   same as for RMatrixLUInverse
    A       -   same as for RMatrixLUInverse.

  -- ALGLIB --
     Copyright 05.02.2010 by Bochkanov Sergey
*************************************************************************/
void rmatrixtrinverse(real_2d_array &a, const bool isupper, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    bool isunit;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'rmatrixtrinverse': looks like one of arguments has wrong size");
    n = a.cols();
    isunit = false;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixtrinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix inverse (complex)

The subroutine inverts the following types of matrices:
    * upper triangular
    * upper triangular with unit diagonal
    * lower triangular
    * lower triangular with unit diagonal

In case of an upper (lower) triangular matrix,  the  inverse  matrix  will
also be upper (lower) triangular, and after the end of the algorithm,  the
inverse matrix replaces the source matrix. The elements  below (above) the
main diagonal are not changed by the algorithm.

If  the matrix  has a unit diagonal, the inverse matrix also  has  a  unit
diagonal, and the diagonal elements are not passed to the algorithm.

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   diagonal type (optional):
                * if True, matrix has unit diagonal (a[i,i] are NOT used)
                * if False, matrix diagonal is arbitrary
                * if not given, False is assumed

Output parameters:
    Info    -   same as for RMatrixLUInverse
    Rep     -   same as for RMatrixLUInverse
    A       -   same as for RMatrixLUInverse.

  -- ALGLIB --
     Copyright 05.02.2010 by Bochkanov Sergey
*************************************************************************/
void cmatrixtrinverse(complex_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixtrinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Triangular matrix inverse (complex)

The subroutine inverts the following types of matrices:
    * upper triangular
    * upper triangular with unit diagonal
    * lower triangular
    * lower triangular with unit diagonal

In case of an upper (lower) triangular matrix,  the  inverse  matrix  will
also be upper (lower) triangular, and after the end of the algorithm,  the
inverse matrix replaces the source matrix. The elements  below (above) the
main diagonal are not changed by the algorithm.

If  the matrix  has a unit diagonal, the inverse matrix also  has  a  unit
diagonal, and the diagonal elements are not passed to the algorithm.

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   diagonal type (optional):
                * if True, matrix has unit diagonal (a[i,i] are NOT used)
                * if False, matrix diagonal is arbitrary
                * if not given, False is assumed

Output parameters:
    Info    -   same as for RMatrixLUInverse
    Rep     -   same as for RMatrixLUInverse
    A       -   same as for RMatrixLUInverse.

  -- ALGLIB --
     Copyright 05.02.2010 by Bochkanov Sergey
*************************************************************************/
void cmatrixtrinverse(complex_2d_array &a, const bool isupper, ae_int_t &info, matinvreport &rep)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    bool isunit;
    if( (a.cols()!=a.rows()))
        throw ap_error("Error while calling 'cmatrixtrinverse': looks like one of arguments has wrong size");
    n = a.cols();
    isunit = false;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::cmatrixtrinverse(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, isunit, &info, const_cast<alglib_impl::matinvreport*>(rep.c_ptr()), &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Singular value decomposition of a bidiagonal matrix (extended algorithm)

The algorithm performs the singular value decomposition  of  a  bidiagonal
matrix B (upper or lower) representing it as B = Q*S*P^T, where Q and  P -
orthogonal matrices, S - diagonal matrix with non-negative elements on the
main diagonal, in descending order.

The  algorithm  finds  singular  values.  In  addition,  the algorithm can
calculate  matrices  Q  and P (more precisely, not the matrices, but their
product  with  given  matrices U and VT - U*Q and (P^T)*VT)).  Of  course,
matrices U and VT can be of any type, including identity. Furthermore, the
algorithm can calculate Q'*C (this product is calculated more  effectively
than U*Q,  because  this calculation operates with rows instead  of matrix
columns).

The feature of the algorithm is its ability to find  all  singular  values
including those which are arbitrarily close to 0  with  relative  accuracy
close to  machine precision. If the parameter IsFractionalAccuracyRequired
is set to True, all singular values will have high relative accuracy close
to machine precision. If the parameter is set to False, only  the  biggest
singular value will have relative accuracy  close  to  machine  precision.
The absolute error of other singular values is equal to the absolute error
of the biggest singular value.

Input parameters:
    D       -   main diagonal of matrix B.
                Array whose index ranges within [0..N-1].
    E       -   superdiagonal (or subdiagonal) of matrix B.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix B.
    IsUpper -   True, if the matrix is upper bidiagonal.
    IsFractionalAccuracyRequired -
                accuracy to search singular values with.
    U       -   matrix to be multiplied by Q.
                Array whose indexes range within [0..NRU-1, 0..N-1].
                The matrix can be bigger, in that case only the  submatrix
                [0..NRU-1, 0..N-1] will be multiplied by Q.
    NRU     -   number of rows in matrix U.
    C       -   matrix to be multiplied by Q'.
                Array whose indexes range within [0..N-1, 0..NCC-1].
                The matrix can be bigger, in that case only the  submatrix
                [0..N-1, 0..NCC-1] will be multiplied by Q'.
    NCC     -   number of columns in matrix C.
    VT      -   matrix to be multiplied by P^T.
                Array whose indexes range within [0..N-1, 0..NCVT-1].
                The matrix can be bigger, in that case only the  submatrix
                [0..N-1, 0..NCVT-1] will be multiplied by P^T.
    NCVT    -   number of columns in matrix VT.

Output parameters:
    D       -   singular values of matrix B in descending order.
    U       -   if NRU>0, contains matrix U*Q.
    VT      -   if NCVT>0, contains matrix (P^T)*VT.
    C       -   if NCC>0, contains matrix Q'*C.

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged (rare case).

Additional information:
    The type of convergence is controlled by the internal  parameter  TOL.
    If the parameter is greater than 0, the singular values will have
    relative accuracy TOL. If TOL<0, the singular values will have
    absolute accuracy ABS(TOL)*norm(B).
    By default, |TOL| falls within the range of 10*Epsilon and 100*Epsilon,
    where Epsilon is the machine precision. It is not  recommended  to  use
    TOL less than 10*Epsilon since this will  considerably  slow  down  the
    algorithm and may not lead to error decreasing.
History:
    * 31 March, 2007.
        changed MAXITR from 6 to 12.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1999.
*************************************************************************/
bool rmatrixbdsvd(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const bool isupper, const bool isfractionalaccuracyrequired, real_2d_array &u, const ae_int_t nru, real_2d_array &c, const ae_int_t ncc, real_2d_array &vt, const ae_int_t ncvt)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::rmatrixbdsvd(const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_vector*>(e.c_ptr()), n, isupper, isfractionalaccuracyrequired, const_cast<alglib_impl::ae_matrix*>(u.c_ptr()), nru, const_cast<alglib_impl::ae_matrix*>(c.c_ptr()), ncc, const_cast<alglib_impl::ae_matrix*>(vt.c_ptr()), ncvt, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Singular value decomposition of a rectangular matrix.

The algorithm calculates the singular value decomposition of a matrix of
size MxN: A = U * S * V^T

The algorithm finds the singular values and, optionally, matrices U and V^T.
The algorithm can find both first min(M,N) columns of matrix U and rows of
matrix V^T (singular vectors), and matrices U and V^T wholly (of sizes MxM
and NxN respectively).

Take into account that the subroutine does not return matrix V but V^T.

Input parameters:
    A           -   matrix to be decomposed.
                    Array whose indexes range within [0..M-1, 0..N-1].
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    UNeeded     -   0, 1 or 2. See the description of the parameter U.
    VTNeeded    -   0, 1 or 2. See the description of the parameter VT.
    AdditionalMemory -
                    If the parameter:
                     * equals 0, the algorithm doesn�t use additional
                       memory (lower requirements, lower performance).
                     * equals 1, the algorithm uses additional
                       memory of size min(M,N)*min(M,N) of real numbers.
                       It often speeds up the algorithm.
                     * equals 2, the algorithm uses additional
                       memory of size M*min(M,N) of real numbers.
                       It allows to get a maximum performance.
                    The recommended value of the parameter is 2.

Output parameters:
    W           -   contains singular values in descending order.
    U           -   if UNeeded=0, U isn't changed, the left singular vectors
                    are not calculated.
                    if Uneeded=1, U contains left singular vectors (first
                    min(M,N) columns of matrix U). Array whose indexes range
                    within [0..M-1, 0..Min(M,N)-1].
                    if UNeeded=2, U contains matrix U wholly. Array whose
                    indexes range within [0..M-1, 0..M-1].
    VT          -   if VTNeeded=0, VT isn�t changed, the right singular vectors
                    are not calculated.
                    if VTNeeded=1, VT contains right singular vectors (first
                    min(M,N) rows of matrix V^T). Array whose indexes range
                    within [0..min(M,N)-1, 0..N-1].
                    if VTNeeded=2, VT contains matrix V^T wholly. Array whose
                    indexes range within [0..N-1, 0..N-1].

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
bool rmatrixsvd(const real_2d_array &a, const ae_int_t m, const ae_int_t n, const ae_int_t uneeded, const ae_int_t vtneeded, const ae_int_t additionalmemory, real_1d_array &w, real_2d_array &u, real_2d_array &vt)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::rmatrixsvd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), m, n, uneeded, vtneeded, additionalmemory, const_cast<alglib_impl::ae_vector*>(w.c_ptr()), const_cast<alglib_impl::ae_matrix*>(u.c_ptr()), const_cast<alglib_impl::ae_matrix*>(vt.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}



/*************************************************************************
Determinant calculation of the matrix given by its LU decomposition.

Input parameters:
    A       -   LU decomposition of the matrix (output of
                RMatrixLU subroutine).
    Pivots  -   table of permutations which were made during
                the LU decomposition.
                Output of RMatrixLU subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: matrix determinant.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
double rmatrixludet(const real_2d_array &a, const integer_1d_array &pivots, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixludet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Determinant calculation of the matrix given by its LU decomposition.

Input parameters:
    A       -   LU decomposition of the matrix (output of
                RMatrixLU subroutine).
    Pivots  -   table of permutations which were made during
                the LU decomposition.
                Output of RMatrixLU subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: matrix determinant.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
double rmatrixludet(const real_2d_array &a, const integer_1d_array &pivots)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.rows()!=a.cols()) || (a.rows()!=pivots.length()))
        throw ap_error("Error while calling 'rmatrixludet': looks like one of arguments has wrong size");
    n = a.rows();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixludet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Calculation of the determinant of a general matrix

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1]
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: determinant of matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
double rmatrixdet(const real_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixdet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Calculation of the determinant of a general matrix

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1]
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: determinant of matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
double rmatrixdet(const real_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.rows()!=a.cols()))
        throw ap_error("Error while calling 'rmatrixdet': looks like one of arguments has wrong size");
    n = a.rows();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::rmatrixdet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Determinant calculation of the matrix given by its LU decomposition.

Input parameters:
    A       -   LU decomposition of the matrix (output of
                RMatrixLU subroutine).
    Pivots  -   table of permutations which were made during
                the LU decomposition.
                Output of RMatrixLU subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: matrix determinant.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
alglib::complex cmatrixludet(const complex_2d_array &a, const integer_1d_array &pivots, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::ae_complex result = alglib_impl::cmatrixludet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);

        alglib::complex dest(result.x, result.y);
        return dest;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Determinant calculation of the matrix given by its LU decomposition.

Input parameters:
    A       -   LU decomposition of the matrix (output of
                RMatrixLU subroutine).
    Pivots  -   table of permutations which were made during
                the LU decomposition.
                Output of RMatrixLU subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: matrix determinant.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
alglib::complex cmatrixludet(const complex_2d_array &a, const integer_1d_array &pivots)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.rows()!=a.cols()) || (a.rows()!=pivots.length()))
        throw ap_error("Error while calling 'cmatrixludet': looks like one of arguments has wrong size");
    n = a.rows();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::ae_complex result = alglib_impl::cmatrixludet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), const_cast<alglib_impl::ae_vector*>(pivots.c_ptr()), n, &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);

        alglib::complex dest(result.x, result.y);
        return dest;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Calculation of the determinant of a general matrix

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1]
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: determinant of matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
alglib::complex cmatrixdet(const complex_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::ae_complex result = alglib_impl::cmatrixdet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);

        alglib::complex dest(result.x, result.y);
        return dest;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Calculation of the determinant of a general matrix

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1]
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: determinant of matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
alglib::complex cmatrixdet(const complex_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.rows()!=a.cols()))
        throw ap_error("Error while calling 'cmatrixdet': looks like one of arguments has wrong size");
    n = a.rows();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::ae_complex result = alglib_impl::cmatrixdet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);

        alglib::complex dest(result.x, result.y);
        return dest;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Determinant calculation of the matrix given by the Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition,
                output of SMatrixCholesky subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

As the determinant is equal to the product of squares of diagonal elements,
it�s not necessary to specify which triangle - lower or upper - the matrix
is stored in.

Result:
    matrix determinant.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixcholeskydet(const real_2d_array &a, const ae_int_t n)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::spdmatrixcholeskydet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Determinant calculation of the matrix given by the Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition,
                output of SMatrixCholesky subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

As the determinant is equal to the product of squares of diagonal elements,
it�s not necessary to specify which triangle - lower or upper - the matrix
is stored in.

Result:
    matrix determinant.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixcholeskydet(const real_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    if( (a.rows()!=a.cols()))
        throw ap_error("Error while calling 'spdmatrixcholeskydet': looks like one of arguments has wrong size");
    n = a.rows();
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::spdmatrixcholeskydet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Determinant calculation of the symmetric positive definite matrix.

Input parameters:
    A       -   matrix. Array with elements [0..N-1, 0..N-1].
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)
    IsUpper -   (optional) storage type:
                * if True, symmetric matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t used/changed  by
                  function
                * if False, symmetric matrix  A  is  given  by  its lower
                  triangle, and the upper triangle isn�t used/changed  by
                  function
                * if not given, both lower and upper  triangles  must  be
                  filled.

Result:
    determinant of matrix A.
    If matrix A is not positive definite, exception is thrown.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixdet(const real_2d_array &a, const ae_int_t n, const bool isupper)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::spdmatrixdet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Determinant calculation of the symmetric positive definite matrix.

Input parameters:
    A       -   matrix. Array with elements [0..N-1, 0..N-1].
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)
    IsUpper -   (optional) storage type:
                * if True, symmetric matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t used/changed  by
                  function
                * if False, symmetric matrix  A  is  given  by  its lower
                  triangle, and the upper triangle isn�t used/changed  by
                  function
                * if not given, both lower and upper  triangles  must  be
                  filled.

Result:
    determinant of matrix A.
    If matrix A is not positive definite, exception is thrown.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixdet(const real_2d_array &a)
{
    alglib_impl::ae_state _alglib_env_state;    
    ae_int_t n;
    bool isupper;
    if( (a.rows()!=a.cols()))
        throw ap_error("Error while calling 'spdmatrixdet': looks like one of arguments has wrong size");
    if( !alglib_impl::ae_is_symmetric(const_cast<alglib_impl::ae_matrix*>(a.c_ptr())) )
        throw ap_error("'a' parameter is not symmetric matrix");
    n = a.rows();
    isupper = false;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        double result = alglib_impl::spdmatrixdet(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isupper, &_alglib_env_state);

        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<double*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Algorithm for solving the following generalized symmetric positive-definite
eigenproblem:
    A*x = lambda*B*x (1) or
    A*B*x = lambda*x (2) or
    B*A*x = lambda*x (3).
where A is a symmetric matrix, B - symmetric positive-definite matrix.
The problem is solved by reducing it to an ordinary  symmetric  eigenvalue
problem.

Input parameters:
    A           -   symmetric matrix which is given by its upper or lower
                    triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    N           -   size of matrices A and B.
    IsUpperA    -   storage format of matrix A.
    B           -   symmetric positive-definite matrix which is given by
                    its upper or lower triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    IsUpperB    -   storage format of matrix B.
    ZNeeded     -   if ZNeeded is equal to:
                     * 0, the eigenvectors are not returned;
                     * 1, the eigenvectors are returned.
    ProblemType -   if ProblemType is equal to:
                     * 1, the following problem is solved: A*x = lambda*B*x;
                     * 2, the following problem is solved: A*B*x = lambda*x;
                     * 3, the following problem is solved: B*A*x = lambda*x.

Output parameters:
    D           -   eigenvalues in ascending order.
                    Array whose index ranges within [0..N-1].
    Z           -   if ZNeeded is equal to:
                     * 0, Z hasn�t changed;
                     * 1, Z contains eigenvectors.
                    Array whose indexes range within [0..N-1, 0..N-1].
                    The eigenvectors are stored in matrix columns. It should
                    be noted that the eigenvectors in such problems do not
                    form an orthogonal system.

Result:
    True, if the problem was solved successfully.
    False, if the error occurred during the Cholesky decomposition of matrix
    B (the matrix isn�t positive-definite) or during the work of the iterative
    algorithm for solving the symmetric eigenproblem.

See also the GeneralizedSymmetricDefiniteEVDReduce subroutine.

  -- ALGLIB --
     Copyright 1.28.2006 by Bochkanov Sergey
*************************************************************************/
bool smatrixgevd(const real_2d_array &a, const ae_int_t n, const bool isuppera, const real_2d_array &b, const bool isupperb, const ae_int_t zneeded, const ae_int_t problemtype, real_1d_array &d, real_2d_array &z)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixgevd(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isuppera, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), isupperb, zneeded, problemtype, const_cast<alglib_impl::ae_vector*>(d.c_ptr()), const_cast<alglib_impl::ae_matrix*>(z.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Algorithm for reduction of the following generalized symmetric positive-
definite eigenvalue problem:
    A*x = lambda*B*x (1) or
    A*B*x = lambda*x (2) or
    B*A*x = lambda*x (3)
to the symmetric eigenvalues problem C*y = lambda*y (eigenvalues of this and
the given problems are the same, and the eigenvectors of the given problem
could be obtained by multiplying the obtained eigenvectors by the
transformation matrix x = R*y).

Here A is a symmetric matrix, B - symmetric positive-definite matrix.

Input parameters:
    A           -   symmetric matrix which is given by its upper or lower
                    triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    N           -   size of matrices A and B.
    IsUpperA    -   storage format of matrix A.
    B           -   symmetric positive-definite matrix which is given by
                    its upper or lower triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    IsUpperB    -   storage format of matrix B.
    ProblemType -   if ProblemType is equal to:
                     * 1, the following problem is solved: A*x = lambda*B*x;
                     * 2, the following problem is solved: A*B*x = lambda*x;
                     * 3, the following problem is solved: B*A*x = lambda*x.

Output parameters:
    A           -   symmetric matrix which is given by its upper or lower
                    triangle depending on IsUpperA. Contains matrix C.
                    Array whose indexes range within [0..N-1, 0..N-1].
    R           -   upper triangular or low triangular transformation matrix
                    which is used to obtain the eigenvectors of a given problem
                    as the product of eigenvectors of C (from the right) and
                    matrix R (from the left). If the matrix is upper
                    triangular, the elements below the main diagonal
                    are equal to 0 (and vice versa). Thus, we can perform
                    the multiplication without taking into account the
                    internal structure (which is an easier though less
                    effective way).
                    Array whose indexes range within [0..N-1, 0..N-1].
    IsUpperR    -   type of matrix R (upper or lower triangular).

Result:
    True, if the problem was reduced successfully.
    False, if the error occurred during the Cholesky decomposition of
        matrix B (the matrix is not positive-definite).

  -- ALGLIB --
     Copyright 1.28.2006 by Bochkanov Sergey
*************************************************************************/
bool smatrixgevdreduce(real_2d_array &a, const ae_int_t n, const bool isuppera, const real_2d_array &b, const bool isupperb, const ae_int_t problemtype, real_2d_array &r, bool &isupperr)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::smatrixgevdreduce(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, isuppera, const_cast<alglib_impl::ae_matrix*>(b.c_ptr()), isupperb, problemtype, const_cast<alglib_impl::ae_matrix*>(r.c_ptr()), &isupperr, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm updates matrix A^-1 when adding a number to an element
of matrix A.

Input parameters:
    InvA    -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    UpdRow  -   row where the element to be updated is stored.
    UpdColumn - column where the element to be updated is stored.
    UpdVal  -   a number to be added to the element.


Output parameters:
    InvA    -   inverse of modified matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdatesimple(real_2d_array &inva, const ae_int_t n, const ae_int_t updrow, const ae_int_t updcolumn, const double updval)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixinvupdatesimple(const_cast<alglib_impl::ae_matrix*>(inva.c_ptr()), n, updrow, updcolumn, updval, &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm updates matrix A^-1 when adding a vector to a row
of matrix A.

Input parameters:
    InvA    -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    UpdRow  -   the row of A whose vector V was added.
                0 <= Row <= N-1
    V       -   the vector to be added to a row.
                Array whose index ranges within [0..N-1].

Output parameters:
    InvA    -   inverse of modified matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdaterow(real_2d_array &inva, const ae_int_t n, const ae_int_t updrow, const real_1d_array &v)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixinvupdaterow(const_cast<alglib_impl::ae_matrix*>(inva.c_ptr()), n, updrow, const_cast<alglib_impl::ae_vector*>(v.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm updates matrix A^-1 when adding a vector to a column
of matrix A.

Input parameters:
    InvA        -   inverse of matrix A.
                    Array whose indexes range within [0..N-1, 0..N-1].
    N           -   size of matrix A.
    UpdColumn   -   the column of A whose vector U was added.
                    0 <= UpdColumn <= N-1
    U           -   the vector to be added to a column.
                    Array whose index ranges within [0..N-1].

Output parameters:
    InvA        -   inverse of modified matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdatecolumn(real_2d_array &inva, const ae_int_t n, const ae_int_t updcolumn, const real_1d_array &u)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixinvupdatecolumn(const_cast<alglib_impl::ae_matrix*>(inva.c_ptr()), n, updcolumn, const_cast<alglib_impl::ae_vector*>(u.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm computes the inverse of matrix A+u*v� by using the given matrix
A^-1 and the vectors u and v.

Input parameters:
    InvA    -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    U       -   the vector modifying the matrix.
                Array whose index ranges within [0..N-1].
    V       -   the vector modifying the matrix.
                Array whose index ranges within [0..N-1].

Output parameters:
    InvA - inverse of matrix A + u*v'.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdateuv(real_2d_array &inva, const ae_int_t n, const real_1d_array &u, const real_1d_array &v)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        alglib_impl::rmatrixinvupdateuv(const_cast<alglib_impl::ae_matrix*>(inva.c_ptr()), n, const_cast<alglib_impl::ae_vector*>(u.c_ptr()), const_cast<alglib_impl::ae_vector*>(v.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return;
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}

/*************************************************************************
Subroutine performing the Schur decomposition of a general matrix by using
the QR algorithm with multiple shifts.

The source matrix A is represented as S'*A*S = T, where S is an orthogonal
matrix (Schur vectors), T - upper quasi-triangular matrix (with blocks of
sizes 1x1 and 2x2 on the main diagonal).

Input parameters:
    A   -   matrix to be decomposed.
            Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of A, N>=0.


Output parameters:
    A   -   contains matrix T.
            Array whose indexes range within [0..N-1, 0..N-1].
    S   -   contains Schur vectors.
            Array whose indexes range within [0..N-1, 0..N-1].

Note 1:
    The block structure of matrix T can be easily recognized: since all
    the elements below the blocks are zeros, the elements a[i+1,i] which
    are equal to 0 show the block border.

Note 2:
    The algorithm performance depends on the value of the internal parameter
    NS of the InternalSchurDecomposition subroutine which defines the number
    of shifts in the QR algorithm (similarly to the block width in block-matrix
    algorithms in linear algebra). If you require maximum performance on
    your machine, it is recommended to adjust this parameter manually.

Result:
    True,
        if the algorithm has converged and parameters A and S contain the result.
    False,
        if the algorithm has not converged.

Algorithm implemented on the basis of the DHSEQR subroutine (LAPACK 3.0 library).
*************************************************************************/
bool rmatrixschur(real_2d_array &a, const ae_int_t n, real_2d_array &s)
{
    alglib_impl::ae_state _alglib_env_state;
    alglib_impl::ae_state_init(&_alglib_env_state);
    try
    {
        ae_bool result = alglib_impl::rmatrixschur(const_cast<alglib_impl::ae_matrix*>(a.c_ptr()), n, const_cast<alglib_impl::ae_matrix*>(s.c_ptr()), &_alglib_env_state);
        alglib_impl::ae_state_clear(&_alglib_env_state);
        return *(reinterpret_cast<bool*>(&result));
    }
    catch(alglib_impl::ae_error_type)
    {
        throw ap_error(_alglib_env_state.error_msg);
    }
    catch(...)
    {
        throw;
    }
}
}

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS IMPLEMENTATION OF COMPUTATIONAL CORE
//
/////////////////////////////////////////////////////////////////////////
namespace alglib_impl
{
static void ablas_ablasinternalsplitlength(ae_int_t n,
     ae_int_t nb,
     ae_int_t* n1,
     ae_int_t* n2,
     ae_state *_state);
static void ablas_cmatrixrighttrsm2(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Complex */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state);
static void ablas_cmatrixlefttrsm2(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Complex */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state);
static void ablas_rmatrixrighttrsm2(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Real    */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state);
static void ablas_rmatrixlefttrsm2(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Real    */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state);
static void ablas_cmatrixsyrk2(ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     double beta,
     /* Complex */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_bool isupper,
     ae_state *_state);
static void ablas_rmatrixsyrk2(ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     double beta,
     /* Real    */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_bool isupper,
     ae_state *_state);
static void ablas_cmatrixgemmk(ae_int_t m,
     ae_int_t n,
     ae_int_t k,
     ae_complex alpha,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     /* Complex */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_int_t optypeb,
     ae_complex beta,
     /* Complex */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_state *_state);
static void ablas_rmatrixgemmk(ae_int_t m,
     ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     /* Real    */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_int_t optypeb,
     double beta,
     /* Real    */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_state *_state);


static void ortfac_rmatrixqrbasecase(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* work,
     /* Real    */ ae_vector* t,
     /* Real    */ ae_vector* tau,
     ae_state *_state);
static void ortfac_rmatrixlqbasecase(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* work,
     /* Real    */ ae_vector* t,
     /* Real    */ ae_vector* tau,
     ae_state *_state);
static void ortfac_cmatrixqrbasecase(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* work,
     /* Complex */ ae_vector* t,
     /* Complex */ ae_vector* tau,
     ae_state *_state);
static void ortfac_cmatrixlqbasecase(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* work,
     /* Complex */ ae_vector* t,
     /* Complex */ ae_vector* tau,
     ae_state *_state);
static void ortfac_rmatrixblockreflector(/* Real    */ ae_matrix* a,
     /* Real    */ ae_vector* tau,
     ae_bool columnwisea,
     ae_int_t lengtha,
     ae_int_t blocksize,
     /* Real    */ ae_matrix* t,
     /* Real    */ ae_vector* work,
     ae_state *_state);
static void ortfac_cmatrixblockreflector(/* Complex */ ae_matrix* a,
     /* Complex */ ae_vector* tau,
     ae_bool columnwisea,
     ae_int_t lengtha,
     ae_int_t blocksize,
     /* Complex */ ae_matrix* t,
     /* Complex */ ae_vector* work,
     ae_state *_state);


static ae_bool evd_tridiagonalevd(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
static void evd_tdevde2(double a,
     double b,
     double c,
     double* rt1,
     double* rt2,
     ae_state *_state);
static void evd_tdevdev2(double a,
     double b,
     double c,
     double* rt1,
     double* rt2,
     double* cs1,
     double* sn1,
     ae_state *_state);
static double evd_tdevdpythag(double a, double b, ae_state *_state);
static double evd_tdevdextsign(double a, double b, ae_state *_state);
static ae_bool evd_internalbisectioneigenvalues(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t irange,
     ae_int_t iorder,
     double vl,
     double vu,
     ae_int_t il,
     ae_int_t iu,
     double abstol,
     /* Real    */ ae_vector* w,
     ae_int_t* m,
     ae_int_t* nsplit,
     /* Integer */ ae_vector* iblock,
     /* Integer */ ae_vector* isplit,
     ae_int_t* errorcode,
     ae_state *_state);
static void evd_internaldstein(ae_int_t n,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t m,
     /* Real    */ ae_vector* w,
     /* Integer */ ae_vector* iblock,
     /* Integer */ ae_vector* isplit,
     /* Real    */ ae_matrix* z,
     /* Integer */ ae_vector* ifail,
     ae_int_t* info,
     ae_state *_state);
static void evd_tdininternaldlagtf(ae_int_t n,
     /* Real    */ ae_vector* a,
     double lambdav,
     /* Real    */ ae_vector* b,
     /* Real    */ ae_vector* c,
     double tol,
     /* Real    */ ae_vector* d,
     /* Integer */ ae_vector* iin,
     ae_int_t* info,
     ae_state *_state);
static void evd_tdininternaldlagts(ae_int_t n,
     /* Real    */ ae_vector* a,
     /* Real    */ ae_vector* b,
     /* Real    */ ae_vector* c,
     /* Real    */ ae_vector* d,
     /* Integer */ ae_vector* iin,
     /* Real    */ ae_vector* y,
     double* tol,
     ae_int_t* info,
     ae_state *_state);
static void evd_internaldlaebz(ae_int_t ijob,
     ae_int_t nitmax,
     ae_int_t n,
     ae_int_t mmax,
     ae_int_t minp,
     double abstol,
     double reltol,
     double pivmin,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     /* Real    */ ae_vector* e2,
     /* Integer */ ae_vector* nval,
     /* Real    */ ae_matrix* ab,
     /* Real    */ ae_vector* c,
     ae_int_t* mout,
     /* Integer */ ae_matrix* nab,
     /* Real    */ ae_vector* work,
     /* Integer */ ae_vector* iwork,
     ae_int_t* info,
     ae_state *_state);
static void evd_internaltrevc(/* Real    */ ae_matrix* t,
     ae_int_t n,
     ae_int_t side,
     ae_int_t howmny,
     /* Boolean */ ae_vector* vselect,
     /* Real    */ ae_matrix* vl,
     /* Real    */ ae_matrix* vr,
     ae_int_t* m,
     ae_int_t* info,
     ae_state *_state);
static void evd_internalhsevdlaln2(ae_bool ltrans,
     ae_int_t na,
     ae_int_t nw,
     double smin,
     double ca,
     /* Real    */ ae_matrix* a,
     double d1,
     double d2,
     /* Real    */ ae_matrix* b,
     double wr,
     double wi,
     /* Boolean */ ae_vector* rswap4,
     /* Boolean */ ae_vector* zswap4,
     /* Integer */ ae_matrix* ipivot44,
     /* Real    */ ae_vector* civ4,
     /* Real    */ ae_vector* crv4,
     /* Real    */ ae_matrix* x,
     double* scl,
     double* xnorm,
     ae_int_t* info,
     ae_state *_state);
static void evd_internalhsevdladiv(double a,
     double b,
     double c,
     double d,
     double* p,
     double* q,
     ae_state *_state);
static ae_bool evd_nonsymmetricevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t vneeded,
     /* Real    */ ae_vector* wr,
     /* Real    */ ae_vector* wi,
     /* Real    */ ae_matrix* vl,
     /* Real    */ ae_matrix* vr,
     ae_state *_state);
static void evd_toupperhessenberg(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state);
static void evd_unpackqfromupperhessenberg(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_matrix* q,
     ae_state *_state);




static void trfac_cmatrixluprec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state);
static void trfac_rmatrixluprec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);
static void trfac_cmatrixplurec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state);
static void trfac_rmatrixplurec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);
static void trfac_cmatrixlup2(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state);
static void trfac_rmatrixlup2(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);
static void trfac_cmatrixplu2(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state);
static void trfac_rmatrixplu2(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);
static ae_bool trfac_hpdmatrixcholeskyrec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tmp,
     ae_state *_state);
static ae_bool trfac_hpdmatrixcholesky2(/* Complex */ ae_matrix* aaa,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tmp,
     ae_state *_state);
static ae_bool trfac_spdmatrixcholesky2(/* Real    */ ae_matrix* aaa,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);


static void rcond_rmatrixrcondtrinternal(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_bool onenorm,
     double anorm,
     double* rc,
     ae_state *_state);
static void rcond_cmatrixrcondtrinternal(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_bool onenorm,
     double anorm,
     double* rc,
     ae_state *_state);
static void rcond_spdmatrixrcondcholeskyinternal(/* Real    */ ae_matrix* cha,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isnormprovided,
     double anorm,
     double* rc,
     ae_state *_state);
static void rcond_hpdmatrixrcondcholeskyinternal(/* Complex */ ae_matrix* cha,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isnormprovided,
     double anorm,
     double* rc,
     ae_state *_state);
static void rcond_rmatrixrcondluinternal(/* Real    */ ae_matrix* lua,
     ae_int_t n,
     ae_bool onenorm,
     ae_bool isanormprovided,
     double anorm,
     double* rc,
     ae_state *_state);
static void rcond_cmatrixrcondluinternal(/* Complex */ ae_matrix* lua,
     ae_int_t n,
     ae_bool onenorm,
     ae_bool isanormprovided,
     double anorm,
     double* rc,
     ae_state *_state);
static void rcond_rmatrixestimatenorm(ae_int_t n,
     /* Real    */ ae_vector* v,
     /* Real    */ ae_vector* x,
     /* Integer */ ae_vector* isgn,
     double* est,
     ae_int_t* kase,
     ae_state *_state);
static void rcond_cmatrixestimatenorm(ae_int_t n,
     /* Complex */ ae_vector* v,
     /* Complex */ ae_vector* x,
     double* est,
     ae_int_t* kase,
     /* Integer */ ae_vector* isave,
     /* Real    */ ae_vector* rsave,
     ae_state *_state);
static double rcond_internalcomplexrcondscsum1(/* Complex */ ae_vector* x,
     ae_int_t n,
     ae_state *_state);
static ae_int_t rcond_internalcomplexrcondicmax1(/* Complex */ ae_vector* x,
     ae_int_t n,
     ae_state *_state);
static void rcond_internalcomplexrcondsaveall(/* Integer */ ae_vector* isave,
     /* Real    */ ae_vector* rsave,
     ae_int_t* i,
     ae_int_t* iter,
     ae_int_t* j,
     ae_int_t* jlast,
     ae_int_t* jump,
     double* absxi,
     double* altsgn,
     double* estold,
     double* temp,
     ae_state *_state);
static void rcond_internalcomplexrcondloadall(/* Integer */ ae_vector* isave,
     /* Real    */ ae_vector* rsave,
     ae_int_t* i,
     ae_int_t* iter,
     ae_int_t* j,
     ae_int_t* jlast,
     ae_int_t* jump,
     double* absxi,
     double* altsgn,
     double* estold,
     double* temp,
     ae_state *_state);


static void matinv_rmatrixtrinverserec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     /* Real    */ ae_vector* tmp,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
static void matinv_cmatrixtrinverserec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     /* Complex */ ae_vector* tmp,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
static void matinv_rmatrixluinverserec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     /* Real    */ ae_vector* work,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
static void matinv_cmatrixluinverserec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     /* Complex */ ae_vector* work,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
static void matinv_spdmatrixcholeskyinverserec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);
static void matinv_hpdmatrixcholeskyinverserec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tmp,
     ae_state *_state);


static ae_bool bdsvd_bidiagonalsvddecompositioninternal(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isfractionalaccuracyrequired,
     /* Real    */ ae_matrix* u,
     ae_int_t ustart,
     ae_int_t nru,
     /* Real    */ ae_matrix* c,
     ae_int_t cstart,
     ae_int_t ncc,
     /* Real    */ ae_matrix* vt,
     ae_int_t vstart,
     ae_int_t ncvt,
     ae_state *_state);
static double bdsvd_extsignbdsqr(double a, double b, ae_state *_state);
static void bdsvd_svd2x2(double f,
     double g,
     double h,
     double* ssmin,
     double* ssmax,
     ae_state *_state);
static void bdsvd_svdv2x2(double f,
     double g,
     double h,
     double* ssmin,
     double* ssmax,
     double* snr,
     double* csr,
     double* snl,
     double* csl,
     ae_state *_state);

















/*************************************************************************
Splits matrix length in two parts, left part should match ABLAS block size

INPUT PARAMETERS
    A   -   real matrix, is passed to ensure that we didn't split
            complex matrix using real splitting subroutine.
            matrix itself is not changed.
    N   -   length, N>0

OUTPUT PARAMETERS
    N1  -   length
    N2  -   length

N1+N2=N, N1>=N2, N2 may be zero

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void ablassplitlength(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* n1,
     ae_int_t* n2,
     ae_state *_state)
{

    *n1 = 0;
    *n2 = 0;

    if( n>ablasblocksize(a, _state) )
    {
        ablas_ablasinternalsplitlength(n, ablasblocksize(a, _state), n1, n2, _state);
    }
    else
    {
        ablas_ablasinternalsplitlength(n, ablasmicroblocksize(_state), n1, n2, _state);
    }
}


/*************************************************************************
Complex ABLASSplitLength

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void ablascomplexsplitlength(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* n1,
     ae_int_t* n2,
     ae_state *_state)
{

    *n1 = 0;
    *n2 = 0;

    if( n>ablascomplexblocksize(a, _state) )
    {
        ablas_ablasinternalsplitlength(n, ablascomplexblocksize(a, _state), n1, n2, _state);
    }
    else
    {
        ablas_ablasinternalsplitlength(n, ablasmicroblocksize(_state), n1, n2, _state);
    }
}


/*************************************************************************
Returns block size - subdivision size where  cache-oblivious  soubroutines
switch to the optimized kernel.

INPUT PARAMETERS
    A   -   real matrix, is passed to ensure that we didn't split
            complex matrix using real splitting subroutine.
            matrix itself is not changed.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
ae_int_t ablasblocksize(/* Real    */ ae_matrix* a, ae_state *_state)
{
    ae_int_t result;


    result = 32;
    return result;
}


/*************************************************************************
Block size for complex subroutines.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
ae_int_t ablascomplexblocksize(/* Complex */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t result;


    result = 24;
    return result;
}


/*************************************************************************
Microblock size

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
ae_int_t ablasmicroblocksize(ae_state *_state)
{
    ae_int_t result;


    result = 8;
    return result;
}


/*************************************************************************
Cache-oblivous complex "copy-and-transpose"

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    A   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void cmatrixtranspose(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Complex */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t s1;
    ae_int_t s2;


    if( m<=2*ablascomplexblocksize(a, _state)&&n<=2*ablascomplexblocksize(a, _state) )
    {
        
        /*
         * base case
         */
        for(i=0; i<=m-1; i++)
        {
            ae_v_cmove(&b->ptr.pp_complex[ib][jb+i], b->stride, &a->ptr.pp_complex[ia+i][ja], 1, "N", ae_v_len(ib,ib+n-1));
        }
    }
    else
    {
        
        /*
         * Cache-oblivious recursion
         */
        if( m>n )
        {
            ablascomplexsplitlength(a, m, &s1, &s2, _state);
            cmatrixtranspose(s1, n, a, ia, ja, b, ib, jb, _state);
            cmatrixtranspose(s2, n, a, ia+s1, ja, b, ib, jb+s1, _state);
        }
        else
        {
            ablascomplexsplitlength(a, n, &s1, &s2, _state);
            cmatrixtranspose(m, s1, a, ia, ja, b, ib, jb, _state);
            cmatrixtranspose(m, s2, a, ia, ja+s1, b, ib+s1, jb, _state);
        }
    }
}


/*************************************************************************
Cache-oblivous real "copy-and-transpose"

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    A   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void rmatrixtranspose(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Real    */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t s1;
    ae_int_t s2;


    if( m<=2*ablasblocksize(a, _state)&&n<=2*ablasblocksize(a, _state) )
    {
        
        /*
         * base case
         */
        for(i=0; i<=m-1; i++)
        {
            ae_v_move(&b->ptr.pp_double[ib][jb+i], b->stride, &a->ptr.pp_double[ia+i][ja], 1, ae_v_len(ib,ib+n-1));
        }
    }
    else
    {
        
        /*
         * Cache-oblivious recursion
         */
        if( m>n )
        {
            ablassplitlength(a, m, &s1, &s2, _state);
            rmatrixtranspose(s1, n, a, ia, ja, b, ib, jb, _state);
            rmatrixtranspose(s2, n, a, ia+s1, ja, b, ib, jb+s1, _state);
        }
        else
        {
            ablassplitlength(a, n, &s1, &s2, _state);
            rmatrixtranspose(m, s1, a, ia, ja, b, ib, jb, _state);
            rmatrixtranspose(m, s2, a, ia, ja+s1, b, ib+s1, jb, _state);
        }
    }
}


/*************************************************************************
Copy

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    B   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void cmatrixcopy(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Complex */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state)
{
    ae_int_t i;


    for(i=0; i<=m-1; i++)
    {
        ae_v_cmove(&b->ptr.pp_complex[ib+i][jb], 1, &a->ptr.pp_complex[ia+i][ja], 1, "N", ae_v_len(jb,jb+n-1));
    }
}


/*************************************************************************
Copy

Input parameters:
    M   -   number of rows
    N   -   number of columns
    A   -   source matrix, MxN submatrix is copied and transposed
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    B   -   destination matrix
    IB  -   submatrix offset (row index)
    JB  -   submatrix offset (column index)
*************************************************************************/
void rmatrixcopy(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Real    */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state)
{
    ae_int_t i;


    for(i=0; i<=m-1; i++)
    {
        ae_v_move(&b->ptr.pp_double[ib+i][jb], 1, &a->ptr.pp_double[ia+i][ja], 1, ae_v_len(jb,jb+n-1));
    }
}


/*************************************************************************
Rank-1 correction: A := A + u*v'

INPUT PARAMETERS:
    M   -   number of rows
    N   -   number of columns
    A   -   target matrix, MxN submatrix is updated
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    U   -   vector #1
    IU  -   subvector offset
    V   -   vector #2
    IV  -   subvector offset
*************************************************************************/
void cmatrixrank1(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Complex */ ae_vector* u,
     ae_int_t iu,
     /* Complex */ ae_vector* v,
     ae_int_t iv,
     ae_state *_state)
{
    ae_int_t i;
    ae_complex s;


    if( m==0||n==0 )
    {
        return;
    }
    if( cmatrixrank1f(m, n, a, ia, ja, u, iu, v, iv, _state) )
    {
        return;
    }
    for(i=0; i<=m-1; i++)
    {
        s = u->ptr.p_complex[iu+i];
        ae_v_caddc(&a->ptr.pp_complex[ia+i][ja], 1, &v->ptr.p_complex[iv], 1, "N", ae_v_len(ja,ja+n-1), s);
    }
}


/*************************************************************************
Rank-1 correction: A := A + u*v'

INPUT PARAMETERS:
    M   -   number of rows
    N   -   number of columns
    A   -   target matrix, MxN submatrix is updated
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    U   -   vector #1
    IU  -   subvector offset
    V   -   vector #2
    IV  -   subvector offset
*************************************************************************/
void rmatrixrank1(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Real    */ ae_vector* u,
     ae_int_t iu,
     /* Real    */ ae_vector* v,
     ae_int_t iv,
     ae_state *_state)
{
    ae_int_t i;
    double s;


    if( m==0||n==0 )
    {
        return;
    }
    if( rmatrixrank1f(m, n, a, ia, ja, u, iu, v, iv, _state) )
    {
        return;
    }
    for(i=0; i<=m-1; i++)
    {
        s = u->ptr.p_double[iu+i];
        ae_v_addd(&a->ptr.pp_double[ia+i][ja], 1, &v->ptr.p_double[iv], 1, ae_v_len(ja,ja+n-1), s);
    }
}


/*************************************************************************
Matrix-vector product: y := op(A)*x

INPUT PARAMETERS:
    M   -   number of rows of op(A)
            M>=0
    N   -   number of columns of op(A)
            N>=0
    A   -   target matrix
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    OpA -   operation type:
            * OpA=0     =>  op(A) = A
            * OpA=1     =>  op(A) = A^T
            * OpA=2     =>  op(A) = A^H
    X   -   input vector
    IX  -   subvector offset
    IY  -   subvector offset

OUTPUT PARAMETERS:
    Y   -   vector which stores result

if M=0, then subroutine does nothing.
if N=0, Y is filled by zeros.


  -- ALGLIB routine --

     28.01.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixmv(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t opa,
     /* Complex */ ae_vector* x,
     ae_int_t ix,
     /* Complex */ ae_vector* y,
     ae_int_t iy,
     ae_state *_state)
{
    ae_int_t i;
    ae_complex v;


    if( m==0 )
    {
        return;
    }
    if( n==0 )
    {
        for(i=0; i<=m-1; i++)
        {
            y->ptr.p_complex[iy+i] = ae_complex_from_d(0);
        }
        return;
    }
    if( cmatrixmvf(m, n, a, ia, ja, opa, x, ix, y, iy, _state) )
    {
        return;
    }
    if( opa==0 )
    {
        
        /*
         * y = A*x
         */
        for(i=0; i<=m-1; i++)
        {
            v = ae_v_cdotproduct(&a->ptr.pp_complex[ia+i][ja], 1, "N", &x->ptr.p_complex[ix], 1, "N", ae_v_len(ja,ja+n-1));
            y->ptr.p_complex[iy+i] = v;
        }
        return;
    }
    if( opa==1 )
    {
        
        /*
         * y = A^T*x
         */
        for(i=0; i<=m-1; i++)
        {
            y->ptr.p_complex[iy+i] = ae_complex_from_d(0);
        }
        for(i=0; i<=n-1; i++)
        {
            v = x->ptr.p_complex[ix+i];
            ae_v_caddc(&y->ptr.p_complex[iy], 1, &a->ptr.pp_complex[ia+i][ja], 1, "N", ae_v_len(iy,iy+m-1), v);
        }
        return;
    }
    if( opa==2 )
    {
        
        /*
         * y = A^H*x
         */
        for(i=0; i<=m-1; i++)
        {
            y->ptr.p_complex[iy+i] = ae_complex_from_d(0);
        }
        for(i=0; i<=n-1; i++)
        {
            v = x->ptr.p_complex[ix+i];
            ae_v_caddc(&y->ptr.p_complex[iy], 1, &a->ptr.pp_complex[ia+i][ja], 1, "Conj", ae_v_len(iy,iy+m-1), v);
        }
        return;
    }
}


/*************************************************************************
Matrix-vector product: y := op(A)*x

INPUT PARAMETERS:
    M   -   number of rows of op(A)
    N   -   number of columns of op(A)
    A   -   target matrix
    IA  -   submatrix offset (row index)
    JA  -   submatrix offset (column index)
    OpA -   operation type:
            * OpA=0     =>  op(A) = A
            * OpA=1     =>  op(A) = A^T
    X   -   input vector
    IX  -   subvector offset
    IY  -   subvector offset

OUTPUT PARAMETERS:
    Y   -   vector which stores result

if M=0, then subroutine does nothing.
if N=0, Y is filled by zeros.


  -- ALGLIB routine --

     28.01.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixmv(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t opa,
     /* Real    */ ae_vector* x,
     ae_int_t ix,
     /* Real    */ ae_vector* y,
     ae_int_t iy,
     ae_state *_state)
{
    ae_int_t i;
    double v;


    if( m==0 )
    {
        return;
    }
    if( n==0 )
    {
        for(i=0; i<=m-1; i++)
        {
            y->ptr.p_double[iy+i] = 0;
        }
        return;
    }
    if( rmatrixmvf(m, n, a, ia, ja, opa, x, ix, y, iy, _state) )
    {
        return;
    }
    if( opa==0 )
    {
        
        /*
         * y = A*x
         */
        for(i=0; i<=m-1; i++)
        {
            v = ae_v_dotproduct(&a->ptr.pp_double[ia+i][ja], 1, &x->ptr.p_double[ix], 1, ae_v_len(ja,ja+n-1));
            y->ptr.p_double[iy+i] = v;
        }
        return;
    }
    if( opa==1 )
    {
        
        /*
         * y = A^T*x
         */
        for(i=0; i<=m-1; i++)
        {
            y->ptr.p_double[iy+i] = 0;
        }
        for(i=0; i<=n-1; i++)
        {
            v = x->ptr.p_double[ix+i];
            ae_v_addd(&y->ptr.p_double[iy], 1, &a->ptr.pp_double[ia+i][ja], 1, ae_v_len(iy,iy+m-1), v);
        }
        return;
    }
}


/*************************************************************************
This subroutine calculates X*op(A^-1) where:
* X is MxN general matrix
* A is NxN upper/lower triangular/unitriangular matrix
* "op" may be identity transformation, transposition, conjugate transposition

Multiplication result replaces X.
Cache-oblivious algorithm is used.

INPUT PARAMETERS
    N   -   matrix size, N>=0
    M   -   matrix size, N>=0
    A       -   matrix, actial matrix is stored in A[I1:I1+N-1,J1:J1+N-1]
    I1      -   submatrix offset
    J1      -   submatrix offset
    IsUpper -   whether matrix is upper triangular
    IsUnit  -   whether matrix is unitriangular
    OpType  -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    C   -   matrix, actial matrix is stored in C[I2:I2+M-1,J2:J2+N-1]
    I2  -   submatrix offset
    J2  -   submatrix offset

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrighttrsm(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Complex */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablascomplexblocksize(a, _state);
    if( m<=bs&&n<=bs )
    {
        ablas_cmatrixrighttrsm2(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        return;
    }
    if( m>=n )
    {
        
        /*
         * Split X: X*A = (X1 X2)^T*A
         */
        ablascomplexsplitlength(a, m, &s1, &s2, _state);
        cmatrixrighttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        cmatrixrighttrsm(s2, n, a, i1, j1, isupper, isunit, optype, x, i2+s1, j2, _state);
    }
    else
    {
        
        /*
         * Split A:
         *               (A1  A12)
         * X*op(A) = X*op(       )
         *               (     A2)
         *
         * Different variants depending on
         * IsUpper/OpType combinations
         */
        ablascomplexsplitlength(a, n, &s1, &s2, _state);
        if( isupper&&optype==0 )
        {
            
            /*
             *                  (A1  A12)-1
             * X*A^-1 = (X1 X2)*(       )
             *                  (     A2)
             */
            cmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            cmatrixgemm(m, s2, s1, ae_complex_from_d(-1.0), x, i2, j2, 0, a, i1, j1+s1, 0, ae_complex_from_d(1.0), x, i2, j2+s1, _state);
            cmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            return;
        }
        if( isupper&&optype!=0 )
        {
            
            /*
             *                  (A1'     )-1
             * X*A^-1 = (X1 X2)*(        )
             *                  (A12' A2')
             */
            cmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            cmatrixgemm(m, s1, s2, ae_complex_from_d(-1.0), x, i2, j2+s1, 0, a, i1, j1+s1, optype, ae_complex_from_d(1.0), x, i2, j2, _state);
            cmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
        if( !isupper&&optype==0 )
        {
            
            /*
             *                  (A1     )-1
             * X*A^-1 = (X1 X2)*(       )
             *                  (A21  A2)
             */
            cmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            cmatrixgemm(m, s1, s2, ae_complex_from_d(-1.0), x, i2, j2+s1, 0, a, i1+s1, j1, 0, ae_complex_from_d(1.0), x, i2, j2, _state);
            cmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
        if( !isupper&&optype!=0 )
        {
            
            /*
             *                  (A1' A21')-1
             * X*A^-1 = (X1 X2)*(        )
             *                  (     A2')
             */
            cmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            cmatrixgemm(m, s2, s1, ae_complex_from_d(-1.0), x, i2, j2, 0, a, i1+s1, j1, optype, ae_complex_from_d(1.0), x, i2, j2+s1, _state);
            cmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            return;
        }
    }
}


/*************************************************************************
This subroutine calculates op(A^-1)*X where:
* X is MxN general matrix
* A is MxM upper/lower triangular/unitriangular matrix
* "op" may be identity transformation, transposition, conjugate transposition

Multiplication result replaces X.
Cache-oblivious algorithm is used.

INPUT PARAMETERS
    N   -   matrix size, N>=0
    M   -   matrix size, N>=0
    A       -   matrix, actial matrix is stored in A[I1:I1+M-1,J1:J1+M-1]
    I1      -   submatrix offset
    J1      -   submatrix offset
    IsUpper -   whether matrix is upper triangular
    IsUnit  -   whether matrix is unitriangular
    OpType  -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    C   -   matrix, actial matrix is stored in C[I2:I2+M-1,J2:J2+N-1]
    I2  -   submatrix offset
    J2  -   submatrix offset

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixlefttrsm(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Complex */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablascomplexblocksize(a, _state);
    if( m<=bs&&n<=bs )
    {
        ablas_cmatrixlefttrsm2(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        return;
    }
    if( n>=m )
    {
        
        /*
         * Split X: op(A)^-1*X = op(A)^-1*(X1 X2)
         */
        ablascomplexsplitlength(x, n, &s1, &s2, _state);
        cmatrixlefttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        cmatrixlefttrsm(m, s2, a, i1, j1, isupper, isunit, optype, x, i2, j2+s1, _state);
    }
    else
    {
        
        /*
         * Split A
         */
        ablascomplexsplitlength(a, m, &s1, &s2, _state);
        if( isupper&&optype==0 )
        {
            
            /*
             *           (A1  A12)-1  ( X1 )
             * A^-1*X* = (       )   *(    )
             *           (     A2)    ( X2 )
             */
            cmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            cmatrixgemm(s1, n, s2, ae_complex_from_d(-1.0), a, i1, j1+s1, 0, x, i2+s1, j2, 0, ae_complex_from_d(1.0), x, i2, j2, _state);
            cmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
        if( isupper&&optype!=0 )
        {
            
            /*
             *          (A1'     )-1 ( X1 )
             * A^-1*X = (        )  *(    )
             *          (A12' A2')   ( X2 )
             */
            cmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            cmatrixgemm(s2, n, s1, ae_complex_from_d(-1.0), a, i1, j1+s1, optype, x, i2, j2, 0, ae_complex_from_d(1.0), x, i2+s1, j2, _state);
            cmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            return;
        }
        if( !isupper&&optype==0 )
        {
            
            /*
             *          (A1     )-1 ( X1 )
             * A^-1*X = (       )  *(    )
             *          (A21  A2)   ( X2 )
             */
            cmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            cmatrixgemm(s2, n, s1, ae_complex_from_d(-1.0), a, i1+s1, j1, 0, x, i2, j2, 0, ae_complex_from_d(1.0), x, i2+s1, j2, _state);
            cmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            return;
        }
        if( !isupper&&optype!=0 )
        {
            
            /*
             *          (A1' A21')-1 ( X1 )
             * A^-1*X = (        )  *(    )
             *          (     A2')   ( X2 )
             */
            cmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            cmatrixgemm(s1, n, s2, ae_complex_from_d(-1.0), a, i1+s1, j1, optype, x, i2+s1, j2, 0, ae_complex_from_d(1.0), x, i2, j2, _state);
            cmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
    }
}


/*************************************************************************
Same as CMatrixRightTRSM, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrighttrsm(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Real    */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablasblocksize(a, _state);
    if( m<=bs&&n<=bs )
    {
        ablas_rmatrixrighttrsm2(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        return;
    }
    if( m>=n )
    {
        
        /*
         * Split X: X*A = (X1 X2)^T*A
         */
        ablassplitlength(a, m, &s1, &s2, _state);
        rmatrixrighttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        rmatrixrighttrsm(s2, n, a, i1, j1, isupper, isunit, optype, x, i2+s1, j2, _state);
    }
    else
    {
        
        /*
         * Split A:
         *               (A1  A12)
         * X*op(A) = X*op(       )
         *               (     A2)
         *
         * Different variants depending on
         * IsUpper/OpType combinations
         */
        ablassplitlength(a, n, &s1, &s2, _state);
        if( isupper&&optype==0 )
        {
            
            /*
             *                  (A1  A12)-1
             * X*A^-1 = (X1 X2)*(       )
             *                  (     A2)
             */
            rmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            rmatrixgemm(m, s2, s1, -1.0, x, i2, j2, 0, a, i1, j1+s1, 0, 1.0, x, i2, j2+s1, _state);
            rmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            return;
        }
        if( isupper&&optype!=0 )
        {
            
            /*
             *                  (A1'     )-1
             * X*A^-1 = (X1 X2)*(        )
             *                  (A12' A2')
             */
            rmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            rmatrixgemm(m, s1, s2, -1.0, x, i2, j2+s1, 0, a, i1, j1+s1, optype, 1.0, x, i2, j2, _state);
            rmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
        if( !isupper&&optype==0 )
        {
            
            /*
             *                  (A1     )-1
             * X*A^-1 = (X1 X2)*(       )
             *                  (A21  A2)
             */
            rmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            rmatrixgemm(m, s1, s2, -1.0, x, i2, j2+s1, 0, a, i1+s1, j1, 0, 1.0, x, i2, j2, _state);
            rmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
        if( !isupper&&optype!=0 )
        {
            
            /*
             *                  (A1' A21')-1
             * X*A^-1 = (X1 X2)*(        )
             *                  (     A2')
             */
            rmatrixrighttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            rmatrixgemm(m, s2, s1, -1.0, x, i2, j2, 0, a, i1+s1, j1, optype, 1.0, x, i2, j2+s1, _state);
            rmatrixrighttrsm(m, s2, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2, j2+s1, _state);
            return;
        }
    }
}


/*************************************************************************
Same as CMatrixLeftTRSM, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixlefttrsm(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Real    */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablasblocksize(a, _state);
    if( m<=bs&&n<=bs )
    {
        ablas_rmatrixlefttrsm2(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        return;
    }
    if( n>=m )
    {
        
        /*
         * Split X: op(A)^-1*X = op(A)^-1*(X1 X2)
         */
        ablassplitlength(x, n, &s1, &s2, _state);
        rmatrixlefttrsm(m, s1, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
        rmatrixlefttrsm(m, s2, a, i1, j1, isupper, isunit, optype, x, i2, j2+s1, _state);
    }
    else
    {
        
        /*
         * Split A
         */
        ablassplitlength(a, m, &s1, &s2, _state);
        if( isupper&&optype==0 )
        {
            
            /*
             *           (A1  A12)-1  ( X1 )
             * A^-1*X* = (       )   *(    )
             *           (     A2)    ( X2 )
             */
            rmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            rmatrixgemm(s1, n, s2, -1.0, a, i1, j1+s1, 0, x, i2+s1, j2, 0, 1.0, x, i2, j2, _state);
            rmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
        if( isupper&&optype!=0 )
        {
            
            /*
             *          (A1'     )-1 ( X1 )
             * A^-1*X = (        )  *(    )
             *          (A12' A2')   ( X2 )
             */
            rmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            rmatrixgemm(s2, n, s1, -1.0, a, i1, j1+s1, optype, x, i2, j2, 0, 1.0, x, i2+s1, j2, _state);
            rmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            return;
        }
        if( !isupper&&optype==0 )
        {
            
            /*
             *          (A1     )-1 ( X1 )
             * A^-1*X = (       )  *(    )
             *          (A21  A2)   ( X2 )
             */
            rmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            rmatrixgemm(s2, n, s1, -1.0, a, i1+s1, j1, 0, x, i2, j2, 0, 1.0, x, i2+s1, j2, _state);
            rmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            return;
        }
        if( !isupper&&optype!=0 )
        {
            
            /*
             *          (A1' A21')-1 ( X1 )
             * A^-1*X = (        )  *(    )
             *          (     A2')   ( X2 )
             */
            rmatrixlefttrsm(s2, n, a, i1+s1, j1+s1, isupper, isunit, optype, x, i2+s1, j2, _state);
            rmatrixgemm(s1, n, s2, -1.0, a, i1+s1, j1, optype, x, i2+s1, j2, 0, 1.0, x, i2, j2, _state);
            rmatrixlefttrsm(s1, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state);
            return;
        }
    }
}


/*************************************************************************
This subroutine calculates  C=alpha*A*A^H+beta*C  or  C=alpha*A^H*A+beta*C
where:
* C is NxN Hermitian matrix given by its upper/lower triangle
* A is NxK matrix when A*A^H is calculated, KxN matrix otherwise

Additional info:
* cache-oblivious algorithm is used.
* multiplication result replaces C. If Beta=0, C elements are not used in
  calculations (not multiplied by zero - just not referenced)
* if Alpha=0, A is not used (not multiplied by zero - just not referenced)
* if both Beta and Alpha are zero, C is filled by zeros.

INPUT PARAMETERS
    N       -   matrix size, N>=0
    K       -   matrix size, K>=0
    Alpha   -   coefficient
    A       -   matrix
    IA      -   submatrix offset
    JA      -   submatrix offset
    OpTypeA -   multiplication type:
                * 0 - A*A^H is calculated
                * 2 - A^H*A is calculated
    Beta    -   coefficient
    C       -   matrix
    IC      -   submatrix offset
    JC      -   submatrix offset
    IsUpper -   whether C is upper triangular or lower triangular

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixsyrk(ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     double beta,
     /* Complex */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_bool isupper,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablascomplexblocksize(a, _state);
    if( n<=bs&&k<=bs )
    {
        ablas_cmatrixsyrk2(n, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
        return;
    }
    if( k>=n )
    {
        
        /*
         * Split K
         */
        ablascomplexsplitlength(a, k, &s1, &s2, _state);
        if( optypea==0 )
        {
            cmatrixsyrk(n, s1, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            cmatrixsyrk(n, s2, alpha, a, ia, ja+s1, optypea, 1.0, c, ic, jc, isupper, _state);
        }
        else
        {
            cmatrixsyrk(n, s1, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            cmatrixsyrk(n, s2, alpha, a, ia+s1, ja, optypea, 1.0, c, ic, jc, isupper, _state);
        }
    }
    else
    {
        
        /*
         * Split N
         */
        ablascomplexsplitlength(a, n, &s1, &s2, _state);
        if( optypea==0&&isupper )
        {
            cmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            cmatrixgemm(s1, s2, k, ae_complex_from_d(alpha), a, ia, ja, 0, a, ia+s1, ja, 2, ae_complex_from_d(beta), c, ic, jc+s1, _state);
            cmatrixsyrk(s2, k, alpha, a, ia+s1, ja, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
        if( optypea==0&&!isupper )
        {
            cmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            cmatrixgemm(s2, s1, k, ae_complex_from_d(alpha), a, ia+s1, ja, 0, a, ia, ja, 2, ae_complex_from_d(beta), c, ic+s1, jc, _state);
            cmatrixsyrk(s2, k, alpha, a, ia+s1, ja, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
        if( optypea!=0&&isupper )
        {
            cmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            cmatrixgemm(s1, s2, k, ae_complex_from_d(alpha), a, ia, ja, 2, a, ia, ja+s1, 0, ae_complex_from_d(beta), c, ic, jc+s1, _state);
            cmatrixsyrk(s2, k, alpha, a, ia, ja+s1, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
        if( optypea!=0&&!isupper )
        {
            cmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            cmatrixgemm(s2, s1, k, ae_complex_from_d(alpha), a, ia, ja+s1, 2, a, ia, ja, 0, ae_complex_from_d(beta), c, ic+s1, jc, _state);
            cmatrixsyrk(s2, k, alpha, a, ia, ja+s1, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
    }
}


/*************************************************************************
Same as CMatrixSYRK, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixsyrk(ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     double beta,
     /* Real    */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_bool isupper,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablasblocksize(a, _state);
    if( n<=bs&&k<=bs )
    {
        ablas_rmatrixsyrk2(n, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
        return;
    }
    if( k>=n )
    {
        
        /*
         * Split K
         */
        ablassplitlength(a, k, &s1, &s2, _state);
        if( optypea==0 )
        {
            rmatrixsyrk(n, s1, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            rmatrixsyrk(n, s2, alpha, a, ia, ja+s1, optypea, 1.0, c, ic, jc, isupper, _state);
        }
        else
        {
            rmatrixsyrk(n, s1, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            rmatrixsyrk(n, s2, alpha, a, ia+s1, ja, optypea, 1.0, c, ic, jc, isupper, _state);
        }
    }
    else
    {
        
        /*
         * Split N
         */
        ablassplitlength(a, n, &s1, &s2, _state);
        if( optypea==0&&isupper )
        {
            rmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            rmatrixgemm(s1, s2, k, alpha, a, ia, ja, 0, a, ia+s1, ja, 1, beta, c, ic, jc+s1, _state);
            rmatrixsyrk(s2, k, alpha, a, ia+s1, ja, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
        if( optypea==0&&!isupper )
        {
            rmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            rmatrixgemm(s2, s1, k, alpha, a, ia+s1, ja, 0, a, ia, ja, 1, beta, c, ic+s1, jc, _state);
            rmatrixsyrk(s2, k, alpha, a, ia+s1, ja, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
        if( optypea!=0&&isupper )
        {
            rmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            rmatrixgemm(s1, s2, k, alpha, a, ia, ja, 1, a, ia, ja+s1, 0, beta, c, ic, jc+s1, _state);
            rmatrixsyrk(s2, k, alpha, a, ia, ja+s1, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
        if( optypea!=0&&!isupper )
        {
            rmatrixsyrk(s1, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state);
            rmatrixgemm(s2, s1, k, alpha, a, ia, ja+s1, 1, a, ia, ja, 0, beta, c, ic+s1, jc, _state);
            rmatrixsyrk(s2, k, alpha, a, ia, ja+s1, optypea, beta, c, ic+s1, jc+s1, isupper, _state);
            return;
        }
    }
}


/*************************************************************************
This subroutine calculates C = alpha*op1(A)*op2(B) +beta*C where:
* C is MxN general matrix
* op1(A) is MxK matrix
* op2(B) is KxN matrix
* "op" may be identity transformation, transposition, conjugate transposition

Additional info:
* cache-oblivious algorithm is used.
* multiplication result replaces C. If Beta=0, C elements are not used in
  calculations (not multiplied by zero - just not referenced)
* if Alpha=0, A is not used (not multiplied by zero - just not referenced)
* if both Beta and Alpha are zero, C is filled by zeros.

INPUT PARAMETERS
    N       -   matrix size, N>0
    M       -   matrix size, N>0
    K       -   matrix size, K>0
    Alpha   -   coefficient
    A       -   matrix
    IA      -   submatrix offset
    JA      -   submatrix offset
    OpTypeA -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    B       -   matrix
    IB      -   submatrix offset
    JB      -   submatrix offset
    OpTypeB -   transformation type:
                * 0 - no transformation
                * 1 - transposition
                * 2 - conjugate transposition
    Beta    -   coefficient
    C       -   matrix
    IC      -   submatrix offset
    JC      -   submatrix offset

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixgemm(ae_int_t m,
     ae_int_t n,
     ae_int_t k,
     ae_complex alpha,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     /* Complex */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_int_t optypeb,
     ae_complex beta,
     /* Complex */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablascomplexblocksize(a, _state);
    if( (m<=bs&&n<=bs)&&k<=bs )
    {
        ablas_cmatrixgemmk(m, n, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
        return;
    }
    if( m>=n&&m>=k )
    {
        
        /*
         * A*B = (A1 A2)^T*B
         */
        ablascomplexsplitlength(a, m, &s1, &s2, _state);
        cmatrixgemm(s1, n, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
        if( optypea==0 )
        {
            cmatrixgemm(s2, n, k, alpha, a, ia+s1, ja, optypea, b, ib, jb, optypeb, beta, c, ic+s1, jc, _state);
        }
        else
        {
            cmatrixgemm(s2, n, k, alpha, a, ia, ja+s1, optypea, b, ib, jb, optypeb, beta, c, ic+s1, jc, _state);
        }
        return;
    }
    if( n>=m&&n>=k )
    {
        
        /*
         * A*B = A*(B1 B2)
         */
        ablascomplexsplitlength(a, n, &s1, &s2, _state);
        if( optypeb==0 )
        {
            cmatrixgemm(m, s1, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            cmatrixgemm(m, s2, k, alpha, a, ia, ja, optypea, b, ib, jb+s1, optypeb, beta, c, ic, jc+s1, _state);
        }
        else
        {
            cmatrixgemm(m, s1, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            cmatrixgemm(m, s2, k, alpha, a, ia, ja, optypea, b, ib+s1, jb, optypeb, beta, c, ic, jc+s1, _state);
        }
        return;
    }
    if( k>=m&&k>=n )
    {
        
        /*
         * A*B = (A1 A2)*(B1 B2)^T
         */
        ablascomplexsplitlength(a, k, &s1, &s2, _state);
        if( optypea==0&&optypeb==0 )
        {
            cmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            cmatrixgemm(m, n, s2, alpha, a, ia, ja+s1, optypea, b, ib+s1, jb, optypeb, ae_complex_from_d(1.0), c, ic, jc, _state);
        }
        if( optypea==0&&optypeb!=0 )
        {
            cmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            cmatrixgemm(m, n, s2, alpha, a, ia, ja+s1, optypea, b, ib, jb+s1, optypeb, ae_complex_from_d(1.0), c, ic, jc, _state);
        }
        if( optypea!=0&&optypeb==0 )
        {
            cmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            cmatrixgemm(m, n, s2, alpha, a, ia+s1, ja, optypea, b, ib+s1, jb, optypeb, ae_complex_from_d(1.0), c, ic, jc, _state);
        }
        if( optypea!=0&&optypeb!=0 )
        {
            cmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            cmatrixgemm(m, n, s2, alpha, a, ia+s1, ja, optypea, b, ib, jb+s1, optypeb, ae_complex_from_d(1.0), c, ic, jc, _state);
        }
        return;
    }
}


/*************************************************************************
Same as CMatrixGEMM, but for real numbers.
OpType may be only 0 or 1.

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixgemm(ae_int_t m,
     ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     /* Real    */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_int_t optypeb,
     double beta,
     /* Real    */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_state *_state)
{
    ae_int_t s1;
    ae_int_t s2;
    ae_int_t bs;


    bs = ablasblocksize(a, _state);
    if( (m<=bs&&n<=bs)&&k<=bs )
    {
        ablas_rmatrixgemmk(m, n, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
        return;
    }
    if( m>=n&&m>=k )
    {
        
        /*
         * A*B = (A1 A2)^T*B
         */
        ablassplitlength(a, m, &s1, &s2, _state);
        if( optypea==0 )
        {
            rmatrixgemm(s1, n, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(s2, n, k, alpha, a, ia+s1, ja, optypea, b, ib, jb, optypeb, beta, c, ic+s1, jc, _state);
        }
        else
        {
            rmatrixgemm(s1, n, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(s2, n, k, alpha, a, ia, ja+s1, optypea, b, ib, jb, optypeb, beta, c, ic+s1, jc, _state);
        }
        return;
    }
    if( n>=m&&n>=k )
    {
        
        /*
         * A*B = A*(B1 B2)
         */
        ablassplitlength(a, n, &s1, &s2, _state);
        if( optypeb==0 )
        {
            rmatrixgemm(m, s1, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(m, s2, k, alpha, a, ia, ja, optypea, b, ib, jb+s1, optypeb, beta, c, ic, jc+s1, _state);
        }
        else
        {
            rmatrixgemm(m, s1, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(m, s2, k, alpha, a, ia, ja, optypea, b, ib+s1, jb, optypeb, beta, c, ic, jc+s1, _state);
        }
        return;
    }
    if( k>=m&&k>=n )
    {
        
        /*
         * A*B = (A1 A2)*(B1 B2)^T
         */
        ablassplitlength(a, k, &s1, &s2, _state);
        if( optypea==0&&optypeb==0 )
        {
            rmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(m, n, s2, alpha, a, ia, ja+s1, optypea, b, ib+s1, jb, optypeb, 1.0, c, ic, jc, _state);
        }
        if( optypea==0&&optypeb!=0 )
        {
            rmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(m, n, s2, alpha, a, ia, ja+s1, optypea, b, ib, jb+s1, optypeb, 1.0, c, ic, jc, _state);
        }
        if( optypea!=0&&optypeb==0 )
        {
            rmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(m, n, s2, alpha, a, ia+s1, ja, optypea, b, ib+s1, jb, optypeb, 1.0, c, ic, jc, _state);
        }
        if( optypea!=0&&optypeb!=0 )
        {
            rmatrixgemm(m, n, s1, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state);
            rmatrixgemm(m, n, s2, alpha, a, ia+s1, ja, optypea, b, ib, jb+s1, optypeb, 1.0, c, ic, jc, _state);
        }
        return;
    }
}


/*************************************************************************
Complex ABLASSplitLength

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
static void ablas_ablasinternalsplitlength(ae_int_t n,
     ae_int_t nb,
     ae_int_t* n1,
     ae_int_t* n2,
     ae_state *_state)
{
    ae_int_t r;

    *n1 = 0;
    *n2 = 0;

    if( n<=nb )
    {
        
        /*
         * Block size, no further splitting
         */
        *n1 = n;
        *n2 = 0;
    }
    else
    {
        
        /*
         * Greater than block size
         */
        if( n%nb!=0 )
        {
            
            /*
             * Split remainder
             */
            *n2 = n%nb;
            *n1 = n-(*n2);
        }
        else
        {
            
            /*
             * Split on block boundaries
             */
            *n2 = n/2;
            *n1 = n-(*n2);
            if( *n1%nb==0 )
            {
                return;
            }
            r = nb-*n1%nb;
            *n1 = *n1+r;
            *n2 = *n2-r;
        }
    }
}


/*************************************************************************
Level 2 variant of CMatrixRightTRSM
*************************************************************************/
static void ablas_cmatrixrighttrsm2(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Complex */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_complex vc;
    ae_complex vd;


    
    /*
     * Special case
     */
    if( n*m==0 )
    {
        return;
    }
    
    /*
     * Try to call fast TRSM
     */
    if( cmatrixrighttrsmf(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state) )
    {
        return;
    }
    
    /*
     * General case
     */
    if( isupper )
    {
        
        /*
         * Upper triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * X*A^(-1)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    if( isunit )
                    {
                        vd = ae_complex_from_d(1);
                    }
                    else
                    {
                        vd = a->ptr.pp_complex[i1+j][j1+j];
                    }
                    x->ptr.pp_complex[i2+i][j2+j] = ae_c_div(x->ptr.pp_complex[i2+i][j2+j],vd);
                    if( j<n-1 )
                    {
                        vc = x->ptr.pp_complex[i2+i][j2+j];
                        ae_v_csubc(&x->ptr.pp_complex[i2+i][j2+j+1], 1, &a->ptr.pp_complex[i1+j][j1+j+1], 1, "N", ae_v_len(j2+j+1,j2+n-1), vc);
                    }
                }
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * X*A^(-T)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=n-1; j>=0; j--)
                {
                    vc = ae_complex_from_d(0);
                    vd = ae_complex_from_d(1);
                    if( j<n-1 )
                    {
                        vc = ae_v_cdotproduct(&x->ptr.pp_complex[i2+i][j2+j+1], 1, "N", &a->ptr.pp_complex[i1+j][j1+j+1], 1, "N", ae_v_len(j2+j+1,j2+n-1));
                    }
                    if( !isunit )
                    {
                        vd = a->ptr.pp_complex[i1+j][j1+j];
                    }
                    x->ptr.pp_complex[i2+i][j2+j] = ae_c_div(ae_c_sub(x->ptr.pp_complex[i2+i][j2+j],vc),vd);
                }
            }
            return;
        }
        if( optype==2 )
        {
            
            /*
             * X*A^(-H)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=n-1; j>=0; j--)
                {
                    vc = ae_complex_from_d(0);
                    vd = ae_complex_from_d(1);
                    if( j<n-1 )
                    {
                        vc = ae_v_cdotproduct(&x->ptr.pp_complex[i2+i][j2+j+1], 1, "N", &a->ptr.pp_complex[i1+j][j1+j+1], 1, "Conj", ae_v_len(j2+j+1,j2+n-1));
                    }
                    if( !isunit )
                    {
                        vd = ae_c_conj(a->ptr.pp_complex[i1+j][j1+j], _state);
                    }
                    x->ptr.pp_complex[i2+i][j2+j] = ae_c_div(ae_c_sub(x->ptr.pp_complex[i2+i][j2+j],vc),vd);
                }
            }
            return;
        }
    }
    else
    {
        
        /*
         * Lower triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * X*A^(-1)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=n-1; j>=0; j--)
                {
                    if( isunit )
                    {
                        vd = ae_complex_from_d(1);
                    }
                    else
                    {
                        vd = a->ptr.pp_complex[i1+j][j1+j];
                    }
                    x->ptr.pp_complex[i2+i][j2+j] = ae_c_div(x->ptr.pp_complex[i2+i][j2+j],vd);
                    if( j>0 )
                    {
                        vc = x->ptr.pp_complex[i2+i][j2+j];
                        ae_v_csubc(&x->ptr.pp_complex[i2+i][j2], 1, &a->ptr.pp_complex[i1+j][j1], 1, "N", ae_v_len(j2,j2+j-1), vc);
                    }
                }
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * X*A^(-T)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    vc = ae_complex_from_d(0);
                    vd = ae_complex_from_d(1);
                    if( j>0 )
                    {
                        vc = ae_v_cdotproduct(&x->ptr.pp_complex[i2+i][j2], 1, "N", &a->ptr.pp_complex[i1+j][j1], 1, "N", ae_v_len(j2,j2+j-1));
                    }
                    if( !isunit )
                    {
                        vd = a->ptr.pp_complex[i1+j][j1+j];
                    }
                    x->ptr.pp_complex[i2+i][j2+j] = ae_c_div(ae_c_sub(x->ptr.pp_complex[i2+i][j2+j],vc),vd);
                }
            }
            return;
        }
        if( optype==2 )
        {
            
            /*
             * X*A^(-H)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    vc = ae_complex_from_d(0);
                    vd = ae_complex_from_d(1);
                    if( j>0 )
                    {
                        vc = ae_v_cdotproduct(&x->ptr.pp_complex[i2+i][j2], 1, "N", &a->ptr.pp_complex[i1+j][j1], 1, "Conj", ae_v_len(j2,j2+j-1));
                    }
                    if( !isunit )
                    {
                        vd = ae_c_conj(a->ptr.pp_complex[i1+j][j1+j], _state);
                    }
                    x->ptr.pp_complex[i2+i][j2+j] = ae_c_div(ae_c_sub(x->ptr.pp_complex[i2+i][j2+j],vc),vd);
                }
            }
            return;
        }
    }
}


/*************************************************************************
Level-2 subroutine
*************************************************************************/
static void ablas_cmatrixlefttrsm2(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Complex */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_complex vc;
    ae_complex vd;


    
    /*
     * Special case
     */
    if( n*m==0 )
    {
        return;
    }
    
    /*
     * Try to call fast TRSM
     */
    if( cmatrixlefttrsmf(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state) )
    {
        return;
    }
    
    /*
     * General case
     */
    if( isupper )
    {
        
        /*
         * Upper triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * A^(-1)*X
             */
            for(i=m-1; i>=0; i--)
            {
                for(j=i+1; j<=m-1; j++)
                {
                    vc = a->ptr.pp_complex[i1+i][j1+j];
                    ae_v_csubc(&x->ptr.pp_complex[i2+i][j2], 1, &x->ptr.pp_complex[i2+j][j2], 1, "N", ae_v_len(j2,j2+n-1), vc);
                }
                if( !isunit )
                {
                    vd = ae_c_d_div(1,a->ptr.pp_complex[i1+i][j1+i]);
                    ae_v_cmulc(&x->ptr.pp_complex[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                }
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * A^(-T)*X
             */
            for(i=0; i<=m-1; i++)
            {
                if( isunit )
                {
                    vd = ae_complex_from_d(1);
                }
                else
                {
                    vd = ae_c_d_div(1,a->ptr.pp_complex[i1+i][j1+i]);
                }
                ae_v_cmulc(&x->ptr.pp_complex[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                for(j=i+1; j<=m-1; j++)
                {
                    vc = a->ptr.pp_complex[i1+i][j1+j];
                    ae_v_csubc(&x->ptr.pp_complex[i2+j][j2], 1, &x->ptr.pp_complex[i2+i][j2], 1, "N", ae_v_len(j2,j2+n-1), vc);
                }
            }
            return;
        }
        if( optype==2 )
        {
            
            /*
             * A^(-H)*X
             */
            for(i=0; i<=m-1; i++)
            {
                if( isunit )
                {
                    vd = ae_complex_from_d(1);
                }
                else
                {
                    vd = ae_c_d_div(1,ae_c_conj(a->ptr.pp_complex[i1+i][j1+i], _state));
                }
                ae_v_cmulc(&x->ptr.pp_complex[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                for(j=i+1; j<=m-1; j++)
                {
                    vc = ae_c_conj(a->ptr.pp_complex[i1+i][j1+j], _state);
                    ae_v_csubc(&x->ptr.pp_complex[i2+j][j2], 1, &x->ptr.pp_complex[i2+i][j2], 1, "N", ae_v_len(j2,j2+n-1), vc);
                }
            }
            return;
        }
    }
    else
    {
        
        /*
         * Lower triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * A^(-1)*X
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=i-1; j++)
                {
                    vc = a->ptr.pp_complex[i1+i][j1+j];
                    ae_v_csubc(&x->ptr.pp_complex[i2+i][j2], 1, &x->ptr.pp_complex[i2+j][j2], 1, "N", ae_v_len(j2,j2+n-1), vc);
                }
                if( isunit )
                {
                    vd = ae_complex_from_d(1);
                }
                else
                {
                    vd = ae_c_d_div(1,a->ptr.pp_complex[i1+j][j1+j]);
                }
                ae_v_cmulc(&x->ptr.pp_complex[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * A^(-T)*X
             */
            for(i=m-1; i>=0; i--)
            {
                if( isunit )
                {
                    vd = ae_complex_from_d(1);
                }
                else
                {
                    vd = ae_c_d_div(1,a->ptr.pp_complex[i1+i][j1+i]);
                }
                ae_v_cmulc(&x->ptr.pp_complex[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                for(j=i-1; j>=0; j--)
                {
                    vc = a->ptr.pp_complex[i1+i][j1+j];
                    ae_v_csubc(&x->ptr.pp_complex[i2+j][j2], 1, &x->ptr.pp_complex[i2+i][j2], 1, "N", ae_v_len(j2,j2+n-1), vc);
                }
            }
            return;
        }
        if( optype==2 )
        {
            
            /*
             * A^(-H)*X
             */
            for(i=m-1; i>=0; i--)
            {
                if( isunit )
                {
                    vd = ae_complex_from_d(1);
                }
                else
                {
                    vd = ae_c_d_div(1,ae_c_conj(a->ptr.pp_complex[i1+i][j1+i], _state));
                }
                ae_v_cmulc(&x->ptr.pp_complex[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                for(j=i-1; j>=0; j--)
                {
                    vc = ae_c_conj(a->ptr.pp_complex[i1+i][j1+j], _state);
                    ae_v_csubc(&x->ptr.pp_complex[i2+j][j2], 1, &x->ptr.pp_complex[i2+i][j2], 1, "N", ae_v_len(j2,j2+n-1), vc);
                }
            }
            return;
        }
    }
}


/*************************************************************************
Level 2 subroutine

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
static void ablas_rmatrixrighttrsm2(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Real    */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double vr;
    double vd;


    
    /*
     * Special case
     */
    if( n*m==0 )
    {
        return;
    }
    
    /*
     * Try to use "fast" code
     */
    if( rmatrixrighttrsmf(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state) )
    {
        return;
    }
    
    /*
     * General case
     */
    if( isupper )
    {
        
        /*
         * Upper triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * X*A^(-1)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    if( isunit )
                    {
                        vd = 1;
                    }
                    else
                    {
                        vd = a->ptr.pp_double[i1+j][j1+j];
                    }
                    x->ptr.pp_double[i2+i][j2+j] = x->ptr.pp_double[i2+i][j2+j]/vd;
                    if( j<n-1 )
                    {
                        vr = x->ptr.pp_double[i2+i][j2+j];
                        ae_v_subd(&x->ptr.pp_double[i2+i][j2+j+1], 1, &a->ptr.pp_double[i1+j][j1+j+1], 1, ae_v_len(j2+j+1,j2+n-1), vr);
                    }
                }
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * X*A^(-T)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=n-1; j>=0; j--)
                {
                    vr = 0;
                    vd = 1;
                    if( j<n-1 )
                    {
                        vr = ae_v_dotproduct(&x->ptr.pp_double[i2+i][j2+j+1], 1, &a->ptr.pp_double[i1+j][j1+j+1], 1, ae_v_len(j2+j+1,j2+n-1));
                    }
                    if( !isunit )
                    {
                        vd = a->ptr.pp_double[i1+j][j1+j];
                    }
                    x->ptr.pp_double[i2+i][j2+j] = (x->ptr.pp_double[i2+i][j2+j]-vr)/vd;
                }
            }
            return;
        }
    }
    else
    {
        
        /*
         * Lower triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * X*A^(-1)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=n-1; j>=0; j--)
                {
                    if( isunit )
                    {
                        vd = 1;
                    }
                    else
                    {
                        vd = a->ptr.pp_double[i1+j][j1+j];
                    }
                    x->ptr.pp_double[i2+i][j2+j] = x->ptr.pp_double[i2+i][j2+j]/vd;
                    if( j>0 )
                    {
                        vr = x->ptr.pp_double[i2+i][j2+j];
                        ae_v_subd(&x->ptr.pp_double[i2+i][j2], 1, &a->ptr.pp_double[i1+j][j1], 1, ae_v_len(j2,j2+j-1), vr);
                    }
                }
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * X*A^(-T)
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    vr = 0;
                    vd = 1;
                    if( j>0 )
                    {
                        vr = ae_v_dotproduct(&x->ptr.pp_double[i2+i][j2], 1, &a->ptr.pp_double[i1+j][j1], 1, ae_v_len(j2,j2+j-1));
                    }
                    if( !isunit )
                    {
                        vd = a->ptr.pp_double[i1+j][j1+j];
                    }
                    x->ptr.pp_double[i2+i][j2+j] = (x->ptr.pp_double[i2+i][j2+j]-vr)/vd;
                }
            }
            return;
        }
    }
}


/*************************************************************************
Level 2 subroutine
*************************************************************************/
static void ablas_rmatrixlefttrsm2(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t i1,
     ae_int_t j1,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t optype,
     /* Real    */ ae_matrix* x,
     ae_int_t i2,
     ae_int_t j2,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double vr;
    double vd;


    
    /*
     * Special case
     */
    if( n*m==0 )
    {
        return;
    }
    
    /*
     * Try fast code
     */
    if( rmatrixlefttrsmf(m, n, a, i1, j1, isupper, isunit, optype, x, i2, j2, _state) )
    {
        return;
    }
    
    /*
     * General case
     */
    if( isupper )
    {
        
        /*
         * Upper triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * A^(-1)*X
             */
            for(i=m-1; i>=0; i--)
            {
                for(j=i+1; j<=m-1; j++)
                {
                    vr = a->ptr.pp_double[i1+i][j1+j];
                    ae_v_subd(&x->ptr.pp_double[i2+i][j2], 1, &x->ptr.pp_double[i2+j][j2], 1, ae_v_len(j2,j2+n-1), vr);
                }
                if( !isunit )
                {
                    vd = 1/a->ptr.pp_double[i1+i][j1+i];
                    ae_v_muld(&x->ptr.pp_double[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                }
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * A^(-T)*X
             */
            for(i=0; i<=m-1; i++)
            {
                if( isunit )
                {
                    vd = 1;
                }
                else
                {
                    vd = 1/a->ptr.pp_double[i1+i][j1+i];
                }
                ae_v_muld(&x->ptr.pp_double[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                for(j=i+1; j<=m-1; j++)
                {
                    vr = a->ptr.pp_double[i1+i][j1+j];
                    ae_v_subd(&x->ptr.pp_double[i2+j][j2], 1, &x->ptr.pp_double[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vr);
                }
            }
            return;
        }
    }
    else
    {
        
        /*
         * Lower triangular matrix
         */
        if( optype==0 )
        {
            
            /*
             * A^(-1)*X
             */
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=i-1; j++)
                {
                    vr = a->ptr.pp_double[i1+i][j1+j];
                    ae_v_subd(&x->ptr.pp_double[i2+i][j2], 1, &x->ptr.pp_double[i2+j][j2], 1, ae_v_len(j2,j2+n-1), vr);
                }
                if( isunit )
                {
                    vd = 1;
                }
                else
                {
                    vd = 1/a->ptr.pp_double[i1+j][j1+j];
                }
                ae_v_muld(&x->ptr.pp_double[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
            }
            return;
        }
        if( optype==1 )
        {
            
            /*
             * A^(-T)*X
             */
            for(i=m-1; i>=0; i--)
            {
                if( isunit )
                {
                    vd = 1;
                }
                else
                {
                    vd = 1/a->ptr.pp_double[i1+i][j1+i];
                }
                ae_v_muld(&x->ptr.pp_double[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vd);
                for(j=i-1; j>=0; j--)
                {
                    vr = a->ptr.pp_double[i1+i][j1+j];
                    ae_v_subd(&x->ptr.pp_double[i2+j][j2], 1, &x->ptr.pp_double[i2+i][j2], 1, ae_v_len(j2,j2+n-1), vr);
                }
            }
            return;
        }
    }
}


/*************************************************************************
Level 2 subroutine
*************************************************************************/
static void ablas_cmatrixsyrk2(ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     double beta,
     /* Complex */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_bool isupper,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_int_t j1;
    ae_int_t j2;
    ae_complex v;


    
    /*
     * Fast exit (nothing to be done)
     */
    if( (ae_fp_eq(alpha,0)||k==0)&&ae_fp_eq(beta,1) )
    {
        return;
    }
    
    /*
     * Try to call fast SYRK
     */
    if( cmatrixsyrkf(n, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state) )
    {
        return;
    }
    
    /*
     * SYRK
     */
    if( optypea==0 )
    {
        
        /*
         * C=alpha*A*A^H+beta*C
         */
        for(i=0; i<=n-1; i++)
        {
            if( isupper )
            {
                j1 = i;
                j2 = n-1;
            }
            else
            {
                j1 = 0;
                j2 = i;
            }
            for(j=j1; j<=j2; j++)
            {
                if( ae_fp_neq(alpha,0)&&k>0 )
                {
                    v = ae_v_cdotproduct(&a->ptr.pp_complex[ia+i][ja], 1, "N", &a->ptr.pp_complex[ia+j][ja], 1, "Conj", ae_v_len(ja,ja+k-1));
                }
                else
                {
                    v = ae_complex_from_d(0);
                }
                if( ae_fp_eq(beta,0) )
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_c_mul_d(v,alpha);
                }
                else
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_c_add(ae_c_mul_d(c->ptr.pp_complex[ic+i][jc+j],beta),ae_c_mul_d(v,alpha));
                }
            }
        }
        return;
    }
    else
    {
        
        /*
         * C=alpha*A^H*A+beta*C
         */
        for(i=0; i<=n-1; i++)
        {
            if( isupper )
            {
                j1 = i;
                j2 = n-1;
            }
            else
            {
                j1 = 0;
                j2 = i;
            }
            if( ae_fp_eq(beta,0) )
            {
                for(j=j1; j<=j2; j++)
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_complex_from_d(0);
                }
            }
            else
            {
                ae_v_cmuld(&c->ptr.pp_complex[ic+i][jc+j1], 1, ae_v_len(jc+j1,jc+j2), beta);
            }
        }
        for(i=0; i<=k-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                if( isupper )
                {
                    j1 = j;
                    j2 = n-1;
                }
                else
                {
                    j1 = 0;
                    j2 = j;
                }
                v = ae_c_mul_d(ae_c_conj(a->ptr.pp_complex[ia+i][ja+j], _state),alpha);
                ae_v_caddc(&c->ptr.pp_complex[ic+j][jc+j1], 1, &a->ptr.pp_complex[ia+i][ja+j1], 1, "N", ae_v_len(jc+j1,jc+j2), v);
            }
        }
        return;
    }
}


/*************************************************************************
Level 2 subrotuine
*************************************************************************/
static void ablas_rmatrixsyrk2(ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     double beta,
     /* Real    */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_bool isupper,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_int_t j1;
    ae_int_t j2;
    double v;


    
    /*
     * Fast exit (nothing to be done)
     */
    if( (ae_fp_eq(alpha,0)||k==0)&&ae_fp_eq(beta,1) )
    {
        return;
    }
    
    /*
     * Try to call fast SYRK
     */
    if( rmatrixsyrkf(n, k, alpha, a, ia, ja, optypea, beta, c, ic, jc, isupper, _state) )
    {
        return;
    }
    
    /*
     * SYRK
     */
    if( optypea==0 )
    {
        
        /*
         * C=alpha*A*A^H+beta*C
         */
        for(i=0; i<=n-1; i++)
        {
            if( isupper )
            {
                j1 = i;
                j2 = n-1;
            }
            else
            {
                j1 = 0;
                j2 = i;
            }
            for(j=j1; j<=j2; j++)
            {
                if( ae_fp_neq(alpha,0)&&k>0 )
                {
                    v = ae_v_dotproduct(&a->ptr.pp_double[ia+i][ja], 1, &a->ptr.pp_double[ia+j][ja], 1, ae_v_len(ja,ja+k-1));
                }
                else
                {
                    v = 0;
                }
                if( ae_fp_eq(beta,0) )
                {
                    c->ptr.pp_double[ic+i][jc+j] = alpha*v;
                }
                else
                {
                    c->ptr.pp_double[ic+i][jc+j] = beta*c->ptr.pp_double[ic+i][jc+j]+alpha*v;
                }
            }
        }
        return;
    }
    else
    {
        
        /*
         * C=alpha*A^H*A+beta*C
         */
        for(i=0; i<=n-1; i++)
        {
            if( isupper )
            {
                j1 = i;
                j2 = n-1;
            }
            else
            {
                j1 = 0;
                j2 = i;
            }
            if( ae_fp_eq(beta,0) )
            {
                for(j=j1; j<=j2; j++)
                {
                    c->ptr.pp_double[ic+i][jc+j] = 0;
                }
            }
            else
            {
                ae_v_muld(&c->ptr.pp_double[ic+i][jc+j1], 1, ae_v_len(jc+j1,jc+j2), beta);
            }
        }
        for(i=0; i<=k-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                if( isupper )
                {
                    j1 = j;
                    j2 = n-1;
                }
                else
                {
                    j1 = 0;
                    j2 = j;
                }
                v = alpha*a->ptr.pp_double[ia+i][ja+j];
                ae_v_addd(&c->ptr.pp_double[ic+j][jc+j1], 1, &a->ptr.pp_double[ia+i][ja+j1], 1, ae_v_len(jc+j1,jc+j2), v);
            }
        }
        return;
    }
}


/*************************************************************************
GEMM kernel

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
static void ablas_cmatrixgemmk(ae_int_t m,
     ae_int_t n,
     ae_int_t k,
     ae_complex alpha,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     /* Complex */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_int_t optypeb,
     ae_complex beta,
     /* Complex */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_complex v;


    
    /*
     * Special case
     */
    if( m*n==0 )
    {
        return;
    }
    
    /*
     * Try optimized code
     */
    if( cmatrixgemmf(m, n, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state) )
    {
        return;
    }
    
    /*
     * Another special case
     */
    if( k==0 )
    {
        if( ae_c_neq_d(beta,0) )
        {
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_c_mul(beta,c->ptr.pp_complex[ic+i][jc+j]);
                }
            }
        }
        else
        {
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_complex_from_d(0);
                }
            }
        }
        return;
    }
    
    /*
     * General case
     */
    if( optypea==0&&optypeb!=0 )
    {
        
        /*
         * A*B'
         */
        for(i=0; i<=m-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                if( k==0||ae_c_eq_d(alpha,0) )
                {
                    v = ae_complex_from_d(0);
                }
                else
                {
                    if( optypeb==1 )
                    {
                        v = ae_v_cdotproduct(&a->ptr.pp_complex[ia+i][ja], 1, "N", &b->ptr.pp_complex[ib+j][jb], 1, "N", ae_v_len(ja,ja+k-1));
                    }
                    else
                    {
                        v = ae_v_cdotproduct(&a->ptr.pp_complex[ia+i][ja], 1, "N", &b->ptr.pp_complex[ib+j][jb], 1, "Conj", ae_v_len(ja,ja+k-1));
                    }
                }
                if( ae_c_eq_d(beta,0) )
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_c_mul(alpha,v);
                }
                else
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_c_add(ae_c_mul(beta,c->ptr.pp_complex[ic+i][jc+j]),ae_c_mul(alpha,v));
                }
            }
        }
        return;
    }
    if( optypea==0&&optypeb==0 )
    {
        
        /*
         * A*B
         */
        for(i=0; i<=m-1; i++)
        {
            if( ae_c_neq_d(beta,0) )
            {
                ae_v_cmulc(&c->ptr.pp_complex[ic+i][jc], 1, ae_v_len(jc,jc+n-1), beta);
            }
            else
            {
                for(j=0; j<=n-1; j++)
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_complex_from_d(0);
                }
            }
            if( ae_c_neq_d(alpha,0) )
            {
                for(j=0; j<=k-1; j++)
                {
                    v = ae_c_mul(alpha,a->ptr.pp_complex[ia+i][ja+j]);
                    ae_v_caddc(&c->ptr.pp_complex[ic+i][jc], 1, &b->ptr.pp_complex[ib+j][jb], 1, "N", ae_v_len(jc,jc+n-1), v);
                }
            }
        }
        return;
    }
    if( optypea!=0&&optypeb!=0 )
    {
        
        /*
         * A'*B'
         */
        for(i=0; i<=m-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                if( ae_c_eq_d(alpha,0) )
                {
                    v = ae_complex_from_d(0);
                }
                else
                {
                    if( optypea==1 )
                    {
                        if( optypeb==1 )
                        {
                            v = ae_v_cdotproduct(&a->ptr.pp_complex[ia][ja+i], a->stride, "N", &b->ptr.pp_complex[ib+j][jb], 1, "N", ae_v_len(ia,ia+k-1));
                        }
                        else
                        {
                            v = ae_v_cdotproduct(&a->ptr.pp_complex[ia][ja+i], a->stride, "N", &b->ptr.pp_complex[ib+j][jb], 1, "Conj", ae_v_len(ia,ia+k-1));
                        }
                    }
                    else
                    {
                        if( optypeb==1 )
                        {
                            v = ae_v_cdotproduct(&a->ptr.pp_complex[ia][ja+i], a->stride, "Conj", &b->ptr.pp_complex[ib+j][jb], 1, "N", ae_v_len(ia,ia+k-1));
                        }
                        else
                        {
                            v = ae_v_cdotproduct(&a->ptr.pp_complex[ia][ja+i], a->stride, "Conj", &b->ptr.pp_complex[ib+j][jb], 1, "Conj", ae_v_len(ia,ia+k-1));
                        }
                    }
                }
                if( ae_c_eq_d(beta,0) )
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_c_mul(alpha,v);
                }
                else
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_c_add(ae_c_mul(beta,c->ptr.pp_complex[ic+i][jc+j]),ae_c_mul(alpha,v));
                }
            }
        }
        return;
    }
    if( optypea!=0&&optypeb==0 )
    {
        
        /*
         * A'*B
         */
        if( ae_c_eq_d(beta,0) )
        {
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    c->ptr.pp_complex[ic+i][jc+j] = ae_complex_from_d(0);
                }
            }
        }
        else
        {
            for(i=0; i<=m-1; i++)
            {
                ae_v_cmulc(&c->ptr.pp_complex[ic+i][jc], 1, ae_v_len(jc,jc+n-1), beta);
            }
        }
        if( ae_c_neq_d(alpha,0) )
        {
            for(j=0; j<=k-1; j++)
            {
                for(i=0; i<=m-1; i++)
                {
                    if( optypea==1 )
                    {
                        v = ae_c_mul(alpha,a->ptr.pp_complex[ia+j][ja+i]);
                    }
                    else
                    {
                        v = ae_c_mul(alpha,ae_c_conj(a->ptr.pp_complex[ia+j][ja+i], _state));
                    }
                    ae_v_caddc(&c->ptr.pp_complex[ic+i][jc], 1, &b->ptr.pp_complex[ib+j][jb], 1, "N", ae_v_len(jc,jc+n-1), v);
                }
            }
        }
        return;
    }
}


/*************************************************************************
GEMM kernel

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
static void ablas_rmatrixgemmk(ae_int_t m,
     ae_int_t n,
     ae_int_t k,
     double alpha,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     ae_int_t optypea,
     /* Real    */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_int_t optypeb,
     double beta,
     /* Real    */ ae_matrix* c,
     ae_int_t ic,
     ae_int_t jc,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double v;


    
    /*
     * if matrix size is zero
     */
    if( m*n==0 )
    {
        return;
    }
    
    /*
     * Try optimized code
     */
    if( rmatrixgemmf(m, n, k, alpha, a, ia, ja, optypea, b, ib, jb, optypeb, beta, c, ic, jc, _state) )
    {
        return;
    }
    
    /*
     * if K=0, then C=Beta*C
     */
    if( k==0 )
    {
        if( ae_fp_neq(beta,1) )
        {
            if( ae_fp_neq(beta,0) )
            {
                for(i=0; i<=m-1; i++)
                {
                    for(j=0; j<=n-1; j++)
                    {
                        c->ptr.pp_double[ic+i][jc+j] = beta*c->ptr.pp_double[ic+i][jc+j];
                    }
                }
            }
            else
            {
                for(i=0; i<=m-1; i++)
                {
                    for(j=0; j<=n-1; j++)
                    {
                        c->ptr.pp_double[ic+i][jc+j] = 0;
                    }
                }
            }
        }
        return;
    }
    
    /*
     * General case
     */
    if( optypea==0&&optypeb!=0 )
    {
        
        /*
         * A*B'
         */
        for(i=0; i<=m-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                if( k==0||ae_fp_eq(alpha,0) )
                {
                    v = 0;
                }
                else
                {
                    v = ae_v_dotproduct(&a->ptr.pp_double[ia+i][ja], 1, &b->ptr.pp_double[ib+j][jb], 1, ae_v_len(ja,ja+k-1));
                }
                if( ae_fp_eq(beta,0) )
                {
                    c->ptr.pp_double[ic+i][jc+j] = alpha*v;
                }
                else
                {
                    c->ptr.pp_double[ic+i][jc+j] = beta*c->ptr.pp_double[ic+i][jc+j]+alpha*v;
                }
            }
        }
        return;
    }
    if( optypea==0&&optypeb==0 )
    {
        
        /*
         * A*B
         */
        for(i=0; i<=m-1; i++)
        {
            if( ae_fp_neq(beta,0) )
            {
                ae_v_muld(&c->ptr.pp_double[ic+i][jc], 1, ae_v_len(jc,jc+n-1), beta);
            }
            else
            {
                for(j=0; j<=n-1; j++)
                {
                    c->ptr.pp_double[ic+i][jc+j] = 0;
                }
            }
            if( ae_fp_neq(alpha,0) )
            {
                for(j=0; j<=k-1; j++)
                {
                    v = alpha*a->ptr.pp_double[ia+i][ja+j];
                    ae_v_addd(&c->ptr.pp_double[ic+i][jc], 1, &b->ptr.pp_double[ib+j][jb], 1, ae_v_len(jc,jc+n-1), v);
                }
            }
        }
        return;
    }
    if( optypea!=0&&optypeb!=0 )
    {
        
        /*
         * A'*B'
         */
        for(i=0; i<=m-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                if( ae_fp_eq(alpha,0) )
                {
                    v = 0;
                }
                else
                {
                    v = ae_v_dotproduct(&a->ptr.pp_double[ia][ja+i], a->stride, &b->ptr.pp_double[ib+j][jb], 1, ae_v_len(ia,ia+k-1));
                }
                if( ae_fp_eq(beta,0) )
                {
                    c->ptr.pp_double[ic+i][jc+j] = alpha*v;
                }
                else
                {
                    c->ptr.pp_double[ic+i][jc+j] = beta*c->ptr.pp_double[ic+i][jc+j]+alpha*v;
                }
            }
        }
        return;
    }
    if( optypea!=0&&optypeb==0 )
    {
        
        /*
         * A'*B
         */
        if( ae_fp_eq(beta,0) )
        {
            for(i=0; i<=m-1; i++)
            {
                for(j=0; j<=n-1; j++)
                {
                    c->ptr.pp_double[ic+i][jc+j] = 0;
                }
            }
        }
        else
        {
            for(i=0; i<=m-1; i++)
            {
                ae_v_muld(&c->ptr.pp_double[ic+i][jc], 1, ae_v_len(jc,jc+n-1), beta);
            }
        }
        if( ae_fp_neq(alpha,0) )
        {
            for(j=0; j<=k-1; j++)
            {
                for(i=0; i<=m-1; i++)
                {
                    v = alpha*a->ptr.pp_double[ia+j][ja+i];
                    ae_v_addd(&c->ptr.pp_double[ic+i][jc], 1, &b->ptr.pp_double[ib+j][jb], 1, ae_v_len(jc,jc+n-1), v);
                }
            }
        }
        return;
    }
}




/*************************************************************************
QR decomposition of a rectangular matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1].
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices Q and R in compact form (see below).
    Tau -   array of scalar factors which are used to form
            matrix Q. Array whose index ranges within [0.. Min(M-1,N-1)].

Matrix A is represented as A = QR, where Q is an orthogonal matrix of size
MxM, R - upper triangular (or upper trapezoid) matrix of size M x N.

The elements of matrix R are located on and above the main diagonal of
matrix A. The elements which are located in Tau array and below the main
diagonal of matrix A are used to form matrix Q as follows:

Matrix Q is represented as a product of elementary reflections

Q = H(0)*H(2)*...*H(k-1),

where k = min(m,n), and each H(i) is in the form

H(i) = 1 - tau * v * (v^T)

where tau is a scalar stored in Tau[I]; v - real vector,
so that v(0:i-1) = 0, v(i) = 1, v(i+1:m-1) stored in A(i+1:m-1,i).

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixqr(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t rowscount;
    ae_int_t i;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_REAL, _state, ae_true);

    if( m<=0||n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    minmn = ae_minint(m, n, _state);
    ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(tau, minmn, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, m, ablasblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpt, ablasblocksize(a, _state), 2*ablasblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, 2*ablasblocksize(a, _state), n, _state);
    
    /*
     * Blocked code
     */
    blockstart = 0;
    while(blockstart!=minmn)
    {
        
        /*
         * Determine block size
         */
        blocksize = minmn-blockstart;
        if( blocksize>ablasblocksize(a, _state) )
        {
            blocksize = ablasblocksize(a, _state);
        }
        rowscount = m-blockstart;
        
        /*
         * QR decomposition of submatrix.
         * Matrix is copied to temporary storage to solve
         * some TLB issues arising from non-contiguous memory
         * access pattern.
         */
        rmatrixcopy(rowscount, blocksize, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ortfac_rmatrixqrbasecase(&tmpa, rowscount, blocksize, &work, &t, &taubuf, _state);
        rmatrixcopy(rowscount, blocksize, &tmpa, 0, 0, a, blockstart, blockstart, _state);
        ae_v_move(&tau->ptr.p_double[blockstart], 1, &taubuf.ptr.p_double[0], 1, ae_v_len(blockstart,blockstart+blocksize-1));
        
        /*
         * Update the rest, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( blockstart+blocksize<=n-1 )
        {
            if( n-blockstart-blocksize>=2*ablasblocksize(a, _state)||rowscount>=4*ablasblocksize(a, _state) )
            {
                
                /*
                 * Prepare block reflector
                 */
                ortfac_rmatrixblockreflector(&tmpa, &taubuf, ae_true, rowscount, blocksize, &tmpt, &work, _state);
                
                /*
                 * Multiply the rest of A by Q'.
                 *
                 * Q  = E + Y*T*Y'  = E + TmpA*TmpT*TmpA'
                 * Q' = E + Y*T'*Y' = E + TmpA*TmpT'*TmpA'
                 */
                rmatrixgemm(blocksize, n-blockstart-blocksize, rowscount, 1.0, &tmpa, 0, 0, 1, a, blockstart, blockstart+blocksize, 0, 0.0, &tmpr, 0, 0, _state);
                rmatrixgemm(blocksize, n-blockstart-blocksize, blocksize, 1.0, &tmpt, 0, 0, 1, &tmpr, 0, 0, 0, 0.0, &tmpr, blocksize, 0, _state);
                rmatrixgemm(rowscount, n-blockstart-blocksize, blocksize, 1.0, &tmpa, 0, 0, 0, &tmpr, blocksize, 0, 0, 1.0, a, blockstart, blockstart+blocksize, _state);
            }
            else
            {
                
                /*
                 * Level 2 algorithm
                 */
                for(i=0; i<=blocksize-1; i++)
                {
                    ae_v_move(&t.ptr.p_double[1], 1, &tmpa.ptr.pp_double[i][i], tmpa.stride, ae_v_len(1,rowscount-i));
                    t.ptr.p_double[1] = 1;
                    applyreflectionfromtheleft(a, taubuf.ptr.p_double[i], &t, blockstart+i, m-1, blockstart+blocksize, n-1, &work, _state);
                }
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart+blocksize;
    }
    ae_frame_leave(_state);
}


/*************************************************************************
LQ decomposition of a rectangular matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1].
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices L and Q in compact form (see below)
    Tau -   array of scalar factors which are used to form
            matrix Q. Array whose index ranges within [0..Min(M,N)-1].

Matrix A is represented as A = LQ, where Q is an orthogonal matrix of size
MxM, L - lower triangular (or lower trapezoid) matrix of size M x N.

The elements of matrix L are located on and below  the  main  diagonal  of
matrix A. The elements which are located in Tau array and above  the  main
diagonal of matrix A are used to form matrix Q as follows:

Matrix Q is represented as a product of elementary reflections

Q = H(k-1)*H(k-2)*...*H(1)*H(0),

where k = min(m,n), and each H(i) is of the form

H(i) = 1 - tau * v * (v^T)

where tau is a scalar stored in Tau[I]; v - real vector, so that v(0:i-1)=0,
v(i) = 1, v(i+1:n-1) stored in A(i,i+1:n-1).

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlq(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t columnscount;
    ae_int_t i;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_REAL, _state, ae_true);

    if( m<=0||n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    minmn = ae_minint(m, n, _state);
    ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(tau, minmn, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, ablasblocksize(a, _state), n, _state);
    ae_matrix_set_length(&tmpt, ablasblocksize(a, _state), 2*ablasblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, m, 2*ablasblocksize(a, _state), _state);
    
    /*
     * Blocked code
     */
    blockstart = 0;
    while(blockstart!=minmn)
    {
        
        /*
         * Determine block size
         */
        blocksize = minmn-blockstart;
        if( blocksize>ablasblocksize(a, _state) )
        {
            blocksize = ablasblocksize(a, _state);
        }
        columnscount = n-blockstart;
        
        /*
         * LQ decomposition of submatrix.
         * Matrix is copied to temporary storage to solve
         * some TLB issues arising from non-contiguous memory
         * access pattern.
         */
        rmatrixcopy(blocksize, columnscount, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ortfac_rmatrixlqbasecase(&tmpa, blocksize, columnscount, &work, &t, &taubuf, _state);
        rmatrixcopy(blocksize, columnscount, &tmpa, 0, 0, a, blockstart, blockstart, _state);
        ae_v_move(&tau->ptr.p_double[blockstart], 1, &taubuf.ptr.p_double[0], 1, ae_v_len(blockstart,blockstart+blocksize-1));
        
        /*
         * Update the rest, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( blockstart+blocksize<=m-1 )
        {
            if( m-blockstart-blocksize>=2*ablasblocksize(a, _state) )
            {
                
                /*
                 * Prepare block reflector
                 */
                ortfac_rmatrixblockreflector(&tmpa, &taubuf, ae_false, columnscount, blocksize, &tmpt, &work, _state);
                
                /*
                 * Multiply the rest of A by Q.
                 *
                 * Q  = E + Y*T*Y'  = E + TmpA'*TmpT*TmpA
                 */
                rmatrixgemm(m-blockstart-blocksize, blocksize, columnscount, 1.0, a, blockstart+blocksize, blockstart, 0, &tmpa, 0, 0, 1, 0.0, &tmpr, 0, 0, _state);
                rmatrixgemm(m-blockstart-blocksize, blocksize, blocksize, 1.0, &tmpr, 0, 0, 0, &tmpt, 0, 0, 0, 0.0, &tmpr, 0, blocksize, _state);
                rmatrixgemm(m-blockstart-blocksize, columnscount, blocksize, 1.0, &tmpr, 0, blocksize, 0, &tmpa, 0, 0, 0, 1.0, a, blockstart+blocksize, blockstart, _state);
            }
            else
            {
                
                /*
                 * Level 2 algorithm
                 */
                for(i=0; i<=blocksize-1; i++)
                {
                    ae_v_move(&t.ptr.p_double[1], 1, &tmpa.ptr.pp_double[i][i], 1, ae_v_len(1,columnscount-i));
                    t.ptr.p_double[1] = 1;
                    applyreflectionfromtheright(a, taubuf.ptr.p_double[i], &t, blockstart+blocksize, m-1, blockstart+i, n-1, &work, _state);
                }
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart+blocksize;
    }
    ae_frame_leave(_state);
}


/*************************************************************************
QR decomposition of a rectangular complex matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1]
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices Q and R in compact form
    Tau -   array of scalar factors which are used to form matrix Q. Array
            whose indexes range within [0.. Min(M,N)-1]

Matrix A is represented as A = QR, where Q is an orthogonal matrix of size
MxM, R - upper triangular (or upper trapezoid) matrix of size MxN.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994
*************************************************************************/
void cmatrixqr(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t rowscount;
    ae_int_t i;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_init(&work, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&t, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_COMPLEX, _state, ae_true);

    if( m<=0||n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    minmn = ae_minint(m, n, _state);
    ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(tau, minmn, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, m, ablascomplexblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpt, ablascomplexblocksize(a, _state), ablascomplexblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, 2*ablascomplexblocksize(a, _state), n, _state);
    
    /*
     * Blocked code
     */
    blockstart = 0;
    while(blockstart!=minmn)
    {
        
        /*
         * Determine block size
         */
        blocksize = minmn-blockstart;
        if( blocksize>ablascomplexblocksize(a, _state) )
        {
            blocksize = ablascomplexblocksize(a, _state);
        }
        rowscount = m-blockstart;
        
        /*
         * QR decomposition of submatrix.
         * Matrix is copied to temporary storage to solve
         * some TLB issues arising from non-contiguous memory
         * access pattern.
         */
        cmatrixcopy(rowscount, blocksize, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ortfac_cmatrixqrbasecase(&tmpa, rowscount, blocksize, &work, &t, &taubuf, _state);
        cmatrixcopy(rowscount, blocksize, &tmpa, 0, 0, a, blockstart, blockstart, _state);
        ae_v_cmove(&tau->ptr.p_complex[blockstart], 1, &taubuf.ptr.p_complex[0], 1, "N", ae_v_len(blockstart,blockstart+blocksize-1));
        
        /*
         * Update the rest, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( blockstart+blocksize<=n-1 )
        {
            if( n-blockstart-blocksize>=2*ablascomplexblocksize(a, _state) )
            {
                
                /*
                 * Prepare block reflector
                 */
                ortfac_cmatrixblockreflector(&tmpa, &taubuf, ae_true, rowscount, blocksize, &tmpt, &work, _state);
                
                /*
                 * Multiply the rest of A by Q'.
                 *
                 * Q  = E + Y*T*Y'  = E + TmpA*TmpT*TmpA'
                 * Q' = E + Y*T'*Y' = E + TmpA*TmpT'*TmpA'
                 */
                cmatrixgemm(blocksize, n-blockstart-blocksize, rowscount, ae_complex_from_d(1.0), &tmpa, 0, 0, 2, a, blockstart, blockstart+blocksize, 0, ae_complex_from_d(0.0), &tmpr, 0, 0, _state);
                cmatrixgemm(blocksize, n-blockstart-blocksize, blocksize, ae_complex_from_d(1.0), &tmpt, 0, 0, 2, &tmpr, 0, 0, 0, ae_complex_from_d(0.0), &tmpr, blocksize, 0, _state);
                cmatrixgemm(rowscount, n-blockstart-blocksize, blocksize, ae_complex_from_d(1.0), &tmpa, 0, 0, 0, &tmpr, blocksize, 0, 0, ae_complex_from_d(1.0), a, blockstart, blockstart+blocksize, _state);
            }
            else
            {
                
                /*
                 * Level 2 algorithm
                 */
                for(i=0; i<=blocksize-1; i++)
                {
                    ae_v_cmove(&t.ptr.p_complex[1], 1, &tmpa.ptr.pp_complex[i][i], tmpa.stride, "N", ae_v_len(1,rowscount-i));
                    t.ptr.p_complex[1] = ae_complex_from_d(1);
                    complexapplyreflectionfromtheleft(a, ae_c_conj(taubuf.ptr.p_complex[i], _state), &t, blockstart+i, m-1, blockstart+blocksize, n-1, &work, _state);
                }
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart+blocksize;
    }
    ae_frame_leave(_state);
}


/*************************************************************************
LQ decomposition of a rectangular complex matrix of size MxN

Input parameters:
    A   -   matrix A whose indexes range within [0..M-1, 0..N-1]
    M   -   number of rows in matrix A.
    N   -   number of columns in matrix A.

Output parameters:
    A   -   matrices Q and L in compact form
    Tau -   array of scalar factors which are used to form matrix Q. Array
            whose indexes range within [0.. Min(M,N)-1]

Matrix A is represented as A = LQ, where Q is an orthogonal matrix of size
MxM, L - lower triangular (or lower trapezoid) matrix of size MxN.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994
*************************************************************************/
void cmatrixlq(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t columnscount;
    ae_int_t i;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_init(&work, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&t, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_COMPLEX, _state, ae_true);

    if( m<=0||n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    minmn = ae_minint(m, n, _state);
    ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(tau, minmn, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, ablascomplexblocksize(a, _state), n, _state);
    ae_matrix_set_length(&tmpt, ablascomplexblocksize(a, _state), ablascomplexblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, m, 2*ablascomplexblocksize(a, _state), _state);
    
    /*
     * Blocked code
     */
    blockstart = 0;
    while(blockstart!=minmn)
    {
        
        /*
         * Determine block size
         */
        blocksize = minmn-blockstart;
        if( blocksize>ablascomplexblocksize(a, _state) )
        {
            blocksize = ablascomplexblocksize(a, _state);
        }
        columnscount = n-blockstart;
        
        /*
         * LQ decomposition of submatrix.
         * Matrix is copied to temporary storage to solve
         * some TLB issues arising from non-contiguous memory
         * access pattern.
         */
        cmatrixcopy(blocksize, columnscount, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ortfac_cmatrixlqbasecase(&tmpa, blocksize, columnscount, &work, &t, &taubuf, _state);
        cmatrixcopy(blocksize, columnscount, &tmpa, 0, 0, a, blockstart, blockstart, _state);
        ae_v_cmove(&tau->ptr.p_complex[blockstart], 1, &taubuf.ptr.p_complex[0], 1, "N", ae_v_len(blockstart,blockstart+blocksize-1));
        
        /*
         * Update the rest, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( blockstart+blocksize<=m-1 )
        {
            if( m-blockstart-blocksize>=2*ablascomplexblocksize(a, _state) )
            {
                
                /*
                 * Prepare block reflector
                 */
                ortfac_cmatrixblockreflector(&tmpa, &taubuf, ae_false, columnscount, blocksize, &tmpt, &work, _state);
                
                /*
                 * Multiply the rest of A by Q.
                 *
                 * Q  = E + Y*T*Y'  = E + TmpA'*TmpT*TmpA
                 */
                cmatrixgemm(m-blockstart-blocksize, blocksize, columnscount, ae_complex_from_d(1.0), a, blockstart+blocksize, blockstart, 0, &tmpa, 0, 0, 2, ae_complex_from_d(0.0), &tmpr, 0, 0, _state);
                cmatrixgemm(m-blockstart-blocksize, blocksize, blocksize, ae_complex_from_d(1.0), &tmpr, 0, 0, 0, &tmpt, 0, 0, 0, ae_complex_from_d(0.0), &tmpr, 0, blocksize, _state);
                cmatrixgemm(m-blockstart-blocksize, columnscount, blocksize, ae_complex_from_d(1.0), &tmpr, 0, blocksize, 0, &tmpa, 0, 0, 0, ae_complex_from_d(1.0), a, blockstart+blocksize, blockstart, _state);
            }
            else
            {
                
                /*
                 * Level 2 algorithm
                 */
                for(i=0; i<=blocksize-1; i++)
                {
                    ae_v_cmove(&t.ptr.p_complex[1], 1, &tmpa.ptr.pp_complex[i][i], 1, "Conj", ae_v_len(1,columnscount-i));
                    t.ptr.p_complex[1] = ae_complex_from_d(1);
                    complexapplyreflectionfromtheright(a, taubuf.ptr.p_complex[i], &t, blockstart+blocksize, m-1, blockstart+i, n-1, &work, _state);
                }
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart+blocksize;
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Partial unpacking of matrix Q from the QR decomposition of a matrix A

Input parameters:
    A       -   matrices Q and R in compact form.
                Output of RMatrixQR subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.
    Tau     -   scalar factors which are used to form Q.
                Output of the RMatrixQR subroutine.
    QColumns -  required number of columns of matrix Q. M>=QColumns>=0.

Output parameters:
    Q       -   first QColumns columns of matrix Q.
                Array whose indexes range within [0..M-1, 0..QColumns-1].
                If QColumns=0, the array remains unchanged.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixqrunpackq(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_int_t qcolumns,
     /* Real    */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_int_t refcnt;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t rowscount;
    ae_int_t i;
    ae_int_t j;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_REAL, _state, ae_true);

    ae_assert(qcolumns<=m, "UnpackQFromQR: QColumns>M!", _state);
    if( (m<=0||n<=0)||qcolumns<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * init
     */
    minmn = ae_minint(m, n, _state);
    refcnt = ae_minint(minmn, qcolumns, _state);
    ae_matrix_set_length(q, m, qcolumns, _state);
    for(i=0; i<=m-1; i++)
    {
        for(j=0; j<=qcolumns-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_double[i][j] = 1;
            }
            else
            {
                q->ptr.pp_double[i][j] = 0;
            }
        }
    }
    ae_vector_set_length(&work, ae_maxint(m, qcolumns, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, qcolumns, _state)+1, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, m, ablasblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpt, ablasblocksize(a, _state), 2*ablasblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, 2*ablasblocksize(a, _state), qcolumns, _state);
    
    /*
     * Blocked code
     */
    blockstart = ablasblocksize(a, _state)*(refcnt/ablasblocksize(a, _state));
    blocksize = refcnt-blockstart;
    while(blockstart>=0)
    {
        rowscount = m-blockstart;
        
        /*
         * Copy current block
         */
        rmatrixcopy(rowscount, blocksize, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ae_v_move(&taubuf.ptr.p_double[0], 1, &tau->ptr.p_double[blockstart], 1, ae_v_len(0,blocksize-1));
        
        /*
         * Update, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( qcolumns>=2*ablasblocksize(a, _state) )
        {
            
            /*
             * Prepare block reflector
             */
            ortfac_rmatrixblockreflector(&tmpa, &taubuf, ae_true, rowscount, blocksize, &tmpt, &work, _state);
            
            /*
             * Multiply matrix by Q.
             *
             * Q  = E + Y*T*Y'  = E + TmpA*TmpT*TmpA'
             */
            rmatrixgemm(blocksize, qcolumns, rowscount, 1.0, &tmpa, 0, 0, 1, q, blockstart, 0, 0, 0.0, &tmpr, 0, 0, _state);
            rmatrixgemm(blocksize, qcolumns, blocksize, 1.0, &tmpt, 0, 0, 0, &tmpr, 0, 0, 0, 0.0, &tmpr, blocksize, 0, _state);
            rmatrixgemm(rowscount, qcolumns, blocksize, 1.0, &tmpa, 0, 0, 0, &tmpr, blocksize, 0, 0, 1.0, q, blockstart, 0, _state);
        }
        else
        {
            
            /*
             * Level 2 algorithm
             */
            for(i=blocksize-1; i>=0; i--)
            {
                ae_v_move(&t.ptr.p_double[1], 1, &tmpa.ptr.pp_double[i][i], tmpa.stride, ae_v_len(1,rowscount-i));
                t.ptr.p_double[1] = 1;
                applyreflectionfromtheleft(q, taubuf.ptr.p_double[i], &t, blockstart+i, m-1, 0, qcolumns-1, &work, _state);
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart-ablasblocksize(a, _state);
        blocksize = ablasblocksize(a, _state);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking of matrix R from the QR decomposition of a matrix A

Input parameters:
    A       -   matrices Q and R in compact form.
                Output of RMatrixQR subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    R       -   matrix R, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixqrunpackr(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* r,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;

    ae_matrix_clear(r);

    if( m<=0||n<=0 )
    {
        return;
    }
    k = ae_minint(m, n, _state);
    ae_matrix_set_length(r, m, n, _state);
    for(i=0; i<=n-1; i++)
    {
        r->ptr.pp_double[0][i] = 0;
    }
    for(i=1; i<=m-1; i++)
    {
        ae_v_move(&r->ptr.pp_double[i][0], 1, &r->ptr.pp_double[0][0], 1, ae_v_len(0,n-1));
    }
    for(i=0; i<=k-1; i++)
    {
        ae_v_move(&r->ptr.pp_double[i][i], 1, &a->ptr.pp_double[i][i], 1, ae_v_len(i,n-1));
    }
}


/*************************************************************************
Partial unpacking of matrix Q from the LQ decomposition of a matrix A

Input parameters:
    A       -   matrices L and Q in compact form.
                Output of RMatrixLQ subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.
    Tau     -   scalar factors which are used to form Q.
                Output of the RMatrixLQ subroutine.
    QRows   -   required number of rows in matrix Q. N>=QRows>=0.

Output parameters:
    Q       -   first QRows rows of matrix Q. Array whose indexes range
                within [0..QRows-1, 0..N-1]. If QRows=0, the array remains
                unchanged.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlqunpackq(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_int_t qrows,
     /* Real    */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_int_t refcnt;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t columnscount;
    ae_int_t i;
    ae_int_t j;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_REAL, _state, ae_true);

    ae_assert(qrows<=n, "RMatrixLQUnpackQ: QRows>N!", _state);
    if( (m<=0||n<=0)||qrows<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * init
     */
    minmn = ae_minint(m, n, _state);
    refcnt = ae_minint(minmn, qrows, _state);
    ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, ablasblocksize(a, _state), n, _state);
    ae_matrix_set_length(&tmpt, ablasblocksize(a, _state), 2*ablasblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, qrows, 2*ablasblocksize(a, _state), _state);
    ae_matrix_set_length(q, qrows, n, _state);
    for(i=0; i<=qrows-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_double[i][j] = 1;
            }
            else
            {
                q->ptr.pp_double[i][j] = 0;
            }
        }
    }
    
    /*
     * Blocked code
     */
    blockstart = ablasblocksize(a, _state)*(refcnt/ablasblocksize(a, _state));
    blocksize = refcnt-blockstart;
    while(blockstart>=0)
    {
        columnscount = n-blockstart;
        
        /*
         * Copy submatrix
         */
        rmatrixcopy(blocksize, columnscount, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ae_v_move(&taubuf.ptr.p_double[0], 1, &tau->ptr.p_double[blockstart], 1, ae_v_len(0,blocksize-1));
        
        /*
         * Update matrix, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( qrows>=2*ablasblocksize(a, _state) )
        {
            
            /*
             * Prepare block reflector
             */
            ortfac_rmatrixblockreflector(&tmpa, &taubuf, ae_false, columnscount, blocksize, &tmpt, &work, _state);
            
            /*
             * Multiply the rest of A by Q'.
             *
             * Q'  = E + Y*T'*Y'  = E + TmpA'*TmpT'*TmpA
             */
            rmatrixgemm(qrows, blocksize, columnscount, 1.0, q, 0, blockstart, 0, &tmpa, 0, 0, 1, 0.0, &tmpr, 0, 0, _state);
            rmatrixgemm(qrows, blocksize, blocksize, 1.0, &tmpr, 0, 0, 0, &tmpt, 0, 0, 1, 0.0, &tmpr, 0, blocksize, _state);
            rmatrixgemm(qrows, columnscount, blocksize, 1.0, &tmpr, 0, blocksize, 0, &tmpa, 0, 0, 0, 1.0, q, 0, blockstart, _state);
        }
        else
        {
            
            /*
             * Level 2 algorithm
             */
            for(i=blocksize-1; i>=0; i--)
            {
                ae_v_move(&t.ptr.p_double[1], 1, &tmpa.ptr.pp_double[i][i], 1, ae_v_len(1,columnscount-i));
                t.ptr.p_double[1] = 1;
                applyreflectionfromtheright(q, taubuf.ptr.p_double[i], &t, 0, qrows-1, blockstart+i, n-1, &work, _state);
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart-ablasblocksize(a, _state);
        blocksize = ablasblocksize(a, _state);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking of matrix L from the LQ decomposition of a matrix A

Input parameters:
    A       -   matrices Q and L in compact form.
                Output of RMatrixLQ subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    L       -   matrix L, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlqunpackl(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* l,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;

    ae_matrix_clear(l);

    if( m<=0||n<=0 )
    {
        return;
    }
    ae_matrix_set_length(l, m, n, _state);
    for(i=0; i<=n-1; i++)
    {
        l->ptr.pp_double[0][i] = 0;
    }
    for(i=1; i<=m-1; i++)
    {
        ae_v_move(&l->ptr.pp_double[i][0], 1, &l->ptr.pp_double[0][0], 1, ae_v_len(0,n-1));
    }
    for(i=0; i<=m-1; i++)
    {
        k = ae_minint(i, n-1, _state);
        ae_v_move(&l->ptr.pp_double[i][0], 1, &a->ptr.pp_double[i][0], 1, ae_v_len(0,k));
    }
}


/*************************************************************************
Partial unpacking of matrix Q from QR decomposition of a complex matrix A.

Input parameters:
    A           -   matrices Q and R in compact form.
                    Output of CMatrixQR subroutine .
    M           -   number of rows in matrix A. M>=0.
    N           -   number of columns in matrix A. N>=0.
    Tau         -   scalar factors which are used to form Q.
                    Output of CMatrixQR subroutine .
    QColumns    -   required number of columns in matrix Q. M>=QColumns>=0.

Output parameters:
    Q           -   first QColumns columns of matrix Q.
                    Array whose index ranges within [0..M-1, 0..QColumns-1].
                    If QColumns=0, array isn't changed.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixqrunpackq(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_int_t qcolumns,
     /* Complex */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_int_t refcnt;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t rowscount;
    ae_int_t i;
    ae_int_t j;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&work, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&t, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_COMPLEX, _state, ae_true);

    ae_assert(qcolumns<=m, "UnpackQFromQR: QColumns>M!", _state);
    if( m<=0||n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * init
     */
    minmn = ae_minint(m, n, _state);
    refcnt = ae_minint(minmn, qcolumns, _state);
    ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, m, ablascomplexblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpt, ablascomplexblocksize(a, _state), ablascomplexblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, 2*ablascomplexblocksize(a, _state), qcolumns, _state);
    ae_matrix_set_length(q, m, qcolumns, _state);
    for(i=0; i<=m-1; i++)
    {
        for(j=0; j<=qcolumns-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_complex[i][j] = ae_complex_from_d(1);
            }
            else
            {
                q->ptr.pp_complex[i][j] = ae_complex_from_d(0);
            }
        }
    }
    
    /*
     * Blocked code
     */
    blockstart = ablascomplexblocksize(a, _state)*(refcnt/ablascomplexblocksize(a, _state));
    blocksize = refcnt-blockstart;
    while(blockstart>=0)
    {
        rowscount = m-blockstart;
        
        /*
         * QR decomposition of submatrix.
         * Matrix is copied to temporary storage to solve
         * some TLB issues arising from non-contiguous memory
         * access pattern.
         */
        cmatrixcopy(rowscount, blocksize, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ae_v_cmove(&taubuf.ptr.p_complex[0], 1, &tau->ptr.p_complex[blockstart], 1, "N", ae_v_len(0,blocksize-1));
        
        /*
         * Update matrix, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( qcolumns>=2*ablascomplexblocksize(a, _state) )
        {
            
            /*
             * Prepare block reflector
             */
            ortfac_cmatrixblockreflector(&tmpa, &taubuf, ae_true, rowscount, blocksize, &tmpt, &work, _state);
            
            /*
             * Multiply the rest of A by Q.
             *
             * Q  = E + Y*T*Y'  = E + TmpA*TmpT*TmpA'
             */
            cmatrixgemm(blocksize, qcolumns, rowscount, ae_complex_from_d(1.0), &tmpa, 0, 0, 2, q, blockstart, 0, 0, ae_complex_from_d(0.0), &tmpr, 0, 0, _state);
            cmatrixgemm(blocksize, qcolumns, blocksize, ae_complex_from_d(1.0), &tmpt, 0, 0, 0, &tmpr, 0, 0, 0, ae_complex_from_d(0.0), &tmpr, blocksize, 0, _state);
            cmatrixgemm(rowscount, qcolumns, blocksize, ae_complex_from_d(1.0), &tmpa, 0, 0, 0, &tmpr, blocksize, 0, 0, ae_complex_from_d(1.0), q, blockstart, 0, _state);
        }
        else
        {
            
            /*
             * Level 2 algorithm
             */
            for(i=blocksize-1; i>=0; i--)
            {
                ae_v_cmove(&t.ptr.p_complex[1], 1, &tmpa.ptr.pp_complex[i][i], tmpa.stride, "N", ae_v_len(1,rowscount-i));
                t.ptr.p_complex[1] = ae_complex_from_d(1);
                complexapplyreflectionfromtheleft(q, taubuf.ptr.p_complex[i], &t, blockstart+i, m-1, 0, qcolumns-1, &work, _state);
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart-ablascomplexblocksize(a, _state);
        blocksize = ablascomplexblocksize(a, _state);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking of matrix R from the QR decomposition of a matrix A

Input parameters:
    A       -   matrices Q and R in compact form.
                Output of CMatrixQR subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    R       -   matrix R, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixqrunpackr(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* r,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;

    ae_matrix_clear(r);

    if( m<=0||n<=0 )
    {
        return;
    }
    k = ae_minint(m, n, _state);
    ae_matrix_set_length(r, m, n, _state);
    for(i=0; i<=n-1; i++)
    {
        r->ptr.pp_complex[0][i] = ae_complex_from_d(0);
    }
    for(i=1; i<=m-1; i++)
    {
        ae_v_cmove(&r->ptr.pp_complex[i][0], 1, &r->ptr.pp_complex[0][0], 1, "N", ae_v_len(0,n-1));
    }
    for(i=0; i<=k-1; i++)
    {
        ae_v_cmove(&r->ptr.pp_complex[i][i], 1, &a->ptr.pp_complex[i][i], 1, "N", ae_v_len(i,n-1));
    }
}


/*************************************************************************
Partial unpacking of matrix Q from LQ decomposition of a complex matrix A.

Input parameters:
    A           -   matrices Q and R in compact form.
                    Output of CMatrixLQ subroutine .
    M           -   number of rows in matrix A. M>=0.
    N           -   number of columns in matrix A. N>=0.
    Tau         -   scalar factors which are used to form Q.
                    Output of CMatrixLQ subroutine .
    QRows       -   required number of rows in matrix Q. N>=QColumns>=0.

Output parameters:
    Q           -   first QRows rows of matrix Q.
                    Array whose index ranges within [0..QRows-1, 0..N-1].
                    If QRows=0, array isn't changed.

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixlqunpackq(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_int_t qrows,
     /* Complex */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_vector taubuf;
    ae_int_t minmn;
    ae_int_t refcnt;
    ae_matrix tmpa;
    ae_matrix tmpt;
    ae_matrix tmpr;
    ae_int_t blockstart;
    ae_int_t blocksize;
    ae_int_t columnscount;
    ae_int_t i;
    ae_int_t j;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&work, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&t, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&taubuf, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpa, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpt, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&tmpr, 0, 0, DT_COMPLEX, _state, ae_true);

    if( m<=0||n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Init
     */
    minmn = ae_minint(m, n, _state);
    refcnt = ae_minint(minmn, qrows, _state);
    ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&t, ae_maxint(m, n, _state)+1, _state);
    ae_vector_set_length(&taubuf, minmn, _state);
    ae_matrix_set_length(&tmpa, ablascomplexblocksize(a, _state), n, _state);
    ae_matrix_set_length(&tmpt, ablascomplexblocksize(a, _state), ablascomplexblocksize(a, _state), _state);
    ae_matrix_set_length(&tmpr, qrows, 2*ablascomplexblocksize(a, _state), _state);
    ae_matrix_set_length(q, qrows, n, _state);
    for(i=0; i<=qrows-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_complex[i][j] = ae_complex_from_d(1);
            }
            else
            {
                q->ptr.pp_complex[i][j] = ae_complex_from_d(0);
            }
        }
    }
    
    /*
     * Blocked code
     */
    blockstart = ablascomplexblocksize(a, _state)*(refcnt/ablascomplexblocksize(a, _state));
    blocksize = refcnt-blockstart;
    while(blockstart>=0)
    {
        columnscount = n-blockstart;
        
        /*
         * LQ decomposition of submatrix.
         * Matrix is copied to temporary storage to solve
         * some TLB issues arising from non-contiguous memory
         * access pattern.
         */
        cmatrixcopy(blocksize, columnscount, a, blockstart, blockstart, &tmpa, 0, 0, _state);
        ae_v_cmove(&taubuf.ptr.p_complex[0], 1, &tau->ptr.p_complex[blockstart], 1, "N", ae_v_len(0,blocksize-1));
        
        /*
         * Update matrix, choose between:
         * a) Level 2 algorithm (when the rest of the matrix is small enough)
         * b) blocked algorithm, see algorithm 5 from  'A storage efficient WY
         *    representation for products of Householder transformations',
         *    by R. Schreiber and C. Van Loan.
         */
        if( qrows>=2*ablascomplexblocksize(a, _state) )
        {
            
            /*
             * Prepare block reflector
             */
            ortfac_cmatrixblockreflector(&tmpa, &taubuf, ae_false, columnscount, blocksize, &tmpt, &work, _state);
            
            /*
             * Multiply the rest of A by Q'.
             *
             * Q'  = E + Y*T'*Y'  = E + TmpA'*TmpT'*TmpA
             */
            cmatrixgemm(qrows, blocksize, columnscount, ae_complex_from_d(1.0), q, 0, blockstart, 0, &tmpa, 0, 0, 2, ae_complex_from_d(0.0), &tmpr, 0, 0, _state);
            cmatrixgemm(qrows, blocksize, blocksize, ae_complex_from_d(1.0), &tmpr, 0, 0, 0, &tmpt, 0, 0, 2, ae_complex_from_d(0.0), &tmpr, 0, blocksize, _state);
            cmatrixgemm(qrows, columnscount, blocksize, ae_complex_from_d(1.0), &tmpr, 0, blocksize, 0, &tmpa, 0, 0, 0, ae_complex_from_d(1.0), q, 0, blockstart, _state);
        }
        else
        {
            
            /*
             * Level 2 algorithm
             */
            for(i=blocksize-1; i>=0; i--)
            {
                ae_v_cmove(&t.ptr.p_complex[1], 1, &tmpa.ptr.pp_complex[i][i], 1, "Conj", ae_v_len(1,columnscount-i));
                t.ptr.p_complex[1] = ae_complex_from_d(1);
                complexapplyreflectionfromtheright(q, ae_c_conj(taubuf.ptr.p_complex[i], _state), &t, 0, qrows-1, blockstart+i, n-1, &work, _state);
            }
        }
        
        /*
         * Advance
         */
        blockstart = blockstart-ablascomplexblocksize(a, _state);
        blocksize = ablascomplexblocksize(a, _state);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking of matrix L from the LQ decomposition of a matrix A

Input parameters:
    A       -   matrices Q and L in compact form.
                Output of CMatrixLQ subroutine.
    M       -   number of rows in given matrix A. M>=0.
    N       -   number of columns in given matrix A. N>=0.

Output parameters:
    L       -   matrix L, array[0..M-1, 0..N-1].

  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixlqunpackl(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* l,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;

    ae_matrix_clear(l);

    if( m<=0||n<=0 )
    {
        return;
    }
    ae_matrix_set_length(l, m, n, _state);
    for(i=0; i<=n-1; i++)
    {
        l->ptr.pp_complex[0][i] = ae_complex_from_d(0);
    }
    for(i=1; i<=m-1; i++)
    {
        ae_v_cmove(&l->ptr.pp_complex[i][0], 1, &l->ptr.pp_complex[0][0], 1, "N", ae_v_len(0,n-1));
    }
    for(i=0; i<=m-1; i++)
    {
        k = ae_minint(i, n-1, _state);
        ae_v_cmove(&l->ptr.pp_complex[i][0], 1, &a->ptr.pp_complex[i][0], 1, "N", ae_v_len(0,k));
    }
}


/*************************************************************************
Reduction of a rectangular matrix to  bidiagonal form

The algorithm reduces the rectangular matrix A to  bidiagonal form by
orthogonal transformations P and Q: A = Q*B*P.

Input parameters:
    A       -   source matrix. array[0..M-1, 0..N-1]
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.

Output parameters:
    A       -   matrices Q, B, P in compact form (see below).
    TauQ    -   scalar factors which are used to form matrix Q.
    TauP    -   scalar factors which are used to form matrix P.

The main diagonal and one of the  secondary  diagonals  of  matrix  A  are
replaced with bidiagonal  matrix  B.  Other  elements  contain  elementary
reflections which form MxM matrix Q and NxN matrix P, respectively.

If M>=N, B is the upper  bidiagonal  MxN  matrix  and  is  stored  in  the
corresponding  elements  of  matrix  A.  Matrix  Q  is  represented  as  a
product   of   elementary   reflections   Q = H(0)*H(1)*...*H(n-1),  where
H(i) = 1-tau*v*v'. Here tau is a scalar which is stored  in  TauQ[i],  and
vector v has the following  structure:  v(0:i-1)=0, v(i)=1, v(i+1:m-1)  is
stored   in   elements   A(i+1:m-1,i).   Matrix   P  is  as  follows:  P =
G(0)*G(1)*...*G(n-2), where G(i) = 1 - tau*u*u'. Tau is stored in TauP[i],
u(0:i)=0, u(i+1)=1, u(i+2:n-1) is stored in elements A(i,i+2:n-1).

If M<N, B is the  lower  bidiagonal  MxN  matrix  and  is  stored  in  the
corresponding   elements  of  matrix  A.  Q = H(0)*H(1)*...*H(m-2),  where
H(i) = 1 - tau*v*v', tau is stored in TauQ, v(0:i)=0, v(i+1)=1, v(i+2:m-1)
is    stored    in   elements   A(i+2:m-1,i).    P = G(0)*G(1)*...*G(m-1),
G(i) = 1-tau*u*u', tau is stored in  TauP,  u(0:i-1)=0, u(i)=1, u(i+1:n-1)
is stored in A(i,i+1:n-1).

EXAMPLE:

m=6, n=5 (m > n):               m=5, n=6 (m < n):

(  d   e   u1  u1  u1 )         (  d   u1  u1  u1  u1  u1 )
(  v1  d   e   u2  u2 )         (  e   d   u2  u2  u2  u2 )
(  v1  v2  d   e   u3 )         (  v1  e   d   u3  u3  u3 )
(  v1  v2  v3  d   e  )         (  v1  v2  e   d   u4  u4 )
(  v1  v2  v3  v4  d  )         (  v1  v2  v3  e   d   u5 )
(  v1  v2  v3  v4  v5 )

Here vi and ui are vectors which form H(i) and G(i), and d and e -
are the diagonal and off-diagonal elements of matrix B.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994.
     Sergey Bochkanov, ALGLIB project, translation from FORTRAN to
     pseudocode, 2007-2010.
*************************************************************************/
void rmatrixbd(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tauq,
     /* Real    */ ae_vector* taup,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_vector t;
    ae_int_t minmn;
    ae_int_t maxmn;
    ae_int_t i;
    double ltau;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tauq);
    ae_vector_clear(taup);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);

    
    /*
     * Prepare
     */
    if( n<=0||m<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    minmn = ae_minint(m, n, _state);
    maxmn = ae_maxint(m, n, _state);
    ae_vector_set_length(&work, maxmn+1, _state);
    ae_vector_set_length(&t, maxmn+1, _state);
    if( m>=n )
    {
        ae_vector_set_length(tauq, n, _state);
        ae_vector_set_length(taup, n, _state);
    }
    else
    {
        ae_vector_set_length(tauq, m, _state);
        ae_vector_set_length(taup, m, _state);
    }
    if( m>=n )
    {
        
        /*
         * Reduce to upper bidiagonal form
         */
        for(i=0; i<=n-1; i++)
        {
            
            /*
             * Generate elementary reflector H(i) to annihilate A(i+1:m-1,i)
             */
            ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i][i], a->stride, ae_v_len(1,m-i));
            generatereflection(&t, m-i, &ltau, _state);
            tauq->ptr.p_double[i] = ltau;
            ae_v_move(&a->ptr.pp_double[i][i], a->stride, &t.ptr.p_double[1], 1, ae_v_len(i,m-1));
            t.ptr.p_double[1] = 1;
            
            /*
             * Apply H(i) to A(i:m-1,i+1:n-1) from the left
             */
            applyreflectionfromtheleft(a, ltau, &t, i, m-1, i+1, n-1, &work, _state);
            if( i<n-1 )
            {
                
                /*
                 * Generate elementary reflector G(i) to annihilate
                 * A(i,i+2:n-1)
                 */
                ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i][i+1], 1, ae_v_len(1,n-i-1));
                generatereflection(&t, n-1-i, &ltau, _state);
                taup->ptr.p_double[i] = ltau;
                ae_v_move(&a->ptr.pp_double[i][i+1], 1, &t.ptr.p_double[1], 1, ae_v_len(i+1,n-1));
                t.ptr.p_double[1] = 1;
                
                /*
                 * Apply G(i) to A(i+1:m-1,i+1:n-1) from the right
                 */
                applyreflectionfromtheright(a, ltau, &t, i+1, m-1, i+1, n-1, &work, _state);
            }
            else
            {
                taup->ptr.p_double[i] = 0;
            }
        }
    }
    else
    {
        
        /*
         * Reduce to lower bidiagonal form
         */
        for(i=0; i<=m-1; i++)
        {
            
            /*
             * Generate elementary reflector G(i) to annihilate A(i,i+1:n-1)
             */
            ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i][i], 1, ae_v_len(1,n-i));
            generatereflection(&t, n-i, &ltau, _state);
            taup->ptr.p_double[i] = ltau;
            ae_v_move(&a->ptr.pp_double[i][i], 1, &t.ptr.p_double[1], 1, ae_v_len(i,n-1));
            t.ptr.p_double[1] = 1;
            
            /*
             * Apply G(i) to A(i+1:m-1,i:n-1) from the right
             */
            applyreflectionfromtheright(a, ltau, &t, i+1, m-1, i, n-1, &work, _state);
            if( i<m-1 )
            {
                
                /*
                 * Generate elementary reflector H(i) to annihilate
                 * A(i+2:m-1,i)
                 */
                ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(1,m-1-i));
                generatereflection(&t, m-1-i, &ltau, _state);
                tauq->ptr.p_double[i] = ltau;
                ae_v_move(&a->ptr.pp_double[i+1][i], a->stride, &t.ptr.p_double[1], 1, ae_v_len(i+1,m-1));
                t.ptr.p_double[1] = 1;
                
                /*
                 * Apply H(i) to A(i+1:m-1,i+1:n-1) from the left
                 */
                applyreflectionfromtheleft(a, ltau, &t, i+1, m-1, i+1, n-1, &work, _state);
            }
            else
            {
                tauq->ptr.p_double[i] = 0;
            }
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking matrix Q which reduces a matrix to bidiagonal form.

Input parameters:
    QP          -   matrices Q and P in compact form.
                    Output of ToBidiagonal subroutine.
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    TAUQ        -   scalar factors which are used to form Q.
                    Output of ToBidiagonal subroutine.
    QColumns    -   required number of columns in matrix Q.
                    M>=QColumns>=0.

Output parameters:
    Q           -   first QColumns columns of matrix Q.
                    Array[0..M-1, 0..QColumns-1]
                    If QColumns=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdunpackq(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tauq,
     ae_int_t qcolumns,
     /* Real    */ ae_matrix* q,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;

    ae_matrix_clear(q);

    ae_assert(qcolumns<=m, "RMatrixBDUnpackQ: QColumns>M!", _state);
    ae_assert(qcolumns>=0, "RMatrixBDUnpackQ: QColumns<0!", _state);
    if( (m==0||n==0)||qcolumns==0 )
    {
        return;
    }
    
    /*
     * prepare Q
     */
    ae_matrix_set_length(q, m, qcolumns, _state);
    for(i=0; i<=m-1; i++)
    {
        for(j=0; j<=qcolumns-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_double[i][j] = 1;
            }
            else
            {
                q->ptr.pp_double[i][j] = 0;
            }
        }
    }
    
    /*
     * Calculate
     */
    rmatrixbdmultiplybyq(qp, m, n, tauq, q, m, qcolumns, ae_false, ae_false, _state);
}


/*************************************************************************
Multiplication by matrix Q which reduces matrix A to  bidiagonal form.

The algorithm allows pre- or post-multiply by Q or Q'.

Input parameters:
    QP          -   matrices Q and P in compact form.
                    Output of ToBidiagonal subroutine.
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    TAUQ        -   scalar factors which are used to form Q.
                    Output of ToBidiagonal subroutine.
    Z           -   multiplied matrix.
                    array[0..ZRows-1,0..ZColumns-1]
    ZRows       -   number of rows in matrix Z. If FromTheRight=False,
                    ZRows=M, otherwise ZRows can be arbitrary.
    ZColumns    -   number of columns in matrix Z. If FromTheRight=True,
                    ZColumns=M, otherwise ZColumns can be arbitrary.
    FromTheRight -  pre- or post-multiply.
    DoTranspose -   multiply by Q or Q'.

Output parameters:
    Z           -   product of Z and Q.
                    Array[0..ZRows-1,0..ZColumns-1]
                    If ZRows=0 or ZColumns=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdmultiplybyq(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tauq,
     /* Real    */ ae_matrix* z,
     ae_int_t zrows,
     ae_int_t zcolumns,
     ae_bool fromtheright,
     ae_bool dotranspose,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t i1;
    ae_int_t i2;
    ae_int_t istep;
    ae_vector v;
    ae_vector work;
    ae_int_t mx;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    if( ((m<=0||n<=0)||zrows<=0)||zcolumns<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    ae_assert((fromtheright&&zcolumns==m)||(!fromtheright&&zrows==m), "RMatrixBDMultiplyByQ: incorrect Z size!", _state);
    
    /*
     * init
     */
    mx = ae_maxint(m, n, _state);
    mx = ae_maxint(mx, zrows, _state);
    mx = ae_maxint(mx, zcolumns, _state);
    ae_vector_set_length(&v, mx+1, _state);
    ae_vector_set_length(&work, mx+1, _state);
    if( m>=n )
    {
        
        /*
         * setup
         */
        if( fromtheright )
        {
            i1 = 0;
            i2 = n-1;
            istep = 1;
        }
        else
        {
            i1 = n-1;
            i2 = 0;
            istep = -1;
        }
        if( dotranspose )
        {
            i = i1;
            i1 = i2;
            i2 = i;
            istep = -istep;
        }
        
        /*
         * Process
         */
        i = i1;
        do
        {
            ae_v_move(&v.ptr.p_double[1], 1, &qp->ptr.pp_double[i][i], qp->stride, ae_v_len(1,m-i));
            v.ptr.p_double[1] = 1;
            if( fromtheright )
            {
                applyreflectionfromtheright(z, tauq->ptr.p_double[i], &v, 0, zrows-1, i, m-1, &work, _state);
            }
            else
            {
                applyreflectionfromtheleft(z, tauq->ptr.p_double[i], &v, i, m-1, 0, zcolumns-1, &work, _state);
            }
            i = i+istep;
        }
        while(i!=i2+istep);
    }
    else
    {
        
        /*
         * setup
         */
        if( fromtheright )
        {
            i1 = 0;
            i2 = m-2;
            istep = 1;
        }
        else
        {
            i1 = m-2;
            i2 = 0;
            istep = -1;
        }
        if( dotranspose )
        {
            i = i1;
            i1 = i2;
            i2 = i;
            istep = -istep;
        }
        
        /*
         * Process
         */
        if( m-1>0 )
        {
            i = i1;
            do
            {
                ae_v_move(&v.ptr.p_double[1], 1, &qp->ptr.pp_double[i+1][i], qp->stride, ae_v_len(1,m-i-1));
                v.ptr.p_double[1] = 1;
                if( fromtheright )
                {
                    applyreflectionfromtheright(z, tauq->ptr.p_double[i], &v, 0, zrows-1, i+1, m-1, &work, _state);
                }
                else
                {
                    applyreflectionfromtheleft(z, tauq->ptr.p_double[i], &v, i+1, m-1, 0, zcolumns-1, &work, _state);
                }
                i = i+istep;
            }
            while(i!=i2+istep);
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking matrix P which reduces matrix A to bidiagonal form.
The subroutine returns transposed matrix P.

Input parameters:
    QP      -   matrices Q and P in compact form.
                Output of ToBidiagonal subroutine.
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.
    TAUP    -   scalar factors which are used to form P.
                Output of ToBidiagonal subroutine.
    PTRows  -   required number of rows of matrix P^T. N >= PTRows >= 0.

Output parameters:
    PT      -   first PTRows columns of matrix P^T
                Array[0..PTRows-1, 0..N-1]
                If PTRows=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdunpackpt(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* taup,
     ae_int_t ptrows,
     /* Real    */ ae_matrix* pt,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;

    ae_matrix_clear(pt);

    ae_assert(ptrows<=n, "RMatrixBDUnpackPT: PTRows>N!", _state);
    ae_assert(ptrows>=0, "RMatrixBDUnpackPT: PTRows<0!", _state);
    if( (m==0||n==0)||ptrows==0 )
    {
        return;
    }
    
    /*
     * prepare PT
     */
    ae_matrix_set_length(pt, ptrows, n, _state);
    for(i=0; i<=ptrows-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                pt->ptr.pp_double[i][j] = 1;
            }
            else
            {
                pt->ptr.pp_double[i][j] = 0;
            }
        }
    }
    
    /*
     * Calculate
     */
    rmatrixbdmultiplybyp(qp, m, n, taup, pt, ptrows, n, ae_true, ae_true, _state);
}


/*************************************************************************
Multiplication by matrix P which reduces matrix A to  bidiagonal form.

The algorithm allows pre- or post-multiply by P or P'.

Input parameters:
    QP          -   matrices Q and P in compact form.
                    Output of RMatrixBD subroutine.
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    TAUP        -   scalar factors which are used to form P.
                    Output of RMatrixBD subroutine.
    Z           -   multiplied matrix.
                    Array whose indexes range within [0..ZRows-1,0..ZColumns-1].
    ZRows       -   number of rows in matrix Z. If FromTheRight=False,
                    ZRows=N, otherwise ZRows can be arbitrary.
    ZColumns    -   number of columns in matrix Z. If FromTheRight=True,
                    ZColumns=N, otherwise ZColumns can be arbitrary.
    FromTheRight -  pre- or post-multiply.
    DoTranspose -   multiply by P or P'.

Output parameters:
    Z - product of Z and P.
                Array whose indexes range within [0..ZRows-1,0..ZColumns-1].
                If ZRows=0 or ZColumns=0, the array is not modified.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdmultiplybyp(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* taup,
     /* Real    */ ae_matrix* z,
     ae_int_t zrows,
     ae_int_t zcolumns,
     ae_bool fromtheright,
     ae_bool dotranspose,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_vector v;
    ae_vector work;
    ae_int_t mx;
    ae_int_t i1;
    ae_int_t i2;
    ae_int_t istep;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    if( ((m<=0||n<=0)||zrows<=0)||zcolumns<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    ae_assert((fromtheright&&zcolumns==n)||(!fromtheright&&zrows==n), "RMatrixBDMultiplyByP: incorrect Z size!", _state);
    
    /*
     * init
     */
    mx = ae_maxint(m, n, _state);
    mx = ae_maxint(mx, zrows, _state);
    mx = ae_maxint(mx, zcolumns, _state);
    ae_vector_set_length(&v, mx+1, _state);
    ae_vector_set_length(&work, mx+1, _state);
    if( m>=n )
    {
        
        /*
         * setup
         */
        if( fromtheright )
        {
            i1 = n-2;
            i2 = 0;
            istep = -1;
        }
        else
        {
            i1 = 0;
            i2 = n-2;
            istep = 1;
        }
        if( !dotranspose )
        {
            i = i1;
            i1 = i2;
            i2 = i;
            istep = -istep;
        }
        
        /*
         * Process
         */
        if( n-1>0 )
        {
            i = i1;
            do
            {
                ae_v_move(&v.ptr.p_double[1], 1, &qp->ptr.pp_double[i][i+1], 1, ae_v_len(1,n-1-i));
                v.ptr.p_double[1] = 1;
                if( fromtheright )
                {
                    applyreflectionfromtheright(z, taup->ptr.p_double[i], &v, 0, zrows-1, i+1, n-1, &work, _state);
                }
                else
                {
                    applyreflectionfromtheleft(z, taup->ptr.p_double[i], &v, i+1, n-1, 0, zcolumns-1, &work, _state);
                }
                i = i+istep;
            }
            while(i!=i2+istep);
        }
    }
    else
    {
        
        /*
         * setup
         */
        if( fromtheright )
        {
            i1 = m-1;
            i2 = 0;
            istep = -1;
        }
        else
        {
            i1 = 0;
            i2 = m-1;
            istep = 1;
        }
        if( !dotranspose )
        {
            i = i1;
            i1 = i2;
            i2 = i;
            istep = -istep;
        }
        
        /*
         * Process
         */
        i = i1;
        do
        {
            ae_v_move(&v.ptr.p_double[1], 1, &qp->ptr.pp_double[i][i], 1, ae_v_len(1,n-i));
            v.ptr.p_double[1] = 1;
            if( fromtheright )
            {
                applyreflectionfromtheright(z, taup->ptr.p_double[i], &v, 0, zrows-1, i, n-1, &work, _state);
            }
            else
            {
                applyreflectionfromtheleft(z, taup->ptr.p_double[i], &v, i, n-1, 0, zcolumns-1, &work, _state);
            }
            i = i+istep;
        }
        while(i!=i2+istep);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking of the main and secondary diagonals of bidiagonal decomposition
of matrix A.

Input parameters:
    B   -   output of RMatrixBD subroutine.
    M   -   number of rows in matrix B.
    N   -   number of columns in matrix B.

Output parameters:
    IsUpper -   True, if the matrix is upper bidiagonal.
                otherwise IsUpper is False.
    D       -   the main diagonal.
                Array whose index ranges within [0..Min(M,N)-1].
    E       -   the secondary diagonal (upper or lower, depending on
                the value of IsUpper).
                Array index ranges within [0..Min(M,N)-1], the last
                element is not used.

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixbdunpackdiagonals(/* Real    */ ae_matrix* b,
     ae_int_t m,
     ae_int_t n,
     ae_bool* isupper,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_state *_state)
{
    ae_int_t i;

    *isupper = ae_false;
    ae_vector_clear(d);
    ae_vector_clear(e);

    *isupper = m>=n;
    if( m<=0||n<=0 )
    {
        return;
    }
    if( *isupper )
    {
        ae_vector_set_length(d, n, _state);
        ae_vector_set_length(e, n, _state);
        for(i=0; i<=n-2; i++)
        {
            d->ptr.p_double[i] = b->ptr.pp_double[i][i];
            e->ptr.p_double[i] = b->ptr.pp_double[i][i+1];
        }
        d->ptr.p_double[n-1] = b->ptr.pp_double[n-1][n-1];
    }
    else
    {
        ae_vector_set_length(d, m, _state);
        ae_vector_set_length(e, m, _state);
        for(i=0; i<=m-2; i++)
        {
            d->ptr.p_double[i] = b->ptr.pp_double[i][i];
            e->ptr.p_double[i] = b->ptr.pp_double[i+1][i];
        }
        d->ptr.p_double[m-1] = b->ptr.pp_double[m-1][m-1];
    }
}


/*************************************************************************
Reduction of a square matrix to  upper Hessenberg form: Q'*A*Q = H,
where Q is an orthogonal matrix, H - Hessenberg matrix.

Input parameters:
    A       -   matrix A with elements [0..N-1, 0..N-1]
    N       -   size of matrix A.

Output parameters:
    A       -   matrices Q and P in  compact form (see below).
    Tau     -   array of scalar factors which are used to form matrix Q.
                Array whose index ranges within [0..N-2]

Matrix H is located on the main diagonal, on the lower secondary  diagonal
and above the main diagonal of matrix A. The elements which are used to
form matrix Q are situated in array Tau and below the lower secondary
diagonal of matrix A as follows:

Matrix Q is represented as a product of elementary reflections

Q = H(0)*H(2)*...*H(n-2),

where each H(i) is given by

H(i) = 1 - tau * v * (v^T)

where tau is a scalar stored in Tau[I]; v - is a real vector,
so that v(0:i) = 0, v(i+1) = 1, v(i+2:n-1) stored in A(i+2:n-1,i).

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
void rmatrixhessenberg(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    double v;
    ae_vector t;
    ae_vector work;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    ae_assert(n>=0, "RMatrixHessenberg: incorrect N!", _state);
    
    /*
     * Quick return if possible
     */
    if( n<=1 )
    {
        ae_frame_leave(_state);
        return;
    }
    ae_vector_set_length(tau, n-2+1, _state);
    ae_vector_set_length(&t, n+1, _state);
    ae_vector_set_length(&work, n-1+1, _state);
    for(i=0; i<=n-2; i++)
    {
        
        /*
         * Compute elementary reflector H(i) to annihilate A(i+2:ihi,i)
         */
        ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(1,n-i-1));
        generatereflection(&t, n-i-1, &v, _state);
        ae_v_move(&a->ptr.pp_double[i+1][i], a->stride, &t.ptr.p_double[1], 1, ae_v_len(i+1,n-1));
        tau->ptr.p_double[i] = v;
        t.ptr.p_double[1] = 1;
        
        /*
         * Apply H(i) to A(1:ihi,i+1:ihi) from the right
         */
        applyreflectionfromtheright(a, v, &t, 0, n-1, i+1, n-1, &work, _state);
        
        /*
         * Apply H(i) to A(i+1:ihi,i+1:n) from the left
         */
        applyreflectionfromtheleft(a, v, &t, i+1, n-1, i+1, n-1, &work, _state);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking matrix Q which reduces matrix A to upper Hessenberg form

Input parameters:
    A   -   output of RMatrixHessenberg subroutine.
    N   -   size of matrix A.
    Tau -   scalar factors which are used to form Q.
            Output of RMatrixHessenberg subroutine.

Output parameters:
    Q   -   matrix Q.
            Array whose indexes range within [0..N-1, 0..N-1].

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixhessenbergunpackq(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector v;
    ae_vector work;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    if( n==0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * init
     */
    ae_matrix_set_length(q, n-1+1, n-1+1, _state);
    ae_vector_set_length(&v, n-1+1, _state);
    ae_vector_set_length(&work, n-1+1, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_double[i][j] = 1;
            }
            else
            {
                q->ptr.pp_double[i][j] = 0;
            }
        }
    }
    
    /*
     * unpack Q
     */
    for(i=0; i<=n-2; i++)
    {
        
        /*
         * Apply H(i)
         */
        ae_v_move(&v.ptr.p_double[1], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(1,n-i-1));
        v.ptr.p_double[1] = 1;
        applyreflectionfromtheright(q, tau->ptr.p_double[i], &v, 0, n-1, i+1, n-1, &work, _state);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking matrix H (the result of matrix A reduction to upper Hessenberg form)

Input parameters:
    A   -   output of RMatrixHessenberg subroutine.
    N   -   size of matrix A.

Output parameters:
    H   -   matrix H. Array whose indexes range within [0..N-1, 0..N-1].

  -- ALGLIB --
     2005-2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixhessenbergunpackh(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_matrix* h,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector v;
    ae_vector work;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(h);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    if( n==0 )
    {
        ae_frame_leave(_state);
        return;
    }
    ae_matrix_set_length(h, n-1+1, n-1+1, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=i-2; j++)
        {
            h->ptr.pp_double[i][j] = 0;
        }
        j = ae_maxint(0, i-1, _state);
        ae_v_move(&h->ptr.pp_double[i][j], 1, &a->ptr.pp_double[i][j], 1, ae_v_len(j,n-1));
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Reduction of a symmetric matrix which is given by its higher or lower
triangular part to a tridiagonal matrix using orthogonal similarity
transformation: Q'*A*Q=T.

Input parameters:
    A       -   matrix to be transformed
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format. If IsUpper = True, then matrix A is given
                by its upper triangle, and the lower triangle is not used
                and not modified by the algorithm, and vice versa
                if IsUpper = False.

Output parameters:
    A       -   matrices T and Q in  compact form (see lower)
    Tau     -   array of factors which are forming matrices H(i)
                array with elements [0..N-2].
    D       -   main diagonal of symmetric matrix T.
                array with elements [0..N-1].
    E       -   secondary diagonal of symmetric matrix T.
                array with elements [0..N-2].


  If IsUpper=True, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(n-2) . . . H(2) H(0).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a real scalar, and v is a real vector with
  v(i+1:n-1) = 0, v(i) = 1, v(0:i-1) is stored on exit in
  A(0:i-1,i+1), and tau in TAU(i).

  If IsUpper=False, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(0) H(2) . . . H(n-2).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a real scalar, and v is a real vector with
  v(0:i) = 0, v(i+1) = 1, v(i+2:n-1) is stored on exit in A(i+2:n-1,i),
  and tau in TAU(i).

  The contents of A on exit are illustrated by the following examples
  with n = 5:

  if UPLO = 'U':                       if UPLO = 'L':

    (  d   e   v1  v2  v3 )              (  d                  )
    (      d   e   v2  v3 )              (  e   d              )
    (          d   e   v3 )              (  v0  e   d          )
    (              d   e  )              (  v0  v1  e   d      )
    (                  d  )              (  v0  v1  v2  e   d  )

  where d and e denote diagonal and off-diagonal elements of T, and vi
  denotes an element of the vector defining H(i).

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
void smatrixtd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    double alpha;
    double taui;
    double v;
    ae_vector t;
    ae_vector t2;
    ae_vector t3;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_clear(d);
    ae_vector_clear(e);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t2, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t3, 0, DT_REAL, _state, ae_true);

    if( n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    ae_vector_set_length(&t, n+1, _state);
    ae_vector_set_length(&t2, n+1, _state);
    ae_vector_set_length(&t3, n+1, _state);
    if( n>1 )
    {
        ae_vector_set_length(tau, n-2+1, _state);
    }
    ae_vector_set_length(d, n-1+1, _state);
    if( n>1 )
    {
        ae_vector_set_length(e, n-2+1, _state);
    }
    if( isupper )
    {
        
        /*
         * Reduce the upper triangle of A
         */
        for(i=n-2; i>=0; i--)
        {
            
            /*
             * Generate elementary reflector H() = E - tau * v * v'
             */
            if( i>=1 )
            {
                ae_v_move(&t.ptr.p_double[2], 1, &a->ptr.pp_double[0][i+1], a->stride, ae_v_len(2,i+1));
            }
            t.ptr.p_double[1] = a->ptr.pp_double[i][i+1];
            generatereflection(&t, i+1, &taui, _state);
            if( i>=1 )
            {
                ae_v_move(&a->ptr.pp_double[0][i+1], a->stride, &t.ptr.p_double[2], 1, ae_v_len(0,i-1));
            }
            a->ptr.pp_double[i][i+1] = t.ptr.p_double[1];
            e->ptr.p_double[i] = a->ptr.pp_double[i][i+1];
            if( ae_fp_neq(taui,0) )
            {
                
                /*
                 * Apply H from both sides to A
                 */
                a->ptr.pp_double[i][i+1] = 1;
                
                /*
                 * Compute  x := tau * A * v  storing x in TAU
                 */
                ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[0][i+1], a->stride, ae_v_len(1,i+1));
                symmetricmatrixvectormultiply(a, isupper, 0, i, &t, taui, &t3, _state);
                ae_v_move(&tau->ptr.p_double[0], 1, &t3.ptr.p_double[1], 1, ae_v_len(0,i));
                
                /*
                 * Compute  w := x - 1/2 * tau * (x'*v) * v
                 */
                v = ae_v_dotproduct(&tau->ptr.p_double[0], 1, &a->ptr.pp_double[0][i+1], a->stride, ae_v_len(0,i));
                alpha = -0.5*taui*v;
                ae_v_addd(&tau->ptr.p_double[0], 1, &a->ptr.pp_double[0][i+1], a->stride, ae_v_len(0,i), alpha);
                
                /*
                 * Apply the transformation as a rank-2 update:
                 *    A := A - v * w' - w * v'
                 */
                ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[0][i+1], a->stride, ae_v_len(1,i+1));
                ae_v_move(&t3.ptr.p_double[1], 1, &tau->ptr.p_double[0], 1, ae_v_len(1,i+1));
                symmetricrank2update(a, isupper, 0, i, &t, &t3, &t2, -1, _state);
                a->ptr.pp_double[i][i+1] = e->ptr.p_double[i];
            }
            d->ptr.p_double[i+1] = a->ptr.pp_double[i+1][i+1];
            tau->ptr.p_double[i] = taui;
        }
        d->ptr.p_double[0] = a->ptr.pp_double[0][0];
    }
    else
    {
        
        /*
         * Reduce the lower triangle of A
         */
        for(i=0; i<=n-2; i++)
        {
            
            /*
             * Generate elementary reflector H = E - tau * v * v'
             */
            ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(1,n-i-1));
            generatereflection(&t, n-i-1, &taui, _state);
            ae_v_move(&a->ptr.pp_double[i+1][i], a->stride, &t.ptr.p_double[1], 1, ae_v_len(i+1,n-1));
            e->ptr.p_double[i] = a->ptr.pp_double[i+1][i];
            if( ae_fp_neq(taui,0) )
            {
                
                /*
                 * Apply H from both sides to A
                 */
                a->ptr.pp_double[i+1][i] = 1;
                
                /*
                 * Compute  x := tau * A * v  storing y in TAU
                 */
                ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(1,n-i-1));
                symmetricmatrixvectormultiply(a, isupper, i+1, n-1, &t, taui, &t2, _state);
                ae_v_move(&tau->ptr.p_double[i], 1, &t2.ptr.p_double[1], 1, ae_v_len(i,n-2));
                
                /*
                 * Compute  w := x - 1/2 * tau * (x'*v) * v
                 */
                v = ae_v_dotproduct(&tau->ptr.p_double[i], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(i,n-2));
                alpha = -0.5*taui*v;
                ae_v_addd(&tau->ptr.p_double[i], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(i,n-2), alpha);
                
                /*
                 * Apply the transformation as a rank-2 update:
                 *     A := A - v * w' - w * v'
                 *
                 */
                ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(1,n-i-1));
                ae_v_move(&t2.ptr.p_double[1], 1, &tau->ptr.p_double[i], 1, ae_v_len(1,n-i-1));
                symmetricrank2update(a, isupper, i+1, n-1, &t, &t2, &t3, -1, _state);
                a->ptr.pp_double[i+1][i] = e->ptr.p_double[i];
            }
            d->ptr.p_double[i] = a->ptr.pp_double[i][i];
            tau->ptr.p_double[i] = taui;
        }
        d->ptr.p_double[n-1] = a->ptr.pp_double[n-1][n-1];
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking matrix Q which reduces symmetric matrix to a tridiagonal
form.

Input parameters:
    A       -   the result of a SMatrixTD subroutine
    N       -   size of matrix A.
    IsUpper -   storage format (a parameter of SMatrixTD subroutine)
    Tau     -   the result of a SMatrixTD subroutine

Output parameters:
    Q       -   transformation matrix.
                array with elements [0..N-1, 0..N-1].

  -- ALGLIB --
     Copyright 2005-2010 by Bochkanov Sergey
*************************************************************************/
void smatrixtdunpackq(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector v;
    ae_vector work;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    if( n==0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * init
     */
    ae_matrix_set_length(q, n-1+1, n-1+1, _state);
    ae_vector_set_length(&v, n+1, _state);
    ae_vector_set_length(&work, n-1+1, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_double[i][j] = 1;
            }
            else
            {
                q->ptr.pp_double[i][j] = 0;
            }
        }
    }
    
    /*
     * unpack Q
     */
    if( isupper )
    {
        for(i=0; i<=n-2; i++)
        {
            
            /*
             * Apply H(i)
             */
            ae_v_move(&v.ptr.p_double[1], 1, &a->ptr.pp_double[0][i+1], a->stride, ae_v_len(1,i+1));
            v.ptr.p_double[i+1] = 1;
            applyreflectionfromtheleft(q, tau->ptr.p_double[i], &v, 0, i, 0, n-1, &work, _state);
        }
    }
    else
    {
        for(i=n-2; i>=0; i--)
        {
            
            /*
             * Apply H(i)
             */
            ae_v_move(&v.ptr.p_double[1], 1, &a->ptr.pp_double[i+1][i], a->stride, ae_v_len(1,n-i-1));
            v.ptr.p_double[1] = 1;
            applyreflectionfromtheleft(q, tau->ptr.p_double[i], &v, i+1, n-1, 0, n-1, &work, _state);
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Reduction of a Hermitian matrix which is given  by  its  higher  or  lower
triangular part to a real  tridiagonal  matrix  using  unitary  similarity
transformation: Q'*A*Q = T.

Input parameters:
    A       -   matrix to be transformed
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format. If IsUpper = True, then matrix A is  given
                by its upper triangle, and the lower triangle is not  used
                and not modified by the algorithm, and vice versa
                if IsUpper = False.

Output parameters:
    A       -   matrices T and Q in  compact form (see lower)
    Tau     -   array of factors which are forming matrices H(i)
                array with elements [0..N-2].
    D       -   main diagonal of real symmetric matrix T.
                array with elements [0..N-1].
    E       -   secondary diagonal of real symmetric matrix T.
                array with elements [0..N-2].


  If IsUpper=True, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(n-2) . . . H(2) H(0).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a complex scalar, and v is a complex vector with
  v(i+1:n-1) = 0, v(i) = 1, v(0:i-1) is stored on exit in
  A(0:i-1,i+1), and tau in TAU(i).

  If IsUpper=False, the matrix Q is represented as a product of elementary
  reflectors

     Q = H(0) H(2) . . . H(n-2).

  Each H(i) has the form

     H(i) = I - tau * v * v'

  where tau is a complex scalar, and v is a complex vector with
  v(0:i) = 0, v(i+1) = 1, v(i+2:n-1) is stored on exit in A(i+2:n-1,i),
  and tau in TAU(i).

  The contents of A on exit are illustrated by the following examples
  with n = 5:

  if UPLO = 'U':                       if UPLO = 'L':

    (  d   e   v1  v2  v3 )              (  d                  )
    (      d   e   v2  v3 )              (  e   d              )
    (          d   e   v3 )              (  v0  e   d          )
    (              d   e  )              (  v0  v1  e   d      )
    (                  d  )              (  v0  v1  v2  e   d  )

where d and e denote diagonal and off-diagonal elements of T, and vi
denotes an element of the vector defining H(i).

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
void hmatrixtd(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tau,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_complex alpha;
    ae_complex taui;
    ae_complex v;
    ae_vector t;
    ae_vector t2;
    ae_vector t3;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_clear(d);
    ae_vector_clear(e);
    ae_vector_init(&t, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&t2, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&t3, 0, DT_COMPLEX, _state, ae_true);

    if( n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    for(i=0; i<=n-1; i++)
    {
        ae_assert(ae_fp_eq(a->ptr.pp_complex[i][i].y,0), "Assertion failed", _state);
    }
    if( n>1 )
    {
        ae_vector_set_length(tau, n-2+1, _state);
        ae_vector_set_length(e, n-2+1, _state);
    }
    ae_vector_set_length(d, n-1+1, _state);
    ae_vector_set_length(&t, n-1+1, _state);
    ae_vector_set_length(&t2, n-1+1, _state);
    ae_vector_set_length(&t3, n-1+1, _state);
    if( isupper )
    {
        
        /*
         * Reduce the upper triangle of A
         */
        a->ptr.pp_complex[n-1][n-1] = ae_complex_from_d(a->ptr.pp_complex[n-1][n-1].x);
        for(i=n-2; i>=0; i--)
        {
            
            /*
             * Generate elementary reflector H = I+1 - tau * v * v'
             */
            alpha = a->ptr.pp_complex[i][i+1];
            t.ptr.p_complex[1] = alpha;
            if( i>=1 )
            {
                ae_v_cmove(&t.ptr.p_complex[2], 1, &a->ptr.pp_complex[0][i+1], a->stride, "N", ae_v_len(2,i+1));
            }
            complexgeneratereflection(&t, i+1, &taui, _state);
            if( i>=1 )
            {
                ae_v_cmove(&a->ptr.pp_complex[0][i+1], a->stride, &t.ptr.p_complex[2], 1, "N", ae_v_len(0,i-1));
            }
            alpha = t.ptr.p_complex[1];
            e->ptr.p_double[i] = alpha.x;
            if( ae_c_neq_d(taui,0) )
            {
                
                /*
                 * Apply H(I+1) from both sides to A
                 */
                a->ptr.pp_complex[i][i+1] = ae_complex_from_d(1);
                
                /*
                 * Compute  x := tau * A * v  storing x in TAU
                 */
                ae_v_cmove(&t.ptr.p_complex[1], 1, &a->ptr.pp_complex[0][i+1], a->stride, "N", ae_v_len(1,i+1));
                hermitianmatrixvectormultiply(a, isupper, 0, i, &t, taui, &t2, _state);
                ae_v_cmove(&tau->ptr.p_complex[0], 1, &t2.ptr.p_complex[1], 1, "N", ae_v_len(0,i));
                
                /*
                 * Compute  w := x - 1/2 * tau * (x'*v) * v
                 */
                v = ae_v_cdotproduct(&tau->ptr.p_complex[0], 1, "Conj", &a->ptr.pp_complex[0][i+1], a->stride, "N", ae_v_len(0,i));
                alpha = ae_c_neg(ae_c_mul(ae_c_mul_d(taui,0.5),v));
                ae_v_caddc(&tau->ptr.p_complex[0], 1, &a->ptr.pp_complex[0][i+1], a->stride, "N", ae_v_len(0,i), alpha);
                
                /*
                 * Apply the transformation as a rank-2 update:
                 *    A := A - v * w' - w * v'
                 */
                ae_v_cmove(&t.ptr.p_complex[1], 1, &a->ptr.pp_complex[0][i+1], a->stride, "N", ae_v_len(1,i+1));
                ae_v_cmove(&t3.ptr.p_complex[1], 1, &tau->ptr.p_complex[0], 1, "N", ae_v_len(1,i+1));
                hermitianrank2update(a, isupper, 0, i, &t, &t3, &t2, ae_complex_from_d(-1), _state);
            }
            else
            {
                a->ptr.pp_complex[i][i] = ae_complex_from_d(a->ptr.pp_complex[i][i].x);
            }
            a->ptr.pp_complex[i][i+1] = ae_complex_from_d(e->ptr.p_double[i]);
            d->ptr.p_double[i+1] = a->ptr.pp_complex[i+1][i+1].x;
            tau->ptr.p_complex[i] = taui;
        }
        d->ptr.p_double[0] = a->ptr.pp_complex[0][0].x;
    }
    else
    {
        
        /*
         * Reduce the lower triangle of A
         */
        a->ptr.pp_complex[0][0] = ae_complex_from_d(a->ptr.pp_complex[0][0].x);
        for(i=0; i<=n-2; i++)
        {
            
            /*
             * Generate elementary reflector H = I - tau * v * v'
             */
            ae_v_cmove(&t.ptr.p_complex[1], 1, &a->ptr.pp_complex[i+1][i], a->stride, "N", ae_v_len(1,n-i-1));
            complexgeneratereflection(&t, n-i-1, &taui, _state);
            ae_v_cmove(&a->ptr.pp_complex[i+1][i], a->stride, &t.ptr.p_complex[1], 1, "N", ae_v_len(i+1,n-1));
            e->ptr.p_double[i] = a->ptr.pp_complex[i+1][i].x;
            if( ae_c_neq_d(taui,0) )
            {
                
                /*
                 * Apply H(i) from both sides to A(i+1:n,i+1:n)
                 */
                a->ptr.pp_complex[i+1][i] = ae_complex_from_d(1);
                
                /*
                 * Compute  x := tau * A * v  storing y in TAU
                 */
                ae_v_cmove(&t.ptr.p_complex[1], 1, &a->ptr.pp_complex[i+1][i], a->stride, "N", ae_v_len(1,n-i-1));
                hermitianmatrixvectormultiply(a, isupper, i+1, n-1, &t, taui, &t2, _state);
                ae_v_cmove(&tau->ptr.p_complex[i], 1, &t2.ptr.p_complex[1], 1, "N", ae_v_len(i,n-2));
                
                /*
                 * Compute  w := x - 1/2 * tau * (x'*v) * v
                 */
                v = ae_v_cdotproduct(&tau->ptr.p_complex[i], 1, "Conj", &a->ptr.pp_complex[i+1][i], a->stride, "N", ae_v_len(i,n-2));
                alpha = ae_c_neg(ae_c_mul(ae_c_mul_d(taui,0.5),v));
                ae_v_caddc(&tau->ptr.p_complex[i], 1, &a->ptr.pp_complex[i+1][i], a->stride, "N", ae_v_len(i,n-2), alpha);
                
                /*
                 * Apply the transformation as a rank-2 update:
                 * A := A - v * w' - w * v'
                 */
                ae_v_cmove(&t.ptr.p_complex[1], 1, &a->ptr.pp_complex[i+1][i], a->stride, "N", ae_v_len(1,n-i-1));
                ae_v_cmove(&t2.ptr.p_complex[1], 1, &tau->ptr.p_complex[i], 1, "N", ae_v_len(1,n-i-1));
                hermitianrank2update(a, isupper, i+1, n-1, &t, &t2, &t3, ae_complex_from_d(-1), _state);
            }
            else
            {
                a->ptr.pp_complex[i+1][i+1] = ae_complex_from_d(a->ptr.pp_complex[i+1][i+1].x);
            }
            a->ptr.pp_complex[i+1][i] = ae_complex_from_d(e->ptr.p_double[i]);
            d->ptr.p_double[i] = a->ptr.pp_complex[i][i].x;
            tau->ptr.p_complex[i] = taui;
        }
        d->ptr.p_double[n-1] = a->ptr.pp_complex[n-1][n-1].x;
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Unpacking matrix Q which reduces a Hermitian matrix to a real  tridiagonal
form.

Input parameters:
    A       -   the result of a HMatrixTD subroutine
    N       -   size of matrix A.
    IsUpper -   storage format (a parameter of HMatrixTD subroutine)
    Tau     -   the result of a HMatrixTD subroutine

Output parameters:
    Q       -   transformation matrix.
                array with elements [0..N-1, 0..N-1].

  -- ALGLIB --
     Copyright 2005-2010 by Bochkanov Sergey
*************************************************************************/
void hmatrixtdunpackq(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tau,
     /* Complex */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector v;
    ae_vector work;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&v, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&work, 0, DT_COMPLEX, _state, ae_true);

    if( n==0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * init
     */
    ae_matrix_set_length(q, n-1+1, n-1+1, _state);
    ae_vector_set_length(&v, n+1, _state);
    ae_vector_set_length(&work, n-1+1, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                q->ptr.pp_complex[i][j] = ae_complex_from_d(1);
            }
            else
            {
                q->ptr.pp_complex[i][j] = ae_complex_from_d(0);
            }
        }
    }
    
    /*
     * unpack Q
     */
    if( isupper )
    {
        for(i=0; i<=n-2; i++)
        {
            
            /*
             * Apply H(i)
             */
            ae_v_cmove(&v.ptr.p_complex[1], 1, &a->ptr.pp_complex[0][i+1], a->stride, "N", ae_v_len(1,i+1));
            v.ptr.p_complex[i+1] = ae_complex_from_d(1);
            complexapplyreflectionfromtheleft(q, tau->ptr.p_complex[i], &v, 0, i, 0, n-1, &work, _state);
        }
    }
    else
    {
        for(i=n-2; i>=0; i--)
        {
            
            /*
             * Apply H(i)
             */
            ae_v_cmove(&v.ptr.p_complex[1], 1, &a->ptr.pp_complex[i+1][i], a->stride, "N", ae_v_len(1,n-i-1));
            v.ptr.p_complex[1] = ae_complex_from_d(1);
            complexapplyreflectionfromtheleft(q, tau->ptr.p_complex[i], &v, i+1, n-1, 0, n-1, &work, _state);
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Base case for real QR

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994.
     Sergey Bochkanov, ALGLIB project, translation from FORTRAN to
     pseudocode, 2007-2010.
*************************************************************************/
static void ortfac_rmatrixqrbasecase(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* work,
     /* Real    */ ae_vector* t,
     /* Real    */ ae_vector* tau,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;
    ae_int_t minmn;
    double tmp;


    minmn = ae_minint(m, n, _state);
    
    /*
     * Test the input arguments
     */
    k = minmn;
    for(i=0; i<=k-1; i++)
    {
        
        /*
         * Generate elementary reflector H(i) to annihilate A(i+1:m,i)
         */
        ae_v_move(&t->ptr.p_double[1], 1, &a->ptr.pp_double[i][i], a->stride, ae_v_len(1,m-i));
        generatereflection(t, m-i, &tmp, _state);
        tau->ptr.p_double[i] = tmp;
        ae_v_move(&a->ptr.pp_double[i][i], a->stride, &t->ptr.p_double[1], 1, ae_v_len(i,m-1));
        t->ptr.p_double[1] = 1;
        if( i<n )
        {
            
            /*
             * Apply H(i) to A(i:m-1,i+1:n-1) from the left
             */
            applyreflectionfromtheleft(a, tau->ptr.p_double[i], t, i, m-1, i+1, n-1, work, _state);
        }
    }
}


/*************************************************************************
Base case for real LQ

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994.
     Sergey Bochkanov, ALGLIB project, translation from FORTRAN to
     pseudocode, 2007-2010.
*************************************************************************/
static void ortfac_rmatrixlqbasecase(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* work,
     /* Real    */ ae_vector* t,
     /* Real    */ ae_vector* tau,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;
    ae_int_t minmn;
    double tmp;


    minmn = ae_minint(m, n, _state);
    k = ae_minint(m, n, _state);
    for(i=0; i<=k-1; i++)
    {
        
        /*
         * Generate elementary reflector H(i) to annihilate A(i,i+1:n-1)
         */
        ae_v_move(&t->ptr.p_double[1], 1, &a->ptr.pp_double[i][i], 1, ae_v_len(1,n-i));
        generatereflection(t, n-i, &tmp, _state);
        tau->ptr.p_double[i] = tmp;
        ae_v_move(&a->ptr.pp_double[i][i], 1, &t->ptr.p_double[1], 1, ae_v_len(i,n-1));
        t->ptr.p_double[1] = 1;
        if( i<n )
        {
            
            /*
             * Apply H(i) to A(i+1:m,i:n) from the right
             */
            applyreflectionfromtheright(a, tau->ptr.p_double[i], t, i+1, m-1, i, n-1, work, _state);
        }
    }
}


/*************************************************************************
Base case for complex QR

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994.
     Sergey Bochkanov, ALGLIB project, translation from FORTRAN to
     pseudocode, 2007-2010.
*************************************************************************/
static void ortfac_cmatrixqrbasecase(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* work,
     /* Complex */ ae_vector* t,
     /* Complex */ ae_vector* tau,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;
    ae_int_t mmi;
    ae_int_t minmn;
    ae_complex tmp;


    minmn = ae_minint(m, n, _state);
    if( minmn<=0 )
    {
        return;
    }
    
    /*
     * Test the input arguments
     */
    k = ae_minint(m, n, _state);
    for(i=0; i<=k-1; i++)
    {
        
        /*
         * Generate elementary reflector H(i) to annihilate A(i+1:m,i)
         */
        mmi = m-i;
        ae_v_cmove(&t->ptr.p_complex[1], 1, &a->ptr.pp_complex[i][i], a->stride, "N", ae_v_len(1,mmi));
        complexgeneratereflection(t, mmi, &tmp, _state);
        tau->ptr.p_complex[i] = tmp;
        ae_v_cmove(&a->ptr.pp_complex[i][i], a->stride, &t->ptr.p_complex[1], 1, "N", ae_v_len(i,m-1));
        t->ptr.p_complex[1] = ae_complex_from_d(1);
        if( i<n-1 )
        {
            
            /*
             * Apply H'(i) to A(i:m,i+1:n) from the left
             */
            complexapplyreflectionfromtheleft(a, ae_c_conj(tau->ptr.p_complex[i], _state), t, i, m-1, i+1, n-1, work, _state);
        }
    }
}


/*************************************************************************
Base case for complex LQ

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994.
     Sergey Bochkanov, ALGLIB project, translation from FORTRAN to
     pseudocode, 2007-2010.
*************************************************************************/
static void ortfac_cmatrixlqbasecase(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* work,
     /* Complex */ ae_vector* t,
     /* Complex */ ae_vector* tau,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t minmn;
    ae_complex tmp;


    minmn = ae_minint(m, n, _state);
    if( minmn<=0 )
    {
        return;
    }
    
    /*
     * Test the input arguments
     */
    for(i=0; i<=minmn-1; i++)
    {
        
        /*
         * Generate elementary reflector H(i)
         *
         * NOTE: ComplexGenerateReflection() generates left reflector,
         * i.e. H which reduces x by applyiong from the left, but we
         * need RIGHT reflector. So we replace H=E-tau*v*v' by H^H,
         * which changes v to conj(v).
         */
        ae_v_cmove(&t->ptr.p_complex[1], 1, &a->ptr.pp_complex[i][i], 1, "Conj", ae_v_len(1,n-i));
        complexgeneratereflection(t, n-i, &tmp, _state);
        tau->ptr.p_complex[i] = tmp;
        ae_v_cmove(&a->ptr.pp_complex[i][i], 1, &t->ptr.p_complex[1], 1, "Conj", ae_v_len(i,n-1));
        t->ptr.p_complex[1] = ae_complex_from_d(1);
        if( i<m-1 )
        {
            
            /*
             * Apply H'(i)
             */
            complexapplyreflectionfromtheright(a, tau->ptr.p_complex[i], t, i+1, m-1, i, n-1, work, _state);
        }
    }
}


/*************************************************************************
Generate block reflector:
* fill unused parts of reflectors matrix by zeros
* fill diagonal of reflectors matrix by ones
* generate triangular factor T

PARAMETERS:
    A           -   either LengthA*BlockSize (if ColumnwiseA) or
                    BlockSize*LengthA (if not ColumnwiseA) matrix of
                    elementary reflectors.
                    Modified on exit.
    Tau         -   scalar factors
    ColumnwiseA -   reflectors are stored in rows or in columns
    LengthA     -   length of largest reflector
    BlockSize   -   number of reflectors
    T           -   array[BlockSize,2*BlockSize]. Left BlockSize*BlockSize
                    submatrix stores triangular factor on exit.
    WORK        -   array[BlockSize]
    
  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
static void ortfac_rmatrixblockreflector(/* Real    */ ae_matrix* a,
     /* Real    */ ae_vector* tau,
     ae_bool columnwisea,
     ae_int_t lengtha,
     ae_int_t blocksize,
     /* Real    */ ae_matrix* t,
     /* Real    */ ae_vector* work,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_int_t k;
    double v;


    
    /*
     * fill beginning of new column with zeros,
     * load 1.0 in the first non-zero element
     */
    for(k=0; k<=blocksize-1; k++)
    {
        if( columnwisea )
        {
            for(i=0; i<=k-1; i++)
            {
                a->ptr.pp_double[i][k] = 0;
            }
        }
        else
        {
            for(i=0; i<=k-1; i++)
            {
                a->ptr.pp_double[k][i] = 0;
            }
        }
        a->ptr.pp_double[k][k] = 1;
    }
    
    /*
     * Calculate Gram matrix of A
     */
    for(i=0; i<=blocksize-1; i++)
    {
        for(j=0; j<=blocksize-1; j++)
        {
            t->ptr.pp_double[i][blocksize+j] = 0;
        }
    }
    for(k=0; k<=lengtha-1; k++)
    {
        for(j=1; j<=blocksize-1; j++)
        {
            if( columnwisea )
            {
                v = a->ptr.pp_double[k][j];
                if( ae_fp_neq(v,0) )
                {
                    ae_v_addd(&t->ptr.pp_double[j][blocksize], 1, &a->ptr.pp_double[k][0], 1, ae_v_len(blocksize,blocksize+j-1), v);
                }
            }
            else
            {
                v = a->ptr.pp_double[j][k];
                if( ae_fp_neq(v,0) )
                {
                    ae_v_addd(&t->ptr.pp_double[j][blocksize], 1, &a->ptr.pp_double[0][k], a->stride, ae_v_len(blocksize,blocksize+j-1), v);
                }
            }
        }
    }
    
    /*
     * Prepare Y (stored in TmpA) and T (stored in TmpT)
     */
    for(k=0; k<=blocksize-1; k++)
    {
        
        /*
         * fill non-zero part of T, use pre-calculated Gram matrix
         */
        ae_v_move(&work->ptr.p_double[0], 1, &t->ptr.pp_double[k][blocksize], 1, ae_v_len(0,k-1));
        for(i=0; i<=k-1; i++)
        {
            v = ae_v_dotproduct(&t->ptr.pp_double[i][i], 1, &work->ptr.p_double[i], 1, ae_v_len(i,k-1));
            t->ptr.pp_double[i][k] = -tau->ptr.p_double[k]*v;
        }
        t->ptr.pp_double[k][k] = -tau->ptr.p_double[k];
        
        /*
         * Rest of T is filled by zeros
         */
        for(i=k+1; i<=blocksize-1; i++)
        {
            t->ptr.pp_double[i][k] = 0;
        }
    }
}


/*************************************************************************
Generate block reflector (complex):
* fill unused parts of reflectors matrix by zeros
* fill diagonal of reflectors matrix by ones
* generate triangular factor T


  -- ALGLIB routine --
     17.02.2010
     Bochkanov Sergey
*************************************************************************/
static void ortfac_cmatrixblockreflector(/* Complex */ ae_matrix* a,
     /* Complex */ ae_vector* tau,
     ae_bool columnwisea,
     ae_int_t lengtha,
     ae_int_t blocksize,
     /* Complex */ ae_matrix* t,
     /* Complex */ ae_vector* work,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t k;
    ae_complex v;


    
    /*
     * Prepare Y (stored in TmpA) and T (stored in TmpT)
     */
    for(k=0; k<=blocksize-1; k++)
    {
        
        /*
         * fill beginning of new column with zeros,
         * load 1.0 in the first non-zero element
         */
        if( columnwisea )
        {
            for(i=0; i<=k-1; i++)
            {
                a->ptr.pp_complex[i][k] = ae_complex_from_d(0);
            }
        }
        else
        {
            for(i=0; i<=k-1; i++)
            {
                a->ptr.pp_complex[k][i] = ae_complex_from_d(0);
            }
        }
        a->ptr.pp_complex[k][k] = ae_complex_from_d(1);
        
        /*
         * fill non-zero part of T,
         */
        for(i=0; i<=k-1; i++)
        {
            if( columnwisea )
            {
                v = ae_v_cdotproduct(&a->ptr.pp_complex[k][i], a->stride, "Conj", &a->ptr.pp_complex[k][k], a->stride, "N", ae_v_len(k,lengtha-1));
            }
            else
            {
                v = ae_v_cdotproduct(&a->ptr.pp_complex[i][k], 1, "N", &a->ptr.pp_complex[k][k], 1, "Conj", ae_v_len(k,lengtha-1));
            }
            work->ptr.p_complex[i] = v;
        }
        for(i=0; i<=k-1; i++)
        {
            v = ae_v_cdotproduct(&t->ptr.pp_complex[i][i], 1, "N", &work->ptr.p_complex[i], 1, "N", ae_v_len(i,k-1));
            t->ptr.pp_complex[i][k] = ae_c_neg(ae_c_mul(tau->ptr.p_complex[k],v));
        }
        t->ptr.pp_complex[k][k] = ae_c_neg(tau->ptr.p_complex[k]);
        
        /*
         * Rest of T is filled by zeros
         */
        for(i=k+1; i<=blocksize-1; i++)
        {
            t->ptr.pp_complex[i][k] = ae_complex_from_d(0);
        }
    }
}




/*************************************************************************
Finding the eigenvalues and eigenvectors of a symmetric matrix

The algorithm finds eigen pairs of a symmetric matrix by reducing it to
tridiagonal form and using the QL/QR algorithm.

Input parameters:
    A       -   symmetric matrix which is given by its upper or lower
                triangular part.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpper -   storage format.

Output parameters:
    D       -   eigenvalues in ascending order.
                Array whose index ranges within [0..N-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains the eigenvectors.
                Array whose indexes range within [0..N-1, 0..N-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged (rare case).

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
ae_bool smatrixevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_vector tau;
    ae_vector e;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(d);
    ae_matrix_clear(z);
    ae_vector_init(&tau, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e, 0, DT_REAL, _state, ae_true);

    ae_assert(zneeded==0||zneeded==1, "SMatrixEVD: incorrect ZNeeded", _state);
    smatrixtd(a, n, isupper, &tau, d, &e, _state);
    if( zneeded==1 )
    {
        smatrixtdunpackq(a, n, isupper, &tau, z, _state);
    }
    result = smatrixtdevd(d, &e, n, zneeded, z, _state);
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Subroutine for finding the eigenvalues (and eigenvectors) of  a  symmetric
matrix  in  a  given half open interval (A, B] by using  a  bisection  and
inverse iteration

Input parameters:
    A       -   symmetric matrix which is given by its upper or lower
                triangular part. Array [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    B1, B2 -    half open interval (B1, B2] to search eigenvalues in.

Output parameters:
    M       -   number of eigenvalues found in a given half-interval (M>=0).
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..M-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..M-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if successful. M contains the number of eigenvalues in the given
    half-interval (could be equal to 0), W contains the eigenvalues,
    Z contains the eigenvectors (if needed).

    False, if the bisection method subroutine wasn't able to find the
    eigenvalues in the given interval or if the inverse iteration subroutine
    wasn't able to find all the corresponding eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned,
    M is equal to 0.

  -- ALGLIB --
     Copyright 07.01.2006 by Bochkanov Sergey
*************************************************************************/
ae_bool smatrixevdr(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     double b1,
     double b2,
     ae_int_t* m,
     /* Real    */ ae_vector* w,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_vector tau;
    ae_vector e;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    *m = 0;
    ae_vector_clear(w);
    ae_matrix_clear(z);
    ae_vector_init(&tau, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e, 0, DT_REAL, _state, ae_true);

    ae_assert(zneeded==0||zneeded==1, "SMatrixTDEVDR: incorrect ZNeeded", _state);
    smatrixtd(a, n, isupper, &tau, w, &e, _state);
    if( zneeded==1 )
    {
        smatrixtdunpackq(a, n, isupper, &tau, z, _state);
    }
    result = smatrixtdevdr(w, &e, n, zneeded, b1, b2, m, z, _state);
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Subroutine for finding the eigenvalues and  eigenvectors  of  a  symmetric
matrix with given indexes by using bisection and inverse iteration methods.

Input parameters:
    A       -   symmetric matrix which is given by its upper or lower
                triangular part. Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    I1, I2 -    index interval for searching (from I1 to I2).
                0 <= I1 <= I2 <= N-1.

Output parameters:
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..I2-I1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..I2-I1].
                In that case, the eigenvectors are stored in the matrix columns.

Result:
    True, if successful. W contains the eigenvalues, Z contains the
    eigenvectors (if needed).

    False, if the bisection method subroutine wasn't able to find the
    eigenvalues in the given interval or if the inverse iteration subroutine
    wasn't able to find all the corresponding eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned.

  -- ALGLIB --
     Copyright 07.01.2006 by Bochkanov Sergey
*************************************************************************/
ae_bool smatrixevdi(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     ae_int_t i1,
     ae_int_t i2,
     /* Real    */ ae_vector* w,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_vector tau;
    ae_vector e;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(w);
    ae_matrix_clear(z);
    ae_vector_init(&tau, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e, 0, DT_REAL, _state, ae_true);

    ae_assert(zneeded==0||zneeded==1, "SMatrixEVDI: incorrect ZNeeded", _state);
    smatrixtd(a, n, isupper, &tau, w, &e, _state);
    if( zneeded==1 )
    {
        smatrixtdunpackq(a, n, isupper, &tau, z, _state);
    }
    result = smatrixtdevdi(w, &e, n, zneeded, i1, i2, z, _state);
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Finding the eigenvalues and eigenvectors of a Hermitian matrix

The algorithm finds eigen pairs of a Hermitian matrix by  reducing  it  to
real tridiagonal form and using the QL/QR algorithm.

Input parameters:
    A       -   Hermitian matrix which is given  by  its  upper  or  lower
                triangular part.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format.
    ZNeeded -   flag controlling whether the eigenvectors  are  needed  or
                not. If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.

Output parameters:
    D       -   eigenvalues in ascending order.
                Array whose index ranges within [0..N-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains the eigenvectors.
                Array whose indexes range within [0..N-1, 0..N-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged (rare case).

Note:
    eigenvectors of Hermitian matrix are defined up to  multiplication  by
    a complex number L, such that |L|=1.

  -- ALGLIB --
     Copyright 2005, 23 March 2007 by Bochkanov Sergey
*************************************************************************/
ae_bool hmatrixevd(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     /* Real    */ ae_vector* d,
     /* Complex */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_vector tau;
    ae_vector e;
    ae_vector work;
    ae_matrix t;
    ae_matrix q;
    ae_int_t i;
    ae_int_t k;
    double v;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(d);
    ae_matrix_clear(z);
    ae_vector_init(&tau, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&e, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&t, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&q, 0, 0, DT_COMPLEX, _state, ae_true);

    ae_assert(zneeded==0||zneeded==1, "HermitianEVD: incorrect ZNeeded", _state);
    
    /*
     * Reduce to tridiagonal form
     */
    hmatrixtd(a, n, isupper, &tau, d, &e, _state);
    if( zneeded==1 )
    {
        hmatrixtdunpackq(a, n, isupper, &tau, &q, _state);
        zneeded = 2;
    }
    
    /*
     * TDEVD
     */
    result = smatrixtdevd(d, &e, n, zneeded, &t, _state);
    
    /*
     * Eigenvectors are needed
     * Calculate Z = Q*T = Re(Q)*T + i*Im(Q)*T
     */
    if( result&&zneeded!=0 )
    {
        ae_vector_set_length(&work, n-1+1, _state);
        ae_matrix_set_length(z, n-1+1, n-1+1, _state);
        for(i=0; i<=n-1; i++)
        {
            
            /*
             * Calculate real part
             */
            for(k=0; k<=n-1; k++)
            {
                work.ptr.p_double[k] = 0;
            }
            for(k=0; k<=n-1; k++)
            {
                v = q.ptr.pp_complex[i][k].x;
                ae_v_addd(&work.ptr.p_double[0], 1, &t.ptr.pp_double[k][0], 1, ae_v_len(0,n-1), v);
            }
            for(k=0; k<=n-1; k++)
            {
                z->ptr.pp_complex[i][k].x = work.ptr.p_double[k];
            }
            
            /*
             * Calculate imaginary part
             */
            for(k=0; k<=n-1; k++)
            {
                work.ptr.p_double[k] = 0;
            }
            for(k=0; k<=n-1; k++)
            {
                v = q.ptr.pp_complex[i][k].y;
                ae_v_addd(&work.ptr.p_double[0], 1, &t.ptr.pp_double[k][0], 1, ae_v_len(0,n-1), v);
            }
            for(k=0; k<=n-1; k++)
            {
                z->ptr.pp_complex[i][k].y = work.ptr.p_double[k];
            }
        }
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Subroutine for finding the eigenvalues (and eigenvectors) of  a  Hermitian
matrix  in  a  given half-interval (A, B] by using a bisection and inverse
iteration

Input parameters:
    A       -   Hermitian matrix which is given  by  its  upper  or  lower
                triangular  part.  Array  whose   indexes   range   within
                [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors  are  needed  or
                not. If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    B1, B2 -    half-interval (B1, B2] to search eigenvalues in.

Output parameters:
    M       -   number of eigenvalues found in a given half-interval, M>=0
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..M-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..M-1].
                The eigenvectors are stored in the matrix columns.

Result:
    True, if successful. M contains the number of eigenvalues in the given
    half-interval (could be equal to 0), W contains the eigenvalues,
    Z contains the eigenvectors (if needed).

    False, if the bisection method subroutine  wasn't  able  to  find  the
    eigenvalues  in  the  given  interval  or  if  the  inverse  iteration
    subroutine  wasn't  able  to  find all the corresponding eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned, M  is
    equal to 0.

Note:
    eigen vectors of Hermitian matrix are defined up to multiplication  by
    a complex number L, such as |L|=1.

  -- ALGLIB --
     Copyright 07.01.2006, 24.03.2007 by Bochkanov Sergey.
*************************************************************************/
ae_bool hmatrixevdr(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     double b1,
     double b2,
     ae_int_t* m,
     /* Real    */ ae_vector* w,
     /* Complex */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_matrix q;
    ae_matrix t;
    ae_vector tau;
    ae_vector e;
    ae_vector work;
    ae_int_t i;
    ae_int_t k;
    double v;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    *m = 0;
    ae_vector_clear(w);
    ae_matrix_clear(z);
    ae_matrix_init(&q, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&t, 0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&tau, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&e, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    ae_assert(zneeded==0||zneeded==1, "HermitianEigenValuesAndVectorsInInterval: incorrect ZNeeded", _state);
    
    /*
     * Reduce to tridiagonal form
     */
    hmatrixtd(a, n, isupper, &tau, w, &e, _state);
    if( zneeded==1 )
    {
        hmatrixtdunpackq(a, n, isupper, &tau, &q, _state);
        zneeded = 2;
    }
    
    /*
     * Bisection and inverse iteration
     */
    result = smatrixtdevdr(w, &e, n, zneeded, b1, b2, m, &t, _state);
    
    /*
     * Eigenvectors are needed
     * Calculate Z = Q*T = Re(Q)*T + i*Im(Q)*T
     */
    if( (result&&zneeded!=0)&&*m!=0 )
    {
        ae_vector_set_length(&work, *m-1+1, _state);
        ae_matrix_set_length(z, n-1+1, *m-1+1, _state);
        for(i=0; i<=n-1; i++)
        {
            
            /*
             * Calculate real part
             */
            for(k=0; k<=*m-1; k++)
            {
                work.ptr.p_double[k] = 0;
            }
            for(k=0; k<=n-1; k++)
            {
                v = q.ptr.pp_complex[i][k].x;
                ae_v_addd(&work.ptr.p_double[0], 1, &t.ptr.pp_double[k][0], 1, ae_v_len(0,*m-1), v);
            }
            for(k=0; k<=*m-1; k++)
            {
                z->ptr.pp_complex[i][k].x = work.ptr.p_double[k];
            }
            
            /*
             * Calculate imaginary part
             */
            for(k=0; k<=*m-1; k++)
            {
                work.ptr.p_double[k] = 0;
            }
            for(k=0; k<=n-1; k++)
            {
                v = q.ptr.pp_complex[i][k].y;
                ae_v_addd(&work.ptr.p_double[0], 1, &t.ptr.pp_double[k][0], 1, ae_v_len(0,*m-1), v);
            }
            for(k=0; k<=*m-1; k++)
            {
                z->ptr.pp_complex[i][k].y = work.ptr.p_double[k];
            }
        }
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Subroutine for finding the eigenvalues and  eigenvectors  of  a  Hermitian
matrix with given indexes by using bisection and inverse iteration methods

Input parameters:
    A       -   Hermitian matrix which is given  by  its  upper  or  lower
                triangular part.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors  are  needed  or
                not. If ZNeeded is equal to:
                 * 0, the eigenvectors are not returned;
                 * 1, the eigenvectors are returned.
    IsUpperA -  storage format of matrix A.
    I1, I2 -    index interval for searching (from I1 to I2).
                0 <= I1 <= I2 <= N-1.

Output parameters:
    W       -   array of the eigenvalues found.
                Array whose index ranges within [0..I2-I1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains eigenvectors.
                Array whose indexes range within [0..N-1, 0..I2-I1].
                In  that  case,  the eigenvectors are stored in the matrix
                columns.

Result:
    True, if successful. W contains the eigenvalues, Z contains the
    eigenvectors (if needed).

    False, if the bisection method subroutine  wasn't  able  to  find  the
    eigenvalues  in  the  given  interval  or  if  the  inverse  iteration
    subroutine wasn't able to find  all  the  corresponding  eigenvectors.
    In that case, the eigenvalues and eigenvectors are not returned.

Note:
    eigen vectors of Hermitian matrix are defined up to multiplication  by
    a complex number L, such as |L|=1.

  -- ALGLIB --
     Copyright 07.01.2006, 24.03.2007 by Bochkanov Sergey.
*************************************************************************/
ae_bool hmatrixevdi(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     ae_int_t i1,
     ae_int_t i2,
     /* Real    */ ae_vector* w,
     /* Complex */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_matrix q;
    ae_matrix t;
    ae_vector tau;
    ae_vector e;
    ae_vector work;
    ae_int_t i;
    ae_int_t k;
    double v;
    ae_int_t m;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(w);
    ae_matrix_clear(z);
    ae_matrix_init(&q, 0, 0, DT_COMPLEX, _state, ae_true);
    ae_matrix_init(&t, 0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&tau, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&e, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    ae_assert(zneeded==0||zneeded==1, "HermitianEigenValuesAndVectorsByIndexes: incorrect ZNeeded", _state);
    
    /*
     * Reduce to tridiagonal form
     */
    hmatrixtd(a, n, isupper, &tau, w, &e, _state);
    if( zneeded==1 )
    {
        hmatrixtdunpackq(a, n, isupper, &tau, &q, _state);
        zneeded = 2;
    }
    
    /*
     * Bisection and inverse iteration
     */
    result = smatrixtdevdi(w, &e, n, zneeded, i1, i2, &t, _state);
    
    /*
     * Eigenvectors are needed
     * Calculate Z = Q*T = Re(Q)*T + i*Im(Q)*T
     */
    m = i2-i1+1;
    if( result&&zneeded!=0 )
    {
        ae_vector_set_length(&work, m-1+1, _state);
        ae_matrix_set_length(z, n-1+1, m-1+1, _state);
        for(i=0; i<=n-1; i++)
        {
            
            /*
             * Calculate real part
             */
            for(k=0; k<=m-1; k++)
            {
                work.ptr.p_double[k] = 0;
            }
            for(k=0; k<=n-1; k++)
            {
                v = q.ptr.pp_complex[i][k].x;
                ae_v_addd(&work.ptr.p_double[0], 1, &t.ptr.pp_double[k][0], 1, ae_v_len(0,m-1), v);
            }
            for(k=0; k<=m-1; k++)
            {
                z->ptr.pp_complex[i][k].x = work.ptr.p_double[k];
            }
            
            /*
             * Calculate imaginary part
             */
            for(k=0; k<=m-1; k++)
            {
                work.ptr.p_double[k] = 0;
            }
            for(k=0; k<=n-1; k++)
            {
                v = q.ptr.pp_complex[i][k].y;
                ae_v_addd(&work.ptr.p_double[0], 1, &t.ptr.pp_double[k][0], 1, ae_v_len(0,m-1), v);
            }
            for(k=0; k<=m-1; k++)
            {
                z->ptr.pp_complex[i][k].y = work.ptr.p_double[k];
            }
        }
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Finding the eigenvalues and eigenvectors of a tridiagonal symmetric matrix

The algorithm finds the eigen pairs of a tridiagonal symmetric matrix by
using an QL/QR algorithm with implicit shifts.

Input parameters:
    D       -   the main diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-1].
    E       -   the secondary diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix A.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not needed;
                 * 1, the eigenvectors of a tridiagonal matrix
                   are multiplied by the square matrix Z. It is used if the
                   tridiagonal matrix is obtained by the similarity
                   transformation of a symmetric matrix;
                 * 2, the eigenvectors of a tridiagonal matrix replace the
                   square matrix Z;
                 * 3, matrix Z contains the first row of the eigenvectors
                   matrix.
    Z       -   if ZNeeded=1, Z contains the square matrix by which the
                eigenvectors are multiplied.
                Array whose indexes range within [0..N-1, 0..N-1].

Output parameters:
    D       -   eigenvalues in ascending order.
                Array whose index ranges within [0..N-1].
    Z       -   if ZNeeded is equal to:
                 * 0, Z hasn�t changed;
                 * 1, Z contains the product of a given matrix (from the left)
                   and the eigenvectors matrix (from the right);
                 * 2, Z contains the eigenvectors.
                 * 3, Z contains the first row of the eigenvectors matrix.
                If ZNeeded<3, Z is the array whose indexes range within [0..N-1, 0..N-1].
                In that case, the eigenvectors are stored in the matrix columns.
                If ZNeeded=3, Z is the array whose indexes range within [0..0, 0..N-1].

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     September 30, 1994
*************************************************************************/
ae_bool smatrixtdevd(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _e;
    ae_vector d1;
    ae_vector e1;
    ae_matrix z1;
    ae_int_t i;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_e, e, _state, ae_true);
    e = &_e;
    ae_vector_init(&d1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e1, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&z1, 0, 0, DT_REAL, _state, ae_true);

    
    /*
     * Prepare 1-based task
     */
    ae_vector_set_length(&d1, n+1, _state);
    ae_vector_set_length(&e1, n+1, _state);
    ae_v_move(&d1.ptr.p_double[1], 1, &d->ptr.p_double[0], 1, ae_v_len(1,n));
    if( n>1 )
    {
        ae_v_move(&e1.ptr.p_double[1], 1, &e->ptr.p_double[0], 1, ae_v_len(1,n-1));
    }
    if( zneeded==1 )
    {
        ae_matrix_set_length(&z1, n+1, n+1, _state);
        for(i=1; i<=n; i++)
        {
            ae_v_move(&z1.ptr.pp_double[i][1], 1, &z->ptr.pp_double[i-1][0], 1, ae_v_len(1,n));
        }
    }
    
    /*
     * Solve 1-based task
     */
    result = evd_tridiagonalevd(&d1, &e1, n, zneeded, &z1, _state);
    if( !result )
    {
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Convert back to 0-based result
     */
    ae_v_move(&d->ptr.p_double[0], 1, &d1.ptr.p_double[1], 1, ae_v_len(0,n-1));
    if( zneeded!=0 )
    {
        if( zneeded==1 )
        {
            for(i=1; i<=n; i++)
            {
                ae_v_move(&z->ptr.pp_double[i-1][0], 1, &z1.ptr.pp_double[i][1], 1, ae_v_len(0,n-1));
            }
            ae_frame_leave(_state);
            return result;
        }
        if( zneeded==2 )
        {
            ae_matrix_set_length(z, n-1+1, n-1+1, _state);
            for(i=1; i<=n; i++)
            {
                ae_v_move(&z->ptr.pp_double[i-1][0], 1, &z1.ptr.pp_double[i][1], 1, ae_v_len(0,n-1));
            }
            ae_frame_leave(_state);
            return result;
        }
        if( zneeded==3 )
        {
            ae_matrix_set_length(z, 0+1, n-1+1, _state);
            ae_v_move(&z->ptr.pp_double[0][0], 1, &z1.ptr.pp_double[1][1], 1, ae_v_len(0,n-1));
            ae_frame_leave(_state);
            return result;
        }
        ae_assert(ae_false, "SMatrixTDEVD: Incorrect ZNeeded!", _state);
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Subroutine for finding the tridiagonal matrix eigenvalues/vectors in a
given half-interval (A, B] by using bisection and inverse iteration.

Input parameters:
    D       -   the main diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-1].
    E       -   the secondary diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix, N>=0.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not needed;
                 * 1, the eigenvectors of a tridiagonal matrix are multiplied
                   by the square matrix Z. It is used if the tridiagonal
                   matrix is obtained by the similarity transformation
                   of a symmetric matrix.
                 * 2, the eigenvectors of a tridiagonal matrix replace matrix Z.
    A, B    -   half-interval (A, B] to search eigenvalues in.
    Z       -   if ZNeeded is equal to:
                 * 0, Z isn't used and remains unchanged;
                 * 1, Z contains the square matrix (array whose indexes range
                   within [0..N-1, 0..N-1]) which reduces the given symmetric
                   matrix to tridiagonal form;
                 * 2, Z isn't used (but changed on the exit).

Output parameters:
    D       -   array of the eigenvalues found.
                Array whose index ranges within [0..M-1].
    M       -   number of eigenvalues found in the given half-interval (M>=0).
    Z       -   if ZNeeded is equal to:
                 * 0, doesn't contain any information;
                 * 1, contains the product of a given NxN matrix Z (from the
                   left) and NxM matrix of the eigenvectors found (from the
                   right). Array whose indexes range within [0..N-1, 0..M-1].
                 * 2, contains the matrix of the eigenvectors found.
                   Array whose indexes range within [0..N-1, 0..M-1].

Result:

    True, if successful. In that case, M contains the number of eigenvalues
    in the given half-interval (could be equal to 0), D contains the eigenvalues,
    Z contains the eigenvectors (if needed).
    It should be noted that the subroutine changes the size of arrays D and Z.

    False, if the bisection method subroutine wasn't able to find the
    eigenvalues in the given interval or if the inverse iteration subroutine
    wasn't able to find all the corresponding eigenvectors. In that case,
    the eigenvalues and eigenvectors are not returned, M is equal to 0.

  -- ALGLIB --
     Copyright 31.03.2008 by Bochkanov Sergey
*************************************************************************/
ae_bool smatrixtdevdr(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     double a,
     double b,
     ae_int_t* m,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t errorcode;
    ae_int_t nsplit;
    ae_int_t i;
    ae_int_t j;
    ae_int_t k;
    ae_int_t cr;
    ae_vector iblock;
    ae_vector isplit;
    ae_vector ifail;
    ae_vector d1;
    ae_vector e1;
    ae_vector w;
    ae_matrix z2;
    ae_matrix z3;
    double v;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    *m = 0;
    ae_vector_init(&iblock, 0, DT_INT, _state, ae_true);
    ae_vector_init(&isplit, 0, DT_INT, _state, ae_true);
    ae_vector_init(&ifail, 0, DT_INT, _state, ae_true);
    ae_vector_init(&d1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&w, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&z2, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&z3, 0, 0, DT_REAL, _state, ae_true);

    ae_assert(zneeded>=0&&zneeded<=2, "SMatrixTDEVDR: incorrect ZNeeded!", _state);
    
    /*
     * Special cases
     */
    if( ae_fp_less_eq(b,a) )
    {
        *m = 0;
        result = ae_true;
        ae_frame_leave(_state);
        return result;
    }
    if( n<=0 )
    {
        *m = 0;
        result = ae_true;
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Copy D,E to D1, E1
     */
    ae_vector_set_length(&d1, n+1, _state);
    ae_v_move(&d1.ptr.p_double[1], 1, &d->ptr.p_double[0], 1, ae_v_len(1,n));
    if( n>1 )
    {
        ae_vector_set_length(&e1, n-1+1, _state);
        ae_v_move(&e1.ptr.p_double[1], 1, &e->ptr.p_double[0], 1, ae_v_len(1,n-1));
    }
    
    /*
     * No eigen vectors
     */
    if( zneeded==0 )
    {
        result = evd_internalbisectioneigenvalues(&d1, &e1, n, 2, 1, a, b, 0, 0, -1, &w, m, &nsplit, &iblock, &isplit, &errorcode, _state);
        if( !result||*m==0 )
        {
            *m = 0;
            ae_frame_leave(_state);
            return result;
        }
        ae_vector_set_length(d, *m-1+1, _state);
        ae_v_move(&d->ptr.p_double[0], 1, &w.ptr.p_double[1], 1, ae_v_len(0,*m-1));
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Eigen vectors are multiplied by Z
     */
    if( zneeded==1 )
    {
        
        /*
         * Find eigen pairs
         */
        result = evd_internalbisectioneigenvalues(&d1, &e1, n, 2, 2, a, b, 0, 0, -1, &w, m, &nsplit, &iblock, &isplit, &errorcode, _state);
        if( !result||*m==0 )
        {
            *m = 0;
            ae_frame_leave(_state);
            return result;
        }
        evd_internaldstein(n, &d1, &e1, *m, &w, &iblock, &isplit, &z2, &ifail, &cr, _state);
        if( cr!=0 )
        {
            *m = 0;
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Sort eigen values and vectors
         */
        for(i=1; i<=*m; i++)
        {
            k = i;
            for(j=i; j<=*m; j++)
            {
                if( ae_fp_less(w.ptr.p_double[j],w.ptr.p_double[k]) )
                {
                    k = j;
                }
            }
            v = w.ptr.p_double[i];
            w.ptr.p_double[i] = w.ptr.p_double[k];
            w.ptr.p_double[k] = v;
            for(j=1; j<=n; j++)
            {
                v = z2.ptr.pp_double[j][i];
                z2.ptr.pp_double[j][i] = z2.ptr.pp_double[j][k];
                z2.ptr.pp_double[j][k] = v;
            }
        }
        
        /*
         * Transform Z2 and overwrite Z
         */
        ae_matrix_set_length(&z3, *m+1, n+1, _state);
        for(i=1; i<=*m; i++)
        {
            ae_v_move(&z3.ptr.pp_double[i][1], 1, &z2.ptr.pp_double[1][i], z2.stride, ae_v_len(1,n));
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=*m; j++)
            {
                v = ae_v_dotproduct(&z->ptr.pp_double[i-1][0], 1, &z3.ptr.pp_double[j][1], 1, ae_v_len(0,n-1));
                z2.ptr.pp_double[i][j] = v;
            }
        }
        ae_matrix_set_length(z, n-1+1, *m-1+1, _state);
        for(i=1; i<=*m; i++)
        {
            ae_v_move(&z->ptr.pp_double[0][i-1], z->stride, &z2.ptr.pp_double[1][i], z2.stride, ae_v_len(0,n-1));
        }
        
        /*
         * Store W
         */
        ae_vector_set_length(d, *m-1+1, _state);
        for(i=1; i<=*m; i++)
        {
            d->ptr.p_double[i-1] = w.ptr.p_double[i];
        }
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Eigen vectors are stored in Z
     */
    if( zneeded==2 )
    {
        
        /*
         * Find eigen pairs
         */
        result = evd_internalbisectioneigenvalues(&d1, &e1, n, 2, 2, a, b, 0, 0, -1, &w, m, &nsplit, &iblock, &isplit, &errorcode, _state);
        if( !result||*m==0 )
        {
            *m = 0;
            ae_frame_leave(_state);
            return result;
        }
        evd_internaldstein(n, &d1, &e1, *m, &w, &iblock, &isplit, &z2, &ifail, &cr, _state);
        if( cr!=0 )
        {
            *m = 0;
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Sort eigen values and vectors
         */
        for(i=1; i<=*m; i++)
        {
            k = i;
            for(j=i; j<=*m; j++)
            {
                if( ae_fp_less(w.ptr.p_double[j],w.ptr.p_double[k]) )
                {
                    k = j;
                }
            }
            v = w.ptr.p_double[i];
            w.ptr.p_double[i] = w.ptr.p_double[k];
            w.ptr.p_double[k] = v;
            for(j=1; j<=n; j++)
            {
                v = z2.ptr.pp_double[j][i];
                z2.ptr.pp_double[j][i] = z2.ptr.pp_double[j][k];
                z2.ptr.pp_double[j][k] = v;
            }
        }
        
        /*
         * Store W
         */
        ae_vector_set_length(d, *m-1+1, _state);
        for(i=1; i<=*m; i++)
        {
            d->ptr.p_double[i-1] = w.ptr.p_double[i];
        }
        ae_matrix_set_length(z, n-1+1, *m-1+1, _state);
        for(i=1; i<=*m; i++)
        {
            ae_v_move(&z->ptr.pp_double[0][i-1], z->stride, &z2.ptr.pp_double[1][i], z2.stride, ae_v_len(0,n-1));
        }
        ae_frame_leave(_state);
        return result;
    }
    result = ae_false;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Subroutine for finding tridiagonal matrix eigenvalues/vectors with given
indexes (in ascending order) by using the bisection and inverse iteraion.

Input parameters:
    D       -   the main diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-1].
    E       -   the secondary diagonal of a tridiagonal matrix.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix. N>=0.
    ZNeeded -   flag controlling whether the eigenvectors are needed or not.
                If ZNeeded is equal to:
                 * 0, the eigenvectors are not needed;
                 * 1, the eigenvectors of a tridiagonal matrix are multiplied
                   by the square matrix Z. It is used if the
                   tridiagonal matrix is obtained by the similarity transformation
                   of a symmetric matrix.
                 * 2, the eigenvectors of a tridiagonal matrix replace
                   matrix Z.
    I1, I2  -   index interval for searching (from I1 to I2).
                0 <= I1 <= I2 <= N-1.
    Z       -   if ZNeeded is equal to:
                 * 0, Z isn't used and remains unchanged;
                 * 1, Z contains the square matrix (array whose indexes range within [0..N-1, 0..N-1])
                   which reduces the given symmetric matrix to  tridiagonal form;
                 * 2, Z isn't used (but changed on the exit).

Output parameters:
    D       -   array of the eigenvalues found.
                Array whose index ranges within [0..I2-I1].
    Z       -   if ZNeeded is equal to:
                 * 0, doesn't contain any information;
                 * 1, contains the product of a given NxN matrix Z (from the left) and
                   Nx(I2-I1) matrix of the eigenvectors found (from the right).
                   Array whose indexes range within [0..N-1, 0..I2-I1].
                 * 2, contains the matrix of the eigenvalues found.
                   Array whose indexes range within [0..N-1, 0..I2-I1].


Result:

    True, if successful. In that case, D contains the eigenvalues,
    Z contains the eigenvectors (if needed).
    It should be noted that the subroutine changes the size of arrays D and Z.

    False, if the bisection method subroutine wasn't able to find the eigenvalues
    in the given interval or if the inverse iteration subroutine wasn't able
    to find all the corresponding eigenvectors. In that case, the eigenvalues
    and eigenvectors are not returned.

  -- ALGLIB --
     Copyright 25.12.2005 by Bochkanov Sergey
*************************************************************************/
ae_bool smatrixtdevdi(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     ae_int_t i1,
     ae_int_t i2,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t errorcode;
    ae_int_t nsplit;
    ae_int_t i;
    ae_int_t j;
    ae_int_t k;
    ae_int_t m;
    ae_int_t cr;
    ae_vector iblock;
    ae_vector isplit;
    ae_vector ifail;
    ae_vector w;
    ae_vector d1;
    ae_vector e1;
    ae_matrix z2;
    ae_matrix z3;
    double v;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&iblock, 0, DT_INT, _state, ae_true);
    ae_vector_init(&isplit, 0, DT_INT, _state, ae_true);
    ae_vector_init(&ifail, 0, DT_INT, _state, ae_true);
    ae_vector_init(&w, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&d1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e1, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&z2, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&z3, 0, 0, DT_REAL, _state, ae_true);

    ae_assert((0<=i1&&i1<=i2)&&i2<n, "SMatrixTDEVDI: incorrect I1/I2!", _state);
    
    /*
     * Copy D,E to D1, E1
     */
    ae_vector_set_length(&d1, n+1, _state);
    ae_v_move(&d1.ptr.p_double[1], 1, &d->ptr.p_double[0], 1, ae_v_len(1,n));
    if( n>1 )
    {
        ae_vector_set_length(&e1, n-1+1, _state);
        ae_v_move(&e1.ptr.p_double[1], 1, &e->ptr.p_double[0], 1, ae_v_len(1,n-1));
    }
    
    /*
     * No eigen vectors
     */
    if( zneeded==0 )
    {
        result = evd_internalbisectioneigenvalues(&d1, &e1, n, 3, 1, 0, 0, i1+1, i2+1, -1, &w, &m, &nsplit, &iblock, &isplit, &errorcode, _state);
        if( !result )
        {
            ae_frame_leave(_state);
            return result;
        }
        if( m!=i2-i1+1 )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        ae_vector_set_length(d, m-1+1, _state);
        for(i=1; i<=m; i++)
        {
            d->ptr.p_double[i-1] = w.ptr.p_double[i];
        }
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Eigen vectors are multiplied by Z
     */
    if( zneeded==1 )
    {
        
        /*
         * Find eigen pairs
         */
        result = evd_internalbisectioneigenvalues(&d1, &e1, n, 3, 2, 0, 0, i1+1, i2+1, -1, &w, &m, &nsplit, &iblock, &isplit, &errorcode, _state);
        if( !result )
        {
            ae_frame_leave(_state);
            return result;
        }
        if( m!=i2-i1+1 )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        evd_internaldstein(n, &d1, &e1, m, &w, &iblock, &isplit, &z2, &ifail, &cr, _state);
        if( cr!=0 )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Sort eigen values and vectors
         */
        for(i=1; i<=m; i++)
        {
            k = i;
            for(j=i; j<=m; j++)
            {
                if( ae_fp_less(w.ptr.p_double[j],w.ptr.p_double[k]) )
                {
                    k = j;
                }
            }
            v = w.ptr.p_double[i];
            w.ptr.p_double[i] = w.ptr.p_double[k];
            w.ptr.p_double[k] = v;
            for(j=1; j<=n; j++)
            {
                v = z2.ptr.pp_double[j][i];
                z2.ptr.pp_double[j][i] = z2.ptr.pp_double[j][k];
                z2.ptr.pp_double[j][k] = v;
            }
        }
        
        /*
         * Transform Z2 and overwrite Z
         */
        ae_matrix_set_length(&z3, m+1, n+1, _state);
        for(i=1; i<=m; i++)
        {
            ae_v_move(&z3.ptr.pp_double[i][1], 1, &z2.ptr.pp_double[1][i], z2.stride, ae_v_len(1,n));
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                v = ae_v_dotproduct(&z->ptr.pp_double[i-1][0], 1, &z3.ptr.pp_double[j][1], 1, ae_v_len(0,n-1));
                z2.ptr.pp_double[i][j] = v;
            }
        }
        ae_matrix_set_length(z, n-1+1, m-1+1, _state);
        for(i=1; i<=m; i++)
        {
            ae_v_move(&z->ptr.pp_double[0][i-1], z->stride, &z2.ptr.pp_double[1][i], z2.stride, ae_v_len(0,n-1));
        }
        
        /*
         * Store W
         */
        ae_vector_set_length(d, m-1+1, _state);
        for(i=1; i<=m; i++)
        {
            d->ptr.p_double[i-1] = w.ptr.p_double[i];
        }
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Eigen vectors are stored in Z
     */
    if( zneeded==2 )
    {
        
        /*
         * Find eigen pairs
         */
        result = evd_internalbisectioneigenvalues(&d1, &e1, n, 3, 2, 0, 0, i1+1, i2+1, -1, &w, &m, &nsplit, &iblock, &isplit, &errorcode, _state);
        if( !result )
        {
            ae_frame_leave(_state);
            return result;
        }
        if( m!=i2-i1+1 )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        evd_internaldstein(n, &d1, &e1, m, &w, &iblock, &isplit, &z2, &ifail, &cr, _state);
        if( cr!=0 )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Sort eigen values and vectors
         */
        for(i=1; i<=m; i++)
        {
            k = i;
            for(j=i; j<=m; j++)
            {
                if( ae_fp_less(w.ptr.p_double[j],w.ptr.p_double[k]) )
                {
                    k = j;
                }
            }
            v = w.ptr.p_double[i];
            w.ptr.p_double[i] = w.ptr.p_double[k];
            w.ptr.p_double[k] = v;
            for(j=1; j<=n; j++)
            {
                v = z2.ptr.pp_double[j][i];
                z2.ptr.pp_double[j][i] = z2.ptr.pp_double[j][k];
                z2.ptr.pp_double[j][k] = v;
            }
        }
        
        /*
         * Store Z
         */
        ae_matrix_set_length(z, n-1+1, m-1+1, _state);
        for(i=1; i<=m; i++)
        {
            ae_v_move(&z->ptr.pp_double[0][i-1], z->stride, &z2.ptr.pp_double[1][i], z2.stride, ae_v_len(0,n-1));
        }
        
        /*
         * Store W
         */
        ae_vector_set_length(d, m-1+1, _state);
        for(i=1; i<=m; i++)
        {
            d->ptr.p_double[i-1] = w.ptr.p_double[i];
        }
        ae_frame_leave(_state);
        return result;
    }
    result = ae_false;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Finding eigenvalues and eigenvectors of a general matrix

The algorithm finds eigenvalues and eigenvectors of a general matrix by
using the QR algorithm with multiple shifts. The algorithm can find
eigenvalues and both left and right eigenvectors.

The right eigenvector is a vector x such that A*x = w*x, and the left
eigenvector is a vector y such that y'*A = w*y' (here y' implies a complex
conjugate transposition of vector y).

Input parameters:
    A       -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    VNeeded -   flag controlling whether eigenvectors are needed or not.
                If VNeeded is equal to:
                 * 0, eigenvectors are not returned;
                 * 1, right eigenvectors are returned;
                 * 2, left eigenvectors are returned;
                 * 3, both left and right eigenvectors are returned.

Output parameters:
    WR      -   real parts of eigenvalues.
                Array whose index ranges within [0..N-1].
    WR      -   imaginary parts of eigenvalues.
                Array whose index ranges within [0..N-1].
    VL, VR  -   arrays of left and right eigenvectors (if they are needed).
                If WI[i]=0, the respective eigenvalue is a real number,
                and it corresponds to the column number I of matrices VL/VR.
                If WI[i]>0, we have a pair of complex conjugate numbers with
                positive and negative imaginary parts:
                    the first eigenvalue WR[i] + sqrt(-1)*WI[i];
                    the second eigenvalue WR[i+1] + sqrt(-1)*WI[i+1];
                    WI[i]>0
                    WI[i+1] = -WI[i] < 0
                In that case, the eigenvector  corresponding to the first
                eigenvalue is located in i and i+1 columns of matrices
                VL/VR (the column number i contains the real part, and the
                column number i+1 contains the imaginary part), and the vector
                corresponding to the second eigenvalue is a complex conjugate to
                the first vector.
                Arrays whose indexes range within [0..N-1, 0..N-1].

Result:
    True, if the algorithm has converged.
    False, if the algorithm has not converged.

Note 1:
    Some users may ask the following question: what if WI[N-1]>0?
    WI[N] must contain an eigenvalue which is complex conjugate to the
    N-th eigenvalue, but the array has only size N?
    The answer is as follows: such a situation cannot occur because the
    algorithm finds a pairs of eigenvalues, therefore, if WI[i]>0, I is
    strictly less than N-1.

Note 2:
    The algorithm performance depends on the value of the internal parameter
    NS of the InternalSchurDecomposition subroutine which defines the number
    of shifts in the QR algorithm (similarly to the block width in block-matrix
    algorithms of linear algebra). If you require maximum performance
    on your machine, it is recommended to adjust this parameter manually.


See also the InternalTREVC subroutine.

The algorithm is based on the LAPACK 3.0 library.
*************************************************************************/
ae_bool rmatrixevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t vneeded,
     /* Real    */ ae_vector* wr,
     /* Real    */ ae_vector* wi,
     /* Real    */ ae_matrix* vl,
     /* Real    */ ae_matrix* vr,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_matrix a1;
    ae_matrix vl1;
    ae_matrix vr1;
    ae_vector wr1;
    ae_vector wi1;
    ae_int_t i;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(wr);
    ae_vector_clear(wi);
    ae_matrix_clear(vl);
    ae_matrix_clear(vr);
    ae_matrix_init(&a1, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&vl1, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&vr1, 0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&wr1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&wi1, 0, DT_REAL, _state, ae_true);

    ae_assert(vneeded>=0&&vneeded<=3, "RMatrixEVD: incorrect VNeeded!", _state);
    ae_matrix_set_length(&a1, n+1, n+1, _state);
    for(i=1; i<=n; i++)
    {
        ae_v_move(&a1.ptr.pp_double[i][1], 1, &a->ptr.pp_double[i-1][0], 1, ae_v_len(1,n));
    }
    result = evd_nonsymmetricevd(&a1, n, vneeded, &wr1, &wi1, &vl1, &vr1, _state);
    if( result )
    {
        ae_vector_set_length(wr, n-1+1, _state);
        ae_vector_set_length(wi, n-1+1, _state);
        ae_v_move(&wr->ptr.p_double[0], 1, &wr1.ptr.p_double[1], 1, ae_v_len(0,n-1));
        ae_v_move(&wi->ptr.p_double[0], 1, &wi1.ptr.p_double[1], 1, ae_v_len(0,n-1));
        if( vneeded==2||vneeded==3 )
        {
            ae_matrix_set_length(vl, n-1+1, n-1+1, _state);
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&vl->ptr.pp_double[i][0], 1, &vl1.ptr.pp_double[i+1][1], 1, ae_v_len(0,n-1));
            }
        }
        if( vneeded==1||vneeded==3 )
        {
            ae_matrix_set_length(vr, n-1+1, n-1+1, _state);
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&vr->ptr.pp_double[i][0], 1, &vr1.ptr.pp_double[i+1][1], 1, ae_v_len(0,n-1));
            }
        }
    }
    ae_frame_leave(_state);
    return result;
}


static ae_bool evd_tridiagonalevd(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _e;
    ae_int_t maxit;
    ae_int_t i;
    ae_int_t ii;
    ae_int_t iscale;
    ae_int_t j;
    ae_int_t jtot;
    ae_int_t k;
    ae_int_t t;
    ae_int_t l;
    ae_int_t l1;
    ae_int_t lend;
    ae_int_t lendm1;
    ae_int_t lendp1;
    ae_int_t lendsv;
    ae_int_t lm1;
    ae_int_t lsv;
    ae_int_t m;
    ae_int_t mm;
    ae_int_t mm1;
    ae_int_t nm1;
    ae_int_t nmaxit;
    ae_int_t tmpint;
    double anorm;
    double b;
    double c;
    double eps;
    double eps2;
    double f;
    double g;
    double p;
    double r;
    double rt1;
    double rt2;
    double s;
    double safmax;
    double safmin;
    double ssfmax;
    double ssfmin;
    double tst;
    double tmp;
    ae_vector work1;
    ae_vector work2;
    ae_vector workc;
    ae_vector works;
    ae_vector wtemp;
    ae_bool gotoflag;
    ae_int_t zrows;
    ae_bool wastranspose;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_e, e, _state, ae_true);
    e = &_e;
    ae_vector_init(&work1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work2, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&workc, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&works, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&wtemp, 0, DT_REAL, _state, ae_true);

    ae_assert(zneeded>=0&&zneeded<=3, "TridiagonalEVD: Incorrent ZNeeded", _state);
    
    /*
     * Quick return if possible
     */
    if( zneeded<0||zneeded>3 )
    {
        result = ae_false;
        ae_frame_leave(_state);
        return result;
    }
    result = ae_true;
    if( n==0 )
    {
        ae_frame_leave(_state);
        return result;
    }
    if( n==1 )
    {
        if( zneeded==2||zneeded==3 )
        {
            ae_matrix_set_length(z, 1+1, 1+1, _state);
            z->ptr.pp_double[1][1] = 1;
        }
        ae_frame_leave(_state);
        return result;
    }
    maxit = 30;
    
    /*
     * Initialize arrays
     */
    ae_vector_set_length(&wtemp, n+1, _state);
    ae_vector_set_length(&work1, n-1+1, _state);
    ae_vector_set_length(&work2, n-1+1, _state);
    ae_vector_set_length(&workc, n+1, _state);
    ae_vector_set_length(&works, n+1, _state);
    
    /*
     * Determine the unit roundoff and over/underflow thresholds.
     */
    eps = ae_machineepsilon;
    eps2 = ae_sqr(eps, _state);
    safmin = ae_minrealnumber;
    safmax = ae_maxrealnumber;
    ssfmax = ae_sqrt(safmax, _state)/3;
    ssfmin = ae_sqrt(safmin, _state)/eps2;
    
    /*
     * Prepare Z
     *
     * Here we are using transposition to get rid of column operations
     *
     */
    wastranspose = ae_false;
    zrows = 0;
    if( zneeded==1 )
    {
        zrows = n;
    }
    if( zneeded==2 )
    {
        zrows = n;
    }
    if( zneeded==3 )
    {
        zrows = 1;
    }
    if( zneeded==1 )
    {
        wastranspose = ae_true;
        inplacetranspose(z, 1, n, 1, n, &wtemp, _state);
    }
    if( zneeded==2 )
    {
        wastranspose = ae_true;
        ae_matrix_set_length(z, n+1, n+1, _state);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if( i==j )
                {
                    z->ptr.pp_double[i][j] = 1;
                }
                else
                {
                    z->ptr.pp_double[i][j] = 0;
                }
            }
        }
    }
    if( zneeded==3 )
    {
        wastranspose = ae_false;
        ae_matrix_set_length(z, 1+1, n+1, _state);
        for(j=1; j<=n; j++)
        {
            if( j==1 )
            {
                z->ptr.pp_double[1][j] = 1;
            }
            else
            {
                z->ptr.pp_double[1][j] = 0;
            }
        }
    }
    nmaxit = n*maxit;
    jtot = 0;
    
    /*
     * Determine where the matrix splits and choose QL or QR iteration
     * for each block, according to whether top or bottom diagonal
     * element is smaller.
     */
    l1 = 1;
    nm1 = n-1;
    for(;;)
    {
        if( l1>n )
        {
            break;
        }
        if( l1>1 )
        {
            e->ptr.p_double[l1-1] = 0;
        }
        gotoflag = ae_false;
        m = l1;
        if( l1<=nm1 )
        {
            for(m=l1; m<=nm1; m++)
            {
                tst = ae_fabs(e->ptr.p_double[m], _state);
                if( ae_fp_eq(tst,0) )
                {
                    gotoflag = ae_true;
                    break;
                }
                if( ae_fp_less_eq(tst,ae_sqrt(ae_fabs(d->ptr.p_double[m], _state), _state)*ae_sqrt(ae_fabs(d->ptr.p_double[m+1], _state), _state)*eps) )
                {
                    e->ptr.p_double[m] = 0;
                    gotoflag = ae_true;
                    break;
                }
            }
        }
        if( !gotoflag )
        {
            m = n;
        }
        
        /*
         * label 30:
         */
        l = l1;
        lsv = l;
        lend = m;
        lendsv = lend;
        l1 = m+1;
        if( lend==l )
        {
            continue;
        }
        
        /*
         * Scale submatrix in rows and columns L to LEND
         */
        if( l==lend )
        {
            anorm = ae_fabs(d->ptr.p_double[l], _state);
        }
        else
        {
            anorm = ae_maxreal(ae_fabs(d->ptr.p_double[l], _state)+ae_fabs(e->ptr.p_double[l], _state), ae_fabs(e->ptr.p_double[lend-1], _state)+ae_fabs(d->ptr.p_double[lend], _state), _state);
            for(i=l+1; i<=lend-1; i++)
            {
                anorm = ae_maxreal(anorm, ae_fabs(d->ptr.p_double[i], _state)+ae_fabs(e->ptr.p_double[i], _state)+ae_fabs(e->ptr.p_double[i-1], _state), _state);
            }
        }
        iscale = 0;
        if( ae_fp_eq(anorm,0) )
        {
            continue;
        }
        if( ae_fp_greater(anorm,ssfmax) )
        {
            iscale = 1;
            tmp = ssfmax/anorm;
            tmpint = lend-1;
            ae_v_muld(&d->ptr.p_double[l], 1, ae_v_len(l,lend), tmp);
            ae_v_muld(&e->ptr.p_double[l], 1, ae_v_len(l,tmpint), tmp);
        }
        if( ae_fp_less(anorm,ssfmin) )
        {
            iscale = 2;
            tmp = ssfmin/anorm;
            tmpint = lend-1;
            ae_v_muld(&d->ptr.p_double[l], 1, ae_v_len(l,lend), tmp);
            ae_v_muld(&e->ptr.p_double[l], 1, ae_v_len(l,tmpint), tmp);
        }
        
        /*
         * Choose between QL and QR iteration
         */
        if( ae_fp_less(ae_fabs(d->ptr.p_double[lend], _state),ae_fabs(d->ptr.p_double[l], _state)) )
        {
            lend = lsv;
            l = lendsv;
        }
        if( lend>l )
        {
            
            /*
             * QL Iteration
             *
             * Look for small subdiagonal element.
             */
            for(;;)
            {
                gotoflag = ae_false;
                if( l!=lend )
                {
                    lendm1 = lend-1;
                    for(m=l; m<=lendm1; m++)
                    {
                        tst = ae_sqr(ae_fabs(e->ptr.p_double[m], _state), _state);
                        if( ae_fp_less_eq(tst,eps2*ae_fabs(d->ptr.p_double[m], _state)*ae_fabs(d->ptr.p_double[m+1], _state)+safmin) )
                        {
                            gotoflag = ae_true;
                            break;
                        }
                    }
                }
                if( !gotoflag )
                {
                    m = lend;
                }
                if( m<lend )
                {
                    e->ptr.p_double[m] = 0;
                }
                p = d->ptr.p_double[l];
                if( m!=l )
                {
                    
                    /*
                     * If remaining matrix is 2-by-2, use DLAE2 or SLAEV2
                     * to compute its eigensystem.
                     */
                    if( m==l+1 )
                    {
                        if( zneeded>0 )
                        {
                            evd_tdevdev2(d->ptr.p_double[l], e->ptr.p_double[l], d->ptr.p_double[l+1], &rt1, &rt2, &c, &s, _state);
                            work1.ptr.p_double[l] = c;
                            work2.ptr.p_double[l] = s;
                            workc.ptr.p_double[1] = work1.ptr.p_double[l];
                            works.ptr.p_double[1] = work2.ptr.p_double[l];
                            if( !wastranspose )
                            {
                                applyrotationsfromtheright(ae_false, 1, zrows, l, l+1, &workc, &works, z, &wtemp, _state);
                            }
                            else
                            {
                                applyrotationsfromtheleft(ae_false, l, l+1, 1, zrows, &workc, &works, z, &wtemp, _state);
                            }
                        }
                        else
                        {
                            evd_tdevde2(d->ptr.p_double[l], e->ptr.p_double[l], d->ptr.p_double[l+1], &rt1, &rt2, _state);
                        }
                        d->ptr.p_double[l] = rt1;
                        d->ptr.p_double[l+1] = rt2;
                        e->ptr.p_double[l] = 0;
                        l = l+2;
                        if( l<=lend )
                        {
                            continue;
                        }
                        
                        /*
                         * GOTO 140
                         */
                        break;
                    }
                    if( jtot==nmaxit )
                    {
                        
                        /*
                         * GOTO 140
                         */
                        break;
                    }
                    jtot = jtot+1;
                    
                    /*
                     * Form shift.
                     */
                    g = (d->ptr.p_double[l+1]-p)/(2*e->ptr.p_double[l]);
                    r = evd_tdevdpythag(g, 1, _state);
                    g = d->ptr.p_double[m]-p+e->ptr.p_double[l]/(g+evd_tdevdextsign(r, g, _state));
                    s = 1;
                    c = 1;
                    p = 0;
                    
                    /*
                     * Inner loop
                     */
                    mm1 = m-1;
                    for(i=mm1; i>=l; i--)
                    {
                        f = s*e->ptr.p_double[i];
                        b = c*e->ptr.p_double[i];
                        generaterotation(g, f, &c, &s, &r, _state);
                        if( i!=m-1 )
                        {
                            e->ptr.p_double[i+1] = r;
                        }
                        g = d->ptr.p_double[i+1]-p;
                        r = (d->ptr.p_double[i]-g)*s+2*c*b;
                        p = s*r;
                        d->ptr.p_double[i+1] = g+p;
                        g = c*r-b;
                        
                        /*
                         * If eigenvectors are desired, then save rotations.
                         */
                        if( zneeded>0 )
                        {
                            work1.ptr.p_double[i] = c;
                            work2.ptr.p_double[i] = -s;
                        }
                    }
                    
                    /*
                     * If eigenvectors are desired, then apply saved rotations.
                     */
                    if( zneeded>0 )
                    {
                        for(i=l; i<=m-1; i++)
                        {
                            workc.ptr.p_double[i-l+1] = work1.ptr.p_double[i];
                            works.ptr.p_double[i-l+1] = work2.ptr.p_double[i];
                        }
                        if( !wastranspose )
                        {
                            applyrotationsfromtheright(ae_false, 1, zrows, l, m, &workc, &works, z, &wtemp, _state);
                        }
                        else
                        {
                            applyrotationsfromtheleft(ae_false, l, m, 1, zrows, &workc, &works, z, &wtemp, _state);
                        }
                    }
                    d->ptr.p_double[l] = d->ptr.p_double[l]-p;
                    e->ptr.p_double[l] = g;
                    continue;
                }
                
                /*
                 * Eigenvalue found.
                 */
                d->ptr.p_double[l] = p;
                l = l+1;
                if( l<=lend )
                {
                    continue;
                }
                break;
            }
        }
        else
        {
            
            /*
             * QR Iteration
             *
             * Look for small superdiagonal element.
             */
            for(;;)
            {
                gotoflag = ae_false;
                if( l!=lend )
                {
                    lendp1 = lend+1;
                    for(m=l; m>=lendp1; m--)
                    {
                        tst = ae_sqr(ae_fabs(e->ptr.p_double[m-1], _state), _state);
                        if( ae_fp_less_eq(tst,eps2*ae_fabs(d->ptr.p_double[m], _state)*ae_fabs(d->ptr.p_double[m-1], _state)+safmin) )
                        {
                            gotoflag = ae_true;
                            break;
                        }
                    }
                }
                if( !gotoflag )
                {
                    m = lend;
                }
                if( m>lend )
                {
                    e->ptr.p_double[m-1] = 0;
                }
                p = d->ptr.p_double[l];
                if( m!=l )
                {
                    
                    /*
                     * If remaining matrix is 2-by-2, use DLAE2 or SLAEV2
                     * to compute its eigensystem.
                     */
                    if( m==l-1 )
                    {
                        if( zneeded>0 )
                        {
                            evd_tdevdev2(d->ptr.p_double[l-1], e->ptr.p_double[l-1], d->ptr.p_double[l], &rt1, &rt2, &c, &s, _state);
                            work1.ptr.p_double[m] = c;
                            work2.ptr.p_double[m] = s;
                            workc.ptr.p_double[1] = c;
                            works.ptr.p_double[1] = s;
                            if( !wastranspose )
                            {
                                applyrotationsfromtheright(ae_true, 1, zrows, l-1, l, &workc, &works, z, &wtemp, _state);
                            }
                            else
                            {
                                applyrotationsfromtheleft(ae_true, l-1, l, 1, zrows, &workc, &works, z, &wtemp, _state);
                            }
                        }
                        else
                        {
                            evd_tdevde2(d->ptr.p_double[l-1], e->ptr.p_double[l-1], d->ptr.p_double[l], &rt1, &rt2, _state);
                        }
                        d->ptr.p_double[l-1] = rt1;
                        d->ptr.p_double[l] = rt2;
                        e->ptr.p_double[l-1] = 0;
                        l = l-2;
                        if( l>=lend )
                        {
                            continue;
                        }
                        break;
                    }
                    if( jtot==nmaxit )
                    {
                        break;
                    }
                    jtot = jtot+1;
                    
                    /*
                     * Form shift.
                     */
                    g = (d->ptr.p_double[l-1]-p)/(2*e->ptr.p_double[l-1]);
                    r = evd_tdevdpythag(g, 1, _state);
                    g = d->ptr.p_double[m]-p+e->ptr.p_double[l-1]/(g+evd_tdevdextsign(r, g, _state));
                    s = 1;
                    c = 1;
                    p = 0;
                    
                    /*
                     * Inner loop
                     */
                    lm1 = l-1;
                    for(i=m; i<=lm1; i++)
                    {
                        f = s*e->ptr.p_double[i];
                        b = c*e->ptr.p_double[i];
                        generaterotation(g, f, &c, &s, &r, _state);
                        if( i!=m )
                        {
                            e->ptr.p_double[i-1] = r;
                        }
                        g = d->ptr.p_double[i]-p;
                        r = (d->ptr.p_double[i+1]-g)*s+2*c*b;
                        p = s*r;
                        d->ptr.p_double[i] = g+p;
                        g = c*r-b;
                        
                        /*
                         * If eigenvectors are desired, then save rotations.
                         */
                        if( zneeded>0 )
                        {
                            work1.ptr.p_double[i] = c;
                            work2.ptr.p_double[i] = s;
                        }
                    }
                    
                    /*
                     * If eigenvectors are desired, then apply saved rotations.
                     */
                    if( zneeded>0 )
                    {
                        mm = l-m+1;
                        for(i=m; i<=l-1; i++)
                        {
                            workc.ptr.p_double[i-m+1] = work1.ptr.p_double[i];
                            works.ptr.p_double[i-m+1] = work2.ptr.p_double[i];
                        }
                        if( !wastranspose )
                        {
                            applyrotationsfromtheright(ae_true, 1, zrows, m, l, &workc, &works, z, &wtemp, _state);
                        }
                        else
                        {
                            applyrotationsfromtheleft(ae_true, m, l, 1, zrows, &workc, &works, z, &wtemp, _state);
                        }
                    }
                    d->ptr.p_double[l] = d->ptr.p_double[l]-p;
                    e->ptr.p_double[lm1] = g;
                    continue;
                }
                
                /*
                 * Eigenvalue found.
                 */
                d->ptr.p_double[l] = p;
                l = l-1;
                if( l>=lend )
                {
                    continue;
                }
                break;
            }
        }
        
        /*
         * Undo scaling if necessary
         */
        if( iscale==1 )
        {
            tmp = anorm/ssfmax;
            tmpint = lendsv-1;
            ae_v_muld(&d->ptr.p_double[lsv], 1, ae_v_len(lsv,lendsv), tmp);
            ae_v_muld(&e->ptr.p_double[lsv], 1, ae_v_len(lsv,tmpint), tmp);
        }
        if( iscale==2 )
        {
            tmp = anorm/ssfmin;
            tmpint = lendsv-1;
            ae_v_muld(&d->ptr.p_double[lsv], 1, ae_v_len(lsv,lendsv), tmp);
            ae_v_muld(&e->ptr.p_double[lsv], 1, ae_v_len(lsv,tmpint), tmp);
        }
        
        /*
         * Check for no convergence to an eigenvalue after a total
         * of N*MAXIT iterations.
         */
        if( jtot>=nmaxit )
        {
            result = ae_false;
            if( wastranspose )
            {
                inplacetranspose(z, 1, n, 1, n, &wtemp, _state);
            }
            ae_frame_leave(_state);
            return result;
        }
    }
    
    /*
     * Order eigenvalues and eigenvectors.
     */
    if( zneeded==0 )
    {
        
        /*
         * Sort
         */
        if( n==1 )
        {
            ae_frame_leave(_state);
            return result;
        }
        if( n==2 )
        {
            if( ae_fp_greater(d->ptr.p_double[1],d->ptr.p_double[2]) )
            {
                tmp = d->ptr.p_double[1];
                d->ptr.p_double[1] = d->ptr.p_double[2];
                d->ptr.p_double[2] = tmp;
            }
            ae_frame_leave(_state);
            return result;
        }
        i = 2;
        do
        {
            t = i;
            while(t!=1)
            {
                k = t/2;
                if( ae_fp_greater_eq(d->ptr.p_double[k],d->ptr.p_double[t]) )
                {
                    t = 1;
                }
                else
                {
                    tmp = d->ptr.p_double[k];
                    d->ptr.p_double[k] = d->ptr.p_double[t];
                    d->ptr.p_double[t] = tmp;
                    t = k;
                }
            }
            i = i+1;
        }
        while(i<=n);
        i = n-1;
        do
        {
            tmp = d->ptr.p_double[i+1];
            d->ptr.p_double[i+1] = d->ptr.p_double[1];
            d->ptr.p_double[1] = tmp;
            t = 1;
            while(t!=0)
            {
                k = 2*t;
                if( k>i )
                {
                    t = 0;
                }
                else
                {
                    if( k<i )
                    {
                        if( ae_fp_greater(d->ptr.p_double[k+1],d->ptr.p_double[k]) )
                        {
                            k = k+1;
                        }
                    }
                    if( ae_fp_greater_eq(d->ptr.p_double[t],d->ptr.p_double[k]) )
                    {
                        t = 0;
                    }
                    else
                    {
                        tmp = d->ptr.p_double[k];
                        d->ptr.p_double[k] = d->ptr.p_double[t];
                        d->ptr.p_double[t] = tmp;
                        t = k;
                    }
                }
            }
            i = i-1;
        }
        while(i>=1);
    }
    else
    {
        
        /*
         * Use Selection Sort to minimize swaps of eigenvectors
         */
        for(ii=2; ii<=n; ii++)
        {
            i = ii-1;
            k = i;
            p = d->ptr.p_double[i];
            for(j=ii; j<=n; j++)
            {
                if( ae_fp_less(d->ptr.p_double[j],p) )
                {
                    k = j;
                    p = d->ptr.p_double[j];
                }
            }
            if( k!=i )
            {
                d->ptr.p_double[k] = d->ptr.p_double[i];
                d->ptr.p_double[i] = p;
                if( wastranspose )
                {
                    ae_v_move(&wtemp.ptr.p_double[1], 1, &z->ptr.pp_double[i][1], 1, ae_v_len(1,n));
                    ae_v_move(&z->ptr.pp_double[i][1], 1, &z->ptr.pp_double[k][1], 1, ae_v_len(1,n));
                    ae_v_move(&z->ptr.pp_double[k][1], 1, &wtemp.ptr.p_double[1], 1, ae_v_len(1,n));
                }
                else
                {
                    ae_v_move(&wtemp.ptr.p_double[1], 1, &z->ptr.pp_double[1][i], z->stride, ae_v_len(1,zrows));
                    ae_v_move(&z->ptr.pp_double[1][i], z->stride, &z->ptr.pp_double[1][k], z->stride, ae_v_len(1,zrows));
                    ae_v_move(&z->ptr.pp_double[1][k], z->stride, &wtemp.ptr.p_double[1], 1, ae_v_len(1,zrows));
                }
            }
        }
        if( wastranspose )
        {
            inplacetranspose(z, 1, n, 1, n, &wtemp, _state);
        }
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
DLAE2  computes the eigenvalues of a 2-by-2 symmetric matrix
   [  A   B  ]
   [  B   C  ].
On return, RT1 is the eigenvalue of larger absolute value, and RT2
is the eigenvalue of smaller absolute value.

  -- LAPACK auxiliary routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
static void evd_tdevde2(double a,
     double b,
     double c,
     double* rt1,
     double* rt2,
     ae_state *_state)
{
    double ab;
    double acmn;
    double acmx;
    double adf;
    double df;
    double rt;
    double sm;
    double tb;

    *rt1 = 0;
    *rt2 = 0;

    sm = a+c;
    df = a-c;
    adf = ae_fabs(df, _state);
    tb = b+b;
    ab = ae_fabs(tb, _state);
    if( ae_fp_greater(ae_fabs(a, _state),ae_fabs(c, _state)) )
    {
        acmx = a;
        acmn = c;
    }
    else
    {
        acmx = c;
        acmn = a;
    }
    if( ae_fp_greater(adf,ab) )
    {
        rt = adf*ae_sqrt(1+ae_sqr(ab/adf, _state), _state);
    }
    else
    {
        if( ae_fp_less(adf,ab) )
        {
            rt = ab*ae_sqrt(1+ae_sqr(adf/ab, _state), _state);
        }
        else
        {
            
            /*
             * Includes case AB=ADF=0
             */
            rt = ab*ae_sqrt(2, _state);
        }
    }
    if( ae_fp_less(sm,0) )
    {
        *rt1 = 0.5*(sm-rt);
        
        /*
         * Order of execution important.
         * To get fully accurate smaller eigenvalue,
         * next line needs to be executed in higher precision.
         */
        *rt2 = acmx/(*rt1)*acmn-b/(*rt1)*b;
    }
    else
    {
        if( ae_fp_greater(sm,0) )
        {
            *rt1 = 0.5*(sm+rt);
            
            /*
             * Order of execution important.
             * To get fully accurate smaller eigenvalue,
             * next line needs to be executed in higher precision.
             */
            *rt2 = acmx/(*rt1)*acmn-b/(*rt1)*b;
        }
        else
        {
            
            /*
             * Includes case RT1 = RT2 = 0
             */
            *rt1 = 0.5*rt;
            *rt2 = -0.5*rt;
        }
    }
}


/*************************************************************************
DLAEV2 computes the eigendecomposition of a 2-by-2 symmetric matrix

   [  A   B  ]
   [  B   C  ].

On return, RT1 is the eigenvalue of larger absolute value, RT2 is the
eigenvalue of smaller absolute value, and (CS1,SN1) is the unit right
eigenvector for RT1, giving the decomposition

   [ CS1  SN1 ] [  A   B  ] [ CS1 -SN1 ]  =  [ RT1  0  ]
   [-SN1  CS1 ] [  B   C  ] [ SN1  CS1 ]     [  0  RT2 ].


  -- LAPACK auxiliary routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
static void evd_tdevdev2(double a,
     double b,
     double c,
     double* rt1,
     double* rt2,
     double* cs1,
     double* sn1,
     ae_state *_state)
{
    ae_int_t sgn1;
    ae_int_t sgn2;
    double ab;
    double acmn;
    double acmx;
    double acs;
    double adf;
    double cs;
    double ct;
    double df;
    double rt;
    double sm;
    double tb;
    double tn;

    *rt1 = 0;
    *rt2 = 0;
    *cs1 = 0;
    *sn1 = 0;

    
    /*
     * Compute the eigenvalues
     */
    sm = a+c;
    df = a-c;
    adf = ae_fabs(df, _state);
    tb = b+b;
    ab = ae_fabs(tb, _state);
    if( ae_fp_greater(ae_fabs(a, _state),ae_fabs(c, _state)) )
    {
        acmx = a;
        acmn = c;
    }
    else
    {
        acmx = c;
        acmn = a;
    }
    if( ae_fp_greater(adf,ab) )
    {
        rt = adf*ae_sqrt(1+ae_sqr(ab/adf, _state), _state);
    }
    else
    {
        if( ae_fp_less(adf,ab) )
        {
            rt = ab*ae_sqrt(1+ae_sqr(adf/ab, _state), _state);
        }
        else
        {
            
            /*
             * Includes case AB=ADF=0
             */
            rt = ab*ae_sqrt(2, _state);
        }
    }
    if( ae_fp_less(sm,0) )
    {
        *rt1 = 0.5*(sm-rt);
        sgn1 = -1;
        
        /*
         * Order of execution important.
         * To get fully accurate smaller eigenvalue,
         * next line needs to be executed in higher precision.
         */
        *rt2 = acmx/(*rt1)*acmn-b/(*rt1)*b;
    }
    else
    {
        if( ae_fp_greater(sm,0) )
        {
            *rt1 = 0.5*(sm+rt);
            sgn1 = 1;
            
            /*
             * Order of execution important.
             * To get fully accurate smaller eigenvalue,
             * next line needs to be executed in higher precision.
             */
            *rt2 = acmx/(*rt1)*acmn-b/(*rt1)*b;
        }
        else
        {
            
            /*
             * Includes case RT1 = RT2 = 0
             */
            *rt1 = 0.5*rt;
            *rt2 = -0.5*rt;
            sgn1 = 1;
        }
    }
    
    /*
     * Compute the eigenvector
     */
    if( ae_fp_greater_eq(df,0) )
    {
        cs = df+rt;
        sgn2 = 1;
    }
    else
    {
        cs = df-rt;
        sgn2 = -1;
    }
    acs = ae_fabs(cs, _state);
    if( ae_fp_greater(acs,ab) )
    {
        ct = -tb/cs;
        *sn1 = 1/ae_sqrt(1+ct*ct, _state);
        *cs1 = ct*(*sn1);
    }
    else
    {
        if( ae_fp_eq(ab,0) )
        {
            *cs1 = 1;
            *sn1 = 0;
        }
        else
        {
            tn = -cs/tb;
            *cs1 = 1/ae_sqrt(1+tn*tn, _state);
            *sn1 = tn*(*cs1);
        }
    }
    if( sgn1==sgn2 )
    {
        tn = *cs1;
        *cs1 = -*sn1;
        *sn1 = tn;
    }
}


/*************************************************************************
Internal routine
*************************************************************************/
static double evd_tdevdpythag(double a, double b, ae_state *_state)
{
    double result;


    if( ae_fp_less(ae_fabs(a, _state),ae_fabs(b, _state)) )
    {
        result = ae_fabs(b, _state)*ae_sqrt(1+ae_sqr(a/b, _state), _state);
    }
    else
    {
        result = ae_fabs(a, _state)*ae_sqrt(1+ae_sqr(b/a, _state), _state);
    }
    return result;
}


/*************************************************************************
Internal routine
*************************************************************************/
static double evd_tdevdextsign(double a, double b, ae_state *_state)
{
    double result;


    if( ae_fp_greater_eq(b,0) )
    {
        result = ae_fabs(a, _state);
    }
    else
    {
        result = -ae_fabs(a, _state);
    }
    return result;
}


static ae_bool evd_internalbisectioneigenvalues(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t irange,
     ae_int_t iorder,
     double vl,
     double vu,
     ae_int_t il,
     ae_int_t iu,
     double abstol,
     /* Real    */ ae_vector* w,
     ae_int_t* m,
     ae_int_t* nsplit,
     /* Integer */ ae_vector* iblock,
     /* Integer */ ae_vector* isplit,
     ae_int_t* errorcode,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _d;
    ae_vector _e;
    double fudge;
    double relfac;
    ae_bool ncnvrg;
    ae_bool toofew;
    ae_int_t ib;
    ae_int_t ibegin;
    ae_int_t idiscl;
    ae_int_t idiscu;
    ae_int_t ie;
    ae_int_t iend;
    ae_int_t iinfo;
    ae_int_t im;
    ae_int_t iin;
    ae_int_t ioff;
    ae_int_t iout;
    ae_int_t itmax;
    ae_int_t iw;
    ae_int_t iwoff;
    ae_int_t j;
    ae_int_t itmp1;
    ae_int_t jb;
    ae_int_t jdisc;
    ae_int_t je;
    ae_int_t nwl;
    ae_int_t nwu;
    double atoli;
    double bnorm;
    double gl;
    double gu;
    double pivmin;
    double rtoli;
    double safemn;
    double tmp1;
    double tmp2;
    double tnorm;
    double ulp;
    double wkill;
    double wl;
    double wlu;
    double wu;
    double wul;
    double scalefactor;
    double t;
    ae_vector idumma;
    ae_vector work;
    ae_vector iwork;
    ae_vector ia1s2;
    ae_vector ra1s2;
    ae_matrix ra1s2x2;
    ae_matrix ia1s2x2;
    ae_vector ra1siin;
    ae_vector ra2siin;
    ae_vector ra3siin;
    ae_vector ra4siin;
    ae_matrix ra1siinx2;
    ae_matrix ia1siinx2;
    ae_vector iworkspace;
    ae_vector rworkspace;
    ae_int_t tmpi;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_d, d, _state, ae_true);
    d = &_d;
    ae_vector_init_copy(&_e, e, _state, ae_true);
    e = &_e;
    ae_vector_clear(w);
    *m = 0;
    *nsplit = 0;
    ae_vector_clear(iblock);
    ae_vector_clear(isplit);
    *errorcode = 0;
    ae_vector_init(&idumma, 0, DT_INT, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&iwork, 0, DT_INT, _state, ae_true);
    ae_vector_init(&ia1s2, 0, DT_INT, _state, ae_true);
    ae_vector_init(&ra1s2, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&ra1s2x2, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&ia1s2x2, 0, 0, DT_INT, _state, ae_true);
    ae_vector_init(&ra1siin, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ra2siin, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ra3siin, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ra4siin, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&ra1siinx2, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&ia1siinx2, 0, 0, DT_INT, _state, ae_true);
    ae_vector_init(&iworkspace, 0, DT_INT, _state, ae_true);
    ae_vector_init(&rworkspace, 0, DT_REAL, _state, ae_true);

    
    /*
     * Quick return if possible
     */
    *m = 0;
    if( n==0 )
    {
        result = ae_true;
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Get machine constants
     * NB is the minimum vector length for vector bisection, or 0
     * if only scalar is to be done.
     */
    fudge = 2;
    relfac = 2;
    safemn = ae_minrealnumber;
    ulp = 2*ae_machineepsilon;
    rtoli = ulp*relfac;
    ae_vector_set_length(&idumma, 1+1, _state);
    ae_vector_set_length(&work, 4*n+1, _state);
    ae_vector_set_length(&iwork, 3*n+1, _state);
    ae_vector_set_length(w, n+1, _state);
    ae_vector_set_length(iblock, n+1, _state);
    ae_vector_set_length(isplit, n+1, _state);
    ae_vector_set_length(&ia1s2, 2+1, _state);
    ae_vector_set_length(&ra1s2, 2+1, _state);
    ae_matrix_set_length(&ra1s2x2, 2+1, 2+1, _state);
    ae_matrix_set_length(&ia1s2x2, 2+1, 2+1, _state);
    ae_vector_set_length(&ra1siin, n+1, _state);
    ae_vector_set_length(&ra2siin, n+1, _state);
    ae_vector_set_length(&ra3siin, n+1, _state);
    ae_vector_set_length(&ra4siin, n+1, _state);
    ae_matrix_set_length(&ra1siinx2, n+1, 2+1, _state);
    ae_matrix_set_length(&ia1siinx2, n+1, 2+1, _state);
    ae_vector_set_length(&iworkspace, n+1, _state);
    ae_vector_set_length(&rworkspace, n+1, _state);
    
    /*
     * these initializers are not really necessary,
     * but without them compiler complains about uninitialized locals
     */
    wlu = 0;
    wul = 0;
    
    /*
     * Check for Errors
     */
    result = ae_false;
    *errorcode = 0;
    if( irange<=0||irange>=4 )
    {
        *errorcode = -4;
    }
    if( iorder<=0||iorder>=3 )
    {
        *errorcode = -5;
    }
    if( n<0 )
    {
        *errorcode = -3;
    }
    if( irange==2&&ae_fp_greater_eq(vl,vu) )
    {
        *errorcode = -6;
    }
    if( irange==3&&(il<1||il>ae_maxint(1, n, _state)) )
    {
        *errorcode = -8;
    }
    if( irange==3&&(iu<ae_minint(n, il, _state)||iu>n) )
    {
        *errorcode = -9;
    }
    if( *errorcode!=0 )
    {
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Initialize error flags
     */
    ncnvrg = ae_false;
    toofew = ae_false;
    
    /*
     * Simplifications:
     */
    if( (irange==3&&il==1)&&iu==n )
    {
        irange = 1;
    }
    
    /*
     * Special Case when N=1
     */
    if( n==1 )
    {
        *nsplit = 1;
        isplit->ptr.p_int[1] = 1;
        if( irange==2&&(ae_fp_greater_eq(vl,d->ptr.p_double[1])||ae_fp_less(vu,d->ptr.p_double[1])) )
        {
            *m = 0;
        }
        else
        {
            w->ptr.p_double[1] = d->ptr.p_double[1];
            iblock->ptr.p_int[1] = 1;
            *m = 1;
        }
        result = ae_true;
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Scaling
     */
    t = ae_fabs(d->ptr.p_double[n], _state);
    for(j=1; j<=n-1; j++)
    {
        t = ae_maxreal(t, ae_fabs(d->ptr.p_double[j], _state), _state);
        t = ae_maxreal(t, ae_fabs(e->ptr.p_double[j], _state), _state);
    }
    scalefactor = 1;
    if( ae_fp_neq(t,0) )
    {
        if( ae_fp_greater(t,ae_sqrt(ae_sqrt(ae_minrealnumber, _state), _state)*ae_sqrt(ae_maxrealnumber, _state)) )
        {
            scalefactor = t;
        }
        if( ae_fp_less(t,ae_sqrt(ae_sqrt(ae_maxrealnumber, _state), _state)*ae_sqrt(ae_minrealnumber, _state)) )
        {
            scalefactor = t;
        }
        for(j=1; j<=n-1; j++)
        {
            d->ptr.p_double[j] = d->ptr.p_double[j]/scalefactor;
            e->ptr.p_double[j] = e->ptr.p_double[j]/scalefactor;
        }
        d->ptr.p_double[n] = d->ptr.p_double[n]/scalefactor;
    }
    
    /*
     * Compute Splitting Points
     */
    *nsplit = 1;
    work.ptr.p_double[n] = 0;
    pivmin = 1;
    for(j=2; j<=n; j++)
    {
        tmp1 = ae_sqr(e->ptr.p_double[j-1], _state);
        if( ae_fp_greater(ae_fabs(d->ptr.p_double[j]*d->ptr.p_double[j-1], _state)*ae_sqr(ulp, _state)+safemn,tmp1) )
        {
            isplit->ptr.p_int[*nsplit] = j-1;
            *nsplit = *nsplit+1;
            work.ptr.p_double[j-1] = 0;
        }
        else
        {
            work.ptr.p_double[j-1] = tmp1;
            pivmin = ae_maxreal(pivmin, tmp1, _state);
        }
    }
    isplit->ptr.p_int[*nsplit] = n;
    pivmin = pivmin*safemn;
    
    /*
     * Compute Interval and ATOLI
     */
    if( irange==3 )
    {
        
        /*
         * RANGE='I': Compute the interval containing eigenvalues
         *     IL through IU.
         *
         * Compute Gershgorin interval for entire (split) matrix
         * and use it as the initial interval
         */
        gu = d->ptr.p_double[1];
        gl = d->ptr.p_double[1];
        tmp1 = 0;
        for(j=1; j<=n-1; j++)
        {
            tmp2 = ae_sqrt(work.ptr.p_double[j], _state);
            gu = ae_maxreal(gu, d->ptr.p_double[j]+tmp1+tmp2, _state);
            gl = ae_minreal(gl, d->ptr.p_double[j]-tmp1-tmp2, _state);
            tmp1 = tmp2;
        }
        gu = ae_maxreal(gu, d->ptr.p_double[n]+tmp1, _state);
        gl = ae_minreal(gl, d->ptr.p_double[n]-tmp1, _state);
        tnorm = ae_maxreal(ae_fabs(gl, _state), ae_fabs(gu, _state), _state);
        gl = gl-fudge*tnorm*ulp*n-fudge*2*pivmin;
        gu = gu+fudge*tnorm*ulp*n+fudge*pivmin;
        
        /*
         * Compute Iteration parameters
         */
        itmax = ae_iceil((ae_log(tnorm+pivmin, _state)-ae_log(pivmin, _state))/ae_log(2, _state), _state)+2;
        if( ae_fp_less_eq(abstol,0) )
        {
            atoli = ulp*tnorm;
        }
        else
        {
            atoli = abstol;
        }
        work.ptr.p_double[n+1] = gl;
        work.ptr.p_double[n+2] = gl;
        work.ptr.p_double[n+3] = gu;
        work.ptr.p_double[n+4] = gu;
        work.ptr.p_double[n+5] = gl;
        work.ptr.p_double[n+6] = gu;
        iwork.ptr.p_int[1] = -1;
        iwork.ptr.p_int[2] = -1;
        iwork.ptr.p_int[3] = n+1;
        iwork.ptr.p_int[4] = n+1;
        iwork.ptr.p_int[5] = il-1;
        iwork.ptr.p_int[6] = iu;
        
        /*
         * Calling DLAEBZ
         *
         * DLAEBZ( 3, ITMAX, N, 2, 2, NB, ATOLI, RTOLI, PIVMIN, D, E,
         *    WORK, IWORK( 5 ), WORK( N+1 ), WORK( N+5 ), IOUT,
         *    IWORK, W, IBLOCK, IINFO )
         */
        ia1s2.ptr.p_int[1] = iwork.ptr.p_int[5];
        ia1s2.ptr.p_int[2] = iwork.ptr.p_int[6];
        ra1s2.ptr.p_double[1] = work.ptr.p_double[n+5];
        ra1s2.ptr.p_double[2] = work.ptr.p_double[n+6];
        ra1s2x2.ptr.pp_double[1][1] = work.ptr.p_double[n+1];
        ra1s2x2.ptr.pp_double[2][1] = work.ptr.p_double[n+2];
        ra1s2x2.ptr.pp_double[1][2] = work.ptr.p_double[n+3];
        ra1s2x2.ptr.pp_double[2][2] = work.ptr.p_double[n+4];
        ia1s2x2.ptr.pp_int[1][1] = iwork.ptr.p_int[1];
        ia1s2x2.ptr.pp_int[2][1] = iwork.ptr.p_int[2];
        ia1s2x2.ptr.pp_int[1][2] = iwork.ptr.p_int[3];
        ia1s2x2.ptr.pp_int[2][2] = iwork.ptr.p_int[4];
        evd_internaldlaebz(3, itmax, n, 2, 2, atoli, rtoli, pivmin, d, e, &work, &ia1s2, &ra1s2x2, &ra1s2, &iout, &ia1s2x2, w, iblock, &iinfo, _state);
        iwork.ptr.p_int[5] = ia1s2.ptr.p_int[1];
        iwork.ptr.p_int[6] = ia1s2.ptr.p_int[2];
        work.ptr.p_double[n+5] = ra1s2.ptr.p_double[1];
        work.ptr.p_double[n+6] = ra1s2.ptr.p_double[2];
        work.ptr.p_double[n+1] = ra1s2x2.ptr.pp_double[1][1];
        work.ptr.p_double[n+2] = ra1s2x2.ptr.pp_double[2][1];
        work.ptr.p_double[n+3] = ra1s2x2.ptr.pp_double[1][2];
        work.ptr.p_double[n+4] = ra1s2x2.ptr.pp_double[2][2];
        iwork.ptr.p_int[1] = ia1s2x2.ptr.pp_int[1][1];
        iwork.ptr.p_int[2] = ia1s2x2.ptr.pp_int[2][1];
        iwork.ptr.p_int[3] = ia1s2x2.ptr.pp_int[1][2];
        iwork.ptr.p_int[4] = ia1s2x2.ptr.pp_int[2][2];
        if( iwork.ptr.p_int[6]==iu )
        {
            wl = work.ptr.p_double[n+1];
            wlu = work.ptr.p_double[n+3];
            nwl = iwork.ptr.p_int[1];
            wu = work.ptr.p_double[n+4];
            wul = work.ptr.p_double[n+2];
            nwu = iwork.ptr.p_int[4];
        }
        else
        {
            wl = work.ptr.p_double[n+2];
            wlu = work.ptr.p_double[n+4];
            nwl = iwork.ptr.p_int[2];
            wu = work.ptr.p_double[n+3];
            wul = work.ptr.p_double[n+1];
            nwu = iwork.ptr.p_int[3];
        }
        if( ((nwl<0||nwl>=n)||nwu<1)||nwu>n )
        {
            *errorcode = 4;
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
    }
    else
    {
        
        /*
         * RANGE='A' or 'V' -- Set ATOLI
         */
        tnorm = ae_maxreal(ae_fabs(d->ptr.p_double[1], _state)+ae_fabs(e->ptr.p_double[1], _state), ae_fabs(d->ptr.p_double[n], _state)+ae_fabs(e->ptr.p_double[n-1], _state), _state);
        for(j=2; j<=n-1; j++)
        {
            tnorm = ae_maxreal(tnorm, ae_fabs(d->ptr.p_double[j], _state)+ae_fabs(e->ptr.p_double[j-1], _state)+ae_fabs(e->ptr.p_double[j], _state), _state);
        }
        if( ae_fp_less_eq(abstol,0) )
        {
            atoli = ulp*tnorm;
        }
        else
        {
            atoli = abstol;
        }
        if( irange==2 )
        {
            wl = vl;
            wu = vu;
        }
        else
        {
            wl = 0;
            wu = 0;
        }
    }
    
    /*
     * Find Eigenvalues -- Loop Over Blocks and recompute NWL and NWU.
     * NWL accumulates the number of eigenvalues .le. WL,
     * NWU accumulates the number of eigenvalues .le. WU
     */
    *m = 0;
    iend = 0;
    *errorcode = 0;
    nwl = 0;
    nwu = 0;
    for(jb=1; jb<=*nsplit; jb++)
    {
        ioff = iend;
        ibegin = ioff+1;
        iend = isplit->ptr.p_int[jb];
        iin = iend-ioff;
        if( iin==1 )
        {
            
            /*
             * Special Case -- IIN=1
             */
            if( irange==1||ae_fp_greater_eq(wl,d->ptr.p_double[ibegin]-pivmin) )
            {
                nwl = nwl+1;
            }
            if( irange==1||ae_fp_greater_eq(wu,d->ptr.p_double[ibegin]-pivmin) )
            {
                nwu = nwu+1;
            }
            if( irange==1||(ae_fp_less(wl,d->ptr.p_double[ibegin]-pivmin)&&ae_fp_greater_eq(wu,d->ptr.p_double[ibegin]-pivmin)) )
            {
                *m = *m+1;
                w->ptr.p_double[*m] = d->ptr.p_double[ibegin];
                iblock->ptr.p_int[*m] = jb;
            }
        }
        else
        {
            
            /*
             * General Case -- IIN > 1
             *
             * Compute Gershgorin Interval
             * and use it as the initial interval
             */
            gu = d->ptr.p_double[ibegin];
            gl = d->ptr.p_double[ibegin];
            tmp1 = 0;
            for(j=ibegin; j<=iend-1; j++)
            {
                tmp2 = ae_fabs(e->ptr.p_double[j], _state);
                gu = ae_maxreal(gu, d->ptr.p_double[j]+tmp1+tmp2, _state);
                gl = ae_minreal(gl, d->ptr.p_double[j]-tmp1-tmp2, _state);
                tmp1 = tmp2;
            }
            gu = ae_maxreal(gu, d->ptr.p_double[iend]+tmp1, _state);
            gl = ae_minreal(gl, d->ptr.p_double[iend]-tmp1, _state);
            bnorm = ae_maxreal(ae_fabs(gl, _state), ae_fabs(gu, _state), _state);
            gl = gl-fudge*bnorm*ulp*iin-fudge*pivmin;
            gu = gu+fudge*bnorm*ulp*iin+fudge*pivmin;
            
            /*
             * Compute ATOLI for the current submatrix
             */
            if( ae_fp_less_eq(abstol,0) )
            {
                atoli = ulp*ae_maxreal(ae_fabs(gl, _state), ae_fabs(gu, _state), _state);
            }
            else
            {
                atoli = abstol;
            }
            if( irange>1 )
            {
                if( ae_fp_less(gu,wl) )
                {
                    nwl = nwl+iin;
                    nwu = nwu+iin;
                    continue;
                }
                gl = ae_maxreal(gl, wl, _state);
                gu = ae_minreal(gu, wu, _state);
                if( ae_fp_greater_eq(gl,gu) )
                {
                    continue;
                }
            }
            
            /*
             * Set Up Initial Interval
             */
            work.ptr.p_double[n+1] = gl;
            work.ptr.p_double[n+iin+1] = gu;
            
            /*
             * Calling DLAEBZ
             *
             * CALL DLAEBZ( 1, 0, IN, IN, 1, NB, ATOLI, RTOLI, PIVMIN,
             *    D( IBEGIN ), E( IBEGIN ), WORK( IBEGIN ),
             *    IDUMMA, WORK( N+1 ), WORK( N+2*IN+1 ), IM,
             *    IWORK, W( M+1 ), IBLOCK( M+1 ), IINFO )
             */
            for(tmpi=1; tmpi<=iin; tmpi++)
            {
                ra1siin.ptr.p_double[tmpi] = d->ptr.p_double[ibegin-1+tmpi];
                if( ibegin-1+tmpi<n )
                {
                    ra2siin.ptr.p_double[tmpi] = e->ptr.p_double[ibegin-1+tmpi];
                }
                ra3siin.ptr.p_double[tmpi] = work.ptr.p_double[ibegin-1+tmpi];
                ra1siinx2.ptr.pp_double[tmpi][1] = work.ptr.p_double[n+tmpi];
                ra1siinx2.ptr.pp_double[tmpi][2] = work.ptr.p_double[n+tmpi+iin];
                ra4siin.ptr.p_double[tmpi] = work.ptr.p_double[n+2*iin+tmpi];
                rworkspace.ptr.p_double[tmpi] = w->ptr.p_double[*m+tmpi];
                iworkspace.ptr.p_int[tmpi] = iblock->ptr.p_int[*m+tmpi];
                ia1siinx2.ptr.pp_int[tmpi][1] = iwork.ptr.p_int[tmpi];
                ia1siinx2.ptr.pp_int[tmpi][2] = iwork.ptr.p_int[tmpi+iin];
            }
            evd_internaldlaebz(1, 0, iin, iin, 1, atoli, rtoli, pivmin, &ra1siin, &ra2siin, &ra3siin, &idumma, &ra1siinx2, &ra4siin, &im, &ia1siinx2, &rworkspace, &iworkspace, &iinfo, _state);
            for(tmpi=1; tmpi<=iin; tmpi++)
            {
                work.ptr.p_double[n+tmpi] = ra1siinx2.ptr.pp_double[tmpi][1];
                work.ptr.p_double[n+tmpi+iin] = ra1siinx2.ptr.pp_double[tmpi][2];
                work.ptr.p_double[n+2*iin+tmpi] = ra4siin.ptr.p_double[tmpi];
                w->ptr.p_double[*m+tmpi] = rworkspace.ptr.p_double[tmpi];
                iblock->ptr.p_int[*m+tmpi] = iworkspace.ptr.p_int[tmpi];
                iwork.ptr.p_int[tmpi] = ia1siinx2.ptr.pp_int[tmpi][1];
                iwork.ptr.p_int[tmpi+iin] = ia1siinx2.ptr.pp_int[tmpi][2];
            }
            nwl = nwl+iwork.ptr.p_int[1];
            nwu = nwu+iwork.ptr.p_int[iin+1];
            iwoff = *m-iwork.ptr.p_int[1];
            
            /*
             * Compute Eigenvalues
             */
            itmax = ae_iceil((ae_log(gu-gl+pivmin, _state)-ae_log(pivmin, _state))/ae_log(2, _state), _state)+2;
            
            /*
             * Calling DLAEBZ
             *
             *CALL DLAEBZ( 2, ITMAX, IN, IN, 1, NB, ATOLI, RTOLI, PIVMIN,
             *    D( IBEGIN ), E( IBEGIN ), WORK( IBEGIN ),
             *    IDUMMA, WORK( N+1 ), WORK( N+2*IN+1 ), IOUT,
             *    IWORK, W( M+1 ), IBLOCK( M+1 ), IINFO )
             */
            for(tmpi=1; tmpi<=iin; tmpi++)
            {
                ra1siin.ptr.p_double[tmpi] = d->ptr.p_double[ibegin-1+tmpi];
                if( ibegin-1+tmpi<n )
                {
                    ra2siin.ptr.p_double[tmpi] = e->ptr.p_double[ibegin-1+tmpi];
                }
                ra3siin.ptr.p_double[tmpi] = work.ptr.p_double[ibegin-1+tmpi];
                ra1siinx2.ptr.pp_double[tmpi][1] = work.ptr.p_double[n+tmpi];
                ra1siinx2.ptr.pp_double[tmpi][2] = work.ptr.p_double[n+tmpi+iin];
                ra4siin.ptr.p_double[tmpi] = work.ptr.p_double[n+2*iin+tmpi];
                rworkspace.ptr.p_double[tmpi] = w->ptr.p_double[*m+tmpi];
                iworkspace.ptr.p_int[tmpi] = iblock->ptr.p_int[*m+tmpi];
                ia1siinx2.ptr.pp_int[tmpi][1] = iwork.ptr.p_int[tmpi];
                ia1siinx2.ptr.pp_int[tmpi][2] = iwork.ptr.p_int[tmpi+iin];
            }
            evd_internaldlaebz(2, itmax, iin, iin, 1, atoli, rtoli, pivmin, &ra1siin, &ra2siin, &ra3siin, &idumma, &ra1siinx2, &ra4siin, &iout, &ia1siinx2, &rworkspace, &iworkspace, &iinfo, _state);
            for(tmpi=1; tmpi<=iin; tmpi++)
            {
                work.ptr.p_double[n+tmpi] = ra1siinx2.ptr.pp_double[tmpi][1];
                work.ptr.p_double[n+tmpi+iin] = ra1siinx2.ptr.pp_double[tmpi][2];
                work.ptr.p_double[n+2*iin+tmpi] = ra4siin.ptr.p_double[tmpi];
                w->ptr.p_double[*m+tmpi] = rworkspace.ptr.p_double[tmpi];
                iblock->ptr.p_int[*m+tmpi] = iworkspace.ptr.p_int[tmpi];
                iwork.ptr.p_int[tmpi] = ia1siinx2.ptr.pp_int[tmpi][1];
                iwork.ptr.p_int[tmpi+iin] = ia1siinx2.ptr.pp_int[tmpi][2];
            }
            
            /*
             * Copy Eigenvalues Into W and IBLOCK
             * Use -JB for block number for unconverged eigenvalues.
             */
            for(j=1; j<=iout; j++)
            {
                tmp1 = 0.5*(work.ptr.p_double[j+n]+work.ptr.p_double[j+iin+n]);
                
                /*
                 * Flag non-convergence.
                 */
                if( j>iout-iinfo )
                {
                    ncnvrg = ae_true;
                    ib = -jb;
                }
                else
                {
                    ib = jb;
                }
                for(je=iwork.ptr.p_int[j]+1+iwoff; je<=iwork.ptr.p_int[j+iin]+iwoff; je++)
                {
                    w->ptr.p_double[je] = tmp1;
                    iblock->ptr.p_int[je] = ib;
                }
            }
            *m = *m+im;
        }
    }
    
    /*
     * If RANGE='I', then (WL,WU) contains eigenvalues NWL+1,...,NWU
     * If NWL+1 < IL or NWU > IU, discard extra eigenvalues.
     */
    if( irange==3 )
    {
        im = 0;
        idiscl = il-1-nwl;
        idiscu = nwu-iu;
        if( idiscl>0||idiscu>0 )
        {
            for(je=1; je<=*m; je++)
            {
                if( ae_fp_less_eq(w->ptr.p_double[je],wlu)&&idiscl>0 )
                {
                    idiscl = idiscl-1;
                }
                else
                {
                    if( ae_fp_greater_eq(w->ptr.p_double[je],wul)&&idiscu>0 )
                    {
                        idiscu = idiscu-1;
                    }
                    else
                    {
                        im = im+1;
                        w->ptr.p_double[im] = w->ptr.p_double[je];
                        iblock->ptr.p_int[im] = iblock->ptr.p_int[je];
                    }
                }
            }
            *m = im;
        }
        if( idiscl>0||idiscu>0 )
        {
            
            /*
             * Code to deal with effects of bad arithmetic:
             * Some low eigenvalues to be discarded are not in (WL,WLU],
             * or high eigenvalues to be discarded are not in (WUL,WU]
             * so just kill off the smallest IDISCL/largest IDISCU
             * eigenvalues, by simply finding the smallest/largest
             * eigenvalue(s).
             *
             * (If N(w) is monotone non-decreasing, this should never
             *  happen.)
             */
            if( idiscl>0 )
            {
                wkill = wu;
                for(jdisc=1; jdisc<=idiscl; jdisc++)
                {
                    iw = 0;
                    for(je=1; je<=*m; je++)
                    {
                        if( iblock->ptr.p_int[je]!=0&&(ae_fp_less(w->ptr.p_double[je],wkill)||iw==0) )
                        {
                            iw = je;
                            wkill = w->ptr.p_double[je];
                        }
                    }
                    iblock->ptr.p_int[iw] = 0;
                }
            }
            if( idiscu>0 )
            {
                wkill = wl;
                for(jdisc=1; jdisc<=idiscu; jdisc++)
                {
                    iw = 0;
                    for(je=1; je<=*m; je++)
                    {
                        if( iblock->ptr.p_int[je]!=0&&(ae_fp_greater(w->ptr.p_double[je],wkill)||iw==0) )
                        {
                            iw = je;
                            wkill = w->ptr.p_double[je];
                        }
                    }
                    iblock->ptr.p_int[iw] = 0;
                }
            }
            im = 0;
            for(je=1; je<=*m; je++)
            {
                if( iblock->ptr.p_int[je]!=0 )
                {
                    im = im+1;
                    w->ptr.p_double[im] = w->ptr.p_double[je];
                    iblock->ptr.p_int[im] = iblock->ptr.p_int[je];
                }
            }
            *m = im;
        }
        if( idiscl<0||idiscu<0 )
        {
            toofew = ae_true;
        }
    }
    
    /*
     * If ORDER='B', do nothing -- the eigenvalues are already sorted
     *    by block.
     * If ORDER='E', sort the eigenvalues from smallest to largest
     */
    if( iorder==1&&*nsplit>1 )
    {
        for(je=1; je<=*m-1; je++)
        {
            ie = 0;
            tmp1 = w->ptr.p_double[je];
            for(j=je+1; j<=*m; j++)
            {
                if( ae_fp_less(w->ptr.p_double[j],tmp1) )
                {
                    ie = j;
                    tmp1 = w->ptr.p_double[j];
                }
            }
            if( ie!=0 )
            {
                itmp1 = iblock->ptr.p_int[ie];
                w->ptr.p_double[ie] = w->ptr.p_double[je];
                iblock->ptr.p_int[ie] = iblock->ptr.p_int[je];
                w->ptr.p_double[je] = tmp1;
                iblock->ptr.p_int[je] = itmp1;
            }
        }
    }
    for(j=1; j<=*m; j++)
    {
        w->ptr.p_double[j] = w->ptr.p_double[j]*scalefactor;
    }
    *errorcode = 0;
    if( ncnvrg )
    {
        *errorcode = *errorcode+1;
    }
    if( toofew )
    {
        *errorcode = *errorcode+2;
    }
    result = *errorcode==0;
    ae_frame_leave(_state);
    return result;
}


static void evd_internaldstein(ae_int_t n,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t m,
     /* Real    */ ae_vector* w,
     /* Integer */ ae_vector* iblock,
     /* Integer */ ae_vector* isplit,
     /* Real    */ ae_matrix* z,
     /* Integer */ ae_vector* ifail,
     ae_int_t* info,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _e;
    ae_vector _w;
    ae_int_t maxits;
    ae_int_t extra;
    ae_int_t b1;
    ae_int_t blksiz;
    ae_int_t bn;
    ae_int_t gpind;
    ae_int_t i;
    ae_int_t iinfo;
    ae_int_t its;
    ae_int_t j;
    ae_int_t j1;
    ae_int_t jblk;
    ae_int_t jmax;
    ae_int_t nblk;
    ae_int_t nrmchk;
    double dtpcrt;
    double eps;
    double eps1;
    double nrm;
    double onenrm;
    double ortol;
    double pertol;
    double scl;
    double sep;
    double tol;
    double xj;
    double xjm;
    double ztr;
    ae_vector work1;
    ae_vector work2;
    ae_vector work3;
    ae_vector work4;
    ae_vector work5;
    ae_vector iwork;
    ae_bool tmpcriterion;
    ae_int_t ti;
    ae_int_t i1;
    ae_int_t i2;
    double v;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_e, e, _state, ae_true);
    e = &_e;
    ae_vector_init_copy(&_w, w, _state, ae_true);
    w = &_w;
    ae_matrix_clear(z);
    ae_vector_clear(ifail);
    *info = 0;
    ae_vector_init(&work1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work2, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work3, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work4, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work5, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&iwork, 0, DT_INT, _state, ae_true);

    maxits = 5;
    extra = 2;
    ae_vector_set_length(&work1, ae_maxint(n, 1, _state)+1, _state);
    ae_vector_set_length(&work2, ae_maxint(n-1, 1, _state)+1, _state);
    ae_vector_set_length(&work3, ae_maxint(n, 1, _state)+1, _state);
    ae_vector_set_length(&work4, ae_maxint(n, 1, _state)+1, _state);
    ae_vector_set_length(&work5, ae_maxint(n, 1, _state)+1, _state);
    ae_vector_set_length(&iwork, ae_maxint(n, 1, _state)+1, _state);
    ae_vector_set_length(ifail, ae_maxint(m, 1, _state)+1, _state);
    ae_matrix_set_length(z, ae_maxint(n, 1, _state)+1, ae_maxint(m, 1, _state)+1, _state);
    
    /*
     * these initializers are not really necessary,
     * but without them compiler complains about uninitialized locals
     */
    gpind = 0;
    onenrm = 0;
    ortol = 0;
    dtpcrt = 0;
    xjm = 0;
    
    /*
     * Test the input parameters.
     */
    *info = 0;
    for(i=1; i<=m; i++)
    {
        ifail->ptr.p_int[i] = 0;
    }
    if( n<0 )
    {
        *info = -1;
        ae_frame_leave(_state);
        return;
    }
    if( m<0||m>n )
    {
        *info = -4;
        ae_frame_leave(_state);
        return;
    }
    for(j=2; j<=m; j++)
    {
        if( iblock->ptr.p_int[j]<iblock->ptr.p_int[j-1] )
        {
            *info = -6;
            break;
        }
        if( iblock->ptr.p_int[j]==iblock->ptr.p_int[j-1]&&ae_fp_less(w->ptr.p_double[j],w->ptr.p_double[j-1]) )
        {
            *info = -5;
            break;
        }
    }
    if( *info!=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Quick return if possible
     */
    if( n==0||m==0 )
    {
        ae_frame_leave(_state);
        return;
    }
    if( n==1 )
    {
        z->ptr.pp_double[1][1] = 1;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Some preparations
     */
    ti = n-1;
    ae_v_move(&work1.ptr.p_double[1], 1, &e->ptr.p_double[1], 1, ae_v_len(1,ti));
    ae_vector_set_length(e, n+1, _state);
    ae_v_move(&e->ptr.p_double[1], 1, &work1.ptr.p_double[1], 1, ae_v_len(1,ti));
    ae_v_move(&work1.ptr.p_double[1], 1, &w->ptr.p_double[1], 1, ae_v_len(1,m));
    ae_vector_set_length(w, n+1, _state);
    ae_v_move(&w->ptr.p_double[1], 1, &work1.ptr.p_double[1], 1, ae_v_len(1,m));
    
    /*
     * Get machine constants.
     */
    eps = ae_machineepsilon;
    
    /*
     * Compute eigenvectors of matrix blocks.
     */
    j1 = 1;
    for(nblk=1; nblk<=iblock->ptr.p_int[m]; nblk++)
    {
        
        /*
         * Find starting and ending indices of block nblk.
         */
        if( nblk==1 )
        {
            b1 = 1;
        }
        else
        {
            b1 = isplit->ptr.p_int[nblk-1]+1;
        }
        bn = isplit->ptr.p_int[nblk];
        blksiz = bn-b1+1;
        if( blksiz!=1 )
        {
            
            /*
             * Compute reorthogonalization criterion and stopping criterion.
             */
            gpind = b1;
            onenrm = ae_fabs(d->ptr.p_double[b1], _state)+ae_fabs(e->ptr.p_double[b1], _state);
            onenrm = ae_maxreal(onenrm, ae_fabs(d->ptr.p_double[bn], _state)+ae_fabs(e->ptr.p_double[bn-1], _state), _state);
            for(i=b1+1; i<=bn-1; i++)
            {
                onenrm = ae_maxreal(onenrm, ae_fabs(d->ptr.p_double[i], _state)+ae_fabs(e->ptr.p_double[i-1], _state)+ae_fabs(e->ptr.p_double[i], _state), _state);
            }
            ortol = 0.001*onenrm;
            dtpcrt = ae_sqrt(0.1/blksiz, _state);
        }
        
        /*
         * Loop through eigenvalues of block nblk.
         */
        jblk = 0;
        for(j=j1; j<=m; j++)
        {
            if( iblock->ptr.p_int[j]!=nblk )
            {
                j1 = j;
                break;
            }
            jblk = jblk+1;
            xj = w->ptr.p_double[j];
            if( blksiz==1 )
            {
                
                /*
                 * Skip all the work if the block size is one.
                 */
                work1.ptr.p_double[1] = 1;
            }
            else
            {
                
                /*
                 * If eigenvalues j and j-1 are too close, add a relatively
                 * small perturbation.
                 */
                if( jblk>1 )
                {
                    eps1 = ae_fabs(eps*xj, _state);
                    pertol = 10*eps1;
                    sep = xj-xjm;
                    if( ae_fp_less(sep,pertol) )
                    {
                        xj = xjm+pertol;
                    }
                }
                its = 0;
                nrmchk = 0;
                
                /*
                 * Get random starting vector.
                 */
                for(ti=1; ti<=blksiz; ti++)
                {
                    work1.ptr.p_double[ti] = 2*ae_randomreal(_state)-1;
                }
                
                /*
                 * Copy the matrix T so it won't be destroyed in factorization.
                 */
                for(ti=1; ti<=blksiz-1; ti++)
                {
                    work2.ptr.p_double[ti] = e->ptr.p_double[b1+ti-1];
                    work3.ptr.p_double[ti] = e->ptr.p_double[b1+ti-1];
                    work4.ptr.p_double[ti] = d->ptr.p_double[b1+ti-1];
                }
                work4.ptr.p_double[blksiz] = d->ptr.p_double[b1+blksiz-1];
                
                /*
                 * Compute LU factors with partial pivoting  ( PT = LU )
                 */
                tol = 0;
                evd_tdininternaldlagtf(blksiz, &work4, xj, &work2, &work3, tol, &work5, &iwork, &iinfo, _state);
                
                /*
                 * Update iteration count.
                 */
                do
                {
                    its = its+1;
                    if( its>maxits )
                    {
                        
                        /*
                         * If stopping criterion was not satisfied, update info and
                         * store eigenvector number in array ifail.
                         */
                        *info = *info+1;
                        ifail->ptr.p_int[*info] = j;
                        break;
                    }
                    
                    /*
                     * Normalize and scale the righthand side vector Pb.
                     */
                    v = 0;
                    for(ti=1; ti<=blksiz; ti++)
                    {
                        v = v+ae_fabs(work1.ptr.p_double[ti], _state);
                    }
                    scl = blksiz*onenrm*ae_maxreal(eps, ae_fabs(work4.ptr.p_double[blksiz], _state), _state)/v;
                    ae_v_muld(&work1.ptr.p_double[1], 1, ae_v_len(1,blksiz), scl);
                    
                    /*
                     * Solve the system LU = Pb.
                     */
                    evd_tdininternaldlagts(blksiz, &work4, &work2, &work3, &work5, &iwork, &work1, &tol, &iinfo, _state);
                    
                    /*
                     * Reorthogonalize by modified Gram-Schmidt if eigenvalues are
                     * close enough.
                     */
                    if( jblk!=1 )
                    {
                        if( ae_fp_greater(ae_fabs(xj-xjm, _state),ortol) )
                        {
                            gpind = j;
                        }
                        if( gpind!=j )
                        {
                            for(i=gpind; i<=j-1; i++)
                            {
                                i1 = b1;
                                i2 = b1+blksiz-1;
                                ztr = ae_v_dotproduct(&work1.ptr.p_double[1], 1, &z->ptr.pp_double[i1][i], z->stride, ae_v_len(1,blksiz));
                                ae_v_subd(&work1.ptr.p_double[1], 1, &z->ptr.pp_double[i1][i], z->stride, ae_v_len(1,blksiz), ztr);
                            }
                        }
                    }
                    
                    /*
                     * Check the infinity norm of the iterate.
                     */
                    jmax = vectoridxabsmax(&work1, 1, blksiz, _state);
                    nrm = ae_fabs(work1.ptr.p_double[jmax], _state);
                    
                    /*
                     * Continue for additional iterations after norm reaches
                     * stopping criterion.
                     */
                    tmpcriterion = ae_false;
                    if( ae_fp_less(nrm,dtpcrt) )
                    {
                        tmpcriterion = ae_true;
                    }
                    else
                    {
                        nrmchk = nrmchk+1;
                        if( nrmchk<extra+1 )
                        {
                            tmpcriterion = ae_true;
                        }
                    }
                }
                while(tmpcriterion);
                
                /*
                 * Accept iterate as jth eigenvector.
                 */
                scl = 1/vectornorm2(&work1, 1, blksiz, _state);
                jmax = vectoridxabsmax(&work1, 1, blksiz, _state);
                if( ae_fp_less(work1.ptr.p_double[jmax],0) )
                {
                    scl = -scl;
                }
                ae_v_muld(&work1.ptr.p_double[1], 1, ae_v_len(1,blksiz), scl);
            }
            for(i=1; i<=n; i++)
            {
                z->ptr.pp_double[i][j] = 0;
            }
            for(i=1; i<=blksiz; i++)
            {
                z->ptr.pp_double[b1+i-1][j] = work1.ptr.p_double[i];
            }
            
            /*
             * Save the shift to check eigenvalue spacing at next
             * iteration.
             */
            xjm = xj;
        }
    }
    ae_frame_leave(_state);
}


static void evd_tdininternaldlagtf(ae_int_t n,
     /* Real    */ ae_vector* a,
     double lambdav,
     /* Real    */ ae_vector* b,
     /* Real    */ ae_vector* c,
     double tol,
     /* Real    */ ae_vector* d,
     /* Integer */ ae_vector* iin,
     ae_int_t* info,
     ae_state *_state)
{
    ae_int_t k;
    double eps;
    double mult;
    double piv1;
    double piv2;
    double scale1;
    double scale2;
    double temp;
    double tl;

    *info = 0;

    *info = 0;
    if( n<0 )
    {
        *info = -1;
        return;
    }
    if( n==0 )
    {
        return;
    }
    a->ptr.p_double[1] = a->ptr.p_double[1]-lambdav;
    iin->ptr.p_int[n] = 0;
    if( n==1 )
    {
        if( ae_fp_eq(a->ptr.p_double[1],0) )
        {
            iin->ptr.p_int[1] = 1;
        }
        return;
    }
    eps = ae_machineepsilon;
    tl = ae_maxreal(tol, eps, _state);
    scale1 = ae_fabs(a->ptr.p_double[1], _state)+ae_fabs(b->ptr.p_double[1], _state);
    for(k=1; k<=n-1; k++)
    {
        a->ptr.p_double[k+1] = a->ptr.p_double[k+1]-lambdav;
        scale2 = ae_fabs(c->ptr.p_double[k], _state)+ae_fabs(a->ptr.p_double[k+1], _state);
        if( k<n-1 )
        {
            scale2 = scale2+ae_fabs(b->ptr.p_double[k+1], _state);
        }
        if( ae_fp_eq(a->ptr.p_double[k],0) )
        {
            piv1 = 0;
        }
        else
        {
            piv1 = ae_fabs(a->ptr.p_double[k], _state)/scale1;
        }
        if( ae_fp_eq(c->ptr.p_double[k],0) )
        {
            iin->ptr.p_int[k] = 0;
            piv2 = 0;
            scale1 = scale2;
            if( k<n-1 )
            {
                d->ptr.p_double[k] = 0;
            }
        }
        else
        {
            piv2 = ae_fabs(c->ptr.p_double[k], _state)/scale2;
            if( ae_fp_less_eq(piv2,piv1) )
            {
                iin->ptr.p_int[k] = 0;
                scale1 = scale2;
                c->ptr.p_double[k] = c->ptr.p_double[k]/a->ptr.p_double[k];
                a->ptr.p_double[k+1] = a->ptr.p_double[k+1]-c->ptr.p_double[k]*b->ptr.p_double[k];
                if( k<n-1 )
                {
                    d->ptr.p_double[k] = 0;
                }
            }
            else
            {
                iin->ptr.p_int[k] = 1;
                mult = a->ptr.p_double[k]/c->ptr.p_double[k];
                a->ptr.p_double[k] = c->ptr.p_double[k];
                temp = a->ptr.p_double[k+1];
                a->ptr.p_double[k+1] = b->ptr.p_double[k]-mult*temp;
                if( k<n-1 )
                {
                    d->ptr.p_double[k] = b->ptr.p_double[k+1];
                    b->ptr.p_double[k+1] = -mult*d->ptr.p_double[k];
                }
                b->ptr.p_double[k] = temp;
                c->ptr.p_double[k] = mult;
            }
        }
        if( ae_fp_less_eq(ae_maxreal(piv1, piv2, _state),tl)&&iin->ptr.p_int[n]==0 )
        {
            iin->ptr.p_int[n] = k;
        }
    }
    if( ae_fp_less_eq(ae_fabs(a->ptr.p_double[n], _state),scale1*tl)&&iin->ptr.p_int[n]==0 )
    {
        iin->ptr.p_int[n] = n;
    }
}


static void evd_tdininternaldlagts(ae_int_t n,
     /* Real    */ ae_vector* a,
     /* Real    */ ae_vector* b,
     /* Real    */ ae_vector* c,
     /* Real    */ ae_vector* d,
     /* Integer */ ae_vector* iin,
     /* Real    */ ae_vector* y,
     double* tol,
     ae_int_t* info,
     ae_state *_state)
{
    ae_int_t k;
    double absak;
    double ak;
    double bignum;
    double eps;
    double pert;
    double sfmin;
    double temp;

    *info = 0;

    *info = 0;
    if( n<0 )
    {
        *info = -1;
        return;
    }
    if( n==0 )
    {
        return;
    }
    eps = ae_machineepsilon;
    sfmin = ae_minrealnumber;
    bignum = 1/sfmin;
    if( ae_fp_less_eq(*tol,0) )
    {
        *tol = ae_fabs(a->ptr.p_double[1], _state);
        if( n>1 )
        {
            *tol = ae_maxreal(*tol, ae_maxreal(ae_fabs(a->ptr.p_double[2], _state), ae_fabs(b->ptr.p_double[1], _state), _state), _state);
        }
        for(k=3; k<=n; k++)
        {
            *tol = ae_maxreal(*tol, ae_maxreal(ae_fabs(a->ptr.p_double[k], _state), ae_maxreal(ae_fabs(b->ptr.p_double[k-1], _state), ae_fabs(d->ptr.p_double[k-2], _state), _state), _state), _state);
        }
        *tol = *tol*eps;
        if( ae_fp_eq(*tol,0) )
        {
            *tol = eps;
        }
    }
    for(k=2; k<=n; k++)
    {
        if( iin->ptr.p_int[k-1]==0 )
        {
            y->ptr.p_double[k] = y->ptr.p_double[k]-c->ptr.p_double[k-1]*y->ptr.p_double[k-1];
        }
        else
        {
            temp = y->ptr.p_double[k-1];
            y->ptr.p_double[k-1] = y->ptr.p_double[k];
            y->ptr.p_double[k] = temp-c->ptr.p_double[k-1]*y->ptr.p_double[k];
        }
    }
    for(k=n; k>=1; k--)
    {
        if( k<=n-2 )
        {
            temp = y->ptr.p_double[k]-b->ptr.p_double[k]*y->ptr.p_double[k+1]-d->ptr.p_double[k]*y->ptr.p_double[k+2];
        }
        else
        {
            if( k==n-1 )
            {
                temp = y->ptr.p_double[k]-b->ptr.p_double[k]*y->ptr.p_double[k+1];
            }
            else
            {
                temp = y->ptr.p_double[k];
            }
        }
        ak = a->ptr.p_double[k];
        pert = ae_fabs(*tol, _state);
        if( ae_fp_less(ak,0) )
        {
            pert = -pert;
        }
        for(;;)
        {
            absak = ae_fabs(ak, _state);
            if( ae_fp_less(absak,1) )
            {
                if( ae_fp_less(absak,sfmin) )
                {
                    if( ae_fp_eq(absak,0)||ae_fp_greater(ae_fabs(temp, _state)*sfmin,absak) )
                    {
                        ak = ak+pert;
                        pert = 2*pert;
                        continue;
                    }
                    else
                    {
                        temp = temp*bignum;
                        ak = ak*bignum;
                    }
                }
                else
                {
                    if( ae_fp_greater(ae_fabs(temp, _state),absak*bignum) )
                    {
                        ak = ak+pert;
                        pert = 2*pert;
                        continue;
                    }
                }
            }
            break;
        }
        y->ptr.p_double[k] = temp/ak;
    }
}


static void evd_internaldlaebz(ae_int_t ijob,
     ae_int_t nitmax,
     ae_int_t n,
     ae_int_t mmax,
     ae_int_t minp,
     double abstol,
     double reltol,
     double pivmin,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     /* Real    */ ae_vector* e2,
     /* Integer */ ae_vector* nval,
     /* Real    */ ae_matrix* ab,
     /* Real    */ ae_vector* c,
     ae_int_t* mout,
     /* Integer */ ae_matrix* nab,
     /* Real    */ ae_vector* work,
     /* Integer */ ae_vector* iwork,
     ae_int_t* info,
     ae_state *_state)
{
    ae_int_t itmp1;
    ae_int_t itmp2;
    ae_int_t j;
    ae_int_t ji;
    ae_int_t jit;
    ae_int_t jp;
    ae_int_t kf;
    ae_int_t kfnew;
    ae_int_t kl;
    ae_int_t klnew;
    double tmp1;
    double tmp2;

    *mout = 0;
    *info = 0;

    *info = 0;
    if( ijob<1||ijob>3 )
    {
        *info = -1;
        return;
    }
    
    /*
     * Initialize NAB
     */
    if( ijob==1 )
    {
        
        /*
         * Compute the number of eigenvalues in the initial intervals.
         */
        *mout = 0;
        
        /*
         *DIR$ NOVECTOR
         */
        for(ji=1; ji<=minp; ji++)
        {
            for(jp=1; jp<=2; jp++)
            {
                tmp1 = d->ptr.p_double[1]-ab->ptr.pp_double[ji][jp];
                if( ae_fp_less(ae_fabs(tmp1, _state),pivmin) )
                {
                    tmp1 = -pivmin;
                }
                nab->ptr.pp_int[ji][jp] = 0;
                if( ae_fp_less_eq(tmp1,0) )
                {
                    nab->ptr.pp_int[ji][jp] = 1;
                }
                for(j=2; j<=n; j++)
                {
                    tmp1 = d->ptr.p_double[j]-e2->ptr.p_double[j-1]/tmp1-ab->ptr.pp_double[ji][jp];
                    if( ae_fp_less(ae_fabs(tmp1, _state),pivmin) )
                    {
                        tmp1 = -pivmin;
                    }
                    if( ae_fp_less_eq(tmp1,0) )
                    {
                        nab->ptr.pp_int[ji][jp] = nab->ptr.pp_int[ji][jp]+1;
                    }
                }
            }
            *mout = *mout+nab->ptr.pp_int[ji][2]-nab->ptr.pp_int[ji][1];
        }
        return;
    }
    
    /*
     * Initialize for loop
     *
     * KF and KL have the following meaning:
     *   Intervals 1,...,KF-1 have converged.
     *   Intervals KF,...,KL  still need to be refined.
     */
    kf = 1;
    kl = minp;
    
    /*
     * If IJOB=2, initialize C.
     * If IJOB=3, use the user-supplied starting point.
     */
    if( ijob==2 )
    {
        for(ji=1; ji<=minp; ji++)
        {
            c->ptr.p_double[ji] = 0.5*(ab->ptr.pp_double[ji][1]+ab->ptr.pp_double[ji][2]);
        }
    }
    
    /*
     * Iteration loop
     */
    for(jit=1; jit<=nitmax; jit++)
    {
        
        /*
         * Loop over intervals
         *
         *
         * Serial Version of the loop
         */
        klnew = kl;
        for(ji=kf; ji<=kl; ji++)
        {
            
            /*
             * Compute N(w), the number of eigenvalues less than w
             */
            tmp1 = c->ptr.p_double[ji];
            tmp2 = d->ptr.p_double[1]-tmp1;
            itmp1 = 0;
            if( ae_fp_less_eq(tmp2,pivmin) )
            {
                itmp1 = 1;
                tmp2 = ae_minreal(tmp2, -pivmin, _state);
            }
            
            /*
             * A series of compiler directives to defeat vectorization
             * for the next loop
             *
             **$PL$ CMCHAR=' '
             *CDIR$          NEXTSCALAR
             *C$DIR          SCALAR
             *CDIR$          NEXT SCALAR
             *CVD$L          NOVECTOR
             *CDEC$          NOVECTOR
             *CVD$           NOVECTOR
             **VDIR          NOVECTOR
             **VOCL          LOOP,SCALAR
             *CIBM           PREFER SCALAR
             **$PL$ CMCHAR='*'
             */
            for(j=2; j<=n; j++)
            {
                tmp2 = d->ptr.p_double[j]-e2->ptr.p_double[j-1]/tmp2-tmp1;
                if( ae_fp_less_eq(tmp2,pivmin) )
                {
                    itmp1 = itmp1+1;
                    tmp2 = ae_minreal(tmp2, -pivmin, _state);
                }
            }
            if( ijob<=2 )
            {
                
                /*
                 * IJOB=2: Choose all intervals containing eigenvalues.
                 *
                 * Insure that N(w) is monotone
                 */
                itmp1 = ae_minint(nab->ptr.pp_int[ji][2], ae_maxint(nab->ptr.pp_int[ji][1], itmp1, _state), _state);
                
                /*
                 * Update the Queue -- add intervals if both halves
                 * contain eigenvalues.
                 */
                if( itmp1==nab->ptr.pp_int[ji][2] )
                {
                    
                    /*
                     * No eigenvalue in the upper interval:
                     * just use the lower interval.
                     */
                    ab->ptr.pp_double[ji][2] = tmp1;
                }
                else
                {
                    if( itmp1==nab->ptr.pp_int[ji][1] )
                    {
                        
                        /*
                         * No eigenvalue in the lower interval:
                         * just use the upper interval.
                         */
                        ab->ptr.pp_double[ji][1] = tmp1;
                    }
                    else
                    {
                        if( klnew<mmax )
                        {
                            
                            /*
                             * Eigenvalue in both intervals -- add upper to queue.
                             */
                            klnew = klnew+1;
                            ab->ptr.pp_double[klnew][2] = ab->ptr.pp_double[ji][2];
                            nab->ptr.pp_int[klnew][2] = nab->ptr.pp_int[ji][2];
                            ab->ptr.pp_double[klnew][1] = tmp1;
                            nab->ptr.pp_int[klnew][1] = itmp1;
                            ab->ptr.pp_double[ji][2] = tmp1;
                            nab->ptr.pp_int[ji][2] = itmp1;
                        }
                        else
                        {
                            *info = mmax+1;
                            return;
                        }
                    }
                }
            }
            else
            {
                
                /*
                 * IJOB=3: Binary search.  Keep only the interval
                 * containing  w  s.t. N(w) = NVAL
                 */
                if( itmp1<=nval->ptr.p_int[ji] )
                {
                    ab->ptr.pp_double[ji][1] = tmp1;
                    nab->ptr.pp_int[ji][1] = itmp1;
                }
                if( itmp1>=nval->ptr.p_int[ji] )
                {
                    ab->ptr.pp_double[ji][2] = tmp1;
                    nab->ptr.pp_int[ji][2] = itmp1;
                }
            }
        }
        kl = klnew;
        
        /*
         * Check for convergence
         */
        kfnew = kf;
        for(ji=kf; ji<=kl; ji++)
        {
            tmp1 = ae_fabs(ab->ptr.pp_double[ji][2]-ab->ptr.pp_double[ji][1], _state);
            tmp2 = ae_maxreal(ae_fabs(ab->ptr.pp_double[ji][2], _state), ae_fabs(ab->ptr.pp_double[ji][1], _state), _state);
            if( ae_fp_less(tmp1,ae_maxreal(abstol, ae_maxreal(pivmin, reltol*tmp2, _state), _state))||nab->ptr.pp_int[ji][1]>=nab->ptr.pp_int[ji][2] )
            {
                
                /*
                 * Converged -- Swap with position KFNEW,
                 * then increment KFNEW
                 */
                if( ji>kfnew )
                {
                    tmp1 = ab->ptr.pp_double[ji][1];
                    tmp2 = ab->ptr.pp_double[ji][2];
                    itmp1 = nab->ptr.pp_int[ji][1];
                    itmp2 = nab->ptr.pp_int[ji][2];
                    ab->ptr.pp_double[ji][1] = ab->ptr.pp_double[kfnew][1];
                    ab->ptr.pp_double[ji][2] = ab->ptr.pp_double[kfnew][2];
                    nab->ptr.pp_int[ji][1] = nab->ptr.pp_int[kfnew][1];
                    nab->ptr.pp_int[ji][2] = nab->ptr.pp_int[kfnew][2];
                    ab->ptr.pp_double[kfnew][1] = tmp1;
                    ab->ptr.pp_double[kfnew][2] = tmp2;
                    nab->ptr.pp_int[kfnew][1] = itmp1;
                    nab->ptr.pp_int[kfnew][2] = itmp2;
                    if( ijob==3 )
                    {
                        itmp1 = nval->ptr.p_int[ji];
                        nval->ptr.p_int[ji] = nval->ptr.p_int[kfnew];
                        nval->ptr.p_int[kfnew] = itmp1;
                    }
                }
                kfnew = kfnew+1;
            }
        }
        kf = kfnew;
        
        /*
         * Choose Midpoints
         */
        for(ji=kf; ji<=kl; ji++)
        {
            c->ptr.p_double[ji] = 0.5*(ab->ptr.pp_double[ji][1]+ab->ptr.pp_double[ji][2]);
        }
        
        /*
         * If no more intervals to refine, quit.
         */
        if( kf>kl )
        {
            break;
        }
    }
    
    /*
     * Converged
     */
    *info = ae_maxint(kl+1-kf, 0, _state);
    *mout = kl;
}


/*************************************************************************
Internal subroutine

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     June 30, 1999
*************************************************************************/
static void evd_internaltrevc(/* Real    */ ae_matrix* t,
     ae_int_t n,
     ae_int_t side,
     ae_int_t howmny,
     /* Boolean */ ae_vector* vselect,
     /* Real    */ ae_matrix* vl,
     /* Real    */ ae_matrix* vr,
     ae_int_t* m,
     ae_int_t* info,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _vselect;
    ae_bool allv;
    ae_bool bothv;
    ae_bool leftv;
    ae_bool over;
    ae_bool pair;
    ae_bool rightv;
    ae_bool somev;
    ae_int_t i;
    ae_int_t ierr;
    ae_int_t ii;
    ae_int_t ip;
    ae_int_t iis;
    ae_int_t j;
    ae_int_t j1;
    ae_int_t j2;
    ae_int_t jnxt;
    ae_int_t k;
    ae_int_t ki;
    ae_int_t n2;
    double beta;
    double bignum;
    double emax;
    double ovfl;
    double rec;
    double remax;
    double scl;
    double smin;
    double smlnum;
    double ulp;
    double unfl;
    double vcrit;
    double vmax;
    double wi;
    double wr;
    double xnorm;
    ae_matrix x;
    ae_vector work;
    ae_vector temp;
    ae_matrix temp11;
    ae_matrix temp22;
    ae_matrix temp11b;
    ae_matrix temp21b;
    ae_matrix temp12b;
    ae_matrix temp22b;
    ae_bool skipflag;
    ae_int_t k1;
    ae_int_t k2;
    ae_int_t k3;
    ae_int_t k4;
    double vt;
    ae_vector rswap4;
    ae_vector zswap4;
    ae_matrix ipivot44;
    ae_vector civ4;
    ae_vector crv4;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_vselect, vselect, _state, ae_true);
    vselect = &_vselect;
    *m = 0;
    *info = 0;
    ae_matrix_init(&x, 0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&temp, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&temp11, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&temp22, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&temp11b, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&temp21b, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&temp12b, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&temp22b, 0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&rswap4, 0, DT_BOOL, _state, ae_true);
    ae_vector_init(&zswap4, 0, DT_BOOL, _state, ae_true);
    ae_matrix_init(&ipivot44, 0, 0, DT_INT, _state, ae_true);
    ae_vector_init(&civ4, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&crv4, 0, DT_REAL, _state, ae_true);

    ae_matrix_set_length(&x, 2+1, 2+1, _state);
    ae_matrix_set_length(&temp11, 1+1, 1+1, _state);
    ae_matrix_set_length(&temp11b, 1+1, 1+1, _state);
    ae_matrix_set_length(&temp21b, 2+1, 1+1, _state);
    ae_matrix_set_length(&temp12b, 1+1, 2+1, _state);
    ae_matrix_set_length(&temp22b, 2+1, 2+1, _state);
    ae_matrix_set_length(&temp22, 2+1, 2+1, _state);
    ae_vector_set_length(&work, 3*n+1, _state);
    ae_vector_set_length(&temp, n+1, _state);
    ae_vector_set_length(&rswap4, 4+1, _state);
    ae_vector_set_length(&zswap4, 4+1, _state);
    ae_matrix_set_length(&ipivot44, 4+1, 4+1, _state);
    ae_vector_set_length(&civ4, 4+1, _state);
    ae_vector_set_length(&crv4, 4+1, _state);
    if( howmny!=1 )
    {
        if( side==1||side==3 )
        {
            ae_matrix_set_length(vr, n+1, n+1, _state);
        }
        if( side==2||side==3 )
        {
            ae_matrix_set_length(vl, n+1, n+1, _state);
        }
    }
    
    /*
     * Decode and test the input parameters
     */
    bothv = side==3;
    rightv = side==1||bothv;
    leftv = side==2||bothv;
    allv = howmny==2;
    over = howmny==1;
    somev = howmny==3;
    *info = 0;
    if( n<0 )
    {
        *info = -2;
        ae_frame_leave(_state);
        return;
    }
    if( !rightv&&!leftv )
    {
        *info = -3;
        ae_frame_leave(_state);
        return;
    }
    if( (!allv&&!over)&&!somev )
    {
        *info = -4;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Set M to the number of columns required to store the selected
     * eigenvectors, standardize the array SELECT if necessary, and
     * test MM.
     */
    if( somev )
    {
        *m = 0;
        pair = ae_false;
        for(j=1; j<=n; j++)
        {
            if( pair )
            {
                pair = ae_false;
                vselect->ptr.p_bool[j] = ae_false;
            }
            else
            {
                if( j<n )
                {
                    if( ae_fp_eq(t->ptr.pp_double[j+1][j],0) )
                    {
                        if( vselect->ptr.p_bool[j] )
                        {
                            *m = *m+1;
                        }
                    }
                    else
                    {
                        pair = ae_true;
                        if( vselect->ptr.p_bool[j]||vselect->ptr.p_bool[j+1] )
                        {
                            vselect->ptr.p_bool[j] = ae_true;
                            *m = *m+2;
                        }
                    }
                }
                else
                {
                    if( vselect->ptr.p_bool[n] )
                    {
                        *m = *m+1;
                    }
                }
            }
        }
    }
    else
    {
        *m = n;
    }
    
    /*
     * Quick return if possible.
     */
    if( n==0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Set the constants to control overflow.
     */
    unfl = ae_minrealnumber;
    ovfl = 1/unfl;
    ulp = ae_machineepsilon;
    smlnum = unfl*(n/ulp);
    bignum = (1-ulp)/smlnum;
    
    /*
     * Compute 1-norm of each column of strictly upper triangular
     * part of T to control overflow in triangular solver.
     */
    work.ptr.p_double[1] = 0;
    for(j=2; j<=n; j++)
    {
        work.ptr.p_double[j] = 0;
        for(i=1; i<=j-1; i++)
        {
            work.ptr.p_double[j] = work.ptr.p_double[j]+ae_fabs(t->ptr.pp_double[i][j], _state);
        }
    }
    
    /*
     * Index IP is used to specify the real or complex eigenvalue:
     * IP = 0, real eigenvalue,
     *      1, first of conjugate complex pair: (wr,wi)
     *     -1, second of conjugate complex pair: (wr,wi)
     */
    n2 = 2*n;
    if( rightv )
    {
        
        /*
         * Compute right eigenvectors.
         */
        ip = 0;
        iis = *m;
        for(ki=n; ki>=1; ki--)
        {
            skipflag = ae_false;
            if( ip==1 )
            {
                skipflag = ae_true;
            }
            else
            {
                if( ki!=1 )
                {
                    if( ae_fp_neq(t->ptr.pp_double[ki][ki-1],0) )
                    {
                        ip = -1;
                    }
                }
                if( somev )
                {
                    if( ip==0 )
                    {
                        if( !vselect->ptr.p_bool[ki] )
                        {
                            skipflag = ae_true;
                        }
                    }
                    else
                    {
                        if( !vselect->ptr.p_bool[ki-1] )
                        {
                            skipflag = ae_true;
                        }
                    }
                }
            }
            if( !skipflag )
            {
                
                /*
                 * Compute the KI-th eigenvalue (WR,WI).
                 */
                wr = t->ptr.pp_double[ki][ki];
                wi = 0;
                if( ip!=0 )
                {
                    wi = ae_sqrt(ae_fabs(t->ptr.pp_double[ki][ki-1], _state), _state)*ae_sqrt(ae_fabs(t->ptr.pp_double[ki-1][ki], _state), _state);
                }
                smin = ae_maxreal(ulp*(ae_fabs(wr, _state)+ae_fabs(wi, _state)), smlnum, _state);
                if( ip==0 )
                {
                    
                    /*
                     * Real right eigenvector
                     */
                    work.ptr.p_double[ki+n] = 1;
                    
                    /*
                     * Form right-hand side
                     */
                    for(k=1; k<=ki-1; k++)
                    {
                        work.ptr.p_double[k+n] = -t->ptr.pp_double[k][ki];
                    }
                    
                    /*
                     * Solve the upper quasi-triangular system:
                     *   (T(1:KI-1,1:KI-1) - WR)*X = SCALE*WORK.
                     */
                    jnxt = ki-1;
                    for(j=ki-1; j>=1; j--)
                    {
                        if( j>jnxt )
                        {
                            continue;
                        }
                        j1 = j;
                        j2 = j;
                        jnxt = j-1;
                        if( j>1 )
                        {
                            if( ae_fp_neq(t->ptr.pp_double[j][j-1],0) )
                            {
                                j1 = j-1;
                                jnxt = j-2;
                            }
                        }
                        if( j1==j2 )
                        {
                            
                            /*
                             * 1-by-1 diagonal block
                             */
                            temp11.ptr.pp_double[1][1] = t->ptr.pp_double[j][j];
                            temp11b.ptr.pp_double[1][1] = work.ptr.p_double[j+n];
                            evd_internalhsevdlaln2(ae_false, 1, 1, smin, 1, &temp11, 1.0, 1.0, &temp11b, wr, 0.0, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale X(1,1) to avoid overflow when updating
                             * the right-hand side.
                             */
                            if( ae_fp_greater(xnorm,1) )
                            {
                                if( ae_fp_greater(work.ptr.p_double[j],bignum/xnorm) )
                                {
                                    x.ptr.pp_double[1][1] = x.ptr.pp_double[1][1]/xnorm;
                                    scl = scl/xnorm;
                                }
                            }
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                k1 = n+1;
                                k2 = n+ki;
                                ae_v_muld(&work.ptr.p_double[k1], 1, ae_v_len(k1,k2), scl);
                            }
                            work.ptr.p_double[j+n] = x.ptr.pp_double[1][1];
                            
                            /*
                             * Update right-hand side
                             */
                            k1 = 1+n;
                            k2 = j-1+n;
                            k3 = j-1;
                            vt = -x.ptr.pp_double[1][1];
                            ae_v_addd(&work.ptr.p_double[k1], 1, &t->ptr.pp_double[1][j], t->stride, ae_v_len(k1,k2), vt);
                        }
                        else
                        {
                            
                            /*
                             * 2-by-2 diagonal block
                             */
                            temp22.ptr.pp_double[1][1] = t->ptr.pp_double[j-1][j-1];
                            temp22.ptr.pp_double[1][2] = t->ptr.pp_double[j-1][j];
                            temp22.ptr.pp_double[2][1] = t->ptr.pp_double[j][j-1];
                            temp22.ptr.pp_double[2][2] = t->ptr.pp_double[j][j];
                            temp21b.ptr.pp_double[1][1] = work.ptr.p_double[j-1+n];
                            temp21b.ptr.pp_double[2][1] = work.ptr.p_double[j+n];
                            evd_internalhsevdlaln2(ae_false, 2, 1, smin, 1.0, &temp22, 1.0, 1.0, &temp21b, wr, 0, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale X(1,1) and X(2,1) to avoid overflow when
                             * updating the right-hand side.
                             */
                            if( ae_fp_greater(xnorm,1) )
                            {
                                beta = ae_maxreal(work.ptr.p_double[j-1], work.ptr.p_double[j], _state);
                                if( ae_fp_greater(beta,bignum/xnorm) )
                                {
                                    x.ptr.pp_double[1][1] = x.ptr.pp_double[1][1]/xnorm;
                                    x.ptr.pp_double[2][1] = x.ptr.pp_double[2][1]/xnorm;
                                    scl = scl/xnorm;
                                }
                            }
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                k1 = 1+n;
                                k2 = ki+n;
                                ae_v_muld(&work.ptr.p_double[k1], 1, ae_v_len(k1,k2), scl);
                            }
                            work.ptr.p_double[j-1+n] = x.ptr.pp_double[1][1];
                            work.ptr.p_double[j+n] = x.ptr.pp_double[2][1];
                            
                            /*
                             * Update right-hand side
                             */
                            k1 = 1+n;
                            k2 = j-2+n;
                            k3 = j-2;
                            k4 = j-1;
                            vt = -x.ptr.pp_double[1][1];
                            ae_v_addd(&work.ptr.p_double[k1], 1, &t->ptr.pp_double[1][k4], t->stride, ae_v_len(k1,k2), vt);
                            vt = -x.ptr.pp_double[2][1];
                            ae_v_addd(&work.ptr.p_double[k1], 1, &t->ptr.pp_double[1][j], t->stride, ae_v_len(k1,k2), vt);
                        }
                    }
                    
                    /*
                     * Copy the vector x or Q*x to VR and normalize.
                     */
                    if( !over )
                    {
                        k1 = 1+n;
                        k2 = ki+n;
                        ae_v_move(&vr->ptr.pp_double[1][iis], vr->stride, &work.ptr.p_double[k1], 1, ae_v_len(1,ki));
                        ii = columnidxabsmax(vr, 1, ki, iis, _state);
                        remax = 1/ae_fabs(vr->ptr.pp_double[ii][iis], _state);
                        ae_v_muld(&vr->ptr.pp_double[1][iis], vr->stride, ae_v_len(1,ki), remax);
                        for(k=ki+1; k<=n; k++)
                        {
                            vr->ptr.pp_double[k][iis] = 0;
                        }
                    }
                    else
                    {
                        if( ki>1 )
                        {
                            ae_v_move(&temp.ptr.p_double[1], 1, &vr->ptr.pp_double[1][ki], vr->stride, ae_v_len(1,n));
                            matrixvectormultiply(vr, 1, n, 1, ki-1, ae_false, &work, 1+n, ki-1+n, 1.0, &temp, 1, n, work.ptr.p_double[ki+n], _state);
                            ae_v_move(&vr->ptr.pp_double[1][ki], vr->stride, &temp.ptr.p_double[1], 1, ae_v_len(1,n));
                        }
                        ii = columnidxabsmax(vr, 1, n, ki, _state);
                        remax = 1/ae_fabs(vr->ptr.pp_double[ii][ki], _state);
                        ae_v_muld(&vr->ptr.pp_double[1][ki], vr->stride, ae_v_len(1,n), remax);
                    }
                }
                else
                {
                    
                    /*
                     * Complex right eigenvector.
                     *
                     * Initial solve
                     *     [ (T(KI-1,KI-1) T(KI-1,KI) ) - (WR + I* WI)]*X = 0.
                     *     [ (T(KI,KI-1)   T(KI,KI)   )               ]
                     */
                    if( ae_fp_greater_eq(ae_fabs(t->ptr.pp_double[ki-1][ki], _state),ae_fabs(t->ptr.pp_double[ki][ki-1], _state)) )
                    {
                        work.ptr.p_double[ki-1+n] = 1;
                        work.ptr.p_double[ki+n2] = wi/t->ptr.pp_double[ki-1][ki];
                    }
                    else
                    {
                        work.ptr.p_double[ki-1+n] = -wi/t->ptr.pp_double[ki][ki-1];
                        work.ptr.p_double[ki+n2] = 1;
                    }
                    work.ptr.p_double[ki+n] = 0;
                    work.ptr.p_double[ki-1+n2] = 0;
                    
                    /*
                     * Form right-hand side
                     */
                    for(k=1; k<=ki-2; k++)
                    {
                        work.ptr.p_double[k+n] = -work.ptr.p_double[ki-1+n]*t->ptr.pp_double[k][ki-1];
                        work.ptr.p_double[k+n2] = -work.ptr.p_double[ki+n2]*t->ptr.pp_double[k][ki];
                    }
                    
                    /*
                     * Solve upper quasi-triangular system:
                     * (T(1:KI-2,1:KI-2) - (WR+i*WI))*X = SCALE*(WORK+i*WORK2)
                     */
                    jnxt = ki-2;
                    for(j=ki-2; j>=1; j--)
                    {
                        if( j>jnxt )
                        {
                            continue;
                        }
                        j1 = j;
                        j2 = j;
                        jnxt = j-1;
                        if( j>1 )
                        {
                            if( ae_fp_neq(t->ptr.pp_double[j][j-1],0) )
                            {
                                j1 = j-1;
                                jnxt = j-2;
                            }
                        }
                        if( j1==j2 )
                        {
                            
                            /*
                             * 1-by-1 diagonal block
                             */
                            temp11.ptr.pp_double[1][1] = t->ptr.pp_double[j][j];
                            temp12b.ptr.pp_double[1][1] = work.ptr.p_double[j+n];
                            temp12b.ptr.pp_double[1][2] = work.ptr.p_double[j+n+n];
                            evd_internalhsevdlaln2(ae_false, 1, 2, smin, 1.0, &temp11, 1.0, 1.0, &temp12b, wr, wi, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale X(1,1) and X(1,2) to avoid overflow when
                             * updating the right-hand side.
                             */
                            if( ae_fp_greater(xnorm,1) )
                            {
                                if( ae_fp_greater(work.ptr.p_double[j],bignum/xnorm) )
                                {
                                    x.ptr.pp_double[1][1] = x.ptr.pp_double[1][1]/xnorm;
                                    x.ptr.pp_double[1][2] = x.ptr.pp_double[1][2]/xnorm;
                                    scl = scl/xnorm;
                                }
                            }
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                k1 = 1+n;
                                k2 = ki+n;
                                ae_v_muld(&work.ptr.p_double[k1], 1, ae_v_len(k1,k2), scl);
                                k1 = 1+n2;
                                k2 = ki+n2;
                                ae_v_muld(&work.ptr.p_double[k1], 1, ae_v_len(k1,k2), scl);
                            }
                            work.ptr.p_double[j+n] = x.ptr.pp_double[1][1];
                            work.ptr.p_double[j+n2] = x.ptr.pp_double[1][2];
                            
                            /*
                             * Update the right-hand side
                             */
                            k1 = 1+n;
                            k2 = j-1+n;
                            k3 = 1;
                            k4 = j-1;
                            vt = -x.ptr.pp_double[1][1];
                            ae_v_addd(&work.ptr.p_double[k1], 1, &t->ptr.pp_double[k3][j], t->stride, ae_v_len(k1,k2), vt);
                            k1 = 1+n2;
                            k2 = j-1+n2;
                            k3 = 1;
                            k4 = j-1;
                            vt = -x.ptr.pp_double[1][2];
                            ae_v_addd(&work.ptr.p_double[k1], 1, &t->ptr.pp_double[k3][j], t->stride, ae_v_len(k1,k2), vt);
                        }
                        else
                        {
                            
                            /*
                             * 2-by-2 diagonal block
                             */
                            temp22.ptr.pp_double[1][1] = t->ptr.pp_double[j-1][j-1];
                            temp22.ptr.pp_double[1][2] = t->ptr.pp_double[j-1][j];
                            temp22.ptr.pp_double[2][1] = t->ptr.pp_double[j][j-1];
                            temp22.ptr.pp_double[2][2] = t->ptr.pp_double[j][j];
                            temp22b.ptr.pp_double[1][1] = work.ptr.p_double[j-1+n];
                            temp22b.ptr.pp_double[1][2] = work.ptr.p_double[j-1+n+n];
                            temp22b.ptr.pp_double[2][1] = work.ptr.p_double[j+n];
                            temp22b.ptr.pp_double[2][2] = work.ptr.p_double[j+n+n];
                            evd_internalhsevdlaln2(ae_false, 2, 2, smin, 1.0, &temp22, 1.0, 1.0, &temp22b, wr, wi, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale X to avoid overflow when updating
                             * the right-hand side.
                             */
                            if( ae_fp_greater(xnorm,1) )
                            {
                                beta = ae_maxreal(work.ptr.p_double[j-1], work.ptr.p_double[j], _state);
                                if( ae_fp_greater(beta,bignum/xnorm) )
                                {
                                    rec = 1/xnorm;
                                    x.ptr.pp_double[1][1] = x.ptr.pp_double[1][1]*rec;
                                    x.ptr.pp_double[1][2] = x.ptr.pp_double[1][2]*rec;
                                    x.ptr.pp_double[2][1] = x.ptr.pp_double[2][1]*rec;
                                    x.ptr.pp_double[2][2] = x.ptr.pp_double[2][2]*rec;
                                    scl = scl*rec;
                                }
                            }
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                ae_v_muld(&work.ptr.p_double[1+n], 1, ae_v_len(1+n,ki+n), scl);
                                ae_v_muld(&work.ptr.p_double[1+n2], 1, ae_v_len(1+n2,ki+n2), scl);
                            }
                            work.ptr.p_double[j-1+n] = x.ptr.pp_double[1][1];
                            work.ptr.p_double[j+n] = x.ptr.pp_double[2][1];
                            work.ptr.p_double[j-1+n2] = x.ptr.pp_double[1][2];
                            work.ptr.p_double[j+n2] = x.ptr.pp_double[2][2];
                            
                            /*
                             * Update the right-hand side
                             */
                            vt = -x.ptr.pp_double[1][1];
                            ae_v_addd(&work.ptr.p_double[n+1], 1, &t->ptr.pp_double[1][j-1], t->stride, ae_v_len(n+1,n+j-2), vt);
                            vt = -x.ptr.pp_double[2][1];
                            ae_v_addd(&work.ptr.p_double[n+1], 1, &t->ptr.pp_double[1][j], t->stride, ae_v_len(n+1,n+j-2), vt);
                            vt = -x.ptr.pp_double[1][2];
                            ae_v_addd(&work.ptr.p_double[n2+1], 1, &t->ptr.pp_double[1][j-1], t->stride, ae_v_len(n2+1,n2+j-2), vt);
                            vt = -x.ptr.pp_double[2][2];
                            ae_v_addd(&work.ptr.p_double[n2+1], 1, &t->ptr.pp_double[1][j], t->stride, ae_v_len(n2+1,n2+j-2), vt);
                        }
                    }
                    
                    /*
                     * Copy the vector x or Q*x to VR and normalize.
                     */
                    if( !over )
                    {
                        ae_v_move(&vr->ptr.pp_double[1][iis-1], vr->stride, &work.ptr.p_double[n+1], 1, ae_v_len(1,ki));
                        ae_v_move(&vr->ptr.pp_double[1][iis], vr->stride, &work.ptr.p_double[n2+1], 1, ae_v_len(1,ki));
                        emax = 0;
                        for(k=1; k<=ki; k++)
                        {
                            emax = ae_maxreal(emax, ae_fabs(vr->ptr.pp_double[k][iis-1], _state)+ae_fabs(vr->ptr.pp_double[k][iis], _state), _state);
                        }
                        remax = 1/emax;
                        ae_v_muld(&vr->ptr.pp_double[1][iis-1], vr->stride, ae_v_len(1,ki), remax);
                        ae_v_muld(&vr->ptr.pp_double[1][iis], vr->stride, ae_v_len(1,ki), remax);
                        for(k=ki+1; k<=n; k++)
                        {
                            vr->ptr.pp_double[k][iis-1] = 0;
                            vr->ptr.pp_double[k][iis] = 0;
                        }
                    }
                    else
                    {
                        if( ki>2 )
                        {
                            ae_v_move(&temp.ptr.p_double[1], 1, &vr->ptr.pp_double[1][ki-1], vr->stride, ae_v_len(1,n));
                            matrixvectormultiply(vr, 1, n, 1, ki-2, ae_false, &work, 1+n, ki-2+n, 1.0, &temp, 1, n, work.ptr.p_double[ki-1+n], _state);
                            ae_v_move(&vr->ptr.pp_double[1][ki-1], vr->stride, &temp.ptr.p_double[1], 1, ae_v_len(1,n));
                            ae_v_move(&temp.ptr.p_double[1], 1, &vr->ptr.pp_double[1][ki], vr->stride, ae_v_len(1,n));
                            matrixvectormultiply(vr, 1, n, 1, ki-2, ae_false, &work, 1+n2, ki-2+n2, 1.0, &temp, 1, n, work.ptr.p_double[ki+n2], _state);
                            ae_v_move(&vr->ptr.pp_double[1][ki], vr->stride, &temp.ptr.p_double[1], 1, ae_v_len(1,n));
                        }
                        else
                        {
                            vt = work.ptr.p_double[ki-1+n];
                            ae_v_muld(&vr->ptr.pp_double[1][ki-1], vr->stride, ae_v_len(1,n), vt);
                            vt = work.ptr.p_double[ki+n2];
                            ae_v_muld(&vr->ptr.pp_double[1][ki], vr->stride, ae_v_len(1,n), vt);
                        }
                        emax = 0;
                        for(k=1; k<=n; k++)
                        {
                            emax = ae_maxreal(emax, ae_fabs(vr->ptr.pp_double[k][ki-1], _state)+ae_fabs(vr->ptr.pp_double[k][ki], _state), _state);
                        }
                        remax = 1/emax;
                        ae_v_muld(&vr->ptr.pp_double[1][ki-1], vr->stride, ae_v_len(1,n), remax);
                        ae_v_muld(&vr->ptr.pp_double[1][ki], vr->stride, ae_v_len(1,n), remax);
                    }
                }
                iis = iis-1;
                if( ip!=0 )
                {
                    iis = iis-1;
                }
            }
            if( ip==1 )
            {
                ip = 0;
            }
            if( ip==-1 )
            {
                ip = 1;
            }
        }
    }
    if( leftv )
    {
        
        /*
         * Compute left eigenvectors.
         */
        ip = 0;
        iis = 1;
        for(ki=1; ki<=n; ki++)
        {
            skipflag = ae_false;
            if( ip==-1 )
            {
                skipflag = ae_true;
            }
            else
            {
                if( ki!=n )
                {
                    if( ae_fp_neq(t->ptr.pp_double[ki+1][ki],0) )
                    {
                        ip = 1;
                    }
                }
                if( somev )
                {
                    if( !vselect->ptr.p_bool[ki] )
                    {
                        skipflag = ae_true;
                    }
                }
            }
            if( !skipflag )
            {
                
                /*
                 * Compute the KI-th eigenvalue (WR,WI).
                 */
                wr = t->ptr.pp_double[ki][ki];
                wi = 0;
                if( ip!=0 )
                {
                    wi = ae_sqrt(ae_fabs(t->ptr.pp_double[ki][ki+1], _state), _state)*ae_sqrt(ae_fabs(t->ptr.pp_double[ki+1][ki], _state), _state);
                }
                smin = ae_maxreal(ulp*(ae_fabs(wr, _state)+ae_fabs(wi, _state)), smlnum, _state);
                if( ip==0 )
                {
                    
                    /*
                     * Real left eigenvector.
                     */
                    work.ptr.p_double[ki+n] = 1;
                    
                    /*
                     * Form right-hand side
                     */
                    for(k=ki+1; k<=n; k++)
                    {
                        work.ptr.p_double[k+n] = -t->ptr.pp_double[ki][k];
                    }
                    
                    /*
                     * Solve the quasi-triangular system:
                     * (T(KI+1:N,KI+1:N) - WR)'*X = SCALE*WORK
                     */
                    vmax = 1;
                    vcrit = bignum;
                    jnxt = ki+1;
                    for(j=ki+1; j<=n; j++)
                    {
                        if( j<jnxt )
                        {
                            continue;
                        }
                        j1 = j;
                        j2 = j;
                        jnxt = j+1;
                        if( j<n )
                        {
                            if( ae_fp_neq(t->ptr.pp_double[j+1][j],0) )
                            {
                                j2 = j+1;
                                jnxt = j+2;
                            }
                        }
                        if( j1==j2 )
                        {
                            
                            /*
                             * 1-by-1 diagonal block
                             *
                             * Scale if necessary to avoid overflow when forming
                             * the right-hand side.
                             */
                            if( ae_fp_greater(work.ptr.p_double[j],vcrit) )
                            {
                                rec = 1/vmax;
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), rec);
                                vmax = 1;
                                vcrit = bignum;
                            }
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+1][j], t->stride, &work.ptr.p_double[ki+1+n], 1, ae_v_len(ki+1,j-1));
                            work.ptr.p_double[j+n] = work.ptr.p_double[j+n]-vt;
                            
                            /*
                             * Solve (T(J,J)-WR)'*X = WORK
                             */
                            temp11.ptr.pp_double[1][1] = t->ptr.pp_double[j][j];
                            temp11b.ptr.pp_double[1][1] = work.ptr.p_double[j+n];
                            evd_internalhsevdlaln2(ae_false, 1, 1, smin, 1.0, &temp11, 1.0, 1.0, &temp11b, wr, 0, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), scl);
                            }
                            work.ptr.p_double[j+n] = x.ptr.pp_double[1][1];
                            vmax = ae_maxreal(ae_fabs(work.ptr.p_double[j+n], _state), vmax, _state);
                            vcrit = bignum/vmax;
                        }
                        else
                        {
                            
                            /*
                             * 2-by-2 diagonal block
                             *
                             * Scale if necessary to avoid overflow when forming
                             * the right-hand side.
                             */
                            beta = ae_maxreal(work.ptr.p_double[j], work.ptr.p_double[j+1], _state);
                            if( ae_fp_greater(beta,vcrit) )
                            {
                                rec = 1/vmax;
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), rec);
                                vmax = 1;
                                vcrit = bignum;
                            }
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+1][j], t->stride, &work.ptr.p_double[ki+1+n], 1, ae_v_len(ki+1,j-1));
                            work.ptr.p_double[j+n] = work.ptr.p_double[j+n]-vt;
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+1][j+1], t->stride, &work.ptr.p_double[ki+1+n], 1, ae_v_len(ki+1,j-1));
                            work.ptr.p_double[j+1+n] = work.ptr.p_double[j+1+n]-vt;
                            
                            /*
                             * Solve
                             *    [T(J,J)-WR   T(J,J+1)     ]'* X = SCALE*( WORK1 )
                             *    [T(J+1,J)    T(J+1,J+1)-WR]             ( WORK2 )
                             */
                            temp22.ptr.pp_double[1][1] = t->ptr.pp_double[j][j];
                            temp22.ptr.pp_double[1][2] = t->ptr.pp_double[j][j+1];
                            temp22.ptr.pp_double[2][1] = t->ptr.pp_double[j+1][j];
                            temp22.ptr.pp_double[2][2] = t->ptr.pp_double[j+1][j+1];
                            temp21b.ptr.pp_double[1][1] = work.ptr.p_double[j+n];
                            temp21b.ptr.pp_double[2][1] = work.ptr.p_double[j+1+n];
                            evd_internalhsevdlaln2(ae_true, 2, 1, smin, 1.0, &temp22, 1.0, 1.0, &temp21b, wr, 0, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), scl);
                            }
                            work.ptr.p_double[j+n] = x.ptr.pp_double[1][1];
                            work.ptr.p_double[j+1+n] = x.ptr.pp_double[2][1];
                            vmax = ae_maxreal(ae_fabs(work.ptr.p_double[j+n], _state), ae_maxreal(ae_fabs(work.ptr.p_double[j+1+n], _state), vmax, _state), _state);
                            vcrit = bignum/vmax;
                        }
                    }
                    
                    /*
                     * Copy the vector x or Q*x to VL and normalize.
                     */
                    if( !over )
                    {
                        ae_v_move(&vl->ptr.pp_double[ki][iis], vl->stride, &work.ptr.p_double[ki+n], 1, ae_v_len(ki,n));
                        ii = columnidxabsmax(vl, ki, n, iis, _state);
                        remax = 1/ae_fabs(vl->ptr.pp_double[ii][iis], _state);
                        ae_v_muld(&vl->ptr.pp_double[ki][iis], vl->stride, ae_v_len(ki,n), remax);
                        for(k=1; k<=ki-1; k++)
                        {
                            vl->ptr.pp_double[k][iis] = 0;
                        }
                    }
                    else
                    {
                        if( ki<n )
                        {
                            ae_v_move(&temp.ptr.p_double[1], 1, &vl->ptr.pp_double[1][ki], vl->stride, ae_v_len(1,n));
                            matrixvectormultiply(vl, 1, n, ki+1, n, ae_false, &work, ki+1+n, n+n, 1.0, &temp, 1, n, work.ptr.p_double[ki+n], _state);
                            ae_v_move(&vl->ptr.pp_double[1][ki], vl->stride, &temp.ptr.p_double[1], 1, ae_v_len(1,n));
                        }
                        ii = columnidxabsmax(vl, 1, n, ki, _state);
                        remax = 1/ae_fabs(vl->ptr.pp_double[ii][ki], _state);
                        ae_v_muld(&vl->ptr.pp_double[1][ki], vl->stride, ae_v_len(1,n), remax);
                    }
                }
                else
                {
                    
                    /*
                     * Complex left eigenvector.
                     *
                     * Initial solve:
                     *   ((T(KI,KI)    T(KI,KI+1) )' - (WR - I* WI))*X = 0.
                     *   ((T(KI+1,KI) T(KI+1,KI+1))                )
                     */
                    if( ae_fp_greater_eq(ae_fabs(t->ptr.pp_double[ki][ki+1], _state),ae_fabs(t->ptr.pp_double[ki+1][ki], _state)) )
                    {
                        work.ptr.p_double[ki+n] = wi/t->ptr.pp_double[ki][ki+1];
                        work.ptr.p_double[ki+1+n2] = 1;
                    }
                    else
                    {
                        work.ptr.p_double[ki+n] = 1;
                        work.ptr.p_double[ki+1+n2] = -wi/t->ptr.pp_double[ki+1][ki];
                    }
                    work.ptr.p_double[ki+1+n] = 0;
                    work.ptr.p_double[ki+n2] = 0;
                    
                    /*
                     * Form right-hand side
                     */
                    for(k=ki+2; k<=n; k++)
                    {
                        work.ptr.p_double[k+n] = -work.ptr.p_double[ki+n]*t->ptr.pp_double[ki][k];
                        work.ptr.p_double[k+n2] = -work.ptr.p_double[ki+1+n2]*t->ptr.pp_double[ki+1][k];
                    }
                    
                    /*
                     * Solve complex quasi-triangular system:
                     * ( T(KI+2,N:KI+2,N) - (WR-i*WI) )*X = WORK1+i*WORK2
                     */
                    vmax = 1;
                    vcrit = bignum;
                    jnxt = ki+2;
                    for(j=ki+2; j<=n; j++)
                    {
                        if( j<jnxt )
                        {
                            continue;
                        }
                        j1 = j;
                        j2 = j;
                        jnxt = j+1;
                        if( j<n )
                        {
                            if( ae_fp_neq(t->ptr.pp_double[j+1][j],0) )
                            {
                                j2 = j+1;
                                jnxt = j+2;
                            }
                        }
                        if( j1==j2 )
                        {
                            
                            /*
                             * 1-by-1 diagonal block
                             *
                             * Scale if necessary to avoid overflow when
                             * forming the right-hand side elements.
                             */
                            if( ae_fp_greater(work.ptr.p_double[j],vcrit) )
                            {
                                rec = 1/vmax;
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), rec);
                                ae_v_muld(&work.ptr.p_double[ki+n2], 1, ae_v_len(ki+n2,n+n2), rec);
                                vmax = 1;
                                vcrit = bignum;
                            }
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+2][j], t->stride, &work.ptr.p_double[ki+2+n], 1, ae_v_len(ki+2,j-1));
                            work.ptr.p_double[j+n] = work.ptr.p_double[j+n]-vt;
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+2][j], t->stride, &work.ptr.p_double[ki+2+n2], 1, ae_v_len(ki+2,j-1));
                            work.ptr.p_double[j+n2] = work.ptr.p_double[j+n2]-vt;
                            
                            /*
                             * Solve (T(J,J)-(WR-i*WI))*(X11+i*X12)= WK+I*WK2
                             */
                            temp11.ptr.pp_double[1][1] = t->ptr.pp_double[j][j];
                            temp12b.ptr.pp_double[1][1] = work.ptr.p_double[j+n];
                            temp12b.ptr.pp_double[1][2] = work.ptr.p_double[j+n+n];
                            evd_internalhsevdlaln2(ae_false, 1, 2, smin, 1.0, &temp11, 1.0, 1.0, &temp12b, wr, -wi, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), scl);
                                ae_v_muld(&work.ptr.p_double[ki+n2], 1, ae_v_len(ki+n2,n+n2), scl);
                            }
                            work.ptr.p_double[j+n] = x.ptr.pp_double[1][1];
                            work.ptr.p_double[j+n2] = x.ptr.pp_double[1][2];
                            vmax = ae_maxreal(ae_fabs(work.ptr.p_double[j+n], _state), ae_maxreal(ae_fabs(work.ptr.p_double[j+n2], _state), vmax, _state), _state);
                            vcrit = bignum/vmax;
                        }
                        else
                        {
                            
                            /*
                             * 2-by-2 diagonal block
                             *
                             * Scale if necessary to avoid overflow when forming
                             * the right-hand side elements.
                             */
                            beta = ae_maxreal(work.ptr.p_double[j], work.ptr.p_double[j+1], _state);
                            if( ae_fp_greater(beta,vcrit) )
                            {
                                rec = 1/vmax;
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), rec);
                                ae_v_muld(&work.ptr.p_double[ki+n2], 1, ae_v_len(ki+n2,n+n2), rec);
                                vmax = 1;
                                vcrit = bignum;
                            }
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+2][j], t->stride, &work.ptr.p_double[ki+2+n], 1, ae_v_len(ki+2,j-1));
                            work.ptr.p_double[j+n] = work.ptr.p_double[j+n]-vt;
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+2][j], t->stride, &work.ptr.p_double[ki+2+n2], 1, ae_v_len(ki+2,j-1));
                            work.ptr.p_double[j+n2] = work.ptr.p_double[j+n2]-vt;
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+2][j+1], t->stride, &work.ptr.p_double[ki+2+n], 1, ae_v_len(ki+2,j-1));
                            work.ptr.p_double[j+1+n] = work.ptr.p_double[j+1+n]-vt;
                            vt = ae_v_dotproduct(&t->ptr.pp_double[ki+2][j+1], t->stride, &work.ptr.p_double[ki+2+n2], 1, ae_v_len(ki+2,j-1));
                            work.ptr.p_double[j+1+n2] = work.ptr.p_double[j+1+n2]-vt;
                            
                            /*
                             * Solve 2-by-2 complex linear equation
                             *   ([T(j,j)   T(j,j+1)  ]'-(wr-i*wi)*I)*X = SCALE*B
                             *   ([T(j+1,j) T(j+1,j+1)]             )
                             */
                            temp22.ptr.pp_double[1][1] = t->ptr.pp_double[j][j];
                            temp22.ptr.pp_double[1][2] = t->ptr.pp_double[j][j+1];
                            temp22.ptr.pp_double[2][1] = t->ptr.pp_double[j+1][j];
                            temp22.ptr.pp_double[2][2] = t->ptr.pp_double[j+1][j+1];
                            temp22b.ptr.pp_double[1][1] = work.ptr.p_double[j+n];
                            temp22b.ptr.pp_double[1][2] = work.ptr.p_double[j+n+n];
                            temp22b.ptr.pp_double[2][1] = work.ptr.p_double[j+1+n];
                            temp22b.ptr.pp_double[2][2] = work.ptr.p_double[j+1+n+n];
                            evd_internalhsevdlaln2(ae_true, 2, 2, smin, 1.0, &temp22, 1.0, 1.0, &temp22b, wr, -wi, &rswap4, &zswap4, &ipivot44, &civ4, &crv4, &x, &scl, &xnorm, &ierr, _state);
                            
                            /*
                             * Scale if necessary
                             */
                            if( ae_fp_neq(scl,1) )
                            {
                                ae_v_muld(&work.ptr.p_double[ki+n], 1, ae_v_len(ki+n,n+n), scl);
                                ae_v_muld(&work.ptr.p_double[ki+n2], 1, ae_v_len(ki+n2,n+n2), scl);
                            }
                            work.ptr.p_double[j+n] = x.ptr.pp_double[1][1];
                            work.ptr.p_double[j+n2] = x.ptr.pp_double[1][2];
                            work.ptr.p_double[j+1+n] = x.ptr.pp_double[2][1];
                            work.ptr.p_double[j+1+n2] = x.ptr.pp_double[2][2];
                            vmax = ae_maxreal(ae_fabs(x.ptr.pp_double[1][1], _state), vmax, _state);
                            vmax = ae_maxreal(ae_fabs(x.ptr.pp_double[1][2], _state), vmax, _state);
                            vmax = ae_maxreal(ae_fabs(x.ptr.pp_double[2][1], _state), vmax, _state);
                            vmax = ae_maxreal(ae_fabs(x.ptr.pp_double[2][2], _state), vmax, _state);
                            vcrit = bignum/vmax;
                        }
                    }
                    
                    /*
                     * Copy the vector x or Q*x to VL and normalize.
                     */
                    if( !over )
                    {
                        ae_v_move(&vl->ptr.pp_double[ki][iis], vl->stride, &work.ptr.p_double[ki+n], 1, ae_v_len(ki,n));
                        ae_v_move(&vl->ptr.pp_double[ki][iis+1], vl->stride, &work.ptr.p_double[ki+n2], 1, ae_v_len(ki,n));
                        emax = 0;
                        for(k=ki; k<=n; k++)
                        {
                            emax = ae_maxreal(emax, ae_fabs(vl->ptr.pp_double[k][iis], _state)+ae_fabs(vl->ptr.pp_double[k][iis+1], _state), _state);
                        }
                        remax = 1/emax;
                        ae_v_muld(&vl->ptr.pp_double[ki][iis], vl->stride, ae_v_len(ki,n), remax);
                        ae_v_muld(&vl->ptr.pp_double[ki][iis+1], vl->stride, ae_v_len(ki,n), remax);
                        for(k=1; k<=ki-1; k++)
                        {
                            vl->ptr.pp_double[k][iis] = 0;
                            vl->ptr.pp_double[k][iis+1] = 0;
                        }
                    }
                    else
                    {
                        if( ki<n-1 )
                        {
                            ae_v_move(&temp.ptr.p_double[1], 1, &vl->ptr.pp_double[1][ki], vl->stride, ae_v_len(1,n));
                            matrixvectormultiply(vl, 1, n, ki+2, n, ae_false, &work, ki+2+n, n+n, 1.0, &temp, 1, n, work.ptr.p_double[ki+n], _state);
                            ae_v_move(&vl->ptr.pp_double[1][ki], vl->stride, &temp.ptr.p_double[1], 1, ae_v_len(1,n));
                            ae_v_move(&temp.ptr.p_double[1], 1, &vl->ptr.pp_double[1][ki+1], vl->stride, ae_v_len(1,n));
                            matrixvectormultiply(vl, 1, n, ki+2, n, ae_false, &work, ki+2+n2, n+n2, 1.0, &temp, 1, n, work.ptr.p_double[ki+1+n2], _state);
                            ae_v_move(&vl->ptr.pp_double[1][ki+1], vl->stride, &temp.ptr.p_double[1], 1, ae_v_len(1,n));
                        }
                        else
                        {
                            vt = work.ptr.p_double[ki+n];
                            ae_v_muld(&vl->ptr.pp_double[1][ki], vl->stride, ae_v_len(1,n), vt);
                            vt = work.ptr.p_double[ki+1+n2];
                            ae_v_muld(&vl->ptr.pp_double[1][ki+1], vl->stride, ae_v_len(1,n), vt);
                        }
                        emax = 0;
                        for(k=1; k<=n; k++)
                        {
                            emax = ae_maxreal(emax, ae_fabs(vl->ptr.pp_double[k][ki], _state)+ae_fabs(vl->ptr.pp_double[k][ki+1], _state), _state);
                        }
                        remax = 1/emax;
                        ae_v_muld(&vl->ptr.pp_double[1][ki], vl->stride, ae_v_len(1,n), remax);
                        ae_v_muld(&vl->ptr.pp_double[1][ki+1], vl->stride, ae_v_len(1,n), remax);
                    }
                }
                iis = iis+1;
                if( ip!=0 )
                {
                    iis = iis+1;
                }
            }
            if( ip==-1 )
            {
                ip = 0;
            }
            if( ip==1 )
            {
                ip = -1;
            }
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
DLALN2 solves a system of the form  (ca A - w D ) X = s B
or (ca A' - w D) X = s B   with possible scaling ("s") and
perturbation of A.  (A' means A-transpose.)

A is an NA x NA real matrix, ca is a real scalar, D is an NA x NA
real diagonal matrix, w is a real or complex value, and X and B are
NA x 1 matrices -- real if w is real, complex if w is complex.  NA
may be 1 or 2.

If w is complex, X and B are represented as NA x 2 matrices,
the first column of each being the real part and the second
being the imaginary part.

"s" is a scaling factor (.LE. 1), computed by DLALN2, which is
so chosen that X can be computed without overflow.  X is further
scaled if necessary to assure that norm(ca A - w D)*norm(X) is less
than overflow.

If both singular values of (ca A - w D) are less than SMIN,
SMIN*identity will be used instead of (ca A - w D).  If only one
singular value is less than SMIN, one element of (ca A - w D) will be
perturbed enough to make the smallest singular value roughly SMIN.
If both singular values are at least SMIN, (ca A - w D) will not be
perturbed.  In any case, the perturbation will be at most some small
multiple of max( SMIN, ulp*norm(ca A - w D) ).  The singular values
are computed by infinity-norm approximations, and thus will only be
correct to a factor of 2 or so.

Note: all input quantities are assumed to be smaller than overflow
by a reasonable factor.  (See BIGNUM.)

  -- LAPACK auxiliary routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
static void evd_internalhsevdlaln2(ae_bool ltrans,
     ae_int_t na,
     ae_int_t nw,
     double smin,
     double ca,
     /* Real    */ ae_matrix* a,
     double d1,
     double d2,
     /* Real    */ ae_matrix* b,
     double wr,
     double wi,
     /* Boolean */ ae_vector* rswap4,
     /* Boolean */ ae_vector* zswap4,
     /* Integer */ ae_matrix* ipivot44,
     /* Real    */ ae_vector* civ4,
     /* Real    */ ae_vector* crv4,
     /* Real    */ ae_matrix* x,
     double* scl,
     double* xnorm,
     ae_int_t* info,
     ae_state *_state)
{
    ae_int_t icmax;
    ae_int_t j;
    double bbnd;
    double bi1;
    double bi2;
    double bignum;
    double bnorm;
    double br1;
    double br2;
    double ci21;
    double ci22;
    double cmax;
    double cnorm;
    double cr21;
    double cr22;
    double csi;
    double csr;
    double li21;
    double lr21;
    double smini;
    double smlnum;
    double temp;
    double u22abs;
    double ui11;
    double ui11r;
    double ui12;
    double ui12s;
    double ui22;
    double ur11;
    double ur11r;
    double ur12;
    double ur12s;
    double ur22;
    double xi1;
    double xi2;
    double xr1;
    double xr2;
    double tmp1;
    double tmp2;

    *scl = 0;
    *xnorm = 0;
    *info = 0;

    zswap4->ptr.p_bool[1] = ae_false;
    zswap4->ptr.p_bool[2] = ae_false;
    zswap4->ptr.p_bool[3] = ae_true;
    zswap4->ptr.p_bool[4] = ae_true;
    rswap4->ptr.p_bool[1] = ae_false;
    rswap4->ptr.p_bool[2] = ae_true;
    rswap4->ptr.p_bool[3] = ae_false;
    rswap4->ptr.p_bool[4] = ae_true;
    ipivot44->ptr.pp_int[1][1] = 1;
    ipivot44->ptr.pp_int[2][1] = 2;
    ipivot44->ptr.pp_int[3][1] = 3;
    ipivot44->ptr.pp_int[4][1] = 4;
    ipivot44->ptr.pp_int[1][2] = 2;
    ipivot44->ptr.pp_int[2][2] = 1;
    ipivot44->ptr.pp_int[3][2] = 4;
    ipivot44->ptr.pp_int[4][2] = 3;
    ipivot44->ptr.pp_int[1][3] = 3;
    ipivot44->ptr.pp_int[2][3] = 4;
    ipivot44->ptr.pp_int[3][3] = 1;
    ipivot44->ptr.pp_int[4][3] = 2;
    ipivot44->ptr.pp_int[1][4] = 4;
    ipivot44->ptr.pp_int[2][4] = 3;
    ipivot44->ptr.pp_int[3][4] = 2;
    ipivot44->ptr.pp_int[4][4] = 1;
    smlnum = 2*ae_minrealnumber;
    bignum = 1/smlnum;
    smini = ae_maxreal(smin, smlnum, _state);
    
    /*
     * Don't check for input errors
     */
    *info = 0;
    
    /*
     * Standard Initializations
     */
    *scl = 1;
    if( na==1 )
    {
        
        /*
         * 1 x 1  (i.e., scalar) system   C X = B
         */
        if( nw==1 )
        {
            
            /*
             * Real 1x1 system.
             *
             * C = ca A - w D
             */
            csr = ca*a->ptr.pp_double[1][1]-wr*d1;
            cnorm = ae_fabs(csr, _state);
            
            /*
             * If | C | < SMINI, use C = SMINI
             */
            if( ae_fp_less(cnorm,smini) )
            {
                csr = smini;
                cnorm = smini;
                *info = 1;
            }
            
            /*
             * Check scaling for  X = B / C
             */
            bnorm = ae_fabs(b->ptr.pp_double[1][1], _state);
            if( ae_fp_less(cnorm,1)&&ae_fp_greater(bnorm,1) )
            {
                if( ae_fp_greater(bnorm,bignum*cnorm) )
                {
                    *scl = 1/bnorm;
                }
            }
            
            /*
             * Compute X
             */
            x->ptr.pp_double[1][1] = b->ptr.pp_double[1][1]*(*scl)/csr;
            *xnorm = ae_fabs(x->ptr.pp_double[1][1], _state);
        }
        else
        {
            
            /*
             * Complex 1x1 system (w is complex)
             *
             * C = ca A - w D
             */
            csr = ca*a->ptr.pp_double[1][1]-wr*d1;
            csi = -wi*d1;
            cnorm = ae_fabs(csr, _state)+ae_fabs(csi, _state);
            
            /*
             * If | C | < SMINI, use C = SMINI
             */
            if( ae_fp_less(cnorm,smini) )
            {
                csr = smini;
                csi = 0;
                cnorm = smini;
                *info = 1;
            }
            
            /*
             * Check scaling for  X = B / C
             */
            bnorm = ae_fabs(b->ptr.pp_double[1][1], _state)+ae_fabs(b->ptr.pp_double[1][2], _state);
            if( ae_fp_less(cnorm,1)&&ae_fp_greater(bnorm,1) )
            {
                if( ae_fp_greater(bnorm,bignum*cnorm) )
                {
                    *scl = 1/bnorm;
                }
            }
            
            /*
             * Compute X
             */
            evd_internalhsevdladiv(*scl*b->ptr.pp_double[1][1], *scl*b->ptr.pp_double[1][2], csr, csi, &tmp1, &tmp2, _state);
            x->ptr.pp_double[1][1] = tmp1;
            x->ptr.pp_double[1][2] = tmp2;
            *xnorm = ae_fabs(x->ptr.pp_double[1][1], _state)+ae_fabs(x->ptr.pp_double[1][2], _state);
        }
    }
    else
    {
        
        /*
         * 2x2 System
         *
         * Compute the real part of  C = ca A - w D  (or  ca A' - w D )
         */
        crv4->ptr.p_double[1+0] = ca*a->ptr.pp_double[1][1]-wr*d1;
        crv4->ptr.p_double[2+2] = ca*a->ptr.pp_double[2][2]-wr*d2;
        if( ltrans )
        {
            crv4->ptr.p_double[1+2] = ca*a->ptr.pp_double[2][1];
            crv4->ptr.p_double[2+0] = ca*a->ptr.pp_double[1][2];
        }
        else
        {
            crv4->ptr.p_double[2+0] = ca*a->ptr.pp_double[2][1];
            crv4->ptr.p_double[1+2] = ca*a->ptr.pp_double[1][2];
        }
        if( nw==1 )
        {
            
            /*
             * Real 2x2 system  (w is real)
             *
             * Find the largest element in C
             */
            cmax = 0;
            icmax = 0;
            for(j=1; j<=4; j++)
            {
                if( ae_fp_greater(ae_fabs(crv4->ptr.p_double[j], _state),cmax) )
                {
                    cmax = ae_fabs(crv4->ptr.p_double[j], _state);
                    icmax = j;
                }
            }
            
            /*
             * If norm(C) < SMINI, use SMINI*identity.
             */
            if( ae_fp_less(cmax,smini) )
            {
                bnorm = ae_maxreal(ae_fabs(b->ptr.pp_double[1][1], _state), ae_fabs(b->ptr.pp_double[2][1], _state), _state);
                if( ae_fp_less(smini,1)&&ae_fp_greater(bnorm,1) )
                {
                    if( ae_fp_greater(bnorm,bignum*smini) )
                    {
                        *scl = 1/bnorm;
                    }
                }
                temp = *scl/smini;
                x->ptr.pp_double[1][1] = temp*b->ptr.pp_double[1][1];
                x->ptr.pp_double[2][1] = temp*b->ptr.pp_double[2][1];
                *xnorm = temp*bnorm;
                *info = 1;
                return;
            }
            
            /*
             * Gaussian elimination with complete pivoting.
             */
            ur11 = crv4->ptr.p_double[icmax];
            cr21 = crv4->ptr.p_double[ipivot44->ptr.pp_int[2][icmax]];
            ur12 = crv4->ptr.p_double[ipivot44->ptr.pp_int[3][icmax]];
            cr22 = crv4->ptr.p_double[ipivot44->ptr.pp_int[4][icmax]];
            ur11r = 1/ur11;
            lr21 = ur11r*cr21;
            ur22 = cr22-ur12*lr21;
            
            /*
             * If smaller pivot < SMINI, use SMINI
             */
            if( ae_fp_less(ae_fabs(ur22, _state),smini) )
            {
                ur22 = smini;
                *info = 1;
            }
            if( rswap4->ptr.p_bool[icmax] )
            {
                br1 = b->ptr.pp_double[2][1];
                br2 = b->ptr.pp_double[1][1];
            }
            else
            {
                br1 = b->ptr.pp_double[1][1];
                br2 = b->ptr.pp_double[2][1];
            }
            br2 = br2-lr21*br1;
            bbnd = ae_maxreal(ae_fabs(br1*(ur22*ur11r), _state), ae_fabs(br2, _state), _state);
            if( ae_fp_greater(bbnd,1)&&ae_fp_less(ae_fabs(ur22, _state),1) )
            {
                if( ae_fp_greater_eq(bbnd,bignum*ae_fabs(ur22, _state)) )
                {
                    *scl = 1/bbnd;
                }
            }
            xr2 = br2*(*scl)/ur22;
            xr1 = *scl*br1*ur11r-xr2*(ur11r*ur12);
            if( zswap4->ptr.p_bool[icmax] )
            {
                x->ptr.pp_double[1][1] = xr2;
                x->ptr.pp_double[2][1] = xr1;
            }
            else
            {
                x->ptr.pp_double[1][1] = xr1;
                x->ptr.pp_double[2][1] = xr2;
            }
            *xnorm = ae_maxreal(ae_fabs(xr1, _state), ae_fabs(xr2, _state), _state);
            
            /*
             * Further scaling if  norm(A) norm(X) > overflow
             */
            if( ae_fp_greater(*xnorm,1)&&ae_fp_greater(cmax,1) )
            {
                if( ae_fp_greater(*xnorm,bignum/cmax) )
                {
                    temp = cmax/bignum;
                    x->ptr.pp_double[1][1] = temp*x->ptr.pp_double[1][1];
                    x->ptr.pp_double[2][1] = temp*x->ptr.pp_double[2][1];
                    *xnorm = temp*(*xnorm);
                    *scl = temp*(*scl);
                }
            }
        }
        else
        {
            
            /*
             * Complex 2x2 system  (w is complex)
             *
             * Find the largest element in C
             */
            civ4->ptr.p_double[1+0] = -wi*d1;
            civ4->ptr.p_double[2+0] = 0;
            civ4->ptr.p_double[1+2] = 0;
            civ4->ptr.p_double[2+2] = -wi*d2;
            cmax = 0;
            icmax = 0;
            for(j=1; j<=4; j++)
            {
                if( ae_fp_greater(ae_fabs(crv4->ptr.p_double[j], _state)+ae_fabs(civ4->ptr.p_double[j], _state),cmax) )
                {
                    cmax = ae_fabs(crv4->ptr.p_double[j], _state)+ae_fabs(civ4->ptr.p_double[j], _state);
                    icmax = j;
                }
            }
            
            /*
             * If norm(C) < SMINI, use SMINI*identity.
             */
            if( ae_fp_less(cmax,smini) )
            {
                bnorm = ae_maxreal(ae_fabs(b->ptr.pp_double[1][1], _state)+ae_fabs(b->ptr.pp_double[1][2], _state), ae_fabs(b->ptr.pp_double[2][1], _state)+ae_fabs(b->ptr.pp_double[2][2], _state), _state);
                if( ae_fp_less(smini,1)&&ae_fp_greater(bnorm,1) )
                {
                    if( ae_fp_greater(bnorm,bignum*smini) )
                    {
                        *scl = 1/bnorm;
                    }
                }
                temp = *scl/smini;
                x->ptr.pp_double[1][1] = temp*b->ptr.pp_double[1][1];
                x->ptr.pp_double[2][1] = temp*b->ptr.pp_double[2][1];
                x->ptr.pp_double[1][2] = temp*b->ptr.pp_double[1][2];
                x->ptr.pp_double[2][2] = temp*b->ptr.pp_double[2][2];
                *xnorm = temp*bnorm;
                *info = 1;
                return;
            }
            
            /*
             * Gaussian elimination with complete pivoting.
             */
            ur11 = crv4->ptr.p_double[icmax];
            ui11 = civ4->ptr.p_double[icmax];
            cr21 = crv4->ptr.p_double[ipivot44->ptr.pp_int[2][icmax]];
            ci21 = civ4->ptr.p_double[ipivot44->ptr.pp_int[2][icmax]];
            ur12 = crv4->ptr.p_double[ipivot44->ptr.pp_int[3][icmax]];
            ui12 = civ4->ptr.p_double[ipivot44->ptr.pp_int[3][icmax]];
            cr22 = crv4->ptr.p_double[ipivot44->ptr.pp_int[4][icmax]];
            ci22 = civ4->ptr.p_double[ipivot44->ptr.pp_int[4][icmax]];
            if( icmax==1||icmax==4 )
            {
                
                /*
                 * Code when off-diagonals of pivoted C are real
                 */
                if( ae_fp_greater(ae_fabs(ur11, _state),ae_fabs(ui11, _state)) )
                {
                    temp = ui11/ur11;
                    ur11r = 1/(ur11*(1+ae_sqr(temp, _state)));
                    ui11r = -temp*ur11r;
                }
                else
                {
                    temp = ur11/ui11;
                    ui11r = -1/(ui11*(1+ae_sqr(temp, _state)));
                    ur11r = -temp*ui11r;
                }
                lr21 = cr21*ur11r;
                li21 = cr21*ui11r;
                ur12s = ur12*ur11r;
                ui12s = ur12*ui11r;
                ur22 = cr22-ur12*lr21;
                ui22 = ci22-ur12*li21;
            }
            else
            {
                
                /*
                 * Code when diagonals of pivoted C are real
                 */
                ur11r = 1/ur11;
                ui11r = 0;
                lr21 = cr21*ur11r;
                li21 = ci21*ur11r;
                ur12s = ur12*ur11r;
                ui12s = ui12*ur11r;
                ur22 = cr22-ur12*lr21+ui12*li21;
                ui22 = -ur12*li21-ui12*lr21;
            }
            u22abs = ae_fabs(ur22, _state)+ae_fabs(ui22, _state);
            
            /*
             * If smaller pivot < SMINI, use SMINI
             */
            if( ae_fp_less(u22abs,smini) )
            {
                ur22 = smini;
                ui22 = 0;
                *info = 1;
            }
            if( rswap4->ptr.p_bool[icmax] )
            {
                br2 = b->ptr.pp_double[1][1];
                br1 = b->ptr.pp_double[2][1];
                bi2 = b->ptr.pp_double[1][2];
                bi1 = b->ptr.pp_double[2][2];
            }
            else
            {
                br1 = b->ptr.pp_double[1][1];
                br2 = b->ptr.pp_double[2][1];
                bi1 = b->ptr.pp_double[1][2];
                bi2 = b->ptr.pp_double[2][2];
            }
            br2 = br2-lr21*br1+li21*bi1;
            bi2 = bi2-li21*br1-lr21*bi1;
            bbnd = ae_maxreal((ae_fabs(br1, _state)+ae_fabs(bi1, _state))*(u22abs*(ae_fabs(ur11r, _state)+ae_fabs(ui11r, _state))), ae_fabs(br2, _state)+ae_fabs(bi2, _state), _state);
            if( ae_fp_greater(bbnd,1)&&ae_fp_less(u22abs,1) )
            {
                if( ae_fp_greater_eq(bbnd,bignum*u22abs) )
                {
                    *scl = 1/bbnd;
                    br1 = *scl*br1;
                    bi1 = *scl*bi1;
                    br2 = *scl*br2;
                    bi2 = *scl*bi2;
                }
            }
            evd_internalhsevdladiv(br2, bi2, ur22, ui22, &xr2, &xi2, _state);
            xr1 = ur11r*br1-ui11r*bi1-ur12s*xr2+ui12s*xi2;
            xi1 = ui11r*br1+ur11r*bi1-ui12s*xr2-ur12s*xi2;
            if( zswap4->ptr.p_bool[icmax] )
            {
                x->ptr.pp_double[1][1] = xr2;
                x->ptr.pp_double[2][1] = xr1;
                x->ptr.pp_double[1][2] = xi2;
                x->ptr.pp_double[2][2] = xi1;
            }
            else
            {
                x->ptr.pp_double[1][1] = xr1;
                x->ptr.pp_double[2][1] = xr2;
                x->ptr.pp_double[1][2] = xi1;
                x->ptr.pp_double[2][2] = xi2;
            }
            *xnorm = ae_maxreal(ae_fabs(xr1, _state)+ae_fabs(xi1, _state), ae_fabs(xr2, _state)+ae_fabs(xi2, _state), _state);
            
            /*
             * Further scaling if  norm(A) norm(X) > overflow
             */
            if( ae_fp_greater(*xnorm,1)&&ae_fp_greater(cmax,1) )
            {
                if( ae_fp_greater(*xnorm,bignum/cmax) )
                {
                    temp = cmax/bignum;
                    x->ptr.pp_double[1][1] = temp*x->ptr.pp_double[1][1];
                    x->ptr.pp_double[2][1] = temp*x->ptr.pp_double[2][1];
                    x->ptr.pp_double[1][2] = temp*x->ptr.pp_double[1][2];
                    x->ptr.pp_double[2][2] = temp*x->ptr.pp_double[2][2];
                    *xnorm = temp*(*xnorm);
                    *scl = temp*(*scl);
                }
            }
        }
    }
}


/*************************************************************************
performs complex division in  real arithmetic

                        a + i*b
             p + i*q = ---------
                        c + i*d

The algorithm is due to Robert L. Smith and can be found
in D. Knuth, The art of Computer Programming, Vol.2, p.195

  -- LAPACK auxiliary routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1992
*************************************************************************/
static void evd_internalhsevdladiv(double a,
     double b,
     double c,
     double d,
     double* p,
     double* q,
     ae_state *_state)
{
    double e;
    double f;

    *p = 0;
    *q = 0;

    if( ae_fp_less(ae_fabs(d, _state),ae_fabs(c, _state)) )
    {
        e = d/c;
        f = c+d*e;
        *p = (a+b*e)/f;
        *q = (b-a*e)/f;
    }
    else
    {
        e = c/d;
        f = d+c*e;
        *p = (b+a*e)/f;
        *q = (-a+b*e)/f;
    }
}


static ae_bool evd_nonsymmetricevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t vneeded,
     /* Real    */ ae_vector* wr,
     /* Real    */ ae_vector* wi,
     /* Real    */ ae_matrix* vl,
     /* Real    */ ae_matrix* vr,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_matrix s;
    ae_vector tau;
    ae_vector sel;
    ae_int_t i;
    ae_int_t info;
    ae_int_t m;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(wr);
    ae_vector_clear(wi);
    ae_matrix_clear(vl);
    ae_matrix_clear(vr);
    ae_matrix_init(&s, 0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&tau, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&sel, 0, DT_BOOL, _state, ae_true);

    ae_assert(vneeded>=0&&vneeded<=3, "NonSymmetricEVD: incorrect VNeeded!", _state);
    if( vneeded==0 )
    {
        
        /*
         * Eigen values only
         */
        evd_toupperhessenberg(a, n, &tau, _state);
        internalschurdecomposition(a, n, 0, 0, wr, wi, &s, &info, _state);
        result = info==0;
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Eigen values and vectors
     */
    evd_toupperhessenberg(a, n, &tau, _state);
    evd_unpackqfromupperhessenberg(a, n, &tau, &s, _state);
    internalschurdecomposition(a, n, 1, 1, wr, wi, &s, &info, _state);
    result = info==0;
    if( !result )
    {
        ae_frame_leave(_state);
        return result;
    }
    if( vneeded==1||vneeded==3 )
    {
        ae_matrix_set_length(vr, n+1, n+1, _state);
        for(i=1; i<=n; i++)
        {
            ae_v_move(&vr->ptr.pp_double[i][1], 1, &s.ptr.pp_double[i][1], 1, ae_v_len(1,n));
        }
    }
    if( vneeded==2||vneeded==3 )
    {
        ae_matrix_set_length(vl, n+1, n+1, _state);
        for(i=1; i<=n; i++)
        {
            ae_v_move(&vl->ptr.pp_double[i][1], 1, &s.ptr.pp_double[i][1], 1, ae_v_len(1,n));
        }
    }
    evd_internaltrevc(a, n, vneeded, 1, &sel, vl, vr, &m, &info, _state);
    result = info==0;
    ae_frame_leave(_state);
    return result;
}


static void evd_toupperhessenberg(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t ip1;
    ae_int_t nmi;
    double v;
    ae_vector t;
    ae_vector work;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(tau);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    ae_assert(n>=0, "ToUpperHessenberg: incorrect N!", _state);
    
    /*
     * Quick return if possible
     */
    if( n<=1 )
    {
        ae_frame_leave(_state);
        return;
    }
    ae_vector_set_length(tau, n-1+1, _state);
    ae_vector_set_length(&t, n+1, _state);
    ae_vector_set_length(&work, n+1, _state);
    for(i=1; i<=n-1; i++)
    {
        
        /*
         * Compute elementary reflector H(i) to annihilate A(i+2:ihi,i)
         */
        ip1 = i+1;
        nmi = n-i;
        ae_v_move(&t.ptr.p_double[1], 1, &a->ptr.pp_double[ip1][i], a->stride, ae_v_len(1,nmi));
        generatereflection(&t, nmi, &v, _state);
        ae_v_move(&a->ptr.pp_double[ip1][i], a->stride, &t.ptr.p_double[1], 1, ae_v_len(ip1,n));
        tau->ptr.p_double[i] = v;
        t.ptr.p_double[1] = 1;
        
        /*
         * Apply H(i) to A(1:ihi,i+1:ihi) from the right
         */
        applyreflectionfromtheright(a, v, &t, 1, n, i+1, n, &work, _state);
        
        /*
         * Apply H(i) to A(i+1:ihi,i+1:n) from the left
         */
        applyreflectionfromtheleft(a, v, &t, i+1, n, i+1, n, &work, _state);
    }
    ae_frame_leave(_state);
}


static void evd_unpackqfromupperhessenberg(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_matrix* q,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector v;
    ae_vector work;
    ae_int_t ip1;
    ae_int_t nmi;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(q);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    if( n==0 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * init
     */
    ae_matrix_set_length(q, n+1, n+1, _state);
    ae_vector_set_length(&v, n+1, _state);
    ae_vector_set_length(&work, n+1, _state);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if( i==j )
            {
                q->ptr.pp_double[i][j] = 1;
            }
            else
            {
                q->ptr.pp_double[i][j] = 0;
            }
        }
    }
    
    /*
     * unpack Q
     */
    for(i=1; i<=n-1; i++)
    {
        
        /*
         * Apply H(i)
         */
        ip1 = i+1;
        nmi = n-i;
        ae_v_move(&v.ptr.p_double[1], 1, &a->ptr.pp_double[ip1][i], a->stride, ae_v_len(1,nmi));
        v.ptr.p_double[1] = 1;
        applyreflectionfromtheright(q, tau->ptr.p_double[i], &v, 1, n, i+1, n, &work, _state);
    }
    ae_frame_leave(_state);
}




/*************************************************************************
Generation of a random uniformly distributed (Haar) orthogonal matrix

INPUT PARAMETERS:
    N   -   matrix size, N>=1
    
OUTPUT PARAMETERS:
    A   -   orthogonal NxN matrix, array[0..N-1,0..N-1]

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndorthogonal(ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;

    ae_matrix_clear(a);

    ae_assert(n>=1, "RMatrixRndOrthogonal: N<1!", _state);
    ae_matrix_set_length(a, n, n, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                a->ptr.pp_double[i][j] = 1;
            }
            else
            {
                a->ptr.pp_double[i][j] = 0;
            }
        }
    }
    rmatrixrndorthogonalfromtheright(a, n, n, _state);
}


/*************************************************************************
Generation of random NxN matrix with given condition number and norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndcond(ae_int_t n,
     double c,
     /* Real    */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double l1;
    double l2;

    ae_matrix_clear(a);

    ae_assert(n>=1&&ae_fp_greater_eq(c,1), "RMatrixRndCond: N<1 or C<1!", _state);
    ae_matrix_set_length(a, n, n, _state);
    if( n==1 )
    {
        
        /*
         * special case
         */
        a->ptr.pp_double[0][0] = 2*ae_randominteger(2, _state)-1;
        return;
    }
    l1 = 0;
    l2 = ae_log(1/c, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_double[i][j] = 0;
        }
    }
    a->ptr.pp_double[0][0] = ae_exp(l1, _state);
    for(i=1; i<=n-2; i++)
    {
        a->ptr.pp_double[i][i] = ae_exp(ae_randomreal(_state)*(l2-l1)+l1, _state);
    }
    a->ptr.pp_double[n-1][n-1] = ae_exp(l2, _state);
    rmatrixrndorthogonalfromtheleft(a, n, n, _state);
    rmatrixrndorthogonalfromtheright(a, n, n, _state);
}


/*************************************************************************
Generation of a random Haar distributed orthogonal complex matrix

INPUT PARAMETERS:
    N   -   matrix size, N>=1

OUTPUT PARAMETERS:
    A   -   orthogonal NxN matrix, array[0..N-1,0..N-1]

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndorthogonal(ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;

    ae_matrix_clear(a);

    ae_assert(n>=1, "CMatrixRndOrthogonal: N<1!", _state);
    ae_matrix_set_length(a, n, n, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            if( i==j )
            {
                a->ptr.pp_complex[i][j] = ae_complex_from_d(1);
            }
            else
            {
                a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
            }
        }
    }
    cmatrixrndorthogonalfromtheright(a, n, n, _state);
}


/*************************************************************************
Generation of random NxN complex matrix with given condition number C and
norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndcond(ae_int_t n,
     double c,
     /* Complex */ ae_matrix* a,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    double l1;
    double l2;
    hqrndstate state;
    ae_complex v;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(a);
    _hqrndstate_init(&state, _state, ae_true);

    ae_assert(n>=1&&ae_fp_greater_eq(c,1), "CMatrixRndCond: N<1 or C<1!", _state);
    ae_matrix_set_length(a, n, n, _state);
    if( n==1 )
    {
        
        /*
         * special case
         */
        hqrndrandomize(&state, _state);
        hqrndunit2(&state, &v.x, &v.y, _state);
        a->ptr.pp_complex[0][0] = v;
        ae_frame_leave(_state);
        return;
    }
    l1 = 0;
    l2 = ae_log(1/c, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
        }
    }
    a->ptr.pp_complex[0][0] = ae_complex_from_d(ae_exp(l1, _state));
    for(i=1; i<=n-2; i++)
    {
        a->ptr.pp_complex[i][i] = ae_complex_from_d(ae_exp(ae_randomreal(_state)*(l2-l1)+l1, _state));
    }
    a->ptr.pp_complex[n-1][n-1] = ae_complex_from_d(ae_exp(l2, _state));
    cmatrixrndorthogonalfromtheleft(a, n, n, _state);
    cmatrixrndorthogonalfromtheright(a, n, n, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Generation of random NxN symmetric matrix with given condition number  and
norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void smatrixrndcond(ae_int_t n,
     double c,
     /* Real    */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double l1;
    double l2;

    ae_matrix_clear(a);

    ae_assert(n>=1&&ae_fp_greater_eq(c,1), "SMatrixRndCond: N<1 or C<1!", _state);
    ae_matrix_set_length(a, n, n, _state);
    if( n==1 )
    {
        
        /*
         * special case
         */
        a->ptr.pp_double[0][0] = 2*ae_randominteger(2, _state)-1;
        return;
    }
    
    /*
     * Prepare matrix
     */
    l1 = 0;
    l2 = ae_log(1/c, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_double[i][j] = 0;
        }
    }
    a->ptr.pp_double[0][0] = ae_exp(l1, _state);
    for(i=1; i<=n-2; i++)
    {
        a->ptr.pp_double[i][i] = (2*ae_randominteger(2, _state)-1)*ae_exp(ae_randomreal(_state)*(l2-l1)+l1, _state);
    }
    a->ptr.pp_double[n-1][n-1] = ae_exp(l2, _state);
    
    /*
     * Multiply
     */
    smatrixrndmultiply(a, n, _state);
}


/*************************************************************************
Generation of random NxN symmetric positive definite matrix with given
condition number and norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random SPD matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void spdmatrixrndcond(ae_int_t n,
     double c,
     /* Real    */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double l1;
    double l2;

    ae_matrix_clear(a);

    
    /*
     * Special cases
     */
    if( n<=0||ae_fp_less(c,1) )
    {
        return;
    }
    ae_matrix_set_length(a, n, n, _state);
    if( n==1 )
    {
        a->ptr.pp_double[0][0] = 1;
        return;
    }
    
    /*
     * Prepare matrix
     */
    l1 = 0;
    l2 = ae_log(1/c, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_double[i][j] = 0;
        }
    }
    a->ptr.pp_double[0][0] = ae_exp(l1, _state);
    for(i=1; i<=n-2; i++)
    {
        a->ptr.pp_double[i][i] = ae_exp(ae_randomreal(_state)*(l2-l1)+l1, _state);
    }
    a->ptr.pp_double[n-1][n-1] = ae_exp(l2, _state);
    
    /*
     * Multiply
     */
    smatrixrndmultiply(a, n, _state);
}


/*************************************************************************
Generation of random NxN Hermitian matrix with given condition number  and
norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void hmatrixrndcond(ae_int_t n,
     double c,
     /* Complex */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double l1;
    double l2;

    ae_matrix_clear(a);

    ae_assert(n>=1&&ae_fp_greater_eq(c,1), "HMatrixRndCond: N<1 or C<1!", _state);
    ae_matrix_set_length(a, n, n, _state);
    if( n==1 )
    {
        
        /*
         * special case
         */
        a->ptr.pp_complex[0][0] = ae_complex_from_d(2*ae_randominteger(2, _state)-1);
        return;
    }
    
    /*
     * Prepare matrix
     */
    l1 = 0;
    l2 = ae_log(1/c, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
        }
    }
    a->ptr.pp_complex[0][0] = ae_complex_from_d(ae_exp(l1, _state));
    for(i=1; i<=n-2; i++)
    {
        a->ptr.pp_complex[i][i] = ae_complex_from_d((2*ae_randominteger(2, _state)-1)*ae_exp(ae_randomreal(_state)*(l2-l1)+l1, _state));
    }
    a->ptr.pp_complex[n-1][n-1] = ae_complex_from_d(ae_exp(l2, _state));
    
    /*
     * Multiply
     */
    hmatrixrndmultiply(a, n, _state);
    
    /*
     * post-process to ensure that matrix diagonal is real
     */
    for(i=0; i<=n-1; i++)
    {
        a->ptr.pp_complex[i][i].y = 0;
    }
}


/*************************************************************************
Generation of random NxN Hermitian positive definite matrix with given
condition number and norm2(A)=1

INPUT PARAMETERS:
    N   -   matrix size
    C   -   condition number (in 2-norm)

OUTPUT PARAMETERS:
    A   -   random HPD matrix with norm2(A)=1 and cond(A)=C

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixrndcond(ae_int_t n,
     double c,
     /* Complex */ ae_matrix* a,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double l1;
    double l2;

    ae_matrix_clear(a);

    
    /*
     * Special cases
     */
    if( n<=0||ae_fp_less(c,1) )
    {
        return;
    }
    ae_matrix_set_length(a, n, n, _state);
    if( n==1 )
    {
        a->ptr.pp_complex[0][0] = ae_complex_from_d(1);
        return;
    }
    
    /*
     * Prepare matrix
     */
    l1 = 0;
    l2 = ae_log(1/c, _state);
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
        }
    }
    a->ptr.pp_complex[0][0] = ae_complex_from_d(ae_exp(l1, _state));
    for(i=1; i<=n-2; i++)
    {
        a->ptr.pp_complex[i][i] = ae_complex_from_d(ae_exp(ae_randomreal(_state)*(l2-l1)+l1, _state));
    }
    a->ptr.pp_complex[n-1][n-1] = ae_complex_from_d(ae_exp(l2, _state));
    
    /*
     * Multiply
     */
    hmatrixrndmultiply(a, n, _state);
    
    /*
     * post-process to ensure that matrix diagonal is real
     */
    for(i=0; i<=n-1; i++)
    {
        a->ptr.pp_complex[i][i].y = 0;
    }
}


/*************************************************************************
Multiplication of MxN matrix by NxN random Haar distributed orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndorthogonalfromtheright(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    double tau;
    double lambdav;
    ae_int_t s;
    ae_int_t i;
    double u1;
    double u2;
    ae_vector w;
    ae_vector v;
    hqrndstate state;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&w, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    _hqrndstate_init(&state, _state, ae_true);

    ae_assert(n>=1&&m>=1, "RMatrixRndOrthogonalFromTheRight: N<1 or M<1!", _state);
    if( n==1 )
    {
        
        /*
         * Special case
         */
        tau = 2*ae_randominteger(2, _state)-1;
        for(i=0; i<=m-1; i++)
        {
            a->ptr.pp_double[i][0] = a->ptr.pp_double[i][0]*tau;
        }
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * General case.
     * First pass.
     */
    ae_vector_set_length(&w, m, _state);
    ae_vector_set_length(&v, n+1, _state);
    hqrndrandomize(&state, _state);
    for(s=2; s<=n; s++)
    {
        
        /*
         * Prepare random normal v
         */
        do
        {
            i = 1;
            while(i<=s)
            {
                hqrndnormal2(&state, &u1, &u2, _state);
                v.ptr.p_double[i] = u1;
                if( i+1<=s )
                {
                    v.ptr.p_double[i+1] = u2;
                }
                i = i+2;
            }
            lambdav = ae_v_dotproduct(&v.ptr.p_double[1], 1, &v.ptr.p_double[1], 1, ae_v_len(1,s));
        }
        while(ae_fp_eq(lambdav,0));
        
        /*
         * Prepare and apply reflection
         */
        generatereflection(&v, s, &tau, _state);
        v.ptr.p_double[1] = 1;
        applyreflectionfromtheright(a, tau, &v, 0, m-1, n-s, n-1, &w, _state);
    }
    
    /*
     * Second pass.
     */
    for(i=0; i<=n-1; i++)
    {
        tau = 2*ae_randominteger(2, _state)-1;
        ae_v_muld(&a->ptr.pp_double[0][i], a->stride, ae_v_len(0,m-1), tau);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Multiplication of MxN matrix by MxM random Haar distributed orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   Q*A, where Q is random MxM orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrndorthogonalfromtheleft(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    double tau;
    double lambdav;
    ae_int_t s;
    ae_int_t i;
    ae_int_t j;
    double u1;
    double u2;
    ae_vector w;
    ae_vector v;
    hqrndstate state;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&w, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    _hqrndstate_init(&state, _state, ae_true);

    ae_assert(n>=1&&m>=1, "RMatrixRndOrthogonalFromTheRight: N<1 or M<1!", _state);
    if( m==1 )
    {
        
        /*
         * special case
         */
        tau = 2*ae_randominteger(2, _state)-1;
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_double[0][j] = a->ptr.pp_double[0][j]*tau;
        }
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * General case.
     * First pass.
     */
    ae_vector_set_length(&w, n, _state);
    ae_vector_set_length(&v, m+1, _state);
    hqrndrandomize(&state, _state);
    for(s=2; s<=m; s++)
    {
        
        /*
         * Prepare random normal v
         */
        do
        {
            i = 1;
            while(i<=s)
            {
                hqrndnormal2(&state, &u1, &u2, _state);
                v.ptr.p_double[i] = u1;
                if( i+1<=s )
                {
                    v.ptr.p_double[i+1] = u2;
                }
                i = i+2;
            }
            lambdav = ae_v_dotproduct(&v.ptr.p_double[1], 1, &v.ptr.p_double[1], 1, ae_v_len(1,s));
        }
        while(ae_fp_eq(lambdav,0));
        
        /*
         * Prepare and apply reflection
         */
        generatereflection(&v, s, &tau, _state);
        v.ptr.p_double[1] = 1;
        applyreflectionfromtheleft(a, tau, &v, m-s, m-1, 0, n-1, &w, _state);
    }
    
    /*
     * Second pass.
     */
    for(i=0; i<=m-1; i++)
    {
        tau = 2*ae_randominteger(2, _state)-1;
        ae_v_muld(&a->ptr.pp_double[i][0], 1, ae_v_len(0,n-1), tau);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Multiplication of MxN complex matrix by NxN random Haar distributed
complex orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndorthogonalfromtheright(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_complex lambdav;
    ae_complex tau;
    ae_int_t s;
    ae_int_t i;
    ae_vector w;
    ae_vector v;
    hqrndstate state;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&w, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&v, 0, DT_COMPLEX, _state, ae_true);
    _hqrndstate_init(&state, _state, ae_true);

    ae_assert(n>=1&&m>=1, "CMatrixRndOrthogonalFromTheRight: N<1 or M<1!", _state);
    if( n==1 )
    {
        
        /*
         * Special case
         */
        hqrndrandomize(&state, _state);
        hqrndunit2(&state, &tau.x, &tau.y, _state);
        for(i=0; i<=m-1; i++)
        {
            a->ptr.pp_complex[i][0] = ae_c_mul(a->ptr.pp_complex[i][0],tau);
        }
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * General case.
     * First pass.
     */
    ae_vector_set_length(&w, m, _state);
    ae_vector_set_length(&v, n+1, _state);
    hqrndrandomize(&state, _state);
    for(s=2; s<=n; s++)
    {
        
        /*
         * Prepare random normal v
         */
        do
        {
            for(i=1; i<=s; i++)
            {
                hqrndnormal2(&state, &tau.x, &tau.y, _state);
                v.ptr.p_complex[i] = tau;
            }
            lambdav = ae_v_cdotproduct(&v.ptr.p_complex[1], 1, "N", &v.ptr.p_complex[1], 1, "Conj", ae_v_len(1,s));
        }
        while(ae_c_eq_d(lambdav,0));
        
        /*
         * Prepare and apply reflection
         */
        complexgeneratereflection(&v, s, &tau, _state);
        v.ptr.p_complex[1] = ae_complex_from_d(1);
        complexapplyreflectionfromtheright(a, tau, &v, 0, m-1, n-s, n-1, &w, _state);
    }
    
    /*
     * Second pass.
     */
    for(i=0; i<=n-1; i++)
    {
        hqrndunit2(&state, &tau.x, &tau.y, _state);
        ae_v_cmulc(&a->ptr.pp_complex[0][i], a->stride, ae_v_len(0,m-1), tau);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Multiplication of MxN complex matrix by MxM random Haar distributed
complex orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..M-1, 0..N-1]
    M, N-   matrix size

OUTPUT PARAMETERS:
    A   -   Q*A, where Q is random MxM orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void cmatrixrndorthogonalfromtheleft(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_complex tau;
    ae_complex lambdav;
    ae_int_t s;
    ae_int_t i;
    ae_int_t j;
    ae_vector w;
    ae_vector v;
    hqrndstate state;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&w, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&v, 0, DT_COMPLEX, _state, ae_true);
    _hqrndstate_init(&state, _state, ae_true);

    ae_assert(n>=1&&m>=1, "CMatrixRndOrthogonalFromTheRight: N<1 or M<1!", _state);
    if( m==1 )
    {
        
        /*
         * special case
         */
        hqrndrandomize(&state, _state);
        hqrndunit2(&state, &tau.x, &tau.y, _state);
        for(j=0; j<=n-1; j++)
        {
            a->ptr.pp_complex[0][j] = ae_c_mul(a->ptr.pp_complex[0][j],tau);
        }
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * General case.
     * First pass.
     */
    ae_vector_set_length(&w, n, _state);
    ae_vector_set_length(&v, m+1, _state);
    hqrndrandomize(&state, _state);
    for(s=2; s<=m; s++)
    {
        
        /*
         * Prepare random normal v
         */
        do
        {
            for(i=1; i<=s; i++)
            {
                hqrndnormal2(&state, &tau.x, &tau.y, _state);
                v.ptr.p_complex[i] = tau;
            }
            lambdav = ae_v_cdotproduct(&v.ptr.p_complex[1], 1, "N", &v.ptr.p_complex[1], 1, "Conj", ae_v_len(1,s));
        }
        while(ae_c_eq_d(lambdav,0));
        
        /*
         * Prepare and apply reflection
         */
        complexgeneratereflection(&v, s, &tau, _state);
        v.ptr.p_complex[1] = ae_complex_from_d(1);
        complexapplyreflectionfromtheleft(a, tau, &v, m-s, m-1, 0, n-1, &w, _state);
    }
    
    /*
     * Second pass.
     */
    for(i=0; i<=m-1; i++)
    {
        hqrndunit2(&state, &tau.x, &tau.y, _state);
        ae_v_cmulc(&a->ptr.pp_complex[i][0], 1, ae_v_len(0,n-1), tau);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Symmetric multiplication of NxN matrix by random Haar distributed
orthogonal  matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..N-1, 0..N-1]
    N   -   matrix size

OUTPUT PARAMETERS:
    A   -   Q'*A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void smatrixrndmultiply(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    double tau;
    double lambdav;
    ae_int_t s;
    ae_int_t i;
    double u1;
    double u2;
    ae_vector w;
    ae_vector v;
    hqrndstate state;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&w, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&v, 0, DT_REAL, _state, ae_true);
    _hqrndstate_init(&state, _state, ae_true);

    
    /*
     * General case.
     */
    ae_vector_set_length(&w, n, _state);
    ae_vector_set_length(&v, n+1, _state);
    hqrndrandomize(&state, _state);
    for(s=2; s<=n; s++)
    {
        
        /*
         * Prepare random normal v
         */
        do
        {
            i = 1;
            while(i<=s)
            {
                hqrndnormal2(&state, &u1, &u2, _state);
                v.ptr.p_double[i] = u1;
                if( i+1<=s )
                {
                    v.ptr.p_double[i+1] = u2;
                }
                i = i+2;
            }
            lambdav = ae_v_dotproduct(&v.ptr.p_double[1], 1, &v.ptr.p_double[1], 1, ae_v_len(1,s));
        }
        while(ae_fp_eq(lambdav,0));
        
        /*
         * Prepare and apply reflection
         */
        generatereflection(&v, s, &tau, _state);
        v.ptr.p_double[1] = 1;
        applyreflectionfromtheright(a, tau, &v, 0, n-1, n-s, n-1, &w, _state);
        applyreflectionfromtheleft(a, tau, &v, n-s, n-1, 0, n-1, &w, _state);
    }
    
    /*
     * Second pass.
     */
    for(i=0; i<=n-1; i++)
    {
        tau = 2*ae_randominteger(2, _state)-1;
        ae_v_muld(&a->ptr.pp_double[0][i], a->stride, ae_v_len(0,n-1), tau);
        ae_v_muld(&a->ptr.pp_double[i][0], 1, ae_v_len(0,n-1), tau);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Hermitian multiplication of NxN matrix by random Haar distributed
complex orthogonal matrix

INPUT PARAMETERS:
    A   -   matrix, array[0..N-1, 0..N-1]
    N   -   matrix size

OUTPUT PARAMETERS:
    A   -   Q^H*A*Q, where Q is random NxN orthogonal matrix

  -- ALGLIB routine --
     04.12.2009
     Bochkanov Sergey
*************************************************************************/
void hmatrixrndmultiply(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_complex tau;
    ae_complex lambdav;
    ae_int_t s;
    ae_int_t i;
    ae_vector w;
    ae_vector v;
    hqrndstate state;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&w, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&v, 0, DT_COMPLEX, _state, ae_true);
    _hqrndstate_init(&state, _state, ae_true);

    
    /*
     * General case.
     */
    ae_vector_set_length(&w, n, _state);
    ae_vector_set_length(&v, n+1, _state);
    hqrndrandomize(&state, _state);
    for(s=2; s<=n; s++)
    {
        
        /*
         * Prepare random normal v
         */
        do
        {
            for(i=1; i<=s; i++)
            {
                hqrndnormal2(&state, &tau.x, &tau.y, _state);
                v.ptr.p_complex[i] = tau;
            }
            lambdav = ae_v_cdotproduct(&v.ptr.p_complex[1], 1, "N", &v.ptr.p_complex[1], 1, "Conj", ae_v_len(1,s));
        }
        while(ae_c_eq_d(lambdav,0));
        
        /*
         * Prepare and apply reflection
         */
        complexgeneratereflection(&v, s, &tau, _state);
        v.ptr.p_complex[1] = ae_complex_from_d(1);
        complexapplyreflectionfromtheright(a, tau, &v, 0, n-1, n-s, n-1, &w, _state);
        complexapplyreflectionfromtheleft(a, ae_c_conj(tau, _state), &v, n-s, n-1, 0, n-1, &w, _state);
    }
    
    /*
     * Second pass.
     */
    for(i=0; i<=n-1; i++)
    {
        hqrndunit2(&state, &tau.x, &tau.y, _state);
        ae_v_cmulc(&a->ptr.pp_complex[0][i], a->stride, ae_v_len(0,n-1), tau);
        tau = ae_c_conj(tau, _state);
        ae_v_cmulc(&a->ptr.pp_complex[i][0], 1, ae_v_len(0,n-1), tau);
    }
    ae_frame_leave(_state);
}




/*************************************************************************
LU decomposition of a general real matrix with row pivoting

A is represented as A = P*L*U, where:
* L is lower unitriangular matrix
* U is upper triangular matrix
* P = P0*P1*...*PK, K=min(M,N)-1,
  Pi - permutation matrix for I and Pivots[I]

This is cache-oblivous implementation of LU decomposition.
It is optimized for square matrices. As for rectangular matrices:
* best case - M>>N
* worst case - N>>M, small M, large N, matrix does not fit in CPU cache

INPUT PARAMETERS:
    A       -   array[0..M-1, 0..N-1].
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.


OUTPUT PARAMETERS:
    A       -   matrices L and U in compact form:
                * L is stored under main diagonal
                * U is stored on and above main diagonal
    Pivots  -   permutation matrix in compact form.
                array[0..Min(M-1,N-1)].

  -- ALGLIB routine --
     10.01.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixlu(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state)
{

    ae_vector_clear(pivots);

    ae_assert(m>0, "RMatrixLU: incorrect M!", _state);
    ae_assert(n>0, "RMatrixLU: incorrect N!", _state);
    rmatrixplu(a, m, n, pivots, _state);
}


/*************************************************************************
LU decomposition of a general complex matrix with row pivoting

A is represented as A = P*L*U, where:
* L is lower unitriangular matrix
* U is upper triangular matrix
* P = P0*P1*...*PK, K=min(M,N)-1,
  Pi - permutation matrix for I and Pivots[I]

This is cache-oblivous implementation of LU decomposition. It is optimized
for square matrices. As for rectangular matrices:
* best case - M>>N
* worst case - N>>M, small M, large N, matrix does not fit in CPU cache

INPUT PARAMETERS:
    A       -   array[0..M-1, 0..N-1].
    M       -   number of rows in matrix A.
    N       -   number of columns in matrix A.


OUTPUT PARAMETERS:
    A       -   matrices L and U in compact form:
                * L is stored under main diagonal
                * U is stored on and above main diagonal
    Pivots  -   permutation matrix in compact form.
                array[0..Min(M-1,N-1)].

  -- ALGLIB routine --
     10.01.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixlu(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state)
{

    ae_vector_clear(pivots);

    ae_assert(m>0, "CMatrixLU: incorrect M!", _state);
    ae_assert(n>0, "CMatrixLU: incorrect N!", _state);
    cmatrixplu(a, m, n, pivots, _state);
}


/*************************************************************************
Cache-oblivious Cholesky decomposition

The algorithm computes Cholesky decomposition  of  a  Hermitian  positive-
definite matrix. The result of an algorithm is a representation  of  A  as
A=U'*U  or A=L*L' (here X' detones conj(X^T)).

INPUT PARAMETERS:
    A       -   upper or lower triangle of a factorized matrix.
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   if IsUpper=True, then A contains an upper triangle of
                a symmetric matrix, otherwise A contains a lower one.

OUTPUT PARAMETERS:
    A       -   the result of factorization. If IsUpper=True, then
                the upper triangle contains matrix U, so that A = U'*U,
                and the elements below the main diagonal are not modified.
                Similarly, if IsUpper = False.

RESULT:
    If  the  matrix  is  positive-definite,  the  function  returns  True.
    Otherwise, the function returns False. Contents of A is not determined
    in such case.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
ae_bool hpdmatrixcholesky(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector tmp;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&tmp, 0, DT_COMPLEX, _state, ae_true);

    if( n<1 )
    {
        result = ae_false;
        ae_frame_leave(_state);
        return result;
    }
    result = trfac_hpdmatrixcholeskyrec(a, 0, n, isupper, &tmp, _state);
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Cache-oblivious Cholesky decomposition

The algorithm computes Cholesky decomposition  of  a  symmetric  positive-
definite matrix. The result of an algorithm is a representation  of  A  as
A=U^T*U  or A=L*L^T

INPUT PARAMETERS:
    A       -   upper or lower triangle of a factorized matrix.
                array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   if IsUpper=True, then A contains an upper triangle of
                a symmetric matrix, otherwise A contains a lower one.

OUTPUT PARAMETERS:
    A       -   the result of factorization. If IsUpper=True, then
                the upper triangle contains matrix U, so that A = U^T*U,
                and the elements below the main diagonal are not modified.
                Similarly, if IsUpper = False.

RESULT:
    If  the  matrix  is  positive-definite,  the  function  returns  True.
    Otherwise, the function returns False. Contents of A is not determined
    in such case.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
ae_bool spdmatrixcholesky(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector tmp;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);

    if( n<1 )
    {
        result = ae_false;
        ae_frame_leave(_state);
        return result;
    }
    result = spdmatrixcholeskyrec(a, 0, n, isupper, &tmp, _state);
    ae_frame_leave(_state);
    return result;
}


void rmatrixlup(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector tmp;
    ae_int_t i;
    ae_int_t j;
    double mx;
    double v;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(pivots);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);

    
    /*
     * Internal LU decomposition subroutine.
     * Never call it directly.
     */
    ae_assert(m>0, "RMatrixLUP: incorrect M!", _state);
    ae_assert(n>0, "RMatrixLUP: incorrect N!", _state);
    
    /*
     * Scale matrix to avoid overflows,
     * decompose it, then scale back.
     */
    mx = 0;
    for(i=0; i<=m-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            mx = ae_maxreal(mx, ae_fabs(a->ptr.pp_double[i][j], _state), _state);
        }
    }
    if( ae_fp_neq(mx,0) )
    {
        v = 1/mx;
        for(i=0; i<=m-1; i++)
        {
            ae_v_muld(&a->ptr.pp_double[i][0], 1, ae_v_len(0,n-1), v);
        }
    }
    ae_vector_set_length(pivots, ae_minint(m, n, _state), _state);
    ae_vector_set_length(&tmp, 2*ae_maxint(m, n, _state), _state);
    trfac_rmatrixluprec(a, 0, m, n, pivots, &tmp, _state);
    if( ae_fp_neq(mx,0) )
    {
        v = mx;
        for(i=0; i<=m-1; i++)
        {
            ae_v_muld(&a->ptr.pp_double[i][0], 1, ae_v_len(0,ae_minint(i, n-1, _state)), v);
        }
    }
    ae_frame_leave(_state);
}


void cmatrixlup(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector tmp;
    ae_int_t i;
    ae_int_t j;
    double mx;
    double v;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(pivots);
    ae_vector_init(&tmp, 0, DT_COMPLEX, _state, ae_true);

    
    /*
     * Internal LU decomposition subroutine.
     * Never call it directly.
     */
    ae_assert(m>0, "CMatrixLUP: incorrect M!", _state);
    ae_assert(n>0, "CMatrixLUP: incorrect N!", _state);
    
    /*
     * Scale matrix to avoid overflows,
     * decompose it, then scale back.
     */
    mx = 0;
    for(i=0; i<=m-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            mx = ae_maxreal(mx, ae_c_abs(a->ptr.pp_complex[i][j], _state), _state);
        }
    }
    if( ae_fp_neq(mx,0) )
    {
        v = 1/mx;
        for(i=0; i<=m-1; i++)
        {
            ae_v_cmuld(&a->ptr.pp_complex[i][0], 1, ae_v_len(0,n-1), v);
        }
    }
    ae_vector_set_length(pivots, ae_minint(m, n, _state), _state);
    ae_vector_set_length(&tmp, 2*ae_maxint(m, n, _state), _state);
    trfac_cmatrixluprec(a, 0, m, n, pivots, &tmp, _state);
    if( ae_fp_neq(mx,0) )
    {
        v = mx;
        for(i=0; i<=m-1; i++)
        {
            ae_v_cmuld(&a->ptr.pp_complex[i][0], 1, ae_v_len(0,ae_minint(i, n-1, _state)), v);
        }
    }
    ae_frame_leave(_state);
}


void rmatrixplu(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector tmp;
    ae_int_t i;
    ae_int_t j;
    double mx;
    double v;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(pivots);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);

    
    /*
     * Internal LU decomposition subroutine.
     * Never call it directly.
     */
    ae_assert(m>0, "RMatrixPLU: incorrect M!", _state);
    ae_assert(n>0, "RMatrixPLU: incorrect N!", _state);
    ae_vector_set_length(&tmp, 2*ae_maxint(m, n, _state), _state);
    ae_vector_set_length(pivots, ae_minint(m, n, _state), _state);
    
    /*
     * Scale matrix to avoid overflows,
     * decompose it, then scale back.
     */
    mx = 0;
    for(i=0; i<=m-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            mx = ae_maxreal(mx, ae_fabs(a->ptr.pp_double[i][j], _state), _state);
        }
    }
    if( ae_fp_neq(mx,0) )
    {
        v = 1/mx;
        for(i=0; i<=m-1; i++)
        {
            ae_v_muld(&a->ptr.pp_double[i][0], 1, ae_v_len(0,n-1), v);
        }
    }
    trfac_rmatrixplurec(a, 0, m, n, pivots, &tmp, _state);
    if( ae_fp_neq(mx,0) )
    {
        v = mx;
        for(i=0; i<=ae_minint(m, n, _state)-1; i++)
        {
            ae_v_muld(&a->ptr.pp_double[i][i], 1, ae_v_len(i,n-1), v);
        }
    }
    ae_frame_leave(_state);
}


void cmatrixplu(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector tmp;
    ae_int_t i;
    ae_int_t j;
    double mx;
    ae_complex v;

    ae_frame_make(_state, &_frame_block);
    ae_vector_clear(pivots);
    ae_vector_init(&tmp, 0, DT_COMPLEX, _state, ae_true);

    
    /*
     * Internal LU decomposition subroutine.
     * Never call it directly.
     */
    ae_assert(m>0, "CMatrixPLU: incorrect M!", _state);
    ae_assert(n>0, "CMatrixPLU: incorrect N!", _state);
    ae_vector_set_length(&tmp, 2*ae_maxint(m, n, _state), _state);
    ae_vector_set_length(pivots, ae_minint(m, n, _state), _state);
    
    /*
     * Scale matrix to avoid overflows,
     * decompose it, then scale back.
     */
    mx = 0;
    for(i=0; i<=m-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            mx = ae_maxreal(mx, ae_c_abs(a->ptr.pp_complex[i][j], _state), _state);
        }
    }
    if( ae_fp_neq(mx,0) )
    {
        v = ae_complex_from_d(1/mx);
        for(i=0; i<=m-1; i++)
        {
            ae_v_cmulc(&a->ptr.pp_complex[i][0], 1, ae_v_len(0,n-1), v);
        }
    }
    trfac_cmatrixplurec(a, 0, m, n, pivots, &tmp, _state);
    if( ae_fp_neq(mx,0) )
    {
        v = ae_complex_from_d(mx);
        for(i=0; i<=ae_minint(m, n, _state)-1; i++)
        {
            ae_v_cmulc(&a->ptr.pp_complex[i][i], 1, ae_v_len(i,n-1), v);
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Recursive computational subroutine for SPDMatrixCholesky.

INPUT PARAMETERS:
    A       -   matrix given by upper or lower triangle
    Offs    -   offset of diagonal block to decompose
    N       -   diagonal block size
    IsUpper -   what half is given
    Tmp     -   temporary array; allocated by function, if its size is too
                small; can be reused on subsequent calls.
                
OUTPUT PARAMETERS:
    A       -   upper (or lower) triangle contains Cholesky decomposition

RESULT:
    True, on success
    False, on failure

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
ae_bool spdmatrixcholeskyrec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t n1;
    ae_int_t n2;
    ae_bool result;


    
    /*
     * check N
     */
    if( n<1 )
    {
        result = ae_false;
        return result;
    }
    
    /*
     * Prepare buffer
     */
    if( tmp->cnt<2*n )
    {
        ae_vector_set_length(tmp, 2*n, _state);
    }
    
    /*
     * special cases
     */
    if( n==1 )
    {
        if( ae_fp_greater(a->ptr.pp_double[offs][offs],0) )
        {
            a->ptr.pp_double[offs][offs] = ae_sqrt(a->ptr.pp_double[offs][offs], _state);
            result = ae_true;
        }
        else
        {
            result = ae_false;
        }
        return result;
    }
    if( n<=ablasblocksize(a, _state) )
    {
        result = trfac_spdmatrixcholesky2(a, offs, n, isupper, tmp, _state);
        return result;
    }
    
    /*
     * general case: split task in cache-oblivious manner
     */
    result = ae_true;
    ablassplitlength(a, n, &n1, &n2, _state);
    result = spdmatrixcholeskyrec(a, offs, n1, isupper, tmp, _state);
    if( !result )
    {
        return result;
    }
    if( n2>0 )
    {
        if( isupper )
        {
            rmatrixlefttrsm(n1, n2, a, offs, offs, isupper, ae_false, 1, a, offs, offs+n1, _state);
            rmatrixsyrk(n2, n1, -1.0, a, offs, offs+n1, 1, 1.0, a, offs+n1, offs+n1, isupper, _state);
        }
        else
        {
            rmatrixrighttrsm(n2, n1, a, offs, offs, isupper, ae_false, 1, a, offs+n1, offs, _state);
            rmatrixsyrk(n2, n1, -1.0, a, offs+n1, offs, 0, 1.0, a, offs+n1, offs+n1, isupper, _state);
        }
        result = spdmatrixcholeskyrec(a, offs+n1, n2, isupper, tmp, _state);
        if( !result )
        {
            return result;
        }
    }
    return result;
}


/*************************************************************************
Recurrent complex LU subroutine.
Never call it directly.

  -- ALGLIB routine --
     04.01.2010
     Bochkanov Sergey
*************************************************************************/
static void trfac_cmatrixluprec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t m1;
    ae_int_t m2;


    
    /*
     * Kernel case
     */
    if( ae_minint(m, n, _state)<=ablascomplexblocksize(a, _state) )
    {
        trfac_cmatrixlup2(a, offs, m, n, pivots, tmp, _state);
        return;
    }
    
    /*
     * Preliminary step, make N>=M
     *
     *     ( A1 )
     * A = (    ), where A1 is square
     *     ( A2 )
     *
     * Factorize A1, update A2
     */
    if( m>n )
    {
        trfac_cmatrixluprec(a, offs, n, n, pivots, tmp, _state);
        for(i=0; i<=n-1; i++)
        {
            ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+n][offs+i], a->stride, "N", ae_v_len(0,m-n-1));
            ae_v_cmove(&a->ptr.pp_complex[offs+n][offs+i], a->stride, &a->ptr.pp_complex[offs+n][pivots->ptr.p_int[offs+i]], a->stride, "N", ae_v_len(offs+n,offs+m-1));
            ae_v_cmove(&a->ptr.pp_complex[offs+n][pivots->ptr.p_int[offs+i]], a->stride, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs+n,offs+m-1));
        }
        cmatrixrighttrsm(m-n, n, a, offs, offs, ae_true, ae_true, 0, a, offs+n, offs, _state);
        return;
    }
    
    /*
     * Non-kernel case
     */
    ablascomplexsplitlength(a, m, &m1, &m2, _state);
    trfac_cmatrixluprec(a, offs, m1, n, pivots, tmp, _state);
    if( m2>0 )
    {
        for(i=0; i<=m1-1; i++)
        {
            if( offs+i!=pivots->ptr.p_int[offs+i] )
            {
                ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+m1][offs+i], a->stride, "N", ae_v_len(0,m2-1));
                ae_v_cmove(&a->ptr.pp_complex[offs+m1][offs+i], a->stride, &a->ptr.pp_complex[offs+m1][pivots->ptr.p_int[offs+i]], a->stride, "N", ae_v_len(offs+m1,offs+m-1));
                ae_v_cmove(&a->ptr.pp_complex[offs+m1][pivots->ptr.p_int[offs+i]], a->stride, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs+m1,offs+m-1));
            }
        }
        cmatrixrighttrsm(m2, m1, a, offs, offs, ae_true, ae_true, 0, a, offs+m1, offs, _state);
        cmatrixgemm(m-m1, n-m1, m1, ae_complex_from_d(-1.0), a, offs+m1, offs, 0, a, offs, offs+m1, 0, ae_complex_from_d(1.0), a, offs+m1, offs+m1, _state);
        trfac_cmatrixluprec(a, offs+m1, m-m1, n-m1, pivots, tmp, _state);
        for(i=0; i<=m2-1; i++)
        {
            if( offs+m1+i!=pivots->ptr.p_int[offs+m1+i] )
            {
                ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs][offs+m1+i], a->stride, "N", ae_v_len(0,m1-1));
                ae_v_cmove(&a->ptr.pp_complex[offs][offs+m1+i], a->stride, &a->ptr.pp_complex[offs][pivots->ptr.p_int[offs+m1+i]], a->stride, "N", ae_v_len(offs,offs+m1-1));
                ae_v_cmove(&a->ptr.pp_complex[offs][pivots->ptr.p_int[offs+m1+i]], a->stride, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs,offs+m1-1));
            }
        }
    }
}


/*************************************************************************
Recurrent real LU subroutine.
Never call it directly.

  -- ALGLIB routine --
     04.01.2010
     Bochkanov Sergey
*************************************************************************/
static void trfac_rmatrixluprec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t m1;
    ae_int_t m2;


    
    /*
     * Kernel case
     */
    if( ae_minint(m, n, _state)<=ablasblocksize(a, _state) )
    {
        trfac_rmatrixlup2(a, offs, m, n, pivots, tmp, _state);
        return;
    }
    
    /*
     * Preliminary step, make N>=M
     *
     *     ( A1 )
     * A = (    ), where A1 is square
     *     ( A2 )
     *
     * Factorize A1, update A2
     */
    if( m>n )
    {
        trfac_rmatrixluprec(a, offs, n, n, pivots, tmp, _state);
        for(i=0; i<=n-1; i++)
        {
            if( offs+i!=pivots->ptr.p_int[offs+i] )
            {
                ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+n][offs+i], a->stride, ae_v_len(0,m-n-1));
                ae_v_move(&a->ptr.pp_double[offs+n][offs+i], a->stride, &a->ptr.pp_double[offs+n][pivots->ptr.p_int[offs+i]], a->stride, ae_v_len(offs+n,offs+m-1));
                ae_v_move(&a->ptr.pp_double[offs+n][pivots->ptr.p_int[offs+i]], a->stride, &tmp->ptr.p_double[0], 1, ae_v_len(offs+n,offs+m-1));
            }
        }
        rmatrixrighttrsm(m-n, n, a, offs, offs, ae_true, ae_true, 0, a, offs+n, offs, _state);
        return;
    }
    
    /*
     * Non-kernel case
     */
    ablassplitlength(a, m, &m1, &m2, _state);
    trfac_rmatrixluprec(a, offs, m1, n, pivots, tmp, _state);
    if( m2>0 )
    {
        for(i=0; i<=m1-1; i++)
        {
            if( offs+i!=pivots->ptr.p_int[offs+i] )
            {
                ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+m1][offs+i], a->stride, ae_v_len(0,m2-1));
                ae_v_move(&a->ptr.pp_double[offs+m1][offs+i], a->stride, &a->ptr.pp_double[offs+m1][pivots->ptr.p_int[offs+i]], a->stride, ae_v_len(offs+m1,offs+m-1));
                ae_v_move(&a->ptr.pp_double[offs+m1][pivots->ptr.p_int[offs+i]], a->stride, &tmp->ptr.p_double[0], 1, ae_v_len(offs+m1,offs+m-1));
            }
        }
        rmatrixrighttrsm(m2, m1, a, offs, offs, ae_true, ae_true, 0, a, offs+m1, offs, _state);
        rmatrixgemm(m-m1, n-m1, m1, -1.0, a, offs+m1, offs, 0, a, offs, offs+m1, 0, 1.0, a, offs+m1, offs+m1, _state);
        trfac_rmatrixluprec(a, offs+m1, m-m1, n-m1, pivots, tmp, _state);
        for(i=0; i<=m2-1; i++)
        {
            if( offs+m1+i!=pivots->ptr.p_int[offs+m1+i] )
            {
                ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs][offs+m1+i], a->stride, ae_v_len(0,m1-1));
                ae_v_move(&a->ptr.pp_double[offs][offs+m1+i], a->stride, &a->ptr.pp_double[offs][pivots->ptr.p_int[offs+m1+i]], a->stride, ae_v_len(offs,offs+m1-1));
                ae_v_move(&a->ptr.pp_double[offs][pivots->ptr.p_int[offs+m1+i]], a->stride, &tmp->ptr.p_double[0], 1, ae_v_len(offs,offs+m1-1));
            }
        }
    }
}


/*************************************************************************
Recurrent complex LU subroutine.
Never call it directly.

  -- ALGLIB routine --
     04.01.2010
     Bochkanov Sergey
*************************************************************************/
static void trfac_cmatrixplurec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t n1;
    ae_int_t n2;


    
    /*
     * Kernel case
     */
    if( ae_minint(m, n, _state)<=ablascomplexblocksize(a, _state) )
    {
        trfac_cmatrixplu2(a, offs, m, n, pivots, tmp, _state);
        return;
    }
    
    /*
     * Preliminary step, make M>=N.
     *
     * A = (A1 A2), where A1 is square
     * Factorize A1, update A2
     */
    if( n>m )
    {
        trfac_cmatrixplurec(a, offs, m, m, pivots, tmp, _state);
        for(i=0; i<=m-1; i++)
        {
            ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+i][offs+m], 1, "N", ae_v_len(0,n-m-1));
            ae_v_cmove(&a->ptr.pp_complex[offs+i][offs+m], 1, &a->ptr.pp_complex[pivots->ptr.p_int[offs+i]][offs+m], 1, "N", ae_v_len(offs+m,offs+n-1));
            ae_v_cmove(&a->ptr.pp_complex[pivots->ptr.p_int[offs+i]][offs+m], 1, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs+m,offs+n-1));
        }
        cmatrixlefttrsm(m, n-m, a, offs, offs, ae_false, ae_true, 0, a, offs, offs+m, _state);
        return;
    }
    
    /*
     * Non-kernel case
     */
    ablascomplexsplitlength(a, n, &n1, &n2, _state);
    trfac_cmatrixplurec(a, offs, m, n1, pivots, tmp, _state);
    if( n2>0 )
    {
        for(i=0; i<=n1-1; i++)
        {
            if( offs+i!=pivots->ptr.p_int[offs+i] )
            {
                ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+i][offs+n1], 1, "N", ae_v_len(0,n2-1));
                ae_v_cmove(&a->ptr.pp_complex[offs+i][offs+n1], 1, &a->ptr.pp_complex[pivots->ptr.p_int[offs+i]][offs+n1], 1, "N", ae_v_len(offs+n1,offs+n-1));
                ae_v_cmove(&a->ptr.pp_complex[pivots->ptr.p_int[offs+i]][offs+n1], 1, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs+n1,offs+n-1));
            }
        }
        cmatrixlefttrsm(n1, n2, a, offs, offs, ae_false, ae_true, 0, a, offs, offs+n1, _state);
        cmatrixgemm(m-n1, n-n1, n1, ae_complex_from_d(-1.0), a, offs+n1, offs, 0, a, offs, offs+n1, 0, ae_complex_from_d(1.0), a, offs+n1, offs+n1, _state);
        trfac_cmatrixplurec(a, offs+n1, m-n1, n-n1, pivots, tmp, _state);
        for(i=0; i<=n2-1; i++)
        {
            if( offs+n1+i!=pivots->ptr.p_int[offs+n1+i] )
            {
                ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+n1+i][offs], 1, "N", ae_v_len(0,n1-1));
                ae_v_cmove(&a->ptr.pp_complex[offs+n1+i][offs], 1, &a->ptr.pp_complex[pivots->ptr.p_int[offs+n1+i]][offs], 1, "N", ae_v_len(offs,offs+n1-1));
                ae_v_cmove(&a->ptr.pp_complex[pivots->ptr.p_int[offs+n1+i]][offs], 1, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs,offs+n1-1));
            }
        }
    }
}


/*************************************************************************
Recurrent real LU subroutine.
Never call it directly.

  -- ALGLIB routine --
     04.01.2010
     Bochkanov Sergey
*************************************************************************/
static void trfac_rmatrixplurec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t n1;
    ae_int_t n2;


    
    /*
     * Kernel case
     */
    if( ae_minint(m, n, _state)<=ablasblocksize(a, _state) )
    {
        trfac_rmatrixplu2(a, offs, m, n, pivots, tmp, _state);
        return;
    }
    
    /*
     * Preliminary step, make M>=N.
     *
     * A = (A1 A2), where A1 is square
     * Factorize A1, update A2
     */
    if( n>m )
    {
        trfac_rmatrixplurec(a, offs, m, m, pivots, tmp, _state);
        for(i=0; i<=m-1; i++)
        {
            ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+i][offs+m], 1, ae_v_len(0,n-m-1));
            ae_v_move(&a->ptr.pp_double[offs+i][offs+m], 1, &a->ptr.pp_double[pivots->ptr.p_int[offs+i]][offs+m], 1, ae_v_len(offs+m,offs+n-1));
            ae_v_move(&a->ptr.pp_double[pivots->ptr.p_int[offs+i]][offs+m], 1, &tmp->ptr.p_double[0], 1, ae_v_len(offs+m,offs+n-1));
        }
        rmatrixlefttrsm(m, n-m, a, offs, offs, ae_false, ae_true, 0, a, offs, offs+m, _state);
        return;
    }
    
    /*
     * Non-kernel case
     */
    ablassplitlength(a, n, &n1, &n2, _state);
    trfac_rmatrixplurec(a, offs, m, n1, pivots, tmp, _state);
    if( n2>0 )
    {
        for(i=0; i<=n1-1; i++)
        {
            if( offs+i!=pivots->ptr.p_int[offs+i] )
            {
                ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+i][offs+n1], 1, ae_v_len(0,n2-1));
                ae_v_move(&a->ptr.pp_double[offs+i][offs+n1], 1, &a->ptr.pp_double[pivots->ptr.p_int[offs+i]][offs+n1], 1, ae_v_len(offs+n1,offs+n-1));
                ae_v_move(&a->ptr.pp_double[pivots->ptr.p_int[offs+i]][offs+n1], 1, &tmp->ptr.p_double[0], 1, ae_v_len(offs+n1,offs+n-1));
            }
        }
        rmatrixlefttrsm(n1, n2, a, offs, offs, ae_false, ae_true, 0, a, offs, offs+n1, _state);
        rmatrixgemm(m-n1, n-n1, n1, -1.0, a, offs+n1, offs, 0, a, offs, offs+n1, 0, 1.0, a, offs+n1, offs+n1, _state);
        trfac_rmatrixplurec(a, offs+n1, m-n1, n-n1, pivots, tmp, _state);
        for(i=0; i<=n2-1; i++)
        {
            if( offs+n1+i!=pivots->ptr.p_int[offs+n1+i] )
            {
                ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+n1+i][offs], 1, ae_v_len(0,n1-1));
                ae_v_move(&a->ptr.pp_double[offs+n1+i][offs], 1, &a->ptr.pp_double[pivots->ptr.p_int[offs+n1+i]][offs], 1, ae_v_len(offs,offs+n1-1));
                ae_v_move(&a->ptr.pp_double[pivots->ptr.p_int[offs+n1+i]][offs], 1, &tmp->ptr.p_double[0], 1, ae_v_len(offs,offs+n1-1));
            }
        }
    }
}


/*************************************************************************
Complex LUP kernel

  -- ALGLIB routine --
     10.01.2010
     Bochkanov Sergey
*************************************************************************/
static void trfac_cmatrixlup2(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_int_t jp;
    ae_complex s;


    
    /*
     * Quick return if possible
     */
    if( m==0||n==0 )
    {
        return;
    }
    
    /*
     * main cycle
     */
    for(j=0; j<=ae_minint(m-1, n-1, _state); j++)
    {
        
        /*
         * Find pivot, swap columns
         */
        jp = j;
        for(i=j+1; i<=n-1; i++)
        {
            if( ae_fp_greater(ae_c_abs(a->ptr.pp_complex[offs+j][offs+i], _state),ae_c_abs(a->ptr.pp_complex[offs+j][offs+jp], _state)) )
            {
                jp = i;
            }
        }
        pivots->ptr.p_int[offs+j] = offs+jp;
        if( jp!=j )
        {
            ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs][offs+j], a->stride, "N", ae_v_len(0,m-1));
            ae_v_cmove(&a->ptr.pp_complex[offs][offs+j], a->stride, &a->ptr.pp_complex[offs][offs+jp], a->stride, "N", ae_v_len(offs,offs+m-1));
            ae_v_cmove(&a->ptr.pp_complex[offs][offs+jp], a->stride, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs,offs+m-1));
        }
        
        /*
         * LU decomposition of 1x(N-J) matrix
         */
        if( ae_c_neq_d(a->ptr.pp_complex[offs+j][offs+j],0)&&j+1<=n-1 )
        {
            s = ae_c_d_div(1,a->ptr.pp_complex[offs+j][offs+j]);
            ae_v_cmulc(&a->ptr.pp_complex[offs+j][offs+j+1], 1, ae_v_len(offs+j+1,offs+n-1), s);
        }
        
        /*
         * Update trailing (M-J-1)x(N-J-1) matrix
         */
        if( j<ae_minint(m-1, n-1, _state) )
        {
            ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+j+1][offs+j], a->stride, "N", ae_v_len(0,m-j-2));
            ae_v_cmoveneg(&tmp->ptr.p_complex[m], 1, &a->ptr.pp_complex[offs+j][offs+j+1], 1, "N", ae_v_len(m,m+n-j-2));
            cmatrixrank1(m-j-1, n-j-1, a, offs+j+1, offs+j+1, tmp, 0, tmp, m, _state);
        }
    }
}


/*************************************************************************
Real LUP kernel

  -- ALGLIB routine --
     10.01.2010
     Bochkanov Sergey
*************************************************************************/
static void trfac_rmatrixlup2(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_int_t jp;
    double s;


    
    /*
     * Quick return if possible
     */
    if( m==0||n==0 )
    {
        return;
    }
    
    /*
     * main cycle
     */
    for(j=0; j<=ae_minint(m-1, n-1, _state); j++)
    {
        
        /*
         * Find pivot, swap columns
         */
        jp = j;
        for(i=j+1; i<=n-1; i++)
        {
            if( ae_fp_greater(ae_fabs(a->ptr.pp_double[offs+j][offs+i], _state),ae_fabs(a->ptr.pp_double[offs+j][offs+jp], _state)) )
            {
                jp = i;
            }
        }
        pivots->ptr.p_int[offs+j] = offs+jp;
        if( jp!=j )
        {
            ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs][offs+j], a->stride, ae_v_len(0,m-1));
            ae_v_move(&a->ptr.pp_double[offs][offs+j], a->stride, &a->ptr.pp_double[offs][offs+jp], a->stride, ae_v_len(offs,offs+m-1));
            ae_v_move(&a->ptr.pp_double[offs][offs+jp], a->stride, &tmp->ptr.p_double[0], 1, ae_v_len(offs,offs+m-1));
        }
        
        /*
         * LU decomposition of 1x(N-J) matrix
         */
        if( ae_fp_neq(a->ptr.pp_double[offs+j][offs+j],0)&&j+1<=n-1 )
        {
            s = 1/a->ptr.pp_double[offs+j][offs+j];
            ae_v_muld(&a->ptr.pp_double[offs+j][offs+j+1], 1, ae_v_len(offs+j+1,offs+n-1), s);
        }
        
        /*
         * Update trailing (M-J-1)x(N-J-1) matrix
         */
        if( j<ae_minint(m-1, n-1, _state) )
        {
            ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+j+1][offs+j], a->stride, ae_v_len(0,m-j-2));
            ae_v_moveneg(&tmp->ptr.p_double[m], 1, &a->ptr.pp_double[offs+j][offs+j+1], 1, ae_v_len(m,m+n-j-2));
            rmatrixrank1(m-j-1, n-j-1, a, offs+j+1, offs+j+1, tmp, 0, tmp, m, _state);
        }
    }
}


/*************************************************************************
Complex PLU kernel

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     June 30, 1992
*************************************************************************/
static void trfac_cmatrixplu2(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Complex */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_int_t jp;
    ae_complex s;


    
    /*
     * Quick return if possible
     */
    if( m==0||n==0 )
    {
        return;
    }
    for(j=0; j<=ae_minint(m-1, n-1, _state); j++)
    {
        
        /*
         * Find pivot and test for singularity.
         */
        jp = j;
        for(i=j+1; i<=m-1; i++)
        {
            if( ae_fp_greater(ae_c_abs(a->ptr.pp_complex[offs+i][offs+j], _state),ae_c_abs(a->ptr.pp_complex[offs+jp][offs+j], _state)) )
            {
                jp = i;
            }
        }
        pivots->ptr.p_int[offs+j] = offs+jp;
        if( ae_c_neq_d(a->ptr.pp_complex[offs+jp][offs+j],0) )
        {
            
            /*
             *Apply the interchange to rows
             */
            if( jp!=j )
            {
                for(i=0; i<=n-1; i++)
                {
                    s = a->ptr.pp_complex[offs+j][offs+i];
                    a->ptr.pp_complex[offs+j][offs+i] = a->ptr.pp_complex[offs+jp][offs+i];
                    a->ptr.pp_complex[offs+jp][offs+i] = s;
                }
            }
            
            /*
             *Compute elements J+1:M of J-th column.
             */
            if( j+1<=m-1 )
            {
                s = ae_c_d_div(1,a->ptr.pp_complex[offs+j][offs+j]);
                ae_v_cmulc(&a->ptr.pp_complex[offs+j+1][offs+j], a->stride, ae_v_len(offs+j+1,offs+m-1), s);
            }
        }
        if( j<ae_minint(m, n, _state)-1 )
        {
            
            /*
             *Update trailing submatrix.
             */
            ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+j+1][offs+j], a->stride, "N", ae_v_len(0,m-j-2));
            ae_v_cmoveneg(&tmp->ptr.p_complex[m], 1, &a->ptr.pp_complex[offs+j][offs+j+1], 1, "N", ae_v_len(m,m+n-j-2));
            cmatrixrank1(m-j-1, n-j-1, a, offs+j+1, offs+j+1, tmp, 0, tmp, m, _state);
        }
    }
}


/*************************************************************************
Real PLU kernel

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     June 30, 1992
*************************************************************************/
static void trfac_rmatrixplu2(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_int_t jp;
    double s;


    
    /*
     * Quick return if possible
     */
    if( m==0||n==0 )
    {
        return;
    }
    for(j=0; j<=ae_minint(m-1, n-1, _state); j++)
    {
        
        /*
         * Find pivot and test for singularity.
         */
        jp = j;
        for(i=j+1; i<=m-1; i++)
        {
            if( ae_fp_greater(ae_fabs(a->ptr.pp_double[offs+i][offs+j], _state),ae_fabs(a->ptr.pp_double[offs+jp][offs+j], _state)) )
            {
                jp = i;
            }
        }
        pivots->ptr.p_int[offs+j] = offs+jp;
        if( ae_fp_neq(a->ptr.pp_double[offs+jp][offs+j],0) )
        {
            
            /*
             *Apply the interchange to rows
             */
            if( jp!=j )
            {
                for(i=0; i<=n-1; i++)
                {
                    s = a->ptr.pp_double[offs+j][offs+i];
                    a->ptr.pp_double[offs+j][offs+i] = a->ptr.pp_double[offs+jp][offs+i];
                    a->ptr.pp_double[offs+jp][offs+i] = s;
                }
            }
            
            /*
             *Compute elements J+1:M of J-th column.
             */
            if( j+1<=m-1 )
            {
                s = 1/a->ptr.pp_double[offs+j][offs+j];
                ae_v_muld(&a->ptr.pp_double[offs+j+1][offs+j], a->stride, ae_v_len(offs+j+1,offs+m-1), s);
            }
        }
        if( j<ae_minint(m, n, _state)-1 )
        {
            
            /*
             *Update trailing submatrix.
             */
            ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+j+1][offs+j], a->stride, ae_v_len(0,m-j-2));
            ae_v_moveneg(&tmp->ptr.p_double[m], 1, &a->ptr.pp_double[offs+j][offs+j+1], 1, ae_v_len(m,m+n-j-2));
            rmatrixrank1(m-j-1, n-j-1, a, offs+j+1, offs+j+1, tmp, 0, tmp, m, _state);
        }
    }
}


/*************************************************************************
Recursive computational subroutine for HPDMatrixCholesky

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
static ae_bool trfac_hpdmatrixcholeskyrec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t n1;
    ae_int_t n2;
    ae_bool result;


    
    /*
     * check N
     */
    if( n<1 )
    {
        result = ae_false;
        return result;
    }
    
    /*
     * Prepare buffer
     */
    if( tmp->cnt<2*n )
    {
        ae_vector_set_length(tmp, 2*n, _state);
    }
    
    /*
     * special cases
     */
    if( n==1 )
    {
        if( ae_fp_greater(a->ptr.pp_complex[offs][offs].x,0) )
        {
            a->ptr.pp_complex[offs][offs] = ae_complex_from_d(ae_sqrt(a->ptr.pp_complex[offs][offs].x, _state));
            result = ae_true;
        }
        else
        {
            result = ae_false;
        }
        return result;
    }
    if( n<=ablascomplexblocksize(a, _state) )
    {
        result = trfac_hpdmatrixcholesky2(a, offs, n, isupper, tmp, _state);
        return result;
    }
    
    /*
     * general case: split task in cache-oblivious manner
     */
    result = ae_true;
    ablascomplexsplitlength(a, n, &n1, &n2, _state);
    result = trfac_hpdmatrixcholeskyrec(a, offs, n1, isupper, tmp, _state);
    if( !result )
    {
        return result;
    }
    if( n2>0 )
    {
        if( isupper )
        {
            cmatrixlefttrsm(n1, n2, a, offs, offs, isupper, ae_false, 2, a, offs, offs+n1, _state);
            cmatrixsyrk(n2, n1, -1.0, a, offs, offs+n1, 2, 1.0, a, offs+n1, offs+n1, isupper, _state);
        }
        else
        {
            cmatrixrighttrsm(n2, n1, a, offs, offs, isupper, ae_false, 2, a, offs+n1, offs, _state);
            cmatrixsyrk(n2, n1, -1.0, a, offs+n1, offs, 0, 1.0, a, offs+n1, offs+n1, isupper, _state);
        }
        result = trfac_hpdmatrixcholeskyrec(a, offs+n1, n2, isupper, tmp, _state);
        if( !result )
        {
            return result;
        }
    }
    return result;
}


/*************************************************************************
Level-2 Hermitian Cholesky subroutine.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992
*************************************************************************/
static ae_bool trfac_hpdmatrixcholesky2(/* Complex */ ae_matrix* aaa,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double ajj;
    ae_complex v;
    double r;
    ae_bool result;


    result = ae_true;
    if( n<0 )
    {
        result = ae_false;
        return result;
    }
    
    /*
     * Quick return if possible
     */
    if( n==0 )
    {
        return result;
    }
    if( isupper )
    {
        
        /*
         * Compute the Cholesky factorization A = U'*U.
         */
        for(j=0; j<=n-1; j++)
        {
            
            /*
             * Compute U(J,J) and test for non-positive-definiteness.
             */
            v = ae_v_cdotproduct(&aaa->ptr.pp_complex[offs][offs+j], aaa->stride, "Conj", &aaa->ptr.pp_complex[offs][offs+j], aaa->stride, "N", ae_v_len(offs,offs+j-1));
            ajj = ae_c_sub(aaa->ptr.pp_complex[offs+j][offs+j],v).x;
            if( ae_fp_less_eq(ajj,0) )
            {
                aaa->ptr.pp_complex[offs+j][offs+j] = ae_complex_from_d(ajj);
                result = ae_false;
                return result;
            }
            ajj = ae_sqrt(ajj, _state);
            aaa->ptr.pp_complex[offs+j][offs+j] = ae_complex_from_d(ajj);
            
            /*
             * Compute elements J+1:N-1 of row J.
             */
            if( j<n-1 )
            {
                if( j>0 )
                {
                    ae_v_cmoveneg(&tmp->ptr.p_complex[0], 1, &aaa->ptr.pp_complex[offs][offs+j], aaa->stride, "Conj", ae_v_len(0,j-1));
                    cmatrixmv(n-j-1, j, aaa, offs, offs+j+1, 1, tmp, 0, tmp, n, _state);
                    ae_v_cadd(&aaa->ptr.pp_complex[offs+j][offs+j+1], 1, &tmp->ptr.p_complex[n], 1, "N", ae_v_len(offs+j+1,offs+n-1));
                }
                r = 1/ajj;
                ae_v_cmuld(&aaa->ptr.pp_complex[offs+j][offs+j+1], 1, ae_v_len(offs+j+1,offs+n-1), r);
            }
        }
    }
    else
    {
        
        /*
         * Compute the Cholesky factorization A = L*L'.
         */
        for(j=0; j<=n-1; j++)
        {
            
            /*
             * Compute L(J+1,J+1) and test for non-positive-definiteness.
             */
            v = ae_v_cdotproduct(&aaa->ptr.pp_complex[offs+j][offs], 1, "Conj", &aaa->ptr.pp_complex[offs+j][offs], 1, "N", ae_v_len(offs,offs+j-1));
            ajj = ae_c_sub(aaa->ptr.pp_complex[offs+j][offs+j],v).x;
            if( ae_fp_less_eq(ajj,0) )
            {
                aaa->ptr.pp_complex[offs+j][offs+j] = ae_complex_from_d(ajj);
                result = ae_false;
                return result;
            }
            ajj = ae_sqrt(ajj, _state);
            aaa->ptr.pp_complex[offs+j][offs+j] = ae_complex_from_d(ajj);
            
            /*
             * Compute elements J+1:N of column J.
             */
            if( j<n-1 )
            {
                if( j>0 )
                {
                    ae_v_cmove(&tmp->ptr.p_complex[0], 1, &aaa->ptr.pp_complex[offs+j][offs], 1, "Conj", ae_v_len(0,j-1));
                    cmatrixmv(n-j-1, j, aaa, offs+j+1, offs, 0, tmp, 0, tmp, n, _state);
                    for(i=0; i<=n-j-2; i++)
                    {
                        aaa->ptr.pp_complex[offs+j+1+i][offs+j] = ae_c_div_d(ae_c_sub(aaa->ptr.pp_complex[offs+j+1+i][offs+j],tmp->ptr.p_complex[n+i]),ajj);
                    }
                }
                else
                {
                    for(i=0; i<=n-j-2; i++)
                    {
                        aaa->ptr.pp_complex[offs+j+1+i][offs+j] = ae_c_div_d(aaa->ptr.pp_complex[offs+j+1+i][offs+j],ajj);
                    }
                }
            }
        }
    }
    return result;
}


/*************************************************************************
Level-2 Cholesky subroutine

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992
*************************************************************************/
static ae_bool trfac_spdmatrixcholesky2(/* Real    */ ae_matrix* aaa,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double ajj;
    double v;
    double r;
    ae_bool result;


    result = ae_true;
    if( n<0 )
    {
        result = ae_false;
        return result;
    }
    
    /*
     * Quick return if possible
     */
    if( n==0 )
    {
        return result;
    }
    if( isupper )
    {
        
        /*
         * Compute the Cholesky factorization A = U'*U.
         */
        for(j=0; j<=n-1; j++)
        {
            
            /*
             * Compute U(J,J) and test for non-positive-definiteness.
             */
            v = ae_v_dotproduct(&aaa->ptr.pp_double[offs][offs+j], aaa->stride, &aaa->ptr.pp_double[offs][offs+j], aaa->stride, ae_v_len(offs,offs+j-1));
            ajj = aaa->ptr.pp_double[offs+j][offs+j]-v;
            if( ae_fp_less_eq(ajj,0) )
            {
                aaa->ptr.pp_double[offs+j][offs+j] = ajj;
                result = ae_false;
                return result;
            }
            ajj = ae_sqrt(ajj, _state);
            aaa->ptr.pp_double[offs+j][offs+j] = ajj;
            
            /*
             * Compute elements J+1:N-1 of row J.
             */
            if( j<n-1 )
            {
                if( j>0 )
                {
                    ae_v_moveneg(&tmp->ptr.p_double[0], 1, &aaa->ptr.pp_double[offs][offs+j], aaa->stride, ae_v_len(0,j-1));
                    rmatrixmv(n-j-1, j, aaa, offs, offs+j+1, 1, tmp, 0, tmp, n, _state);
                    ae_v_add(&aaa->ptr.pp_double[offs+j][offs+j+1], 1, &tmp->ptr.p_double[n], 1, ae_v_len(offs+j+1,offs+n-1));
                }
                r = 1/ajj;
                ae_v_muld(&aaa->ptr.pp_double[offs+j][offs+j+1], 1, ae_v_len(offs+j+1,offs+n-1), r);
            }
        }
    }
    else
    {
        
        /*
         * Compute the Cholesky factorization A = L*L'.
         */
        for(j=0; j<=n-1; j++)
        {
            
            /*
             * Compute L(J+1,J+1) and test for non-positive-definiteness.
             */
            v = ae_v_dotproduct(&aaa->ptr.pp_double[offs+j][offs], 1, &aaa->ptr.pp_double[offs+j][offs], 1, ae_v_len(offs,offs+j-1));
            ajj = aaa->ptr.pp_double[offs+j][offs+j]-v;
            if( ae_fp_less_eq(ajj,0) )
            {
                aaa->ptr.pp_double[offs+j][offs+j] = ajj;
                result = ae_false;
                return result;
            }
            ajj = ae_sqrt(ajj, _state);
            aaa->ptr.pp_double[offs+j][offs+j] = ajj;
            
            /*
             * Compute elements J+1:N of column J.
             */
            if( j<n-1 )
            {
                if( j>0 )
                {
                    ae_v_move(&tmp->ptr.p_double[0], 1, &aaa->ptr.pp_double[offs+j][offs], 1, ae_v_len(0,j-1));
                    rmatrixmv(n-j-1, j, aaa, offs+j+1, offs, 0, tmp, 0, tmp, n, _state);
                    for(i=0; i<=n-j-2; i++)
                    {
                        aaa->ptr.pp_double[offs+j+1+i][offs+j] = (aaa->ptr.pp_double[offs+j+1+i][offs+j]-tmp->ptr.p_double[n+i])/ajj;
                    }
                }
                else
                {
                    for(i=0; i<=n-j-2; i++)
                    {
                        aaa->ptr.pp_double[offs+j+1+i][offs+j] = aaa->ptr.pp_double[offs+j+1+i][offs+j]/ajj;
                    }
                }
            }
        }
    }
    return result;
}




/*************************************************************************
Estimate of a matrix condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixrcond1(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    ae_vector t;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);

    ae_assert(n>=1, "RMatrixRCond1: N<1!", _state);
    ae_vector_set_length(&t, n, _state);
    for(i=0; i<=n-1; i++)
    {
        t.ptr.p_double[i] = 0;
    }
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            t.ptr.p_double[j] = t.ptr.p_double[j]+ae_fabs(a->ptr.pp_double[i][j], _state);
        }
    }
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        nrm = ae_maxreal(nrm, t.ptr.p_double[i], _state);
    }
    rmatrixlu(a, n, n, &pivots, _state);
    rcond_rmatrixrcondluinternal(a, n, ae_true, ae_true, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixrcondinf(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>=1, "RMatrixRCondInf: N<1!", _state);
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        v = 0;
        for(j=0; j<=n-1; j++)
        {
            v = v+ae_fabs(a->ptr.pp_double[i][j], _state);
        }
        nrm = ae_maxreal(nrm, v, _state);
    }
    rmatrixlu(a, n, n, &pivots, _state);
    rcond_rmatrixrcondluinternal(a, n, ae_false, ae_true, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Condition number estimate of a symmetric positive definite matrix.

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm of condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    A       -   symmetric positive definite matrix which is given by its
                upper or lower triangle depending on the value of
                IsUpper. Array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format.

Result:
    1/LowerBound(cond(A)), if matrix A is positive definite,
   -1, if matrix A is not positive definite, and its condition number
    could not be found by this algorithm.

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double spdmatrixrcond(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_int_t i;
    ae_int_t j;
    ae_int_t j1;
    ae_int_t j2;
    double v;
    double nrm;
    ae_vector t;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);

    ae_vector_set_length(&t, n, _state);
    for(i=0; i<=n-1; i++)
    {
        t.ptr.p_double[i] = 0;
    }
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i;
        }
        for(j=j1; j<=j2; j++)
        {
            if( i==j )
            {
                t.ptr.p_double[i] = t.ptr.p_double[i]+ae_fabs(a->ptr.pp_double[i][i], _state);
            }
            else
            {
                t.ptr.p_double[i] = t.ptr.p_double[i]+ae_fabs(a->ptr.pp_double[i][j], _state);
                t.ptr.p_double[j] = t.ptr.p_double[j]+ae_fabs(a->ptr.pp_double[i][j], _state);
            }
        }
    }
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        nrm = ae_maxreal(nrm, t.ptr.p_double[i], _state);
    }
    if( spdmatrixcholesky(a, n, isupper, _state) )
    {
        rcond_spdmatrixrcondcholeskyinternal(a, n, isupper, ae_true, nrm, &v, _state);
        result = v;
    }
    else
    {
        result = -1;
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Triangular matrix: estimate of a condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A       -   matrix. Array[0..N-1, 0..N-1].
    N       -   size of A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixtrrcond1(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    ae_vector t;
    ae_int_t j1;
    ae_int_t j2;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);

    ae_assert(n>=1, "RMatrixTRRCond1: N<1!", _state);
    ae_vector_set_length(&t, n, _state);
    for(i=0; i<=n-1; i++)
    {
        t.ptr.p_double[i] = 0;
    }
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i+1;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i-1;
        }
        for(j=j1; j<=j2; j++)
        {
            t.ptr.p_double[j] = t.ptr.p_double[j]+ae_fabs(a->ptr.pp_double[i][j], _state);
        }
        if( isunit )
        {
            t.ptr.p_double[i] = t.ptr.p_double[i]+1;
        }
        else
        {
            t.ptr.p_double[i] = t.ptr.p_double[i]+ae_fabs(a->ptr.pp_double[i][i], _state);
        }
    }
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        nrm = ae_maxreal(nrm, t.ptr.p_double[i], _state);
    }
    rcond_rmatrixrcondtrinternal(a, n, isupper, isunit, ae_true, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Triangular matrix: estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixtrrcondinf(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    ae_int_t j1;
    ae_int_t j2;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>=1, "RMatrixTRRCondInf: N<1!", _state);
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i+1;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i-1;
        }
        v = 0;
        for(j=j1; j<=j2; j++)
        {
            v = v+ae_fabs(a->ptr.pp_double[i][j], _state);
        }
        if( isunit )
        {
            v = v+1;
        }
        else
        {
            v = v+ae_fabs(a->ptr.pp_double[i][i], _state);
        }
        nrm = ae_maxreal(nrm, v, _state);
    }
    rcond_rmatrixrcondtrinternal(a, n, isupper, isunit, ae_false, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Condition number estimate of a Hermitian positive definite matrix.

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm of condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    A       -   Hermitian positive definite matrix which is given by its
                upper or lower triangle depending on the value of
                IsUpper. Array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   storage format.

Result:
    1/LowerBound(cond(A)), if matrix A is positive definite,
   -1, if matrix A is not positive definite, and its condition number
    could not be found by this algorithm.

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double hpdmatrixrcond(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_int_t i;
    ae_int_t j;
    ae_int_t j1;
    ae_int_t j2;
    double v;
    double nrm;
    ae_vector t;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);

    ae_vector_set_length(&t, n, _state);
    for(i=0; i<=n-1; i++)
    {
        t.ptr.p_double[i] = 0;
    }
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i;
        }
        for(j=j1; j<=j2; j++)
        {
            if( i==j )
            {
                t.ptr.p_double[i] = t.ptr.p_double[i]+ae_c_abs(a->ptr.pp_complex[i][i], _state);
            }
            else
            {
                t.ptr.p_double[i] = t.ptr.p_double[i]+ae_c_abs(a->ptr.pp_complex[i][j], _state);
                t.ptr.p_double[j] = t.ptr.p_double[j]+ae_c_abs(a->ptr.pp_complex[i][j], _state);
            }
        }
    }
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        nrm = ae_maxreal(nrm, t.ptr.p_double[i], _state);
    }
    if( hpdmatrixcholesky(a, n, isupper, _state) )
    {
        rcond_hpdmatrixrcondcholeskyinternal(a, n, isupper, ae_true, nrm, &v, _state);
        result = v;
    }
    else
    {
        result = -1;
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Estimate of a matrix condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixrcond1(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    ae_vector t;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);

    ae_assert(n>=1, "CMatrixRCond1: N<1!", _state);
    ae_vector_set_length(&t, n, _state);
    for(i=0; i<=n-1; i++)
    {
        t.ptr.p_double[i] = 0;
    }
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            t.ptr.p_double[j] = t.ptr.p_double[j]+ae_c_abs(a->ptr.pp_complex[i][j], _state);
        }
    }
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        nrm = ae_maxreal(nrm, t.ptr.p_double[i], _state);
    }
    cmatrixlu(a, n, n, &pivots, _state);
    rcond_cmatrixrcondluinternal(a, n, ae_true, ae_true, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixrcondinf(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>=1, "CMatrixRCondInf: N<1!", _state);
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        v = 0;
        for(j=0; j<=n-1; j++)
        {
            v = v+ae_c_abs(a->ptr.pp_complex[i][j], _state);
        }
        nrm = ae_maxreal(nrm, v, _state);
    }
    cmatrixlu(a, n, n, &pivots, _state);
    rcond_cmatrixrcondluinternal(a, n, ae_false, ae_true, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA         -   LU decomposition of a matrix in compact form. Output of
                    the RMatrixLU subroutine.
    N           -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixlurcond1(/* Real    */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state)
{
    double v;
    double result;


    rcond_rmatrixrcondluinternal(lua, n, ae_true, ae_false, 0, &v, _state);
    result = v;
    return result;
}


/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition
(infinity norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA     -   LU decomposition of a matrix in compact form. Output of
                the RMatrixLU subroutine.
    N       -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double rmatrixlurcondinf(/* Real    */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state)
{
    double v;
    double result;


    rcond_rmatrixrcondluinternal(lua, n, ae_false, ae_false, 0, &v, _state);
    result = v;
    return result;
}


/*************************************************************************
Condition number estimate of a symmetric positive definite matrix given by
Cholesky decomposition.

The algorithm calculates a lower bound of the condition number. In this
case, the algorithm does not return a lower bound of the condition number,
but an inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    CD  - Cholesky decomposition of matrix A,
          output of SMatrixCholesky subroutine.
    N   - size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double spdmatrixcholeskyrcond(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state)
{
    double v;
    double result;


    rcond_spdmatrixrcondcholeskyinternal(a, n, isupper, ae_false, 0, &v, _state);
    result = v;
    return result;
}


/*************************************************************************
Condition number estimate of a Hermitian positive definite matrix given by
Cholesky decomposition.

The algorithm calculates a lower bound of the condition number. In this
case, the algorithm does not return a lower bound of the condition number,
but an inverse number (to avoid an overflow in case of a singular matrix).

It should be noted that 1-norm and inf-norm condition numbers of symmetric
matrices are equal, so the algorithm doesn't take into account the
differences between these types of norms.

Input parameters:
    CD  - Cholesky decomposition of matrix A,
          output of SMatrixCholesky subroutine.
    N   - size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double hpdmatrixcholeskyrcond(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state)
{
    double v;
    double result;


    rcond_hpdmatrixrcondcholeskyinternal(a, n, isupper, ae_false, 0, &v, _state);
    result = v;
    return result;
}


/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA         -   LU decomposition of a matrix in compact form. Output of
                    the CMatrixLU subroutine.
    N           -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixlurcond1(/* Complex */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state)
{
    double v;
    double result;


    ae_assert(n>=1, "CMatrixLURCond1: N<1!", _state);
    rcond_cmatrixrcondluinternal(lua, n, ae_true, ae_false, 0.0, &v, _state);
    result = v;
    return result;
}


/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition
(infinity norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUA     -   LU decomposition of a matrix in compact form. Output of
                the CMatrixLU subroutine.
    N       -   size of matrix A.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixlurcondinf(/* Complex */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state)
{
    double v;
    double result;


    ae_assert(n>=1, "CMatrixLURCondInf: N<1!", _state);
    rcond_cmatrixrcondluinternal(lua, n, ae_false, ae_false, 0.0, &v, _state);
    result = v;
    return result;
}


/*************************************************************************
Triangular matrix: estimate of a condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A       -   matrix. Array[0..N-1, 0..N-1].
    N       -   size of A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixtrrcond1(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    ae_vector t;
    ae_int_t j1;
    ae_int_t j2;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);
    ae_vector_init(&t, 0, DT_REAL, _state, ae_true);

    ae_assert(n>=1, "RMatrixTRRCond1: N<1!", _state);
    ae_vector_set_length(&t, n, _state);
    for(i=0; i<=n-1; i++)
    {
        t.ptr.p_double[i] = 0;
    }
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i+1;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i-1;
        }
        for(j=j1; j<=j2; j++)
        {
            t.ptr.p_double[j] = t.ptr.p_double[j]+ae_c_abs(a->ptr.pp_complex[i][j], _state);
        }
        if( isunit )
        {
            t.ptr.p_double[i] = t.ptr.p_double[i]+1;
        }
        else
        {
            t.ptr.p_double[i] = t.ptr.p_double[i]+ae_c_abs(a->ptr.pp_complex[i][i], _state);
        }
    }
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        nrm = ae_maxreal(nrm, t.ptr.p_double[i], _state);
    }
    rcond_cmatrixrcondtrinternal(a, n, isupper, isunit, ae_true, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Triangular matrix: estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   True, if the matrix has a unit diagonal.

Result: 1/LowerBound(cond(A))

NOTE:
    if k(A) is very large, then matrix is  assumed  degenerate,  k(A)=INF,
    0.0 is returned in such cases.
*************************************************************************/
double cmatrixtrrcondinf(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    double v;
    double nrm;
    ae_vector pivots;
    ae_int_t j1;
    ae_int_t j2;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>=1, "RMatrixTRRCondInf: N<1!", _state);
    nrm = 0;
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i+1;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i-1;
        }
        v = 0;
        for(j=j1; j<=j2; j++)
        {
            v = v+ae_c_abs(a->ptr.pp_complex[i][j], _state);
        }
        if( isunit )
        {
            v = v+1;
        }
        else
        {
            v = v+ae_c_abs(a->ptr.pp_complex[i][i], _state);
        }
        nrm = ae_maxreal(nrm, v, _state);
    }
    rcond_cmatrixrcondtrinternal(a, n, isupper, isunit, ae_false, nrm, &v, _state);
    result = v;
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Threshold for rcond: matrices with condition number beyond this  threshold
are considered singular.

Threshold must be far enough from underflow, at least Sqr(Threshold)  must
be greater than underflow.
*************************************************************************/
double rcondthreshold(ae_state *_state)
{
    double result;


    result = ae_sqrt(ae_sqrt(ae_minrealnumber, _state), _state);
    return result;
}


/*************************************************************************
Internal subroutine for condition number estimation

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992
*************************************************************************/
static void rcond_rmatrixrcondtrinternal(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_bool onenorm,
     double anorm,
     double* rc,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector ex;
    ae_vector ev;
    ae_vector iwork;
    ae_vector tmp;
    ae_int_t i;
    ae_int_t j;
    ae_int_t kase;
    ae_int_t kase1;
    ae_int_t j1;
    ae_int_t j2;
    double ainvnm;
    double maxgrowth;
    double s;
    ae_bool mupper;
    ae_bool mtrans;
    ae_bool munit;

    ae_frame_make(_state, &_frame_block);
    *rc = 0;
    ae_vector_init(&ex, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ev, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&iwork, 0, DT_INT, _state, ae_true);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);

    
    /*
     * RC=0 if something happens
     */
    *rc = 0;
    
    /*
     * init
     */
    if( onenorm )
    {
        kase1 = 1;
    }
    else
    {
        kase1 = 2;
    }
    mupper = ae_true;
    mtrans = ae_true;
    munit = ae_true;
    ae_vector_set_length(&iwork, n+1, _state);
    ae_vector_set_length(&tmp, n, _state);
    
    /*
     * prepare parameters for triangular solver
     */
    maxgrowth = 1/rcondthreshold(_state);
    s = 0;
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i+1;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i-1;
        }
        for(j=j1; j<=j2; j++)
        {
            s = ae_maxreal(s, ae_fabs(a->ptr.pp_double[i][j], _state), _state);
        }
        if( isunit )
        {
            s = ae_maxreal(s, 1, _state);
        }
        else
        {
            s = ae_maxreal(s, ae_fabs(a->ptr.pp_double[i][i], _state), _state);
        }
    }
    if( ae_fp_eq(s,0) )
    {
        s = 1;
    }
    s = 1/s;
    
    /*
     * Scale according to S
     */
    anorm = anorm*s;
    
    /*
     * Quick return if possible
     * We assume that ANORM<>0 after this block
     */
    if( ae_fp_eq(anorm,0) )
    {
        ae_frame_leave(_state);
        return;
    }
    if( n==1 )
    {
        *rc = 1;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Estimate the norm of inv(A).
     */
    ainvnm = 0;
    kase = 0;
    for(;;)
    {
        rcond_rmatrixestimatenorm(n, &ev, &ex, &iwork, &ainvnm, &kase, _state);
        if( kase==0 )
        {
            break;
        }
        
        /*
         * from 1-based array to 0-based
         */
        for(i=0; i<=n-1; i++)
        {
            ex.ptr.p_double[i] = ex.ptr.p_double[i+1];
        }
        
        /*
         * multiply by inv(A) or inv(A')
         */
        if( kase==kase1 )
        {
            
            /*
             * multiply by inv(A)
             */
            if( !rmatrixscaledtrsafesolve(a, s, n, &ex, isupper, 0, isunit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        else
        {
            
            /*
             * multiply by inv(A')
             */
            if( !rmatrixscaledtrsafesolve(a, s, n, &ex, isupper, 1, isunit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        
        /*
         * from 0-based array to 1-based
         */
        for(i=n-1; i>=0; i--)
        {
            ex.ptr.p_double[i+1] = ex.ptr.p_double[i];
        }
    }
    
    /*
     * Compute the estimate of the reciprocal condition number.
     */
    if( ae_fp_neq(ainvnm,0) )
    {
        *rc = 1/ainvnm;
        *rc = *rc/anorm;
        if( ae_fp_less(*rc,rcondthreshold(_state)) )
        {
            *rc = 0;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Condition number estimation

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     March 31, 1993
*************************************************************************/
static void rcond_cmatrixrcondtrinternal(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_bool onenorm,
     double anorm,
     double* rc,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector ex;
    ae_vector cwork2;
    ae_vector cwork3;
    ae_vector cwork4;
    ae_vector isave;
    ae_vector rsave;
    ae_int_t kase;
    ae_int_t kase1;
    double ainvnm;
    ae_int_t i;
    ae_int_t j;
    ae_int_t j1;
    ae_int_t j2;
    double s;
    double maxgrowth;

    ae_frame_make(_state, &_frame_block);
    *rc = 0;
    ae_vector_init(&ex, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&cwork2, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&cwork3, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&cwork4, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&isave, 0, DT_INT, _state, ae_true);
    ae_vector_init(&rsave, 0, DT_REAL, _state, ae_true);

    
    /*
     * RC=0 if something happens
     */
    *rc = 0;
    
    /*
     * init
     */
    if( n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    if( n==0 )
    {
        *rc = 1;
        ae_frame_leave(_state);
        return;
    }
    ae_vector_set_length(&cwork2, n+1, _state);
    
    /*
     * prepare parameters for triangular solver
     */
    maxgrowth = 1/rcondthreshold(_state);
    s = 0;
    for(i=0; i<=n-1; i++)
    {
        if( isupper )
        {
            j1 = i+1;
            j2 = n-1;
        }
        else
        {
            j1 = 0;
            j2 = i-1;
        }
        for(j=j1; j<=j2; j++)
        {
            s = ae_maxreal(s, ae_c_abs(a->ptr.pp_complex[i][j], _state), _state);
        }
        if( isunit )
        {
            s = ae_maxreal(s, 1, _state);
        }
        else
        {
            s = ae_maxreal(s, ae_c_abs(a->ptr.pp_complex[i][i], _state), _state);
        }
    }
    if( ae_fp_eq(s,0) )
    {
        s = 1;
    }
    s = 1/s;
    
    /*
     * Scale according to S
     */
    anorm = anorm*s;
    
    /*
     * Quick return if possible
     */
    if( ae_fp_eq(anorm,0) )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Estimate the norm of inv(A).
     */
    ainvnm = 0;
    if( onenorm )
    {
        kase1 = 1;
    }
    else
    {
        kase1 = 2;
    }
    kase = 0;
    for(;;)
    {
        rcond_cmatrixestimatenorm(n, &cwork4, &ex, &ainvnm, &kase, &isave, &rsave, _state);
        if( kase==0 )
        {
            break;
        }
        
        /*
         * From 1-based to 0-based
         */
        for(i=0; i<=n-1; i++)
        {
            ex.ptr.p_complex[i] = ex.ptr.p_complex[i+1];
        }
        
        /*
         * multiply by inv(A) or inv(A')
         */
        if( kase==kase1 )
        {
            
            /*
             * multiply by inv(A)
             */
            if( !cmatrixscaledtrsafesolve(a, s, n, &ex, isupper, 0, isunit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        else
        {
            
            /*
             * multiply by inv(A')
             */
            if( !cmatrixscaledtrsafesolve(a, s, n, &ex, isupper, 2, isunit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        
        /*
         * from 0-based to 1-based
         */
        for(i=n-1; i>=0; i--)
        {
            ex.ptr.p_complex[i+1] = ex.ptr.p_complex[i];
        }
    }
    
    /*
     * Compute the estimate of the reciprocal condition number.
     */
    if( ae_fp_neq(ainvnm,0) )
    {
        *rc = 1/ainvnm;
        *rc = *rc/anorm;
        if( ae_fp_less(*rc,rcondthreshold(_state)) )
        {
            *rc = 0;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Internal subroutine for condition number estimation

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992
*************************************************************************/
static void rcond_spdmatrixrcondcholeskyinternal(/* Real    */ ae_matrix* cha,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isnormprovided,
     double anorm,
     double* rc,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_int_t kase;
    double ainvnm;
    ae_vector ex;
    ae_vector ev;
    ae_vector tmp;
    ae_vector iwork;
    double sa;
    double v;
    double maxgrowth;

    ae_frame_make(_state, &_frame_block);
    *rc = 0;
    ae_vector_init(&ex, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ev, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&iwork, 0, DT_INT, _state, ae_true);

    ae_assert(n>=1, "Assertion failed", _state);
    ae_vector_set_length(&tmp, n, _state);
    
    /*
     * RC=0 if something happens
     */
    *rc = 0;
    
    /*
     * prepare parameters for triangular solver
     */
    maxgrowth = 1/rcondthreshold(_state);
    sa = 0;
    if( isupper )
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=i; j<=n-1; j++)
            {
                sa = ae_maxreal(sa, ae_c_abs(ae_complex_from_d(cha->ptr.pp_double[i][j]), _state), _state);
            }
        }
    }
    else
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=0; j<=i; j++)
            {
                sa = ae_maxreal(sa, ae_c_abs(ae_complex_from_d(cha->ptr.pp_double[i][j]), _state), _state);
            }
        }
    }
    if( ae_fp_eq(sa,0) )
    {
        sa = 1;
    }
    sa = 1/sa;
    
    /*
     * Estimate the norm of A.
     */
    if( !isnormprovided )
    {
        kase = 0;
        anorm = 0;
        for(;;)
        {
            rcond_rmatrixestimatenorm(n, &ev, &ex, &iwork, &anorm, &kase, _state);
            if( kase==0 )
            {
                break;
            }
            if( isupper )
            {
                
                /*
                 * Multiply by U
                 */
                for(i=1; i<=n; i++)
                {
                    v = ae_v_dotproduct(&cha->ptr.pp_double[i-1][i-1], 1, &ex.ptr.p_double[i], 1, ae_v_len(i-1,n-1));
                    ex.ptr.p_double[i] = v;
                }
                ae_v_muld(&ex.ptr.p_double[1], 1, ae_v_len(1,n), sa);
                
                /*
                 * Multiply by U'
                 */
                for(i=0; i<=n-1; i++)
                {
                    tmp.ptr.p_double[i] = 0;
                }
                for(i=0; i<=n-1; i++)
                {
                    v = ex.ptr.p_double[i+1];
                    ae_v_addd(&tmp.ptr.p_double[i], 1, &cha->ptr.pp_double[i][i], 1, ae_v_len(i,n-1), v);
                }
                ae_v_move(&ex.ptr.p_double[1], 1, &tmp.ptr.p_double[0], 1, ae_v_len(1,n));
                ae_v_muld(&ex.ptr.p_double[1], 1, ae_v_len(1,n), sa);
            }
            else
            {
                
                /*
                 * Multiply by L'
                 */
                for(i=0; i<=n-1; i++)
                {
                    tmp.ptr.p_double[i] = 0;
                }
                for(i=0; i<=n-1; i++)
                {
                    v = ex.ptr.p_double[i+1];
                    ae_v_addd(&tmp.ptr.p_double[0], 1, &cha->ptr.pp_double[i][0], 1, ae_v_len(0,i), v);
                }
                ae_v_move(&ex.ptr.p_double[1], 1, &tmp.ptr.p_double[0], 1, ae_v_len(1,n));
                ae_v_muld(&ex.ptr.p_double[1], 1, ae_v_len(1,n), sa);
                
                /*
                 * Multiply by L
                 */
                for(i=n; i>=1; i--)
                {
                    v = ae_v_dotproduct(&cha->ptr.pp_double[i-1][0], 1, &ex.ptr.p_double[1], 1, ae_v_len(0,i-1));
                    ex.ptr.p_double[i] = v;
                }
                ae_v_muld(&ex.ptr.p_double[1], 1, ae_v_len(1,n), sa);
            }
        }
    }
    
    /*
     * Quick return if possible
     */
    if( ae_fp_eq(anorm,0) )
    {
        ae_frame_leave(_state);
        return;
    }
    if( n==1 )
    {
        *rc = 1;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Estimate the 1-norm of inv(A).
     */
    kase = 0;
    for(;;)
    {
        rcond_rmatrixestimatenorm(n, &ev, &ex, &iwork, &ainvnm, &kase, _state);
        if( kase==0 )
        {
            break;
        }
        for(i=0; i<=n-1; i++)
        {
            ex.ptr.p_double[i] = ex.ptr.p_double[i+1];
        }
        if( isupper )
        {
            
            /*
             * Multiply by inv(U').
             */
            if( !rmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 1, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(U).
             */
            if( !rmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 0, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        else
        {
            
            /*
             * Multiply by inv(L).
             */
            if( !rmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 0, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(L').
             */
            if( !rmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 1, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        for(i=n-1; i>=0; i--)
        {
            ex.ptr.p_double[i+1] = ex.ptr.p_double[i];
        }
    }
    
    /*
     * Compute the estimate of the reciprocal condition number.
     */
    if( ae_fp_neq(ainvnm,0) )
    {
        v = 1/ainvnm;
        *rc = v/anorm;
        if( ae_fp_less(*rc,rcondthreshold(_state)) )
        {
            *rc = 0;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Internal subroutine for condition number estimation

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992
*************************************************************************/
static void rcond_hpdmatrixrcondcholeskyinternal(/* Complex */ ae_matrix* cha,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isnormprovided,
     double anorm,
     double* rc,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector isave;
    ae_vector rsave;
    ae_vector ex;
    ae_vector ev;
    ae_vector tmp;
    ae_int_t kase;
    double ainvnm;
    ae_complex v;
    ae_int_t i;
    ae_int_t j;
    double sa;
    double maxgrowth;

    ae_frame_make(_state, &_frame_block);
    *rc = 0;
    ae_vector_init(&isave, 0, DT_INT, _state, ae_true);
    ae_vector_init(&rsave, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ex, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&ev, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&tmp, 0, DT_COMPLEX, _state, ae_true);

    ae_assert(n>=1, "Assertion failed", _state);
    ae_vector_set_length(&tmp, n, _state);
    
    /*
     * RC=0 if something happens
     */
    *rc = 0;
    
    /*
     * prepare parameters for triangular solver
     */
    maxgrowth = 1/rcondthreshold(_state);
    sa = 0;
    if( isupper )
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=i; j<=n-1; j++)
            {
                sa = ae_maxreal(sa, ae_c_abs(cha->ptr.pp_complex[i][j], _state), _state);
            }
        }
    }
    else
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=0; j<=i; j++)
            {
                sa = ae_maxreal(sa, ae_c_abs(cha->ptr.pp_complex[i][j], _state), _state);
            }
        }
    }
    if( ae_fp_eq(sa,0) )
    {
        sa = 1;
    }
    sa = 1/sa;
    
    /*
     * Estimate the norm of A
     */
    if( !isnormprovided )
    {
        anorm = 0;
        kase = 0;
        for(;;)
        {
            rcond_cmatrixestimatenorm(n, &ev, &ex, &anorm, &kase, &isave, &rsave, _state);
            if( kase==0 )
            {
                break;
            }
            if( isupper )
            {
                
                /*
                 * Multiply by U
                 */
                for(i=1; i<=n; i++)
                {
                    v = ae_v_cdotproduct(&cha->ptr.pp_complex[i-1][i-1], 1, "N", &ex.ptr.p_complex[i], 1, "N", ae_v_len(i-1,n-1));
                    ex.ptr.p_complex[i] = v;
                }
                ae_v_cmuld(&ex.ptr.p_complex[1], 1, ae_v_len(1,n), sa);
                
                /*
                 * Multiply by U'
                 */
                for(i=0; i<=n-1; i++)
                {
                    tmp.ptr.p_complex[i] = ae_complex_from_d(0);
                }
                for(i=0; i<=n-1; i++)
                {
                    v = ex.ptr.p_complex[i+1];
                    ae_v_caddc(&tmp.ptr.p_complex[i], 1, &cha->ptr.pp_complex[i][i], 1, "Conj", ae_v_len(i,n-1), v);
                }
                ae_v_cmove(&ex.ptr.p_complex[1], 1, &tmp.ptr.p_complex[0], 1, "N", ae_v_len(1,n));
                ae_v_cmuld(&ex.ptr.p_complex[1], 1, ae_v_len(1,n), sa);
            }
            else
            {
                
                /*
                 * Multiply by L'
                 */
                for(i=0; i<=n-1; i++)
                {
                    tmp.ptr.p_complex[i] = ae_complex_from_d(0);
                }
                for(i=0; i<=n-1; i++)
                {
                    v = ex.ptr.p_complex[i+1];
                    ae_v_caddc(&tmp.ptr.p_complex[0], 1, &cha->ptr.pp_complex[i][0], 1, "Conj", ae_v_len(0,i), v);
                }
                ae_v_cmove(&ex.ptr.p_complex[1], 1, &tmp.ptr.p_complex[0], 1, "N", ae_v_len(1,n));
                ae_v_cmuld(&ex.ptr.p_complex[1], 1, ae_v_len(1,n), sa);
                
                /*
                 * Multiply by L
                 */
                for(i=n; i>=1; i--)
                {
                    v = ae_v_cdotproduct(&cha->ptr.pp_complex[i-1][0], 1, "N", &ex.ptr.p_complex[1], 1, "N", ae_v_len(0,i-1));
                    ex.ptr.p_complex[i] = v;
                }
                ae_v_cmuld(&ex.ptr.p_complex[1], 1, ae_v_len(1,n), sa);
            }
        }
    }
    
    /*
     * Quick return if possible
     * After this block we assume that ANORM<>0
     */
    if( ae_fp_eq(anorm,0) )
    {
        ae_frame_leave(_state);
        return;
    }
    if( n==1 )
    {
        *rc = 1;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Estimate the norm of inv(A).
     */
    ainvnm = 0;
    kase = 0;
    for(;;)
    {
        rcond_cmatrixestimatenorm(n, &ev, &ex, &ainvnm, &kase, &isave, &rsave, _state);
        if( kase==0 )
        {
            break;
        }
        for(i=0; i<=n-1; i++)
        {
            ex.ptr.p_complex[i] = ex.ptr.p_complex[i+1];
        }
        if( isupper )
        {
            
            /*
             * Multiply by inv(U').
             */
            if( !cmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 2, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(U).
             */
            if( !cmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 0, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        else
        {
            
            /*
             * Multiply by inv(L).
             */
            if( !cmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 0, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(L').
             */
            if( !cmatrixscaledtrsafesolve(cha, sa, n, &ex, isupper, 2, ae_false, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        for(i=n-1; i>=0; i--)
        {
            ex.ptr.p_complex[i+1] = ex.ptr.p_complex[i];
        }
    }
    
    /*
     * Compute the estimate of the reciprocal condition number.
     */
    if( ae_fp_neq(ainvnm,0) )
    {
        *rc = 1/ainvnm;
        *rc = *rc/anorm;
        if( ae_fp_less(*rc,rcondthreshold(_state)) )
        {
            *rc = 0;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Internal subroutine for condition number estimation

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992
*************************************************************************/
static void rcond_rmatrixrcondluinternal(/* Real    */ ae_matrix* lua,
     ae_int_t n,
     ae_bool onenorm,
     ae_bool isanormprovided,
     double anorm,
     double* rc,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector ex;
    ae_vector ev;
    ae_vector iwork;
    ae_vector tmp;
    double v;
    ae_int_t i;
    ae_int_t j;
    ae_int_t kase;
    ae_int_t kase1;
    double ainvnm;
    double maxgrowth;
    double su;
    double sl;
    ae_bool mupper;
    ae_bool mtrans;
    ae_bool munit;

    ae_frame_make(_state, &_frame_block);
    *rc = 0;
    ae_vector_init(&ex, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ev, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&iwork, 0, DT_INT, _state, ae_true);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);

    
    /*
     * RC=0 if something happens
     */
    *rc = 0;
    
    /*
     * init
     */
    if( onenorm )
    {
        kase1 = 1;
    }
    else
    {
        kase1 = 2;
    }
    mupper = ae_true;
    mtrans = ae_true;
    munit = ae_true;
    ae_vector_set_length(&iwork, n+1, _state);
    ae_vector_set_length(&tmp, n, _state);
    
    /*
     * prepare parameters for triangular solver
     */
    maxgrowth = 1/rcondthreshold(_state);
    su = 0;
    sl = 1;
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=i-1; j++)
        {
            sl = ae_maxreal(sl, ae_fabs(lua->ptr.pp_double[i][j], _state), _state);
        }
        for(j=i; j<=n-1; j++)
        {
            su = ae_maxreal(su, ae_fabs(lua->ptr.pp_double[i][j], _state), _state);
        }
    }
    if( ae_fp_eq(su,0) )
    {
        su = 1;
    }
    su = 1/su;
    sl = 1/sl;
    
    /*
     * Estimate the norm of A.
     */
    if( !isanormprovided )
    {
        kase = 0;
        anorm = 0;
        for(;;)
        {
            rcond_rmatrixestimatenorm(n, &ev, &ex, &iwork, &anorm, &kase, _state);
            if( kase==0 )
            {
                break;
            }
            if( kase==kase1 )
            {
                
                /*
                 * Multiply by U
                 */
                for(i=1; i<=n; i++)
                {
                    v = ae_v_dotproduct(&lua->ptr.pp_double[i-1][i-1], 1, &ex.ptr.p_double[i], 1, ae_v_len(i-1,n-1));
                    ex.ptr.p_double[i] = v;
                }
                
                /*
                 * Multiply by L
                 */
                for(i=n; i>=1; i--)
                {
                    if( i>1 )
                    {
                        v = ae_v_dotproduct(&lua->ptr.pp_double[i-1][0], 1, &ex.ptr.p_double[1], 1, ae_v_len(0,i-2));
                    }
                    else
                    {
                        v = 0;
                    }
                    ex.ptr.p_double[i] = ex.ptr.p_double[i]+v;
                }
            }
            else
            {
                
                /*
                 * Multiply by L'
                 */
                for(i=0; i<=n-1; i++)
                {
                    tmp.ptr.p_double[i] = 0;
                }
                for(i=0; i<=n-1; i++)
                {
                    v = ex.ptr.p_double[i+1];
                    if( i>=1 )
                    {
                        ae_v_addd(&tmp.ptr.p_double[0], 1, &lua->ptr.pp_double[i][0], 1, ae_v_len(0,i-1), v);
                    }
                    tmp.ptr.p_double[i] = tmp.ptr.p_double[i]+v;
                }
                ae_v_move(&ex.ptr.p_double[1], 1, &tmp.ptr.p_double[0], 1, ae_v_len(1,n));
                
                /*
                 * Multiply by U'
                 */
                for(i=0; i<=n-1; i++)
                {
                    tmp.ptr.p_double[i] = 0;
                }
                for(i=0; i<=n-1; i++)
                {
                    v = ex.ptr.p_double[i+1];
                    ae_v_addd(&tmp.ptr.p_double[i], 1, &lua->ptr.pp_double[i][i], 1, ae_v_len(i,n-1), v);
                }
                ae_v_move(&ex.ptr.p_double[1], 1, &tmp.ptr.p_double[0], 1, ae_v_len(1,n));
            }
        }
    }
    
    /*
     * Scale according to SU/SL
     */
    anorm = anorm*su*sl;
    
    /*
     * Quick return if possible
     * We assume that ANORM<>0 after this block
     */
    if( ae_fp_eq(anorm,0) )
    {
        ae_frame_leave(_state);
        return;
    }
    if( n==1 )
    {
        *rc = 1;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Estimate the norm of inv(A).
     */
    ainvnm = 0;
    kase = 0;
    for(;;)
    {
        rcond_rmatrixestimatenorm(n, &ev, &ex, &iwork, &ainvnm, &kase, _state);
        if( kase==0 )
        {
            break;
        }
        
        /*
         * from 1-based array to 0-based
         */
        for(i=0; i<=n-1; i++)
        {
            ex.ptr.p_double[i] = ex.ptr.p_double[i+1];
        }
        
        /*
         * multiply by inv(A) or inv(A')
         */
        if( kase==kase1 )
        {
            
            /*
             * Multiply by inv(L).
             */
            if( !rmatrixscaledtrsafesolve(lua, sl, n, &ex, !mupper, 0, munit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(U).
             */
            if( !rmatrixscaledtrsafesolve(lua, su, n, &ex, mupper, 0, !munit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        else
        {
            
            /*
             * Multiply by inv(U').
             */
            if( !rmatrixscaledtrsafesolve(lua, su, n, &ex, mupper, 1, !munit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(L').
             */
            if( !rmatrixscaledtrsafesolve(lua, sl, n, &ex, !mupper, 1, munit, maxgrowth, _state) )
            {
                ae_frame_leave(_state);
                return;
            }
        }
        
        /*
         * from 0-based array to 1-based
         */
        for(i=n-1; i>=0; i--)
        {
            ex.ptr.p_double[i+1] = ex.ptr.p_double[i];
        }
    }
    
    /*
     * Compute the estimate of the reciprocal condition number.
     */
    if( ae_fp_neq(ainvnm,0) )
    {
        *rc = 1/ainvnm;
        *rc = *rc/anorm;
        if( ae_fp_less(*rc,rcondthreshold(_state)) )
        {
            *rc = 0;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Condition number estimation

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     March 31, 1993
*************************************************************************/
static void rcond_cmatrixrcondluinternal(/* Complex */ ae_matrix* lua,
     ae_int_t n,
     ae_bool onenorm,
     ae_bool isanormprovided,
     double anorm,
     double* rc,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector ex;
    ae_vector cwork2;
    ae_vector cwork3;
    ae_vector cwork4;
    ae_vector isave;
    ae_vector rsave;
    ae_int_t kase;
    ae_int_t kase1;
    double ainvnm;
    ae_complex v;
    ae_int_t i;
    ae_int_t j;
    double su;
    double sl;
    double maxgrowth;

    ae_frame_make(_state, &_frame_block);
    *rc = 0;
    ae_vector_init(&ex, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&cwork2, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&cwork3, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&cwork4, 0, DT_COMPLEX, _state, ae_true);
    ae_vector_init(&isave, 0, DT_INT, _state, ae_true);
    ae_vector_init(&rsave, 0, DT_REAL, _state, ae_true);

    if( n<=0 )
    {
        ae_frame_leave(_state);
        return;
    }
    ae_vector_set_length(&cwork2, n+1, _state);
    *rc = 0;
    if( n==0 )
    {
        *rc = 1;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * prepare parameters for triangular solver
     */
    maxgrowth = 1/rcondthreshold(_state);
    su = 0;
    sl = 1;
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=i-1; j++)
        {
            sl = ae_maxreal(sl, ae_c_abs(lua->ptr.pp_complex[i][j], _state), _state);
        }
        for(j=i; j<=n-1; j++)
        {
            su = ae_maxreal(su, ae_c_abs(lua->ptr.pp_complex[i][j], _state), _state);
        }
    }
    if( ae_fp_eq(su,0) )
    {
        su = 1;
    }
    su = 1/su;
    sl = 1/sl;
    
    /*
     * Estimate the norm of SU*SL*A.
     */
    if( !isanormprovided )
    {
        anorm = 0;
        if( onenorm )
        {
            kase1 = 1;
        }
        else
        {
            kase1 = 2;
        }
        kase = 0;
        do
        {
            rcond_cmatrixestimatenorm(n, &cwork4, &ex, &anorm, &kase, &isave, &rsave, _state);
            if( kase!=0 )
            {
                if( kase==kase1 )
                {
                    
                    /*
                     * Multiply by U
                     */
                    for(i=1; i<=n; i++)
                    {
                        v = ae_v_cdotproduct(&lua->ptr.pp_complex[i-1][i-1], 1, "N", &ex.ptr.p_complex[i], 1, "N", ae_v_len(i-1,n-1));
                        ex.ptr.p_complex[i] = v;
                    }
                    
                    /*
                     * Multiply by L
                     */
                    for(i=n; i>=1; i--)
                    {
                        v = ae_complex_from_d(0);
                        if( i>1 )
                        {
                            v = ae_v_cdotproduct(&lua->ptr.pp_complex[i-1][0], 1, "N", &ex.ptr.p_complex[1], 1, "N", ae_v_len(0,i-2));
                        }
                        ex.ptr.p_complex[i] = ae_c_add(v,ex.ptr.p_complex[i]);
                    }
                }
                else
                {
                    
                    /*
                     * Multiply by L'
                     */
                    for(i=1; i<=n; i++)
                    {
                        cwork2.ptr.p_complex[i] = ae_complex_from_d(0);
                    }
                    for(i=1; i<=n; i++)
                    {
                        v = ex.ptr.p_complex[i];
                        if( i>1 )
                        {
                            ae_v_caddc(&cwork2.ptr.p_complex[1], 1, &lua->ptr.pp_complex[i-1][0], 1, "Conj", ae_v_len(1,i-1), v);
                        }
                        cwork2.ptr.p_complex[i] = ae_c_add(cwork2.ptr.p_complex[i],v);
                    }
                    
                    /*
                     * Multiply by U'
                     */
                    for(i=1; i<=n; i++)
                    {
                        ex.ptr.p_complex[i] = ae_complex_from_d(0);
                    }
                    for(i=1; i<=n; i++)
                    {
                        v = cwork2.ptr.p_complex[i];
                        ae_v_caddc(&ex.ptr.p_complex[i], 1, &lua->ptr.pp_complex[i-1][i-1], 1, "Conj", ae_v_len(i,n), v);
                    }
                }
            }
        }
        while(kase!=0);
    }
    
    /*
     * Scale according to SU/SL
     */
    anorm = anorm*su*sl;
    
    /*
     * Quick return if possible
     */
    if( ae_fp_eq(anorm,0) )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Estimate the norm of inv(A).
     */
    ainvnm = 0;
    if( onenorm )
    {
        kase1 = 1;
    }
    else
    {
        kase1 = 2;
    }
    kase = 0;
    for(;;)
    {
        rcond_cmatrixestimatenorm(n, &cwork4, &ex, &ainvnm, &kase, &isave, &rsave, _state);
        if( kase==0 )
        {
            break;
        }
        
        /*
         * From 1-based to 0-based
         */
        for(i=0; i<=n-1; i++)
        {
            ex.ptr.p_complex[i] = ex.ptr.p_complex[i+1];
        }
        
        /*
         * multiply by inv(A) or inv(A')
         */
        if( kase==kase1 )
        {
            
            /*
             * Multiply by inv(L).
             */
            if( !cmatrixscaledtrsafesolve(lua, sl, n, &ex, ae_false, 0, ae_true, maxgrowth, _state) )
            {
                *rc = 0;
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(U).
             */
            if( !cmatrixscaledtrsafesolve(lua, su, n, &ex, ae_true, 0, ae_false, maxgrowth, _state) )
            {
                *rc = 0;
                ae_frame_leave(_state);
                return;
            }
        }
        else
        {
            
            /*
             * Multiply by inv(U').
             */
            if( !cmatrixscaledtrsafesolve(lua, su, n, &ex, ae_true, 2, ae_false, maxgrowth, _state) )
            {
                *rc = 0;
                ae_frame_leave(_state);
                return;
            }
            
            /*
             * Multiply by inv(L').
             */
            if( !cmatrixscaledtrsafesolve(lua, sl, n, &ex, ae_false, 2, ae_true, maxgrowth, _state) )
            {
                *rc = 0;
                ae_frame_leave(_state);
                return;
            }
        }
        
        /*
         * from 0-based to 1-based
         */
        for(i=n-1; i>=0; i--)
        {
            ex.ptr.p_complex[i+1] = ex.ptr.p_complex[i];
        }
    }
    
    /*
     * Compute the estimate of the reciprocal condition number.
     */
    if( ae_fp_neq(ainvnm,0) )
    {
        *rc = 1/ainvnm;
        *rc = *rc/anorm;
        if( ae_fp_less(*rc,rcondthreshold(_state)) )
        {
            *rc = 0;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Internal subroutine for matrix norm estimation

  -- LAPACK auxiliary routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992
*************************************************************************/
static void rcond_rmatrixestimatenorm(ae_int_t n,
     /* Real    */ ae_vector* v,
     /* Real    */ ae_vector* x,
     /* Integer */ ae_vector* isgn,
     double* est,
     ae_int_t* kase,
     ae_state *_state)
{
    ae_int_t itmax;
    ae_int_t i;
    double t;
    ae_bool flg;
    ae_int_t positer;
    ae_int_t posj;
    ae_int_t posjlast;
    ae_int_t posjump;
    ae_int_t posaltsgn;
    ae_int_t posestold;
    ae_int_t postemp;


    itmax = 5;
    posaltsgn = n+1;
    posestold = n+2;
    postemp = n+3;
    positer = n+1;
    posj = n+2;
    posjlast = n+3;
    posjump = n+4;
    if( *kase==0 )
    {
        ae_vector_set_length(v, n+4, _state);
        ae_vector_set_length(x, n+1, _state);
        ae_vector_set_length(isgn, n+5, _state);
        t = (double)1/(double)n;
        for(i=1; i<=n; i++)
        {
            x->ptr.p_double[i] = t;
        }
        *kase = 1;
        isgn->ptr.p_int[posjump] = 1;
        return;
    }
    
    /*
     *     ................ ENTRY   (JUMP = 1)
     *     FIRST ITERATION.  X HAS BEEN OVERWRITTEN BY A*X.
     */
    if( isgn->ptr.p_int[posjump]==1 )
    {
        if( n==1 )
        {
            v->ptr.p_double[1] = x->ptr.p_double[1];
            *est = ae_fabs(v->ptr.p_double[1], _state);
            *kase = 0;
            return;
        }
        *est = 0;
        for(i=1; i<=n; i++)
        {
            *est = *est+ae_fabs(x->ptr.p_double[i], _state);
        }
        for(i=1; i<=n; i++)
        {
            if( ae_fp_greater_eq(x->ptr.p_double[i],0) )
            {
                x->ptr.p_double[i] = 1;
            }
            else
            {
                x->ptr.p_double[i] = -1;
            }
            isgn->ptr.p_int[i] = ae_sign(x->ptr.p_double[i], _state);
        }
        *kase = 2;
        isgn->ptr.p_int[posjump] = 2;
        return;
    }
    
    /*
     *     ................ ENTRY   (JUMP = 2)
     *     FIRST ITERATION.  X HAS BEEN OVERWRITTEN BY TRANDPOSE(A)*X.
     */
    if( isgn->ptr.p_int[posjump]==2 )
    {
        isgn->ptr.p_int[posj] = 1;
        for(i=2; i<=n; i++)
        {
            if( ae_fp_greater(ae_fabs(x->ptr.p_double[i], _state),ae_fabs(x->ptr.p_double[isgn->ptr.p_int[posj]], _state)) )
            {
                isgn->ptr.p_int[posj] = i;
            }
        }
        isgn->ptr.p_int[positer] = 2;
        
        /*
         * MAIN LOOP - ITERATIONS 2,3,...,ITMAX.
         */
        for(i=1; i<=n; i++)
        {
            x->ptr.p_double[i] = 0;
        }
        x->ptr.p_double[isgn->ptr.p_int[posj]] = 1;
        *kase = 1;
        isgn->ptr.p_int[posjump] = 3;
        return;
    }
    
    /*
     *     ................ ENTRY   (JUMP = 3)
     *     X HAS BEEN OVERWRITTEN BY A*X.
     */
    if( isgn->ptr.p_int[posjump]==3 )
    {
        ae_v_move(&v->ptr.p_double[1], 1, &x->ptr.p_double[1], 1, ae_v_len(1,n));
        v->ptr.p_double[posestold] = *est;
        *est = 0;
        for(i=1; i<=n; i++)
        {
            *est = *est+ae_fabs(v->ptr.p_double[i], _state);
        }
        flg = ae_false;
        for(i=1; i<=n; i++)
        {
            if( (ae_fp_greater_eq(x->ptr.p_double[i],0)&&isgn->ptr.p_int[i]<0)||(ae_fp_less(x->ptr.p_double[i],0)&&isgn->ptr.p_int[i]>=0) )
            {
                flg = ae_true;
            }
        }
        
        /*
         * REPEATED SIGN VECTOR DETECTED, HENCE ALGORITHM HAS CONVERGED.
         * OR MAY BE CYCLING.
         */
        if( !flg||ae_fp_less_eq(*est,v->ptr.p_double[posestold]) )
        {
            v->ptr.p_double[posaltsgn] = 1;
            for(i=1; i<=n; i++)
            {
                x->ptr.p_double[i] = v->ptr.p_double[posaltsgn]*(1+(double)(i-1)/(double)(n-1));
                v->ptr.p_double[posaltsgn] = -v->ptr.p_double[posaltsgn];
            }
            *kase = 1;
            isgn->ptr.p_int[posjump] = 5;
            return;
        }
        for(i=1; i<=n; i++)
        {
            if( ae_fp_greater_eq(x->ptr.p_double[i],0) )
            {
                x->ptr.p_double[i] = 1;
                isgn->ptr.p_int[i] = 1;
            }
            else
            {
                x->ptr.p_double[i] = -1;
                isgn->ptr.p_int[i] = -1;
            }
        }
        *kase = 2;
        isgn->ptr.p_int[posjump] = 4;
        return;
    }
    
    /*
     *     ................ ENTRY   (JUMP = 4)
     *     X HAS BEEN OVERWRITTEN BY TRANDPOSE(A)*X.
     */
    if( isgn->ptr.p_int[posjump]==4 )
    {
        isgn->ptr.p_int[posjlast] = isgn->ptr.p_int[posj];
        isgn->ptr.p_int[posj] = 1;
        for(i=2; i<=n; i++)
        {
            if( ae_fp_greater(ae_fabs(x->ptr.p_double[i], _state),ae_fabs(x->ptr.p_double[isgn->ptr.p_int[posj]], _state)) )
            {
                isgn->ptr.p_int[posj] = i;
            }
        }
        if( ae_fp_neq(x->ptr.p_double[isgn->ptr.p_int[posjlast]],ae_fabs(x->ptr.p_double[isgn->ptr.p_int[posj]], _state))&&isgn->ptr.p_int[positer]<itmax )
        {
            isgn->ptr.p_int[positer] = isgn->ptr.p_int[positer]+1;
            for(i=1; i<=n; i++)
            {
                x->ptr.p_double[i] = 0;
            }
            x->ptr.p_double[isgn->ptr.p_int[posj]] = 1;
            *kase = 1;
            isgn->ptr.p_int[posjump] = 3;
            return;
        }
        
        /*
         * ITERATION COMPLETE.  FINAL STAGE.
         */
        v->ptr.p_double[posaltsgn] = 1;
        for(i=1; i<=n; i++)
        {
            x->ptr.p_double[i] = v->ptr.p_double[posaltsgn]*(1+(double)(i-1)/(double)(n-1));
            v->ptr.p_double[posaltsgn] = -v->ptr.p_double[posaltsgn];
        }
        *kase = 1;
        isgn->ptr.p_int[posjump] = 5;
        return;
    }
    
    /*
     *     ................ ENTRY   (JUMP = 5)
     *     X HAS BEEN OVERWRITTEN BY A*X.
     */
    if( isgn->ptr.p_int[posjump]==5 )
    {
        v->ptr.p_double[postemp] = 0;
        for(i=1; i<=n; i++)
        {
            v->ptr.p_double[postemp] = v->ptr.p_double[postemp]+ae_fabs(x->ptr.p_double[i], _state);
        }
        v->ptr.p_double[postemp] = 2*v->ptr.p_double[postemp]/(3*n);
        if( ae_fp_greater(v->ptr.p_double[postemp],*est) )
        {
            ae_v_move(&v->ptr.p_double[1], 1, &x->ptr.p_double[1], 1, ae_v_len(1,n));
            *est = v->ptr.p_double[postemp];
        }
        *kase = 0;
        return;
    }
}


static void rcond_cmatrixestimatenorm(ae_int_t n,
     /* Complex */ ae_vector* v,
     /* Complex */ ae_vector* x,
     double* est,
     ae_int_t* kase,
     /* Integer */ ae_vector* isave,
     /* Real    */ ae_vector* rsave,
     ae_state *_state)
{
    ae_int_t itmax{0};
    ae_int_t i{0};
    ae_int_t iter{0};
    ae_int_t j{0};
    ae_int_t jlast{0};
    ae_int_t jump{0};
    double absxi{0.0};
    double altsgn{0.0};
    double estold{0.0};
    double safmin{0.0};
    double temp{0.0};


    
    /*
     *Executable Statements ..
     */
    itmax = 5;
    safmin = ae_minrealnumber;
    if( *kase==0 )
    {
        ae_vector_set_length(v, n+1, _state);
        ae_vector_set_length(x, n+1, _state);
        ae_vector_set_length(isave, 5, _state);
        ae_vector_set_length(rsave, 4, _state);
        for(i=1; i<=n; i++)
        {
            x->ptr.p_complex[i] = ae_complex_from_d((double)1/(double)n);
        }
        *kase = 1;
        jump = 1;
        rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
        return;
    }
    rcond_internalcomplexrcondloadall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
    
    /*
     * ENTRY   (JUMP = 1)
     * FIRST ITERATION.  X HAS BEEN OVERWRITTEN BY A*X.
     */
    if( jump==1 )
    {
        if( n==1 )
        {
            v->ptr.p_complex[1] = x->ptr.p_complex[1];
            *est = ae_c_abs(v->ptr.p_complex[1], _state);
            *kase = 0;
            rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
            return;
        }
        *est = rcond_internalcomplexrcondscsum1(x, n, _state);
        for(i=1; i<=n; i++)
        {
            absxi = ae_c_abs(x->ptr.p_complex[i], _state);
            if( ae_fp_greater(absxi,safmin) )
            {
                x->ptr.p_complex[i] = ae_c_div_d(x->ptr.p_complex[i],absxi);
            }
            else
            {
                x->ptr.p_complex[i] = ae_complex_from_d(1);
            }
        }
        *kase = 2;
        jump = 2;
        rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
        return;
    }
    
    /*
     * ENTRY   (JUMP = 2)
     * FIRST ITERATION.  X HAS BEEN OVERWRITTEN BY CTRANS(A)*X.
     */
    if( jump==2 )
    {
        j = rcond_internalcomplexrcondicmax1(x, n, _state);
        iter = 2;
        
        /*
         * MAIN LOOP - ITERATIONS 2,3,...,ITMAX.
         */
        for(i=1; i<=n; i++)
        {
            x->ptr.p_complex[i] = ae_complex_from_d(0);
        }
        x->ptr.p_complex[j] = ae_complex_from_d(1);
        *kase = 1;
        jump = 3;
        rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
        return;
    }
    
    /*
     * ENTRY   (JUMP = 3)
     * X HAS BEEN OVERWRITTEN BY A*X.
     */
    if( jump==3 )
    {
        ae_v_cmove(&v->ptr.p_complex[1], 1, &x->ptr.p_complex[1], 1, "N", ae_v_len(1,n));
        estold = *est;
        *est = rcond_internalcomplexrcondscsum1(v, n, _state);
        
        /*
         * TEST FOR CYCLING.
         */
        if( ae_fp_less_eq(*est,estold) )
        {
            
            /*
             * ITERATION COMPLETE.  FINAL STAGE.
             */
            altsgn = 1;
            for(i=1; i<=n; i++)
            {
                x->ptr.p_complex[i] = ae_complex_from_d(altsgn*(1+(double)(i-1)/(double)(n-1)));
                altsgn = -altsgn;
            }
            *kase = 1;
            jump = 5;
            rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
            return;
        }
        for(i=1; i<=n; i++)
        {
            absxi = ae_c_abs(x->ptr.p_complex[i], _state);
            if( ae_fp_greater(absxi,safmin) )
            {
                x->ptr.p_complex[i] = ae_c_div_d(x->ptr.p_complex[i],absxi);
            }
            else
            {
                x->ptr.p_complex[i] = ae_complex_from_d(1);
            }
        }
        *kase = 2;
        jump = 4;
        rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
        return;
    }
    
    /*
     * ENTRY   (JUMP = 4)
     * X HAS BEEN OVERWRITTEN BY CTRANS(A)*X.
     */
    if( jump==4 )
    {
        jlast = j;
        j = rcond_internalcomplexrcondicmax1(x, n, _state);
        if( ae_fp_neq(ae_c_abs(x->ptr.p_complex[jlast], _state),ae_c_abs(x->ptr.p_complex[j], _state))&&iter<itmax )
        {
            iter = iter+1;
            
            /*
             * MAIN LOOP - ITERATIONS 2,3,...,ITMAX.
             */
            for(i=1; i<=n; i++)
            {
                x->ptr.p_complex[i] = ae_complex_from_d(0);
            }
            x->ptr.p_complex[j] = ae_complex_from_d(1);
            *kase = 1;
            jump = 3;
            rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
            return;
        }
        
        /*
         * ITERATION COMPLETE.  FINAL STAGE.
         */
        altsgn = 1;
        for(i=1; i<=n; i++)
        {
            x->ptr.p_complex[i] = ae_complex_from_d(altsgn*(1+(double)(i-1)/(double)(n-1)));
            altsgn = -altsgn;
        }
        *kase = 1;
        jump = 5;
        rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
        return;
    }
    
    /*
     * ENTRY   (JUMP = 5)
     * X HAS BEEN OVERWRITTEN BY A*X.
     */
    if( jump==5 )
    {
        temp = 2*(rcond_internalcomplexrcondscsum1(x, n, _state)/(3*n));
        if( ae_fp_greater(temp,*est) )
        {
            ae_v_cmove(&v->ptr.p_complex[1], 1, &x->ptr.p_complex[1], 1, "N", ae_v_len(1,n));
            *est = temp;
        }
        *kase = 0;
        rcond_internalcomplexrcondsaveall(isave, rsave, &i, &iter, &j, &jlast, &jump, &absxi, &altsgn, &estold, &temp, _state);
        return;
    }
}


static double rcond_internalcomplexrcondscsum1(/* Complex */ ae_vector* x,
     ae_int_t n,
     ae_state *_state)
{
    ae_int_t i;
    double result;


    result = 0;
    for(i=1; i<=n; i++)
    {
        result = result+ae_c_abs(x->ptr.p_complex[i], _state);
    }
    return result;
}


static ae_int_t rcond_internalcomplexrcondicmax1(/* Complex */ ae_vector* x,
     ae_int_t n,
     ae_state *_state)
{
    ae_int_t i;
    double m;
    ae_int_t result;


    result = 1;
    m = ae_c_abs(x->ptr.p_complex[1], _state);
    for(i=2; i<=n; i++)
    {
        if( ae_fp_greater(ae_c_abs(x->ptr.p_complex[i], _state),m) )
        {
            result = i;
            m = ae_c_abs(x->ptr.p_complex[i], _state);
        }
    }
    return result;
}


static void rcond_internalcomplexrcondsaveall(/* Integer */ ae_vector* isave,
     /* Real    */ ae_vector* rsave,
     ae_int_t* i,
     ae_int_t* iter,
     ae_int_t* j,
     ae_int_t* jlast,
     ae_int_t* jump,
     double* absxi,
     double* altsgn,
     double* estold,
     double* temp,
     ae_state *_state)
{


    isave->ptr.p_int[0] = *i;
    isave->ptr.p_int[1] = *iter;
    isave->ptr.p_int[2] = *j;
    isave->ptr.p_int[3] = *jlast;
    isave->ptr.p_int[4] = *jump;
    rsave->ptr.p_double[0] = *absxi;
    rsave->ptr.p_double[1] = *altsgn;
    rsave->ptr.p_double[2] = *estold;
    rsave->ptr.p_double[3] = *temp;
}


static void rcond_internalcomplexrcondloadall(/* Integer */ ae_vector* isave,
     /* Real    */ ae_vector* rsave,
     ae_int_t* i,
     ae_int_t* iter,
     ae_int_t* j,
     ae_int_t* jlast,
     ae_int_t* jump,
     double* absxi,
     double* altsgn,
     double* estold,
     double* temp,
     ae_state *_state)
{


    *i = isave->ptr.p_int[0];
    *iter = isave->ptr.p_int[1];
    *j = isave->ptr.p_int[2];
    *jlast = isave->ptr.p_int[3];
    *jump = isave->ptr.p_int[4];
    *absxi = rsave->ptr.p_double[0];
    *altsgn = rsave->ptr.p_double[1];
    *estold = rsave->ptr.p_double[2];
    *temp = rsave->ptr.p_double[3];
}




/*************************************************************************
Inversion of a matrix given by its LU decomposition.

INPUT PARAMETERS:
    A       -   LU decomposition of the matrix
                (output of RMatrixLU subroutine).
    Pivots  -   table of permutations
                (the output of RMatrixLU subroutine).
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

OUTPUT PARAMETERS:
    Info    -   return code:
                * -3    A is singular, or VERY close to singular.
                        it is filled by zeros in such cases.
                *  1    task is solved (but matrix A may be ill-conditioned,
                        check R1/RInf parameters for condition numbers).
    Rep     -   solver report, see below for more info
    A       -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].

SOLVER REPORT

Subroutine sets following fields of the Rep structure:
* R1        reciprocal of condition number: 1/cond(A), 1-norm.
* RInf      reciprocal of condition number: 1/cond(A), inf-norm.

  -- ALGLIB routine --
     05.02.2010
     Bochkanov Sergey
*************************************************************************/
void rmatrixluinverse(/* Real    */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_int_t i;
    ae_int_t j;
    ae_int_t k;
    double v;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);

    ae_assert(n>0, "RMatrixLUInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "RMatrixLUInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "RMatrixLUInverse: rows(A)<N!", _state);
    ae_assert(pivots->cnt>=n, "RMatrixLUInverse: len(Pivots)<N!", _state);
    ae_assert(apservisfinitematrix(a, n, n, _state), "RMatrixLUInverse: A contains infinite or NaN values!", _state);
    *info = 1;
    for(i=0; i<=n-1; i++)
    {
        if( pivots->ptr.p_int[i]>n-1||pivots->ptr.p_int[i]<i )
        {
            *info = -1;
        }
    }
    ae_assert(*info>0, "RMatrixLUInverse: incorrect Pivots array!", _state);
    
    /*
     * calculate condition numbers
     */
    rep->r1 = rmatrixlurcond1(a, n, _state);
    rep->rinf = rmatrixlurcondinf(a, n, _state);
    if( ae_fp_less(rep->r1,rcondthreshold(_state))||ae_fp_less(rep->rinf,rcondthreshold(_state)) )
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                a->ptr.pp_double[i][j] = 0;
            }
        }
        rep->r1 = 0;
        rep->rinf = 0;
        *info = -3;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Call cache-oblivious code
     */
    ae_vector_set_length(&work, n, _state);
    matinv_rmatrixluinverserec(a, 0, n, &work, info, rep, _state);
    
    /*
     * apply permutations
     */
    for(i=0; i<=n-1; i++)
    {
        for(j=n-2; j>=0; j--)
        {
            k = pivots->ptr.p_int[j];
            v = a->ptr.pp_double[i][j];
            a->ptr.pp_double[i][j] = a->ptr.pp_double[i][k];
            a->ptr.pp_double[i][k] = v;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Inversion of a general matrix.

Input parameters:
    A       -   matrix.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

Result:
    True, if the matrix is not singular.
    False, if the matrix is singular.

  -- ALGLIB --
     Copyright 2005-2010 by Bochkanov Sergey
*************************************************************************/
void rmatrixinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector pivots;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>0, "RMatrixInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "RMatrixInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "RMatrixInverse: rows(A)<N!", _state);
    ae_assert(apservisfinitematrix(a, n, n, _state), "RMatrixInverse: A contains infinite or NaN values!", _state);
    rmatrixlu(a, n, n, &pivots, _state);
    rmatrixluinverse(a, &pivots, n, info, rep, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Inversion of a matrix given by its LU decomposition.

INPUT PARAMETERS:
    A       -   LU decomposition of the matrix
                (output of CMatrixLU subroutine).
    Pivots  -   table of permutations
                (the output of CMatrixLU subroutine).
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

OUTPUT PARAMETERS:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     05.02.2010
     Bochkanov Sergey
*************************************************************************/
void cmatrixluinverse(/* Complex */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector work;
    ae_int_t i;
    ae_int_t j;
    ae_int_t k;
    ae_complex v;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    ae_vector_init(&work, 0, DT_COMPLEX, _state, ae_true);

    ae_assert(n>0, "CMatrixLUInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "CMatrixLUInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "CMatrixLUInverse: rows(A)<N!", _state);
    ae_assert(pivots->cnt>=n, "CMatrixLUInverse: len(Pivots)<N!", _state);
    ae_assert(apservisfinitecmatrix(a, n, n, _state), "CMatrixLUInverse: A contains infinite or NaN values!", _state);
    *info = 1;
    for(i=0; i<=n-1; i++)
    {
        if( pivots->ptr.p_int[i]>n-1||pivots->ptr.p_int[i]<i )
        {
            *info = -1;
        }
    }
    ae_assert(*info>0, "CMatrixLUInverse: incorrect Pivots array!", _state);
    
    /*
     * calculate condition numbers
     */
    rep->r1 = cmatrixlurcond1(a, n, _state);
    rep->rinf = cmatrixlurcondinf(a, n, _state);
    if( ae_fp_less(rep->r1,rcondthreshold(_state))||ae_fp_less(rep->rinf,rcondthreshold(_state)) )
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
            }
        }
        rep->r1 = 0;
        rep->rinf = 0;
        *info = -3;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Call cache-oblivious code
     */
    ae_vector_set_length(&work, n, _state);
    matinv_cmatrixluinverserec(a, 0, n, &work, info, rep, _state);
    
    /*
     * apply permutations
     */
    for(i=0; i<=n-1; i++)
    {
        for(j=n-2; j>=0; j--)
        {
            k = pivots->ptr.p_int[j];
            v = a->ptr.pp_complex[i][j];
            a->ptr.pp_complex[i][j] = a->ptr.pp_complex[i][k];
            a->ptr.pp_complex[i][k] = v;
        }
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Inversion of a general matrix.

Input parameters:
    A       -   matrix
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void cmatrixinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector pivots;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>0, "CRMatrixInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "CRMatrixInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "CRMatrixInverse: rows(A)<N!", _state);
    ae_assert(apservisfinitecmatrix(a, n, n, _state), "CMatrixInverse: A contains infinite or NaN values!", _state);
    cmatrixlu(a, n, n, &pivots, _state);
    cmatrixluinverse(a, &pivots, n, info, rep, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Inversion of a symmetric positive definite matrix which is given
by Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition of the matrix to be inverted:
                A=U�*U or A = L*L'.
                Output of  SPDMatrixCholesky subroutine.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given, lower half is used.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void spdmatrixcholeskyinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector tmp;
    matinvreport rep2;
    ae_bool f;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);
    _matinvreport_init(&rep2, _state, ae_true);

    ae_assert(n>0, "SPDMatrixCholeskyInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "SPDMatrixCholeskyInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "SPDMatrixCholeskyInverse: rows(A)<N!", _state);
    *info = 1;
    f = ae_true;
    for(i=0; i<=n-1; i++)
    {
        f = f&&ae_isfinite(a->ptr.pp_double[i][i], _state);
    }
    ae_assert(f, "SPDMatrixCholeskyInverse: A contains infinite or NaN values!", _state);
    
    /*
     * calculate condition numbers
     */
    rep->r1 = spdmatrixcholeskyrcond(a, n, isupper, _state);
    rep->rinf = rep->r1;
    if( ae_fp_less(rep->r1,rcondthreshold(_state))||ae_fp_less(rep->rinf,rcondthreshold(_state)) )
    {
        if( isupper )
        {
            for(i=0; i<=n-1; i++)
            {
                for(j=i; j<=n-1; j++)
                {
                    a->ptr.pp_double[i][j] = 0;
                }
            }
        }
        else
        {
            for(i=0; i<=n-1; i++)
            {
                for(j=0; j<=i; j++)
                {
                    a->ptr.pp_double[i][j] = 0;
                }
            }
        }
        rep->r1 = 0;
        rep->rinf = 0;
        *info = -3;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Inverse
     */
    ae_vector_set_length(&tmp, n, _state);
    matinv_spdmatrixcholeskyinverserec(a, 0, n, isupper, &tmp, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Inversion of a symmetric positive definite matrix.

Given an upper or lower triangle of a symmetric positive definite matrix,
the algorithm generates matrix A^-1 and saves the upper or lower triangle
depending on the input.

Input parameters:
    A       -   matrix to be inverted (upper or lower triangle).
                Array with elements [0..N-1,0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given,  both lower and upper  triangles  must  be
                  filled.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void spdmatrixinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{

    *info = 0;
    _matinvreport_clear(rep);

    ae_assert(n>0, "SPDMatrixInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "SPDMatrixInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "SPDMatrixInverse: rows(A)<N!", _state);
    ae_assert(isfinitertrmatrix(a, n, isupper, _state), "SPDMatrixInverse: A contains infinite or NaN values!", _state);
    *info = 1;
    if( spdmatrixcholesky(a, n, isupper, _state) )
    {
        spdmatrixcholeskyinverse(a, n, isupper, info, rep, _state);
    }
    else
    {
        *info = -3;
    }
}


/*************************************************************************
Inversion of a Hermitian positive definite matrix which is given
by Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition of the matrix to be inverted:
                A=U�*U or A = L*L'.
                Output of  HPDMatrixCholesky subroutine.
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given, lower half is used.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixcholeskyinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    matinvreport rep2;
    ae_vector tmp;
    ae_bool f;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    _matinvreport_init(&rep2, _state, ae_true);
    ae_vector_init(&tmp, 0, DT_COMPLEX, _state, ae_true);

    ae_assert(n>0, "HPDMatrixCholeskyInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "HPDMatrixCholeskyInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "HPDMatrixCholeskyInverse: rows(A)<N!", _state);
    f = ae_true;
    for(i=0; i<=n-1; i++)
    {
        f = (f&&ae_isfinite(a->ptr.pp_complex[i][i].x, _state))&&ae_isfinite(a->ptr.pp_complex[i][i].y, _state);
    }
    ae_assert(f, "HPDMatrixCholeskyInverse: A contains infinite or NaN values!", _state);
    *info = 1;
    
    /*
     * calculate condition numbers
     */
    rep->r1 = hpdmatrixcholeskyrcond(a, n, isupper, _state);
    rep->rinf = rep->r1;
    if( ae_fp_less(rep->r1,rcondthreshold(_state))||ae_fp_less(rep->rinf,rcondthreshold(_state)) )
    {
        if( isupper )
        {
            for(i=0; i<=n-1; i++)
            {
                for(j=i; j<=n-1; j++)
                {
                    a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
                }
            }
        }
        else
        {
            for(i=0; i<=n-1; i++)
            {
                for(j=0; j<=i; j++)
                {
                    a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
                }
            }
        }
        rep->r1 = 0;
        rep->rinf = 0;
        *info = -3;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Inverse
     */
    ae_vector_set_length(&tmp, n, _state);
    matinv_hpdmatrixcholeskyinverserec(a, 0, n, isupper, &tmp, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Inversion of a Hermitian positive definite matrix.

Given an upper or lower triangle of a Hermitian positive definite matrix,
the algorithm generates matrix A^-1 and saves the upper or lower triangle
depending on the input.

Input parameters:
    A       -   matrix to be inverted (upper or lower triangle).
                Array with elements [0..N-1,0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   storage type (optional):
                * if True, symmetric  matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t  used/changed  by
                  function
                * if False,  symmetric matrix  A  is  given  by  its lower
                  triangle, and the  upper triangle isn�t used/changed  by
                  function
                * if not given,  both lower and upper  triangles  must  be
                  filled.

Output parameters:
    Info    -   return code, same as in RMatrixLUInverse
    Rep     -   solver report, same as in RMatrixLUInverse
    A       -   inverse of matrix A, same as in RMatrixLUInverse

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
void hpdmatrixinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{

    *info = 0;
    _matinvreport_clear(rep);

    ae_assert(n>0, "HPDMatrixInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "HPDMatrixInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "HPDMatrixInverse: rows(A)<N!", _state);
    ae_assert(apservisfinitectrmatrix(a, n, isupper, _state), "HPDMatrixInverse: A contains infinite or NaN values!", _state);
    *info = 1;
    if( hpdmatrixcholesky(a, n, isupper, _state) )
    {
        hpdmatrixcholeskyinverse(a, n, isupper, info, rep, _state);
    }
    else
    {
        *info = -3;
    }
}


/*************************************************************************
Triangular matrix inverse (real)

The subroutine inverts the following types of matrices:
    * upper triangular
    * upper triangular with unit diagonal
    * lower triangular
    * lower triangular with unit diagonal

In case of an upper (lower) triangular matrix,  the  inverse  matrix  will
also be upper (lower) triangular, and after the end of the algorithm,  the
inverse matrix replaces the source matrix. The elements  below (above) the
main diagonal are not changed by the algorithm.

If  the matrix  has a unit diagonal, the inverse matrix also  has  a  unit
diagonal, and the diagonal elements are not passed to the algorithm.

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   diagonal type (optional):
                * if True, matrix has unit diagonal (a[i,i] are NOT used)
                * if False, matrix diagonal is arbitrary
                * if not given, False is assumed

Output parameters:
    Info    -   same as for RMatrixLUInverse
    Rep     -   same as for RMatrixLUInverse
    A       -   same as for RMatrixLUInverse.

  -- ALGLIB --
     Copyright 05.02.2010 by Bochkanov Sergey
*************************************************************************/
void rmatrixtrinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector tmp;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    ae_vector_init(&tmp, 0, DT_REAL, _state, ae_true);

    ae_assert(n>0, "RMatrixTRInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "RMatrixTRInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "RMatrixTRInverse: rows(A)<N!", _state);
    ae_assert(isfinitertrmatrix(a, n, isupper, _state), "RMatrixTRInverse: A contains infinite or NaN values!", _state);
    *info = 1;
    
    /*
     * calculate condition numbers
     */
    rep->r1 = rmatrixtrrcond1(a, n, isupper, isunit, _state);
    rep->rinf = rmatrixtrrcondinf(a, n, isupper, isunit, _state);
    if( ae_fp_less(rep->r1,rcondthreshold(_state))||ae_fp_less(rep->rinf,rcondthreshold(_state)) )
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                a->ptr.pp_double[i][j] = 0;
            }
        }
        rep->r1 = 0;
        rep->rinf = 0;
        *info = -3;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Invert
     */
    ae_vector_set_length(&tmp, n, _state);
    matinv_rmatrixtrinverserec(a, 0, n, isupper, isunit, &tmp, info, rep, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Triangular matrix inverse (complex)

The subroutine inverts the following types of matrices:
    * upper triangular
    * upper triangular with unit diagonal
    * lower triangular
    * lower triangular with unit diagonal

In case of an upper (lower) triangular matrix,  the  inverse  matrix  will
also be upper (lower) triangular, and after the end of the algorithm,  the
inverse matrix replaces the source matrix. The elements  below (above) the
main diagonal are not changed by the algorithm.

If  the matrix  has a unit diagonal, the inverse matrix also  has  a  unit
diagonal, and the diagonal elements are not passed to the algorithm.

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1].
    N       -   size of matrix A (optional) :
                * if given, only principal NxN submatrix is processed  and
                  overwritten. other elements are unchanged.
                * if not given,  size  is  automatically  determined  from
                  matrix size (A must be square matrix)
    IsUpper -   True, if the matrix is upper triangular.
    IsUnit  -   diagonal type (optional):
                * if True, matrix has unit diagonal (a[i,i] are NOT used)
                * if False, matrix diagonal is arbitrary
                * if not given, False is assumed

Output parameters:
    Info    -   same as for RMatrixLUInverse
    Rep     -   same as for RMatrixLUInverse
    A       -   same as for RMatrixLUInverse.

  -- ALGLIB --
     Copyright 05.02.2010 by Bochkanov Sergey
*************************************************************************/
void cmatrixtrinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_vector tmp;

    ae_frame_make(_state, &_frame_block);
    *info = 0;
    _matinvreport_clear(rep);
    ae_vector_init(&tmp, 0, DT_COMPLEX, _state, ae_true);

    ae_assert(n>0, "CMatrixTRInverse: N<=0!", _state);
    ae_assert(a->cols>=n, "CMatrixTRInverse: cols(A)<N!", _state);
    ae_assert(a->rows>=n, "CMatrixTRInverse: rows(A)<N!", _state);
    ae_assert(apservisfinitectrmatrix(a, n, isupper, _state), "CMatrixTRInverse: A contains infinite or NaN values!", _state);
    *info = 1;
    
    /*
     * calculate condition numbers
     */
    rep->r1 = cmatrixtrrcond1(a, n, isupper, isunit, _state);
    rep->rinf = cmatrixtrrcondinf(a, n, isupper, isunit, _state);
    if( ae_fp_less(rep->r1,rcondthreshold(_state))||ae_fp_less(rep->rinf,rcondthreshold(_state)) )
    {
        for(i=0; i<=n-1; i++)
        {
            for(j=0; j<=n-1; j++)
            {
                a->ptr.pp_complex[i][j] = ae_complex_from_d(0);
            }
        }
        rep->r1 = 0;
        rep->rinf = 0;
        *info = -3;
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Invert
     */
    ae_vector_set_length(&tmp, n, _state);
    matinv_cmatrixtrinverserec(a, 0, n, isupper, isunit, &tmp, info, rep, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Triangular matrix inversion, recursive subroutine

  -- ALGLIB --
     05.02.2010, Bochkanov Sergey.
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992.
*************************************************************************/
static void matinv_rmatrixtrinverserec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     /* Real    */ ae_vector* tmp,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_int_t n1;
    ae_int_t n2;
    ae_int_t i;
    ae_int_t j;
    double v;
    double ajj;


    if( n<1 )
    {
        *info = -1;
        return;
    }
    
    /*
     * Base case
     */
    if( n<=ablasblocksize(a, _state) )
    {
        if( isupper )
        {
            
            /*
             * Compute inverse of upper triangular matrix.
             */
            for(j=0; j<=n-1; j++)
            {
                if( !isunit )
                {
                    if( ae_fp_eq(a->ptr.pp_double[offs+j][offs+j],0) )
                    {
                        *info = -3;
                        return;
                    }
                    a->ptr.pp_double[offs+j][offs+j] = 1/a->ptr.pp_double[offs+j][offs+j];
                    ajj = -a->ptr.pp_double[offs+j][offs+j];
                }
                else
                {
                    ajj = -1;
                }
                
                /*
                 * Compute elements 1:j-1 of j-th column.
                 */
                if( j>0 )
                {
                    ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+0][offs+j], a->stride, ae_v_len(0,j-1));
                    for(i=0; i<=j-1; i++)
                    {
                        if( i<j-1 )
                        {
                            v = ae_v_dotproduct(&a->ptr.pp_double[offs+i][offs+i+1], 1, &tmp->ptr.p_double[i+1], 1, ae_v_len(offs+i+1,offs+j-1));
                        }
                        else
                        {
                            v = 0;
                        }
                        if( !isunit )
                        {
                            a->ptr.pp_double[offs+i][offs+j] = v+a->ptr.pp_double[offs+i][offs+i]*tmp->ptr.p_double[i];
                        }
                        else
                        {
                            a->ptr.pp_double[offs+i][offs+j] = v+tmp->ptr.p_double[i];
                        }
                    }
                    ae_v_muld(&a->ptr.pp_double[offs+0][offs+j], a->stride, ae_v_len(offs+0,offs+j-1), ajj);
                }
            }
        }
        else
        {
            
            /*
             * Compute inverse of lower triangular matrix.
             */
            for(j=n-1; j>=0; j--)
            {
                if( !isunit )
                {
                    if( ae_fp_eq(a->ptr.pp_double[offs+j][offs+j],0) )
                    {
                        *info = -3;
                        return;
                    }
                    a->ptr.pp_double[offs+j][offs+j] = 1/a->ptr.pp_double[offs+j][offs+j];
                    ajj = -a->ptr.pp_double[offs+j][offs+j];
                }
                else
                {
                    ajj = -1;
                }
                if( j<n-1 )
                {
                    
                    /*
                     * Compute elements j+1:n of j-th column.
                     */
                    ae_v_move(&tmp->ptr.p_double[j+1], 1, &a->ptr.pp_double[offs+j+1][offs+j], a->stride, ae_v_len(j+1,n-1));
                    for(i=j+1; i<=n-1; i++)
                    {
                        if( i>j+1 )
                        {
                            v = ae_v_dotproduct(&a->ptr.pp_double[offs+i][offs+j+1], 1, &tmp->ptr.p_double[j+1], 1, ae_v_len(offs+j+1,offs+i-1));
                        }
                        else
                        {
                            v = 0;
                        }
                        if( !isunit )
                        {
                            a->ptr.pp_double[offs+i][offs+j] = v+a->ptr.pp_double[offs+i][offs+i]*tmp->ptr.p_double[i];
                        }
                        else
                        {
                            a->ptr.pp_double[offs+i][offs+j] = v+tmp->ptr.p_double[i];
                        }
                    }
                    ae_v_muld(&a->ptr.pp_double[offs+j+1][offs+j], a->stride, ae_v_len(offs+j+1,offs+n-1), ajj);
                }
            }
        }
        return;
    }
    
    /*
     * Recursive case
     */
    ablassplitlength(a, n, &n1, &n2, _state);
    if( n2>0 )
    {
        if( isupper )
        {
            for(i=0; i<=n1-1; i++)
            {
                ae_v_muld(&a->ptr.pp_double[offs+i][offs+n1], 1, ae_v_len(offs+n1,offs+n-1), -1);
            }
            rmatrixlefttrsm(n1, n2, a, offs, offs, isupper, isunit, 0, a, offs, offs+n1, _state);
            rmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, isupper, isunit, 0, a, offs, offs+n1, _state);
        }
        else
        {
            for(i=0; i<=n2-1; i++)
            {
                ae_v_muld(&a->ptr.pp_double[offs+n1+i][offs], 1, ae_v_len(offs,offs+n1-1), -1);
            }
            rmatrixrighttrsm(n2, n1, a, offs, offs, isupper, isunit, 0, a, offs+n1, offs, _state);
            rmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, isupper, isunit, 0, a, offs+n1, offs, _state);
        }
        matinv_rmatrixtrinverserec(a, offs+n1, n2, isupper, isunit, tmp, info, rep, _state);
    }
    matinv_rmatrixtrinverserec(a, offs, n1, isupper, isunit, tmp, info, rep, _state);
}


/*************************************************************************
Triangular matrix inversion, recursive subroutine

  -- ALGLIB --
     05.02.2010, Bochkanov Sergey.
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     February 29, 1992.
*************************************************************************/
static void matinv_cmatrixtrinverserec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     /* Complex */ ae_vector* tmp,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_int_t n1;
    ae_int_t n2;
    ae_int_t i;
    ae_int_t j;
    ae_complex v;
    ae_complex ajj;


    if( n<1 )
    {
        *info = -1;
        return;
    }
    
    /*
     * Base case
     */
    if( n<=ablascomplexblocksize(a, _state) )
    {
        if( isupper )
        {
            
            /*
             * Compute inverse of upper triangular matrix.
             */
            for(j=0; j<=n-1; j++)
            {
                if( !isunit )
                {
                    if( ae_c_eq_d(a->ptr.pp_complex[offs+j][offs+j],0) )
                    {
                        *info = -3;
                        return;
                    }
                    a->ptr.pp_complex[offs+j][offs+j] = ae_c_d_div(1,a->ptr.pp_complex[offs+j][offs+j]);
                    ajj = ae_c_neg(a->ptr.pp_complex[offs+j][offs+j]);
                }
                else
                {
                    ajj = ae_complex_from_d(-1);
                }
                
                /*
                 * Compute elements 1:j-1 of j-th column.
                 */
                if( j>0 )
                {
                    ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+0][offs+j], a->stride, "N", ae_v_len(0,j-1));
                    for(i=0; i<=j-1; i++)
                    {
                        if( i<j-1 )
                        {
                            v = ae_v_cdotproduct(&a->ptr.pp_complex[offs+i][offs+i+1], 1, "N", &tmp->ptr.p_complex[i+1], 1, "N", ae_v_len(offs+i+1,offs+j-1));
                        }
                        else
                        {
                            v = ae_complex_from_d(0);
                        }
                        if( !isunit )
                        {
                            a->ptr.pp_complex[offs+i][offs+j] = ae_c_add(v,ae_c_mul(a->ptr.pp_complex[offs+i][offs+i],tmp->ptr.p_complex[i]));
                        }
                        else
                        {
                            a->ptr.pp_complex[offs+i][offs+j] = ae_c_add(v,tmp->ptr.p_complex[i]);
                        }
                    }
                    ae_v_cmulc(&a->ptr.pp_complex[offs+0][offs+j], a->stride, ae_v_len(offs+0,offs+j-1), ajj);
                }
            }
        }
        else
        {
            
            /*
             * Compute inverse of lower triangular matrix.
             */
            for(j=n-1; j>=0; j--)
            {
                if( !isunit )
                {
                    if( ae_c_eq_d(a->ptr.pp_complex[offs+j][offs+j],0) )
                    {
                        *info = -3;
                        return;
                    }
                    a->ptr.pp_complex[offs+j][offs+j] = ae_c_d_div(1,a->ptr.pp_complex[offs+j][offs+j]);
                    ajj = ae_c_neg(a->ptr.pp_complex[offs+j][offs+j]);
                }
                else
                {
                    ajj = ae_complex_from_d(-1);
                }
                if( j<n-1 )
                {
                    
                    /*
                     * Compute elements j+1:n of j-th column.
                     */
                    ae_v_cmove(&tmp->ptr.p_complex[j+1], 1, &a->ptr.pp_complex[offs+j+1][offs+j], a->stride, "N", ae_v_len(j+1,n-1));
                    for(i=j+1; i<=n-1; i++)
                    {
                        if( i>j+1 )
                        {
                            v = ae_v_cdotproduct(&a->ptr.pp_complex[offs+i][offs+j+1], 1, "N", &tmp->ptr.p_complex[j+1], 1, "N", ae_v_len(offs+j+1,offs+i-1));
                        }
                        else
                        {
                            v = ae_complex_from_d(0);
                        }
                        if( !isunit )
                        {
                            a->ptr.pp_complex[offs+i][offs+j] = ae_c_add(v,ae_c_mul(a->ptr.pp_complex[offs+i][offs+i],tmp->ptr.p_complex[i]));
                        }
                        else
                        {
                            a->ptr.pp_complex[offs+i][offs+j] = ae_c_add(v,tmp->ptr.p_complex[i]);
                        }
                    }
                    ae_v_cmulc(&a->ptr.pp_complex[offs+j+1][offs+j], a->stride, ae_v_len(offs+j+1,offs+n-1), ajj);
                }
            }
        }
        return;
    }
    
    /*
     * Recursive case
     */
    ablascomplexsplitlength(a, n, &n1, &n2, _state);
    if( n2>0 )
    {
        if( isupper )
        {
            for(i=0; i<=n1-1; i++)
            {
                ae_v_cmuld(&a->ptr.pp_complex[offs+i][offs+n1], 1, ae_v_len(offs+n1,offs+n-1), -1);
            }
            cmatrixlefttrsm(n1, n2, a, offs, offs, isupper, isunit, 0, a, offs, offs+n1, _state);
            cmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, isupper, isunit, 0, a, offs, offs+n1, _state);
        }
        else
        {
            for(i=0; i<=n2-1; i++)
            {
                ae_v_cmuld(&a->ptr.pp_complex[offs+n1+i][offs], 1, ae_v_len(offs,offs+n1-1), -1);
            }
            cmatrixrighttrsm(n2, n1, a, offs, offs, isupper, isunit, 0, a, offs+n1, offs, _state);
            cmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, isupper, isunit, 0, a, offs+n1, offs, _state);
        }
        matinv_cmatrixtrinverserec(a, offs+n1, n2, isupper, isunit, tmp, info, rep, _state);
    }
    matinv_cmatrixtrinverserec(a, offs, n1, isupper, isunit, tmp, info, rep, _state);
}


static void matinv_rmatrixluinverserec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     /* Real    */ ae_vector* work,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    double v;
    ae_int_t n1;
    ae_int_t n2;


    if( n<1 )
    {
        *info = -1;
        return;
    }
    
    /*
     * Base case
     */
    if( n<=ablasblocksize(a, _state) )
    {
        
        /*
         * Form inv(U)
         */
        matinv_rmatrixtrinverserec(a, offs, n, ae_true, ae_false, work, info, rep, _state);
        if( *info<=0 )
        {
            return;
        }
        
        /*
         * Solve the equation inv(A)*L = inv(U) for inv(A).
         */
        for(j=n-1; j>=0; j--)
        {
            
            /*
             * Copy current column of L to WORK and replace with zeros.
             */
            for(i=j+1; i<=n-1; i++)
            {
                work->ptr.p_double[i] = a->ptr.pp_double[offs+i][offs+j];
                a->ptr.pp_double[offs+i][offs+j] = 0;
            }
            
            /*
             * Compute current column of inv(A).
             */
            if( j<n-1 )
            {
                for(i=0; i<=n-1; i++)
                {
                    v = ae_v_dotproduct(&a->ptr.pp_double[offs+i][offs+j+1], 1, &work->ptr.p_double[j+1], 1, ae_v_len(offs+j+1,offs+n-1));
                    a->ptr.pp_double[offs+i][offs+j] = a->ptr.pp_double[offs+i][offs+j]-v;
                }
            }
        }
        return;
    }
    
    /*
     * Recursive code:
     *
     *         ( L1      )   ( U1  U12 )
     * A    =  (         ) * (         )
     *         ( L12  L2 )   (     U2  )
     *
     *         ( W   X )
     * A^-1 =  (       )
     *         ( Y   Z )
     */
    ablassplitlength(a, n, &n1, &n2, _state);
    ae_assert(n2>0, "LUInverseRec: internal error!", _state);
    
    /*
     * X := inv(U1)*U12*inv(U2)
     */
    rmatrixlefttrsm(n1, n2, a, offs, offs, ae_true, ae_false, 0, a, offs, offs+n1, _state);
    rmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, ae_true, ae_false, 0, a, offs, offs+n1, _state);
    
    /*
     * Y := inv(L2)*L12*inv(L1)
     */
    rmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, ae_false, ae_true, 0, a, offs+n1, offs, _state);
    rmatrixrighttrsm(n2, n1, a, offs, offs, ae_false, ae_true, 0, a, offs+n1, offs, _state);
    
    /*
     * W := inv(L1*U1)+X*Y
     */
    matinv_rmatrixluinverserec(a, offs, n1, work, info, rep, _state);
    if( *info<=0 )
    {
        return;
    }
    rmatrixgemm(n1, n1, n2, 1.0, a, offs, offs+n1, 0, a, offs+n1, offs, 0, 1.0, a, offs, offs, _state);
    
    /*
     * X := -X*inv(L2)
     * Y := -inv(U2)*Y
     */
    rmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, ae_false, ae_true, 0, a, offs, offs+n1, _state);
    for(i=0; i<=n1-1; i++)
    {
        ae_v_muld(&a->ptr.pp_double[offs+i][offs+n1], 1, ae_v_len(offs+n1,offs+n-1), -1);
    }
    rmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, ae_true, ae_false, 0, a, offs+n1, offs, _state);
    for(i=0; i<=n2-1; i++)
    {
        ae_v_muld(&a->ptr.pp_double[offs+n1+i][offs], 1, ae_v_len(offs,offs+n1-1), -1);
    }
    
    /*
     * Z := inv(L2*U2)
     */
    matinv_rmatrixluinverserec(a, offs+n1, n2, work, info, rep, _state);
}


static void matinv_cmatrixluinverserec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     /* Complex */ ae_vector* work,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t j;
    ae_complex v;
    ae_int_t n1;
    ae_int_t n2;


    if( n<1 )
    {
        *info = -1;
        return;
    }
    
    /*
     * Base case
     */
    if( n<=ablascomplexblocksize(a, _state) )
    {
        
        /*
         * Form inv(U)
         */
        matinv_cmatrixtrinverserec(a, offs, n, ae_true, ae_false, work, info, rep, _state);
        if( *info<=0 )
        {
            return;
        }
        
        /*
         * Solve the equation inv(A)*L = inv(U) for inv(A).
         */
        for(j=n-1; j>=0; j--)
        {
            
            /*
             * Copy current column of L to WORK and replace with zeros.
             */
            for(i=j+1; i<=n-1; i++)
            {
                work->ptr.p_complex[i] = a->ptr.pp_complex[offs+i][offs+j];
                a->ptr.pp_complex[offs+i][offs+j] = ae_complex_from_d(0);
            }
            
            /*
             * Compute current column of inv(A).
             */
            if( j<n-1 )
            {
                for(i=0; i<=n-1; i++)
                {
                    v = ae_v_cdotproduct(&a->ptr.pp_complex[offs+i][offs+j+1], 1, "N", &work->ptr.p_complex[j+1], 1, "N", ae_v_len(offs+j+1,offs+n-1));
                    a->ptr.pp_complex[offs+i][offs+j] = ae_c_sub(a->ptr.pp_complex[offs+i][offs+j],v);
                }
            }
        }
        return;
    }
    
    /*
     * Recursive code:
     *
     *         ( L1      )   ( U1  U12 )
     * A    =  (         ) * (         )
     *         ( L12  L2 )   (     U2  )
     *
     *         ( W   X )
     * A^-1 =  (       )
     *         ( Y   Z )
     */
    ablascomplexsplitlength(a, n, &n1, &n2, _state);
    ae_assert(n2>0, "LUInverseRec: internal error!", _state);
    
    /*
     * X := inv(U1)*U12*inv(U2)
     */
    cmatrixlefttrsm(n1, n2, a, offs, offs, ae_true, ae_false, 0, a, offs, offs+n1, _state);
    cmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, ae_true, ae_false, 0, a, offs, offs+n1, _state);
    
    /*
     * Y := inv(L2)*L12*inv(L1)
     */
    cmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, ae_false, ae_true, 0, a, offs+n1, offs, _state);
    cmatrixrighttrsm(n2, n1, a, offs, offs, ae_false, ae_true, 0, a, offs+n1, offs, _state);
    
    /*
     * W := inv(L1*U1)+X*Y
     */
    matinv_cmatrixluinverserec(a, offs, n1, work, info, rep, _state);
    if( *info<=0 )
    {
        return;
    }
    cmatrixgemm(n1, n1, n2, ae_complex_from_d(1.0), a, offs, offs+n1, 0, a, offs+n1, offs, 0, ae_complex_from_d(1.0), a, offs, offs, _state);
    
    /*
     * X := -X*inv(L2)
     * Y := -inv(U2)*Y
     */
    cmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, ae_false, ae_true, 0, a, offs, offs+n1, _state);
    for(i=0; i<=n1-1; i++)
    {
        ae_v_cmuld(&a->ptr.pp_complex[offs+i][offs+n1], 1, ae_v_len(offs+n1,offs+n-1), -1);
    }
    cmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, ae_true, ae_false, 0, a, offs+n1, offs, _state);
    for(i=0; i<=n2-1; i++)
    {
        ae_v_cmuld(&a->ptr.pp_complex[offs+n1+i][offs], 1, ae_v_len(offs,offs+n1-1), -1);
    }
    
    /*
     * Z := inv(L2*U2)
     */
    matinv_cmatrixluinverserec(a, offs+n1, n2, work, info, rep, _state);
}


/*************************************************************************
Recursive subroutine for SPD inversion.

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
static void matinv_spdmatrixcholeskyinverserec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    double v;
    ae_int_t n1;
    ae_int_t n2;
    ae_int_t info2;
    matinvreport rep2;

    ae_frame_make(_state, &_frame_block);
    _matinvreport_init(&rep2, _state, ae_true);

    if( n<1 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Base case
     */
    if( n<=ablasblocksize(a, _state) )
    {
        matinv_rmatrixtrinverserec(a, offs, n, isupper, ae_false, tmp, &info2, &rep2, _state);
        if( isupper )
        {
            
            /*
             * Compute the product U * U'.
             * NOTE: we never assume that diagonal of U is real
             */
            for(i=0; i<=n-1; i++)
            {
                if( i==0 )
                {
                    
                    /*
                     * 1x1 matrix
                     */
                    a->ptr.pp_double[offs+i][offs+i] = ae_sqr(a->ptr.pp_double[offs+i][offs+i], _state);
                }
                else
                {
                    
                    /*
                     * (I+1)x(I+1) matrix,
                     *
                     * ( A11  A12 )   ( A11^H        )   ( A11*A11^H+A12*A12^H  A12*A22^H )
                     * (          ) * (              ) = (                                )
                     * (      A22 )   ( A12^H  A22^H )   ( A22*A12^H            A22*A22^H )
                     *
                     * A11 is IxI, A22 is 1x1.
                     */
                    ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs][offs+i], a->stride, ae_v_len(0,i-1));
                    for(j=0; j<=i-1; j++)
                    {
                        v = a->ptr.pp_double[offs+j][offs+i];
                        ae_v_addd(&a->ptr.pp_double[offs+j][offs+j], 1, &tmp->ptr.p_double[j], 1, ae_v_len(offs+j,offs+i-1), v);
                    }
                    v = a->ptr.pp_double[offs+i][offs+i];
                    ae_v_muld(&a->ptr.pp_double[offs][offs+i], a->stride, ae_v_len(offs,offs+i-1), v);
                    a->ptr.pp_double[offs+i][offs+i] = ae_sqr(a->ptr.pp_double[offs+i][offs+i], _state);
                }
            }
        }
        else
        {
            
            /*
             * Compute the product L' * L
             * NOTE: we never assume that diagonal of L is real
             */
            for(i=0; i<=n-1; i++)
            {
                if( i==0 )
                {
                    
                    /*
                     * 1x1 matrix
                     */
                    a->ptr.pp_double[offs+i][offs+i] = ae_sqr(a->ptr.pp_double[offs+i][offs+i], _state);
                }
                else
                {
                    
                    /*
                     * (I+1)x(I+1) matrix,
                     *
                     * ( A11^H  A21^H )   ( A11      )   ( A11^H*A11+A21^H*A21  A21^H*A22 )
                     * (              ) * (          ) = (                                )
                     * (        A22^H )   ( A21  A22 )   ( A22^H*A21            A22^H*A22 )
                     *
                     * A11 is IxI, A22 is 1x1.
                     */
                    ae_v_move(&tmp->ptr.p_double[0], 1, &a->ptr.pp_double[offs+i][offs], 1, ae_v_len(0,i-1));
                    for(j=0; j<=i-1; j++)
                    {
                        v = a->ptr.pp_double[offs+i][offs+j];
                        ae_v_addd(&a->ptr.pp_double[offs+j][offs], 1, &tmp->ptr.p_double[0], 1, ae_v_len(offs,offs+j), v);
                    }
                    v = a->ptr.pp_double[offs+i][offs+i];
                    ae_v_muld(&a->ptr.pp_double[offs+i][offs], 1, ae_v_len(offs,offs+i-1), v);
                    a->ptr.pp_double[offs+i][offs+i] = ae_sqr(a->ptr.pp_double[offs+i][offs+i], _state);
                }
            }
        }
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Recursive code: triangular factor inversion merged with
     * UU' or L'L multiplication
     */
    ablassplitlength(a, n, &n1, &n2, _state);
    
    /*
     * form off-diagonal block of trangular inverse
     */
    if( isupper )
    {
        for(i=0; i<=n1-1; i++)
        {
            ae_v_muld(&a->ptr.pp_double[offs+i][offs+n1], 1, ae_v_len(offs+n1,offs+n-1), -1);
        }
        rmatrixlefttrsm(n1, n2, a, offs, offs, isupper, ae_false, 0, a, offs, offs+n1, _state);
        rmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, isupper, ae_false, 0, a, offs, offs+n1, _state);
    }
    else
    {
        for(i=0; i<=n2-1; i++)
        {
            ae_v_muld(&a->ptr.pp_double[offs+n1+i][offs], 1, ae_v_len(offs,offs+n1-1), -1);
        }
        rmatrixrighttrsm(n2, n1, a, offs, offs, isupper, ae_false, 0, a, offs+n1, offs, _state);
        rmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, isupper, ae_false, 0, a, offs+n1, offs, _state);
    }
    
    /*
     * invert first diagonal block
     */
    matinv_spdmatrixcholeskyinverserec(a, offs, n1, isupper, tmp, _state);
    
    /*
     * update first diagonal block with off-diagonal block,
     * update off-diagonal block
     */
    if( isupper )
    {
        rmatrixsyrk(n1, n2, 1.0, a, offs, offs+n1, 0, 1.0, a, offs, offs, isupper, _state);
        rmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, isupper, ae_false, 1, a, offs, offs+n1, _state);
    }
    else
    {
        rmatrixsyrk(n1, n2, 1.0, a, offs+n1, offs, 1, 1.0, a, offs, offs, isupper, _state);
        rmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, isupper, ae_false, 1, a, offs+n1, offs, _state);
    }
    
    /*
     * invert second diagonal block
     */
    matinv_spdmatrixcholeskyinverserec(a, offs+n1, n2, isupper, tmp, _state);
    ae_frame_leave(_state);
}


/*************************************************************************
Recursive subroutine for HPD inversion.

  -- ALGLIB routine --
     10.02.2010
     Bochkanov Sergey
*************************************************************************/
static void matinv_hpdmatrixcholeskyinverserec(/* Complex */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tmp,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_int_t i;
    ae_int_t j;
    ae_complex v;
    ae_int_t n1;
    ae_int_t n2;
    ae_int_t info2;
    matinvreport rep2;

    ae_frame_make(_state, &_frame_block);
    _matinvreport_init(&rep2, _state, ae_true);

    if( n<1 )
    {
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Base case
     */
    if( n<=ablascomplexblocksize(a, _state) )
    {
        matinv_cmatrixtrinverserec(a, offs, n, isupper, ae_false, tmp, &info2, &rep2, _state);
        if( isupper )
        {
            
            /*
             * Compute the product U * U'.
             * NOTE: we never assume that diagonal of U is real
             */
            for(i=0; i<=n-1; i++)
            {
                if( i==0 )
                {
                    
                    /*
                     * 1x1 matrix
                     */
                    a->ptr.pp_complex[offs+i][offs+i] = ae_complex_from_d(ae_sqr(a->ptr.pp_complex[offs+i][offs+i].x, _state)+ae_sqr(a->ptr.pp_complex[offs+i][offs+i].y, _state));
                }
                else
                {
                    
                    /*
                     * (I+1)x(I+1) matrix,
                     *
                     * ( A11  A12 )   ( A11^H        )   ( A11*A11^H+A12*A12^H  A12*A22^H )
                     * (          ) * (              ) = (                                )
                     * (      A22 )   ( A12^H  A22^H )   ( A22*A12^H            A22*A22^H )
                     *
                     * A11 is IxI, A22 is 1x1.
                     */
                    ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs][offs+i], a->stride, "Conj", ae_v_len(0,i-1));
                    for(j=0; j<=i-1; j++)
                    {
                        v = a->ptr.pp_complex[offs+j][offs+i];
                        ae_v_caddc(&a->ptr.pp_complex[offs+j][offs+j], 1, &tmp->ptr.p_complex[j], 1, "N", ae_v_len(offs+j,offs+i-1), v);
                    }
                    v = ae_c_conj(a->ptr.pp_complex[offs+i][offs+i], _state);
                    ae_v_cmulc(&a->ptr.pp_complex[offs][offs+i], a->stride, ae_v_len(offs,offs+i-1), v);
                    a->ptr.pp_complex[offs+i][offs+i] = ae_complex_from_d(ae_sqr(a->ptr.pp_complex[offs+i][offs+i].x, _state)+ae_sqr(a->ptr.pp_complex[offs+i][offs+i].y, _state));
                }
            }
        }
        else
        {
            
            /*
             * Compute the product L' * L
             * NOTE: we never assume that diagonal of L is real
             */
            for(i=0; i<=n-1; i++)
            {
                if( i==0 )
                {
                    
                    /*
                     * 1x1 matrix
                     */
                    a->ptr.pp_complex[offs+i][offs+i] = ae_complex_from_d(ae_sqr(a->ptr.pp_complex[offs+i][offs+i].x, _state)+ae_sqr(a->ptr.pp_complex[offs+i][offs+i].y, _state));
                }
                else
                {
                    
                    /*
                     * (I+1)x(I+1) matrix,
                     *
                     * ( A11^H  A21^H )   ( A11      )   ( A11^H*A11+A21^H*A21  A21^H*A22 )
                     * (              ) * (          ) = (                                )
                     * (        A22^H )   ( A21  A22 )   ( A22^H*A21            A22^H*A22 )
                     *
                     * A11 is IxI, A22 is 1x1.
                     */
                    ae_v_cmove(&tmp->ptr.p_complex[0], 1, &a->ptr.pp_complex[offs+i][offs], 1, "N", ae_v_len(0,i-1));
                    for(j=0; j<=i-1; j++)
                    {
                        v = ae_c_conj(a->ptr.pp_complex[offs+i][offs+j], _state);
                        ae_v_caddc(&a->ptr.pp_complex[offs+j][offs], 1, &tmp->ptr.p_complex[0], 1, "N", ae_v_len(offs,offs+j), v);
                    }
                    v = ae_c_conj(a->ptr.pp_complex[offs+i][offs+i], _state);
                    ae_v_cmulc(&a->ptr.pp_complex[offs+i][offs], 1, ae_v_len(offs,offs+i-1), v);
                    a->ptr.pp_complex[offs+i][offs+i] = ae_complex_from_d(ae_sqr(a->ptr.pp_complex[offs+i][offs+i].x, _state)+ae_sqr(a->ptr.pp_complex[offs+i][offs+i].y, _state));
                }
            }
        }
        ae_frame_leave(_state);
        return;
    }
    
    /*
     * Recursive code: triangular factor inversion merged with
     * UU' or L'L multiplication
     */
    ablascomplexsplitlength(a, n, &n1, &n2, _state);
    
    /*
     * form off-diagonal block of trangular inverse
     */
    if( isupper )
    {
        for(i=0; i<=n1-1; i++)
        {
            ae_v_cmuld(&a->ptr.pp_complex[offs+i][offs+n1], 1, ae_v_len(offs+n1,offs+n-1), -1);
        }
        cmatrixlefttrsm(n1, n2, a, offs, offs, isupper, ae_false, 0, a, offs, offs+n1, _state);
        cmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, isupper, ae_false, 0, a, offs, offs+n1, _state);
    }
    else
    {
        for(i=0; i<=n2-1; i++)
        {
            ae_v_cmuld(&a->ptr.pp_complex[offs+n1+i][offs], 1, ae_v_len(offs,offs+n1-1), -1);
        }
        cmatrixrighttrsm(n2, n1, a, offs, offs, isupper, ae_false, 0, a, offs+n1, offs, _state);
        cmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, isupper, ae_false, 0, a, offs+n1, offs, _state);
    }
    
    /*
     * invert first diagonal block
     */
    matinv_hpdmatrixcholeskyinverserec(a, offs, n1, isupper, tmp, _state);
    
    /*
     * update first diagonal block with off-diagonal block,
     * update off-diagonal block
     */
    if( isupper )
    {
        cmatrixsyrk(n1, n2, 1.0, a, offs, offs+n1, 0, 1.0, a, offs, offs, isupper, _state);
        cmatrixrighttrsm(n1, n2, a, offs+n1, offs+n1, isupper, ae_false, 2, a, offs, offs+n1, _state);
    }
    else
    {
        cmatrixsyrk(n1, n2, 1.0, a, offs+n1, offs, 2, 1.0, a, offs, offs, isupper, _state);
        cmatrixlefttrsm(n2, n1, a, offs+n1, offs+n1, isupper, ae_false, 2, a, offs+n1, offs, _state);
    }
    
    /*
     * invert second diagonal block
     */
    matinv_hpdmatrixcholeskyinverserec(a, offs+n1, n2, isupper, tmp, _state);
    ae_frame_leave(_state);
}


ae_bool _matinvreport_init(matinvreport* p, ae_state *_state, ae_bool make_automatic)
{
    return ae_true;
}


ae_bool _matinvreport_init_copy(matinvreport* dst, matinvreport* src, ae_state *_state, ae_bool make_automatic)
{
    dst->r1 = src->r1;
    dst->rinf = src->rinf;
    return ae_true;
}


void _matinvreport_clear(matinvreport* p)
{
}




/*************************************************************************
Singular value decomposition of a bidiagonal matrix (extended algorithm)

The algorithm performs the singular value decomposition  of  a  bidiagonal
matrix B (upper or lower) representing it as B = Q*S*P^T, where Q and  P -
orthogonal matrices, S - diagonal matrix with non-negative elements on the
main diagonal, in descending order.

The  algorithm  finds  singular  values.  In  addition,  the algorithm can
calculate  matrices  Q  and P (more precisely, not the matrices, but their
product  with  given  matrices U and VT - U*Q and (P^T)*VT)).  Of  course,
matrices U and VT can be of any type, including identity. Furthermore, the
algorithm can calculate Q'*C (this product is calculated more  effectively
than U*Q,  because  this calculation operates with rows instead  of matrix
columns).

The feature of the algorithm is its ability to find  all  singular  values
including those which are arbitrarily close to 0  with  relative  accuracy
close to  machine precision. If the parameter IsFractionalAccuracyRequired
is set to True, all singular values will have high relative accuracy close
to machine precision. If the parameter is set to False, only  the  biggest
singular value will have relative accuracy  close  to  machine  precision.
The absolute error of other singular values is equal to the absolute error
of the biggest singular value.

Input parameters:
    D       -   main diagonal of matrix B.
                Array whose index ranges within [0..N-1].
    E       -   superdiagonal (or subdiagonal) of matrix B.
                Array whose index ranges within [0..N-2].
    N       -   size of matrix B.
    IsUpper -   True, if the matrix is upper bidiagonal.
    IsFractionalAccuracyRequired -
                accuracy to search singular values with.
    U       -   matrix to be multiplied by Q.
                Array whose indexes range within [0..NRU-1, 0..N-1].
                The matrix can be bigger, in that case only the  submatrix
                [0..NRU-1, 0..N-1] will be multiplied by Q.
    NRU     -   number of rows in matrix U.
    C       -   matrix to be multiplied by Q'.
                Array whose indexes range within [0..N-1, 0..NCC-1].
                The matrix can be bigger, in that case only the  submatrix
                [0..N-1, 0..NCC-1] will be multiplied by Q'.
    NCC     -   number of columns in matrix C.
    VT      -   matrix to be multiplied by P^T.
                Array whose indexes range within [0..N-1, 0..NCVT-1].
                The matrix can be bigger, in that case only the  submatrix
                [0..N-1, 0..NCVT-1] will be multiplied by P^T.
    NCVT    -   number of columns in matrix VT.

Output parameters:
    D       -   singular values of matrix B in descending order.
    U       -   if NRU>0, contains matrix U*Q.
    VT      -   if NCVT>0, contains matrix (P^T)*VT.
    C       -   if NCC>0, contains matrix Q'*C.

Result:
    True, if the algorithm has converged.
    False, if the algorithm hasn't converged (rare case).

Additional information:
    The type of convergence is controlled by the internal  parameter  TOL.
    If the parameter is greater than 0, the singular values will have
    relative accuracy TOL. If TOL<0, the singular values will have
    absolute accuracy ABS(TOL)*norm(B).
    By default, |TOL| falls within the range of 10*Epsilon and 100*Epsilon,
    where Epsilon is the machine precision. It is not  recommended  to  use
    TOL less than 10*Epsilon since this will  considerably  slow  down  the
    algorithm and may not lead to error decreasing.
History:
    * 31 March, 2007.
        changed MAXITR from 6 to 12.

  -- LAPACK routine (version 3.0) --
     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
     Courant Institute, Argonne National Lab, and Rice University
     October 31, 1999.
*************************************************************************/
ae_bool rmatrixbdsvd(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isfractionalaccuracyrequired,
     /* Real    */ ae_matrix* u,
     ae_int_t nru,
     /* Real    */ ae_matrix* c,
     ae_int_t ncc,
     /* Real    */ ae_matrix* vt,
     ae_int_t ncvt,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _e;
    ae_vector d1;
    ae_vector e1;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_e, e, _state, ae_true);
    e = &_e;
    ae_vector_init(&d1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e1, 0, DT_REAL, _state, ae_true);

    ae_vector_set_length(&d1, n+1, _state);
    ae_v_move(&d1.ptr.p_double[1], 1, &d->ptr.p_double[0], 1, ae_v_len(1,n));
    if( n>1 )
    {
        ae_vector_set_length(&e1, n-1+1, _state);
        ae_v_move(&e1.ptr.p_double[1], 1, &e->ptr.p_double[0], 1, ae_v_len(1,n-1));
    }
    result = bdsvd_bidiagonalsvddecompositioninternal(&d1, &e1, n, isupper, isfractionalaccuracyrequired, u, 0, nru, c, 0, ncc, vt, 0, ncvt, _state);
    ae_v_move(&d->ptr.p_double[0], 1, &d1.ptr.p_double[1], 1, ae_v_len(0,n-1));
    ae_frame_leave(_state);
    return result;
}


ae_bool bidiagonalsvddecomposition(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isfractionalaccuracyrequired,
     /* Real    */ ae_matrix* u,
     ae_int_t nru,
     /* Real    */ ae_matrix* c,
     ae_int_t ncc,
     /* Real    */ ae_matrix* vt,
     ae_int_t ncvt,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _e;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_e, e, _state, ae_true);
    e = &_e;

    result = bdsvd_bidiagonalsvddecompositioninternal(d, e, n, isupper, isfractionalaccuracyrequired, u, 1, nru, c, 1, ncc, vt, 1, ncvt, _state);
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Internal working subroutine for bidiagonal decomposition
*************************************************************************/
static ae_bool bdsvd_bidiagonalsvddecompositioninternal(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isfractionalaccuracyrequired,
     /* Real    */ ae_matrix* u,
     ae_int_t ustart,
     ae_int_t nru,
     /* Real    */ ae_matrix* c,
     ae_int_t cstart,
     ae_int_t ncc,
     /* Real    */ ae_matrix* vt,
     ae_int_t vstart,
     ae_int_t ncvt,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector _e;
    ae_int_t i;
    ae_int_t idir;
    ae_int_t isub;
    ae_int_t iter;
    ae_int_t j;
    ae_int_t ll;
    ae_int_t lll;
    ae_int_t m;
    ae_int_t maxit;
    ae_int_t oldll;
    ae_int_t oldm;
    double abse;
    double abss;
    double cosl;
    double cosr;
    double cs;
    double eps;
    double f;
    double g;
    double h;
    double mu;
    double oldcs;
    double oldsn;
    double r;
    double shift;
    double sigmn;
    double sigmx;
    double sinl;
    double sinr;
    double sll;
    double smax;
    double smin;
    double sminl;
    double sminlo;
    double sminoa;
    double sn;
    double thresh;
    double tol;
    double tolmul;
    double unfl;
    ae_vector work0;
    ae_vector work1;
    ae_vector work2;
    ae_vector work3;
    ae_int_t maxitr;
    ae_bool matrixsplitflag;
    ae_bool iterflag;
    ae_vector utemp;
    ae_vector vttemp;
    ae_vector ctemp;
    ae_vector etemp;
    ae_bool rightside;
    ae_bool fwddir;
    double tmp;
    ae_int_t mm1;
    ae_int_t mm0;
    ae_bool bchangedir;
    ae_int_t uend;
    ae_int_t cend;
    ae_int_t vend;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init_copy(&_e, e, _state, ae_true);
    e = &_e;
    ae_vector_init(&work0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work2, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work3, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&utemp, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&vttemp, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&ctemp, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&etemp, 0, DT_REAL, _state, ae_true);

    result = ae_true;
    if( n==0 )
    {
        ae_frame_leave(_state);
        return result;
    }
    if( n==1 )
    {
        if( ae_fp_less(d->ptr.p_double[1],0) )
        {
            d->ptr.p_double[1] = -d->ptr.p_double[1];
            if( ncvt>0 )
            {
                ae_v_muld(&vt->ptr.pp_double[vstart][vstart], 1, ae_v_len(vstart,vstart+ncvt-1), -1);
            }
        }
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * these initializers are not really necessary,
     * but without them compiler complains about uninitialized locals
     */
    ll = 0;
    oldsn = 0;
    
    /*
     * init
     */
    ae_vector_set_length(&work0, n-1+1, _state);
    ae_vector_set_length(&work1, n-1+1, _state);
    ae_vector_set_length(&work2, n-1+1, _state);
    ae_vector_set_length(&work3, n-1+1, _state);
    uend = ustart+ae_maxint(nru-1, 0, _state);
    vend = vstart+ae_maxint(ncvt-1, 0, _state);
    cend = cstart+ae_maxint(ncc-1, 0, _state);
    ae_vector_set_length(&utemp, uend+1, _state);
    ae_vector_set_length(&vttemp, vend+1, _state);
    ae_vector_set_length(&ctemp, cend+1, _state);
    maxitr = 12;
    rightside = ae_true;
    fwddir = ae_true;
    
    /*
     * resize E from N-1 to N
     */
    ae_vector_set_length(&etemp, n+1, _state);
    for(i=1; i<=n-1; i++)
    {
        etemp.ptr.p_double[i] = e->ptr.p_double[i];
    }
    ae_vector_set_length(e, n+1, _state);
    for(i=1; i<=n-1; i++)
    {
        e->ptr.p_double[i] = etemp.ptr.p_double[i];
    }
    e->ptr.p_double[n] = 0;
    idir = 0;
    
    /*
     * Get machine constants
     */
    eps = ae_machineepsilon;
    unfl = ae_minrealnumber;
    
    /*
     * If matrix lower bidiagonal, rotate to be upper bidiagonal
     * by applying Givens rotations on the left
     */
    if( !isupper )
    {
        for(i=1; i<=n-1; i++)
        {
            generaterotation(d->ptr.p_double[i], e->ptr.p_double[i], &cs, &sn, &r, _state);
            d->ptr.p_double[i] = r;
            e->ptr.p_double[i] = sn*d->ptr.p_double[i+1];
            d->ptr.p_double[i+1] = cs*d->ptr.p_double[i+1];
            work0.ptr.p_double[i] = cs;
            work1.ptr.p_double[i] = sn;
        }
        
        /*
         * Update singular vectors if desired
         */
        if( nru>0 )
        {
            applyrotationsfromtheright(fwddir, ustart, uend, 1+ustart-1, n+ustart-1, &work0, &work1, u, &utemp, _state);
        }
        if( ncc>0 )
        {
            applyrotationsfromtheleft(fwddir, 1+cstart-1, n+cstart-1, cstart, cend, &work0, &work1, c, &ctemp, _state);
        }
    }
    
    /*
     * Compute singular values to relative accuracy TOL
     * (By setting TOL to be negative, algorithm will compute
     * singular values to absolute accuracy ABS(TOL)*norm(input matrix))
     */
    tolmul = ae_maxreal(10, ae_minreal(100, ae_pow(eps, -0.125, _state), _state), _state);
    tol = tolmul*eps;
    if( !isfractionalaccuracyrequired )
    {
        tol = -tol;
    }
    
    /*
     * Compute approximate maximum, minimum singular values
     */
    smax = 0;
    for(i=1; i<=n; i++)
    {
        smax = ae_maxreal(smax, ae_fabs(d->ptr.p_double[i], _state), _state);
    }
    for(i=1; i<=n-1; i++)
    {
        smax = ae_maxreal(smax, ae_fabs(e->ptr.p_double[i], _state), _state);
    }
    sminl = 0;
    if( ae_fp_greater_eq(tol,0) )
    {
        
        /*
         * Relative accuracy desired
         */
        sminoa = ae_fabs(d->ptr.p_double[1], _state);
        if( ae_fp_neq(sminoa,0) )
        {
            mu = sminoa;
            for(i=2; i<=n; i++)
            {
                mu = ae_fabs(d->ptr.p_double[i], _state)*(mu/(mu+ae_fabs(e->ptr.p_double[i-1], _state)));
                sminoa = ae_minreal(sminoa, mu, _state);
                if( ae_fp_eq(sminoa,0) )
                {
                    break;
                }
            }
        }
        sminoa = sminoa/ae_sqrt(n, _state);
        thresh = ae_maxreal(tol*sminoa, maxitr*n*n*unfl, _state);
    }
    else
    {
        
        /*
         * Absolute accuracy desired
         */
        thresh = ae_maxreal(ae_fabs(tol, _state)*smax, maxitr*n*n*unfl, _state);
    }
    
    /*
     * Prepare for main iteration loop for the singular values
     * (MAXIT is the maximum number of passes through the inner
     * loop permitted before nonconvergence signalled.)
     */
    maxit = maxitr*n*n;
    iter = 0;
    oldll = -1;
    oldm = -1;
    
    /*
     * M points to last element of unconverged part of matrix
     */
    m = n;
    
    /*
     * Begin main iteration loop
     */
    for(;;)
    {
        
        /*
         * Check for convergence or exceeding iteration count
         */
        if( m<=1 )
        {
            break;
        }
        if( iter>maxit )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Find diagonal block of matrix to work on
         */
        if( ae_fp_less(tol,0)&&ae_fp_less_eq(ae_fabs(d->ptr.p_double[m], _state),thresh) )
        {
            d->ptr.p_double[m] = 0;
        }
        smax = ae_fabs(d->ptr.p_double[m], _state);
        smin = smax;
        matrixsplitflag = ae_false;
        for(lll=1; lll<=m-1; lll++)
        {
            ll = m-lll;
            abss = ae_fabs(d->ptr.p_double[ll], _state);
            abse = ae_fabs(e->ptr.p_double[ll], _state);
            if( ae_fp_less(tol,0)&&ae_fp_less_eq(abss,thresh) )
            {
                d->ptr.p_double[ll] = 0;
            }
            if( ae_fp_less_eq(abse,thresh) )
            {
                matrixsplitflag = ae_true;
                break;
            }
            smin = ae_minreal(smin, abss, _state);
            smax = ae_maxreal(smax, ae_maxreal(abss, abse, _state), _state);
        }
        if( !matrixsplitflag )
        {
            ll = 0;
        }
        else
        {
            
            /*
             * Matrix splits since E(LL) = 0
             */
            e->ptr.p_double[ll] = 0;
            if( ll==m-1 )
            {
                
                /*
                 * Convergence of bottom singular value, return to top of loop
                 */
                m = m-1;
                continue;
            }
        }
        ll = ll+1;
        
        /*
         * E(LL) through E(M-1) are nonzero, E(LL-1) is zero
         */
        if( ll==m-1 )
        {
            
            /*
             * 2 by 2 block, handle separately
             */
            bdsvd_svdv2x2(d->ptr.p_double[m-1], e->ptr.p_double[m-1], d->ptr.p_double[m], &sigmn, &sigmx, &sinr, &cosr, &sinl, &cosl, _state);
            d->ptr.p_double[m-1] = sigmx;
            e->ptr.p_double[m-1] = 0;
            d->ptr.p_double[m] = sigmn;
            
            /*
             * Compute singular vectors, if desired
             */
            if( ncvt>0 )
            {
                mm0 = m+(vstart-1);
                mm1 = m-1+(vstart-1);
                ae_v_moved(&vttemp.ptr.p_double[vstart], 1, &vt->ptr.pp_double[mm1][vstart], 1, ae_v_len(vstart,vend), cosr);
                ae_v_addd(&vttemp.ptr.p_double[vstart], 1, &vt->ptr.pp_double[mm0][vstart], 1, ae_v_len(vstart,vend), sinr);
                ae_v_muld(&vt->ptr.pp_double[mm0][vstart], 1, ae_v_len(vstart,vend), cosr);
                ae_v_subd(&vt->ptr.pp_double[mm0][vstart], 1, &vt->ptr.pp_double[mm1][vstart], 1, ae_v_len(vstart,vend), sinr);
                ae_v_move(&vt->ptr.pp_double[mm1][vstart], 1, &vttemp.ptr.p_double[vstart], 1, ae_v_len(vstart,vend));
            }
            if( nru>0 )
            {
                mm0 = m+ustart-1;
                mm1 = m-1+ustart-1;
                ae_v_moved(&utemp.ptr.p_double[ustart], 1, &u->ptr.pp_double[ustart][mm1], u->stride, ae_v_len(ustart,uend), cosl);
                ae_v_addd(&utemp.ptr.p_double[ustart], 1, &u->ptr.pp_double[ustart][mm0], u->stride, ae_v_len(ustart,uend), sinl);
                ae_v_muld(&u->ptr.pp_double[ustart][mm0], u->stride, ae_v_len(ustart,uend), cosl);
                ae_v_subd(&u->ptr.pp_double[ustart][mm0], u->stride, &u->ptr.pp_double[ustart][mm1], u->stride, ae_v_len(ustart,uend), sinl);
                ae_v_move(&u->ptr.pp_double[ustart][mm1], u->stride, &utemp.ptr.p_double[ustart], 1, ae_v_len(ustart,uend));
            }
            if( ncc>0 )
            {
                mm0 = m+cstart-1;
                mm1 = m-1+cstart-1;
                ae_v_moved(&ctemp.ptr.p_double[cstart], 1, &c->ptr.pp_double[mm1][cstart], 1, ae_v_len(cstart,cend), cosl);
                ae_v_addd(&ctemp.ptr.p_double[cstart], 1, &c->ptr.pp_double[mm0][cstart], 1, ae_v_len(cstart,cend), sinl);
                ae_v_muld(&c->ptr.pp_double[mm0][cstart], 1, ae_v_len(cstart,cend), cosl);
                ae_v_subd(&c->ptr.pp_double[mm0][cstart], 1, &c->ptr.pp_double[mm1][cstart], 1, ae_v_len(cstart,cend), sinl);
                ae_v_move(&c->ptr.pp_double[mm1][cstart], 1, &ctemp.ptr.p_double[cstart], 1, ae_v_len(cstart,cend));
            }
            m = m-2;
            continue;
        }
        
        /*
         * If working on new submatrix, choose shift direction
         * (from larger end diagonal element towards smaller)
         *
         * Previously was
         *     "if (LL>OLDM) or (M<OLDLL) then"
         * fixed thanks to Michael Rolle < m@rolle.name >
         * Very strange that LAPACK still contains it.
         */
        bchangedir = ae_false;
        if( idir==1&&ae_fp_less(ae_fabs(d->ptr.p_double[ll], _state),1.0E-3*ae_fabs(d->ptr.p_double[m], _state)) )
        {
            bchangedir = ae_true;
        }
        if( idir==2&&ae_fp_less(ae_fabs(d->ptr.p_double[m], _state),1.0E-3*ae_fabs(d->ptr.p_double[ll], _state)) )
        {
            bchangedir = ae_true;
        }
        if( (ll!=oldll||m!=oldm)||bchangedir )
        {
            if( ae_fp_greater_eq(ae_fabs(d->ptr.p_double[ll], _state),ae_fabs(d->ptr.p_double[m], _state)) )
            {
                
                /*
                 * Chase bulge from top (big end) to bottom (small end)
                 */
                idir = 1;
            }
            else
            {
                
                /*
                 * Chase bulge from bottom (big end) to top (small end)
                 */
                idir = 2;
            }
        }
        
        /*
         * Apply convergence tests
         */
        if( idir==1 )
        {
            
            /*
             * Run convergence test in forward direction
             * First apply standard test to bottom of matrix
             */
            if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[m-1], _state),ae_fabs(tol, _state)*ae_fabs(d->ptr.p_double[m], _state))||(ae_fp_less(tol,0)&&ae_fp_less_eq(ae_fabs(e->ptr.p_double[m-1], _state),thresh)) )
            {
                e->ptr.p_double[m-1] = 0;
                continue;
            }
            if( ae_fp_greater_eq(tol,0) )
            {
                
                /*
                 * If relative accuracy desired,
                 * apply convergence criterion forward
                 */
                mu = ae_fabs(d->ptr.p_double[ll], _state);
                sminl = mu;
                iterflag = ae_false;
                for(lll=ll; lll<=m-1; lll++)
                {
                    if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[lll], _state),tol*mu) )
                    {
                        e->ptr.p_double[lll] = 0;
                        iterflag = ae_true;
                        break;
                    }
                    sminlo = sminl;
                    mu = ae_fabs(d->ptr.p_double[lll+1], _state)*(mu/(mu+ae_fabs(e->ptr.p_double[lll], _state)));
                    sminl = ae_minreal(sminl, mu, _state);
                }
                if( iterflag )
                {
                    continue;
                }
            }
        }
        else
        {
            
            /*
             * Run convergence test in backward direction
             * First apply standard test to top of matrix
             */
            if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[ll], _state),ae_fabs(tol, _state)*ae_fabs(d->ptr.p_double[ll], _state))||(ae_fp_less(tol,0)&&ae_fp_less_eq(ae_fabs(e->ptr.p_double[ll], _state),thresh)) )
            {
                e->ptr.p_double[ll] = 0;
                continue;
            }
            if( ae_fp_greater_eq(tol,0) )
            {
                
                /*
                 * If relative accuracy desired,
                 * apply convergence criterion backward
                 */
                mu = ae_fabs(d->ptr.p_double[m], _state);
                sminl = mu;
                iterflag = ae_false;
                for(lll=m-1; lll>=ll; lll--)
                {
                    if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[lll], _state),tol*mu) )
                    {
                        e->ptr.p_double[lll] = 0;
                        iterflag = ae_true;
                        break;
                    }
                    sminlo = sminl;
                    mu = ae_fabs(d->ptr.p_double[lll], _state)*(mu/(mu+ae_fabs(e->ptr.p_double[lll], _state)));
                    sminl = ae_minreal(sminl, mu, _state);
                }
                if( iterflag )
                {
                    continue;
                }
            }
        }
        oldll = ll;
        oldm = m;
        
        /*
         * Compute shift.  First, test if shifting would ruin relative
         * accuracy, and if so set the shift to zero.
         */
        if( ae_fp_greater_eq(tol,0)&&ae_fp_less_eq(n*tol*(sminl/smax),ae_maxreal(eps, 0.01*tol, _state)) )
        {
            
            /*
             * Use a zero shift to avoid loss of relative accuracy
             */
            shift = 0;
        }
        else
        {
            
            /*
             * Compute the shift from 2-by-2 block at end of matrix
             */
            if( idir==1 )
            {
                sll = ae_fabs(d->ptr.p_double[ll], _state);
                bdsvd_svd2x2(d->ptr.p_double[m-1], e->ptr.p_double[m-1], d->ptr.p_double[m], &shift, &r, _state);
            }
            else
            {
                sll = ae_fabs(d->ptr.p_double[m], _state);
                bdsvd_svd2x2(d->ptr.p_double[ll], e->ptr.p_double[ll], d->ptr.p_double[ll+1], &shift, &r, _state);
            }
            
            /*
             * Test if shift negligible, and if so set to zero
             */
            if( ae_fp_greater(sll,0) )
            {
                if( ae_fp_less(ae_sqr(shift/sll, _state),eps) )
                {
                    shift = 0;
                }
            }
        }
        
        /*
         * Increment iteration count
         */
        iter = iter+m-ll;
        
        /*
         * If SHIFT = 0, do simplified QR iteration
         */
        if( ae_fp_eq(shift,0) )
        {
            if( idir==1 )
            {
                
                /*
                 * Chase bulge from top to bottom
                 * Save cosines and sines for later singular vector updates
                 */
                cs = 1;
                oldcs = 1;
                for(i=ll; i<=m-1; i++)
                {
                    generaterotation(d->ptr.p_double[i]*cs, e->ptr.p_double[i], &cs, &sn, &r, _state);
                    if( i>ll )
                    {
                        e->ptr.p_double[i-1] = oldsn*r;
                    }
                    generaterotation(oldcs*r, d->ptr.p_double[i+1]*sn, &oldcs, &oldsn, &tmp, _state);
                    d->ptr.p_double[i] = tmp;
                    work0.ptr.p_double[i-ll+1] = cs;
                    work1.ptr.p_double[i-ll+1] = sn;
                    work2.ptr.p_double[i-ll+1] = oldcs;
                    work3.ptr.p_double[i-ll+1] = oldsn;
                }
                h = d->ptr.p_double[m]*cs;
                d->ptr.p_double[m] = h*oldcs;
                e->ptr.p_double[m-1] = h*oldsn;
                
                /*
                 * Update singular vectors
                 */
                if( ncvt>0 )
                {
                    applyrotationsfromtheleft(fwddir, ll+vstart-1, m+vstart-1, vstart, vend, &work0, &work1, vt, &vttemp, _state);
                }
                if( nru>0 )
                {
                    applyrotationsfromtheright(fwddir, ustart, uend, ll+ustart-1, m+ustart-1, &work2, &work3, u, &utemp, _state);
                }
                if( ncc>0 )
                {
                    applyrotationsfromtheleft(fwddir, ll+cstart-1, m+cstart-1, cstart, cend, &work2, &work3, c, &ctemp, _state);
                }
                
                /*
                 * Test convergence
                 */
                if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[m-1], _state),thresh) )
                {
                    e->ptr.p_double[m-1] = 0;
                }
            }
            else
            {
                
                /*
                 * Chase bulge from bottom to top
                 * Save cosines and sines for later singular vector updates
                 */
                cs = 1;
                oldcs = 1;
                for(i=m; i>=ll+1; i--)
                {
                    generaterotation(d->ptr.p_double[i]*cs, e->ptr.p_double[i-1], &cs, &sn, &r, _state);
                    if( i<m )
                    {
                        e->ptr.p_double[i] = oldsn*r;
                    }
                    generaterotation(oldcs*r, d->ptr.p_double[i-1]*sn, &oldcs, &oldsn, &tmp, _state);
                    d->ptr.p_double[i] = tmp;
                    work0.ptr.p_double[i-ll] = cs;
                    work1.ptr.p_double[i-ll] = -sn;
                    work2.ptr.p_double[i-ll] = oldcs;
                    work3.ptr.p_double[i-ll] = -oldsn;
                }
                h = d->ptr.p_double[ll]*cs;
                d->ptr.p_double[ll] = h*oldcs;
                e->ptr.p_double[ll] = h*oldsn;
                
                /*
                 * Update singular vectors
                 */
                if( ncvt>0 )
                {
                    applyrotationsfromtheleft(!fwddir, ll+vstart-1, m+vstart-1, vstart, vend, &work2, &work3, vt, &vttemp, _state);
                }
                if( nru>0 )
                {
                    applyrotationsfromtheright(!fwddir, ustart, uend, ll+ustart-1, m+ustart-1, &work0, &work1, u, &utemp, _state);
                }
                if( ncc>0 )
                {
                    applyrotationsfromtheleft(!fwddir, ll+cstart-1, m+cstart-1, cstart, cend, &work0, &work1, c, &ctemp, _state);
                }
                
                /*
                 * Test convergence
                 */
                if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[ll], _state),thresh) )
                {
                    e->ptr.p_double[ll] = 0;
                }
            }
        }
        else
        {
            
            /*
             * Use nonzero shift
             */
            if( idir==1 )
            {
                
                /*
                 * Chase bulge from top to bottom
                 * Save cosines and sines for later singular vector updates
                 */
                f = (ae_fabs(d->ptr.p_double[ll], _state)-shift)*(bdsvd_extsignbdsqr(1, d->ptr.p_double[ll], _state)+shift/d->ptr.p_double[ll]);
                g = e->ptr.p_double[ll];
                for(i=ll; i<=m-1; i++)
                {
                    generaterotation(f, g, &cosr, &sinr, &r, _state);
                    if( i>ll )
                    {
                        e->ptr.p_double[i-1] = r;
                    }
                    f = cosr*d->ptr.p_double[i]+sinr*e->ptr.p_double[i];
                    e->ptr.p_double[i] = cosr*e->ptr.p_double[i]-sinr*d->ptr.p_double[i];
                    g = sinr*d->ptr.p_double[i+1];
                    d->ptr.p_double[i+1] = cosr*d->ptr.p_double[i+1];
                    generaterotation(f, g, &cosl, &sinl, &r, _state);
                    d->ptr.p_double[i] = r;
                    f = cosl*e->ptr.p_double[i]+sinl*d->ptr.p_double[i+1];
                    d->ptr.p_double[i+1] = cosl*d->ptr.p_double[i+1]-sinl*e->ptr.p_double[i];
                    if( i<m-1 )
                    {
                        g = sinl*e->ptr.p_double[i+1];
                        e->ptr.p_double[i+1] = cosl*e->ptr.p_double[i+1];
                    }
                    work0.ptr.p_double[i-ll+1] = cosr;
                    work1.ptr.p_double[i-ll+1] = sinr;
                    work2.ptr.p_double[i-ll+1] = cosl;
                    work3.ptr.p_double[i-ll+1] = sinl;
                }
                e->ptr.p_double[m-1] = f;
                
                /*
                 * Update singular vectors
                 */
                if( ncvt>0 )
                {
                    applyrotationsfromtheleft(fwddir, ll+vstart-1, m+vstart-1, vstart, vend, &work0, &work1, vt, &vttemp, _state);
                }
                if( nru>0 )
                {
                    applyrotationsfromtheright(fwddir, ustart, uend, ll+ustart-1, m+ustart-1, &work2, &work3, u, &utemp, _state);
                }
                if( ncc>0 )
                {
                    applyrotationsfromtheleft(fwddir, ll+cstart-1, m+cstart-1, cstart, cend, &work2, &work3, c, &ctemp, _state);
                }
                
                /*
                 * Test convergence
                 */
                if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[m-1], _state),thresh) )
                {
                    e->ptr.p_double[m-1] = 0;
                }
            }
            else
            {
                
                /*
                 * Chase bulge from bottom to top
                 * Save cosines and sines for later singular vector updates
                 */
                f = (ae_fabs(d->ptr.p_double[m], _state)-shift)*(bdsvd_extsignbdsqr(1, d->ptr.p_double[m], _state)+shift/d->ptr.p_double[m]);
                g = e->ptr.p_double[m-1];
                for(i=m; i>=ll+1; i--)
                {
                    generaterotation(f, g, &cosr, &sinr, &r, _state);
                    if( i<m )
                    {
                        e->ptr.p_double[i] = r;
                    }
                    f = cosr*d->ptr.p_double[i]+sinr*e->ptr.p_double[i-1];
                    e->ptr.p_double[i-1] = cosr*e->ptr.p_double[i-1]-sinr*d->ptr.p_double[i];
                    g = sinr*d->ptr.p_double[i-1];
                    d->ptr.p_double[i-1] = cosr*d->ptr.p_double[i-1];
                    generaterotation(f, g, &cosl, &sinl, &r, _state);
                    d->ptr.p_double[i] = r;
                    f = cosl*e->ptr.p_double[i-1]+sinl*d->ptr.p_double[i-1];
                    d->ptr.p_double[i-1] = cosl*d->ptr.p_double[i-1]-sinl*e->ptr.p_double[i-1];
                    if( i>ll+1 )
                    {
                        g = sinl*e->ptr.p_double[i-2];
                        e->ptr.p_double[i-2] = cosl*e->ptr.p_double[i-2];
                    }
                    work0.ptr.p_double[i-ll] = cosr;
                    work1.ptr.p_double[i-ll] = -sinr;
                    work2.ptr.p_double[i-ll] = cosl;
                    work3.ptr.p_double[i-ll] = -sinl;
                }
                e->ptr.p_double[ll] = f;
                
                /*
                 * Test convergence
                 */
                if( ae_fp_less_eq(ae_fabs(e->ptr.p_double[ll], _state),thresh) )
                {
                    e->ptr.p_double[ll] = 0;
                }
                
                /*
                 * Update singular vectors if desired
                 */
                if( ncvt>0 )
                {
                    applyrotationsfromtheleft(!fwddir, ll+vstart-1, m+vstart-1, vstart, vend, &work2, &work3, vt, &vttemp, _state);
                }
                if( nru>0 )
                {
                    applyrotationsfromtheright(!fwddir, ustart, uend, ll+ustart-1, m+ustart-1, &work0, &work1, u, &utemp, _state);
                }
                if( ncc>0 )
                {
                    applyrotationsfromtheleft(!fwddir, ll+cstart-1, m+cstart-1, cstart, cend, &work0, &work1, c, &ctemp, _state);
                }
            }
        }
        
        /*
         * QR iteration finished, go back and check convergence
         */
        continue;
    }
    
    /*
     * All singular values converged, so make them positive
     */
    for(i=1; i<=n; i++)
    {
        if( ae_fp_less(d->ptr.p_double[i],0) )
        {
            d->ptr.p_double[i] = -d->ptr.p_double[i];
            
            /*
             * Change sign of singular vectors, if desired
             */
            if( ncvt>0 )
            {
                ae_v_muld(&vt->ptr.pp_double[i+vstart-1][vstart], 1, ae_v_len(vstart,vend), -1);
            }
        }
    }
    
    /*
     * Sort the singular values into decreasing order (insertion sort on
     * singular values, but only one transposition per singular vector)
     */
    for(i=1; i<=n-1; i++)
    {
        
        /*
         * Scan for smallest D(I)
         */
        isub = 1;
        smin = d->ptr.p_double[1];
        for(j=2; j<=n+1-i; j++)
        {
            if( ae_fp_less_eq(d->ptr.p_double[j],smin) )
            {
                isub = j;
                smin = d->ptr.p_double[j];
            }
        }
        if( isub!=n+1-i )
        {
            
            /*
             * Swap singular values and vectors
             */
            d->ptr.p_double[isub] = d->ptr.p_double[n+1-i];
            d->ptr.p_double[n+1-i] = smin;
            if( ncvt>0 )
            {
                j = n+1-i;
                ae_v_move(&vttemp.ptr.p_double[vstart], 1, &vt->ptr.pp_double[isub+vstart-1][vstart], 1, ae_v_len(vstart,vend));
                ae_v_move(&vt->ptr.pp_double[isub+vstart-1][vstart], 1, &vt->ptr.pp_double[j+vstart-1][vstart], 1, ae_v_len(vstart,vend));
                ae_v_move(&vt->ptr.pp_double[j+vstart-1][vstart], 1, &vttemp.ptr.p_double[vstart], 1, ae_v_len(vstart,vend));
            }
            if( nru>0 )
            {
                j = n+1-i;
                ae_v_move(&utemp.ptr.p_double[ustart], 1, &u->ptr.pp_double[ustart][isub+ustart-1], u->stride, ae_v_len(ustart,uend));
                ae_v_move(&u->ptr.pp_double[ustart][isub+ustart-1], u->stride, &u->ptr.pp_double[ustart][j+ustart-1], u->stride, ae_v_len(ustart,uend));
                ae_v_move(&u->ptr.pp_double[ustart][j+ustart-1], u->stride, &utemp.ptr.p_double[ustart], 1, ae_v_len(ustart,uend));
            }
            if( ncc>0 )
            {
                j = n+1-i;
                ae_v_move(&ctemp.ptr.p_double[cstart], 1, &c->ptr.pp_double[isub+cstart-1][cstart], 1, ae_v_len(cstart,cend));
                ae_v_move(&c->ptr.pp_double[isub+cstart-1][cstart], 1, &c->ptr.pp_double[j+cstart-1][cstart], 1, ae_v_len(cstart,cend));
                ae_v_move(&c->ptr.pp_double[j+cstart-1][cstart], 1, &ctemp.ptr.p_double[cstart], 1, ae_v_len(cstart,cend));
            }
        }
    }
    ae_frame_leave(_state);
    return result;
}


static double bdsvd_extsignbdsqr(double a, double b, ae_state *_state)
{
    double result;


    if( ae_fp_greater_eq(b,0) )
    {
        result = ae_fabs(a, _state);
    }
    else
    {
        result = -ae_fabs(a, _state);
    }
    return result;
}


static void bdsvd_svd2x2(double f,
     double g,
     double h,
     double* ssmin,
     double* ssmax,
     ae_state *_state)
{
    double aas;
    double at;
    double au;
    double c;
    double fa;
    double fhmn;
    double fhmx;
    double ga;
    double ha;

    *ssmin = 0;
    *ssmax = 0;

    fa = ae_fabs(f, _state);
    ga = ae_fabs(g, _state);
    ha = ae_fabs(h, _state);
    fhmn = ae_minreal(fa, ha, _state);
    fhmx = ae_maxreal(fa, ha, _state);
    if( ae_fp_eq(fhmn,0) )
    {
        *ssmin = 0;
        if( ae_fp_eq(fhmx,0) )
        {
            *ssmax = ga;
        }
        else
        {
            *ssmax = ae_maxreal(fhmx, ga, _state)*ae_sqrt(1+ae_sqr(ae_minreal(fhmx, ga, _state)/ae_maxreal(fhmx, ga, _state), _state), _state);
        }
    }
    else
    {
        if( ae_fp_less(ga,fhmx) )
        {
            aas = 1+fhmn/fhmx;
            at = (fhmx-fhmn)/fhmx;
            au = ae_sqr(ga/fhmx, _state);
            c = 2/(ae_sqrt(aas*aas+au, _state)+ae_sqrt(at*at+au, _state));
            *ssmin = fhmn*c;
            *ssmax = fhmx/c;
        }
        else
        {
            au = fhmx/ga;
            if( ae_fp_eq(au,0) )
            {
                
                /*
                 * Avoid possible harmful underflow if exponent range
                 * asymmetric (true SSMIN may not underflow even if
                 * AU underflows)
                 */
                *ssmin = fhmn*fhmx/ga;
                *ssmax = ga;
            }
            else
            {
                aas = 1+fhmn/fhmx;
                at = (fhmx-fhmn)/fhmx;
                c = 1/(ae_sqrt(1+ae_sqr(aas*au, _state), _state)+ae_sqrt(1+ae_sqr(at*au, _state), _state));
                *ssmin = fhmn*c*au;
                *ssmin = *ssmin+(*ssmin);
                *ssmax = ga/(c+c);
            }
        }
    }
}


static void bdsvd_svdv2x2(double f,
     double g,
     double h,
     double* ssmin,
     double* ssmax,
     double* snr,
     double* csr,
     double* snl,
     double* csl,
     ae_state *_state)
{
    ae_bool gasmal;
    ae_bool swp;
    ae_int_t pmax;
    double a;
    double clt;
    double crt;
    double d;
    double fa;
    double ft;
    double ga;
    double gt;
    double ha;
    double ht;
    double l;
    double m;
    double mm;
    double r;
    double s;
    double slt;
    double srt;
    double t;
    double temp;
    double tsign;
    double tt;
    double v;

    *ssmin = 0;
    *ssmax = 0;
    *snr = 0;
    *csr = 0;
    *snl = 0;
    *csl = 0;

    ft = f;
    fa = ae_fabs(ft, _state);
    ht = h;
    ha = ae_fabs(h, _state);
    
    /*
     * these initializers are not really necessary,
     * but without them compiler complains about uninitialized locals
     */
    clt = 0;
    crt = 0;
    slt = 0;
    srt = 0;
    tsign = 0;
    
    /*
     * PMAX points to the maximum absolute element of matrix
     *  PMAX = 1 if F largest in absolute values
     *  PMAX = 2 if G largest in absolute values
     *  PMAX = 3 if H largest in absolute values
     */
    pmax = 1;
    swp = ae_fp_greater(ha,fa);
    if( swp )
    {
        
        /*
         * Now FA .ge. HA
         */
        pmax = 3;
        temp = ft;
        ft = ht;
        ht = temp;
        temp = fa;
        fa = ha;
        ha = temp;
    }
    gt = g;
    ga = ae_fabs(gt, _state);
    if( ae_fp_eq(ga,0) )
    {
        
        /*
         * Diagonal matrix
         */
        *ssmin = ha;
        *ssmax = fa;
        clt = 1;
        crt = 1;
        slt = 0;
        srt = 0;
    }
    else
    {
        gasmal = ae_true;
        if( ae_fp_greater(ga,fa) )
        {
            pmax = 2;
            if( ae_fp_less(fa/ga,ae_machineepsilon) )
            {
                
                /*
                 * Case of very large GA
                 */
                gasmal = ae_false;
                *ssmax = ga;
                if( ae_fp_greater(ha,1) )
                {
                    v = ga/ha;
                    *ssmin = fa/v;
                }
                else
                {
                    v = fa/ga;
                    *ssmin = v*ha;
                }
                clt = 1;
                slt = ht/gt;
                srt = 1;
                crt = ft/gt;
            }
        }
        if( gasmal )
        {
            
            /*
             * Normal case
             */
            d = fa-ha;
            if( ae_fp_eq(d,fa) )
            {
                l = 1;
            }
            else
            {
                l = d/fa;
            }
            m = gt/ft;
            t = 2-l;
            mm = m*m;
            tt = t*t;
            s = ae_sqrt(tt+mm, _state);
            if( ae_fp_eq(l,0) )
            {
                r = ae_fabs(m, _state);
            }
            else
            {
                r = ae_sqrt(l*l+mm, _state);
            }
            a = 0.5*(s+r);
            *ssmin = ha/a;
            *ssmax = fa*a;
            if( ae_fp_eq(mm,0) )
            {
                
                /*
                 * Note that M is very tiny
                 */
                if( ae_fp_eq(l,0) )
                {
                    t = bdsvd_extsignbdsqr(2, ft, _state)*bdsvd_extsignbdsqr(1, gt, _state);
                }
                else
                {
                    t = gt/bdsvd_extsignbdsqr(d, ft, _state)+m/t;
                }
            }
            else
            {
                t = (m/(s+t)+m/(r+l))*(1+a);
            }
            l = ae_sqrt(t*t+4, _state);
            crt = 2/l;
            srt = t/l;
            clt = (crt+srt*m)/a;
            v = ht/ft;
            slt = v*srt/a;
        }
    }
    if( swp )
    {
        *csl = srt;
        *snl = crt;
        *csr = slt;
        *snr = clt;
    }
    else
    {
        *csl = clt;
        *snl = slt;
        *csr = crt;
        *snr = srt;
    }
    
    /*
     * Correct signs of SSMAX and SSMIN
     */
    if( pmax==1 )
    {
        tsign = bdsvd_extsignbdsqr(1, *csr, _state)*bdsvd_extsignbdsqr(1, *csl, _state)*bdsvd_extsignbdsqr(1, f, _state);
    }
    if( pmax==2 )
    {
        tsign = bdsvd_extsignbdsqr(1, *snr, _state)*bdsvd_extsignbdsqr(1, *csl, _state)*bdsvd_extsignbdsqr(1, g, _state);
    }
    if( pmax==3 )
    {
        tsign = bdsvd_extsignbdsqr(1, *snr, _state)*bdsvd_extsignbdsqr(1, *snl, _state)*bdsvd_extsignbdsqr(1, h, _state);
    }
    *ssmax = bdsvd_extsignbdsqr(*ssmax, tsign, _state);
    *ssmin = bdsvd_extsignbdsqr(*ssmin, tsign*bdsvd_extsignbdsqr(1, f, _state)*bdsvd_extsignbdsqr(1, h, _state), _state);
}




/*************************************************************************
Singular value decomposition of a rectangular matrix.

The algorithm calculates the singular value decomposition of a matrix of
size MxN: A = U * S * V^T

The algorithm finds the singular values and, optionally, matrices U and V^T.
The algorithm can find both first min(M,N) columns of matrix U and rows of
matrix V^T (singular vectors), and matrices U and V^T wholly (of sizes MxM
and NxN respectively).

Take into account that the subroutine does not return matrix V but V^T.

Input parameters:
    A           -   matrix to be decomposed.
                    Array whose indexes range within [0..M-1, 0..N-1].
    M           -   number of rows in matrix A.
    N           -   number of columns in matrix A.
    UNeeded     -   0, 1 or 2. See the description of the parameter U.
    VTNeeded    -   0, 1 or 2. See the description of the parameter VT.
    AdditionalMemory -
                    If the parameter:
                     * equals 0, the algorithm doesn�t use additional
                       memory (lower requirements, lower performance).
                     * equals 1, the algorithm uses additional
                       memory of size min(M,N)*min(M,N) of real numbers.
                       It often speeds up the algorithm.
                     * equals 2, the algorithm uses additional
                       memory of size M*min(M,N) of real numbers.
                       It allows to get a maximum performance.
                    The recommended value of the parameter is 2.

Output parameters:
    W           -   contains singular values in descending order.
    U           -   if UNeeded=0, U isn't changed, the left singular vectors
                    are not calculated.
                    if Uneeded=1, U contains left singular vectors (first
                    min(M,N) columns of matrix U). Array whose indexes range
                    within [0..M-1, 0..Min(M,N)-1].
                    if UNeeded=2, U contains matrix U wholly. Array whose
                    indexes range within [0..M-1, 0..M-1].
    VT          -   if VTNeeded=0, VT isn�t changed, the right singular vectors
                    are not calculated.
                    if VTNeeded=1, VT contains right singular vectors (first
                    min(M,N) rows of matrix V^T). Array whose indexes range
                    within [0..min(M,N)-1, 0..N-1].
                    if VTNeeded=2, VT contains matrix V^T wholly. Array whose
                    indexes range within [0..N-1, 0..N-1].

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
ae_bool rmatrixsvd(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_int_t uneeded,
     ae_int_t vtneeded,
     ae_int_t additionalmemory,
     /* Real    */ ae_vector* w,
     /* Real    */ ae_matrix* u,
     /* Real    */ ae_matrix* vt,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_vector tauq;
    ae_vector taup;
    ae_vector tau;
    ae_vector e;
    ae_vector work;
    ae_matrix t2;
    ae_bool isupper;
    ae_int_t minmn;
    ae_int_t ncu;
    ae_int_t nrvt;
    ae_int_t nru;
    ae_int_t ncvt;
    ae_int_t i;
    ae_int_t j;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(w);
    ae_matrix_clear(u);
    ae_matrix_clear(vt);
    ae_vector_init(&tauq, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&taup, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&tau, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&e, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&work, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&t2, 0, 0, DT_REAL, _state, ae_true);

    result = ae_true;
    if( m==0||n==0 )
    {
        ae_frame_leave(_state);
        return result;
    }
    ae_assert(uneeded>=0&&uneeded<=2, "SVDDecomposition: wrong parameters!", _state);
    ae_assert(vtneeded>=0&&vtneeded<=2, "SVDDecomposition: wrong parameters!", _state);
    ae_assert(additionalmemory>=0&&additionalmemory<=2, "SVDDecomposition: wrong parameters!", _state);
    
    /*
     * initialize
     */
    minmn = ae_minint(m, n, _state);
    ae_vector_set_length(w, minmn+1, _state);
    ncu = 0;
    nru = 0;
    if( uneeded==1 )
    {
        nru = m;
        ncu = minmn;
        ae_matrix_set_length(u, nru-1+1, ncu-1+1, _state);
    }
    if( uneeded==2 )
    {
        nru = m;
        ncu = m;
        ae_matrix_set_length(u, nru-1+1, ncu-1+1, _state);
    }
    nrvt = 0;
    ncvt = 0;
    if( vtneeded==1 )
    {
        nrvt = minmn;
        ncvt = n;
        ae_matrix_set_length(vt, nrvt-1+1, ncvt-1+1, _state);
    }
    if( vtneeded==2 )
    {
        nrvt = n;
        ncvt = n;
        ae_matrix_set_length(vt, nrvt-1+1, ncvt-1+1, _state);
    }
    
    /*
     * M much larger than N
     * Use bidiagonal reduction with QR-decomposition
     */
    if( ae_fp_greater(m,1.6*n) )
    {
        if( uneeded==0 )
        {
            
            /*
             * No left singular vectors to be computed
             */
            rmatrixqr(a, m, n, &tau, _state);
            for(i=0; i<=n-1; i++)
            {
                for(j=0; j<=i-1; j++)
                {
                    a->ptr.pp_double[i][j] = 0;
                }
            }
            rmatrixbd(a, n, n, &tauq, &taup, _state);
            rmatrixbdunpackpt(a, n, n, &taup, nrvt, vt, _state);
            rmatrixbdunpackdiagonals(a, n, n, &isupper, w, &e, _state);
            result = rmatrixbdsvd(w, &e, n, isupper, ae_false, u, 0, a, 0, vt, ncvt, _state);
            ae_frame_leave(_state);
            return result;
        }
        else
        {
            
            /*
             * Left singular vectors (may be full matrix U) to be computed
             */
            rmatrixqr(a, m, n, &tau, _state);
            rmatrixqrunpackq(a, m, n, &tau, ncu, u, _state);
            for(i=0; i<=n-1; i++)
            {
                for(j=0; j<=i-1; j++)
                {
                    a->ptr.pp_double[i][j] = 0;
                }
            }
            rmatrixbd(a, n, n, &tauq, &taup, _state);
            rmatrixbdunpackpt(a, n, n, &taup, nrvt, vt, _state);
            rmatrixbdunpackdiagonals(a, n, n, &isupper, w, &e, _state);
            if( additionalmemory<1 )
            {
                
                /*
                 * No additional memory can be used
                 */
                rmatrixbdmultiplybyq(a, n, n, &tauq, u, m, n, ae_true, ae_false, _state);
                result = rmatrixbdsvd(w, &e, n, isupper, ae_false, u, m, a, 0, vt, ncvt, _state);
            }
            else
            {
                
                /*
                 * Large U. Transforming intermediate matrix T2
                 */
                ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
                rmatrixbdunpackq(a, n, n, &tauq, n, &t2, _state);
                copymatrix(u, 0, m-1, 0, n-1, a, 0, m-1, 0, n-1, _state);
                inplacetranspose(&t2, 0, n-1, 0, n-1, &work, _state);
                result = rmatrixbdsvd(w, &e, n, isupper, ae_false, u, 0, &t2, n, vt, ncvt, _state);
                matrixmatrixmultiply(a, 0, m-1, 0, n-1, ae_false, &t2, 0, n-1, 0, n-1, ae_true, 1.0, u, 0, m-1, 0, n-1, 0.0, &work, _state);
            }
            ae_frame_leave(_state);
            return result;
        }
    }
    
    /*
     * N much larger than M
     * Use bidiagonal reduction with LQ-decomposition
     */
    if( ae_fp_greater(n,1.6*m) )
    {
        if( vtneeded==0 )
        {
            
            /*
             * No right singular vectors to be computed
             */
            rmatrixlq(a, m, n, &tau, _state);
            for(i=0; i<=m-1; i++)
            {
                for(j=i+1; j<=m-1; j++)
                {
                    a->ptr.pp_double[i][j] = 0;
                }
            }
            rmatrixbd(a, m, m, &tauq, &taup, _state);
            rmatrixbdunpackq(a, m, m, &tauq, ncu, u, _state);
            rmatrixbdunpackdiagonals(a, m, m, &isupper, w, &e, _state);
            ae_vector_set_length(&work, m+1, _state);
            inplacetranspose(u, 0, nru-1, 0, ncu-1, &work, _state);
            result = rmatrixbdsvd(w, &e, m, isupper, ae_false, a, 0, u, nru, vt, 0, _state);
            inplacetranspose(u, 0, nru-1, 0, ncu-1, &work, _state);
            ae_frame_leave(_state);
            return result;
        }
        else
        {
            
            /*
             * Right singular vectors (may be full matrix VT) to be computed
             */
            rmatrixlq(a, m, n, &tau, _state);
            rmatrixlqunpackq(a, m, n, &tau, nrvt, vt, _state);
            for(i=0; i<=m-1; i++)
            {
                for(j=i+1; j<=m-1; j++)
                {
                    a->ptr.pp_double[i][j] = 0;
                }
            }
            rmatrixbd(a, m, m, &tauq, &taup, _state);
            rmatrixbdunpackq(a, m, m, &tauq, ncu, u, _state);
            rmatrixbdunpackdiagonals(a, m, m, &isupper, w, &e, _state);
            ae_vector_set_length(&work, ae_maxint(m, n, _state)+1, _state);
            inplacetranspose(u, 0, nru-1, 0, ncu-1, &work, _state);
            if( additionalmemory<1 )
            {
                
                /*
                 * No additional memory available
                 */
                rmatrixbdmultiplybyp(a, m, m, &taup, vt, m, n, ae_false, ae_true, _state);
                result = rmatrixbdsvd(w, &e, m, isupper, ae_false, a, 0, u, nru, vt, n, _state);
            }
            else
            {
                
                /*
                 * Large VT. Transforming intermediate matrix T2
                 */
                rmatrixbdunpackpt(a, m, m, &taup, m, &t2, _state);
                result = rmatrixbdsvd(w, &e, m, isupper, ae_false, a, 0, u, nru, &t2, m, _state);
                copymatrix(vt, 0, m-1, 0, n-1, a, 0, m-1, 0, n-1, _state);
                matrixmatrixmultiply(&t2, 0, m-1, 0, m-1, ae_false, a, 0, m-1, 0, n-1, ae_false, 1.0, vt, 0, m-1, 0, n-1, 0.0, &work, _state);
            }
            inplacetranspose(u, 0, nru-1, 0, ncu-1, &work, _state);
            ae_frame_leave(_state);
            return result;
        }
    }
    
    /*
     * M<=N
     * We can use inplace transposition of U to get rid of columnwise operations
     */
    if( m<=n )
    {
        rmatrixbd(a, m, n, &tauq, &taup, _state);
        rmatrixbdunpackq(a, m, n, &tauq, ncu, u, _state);
        rmatrixbdunpackpt(a, m, n, &taup, nrvt, vt, _state);
        rmatrixbdunpackdiagonals(a, m, n, &isupper, w, &e, _state);
        ae_vector_set_length(&work, m+1, _state);
        inplacetranspose(u, 0, nru-1, 0, ncu-1, &work, _state);
        result = rmatrixbdsvd(w, &e, minmn, isupper, ae_false, a, 0, u, nru, vt, ncvt, _state);
        inplacetranspose(u, 0, nru-1, 0, ncu-1, &work, _state);
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Simple bidiagonal reduction
     */
    rmatrixbd(a, m, n, &tauq, &taup, _state);
    rmatrixbdunpackq(a, m, n, &tauq, ncu, u, _state);
    rmatrixbdunpackpt(a, m, n, &taup, nrvt, vt, _state);
    rmatrixbdunpackdiagonals(a, m, n, &isupper, w, &e, _state);
    if( additionalmemory<2||uneeded==0 )
    {
        
        /*
         * We cant use additional memory or there is no need in such operations
         */
        result = rmatrixbdsvd(w, &e, minmn, isupper, ae_false, u, nru, a, 0, vt, ncvt, _state);
    }
    else
    {
        
        /*
         * We can use additional memory
         */
        ae_matrix_set_length(&t2, minmn-1+1, m-1+1, _state);
        copyandtranspose(u, 0, m-1, 0, minmn-1, &t2, 0, minmn-1, 0, m-1, _state);
        result = rmatrixbdsvd(w, &e, minmn, isupper, ae_false, u, 0, &t2, m, vt, ncvt, _state);
        copyandtranspose(&t2, 0, minmn-1, 0, m-1, u, 0, m-1, 0, minmn-1, _state);
    }
    ae_frame_leave(_state);
    return result;
}




/*************************************************************************
Basic Cholesky solver for ScaleA*Cholesky(A)'*x = y.

This subroutine assumes that:
* A*ScaleA is well scaled
* A is well-conditioned, so no zero divisions or overflow may occur

INPUT PARAMETERS:
    CHA     -   Cholesky decomposition of A
    SqrtScaleA- square root of scale factor ScaleA
    N       -   matrix size
    IsUpper -   storage type
    XB      -   right part
    Tmp     -   buffer; function automatically allocates it, if it is  too
                small.  It  can  be  reused  if function is called several
                times.
                
OUTPUT PARAMETERS:
    XB      -   solution

NOTES: no assertion or tests are done during algorithm operation

  -- ALGLIB --
     Copyright 13.10.2010 by Bochkanov Sergey
*************************************************************************/
void fblscholeskysolve(/* Real    */ ae_matrix* cha,
     double sqrtscalea,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* xb,
     /* Real    */ ae_vector* tmp,
     ae_state *_state)
{
    ae_int_t i;
    double v;


    if( tmp->cnt<n )
    {
        ae_vector_set_length(tmp, n, _state);
    }
    
    /*
     * A = L*L' or A=U'*U
     */
    if( isupper )
    {
        
        /*
         * Solve U'*y=b first.
         */
        for(i=0; i<=n-1; i++)
        {
            xb->ptr.p_double[i] = xb->ptr.p_double[i]/(sqrtscalea*cha->ptr.pp_double[i][i]);
            if( i<n-1 )
            {
                v = xb->ptr.p_double[i];
                ae_v_moved(&tmp->ptr.p_double[i+1], 1, &cha->ptr.pp_double[i][i+1], 1, ae_v_len(i+1,n-1), sqrtscalea);
                ae_v_subd(&xb->ptr.p_double[i+1], 1, &tmp->ptr.p_double[i+1], 1, ae_v_len(i+1,n-1), v);
            }
        }
        
        /*
         * Solve U*x=y then.
         */
        for(i=n-1; i>=0; i--)
        {
            if( i<n-1 )
            {
                ae_v_moved(&tmp->ptr.p_double[i+1], 1, &cha->ptr.pp_double[i][i+1], 1, ae_v_len(i+1,n-1), sqrtscalea);
                v = ae_v_dotproduct(&tmp->ptr.p_double[i+1], 1, &xb->ptr.p_double[i+1], 1, ae_v_len(i+1,n-1));
                xb->ptr.p_double[i] = xb->ptr.p_double[i]-v;
            }
            xb->ptr.p_double[i] = xb->ptr.p_double[i]/(sqrtscalea*cha->ptr.pp_double[i][i]);
        }
    }
    else
    {
        
        /*
         * Solve L*y=b first
         */
        for(i=0; i<=n-1; i++)
        {
            if( i>0 )
            {
                ae_v_moved(&tmp->ptr.p_double[0], 1, &cha->ptr.pp_double[i][0], 1, ae_v_len(0,i-1), sqrtscalea);
                v = ae_v_dotproduct(&tmp->ptr.p_double[0], 1, &xb->ptr.p_double[0], 1, ae_v_len(0,i-1));
                xb->ptr.p_double[i] = xb->ptr.p_double[i]-v;
            }
            xb->ptr.p_double[i] = xb->ptr.p_double[i]/(sqrtscalea*cha->ptr.pp_double[i][i]);
        }
        
        /*
         * Solve L'*x=y then.
         */
        for(i=n-1; i>=0; i--)
        {
            xb->ptr.p_double[i] = xb->ptr.p_double[i]/(sqrtscalea*cha->ptr.pp_double[i][i]);
            if( i>0 )
            {
                v = xb->ptr.p_double[i];
                ae_v_moved(&tmp->ptr.p_double[0], 1, &cha->ptr.pp_double[i][0], 1, ae_v_len(0,i-1), sqrtscalea);
                ae_v_subd(&xb->ptr.p_double[0], 1, &tmp->ptr.p_double[0], 1, ae_v_len(0,i-1), v);
            }
        }
    }
}


/*************************************************************************
Fast basic linear solver: linear SPD CG

Solves (A^T*A + alpha*I)*x = b where:
* A is MxN matrix
* alpha>0 is a scalar
* I is NxN identity matrix
* b is Nx1 vector
* X is Nx1 unknown vector.

N iterations of linear conjugate gradient are used to solve problem.

INPUT PARAMETERS:
    A   -   array[M,N], matrix
    M   -   number of rows
    N   -   number of unknowns
    B   -   array[N], right part
    X   -   initial approxumation, array[N]
    Buf -   buffer; function automatically allocates it, if it is too
            small. It can be reused if function is called several times
            with same M and N.
            
OUTPUT PARAMETERS:
    X   -   improved solution
    
NOTES:
*   solver checks quality of improved solution. If (because of problem
    condition number, numerical noise, etc.) new solution is WORSE than
    original approximation, then original approximation is returned.
*   solver assumes that both A, B, Alpha are well scaled (i.e. they are
    less than sqrt(overflow) and greater than sqrt(underflow)).
    
  -- ALGLIB --
     Copyright 20.08.2009 by Bochkanov Sergey
*************************************************************************/
void fblssolvecgx(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     double alpha,
     /* Real    */ ae_vector* b,
     /* Real    */ ae_vector* x,
     /* Real    */ ae_vector* buf,
     ae_state *_state)
{
    ae_int_t k;
    ae_int_t offsrk;
    ae_int_t offsrk1;
    ae_int_t offsxk;
    ae_int_t offsxk1;
    ae_int_t offspk;
    ae_int_t offspk1;
    ae_int_t offstmp1;
    ae_int_t offstmp2;
    ae_int_t bs;
    double e1;
    double e2;
    double rk2;
    double rk12;
    double pap;
    double s;
    double betak;
    double v1;
    double v2;


    
    /*
     * Test for special case: B=0
     */
    v1 = ae_v_dotproduct(&b->ptr.p_double[0], 1, &b->ptr.p_double[0], 1, ae_v_len(0,n-1));
    if( ae_fp_eq(v1,0) )
    {
        for(k=0; k<=n-1; k++)
        {
            x->ptr.p_double[k] = 0;
        }
        return;
    }
    
    /*
     * Offsets inside Buf for:
     * * R[K], R[K+1]
     * * X[K], X[K+1]
     * * P[K], P[K+1]
     * * Tmp1 - array[M], Tmp2 - array[N]
     */
    offsrk = 0;
    offsrk1 = offsrk+n;
    offsxk = offsrk1+n;
    offsxk1 = offsxk+n;
    offspk = offsxk1+n;
    offspk1 = offspk+n;
    offstmp1 = offspk1+n;
    offstmp2 = offstmp1+m;
    bs = offstmp2+n;
    if( buf->cnt<bs )
    {
        ae_vector_set_length(buf, bs, _state);
    }
    
    /*
     * x(0) = x
     */
    ae_v_move(&buf->ptr.p_double[offsxk], 1, &x->ptr.p_double[0], 1, ae_v_len(offsxk,offsxk+n-1));
    
    /*
     * r(0) = b-A*x(0)
     * RK2 = r(0)'*r(0)
     */
    rmatrixmv(m, n, a, 0, 0, 0, buf, offsxk, buf, offstmp1, _state);
    rmatrixmv(n, m, a, 0, 0, 1, buf, offstmp1, buf, offstmp2, _state);
    ae_v_addd(&buf->ptr.p_double[offstmp2], 1, &buf->ptr.p_double[offsxk], 1, ae_v_len(offstmp2,offstmp2+n-1), alpha);
    ae_v_move(&buf->ptr.p_double[offsrk], 1, &b->ptr.p_double[0], 1, ae_v_len(offsrk,offsrk+n-1));
    ae_v_sub(&buf->ptr.p_double[offsrk], 1, &buf->ptr.p_double[offstmp2], 1, ae_v_len(offsrk,offsrk+n-1));
    rk2 = ae_v_dotproduct(&buf->ptr.p_double[offsrk], 1, &buf->ptr.p_double[offsrk], 1, ae_v_len(offsrk,offsrk+n-1));
    ae_v_move(&buf->ptr.p_double[offspk], 1, &buf->ptr.p_double[offsrk], 1, ae_v_len(offspk,offspk+n-1));
    e1 = ae_sqrt(rk2, _state);
    
    /*
     * Cycle
     */
    for(k=0; k<=n-1; k++)
    {
        
        /*
         * Calculate A*p(k) - store in Buf[OffsTmp2:OffsTmp2+N-1]
         * and p(k)'*A*p(k)  - store in PAP
         *
         * If PAP=0, break (iteration is over)
         */
        rmatrixmv(m, n, a, 0, 0, 0, buf, offspk, buf, offstmp1, _state);
        v1 = ae_v_dotproduct(&buf->ptr.p_double[offstmp1], 1, &buf->ptr.p_double[offstmp1], 1, ae_v_len(offstmp1,offstmp1+m-1));
        v2 = ae_v_dotproduct(&buf->ptr.p_double[offspk], 1, &buf->ptr.p_double[offspk], 1, ae_v_len(offspk,offspk+n-1));
        pap = v1+alpha*v2;
        rmatrixmv(n, m, a, 0, 0, 1, buf, offstmp1, buf, offstmp2, _state);
        ae_v_addd(&buf->ptr.p_double[offstmp2], 1, &buf->ptr.p_double[offspk], 1, ae_v_len(offstmp2,offstmp2+n-1), alpha);
        if( ae_fp_eq(pap,0) )
        {
            break;
        }
        
        /*
         * S = (r(k)'*r(k))/(p(k)'*A*p(k))
         */
        s = rk2/pap;
        
        /*
         * x(k+1) = x(k) + S*p(k)
         */
        ae_v_move(&buf->ptr.p_double[offsxk1], 1, &buf->ptr.p_double[offsxk], 1, ae_v_len(offsxk1,offsxk1+n-1));
        ae_v_addd(&buf->ptr.p_double[offsxk1], 1, &buf->ptr.p_double[offspk], 1, ae_v_len(offsxk1,offsxk1+n-1), s);
        
        /*
         * r(k+1) = r(k) - S*A*p(k)
         * RK12 = r(k+1)'*r(k+1)
         *
         * Break if r(k+1) small enough (when compared to r(k))
         */
        ae_v_move(&buf->ptr.p_double[offsrk1], 1, &buf->ptr.p_double[offsrk], 1, ae_v_len(offsrk1,offsrk1+n-1));
        ae_v_subd(&buf->ptr.p_double[offsrk1], 1, &buf->ptr.p_double[offstmp2], 1, ae_v_len(offsrk1,offsrk1+n-1), s);
        rk12 = ae_v_dotproduct(&buf->ptr.p_double[offsrk1], 1, &buf->ptr.p_double[offsrk1], 1, ae_v_len(offsrk1,offsrk1+n-1));
        if( ae_fp_less_eq(ae_sqrt(rk12, _state),100*ae_machineepsilon*ae_sqrt(rk2, _state)) )
        {
            
            /*
             * X(k) = x(k+1) before exit -
             * - because we expect to find solution at x(k)
             */
            ae_v_move(&buf->ptr.p_double[offsxk], 1, &buf->ptr.p_double[offsxk1], 1, ae_v_len(offsxk,offsxk+n-1));
            break;
        }
        
        /*
         * BetaK = RK12/RK2
         * p(k+1) = r(k+1)+betak*p(k)
         */
        betak = rk12/rk2;
        ae_v_move(&buf->ptr.p_double[offspk1], 1, &buf->ptr.p_double[offsrk1], 1, ae_v_len(offspk1,offspk1+n-1));
        ae_v_addd(&buf->ptr.p_double[offspk1], 1, &buf->ptr.p_double[offspk], 1, ae_v_len(offspk1,offspk1+n-1), betak);
        
        /*
         * r(k) := r(k+1)
         * x(k) := x(k+1)
         * p(k) := p(k+1)
         */
        ae_v_move(&buf->ptr.p_double[offsrk], 1, &buf->ptr.p_double[offsrk1], 1, ae_v_len(offsrk,offsrk+n-1));
        ae_v_move(&buf->ptr.p_double[offsxk], 1, &buf->ptr.p_double[offsxk1], 1, ae_v_len(offsxk,offsxk+n-1));
        ae_v_move(&buf->ptr.p_double[offspk], 1, &buf->ptr.p_double[offspk1], 1, ae_v_len(offspk,offspk+n-1));
        rk2 = rk12;
    }
    
    /*
     * Calculate E2
     */
    rmatrixmv(m, n, a, 0, 0, 0, buf, offsxk, buf, offstmp1, _state);
    rmatrixmv(n, m, a, 0, 0, 1, buf, offstmp1, buf, offstmp2, _state);
    ae_v_addd(&buf->ptr.p_double[offstmp2], 1, &buf->ptr.p_double[offsxk], 1, ae_v_len(offstmp2,offstmp2+n-1), alpha);
    ae_v_move(&buf->ptr.p_double[offsrk], 1, &b->ptr.p_double[0], 1, ae_v_len(offsrk,offsrk+n-1));
    ae_v_sub(&buf->ptr.p_double[offsrk], 1, &buf->ptr.p_double[offstmp2], 1, ae_v_len(offsrk,offsrk+n-1));
    v1 = ae_v_dotproduct(&buf->ptr.p_double[offsrk], 1, &buf->ptr.p_double[offsrk], 1, ae_v_len(offsrk,offsrk+n-1));
    e2 = ae_sqrt(v1, _state);
    
    /*
     * Output result (if it was improved)
     */
    if( ae_fp_less(e2,e1) )
    {
        ae_v_move(&x->ptr.p_double[0], 1, &buf->ptr.p_double[offsxk], 1, ae_v_len(0,n-1));
    }
}


/*************************************************************************
Construction of linear conjugate gradient solver.

State parameter passed using "var" semantics (i.e. previous state  is  NOT
erased). When it is already initialized, we can reause prevously allocated
memory.

INPUT PARAMETERS:
    X       -   initial solution
    B       -   right part
    N       -   system size
    State   -   structure; may be preallocated, if we want to reuse memory

OUTPUT PARAMETERS:
    State   -   structure which is used by FBLSCGIteration() to store
                algorithm state between subsequent calls.

NOTE: no error checking is done; caller must check all parameters, prevent
      overflows, and so on.

  -- ALGLIB --
     Copyright 22.10.2009 by Bochkanov Sergey
*************************************************************************/
void fblscgcreate(/* Real    */ ae_vector* x,
     /* Real    */ ae_vector* b,
     ae_int_t n,
     fblslincgstate* state,
     ae_state *_state)
{


    if( state->b.cnt<n )
    {
        ae_vector_set_length(&state->b, n, _state);
    }
    if( state->rk.cnt<n )
    {
        ae_vector_set_length(&state->rk, n, _state);
    }
    if( state->rk1.cnt<n )
    {
        ae_vector_set_length(&state->rk1, n, _state);
    }
    if( state->xk.cnt<n )
    {
        ae_vector_set_length(&state->xk, n, _state);
    }
    if( state->xk1.cnt<n )
    {
        ae_vector_set_length(&state->xk1, n, _state);
    }
    if( state->pk.cnt<n )
    {
        ae_vector_set_length(&state->pk, n, _state);
    }
    if( state->pk1.cnt<n )
    {
        ae_vector_set_length(&state->pk1, n, _state);
    }
    if( state->tmp2.cnt<n )
    {
        ae_vector_set_length(&state->tmp2, n, _state);
    }
    if( state->x.cnt<n )
    {
        ae_vector_set_length(&state->x, n, _state);
    }
    if( state->ax.cnt<n )
    {
        ae_vector_set_length(&state->ax, n, _state);
    }
    state->n = n;
    ae_v_move(&state->xk.ptr.p_double[0], 1, &x->ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_move(&state->b.ptr.p_double[0], 1, &b->ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_vector_set_length(&state->rstate.ia, 1+1, _state);
    ae_vector_set_length(&state->rstate.ra, 6+1, _state);
    state->rstate.stage = -1;
}


/*************************************************************************
Linear CG solver, function relying on reverse communication to calculate
matrix-vector products.

See comments for FBLSLinCGState structure for more info.

  -- ALGLIB --
     Copyright 22.10.2009 by Bochkanov Sergey
*************************************************************************/
ae_bool fblscgiteration(fblslincgstate* state, ae_state *_state)
{
    ae_int_t n;
    ae_int_t k;
    double rk2;
    double rk12;
    double pap;
    double s;
    double betak;
    double v1;
    double v2;
    ae_bool result;


    
    /*
     * Reverse communication preparations
     * I know it looks ugly, but it works the same way
     * anywhere from C++ to Python.
     *
     * This code initializes locals by:
     * * random values determined during code
     *   generation - on first subroutine call
     * * values from previous call - on subsequent calls
     */
    if( state->rstate.stage>=0 )
    {
        n = state->rstate.ia.ptr.p_int[0];
        k = state->rstate.ia.ptr.p_int[1];
        rk2 = state->rstate.ra.ptr.p_double[0];
        rk12 = state->rstate.ra.ptr.p_double[1];
        pap = state->rstate.ra.ptr.p_double[2];
        s = state->rstate.ra.ptr.p_double[3];
        betak = state->rstate.ra.ptr.p_double[4];
        v1 = state->rstate.ra.ptr.p_double[5];
        v2 = state->rstate.ra.ptr.p_double[6];
    }
    else
    {
        n = -983;
        k = -989;
        rk2 = -834;
        rk12 = 900;
        pap = -287;
        s = 364;
        betak = 214;
        v1 = -338;
        v2 = -686;
    }
    if( state->rstate.stage==0 )
    {
        goto lbl_0;
    }
    if( state->rstate.stage==1 )
    {
        goto lbl_1;
    }
    if( state->rstate.stage==2 )
    {
        goto lbl_2;
    }
    
    /*
     * Routine body
     */
    
    /*
     * prepare locals
     */
    n = state->n;
    
    /*
     * Test for special case: B=0
     */
    v1 = ae_v_dotproduct(&state->b.ptr.p_double[0], 1, &state->b.ptr.p_double[0], 1, ae_v_len(0,n-1));
    if( ae_fp_eq(v1,0) )
    {
        for(k=0; k<=n-1; k++)
        {
            state->xk.ptr.p_double[k] = 0;
        }
        result = ae_false;
        return result;
    }
    
    /*
     * r(0) = b-A*x(0)
     * RK2 = r(0)'*r(0)
     */
    ae_v_move(&state->x.ptr.p_double[0], 1, &state->xk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    state->rstate.stage = 0;
    goto lbl_rcomm;
lbl_0:
    ae_v_move(&state->rk.ptr.p_double[0], 1, &state->b.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_sub(&state->rk.ptr.p_double[0], 1, &state->ax.ptr.p_double[0], 1, ae_v_len(0,n-1));
    rk2 = ae_v_dotproduct(&state->rk.ptr.p_double[0], 1, &state->rk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_move(&state->pk.ptr.p_double[0], 1, &state->rk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    state->e1 = ae_sqrt(rk2, _state);
    
    /*
     * Cycle
     */
    k = 0;
lbl_3:
    if( k>n-1 )
    {
        goto lbl_5;
    }
    
    /*
     * Calculate A*p(k) - store in State.Tmp2
     * and p(k)'*A*p(k)  - store in PAP
     *
     * If PAP=0, break (iteration is over)
     */
    ae_v_move(&state->x.ptr.p_double[0], 1, &state->pk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    state->rstate.stage = 1;
    goto lbl_rcomm;
lbl_1:
    ae_v_move(&state->tmp2.ptr.p_double[0], 1, &state->ax.ptr.p_double[0], 1, ae_v_len(0,n-1));
    pap = state->xax;
    if( !ae_isfinite(pap, _state) )
    {
        goto lbl_5;
    }
    if( ae_fp_less_eq(pap,0) )
    {
        goto lbl_5;
    }
    
    /*
     * S = (r(k)'*r(k))/(p(k)'*A*p(k))
     */
    s = rk2/pap;
    
    /*
     * x(k+1) = x(k) + S*p(k)
     */
    ae_v_move(&state->xk1.ptr.p_double[0], 1, &state->xk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_addd(&state->xk1.ptr.p_double[0], 1, &state->pk.ptr.p_double[0], 1, ae_v_len(0,n-1), s);
    
    /*
     * r(k+1) = r(k) - S*A*p(k)
     * RK12 = r(k+1)'*r(k+1)
     *
     * Break if r(k+1) small enough (when compared to r(k))
     */
    ae_v_move(&state->rk1.ptr.p_double[0], 1, &state->rk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_subd(&state->rk1.ptr.p_double[0], 1, &state->tmp2.ptr.p_double[0], 1, ae_v_len(0,n-1), s);
    rk12 = ae_v_dotproduct(&state->rk1.ptr.p_double[0], 1, &state->rk1.ptr.p_double[0], 1, ae_v_len(0,n-1));
    if( ae_fp_less_eq(ae_sqrt(rk12, _state),100*ae_machineepsilon*state->e1) )
    {
        
        /*
         * X(k) = x(k+1) before exit -
         * - because we expect to find solution at x(k)
         */
        ae_v_move(&state->xk.ptr.p_double[0], 1, &state->xk1.ptr.p_double[0], 1, ae_v_len(0,n-1));
        goto lbl_5;
    }
    
    /*
     * BetaK = RK12/RK2
     * p(k+1) = r(k+1)+betak*p(k)
     *
     * NOTE: we expect that BetaK won't overflow because of
     * "Sqrt(RK12)<=100*MachineEpsilon*E1" test above.
     */
    betak = rk12/rk2;
    ae_v_move(&state->pk1.ptr.p_double[0], 1, &state->rk1.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_addd(&state->pk1.ptr.p_double[0], 1, &state->pk.ptr.p_double[0], 1, ae_v_len(0,n-1), betak);
    
    /*
     * r(k) := r(k+1)
     * x(k) := x(k+1)
     * p(k) := p(k+1)
     */
    ae_v_move(&state->rk.ptr.p_double[0], 1, &state->rk1.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_move(&state->xk.ptr.p_double[0], 1, &state->xk1.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_move(&state->pk.ptr.p_double[0], 1, &state->pk1.ptr.p_double[0], 1, ae_v_len(0,n-1));
    rk2 = rk12;
    k = k+1;
    goto lbl_3;
lbl_5:
    
    /*
     * Calculate E2
     */
    ae_v_move(&state->x.ptr.p_double[0], 1, &state->xk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    state->rstate.stage = 2;
    goto lbl_rcomm;
lbl_2:
    ae_v_move(&state->rk.ptr.p_double[0], 1, &state->b.ptr.p_double[0], 1, ae_v_len(0,n-1));
    ae_v_sub(&state->rk.ptr.p_double[0], 1, &state->ax.ptr.p_double[0], 1, ae_v_len(0,n-1));
    v1 = ae_v_dotproduct(&state->rk.ptr.p_double[0], 1, &state->rk.ptr.p_double[0], 1, ae_v_len(0,n-1));
    state->e2 = ae_sqrt(v1, _state);
    result = ae_false;
    return result;
    
    /*
     * Saving state
     */
lbl_rcomm:
    result = ae_true;
    state->rstate.ia.ptr.p_int[0] = n;
    state->rstate.ia.ptr.p_int[1] = k;
    state->rstate.ra.ptr.p_double[0] = rk2;
    state->rstate.ra.ptr.p_double[1] = rk12;
    state->rstate.ra.ptr.p_double[2] = pap;
    state->rstate.ra.ptr.p_double[3] = s;
    state->rstate.ra.ptr.p_double[4] = betak;
    state->rstate.ra.ptr.p_double[5] = v1;
    state->rstate.ra.ptr.p_double[6] = v2;
    return result;
}


ae_bool _fblslincgstate_init(fblslincgstate* p, ae_state *_state, ae_bool make_automatic)
{
    if( !ae_vector_init(&p->x, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->ax, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->rk, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->rk1, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->xk, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->xk1, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->pk, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->pk1, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->b, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    if( !_rcommstate_init(&p->rstate, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init(&p->tmp2, 0, DT_REAL, _state, make_automatic) )
        return ae_false;
    return ae_true;
}


ae_bool _fblslincgstate_init_copy(fblslincgstate* dst, fblslincgstate* src, ae_state *_state, ae_bool make_automatic)
{
    dst->e1 = src->e1;
    dst->e2 = src->e2;
    if( !ae_vector_init_copy(&dst->x, &src->x, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->ax, &src->ax, _state, make_automatic) )
        return ae_false;
    dst->xax = src->xax;
    dst->n = src->n;
    if( !ae_vector_init_copy(&dst->rk, &src->rk, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->rk1, &src->rk1, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->xk, &src->xk, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->xk1, &src->xk1, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->pk, &src->pk, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->pk1, &src->pk1, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->b, &src->b, _state, make_automatic) )
        return ae_false;
    if( !_rcommstate_init_copy(&dst->rstate, &src->rstate, _state, make_automatic) )
        return ae_false;
    if( !ae_vector_init_copy(&dst->tmp2, &src->tmp2, _state, make_automatic) )
        return ae_false;
    return ae_true;
}


void _fblslincgstate_clear(fblslincgstate* p)
{
    ae_vector_clear(&p->x);
    ae_vector_clear(&p->ax);
    ae_vector_clear(&p->rk);
    ae_vector_clear(&p->rk1);
    ae_vector_clear(&p->xk);
    ae_vector_clear(&p->xk1);
    ae_vector_clear(&p->pk);
    ae_vector_clear(&p->pk1);
    ae_vector_clear(&p->b);
    _rcommstate_clear(&p->rstate);
    ae_vector_clear(&p->tmp2);
}




/*************************************************************************
Determinant calculation of the matrix given by its LU decomposition.

Input parameters:
    A       -   LU decomposition of the matrix (output of
                RMatrixLU subroutine).
    Pivots  -   table of permutations which were made during
                the LU decomposition.
                Output of RMatrixLU subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: matrix determinant.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
double rmatrixludet(/* Real    */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t s;
    double result;


    ae_assert(n>=1, "RMatrixLUDet: N<1!", _state);
    ae_assert(pivots->cnt>=n, "RMatrixLUDet: Pivots array is too short!", _state);
    ae_assert(a->rows>=n, "RMatrixLUDet: rows(A)<N!", _state);
    ae_assert(a->cols>=n, "RMatrixLUDet: cols(A)<N!", _state);
    ae_assert(apservisfinitematrix(a, n, n, _state), "RMatrixLUDet: A contains infinite or NaN values!", _state);
    result = 1;
    s = 1;
    for(i=0; i<=n-1; i++)
    {
        result = result*a->ptr.pp_double[i][i];
        if( pivots->ptr.p_int[i]!=i )
        {
            s = -s;
        }
    }
    result = result*s;
    return result;
}


/*************************************************************************
Calculation of the determinant of a general matrix

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1]
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: determinant of matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
double rmatrixdet(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_vector pivots;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>=1, "RMatrixDet: N<1!", _state);
    ae_assert(a->rows>=n, "RMatrixDet: rows(A)<N!", _state);
    ae_assert(a->cols>=n, "RMatrixDet: cols(A)<N!", _state);
    ae_assert(apservisfinitematrix(a, n, n, _state), "RMatrixDet: A contains infinite or NaN values!", _state);
    rmatrixlu(a, n, n, &pivots, _state);
    result = rmatrixludet(a, &pivots, n, _state);
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Determinant calculation of the matrix given by its LU decomposition.

Input parameters:
    A       -   LU decomposition of the matrix (output of
                RMatrixLU subroutine).
    Pivots  -   table of permutations which were made during
                the LU decomposition.
                Output of RMatrixLU subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: matrix determinant.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
ae_complex cmatrixludet(/* Complex */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_state *_state)
{
    ae_int_t i;
    ae_int_t s;
    ae_complex result;


    ae_assert(n>=1, "CMatrixLUDet: N<1!", _state);
    ae_assert(pivots->cnt>=n, "CMatrixLUDet: Pivots array is too short!", _state);
    ae_assert(a->rows>=n, "CMatrixLUDet: rows(A)<N!", _state);
    ae_assert(a->cols>=n, "CMatrixLUDet: cols(A)<N!", _state);
    ae_assert(apservisfinitecmatrix(a, n, n, _state), "CMatrixLUDet: A contains infinite or NaN values!", _state);
    result = ae_complex_from_d(1);
    s = 1;
    for(i=0; i<=n-1; i++)
    {
        result = ae_c_mul(result,a->ptr.pp_complex[i][i]);
        if( pivots->ptr.p_int[i]!=i )
        {
            s = -s;
        }
    }
    result = ae_c_mul_d(result,s);
    return result;
}


/*************************************************************************
Calculation of the determinant of a general matrix

Input parameters:
    A       -   matrix, array[0..N-1, 0..N-1]
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

Result: determinant of matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
ae_complex cmatrixdet(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_vector pivots;
    ae_complex result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_init(&pivots, 0, DT_INT, _state, ae_true);

    ae_assert(n>=1, "CMatrixDet: N<1!", _state);
    ae_assert(a->rows>=n, "CMatrixDet: rows(A)<N!", _state);
    ae_assert(a->cols>=n, "CMatrixDet: cols(A)<N!", _state);
    ae_assert(apservisfinitecmatrix(a, n, n, _state), "CMatrixDet: A contains infinite or NaN values!", _state);
    cmatrixlu(a, n, n, &pivots, _state);
    result = cmatrixludet(a, &pivots, n, _state);
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Determinant calculation of the matrix given by the Cholesky decomposition.

Input parameters:
    A       -   Cholesky decomposition,
                output of SMatrixCholesky subroutine.
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)

As the determinant is equal to the product of squares of diagonal elements,
it�s not necessary to specify which triangle - lower or upper - the matrix
is stored in.

Result:
    matrix determinant.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixcholeskydet(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state)
{
    ae_int_t i;
    ae_bool f;
    double result;


    ae_assert(n>=1, "SPDMatrixCholeskyDet: N<1!", _state);
    ae_assert(a->rows>=n, "SPDMatrixCholeskyDet: rows(A)<N!", _state);
    ae_assert(a->cols>=n, "SPDMatrixCholeskyDet: cols(A)<N!", _state);
    f = ae_true;
    for(i=0; i<=n-1; i++)
    {
        f = f&&ae_isfinite(a->ptr.pp_double[i][i], _state);
    }
    ae_assert(f, "SPDMatrixCholeskyDet: A contains infinite or NaN values!", _state);
    result = 1;
    for(i=0; i<=n-1; i++)
    {
        result = result*ae_sqr(a->ptr.pp_double[i][i], _state);
    }
    return result;
}


/*************************************************************************
Determinant calculation of the symmetric positive definite matrix.

Input parameters:
    A       -   matrix. Array with elements [0..N-1, 0..N-1].
    N       -   (optional) size of matrix A:
                * if given, only principal NxN submatrix is processed and
                  overwritten. other elements are unchanged.
                * if not given, automatically determined from matrix size
                  (A must be square matrix)
    IsUpper -   (optional) storage type:
                * if True, symmetric matrix  A  is  given  by  its  upper
                  triangle, and the lower triangle isn�t used/changed  by
                  function
                * if False, symmetric matrix  A  is  given  by  its lower
                  triangle, and the upper triangle isn�t used/changed  by
                  function
                * if not given, both lower and upper  triangles  must  be
                  filled.

Result:
    determinant of matrix A.
    If matrix A is not positive definite, exception is thrown.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixdet(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_bool b;
    double result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;

    ae_assert(n>=1, "SPDMatrixDet: N<1!", _state);
    ae_assert(a->rows>=n, "SPDMatrixDet: rows(A)<N!", _state);
    ae_assert(a->cols>=n, "SPDMatrixDet: cols(A)<N!", _state);
    ae_assert(isfinitertrmatrix(a, n, isupper, _state), "SPDMatrixDet: A contains infinite or NaN values!", _state);
    b = spdmatrixcholesky(a, n, isupper, _state);
    ae_assert(b, "SPDMatrixDet: A is not SPD!", _state);
    result = spdmatrixcholeskydet(a, n, _state);
    ae_frame_leave(_state);
    return result;
}




/*************************************************************************
Algorithm for solving the following generalized symmetric positive-definite
eigenproblem:
    A*x = lambda*B*x (1) or
    A*B*x = lambda*x (2) or
    B*A*x = lambda*x (3).
where A is a symmetric matrix, B - symmetric positive-definite matrix.
The problem is solved by reducing it to an ordinary  symmetric  eigenvalue
problem.

Input parameters:
    A           -   symmetric matrix which is given by its upper or lower
                    triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    N           -   size of matrices A and B.
    IsUpperA    -   storage format of matrix A.
    B           -   symmetric positive-definite matrix which is given by
                    its upper or lower triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    IsUpperB    -   storage format of matrix B.
    ZNeeded     -   if ZNeeded is equal to:
                     * 0, the eigenvectors are not returned;
                     * 1, the eigenvectors are returned.
    ProblemType -   if ProblemType is equal to:
                     * 1, the following problem is solved: A*x = lambda*B*x;
                     * 2, the following problem is solved: A*B*x = lambda*x;
                     * 3, the following problem is solved: B*A*x = lambda*x.

Output parameters:
    D           -   eigenvalues in ascending order.
                    Array whose index ranges within [0..N-1].
    Z           -   if ZNeeded is equal to:
                     * 0, Z hasn�t changed;
                     * 1, Z contains eigenvectors.
                    Array whose indexes range within [0..N-1, 0..N-1].
                    The eigenvectors are stored in matrix columns. It should
                    be noted that the eigenvectors in such problems do not
                    form an orthogonal system.

Result:
    True, if the problem was solved successfully.
    False, if the error occurred during the Cholesky decomposition of matrix
    B (the matrix isn�t positive-definite) or during the work of the iterative
    algorithm for solving the symmetric eigenproblem.

See also the GeneralizedSymmetricDefiniteEVDReduce subroutine.

  -- ALGLIB --
     Copyright 1.28.2006 by Bochkanov Sergey
*************************************************************************/
ae_bool smatrixgevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isuppera,
     /* Real    */ ae_matrix* b,
     ae_bool isupperb,
     ae_int_t zneeded,
     ae_int_t problemtype,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_matrix* z,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix _a;
    ae_matrix r;
    ae_matrix t;
    ae_bool isupperr;
    ae_int_t j1;
    ae_int_t j2;
    ae_int_t j1inc;
    ae_int_t j2inc;
    ae_int_t i;
    ae_int_t j;
    double v;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_init_copy(&_a, a, _state, ae_true);
    a = &_a;
    ae_vector_clear(d);
    ae_matrix_clear(z);
    ae_matrix_init(&r, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&t, 0, 0, DT_REAL, _state, ae_true);

    
    /*
     * Reduce and solve
     */
    result = smatrixgevdreduce(a, n, isuppera, b, isupperb, problemtype, &r, &isupperr, _state);
    if( !result )
    {
        ae_frame_leave(_state);
        return result;
    }
    result = smatrixevd(a, n, zneeded, isuppera, d, &t, _state);
    if( !result )
    {
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Transform eigenvectors if needed
     */
    if( zneeded!=0 )
    {
        
        /*
         * fill Z with zeros
         */
        ae_matrix_set_length(z, n-1+1, n-1+1, _state);
        for(j=0; j<=n-1; j++)
        {
            z->ptr.pp_double[0][j] = 0.0;
        }
        for(i=1; i<=n-1; i++)
        {
            ae_v_move(&z->ptr.pp_double[i][0], 1, &z->ptr.pp_double[0][0], 1, ae_v_len(0,n-1));
        }
        
        /*
         * Setup R properties
         */
        if( isupperr )
        {
            j1 = 0;
            j2 = n-1;
            j1inc = 1;
            j2inc = 0;
        }
        else
        {
            j1 = 0;
            j2 = 0;
            j1inc = 0;
            j2inc = 1;
        }
        
        /*
         * Calculate R*Z
         */
        for(i=0; i<=n-1; i++)
        {
            for(j=j1; j<=j2; j++)
            {
                v = r.ptr.pp_double[i][j];
                ae_v_addd(&z->ptr.pp_double[i][0], 1, &t.ptr.pp_double[j][0], 1, ae_v_len(0,n-1), v);
            }
            j1 = j1+j1inc;
            j2 = j2+j2inc;
        }
    }
    ae_frame_leave(_state);
    return result;
}


/*************************************************************************
Algorithm for reduction of the following generalized symmetric positive-
definite eigenvalue problem:
    A*x = lambda*B*x (1) or
    A*B*x = lambda*x (2) or
    B*A*x = lambda*x (3)
to the symmetric eigenvalues problem C*y = lambda*y (eigenvalues of this and
the given problems are the same, and the eigenvectors of the given problem
could be obtained by multiplying the obtained eigenvectors by the
transformation matrix x = R*y).

Here A is a symmetric matrix, B - symmetric positive-definite matrix.

Input parameters:
    A           -   symmetric matrix which is given by its upper or lower
                    triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    N           -   size of matrices A and B.
    IsUpperA    -   storage format of matrix A.
    B           -   symmetric positive-definite matrix which is given by
                    its upper or lower triangular part.
                    Array whose indexes range within [0..N-1, 0..N-1].
    IsUpperB    -   storage format of matrix B.
    ProblemType -   if ProblemType is equal to:
                     * 1, the following problem is solved: A*x = lambda*B*x;
                     * 2, the following problem is solved: A*B*x = lambda*x;
                     * 3, the following problem is solved: B*A*x = lambda*x.

Output parameters:
    A           -   symmetric matrix which is given by its upper or lower
                    triangle depending on IsUpperA. Contains matrix C.
                    Array whose indexes range within [0..N-1, 0..N-1].
    R           -   upper triangular or low triangular transformation matrix
                    which is used to obtain the eigenvectors of a given problem
                    as the product of eigenvectors of C (from the right) and
                    matrix R (from the left). If the matrix is upper
                    triangular, the elements below the main diagonal
                    are equal to 0 (and vice versa). Thus, we can perform
                    the multiplication without taking into account the
                    internal structure (which is an easier though less
                    effective way).
                    Array whose indexes range within [0..N-1, 0..N-1].
    IsUpperR    -   type of matrix R (upper or lower triangular).

Result:
    True, if the problem was reduced successfully.
    False, if the error occurred during the Cholesky decomposition of
        matrix B (the matrix is not positive-definite).

  -- ALGLIB --
     Copyright 1.28.2006 by Bochkanov Sergey
*************************************************************************/
ae_bool smatrixgevdreduce(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isuppera,
     /* Real    */ ae_matrix* b,
     ae_bool isupperb,
     ae_int_t problemtype,
     /* Real    */ ae_matrix* r,
     ae_bool* isupperr,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_matrix t;
    ae_vector w1;
    ae_vector w2;
    ae_vector w3;
    ae_int_t i;
    ae_int_t j;
    double v;
    matinvreport rep;
    ae_int_t info;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(r);
    *isupperr = ae_false;
    ae_matrix_init(&t, 0, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&w1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&w2, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&w3, 0, DT_REAL, _state, ae_true);
    _matinvreport_init(&rep, _state, ae_true);

    ae_assert(n>0, "SMatrixGEVDReduce: N<=0!", _state);
    ae_assert((problemtype==1||problemtype==2)||problemtype==3, "SMatrixGEVDReduce: incorrect ProblemType!", _state);
    result = ae_true;
    
    /*
     * Problem 1:  A*x = lambda*B*x
     *
     * Reducing to:
     *     C*y = lambda*y
     *     C = L^(-1) * A * L^(-T)
     *     x = L^(-T) * y
     */
    if( problemtype==1 )
    {
        
        /*
         * Factorize B in T: B = LL'
         */
        ae_matrix_set_length(&t, n-1+1, n-1+1, _state);
        if( isupperb )
        {
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&t.ptr.pp_double[i][i], t.stride, &b->ptr.pp_double[i][i], 1, ae_v_len(i,n-1));
            }
        }
        else
        {
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&t.ptr.pp_double[i][0], 1, &b->ptr.pp_double[i][0], 1, ae_v_len(0,i));
            }
        }
        if( !spdmatrixcholesky(&t, n, ae_false, _state) )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Invert L in T
         */
        rmatrixtrinverse(&t, n, ae_false, ae_false, &info, &rep, _state);
        if( info<=0 )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Build L^(-1) * A * L^(-T) in R
         */
        ae_vector_set_length(&w1, n+1, _state);
        ae_vector_set_length(&w2, n+1, _state);
        ae_matrix_set_length(r, n-1+1, n-1+1, _state);
        for(j=1; j<=n; j++)
        {
            
            /*
             * Form w2 = A * l'(j) (here l'(j) is j-th column of L^(-T))
             */
            ae_v_move(&w1.ptr.p_double[1], 1, &t.ptr.pp_double[j-1][0], 1, ae_v_len(1,j));
            symmetricmatrixvectormultiply(a, isuppera, 0, j-1, &w1, 1.0, &w2, _state);
            if( isuppera )
            {
                matrixvectormultiply(a, 0, j-1, j, n-1, ae_true, &w1, 1, j, 1.0, &w2, j+1, n, 0.0, _state);
            }
            else
            {
                matrixvectormultiply(a, j, n-1, 0, j-1, ae_false, &w1, 1, j, 1.0, &w2, j+1, n, 0.0, _state);
            }
            
            /*
             * Form l(i)*w2 (here l(i) is i-th row of L^(-1))
             */
            for(i=1; i<=n; i++)
            {
                v = ae_v_dotproduct(&t.ptr.pp_double[i-1][0], 1, &w2.ptr.p_double[1], 1, ae_v_len(0,i-1));
                r->ptr.pp_double[i-1][j-1] = v;
            }
        }
        
        /*
         * Copy R to A
         */
        for(i=0; i<=n-1; i++)
        {
            ae_v_move(&a->ptr.pp_double[i][0], 1, &r->ptr.pp_double[i][0], 1, ae_v_len(0,n-1));
        }
        
        /*
         * Copy L^(-1) from T to R and transpose
         */
        *isupperr = ae_true;
        for(i=0; i<=n-1; i++)
        {
            for(j=0; j<=i-1; j++)
            {
                r->ptr.pp_double[i][j] = 0;
            }
        }
        for(i=0; i<=n-1; i++)
        {
            ae_v_move(&r->ptr.pp_double[i][i], 1, &t.ptr.pp_double[i][i], t.stride, ae_v_len(i,n-1));
        }
        ae_frame_leave(_state);
        return result;
    }
    
    /*
     * Problem 2:  A*B*x = lambda*x
     * or
     * problem 3:  B*A*x = lambda*x
     *
     * Reducing to:
     *     C*y = lambda*y
     *     C = U * A * U'
     *     B = U'* U
     */
    if( problemtype==2||problemtype==3 )
    {
        
        /*
         * Factorize B in T: B = U'*U
         */
        ae_matrix_set_length(&t, n-1+1, n-1+1, _state);
        if( isupperb )
        {
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&t.ptr.pp_double[i][i], 1, &b->ptr.pp_double[i][i], 1, ae_v_len(i,n-1));
            }
        }
        else
        {
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&t.ptr.pp_double[i][i], 1, &b->ptr.pp_double[i][i], b->stride, ae_v_len(i,n-1));
            }
        }
        if( !spdmatrixcholesky(&t, n, ae_true, _state) )
        {
            result = ae_false;
            ae_frame_leave(_state);
            return result;
        }
        
        /*
         * Build U * A * U' in R
         */
        ae_vector_set_length(&w1, n+1, _state);
        ae_vector_set_length(&w2, n+1, _state);
        ae_vector_set_length(&w3, n+1, _state);
        ae_matrix_set_length(r, n-1+1, n-1+1, _state);
        for(j=1; j<=n; j++)
        {
            
            /*
             * Form w2 = A * u'(j) (here u'(j) is j-th column of U')
             */
            ae_v_move(&w1.ptr.p_double[1], 1, &t.ptr.pp_double[j-1][j-1], 1, ae_v_len(1,n-j+1));
            symmetricmatrixvectormultiply(a, isuppera, j-1, n-1, &w1, 1.0, &w3, _state);
            ae_v_move(&w2.ptr.p_double[j], 1, &w3.ptr.p_double[1], 1, ae_v_len(j,n));
            ae_v_move(&w1.ptr.p_double[j], 1, &t.ptr.pp_double[j-1][j-1], 1, ae_v_len(j,n));
            if( isuppera )
            {
                matrixvectormultiply(a, 0, j-2, j-1, n-1, ae_false, &w1, j, n, 1.0, &w2, 1, j-1, 0.0, _state);
            }
            else
            {
                matrixvectormultiply(a, j-1, n-1, 0, j-2, ae_true, &w1, j, n, 1.0, &w2, 1, j-1, 0.0, _state);
            }
            
            /*
             * Form u(i)*w2 (here u(i) is i-th row of U)
             */
            for(i=1; i<=n; i++)
            {
                v = ae_v_dotproduct(&t.ptr.pp_double[i-1][i-1], 1, &w2.ptr.p_double[i], 1, ae_v_len(i-1,n-1));
                r->ptr.pp_double[i-1][j-1] = v;
            }
        }
        
        /*
         * Copy R to A
         */
        for(i=0; i<=n-1; i++)
        {
            ae_v_move(&a->ptr.pp_double[i][0], 1, &r->ptr.pp_double[i][0], 1, ae_v_len(0,n-1));
        }
        if( problemtype==2 )
        {
            
            /*
             * Invert U in T
             */
            rmatrixtrinverse(&t, n, ae_true, ae_false, &info, &rep, _state);
            if( info<=0 )
            {
                result = ae_false;
                ae_frame_leave(_state);
                return result;
            }
            
            /*
             * Copy U^-1 from T to R
             */
            *isupperr = ae_true;
            for(i=0; i<=n-1; i++)
            {
                for(j=0; j<=i-1; j++)
                {
                    r->ptr.pp_double[i][j] = 0;
                }
            }
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&r->ptr.pp_double[i][i], 1, &t.ptr.pp_double[i][i], 1, ae_v_len(i,n-1));
            }
        }
        else
        {
            
            /*
             * Copy U from T to R and transpose
             */
            *isupperr = ae_false;
            for(i=0; i<=n-1; i++)
            {
                for(j=i+1; j<=n-1; j++)
                {
                    r->ptr.pp_double[i][j] = 0;
                }
            }
            for(i=0; i<=n-1; i++)
            {
                ae_v_move(&r->ptr.pp_double[i][i], r->stride, &t.ptr.pp_double[i][i], 1, ae_v_len(i,n-1));
            }
        }
    }
    ae_frame_leave(_state);
    return result;
}




/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm updates matrix A^-1 when adding a number to an element
of matrix A.

Input parameters:
    InvA    -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    UpdRow  -   row where the element to be updated is stored.
    UpdColumn - column where the element to be updated is stored.
    UpdVal  -   a number to be added to the element.


Output parameters:
    InvA    -   inverse of modified matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdatesimple(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     ae_int_t updrow,
     ae_int_t updcolumn,
     double updval,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector t1;
    ae_vector t2;
    ae_int_t i;
    double lambdav;
    double vt;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&t1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t2, 0, DT_REAL, _state, ae_true);

    ae_assert(updrow>=0&&updrow<n, "RMatrixInvUpdateSimple: incorrect UpdRow!", _state);
    ae_assert(updcolumn>=0&&updcolumn<n, "RMatrixInvUpdateSimple: incorrect UpdColumn!", _state);
    ae_vector_set_length(&t1, n-1+1, _state);
    ae_vector_set_length(&t2, n-1+1, _state);
    
    /*
     * T1 = InvA * U
     */
    ae_v_move(&t1.ptr.p_double[0], 1, &inva->ptr.pp_double[0][updrow], inva->stride, ae_v_len(0,n-1));
    
    /*
     * T2 = v*InvA
     */
    ae_v_move(&t2.ptr.p_double[0], 1, &inva->ptr.pp_double[updcolumn][0], 1, ae_v_len(0,n-1));
    
    /*
     * Lambda = v * InvA * U
     */
    lambdav = updval*inva->ptr.pp_double[updcolumn][updrow];
    
    /*
     * InvA = InvA - correction
     */
    for(i=0; i<=n-1; i++)
    {
        vt = updval*t1.ptr.p_double[i];
        vt = vt/(1+lambdav);
        ae_v_subd(&inva->ptr.pp_double[i][0], 1, &t2.ptr.p_double[0], 1, ae_v_len(0,n-1), vt);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm updates matrix A^-1 when adding a vector to a row
of matrix A.

Input parameters:
    InvA    -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    UpdRow  -   the row of A whose vector V was added.
                0 <= Row <= N-1
    V       -   the vector to be added to a row.
                Array whose index ranges within [0..N-1].

Output parameters:
    InvA    -   inverse of modified matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdaterow(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     ae_int_t updrow,
     /* Real    */ ae_vector* v,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector t1;
    ae_vector t2;
    ae_int_t i;
    ae_int_t j;
    double lambdav;
    double vt;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&t1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t2, 0, DT_REAL, _state, ae_true);

    ae_vector_set_length(&t1, n-1+1, _state);
    ae_vector_set_length(&t2, n-1+1, _state);
    
    /*
     * T1 = InvA * U
     */
    ae_v_move(&t1.ptr.p_double[0], 1, &inva->ptr.pp_double[0][updrow], inva->stride, ae_v_len(0,n-1));
    
    /*
     * T2 = v*InvA
     * Lambda = v * InvA * U
     */
    for(j=0; j<=n-1; j++)
    {
        vt = ae_v_dotproduct(&v->ptr.p_double[0], 1, &inva->ptr.pp_double[0][j], inva->stride, ae_v_len(0,n-1));
        t2.ptr.p_double[j] = vt;
    }
    lambdav = t2.ptr.p_double[updrow];
    
    /*
     * InvA = InvA - correction
     */
    for(i=0; i<=n-1; i++)
    {
        vt = t1.ptr.p_double[i]/(1+lambdav);
        ae_v_subd(&inva->ptr.pp_double[i][0], 1, &t2.ptr.p_double[0], 1, ae_v_len(0,n-1), vt);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm updates matrix A^-1 when adding a vector to a column
of matrix A.

Input parameters:
    InvA        -   inverse of matrix A.
                    Array whose indexes range within [0..N-1, 0..N-1].
    N           -   size of matrix A.
    UpdColumn   -   the column of A whose vector U was added.
                    0 <= UpdColumn <= N-1
    U           -   the vector to be added to a column.
                    Array whose index ranges within [0..N-1].

Output parameters:
    InvA        -   inverse of modified matrix A.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdatecolumn(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     ae_int_t updcolumn,
     /* Real    */ ae_vector* u,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector t1;
    ae_vector t2;
    ae_int_t i;
    double lambdav;
    double vt;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&t1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t2, 0, DT_REAL, _state, ae_true);

    ae_vector_set_length(&t1, n-1+1, _state);
    ae_vector_set_length(&t2, n-1+1, _state);
    
    /*
     * T1 = InvA * U
     * Lambda = v * InvA * U
     */
    for(i=0; i<=n-1; i++)
    {
        vt = ae_v_dotproduct(&inva->ptr.pp_double[i][0], 1, &u->ptr.p_double[0], 1, ae_v_len(0,n-1));
        t1.ptr.p_double[i] = vt;
    }
    lambdav = t1.ptr.p_double[updcolumn];
    
    /*
     * T2 = v*InvA
     */
    ae_v_move(&t2.ptr.p_double[0], 1, &inva->ptr.pp_double[updcolumn][0], 1, ae_v_len(0,n-1));
    
    /*
     * InvA = InvA - correction
     */
    for(i=0; i<=n-1; i++)
    {
        vt = t1.ptr.p_double[i]/(1+lambdav);
        ae_v_subd(&inva->ptr.pp_double[i][0], 1, &t2.ptr.p_double[0], 1, ae_v_len(0,n-1), vt);
    }
    ae_frame_leave(_state);
}


/*************************************************************************
Inverse matrix update by the Sherman-Morrison formula

The algorithm computes the inverse of matrix A+u*v� by using the given matrix
A^-1 and the vectors u and v.

Input parameters:
    InvA    -   inverse of matrix A.
                Array whose indexes range within [0..N-1, 0..N-1].
    N       -   size of matrix A.
    U       -   the vector modifying the matrix.
                Array whose index ranges within [0..N-1].
    V       -   the vector modifying the matrix.
                Array whose index ranges within [0..N-1].

Output parameters:
    InvA - inverse of matrix A + u*v'.

  -- ALGLIB --
     Copyright 2005 by Bochkanov Sergey
*************************************************************************/
void rmatrixinvupdateuv(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     /* Real    */ ae_vector* u,
     /* Real    */ ae_vector* v,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector t1;
    ae_vector t2;
    ae_int_t i;
    ae_int_t j;
    double lambdav;
    double vt;

    ae_frame_make(_state, &_frame_block);
    ae_vector_init(&t1, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&t2, 0, DT_REAL, _state, ae_true);

    ae_vector_set_length(&t1, n-1+1, _state);
    ae_vector_set_length(&t2, n-1+1, _state);
    
    /*
     * T1 = InvA * U
     * Lambda = v * T1
     */
    for(i=0; i<=n-1; i++)
    {
        vt = ae_v_dotproduct(&inva->ptr.pp_double[i][0], 1, &u->ptr.p_double[0], 1, ae_v_len(0,n-1));
        t1.ptr.p_double[i] = vt;
    }
    lambdav = ae_v_dotproduct(&v->ptr.p_double[0], 1, &t1.ptr.p_double[0], 1, ae_v_len(0,n-1));
    
    /*
     * T2 = v*InvA
     */
    for(j=0; j<=n-1; j++)
    {
        vt = ae_v_dotproduct(&v->ptr.p_double[0], 1, &inva->ptr.pp_double[0][j], inva->stride, ae_v_len(0,n-1));
        t2.ptr.p_double[j] = vt;
    }
    
    /*
     * InvA = InvA - correction
     */
    for(i=0; i<=n-1; i++)
    {
        vt = t1.ptr.p_double[i]/(1+lambdav);
        ae_v_subd(&inva->ptr.pp_double[i][0], 1, &t2.ptr.p_double[0], 1, ae_v_len(0,n-1), vt);
    }
    ae_frame_leave(_state);
}




/*************************************************************************
Subroutine performing the Schur decomposition of a general matrix by using
the QR algorithm with multiple shifts.

The source matrix A is represented as S'*A*S = T, where S is an orthogonal
matrix (Schur vectors), T - upper quasi-triangular matrix (with blocks of
sizes 1x1 and 2x2 on the main diagonal).

Input parameters:
    A   -   matrix to be decomposed.
            Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of A, N>=0.


Output parameters:
    A   -   contains matrix T.
            Array whose indexes range within [0..N-1, 0..N-1].
    S   -   contains Schur vectors.
            Array whose indexes range within [0..N-1, 0..N-1].

Note 1:
    The block structure of matrix T can be easily recognized: since all
    the elements below the blocks are zeros, the elements a[i+1,i] which
    are equal to 0 show the block border.

Note 2:
    The algorithm performance depends on the value of the internal parameter
    NS of the InternalSchurDecomposition subroutine which defines the number
    of shifts in the QR algorithm (similarly to the block width in block-matrix
    algorithms in linear algebra). If you require maximum performance on
    your machine, it is recommended to adjust this parameter manually.

Result:
    True,
        if the algorithm has converged and parameters A and S contain the result.
    False,
        if the algorithm has not converged.

Algorithm implemented on the basis of the DHSEQR subroutine (LAPACK 3.0 library).
*************************************************************************/
ae_bool rmatrixschur(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_matrix* s,
     ae_state *_state)
{
    ae_frame _frame_block;
    ae_vector tau;
    ae_vector wi;
    ae_vector wr;
    ae_matrix a1;
    ae_matrix s1;
    ae_int_t info;
    ae_int_t i;
    ae_int_t j;
    ae_bool result;

    ae_frame_make(_state, &_frame_block);
    ae_matrix_clear(s);
    ae_vector_init(&tau, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&wi, 0, DT_REAL, _state, ae_true);
    ae_vector_init(&wr, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&a1, 0, 0, DT_REAL, _state, ae_true);
    ae_matrix_init(&s1, 0, 0, DT_REAL, _state, ae_true);

    
    /*
     * Upper Hessenberg form of the 0-based matrix
     */
    rmatrixhessenberg(a, n, &tau, _state);
    rmatrixhessenbergunpackq(a, n, &tau, s, _state);
    
    /*
     * Convert from 0-based arrays to 1-based,
     * then call InternalSchurDecomposition
     * Awkward, of course, but Schur decompisiton subroutine
     * is too complex to fix it.
     *
     */
    ae_matrix_set_length(&a1, n+1, n+1, _state);
    ae_matrix_set_length(&s1, n+1, n+1, _state);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a1.ptr.pp_double[i][j] = a->ptr.pp_double[i-1][j-1];
            s1.ptr.pp_double[i][j] = s->ptr.pp_double[i-1][j-1];
        }
    }
    internalschurdecomposition(&a1, n, 1, 1, &wr, &wi, &s1, &info, _state);
    result = info==0;
    
    /*
     * convert from 1-based arrays to -based
     */
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a->ptr.pp_double[i-1][j-1] = a1.ptr.pp_double[i][j];
            s->ptr.pp_double[i-1][j-1] = s1.ptr.pp_double[i][j];
        }
    }
    ae_frame_leave(_state);
    return result;
}



}

