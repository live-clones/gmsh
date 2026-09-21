// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <algorithm>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "Plugin.h"
#include "Numeric.h"
#include "VertexArray.h"
#include "Context.h"
#include "ClipPlanes.h"
#include <vector>
#include <cstring>
#include "gl2ps.h"
#include "glyphList.h"
#include "glShader.h"

void clearGlyphArrays(PView *p) { glyphCache::clear(p); }

// turn the clipping planes of this view on or off (the cut elements of whole
// element mode and the glyphs are drawn with them off)
static void setViewClipPlanes(PViewOptions *opt, bool on)
{
  gmshClipPlanesOn(on ? opt->clip : 0);
}

// The cut elements of whole element mode, with the shader pipeline, are
// clipped to what the planes cut off, so that they sit next to the clipped
// rest of the view without overlapping it (a transparent view would show the
// overlap); the fixed function pipeline draws them whole with the planes off.
static void setViewClipOutside(PViewOptions *opt, bool on)
{
  if(gmshUseShaders())
    gmshClipOutside(on);
  else
    setViewClipPlanes(opt, !on);
}

// Are the glyphs tested against the planes one at a time? In whole element
// mode a glyph is drawn whole or not at all, so the test is made on the
// point or segment it is placed by, with the planes off while drawing. Not
// in the mode that draws only the cut volumes: its arrays are already filled
// through the planes.
static bool clipGlyphs(PViewOptions *opt)
{
  return CTX::instance()->clipWholeElements && opt->clip &&
         !CTX::instance()->clipOnlyDrawIntersectingVolume;
}

// is this glyph kept by whole element mode? A point is kept when on the
// visible side of every plane, a segment unless a plane has all of it beyond
static bool glyphIsKept(PViewOptions *opt, const float *p0,
                        const float *p1 = nullptr)
{
  if(!clipGlyphs(opt)) return true;
  const float *ends[2] = {p0, p1};
  return !clipPlanes::removesAll(opt->clip, p1 ? 2 : 1,
                                 [&](int j, int k) { return ends[j][k]; });
}

// what the kept glyphs depend on
static void addClipToken(glyphToken &tok, PViewOptions *opt)
{
  tok.add(clipGlyphs(opt) ? opt->clip : 0);
  // what the planes keep of the elements
  if(clipGlyphs(opt)) tok.add(CTX::instance()->clipKey(opt->clip));
}

// the clipping planes off while the glyphs are drawn, and back on after
class glyphClip : public gmshClipPlanesOff {
public:
  glyphClip(PViewOptions *opt) : gmshClipPlanesOff(clipGlyphs(opt)) {}
};

// the value a point or a line of a view carries in its normal (what its
// sphere or its cylinder is sized by)
static double normalValue(VertexArray *va, int i)
{
#if defined(HAVE_VISUDEV)
  return *va->getNormalArray(3 * i);
#else
  return char2float(*va->getNormalArray(3 * i));
#endif
}

// the sphere of one point (thread safe: only reads the view)
static void addSphereFor(drawContext *ctx, PViewOptions *opt, VertexArray *va,
                         int i, glyphList *into)
{
  float *pt = va->getVertexArray(3 * i);
  double f = (opt->pointType > 1) ? normalValue(va, i) : 1.;
  unsigned int col;
  memcpy(&col, va->getColorArray(4 * i), 4);
  into->addSphere(ctx, opt->pointSize * f, pt[0], pt[1], pt[2], col);
}

// share a range over the threads, each collecting into its own list, merged
// in order afterwards
template <class F>
static void collect(int num, glyphList *into, F add)
{
  int nthreads = CTX::instance()->numThreads;
  if(nthreads <= 0) nthreads = 1;
  // not worth splitting a handful of glyphs over several threads
  if(num < 2000) nthreads = 1;
  if(nthreads > num) nthreads = num;
  if(nthreads == 1) {
    for(int i = 0; i < num; i++) add(i, into);
    return;
  }
  std::vector<glyphList *> parts(nthreads, nullptr);
#if defined(_OPENMP)
#pragma omp parallel for num_threads(nthreads) schedule(static, 1)
#endif
  for(int t = 0; t < nthreads; t++) {
    int first = (int)((long)num * t / nthreads);
    int last = (int)((long)num * (t + 1) / nthreads);
    glyphList *mine = new glyphList();
    for(int i = first; i < last; i++) add(i, mine);
    parts[t] = mine;
  }
  for(int t = 0; t < nthreads; t++) {
    into->merge(parts[t]);
    delete parts[t];
  }
}

// the cylinder of one line segment (thread safe: only reads the view)
static void addCylinderFor(drawContext *ctx, PViewOptions *opt,
                           VertexArray *va, int i, glyphList *into)
{
  float *p0 = va->getVertexArray(3 * i);
  float *p1 = va->getVertexArray(3 * (i + 1));
  double x[2] = {p0[0], p1[0]}, y[2] = {p0[1], p1[1]}, z[2] = {p0[2], p1[2]};
  double r = opt->lineWidth * ctx->pixel_equiv_x / ctx->s[0];
  double r0 = r, r1 = r;
  if(opt->lineType == 2) {
    // the thickness follows the value at each end
    r0 = normalValue(va, i) * r;
    r1 = normalValue(va, i + 1) * r;
  }
  unsigned int col;
  memcpy(&col, va->getColorArray(4 * i), 4);
  into->addCylinder(x, y, z, r0, r1, col);
}

// the cylinders a view draws its lines with, collected once and kept
static void drawLineGlyphs(drawContext *ctx, PView *p, VertexArray *va,
                           bool clipArray)
{
  PViewOptions *opt = p->getOptions();
  glyphToken tok;
  tok.add(ctx->pixel_equiv_x / ctx->s[0]);
  tok.add(opt->lineWidth);
  tok.add(opt->lineType);
  addClipToken(tok, opt);
  glyphList *g;
  if(!glyphCache::get(p, clipArray ? GLYPH_CLIP_LINES : GLYPH_LINES, tok, g)) {
    int num = va->getNumVertices() / 2;
    g->reserve(GLYPH_CYLINDER, num);
    collect(num, g, [ctx, opt, va, clipArray](int e, glyphList *into) {
      // what the planes add is the right set already
      if(!clipArray && !glyphIsKept(opt, va->getVertexArray(3 * 2 * e),
                                    va->getVertexArray(3 * (2 * e + 1))))
        return;
      addCylinderFor(ctx, opt, va, 2 * e, into);
    });
  }
  g->draw(ctx, opt->light);
}

// the spheres a view draws its points with, collected once and kept
static void drawPointGlyphs(drawContext *ctx, PView *p, VertexArray *va)
{
  PViewOptions *opt = p->getOptions();
  glyphToken tok;
  tok.add(ctx->pixel_equiv_x / ctx->s[0]);
  tok.add(opt->pointSize);
  tok.add(opt->pointType);
  addClipToken(tok, opt);
  glyphList *g;
  if(!glyphCache::get(p, GLYPH_POINTS, tok, g)) {
    g->reserve(GLYPH_SPHERE, va->getNumVertices());
    collect(va->getNumVertices(), g, [ctx, opt, va](int i, glyphList *into) {
      if(!glyphIsKept(opt, va->getVertexArray(3 * i))) return;
      addSphereFor(ctx, opt, va, i, into);
    });
  }
  g->draw(ctx, opt->light);
}

// clipArray says this array holds what the clipping planes add, drawn whole
// and not tested against them again
static void drawArrays(drawContext *ctx, PView *p, VertexArray *va, GLint type,
                       bool useNormalArray, bool clipArray = false)
{
  if(!va || !va->getNumVertices()) return;

  PViewOptions *opt = p->getOptions();

  if(CTX::instance()->polygonOffset || opt->showElement)
    glEnable(GL_POLYGON_OFFSET_FILL);

  if(type == GL_POINTS && opt->pointType > 0) {
    // a sphere is drawn whole or not at all
    glyphClip clip(opt);
    // the spheres are worth keeping: dozens of triangles each
    if(opt->pointType != 2) {
      drawPointGlyphs(ctx, p, va);
      glDisable(GL_POLYGON_OFFSET_FILL);
      gmshLighting(false);
      return;
    }
    // points sized by the value, one at a time
    for(int i = 0; i < va->getNumVertices(); i++) {
      float *pt = va->getVertexArray(3 * i);
      if(!glyphIsKept(opt, pt)) continue;
      gmshColor4ubv((const void *)va->getColorArray(4 * i));
      int s = (int)(opt->pointSize * normalValue(va, i));
      if(s) {
        gmshPointSize((float)s);
        gl2psPointSize((float)(s * CTX::instance()->print.epsPointSizeFactor));
        gmshBegin(GL_POINTS);
        gmshVertex3d(pt[0], pt[1], pt[2]);
        gmshEnd();
      }
    }
  }
  else if(type == GL_LINES && opt->lineType > 0) {
    // as with the spheres above: a cylinder is drawn whole or not at all, and
    // the cylinders are worth keeping
    glyphClip clip(opt);
    drawLineGlyphs(ctx, p, va, clipArray);
  }
  else {

    if(type == GL_LINES && opt->useStipple) {
      gmshLineStipple(opt->stipple[0][0], opt->stipple[0][1]);
      gl2psEnable(GL2PS_LINE_STIPPLE);
    }

    gmshDrawVertexArray(va, type,
                        (useNormalArray ? GMSH_DRAW_LIGHT : 0) |
                          GMSH_DRAW_COLORS);

    if(type == GL_LINES && opt->useStipple) {
      gmshLineStippleOff();
      gl2psDisable(GL2PS_LINE_STIPPLE);
    }

  }

  glDisable(GL_POLYGON_OFFSET_FILL);
  gmshLighting(false);
}

// the ellipse or ellipsoid of the tensor at one point (thread safe: only
// reads the view)
static void addEllipseFor(drawContext *ctx, PViewOptions *opt, VertexArray *va,
                          int i, glyphList *into)
{
  float *s = va->getVertexArray(3 * i);
  double vv[3][3];
  double lmax = opt->tmpMax;
  double scale = (opt->arrowSizeMax - opt->arrowSizeMin) * ctx->pixel_equiv_x /
                 ctx->s[0] / 2;
  double lmin = opt->arrowSizeMin * ctx->pixel_equiv_x / ctx->s[0] / 2;
  for(int j = 0; j < 3; j++) {
    float *v = va->getVertexArray(3 * (i + j + 1));
    double l = std::sqrt((double)v[0] * v[0] + (double)v[1] * v[1] +
                         (double)v[2] * v[2]);
    double l2 = std::min(1., l / lmax);
    // an axis of zero length (a singular tensor, a plane stress) is flat
    for(int k = 0; k < 3; k++) vv[j][k] = l ? v[k] / l * (scale * l2 + lmin) : 0.;
  }
  unsigned int col;
  memcpy(&col, va->getColorArray(4 * i), 4);

  // the axes are the columns of the transform of the unit sphere or disk
  if(opt->tensorType == PViewOptions::Ellipsoid) {
    double m[16] = {vv[0][0], vv[0][1], vv[0][2], 0., vv[1][0], vv[1][1],
                    vv[1][2], 0.,       vv[2][0], vv[2][1], vv[2][2], 0.,
                    s[0],     s[1],     s[2],     1.};
    into->add(GLYPH_SPHERE, m, col);
  }
  else {
    // the third axis of an ellipse is the one the other two span
    double n[3] = {vv[0][1] * vv[1][2] - vv[0][2] * vv[1][1],
                   vv[0][2] * vv[1][0] - vv[0][0] * vv[1][2],
                   vv[0][0] * vv[1][1] - vv[0][1] * vv[1][0]};
    double m[16] = {vv[0][0], vv[0][1], vv[0][2], 0., vv[1][0], vv[1][1],
                    vv[1][2], 0.,       n[0],     n[1], n[2],   0.,
                    s[0],     s[1],     s[2],     1.};
    into->add(GLYPH_DISK, m, col);
  }
}

static void drawEllipseArray(drawContext *ctx, PView *p, VertexArray *va)
{
  if(!va || va->getNumVerticesPerElement() != 4) return;

  PViewOptions *opt = p->getOptions();

  // as with the arrows: an ellipsoid is drawn whole or not at all
  glyphClip clip(opt);

  // the array only holds ellipses and ellipsoids (frames are triangles)
  if(!va->getNumVertices()) return;
  glyphToken tok;
  tok.add(ctx->pixel_equiv_x / ctx->s[0]);
  tok.add(opt->tensorType);
  tok.add(opt->arrowSizeMin);
  tok.add(opt->arrowSizeMax);
  tok.add(opt->tmpMax);
  addClipToken(tok, opt);
  glyphList *g;
  if(!glyphCache::get(p, GLYPH_TENSORS, tok, g)) {
    int num = va->getNumVertices() / 4;
    collect(num, g, [ctx, opt, va](int e, glyphList *into) {
      if(!glyphIsKept(opt, va->getVertexArray(3 * 4 * e))) return;
      addEllipseFor(ctx, opt, va, 4 * e, into);
    });
  }
  g->draw(ctx, opt->light);
}

// where the arrow of the vector v at s goes and how long it is, scaled as
// the options of the view say; false if it is not worth drawing, i.e. zero or
// less than a pixel long, unless it is a comet (vector type 6)
static bool placeArrow(drawContext *ctx, PViewOptions *opt, const float *s,
                       const float *v, double x[3], double d[3])
{
  bool comet = (opt->vectorType == 6);
  double l = sqrt((double)v[0] * v[0] + (double)v[1] * v[1] +
                  (double)v[2] * v[2]);
  double lmax = opt->tmpMax;
  if((!l && !comet) || !lmax) return false;
  double scale = (opt->arrowSizeMax - opt->arrowSizeMin) / lmax;
  if(opt->getScaleType(opt->tmpMin, opt->tmpMax) != PViewOptions::Linear &&
     opt->tmpMax > opt->tmpMin && l != opt->tmpMin) {
    // as long as the arrow, on the scale of the view
    double a = opt->scaleForward(opt->tmpMin, opt->tmpMin, opt->tmpMax);
    double b = opt->scaleForward(opt->tmpMax, opt->tmpMin, opt->tmpMax);
    scale = (opt->arrowSizeMax - opt->arrowSizeMin) / l *
            (opt->scaleForward(l, opt->tmpMin, opt->tmpMax) - a) / (b - a);
  }
  if(opt->arrowSizeMin && l) scale += opt->arrowSizeMin / l;
  double p[3] = {scale * v[0], scale * v[1], scale * v[2]};
  if(!comet && fabs(p[0]) <= 1. && fabs(p[1]) <= 1. && fabs(p[2]) <= 1.)
    return false;
  double f = ctx->pixel_equiv_x / ctx->s[0];
  // hanging from s, centred on it or ending at it
  double c = (opt->centerGlyphs == 2) ? 1. : (opt->centerGlyphs == 1) ? 0.5 : 0.;
  for(int k = 0; k < 3; k++) {
    d[k] = p[k] * f;
    x[k] = c ? s[k] - c * d[k] : s[k];
  }
  return true;
}

// the arrow of one element, appended if worth drawing (thread safe: only
// reads the view)
static void addArrowFor(drawContext *ctx, PViewOptions *opt, VertexArray *va,
                        int i, glyphList *into)
{
  double x[3], d[3];
  if(!placeArrow(ctx, opt, va->getVertexArray(3 * i),
                 va->getVertexArray(3 * (i + 1)), x, d))
    return;
  unsigned int col;
  memcpy(&col, va->getColorArray(4 * i), 4);
  into->addArrow(x[0], x[1], x[2], d[0], d[1], d[2], col);
}

// draw a list of arrows, with the offset of the faces the view asks for
static void drawArrowList(drawContext *ctx, PViewOptions *opt, glyphList *g)
{
  if(CTX::instance()->polygonOffset || opt->showElement)
    glEnable(GL_POLYGON_OFFSET_FILL);
  g->draw(ctx, opt->light);
  glDisable(GL_POLYGON_OFFSET_FILL);
}

static void drawVectorArray(drawContext *ctx, PView *p, VertexArray *va)
{
  if(!va || va->getNumVerticesPerElement() != 2) return;

  PViewOptions *opt = p->getOptions();

  // an arrow is drawn whole or not at all, tested on the point it hangs from
  glyphClip clip(opt);

  // the 3D arrows are worth keeping: dozens of triangles each
  if(opt->vectorType == 4) {
    glyphToken tok;
    tok.add(ctx->pixel_equiv_x / ctx->s[0]);
    tok.add(opt->vectorType);
    // everything addArrowFor() depends on
    tok.add(opt->arrowSizeMin);
    tok.add(opt->arrowSizeMax);
    tok.add(opt->tmpMin);
    tok.add(opt->tmpMax);
    tok.add(opt->scaleType);
    tok.add(opt->scaleThreshold);
    tok.add(opt->centerGlyphs);
    addClipToken(tok, opt);
    glyphList *g;
    if(!glyphCache::get(p, GLYPH_VECTORS, tok, g)) {
      int num = va->getNumVertices() / 2;
      g->reserve(GLYPH_ARROW, num);
      collect(num, g, [ctx, opt, va](int e, glyphList *into) {
        if(!glyphIsKept(opt, va->getVertexArray(3 * 2 * e))) return;
        addArrowFor(ctx, opt, va, 2 * e, into);
      });
    }
    drawArrowList(ctx, opt, g);
    return;
  }

  // The other types are drawn a primitive at a time: recorded once into the
  // list, which is then drawn as a whole (a million flat arrows took 13 s a
  // frame with the shader pipeline, 3 s without).
  glyphToken tok;
  tok.add(ctx->pixel_equiv_x / ctx->s[0]);
  tok.add(opt->vectorType);
  tok.add(opt->intervalsType == PViewOptions::Iso);
  tok.add(opt->arrowSizeMin);
  tok.add(opt->arrowSizeMax);
  tok.add(opt->tmpMin);
  tok.add(opt->tmpMax);
  tok.add(opt->scaleType);
  tok.add(opt->scaleThreshold);
  tok.add(opt->centerGlyphs);
  tok.add(CTX::instance()->arrowRelHeadRadius);
  tok.add(CTX::instance()->arrowRelStemLength);
  tok.add(CTX::instance()->arrowRelStemRadius);
  tok.add(CTX::instance()->color.bg);
  addClipToken(tok, opt);
  glyphList *g;
  if(!glyphCache::get(p, GLYPH_VECTORS, tok, g)) {
    g->recordBegin();
    for(int i = 0; i < va->getNumVertices(); i += 2) {
      float *s = va->getVertexArray(3 * i);
      if(!glyphIsKept(opt, s)) continue;
      gmshColor4ubv((const void *)va->getColorArray(4 * i));
      double x[3], d[3];
      if(!placeArrow(ctx, opt, s, va->getVertexArray(3 * (i + 1)), x, d))
        continue;
      ctx->drawVector(opt->vectorType, opt->intervalsType != PViewOptions::Iso,
                      x[0], x[1], x[2], d[0], d[1], d[2], opt->light);
    }
    g->recordEnd();
  }
  drawArrowList(ctx, opt, g);
}

static std::string stringValue(int numComp, double d[9], double norm,
                               const char *format)
{
  // a field of 2, 4 or 6 components is none of the cases below
  char label[100] = "";
  if(numComp == 1)
    snprintf(label, sizeof(label), format, d[0]);
  else if(numComp == 3) {
    char str[3][32];
    for(int i = 0; i < 3; i++) snprintf(str[i], sizeof(str[i]), format, d[i]);
    snprintf(label, sizeof(label), "(%s,%s,%s)", str[0], str[1], str[2]);
  }
  else if(numComp == 9)
    snprintf(label, sizeof(label), format, norm);
  return std::string(label);
}

// a number at (x, y, z): starting there, centred on it or ending at it
static void drawNumber(drawContext *ctx, PViewOptions *opt, const std::string &s,
                       double x, double y, double z)
{
  int align = (opt->centerGlyphs == 2) ? 2 : (opt->centerGlyphs == 1) ? 1 : 0;
  ctx->drawString(s, x, y, z, CTX::instance()->glFont,
                  CTX::instance()->glFontEnum, CTX::instance()->glFontSize, align);
}

static void drawNumberGlyphs(drawContext *ctx, PView *p, int numNodes,
                             int numComp, double **xyz, double **val)
{
  PViewOptions *opt = p->getOptions();
  double d[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};

  double vmin = opt->tmpMin, vmax = opt->tmpMax;

  if(opt->glyphLocation == PViewOptions::COG) {
    SPoint3 pc(0., 0., 0.);
    for(int i = 0; i < numNodes; i++) {
      pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
      for(int j = 0; j < numComp; j++) d[j] += val[i][j];
    }
    pc /= (double)numNodes;
    for(int j = 0; j < numComp; j++) d[j] /= (double)numNodes;
    double v = ComputeScalarRep(numComp, d);
    if(v >= vmin && v <= vmax) {
      unsigned int col = opt->getColor(v, vmin, vmax, false, opt->nbIso);
      gmshColor4ubv((const void *)&col);
      drawNumber(ctx, opt, stringValue(numComp, d, v, opt->getFormat().c_str()),
                 pc.x(), pc.y(), pc.z());
    }
  }
  else if(opt->glyphLocation == PViewOptions::Vertex) {
    for(int i = 0; i < numNodes; i++) {
      double v = ComputeScalarRep(numComp, val[i]);
      if(v >= vmin && v <= vmax) {
        unsigned int col = opt->getColor(v, vmin, vmax, false, opt->nbIso);
        gmshColor4ubv((const void *)&col);
        drawNumber(ctx, opt,
                   stringValue(numComp, val[i], v, opt->getFormat().c_str()),
                   xyz[i][0], xyz[i][1], xyz[i][2]);
      }
    }
  }
}

static void drawNormalVectorGlyphs(drawContext *ctx, PView *p, int numNodes,
                                   double **xyz)
{
  PViewOptions *opt = p->getOptions();

  SPoint3 pc(0., 0., 0.);
  for(int i = 0; i < numNodes; i++)
    pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
  pc /= (double)numNodes;

  SVector3 t1(xyz[1][0] - xyz[0][0], xyz[1][1] - xyz[0][1],
              xyz[1][2] - xyz[0][2]);
  SVector3 t2(xyz[2][0] - xyz[0][0], xyz[2][1] - xyz[0][1],
              xyz[2][2] - xyz[0][2]);
  SVector3 n = crossprod(t1, t2);
  n.normalize();

  for(int i = 0; i < 3; i++)
    n[i] *= opt->normals * ctx->pixel_equiv_x / ctx->s[i];
  gmshColor4ubv((const void *)&opt->color.normals);
  ctx->drawVector(CTX::instance()->vectorType, 0, pc[0], pc[1], pc[2], n[0],
                  n[1], n[2], opt->light);
}

static void drawTangentVectorGlyphs(drawContext *ctx, PView *p, int numNodes,
                                    double **xyz)
{
  PViewOptions *opt = p->getOptions();

  SPoint3 p0(xyz[0][0], xyz[0][1], xyz[0][2]);
  SPoint3 p1(xyz[1][0], xyz[1][1], xyz[1][2]);
  SVector3 pc = 0.5 * (p0 + p1);
  SVector3 t(p0, p1);
  t.normalize();
  for(int i = 0; i < 3; i++)
    t[i] *= opt->tangents * ctx->pixel_equiv_x / ctx->s[i];
  gmshColor4ubv((const void *)&opt->color.tangents);
  ctx->drawVector(CTX::instance()->vectorType, 0, pc[0], pc[1], pc[2], t[0],
                  t[1], t[2], opt->light);
}

static void drawGlyphs(drawContext *ctx, PView *p)
{
  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  bool arrows = opt->normals || opt->tangents;
  bool numbers = (opt->intervalsType == PViewOptions::Numeric);
  if(!arrows && !numbers) return;

  // a number or a normal is drawn whole or not at all, like the other glyphs
  glyphClip clip(opt);

  // The normals and tangents are recorded once and drawn as a whole
  // afterwards (a change of any option of the view drops them); the numbers
  // are strings, drawn every time.
  glyphList *g = nullptr;
  bool record = false;
  if(arrows) {
    glyphToken tok;
    // the arrows are scaled per axis
    for(int i = 0; i < 3; i++) tok.add(ctx->pixel_equiv_x / ctx->s[i]);
    // the options that do not mark the view as changed
    tok.add(opt->normals);
    tok.add(opt->tangents);
    tok.add(opt->color.normals);
    tok.add(opt->color.tangents);
    tok.add(CTX::instance()->vectorType);
    tok.add(CTX::instance()->arrowRelHeadRadius);
    tok.add(CTX::instance()->arrowRelStemLength);
    tok.add(CTX::instance()->arrowRelStemRadius);
    addClipToken(tok, opt);
    if(glyphCache::get(p, GLYPH_NORMALS, tok, g)) {
      g->draw(ctx, opt->light);
      arrows = false;
      if(!numbers) return;
    }
    else
      record = true;
  }

  Msg::Debug("drawing extra glyphs (this is slow...)");

  // The arrows are recorded on a walk of their own, before the numbers are
  // drawn: the strings would otherwise be recorded with them (the shader
  // pipeline draws them through the same immediate mode path), and replayed
  // as huge quads without the projection of the text.
  PViewElement el;
  auto walk = [&](bool numbersNow, bool arrowsNow) {
    for(int ent = 0; ent < data->getNumEntities(opt->timeStep); ent++) {
      if(data->skipEntity(opt->timeStep, ent)) continue;
      for(int i = 0; i < data->getNumElements(opt->timeStep, ent); i++) {
        if(!el.select(p, ent, i)) continue;
        int dim = el.dim;
        // a normal is drawn for a surface element, a tangent for a line:
        // the others are not worth reading (this runs at every frame, and a
        // view of a million tetrahedra with normals on took a quarter of a
        // second to draw none)
        bool normal = arrowsNow && dim == 2 && opt->normals;
        bool tangent = arrowsNow && dim == 1 && opt->tangents;
        if(!numbersNow && !normal && !tangent) continue;
        el.read(p);
        // drawn straight from the elements: whole element mode applies here
        if(!elementIsKept(opt, dim, el.numNodes, el.xyz)) continue;
        if(numbersNow)
          drawNumberGlyphs(ctx, p, el.numNodes, el.numComp, el.xyz, el.val);
        if(normal)
          drawNormalVectorGlyphs(ctx, p, el.numNodes, el.xyz);
        else if(tangent)
          drawTangentVectorGlyphs(ctx, p, el.numNodes, el.xyz);
      }
    }
  };
  if(record) {
    g->recordBegin();
    walk(false, true);
    g->recordEnd();
    g->draw(ctx, opt->light);
  }
  if(numbers) walk(true, false);
}

static bool eyeChanged(drawContext *ctx, PView *p)
{
  double zeye = 100 * CTX::instance()->lc;
  SPoint3 tmp(ctx->rot[2] * zeye, ctx->rot[6] * zeye, ctx->rot[10] * zeye);
  // a fraction of the distance to the eye: an absolute tolerance never
  // sorted a small model again, and sorted a large one at every frame
  if(tmp.distance(p->getEye()) > 1.e-5 * zeye) {
    p->setEye(tmp);
    return true;
  }
  return false;
}

// does this view have to be blended with what is behind it? (a "fake"
// transparency view is additive and unordered already)
bool gmshViewIsTransparent(PView *p)
{
  PViewOptions *opt = p->getOptions();
  if(!CTX::instance()->alpha) return false;
  // an alpha in the colormap, or the factor the shader applies
  return ColorTable_IsAlpha(&opt->colorTable) ||
         (gmshUseShaders() && opt->transparency < 1.);
}

class drawPView {
public:
  // which views this pass draws (not OPAQUE and TRANSPARENT: windows.h has
  // macros of both names)
  enum whichViews { ALL_VIEWS, OPAQUE_VIEWS, TRANSPARENT_VIEWS };

private:
  drawContext *_ctx;
  whichViews _which;

public:
  drawPView(drawContext *ctx, whichViews which = ALL_VIEWS)
    : _ctx(ctx), _which(which)
  {
  }
  void operator()(PView *p)
  {
    // use adaptive data if available
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();

    if(data->getDirty() || !data->getNumTimeSteps()) return;
    if(!opt->visible || opt->type != PViewOptions::Plot3D) return;
    if(!_ctx->isVisible(p)) return;
    if(_which != ALL_VIEWS &&
       (gmshViewIsTransparent(p) != (_which == TRANSPARENT_VIEWS)))
      return;

    if(_ctx->render_mode == drawContext::GMSH_SELECT) {
      _ctx->setPickColor(5, p->getIndex());
    }

    gmshPointSize((float)opt->pointSize);
    gl2psPointSize(
      (float)(opt->pointSize * CTX::instance()->print.epsPointSizeFactor));

    gmshLineWidth((float)opt->lineWidth);
    gl2psLineWidth(
      (float)(opt->lineWidth * CTX::instance()->print.epsLineWidthFactor));

    if(opt->axes) {
      gmshColor4ubv((const void *)&opt->color.axes);
      gmshLineWidth((float)CTX::instance()->lineWidth);
      gl2psLineWidth((float)(CTX::instance()->lineWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      if(!opt->axesAutoPosition)
        _ctx->drawAxes(opt->axes, opt->axesTicks, opt->axesFormat,
                       opt->axesLabel, opt->axesPosition, opt->axesMikado,
                       opt->axesPosition);
      else if(!opt->tmpBBox.empty())
        _ctx->drawAxes(opt->axes, opt->axesTicks, opt->axesFormat,
                       opt->axesLabel, opt->tmpBBox, opt->axesMikado,
                       opt->tmpBBox);
    }

    // OpenGL applies the planes to the view's arrays, and what they add is
    // drawn from its own arrays with them off; the mode that draws only the
    // cut volumes fills the view's arrays through the planes and draws them
    // whole
    CTX *c = CTX::instance();
    bool cutOnly = c->clipWholeElements && opt->clip &&
                   c->clipOnlyDrawIntersectingVolume;
    bool whole = clipGlyphs(opt); // whole element mode, other than cutOnly
    setViewClipPlanes(opt, !cutOnly);

    // a transparent view is blended back to front, unless the transparency
    // pass sums it in any order with its own blending
    bool blend = gmshViewIsTransparent(p) && !glShader::transparentPass();
    if(blend) {
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_BLEND);
      if(p->va_triangles && p->va_triangles->getNumVertices() &&
         eyeChanged(_ctx, p)) {
        Msg::Debug("Sorting View[%d] for transparency", p->getIndex());
        p->va_triangles->sort(p->getEye().x(), p->getEye().y(),
                              p->getEye().z());
      }
    }

    // (not perfect for multi-step adaptive views, which do not know the
    // range of the other steps)
    opt->getRange(data, opt->tmpMin, opt->tmpMax);

    // draw all the vertex arrays
    gmshLightTwoSide(false);
    gmshAlphaScale(_ctx->inPickColorMode() ? 1. : opt->transparency, false);

    drawArrays(_ctx, p, p->va_points, GL_POINTS, false);
    drawArrays(_ctx, p, p->va_lines, GL_LINES, opt->light && opt->lightLines);

    // the outlines of the cut elements, on the side the planes cut off
    if(whole) {
      setViewClipOutside(opt, true);
      drawArrays(_ctx, p, p->va_clip_lines, GL_LINES,
                 opt->light && opt->lightLines, true);
      setViewClipOutside(opt, false);
    }

    if(opt->lightTwoSide) gmshLightTwoSide(true);

    drawArrays(_ctx, p, p->va_triangles, GL_TRIANGLES, opt->light);

    // what the clipping planes add: in capping mode the section they cut,
    // clipped like everything else; in whole element mode the cut elements,
    // on the side the planes cut off
    if(whole) setViewClipOutside(opt, true);
    drawArrays(_ctx, p, p->va_clip_triangles, GL_TRIANGLES, opt->light, true);
    if(whole) setViewClipOutside(opt, false);

    // draw the "pseudo" vertex arrays for vectors
    drawVectorArray(_ctx, p, p->va_vectors);
    drawEllipseArray(_ctx, p, p->va_ellipses);

    // the numbers, normals and tangents, read from the elements
    drawGlyphs(_ctx, p);

    // draw the 3D strings
    if(opt->drawStrings) {
      gmshColor4ubv((const void *)&opt->color.text3d);
      for(int i = 0; i < data->getNumStrings3D(); i++) {
        double x, y, z, style;
        std::string str;
        data->getString3D(i, opt->timeStep, str, x, y, z, style);
        _ctx->drawString(str, x, y, z, style);
      }
    }

    if(blend) {
      glDisable(GL_BLEND);
      gmshDepthTest(true);
    }

    gmshAlphaScale(1., false);

    gmshClipPlanesOn(0);

    if(_ctx->render_mode == drawContext::GMSH_SELECT) _ctx->unsetPickColor();
  }
};

class drawPViewBoundingBox {
private:
  drawContext *_ctx;

public:
  drawPViewBoundingBox(drawContext *ctx) : _ctx(ctx) {}
  void operator()(PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(!opt->visible || opt->type != PViewOptions::Plot3D) return;

    SBoundingBox3d bb = data->getBoundingBox(opt->timeStep);
    if(bb.empty()) return;

    gmshColor4ubv((const void *)&CTX::instance()->color.fg);
    gmshLineWidth((float)CTX::instance()->lineWidth);
    gl2psLineWidth((float)(CTX::instance()->lineWidth *
                           CTX::instance()->print.epsLineWidthFactor));

    _ctx->drawBox(bb.min().x(), bb.min().y(), bb.min().z(), bb.max().x(),
                  bb.max().y(), bb.max().z());
    gmshColor3d(1., 0., 0.);
    for(int i = 0; i < 6; i++)
      if(opt->clip & (1 << i))
        _ctx->drawPlaneInBoundingBox(
          bb.min().x(), bb.min().y(), bb.min().z(), bb.max().x(), bb.max().y(),
          bb.max().z(), CTX::instance()->clipPlane[i][0],
          CTX::instance()->clipPlane[i][1], CTX::instance()->clipPlane[i][2],
          CTX::instance()->clipPlane[i][3]);
  }
};

// Each view is drawn from vertex arrays built when its data or the options
// that shape it change (PView::fillVertexArrays()): a redraw only issues them,
// sorting the transparent triangles again when the eye has moved. The glyphs
// (arrows, normals and tangents, spheres...) are expanded through the glyph
// cache, the numbers are drawn as strings at every frame, and what the
// clipping planes add has arrays of its own, so that moving a plane only
// rebuilds those.
void drawContext::drawPost()
{
  // draw any plugin-specific stuff
  if(GMSH_Plugin::draw) (*GMSH_Plugin::draw)(this);

  if(PView::list.empty()) return;

  if(CTX::instance()->drawBBox || !CTX::instance()->post.draw)
    std::for_each(PView::list.begin(), PView::list.end(),
                  drawPViewBoundingBox(this));

  if(!CTX::instance()->post.draw) return;

  for(std::size_t i = 0; i < PView::list.size(); i++) {
    bool changed = PView::list[i]->fillVertexArrays();
    // what the planes add is built on its own
    if(changed) PView::list[i]->invalidateClipVertexArrays();
    PView::list[i]->fillClipVertexArrays();
    if(changed) {
      Msg::Debug("post-pro vertex arrays have changed");
      clearGlyphArrays(PView::list[i]);
    }
    // the strings of the arrays that changed are drawn again
    if(changed) global()->resetFontTextures();
  }

  // draw3d() draws the opaque part of the scene, then the transparent one
  drawPView::whichViews which =
    (transparencyPass == TRANSPARENCY_OPAQUE) ?
      drawPView::OPAQUE_VIEWS :
      ((transparencyPass == TRANSPARENCY_TRANSPARENT) ?
         drawPView::TRANSPARENT_VIEWS : drawPView::ALL_VIEWS);
  std::for_each(PView::list.begin(), PView::list.end(), drawPView(this, which));
}

// whether any view would be drawn in the transparent pass
bool gmshAnyViewIsTransparent()
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(gmshViewIsTransparent(PView::list[i])) return true;
  return false;
}
