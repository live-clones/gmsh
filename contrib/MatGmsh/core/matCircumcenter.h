#ifndef MAT_CIRCUMCENTER_H
#define MAT_CIRCUMCENTER_H

#include <array>

namespace matgmsh::circumcenter {

enum class Status { Fast, Exact, Degenerate };

struct Result {
  std::array<double, 3> center{};
  double determinant = 0.;
  Status status = Status::Fast;
};

// Preserve the historical double construction when an outward interval
// certifies its coordinate error below 1e-10 times the largest local edge
// component plus eight storage ULPs. Otherwise construct the center exactly
// from the input doubles and round only the final coordinates.
// Degenerate explicitly denotes the historical barycenter substitute: an
// exactly coplanar tetrahedron has no unique three-dimensional circumcenter.
// Nonfinite inputs or an unrepresentable output center throw std::runtime_error.
Result compute(const double *a, const double *b, const double *c,
               const double *d);

} // namespace matgmsh::circumcenter

#endif
