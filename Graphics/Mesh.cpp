// $Id: Mesh.cpp,v 1.120 2005-01-09 02:18:59 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "MinMax.h"
#include "gl2ps.h"
#include "Numeric.h"

extern Mesh *THEM;
extern Context_T CTX;

extern int edges_tetra[6][2];
extern int edges_hexa[12][2];
extern int edges_prism[9][2];
extern int edges_pyramid[8][2];

extern int trifaces_tetra[4][3];
extern int trifaces_prism[2][3];
extern int trifaces_pyramid[4][3];
extern int quadfaces_hexa[6][4];
extern int quadfaces_prism[3][4];
extern int quadfaces_pyramid[1][4];

static DrawingColor theColor;
static int thePhysical = 0;
static Surface *theSurface = NULL;
static Volume *theVolume = NULL;

void draw_polygon_2d(double r, double g, double b, int n,
                     double *x, double *y, double *z)
{
  int i;

  CalculateMinMax(THEM->Points, NULL);
  InitOpengl();
  InitPosition();

  glDisable(GL_DEPTH_TEST);
  glDrawBuffer(GL_FRONT);
  glColor3f(r, g, b);
  glBegin(GL_LINE_STRIP);
  for(i = 0; i < n; i++)
    if(z)
      glVertex3d(x[i], y[i], z[i]);
    else
      glVertex2d(x[i], y[i]);
  glEnd();
  glFlush();
  glDrawBuffer(GL_BACK);
  glEnable(GL_DEPTH_TEST);
}

int getFirstPhysical(int type, int num)
{
  for(int i = 0; i < List_Nbr(THEM->PhysicalGroups); i++){
    PhysicalGroup *p = *(PhysicalGroup**)List_Pointer(THEM->PhysicalGroups, i);
    if(p->Typ == type && List_Query(p->Entities, &num, fcmp_int))
      return p->Num;
  }  
  return 0;
}

double intersectCutPlane(int num, Vertex **v, int *edges, int *faces)
{
  if(!CTX.mesh.use_cut_plane)
    return 0;

  double val = CTX.mesh.evalCutPlane(v[0]->Pos.X, v[0]->Pos.Y, v[0]->Pos.Z);
  for(int i = 1; i < num; i++){
    if(val * CTX.mesh.evalCutPlane(v[i]->Pos.X, v[i]->Pos.Y, v[i]->Pos.Z) <= 0){
      // the element intersects the cut plane
      if(CTX.mesh.cut_plane_as_surface){
	if(!*edges)
	  *edges = CTX.mesh.surfaces_edges;
	if(!*faces)
	  *faces = CTX.mesh.surfaces_faces;
      }
      return 1.;
    }
  }
  return val;
}

double intersectCutPlane(int num, Vertex **v)
{
  int dummy;
  return intersectCutPlane(num, v, &dummy, &dummy);
}

void Draw_Mesh(Mesh * M)
{
  InitPosition();

  for(int i = 0; i < 6; i++)
    glClipPlane((GLenum)(GL_CLIP_PLANE0 + i), CTX.clip_plane[i]);

  // draw the geometry

  if(M->status >= 0){
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    for(int i = 0; i < 6; i++)
      if(CTX.clip[i] & 1) 
	glEnable((GLenum)(GL_CLIP_PLANE0 + i));
      else
	glDisable((GLenum)(GL_CLIP_PLANE0 + i));

    Draw_Geom(M);

    for(int i = 0; i < 6; i++)
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  }

  // if we're in selection mode, we're done

  if(CTX.render_mode == GMSH_SELECT)
    return;

  // draw the bounding box of the mesh if we are in fast redraw mode
  // and there is no geometry
 
  if((CTX.draw_bbox && (Tree_Nbr(M->Vertices) || Tree_Nbr(M->Points))) ||
     (!CTX.mesh.draw && Tree_Nbr(M->Vertices) && !Tree_Nbr(M->Points))) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);

    glBegin(GL_LINE_LOOP);
    glVertex3d(CTX.min[0], CTX.min[1], CTX.min[2]);
    glVertex3d(CTX.max[0], CTX.min[1], CTX.min[2]);
    glVertex3d(CTX.max[0], CTX.max[1], CTX.min[2]);
    glVertex3d(CTX.min[0], CTX.max[1], CTX.min[2]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(CTX.min[0], CTX.min[1], CTX.max[2]);
    glVertex3d(CTX.max[0], CTX.min[1], CTX.max[2]);
    glVertex3d(CTX.max[0], CTX.max[1], CTX.max[2]);
    glVertex3d(CTX.min[0], CTX.max[1], CTX.max[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(CTX.min[0], CTX.min[1], CTX.min[2]);
    glVertex3d(CTX.min[0], CTX.min[1], CTX.max[2]);
    glVertex3d(CTX.max[0], CTX.min[1], CTX.min[2]);
    glVertex3d(CTX.max[0], CTX.min[1], CTX.max[2]);
    glVertex3d(CTX.max[0], CTX.max[1], CTX.min[2]);
    glVertex3d(CTX.max[0], CTX.max[1], CTX.max[2]);
    glVertex3d(CTX.min[0], CTX.max[1], CTX.min[2]);
    glVertex3d(CTX.min[0], CTX.max[1], CTX.max[2]);
    glEnd();
    char label[256];
    double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
    glRasterPos3d(CTX.min[0] + offset / CTX.s[0], 
		  CTX.min[1] + offset / CTX.s[0], 
		  CTX.min[2] + offset / CTX.s[0]);
    sprintf(label, "(%g,%g,%g)", CTX.min[0], CTX.min[1], CTX.min[2]);
    Draw_String(label);
    glRasterPos3d(CTX.max[0] + offset / CTX.s[0], 
		  CTX.max[1] + offset / CTX.s[0], 
		  CTX.max[2] + offset / CTX.s[0]);
    sprintf(label, "(%g,%g,%g)", CTX.max[0], CTX.max[1], CTX.max[2]);
    Draw_String(label);

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
  
  // draw the mesh

  if(CTX.mesh.draw) {  
    glPointSize(CTX.mesh.point_size);
    gl2psPointSize(CTX.mesh.point_size * CTX.print.eps_point_size_factor);
    glLineWidth(CTX.mesh.line_width);
    gl2psLineWidth(CTX.mesh.line_width * CTX.print.eps_line_width_factor);

    if(CTX.mesh.light_two_side)
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    else
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

    for(int i = 0; i < 6; i++)
      if(CTX.clip[i] & 2) 
	glEnable((GLenum)(GL_CLIP_PLANE0 + i));
      else
	glDisable((GLenum)(GL_CLIP_PLANE0 + i));
    
    if(M->status >= 3 && (CTX.mesh.volumes_faces || CTX.mesh.volumes_edges ||
			  CTX.mesh.volumes_num || CTX.mesh.points_per_element ||
			  (CTX.mesh.use_cut_plane && CTX.mesh.cut_plane_as_surface &&
			   (CTX.mesh.surfaces_edges || CTX.mesh.surfaces_faces)))) {
      Tree_Action(M->Volumes, Draw_Mesh_Volume);
    }
   
    if(M->status >= 2 && (CTX.mesh.surfaces_faces || CTX.mesh.surfaces_edges ||
			  CTX.mesh.surfaces_num || CTX.mesh.points_per_element ||
			  CTX.mesh.normals)) {
      Tree_Action(M->Surfaces, Draw_Mesh_Surface);
      if(CTX.mesh.oldxtrude)  //old extrusion algo
	Tree_Action(M->Volumes, Draw_Mesh_Extruded_Surfaces);
    }
    
    if(M->status >= 1 && (CTX.mesh.lines || CTX.mesh.lines_num || 
			  CTX.mesh.points_per_element || CTX.mesh.tangents)) {
      Tree_Action(M->Curves, Draw_Mesh_Curve);
    }
    
    if(M->status >= 0 && !CTX.mesh.points_per_element &&
       (CTX.mesh.points || CTX.mesh.points_num)) {
      Tree_Action(M->Vertices, Draw_Mesh_Point);
    }
    CTX.mesh.changed = 0;

    for(int i = 0; i < 6; i++)
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));
  }

  // draw the big moving axes

  if(CTX.axes)
    Draw_Axes(CTX.lc_middle / 4.);

  // draw any plugin-specific stuff
  
  if(CTX.post.plugin_draw_function)
    (*CTX.post.plugin_draw_function)();

  // draw the post-processing views

  Draw_Post();
}

void Draw_Mesh_Volume(void *a, void *b)
{
  Volume *v = *(Volume **) a;
  if(!(v->Visible & VIS_MESH))
    return;

  theVolume = v;
  theColor = v->Color;
  thePhysical = getFirstPhysical(MSH_PHYSICAL_VOLUME, v->Num);

  // we don't use vertex arrays for every volume primitive: only for
  // volume cuts drawn "as surfaces" (using vertex arrays for
  // everything would require quite a bit of memory...)
  if(CTX.mesh.use_cut_plane && CTX.mesh.cut_plane_as_surface && 
     CTX.mesh.vertex_arrays){
    if(CTX.mesh.changed){
      Msg(DEBUG, "regenerate volume mesh vertex arrays");
      // triangles
      if(v->TriVertexArray) delete v->TriVertexArray;
      v->TriVertexArray = new VertexArray(3, 1000);
      v->TriVertexArray->fill = 1;
      // quadrangles
      if(v->QuadVertexArray) delete v->QuadVertexArray;
      v->QuadVertexArray = new VertexArray(4, 1000);
      v->QuadVertexArray->fill = 1;
      Tree_Action(v->Simplexes, Draw_Mesh_Tetrahedron);
      Tree_Action(v->SimplexesBase, Draw_Mesh_Tetrahedron);
      Tree_Action(v->Hexahedra, Draw_Mesh_Hexahedron);
      Tree_Action(v->Prisms, Draw_Mesh_Prism);
      Tree_Action(v->Pyramids, Draw_Mesh_Pyramid);
      if(v->TriVertexArray){
	Msg(DEBUG, "%d triangles in volume vertex array", v->TriVertexArray->num);
	v->TriVertexArray->fill = 0;
      }
      if(v->QuadVertexArray){
	Msg(DEBUG, "%d quads in volume vertex array", v->QuadVertexArray->num);
	v->QuadVertexArray->fill = 0;
      }
    }
    if(v->TriVertexArray)
      Draw_Mesh_Array(v->TriVertexArray,
		      CTX.mesh.surfaces_faces, CTX.mesh.surfaces_edges);
    if(v->QuadVertexArray)
      Draw_Mesh_Array(v->QuadVertexArray,
		      CTX.mesh.surfaces_faces, CTX.mesh.surfaces_edges);
  }

  if(!CTX.mesh.use_cut_plane || !CTX.mesh.cut_plane_as_surface ||
     !v->TriVertexArray || !v->QuadVertexArray ||
     CTX.mesh.volumes_faces || CTX.mesh.volumes_edges ||
     CTX.mesh.dual || CTX.mesh.volumes_num || CTX.mesh.points_per_element ||
     CTX.mesh.normals){
    Msg(DEBUG, "classic volume data path");
    Tree_Action(v->Simplexes, Draw_Mesh_Tetrahedron);
    Tree_Action(v->SimplexesBase, Draw_Mesh_Tetrahedron);
    Tree_Action(v->Hexahedra, Draw_Mesh_Hexahedron);
    Tree_Action(v->Prisms, Draw_Mesh_Prism);
    Tree_Action(v->Pyramids, Draw_Mesh_Pyramid);
  }
}

static int preproNormals = 0;

void Draw_Mesh_Surface(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  if(!(s->Visible & VIS_MESH))
    return;

  theSurface = s;
  theColor = s->Color;
  thePhysical = getFirstPhysical(MSH_PHYSICAL_SURFACE, s->Num);

  if(CTX.mesh.changed && CTX.mesh.smooth_normals){
    Msg(DEBUG, "pre-processing smooth normals");
    if(s->normals) delete s->normals;
    s->normals = new smooth_normals;
    preproNormals = 1;
    Tree_Action(s->Simplexes, Draw_Mesh_Triangle);
    Tree_Action(s->SimplexesBase, Draw_Mesh_Triangle);
    Tree_Action(s->Quadrangles, Draw_Mesh_Quadrangle);
    preproNormals = 0;
  }

  if(CTX.mesh.vertex_arrays){
    if(CTX.mesh.changed){
      Msg(DEBUG, "regenerate surface mesh vertex arrays");
      // triangles
      if(s->TriVertexArray) delete s->TriVertexArray;
      s->TriVertexArray = new VertexArray(3, Tree_Nbr(s->Simplexes) + 
					  Tree_Nbr(s->SimplexesBase));
      s->TriVertexArray->fill = 1;
      Tree_Action(s->Simplexes, Draw_Mesh_Triangle);
      Tree_Action(s->SimplexesBase, Draw_Mesh_Triangle);
      if(s->TriVertexArray){
	Msg(DEBUG, "%d triangles in surface vertex array", s->TriVertexArray->num);
	s->TriVertexArray->fill = 0;
      }
      // quads
      if(s->QuadVertexArray) delete s->QuadVertexArray;
      s->QuadVertexArray = new VertexArray(4, Tree_Nbr(s->Quadrangles));
      s->QuadVertexArray->fill = 1;
      Tree_Action(s->Quadrangles, Draw_Mesh_Quadrangle);
      if(s->QuadVertexArray){
	Msg(DEBUG, "%d quads in surface vertex array", s->QuadVertexArray->num);
	s->QuadVertexArray->fill = 0;
      }
    }
    if(s->TriVertexArray)
      Draw_Mesh_Array(s->TriVertexArray,
		      CTX.mesh.surfaces_faces, CTX.mesh.surfaces_edges);
    if(s->QuadVertexArray)
      Draw_Mesh_Array(s->QuadVertexArray,
		      CTX.mesh.surfaces_faces, CTX.mesh.surfaces_edges);
  }
    
  if(!s->TriVertexArray || CTX.mesh.dual || CTX.mesh.surfaces_num ||
     CTX.mesh.points_per_element || CTX.mesh.normals){
    Msg(DEBUG, "classic triangle data path");
    Tree_Action(s->Simplexes, Draw_Mesh_Triangle);
    Tree_Action(s->SimplexesBase, Draw_Mesh_Triangle);
  }

  if(!s->QuadVertexArray || CTX.mesh.dual || CTX.mesh.surfaces_num ||
     CTX.mesh.points_per_element || CTX.mesh.normals){
    Msg(DEBUG, "classic quadrangle data path");
    Tree_Action(s->Quadrangles, Draw_Mesh_Quadrangle);
  }

  theSurface = NULL;
}

void Draw_Mesh_Extruded_Surfaces(void *a, void *b)
{
  Volume *v = *(Volume **) a;
  if(!(v->Visible & VIS_MESH))
    return;
  Tree_Action(v->Simp_Surf, Draw_Mesh_Triangle);
  Tree_Action(v->Quad_Surf, Draw_Mesh_Quadrangle);
}

void Draw_Mesh_Curve(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  if(c->Num < 0)
    return;
  if(!(c->Visible & VIS_MESH))
    return;
  theColor = c->Color;
  thePhysical = getFirstPhysical(MSH_PHYSICAL_LINE, c->Num);

  Tree_Action(c->Simplexes, Draw_Mesh_Line);
  Tree_Action(c->SimplexesBase, Draw_Mesh_Line);
}

void Draw_Mesh_Point(int num, double x, double y, double z, int degree, int visible)
{
  if(!(visible & VIS_MESH))
    return;

  if(degree == 2)
    glColor4ubv((GLubyte *) & CTX.color.mesh.vertex_deg2);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.vertex);

  if(CTX.mesh.points) {
    if(CTX.mesh.point_type) {
      Draw_Sphere(CTX.mesh.point_size, x, y, z, CTX.mesh.light);
    }
    else {
      glBegin(GL_POINTS);
      glVertex3d(x, y, z);
      glEnd();
    }
  }

  if(CTX.mesh.points_num) {
    char Num[100];
    sprintf(Num, "%d", num);
    double offset = 0.3 * (CTX.mesh.point_size + CTX.gl_fontsize) * CTX.pixel_equiv_x;
    glRasterPos3d(x + offset / CTX.s[0],
                  y + offset / CTX.s[1],
                  z + offset / CTX.s[2]);
    Draw_String(Num);
  }
}

void Draw_Mesh_Point(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;

  if(!CTX.mesh.cut_plane_only_volume && intersectCutPlane(1, &v) < 0)
    return;

  Draw_Mesh_Point(v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z, v->Degree, v->Visible);
}

void Draw_Mesh_Line(void *a, void *b)
{
  double Xc = 0.0, Yc = 0.0, Zc = 0.0, m[3];
  char Num[100];

  SimplexBase *s = *(SimplexBase **) a;

  if(!(s->Visible & VIS_MESH))
    return;

  MeshPartition **part = (MeshPartition**)List_Pointer_Test(THEM->Partitions, s->iPart);
  if(part && !(*part)->Visible)
    return;

  if(CTX.mesh.radius_sup) {
    double r = s->maxEdge();
    if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup)
      return;
  }

  if(!CTX.mesh.cut_plane_only_volume && intersectCutPlane(2, s->V) < 0)
    return;

  Xc = 0.5 * (s->V[0]->Pos.X + s->V[1]->Pos.X);
  Yc = 0.5 * (s->V[0]->Pos.Y + s->V[1]->Pos.Y);
  Zc = 0.5 * (s->V[0]->Pos.Z + s->V[1]->Pos.Z);

  double X[3], Y[3], Z[3];
  int N = s->VSUP ? 3 : 2;

  for(int i = 0; i < 2; i++) {
    X[i] = Xc + CTX.mesh.explode * (s->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (s->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (s->V[i]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(s->V[i]->Num, X[i], Y[i], Z[i], 
		      s->V[i]->Degree, s->V[i]->Visible);
  }
  
  if(N == 3){
    X[2] = X[1];
    Y[2] = Y[1];
    Z[2] = Z[1];
    X[1] = Xc + CTX.mesh.explode * (s->VSUP[0]->Pos.X - Xc);
    Y[1] = Yc + CTX.mesh.explode * (s->VSUP[0]->Pos.Y - Yc);
    Z[1] = Zc + CTX.mesh.explode * (s->VSUP[0]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(s->VSUP[0]->Num, X[1], Y[1], Z[1], 
		      s->VSUP[0]->Degree, s->VSUP[0]->Visible);
  }

  if(theColor.type)
    glColor4ubv((GLubyte *) & theColor.mesh);
  else if(CTX.mesh.color_carousel == 1)
    glColor4ubv((GLubyte *) & CTX.color.mesh.carousel[abs(s->iEnt % 10)]);
  else if(CTX.mesh.color_carousel == 2)
    glColor4ubv((GLubyte *) & CTX.color.mesh.carousel[abs(thePhysical % 10)]);
  else if(CTX.mesh.color_carousel == 3)
    glColor4ubv((GLubyte *) & CTX.color.mesh.carousel[abs(s->iPart % 10)]);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.line);

  if(CTX.mesh.lines) {
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i < N; i++){
      glVertex3d(X[i], Y[i], Z[i]);
    }
    glEnd();
  }

  if(CTX.mesh.lines_num) {
    sprintf(Num, "%d", s->Num);
    double offset = 0.3 * (CTX.mesh.line_width + CTX.gl_fontsize) * CTX.pixel_equiv_x;
    glRasterPos3d(Xc + offset / CTX.s[0],
                  Yc + offset / CTX.s[1],
                  Zc + offset / CTX.s[2]);
    Draw_String(Num);
  }

  if(CTX.mesh.tangents) {
    glColor4ubv((GLubyte *) & CTX.color.mesh.tangents);
    m[0] = X[1] - X[0];
    m[1] = Y[1] - Y[0];
    m[2] = Z[1] - Z[0];
    norme(m);
    m[0] *= CTX.mesh.tangents * CTX.pixel_equiv_x / CTX.s[0];
    m[1] *= CTX.mesh.tangents * CTX.pixel_equiv_x / CTX.s[1];
    m[2] *= CTX.mesh.tangents * CTX.pixel_equiv_x / CTX.s[2];
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		Xc, Yc, Zc, m[0], m[1], m[2], CTX.mesh.light);
  }
}

void _triFace(double x0, double y0, double z0,
	      double x1, double y1, double z1,
	      double x2, double y2, double z2)
{
  double n[3], ns[3];

  if(CTX.mesh.light || (theSurface && preproNormals)){
    normal3points(x0, y0, z0, x1, y1, z1, x2, y2, z2, n);
    if(theSurface && preproNormals){
      theSurface->normals->add(x0, y0, z0, n[0], n[1], n[2]);
      theSurface->normals->add(x1, y1, z1, n[0], n[1], n[2]);
      theSurface->normals->add(x2, y2, z2, n[0], n[1], n[2]);
      return;
    }
    glNormal3dv(n);
  }

  if(CTX.mesh.light && theSurface && CTX.mesh.smooth_normals){
    ns[0] = n[0]; ns[1] = n[1]; ns[2] = n[2];
    theSurface->normals->get(x0, y0, z0, ns[0], ns[1], ns[2], 
			     CTX.mesh.angle_smooth_normals);
    glNormal3dv(ns);    
  }
  glVertex3d(x0, y0, z0);

  if(CTX.mesh.light && theSurface && CTX.mesh.smooth_normals){
    ns[0] = n[0]; ns[1] = n[1]; ns[2] = n[2];
    theSurface->normals->get(x1, y1, z1, ns[0], ns[1], ns[2], 
			     CTX.mesh.angle_smooth_normals);
    glNormal3dv(ns);    
  }
  glVertex3d(x1, y1, z1);

  if(CTX.mesh.light && theSurface && CTX.mesh.smooth_normals){
    ns[0] = n[0]; ns[1] = n[1]; ns[2] = n[2];
    theSurface->normals->get(x2, y2, z2, ns[0], ns[1], ns[2], 
			     CTX.mesh.angle_smooth_normals);
    glNormal3dv(ns);    
  }
  glVertex3d(x2, y2, z2);
}

void _triFace2(double *x, double *y, double *z,
	       double *x2, double *y2, double *z2,
	       int i0, int i1, int i2, 
	       int j0, int j1, int j2)
{
  _triFace(x[i0], y[i0], z[i0], x2[j0], y2[j0], z2[j0], x2[j2], y2[j2], z2[j2]);
  _triFace(x[i1], y[i1], z[i1], x2[j1], y2[j1], z2[j1], x2[j0], y2[j0], z2[j0]);
  _triFace(x[i2], y[i2], z[i2], x2[j2], y2[j2], z2[j2], x2[j1], y2[j1], z2[j1]);
  _triFace(x2[j0], y2[j0], z2[j0], x2[j1], y2[j1], z2[j1], x2[j2], y2[j2], z2[j2]);
}

void _quadFace(double *x, double *y, double *z,
	       int i0, int i1, int i2, int i3)
{
  double n[3], ns[3];

  if(CTX.mesh.light || (theSurface && preproNormals)){
    normal3points(x[i0], y[i0], z[i0],
		  x[i1], y[i1], z[i1],
		  x[i2], y[i2], z[i2], n);
    if(theSurface && preproNormals){
      theSurface->normals->add(x[i0], y[i0], z[i0], n[0], n[1], n[2]);
      theSurface->normals->add(x[i1], y[i1], z[i1], n[0], n[1], n[2]);
      theSurface->normals->add(x[i2], y[i2], z[i2], n[0], n[1], n[2]);
      theSurface->normals->add(x[i3], y[i3], z[i3], n[0], n[1], n[2]);
      return;
    }
    glNormal3dv(n);
  }

  if(CTX.mesh.light && theSurface && CTX.mesh.smooth_normals){
    ns[0] = n[0]; ns[1] = n[1]; ns[2] = n[2];
    theSurface->normals->get(x[i0], y[i0], z[i0], ns[0], ns[1], ns[2], 
			     CTX.mesh.angle_smooth_normals);
    glNormal3dv(ns);    
  }
  glVertex3d(x[i0], y[i0], z[i0]);

  if(CTX.mesh.light && theSurface && CTX.mesh.smooth_normals){
    ns[0] = n[0]; ns[1] = n[1]; ns[2] = n[2];
    theSurface->normals->get(x[i1], y[i1], z[i1], ns[0], ns[1], ns[2], 
			     CTX.mesh.angle_smooth_normals);
    glNormal3dv(ns);    
  }
  glVertex3d(x[i1], y[i1], z[i1]);

  if(CTX.mesh.light && theSurface && CTX.mesh.smooth_normals){
    ns[0] = n[0]; ns[1] = n[1]; ns[2] = n[2];
    theSurface->normals->get(x[i2], y[i2], z[i2], ns[0], ns[1], ns[2], 
			     CTX.mesh.angle_smooth_normals);
    glNormal3dv(ns);    
  }
  glVertex3d(x[i2], y[i2], z[i2]);

  if(CTX.mesh.light && theSurface && CTX.mesh.smooth_normals){
    ns[0] = n[0]; ns[1] = n[1]; ns[2] = n[2];
    theSurface->normals->get(x[i3], y[i3], z[i3], ns[0], ns[1], ns[2], 
			     CTX.mesh.angle_smooth_normals);
    glNormal3dv(ns);    
  }
  glVertex3d(x[i3], y[i3], z[i3]);
}

void _quadFace2(double *x, double *y, double *z,
		double *x2, double *y2, double *z2,
		int i0, int i1, int i2, int i3,
		int j0, int j1, int j2, int j3, int j4)
{
  _triFace(x[i0], y[i0], z[i0], x2[j0], y2[j0], z2[j0], x2[j4], y2[j4], z2[j4]);
  _triFace(x2[j0], y2[j0], z2[j0], x[i1], y[i1], z[i1], x2[j4], y2[j4], z2[j4]);
  _triFace(x[i1], y[i1], z[i1], x2[j1], y2[j1], z2[j1], x2[j4], y2[j4], z2[j4]);
  _triFace(x2[j1], y2[j1], z2[j1], x[i2], y[i2], z[i2], x2[j4], y2[j4], z2[j4]);
  _triFace(x[i2], y[i2], z[i2], x2[j2], y2[j2], z2[j2], x2[j4], y2[j4], z2[j4]);
  _triFace(x2[j2], y2[j2], z2[j2], x[i3], y[i3], z[i3], x2[j4], y2[j4], z2[j4]);
  _triFace(x[i3], y[i3], z[i3], x2[j3], y2[j3], z2[j3], x2[j4], y2[j4], z2[j4]);
  _triFace(x2[j3], y2[j3], z2[j3], x[i0], y[i0], z[i0], x2[j4], y2[j4], z2[j4]);
}

void Draw_Mesh_Array(VertexArray *va, int faces, int edges)
{
  if(!va->num)
    return;

  glVertexPointer(3, GL_FLOAT, 0, va->vertices->array);
  glNormalPointer(GL_FLOAT, 0, va->normals->array);
  glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->colors->array);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);

  if(faces){
    if(CTX.mesh.light)
      glEnable(GL_LIGHTING);
    else
      glDisableClientState(GL_NORMAL_ARRAY);
    if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
    glDrawArrays((va->type == 3) ? GL_TRIANGLES : GL_QUADS, 0, va->type * va->num);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
  }
      
  if(edges){
    if(faces){
      glDisableClientState(GL_COLOR_ARRAY);
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    }
    glDisableClientState(GL_NORMAL_ARRAY);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays((va->type == 3) ? GL_TRIANGLES : GL_QUADS, 0, va->type * va->num);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
}

void Draw_Mesh_Triangle(void *a, void *b)
{
  double X[3], Y[3], Z[3], X2[3], Y2[3], Z2[3];
  double n[3];
  char Num[256];

  SimplexBase *s = *(SimplexBase **) a;

  if(!s->V[2]) // the old extrusion algo puts lines in the simp_surf tree...
    return;

  if(!(s->Visible & VIS_MESH))
    return;

  MeshPartition **part = (MeshPartition**)List_Pointer_Test(THEM->Partitions, s->iPart);
  if(part && !(*part)->Visible)
    return;

  if(CTX.mesh.radius_sup) {
    double r = s->maxEdge();
    if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup)
      return;
  }

  if(!CTX.mesh.cut_plane_only_volume && intersectCutPlane(3, s->V) < 0)
    return;

  unsigned int col;
  if(theColor.type)
    col = theColor.mesh;
  else if(CTX.mesh.color_carousel == 1)
    col = CTX.color.mesh.carousel[abs(s->iEnt % 10)];
  else if(CTX.mesh.color_carousel == 2)
    col = CTX.color.mesh.carousel[abs(thePhysical % 10)];
  else if(CTX.mesh.color_carousel == 3)
    col = CTX.color.mesh.carousel[abs(s->iPart % 10)];
  else
    col = CTX.color.mesh.triangle;

  double Xc = (s->V[0]->Pos.X + s->V[1]->Pos.X + s->V[2]->Pos.X) / 3.;
  double Yc = (s->V[0]->Pos.Y + s->V[1]->Pos.Y + s->V[2]->Pos.Y) / 3.;
  double Zc = (s->V[0]->Pos.Z + s->V[1]->Pos.Z + s->V[2]->Pos.Z) / 3.;

  for(int i = 0; i < 3; i++) {
    X[i] = Xc + CTX.mesh.explode * (s->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (s->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (s->V[i]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(s->V[i]->Num, X[i], Y[i], Z[i], 
		      s->V[i]->Degree, s->V[i]->Visible);
  }

  if(s->VSUP){
    if(theSurface && theSurface->TriVertexArray){
      // vertex arrays not implemented for second order elements
      delete theSurface->TriVertexArray;
      theSurface->TriVertexArray = NULL;
    }
    for(int i = 0; i < 3; i++) {
      X2[i] = Xc + CTX.mesh.explode * (s->VSUP[i]->Pos.X - Xc);
      Y2[i] = Yc + CTX.mesh.explode * (s->VSUP[i]->Pos.Y - Yc);
      Z2[i] = Zc + CTX.mesh.explode * (s->VSUP[i]->Pos.Z - Zc);
      if(CTX.mesh.points_per_element)
	Draw_Mesh_Point(s->VSUP[i]->Num, X2[i], Y2[i], Z2[i], 
			s->VSUP[i]->Degree, s->VSUP[i]->Visible);
    }
  }

  if(theSurface && theSurface->TriVertexArray){
    if(preproNormals || theSurface->TriVertexArray->fill)
     normal3points(X[0], Y[0], Z[0], 
		   X[1], Y[1], Z[1],
		   X[2], Y[2], Z[2], n);
    if(preproNormals){
      for(int i = 0; i < 3; i++)
	theSurface->normals->add(X[i], Y[i], Z[i], n[0], n[1], n[2]);
      return;
    }
    if(theSurface->TriVertexArray->fill){
      for(int i = 0; i < 3; i++){
	double ns[3] = {n[0], n[1], n[2]};
	if(CTX.mesh.smooth_normals)
	  theSurface->normals->get(X[i], Y[i], Z[i], ns[0], ns[1], ns[2], 
				   CTX.mesh.angle_smooth_normals);
	theSurface->TriVertexArray->add(X[i], Y[i], Z[i], ns[0], ns[1], ns[2], col);
      }
      theSurface->TriVertexArray->num++;
    }
  }    
  else{
    if(CTX.mesh.surfaces_edges){
      if(CTX.mesh.surfaces_faces)
	glColor4ubv((GLubyte *) & CTX.color.mesh.line);
      else
	glColor4ubv((GLubyte *) & col);
      glBegin(GL_LINE_LOOP);
      for(int i = 0; i < 3; i++){
	glVertex3d(X[i], Y[i], Z[i]);
	if(s->VSUP) glVertex3d(X2[i], Y2[i], Z2[i]);
      }
      glEnd();
    }

    if(CTX.mesh.surfaces_faces) {
      glColor4ubv((GLubyte *) & col);      
      if(CTX.mesh.light) glEnable(GL_LIGHTING);
      if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
      if(!s->VSUP) {
	glBegin(GL_TRIANGLES);
	_triFace(X[0], Y[0], Z[0], X[1], Y[1], Z[1], X[2], Y[2], Z[2]);
	glEnd();
      }
      else {
	glBegin(GL_TRIANGLES);
	_triFace2(X, Y, Z, X2, Y2, Z2, 0, 1, 2, 0, 1, 2);
	glEnd();
      }		    
      glDisable(GL_POLYGON_OFFSET_FILL);
      glDisable(GL_LIGHTING);
    }
  }

  if(CTX.mesh.dual) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    for(int i = 0; i < 3; i++) {
      int j = i ? (i - 1) : 2;
      glVertex3d(Xc, Yc, Zc);
      glVertex3d((X[i] + X[j]) / 2., (Y[i] + Y[j]) / 2., (Z[i] + Z[j]) / 2.);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if(CTX.mesh.surfaces_num) {
    if(CTX.mesh.surfaces_faces)
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    else
      glColor4ubv((GLubyte *) & col);
    sprintf(Num, "%d", s->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }

  if(CTX.mesh.normals) {
    normal3points(X[0], Y[0], Z[0], 
		  X[1], Y[1], Z[1],
		  X[2], Y[2], Z[2], n);
    glColor4ubv((GLubyte *) & CTX.color.mesh.normals);
    n[0] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[0];
    n[1] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[1];
    n[2] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[2];
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		Xc, Yc, Zc, n[0], n[1], n[2], CTX.mesh.light);
  }
}

void Draw_Mesh_Quadrangle(void *a, void *b)
{
  double X[4], Y[4], Z[4], X2[5], Y2[5], Z2[5];
  double n[3];
  char Num[256];

  Quadrangle *q = *(Quadrangle **) a;

  if(!(q->Visible & VIS_MESH))
    return;

  MeshPartition **part = (MeshPartition**)List_Pointer_Test(THEM->Partitions, q->iPart);
  if(part && !(*part)->Visible)
    return;

  if(CTX.mesh.radius_sup) {
    double r = q->maxEdge();
    if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup)
      return;
  }

  if(!CTX.mesh.cut_plane_only_volume && intersectCutPlane(4, q->V) < 0)
    return;

  unsigned int col;
  if(theColor.type)
    col = theColor.mesh;
  else if(CTX.mesh.color_carousel == 1)
    col = CTX.color.mesh.carousel[abs(q->iEnt % 10)];
  else if(CTX.mesh.color_carousel == 2)
    col = CTX.color.mesh.carousel[abs(thePhysical % 10)];
  else if(CTX.mesh.color_carousel == 3)
    col = CTX.color.mesh.carousel[abs(q->iPart % 10)];
  else
    col = CTX.color.mesh.quadrangle;

  double Xc = 0.25 * (q->V[0]->Pos.X + q->V[1]->Pos.X + 
		      q->V[2]->Pos.X + q->V[3]->Pos.X);
  double Yc = 0.25 * (q->V[0]->Pos.Y + q->V[1]->Pos.Y + 
		      q->V[2]->Pos.Y + q->V[3]->Pos.Y);
  double Zc = 0.25 * (q->V[0]->Pos.Z + q->V[1]->Pos.Z + 
		      q->V[2]->Pos.Z + q->V[3]->Pos.Z);

  for(int i = 0; i < 4; i++) {
    X[i] = Xc + CTX.mesh.explode * (q->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (q->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (q->V[i]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(q->V[i]->Num, X[i], Y[i], Z[i], 
		      q->V[i]->Degree, q->V[i]->Visible);
  }

  if(q->VSUP){
    if(theSurface && theSurface->QuadVertexArray){
      // vertex arrays not implemented for second order elements
      delete theSurface->QuadVertexArray;
      theSurface->QuadVertexArray = NULL;
    }
    for(int i = 0; i < 5; i++) {
      X2[i] = Xc + CTX.mesh.explode * (q->VSUP[i]->Pos.X - Xc);
      Y2[i] = Yc + CTX.mesh.explode * (q->VSUP[i]->Pos.Y - Yc);
      Z2[i] = Zc + CTX.mesh.explode * (q->VSUP[i]->Pos.Z - Zc);
      if(CTX.mesh.points_per_element)
	Draw_Mesh_Point(q->VSUP[i]->Num, X2[i], Y2[i], Z2[i], 
			q->VSUP[i]->Degree, q->VSUP[i]->Visible);
    }
  }

  if(theSurface && theSurface->QuadVertexArray){
    if(preproNormals || theSurface->QuadVertexArray->fill)
      normal3points(X[0], Y[0], Z[0], 
		    X[1], Y[1], Z[1],
		    X[2], Y[2], Z[2], n);
    if(preproNormals){
      for(int i = 0; i < 4; i++)
	theSurface->normals->add(X[i], Y[i], Z[i], n[0], n[1], n[2]);
      return;
    }
    if(theSurface->QuadVertexArray->fill){
      for(int i = 0; i < 4; i++){
	double ns[3] = {n[0], n[1], n[2]};
	if(CTX.mesh.smooth_normals)
	  theSurface->normals->get(X[i], Y[i], Z[i], ns[0], ns[1], ns[2], 
				   CTX.mesh.angle_smooth_normals);
	theSurface->QuadVertexArray->add(X[i], Y[i], Z[i], ns[0], ns[1], ns[2], col);
      }
      theSurface->QuadVertexArray->num++;
    }
  }    
  else{
    if(CTX.mesh.surfaces_edges){
      if(CTX.mesh.surfaces_faces)
	glColor4ubv((GLubyte *) & CTX.color.mesh.line);
      else
	glColor4ubv((GLubyte *) & col);
      glBegin(GL_LINE_LOOP);
      for(int i = 0; i < 4; i++){
	glVertex3d(X[i], Y[i], Z[i]);
	if(q->VSUP) glVertex3d(X2[i], Y2[i], Z2[i]);
      }
      glEnd();
    }

    if(CTX.mesh.surfaces_faces) {
      glColor4ubv((GLubyte *) & col);
      if(CTX.mesh.light) glEnable(GL_LIGHTING);
      if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
      if(!q->VSUP) {
	glBegin(GL_QUADS);
	_quadFace(X, Y, Z, 0, 1, 2, 3);
	glEnd();
      }
      else {
	glBegin(GL_TRIANGLES);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 0, 1, 2, 3, 0, 1, 2, 3, 4);
	glEnd();
      }
      glDisable(GL_POLYGON_OFFSET_FILL);
      glDisable(GL_LIGHTING);
    }
  }

  if(CTX.mesh.dual) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    for(int i = 0; i < 4; i++) {
      int j = i ? (i - 1) : 3;
      glVertex3d(Xc, Yc, Zc);
      glVertex3d((X[i] + X[j]) / 2., (Y[i] + Y[j]) / 2., (Z[i] + Z[j]) / 2.);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if(CTX.mesh.surfaces_num) {
    if(CTX.mesh.surfaces_faces)
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    else
      glColor4ubv((GLubyte *) & col);
    sprintf(Num, "%d", q->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }

  if(CTX.mesh.normals) {
    glColor4ubv((GLubyte *) & CTX.color.mesh.normals);
    normal3points(X[0], Y[0], Z[0], 
		  X[1], Y[1], Z[1],
		  X[2], Y[2], Z[2], n);
    n[0] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[0];
    n[1] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[1];
    n[2] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[2];
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		Xc, Yc, Zc, n[0], n[1], n[2], CTX.mesh.light);
  }
}

void Draw_Mesh_Tetrahedron(void *a, void *b)
{
  char Num[100];
  double tmp, X[4], Y[4], Z[4], X2[6], Y2[6], Z2[6];

  SimplexBase *s = *(SimplexBase **) a;

  if(!s->V[3] || !(s->Visible & VIS_MESH))
    return;

  MeshPartition **part = (MeshPartition**)List_Pointer_Test(THEM->Partitions, s->iPart);
  if(part && !(*part)->Visible)
    return;

  if(CTX.mesh.gamma_sup) {
    tmp = s->GammaShapeMeasure();
    if(tmp < CTX.mesh.gamma_inf || tmp > CTX.mesh.gamma_sup)
      return;
  }

  if(CTX.mesh.radius_sup) {
    double r = s->maxEdge();
    if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup)
      return;
  }
  
  int edges = CTX.mesh.volumes_edges;
  int faces = CTX.mesh.volumes_faces;

  if(intersectCutPlane(4, s->V, &edges, &faces) < 0)
    return;

  unsigned int col;
  if(theColor.type)
    col = theColor.mesh;
  else if(CTX.mesh.color_carousel == 1)
    col = CTX.color.mesh.carousel[abs(s->iEnt % 10)];
  else if(CTX.mesh.color_carousel == 2)
    col = CTX.color.mesh.carousel[abs(thePhysical % 10)];
  else if(CTX.mesh.color_carousel == 3)
    col = CTX.color.mesh.carousel[abs(s->iPart % 10)];
  else
    col = CTX.color.mesh.tetrahedron;

  double Xc = .25 * (s->V[0]->Pos.X + s->V[1]->Pos.X +
                     s->V[2]->Pos.X + s->V[3]->Pos.X);
  double Yc = .25 * (s->V[0]->Pos.Y + s->V[1]->Pos.Y +
                     s->V[2]->Pos.Y + s->V[3]->Pos.Y);
  double Zc = .25 * (s->V[0]->Pos.Z + s->V[1]->Pos.Z +
                     s->V[2]->Pos.Z + s->V[3]->Pos.Z);

  for(int i = 0; i < 4; i++) {
    X[i] = Xc + CTX.mesh.explode * (s->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (s->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (s->V[i]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(s->V[i]->Num, X[i], Y[i], Z[i], 
		      s->V[i]->Degree, s->V[i]->Visible);
  }

  if(s->VSUP){
    if(theVolume && theVolume->TriVertexArray){
      // vertex arrays not implemented for second order elements
      delete theVolume->TriVertexArray;
      theVolume->TriVertexArray = NULL;
    }
    for(int i = 0; i < 6; i++) {
      X2[i] = Xc + CTX.mesh.explode * (s->VSUP[i]->Pos.X - Xc);
      Y2[i] = Yc + CTX.mesh.explode * (s->VSUP[i]->Pos.Y - Yc);
      Z2[i] = Zc + CTX.mesh.explode * (s->VSUP[i]->Pos.Z - Zc);
      if(CTX.mesh.points_per_element)
	Draw_Mesh_Point(s->VSUP[i]->Num, X2[i], Y2[i], Z2[i], 
			s->VSUP[i]->Degree, s->VSUP[i]->Visible);
    }
  }

  if(CTX.mesh.use_cut_plane && CTX.mesh.cut_plane_as_surface && 
     (edges || faces) && !(CTX.mesh.volumes_edges || CTX.mesh.volumes_faces) &&
     theVolume && theVolume->TriVertexArray){
    if(theVolume->TriVertexArray->fill){
      for(int i = 0; i < 4; i++){
	int a = trifaces_tetra[i][0];
	int b = trifaces_tetra[i][1];
	int c = trifaces_tetra[i][2];
	double n[3];
	normal3points(X[a], Y[a], Z[a], X[b], Y[b], Z[b], X[c], Y[c], Z[c], n);
	theVolume->TriVertexArray->add(X[a], Y[a], Z[a], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->add(X[b], Y[b], Z[b], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->add(X[c], Y[c], Z[c], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->num++;
      }
    }
  }    
  else{
    if(edges) {
      if(CTX.mesh.surfaces_faces || faces)
	glColor4ubv((GLubyte *) & CTX.color.mesh.line);
      else
	glColor4ubv((GLubyte *) & col);
      glBegin(GL_LINES);
      for(int i = 0; i < 6; i++){
	int j = edges_tetra[i][0];
	int k = edges_tetra[i][1];
	glVertex3d(X[j], Y[j], Z[j]);
	if(s->VSUP){
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	}
	glVertex3d(X[k], Y[k], Z[k]);
      }
      glEnd();
    }
    
    if(faces){
      glColor4ubv((GLubyte *) & col);
      if(CTX.mesh.light) glEnable(GL_LIGHTING);
      if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
      if(!s->VSUP){
	glBegin(GL_TRIANGLES);
	_triFace(X[0], Y[0], Z[0], X[2], Y[2], Z[2], X[1], Y[1], Z[1]);
	_triFace(X[0], Y[0], Z[0], X[1], Y[1], Z[1], X[3], Y[3], Z[3]);
	_triFace(X[0], Y[0], Z[0], X[3], Y[3], Z[3], X[2], Y[2], Z[2]);
	_triFace(X[3], Y[3], Z[3], X[1], Y[1], Z[1], X[2], Y[2], Z[2]);
	glEnd();
      }
      else{
	glBegin(GL_TRIANGLES);
	_triFace2(X, Y, Z, X2, Y2, Z2, 0, 2, 1, 2, 1, 0);
	_triFace2(X, Y, Z, X2, Y2, Z2, 0, 1, 3, 0, 5, 3);
	_triFace2(X, Y, Z, X2, Y2, Z2, 0, 3, 2, 3, 4, 2);
	_triFace2(X, Y, Z, X2, Y2, Z2, 3, 1, 2, 5, 1, 4);
	glEnd();
      }
      glDisable(GL_POLYGON_OFFSET_FILL);
      glDisable(GL_LIGHTING);
    }
  }

  if(CTX.mesh.dual) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[1] + X[2]) / 3., (Y[0] + Y[1] + Y[2]) / 3.,
               (Z[0] + Z[1] + Z[2]) / 3.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[1] + X[3]) / 3., (Y[0] + Y[1] + Y[3]) / 3.,
               (Z[0] + Z[1] + Z[3]) / 3.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[2] + X[3]) / 3., (Y[0] + Y[2] + Y[3]) / 3.,
               (Z[0] + Z[2] + Z[3]) / 3.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[1] + X[2] + X[3]) / 3., (Y[1] + Y[2] + Y[3]) / 3.,
               (Z[1] + Z[2] + Z[3]) / 3.);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if(CTX.mesh.volumes_num) {
    if(CTX.mesh.surfaces_faces || faces)
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    else
      glColor4ubv((GLubyte *) & col);
    sprintf(Num, "%d", s->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }
}

void Draw_Mesh_Hexahedron(void *a, void *b)
{
  double Xc = 0.0, Yc = 0.0, Zc = 0.0;
  double X[8], Y[8], Z[8], X2[18], Y2[18], Z2[18];
  char Num[100];

  Hexahedron *h = *(Hexahedron **) a;

  if(!(h->Visible & VIS_MESH))
    return;

  MeshPartition **part = (MeshPartition**)List_Pointer_Test(THEM->Partitions, h->iPart);
  if(part && !(*part)->Visible)
    return;

  if(CTX.mesh.radius_sup) {
    double r = h->maxEdge();
    if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup)
      return;
  }

  int edges = CTX.mesh.volumes_edges;
  int faces = CTX.mesh.volumes_faces;

  if(intersectCutPlane(8, h->V, &edges, &faces) < 0)
    return;

  unsigned int col;
  if(theColor.type)
    col = theColor.mesh;
  else if(CTX.mesh.color_carousel == 1)
    col = CTX.color.mesh.carousel[abs(h->iEnt % 10)];
  else if(CTX.mesh.color_carousel == 2)
    col = CTX.color.mesh.carousel[abs(thePhysical % 10)];
  else if(CTX.mesh.color_carousel == 3)
    col = CTX.color.mesh.carousel[abs(h->iPart % 10)];
  else
    col = CTX.color.mesh.hexahedron;

  for(int i = 0; i < 8; i++) {
    Xc += h->V[i]->Pos.X;
    Yc += h->V[i]->Pos.Y;
    Zc += h->V[i]->Pos.Z;
  }
  Xc *= .125;
  Zc *= .125;
  Yc *= .125;

  for(int i = 0; i < 8; i++) {
    X[i] = Xc + CTX.mesh.explode * (h->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (h->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (h->V[i]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(h->V[i]->Num, X[i], Y[i], Z[i], 
		      h->V[i]->Degree, h->V[i]->Visible);
  }

  if(h->VSUP){
    if(theVolume && theVolume->QuadVertexArray){
      // vertex arrays not implemented for second order elements
      delete theVolume->QuadVertexArray;
      theVolume->QuadVertexArray = NULL;
    }
    for(int i = 0; i < 18; i++) {
      X2[i] = Xc + CTX.mesh.explode * (h->VSUP[i]->Pos.X - Xc);
      Y2[i] = Yc + CTX.mesh.explode * (h->VSUP[i]->Pos.Y - Yc);
      Z2[i] = Zc + CTX.mesh.explode * (h->VSUP[i]->Pos.Z - Zc);
      if(CTX.mesh.points_per_element)
	Draw_Mesh_Point(h->VSUP[i]->Num, X2[i], Y2[i], Z2[i], 
			h->VSUP[i]->Degree, h->VSUP[i]->Visible);
    }
  }

  if(CTX.mesh.use_cut_plane && CTX.mesh.cut_plane_as_surface && 
     (edges || faces) && !(CTX.mesh.volumes_edges || CTX.mesh.volumes_faces) &&
     theVolume && theVolume->QuadVertexArray){
    if(theVolume->QuadVertexArray->fill){
      for(int i = 0; i < 6; i++){
	int a = quadfaces_hexa[i][0];
	int b = quadfaces_hexa[i][1];
	int c = quadfaces_hexa[i][2];
	int d = quadfaces_hexa[i][3];
	double n[3];
	normal3points(X[a], Y[a], Z[a], X[b], Y[b], Z[b], X[c], Y[c], Z[c], n);
	theVolume->QuadVertexArray->add(X[a], Y[a], Z[a], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->add(X[b], Y[b], Z[b], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->add(X[c], Y[c], Z[c], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->add(X[d], Y[d], Z[d], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->num++;
      }
    }
  }    
  else{
    if(edges){
      if(CTX.mesh.surfaces_faces || faces)
	glColor4ubv((GLubyte *) & CTX.color.mesh.line);
      else
	glColor4ubv((GLubyte *) & col);
      glBegin(GL_LINES);
      for(int i = 0; i < 12; i++){
	int j = edges_hexa[i][0];
	int k = edges_hexa[i][1];
	glVertex3d(X[j], Y[j], Z[j]);
	if(h->VSUP){
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	}
	glVertex3d(X[k], Y[k], Z[k]);
      }
      glEnd();
    }
    
    if(faces){
      glColor4ubv((GLubyte *) & col);
      if(CTX.mesh.light) glEnable(GL_LIGHTING);
      if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
      if(!h->VSUP){
	glBegin(GL_QUADS);
	_quadFace(X, Y, Z, 0, 3, 2, 1);
	_quadFace(X, Y, Z, 0, 1, 5, 4);
	_quadFace(X, Y, Z, 0, 4, 7, 3);
	_quadFace(X, Y, Z, 1, 2, 6, 5);
	_quadFace(X, Y, Z, 2, 3, 7, 6);
	_quadFace(X, Y, Z, 4, 5, 6, 7);
	glEnd();
      }
      else{
	glBegin(GL_TRIANGLES);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 0, 3, 2, 1, 1, 5, 3, 0, 12);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 0, 1, 5, 4, 0, 4, 8, 2, 13);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 0, 4, 7, 3, 2, 9, 7, 1, 14);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 1, 2, 6, 5, 3, 6, 10, 4, 15);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 2, 3, 7, 6, 5, 7, 11, 6, 16);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 4, 5, 6, 7, 8, 10, 11, 9, 17);
	glEnd();
      }
      glDisable(GL_POLYGON_OFFSET_FILL);
      glDisable(GL_LIGHTING);
    }
  }    

  if(CTX.mesh.dual) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[1] + X[5] + X[4]) / 4., (Y[0] + Y[1] + Y[5] + Y[4]) / 4.,
	       (Z[0] + Z[1] + Z[5] + Z[4]) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[3] + X[2] + X[1]) / 4., (Y[0] + Y[3] + Y[2] + Y[1]) / 4.,
	       (Z[0] + Z[3] + Z[2] + Z[1]) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[4] + X[7] + X[3]) / 4., (Y[0] + Y[4] + Y[7] + Y[3]) / 4.,
	       (Z[0] + Z[4] + Z[7] + Z[3]) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[1] + X[2] + X[6] + X[5]) / 4., (Y[1] + Y[2] + Y[6] + Y[5]) / 4.,
	       (Z[1] + Z[2] + Z[6] + Z[5]) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[2] + X[3] + X[7] + X[6]) / 4., (Y[2] + Y[3] + Y[7] + Y[6]) / 4.,
	       (Z[2] + Z[3] + Z[7] + Z[6]) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[4] + X[5] + X[6] + X[7]) / 4., (Y[4] + Y[5] + Y[6] + Y[7]) / 4.,
	       (Z[4] + Z[5] + Z[6] + Z[7]) / 4.);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if(CTX.mesh.volumes_num) {
    if(CTX.mesh.surfaces_faces || faces)
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    else
      glColor4ubv((GLubyte *) & col);
    sprintf(Num, "%d", h->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }
}

void Draw_Mesh_Prism(void *a, void *b)
{
  double Xc = 0.0, Yc = 0.0, Zc = 0.0;
  double X[6], Y[6], Z[6], X2[12], Y2[12], Z2[12];
  char Num[100];

  Prism *p = *(Prism **) a;

  if(!(p->Visible & VIS_MESH))
    return;

  MeshPartition **part = (MeshPartition**)List_Pointer_Test(THEM->Partitions, p->iPart);
  if(part && !(*part)->Visible)
    return;

  if(CTX.mesh.radius_sup) {
    double r = p->maxEdge();
    if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup)
      return;
  }

  int edges = CTX.mesh.volumes_edges;
  int faces = CTX.mesh.volumes_faces;

  if(intersectCutPlane(6, p->V, &edges, &faces) < 0)
    return;

  unsigned int col;
  if(theColor.type)
    col = theColor.mesh;
  else if(CTX.mesh.color_carousel == 1)
    col = CTX.color.mesh.carousel[abs(p->iEnt % 10)];
  else if(CTX.mesh.color_carousel == 2)
    col = CTX.color.mesh.carousel[abs(thePhysical % 10)];
  else if(CTX.mesh.color_carousel == 3)
    col = CTX.color.mesh.carousel[abs(p->iPart % 10)];
  else
    col = CTX.color.mesh.prism;

  for(int i = 0; i < 6; i++) {
    Xc += p->V[i]->Pos.X;
    Yc += p->V[i]->Pos.Y;
    Zc += p->V[i]->Pos.Z;
  }
  Xc /= 6.;
  Zc /= 6.;
  Yc /= 6.;

  for(int i = 0; i < 6; i++) {
    X[i] = Xc + CTX.mesh.explode * (p->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (p->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (p->V[i]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(p->V[i]->Num, X[i], Y[i], Z[i], 
		      p->V[i]->Degree, p->V[i]->Visible);
  }

  if(p->VSUP){
    if(theVolume && theVolume->TriVertexArray){
      // vertex arrays not implemented for second order elements
      delete theVolume->TriVertexArray;
      theVolume->TriVertexArray = NULL;
    }
    if(theVolume && theVolume->QuadVertexArray){
      // vertex arrays not implemented for second order elements
      delete theVolume->QuadVertexArray;
      theVolume->QuadVertexArray = NULL;
    }
    for(int i = 0; i < 12; i++) {
      X2[i] = Xc + CTX.mesh.explode * (p->VSUP[i]->Pos.X - Xc);
      Y2[i] = Yc + CTX.mesh.explode * (p->VSUP[i]->Pos.Y - Yc);
      Z2[i] = Zc + CTX.mesh.explode * (p->VSUP[i]->Pos.Z - Zc);
      if(CTX.mesh.points_per_element)
	Draw_Mesh_Point(p->VSUP[i]->Num, X2[i], Y2[i], Z2[i], 
			p->VSUP[i]->Degree, p->VSUP[i]->Visible);
    }
  }

  if(CTX.mesh.use_cut_plane && CTX.mesh.cut_plane_as_surface && 
     (edges || faces) && !(CTX.mesh.volumes_edges || CTX.mesh.volumes_faces) &&
     theVolume && theVolume->TriVertexArray && theVolume->QuadVertexArray){
    if(theVolume->TriVertexArray->fill){
      for(int i = 0; i < 2; i++){
	int a = trifaces_prism[i][0];
	int b = trifaces_prism[i][1];
	int c = trifaces_prism[i][2];
	double n[3];
	normal3points(X[a], Y[a], Z[a], X[b], Y[b], Z[b], X[c], Y[c], Z[c], n);
	theVolume->TriVertexArray->add(X[a], Y[a], Z[a], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->add(X[b], Y[b], Z[b], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->add(X[c], Y[c], Z[c], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->num++;
      }
    }
    if(theVolume->QuadVertexArray->fill){
      for(int i = 0; i < 3; i++){
	int a = quadfaces_prism[i][0];
	int b = quadfaces_prism[i][1];
	int c = quadfaces_prism[i][2];
	int d = quadfaces_prism[i][3];
	double n[3];
	normal3points(X[a], Y[a], Z[a], X[b], Y[b], Z[b], X[c], Y[c], Z[c], n);
	theVolume->QuadVertexArray->add(X[a], Y[a], Z[a], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->add(X[b], Y[b], Z[b], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->add(X[c], Y[c], Z[c], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->add(X[d], Y[d], Z[d], n[0], n[1], n[2], col);
	theVolume->QuadVertexArray->num++;
      }
    }
  }    
  else{
    if(edges){
      if(CTX.mesh.surfaces_faces || faces)
	glColor4ubv((GLubyte *) & CTX.color.mesh.line);
      else
	glColor4ubv((GLubyte *) & col);
      glBegin(GL_LINES);
      for(int i = 0; i < 9; i++){
	int j = edges_prism[i][0];
	int k = edges_prism[i][1];
	glVertex3d(X[j], Y[j], Z[j]);
	if(p->VSUP){
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	}
	glVertex3d(X[k], Y[k], Z[k]);
      }
      glEnd();
    }
    
    if(faces){
      glColor4ubv((GLubyte *) & col);
      if(CTX.mesh.light) glEnable(GL_LIGHTING);
      if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
      if(!p->VSUP){
	glBegin(GL_TRIANGLES);
	_triFace(X[0], Y[0], Z[0], X[2], Y[2], Z[2], X[1], Y[1], Z[1]);
	_triFace(X[3], Y[3], Z[3], X[4], Y[4], Z[4], X[5], Y[5], Z[5]);
	glEnd();
	glBegin(GL_QUADS);
	_quadFace(X, Y, Z, 0, 1, 4, 3);
	_quadFace(X, Y, Z, 0, 3, 5, 2);
	_quadFace(X, Y, Z, 1, 2, 5, 4);
	glEnd();
      }
      else{
	glBegin(GL_TRIANGLES);
	_triFace2(X, Y, Z, X2, Y2, Z2, 0, 2, 1, 1, 3, 0);
	_triFace2(X, Y, Z, X2, Y2, Z2, 3, 4, 5, 6, 8, 7);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 0, 1, 4, 3, 0, 4, 6, 2, 9);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 0, 3, 5, 2, 2, 7, 5, 1, 10);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 1, 2, 5, 4, 3, 5, 8, 4, 11);
	glEnd();
      }
      glDisable(GL_POLYGON_OFFSET_FILL);
      glDisable(GL_LIGHTING);
    }
  }

  if(CTX.mesh.dual) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[2] + X[1]) / 3., (Y[0] + Y[2] + Y[1]) / 3.,
	       (Z[0] + Z[2] + Z[1]) / 3.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[3] + X[4] + X[5]) / 3., (Y[3] + Y[4] + Y[5]) / 3.,
	       (Z[3] + Z[4] + Z[5]) / 3.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[1] + X[4] + X[3]) / 4., (Y[0] + Y[1] + Y[4] + Y[3]) / 4.,
	       (Z[0] + Z[1] + Z[4] + Z[3]) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[0] + X[3] + X[5] + X[2]) / 4., (Y[0] + Y[3] + Y[5] + Y[2]) / 4.,
	       (Z[0] + Z[3] + Z[5] + Z[2]) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d((X[1] + X[2] + X[5] + X[4]) / 4., (Y[1] + Y[2] + Y[5] + Y[4]) / 4.,
	       (Z[1] + Z[2] + Z[5] + Z[4]) / 4.);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if(CTX.mesh.volumes_num) {
    if(CTX.mesh.surfaces_faces || faces)
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    else
      glColor4ubv((GLubyte *) & col);
    sprintf(Num, "%d", p->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }
}

void Draw_Mesh_Pyramid(void *a, void *b)
{
  double Xc = 0.0, Yc = 0.0, Zc = 0.0;
  double X[5], Y[5], Z[5], X2[9], Y2[9], Z2[9];
  char Num[100];

  Pyramid *p = *(Pyramid **) a;

  if(!(p->Visible & VIS_MESH))
    return;

  MeshPartition **part = (MeshPartition**)List_Pointer_Test(THEM->Partitions, p->iPart);
  if(part && !(*part)->Visible)
    return;

  if(CTX.mesh.radius_sup) {
    double r = p->maxEdge();
    if(r < CTX.mesh.radius_inf || r > CTX.mesh.radius_sup)
      return;
  }

  int edges = CTX.mesh.volumes_edges;
  int faces = CTX.mesh.volumes_faces;

  if(intersectCutPlane(5, p->V, &edges, &faces) < 0)
    return;

  unsigned int col;
  if(theColor.type)
    col = theColor.mesh;
  else if(CTX.mesh.color_carousel == 1)
    col = CTX.color.mesh.carousel[abs(p->iEnt % 10)];
  else if(CTX.mesh.color_carousel == 2)
    col = CTX.color.mesh.carousel[abs(thePhysical % 10)];
  else if(CTX.mesh.color_carousel == 3)
    col = CTX.color.mesh.carousel[abs(p->iPart % 10)];
  else
    col = CTX.color.mesh.pyramid;

  for(int i = 0; i < 5; i++) {
    Xc += p->V[i]->Pos.X;
    Yc += p->V[i]->Pos.Y;
    Zc += p->V[i]->Pos.Z;
  }
  Xc /= 5.;
  Zc /= 5.;
  Yc /= 5.;

  for(int i = 0; i < 5; i++) {
    X[i] = Xc + CTX.mesh.explode * (p->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (p->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (p->V[i]->Pos.Z - Zc);
    if(CTX.mesh.points_per_element)
      Draw_Mesh_Point(p->V[i]->Num, X[i], Y[i], Z[i], 
		      p->V[i]->Degree, p->V[i]->Visible);
  }

  if(p->VSUP){
    if(theVolume && theVolume->TriVertexArray){
      // vertex arrays not implemented for second order elements
      delete theVolume->TriVertexArray;
      theVolume->TriVertexArray = NULL;
    }
    if(theVolume && theVolume->QuadVertexArray){
      // vertex arrays not implemented for second order elements
      delete theVolume->QuadVertexArray;
      theVolume->QuadVertexArray = NULL;
    }
    for(int i = 0; i < 9; i++) {
      X2[i] = Xc + CTX.mesh.explode * (p->VSUP[i]->Pos.X - Xc);
      Y2[i] = Yc + CTX.mesh.explode * (p->VSUP[i]->Pos.Y - Yc);
      Z2[i] = Zc + CTX.mesh.explode * (p->VSUP[i]->Pos.Z - Zc);
      if(CTX.mesh.points_per_element)
	Draw_Mesh_Point(p->VSUP[i]->Num, X2[i], Y2[i], Z2[i], 
			p->VSUP[i]->Degree, p->VSUP[i]->Visible);
    }
  }

  if(CTX.mesh.use_cut_plane && CTX.mesh.cut_plane_as_surface && 
     (edges || faces) && !(CTX.mesh.volumes_edges || CTX.mesh.volumes_faces) &&
     theVolume && theVolume->TriVertexArray && theVolume->QuadVertexArray){
    if(theVolume->TriVertexArray->fill){
      for(int i = 0; i < 4; i++){
	int a = trifaces_pyramid[i][0];
	int b = trifaces_pyramid[i][1];
	int c = trifaces_pyramid[i][2];
	double n[3];
	normal3points(X[a], Y[a], Z[a], X[b], Y[b], Z[b], X[c], Y[c], Z[c], n);
	theVolume->TriVertexArray->add(X[a], Y[a], Z[a], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->add(X[b], Y[b], Z[b], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->add(X[c], Y[c], Z[c], n[0], n[1], n[2], col);
	theVolume->TriVertexArray->num++;
      }
    }
    if(theVolume->QuadVertexArray->fill){
      int a = quadfaces_pyramid[0][0];
      int b = quadfaces_pyramid[0][1];
      int c = quadfaces_pyramid[0][2];
      int d = quadfaces_pyramid[0][3];
      double n[3];
      normal3points(X[a], Y[a], Z[a], X[b], Y[b], Z[b], X[c], Y[c], Z[c], n);
      theVolume->QuadVertexArray->add(X[a], Y[a], Z[a], n[0], n[1], n[2], col);
      theVolume->QuadVertexArray->add(X[b], Y[b], Z[b], n[0], n[1], n[2], col);
      theVolume->QuadVertexArray->add(X[c], Y[c], Z[c], n[0], n[1], n[2], col);
      theVolume->QuadVertexArray->add(X[d], Y[d], Z[d], n[0], n[1], n[2], col);
      theVolume->QuadVertexArray->num++;
    }
  }    
  else{
    if(edges){
      if(CTX.mesh.surfaces_faces || faces)
	glColor4ubv((GLubyte *) & CTX.color.mesh.line);
      else
	glColor4ubv((GLubyte *) & col);
      glBegin(GL_LINES);
      for(int i = 0; i < 8; i++){
	int j = edges_pyramid[i][0];
	int k = edges_pyramid[i][1];
	glVertex3d(X[j], Y[j], Z[j]);
	if(p->VSUP){
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	  glVertex3d(X2[i], Y2[i], Z2[i]);
	}
	glVertex3d(X[k], Y[k], Z[k]);
      }
      glEnd();
    }

    if(faces){
      glColor4ubv((GLubyte *) & col);
      if(CTX.mesh.light) glEnable(GL_LIGHTING);
      if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
      if(!p->VSUP){
	glBegin(GL_QUADS);
	_quadFace(X, Y, Z, 0, 3, 2, 1);
	glEnd();
	glBegin(GL_TRIANGLES);
	_triFace(X[0], Y[0], Z[0], X[1], Y[1], Z[1], X[4], Y[4], Z[4]);
	_triFace(X[3], Y[3], Z[3], X[0], Y[0], Z[0], X[4], Y[4], Z[4]);
	_triFace(X[1], Y[1], Z[1], X[2], Y[2], Z[2], X[4], Y[4], Z[4]);
	_triFace(X[2], Y[2], Z[2], X[3], Y[3], Z[3], X[4], Y[4], Z[4]);
	glEnd();
      }
      else{
	glBegin(GL_TRIANGLES);
	_quadFace2(X, Y, Z, X2, Y2, Z2, 0, 3, 2, 1, 1, 5, 3, 0, 8);
	_triFace2(X, Y, Z, X2, Y2, Z2, 0, 1, 4, 0, 4, 2);
	_triFace2(X, Y, Z, X2, Y2, Z2, 3, 0, 4, 1, 2, 7);
	_triFace2(X, Y, Z, X2, Y2, Z2, 1, 2, 4, 3, 6, 4);
	_triFace2(X, Y, Z, X2, Y2, Z2, 2, 3, 4, 5, 7, 6);
	glEnd();
      }
      glDisable(GL_POLYGON_OFFSET_FILL);
      glDisable(GL_LIGHTING);
    }
  }

  if(CTX.mesh.volumes_num) {
    if(CTX.mesh.surfaces_faces || faces)
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    else
      glColor4ubv((GLubyte *) & col);
    sprintf(Num, "%d", p->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }
}
