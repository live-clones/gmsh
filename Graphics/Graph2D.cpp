// $Id: Graph2D.cpp,v 1.47 2005-03-12 00:59:41 geuzaine Exp $
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
#include "Context.h"
#include "Numeric.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "gl2ps.h"

extern Context_T CTX;

// 2D graphics (gnuplot style)

static void getval(Post_View * v, int i, int j, double *p1, double *p2,
                   double *Abs, double *Val)
{
  int k;
  if(v->Type == DRAW_POST_2D_SPACE) {
    for(k = 0; k < 3; k++) {
      List_Read(v->SP, j + k, &p2[k]);
      if(j)
        p1[k] = p2[k] - p1[k];
    }
    *Abs += sqrt(p1[0] * p1[0] + p1[1] * p1[1] + p1[2] * p1[2]);
    for(k = 0; k < 3; k++) {
      p1[k] = p2[k];
    }
    *Val = ((double *)List_Pointer_Fast(v->SP, j + 3))[v->TimeStep];
  }
  else {
    *Abs = *(double *)List_Pointer_Fast(v->Time, j);
    *Val = ((double *)List_Pointer_Fast(v->SP, i + 3))[j];
  }
}

static void addval(Post_View * v, double Abs, double Val,
                   double AbsMin, double AbsMax, double ValMin, double ValMax,
                   double xtop, double width, double ybot, double height,
                   int numeric)
{
  char label[256];
  double x, y;

  if(AbsMax == AbsMin)
    x = xtop;
  else
    x = xtop + (Abs - AbsMin) / (AbsMax - AbsMin) * width;

  if(v->SaturateValues) {
    if(Val > ValMax)
      Val = ValMax;
    else if(Val < ValMin)
      Val = ValMin;
  }

  if(ValMax == ValMin)
    y = ybot;
  else
    y = ybot + (Val - ValMin) / (ValMax - ValMin) * height;

  if(Val >= ValMin && Val <= ValMax) {
    PaletteContinuousLinear(v, ValMin, ValMax, Val);
    if(numeric) {
      glRasterPos2d(x + 3, y + 3);
      sprintf(label, v->Format, Val);
      Draw_String(label);
    }
    else
      glVertex2d(x, y);
  }
}


static void Draw_Graph2D(Post_View * v, double xx, double yy, 
			 double width, double height, double tic)
{
  char label[1024];
  float font_h, font_a;
  int i, i_inc, i_max, j, j_inc, j_max, k, nb;
  double dx, dy, dv;
  double xtop = xx;
  double ytop = CTX.viewport[3] - yy;
  double ybot = ytop - height;
  double Abs, Val, ValMin = 0., ValMax = 0., AbsMin, AbsMax;
  double p1[3], p2[3];

  gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
  font_h = gl_height(); // total font height
  font_a = gl_height() - gl_descent();  // height above ref pt

  switch (v->RangeType) {
  case DRAW_POST_RANGE_DEFAULT:
    ValMin = v->Min;
    ValMax = v->Max;
    break;
  case DRAW_POST_RANGE_CUSTOM:
    ValMin = v->CustomMin;
    ValMax = v->CustomMax;
    break;
  case DRAW_POST_RANGE_PER_STEP:
    if(v->TimeStepMin && v->TimeStepMax){
      ValMin = v->TimeStepMin[v->TimeStep];
      ValMax = v->TimeStepMax[v->TimeStep];
    }
    else{ // possible if the view is empty
      ValMin = v->Min;
      ValMax = v->Max;
    }
    break;
  }

  glPointSize(CTX.point_size);
  gl2psPointSize(CTX.point_size * CTX.print.eps_point_size_factor);

  glLineWidth(CTX.line_width);
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);

  // axes

  if(v->Grid) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glBegin(GL_LINE_STRIP);
    glVertex2d(xtop, ytop);
    glVertex2d(xtop, ytop - height);
    glVertex2d(xtop + width, ybot);
    if(v->Grid > 1) {
      glVertex2d(xtop + width, ytop);
      glVertex2d(xtop, ytop);
    }
    glEnd();
  }

  // y tics + labels

  nb = v->NbIso ? v->NbIso : 1;
  if(v->ShowScale && (v->NbIso * font_h > height))
    nb = (int)floor(height / font_h);

  dy = height / (double)nb;
  dv = (ValMax - ValMin) / (double)nb;
  for(i = 0; i < nb + 1; i++) {
    if(v->Grid > 0) {
      glColor4ubv((GLubyte *) & CTX.color.fg);
      glBegin(GL_LINES);
      glVertex2d(xtop, ytop - i * dy);
      glVertex2d(xtop + tic, ytop - i * dy);
      if(v->Grid > 1) {
        glVertex2d(xtop + width - tic, ytop - i * dy);
        glVertex2d(xtop + width, ytop - i * dy);
      }
      glEnd();
      if(v->Grid > 2 && i != 0 && i != nb) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x1111);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        glLineWidth(1.);
        gl2psLineWidth(1. * CTX.print.eps_line_width_factor);
        glBegin(GL_LINES);
        glVertex2d(xtop, ytop - i * dy);
        glVertex2d(xtop + width, ytop - i * dy);
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
        glLineWidth(CTX.line_width);
        gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
      }
    }
    if(v->ShowScale) {
      glColor4ubv((GLubyte *) & CTX.color.text);
      sprintf(label, v->Format, (i == nb) ? ValMin : (ValMax - i * dv));
      glRasterPos2d(xtop - 2 * tic, ytop - i * dy - font_a / 3.);
      Draw_String_Right(label);
    }
  }

  if(v->ShowScale) {
    glColor4ubv((GLubyte *) & CTX.color.text);
    if(v->Type == DRAW_POST_2D_SPACE &&
       ((v->ShowTime == 1 && List_Nbr(v->Time) > 1) ||
	(v->ShowTime == 2 && List_Nbr(v->Time) > 0))){
      char tmp[256];
      sprintf(tmp, v->Format, *(double *)List_Pointer(v->Time, v->TimeStep));
      sprintf(label, "%s (%s)", v->Name, tmp);
    }
    else
      sprintf(label, "%s", v->Name);
    glRasterPos2d(xtop, ytop + font_h + tic);
    Draw_String_Center(label);
  }

  // x tics + labels

  if(v->Type == DRAW_POST_2D_SPACE) {
    AbsMin = AbsMax = 0.;
    double p1[3] = { 0., 0., 0. }, p2[3];
    for(i = 0; i < List_Nbr(v->SP); i += List_Nbr(v->SP) / v->NbSP) {
      for(k = 0; k < 3; k++) {
        List_Read(v->SP, i + k, &p2[k]);
        if(i)
          p1[k] = p2[k] - p1[k];
      }
      AbsMax += sqrt(p1[0] * p1[0] + p1[1] * p1[1] + p1[2] * p1[2]);
      for(k = 0; k < 3; k++) {
        p1[k] = p2[k];
      }
    }
  }
  else {
    AbsMin = *(double *)List_Pointer(v->Time, 0);
    AbsMax = *(double *)List_Pointer(v->Time, List_Nbr(v->Time) - 1);
  }

  nb = v->NbTics[0];
  if(v->ShowScale) {
    sprintf(label, v->AxesFormat[0], -M_PI/1.e4);
    if((nb-1) * gl_width(label) > width)
      nb = (int)(width / gl_width(label)) + 1;
  }
  if(nb == 1) nb++;

  dx = width / (double)(nb - 1);
  
  for(i = 0; i < nb; i++) {
    if(v->Grid > 0) {
      glColor4ubv((GLubyte *) & CTX.color.fg);
      glBegin(GL_LINES);
      glVertex2d(xtop + i * dx, ybot);
      glVertex2d(xtop + i * dx, ybot + tic);
      if(v->Grid > 1) {
        glVertex2d(xtop + i * dx, ytop);
        glVertex2d(xtop + i * dx, ytop - tic);
      }
      glEnd();
      if(v->Grid > 2 && i != 0 && i != nb - 1) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x1111);
        gl2psEnable(GL2PS_LINE_STIPPLE);
        glLineWidth(1.);
        gl2psLineWidth(1. * CTX.print.eps_line_width_factor);
        glBegin(GL_LINES);
        glVertex2d(xtop + i * dx, ytop);
        glVertex2d(xtop + i * dx, ybot);
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        gl2psDisable(GL2PS_LINE_STIPPLE);
        glLineWidth(CTX.line_width);
        gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
      }
    }
    if(v->ShowScale) {
      glColor4ubv((GLubyte *) & CTX.color.text);
      if(nb == 1)
        sprintf(label, v->AxesFormat[0], AbsMin);
      else
        sprintf(label, v->AxesFormat[0],
                AbsMin + i * (AbsMax - AbsMin) / (double)(nb - 1));
      glRasterPos2d(xtop + i * dx, ybot - font_h - tic);
      Draw_String_Center(label);
    }
  }
  if(v->ShowScale) {
    glColor4ubv((GLubyte *) & CTX.color.text);
    sprintf(label, "%s", v->AxesLabel[0]);
    glRasterPos2d(xtop + width / 2, ybot - 2 * font_h - 2 * tic);
    Draw_String_Center(label);
  }

  // the curve(s)

  glPointSize(v->PointSize);
  gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

  glLineWidth(v->LineWidth);
  gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

  if(v->Type == DRAW_POST_2D_SPACE) {
    i_inc = 1;
    i_max = 1;
    j_inc = List_Nbr(v->SP) / v->NbSP;
    j_max = List_Nbr(v->SP);
  }
  else {
    i_inc = List_Nbr(v->SP) / v->NbSP;
    i_max = List_Nbr(v->SP);
    j_inc = 1;
    j_max = v->TimeStep + 1;
  }

  for(i = 0; i < i_max; i += i_inc) {
    if(v->IntervalsType == DRAW_POST_ISO ||
       v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_NUMERIC) {
      glBegin(GL_POINTS);
      Abs = Val = p1[0] = p1[1] = p1[2] = 0.;
      for(j = 0; j < j_max; j += j_inc) {
        getval(v, i, j, p1, p2, &Abs, &Val);
        addval(v, Abs, Val, AbsMin, AbsMax, ValMin, ValMax, xtop, width, ybot,
               height, 0);
      }
      glEnd();
    }
    if(v->IntervalsType == DRAW_POST_NUMERIC) {
      Abs = Val = p1[0] = p1[1] = p1[2] = 0.;
      for(j = 0; j < j_max; j += j_inc) {
        getval(v, i, j, p1, p2, &Abs, &Val);
        addval(v, Abs, Val, AbsMin, AbsMax, ValMin, ValMax, xtop, width, ybot,
               height, 1);
      }
    }
    if(v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_CONTINUOUS) {
      glBegin(GL_LINE_STRIP);
      Abs = Val = p1[0] = p1[1] = p1[2] = 0.;
      for(j = 0; j < j_max; j += j_inc) {
        getval(v, i, j, p1, p2, &Abs, &Val);
        addval(v, Abs, Val, AbsMin, AbsMax, ValMin, ValMax, xtop, width, ybot,
               height, 0);
      }
      glEnd();
    }

  }

}

void Draw_Graph2D(void)
{
  static List_T *todraw = NULL;

  if(!CTX.post.list)
    return;

  // 2d graphs to draw?

  if(!todraw)
    todraw = List_Create(5, 5, sizeof(Post_View *));
  else
    List_Reset(todraw);

  gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
  char label[1024];
  double largest_number = 0.;

  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    if(v->Visible && !v->Dirty && v->NbSP && v->Type != DRAW_POST_3D){
      List_Add(todraw, &v);
      sprintf(label, v->Format, -M_PI/1.e4);
      if(largest_number < gl_width(label))
	largest_number = gl_width(label);
    }
  }
  
  if(!List_Nbr(todraw))
    return;

  const double tic = 5;
  double xsep = largest_number;
  double ysep = 5 * gl_height();
  
  int num = 0;

  for(int i = 0; i < List_Nbr(todraw); i++) {
    Post_View *v = *(Post_View **) List_Pointer(todraw, i);

    if(!v->AutoPosition2D) {
      Draw_Graph2D(v, v->Position2D[0], v->Position2D[1], v->Size2D[0], v->Size2D[1], tic);
    }
    else{
      double winw = CTX.viewport[2] - CTX.viewport[0];
      double winh = CTX.viewport[3] - CTX.viewport[1];
      if(List_Nbr(todraw) == 1){
	double fracw = 0.75, frach = 0.75;
	double w = fracw * winw - xsep;
	double h = frach * winh - ysep;
	double xmin = CTX.viewport[0] + (1-fracw)/2. * winw;
	double ymin = CTX.viewport[1] + (1-frach)/2. * winh;
	Draw_Graph2D(v, xmin + 0.95*xsep, ymin + 0.4*ysep, w, h, tic);
      }
      else if(List_Nbr(todraw) == 2){
	double fracw = 0.75, frach = 0.85;
	double w = fracw * winw - xsep;
	double h = frach * winh / 2. - ysep;
	double xmin = CTX.viewport[0] + (1-fracw)/2. * winw;
	double ymin = CTX.viewport[1] + (1-frach)/3. * winh;
	if(num == 1) ymin += (h + ysep + (1-frach)/3. * winh);
	Draw_Graph2D(v, xmin + 0.95*xsep, ymin + 0.4*ysep, w, h, tic);
	num++;
      }
      else{
	double fracw = 0.85, frach = 0.85;
	double w = fracw * winw / 2. - xsep;
	double h = frach * winh / 2. - ysep;
	double xmin = CTX.viewport[0] + (1-fracw)/3. * winw;
	if(num == 1 || num == 3) xmin += (w + xsep + (1-fracw)/3. * winw);
	double ymin = CTX.viewport[1] + (1-frach)/3. * winh;
	if(num == 2 || num == 3) ymin += (h + ysep + (1-frach)/3. * winh);
	Draw_Graph2D(v, xmin + 0.95*xsep, ymin + 0.4*ysep, w, h, tic);
	num++;
      }
    }
  }
}

// Text strings

void FixText2DCoordinates(double *x, double *y)
{
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
}

// Parser format: T2(x,y,style){"str","str",...};
// T2D list of double : x,y,style,index,x,y,style,index,...
// T2C list of chars  : string\0,string\0,string\0,string\0,...

// Parser format: T3(x,y,z,style){"str","str",...};
// T3D list of double: x,y,z,style,index,x,y,z,style,index,...
// T3C list of chars: string\0,string\0,string\0,string\0,...

void Draw_Text2D3D(int dim, int timestep, int nb, List_T * td, List_T * tc)
{
  int j, k, l, nbd, index, nbchar;
  char *c;
  double *d1, *d2, style, x, y, z;

  if(dim == 2)
    nbd = 4;
  else if(dim == 3)
    nbd = 5;
  else
    return;

#if 0   //debug
  if(nb) {
    for(j = 0; j < List_Nbr(tc); j++) {
      c = (char *)List_Pointer(tc, j);
      if(*c == '\0')
        printf("|");
      else
        printf("%c", *c);
    }
    printf("\n");
  }
#endif

  for(j = 0; j < nb; j++) {
    d1 = (double *)List_Pointer(td, j * nbd);
    d2 = (double *)List_Pointer_Test(td, (j + 1) * nbd);
    if(dim == 2) {
      x = d1[0];
      y = d1[1];
      z = 0.;
      FixText2DCoordinates(&x, &y);
      style = d1[2];
      index = (int)d1[3];
      if(d2)
        nbchar = (int)d2[3] - index;
      else
        nbchar = List_Nbr(tc) - index;
    }
    else {
      x = d1[0];
      y = d1[1];
      z = d1[2];
      style = d1[3];
      index = (int)d1[4];
      if(d2)
        nbchar = (int)d2[4] - index;
      else
        nbchar = List_Nbr(tc) - index;
    }
    glRasterPos3d(x, y, z);
    c = (char *)List_Pointer(tc, index);
    k = l = 0;
    while(k < nbchar && l != timestep) {
      if(c[k++] == '\0')
        l++;
    }
    if(k < nbchar && l == timestep)
      Draw_String(&c[k], style);
    else
      Draw_String(c, style);
  }
}


void Draw_Text2D(void)
{
  if(!CTX.post.list)
    return;

  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    if(v->Visible && !v->Dirty && v->DrawStrings){
      glColor4ubv((GLubyte *) & v->color.text2d);
      Draw_Text2D3D(2, v->TimeStep, v->NbT2, v->T2D, v->T2C);
    }
  }
}
