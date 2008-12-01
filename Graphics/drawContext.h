// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DRAW_CONTEXT_H_
#define _DRAW_CONTEXT_H_

#include "SBoundingBox3d.h"

class drawTransform {
 public:
  drawTransform(){}
  virtual ~drawTransform(){}
  virtual void transform(double &x, double &y, double &z){}
};

class drawTransformScaled : public drawTransform {
 private:
  bool _identityTransform;
  double _mat[3][3];
 public:
  drawTransformScaled(double mat[3][3]) : drawTransform()
  {
    if(mat[0][0] != 1. || mat[0][1] != 0. || mat[0][2] != 0. ||
       mat[1][0] != 0. || mat[1][1] != 1. || mat[1][2] != 0. ||
       mat[2][0] != 0. || mat[2][1] != 0. || mat[2][2] != 1.)
      _identityTransform = false;
    else
      _identityTransform = true;
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        _mat[i][j] = mat[i][j];
  }
  virtual void transform(double &x, double &y, double &z)
  {
    if(_identityTransform) return;
    double xyz[3] = {x, y, z};
    x = y = z = 0.;
    for(int k = 0; k < 3; k++){
      x += _mat[0][k] * xyz[k];
      y += _mat[1][k] * xyz[k];
      z += _mat[2][k] * xyz[k];
    }
  }
};

class drawContext {
 private:
  drawTransform *_transform;

 public:
  double r[3]; // current Euler angles (in degrees!) 
  double t[3], s[3]; // current translation and scale 
  double quaternion[4]; // current quaternion used for "trackball" rotation
  int viewport[4]; // current viewport 
  double rot[16]; // current rotation matrix 
  double t_init[3]; // initial translation before applying modelview transform
  double vxmin, vxmax, vymin, vymax; // current viewport in real coordinates 
  double pixel_equiv_x, pixel_equiv_y; // approx equiv model length of a pixel 
  double model[16], proj[16]; // the modelview and projection matrix as they were
                              // at the time of the last InitPosition() call
  enum RenderMode {GMSH_RENDER=1, GMSH_SELECT=2, GMSH_FEEDBACK=3};
  int render_mode; // current rendering mode

 public:
  drawContext(drawTransform *transform=0);
  virtual ~drawContext(){}
  void setTransform(drawTransform *transform){ _transform = transform; }
  drawTransform *getTransform(){ return _transform; }
  void transform(double &x, double &y, double &z)
  {
    if(_transform) _transform->transform(x, y, z); 
  }
  void buildRotationMatrix();
  void setQuaternion(double p1x, double p1y, double p2x, double p2y);
  void addQuaternion(double p1x, double p1y, double p2x, double p2y);
  void addQuaternionFromAxisAndAngle(double axis[3], double angle);
  void setQuaternionFromEulerAngles();
  void setEulerAnglesFromRotationMatrix();
  void initProjection(int xpick=0, int ypick=0, int wpick=0, int hpick=0);
  void initRenderModel();
  void initPosition();
  void unproject(double x, double y, double p[3], double d[3]);
  int fix2dCoordinates(double *x, double *y);
  void draw3d();
  void draw2d();
  void drawGeom();
  void drawMesh();
  void drawPost();
  void drawText2d();
  void drawGraph2d();
  void drawAxis(double xmin, double ymin, double zmin,
                double xmax, double ymax, double zmax, 
                int nticks, int mikado);
  void drawAxes(int mode, int tics[3], char format[3][256],
                char label[3][256], double bb[6], int mikado);
  void drawAxes(int mode, int tics[3], char format[3][256], 
                char label[3][256], SBoundingBox3d &bb, int mikado);
  void drawAxes();
  void drawSmallAxes();
  void drawScales();
  void drawSphere(double size, double x, double y, double z, int light);
  void drawCylinder(double width, double *x, double *y, double *z, int light);
  void drawTaperedCylinder(double width, double val1, double val2, 
                           double ValMin, double ValMax, 
                           double *x, double *y, double *z, int light);
  void drawVector(int Type, int Fill,
                  double relHeadRadius, double relStemLength,
                  double relStemRadius, double x, double y, double z,
                  double dx, double dy, double dz, int light);
  void drawBox(double xmin, double ymin, double zmin,
               double xmax, double ymax, double zmax,
               bool labels=true);
  void drawPlaneInBoundingBox(double xmin, double ymin, double zmin,
                              double xmax, double ymax, double zmax,
                              double a, double b, double c, double d,
                              int shade=0);
};

#endif
