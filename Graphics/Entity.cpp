// $Id: Entity.cpp,v 1.42 2004-05-30 19:17:58 geuzaine Exp $
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
#include "Numeric.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"

extern Context_T CTX;

void Draw_Point(int type, double size, double *x, double *y, double *z,
                double Raise[3][8], int light)
{
  if(type)
    Draw_Sphere(size, x[0] + Raise[0][0], y[0] + Raise[1][0],
                z[0] + Raise[2][0], light);
  else {
    glBegin(GL_POINTS);
    glVertex3d(x[0] + Raise[0][0], y[0] + Raise[1][0], z[0] + Raise[2][0]);
    glEnd();
  }
}

void Draw_Sphere(double size, double x, double y, double z, int light)
{
  if(light) glEnable(GL_LIGHTING);
  static GLUquadricObj *qua;
  static int first = 1, listnum;
  float s = size * CTX.pixel_equiv_x / CTX.s[0];        // size is in pixels
  if(first) {
    first = 0;
    qua = gluNewQuadric();
    listnum = glGenLists(1);
    glNewList(listnum, GL_COMPILE);
    gluSphere(qua, 1, CTX.quadric_subdivisions, CTX.quadric_subdivisions);
    glEndList();
  }
  glPushMatrix();
  glTranslated(x, y, z);
  glScalef(s, s, s);
  glCallList(listnum);
  glPopMatrix();
  glDisable(GL_LIGHTING);
}

void Draw_Cylinder(double width, double *x, double *y, double *z, int light)
{
  if(light) glEnable(GL_LIGHTING);

  static int first = 1;
  static GLUquadricObj *qua;

  if(first){
    first = 0;
    qua = gluNewQuadric();
  }

  glPushMatrix();

  double dx = x[1] - x[0];
  double dy = y[1] - y[0];
  double dz = z[1] - z[0];
  double length = sqrt(dx*dx + dy*dy + dz*dz);
  double radius = width * CTX.pixel_equiv_x / CTX.s[0];
  double zdir[3] = {0., 0., 1.};
  double vdir[3] = {dx/length, dy/length, dz/length};
  double axis[3], cosphi, phi;
  prodve(zdir, vdir, axis);
  prosca(zdir, vdir, &cosphi);
  if(!norme(axis)){
    axis[0] = 0.;
    axis[1] = 1.;
    axis[2] = 0.;
  }
  phi = 180. * myacos(cosphi) / M_PI;

  glTranslated(x[0], y[0], z[0]);
  glRotated(phi, axis[0], axis[1], axis[2]);
  gluCylinder(qua, radius, radius, length, CTX.quadric_subdivisions, 1);
  glPopMatrix();

  glDisable(GL_LIGHTING);
}

void Draw_Line(int type, double width, double *x, double *y, double *z,
               double Raise[3][8], int light)
{
  double X[2], Y[2], Z[2];

  X[0] = x[0] + Raise[0][0];
  Y[0] = y[0] + Raise[1][0];
  Z[0] = z[0] + Raise[2][0];

  X[1] = x[1] + Raise[0][1];
  Y[1] = y[1] + Raise[1][1];
  Z[1] = z[1] + Raise[2][1];

  if(type)
    Draw_Cylinder(width, X, Y, Z, light);
  else {
    glBegin(GL_LINES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glEnd();
  }
}

void Draw_SimpleVector(int arrow, int fill,
		       double relHeadRadius, double relStemLength, double relStemRadius,
		       double x, double y, double z,
		       double dx, double dy, double dz, 
		       double d, int light)
{
  double n[3], t[3], u[3];

  if(light && fill) glEnable(GL_LIGHTING);

  n[0] = dx / d;
  n[1] = dy / d;
  n[2] = dz / d;

  if((fabs(n[0]) >= fabs(n[1]) && fabs(n[0]) >= fabs(n[2])) ||
     (fabs(n[1]) >= fabs(n[0]) && fabs(n[1]) >= fabs(n[2]))) {
    t[0] = n[1];
    t[1] = -n[0];
    t[2] = 0.;
  }
  else {
    t[0] = 0.;
    t[1] = n[2];
    t[2] = -n[1];
  }

  double l = sqrt(t[0] * t[0] + t[1] * t[1] + t[2] * t[2]);
  t[0] /= l;
  t[1] /= l;
  t[2] /= l;

  u[0] = n[1] * t[2] - n[2] * t[1];
  u[1] = n[2] * t[0] - n[0] * t[2];
  u[2] = n[0] * t[1] - n[1] * t[0];

  l = sqrt(u[0] * u[0] + u[1] * u[1] + u[2] * u[2]);
  u[0] /= l;
  u[1] /= l;
  u[2] /= l;

  double b = relHeadRadius * d;

  if(arrow){
    double f1 = relStemLength;
    double f2 = (1-2.*relStemRadius) * f1; // hack :-)

    if(fill) {
      glBegin(GL_LINES);
      glVertex3d(x, y, z);
      glVertex3d(x + dx, y + dy, z + dz);
      glEnd();
      
      glBegin(GL_TRIANGLES);
      if(light) glNormal3dv(u);

      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (t[0]), y + f2 * dy + b * (t[1]),
		 z + f2 * dz + b * (t[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      
      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (-t[0]), y + f2 * dy + b * (-t[1]),
		 z + f2 * dz + b * (-t[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      
      if(light) glNormal3dv(t);
      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (-u[0]), y + f2 * dy + b * (-u[1]),
		 z + f2 * dz + b * (-u[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      
      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (u[0]), y + f2 * dy + b * (u[1]),
		 z + f2 * dz + b * (u[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      glEnd();
    }
    else {
      glBegin(GL_LINE_STRIP);
      glVertex3d(x, y, z);
      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (t[0]), y + f2 * dy + b * (t[1]),
		 z + f2 * dz + b * (t[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      glVertex3d(x + f2 * dx + b * (-t[0]), y + f2 * dy + b * (-t[1]),
		 z + f2 * dz + b * (-t[2]));
      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (-u[0]), y + f2 * dy + b * (-u[1]),
		 z + f2 * dz + b * (-u[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      glVertex3d(x + f2 * dx + b * (u[0]), y + f2 * dy + b * (u[1]),
		 z + f2 * dz + b * (u[2]));
      glVertex3d(x + dx, y + dy, z + dz);
      glEnd();
    }
  }
  else{ // simple pyramid
    if(fill){
      glBegin(GL_TRIANGLES);
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      glVertex3d(x+b*(u[0]),  y+b*(u[1]),  z+b*(u[2]));
      
      glVertex3d(x+dx,        y+dy,        z+dz);
      glVertex3d(x+b*(u[0]),  y+b*(u[1]),  z+b*(u[2]));
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glEnd();
    }
    else{
      glBegin(GL_LINE_LOOP);
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      glVertex3d(x+b*(u[0]),  y+b*(u[1]),  z+b*(u[2]));
      glEnd();
      
      glBegin(GL_LINES);
      glVertex3d(x+b*(t[0]),  y+b*(t[1]),  z+b*(t[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      
      glVertex3d(x+b*(-u[0]), y+b*(-u[1]), z+b*(-u[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      
      glVertex3d(x+b*(-t[0]), y+b*(-t[1]), z+b*(-t[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      
      glVertex3d (x+b*(u[0]), y+b*(u[1]),  z+b*(u[2]));
      glVertex3d(x+dx,        y+dy,        z+dz);
      glEnd();
    }
  }

  glDisable(GL_LIGHTING);
}

void Draw_3DArrow(double relHeadRadius, double relStemLength, double relStemRadius,
		  double x, double y, double z, double dx, double dy, double dz,
		  double length, int light)
{
  if(light) glEnable(GL_LIGHTING);

  int subdiv = CTX.quadric_subdivisions;
  double head_r = relHeadRadius * length;
  double head_l = (1. - relStemLength) * length;
  double stem_r = relStemRadius * length;
  double stem_l = relStemLength * length;

  static int first = 1;
  static GLUquadricObj *qua;

  if(first){
    first = 0;
    qua = gluNewQuadric();
  }

  glPushMatrix();

  double zdir[3] = {0., 0., 1.};
  double vdir[3] = {dx/length, dy/length, dz/length};
  double axis[3], cosphi, phi;
  prodve(zdir, vdir, axis);
  prosca(zdir, vdir, &cosphi);
  if(!norme(axis)){
    axis[0] = 0.;
    axis[1] = 1.;
    axis[2] = 0.;
  }
  phi = 180. * myacos(cosphi) / M_PI; 

  glTranslated(x, y, z);
  glRotated(phi, axis[0], axis[1], axis[2]);
  
  glTranslated(0., 0., stem_l);
  if(head_l && head_r)
    gluCylinder(qua, head_r, 0., head_l, subdiv, 1);
  if(head_r > stem_r)
    gluDisk(qua, stem_r, head_r, subdiv, 1);
  else
    gluDisk(qua, head_r, stem_r, subdiv, 1);      
  glTranslated(0., 0., -stem_l);

  if(stem_l && stem_r){
    gluCylinder(qua, stem_r, stem_r, stem_l, subdiv, 1);
    gluDisk(qua, 0, stem_r, subdiv, 1);
  }

  glPopMatrix();

  glDisable(GL_LIGHTING);
}

void Draw_Vector(int Type, int Fill,
		 double relHeadRadius, double relStemLength, double relStemRadius,
                 double x, double y, double z, double dx, double dy, double dz,
                 double Raise[3][8], int light)
{
  double length = sqrt(dx * dx + dy * dy + dz * dz);

  if(length == 0.0)
    return;

  if(Raise != NULL) {
    x += Raise[0][0];
    y += Raise[1][0];
    z += Raise[2][0];
  }

  switch(Type){
  case DRAW_POST_SEGMENT:
    glBegin(GL_LINES);
    glVertex3d(x, y, z);
    glVertex3d(x + dx, y + dy, z + dz);
    glEnd();
    break;
  case DRAW_POST_ARROW:
    Draw_SimpleVector(1, Fill, relHeadRadius, relStemLength, relStemRadius,
		      x, y, z, dx, dy, dz, length, light);
    break;
  case DRAW_POST_PYRAMID:
    Draw_SimpleVector(0, Fill, relHeadRadius, relStemLength, relStemRadius,
		      x, y, z, dx, dy, dz, length, light);
    break;
  case DRAW_POST_ARROW3D:
  default:
    Draw_3DArrow(relHeadRadius, relStemLength, relStemRadius,
		 x, y, z, dx, dy, dz, length, light);
    break;
  }

}
