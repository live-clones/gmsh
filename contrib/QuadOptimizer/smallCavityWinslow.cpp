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
      double twiceArea = 0.;
      for(std::size_t i = 0; i < boundaryVertexCount; ++i) {
        const Point &a = points[i];
        const Point &b = points[(i + 1) % boundaryVertexCount];
        twiceArea += a[0] * b[1] - a[1] * b[0];
      }
      return .5 * twiceArea;
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
      return .5 *
             (determinant +
              std::sqrt(epsilon * epsilon + determinant * determinant));
    }

    double chip(double determinant, double epsilon)
    {
      return .5 + determinant /
                      (2. * std::sqrt(epsilon * epsilon +
                                      determinant * determinant));
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
        for(std::size_t k = 0; k < 3; ++k) {
          J00 += p[k][0] * triangle.shapeGradients[k][0];
          J10 += p[k][0] * triangle.shapeGradients[k][1];
          J01 += p[k][1] * triangle.shapeGradients[k][0];
          J11 += p[k][1] * triangle.shapeGradients[k][1];
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
      const std::vector<std::array<std::size_t, 4> > &quadrangles)
    {
      const std::size_t vertexCount = points.size();
      std::vector<std::set<std::size_t> > neighbors(vertexCount);
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

      Point centroid = {0., 0.};
      for(std::size_t i = 0; i < boundaryVertexCount; ++i) {
        centroid[0] += points[i][0];
        centroid[1] += points[i][1];
      }
      centroid[0] /= static_cast<double>(boundaryVertexCount);
      centroid[1] /= static_cast<double>(boundaryVertexCount);
      for(std::size_t i = boundaryVertexCount; i < vertexCount; ++i)
        points[i] = centroid;

      for(int iteration = 0; iteration < 10000; ++iteration) {
        double maximumChange = 0.;
        for(std::size_t i = boundaryVertexCount; i < vertexCount; ++i) {
          if(neighbors[i].empty()) continue;
          Point average = {0., 0.};
          for(const std::size_t neighbor : neighbors[i]) {
            average[0] += points[neighbor][0];
            average[1] += points[neighbor][1];
          }
          const double inverse = 1. / static_cast<double>(neighbors[i].size());
          average[0] *= inverse;
          average[1] *= inverse;
          maximumChange =
            std::max(maximumChange,
                     std::hypot(average[0] - points[i][0],
                                average[1] - points[i][1]));
          points[i] = average;
        }
        if(maximumChange < 1.e-13) break;
      }
    }

    WinslowData prepareData(
      const std::vector<Point> &points, std::size_t boundaryVertexCount,
      const std::vector<std::array<std::size_t, 4> > &quadrangles,
      double lambda)
    {
      if(boundaryVertexCount < 4 || boundaryVertexCount >= points.size())
        throw std::invalid_argument(
          "Small-cavity Winslow requires a boundary and interior vertices");
      if(quadrangles.empty())
        throw std::invalid_argument(
          "Small-cavity Winslow requires at least one quadrangle");
      if(!std::isfinite(lambda) || lambda < 0.)
        throw std::invalid_argument("Invalid Winslow lambda");

      const double orientation =
        boundarySignedArea(points, boundaryVertexCount);
      if(std::abs(orientation) <= std::numeric_limits<double>::epsilon())
        throw std::invalid_argument(
          "Small-cavity Winslow boundary has zero signed area");

      WinslowData data;
      data.points = points;
      data.boundaryVertexCount = boundaryVertexCount;
      data.lambda = lambda;
      const std::array<Point, 4> target = {
        Point{0., 0.}, Point{1., 0.}, Point{1., 1.}, Point{0., 1.}};
      data.triangles.reserve(4 * quadrangles.size());
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
          if(orientation < 0.) {
            std::swap(triangle.vertices[1], triangle.vertices[2]);
          }
          triangle.shapeGradients = shapeGradients(ideal);
          data.triangles.push_back(triangle);
        }
      }
      return data;
    }

  } // namespace

  SmallCavityWinslowResult optimizeSmallQuadCavityWinslow(
    std::vector<std::array<double, 2> > &parametricPoints,
    std::size_t boundaryVertexCount,
    const std::vector<std::array<std::size_t, 4> > &quadrangles,
    const SmallCavityWinslowOptions &options)
  {
    if(options.maxInnerIterations <= 0 || options.maxOuterIterations <= 0 ||
       options.maxLineSearchSteps <= 0)
      throw std::invalid_argument(
        "Small-cavity Winslow iteration limits must be positive");

    std::vector<Point> candidate = parametricPoints;
    if(options.harmonicInitialization)
      harmonicInitialize(candidate, boundaryVertexCount, quadrangles);
    WinslowData data =
      prepareData(candidate, boundaryVertexCount, quadrangles, options.lambda);

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
      data.epsilon = std::sqrt(
        1.e-12 + .04 * std::pow(std::min(data.minimumJacobian, 0.), 2));

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
      for(std::size_t i = 0; i < interiorVertexCount; ++i) {
        parametricPoints[boundaryVertexCount + i] =
          {x[2 * i], x[2 * i + 1]};
      }
    }
    else if(initialMinimumJacobian > 0. && std::isfinite(initialEnergy)) {
      // A failed line search must never destroy an already valid cavity.
      output.success = true;
      output.untangled = true;
      output.finalEnergy = initialEnergy;
      output.minimumJacobian = initialMinimumJacobian;
      parametricPoints = candidate;
    }
    return output;
  }

} // namespace QuadOptimizer
