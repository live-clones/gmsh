#include "matPolygonFan.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace matgmsh {
namespace polygon_fan {
namespace {

using Point2 = std::array<double, 2>;
constexpr double eps = std::numeric_limits<double>::epsilon();

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
bool finite(const Point &a)
{
  return std::isfinite(a[0]) && std::isfinite(a[1]) && std::isfinite(a[2]);
}
void compensatedAdd(double value, double &sum, double &correction)
{
  const double y = value - correction;
  const double next = sum + y;
  correction = (next - sum) - y;
  sum = next;
}
double orient(const Point2 &a, const Point2 &b, const Point2 &c)
{
  return std::fma(b[0] - a[0], c[1] - a[1],
                  -(b[1] - a[1]) * (c[0] - a[0]));
}

// A conservative contact test: near contacts are unsupported, rather than
// certified as a simple contour using an uncertain floating-point sign.
bool simple(const std::vector<Point2> &p, double tolerance)
{
  for(std::size_t i = 0; i < p.size(); ++i) {
    const Point2 &a = p[i], &b = p[(i + 1) % p.size()];
    if(std::hypot(b[0] - a[0], b[1] - a[1]) <= tolerance) return false;
    for(std::size_t j = i + 1; j < p.size(); ++j) {
      if(j == i + 1 || (i == 0 && j + 1 == p.size())) continue;
      const Point2 &c = p[j], &d = p[(j + 1) % p.size()];
      if(std::max(a[0], b[0]) + tolerance < std::min(c[0], d[0]) ||
         std::max(c[0], d[0]) + tolerance < std::min(a[0], b[0]) ||
         std::max(a[1], b[1]) + tolerance < std::min(c[1], d[1]) ||
         std::max(c[1], d[1]) + tolerance < std::min(a[1], b[1]))
        continue;
      const double ab = std::hypot(b[0] - a[0], b[1] - a[1]);
      const double cd = std::hypot(d[0] - c[0], d[1] - c[1]);
      const double x = orient(a, b, c) / ab;
      const double y = orient(a, b, d) / ab;
      const double z = orient(c, d, a) / cd;
      const double w = orient(c, d, b) / cd;
      if((x > tolerance && y > tolerance) ||
         (x < -tolerance && y < -tolerance) ||
         (z > tolerance && w > tolerance) ||
         (z < -tolerance && w < -tolerance))
        continue;
      return false;
    }
  }
  return true;
}

struct HalfPlane {
  Point2 normal;
  double offset;
  double distance(const Point2 &p) const
  {
    return std::fma(normal[0], p[0], normal[1] * p[1]) - offset;
  }
};

std::vector<Point2> clip(const std::vector<Point2> &polygon,
                         const HalfPlane &plane, double margin)
{
  std::vector<Point2> result;
  if(polygon.empty()) return result;
  Point2 previous = polygon.back();
  double previousDistance = plane.distance(previous) - margin;
  for(const Point2 &point : polygon) {
    const double distance = plane.distance(point) - margin;
    if((previousDistance >= 0.) != (distance >= 0.)) {
      const double fraction = previousDistance / (previousDistance - distance);
      result.push_back({previous[0] + fraction * (point[0] - previous[0]),
                        previous[1] + fraction * (point[1] - previous[1])});
    }
    if(distance >= 0.) result.push_back(point);
    previous = point;
    previousDistance = distance;
  }
  return result;
}

} // namespace

Result selectCenter(const std::vector<Point> &boundary, const Point &center)
{
  Result result;
  result.center = center;
  if(boundary.size() < 3 || !finite(center)) return result;
  double radius = 0., worldScale = 0.;
  for(const Point &p : boundary) {
    if(!finite(p)) return result;
    radius = std::max(radius, norm(subtract(p, center)));
    for(double value : p) worldScale = std::max(worldScale, std::abs(value));
  }
  if(!std::isfinite(radius) || radius <= 0.) {
    result.reason = Reason::Degenerate;
    return result;
  }

  std::vector<Point> local;
  local.reserve(boundary.size());
  for(const Point &p : boundary) {
    Point q = subtract(p, center);
    for(double &x : q) x /= radius;
    local.push_back(q);
  }
  Point normal{}, correction{};
  for(std::size_t i = 0; i < local.size(); ++i) {
    const Point n = cross(local[i], local[(i + 1) % local.size()]);
    for(int k = 0; k < 3; ++k)
      compensatedAdd(n[k], normal[k], correction[k]);
  }
  const double length = norm(normal);
  if(!std::isfinite(length) || length <= 64. * eps) {
    result.reason = Reason::Degenerate;
    return result;
  }
  for(double &x : normal) x /= length;

  bool coherent = true;
  double planeDeviation = 0.;
  for(std::size_t i = 0; i < local.size(); ++i) {
    const Point n = cross(local[i], local[(i + 1) % local.size()]);
    coherent = coherent && dot(n, normal) > 0.;
    planeDeviation = std::max(planeDeviation, std::abs(dot(local[i], normal)));
  }
  const double planeTolerance = 1e-8 + 64. * eps * worldScale / radius;
  if(planeDeviation > planeTolerance) {
    result.status = coherent ? Status::UnchangedCoherent : Status::Unsupported;
    result.reason = coherent ? Reason::None : Reason::NonPlanar;
    return result;
  }

  // This oriented orthonormal chart follows the polygon's own winding.
  int axis = 0;
  for(int k = 1; k < 3; ++k)
    if(std::abs(normal[k]) < std::abs(normal[axis])) axis = k;
  Point reference{};
  reference[axis] = 1.;
  Point u = cross(reference, normal);
  const double uLength = norm(u);
  for(double &x : u) x /= uLength;
  const Point v = cross(normal, u);
  std::vector<Point2> projected;
  projected.reserve(local.size());
  for(const Point &p : local) projected.push_back({dot(p, u), dot(p, v)});
  const double minimumMargin = std::max(1e-12, 512. * eps * worldScale / radius);
  if(!simple(projected, minimumMargin)) {
    result.reason = Reason::NonSimple;
    return result;
  }
  if(coherent) {
    result.status = Status::UnchangedCoherent;
    result.reason = Reason::None;
    return result;
  }

  Point2 low = projected.front(), high = low;
  std::vector<HalfPlane> planes;
  for(std::size_t i = 0; i < projected.size(); ++i) {
    const Point2 &a = projected[i], &b = projected[(i + 1) % projected.size()];
    for(int k = 0; k < 2; ++k) {
      low[k] = std::min(low[k], a[k]);
      high[k] = std::max(high[k], a[k]);
    }
    const double length = std::hypot(b[0] - a[0], b[1] - a[1]);
    HalfPlane plane{{-(b[1] - a[1]) / length, (b[0] - a[0]) / length}, 0.};
    plane.offset = plane.normal[0] * a[0] + plane.normal[1] * a[1];
    planes.push_back(plane);
  }
  std::vector<Point2> kernel{{low[0], low[1]}, {high[0], low[1]},
                              {high[0], high[1]}, {low[0], high[1]}};
  for(const HalfPlane &plane : planes) kernel = clip(kernel, plane, 2. * minimumMargin);
  if(kernel.size() < 3) {
    result.reason = Reason::EmptyKernel;
    return result;
  }
  Point2 chosen{}, sumCorrection{};
  for(const Point2 &p : kernel)
    for(int k = 0; k < 2; ++k)
      compensatedAdd(p[k], chosen[k], sumCorrection[k]);
  for(double &x : chosen) x /= static_cast<double>(kernel.size());
  Point candidate{};
  for(int k = 0; k < 3; ++k)
    candidate[k] = center[k] + radius * (u[k] * chosen[0] + v[k] * chosen[1]);
  if(!finite(candidate)) return result;

  // Audit the rounded XYZ that will actually be exported, not just the ideal
  // 2D kernel point. Keep a length margin above the world-coordinate ULPs.
  Point actual = subtract(candidate, center);
  for(double &x : actual) x /= radius;
  const Point2 actualUV{dot(actual, u), dot(actual, v)};
  double margin = std::numeric_limits<double>::infinity();
  for(const HalfPlane &plane : planes)
    margin = std::min(margin, plane.distance(actualUV));
  if(!std::isfinite(margin) || margin < minimumMargin) {
    result.reason = Reason::InsufficientMargin;
    return result;
  }
  for(std::size_t i = 0; i < boundary.size(); ++i) {
    const Point a = subtract(boundary[i], candidate);
    const Point b = subtract(boundary[(i + 1) % boundary.size()], candidate);
    const Point n = cross(a, b);
    if(!finite(n) || !(dot(n, normal) > 0.)) {
      result.reason = Reason::InsufficientMargin;
      return result;
    }
  }
  result.center = candidate;
  result.status = Status::Corrected;
  result.reason = Reason::None;
  result.minimumMargin = margin * radius;
  return result;
}

const char *reasonName(Reason reason)
{
  switch(reason) {
  case Reason::None: return "none";
  case Reason::InvalidInput: return "invalidInput";
  case Reason::Degenerate: return "degenerate";
  case Reason::NonPlanar: return "nonPlanar";
  case Reason::NonSimple: return "nonSimple";
  case Reason::EmptyKernel: return "emptyKernel";
  case Reason::InsufficientMargin: return "insufficientMargin";
  }
  return "unknown";
}

} // namespace polygon_fan
} // namespace matgmsh
