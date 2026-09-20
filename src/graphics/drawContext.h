// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_H
#define DRAW_CONTEXT_H

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include "SBoundingBox3d.h"
#include "SPoint2.h"
#include "Camera.h"

// the OpenGL headers, and the entry points that came after OpenGL 1.1
#include "glApi.h"
// the immediate mode drawing the decorations of the scene are made of
#include "glImmediate.h"

#include "GmshConfig.h"
#include "VertexArray.h"

#if defined(HAVE_VISUDEV)
#define NORMAL_GLTYPE GL_FLOAT
#else
#define NORMAL_GLTYPE GL_BYTE
#endif

// Draw a vertex array as primitives of the given type, all of it or the runs
// [first, last) of its vertices: lit with its normals (GMSH_DRAW_LIGHT, when
// it has some), in its colours (GMSH_DRAW_COLORS, when it has some) or else
// in the current colour, and with its polygons pushed behind the lines drawn
// over them (GMSH_DRAW_OFFSET). A picking pass draws it unlit, in the colour
// of the identifier it has set, unless the colours of the array are the
// identifiers (GMSH_DRAW_IDENTIFIERS). The shader pipeline makes quads of the
// lines wider than a pixel, and dashes the lines if stippling is on. Leaves
// the lighting off.
enum {
  GMSH_DRAW_LIGHT = 1,
  GMSH_DRAW_COLORS = 2,
  GMSH_DRAW_OFFSET = 4,
  GMSH_DRAW_IDENTIFIERS = 8
};
void gmshDrawVertexArray(VertexArray *va, GLenum type, int flags,
                         const std::vector<std::pair<int, int> > *runs =
                           nullptr);

// which part of the scene a pass draws: everything transparent is drawn after
// everything else, in one pass
enum gmshTransparencyPass {
  TRANSPARENCY_ALL = 0,
  TRANSPARENCY_OPAQUE = 1,
  TRANSPARENCY_TRANSPARENT = 2
};
// Is anything in the geometry or the mesh transparent, through the
// Transparency options, the colours of the options, or the colour of an
// entity? Everything is, when the options' colours are; otherwise only the
// entities whose own colour is, which a pass asks about one by one.
bool gmshGeometryIsTransparent();
bool gmshGeometryColorsAreTransparent();
bool gmshGeometryEntityIsTransparent(GEntity *e);
bool gmshMeshIsTransparent();
bool gmshMeshColorsAreTransparent();
bool gmshMeshEntityIsTransparent(GEntity *e);

class GModel;
// GModel::getMeshStatus() for the drawing, which asks it several times a
// frame: computed again only when the mesh, the geometry or the visibilities
// have changed (see CTX::meshChanged())
int drawMeshStatus(GModel *m);

class PView;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

class drawTransform {
public:
  drawTransform() {}
  virtual ~drawTransform() {}
  virtual void transform(double &x, double &y, double &z) {}
  virtual void transformOneForm(double &x, double &y, double &z) {}
  virtual void transformTwoForm(double &x, double &y, double &z) {}
  virtual void setMatrix(double mat[3][3], double tra[3] = nullptr) {}
};

class drawTransformScaled : public drawTransform {
private:
  double _mat[3][3];
  double _tra[3];

public:
  drawTransformScaled(double mat[3][3], double tra[3] = nullptr) : drawTransform()
  {
    drawTransformScaled::setMatrix(mat, tra);
  }
  virtual void setMatrix(double mat[3][3], double tra[3] = nullptr)
  {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) _mat[i][j] = mat[i][j];
      if(tra)
        _tra[i] = tra[i];
      else
        _tra[i] = 0.;
    }
  }
  virtual void transform(double &x, double &y, double &z)
  {
    double xyz[3] = {x, y, z};
    x = y = z = 0.;
    for(int k = 0; k < 3; k++) {
      x += _mat[0][k] * xyz[k];
      y += _mat[1][k] * xyz[k];
      z += _mat[2][k] * xyz[k];
    }
    x += _tra[0];
    y += _tra[1];
    z += _tra[2];
  }
};

// global drawing functions, which need to be redefined for each widget toolkit
// (FLTK, Qt, etc.)
class drawContextGlobal {
public:
  drawContextGlobal() {}
  virtual ~drawContextGlobal() {}
  virtual void draw(bool rateLimited = true) {}
  // again: the same picture as the draw just before it (the second of the
  // two a print makes), whose studio frames need not be drawn a second time
  virtual void drawCurrentOpenglWindow(bool make_current, bool again = false)
  {
  }
  virtual int getFontIndex(const char *fontname) { return 0; }
  virtual int getFontEnum(int index) { return 0; }
  virtual const char *getFontName(int index) { return "Helvetica"; }
  // the same for every toolkit, so not a hook: implemented once in
  // drawContext.cpp
  int getFontAlign(const char *alignstr);
  virtual int getFontSize() { return 12; }
  virtual void setFont(int fontid, int fontsize) {}
  virtual double getStringWidth(const char *str) { return 1.; }
  virtual int getStringHeight() { return 12; }
  virtual int getStringDescent() { return 3; }
  virtual void drawString(const char *str) {}
  // draw a string at window coordinates win in the current colour (a core
  // profile has no raster position, so the position is computed and passed;
  // the raster position is also set for backends that still use it)
  virtual void drawString(const char *str, const double win[3])
  {
    drawString(str);
  }
  // Does this engine keep a pile of string textures, one per string, that has
  // to be sized for the frame? Only the native one does, and only where FLTK
  // draws its strings as textures; the others hold their strings in an atlas
  // that grows by itself. The count is only worth making when the answer is
  // yes (see stringsInFrame()).
  virtual bool keepsStringTextures() { return false; }
  virtual void resetFontTextures() {}
  // make the pile able to hold n strings: past its capacity the textures are
  // recomputed one by one, which is slow
  virtual void reserveStringTextures(std::size_t n) {}
  virtual void flushString() {}
  // draw the strings with a one pixel halo in the background colour, so
  // that they read over the data
  void setStringHalo(bool halo) { _stringHalo = halo; }
  bool stringHalo() { return _stringHalo; }
  // the pixels per unit of the drawing of what is being drawn (a window, or
  // a picture being printed), which the strings are rasterised at: said by
  // the window at the beginning of its draw, as a window that has not drawn
  // yet (a tile just split off) knows nothing of its own
  void setPixelFactor(double f) { _pixelFactor = (f > 0.) ? f : 1.; }
  double pixelFactor() { return _pixelFactor; }
protected:
  bool _stringHalo = false;
  double _pixelFactor = 1.;
public:
  // is a mouse button held down? The vertex arrays are left alone while
  // dragging.
  virtual bool mouseIsPressed() { return false; }
  virtual std::string getName() { return "None"; }
};

class drawContext {
private:
  // a picture drawn in the scene, kept as a texture with its size
  struct imgtex {
    GLuint tex = 0, w = 0, h = 0;
  };
  static drawContextGlobal *_global;
  drawTransform *_transform;
  std::set<GModel *> _hiddenModels;
  std::set<PView *> _hiddenViews;
  GLuint _bgImageTexture, _bgImageW, _bgImageH;
  // factor between the (true) size in pixels and the size reported by the
  // windowing system (e.g. 2 on an Apple "retina" display); set by the GUI
  double _highResolutionPixelFactor;
  std::map<std::string, imgtex> _imageTextures;

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
  double model[16],
    proj[16]; // the modelview and projection matrix as they were
              // at the time of the last InitPosition() call
  // a pass either draws the scene or draws it in picking colours
  enum RenderMode { GMSH_RENDER = 1, GMSH_SELECT = 2 };
  int render_mode; // current rendering mode
  // which half of the scene is being drawn, see gmshTransparencyPass
  int transparencyPass;
  // true while the scene is drawn into the shadow map of the studio shading:
  // only the model is drawn then, no strings or images
  bool shadowPass;
  // the frame being accumulated in studio shading: 0 draws the plain frame,
  // higher ones jitter the light, the dome and the projection
  int studioSample;
  // the shift of the projection of the frame being accumulated, a fraction
  // of a pixel, which antialiases the average (identity on the plain frame
  // and when picking)

private:
  // Colour buffer picking: a selection pass draws every pickable object in a
  // flat colour encoding its position in _pickObjects, then reads the colours
  // back. This replaces GL_SELECT, which drivers implement on the CPU.
  struct pickObject {
    int type, ient, type2, ient2;
    // a marker standing for an entity rather than showing its shape, drawn
    // in front of everything (the sphere of a volume)
    bool front;
    pickObject(int t = -1, int i = -1, int t2 = -1, int i2 = -1, bool f = false)
      : type(t), ient(i), type2(t2), ient2(i2), front(f)
    {
    }
  };
  std::vector<pickObject> _pickObjects;
  bool _pickColor;
  // the scale of the depth range per dimension in a picking pass
  double _pickDepthStep = 0.;
  // the masks and the depth range the pass is drawing with (-1: not known)
  int _pickStateSkip = -1;
  double _pickStateFar = -1.;
  // the far end of the depth range an object of a type is drawn into (see
  // setPickColor()), and a change of the masks and of that range
  double _pickFar(int type, bool front) const
  {
    return front ? 0.2 :
           (type >= 0 && type <= 3) ? 1. - (3 - type) * _pickDepthStep :
                                      1.;
  }
  void _pickState(bool skip, double zfar);
  // The last identifier image and depths read back from a picking pass, so
  // that hovering costs a lookup instead of a redraw per mouse move. Dropped
  // by openglWindow::draw() on every redraw; the flags record what it was
  // drawn with, as a pick asking for something else has to redraw.
  std::vector<unsigned char> _pickCache;
  std::vector<float> _pickCacheDepth;
  bool _pickCacheValid, _pickCacheMesh, _pickCachePost, _pickCacheElements;
  void _pickCheckLimit();
  // what names an object of a picking pass from one pass to the next: the
  // identifiers are indices into a list rebuilt every time, the tags are not
  struct pickKey {
    int type = -1, ient = 0, type2 = -1, ient2 = -1;
    bool operator==(const pickKey &o) const
    {
      return type == o.type && ient == o.ient && type2 == o.type2 &&
             ient2 == o.ient2;
    }
  };
  // the entities stepped past, and the last one a pick chose
  std::vector<pickKey> _pickSkip;
  pickKey _pickLast;
  bool _pickLastValid = false;
  int _pickCandidates = 0;
  // the point of the model under the middle of the last pick, from the depth
  // the pass read back
  double _pickPoint[3] = {0., 0., 0.};
  bool _pickPointValid = false;
  // the region of the window the image covers, in real pixels (a region
  // around the pointer is much cheaper to draw than the whole window)
  int _pickCacheX, _pickCacheY, _pickCacheWidth, _pickCacheHeight;
  // draw a region of the window in picking colours and keep the result
  bool _fillPickCache(bool mesh, bool post, int fx, int fy, int fw, int fh);
  // the projection built by initProjection(), and the modelview it leaves
  // for initPosition()
  double _projection[16], _modelBase[16];
  void drawAxis(double xmin, double ymin, double zmin, double xmax, double ymax,
                double zmax, int nticks, int mikado);
  bool generateTextureForImage(const std::string &name, int page,
                               GLuint &imageTexture, GLuint &imageW,
                               GLuint &imageH);
  // The steps of a frame, called by draw3d(), draw2d() and the picking pass
  // and by nothing outside this class: the order they go in is what a frame
  // is, and is not something a caller picks.
  void studioJitter(double m[16]);
  void initProjection();
  void drawGeom();
  void drawMesh();
  void drawPost();
  bool anyViewIsTransparent();
  void drawBackgroundGradient();
  void drawBackgroundImage(bool moving);
  void drawText2d();
  void drawGraph2d(bool inModelCoordinates);
  void drawAxes();
  void drawSmallAxes();
  void drawScales();
  void buildRotationMatrix();
  void setEulerAnglesFromRotationMatrix();
  void initRenderModel();
  void drawShadowMap();
  bool drawOneShadowMap(int which, const double dir[3]);
  void drawStudioFloor();
  // same as _pickColor, but reachable from the free drawing functions
  static bool _pickColorActive;
  bool _selectColor(int type, bool multiple, bool mesh, bool post, int x, int y,
                    int w, int h, std::vector<GVertex *> &vertices,
                    std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
                    std::vector<GRegion *> &regions,
                    std::vector<MElement *> &elements,
                    std::vector<SPoint2> &points,
                    std::vector<PView *> &views);
public:
  // true during a colour buffer picking pass, where the drawing code must
  // use the colour set by setPickColor() instead of its own
  bool inPickColorMode() const { return _pickColor; }
  // Register a pickable object and set the colour that encodes it. Each
  // dimension is drawn into a depth range of its own, lower dimensions in
  // front, so that a point or a curve can be picked through a surface;
  // `front' puts what follows in the front-most range whatever its
  // dimension, for a marker that stands for an entity rather than showing
  // its shape (the sphere of a volume, which floats inside it).
  void setPickColor(int type, int ient, int type2 = -1, int ient2 = -1,
                    bool front = false);
  // For what is drawn from a kept array with the identifiers as its vertex
  // colours (see drawGeom.cpp): register the entities of a type as
  // setPickColor() would, returning the identifier of the first (the others
  // follow), or 0 outside a picking pass; say whether one has been stepped
  // past with the wheel; and set the masks and the depth range setPickColor()
  // gives the type
  std::size_t pickRegister(int type, const std::vector<int> &tags);
  bool pickSkipped(int type, int ient);
  void pickStateFor(int type);
  // the colour of an identifier: 24 bits, 0 being the background; beyond,
  // the background (what cannot be told apart is not pickable, rather than
  // taken for something else)
  static void pickIdColor(std::size_t id, unsigned char c[4])
  {
    if(id >= (std::size_t)1 << 24) id = 0;
    c[0] = (unsigned char)(id & 0xff);
    c[1] = (unsigned char)((id >> 8) & 0xff);
    c[2] = (unsigned char)((id >> 16) & 0xff);
    c[3] = 255;
  }
  // forget the identifier image: anything that changes what a redraw would
  // show must call this
  void invalidatePickCache() { _pickCacheValid = false; }
  // Step through the entities under the cursor instead of the drawing order
  // deciding which one wins: what a pick returned is set aside, a pass draws
  // nothing at all for it (setPickColor()), and the next pick finds what was
  // behind it. stepPick() goes one deeper (or back) and stops at the furthest
  // and the nearest rather than coming round, resetPick() returns to the
  // entity in front, pickDepth() says how deep the last pick went and
  // pickCandidates() how many entities its image held around the cursor.
  void stepPick(int direction);
  void resetPick();
  int pickDepth() const { return (int)_pickSkip.size(); }
  int pickCandidates() const { return _pickCandidates; }
  // whether a step from what the last pick returned would find something:
  // the identifier image holds only what is in front, so this draws it
  // again without that entity, and leaves the stepping as it was
  bool pickBehind(int type, bool mesh, bool post, int x, int y, int w, int h);
  // the point of the model the last pick hit, from the depth under the middle
  // of its rectangle (or the nearest depth of what it returned): false when
  // it hit nothing of the 3D scene
  bool pickPoint(double xyz[3]) const
  {
    if(!_pickPointValid) return false;
    for(int i = 0; i < 3; i++) xyz[i] = _pickPoint[i];
    return true;
  }
  // stop attributing what is drawn next to the last registered object, so
  // that decorations (frames, axes, labels) are not picked as it
  void unsetPickColor();
  // the identifier of an entity for a picking pass - or the background for
  // an entity of another model than the current one, as a pick looks the
  // tags up in the current model (drawn with whatever identifier was set
  // last, it was taken for the entity that had set it)
  void setPickColorFor(GEntity *e, bool front = false);
  static bool pickColorActive() { return _pickColorActive; }
  drawContext(drawTransform *transform = nullptr);
  // factor between the true size in pixels and the size reported by the OS
  // (e.g. 2 on an Apple "retina" display); refreshed by the GUI before each
  // draw, as it changes when a window moves across displays
  double highResolutionPixelFactor() { return _highResolutionPixelFactor; }
  void setHighResolutionPixelFactor(double factor)
  {
    _highResolutionPixelFactor = (factor > 0.) ? factor : 1.;
  }
  void copyViewAttributes(drawContext *other)
  {
    camera = other->camera;
    for(int i = 0; i < 3; i++) {
      r[i] = other->r[i];
      t[i] = other->t[i];
      s[i] = other->s[i];
      t_init[i] = other->t_init[i];
    }
    for(int i = 0; i < 4; i++) {
      quaternion[i] = other->quaternion[i];
    }
    for(int i = 0; i < 16; i++) {
      rot[i] = other->rot[i];
    }
  }
  static void setGlobal(drawContextGlobal *global) { _global = global; }
  static drawContextGlobal *global();
  void setTransform(drawTransform *transform) { _transform = transform; }
  drawTransform *getTransform() { return _transform; }
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
  void hide(GModel *m) { _hiddenModels.insert(m); }
  void hide(PView *v) { _hiddenViews.insert(v); }
  void show(GModel *m) { _hiddenModels.erase(m); }
  void show(PView *v) { _hiddenViews.erase(v); }
  void showAll()
  {
    _hiddenModels.clear();
    _hiddenViews.clear();
  }
  bool isVisible(GModel *m)
  {
    return (_hiddenModels.find(m) == _hiddenModels.end());
  }
  bool isVisible(PView *v)
  {
    return (_hiddenViews.find(v) == _hiddenViews.end());
  }
  void invalidateBgImageTexture();
  void setQuaternion(double q0, double q1, double q2, double q3);
  void addQuaternion(double p1x, double p1y, double p2x, double p2y);
  void addQuaternionFromAxisAndAngle(double axis[3], double angle);
  void setQuaternionFromEulerAngles();
  // the matrices of camera mode: the projection (the camera's frustum,
  // shifted for a studio frame) and the modelview (the camera looking at
  // its target), which `view' comes back with
  void initCameraMatrices(double view[16]);
  void initPosition(bool saveMatrices);
  void unproject(double winx, double winy, double p[3], double d[3]);
  void viewport2World(double vp[3], double xyz[3]);
  void world2Viewport(double xyz[3], double vp[3]);
  bool select(int type, bool multiple, bool mesh, bool post, int x, int y,
              int w, int h, std::vector<GVertex *> &vertices,
              std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
              std::vector<GRegion *> &regions,
              std::vector<MElement *> &elements, std::vector<SPoint2> &points,
              std::vector<PView *> &views);
  void recenterForRotationCenterChange(SPoint3 newRotationCenter);
  int fix2dCoordinates(double *x, double *y);
  void draw3d();
  void draw2d();
  void drawAxes(int mode, double ticks[3], std::string format[3],
                std::string label[3], double bb[6], int mikado,
                double value_bb[6]);
  void drawAxes(int mode, double ticks[3], std::string format[3],
                std::string label[3], SBoundingBox3d &bb, int mikado,
                SBoundingBox3d &value_bb);
  // a box of text over the picture, in the pixel coordinates of draw2d: the
  // lines are split on newlines and wrapped; (x, y) is the top left corner
  // of the box (align 0), the top centre (1), or the cursor, which the box
  // hangs below and to the right of, or above or to the left of when there
  // is no room (2); the box is kept inside the window, and box gets where it
  // was drawn (left, bottom, width, height)
  void drawTextBox(const std::string &text, double x, double y, int align,
                   double box[4] = nullptr);
  void drawString(const std::string &s, double x, double y, double z,
                  const std::string &font_name, int font_enum, int font_size,
                  int align, int line_num = 0);
  void drawString(const std::string &s, double x, double y, double z,
                  int line_num = 0);
  void drawStringCenter(const std::string &s, double x, double y, double z,
                        int line_num = 0);
  void drawStringRight(const std::string &s, double x, double y, double z,
                       int line_num = 0);
  void drawString(const std::string &s, double x, double y, double z,
                  double style, int line_num = 0);
  void drawImage(const std::string &s, double x, double y, double z,
                 int align = 0);
  void drawSphere(double R, double x, double y, double z, int n1, int n2,
                  int light);
  void drawSphere(double size, double x, double y, double z, int light);
  void drawCylinder(double width, double *x, double *y, double *z, int light);
  // update the glyph shapes to the options; they are only read afterwards,
  // possibly by several threads at once
  void updateGlyphTemplates();
  // the version of the templates, which changes when they are built again
  // (in any window)
  int glyphTemplatesVersion();
  // the shape of a kind of glyph: triangle corners, normals, and the normals
  // encoded as a vertex array stores them; valid after
  // updateGlyphTemplates(), null if the shape has no triangles
  const float *glyphTemplate(int kind, const float *&normals,
                             const normal_type *&encoded, int &numVertices);
  void drawArrow3d(double x, double y, double z, double dx, double dy,
                   double dz, double length, int light);
  void drawVector(int Type, int Fill, double x, double y, double z, double dx,
                  double dy, double dz, int light);
  void drawBox(double xmin, double ymin, double zmin, double xmax, double ymax,
               double zmax, bool labels = true);
  void drawPlaneInBoundingBox(double xmin, double ymin, double zmin,
                              double xmax, double ymax, double zmax, double a,
                              double b, double c, double d, int shade = 0);
  // dynamic pointer to a transient geometry drawing function
  static void setDrawGeomTransientFunction(void (*fct)(void *));
  static void (*drawGeomTransient)(void *);
};

class mousePosition {
public:
  double win[3]; // window coordinates
  double wnr[3]; // world coordinates BEFORE rotation
  double s[3]; // scaling state when the event was recorded
  double t[3]; // translation state when the event was recorded
  mousePosition()
  {
    for(int i = 0; i < 3; i++) win[i] = wnr[i] = s[i] = t[i] = 0.;
  }
  void set(drawContext *ctx, int x, int y)
  {
    for(int i = 0; i < 3; i++) {
      s[i] = ctx->s[i];
      t[i] = ctx->t[i];
    }
    win[0] = (double)x;
    win[1] = (double)y;
    win[2] = 0.;

    wnr[0] = (ctx->vxmin +
              win[0] / (double)ctx->viewport[2] * (ctx->vxmax - ctx->vxmin)) /
               ctx->s[0] -
             ctx->t[0] + ctx->t_init[0] / ctx->s[0];
    wnr[1] = (ctx->vymax -
              win[1] / (double)ctx->viewport[3] * (ctx->vymax - ctx->vymin)) /
               ctx->s[1] -
             ctx->t[1] + ctx->t_init[1] / ctx->s[1];
    wnr[2] = 0.;
  }
  void recenter(drawContext *ctx)
  {
    // compute the equivalent translation to apply *after* the scaling so that
    // the scaling is done around the point which was clicked:
    ctx->t[0] = t[0] * (s[0] / ctx->s[0]) - wnr[0] * (1. - (s[0] / ctx->s[0]));
    ctx->t[1] = t[1] * (s[1] / ctx->s[1]) - wnr[1] * (1. - (s[1] / ctx->s[1]));
  }
};

#endif
