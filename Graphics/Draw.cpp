// $Id: Draw.cpp,v 1.70 2004-12-31 21:12:40 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

void Draw3d(void)
{
  // offset = factor*DZ+r*units, where DZ is a measurement of the
  // change in depth relative to the screen area of the polygon, and r
  // is the smallest value that is guaranteed to produce a resolvable
  // offset for a given implementation:
  glPolygonOffset(CTX.polygon_offset_factor, CTX.polygon_offset_units);

  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);

  InitRenderModel();

  glPushMatrix();
  Draw_Mesh(&M);
  glPopMatrix();
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
  glTranslated(0.0, 0.0, CTX.clip_factor ? 1./CTX.clip_factor : 0.);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  Draw_Graph2D();
  Draw_Text2D();
  Draw_OnScreenMessages();
  if(CTX.post.draw && CTX.post.scales)
    Draw_Scales();
  if(CTX.small_axes)
    Draw_SmallAxes();
  glPopMatrix();
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

// Ortho

void Orthogonalize(int x, int y)
{
  double Va, Wa;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if(CTX.render_mode == GMSH_SELECT)
    gluPickMatrix((GLdouble) x,
                  (GLdouble) (CTX.viewport[3] - y),
                  5.0, 5.0, (GLint *) CTX.viewport);

  Va = (GLdouble) (CTX.viewport[3] - CTX.viewport[1]) /
    (GLdouble) (CTX.viewport[2] - CTX.viewport[0]);

  Wa = (CTX.max[1] - CTX.min[1]) / (CTX.max[0] - CTX.min[0]);

  if(Va > Wa) {
    CTX.vxmin = CTX.min[0];
    CTX.vxmax = CTX.max[0];
    CTX.vymin =
      0.5 * (CTX.min[1] + CTX.max[1] - Va * (CTX.max[0] - CTX.min[0]));
    CTX.vymax =
      0.5 * (CTX.min[1] + CTX.max[1] + Va * (CTX.max[0] - CTX.min[0]));
  }
  else {
    CTX.vxmin =
      0.5 * (CTX.min[0] + CTX.max[0] - (CTX.max[1] - CTX.min[1]) / Va);
    CTX.vxmax =
      0.5 * (CTX.min[0] + CTX.max[0] + (CTX.max[1] - CTX.min[1]) / Va);
    CTX.vymin = CTX.min[1];
    CTX.vymax = CTX.max[1];
  }
  CTX.vxmin -= (CTX.vxmax - CTX.vxmin) / 3.;
  CTX.vxmax += 0.25 * (CTX.vxmax - CTX.vxmin);
  CTX.vymin -= (CTX.vymax - CTX.vymin) / 3.;
  CTX.vymax += 0.25 * (CTX.vymax - CTX.vymin);

  CTX.pixel_equiv_x =
    (CTX.vxmax - CTX.vxmin) / (CTX.viewport[2] - CTX.viewport[0]);
  CTX.pixel_equiv_y =
    (CTX.vymax - CTX.vymin) / (CTX.viewport[3] - CTX.viewport[1]);

  // We should have a look at how the scaling is done in "real" opengl
  // applications (I guess they normalize the scene to fit in a 1x1x1
  // box or something...). Here, we set up a large box around the
  // object, so that if we zoom a lot the resolution of the depth
  // buffer might become insufficient (at least with the "software"
  // Mesa on Linux; with hardware acceleration or on Windows
  // everyhting seems to be fine).
  if(CTX.ortho) {
    double maxz = MAX(fabs(CTX.min[2]), fabs(CTX.max[2]));
    if(maxz < CTX.lc) maxz = CTX.lc;
    double clip = maxz * CTX.s[2] * CTX.clip_factor;
    glOrtho(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax, -clip, clip);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  }
  else {
    glFrustum(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax, CTX.lc,
              100 * CTX.lc);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -10 * CTX.lc);
    glScaled(10., 10., 10.);
  }

}

// Init

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
  
  CTX.buildRotmatrix();
  glMultMatrixd(CTX.rot);

  if(CTX.rotation_center_cg)
    glTranslated(-CTX.cg[0], -CTX.cg[1], -CTX.cg[2]);
  else
    glTranslated(-CTX.rotation_center[0],
		 -CTX.rotation_center[1],
		 -CTX.rotation_center[2]);

  // store the modelview and projection matrices
  glGetDoublev(GL_MODELVIEW_MATRIX, CTX.mod);
  glGetDoublev(GL_PROJECTION_MATRIX, CTX.proj);
}

// Entity selection

void Process_SelectionBuffer(int x, int y, int *n, GLuint * ii, GLuint * jj)
{
  GLuint selectBuf[SELECTION_BUFFER_SIZE];

  glSelectBuffer(SELECTION_BUFFER_SIZE, selectBuf);

  glRenderMode(GL_SELECT);
  CTX.render_mode = GMSH_SELECT;

  glInitNames();
  glPushName(0);

  glPushMatrix();
  Orthogonalize(x, y);
  Draw_Mesh(&M);
  glPopMatrix();

  GLint hits = glRenderMode(GL_RENDER);
  CTX.render_mode = GMSH_RENDER;

  if(hits < 0)
    return;     // Selection Buffer Overflow

  GLint *ptr = (GLint *) selectBuf;

  for(int i = 0; i < hits; i++) {
    GLint names = *ptr;
    ptr++;
    ptr++;
    ptr++;
    for(int j = 0; j < names; j++) {
      if(j == 0)
        ii[i] = *ptr;
      else if(j == 1)
        jj[i] = *ptr;
      ptr++;
    }
  }
  *n = hits;
}

void Filter_SelectionBuffer(int n, GLuint * typ, GLuint * ient,
                            Vertex ** thev, Curve ** thec, Surface ** thes,
                            Mesh * m)
{
  GLuint typmin = 4;

  for(int i = 0; i < n; i++) {
    if(typ[i] < typmin)
      typmin = typ[i];
  }

  for(int i = 0; i < n; i++) {
    if(typ[i] == typmin) {
      switch (typ[i]) {
      case 0:
	*thev = FindPoint(ient[i], m);
        break;
      case 1:
	*thec = FindCurve(ient[i], m);
        break;
      case 2:
	*thes = FindSurface(ient[i], m);
        break;
      }
    }
  }
}

// FIXME: this is notoriously wrong :-)

void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
            GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2)
{
  GLdouble xscale1 = CTX.s[0];
  GLdouble yscale1 = CTX.s[1];
  set_s(0, CTX.s[0] * (CTX.vxmax - CTX.vxmin) / (X2 - X1));
  set_s(1, CTX.s[1] * (CTX.vymax - CTX.vymin) / (Y1 - Y2));
  set_s(2, MIN(CTX.s[0], CTX.s[1])); // bof...
  set_t(0, CTX.t[0] * (xscale1 / CTX.s[0]) - 
	((Xc1 + Xc2) / 2.) * (1. - (xscale1 / CTX.s[0])));
  set_t(1, CTX.t[1] * (yscale1 / CTX.s[1]) - 
	((Yc1 + Yc2) / 2.) * (1. - (yscale1 / CTX.s[1])));
  InitPosition();
  Draw();
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
  
  if(!gluUnProject(x, y, 0.0, CTX.mod, CTX.proj, viewport, &x0, &y0, &z0))
    Msg(WARNING, "unproject1 failed");
  if(!gluUnProject(x, y, 1.0, CTX.mod, CTX.proj, viewport, &x1, &y1, &z1))
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
