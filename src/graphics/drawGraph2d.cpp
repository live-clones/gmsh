// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "gl2ps.h"
#include "Context.h"
#include "Numeric.h"

int drawContext::fix2dCoordinates(double *x, double *y)
{
  int ret =
    (*x > 99999 && *y > 99999) ? 3 : (*y > 99999) ? 2 : (*x > 99999) ? 1 : 0;

  if(*x < 0) // measure from right border
    *x = viewport[2] + *x;
  else if(*x > 99999) // by convention, x-centered
    *x = viewport[2] / 2;

  if(*y < 0) // measure from bottom border
    *y = -(*y);
  else if(*y > 99999) // by convention, y-centered
    *y = viewport[3] / 2.;
  else
    *y = viewport[3] - *y;
  return ret;
}

void drawContext::drawText2d()
{
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->visible && opt->drawStrings && isVisible(PView::list[i])) {
      if(render_mode == drawContext::GMSH_SELECT) {
        glPushName(5);
        glPushName(PView::list[i]->getIndex());
      }
      glColor4ubv((GLubyte *)&opt->color.text2d);
      for(int j = 0; j < data->getNumStrings2D(); j++) {
        double x, y, style;
        std::string str;
        data->getString2D(j, opt->timeStep, str, x, y, style);
        fix2dCoordinates(&x, &y);
        drawString(str, x, y, 0., style);
      }
      if(render_mode == drawContext::GMSH_SELECT) {
        glPopName();
        glPopName();
      }
    }
  }
}

static bool getGraphData(PView *p, std::vector<double> &x, double &xmin,
                         double &xmax, std::vector<std::vector<double> > &y,
                         double &ymin, double &ymax)
{
  PViewData *data = p->getData(true); // use adaptive data if available
  PViewOptions *opt = p->getOptions();

  if(data->hasMultipleMeshes()) return false; // cannot handle multi-mesh

  int numy = 0;
  if(opt->type == PViewOptions::Plot2D ||
     opt->type == PViewOptions::Plot2DSpace) {
    numy = 1;
  }
  else if(opt->type == PViewOptions::Plot2DTime) {
    numy = 0;
    for(int ent = 0; ent < data->getNumEntities(0); ent++) {
      if(data->skipEntity(0, ent)) continue;
      for(int ele = 0; ele < data->getNumElements(0, ent); ele++) {
        if(data->skipElement(0, ent, ele, true)) continue;
        if(opt->skipElement(data->getType(0, ent, ele))) continue;
        if(data->getDimension(0, ent, ele) >= 2) continue;
        numy++;
      }
    }
  }

  if(!numy) return false;
  y.resize(numy);

  bool space = (opt->type == PViewOptions::Plot2D ||
                opt->type == PViewOptions::Plot2DSpace);

  int which2d = 0;
  if(opt->type == PViewOptions::Plot2D) {
    SBoundingBox3d bbox = p->getData()->getBoundingBox();
    SPoint3 min = bbox.min();
    SPoint3 max = bbox.max();
    if(fabs(max.y() - min.y()) > fabs(max.x() - min.x()) &&
       fabs(max.y() - min.y()) > fabs(max.z() - min.z()))
      which2d = 1;
    else if(fabs(max.z() - min.z()) > fabs(max.x() - min.x()) &&
            fabs(max.z() - min.z()) > fabs(max.y() - min.y()))
      which2d = 2;
  }

  SPoint3 p0(0., 0., 0.);

  numy = 0;
  for(int ent = 0; ent < data->getNumEntities(0); ent++) {
    if(data->skipEntity(0, ent)) continue;
    for(int ele = 0; ele < data->getNumElements(0, ent); ele++) {
      if(data->skipElement(0, ent, ele, true)) continue;
      if(opt->skipElement(data->getType(0, ent, ele))) continue;
      if(data->getDimension(0, ent, ele) >= 2) continue;
      int numNodes = data->getNumNodes(0, ent, ele);
      // reorder the nodes for high order line elements
      std::vector<int> reorder(numNodes);
      if(numNodes < 3) {
        for(int j = 0; j < numNodes; j++) reorder[j] = j;
      }
      else {
        reorder[0] = 0;
        reorder[numNodes - 1] = 1;
        for(int j = 1; j < numNodes - 1; j++) reorder[j] = 1 + j;
      }
      for(int ts = space ? opt->timeStep : 0; ts < opt->timeStep + 1; ts++) {
        if(!data->hasTimeStep(ts)) continue;
        int numComp = data->getNumComponents(ts, ent, ele);
        for(int j = 0; j < numNodes; j++) {
          double val[9], xyz[3];
          data->getNode(ts, ent, ele, reorder[j], xyz[0], xyz[1], xyz[2]);
          for(int k = 0; k < numComp; k++)
            data->getValue(ts, ent, ele, reorder[j], k, val[k]);
          double vy = ComputeScalarRep(numComp, val);

          if(opt->type == PViewOptions::Plot2D) {
            x.push_back(xyz[which2d]);
            y[0].push_back(vy);
          }
          else if(opt->type == PViewOptions::Plot2DSpace) {
            // compute curvilinear coordinate
            if(x.empty()) {
              p0 = SPoint3(xyz[0], xyz[1], xyz[2]);
              x.push_back(ComputeScalarRep(3, xyz));
            }
            else {
              SPoint3 p1(xyz[0], xyz[1], xyz[2]);
              x.push_back(x.back() + p0.distance(p1));
              p0 = p1;
            }
            y[0].push_back(vy);
          }
          else {
            if(!numy) x.push_back(data->getTime(ts));
            y[numy].push_back(vy);
          }
        }
      }
      numy++;
    }
  }

  if(x.empty()) return false;

  if(opt->abscissaRangeType == PViewOptions::Custom) {
    std::vector<double> x2;
    std::vector<std::vector<double> > y2(y.size());
    for(std::size_t i = 0; i < x.size(); i++) {
      if(x[i] >= opt->customAbscissaMin && x[i] <= opt->customAbscissaMax) {
        x2.push_back(x[i]);
        for(std::size_t j = 0; j < y2.size(); j++) y2[j].push_back(y[j][i]);
      }
    }
    x = x2;
    y = y2;
  }

  if(space) {
    xmin = xmax = x[0];
    for(std::size_t i = 1; i < x.size(); i++) {
      xmin = std::min(xmin, x[i]);
      xmax = std::max(xmax, x[i]);
    }
  }
  else {
    xmin = data->getTime(0);
    xmax = data->getTime(data->getNumTimeSteps() - 1);
  }

  if(opt->scaleType == PViewOptions::Logarithmic)
    for(std::size_t i = 0; i < y.size(); i++)
      for(std::size_t j = 0; j < y[i].size(); j++) y[i][j] = log10(y[i][j]);

  ymin = VAL_INF;
  ymax = -VAL_INF;
  for(std::size_t i = 0; i < y.size(); i++) {
    for(std::size_t j = 0; j < y[i].size(); j++) {
      ymin = std::min(ymin, y[i][j]);
      ymax = std::max(ymax, y[i][j]);
    }
  }

  return true;
}

static void drawGraphAxes(drawContext *ctx, PView *p, double xleft, double ytop,
                          double width, double height, double xmin, double xmax,
                          double tic, int overlay, bool inModelCoordinates)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  if(!opt->axes) return;

  if(overlay > 2) return;

  if(width <= 0 || height <= 0) return;

  if(!overlay && !inModelCoordinates) {
    int alpha = CTX::instance()->unpackAlpha(opt->color.background2d);
    if(alpha != 0) {
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_BLEND);
      glColor4ubv((GLubyte *)&opt->color.background2d);
      glBegin(GL_QUADS);
      glVertex2d(xleft, ytop);
      glVertex2d(xleft + width, ytop);
      glVertex2d(xleft + width, ytop - height);
      glVertex2d(xleft, ytop - height);
      glEnd();
      glDisable(GL_BLEND);
    }
  }

  // total font height
  double font_h = drawContext::global()->getStringHeight() ?
                    drawContext::global()->getStringHeight() :
                    1;
  // height above ref. point
  double font_a = font_h - drawContext::global()->getStringDescent();

  if(inModelCoordinates) {
    double ss = ctx->pixel_equiv_x / ctx->s[0];
    font_h *= ss;
    font_a *= ss;
  }

  double ps = CTX::instance()->pointSize * ctx->highResolutionPixelFactor();

  glPointSize((float)ps);
  gl2psPointSize((float)(CTX::instance()->pointSize *
                         CTX::instance()->print.epsPointSizeFactor));

  glLineWidth((float)CTX::instance()->lineWidth);
  gl2psLineWidth((float)(CTX::instance()->lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));

  glColor4ubv((GLubyte *)&opt->color.axes);

  // bare axes
  if(!overlay) {
    glBegin(GL_LINE_STRIP);
    glVertex2d(xleft, ytop);
    glVertex2d(xleft, ytop - height);
    glVertex2d(xleft + width, ytop - height);
    if(opt->axes > 1) {
      glVertex2d(xleft + width, ytop);
      glVertex2d(xleft, ytop);
    }
    glEnd();
  }

  // y label
  std::string label = data->getName();
  if(opt->type == PViewOptions::Plot2D ||
     opt->type == PViewOptions::Plot2DSpace) {
    int nt = data->getNumTimeSteps();
    if((opt->showTime == 1 && nt > 1) || opt->showTime == 2) {
      char tmp[256];
      sprintf(tmp, opt->format.c_str(), data->getTime(opt->timeStep));
      label += std::string(" (") + tmp + ")";
    }
    else if((opt->showTime == 3 && nt > 1) || opt->showTime == 4) {
      char tmp[256];
      sprintf(tmp, "%d", opt->timeStep);
      label += std::string(" (") + tmp + ")";
    }
  }
  if(opt->scaleType == PViewOptions::Logarithmic) label = "Log10 " + label;
  ctx->drawString(label, xleft + (overlay ? width : 0), ytop + font_h + tic, 0,
                  CTX::instance()->glFontTitle,
                  CTX::instance()->glFontEnumTitle,
                  CTX::instance()->glFontSizeTitle, 1);

  // x label
  label = opt->axesLabel[0];
  ctx->drawString(
    label, xleft + width / 2,
    ytop - height - 2 * font_h - 2 * tic - overlay * (font_h + tic), 0,
    CTX::instance()->glFontTitle, CTX::instance()->glFontEnumTitle,
    CTX::instance()->glFontSizeTitle, 1);

  // y tics and horizontal grid
  if(opt->nbIso > 0) {
    int nb = opt->nbIso;
    if(opt->showScale && (opt->nbIso * font_h > height))
      nb = (int)floor(height / font_h);
    double dy = height / (double)nb;
    double dv = (opt->tmpMax - opt->tmpMin) / (double)nb;
    for(int i = 0; i < nb + 1; i++) {
      glBegin(GL_LINES);
      glVertex2d(xleft, ytop - i * dy);
      glVertex2d(xleft + tic, ytop - i * dy);
      if(opt->axes > 1) {
        glVertex2d(xleft + width - tic, ytop - i * dy);
        glVertex2d(xleft + width, ytop - i * dy);
      }
      glEnd();
      if(opt->axes > 2 && i != 0 && i != nb) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x1111);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        gl2psLineWidth((float)(1. * CTX::instance()->print.epsLineWidthFactor));
        glBegin(GL_LINES);
        glVertex2d(xleft, ytop - i * dy);
        glVertex2d(xleft + width, ytop - i * dy);
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
        gl2psLineWidth((float)(CTX::instance()->lineWidth *
                               CTX::instance()->print.epsLineWidthFactor));
      }
      if(opt->showScale) {
        char tmp[256];
        sprintf(tmp, opt->format.c_str(),
                (i == nb) ? opt->tmpMin : (opt->tmpMax - i * dv));
        if(!overlay) {
          ctx->drawStringRight(tmp, xleft - 2 * tic,
                               ytop - i * dy - font_a / 3., 0.);
        }
        else {
          ctx->drawString(tmp, xleft + width + 2 * tic,
                          ytop - i * dy - font_a / 3., 0.);
        }
      }
    }
  }

  // x tics and vertical grid
  if(opt->axesTics[0] > 0) {
    int nb = opt->axesTics[0];
    char tmp[256];
    sprintf(tmp, opt->axesFormat[0].c_str(), -M_PI * 1.e4);
    double ww = drawContext::global()->getStringWidth(tmp);
    if(inModelCoordinates) ww *= ctx->pixel_equiv_x / ctx->s[0];
    if((nb - 1) * ww > width) nb = (int)(width / ww) + 1;
    if(nb == 1) nb++;

    double dx = width / (double)(nb - 1);
    double ybot = ytop - height;

    for(int i = 0; i < nb; i++) {
      glBegin(GL_LINES);
      glVertex2d(xleft + i * dx, ybot);
      glVertex2d(xleft + i * dx, ybot + tic);
      if(opt->axes > 1) {
        glVertex2d(xleft + i * dx, ytop);
        glVertex2d(xleft + i * dx, ytop - tic);
      }
      glEnd();
      if(opt->axes > 2 && i != 0 && i != nb - 1) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x1111);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        gl2psLineWidth((float)(1. * CTX::instance()->print.epsLineWidthFactor));
        glBegin(GL_LINES);
        glVertex2d(xleft + i * dx, ytop);
        glVertex2d(xleft + i * dx, ybot);
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
        gl2psLineWidth((float)(CTX::instance()->lineWidth *
                               CTX::instance()->print.epsLineWidthFactor));
      }
      if(opt->showScale) {
        char tmp[256];
        if(nb == 1)
          sprintf(tmp, opt->axesFormat[0].c_str(), xmin);
        else
          sprintf(tmp, opt->axesFormat[0].c_str(),
                  xmin + i * (xmax - xmin) / (double)(nb - 1));
        ctx->drawStringCenter(tmp, xleft + i * dx,
                              ybot - font_h - tic - overlay * (font_h + tic),
                              0.);
      }
    }
  }
}

static std::map<SPoint2, unsigned int> tags;
static std::map<unsigned int, SPoint2> tags_rev;

static unsigned int getTagForGraph2dDataPoint(const SPoint2 &p)
{
  auto it = tags.find(p);
  if(it != tags.end()) return it->second;
  int t = tags.size();
  tags[p] = t;
  tags_rev[t] = p;
  return t;
}

SPoint2 getGraph2dDataPointForTag(unsigned int tag) { return tags_rev[tag]; }

static void addGraphPoint(drawContext *ctx, PView *p, double xleft, double ytop,
                          double width, double height, double x, double y,
                          double xmin, double xmax, double ymin, double ymax,
                          bool numeric, bool singlePoint,
                          bool inModelCoordinates)
{
  PViewOptions *opt = p->getOptions();

  double px = xleft;
  if(xmin != xmax) px += (x - xmin) / (xmax - xmin) * width;

  if(opt->saturateValues) {
    if(y > ymax)
      y = ymax;
    else if(y < ymin)
      y = ymin;
  }

  double ybot = ytop - height;
  double py = ybot;
  if(ymax != ymin) py += (y - ymin) / (ymax - ymin) * height;

  if(y >= ymin && y <= ymax) {
    unsigned int col = opt->getColor(y, ymin, ymax, true);
    glColor4ubv((GLubyte *)&col);

    if(singlePoint && ctx->render_mode == drawContext::GMSH_SELECT) {
      glPushName(4);
      glPushName(getTagForGraph2dDataPoint(SPoint2(x, y)));
    }

    if(numeric) {
      double offset = 3;
      if(inModelCoordinates) offset *= ctx->pixel_equiv_x / ctx->s[0];
      char label[256];
      sprintf(label, opt->format.c_str(), y);
      ctx->drawString(label, px + offset, py + offset, 0.);
    }
    else if(singlePoint && (opt->pointType == 1 || opt->pointType == 3)) {
      double ps = CTX::instance()->pointSize * ctx->highResolutionPixelFactor();
      if(inModelCoordinates)
        ctx->drawSphere(ps, px, py, 0, opt->light);
      else
        ctx->drawSphere(ps, px, py, 0, 10, 10, opt->light);
    }
    else {
      if(singlePoint) glBegin(GL_POINTS);
      glVertex2d(px, py);
      if(singlePoint) glEnd();
    }

    if(singlePoint && ctx->render_mode == drawContext::GMSH_SELECT) {
      glPopName();
      glPopName();
    }
  }
}

static void drawGraphCurves(drawContext *ctx, PView *p, double xleft,
                            double ytop, double width, double height,
                            std::vector<double> &x, double xmin, double xmax,
                            std::vector<std::vector<double> > &y,
                            bool inModelCoordinates)
{
  if(width <= 0 || height <= 0) return;

  PViewOptions *opt = p->getOptions();

  double ps = CTX::instance()->pointSize * ctx->highResolutionPixelFactor();

  glPointSize((float)ps);
  gl2psPointSize(
    (float)(opt->pointSize * CTX::instance()->print.epsPointSizeFactor));

  glLineWidth((float)opt->lineWidth);
  gl2psLineWidth(
    (float)(opt->lineWidth * CTX::instance()->print.epsLineWidthFactor));

  if(opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Continuous) {
    for(std::size_t i = 0; i < y.size(); i++) {
      if(opt->useStipple) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(opt->stipple[i % 10][0], opt->stipple[i % 10][1]);
        gl2psEnable(GL2PS_LINE_STIPPLE);
      }
      glBegin(GL_LINE_STRIP);
      for(std::size_t j = 0; j < x.size(); j++)
        addGraphPoint(ctx, p, xleft, ytop, width, height, x[j], y[i][j], xmin,
                      xmax, opt->tmpMin, opt->tmpMax, false, false,
                      inModelCoordinates);
      glEnd();
      if(opt->useStipple) {
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
      }
    }
  }

  if(opt->intervalsType == PViewOptions::Iso ||
     opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Numeric) {
    for(std::size_t i = 0; i < y.size(); i++)
      for(std::size_t j = 0; j < x.size(); j++)
        addGraphPoint(ctx, p, xleft, ytop, width, height, x[j], y[i][j], xmin,
                      xmax, opt->tmpMin, opt->tmpMax, false, true,
                      inModelCoordinates);
  }

  if(opt->intervalsType == PViewOptions::Numeric) {
    for(std::size_t i = 0; i < y.size(); i++)
      for(std::size_t j = 0; j < x.size(); j++)
        addGraphPoint(ctx, p, xleft, ytop, width, height, x[j], y[i][j], xmin,
                      xmax, opt->tmpMin, opt->tmpMax, true, true,
                      inModelCoordinates);
  }
}

static void drawGraph(drawContext *ctx, PView *p, double xleft, double ytop,
                      double width, double height, double tic, int overlay = 0,
                      bool inModelCoordinates = false)
{
  std::vector<double> x;
  std::vector<std::vector<double> > y;
  double xmin, xmax, ymin, ymax;
  if(!getGraphData(p, x, xmin, xmax, y, ymin, ymax)) return;

  PViewData *data = p->getData(true); // use adaptive data if available
  PViewOptions *opt = p->getOptions();
  if(opt->rangeType == PViewOptions::Custom) {
    opt->tmpMin = opt->customMin;
    opt->tmpMax = opt->customMax;
  }
  else if(opt->rangeType == PViewOptions::PerTimeStep) {
    opt->tmpMin = data->getMin(opt->timeStep);
    opt->tmpMax = data->getMax(opt->timeStep);
  }
  else if(opt->abscissaRangeType == PViewOptions::Custom) {
    // FIXME: should also compute min/max for reduced abscissa range over all
    // steps
    opt->tmpMin = ymin;
    opt->tmpMax = ymax;
  }
  else {
    opt->tmpMin = data->getMin();
    opt->tmpMax = data->getMax();
  }

  if(opt->scaleType == PViewOptions::Logarithmic) {
    opt->tmpMin = log10(opt->tmpMin);
    opt->tmpMax = log10(opt->tmpMax);
  }

  drawGraphAxes(ctx, p, xleft, ytop, width, height, xmin, xmax, tic, overlay,
                inModelCoordinates);
  drawGraphCurves(ctx, p, xleft, ytop, width, height, x, xmin, xmax, y,
                  inModelCoordinates);
}

void drawContext::drawGraph2d(bool inModelCoordinates)
{
  std::vector<PView *> graphs;
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(!data->getDirty() && opt->visible && opt->type != PViewOptions::Plot3D &&
       isVisible(PView::list[i]))
      graphs.push_back(PView::list[i]);
  }
  if(graphs.empty()) return;

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double tic = 5; // size of tic marks and interline
  double mx = 25, my = 5; // x- and y-margin
  double xsep = 0., ysep = drawContext::global()->getStringHeight() + tic;
  char label[1024];
  for(std::size_t i = 0; i < graphs.size(); i++) {
    PViewOptions *opt = graphs[i]->getOptions();
    sprintf(label, opt->format.c_str(), -M_PI * 1.e4);
    xsep = std::max(xsep, drawContext::global()->getStringWidth(label));
  }
  xsep += tic;

  if(inModelCoordinates) {
    double ss = pixel_equiv_x / s[0];
    tic *= ss;
    mx *= ss;
    my *= ss;
    xsep *= ss;
    ysep *= ss;
  }

  //  +------------------winw-------------------+
  //  |       my+3*ysep                         |
  //  |mx+xsep+---w---+mx+2*xsep+---w---+mx+xsep|
  //  |       |       |         |       |       |
  //  |       h       |         |       |       |
  //  |       |       |         |       |       |
  //  |       +-------+         +-------+       |
  // winh     my+5*ysep                         |
  //  |       +-------+         +-------+       |
  //  |       |       |         |       |       |
  //  |       h       |         |       |       |
  //  |       |       |         |       |       |
  //  |       +-------+         +-------+       |
  //  |       my+4*ysep                         |
  //  +-----------------------------------------+

  int overlay[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  double winw = viewport[2] - viewport[0];
  double winh = viewport[3] - viewport[1];
  for(std::size_t i = 0; i < graphs.size(); i++) {
    double x = viewport[0] + mx + xsep;
    double y = viewport[1] + my + 3 * ysep;
    PView *p = graphs[i];
    PViewOptions *opt = graphs[i]->getOptions();
    if(opt->autoPosition == 0 && !inModelCoordinates) { // manual
      double x = opt->position[0], y = opt->position[1];
      int center = fix2dCoordinates(&x, &y);
      drawGraph(this, p, x - (center & 1 ? opt->size[0] / 2. : 0),
                y + (center & 2 ? opt->size[1] / 2. : 0), opt->size[0],
                opt->size[1], tic);
    }
    else if(opt->autoPosition == 1 && !inModelCoordinates) { // automatic
      if(graphs.size() == 1) {
        double w = winw - 2 * mx - 2 * xsep;
        double h = winh - 2 * my - 7 * ysep;
        drawGraph(this, p, x, viewport[3] - y, w, h, tic);
      }
      else if(graphs.size() == 2) {
        double w = winw - 2 * mx - 2 * xsep;
        double h = (winh - 3 * my - 12 * ysep) / 2.;
        if(i == 1) y += (h + my + 5 * ysep);
        drawGraph(this, p, x, viewport[3] - y, w, h, tic);
      }
      else {
        double w = (winw - 3 * mx - 4 * xsep) / 2.;
        double h = (winh - 3 * my - 12 * ysep) / 2.;
        if(i == 1 || i == 3) x += (w + mx + 2 * xsep);
        if(i == 2 || i == 3) y += (h + 5 * ysep);
        drawGraph(this, p, x, viewport[3] - y, w, h, tic);
      }
    }
    else if(opt->autoPosition >= 2 && opt->autoPosition <= 11 &&
            !inModelCoordinates) {
      // top left (2), top right (3), bottom left (4), bottom right (5), top
      // half (6), bottom half (7), left half (8), right half (9), full (10),
      // top third (11)
      int a = opt->autoPosition;
      double w, h;
      if(a <= 5 || a == 8 || a == 9)
        w = (winw - 3 * mx - 4 * xsep) / 2.;
      else
        w = winw - 2 * mx - 2 * xsep;
      if(a <= 5 || a == 6 || a == 7)
        h = (winh - 3 * my - 12 * ysep) / 2.;
      else if(a == 11)
        h = (winh - 3 * my - 12 * ysep) / 3.;
      else
        h = winh - 2 * my - 7 * ysep;
      if(a == 3 || a == 5 || a == 9) x += (w + mx + 2 * xsep);
      if(a == 4 || a == 5 || a == 7) y += (h + my + 5 * ysep);
      drawGraph(this, p, x, viewport[3] - y, w, h, tic,
                overlay[opt->autoPosition]);
      if(opt->axes)
        overlay[opt->autoPosition] += (opt->axesLabel[0].size() ? 2 : 1);
    }
    else if(opt->autoPosition == 12 &&
            inModelCoordinates) { // in model coordinates
      drawGraph(this, p, opt->position[0], opt->position[1] + opt->size[1],
                opt->size[0], opt->size[1], tic, 0, true);
    }
  }
}
