// $Id: Scale.cpp,v 1.36 2003-11-28 19:15:29 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

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

extern double GiveValueFromIndex_Lin(double ValMin, double ValMax, int NbIso,
                                     int Iso);
extern double GiveValueFromIndex_Log(double ValMin, double ValMax, int NbIso,
                                     int Iso);
extern int GiveIndexFromValue_Lin(double ValMin, double ValMax, int NbIso,
                                  double Val);
extern int GiveIndexFromValue_Log(double ValMin, double ValMax, int NbIso,
                                  double Val);

void draw_scale(Post_View * v,
                double xmin, double ymin, double width, double height,
                double tic, double space, double dx, double dy)
{
  int i, nbv;
  double font_h, font_a;
  double cs_bh, cv_xmin, cv_bh;
  char label[1024];
  double Val, ValMin, ValMax;

  gl_font(FL_HELVETICA, CTX.gl_fontsize);
  font_h = gl_height(); // total font height
  font_a = gl_height() - gl_descent();  // height above ref pt
  cs_bh = height / (v->NbIso ? v->NbIso : 1);   // colorscale box height
  cv_xmin = xmin + width + tic; // valuescale xmin

  glPointSize(v->PointSize);
  gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

  glLineWidth(v->LineWidth);
  gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

  if(!v->TransparentScale) {
    double dytop = 0.;
    if(v->IntervalsType != DRAW_POST_ISO)
      dytop = font_h / 2.;
    glColor4ubv((GLubyte *) & CTX.color.bg);
    glBegin(GL_QUADS);
    glVertex2d(xmin - space, ymin - dy - space);
    glVertex2d(xmin + width + dx + space, ymin - dy - space);
    glVertex2d(xmin + width + dx + space, ymin + height + dytop + space);
    glVertex2d(xmin - space, ymin + height + dytop + space);
    glEnd();
  }

  if(v->IntervalsType == DRAW_POST_CONTINUOUS)
    glShadeModel(GL_SMOOTH);
  else
    glShadeModel(GL_FLAT);

  if(v->RangeType == DRAW_POST_CUSTOM) {
    ValMin = v->CustomMin;
    ValMax = v->CustomMax;
  }
  else {
    ValMin = v->Min;
    ValMax = v->Max;
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
  }

  // colorscale

  for(i = 0; i < v->NbIso; i++) {
    if(v->IntervalsType == DRAW_POST_DISCRETE) {
      Palette1(v, v->NbIso, i);
      glBegin(GL_QUADS);
      glVertex2d(xmin, ymin + i * cs_bh);
      glVertex2d(xmin + width, ymin + i * cs_bh);
      glVertex2d(xmin + width, ymin + (i + 1) * cs_bh);
      glVertex2d(xmin, ymin + (i + 1) * cs_bh);
      glEnd();
    }
    else if(v->IntervalsType == DRAW_POST_CONTINUOUS) {
      glBegin(GL_QUADS);
      Palette2(v, ValMin, ValMax,
               ValMin + i * (ValMax - ValMin) / (v->NbIso ? v->NbIso : 1));
      glVertex2d(xmin, ymin + i * cs_bh);
      glVertex2d(xmin + width, ymin + i * cs_bh);
      Palette2(v, ValMin, ValMax,
               ValMin + (i + 1) * (ValMax -
                                   ValMin) / (v->NbIso ? v->NbIso : 1));
      glVertex2d(xmin + width, ymin + (i + 1) * cs_bh);
      glVertex2d(xmin, ymin + (i + 1) * cs_bh);
      glEnd();
    }
    else {
      Palette1(v, v->NbIso, i);
      glBegin(GL_LINES);
      glVertex2d(xmin, ymin + i * cs_bh + 0.5 * cs_bh);
      glVertex2d(xmin + width, ymin + i * cs_bh + 0.5 * cs_bh);
      glEnd();
    }
  }

  // valuescale

  nbv = (v->NbIso < floor(height / font_h)) ? v->NbIso : -1;
  cv_bh = height / nbv;

  glColor4ubv((GLubyte *) & CTX.color.text);


  if(nbv < 0) { // only min and max if not enough room
    if(v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_CONTINUOUS) {
      sprintf(label, v->Format, ValMin);
      glRasterPos2d(cv_xmin, ymin - font_a / 3.);
      Draw_String(label);

      sprintf(label, v->Format, ValMax);
      glRasterPos2d(cv_xmin, ymin + height - font_a / 3.);
      Draw_String(label);
    }
    else {
      sprintf(label, v->Format, ValMin);
      glRasterPos2d(cv_xmin, ymin + (cs_bh / 2) - font_a / 3.);
      Draw_String(label);

      sprintf(label, v->Format, ValMax);
      glRasterPos2d(cv_xmin, ymin + height - (cs_bh / 2) - font_a / 3.);
      Draw_String(label);
    }
  }
  else {
    if(v->IntervalsType == DRAW_POST_DISCRETE ||
       v->IntervalsType == DRAW_POST_CONTINUOUS) {
      for(i = 0; i < nbv + 1; i++) {
        Val = v->GVFI(ValMin, ValMax, nbv + 1, i);
        sprintf(label, v->Format, Val);
        glRasterPos2d(cv_xmin, ymin + i * cv_bh - font_a / 3.);
        Draw_String(label);
      }
    }
    else {
      for(i = 0; i < nbv; i++) {
        Val = v->GVFI(ValMin, ValMax, nbv, i);
        sprintf(label, v->Format, Val);
        glRasterPos2d(cv_xmin,
                      ymin + (2 * i + 1) * (cv_bh / 2) - font_a / 3.);
        Draw_String(label);
      }
    }
  }

  // the label

  glRasterPos2d(cv_xmin, ymin - 2 * font_h);
  if((v->ShowTime == 1 && List_Nbr(v->Time) > 1) ||
     (v->ShowTime == 2 && List_Nbr(v->Time) > 0))
    sprintf(label, "%s (%g)", v->Name, *(double *)List_Pointer(v->Time, v->TimeStep));
  else
    sprintf(label, "%s", v->Name);
  Draw_String(label);

}

static List_T *todraw = NULL;

void Draw_Scales(void)
{
  int i;
  double xmin, ymin, width, height, xsep, ysep;
  double oldwidth, totalwidth;
  double dx = 0., dy = 0., tic = 5., space = 10.;
  char label[1024];
  Post_View *v;

  if(!CTX.post.list)
    return;

  // scales to draw?

  if(!todraw)
    todraw = List_Create(5, 5, sizeof(Post_View *));
  else
    List_Reset(todraw);

  for(i = 0; i < List_Nbr(CTX.post.list); i++) {
    v = (Post_View *) List_Pointer(CTX.post.list, i);
    if(v->Visible && !v->Dirty && v->ShowScale &&
       v->Type == DRAW_POST_3D && !v->TextOnly)
      List_Add(todraw, &v);
  }

  if(!List_Nbr(todraw)) {
    return;
  }

  xsep = 20.;
  width = 16.0;
  totalwidth = 0.0;
  if(List_Nbr(todraw) == 1)
    ysep = (CTX.viewport[3] - CTX.viewport[1]) / 6.;
  else
    ysep = (CTX.viewport[3] - CTX.viewport[1]) / 15.;
  xmin = CTX.viewport[0] + xsep;
  ymin = CTX.viewport[1] + ysep;

  for(i = 0; i < List_Nbr(todraw); i++) {
    v = *(Post_View **) List_Pointer(todraw, i);
    oldwidth = width + dx + space;
    dx = dy = 0.;
    gl_font(FL_HELVETICA, CTX.gl_fontsize);
    sprintf(label, v->Format, v->CustomMin);
    if(gl_width(label) + tic > dx)
      dx = gl_width(label) + tic;
    sprintf(label, v->Format, v->CustomMax);
    if(gl_width(label) + tic > dx)
      dx = gl_width(label) + tic;
    if(List_Nbr(v->Time) > 1 && v->ShowTime)
      sprintf(label, "%s (%g)", v->Name,
              *(double *)List_Pointer(v->Time, v->TimeStep));
    else
      sprintf(label, "%s", v->Name);
    if(gl_width(label) + tic > dx)
      dx = gl_width(label) + tic;
    dy = 2. * gl_height();
    if(v->AutoPosition) {
      if(List_Nbr(todraw) == 1) {
        height = CTX.viewport[3] - CTX.viewport[1] - 2 * ysep - dy;
        draw_scale(v, xmin, ymin + dy, width, height, tic, space, dx, dy);
      }
      else {
        height =
          (CTX.viewport[3] - CTX.viewport[1] - 3 * ysep - 2.5 * dy) / 2.;
        draw_scale(v, xmin + totalwidth + (i / 2) * xsep,
                   ymin + dy + (1 - i % 2) * (height + 1.5 * dy + ysep),
                   width, height, tic, space, dx, dy);
      }
      if(i % 2)
        totalwidth += DMAX(width + dx + space, oldwidth);
    }
    else
      draw_scale(v, v->Position[0],
                 CTX.viewport[3] - v->Size[1] - v->Position[1], v->Size[0],
                 v->Size[1], tic, space, dx, dy);
  }


}
