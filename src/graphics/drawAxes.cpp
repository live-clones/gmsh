// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <vector>
#include "drawContext.h"
#include "axisTicks.h"
#include "glMatrix.h"
#include "GModel.h"
#include "Context.h"
#include "glyphList.h"
#include "Numeric.h"
#include "gl2ps.h"

#define SQU(a) ((a) * (a))

// The labels of the axis from p1 to p2, whose values go from value_p1 to
// value_p2 (a ruler, comp -1, is labelled with the distance from p1): about
// n of them, at round values with the automatic format (the ticks of the 2D
// graphs and the colour scales, see axisTicks.h), or n equal steps printed
// with the format given, and the power of ten they share
struct axisLabels {
  std::vector<axisTick> ticks;
  std::string multiplier;
};

static axisLabels makeTicks(drawContext *ctx, int comp, double n,
                            const std::string &format, double p1[3],
                            double p2[3], double value_p1[3],
                            double value_p2[3])
{
  axisLabels l;
  // (View.AxesTicks 0 is what hides the ticks; a ruler always has its ends)
  if(n < 2. && comp >= 0) return l;
  double value_t[3] = {value_p2[0] - value_p1[0], value_p2[1] - value_p1[1],
                       value_p2[2] - value_p1[2]};
  double vmin = (comp < 0) ? 0. : value_p1[comp];
  double vmax = (comp < 0) ? norme(value_t) : value_p2[comp];
  // the length of the axis on screen and the font in the pixels of the
  // window (world2Viewport is in true pixels), the labels side by side along
  // an axis that leans more than it stands
  double hr = ctx->highResolutionPixelFactor();
  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double win1[3], win2[3];
  ctx->world2Viewport(p1, win1);
  ctx->world2Viewport(p2, win2);
  double winl = sqrt(SQU(win2[0] - win1[0]) + SQU(win2[1] - win1[1])) / hr;
  bool horizontal = fabs(win2[0] - win1[0]) >= fabs(win2[1] - win1[1]);
  // (the ends are not labelled: the box of a model is its size plus a
  // tolerance, which would print as -1e-07)
  makeAxisTicks(vmin, vmax, winl, drawContext::global()->getStringHeight(),
                horizontal, format, std::max(1, (int)n - 1), false, l.ticks,
                l.multiplier);
  return l;
}

// The place a string takes in the window, to keep the labels of the axes
// from overlapping
struct labelBox {
  double x0, y0, x1, y1;
};

// A string drawn next to a point of the window (in true pixels, its depth
// kept), on the side of the direction (nx, ny) from it: on the left of the
// point when the direction goes right, centred when it goes up or down, and
// so on. Unless `always', a string that would overlap one drawn before (in
// boxes) is left out; returns whether it was drawn.
static bool placeString(drawContext *ctx, const std::string &str,
                        const double win[3], double nx, double ny,
                        std::vector<labelBox> &boxes, bool always = false)
{
  if(str.empty()) return false;
  double hr = ctx->highResolutionPixelFactor();
  double w = hr * drawContext::global()->getStringWidth(str.c_str());
  double h = hr * drawContext::global()->getStringHeight();
  // where the baseline starts, the text taking about 0.2 h below it and
  // 0.8 h above
  double x = win[0], y = win[1];
  if(nx < -0.3)
    x -= w;
  else if(nx <= 0.3)
    x -= w / 2.;
  if(ny < -0.3)
    y -= 0.8 * h;
  else if(ny <= 0.3)
    y -= h / 3.;
  else
    y += 0.2 * h;
  labelBox b = {x, y - 0.2 * h, x + w, y + 0.8 * h};
  if(!always) {
    for(const labelBox &o : boxes)
      if(b.x0 < o.x1 && o.x0 < b.x1 && b.y0 < o.y1 && o.y0 < b.y1)
        return false;
  }
  boxes.push_back(b);
  double r[3] = {x, y, win[2]}, xyz[3];
  ctx->viewport2World(r, xyz);
  ctx->drawString(str, xyz[0], xyz[1], xyz[2]);
  return true;
}

// The tick marks and the labels of the axis from p1 to p2, on the side of
// the axis on screen away from `centre' (the centre of the box of the axes):
// the labels of two axes meeting at a corner go to different sides of it, as
// on a 2D plot, and a label that would still overlap one drawn before (in
// boxes) is left out. The label of the axis goes after p2, with the power of
// ten of the ticks. Returns where the ticks fall along the axis, 0 at p1 and
// 1 at p2.
static std::vector<double> drawTicks(drawContext *ctx, const axisLabels &labels,
                                     const std::string &label, double p1[3],
                                     double p2[3], double centre[3],
                                     std::vector<labelBox> &boxes)
{
  std::vector<double> positions;
  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double hr = ctx->highResolutionPixelFactor();
  double tick = 10 * hr, gap = 2.5 * hr; // in true pixels

  // the axis on screen, its direction (dx, dy), and the normal (nx, ny) to
  // it that points away from the centre: down and to the left when the axis
  // passes through the centre (a ruler, an axis seen end on)
  double w1[3], w2[3], wc[3];
  ctx->world2Viewport(p1, w1);
  ctx->world2Viewport(p2, w2);
  ctx->world2Viewport(centre, wc);
  double dx = w2[0] - w1[0], dy = w2[1] - w1[1];
  double dl = sqrt(dx * dx + dy * dy);
  double nx = 0., ny = -1.;
  if(dl > 1.) {
    dx /= dl;
    dy /= dl;
    nx = -dy;
    ny = dx;
    double side = nx * (0.5 * (w1[0] + w2[0]) - wc[0]) +
                  ny * (0.5 * (w1[1] + w2[1]) - wc[1]);
    if(side < -1. || (fabs(side) <= 1. && (ny > 0. || (ny == 0. && nx > 0.)))) {
      nx = -nx;
      ny = -ny;
    }
  }
  else {
    dx = 1.;
    dy = 0.;
  }

  std::string end = label;
  if(labels.multiplier.size())
    end += (end.empty() ? "" : " ") + labels.multiplier;
  double we[3] = {w2[0] + dx * (tick + gap), w2[1] + dy * (tick + gap), w2[2]};
  placeString(ctx, end, we, dx, dy, boxes, true);

  for(const axisTick &tk : labels.ticks) {
    positions.push_back(tk.t);
    double p[3] = {p1[0] + tk.t * (p2[0] - p1[0]), p1[1] + tk.t * (p2[1] - p1[1]),
                   p1[2] + tk.t * (p2[2] - p1[2])};
    double wp[3], wq[3], q[3];
    ctx->world2Viewport(p, wp);
    for(int i = 0; i < 3; i++) wq[i] = wp[i];
    wq[0] += nx * tick;
    wq[1] += ny * tick;
    ctx->viewport2World(wq, q);
    gmshBegin(GL_LINES);
    gmshVertex3d(p[0], p[1], p[2]);
    gmshVertex3d(q[0], q[1], q[2]);
    gmshEnd();
    double wl[3] = {wp[0] + nx * (tick + gap), wp[1] + ny * (tick + gap), wp[2]};
    placeString(ctx, tk.label, wl, nx, ny, boxes);
  }
  return positions;
}

// the lines of a grid between the ticks of its two axes (at t1 along p1->p2
// and t2 along p1->p3), the ends left out
static void drawGridStipple(const std::vector<double> &t1s,
                            const std::vector<double> &t2s, double p1[3],
                            double p2[3], double p3[3])
{
  double t1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double t2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double l1 = norme(t1);
  double l2 = norme(t2);

  gmshLineStipple(1, 0x1111);
  gl2psEnable(GL2PS_LINE_STIPPLE);
  gmshBegin(GL_LINES);

  for(double t : t1s) {
    if(t <= 0. || t >= 1.) continue;
    double d = t * l1;
    gmshVertex3d(p1[0] + t1[0] * d, p1[1] + t1[1] * d, p1[2] + t1[2] * d);
    gmshVertex3d(p1[0] + t1[0] * d + t2[0] * l2, p1[1] + t1[1] * d + t2[1] * l2,
               p1[2] + t1[2] * d + t2[2] * l2);
  }
  for(double t : t2s) {
    if(t <= 0. || t >= 1.) continue;
    double d = t * l2;
    gmshVertex3d(p1[0] + t2[0] * d, p1[1] + t2[1] * d, p1[2] + t2[2] * d);
    gmshVertex3d(p1[0] + t2[0] * d + t1[0] * l1, p1[1] + t2[1] * d + t1[1] * l1,
               p1[2] + t2[2] * d + t1[2] * l1);
  }

  gmshEnd();
  gmshLineStippleOff();
  gl2psDisable(GL2PS_LINE_STIPPLE);
}

// an axis, as a line, or as Mikado sticks: each interval between its ticks
// (at ticks along it, 0 at the start and 1 at the end) in mikado segments of
// alternating colours
void drawContext::drawAxis(double xmin, double ymin, double zmin, double xmax,
                           double ymax, double zmax,
                           const std::vector<double> &ticks, int mikado)
{
  if(mikado) {
    // the sticks from end to end, cut at the ticks
    std::vector<double> t = {0.};
    for(double v : ticks)
      if(v > 0. && v < 1.) t.push_back(v);
    t.push_back(1.);
    // the axis colour, which the ticks alternate with white (a core profile
    // has no current colour to query)
    unsigned int axeColor = glyphCurrentColor();
    const unsigned int white = 0xffffffffu;
    glyphList g;
    g.reserve(GLYPH_CYLINDER, (t.size() - 1) * mikado);
    double radius = 3.5 * pixel_equiv_x / s[0];
    int k = 0;
    for(std::size_t i = 1; i < t.size(); i++) {
      for(int j = 0; j < mikado; j++, k++) {
        double a = t[i - 1] + (t[i] - t[i - 1]) * j / mikado;
        double b = t[i - 1] + (t[i] - t[i - 1]) * (j + 1) / mikado;
        double cx[2] = {xmin + a * (xmax - xmin), xmin + b * (xmax - xmin)};
        double cy[2] = {ymin + a * (ymax - ymin), ymin + b * (ymax - ymin)};
        double cz[2] = {zmin + a * (zmax - zmin), zmin + b * (zmax - zmin)};
        g.addCylinder(cx, cy, cz, radius, radius, (k % 2) ? white : axeColor);
      }
    }
    g.draw(this, 1);
    gmshColor4ubv((const void *)&axeColor);
  }
  else {
    gmshBegin(GL_LINES);
    gmshVertex3d(xmin, ymin, zmin);
    gmshVertex3d(xmax, ymax, zmax);
    gmshEnd();
  }
}

void drawContext::drawAxes(int mode, double ticks[3], std::string format[3],
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

  // the labels go away from the centre of the box, and none overlaps another
  double centre[3] = {0.5 * (xmin + xmax), 0.5 * (ymin + ymax),
                      0.5 * (zmin + zmax)};
  std::vector<labelBox> boxes;

  if(mode == 5) { // draw ruler from xyz_min to xyz_max
    double end[3] = {xmax, ymax, zmax};
    double value_end[3] = {value_xmax, value_ymax, value_zmax};
    axisLabels l =
      makeTicks(this, -1, ticks[0], format[0], orig, end, value_orig, value_end);
    std::vector<double> t =
      drawTicks(this, l, label[0], orig, end, centre, boxes);
    drawAxis(xmin, ymin, zmin, xmax, ymax, zmax, t, mikado);
    return;
  }
  double xx[3] = {xmax, ymin, zmin};
  double yy[3] = {xmin, ymax, zmin};
  double zz[3] = {xmin, ymin, zmax};
  double value_xx[3] = {value_xmax, value_ymin, value_zmin};
  double value_yy[3] = {value_xmin, value_ymax, value_zmin};
  double value_zz[3] = {value_xmin, value_ymin, value_zmax};
  // the three axes from the corner they share, X first: at the corner the
  // label of an axis that would overlap one of X is left out
  std::vector<double> nx, ny, nz;
  if(xmin != xmax)
    nx = drawTicks(this, makeTicks(this, 0, ticks[0], format[0], orig, xx,
                                   value_orig, value_xx),
                   label[0], orig, xx, centre, boxes);
  if(ymin != ymax)
    ny = drawTicks(this, makeTicks(this, 1, ticks[1], format[1], orig, yy,
                                   value_orig, value_yy),
                   label[1], orig, yy, centre, boxes);
  if(zmin != zmax)
    nz = drawTicks(this, makeTicks(this, 2, ticks[2], format[2], orig, zz,
                                   value_orig, value_zz),
                   label[2], orig, zz, centre, boxes);

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

void drawContext::drawAxes(int mode, double ticks[3], std::string format[3],
                           std::string label[3], SBoundingBox3d &bb, int mikado,
                           SBoundingBox3d &value_bb)
{
  double bbox[6] = {bb.min().x(), bb.max().x(), bb.min().y(),
                    bb.max().y(), bb.min().z(), bb.max().z()};
  double value_bbox[6] = {value_bb.min().x(), value_bb.max().x(),
                          value_bb.min().y(), value_bb.max().y(),
                          value_bb.min().z(), value_bb.max().z()};
  drawAxes(mode, ticks, format, label, bbox, mikado, value_bbox);
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
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
    gmshLineWidth((float)CTX::instance()->lineWidth);
    gl2psLineWidth((float)(CTX::instance()->lineWidth *
                           CTX::instance()->print.epsLineWidthFactor));
    drawBox(CTX::instance()->min[0], CTX::instance()->min[1],
            CTX::instance()->min[2], CTX::instance()->max[0],
            CTX::instance()->max[1], CTX::instance()->max[2]);
    gmshColor3d(1., 0., 0.);
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
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.axes);
    gmshLineWidth((float)CTX::instance()->lineWidth);
    gl2psLineWidth((float)(CTX::instance()->lineWidth *
                           CTX::instance()->print.epsLineWidthFactor));
    if(!CTX::instance()->axesAutoPosition) {
      drawAxes(CTX::instance()->axes, CTX::instance()->axesTicks,
               CTX::instance()->axesFormat, CTX::instance()->axesLabel,
               CTX::instance()->axesPosition, CTX::instance()->axesMikado,
               CTX::instance()->axesForceValue ? CTX::instance()->axesValue :
                                                 CTX::instance()->axesPosition);
    }
    else {
      double bb[6] = {CTX::instance()->min[0], CTX::instance()->max[0],
                      CTX::instance()->min[1], CTX::instance()->max[1],
                      CTX::instance()->min[2], CTX::instance()->max[2]};
      drawAxes(CTX::instance()->axes, CTX::instance()->axesTicks,
               CTX::instance()->axesFormat, CTX::instance()->axesLabel, bb,
               CTX::instance()->axesMikado,
               CTX::instance()->axesForceValue ? CTX::instance()->axesValue :
                                                 bb);
    }
  }

  if(CTX::instance()->drawRotationCenter) {
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
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
    gmshMatrixMode(GMSH_MODELVIEW);
    gmshLoadIdentity();
    double eye[3] = {camera.position.x, camera.position.y, camera.position.z};
    double target[3] = {camera.target.x, camera.target.y, camera.target.z};
    double up[3] = {camera.up.x, camera.up.y, camera.up.z};
    double fvViewMatrix[16];
    glMatrix::lookAt(eye, target, up, fvViewMatrix);
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
  gmshLineWidth((float)CTX::instance()->lineWidth);
  gl2psLineWidth((float)(CTX::instance()->lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.smallAxes);

  gmshBegin(GL_LINES);
  gmshVertex2d(cx, cy);
  gmshVertex2d(cx + xx, cy + xy);
  gmshVertex2d(cx, cy);
  gmshVertex2d(cx + yx, cy + yy);
  gmshVertex2d(cx, cy);
  gmshVertex2d(cx + zx, cy + zy);
  gmshEnd();
  drawString("X", cx + xx + o, cy + xy + o, 0.);
  drawString("Y", cx + yx + o, cy + yy + o, 0.);
  drawString("Z", cx + zx + o, cy + zy + o, 0.);
}
