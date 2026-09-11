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
  // a pick pass draws no text (see drawString): a view is picked through
  // what it draws of its data, not through a label lying over the model
  if(render_mode == drawContext::GMSH_SELECT) return;

  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->visible && opt->drawStrings && isVisible(PView::list[i])) {
      gmshColor4ubv((const void *)&opt->color.text2d);
      for(int j = 0; j < data->getNumStrings2D(); j++) {
        double x, y, style;
        std::string str;
        data->getString2D(j, opt->timeStep, str, x, y, style);
        fix2dCoordinates(&x, &y);
        drawString(str, x, y, 0., style);
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

// What a graph does in the frame it is drawn in: the first one drawn there
// owns the frame, the grid and the axes, and the ones drawn over it add an
// axis of their own only where their range differs, so that a shared frame
// does not end up with two grids and two rows of numbers saying the same
// thing. Their names then go in a legend inside the frame.
struct graphPlace {
  bool first = true; // draws the frame, the grid and the axes
  bool legend = false; // several graphs share the frame
  int nth = 0; // its line in the legend
  bool xaxis = true, yaxis = true; // its own numbers under and beside it
  int xrow = 0; // that many rows of numbers under the frame's own
  double yshift = 0.; // that far out on the right of the frame
  bool ytwin = false; // another graph writes numbers on its right
};

// Where the frame of a graph sits in its box and what goes around it: the
// numbers of the two axes, the power of ten they share, the name of the view
// and the label of the abscissa. The margins are what that text measures, so
// that a graph is as large as its box allows and no larger.
struct graphLayout {
  std::vector<axisTick> xt, yt; // where the axes are labelled
  std::string xmult, ymult; // the power of ten their numbers share
  double left = 0., right = 0., top = 0., bottom = 0.; // around the frame
  double out = 0., gap = 0.; // tick out of the frame, tick to its number
  double fontH = 1., fontA = 1., titleH = 1., titleA = 1.;
  double numX = 0., multX = 0., titleX = 0.; // baselines under the frame
  double multY = 0., titleY = 0.; // baselines over the frame
  double ynum = 0.; // how wide the numbers of the Y axis are
  double ss = 1.; // a pixel in the units the graph is drawn in
};

static double stringWidth(const std::string &s)
{
  return drawContext::global()->getStringWidth(s.c_str());
}

// Every length is in pixels: drawGraph scales them to the units it draws in.
static void getGraphLayout(PView *p, double xmin, double xmax, double ymin,
                           double ymax, double width, double height,
                           double tick, const graphPlace &pl, graphLayout &l)
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
  // the tick marks, and the space between them and their numbers, are those
  // of a colour scale, so that a graph and a scale in the same window match
  l.out = l.gap = 0.4 * CTX::instance()->glFontSize;

  if(!opt->axes) { // nothing is written: the curves alone, off the edges
    l.left = l.right = l.top = l.bottom = 1.5 * l.fontH;
    return;
  }

  // the ends of the ranges are labelled as on a colour scale: the frame says
  // where an axis stops, only the number says at what value
  if(pl.xaxis && opt->axesTicks[0] > 0)
    makeAxisTicks(xmin, xmax, width, l.fontH, true, opt->axesFormat[0],
                  (int)opt->axesTicks[0], true, l.xt, l.xmult);
  if(pl.yaxis && opt->axesTicks[1] > 0)
    makeAxisTicks(ymin, ymax, height, l.fontH, false, opt->axesFormat[1],
                  (int)opt->axesTicks[1], true, l.yt, l.ymult);

  // the tick marks stick out of the frame, on both sides of a box
  l.left = l.bottom = l.out;
  l.right = l.top = (opt->axes > 1) ? l.out : 0.;

  l.numX = l.out + l.gap + l.fontH + pl.xrow * (l.fontH + tick);
  l.multX = l.numX + 1.2 * l.fontH;
  // the power of ten of the Y axis goes over the frame, clear of the number
  // written at the top of it
  l.multY = l.fontH - 0.2 * l.fontA;
  l.titleY = (l.ymult.size() ? l.multY + l.fontA : 0.25 * l.fontH) + tick;
  l.titleX = (l.xmult.size() ? l.multX : l.numX) + tick + l.titleA;

  if(opt->showScale) {
    // the widest number of the Y axis, and the power of ten over it
    l.ynum = l.ymult.size() ? stringWidth(l.ymult) : 0.;
    for(std::size_t i = 0; i < l.yt.size(); i++)
      l.ynum = std::max(l.ynum, stringWidth(l.yt[i].label));
    if(l.ynum > 0.) {
      double need = l.out + l.gap + l.ynum;
      if(pl.first)
        l.left = std::max(l.left, need);
      else
        l.right = std::max(l.right, pl.yshift + need);
      if(l.ymult.size()) l.top = std::max(l.top, l.multY + l.fontA);
    }
    // the numbers of the X axis stick out at both ends of the frame, and
    // those of the Y axis over and under its corners
    for(std::size_t i = 0; i < l.xt.size(); i++) {
      double w = 0.5 * stringWidth(l.xt[i].label);
      l.left = std::max(l.left, w - l.xt[i].t * width);
      l.right = std::max(l.right, w - (1. - l.xt[i].t) * width);
    }
    for(std::size_t i = 0; i < l.yt.size(); i++) {
      l.top = std::max(l.top, (l.yt[i].t - 1.) * height + 2. * l.fontA / 3.);
      l.bottom = std::max(l.bottom, -l.yt[i].t * height + l.fontH -
                                      2. * l.fontA / 3.);
    }
    if(l.xt.size())
      l.bottom = std::max(l.bottom, (l.xmult.size() ? l.multX : l.numX) +
                                      l.fontH - l.fontA);
  }

  if(pl.first && opt->axesLabel[0].size())
    l.bottom = std::max(l.bottom, l.titleX + l.titleH - l.titleA);
  // the name of the view goes over the frame, unless it is in the legend
  if(!pl.legend && getGraphTitle(p).size())
    l.top = std::max(l.top, l.titleY + l.titleA);
}

static void scaleGraphLayout(graphLayout &l, double ss)
{
  l.ss = ss;
  double *v[] = {&l.left,  &l.right, &l.top,    &l.bottom, &l.out,
                 &l.gap,   &l.fontH, &l.fontA,  &l.titleH, &l.titleA,
                 &l.numX,  &l.multX, &l.titleX, &l.multY,  &l.titleY,
                 &l.ynum};
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
                          double width, double height, bool inModelCoordinates,
                          const graphPlace &pl, const graphLayout &l)
{
  PViewOptions *opt = p->getOptions();

  if(!opt->axes) return;

  if(width <= 0 || height <= 0) return;

  if(pl.first && !inModelCoordinates) {
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
  if(pl.first) {
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
  if(pl.legend)
    drawGraphLegend(ctx, p, xleft, ytop, width, pl.nth, l);
  else
    ctx->drawString(getGraphTitle(p), xleft, ytop + l.titleY, 0,
                    CTX::instance()->glFontTitle,
                    CTX::instance()->glFontEnumTitle,
                    CTX::instance()->glFontSizeTitle, 0);

  double ybot = ytop - height;

  // the label of the abscissa
  if(pl.first && opt->axesLabel[0].size())
    ctx->drawString(opt->axesLabel[0], xleft + width / 2, ybot - l.titleX, 0,
                    CTX::instance()->glFontTitle,
                    CTX::instance()->glFontEnumTitle,
                    CTX::instance()->glFontSizeTitle, 1);

  // the ticks point away from the plot, as in a printed figure
  double out = l.out;
  // the grid is a faint shade of the axes colour: it should not compete with
  // the curves, so it is blended into whatever is behind the graph
  unsigned int grid = CTX::instance()->packColor(
    CTX::instance()->unpackRed(opt->color.axes),
    CTX::instance()->unpackGreen(opt->color.axes),
    CTX::instance()->unpackBlue(opt->color.axes), 60);
  bool blend = (opt->axes > 2);
  if(blend) {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
  }

  // y ticks, their numbers and the horizontal grid: on the left of the frame
  // for the graph that owns it, on its right, past what is already written
  // there, for a graph drawn over it
  double yaxis = pl.first ? xleft : xleft + width + pl.yshift;
  for(std::size_t i = 0; i < l.yt.size(); i++) {
    double y = ybot + l.yt[i].t * height;
    gmshBegin(GL_LINES);
    if(pl.first) {
      gmshVertex2d(xleft - out, y);
      gmshVertex2d(xleft, y);
      if(opt->axes > 1 && !pl.ytwin) { // the twin axis has the right side
        gmshVertex2d(xleft + width, y);
        gmshVertex2d(xleft + width + out, y);
      }
    }
    else {
      gmshVertex2d(yaxis, y);
      gmshVertex2d(yaxis + out, y);
    }
    gmshEnd();
    if(pl.first && opt->axes > 2 && l.yt[i].t > 0. && l.yt[i].t < 1.) {
      gmshColor4ubv((const void *)&grid);
      gmshBegin(GL_LINES);
      gmshVertex2d(xleft, y);
      gmshVertex2d(xleft + width, y);
      gmshEnd();
      gmshColor4ubv((const void *)&opt->color.axes);
    }
    if(opt->showScale) {
      if(pl.first)
        ctx->drawStringRight(l.yt[i].label, xleft - out - l.gap,
                             y - l.fontA / 3., 0.);
      else
        ctx->drawString(l.yt[i].label, yaxis + out + l.gap, y - l.fontA / 3.,
                        0.);
    }
  }
  if(opt->showScale && l.ymult.size()) {
    if(pl.first)
      ctx->drawStringRight(l.ymult, xleft - out - l.gap, ytop + l.multY, 0.);
    else
      ctx->drawString(l.ymult, yaxis + out + l.gap, ytop + l.multY, 0.);
  }

  // x ticks, their numbers and the vertical grid
  for(std::size_t i = 0; i < l.xt.size(); i++) {
    double x = xleft + l.xt[i].t * width;
    if(pl.first) {
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
    }
    if(opt->showScale)
      ctx->drawStringCenter(l.xt[i].label, x, ybot - l.numX, 0.);
  }
  if(blend) glDisable(GL_BLEND);

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
                      double width, double height, double tick,
                      const graphPlace &pl, bool inModelCoordinates = false)
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
                 height / ss, tick / ss, pl, l);
  scaleGraphLayout(l, ss);

  drawGraphAxes(ctx, p, xleft, ytop, width, height, inModelCoordinates, pl, l);
  drawGraphCurves(ctx, p, xleft, ytop, width, height, x, xmin, xmax, y,
                  inModelCoordinates);
}

// two ranges the same to the eye: an axis for the second would repeat the
// first
static bool sameRange(double a0, double a1, double b0, double b1)
{
  double d = std::max(fabs(a1 - a0), fabs(b1 - b0));
  if(d <= 0.) return (a0 == b0 && a1 == b1);
  return fabs(a0 - b0) < 1.e-6 * d && fabs(a1 - b1) < 1.e-6 * d;
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
  double tick = 5; // the space between two lines of text
  // a margin to the border of the window, in the size of the text, so that a
  // graph keeps its air on a screen whose pixels are half as large
  double font_h = std::max(1., (double)drawContext::global()->getStringHeight());
  double mx = font_h, my = 0.6 * font_h;
  double ss = 1.;
  if(inModelCoordinates) {
    ss = pixel_equiv_x / s[0];
    tick *= ss;
    mx *= ss;
    my *= ss;
  }

  double winw = viewport[2] - viewport[0];
  double winh = viewport[3] - viewport[1];

  // how many graphs share each of the fixed positions: those beyond the
  // first are drawn in its frame, and then the names of the views go in a
  // legend inside it rather than over it
  int shared[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(std::size_t i = 0; i < graphs.size(); i++) {
    PViewOptions *opt = graphs[i]->getOptions();
    int a = opt->autoPosition;
    if(a >= 2 && a <= 11 && opt->axes) shared[a]++;
  }

  // what each graph does in its frame, and what the text of all of them
  // needs around it: measured on a frame as large as the window, so that
  // the margins are never too small for the labels they end up with
  std::vector<graphPlace> place(graphs.size());
  double ml = 0., mr = 0., mt = 0., mb = 0.;
  int nw = 1, nh = 1; // as many graphs side by side, and one over the other
  if(!inModelCoordinates) {
    int nb[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int owner[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int rows[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double shift[12] = {0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.};
    double x0[12], x1[12], y0[12], y1[12];
    for(std::size_t i = 0; i < graphs.size(); i++) {
      PViewOptions *opt = graphs[i]->getOptions();
      int a = opt->autoPosition;
      if(a == 0 || a == 12) continue; // a graph placed by hand
      if(!opt->axes) continue; // nothing is written around it
      graphPlace &pl = place[i];
      double xmin, xmax, ymin, ymax;
      getGraphAbscissa(graphs[i], xmin, xmax);
      getGraphRange(graphs[i], ymin, ymax);
      if(a >= 2 && a <= 11) {
        pl.legend = (shared[a] > 1);
        pl.nth = nb[a];
        pl.first = !nb[a];
        if(pl.first) {
          owner[a] = (int)i;
          x0[a] = xmin; x1[a] = xmax; y0[a] = ymin; y1[a] = ymax;
        }
        else {
          // an axis of its own only where it would not repeat the frame's,
          // and only for the first few: past that they cannot be read
          pl.xaxis = !sameRange(xmin, xmax, x0[a], x1[a]) && nb[a] <= 2;
          pl.yaxis = !sameRange(ymin, ymax, y0[a], y1[a]) && nb[a] <= 3;
          if(pl.xaxis) pl.xrow = ++rows[a]; // under the frame's own numbers
          pl.yshift = shift[a];
          if(pl.yaxis) place[owner[a]].ytwin = true;
        }
        nb[a]++;
      }
      graphLayout l;
      getGraphLayout(graphs[i], xmin, xmax, ymin, ymax, winw, winh, tick, pl, l);
      if(!pl.first && pl.yaxis && l.ynum > 0.)
        shift[a] = pl.yshift + l.out + 2 * l.gap + l.ynum;
      ml = std::max(ml, l.left);
      mr = std::max(mr, l.right);
      mt = std::max(mt, l.top);
      mb = std::max(mb, l.bottom);
      if(a == 1)
        nw = nh = (graphs.size() > 2) ? 2 : 1;
      else {
        if(a <= 5 || a == 8 || a == 9) nw = 2;
        if(a <= 5 || a == 6 || a == 7) nh = std::max(nh, 2);
        if(a == 11) nh = 3;
      }
    }
    // text wider than the window would leave nothing to draw in: the graphs
    // keep two thirds of it, whatever their labels measure
    double needw = nw * (ml + mr) + (nw + 1) * mx;
    if(needw > 0.67 * winw) {
      double f = 0.67 * winw / needw;
      ml *= f;
      mr *= f;
      mx *= f;
    }
    double needh = nh * (mt + mb) + (nh + 1) * my;
    if(needh > 0.67 * winh) {
      double f = 0.67 * winh / needh;
      mt *= f;
      mb *= f;
      my *= f;
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
                opt->size[1], tick, place[i]);
    }
    else if(opt->autoPosition == 1 && !inModelCoordinates) { // automatic
      if(graphs.size() == 1) {
        double w = winw - 2 * mx - ml - mr;
        double h = winh - 2 * my - mt - mb;
        drawGraph(this, p, x, viewport[3] - y, w, h, tick, place[i]);
      }
      else if(graphs.size() == 2) {
        double w = winw - 2 * mx - ml - mr;
        double h = (winh - 3 * my - 2 * (mt + mb)) / 2.;
        if(i == 1) y += (h + my + mt + mb);
        drawGraph(this, p, x, viewport[3] - y, w, h, tick, place[i]);
      }
      else {
        double w = (winw - 3 * mx - 2 * (ml + mr)) / 2.;
        double h = (winh - 3 * my - 2 * (mt + mb)) / 2.;
        if(i == 1 || i == 3) x += (w + mx + ml + mr);
        if(i == 2 || i == 3) y += (h + my + mt + mb);
        drawGraph(this, p, x, viewport[3] - y, w, h, tick, place[i]);
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
      drawGraph(this, p, x, viewport[3] - y, w, h, tick, place[i]);
    }
    else if(opt->autoPosition == 12 &&
            inModelCoordinates) { // in model coordinates
      drawGraph(this, p, opt->position[0], opt->position[1] + opt->size[1],
                opt->size[0], opt->size[1], tick, place[i], true);
    }
  }
}
