// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "drawContext.h"
#include "GModelVertexArrays.h"
#include "Context.h"
#include "OwnerCache.h"

#include "gl2ps.h"
#include "VertexArray.h"
#include "GModel.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "StringUtils.h"
#include "glyphList.h"
#include "glImmediate.h"

// the label of an entity (those shown by the selection in the foreground
// colour)
static void drawEntityLabel(drawContext *ctx, GEntity *e, double x, double y,
                            double z, double offset)
{
  if(e->getSelection() == GEntity::SelectShow)
    gmshColor4ubv((const void *)&CTX::instance()->color.fg);
  double xx = x + offset / ctx->s[0];
  double yy = y + offset / ctx->s[1];
  double zz = z + offset / ctx->s[2];

  // the names are the user's, of any length: the label is built as a string
  // rather than into a buffer it could run past
  std::string str;
  char tmp[64];
  switch(CTX::instance()->geom.labelType) {
  case 5:
    snprintf(tmp, sizeof(tmp), "(%g,%g,%g)", x, y, z);
    str = tmp;
    break;
  case 4:
    for(std::size_t i = 0; i < e->physicals.size(); i++) {
      std::string name =
        e->model()->getPhysicalName(e->dim(), std::abs(e->physicals[i]));
      if(name.empty()) continue;
      if(str.size()) str += ", ";
      str += name;
    }
    break;
  case 3:
    str = e->model()->getElementaryName(e->dim(), e->tag());
    break;
  case 2:
    for(std::size_t i = 0; i < e->physicals.size(); i++) {
      if(i) str += ", ";
      snprintf(tmp, sizeof(tmp), "%d", e->physicals[i]);
      str += tmp;
    }
    break;
  case 1:
    snprintf(tmp, sizeof(tmp), "%d", e->tag());
    str = tmp;
    break;
  case 0:
  default:
    {
      std::vector<std::string> info =
        SplitString(e->getInfoString(false, true), '\n');
      for(int line = 0; line < (int)info.size(); line++)
        ctx->drawString(info[line].c_str(), xx, yy, zz, line);
    }
    return;
  }

  ctx->drawString(str.c_str(), xx, yy, zz);
}

// the glyphs of the geometry (point spheres, curve cylinders), collected
// over the pass and drawn as one array at the end; not kept between frames,
// as nothing says when the geometry has changed
static glyphList _geomGlyphs;

// where a glyph goes, or null when they are drawn one at a time (a picking
// pass needs a colour per entity)
static glyphList *geomGlyphs(drawContext *ctx)
{
  if(ctx->render_mode == drawContext::GMSH_SELECT) return nullptr;
  return &_geomGlyphs;
}

// is this entity drawn by the pass? Not when hidden, and never the discrete,
// partition and boundary layer entities, which only carry a mesh
static bool geomDrawn(drawContext *ctx, GEntity *e)
{
  if(!ctx->passWants(gmshGeometryEntityIsTransparent(e)) || !e->getVisibility()) return false;
  switch(e->geomType()) {
  case GEntity::BoundaryLayerPoint:
  case GEntity::DiscreteCurve:
  case GEntity::PartitionCurve:
  case GEntity::BoundaryLayerCurve:
  case GEntity::PartitionSurface:
  case GEntity::BoundaryLayerSurface: return false;
  default: return true;
  }
}

// the colour of an entity: the selection colour if selected, or else its own
// or that of its dimension, orphans (and curves or surfaces bounding a single
// surface or volume) highlighted if asked
static unsigned int geomColor(GEntity *e, bool selected)
{
  CTX *c = CTX::instance();
  if(selected) return getSelectionColor(e);
  const unsigned int own[4] = {c->color.geom.point, c->color.geom.curve,
                               c->color.geom.surface, c->color.geom.volume};
  unsigned int col = e->useColor() ? e->getColor() : own[e->dim()];
  if(c->geom.highlightOrphans && e->dim() < 3) {
    std::size_t up = (e->dim() == 0) ? static_cast<GVertex *>(e)->numEdges() :
                     (e->dim() == 1) ? static_cast<GEdge *>(e)->numFaces() :
                                       static_cast<GFace *>(e)->numRegions();
    if(e->isOrphan())
      col = c->color.geom.highlight[0];
    else if(up == 1)
      col = c->color.geom.highlight[1];
  }
  return col;
}

// The arrays of the geometry kept between frames, per model and dimension:
// the points, the curves as lines and the surfaces as triangles (merged from
// their own arrays), each drawn in one call. For the picture they carry the
// colours of the entities; gathered and drawn entity by entity at every
// frame, 780,000 points took a tenth of a second and 14,400 curves or
// surfaces 70 ms with the shader pipeline. For a picking pass they carry the
// identifiers of the entities: a pass over a model of 2.4 million entities
// took 2 s drawn entity by entity, 15 s with its surfaces shown, and every
// hover asks for one. The entities are registered in the same order at every
// pass, which gives them the same identifiers as long as nothing before them
// changes; when something does, the colours are written again. An entity
// stepped past with the wheel is left out by drawing the array around its
// vertices. An array is built again when what it is made from changes (see
// keptToken()). The selected entities are drawn again on top by the
// per-entity pass, which also draws the labels and what is not kept.
namespace {
  struct keptArray {
    VertexArray *va = nullptr;
    std::vector<double> token;
    // for picking: the entities, and the first vertex of each (and one past
    // the last), and the identifier of the first the colours were written
    // for
    std::vector<int> tags, start;
    std::size_t base = 0;
    // some surfaces have no triangulation, and are left to the per-entity
    // pass (which draws their cross)
    bool incomplete = false;
    keptArray() = default;
    keptArray(const keptArray &) = delete;
    ~keptArray() { delete va; }
  };
  // for the picture, one set per transparency pass (all, opaque,
  // transparent): with mixed transparency each pass keeps its own entities
  struct keptModel {
    keptArray shown[3][3], picked[3];
  };
  OwnerCache<keptModel> _keptModels;
  // set while the dimension of the model being drawn comes from its kept
  // array, and when some of its entities could not be kept
  bool _kept = false, _keptIncomplete = false;
} // namespace

static void curvePoints(drawContext *ctx, GEdge *e, std::vector<SPoint3> &pts);

// f(x, y, z) for each segment between two consecutive points
template <class F> static void forSegments(const std::vector<SPoint3> &pts, F f)
{
  for(std::size_t i = 0; i + 1 < pts.size(); i++) {
    double x[2] = {pts[i].x(), pts[i + 1].x()};
    double y[2] = {pts[i].y(), pts[i + 1].y()};
    double z[2] = {pts[i].z(), pts[i + 1].z()};
    f(x, y, z);
  }
}

// does a kept array cover this dimension of the model? Not for what it does
// not hold: spheres (the cylinders of the curves are kept in a glyph list),
// crosses, per-entity colours of orphans, points and curves under a display
// transform, the models other than the current one for picking, or what
// depends on the selection
static bool keptCovers(drawContext *ctx, GModel *m, int dim, bool pick)
{
  CTX *c = CTX::instance();
  if(c->hideUnselected) return false;
  if((pick || dim < 2) && ctx->getTransform()) return false;
  if(pick && m != GModel::current()) return false;
  switch(dim) {
  case 0:
    return c->geom.points && c->geom.pointType <= 0 &&
           (pick || !c->geom.highlightOrphans);
  case 1: return c->geom.curves && (!pick || c->geom.curveType <= 0);
  case 2: return c->geom.surfaces && c->geom.surfaceType >= 1;
  default: return false;
  }
}

// what a kept array is made from, besides the entities themselves
static std::vector<double> keptToken(drawContext *ctx, int dim, bool pick)
{
  CTX *c = CTX::instance();
  // (the mesh too: discrete points, curves and surfaces are drawn from it)
  std::vector<double> tok = {(double)c->geom.stamp[dim],
                             (double)c->meshContentStamp,
                             (double)c->entityVisibilityStamp,
                             (double)ctx->transparencyPass};
  // which entities the pass holds, when it is not all of them
  if(!pick) tok.push_back(gmshGeometryColorsAreTransparent());
  if(pick) tok.push_back(c->geom.numSubEdges);
  else if(dim == 0) {
    tok.push_back(c->entityColorsStamp);
    tok.push_back(c->color.geom.point);
  }
  else if(dim == 2)
    tok.push_back(c->entityColorsStamp);
  else if(dim == 1) {
    std::vector<double> more = {(double)c->entityColorsStamp,
                                (double)c->geom.numSubEdges,
                                (double)c->geom.curveType,
                                (double)c->color.geom.curve,
                                (double)c->geom.highlightOrphans,
                                (double)c->color.geom.highlight[0],
                                (double)c->color.geom.highlight[1],
                                (double)c->geom.useTransform};
    tok.insert(tok.end(), more.begin(), more.end());
  }
  return tok;
}

// f(e) for each entity of a dimension of the model a kept array holds: those
// drawn by the pass, as the per-entity drawers decide
template <class F>
static void forKeptEntities(drawContext *ctx, GModel *m, int dim, F f)
{
  std::vector<GEntity *> ents;
  if(dim == 0) ents.insert(ents.end(), m->firstVertex(), m->lastVertex());
  if(dim == 1) ents.insert(ents.end(), m->firstEdge(), m->lastEdge());
  if(dim == 2) ents.insert(ents.end(), m->firstFace(), m->lastFace());
  for(auto e : ents)
    if(geomDrawn(ctx, e)) f(e);
}

// the kept array of a dimension of the model, built again if needed; the
// colours of a picking array are written when it is drawn
static keptArray &getKept(drawContext *ctx, GModel *m, int dim, bool pick)
{
  CTX *c = CTX::instance();
  keptModel &km = _keptModels[m];
  keptArray &ka = pick ? km.picked[dim] : km.shown[ctx->transparencyPass][dim];
  if(ka.va && keptToken(ctx, dim, pick) == ka.token) return ka;
  delete ka.va;
  ka.va = new VertexArray(dim + 1, dim ? 1000 : (int)m->getNumVertices() + 1);
  ka.tags.clear();
  ka.start.clear();
  ka.base = 0;
  ka.incomplete = false;
  const unsigned int black[3] = {0, 0, 0};
  std::vector<SPoint3> pts;
  forKeptEntities(ctx, m, dim, [&](GEntity *e) {
    GFace *f = (dim == 2) ? static_cast<GFace *>(e) : nullptr;
    if(f) {
      f->fillVertexArray();
      if(!f->va_geom_triangles) {
        ka.incomplete = true;
        return;
      }
    }
    ka.tags.push_back(e->tag());
    ka.start.push_back(ka.va->getNumVertices());
    if(dim == 0) {
      GVertex *v = static_cast<GVertex *>(e);
      double x = v->x(), y = v->y(), z = v->z();
      unsigned int col = pick ? 0 : v->useColor() ? v->getColor() :
                                                    c->color.geom.point;
      ka.va->add(&x, &y, &z, nullptr, &col, nullptr, false);
    }
    else if(dim == 1) {
      curvePoints(ctx, static_cast<GEdge *>(e), pts);
      unsigned int col[2];
      col[0] = col[1] = pick ? 0 : geomColor(e, false);
      forSegments(pts, [&](double *x, double *y, double *z) {
        ka.va->add(x, y, z, nullptr, col, nullptr, false);
      });
    }
    else
      ka.va->merge(f->va_geom_triangles,
                   pick ? (const unsigned char *)black : nullptr);
  });
  ka.start.push_back(ka.va->getNumVertices());
  ka.va->finalize();
  // after the arrays of the surfaces have been filled, which may have
  // dropped some of them
  ka.token = keptToken(ctx, dim, pick);
  return ka;
}

// the curves of the model as cylinders, kept in a list of the glyph cache
static void drawKeptCylinders(drawContext *ctx, GModel *m)
{
  CTX *c = CTX::instance();
  glyphToken gt;
  for(auto v : keptToken(ctx, 1, false)) gt.add(v);
  gt.add(ctx->pixel_equiv_x / ctx->s[0]);
  gt.add(c->geom.curveWidth);
  glyphList *g;
  if(!glyphCache::get(m, GLYPH_GEOM_CURVES, gt, g)) {
    double r = c->geom.curveWidth * ctx->pixel_equiv_x / ctx->s[0];
    std::vector<SPoint3> pts;
    forKeptEntities(ctx, m, 1, [&](GEntity *e) {
      curvePoints(ctx, static_cast<GEdge *>(e), pts);
      unsigned int col = geomColor(e, false);
      forSegments(pts, [&](double *x, double *y, double *z) {
        g->addCylinder(x, y, z, r, r, col);
      });
    });
  }
  // the inside of the open end of a tube shows: lit on both sides, as the
  // pass drawing them after the surfaces had left it
  gmshLightTwoSide(c->geom.lightTwoSide ? true : false);
  g->draw(ctx, c->geom.light);
  gmshLightTwoSide(false);
}

// draw a dimension of the model from its kept array; false if its entities
// have to be drawn one at a time (see keptCovers())
static bool drawKept(drawContext *ctx, GModel *m, int dim)
{
  CTX *c = CTX::instance();
  bool pick = (ctx->render_mode == drawContext::GMSH_SELECT);
  if(!keptCovers(ctx, m, dim, pick)) return false;
  if(dim == 1 && !pick && c->geom.curveType > 0) {
    // one glyph list per model: not for passes that draw some curves only
    if(ctx->transparencyPass != TRANSPARENCY_ALL &&
       !gmshGeometryColorsAreTransparent())
      return false;
    drawKeptCylinders(ctx, m);
    return true;
  }
  keptArray &ka = getKept(ctx, m, dim, pick);
  _keptIncomplete = ka.incomplete;
  if(pick ? ka.tags.empty() : !ka.va->getNumVertices()) return true;

  std::vector<std::pair<int, int> > runs;
  if(pick) {
    // the identifiers of this pass, and the colours for them if they moved
    std::size_t base = ctx->pickRegister(dim, ka.tags);
    if(base != ka.base) {
      for(std::size_t k = 0; k < ka.tags.size(); k++) {
        unsigned char id[4];
        drawContext::pickIdColor(base + k, id);
        for(int i = ka.start[k]; i < ka.start[k + 1]; i++) {
          unsigned char *p = ka.va->getColorArray(4 * i);
          for(int j = 0; j < 4; j++) p[j] = id[j];
        }
      }
      ka.va->setVboDirty(true);
      ka.base = base;
    }
    // the runs of vertices between the entities stepped past
    int from = 0;
    for(std::size_t k = 0; k < ka.tags.size(); k++) {
      if(!ctx->pickSkipped(dim, ka.tags[k])) continue;
      if(ka.start[k] > from) runs.push_back(std::make_pair(from, ka.start[k]));
      from = ka.start[k + 1];
    }
    if(ka.start.back() > from)
      runs.push_back(std::make_pair(from, ka.start.back()));
    ctx->pickStateFor(dim);
  }

  // as the entities are drawn one at a time: a wireframe half as wide as the
  // curves, a picking pass the surfaces as they are shown (what is visible is
  // what is picked)
  double width = (dim == 1) ? c->geom.curveWidth : c->geom.curveWidth / 2.;
  gmshLightTwoSide(!pick && dim == 2 && c->geom.surfaceType > 1 &&
                   c->geom.lightTwoSide);
  gmshLighting(false);
  gmshPointSize((float)(c->geom.pointSize * ctx->highResolutionPixelFactor()));
  gl2psPointSize((float)(c->geom.pointSize * c->print.epsPointSizeFactor));
  gmshLineWidth((float)width);
  gl2psLineWidth((float)(width * c->print.epsLineWidthFactor));
  if(dim == 2) gmshPolygonFill(c->geom.surfaceType > 1);
  GLenum type = (dim == 0) ? GL_POINTS : (dim == 1) ? GL_LINES : GL_TRIANGLES;
  int flags = pick ? GMSH_DRAW_IDENTIFIERS : GMSH_DRAW_COLORS;
  if(dim == 2 && !pick && c->geom.light) flags |= GMSH_DRAW_LIGHT;
  if(dim == 2 && c->polygonOffset) flags |= GMSH_DRAW_OFFSET;
  gmshDrawVertexArray(ka.va, type, flags, pick ? &runs : nullptr);
  if(dim == 2) gmshPolygonFill(true);
  return true;
}

// the points a curve is drawn through
static void curvePoints(drawContext *ctx, GEdge *e, std::vector<SPoint3> &pts)
{
  pts.clear();
  Range<double> t_bounds = e->parBounds(0);
  double t_min = t_bounds.low(), t_max = t_bounds.high();
  int N = e->minimumDrawSegments() + 1;
  for(int i = 0; i < N; i++) {
    double t = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
    GPoint p = e->point(t);
    double x = p.x(), y = p.y(), z = p.z();
    ctx->transform(x, y, z);
    pts.push_back(SPoint3(x, y, z));
  }
}

static void drawGeomPoint(drawContext *ctx, GVertex *v, double size)
{
  CTX *c = CTX::instance();
  double x = v->x(), y = v->y(), z = v->z();
  ctx->transform(x, y, z);
  if(c->geom.points || v->getSelection() == GEntity::SelectShow) {
    if(c->geom.pointType > 0) {
      if(glyphList *g = geomGlyphs(ctx))
        g->addSphere(ctx, size, x, y, z, glyphCurrentColor());
      else
        ctx->drawSphere(size, x, y, z, c->geom.light);
    }
    else {
      // over the kept points, which hold this one too
      if(_kept) glDepthFunc(GL_LEQUAL);
      gmshBegin(GL_POINTS);
      gmshVertex3d(x, y, z);
      gmshEnd();
      if(_kept) {
        glImmediate::flush();
        glDepthFunc(GL_LESS);
      }
    }
  }
  if(c->geom.pointLabels || v->getSelection() == GEntity::SelectShow) {
    double ps = c->geom.pointSize * ctx->highResolutionPixelFactor();
    double offset = (0.5 * ps + 0.1 * c->glFontSize) * ctx->pixel_equiv_x;
    drawEntityLabel(ctx, v, x, y, z, offset);
  }
}

static void drawGeomCurve(drawContext *ctx, GEdge *e, bool sel, double width)
{
  CTX *c = CTX::instance();
  // already in the kept curves, unless selected: then drawn again on top,
  // which needs the depth test to accept equal depths
  bool merged = _kept && c->geom.curves;
  bool drawIt = (c->geom.curves || e->getSelection() == GEntity::SelectShow) &&
                (!merged || sel);
  if(drawIt) {
    if(merged) glDepthFunc(GL_LEQUAL);
    std::vector<SPoint3> pts;
    curvePoints(ctx, e, pts);
    if(c->geom.curveType > 0) {
      forSegments(pts, [&](double *x, double *y, double *z) {
        // over the kept cylinders it is drawn now, under the depth test set
        // above, and not with the glyphs drawn at the end of the pass
        if(glyphList *g = merged ? nullptr : geomGlyphs(ctx)) {
          double r = width * ctx->pixel_equiv_x / ctx->s[0];
          g->addCylinder(x, y, z, r, r, glyphCurrentColor());
        }
        else
          ctx->drawCylinder(width, x, y, z, c->geom.light);
      });
    }
    else {
      gmshBegin(GL_LINE_STRIP);
      for(auto &p : pts) gmshVertex3d(p.x(), p.y(), p.z());
      gmshEnd();
    }
    if(merged) {
      glImmediate::flush();
      glDepthFunc(GL_LESS);
    }
  }

  Range<double> t_bounds = e->parBounds(0);
  double t = t_bounds.low() + 0.5 * (t_bounds.high() - t_bounds.low());
  if(c->geom.curveLabels || e->getSelection() == GEntity::SelectShow) {
    GPoint p = e->point(t);
    double offset =
      (0.5 * c->geom.curveWidth + 0.1 * c->glFontSize) * ctx->pixel_equiv_x;
    double x = p.x(), y = p.y(), z = p.z();
    ctx->transform(x, y, z);
    drawEntityLabel(ctx, e, x, y, z, offset);
  }
  if(c->geom.tangents) {
    GPoint p = e->point(t);
    SVector3 der = e->firstDer(t);
    der.normalize();
    for(int i = 0; i < 3; i++)
      der[i] *= c->geom.tangents * ctx->pixel_equiv_x / ctx->s[i];
    gmshColor4ubv((const void *)&c->color.geom.tangents);
    double x = p.x(), y = p.y(), z = p.z();
    ctx->transform(x, y, z);
    ctx->drawVector(c->vectorType, 0, x, y, z, der[0], der[1], der[2],
                    c->geom.light);
  }
}

static void drawGeomSurface(drawContext *ctx, GFace *f, bool sel)
{
  CTX *c = CTX::instance();
  bool shown = c->geom.surfaces || f->getSelection() == GEntity::SelectShow;
  if(shown && c->geom.surfaceType > 0) f->fillVertexArray();
  if((shown && c->geom.surfaceType == 0) || c->geom.surfaceLabels ||
     c->geom.normals)
    f->buildRepresentationCross();

  if(shown) {
    VertexArray *va = f->va_geom_triangles;
    if(c->geom.surfaceType > 0 && va) {
      // already in the merged array, unless selected: then drawn again on
      // top, which needs the depth test to accept equal depths
      bool merged = _kept && c->geom.surfaces;
      if((!merged || sel) && va->getNumVertices()) {
        if(merged) glDepthFunc(GL_LEQUAL);
        bool colors = !f->getSelection() && va->hasColors();
        if(!ctx->inPickColorMode() && !colors) {
          unsigned int col = getSelectionColor(f);
          gmshColor4ubv((const void *)&col);
        }
        // a picking pass draws the surface as it is shown, wireframe or
        // solid: what is visible is what is picked
        bool solid = c->geom.surfaceType > 1;
        gmshLightTwoSide(solid && c->geom.lightTwoSide);
        gmshPolygonFill(solid);
        gmshDrawVertexArray(va, GL_TRIANGLES,
                            (c->geom.light ? GMSH_DRAW_LIGHT : 0) |
                              (colors ? GMSH_DRAW_COLORS : 0) |
                              (c->polygonOffset ? GMSH_DRAW_OFFSET : 0));
        gmshPolygonFill(true);
        if(merged) glDepthFunc(GL_LESS);
      }
    }
    else {
      gmshLineStipple(1, 0x0F0F);
      gl2psEnable(GL2PS_LINE_STIPPLE);
      for(int dim = 0; dim < 2; dim++) {
        for(auto &line : f->cross[dim]) {
          if(line.size() < 2) continue;
          gmshBegin(GL_LINE_STRIP);
          for(auto &p : line) {
            double x = p.x(), y = p.y(), z = p.z();
            ctx->transform(x, y, z);
            gmshVertex3d(x, y, z);
          }
          gmshEnd();
        }
      }
      gmshLineStippleOff();
      gl2psDisable(GL2PS_LINE_STIPPLE);
    }
  }

  // the label and the normal at the middle of the first line of the cross
  if(f->cross[0].empty() || f->cross[0][0].empty()) return;
  SPoint3 p = f->cross[0][0][f->cross[0][0].size() / 2];
  double x = p.x(), y = p.y(), z = p.z();
  ctx->transform(x, y, z);
  if(c->geom.surfaceLabels || f->getSelection() == GEntity::SelectShow)
    drawEntityLabel(ctx, f, x, y, z, 0.1 * c->glFontSize * ctx->pixel_equiv_x);
  if(c->geom.normals) {
    SVector3 n = f->normal(f->parFromPoint(p));
    for(int i = 0; i < 3; i++)
      n[i] *= c->geom.normals * ctx->pixel_equiv_x / ctx->s[i];
    gmshColor4ubv((const void *)&c->color.geom.normals);
    ctx->drawVector(c->vectorType, 0, x, y, z, n[0], n[1], n[2],
                    c->geom.light);
  }
}

// a volume is drawn as a marker at the middle of its bounding box
static void drawGeomVolume(drawContext *ctx, GRegion *r)
{
  CTX *c = CTX::instance();
  bool shown = c->geom.volumes || r->getSelection() == GEntity::SelectShow;
  bool label = c->geom.volumeLabels || r->getSelection() == GEntity::SelectShow;
  if(!shown && !label) return;
  const double size = 8.;
  SBoundingBox3d bb = r->bounds(true); // fast approx if mesh-based
  double x = bb.center().x(), y = bb.center().y(), z = bb.center().z();
  double d = bb.diag() / 50.;
  ctx->transform(x, y, z);
  if(shown) {
    if(c->geom.volumeType == 0) {
      if(glyphList *g = geomGlyphs(ctx))
        g->addSphere(ctx, size, x, y, z, glyphCurrentColor());
      else
        ctx->drawSphere(size, x, y, z, c->geom.light);
    }
    else {
      // three squares in the planes of the axes
      const double sq[3][4][3] = {
        {{d, 0, 0}, {0, d, 0}, {-d, 0, 0}, {0, -d, 0}},
        {{d, 0, 0}, {0, 0, d}, {-d, 0, 0}, {0, 0, -d}},
        {{0, d, 0}, {0, 0, d}, {0, -d, 0}, {0, 0, -d}}};
      for(int i = 0; i < 3; i++) {
        gmshBegin(GL_LINE_LOOP);
        for(int j = 0; j < 4; j++)
          gmshVertex3d(x + sq[i][j][0], y + sq[i][j][1], z + sq[i][j][2]);
        gmshEnd();
      }
    }
  }
  if(label)
    drawEntityLabel(ctx, r, x, y, z,
                    (size + 0.1 * c->glFontSize) * ctx->pixel_equiv_x);
}

// what an entity draws itself: all of it, or what the kept arrays do not
// cover (its label, or itself on top when selected)
static void drawGeomEntity(drawContext *ctx, GEntity *e)
{
  CTX *c = CTX::instance();
  int dim = e->dim();
  if(!geomDrawn(ctx, e)) return;
  bool pick = (ctx->render_mode == drawContext::GMSH_SELECT);
  // a point already in the kept array: for a picking pass, selected or not
  // (it draws them all alike, and no label); for the picture, unless selected
  // or labelled
  if(dim == 0 && _kept &&
     (pick || (!e->getSelection() && !c->geom.pointLabels)))
    return;

  // all a volume draws is a marker at its middle: it is picked in front of
  // the surfaces around it, which would otherwise always cover it
  ctx->setPickColorFor(e, dim == 3);
  gmshLightTwoSide(dim >= 2 && c->geom.lightTwoSide);

  // a picking pass draws what is selected at its plain size and colour: the
  // image it reads identifiers from must not depend on what is selected, or
  // highlighting a point would grow it over the marker of the volume next to
  // it and there would be no way back
  bool sel = e->getSelection() && !ctx->inPickColorMode();
  double fact = ctx->highResolutionPixelFactor();
  double size = sel ? c->geom.selectedPointSize : c->geom.pointSize;
  double width = sel ? c->geom.selectedCurveWidth : c->geom.curveWidth;
  if(dim == 2) width /= 2.; // the wireframe of a surface
  if(dim == 0) {
    gmshPointSize((float)(size * fact));
    gl2psPointSize((float)(size * c->print.epsPointSizeFactor));
  }
  else {
    gmshLineWidth((float)width);
    gl2psLineWidth((float)(width * c->print.epsLineWidthFactor));
  }
  unsigned int col = geomColor(e, sel);
  gmshColor4ubv((const void *)&col);

  switch(dim) {
  // (a sphere is sized in pixels of the window, as those of the mesh nodes,
  // not of the framebuffer, which the point size is)
  case 0: drawGeomPoint(ctx, static_cast<GVertex *>(e), size); break;
  case 1: drawGeomCurve(ctx, static_cast<GEdge *>(e), sel, width); break;
  case 2: drawGeomSurface(ctx, static_cast<GFace *>(e), sel); break;
  case 3: drawGeomVolume(ctx, static_cast<GRegion *>(e)); break;
  }
}

// the entities of a dimension of the model: all of them, or only the
// selected ones
template <class F>
static void forEntities(GModel *m, int dim, bool all, F f)
{
  if(all) {
    std::vector<GEntity *> ents;
    m->getEntities(ents, dim);
    for(auto e : ents) f(e);
    return;
  }
  if(!GEntity::numSelected) return;
  // a copy: drawing does not select, but the set must not move under us
  std::vector<GEntity *> sel(GEntity::selected.begin(),
                             GEntity::selected.end());
  for(auto e : sel)
    if(e->model() == m && e->dim() == dim) f(e);
}

// The geometry is drawn from arrays kept between frames, one per model and
// dimension, each in a single call - with the colours of the entities for the
// picture, with their identifiers for a picking pass - and built again only
// when the geometry, the options they depend on or the colours and visibility
// change. Entities are then walked one by one only for what those arrays do
// not hold: labels, tangents and normals, displays that are not kept, and the
// selected entities, drawn again on top.
void drawContext::drawGeom()
{
  // nothing of the geometry is opaque when the colours of the options are
  // transparent; otherwise the entities are sorted out one by one
  if(transparencyPass == TRANSPARENCY_OPAQUE &&
     gmshGeometryColorsAreTransparent())
    return;
  if(transparencyPass == TRANSPARENCY_TRANSPARENT && !gmshGeometryIsTransparent())
    return;
  if(!CTX::instance()->geom.draw) return;

  // draw any transient geometry stuff
  if(drawGeomTransient) (*drawGeomTransient)(this);

  _geomGlyphs.clear();

  CTX *c = CTX::instance();
  gmshClipPlanesOn(c->geom.clip);

  bool pick = (render_mode == GMSH_SELECT);
  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    if(m->getVisibility() && isVisible(m)) {
      // Each dimension is drawn from what is kept of it - for the picture,
      // or with the identifiers for a picking pass - and entity by entity
      // only what that does not cover: all the entities when labels,
      // normals or a display not kept need them, or else only the selected
      // ones, drawn again on top (a million entities were walked at every
      // frame, and at every pick, for the one highlighted)
      for(int dim = 0; dim < 3; dim++) {
        _kept = drawKept(this, m, dim);
        bool shown = (dim == 0) ? c->geom.points :
                     (dim == 1) ? c->geom.curves :
                                  c->geom.surfaces;
        bool labels = (dim == 0) ? c->geom.pointLabels :
                      (dim == 1) ? c->geom.curveLabels :
                                   c->geom.surfaceLabels;
        bool vectors = (dim == 1) ? c->geom.tangents :
                       (dim == 2) ? c->geom.normals :
                                    false;
        bool all = (!pick && labels) || vectors ||
                   (shown && (!_kept || _keptIncomplete));
        forEntities(m, dim, all,
                    [this](GEntity *e) { drawGeomEntity(this, e); });
        _kept = _keptIncomplete = false;
      }
      forEntities(m, 3, true, [this](GEntity *e) { drawGeomEntity(this, e); });
    }
  }

  _geomGlyphs.draw(this, c->geom.light);
  _geomGlyphs.clear();

  gmshClipPlanesOn(0);
}
