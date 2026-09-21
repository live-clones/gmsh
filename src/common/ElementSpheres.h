// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ELEMENT_SPHERES_H
#define ELEMENT_SPHERES_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>
#include "Context.h"

// A sphere around each element of a list, as it is drawn, kept from one
// position of the clipping planes to the next: the elements a plane may cut
// are then found without reading any of the others. What decides that a plane
// cuts an element only looks at the side its nodes are on; the sphere holds
// them all, so that one that is clear of a plane is around an element that is
// not cut, however distorted.
class elementSpheres {
private:
  std::vector<float> _s; // centre and radius; a negative radius if not drawn
  std::vector<std::uint8_t> _dim;

public:
  void assign(std::size_t num)
  {
    _s.assign(4 * num, -1.f);
    _dim.assign(num, 0);
  }
  std::size_t size() const { return _dim.size(); }
  double getMemoryInMB() const { return 17. * size() / 1024. / 1024.; }
  // around n nodes given by xyz(j, k); distinct elements can be set by
  // distinct threads
  template <class XYZ> void set(std::size_t i, int dim, int n, XYZ xyz)
  {
    double c[3] = {0., 0., 0.}, r2 = 0.;
    for(int j = 0; j < n; j++)
      for(int k = 0; k < 3; k++) c[k] += xyz(j, k);
    float *s = &_s[4 * i];
    for(int k = 0; k < 3; k++) s[k] = (float)(c[k] / n);
    // around the centre as it was rounded
    for(int j = 0; j < n; j++) {
      double d2 = 0.;
      for(int k = 0; k < 3; k++) d2 += (xyz(j, k) - s[k]) * (xyz(j, k) - s[k]);
      r2 = std::max(r2, d2);
    }
    double mag = std::abs(c[0]) + std::abs(c[1]) + std::abs(c[2]);
    s[3] = (float)(std::sqrt(r2) * (1. + 1e-5) + 1e-6 * mag / n + 1e-30);
    _dim[i] = (std::uint8_t)dim;
  }
  bool drawn(std::size_t i) const { return _s[4 * i + 3] >= 0.f; }
  int dim(std::size_t i) const { return _dim[i]; }
  double radius(std::size_t i) const { return _s[4 * i + 3]; }
  const float *sphere(std::size_t i) const { return &_s[4 * i]; }
};

// the clipping planes of a mask, with normals of length 1
class activePlanes {
private:
  int _n;
  double _eq[6][4];

public:
  activePlanes(int mask) : _n(0)
  {
    for(int clip = 0; clip < 6; clip++) {
      if(!(mask & (1 << clip))) continue;
      const double *pl = CTX::instance()->clipPlane[clip];
      double norm = std::sqrt(pl[0] * pl[0] + pl[1] * pl[1] + pl[2] * pl[2]);
      if(!norm) continue;
      for(int k = 0; k < 4; k++) _eq[_n][k] = pl[k] / norm;
      _n++;
    }
  }
  int num() const { return _n; }
  // the distance from a sphere to the closest plane, negative or zero if
  // one may cut what it holds
  double gap(const float *s) const
  {
    double g = 1e300;
    for(int i = 0; i < _n; i++) {
      double d =
        _eq[i][0] * s[0] + _eq[i][1] * s[1] + _eq[i][2] * s[2] + _eq[i][3];
      g = std::min(g, std::abs(d) - (double)s[3] * (1. + 1e-5));
    }
    return g;
  }
};

#endif
