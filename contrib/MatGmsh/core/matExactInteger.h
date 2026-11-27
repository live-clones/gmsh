// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MAT_EXACT_INTEGER_H
#define MAT_EXACT_INTEGER_H

// Signed integers of any size, enough for exact constructions from double
// inputs: every finite double is an integer times a power of two, so a set of
// doubles scaled by a common power of two are integers (fromDouble), on which
// sums and products are exact. divide() gives the double nearest to a
// quotient, ties to even, as IEEE rounding does. Small numbers of limbs are
// expected (a few hundred bits): schoolbook products, bitwise division.

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <vector>

namespace matgmsh::exact {

// limbs of 32 bits, the first ones in place (no allocation for the few
// hundred bits usually met)
class Limbs {
public:
  Limbs() = default;
  Limbs(const Limbs &o) { *this = o; }
  Limbs &operator=(const Limbs &o)
  {
    if(this == &o) return *this;
    size_ = 0;
    reserve(o.size_);
    std::copy(o.data(), o.data() + o.size_, data());
    size_ = o.size_;
    return *this;
  }
  std::size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }
  std::uint32_t &operator[](std::size_t i) { return data()[i]; }
  std::uint32_t operator[](std::size_t i) const { return data()[i]; }
  std::uint32_t back() const { return data()[size_ - 1]; }
  const std::uint32_t *begin() const { return data(); }
  const std::uint32_t *end() const { return data() + size_; }
  void pop_back() { --size_; }
  void push_back(std::uint32_t v)
  {
    reserve(size_ + 1);
    data()[size_++] = v;
  }
  void assign(std::size_t n, std::uint32_t v)
  {
    size_ = 0;
    reserve(n);
    std::fill(data(), data() + n, v);
    size_ = n;
  }
  void resize(std::size_t n, std::uint32_t v)
  {
    reserve(n);
    if(n > size_) std::fill(data() + size_, data() + n, v);
    size_ = n;
  }

private:
  static const std::size_t inPlace = 24;
  std::uint32_t local_[inPlace];
  std::vector<std::uint32_t> heap_;
  std::size_t size_ = 0;
  std::uint32_t *data() { return heap_.empty() ? local_ : heap_.data(); }
  const std::uint32_t *data() const { return heap_.empty() ? local_ : heap_.data(); }
  void reserve(std::size_t n)
  {
    if(n <= inPlace && heap_.empty()) return;
    if(heap_.empty()) {
      heap_.resize(std::max(n, 2 * inPlace));
      std::copy(local_, local_ + size_, heap_.data());
    }
    else if(n > heap_.size())
      heap_.resize(std::max(n, 2 * heap_.size()));
  }
};

class Integer {
public:
  Integer() = default;
  explicit Integer(std::int64_t v)
  {
    negative_ = v < 0;
    std::uint64_t m = v < 0 ? std::uint64_t(0) - std::uint64_t(v) : std::uint64_t(v);
    while(m) {
      limbs_.push_back(std::uint32_t(m));
      m >>= 32;
    }
  }

  // The power of two by which x must be multiplied to be an odd integer (or
  // the smallest one making it an integer): -(the exponent of its last bit).
  // Zero needs none.
  static int scaleOf(double x)
  {
    if(x == 0.) return std::numeric_limits<int>::min();
    int e;
    const double m = std::frexp(std::abs(x), &e); // x = m 2^e, 0.5 <= m < 1
    std::uint64_t mantissa = std::uint64_t(std::ldexp(m, 53));
    int lowest = e - 53;
    while(!(mantissa & 1u)) {
      mantissa >>= 1;
      ++lowest;
    }
    return -lowest;
  }

  // x 2^shift, which must be an integer (shift >= scaleOf(x))
  static Integer fromDouble(double x, int shift)
  {
    if(!std::isfinite(x)) throw std::runtime_error("Exact integer from a nonfinite double");
    Integer r;
    if(x == 0.) return r;
    int e;
    const double m = std::frexp(std::abs(x), &e);
    std::uint64_t mantissa = std::uint64_t(std::ldexp(m, 53));
    int exponent = e - 53 + shift; // x 2^shift = mantissa 2^exponent
    while(exponent < 0) {
      if(mantissa & 1u) throw std::runtime_error("Exact integer: the scale is too small");
      mantissa >>= 1;
      ++exponent;
    }
    while(mantissa) {
      r.limbs_.push_back(std::uint32_t(mantissa));
      mantissa >>= 32;
    }
    r.negative_ = x < 0.;
    return r.shifted(std::size_t(exponent));
  }

  bool isZero() const { return limbs_.empty(); }
  int sign() const { return isZero() ? 0 : (negative_ ? -1 : 1); }
  std::size_t bits() const
  {
    if(limbs_.empty()) return 0;
    std::size_t n = 32 * (limbs_.size() - 1);
    for(std::uint32_t top = limbs_.back(); top; top >>= 1) ++n;
    return n;
  }
  Integer operator-() const
  {
    Integer r = *this;
    if(!r.isZero()) r.negative_ = !r.negative_;
    return r;
  }
  Integer magnitude() const
  {
    Integer r = *this;
    r.negative_ = false;
    return r;
  }
  // this 2^left
  Integer shifted(std::size_t left) const
  {
    if(isZero() || !left) return *this;
    Integer r;
    r.negative_ = negative_;
    const std::size_t words = left / 32, bitsLeft = left % 32;
    r.limbs_.assign(words, 0u);
    std::uint32_t carry = 0;
    for(std::uint32_t limb : limbs_) {
      r.limbs_.push_back(bitsLeft ? (limb << bitsLeft) | carry : limb);
      carry = bitsLeft ? limb >> (32 - bitsLeft) : 0u;
    }
    if(carry) r.limbs_.push_back(carry);
    return r;
  }
  // the magnitude to about 64 bits: top 2^exponent, top < 2^64
  void top64(std::uint64_t &top, long &exponent) const
  {
    const std::size_t n = bits();
    if(n <= 64) {
      top = low64();
      exponent = 0;
      return;
    }
    const std::size_t drop = n - 64;
    top = 0;
    for(int k = 0; k < 64; ++k) {
      const std::size_t bit = drop + std::size_t(k);
      if((limbs_[bit / 32] >> (bit % 32)) & 1u) top |= std::uint64_t(1) << k;
    }
    exponent = long(drop);
  }
  // the lowest 64 bits of the magnitude
  std::uint64_t low64() const
  {
    std::uint64_t v = 0;
    for(std::size_t i = 0; i < std::min<std::size_t>(2, limbs_.size()); ++i)
      v |= std::uint64_t(limbs_[i]) << (32 * i);
    return v;
  }

  friend int compareMagnitude(const Integer &a, const Integer &b)
  {
    if(a.limbs_.size() != b.limbs_.size()) return a.limbs_.size() < b.limbs_.size() ? -1 : 1;
    for(std::size_t i = a.limbs_.size(); i-- > 0;)
      if(a.limbs_[i] != b.limbs_[i]) return a.limbs_[i] < b.limbs_[i] ? -1 : 1;
    return 0;
  }
  friend int compare(const Integer &a, const Integer &b)
  {
    if(a.sign() != b.sign()) return a.sign() < b.sign() ? -1 : 1;
    const int m = compareMagnitude(a, b);
    return a.negative_ ? -m : m;
  }
  friend bool operator==(const Integer &a, const Integer &b) { return compare(a, b) == 0; }
  friend bool operator!=(const Integer &a, const Integer &b) { return compare(a, b) != 0; }

  friend Integer operator+(const Integer &a, const Integer &b)
  {
    if(a.negative_ == b.negative_) {
      Integer r = addMagnitudes(a, b);
      r.negative_ = a.negative_ && !r.isZero();
      return r;
    }
    // different signs: the larger magnitude minus the smaller one
    const int m = compareMagnitude(a, b);
    if(m == 0) return Integer();
    const Integer &large = m > 0 ? a : b, &small = m > 0 ? b : a;
    Integer r = subtractMagnitudes(large, small);
    r.negative_ = large.negative_ && !r.isZero();
    return r;
  }
  friend Integer operator-(const Integer &a, const Integer &b) { return a + (-b); }
  friend Integer operator*(const Integer &a, const Integer &b)
  {
    Integer r;
    if(a.isZero() || b.isZero()) return r;
    r.limbs_.assign(a.limbs_.size() + b.limbs_.size(), 0u);
    for(std::size_t i = 0; i < a.limbs_.size(); ++i) {
      std::uint64_t carry = 0;
      for(std::size_t j = 0; j < b.limbs_.size(); ++j) {
        const std::uint64_t t = std::uint64_t(a.limbs_[i]) * b.limbs_[j] + r.limbs_[i + j] + carry;
        r.limbs_[i + j] = std::uint32_t(t);
        carry = t >> 32;
      }
      r.limbs_[i + b.limbs_.size()] = std::uint32_t(carry);
    }
    r.trim();
    r.negative_ = a.negative_ != b.negative_;
    return r;
  }

  // the quotient and the remainder of |a| by |b| (b not zero), both
  // nonnegative: bitwise long division
  friend void divideMagnitudes(const Integer &a, const Integer &b, Integer &quotient,
                               Integer &remainder)
  {
    if(b.isZero()) throw std::runtime_error("Exact integer division by zero");
    quotient = Integer();
    remainder = a.magnitude();
    const Integer divisor = b.magnitude();
    if(compareMagnitude(remainder, divisor) < 0) return;
    const std::size_t shift = remainder.bits() - divisor.bits();
    quotient.limbs_.assign(shift / 32 + 1, 0u);
    for(std::size_t i = shift + 1; i-- > 0;) {
      const Integer part = divisor.shifted(i);
      if(compareMagnitude(remainder, part) >= 0) {
        remainder = subtractMagnitudes(remainder, part);
        quotient.limbs_[i / 32] |= std::uint32_t(1) << (i % 32);
      }
    }
    quotient.trim();
  }

private:
  bool negative_ = false;
  Limbs limbs_; // little endian, no leading zero limb

  void trim()
  {
    while(!limbs_.empty() && !limbs_.back()) limbs_.pop_back();
    if(limbs_.empty()) negative_ = false;
  }
  static Integer addMagnitudes(const Integer &a, const Integer &b)
  {
    Integer r;
    const std::size_t n = std::max(a.limbs_.size(), b.limbs_.size());
    r.limbs_.resize(n + 1, 0u);
    std::uint64_t carry = 0;
    for(std::size_t i = 0; i < n; ++i) {
      const std::uint64_t t = std::uint64_t(i < a.limbs_.size() ? a.limbs_[i] : 0u) +
                              (i < b.limbs_.size() ? b.limbs_[i] : 0u) + carry;
      r.limbs_[i] = std::uint32_t(t);
      carry = t >> 32;
    }
    r.limbs_[n] = std::uint32_t(carry);
    r.trim();
    return r;
  }
  // |a| - |b| with |a| >= |b|
  static Integer subtractMagnitudes(const Integer &a, const Integer &b)
  {
    Integer r;
    r.limbs_.resize(a.limbs_.size(), 0u);
    std::int64_t borrow = 0;
    for(std::size_t i = 0; i < a.limbs_.size(); ++i) {
      std::int64_t t = std::int64_t(a.limbs_[i]) - (i < b.limbs_.size() ? b.limbs_[i] : 0u) - borrow;
      borrow = t < 0;
      if(t < 0) t += std::int64_t(1) << 32;
      r.limbs_[i] = std::uint32_t(t);
    }
    r.trim();
    return r;
  }
};

// divide() by long division: any magnitude, the subnormal range included
inline double divideLong(const Integer &n, const Integer &d, int exponent)
{
  if(d.isZero()) throw std::runtime_error("Exact quotient with a zero denominator");
  if(n.isZero()) return 0.;
  const bool negative = n.sign() != d.sign();
  // a quotient of 55 or 56 bits: num / den = n / d 2^k
  const long k = 55 + long(d.bits()) - long(n.bits());
  const Integer num = k >= 0 ? n.magnitude().shifted(std::size_t(k)) : n.magnitude();
  const Integer den = k >= 0 ? d.magnitude() : d.magnitude().shifted(std::size_t(-k));
  Integer q, r;
  divideMagnitudes(num, den, q, r);
  const std::uint64_t quotient = q.low64();
  const int nb = int(q.bits()); // 55 or 56
  // the value is in [2^top, 2^(top + 1)): fewer bits kept below the normal range
  const long top = long(nb) - 1 + exponent - k;
  const long keep = top >= -1022 ? 53 : 53 - (-1022 - top);
  double value;
  if(keep < 0)
    value = 0.;
  else {
    const int drop = nb - int(keep);
    std::uint64_t mantissa = drop >= 64 ? 0u : quotient >> drop;
    const std::uint64_t rest = drop >= 64 ? quotient : quotient & ((std::uint64_t(1) << drop) - 1u);
    const std::uint64_t half = std::uint64_t(1) << (drop - 1);
    const bool sticky = !r.isZero();
    if(rest > half || (rest == half && (sticky || (mantissa & 1u)))) ++mantissa;
    value = std::ldexp(double(mantissa), int(drop + exponent - k));
  }
  return negative ? -value : value;
}

// The double nearest to (n / d) 2^exponent, ties to even, signed zero for a
// zero numerator, an infinity beyond the largest double (d not zero). An
// estimate from the leading bits, moved to the neighbouring double while the
// exact value is beyond a midpoint (compared exactly); long division near the
// ends of the range.
inline double divide(const Integer &n, const Integer &d, int exponent)
{
  if(d.isZero()) throw std::runtime_error("Exact quotient with a zero denominator");
  if(n.isZero()) return 0.;
  const bool negative = n.sign() != d.sign();
  const Integer N = n.magnitude(), D = d.magnitude();
  std::uint64_t tn, td;
  long en, ed;
  N.top64(tn, en);
  D.top64(td, ed);
  double q = std::ldexp(double(tn) / double(td), int(en - ed + exponent));
  const double smallest = std::ldexp(1., -1020), largest = std::ldexp(1., 1020);
  if(!(q > smallest && q < largest)) return divideLong(n, d, exponent);
  // x = mantissa 2^e, mantissa < 2^53
  const auto split = [](double x, std::uint64_t &mantissa, int &e) {
    const double m = std::frexp(x, &e);
    mantissa = std::uint64_t(std::ldexp(m, 53));
    e -= 53;
  };
  // the sign of N/D 2^exponent - (a + b) / 2, a and b adjacent positive doubles
  const auto side = [&](double a, double b) {
    std::uint64_t ma, mb;
    int ea, eb;
    split(a, ma, ea);
    split(b, mb, eb);
    const int low = std::min(ea, eb), e = low - 1;
    const std::uint64_t m = (ma << (ea - low)) + (mb << (eb - low)); // (a + b) / 2 = m 2^e
    // N 2^exponent ? D m 2^e
    const long shift = long(exponent) - e;
    Integer left = N, right = D * Integer(std::int64_t(m)); // (m < 2^56)
    if(shift >= 0)
      left = left.shifted(std::size_t(shift));
    else
      right = right.shifted(std::size_t(-shift));
    return compare(left, right);
  };
  const auto even = [&](double a, double b) {
    std::uint64_t ma, mb;
    int ea, eb;
    split(a, ma, ea);
    split(b, mb, eb);
    return (ma & 1u) == 0 ? a : b;
  };
  for(int step = 0; step < 64; ++step) {
    const double up = std::nextafter(q, std::numeric_limits<double>::infinity());
    const double down = std::nextafter(q, 0.);
    const int above = side(q, up);
    if(above > 0) {
      q = up;
      continue;
    }
    const int below = side(down, q);
    if(below < 0) {
      q = down;
      continue;
    }
    if(above == 0) q = even(q, up);
    else if(below == 0)
      q = even(down, q);
    return negative ? -q : q;
  }
  return divideLong(n, d, exponent);
}

} // namespace matgmsh::exact

#endif
