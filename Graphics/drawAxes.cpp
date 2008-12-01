// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/gl.h>
#include "drawContext.h"
#include "Draw.h"
#include "GModel.h"
#include "Context.h"
#include "Numeric.h"
#include "gl2ps.h"

extern Context_T CTX;

static int drawTics(int comp, int n, char *format, char *label,
                    double p1[3], double p2[3], double perp[3], int mikado,
                    double pixelfact)
{
  // draws n tic marks (in direction perp) and labels along the line p1->p2

  double t[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double l = norme(t);
  double w = 10 * pixelfact; // big tics 10 pixels
  double w2 = 5 * pixelfact; // small tics 5 pixels

  glRasterPos3d(p2[0] + t[0] * w * 1.4,
                p2[1] + t[1] * w * 1.4,
                p2[2] + t[2] * w * 1.4);
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
  
  double tmp = 2. * CTX.gl_fontsize * pixelfact;
  if(n * tmp > l) n = 3;
  if(n * tmp > l) n = 2;
  
  double step = l / (double)(n - 1);

  for(int i = 0; i < n; i++){
    double d = i * step;
    double p[3] = {p1[0] + t[0] * d, p1[1] + t[1] * d, p1[2] + t[2] * d};
    double q[3] = {p[0] + perp[0] * w, 
                   p[1] + perp[1] * w, 
                   p[2] + perp[2] * w};
    double r[3] = {p[0] + perp[0] * w * 1.4,
                   p[1] + perp[1] * w * 1.4, 
                   p[2] + perp[2] * w * 1.4 };

    glBegin(GL_LINES);
    glVertex3d(p[0], p[1], p[2]);
    glVertex3d(q[0], q[1], q[2]);
    glEnd();

    if(i < n-1 && !mikado){
      for(int j = 1; j < 10; j++){
        double dd = d + j * step/10.;
        double pp[3] = {p1[0] + t[0] * dd, 
                        p1[1] + t[1] * dd,
                        p1[2] + t[2] * dd};
        double qq[3] = {pp[0] + perp[0] * w2,
                        pp[1] + perp[1] * w2,
                        pp[2] + perp[2] * w2};
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

static void drawGridStipple(int n1, int n2, double p1[3], double p2[3], double p3[3])
{
  double t1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double t2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double l1 = norme(t1);
  double l2 = norme(t2);

  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x1111);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);
  
  for(int i = 1; i < n1 - 1; i++){
    double d = (double)i / (double)(n1 - 1) * l1;
    glVertex3d(p1[0] + t1[0] * d,
               p1[1] + t1[1] * d,
               p1[2] + t1[2] * d);
    glVertex3d(p1[0] + t1[0] * d + t2[0] * l2, 
               p1[1] + t1[1] * d + t2[1] * l2, 
               p1[2] + t1[2] * d + t2[2] * l2);
  }
  for(int i = 1; i < n2 - 1; i++){
    double d = (double)i/(double)(n2 - 1) * l2;
    glVertex3d(p1[0] + t2[0] * d, 
               p1[1] + t2[1] * d, 
               p1[2] + t2[2] * d);
    glVertex3d(p1[0] + t2[0] * d + t1[0] * l1, 
               p1[1] + t2[1] * d + t1[1] * l1, 
               p1[2] + t2[2] * d + t1[2] * l1);
  }

  glEnd();
  glDisable(GL_LINE_STIPPLE);
  gl2psDisable(GL2PS_LINE_STIPPLE);
}

void drawContext::drawAxis(double xmin, double ymin, double zmin,
                           double xmax, double ymax, double zmax, 
                           int nticks, int mikado)
{
  if(mikado){
    nticks = (nticks - 1) * mikado;
    if(nticks < 1) nticks = 1;
    double dd[3] = {(xmax - xmin) / nticks, 
                    (ymax - ymin) / nticks, 
                    (zmax - zmin) / nticks};
    double axe_color[4];
    glGetDoublev(GL_CURRENT_COLOR, axe_color);
    for(int i = 1; i <= nticks; i++){
      if(i % 2) glColor4dv(axe_color);
      else glColor3f(1, 1, 1);
      double cx[2] = {xmin + (i - 1) * dd[0], xmin + i * dd[0]};
      double cy[2] = {ymin + (i - 1) * dd[1], ymin + i * dd[1]};
      double cz[2] = {zmin + (i - 1) * dd[2], zmin + i * dd[2]};
      drawCylinder(3.5, cx, cy, cz, 1);
    }
    glColor4dv(axe_color);
  }
  else{
    glBegin(GL_LINES);
    glVertex3d(xmin, ymin, zmin); 
    glVertex3d(xmax, ymax, zmax);
    glEnd();
  }
}

void drawContext::drawAxes(int mode, int tics[3], char format[3][256],
                           char label[3][256], double bb[6], int mikado)
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

  double pixelfact = pixel_equiv_x / s[0];

  if(mode == 5){ // draw ruler from xyz_min to xyz_max
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
    drawTics(-1, tics[0], format[0], label[0], orig, end, perp, mikado, pixelfact);
    drawAxis(xmin, ymin, zmin, xmax, ymax, zmax, tics[0], mikado);
    return;
  }
  double xx[3] = {xmax, ymin, zmin};
  double yy[3] = {xmin, ymax, zmin};
  double zz[3] = {xmin, ymin, zmax};
  double dxm[3] = {0., (ymin != ymax) ? -1. : 0., (zmin != zmax) ? -1. : 0.};
  double dym[3] = {(xmin != xmax) ? -1. : 0., 0., (zmin != zmax) ? -1. : 0.};
  double dzm[3] = {(xmin != xmax) ? -1. : 0., (ymin != ymax) ? -1. : 0., 0.};
  
  int nx = (xmin != xmax) ? 
    drawTics(0, tics[0], format[0], label[0], orig, xx, dxm, mikado, pixelfact) : 0;
  int ny = (ymin != ymax) ? 
    drawTics(1, tics[1], format[1], label[1], orig, yy, dym, mikado, pixelfact) : 0;
  int nz = (zmin != zmax) ? 
    drawTics(2, tics[2], format[2], label[2], orig, zz, dzm, mikado, pixelfact) : 0;

  drawAxis(xmin, ymin, zmin, xmax, ymin, zmin, nx, mikado);
  drawAxis(xmin, ymin, zmin, xmin, ymax, zmin, ny, mikado);
  drawAxis(xmin, ymin, zmin, xmin, ymin, zmax, nz, mikado);

  // open box
  if(mode > 1){
    drawAxis(xmin, ymax, zmin, xmax, ymax, zmin, nx, mikado);
    drawAxis(xmax, ymin, zmin, xmax, ymax, zmin, ny, mikado);
    drawAxis(xmax, ymin, zmin, xmax, ymin, zmax, nz, mikado);
    drawAxis(xmin, ymin, zmax, xmax, ymin, zmax, nx, mikado);
    drawAxis(xmin, ymin, zmax, xmin, ymax, zmax, ny, mikado);
    drawAxis(xmin, ymax, zmin, xmin, ymax, zmax, nz, mikado);
  }

  // closed box
  if(mode == 2 || mode == 3){
    drawAxis(xmin, ymax, zmax, xmax, ymax, zmax, nx, mikado);
    drawAxis(xmax, ymin, zmax, xmax, ymax, zmax, ny, mikado);
    drawAxis(xmax, ymax, zmin, xmax, ymax, zmax, nz, mikado);
  }
  
  if(mode > 2){
    drawGridStipple(nx, ny, orig, xx, yy);
    drawGridStipple(ny, nz, orig, yy, zz);
    drawGridStipple(nx, nz, orig, xx, zz);
  }

  if(mode == 3){
    double orig2[3] = {xmax, ymax, zmax};
    double xy[3] = {xmax, ymax, zmin};
    double yz[3] = {xmin, ymax, zmax};
    double xz[3] = {xmax, ymin, zmax};
    if(zmin != zmax) drawGridStipple(nx, ny, orig2, yz, xz);
    if(xmin != xmax) drawGridStipple(ny, nz, orig2, xz, xy);
    if(ymin != ymax) drawGridStipple(nx, nz, orig2, yz, xy);
  }
}

void drawContext::drawAxes(int mode, int tics[3], char format[3][256], 
                           char label[3][256], SBoundingBox3d &bb, int mikado)
{
  double bbox[6] = {bb.min().x(), bb.max().x(),
                    bb.min().y(), bb.max().y(),
                    bb.min().z(), bb.max().z()};
  drawAxes(mode, tics, format, label, bbox, mikado);
}

void drawContext::drawAxes()
{
  bool geometryExists = false;
  for(unsigned int i = 0; i < GModel::list.size(); i++){
    if(!GModel::list[i]->empty()){
      geometryExists = true;
      break;
    }
  }
    
  if(geometryExists && (CTX.draw_bbox || !CTX.mesh.draw)) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
    drawBox(CTX.min[0], CTX.min[1], CTX.min[2], 
            CTX.max[0], CTX.max[1], CTX.max[2]);
    glColor3d(1.,0.,0.);
    for(int j = 0; j < 6; j++)
      if(CTX.geom.clip & (1 << j) || CTX.mesh.clip & (1 << j))
        drawPlaneInBoundingBox(CTX.min[0], CTX.min[1], CTX.min[2],
                               CTX.max[0], CTX.max[1], CTX.max[2],
                               CTX.clip_plane[j][0], CTX.clip_plane[j][1], 
                               CTX.clip_plane[j][2], CTX.clip_plane[j][3]);
  }

  if(CTX.axes){
    glColor4ubv((GLubyte *) & CTX.color.axes);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
    if(!CTX.axes_auto_position){
      drawAxes(CTX.axes, CTX.axes_tics, CTX.axes_format, CTX.axes_label, 
               CTX.axes_position, CTX.axes_mikado);
    }
    else if(geometryExists){
      double bb[6] = {CTX.min[0], CTX.max[0], CTX.min[1], 
                      CTX.max[1], CTX.min[2], CTX.max[2]};
      drawAxes(CTX.axes, CTX.axes_tics, CTX.axes_format, CTX.axes_label, 
               bb, CTX.axes_mikado);
    }
  }

  if(CTX.draw_rotation_center){
    glColor4ubv((GLubyte *) & CTX.color.fg);
    if(CTX.rotation_center_cg)
      drawSphere(CTX.point_size, CTX.cg[0], CTX.cg[1], CTX.cg[2], CTX.geom.light);
    else
      drawSphere(CTX.point_size, CTX.rotation_center[0], CTX.rotation_center[1], 
                 CTX.rotation_center[2], CTX.geom.light);
  }

}

void drawContext::drawSmallAxes()
{
  double l = CTX.small_axes_size;
  double o = CTX.gl_fontsize / 5;

  double cx = CTX.small_axes_pos[0];
  double cy = CTX.small_axes_pos[1];
  fix2dCoordinates(&cx, &cy);

  double xx = l * rot[0];
  double xy = l * rot[1];
  double yx = l * rot[4];
  double yy = l * rot[5];
  double zx = l * rot[8];
  double zy = l * rot[9];

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
