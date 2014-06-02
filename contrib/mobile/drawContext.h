#ifndef _DRAW_GMODEL_H_
#define _DRAW_GMODEL_H_

#include <string>

#include <gmsh/PView.h>
#include <gmsh/PViewOptions.h>

#include "movePosition.h"

class drawContext{
private:
  float _translate[3], _scale[3]; // current translation and scale
  double _rotate[16]; // current rotation matrix (double for Trackball)
  float _rotatef[16]; // current rotation matrix (float for OpenGL ES)
  double _quaternion[4]; // current quaternion used for rotation
  movePosition _start, _previous, _current; // store informations about user interactions
  int _width, _height; // size of OpenGL context in pixel
  float _left, _right, _top, _bottom, _far; // value of "border"
  float _fontFactor;
  bool _retina; // retina display

  void OrthofFromGModel(void);
  void drawPView(PView *p);
  void drawVectorArray(PViewOptions *opt, VertexArray *va);
public:
  drawContext(float fontFactor=1., bool retina=false);
  ~drawContext(){}
  void load(std::string filename);
  void eventHandler(int event, float x=0, float y=0);
  void setQuaternion(double q0, double q1, double q2, double q3);
  void addQuaternion(double p1x, double p1y, double p2x, double p2y);
  void buildRotationMatrix();
  void setTranslate(int i, float t) {if(i>=0 && i<3) _translate[i] = t;}
  float getTranslate(int i) {if(i>=0 && i<3) return _translate[i]; return 0;}
  void setScale(int i, float s) {if(i>=0 && i<3) _scale[i] = s;}
  float getScale(int i) {if(i>=0 && i<3) return _scale[i]; return 0;}
  void initView(int w, int h);
  void drawView();
  void drawAxes(float x0=0., float y0=0., float z0=0., float h=0.5);
  void drawGeom();
  void drawMesh();
  void drawPost();
  void drawScale();
};

void drawArray(VertexArray *va, int type, bool useColorArray=false,
               bool useNormalArray=false);
int onelab_cb(std::string);
int animation_next();
int animation_prev();
int number_of_animation();
void set_animation(int step);

#endif
