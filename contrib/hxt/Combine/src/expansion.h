/**
 * \file expansion.h Expansion arithmetic for exact hex validity computation 
 *
 * These classes implement expansion arithmetic, as described in Jonathan
 * Shewchuk's paper on adaptive precision floating point numbers and as used in
 * his robust predicates.
 *
 * An optimizing compiler can still generate efficient code if C++-style
 * operators are used, as long as the SmallExpansion and StaticSmallExpansion
 * classes are used (because they encode the maximum size of the expansion
 * within their type). The DynamicExpansion class is around 50% slower when
 * performing an exact computation of orient3d.
 *
 * \author Kilian Verhetsel
 */

#include "predicates.h"
#include <vector>
#include "hxt_tools.h"

static int sign(double v) {
  if (v > 0) return 1;
  else if (v < 0) return -1;
  else return 0;
}

/**
 * Exact representation of a number which does not require compile-time
 * knowledge of the number of terms in the expansion.
 *
 * This class is much slower and should only be used if this level of
 * flexibility is needed.
 */
struct DynamicExpansion {
  std::vector<double> data_;

public:
  DynamicExpansion(HXTIndex n, const double *data): data_(n) {
    std::copy(data, data + n, data_.begin());
  }

  DynamicExpansion() {}

  DynamicExpansion(HXTIndex n): data_(n) {}

  /**
   * Returns a pointer to the first term of the expansion.
   */
  const double *data() const { return data_.data(); }
  double *data() { return data_.data(); }

  /**
   * Returns the number of terms in the expansion.
   */
  HXTIndex size() const { return data_.size(); }

  /**
   * Truncates the expansion, keeping only the \t size first terms.
   */
  void resize(HXTIndex size) { data_.resize(size); }

  /**
   * Returns an integer of the same sign as this number.
   */
  int sign() const { return data_.size() == 0 ? 0 : ::sign(data_[data_.size() - 1]); }

  /**
   * Returns a new number scaled by a factor v.
   *
   * This operation is only correct if the multiplication by v of each term of
   * the expansion produces no round-off error. In particular, this is
   * guaranteed when v is a power of two.
   */
  DynamicExpansion scalePowerOfTwo(double v) const {
    DynamicExpansion other(size(), data());
    for (HXTIndex i = 0; i < size(); i++) other.data()[i] *= v;
    return other;
  }

  /**
   * Scales a number by a given factor in-place.
   *
   * The restrictions on the value of v are the same as when calling \ref
   * scalePowerOfTwo.
   */
  DynamicExpansion &scaleInPlace(double v) {
    for (HXTIndex i = 0; i < size(); i++) data()[i] *= v;
    return *this;
  }

  /**
   * Returns an estimate
   */
  double estimate() const {
    double sum = 0.0;
    for (HXTIndex i = 0; i < size(); i++) sum += data()[size() - i - 1];
    return sum;
  }
};

template<unsigned int N>
struct SmallExpansion;

template<unsigned int N>
struct StaticSmallExpansion;

/**
 * Exact representation of a number using a fixed number of terms.
 */
template<unsigned int N>
struct StaticSmallExpansion {
  double data_[N];

public:
  StaticSmallExpansion() {}

  StaticSmallExpansion(HXTIndex n, const double *data) {
    HXTIndex offset = N - n;
    std::fill(data_, data_ + offset, 0.0);
    std::copy(data, data+n, data_ + offset);
  }

  explicit operator DynamicExpansion() const {
    return DynamicExpansion(N, data_);
  }

  explicit operator SmallExpansion<N>() const;

  const double *data() const { return data_; }
  double *data() { return data_; }

  HXTIndex size() const { return N; }

  int sign() const { return N == 0 ? 0 : ::sign(data_[N - 1]); }

  StaticSmallExpansion<N> scalePowerOfTwo(double v) const {
    StaticSmallExpansion<N> other(size(), data());
    for (HXTIndex i = 0; i < size(); i++) other.data()[i] *= v;
    return other;
  }

  StaticSmallExpansion<N> &scaleInPlace(double v) {
    for (HXTIndex i = 0; i < size(); i++) data()[i] *= v;
    return *this;
  }

  SmallExpansion<N> withZeroElimination() const {
    return (SmallExpansion<N>)(*this);
  }

  double estimate() const {
    double sum = 0.0;
    for (HXTIndex i = 0; i < size(); i++) sum += data()[size() - i - 1];
    return sum;
  }
};

/**
 * Exact representation of a number which eliminates spurious zeroes from the
 * expansion as computations are performed.
 *
 * N is the maximum number of terms in the expansion.
 */
template<unsigned int N>
struct SmallExpansion {
  HXTIndex size_;
  double data_[N];

public:
  SmallExpansion(): size_(0) {}

  SmallExpansion(HXTIndex n, const double *data): size_(n) {
    std::copy(data, data+n, data_);
  }

  explicit operator DynamicExpansion() const {
    return DynamicExpansion(size_, data_);
  }

  operator StaticSmallExpansion<N>() const;

  const double *data() const { return data_; }
  double *data() { return data_; }

  HXTIndex size() const { return size_; }
  void resize(HXTIndex size) { size_ = size; }

  int sign() const { return size_ == 0 ? 0 : ::sign(data_[size_ - 1]); }

  SmallExpansion<N> withZeroElimination() const { return *this; }

  SmallExpansion<N> scalePowerOfTwo(double v) const {
    SmallExpansion<N> other(size(), data());
    for (HXTIndex i = 0; i < size(); i++) other.data()[i] *= v;
    return other;
  }

  SmallExpansion<N> &scaleInPlace(double v) {
    for (HXTIndex i = 0; i < size(); i++) data()[i] *= v;
    return *this;
  }

  double estimate() const {
    double sum = 0.0;
    for (HXTIndex i = 0; i < size(); i++) sum += data()[size() - i - 1];
    return sum;
  }
};

template<unsigned int N>
StaticSmallExpansion<N>::operator SmallExpansion<N>() const {
  return SmallExpansion<N>(N, data_);
}

template<unsigned int N>
SmallExpansion<N>::operator StaticSmallExpansion<N>() const {
  return StaticSmallExpansion<N>(size_, data_);
}

static inline StaticSmallExpansion<1> exact(double v) {
  return StaticSmallExpansion<1>(1, &v);
}

/**_
 * Adding a floating point number to an expansion
 */

template<unsigned int N>
StaticSmallExpansion<N+1> operator+(const StaticSmallExpansion<N> &a, double b) {
  SmallExpansion<N+1> ret;
  ret.resize(grow_expansion(a.size(), a.data(), b, ret.data()));
  return ret;
}

template<unsigned int N>
SmallExpansion<N+1> operator+(const SmallExpansion<N> &a, double b) {
  SmallExpansion<N+1> ret;
  ret.resize(grow_expansion_zeroelim(a.size(), a.data(), b, ret.data()));
  return ret;
}

static inline
DynamicExpansion operator+(const DynamicExpansion &a, double b) {
  DynamicExpansion ret(a.size() + 1);
  ret.resize(grow_expansion_zeroelim(a.size(), a.data(), b, ret.data()));
  return ret;
}

template<unsigned int N>
StaticSmallExpansion<N+1> operator-(const StaticSmallExpansion<N> &a, double b) {
  return a + (-b);
}

template<unsigned int N>
SmallExpansion<N+1> operator-(const SmallExpansion<N> &a, double b) {
  return a + (-b);
}

static inline
DynamicExpansion operator-(const DynamicExpansion &a, double b) {
  return a + (-b);
}

/**
 * Sum of two expansions
 */

template<unsigned int N, unsigned int M>
StaticSmallExpansion<N+M> operator+(const StaticSmallExpansion<N> &a,
                                    const StaticSmallExpansion<M> &b) {
  StaticSmallExpansion<N+M> ret;
  fast_expansion_sum(a.size(), a.data(),
                     b.size(), b.data(), ret.data());
  return ret;
}

template<unsigned int N, unsigned int M>
SmallExpansion<N+M> operator+(const SmallExpansion<N> &a,
                              const SmallExpansion<M> &b) {
  SmallExpansion<N+M> ret;
  ret.resize(fast_expansion_sum_zeroelim(a.size(), a.data(), b.size(), b.data(),
                                         ret.data()));
  return ret;
}

static inline
DynamicExpansion operator+(const DynamicExpansion &a,
                           const DynamicExpansion &b) {
  DynamicExpansion ret(a.size() + b.size());
  ret.resize(fast_expansion_sum_zeroelim(a.size(), a.data(), b.size(), b.data(),
                                         ret.data()));
  return ret;
}

/**
 * Subtraction of two expansions
 */

template<unsigned int N, unsigned int M>
StaticSmallExpansion<N+M> operator-(const StaticSmallExpansion<N> &a,
                                    StaticSmallExpansion<M> b) {
  b.scaleInPlace(-1.0);
  return a + b;
}

template<unsigned int N, unsigned int M>
SmallExpansion<N+M> operator-(const SmallExpansion<N> &a,
                              SmallExpansion<M> b) {
  b.scaleInPlace(-1.0);
  return a + b;
}

static inline
DynamicExpansion operator-(const DynamicExpansion &a, DynamicExpansion b) {
  b.scaleInPlace(-1.0);
  return a + b;
}

/**
 * Negation operator
 */

template<unsigned int N>
StaticSmallExpansion<N> operator-(StaticSmallExpansion<N> b) {
  b.scaleInPlace(-1.0);
  return b;
}

template<unsigned int N>
SmallExpansion<N> operator-(SmallExpansion<N> b) {
  b.scaleInPlace(-1.0);
  return b;
}

static inline
DynamicExpansion operator-(DynamicExpansion b) {
  b.scaleInPlace(-1.0);
  return b;
}

/**
 * Scaling of an expansion by a floating point number
 */

template<unsigned int N>
StaticSmallExpansion<2*N> operator*(const StaticSmallExpansion<N> &a, double b) {
  SmallExpansion<2*N> ret;
  ret.resize(scale_expansion(a.size(), a.data(), b, ret.data()));
  return ret;
}

template<unsigned int N>
StaticSmallExpansion<2*N> operator*(double b, const StaticSmallExpansion<N> &a) {
  return a * b;
}

template<unsigned int N>
SmallExpansion<2*N> operator*(const SmallExpansion<N> &a, double b) {
  SmallExpansion<2*N> ret;
  ret.resize(scale_expansion_zeroelim(a.size(), a.data(), b, ret.data()));
  return ret;
}

template<unsigned int N>
SmallExpansion<2*N> operator*(double b, const SmallExpansion<N> &a) {
  return a * b;
}

static inline
DynamicExpansion operator*(const DynamicExpansion &a, double b) {
  DynamicExpansion ret(2*a.size());
  ret.resize(scale_expansion_zeroelim(a.size(), a.data(), b, ret.data()));
  return ret;
}

static inline
DynamicExpansion operator*(double b, const DynamicExpansion &a) {
  return a * b;
}

/**
 * Expansion products
 */

template<unsigned int N>
struct ProductComputation {
  template<unsigned int M>
  static StaticSmallExpansion<2*N*M> computePartialProduct(
    const double *data, const StaticSmallExpansion<M> &b) {
    return ProductComputation<N/2>::computePartialProduct(data, b) +
      ProductComputation<N - N/2>::computePartialProduct(data + N/2, b);
  }

  template<unsigned int M>
  static SmallExpansion<2*N*M> computePartialProduct(
    const double *data, const SmallExpansion<M> &b) {
    return ProductComputation<N/2>::computePartialProduct(data, b) +
      ProductComputation<N - N/2>::computePartialProduct(data + N/2, b);
  }
};

template<>
struct ProductComputation<1> {
  template<unsigned int M>
  static StaticSmallExpansion<2*M> computePartialProduct(
    const double *data, const StaticSmallExpansion<M> &b) {
    StaticSmallExpansion<2*M> result;
    scale_expansion(b.size(), b.data(), data[0], result.data());
    return result;
  }

  template<unsigned int M>
  static SmallExpansion<2*M> computePartialProduct(
    const double *data, const SmallExpansion<M> &b) {
    SmallExpansion<2*M> result;
    result.resize(scale_expansion_zeroelim(b.size(), b.data(), data[0],
                                           result.data()));
    return result;
  }
};

template<unsigned int N, unsigned int M>
StaticSmallExpansion<2*N*M> computePartialProduct(
  const double *data, const StaticSmallExpansion<M> &b) {
  return ProductComputation<N>::computePartialProduct(data, b);
}

template<unsigned int N, unsigned int M>
StaticSmallExpansion<2*N*M> computeProduct(
  const StaticSmallExpansion<N> &a,
  const StaticSmallExpansion<M> &b) {
  SmallExpansion<2*N*M> result;
  return computePartialProduct<N/2>(a.data(), b) +
    computePartialProduct<N - N/2>(
      a.data() + N/2, b);
}

template<unsigned int N, unsigned int M>
StaticSmallExpansion<2*N*M> operator*(
  const StaticSmallExpansion<N> &a,
  const StaticSmallExpansion<M> &b) {
  if (a.size() < b.size()) return computeProduct(a, b);
  else return computeProduct(b, a);
}

template<unsigned int N, unsigned int M>
SmallExpansion<2*N*M> computePartialProduct(const double *data, HXTIndex n,
                                            const SmallExpansion<M> &b) {
  if (n == 1) {
    SmallExpansion<2*N*M> result;
    result.resize(scale_expansion_zeroelim(b.size(), b.data(), data[0],
                                           result.data()));
    return result;
  }
  else if (n == 0) {
    SmallExpansion<2*N*M> result;
    result.resize(0);
    return result;
  }
  else {
    return computePartialProduct<N/2>(data, n/2, b) +
      computePartialProduct<N - N/2>(data + n/2, n - n/2, b);
  }
}

template<unsigned int N, unsigned int M>
SmallExpansion<2*N*M> computeProduct(const SmallExpansion<N> &a,
                                     const SmallExpansion<M> &b) {
  SmallExpansion<2*N*M> result;
  return computePartialProduct<N>(a.data(), a.size(), b);
}

template<unsigned int N, unsigned int M>
SmallExpansion<2*N*M> operator*(const SmallExpansion<N> &a,
                                const SmallExpansion<M> &b) {
  if (a.size() < b.size()) return computeProduct(a, b);
  else return computeProduct(b, a);
}

template<unsigned int N, unsigned int M>
SmallExpansion<2*N*M> operator*(const SmallExpansion<N> &a,
                                const StaticSmallExpansion<M> &b) {
  return ProductComputation<M>::computePartialProduct(b.data(), a);
}

template<unsigned int N, unsigned int M>
SmallExpansion<2*N*M> operator*(const StaticSmallExpansion<N> &a,
                                const SmallExpansion<M> &b) {
  return ProductComputation<N>::computePartialProduct(a.data(), b);
}

/**
 * Special cases for small expansions
 */

static inline
StaticSmallExpansion<2> operator+(const StaticSmallExpansion<1> &a,
                                  const StaticSmallExpansion<1> &b) {
  double x = a.data()[0] + b.data()[0];

  double bvirt = x - a.data()[0];
  double avirt = x - bvirt;

  double errB = b.data()[0] - bvirt;
  double errA = a.data()[0] - avirt;

  double y = errA + errB;

  StaticSmallExpansion<2> result;

  result.data()[0] = y;
  result.data()[1] = x;

  return result;
}

static inline
StaticSmallExpansion<3> operator+(const StaticSmallExpansion<2> &a,
                                  const StaticSmallExpansion<1> &b) {
  auto t1 = exact(a.data()[0]) + exact(b.data()[0]);
  auto t2 = exact(a.data()[1]) + exact(t1.data()[1]);

  StaticSmallExpansion<3> result;
  result.data()[0] = t1.data()[0];
  result.data()[1] = t2.data()[0];
  result.data()[2] = t2.data()[1];

  return result;
}

static inline
StaticSmallExpansion<4> operator+(const StaticSmallExpansion<2> &a,
                                  const StaticSmallExpansion<2> &b) {
  auto t1 = a + exact(b.data()[0]);

  StaticSmallExpansion<2> t2;
  t2.data()[0] = t1.data()[1];
  t2.data()[1] = t1.data()[2];

  auto t3 = t2 + exact(b.data()[1]);

  StaticSmallExpansion<4> result;
  result.data()[0] = t1.data()[0];
  result.data()[1] = t3.data()[0];
  result.data()[2] = t3.data()[1];
  result.data()[3] = t3.data()[2];

  return result;
}

static inline
StaticSmallExpansion<2> operator-(const StaticSmallExpansion<1> &a,
                                  const StaticSmallExpansion<1> &b) {
  double x = a.data()[0] - b.data()[0];

  double bvirt = a.data()[0] - x;
  double avirt = x + bvirt;

  double errB = bvirt - b.data()[0];
  double errA = a.data()[0] - avirt;

  double y = errA + errB;

  StaticSmallExpansion<2> result;

  result.data()[0] = y;
  result.data()[1] = x;

  return result;
}

static inline
StaticSmallExpansion<3> operator-(const StaticSmallExpansion<2> &a,
                                  const StaticSmallExpansion<1> &b) {
  auto t1 = exact(a.data()[0]) - exact(b.data()[0]);
  auto t2 = exact(a.data()[1]) + exact(t1.data()[1]);

  StaticSmallExpansion<3> result;
  result.data()[0] = t1.data()[0];
  result.data()[1] = t2.data()[0];
  result.data()[2] = t2.data()[1];

  return result;
}

static inline
StaticSmallExpansion<4> operator-(const StaticSmallExpansion<2> &a,
                                  const StaticSmallExpansion<2> &b) {
  auto t1 = a - exact(b.data()[0]);

  StaticSmallExpansion<2> t2;
  t2.data()[0] = t1.data()[1];
  t2.data()[1] = t1.data()[2];

  auto t3 = t2 - exact(b.data()[1]);

  StaticSmallExpansion<4> result;
  result.data()[0] = t1.data()[0];
  result.data()[1] = t3.data()[0];
  result.data()[2] = t3.data()[1];
  result.data()[3] = t3.data()[2];

  return result;
}

static inline
void split(double x, double &hi, double &lo) {
  double v = splitter * x;
  double big = v - x;
  hi = v - big;
  lo = x - hi;
}

static inline
void twoProduct(double a, double b,
                double ahi, double alo,
                double bhi, double blo,
                double &x, double &y) {
  x = a * b;
  double err1 = x - (ahi * bhi);
  double err2 = err1 - (alo * bhi);
  double err3 = err2 - (ahi * blo);
  y = (alo * blo) - err3;
}

static inline
void twoProduct(double a, double b, double bhi, double blo,
                double &x, double &y) {
  double alo, ahi;
  split(a, ahi, alo);
  return twoProduct(a, b, ahi, alo, bhi, blo, x, y);
}

static inline
void twoProduct(double a, double b, double &x, double &y) {
  double blo, bhi;
  split(b, bhi, blo);
  return twoProduct(a, b, bhi, blo, x, y);
}

static inline
StaticSmallExpansion<2> operator*(const StaticSmallExpansion<1> &a,
                                  const StaticSmallExpansion<1> &b) {
  double x, y;
  twoProduct(a.data()[0], b.data()[0], x, y);

  StaticSmallExpansion<2> result;

  result.data()[0] = y;
  result.data()[1] = x;

  return result;
}

static inline
StaticSmallExpansion<4> operator*(const StaticSmallExpansion<2> &a,
                                  const StaticSmallExpansion<1> &b) {
  double t0, t1, t2, r0;

  double blo, bhi;
  split(b.data()[0], bhi, blo);

  twoProduct(a.data()[0], b.data()[0], bhi, blo, t0, r0);
  twoProduct(a.data()[1], b.data()[0], bhi, blo, t2, t1);

  auto t3 = exact(t0) + exact(t1);
  double r1 = t3.data()[0];

  double r3 = t2 + t3.data()[1];
  double bvirt = r3 - t2;
  double r2 = t3.data()[1] - bvirt;

  StaticSmallExpansion<4> result;

  result.data()[0] = r0;
  result.data()[1] = r1;
  result.data()[2] = r2;
  result.data()[3] = r3;

  return result;
}

static inline
StaticSmallExpansion<4> operator*(const StaticSmallExpansion<1> &a,
                                  const StaticSmallExpansion<2> &b) {
  return b * a;
}
