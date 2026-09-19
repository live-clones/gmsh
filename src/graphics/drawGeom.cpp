// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include "drawContext.h"
#include "Context.h"
#include "OwnerCache.h"

// the colour a selected entity is drawn in (GModelVertexArrays.cpp)
extern unsigned int getSelectionColor(GEntity *e);
#include "gl2ps.h"
#include "VertexArray.h"
#include "GModel.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "StringUtils.h"
#include "glyphList.h"
#include "glImmediate.h"
#include <map>

static void drawEntityLabel(drawContext *ctx, GEntity *e, double x, double y,
                            double z, double offset)
{
  double xx = x + offset / ctx->s[0];
  double yy = y + offset / ctx->s[1];
  double zz = z + offset / ctx->s[2];

  char str[1024];
  switch(CTX::instance()->geom.labelType) {
  case 5:
    {
      sprintf(str, "(%g,%g,%g)", x, y, z);
    }
    break;
  case 4:
    {
      strcpy(str, "");
      std::string name = "";
      for(std::size_t i = 0; i < e->physicals.size(); i++) {
        if(name.size()) strcat(str, ", ");
        name = e->model()->getPhysicalName(e->dim(), std::abs(e->physicals[i]));
        if(name.size()) strcat(str, name.c_str());
      }
    }
    break;
  case 3:
    strcpy(str, e->model()->getElementaryName(e->dim(), e->tag()).c_str());
    break;
  case 2:
    strcpy(str, "");
    for(std::size_t i = 0; i < e->physicals.size(); i++) {
      char tmp[32];
      if(i) strcat(str, ", ");
      sprintf(tmp, "%d", e->physicals[i]);
      strcat(str, tmp);
    }
    break;
  case 1:
    sprintf(str, "%d", e->tag());
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

  ctx->drawString(str, xx, yy, zz);
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

// does this pass draw this entity? A mixed geometry draws its opaque
// entities in the opaque pass and the others in the transparent one
static bool passWants(drawContext *ctx, GEntity *e)
{
  if(ctx->transparencyPass == TRANSPARENCY_ALL) return true;
  return (ctx->transparencyPass == TRANSPARENCY_TRANSPARENT) ==
         gmshGeometryEntityIsTransparent(e);
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
  struct keptModel {
    keptArray shown[3], picked[3];
  };
  OwnerCache<keptModel> _keptModels;
  // set while the dimension of the model being drawn comes from its kept
  // array, and when some of its entities could not be kept
  bool _kept = false, _keptIncomplete = false;
} // namespace

static void curvePoints(drawContext *ctx, GEdge *e, std::vector<SPoint3> &pts);
static unsigned int curveColor(GEdge *e);

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
  std::vector<double> tok = {(double)c->geom.stamp[dim],
                             (double)c->entityVisibilityStamp};
  if(pick) {
    tok.push_back(c->geom.numSubEdges);
    tok.push_back(ctx->transparencyPass);
  }
  else if(dim == 0) {
    tok.push_back(c->entityColorsStamp);
    tok.push_back(c->color.geom.point);
  }
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
  for(auto e : ents) {
    if(!passWants(ctx, e) || !e->getVisibility()) continue;
    switch(e->geomType()) {
    case GEntity::BoundaryLayerPoint:
    case GEntity::DiscreteCurve:
    case GEntity::PartitionCurve:
    case GEntity::BoundaryLayerCurve:
    case GEntity::PartitionSurface:
    case GEntity::BoundaryLayerSurface: continue;
    default: f(e);
    }
  }
}

// the kept array of a dimension of the model, built again if needed; the
// colours of a picking array are written when it is drawn
static keptArray &getKept(drawContext *ctx, GModel *m, int dim, bool pick)
{
  CTX *c = CTX::instance();
  keptModel &km = _keptModels[m];
  keptArray &ka = pick ? km.picked[dim] : km.shown[dim];
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
      col[0] = col[1] = pick ? 0 : curveColor(static_cast<GEdge *>(e));
      for(std::size_t i = 0; i + 1 < pts.size(); i++) {
        double x[2] = {pts[i].x(), pts[i + 1].x()};
        double y[2] = {pts[i].y(), pts[i + 1].y()};
        double z[2] = {pts[i].z(), pts[i + 1].z()};
        ka.va->add(x, y, z, nullptr, col, nullptr, false);
      }
    }
    else
      ka.va->merge(f->va_geom_triangles,
                   pick ? (const unsigned char *)black : nullptr);
  });
  ka.start.push_back(ka.va->getNumVertices());
  ka.va->finalize();
  // after the arrays of the surfaces have been filled, which may have
  // dropped some of them
  c->stampChanges();
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
      unsigned int col = curveColor(static_cast<GEdge *>(e));
      for(std::size_t i = 0; i + 1 < pts.size(); i++) {
        double x[2] = {pts[i].x(), pts[i + 1].x()};
        double y[2] = {pts[i].y(), pts[i + 1].y()};
        double z[2] = {pts[i].z(), pts[i + 1].z()};
        g->addCylinder(x, y, z, r, r, col);
      }
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

class drawGVertex {
private:
  drawContext *_ctx;

public:
  drawGVertex(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GVertex *v)
  {
    if(!passWants(_ctx, v)) return;
    if(!v->getVisibility()) return;
    if(v->geomType() == GEntity::BoundaryLayerPoint) return;
    // already in the kept array: for a picking pass, selected or not (it
    // draws them all alike, and no label); for the picture, unless selected
    // or labelled
    if(_kept && (_ctx->render_mode == drawContext::GMSH_SELECT ||
                 (!v->getSelection() && !CTX::instance()->geom.pointLabels)))
      return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   v->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(0, v->tag());
    }

    gmshLightTwoSide(false);

    double fact = _ctx->highResolutionPixelFactor();
    double ps = CTX::instance()->geom.pointSize * fact;
    double sps = CTX::instance()->geom.selectedPointSize * fact;

    // a picking pass draws what is selected at its plain size: the image it
    // reads identifiers from must not depend on what is selected, or
    // highlighting a point would grow it over the marker of the volume next
    // to it and there would be no way back
    bool sel = v->getSelection() && !_ctx->inPickColorMode();
    if(sel) {
      gmshPointSize((float)sps);
      gl2psPointSize((float)(CTX::instance()->geom.selectedPointSize *
                             CTX::instance()->print.epsPointSizeFactor));
      unsigned int sc = getSelectionColor(v);
      gmshColor4ubv((const void *)&sc);
    }
    else {
      gmshPointSize((float)ps);
      gl2psPointSize((float)(CTX::instance()->geom.pointSize *
                             CTX::instance()->print.epsPointSizeFactor));
      unsigned int col = v->useColor() ? v->getColor() :
        CTX::instance()->color.geom.point;
      gmshColor4ubv((const void *)&col);
    }

    if(CTX::instance()->geom.highlightOrphans) {
      if(v->isOrphan())
        gmshColor4ubv((const void *)&CTX::instance()->color.geom.highlight[0]);
      else if(v->numEdges() == 1)
        gmshColor4ubv((const void *)&CTX::instance()->color.geom.highlight[1]);
    }

    double x = v->x(), y = v->y(), z = v->z();
    _ctx->transform(x, y, z);

    if(CTX::instance()->geom.points || v->getSelection() == GEntity::SelectShow) {
      if(CTX::instance()->geom.pointType > 0) {
        double size = sel ? sps : ps;
        if(glyphList *g = geomGlyphs(_ctx))
          g->addSphere(_ctx, size, x, y, z, glyphCurrentColor());
        else
          _ctx->drawSphere(size, x, y, z, CTX::instance()->geom.light);
      }
      else {
        // over the kept points, which hold this one too
        if(_kept) glDepthFunc(GL_LEQUAL);
        gmshBegin(GL_POINTS);
        gmshVertex3d(x, y, z);
        gmshEnd();
        if(_kept) {
          gmshFlushImmediate();
          glDepthFunc(GL_LESS);
        }
      }
    }

    if(CTX::instance()->geom.pointLabels || v->getSelection() == GEntity::SelectShow) {
      double offset =
        (0.5 * ps + 0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      if(v->getSelection() == GEntity::SelectShow)
        gmshColor4ubv((const void *)&CTX::instance()->color.fg);
      drawEntityLabel(_ctx, v, x, y, z, offset);
    }

    if(select) {
    }
  }
};

// The colour a curve is drawn in when it is not selected
static unsigned int curveColor(GEdge *e)
{
  CTX *c = CTX::instance();
  unsigned int col = e->useColor() ? e->getColor() : c->color.geom.curve;
  if(c->geom.highlightOrphans) {
    if(e->isOrphan())
      col = c->color.geom.highlight[0];
    else if(e->numFaces() == 1)
      col = c->color.geom.highlight[1];
  }
  return col;
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

class drawGEdge {
private:
  drawContext *_ctx;

public:
  drawGEdge(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GEdge *e)
  {
    if(!passWants(_ctx, e)) return;
    if(!e->getVisibility()) return;
    if(e->geomType() == GEntity::DiscreteCurve) return;
    if(e->geomType() == GEntity::PartitionCurve) return;
    if(e->geomType() == GEntity::BoundaryLayerCurve) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   e->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(1, e->tag());
    }

    gmshLightTwoSide(false);

    bool sel = e->getSelection() && !_ctx->inPickColorMode();
    if(sel) {
      gmshLineWidth((float)CTX::instance()->geom.selectedCurveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int sc = getSelectionColor(e);
      gmshColor4ubv((const void *)&sc);
    }
    else {
      gmshLineWidth((float)CTX::instance()->geom.curveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.curveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int col = e->useColor() ? e->getColor() :
        CTX::instance()->color.geom.curve;
      gmshColor4ubv((const void *)&col);
    }

    if(CTX::instance()->geom.highlightOrphans) {
      if(e->isOrphan())
        gmshColor4ubv((const void *)&CTX::instance()->color.geom.highlight[0]);
      else if(e->numFaces() == 1)
        gmshColor4ubv((const void *)&CTX::instance()->color.geom.highlight[1]);
    }

    Range<double> t_bounds = e->parBounds(0);
    double t_min = t_bounds.low();
    double t_max = t_bounds.high();

    // already in the kept curves, unless selected: then drawn again on top,
    // which needs the depth test to accept equal depths
    bool merged = _kept && CTX::instance()->geom.curves;
    bool drawIt =
      (CTX::instance()->geom.curves ||
       e->getSelection() == GEntity::SelectShow) &&
      (!merged || (e->getSelection() && !_ctx->inPickColorMode()));
    if(drawIt && merged) glDepthFunc(GL_LEQUAL);
    if(drawIt) {
      int N = e->minimumDrawSegments() + 1;
      if(CTX::instance()->geom.curveType > 0) {
        for(int i = 0; i < N - 1; i++) {
          double t1 = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
          GPoint p1 = e->point(t1);
          double t2 =
            t_min + (double)(i + 1) / (double)(N - 1) * (t_max - t_min);
          GPoint p2 = e->point(t2);
          double x[2] = {p1.x(), p2.x()};
          double y[2] = {p1.y(), p2.y()};
          double z[2] = {p1.z(), p2.z()};
          _ctx->transform(x[0], y[0], z[0]);
          _ctx->transform(x[1], y[1], z[1]);
          // a picking pass draws it at its plain width, as it does points
          double w = sel ? CTX::instance()->geom.selectedCurveWidth :
                           CTX::instance()->geom.curveWidth;
          // over the kept cylinders it is drawn now, under the depth test
          // set above, and not with the glyphs drawn at the end of the pass
          if(glyphList *g = merged ? nullptr : geomGlyphs(_ctx)) {
            double r = w * _ctx->pixel_equiv_x / _ctx->s[0];
            g->addCylinder(x, y, z, r, r, glyphCurrentColor());
          }
          else
            _ctx->drawCylinder(w, x, y, z, CTX::instance()->geom.light);
        }
      }
      else {
        gmshBegin(GL_LINE_STRIP);
        for(int i = 0; i < N; i++) {
          double t = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
          GPoint p = e->point(t);
          double x = p.x(), y = p.y(), z = p.z();
          _ctx->transform(x, y, z);
          gmshVertex3d(x, y, z);
        }
        gmshEnd();
      }
    }
    if(drawIt && merged) {
      gmshFlushImmediate();
      glDepthFunc(GL_LESS);
    }

    if(CTX::instance()->geom.curveLabels || e->getSelection() == GEntity::SelectShow) {
      GPoint p = e->point(t_min + 0.5 * (t_max - t_min));
      double offset = (0.5 * CTX::instance()->geom.curveWidth +
                       0.1 * CTX::instance()->glFontSize) *
                      _ctx->pixel_equiv_x;
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      if(e->getSelection() == GEntity::SelectShow)
        gmshColor4ubv((const void *)&CTX::instance()->color.fg);
      drawEntityLabel(_ctx, e, x, y, z, offset);
    }

    if(CTX::instance()->geom.tangents) {
      double t = t_min + 0.5 * (t_max - t_min);
      GPoint p = e->point(t);
      SVector3 der = e->firstDer(t);
      der.normalize();
      for(int i = 0; i < 3; i++)
        der[i] *=
          CTX::instance()->geom.tangents * _ctx->pixel_equiv_x / _ctx->s[i];
      gmshColor4ubv((const void *)&CTX::instance()->color.geom.tangents);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      _ctx->transformOneForm(der[0], der[1], der[2]);
      _ctx->drawVector(CTX::instance()->vectorType, 0, x, y, z, der[0], der[1],
                       der[2], CTX::instance()->geom.light);
    }

    if(select) {
    }
  }
};

class drawGFace {
private:
  drawContext *_ctx;
  void _drawVertexArray(VertexArray *va, bool useNormalArray,
                        int forceColor = 0, unsigned int color = 0)
  {
    if(!va || !va->getNumVertices()) return;
    bool colors = !forceColor && va->hasColors();
    if(!_ctx->inPickColorMode() && !colors)
      gmshColor4ubv((const void *)&color);
    // a picking pass draws the surface as it is shown, wireframe or solid:
    // what is visible is what is picked
    if(CTX::instance()->geom.surfaceType > 1) {
      if(CTX::instance()->geom.lightTwoSide)
        gmshLightTwoSide(true);
      else
        gmshLightTwoSide(false);
      gmshPolygonFill(true);
    }
    else {
      gmshLightTwoSide(false);
      gmshPolygonFill(false);
    }
    gmshDrawVertexArray(va, GL_TRIANGLES,
                        (useNormalArray ? GMSH_DRAW_LIGHT : 0) |
                          (colors ? GMSH_DRAW_COLORS : 0) |
                          (CTX::instance()->polygonOffset ? GMSH_DRAW_OFFSET :
                                                            0));
    gmshPolygonFill(true);
  }

public:
  drawGFace(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GFace *f)
  {
    if(!passWants(_ctx, f)) return;
    if(!f->getVisibility()) return;
    if(f->geomType() == GEntity::PartitionSurface) return;
    if(f->geomType() == GEntity::BoundaryLayerSurface) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   f->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(2, f->tag());
    }

    if(f->getSelection() && !_ctx->inPickColorMode()) {
      gmshLineWidth((float)(CTX::instance()->geom.selectedCurveWidth / 2.));
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth / 2. *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int sc = getSelectionColor(f);
      gmshColor4ubv((const void *)&sc);
    }
    else {
      gmshLineWidth((float)(CTX::instance()->geom.curveWidth / 2.));
      gl2psLineWidth((float)(CTX::instance()->geom.curveWidth / 2. *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int col = f->useColor() ? f->getColor() :
        CTX::instance()->color.geom.surface;
      gmshColor4ubv((const void *)&col);
    }

    if(CTX::instance()->geom.highlightOrphans) {
      if(f->isOrphan())
        gmshColor4ubv((const void *)&CTX::instance()->color.geom.highlight[0]);
      else if(f->numRegions() == 1)
        gmshColor4ubv((const void *)&CTX::instance()->color.geom.highlight[1]);
    }

    if(CTX::instance()->geom.lightTwoSide)
      gmshLightTwoSide(true);
    else
      gmshLightTwoSide(false);

    if((CTX::instance()->geom.surfaces || f->getSelection() == GEntity::SelectShow) &&
       CTX::instance()->geom.surfaceType > 0)
      f->fillVertexArray();

    if(((CTX::instance()->geom.surfaces || f->getSelection() == GEntity::SelectShow) &&
        CTX::instance()->geom.surfaceType == 0) ||
       CTX::instance()->geom.surfaceLabels || CTX::instance()->geom.normals)
      f->buildRepresentationCross();

    if(CTX::instance()->geom.surfaces || f->getSelection() == GEntity::SelectShow) {
      if(CTX::instance()->geom.surfaceType > 0 && f->va_geom_triangles) {
        bool selected = false;
        if(f->getSelection()) selected = true;
        // already in the merged array, unless selected: then drawn again on
        // top, which needs the depth test to accept equal depths
        bool merged = _kept && CTX::instance()->geom.surfaces;
        if(!merged || (selected && !_ctx->inPickColorMode())) {
          if(merged) glDepthFunc(GL_LEQUAL);
          _drawVertexArray(f->va_geom_triangles, CTX::instance()->geom.light,
                           selected, getSelectionColor(f));
          if(merged) glDepthFunc(GL_LESS);
        }
      }
      else {
        gmshLineStipple(1, 0x0F0F);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        for(int dim = 0; dim < 2; dim++) {
          for(std::size_t i = 0; i < f->cross[dim].size(); i++) {
            if(f->cross[dim][i].size() >= 2) {
              gmshBegin(GL_LINE_STRIP);
              for(std::size_t j = 0; j < f->cross[dim][i].size(); j++) {
                double x = f->cross[dim][i][j].x();
                double y = f->cross[dim][i][j].y();
                double z = f->cross[dim][i][j].z();
                _ctx->transform(x, y, z);
                gmshVertex3d(x, y, z);
              }
              gmshEnd();
            }
          }
        }
        gmshLineStippleOff();
        gl2psDisable(GL2PS_LINE_STIPPLE);
      }
    }

    if(f->cross[0].size() && f->cross[0][0].size()) {
      int idx = f->cross[0][0].size() / 2;
      if(CTX::instance()->geom.surfaceLabels || f->getSelection() == GEntity::SelectShow) {
        double offset = 0.1 * CTX::instance()->glFontSize * _ctx->pixel_equiv_x;
        double x = f->cross[0][0][idx].x();
        double y = f->cross[0][0][idx].y();
        double z = f->cross[0][0][idx].z();
        _ctx->transform(x, y, z);
        if(f->getSelection() == GEntity::SelectShow)
          gmshColor4ubv((const void *)&CTX::instance()->color.fg);
        drawEntityLabel(_ctx, f, x, y, z, offset);
      }

      if(CTX::instance()->geom.normals) {
        SPoint3 p(f->cross[0][0][idx].x(), f->cross[0][0][idx].y(),
                  f->cross[0][0][idx].z());
        SPoint2 uv = f->parFromPoint(p);
        SVector3 n = f->normal(uv);
        for(int i = 0; i < 3; i++)
          n[i] *=
            CTX::instance()->geom.normals * _ctx->pixel_equiv_x / _ctx->s[i];
        gmshColor4ubv((const void *)&CTX::instance()->color.geom.normals);
        double x = p.x(), y = p.y(), z = p.z();
        _ctx->transform(x, y, z);
        _ctx->transformTwoForm(n[0], n[1], n[2]);
        _ctx->drawVector(CTX::instance()->vectorType, 0, x, y, z, n[0], n[1],
                         n[2], CTX::instance()->geom.light);
      }
    }

    if(select) {
    }
  }
};

class drawGRegion {
private:
  drawContext *_ctx;

public:
  drawGRegion(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GRegion *r)
  {
    if(!passWants(_ctx, r)) return;
    if(!r->getVisibility()) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   r->model() == GModel::current());
    if(select) {
      // all a volume draws is a marker at its middle: it is picked in front
      // of the surfaces around it, which would otherwise always cover it
      _ctx->setPickColor(3, r->tag(), -1, -1, true);
    }

    if(CTX::instance()->geom.lightTwoSide)
      gmshLightTwoSide(true);
    else
      gmshLightTwoSide(false);

    if(r->getSelection() && !_ctx->inPickColorMode()) {
      gmshLineWidth((float)CTX::instance()->geom.selectedCurveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int sc = getSelectionColor(r);
      gmshColor4ubv((const void *)&sc);
    }
    else {
      gmshLineWidth((float)CTX::instance()->geom.curveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.curveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int col = r->useColor() ? r->getColor() :
        CTX::instance()->color.geom.volume;
      gmshColor4ubv((const void *)&col);
    }

    const double size = 8.;
    double x = 0., y = 0., z = 0., d = 0.;

    if(CTX::instance()->geom.volumes || CTX::instance()->geom.volumeLabels ||
       r->getSelection() == GEntity::SelectShow) {
      SBoundingBox3d bb = r->bounds(true); // fast approx if mesh-based
      SPoint3 p = bb.center();
      x = p.x();
      y = p.y();
      z = p.z();
      d = bb.diag() / 50.;
      _ctx->transform(x, y, z);
    }

    if(CTX::instance()->geom.volumes || r->getSelection() == GEntity::SelectShow) {
      if(CTX::instance()->geom.volumeType == 0) {
        if(glyphList *g = geomGlyphs(_ctx))
          g->addSphere(_ctx, size, x, y, z, glyphCurrentColor());
        else
          _ctx->drawSphere(size, x, y, z, CTX::instance()->geom.light);
      }
      else {
        gmshBegin(GL_LINE_LOOP);
        gmshVertex3d(x + d, y, z);
        gmshVertex3d(x, y + d, z);
        gmshVertex3d(x - d, y, z);
        gmshVertex3d(x, y - d, z);
        gmshEnd();
        gmshBegin(GL_LINE_LOOP);
        gmshVertex3d(x + d, y, z);
        gmshVertex3d(x, y, z + d);
        gmshVertex3d(x - d, y, z);
        gmshVertex3d(x, y, z - d);
        gmshEnd();
        gmshBegin(GL_LINE_LOOP);
        gmshVertex3d(x, y + d, z);
        gmshVertex3d(x, y, z + d);
        gmshVertex3d(x, y - d, z);
        gmshVertex3d(x, y, z - d);
        gmshEnd();
      }
    }

    if(CTX::instance()->geom.volumeLabels || r->getSelection() == GEntity::SelectShow) {
      double offset =
        (1. * size + 0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      if(r->getSelection() == GEntity::SelectShow)
        gmshColor4ubv((const void *)&CTX::instance()->color.fg);
      drawEntityLabel(_ctx, r, x, y, z, offset);
    }

    if(select) {
    }
  }
};

// the entities of a dimension of the model the per-entity drawer f is given:
// all of them, or only the selected ones
template <class T, class F>
static void forEntities(GModel *m, int dim, bool all, F f)
{
  if(all) {
    std::vector<GEntity *> ents;
    if(dim == 0) ents.insert(ents.end(), m->firstVertex(), m->lastVertex());
    if(dim == 1) ents.insert(ents.end(), m->firstEdge(), m->lastEdge());
    if(dim == 2) ents.insert(ents.end(), m->firstFace(), m->lastFace());
    for(auto e : ents) f(static_cast<T *>(e));
    return;
  }
  if(!GEntity::numSelected) return;
  // a copy: drawing does not select, but the set must not move under us
  std::vector<GEntity *> sel(GEntity::selected.begin(),
                             GEntity::selected.end());
  for(auto e : sel)
    if(e->model() == m && e->dim() == dim) f(static_cast<T *>(e));
}

void drawContext::drawGeom()
{
  // before anything else, whatever this pass draws (see CTX::stampChanges())
  CTX::instance()->stampChanges();

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

  for(int i = 0; i < 6; i++)
    if(CTX::instance()->geom.clip & (1 << i))
      gmshClipPlaneOn(i, true);
    else
      gmshClipPlaneOn(i, false);

  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    if(m->getVisibility() && isVisible(m)) {
      // Each dimension is drawn from what is kept of it - for the picture,
      // or with the identifiers for a picking pass - and entity by entity
      // only what that does not cover: all the entities when labels,
      // normals or a display not kept need them, or else only the selected
      // ones, drawn again on top (a million entities were walked at every
      // frame, and at every pick, for the one highlighted)
      bool mixed = transparencyPass != TRANSPARENCY_ALL &&
                   !gmshGeometryColorsAreTransparent();
      bool pick = (render_mode == GMSH_SELECT);
      CTX *c = CTX::instance();
      for(int dim = 0; dim < 3; dim++) {
        _kept = !mixed && drawKept(this, m, dim);
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
        if(dim == 0) forEntities<GVertex>(m, 0, all, drawGVertex(this));
        if(dim == 1) forEntities<GEdge>(m, 1, all, drawGEdge(this));
        if(dim == 2) forEntities<GFace>(m, 2, all, drawGFace(this));
        _kept = _keptIncomplete = false;
      }
      std::for_each(m->firstRegion(), m->lastRegion(), drawGRegion(this));
    }
  }

  _geomGlyphs.draw(this, CTX::instance()->geom.light);
  _geomGlyphs.clear();

  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);
}
