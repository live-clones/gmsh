// $Id: Geom.cpp,v 1.101 2006-07-24 14:05:50 geuzaine Exp $
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
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Utils.h"
#include "Draw.h"
#include "Context.h"
#include "Interpolation.h"
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

void putZ(Vertex * v, Surface * s)
{
  Vertex V;
  V.Pos.X = s->a;
  V.Pos.Y = s->b;
  V.Pos.Z = s->c;
  Projette(&V, s->plan);
  if(V.Pos.Z != 0.0)
    v->Pos.Z = (s->d - V.Pos.X * v->Pos.X - V.Pos.Y * v->Pos.Y) / V.Pos.Z;
  else
    v->Pos.Z = 0.0;

  Projette(v, s->invplan);
}

int isPointOnPlanarSurface(Surface * S, double X, double Y, double Z,
                           double n[3])
{
  double Angle = 0.0;
  Vertex V;
  V.Pos.X = X;
  V.Pos.Y = Y;
  V.Pos.Z = Z;

  for(int i = 0; i < List_Nbr(S->Generatrices); i++) {

    Curve *C;
    List_Read(S->Generatrices, i, &C);

    int N = (C->Typ == MSH_SEGM_LINE) ? 1 : 10;

    for(int j = 0; j < N; j++) {
      double u1 = (double)j / (double)(N);
      double u2 = (double)(j + 1) / (double)(N);
      Vertex P1 = InterpolateCurve(C, u1, 0);
      Vertex P2 = InterpolateCurve(C, u2, 0);
      Angle += angle_plan(&V, &P1, &P2, n);
    }

  }

  // if Angle == 2*pi, we're inside

  if(fabs(Angle) > 2*M_PI-0.5 && fabs(Angle) < 2*M_PI+0.5) 
    return 1;
  return 0;
}

void getPlaneSurfaceNormal(Surface *s, double x, double y, double z, double n[3])
{
  double t1[3], t2[3];
  Curve *c;

  for(int i = 0; i < 3; i++)
    n[i] = 0.0;

  if(s->Typ != MSH_SURF_PLAN)
    return;

  // We cannot use s->plan or InterpolateSurface here (they both rely
  // on the mean plane, which borks the orientation). So we need to
  // use this trick:

  if(List_Nbr(s->Generatrices) > 1){
    List_Read(s->Generatrices, 0, &c);
    if(c->beg){
      t1[0] = x - c->beg->Pos.X;
      t1[1] = y - c->beg->Pos.Y;
      t1[2] = z - c->beg->Pos.Z;
      // 1) try to get a point close to 'beg' on the same curve
      // 2) if we are really unlucky and these two points are aligned 
      // with (x,y,z), which we know is inside or on the boundary of
      // the surface, then get a point from the next generatrice
      // 3) repeat
      for(int i = 0; i < List_Nbr(s->Generatrices); i++){
	List_Read(s->Generatrices, i, &c);
	Vertex v = InterpolateCurve(c, 0.1, 0);
	t2[0] = x - v.Pos.X;
	t2[1] = y - v.Pos.Y;
	t2[2] = z - v.Pos.Z;
	prodve(t1, t2, n);
	if(norme(n))
	  break;
      }
    }
  }
  if(List_Nbr(s->Generatrices) < 2 || !norme(n)){
    Msg(WARNING, "Reverting to mean plane normal for surface %d", s->Num);
    n[0] = s->a;
    n[1] = s->b;
    n[2] = s->c;
    norme(n);
  }
}

void Draw_Plane_Surface(Surface * s)
{
  Curve *c;
  Vertex V[4], vv, vv1, vv2;
  double n[3];

  if(!CTX.threads_lock && List_Nbr(s->Orientations) < 1) {
    CTX.threads_lock = 1;

    List_T *points = List_Create(10, 10, sizeof(Vertex *));
    for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
      List_Read(s->Generatrices, i, &c);
      for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
	List_Add(points, List_Pointer(c->Control_Points, j));
      }
    }

    if(!List_Nbr(points)){
      List_Delete(points);      
      CTX.threads_lock = 0;
      return;
    }
    MeanPlane(points, s);
    List_Delete(points);
    
    // compute (rough) bounding box of surface
    double minx = 0., miny = 0., maxx = 0., maxy = 0.;
    for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
      List_Read(s->Generatrices, i, &c);
      Vertex P1 = InterpolateCurve(c, 0.0, 0);
      Vertex P2 = InterpolateCurve(c, 0.5, 0);
      Vertex P3 = InterpolateCurve(c, 1.0, 0);
      Projette(&P1, s->plan);
      Projette(&P2, s->plan);
      Projette(&P3, s->plan);
      if(!i) {
	minx = maxx = P1.Pos.X;
	miny = maxy = P1.Pos.Y;
      }
      minx = DMIN(DMIN(DMIN(minx, P1.Pos.X), P2.Pos.X), P3.Pos.X);
      miny = DMIN(DMIN(DMIN(miny, P1.Pos.Y), P2.Pos.Y), P3.Pos.Y);
      maxx = DMAX(DMAX(DMAX(maxx, P1.Pos.X), P2.Pos.X), P3.Pos.X);
      maxy = DMAX(DMAX(DMAX(maxy, P1.Pos.Y), P2.Pos.Y), P3.Pos.Y);
    }

    V[0].Pos.X = minx;
    V[0].Pos.Y = miny;
    V[1].Pos.X = maxx;
    V[1].Pos.Y = miny;
    V[2].Pos.X = maxx;
    V[2].Pos.Y = maxy;
    V[3].Pos.X = minx;
    V[3].Pos.Y = maxy;

    for(int i = 0; i < 4; i++) {
      V[i].Pos.Z = 0.0;
      putZ(&V[i], s);
    }

    n[0] = s->plan[2][0];
    n[1] = s->plan[2][1];
    n[2] = s->plan[2][2];
    norme(n);

    // compute which parts of the "middle cross" lie inside the surface
    const int numPoints = 200;
    for(int cross = 0; cross < 2; cross++) {
      int k = 0;
      for(int i = 0; i < numPoints; i++) {
	double t = (double)i / (double)(numPoints-1);
	if(!cross){
	  vv.Pos.X = t * 0.5 * (V[0].Pos.X + V[1].Pos.X) + 
	    (1. - t) * 0.5 * (V[2].Pos.X + V[3].Pos.X);
	  vv.Pos.Y = t * 0.5 * (V[0].Pos.Y + V[1].Pos.Y) + 
	    (1. - t) * 0.5 * (V[2].Pos.Y + V[3].Pos.Y);
	  vv.Pos.Z = t * 0.5 * (V[0].Pos.Z + V[1].Pos.Z) + 
	    (1. - t) * 0.5 * (V[2].Pos.Z + V[3].Pos.Z);
	}
	else{
	  vv.Pos.X = t * .5 * (V[0].Pos.X + V[3].Pos.X) + 
	    (1. - t) * .5 * (V[2].Pos.X + V[1].Pos.X);
	  vv.Pos.Y = t * .5 * (V[0].Pos.Y + V[3].Pos.Y) + 
	    (1. - t) * .5 * (V[2].Pos.Y + V[1].Pos.Y);
	  vv.Pos.Z = t * .5 * (V[0].Pos.Z + V[3].Pos.Z) + 
	    (1. - t) * .5 * (V[2].Pos.Z + V[1].Pos.Z);
	}
	if(isPointOnPlanarSurface(s, vv.Pos.X, vv.Pos.Y, vv.Pos.Z, n)) {
	  if(!k) {
	    List_Add(s->Orientations, &vv);
	    k = 1;
	  }
	}
	else {
	  if(k) {
	    List_Add(s->Orientations, &vv);
	    k = 0;
	  }
	}
      }
      if(k)
	List_Add(s->Orientations, &vv);
    }

    Msg(STATUS2, "Plane Surface %d (%d cross points)", 
	s->Num, List_Nbr(s->Orientations));
    
    if(!List_Nbr(s->Orientations)){ // add dummy
      List_Add(s->Orientations, &vv);
      //printf("surf %d: min=%g %g max=%g %g\n", s->Num, minx, miny, maxx, maxy);
    }

    CTX.threads_lock = 0;
  }
  
  if(List_Nbr(s->Orientations) > 1) {

    if(CTX.geom.surfaces) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x1F1F);
      gl2psEnable(GL2PS_LINE_STIPPLE);
      glBegin(GL_LINES);
      for(int i = 0; i < List_Nbr(s->Orientations); i++) {
	List_Read(s->Orientations, i, &vv);
	glVertex3d(vv.Pos.X, vv.Pos.Y, vv.Pos.Z);
      }
      glEnd();
      glDisable(GL_LINE_STIPPLE);
      gl2psDisable(GL2PS_LINE_STIPPLE);
    }

    if(CTX.geom.surfaces_num) {
      List_Read(s->Orientations, 0, &vv1);
      List_Read(s->Orientations, 1, &vv2);
      char Num[100];
      sprintf(Num, "%d", s->Num);
      double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
      glRasterPos3d((vv2.Pos.X + vv1.Pos.X) / 2. + offset / CTX.s[0],
		    (vv2.Pos.Y + vv1.Pos.Y) / 2. + offset / CTX.s[1],
		    (vv2.Pos.Z + vv1.Pos.Z) / 2. + offset / CTX.s[2]);
      Draw_String(Num);
    }

    if(CTX.geom.normals) {
      List_Read(s->Orientations, 0, &vv1);
      List_Read(s->Orientations, 1, &vv2);
      double x = (vv1.Pos.X + vv2.Pos.X) / 2.;
      double y = (vv1.Pos.Y + vv2.Pos.Y) / 2.;
      double z = (vv1.Pos.Z + vv2.Pos.Z) / 2.;
      getPlaneSurfaceNormal(s, x, y, z, n);
      n[0] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[0];
      n[1] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[1];
      n[2] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[2];
      glColor4ubv((GLubyte *) & CTX.color.geom.normals);
      Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		  CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
		  x, y, z, n[0], n[1], n[2], CTX.geom.light);
    }

  }
}

void Draw_NonPlane_Surface(Surface * s)
{
  if(CTX.geom.surfaces) {
    if(s->Typ == MSH_SURF_NURBS) {
      if(CTX.geom.light) glEnable(GL_LIGHTING);
      if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
      GLUnurbsObj *nurb;
      nurb = gluNewNurbsRenderer();
#if defined(GLU_VERSION_1_3)
      gluNurbsProperty(nurb, (GLenum) GLU_SAMPLING_TOLERANCE, 50.0);
      gluNurbsProperty(nurb, (GLenum) GLU_DISPLAY_MODE, GLU_FILL);
#endif
      gluBeginSurface(nurb);
      gluNurbsSurface(nurb, s->Nu + s->OrderU + 1, s->ku,
		      s->Nv + s->OrderV + 1, s->kv, 4, 4 * s->Nu, s->cp,
		      s->OrderU + 1, s->OrderV + 1, GL_MAP2_VERTEX_4);
      gluEndSurface(nurb);
      gluDeleteNurbsRenderer(nurb);
      glDisable(GL_POLYGON_OFFSET_FILL);
      glDisable(GL_LIGHTING);
    }
    else{
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x1F1F);
      gl2psEnable(GL2PS_LINE_STIPPLE);
      int N = 50;
      glBegin(GL_LINE_STRIP);
      for(int i = 0; i < N + 1; i++) {
	double u = (double)i / (double)N;
	Vertex v = InterpolateSurface(s, u, 0.5, 0, 0);
	glVertex3d(v.Pos.X, v.Pos.Y, v.Pos.Z);
      }
      glEnd();
      glBegin(GL_LINE_STRIP);
      for(int i = 0; i < N + 1; i++) {
	double u = (double)i / (double)N;
	Vertex v = InterpolateSurface(s, 0.5, u, 0, 0);
	glVertex3d(v.Pos.X, v.Pos.Y, v.Pos.Z);
      }
      glEnd();
      glDisable(GL_LINE_STIPPLE);
      gl2psDisable(GL2PS_LINE_STIPPLE);
    }
  }

  if(CTX.geom.surfaces_num) {
    Vertex v = InterpolateSurface(s, 0.5, 0.5, 0, 0);
    char Num[100];
    sprintf(Num, "%d", s->Num);
    double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
    glRasterPos3d(v.Pos.X + offset / CTX.s[0],
		  v.Pos.Y + offset / CTX.s[1],
		  v.Pos.Z + offset / CTX.s[2]);
    Draw_String(Num);
  }

  if(CTX.geom.normals) {
    const double eps = 1.e-3;
    Vertex v1 = InterpolateSurface(s, 0.5, 0.5, 0, 0);
    Vertex v2 = InterpolateSurface(s, 0.5 + eps, 0.5, 0, 0);
    Vertex v3 = InterpolateSurface(s, 0.5, 0.5 + eps, 0, 0);
    double n[3];
    normal3points(v1.Pos.X, v1.Pos.Y, v1.Pos.Z, 
		  v2.Pos.X, v2.Pos.Y, v2.Pos.Z, 
		  v3.Pos.X, v3.Pos.Y, v3.Pos.Z, n);
    n[0] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[0];
    n[1] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[1];
    n[2] *= CTX.geom.normals * CTX.pixel_equiv_x / CTX.s[2];
    glColor4ubv((GLubyte *) & CTX.color.geom.normals);
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		v1.Pos.X, v1.Pos.Y, v1.Pos.Z, n[0], n[1], n[2],
		CTX.geom.light);
  }
}

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
}

// Highlight routines (Note: in Gmsh < 1.61, we used to draw permanent
// highlights (the "red" selected lines, etc.) using incremental
// drawing, i.e., by drawing "over" the current picture in-between
// Draw() calls. This was fine for simple overlays on points and lines
// (that we could draw with a slightly larger width so that they would
// cover the old ones), but it does not work well when drawing
// surfaces, post-pro views, etc. And since real cross-platform
// overlays are unmanageable, the best solution is actually to redraw
// the whole scene. This is the approach we follow now.

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
