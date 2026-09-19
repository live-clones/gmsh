// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include "drawContext.h"
#include "Context.h"

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

// Draw every plain geometry point in one call instead of a gmshBegin/gmshEnd
// block each, from an array per model kept between frames: gathered again at
// every frame, 780,000 points took a tenth of a second. Rebuilt when the
// geometry, the colours or the visibilities change (see CTX::stampChanges())
// or the point colour. Returns true if it drew them; the selected points are
// drawn again on top by the per-entity pass, and the labels too.
namespace {
  struct mergedPoints {
    VertexArray *points = nullptr;
    std::vector<double> token;
  };
  std::map<GModel *, mergedPoints> _mergedPoints;
} // namespace

static bool drawGeomPointsBatched(drawContext *ctx, GModel *m)
{
  CTX *c = CTX::instance();
  if(ctx->render_mode == drawContext::GMSH_SELECT) return false;
  if(!c->geom.points) return false; // only the selected ones are drawn
  if(c->geom.pointType > 0) return false; // spheres, not points
  if(c->geom.highlightOrphans) return false; // needs the per-entity colours
  // which points are visible depends on which are selected; the display
  // transform is applied here, and not kept
  if(c->hideUnselected || ctx->getTransform()) return false;

  for(auto it = _mergedPoints.begin(); it != _mergedPoints.end();) {
    if(std::find(GModel::list.begin(), GModel::list.end(), it->first) ==
       GModel::list.end()) {
      delete it->second.points;
      it = _mergedPoints.erase(it);
    }
    else
      it++;
  }
  std::vector<double> tok = {(double)c->geom.stamp[0],
                             (double)c->entityColorsStamp,
                             (double)c->entityVisibilityStamp,
                             (double)c->color.geom.point};
  mergedPoints &mp = _mergedPoints[m];
  if(!mp.points || tok != mp.token) {
    delete mp.points;
    mp.points = new VertexArray(1, (int)m->getNumVertices() + 1);
    mp.token = tok;
    for(auto it = m->firstVertex(); it != m->lastVertex(); it++) {
      GVertex *v = *it;
      if(!v->getVisibility()) continue;
      if(v->geomType() == GEntity::BoundaryLayerPoint) continue;
      double x = v->x(), y = v->y(), z = v->z();
      unsigned int cc = v->useColor() ? v->getColor() : c->color.geom.point;
      mp.points->add(&x, &y, &z, nullptr, &cc, nullptr, false);
    }
    mp.points->finalize();
  }
  if(!mp.points->getNumVertices()) return true;

  gmshLightTwoSide(false);
  gmshLighting(false);
  gmshPointSize((float)(c->geom.pointSize * ctx->highResolutionPixelFactor()));
  gl2psPointSize((float)(c->geom.pointSize * c->print.epsPointSizeFactor));
  gmshBindVertexArray(mp.points, false, true);
  drawVertexArray(mp.points, GL_POINTS);
  gmshUnbindArrays();
  return true;
}

// does this pass draw this entity? A mixed geometry draws its opaque
// entities in the opaque pass and the others in the transparent one
static bool passWants(drawContext *ctx, GEntity *e)
{
  if(ctx->transparencyPass == TRANSPARENCY_ALL) return true;
  return (ctx->transparencyPass == TRANSPARENCY_TRANSPARENT) ==
         gmshGeometryEntityIsTransparent(e);
}

class drawGVertex {
private:
  drawContext *_ctx;
  bool _batched;

public:
  drawGVertex(drawContext *ctx, bool batched = false)
    : _ctx(ctx), _batched(batched)
  {
  }
  void operator()(GVertex *v)
  {
    if(!passWants(_ctx, v)) return;
    if(!v->getVisibility()) return;
    if(v->geomType() == GEntity::BoundaryLayerPoint) return;
    // already drawn by drawGeomPointsBatched(), and nothing else here applies
    if(_batched && !v->getSelection() && !CTX::instance()->geom.pointLabels)
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
        if(_batched) glDepthFunc(GL_LEQUAL);
        gmshBegin(GL_POINTS);
        gmshVertex3d(x, y, z);
        gmshEnd();
        if(_batched) {
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

// The curves of a model, sampled once and kept between frames - as lines in
// one array, or as cylinders in a list of the glyph cache - and drawn at
// once: sampled again at every frame, a line strip or cylinders at a time,
// 14,400 curves took 70 ms a frame with the shader pipeline. Rebuilt when the
// geometry, the colours or the visibilities change (see CTX::stampChanges()),
// or the options they are drawn with. The selected curves are drawn again
// on top by the per-entity pass, and a picking pass draws them one at a
// time, each with its own identifier.
namespace {
  struct mergedCurves {
    VertexArray *lines = nullptr;
    std::vector<double> token;
  };
  std::map<GModel *, mergedCurves> _mergedCurves;
  // set while the curves of the model being drawn come from these
  bool _curvesMerged = false;
} // namespace

static bool drawMergedCurves(drawContext *ctx, GModel *m)
{
  CTX *c = CTX::instance();
  if(ctx->render_mode == drawContext::GMSH_SELECT) return false;
  if(!c->geom.curves) return false; // only the ones shown by the selection
  // which entities are visible depends on which are selected
  if(c->hideUnselected) return false;
  // the models that are gone take their arrays with them
  for(auto it = _mergedCurves.begin(); it != _mergedCurves.end();) {
    if(std::find(GModel::list.begin(), GModel::list.end(), it->first) ==
       GModel::list.end()) {
      delete it->second.lines;
      it = _mergedCurves.erase(it);
    }
    else
      it++;
  }
  std::vector<double> tok = {(double)CTX::instance()->geom.stamp[1],
                             (double)CTX::instance()->entityColorsStamp,
                             (double)CTX::instance()->entityVisibilityStamp,
                             (double)c->geom.numSubEdges,
                             (double)c->geom.curveType,
                             (double)c->color.geom.curve,
                             (double)c->geom.highlightOrphans,
                             (double)c->color.geom.highlight[0],
                             (double)c->color.geom.highlight[1],
                             (double)c->geom.useTransform};
  bool cylinders = (c->geom.curveType > 0);
  std::vector<SPoint3> pts;
  if(cylinders) {
    glyphToken gt;
    for(auto v : tok) gt.add(v);
    gt.add(ctx->pixel_equiv_x / ctx->s[0]);
    gt.add(c->geom.curveWidth);
    glyphList *g;
    if(!glyphCache::get(m, GLYPH_GEOM_CURVES, gt, g)) {
      double r = c->geom.curveWidth * ctx->pixel_equiv_x / ctx->s[0];
      for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
        GEdge *e = *it;
        if(!e->getVisibility()) continue;
        if(e->geomType() == GEntity::DiscreteCurve ||
           e->geomType() == GEntity::PartitionCurve ||
           e->geomType() == GEntity::BoundaryLayerCurve)
          continue;
        curvePoints(ctx, e, pts);
        unsigned int col = curveColor(e);
        for(std::size_t i = 0; i + 1 < pts.size(); i++) {
          double x[2] = {pts[i].x(), pts[i + 1].x()};
          double y[2] = {pts[i].y(), pts[i + 1].y()};
          double z[2] = {pts[i].z(), pts[i + 1].z()};
          g->addCylinder(x, y, z, r, r, col);
        }
      }
    }
    // the inside of the open end of a tube shows: lit on both sides, as the
    // pass drawing them after the surfaces had left it
    gmshLightTwoSide(c->geom.lightTwoSide ? true : false);
    g->draw(ctx, c->geom.light);
    gmshLightTwoSide(false);
    return true;
  }
  mergedCurves &mc = _mergedCurves[m];
  if(!mc.lines || tok != mc.token) {
    delete mc.lines;
    mc.lines = new VertexArray(2, 1000);
    mc.token = tok;
    for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
      GEdge *e = *it;
      if(!e->getVisibility()) continue;
      if(e->geomType() == GEntity::DiscreteCurve ||
         e->geomType() == GEntity::PartitionCurve ||
         e->geomType() == GEntity::BoundaryLayerCurve)
        continue;
      curvePoints(ctx, e, pts);
      unsigned int col[2];
      col[0] = col[1] = curveColor(e);
      for(std::size_t i = 0; i + 1 < pts.size(); i++) {
        double x[2] = {pts[i].x(), pts[i + 1].x()};
        double y[2] = {pts[i].y(), pts[i + 1].y()};
        double z[2] = {pts[i].z(), pts[i + 1].z()};
        mc.lines->add(x, y, z, nullptr, col, nullptr, false);
      }
    }
    mc.lines->finalize();
  }
  if(mc.lines->getNumVertices()) {
    gmshLightTwoSide(false);
    gmshLighting(false);
    gmshLineWidth((float)c->geom.curveWidth);
    gl2psLineWidth((float)(c->geom.curveWidth * c->print.epsLineWidthFactor));
    gmshBindVertexArray(mc.lines, false, true);
    drawVertexArray(mc.lines, GL_LINES);
    gmshUnbindArrays();
  }
  return true;
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
    bool merged = _curvesMerged && CTX::instance()->geom.curves;
    bool drawIt = (CTX::instance()->geom.curves ||
                   e->getSelection() == GEntity::SelectShow) &&
                  (!merged || e->getSelection());
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
          double w = e->getSelection() ?
                       CTX::instance()->geom.selectedCurveWidth :
                       CTX::instance()->geom.curveWidth;
          if(glyphList *g = geomGlyphs(_ctx)) {
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

// The surfaces of a model drawn as their triangulation (wireframe or solid),
// merged into one array kept between frames and drawn at once, rather than
// an array per surface: 14,400 surfaces took 70 ms a frame with the shader
// pipeline, a draw call each. Merged from the arrays of the surfaces, which
// keep their colours, and rebuilt when one of them is dropped or the
// geometry changes (CTX::geom.changed, ENT_SURFACE), or the visibilities.
// The selected surfaces are drawn again on top by the per-entity pass, and
// a picking pass draws them one at a time as before.
namespace {
  struct mergedSurfaces {
    VertexArray *triangles = nullptr;
    std::vector<double> token;
  };
  std::map<GModel *, mergedSurfaces> _mergedSurfaces;
  bool _surfacesMerged = false;
} // namespace

static bool drawMergedSurfaces(drawContext *ctx, GModel *m)
{
  CTX *c = CTX::instance();
  if(ctx->render_mode == drawContext::GMSH_SELECT) return false;
  if(!c->geom.surfaces || c->geom.surfaceType < 1) return false;
  if(c->hideUnselected) return false;
  for(auto it = _mergedSurfaces.begin(); it != _mergedSurfaces.end();) {
    if(std::find(GModel::list.begin(), GModel::list.end(), it->first) ==
       GModel::list.end()) {
      delete it->second.triangles;
      it = _mergedSurfaces.erase(it);
    }
    else
      it++;
  }
  std::vector<double> tok = {(double)c->geom.stamp[2],
                             (double)c->entityVisibilityStamp};
  mergedSurfaces &ms = _mergedSurfaces[m];
  if(!ms.triangles || tok != ms.token) {
    delete ms.triangles;
    ms.triangles = new VertexArray(3, 1000);
    for(auto it = m->firstFace(); it != m->lastFace(); it++) {
      GFace *f = *it;
      if(!f->getVisibility()) continue;
      if(f->geomType() == GEntity::PartitionSurface ||
         f->geomType() == GEntity::BoundaryLayerSurface)
        continue;
      f->fillVertexArray();
      if(f->va_geom_triangles) ms.triangles->merge(f->va_geom_triangles);
    }
    ms.triangles->finalize();
    // after the arrays of the surfaces have been filled, which may have
    // dropped some of them
    c->stampChanges();
    ms.token = {(double)c->geom.stamp[2], (double)c->entityVisibilityStamp};
  }
  VertexArray *va = ms.triangles;
  if(!va->getNumVertices()) return true;
  bool normals = c->geom.light && va->hasNormals();
  if(normals) gmshLighting(true);
  gmshBindVertexArray(va, normals, va->hasColors());
  if(c->polygonOffset) glEnable(GL_POLYGON_OFFSET_FILL);
  gmshLightTwoSide(c->geom.surfaceType > 1 && c->geom.lightTwoSide);
  gmshPolygonFill(c->geom.surfaceType > 1);
  // a wireframe is drawn half as wide as the curves, as drawGFace does
  gmshLineWidth((float)(c->geom.curveWidth / 2.));
  gl2psLineWidth((float)(c->geom.curveWidth / 2. * c->print.epsLineWidthFactor));
  drawVertexArray(va, GL_TRIANGLES);
  glDisable(GL_POLYGON_OFFSET_FILL);
  gmshLighting(false);
  gmshPolygonFill(true);
  gmshUnbindArrays();
  return true;
}

class drawGFace {
private:
  drawContext *_ctx;
  void _drawVertexArray(VertexArray *va, bool useNormalArray,
                        int forceColor = 0, unsigned int color = 0)
  {
    if(!va || !va->getNumVertices()) return;
    bool normals =
      !_ctx->inPickColorMode() && useNormalArray && va->hasNormals();
    if(normals) gmshLighting(true);
    bool colors = !_ctx->inPickColorMode() && !forceColor && va->hasColors();
    gmshBindVertexArray(va, normals, colors);
    if(!_ctx->inPickColorMode() && !colors)
      gmshColor4ubv((const void *)&color);
    if(CTX::instance()->polygonOffset) glEnable(GL_POLYGON_OFFSET_FILL);
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
    drawVertexArray(va, GL_TRIANGLES);
    glDisable(GL_POLYGON_OFFSET_FILL);
    gmshLighting(false);
    gmshPolygonFill(true);
    gmshUnbindArrays();
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
        bool merged = _surfacesMerged && CTX::instance()->geom.surfaces;
        if(!merged || selected) {
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
      {
        // nothing left for the per-point pass when the batch drew them all
        // a mixed geometry is drawn entity by entity
        bool mixed = transparencyPass != TRANSPARENCY_ALL &&
                     !gmshGeometryColorsAreTransparent();
        bool batched = !mixed && drawGeomPointsBatched(this, m);
        CTX *c = CTX::instance();
        if(c->geom.pointLabels || GEntity::numSelected ||
           (c->geom.points && !batched))
          std::for_each(m->firstVertex(), m->lastVertex(),
                        drawGVertex(this, batched));
      }
      {
        bool mixed = transparencyPass != TRANSPARENCY_ALL &&
                     !gmshGeometryColorsAreTransparent();
        _curvesMerged = !mixed && !getTransform() && drawMergedCurves(this, m);
        CTX *c = CTX::instance();
        // one by one only what the kept curves do not draw: a million curves
        // were walked at every frame for nothing
        if(c->geom.curveLabels || c->geom.tangents || GEntity::numSelected ||
           (c->geom.curves && !_curvesMerged))
          std::for_each(m->firstEdge(), m->lastEdge(), drawGEdge(this));
        _curvesMerged = false;
      }
      {
        bool mixed = transparencyPass != TRANSPARENCY_ALL &&
                     !gmshGeometryColorsAreTransparent();
        _surfacesMerged = !mixed && drawMergedSurfaces(this, m);
        CTX *c = CTX::instance();
        if(c->geom.surfaceLabels || c->geom.normals || GEntity::numSelected ||
           (c->geom.surfaces && !_surfacesMerged))
          std::for_each(m->firstFace(), m->lastFace(), drawGFace(this));
        _surfacesMerged = false;
      }
      std::for_each(m->firstRegion(), m->lastRegion(), drawGRegion(this));
    }
  }

  _geomGlyphs.draw(this, CTX::instance()->geom.light);
  _geomGlyphs.clear();

  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);
}
