// $Id: Entity.cpp,v 1.56 2005-03-09 09:21:26 geuzaine Exp $
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


#include "Mesh.h"
#include "Gmsh.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "Draw.h"
#include "Context.h"

extern Context_T CTX;

void Draw_Point(int type, double size, double *x, double *y, double *z,
                int light)
{
  if(type)
    Draw_Sphere(size, x[0], y[0], z[0], light);
  else {
    glBegin(GL_POINTS);
    glVertex3d(x[0], y[0], z[0]);
    glEnd();
  }
}

void Draw_Sphere(double size, double x, double y, double z, int light)
{
  if(light) glEnable(GL_LIGHTING);
  static GLUquadricObj *qua;
  static int first = 1, listnum;
  double s = size * CTX.pixel_equiv_x / CTX.s[0]; // size is in pixels
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
  glScaled(s, s, s);
  glCallList(listnum);
  glPopMatrix();
  glDisable(GL_LIGHTING);
}


void Draw_Disk(double size, double rint, double x, double y, double z, int light)
{
  if(light) glEnable(GL_LIGHTING);
  static GLUquadricObj *qua;
  static int first = 1, listnum;
  double s = size;
  if(first) {
    first = 0;
    qua = gluNewQuadric();
    listnum = glGenLists(1);
    glNewList(listnum, GL_COMPILE);
    gluDisk(qua, rint, 1, 2*CTX.quadric_subdivisions, 2*CTX.quadric_subdivisions);
    glEndList();
  }

  glPushMatrix();
  glTranslated(x, y, z);
  glScaled(s, s, s);
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

  glPushMatrix();
  glTranslated(x[0], y[0], z[0]);
  glRotated(phi, axis[0], axis[1], axis[2]);
  gluCylinder(qua, radius, radius, length, CTX.quadric_subdivisions, 1);
  glPopMatrix();

  glDisable(GL_LIGHTING);
}

void Draw_Line(int type, double width, double *x, double *y, double *z,
               int light)
{
  if(type)
    Draw_Cylinder(width, x, y, z, light);
  else {
    glBegin(GL_LINES);
    glVertex3d(x[0], y[0], z[0]);
    glVertex3d(x[1], y[1], z[1]);
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
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      glEnd();
      
      if(light && fill) glEnable(GL_LIGHTING);
      glBegin(GL_TRIANGLES);
      if(light) glNormal3dv(u);
      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (t[0]), y + f2 * dy + b * (t[1]),
		 z + f2 * dz + b * (t[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);
      glVertex3d(x + f2 * dx + b * (-t[0]), y + f2 * dy + b * (-t[1]),
		 z + f2 * dz + b * (-t[2]));
      glVertex3d(x + dx, y + dy, z + dz);
      
      if(light) glNormal3dv(t);
      glVertex3d(x + dx, y + dy, z + dz);
      glVertex3d(x + f2 * dx + b * (-u[0]), y + f2 * dy + b * (-u[1]),
		 z + f2 * dz + b * (-u[2]));
      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);

      glVertex3d(x + f1 * dx, y + f1 * dy, z + f1 * dz);      
      glVertex3d(x + f2 * dx + b * (u[0]), y + f2 * dy + b * (u[1]),
		 z + f2 * dz + b * (u[2]));
      glVertex3d(x + dx, y + dy, z + dz);
      glEnd();
      glDisable(GL_LIGHTING);
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
      double top[3] = { x+dx,      y+dy,      z+dz };
      double tp[3]  = { x+b*t[0],  y+b*t[1],  z+b*t[2] };
      double tm[3]  = { x-b*t[0],  y-b*t[1],  z-b*t[2] };
      double up[3]  = { x+b*u[0],  y+b*u[1],  z+b*u[2] };
      double um[3]  = { x-b*u[0],  y-b*u[1],  z-b*u[2] };
      double nn[3];

      if(light && fill) glEnable(GL_LIGHTING);
      glBegin(GL_TRIANGLES);
      if(light){
	normal3points(tm[0], tm[1], tm[2], um[0], um[1], um[2],
		      top[0], top[1], top[2], nn);
	glNormal3dv(nn);
      }
      glVertex3d(tm[0], tm[1], tm[2]);
      glVertex3d(um[0], um[1], um[2]);
      glVertex3d(top[0], top[1], top[2]);

      if(light){
	normal3points(um[0], um[1], um[2], tp[0], tp[1], tp[2],
		      top[0], top[1], top[2], nn);
	glNormal3dv(nn);
      }
      glVertex3d(um[0], um[1], um[2]);
      glVertex3d(tp[0], tp[1], tp[2]);
      glVertex3d(top[0], top[1], top[2]);

      if(light){
	normal3points(tp[0], tp[1], tp[2], up[0], up[1], up[2],
		      top[0], top[1], top[2], nn);
	glNormal3dv(nn);
      }
      glVertex3d(tp[0], tp[1], tp[2]);
      glVertex3d(up[0], up[1], up[2]);
      glVertex3d(top[0], top[1], top[2]);

      if(light){
	normal3points(up[0], up[1], up[2], tm[0], tm[1], tm[2],
		      top[0], top[1], top[2], nn);
	glNormal3dv(nn);
      }
      glVertex3d(up[0], up[1], up[2]);
      glVertex3d(tm[0], tm[1], tm[2]);
      glVertex3d(top[0], top[1], top[2]);
      glEnd();
      glDisable(GL_LIGHTING);
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

  glPushMatrix();
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
                 int light)
{
  double length = sqrt(dx * dx + dy * dy + dz * dz);

  if(length == 0.0)
    return;

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

class point{
public:
    double x, y, z;
    bool valid;
    point() : x(0.), y(0.), z(0.), valid(false) {;};
    point(double xi, double yi, double zi) :
	x(xi), y(yi), z(zi), valid(true) {;};
};

class plane{
private:
    double _a, _b, _c, _d;
public:
    plane(double a, double b, double c, double d) :
	_a(a), _b(b), _c(c), _d(d) {;};
    double val(point &p){
	return _a*p.x + _b*p.y + _c*p.z + _d;
    };
    point intersect(point &p1, point &p2){
	double v1 = val(p1), v2 = val(p2);
	if(fabs(v1) < 1.e-12){
	    if(fabs(v2) < 1.e-12)
		return point();
	    else
		return point(p1.x, p1.y, p1.z);
	}
	else if(fabs(v2) < 1.e-12){
	    return point(p2.x, p2.y, p2.z);
	}
	else if(v1 * v2 < 0.){
	    double coef = - v1 / (v2 - v1);
	    return point(coef * (p2.x - p1.x) + p1.x,
			 coef * (p2.y - p1.y) + p1.y,
			 coef * (p2.z - p1.z) + p1.z);
	}
	else
	    return point();
    };
};

void Draw_PlaneInBoundingBox(double xmin, double ymin, double zmin,
			     double xmax, double ymax, double zmax,
			     double a, double b, double c, double d)
{

  plane pl(a, b, c, d);
  point p1(xmin, ymin, zmin), p2(xmax, ymin, zmin);
  point p3(xmax, ymax, zmin), p4(xmin, ymax, zmin);
  point p5(xmin, ymin, zmax), p6(xmax, ymin, zmax);
  point p7(xmax, ymax, zmax), p8(xmin, ymax, zmax);

  point edge[12];
  edge[0] = pl.intersect(p1, p2);
  edge[1] = pl.intersect(p1, p4);
  edge[2] = pl.intersect(p1, p5);
  edge[3] = pl.intersect(p2, p3);
  edge[4] = pl.intersect(p2, p6);
  edge[5] = pl.intersect(p3, p4);
  edge[6] = pl.intersect(p3, p7);
  edge[7] = pl.intersect(p4, p8);
  edge[8] = pl.intersect(p5, p6);
  edge[9] = pl.intersect(p5, p8);
  edge[10] = pl.intersect(p6, p7);
  edge[11] = pl.intersect(p7, p8);

  int face[6][4] = {
    {0, 2, 4, 8},
    {0, 1, 3, 5},
    {1, 2, 7, 9},
    {3, 4, 6, 10},
    {5, 6, 7, 11},
    {8, 9, 10, 11}
  };
  
  double n[3] = {a,b,c}, ll = 50;
  norme(n);
  if(CTX.arrow_rel_stem_radius)
    ll = CTX.line_width/CTX.arrow_rel_stem_radius;
  n[0] *= ll * CTX.pixel_equiv_x / CTX.s[0];
  n[1] *= ll * CTX.pixel_equiv_x / CTX.s[1];
  n[2] *= ll * CTX.pixel_equiv_x / CTX.s[2];
  double length = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);

  for(int i = 0; i < 6; i++){
    int nb = 0;
    point p[4];
    for(int j = 0; j < 4; j++){
      if(edge[face[i][j]].valid == true)
	p[nb++] = edge[face[i][j]];
    }
    if(nb > 1){
      for(int j = 1; j < nb; j++){
	double xx[2] = {p[j].x, p[j-1].x};
	double yy[2] = {p[j].y, p[j-1].y};
	double zz[2] = {p[j].z, p[j-1].z};
	Draw_Cylinder(CTX.line_width, xx, yy, zz, 1);
      }
      for(int j = 0; j < nb; j++){
	Draw_3DArrow(CTX.arrow_rel_head_radius, 
		     CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
		     p[j].x, p[j].y, p[j].z, n[0], n[1], n[2], length, 1);
      }
    }
  }
}
