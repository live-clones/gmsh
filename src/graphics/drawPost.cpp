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
#include <map>
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
  for(int i = 0; i < 6; i++)
    gmshClipPlaneOn(i, on && (opt->clip & (1 << i)));
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
  CTX *ctx = CTX::instance();
  for(int clip = 0; clip < 6; clip++) {
    if(!(opt->clip & (1 << clip))) continue;
    const double *e = ctx->clipPlane[clip];
    double d0 = e[0] * p0[0] + e[1] * p0[1] + e[2] * p0[2] + e[3];
    if(p1) {
      double d1 = e[0] * p1[0] + e[1] * p1[1] + e[2] * p1[2] + e[3];
      if(d0 < 0. && d1 < 0.) return false;
    }
    else if(d0 < 0.)
      return false;
  }
  return true;
}

// what the kept glyphs depend on
static void addClipToken(glyphToken &tok, PViewOptions *opt)
{
  tok.add(clipGlyphs(opt) ? opt->clip : 0);
  if(!clipGlyphs(opt)) return;
  for(int i = 0; i < 6; i++)
    if(opt->clip & (1 << i))
      for(int j = 0; j < 4; j++) tok.add(CTX::instance()->clipPlane[i][j]);
}

// the clipping planes off while the glyphs are drawn, and back on after
class glyphClip {
private:
  PViewOptions *_opt;
  bool _off;

public:
  glyphClip(PViewOptions *opt) : _opt(opt), _off(clipGlyphs(opt))
  {
    if(_off) setViewClipPlanes(_opt, false);
  }
  ~glyphClip()
  {
    if(_off) setViewClipPlanes(_opt, true);
  }
};

// the sphere of one point (thread safe: only reads the view)
static void addSphereFor(drawContext *ctx, PViewOptions *opt, VertexArray *va,
                         int i, glyphList *into)
{
  float *pt = va->getVertexArray(3 * i);
  double f = 1.;
  if(opt->pointType > 1) {
#if defined(HAVE_VISUDEV)
    f = *va->getNormalArray(3 * i);
#else
    char *n = va->getNormalArray(3 * i);
    f = char2float(*n);
#endif
  }
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
#if defined(HAVE_VISUDEV)
    double v0 = *va->getNormalArray(3 * i);
    double v1 = *va->getNormalArray(3 * (i + 1));
#else
    char *n0 = va->getNormalArray(3 * i);
    char *n1 = va->getNormalArray(3 * (i + 1));
    double v0 = char2float(*n0), v1 = char2float(*n1);
#endif
    r0 = v0 * r;
    r1 = v1 * r;
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
    (void)clipArray; // no array of points is held apart
    // the spheres are worth keeping: dozens of triangles each
    if(opt->pointType != 2 && va->getNumVertices()) {
      drawPointGlyphs(ctx, p, va);
      glDisable(GL_POLYGON_OFFSET_FILL);
      gmshLighting(false);
      return;
    }
    for(int i = 0; i < va->getNumVertices(); i++) {
      float *p = va->getVertexArray(3 * i);
      if(!glyphIsKept(opt, p)) continue;
      gmshColor4ubv((const void *)va->getColorArray(4 * i));
      double f = 1.;
      if(opt->pointType > 1) {
#if defined(HAVE_VISUDEV)
        f = *va->getNormalArray(3 * i);
#else
        char *n = va->getNormalArray(3 * i);
        f = char2float(*n);
#endif
      }
      if(opt->pointType == 2) {
        int s = (int)(opt->pointSize * f);
        if(s) {
          gmshPointSize((float)s);
          gl2psPointSize(
            (float)(s * CTX::instance()->print.epsPointSizeFactor));
          gmshBegin(GL_POINTS);
          gmshVertex3d(p[0], p[1], p[2]);
          gmshEnd();
        }
      }
      else
        ctx->drawSphere(opt->pointSize * f, p[0], p[1], p[2], opt->light);
    }
  }
  else if(type == GL_LINES && opt->lineType > 0) {
    // as with the spheres above: a cylinder is drawn whole or not at all
    glyphClip clip(opt);
    // the cylinders are worth keeping: dozens of triangles each
    if(opt->lineType <= 2 && va->getNumVertices()) {
      drawLineGlyphs(ctx, p, va, clipArray);
      glDisable(GL_POLYGON_OFFSET_FILL);
      gmshLighting(false);
      return;
    }
    for(int i = 0; i < va->getNumVertices(); i += 2) {
      float *p0 = va->getVertexArray(3 * i);
      float *p1 = va->getVertexArray(3 * (i + 1));
      if(!clipArray && !glyphIsKept(opt, p0, p1)) continue;
      double x[2] = {p0[0], p1[0]}, y[2] = {p0[1], p1[1]},
             z[2] = {p0[2], p1[2]};
      gmshColor4ubv((const void *)va->getColorArray(4 * i));
      if(opt->lineType == 2) {
#if defined(HAVE_VISUDEV)
        double v0 = *va->getNormalArray(3 * i);
        double v1 = *va->getNormalArray(3 * (i + 1));
#else
        char *n0 = va->getNormalArray(3 * i);
        char *n1 = va->getNormalArray(3 * (i + 1));
        double v0 = char2float(*n0), v1 = char2float(*n1);
#endif
        ctx->drawTaperedCylinder(opt->lineWidth, v0, v1, 0., 1., x, y, z,
                                 opt->light);
      }
      else if(opt->lineType == 1)
        ctx->drawCylinder(opt->lineWidth, x, y, z, opt->light);
      else { // 2D (for now) MNT diagrams for frames
        float l = std::sqrt((p0[0] - p1[0]) * (p0[0] - p1[0]) +
                            (p0[1] - p1[1]) * (p0[1] - p1[1]) +
                            (p0[2] - p1[2]) * (p0[2] - p1[2]));
#if defined(HAVE_VISUDEV)
        double v0 = *va->getNormalArray(3 * i);
        double v1 = *va->getNormalArray(3 * (i + 1));
#else
        char *n0 = va->getNormalArray(3 * i);
        char *n1 = va->getNormalArray(3 * (i + 1));
        double v0 = char2float(*n0), v1 = char2float(*n1);
#endif
        float dir[3] = {(p1[0] - p0[0]) / l, (p1[1] - p0[1]) / l,
                        (p1[2] - p0[2]) / l};
        //printf("%g %g %g %g %g %g\n", v0, v1, p0[0], p0[1], p1[0], p1[1]);
        ctx->drawVector(1, 0, p0[0] - dir[1] * v0, p0[1] + dir[0] * v0, 0.0,
                        p1[0] - dir[1] * v1, p1[1] + dir[0] * v1, 0.0,
                        opt->light);
      }
    }
  }
  else {

    if(type == GL_LINES && opt->useStipple) {
      gmshLineStipple(opt->stipple[0][0], opt->stipple[0][1]);
      gl2psEnable(GL2PS_LINE_STIPPLE);
    }

    bool normals =
      !ctx->inPickColorMode() && useNormalArray && va->hasNormals();
    if(normals) gmshLighting(true);
    bool colors = !ctx->inPickColorMode() && va->hasColors();
    gmshBindVertexArray(va, normals, colors);
    drawVertexArray(va, type);
    gmshUnbindArrays();

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
    for(int k = 0; k < 3; k++) vv[j][k] = v[k] / l * (scale * l2 + lmin);
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

  // ellipses and ellipsoids are glyphs; frames are still drawn one at a time
  if(opt->tensorType != PViewOptions::Frame && va->getNumVertices()) {
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
    return;
  }

  for(int i = 0; i < va->getNumVertices(); i += 4) {
    float *s = va->getVertexArray(3 * i);
    if(!glyphIsKept(opt, s)) continue;
    float vv[3][3];
    double lmax = opt->tmpMax;
    double scale = (opt->arrowSizeMax - opt->arrowSizeMin) *
                   ctx->pixel_equiv_x / ctx->s[0] / 2;
    double lmin = opt->arrowSizeMin * ctx->pixel_equiv_x / ctx->s[0] / 2;
    for(int j = 0; j < 3; j++) {
      float *v = va->getVertexArray(3 * (i + j + 1));
      double l = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
      double l2 = std::min(1., l / lmax);
      for(int k = 0; k < 3; k++) { vv[j][k] = v[k] / l * (scale * l2 + lmin); }
    }
    gmshColor4ubv((const void *)va->getColorArray(4 * i));

    ctx->drawCube(s[0], s[1], s[2], vv[0], vv[1], vv[2], opt->light);
  }
}

// the arrow of one element, appended if worth drawing; shared with the
// drawing loop below (thread safe: only reads the view)
static void addArrowFor(drawContext *ctx, PViewOptions *opt, VertexArray *va,
                        int i, glyphList *into)
{
  float *s = va->getVertexArray(3 * i);
  float *v = va->getVertexArray(3 * (i + 1));
  double l = sqrt((double)v[0] * v[0] + (double)v[1] * v[1] +
                  (double)v[2] * v[2]);
  double lmax = opt->tmpMax;
  if(!l || !lmax) return;
  double scale = (opt->arrowSizeMax - opt->arrowSizeMin) / lmax;
  if(opt->scaleType == PViewOptions::Logarithmic && opt->tmpMin > 0 &&
     opt->tmpMax > opt->tmpMin && l != opt->tmpMin) {
    scale = (opt->arrowSizeMax - opt->arrowSizeMin) / l *
            log10(l / opt->tmpMin) / log10(opt->tmpMax / opt->tmpMin);
  }
  if(opt->arrowSizeMin && l) scale += opt->arrowSizeMin / l;
  double px = scale * v[0], py = scale * v[1], pz = scale * v[2];
  // only draw vectors larger than one pixel on screen
  if(fabs(px) <= 1. && fabs(py) <= 1. && fabs(pz) <= 1.) return;
  double d = ctx->pixel_equiv_x / ctx->s[0];
  double dx = px * d, dy = py * d, dz = pz * d;
  double x = s[0], y = s[1], z = s[2];
  if(opt->centerGlyphs == 2) {
    x -= dx;
    y -= dy;
    z -= dz;
  }
  else if(opt->centerGlyphs == 1) {
    x -= 0.5 * dx;
    y -= 0.5 * dy;
    z -= 0.5 * dz;
  }
  unsigned int col;
  memcpy(&col, va->getColorArray(4 * i), 4);
  into->addArrow(x, y, z, dx, dy, dz, col);
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
    if(CTX::instance()->polygonOffset || opt->showElement)
      glEnable(GL_POLYGON_OFFSET_FILL);
    g->draw(ctx, opt->light);
    glDisable(GL_POLYGON_OFFSET_FILL);
    return;
  }

  for(int i = 0; i < va->getNumVertices(); i += 2) {
    float *s = va->getVertexArray(3 * i);
    float *v = va->getVertexArray(3 * (i + 1));
    if(!glyphIsKept(opt, s)) continue;
    gmshColor4ubv((const void *)va->getColorArray(4 * i));
    double vv[3] = {v[0], v[1], v[2]};
    double l = sqrt(vv[0] * vv[0] + vv[1] * vv[1] + vv[2] * vv[2]);
    double lmax = opt->tmpMax;
    if((l || opt->vectorType == 6) && lmax) {
      double scale = (opt->arrowSizeMax - opt->arrowSizeMin) / lmax;
      // log scaling
      if(opt->scaleType == PViewOptions::Logarithmic && opt->tmpMin > 0 &&
         opt->tmpMax > opt->tmpMin && l != opt->tmpMin) {
        scale = (opt->arrowSizeMax - opt->arrowSizeMin) / l *
                log10(l / opt->tmpMin) / log10(opt->tmpMax / opt->tmpMin);
      }
      if(opt->arrowSizeMin && l) scale += opt->arrowSizeMin / l;
      double px = scale * v[0];
      double py = scale * v[1];
      double pz = scale * v[2];
      // only draw vectors larger than 1 pixel on screen, except when
      // drawing "comet" glyphs
      if(opt->vectorType == 6 || fabs(px) > 1. || fabs(py) > 1. ||
         fabs(pz) > 1.) {
        double d = ctx->pixel_equiv_x / ctx->s[0];
        double dx = px * d, dy = py * d, dz = pz * d;
        double x = s[0], y = s[1], z = s[2];
        if(opt->centerGlyphs == 2) {
          x -= dx;
          y -= dy;
          z -= dz;
        }
        else if(opt->centerGlyphs == 1) {
          x -= 0.5 * dx;
          y -= 0.5 * dy;
          z -= 0.5 * dz;
        }
        ctx->drawVector(opt->vectorType,
                        opt->intervalsType != PViewOptions::Iso, x, y, z, dx,
                        dy, dz, opt->light);
      }
    }
  }

}

static std::string stringValue(int numComp, double d[9], double norm,
                               const char *format)
{
  char label[100];
  if(numComp == 1)
    sprintf(label, format, d[0]);
  else if(numComp == 3) {
    char str[3][32];
    sprintf(str[0], format, d[0]);
    sprintf(str[1], format, d[1]);
    sprintf(str[2], format, d[2]);
    sprintf(label, "(%s,%s,%s)", str[0], str[1], str[2]);
  }
  else if(numComp == 9)
    sprintf(label, format, norm);
  return std::string(label);
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
      if(opt->centerGlyphs == 2)
        ctx->drawStringRight(stringValue(numComp, d, v, opt->getFormat().c_str()),
                             pc.x(), pc.y(), pc.z());
      else if(opt->centerGlyphs == 1)
        ctx->drawStringCenter(stringValue(numComp, d, v, opt->getFormat().c_str()),
                              pc.x(), pc.y(), pc.z());
      else
        ctx->drawString(stringValue(numComp, d, v, opt->getFormat().c_str()), pc.x(),
                        pc.y(), pc.z());
    }
  }
  else if(opt->glyphLocation == PViewOptions::Vertex) {
    for(int i = 0; i < numNodes; i++) {
      double v = ComputeScalarRep(numComp, val[i]);
      if(v >= vmin && v <= vmax) {
        unsigned int col = opt->getColor(v, vmin, vmax, false, opt->nbIso);
        gmshColor4ubv((const void *)&col);
        if(opt->centerGlyphs == 2)
          ctx->drawStringRight(
            stringValue(numComp, val[i], v, opt->getFormat().c_str()), xyz[i][0],
            xyz[i][1], xyz[i][2]);
        else if(opt->centerGlyphs == 1)
          ctx->drawStringCenter(
            stringValue(numComp, val[i], v, opt->getFormat().c_str()), xyz[i][0],
            xyz[i][1], xyz[i][2]);
        else
          ctx->drawString(stringValue(numComp, val[i], v, opt->getFormat().c_str()),
                          xyz[i][0], xyz[i][1], xyz[i][2]);
      }
    }
  }
}

static void drawNormalVectorGlyphs(drawContext *ctx, PView *p, int numNodes,
                                   double **xyz, double **val)
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
                                    double **xyz, double **val)
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
  static int numNodesError = 0;

  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  if(!opt->normals && !opt->tangents &&
     opt->intervalsType != PViewOptions::Numeric)
    return;

  Msg::Debug("drawing extra glyphs (this is slow...)");

  // a number or a normal is drawn whole or not at all, like the other glyphs
  glyphClip clip(opt);

  // speedup drawing of textured fonts on cocoa mac version
#if defined(__APPLE__)
  if(opt->intervalsType == PViewOptions::Numeric) {
    int numStrings = 0;
    for(int ent = 0; ent < data->getNumEntities(opt->timeStep); ent++)
      numStrings += data->getNumElements(opt->timeStep, ent);
    drawContext::global()->reserveStringTextures(numStrings);
  }
#endif

  // double xyz[PVIEW_NMAX][3], val[PVIEW_NMAX][9];
  int NMAX = PVIEW_NMAX;
  double **xyz = new double *[NMAX];
  double **val = new double *[NMAX];
  for(int i = 0; i < NMAX; i++) {
    xyz[i] = new double[3];
    val[i] = new double[9];
  }
  for(int ent = 0; ent < data->getNumEntities(opt->timeStep); ent++) {
    if(data->skipEntity(opt->timeStep, ent)) continue;
    for(int i = 0; i < data->getNumElements(opt->timeStep, ent); i++) {
      if(data->skipElement(opt->timeStep, ent, i, true, opt->sampling))
        continue;
      int type = data->getType(opt->timeStep, ent, i);
      if(opt->skipElement(type)) continue;
      int dim = data->getDimension(opt->timeStep, ent, i);
      int numComp = data->getNumComponents(opt->timeStep, ent, i);
      int numNodes = data->getNumNodes(opt->timeStep, ent, i);
      if(numNodes > NMAX) {
        if(type == TYPE_POLYG || type == TYPE_POLYH) {
          for(int j = 0; j < NMAX; j++) {
            delete[] xyz[i];
            delete[] val[i];
          }
          delete[] xyz;
          delete[] val;
          NMAX = numNodes;
          xyz = new double *[NMAX];
          val = new double *[NMAX];
          for(int j = 0; j < NMAX; j++) {
            xyz[j] = new double[3];
            val[j] = new double[9];
          }
        }
        else {
          if(numNodesError != numNodes) {
            numNodesError = numNodes;
            Msg::Warning(
              "Fields with %d nodes per element cannot be displayed: "
              "either force the field type or select 'Adapt visualization "
              "grid' if the field is high-order",
              numNodes);
          }
          continue;
        }
      }
      for(int j = 0; j < numNodes; j++) {
        data->getNode(opt->timeStep, ent, i, j, xyz[j][0], xyz[j][1],
                      xyz[j][2]);
        if(opt->forceNumComponents) {
          for(int k = 0; k < opt->forceNumComponents; k++) {
            int comp = opt->componentMap[k];
            if(comp >= 0 && comp < numComp)
              data->getValue(opt->timeStep, ent, i, j, comp, val[j][k]);
            else
              val[j][k] = 0.;
          }
        }
        else
          for(int k = 0; k < numComp; k++)
            data->getValue(opt->timeStep, ent, i, j, k, val[j][k]);
      }
      if(opt->forceNumComponents) numComp = opt->forceNumComponents;
      changeCoordinates(p, ent, i, numNodes, type, numComp, xyz, val);
      // drawn straight from the elements: whole element mode applies here
      if(!elementIsKept(opt, dim, numNodes, xyz)) continue;
      if(opt->intervalsType == PViewOptions::Numeric)
        drawNumberGlyphs(ctx, p, numNodes, numComp, xyz, val);
      if(dim == 2 && opt->normals)
        drawNormalVectorGlyphs(ctx, p, numNodes, xyz, val);
      else if(dim == 1 && opt->tangents)
        drawTangentVectorGlyphs(ctx, p, numNodes, xyz, val);
    }
  }
  for(int j = 0; j < NMAX; j++) {
    delete[] xyz[j];
    delete[] val[j];
  }
  delete[] xyz;
  delete[] val;
}

static bool eyeChanged(drawContext *ctx, PView *p)
{
  double zeye = 100 * CTX::instance()->lc;
  SPoint3 tmp(ctx->rot[2] * zeye, ctx->rot[6] * zeye, ctx->rot[10] * zeye);
  if(tmp.distance(p->getEye()) > 1.e-3) {
    p->setEye(tmp);
    return true;
  }
  return false;
}

// does this view have to be blended with what is behind it? (a "fake"
// transparency view is additive and unordered already)
static bool viewIsTransparent(PView *p)
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
       (viewIsTransparent(p) != (_which == TRANSPARENT_VIEWS)))
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

    if(opt->axes && opt->type == PViewOptions::Plot3D) {
      gmshColor4ubv((const void *)&opt->color.axes);
      gmshLineWidth((float)CTX::instance()->lineWidth);
      gl2psLineWidth((float)(CTX::instance()->lineWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      if(!opt->axesAutoPosition)
        _ctx->drawAxes(opt->axes, opt->axesTics, opt->axesFormat,
                       opt->axesLabel, opt->axesPosition, opt->axesMikado,
                       opt->axesPosition);
      else if(!opt->tmpBBox.empty())
        _ctx->drawAxes(opt->axes, opt->axesTics, opt->axesFormat,
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
    bool whole = c->clipWholeElements && opt->clip && !cutOnly;
    setViewClipPlanes(opt, !cutOnly);

    if(CTX::instance()->alpha && ColorTable_IsAlpha(&opt->colorTable)) {
      if(glShader::transparentPass()) {
        // the transparency pass sums in any order, with its own blending
      }
      else {
        // real translucent blending (requires back-to-front traversal)
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        // glBlendEquation(GL_FUNC_ADD);
        glEnable(GL_BLEND);
        if(p->va_triangles && p->va_triangles->getNumVertices() &&
           eyeChanged(_ctx, p)) {
          Msg::Debug("Sorting View[%d] for transparency", p->getIndex());
          p->va_triangles->sort(p->getEye().x(), p->getEye().y(),
                                p->getEye().z());
        }
      }
    }

    if(opt->rangeType == PViewOptions::Custom) {
      opt->tmpMin = opt->customMin;
      opt->tmpMax = opt->customMax;
    }
    else if(opt->rangeType == PViewOptions::PerTimeStep) {
      opt->tmpMin = data->getMin(opt->timeStep);
      opt->tmpMax = data->getMax(opt->timeStep);
    }
    else {
      // FIXME: this is not perfect for multi-step adaptive views, as
      // we don't have the correct min/max info for the other steps
      opt->tmpMin = data->getMin();
      opt->tmpMax = data->getMax();
    }

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

    // to avoid looping over elements (and to enable drawing glyphs
    // for remote views) we should also store these glyphs in "pseudo"
    // vertex arrays
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

    if(CTX::instance()->alpha && !glShader::transparentPass()) {
      glDisable(GL_BLEND);
      glEnable(GL_DEPTH_TEST);
    }

    gmshAlphaScale(1., false);

    for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);

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
#if defined(__APPLE__)
    // FIXME: resetting texture pile fixes bug with recent macOS versions
    if(changed) global()->resetFontTextures();
#endif
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
bool drawContext::anyViewIsTransparent()
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(viewIsTransparent(PView::list[i])) return true;
  return false;
}
