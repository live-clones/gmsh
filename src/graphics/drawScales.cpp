// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
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

static void drawScaleBar(PView *p, double xmin, double ymin, double width,
                         double height, double tic, int horizontal)
{
  PViewOptions *opt = p->getOptions();

  double box = (horizontal ? width : height) / (opt->nbIso ? opt->nbIso : 1);

  for(int i = 0; i < opt->nbIso; i++) {
    if(opt->intervalsType == PViewOptions::Discrete ||
       opt->intervalsType == PViewOptions::Numeric) {
      unsigned int col = opt->getColor(i, opt->nbIso);
      glColor4ubv((GLubyte *)&col);
      glBegin(GL_QUADS);
      if(horizontal) {
        glVertex2d(xmin + i * box, ymin);
        glVertex2d(xmin + (i + 1) * box, ymin);
        glVertex2d(xmin + (i + 1) * box, ymin + height);
        glVertex2d(xmin + i * box, ymin + height);
      }
      else {
        glVertex2d(xmin, ymin + i * box);
        glVertex2d(xmin + width, ymin + i * box);
        glVertex2d(xmin + width, ymin + (i + 1) * box);
        glVertex2d(xmin, ymin + (i + 1) * box);
      }
      glEnd();
    }
    else if(opt->intervalsType == PViewOptions::Continuous) {
      glBegin(GL_QUADS);
      double dv = (opt->tmpMax - opt->tmpMin) / (opt->nbIso ? opt->nbIso : 1);
      double v1 = opt->tmpMin + i * dv;
      unsigned int col1 = opt->getColor(v1, opt->tmpMin, opt->tmpMax, true);
      glColor4ubv((GLubyte *)&col1);
      if(horizontal) {
        glVertex2d(xmin + i * box, ymin + height);
        glVertex2d(xmin + i * box, ymin);
      }
      else {
        glVertex2d(xmin, ymin + i * box);
        glVertex2d(xmin + width, ymin + i * box);
      }
      double v2 = opt->tmpMin + (i + 1) * dv;
      unsigned int col2 = opt->getColor(v2, opt->tmpMin, opt->tmpMax, true);
      glColor4ubv((GLubyte *)&col2);
      if(horizontal) {
        glVertex2d(xmin + (i + 1) * box, ymin);
        glVertex2d(xmin + (i + 1) * box, ymin + height);
      }
      else {
        glVertex2d(xmin + width, ymin + (i + 1) * box);
        glVertex2d(xmin, ymin + (i + 1) * box);
      }
      glEnd();
    }
    else {
      unsigned int col = opt->getColor(i, opt->nbIso);
      glColor4ubv((GLubyte *)&col);
      glBegin(GL_LINES);
      if(horizontal) {
        glVertex2d(xmin + box / 2. + i * box, ymin);
        glVertex2d(xmin + box / 2. + i * box, ymin + height);
      }
      else {
        glVertex2d(xmin, ymin + box / 2. + i * box);
        glVertex2d(xmin + width, ymin + box / 2. + i * box);
      }
      glEnd();
    }
  }
}

static void drawScaleValues(drawContext *ctx, PView *p, double xmin,
                            double ymin, double width, double height,
                            double tic, int horizontal)
{
  PViewOptions *opt = p->getOptions();

  if(!opt->nbIso) return;

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double font_h = drawContext::global()->getStringHeight(); // total font height
  double font_a =
    drawContext::global()->getStringHeight() -
    drawContext::global()->getStringDescent(); // height above ref pt

  char label[1024];
  sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
  double maxw = drawContext::global()->getStringWidth(label);

  int nbv = opt->nbIso;
  double f = (opt->intervalsType == PViewOptions::Discrete ||
              opt->intervalsType == PViewOptions::Numeric ||
              opt->intervalsType == PViewOptions::Continuous) ?
               2 :
               2.5;

  if(horizontal && width < nbv * maxw) {
    if(width < f * maxw)
      nbv = 1;
    else
      nbv = 2;
  }
  else if(!horizontal && height < nbv * font_h) {
    if(height < f * font_h)
      nbv = 1;
    else
      nbv = 2;
  }

  double box = (horizontal ? width : height) / opt->nbIso;
  double vbox = (horizontal ? width : height) / nbv;

  glColor4ubv((GLubyte *)&CTX::instance()->color.text);

  if(opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Numeric ||
     opt->intervalsType == PViewOptions::Continuous) {
    for(int i = 0; i < nbv + 1; i++) {
      double v = opt->getScaleValue(i, nbv + 1, opt->tmpMin, opt->tmpMax);
      sprintf(label, opt->format.c_str(), v);
      if(horizontal) {
        ctx->drawStringCenter(label, xmin + i * vbox, ymin + height + tic, 0.);
      }
      else {
        ctx->drawString(label, xmin + width + tic,
                        ymin + i * vbox - font_a / 3., 0.);
      }
    }
  }
  else {
    if(opt->nbIso > 2 && (nbv == 1 || nbv == 2)) {
      vbox = (vbox * nbv - box) / nbv;
      nbv++;
    }
    for(int i = 0; i < nbv; i++) {
      double v = opt->getScaleValue(i, nbv, opt->tmpMin, opt->tmpMax);
      sprintf(label, opt->format.c_str(), v);
      if(horizontal) {
        ctx->drawStringCenter(label, xmin + box / 2. + i * vbox,
                              ymin + height + tic, 0.);
      }
      else {
        ctx->drawString(label, xmin + width + tic,
                        ymin + box / 2. + i * vbox - font_a / 3., 0.);
      }
    }
  }
}

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

  char label[1024];

  int nt = data->getNumTimeSteps();
  int n0 = data->getFirstNonEmptyTimeStep();
  int n = (nt - n0 > 0) ? nt - n0 : 1;
  char time[256];
  sprintf(time, opt->format.c_str(), data->getTime(opt->timeStep));
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
  case 1: // time series
    sprintf(label, "%s - time %s", data->getName().c_str(), time);
    break;
  case 2: // harmonic data
    if(n <= 2)
      sprintf(label, "%s - %s part", data->getName().c_str(),
              ((opt->timeStep - n0) % 2) ? "imaginary" : "real");
    else
      sprintf(label, "%s - harmonic %s (%s part)", data->getName().c_str(),
              time, ((opt->timeStep - n0) % 2) ? "imaginary" : "real");
    break;
  case 3: // automatic
    // never here
    break;
  case 4: // step data
    sprintf(label, "%s - step %d", data->getName().c_str(), opt->timeStep);
    break;
  case 5: // multi-step data
    sprintf(label, "%s - step %d in [0,%d]", data->getName().c_str(),
            opt->timeStep, data->getNumTimeSteps() - 1);
    break;
  case 6: // real eigenvalues
    sprintf(label, "%s - eigenvalue %s", data->getName().c_str(), time);
    break;
  case 7: // complex eigenvalues
    sprintf(label, "%s - eigenvalue %s (%s part)", data->getName().c_str(),
            time, ((opt->timeStep - n0) % 2) ? "imaginary" : "real");
    break;
  default: sprintf(label, "%s", data->getName().c_str()); break;
  }

  if(horizontal) {
    ctx->drawString(
      label, xmin + width / 2., ymin + height + tic + 1.4 * font_h, 0.,
      CTX::instance()->glFontTitle, CTX::instance()->glFontEnumTitle,
      CTX::instance()->glFontSizeTitle, 1);
  }
  else {
    ctx->drawString(
      label, xmin, ymin - 2 * font_h, 0., CTX::instance()->glFontTitle,
      CTX::instance()->glFontEnumTitle, CTX::instance()->glFontSizeTitle, 0);
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

  drawScaleBar(p, xmin, ymin, width, height, tic, horizontal);
  drawScaleValues(ctx, p, xmin, ymin, width, height, tic, horizontal);
  drawScaleLabel(ctx, p, xmin, ymin, width, height, tic, horizontal);
}

void drawContext::drawScales()
{
  std::vector<PView *> scales;
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(!data->getDirty() && opt->visible && opt->showScale &&
       opt->type == PViewOptions::Plot3D && data->getNumElements() &&
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

  const double tic = 10., bar_size = 16.;
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
        double w = (viewport[2] - viewport[0]) / 2., h = bar_size;
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
      double dy = 2. * drawContext::global()->getStringHeight();
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
