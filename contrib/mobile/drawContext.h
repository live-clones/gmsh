#ifndef ONELAB_DRAW_CONTEXT_H
#define ONELAB_DRAW_CONTEXT_H

#include <string>

#include <gmsh/PView.h>
#include <gmsh/PViewOptions.h>

class movePosition {
public:
  float win[3]; // window coordinates
  float wnr[3]; // world coordinates BEFORE rotation
  float s[3]; // scaling state when the event was recorded
  float t[3]; // translation state when the event was recorded
  movePosition()
  {
    for(int i = 0; i < 3; i++) win[i] = wnr[i] = s[i] = t[i] = 0.;
  }
  movePosition(const movePosition &instance)
  {
    for(int i = 0; i < 3; i++) {
      win[i] = instance.win[i];
      wnr[i] = instance.wnr[i];
      s[i] = instance.s[i];
      t[i] = instance.t[i];
    }
  }
  void set(float scale[3], float translate[3], float vxmax, float vxmin,
           float vymin, float vymax, int width, int height, int x, int y)
  {
    for(int i = 0; i < 3; i++) {
      s[i] = scale[i];
      t[i] = translate[i];
    }
    win[0] = (float)x;
    win[1] = (float)y;
    win[2] = 0.;

    wnr[0] = (vxmin + win[0] / (float)width * (vxmax - vxmin)) / scale[0] -
             translate[0];
    wnr[1] = (vymax - win[1] / (float)height * (vymax - vymin)) / scale[1] -
             translate[1];
    wnr[2] = 0.;
  }
  void recenter(float scale[3], float translate[3]) const
  {
    // compute the equivalent translation to apply *after* the scaling so that
    // the scaling is done around the point which was clicked:
    translate[0] = t[0] * (s[0] / scale[0]) - wnr[0] * (1. - (s[0] / scale[0]));
    translate[1] = t[1] * (s[1] / scale[1]) - wnr[1] * (1. - (s[1] / scale[1]));
  }
};

class drawContext {
private:
  float _translate[3], _scale[3]; // current translation and scale
  double _rotate[16]; // current rotation matrix (double for Trackball)
  float _rotatef[16]; // current rotation matrix (float for OpenGL ES)
  double _quaternion[4]; // current quaternion used for rotation
  movePosition _start, _previous,
    _current; // store informations about user interactions
  int _width, _height; // size of OpenGL context in pixel
  float _left, _right, _top, _bottom, _far; // value of "border"
  float _fontFactor;
  bool _retina; // retina display
  double _pixel_equiv_x, _pixel_equiv_y;

  void OrthofFromGModel(void);
  void drawPView(PView *p);
  void drawVectorArray(PViewOptions *opt, VertexArray *va);

public:
  drawContext(float fontFactor = 1., bool retina = false);
  ~drawContext() {}
  void load(std::string filename);
  void eventHandler(int event, float x = 0, float y = 0);
  void setQuaternion(double q0, double q1, double q2, double q3);
  void addQuaternion(double p1x, double p1y, double p2x, double p2y);
  void buildRotationMatrix();
  void setTranslate(int i, float t)
  {
    if(i >= 0 && i < 3) _translate[i] = t;
  }
  float getTranslate(int i)
  {
    if(i >= 0 && i < 3) return _translate[i];
    return 0;
  }
  void setScale(int i, float s)
  {
    if(i >= 0 && i < 3) _scale[i] = s;
  }
  float getScale(int i)
  {
    if(i >= 0 && i < 3) return _scale[i];
    return 0;
  }
  void initView(int w, int h);
  int fix2dCoordinates(double *x, double *y);
  void drawView();
  void drawAxes();
  void drawAxes(int mode, double tics[3], std::string format[3],
                std::string label[3], double bb[6], int mikado,
                double value_bb[6]);
  int drawTics(drawContext *ctx, int comp, double n, std::string &format,
               std::string &label, double p1[3], double p2[3], double perp[3],
               int mikado, double pixelfact, double value_p1[3],
               double value_p2[3]);
  void drawSmallAxes();
  void drawGeom();
  void drawMesh();
  void drawPost();
  void drawScale();
  void drawText2d();
};

void drawArray(VertexArray *va, int type, bool useColorArray = false,
               bool useNormalArray = false);
int onelab_cb(std::string);
int animation_next();
int animation_prev();
int number_of_animation();
void set_animation(int step);

#endif
