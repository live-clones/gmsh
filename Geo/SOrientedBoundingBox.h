// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Bastien Gorissen
//

#ifndef _ORIENTED_BOUNDING_BOX_H_
#define _ORIENTED_BOUNDING_BOX_H_

#include <vector>
#include <list>
#include "SVector3.h"
#include "SPoint2.h"
#include "Pair.h"

class SOrientedBoundingRectangle {
 public:
  std::vector<double> *center;
  std::vector<double> *size;
  std::vector<double> *axisX;
  std::vector<double> *axisY;
  SOrientedBoundingRectangle();
  ~SOrientedBoundingRectangle();
  double area();
};

class SOrientedBoundingBox {
 private:
  SVector3 center;
  SVector3 size;
  SVector3 axisX;
  SVector3 axisY;
  SVector3 axisZ;

 public:
  double p1x, p1y, p1z;
  double p2x, p2y, p2z;
  double p3x, p3y, p3z;
  double p4x, p4y, p4z;
  double p5x, p5y, p5z;
  double p6x, p6y, p6z;
  double p7x, p7y, p7z;
  double p8x, p8y, p8z;
  SOrientedBoundingBox();

  // x, y, z are the box center, whereas the sizes are in the local
  // axis system of the box. The axis form the local coordinates
  // system of the box. All these data are given in the local
  // coordinates system of the object.
  SOrientedBoundingBox(SVector3& center, double sizeX, double sizeY, 
                       double sizeZ, const SVector3 &axisX, 
                       const SVector3 &axisY, const SVector3 &axisZ);

  SOrientedBoundingBox(SOrientedBoundingBox* other);
  ~SOrientedBoundingBox(){}

  SVector3 getCenter(){ return center; }
  const SVector3 &getCenter() const{ return center; }
  double getCenterX(){ return center[0]; }
  double getCenterY(){ return center[1]; }
  double getCenterZ(){ return center[2]; }
  SVector3 getSize(){ return size; }
  double getMaxSize();

  // valid values for axis are 0 (X-axis), 1 (Y-axis) or 2 (Z-axis)
  SVector3 getAxis(int axis);
  
  static SOrientedBoundingBox* buildOBB(std::vector<SPoint3> vertices);
  
  bool intersects(SOrientedBoundingBox &obb);
  
  static double compare(SOrientedBoundingBox &obb1, SOrientedBoundingBox &obb2);
};

#endif
