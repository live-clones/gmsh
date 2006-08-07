#ifndef _SBOUNDING_BOX_3D_H_
#define _SBOUNDING_BOX_3D_H_

#include "SPoint3.h"

// A bounding box class - add points and it grows to be the bounding
// box of the point set
class SBoundingBox3d {
 public:
  SBoundingBox3d();
  SBoundingBox3d(const SPoint3 &);
  bool empty();
  void operator+=(const SPoint3 &pt);
  void operator+=(const SBoundingBox3d &pt);
  void operator*=(double scale);
  void scale(double, double, double);
  SPoint3 min() const;
  SPoint3 max() const;
  SPoint3 center() const;
  void makeCube();
 private:
  SPoint3 MinPt,MaxPt;
};

#endif
