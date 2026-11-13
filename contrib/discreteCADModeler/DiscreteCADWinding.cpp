// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <thread>
#include "DiscreteCADWinding.h"

namespace {
  const double pi = 3.14159265358979323846;

  // the solid angle of triangle abc seen from q (Van Oosterom and Strackee),
  // positive if q is on the side opposite to its normal
  double solidAngle(const double q[3], const double *a, const double *b,
                    const double *c)
  {
    double p[3], r[3], s[3];
    for(int k = 0; k < 3; k++) {
      p[k] = a[k] - q[k];
      r[k] = b[k] - q[k];
      s[k] = c[k] - q[k];
    }
    const double lp = std::sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
    const double lr = std::sqrt(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);
    const double ls = std::sqrt(s[0] * s[0] + s[1] * s[1] + s[2] * s[2]);
    const double det = p[0] * (r[1] * s[2] - r[2] * s[1]) -
                       p[1] * (r[0] * s[2] - r[2] * s[0]) +
                       p[2] * (r[0] * s[1] - r[1] * s[0]);
    const double pr = p[0] * r[0] + p[1] * r[1] + p[2] * r[2];
    const double ps = p[0] * s[0] + p[1] * s[1] + p[2] * s[2];
    const double rs = r[0] * s[0] + r[1] * s[1] + r[2] * s[2];
    return 2. * std::atan2(det, lp * lr * ls + pr * ls + ps * lr + rs * lp);
  }
} // namespace

DiscreteCADWinding::DiscreteCADWinding(
  const std::vector<std::array<double, 3> > &x,
  const std::vector<std::array<int, 3> > &triangles, double beta)
  : _x(x), _t(triangles), _beta(beta)
{
  if(_t.empty()) return;
  std::vector<int> order(_t.size());
  for(std::size_t i = 0; i < order.size(); i++) order[i] = (int)i;
  _nodes.reserve(2 * _t.size() / 4 + 1);
  _build(order, 0, (int)_t.size());
  // (the triangles in the order of the leaves)
  std::vector<std::array<int, 3> > t(_t.size());
  for(std::size_t i = 0; i < order.size(); i++) t[i] = _t[order[i]];
  _t = t;
}

int DiscreteCADWinding::_build(std::vector<int> &order, int first, int count)
{
  const int index = (int)_nodes.size();
  _nodes.push_back(Node());
  // the moments of the triangles about their area-weighted centroid
  double area = 0., c[3] = {0., 0., 0.}, g[3] = {0., 0., 0.};
  for(int i = first; i < first + count; i++) {
    const std::array<int, 3> &t = _t[order[i]];
    const double *a = _x[t[0]].data(), *b = _x[t[1]].data(), *d = _x[t[2]].data();
    double u[3], v[3];
    for(int k = 0; k < 3; k++) {
      u[k] = b[k] - a[k];
      v[k] = d[k] - a[k];
    }
    const double n[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
                         u[0] * v[1] - u[1] * v[0]};
    const double A = 0.5 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    area += A;
    for(int k = 0; k < 3; k++) {
      const double gk = (a[k] + b[k] + d[k]) / 3.;
      c[k] += A * gk;
      g[k] += gk;
    }
  }
  for(int k = 0; k < 3; k++) c[k] = area > 0. ? c[k] / area : g[k] / count;
  Node n;
  for(int k = 0; k < 3; k++) n.c[k] = c[k];
  n.r = 0.;
  for(int k = 0; k < 3; k++) n.m0[k] = 0.;
  for(int k = 0; k < 9; k++) n.m1[k] = 0.;
  for(int k = 0; k < 27; k++) n.m2[k] = 0.;
  for(int i = first; i < first + count; i++) {
    const std::array<int, 3> &t = _t[order[i]];
    double e[3][3], u[3], v[3], s[3] = {0., 0., 0.};
    for(int m = 0; m < 3; m++)
      for(int k = 0; k < 3; k++) {
        e[m][k] = _x[t[m]][k] - c[k];
        s[k] += e[m][k];
      }
    for(int m = 0; m < 3; m++)
      n.r = std::max(n.r, std::sqrt(e[m][0] * e[m][0] + e[m][1] * e[m][1] +
                                    e[m][2] * e[m][2]));
    for(int k = 0; k < 3; k++) {
      u[k] = e[1][k] - e[0][k];
      v[k] = e[2][k] - e[0][k];
    }
    // (the area-weighted normal a, the centroid about the center s / 3, and
    // the second moment, the integral of (x - c)(x - c)^T over the triangle:
    // A / 12 (sum of e e^T + s s^T))
    const double a[3] = {0.5 * (u[1] * v[2] - u[2] * v[1]),
                         0.5 * (u[2] * v[0] - u[0] * v[2]),
                         0.5 * (u[0] * v[1] - u[1] * v[0])};
    double second[3][3];
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        second[j][k] = (e[0][j] * e[0][k] + e[1][j] * e[1][k] +
                        e[2][j] * e[2][k] + s[j] * s[k]) /
                       12.;
    for(int i2 = 0; i2 < 3; i2++) {
      n.m0[i2] += a[i2];
      for(int j = 0; j < 3; j++) {
        n.m1[3 * i2 + j] += a[i2] * s[j] / 3.;
        for(int k = 0; k < 3; k++) n.m2[9 * i2 + 3 * j + k] += a[i2] * second[j][k];
      }
    }
  }
  n.first = first;
  n.count = count;
  n.left = n.right = -1;
  if(count > 8) {
    // (split at the median of the centroids along the longest side of their
    // box)
    double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
    auto centroid = [&](int i, int k) {
      const std::array<int, 3> &t = _t[i];
      return _x[t[0]][k] + _x[t[1]][k] + _x[t[2]][k];
    };
    for(int i = first; i < first + count; i++)
      for(int k = 0; k < 3; k++) {
        lo[k] = std::min(lo[k], centroid(order[i], k));
        hi[k] = std::max(hi[k], centroid(order[i], k));
      }
    int axis = 0;
    for(int k = 1; k < 3; k++)
      if(hi[k] - lo[k] > hi[axis] - lo[axis]) axis = k;
    const int half = count / 2;
    std::nth_element(order.begin() + first, order.begin() + first + half,
                     order.begin() + first + count, [&](int i, int j) {
                       return centroid(i, axis) < centroid(j, axis);
                     });
    _nodes[index] = n;
    const int left = _build(order, first, half);
    const int right = _build(order, first + half, count - half);
    _nodes[index].left = left;
    _nodes[index].right = right;
    return index;
  }
  _nodes[index] = n;
  return index;
}

double DiscreteCADWinding::_leaf(const Node &n, const double q[3]) const
{
  double w = 0.;
  for(int i = n.first; i < n.first + n.count; i++)
    w += solidAngle(q, _x[_t[i][0]].data(), _x[_t[i][1]].data(),
                    _x[_t[i][2]].data());
  return w;
}

double DiscreteCADWinding::operator()(const double q[3]) const
{
  if(_nodes.empty()) return 0.;
  // (the solid angles: those of the leaves near q, and the expansions of the
  // boxes far from it, of the kernel (x - q) / |x - q|^3 dotted with the
  // normals, about their centers)
  double w = 0.;
  int stack[128], top = 0;
  stack[top++] = 0;
  while(top) {
    const Node &n = _nodes[stack[--top]];
    const double r[3] = {n.c[0] - q[0], n.c[1] - q[1], n.c[2] - q[2]};
    const double r2 = r[0] * r[0] + r[1] * r[1] + r[2] * r[2];
    if(r2 > _beta * _beta * n.r * n.r) {
      const double rho = std::sqrt(r2);
      const double i3 = 1. / (r2 * rho), i5 = i3 / r2, i7 = i5 / r2;
      // f(r) . m0
      double t = (n.m0[0] * r[0] + n.m0[1] * r[1] + n.m0[2] * r[2]) * i3;
      // J : m1, J_ij = d_ij / rho^3 - 3 r_i r_j / rho^5
      double rm1r = 0.;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) rm1r += r[i] * n.m1[3 * i + j] * r[j];
      t += (n.m1[0] + n.m1[4] + n.m1[8]) * i3 - 3. * rm1r * i5;
      // H : m2 / 2, H_ijk = -3 (d_ij r_k + d_ik r_j + d_jk r_i) / rho^5 +
      // 15 r_i r_j r_k / rho^7 (m2 symmetric in jk)
      double iik = 0., ijj = 0., rrr = 0.;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
          iik += n.m2[9 * i + 3 * i + j] * r[j];
          ijj += n.m2[9 * i + 3 * j + j] * r[i];
          for(int k = 0; k < 3; k++)
            rrr += n.m2[9 * i + 3 * j + k] * r[i] * r[j] * r[k];
        }
      t += 0.5 * (-3. * (2. * iik + ijj) * i5 + 15. * rrr * i7);
      // (a solid angle, as those of the leaves)
      w += t;
      continue;
    }
    if(n.left < 0) {
      w += _leaf(n, q);
      continue;
    }
    stack[top++] = n.left;
    stack[top++] = n.right;
  }
  return w / (4. * pi);
}

void DiscreteCADWinding::evaluate(const std::vector<std::array<double, 3> > &q,
                                  std::vector<double> &w) const
{
  w.resize(q.size());
  // (in chunks taken in turn by the threads of the machine)
  const std::size_t chunk = 1024;
  std::atomic<std::size_t> next(0);
  auto work = [&]() {
    for(std::size_t i; (i = next.fetch_add(chunk)) < q.size();)
      for(std::size_t j = i; j < std::min(q.size(), i + chunk); j++)
        w[j] = (*this)(q[j].data());
  };
  const unsigned n = std::max(1u, std::thread::hardware_concurrency());
  std::vector<std::thread> threads;
  for(unsigned t = 1; t < n && q.size() > chunk; t++) threads.emplace_back(work);
  work();
  for(auto &t : threads) t.join();
}

double DiscreteCADWinding::exact(const double q[3]) const
{
  double w = 0.;
  for(auto &t : _t)
    w += solidAngle(q, _x[t[0]].data(), _x[t[1]].data(), _x[t[2]].data());
  return w / (4. * pi);
}
