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
#include "gl2ps.h"

// A label of the scale: its value, where it sits along the bar (0 at the
// start, 1 at the end) and the text
struct scaleTick {
  double v, t;
  std::string label;
};

// v divided by 10^exp, with the given number of decimals
static std::string fixedNumber(double v, int decimals, int exp)
{
  double m = exp ? v / pow(10., exp) : v;
  char str[64];
  sprintf(str, "%.*f", decimals, m);
  // no "-0.00"
  bool zero = true;
  for(const char *c = str; *c; c++)
    if(*c >= '1' && *c <= '9') zero = false;
  if(zero && str[0] == '-') return std::string(str + 1);
  return str;
}

// decimals enough for three significant digits of v / 10^exp
static int significantDecimals(double v, int exp)
{
  double m = fabs(exp ? v / pow(10., exp) : v);
  if(m == 0.) return 0;
  return std::max(0, 2 - (int)floor(log10(m)));
}

// the label of an end of the range: with the decimals of the step when they
// print it exactly, with three significant digits otherwise
static std::string endLabel(double v, int stepDecimals, int exp, double range)
{
  double m = exp ? v / pow(10., exp) : v;
  double scale = pow(10., stepDecimals);
  if(fabs(m * scale - floor(m * scale + 0.5)) < 1.e-6 * range / pow(10., exp))
    return fixedNumber(v, stepDecimals, exp);
  return fixedNumber(v, std::max(stepDecimals, significantDecimals(v, exp)),
                     exp);
}

static bool ticksFit(const std::vector<scaleTick> &ticks, double length,
                     const std::vector<double> &widths, double fontH,
                     bool horizontal)
{
  for(std::size_t i = 1; i < ticks.size(); i++) {
    double gap = (ticks[i].t - ticks[i - 1].t) * length;
    double need = horizontal ? 0.5 * (widths[i] + widths[i - 1]) + 0.6 * fontH :
                               1.3 * fontH;
    if(gap < need) return false;
  }
  return true;
}

// The labels of the scale. With the default format the values are round
// numbers of a step that lets the labels fit along the bar, the range's
// ends added, printed as plain decimals or scaled by a power of ten written
// once in `multiplier'; with a format of the user's, or on a logarithmic
// scale, they are the nbIso divisions of the range as before, as many as
// fit.
static void scaleTicks(PViewOptions *opt, double min, double max,
                       double length, double fontH, bool horizontal,
                       std::vector<scaleTick> &ticks, std::string &multiplier)
{
  ticks.clear();
  multiplier.clear();
  drawContextGlobal *g = drawContext::global();
  bool defaultFormat = (opt->format == "%.3g");
  bool linear = (opt->scaleType == PViewOptions::Linear);
  char str[128];

  if(defaultFormat && linear && max > min) {
    double mag = std::max(fabs(min), fabs(max));
    int e = (int)floor(log10(mag));
    int exp = (e >= 5 || e <= -4) ? e : 0;
    if(exp) {
      sprintf(str, "x10^%d", exp);
      multiplier = str;
    }
    // the ends
    double r = max - min;
    std::vector<scaleTick> ends(2);
    ends[0].v = min; ends[0].t = 0.; ends[0].label = endLabel(min, 0, exp, r);
    ends[1].v = max; ends[1].t = 1.; ends[1].label = endLabel(max, 0, exp, r);
    std::vector<double> endWidths(2);
    for(int i = 0; i < 2; i++) endWidths[i] = g->getStringWidth(ends[i].label.c_str());
    if(!ticksFit(ends, length, endWidths, fontH, horizontal)) {
      // room for one label only: the middle of the range
      scaleTick mid;
      mid.v = 0.5 * (min + max);
      mid.t = 0.5;
      mid.label = fixedNumber(mid.v, significantDecimals(mid.v, exp), exp);
      ticks.push_back(mid);
      return;
    }
    // the finest round step whose labels all fit, tried from coarse to
    // fine; a round value too close to an end for both labels gives way
    std::vector<double> steps;
    const int mant[3] = {5, 2, 1};
    for(int k = (int)ceil(log10(r)); k >= (int)floor(log10(r)) - 2; k--)
      for(int j = 0; j < 3; j++) {
        double st = mant[j] * pow(10., k);
        if(r / st >= 1.5 && r / st <= 12.) steps.push_back(st);
      }
    std::vector<scaleTick> best = ends;
    for(std::size_t si = 0; si < steps.size(); si++) {
      double st = steps[si];
      int decimals = std::max(0, -(int)floor(log10(st / pow(10., exp)) + 1e-9));
      std::vector<scaleTick> cand;
      cand.push_back(ends[0]);
      cand[0].label = endLabel(min, decimals, exp, r);
      double w0 = g->getStringWidth(cand[0].label.c_str());
      scaleTick last = ends[1];
      last.label = endLabel(max, decimals, exp, r);
      double w1 = g->getStringWidth(last.label.c_str());
      for(double v = ceil(min / st) * st; v < max; v += st) {
        if(v <= min) continue;
        scaleTick tk;
        tk.v = v;
        tk.t = (v - min) / r;
        tk.label = fixedNumber(v, decimals, exp);
        double w = g->getStringWidth(tk.label.c_str());
        double need0 = horizontal ? 0.5 * (w + w0) + 0.6 * fontH : 1.3 * fontH;
        double need1 = horizontal ? 0.5 * (w + w1) + 0.6 * fontH : 1.3 * fontH;
        if(tk.t * length < need0 || (1. - tk.t) * length < need1) continue;
        cand.push_back(tk);
      }
      cand.push_back(last);
      std::vector<double> widths(cand.size());
      for(std::size_t i = 0; i < cand.size(); i++)
        widths[i] = g->getStringWidth(cand[i].label.c_str());
      if(ticksFit(cand, length, widths, fontH, horizontal)) best = cand;
    }
    ticks = best;
    return;
  }

  // the divisions of the range, as many as fit
  sprintf(str, opt->format.c_str(), -M_PI * 1.e-4);
  double maxw = g->getStringWidth(str);
  int nbv = std::max(1, opt->nbIso);
  double f = 2.;
  if(horizontal && length < nbv * maxw)
    nbv = (length < f * maxw) ? 1 : 2;
  else if(!horizontal && length < nbv * fontH)
    nbv = (length < f * fontH) ? 1 : 2;
  for(int i = 0; i < nbv + 1; i++) {
    scaleTick tk;
    tk.v = opt->getScaleValue(i, nbv + 1, min, max);
    tk.t = (nbv == 0) ? 0.5 : (double)i / nbv;
    sprintf(str, opt->format.c_str(), tk.v);
    tk.label = str;
    ticks.push_back(tk);
  }
}

static void drawScaleBar(PView *p, double xmin, double ymin, double width,
                         double height, double tic, int horizontal,
                         const std::vector<scaleTick> &ticks)
{
  PViewOptions *opt = p->getOptions();

  double box = (horizontal ? width : height) / (opt->nbIso ? opt->nbIso : 1);

  for(int i = 0; i < opt->nbIso; i++) {
    if(opt->intervalsType == PViewOptions::Discrete ||
       opt->intervalsType == PViewOptions::Numeric) {
      unsigned int col = opt->getColor(i, opt->nbIso);
      gmshColor4ubv((GLubyte *)&col);
      gmshBegin(GL_QUADS);
      if(horizontal) {
        gmshVertex2d(xmin + i * box, ymin);
        gmshVertex2d(xmin + (i + 1) * box, ymin);
        gmshVertex2d(xmin + (i + 1) * box, ymin + height);
        gmshVertex2d(xmin + i * box, ymin + height);
      }
      else {
        gmshVertex2d(xmin, ymin + i * box);
        gmshVertex2d(xmin + width, ymin + i * box);
        gmshVertex2d(xmin + width, ymin + (i + 1) * box);
        gmshVertex2d(xmin, ymin + (i + 1) * box);
      }
      gmshEnd();
    }
    else if(opt->intervalsType == PViewOptions::Continuous) {
      gmshBegin(GL_QUADS);
      double dv = (opt->tmpMax - opt->tmpMin) / (opt->nbIso ? opt->nbIso : 1);
      double v1 = opt->tmpMin + i * dv;
      unsigned int col1 = opt->getColor(v1, opt->tmpMin, opt->tmpMax, true);
      gmshColor4ubv((GLubyte *)&col1);
      if(horizontal) {
        gmshVertex2d(xmin + i * box, ymin + height);
        gmshVertex2d(xmin + i * box, ymin);
      }
      else {
        gmshVertex2d(xmin, ymin + i * box);
        gmshVertex2d(xmin + width, ymin + i * box);
      }
      double v2 = opt->tmpMin + (i + 1) * dv;
      unsigned int col2 = opt->getColor(v2, opt->tmpMin, opt->tmpMax, true);
      gmshColor4ubv((GLubyte *)&col2);
      if(horizontal) {
        gmshVertex2d(xmin + (i + 1) * box, ymin);
        gmshVertex2d(xmin + (i + 1) * box, ymin + height);
      }
      else {
        gmshVertex2d(xmin + width, ymin + (i + 1) * box);
        gmshVertex2d(xmin, ymin + (i + 1) * box);
      }
      gmshEnd();
    }
    else {
      unsigned int col = opt->getColor(i, opt->nbIso);
      gmshColor4ubv((GLubyte *)&col);
      gmshBegin(GL_LINES);
      if(horizontal) {
        gmshVertex2d(xmin + box / 2. + i * box, ymin);
        gmshVertex2d(xmin + box / 2. + i * box, ymin + height);
      }
      else {
        gmshVertex2d(xmin, ymin + box / 2. + i * box);
        gmshVertex2d(xmin + width, ymin + box / 2. + i * box);
      }
      gmshEnd();
    }
  }

  // a filled bar gets an outline and a tick mark at each label
  if(opt->intervalsType != PViewOptions::Iso) {
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
      if(horizontal) {
        double x = xmin + ticks[i].t * width;
        gmshVertex2d(x, ymin + height);
        gmshVertex2d(x, ymin + height + 0.4 * tic);
      }
      else {
        double y = ymin + ticks[i].t * height;
        gmshVertex2d(xmin + width, y);
        gmshVertex2d(xmin + width + 0.4 * tic, y);
      }
    }
    gmshEnd();
  }
}

static void drawScaleValues(drawContext *ctx, PView *p, double xmin,
                            double ymin, double width, double height,
                            double tic, int horizontal,
                            const std::vector<scaleTick> &ticks,
                            const std::string &multiplier)
{
  PViewOptions *opt = p->getOptions();

  if(!opt->nbIso) return;

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double font_h = drawContext::global()->getStringHeight(); // total font height
  double font_a =
    drawContext::global()->getStringHeight() -
    drawContext::global()->getStringDescent(); // height above ref pt

  gmshColor4ubv((GLubyte *)&CTX::instance()->color.text);

  if(opt->intervalsType == PViewOptions::Iso) {
    // one label per iso line, centred on it; with the default format the
    // values share the multiplier, with three significant digits
    bool defaultFormat = (opt->format == "%.3g");
    int exp = 0, decimals = 0;
    if(defaultFormat) {
      // three significant digits of the largest value, and enough to tell
      // neighbouring iso values apart
      double mag = std::max(fabs(opt->tmpMin), fabs(opt->tmpMax));
      int e = mag > 0. ? (int)floor(log10(mag)) : 0;
      exp = (e >= 5 || e <= -4) ? e : 0;
      decimals = significantDecimals(mag, exp);
      if(opt->nbIso > 1 && opt->tmpMax > opt->tmpMin) {
        double spacing = (opt->tmpMax - opt->tmpMin) / (opt->nbIso - 1);
        int d = -(int)floor(log10(spacing / pow(10., exp)) + 1e-9);
        decimals = std::max(decimals, std::min(d, decimals + 2));
      }
    }
    char label[1024];
    if(defaultFormat)
      strcpy(label, fixedNumber(-M_PI * 1.e-4 * pow(10., exp), decimals, exp).c_str());
    else
      sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
    double maxw = drawContext::global()->getStringWidth(label);
    int nbv = opt->nbIso;
    if(horizontal && width < nbv * maxw)
      nbv = (width < 2.5 * maxw) ? 1 : 2;
    else if(!horizontal && height < nbv * font_h)
      nbv = (height < 2.5 * font_h) ? 1 : 2;
    double box = (horizontal ? width : height) / opt->nbIso;
    double vbox = (horizontal ? width : height) / nbv;
    if(opt->nbIso > 2 && (nbv == 1 || nbv == 2)) {
      vbox = (vbox * nbv - box) / nbv;
      nbv++;
    }
    for(int i = 0; i < nbv; i++) {
      double v = opt->getScaleValue(i, nbv, opt->tmpMin, opt->tmpMax);
      if(defaultFormat)
        strcpy(label, fixedNumber(v, decimals, exp).c_str());
      else
        sprintf(label, opt->format.c_str(), v);
      if(horizontal)
        ctx->drawStringCenter(label, xmin + box / 2. + i * vbox,
                              ymin + height + tic, 0.);
      else
        ctx->drawString(label, xmin + width + tic,
                        ymin + box / 2. + i * vbox - font_a / 3., 0.);
    }
    if(exp) {
      char mult[32];
      sprintf(mult, "x10^%d", exp);
      if(horizontal)
        ctx->drawStringRight(mult, xmin + width, ymin - 0.4 * tic - font_a, 0.);
      else
        ctx->drawString(mult, xmin + width + tic, ymin + height + 1.2 * font_h,
                        0.);
    }
    return;
  }

  for(std::size_t i = 0; i < ticks.size(); i++) {
    if(horizontal)
      ctx->drawStringCenter(ticks[i].label, xmin + ticks[i].t * width,
                            ymin + height + tic, 0.);
    else
      ctx->drawString(ticks[i].label, xmin + width + tic,
                      ymin + ticks[i].t * height - font_a / 3., 0.);
  }
  if(multiplier.size()) {
    if(horizontal)
      ctx->drawStringRight(multiplier, xmin + width, ymin - 0.4 * tic - font_a,
                           0.);
    else
      ctx->drawString(multiplier, xmin + width + tic,
                      ymin + height + 1.2 * font_h, 0.);
  }
}

// the title of the scale: the name of the view, and on a line of its own
// below it what the time or step is, when there is one
static void drawScaleLabel(drawContext *ctx, PView *p, double xmin, double ymin,
                           double width, double height, double tic,
                           int horizontal)
{
  PViewOptions *opt = p->getOptions();
  PViewData *data;

  // requested by Laurent: but is this really what we should be doing?
  if(opt->externalViewIndex >= 0 &&
     opt->externalViewIndex < (int)PView::list.size())
    data = PView::list[opt->externalViewIndex]->getData();
  else
    data = p->getData();

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double font_h = drawContext::global()->getStringHeight();
  drawContext::global()->setFont(CTX::instance()->glFontEnumTitle,
                                 CTX::instance()->glFontSizeTitle);
  double title_h = drawContext::global()->getStringHeight();

  char sub[512] = "";
  int nt = data->getNumTimeSteps();
  int n0 = data->getFirstNonEmptyTimeStep();
  int n = (nt - n0 > 0) ? nt - n0 : 1;
  char time[256];
  sprintf(time, opt->format.c_str(), data->getTime(opt->timeStep));
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
  case 1: sprintf(sub, "time %s", time); break;
  case 2:
    if(n <= 2)
      sprintf(sub, "%s part", part);
    else
      sprintf(sub, "harmonic %s (%s part)", time, part);
    break;
  case 4: sprintf(sub, "step %d", opt->timeStep); break;
  case 5:
    sprintf(sub, "step %d of %d", opt->timeStep, data->getNumTimeSteps() - 1);
    break;
  case 6: sprintf(sub, "eigenvalue %s", time); break;
  case 7: sprintf(sub, "eigenvalue %s (%s part)", time, part); break;
  default: break;
  }
  std::string name = data->getName();

  gmshColor4ubv((GLubyte *)&CTX::instance()->color.text);
  if(horizontal) {
    double y = ymin + height + tic + 1.4 * font_h;
    if(sub[0]) {
      ctx->drawString(sub, xmin + width / 2., y, 0., CTX::instance()->glFont,
                      CTX::instance()->glFontEnum, CTX::instance()->glFontSize,
                      1);
      y += 1.2 * title_h;
    }
    ctx->drawString(name, xmin + width / 2., y, 0.,
                    CTX::instance()->glFontTitle,
                    CTX::instance()->glFontEnumTitle,
                    CTX::instance()->glFontSizeTitle, 1);
  }
  else {
    double y = ymin - 2 * font_h;
    ctx->drawString(name, xmin, y, 0., CTX::instance()->glFontTitle,
                    CTX::instance()->glFontEnumTitle,
                    CTX::instance()->glFontSizeTitle, 0);
    if(sub[0])
      ctx->drawString(sub, xmin, y - 1.3 * font_h, 0., CTX::instance()->glFont,
                      CTX::instance()->glFontEnum, CTX::instance()->glFontSize,
                      0);
  }
}

static void drawScale(drawContext *ctx, PView *p, double xmin, double ymin,
                      double width, double height, double tic, int horizontal)
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

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double font_h = drawContext::global()->getStringHeight();
  std::vector<scaleTick> ticks;
  std::string multiplier;
  if(opt->intervalsType != PViewOptions::Iso)
    scaleTicks(opt, opt->tmpMin, opt->tmpMax, horizontal ? width : height,
               font_h, horizontal, ticks, multiplier);

  drawScaleBar(p, xmin, ymin, width, height, tic, horizontal, ticks);
  drawScaleValues(ctx, p, xmin, ymin, width, height, tic, horizontal, ticks,
                  multiplier);
  drawScaleLabel(ctx, p, xmin, ymin, width, height, tic, horizontal);
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
    sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
    maxw = std::max(maxw, drawContext::global()->getStringWidth(label));
  }

  const double tic = CTX::instance()->glFontSize; // used to be 10
  const double bar_size = CTX::instance()->glFontSize; // used to be 16
  double width = 0., width_prev = 0., width_total = 0.;

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
      drawScale(this, p, x, y, w, h, tic,
                CTX::instance()->post.horizontalScales);
    }
    else if(CTX::instance()->post.horizontalScales) {
      double ysep = 20.;
      double xc = (viewport[2] - viewport[0]) / 2.;
      if(scales.size() == 1) {
        // half the window long, and thicker than the font on a large window
        double vw = viewport[2] - viewport[0], vh = viewport[3] - viewport[1];
        double w = vw / 2., h = std::max(bar_size, 0.03 * std::min(vw, vh));
        double x = xc - w / 2., y = viewport[1] + ysep;
        drawScale(this, p, x, y, w, h, tic, 1);
      }
      else {
        double xsep = maxw / 4. + (viewport[2] - viewport[0]) / 10.;
        double w = (viewport[2] - viewport[0] - 4 * xsep) / 2.;
        if(w < 20.) w = 20.;
        double h = bar_size;
        double x = xc - (i % 2 ? -xsep / 1.5 : w + xsep / 1.5);
        double y =
          viewport[1] + ysep +
          (i / 2) * (bar_size + tic +
                     2 * drawContext::global()->getStringHeight() + ysep);
        drawScale(this, p, x, y, w, h, tic, 1);
      }
    }
    else {
      double xsep = 20.;
      double dy = 2. * CTX::instance()->glFontSize;
      if(scales.size() == 1) {
        double ysep = (viewport[3] - viewport[1]) / 6.;
        double w = bar_size, h = viewport[3] - viewport[1] - 2 * ysep - dy;
        double x = viewport[0] + xsep, y = viewport[1] + ysep + dy;
        drawScale(this, p, x, y, w, h, tic, 0);
      }
      else {
        double ysep = (viewport[3] - viewport[1]) / 15.;
        double w = bar_size;
        double h = (viewport[3] - viewport[1] - 3 * ysep - 2.5 * dy) / 2.;
        double x = viewport[0] + xsep + width_total + (i / 2) * xsep;
        double y =
          viewport[1] + ysep + dy + (1 - i % 2) * (h + 1.5 * dy + ysep);
        drawScale(this, p, x, y, w, h, tic, 0);
      }
      // compute width
      width_prev = width;
      sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
      width = bar_size + tic + drawContext::global()->getStringWidth(label);
      if(opt->showTime) {
        char tmp[256];
        sprintf(tmp, opt->format.c_str(), data->getTime(opt->timeStep));
        sprintf(label, "%s (%s)", data->getName().c_str(), tmp);
      }
      else
        sprintf(label, "%s", data->getName().c_str());
      width = std::max(width, drawContext::global()->getStringWidth(label));
      if(i % 2)
        width_total += std::max(bar_size + width, bar_size + width_prev);
    }
  }
}
