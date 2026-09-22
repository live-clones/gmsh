// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "Context.h"
#include "GmshMessage.h"
#include "gl2ps.h"
#include "axisTicks.h"

// where a scale is labelled: the same as an axis
typedef axisTick scaleTick;

// the pixels per unit of the drawing, for the snapping below
static double _pixelFactor = 1.;

// Where t (0 to 1) falls along a bar of the given length: a pixel inside
// the outline at either end, the same for every interval type so that
// nothing moves when the type changes (the first and last iso marks, 3
// pixels wide, then overlap the outline, which is drawn over them). Snapped
// to a pixel boundary, so that the edge of a box and the line drawn at it
// (half a pixel further) fall on the same pixel.
static double alongBar(double t, double length)
{
  // in pixels: the outline, a line centred on the bar's ends, covers the
  // pixel before the first and the last one of the bar, so the inside runs
  // from the second pixel to the one before the last
  double n = length * _pixelFactor;
  double col = 1. + floor(t * (n - 3.) + 0.5);
  return col / _pixelFactor;
}

// a line drawn at a box edge: on the pixel that starts there
static double lineAt(double edge) { return edge + 0.5 / _pixelFactor; }

// Where a tick mark and its label go along a bar of the given length. The
// ends of the range are marked on the outline of the box itself: they are
// what it stops at, and a mark a pixel inside it, at the first and the last
// colour, reads as a misalignment.
static double tickAt(double t, double length)
{
  if(t <= 0.) return 0.;
  if(t >= 1.) return length;
  return lineAt(alongBar(t, length));
}

// The labels of the scale. Iso: one per iso value, centred on it; discrete
// or numeric: the boundaries of the bands; both every k-th as needed to fit.
// Anything else is an axis over the range, round numbers when the user asked
// for no particular format, round powers of ten when the scale is
// logarithmic.
static void scaleTicks(PViewOptions *opt, double min, double max,
                       double length, double fontH, bool horizontal,
                       std::vector<scaleTick> &ticks, std::string &multiplier)
{
  ticks.clear();
  multiplier.clear();
  bool defaultFormat = opt->format.empty();
  int type = opt->getScaleType(min, max);
  bool linear = (type == PViewOptions::Linear);
  // a symmetric logarithmic scale is logarithmic outside this and linear
  // inside it; the labels of the other two have no threshold to keep clear
  double thr = (type == PViewOptions::SymmetricLogarithmic) ?
                 opt->getScaleThreshold(min, max) : 0.;
  int nbIso = std::max(1, opt->nbIso);
  char str[128];

  if(min > max || (defaultFormat &&
                   opt->intervalsType == PViewOptions::Continuous)) {
    // a range given the other way round shows nothing: only its two ends,
    // which is what an axis over it comes down to
    if(linear || min > max) {
      makeAxisTicks(min, max, length, fontH, horizontal, opt->format, 0, true,
                    ticks, multiplier);
      return;
    }
  }

  // A format of the user's own labels a continuous scale the way it labels
  // filled iso-values, at the boundaries of the bands the map would be cut
  // into (as the scales always did before the automatic labels): the round
  // numbers are the automatic format's business.
  if(opt->intervalsType == PViewOptions::Iso ||
     opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Numeric ||
     (!defaultFormat && opt->intervalsType == PViewOptions::Continuous)) {
    bool iso = (opt->intervalsType == PViewOptions::Iso);
    int n = iso ? nbIso : nbIso + 1;
    int exp = 0, decimals = 0;
    if(defaultFormat && linear) {
      // the decimals the spacing calls for when they print every value
      // exactly (round bands), else three significant digits of the largest
      // value and enough to tell the neighbours apart
      exp = axisSharedExponent(min, max);
      int sig = axisDecimals(std::max(fabs(min), fabs(max)), exp);
      decimals = sig;
      if(n > 1 && max != min && linear) {
        double spacing = fabs(max - min) / (n - 1);
        int d = std::max(0, -(int)floor(log10(spacing / pow(10., exp)) + 1e-9));
        bool exact = true;
        for(int i = 0; i < n && exact; i++) {
          double m = opt->getScaleValue(i, n, min, max) / pow(10., exp);
          double sc = pow(10., d);
          if(fabs(m * sc - floor(m * sc + 0.5)) > 1.e-6) exact = false;
        }
        decimals = exact ? d : std::max(sig, std::min(d, sig + 2));
      }
      multiplier = axisMultiplier(exp);
    }
    for(int i = 0; i < n; i++) {
      scaleTick tk;
      tk.v = opt->getScaleValue(i, n, min, max);
      // the first and last iso values are the ends of the range: at the
      // ends of the bar
      tk.t = iso ? (nbIso > 1 ? (double)i / (nbIso - 1) : 0.5) :
                   (double)i / nbIso;
      if(defaultFormat)
        tk.label = linear ?
                     axisNumber(tk.v, decimals, exp) :
                     axisLogNumber(tk.v,
                                   axisLogPowers(thr > 0. ? thr : min,
                                                 std::max(fabs(min),
                                                          fabs(max))));
      else {
        snprintf(str, sizeof(str), opt->getFormat().c_str(), tk.v);
        tk.label = str;
      }
      ticks.push_back(tk);
    }
    axisThinTicks(ticks, length, fontH, horizontal);
    return;
  }

  if(linear) {
    makeAxisTicks(min, max, length, fontH, horizontal, opt->format, 0, true,
                  ticks, multiplier);
    return;
  }

  // logarithmic: the powers of ten of the range, laid out by their
  // logarithm, on one side of zero or on both
  if(thr > 0.)
    makeSymLogAxisTicks(min, max, thr, length, fontH, horizontal, opt->format,
                        defaultFormat ? 0 : nbIso, true, ticks, multiplier);
  else
    makeLogAxisTicks(min, max, length, fontH, horizontal, opt->format,
                     defaultFormat ? 0 : nbIso, true, ticks, multiplier);
}

// a string with a halo in the background colour, so that it reads over the
// data; align 0 left, 1 centred, 2 right
static void haloString(drawContext *ctx, const std::string &s, double x,
                       double y, int align, bool title = false)
{
  CTX *c = CTX::instance();
  const std::string &font = title ? c->glFontTitle : c->glFont;
  int fontEnum = title ? c->glFontEnumTitle : c->glFontEnum;
  int size = title ? c->glFontSizeTitle : c->glFontSize;
  gmshColor4ubv((GLubyte *)&c->color.text);
  drawContext::global()->setStringHalo(true);
  ctx->drawString(s, x, y, 0., font, fontEnum, size, align);
  drawContext::global()->setStringHalo(false);
}

static void drawScaleBar(PView *p, double xmin, double ymin, double width,
                         double height, double tick, int horizontal,
                         const std::vector<scaleTick> &ticks)
{
  PViewOptions *opt = p->getOptions();

  int nb = opt->nbIso ? opt->nbIso : 1;
  // the edges of the boxes go through the mapping of the ticks, so that the
  // colour changes sit under the tick marks; the ends stay on the bar's
  double length = horizontal ? width : height;
  auto edge = [&](int i) {
    return (i <= 0) ? 0. :
           (i >= nb) ? length : alongBar((double)i / nb, length);
  };
  // a point of the bar, given how far along it lies and how far across:
  // which of the two is x and which is y is all a vertical bar changes
  double across = horizontal ? height : width;
  auto at = [&](double along, double a) {
    horizontal ? gmshVertex2d(xmin + along, ymin + a) :
                 gmshVertex2d(xmin + a, ymin + along);
  };

  bool iso = (opt->intervalsType == PViewOptions::Iso);
  // nothing is drawn with a range given the other way round: an empty bar
  int n = (opt->tmpMin > opt->tmpMax) ? 0 : opt->nbIso;
  if(iso) gmshLineWidth(3.);
  for(int i = 0; i < n; i++) {
    if(opt->intervalsType == PViewOptions::Discrete ||
       opt->intervalsType == PViewOptions::Numeric) {
      unsigned int col = opt->getColor(i, opt->nbIso);
      gmshColor4ubv((GLubyte *)&col);
      gmshBegin(GL_QUADS);
      at(edge(i), 0.);
      at(edge(i + 1), 0.);
      at(edge(i + 1), across);
      at(edge(i), across);
      gmshEnd();
    }
    else if(opt->intervalsType == PViewOptions::Continuous) {
      gmshBegin(GL_QUADS);
      double dv = (opt->tmpMax - opt->tmpMin) / (opt->nbIso ? opt->nbIso : 1);
      double v1 = opt->tmpMin + i * dv;
      unsigned int col1 = opt->getColor(v1, opt->tmpMin, opt->tmpMax, true);
      gmshColor4ubv((GLubyte *)&col1);
      at(edge(i), across);
      at(edge(i), 0.);
      double v2 = opt->tmpMin + (i + 1) * dv;
      unsigned int col2 = opt->getColor(v2, opt->tmpMin, opt->tmpMax, true);
      gmshColor4ubv((GLubyte *)&col2);
      at(edge(i + 1), 0.);
      at(edge(i + 1), across);
      gmshEnd();
    }
    else {
      // an iso value: a thick mark in its colour, the first and last ones on
      // the ends of the bar, which they are the values of
      unsigned int col = opt->getColor(i, opt->nbIso);
      gmshColor4ubv((GLubyte *)&col);
      double t = (opt->nbIso > 1) ? (double)i / (opt->nbIso - 1) : 0.5;
      gmshBegin(GL_LINES);
      double along = lineAt(alongBar(t, length));
      at(along, 0.);
      at(along, across);
      gmshEnd();
    }
  }

  // an outline, and a tick mark at each label
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.text);
  gmshLineWidth(1.);
  gmshBegin(GL_LINE_LOOP);
  gmshVertex2d(xmin, ymin);
  gmshVertex2d(xmin + width, ymin);
  gmshVertex2d(xmin + width, ymin + height);
  gmshVertex2d(xmin, ymin + height);
  gmshEnd();
  gmshBegin(GL_LINES);
  for(std::size_t i = 0; i < ticks.size(); i++) {
    double out = (ticks[i].minor ? 0.2 : 0.4) * tick;
    double along = tickAt(ticks[i].t, length);
    at(along, across);
    at(along, across + out);
  }
  gmshEnd();
}

static void drawScaleValues(drawContext *ctx, PView *p, double xmin,
                            double ymin, double width, double height,
                            double tick, int horizontal,
                            const std::vector<scaleTick> &ticks)
{
  PViewOptions *opt = p->getOptions();
  if(!opt->nbIso) return;

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double font_a =
    drawContext::global()->getStringHeight() -
    drawContext::global()->getStringDescent(); // height above ref pt

  for(std::size_t i = 0; i < ticks.size(); i++) {
    if(ticks[i].minor) continue; // a subdivision: the mark says enough
    // centred on its tick mark
    if(horizontal)
      haloString(ctx, ticks[i].label, xmin + tickAt(ticks[i].t, width),
                 ymin + height + tick, 1); // adjust for compactness
    else
      haloString(ctx, ticks[i].label, xmin + width + 0.8 * tick,
                 ymin + tickAt(ticks[i].t, height) - font_a / 3., 0);
  }
}

// the data a scale is labelled from: that of another view when it is asked
// for (which is also what the values shown come from)
static PViewData *scaleData(PView *p)
{
  PViewOptions *opt = p->getOptions();
  if(opt->externalViewIndex >= 0 &&
     opt->externalViewIndex < (int)PView::list.size())
    return PView::list[opt->externalViewIndex]->getData();
  return p->getData();
}

// what is written under the name of a scale: the time, the step or the part
// of a harmonic view, as View.ShowTime asks
static std::string scaleSubtitle(PView *p)
{
  PViewOptions *opt = p->getOptions();
  PViewData *data = scaleData(p);
  char sub[512] = "";
  int nt = data->getNumTimeSteps();
  int n0 = data->getFirstNonEmptyTimeStep();
  int n = (nt - n0 > 0) ? nt - n0 : 1;
  char time[256];
  snprintf(time, sizeof(time), opt->getFormat().c_str(), data->getTime(opt->timeStep));
  const char *part = ((opt->timeStep - n0) % 2) ? "imaginary" : "real";
  int choice = opt->showTime;
  if(choice == 3) { // automatic
    if(n == 1)
      choice = 0; // nothing
    else if(n == 2)
      choice = 2; // harmonic
    else
      choice = 5; // multi-step data
  }
  switch(choice) {
  case 1: snprintf(sub, sizeof(sub), "time %s", time); break;
  case 2:
    if(n <= 2)
      snprintf(sub, sizeof(sub), "%s part", part);
    else
      snprintf(sub, sizeof(sub), "harmonic %s (%s part)", time, part);
    break;
  case 4: snprintf(sub, sizeof(sub), "step %d", opt->timeStep); break;
  case 5:
    snprintf(sub, sizeof(sub), "step %d of %d", opt->timeStep, data->getNumTimeSteps() - 1);
    break;
  case 6: snprintf(sub, sizeof(sub), "eigenvalue %s", time); break;
  case 7: snprintf(sub, sizeof(sub), "eigenvalue %s (%s part)", time, part); break;
  default: break;
  }
  return sub;
}

// the title of the scale: the name of the view, and below it on a line of
// its own what the time or step is, when there is one, with the power of
// ten the labels share at the end of that line
static void drawScaleLabel(drawContext *ctx, PView *p, double xmin, double ymin,
                           double width, double height, double tick,
                           int horizontal, const std::string &multiplier)
{
  PViewData *data = scaleData(p);

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double font_h = drawContext::global()->getStringHeight();
  drawContext::global()->setFont(CTX::instance()->glFontEnumTitle,
                                 CTX::instance()->glFontSizeTitle);
  double title_h = drawContext::global()->getStringHeight();

  std::string sub = scaleSubtitle(p);
  std::string name = data->getName();

  if(horizontal) {
    double y = ymin + height + tick + 1.3 * font_h; // adjust for compactness
    if(sub.size() || multiplier.size()) {
      if(sub.size()) haloString(ctx, sub, xmin + width / 2., y, 1);
      if(multiplier.size()) haloString(ctx, multiplier, xmin + width, y, 2);
      y += 1.1 * title_h; // adjust for compactness
    }
    haloString(ctx, name, xmin + width / 2., y, 1, true);
  }
  else {
    double y = ymin - 2 * font_h;
    haloString(ctx, name, xmin, y, 0, true);
    if(sub.size())
      haloString(ctx, sub, xmin, y - 1.2 * font_h, 0); // adjust for compactness
    if(multiplier.size())
      haloString(ctx, multiplier, xmin + width + 0.8 * tick,
                 ymin + height + 1.2 * font_h,
                 0);
  }
}

static void drawScale(drawContext *ctx, PView *p, double xmin, double ymin,
                      double width, double height, double tick, int horizontal)
{
  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  if(opt->externalViewIndex >= 0) {
    opt->tmpMin = opt->externalMin;
    opt->tmpMax = opt->externalMax;
  }
  else if(opt->rangeType == PViewOptions::Custom) {
    opt->tmpMin = opt->customMin;
    opt->tmpMax = opt->customMax;
  }
  else if(opt->rangeType == PViewOptions::PerTimeStep) {
    opt->tmpMin = data->getMin(opt->timeStep);
    opt->tmpMax = data->getMax(opt->timeStep);
  }
  else {
    opt->tmpMin = data->getMin();
    opt->tmpMax = data->getMax();
  }

  if(opt->scaleType != PViewOptions::Linear &&
     opt->getScaleType(opt->tmpMin, opt->tmpMax) == PViewOptions::Linear) {
    static bool warned = false;
    if(!warned) {
      warned = true;
      Msg::Warning("Logarithmic scale of a range that is not positive: "
                   "drawing it linearly (View.ScaleType = 3 for a scale that "
                   "is logarithmic on both sides of zero)");
    }
  }

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double font_h = drawContext::global()->getStringHeight();
  _pixelFactor = ctx->highResolutionPixelFactor();
  std::vector<scaleTick> ticks;
  std::string multiplier;
  scaleTicks(opt, opt->tmpMin, opt->tmpMax, horizontal ? width : height,
             font_h, horizontal, ticks, multiplier);

  drawScaleBar(p, xmin, ymin, width, height, tick, horizontal, ticks);
  drawScaleValues(ctx, p, xmin, ymin, width, height, tick, horizontal, ticks);
  drawScaleLabel(ctx, p, xmin, ymin, width, height, tick, horizontal,
                 multiplier);
}

void drawContext::drawScales()
{
  std::vector<PView *> scales;
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(!data->getDirty() && opt->visible && opt->showScale &&
       opt->type == PViewOptions::Plot3D && data->hasElements() &&
       isVisible(PView::list[i]))
      scales.push_back(PView::list[i]);
  }
  if(scales.empty()) return;

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  char label[1024];
  double maxw = 0.;
  for(std::size_t i = 0; i < scales.size(); i++) {
    PViewOptions *opt = scales[i]->getOptions();
    snprintf(label, sizeof(label), opt->getFormat().c_str(), -M_PI * 1.e-4);
    maxw = std::max(maxw, drawContext::global()->getStringWidth(label));
  }

  const double tick = CTX::instance()->glFontSize; // used to be 10
  const double bar_size = CTX::instance()->glFontSize; // used to be 16
  double width = 0., width_prev = 0., width_total = 0.;
  // what a horizontal scale takes above its bar: the labels, the line of
  // the time or step, and the title (see drawScaleLabel())
  double font_h = drawContext::global()->getStringHeight();
  drawContext::global()->setFont(CTX::instance()->glFontEnumTitle,
                                 CTX::instance()->glFontSizeTitle);
  double title_h = drawContext::global()->getStringHeight();
  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double above = tick + 1.3 * font_h + 2.1 * title_h; // adjust for compactness
  // and a vertical one below its bar (the title and that line) and above
  // it (the top label and the power of ten)
  double belowV = 3.5 * font_h, aboveV = 2.2 * font_h; // adjust for compactness

  for(std::size_t i = 0; i < scales.size(); i++) {
    PView *p = scales[i];
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(!opt->autoPosition) {
      double w = opt->size[0], h = opt->size[1];
      double x = opt->position[0], y = opt->position[1];
      int c = fix2dCoordinates(&x, &y);
      if(c & 1) x -= w / 2.;
      if(c & 2) y -= h / 2.;
      drawScale(this, p, x, y, w, h, tick,
                CTX::instance()->post.horizontalScales);
    }
    else if(CTX::instance()->post.horizontalScales) {
      double ysep = 20.;
      double xc = (viewport[2] - viewport[0]) / 2.;
      if(scales.size() == 1) {
        // half the window long, and thicker than the font on a large window
        double vw = viewport[2] - viewport[0], vh = viewport[3] - viewport[1];
        double w = vw / 2., h = std::max(bar_size, 0.025 * std::min(vw, vh));
        double x = xc - w / 2., y = viewport[1] + ysep;
        drawScale(this, p, x, y, w, h, tick, 1);
      }
      else {
        double xsep = maxw / 4. + (viewport[2] - viewport[0]) / 10.;
        double w = (viewport[2] - viewport[0] - 4 * xsep) / 2.;
        if(w < 20.) w = 20.;
        double h = bar_size;
        double x = xc - (i % 2 ? -xsep / 1.5 : w + xsep / 1.5);
        double y = viewport[1] + ysep + (i / 2) * (bar_size + above + ysep);
        drawScale(this, p, x, y, w, h, tick, 1);
      }
    }
    else {
      double xsep = 20.;
      double dy = 2. * CTX::instance()->glFontSize;
      if(scales.size() == 1) {
        double vw = viewport[2] - viewport[0], vh = viewport[3] - viewport[1];
        double ysep = vh / 6.;
        // thicker than the font on a large window
        double w = std::max(bar_size, 0.025 * std::min(vw, vh));
        double h = vh - 2 * ysep - dy;
        double x = viewport[0] + xsep, y = viewport[1] + ysep + dy;
        drawScale(this, p, x, y, w, h, tick, 0);
      }
      else {
        double ysep = (viewport[3] - viewport[1]) / 15.;
        double w = bar_size;
        double h = (viewport[3] - viewport[1] - 3 * ysep -
                    2 * (belowV + aboveV)) / 2.;
        double x = viewport[0] + xsep + width_total + (i / 2) * xsep;
        double y = viewport[1] + ysep + belowV +
                   (1 - i % 2) * (h + aboveV + ysep + belowV);
        drawScale(this, p, x, y, w, h, tick, 0);
      }
      // the width this scale takes: its values, and under them its name and
      // its sub-line, each in the font it is drawn with
      width_prev = width;
      drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                     CTX::instance()->glFontSize);
      snprintf(label, sizeof(label), opt->getFormat().c_str(), -M_PI * 1.e-4);
      width = bar_size + tick + drawContext::global()->getStringWidth(label);
      width = std::max(
        width, drawContext::global()->getStringWidth(scaleSubtitle(p).c_str()));
      drawContext::global()->setFont(CTX::instance()->glFontEnumTitle,
                                     CTX::instance()->glFontSizeTitle);
      width = std::max(
        width, drawContext::global()->getStringWidth(data->getName().c_str()));
      if(i % 2)
        width_total += std::max(bar_size + width, bar_size + width_prev);
    }
  }
}
