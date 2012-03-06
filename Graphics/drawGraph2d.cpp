// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "gl2ps.h"
#include "Context.h"
#include "Numeric.h"

int drawContext::fix2dCoordinates(double *x, double *y)
{
  int ret = (*x > 99999 && *y > 99999) ? 3 : (*y > 99999) ? 2 : (*x > 99999) ? 1 : 0;

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
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->visible && opt->drawStrings && isVisible(PView::list[i])){
      glColor4ubv((GLubyte *) & opt->color.text2d);
      for(int j = 0; j < data->getNumStrings2D(); j++){
        double x, y, style;
        std::string str;
        data->getString2D(j, opt->timeStep, str, x, y, style);
        fix2dCoordinates(&x, &y);
        glRasterPos2d(x, y);
        drawString(str, style);
      }
    }
  }
}

static bool getGraphData(PView *p, std::vector<double> &x, double &xmin,
                         double &xmax, std::vector<std::vector<double> > &y)
{
  PViewData *data = p->getData(true); // use adaptive data if available
  PViewOptions *opt = p->getOptions();

  if(data->hasMultipleMeshes()) return false; // cannot handle multi-mesh

  int numy = 0;
  if(opt->type == PViewOptions::Plot2D ||
     opt->type == PViewOptions::Plot2DSpace){
    numy = 1;
  }
  else if(opt->type == PViewOptions::Plot2DTime){
    numy = 0;
    for(int ent = 0; ent < data->getNumEntities(0); ent++){
      if(data->skipEntity(0, ent)) continue;
      for(int ele = 0; ele < data->getNumElements(0, ent); ele++){
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

  SPoint3 p0(0., 0., 0.);

  numy = 0;
  for(int ent = 0; ent < data->getNumEntities(0); ent++){
    if(data->skipEntity(0, ent)) continue;
    for(int ele = 0; ele < data->getNumElements(0, ent); ele++){
      if(data->skipElement(0, ent, ele, true)) continue;
      if(opt->skipElement(data->getType(0, ent, ele))) continue;
      if(data->getDimension(0, ent, ele) >= 2) continue;
      int numNodes = data->getNumNodes(0, ent, ele);
      // reorder the nodes for high order line elements
      std::vector<int> reorder(numNodes);
      if(numNodes < 3){
        for(int j = 0; j < numNodes; j++)
          reorder[j] = j;
      }
      else{
        reorder[0] = 0;
        reorder[numNodes - 1] = 1;
        for(int j = 1; j < numNodes - 1; j++)
          reorder[j] = 1 + j;
      }
      for(int ts = space ? opt->timeStep : 0; ts < opt->timeStep + 1; ts++){
        if(!data->hasTimeStep(ts)) continue;
        int numComp = data->getNumComponents(ts, ent, ele);
        for(int j = 0; j < numNodes; j++){
          double val[9], xyz[3];
          data->getNode(ts, ent, ele, reorder[j], xyz[0], xyz[1], xyz[2]);
          for(int k = 0; k < numComp; k++)
            data->getValue(ts, ent, ele, reorder[j], k, val[k]);
          double vy = ComputeScalarRep(numComp, val);

          if(opt->type == PViewOptions::Plot2D){
            x.push_back(xyz[0]);
            y[0].push_back(vy);
          }
          else if(opt->type == PViewOptions::Plot2DSpace){
            // compute curvilinear coordinate
            if(x.empty()){
              p0 = SPoint3(xyz[0], xyz[1], xyz[2]);
              x.push_back(ComputeScalarRep(3, xyz));
            }
            else{
              SPoint3 p1(xyz[0], xyz[1], xyz[2]);
              x.push_back(x.back() + p0.distance(p1));
              p0 = p1;
            }
            y[0].push_back(vy);
          }
          else{
            if(!numy) x.push_back(data->getTime(ts));
            y[numy].push_back(vy);
          }

        }
      }
      numy++;
    }
  }

  if(x.empty()) return false;

  if(space){
    xmin = xmax = x[0];
    for(unsigned int i = 1; i < x.size(); i++){
      xmin = std::min(xmin, x[i]);
      xmax = std::max(xmax, x[i]);
    }
  }
  else{
    xmin = data->getTime(0);
    xmax = data->getTime(data->getNumTimeSteps() - 1);
  }

  if(opt->scaleType == PViewOptions::Logarithmic)
    for(unsigned int i = 0; i < y.size(); i++)
      for(unsigned int j = 0; j < y[i].size(); j++)
        y[i][j] = log10(y[i][j]);

  return true;
}

static void drawGraphAxes(drawContext *ctx, PView *p, double xleft, double ytop,
                          double width, double height, double xmin, double xmax)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  if(!opt->axes) return;

  int alpha = CTX::instance()->unpackAlpha(opt->color.background2d);
  if(alpha != 0){
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4ubv((GLubyte *) & opt->color.background2d);
    glBegin(GL_QUADS);
    glVertex2d(xleft, ytop);
    glVertex2d(xleft + width, ytop);
    glVertex2d(xleft + width, ytop - height);
    glVertex2d(xleft, ytop - height);
    glEnd();
    glDisable(GL_BLEND);
  }

  // total font height
  double font_h = drawContext::global()->getStringHeight() ?
    drawContext::global()->getStringHeight() : 1;
  // height above ref. point
  double font_a = font_h - drawContext::global()->getStringDescent();

  const double tic = 5.;

  glPointSize((float)CTX::instance()->pointSize);
  gl2psPointSize((float)(CTX::instance()->pointSize *
                         CTX::instance()->print.epsPointSizeFactor));

  glLineWidth((float)CTX::instance()->lineWidth);
  gl2psLineWidth((float)(CTX::instance()->lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));

  glColor4ubv((GLubyte *) & opt->color.axes);

  // bare axes
  glBegin(GL_LINE_STRIP);
  glVertex2d(xleft, ytop);
  glVertex2d(xleft, ytop - height);
  glVertex2d(xleft + width, ytop - height);
  if(opt->axes > 1){
    glVertex2d(xleft + width, ytop);
    glVertex2d(xleft, ytop);
  }
  glEnd();

  // y label
  std::string label = data->getName();
  if(opt->type == PViewOptions::Plot2D ||
     opt->type == PViewOptions::Plot2DSpace){
    int nt = data->getNumTimeSteps();
    if((opt->showTime == 1 && nt > 1) || opt->showTime == 2){
      char tmp[256];
      sprintf(tmp, opt->format.c_str(), data->getTime(opt->timeStep));
      label += std::string(" (") + tmp + ")";
    }
    else if((opt->showTime == 3 && nt > 1) || opt->showTime == 4){
      char tmp[256];
      sprintf(tmp, "%d", opt->timeStep);
      label += std::string(" (") + tmp + ")";
    }
  }
  if(opt->scaleType == PViewOptions::Logarithmic)
    label = "Log10 " + label;
  glRasterPos2d(xleft, ytop + font_h + tic);
  ctx->drawStringCenter(label.c_str());

  // x label
  label = opt->axesLabel[0];
  glRasterPos2d(xleft + width / 2, ytop - height - 2 * font_h - 2 * tic);
  ctx->drawStringCenter(label.c_str());

  // y tics and horizontal grid
  if(opt->nbIso > 0){
    int nb = opt->nbIso;
    if(opt->showScale && (opt->nbIso * font_h > height))
      nb = (int)floor(height / font_h);
    double dy = height / (double)nb;
    double dv = (opt->tmpMax - opt->tmpMin) / (double)nb;
    for(int i = 0; i < nb + 1; i++){
      if(opt->axes > 0){
        glBegin(GL_LINES);
        glVertex2d(xleft, ytop - i * dy);
        glVertex2d(xleft + tic, ytop - i * dy);
        if(opt->axes > 1){
          glVertex2d(xleft + width - tic, ytop - i * dy);
          glVertex2d(xleft + width, ytop - i * dy);
        }
        glEnd();
        if(opt->axes > 2 && i != 0 && i != nb){
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
      }
      if(opt->showScale){
        char tmp[256];
        sprintf(tmp, opt->format.c_str(), (i == nb) ? opt->tmpMin :
                (opt->tmpMax - i * dv));
        glRasterPos2d(xleft - 2 * tic, ytop - i * dy - font_a / 3.);
        ctx->drawStringRight(tmp);
      }
    }
  }

  // x tics and vertical grid
  if(opt->axesTics[0] > 0){
    int nb = opt->axesTics[0];
    if(opt->axes){
      char tmp[256];
      sprintf(tmp, opt->axesFormat[0].c_str(), - M_PI * 1.e-4);
      if((nb - 1) * drawContext::global()->getStringWidth(tmp) > width)
        nb = (int)(width / drawContext::global()->getStringWidth(tmp)) + 1;
    }
    if(nb == 1) nb++;

    double dx = width / (double)(nb - 1);
    double ybot = ytop - height;

    for(int i = 0; i < nb; i++){
      if(opt->axes){
        glBegin(GL_LINES);
        glVertex2d(xleft + i * dx, ybot);
        glVertex2d(xleft + i * dx, ybot + tic);
        if(opt->axes > 1){
          glVertex2d(xleft + i * dx, ytop);
          glVertex2d(xleft + i * dx, ytop - tic);
        }
        glEnd();
        if(opt->axes > 2 && i != 0 && i != nb - 1){
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

        char tmp[256];
        if(nb == 1)
          sprintf(tmp, opt->axesFormat[0].c_str(), xmin);
        else
          sprintf(tmp, opt->axesFormat[0].c_str(),
                  xmin + i * (xmax - xmin) / (double)(nb - 1));
        glRasterPos2d(xleft + i * dx, ybot - font_h - tic);
        ctx->drawStringCenter(tmp);
      }
    }
  }

}

static void addGraphPoint(drawContext *ctx, PView *p, double xleft, double ytop,
                          double width, double height, double x, double y,
                          double xmin, double xmax, double ymin, double ymax,
                          bool numeric, bool sphere)
{
  PViewOptions *opt = p->getOptions();

  double px = xleft;
  if(xmin != xmax) px += (x - xmin) / (xmax - xmin) * width;

  if(opt->saturateValues){
    if(y > ymax)
      y = ymax;
    else if(y < ymin)
      y = ymin;
  }

  double ybot = ytop - height;
  double py = ybot;
  if(ymax != ymin) py += (y - ymin) / (ymax - ymin) * height;

  if(y >= ymin && y <= ymax){
    unsigned int col = opt->getColor(y, ymin, ymax, true);
    glColor4ubv((GLubyte *) &col);
    if(numeric){
      glRasterPos2d(px + 3, py + 3);
      char label[256];
      sprintf(label, opt->format.c_str(), y);
      ctx->drawString(label);
    }
    else if(sphere)
      ctx->drawSphere(opt->pointSize, px, py, 0, 10, 10, opt->light);
    else
      glVertex2d(px, py);
  }
}

static void drawGraphCurves(drawContext *ctx, PView *p, double xleft, double ytop,
                            double width, double height, std::vector<double> &x,
                            double xmin, double xmax,
                            std::vector<std::vector<double> > &y)
{
  PViewOptions *opt = p->getOptions();

  glPointSize((float)opt->pointSize);
  gl2psPointSize((float)(opt->pointSize * CTX::instance()->print.epsPointSizeFactor));

  glLineWidth((float)opt->lineWidth);
  gl2psLineWidth((float)(opt->lineWidth * CTX::instance()->print.epsLineWidthFactor));

  if(opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Continuous){
    for(unsigned int i = 0; i < y.size(); i++){
      if(opt->useStipple){
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(opt->stipple[i % 10][0], opt->stipple[i % 10][1]);
        gl2psEnable(GL2PS_LINE_STIPPLE);
      }
      glBegin(GL_LINE_STRIP);
      for(unsigned int j = 0; j < x.size(); j++)
        addGraphPoint(ctx, p, xleft, ytop, width, height, x[j], y[i][j],
                      xmin, xmax, opt->tmpMin, opt->tmpMax, false, false);
      glEnd();
      if(opt->useStipple){
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
      }
    }
  }

  if(opt->intervalsType == PViewOptions::Iso ||
     opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Numeric){
    bool sphere =  (opt->pointType == 1 || opt->pointType == 3);
    if(!sphere) glBegin(GL_POINTS);
    for(unsigned int i = 0; i < y.size(); i++)
      for(unsigned int j = 0; j < x.size(); j++)
        addGraphPoint(ctx, p, xleft, ytop, width, height, x[j], y[i][j],
                      xmin, xmax, opt->tmpMin, opt->tmpMax, false, sphere);
    if(!sphere) glEnd();
  }

  if(opt->intervalsType == PViewOptions::Numeric){
    for(unsigned int i = 0; i < y.size(); i++)
      for(unsigned int j = 0; j < x.size(); j++)
        addGraphPoint(ctx, p, xleft, ytop, width, height, x[j], y[i][j],
                      xmin, xmax, opt->tmpMin, opt->tmpMax, true, false);
  }
}

static void drawGraph(drawContext *ctx, PView *p, double xleft, double ytop,
                      double width, double height)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  if(opt->rangeType == PViewOptions::Custom){
    opt->tmpMin = opt->customMin;
    opt->tmpMax = opt->customMax;
  }
  else if(opt->rangeType == PViewOptions::PerTimeStep){
    opt->tmpMin = data->getMin(opt->timeStep);
    opt->tmpMax = data->getMax(opt->timeStep);
  }
  else{
    opt->tmpMin = data->getMin();
    opt->tmpMax = data->getMax();
  }

  if(opt->scaleType == PViewOptions::Logarithmic){
    opt->tmpMin = log10(opt->tmpMin);
    opt->tmpMax = log10(opt->tmpMax);
  }

  std::vector<double> x;
  std::vector<std::vector<double> > y;
  double xmin, xmax;
  if(!getGraphData(p, x, xmin, xmax, y)) return;
  drawGraphAxes(ctx, p, xleft, ytop, width, height, xmin, xmax);
  drawGraphCurves(ctx, p, xleft, ytop, width, height, x, xmin, xmax, y);
}

void drawContext::drawGraph2d()
{
  std::vector<PView*> graphs;
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(!data->getDirty() && opt->visible && opt->type != PViewOptions::Plot3D &&
       isVisible(PView::list[i]))
      graphs.push_back(PView::list[i]);
  }
  if(graphs.empty()) return;

  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double xsep = 0., ysep = 5 * drawContext::global()->getStringHeight();
  char label[1024];
  for(unsigned int i = 0; i < graphs.size(); i++){
    PViewOptions *opt = graphs[i]->getOptions();
    sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
    xsep = std::max(xsep, drawContext::global()->getStringWidth(label));
  }

  for(unsigned int i = 0; i < graphs.size(); i++){
    PView *p = graphs[i];
    PViewOptions *opt = graphs[i]->getOptions();
    if(opt->autoPosition == 1){ // automatic
      double winw = viewport[2] - viewport[0];
      double winh = viewport[3] - viewport[1];
      if(graphs.size() == 1){
        double fracw = 0.75, frach = 0.75;
        double w = fracw * winw - xsep;
        double h = frach * winh - ysep;
        double x = viewport[0] + (1 - fracw) / 2. * winw;
        double y = viewport[1] + (1 - frach) / 2. * winh;
        drawGraph(this, p, x + 0.95 * xsep, viewport[3] - (y + 0.4 * ysep), w, h);
      }
      else if(graphs.size() == 2){
        double fracw = 0.75, frach = 0.85;
        double w = fracw * winw - xsep;
        double h = frach * winh / 2. - ysep;
        double x = viewport[0] + (1 - fracw) / 2. * winw;
        double y = viewport[1] + (1 - frach) / 3. * winh;
        if(i == 1) y += (h + ysep + (1 - frach) / 3. * winh);
        drawGraph(this, p, x + 0.95 * xsep, viewport[3] - (y + 0.4 * ysep), w, h);
      }
      else{
        double fracw = 0.85, frach = 0.85;
        double w = fracw * winw / 2. - xsep;
        double h = frach * winh / 2. - ysep;
        double x = viewport[0] + (1 - fracw) / 3. * winw;
        if(i == 1 || i == 3) x += (w + xsep + (1 - fracw) / 3. * winw);
        double y = viewport[1] + (1 - frach) / 3. * winh;
        if(i == 2 || i == 3) y += (h + ysep + (1 - frach) / 3. * winh);
        drawGraph(this, p, x + 0.95 * xsep, viewport[3] - (y + 0.4 * ysep), w, h);
      }
    }
    else if(opt->autoPosition >= 2 && opt->autoPosition <= 9){
      // top left (2), top right (3), bottom left (4), bottom right (5), top
      // half (6), bottom half (7), left half (8), right half (9)
      double winw = viewport[2] - viewport[0];
      double winh = viewport[3] - viewport[1];
      double fracw = 0.85, frach = 0.85;
      int a = opt->autoPosition;
      double wd = (a <= 5 || a == 8 || a == 9) ? 2. : 1.;
      double w = fracw * winw / wd - xsep;
      double hd = (a <= 5 || a == 6 || a == 7) ? 2. : 1.;
      double h = frach * winh / hd - ysep;
      double x = viewport[0] + (1 - fracw) / 3. * winw;
      if(a == 3 || a == 5 || a == 9)
        x += (w + xsep + (1 - fracw) / 3. * winw);
      double y = viewport[1] + (1 - frach) / 3. * winh;
      if(a == 4 || a == 5 || a == 7)
        y += (h + ysep + (1 - frach) / 3. * winh);
      drawGraph(this, p, x + 0.95 * xsep, viewport[3] - (y + 0.4 * ysep), w, h);
    }
    else{ // manual
      double x = opt->position[0], y = opt->position[1];
      int center = fix2dCoordinates(&x, &y);
      drawGraph(this, p, x - (center & 1 ? opt->size[0] / 2. : 0),
                y + (center & 2 ? opt->size[1] / 2. : 0),
                opt->size[0], opt->size[1]);
    }
  }
}
