// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "drawContext.h"
#include "Context.h"
#include "gl2ps.h"
#include "VertexArray.h"
#include "GModel.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "GEdgeCompound.h"
#include "GFaceCompound.h"

class drawGVertex {
 private :
  drawContext *_ctx;
 public :
  drawGVertex(drawContext *ctx) : _ctx(ctx){}
  void operator () (GVertex *v)
  {
    if(!v->getVisibility()) return;
    if(v->geomType() == GEntity::BoundaryLayerPoint) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   v->model() == GModel::current());
    if(select) {
      glPushName(0);
      glPushName(v->tag());
    }

    if(v->getSelection()) {
      glPointSize((float)CTX::instance()->geom.selectedPointSize);
      gl2psPointSize((float)(CTX::instance()->geom.selectedPointSize *
                             CTX::instance()->print.epsPointSizeFactor));
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.selection);
    }
    else {
      glPointSize((float)CTX::instance()->geom.pointSize);
      gl2psPointSize((float)(CTX::instance()->geom.pointSize *
                             CTX::instance()->print.epsPointSizeFactor));
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.point);
    }

    if(CTX::instance()->geom.highlightOrphans){
      std::list<GEdge*> edges = v->edges();
      if(edges.size() == 0)
        glColor4ubv((GLubyte *) & CTX::instance()->color.geom.highlight[0]);
      else if(edges.size() == 1)
        glColor4ubv((GLubyte *) & CTX::instance()->color.geom.highlight[1]);
    }

    double x = v->x(), y = v->y(), z = v->z();
    _ctx->transform(x, y, z);

    if(CTX::instance()->geom.points) {
      if(CTX::instance()->geom.pointType > 0) {
        if(v->getSelection())
          _ctx->drawSphere(CTX::instance()->geom.selectedPointSize, x, y, z,
                           CTX::instance()->geom.light);
        else
          _ctx->drawSphere(CTX::instance()->geom.pointSize, x, y, z,
                           CTX::instance()->geom.light);
      }
      else {
        glBegin(GL_POINTS);
        glVertex3d(x, y, z);
        glEnd();
      }
    }

    if(CTX::instance()->geom.pointsNum) {
      char Num[100];
      sprintf(Num, "%d", v->tag());
      double offset = (0.5 * CTX::instance()->geom.pointSize +
                       0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      glRasterPos3d(x + offset / _ctx->s[0],
                    y + offset / _ctx->s[1],
                    z + offset / _ctx->s[2]);
      _ctx->drawString(Num);
    }

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

class drawGEdge {
 private :
  drawContext *_ctx;
 public :
  drawGEdge(drawContext *ctx) : _ctx(ctx){}
  void operator () (GEdge *e)
  {
    if(!e->getVisibility()) return;
    if(e->geomType() == GEntity::DiscreteCurve) return;
    if(e->geomType() == GEntity::PartitionCurve) return;
    if(e->geomType() == GEntity::BoundaryLayerCurve) return;
    //    if(e->geomType() == GEntity::CompoundCurve) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   e->model() == GModel::current());
    if(select) {
      glPushName(1);
      glPushName(e->tag());
    }

    if(e->getSelection()) {
      glLineWidth((float)CTX::instance()->geom.selectedLineWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.selectedLineWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.selection);
    }
    else {
      glLineWidth((float)CTX::instance()->geom.lineWidth);
      gl2psLineWidth((float)(CTX::instance()->geom.lineWidth *
                             CTX::instance()->print.epsLineWidthFactor));
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.line);
    }

    if(CTX::instance()->geom.highlightOrphans){
      std::list<GFace*> faces = e->faces();
      if(faces.size() == 0)
        glColor4ubv((GLubyte *) & CTX::instance()->color.geom.highlight[0]);
      else if(faces.size() == 1)
        glColor4ubv((GLubyte *) & CTX::instance()->color.geom.highlight[1]);
    }

    Range<double> t_bounds = e->parBounds(0);
    double t_min = t_bounds.low();
    double t_max = t_bounds.high();

    if(CTX::instance()->geom.lines) {
      int N = e->minimumDrawSegments() + 1;
      if(CTX::instance()->geom.lineType > 0) {
        for(int i = 0; i < N - 1; i++) {
          double t1 = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
          GPoint p1 = e->point(t1);
          double t2 = t_min + (double)(i + 1) / (double)(N - 1) * (t_max - t_min);
          GPoint p2 = e->point(t2);
          double x[2] = {p1.x(), p2.x()};
          double y[2] = {p1.y(), p2.y()};
          double z[2] = {p1.z(), p2.z()};
          _ctx->transform(x[0], y[0], z[0]);
          _ctx->transform(x[1], y[1], z[1]);
          _ctx->drawCylinder(e->getSelection() ? CTX::instance()->geom.selectedLineWidth :
                             CTX::instance()->geom.lineWidth, x, y, z,
                             CTX::instance()->geom.light);
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

    if(CTX::instance()->geom.linesNum) {
      GPoint p = e->point(t_min + 0.5 * (t_max - t_min));
      char Num[100];
      sprintf(Num, "%d", e->tag());
      double offset = (0.5 * CTX::instance()->geom.lineWidth +
                       0.1 * CTX::instance()->glFontSize) * _ctx->pixel_equiv_x;
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      glRasterPos3d(x + offset / _ctx->s[0],
                    y + offset / _ctx->s[1],
                    z + offset / _ctx->s[2]);
      _ctx->drawString(Num);
    }

    if(CTX::instance()->geom.tangents) {
      double t = t_min + 0.5 * (t_max - t_min);
      GPoint p = e->point(t);
      SVector3 der = e->firstDer(t);
      der.normalize();
      for(int i = 0; i < 3; i++)
        der[i] *= CTX::instance()->geom.tangents * _ctx->pixel_equiv_x / _ctx->s[i];
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.tangents);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      _ctx->transformOneForm(der[0], der[1], der[2]);
      _ctx->drawVector(CTX::instance()->vectorType, 0, x, y, z, der[0], der[1], der[2],
                       CTX::instance()->geom.light);
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
  void _drawVertexArray(VertexArray *va, bool useNormalArray, int forceColor=0,
                        unsigned int color=0)
  {
    if(!va || !va->getNumVertices()) return;
    glVertexPointer(3, GL_FLOAT, 0, va->getVertexArray());
    glEnableClientState(GL_VERTEX_ARRAY);
    if(useNormalArray){
      glEnable(GL_LIGHTING);
      glNormalPointer(GL_BYTE, 0, va->getNormalArray());
      glEnableClientState(GL_NORMAL_ARRAY);
    }
    else
      glDisableClientState(GL_NORMAL_ARRAY);
    if(forceColor){
      glDisableClientState(GL_COLOR_ARRAY);
      glColor4ubv((GLubyte *) & color);
    }
    else{
      glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
      glEnableClientState(GL_COLOR_ARRAY);
    }
    if(CTX::instance()->polygonOffset) glEnable(GL_POLYGON_OFFSET_FILL);
    if(CTX::instance()->geom.surfaceType > 1)
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, va->getNumVertices());
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
  void _drawParametricGFace(GFace *f)
  {
    if(CTX::instance()->geom.surfaceType > 0)
      f->fillVertexArray(f->geomType() == GEntity::ProjectionFace);

    Range<double> ubounds = f->parBounds(0);
    Range<double> vbounds = f->parBounds(1);
    bool tri = (f->geomType() == GEntity::RuledSurface && f->edges().size() == 3);
    double c = tri ? 0.75 : 0.5;
    double uav = c * (ubounds.high() + ubounds.low());
    double vav = (1-c) * (vbounds.high() + vbounds.low());
    double u2 = 0.5 * (ubounds.high() + ubounds.low());
    double v2 = 0.5 * (vbounds.high() + vbounds.low());

    if(CTX::instance()->geom.surfaces){
      if(CTX::instance()->geom.surfaceType > 0 && f->va_geom_triangles){
        bool selected = false;
        if (f->getSelection() || (f->getCompound() && f->getCompound()->getSelection()))
          selected = true;
        _drawVertexArray
          (f->va_geom_triangles, CTX::instance()->geom.light,
           (f->geomType() == GEntity::ProjectionFace) ? true : selected,
           (f->geomType() == GEntity::ProjectionFace) ?
           CTX::instance()->color.geom.projection :
           CTX::instance()->color.geom.selection);
      }
      else{
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x1F1F);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        const double ud = (ubounds.high() - ubounds.low());
        const double vd = (vbounds.high() - vbounds.low());
        int N = 20;
        GPoint p;
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < N; i++) {
          if(tri)
            p = f->point(u2 + u2 * (double)i / (double)(N - 1),
                         vbounds.low() + v2 * (double)i / (double)(N - 1));
          else
            p = f->point(ubounds.low() + ud * (double)i / (double)(N - 1), vav);
          double x = p.x(), y = p.y(), z = p.z();
          _ctx->transform(x, y, z);
          glVertex3d(x, y, z);
        }
        glEnd();
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < N; i++) {
          if(tri)
            p = f->point(u2 + u2 * (double)i / (double)(N - 1),
                         v2 - v2 * (double)i / (double)(N - 1));
          else
            p = f->point(uav, vbounds.low() + vd * (double)i / (double)(N - 1));
          double x = p.x(), y = p.y(), z = p.z();
          _ctx->transform(x, y, z);
          glVertex3d(x, y, z);
        }
        glEnd();

        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
      }
    }

    if(CTX::instance()->geom.surfacesNum) {
      GPoint p = f->point(uav, vav);
      char Num[100];
      sprintf(Num, "%d", f->tag());
      double offset = 0.1 * CTX::instance()->glFontSize * _ctx->pixel_equiv_x;
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      glRasterPos3d(x + offset / _ctx->s[0],
                    y + offset / _ctx->s[1],
                    z + offset / _ctx->s[2]);
      _ctx->drawString(Num);
    }

    if(CTX::instance()->geom.normals) {
      GPoint p = f->point(uav, vav);
      SVector3 n = f->normal(SPoint2(uav, vav));
      for(int i = 0; i < 3; i++)
        n[i] *= CTX::instance()->geom.normals * _ctx->pixel_equiv_x / _ctx->s[i];
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.normals);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      _ctx->transformTwoForm(n[0], n[1], n[2]);
      _ctx->drawVector(CTX::instance()->vectorType, 0, x, y, z, n[0], n[1], n[2],
                       CTX::instance()->geom.light);
    }
  }
  void _drawPlaneGFace(GFace *f)
  {
    if(CTX::instance()->geom.surfaceType > 0)
      f->fillVertexArray();

    if(!CTX::instance()->geom.surfaceType || !f->va_geom_triangles ||
       CTX::instance()->geom.surfacesNum || CTX::instance()->geom.normals)
      f->buildRepresentationCross();

    if(CTX::instance()->geom.surfaces) {
      bool selected = false;
      if (f->getSelection() || (f->getCompound() && f->getCompound()->getSelection()))
        selected = true;
      if(CTX::instance()->geom.surfaceType > 0 && f->va_geom_triangles){
        _drawVertexArray(f->va_geom_triangles, CTX::instance()->geom.light,
                         f->getSelection(), CTX::instance()->color.geom.selection);
      }
      else{
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x1F1F);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        glBegin(GL_LINES);
        for(unsigned int i = 0; i < f->cross.size(); i++){
          double x = f->cross[i].x(), y = f->cross[i].y(), z = f->cross[i].z();
          _ctx->transform(x, y, z);
          glVertex3d(x, y, z);
        }
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
      }
    }

    if(f->cross.size() < 2) return;

    if(CTX::instance()->geom.surfacesNum) {
      char Num[100];
      sprintf(Num, "%d", f->tag());
      double offset = 0.1 * CTX::instance()->glFontSize * _ctx->pixel_equiv_x;
      double x = 0.5 * (f->cross[0].x() + f->cross[1].x());
      double y = 0.5 * (f->cross[0].y() + f->cross[1].y());
      double z = 0.5 * (f->cross[0].z() + f->cross[1].z());
      _ctx->transform(x, y, z);
      glRasterPos3d(x + offset / _ctx->s[0],
                    y + offset / _ctx->s[0],
                    z + offset / _ctx->s[0]);
      _ctx->drawString(Num);
    }

    if(CTX::instance()->geom.normals) {
      SPoint3 p(0.5 * (f->cross[0].x() + f->cross[1].x()),
                0.5 * (f->cross[0].y() + f->cross[1].y()),
                0.5 * (f->cross[0].z() + f->cross[1].z()));
      SPoint2 uv = f->parFromPoint(p);
      SVector3 n = f->normal(uv);
      for(int i = 0; i < 3; i++)
        n[i] *= CTX::instance()->geom.normals * _ctx->pixel_equiv_x / _ctx->s[i];
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.normals);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      _ctx->transformTwoForm(n[0], n[1], n[2]);
      _ctx->drawVector(CTX::instance()->vectorType, 0, x, y, z, n[0], n[1], n[2],
                       CTX::instance()->geom.light);
    }
  }

  void _drawCompoundGFace(GFace *f, bool visible = false, bool selected = false)
  {
    GFaceCompound *fc = (GFaceCompound*) f;
    std::list<GFace*> faces = fc->getCompounds();
    for (std::list<GFace*>::iterator it = faces.begin(); it!=faces.end(); it++) {
      if ((*it)->geomType() == GEntity::DiscreteSurface) continue;
      if ((*it)->geomType() == GEntity::PartitionSurface) continue;
      if ((*it)->geomType() == GEntity::BoundaryLayerSurface) continue;

      if((*it)->geomType() == GEntity::CompoundSurface)
        _drawCompoundGFace((*it));
      else if ((*it)->geomType() == GEntity::Plane)
        _drawPlaneGFace((*it));
      else
        _drawParametricGFace((*it));
    }
  }

 public :
  drawGFace(drawContext *ctx) : _ctx(ctx) {}
  void operator () (GFace *f)
  {
    if(!f->getVisibility()) return;
    if(f->geomType() == GEntity::DiscreteSurface) return;
    if(f->geomType() == GEntity::PartitionSurface) return;
    if(f->geomType() == GEntity::BoundaryLayerSurface) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   f->model() == GModel::current());
    if(select) {
      glPushName(2);
      glPushName(f->tag());
    }

    if(f->getSelection()) {
      glLineWidth((float)(CTX::instance()->geom.selectedLineWidth / 2.));
      gl2psLineWidth((float)(CTX::instance()->geom.selectedLineWidth / 2. *
                             CTX::instance()->print.epsLineWidthFactor));
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.selection);
    }
    else {
      glLineWidth((float)(CTX::instance()->geom.lineWidth / 2.));
      gl2psLineWidth((float)(CTX::instance()->geom.lineWidth / 2. *
                             CTX::instance()->print.epsLineWidthFactor));
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.surface);
    }

    if(f->geomType() == GEntity::CompoundSurface)
      _drawCompoundGFace(f);
    else if(f->geomType() == GEntity::Plane)
      _drawPlaneGFace(f);
    else
      _drawParametricGFace(f);

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

class drawGRegion {
 private :
  drawContext *_ctx;
 public :
  drawGRegion(drawContext *ctx) : _ctx(ctx){}
  void operator () (GRegion *r)
  {
    if(!r->getVisibility()) return;
    //    if(r->geomType() == GEntity::DiscreteVolume) return;

    bool select = (_ctx->render_mode == drawContext::GMSH_SELECT &&
                   r->model() == GModel::current());
    if(select) {
      glPushName(3);
      glPushName(r->tag());
    }

    if(r->getSelection())
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.selection);
    else
      glColor4ubv((GLubyte *) & CTX::instance()->color.geom.volume);

    SPoint3 p = r->bounds().center();
    const double size = 8.;

    double x = p.x(), y = p.y(), z = p.z();
    _ctx->transform(x, y, z);

    if(CTX::instance()->geom.volumes)
      _ctx->drawSphere(size, x, y, z, CTX::instance()->geom.light);

    if(CTX::instance()->geom.volumesNum){
      char Num[100];
      sprintf(Num, "%d", r->tag());
      double offset = (0.5 * size + 0.1 * CTX::instance()->glFontSize) *
        _ctx->pixel_equiv_x;
      glRasterPos3d(x + offset / _ctx->s[0],
                    y + offset / _ctx->s[1],
                    z + offset / _ctx->s[2]);
      _ctx->drawString(Num);
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

  if(CTX::instance()->geom.lightTwoSide)
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  else
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

  for(int i = 0; i < 6; i++)
    if(CTX::instance()->geom.clip & (1 << i))
      glEnable((GLenum)(GL_CLIP_PLANE0 + i));
    else
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  for(unsigned int i = 0; i < GModel::list.size(); i++){
    GModel *m = GModel::list[i];
    if(m->getVisibility() && isVisible(m)){
      if(CTX::instance()->geom.points || CTX::instance()->geom.pointsNum)
        std::for_each(m->firstVertex(), m->lastVertex(), drawGVertex(this));
      if(CTX::instance()->geom.lines || CTX::instance()->geom.linesNum ||
         CTX::instance()->geom.tangents)
        std::for_each(m->firstEdge(), m->lastEdge(), drawGEdge(this));
      if(CTX::instance()->geom.surfaces || CTX::instance()->geom.surfacesNum ||
         CTX::instance()->geom.normals) {
        std::for_each(m->firstFace(), m->lastFace(), drawGFace(this));
      }
      if(CTX::instance()->geom.volumes || CTX::instance()->geom.volumesNum)
        std::for_each(m->firstRegion(), m->lastRegion(), drawGRegion(this));
    }
  }

  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}
