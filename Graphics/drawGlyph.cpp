// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "drawContext.h"
#include "GmshDefines.h"
#include "Numeric.h"
#include "StringUtils.h"
#include "Context.h"
#include "gl2ps.h"
#include "SVector3.h"

void drawContext::drawString(const std::string &s, const std::string &font_name,
                             int font_enum, int font_size, int align)
{
  if(CTX::instance()->printing && !CTX::instance()->print.text) return;

  // change the raster position only if not creating TeX files
  if(align > 0 && (!CTX::instance()->printing || 
                   CTX::instance()->print.fileFormat != FORMAT_TEX)){
    GLboolean valid;
    glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, &valid);
    if(valid == GL_TRUE){
      GLdouble pos[4];
      glGetDoublev(GL_CURRENT_RASTER_POSITION, pos);
      double x[3], w[3] = {pos[0], pos[1], pos[2]};
      drawContext::global()->setFont(font_enum, font_size);
      double width = drawContext::global()->getStringWidth(s.c_str());
      double height = drawContext::global()->getStringHeight();
      switch(align){
      case 1: w[0] -= width/2.;                     break; // bottom center
      case 2: w[0] -= width;                        break; // bottom right
      case 3:                    w[1] -= height;    break; // top left
      case 4: w[0] -= width/2.;  w[1] -= height;    break; // top center
      case 5: w[0] -= width;     w[1] -= height;    break; // top right
      case 6:                    w[1] -= height/2.; break; // center left
      case 7: w[0] -= width/2.;  w[1] -= height/2.; break; // center center
      case 8: w[0] -= width;     w[1] -= height/2.; break; // center right
      default: break;
      }
      viewport2World(w, x);
      glRasterPos3d(x[0], x[1], x[2]);
    }
  }
  
  if(!CTX::instance()->printing){
    drawContext::global()->setFont(font_enum, font_size);
    drawContext::global()->drawString(s.c_str());
  }
  else{
    if(CTX::instance()->print.fileFormat == FORMAT_TEX){
      std::string tmp = SanitizeTeXString
        (s.c_str(), CTX::instance()->print.texAsEquation);
      int opt;
      switch(align){
      case 1: opt = GL2PS_TEXT_B;   break; // bottom center
      case 2: opt = GL2PS_TEXT_BR;  break; // bottom right
      case 3: opt = GL2PS_TEXT_TL;  break; // top left
      case 4: opt = GL2PS_TEXT_T;   break; // top center
      case 5: opt = GL2PS_TEXT_TR;  break; // top right
      case 6: opt = GL2PS_TEXT_CL;  break; // center left
      case 7: opt = GL2PS_TEXT_C;   break; // center center
      case 8: opt = GL2PS_TEXT_CR;  break; // center right
      default: opt = GL2PS_TEXT_BL; break; // bottom left
      }
      gl2psTextOpt(tmp.c_str(), font_name.c_str(), font_size, opt, 0.);
    }
    else if(CTX::instance()->print.epsQuality && 
            (CTX::instance()->print.fileFormat == FORMAT_PS ||
             CTX::instance()->print.fileFormat == FORMAT_EPS ||
             CTX::instance()->print.fileFormat == FORMAT_PDF ||
             CTX::instance()->print.fileFormat == FORMAT_SVG)){
      gl2psText(s.c_str(), font_name.c_str(), font_size);
    }
    else{
      drawContext::global()->setFont(font_enum, font_size);
      drawContext::global()->drawString(s.c_str());
    }
  }
}

void drawContext::drawString(const std::string &s)
{
  drawString(s, CTX::instance()->glFont, CTX::instance()->glFontEnum, 
             CTX::instance()->glFontSize, 0);
}

void drawContext::drawStringCenter(const std::string &s)
{
  drawString(s, CTX::instance()->glFont, CTX::instance()->glFontEnum,
             CTX::instance()->glFontSize, 1);
}

void drawContext::drawStringRight(const std::string &s)
{
  drawString(s, CTX::instance()->glFont, CTX::instance()->glFontEnum,
             CTX::instance()->glFontSize, 2);
}

void drawContext::drawString(const std::string &s, double style)
{
  unsigned int bits = (unsigned int)style;

  if(!bits){ // use defaults
    drawString(s);
  }
  else{
    int size = (bits & 0xff);
    int font = (bits>>8 & 0xff);
    int align = (bits>>16 & 0xff);
    int font_enum = drawContext::global()->getFontEnum(font);
    std::string font_name = drawContext::global()->getFontName(font);
    if(!size) size = CTX::instance()->glFontSize;
    drawString(s, font_name, font_enum, size, align);
  }
}

void drawContext::drawSphere(double R, double x, double y, double z,
                             int n1, int n2, int light)
{
  if(light) glEnable(GL_LIGHTING);
  glPushMatrix();
  glTranslated(x, y, z);
  gluSphere(_quadric, R, n1, n2);
  glPopMatrix();
  glDisable(GL_LIGHTING);
}

void drawContext::drawEllipse(double x, double y, double z, float v0[3], float v1[3], float v2[3], int light)
{
  if(light) glEnable(GL_LIGHTING);
  glPushMatrix();
  GLfloat m[16] = {
    v0[0], v0[1], v0[2], .0f,
    v1[0], v1[1], v1[2], .0f,
    v2[0], v2[1], v2[2], .0f,
    x, y, z, 1.f
  };
  glMultMatrixf(m);
  glCallList(_displayLists + 0);
  glPopMatrix();
  glDisable(GL_LIGHTING);
}

void drawContext::drawSphere(double size, double x, double y, double z, int light)
{
  double ss = size * pixel_equiv_x / s[0]; // size is in pixels

  if(light) glEnable(GL_LIGHTING);
  glPushMatrix();
  glTranslated(x, y, z);
  glScaled(ss, ss, ss);
  glCallList(_displayLists + 0);
  glPopMatrix();
  glDisable(GL_LIGHTING);
}

void drawContext::drawTaperedCylinder(double width, double val1, double val2, 
                                      double ValMin, double ValMax, 
                                      double *x, double *y, double *z, int light)
{
  if(light) glEnable(GL_LIGHTING);

  double dx = x[1] - x[0];
  double dy = y[1] - y[0];
  double dz = z[1] - z[0];
  double length = sqrt(dx * dx + dy * dy + dz * dz);
  double fact = width * pixel_equiv_x / s[0] / (ValMax - ValMin);
  double radius1 = (val1 - ValMin) * fact;
  double radius2 = (val2 - ValMin) * fact;
  double zdir[3] = {0., 0., 1.};
  double vdir[3] = {dx / length, dy / length, dz / length};
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
  gluCylinder(_quadric, radius1, radius2, length, CTX::instance()->quadricSubdivisions, 1);
  glPopMatrix();

  glDisable(GL_LIGHTING);
}

void drawContext::drawCylinder(double width, double *x, double *y, double *z, int light)
{
  if(light) glEnable(GL_LIGHTING);

  double dx = x[1] - x[0];
  double dy = y[1] - y[0];
  double dz = z[1] - z[0];
  double length = sqrt(dx * dx + dy * dy + dz * dz);
  double radius = width * pixel_equiv_x / s[0];
  double zdir[3] = {0., 0., 1.};
  double vdir[3] = {dx / length, dy / length, dz / length};
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
  gluCylinder(_quadric, radius, radius, length, CTX::instance()->quadricSubdivisions, 1);
  glPopMatrix();

  glDisable(GL_LIGHTING);
}

static void drawSimpleVector(int arrow, int fill,
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

  double b = CTX::instance()->arrowRelHeadRadius * d;

  if(arrow){
    double f1 = CTX::instance()->arrowRelStemLength;
    double f2 = (1 - 2. * CTX::instance()->arrowRelStemRadius) * f1; // hack :-)

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

void drawContext::drawArrow3d(double x, double y, double z, 
                              double dx, double dy, double dz, 
                              double length, int light)
{
  double zdir[3] = {0., 0., 1.};
  double vdir[3] = {dx / length, dy / length, dz / length};
  double axis[3], cosphi;
  prodve(zdir, vdir, axis);
  prosca(zdir, vdir, &cosphi);
  if(!norme(axis)){
    axis[0] = 0.;
    axis[1] = 1.;
    axis[2] = 0.;
  }
  double phi = 180. * myacos(cosphi) / M_PI; 

  if(light) glEnable(GL_LIGHTING);
  glPushMatrix();
  glTranslated(x, y, z);
  glScaled(length, length, length);
  glRotated(phi, axis[0], axis[1], axis[2]);
  glCallList(_displayLists + 1);
  glPopMatrix();
  glDisable(GL_LIGHTING);
}

void drawContext::drawVector(int Type, int Fill, double x, double y, double z,
                             double dx, double dy, double dz, int light)
{
  double length = sqrt(dx * dx + dy * dy + dz * dz);

  if(length == 0.0) return;

  switch(Type){
  case 1:
    glBegin(GL_LINES);
    glVertex3d(x, y, z);
    glVertex3d(x + dx, y + dy, z + dz);
    glEnd();
    break;
  case 6:
    if(CTX::instance()->arrowRelHeadRadius){
      glBegin(GL_POINTS);
      glVertex3d(x + dx, y + dy, z + dz);
      glEnd();
    }
    glBegin(GL_LINES);
    glVertex3d(x + dx, y + dy, z + dz);
    // color gradient
    glColor4ubv((GLubyte *) & CTX::instance()->color.bg);
    glVertex3d(x, y, z);
    glEnd();
    break;
  case 2:
    drawSimpleVector(1, Fill, x, y, z, dx, dy, dz, length, light);
    break;
  case 3:
    drawSimpleVector(0, Fill, x, y, z, dx, dy, dz, length, light);
    break;
  case 4:
  default:
    drawArrow3d(x, y, z, dx, dy, dz, length, light);
    break;
  }
}

class point{
 public:
  double x, y, z;
  bool valid;
  point() : x(0.), y(0.), z(0.), valid(false) {}
  point(double xi, double yi, double zi) : x(xi), y(yi), z(zi), valid(true) {}
};

class plane{
 private:
  double _a, _b, _c, _d;
 public:
  plane(double a, double b, double c, double d) : _a(a), _b(b), _c(c), _d(d) {}
  double val(point &p)
  {
    return _a * p.x + _b * p.y + _c * p.z + _d;
  };
  point intersect(point &p1, point &p2)
  {
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
  }
};

void drawContext::drawBox(double xmin, double ymin, double zmin,
                          double xmax, double ymax, double zmax,
                          bool labels)
{
  glBegin(GL_LINE_LOOP);
  glVertex3d(xmin, ymin, zmin);
  glVertex3d(xmax, ymin, zmin);
  glVertex3d(xmax, ymax, zmin);
  glVertex3d(xmin, ymax, zmin);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex3d(xmin, ymin, zmax);
  glVertex3d(xmax, ymin, zmax);
  glVertex3d(xmax, ymax, zmax);
  glVertex3d(xmin, ymax, zmax);
  glEnd();
  glBegin(GL_LINES);
  glVertex3d(xmin, ymin, zmin);
  glVertex3d(xmin, ymin, zmax);
  glVertex3d(xmax, ymin, zmin);
  glVertex3d(xmax, ymin, zmax);
  glVertex3d(xmax, ymax, zmin);
  glVertex3d(xmax, ymax, zmax);
  glVertex3d(xmin, ymax, zmin);
  glVertex3d(xmin, ymax, zmax);
  glEnd();
  if(labels){
    char label[256];
    double offset = 0.3 * CTX::instance()->glFontSize * pixel_equiv_x;
    glRasterPos3d(xmin + offset / s[0], 
                  ymin + offset / s[1], 
                  zmin + offset / s[2]);
    sprintf(label, "(%g,%g,%g)", xmin, ymin, zmin);
    drawString(label);
    glRasterPos3d(xmax + offset / s[0], 
                  ymax + offset / s[1], 
                  zmax + offset / s[2]);
    sprintf(label, "(%g,%g,%g)", xmax, ymax, zmax);
    drawString(label);
  }
}

void drawContext::drawPlaneInBoundingBox(double xmin, double ymin, double zmin,
                                         double xmax, double ymax, double zmax,
                                         double a, double b, double c, double d,
                                         int shade)
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
  if(CTX::instance()->arrowRelStemRadius)
    ll = CTX::instance()->lineWidth / CTX::instance()->arrowRelStemRadius;
  n[0] *= ll * pixel_equiv_x / s[0];
  n[1] *= ll * pixel_equiv_x / s[1];
  n[2] *= ll * pixel_equiv_x / s[2];
  double length = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);

  int n_shade = 0;
  point p_shade[24];

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
        drawCylinder(CTX::instance()->lineWidth, xx, yy, zz, 1);
      }
      for(int j = 0; j < nb; j++){
        drawArrow3d(p[j].x, p[j].y, p[j].z, n[0], n[1], n[2], length, 1);
        if(shade){
          p_shade[n_shade].x = p[j].x;
          p_shade[n_shade].y = p[j].y;
          p_shade[n_shade].z = p[j].z;
          n_shade++;
        }
      }
    }
  }

  if(shade){
    // disable two-side lighting beacuse polygon can overlap itself
    GLboolean twoside;
    glGetBooleanv(GL_LIGHT_MODEL_TWO_SIDE, &twoside);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glEnable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glNormal3d(n[0], n[1], n[2]);
    for(int j = 0; j < n_shade; j++){
      glVertex3d(p_shade[j].x, p_shade[j].y, p_shade[j].z);
    }   
    glEnd();
    glDisable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, twoside);
  }
}
