// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Bastien Gorissen
//

#ifndef ORIENTED_BOUNDING_BOX_H
#define ORIENTED_BOUNDING_BOX_H

#include "SVector3.h"
#include "SPoint2.h"

#include <algorithm>
#include <array>
#include <vector>

class SOrientedBoundingRectangle {
public:
  SOrientedBoundingRectangle();

  double area();

public:
  std::array<double, 2> center;
  std::array<double, 2> size;
  std::array<double, 2> axisX;
  std::array<double, 2> axisY;
};

class SOrientedBoundingBox {
public:
  SOrientedBoundingBox();

  // x, y, z are the box center, whereas the sizes are in the local
  // axis system of the box. The axis form the local coordinates
  // system of the box. All these data are given in the local
  // coordinates system of the object.
  SOrientedBoundingBox(SVector3 &center, double sizeX, double sizeY,
                       double sizeZ, const SVector3 &axisX,
                       const SVector3 &axisY, const SVector3 &axisZ);

  SOrientedBoundingBox(SOrientedBoundingBox *other);

  const SVector3 &getCenter() const { return center; }
  double getCenterX() const { return center[0]; }
  double getCenterY() const { return center[1]; }
  double getCenterZ() const { return center[2]; }
  SVector3 getSize() const { return size; }

  double getMaxSize() const
  {
    return std::max(size[0], std::max(size[1], size[2]));
  }

  double getMinSize() const
  {
    return std::min(size[0], std::min(size[1], size[2]));
  }

  /// valid values for axis are 0 (X-axis), 1 (Y-axis) or 2 (Z-axis)
  SVector3 getAxis(int axis) const;

  static SOrientedBoundingBox *buildOBB(std::vector<SPoint3> &vertices);

  bool intersects(SOrientedBoundingBox &obb) const;

  static double compare(SOrientedBoundingBox &obb1, SOrientedBoundingBox &obb2);

public:
  double p1x, p1y, p1z;
  double p2x, p2y, p2z;
  double p3x, p3y, p3z;
  double p4x, p4y, p4z;
  double p5x, p5y, p5z;
  double p6x, p6y, p6z;
  double p7x, p7y, p7z;
  double p8x, p8y, p8z;

private:
  void fillp();

private:
  SVector3 center;
  SVector3 size;
  SVector3 axisX;
  SVector3 axisY;
  SVector3 axisZ;
};

#endif
