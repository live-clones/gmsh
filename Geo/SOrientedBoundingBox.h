// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Bastien Gorissen

#ifndef ORIENTEDBOUNDINGBOX_H
#define ORIENTEDBOUNDINGBOX_H

#include "SVector3.h"
#
#include "SPoint2.h"
#include "Pair.h"
#include <vector>
#include <list>

using namespace std;

class SOrientedBoundingRectangle {
  
  public:
    vector<double>* center;
    vector<double>* size;
    vector<double>* axisX;
    vector<double>* axisY;
  
    SOrientedBoundingRectangle();
    ~SOrientedBoundingRectangle();
    double area();
};


class SOrientedBoundingBox {

  public:
  
    double p1x,p1y,p1z;
    double p2x,p2y,p2z;
    double p3x,p3y,p3z;
    double p4x,p4y,p4z;
    double p5x,p5y,p5z;
    double p6x,p6y,p6z;
    double p7x,p7y,p7z;
    double p8x,p8y,p8z;
    
    SOrientedBoundingBox();
    /*
     * x, y, z are the box center, whereas the sizes are in the local axis
     * system of the box. The axis form the local coordinates system of the
     * box. All these data are given in the local coordinates system of the
     * object.
     */
    SOrientedBoundingBox(SVector3& center,
                        double sizeX,
                        double sizeY,
                        double sizeZ,
                        const SVector3& axisX,
                        const SVector3& axisY,
                        const SVector3& axisZ);

    ~SOrientedBoundingBox();

    SVector3 getCenter()  {return (this->center);};
    double  getCenterX() {return (this->center[0]);};
    double  getCenterY() {return (this->center[1]);};
    double  getCenterZ() {return (this->center[2]);};
    SVector3 getSize()    {return (this->size);};
    double  getMaxSize();

    /*
     * Valid values for axis are 0 (X-axis), 1 (Y-axis) or 2 (Z-axis)
     */
    SVector3 getAxis(int axis);

    static SOrientedBoundingBox* buildOBB(vector<SPoint3> vertices);

    bool intersects(SOrientedBoundingBox* obb);

    static double compare(SOrientedBoundingBox* obb1, SOrientedBoundingBox* obb2);

  private:
    SVector3 center;
    SVector3 size;
    SVector3 axisX;
    SVector3 axisY;
    SVector3 axisZ;
};
#endif
