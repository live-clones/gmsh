// $Id: Draw.cpp,v 1.54 2004-05-28 21:06:11 geuzaine Exp $
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
  if(CTX.alpha) {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
  }
  glPolygonOffset(1.0, 1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
  for(int i = 0; i < 6; i++)
    if(CTX.clip[i])
      glEnable((GLenum) (GL_CLIP_PLANE0 + i));

  glPushMatrix();
  Draw_Mesh(&M);
  glPopMatrix();
}

void Draw2d(void)
{
  glDisable(GL_DEPTH_TEST);
  for(int i = 0; i < 6; i++)
    glDisable((GLenum) (GL_CLIP_PLANE0 + i));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // to draw directly in screen coords
  glOrtho((double)CTX.viewport[0],
          (double)CTX.viewport[2],
          (double)CTX.viewport[1], (double)CTX.viewport[3], -1., 1.);
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
    double clip = maxz * CTX.s[2] * 10;
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
  for(int i = 0; i < 6; i++) {
    if(CTX.light[i]) {
      GLfloat tmp[4];
      for(int j = 0; j < 4; j++) 
	tmp[j] = (GLfloat)CTX.light_position[i][j];
      glLightfv((GLenum) (GL_LIGHT0 + i), GL_POSITION, tmp);
      glEnable((GLenum) (GL_LIGHT0 + i));
    }
  }
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 40.);
  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glShadeModel(GL_SMOOTH);
  float specular[4] = {CTX.shine, CTX.shine, CTX.shine, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
  glEnable(GL_RESCALE_NORMAL);
  glEnable(GL_COLOR_MATERIAL);
  // disable lighting by default (we enable it for each particular
  // case in the drawing routines)
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
  glMultMatrixf(&(CTX.rot[0][0]));

  if(CTX.rotation_center_cg)
    glTranslated(-CTX.cg[0], -CTX.cg[1], -CTX.cg[2]);
  else
    glTranslated(-CTX.rotation_center[0],
		 -CTX.rotation_center[1],
		 -CTX.rotation_center[2]);
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
  GLdouble xscale1, yscale1;

  xscale1 = CTX.s[0];
  yscale1 = CTX.s[1];
  set_s(0, CTX.s[0] * (CTX.vxmax - CTX.vxmin) / (X2 - X1));
  set_s(1, CTX.s[1] * (CTX.vymax - CTX.vymin) / (Y1 - Y2));
  set_s(2, 0.5 * (CTX.s[0] + CTX.s[1]));
  set_t(0,
        CTX.t[0] * (xscale1 / CTX.s[0]) - ((Xc1 + Xc2) / 2.) * (1. -
                                                                (xscale1 /
                                                                 CTX.s[0])));
  set_t(1,
        CTX.t[1] * (yscale1 / CTX.s[1]) - ((Yc1 + Yc2) / 2.) * (1. -
                                                                (yscale1 /
                                                                 CTX.s[1])));
  Draw();
}
