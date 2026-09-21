// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CLIP_PLANES_H
#define CLIP_PLANES_H

#include <algorithm>
#include <cmath>
#include "Context.h"

// The questions asked of the six clipping planes (CTX::clipPlane), by the
// geometry, the mesh and the views alike. Each of those has a mask
// (Geometry.Clip, Mesh.Clip, View.Clip) with a bit for each plane that
// applies to it. A plane a x + b y + c z + d = 0 removes what is on its
// negative side.
//
// The nodes of an element are given as xyz(j, k), coordinate k of node j, so
// that the same code serves the elements of a mesh and those of a view.
namespace clipPlanes {

  inline bool inMask(int mask, int i) { return (mask >> i) & 1; }

  // positive on the side that is kept
  inline double eval(int i, double x, double y, double z)
  {
    const double *p = CTX::instance()->clipPlane[i];
    return p[0] * x + p[1] * y + p[2] * z + p[3];
  }

  // does a plane of the mask remove this point?
  inline bool removes(int mask, double x, double y, double z)
  {
    for(int i = 0; i < 6; i++)
      if(inMask(mask, i) && eval(i, x, y, z) < 0.) return true;
    return false;
  }

  // the side of plane i the n nodes are on: negative if it removes them all,
  // positive if it keeps them all, 0 if it cuts through them (or touches one)
  template <class XYZ> double side(int i, int n, XYZ xyz)
  {
    double first = eval(i, xyz(0, 0), xyz(0, 1), xyz(0, 2));
    for(int j = 1; j < n; j++)
      if(first * eval(i, xyz(j, 0), xyz(j, 1), xyz(j, 2)) <= 0.) return 0.;
    return first;
  }

  // does a plane of the mask remove all the n nodes?
  template <class XYZ> bool removesAll(int mask, int n, XYZ xyz)
  {
    for(int i = 0; i < 6; i++)
      if(inMask(mask, i) && side(i, n, xyz) < 0.) return true;
    return false;
  }

  // Does whole element mode keep an element of this dimension? Only the
  // elements a plane removes entirely are dropped; the planes leave curves
  // and surfaces alone when only the volume is clipped, and drop the volume
  // elements they do not cut when only the cut volumes are drawn.
  template <class XYZ> bool keeps(int mask, int dim, int n, XYZ xyz)
  {
    CTX *ctx = CTX::instance();
    for(int i = 0; i < 6; i++) {
      if(!inMask(mask, i)) continue;
      if(dim < 3 && ctx->clipOnlyVolume) continue;
      double s = side(i, n, xyz);
      if(dim == 3 && ctx->clipOnlyDrawIntersectingVolume && s) return false;
      if(s < 0.) return false;
    }
    return true;
  }

  // does a plane of the mask cut through the nodes?
  template <class XYZ> bool cuts(int mask, int n, XYZ xyz)
  {
    for(int i = 0; i < 6; i++)
      if(inMask(mask, i) && !side(i, n, xyz)) return true;
    return false;
  }

} // namespace clipPlanes

// The planes of a mask with normals of length 1, to measure distances from
// (see ElementSpheres.h)
class activePlanes {
private:
  int _n;
  double _eq[6][4];

public:
  activePlanes(int mask) : _n(0)
  {
    for(int i = 0; i < 6; i++) {
      if(!clipPlanes::inMask(mask, i)) continue;
      const double *pl = CTX::instance()->clipPlane[i];
      double norm = std::sqrt(pl[0] * pl[0] + pl[1] * pl[1] + pl[2] * pl[2]);
      if(!norm) continue;
      for(int k = 0; k < 4; k++) _eq[_n][k] = pl[k] / norm;
      _n++;
    }
  }
  int num() const { return _n; }
  // the distance from a sphere (centre and radius) to the closest plane,
  // negative or zero if one may cut what it holds
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
