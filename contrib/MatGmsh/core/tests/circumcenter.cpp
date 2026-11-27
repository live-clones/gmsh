#include "matCircumcenter.h"

#include "matExactInteger.h"
#include "robustPredicates.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>

namespace cc = matgmsh::circumcenter;
using Point = std::array<double, 3>;
using Tet = std::array<Point, 4>;
using matgmsh::exact::Integer;

// Exact rationals for the reference, without normalization: numerator and a
// positive denominator.
struct Rational {
  Integer n, d{Integer(1)};
  Rational() : n(Integer(0)) {}
  explicit Rational(const Integer &value) : n(value) {}
  Rational(const Integer &num, const Integer &den) : n(num), d(den)
  {
    if(d.sign() < 0) {
      n = -n;
      d = -d;
    }
  }
  bool isZero() const { return n.isZero(); }
};
static Rational operator+(const Rational &a, const Rational &b) { return {a.n * b.d + b.n * a.d, a.d * b.d}; }
static Rational operator-(const Rational &a, const Rational &b) { return {a.n * b.d - b.n * a.d, a.d * b.d}; }
static Rational operator*(const Rational &a, const Rational &b) { return {a.n * b.n, a.d * b.d}; }
static Rational operator/(const Rational &a, const Rational &b) { return {a.n * b.d, a.d * b.n}; }
static bool largerMagnitude(const Rational &a, const Rational &b)
{
  return compareMagnitude(a.n * b.d, b.n * a.d) > 0;
}

static void require(bool condition, const char *message)
{
  if(!condition) throw std::runtime_error(message);
}

static cc::Result compute(const Tet &p)
{
  return cc::compute(p[0].data(), p[1].data(), p[2].data(), p[3].data());
}

// Independent reference: exact Gaussian elimination of the three equidistance
// equations, with pivoting. It does not use the production cofactor formula.
// The coordinates are scaled by a common power of two to be integers.
static Point reference(const Tet &p)
{
  int shift = 0;
  bool any = false;
  for(const auto &point : p)
    for(double x : point)
      if(x != 0.) {
        shift = any ? std::max(shift, Integer::scaleOf(x)) : Integer::scaleOf(x);
        any = true;
      }
  Rational matrix[3][4];
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      const Rational edge(Integer::fromDouble(p[i][j], shift) - Integer::fromDouble(p[3][j], shift));
      matrix[i][j] = edge + edge;
      matrix[i][3] = matrix[i][3] + edge * edge;
    }
  }
  for(int k = 0; k < 3; ++k) {
    int pivot = k;
    for(int i = k + 1; i < 3; ++i)
      if(largerMagnitude(matrix[i][k], matrix[pivot][k])) pivot = i;
    require(!matrix[pivot][k].isZero(), "Singular reference system");
    for(int j = k; j < 4; ++j) std::swap(matrix[k][j], matrix[pivot][j]);
    const Rational diagonal = matrix[k][k];
    for(int j = k; j < 4; ++j) matrix[k][j] = matrix[k][j] / diagonal;
    for(int i = 0; i < 3; ++i) {
      if(i == k) continue;
      const Rational factor = matrix[i][k];
      for(int j = k; j < 4; ++j) matrix[i][j] = matrix[i][j] - factor * matrix[k][j];
    }
  }
  // the solution is the center minus the last point, times 2^shift
  Point result;
  for(int j = 0; j < 3; ++j) {
    const Rational coordinate = matrix[j][3] + Rational(Integer::fromDouble(p[3][j], shift));
    result[j] = matgmsh::exact::divide(coordinate.n, coordinate.d, -shift);
  }
  return result;
}

static Point historical(const Tet &p)
{
  const double *a = p[0].data(), *b = p[1].data();
  const double *c = p[2].data(), *d = p[3].data();
  double A[3] = {a[0]-d[0], a[1]-d[1], a[2]-d[2]};
  double B[3] = {b[0]-d[0], b[1]-d[1], b[2]-d[2]};
  double C[3] = {c[0]-d[0], c[1]-d[1], c[2]-d[2]};
  double a2 = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
  double b2 = B[0]*B[0] + B[1]*B[1] + B[2]*B[2];
  double c2 = C[0]*C[0] + C[1]*C[1] + C[2]*C[2];
  const double det = robustPredicates::orient3d(const_cast<double *>(a), const_cast<double *>(b),
                             const_cast<double *>(c), const_cast<double *>(d));
  const double inv = 1. / (2. * det);
  return {{d[0] + inv * (a2*(B[1]*C[2] - B[2]*C[1]) -
                         b2*(A[1]*C[2] - A[2]*C[1]) +
                         c2*(A[1]*B[2] - A[2]*B[1])),
           d[1] - inv * (a2*(B[0]*C[2] - B[2]*C[0]) -
                         b2*(A[0]*C[2] - A[2]*C[0]) +
                         c2*(A[0]*B[2] - A[2]*B[0])),
           d[2] + inv * (a2*(B[0]*C[1] - B[1]*C[0]) -
                         b2*(A[0]*C[1] - A[1]*C[0]) +
                         c2*(A[0]*B[1] - A[1]*B[0]))}};
}

static void checkActual()
{
  // Native A5607 source, tetrahedron 4646733. Coordinates are the exact
  // captured input doubles. The old ARM build produced an error over 8 mm;
  // compiler contraction and evaluation order can change that historical
  // error. The portable contract is agreement with the exact reference.
  const Tet p = {{{-.27084143123117044, -.9708871226842605, -1211.3321243756222},
                  {-.2708414312311706, .9708871226842606, -1211.3321243756222},
                  {-.2808300296882494, -.9808757211413394, -1211.9043707979733},
                  {-.2808300296882495, .9808757211413395, -1211.9043707979733}}};
  const auto before = p;
  const auto result = compute(p);
  const auto expected = reference(p);
  require(result.status == cc::Status::Exact, "Actual bad center missed exact fallback");
  require(result.center == expected, "Actual center differs from independent exact solution");
  require(std::abs(result.center[0] + .2514623567624002) < 1e-16,
          "Actual reference coordinate changed");
  std::cout << "Historical actual-fixture X error (diagnostic): "
            << std::abs(historical(p)[0] - result.center[0]) << '\n';
  require(p == before, "Circumcenter construction moved the seeds");
  std::array<int, 4> order{{0, 1, 2, 3}};
  do {
    Tet permutation{{p[order[0]], p[order[1]], p[order[2]], p[order[3]]}};
    const auto value = compute(permutation);
    require(value.status == cc::Status::Exact && value.center == expected,
            "Vertex permutation changed the exact physical center");
  } while(std::next_permutation(order.begin(), order.end()));
}

static void checkFast()
{
  std::mt19937 random(137);
  std::uniform_real_distribution<double> perturb(-.125, .125);
  for(int i = 0; i < 100; ++i) {
    Tet p{{{0., 0., 0.}, {2., 0., 0.}, {0., 3., 0.}, {0., 0., 4.}}};
    for(auto &point : p)
      for(double &x : point) x += perturb(random);
    const auto result = compute(p);
    require(result.status == cc::Status::Fast, "Well-conditioned tetrahedron used rational fallback");
    const auto old = historical(p);
    require(std::memcmp(old.data(), result.center.data(), sizeof(Point)) == 0,
            "Certified double path changed the historical result");
    const auto expected = reference(p);
    for(int k = 0; k < 3; ++k)
      require(std::abs(result.center[k] - expected[k]) < 1e-12,
              "Certified double center is inaccurate");
  }
}

static void checkDifficultCases()
{
  Tet nearPlane{{{-.44124178135196, 3., -1215.067965240744},
                  {.21383813823437112, 3., -1215.4354034135795},
                  {-.44124178135196, -3., -1215.067965240744},
                  {std::nextafter(.21383813823437112, 1.), -3., -1215.4354034135795}}};
  const auto synthetic = compute(nearPlane);
  require(synthetic.status == cc::Status::Exact && synthetic.center == reference(nearPlane),
          "Nearly coplanar synthetic center is inaccurate");
  // Cancellation in the old formula is compiler-dependent; its magnitude
  // does not determine whether the exact construction is correct.
  std::cout << "Historical synthetic-fixture Z error (diagnostic): "
            << std::abs(historical(nearPlane)[2] - synthetic.center[2]) << '\n';

  // A legitimately distant center must remain distant: precision is not a
  // radius cap or a projection back into the tetrahedron.
  Tet distant{{{0., 0., 0.}, {1., 0., 0.}, {0., 1., 0.}, {.25, .25, 1e-20}}};
  const auto far = compute(distant);
  require(far.center == reference(distant) && std::abs(far.center[2]) > 1e18,
          "Legitimate distant center was altered");

  // Overflow and underflow of the old products must not imply degeneracy.
  for(int exponent : {-400, 400}) {
    const double s = std::ldexp(1., exponent);
    Tet scaled{{{0., 0., 0.}, {2.*s, 0., 0.}, {0., 4.*s, 0.}, {0., 0., 6.*s}}};
    const auto value = compute(scaled);
    require(value.status == cc::Status::Exact && value.center == reference(scaled),
            "Extreme finite scale lost the exact center");
  }

  distant[3][2] = std::numeric_limits<double>::denorm_min();
  bool unrepresentableThrew = false;
  try { compute(distant); }
  catch(const std::runtime_error &) { unrepresentableThrew = true; }
  require(unrepresentableThrew, "Unrepresentable exact center was accepted");

  Tet flat{{{0., 0., 0.}, {2., 0., 0.}, {0., 4., 0.}, {2., 4., 0.}}};
  const auto degenerate = compute(flat);
  require(degenerate.status == cc::Status::Degenerate && degenerate.determinant == 0. &&
              degenerate.center == Point{{1., 2., 0.}},
          "Exact degeneracy must retain an explicit barycenter status");

  for(double bad : {std::numeric_limits<double>::infinity(),
                    std::numeric_limits<double>::quiet_NaN()}) {
    flat[0][0] = bad;
    bool threw = false;
    try { compute(flat); } catch(const std::runtime_error &) { threw = true; }
    require(threw, "Nonfinite input was accepted");
  }
}

int main()
{
  robustPredicates::exactinit(1., 1., 1.);
  try {
    checkFast();
    checkActual();
    checkDifficultCases();
    std::cout << "Circumcenter exact/filtered construction PASS\n";
    return 0;
  }
  catch(const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
