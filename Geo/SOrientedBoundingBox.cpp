// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Bastien Gorissen
//

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "SOrientedBoundingBox.h"
#include "fullMatrix.h"
#include "DivideAndConquer.h"
#include "SBoundingBox3d.h"

double SOrientedBoundingRectangle::area()
{
  double b = size->at(0);
  double B = size->at(1);
  return (b*B);
}

SOrientedBoundingRectangle::SOrientedBoundingRectangle()
{
  center = new std::vector<double>(2,0);
  size = new std::vector<double>(2,0);
  axisX = new std::vector<double>(2,0);
  axisY = new std::vector<double>(2,0);
}

SOrientedBoundingRectangle::~SOrientedBoundingRectangle()
{
  delete center;
  delete size;
  delete axisX;
  delete axisY;
}

SOrientedBoundingBox::SOrientedBoundingBox()
{
  center = SVector3();
  size = SVector3();
  axisX = SVector3();
  axisY = SVector3();
  axisZ = SVector3();
}

SOrientedBoundingBox::SOrientedBoundingBox(SVector3 &center_,
                                           double sizeX,
                                           double sizeY,
                                           double sizeZ,
                                           const SVector3 &axisX_,
                                           const SVector3 &axisY_,
                                           const SVector3 &axisZ_)
{
  center = center_;
  size = SVector3(sizeX, sizeY, sizeZ);
  axisX = axisX_;
  axisX.normalize();
  axisY = axisY_;
  axisY.normalize();
  axisZ = axisZ_;
  axisZ.normalize();

  double dx = 0.5 * size[0];
  double dy = 0.5 * size[1];
  double dz = 0.5 * size[2];

  p1x = center[0] - (axisX[0]*dx) - (axisY[0]*dy) - (axisZ[0]*dz);
  p1y = center[1] - (axisX[1]*dx) - (axisY[1]*dy) - (axisZ[1]*dz);
  p1z = center[2] - (axisX[2]*dx) - (axisY[2]*dy) - (axisZ[2]*dz);

  p2x = center[0] + (axisX[0]*dx) - (axisY[0]*dy) - (axisZ[0]*dz);
  p2y = center[1] + (axisX[1]*dx) - (axisY[1]*dy) - (axisZ[1]*dz);
  p2z = center[2] + (axisX[2]*dx) - (axisY[2]*dy) - (axisZ[2]*dz);

  p3x = center[0] - (axisX[0]*dx) + (axisY[0]*dy) - (axisZ[0]*dz);
  p3y = center[1] - (axisX[1]*dx) + (axisY[1]*dy) - (axisZ[1]*dz);
  p3z = center[2] - (axisX[2]*dx) + (axisY[2]*dy) - (axisZ[2]*dz);

  p4x = center[0] + (axisX[0]*dx) + (axisY[0]*dy) - (axisZ[0]*dz);
  p4y = center[1] + (axisX[1]*dx) + (axisY[1]*dy) - (axisZ[1]*dz);
  p4z = center[2] + (axisX[2]*dx) + (axisY[2]*dy) - (axisZ[2]*dz);

  p5x = center[0] - (axisX[0]*dx) - (axisY[0]*dy) + (axisZ[0]*dz);
  p5y = center[1] - (axisX[1]*dx) - (axisY[1]*dy) + (axisZ[1]*dz);
  p5z = center[2] - (axisX[2]*dx) - (axisY[2]*dy) + (axisZ[2]*dz);

  p6x = center[0] + (axisX[0]*dx) - (axisY[0]*dy) + (axisZ[0]*dz);
  p6y = center[1] + (axisX[1]*dx) - (axisY[1]*dy) + (axisZ[1]*dz);
  p6z = center[2] + (axisX[2]*dx) - (axisY[2]*dy) + (axisZ[2]*dz);

  p7x = center[0] - (axisX[0]*dx) + (axisY[0]*dy) + (axisZ[0]*dz);
  p7y = center[1] - (axisX[1]*dx) + (axisY[1]*dy) + (axisZ[1]*dz);
  p7z = center[2] - (axisX[2]*dx) + (axisY[2]*dy) + (axisZ[2]*dz);

  p8x = center[0] + (axisX[0]*dx) + (axisY[0]*dy) + (axisZ[0]*dz);
  p8y = center[1] + (axisX[1]*dx) + (axisY[1]*dy) + (axisZ[1]*dz);
  p8z = center[2] + (axisX[2]*dx) + (axisY[2]*dy) + (axisZ[2]*dz);
}

SOrientedBoundingBox::SOrientedBoundingBox(SOrientedBoundingBox* other)
{
  size = other->getSize();
  axisX = other->getAxis(0);
  axisY = other->getAxis(1);
  axisZ = other->getAxis(2);
  center = other->getCenter();

  double dx = 0.5*size[0];
  double dy = 0.5*size[1];
  double dz = 0.5*size[2];

  p1x = center[0] - (axisX[0]*dx) - (axisY[0]*dy) - (axisZ[0]*dz);
  p1y = center[1] - (axisX[1]*dx) - (axisY[1]*dy) - (axisZ[1]*dz);
  p1z = center[2] - (axisX[2]*dx) - (axisY[2]*dy) - (axisZ[2]*dz);

  p2x = center[0] + (axisX[0]*dx) - (axisY[0]*dy) - (axisZ[0]*dz);
  p2y = center[1] + (axisX[1]*dx) - (axisY[1]*dy) - (axisZ[1]*dz);
  p2z = center[2] + (axisX[2]*dx) - (axisY[2]*dy) - (axisZ[2]*dz);

  p3x = center[0] - (axisX[0]*dx) + (axisY[0]*dy) - (axisZ[0]*dz);
  p3y = center[1] - (axisX[1]*dx) + (axisY[1]*dy) - (axisZ[1]*dz);
  p3z = center[2] - (axisX[2]*dx) + (axisY[2]*dy) - (axisZ[2]*dz);

  p4x = center[0] + (axisX[0]*dx) + (axisY[0]*dy) - (axisZ[0]*dz);
  p4y = center[1] + (axisX[1]*dx) + (axisY[1]*dy) - (axisZ[1]*dz);
  p4z = center[2] + (axisX[2]*dx) + (axisY[2]*dy) - (axisZ[2]*dz);

  p5x = center[0] - (axisX[0]*dx) - (axisY[0]*dy) + (axisZ[0]*dz);
  p5y = center[1] - (axisX[1]*dx) - (axisY[1]*dy) + (axisZ[1]*dz);
  p5z = center[2] - (axisX[2]*dx) - (axisY[2]*dy) + (axisZ[2]*dz);

  p6x = center[0] + (axisX[0]*dx) - (axisY[0]*dy) + (axisZ[0]*dz);
  p6y = center[1] + (axisX[1]*dx) - (axisY[1]*dy) + (axisZ[1]*dz);
  p6z = center[2] + (axisX[2]*dx) - (axisY[2]*dy) + (axisZ[2]*dz);

  p7x = center[0] - (axisX[0]*dx) + (axisY[0]*dy) + (axisZ[0]*dz);
  p7y = center[1] - (axisX[1]*dx) + (axisY[1]*dy) + (axisZ[1]*dz);
  p7z = center[2] - (axisX[2]*dx) + (axisY[2]*dy) + (axisZ[2]*dz);

  p8x = center[0] + (axisX[0]*dx) + (axisY[0]*dy) + (axisZ[0]*dz);
  p8y = center[1] + (axisX[1]*dx) + (axisY[1]*dy) + (axisZ[1]*dz);
  p8z = center[2] + (axisX[2]*dx) + (axisY[2]*dy) + (axisZ[2]*dz);

}

double SOrientedBoundingBox::getMaxSize()
{
  return (std::max(size[0], std::max(size[1], size[2])));
}

double SOrientedBoundingBox::getMinSize()
{
  return (std::min(size[0], std::min(size[1], size[2])));
}

SVector3 SOrientedBoundingBox::getAxis(int axis)
{
  SVector3 ret;
  switch (axis) {
  case 0: ret=axisX; break;
  case 1: ret=axisY; break;
  case 2: ret=axisZ; break;
  }
  return ret;
}

bool SOrientedBoundingBox::intersects(SOrientedBoundingBox& obb)
{
  SVector3 collide_axes[15];
  for (int i = 0; i < 3; i ++) {
    collide_axes[i] = getAxis(i);
    collide_axes[i+3] = obb.getAxis(i);
  }

  SVector3 sizes[2];
  sizes[0] = getSize();
  sizes[1] = obb.getSize();

  for(unsigned int i=0 ; i<3 ; i++) {
    for(unsigned int j=3 ; j<6 ; j++) {
      collide_axes[3*i+j+3] = crossprod(collide_axes[i],collide_axes[j]);
    }
  }
  SVector3 T = obb.getCenter() - getCenter();

  for(unsigned int i=0 ; i<15 ; i++) {
    double val = 0.0;
    for(unsigned int j=0 ; j<6 ; j++) {
      val += 0.5*(sizes[j<3?0:1])(j % 3) * fabs(dot(collide_axes[j],collide_axes[i]));
    }
    if (fabs(dot(collide_axes[i],T )) > val)
      return false;
  }

  return true;
}

SOrientedBoundingBox* SOrientedBoundingBox::buildOBB(std::vector<SPoint3> vertices)
{
  int num_vertices = vertices.size();
  // First organize the data
  fullMatrix<double> data(3,num_vertices);
  int tmp = 0;
  for (int i = 0; i < num_vertices; i++) {
    bool okay = true;
    for (int j = 0; j < tmp; j++) {
      if((data(0,j) == vertices[i].x()) &&
         (data(1,j) == vertices[i].y()) &&
         (data(2,j) == vertices[i].z())) {
        okay = false;
        break;
      }
    }
    if (okay) {
      data(0,tmp) = vertices[i].x();
      data(1,tmp) = vertices[i].y();
      data(2,tmp) = vertices[i].z();
      tmp++;
    }
  }
  num_vertices = tmp;

  // Compute the empirical means
  fullVector<double> mean(3);
  for (int i = 0; i < 3; i++) {
    mean(i) = 0;
    for (int j = 0; j < num_vertices; j++) {
      mean(i) += data(i,j);
    }
    mean(i) /= (double)num_vertices;
  }

  // Get the deviation from the mean
  fullMatrix<double> B(3,num_vertices);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < num_vertices; j++) {
      B(i,j) = data(i,j) - mean(i);
    }
  }

  // Compute the covariance matrix
  fullMatrix<double> covariance(3,3);
  B.mult(B.transpose(), covariance);
  covariance.scale(1./(num_vertices-1));
  /*
  Msg::Debug("Covariance matrix");
  Msg::Debug("%f %f %f", covariance(0,0),covariance(0,1),covariance(0,2) );
  Msg::Debug("%f %f %f", covariance(1,0),covariance(1,1),covariance(1,2) );
  Msg::Debug("%f %f %f", covariance(2,0),covariance(2,1),covariance(2,2) );
  */
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (fabs(covariance(i,j))< 10e-16)
        covariance(i,j) = 0;
    }
  }

  fullMatrix<double> left_eigv(3,3);
  fullMatrix<double> right_eigv(3,3);
  fullVector<double> real_eig(3);
  fullVector<double> img_eig(3);
  covariance.eig(real_eig, img_eig, left_eigv, right_eigv,true);

  // Now, project the data in the new basis.
  fullMatrix<double> projected(3,num_vertices);
  left_eigv.transpose().mult(data,projected);
  // Get the size of the box in the new direction
  fullVector<double> mins(3);
  fullVector<double> maxs(3);
  for (int i = 0; i < 3; i++) {
    mins(i) = DBL_MAX;
    maxs(i) = -DBL_MAX;
    for (int j = 0; j < num_vertices; j++) {
      maxs(i) =std::max(maxs(i),projected(i,j));
      mins(i) = std::min(mins(i),projected(i,j));
    }
  }

  double means[3];
  double sizes[3];

  // Note:  the size is computed in the box's coordinates!
  for(int i = 0 ; i < 3 ; i++) {
    sizes[i] = maxs(i) - mins(i);
    means[i] = (maxs(i) - mins(i)) / 2.;
  }
  /*
  Msg::Debug("Sizes : %f %f %f",sizes[0],sizes[1], sizes[2]);
  Msg::Debug("Eig Axis 1 : %f %f %f",left_eigv(0,0),left_eigv(1,0), left_eigv(2,0));
  Msg::Debug("Eig Axis 2 : %f %f %f",left_eigv(0,1),left_eigv(1,1), left_eigv(2,1));
  Msg::Debug("Eig Axis 3 : %f %f %f",left_eigv(0,2),left_eigv(1,2), left_eigv(2,2));
  */
  // We take the smallest component, then project the data on the plane defined by the other twos

  int smallest_comp = 0;
  if (sizes[0] <= sizes[1] && sizes[0] <= sizes[2])
    smallest_comp = 0;
  else if (sizes[1] <= sizes[0] && sizes[1] <= sizes[2])
    smallest_comp = 1;
  else if (sizes[2] <= sizes[0] && sizes[2] <= sizes[1])
    smallest_comp = 2;

  // The projection has been done circa line 161.
  // We just ignore the coordinate corresponding to smallest_comp.
  std::vector<SPoint2*> points;
  for (int i = 0; i < num_vertices; i++) {
    SPoint2* p = new SPoint2(projected(smallest_comp==0?1:0,i), projected(smallest_comp==2?1:2,i));
    bool keep = true;
    for (std::vector<SPoint2*>::iterator point = points.begin();point != points.end();point++) {
      if ( fabs((*p)[0] -(**point)[0]) < 10e-10 && fabs((*p)[1] -(**point)[1]) < 10e-10 ) {
        keep = false;
        break;
      }
    }
    if (keep) {
      points.push_back(p);
    } else {
      delete p;
    }
  }

  // Find the convex hull from a delaunay triangulation of the points
  DocRecord record(points.size());
  record.numPoints = points.size();
  srand((unsigned)time(0));
  for (unsigned int i = 0; i < points.size(); i++) {
    record.points[i].where.h = points[i]->x()+(10e-6)*sizes[smallest_comp==0?1:0]*(-0.5+((double)rand())/RAND_MAX);
    record.points[i].where.v = points[i]->y()+(10e-6)*sizes[smallest_comp==2?1:0]*(-0.5+((double)rand())/RAND_MAX);
    record.points[i].adjacent = NULL;
    //Msg::Info("Points for delaunay : %f %f",record.points[i].where.h,record.points[i].where.v);
  }

  record.MakeMeshWithPoints();

  std::vector<Segment> convex_hull;
  for (int i = 0; i < record.numTriangles; i++) {
    Segment segs[3];
    segs[0].from = record.triangles[i].a;
    segs[0].to = record.triangles[i].b;
    segs[1].from = record.triangles[i].b;
    segs[1].to = record.triangles[i].c;
    segs[2].from = record.triangles[i].c;
    segs[2].to = record.triangles[i].a;

    for (int j = 0; j < 3; j++) {
      bool okay = true;
      for (std::vector<Segment>::iterator seg = convex_hull.begin(); seg != convex_hull.end(); seg++) {
        if ( ((*seg).from == segs[j].from && (*seg).from == segs[j].to) ||  ((*seg).from == segs[j].to && (*seg).from == segs[j].from)) {
          convex_hull.erase(seg);
          okay = false;
          break;
        }
      }
      if (okay) {
        convex_hull.push_back(segs[j]);
      }
    }
  }

  // Now, examinate all the directions given by the edges of the convex hull
  // to find the one that lets us build the least-area bounding rectangle for then
  // points.
  fullVector<double> axis(2);
  axis(0) = 1;
  axis(1) = 0;
  fullVector<double> axis2(2);
  axis2(0) = 0;
  axis2(1) = 1;
  SOrientedBoundingRectangle least_rectangle;
  least_rectangle.center->at(0) = 0.0;
  least_rectangle.center->at(1) = 0.0;
  least_rectangle.size->at(0) = -1;
  least_rectangle.size->at(1) = 1;

  for (std::vector<Segment>::iterator seg = convex_hull.begin(); seg != convex_hull.end(); seg++) {

    fullVector<double> segment(2);
    //segment(0) = record.points[(*seg).from].where.h - record.points[(*seg).to].where.h;
    //segment(1) = record.points[(*seg).from].where.v - record.points[(*seg).to].where.v;
    segment(0) = points[(*seg).from]->x() - points[(*seg).to]->x();
    segment(1) = points[(*seg).from]->y() - points[(*seg).to]->y();
    segment.scale(1.0/segment.norm());

    double cosine = axis(0)*segment(0) + segment(1)*axis(1);
    double sine = axis(1)*segment(0) - segment(1)*axis(0);
    //double sine = axis(0)*segment(1) - segment(0)*axis(1);

    fullMatrix<double> rotation(2,2);

    rotation(0,0) = cosine; rotation(0,1) =   sine;
    rotation(1,0) =  -sine; rotation(1,1) = cosine;

    double max_x = -DBL_MAX;
    double min_x = DBL_MAX;
    double max_y = -DBL_MAX;
    double min_y = DBL_MAX;

    for (int i = 0; i < record.numPoints; i++) {
      fullVector<double> pnt(2);
      //pnt(0) = record.points[i].where.h;
      //pnt(1) = record.points[i].where.v;
      pnt(0) = points[i]->x();
      pnt(1) = points[i]->y();
      fullVector<double> rot_pnt(2);
      rotation.mult(pnt,rot_pnt);
      if (rot_pnt(0) < min_x) min_x = rot_pnt(0);
      if (rot_pnt(0) > max_x) max_x = rot_pnt(0);
      if (rot_pnt(1) < min_y) min_y = rot_pnt(1);
      if (rot_pnt(1) > max_y) max_y = rot_pnt(1);
    }

/**/
    fullVector<double> center_rot(2);
    fullVector<double> center_before_rot(2);
    center_before_rot(0) = (max_x+min_x)/2.0;
    center_before_rot(1) = (max_y+min_y)/2.0;
    fullMatrix<double> rotation_inv(2,2);

    rotation_inv(0,0) = cosine; rotation_inv(0,1) =  -sine;
    rotation_inv(1,0) =   sine; rotation_inv(1,1) = cosine;

    rotation_inv.mult(center_before_rot,center_rot);

    fullVector<double> axis_rot1(2);
    fullVector<double> axis_rot2(2);

    rotation_inv.mult(axis,axis_rot1);
    rotation_inv.mult(axis2,axis_rot2);
//*/

    if ((least_rectangle.area() == -1) || (max_x-min_x)*(max_y-min_y) < least_rectangle.area()) {

      least_rectangle.size->at(0) = max_x-min_x;
      least_rectangle.size->at(1) = max_y-min_y;
      least_rectangle.center->at(0) = (max_x+min_x)/2.0;
      least_rectangle.center->at(1) = (max_y+min_y)/2.0;
      least_rectangle.center->at(0) = center_rot(0);
      least_rectangle.center->at(1) = center_rot(1);
      least_rectangle.axisX->at(0) = axis_rot1(0);
      least_rectangle.axisX->at(1) = axis_rot1(1);
//      least_rectangle.axisX->at(0) = segment(0);
//      least_rectangle.axisX->at(1) = segment(1);
      least_rectangle.axisY->at(0) = axis_rot2(0);
      least_rectangle.axisY->at(1) = axis_rot2(1);
    }
  }

  double min_pca = DBL_MAX;
  double max_pca = -DBL_MAX;
  for (int i = 0; i < num_vertices; i++) {
    min_pca = std::min(min_pca,projected(smallest_comp,i));
    max_pca = std::max(max_pca,projected(smallest_comp,i));
  }
  double center_pca = (max_pca+min_pca)/2.0;
  double size_pca = (max_pca-min_pca);

  double raw_data[3][5];
  raw_data[0][0] = size_pca;
  raw_data[1][0] = least_rectangle.size->at(0);
  raw_data[2][0] = least_rectangle.size->at(1);

  raw_data[0][1] = center_pca;
  raw_data[1][1] = least_rectangle.center->at(0);
  raw_data[2][1] = least_rectangle.center->at(1);

  for (int i = 0; i < 3; i++) {
    raw_data[0][2+i] = left_eigv(i,smallest_comp);
    raw_data[1][2+i] = least_rectangle.axisX->at(0)*left_eigv(i,smallest_comp==0?1:0) +
                       least_rectangle.axisX->at(1)*left_eigv(i,smallest_comp==2?1:2);
    raw_data[2][2+i] = least_rectangle.axisY->at(0)*left_eigv(i,smallest_comp==0?1:0) +
                       least_rectangle.axisY->at(1)*left_eigv(i,smallest_comp==2?1:2);
  }
  //  Msg::Info("Test 1 : %f %f",least_rectangle.center->at(0),least_rectangle.center->at(1));
//  Msg::Info("Test 2 : %f %f",least_rectangle.axisY->at(0),least_rectangle.axisY->at(1));

  int tri[3];

  if (size_pca > least_rectangle.size->at(0)) {  // P > R0
    if (size_pca > least_rectangle.size->at(1)) { // P > R1
      tri[0] = 0;
      if (least_rectangle.size->at(0) > least_rectangle.size->at(1)) { // R0 > R1
        tri[1] = 1;
        tri[2] = 2;
      } else { // R1 > R0
        tri[1] = 2;
        tri[2] = 1;
      }
    } else { // P < R1
      tri[0] = 2;
      tri[1] = 0;
      tri[2] = 1;
    }
  } else { // P < R0
    if (size_pca < least_rectangle.size->at(1)) {  // P < R1
      tri[2] = 0;
      if (least_rectangle.size->at(0) > least_rectangle.size->at(1)) {
        tri[0] = 1;
        tri[1] = 2;
      } else {
        tri[0] = 2;
        tri[1] = 1;
      }
    } else {
      tri[0] = 1;
      tri[1] = 0;
      tri[2] = 2;
    }
  }

  SVector3 size;
  SVector3 center;
  SVector3 Axis1;
  SVector3 Axis2;
  SVector3 Axis3;

  for (int i = 0; i < 3; i++) {
    size[i] = raw_data[tri[i]][0];
    center[i] = raw_data[tri[i]][1];
    Axis1[i] = raw_data[tri[0]][2+i];
    Axis2[i] = raw_data[tri[1]][2+i];
    Axis3[i] = raw_data[tri[2]][2+i];
  }

  SVector3 aux1;
  SVector3 aux2;
  SVector3 aux3;
  for (int i = 0; i < 3; i++) {
    aux1(i) = left_eigv(i,smallest_comp);
    aux2(i) = left_eigv(i,smallest_comp==0?1:0);
    aux3(i) = left_eigv(i,smallest_comp==2?1:2);
  }
  center = aux1*center_pca + aux2*least_rectangle.center->at(0) + aux3*least_rectangle.center->at(1);
  //center[1] = -center[1];

  /*
  Msg::Info("Box center : %f %f %f",center[0],center[1],center[2]);
  Msg::Info("Box size : %f %f %f",size[0],size[1],size[2]);
  Msg::Info("Box axis 1 : %f %f %f",Axis1[0],Axis1[1],Axis1[2]);
  Msg::Info("Box axis 2 : %f %f %f",Axis2[0],Axis2[1],Axis2[2]);
  Msg::Info("Box axis 3 : %f %f %f",Axis3[0],Axis3[1],Axis3[2]);
  
  Msg::Info("Volume : %f", size[0]*size[1]*size[2]);
  */
  return (new SOrientedBoundingBox(center,
          size[0], size[1], size[2], Axis1, Axis2, Axis3));
}

double SOrientedBoundingBox::compare(SOrientedBoundingBox& obb1, SOrientedBoundingBox& obb2)
{
  // "center term"
  double center_term = norm(obb1.getCenter() - obb2.getCenter());

  // "size term"
  double size_term = 0.0;
  for (int i = 0; i < 3; i++) {
    if ((obb1.getSize())(i) + (obb2.getSize())(i) != 0) {
      size_term += fabs((obb1.getSize())(i) - (obb2.getSize())(i)) / ((obb1.getSize())(i) + (obb2.getSize())(i));
    }
  }

  // "orientation term"
  double orientation_term = 0.0;
  for (int i = 0; i < 3; i++) {
    orientation_term += 1 - fabs(dot(obb1.getAxis(i),obb2.getAxis(i)));
  }

  return (center_term + size_term + orientation_term);

}
