// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include "drawContext.h"
#include "Context.h"
#include "gl2ps.h"
#include "VertexArray.h"
#include "GModel.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "StringUtils.h"

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

// Draw every plain, unselected geometry point in one call instead of a
// gmshBegin/gmshVertex3d/gmshEnd block each. A model split into partitions has one
// geometry point per partition boundary node, so this is tens of thousands of
// one-vertex draw calls per frame, and the driver spends longer setting each
// of them up than drawing it. Returns true when it has drawn the points, so
// that the per-entity pass can skip them; selected points and labels are left
// to that pass, which paints them on top.
static bool drawGeomPointsBatched(drawContext *ctx, GModel *m)
{
  CTX *c = CTX::instance();
  if(ctx->render_mode == drawContext::GMSH_SELECT) return false;
  if(!c->geom.points) return false; // only the selected ones are drawn
  if(c->geom.pointType > 0) return false; // spheres, not points
  if(c->geom.highlightOrphans) return false; // needs the per-entity colours

  static std::vector<float> xyz;
  static std::vector<unsigned char> col;
  xyz.clear();
  col.clear();
  for(auto it = m->firstVertex(); it != m->lastVertex(); it++) {
    GVertex *v = *it;
    if(!v->getVisibility()) continue;
    if(v->geomType() == GEntity::BoundaryLayerPoint) continue;
    if(v->getSelection()) continue;
    double x = v->x(), y = v->y(), z = v->z();
    ctx->transform(x, y, z);
    xyz.push_back((float)x);
    xyz.push_back((float)y);
    xyz.push_back((float)z);
    unsigned int cc = v->useColor() ? v->getColor() : c->color.geom.point;
    const unsigned char *p = (const unsigned char *)&cc;
    for(int k = 0; k < 4; k++) col.push_back(p[k]);
  }
  if(xyz.empty()) return true;

  gmshLightTwoSide(false);
  gmshLighting(false);
  gmshPointSize((float)(c->geom.pointSize * ctx->highResolutionPixelFactor()));
  gl2psPointSize((float)(c->geom.pointSize * c->print.epsPointSizeFactor));
  gmshBindArrays(&xyz[0], &col[0]);
  gmshDrawArrays(GL_POINTS, (int)(xyz.size() / 3));
  gmshUnbindArrays();
  return true;
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

    if(v->getSelection()) {
      gmshPointSize((float)sps);
      gl2psPointSize((float)(CTX::instance()->geom.selectedPointSize *
                             CTX::instance()->print.epsPointSizeFactor));
      gmshColor4ubv((const void *)&CTX::instance()->color.geom.selection);
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

    if(CTX::instance()->geom.points || v->getSelection() > 1) {
      if(CTX::instance()->geom.pointType > 0) {
        if(v->getSelection())
          _ctx->drawSphere(sps, x, y, z, CTX::instance()->geom.light);
        else
          _ctx->drawSphere(ps, x, y, z, CTX::instance()->geom.light);
      }
      else {
        gmshBegin(GL_POINTS);
        gmshVertex3d(x, y, z);
        gmshEnd();
      }
    }

    if(CTX::instance()->geom.pointLabels || v->getSelection() > 1) {
      double offset =
        (0.5 * ps + 0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      if(v->getSelection() > 1)
        gmshColor4ubv((const void *)&CTX::instance()->color.fg);
      drawEntityLabel(_ctx, v, x, y, z, offset);
    }

    if(select) {
    }
  }
};

class drawGEdge {
private:
  drawContext *_ctx;

public:
  drawGEdge(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GEdge *e)
  {
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

    if(e->getSelection()) {
      gmshLineWidth((float)CTX::instance()->geom.selectedCurveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      gmshColor4ubv((const void *)&CTX::instance()->color.geom.selection);
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

    if(CTX::instance()->geom.curves || e->getSelection() > 1) {
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
          _ctx->drawCylinder(e->getSelection() ?
                               CTX::instance()->geom.selectedCurveWidth :
                               CTX::instance()->geom.curveWidth,
                             x, y, z, CTX::instance()->geom.light);
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

    if(CTX::instance()->geom.curveLabels || e->getSelection() > 1) {
      GPoint p = e->point(t_min + 0.5 * (t_max - t_min));
      double offset = (0.5 * CTX::instance()->geom.curveWidth +
                       0.1 * CTX::instance()->glFontSize) *
                      _ctx->pixel_equiv_x;
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      if(e->getSelection() > 1)
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
    bool normals =
      !_ctx->inPickColorMode() && useNormalArray && va->hasNormals();
    if(normals) gmshLighting(true);
    bool colors = !_ctx->inPickColorMode() && !forceColor && va->hasColors();
    gmshBindVertexArray(va, normals, colors);
    if(!_ctx->inPickColorMode() && !colors)
      gmshColor4ubv((const void *)&color);
    if(CTX::instance()->polygonOffset) glEnable(GL_POLYGON_OFFSET_FILL);
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
    if(!f->getVisibility()) return;
    if(f->geomType() == GEntity::PartitionSurface) return;
    if(f->geomType() == GEntity::BoundaryLayerSurface) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   f->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(2, f->tag());
    }

    if(f->getSelection()) {
      gmshLineWidth((float)(CTX::instance()->geom.selectedCurveWidth / 2.));
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth / 2. *
                             CTX::instance()->print.epsLineWidthFactor));
      gmshColor4ubv((const void *)&CTX::instance()->color.geom.selection);
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

    if((CTX::instance()->geom.surfaces || f->getSelection() > 1) &&
       CTX::instance()->geom.surfaceType > 0)
      f->fillVertexArray();

    if(((CTX::instance()->geom.surfaces || f->getSelection() > 1) &&
        CTX::instance()->geom.surfaceType == 0) ||
       CTX::instance()->geom.surfaceLabels || CTX::instance()->geom.normals)
      f->buildRepresentationCross();

    if(CTX::instance()->geom.surfaces || f->getSelection() > 1) {
      if(CTX::instance()->geom.surfaceType > 0 && f->va_geom_triangles) {
        bool selected = false;
        if(f->getSelection()) selected = true;
        _drawVertexArray(f->va_geom_triangles, CTX::instance()->geom.light,
                         selected, CTX::instance()->color.geom.selection);
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
      if(CTX::instance()->geom.surfaceLabels || f->getSelection() > 1) {
        double offset = 0.1 * CTX::instance()->glFontSize * _ctx->pixel_equiv_x;
        double x = f->cross[0][0][idx].x();
        double y = f->cross[0][0][idx].y();
        double z = f->cross[0][0][idx].z();
        _ctx->transform(x, y, z);
        if(f->getSelection() > 1)
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
    if(!r->getVisibility()) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   r->model() == GModel::current());
    if(select) {
      _ctx->setPickColor(3, r->tag());
    }

    if(CTX::instance()->geom.lightTwoSide)
      gmshLightTwoSide(true);
    else
      gmshLightTwoSide(false);

    if(r->getSelection()) {
      gmshLineWidth((float)CTX::instance()->geom.selectedCurveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      gmshColor4ubv((const void *)&CTX::instance()->color.geom.selection);
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
       r->getSelection() > 1) {
      SBoundingBox3d bb = r->bounds(true); // fast approx if mesh-based
      SPoint3 p = bb.center();
      x = p.x();
      y = p.y();
      z = p.z();
      d = bb.diag() / 50.;
      _ctx->transform(x, y, z);
    }

    if(CTX::instance()->geom.volumes || r->getSelection() > 1) {
      if(CTX::instance()->geom.volumeType == 0) {
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

    if(CTX::instance()->geom.volumeLabels || r->getSelection() > 1) {
      double offset =
        (1. * size + 0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      if(r->getSelection() > 1)
        gmshColor4ubv((const void *)&CTX::instance()->color.fg);
      drawEntityLabel(_ctx, r, x, y, z, offset);
    }

    if(select) {
    }
  }
};

void drawContext::drawGeom()
{
  if(!CTX::instance()->geom.draw) return;

  // draw any transient geometry stuff
  if(drawGeomTransient) (*drawGeomTransient)(this);

  for(int i = 0; i < 6; i++)
    if(CTX::instance()->geom.clip & (1 << i))
      gmshClipPlaneOn(i, true);
    else
      gmshClipPlaneOn(i, false);

  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    if(m->getVisibility() && isVisible(m)) {
      {
        // when the batch drew every point there is, the pass below would walk
        // the points only to return immediately for each of them
        bool batched = drawGeomPointsBatched(this, m);
        if(!batched || CTX::instance()->geom.pointLabels ||
           GEntity::numSelected)
          std::for_each(m->firstVertex(), m->lastVertex(),
                        drawGVertex(this, batched));
      }
      std::for_each(m->firstEdge(), m->lastEdge(), drawGEdge(this));
      std::for_each(m->firstFace(), m->lastFace(), drawGFace(this));
      std::for_each(m->firstRegion(), m->lastRegion(), drawGRegion(this));
    }
  }

  for(int i = 0; i < 6; i++) gmshClipPlaneOn(i, false);
}
