// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DRAW_CONTEXT_H_
#define _DRAW_CONTEXT_H_

#include <string>
#include <vector>
#include <set>
#include "SBoundingBox3d.h"
#include "Camera.h"

#if defined(WIN32)
#include <windows.h>
#undef min
#undef max
#endif

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class PView;
class GModel;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

class drawTransform {
 public:
  drawTransform(){}
  virtual ~drawTransform(){}
  virtual void transform(double &x, double &y, double &z){}
  virtual void transformOneForm(double &x, double &y, double &z){}
  virtual void transformTwoForm(double &x, double &y, double &z){}
  virtual void setMatrix(double mat[3][3], double tra[3]){}
};

class drawTransformScaled : public drawTransform {
 private:
  double _mat[3][3];
  double _tra[3];

 public:
  drawTransformScaled(double mat[3][3], double tra[3]=0)
    : drawTransform()
  {
    setMatrix(mat, tra);
  }
  virtual void setMatrix(double mat[3][3], double tra[3]=0)
  {
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++)
        _mat[i][j] = mat[i][j];
      if(tra) _tra[i] = tra[i];
      else _tra[i] = 0.;
    }
  }
  virtual void transform(double &x, double &y, double &z)
  {
    double xyz[3] = {x, y, z};
    x = y = z = 0.;
    for(int k = 0; k < 3; k++){
      x += _mat[0][k] * xyz[k];
      y += _mat[1][k] * xyz[k];
      z += _mat[2][k] * xyz[k];
    }
    x += _tra[0];
    y += _tra[1];
    z += _tra[2];
  }
};

// global drawing functions, which need to be redefined for each
// widget toolkit (FLTK, Qt, etc.)
class drawContextGlobal {
 public:
  drawContextGlobal(){}
  virtual ~drawContextGlobal(){}
  virtual void draw(){}
  virtual void drawCurrentOpenglWindow(bool make_current){}
  virtual int getFontIndex(const char *fontname){ return 0; }
  virtual int getFontEnum(int index){ return 0; }
  virtual const char *getFontName(int index){ return "Helvetica"; }
  virtual int getFontAlign(const char *alignstr){ return 0; }
  virtual int getFontSize(){ return 12; }
  virtual void setFont(int fontid, int fontsize){}
  virtual double getStringWidth(const char *str){ return 1.; }
  virtual int getStringHeight(){ return 12; }
  virtual int getStringDescent(){ return 3; }
  virtual void drawString(const char *str){}
  virtual void resetFontTextures(){}
};

class drawContext {
 private:
  static drawContextGlobal *_global;
  drawTransform *_transform;
  GLUquadricObj *_quadric;
  GLuint _displayLists;
  std::set<GModel*> _hiddenModels;
  std::set<PView*> _hiddenViews;
  std::vector<GLfloat> _bgImage;
  int _bgImageSize[2];

 public:
  Camera camera;
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
  ~drawContext();
  static void setGlobal(drawContextGlobal *global){ _global = global; }
  static drawContextGlobal *global();
  void setTransform(drawTransform *transform){ _transform = transform; }
  drawTransform *getTransform(){ return _transform; }
  void transform(double &x, double &y, double &z)
  {
    if(_transform) _transform->transform(x, y, z);
  }
  void transformOneForm(double &x, double &y, double &z)
  {
    if(_transform) _transform->transformOneForm(x, y, z);
  }
  void transformTwoForm(double &x, double &y, double &z)
  {
    if(_transform) _transform->transformTwoForm(x, y, z);
  }
  void hide(GModel *m){ _hiddenModels.insert(m); }
  void hide(PView *v){ _hiddenViews.insert(v); }
  void show(GModel *m)
  {
    std::set<GModel*>::iterator it = _hiddenModels.find(m);
    if(it != _hiddenModels.end()) _hiddenModels.erase(it);
  }
  void show(PView *v)
  {
    std::set<PView*>::iterator it = _hiddenViews.find(v);
    if(it != _hiddenViews.end()) _hiddenViews.erase(it);
  }
  void showAll(){ _hiddenModels.clear(); _hiddenViews.clear(); }
  bool isVisible(GModel *m){ return (_hiddenModels.find(m) == _hiddenModels.end()); }
  bool isVisible(PView *v){ return (_hiddenViews.find(v) == _hiddenViews.end()); }
  void createQuadricsAndDisplayLists();
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
  void viewport2World(double win[3], double xyz[3]);
  void world2Viewport(double xyz[3], double win[3]);
  bool select(int type, bool multiple, bool mesh, int x, int y, int w, int h,
              std::vector<GVertex*> &vertices, std::vector<GEdge*> &edges,
              std::vector<GFace*> &faces, std::vector<GRegion*> &regions,
              std::vector<MElement*> &elements);
  int fix2dCoordinates(double *x, double *y);
  void draw3d();
  void draw2d();
  void drawGeom();
  void drawMesh();
  void drawPost();
  void drawBackgroundGradient();
  void drawBackgroundImage();
  void drawText2d();
  void drawGraph2d();
  void drawAxis(double xmin, double ymin, double zmin,
                double xmax, double ymax, double zmax,
                int nticks, int mikado);
  void drawAxes(int mode, double tics[3], std::string format[3],
                std::string label[3], double bb[6], int mikado, double value_bb[6]);
  void drawAxes(int mode, double tics[3], std::string format[3],
                std::string label[3], SBoundingBox3d &bb, int mikado, SBoundingBox3d &value_bb);
  void drawAxes();
  void drawSmallAxes();
  void drawTrackball();
  void drawScales();
  void drawString(const std::string &s, const std::string &font_name, int font_enum,
                  int font_size, int align);
  void drawString(const std::string &s);
  void drawStringCenter(const std::string &s);
  void drawStringRight(const std::string &s);
  void drawString(const std::string &s, double style);
  void drawSphere(double R, double x, double y, double z, int n1, int n2, int light);
  void drawEllipsoid(double x, double y, double z, float v0[3], float v1[3], float v2[3], int light);
  void drawEllipse(double x, double y, double z, float v0[3], float v1[3], int light);
  void drawSphere(double size, double x, double y, double z, int light);
  void drawCylinder(double width, double *x, double *y, double *z, int light);
  void drawTaperedCylinder(double width, double val1, double val2,
                           double ValMin, double ValMax,
                           double *x, double *y, double *z, int light);
  void drawArrow3d(double x, double y, double z, double dx, double dy, double dz,
                   double length, int light);
  void drawVector(int Type, int Fill, double x, double y, double z,
                  double dx, double dy, double dz, int light);
  void drawBox(double xmin, double ymin, double zmin,
               double xmax, double ymax, double zmax,
               bool labels=true);
  void drawPlaneInBoundingBox(double xmin, double ymin, double zmin,
                              double xmax, double ymax, double zmax,
                              double a, double b, double c, double d,
                              int shade=0);
};

class mousePosition {
 public:
  double win[3]; // window coordinates
  double wnr[3]; // world coordinates BEFORE rotation
  double s[3]; // scaling state when the event was recorded
  double t[3]; // translation state when the event was recorded
  mousePosition()
  {
    for(int i = 0; i < 3; i++)
      win[i] = wnr[i] = s[i] = t[i] = 0.;
  }
  mousePosition(const mousePosition &instance)
  {
    for(int i = 0; i < 3; i++){
      win[i] = instance.win[i];
      wnr[i] = instance.wnr[i];
      s[i] = instance.s[i];
      t[i] = instance.t[i];
    }
  }
  void set(drawContext *ctx, int x, int y)
  {
    for(int i = 0; i < 3; i++){
      s[i] = ctx->s[i];
      t[i] = ctx->t[i];
    }
    win[0] = (double)x;
    win[1] = (double)y;
    win[2] = 0.;

    wnr[0] =
      (ctx->vxmin + win[0] / (double)ctx->viewport[2] * (ctx->vxmax - ctx->vxmin))
      / ctx->s[0] - ctx->t[0] + ctx->t_init[0] / ctx->s[0];
    wnr[1] =
      (ctx->vymax - win[1] / (double)ctx->viewport[3] * (ctx->vymax - ctx->vymin))
      / ctx->s[1] - ctx->t[1] + ctx->t_init[1] / ctx->s[1];
    wnr[2] = 0.;
  }
  void recenter(drawContext *ctx)
  {
    // compute the equivalent translation to apply *after* the scaling
    // so that the scaling is done around the point which was clicked:
    ctx->t[0] = t[0] * (s[0] / ctx->s[0]) - wnr[0] * (1. - (s[0] / ctx->s[0]));
    ctx->t[1] = t[1] * (s[1] / ctx->s[1]) - wnr[1] * (1. - (s[1] / ctx->s[1]));
  }
};

#endif
