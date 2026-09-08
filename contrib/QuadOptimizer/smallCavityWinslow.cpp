// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "smallCavityWinslow.h"

#include "gmshLBFGS.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <stdexcept>

namespace QuadOptimizer {
  namespace {

    using Point = std::array<double, 2>;

    struct TriangleContribution {
      std::array<std::size_t, 3> vertices;
      std::array<Point, 3> shapeGradients;
    };

    struct WinslowData {
      std::vector<Point> points;
      std::size_t boundaryVertexCount = 0;
      std::vector<TriangleContribution> triangles;
      double epsilon = 1.e-6;
      double lambda = 1. / 127.;
      double minimumJacobian = 0.;
      double energy = 0.;
    };

    constexpr std::size_t quadCornerTriangles[4][3] = {
      {0, 1, 2}, {2, 3, 0}, {1, 2, 3}, {3, 0, 1}};

    double signedArea(const Point &a, const Point &b, const Point &c)
    {
      return .5 * ((b[0] - a[0]) * (c[1] - a[1]) -
                   (b[1] - a[1]) * (c[0] - a[0]));
    }

    double boundarySignedArea(const std::vector<Point> &points,
                              std::size_t boundaryVertexCount)
    {
      if(boundaryVertexCount > points.size() || boundaryVertexCount < 3)
        return 0.;
      // Translate before taking products: a small cavity can have large CAD
      // parameter offsets even when its local coordinates are well resolved.
      const Point &origin = points.front();
      long double twiceArea = 0.;
      for(std::size_t i = 0; i < boundaryVertexCount; ++i) {
        const Point &a = points[i];
        const Point &b = points[(i + 1) % boundaryVertexCount];
        twiceArea +=
          (static_cast<long double>(a[0]) - origin[0]) *
            (static_cast<long double>(b[1]) - origin[1]) -
          (static_cast<long double>(a[1]) - origin[1]) *
            (static_cast<long double>(b[0]) - origin[0]);
      }
      return static_cast<double>(.5L * twiceArea);
    }

    struct PatchCoordinates {
      Point origin;
      double scale;
      std::vector<Point> points;

      Point physical(const Point &point) const
      {
        return {std::fma(scale, point[0], origin[0]),
                std::fma(scale, point[1], origin[1])};
      }
    };

    PatchCoordinates normalizedPatch(
      const std::vector<Point> &points,
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const std::vector<std::array<std::size_t, 4> > &quadrangles)
    {
      if(points.empty() || (triangles.empty() && quadrangles.empty()))
        throw std::invalid_argument("Winslow patch has no points or elements");
      Point minimum = points.front(), maximum = points.front();
      for(const Point &p : points)
        for(std::size_t k = 0; k < 2; ++k) {
          if(!std::isfinite(p[k]))
            throw std::invalid_argument("Winslow patch has non-finite coordinates");
          minimum[k] = std::min(minimum[k], p[k]);
          maximum[k] = std::max(maximum[k], p[k]);
        }
      PatchCoordinates result;
      for(std::size_t k = 0; k < 2; ++k)
        result.origin[k] = .5 * minimum[k] + .5 * maximum[k];
      const long double extent = std::max(
        static_cast<long double>(maximum[0]) - minimum[0],
        static_cast<long double>(maximum[1]) - minimum[1]);
      if(!(extent > 0.) || !std::isfinite(extent))
        throw std::invalid_argument("Winslow patch has zero or invalid extent");

      // Internal edges cancel in this oriented area sum. On a fixed-boundary
      // patch it is independent of the movable vertices, including inverted
      // initial cells. One unit square and one half-unit equilateral triangle
      // retain the same target areas as the former square/right-triangle
      // references. All coordinates share one scale: no UV anisotropy is
      // introduced by the normalization.
      long double area = 0.;
      auto triangleArea = [&](std::size_t a, std::size_t b, std::size_t c) {
        if(a >= points.size() || b >= points.size() || c >= points.size())
          throw std::invalid_argument("Winslow element references an invalid vertex");
        const long double ux = static_cast<long double>(points[b][0]) - points[a][0];
        const long double uy = static_cast<long double>(points[b][1]) - points[a][1];
        const long double vx = static_cast<long double>(points[c][0]) - points[a][0];
        const long double vy = static_cast<long double>(points[c][1]) - points[a][1];
        return .5L * (ux * vy - uy * vx);
      };
      for(const auto &triangle : triangles)
        area += triangleArea(triangle[0], triangle[1], triangle[2]);
      for(const auto &quad : quadrangles) {
        area += triangleArea(quad[0], quad[1], quad[2]);
        area += triangleArea(quad[0], quad[2], quad[3]);
      }
      const long double targetArea =
        quadrangles.size() + .5L * triangles.size();
      long double scale = std::sqrt(std::abs(area) / targetArea);
      // A completely collapsed/folded start still needs a finite chart for
      // untangling. The isotropic extent supplies it when signed area cancels.
      if(!(scale > 1.e-12L * extent)) scale = extent;
      result.scale = static_cast<double>(scale);
      if(!(result.scale > 0.) || !std::isfinite(result.scale))
        throw std::invalid_argument("Winslow patch has an invalid coordinate scale");
      result.points.reserve(points.size());
      for(const Point &p : points)
        result.points.push_back({
          static_cast<double>((static_cast<long double>(p[0]) - result.origin[0]) / scale),
          static_cast<double>((static_cast<long double>(p[1]) - result.origin[1]) / scale)});
      return result;
    }

    Point point(const WinslowData &data, const std::vector<double> &x,
                std::size_t vertex)
    {
      if(vertex < data.boundaryVertexCount) return data.points[vertex];
      const std::size_t offset = 2 * (vertex - data.boundaryVertexCount);
      return {x[offset], x[offset + 1]};
    }

    double chi(double determinant, double epsilon)
    {
      const double root = std::hypot(epsilon, determinant);
      // Rationalize the negative branch to avoid cancellation during
      // untangling (the smoothed positive determinant must remain positive).
      return determinant >= 0. ? .5 * (determinant + root) :
        .5 * epsilon * (epsilon / (root - determinant));
    }

    double chip(double determinant, double epsilon)
    {
      return chi(determinant, epsilon) / std::hypot(epsilon, determinant);
    }

    double energyAndGradient(WinslowData &data,
                             const std::vector<double> &x,
                             std::vector<double> &gradient)
    {
      std::fill(gradient.begin(), gradient.end(), 0.);
      data.minimumJacobian = std::numeric_limits<double>::max();
      double energy = 0.;

      for(const TriangleContribution &triangle : data.triangles) {
        Point p[3];
        for(std::size_t k = 0; k < 3; ++k)
          p[k] = point(data, x, triangle.vertices[k]);

        double J00 = 0., J10 = 0., J01 = 0., J11 = 0.;
        for(std::size_t k = 1; k < 3; ++k) {
          J00 += (p[k][0] - p[0][0]) * triangle.shapeGradients[k][0];
          J10 += (p[k][0] - p[0][0]) * triangle.shapeGradients[k][1];
          J01 += (p[k][1] - p[0][1]) * triangle.shapeGradients[k][0];
          J11 += (p[k][1] - p[0][1]) * triangle.shapeGradients[k][1];
        }

        const double determinant = J00 * J11 - J01 * J10;
        data.minimumJacobian =
          std::min(data.minimumJacobian, determinant);
        const double c = chi(determinant, data.epsilon);
        const double cp = chip(determinant, data.epsilon);
        if(!(c > 0.) || !std::isfinite(c))
          return std::numeric_limits<double>::max();

        const double trace =
          J00 * J00 + J10 * J10 + J01 * J01 + J11 * J11;
        const double f = trace / c;
        const double g = (determinant * determinant + 1.) / c;
        energy += f + data.lambda * g;

        const double coefficient =
          f * cp - 2. * data.lambda * determinant + data.lambda * g * cp;
        const double scaleA = 2. / c;
        const double scaleB = coefficient / c;
        const double d00 = scaleA * J00 - scaleB * J11;
        const double d10 = scaleA * J10 + scaleB * J01;
        const double d01 = scaleA * J01 + scaleB * J10;
        const double d11 = scaleA * J11 - scaleB * J00;

        for(std::size_t k = 0; k < 3; ++k) {
          const std::size_t vertex = triangle.vertices[k];
          if(vertex < data.boundaryVertexCount) continue;
          const std::size_t offset =
            2 * (vertex - data.boundaryVertexCount);
          const double n0 = triangle.shapeGradients[k][0];
          const double n1 = triangle.shapeGradients[k][1];
          gradient[offset] += d00 * n0 + d10 * n1;
          gradient[offset + 1] += d01 * n0 + d11 * n1;
        }
      }

      data.energy = std::isfinite(energy) ?
                      energy : std::numeric_limits<double>::max();
      return data.energy;
    }

    std::array<Point, 3> shapeGradients(const std::array<Point, 3> &shape)
    {
      const double area = signedArea(shape[0], shape[1], shape[2]);
      if(!(area > 0.))
        throw std::invalid_argument(
          "Small-cavity Winslow target triangle has non-positive area");
      std::array<Point, 3> result;
      for(std::size_t k = 0; k < 3; ++k) {
        const Point delta = {
          shape[(k + 2) % 3][0] - shape[(k + 1) % 3][0],
          shape[(k + 2) % 3][1] - shape[(k + 1) % 3][1]};
        result[k] = {-delta[1] / (2. * area),
                     delta[0] / (2. * area)};
      }
      return result;
    }

    void harmonicInitialize(
      std::vector<Point> &points, std::size_t boundaryVertexCount,
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const std::vector<std::array<std::size_t, 4> > &quadrangles)
    {
      const std::size_t vertexCount = points.size();
      std::vector<std::set<std::size_t> > neighbors(vertexCount);
      for(const auto &triangle : triangles) {
        for(std::size_t k = 0; k < 3; ++k) {
          const std::size_t a = triangle[k], b = triangle[(k + 1) % 3];
          if(a >= vertexCount || b >= vertexCount)
            throw std::invalid_argument(
              "Small-cavity triangle references an invalid vertex");
          neighbors[a].insert(b);
          neighbors[b].insert(a);
        }
      }
      for(const auto &quad : quadrangles) {
        for(std::size_t k = 0; k < 4; ++k) {
          const std::size_t a = quad[k], b = quad[(k + 1) % 4];
          if(a >= vertexCount || b >= vertexCount)
            throw std::invalid_argument(
              "Small-cavity quadrangle references an invalid vertex");
          neighbors[a].insert(b);
          neighbors[b].insert(a);
        }
      }

      const std::size_t interiorCount =
        vertexCount - boundaryVertexCount;
      if(interiorCount == 0) return;

      // Solve the uniform graph-Laplacian equations directly. CleanUp uses at
      // most a handful of interior nodes; a tiny dense solve is both exact and
      // substantially cheaper than thousands of Gauss-Seidel sweeps.
      std::vector<std::vector<double> > system(
        interiorCount, std::vector<double>(interiorCount + 2, 0.));
      for(std::size_t local = 0; local < interiorCount; ++local) {
        const std::size_t vertex = boundaryVertexCount + local;
        if(neighbors[vertex].empty())
          throw std::invalid_argument(
            "Small-cavity interior vertex has no neighbor");
        system[local][local] =
          static_cast<double>(neighbors[vertex].size());
        for(const std::size_t neighbor : neighbors[vertex]) {
          if(neighbor >= boundaryVertexCount) {
            system[local][neighbor - boundaryVertexCount] -= 1.;
          }
          else {
            system[local][interiorCount] += points[neighbor][0];
            system[local][interiorCount + 1] += points[neighbor][1];
          }
        }
      }

      for(std::size_t column = 0; column < interiorCount; ++column) {
        std::size_t pivot = column;
        for(std::size_t row = column + 1; row < interiorCount; ++row)
          if(std::abs(system[row][column]) >
             std::abs(system[pivot][column]))
            pivot = row;
        if(std::abs(system[pivot][column]) <=
           std::numeric_limits<double>::epsilon())
          throw std::invalid_argument(
            "Small-cavity harmonic system is singular");
        if(pivot != column) std::swap(system[pivot], system[column]);
        const double inverse = 1. / system[column][column];
        for(std::size_t j = column; j < interiorCount + 2; ++j)
          system[column][j] *= inverse;
        for(std::size_t row = 0; row < interiorCount; ++row) {
          if(row == column) continue;
          const double factor = system[row][column];
          if(factor == 0.) continue;
          for(std::size_t j = column; j < interiorCount + 2; ++j)
            system[row][j] -= factor * system[column][j];
        }
      }
      for(std::size_t local = 0; local < interiorCount; ++local)
        points[boundaryVertexCount + local] = {
          system[local][interiorCount],
          system[local][interiorCount + 1]};
    }

    WinslowData prepareData(
      const std::vector<Point> &points, std::size_t boundaryVertexCount,
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const std::vector<std::array<std::size_t, 4> > &quadrangles,
      double lambda, double orientation)
    {
      if(boundaryVertexCount < 3 || boundaryVertexCount >= points.size())
        throw std::invalid_argument(
          "Small-cavity Winslow requires a boundary and interior vertices");
      if(triangles.empty() && quadrangles.empty())
        throw std::invalid_argument(
          "Small-cavity Winslow requires at least one surface element");
      if(!std::isfinite(lambda) || lambda < 0.)
        throw std::invalid_argument("Invalid Winslow lambda");

      if(!std::isfinite(orientation) ||
         std::abs(orientation) <= std::numeric_limits<double>::epsilon())
        throw std::invalid_argument(
          "Small-cavity Winslow orientation is zero");

      WinslowData data;
      data.points = points;
      data.boundaryVertexCount = boundaryVertexCount;
      data.lambda = lambda;
      const std::array<Point, 4> target = {
        Point{0., 0.}, Point{1., 0.}, Point{1., 1.}, Point{0., 1.}};
      data.triangles.reserve(triangles.size() + 4 * quadrangles.size());
      const double triangleSide = std::sqrt(2. / std::sqrt(3.));
      const std::array<Point, 3> targetTriangle = {
        Point{0., 0.}, Point{triangleSide, 0.},
        Point{.5 * triangleSide, .5 * std::sqrt(3.) * triangleSide}};
      for(const auto &source : triangles) {
        TriangleContribution triangle;
        for(std::size_t k = 0; k < 3; ++k) {
          if(source[k] >= points.size())
            throw std::invalid_argument(
              "Small-cavity triangle references an invalid vertex");
          triangle.vertices[k] = source[k];
        }
        triangle.shapeGradients = shapeGradients(targetTriangle);
        if(orientation < 0.)
          for(Point &gradient : triangle.shapeGradients) gradient[0] = -gradient[0];
        data.triangles.push_back(triangle);
      }
      for(const auto &quad : quadrangles) {
        for(const std::size_t vertex : quad) {
          if(vertex >= points.size())
            throw std::invalid_argument(
              "Small-cavity quadrangle references an invalid vertex");
        }
        for(const auto &corner : quadCornerTriangles) {
          TriangleContribution triangle;
          std::array<Point, 3> ideal;
          for(std::size_t k = 0; k < 3; ++k) {
            const std::size_t local = corner[k];
            triangle.vertices[k] = quad[local];
            ideal[k] = target[local];
          }
          triangle.shapeGradients = shapeGradients(ideal);
          // Reflect the reference chart, not the vertex correspondence.
          // Swapping vertices moves the right-angle corner of a quad's
          // reference triangle and changes its intended square metric.
          if(orientation < 0.)
            for(Point &gradient : triangle.shapeGradients) gradient[0] = -gradient[0];
          data.triangles.push_back(triangle);
        }
      }
      return data;
    }

    SmallCavityWinslowResult optimizeContiguousPatch(
      std::vector<Point> &parametricPoints,
      std::size_t boundaryVertexCount,
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const std::vector<std::array<std::size_t, 4> > &quadrangles,
      double orientation,
      const SmallCavityWinslowOptions &options)
    {
      if(options.maxInnerIterations <= 0 || options.maxOuterIterations <= 0 ||
         options.maxLineSearchSteps <= 0)
        throw std::invalid_argument(
          "Small-cavity Winslow iteration limits must be positive");
      for(const double tolerance : {options.gradientTolerance,
                                     options.functionTolerance,
                                     options.stepTolerance})
        if(!std::isfinite(tolerance) || tolerance < 0.)
          throw std::invalid_argument("Invalid Winslow convergence tolerance");
      if(boundaryVertexCount < 3 || boundaryVertexCount >= parametricPoints.size())
        throw std::invalid_argument("Winslow patch needs fixed and movable vertices");

      const PatchCoordinates coordinates = normalizedPatch(
        parametricPoints, triangles, quadrangles);
      std::vector<Point> candidate = coordinates.points;
      if(options.harmonicInitialization)
        harmonicInitialize(candidate, boundaryVertexCount, triangles,
                           quadrangles);
      WinslowData data = prepareData(candidate, boundaryVertexCount,
                                     triangles, quadrangles,
                                     options.lambda, orientation);

      const std::size_t interiorVertexCount =
        candidate.size() - boundaryVertexCount;
      std::vector<double> x(2 * interiorVertexCount);
      for(std::size_t i = 0; i < interiorVertexCount; ++i) {
        x[2 * i] = candidate[boundaryVertexCount + i][0];
        x[2 * i + 1] = candidate[boundaryVertexCount + i][1];
      }
      std::vector<double> gradient(x.size(), 0.);

      data.minimumJacobian = 0.;
      data.epsilon = 1.e-6;
      const double initialEnergy = energyAndGradient(data, x, gradient);
      const double initialMinimumJacobian = data.minimumJacobian;

      SmallCavityWinslowResult output;
      output.initialEnergy = initialEnergy;
      double previousEnergy = initialEnergy;
      for(int outer = 0; outer < options.maxOuterIterations; ++outer) {
        data.epsilon = std::hypot(1.e-6,
                                  .2 * std::min(data.minimumJacobian, 0.));

        GmshLBFGS::Options lbfgs;
        lbfgs.maxIterations = options.maxInnerIterations;
        lbfgs.memory = static_cast<int>(std::min<std::size_t>(15, x.size()));
        lbfgs.gradientTolerance = options.gradientTolerance;
        lbfgs.functionTolerance = options.functionTolerance;
        lbfgs.stepTolerance = options.stepTolerance;
        lbfgs.maxLineSearchSteps = options.maxLineSearchSteps;
        lbfgs.verbose = options.verbose;
        auto fg = [&data](const std::vector<double> &coordinates,
                          std::vector<double> &g) {
          return energyAndGradient(data, coordinates, g);
        };
        const GmshLBFGS::Result result = GmshLBFGS::minimize(x, fg, lbfgs);
        output.lbfgsIterations += result.iterations;
        output.functionEvaluations += result.functionEvaluations;
        output.outerIterations = outer + 1;

        energyAndGradient(data, x, gradient);
        const double relativeChange =
          std::abs(data.energy - previousEnergy) /
          std::max(1., std::abs(data.energy));
        previousEnergy = data.energy;
        if(data.minimumJacobian > 0. && relativeChange < 1.e-5) break;
      }

      output.finalEnergy = data.energy;
      output.minimumJacobian = data.minimumJacobian;
      output.untangled = data.minimumJacobian > 0.;
      output.success = output.untangled && std::isfinite(data.energy);
      if(output.success) {
        for(std::size_t i = 0; i < interiorVertexCount; ++i)
          candidate[boundaryVertexCount + i] = {x[2 * i], x[2 * i + 1]};
      }
      else if(initialMinimumJacobian > 0. && std::isfinite(initialEnergy)) {
        output.success = true;
        output.untangled = true;
        output.finalEnergy = initialEnergy;
        output.minimumJacobian = initialMinimumJacobian;
      }
      if(output.success) {
        std::vector<Point> mapped;
        mapped.reserve(interiorVertexCount);
        for(std::size_t i = boundaryVertexCount; i < candidate.size(); ++i) {
          const Point p = coordinates.physical(candidate[i]);
          if(!std::isfinite(p[0]) || !std::isfinite(p[1])) {
            output.success = false;
            return output;
          }
          mapped.push_back(p);
        }
        // Fixed vertices never make a floating-point round trip.
        std::copy(mapped.begin(), mapped.end(),
                  parametricPoints.begin() + boundaryVertexCount);
      }
      return output;
    }

  } // namespace

  bool initializeSmallQuadCavityHarmonic(
    std::vector<std::array<double, 2> > &parametricPoints,
    std::size_t boundaryVertexCount,
    const std::vector<std::array<std::size_t, 4> > &quadrangles)
  {
    if(boundaryVertexCount < 4 ||
       boundaryVertexCount > parametricPoints.size() ||
       quadrangles.empty())
      return false;
    PatchCoordinates coordinates;
    try {
      coordinates = normalizedPatch(parametricPoints, {}, quadrangles);
      harmonicInitialize(coordinates.points, boundaryVertexCount, {}, quadrangles);
    }
    catch(const std::invalid_argument &) { return false; }

    const double orientation =
      boundarySignedArea(coordinates.points, boundaryVertexCount);
    if(!std::isfinite(orientation) || std::abs(orientation) <=
         std::numeric_limits<double>::epsilon())
      return false;
    const double sign = orientation > 0. ? 1. : -1.;
    for(const auto &quad : quadrangles) {
      for(const std::size_t vertex : quad)
        if(vertex >= parametricPoints.size()) return false;
      for(const auto &corner : quadCornerTriangles) {
        const double area = signedArea(
          coordinates.points[quad[corner[0]]],
          coordinates.points[quad[corner[1]]],
          coordinates.points[quad[corner[2]]]);
        if(!std::isfinite(area) || sign * area <= 1.e-14) return false;
      }
    }
    for(std::size_t i = boundaryVertexCount; i < parametricPoints.size(); ++i)
      parametricPoints[i] = coordinates.physical(coordinates.points[i]);
    return true;
  }

  SmallCavityWinslowResult optimizeSmallQuadCavityWinslow(
    std::vector<std::array<double, 2> > &parametricPoints,
    std::size_t boundaryVertexCount,
    const std::vector<std::array<std::size_t, 4> > &quadrangles,
    const SmallCavityWinslowOptions &options)
  {
    const double orientation =
      boundarySignedArea(parametricPoints, boundaryVertexCount);
    return optimizeContiguousPatch(parametricPoints, boundaryVertexCount, {},
                                   quadrangles,
                                   orientation > 0. ? 1. : orientation < 0. ? -1. : 0.,
                                   options);
  }

  double evaluateLocalSurfacePatchWinslowEnergy(
    const std::vector<std::array<double, 2> > &points,
    const std::vector<std::array<std::size_t, 3> > &triangles,
    const std::vector<std::array<std::size_t, 4> > &quadrangles,
    double orientationSign, double lambda)
  {
    const auto coordinates = normalizedPatch(points, triangles, quadrangles);
    auto data = prepareData(coordinates.points, points.size() - 1,
                            triangles, quadrangles, lambda, orientationSign);
    const auto &last = coordinates.points.back();
    std::vector<double> x{last[0], last[1]}, gradient(2);
    return energyAndGradient(data, x, gradient);
  }

  SmallCavityWinslowResult optimizeLocalSurfacePatchWinslow(
    std::vector<std::array<double, 2> > &parametricPoints,
    const std::vector<bool> &fixed,
    const std::vector<std::array<std::size_t, 3> > &triangles,
    const std::vector<std::array<std::size_t, 4> > &quadrangles,
    double orientationSign, const SmallCavityWinslowOptions &options)
  {
    if(fixed.size() != parametricPoints.size())
      throw std::invalid_argument("Winslow fixed mask has invalid size");
    const std::size_t fixedCount = static_cast<std::size_t>(
      std::count(fixed.begin(), fixed.end(), true));
    if(fixedCount < 3 || fixedCount >= parametricPoints.size())
      throw std::invalid_argument(
        "Local Winslow patch needs fixed and movable vertices");

    std::vector<std::size_t> oldToNew(parametricPoints.size());
    std::vector<std::size_t> newToOld;
    newToOld.reserve(parametricPoints.size());
    for(int pass = 0; pass < 2; ++pass)
      for(std::size_t old = 0; old < fixed.size(); ++old)
        if(fixed[old] == (pass == 0)) {
          oldToNew[old] = newToOld.size();
          newToOld.push_back(old);
        }
    std::vector<Point> reordered(parametricPoints.size());
    for(std::size_t i = 0; i < reordered.size(); ++i)
      reordered[i] = parametricPoints[newToOld[i]];
    auto remapTriangles = triangles;
    for(auto &triangle : remapTriangles)
      for(std::size_t &vertex : triangle) {
        if(vertex >= oldToNew.size())
          throw std::invalid_argument(
            "Local Winslow triangle references an invalid vertex");
        vertex = oldToNew[vertex];
      }
    auto remapQuadrangles = quadrangles;
    for(auto &quadrangle : remapQuadrangles)
      for(std::size_t &vertex : quadrangle) {
        if(vertex >= oldToNew.size())
          throw std::invalid_argument(
            "Local Winslow quadrangle references an invalid vertex");
        vertex = oldToNew[vertex];
      }
    const SmallCavityWinslowResult result = optimizeContiguousPatch(
      reordered, fixedCount, remapTriangles, remapQuadrangles,
      orientationSign, options);
    if(result.success)
      for(std::size_t i = fixedCount; i < reordered.size(); ++i)
        parametricPoints[newToOld[i]] = reordered[i];
    return result;
  }

} // namespace QuadOptimizer
