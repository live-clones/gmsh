#include "quadSurfaceWinslow3D.h"
#include <iostream>
#include <stdexcept>

using namespace QuadOptimizer::SurfaceWinslow3D;

namespace {
void require(bool ok, const char *message)
{
  if(!ok) throw std::runtime_error(message);
}

// An arbitrary rigid rotation followed by a translation and uniform scaling.
P transform(const P &p)
{
  const double c = std::cos(.73), s = std::sin(.73);
  return {{17. + 3. * (c * p[0] - s * p[2]),
           -23. + 3. * (s * p[0] + c * p[2]), 11. - 3. * p[1]}};
}

void exercise(bool mixed)
{
  const int n = 12;
  std::vector<P> points;
  std::vector<bool> fixed;
  std::vector<std::vector<std::size_t>> cells;
  for(int j = 0; j <= n; ++j) for(int i = 0; i <= n; ++i) {
    const bool boundary = !i || !j || i == n || j == n;
    const double u = (i + (boundary ? 0. : .15 * std::sin(i + j))) / n;
    const double v = (j + (boundary ? 0. : .12 * std::cos(i - j))) / n;
    points.push_back({{u, v, .1 * (u * u + v * v)}});
    fixed.push_back(boundary);
  }
  for(int j = 0; j < n; ++j) for(int i = 0; i < n; ++i) {
    const std::size_t a = j * (n + 1) + i;
    if(mixed && (i + j) % 5 == 0) {
      cells.push_back({a, a + 1, a + n + 2});
      cells.push_back({a, a + n + 2, a + n + 1});
    }
    else cells.push_back({a, a + 1, a + n + 2, a + n + 1});
  }
  Problem problem(points, cells, fixed, 1. / n, 1. / 127.);
  std::vector<double> x(problem.variables(), 0.), gradient, ignored;
  const double initial = problem.evaluate(x, gradient);
  for(std::size_t i = 0; i < x.size(); ++i) {
    const double step = 1.e-5;
    x[i] = step; const double plus = problem.evaluate(x, ignored);
    x[i] = -step; const double minus = problem.evaluate(x, ignored);
    x[i] = 0.;
    const double finiteDifference = (plus - minus) / (2. * step);
    require(std::abs(finiteDifference - gradient[i]) <
              1.e-6 * std::max(1., std::abs(finiteDifference)),
            "incorrect physical Winslow gradient");
  }
  std::vector<P> rotated;
  for(const P &p : points) rotated.push_back(transform(p));
  Problem rotatedProblem(rotated, cells, fixed, 3. / n, 1. / 127.);
  std::vector<double> rotatedX(rotatedProblem.variables(), 0.), rotatedGradient;
  const double rotatedInitial = rotatedProblem.evaluate(rotatedX, rotatedGradient);
  require(std::abs(rotatedInitial - initial) < 1.e-8,
          "initial energy depends on world orientation or scale");
  problem.solve(x, 150);
  rotatedProblem.solve(rotatedX, 150);
  const auto result = problem.positions(x, true);
  const auto rotatedResult = rotatedProblem.positions(rotatedX, true);
  require(problem.evaluate(x, gradient) < initial * .999,
          "Winslow failed to improve perturbed surface");
  for(std::size_t i = 0; i < points.size(); ++i) {
    if(fixed[i]) {
      require(result[i] == points[i], "fixed surface vertex moved");
      require(rotatedResult[i] == rotated[i], "rotated fixed vertex moved");
    }
    const P delta = sub(transform(result[i]), rotatedResult[i]);
    require(std::sqrt(dot(delta, delta)) < 1.e-4,
            "smoothed surface depends on world orientation or scale");
  }
}
}

int main()
{
  try {
    exercise(false);
    exercise(true);
    std::cout << "3D mean-plane Winslow: gradient, rigid transformation, scale, "
                 "energy and fixed vertices PASS\n";
  }
  catch(const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
