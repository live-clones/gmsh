// $Id: Geom.cpp,v 1.126 2006-12-08 16:54:02 jacob Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "GmshUI.h"
#include "Draw.h"
#include "Context.h"
#include "gl2ps.h"
#include "GModel.h"
#include "SBoundingBox3d.h"

extern Context_T CTX;
extern GModel *GMODEL;

class drawGVertex {
 public :
  void operator () (GVertex *v)
  {
    if(!v->getVisibility()) return;

    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(0);
      glPushName(v->tag());
    }
    
    if(v->getSelection()) {
      glPointSize(CTX.geom.point_sel_size);
      gl2psPointSize(CTX.geom.point_sel_size * CTX.print.eps_point_size_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.point_sel);
    }
    else {
      glPointSize(CTX.geom.point_size);
      gl2psPointSize(CTX.geom.point_size * CTX.print.eps_point_size_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.point);
    }
    
    if(CTX.geom.points) {
      if(CTX.geom.point_type > 0) {
	if(v->getSelection())
	  Draw_Sphere(CTX.geom.point_sel_size, v->x(), v->y(), v->z(), 
		      CTX.geom.light);
	else
	  Draw_Sphere(CTX.geom.point_size, v->x(), v->y(), v->z(),
		      CTX.geom.light);
      }
      else {
	glBegin(GL_POINTS);
	glVertex3d(v->x(), v->y(), v->z());
	glEnd();
      }
    }

    if(CTX.geom.points_num) {
      char Num[100];
      sprintf(Num, "%d", v->tag());
      double offset = (0.5 * CTX.geom.point_size + 0.3 * CTX.gl_fontsize) * 
	CTX.pixel_equiv_x;
      glRasterPos3d(v->x() + offset / CTX.s[0],
		    v->y() + offset / CTX.s[1],
		    v->z() + offset / CTX.s[2]);
      Draw_String(Num);
    }
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};

class drawGEdge {
 public :
  void operator () (GEdge *e)
  {
    if(!e->getVisibility() || e->geomType() == GEntity::DiscreteCurve)
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(1);
      glPushName(e->tag());
    }
    
    if(e->getSelection()) {
      glLineWidth(CTX.geom.line_sel_width);
      gl2psLineWidth(CTX.geom.line_sel_width * CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.line_sel);
    }
    else {
      glLineWidth(CTX.geom.line_width);
      gl2psLineWidth(CTX.geom.line_width * CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.line);
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
	  Draw_Cylinder(e->getSelection() ? CTX.geom.line_sel_width : 
			CTX.geom.line_width, x, y, z, CTX.geom.light);
	}
      }
      else {
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i < N; i++) {
	  double t = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
	  GPoint p = e->point(t);
	  glVertex3d(p.x(), p.y(), p.z());
	}
	glEnd();
      }
    }
    
    if(CTX.geom.lines_num) {
      GPoint p = e->point(0.5 * (t_max - t_min));
      char Num[100];
      sprintf(Num, "%d", e->tag());
      double offset = (0.5 * CTX.geom.line_width + 0.3 * CTX.gl_fontsize) *
	CTX.pixel_equiv_x;
      glRasterPos3d(p.x() + offset / CTX.s[0],
		    p.y() + offset / CTX.s[1],
		    p.z() + offset / CTX.s[2]);
      Draw_String(Num);
    }
    
    if(CTX.geom.tangents) {
      double t = 0.5 * (t_max - t_min);
      GPoint p = e->point(t);
      SVector3 der = e->firstDer(t);
      der.normalize();
      for(int i = 0; i < 3; i++)
	der[i] *= CTX.geom.tangents * CTX.pixel_equiv_x / CTX.s[i];
      glColor4ubv((GLubyte *) & CTX.color.geom.tangents);
      Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		  CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		  p.x(), p.y(), p.z(), der[0], der[1], der[2], CTX.geom.light);
    }
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};

class drawGFace {
 private:
  void _drawNonPlaneGFace(GFace *f)
  {
    if(CTX.geom.surfaces) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x1F1F);
      gl2psEnable(GL2PS_LINE_STIPPLE);
      int N = 20;
      glBegin(GL_LINE_STRIP);

      Range<double> ubounds = f->parBounds ( 0 );
      Range<double> vbounds = f->parBounds ( 1 );

      const double uav = 0.5 * ( ubounds.high() + ubounds.low());
      const double vav = 0.5 * ( vbounds.high() + vbounds.low());
      const double ud =  ( ubounds.high() - ubounds.low());
      const double vd =  ( vbounds.high() - vbounds.low());

      for(int i = 0; i < N; i++) {
	GPoint p = f->point(ubounds.low() + ud * (double)i / (double)(N - 1), vav);
	glVertex3d(p.x(), p.y(), p.z());
      }
      glEnd();
      glBegin(GL_LINE_STRIP);
      for(int i = 0; i < N; i++) {
	GPoint p = f->point(uav, vbounds.low() + vd * (double)i / (double)(N - 1));
	glVertex3d(p.x(), p.y(), p.z());
      }
      glEnd();
      glDisable(GL_LINE_STIPPLE);
      gl2psDisable(GL2PS_LINE_STIPPLE);
    }
    
    if(CTX.geom.surfaces_num) {
      GPoint p = f->point(0.5, 0.5);
      char Num[100];
      sprintf(Num, "%d", f->tag());
      double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
      glRasterPos3d(p.x() + offset / CTX.s[0],
		    p.y() + offset / CTX.s[1],
		    p.z() + offset / CTX.s[2]);
      Draw_String(Num);
    }
    
    if(CTX.geom.normals) {
      GPoint p = f->point(0.5, 0.5);
      SVector3 n = f->normal(SPoint2(0.5, 0.5));
      for(int i = 0; i < 3; i++)
	n[i] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[i];
      glColor4ubv((GLubyte *) & CTX.color.geom.normals);
      Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		  CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		  p.x(), p.y(), p.z(), n[0], n[1], n[2], CTX.geom.light);
    }
  }
  
  void _drawProjectionGFace(GFace *f)
  {
    Range<double> ubounds = f->parBounds(0);
    Range<double> vbounds = f->parBounds(1);
    const int N = 15;
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(1.0f,0.5f,0.0f);
    glBegin(GL_QUADS);
    for(int i = 1; i < N; i++)
    {
      for(int j = 1; j < N; j++)
      {
    	double u1 = ubounds.low() + (double)i/(double)(N-1) * 
	      (ubounds.high() - ubounds.low());
	    double v1 = vbounds.low() + (double)j/(double)(N-1) * 
	      (vbounds.high() - vbounds.low());
    	double u2 = ubounds.low() + (double)(i-1)/(double)(N-1) * 
	      (ubounds.high() - ubounds.low());
	    double v2 = vbounds.low() + (double)j/(double)(N-1) * 
	      (vbounds.high() - vbounds.low());
      double u3 = ubounds.low() + (double)(i-1)/(double)(N-1) * 
	      (ubounds.high() - ubounds.low());
	    double v3 = vbounds.low() + (double)(j-1)/(double)(N-1) * 
	      (vbounds.high() - vbounds.low());
     	double u4 = ubounds.low() + (double)i/(double)(N-1) * 
	      (ubounds.high() - ubounds.low());
	    double v4 = vbounds.low() + (double)(j-1)/(double)(N-1) * 
	      (vbounds.high() - vbounds.low());
	    GPoint p1 = f->point(u1, v1);
      GPoint p2 = f->point(u2,v2);
      GPoint p3 = f->point(u3,v3);
      GPoint p4 = f->point(u4,v4);
  //	printf("%g %g %g\n", p.x(), p.y(), p.z());	
      glVertex3d(p1.x(), p1.y(), p1.z());
      glVertex3d(p2.x(), p2.y(), p2.z());
      glVertex3d(p3.x(), p3.y(), p3.z());
      glVertex3d(p4.x(), p4.y(), p4.z());
            

      }
    }
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  }

  void _drawPlaneGFace(GFace *f)
  {
    // We create data here and the routine is not designed to be
    // reentrant, so we must lock it to avoid race conditions when
    // redraw events are fired in rapid succession
    if(!f->cross.size() && !CTX.threads_lock) {
      CTX.threads_lock = 1; 
      std::list<GEdge*> edges = f->edges();
      SBoundingBox3d bb;
      for(std::list<GEdge*>::iterator it = edges.begin(); it != edges.end(); it++){
	Range<double> t_bounds = (*it)->parBounds(0);
	GPoint p[3] = {(*it)->point(t_bounds.low()),
		       (*it)->point(0.5 * (t_bounds.low() + t_bounds.high())),
		       (*it)->point(t_bounds.high())};
	for(int i = 0; i < 3; i++){
	  SPoint2 uv = f->parFromPoint(SPoint3(p[i].x(), p[i].y(), p[i].z()));
	  bb += SPoint3(uv.x(), uv.y(), 0.);
	}
      }
      bb *= 1.1;
      GPoint v0 = f->point(bb.min().x(), bb.min().y());
      GPoint v1 = f->point(bb.max().x(), bb.min().y());
      GPoint v2 = f->point(bb.max().x(), bb.max().y());
      GPoint v3 = f->point(bb.min().x(), bb.max().y());
      const int N = 100;
      for(int dir = 0; dir < 2; dir++) {
	int end_line = 0;
	SPoint3 pt, pt_last_inside;
	for(int i = 0; i < N; i++) {
	  double t = (double)i / (double)(N - 1);
	  double x, y, z;
	  if(!dir){
	    x = 0.5 * (t * (v0.x() + v1.x()) + (1. - t) * (v2.x() + v3.x()));
	    y = 0.5 * (t * (v0.y() + v1.y()) + (1. - t) * (v2.y() + v3.y()));
	    z = 0.5 * (t * (v0.z() + v1.z()) + (1. - t) * (v2.z() + v3.z()));
	  }
	  else{
	    x = 0.5 * (t * (v0.x() + v3.x()) + (1. - t) * (v2.x() + v1.x()));
	    y = 0.5 * (t * (v0.y() + v3.y()) + (1. - t) * (v2.y() + v1.y()));
	    z = 0.5 * (t * (v0.z() + v3.z()) + (1. - t) * (v2.z() + v1.z()));
	  }
	  pt.setPosition(x, y, z);
	  if(f->containsPoint(pt)){
	    pt_last_inside.setPosition(x, y, z);
	    if(!end_line) { f->cross.push_back(pt); end_line = 1; }
	  }
	  else {
	    if(end_line) { f->cross.push_back(pt_last_inside); end_line = 0; }
	  }
	}
	if(end_line) f->cross.push_back(pt_last_inside);
      }
      // if we couldn't determine a cross, add a dummy point so that
      // we won't try again
      if(!f->cross.size()) f->cross.push_back(SPoint3(0., 0., 0.));
      CTX.threads_lock = 0;
    }

    if(f->cross.size() < 2) return;

    if(CTX.geom.surfaces) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x1F1F);
      gl2psEnable(GL2PS_LINE_STIPPLE);
      glBegin(GL_LINES);
      for(unsigned int i = 0; i < f->cross.size(); i++)
	glVertex3d(f->cross[i].x(), f->cross[i].y(), f->cross[i].z());
      glEnd();
      glDisable(GL_LINE_STIPPLE);
      gl2psDisable(GL2PS_LINE_STIPPLE);
    }

    if(CTX.geom.surfaces_num) {
      char Num[100];
      sprintf(Num, "%d", f->tag());
      double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
      glRasterPos3d(0.5 * (f->cross[0].x() + f->cross[1].x()) + offset / CTX.s[0],
		    0.5 * (f->cross[0].y() + f->cross[1].y()) + offset / CTX.s[0],
		    0.5 * (f->cross[0].z() + f->cross[1].z()) + offset / CTX.s[0]);
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
      Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		  CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
		  p.x(), p.y(), p.z(), n[0], n[1], n[2], CTX.geom.light);
    }
  }
  
public :
  void operator () (GFace *f)
  {
    if(!f->getVisibility() || f->geomType() == GEntity::DiscreteSurface)
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(2);
      glPushName(f->tag());
    }
    
    if(f->getSelection()) {
      glLineWidth(CTX.geom.line_sel_width / 2.);
      gl2psLineWidth(CTX.geom.line_sel_width / 2. *
		     CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.surface_sel);
    }
    else {
      glLineWidth(CTX.geom.line_width / 2.);
      gl2psLineWidth(CTX.geom.line_width / 2. * CTX.print.eps_line_width_factor);
      glColor4ubv((GLubyte *) & CTX.color.geom.surface);
    }
    
    if(f->geomType() == GEntity::Plane)
      _drawPlaneGFace(f);
    else if(f->geomType() == GEntity::ProjectionSurface)
      _drawProjectionGFace(f);
    else
      _drawNonPlaneGFace(f);
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};


class drawGRegion {
 public :
  void operator () (GRegion *r)
  {
    if(!r->getVisibility() || r->geomType() == GEntity::DiscreteVolume)
      return;
    
    if(CTX.render_mode == GMSH_SELECT) {
      glPushName(3);
      glPushName(r->tag());
    }
    
    if(r->getSelection())
      glColor4ubv((GLubyte *) & CTX.color.geom.volume_sel);
    else
      glColor4ubv((GLubyte *) & CTX.color.geom.volume);
    
    SBoundingBox3d bb = r->bounds();
    SPoint3 p = bb.center();
    const double size = 8.;

    if(CTX.geom.volumes)
      Draw_Sphere(size, p.x(), p.y(), p.z(), CTX.geom.light);

    if(CTX.geom.volumes_num){
      char Num[100];
      sprintf(Num, "%d", r->tag());
      double offset = (0.5 * size + 0.3 * CTX.gl_fontsize) * CTX.pixel_equiv_x;
      glRasterPos3d(p.x() + offset / CTX.s[0],
		    p.y() + offset / CTX.s[1],
		    p.z() + offset / CTX.s[2]);
      Draw_String(Num);
    }

    if(CTX.render_mode == GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
};

void Draw_Geom()
{
  if(!CTX.geom.draw) return;

  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  
  for(int i = 0; i < 6; i++)
    if(CTX.clip[i] & 1) 
      glEnable((GLenum)(GL_CLIP_PLANE0 + i));
    else
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  
  if(CTX.geom.points || CTX.geom.points_num)
    std::for_each(GMODEL->firstVertex(), GMODEL->lastVertex(), drawGVertex());

  if(CTX.geom.lines || CTX.geom.lines_num || CTX.geom.tangents)
    std::for_each(GMODEL->firstEdge(), GMODEL->lastEdge(), drawGEdge());

  if(CTX.geom.surfaces || CTX.geom.surfaces_num || CTX.geom.normals)
    std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), drawGFace());

  if(CTX.geom.volumes || CTX.geom.volumes_num)
    std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), drawGRegion());

  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  bool geometryExists = 
    GMODEL->numVertex() || GMODEL->numEdge() || GMODEL->numFace() || GMODEL->numRegion();

  if(geometryExists && (CTX.draw_bbox || !CTX.mesh.draw)) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
    Draw_Box(CTX.min[0], CTX.min[1], CTX.min[2], 
	     CTX.max[0], CTX.max[1], CTX.max[2]);
    glColor3d(1.,0.,0.);
    for(int i = 0; i < 6; i++)
      if(CTX.clip[i] & 1 || CTX.clip[i] & 2)
	Draw_PlaneInBoundingBox(CTX.min[0], CTX.min[1], CTX.min[2],
				CTX.max[0], CTX.max[1], CTX.max[2],
				CTX.clip_plane[i][0], CTX.clip_plane[i][1], 
				CTX.clip_plane[i][2], CTX.clip_plane[i][3]);
    if(CTX.mesh.use_cut_plane)
      Draw_PlaneInBoundingBox(CTX.min[0], CTX.min[1], CTX.min[2],
			      CTX.max[0], CTX.max[1], CTX.max[2],
			      CTX.mesh.cut_planea, CTX.mesh.cut_planeb, 
			      CTX.mesh.cut_planec, CTX.mesh.cut_planed);
  }
  
  if(CTX.axes){
    glColor4ubv((GLubyte *) & CTX.color.axes);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
    if(!CTX.axes_auto_position){
      Draw_Axes(CTX.axes, CTX.axes_tics, CTX.axes_format, CTX.axes_label, 
		CTX.axes_position);
    }
    else if(geometryExists){
      double bb[6] = {CTX.min[0], CTX.max[0], CTX.min[1], 
		      CTX.max[1], CTX.min[2], CTX.max[2]};
      Draw_Axes(CTX.axes, CTX.axes_tics, CTX.axes_format, CTX.axes_label, bb);
    }
  }

  if(CTX.draw_rotation_center){
    glColor4ubv((GLubyte *) & CTX.color.fg);
    if(CTX.rotation_center_cg)
      Draw_Sphere(CTX.point_size, CTX.cg[0], CTX.cg[1], CTX.cg[2], CTX.geom.light);
    else
      Draw_Sphere(CTX.point_size, CTX.rotation_center[0], CTX.rotation_center[1], 
		  CTX.rotation_center[2], CTX.geom.light);
  }

}
