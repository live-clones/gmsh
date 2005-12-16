// $Id: Draw.cpp,v 1.82 2005-12-16 19:17:34 geuzaine Exp $
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
#include "Numeric.h"

extern Context_T CTX;
extern Mesh M;

// Global Draw functions

int NeedPolygonOffset()
{
  if(M.status == 2 &&
     (CTX.mesh.surfaces_edges || CTX.geom.lines || CTX.geom.surfaces))
    return 1;
  if(M.status == 3 && 
     (CTX.mesh.surfaces_edges || CTX.mesh.volumes_edges))
    return 1;
  for(int i = 0; i < List_Nbr(CTX.post.list); i++){
    Post_View *v = *(Post_View**)List_Pointer(CTX.post.list, i);
    if(v->Visible){
      if(v->ShowElement)
	return 1;
      if((v->NbST || v->NbSQ) && (v->Axes || v->IntervalsType == DRAW_POST_ISO))
	return 1;
    }
  }
  return 0;
}

void Draw3d(void)
{
  // We should only enable the polygon offset when there is a mix of
  // lines and polygons to be drawn; enabling it all the time can lead
  // to very small but annoying artifacts in the picture. Since there
  // are so many ways in Gmsh to combine polygons and lines
  // (geometries + meshes + views...), we do our best here to
  // automatically detect if we should enable it. Note: the formula
  // for the offset is "offset = factor*DZ+r*units", where DZ is a
  // measurement of the change in depth relative to the screen area of
  // the polygon, and r is the smallest value that is guaranteed to
  // produce a resolvable offset for a given implementation.
  glPolygonOffset(CTX.polygon_offset_factor, CTX.polygon_offset_units);
  if(CTX.polygon_offset_factor || CTX.polygon_offset_units)
    CTX.polygon_offset = CTX.polygon_offset_always ? 1 : NeedPolygonOffset();
  else
    CTX.polygon_offset = 0;

  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);

  InitProjection(0, 0);
  InitPosition();
  InitRenderModel();

  Draw_Mesh(&M);
}

void Draw2d(void)
{
  glDisable(GL_DEPTH_TEST);
  for(int i = 0; i < 6; i++)
    glDisable((GLenum)(GL_CLIP_PLANE0 + i));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho((double)CTX.viewport[0], (double)CTX.viewport[2],
          (double)CTX.viewport[1], (double)CTX.viewport[3], -1., 1.);
  // hack to make the 2D primitives appear "in front" in GL2PS
  glTranslated(0., 0., CTX.clip_factor > 1. ? 1./CTX.clip_factor : CTX.clip_factor);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  Draw_Graph2D();
  Draw_Text2D();
  Draw_OnScreenMessages();
  if(CTX.post.draw)
    Draw_Scales();
  if(CTX.small_axes)
    Draw_SmallAxes();
}

void DrawPlugin(void (*draw)(void))
{
  CTX.post.plugin_draw_function = draw;
  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }
  if(!CTX.batch) 
    Draw();
  // this is reset in each plugin run/cancel callback:
  // CTX.post.plugin_draw_function = NULL;
  CTX.draw_bbox = old;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
}

void ClearOpengl(void)
{
  glClearColor(UNPACK_RED(CTX.color.bg) / 255.,
               UNPACK_GREEN(CTX.color.bg) / 255.,
               UNPACK_BLUE(CTX.color.bg) / 255., 0.);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

// Init

void InitProjection(int x, int y)
{
  double Va = 
    (GLdouble) (CTX.viewport[3] - CTX.viewport[1]) /
    (GLdouble) (CTX.viewport[2] - CTX.viewport[0]);
  double Wa = (CTX.max[1] - CTX.min[1]) / (CTX.max[0] - CTX.min[0]);

  // compute the viewport in World coordinates (with margins)
  if(Va > Wa) {
    CTX.vxmin = CTX.min[0];
    CTX.vxmax = CTX.max[0];
    CTX.vymin = 0.5 * (CTX.min[1] + CTX.max[1] - Va * (CTX.max[0] - CTX.min[0]));
    CTX.vymax = 0.5 * (CTX.min[1] + CTX.max[1] + Va * (CTX.max[0] - CTX.min[0]));
  }
  else {
    CTX.vxmin = 0.5 * (CTX.min[0] + CTX.max[0] - (CTX.max[1] - CTX.min[1]) / Va);
    CTX.vxmax = 0.5 * (CTX.min[0] + CTX.max[0] + (CTX.max[1] - CTX.min[1]) / Va);
    CTX.vymin = CTX.min[1];
    CTX.vymax = CTX.max[1];
  }
  CTX.vxmin -= (CTX.vxmax - CTX.vxmin) / 3.;
  CTX.vxmax += 0.25 * (CTX.vxmax - CTX.vxmin);
  CTX.vymin -= (CTX.vymax - CTX.vymin) / 3.;
  CTX.vymax += 0.25 * (CTX.vymax - CTX.vymin);

  // store what one pixel represents in world coordinates
  CTX.pixel_equiv_x = (CTX.vxmax - CTX.vxmin) / (CTX.viewport[2] - CTX.viewport[0]);
  CTX.pixel_equiv_y = (CTX.vymax - CTX.vymin) / (CTX.viewport[3] - CTX.viewport[1]);

  // setup ortho or perspective projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if(CTX.render_mode == GMSH_SELECT)
    gluPickMatrix((GLdouble) x, (GLdouble) (CTX.viewport[3] - y),
                  5.0, 5.0, (GLint *) CTX.viewport);

  double gradient_zdist, gradient_xyfact;
  if(CTX.ortho) {
    // setting up the near and far clipping planes so that the box is
    // large enough to manipulate the model and zoom, but not too big
    // (the z-buffer resolution, e.g., on software Mesa can become
    // insufficient)
    double maxz = MAX(fabs(CTX.min[2]), fabs(CTX.max[2]));
    if(maxz < CTX.lc) maxz = CTX.lc;
    double clip = maxz * CTX.s[2] * CTX.clip_factor;
    glOrtho(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax, -clip, clip);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gradient_zdist = 0.99 * clip;
    gradient_xyfact = 1.;
  }
  else {
    double near = 0.75 * CTX.clip_factor * CTX.lc;
    double far = 75. * CTX.clip_factor * CTX.lc;
    // recenter the model such that the perspective is always at the
    // center of the screen. FIXME: this screws up the zoom, so let's
    // leave it out for now
    //double w = (CTX.max[0] - CTX.min[0]) / 2.;
    //double h = (CTX.max[1] - CTX.min[1]) / 2.;
    //CTX.vxmin -= w;
    //CTX.vxmax -= w;
    //CTX.vymin -= h;
    //CTX.vymax -= h;
    double w = 0.;
    double h = 0.;
    glFrustum(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax, near, far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(-5 * w, -5 * h, -5 * near);
    glScaled(5., 5., 5.);
    gradient_zdist = 0.99 * far;
    gradient_xyfact = far / near;
  }

  // draw background gradient
  if(CTX.render_mode != GMSH_SELECT && CTX.bg_gradient){
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0., 0., -gradient_zdist);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_QUADS);
    if(CTX.bg_gradient == 1){
      glColor4ubv((GLubyte *) & CTX.color.bg);
      glVertex2d(gradient_xyfact * CTX.vxmin, gradient_xyfact * CTX.vymin);
      glVertex2d(gradient_xyfact * CTX.vxmax, gradient_xyfact * CTX.vymin);
      glColor4ubv((GLubyte *) & CTX.color.bg_grad);
      glVertex2d(gradient_xyfact * CTX.vxmax, gradient_xyfact * CTX.vymax);
      glVertex2d(gradient_xyfact * CTX.vxmin, gradient_xyfact * CTX.vymax);
    }
    else{
      glColor4ubv((GLubyte *) & CTX.color.bg);
      glVertex2d(gradient_xyfact * CTX.vxmax, gradient_xyfact * CTX.vymin);
      glVertex2d(gradient_xyfact * CTX.vxmax, gradient_xyfact * CTX.vymax);
      glColor4ubv((GLubyte *) & CTX.color.bg_grad);
      glVertex2d(gradient_xyfact * CTX.vxmin, gradient_xyfact * CTX.vymax);
      glVertex2d(gradient_xyfact * CTX.vxmin, gradient_xyfact * CTX.vymin);
    }
    glEnd();
    glPopMatrix();
  }
}

void InitRenderModel(void)
{
  GLfloat r, g, b;

  for(int i = 0; i < 6; i++) {
    if(CTX.light[i]) {
      GLfloat position[4] = {(GLfloat)CTX.light_position[i][0],
			     (GLfloat)CTX.light_position[i][1],
			     (GLfloat)CTX.light_position[i][2],
			     (GLfloat)CTX.light_position[i][3]};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_POSITION, position);

      r = UNPACK_RED(CTX.color.ambient_light[i])/255.;
      g = UNPACK_GREEN(CTX.color.ambient_light[i])/255.;
      b = UNPACK_BLUE(CTX.color.ambient_light[i])/255.;
      GLfloat ambient[4] = {r, g, b, 1.0};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_AMBIENT, ambient);

      r = UNPACK_RED(CTX.color.diffuse_light[i])/255.;
      g = UNPACK_GREEN(CTX.color.diffuse_light[i])/255.;
      b = UNPACK_BLUE(CTX.color.diffuse_light[i])/255.;
      GLfloat diffuse[4] = {r, g, b, 1.0};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_DIFFUSE, diffuse);

      r = UNPACK_RED(CTX.color.specular_light[i])/255.;
      g = UNPACK_GREEN(CTX.color.specular_light[i])/255.;
      b = UNPACK_BLUE(CTX.color.specular_light[i])/255.;
      GLfloat specular[4] = {r, g, b, 1.0};
      glLightfv((GLenum)(GL_LIGHT0 + i), GL_SPECULAR, specular);

      glEnable((GLenum)(GL_LIGHT0 + i));
    }
    else{
      glDisable((GLenum)(GL_LIGHT0 + i));
    }
  }

  // ambient and diffuse material colors track glColor automatically
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  // "white"-only specular material reflection color
  GLfloat spec[4] = {CTX.shine, CTX.shine, CTX.shine, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
  // specular exponent in [0,128] (larger means more "focused"
  // reflection)
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, CTX.shine_exponent);

  glShadeModel(GL_SMOOTH);
  // Normalize the normals automatically. We could use the more
  // efficient glEnable(GL_RESCALE_NORMAL) instead (since we initially
  // specify unit normals), but GL_RESCALE_NORMAL does only work with
  // isotropic scalings (and we allow anistotropic scalings in
  // myZoom). Note that GL_RESCALE_NORMAL is only available in
  // GL_VERSION_1_2.
  glEnable(GL_NORMALIZE);

  // lighting is enabled/disabled for each particular primitive later
  glDisable(GL_LIGHTING);
}

void InitPosition(void)
{
  glScaled(CTX.s[0], CTX.s[1], CTX.s[2]);
  glTranslated(CTX.t[0], CTX.t[1], CTX.t[2]);

  if(CTX.rotation_center_cg)
    glTranslated(CTX.cg[0], CTX.cg[1], CTX.cg[2]);
  else
    glTranslated(CTX.rotation_center[0],
		 CTX.rotation_center[1],
		 CTX.rotation_center[2]);
  
  CTX.buildRotationMatrix();
  glMultMatrixd(CTX.rot);

  if(CTX.rotation_center_cg)
    glTranslated(-CTX.cg[0], -CTX.cg[1], -CTX.cg[2]);
  else
    glTranslated(-CTX.rotation_center[0],
		 -CTX.rotation_center[1],
		 -CTX.rotation_center[2]);

  // store the projection and modelview matrices at this precise
  // moment (so that we can use them at any later time, even if the
  // context has changed, i.e., even if we are out of Draw())
  glGetDoublev(GL_PROJECTION_MATRIX, CTX.proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, CTX.model);
}

// Entity selection

void Process_SelectionBuffer(int x, int y, int *n, hit *hits)
{
  GLuint selectBuf[SELECTION_BUFFER_SIZE];

  glSelectBuffer(SELECTION_BUFFER_SIZE, selectBuf);

  glRenderMode(GL_SELECT);
  CTX.render_mode = GMSH_SELECT;

  glInitNames();
  glPushName(0); // init stack with 0 (=type=point). This will be
		 // overwritten with the actual entity type everytime
		 // an entity is drawn

  glPushMatrix();
  InitProjection(x, y);
  InitPosition();
  Draw_Mesh(&M);
  glPopMatrix();

  GLint numhits = glRenderMode(GL_RENDER);
  CTX.render_mode = GMSH_RENDER;

  if(numhits < 0){
    // selection buffer overflow
    *n = 0;
    return;
  }

  GLint *ptr = (GLint *) selectBuf;

  for(int i = 0; i < numhits; i++) {
    GLint names = *ptr; // number of names in the name stack (should
			// always be 2 in Gmsh: the first is the type
			// of the entity, the second the entity
			// number)
    ptr++;
    GLint mindepth = *ptr;
    ptr++;
    GLint maxdepth = *ptr;
    ptr++;
    hits[i].depth = (mindepth+maxdepth)/2;
    for(int j = 0; j < names; j++) {
      if(j == 0)
        hits[i].type = *ptr; // type of entity (0, 1, 2, ... for
			     // point, line, surf, ...)
      else if(j == 1)
        hits[i].ient = *ptr; // num of entity
      ptr++;
    }
  }
  *n = numhits;
}

int fcmp_hit_depth(const void *a, const void *b)
{
  return ((hit*)a)->depth - ((hit*)b)->depth;
}

int Filter_SelectionBuffer(int type, int n, hit *hits, 
			   Vertex **thev, Curve **thec, Surface **thes, Mesh *m)
{
  // If type == ENT_NONE, return the closest entity of "lowest
  // dimension" (point < line < surface < volume). Otherwise, return
  // the closest entity of type "type"

  unsigned int typmin = 4;

  for(int i = 0; i < n; i++) {
    if(hits[i].type < typmin)
      typmin = hits[i].type;
  }

  // sort hits to get closest entities first
  qsort(hits, n, sizeof(hit), fcmp_hit_depth);

  for(int i = 0; i < n; i++) {
    if((type == ENT_NONE && hits[i].type == typmin) ||
       (type == ENT_POINT && hits[i].type == 0) ||
       (type == ENT_LINE && hits[i].type == 1) ||
       (type == ENT_SURFACE && hits[i].type == 2)){
      switch (hits[i].type) {
      case 0:
	*thev = FindPoint(hits[i].ient, m);
        return 1;
      case 1:
	*thec = FindCurve(hits[i].ient, m);
	return 1;
      case 2:
	*thes = FindSurface(hits[i].ient, m);
	return 1;
      }
    }
  }
  
  return 0;
}

// Takes a cursor position in window coordinates and returns the line
// (given by a point and a unit direction vector), in real space, that
// corresponds to that cursor position

void unproject(double x, double y, double p[3], double d[3])
{
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  y = viewport[3]-y;

  GLdouble x0, y0, z0, x1, y1, z1;

  // we use CTX.model and CTX.proj instead of directly getGetDouble'ing
  // the matrices since unproject can be called in or after Draw2D
  
  if(!gluUnProject(x, y, 0.0, CTX.model, CTX.proj, viewport, &x0, &y0, &z0))
    Msg(WARNING, "unproject1 failed");
  if(!gluUnProject(x, y, 1.0, CTX.model, CTX.proj, viewport, &x1, &y1, &z1))
    Msg(WARNING, "unproject2 failed");
  
  p[0] = x0;
  p[1] = y0;
  p[2] = z0;
  d[0] = x1-x0;
  d[1] = y1-y0;
  d[2] = z1-z0;
  double len = sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
  d[0] /= len;
  d[1] /= len;
  d[2] /= len;
}

void Viewport2World(double win[3], double xyz[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluUnProject(win[0], win[1], win[2], model, proj, viewport, &xyz[0], &xyz[1], &xyz[2]);
}

void World2Viewport(double xyz[3], double win[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluProject(xyz[0], xyz[1], xyz[2], model, proj, viewport, &win[0], &win[1], &win[2]);
}
