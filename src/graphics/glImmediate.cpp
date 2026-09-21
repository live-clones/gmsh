// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>

#include <cmath>
#include "glImmediate.h"
#include "glMatrix.h"
#include "glShader.h"
#include "drawContext.h"
#include "Context.h"
#include "VertexArray.h"

bool gmshCollecting = false;

namespace {
  // A growable array whose appends are a few inline instructions: the
  // primitives collected here come a number at a time, millions to a frame,
  // and std::vector's push_back() is a call of its own in some builds (with
  // the checks of a hardened library), which made most of the cost of
  // drawing a curve or a glyph this way. The storage only grows.
  template <class T> class growBuf {
  private:
    std::vector<T> _v;
    T *_p = nullptr;
    std::size_t _n = 0, _cap = 0;
    // the rare case, kept out of the way of the common one
    void _reserve(std::size_t n)
    {
      _v.resize(std::max(n, 2 * _cap + 64));
      _p = _v.data();
      _cap = _v.size();
    }

  public:
    std::size_t size() const { return _n; }
    bool empty() const { return !_n; }
    void clear() { _n = 0; }
    T &operator[](std::size_t i) { return _p[i]; }
    const T &operator[](std::size_t i) const { return _p[i]; }
    T *data() { return _p; }
    // k more elements at the end, to be written through the pointer
    inline T *grow(std::size_t k)
    {
      if(_n + k > _cap) _reserve(_n + k);
      T *p = _p + _n;
      _n += k;
      return p;
    }
    void push_back(const T &t) { *grow(1) = t; }
    // shrink, or grow with the value given
    void resize(std::size_t n, const T &t = T())
    {
      if(n > _n) {
        std::size_t k = n - _n;
        T *p = grow(k);
        for(std::size_t i = 0; i < k; i++) p[i] = t;
      }
      else
        _n = n;
    }
    // append the whole of another one
    void append(const growBuf<T> &o)
    {
      T *p = grow(o._n);
      std::copy(o._p, o._p + o._n, p);
    }
  };

  // the vertices of the primitive being collected, with the colour and
  // normal current at each of them
  growBuf<float> _imPos, _imNrm, _imTex;
  // how far along its line each vertex of the batch is, in pixels
  growBuf<float> _batchDash;
  growBuf<unsigned char> _imCol;
  float _imNormal[3] = {0.f, 0.f, 1.f};
  float _imTexCoord[2] = {0.f, 0.f};
  GLenum _imMode = GL_POINTS;

  // The collected primitives not drawn yet, turned into points, lines or
  // triangles so that consecutive primitives with the same state go into one
  // draw (the decorations are thousands of two-vertex runs). Anything that
  // changes how they would be drawn flushes them first.
  GLenum _batchMode = GL_POINTS;
  growBuf<float> _batchPos, _batchNrm, _batchTex;
  growBuf<unsigned char> _batchCol;

  // the state the batch is drawn with; setting one of these does not end
  // the batch, only a primitive that does not match does
  struct BatchState {
    double modelview[16], projection[16];
    double clip[6][4];
    bool clipOn[6], clipOutside;
    // the blending, which the callers switch with plain OpenGL calls around
    // the primitives they hand over: it is read back rather than set here
    bool blend;
    GLint blendSrc[2], blendDst[2]; // colour, then alpha
    bool lighting, twoSide;
    double pointSize;
    double alphaScale;
    bool alphaScaleFilledOnly;
    // the texture, zero for none
    unsigned int texture;
  int textureMode;
    // how wide the lines are and what dash pattern they carry
    double lineWidth;
    bool stipple;
    int stippleFactor;
    unsigned short stipplePattern;
    bool operator!=(const BatchState &o) const
    {
      if(blend != o.blend) return true;
      if(blend)
        for(int i = 0; i < 2; i++)
          if(blendSrc[i] != o.blendSrc[i] || blendDst[i] != o.blendDst[i])
            return true;
      if(lighting != o.lighting || twoSide != o.twoSide ||
         clipOutside != o.clipOutside ||
         pointSize != o.pointSize || texture != o.texture ||
         alphaScale != o.alphaScale ||
         alphaScaleFilledOnly != o.alphaScaleFilledOnly ||
         textureMode != o.textureMode ||
         stipple != o.stipple || stippleFactor != o.stippleFactor ||
         stipplePattern != o.stipplePattern || lineWidth != o.lineWidth)
        return true;
      for(int i = 0; i < 16; i++)
        if(modelview[i] != o.modelview[i] || projection[i] != o.projection[i])
          return true;
      for(int i = 0; i < 6; i++) {
        if(clipOn[i] != o.clipOn[i]) return true;
        if(clipOn[i])
          for(int j = 0; j < 4; j++)
            if(clip[i][j] != o.clip[i][j]) return true;
      }
      return false;
    }
  };
  BatchState _batchState;
} // namespace

namespace {
  // the state a shader is handed as uniforms, which a core profile cannot
  // be asked for
  unsigned char _color[4] = {255, 255, 255, 255};
  // recording (gmshRecordBegin()): into which arrays, and the colour to put
  // back afterwards
  bool _recording = false;
  VertexArray *_recTo[3] = {nullptr, nullptr, nullptr};
  unsigned char _recColor[4];
  bool _lighting = false, _twoSide = false;
  double _pointSize = 1.;
  unsigned int _texture = 0;
  double _alphaScale = 1.;
  bool _alphaScaleFilledOnly = false;
  int _textureMode = GMSH_TEXTURE_NONE;
  double _lineWidth = 1.;
  double _pixelScale = 1.;
  bool _stipple = false;
  int _stippleFactor = 1;
  unsigned short _stipplePattern = 0xffff;
  double _clipPlane[6][4] = {{0.}}, _clipEye[6][4] = {{0.}};
  bool _clipOn[6] = {false, false, false, false, false, false};
  bool _clipOutside = false;
} // namespace

void gmshColor4ub(unsigned char r, unsigned char g, unsigned char b,
                  unsigned char a)
{
  _color[0] = r;
  _color[1] = g;
  _color[2] = b;
  _color[3] = a;
  // a core profile has no current colour: the shader is handed the one above
  if(!glShader::enabled()) glColor4ub(r, g, b, a);
}

const unsigned char *gmshCurrentColor() { return _color; }

void gmshColor4ubv(const void *col)
{
  if(drawContext::pickColorActive() && !_recording) return;
  const GLubyte *c = (const GLubyte *)col;
  gmshColor4ub(c[0], c[1], c[2], c[3]);
}

void gmshLighting(bool on)
{
  // A picking pass writes identifiers as colours: shading one would spread
  // it over the identifiers around it, so a lit glyph came back as a
  // handful of other entities, or as the background. Colours are ignored
  // there for the same reason (see gmshColor4ubv).
  if(on && drawContext::pickColorActive()) on = false;
  _lighting = on;
  if(glShader::enabled()) return;
  if(on)
    glEnable(GL_LIGHTING);
  else
    glDisable(GL_LIGHTING);
}

bool gmshLightingEnabled() { return _lighting; }

void gmshLightTwoSide(bool on)
{
  _twoSide = on;
  if(glShader::enabled()) return;
  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, on ? GL_TRUE : GL_FALSE);
}

bool gmshLightTwoSideEnabled() { return _twoSide; }

void gmshPixelScale(double scale) { _pixelScale = (scale > 0.) ? scale : 1.; }

double gmshPixelScale() { return _pixelScale; }

void gmshPointSize(double s)
{
  s *= _pixelScale;
  _pointSize = s;
  // the shader writes gl_PointSize instead
  if(!glShader::enabled()) glPointSize((float)s);
}

double gmshCurrentPointSize() { return _pointSize; }

void gmshClipPlane(int i, const double plane[4])
{
  if(i < 0 || i > 5) return;
  for(int j = 0; j < 4; j++) _clipPlane[i][j] = plane[j];
  // OpenGL keeps the plane in eye coordinates: the equation (a row vector)
  // is transformed by the inverse transpose of the current modelview
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
  if(!glShader::enabled()) glClipPlane((GLenum)(GL_CLIP_PLANE0 + i), plane);
}

void gmshClipPlaneOn(int i, bool on)
{
  if(i < 0 || i > 5) return;
  _clipOn[i] = on;
  if(glShader::enabled()) return;
  if(on)
    glEnable((GLenum)(GL_CLIP_PLANE0 + i));
  else
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}

void gmshClipPlanesOn(int mask)
{
  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, (mask >> i) & 1);
}

bool gmshClipPlaneEnabled(int i)
{
  return (i >= 0 && i <= 5) ? _clipOn[i] : false;
}

void gmshClipOutside(bool outside)
{
  _clipOutside = outside;
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

  // hand the current matrix to the fixed function pipeline
  void _apply(int kind)
  {
    // the shader gets the matrices as uniforms
    if(glShader::enabled()) return;
    glMatrixMode(kind == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
    glLoadMatrixd(_stack[kind].top());
    if(kind != _mode)
      glMatrixMode(_mode == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
  }
} // namespace

void gmshMatrixMode(int kind)
{
  _mode = (kind == GMSH_PROJECTION) ? GMSH_PROJECTION : GMSH_MODELVIEW;
  if(glShader::enabled()) return;
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
  // what was pending belonged to the context that is gone
  _batchPos.clear();
  _batchNrm.clear();
  _batchCol.clear();
  _batchTex.clear();
  _batchDash.clear();
  _texture = 0;
  _textureMode = GMSH_TEXTURE_NONE;
  _alphaScale = 1.;
  _alphaScaleFilledOnly = false;
  _lineWidth = 1.;
  _stipple = false;
  _stippleFactor = 1;
  _stipplePattern = 0xffff;

  for(int i = 0; i < 4; i++) _color[i] = 255;
  _lighting = _twoSide = false;
  _pointSize = 1.;
  for(int i = 0; i < 6; i++) {
    _clipOn[i] = false;
    for(int j = 0; j < 4; j++) _clipPlane[i][j] = _clipEye[i][j] = 0.;
  }
  _clipOutside = false;

  for(int i = 0; i < 2; i++) {
    _stack[i].m.resize(16);
    glMatrix::identity(&_stack[i].m[0]);
  }
  _mode = GMSH_MODELVIEW;
}

static int _shadingModel = 0;

void gmshShadingModel(int model)
{
  if(model == _shadingModel) return;
  if(glShader::enabled()) gmshFlushImmediate();
  _shadingModel = model;
}

int gmshShadingModel() { return _shadingModel; }

// what the shader is handed alike by the vertex arrays and by the collected
// primitives: the material, the shading and the clipping planes (on[i] says
// which are on); nothing is cut off when no plane is on, whatever outside
// says (the glyphs of the cut elements are drawn whole, with the planes off)
static void setShaderCommon(const bool on[6], const double eye[6][4],
                            bool outside)
{
  glShader::setMaterial(CTX::instance()->shine,
                        CTX::instance()->shineExponent);
  glShader::setShading(gmshShadingModel(), CTX::instance()->brightness,
                       CTX::instance()->studioShadowStrength);
  bool anyPlane = false;
  for(int i = 0; i < 6; i++) {
    if(on[i]) {
      glShader::setClipPlane(i, eye[i]);
      anyPlane = true;
    }
    else
      glShader::setClipPlaneOff(i);
  }
  glShader::setClipOutside(outside && anyPlane);
}

void gmshPushShaderState()
{
  glShader::setMatrices(gmshMatrix(GMSH_MODELVIEW), gmshMatrix(GMSH_PROJECTION));
  glShader::setLighting(gmshLightingEnabled(), gmshLightTwoSideEnabled());
  glShader::setColor(gmshCurrentColor());
  glShader::setPointSize(gmshCurrentPointSize());
  glShader::setAlphaScale(_alphaScale);
  // everything but the collected lines draws undashed: the vertex arrays
  // carry no distance along the line, and a glyph is not a line
  glShader::setStipple(false, 1, 0xffff);
  setShaderCommon(_clipOn, _clipEye, _clipOutside);
}

void gmshRecordBegin(VertexArray *points, VertexArray *lines,
                     VertexArray *triangles)
{
  // what is waiting belongs to what was drawn before
  gmshFlushImmediate();
  _recTo[0] = points;
  _recTo[1] = lines;
  _recTo[2] = triangles;
  for(int i = 0; i < 4; i++) _recColor[i] = _color[i];
  _recording = true;
}

void gmshRecordEnd()
{
  _recording = false;
  gmshColor4ub(_recColor[0], _recColor[1], _recColor[2], _recColor[3]);
}

bool gmshImBegin(GLenum mode)
{
  if(!glShader::enabled() && !_recording) return false;
  gmshCollecting = true;
  _imPos.clear();
  _imNrm.clear();
  _imCol.clear();
  _imTex.clear();
  // the primitive is turned into independent points, lines or triangles
  // when it ends: a core profile has neither quads nor polygons, and only
  // independent primitives can share a draw
  _imMode = mode;
  return true;
}

void gmshImVertex(float x, float y, float z)
{
  float *p = _imPos.grow(3), *n = _imNrm.grow(3), *t = _imTex.grow(2);
  unsigned char *c = _imCol.grow(4);
  p[0] = x;
  p[1] = y;
  p[2] = z;
  for(int i = 0; i < 3; i++) n[i] = _imNormal[i];
  for(int i = 0; i < 4; i++) c[i] = _color[i];
  for(int i = 0; i < 2; i++) t[i] = _imTexCoord[i];
}

void gmshLineWidth(double w)
{
  w *= _pixelScale;
  if(glShader::enabled()) {
    if(_lineWidth == w) return;
    // what is waiting was collected to be drawn at the old width
    gmshFlushImmediate();
    _lineWidth = w;
    // a wider line is made of triangles: nothing to tell OpenGL
    return;
  }
  _lineWidth = w;
  glLineWidth((float)w);
}

double gmshCurrentLineWidth() { return _lineWidth; }

void gmshAlphaScale(double s, bool filledOnly)
{
  if(s < 0.) s = 0.;
  if(s > 1.) s = 1.;
  if(s == _alphaScale && filledOnly == _alphaScaleFilledOnly) return;
  // what is waiting was collected to be drawn with the old one
  if(glShader::enabled()) gmshFlushImmediate();
  _alphaScale = s;
  _alphaScaleFilledOnly = filledOnly;
}

double gmshAlphaScaleFor(unsigned int primitive)
{
  if(_alphaScaleFilledOnly && primitive != GL_TRIANGLES) return 1.;
  return _alphaScale;
}

void gmshLineStipple(int factor, unsigned short pattern)
{
  if(glShader::enabled()) {
    if(_stipple && _stippleFactor == factor && _stipplePattern == pattern)
      return;
    // what is waiting was collected to be drawn with the old pattern
    gmshFlushImmediate();
    _stipple = true;
    _stippleFactor = (factor > 0) ? factor : 1;
    _stipplePattern = pattern;
    return;
  }
  glLineStipple(factor, pattern);
  glEnable(GL_LINE_STIPPLE);
}

void gmshLineStippleOff()
{
  if(glShader::enabled()) {
    if(!_stipple) return;
    gmshFlushImmediate();
    _stipple = false;
    return;
  }
  glDisable(GL_LINE_STIPPLE);
}

bool gmshLineStippleEnabled() { return _stipple; }
int gmshLineStippleFactor() { return _stippleFactor; }
unsigned short gmshLineStipplePattern() { return _stipplePattern; }

void gmshTexture(unsigned int id, int mode)
{
  if(id == _texture && (!id || mode == _textureMode)) return;
  // what is waiting was collected to be drawn through the old one
  if(glShader::enabled()) gmshFlushImmediate();
  _texture = id;
  _textureMode = id ? mode : GMSH_TEXTURE_NONE;
  if(!glShader::enabled()) {
    if(id) {
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, id);
      glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,
                (mode == GMSH_TEXTURE_IMAGE) ? GL_REPLACE : GL_MODULATE);
    }
    else {
      glDisable(GL_TEXTURE_2D);
    }
  }
}

void gmshImTexCoord(float s, float t)
{
  _imTexCoord[0] = s;
  _imTexCoord[1] = t;
}

void gmshImNormal(float x, float y, float z)
{
  _imNormal[0] = x;
  _imNormal[1] = y;
  _imNormal[2] = z;
}

namespace {
  // copy vertex i of what has been collected to the end of what will be drawn
  // the vertices of the primitive being converted, in the order they go
  // into the batch: gathered first, so that the batch grows once
  growBuf<std::size_t> _emitted;
  inline void _emit(std::size_t i) { _emitted.push_back(i); }
  void _emitFlush()
  {
    std::size_t m = _emitted.size();
    if(!m) return;
    float *p = _batchPos.grow(3 * m), *n = _batchNrm.grow(3 * m);
    float *t = _batchTex.grow(2 * m);
    unsigned char *c = _batchCol.grow(4 * m);
    float *d = _batchDash.grow(m);
    const float *ip = _imPos.data(), *in = _imNrm.data(), *it = _imTex.data();
    const unsigned char *ic = _imCol.data();
    for(std::size_t j = 0; j < m; j++) {
      std::size_t i = _emitted[j];
      for(int k = 0; k < 3; k++) p[3 * j + k] = ip[3 * i + k];
      for(int k = 0; k < 3; k++) n[3 * j + k] = in[3 * i + k];
      for(int k = 0; k < 4; k++) c[4 * j + k] = ic[4 * i + k];
      for(int k = 0; k < 2; k++) t[2 * j + k] = it[2 * i + k];
      d[j] = 0.f;
    }
    _emitted.clear();
  }

  // distance along its line of each vertex of the segments just added, in
  // pixels, for the dash pattern; restarts at every independent segment and
  // carries on along a strip, as OpenGL's stipple did
  void _dashDistances(std::size_t first, bool carry)
  {
    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    int viewport[4] = {vp[0], vp[1], vp[2], vp[3]};
    std::size_t count = _batchPos.size() / 3;
    double run = 0.;
    for(std::size_t i = first; i + 1 < count; i += 2) {
      double p0[3] = {_batchPos[3 * i], _batchPos[3 * i + 1],
                      _batchPos[3 * i + 2]};
      double p1[3] = {_batchPos[3 * i + 3], _batchPos[3 * i + 4],
                      _batchPos[3 * i + 5]};
      double w0[3], w1[3];
      if(!glMatrix::project(p0, _batchState.modelview, _batchState.projection,
                            viewport, w0) ||
         !glMatrix::project(p1, _batchState.modelview, _batchState.projection,
                            viewport, w1))
        continue;
      double dx = w1[0] - w0[0], dy = w1[1] - w0[1];
      double len = std::sqrt(dx * dx + dy * dy);
      if(!carry) run = 0.;
      _batchDash[i] = (float)run;
      _batchDash[i + 1] = (float)(run + len);
      run += len;
    }
  }
} // namespace

namespace {
  // switch the blending, colour and alpha factors together
  // the blend function in force; the colour's and the alpha's are the same
  // one when the driver has no separate blending (OpenGL 1.4), whose enums
  // it would reject
  void _getBlend(GLint src[2], GLint dst[2])
  {
    src[0] = src[1] = GL_ONE;
    dst[0] = dst[1] = GL_ZERO;
    if(glApi::BlendFuncSeparate) {
      glGetIntegerv(GL_BLEND_SRC_RGB, &src[0]);
      glGetIntegerv(GL_BLEND_DST_RGB, &dst[0]);
      glGetIntegerv(GL_BLEND_SRC_ALPHA, &src[1]);
      glGetIntegerv(GL_BLEND_DST_ALPHA, &dst[1]);
    }
    else {
      glGetIntegerv(GL_BLEND_SRC, &src[0]);
      glGetIntegerv(GL_BLEND_DST, &dst[0]);
      src[1] = src[0];
      dst[1] = dst[0];
    }
  }

  void _setBlend(bool on, const GLint src[2], const GLint dst[2])
  {
    if(!on) {
      glDisable(GL_BLEND);
      return;
    }
    glEnable(GL_BLEND);
    if(glApi::BlendFuncSeparate)
      glApi::BlendFuncSeparate(src[0], dst[0], src[1], dst[1]);
    else
      glBlendFunc(src[0], dst[0]);
  }
} // namespace

void gmshFlushImmediate()
{
  if(_batchPos.empty()) return;
  int count = (int)(_batchPos.size() / 3);
  if(glShader::use()) {
    // the state the primitives were collected under, not the current one:
    // the blending is OpenGL's own, so it is set here and the caller's put
    // back afterwards
    GLboolean wasBlend = glIsEnabled(GL_BLEND);
    GLint wasSrc[2], wasDst[2];
    _getBlend(wasSrc, wasDst);
    _setBlend(_batchState.blend, _batchState.blendSrc, _batchState.blendDst);
    glShader::setMatrices(_batchState.modelview, _batchState.projection);
    glShader::setLighting(_batchState.lighting, _batchState.twoSide);
    glShader::setPointSize(_batchState.pointSize);
    glShader::setAlphaScale(
      (_batchState.alphaScaleFilledOnly && _batchMode != GL_TRIANGLES) ?
        1. : _batchState.alphaScale);
    setShaderCommon(_batchState.clipOn, _batchState.clip,
                    _batchState.clipOutside);
    // the pattern only applies to lines
    glShader::setStipple(_batchState.stipple && _batchMode == GL_LINES,
                         _batchState.stippleFactor,
                         _batchState.stipplePattern);
    // a core profile draws no wide lines: make triangles out of them
    bool wide = (_batchMode == GL_LINES && _batchState.lineWidth > 1.);
    if(!wide ||
       !glShader::drawWideLines(&_batchPos[0], &_batchNrm[0], GL_FLOAT,
                                &_batchCol[0], count, _batchState.lineWidth,
                                _batchState.lighting))
      glShader::drawImmediate(_batchMode, &_batchPos[0], &_batchNrm[0],
                              &_batchCol[0], &_batchTex[0], &_batchDash[0],
                              _batchState.texture, _batchState.textureMode,
                              count);
    _setBlend(wasBlend ? true : false, wasSrc, wasDst);
  }
  _batchPos.clear();
  _batchNrm.clear();
  _batchCol.clear();
  _batchTex.clear();
  _batchDash.clear();
}

namespace {
  // the current state, to compare with the batch's
  BatchState _currentState()
  {
    BatchState b;
    const double *m = gmshMatrix(GMSH_MODELVIEW);
    const double *p = gmshMatrix(GMSH_PROJECTION);
    for(int i = 0; i < 16; i++) {
      b.modelview[i] = m[i];
      b.projection[i] = p[i];
    }
    for(int i = 0; i < 6; i++) {
      b.clipOn[i] = _clipOn[i];
      for(int j = 0; j < 4; j++) b.clip[i][j] = _clipEye[i][j];
    }
    b.clipOutside = _clipOutside;
    b.blend = glIsEnabled(GL_BLEND) ? true : false;
    b.blendSrc[0] = b.blendSrc[1] = GL_ONE;
    b.blendDst[0] = b.blendDst[1] = GL_ZERO;
    if(b.blend) _getBlend(b.blendSrc, b.blendDst);
    b.lighting = _lighting;
    b.twoSide = _twoSide;
    b.pointSize = _pointSize;
    b.alphaScale = _alphaScale;
    b.alphaScaleFilledOnly = _alphaScaleFilledOnly;
    b.texture = _texture;
    b.textureMode = _textureMode;
    b.lineWidth = _lineWidth;
    b.stipple = _stipple;
    b.stippleFactor = _stippleFactor;
    b.stipplePattern = _stipplePattern;
    return b;
  }
} // namespace

void gmshImEnd()
{
  gmshCollecting = false;
  std::size_t num = _imPos.size() / 3;
  if(!num) return;

  if(!_recording) {
    BatchState now = _currentState();
    if(!_batchPos.empty() && now != _batchState) gmshFlushImmediate();
    _batchState = now;
  }

  // what the primitive becomes as independent points, lines or triangles
  GLenum mode = GL_TRIANGLES;
  if(_imMode == GL_POINTS)
    mode = GL_POINTS;
  else if(_imMode == GL_LINES || _imMode == GL_LINE_STRIP ||
          _imMode == GL_LINE_LOOP)
    mode = GL_LINES;

  if(!_recording) {
    if(!_batchPos.empty() && mode != _batchMode) gmshFlushImmediate();
    _batchMode = mode;
  }

  std::size_t firstEmitted = _batchPos.size() / 3;

  switch(_imMode) {
  case GL_POINTS:
  case GL_LINES:
  case GL_TRIANGLES:
    // already independent primitives: appended as they are, in one go (the
    // nodes of a large mesh come through here, millions to a frame)
    _batchPos.append(_imPos);
    _batchNrm.append(_imNrm);
    _batchCol.append(_imCol);
    _batchTex.append(_imTex);
    _batchDash.resize(_batchDash.size() + num, 0.f);
    break;
  case GL_LINE_STRIP:
    for(std::size_t i = 0; i + 1 < num; i++) {
      _emit(i);
      _emit(i + 1);
    }
    break;
  case GL_LINE_LOOP:
    for(std::size_t i = 0; i + 1 < num; i++) {
      _emit(i);
      _emit(i + 1);
    }
    if(num > 2) {
      _emit(num - 1);
      _emit(0);
    }
    break;
  case GL_TRIANGLE_STRIP:
    // the winding alternates, as it does in the strip itself
    for(std::size_t i = 0; i + 2 < num; i++) {
      if(i & 1) {
        _emit(i + 1);
        _emit(i);
      }
      else {
        _emit(i);
        _emit(i + 1);
      }
      _emit(i + 2);
    }
    break;
  case GL_TRIANGLE_FAN:
  case GL_POLYGON:
    // a fan around the first corner (GL_POLYGON is convex)
    for(std::size_t t = 1; t + 1 < num; t++) {
      _emit(0);
      _emit(t);
      _emit(t + 1);
    }
    break;
  case GL_QUADS:
    for(std::size_t q = 0; q + 3 < num; q += 4) {
      const std::size_t idx[6] = {q, q + 1, q + 2, q, q + 2, q + 3};
      for(int k = 0; k < 6; k++) _emit(idx[k]);
    }
    break;
  default:
    // an unknown primitive is drawn on its own rather than guessed at
    if(_recording) break;
    gmshFlushImmediate();
    for(std::size_t i = 0; i < num; i++) _emit(i);
    _emitFlush();
    _batchMode = _imMode;
    gmshFlushImmediate();
    break;
  }

  _emitFlush();

  if(_recording) {
    // into the array of the primitive, and out of the batch
    int npe = (mode == GL_POINTS) ? 1 : (mode == GL_LINES) ? 2 : 3;
    VertexArray *va = _recTo[npe - 1];
    std::size_t last = _batchPos.size() / 3;
    for(std::size_t i = firstEmitted; va && i + npe <= last; i += npe) {
      double x[3], y[3], z[3];
      unsigned char r[3], g[3], b[3], a[3];
      SVector3 n[3];
      for(int k = 0; k < npe; k++) {
        std::size_t j = i + k;
        x[k] = _batchPos[3 * j];
        y[k] = _batchPos[3 * j + 1];
        z[k] = _batchPos[3 * j + 2];
        n[k] = SVector3(_batchNrm[3 * j], _batchNrm[3 * j + 1],
                        _batchNrm[3 * j + 2]);
        r[k] = _batchCol[4 * j];
        g[k] = _batchCol[4 * j + 1];
        b[k] = _batchCol[4 * j + 2];
        a[k] = _batchCol[4 * j + 3];
      }
      va->add(x, y, z, (npe == 3) ? n : nullptr, r, g, b, a, nullptr, false);
    }
    _batchPos.resize(3 * firstEmitted);
    _batchNrm.resize(3 * firstEmitted);
    _batchCol.resize(4 * firstEmitted);
    _batchTex.resize(2 * firstEmitted);
    _batchDash.resize(firstEmitted);
    return;
  }

  if(mode == GL_LINES && _stipple)
    _dashDistances(firstEmitted, _imMode != GL_LINES);
}
