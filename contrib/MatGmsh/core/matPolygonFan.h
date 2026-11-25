#ifndef MAT_POLYGON_FAN_H
#define MAT_POLYGON_FAN_H

#include <array>
#include <vector>

namespace matgmsh {
namespace polygon_fan {

using Point = std::array<double, 3>;

enum class Status { UnchangedCoherent, Corrected, Unsupported };
enum class Reason {
  None,
  InvalidInput,
  Degenerate,
  NonPlanar,
  NonSimple,
  EmptyKernel,
  InsufficientMargin
};

struct Result {
  Status status = Status::Unsupported;
  Reason reason = Reason::InvalidInput;
  Point center{};
  double minimumMargin = 0.;
};

// Keep an already coherent arithmetic fan bit for bit. Otherwise, move only
// its auxiliary center into the kernel of a simple, nearly planar polygon.
// Boundary vertices are never changed. Unsupported results retain the input
// center and make no validity claim; downstream mesh guards still apply.
// The supporting-plane tolerance is 1e-8 times the local radius plus the
// rounding allowance 64*epsilon times the largest input coordinate magnitude.
Result selectCenter(const std::vector<Point> &boundary,
                    const Point &arithmeticCenter);
const char *reasonName(Reason reason);

} // namespace polygon_fan
} // namespace matgmsh

#endif
