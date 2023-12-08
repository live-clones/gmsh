/* Author: John Burkardt
 * Link:
 * https://people.sc.fsu.edu/~jburkardt/cpp_src/row_echelon_integer/row_echelon_integer.html
 * License: The computer code and data files made available on this web page are
 * distributed under the GNU LGPL license.
 *          https://www.gnu.org/licenses/lgpl-3.0.en.html */

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

#include "row_echelon_integer.hpp"

//****************************************************************************80

int i4_gcd(int i, int j)

//****************************************************************************80
//
//  Purpose:
//
//    I4_GCD finds the greatest common divisor of two I4's.
//
//  Discussion:
//
//    Note that only the absolute values of I and J are
//    considered, so that the result is always nonnegative.
//
//    If I or J is 0, I4_GCD is returned as max ( 1, abs ( I ), abs ( J ) ).
//
//    If I and J have no common factor, I4_GCD is returned as 1.
//
//    Otherwise, using the Euclidean algorithm, I4_GCD is the
//    greatest common divisor of I and J.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 March 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, J, two numbers whose GCD is desired.
//
//    Output, int I4_GCD, the greatest common divisor of I and J.
//
{
  int p;
  int q;
  int r;
  //
  //  Return immediately if either I or J is zero.
  //
  if(i == 0) {
    q = i4_max(1, abs(j));
    return q;
  }
  else if(j == 0) {
    q = i4_max(1, abs(i));
    return q;
  }
  //
  //  Set IP to the larger of I and J, IQ to the smaller.
  //  This way, we can alter IP and IQ as we go.
  //
  p = i4_max(abs(i), abs(j));
  q = i4_min(abs(i), abs(j));
  //
  //  Carry out the Euclidean algorithm.
  //
  for(;;) {
    r = p % q;

    if(r == 0) { break; }
    p = q;
    q = r;
  }

  return q;
}
//****************************************************************************80

int i4_max(int i1, int i2)

//****************************************************************************80
//
//  Purpose:
//
//    I4_MAX returns the maximum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, are two integers to be compared.
//
//    Output, int I4_MAX, the larger of I1 and I2.
//
{
  int value;

  if(i2 < i1) { value = i1; }
  else {
    value = i2;
  }
  return value;
}
//****************************************************************************80

int i4_min(int i1, int i2)

//****************************************************************************80
//
//  Purpose:
//
//    I4_MIN returns the minimum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, two integers to be compared.
//
//    Output, int I4_MIN, the smaller of I1 and I2.
//
{
  int value;

  if(i1 < i2) { value = i1; }
  else {
    value = i2;
  }
  return value;
}
//****************************************************************************80

void i4mat_print(int m, int n, int a[], string title)

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_PRINT prints an I4MAT.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows in A.
//
//    Input, int N, the number of columns in A.
//
//    Input, int A[M*N], the M by N matrix.
//
//    Input, string TITLE, a title.
//
{
  i4mat_print_some(m, n, a, 1, 1, m, n, title);

  return;
}
//****************************************************************************80

void i4mat_print_some(int m, int n, int a[], int ilo, int jlo, int ihi, int jhi,
                      string title)

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_PRINT_SOME prints some of an I4MAT.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 August 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, int A[M*N], the matrix.
//
//    Input, int ILO, JLO, IHI, JHI, designate the first row and
//    column, and the last row and column to be printed.
//
//    Input, string TITLE, a title.
//
{
#define INCX 10

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  cout << "\n";
  cout << title << "\n";

  if(m <= 0 || n <= 0) {
    cout << "\n";
    cout << "  (None)\n";
    return;
  }
  //
  //  Print the columns of the matrix, in strips of INCX.
  //
  for(j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX) {
    j2hi = j2lo + INCX - 1;
    if(n < j2hi) { j2hi = n; }
    if(jhi < j2hi) { j2hi = jhi; }

    cout << "\n";
    //
    //  For each column J in the current range...
    //
    //  Write the header.
    //
    cout << "  Col:";
    for(j = j2lo; j <= j2hi; j++) { cout << "  " << setw(6) << j - 1; }
    cout << "\n";
    cout << "  Row\n";
    cout << "\n";
    //
    //  Determine the range of the rows in this strip.
    //
    if(1 < ilo) { i2lo = ilo; }
    else {
      i2lo = 1;
    }
    if(ihi < m) { i2hi = ihi; }
    else {
      i2hi = m;
    }

    for(i = i2lo; i <= i2hi; i++) {
      //
      //  Print out (up to INCX) entries in row I, that lie in the current
      //  strip.
      //
      cout << setw(5) << i - 1 << ":";
      for(j = j2lo; j <= j2hi; j++) {
        cout << "  " << setw(6) << a[i - 1 + (j - 1) * m];
      }
      cout << "\n";
    }
  }

  return;
#undef INCX
}
//****************************************************************************80

int i4mat_ref(int m, int n, int a[])

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_REF computes the integer row echelon form (IREF) of an I4MAT.
//
//  Discussion:
//
//    If a matrix A contains only integer entries, then when it is reduced
//    to row echelon form, it is likely that many entries will no longer
//    be integers, due to the elimination process.
//
//    In some cases, tiny arithmetic errors in this elimination process can
//    result in spurious, tiny nonzero values which can invalidate the
//    calculation, particular if the elimination is being done in an effort
//    to determine the rank of the matrix.  These serious errors can easily
//    occur in very small matrices, such as of size 7x10.
//
//    If we, instead, insist on using only integer operations on an integer
//    matrix, we can guarantee that tiny roundoff errors will not cause
//    such problems.  On the other hand, as the elimination process proceeds,
//    we may instead calculate integer matrix entries of increasingly
//    large, and then ultimately meaningless magnitude.  I imagine this is
//    likely to happen for moderate size matrices of order 50x50, say, but
//    this is a huge improvement over the unreliability of the real
//    arithmetic case.
//
//
//    Thus, we define "integer row echelon form" (IREF).
//
//
//    A matrix is in integer row echelon form if:
//
//    * The leading nonzero in each row is positive.
//
//    * Each row has no common factor greater than 1.
//
//    * The leading nonzero in each row occurs in a column to
//      the right of the leading nonzero in the previous row.
//
//    * Rows which are entirely zero occur last.
//
//  Example:
//
//    Input matrix:
//
//     1    3    0    2    6    3    1
//    -2   -6    0   -2   -8    3    1
//     3    9    0    0    6    6    2
//    -1   -3    0    1    0    9    3
//
//    Output matrix:
//
//     1    3    0    2    6    3    1
//     0    0    0    2    4    9    3
//     0    0    0    0    0    3    1
//     0    0    0    0    0    0    0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 August 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns of
//    the matrix A.
//
//    Input/output, int A[M*N].  On input, the matrix to be
//    analyzed.  On output, the IREF form of the matrix.
//
//    Output, int I4MAT_REF, the pseudo-determinant.
//
{
  int det;
  int i;
  int j;
  int lead;
  int r;
  int *row;
  int t;

  det = 1;
  lead = 0;

  row = new int[n];

  for(r = 0; r < m; r++) {
    if(n - 1 < lead) { break; }
    //
    //  Start I at row R, and search for nonzero pivot entry A(I,LEAD).
    //
    i = r;

    while(a[i + lead * m] == 0) {
      i = i + 1;
      //
      //  If reach last row, reset I to R, and increment LEAD.
      //
      if(m - 1 < i) {
        i = r;
        lead = lead + 1;
        //
        //  If reach last column, we can find no more pivots.
        //
        if(n - 1 < lead) {
          lead = -1;
          break;
        }
      }
    }

    if(lead < 0) { break; }
    //
    //  Move pivot I into row R.
    //
    if(i != r) {
      for(j = 0; j < n; j++) {
        t = a[i + j * m];
        a[i + j * m] = a[r + j * m];
        a[r + j * m] = t;
      }
    }
    //
    //  Ensure pivot is positive.
    //
    if(a[r + lead * m] < 0) {
      for(j = 0; j < n; j++) { a[r + j * m] = -a[r + j * m]; }
      det = -det;
    }
    //
    //  Update the pseudo-determinant.
    //
    det = det * a[r + lead * m];
    //
    //  Remove any common factor from row R.
    //
    for(j = 0; j < n; j++) { row[j] = a[r + j * m]; }
    i4vec_red(n, row);
    for(j = 0; j < n; j++) { a[r + j * m] = row[j]; }
    //
    //  Use a multiple of A(R,LEAD) to eliminate A(R+1:M,LEAD).
    //
    for(i = r + 1; i < m; i++) {
      t = a[i + lead * m];
      for(j = 0; j < n; j++) {
        a[i + j * m] = a[r + lead * m] * a[i + j * m] - t * a[r + j * m];
      }

      for(j = 0; j < n; j++) { row[j] = a[i + j * m]; }
      i4vec_red(n, row);
      for(j = 0; j < n; j++) { a[i + j * m] = row[j]; }
    }
    lead = lead + 1;
  }

  delete[] row;

  return det;
}
//****************************************************************************80

void i4mat_row_reduce(int m, int n, int i, int a[])

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_ROW_REDUCE divides out common factors in row I of an I4MAT.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 August 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows in the matrix.
//
//    Input, int N, the number of columns in the matrix.
//
//    Input, int I, the row to be reduced.  0 <= I < M.
//
//    Input/output, int A[M*N], on input, the matrix whose
//    row is to be reduced.  On output, row I of the matrix has been reduced.
//
{
  int j;
  int *row;
  //
  //  Remove factors common to a row.
  //
  row = new int[n];

  for(j = 0; j < n; j++) { row[j] = a[i + j * m]; }

  i4vec_red(n, row);

  for(j = 0; j < n; j++) { a[i + j * m] = row[j]; }

  delete[] row;

  return;
}
//****************************************************************************80

void i4mat_row_swap(int m, int n, int a[], int i1, int i2)

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_ROW_SWAP swaps rows in an I4MAT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 September 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input/output, int A[M*N].
//    On input, the matrix to be modified.
//    On output, two rows have been swapped.
//
//    Input, int I1, I2, the indices of the rows.
//    0 <= I1, I2 < M.
//
{
  int j;
  int t;

  if(i1 == i2) { return; }

  if(i1 < 0 || m <= i1) {
    cout << "\n";
    cout << "I4MAT_ROW_SWAP - Fatal error!\n";
    cout << "  Row index 0 <= I1 < M required.\n";
    exit(1);
  }

  if(i2 < 0 || m <= i2) {
    cout << "\n";
    cout << "I4MAT_ROW_SWAP - Fatal error!\n";
    cout << "  Row index 0 <= I2 < M required.\n";
    exit(1);
  }

  for(j = 0; j < n; j++) {
    t = a[i1 + j * m];
    a[i1 + j * m] = a[i2 + j * m];
    a[i2 + j * m] = t;
  }

  return;
}
//****************************************************************************80

int i4mat_rref(int m, int n, int a[])

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_RREF: the integer row reduced echelon form (IRREF) of an I4MAT.
//
//  Discussion:
//
//    If a matrix A contains only integer entries, then when it is reduced
//    to row echelon form, it is likely that many entries will no longer
//    be integers, due to the elimination process.
//
//    In some cases, tiny arithmetic errors in this elimination process can
//    result in spurious, tiny nonzero values which can invalidate the
//    calculation, particular if the elimination is being done in an effort
//    to determine the rank of the matrix.  These serious errors can easily
//    occur in very small matrices, such as of size 7x10.
//
//    If we, instead, insist on using only integer operations on an integer
//    matrix, we can guarantee that tiny roundoff errors will not cause
//    such problems.  On the other hand, as the elimination process proceeds,
//    we may instead calculate integer matrix entries of increasingly
//    large, and then ultimately meaningless magnitude.  I imagine this is
//    likely to happen for moderate size matrices of order 50x50, say, but
//    this is a huge improvement over the unreliability of the real
//    arithmetic case.
//
//
//    Thus, we define "integer row reduced echelon form" (IRREF).
//
//
//    A matrix is in integer row reduced echelon form if:
//
//    * The leading nonzero in each row is positive.
//
//    * Each row has no common factor greater than 1.
//
//    * The leading nonzero in each row occurs in a column to
//      the right of the leading nonzero in the previous row.
//
//    * Rows which are entirely zero occur last.
//
//    * When a row contains a leading nonzero in column J, then column J
//      is otherwise entirely zero.
//
//  Example:
//
//    Input matrix:
//
//     1    3    0    2    6    3    1
//    -2   -6    0   -2   -8    3    1
//     3    9    0    0    6    6    2
//    -1   -3    0    1    0    9    3
//
//    Output matrix:
//
//     1    3    0    0    2    0    0
//     0    0    0    1    2    0    0
//     0    0    0    0    0    3    1
//     0    0    0    0    0    0    0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 September 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns of
//    the matrix A.
//
//    Input/output, int A[M*N].  On input, the matrix to be
//    analyzed.  On output, the IRREF form of the matrix.
//
//    Output, int I4MAT_RREF, the pseudo-determinant.
//
{
  int det;
  int i;
  int j;
  int lead;
  int r;
  int *row;
  int t;

  det = 1;
  lead = 0;

  row = new int[n];

  for(r = 0; r < m; r++) {
    if(n - 1 < lead) { break; }
    //
    //  Start I at row R, and search for nonzero pivot entry A(I,LEAD).
    //
    i = r;

    while(a[i + lead * m] == 0) {
      i = i + 1;
      //
      //  If reach last row, reset I to R, and increment LEAD.
      //
      if(m - 1 < i) {
        i = r;
        lead = lead + 1;
        //
        //  If reach last column, we can find no more pivots.
        //
        if(n - 1 < lead) {
          lead = -1;
          break;
        }
      }
    }

    if(lead < 0) { break; }
    //
    //  Move pivot I into row R.
    //
    if(i != r) {
      for(j = 0; j < n; j++) {
        t = a[i + j * m];
        a[i + j * m] = a[r + j * m];
        a[r + j * m] = t;
      }
    }
    //
    //  Ensure pivot is positive.
    //
    if(a[r + lead * m] < 0) {
      for(j = 0; j < n; j++) { a[r + j * m] = -a[r + j * m]; }
      det = -det;
    }
    //
    //  Update the pseudo-determinant.
    //
    det = det * a[r + lead * m];
    //
    //  Remove any common factor from row R.
    //
    for(j = 0; j < n; j++) { row[j] = a[r + j * m]; }
    i4vec_red(n, row);
    for(j = 0; j < n; j++) { a[r + j * m] = row[j]; }
    //
    //  Use a multiple of A(R,LEAD) to eliminate A(1:M,LEAD).
    //
    for(i = 0; i < m; i++) {
      if(i != r) {
        t = a[i + lead * m];
        for(j = 0; j < n; j++) {
          a[i + j * m] = a[r + lead * m] * a[i + j * m] - t * a[r + j * m];
        }

        for(j = 0; j < n; j++) { row[j] = a[i + j * m]; }
        i4vec_red(n, row);
        for(j = 0; j < n; j++) { a[i + j * m] = row[j]; }
      }
    }
    lead = lead + 1;
  }

  delete[] row;

  return det;
}
//****************************************************************************80

double *i4mat_u_solve(int n, int a[], int b[])

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_U_SOLVE solves an upper triangular linear system.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//    Note that the solution is returned as a real vector.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 August 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of rows and columns of
//    the matrix A.
//
//    Input, int A[N*N], the N by N upper triangular matrix.
//
//    Input, int B[N], the right hand side of the linear system.
//
//    Output, double I4MAT_U_SOLVE[N], the solution of the linear system.
//
{
  int i;
  int j;
  double *x;
  //
  //  Solve U * x = b.
  //
  x = new double[n];

  for(i = n - 1; 0 <= i; i--) {
    x[i] = (double)b[i];
    for(j = i + 1; j < n; j++) { x[i] = x[i] - (double)a[i + j * n] * x[j]; }
    x[i] = x[i] / (double)a[i + i * n];
  }

  return x;
}
//****************************************************************************80

void i4vec_binary_next(int n, int bvec[])

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_BINARY_NEXT generates the next binary vector.
//
//  Discussion:
//
//    The vectors have the order
//
//      (0,0,...,0),
//      (0,0,...,1),
//      ...
//      (1,1,...,1)
//
//    and the "next" vector after (1,1,...,1) is (0,0,...,0).  That is,
//    we allow wrap around.
//
//  Example:
//
//    N = 3
//
//    Input      Output
//    -----      ------
//    0 0 0  =>  0 0 1
//    0 0 1  =>  0 1 0
//    0 1 0  =>  0 1 1
//    0 1 1  =>  1 0 0
//    1 0 0  =>  1 0 1
//    1 0 1  =>  1 1 0
//    1 1 0  =>  1 1 1
//    1 1 1  =>  0 0 0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the dimension of the vectors.
//
//    Input, int BVEC[N], the vector whose successor is desired.
//
//    Output, int BVEC[N], the successor to the input vector.
//
{
  int i;

  for(i = n - 1; 0 <= i; i--) {
    if(bvec[i] == 0) {
      bvec[i] = 1;
      return;
    }
    bvec[i] = 0;
  }

  return;
}
//****************************************************************************80

bool i4vec_is_binary(int n, int x[])

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_IS_BINARY is true if the entries in an I4VEC are all 0 or 1.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, int X[N], the vector to be checked.
//
//    Output, bool I4VEC_IS_BINARY is true if all N elements of X
//    are 0 or 1.
//
{
  int i;
  bool value;

  value = true;

  for(i = 0; i < n; i++) {
    if(x[i] != 0 && x[i] != 1) {
      value = false;
      break;
    }
  }

  return value;
}
//****************************************************************************80

bool i4vec_is_one(int n, int x[])

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_IS_ONE is true if the entries in an I4VEC are all 1.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, int X[N], the vector to be checked.
//
//    Output, bool I4VEC_IS_ONE is true if all N elements of X
//    are 1.
//
{
  int i;
  bool value;

  value = true;

  for(i = 0; i < n; i++) {
    if(x[i] != 1) {
      value = false;
      break;
    }
  }

  return value;
}
//****************************************************************************80

void i4vec_print(int n, int a[], string title)

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_PRINT prints an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 November 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, int A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for(i = 0; i < n; i++) {
    cout << "  " << setw(8) << i << ": " << setw(8) << a[i] << "\n";
  }
  return;
}
//****************************************************************************80

int i4vec_red(int n, int a[])

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_RED divides out common factors in an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input/output, int A[N], the vector to be reduced.
//    On output, the entries have no common factor
//    greater than 1.
//
//    Output, int I4VEC_RED, the common factor that was divided out.
//
{
  int factor;
  int i;
  //
  //  Find the smallest nonzero value.
  //
  factor = 0;

  for(i = 0; i < n; i++) {
    if(a[i] != 0) {
      if(factor == 0) { factor = abs(a[i]); }
      else if(abs(a[i]) < factor) {
        factor = abs(a[i]);
      }
    }
  }

  if(factor == 0) { return factor; }
  //
  //  Find the greatest common factor of the entire vector.
  //
  for(i = 0; i < n; i++) { factor = i4_gcd(a[i], factor); }

  if(factor == 1) { return factor; }
  //
  //  Divide out the common factor.
  //
  for(i = 0; i < n; i++) { a[i] = a[i] / factor; }

  return factor;
}
//****************************************************************************80

void i4vec_transpose_print(int n, int a[], string title)

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_TRANSPOSE_PRINT prints an I4VEC "transposed".
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Example:
//
//    A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }
//    TITLE = "My vector:  "
//
//    My vector:      1    2    3    4    5
//                    6    7    8    9   10
//                   11
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 July 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, int A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;
  int ihi;
  int ilo;
  int title_len;

  title_len = title.length();

  if(0 < title_len) {
    cout << "\n";
    cout << title << "\n";
  }

  if(0 < n) {
    for(ilo = 1; ilo <= n; ilo = ilo + 5) {
      ihi = ilo + 5 - 1;
      if(n < ihi) { ihi = n; }
      for(i = ilo; i <= ihi; i++) { cout << setw(12) << a[i - 1]; }
      cout << "\n";
    }
  }
  else {
    cout << "  (empty vector)\n";
  }

  return;
}
//****************************************************************************80

void ksub_next4(int n, int k, int a[], bool &done)

//****************************************************************************80
//
//  Purpose:
//
//    KSUB_NEXT4 generates the subsets of size K from a set of size N.
//
//  Discussion:
//
//    The subsets are generated one at a time.
//
//    The routine should be used by setting DONE to TRUE, and then calling
//    repeatedly.  Each call returns with DONE equal to FALSE, the array
//    A contains information defining a new subset.  When DONE returns
//    equal to TRUE, there are no more subsets.
//
//    There are ( N*(N-1)*...*(N+K-1)) / ( K*(K-1)*...*2*1) such subsets.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 August 2018
//
//  Author:
//
//    Original FORTRAN77 version by Albert Nijenhuis, Herbert Wilf.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Albert Nijenhuis, Herbert Wilf,
//    Combinatorial Algorithms for Computers and Calculators,
//    Second Edition,
//    Academic Press, 1978,
//    ISBN: 0-12-519260-6,
//    LC: QA164.N54.
//
//  Parameters:
//
//    Input, int N, the size of the entire set.
//
//    Input, int K, the size of the desired subset.  K must be
//    between 0 and N.
//
//    Input/output, int A[K], contains information about
//    the subsets.  On the first call with DONE = TRUE, the input contents
//    of A don't matter.  Thereafter, the input value of A
//    should be the same as the output value of the previous call.
//    In other words, leave the array alone!
//    On output, as long as DONE is returned FALSE, A contains
//    information defining a subset of K elements of a set of N elements.
//    In other words, A will contain K distinct numbers (in order)
//    between 1 and N.
//
//    Input/output, bool &DONE.
//    On the first call, DONE is an input quantity with a value
//    of TRUE which tells the program to initialize data and
//    return the first subset.
//    On return, DONE is an output quantity that is TRUE as long as
//    the routine is returning another subset, and FALSE when
//    there are no more.
//
{
  int j;
  int jsave;

  if(k < 0) {
    cerr << "\n";
    cerr << "KSUB_NEXT4 - Fatal error!\n";
    cerr << "  K = " << k << "\n";
    cerr << "  but 0 <= K is required!\n";
    exit(1);
  }

  if(n < k) {
    cerr << "\n";
    cerr << "KSUB_NEXT4 - Fatal error!\n";
    cerr << "  N = " << n << "\n";
    cerr << "  K = " << k << "\n";
    cerr << "  but K <= N is required!\n";
    exit(1);
  }

  //
  //  First call:
  //
  if(done) {
    for(j = 0; j < k; j++) { a[j] = j + 1; }
    done = false;
  }
  //
  //  Empty set returned on previous call.
  //
  else if(n == 0 || k == 0) {
    done = true;
  }
  //
  //  Next call.
  //
  else if(a[0] < n - k + 1) {
    jsave = k - 1;

    for(j = 0; j < k - 1; j++) {
      if(a[j] + 1 < a[j + 1]) {
        jsave = j;
        break;
      }
    }
    for(j = 0; j < jsave; j++) { a[j] = j + 1; }
    a[jsave] = a[jsave] + 1;
    done = false;
  }
  else {
    done = true;
  }
  return;
}
//****************************************************************************80

bool r8vec_is_integer(int n, double a[])

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_IS_INTEGER is TRUE if an R8VEC is integral.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in A.
//
//    Input, double A[N], the vector
//
//    Output, bool R8VEC_IS_INTEGER, is TRUE if every entry is an integer.
//
{
  int i;
  bool value;

  value = true;

  for(i = 0; i < n; i++) {
    if(a[i] != (double)(int)a[i]) {
      value = false;
      break;
    }
  }
  return value;
}
//****************************************************************************80

void r8vec_print(int n, double a[], string title)

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT prints an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for(i = 0; i < n; i++) {
    cout << "  " << setw(8) << i << ": " << setw(14) << a[i] << "\n";
  }

  return;
}
//****************************************************************************80

void r8vec_transpose_print(int n, double a[], string title)

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_TRANSPOSE_PRINT prints an R8VEC "transposed".
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Example:
//
//    A = (/ 1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 10.9, 11.0 /)
//    TITLE = 'My vector:  '
//
//    My vector:   1.0    2.1    3.2    4.3    5.4
//                 6.5    7.6    8.7    9.8   10.9
//                11.0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 May 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;
  int ihi;
  int ilo;
  int title_length;

  title_length = s_len_trim(title);

  for(ilo = 0; ilo < n; ilo = ilo + 5) {
    if(ilo == 0) { cout << title; }
    else {
      for(i = 0; i < title_length; i++) { cout << " "; }
    }
    cout << "  ";
    ihi = i4_min(ilo + 5, n);
    for(i = ilo; i < ihi; i++) { cout << "  " << setw(12) << a[i]; }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

int s_len_trim(string s)

//****************************************************************************80
//
//  Purpose:
//
//    S_LEN_TRIM returns the length of a string to the last nonblank.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string S, a string.
//
//    Output, int S_LEN_TRIM, the length of the string to the last nonblank.
//    If S_LEN_TRIM is 0, then the string is entirely blank.
//
{
  int n;

  n = s.length();

  while(0 < n) {
    if(s[n - 1] != ' ') { return n; }
    n = n - 1;
  }

  return n;
}
//****************************************************************************80

void timestamp()

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    31 May 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    None
//
{
#define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  std::time_t now;

  now = std::time(NULL);
  tm_ptr = std::localtime(&now);

  std::strftime(time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr);

  std::cout << time_buffer << "\n";

  return;
#undef TIME_SIZE
}
