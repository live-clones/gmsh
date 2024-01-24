// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SBOUNDING_BOX_3D_H
#define SBOUNDING_BOX_3D_H

#include <float.h>
#include "SPoint3.h"
#include "SVector3.h"
#include "MVertex.h"

#if defined(WIN32)
#undef min
#undef max
#endif

// A bounding box class - add points and it grows to be the bounding
// box of the point set
class SBoundingBox3d {
private:
  SPoint3 MinPt, MaxPt;

public:
  SBoundingBox3d()
    : MinPt(DBL_MAX, DBL_MAX, DBL_MAX), MaxPt(-DBL_MAX, -DBL_MAX, -DBL_MAX)
  {
  }
  SBoundingBox3d(const SPoint3 &pt) : MinPt(pt), MaxPt(pt) {}
  SBoundingBox3d(double xmin, double ymin, double zmin, double xmax,
                 double ymax, double zmax)
    : MinPt(xmin, ymin, zmin), MaxPt(xmax, ymax, zmax)
  {
  }
  bool empty()
  {
    if(MinPt.x() == DBL_MAX || MinPt.y() == DBL_MAX || MinPt.z() == DBL_MAX ||
       MaxPt.x() == -DBL_MAX || MaxPt.y() == -DBL_MAX || MaxPt.z() == -DBL_MAX)
      return true;
    return false;
  }
  void reset()
  {
    MinPt = SPoint3(DBL_MAX, DBL_MAX, DBL_MAX);
    MaxPt = SPoint3(-DBL_MAX, -DBL_MAX, -DBL_MAX);
  }
  void operator+=(const SPoint3 &pt)
  {
    // note: it is possible for pt[i] to be both > MaxPt[i] and < MinPt[i]
    // the first point always will be both
    if(pt[0] < MinPt[0]) MinPt[0] = pt[0];
    if(pt[0] > MaxPt[0]) MaxPt[0] = pt[0];

    if(pt[1] < MinPt[1]) MinPt[1] = pt[1];
    if(pt[1] > MaxPt[1]) MaxPt[1] = pt[1];

    if(pt[2] < MinPt[2]) MinPt[2] = pt[2];
    if(pt[2] > MaxPt[2]) MaxPt[2] = pt[2];
  }
  void operator+=(const SBoundingBox3d &box)
  {
    (*this) += box.MinPt;
    (*this) += box.MaxPt;
  }
  void operator*=(double scale)
  {
    SPoint3 center = (MinPt + MaxPt) * .5;
    MaxPt -= center;
    MinPt -= center;
    MaxPt *= scale;
    MinPt *= scale;
    MaxPt += center;
    MinPt += center;
  }
  void scale(double sx, double sy, double sz)
  {
    SPoint3 center = (MinPt + MaxPt) * .5;
    MaxPt -= center;
    MinPt -= center;
    MaxPt[0] *= sx;
    MaxPt[1] *= sy;
    MaxPt[2] *= sz;
    MinPt[0] *= sx;
    MinPt[1] *= sy;
    MinPt[2] *= sz;
    MaxPt += center;
    MinPt += center;
  }
  SPoint3 min() const { return MinPt; }
  SPoint3 max() const { return MaxPt; }
  SPoint3 center() const { return (MinPt + MaxPt) * .5; }
  double diag() const { return MinPt.distance(MaxPt); }
  void makeCube()
  {
    SVector3 len = MaxPt - MinPt;
    SPoint3 cc = center();
    MaxPt = cc + SPoint3(1, 1, 1);
    MinPt = cc + SPoint3(-1, -1, -1);
    double sc = len.norm() * 0.5;
    scale(sc, sc, sc);
  }
  void thicken(double factor)
  {
    double d = factor * diag();
    SPoint3 t(d, d, d);
    MinPt -= t;
    MaxPt += t;
  }
  bool contains(const SBoundingBox3d &bound)
  {
    if(bound.MinPt.x() >= MinPt.x() && bound.MinPt.y() >= MinPt.y() &&
       bound.MinPt.z() >= MinPt.z() && bound.MaxPt.x() <= MaxPt.x() &&
       bound.MaxPt.y() <= MaxPt.y() && bound.MaxPt.z() <= MaxPt.z())
      return true;
    return false;
  }
  bool contains(const SPoint3 &p)
  {
    if(p.x() >= MinPt.x() && p.y() >= MinPt.y() && p.z() >= MinPt.z() &&
       p.x() <= MaxPt.x() && p.y() <= MaxPt.y() && p.z() <= MaxPt.z())
      return true;
    return false;
  }
  bool contains(double x, double y, double z)
  {
    if(x >= MinPt.x() && y >= MinPt.y() && z >= MinPt.z() && x <= MaxPt.x() &&
       y <= MaxPt.y() && z <= MaxPt.z())
      return true;
    return false;
  }
  bool transform(const std::vector<double> &tfo)
  {
    if(tfo.size() != 16) return false;
    MinPt.transform(tfo);
    MaxPt.transform(tfo);
    return true;
  }
};

#endif
