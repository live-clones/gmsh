// $Id: Scale.cpp,v 1.56 2005-01-18 05:31:04 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "Views.h"
#include "gl2ps.h"

extern Context_T CTX;

// Even if all computations in these routines are made in window
// coordinates, double precision is used to work at subpixel accuracy

void draw_scale(Post_View * v,
                double xmin, double ymin, double width, double height,
                double tic, int horizontal)
{
  gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
  double font_h = gl_height(); // total font height
  double font_a = gl_height() - gl_descent();  // height above ref pt

  double box;
  if(horizontal){
    box = width / (v->NbIso ? v->NbIso : 1);   // colorscale box width
  }
  else{
    box = height / (v->NbIso ? v->NbIso : 1);   // colorscale box height
  }

  glPointSize(v->PointSize);
  gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

  glLineWidth(v->LineWidth);
  gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

  double ValMin, ValMax;
  if(v->ExternalViewIndex >= 0){
    ValMin = v->ExternalMin;
    ValMax = v->ExternalMax;
  }
  else{
    switch(v->RangeType){
    case DRAW_POST_RANGE_CUSTOM:
      ValMin = v->CustomMin;
      ValMax = v->CustomMax;
      break;
    case DRAW_POST_RANGE_PER_STEP:
      if(v->TimeStepMin && v->TimeStepMax){
	ValMin = v->TimeStepMin[v->TimeStep];
	ValMax = v->TimeStepMax[v->TimeStep];
      }
      else{ // possible of the view is empty
	ValMin = v->Min;
	ValMax = v->Max;
      }
      break;
    case DRAW_POST_RANGE_DEFAULT:
    default:
      ValMin = v->Min;
      ValMax = v->Max;
      break;
    }
  }

  switch (v->ScaleType) {
  case DRAW_POST_LINEAR:
    v->GIFV = GiveIndexFromValue_Lin;
    v->GVFI = GiveValueFromIndex_Lin;
    break;
  case DRAW_POST_LOGARITHMIC:
    v->GIFV = GiveIndexFromValue_Log;
    v->GVFI = GiveValueFromIndex_Log;
    break;
  case DRAW_POST_DOUBLELOGARITHMIC:
    v->GIFV = GiveIndexFromValue_DoubleLog;
    v->GVFI = GiveValueFromIndex_DoubleLog;
    break;
  }

  // colorscale

  for(int i = 0; i < v->NbIso; i++) {
    if(v->IntervalsType == DRAW_POST_DISCRETE) {
      PaletteDiscrete(v, v->NbIso, i);
      glBegin(GL_QUADS);
      if(horizontal){
	glVertex2d(xmin + i * box, ymin);
	glVertex2d(xmin + (i + 1) * box, ymin);
	glVertex2d(xmin + (i + 1) * box, ymin + height);
	glVertex2d(xmin + i * box, ymin + height);
      }
      else{
	glVertex2d(xmin, ymin + i * box);
	glVertex2d(xmin + width, ymin + i * box);
	glVertex2d(xmin + width, ymin + (i + 1) * box);
	glVertex2d(xmin, ymin + (i + 1) * box);
      }
      glEnd();
    }
    else if(v->IntervalsType == DRAW_POST_CONTINUOUS) {
      glBegin(GL_QUADS);
      PaletteContinuousLinear(v, ValMin, ValMax,
			      ValMin + i * (ValMax - ValMin) / 
			      (v->NbIso ? v->NbIso : 1));
      if(horizontal){
	glVertex2d(xmin + i * box, ymin + height);
	glVertex2d(xmin + i * box, ymin);
      }
      else{
	glVertex2d(xmin, ymin + i * box);
	glVertex2d(xmin + width, ymin + i * box);
      }
      PaletteContinuousLinear(v, ValMin, ValMax,
			      ValMin + (i + 1) * (ValMax - ValMin) / 
			      (v->NbIso ? v->NbIso : 1));
      if(horizontal){
	glVertex2d(xmin + (i + 1) * box, ymin);
	glVertex2d(xmin + (i + 1) * box, ymin + height);
      }
      else{
	glVertex2d(xmin + width, ymin + (i + 1) * box);
	glVertex2d(xmin, ymin + (i + 1) * box);
      }
      glEnd();
    }
    else {
      PaletteDiscrete(v, v->NbIso, i);
      glBegin(GL_LINES);
      if(horizontal){
	glVertex2d(xmin + i * box + 0.5 * box, ymin);
	glVertex2d(xmin + i * box + 0.5 * box, ymin + height);
      }
      else{
	glVertex2d(xmin, ymin + i * box + 0.5 * box);
	glVertex2d(xmin + width, ymin + i * box + 0.5 * box);
      }
      glEnd();
    }
  }

  // valuescale

  char label[1024];
  int nbv;
  double cv_box;
  if(horizontal){
    sprintf(label, v->Format, -100*M_PI);
    double estim = gl_width(label);
    nbv = (width/estim > v->NbIso) ? v->NbIso : ((width/estim > 2.) ? -2 : -1);
    cv_box = width / nbv;
  }
  else{
    nbv = (height/font_h > v->NbIso) ? v->NbIso : ((height/font_h > 3.) ? -2 : -1);
    cv_box = height / nbv;
  }

  glColor4ubv((GLubyte *) & CTX.color.text);

  if(nbv < 0) { // only min and max (+ possibly mid value) if not enough room
    if(v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_CONTINUOUS) {
      sprintf(label, v->Format, ValMin);
      if(horizontal){
	glRasterPos2d(xmin, ymin + height + tic);
	Draw_String_Center(label);
      }
      else{
	glRasterPos2d(xmin + width + tic, ymin - font_a / 3.);
	Draw_String(label);
      }
      sprintf(label, v->Format, ValMax);
      if(horizontal){
	glRasterPos2d(xmin + width, ymin + height + tic);
	Draw_String_Center(label);
      }
      else{
	glRasterPos2d(xmin + width + tic, ymin + height - font_a / 3.);
	Draw_String(label);
      }
    }
    else {
      sprintf(label, v->Format, ValMin);
      if(horizontal){
	glRasterPos2d(xmin + (box / 2), ymin + height + tic);
	Draw_String_Center(label);
      }
      else{
	glRasterPos2d(xmin + width + tic, ymin + (box / 2) - font_a / 3.);
	Draw_String(label);
      }
      sprintf(label, v->Format, ValMax);
      if(horizontal){
	glRasterPos2d(xmin + width - (box / 2), ymin + height + tic);
	Draw_String_Center(label);
      }
      else{
	glRasterPos2d(xmin + width + tic, ymin + height - (box / 2) - font_a / 3.);
	Draw_String(label);
      }
    }
    if(nbv == -2){
      double Val = v->GVFI(ValMin, ValMax, v->NbIso, v->NbIso/2);
      sprintf(label, v->Format, Val);
      if(horizontal){
	glRasterPos2d(xmin + width/2., ymin + height + tic);
	Draw_String_Center(label);
      }
      else{
	glRasterPos2d(xmin + width + tic, ymin + height/2 - font_a / 3.);
	Draw_String(label);
      }
    }
  }
  else {
    if(v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_CONTINUOUS) {
      for(int i = 0; i < nbv + 1; i++) {
        double Val = v->GVFI(ValMin, ValMax, nbv + 1, i);
        sprintf(label, v->Format, Val);
	if(horizontal){
	  glRasterPos2d(xmin + i * cv_box, ymin + height + tic);
	  Draw_String_Center(label);
	}
	else{
	  glRasterPos2d(xmin + width + tic, ymin + i * cv_box - font_a / 3.);
	  Draw_String(label);
	}
      }
    }
    else {
      for(int i = 0; i < nbv; i++) {
        double Val = v->GVFI(ValMin, ValMax, nbv, i);
        sprintf(label, v->Format, Val);
	if(horizontal){
	  glRasterPos2d(xmin + (2 * i + 1) * (cv_box / 2), ymin + height + tic);
	  Draw_String_Center(label);
	}
	else{
	  glRasterPos2d(xmin + width + tic, ymin + (2 * i + 1) * (cv_box / 2) - font_a / 3.);
	  Draw_String(label);
	}
      }
    }
  }

  // the label

  if((v->ShowTime == 1 && List_Nbr(v->Time) > 1) ||
     (v->ShowTime == 2 && List_Nbr(v->Time) > 0)){
    char tmp[256];
    sprintf(tmp, v->Format, *(double *)List_Pointer(v->Time, v->TimeStep));
    sprintf(label, "%s (%s)", v->Name, tmp);
  }
  else
    sprintf(label, "%s", v->Name);

  if(horizontal){
    glRasterPos2d(xmin + width / 2., ymin + height + tic + 1.4*font_h);
    Draw_String_Center(label);
  }
  else{
    glRasterPos2d(xmin, ymin - 2 * font_h);
    Draw_String(label);
  }
}

void Draw_Scales(void)
{
  static List_T *todraw = NULL;

  if(!CTX.post.list)
    return;

  // scales to draw?

  if(!todraw)
    todraw = List_Create(5, 5, sizeof(Post_View *));
  else
    List_Reset(todraw);

  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    if(v->Visible && !v->Dirty && v->ShowScale &&
       v->Type == DRAW_POST_3D && !v->TextOnly)
      List_Add(todraw, &v);
  }

  if(!List_Nbr(todraw)) {
    return;
  }

  const double tic = 10., bar_size = 16.;
  double width = 0., width_prev = 0., width_total = 0.;

  gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
  char label[1024];
  double largest_number = 0.;
  for(int i = 0; i < List_Nbr(todraw); i++) {
    Post_View *v = *(Post_View **) List_Pointer(todraw, i);
    sprintf(label, v->Format, -100*M_PI);
    if(largest_number < gl_width(label))
      largest_number = gl_width(label);
  }

  for(int i = 0; i < List_Nbr(todraw); i++) {
    Post_View *v = *(Post_View **) List_Pointer(todraw, i);

    if(!v->AutoPosition) {
	draw_scale(v, 
		   v->Position[0], 
		   CTX.viewport[3] - v->Size[1] - v->Position[1], 
		   v->Size[0], v->Size[1], 
		   tic, CTX.post.horizontal_scales);
    }
    else{
      if(CTX.post.horizontal_scales){
	double ysep = 20.;
	if(List_Nbr(todraw) == 1){
	  double ww = (CTX.viewport[2] - CTX.viewport[0]) / 2.;
	  draw_scale(v, 
		     (CTX.viewport[2] - CTX.viewport[0]) / 2. - ww / 2,
		     CTX.viewport[1] + ysep, 
		     ww, bar_size, 
		     tic, 1);
	}
	else{
	  double xsep = largest_number/4. + (CTX.viewport[2] - CTX.viewport[0])/10.;
	  double ww = (CTX.viewport[2] - CTX.viewport[0] - 4 * xsep) / 2.;
	  if(ww < 20) ww = 20;
	  draw_scale(v, 
		     (CTX.viewport[2] - CTX.viewport[0])/2. - (i%2 ? -xsep/1.5 : ww+xsep/1.5),
		     CTX.viewport[1] + ysep + (i/2) * (bar_size+tic+2*gl_height()+ysep), 
		     ww, bar_size, 
		     tic, 1);
	}
      }
      else{
	double xsep = 20.;
	double dy = 2. * gl_height();
	if(List_Nbr(todraw) == 1){
	  double ysep = (CTX.viewport[3] - CTX.viewport[1]) / 6.;
	  double hh = CTX.viewport[3] - CTX.viewport[1] - 2 * ysep - dy;
	  draw_scale(v, 
		     CTX.viewport[0] + xsep, 
		     CTX.viewport[1] + ysep + dy, 
		     bar_size, hh, 
		     tic, 0);
	}
	else{
	  double ysep = (CTX.viewport[3] - CTX.viewport[1]) / 15.;
	  double hh = (CTX.viewport[3] - CTX.viewport[1] - 3 * ysep - 2.5 * dy) / 2.;
	  draw_scale(v, 
		     CTX.viewport[0] + xsep + width_total + (i / 2) * xsep,
		     CTX.viewport[1] + ysep + dy + (1 - i % 2) * (hh + 1.5 * dy + ysep),
		     bar_size, hh,
		     tic, 0);
	}
	// compute width
	width_prev = width;
	sprintf(label, v->Format, -100*M_PI);
	width = bar_size + tic + gl_width(label);
	if(List_Nbr(v->Time) > 1 && v->ShowTime){
	  char tmp[256];
	  sprintf(tmp, v->Format, *(double *)List_Pointer(v->Time, v->TimeStep));
	  sprintf(label, "%s (%s)", v->Name, tmp);
	}
	else
	  sprintf(label, "%s", v->Name);
	if(gl_width(label) > width)
	  width = gl_width(label);
	if(i % 2)
	  width_total += DMAX(bar_size + width, bar_size + width_prev);
      }
    }
  }
}

