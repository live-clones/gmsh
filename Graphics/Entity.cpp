// $Id: Entity.cpp,v 1.61 2005-03-13 09:10:35 geuzaine Exp $
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
#include "gl2ps.h"

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

void Draw_SmallAxes()
{
  double l = CTX.small_axes_size;
  double o = 2;

  double cx = CTX.small_axes_pos[0];
  double cy = CTX.small_axes_pos[1];
  Fix2DCoordinates(&cx, &cy);

  double xx = l * CTX.rot[0];
  double xy = l * CTX.rot[1];
  double yx = l * CTX.rot[4];
  double yy = l * CTX.rot[5];
  double zx = l * CTX.rot[8];
  double zy = l * CTX.rot[9];

  glLineWidth(CTX.line_width);
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
  glColor4ubv((GLubyte *) & CTX.color.small_axes);

  glBegin(GL_LINES);
  glVertex2d(cx, cy);
  glVertex2d(cx + xx, cy + xy);
  glVertex2d(cx, cy);
  glVertex2d(cx + yx, cy + yy);
  glVertex2d(cx, cy);
  glVertex2d(cx + zx, cy + zy);
  glEnd();
  glRasterPos2d(cx + xx + o, cy + xy + o);
  Draw_String("X");
  glRasterPos2d(cx + yx + o, cy + yy + o);
  Draw_String("Y");
  glRasterPos2d(cx + zx + o, cy + zy + o);
  Draw_String("Z");
}

int Draw_Tics(int comp, int n, char *format, char *label,
	      double p1[3], double p2[3], double perp[3])
{
  // draws n tic marks (in direction perp) and labels along the line p1->p2

  double t[3] = { p2[0]-p1[0], p2[1]-p1[1], p2[2]-p1[2] };
  double l = norme(t);
  double w = 10 * CTX.pixel_equiv_x / CTX.s[0]; // big tics 10 pixels
  double w2 = 4 * CTX.pixel_equiv_x / CTX.s[0]; // small tics 4 pixels

  glRasterPos3d(p2[0]+t[0]*w*1.4, p2[1]+t[1]*w*1.4, p2[2]+t[2]*w*1.4);
  Draw_String(label);

  if(n < 2) return 0;

  if(!strlen(format)) return n;

  double lp = norme(perp);
  if(!lp){
    switch(comp){
    case 0: perp[1] = -1.; break;
    case 1: perp[0] = -1.; break;
    case 2: perp[0] = 1.; break;
    default: break;
    }
  }
  
  double tmp = 2. * CTX.gl_fontsize * CTX.pixel_equiv_x / CTX.s[0];
  if(n * tmp > l) n = 3;
  if(n * tmp > l) n = 2;
  
  double step = l/(double)(n-1);

  for(int i = 0; i < n; i++){
    double d = i * step;
    double p[3] = { p1[0]+t[0]*d, p1[1]+t[1]*d, p1[2]+t[2]*d };
    double q[3] = { p[0]+perp[0]*w, p[1]+perp[1]*w, p[2]+perp[2]*w };
    double r[3] = { p[0]+perp[0]*w*1.4, p[1]+perp[1]*w*1.4, p[2]+perp[2]*w*1.4 };

    glBegin(GL_LINES);
    glVertex3d(p[0], p[1], p[2]);
    glVertex3d(q[0], q[1], q[2]);
    glEnd();

    if(i < n-1){
      for(int j = 1; j < 10; j++){
	double dd = d + j * step/10.;
	double pp[3] = { p1[0]+t[0]*dd, p1[1]+t[1]*dd, p1[2]+t[2]*dd };
	double qq[3] = { pp[0]+perp[0]*w2, pp[1]+perp[1]*w2, pp[2]+perp[2]*w2 };
	glBegin(GL_LINES);
	glVertex3d(pp[0], pp[1], pp[2]);
	glVertex3d(qq[0], qq[1], qq[2]);
	glEnd();
      }
    }

    char str[256];
    if(comp < 0) // display the length (ruler)
      sprintf(str, format, d);
    else // display the coordinate
      sprintf(str, format, p[comp]);
    double winp[3], winr[3];
    World2Viewport(p, winp);
    World2Viewport(r, winr);
    gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
    if(fabs(winr[0] - winp[0]) < 2.) // center align
      winr[0] -= gl_width(str) / 2.;
    else if(winr[0] < winp[0]) // right align
      winr[0] -= gl_width(str);
    if(fabs(winr[1] - winp[1]) < 2.) // center align
      winr[1] -= gl_height() / 3.;
    else if(winr[1] < winp[1]) // top align
      winr[1] -= gl_height();
    Viewport2World(winr, r);
    glRasterPos3d(r[0], r[1], r[2]);
    Draw_String(str);
  }

  return n;
}

void Draw_GridStipple(int n1, int n2, double p1[3], double p2[3], double p3[3])
{
  double t1[3] = { p2[0]-p1[0], p2[1]-p1[1], p2[2]-p1[2] };
  double t2[3] = { p3[0]-p1[0], p3[1]-p1[1], p3[2]-p1[2] };
  double l1 = norme(t1);
  double l2 = norme(t2);

  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x1111);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);
  
  for(int i = 1; i < n1-1; i++){
    double d = (double)i/(double)(n1-1) * l1;
    glVertex3d(p1[0] + t1[0]*d,
	       p1[1] + t1[1]*d,
	       p1[2] + t1[2]*d);
    glVertex3d(p1[0] + t1[0]*d + t2[0]*l2, 
	       p1[1] + t1[1]*d + t2[1]*l2, 
	       p1[2] + t1[2]*d + t2[2]*l2);
  }
  for(int i = 1; i < n2-1; i++){
    double d = (double)i/(double)(n2-1) * l2;
    glVertex3d(p1[0] + t2[0]*d, 
	       p1[1] + t2[1]*d, 
	       p1[2] + t2[2]*d);
    glVertex3d(p1[0] + t2[0]*d + t1[0]*l1, 
	       p1[1] + t2[1]*d + t1[1]*l1, 
	       p1[2] + t2[2]*d + t1[2]*l1);
  }

  glEnd();
  glDisable(GL_LINE_STIPPLE);
  gl2psDisable(GL2PS_LINE_STIPPLE);
}

void Draw_Axes(int mode, int tics[3], char format[3][256], char label[3][256], 
	       double bb[6])
{
  // mode 0: nothing
  //      1: axes
  //      2: box
  //      3: full grid
  //      4: open grid
  //      5: ruler

  if((mode < 1) || (bb[0] == bb[1] && bb[2] == bb[3] && bb[4] == bb[5]))
    return;

  double xmin = bb[0], xmax = bb[1];
  double ymin = bb[2], ymax = bb[3];
  double zmin = bb[4], zmax = bb[5];
  double orig[3] = {xmin, ymin, zmin};

  if(mode == 5){ // draw ruler from xyz_min to xyz_max
    glBegin(GL_LINES);
    glVertex3d(xmin, ymin, zmin); glVertex3d(xmax, ymax, zmax);
    glEnd();
    double end[3] = {xmax, ymax, zmax};
    double dir[3] = {xmax-xmin, ymax-ymin, zmax-zmin};
    double perp[3];
    if((fabs(dir[0]) >= fabs(dir[1]) && fabs(dir[0]) >= fabs(dir[2])) ||
       (fabs(dir[1]) >= fabs(dir[0]) && fabs(dir[1]) >= fabs(dir[2]))){
      perp[0] = dir[1]; perp[1] = -dir[0]; perp[2] = 0.;
    }
    else{
      perp[0] = 0.; perp[1] = dir[2]; perp[2] = -dir[1];
    }
    Draw_Tics(-1, tics[0], format[0], label[0], orig, end, perp);
    return;
  }
  
  glBegin(GL_LINES);
  // 3 axes
  glVertex3d(xmin, ymin, zmin); glVertex3d(xmax, ymin, zmin);
  glVertex3d(xmin, ymin, zmin); glVertex3d(xmin, ymax, zmin);
  glVertex3d(xmin, ymin, zmin); glVertex3d(xmin, ymin, zmax);
  // open box
  if(mode > 1){
    glVertex3d(xmin, ymax, zmin); glVertex3d(xmax, ymax, zmin);
    glVertex3d(xmax, ymin, zmin); glVertex3d(xmax, ymax, zmin);
    glVertex3d(xmin, ymin, zmax); glVertex3d(xmax, ymin, zmax);
    glVertex3d(xmax, ymin, zmin); glVertex3d(xmax, ymin, zmax);
    glVertex3d(xmin, ymin, zmax); glVertex3d(xmin, ymax, zmax);
    glVertex3d(xmin, ymax, zmin); glVertex3d(xmin, ymax, zmax);
  }
  // closed box
  if(mode == 2 || mode == 3){
    glVertex3d(xmax, ymax, zmax); glVertex3d(xmin, ymax, zmax);
    glVertex3d(xmax, ymax, zmax); glVertex3d(xmax, ymin, zmax);
    glVertex3d(xmax, ymax, zmax); glVertex3d(xmax, ymax, zmin);
  }
  glEnd();

  double xx[3] = {xmax, ymin, zmin};
  double yy[3] = {xmin, ymax, zmin};
  double zz[3] = {xmin, ymin, zmax};
  double dxm[3] = {0., (ymin != ymax) ? -1. : 0., (zmin != zmax) ? -1. : 0.};
  double dym[3] = {(xmin != xmax) ? -1. : 0., 0., (zmin != zmax) ? -1. : 0.};
  double dzm[3] = {(xmin != xmax) ? -1. : 0., (ymin != ymax) ? -1. : 0., 0.};

  int nx = (xmin != xmax) ? Draw_Tics(0, tics[0], format[0], label[0], orig, xx, dxm) : 0;
  int ny = (ymin != ymax) ? Draw_Tics(1, tics[1], format[1], label[1], orig, yy, dym) : 0;
  int nz = (zmin != zmax) ? Draw_Tics(2, tics[2], format[2], label[2], orig, zz, dzm) : 0;
  
  if(mode > 2){
    Draw_GridStipple(nx, ny, orig, xx, yy);
    Draw_GridStipple(ny, nz, orig, yy, zz);
    Draw_GridStipple(nx, nz, orig, xx, zz);
  }

  if(mode == 3){
    double orig2[3] = {xmax, ymax, zmax};
    double xy[3] = {xmax, ymax, zmin};
    double yz[3] = {xmin, ymax, zmax};
    double xz[3] = {xmax, ymin, zmax};
    if(zmin != zmax) Draw_GridStipple(nx, ny, orig2, yz, xz);
    if(xmin != xmax) Draw_GridStipple(ny, nz, orig2, xz, xy);
    if(ymin != ymax) Draw_GridStipple(nx, nz, orig2, yz, xy);
  }
}
