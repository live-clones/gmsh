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
#ifndef _linalg_pkg_h
#define _linalg_pkg_h
#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS COMPUTATIONAL CORE DECLARATIONS (DATATYPES)
//
/////////////////////////////////////////////////////////////////////////
namespace alglib_impl
{
typedef struct
{
    double r1;
    double rinf;
} matinvreport;
typedef struct
{
    double e1;
    double e2;
    ae_vector x;
    ae_vector ax;
    double xax;
    ae_int_t n;
    ae_vector rk;
    ae_vector rk1;
    ae_vector xk;
    ae_vector xk1;
    ae_vector pk;
    ae_vector pk1;
    ae_vector b;
    rcommstate rstate;
    ae_vector tmp2;
} fblslincgstate;

}

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS C++ INTERFACE
//
/////////////////////////////////////////////////////////////////////////
namespace alglib
{













/*************************************************************************
Matrix inverse report:
* R1    reciprocal of condition number in 1-norm
* RInf  reciprocal of condition number in inf-norm
*************************************************************************/
class _matinvreport_owner
{
public:
    _matinvreport_owner();
    _matinvreport_owner(const _matinvreport_owner &rhs);
    _matinvreport_owner& operator=(const _matinvreport_owner &rhs);
    virtual ~_matinvreport_owner();
    alglib_impl::matinvreport* c_ptr();
    alglib_impl::matinvreport* c_ptr() const;
protected:
    alglib_impl::matinvreport *p_struct;
};
class matinvreport : public _matinvreport_owner
{
public:
    matinvreport();
    matinvreport(const matinvreport &rhs);
    matinvreport& operator=(const matinvreport &rhs);
    virtual ~matinvreport();
    double &r1;
    double &rinf;

};

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
void cmatrixtranspose(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, complex_2d_array &b, const ae_int_t ib, const ae_int_t jb);


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
void rmatrixtranspose(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, real_2d_array &b, const ae_int_t ib, const ae_int_t jb);


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
void cmatrixcopy(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, complex_2d_array &b, const ae_int_t ib, const ae_int_t jb);


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
void rmatrixcopy(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, real_2d_array &b, const ae_int_t ib, const ae_int_t jb);


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
void cmatrixrank1(const ae_int_t m, const ae_int_t n, complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, complex_1d_array &u, const ae_int_t iu, complex_1d_array &v, const ae_int_t iv);


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
void rmatrixrank1(const ae_int_t m, const ae_int_t n, real_2d_array &a, const ae_int_t ia, const ae_int_t ja, real_1d_array &u, const ae_int_t iu, real_1d_array &v, const ae_int_t iv);


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
void cmatrixmv(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t opa, const complex_1d_array &x, const ae_int_t ix, complex_1d_array &y, const ae_int_t iy);


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
void rmatrixmv(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t opa, const real_1d_array &x, const ae_int_t ix, real_1d_array &y, const ae_int_t iy);


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
void cmatrixrighttrsm(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, complex_2d_array &x, const ae_int_t i2, const ae_int_t j2);


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
void cmatrixlefttrsm(const ae_int_t m, const ae_int_t n, const complex_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, complex_2d_array &x, const ae_int_t i2, const ae_int_t j2);


/*************************************************************************
Same as CMatrixRightTRSM, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixrighttrsm(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, real_2d_array &x, const ae_int_t i2, const ae_int_t j2);


/*************************************************************************
Same as CMatrixLeftTRSM, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     15.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixlefttrsm(const ae_int_t m, const ae_int_t n, const real_2d_array &a, const ae_int_t i1, const ae_int_t j1, const bool isupper, const bool isunit, const ae_int_t optype, real_2d_array &x, const ae_int_t i2, const ae_int_t j2);


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
void cmatrixsyrk(const ae_int_t n, const ae_int_t k, const double alpha, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const double beta, complex_2d_array &c, const ae_int_t ic, const ae_int_t jc, const bool isupper);


/*************************************************************************
Same as CMatrixSYRK, but for real matrices

OpType may be only 0 or 1.

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixsyrk(const ae_int_t n, const ae_int_t k, const double alpha, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const double beta, real_2d_array &c, const ae_int_t ic, const ae_int_t jc, const bool isupper);


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
void cmatrixgemm(const ae_int_t m, const ae_int_t n, const ae_int_t k, const alglib::complex alpha, const complex_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const complex_2d_array &b, const ae_int_t ib, const ae_int_t jb, const ae_int_t optypeb, const alglib::complex beta, complex_2d_array &c, const ae_int_t ic, const ae_int_t jc);


/*************************************************************************
Same as CMatrixGEMM, but for real numbers.
OpType may be only 0 or 1.

  -- ALGLIB routine --
     16.12.2009
     Bochkanov Sergey
*************************************************************************/
void rmatrixgemm(const ae_int_t m, const ae_int_t n, const ae_int_t k, const double alpha, const real_2d_array &a, const ae_int_t ia, const ae_int_t ja, const ae_int_t optypea, const real_2d_array &b, const ae_int_t ib, const ae_int_t jb, const ae_int_t optypeb, const double beta, real_2d_array &c, const ae_int_t ic, const ae_int_t jc);

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
void rmatrixqr(real_2d_array &a, const ae_int_t m, const ae_int_t n, real_1d_array &tau);


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
void rmatrixlq(real_2d_array &a, const ae_int_t m, const ae_int_t n, real_1d_array &tau);


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
void cmatrixqr(complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_1d_array &tau);


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
void cmatrixlq(complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_1d_array &tau);


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
void rmatrixqrunpackq(const real_2d_array &a, const ae_int_t m, const ae_int_t n, const real_1d_array &tau, const ae_int_t qcolumns, real_2d_array &q);


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
void rmatrixqrunpackr(const real_2d_array &a, const ae_int_t m, const ae_int_t n, real_2d_array &r);


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
void rmatrixlqunpackq(const real_2d_array &a, const ae_int_t m, const ae_int_t n, const real_1d_array &tau, const ae_int_t qrows, real_2d_array &q);


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
void rmatrixlqunpackl(const real_2d_array &a, const ae_int_t m, const ae_int_t n, real_2d_array &l);


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
void cmatrixqrunpackq(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, const complex_1d_array &tau, const ae_int_t qcolumns, complex_2d_array &q);


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
void cmatrixqrunpackr(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_2d_array &r);


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
void cmatrixlqunpackq(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, const complex_1d_array &tau, const ae_int_t qrows, complex_2d_array &q);


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
void cmatrixlqunpackl(const complex_2d_array &a, const ae_int_t m, const ae_int_t n, complex_2d_array &l);


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
void rmatrixbd(real_2d_array &a, const ae_int_t m, const ae_int_t n, real_1d_array &tauq, real_1d_array &taup);


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
void rmatrixbdunpackq(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &tauq, const ae_int_t qcolumns, real_2d_array &q);


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
void rmatrixbdmultiplybyq(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &tauq, real_2d_array &z, const ae_int_t zrows, const ae_int_t zcolumns, const bool fromtheright, const bool dotranspose);


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
void rmatrixbdunpackpt(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &taup, const ae_int_t ptrows, real_2d_array &pt);


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
void rmatrixbdmultiplybyp(const real_2d_array &qp, const ae_int_t m, const ae_int_t n, const real_1d_array &taup, real_2d_array &z, const ae_int_t zrows, const ae_int_t zcolumns, const bool fromtheright, const bool dotranspose);


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
void rmatrixbdunpackdiagonals(const real_2d_array &b, const ae_int_t m, const ae_int_t n, bool &isupper, real_1d_array &d, real_1d_array &e);


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
void rmatrixhessenberg(real_2d_array &a, const ae_int_t n, real_1d_array &tau);


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
void rmatrixhessenbergunpackq(const real_2d_array &a, const ae_int_t n, const real_1d_array &tau, real_2d_array &q);


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
void rmatrixhessenbergunpackh(const real_2d_array &a, const ae_int_t n, real_2d_array &h);


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
void smatrixtd(real_2d_array &a, const ae_int_t n, const bool isupper, real_1d_array &tau, real_1d_array &d, real_1d_array &e);


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
void smatrixtdunpackq(const real_2d_array &a, const ae_int_t n, const bool isupper, const real_1d_array &tau, real_2d_array &q);


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
void hmatrixtd(complex_2d_array &a, const ae_int_t n, const bool isupper, complex_1d_array &tau, real_1d_array &d, real_1d_array &e);


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
void hmatrixtdunpackq(const complex_2d_array &a, const ae_int_t n, const bool isupper, const complex_1d_array &tau, complex_2d_array &q);

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
bool smatrixevd(const real_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, real_1d_array &d, real_2d_array &z);


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
bool smatrixevdr(const real_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const double b1, const double b2, ae_int_t &m, real_1d_array &w, real_2d_array &z);


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
bool smatrixevdi(const real_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const ae_int_t i1, const ae_int_t i2, real_1d_array &w, real_2d_array &z);


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
bool hmatrixevd(const complex_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, real_1d_array &d, complex_2d_array &z);


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
bool hmatrixevdr(const complex_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const double b1, const double b2, ae_int_t &m, real_1d_array &w, complex_2d_array &z);


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
bool hmatrixevdi(const complex_2d_array &a, const ae_int_t n, const ae_int_t zneeded, const bool isupper, const ae_int_t i1, const ae_int_t i2, real_1d_array &w, complex_2d_array &z);


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
bool smatrixtdevd(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const ae_int_t zneeded, real_2d_array &z);


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
bool smatrixtdevdr(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const ae_int_t zneeded, const double a, const double b, ae_int_t &m, real_2d_array &z);


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
bool smatrixtdevdi(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const ae_int_t zneeded, const ae_int_t i1, const ae_int_t i2, real_2d_array &z);


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
bool rmatrixevd(const real_2d_array &a, const ae_int_t n, const ae_int_t vneeded, real_1d_array &wr, real_1d_array &wi, real_2d_array &vl, real_2d_array &vr);

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
void rmatrixrndorthogonal(const ae_int_t n, real_2d_array &a);


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
void rmatrixrndcond(const ae_int_t n, const double c, real_2d_array &a);


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
void cmatrixrndorthogonal(const ae_int_t n, complex_2d_array &a);


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
void cmatrixrndcond(const ae_int_t n, const double c, complex_2d_array &a);


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
void smatrixrndcond(const ae_int_t n, const double c, real_2d_array &a);


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
void spdmatrixrndcond(const ae_int_t n, const double c, real_2d_array &a);


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
void hmatrixrndcond(const ae_int_t n, const double c, complex_2d_array &a);


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
void hpdmatrixrndcond(const ae_int_t n, const double c, complex_2d_array &a);


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
void rmatrixrndorthogonalfromtheright(real_2d_array &a, const ae_int_t m, const ae_int_t n);


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
void rmatrixrndorthogonalfromtheleft(real_2d_array &a, const ae_int_t m, const ae_int_t n);


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
void cmatrixrndorthogonalfromtheright(complex_2d_array &a, const ae_int_t m, const ae_int_t n);


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
void cmatrixrndorthogonalfromtheleft(complex_2d_array &a, const ae_int_t m, const ae_int_t n);


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
void smatrixrndmultiply(real_2d_array &a, const ae_int_t n);


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
void hmatrixrndmultiply(complex_2d_array &a, const ae_int_t n);

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
void rmatrixlu(real_2d_array &a, const ae_int_t m, const ae_int_t n, integer_1d_array &pivots);


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
void cmatrixlu(complex_2d_array &a, const ae_int_t m, const ae_int_t n, integer_1d_array &pivots);


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
bool hpdmatrixcholesky(complex_2d_array &a, const ae_int_t n, const bool isupper);


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
bool spdmatrixcholesky(real_2d_array &a, const ae_int_t n, const bool isupper);

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
double rmatrixrcond1(const real_2d_array &a, const ae_int_t n);


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
double rmatrixrcondinf(const real_2d_array &a, const ae_int_t n);


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
double spdmatrixrcond(const real_2d_array &a, const ae_int_t n, const bool isupper);


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
double rmatrixtrrcond1(const real_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit);


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
double rmatrixtrrcondinf(const real_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit);


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
double hpdmatrixrcond(const complex_2d_array &a, const ae_int_t n, const bool isupper);


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
double cmatrixrcond1(const complex_2d_array &a, const ae_int_t n);


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
double cmatrixrcondinf(const complex_2d_array &a, const ae_int_t n);


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
double rmatrixlurcond1(const real_2d_array &lua, const ae_int_t n);


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
double rmatrixlurcondinf(const real_2d_array &lua, const ae_int_t n);


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
double spdmatrixcholeskyrcond(const real_2d_array &a, const ae_int_t n, const bool isupper);


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
double hpdmatrixcholeskyrcond(const complex_2d_array &a, const ae_int_t n, const bool isupper);


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
double cmatrixlurcond1(const complex_2d_array &lua, const ae_int_t n);


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
double cmatrixlurcondinf(const complex_2d_array &lua, const ae_int_t n);


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
double cmatrixtrrcond1(const complex_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit);


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
double cmatrixtrrcondinf(const complex_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit);

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
void rmatrixluinverse(real_2d_array &a, const integer_1d_array &pivots, const ae_int_t n, ae_int_t &info, matinvreport &rep);
void rmatrixluinverse(real_2d_array &a, const integer_1d_array &pivots, ae_int_t &info, matinvreport &rep);


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
void rmatrixinverse(real_2d_array &a, const ae_int_t n, ae_int_t &info, matinvreport &rep);
void rmatrixinverse(real_2d_array &a, ae_int_t &info, matinvreport &rep);


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
void cmatrixluinverse(complex_2d_array &a, const integer_1d_array &pivots, const ae_int_t n, ae_int_t &info, matinvreport &rep);
void cmatrixluinverse(complex_2d_array &a, const integer_1d_array &pivots, ae_int_t &info, matinvreport &rep);


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
void cmatrixinverse(complex_2d_array &a, const ae_int_t n, ae_int_t &info, matinvreport &rep);
void cmatrixinverse(complex_2d_array &a, ae_int_t &info, matinvreport &rep);


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
void spdmatrixcholeskyinverse(real_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep);
void spdmatrixcholeskyinverse(real_2d_array &a, ae_int_t &info, matinvreport &rep);


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
void spdmatrixinverse(real_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep);
void spdmatrixinverse(real_2d_array &a, ae_int_t &info, matinvreport &rep);


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
void hpdmatrixcholeskyinverse(complex_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep);
void hpdmatrixcholeskyinverse(complex_2d_array &a, ae_int_t &info, matinvreport &rep);


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
void hpdmatrixinverse(complex_2d_array &a, const ae_int_t n, const bool isupper, ae_int_t &info, matinvreport &rep);
void hpdmatrixinverse(complex_2d_array &a, ae_int_t &info, matinvreport &rep);


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
void rmatrixtrinverse(real_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit, ae_int_t &info, matinvreport &rep);
void rmatrixtrinverse(real_2d_array &a, const bool isupper, ae_int_t &info, matinvreport &rep);


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
void cmatrixtrinverse(complex_2d_array &a, const ae_int_t n, const bool isupper, const bool isunit, ae_int_t &info, matinvreport &rep);
void cmatrixtrinverse(complex_2d_array &a, const bool isupper, ae_int_t &info, matinvreport &rep);

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
bool rmatrixbdsvd(real_1d_array &d, const real_1d_array &e, const ae_int_t n, const bool isupper, const bool isfractionalaccuracyrequired, real_2d_array &u, const ae_int_t nru, real_2d_array &c, const ae_int_t ncc, real_2d_array &vt, const ae_int_t ncvt);

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
bool rmatrixsvd(const real_2d_array &a, const ae_int_t m, const ae_int_t n, const ae_int_t uneeded, const ae_int_t vtneeded, const ae_int_t additionalmemory, real_1d_array &w, real_2d_array &u, real_2d_array &vt);



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
double rmatrixludet(const real_2d_array &a, const integer_1d_array &pivots, const ae_int_t n);
double rmatrixludet(const real_2d_array &a, const integer_1d_array &pivots);


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
double rmatrixdet(const real_2d_array &a, const ae_int_t n);
double rmatrixdet(const real_2d_array &a);


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
alglib::complex cmatrixludet(const complex_2d_array &a, const integer_1d_array &pivots, const ae_int_t n);
alglib::complex cmatrixludet(const complex_2d_array &a, const integer_1d_array &pivots);


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
alglib::complex cmatrixdet(const complex_2d_array &a, const ae_int_t n);
alglib::complex cmatrixdet(const complex_2d_array &a);


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
double spdmatrixcholeskydet(const real_2d_array &a, const ae_int_t n);
double spdmatrixcholeskydet(const real_2d_array &a);


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
double spdmatrixdet(const real_2d_array &a, const ae_int_t n, const bool isupper);
double spdmatrixdet(const real_2d_array &a);

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
bool smatrixgevd(const real_2d_array &a, const ae_int_t n, const bool isuppera, const real_2d_array &b, const bool isupperb, const ae_int_t zneeded, const ae_int_t problemtype, real_1d_array &d, real_2d_array &z);


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
bool smatrixgevdreduce(real_2d_array &a, const ae_int_t n, const bool isuppera, const real_2d_array &b, const bool isupperb, const ae_int_t problemtype, real_2d_array &r, bool &isupperr);

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
void rmatrixinvupdatesimple(real_2d_array &inva, const ae_int_t n, const ae_int_t updrow, const ae_int_t updcolumn, const double updval);


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
void rmatrixinvupdaterow(real_2d_array &inva, const ae_int_t n, const ae_int_t updrow, const real_1d_array &v);


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
void rmatrixinvupdatecolumn(real_2d_array &inva, const ae_int_t n, const ae_int_t updcolumn, const real_1d_array &u);


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
void rmatrixinvupdateuv(real_2d_array &inva, const ae_int_t n, const real_1d_array &u, const real_1d_array &v);

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
bool rmatrixschur(real_2d_array &a, const ae_int_t n, real_2d_array &s);
}

/////////////////////////////////////////////////////////////////////////
//
// THIS SECTION CONTAINS COMPUTATIONAL CORE DECLARATIONS (FUNCTIONS)
//
/////////////////////////////////////////////////////////////////////////
namespace alglib_impl
{
void ablassplitlength(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* n1,
     ae_int_t* n2,
     ae_state *_state);
void ablascomplexsplitlength(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* n1,
     ae_int_t* n2,
     ae_state *_state);
ae_int_t ablasblocksize(/* Real    */ ae_matrix* a, ae_state *_state);
ae_int_t ablascomplexblocksize(/* Complex */ ae_matrix* a,
     ae_state *_state);
ae_int_t ablasmicroblocksize(ae_state *_state);
void cmatrixtranspose(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Complex */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state);
void rmatrixtranspose(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Real    */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state);
void cmatrixcopy(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Complex */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state);
void rmatrixcopy(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Real    */ ae_matrix* b,
     ae_int_t ib,
     ae_int_t jb,
     ae_state *_state);
void cmatrixrank1(ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Complex */ ae_vector* u,
     ae_int_t iu,
     /* Complex */ ae_vector* v,
     ae_int_t iv,
     ae_state *_state);
void rmatrixrank1(ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_int_t ia,
     ae_int_t ja,
     /* Real    */ ae_vector* u,
     ae_int_t iu,
     /* Real    */ ae_vector* v,
     ae_int_t iv,
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
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
     ae_state *_state);
void rmatrixqr(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state);
void rmatrixlq(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state);
void cmatrixqr(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_state *_state);
void cmatrixlq(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_state *_state);
void rmatrixqrunpackq(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_int_t qcolumns,
     /* Real    */ ae_matrix* q,
     ae_state *_state);
void rmatrixqrunpackr(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* r,
     ae_state *_state);
void rmatrixlqunpackq(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_int_t qrows,
     /* Real    */ ae_matrix* q,
     ae_state *_state);
void rmatrixlqunpackl(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_matrix* l,
     ae_state *_state);
void cmatrixqrunpackq(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_int_t qcolumns,
     /* Complex */ ae_matrix* q,
     ae_state *_state);
void cmatrixqrunpackr(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* r,
     ae_state *_state);
void cmatrixlqunpackq(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_vector* tau,
     ae_int_t qrows,
     /* Complex */ ae_matrix* q,
     ae_state *_state);
void cmatrixlqunpackl(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Complex */ ae_matrix* l,
     ae_state *_state);
void rmatrixbd(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tauq,
     /* Real    */ ae_vector* taup,
     ae_state *_state);
void rmatrixbdunpackq(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tauq,
     ae_int_t qcolumns,
     /* Real    */ ae_matrix* q,
     ae_state *_state);
void rmatrixbdmultiplybyq(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* tauq,
     /* Real    */ ae_matrix* z,
     ae_int_t zrows,
     ae_int_t zcolumns,
     ae_bool fromtheright,
     ae_bool dotranspose,
     ae_state *_state);
void rmatrixbdunpackpt(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* taup,
     ae_int_t ptrows,
     /* Real    */ ae_matrix* pt,
     ae_state *_state);
void rmatrixbdmultiplybyp(/* Real    */ ae_matrix* qp,
     ae_int_t m,
     ae_int_t n,
     /* Real    */ ae_vector* taup,
     /* Real    */ ae_matrix* z,
     ae_int_t zrows,
     ae_int_t zcolumns,
     ae_bool fromtheright,
     ae_bool dotranspose,
     ae_state *_state);
void rmatrixbdunpackdiagonals(/* Real    */ ae_matrix* b,
     ae_int_t m,
     ae_int_t n,
     ae_bool* isupper,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_state *_state);
void rmatrixhessenberg(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     ae_state *_state);
void rmatrixhessenbergunpackq(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_matrix* q,
     ae_state *_state);
void rmatrixhessenbergunpackh(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_matrix* h,
     ae_state *_state);
void smatrixtd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_state *_state);
void smatrixtdunpackq(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tau,
     /* Real    */ ae_matrix* q,
     ae_state *_state);
void hmatrixtd(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tau,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_state *_state);
void hmatrixtdunpackq(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     /* Complex */ ae_vector* tau,
     /* Complex */ ae_matrix* q,
     ae_state *_state);
ae_bool smatrixevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
ae_bool smatrixevdr(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     double b1,
     double b2,
     ae_int_t* m,
     /* Real    */ ae_vector* w,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
ae_bool smatrixevdi(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     ae_int_t i1,
     ae_int_t i2,
     /* Real    */ ae_vector* w,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
ae_bool hmatrixevd(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     /* Real    */ ae_vector* d,
     /* Complex */ ae_matrix* z,
     ae_state *_state);
ae_bool hmatrixevdr(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     double b1,
     double b2,
     ae_int_t* m,
     /* Real    */ ae_vector* w,
     /* Complex */ ae_matrix* z,
     ae_state *_state);
ae_bool hmatrixevdi(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t zneeded,
     ae_bool isupper,
     ae_int_t i1,
     ae_int_t i2,
     /* Real    */ ae_vector* w,
     /* Complex */ ae_matrix* z,
     ae_state *_state);
ae_bool smatrixtdevd(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
ae_bool smatrixtdevdr(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     double a,
     double b,
     ae_int_t* m,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
ae_bool smatrixtdevdi(/* Real    */ ae_vector* d,
     /* Real    */ ae_vector* e,
     ae_int_t n,
     ae_int_t zneeded,
     ae_int_t i1,
     ae_int_t i2,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
ae_bool rmatrixevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t vneeded,
     /* Real    */ ae_vector* wr,
     /* Real    */ ae_vector* wi,
     /* Real    */ ae_matrix* vl,
     /* Real    */ ae_matrix* vr,
     ae_state *_state);
void rmatrixrndorthogonal(ae_int_t n,
     /* Real    */ ae_matrix* a,
     ae_state *_state);
void rmatrixrndcond(ae_int_t n,
     double c,
     /* Real    */ ae_matrix* a,
     ae_state *_state);
void cmatrixrndorthogonal(ae_int_t n,
     /* Complex */ ae_matrix* a,
     ae_state *_state);
void cmatrixrndcond(ae_int_t n,
     double c,
     /* Complex */ ae_matrix* a,
     ae_state *_state);
void smatrixrndcond(ae_int_t n,
     double c,
     /* Real    */ ae_matrix* a,
     ae_state *_state);
void spdmatrixrndcond(ae_int_t n,
     double c,
     /* Real    */ ae_matrix* a,
     ae_state *_state);
void hmatrixrndcond(ae_int_t n,
     double c,
     /* Complex */ ae_matrix* a,
     ae_state *_state);
void hpdmatrixrndcond(ae_int_t n,
     double c,
     /* Complex */ ae_matrix* a,
     ae_state *_state);
void rmatrixrndorthogonalfromtheright(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state);
void rmatrixrndorthogonalfromtheleft(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state);
void cmatrixrndorthogonalfromtheright(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state);
void cmatrixrndorthogonalfromtheleft(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_state *_state);
void smatrixrndmultiply(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
void hmatrixrndmultiply(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
void rmatrixlu(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state);
void cmatrixlu(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state);
ae_bool hpdmatrixcholesky(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state);
ae_bool spdmatrixcholesky(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state);
void rmatrixlup(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state);
void cmatrixlup(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state);
void rmatrixplu(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state);
void cmatrixplu(/* Complex */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     /* Integer */ ae_vector* pivots,
     ae_state *_state);
ae_bool spdmatrixcholeskyrec(/* Real    */ ae_matrix* a,
     ae_int_t offs,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);
double rmatrixrcond1(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
double rmatrixrcondinf(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
double spdmatrixrcond(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state);
double rmatrixtrrcond1(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state);
double rmatrixtrrcondinf(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state);
double hpdmatrixrcond(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state);
double cmatrixrcond1(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
double cmatrixrcondinf(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
double rmatrixlurcond1(/* Real    */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state);
double rmatrixlurcondinf(/* Real    */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state);
double spdmatrixcholeskyrcond(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state);
double hpdmatrixcholeskyrcond(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state);
double cmatrixlurcond1(/* Complex */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state);
double cmatrixlurcondinf(/* Complex */ ae_matrix* lua,
     ae_int_t n,
     ae_state *_state);
double cmatrixtrrcond1(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state);
double cmatrixtrrcondinf(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_state *_state);
double rcondthreshold(ae_state *_state);
void rmatrixluinverse(/* Real    */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void rmatrixinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void cmatrixluinverse(/* Complex */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void cmatrixinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void spdmatrixcholeskyinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void spdmatrixinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void hpdmatrixcholeskyinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void hpdmatrixinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void rmatrixtrinverse(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
void cmatrixtrinverse(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_bool isunit,
     ae_int_t* info,
     matinvreport* rep,
     ae_state *_state);
ae_bool _matinvreport_init(matinvreport* p, ae_state *_state, ae_bool make_automatic);
ae_bool _matinvreport_init_copy(matinvreport* dst, matinvreport* src, ae_state *_state, ae_bool make_automatic);
void _matinvreport_clear(matinvreport* p);
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
     ae_state *_state);
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
     ae_state *_state);
ae_bool rmatrixsvd(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     ae_int_t uneeded,
     ae_int_t vtneeded,
     ae_int_t additionalmemory,
     /* Real    */ ae_vector* w,
     /* Real    */ ae_matrix* u,
     /* Real    */ ae_matrix* vt,
     ae_state *_state);
void fblscholeskysolve(/* Real    */ ae_matrix* cha,
     double sqrtscalea,
     ae_int_t n,
     ae_bool isupper,
     /* Real    */ ae_vector* xb,
     /* Real    */ ae_vector* tmp,
     ae_state *_state);
void fblssolvecgx(/* Real    */ ae_matrix* a,
     ae_int_t m,
     ae_int_t n,
     double alpha,
     /* Real    */ ae_vector* b,
     /* Real    */ ae_vector* x,
     /* Real    */ ae_vector* buf,
     ae_state *_state);
void fblscgcreate(/* Real    */ ae_vector* x,
     /* Real    */ ae_vector* b,
     ae_int_t n,
     fblslincgstate* state,
     ae_state *_state);
ae_bool fblscgiteration(fblslincgstate* state, ae_state *_state);
ae_bool _fblslincgstate_init(fblslincgstate* p, ae_state *_state, ae_bool make_automatic);
ae_bool _fblslincgstate_init_copy(fblslincgstate* dst, fblslincgstate* src, ae_state *_state, ae_bool make_automatic);
void _fblslincgstate_clear(fblslincgstate* p);
double rmatrixludet(/* Real    */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_state *_state);
double rmatrixdet(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
ae_complex cmatrixludet(/* Complex */ ae_matrix* a,
     /* Integer */ ae_vector* pivots,
     ae_int_t n,
     ae_state *_state);
ae_complex cmatrixdet(/* Complex */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
double spdmatrixcholeskydet(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_state *_state);
double spdmatrixdet(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isupper,
     ae_state *_state);
ae_bool smatrixgevd(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isuppera,
     /* Real    */ ae_matrix* b,
     ae_bool isupperb,
     ae_int_t zneeded,
     ae_int_t problemtype,
     /* Real    */ ae_vector* d,
     /* Real    */ ae_matrix* z,
     ae_state *_state);
ae_bool smatrixgevdreduce(/* Real    */ ae_matrix* a,
     ae_int_t n,
     ae_bool isuppera,
     /* Real    */ ae_matrix* b,
     ae_bool isupperb,
     ae_int_t problemtype,
     /* Real    */ ae_matrix* r,
     ae_bool* isupperr,
     ae_state *_state);
void rmatrixinvupdatesimple(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     ae_int_t updrow,
     ae_int_t updcolumn,
     double updval,
     ae_state *_state);
void rmatrixinvupdaterow(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     ae_int_t updrow,
     /* Real    */ ae_vector* v,
     ae_state *_state);
void rmatrixinvupdatecolumn(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     ae_int_t updcolumn,
     /* Real    */ ae_vector* u,
     ae_state *_state);
void rmatrixinvupdateuv(/* Real    */ ae_matrix* inva,
     ae_int_t n,
     /* Real    */ ae_vector* u,
     /* Real    */ ae_vector* v,
     ae_state *_state);
ae_bool rmatrixschur(/* Real    */ ae_matrix* a,
     ae_int_t n,
     /* Real    */ ae_matrix* s,
     ae_state *_state);

}
#endif

