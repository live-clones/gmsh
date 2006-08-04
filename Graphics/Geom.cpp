// $Id: Geom.cpp,v 1.102 2006-08-04 14:28:02 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "Plugin.h"
#include "PluginManager.h"
#include "gl2ps.h"
#include "GModel.h"

extern Context_T CTX;
extern GModel *GMODEL;

// Points

void drawGeoVertex(GVertex *v)
{
  if(!(v->drawAttributes.Visible & VIS_GEOM))
    return;

  if(CTX.render_mode == GMSH_SELECT) {
    glPushName(0);
    glPushName(v->tag());
  }
  
  if(v->drawAttributes.Frozen > 0) {
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
    if(CTX.geom.point_type == 1) {
      if(v->drawAttributes.Frozen > 0)
	Draw_Sphere(CTX.geom.point_sel_size, v->x(), v->y(), v->z(), 
		    CTX.geom.light);
      else
	Draw_Sphere(CTX.geom.point_size, v->x(), v->y(), v->z(),
		    CTX.geom.light);
    }
    else if(CTX.geom.point_type == 2) {
      GMSH_Solve_Plugin *sp = GMSH_PluginManager::instance()->findSolverPlugin();
      if(sp) {
	Msg(FATAL, "GL_enhancePoint not done");
	//sp-> GL_enhancePoint (v);
      }
      glBegin(GL_POINTS);
      glVertex3d(v->x(), v->y(), v->z());
      glEnd();
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
    double offset = (0.5 * CTX.geom.point_size + 0.3 * CTX.gl_fontsize) * CTX.pixel_equiv_x;
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

// Curves

void drawGeoEdge(GEdge *c)
{
  if(c->tag() < 0 || !(c->drawAttributes.Visible & VIS_GEOM))
    return;

  if(CTX.render_mode == GMSH_SELECT) {
    glPushName(1);
    glPushName(c->tag());
  }

  if(c->drawAttributes.Frozen > 0) {
    glLineWidth(CTX.geom.line_sel_width);
    gl2psLineWidth(CTX.geom.line_sel_width * CTX.print.eps_line_width_factor);
    glColor4ubv((GLubyte *) & CTX.color.geom.line_sel);
  }
  else {
    glLineWidth(CTX.geom.line_width);
    gl2psLineWidth(CTX.geom.line_width * CTX.print.eps_line_width_factor);
    glColor4ubv((GLubyte *) & CTX.color.geom.line);
  }

  Range<double> t_bounds = c->parBounds(0);
  double t_min = t_bounds.low();
  double t_max = t_bounds.high();

  if(CTX.geom.lines) {
    if(c->geomType() == GEntity::DiscreteCurve){
      // do nothing: we draw the elements in the mesh drawing routines
    }
    else {
      int N = c->minimumDrawSegments() + 1;
      if(CTX.geom.line_type >= 1) {
	GMSH_Solve_Plugin *sp = 0;
	if(CTX.geom.line_type == 2)
	  sp = GMSH_PluginManager::instance()->findSolverPlugin();
	for(int i = 0; i < N - 1; i++) {
	  double t1 = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
	  GPoint p1 = c->point(t1);
	  double t2 = t_min + (double)(i + 1) / (double)(N - 1) * (t_max - t_min);
	  GPoint p2 = c->point(t2);
	  double x[2] = {p1.x(), p2.x()};
	  double y[2] = {p1.y(), p2.y()};
	  double z[2] = {p1.z(), p2.z()};
	  Draw_Cylinder(c->drawAttributes.Frozen > 0 ? CTX.geom.line_sel_width : 
			CTX.geom.line_width, x, y, z, CTX.geom.light);
	  if(sp) {
	    Msg(FATAL, "GL_enhanceLine not done");
	    //sp->GL_enhanceLine (c->tag(), &p1, &p2);
	  }
	}
      }
      else {
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i < N; i++) {
	  double t = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
	  GPoint p = c->point(t);
	  glVertex3d(p.x(), p.y(), p.z());
	}
	glEnd();
      }
    }
  }

  if(CTX.geom.lines_num) {
    GPoint p = c->point(0.5 * (t_max - t_min));
    char Num[100];
    sprintf(Num, "%d", c->tag());
    double offset = (0.5 * CTX.geom.line_width + 0.3 * CTX.gl_fontsize) * CTX.pixel_equiv_x;
    glRasterPos3d(p.x() + offset / CTX.s[0],
		  p.y() + offset / CTX.s[1],
		  p.z() + offset / CTX.s[2]);
    Draw_String(Num);
  }

  if(CTX.geom.tangents) {
    double t = 0.5 * (t_max - t_min);
    GPoint p = c->point(t);
    SVector3 der = c->firstDer(t) ;
    double mod = sqrt(der[0] * der[0] + der[1] * der[1] + der[2] * der[2]);
    for(int i = 0; i < 3; i++)
      der[i] = der[i] / mod * CTX.geom.tangents * CTX.pixel_equiv_x / CTX.s[i];
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

// Surfaces

void drawGeoFace(GFace *s)
{
  if(!(s->drawAttributes.Visible & VIS_GEOM))
    return;

  if(CTX.render_mode == GMSH_SELECT) {
    glPushName(2);
    glPushName(s->tag());
  }

  if(s->drawAttributes.Frozen > 0) {
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

  if(s->geomType() == GEntity::DiscreteSurface){
    // do nothing: we draw the elements in the mesh drawing routines
  }
  else if(s->geomType() == GEntity::Plane){
    Msg(GERROR, "draw plane surface not done yet");
    //Draw_Plane_Surface(s);
  }
  else{
    //Draw_NonPlane_Surface(s);
  }

  if(CTX.render_mode == GMSH_SELECT) {
    glPopName();
    glPopName();
  }
}

// Volumes

void drawGeoRegion(GRegion *v)
{
}

// Draw geometry

void Draw_Geom()
{
  if(!GMODEL) return;

  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  
  for(int i = 0; i < 6; i++)
    if(CTX.clip[i] & 1) 
      glEnable((GLenum)(GL_CLIP_PLANE0 + i));
    else
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  
  if(CTX.geom.points || CTX.geom.points_num)
    for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
      drawGeoVertex(*it);

  if(CTX.geom.lines || CTX.geom.lines_num || CTX.geom.tangents)
    for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
      drawGeoEdge(*it);

  if(CTX.geom.surfaces || CTX.geom.surfaces_num || CTX.geom.normals)
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
      drawGeoFace(*it);

  if(CTX.geom.volumes || CTX.geom.volumes_num)
    for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++)
      drawGeoRegion(*it);

  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));
}

// Highlight routines

void HighlightEntity(GEntity *e, int permanent)
{
  if(permanent)
    e->drawAttributes.Frozen = 2;
  else
    Msg(STATUS1N, "%s", e->getInfoString().c_str());
}

void HighlightEntity(GVertex *v, GEdge *c, GFace *s, int permanent)
{
  if(v) HighlightEntity(v, permanent);
  else if(c) HighlightEntity(c, permanent);
  else if(s) HighlightEntity(s, permanent);
  else if(!permanent) Msg(STATUS1N, " ");
}

void HighlightEntityNum(int v, int c, int s, int permanent)
{
  if(v) {
    GVertex *pv = GMODEL->vertexByTag(v);
    if(pv) HighlightEntity(pv, permanent);
  }
  if(c) {
    GEdge *pc = GMODEL->edgeByTag(c);
    if(pc) HighlightEntity(pc, permanent);
  }
  if(s) {
    GFace *ps = GMODEL->faceByTag(s);
    if(ps) HighlightEntity(ps, permanent);
  }
}

void ZeroHighlightEntity(GEntity *e)
{
  e->drawAttributes.Frozen = -2;
}

void ZeroHighlightEntity(GVertex *v, GEdge *c, GFace *s)
{
  if(v) ZeroHighlightEntity(v);
  if(c) ZeroHighlightEntity(c);
  if(s) ZeroHighlightEntity(s);
}

void ZeroHighlight()
{
  for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
    ZeroHighlightEntity(*it);
}

void ZeroHighlightEntityNum(int v, int c, int s)
{
  if(v) {
    GVertex *pv = GMODEL->vertexByTag(v);
    if(pv) ZeroHighlightEntity(pv);
  }
  if(c) {
    GEdge *pc = GMODEL->edgeByTag(c);
    if(pc) ZeroHighlightEntity(pc);
  }
  if(s) {
    GFace *ps = GMODEL->faceByTag(s);
    if(ps) ZeroHighlightEntity(ps);
  }
}
