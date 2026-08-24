// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "quadQuality.h"

#include "MElement.h"
#include "GFace.h"
#include "GModel.h"
#include "MQuadrangle.h"
#include "MTriangle.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <limits>

namespace QuadOptimizer {
  namespace {

    using Point = std::array<double, 3>;
    constexpr double pi = 3.141592653589793238462643383279502884;

    Point subtract(const Point &a, const Point &b)
    {
      return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
    }

    Point cross(const Point &a, const Point &b)
    {
      return {a[1] * b[2] - a[2] * b[1],
              a[2] * b[0] - a[0] * b[2],
              a[0] * b[1] - a[1] * b[0]};
    }

    double dot(const Point &a, const Point &b)
    {
      return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    }

    double norm(const Point &a) { return std::sqrt(dot(a, a)); }

    double angleDegrees(const Point &a, const Point &b)
    {
      const double denominator = norm(a) * norm(b);
      if(!(denominator > 0.))
        return std::numeric_limits<double>::infinity();
      const double cosine =
        std::clamp(dot(a, b) / denominator, -1., 1.);
      return std::acos(cosine) * 180. / pi;
    }

    double normalAngle(const Point &a, const Point &b, const Point &c,
                       const Point &d)
    {
      return angleDegrees(cross(subtract(b, a), subtract(c, a)),
                          cross(subtract(c, a), subtract(d, a)));
    }

    Point polygonNormal(const std::vector<Point> &vertices)
    {
      Point normal = {0., 0., 0.};
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        const Point contribution =
          cross(vertices[i], vertices[(i + 1) % vertices.size()]);
        for(std::size_t d = 0; d < 3; ++d) normal[d] += contribution[d];
      }
      return normal;
    }

    using Point2 = std::array<double, 2>;

    Point2 project(const Point &point, std::size_t droppedCoordinate)
    {
      if(droppedCoordinate == 0) return {point[1], point[2]};
      if(droppedCoordinate == 1) return {point[0], point[2]};
      return {point[0], point[1]};
    }

    double orient2d(const Point2 &a, const Point2 &b, const Point2 &c)
    {
      return (b[0] - a[0]) * (c[1] - a[1]) -
             (b[1] - a[1]) * (c[0] - a[0]);
    }

    bool properIntersection(const Point2 &a, const Point2 &b,
                            const Point2 &c, const Point2 &d,
                            double tolerance)
    {
      const double abc = orient2d(a, b, c);
      const double abd = orient2d(a, b, d);
      const double cda = orient2d(c, d, a);
      const double cdb = orient2d(c, d, b);
      return ((abc > tolerance && abd < -tolerance) ||
              (abc < -tolerance && abd > tolerance)) &&
             ((cda > tolerance && cdb < -tolerance) ||
              (cda < -tolerance && cdb > tolerance));
    }

    bool bowtie(const std::vector<Point> &vertices, const Point &normal)
    {
      if(vertices.size() != 4) return false;
      const std::size_t dropped = static_cast<std::size_t>(
        std::max_element(normal.begin(), normal.end(),
                         [](double a, double b) {
                           return std::abs(a) < std::abs(b);
                         }) - normal.begin());
      std::array<Point2, 4> points;
      double minimum[2] = {std::numeric_limits<double>::infinity(),
                           std::numeric_limits<double>::infinity()};
      double maximum[2] = {-std::numeric_limits<double>::infinity(),
                           -std::numeric_limits<double>::infinity()};
      for(std::size_t i = 0; i < 4; ++i) {
        points[i] = project(vertices[i], dropped);
        for(std::size_t d = 0; d < 2; ++d) {
          minimum[d] = std::min(minimum[d], points[i][d]);
          maximum[d] = std::max(maximum[d], points[i][d]);
        }
      }
      const double scale2 = std::pow(maximum[0] - minimum[0], 2) +
                            std::pow(maximum[1] - minimum[1], 2);
      const double tolerance =
        1.e-12 * std::max(scale2, std::numeric_limits<double>::min());
      return properIntersection(points[0], points[1], points[2], points[3],
                                tolerance) ||
             properIntersection(points[1], points[2], points[3], points[0],
                                tolerance);
    }

    double upperViolation(double value, double limit)
    {
      if(!std::isfinite(value)) return 1.e15;
      return std::max(0., value / limit - 1.);
    }

    double lowerViolation(double value, double limit)
    {
      if(!std::isfinite(value)) return 1.e15;
      return std::max(0., 1. - value / limit);
    }

    double upperPenalty(double value, double limit)
    {
      if(!std::isfinite(value)) return 1.e30;
      const double excess = std::max(0., value / limit - 1.);
      return excess * excess;
    }

    double lowerPenalty(double value, double limit)
    {
      if(!std::isfinite(value)) return 1.e30;
      const double deficit = std::max(0., 1. - value / limit);
      return deficit * deficit;
    }

    void addUpper(SpecificationObjective &objective, double value,
                  double preferred, double absolute)
    {
      if(!(value < absolute)) ++objective.absoluteViolationCount;
      if(!(value < preferred)) ++objective.preferredViolationCount;
      objective.worstAbsoluteViolation = std::max(
        objective.worstAbsoluteViolation, upperViolation(value, absolute));
      objective.worstPreferredViolation = std::max(
        objective.worstPreferredViolation, upperViolation(value, preferred));
      objective.absolutePenalty += upperPenalty(value, absolute);
      objective.preferredPenalty += upperPenalty(value, preferred);
    }

    void addLower(SpecificationObjective &objective, double value,
                  double preferred, double absolute)
    {
      if(!(value > absolute)) ++objective.absoluteViolationCount;
      if(!(value > preferred)) ++objective.preferredViolationCount;
      objective.worstAbsoluteViolation = std::max(
        objective.worstAbsoluteViolation, lowerViolation(value, absolute));
      objective.worstPreferredViolation = std::max(
        objective.worstPreferredViolation, lowerViolation(value, preferred));
      objective.absolutePenalty += lowerPenalty(value, absolute);
      objective.preferredPenalty += lowerPenalty(value, preferred);
    }

    bool less(double candidate, double reference, double tolerance)
    {
      return candidate < reference - tolerance *
        std::max({1., std::abs(candidate), std::abs(reference)});
    }

    std::vector<Point> elementPoints(const MElement *element)
    {
      std::vector<Point> points;
      if(!element) return points;
      const std::size_t count = element->getNumPrimaryVertices();
      points.reserve(count);
      for(std::size_t i = 0; i < count; ++i) {
        const MVertex *vertex = element->getVertex(static_cast<int>(i));
        points.push_back({vertex->x(), vertex->y(), vertex->z()});
      }
      return points;
    }

    enum class Criterion {
      Warping,
      EdgeRatio,
      MinimumQuadAngle,
      MaximumQuadAngle,
      MinimumTriangleAngle,
      MaximumTriangleAngle,
      Skewing
    };

    double value(const ElementQuality &quality, Criterion criterion)
    {
      switch(criterion) {
      case Criterion::Warping: return quality.warpingDegrees;
      case Criterion::EdgeRatio: return quality.edgeRatio;
      case Criterion::MinimumQuadAngle:
      case Criterion::MinimumTriangleAngle:
        return quality.minimumAngleDegrees;
      case Criterion::MaximumQuadAngle:
      case Criterion::MaximumTriangleAngle:
        return quality.maximumAngleDegrees;
      case Criterion::Skewing: return quality.skewingDegrees;
      }
      return 0.;
    }

    void writeElement(std::ostream &out, const MElement *element,
                      double scalar)
    {
      const std::size_t count = element->getNumPrimaryVertices();
      out << (count == 3 ? "ST(" : "SQ(");
      for(std::size_t i = 0; i < count; ++i) {
        if(i) out << ',';
        const MVertex *vertex = element->getVertex(static_cast<int>(i));
        out << vertex->x() << ',' << vertex->y() << ',' << vertex->z();
      }
      out << "){";
      for(std::size_t i = 0; i < count; ++i) {
        if(i) out << ',';
        out << scalar;
      }
      out << "};\n";
    }

  } // namespace

  ElementQuality evaluateElementQuality(
    SurfaceElementKind kind, const std::vector<Point> &vertices)
  {
    const std::size_t count =
      kind == SurfaceElementKind::Triangle ? 3 : 4;
    ElementQuality quality;
    quality.kind = kind;
    if(vertices.size() != count) {
      quality.topologicallyValid = false;
      quality.warpingDegrees = quality.edgeRatio =
        quality.minimumAngleDegrees = quality.maximumAngleDegrees =
          quality.skewingDegrees =
            std::numeric_limits<double>::infinity();
      return quality;
    }

    Point normal = {0., 0., 0.};
    if(kind == SurfaceElementKind::Quadrangle) {
      normal = polygonNormal(vertices);
      double scale = 0.;
      for(std::size_t i = 0; i < count; ++i)
        scale = std::max(
          scale, norm(subtract(vertices[(i + 1) % count], vertices[i])));
      quality.topologicallyValid =
        norm(normal) > 1.e-12 * std::max(scale * scale,
                                        std::numeric_limits<double>::min()) &&
        !bowtie(vertices, normal);
      quality.warpingDegrees =
        std::max(normalAngle(vertices[0], vertices[1], vertices[2], vertices[3]),
                 normalAngle(vertices[1], vertices[2], vertices[3], vertices[0]));
    }

    double minimumEdge = std::numeric_limits<double>::infinity();
    double maximumEdge = 0.;
    std::vector<double> angles(count);
    for(std::size_t i = 0; i < count; ++i) {
      const std::size_t previous = (i + count - 1) % count;
      const std::size_t next = (i + 1) % count;
      minimumEdge = std::min(
        minimumEdge, norm(subtract(vertices[next], vertices[i])));
      maximumEdge = std::max(
        maximumEdge, norm(subtract(vertices[next], vertices[i])));
      const Point previousDirection = subtract(vertices[previous], vertices[i]);
      const Point nextDirection = subtract(vertices[next], vertices[i]);
      angles[i] = angleDegrees(previousDirection, nextDirection);
      if(kind == SurfaceElementKind::Quadrangle &&
         quality.topologicallyValid &&
         dot(cross(nextDirection, previousDirection), normal) < 0.)
        angles[i] = 360. - angles[i];
    }
    quality.edgeRatio = minimumEdge > 0. ?
                          maximumEdge / minimumEdge :
                          std::numeric_limits<double>::infinity();
    quality.minimumAngleDegrees =
      *std::min_element(angles.begin(), angles.end());
    quality.maximumAngleDegrees =
      *std::max_element(angles.begin(), angles.end());
    const double ideal = count == 3 ? 60. : 90.;
    for(const double angle : angles)
      quality.skewingDegrees += std::abs(ideal - angle);

    const bool finite = std::isfinite(quality.warpingDegrees) &&
      std::isfinite(quality.edgeRatio) &&
      std::isfinite(quality.minimumAngleDegrees) &&
      std::isfinite(quality.maximumAngleDegrees) &&
      std::isfinite(quality.skewingDegrees);
    if(kind == SurfaceElementKind::Triangle) {
      quality.passesAbsoluteSpecifications = finite &&
        quality.topologicallyValid &&
        quality.edgeRatio < 10. && quality.minimumAngleDegrees > 10. &&
        quality.maximumAngleDegrees < 150. && quality.skewingDegrees < 160.;
    }
    else {
      quality.passesAbsoluteSpecifications = finite &&
        quality.topologicallyValid &&
        quality.warpingDegrees < 25. && quality.edgeRatio < 10. &&
        quality.minimumAngleDegrees > 25. &&
        quality.maximumAngleDegrees < 160. && quality.skewingDegrees < 160.;
    }
    return quality;
  }

  ElementQuality evaluateElementQuality(const MElement *element)
  {
    if(!element) return ElementQuality();
    const std::size_t count = element->getNumPrimaryVertices();
    if(count != 3 && count != 4) return ElementQuality();
    return evaluateElementQuality(
      count == 3 ? SurfaceElementKind::Triangle :
                   SurfaceElementKind::Quadrangle,
      elementPoints(element));
  }

  SpecificationObjective specificationObjective(const ElementQuality &quality)
  {
    SpecificationObjective objective;
    addUpper(objective, quality.edgeRatio, 5., 10.);
    addUpper(objective, quality.skewingDegrees, 125., 160.);
    const double edgeShape = std::log(std::max(quality.edgeRatio, 1.));
    if(quality.kind == SurfaceElementKind::Triangle) {
      addLower(objective, quality.minimumAngleDegrees, 20., 10.);
      addUpper(objective, quality.maximumAngleDegrees, 120., 150.);
      objective.shapePenalty = edgeShape * edgeShape +
        std::pow((quality.minimumAngleDegrees - 60.) / 60., 2) +
        std::pow((quality.maximumAngleDegrees - 60.) / 60., 2) +
        std::pow(quality.skewingDegrees / 125., 2);
    }
    else {
      addUpper(objective, quality.warpingDegrees, 15., 25.);
      addLower(objective, quality.minimumAngleDegrees, 45., 25.);
      addUpper(objective, quality.maximumAngleDegrees, 135., 160.);
      objective.shapePenalty =
        std::pow(quality.warpingDegrees / 15., 2) + edgeShape * edgeShape +
        std::pow((quality.minimumAngleDegrees - 90.) / 90., 2) +
        std::pow((quality.maximumAngleDegrees - 90.) / 90., 2) +
        std::pow(quality.skewingDegrees / 125., 2);
    }
    objective.absoluteBadElementCount =
      quality.passesAbsoluteSpecifications ? 0 : 1;
    return objective;
  }

  SpecificationObjective specificationObjective(
    const std::vector<MElement *> &elements)
  {
    SpecificationObjective objective;
    for(const MElement *element : elements)
      objective += specificationObjective(evaluateElementQuality(element));
    return objective;
  }

  SpecificationObjective &operator+=(SpecificationObjective &left,
                                      const SpecificationObjective &right)
  {
    left.absoluteBadElementCount += right.absoluteBadElementCount;
    left.absoluteViolationCount += right.absoluteViolationCount;
    left.worstAbsoluteViolation =
      std::max(left.worstAbsoluteViolation, right.worstAbsoluteViolation);
    left.preferredViolationCount += right.preferredViolationCount;
    left.worstPreferredViolation =
      std::max(left.worstPreferredViolation, right.worstPreferredViolation);
    left.absolutePenalty += right.absolutePenalty;
    left.preferredPenalty += right.preferredPenalty;
    left.shapePenalty += right.shapePenalty;
    return left;
  }

  bool improvesSpecificationObjective(const SpecificationObjective &candidate,
                                      const SpecificationObjective &reference,
                                      double tolerance)
  {
    if(candidate.absoluteBadElementCount != reference.absoluteBadElementCount)
      return candidate.absoluteBadElementCount <
             reference.absoluteBadElementCount;
    if(less(candidate.worstAbsoluteViolation,
            reference.worstAbsoluteViolation, tolerance))
      return true;
    if(less(reference.worstAbsoluteViolation,
            candidate.worstAbsoluteViolation, tolerance))
      return false;
    if(candidate.absoluteViolationCount != reference.absoluteViolationCount)
      return candidate.absoluteViolationCount < reference.absoluteViolationCount;
    if(less(candidate.absolutePenalty, reference.absolutePenalty, tolerance))
      return true;
    if(less(reference.absolutePenalty, candidate.absolutePenalty, tolerance))
      return false;
    if(candidate.preferredViolationCount != reference.preferredViolationCount)
      return candidate.preferredViolationCount < reference.preferredViolationCount;
    if(less(candidate.worstPreferredViolation,
            reference.worstPreferredViolation, tolerance))
      return true;
    if(less(reference.worstPreferredViolation,
            candidate.worstPreferredViolation, tolerance))
      return false;
    if(less(candidate.preferredPenalty, reference.preferredPenalty, tolerance))
      return true;
    if(less(reference.preferredPenalty, candidate.preferredPenalty, tolerance))
      return false;
    return less(candidate.shapePenalty, reference.shapePenalty, tolerance);
  }

  bool writeQualityPos(const std::vector<MElement *> &elements,
                       const std::string &filename)
  {
    struct View {
      const char *name;
      Criterion criterion;
      bool triangles;
      bool quadrangles;
    };
    const std::array<View, 7> views = {{{"Warping (deg)", Criterion::Warping, false, true},
      {"Edge ratio", Criterion::EdgeRatio, true, true},
      {"Minimum angle - quads (deg)", Criterion::MinimumQuadAngle, false, true},
      {"Maximum angle - quads (deg)", Criterion::MaximumQuadAngle, false, true},
      {"Minimum angle - triangles (deg)", Criterion::MinimumTriangleAngle, true, false},
      {"Maximum angle - triangles (deg)", Criterion::MaximumTriangleAngle, true, false},
      {"Skewing I-DEAS (deg)", Criterion::Skewing, true, true}}};
    std::ofstream out(filename);
    if(!out) return false;
    out << std::setprecision(17);
    for(const View &view : views) {
      out << "View \"" << view.name << "\" {\n";
      for(const MElement *element : elements) {
        if(!element) continue;
        const std::size_t count = element->getNumPrimaryVertices();
        if((count == 3 && !view.triangles) ||
           (count == 4 && !view.quadrangles) || (count != 3 && count != 4))
          continue;
        const ElementQuality quality = evaluateElementQuality(element);
        writeElement(out, element, value(quality, view.criterion));
      }
      out << "};\n";
    }
    out << "View \"Passes absolute specifications\" {\n";
    for(const MElement *element : elements) {
      if(!element) continue;
      const std::size_t count = element->getNumPrimaryVertices();
      if(count != 3 && count != 4) continue;
      writeElement(out, element,
        evaluateElementQuality(element).passesAbsoluteSpecifications ? 1. : 0.);
    }
    out << "};\n";
    return static_cast<bool>(out);
  }

  bool writeFaceQualityPos(int faceTag, const std::string &filename)
  {
    GFace *face = GModel::current()->getFaceByTag(faceTag);
    if(!face) return false;
    std::vector<MElement *> elements;
    elements.reserve(face->triangles.size() + face->quadrangles.size());
    for(MTriangle *triangle : face->triangles) elements.push_back(triangle);
    for(MQuadrangle *quadrangle : face->quadrangles)
      elements.push_back(quadrangle);
    return writeQualityPos(elements, filename);
  }

  bool writeModelQualityPos(const std::string &filename)
  {
    std::vector<MElement *> elements;
    for(GFace *face : GModel::current()->getFaces()) {
      for(MTriangle *triangle : face->triangles) elements.push_back(triangle);
      for(MQuadrangle *quadrangle : face->quadrangles)
        elements.push_back(quadrangle);
    }
    return writeQualityPos(elements, filename);
  }

} // namespace QuadOptimizer
