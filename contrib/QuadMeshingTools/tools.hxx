#ifndef CFMB_TOOLS_H
#define CFMB_TOOLS_H

#include <vector>
#include <cstddef>
#include <cmath>

namespace tools{
  void normalize(std::vector<double> &v);
  void scale(std::vector<double> &v, double scaling);
  std::vector<double> getNormalizedVector(const std::vector<double> &v);
  std::vector<double> crossprod(const std::vector<double> &v0, const std::vector<double> &v1);
  double dotprod(const std::vector<double> &v0, const std::vector<double> &v1);
  double norm(const std::vector<double> &v);
  double norm(const double *v, const size_t &size);
  double distance(const std::vector<double> &v0, const std::vector<double> &v1);
}

#endif
