// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <iostream>
#include "GmshGlobal.h"
#include <string.h>
#include "drawContext.h"
#include "Trackball.h"
#include "GModel.h"
#include "Context.h"
#include "Numeric.h"
#include "gl2ps.h"

#define SQU(a) ((a) * (a))

static int drawTics(drawContext *ctx, int comp, double n, std::string &format,
                    std::string &label, double p1[3], double p2[3],
                    double perp[3], int mikado, double pixelfact,
                    double value_p1[3], double value_p2[3])
{
  // draws n tic marks (in direction perp) and labels along the line p1->p2

  double t[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double l = norme(t);
  double value_t[3] = {value_p2[0] - value_p1[0], value_p2[1] - value_p1[1],
                       value_p2[2] - value_p1[2]};
  double value_l = norme(value_t);
  double w = 10 * pixelfact; // tic marks are 10 pixels long
  double w2 = w * 1.25; // distance to labels

  // draw label at the end of the axis
  ctx->drawString(label, p2[0] + t[0] * w2, p2[1] + t[1] * w2,
                  p2[2] + t[2] * w2);

  // return number of tics in special cases
  if(n < 2.) return 0;
  if(format.empty()) return n;

  // select perp direction automatically if it is not provided
  double lp = norme(perp);
  if(!lp) {
    switch(comp) {
    case 0: perp[1] = -1.; break;
    case 1: perp[0] = -1.; break;
    case 2: perp[0] = 1.; break;
    default: break;
    }
  }

  // reduce number of tics depending on font size and length of axis on screen
  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  char tmp[256];
  sprintf(tmp, format.c_str(), -M_PI * 1.e4);
  double win1[3], win2[3];
  ctx->world2Viewport(p1, win1);
  ctx->world2Viewport(p2, win2);
  double winl = sqrt(SQU(win2[0] - win1[0]) + SQU(win2[1] - win1[1]));
  double strl = drawContext::global()->getStringWidth(tmp);
  if((n - 1) * strl > winl) n = (int)(winl / strl) + 1;
  if(n <= 1) {
    if(comp < 0) // ruler
      n = 2;
    else
      return 0;
  }

  // draw n tics
  double step = l / (double)(n - 1);
  double value_step = value_l / (double)(n - 1);

  for(int i = 0; i < n; i++) {
    double d = i * step;
    double p[3] = {p1[0] + t[0] * d, p1[1] + t[1] * d, p1[2] + t[2] * d};
    double q[3] = {p[0] + perp[0] * w, p[1] + perp[1] * w, p[2] + perp[2] * w};
    double r[3] = {p[0] + perp[0] * w2, p[1] + perp[1] * w2,
                   p[2] + perp[2] * w2};

    double value_d = i * value_step;
    double value_p[3] = {value_p1[0] + value_t[0] * value_d,
                         value_p1[1] + value_t[1] * value_d,
                         value_p1[2] + value_t[2] * value_d};

    glBegin(GL_LINES);
    glVertex3d(p[0], p[1], p[2]);
    glVertex3d(q[0], q[1], q[2]);
    glEnd();

    // draw tic labels
    if(comp < 0) // display the length value (ruler-mode, starting at 0)
      sprintf(tmp, format.c_str(), value_d);
    else // display the coordinate value
      sprintf(tmp, format.c_str(), value_p[comp]);
    double winp[3], winr[3];
    ctx->world2Viewport(p, winp);
    ctx->world2Viewport(r, winr);
    if(fabs(winr[0] - winp[0]) < 2.) // center align
      winr[0] -= drawContext::global()->getStringWidth(tmp) / 2.;
    else if(winr[0] < winp[0]) // right align
      winr[0] -= drawContext::global()->getStringWidth(tmp);
    if(fabs(winr[1] - winp[1]) < 2.) // center align
      winr[1] -= drawContext::global()->getStringHeight() / 3.;
    else if(winr[1] < winp[1]) // top align
      winr[1] -= drawContext::global()->getStringHeight();
    ctx->viewport2World(winr, r);
    ctx->drawString(tmp, r[0], r[1], r[2]);
  }

  return n;
}

static void drawGridStipple(int n1, int n2, double p1[3], double p2[3],
                            double p3[3])
{
  double t1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double t2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double l1 = norme(t1);
  double l2 = norme(t2);

  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x1111);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  glBegin(GL_LINES);

  for(int i = 1; i < n1 - 1; i++) {
    double d = (double)i / (double)(n1 - 1) * l1;
    glVertex3d(p1[0] + t1[0] * d, p1[1] + t1[1] * d, p1[2] + t1[2] * d);
    glVertex3d(p1[0] + t1[0] * d + t2[0] * l2, p1[1] + t1[1] * d + t2[1] * l2,
               p1[2] + t1[2] * d + t2[2] * l2);
  }
  for(int i = 1; i < n2 - 1; i++) {
    double d = (double)i / (double)(n2 - 1) * l2;
    glVertex3d(p1[0] + t2[0] * d, p1[1] + t2[1] * d, p1[2] + t2[2] * d);
    glVertex3d(p1[0] + t2[0] * d + t1[0] * l1, p1[1] + t2[1] * d + t1[1] * l1,
               p1[2] + t2[2] * d + t1[2] * l1);
  }

  glEnd();
  glDisable(GL_LINE_STIPPLE);
  gl2psDisable(GL2PS_LINE_STIPPLE);
}

void drawContext::drawAxis(double xmin, double ymin, double zmin, double xmax,
                           double ymax, double zmax, int ntics, int mikado)
{
  if(mikado) {
    ntics = (ntics - 1) * mikado;
    if(ntics < 1) ntics = 1;
    double dd[3] = {(xmax - xmin) / ntics, (ymax - ymin) / ntics,
                    (zmax - zmin) / ntics};
    double axe_color[4];
    glGetDoublev(GL_CURRENT_COLOR, axe_color);
    for(int i = 1; i <= ntics; i++) {
      if(i % 2)
        glColor4dv(axe_color);
      else
        glColor3f(1, 1, 1);
      double cx[2] = {xmin + (i - 1) * dd[0], xmin + i * dd[0]};
      double cy[2] = {ymin + (i - 1) * dd[1], ymin + i * dd[1]};
      double cz[2] = {zmin + (i - 1) * dd[2], zmin + i * dd[2]};
      drawCylinder(3.5, cx, cy, cz, 1);
    }
    glColor4dv(axe_color);
  }
  else {
    glBegin(GL_LINES);
    glVertex3d(xmin, ymin, zmin);
    glVertex3d(xmax, ymax, zmax);
    glEnd();
  }
}

void drawContext::drawAxes(int mode, double tics[3], std::string format[3],
                           std::string label[3], double bb[6], int mikado,
                           double value_bb[6])
{
  // mode 0: nothing
  //      1: axes
  //      2: box
  //      3: full grid
  //      4: open grid
  //      5: ruler

  if((mode < 1) || (bb[0] == bb[1] && bb[2] == bb[3] && bb[4] == bb[5])) return;

  double xmin = bb[0], xmax = bb[1];
  double ymin = bb[2], ymax = bb[3];
  double zmin = bb[4], zmax = bb[5];
  double orig[3] = {xmin, ymin, zmin};

  double value_xmin = value_bb[0], value_xmax = value_bb[1];
  double value_ymin = value_bb[2], value_ymax = value_bb[3];
  double value_zmin = value_bb[4], value_zmax = value_bb[5];
  double value_orig[3] = {value_xmin, value_ymin, value_zmin};

  double pixelfact = pixel_equiv_x / s[0];

  if(mode == 5) { // draw ruler from xyz_min to xyz_max
    double end[3] = {xmax, ymax, zmax};
    double dir[3] = {xmax - xmin, ymax - ymin, zmax - zmin};
    double perp[3];
    if((fabs(dir[0]) >= fabs(dir[1]) && fabs(dir[0]) >= fabs(dir[2])) ||
       (fabs(dir[1]) >= fabs(dir[0]) && fabs(dir[1]) >= fabs(dir[2]))) {
      perp[0] = dir[1];
      perp[1] = -dir[0];
      perp[2] = 0.;
    }
    else {
      perp[0] = 0.;
      perp[1] = dir[2];
      perp[2] = -dir[1];
    }
    double value_end[3] = {value_xmax, value_ymax, value_zmax};
    drawTics(this, -1, tics[0], format[0], label[0], orig, end, perp, mikado,
             pixelfact, value_orig, value_end);
    drawAxis(xmin, ymin, zmin, xmax, ymax, zmax, tics[0], mikado);
    return;
  }
  double xx[3] = {xmax, ymin, zmin};
  double yy[3] = {xmin, ymax, zmin};
  double zz[3] = {xmin, ymin, zmax};
  double value_xx[3] = {value_xmax, value_ymin, value_zmin};
  double value_yy[3] = {value_xmin, value_ymax, value_zmin};
  double value_zz[3] = {value_xmin, value_ymin, value_zmax};
  double dxm[3] = {0., (ymin != ymax) ? -1. : 0., (zmin != zmax) ? -1. : 0.};
  double dym[3] = {(xmin != xmax) ? -1. : 0., 0., (zmin != zmax) ? -1. : 0.};
  double dzm[3] = {(xmin != xmax) ? -1. : 0., (ymin != ymax) ? -1. : 0., 0.};

  int nx = (xmin != xmax) ?
             drawTics(this, 0, tics[0], format[0], label[0], orig, xx, dxm,
                      mikado, pixelfact, value_orig, value_xx) :
             0;
  int ny = (ymin != ymax) ?
             drawTics(this, 1, tics[1], format[1], label[1], orig, yy, dym,
                      mikado, pixelfact, value_orig, value_yy) :
             0;
  int nz = (zmin != zmax) ?
             drawTics(this, 2, tics[2], format[2], label[2], orig, zz, dzm,
                      mikado, pixelfact, value_orig, value_zz) :
             0;

  drawAxis(xmin, ymin, zmin, xmax, ymin, zmin, nx, mikado);
  drawAxis(xmin, ymin, zmin, xmin, ymax, zmin, ny, mikado);
  drawAxis(xmin, ymin, zmin, xmin, ymin, zmax, nz, mikado);

  // open box
  if(mode > 1) {
    drawAxis(xmin, ymax, zmin, xmax, ymax, zmin, nx, mikado);
    drawAxis(xmax, ymin, zmin, xmax, ymax, zmin, ny, mikado);
    drawAxis(xmax, ymin, zmin, xmax, ymin, zmax, nz, mikado);
    drawAxis(xmin, ymin, zmax, xmax, ymin, zmax, nx, mikado);
    drawAxis(xmin, ymin, zmax, xmin, ymax, zmax, ny, mikado);
    drawAxis(xmin, ymax, zmin, xmin, ymax, zmax, nz, mikado);
  }

  // closed box
  if(mode == 2 || mode == 3) {
    drawAxis(xmin, ymax, zmax, xmax, ymax, zmax, nx, mikado);
    drawAxis(xmax, ymin, zmax, xmax, ymax, zmax, ny, mikado);
    drawAxis(xmax, ymax, zmin, xmax, ymax, zmax, nz, mikado);
  }

  if(mode > 2) {
    drawGridStipple(nx, ny, orig, xx, yy);
    drawGridStipple(ny, nz, orig, yy, zz);
    drawGridStipple(nx, nz, orig, xx, zz);
  }

  if(mode == 3) {
    double orig2[3] = {xmax, ymax, zmax};
    double xy[3] = {xmax, ymax, zmin};
    double yz[3] = {xmin, ymax, zmax};
    double xz[3] = {xmax, ymin, zmax};
    if(zmin != zmax) drawGridStipple(nx, ny, orig2, yz, xz);
    if(xmin != xmax) drawGridStipple(ny, nz, orig2, xz, xy);
    if(ymin != ymax) drawGridStipple(nx, nz, orig2, yz, xy);
  }
}

void drawContext::drawAxes(int mode, double tics[3], std::string format[3],
                           std::string label[3], SBoundingBox3d &bb, int mikado,
                           SBoundingBox3d &value_bb)
{
  double bbox[6] = {bb.min().x(), bb.max().x(), bb.min().y(),
                    bb.max().y(), bb.min().z(), bb.max().z()};
  double value_bbox[6] = {value_bb.min().x(), value_bb.max().x(),
                          value_bb.min().y(), value_bb.max().y(),
                          value_bb.min().z(), value_bb.max().z()};
  drawAxes(mode, tics, format, label, bbox, mikado, value_bbox);
}

void drawContext::drawAxes()
{
  bool geometryExists = false;
  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    if(!GModel::list[i]->empty()) {
      geometryExists = true;
      break;
    }
  }

  if(geometryExists &&
     (CTX::instance()->drawBBox || !CTX::instance()->mesh.draw)) {
    glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
    glLineWidth((float)CTX::instance()->lineWidth);
    gl2psLineWidth((float)(CTX::instance()->lineWidth *
                           CTX::instance()->print.epsLineWidthFactor));
    drawBox(CTX::instance()->min[0], CTX::instance()->min[1],
            CTX::instance()->min[2], CTX::instance()->max[0],
            CTX::instance()->max[1], CTX::instance()->max[2]);
    glColor3d(1., 0., 0.);
    for(int j = 0; j < 6; j++)
      if(CTX::instance()->geom.clip & (1 << j) ||
         CTX::instance()->mesh.clip & (1 << j))
        drawPlaneInBoundingBox(
          CTX::instance()->min[0], CTX::instance()->min[1],
          CTX::instance()->min[2], CTX::instance()->max[0],
          CTX::instance()->max[1], CTX::instance()->max[2],
          CTX::instance()->clipPlane[j][0], CTX::instance()->clipPlane[j][1],
          CTX::instance()->clipPlane[j][2], CTX::instance()->clipPlane[j][3]);
  }

  if(CTX::instance()->axes) {
    glColor4ubv((GLubyte *)&CTX::instance()->color.axes);
    glLineWidth((float)CTX::instance()->lineWidth);
    gl2psLineWidth((float)(CTX::instance()->lineWidth *
                           CTX::instance()->print.epsLineWidthFactor));
    if(!CTX::instance()->axesAutoPosition) {
      drawAxes(CTX::instance()->axes, CTX::instance()->axesTics,
               CTX::instance()->axesFormat, CTX::instance()->axesLabel,
               CTX::instance()->axesPosition, CTX::instance()->axesMikado,
               CTX::instance()->axesForceValue ? CTX::instance()->axesValue :
                                                 CTX::instance()->axesPosition);
    }
    else {
      double bb[6] = {CTX::instance()->min[0], CTX::instance()->max[0],
                      CTX::instance()->min[1], CTX::instance()->max[1],
                      CTX::instance()->min[2], CTX::instance()->max[2]};
      drawAxes(CTX::instance()->axes, CTX::instance()->axesTics,
               CTX::instance()->axesFormat, CTX::instance()->axesLabel, bb,
               CTX::instance()->axesMikado,
               CTX::instance()->axesForceValue ? CTX::instance()->axesValue :
                                                 bb);
    }
  }

  if(CTX::instance()->drawRotationCenter) {
    glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
    if(CTX::instance()->rotationCenterCg)
      drawSphere(CTX::instance()->pointSize, CTX::instance()->cg[0],
                 CTX::instance()->cg[1], CTX::instance()->cg[2],
                 CTX::instance()->geom.light);
    else
      drawSphere(CTX::instance()->pointSize, CTX::instance()->rotationCenter[0],
                 CTX::instance()->rotationCenter[1],
                 CTX::instance()->rotationCenter[2],
                 CTX::instance()->geom.light);
  }
}

void drawContext::drawSmallAxes()
{
  double l = CTX::instance()->smallAxesSize;
  double o = CTX::instance()->glFontSize / 5;

  double cx = CTX::instance()->smallAxesPos[0];
  double cy = CTX::instance()->smallAxesPos[1];
  fix2dCoordinates(&cx, &cy);

  double xx, xy, yx, yy, zx, zy;

  if(CTX::instance()->camera) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera.position.x, camera.position.y, camera.position.z,
              camera.target.x, camera.target.y, camera.target.z, camera.up.x,
              camera.up.y, camera.up.z);
    glPushMatrix();
    glPopMatrix();
    float fvViewMatrix[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, fvViewMatrix);
    glLoadIdentity();
    xx = l * fvViewMatrix[0];
    xy = l * fvViewMatrix[1];
    yx = l * fvViewMatrix[4];
    yy = l * fvViewMatrix[5];
    zx = l * fvViewMatrix[8];
    zy = l * fvViewMatrix[9];
    ///

    ///
  }
  else {
    xx = l * rot[0];
    xy = l * rot[1];
    yx = l * rot[4];
    yy = l * rot[5];
    zx = l * rot[8];
    zy = l * rot[9];
  }
  glLineWidth((float)CTX::instance()->lineWidth);
  gl2psLineWidth((float)(CTX::instance()->lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));
  glColor4ubv((GLubyte *)&CTX::instance()->color.smallAxes);

  glBegin(GL_LINES);
  glVertex2d(cx, cy);
  glVertex2d(cx + xx, cy + xy);
  glVertex2d(cx, cy);
  glVertex2d(cx + yx, cy + yy);
  glVertex2d(cx, cy);
  glVertex2d(cx + zx, cy + zy);
  glEnd();
  drawString("X", cx + xx + o, cy + xy + o, 0.);
  drawString("Y", cx + yx + o, cy + yy + o, 0.);
  drawString("Z", cx + zx + o, cy + zy + o, 0.);
}
