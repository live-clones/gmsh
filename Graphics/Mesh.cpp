// $Id: Mesh.cpp,v 1.60 2003-06-13 21:14:20 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "MinMax.h"
#include "gl2ps.h"
#include "Verif.h"
#include "Numeric.h"

extern Mesh *THEM;
extern Context_T CTX;

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

static int iColor;
static DrawingColor theColor;

void ColorSwitch(int i)
{
  glColor4ubv((GLubyte *) & CTX.color.mesh.carousel[i % 10]);
}

static int DrawVertexSupp;

void Draw_Mesh(Mesh * M)
{
  int i;

  if(!CTX.moving_light)
    InitRenderModel();

  if(CTX.mesh.shade)
    InitShading();
  else
    InitNoShading();
  InitPosition();

  if(CTX.moving_light)
    InitRenderModel();

  for(i = 0; i < 6; i++)
    if(CTX.clip[i])
      glClipPlane((GLenum) (GL_CLIP_PLANE0 + i), CTX.clip_plane[i]);

  glPointSize(CTX.mesh.point_size);
  gl2psPointSize(CTX.mesh.point_size * CTX.print.eps_point_size_factor);

  glLineWidth(CTX.mesh.line_width);
  gl2psLineWidth(CTX.mesh.line_width * CTX.print.eps_line_width_factor);

  if(CTX.mesh.hidden)
    glEnable(GL_POLYGON_OFFSET_FILL);

  // draw the bbox of the mesh in fast redraw mode if there is no geometry
  if(!CTX.mesh.draw && Tree_Nbr(M->Vertices) && !Tree_Nbr(M->Points)) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
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
  }

  iColor = 0;

  if(CTX.mesh.draw && CTX.render_mode != GMSH_SELECT) {

    static int first = 1, listnum;

    if(CTX.mesh.display_lists && CTX.mesh.changed) {
      if(first)
        listnum = glGenLists(1);
      first = 0;
      //printf("new mesh display list\n");
      glNewList(listnum, GL_COMPILE_AND_EXECUTE);
    }

    if(!CTX.mesh.display_lists
       || (CTX.mesh.display_lists && CTX.mesh.changed)) {

      //printf("normal mesh drawing\n");

      if(M->status >= 3 && (CTX.mesh.volumes || CTX.mesh.volumes_num)) {
        Tree_Action(M->Volumes, Draw_Mesh_Volumes);
      }

      if(M->status >= 2 && (CTX.mesh.surfaces || CTX.mesh.surfaces_num)) {
        Tree_Action(M->Surfaces, Draw_Mesh_Surfaces);
        if(CTX.mesh.oldxtrude)  //old extrusion algo
          Tree_Action(M->Volumes, Draw_Mesh_Extruded_Surfaces);
      }

      if(M->status >= 1 && (CTX.mesh.lines || CTX.mesh.lines_num)) {
        Tree_Action(M->Curves, Draw_Mesh_Curves);
        DrawVertexSupp = 1;
        Tree_Action(M->VertexEdges, Draw_Mesh_Points);
      }

      if(M->status >= 0 && (CTX.mesh.points || CTX.mesh.points_num)) {
        DrawVertexSupp = 0;
        Tree_Action(M->Vertices, Draw_Mesh_Points);
      }

    }
    else {

      //printf("calling mesh display list\n");
      glCallList(listnum);

    }

    if(CTX.mesh.display_lists) {
      if(CTX.mesh.changed) {
        glEndList();
        CTX.mesh.changed = 0;
      }
    }

  }

  if(M->status >= 0) {
    if(!CTX.geom.shade)
      InitNoShading();
    Draw_Geom(M);
  }

  if(CTX.mesh.hidden)
    glDisable(GL_POLYGON_OFFSET_FILL);

  if(CTX.render_mode != GMSH_SELECT) {
    if(CTX.axes)
      Draw_Axes(CTX.lc_middle / 4.);
    Draw_Post();        // les init de shading se font par view
  }
}

void Draw_Mesh_Volumes(void *a, void *b)
{
  Volume *v;
  v = *(Volume **) a;
  iColor++;
  theColor = v->Color;
  // FIXME: this is the correct method, but will only work when a
  // coherent datastruct exists for volumes
  // if(!(v->Visible & VIS_MESH)) return;
  Tree_Action(v->Simplexes, Draw_Simplex_Volume);
  Tree_Action(v->Hexahedra, Draw_Hexahedron_Volume);
  Tree_Action(v->Prisms, Draw_Prism_Volume);
  Tree_Action(v->Pyramids, Draw_Pyramid_Volume);
}

int Test_Simple_Surface_Draw()
{
  if(CTX.mesh.use_cut_plane ||
     CTX.mesh.explode != 1.0 ||
     CTX.mesh.dual || CTX.mesh.surfaces_num || CTX.mesh.normals)
    return 0;
  //printf("simple simplex surface drawing\n");
  return 1;
}

void Draw_Mesh_Surfaces(void *a, void *b)
{
  Surface *s;
  s = *(Surface **) a;
  iColor++;
  theColor = s->Color;
  if(!(s->Visible & VIS_MESH))
    return;
  if(!Test_Simple_Surface_Draw())
    Tree_Action(s->Simplexes, Draw_Simplex_Surface);
  else
    Tree_Action(s->Simplexes, Draw_Simplex_Surface_Simple);
}

void Draw_Mesh_Extruded_Surfaces(void *a, void *b)
{
  Volume *v;
  v = *(Volume **) a;
  if(!(v->Visible & VIS_MESH))
    return;
  if(!Test_Simple_Surface_Draw())
    Tree_Action(v->Simp_Surf, Draw_Simplex_Surface);
  else
    Tree_Action(v->Simp_Surf, Draw_Simplex_Surface_Simple);
}

void Draw_Mesh_Curves(void *a, void *b)
{
  Curve *c;
  c = *(Curve **) a;
  if(c->Num < 0)
    return;
  iColor++;
  theColor = c->Color;
  if(!(c->Visible & VIS_MESH))
    return;
  Tree_Action(c->Simplexes, Draw_Simplex_Curves);
}

void Draw_Mesh_Points(void *a, void *b)
{
  Vertex *v;
  char Num[100];

  v = *(Vertex **) a;

  if(!(v->Visible & VIS_MESH))
    return;

  if(CTX.mesh.use_cut_plane) {
    if(CTX.mesh.evalCutPlane(v->Pos.X, v->Pos.Y, v->Pos.Z) < 0)
      return;
  }

  if(CTX.render_mode == GMSH_SELECT) {
    glLoadName(0);
    glPushName(v->Num);
  }

  if(DrawVertexSupp)
    glColor4ubv((GLubyte *) & CTX.color.mesh.vertex_supp);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.vertex);

  if(CTX.mesh.points) {
    if(CTX.mesh.point_type) {
      Draw_Sphere(CTX.mesh.point_size, v->Pos.X, v->Pos.Y, v->Pos.Z);
    }
    else {
      glBegin(GL_POINTS);
      glVertex3d(v->Pos.X, v->Pos.Y, v->Pos.Z);
      glEnd();
    }
  }

  if(CTX.mesh.points_num) {
    sprintf(Num, "%d", v->Num);
    glRasterPos3d(v->Pos.X + 3 * CTX.pixel_equiv_x / CTX.s[0],
                  v->Pos.Y + 3 * CTX.pixel_equiv_x / CTX.s[1],
                  v->Pos.Z + 3 * CTX.pixel_equiv_x / CTX.s[2]);
    Draw_String(Num);
  }

  if(CTX.render_mode == GMSH_SELECT) {
    glPopName();
  }
}

// Draw simplex

void Draw_Simplex_Volume(void *a, void *b)
{
  Simplex *s;
  char Num[100];
  int fulldraw = 0;
  double tmp, X[4], Y[4], Z[4];

  s = *(Simplex **) a;

  if(!s->V[3] || !(s->Visible & VIS_MESH))
    return;

  // FIXME: remove as soon as a coherent structure exists for volumes
  Volume *V;
  if((V = FindVolume(s->iEnt, THEM)) && !(V->Visible & VIS_MESH))
    return;

  if(CTX.mesh.gamma_sup) {
    tmp = s->GammaShapeMeasure();
    if(tmp < CTX.mesh.gamma_inf || tmp > CTX.mesh.gamma_sup)
      return;
    fulldraw = 1;
  }

  if(CTX.mesh.radius_sup) {
    if(s->Radius < CTX.mesh.radius_inf || s->Radius > CTX.mesh.radius_sup)
      return;
    fulldraw = 1;
  }


  double Xc = .25 * (s->V[0]->Pos.X + s->V[1]->Pos.X +
                     s->V[2]->Pos.X + s->V[3]->Pos.X);
  double Yc = .25 * (s->V[0]->Pos.Y + s->V[1]->Pos.Y +
                     s->V[2]->Pos.Y + s->V[3]->Pos.Y);
  double Zc = .25 * (s->V[0]->Pos.Z + s->V[1]->Pos.Z +
                     s->V[2]->Pos.Z + s->V[3]->Pos.Z);

  if(CTX.mesh.use_cut_plane) {
    if(CTX.mesh.evalCutPlane(Xc, Yc, Zc) < 0)
      return;
    fulldraw = 1;
  }

  if(CTX.mesh.color_carousel && !fulldraw)
    ColorSwitch(s->iEnt);
  else if(fulldraw)
    glColor4ubv((GLubyte *) & CTX.color.mesh.line);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.tetrahedron);

  // this is killing us!!!
  for(int i = 0; i < 4; i++) {
    X[i] = Xc + CTX.mesh.explode * (s->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (s->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (s->V[i]->Pos.Z - Zc);
  }

  if(CTX.mesh.shade)
    glDisable(GL_LIGHTING);

  if(CTX.mesh.volumes && !(fulldraw && CTX.mesh.shade)) {
    glBegin(GL_LINES);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[0], Y[0], Z[0]);

    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[0], Y[0], Z[0]);

    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[0], Y[0], Z[0]);

    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[1], Y[1], Z[1]);

    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[2], Y[2], Z[2]);

    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);

    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[3], Y[3], Z[3]);
    glEnd();
  }

  if(CTX.mesh.volumes_num) {
    sprintf(Num, "%d", s->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
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

  if(CTX.mesh.shade)
    glEnable(GL_LIGHTING);

  if(!fulldraw)
    return;

  double n[4], x1x0, y1y0, z1z0, x2x0, y2y0, z2z0;

  if(CTX.mesh.color_carousel)
    ColorSwitch(s->iEnt);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.tetrahedron);

  if(CTX.mesh.hidden) {

    if(CTX.mesh.shade) {
      x1x0 = X[2] - X[0];
      y1y0 = Y[2] - Y[0];
      z1z0 = Z[2] - Z[0];
      x2x0 = X[1] - X[0];
      y2y0 = Y[1] - Y[0];
      z2z0 = Z[1] - Z[0];
      n[0] = y1y0 * z2z0 - z1z0 * y2y0;
      n[1] = z1z0 * x2x0 - x1x0 * z2z0;
      n[2] = x1x0 * y2y0 - y1y0 * x2x0;
      glNormal3dv(n);
    }

    glBegin(GL_TRIANGLES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[1], Y[1], Z[1]);
    glEnd();

    if(CTX.mesh.shade) {
      x1x0 = X[1] - X[0];
      y1y0 = Y[1] - Y[0];
      z1z0 = Z[1] - Z[0];
      x2x0 = X[3] - X[0];
      y2y0 = Y[3] - Y[0];
      z2z0 = Z[3] - Z[0];
      n[0] = y1y0 * z2z0 - z1z0 * y2y0;
      n[1] = z1z0 * x2x0 - x1x0 * z2z0;
      n[2] = x1x0 * y2y0 - y1y0 * x2x0;
      glNormal3dv(n);
    }

    glBegin(GL_TRIANGLES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[3], Y[3], Z[3]);
    glEnd();

    if(CTX.mesh.shade) {
      x1x0 = X[3] - X[0];
      y1y0 = Y[3] - Y[0];
      z1z0 = Z[3] - Z[0];
      x2x0 = X[2] - X[0];
      y2y0 = Y[2] - Y[0];
      z2z0 = Z[2] - Z[0];
      n[0] = y1y0 * z2z0 - z1z0 * y2y0;
      n[1] = z1z0 * x2x0 - x1x0 * z2z0;
      n[2] = x1x0 * y2y0 - y1y0 * x2x0;
      glNormal3dv(n);
    }

    glBegin(GL_TRIANGLES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[2], Y[2], Z[2]);
    glEnd();

    if(CTX.mesh.shade) {
      x1x0 = X[3] - X[1];
      y1y0 = Y[3] - Y[1];
      z1z0 = Z[3] - Z[1];
      x2x0 = X[2] - X[1];
      y2y0 = Y[2] - Y[1];
      z2z0 = Z[2] - Z[1];
      n[0] = y1y0 * z2z0 - z1z0 * y2y0;
      n[1] = z1z0 * x2x0 - x1x0 * z2z0;
      n[2] = x1x0 * y2y0 - y1y0 * x2x0;
      glNormal3dv(n);
    }

    glBegin(GL_TRIANGLES);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    glEnd();

  }

}

void Draw_Simplex_Surface_Common(Simplex * s, double *pX, double *pY,
                                 double *pZ, double n[3])
{
  double x1x0, y1y0, z1z0, x2x0, y2y0, z2z0;
  int i, K, L;

  L = (s->VSUP) ? 1 : 0;
  K = (s->V[3]) ? 4 : 3;

  if(CTX.mesh.normals || CTX.mesh.shade) {
    x1x0 = s->V[1]->Pos.X - s->V[0]->Pos.X;
    y1y0 = s->V[1]->Pos.Y - s->V[0]->Pos.Y;
    z1z0 = s->V[1]->Pos.Z - s->V[0]->Pos.Z;
    x2x0 = s->V[2]->Pos.X - s->V[0]->Pos.X;
    y2y0 = s->V[2]->Pos.Y - s->V[0]->Pos.Y;
    z2z0 = s->V[2]->Pos.Z - s->V[0]->Pos.Z;
    n[0] = y1y0 * z2z0 - z1z0 * y2y0;
    n[1] = z1z0 * x2x0 - x1x0 * z2z0;
    n[2] = x1x0 * y2y0 - y1y0 * x2x0;
  }

  if(CTX.mesh.hidden && CTX.mesh.shade)
    glNormal3dv(n);

  if(CTX.mesh.surfaces && CTX.mesh.lines) {

    if(CTX.mesh.color_carousel && !(CTX.mesh.hidden || CTX.mesh.shade)) {
      if(theColor.type)
        glColor4ubv((GLubyte *) & theColor.mesh);
      else
        ColorSwitch(iColor);
    }
    else {
      glColor4ubv((GLubyte *) & CTX.color.mesh.line);
    }

    if(CTX.mesh.shade)
      glDisable(GL_LIGHTING);

    if(pX && pY && pZ) {        // using precomputed vertices
      glBegin(GL_LINE_LOOP);
      for(i = 0; i < K * (1 + L); i++) {
        glVertex3d(pX[i], pY[i], pZ[i]);
      }
      glEnd();
    }
    else {      // using the element's unmodified coordinates
      if(!L) {
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < K; i++) {
          glVertex3d(s->V[i]->Pos.X, s->V[i]->Pos.Y, s->V[i]->Pos.Z);
        }
        glEnd();
      }
      else {
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < K; i++) {
          glVertex3d(s->V[i]->Pos.X, s->V[i]->Pos.Y, s->V[i]->Pos.Z);
          glVertex3d(s->VSUP[i]->Pos.X, s->VSUP[i]->Pos.Y, s->VSUP[i]->Pos.Z);
        }
        glEnd();
      }
    }

    if(CTX.mesh.shade)
      glEnable(GL_LIGHTING);

  }

  if(CTX.mesh.color_carousel) {
    if(theColor.type)
      glColor4ubv((GLubyte *) & theColor.mesh);
    else
      ColorSwitch(iColor);
  }
  else {
    if(K == 3)
      glColor4ubv((GLubyte *) & CTX.color.mesh.triangle);
    else
      glColor4ubv((GLubyte *) & CTX.color.mesh.quadrangle);
  }

  if(CTX.mesh.surfaces && CTX.mesh.hidden) {

    if(pX && pY && pZ) {        // using precomputed vertices
      if(L) {
        glBegin(GL_POLYGON);
        for(i = 0; i < K * (1 + L); i++)
          glVertex3d(pX[i], pY[i], pZ[i]);
        glEnd();
      }
      else if(K == 4) {
        glBegin(GL_QUADS);
        glVertex3d(pX[0], pY[0], pZ[0]);
        glVertex3d(pX[1], pY[1], pZ[1]);
        glVertex3d(pX[2], pY[2], pZ[2]);
        glVertex3d(pX[3], pY[3], pZ[3]);
        glEnd();
      }
      else {
        glBegin(GL_TRIANGLES);
        glVertex3d(pX[0], pY[0], pZ[0]);
        glVertex3d(pX[1], pY[1], pZ[1]);
        glVertex3d(pX[2], pY[2], pZ[2]);
        glEnd();
      }
    }
    else {      // using the element's unmodified coordinates
      if(L) {
        glBegin(GL_POLYGON);
        for(i = 0; i < K; i++) {
          glVertex3d(s->V[i]->Pos.X, s->V[i]->Pos.Y, s->V[i]->Pos.Z);
          glVertex3d(s->VSUP[i]->Pos.X, s->VSUP[i]->Pos.Y, s->VSUP[i]->Pos.Z);
        }
        glEnd();
      }
      else if(K == 4) {
        glBegin(GL_QUADS);
        glVertex3d(s->V[0]->Pos.X, s->V[0]->Pos.Y, s->V[0]->Pos.Z);
        glVertex3d(s->V[1]->Pos.X, s->V[1]->Pos.Y, s->V[1]->Pos.Z);
        glVertex3d(s->V[2]->Pos.X, s->V[2]->Pos.Y, s->V[2]->Pos.Z);
        glVertex3d(s->V[3]->Pos.X, s->V[3]->Pos.Y, s->V[3]->Pos.Z);
        glEnd();
      }
      else {
        glBegin(GL_TRIANGLES);
        glVertex3d(s->V[0]->Pos.X, s->V[0]->Pos.Y, s->V[0]->Pos.Z);
        glVertex3d(s->V[1]->Pos.X, s->V[1]->Pos.Y, s->V[1]->Pos.Z);
        glVertex3d(s->V[2]->Pos.X, s->V[2]->Pos.Y, s->V[2]->Pos.Z);
        glEnd();
      }
    }

  }

}

void Draw_Simplex_Surface_Simple(void *a, void *b)
{
  Simplex *s;
  double n[3];

  s = *(Simplex **) a;

  if(!s->V[2] || !(s->Visible & VIS_MESH))
    return;

  Draw_Simplex_Surface_Common(s, NULL, NULL, NULL, n);
}

void Draw_Simplex_Surface(void *a, void *b)
{
  Simplex *s;
  double Xc, Yc, Zc, pX[8], pY[8], pZ[8];
  double n[3], nn;
  int i, j, K, L, k;
  char Num[256];

  s = *(Simplex **) a;

  if(!s->V[2] || !(s->Visible & VIS_MESH))
    return;

  L = (s->VSUP) ? 1 : 0;
  K = (s->V[3]) ? 4 : 3;

  if(K == 4) {
    Xc = .25 * (s->V[0]->Pos.X + s->V[1]->Pos.X +
                s->V[2]->Pos.X + s->V[3]->Pos.X);
    Yc = .25 * (s->V[0]->Pos.Y + s->V[1]->Pos.Y +
                s->V[2]->Pos.Y + s->V[3]->Pos.Y);
    Zc = .25 * (s->V[0]->Pos.Z + s->V[1]->Pos.Z +
                s->V[2]->Pos.Z + s->V[3]->Pos.Z);
  }
  else {
    Xc = (s->V[0]->Pos.X + s->V[1]->Pos.X + s->V[2]->Pos.X) / 3.;
    Yc = (s->V[0]->Pos.Y + s->V[1]->Pos.Y + s->V[2]->Pos.Y) / 3.;
    Zc = (s->V[0]->Pos.Z + s->V[1]->Pos.Z + s->V[2]->Pos.Z) / 3.;
  }

  if(CTX.mesh.use_cut_plane) {
    if(CTX.mesh.evalCutPlane(Xc, Yc, Zc) < 0)
      return;
  }

  k = 0;
  for(i = 0; i < K; i++) {
    pX[k] = Xc + CTX.mesh.explode * (s->V[i]->Pos.X - Xc);
    pY[k] = Yc + CTX.mesh.explode * (s->V[i]->Pos.Y - Yc);
    pZ[k] = Zc + CTX.mesh.explode * (s->V[i]->Pos.Z - Zc);
    k += (L + 1);
  }

  if(L) {
    k = 1;
    for(i = 0; i < K; i++) {
      pX[k] = Xc + CTX.mesh.explode * (s->VSUP[i]->Pos.X - Xc);
      pY[k] = Yc + CTX.mesh.explode * (s->VSUP[i]->Pos.Y - Yc);
      pZ[k] = Zc + CTX.mesh.explode * (s->VSUP[i]->Pos.Z - Zc);
      k += (L + 1);
    }
  }

  if(CTX.mesh.dual) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    for(i = 0; i < K; i++) {
      (!i) ? j = K - 1 : j = i - 1;
      glVertex3d(Xc, Yc, Zc);
      glVertex3d((pX[i] + pX[j]) / 2., (pY[i] + pY[j]) / 2.,
                 (pZ[i] + pZ[j]) / 2.);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  Draw_Simplex_Surface_Common(s, pX, pY, pZ, n);

  if(CTX.mesh.surfaces_num) {
    sprintf(Num, "%d", s->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }

  if(CTX.mesh.normals) {
    norme(n);
    glColor4ubv((GLubyte *) & CTX.color.mesh.normals);
    n[0] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[0];
    n[1] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[1];
    n[2] *= CTX.mesh.normals * CTX.pixel_equiv_x / CTX.s[2];
    nn = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    Draw_Vector(DRAW_POST_ARROW, 0, Xc, Yc, Zc, nn, n[0], n[1], n[2], NULL);
  }


}


void Draw_Simplex_Curves(void *a, void *b)
{
  Simplex *s;
  double Xc = 0.0, Yc = 0.0, Zc = 0.0, m[3], mm;
  char Num[100];

  s = *(Simplex **) a;

  if(!(s->Visible & VIS_MESH))
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
  }
  
  if(N == 3){
    X[2] = X[1];
    Y[2] = Y[1];
    Z[2] = Z[1];
    X[1] = Xc + CTX.mesh.explode * (s->VSUP[0]->Pos.X - Xc);
    Y[1] = Yc + CTX.mesh.explode * (s->VSUP[0]->Pos.Y - Yc);
    Z[1] = Zc + CTX.mesh.explode * (s->VSUP[0]->Pos.Z - Zc);
  }

  if(CTX.mesh.color_carousel) {
    if(theColor.type)
      glColor4ubv((GLubyte *) & theColor.mesh);
    else
      ColorSwitch(iColor);
  }
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.line);

  if(CTX.mesh.shade)
    glDisable(GL_LIGHTING);

  if(CTX.mesh.lines) {
    glBegin(GL_LINES);
    for(int i = 0; i < N; i++){
      glVertex3d(X[i], Y[i], Z[i]);
    }
    glEnd();
  }

  if(CTX.mesh.lines_num) {
    sprintf(Num, "%d", s->Num);
    glRasterPos3d(Xc + 3 * CTX.pixel_equiv_x / CTX.s[0],
                  Yc + 3 * CTX.pixel_equiv_x / CTX.s[1],
                  Zc + 3 * CTX.pixel_equiv_x / CTX.s[2]);
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
    mm = sqrt(m[0] * m[0] + m[1] * m[1] + m[2] * m[2]);
    Draw_Vector(DRAW_POST_ARROW, 0, Xc, Yc, Zc, mm, m[0], m[1], m[2], NULL);
  }

  if(CTX.mesh.shade)
    glEnable(GL_LIGHTING);

}

void Draw_Hexahedron_Volume(void *a, void *b)
{
  Hexahedron *h;
  int i;
  double Xc = 0.0, Yc = 0.0, Zc = 0.0, X[8], Y[8], Z[8];
  char Num[100];

  h = *(Hexahedron **) a;

  if(!(h->Visible & VIS_MESH))
    return;

  // FIXME: remove as soon as a coherent structure exists for volumes
  Volume *V;
  if((V = FindVolume(h->iEnt, THEM)) && !(V->Visible & VIS_MESH))
    return;

  for(i = 0; i < 8; i++) {
    Xc += h->V[i]->Pos.X;
    Yc += h->V[i]->Pos.Y;
    Zc += h->V[i]->Pos.Z;
  }
  Xc *= .125;
  Zc *= .125;
  Yc *= .125;

  if(CTX.mesh.use_cut_plane) {
    if(CTX.mesh.evalCutPlane(Xc, Yc, Zc) < 0)
      return;
  }

  if(CTX.mesh.color_carousel)
    ColorSwitch(h->iEnt);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.hexahedron);

  for(i = 0; i < 8; i++) {
    X[i] = Xc + CTX.mesh.explode * (h->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (h->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (h->V[i]->Pos.Z - Zc);
  }

  if(CTX.mesh.shade)
    glDisable(GL_LIGHTING);

  glBegin(GL_LINE_LOOP);
  glVertex3d(X[0], Y[0], Z[0]);
  glVertex3d(X[1], Y[1], Z[1]);
  glVertex3d(X[2], Y[2], Z[2]);
  glVertex3d(X[3], Y[3], Z[3]);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3d(X[4], Y[4], Z[4]);
  glVertex3d(X[5], Y[5], Z[5]);
  glVertex3d(X[6], Y[6], Z[6]);
  glVertex3d(X[7], Y[7], Z[7]);
  glEnd();

  glBegin(GL_LINES);
  glVertex3d(X[0], Y[0], Z[0]);
  glVertex3d(X[4], Y[4], Z[4]);
  glVertex3d(X[1], Y[1], Z[1]);
  glVertex3d(X[5], Y[5], Z[5]);
  glVertex3d(X[2], Y[2], Z[2]);
  glVertex3d(X[6], Y[6], Z[6]);
  glVertex3d(X[3], Y[3], Z[3]);
  glVertex3d(X[7], Y[7], Z[7]);
  glEnd();

  if(CTX.mesh.volumes_num) {
    sprintf(Num, "%d", h->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }

  if(CTX.mesh.dual) {

    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((h->V[0]->Pos.X + h->V[1]->Pos.X + h->V[5]->Pos.X +
        h->V[4]->Pos.X) / 4.,
       (h->V[0]->Pos.Y + h->V[1]->Pos.Y + h->V[5]->Pos.Y +
        h->V[4]->Pos.Y) / 4.,
       (h->V[0]->Pos.Z + h->V[1]->Pos.Z + h->V[5]->Pos.Z +
        h->V[4]->Pos.Z) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((h->V[0]->Pos.X + h->V[3]->Pos.X + h->V[2]->Pos.X +
        h->V[1]->Pos.X) / 4.,
       (h->V[0]->Pos.Y + h->V[3]->Pos.Y + h->V[2]->Pos.Y +
        h->V[1]->Pos.Y) / 4.,
       (h->V[0]->Pos.Z + h->V[3]->Pos.Z + h->V[2]->Pos.Z +
        h->V[1]->Pos.Z) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((h->V[0]->Pos.X + h->V[4]->Pos.X + h->V[7]->Pos.X +
        h->V[3]->Pos.X) / 4.,
       (h->V[0]->Pos.Y + h->V[4]->Pos.Y + h->V[7]->Pos.Y +
        h->V[3]->Pos.Y) / 4.,
       (h->V[0]->Pos.Z + h->V[4]->Pos.Z + h->V[7]->Pos.Z +
        h->V[3]->Pos.Z) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((h->V[1]->Pos.X + h->V[2]->Pos.X + h->V[6]->Pos.X +
        h->V[5]->Pos.X) / 4.,
       (h->V[1]->Pos.Y + h->V[2]->Pos.Y + h->V[6]->Pos.Y +
        h->V[5]->Pos.Y) / 4.,
       (h->V[1]->Pos.Z + h->V[2]->Pos.Z + h->V[6]->Pos.Z +
        h->V[5]->Pos.Z) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((h->V[2]->Pos.X + h->V[3]->Pos.X + h->V[7]->Pos.X +
        h->V[6]->Pos.X) / 4.,
       (h->V[2]->Pos.Y + h->V[3]->Pos.Y + h->V[7]->Pos.Y +
        h->V[6]->Pos.Y) / 4.,
       (h->V[2]->Pos.Z + h->V[3]->Pos.Z + h->V[7]->Pos.Z +
        h->V[6]->Pos.Z) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((h->V[4]->Pos.X + h->V[5]->Pos.X + h->V[6]->Pos.X +
        h->V[7]->Pos.X) / 4.,
       (h->V[4]->Pos.Y + h->V[5]->Pos.Y + h->V[6]->Pos.Y +
        h->V[7]->Pos.Y) / 4.,
       (h->V[4]->Pos.Z + h->V[5]->Pos.Z + h->V[6]->Pos.Z +
        h->V[7]->Pos.Z) / 4.);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if(CTX.mesh.shade)
    glEnable(GL_LIGHTING);

}

void Draw_Prism_Volume(void *a, void *b)
{
  Prism *p;
  int i;
  double Xc = 0.0, Yc = 0.0, Zc = 0.0, X[6], Y[6], Z[6];
  char Num[100];

  p = *(Prism **) a;

  if(!(p->Visible & VIS_MESH))
    return;

  // FIXME: remove as soon as a coherent structure exists for volumes
  Volume *V;
  if((V = FindVolume(p->iEnt, THEM)) && !(V->Visible & VIS_MESH))
    return;

  for(i = 0; i < 6; i++) {
    Xc += p->V[i]->Pos.X;
    Yc += p->V[i]->Pos.Y;
    Zc += p->V[i]->Pos.Z;
  }
  Xc /= 6.;
  Zc /= 6.;
  Yc /= 6.;

  if(CTX.mesh.use_cut_plane) {
    if(CTX.mesh.evalCutPlane(Xc, Yc, Zc) < 0)
      return;
  }

  if(CTX.mesh.color_carousel)
    ColorSwitch(p->iEnt);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.prism);

  for(i = 0; i < 6; i++) {
    X[i] = Xc + CTX.mesh.explode * (p->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (p->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (p->V[i]->Pos.Z - Zc);
  }

  if(CTX.mesh.shade)
    glDisable(GL_LIGHTING);

  glBegin(GL_LINE_LOOP);
  glVertex3d(X[0], Y[0], Z[0]);
  glVertex3d(X[1], Y[1], Z[1]);
  glVertex3d(X[2], Y[2], Z[2]);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3d(X[3], Y[3], Z[3]);
  glVertex3d(X[4], Y[4], Z[4]);
  glVertex3d(X[5], Y[5], Z[5]);
  glEnd();

  glBegin(GL_LINES);
  glVertex3d(X[0], Y[0], Z[0]);
  glVertex3d(X[3], Y[3], Z[3]);
  glVertex3d(X[1], Y[1], Z[1]);
  glVertex3d(X[4], Y[4], Z[4]);
  glVertex3d(X[2], Y[2], Z[2]);
  glVertex3d(X[5], Y[5], Z[5]);
  glEnd();

  if(CTX.mesh.volumes_num) {
    sprintf(Num, "%d", p->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }

  if(CTX.mesh.dual) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
    gl2psEnable(GL2PS_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((p->V[0]->Pos.X + p->V[2]->Pos.X + p->V[1]->Pos.X) / 3.,
       (p->V[0]->Pos.Y + p->V[2]->Pos.Y + p->V[1]->Pos.Y) / 3.,
       (p->V[0]->Pos.Z + p->V[2]->Pos.Z + p->V[1]->Pos.Z) / 3.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((p->V[3]->Pos.X + p->V[4]->Pos.X + p->V[5]->Pos.X) / 3.,
       (p->V[3]->Pos.Y + p->V[4]->Pos.Y + p->V[5]->Pos.Y) / 3.,
       (p->V[3]->Pos.Z + p->V[4]->Pos.Z + p->V[5]->Pos.Z) / 3.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((p->V[0]->Pos.X + p->V[1]->Pos.X + p->V[4]->Pos.X +
        p->V[3]->Pos.X) / 4.,
       (p->V[0]->Pos.Y + p->V[1]->Pos.Y + p->V[4]->Pos.Y +
        p->V[3]->Pos.Y) / 4.,
       (p->V[0]->Pos.Z + p->V[1]->Pos.Z + p->V[4]->Pos.Z +
        p->V[3]->Pos.Z) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((p->V[0]->Pos.X + p->V[3]->Pos.X + p->V[5]->Pos.X +
        p->V[2]->Pos.X) / 4.,
       (p->V[0]->Pos.Y + p->V[3]->Pos.Y + p->V[5]->Pos.Y +
        p->V[2]->Pos.Y) / 4.,
       (p->V[0]->Pos.Z + p->V[3]->Pos.Z + p->V[5]->Pos.Z +
        p->V[2]->Pos.Z) / 4.);
    glVertex3d(Xc, Yc, Zc);
    glVertex3d
      ((p->V[1]->Pos.X + p->V[2]->Pos.X + p->V[5]->Pos.X +
        p->V[4]->Pos.X) / 4.,
       (p->V[1]->Pos.Y + p->V[2]->Pos.Y + p->V[5]->Pos.Y +
        p->V[4]->Pos.Y) / 4.,
       (p->V[1]->Pos.Z + p->V[2]->Pos.Z + p->V[5]->Pos.Z +
        p->V[4]->Pos.Z) / 4.);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    gl2psDisable(GL2PS_LINE_STIPPLE);
  }

  if(CTX.mesh.shade)
    glEnable(GL_LIGHTING);

}

void Draw_Pyramid_Volume(void *a, void *b)
{
  Pyramid *p;
  int i;
  double Xc = 0.0, Yc = 0.0, Zc = 0.0, X[5], Y[5], Z[5];
  char Num[100];

  p = *(Pyramid **) a;

  if(!(p->Visible & VIS_MESH))
    return;

  // FIXME: remove as soon as a coherent structure exists for volumes
  Volume *V;
  if((V = FindVolume(p->iEnt, THEM)) && !(V->Visible & VIS_MESH))
    return;

  for(i = 0; i < 5; i++) {
    Xc += p->V[i]->Pos.X;
    Yc += p->V[i]->Pos.Y;
    Zc += p->V[i]->Pos.Z;
  }
  Xc /= 5.;
  Zc /= 5.;
  Yc /= 5.;

  if(CTX.mesh.use_cut_plane) {
    if(CTX.mesh.evalCutPlane(Xc, Yc, Zc) < 0)
      return;
  }

  if(CTX.mesh.color_carousel)
    ColorSwitch(p->iEnt);
  else
    glColor4ubv((GLubyte *) & CTX.color.mesh.pyramid);

  for(i = 0; i < 5; i++) {
    X[i] = Xc + CTX.mesh.explode * (p->V[i]->Pos.X - Xc);
    Y[i] = Yc + CTX.mesh.explode * (p->V[i]->Pos.Y - Yc);
    Z[i] = Zc + CTX.mesh.explode * (p->V[i]->Pos.Z - Zc);
  }

  if(CTX.mesh.shade)
    glDisable(GL_LIGHTING);

  glBegin(GL_LINE_LOOP);
  glVertex3d(X[0], Y[0], Z[0]);
  glVertex3d(X[1], Y[1], Z[1]);
  glVertex3d(X[2], Y[2], Z[2]);
  glVertex3d(X[3], Y[3], Z[3]);
  glEnd();

  glBegin(GL_LINES);
  glVertex3d(X[0], Y[0], Z[0]);
  glVertex3d(X[4], Y[4], Z[4]);
  glVertex3d(X[1], Y[1], Z[1]);
  glVertex3d(X[4], Y[4], Z[4]);
  glVertex3d(X[2], Y[2], Z[2]);
  glVertex3d(X[4], Y[4], Z[4]);
  glVertex3d(X[3], Y[3], Z[3]);
  glVertex3d(X[4], Y[4], Z[4]);
  glEnd();

  if(CTX.mesh.volumes_num) {
    sprintf(Num, "%d", p->Num);
    glRasterPos3d(Xc, Yc, Zc);
    Draw_String(Num);
  }

  if(CTX.mesh.shade)
    glEnable(GL_LIGHTING);

}
