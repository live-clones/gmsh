// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshUI.h"
#include "Draw.h"
#include "Context.h"
#include "gl2ps.h"
#include "VertexArray.h"
#include "GModel.h"
#include "SBoundingBox3d.h"

extern Context_T CTX;

class visContext{
 public:
  visContext(){}
  virtual void transform(double &x, double &y, double &z){}
};

class visContextScaled : public visContext {
 private:
  bool _identityTransform;
  double _mat[3][3];
 public:
  visContextScaled(double mat[3][3]) : visContext()
  {
    if(mat[0][0] != 1. || mat[0][1] != 0. || mat[0][2] != 0. ||
       mat[1][0] != 0. || mat[1][1] != 1. || mat[1][2] != 0. ||
       mat[2][0] != 0. || mat[2][1] != 0. || mat[2][2] != 1.)
      _identityTransform = false;
    else
      _identityTransform = true;
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        _mat[i][j] = mat[i][j];
  }
  virtual void transform(double &x, double &y, double &z)
  {
    if(_identityTransform) return;
    double xyz[3] = {x, y, z};
    x = y = z = 0.;
    for(int k = 0; k < 3; k++){
      x += _mat[0][k] * xyz[k];
      y += _mat[1][k] * xyz[k];
      z += _mat[2][k] * xyz[k];
    }
  }
};

static void drawBBox(GEntity *e)
{
  return;
  glColor4ubv((GLubyte *) & CTX.color.fg);
  glLineWidth(CTX.line_width);
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
  SBoundingBox3d bb = e->bounds();
  Draw_Box(bb.min().x(), bb.min().y(), bb.min().z(),
           bb.max().x(), bb.max().y(), bb.max().z());
}

class drawGVertex {
 private :
  visContext *_ctx;
 public :
  drawGVertex(visContext *ctx) : _ctx(ctx){}
  void operator () (GVertex *v)
  {
    if(!v->getVisibility()) return;
    if(v->geomType() == GEntity::BoundaryLayerPoint) return;

    bool select = (CTX.render_mode == GMSH_SELECT && v->model() == GModel::current());
    if(select) {
      glPushName(0);
      glPushName(v->tag());
    }
    
    if(v->getSelection()) {
      glPointSize(CTX.geom.point_sel_size);
      gl2psPointSize(CTX.geom.point_sel_size * CTX.print.eps_point_size_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.selection);
    }
    else {
      glPointSize(CTX.geom.point_size);
      gl2psPointSize(CTX.geom.point_size * CTX.print.eps_point_size_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.point);
    }
    
    if(CTX.geom.highlight_orphans){
      std::list<GEdge*> edges = v->edges();
      if(edges.size() == 0)
        glColor4ubv((GLubyte *) & CTX.color.geom.highlight[0]);
      else if(edges.size() == 1)
        glColor4ubv((GLubyte *) & CTX.color.geom.highlight[1]);
    }

    double x = v->x(), y = v->y(), z = v->z();
    _ctx->transform(x, y, z);

    if(CTX.geom.points) {
      if(CTX.geom.point_type > 0) {
        if(v->getSelection())
          Draw_Sphere(CTX.geom.point_sel_size, x, y, z, CTX.geom.light);
        else
          Draw_Sphere(CTX.geom.point_size, x, y, z, CTX.geom.light);
      }
      else {
        glBegin(GL_POINTS);
        glVertex3d(x, y, z);
        glEnd();
      }
    }

    if(CTX.geom.points_num) {
      char Num[100];
      sprintf(Num, "%d", v->tag());
      double offset = (0.5 * CTX.geom.point_size + 0.3 * CTX.gl_fontsize) * 
        CTX.pixel_equiv_x;
      glRasterPos3d(x + offset / CTX.s[0],
                    y + offset / CTX.s[1],
                    z + offset / CTX.s[2]);
      Draw_String(Num);
    }
    
    if(select) {
      glPopName();
      glPopName();
    }
  }
};

class drawGEdge {
 private :
  visContext *_ctx;
 public :
  drawGEdge(visContext *ctx) : _ctx(ctx){}
  void operator () (GEdge *e)
  {
    if(!e->getVisibility()) return;
    if(e->geomType() == GEntity::DiscreteCurve) return;
    if(e->geomType() == GEntity::BoundaryLayerCurve) return;
    
    bool select = (CTX.render_mode == GMSH_SELECT && e->model() == GModel::current());
    if(select) {
      glPushName(1);
      glPushName(e->tag());
    }
    
    if(e->getSelection()) {
      glLineWidth(CTX.geom.line_sel_width);
      gl2psLineWidth(CTX.geom.line_sel_width * CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.selection);
    }
    else {
      glLineWidth(CTX.geom.line_width);
      gl2psLineWidth(CTX.geom.line_width * CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.line);
    }
    
    if(CTX.geom.highlight_orphans){
      std::list<GFace*> faces = e->faces();
      if(faces.size() == 0)
        glColor4ubv((GLubyte *) & CTX.color.geom.highlight[0]);
      else if(faces.size() == 1)
        glColor4ubv((GLubyte *) & CTX.color.geom.highlight[1]);
    }

    Range<double> t_bounds = e->parBounds(0);
    double t_min = t_bounds.low();
    double t_max = t_bounds.high();
    
    if(CTX.geom.lines) {
      int N = e->minimumDrawSegments() + 1;
      if(CTX.geom.line_type > 0) {
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
          Draw_Cylinder(e->getSelection() ? CTX.geom.line_sel_width : 
                        CTX.geom.line_width, x, y, z, CTX.geom.light);
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
    
    if(CTX.geom.lines_num) {
      GPoint p = e->point(t_min + 0.5 * (t_max - t_min));
      char Num[100];
      sprintf(Num, "%d", e->tag());
      double offset = (0.5 * CTX.geom.line_width + 0.3 * CTX.gl_fontsize) *
        CTX.pixel_equiv_x;
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      glRasterPos3d(x + offset / CTX.s[0],
                    y + offset / CTX.s[1],
                    z + offset / CTX.s[2]);
      Draw_String(Num);
    }
    
    if(CTX.geom.tangents) {
      double t = t_min + 0.5 * (t_max - t_min);
      GPoint p = e->point(t);
      SVector3 der = e->firstDer(t);
      der.normalize();
      for(int i = 0; i < 3; i++)
        der[i] *= CTX.geom.tangents * CTX.pixel_equiv_x / CTX.s[i];
      glColor4ubv((GLubyte *) & CTX.color.geom.tangents);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      // FIXME: transform the tangent
      Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
                  CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
                  x, y, z, der[0], der[1], der[2], CTX.geom.light);
    }

    if(CTX.draw_bbox) drawBBox(e);
    
    if(select) {
      glPopName();
      glPopName();
    }
  }
};

class drawGFace {
 private:
  visContext *_ctx;
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
    if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
    if(CTX.geom.surface_type > 1)
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
    if (f->geomType() == GEntity::CompoundSurface)return;
    Range<double> ubounds = f->parBounds(0);
    Range<double> vbounds = f->parBounds(1);
    const double uav = 0.5 * (ubounds.high() + ubounds.low());
    const double vav = 0.5 * (vbounds.high() + vbounds.low());

    if(CTX.geom.surfaces){
      if(CTX.geom.surface_type > 0 && f->va_geom_triangles){
        _drawVertexArray
          (f->va_geom_triangles, CTX.geom.light, 
           (f->geomType() == GEntity::ProjectionFace) ? true : f->getSelection(), 
           (f->geomType() == GEntity::ProjectionFace) ? CTX.color.geom.projection : 
           CTX.color.geom.selection);
      }
      else{
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x1F1F);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        int N = 20;
        const double ud = (ubounds.high() - ubounds.low());
        const double vd = (vbounds.high() - vbounds.low());
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < N; i++) {
          GPoint p = f->point(ubounds.low() + ud * (double)i / (double)(N - 1), vav);
          double x = p.x(), y = p.y(), z = p.z();
          _ctx->transform(x, y, z);
          glVertex3d(x, y, z);
        }
        glEnd();
        glBegin(GL_LINE_STRIP);
        for(int i = 0; i < N; i++) {
          GPoint p = f->point(uav, vbounds.low() + vd * (double)i / (double)(N - 1));
          double x = p.x(), y = p.y(), z = p.z();
          _ctx->transform(x, y, z);
          glVertex3d(x, y, z);
        }
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
      }
    }

    if(CTX.geom.surfaces_num) {
      GPoint p = f->point(uav, vav);
      char Num[100];
      sprintf(Num, "%d", f->tag());
      double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      glRasterPos3d(x + offset / CTX.s[0],
                    y + offset / CTX.s[1],
                    z + offset / CTX.s[2]);
      Draw_String(Num);
    }
    
    if(CTX.geom.normals) {
      GPoint p = f->point(uav, vav);
      SVector3 n = f->normal(SPoint2(uav, vav));
      for(int i = 0; i < 3; i++)
        n[i] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[i];
      glColor4ubv((GLubyte *) & CTX.color.geom.normals);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      // FIXME: transform the normal
      Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
                  CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
                  x, y, z, n[0], n[1], n[2], CTX.geom.light);
    }
  }
  void _drawPlaneGFace(GFace *f)
  {
    if(!CTX.geom.surface_type || !f->va_geom_triangles ||
       CTX.geom.surfaces_num || CTX.geom.normals){
      // We create data here and the routine is not designed to be
      // reentrant, so we must lock it to avoid race conditions when
      // redraw events are fired in rapid succession
      static bool busy = false;
      if(f->cross.empty() && !busy) {
        busy = true; 
        f->buildRepresentationCross();
        busy = false;
      }
    }

    //FIXME: cleanup buildGraphicsRep
    if(CTX.geom.surfaces) {
      if(CTX.geom.surface_type > 0 && f->va_geom_triangles){
        _drawVertexArray(f->va_geom_triangles, CTX.geom.light, 
                         f->getSelection(), CTX.color.geom.selection);
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
                          
    if(CTX.geom.surfaces_num) {
      char Num[100];
      sprintf(Num, "%d", f->tag());
      double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
      double x = 0.5 * (f->cross[0].x() + f->cross[1].x());
      double y = 0.5 * (f->cross[0].y() + f->cross[1].y());
      double z = 0.5 * (f->cross[0].z() + f->cross[1].z());
      _ctx->transform(x, y, z);
      glRasterPos3d(x + offset / CTX.s[0],
                    y + offset / CTX.s[0],
                    z + offset / CTX.s[0]);
      Draw_String(Num);
    }

    if(CTX.geom.normals) {
      SPoint3 p(0.5 * (f->cross[0].x() + f->cross[1].x()),
                0.5 * (f->cross[0].y() + f->cross[1].y()),
                0.5 * (f->cross[0].z() + f->cross[1].z()));
      SPoint2 uv = f->parFromPoint(p);
      SVector3 n = f->normal(uv);
      for(int i = 0; i < 3; i++)
        n[i] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[i];
      glColor4ubv((GLubyte *) & CTX.color.geom.normals);
      double x = p.x(), y = p.y(), z = p.z();
      _ctx->transform(x, y, z);
      // FIXME: transform the normal
      Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
                  CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
                  x, y, z, n[0], n[1], n[2], CTX.geom.light);
    }
  }
 
 public :
  drawGFace(visContext *ctx) : _ctx(ctx) {}
  void operator () (GFace *f)
  {
    if(!f->getVisibility()) return;
    if(f->geomType() == GEntity::DiscreteSurface) return;
    if(f->geomType() == GEntity::BoundaryLayerSurface) return;

    bool select = (CTX.render_mode == GMSH_SELECT && f->model() == GModel::current());
    if(select) {
      glPushName(2);
      glPushName(f->tag());
    }
    
    if(f->getSelection()) {
      glLineWidth(CTX.geom.line_sel_width / 2.);
      gl2psLineWidth(CTX.geom.line_sel_width / 2. *
                     CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.selection);
    }
    else {
      glLineWidth(CTX.geom.line_width / 2.);
      gl2psLineWidth(CTX.geom.line_width / 2. * CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.surface);
    }

    if(f->geomType() == GEntity::Plane)
      _drawPlaneGFace(f);
    else
      _drawParametricGFace(f);
    
    if(CTX.draw_bbox) drawBBox(f);
    
    if(select) {
      glPopName();
      glPopName();
    }
  }
};

class drawGRegion {
 private :
  visContext *_ctx;
 public :
  drawGRegion(visContext *ctx) : _ctx(ctx){}
  void operator () (GRegion *r)
  {
    if(!r->getVisibility()) return;
    if(r->geomType() == GEntity::DiscreteVolume) return;
    
    bool select = (CTX.render_mode == GMSH_SELECT && r->model() == GModel::current());
    if(select) {
      glPushName(3);
      glPushName(r->tag());
    }
    
    if(r->getSelection())
      glColor4ubv((GLubyte *) & CTX.color.geom.selection);
    else
      glColor4ubv((GLubyte *) & CTX.color.geom.volume);
    
    SPoint3 p = r->bounds().center();
    const double size = 8.;

    double x = p.x(), y = p.y(), z = p.z();
    _ctx->transform(x, y, z);

    if(CTX.geom.volumes)
      Draw_Sphere(size, x, y, z, CTX.geom.light);

    if(CTX.geom.volumes_num){
      char Num[100];
      sprintf(Num, "%d", r->tag());
      double offset = (0.5 * size + 0.3 * CTX.gl_fontsize) * CTX.pixel_equiv_x;
      glRasterPos3d(x + offset / CTX.s[0],
                    y + offset / CTX.s[1],
                    z + offset / CTX.s[2]);
      Draw_String(Num);
    }

    if(CTX.draw_bbox) drawBBox(r);

    if(select) {
      glPopName();
      glPopName();
    }
  }
};

void Draw_Geom()
{
  if(!CTX.geom.draw) return;

  if(CTX.geom.light_two_side)
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  else
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  
  for(int i = 0; i < 6; i++)
    if(CTX.clip[i] & 1) 
      glEnable((GLenum)(GL_CLIP_PLANE0 + i));
    else
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  visContext ctx;
  //double mat[3][3] = {{2, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  //visContextScaled ctx(mat);

  for(unsigned int i = 0; i < GModel::list.size(); i++){
    GModel *m = GModel::list[i];
    if(CTX.draw_all_models || m == GModel::current()){
      if(CTX.geom.points || CTX.geom.points_num)
        std::for_each(m->firstVertex(), m->lastVertex(), drawGVertex(&ctx));
      if(CTX.geom.lines || CTX.geom.lines_num || CTX.geom.tangents)
        std::for_each(m->firstEdge(), m->lastEdge(), drawGEdge(&ctx));
      if(CTX.geom.surfaces || CTX.geom.surfaces_num || CTX.geom.normals)
        std::for_each(m->firstFace(), m->lastFace(), drawGFace(&ctx));
      if(CTX.geom.volumes || CTX.geom.volumes_num)
        std::for_each(m->firstRegion(), m->lastRegion(), drawGRegion(&ctx));
    }
  }
  
  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}
