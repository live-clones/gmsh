// $Id: Graph2D.cpp,v 1.65 2007-09-10 04:47:03 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GmshUI.h"
#include "Draw.h"
#include "PView.h"
#include "gl2ps.h"
#include "Context.h"

extern Context_T CTX;

int Fix2DCoordinates(double *x, double *y)
{
  int ret = (*x > 99999 && *y > 99999) ? 3 : (*y > 99999) ? 2 : (*x > 99999) ? 1 : 0;

  if(*x < 0) // measure from right border
    *x = CTX.viewport[2] + *x;
  else if(*x > 99999) // by convention, x-centered
    *x = CTX.viewport[2]/2;

  if(*y < 0) // measure from bottom border
    *y = -(*y);
  else if(*y > 99999) // by convention, y-centered
    *y = CTX.viewport[3]/2.;
  else
    *y = CTX.viewport[3] - *y;
  return ret;
}

void Draw_Text2D()
{
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->Visible && opt->DrawStrings){
      glColor4ubv((GLubyte *) & opt->color.text2d);
      for(int j = 0; j < data->getNumStrings2D(); j++){
	double x, y, style;
	std::string str;
	data->getString2D(j, opt->TimeStep, str, x, y, style);
	Fix2DCoordinates(&x, &y);
	glRasterPos2d(x, y);
	Draw_String((char*)str.c_str(), style);
      }
    }
  }
}

static bool getGraphData(PView *p, std::vector<double> &x, double &xmin, 
			 double &xmax, std::vector<std::vector<double> > &y, 
			 double &ymin, double ymax) 
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  int numy = 0;
  if(opt->Type == PViewOptions::Plot2DSpace){
    numy = 1;
  }
  else if(opt->Type == PViewOptions::Plot2DTime){
    numy = 0;
    for(int i = 0; i < data->getNumElements(); i++)
      if(data->getDimension(i) < 2) numy++;
  }
  
  if(!numy) return false;
  y.resize(numy);

  for(int i = 0; i < data->getNumElements(); i++){
    int dim = data->getDimension(i);
    if(dim < 2){
      int numNodes = data->getNumNodes(i);
      int numComp = data->getNumComponents(i);
      for(int ts = 0; ts < data->getNumTimeSteps(); ts++){
	if(opt->Type == PViewOptions::Plot2DSpace) ts = opt->TimeStep;
	for(int j = 0; j < numNodes; j++){
	  double val[9], xyz[3];
	  data->getNode(i, j, xyz[0], xyz[1], xyz[2]);
	  for(int k = 0; k < numComp; k++)
	    data->getValue(i, j, k, ts, val[k]);
	  double vx = ComputeScalarRep(3, xyz);
	  double vy = ComputeScalarRep(numComp, val);
	  if(opt->Type == PViewOptions::Plot2DTime){
	    x.push_back(ts);
	    y[i].push_back(vy);
	  }
	  else if(opt->Type == PViewOptions::Plot2DSpace){
	    x.push_back(vx);
	    y[0].push_back(vy);
	  }
	}
	if(opt->Type == PViewOptions::Plot2DSpace) break;
      }
    }
  }

  if(x.empty()) return false;

  xmin = xmax = x[0];
  ymin = ymax = y[0][0];
  for(unsigned int i = 1; i < x.size(); i++){
    xmin = std::min(xmin, x[i]);
    xmax = std::max(xmax, x[i]);
    for(unsigned int j = 0; j < y.size(); j++){
      ymin = std::min(ymin, y[j][i]);
      ymax = std::max(ymax, y[j][i]);
    }
  }

  return true;
}

static void drawGraphAxes(PView *p, double xleft, double ytop, double width,
			  double height, double xmin, double xmax)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  if(!opt->Axes) return;

  char label[1024];    
  float font_h = gl_height() ? gl_height() : 1; // total font height
  float font_a = font_h - gl_descent(); // height above ref. point

  const double tic = 5.;

  glPointSize(CTX.point_size);
  gl2psPointSize(CTX.point_size * CTX.print.eps_point_size_factor);

  glLineWidth(CTX.line_width);
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);

  glColor4ubv((GLubyte *) & opt->color.axes);

  // bare axes
  glBegin(GL_LINE_STRIP);
  glVertex2d(xleft, ytop);
  glVertex2d(xleft, ytop - height);
  glVertex2d(xleft + width, ytop - height);
  if(opt->Axes > 1) {
    glVertex2d(xleft + width, ytop);
    glVertex2d(xleft, ytop);
  }
  glEnd();

  // y label
  if(opt->Type == PViewOptions::Plot2DSpace){
    int nt = data->getNumTimeSteps();
    if((opt->ShowTime == 1 && nt > 1) || opt->ShowTime == 2){
      char tmp[256];
      sprintf(tmp, opt->Format, data->getTime(opt->TimeStep));
      sprintf(label, "%s (%s)", data->getName().c_str(), tmp);
    }
    else if((opt->ShowTime == 3 && nt > 1) || opt->ShowTime == 4){
      sprintf(label, "%s (%d)", data->getName().c_str(), opt->TimeStep);
    }
    else
      sprintf(label, "%s", data->getName().c_str());
  }
  else
    sprintf(label, "%s", data->getName().c_str());
  glRasterPos2d(xleft, ytop + font_h + tic);
  Draw_String_Center(label);
  
  // x label
  sprintf(label, "%s", opt->AxesLabel[0]);
  glRasterPos2d(xleft + width / 2, ytop - height - 2 * font_h - 2 * tic);
  Draw_String_Center(label);

  // y tics and horizontal grid
  if(opt->NbIso > 0){
    int nb = opt->NbIso;
    if(opt->ShowScale && (opt->NbIso * font_h > height))
      nb = (int)floor(height / font_h);
    double dy = height / (double)nb;
    double dv = (opt->TmpMax - opt->TmpMin) / (double)nb;
    for(int i = 0; i < nb + 1; i++){
      if(opt->Axes > 0){
	glBegin(GL_LINES);
	glVertex2d(xleft, ytop - i * dy);
	glVertex2d(xleft + tic, ytop - i * dy);
	if(opt->Axes > 1) {
	  glVertex2d(xleft + width - tic, ytop - i * dy);
	  glVertex2d(xleft + width, ytop - i * dy);
	}
	glEnd();
	if(opt->Axes > 2 && i != 0 && i != nb) {
	  glEnable(GL_LINE_STIPPLE);
	  glLineStipple(1, 0x1111);
	  gl2psEnable(GL2PS_LINE_STIPPLE);
	  gl2psLineWidth(1. * CTX.print.eps_line_width_factor);
	  glBegin(GL_LINES);
	  glVertex2d(xleft, ytop - i * dy);
	  glVertex2d(xleft + width, ytop - i * dy);
	  glEnd();
	  glDisable(GL_LINE_STIPPLE);
	  gl2psDisable(GL2PS_LINE_STIPPLE);
	  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
	}
      }
      if(opt->ShowScale) {
	sprintf(label, opt->Format, (i == nb) ? opt->TmpMin : (opt->TmpMax - i * dv));
	glRasterPos2d(xleft - 2 * tic, ytop - i * dy - font_a / 3.);
	Draw_String_Right(label);
      }
    }
  }

  // x tics and vertical grid
  if(opt->AxesTics[0] > 0){
    int nb = opt->AxesTics[0];
    if(opt->Axes) {
      sprintf(label, opt->AxesFormat[0], - M_PI * 1.e-4);
      if((nb - 1) * gl_width(label) > width)
	nb = (int)(width / gl_width(label)) + 1;
    }
    if(nb == 1) nb++;
    
    double dx = width / (double)(nb - 1);
    double ybot = ytop - height;
    
    for(int i = 0; i < nb; i++) {
      if(opt->Axes) {
	glBegin(GL_LINES);
	glVertex2d(xleft + i * dx, ybot);
	glVertex2d(xleft + i * dx, ybot + tic);
	if(opt->Axes > 1) {
	  glVertex2d(xleft + i * dx, ytop);
	  glVertex2d(xleft + i * dx, ytop - tic);
	}
	glEnd();
	if(opt->Axes > 2 && i != 0 && i != nb - 1) {
	  glEnable(GL_LINE_STIPPLE);
	  glLineStipple(1, 0x1111);
	  gl2psEnable(GL2PS_LINE_STIPPLE);
	  gl2psLineWidth(1. * CTX.print.eps_line_width_factor);
	  glBegin(GL_LINES);
	  glVertex2d(xleft + i * dx, ytop);
	  glVertex2d(xleft + i * dx, ybot);
	  glEnd();
	  glDisable(GL_LINE_STIPPLE);
	  gl2psDisable(GL2PS_LINE_STIPPLE);
	  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
	}
	
	if(nb == 1)
	  sprintf(label, opt->AxesFormat[0], xmin);
	else
	  sprintf(label, opt->AxesFormat[0],
		  xmin + i * (xmax - xmin) / (double)(nb - 1));
	glRasterPos2d(xleft + i * dx, ybot - font_h - tic);
	Draw_String_Center(label);
      }
    }
  }
  
}

static void addGraphPoint(PView *p, double xleft, double ytop, double width, 
			  double height, double x, double y, double xmin, 
			  double xmax, double ymin, double ymax)
{
  PViewOptions *opt = p->getOptions();

  double px = xleft;
  if(xmin != xmax) px += (x - xmin) / (xmax - xmin) * width;

  if(opt->SaturateValues) {
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
    glColor4ubv((GLubyte *) &col);
    if(opt->IntervalsType == PViewOptions::Numeric) {
      glRasterPos2d(px + 3, py + 3);
      char label[256];
      sprintf(label, opt->Format, y);
      Draw_String(label);
    }
    else
      glVertex2d(px, py);
  }
}

static void drawGraphCurves(PView *p, double xleft, double ytop, double width,
			    double height, std::vector<double> &x, double xmin,
			    double xmax, std::vector<std::vector<double> > &y)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  glPointSize(opt->PointSize);
  gl2psPointSize(opt->PointSize * CTX.print.eps_point_size_factor);

  glLineWidth(opt->LineWidth);
  gl2psLineWidth(opt->LineWidth * CTX.print.eps_line_width_factor);

  if(opt->IntervalsType == PViewOptions::Iso ||
     opt->IntervalsType == PViewOptions::Discrete ||
     opt->IntervalsType == PViewOptions::Numeric){
    glBegin(GL_POINTS);
    for(unsigned int i = 0; i < y.size(); i++)
      for(unsigned int j = 0; j < x.size(); j++)
	addGraphPoint(p, xleft, ytop, width, height, x[j], y[i][j], 
		      xmin, xmax, opt->TmpMin, opt->TmpMax);
    glEnd();    
  }

  if(opt->IntervalsType == PViewOptions::Discrete ||
     opt->IntervalsType == PViewOptions::Continuous){
    for(unsigned int i = 0; i < y.size(); i ++) {
      if(opt->UseStipple){
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(opt->Stipple[i % 10][0], opt->Stipple[i % 10][1]);
	gl2psEnable(GL2PS_LINE_STIPPLE);
      }
      glBegin(GL_LINE_STRIP);
      for(unsigned int j = 0; j < x.size(); j++)
	addGraphPoint(p, xleft, ytop, width, height, x[j], y[i][j], 
		      xmin, xmax, opt->TmpMin, opt->TmpMax);
      glEnd();
      if(opt->UseStipple){
	glDisable(GL_LINE_STIPPLE);
	gl2psDisable(GL2PS_LINE_STIPPLE);
      }
    }
  }
}

static void drawGraph(PView *p, double xleft, double ytop, double width, double height)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();
  
  if(opt->RangeType == PViewOptions::Custom){
    opt->TmpMin = opt->CustomMin;
    opt->TmpMax = opt->CustomMax;
  }
  else if(opt->RangeType == PViewOptions::PerTimeStep){
    opt->TmpMin = data->getMin(opt->TimeStep);
    opt->TmpMax = data->getMax(opt->TimeStep);
  }
  else{
    opt->TmpMin = data->getMin();
    opt->TmpMax = data->getMax();
  }
  
  std::vector<double> x;
  std::vector<std::vector<double> > y;
  double xmin, xmax, ymin, ymax;
  if(!getGraphData(p, x, xmin, xmax, y, ymin, ymax)) return;
  drawGraphAxes(p, xleft, ytop, width, height, xmin, xmax);
  drawGraphCurves(p, xleft, ytop, width, height, x, xmin, xmax, y);
}

void Draw_Graph2D()
{
  std::vector<PView*> graphs;
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(!data->getDirty() && opt->Visible && opt->Type != PViewOptions::Plot3D)
      graphs.push_back(PView::list[i]);
  }
  if(graphs.empty()) return;

  gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
  double xsep = 0., ysep = 5 * gl_height();
  char label[1024];
  for(unsigned int i = 0; i < graphs.size(); i++) {
    PViewOptions *opt = graphs[i]->getOptions();
    sprintf(label, opt->Format, -M_PI * 1.e-4);
    xsep = std::max(xsep, gl_width(label));
  }
  
  for(unsigned int i = 0; i < graphs.size(); i++) {
    PView *p = graphs[i];
    PViewOptions *opt = graphs[i]->getOptions();
    if(!opt->AutoPosition) {
      double x = opt->Position[0], y = opt->Position[1];
      int center = Fix2DCoordinates(&x, &y);
      drawGraph(p, x - (center & 1 ? opt->Size[0] / 2. : 0), 
		y + (center & 2 ? opt->Size[1] / 2. : 0), 
		opt->Size[0], opt->Size[1]);
    }
    else{
      double winw = CTX.viewport[2] - CTX.viewport[0];
      double winh = CTX.viewport[3] - CTX.viewport[1];
      if(graphs.size() == 1){
	double fracw = 0.75, frach = 0.75;
	double w = fracw * winw - xsep;
	double h = frach * winh - ysep;
	double x = CTX.viewport[0] + (1 - fracw) / 2. * winw;
	double y = CTX.viewport[1] + (1 - frach) / 2. * winh;
	drawGraph(p, x + 0.95 * xsep, CTX.viewport[3] - (y + 0.4 * ysep), w, h);
      }
      else if(graphs.size() == 2){
	double fracw = 0.75, frach = 0.85;
	double w = fracw * winw - xsep;
	double h = frach * winh / 2. - ysep;
	double x = CTX.viewport[0] + (1 - fracw) / 2. * winw;
	double y = CTX.viewport[1] + (1 - frach) / 3. * winh;
	if(i == 1) y += (h + ysep + (1 - frach) / 3. * winh);
	drawGraph(p, x + 0.95 * xsep, CTX.viewport[3] - (y + 0.4 * ysep), w, h);
      }
      else{
	double fracw = 0.85, frach = 0.85;
	double w = fracw * winw / 2. - xsep;
	double h = frach * winh / 2. - ysep;
	double x = CTX.viewport[0] + (1 - fracw) / 3. * winw;
	if(i == 1 || i == 3) x += (w + xsep + (1-fracw)/3. * winw);
	double y = CTX.viewport[1] + (1 - frach) / 3. * winh;
	if(i == 2 || i == 3) y += (h + ysep + (1 - frach) / 3. * winh);
	drawGraph(p, x + 0.95 * xsep, CTX.viewport[3] - (y + 0.4 * ysep), w, h);
      }
    }
  }
}
