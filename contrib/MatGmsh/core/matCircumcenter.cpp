#include "matCircumcenter.h"

#include <boost/multiprecision/cpp_int.hpp>
#include "robustPredicates.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <mutex>
#include <stdexcept>

#ifdef __FAST_MATH__
#error "Circumcenter interval certificates require IEEE arithmetic; disable fast-math"
#endif

namespace matgmsh::circumcenter {
namespace {

static_assert(std::numeric_limits<double>::is_iec559,
              "Circumcenter interval certificates require IEEE doubles");
constexpr double infinity = std::numeric_limits<double>::infinity();

// Every elementary operation is widened by one representable value in both
// directions. This includes subtraction of the ORIGINAL coordinates, whose
// rounding must not be lost before the interval calculation. No reassociation
// or fast-math is permitted. An overflowing/indeterminate interval is rejected
// by the certificate and sent to rational arithmetic.
struct Interval {
  double lo, hi;
  explicit Interval(double x) : lo(x), hi(x) {}
  Interval(double l, double h) : lo(l), hi(h) {}
};

double down(double x) { return std::nextafter(x, -infinity); }
double up(double x) { return std::nextafter(x, infinity); }

Interval operator+(const Interval &a, const Interval &b)
{
  return {down(a.lo + b.lo), up(a.hi + b.hi)};
}
Interval operator-(const Interval &a, const Interval &b)
{
  return {down(a.lo - b.hi), up(a.hi - b.lo)};
}
Interval operator*(const Interval &a, const Interval &b)
{
  const double p[] = {a.lo * b.lo, a.lo * b.hi,
                      a.hi * b.lo, a.hi * b.hi};
  for(double x : p)
    if(!std::isfinite(x)) return {-infinity, infinity};
  return {down(*std::min_element(p, p + 4)),
          up(*std::max_element(p, p + 4))};
}
Interval operator/(const Interval &a, const Interval &b)
{
  if(!(b.lo > 0. || b.hi < 0.)) return {-infinity, infinity};
  const Interval reciprocal(down(1. / b.hi), up(1. / b.lo));
  return a * reciprocal;
}

bool certified(const double *a, const double *b, const double *c,
               const double *d, const std::array<double, 3> &center)
{
  Interval A[] = {Interval(a[0]) - Interval(d[0]),
                  Interval(a[1]) - Interval(d[1]),
                  Interval(a[2]) - Interval(d[2])};
  Interval B[] = {Interval(b[0]) - Interval(d[0]),
                  Interval(b[1]) - Interval(d[1]),
                  Interval(b[2]) - Interval(d[2])};
  Interval C[] = {Interval(c[0]) - Interval(d[0]),
                  Interval(c[1]) - Interval(d[1]),
                  Interval(c[2]) - Interval(d[2])};
  const Interval a2 = A[0] * A[0] + A[1] * A[1] + A[2] * A[2];
  const Interval b2 = B[0] * B[0] + B[1] * B[1] + B[2] * B[2];
  const Interval c2 = C[0] * C[0] + C[1] * C[1] + C[2] * C[2];
  const Interval determinant =
      A[0] * (B[1] * C[2] - B[2] * C[1]) -
      A[1] * (B[0] * C[2] - B[2] * C[0]) +
      A[2] * (B[0] * C[1] - B[1] * C[0]);
  if(!std::isfinite(determinant.lo) || !std::isfinite(determinant.hi) ||
     !(determinant.lo > 0. || determinant.hi < 0.))
    return false;
  const Interval denominator = Interval(2.) * determinant;
  const Interval x = Interval(d[0]) +
      (a2 * (B[1] * C[2] - B[2] * C[1]) -
       b2 * (A[1] * C[2] - A[2] * C[1]) +
       c2 * (A[1] * B[2] - A[2] * B[1])) / denominator;
  const Interval y = Interval(d[1]) -
      (a2 * (B[0] * C[2] - B[2] * C[0]) -
       b2 * (A[0] * C[2] - A[2] * C[0]) +
       c2 * (A[0] * B[2] - A[2] * B[0])) / denominator;
  const Interval z = Interval(d[2]) +
      (a2 * (B[0] * C[1] - B[1] * C[0]) -
       b2 * (A[0] * C[1] - A[1] * C[0]) +
       c2 * (A[0] * B[1] - A[1] * B[0])) / denominator;
  const Interval coordinates[] = {x, y, z};

  double localSize = 0.;
  const double *points[] = {a, b, c, d};
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < i; ++j)
      for(int k = 0; k < 3; ++k)
        localSize = std::max(localSize, std::abs(points[i][k] - points[j][k]));
  if(!std::isfinite(localSize)) return false;
  for(int k = 0; k < 3; ++k) {
    const auto &q = coordinates[k];
    if(!std::isfinite(center[k]) || !std::isfinite(q.lo) || !std::isfinite(q.hi))
      return false;
    const double magnitude = std::abs(center[k]);
    const double ulp = up(magnitude) - magnitude;
    const double tolerance = 1.e-10 * localSize + 8. * ulp;
    const double error = up(std::max(std::abs(center[k] - q.lo),
                                     std::abs(center[k] - q.hi)));
    if(!std::isfinite(tolerance) || !(error <= tolerance)) return false;
  }
  return true;
}

Result exact(const double *a, const double *b, const double *c,
             const double *d)
{
  using Rational = boost::multiprecision::cpp_rational;
  Rational A[3], B[3], C[3];
  for(int k = 0; k < 3; ++k) {
    A[k] = Rational(a[k]) - Rational(d[k]);
    B[k] = Rational(b[k]) - Rational(d[k]);
    C[k] = Rational(c[k]) - Rational(d[k]);
  }
  const Rational det =
      A[0] * (B[1] * C[2] - B[2] * C[1]) -
      A[1] * (B[0] * C[2] - B[2] * C[0]) +
      A[2] * (B[0] * C[1] - B[1] * C[0]);
  Result result;
  result.determinant = det.convert_to<double>();
  if(det == 0) {
    result.status = Status::Degenerate;
    for(int k = 0; k < 3; ++k) {
      // Preserve the old substitute bit for bit where representable, but do
      // not overflow an otherwise representable average at extreme scales.
      result.center[k] = (a[k] + b[k] + c[k] + d[k]) * .25;
      if(!std::isfinite(result.center[k])) {
        const Rational average =
            (Rational(a[k]) + Rational(b[k]) + Rational(c[k]) + Rational(d[k])) / 4;
        result.center[k] = average.convert_to<double>();
      }
    }
    return result;
  }
  const Rational a2 = A[0] * A[0] + A[1] * A[1] + A[2] * A[2];
  const Rational b2 = B[0] * B[0] + B[1] * B[1] + B[2] * B[2];
  const Rational c2 = C[0] * C[0] + C[1] * C[1] + C[2] * C[2];
  const Rational x = Rational(d[0]) +
      (a2 * (B[1] * C[2] - B[2] * C[1]) -
       b2 * (A[1] * C[2] - A[2] * C[1]) +
       c2 * (A[1] * B[2] - A[2] * B[1])) / (2 * det);
  const Rational y = Rational(d[1]) -
      (a2 * (B[0] * C[2] - B[2] * C[0]) -
       b2 * (A[0] * C[2] - A[2] * C[0]) +
       c2 * (A[0] * B[2] - A[2] * B[0])) / (2 * det);
  const Rational z = Rational(d[2]) +
      (a2 * (B[0] * C[1] - B[1] * C[0]) -
       b2 * (A[0] * C[1] - A[1] * C[0]) +
       c2 * (A[0] * B[1] - A[1] * B[0])) / (2 * det);
  result.center = {x.convert_to<double>(), y.convert_to<double>(), z.convert_to<double>()};
  result.status = Status::Exact;
  return result;
}

} // namespace

Result compute(const double *a, const double *b, const double *c,
               const double *d)
{
  for(const double *p : {a, b, c, d})
    for(int k = 0; k < 3; ++k)
      if(!std::isfinite(p[k]))
        throw std::runtime_error("Cannot construct a circumcenter from nonfinite coordinates");

  // Keep the operation order of the historical double construction.
  double A[3] = {a[0]-d[0], a[1]-d[1], a[2]-d[2]};
  double B[3] = {b[0]-d[0], b[1]-d[1], b[2]-d[2]};
  double C[3] = {c[0]-d[0], c[1]-d[1], c[2]-d[2]};
  double a2 = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
  double b2 = B[0]*B[0] + B[1]*B[1] + B[2]*B[2];
  double c2 = C[0]*C[0] + C[1]*C[1] + C[2]*C[2];
  // Avoid invoking the floating predicates outside their finite arithmetic
  // range. The rational branch also handles determinant underflow exactly.
  const double scale = std::max({std::abs(A[0]), std::abs(A[1]), std::abs(A[2]),
      std::abs(B[0]), std::abs(B[1]), std::abs(B[2]),
      std::abs(C[0]), std::abs(C[1]), std::abs(C[2])});
  Result result;
  if(scale > 1.e-90 && scale < 1.e90) {
    result.determinant = robustPredicates::orient3d(const_cast<double *>(a), const_cast<double *>(b),
                                 const_cast<double *>(c), const_cast<double *>(d));
    if(result.determinant != 0. && std::isfinite(result.determinant)) {
      const double inv = 1.0 / (2.0 * result.determinant);
      result.center[0] = d[0] + inv * (
          a2*(B[1]*C[2] - B[2]*C[1]) -
          b2*(A[1]*C[2] - A[2]*C[1]) +
          c2*(A[1]*B[2] - A[2]*B[1]));
      result.center[1] = d[1] - inv * (
          a2*(B[0]*C[2] - B[2]*C[0]) -
          b2*(A[0]*C[2] - A[2]*C[0]) +
          c2*(A[0]*B[2] - A[2]*B[0]));
      result.center[2] = d[2] + inv * (
          a2*(B[0]*C[1] - B[1]*C[0]) -
          b2*(A[0]*C[1] - A[1]*C[0]) +
          c2*(A[0]*B[1] - A[1]*B[0]));
      if(certified(a, b, c, d, result.center)) return result;
    }
  }
  result = exact(a, b, c, d);
  for(double x : result.center)
    if(!std::isfinite(x))
      throw std::runtime_error("Exact circumcenter cannot be represented by finite coordinates");
  return result;
}

} // namespace matgmsh::circumcenter
