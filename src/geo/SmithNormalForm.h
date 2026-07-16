// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SMITH_NORMAL_FORM_H
#define SMITH_NORMAL_FORM_H

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <stdexcept>
#include <utility>
#include <vector>

// Exact integer linear algebra for the homology solver (ChainComplex):
// dense matrices of 64-bit integers, with Hermite and Smith normal forms
// and their unimodular transformation matrices.
//
// This is a self-contained replacement for the parts of the 'kbipack'
// library of S. Suuriniemi (formerly bundled in contrib/kbipack) that Gmsh
// actually used. The Hermite normal form follows the Kannan-Bachem scheme
// [1] with the Chou-Collins reduction improvement [2]; the Smith normal
// form diagonalizes directly on the shrinking Schur complement with
// extended-gcd row/column rotations.
//
// The matrices arising in homology (boundary operators of a cell complex
// and bases derived from them) are totally unimodular or nearly so, and all
// intermediate quantities stay tiny, so entries are stored as native 64-bit
// integers instead of the arbitrary-precision integers used by kbipack
// (whose per-operation overhead dominated the computation). Every operation
// that could overflow is range-checked and throws std::overflow_error, so a
// (purely theoretical) overflow cannot go undetected.
//
// [1] R. Kannan, A. Bachem, "Polynomial algorithms for computing the Smith
//     and Hermite normal forms of an integer matrix", SIAM J. Comput.,
//     vol. 8, no. 5, pp. 499-507, 1979.
// [2] T.-W. J. Chou, G. E. Collins, "Algorithms for the solution of systems
//     of linear Diophantine equations", SIAM J. Comput., vol. 11, no. 4,
//     pp. 687-708, 1982.

namespace NormalFormDetail {

  [[noreturn]] inline void throwOverflow()
  {
    throw std::overflow_error("64-bit integer overflow");
  }

  // base + a * x, overflow-checked; a * x + b * y, overflow-checked. Where a
  // 128-bit type exists (GCC, Clang) the check is a single wide multiply;
  // otherwise (e.g. MSVC) standard branch-based signed-overflow tests.
#if defined(__SIZEOF_INT128__)
  inline std::int64_t addMul(std::int64_t base, std::int64_t a, std::int64_t x)
  {
    __int128 v = (__int128)base + (__int128)a * x;
    if(v > INT64_MAX || v < INT64_MIN) throwOverflow();
    return (std::int64_t)v;
  }
  inline std::int64_t mulMul(std::int64_t a, std::int64_t x, std::int64_t b,
                             std::int64_t y)
  {
    __int128 v = (__int128)a * x + (__int128)b * y;
    if(v > INT64_MAX || v < INT64_MIN) throwOverflow();
    return (std::int64_t)v;
  }
#else
  inline std::int64_t mul(std::int64_t a, std::int64_t b)
  {
    if(a > 0) {
      if(b > 0) {
        if(a > INT64_MAX / b) throwOverflow();
      }
      else {
        if(b < INT64_MIN / a) throwOverflow();
      }
    }
    else {
      if(b > 0) {
        if(a < INT64_MIN / b) throwOverflow();
      }
      else {
        if(a != 0 && b < INT64_MAX / a) throwOverflow();
      }
    }
    return a * b;
  }
  inline std::int64_t add(std::int64_t a, std::int64_t b)
  {
    if((b > 0 && a > INT64_MAX - b) || (b < 0 && a < INT64_MIN - b))
      throwOverflow();
    return a + b;
  }
  inline std::int64_t addMul(std::int64_t base, std::int64_t a, std::int64_t x)
  {
    return add(base, mul(a, x));
  }
  inline std::int64_t mulMul(std::int64_t a, std::int64_t x, std::int64_t b,
                             std::int64_t y)
  {
    return add(mul(a, x), mul(b, y));
  }
#endif

  inline std::int64_t negate(std::int64_t v)
  {
    if(v == INT64_MIN) throwOverflow();
    return -v;
  }

  inline std::int64_t divide(std::int64_t n, std::int64_t d)
  {
    if(d == -1) return negate(n); // INT64_MIN / -1 overflows
    return n / d;
  }

  // floor(n/d); with the checked negation this gives ceil(-n/d) = -floor(n/d)
  inline std::int64_t floorDiv(std::int64_t n, std::int64_t d)
  {
    std::int64_t q = n / d, r = n % d;
    if(r != 0 && ((r < 0) != (d < 0))) q--;
    return q;
  }

  // extended Euclid: returns g = gcd(a,b) >= 0 with s*a + t*b = g; produces
  // the same (minimal) cofactors as GMP's mpz_gcdext, with which the homology
  // reference results were established
  inline std::int64_t extendedGcd(std::int64_t a, std::int64_t b,
                                  std::int64_t &s, std::int64_t &t)
  {
    std::int64_t oldR = a, r = b, oldS = 1, s1 = 0, oldT = 0, t1 = 1;
    while(r != 0) {
      std::int64_t q = oldR / r, tmp;
      tmp = oldR - q * r;
      oldR = r;
      r = tmp;
      tmp = oldS - q * s1;
      oldS = s1;
      s1 = tmp;
      tmp = oldT - q * t1;
      oldT = t1;
      t1 = tmp;
    }
    if(oldR < 0) {
      oldR = negate(oldR);
      oldS = negate(oldS);
      oldT = negate(oldT);
    }
    s = oldS;
    t = oldT;
    return oldR;
  }

  inline unsigned bitLength(std::uint64_t v)
  {
    unsigned b = 0;
    while(v) {
      b++;
      v >>= 1;
    }
    return b;
  }

} // namespace NormalFormDetail

// A dense matrix of 64-bit integers, stored column-major. A default
// -constructed (0 x 0) matrix doubles as a "no matrix" value.
class IntegerMatrix {
private:
  std::size_t _rows, _cols;
  std::vector<std::int64_t> _storage; // column-major

public:
  IntegerMatrix() : _rows(0), _cols(0) {}
  IntegerMatrix(std::size_t numRows, std::size_t numCols)
    : _rows(numRows), _cols(numCols), _storage(numRows * numCols, 0)
  {
  }
  static IntegerMatrix identity(std::size_t n)
  {
    IntegerMatrix m(n, n);
    for(std::size_t i = 0; i < n; i++) m(i, i) = 1;
    return m;
  }

  std::size_t rows() const { return _rows; }
  std::size_t cols() const { return _cols; }
  bool empty() const { return _storage.empty(); }

  // 0-based element access
  std::int64_t operator()(std::size_t i, std::size_t j) const
  {
    return _storage[j * _rows + i];
  }
  std::int64_t &operator()(std::size_t i, std::size_t j)
  {
    return _storage[j * _rows + i];
  }

  // the submatrix of rows [row, row + numRows) and columns
  // [col, col + numCols)
  IntegerMatrix block(std::size_t row, std::size_t col, std::size_t numRows,
                      std::size_t numCols) const
  {
    IntegerMatrix res(numRows, numCols);
    for(std::size_t j = 0; j < numCols; j++)
      for(std::size_t i = 0; i < numRows; i++)
        res(i, j) = (*this)(row + i, col + j);
    return res;
  }

  void transposeInPlace()
  {
    IntegerMatrix t(_cols, _rows);
    for(std::size_t j = 0; j < _cols; j++)
      for(std::size_t i = 0; i < _rows; i++) t(j, i) = (*this)(i, j);
    *this = std::move(t);
  }

  // elementary (unimodular) row and column operations
  void swapRows(std::size_t r1, std::size_t r2)
  {
    if(r1 == r2) return;
    for(std::size_t j = 0; j < _cols; j++)
      std::swap((*this)(r1, j), (*this)(r2, j));
  }
  void swapCols(std::size_t c1, std::size_t c2)
  {
    if(c1 == c2) return;
    for(std::size_t i = 0; i < _rows; i++)
      std::swap((*this)(i, c1), (*this)(i, c2));
  }
  void negateRow(std::size_t r)
  {
    for(std::size_t j = 0; j < _cols; j++)
      (*this)(r, j) = NormalFormDetail::negate((*this)(r, j));
  }
  void negateCol(std::size_t c)
  {
    for(std::size_t i = 0; i < _rows; i++)
      (*this)(i, c) = NormalFormDetail::negate((*this)(i, c));
  }
  // row(dst) += a * row(src)
  void addRowMultiple(std::int64_t a, std::size_t src, std::size_t dst)
  {
    for(std::size_t j = 0; j < _cols; j++)
      (*this)(dst, j) =
        NormalFormDetail::addMul((*this)(dst, j), a, (*this)(src, j));
  }
  // col(dst) += a * col(src)
  void addColMultiple(std::int64_t a, std::size_t src, std::size_t dst)
  {
    for(std::size_t i = 0; i < _rows; i++)
      (*this)(i, dst) =
        NormalFormDetail::addMul((*this)(i, dst), a, (*this)(i, src));
  }
  // (row(r1), row(r2)) <- (a*row(r1) + b*row(r2), c*row(r1) + d*row(r2))
  void rotateRows(std::int64_t a, std::int64_t b, std::size_t r1,
                  std::int64_t c, std::int64_t d, std::size_t r2)
  {
    for(std::size_t j = 0; j < _cols; j++) {
      std::int64_t x = (*this)(r1, j), y = (*this)(r2, j);
      (*this)(r1, j) = NormalFormDetail::mulMul(a, x, b, y);
      (*this)(r2, j) = NormalFormDetail::mulMul(c, x, d, y);
    }
  }
  // (col(c1), col(c2)) <- (a*col(c1) + b*col(c2), c*col(c1) + d*col(c2))
  void rotateCols(std::int64_t a, std::int64_t b, std::size_t c1,
                  std::int64_t c, std::int64_t d, std::size_t c2)
  {
    for(std::size_t i = 0; i < _rows; i++) {
      std::int64_t x = (*this)(i, c1), y = (*this)(i, c2);
      (*this)(i, c1) = NormalFormDetail::mulMul(a, x, b, y);
      (*this)(i, c2) = NormalFormDetail::mulMul(c, x, d, y);
    }
  }

  // P * this, for the permutation matrix P with P(destRow[i], i) = 1: row i
  // becomes row destRow[i] of the result
  IntegerMatrix permuteRows(const std::vector<std::size_t> &destRow) const
  {
    IntegerMatrix res(_rows, _cols);
    for(std::size_t j = 0; j < _cols; j++)
      for(std::size_t i = 0; i < _rows; i++) res(destRow[i], j) = (*this)(i, j);
    return res;
  }

  // largest bit length of the entries
  unsigned maxBitLength() const
  {
    std::uint64_t m = 0;
    for(std::int64_t v : _storage) {
      std::uint64_t a = v < 0 ? ~(std::uint64_t)v + 1u : (std::uint64_t)v;
      if(a > m) m = a;
    }
    return NormalFormDetail::bitLength(m);
  }

  // Matrix product. A length-k dot product of b1-bit and b2-bit entries is
  // bounded by 2^(b1 + b2 + bitLength(k)); when that fits in an int64 (always
  // the case in homology, where entries are tiny) the product is accumulated
  // unchecked, skipping structural zeros and computing result columns in
  // parallel. Otherwise a serial overflow-checked loop is used.
  IntegerMatrix operator*(const IntegerMatrix &other) const
  {
    if(_cols != other._rows)
      throw std::runtime_error("integer matrix dimension mismatch");
    IntegerMatrix res(_rows, other._cols);
    unsigned bA = maxBitLength(), bB = other.maxBitLength();
    unsigned bK = NormalFormDetail::bitLength(_cols);
    if(bA <= 31 && bB <= 31 && bA + bB + bK <= 62) {
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
      for(long long j = 0; j < (long long)other._cols; j++) {
        std::int64_t *out = &res._storage[(std::size_t)j * _rows];
        const std::int64_t *bcol = &other._storage[(std::size_t)j * _cols];
        for(std::size_t k = 0; k < _cols; k++) {
          std::int64_t b = bcol[k];
          if(b == 0) continue;
          const std::int64_t *acol = &_storage[k * _rows];
          for(std::size_t i = 0; i < _rows; i++) out[i] += acol[i] * b;
        }
      }
    }
    else {
      for(std::size_t j = 0; j < other._cols; j++) {
        std::int64_t *out = &res._storage[j * _rows];
        const std::int64_t *bcol = &other._storage[j * _cols];
        for(std::size_t k = 0; k < _cols; k++) {
          std::int64_t b = bcol[k];
          if(b == 0) continue;
          const std::int64_t *acol = &_storage[k * _rows];
          for(std::size_t i = 0; i < _rows; i++)
            out[i] = NormalFormDetail::addMul(out[i], acol[i], b);
        }
      }
    }
    return res;
  }
};

// Hermite normal form A = P^T * L * U (Kannan-Bachem):
// - canonical: L, lower triangular with positive diagonal entries and
//   non-negative subdiagonal entries smaller than the diagonal entry of
//   their row (trailing all-zero columns permuted to the end);
// - rightInverse: inv(U), U unimodular, so that A * inv(U) = P^T * L;
// - rowPermutation: the permutation P^T, encoded so that row i of the
//   canonical corresponds to row rowPermutation[i] of A; use
//   M.permuteRows(rowPermutation) to form P^T * M.
struct HermiteForm {
  std::vector<std::size_t> rowPermutation;
  IntegerMatrix canonical;
  IntegerMatrix rightInverse;
};

// Smith normal form inv(U) * A * inv(V) = S (i.e. A = U * S * V):
// - canonical: S, diagonal with the first k diagonal entries positive (the
//   invariant factors of A, each divisible by the previous one), rest zero;
// - left, right: the unimodular factors U and V if invertedFactors is
//   false, or their inverses inv(U) and inv(V) if it is true.
struct SmithForm {
  IntegerMatrix left;
  IntegerMatrix canonical;
  IntegerMatrix right;
};

inline HermiteForm hermiteNormalForm(IntegerMatrix A)
{
  namespace nfd = NormalFormDetail;
  const std::size_t m = A.rows(), n = A.cols();

  HermiteForm nf;
  nf.rowPermutation.resize(m);
  std::iota(nf.rowPermutation.begin(), nf.rowPermutation.end(), (std::size_t)0);
  nf.canonical = std::move(A);
  nf.rightInverse = IntegerMatrix::identity(n);
  IntegerMatrix &C = nf.canonical;
  IntegerMatrix &R = nf.rightInverse;

  // Eliminate the entries of column col above the diagonal against the
  // leading diagonal with extended-gcd column rotations, mirrored onto the
  // right factor. Returns true if a leading column changed, which happens
  // exactly when some leading pivot was not a unit (Bezout pair != (1, 0)):
  // the leading block may then have become unreduced.
  auto eliminate = [&](std::size_t col) -> bool {
    bool disturbed = false;
    const std::size_t rowLimit = std::min(col, m);
    for(std::size_t i = 0; i < rowLimit; i++) {
      std::int64_t e = C(i, col);
      if(e == 0) continue;
      std::int64_t p = C(i, i), s, t;
      std::int64_t g = nfd::extendedGcd(p, e, s, t);
      std::int64_t c = nfd::negate(e / g), d = p / g;
      if(s != 1 || t != 0) disturbed = true;
      C.rotateCols(s, t, i, c, d, col);
      R.rotateCols(s, t, i, c, d, col);
    }
    return disturbed;
  };

  // Reduce the off-diagonal entries of the leading block ending at diagonal
  // position col to 0 <= entry < diagonal (Chou-Collins). When rowOnly is
  // set, only row col is reduced: the rest of the block is already reduced
  // and undisturbed, and the skipped entries would have failed the reduction
  // guard anyway, so this is exact and turns the O(col^2) block sweep into
  // an O(col) row sweep.
  auto reduce = [&](std::ptrdiff_t col, bool rowOnly) {
    if(col < 0 || col >= (std::ptrdiff_t)m) return;
    for(std::ptrdiff_t j = col - 1; j >= 0; j--) {
      for(std::size_t i = rowOnly ? col : j + 1; i <= (std::size_t)col; i++) {
        std::int64_t p = C(i, i), e = C(i, j);
        std::int64_t ap = p < 0 ? -p : p, ae = e < 0 ? -e : e;
        if(ae >= ap || e < 0) {
          // the smallest cff with 0 <= e + cff * p < p, i.e. ceil(-e/p)
          std::int64_t cff = nfd::negate(nfd::floorDiv(e, p));
          C.addColMultiple(cff, i, j);
          R.addColMultiple(cff, i, j);
        }
      }
    }
  };

  // "schur" is the diagonal position where the current Schur complement
  // starts; "clean" tracks whether the leading block is fully reduced, which
  // holds as long as elimination only meets unit pivots (always, for the
  // totally unimodular matrices of homology) and allows the cheap rowOnly
  // reductions
  std::size_t schur = 0, ncols = n;
  bool clean = true;
  while(schur < m && schur < ncols) {
    if(schur > 0 && eliminate(schur)) clean = false;

    std::size_t pivotRow = m;
    for(std::size_t i = schur; i < m; i++)
      if(C(i, schur) != 0) {
        pivotRow = i;
        break;
      }

    if(pivotRow == m) {
      // the column is all zero, hence settled: permute it to the end; the
      // elimination may have left the leading block unreduced
      C.swapCols(schur, ncols - 1);
      R.swapCols(schur, ncols - 1);
      ncols--;
      if(schur > 0 && !clean) {
        reduce((std::ptrdiff_t)schur - 1, false);
        clean = true;
      }
    }
    else {
      // permute the pivot to the diagonal, make it positive, and reduce the
      // off-diagonals; the Schur complement then starts at the next diagonal
      C.swapRows(schur, pivotRow);
      std::swap(nf.rowPermutation[schur], nf.rowPermutation[pivotRow]);
      if(C(schur, schur) < 0) {
        C.negateCol(schur);
        R.negateCol(schur);
      }
      reduce((std::ptrdiff_t)schur, clean);
      clean = true;
      schur++;
    }
  }

  // the Schur complement is empty, but a wide matrix may still have
  // uneliminated columns
  for(std::size_t col = schur; col < ncols; col++) {
    if(eliminate(col)) clean = false;
    if(!clean) {
      reduce((std::ptrdiff_t)schur - 1, false);
      clean = true;
    }
  }

  return nf;
}

inline SmithForm smithNormalForm(IntegerMatrix A, bool invertedFactors)
{
  namespace nfd = NormalFormDetail;
  const std::size_t m = A.rows(), n = A.cols();
  const bool inv = invertedFactors;

  SmithForm nf;
  nf.canonical = std::move(A);
  nf.left = IntegerMatrix::identity(m);
  nf.right = IntegerMatrix::identity(n);
  IntegerMatrix &C = nf.canonical;
  IntegerMatrix &L = nf.left;
  IntegerMatrix &R = nf.right;

  // Row/column operations on the canonical matrix, mirrored onto the
  // factors: an operation is applied directly to the factor when the
  // (inverse) factor is requested, and as the inverse operation on the
  // opposite side otherwise. All rotations built below have determinant +1,
  // so their inverse is simply the adjugate.
  auto rowSwap = [&](std::size_t r1, std::size_t r2) {
    C.swapRows(r1, r2);
    if(inv)
      L.swapRows(r1, r2);
    else
      L.swapCols(r1, r2);
  };
  auto rowAddMultiple = [&](std::int64_t q, std::size_t src, std::size_t dst) {
    C.addRowMultiple(q, src, dst);
    if(inv)
      L.addRowMultiple(q, src, dst);
    else
      L.addColMultiple(nfd::negate(q), dst, src);
  };
  auto rowRotate = [&](std::int64_t a, std::int64_t b, std::size_t r1,
                       std::int64_t c, std::int64_t d, std::size_t r2) {
    C.rotateRows(a, b, r1, c, d, r2);
    if(inv)
      L.rotateRows(a, b, r1, c, d, r2);
    else
      L.rotateCols(d, nfd::negate(c), r1, nfd::negate(b), a, r2);
  };
  auto colSwap = [&](std::size_t c1, std::size_t c2) {
    C.swapCols(c1, c2);
    if(inv)
      R.swapCols(c1, c2);
    else
      R.swapRows(c1, c2);
  };
  auto colNegate = [&](std::size_t c) {
    C.negateCol(c);
    if(inv)
      R.negateCol(c);
    else
      R.negateRow(c);
  };
  auto colAddMultiple = [&](std::int64_t q, std::size_t src, std::size_t dst) {
    C.addColMultiple(q, src, dst);
    if(inv)
      R.addColMultiple(q, src, dst);
    else
      R.addRowMultiple(nfd::negate(q), dst, src);
  };
  auto colRotate = [&](std::int64_t a, std::int64_t b, std::size_t c1,
                       std::int64_t c, std::int64_t d, std::size_t c2) {
    C.rotateCols(a, b, c1, c, d, c2);
    if(inv)
      R.rotateCols(a, b, c1, c, d, c2);
    else
      R.rotateRows(d, nfd::negate(c), c1, nfd::negate(b), a, c2);
  };

  // Zero C(i,t) against the pivot C(t,t). When the pivot divides the entry,
  // subtract a multiple of the pivot row, leaving the pivot row untouched;
  // otherwise apply an extended-gcd row rotation, which strictly shrinks the
  // pivot. Mixing the two is essential: in the divisible case a gcd rotation
  // can return a Bezout coefficient of 0 and merely shuffle rows, never
  // making progress.
  auto clearBelow = [&](std::size_t t, std::size_t i) {
    std::int64_t p = C(t, t), e = C(i, t);
    std::int64_t quo = nfd::divide(e, p);
    if(e - quo * p == 0) {
      rowAddMultiple(nfd::negate(quo), t, i);
      return;
    }
    std::int64_t s, u;
    std::int64_t g = nfd::extendedGcd(p, e, s, u);
    rowRotate(s, u, t, nfd::negate(e / g), p / g, i);
  };
  // same, for C(t,j) against the pivot, with column operations
  auto clearRight = [&](std::size_t t, std::size_t j) {
    std::int64_t p = C(t, t), e = C(t, j);
    std::int64_t quo = nfd::divide(e, p);
    if(e - quo * p == 0) {
      colAddMultiple(nfd::negate(quo), t, j);
      return;
    }
    std::int64_t s, u;
    std::int64_t g = nfd::extendedGcd(p, e, s, u);
    colRotate(s, u, t, nfd::negate(e / g), p / g, j);
  };

  const std::size_t ndiag = std::min(m, n);
  for(std::size_t t = 0; t < ndiag; t++) {
    // Smallest-magnitude nonzero of the trailing block as the pivot: this
    // surfaces unit pivots first, which clear their row and column in a
    // single pass with no growth. A nonzero integer has magnitude >= 1, so
    // the first entry of magnitude 1 in scan order is already the best
    // choice: stop there (the usual case -- the matrices are totally
    // unimodular -- avoiding an O(n^2) scan per pivot).
    std::size_t pi = t, pj = t;
    bool have = false, unit = false;
    std::int64_t best = 0;
    for(std::size_t j = t; j < n && !unit; j++)
      for(std::size_t i = t; i < m; i++) {
        std::int64_t v = C(i, j);
        if(v == 0) continue;
        std::int64_t av = v < 0 ? -v : v;
        if(!have || av < best) {
          best = av;
          pi = i;
          pj = j;
          have = true;
          if(av == 1) {
            unit = true;
            break;
          }
        }
      }
    if(!have) break; // the trailing block is all zero: done

    if(pi != t) rowSwap(t, pi);
    if(pj != t) colSwap(t, pj);

    for(;;) {
      for(std::size_t i = t + 1; i < m; i++)
        if(C(i, t) != 0) clearBelow(t, i);
      for(std::size_t j = t + 1; j < n; j++)
        if(C(t, j) != 0) clearRight(t, j);

      // clearing the row may have re-dirtied column t, and vice versa
      bool dirty = false;
      for(std::size_t i = t + 1; i < m && !dirty; i++)
        if(C(i, t) != 0) dirty = true;
      for(std::size_t j = t + 1; j < n && !dirty; j++)
        if(C(t, j) != 0) dirty = true;
      if(dirty) continue;

      // The pivot must divide every entry of the trailing block. If not,
      // fold an offending row into the pivot row and clear again; the
      // pivot's gcd then strictly shrinks, so this terminates. A unit pivot
      // divides everything: skip the O(n^2) scan (again the usual case).
      bool folded = false;
      std::int64_t p = C(t, t);
      if(p != 1 && p != -1)
        for(std::size_t j = t + 1; j < n && !folded; j++)
          for(std::size_t i = t + 1; i < m && !folded; i++) {
            std::int64_t v = C(i, j);
            if(v != 0 && v % p != 0) {
              rowAddMultiple(1, i, t);
              folded = true;
            }
          }
      if(!folded) break;
    }

    if(C(t, t) < 0) colNegate(t);
  }

  return nf;
}

#endif
