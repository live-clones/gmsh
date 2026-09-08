#include "smallCavityWinslow.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
  using Point = std::array<double, 2>;
  using Triangle = std::array<std::size_t, 3>;
  using Quad = std::array<std::size_t, 4>;

  struct Patch {
    std::vector<Point> points;
    std::vector<bool> fixed;
    std::vector<Triangle> triangles;
    std::vector<Quad> quads;
  };

  void require(bool condition, const std::string &message)
  {
    if(!condition) throw std::runtime_error(message);
  }

  double distance(const Point &a, const Point &b)
  {
    return std::hypot(a[0] - b[0], a[1] - b[1]);
  }

  QuadOptimizer::SmallCavityWinslowOptions options()
  {
    QuadOptimizer::SmallCavityWinslowOptions result;
    result.harmonicInitialization = false;
    result.gradientTolerance = 1.e-10;
    result.functionTolerance = 1.e-14;
    result.stepTolerance = 1.e-14;
    result.maxInnerIterations = 400;
    result.maxOuterIterations = 12;
    return result;
  }

  QuadOptimizer::SmallCavityWinslowResult solve(Patch &patch,
                                              double orientation = 1.)
  {
    const auto before = patch.points;
    const auto result = QuadOptimizer::optimizeLocalSurfacePatchWinslow(
      patch.points, patch.fixed, patch.triangles, patch.quads,
      orientation, options());
    require(result.success && result.untangled && result.minimumJacobian > 0.,
            "solve failed to produce an untangled patch");
    require(std::isfinite(result.initialEnergy) && std::isfinite(result.finalEnergy),
            "nonfinite solver energy");
    for(std::size_t i = 0; i < patch.points.size(); ++i) {
      require(std::isfinite(patch.points[i][0]) && std::isfinite(patch.points[i][1]),
              "nonfinite output coordinate");
      if(patch.fixed[i])
        require(std::memcmp(before[i].data(), patch.points[i].data(),
                            sizeof(Point)) == 0,
                "fixed coordinates were not preserved bitwise");
    }
    return result;
  }

  Patch squarePatch(bool mixed = false)
  {
    Patch result;
    result.points = {{-0., 0.}, {1., 0.}, {2., 0.}, {2., 1.},
                     {2., 2.}, {1., 2.}, {0., 2.}, {0., 1.}, {.55, 1.2}};
    result.fixed.assign(9, true);
    result.fixed[8] = false;
    result.quads = {{0, 1, 8, 7}, {1, 2, 3, 8}, {8, 3, 4, 5}, {7, 8, 5, 6}};
    if(mixed) {
      result.quads.resize(2);
      result.triangles = {{8, 3, 4}, {8, 4, 5}, {7, 8, 5}, {7, 5, 6}};
    }
    return result;
  }

  Patch trianglePatch()
  {
    Patch result;
    constexpr double root3 = 1.73205080756887729353;
    result.points = {{1., 0.}, {.5, .5 * root3}, {-.5, .5 * root3},
                     {-1., 0.}, {-.5, -.5 * root3}, {.5, -.5 * root3}, {.21, -.13}};
    result.fixed.assign(7, true);
    result.fixed.back() = false;
    for(std::size_t i = 0; i < 6; ++i)
      result.triangles.push_back({i, (i + 1) % 6, 6});
    return result;
  }

  void targetShapes()
  {
    Patch triangles = trianglePatch();
    const auto triangleResult = solve(triangles);
    require(distance(triangles.points.back(), {0., 0.}) < 1.e-7,
            "equilateral fan did not recover its center");
    // Each ideal true triangle has two equal singular values and determinant
    // one. This analytic energy fails for the old right-triangle target even
    // though symmetry alone would also place the central vertex at the origin.
    const double idealTriangleEnergy = 6. * (2. + 2. * options().lambda);
    require(std::abs(triangleResult.finalEnergy - idealTriangleEnergy) < 1.e-8,
            "true triangles do not have the equilateral half-unit-area target");
    require(std::abs(triangleResult.minimumJacobian - 1.) < 1.e-7,
            "true-triangle area target changed");

    Patch quads = squarePatch();
    const auto quadResult = solve(quads);
    require(distance(quads.points.back(), {1., 1.}) < 1.e-7,
            "quad patch did not recover its square grid");
    const double idealQuadEnergy = 16. * (2. + 2. * options().lambda);
    require(std::abs(quadResult.finalEnergy - idealQuadEnergy) < 1.e-8,
            "quad corner contributions no longer target the unit square");
    require(std::abs(quadResult.minimumJacobian - 1.) < 1.e-7,
            "quad area target changed");
  }

  void invariance(const Patch &input, const char *name)
  {
    Patch reference = input;
    const auto referenceResult = solve(reference);
    require(referenceResult.finalEnergy < referenceResult.initialEnergy - 1.e-4,
            std::string(name) + ": fixture did not exercise optimization");
    for(const double scale : {1.e-6, 1.e-3, 1., 1.e3, 1.e6}) {
      for(const Point shift : {Point{0., 0.}, Point{37. * scale, -19. * scale}}) {
        Patch transformed = input;
        for(Point &p : transformed.points)
          for(std::size_t k = 0; k < 2; ++k) p[k] = scale * p[k] + shift[k];
        const auto result = solve(transformed);
        for(std::size_t i = 0; i < input.points.size(); ++i) {
          const Point recovered = {(transformed.points[i][0] - shift[0]) / scale,
                                   (transformed.points[i][1] - shift[1]) / scale};
          require(distance(recovered, reference.points[i]) < 2.e-7,
                  std::string(name) + ": solution depends on physical units");
        }
        require(std::abs(result.initialEnergy - referenceResult.initialEnergy) < 1.e-9 &&
                std::abs(result.finalEnergy - referenceResult.finalEnergy) < 1.e-9 &&
                std::abs(result.minimumJacobian - referenceResult.minimumJacobian) < 1.e-7,
                std::string(name) + ": dimensionless energy/Jacobian depends on units");
      }
    }
    // A large translation necessarily loses a few input mantissa bits. Keep
    // the positional check above that representational error, without changing
    // solver tolerances or allowing a different macroscopic solution.
    Patch translated = input;
    const Point shift = {1.e9, -2.e9};
    for(Point &p : translated.points)
      for(std::size_t k = 0; k < 2; ++k) p[k] += shift[k];
    solve(translated);
    for(std::size_t i = 0; i < input.points.size(); ++i)
      require(distance({translated.points[i][0] - shift[0],
                        translated.points[i][1] - shift[1]}, reference.points[i]) < 2.e-6,
              std::string(name) + ": large translation changed the solution");

    // Reflecting the chart and reversing its orientation must commute with
    // the solve, including for the asymmetric mixed patch.
    Patch reflected = input;
    for(Point &p : reflected.points) p[0] = -p[0];
    solve(reflected, -1.);
    for(std::size_t i = 0; i < input.points.size(); ++i)
      require(distance({-reflected.points[i][0], reflected.points[i][1]},
                       reference.points[i]) < 2.e-7,
              std::string(name) + ": reflection/orientation changed the solution");

    // Rotating a non-square patch distinguishes one uniform normalization
    // from separate U/V bounding-box scales, which would change its metric.
    constexpr double angle = .47;
    const double c = std::cos(angle), s = std::sin(angle);
    Patch rotated = input;
    for(Point &p : rotated.points) p = {c * p[0] - s * p[1], s * p[0] + c * p[1]};
    solve(rotated);
    for(std::size_t i = 0; i < input.points.size(); ++i)
      require(distance({c * rotated.points[i][0] + s * rotated.points[i][1],
                        -s * rotated.points[i][0] + c * rotated.points[i][1]},
                       reference.points[i]) < 2.e-7,
              std::string(name) + ": rotation changed the normalized metric");
  }

  void harmonicAndUntangling()
  {
    Patch input = squarePatch();
    input.points.back() = {3.5, -2.};
    solve(input);
    require(distance(input.points.back(), {1., 1.}) < 1.e-6,
            "folded quad initialization was not untangled");
    for(double scale : {1.e-6, 1., 1.e6}) {
      Patch patch = squarePatch();
      patch.points.back() = {3.5, -2.};
      for(Point &p : patch.points)
        for(double &coordinate : p) coordinate = scale * coordinate + 13. * scale;
      const auto before = patch.points;
      require(QuadOptimizer::initializeSmallQuadCavityHarmonic(
                patch.points, 8, patch.quads), "scaled harmonic initializer failed");
      for(std::size_t i = 0; i < 8; ++i)
        require(std::memcmp(before[i].data(), patch.points[i].data(), sizeof(Point)) == 0,
                "harmonic initializer changed a fixed point");
      require(distance(patch.points.back(), {14. * scale, 14. * scale}) < 1.e-12 * scale,
              "harmonic initializer depends on scale/translation");
      const auto result = QuadOptimizer::optimizeSmallQuadCavityWinslow(
        patch.points, 8, patch.quads, options());
      require(result.success && result.untangled,
              "disk entrypoint uses an unnormalized orientation tolerance");
    }
    Patch invalid = squarePatch();
    const auto before = invalid.points;
    invalid.quads.back()[3] = 999;
    require(!QuadOptimizer::initializeSmallQuadCavityHarmonic(
              invalid.points, 8, invalid.quads), "invalid harmonic topology accepted");
    require(invalid.points == before, "failed harmonic initialization mutated input");
  }
} // namespace

int main()
{
  try {
    targetShapes();
    invariance(trianglePatch(), "triangle");
    invariance(squarePatch(), "quad");
    invariance(squarePatch(true), "mixed");
    Patch rectangle = squarePatch(true);
    for(Point &p : rectangle.points) p[0] *= 1.6;
    invariance(rectangle, "mixed rectangle");
    harmonicAndUntangling();
    std::cout << "Winslow target/scale/translation/mixed/fixed/untangling tests passed\n";
    return 0;
  }
  catch(const std::exception &error) {
    std::cerr << "Winslow normalization test: " << error.what() << '\n';
    return 1;
  }
}
