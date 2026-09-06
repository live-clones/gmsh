// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>

#include "glImmediate.h"
#include "glMatrix.h"
#include "glShader.h"
#include "drawContext.h"
#include "Context.h"

bool gmshCollecting = false;

bool gmshUseShaders()
{
  return CTX::instance()->shaders && glShader::available();
}

namespace {
  // The vertices of the primitive being collected, with the colour and the
  // normal that were current at each of them. A shader pipeline has no
  // immediate mode: the run between gmshBegin() and gmshEnd() is gathered here
  // and drawn in one call.
  std::vector<float> _imPos, _imNrm;
  std::vector<unsigned char> _imCol;
  float _imNormal[3] = {0.f, 0.f, 1.f};
  GLenum _imMode = GL_POINTS;
  bool _imQuads = false, _imPolygon = false;
} // namespace

namespace {
  // The pieces of state that a shader is handed as uniforms, and that a core
  // profile therefore cannot be asked for. They are remembered here as they
  // are set, and are what glShader is given before a draw.
  unsigned char _color[4] = {255, 255, 255, 255};
  bool _lighting = false, _twoSide = false;
  double _pointSize = 1.;
  double _clipPlane[6][4] = {{0.}}, _clipEye[6][4] = {{0.}};
  bool _clipOn[6] = {false, false, false, false, false, false};
} // namespace

void gmshColor4ub(unsigned char r, unsigned char g, unsigned char b,
                  unsigned char a)
{
  _color[0] = r;
  _color[1] = g;
  _color[2] = b;
  _color[3] = a;
  // a core profile has no current colour: the shader is handed the one above
  if(!gmshUseShaders()) glColor4ub(r, g, b, a);
}

const unsigned char *gmshCurrentColor() { return _color; }

void gmshColor4ubv(const void *col)
{
  if(drawContext::pickColorActive()) return;
  const GLubyte *c = (const GLubyte *)col;
  gmshColor4ub(c[0], c[1], c[2], c[3]);
}

void gmshLighting(bool on)
{
  _lighting = on;
  if(gmshUseShaders()) return;
  if(on)
    glEnable(GL_LIGHTING);
  else
    glDisable(GL_LIGHTING);
}

bool gmshLightingEnabled() { return _lighting; }

void gmshLightTwoSide(bool on)
{
  _twoSide = on;
  if(gmshUseShaders()) return;
  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, on ? GL_TRUE : GL_FALSE);
}

bool gmshLightTwoSideEnabled() { return _twoSide; }

void gmshPointSize(double s)
{
  _pointSize = s;
  // the shader writes gl_PointSize instead
  if(!gmshUseShaders()) glPointSize((float)s);
}

double gmshCurrentPointSize() { return _pointSize; }

void gmshClipPlane(int i, const double plane[4])
{
  if(i < 0 || i > 5) return;
  for(int j = 0; j < 4; j++) _clipPlane[i][j] = plane[j];
  // OpenGL keeps the plane in eye coordinates: the equation is transformed by
  // the inverse of the modelview matrix that is current when it is given,
  // which for a plane - a row vector - is the transpose of that inverse
  double inv[16];
  if(glMatrix::invert(gmshMatrix(GMSH_MODELVIEW), inv)) {
    for(int r = 0; r < 4; r++) {
      double v = 0.;
      for(int c = 0; c < 4; c++) v += inv[4 * r + c] * plane[c];
      _clipEye[i][r] = v;
    }
  }
  else {
    for(int j = 0; j < 4; j++) _clipEye[i][j] = plane[j];
  }
  if(!gmshUseShaders()) glClipPlane((GLenum)(GL_CLIP_PLANE0 + i), plane);
}

void gmshClipPlaneOn(int i, bool on)
{
  if(i < 0 || i > 5) return;
  _clipOn[i] = on;
  if(gmshUseShaders()) return;
  if(on)
    glEnable((GLenum)(GL_CLIP_PLANE0 + i));
  else
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}

bool gmshClipPlaneEnabled(int i)
{
  return (i >= 0 && i <= 5) ? _clipOn[i] : false;
}

const double *gmshClipPlaneEye(int i)
{
  return _clipEye[(i >= 0 && i <= 5) ? i : 0];
}

namespace {
  // one stack per matrix, each holding at least the matrix itself
  class MatrixStack {
  public:
    std::vector<double> m;
    MatrixStack() : m(16) { glMatrix::identity(&m[0]); }
    double *top() { return &m[m.size() - 16]; }
    void push() { m.insert(m.end(), top(), top() + 16); }
    void pop()
    {
      if(m.size() > 16) m.resize(m.size() - 16);
    }
  };
  MatrixStack _stack[2];
  int _mode = GMSH_MODELVIEW;

  // hand the current matrix to OpenGL, which is where the fixed function
  // pipeline reads it
  void _apply(int kind)
  {
    // the shader is handed the matrices as uniforms; a core profile has no
    // matrix stack of its own to load them into
    if(gmshUseShaders()) return;
    glMatrixMode(kind == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
    glLoadMatrixd(_stack[kind].top());
    if(kind != _mode)
      glMatrixMode(_mode == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
  }
} // namespace

void gmshMatrixMode(int kind)
{
  _mode = (kind == GMSH_PROJECTION) ? GMSH_PROJECTION : GMSH_MODELVIEW;
  if(gmshUseShaders()) return;
  glMatrixMode(_mode == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
}

int gmshMatrixMode() { return _mode; }

void gmshPushMatrix() { _stack[_mode].push(); }

void gmshPopMatrix()
{
  _stack[_mode].pop();
  _apply(_mode);
}

void gmshLoadIdentity()
{
  glMatrix::identity(_stack[_mode].top());
  _apply(_mode);
}

void gmshLoadMatrix(const double m[16])
{
  for(int i = 0; i < 16; i++) _stack[_mode].top()[i] = m[i];
  _apply(_mode);
}

void gmshMultMatrix(const double m[16])
{
  double out[16];
  glMatrix::multiply(_stack[_mode].top(), m, out);
  gmshLoadMatrix(out);
}

void gmshTranslate(double x, double y, double z)
{
  double t[16];
  glMatrix::translate(x, y, z, t);
  gmshMultMatrix(t);
}

void gmshScale(double x, double y, double z)
{
  double s[16];
  glMatrix::scale(x, y, z, s);
  gmshMultMatrix(s);
}

void gmshRotate(double angle, double x, double y, double z)
{
  double r[16];
  glMatrix::rotate(angle, x, y, z, r);
  gmshMultMatrix(r);
}

const double *gmshMatrix(int kind)
{
  return _stack[(kind == GMSH_PROJECTION) ? GMSH_PROJECTION : GMSH_MODELVIEW]
    .top();
}

void gmshResetMatrices()
{
  for(int i = 0; i < 4; i++) _color[i] = 255;
  _lighting = _twoSide = false;
  _pointSize = 1.;
  for(int i = 0; i < 6; i++) {
    _clipOn[i] = false;
    for(int j = 0; j < 4; j++) _clipPlane[i][j] = _clipEye[i][j] = 0.;
  }

  for(int i = 0; i < 2; i++) {
    _stack[i].m.resize(16);
    glMatrix::identity(&_stack[i].m[0]);
  }
  _mode = GMSH_MODELVIEW;
}

void gmshPushShaderState()
{
  glShader::setMatrices(gmshMatrix(GMSH_MODELVIEW), gmshMatrix(GMSH_PROJECTION));
  glShader::setLighting(gmshLightingEnabled(), gmshLightTwoSideEnabled());
  glShader::setColor(gmshCurrentColor());
  glShader::setPointSize(gmshCurrentPointSize());
  glShader::setMaterial(CTX::instance()->shine,
                        CTX::instance()->shineExponent);
  for(int i = 0; i < 6; i++) {
    if(gmshClipPlaneEnabled(i))
      glShader::setClipPlane(i, gmshClipPlaneEye(i));
    else
      glShader::setClipPlaneOff(i);
  }
}

bool gmshImBegin(GLenum mode)
{
  if(!gmshUseShaders()) return false;
  gmshCollecting = true;
  _imPos.clear();
  _imNrm.clear();
  _imCol.clear();
  // a core profile has neither quads nor polygons: they are collected as they
  // come and turned into triangles when the primitive ends
  _imQuads = (mode == GL_QUADS);
  _imPolygon = (mode == GL_POLYGON);
  _imMode = (_imQuads || _imPolygon) ? GL_TRIANGLES : mode;
  return true;
}

void gmshImVertex(float x, float y, float z)
{
  _imPos.push_back(x);
  _imPos.push_back(y);
  _imPos.push_back(z);
  for(int i = 0; i < 3; i++) _imNrm.push_back(_imNormal[i]);
  for(int i = 0; i < 4; i++) _imCol.push_back(gmshCurrentColor()[i]);
}

void gmshImNormal(float x, float y, float z)
{
  _imNormal[0] = x;
  _imNormal[1] = y;
  _imNormal[2] = z;
}

namespace {
  // copy vertex i of what has been collected to the end of the arrays it will
  // be drawn from
  void _emit(std::vector<float> &p, std::vector<float> &n,
             std::vector<unsigned char> &c, std::size_t i)
  {
    for(int k = 0; k < 3; k++) p.push_back(_imPos[3 * i + k]);
    for(int k = 0; k < 3; k++) n.push_back(_imNrm[3 * i + k]);
    for(int k = 0; k < 4; k++) c.push_back(_imCol[4 * i + k]);
  }
} // namespace

void gmshImEnd()
{
  gmshCollecting = false;
  std::size_t num = _imPos.size() / 3;
  if(!num) return;

  if(_imQuads || _imPolygon) {
    std::vector<float> p, n;
    std::vector<unsigned char> c;
    if(_imQuads) {
      // each group of four corners becomes two triangles
      for(std::size_t q = 0; q + 3 < num; q += 4) {
        const std::size_t idx[6] = {q, q + 1, q + 2, q, q + 2, q + 3};
        for(int k = 0; k < 6; k++) _emit(p, n, c, idx[k]);
      }
    }
    else {
      // a polygon becomes a fan around its first corner, which is what
      // GL_POLYGON drew and what its convexity allowed
      for(std::size_t t = 1; t + 1 < num; t++) {
        _emit(p, n, c, 0);
        _emit(p, n, c, t);
        _emit(p, n, c, t + 1);
      }
    }
    _imPos.swap(p);
    _imNrm.swap(n);
    _imCol.swap(c);
    num = _imPos.size() / 3;
    if(!num) return;
  }

  if(!glShader::use()) return;
  gmshPushShaderState();
  glShader::drawImmediate(_imMode, &_imPos[0], &_imNrm[0], &_imCol[0],
                          (int)num);
}
