// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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

  if(CTX::instance()->geom.labelType == 0) {
    std::vector<std::string> info =
      SplitString(e->getInfoString(false, true), '\n');
    for(int line = 0; line < (int)info.size(); line++)
      ctx->drawString(info[line].c_str(), xx, yy, zz, line);
    return;
  }

  char str[1024];
  if(CTX::instance()->geom.labelType == 1) {
    sprintf(str, "%d", e->tag());
  }
  else if(CTX::instance()->geom.labelType == 2) {
    strcpy(str, "");
    for(std::size_t i = 0; i < e->physicals.size(); i++) {
      char tmp[32];
      if(i) strcat(str, ", ");
      sprintf(tmp, "%d", e->physicals[i]);
      strcat(str, tmp);
    }
  }
  else if(CTX::instance()->geom.labelType == 3) {
    strcpy(str, e->model()->getElementaryName(e->dim(), e->tag()).c_str());
  }
  else {
    strcpy(str, "");
    std::string name = "";
    for(std::size_t i = 0; i < e->physicals.size(); i++) {
      if(name.size()) strcat(str, ", ");
      name = e->model()->getPhysicalName(e->dim(), std::abs(e->physicals[i]));
      if(name.size()) strcat(str, name.c_str());
    }
  }

  ctx->drawString(str, xx, yy, zz);
}

class drawGVertex {
private:
  drawContext *_ctx;

public:
  drawGVertex(drawContext *ctx) : _ctx(ctx) {}
  void operator()(GVertex *v)
  {
    if(!v->getVisibility()) return;
    if(v->geomType() == GEntity::BoundaryLayerPoint) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   v->model() == GModel::current());
    if(select) {
      glPushName(0);
      glPushName(v->tag());
    }

    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    double fact = _ctx->highResolutionPixelFactor();
    double ps = CTX::instance()->geom.pointSize * fact;
    double sps = CTX::instance()->geom.selectedPointSize * fact;

    if(v->getSelection()) {
      glPointSize((float)sps);
      gl2psPointSize((float)(CTX::instance()->geom.selectedPointSize *
                             CTX::instance()->print.epsPointSizeFactor));
      glColor4ubv((GLubyte *)&CTX::instance()->color.geom.selection);
    }
    else {
      glPointSize((float)ps);
      gl2psPointSize((float)(CTX::instance()->geom.pointSize *
                             CTX::instance()->print.epsPointSizeFactor));
      unsigned int col = v->useColor() ? v->getColor() :
        CTX::instance()->color.geom.point;
      glColor4ubv((GLubyte *)&col);
    }

    if(CTX::instance()->geom.highlightOrphans) {
      std::vector<GEdge *> const &edges = v->edges();
      if(edges.size() == 0)
        glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
      else if(edges.size() == 1)
        glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[1]);
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
        glBegin(GL_POINTS);
        glVertex3d(x, y, z);
        glEnd();
      }
    }

    if(CTX::instance()->geom.pointLabels || v->getSelection() > 1) {
      double offset =
        (0.5 * ps + 0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      if(v->getSelection() > 1)
        glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
      drawEntityLabel(_ctx, v, x, y, z, offset);
    }

    if(select) {
      glPopName();
      glPopName();
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
      glPushName(1);
      glPushName(e->tag());
    }

    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    if(e->getSelection()) {
      glLineWidth((float)CTX::instance()->geom.selectedCurveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      glColor4ubv((GLubyte *)&CTX::instance()->color.geom.selection);
    }
    else {
      glLineWidth((float)CTX::instance()->geom.curveWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.curveWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int col = e->useColor() ? e->getColor() :
        CTX::instance()->color.geom.curve;
      glColor4ubv((GLubyte *)&col);
    }

    if(CTX::instance()->geom.highlightOrphans) {
      std::vector<GFace *> faces = e->faces();
      if(faces.empty())
        glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
      else if(faces.size() == 1)
        glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[1]);
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
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < N; i++) {
          double t = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
          GPoint p = e->point(t);
          double x = p.x(), y = p.y(), z = p.z();
          _ctx->transform(x, y, z);
          glVertex3d(x, y, z);
        }
        glEnd();
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
        glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
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
      glColor4ubv((GLubyte *)&CTX::instance()->color.geom.tangents);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      _ctx->transformOneForm(der[0], der[1], der[2]);
      _ctx->drawVector(CTX::instance()->vectorType, 0, x, y, z, der[0], der[1],
                       der[2], CTX::instance()->geom.light);
    }

    if(select) {
      glPopName();
      glPopName();
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
    glVertexPointer(3, GL_FLOAT, 0, va->getVertexArray());
    glEnableClientState(GL_VERTEX_ARRAY);
    if(useNormalArray) {
      glEnable(GL_LIGHTING);
      glNormalPointer(NORMAL_GLTYPE, 0, va->getNormalArray());
      glEnableClientState(GL_NORMAL_ARRAY);
    }
    else {
      glDisableClientState(GL_NORMAL_ARRAY);
    }
    if(forceColor) {
      glDisableClientState(GL_COLOR_ARRAY);
      glColor4ubv((GLubyte *)&color);
    }
    else {
      glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
      glEnableClientState(GL_COLOR_ARRAY);
    }
    if(CTX::instance()->polygonOffset) glEnable(GL_POLYGON_OFFSET_FILL);
    if(CTX::instance()->geom.surfaceType > 1) {
      if(CTX::instance()->geom.lightTwoSide)
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
      else
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else {
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    glDrawArrays(GL_TRIANGLES, 0, va->getNumVertices());
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
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
      glPushName(2);
      glPushName(f->tag());
    }

    if(f->getSelection()) {
      glLineWidth((float)(CTX::instance()->geom.selectedCurveWidth / 2.));
      gl2psLineWidth((float)(CTX::instance()->geom.selectedCurveWidth / 2. *
                             CTX::instance()->print.epsLineWidthFactor));
      glColor4ubv((GLubyte *)&CTX::instance()->color.geom.selection);
    }
    else {
      glLineWidth((float)(CTX::instance()->geom.curveWidth / 2.));
      gl2psLineWidth((float)(CTX::instance()->geom.curveWidth / 2. *
                             CTX::instance()->print.epsLineWidthFactor));
      unsigned int col = f->useColor() ? f->getColor() :
        CTX::instance()->color.geom.surface;
      glColor4ubv((GLubyte *)&col);
    }

    if(CTX::instance()->geom.lightTwoSide)
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    else
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

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
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x0F0F);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        for(int dim = 0; dim < 2; dim++) {
          for(std::size_t i = 0; i < f->cross[dim].size(); i++) {
            if(f->cross[dim][i].size() >= 2) {
              glBegin(GL_LINE_STRIP);
              for(std::size_t j = 0; j < f->cross[dim][i].size(); j++) {
                double x = f->cross[dim][i][j].x();
                double y = f->cross[dim][i][j].y();
                double z = f->cross[dim][i][j].z();
                _ctx->transform(x, y, z);
                glVertex3d(x, y, z);
              }
              glEnd();
            }
          }
        }
        glDisable(GL_LINE_STIPPLE);
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
          glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
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
        glColor4ubv((GLubyte *)&CTX::instance()->color.geom.normals);
        double x = p.x(), y = p.y(), z = p.z();
        _ctx->transform(x, y, z);
        _ctx->transformTwoForm(n[0], n[1], n[2]);
        _ctx->drawVector(CTX::instance()->vectorType, 0, x, y, z, n[0], n[1],
                         n[2], CTX::instance()->geom.light);
      }
    }

    if(select) {
      glPopName();
      glPopName();
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
      glPushName(3);
      glPushName(r->tag());
    }

    if(CTX::instance()->geom.lightTwoSide)
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    else
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    if(r->getSelection()){
      glColor4ubv((GLubyte *)&CTX::instance()->color.geom.selection);
    }
    else{
      unsigned int col = r->useColor() ? r->getColor() :
        CTX::instance()->color.geom.volume;
      glColor4ubv((GLubyte *)&col);
    }

    const double size = 8.;
    double x = 0., y = 0., z = 0.;

    if(CTX::instance()->geom.volumes || CTX::instance()->geom.volumeLabels ||
       r->getSelection() > 1) {
      SPoint3 p = r->bounds(true).center(); // fast approx if mesh-based
      x = p.x();
      y = p.y();
      z = p.z();
      _ctx->transform(x, y, z);
    }

    if(CTX::instance()->geom.volumes || r->getSelection() > 1)
      _ctx->drawSphere(size, x, y, z, CTX::instance()->geom.light);

    if(CTX::instance()->geom.volumeLabels || r->getSelection() > 1) {
      double offset =
        (1. * size + 0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      if(r->getSelection() > 1)
        glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
      drawEntityLabel(_ctx, r, x, y, z, offset);
    }

    if(select) {
      glPopName();
      glPopName();
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
      glEnable((GLenum)(GL_CLIP_PLANE0 + i));
    else
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    if(m->getVisibility() && isVisible(m)) {
      std::for_each(m->firstVertex(), m->lastVertex(), drawGVertex(this));
      std::for_each(m->firstEdge(), m->lastEdge(), drawGEdge(this));
      std::for_each(m->firstFace(), m->lastFace(), drawGFace(this));
      std::for_each(m->firstRegion(), m->lastRegion(), drawGRegion(this));
    }
  }

  for(int i = 0; i < 6; i++) glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}
