// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "gl2ps.h"
#include "axisTicks.h"
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
      if(render_mode == drawContext::GMSH_SELECT)
        setPickColor(5, PView::list[i]->getIndex());
      else
        gmshColor4ubv((const void *)&opt->color.text2d);
      for(int j = 0; j < data->getNumStrings2D(); j++) {
        double x, y, style;
        std::string str;
        data->getString2D(j, opt->timeStep, str, x, y, style);
        fix2dCoordinates(&x, &y);
        drawString(str, x, y, 0., style);
      }
      if(render_mode == drawContext::GMSH_SELECT) unsetPickColor();
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

// The values a graph is plotted over, from the options and the data alone:
// drawGraph narrows this to the abscissa range when one is asked for.
static void getGraphRange(PView *p, double &min, double &max)
{
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  if(opt->rangeType == PViewOptions::Custom) {
    min = opt->customMin;
    max = opt->customMax;
  }
  else if(opt->rangeType == PViewOptions::PerTimeStep) {
    min = data->getMin(opt->timeStep);
    max = data->getMax(opt->timeStep);
  }
  else {
    min = data->getMin();
    max = data->getMax();
  }
  if(opt->scaleType == PViewOptions::Logarithmic) {
    min = log10(min);
    max = log10(max);
  }
}

// Roughly what a graph spans along its abscissa: enough to know how wide the
// labels of the X axis are before the curves themselves are read.
static void getGraphAbscissa(PView *p, double &min, double &max)
{
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  if(opt->abscissaRangeType == PViewOptions::Custom) {
    min = opt->customAbscissaMin;
    max = opt->customAbscissaMax;
    return;
  }
  if(opt->type == PViewOptions::Plot2DTime) {
    min = data->getTime(0);
    max = data->getTime(data->getNumTimeSteps() - 1);
    return;
  }
  SBoundingBox3d bbox = p->getData()->getBoundingBox();
  double d[3] = {bbox.max().x() - bbox.min().x(), bbox.max().y() - bbox.min().y(),
                 bbox.max().z() - bbox.min().z()};
  if(opt->type == PViewOptions::Plot2DSpace) { // a curvilinear coordinate
    min = 0.;
    max = sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
    return;
  }
  int which = 0;
  if(d[1] > d[0] && d[1] > d[2])
    which = 1;
  else if(d[2] > d[0] && d[2] > d[1])
    which = 2;
  min = which ? (which == 1 ? bbox.min().y() : bbox.min().z()) : bbox.min().x();
  max = which ? (which == 1 ? bbox.max().y() : bbox.max().z()) : bbox.max().x();
}

// The name of the view, with the time step it is drawn at
static std::string getGraphTitle(PView *p)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();
  std::string label = data->getName();
  if(opt->type == PViewOptions::Plot2D ||
     opt->type == PViewOptions::Plot2DSpace) {
    int nt = data->getNumTimeSteps();
    char tmp[256];
    if((opt->showTime == 1 && nt > 1) || opt->showTime == 2) {
      sprintf(tmp, opt->getFormat().c_str(), data->getTime(opt->timeStep));
      label += std::string(" (") + tmp + ")";
    }
    else if((opt->showTime == 3 && nt > 1) || opt->showTime == 4) {
      sprintf(tmp, "%d", opt->timeStep);
      label += std::string(" (") + tmp + ")";
    }
  }
  if(opt->scaleType == PViewOptions::Logarithmic) label = "Log10 " + label;
  return label;
}

// Where the frame of a graph sits in its box and what goes around it: the
// numbers of the two axes, the power of ten they share, the name of the view
// and the label of the abscissa. The margins are what that text measures, so
// that a graph is as large as its box allows and no larger.
struct graphLayout {
  std::vector<axisTick> xt, yt; // where the axes are labelled
  std::string xmult, ymult; // the power of ten their numbers share
  double left = 0., right = 0., top = 0., bottom = 0.; // around the frame
  double out = 0., gap = 0.; // tic out of the frame, tic to its number
  double fontH = 1., fontA = 1., titleH = 1., titleA = 1.;
  double numX = 0., multX = 0., titleX = 0.; // baselines under the frame
  double multY = 0., titleY = 0.; // baselines over the frame
  bool rightLabels = false; // the numbers of the Y axis on the right
  double ss = 1.; // a pixel in the units the graph is drawn in
};

static double stringWidth(const std::string &s)
{
  return drawContext::global()->getStringWidth(s.c_str());
}

// `overlay' is the number of lines of text the graphs already drawn in the
// same frame have put under it, `legend' says that the frame is shared, in
// which case the names of the views go inside it rather than over it. Every
// length is in pixels: drawGraph scales them to the units it draws in.
static void getGraphLayout(PView *p, double xmin, double xmax, double ymin,
                           double ymax, double width, double height,
                           double tic, int overlay, bool legend,
                           graphLayout &l)
{
  PViewOptions *opt = p->getOptions();

  drawContext::global()->setFont(CTX::instance()->glFontEnumTitle,
                                 CTX::instance()->glFontSizeTitle);
  l.titleH = std::max(1., (double)drawContext::global()->getStringHeight());
  l.titleA = l.titleH - drawContext::global()->getStringDescent();
  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  l.fontH = std::max(1., (double)drawContext::global()->getStringHeight());
  l.fontA = l.fontH - drawContext::global()->getStringDescent();
  l.out = 0.5 * tic;
  l.gap = 0.4 * tic;
  l.rightLabels = (overlay != 0);

  if(!opt->axes) { // nothing is written: the curves alone, off the edges
    l.left = l.right = l.top = l.bottom = 1.5 * l.fontH;
    return;
  }

  if(opt->axesTics[0] > 0)
    makeAxisTicks(xmin, xmax, width, l.fontH, true, opt->axesFormat[0],
                  (int)opt->axesTics[0], false, l.xt, l.xmult);
  if(opt->axesTics[1] > 0)
    makeAxisTicks(ymin, ymax, height, l.fontH, false, opt->axesFormat[1],
                  (int)opt->axesTics[1], false, l.yt, l.ymult);

  // the tic marks stick out of the frame, on both sides of a box
  l.left = l.bottom = l.out;
  l.right = l.top = (opt->axes > 1) ? l.out : 0.;

  l.numX = l.out + l.gap + l.fontH + overlay * (l.fontH + tic);
  l.multX = l.numX + 1.2 * l.fontH;
  // the power of ten of the Y axis goes over the frame, clear of the number
  // written at the top of it
  l.multY = l.fontH - 0.3 * l.fontA;
  l.titleY = (l.ymult.size() ? l.multY + l.fontA : 0.25 * l.fontH) + tic;
  l.titleX = (l.xmult.size() ? l.multX : l.numX) + tic + l.titleA;

  if(opt->showScale) {
    // the widest number of the Y axis, and the power of ten over it
    double w = l.ymult.size() ? stringWidth(l.ymult) : 0.;
    for(std::size_t i = 0; i < l.yt.size(); i++)
      w = std::max(w, stringWidth(l.yt[i].label));
    if(w > 0.) {
      double &side = l.rightLabels ? l.right : l.left;
      side = std::max(side, l.out + l.gap + w);
      if(l.ymult.size()) l.top = std::max(l.top, l.multY + l.fontA);
    }
    // the numbers of the X axis stick out at both ends of the frame
    for(std::size_t i = 0; i < l.xt.size(); i++) {
      double w2 = 0.5 * stringWidth(l.xt[i].label);
      l.left = std::max(l.left, w2 - l.xt[i].t * width);
      l.right = std::max(l.right, w2 - (1. - l.xt[i].t) * width);
    }
    if(l.xt.size())
      l.bottom = std::max(l.bottom, (l.xmult.size() ? l.multX : l.numX) +
                                      l.fontH - l.fontA);
  }

  if(opt->axesLabel[0].size())
    l.bottom = std::max(l.bottom, l.titleX + l.titleH - l.titleA);
  // the name of the view goes over the frame, unless it is in the legend
  if(!legend && getGraphTitle(p).size())
    l.top = std::max(l.top, l.titleY + l.titleA);
}

static void scaleGraphLayout(graphLayout &l, double ss)
{
  l.ss = ss;
  double *v[] = {&l.left,  &l.right, &l.top,    &l.bottom, &l.out,
                 &l.gap,   &l.fontH, &l.fontA,  &l.titleH, &l.titleA,
                 &l.numX,  &l.multX, &l.titleX, &l.multY,  &l.titleY};
  for(std::size_t i = 0; i < sizeof(v) / sizeof(v[0]); i++) *v[i] *= ss;
}

// The names of the views sharing a frame, each with a sample of its curve,
// stacked inside its top right corner
static void drawGraphLegend(drawContext *ctx, PView *p, double xleft,
                            double ytop, double width, int nth,
                            const graphLayout &l)
{
  PViewOptions *opt = p->getOptions();
  std::string name = getGraphTitle(p);
  if(name.empty()) return;

  double pad = 0.5 * l.fontH, sample = 2.5 * l.fontH;
  double y = ytop - pad - l.fontA - nth * 1.3 * l.fontH;
  double x = xleft + width - pad - stringWidth(name) * l.ss;
  ctx->drawString(name, x, y, 0.);

  // the sample runs through the colours of the view, as that is what tells
  // the curves apart: they are coloured by their value, not one by one
  double x0 = x - 0.5 * l.fontH - sample, ys = y + 0.35 * l.fontA;
  gmshLineWidth((float)opt->lineWidth);
  if(opt->useStipple)
    gmshLineStipple(opt->stipple[nth % 10][0], opt->stipple[nth % 10][1]);
  const int nbs = 16;
  gmshBegin(GL_LINE_STRIP);
  for(int i = 0; i <= nbs; i++) {
    double t = (double)i / nbs;
    unsigned int col = opt->getColor(opt->tmpMin + t * (opt->tmpMax - opt->tmpMin),
                                     opt->tmpMin, opt->tmpMax, true);
    gmshColor4ubv((const void *)&col);
    gmshVertex2d(x0 + t * sample, ys);
  }
  gmshEnd();
  if(opt->useStipple) gmshLineStippleOff();
  gmshColor4ubv((const void *)&opt->color.axes);
}

static void drawGraphAxes(drawContext *ctx, PView *p, double xleft, double ytop,
                          double width, double height, int overlay, int nth,
                          bool legend, bool inModelCoordinates,
                          const graphLayout &l)
{
  PViewOptions *opt = p->getOptions();

  if(!opt->axes) return;

  if(overlay > 2) return;

  if(width <= 0 || height <= 0) return;

  if(!overlay && !inModelCoordinates) {
    int alpha = CTX::instance()->unpackAlpha(opt->color.background2d);
    if(alpha != 0) {
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_BLEND);
      gmshColor4ubv((const void *)&opt->color.background2d);
      gmshBegin(GL_QUADS);
      gmshVertex2d(xleft, ytop);
      gmshVertex2d(xleft + width, ytop);
      gmshVertex2d(xleft + width, ytop - height);
      gmshVertex2d(xleft, ytop - height);
      gmshEnd();
      glDisable(GL_BLEND);
    }
  }

  double ps = CTX::instance()->pointSize * ctx->highResolutionPixelFactor();

  gmshPointSize((float)ps);
  gl2psPointSize((float)(CTX::instance()->pointSize *
                         CTX::instance()->print.epsPointSizeFactor));

  gmshLineWidth((float)CTX::instance()->lineWidth);
  gl2psLineWidth((float)(CTX::instance()->lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));

  gmshColor4ubv((const void *)&opt->color.axes);

  // bare axes
  if(!overlay) {
    gmshBegin(GL_LINE_STRIP);
    gmshVertex2d(xleft, ytop);
    gmshVertex2d(xleft, ytop - height);
    gmshVertex2d(xleft + width, ytop - height);
    if(opt->axes > 1) {
      gmshVertex2d(xleft + width, ytop);
      gmshVertex2d(xleft, ytop);
    }
    gmshEnd();
  }

  // a halo in the background colour, as a graph often sits over the model
  drawContext::global()->setStringHalo(true);

  // the name of the view
  if(legend)
    drawGraphLegend(ctx, p, xleft, ytop, width, nth, l);
  else
    ctx->drawString(getGraphTitle(p), xleft, ytop + l.titleY, 0,
                    CTX::instance()->glFontTitle,
                    CTX::instance()->glFontEnumTitle,
                    CTX::instance()->glFontSizeTitle, 0);

  double ybot = ytop - height;

  // the label of the abscissa
  if(opt->axesLabel[0].size())
    ctx->drawString(opt->axesLabel[0], xleft + width / 2, ybot - l.titleX, 0,
                    CTX::instance()->glFontTitle,
                    CTX::instance()->glFontEnumTitle,
                    CTX::instance()->glFontSizeTitle, 1);

  // the tics point away from the plot, as in a printed figure
  double out = l.out;
  // the grid is a light shade of the axes colour: it should not compete
  // with the curves
  unsigned int grid = CTX::instance()->packColor(
    CTX::instance()->unpackRed(opt->color.axes),
    CTX::instance()->unpackGreen(opt->color.axes),
    CTX::instance()->unpackBlue(opt->color.axes), 60);

  // y tics, their labels and the horizontal grid
  double ynum = l.rightLabels ? xleft + width + out + l.gap : xleft - out - l.gap;
  for(std::size_t i = 0; i < l.yt.size(); i++) {
    double y = ybot + l.yt[i].t * height;
    gmshBegin(GL_LINES);
    gmshVertex2d(xleft - out, y);
    gmshVertex2d(xleft, y);
    if(opt->axes > 1) {
      gmshVertex2d(xleft + width, y);
      gmshVertex2d(xleft + width + out, y);
    }
    gmshEnd();
    if(opt->axes > 2 && l.yt[i].t > 0. && l.yt[i].t < 1.) {
      gmshColor4ubv((const void *)&grid);
      gmshBegin(GL_LINES);
      gmshVertex2d(xleft, y);
      gmshVertex2d(xleft + width, y);
      gmshEnd();
      gmshColor4ubv((const void *)&opt->color.axes);
    }
    if(opt->showScale) {
      if(l.rightLabels)
        ctx->drawString(l.yt[i].label, ynum, y - l.fontA / 3., 0.);
      else
        ctx->drawStringRight(l.yt[i].label, ynum, y - l.fontA / 3., 0.);
    }
  }
  if(opt->showScale && l.ymult.size()) {
    if(l.rightLabels)
      ctx->drawString(l.ymult, ynum, ytop + l.multY, 0.);
    else
      ctx->drawStringRight(l.ymult, ynum, ytop + l.multY, 0.);
  }

  // x tics, their labels and the vertical grid
  for(std::size_t i = 0; i < l.xt.size(); i++) {
    double x = xleft + l.xt[i].t * width;
    gmshBegin(GL_LINES);
    gmshVertex2d(x, ybot - out);
    gmshVertex2d(x, ybot);
    if(opt->axes > 1) {
      gmshVertex2d(x, ytop);
      gmshVertex2d(x, ytop + out);
    }
    gmshEnd();
    if(opt->axes > 2 && l.xt[i].t > 0. && l.xt[i].t < 1.) {
      gmshColor4ubv((const void *)&grid);
      gmshBegin(GL_LINES);
      gmshVertex2d(x, ybot);
      gmshVertex2d(x, ytop);
      gmshEnd();
      gmshColor4ubv((const void *)&opt->color.axes);
    }
    if(opt->showScale)
      ctx->drawStringCenter(l.xt[i].label, x, ybot - l.numX, 0.);
  }
  if(opt->showScale && l.xmult.size())
    ctx->drawStringRight(l.xmult, xleft + width, ybot - l.multX, 0.);

  drawContext::global()->setStringHalo(false);
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
    gmshColor4ubv((const void *)&col);

    if(singlePoint && ctx->render_mode == drawContext::GMSH_SELECT) {
      ctx->setPickColor(4, (int)getTagForGraph2dDataPoint(SPoint2(x, y)));
    }

    if(numeric) {
      double offset = 3;
      if(inModelCoordinates) offset *= ctx->pixel_equiv_x / ctx->s[0];
      char label[256];
      sprintf(label, opt->getFormat().c_str(), y);
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
      if(singlePoint) gmshBegin(GL_POINTS);
      gmshVertex2d(px, py);
      if(singlePoint) gmshEnd();
    }

    if(singlePoint && ctx->render_mode == drawContext::GMSH_SELECT)
      ctx->unsetPickColor();
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

  gmshPointSize((float)ps);
  gl2psPointSize(
    (float)(opt->pointSize * CTX::instance()->print.epsPointSizeFactor));

  gmshLineWidth((float)opt->lineWidth);
  gl2psLineWidth(
    (float)(opt->lineWidth * CTX::instance()->print.epsLineWidthFactor));

  if(opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Continuous) {
    for(std::size_t i = 0; i < y.size(); i++) {
      if(opt->useStipple) {
        gmshLineStipple(opt->stipple[i % 10][0], opt->stipple[i % 10][1]);
        gl2psEnable(GL2PS_LINE_STIPPLE);
      }
      gmshBegin(GL_LINE_STRIP);
      for(std::size_t j = 0; j < x.size(); j++)
        addGraphPoint(ctx, p, xleft, ytop, width, height, x[j], y[i][j], xmin,
                      xmax, opt->tmpMin, opt->tmpMax, false, false,
                      inModelCoordinates);
      gmshEnd();
      if(opt->useStipple) {
        gmshLineStippleOff();
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
                      int nth = 0, bool legend = false,
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

  // where the text goes around the frame, for the size it ended up with
  double ss = inModelCoordinates ? ctx->pixel_equiv_x / ctx->s[0] : 1.;
  graphLayout l;
  getGraphLayout(p, xmin, xmax, opt->tmpMin, opt->tmpMax, width / ss,
                 height / ss, tic / ss, overlay, legend, l);
  scaleGraphLayout(l, ss);

  drawGraphAxes(ctx, p, xleft, ytop, width, height, overlay, nth, legend,
                inModelCoordinates, l);
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
  double tic = 5; // size of tic marks
  // a margin to the border of the window, in the size of the text, so that a
  // graph keeps its air on a screen whose pixels are half as large
  double font_h = std::max(1., (double)drawContext::global()->getStringHeight());
  double mx = font_h, my = 0.6 * font_h;
  double ss = 1.;
  if(inModelCoordinates) {
    ss = pixel_equiv_x / s[0];
    tic *= ss;
    mx *= ss;
    my *= ss;
  }

  double winw = viewport[2] - viewport[0];
  double winh = viewport[3] - viewport[1];

  // how many graphs share each of the fixed positions: those beyond the
  // first are drawn over the first one, and then the names of the views go
  // in a legend inside the frame rather than over it
  int shared[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(std::size_t i = 0; i < graphs.size(); i++) {
    int a = graphs[i]->getOptions()->autoPosition;
    if(a >= 2 && a <= 11) shared[a]++;
  }

  // what the text of the graphs needs around their frames: measured on a
  // frame as large as the window, so that the margins are never too small
  // for the labels the graphs end up with
  double ml = 0., mr = 0., mt = 0., mb = 0.;
  if(!inModelCoordinates) {
    int rows[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(std::size_t i = 0; i < graphs.size(); i++) {
      PViewOptions *opt = graphs[i]->getOptions();
      int a = opt->autoPosition;
      if(a == 0 || a == 12) continue; // a graph placed by hand
      int overlay = 0;
      bool legend = false;
      if(a >= 2 && a <= 11) {
        overlay = rows[a];
        legend = (shared[a] > 1);
        if(opt->axes) rows[a] += (opt->axesLabel[0].size() ? 2 : 1);
      }
      double xmin, xmax, ymin, ymax;
      getGraphAbscissa(graphs[i], xmin, xmax);
      getGraphRange(graphs[i], ymin, ymax);
      graphLayout l;
      getGraphLayout(graphs[i], xmin, xmax, ymin, ymax, winw, winh, tic,
                     overlay, legend, l);
      ml = std::max(ml, l.left);
      mr = std::max(mr, l.right);
      mt = std::max(mt, l.top);
      mb = std::max(mb, l.bottom);
    }
  }

  //  +------------------winw-------------------+
  //  |          my+mt                          |
  //  |  mx+ml +---w---+ mx+ml+mr +---w---+ mr+mx
  //  |        |       |          |       |     |
  //  |        h       |          |       |     |
  //  |        |       |          |       |     |
  //  |        +-------+          +-------+     |
  // winh      mb+my+mt                         |
  //  |        +-------+          +-------+     |
  //  |        |       |          |       |     |
  //  |        h       |          |       |     |
  //  |        |       |          |       |     |
  //  |        +-------+          +-------+     |
  //  |          mb+my                          |
  //  +-----------------------------------------+

  int overlay[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int nb[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(std::size_t i = 0; i < graphs.size(); i++) {
    double x = viewport[0] + mx + ml;
    double y = viewport[1] + my + mt;
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
        double w = winw - 2 * mx - ml - mr;
        double h = winh - 2 * my - mt - mb;
        drawGraph(this, p, x, viewport[3] - y, w, h, tic);
      }
      else if(graphs.size() == 2) {
        double w = winw - 2 * mx - ml - mr;
        double h = (winh - 3 * my - 2 * (mt + mb)) / 2.;
        if(i == 1) y += (h + my + mt + mb);
        drawGraph(this, p, x, viewport[3] - y, w, h, tic);
      }
      else {
        double w = (winw - 3 * mx - 2 * (ml + mr)) / 2.;
        double h = (winh - 3 * my - 2 * (mt + mb)) / 2.;
        if(i == 1 || i == 3) x += (w + mx + ml + mr);
        if(i == 2 || i == 3) y += (h + my + mt + mb);
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
        w = (winw - 3 * mx - 2 * (ml + mr)) / 2.;
      else
        w = winw - 2 * mx - ml - mr;
      if(a <= 5 || a == 6 || a == 7)
        h = (winh - 3 * my - 2 * (mt + mb)) / 2.;
      else if(a == 11)
        h = (winh - 4 * my - 3 * (mt + mb)) / 3.;
      else
        h = winh - 2 * my - mt - mb;
      if(a == 3 || a == 5 || a == 9) x += (w + mx + ml + mr);
      if(a == 4 || a == 5 || a == 7) y += (h + my + mt + mb);
      drawGraph(this, p, x, viewport[3] - y, w, h, tic, overlay[a], nb[a],
                shared[a] > 1);
      if(opt->axes) {
        overlay[a] += (opt->axesLabel[0].size() ? 2 : 1);
        nb[a]++;
      }
    }
    else if(opt->autoPosition == 12 &&
            inModelCoordinates) { // in model coordinates
      drawGraph(this, p, opt->position[0], opt->position[1] + opt->size[1],
                opt->size[0], opt->size[1], tic, 0, 0, false, true);
    }
  }
}
