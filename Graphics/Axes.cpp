// $Id: Axes.cpp,v 1.22 2004-11-01 15:10:36 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "gl2ps.h"

extern Context_T CTX;

void Draw_Axes(double s)
{
  double f, g, b, c;

  if(s == 0.)
    return;

  if(!CTX.range[0] && !CTX.range[1] && !CTX.range[2])
    return;

  f = 0.666 * s;
  g = 1.233 * s;
  b = .1 * s;
  c = 0.666 * b;

  glLineWidth(CTX.line_width);
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
  glColor4ubv((GLubyte *) & CTX.color.axes);

  glBegin(GL_LINES);
  if(CTX.range[2] != 0.) {
    // X
    glVertex3d(0., 0., 0.);
    glVertex3d(s, 0., 0.);
    glVertex3d(g - b, b, 0.);
    glVertex3d(g + b, -b, 0.);
    glVertex3d(g, -b, b);
    glVertex3d(g, b, -b);
    // Y
    glVertex3d(0., 0., 0.);
    glVertex3d(0., s, 0.);
    glVertex3d(-b, g + b, 0.);
    glVertex3d(0., g, 0.);
    glVertex3d(0., g, 0.);
    glVertex3d(0., g + b, -b);
    glVertex3d(0., g, 0.);
    glVertex3d(.5 * b, g - b, .5 * b);
    // Z
    glVertex3d(0., 0., 0.);
    glVertex3d(0., 0., s);
    glVertex3d(-b, b, g);
    glVertex3d(0., b, g - b);
    glVertex3d(0., b, g - b);
    glVertex3d(0., -b, g + b);
    glVertex3d(0., -b, g + b);
    glVertex3d(b, -b, g);
  }
  else {
    // X
    glVertex3d(0., 0., 0.);
    glVertex3d(s, 0., 0.);
    glVertex3d(g - c, b, 0.);
    glVertex3d(g + c, -b, 0.);
    glVertex3d(g - c, -b, 0.);
    glVertex3d(g + c, b, 0.);
    // Y
    glVertex3d(0., 0., 0.);
    glVertex3d(0., s, 0.);
    glVertex3d(-c, g + b, 0.);
    glVertex3d(0., g, 0.);
    glVertex3d(0., g, 0.);
    glVertex3d(c, g + b, 0.);
    glVertex3d(0., g, 0.);
    glVertex3d(0., g - b, 0.);
  }
  glEnd();

  glEnable(GL_LINE_STIPPLE);
  glLineStipple(2, 0x0F0F);
  glBegin(GL_LINES);
  if(CTX.range[2] != 0.) {
    glVertex3d(f, 0., 0.);
    glVertex3d(f, 0., f);
    glVertex3d(f, 0., f);
    glVertex3d(0., 0., f);
    glVertex3d(0., 0., f);
    glVertex3d(0., f, f);
    glVertex3d(0., f, f);
    glVertex3d(0., f, 0.);
  }
  glVertex3d(0., f, 0.);
  glVertex3d(f, f, 0.);
  glVertex3d(f, f, 0.);
  glVertex3d(f, 0., 0.);
  glEnd();
  glDisable(GL_LINE_STIPPLE);

}

void Draw_SmallAxes(void)
{
  double l, o, xx, xy, yx, yy, zx, zy, cx, cy;

  l = 30;
  o = 2;

  if(CTX.small_axes_pos[0] > 0)
    cx = CTX.viewport[0] + CTX.small_axes_pos[0];
  else
    cx = CTX.viewport[2] + CTX.small_axes_pos[0];

  if(CTX.small_axes_pos[1] > 0)
    cy = CTX.viewport[3] - CTX.small_axes_pos[1];
  else
    cy = CTX.viewport[1] - CTX.small_axes_pos[1];

  xx = l * CTX.rot[0];
  xy = l * CTX.rot[1];
  yx = l * CTX.rot[4];
  yy = l * CTX.rot[5];
  zx = l * CTX.rot[8];
  zy = l * CTX.rot[9];

  glLineWidth(CTX.line_width);
  gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
  glColor4ubv((GLubyte *) & CTX.color.small_axes);

  glBegin(GL_LINES);
  glVertex2d(cx, cy);
  glVertex2d(cx + xx, cy + xy);
  glVertex2d(cx, cy);
  glVertex2d(cx + yx, cy + yy);
  glVertex2d(cx, cy);
  glVertex2d(cx + zx, cy + zy);
  glEnd();
  glRasterPos2d(cx + xx + o, cy + xy + o);
  Draw_String("X");
  glRasterPos2d(cx + yx + o, cy + yy + o);
  Draw_String("Y");
  glRasterPos2d(cx + zx + o, cy + zy + o);
  Draw_String("Z");

}
