// $Id: PostElement.cpp,v 1.39 2004-07-16 18:02:20 geuzaine Exp $
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
//
// Contributor(s):
//   Laurent Stainier
//   Jean-Luc Flejou

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "Context.h"
#include "Numeric.h"

#define POINT           0
#define LINE            1
#define TRIANGLE        2
#define QUADRANGLE      3
#define TETRAHEDRON     4
#define HEXAHEDRON      5
#define PRISM           6
#define PYRAMID         7

extern Context_T CTX;

void Draw_ElementBoundary(int type, Post_View * View, double *X, double *Y,
                          double *Z, double Raise[3][8])
{
  double xx[8], yy[8], zz[8];

  glColor4ubv((GLubyte *) & CTX.color.fg);
  switch (type) {
  case POINT:
    Draw_Point(View->PointType, View->PointSize, X, Y, Z, Raise, View->Light);
    break;
  case LINE:
    Draw_Line(0, View->LineWidth, X, Y, Z, Raise, View->Light);
    break;
  case TRIANGLE:
    glBegin(GL_LINE_LOOP);
    for(int k = 0; k < 3; k++)
      glVertex3d(X[k] + Raise[0][k], Y[k] + Raise[1][k], Z[k] + Raise[2][k]);
    glEnd();
    break;
  case TETRAHEDRON:
    for(int k = 0; k < 4; k++) {
      xx[k] = X[k] + Raise[0][k];
      yy[k] = Y[k] + Raise[1][k];
      zz[k] = Z[k] + Raise[2][k];
    }
    glBegin(GL_LINES);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glEnd();
    break;
  case QUADRANGLE:
    glBegin(GL_LINE_LOOP);
    for(int k = 0; k < 4; k++)
      glVertex3d(X[k] + Raise[0][k], Y[k] + Raise[1][k], Z[k] + Raise[2][k]);
    glEnd();
    break;
  case HEXAHEDRON:
    for(int k = 0; k < 8; k++) {
      xx[k] = X[k] + Raise[0][k];
      yy[k] = Y[k] + Raise[1][k];
      zz[k] = Z[k] + Raise[2][k];
    }
    glBegin(GL_LINES);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[5], yy[5], zz[5]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[6], yy[6], zz[6]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[7], yy[7], zz[7]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[5], yy[5], zz[5]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[7], yy[7], zz[7]);
    glVertex3d(xx[5], yy[5], zz[5]);
    glVertex3d(xx[6], yy[6], zz[6]);
    glVertex3d(xx[6], yy[6], zz[6]);
    glVertex3d(xx[7], yy[7], zz[7]);
    glEnd();
    break;
  case PRISM:
    for(int k = 0; k < 6; k++) {
      xx[k] = X[k] + Raise[0][k];
      yy[k] = Y[k] + Raise[1][k];
      zz[k] = Z[k] + Raise[2][k];
    }
    glBegin(GL_LINES);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[5], yy[5], zz[5]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[5], yy[5], zz[5]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[5], yy[5], zz[5]);
    glEnd();
    break;
  case PYRAMID:
    for(int k = 0; k < 5; k++) {
      xx[k] = X[k] + Raise[0][k];
      yy[k] = Y[k] + Raise[1][k];
      zz[k] = Z[k] + Raise[2][k];
    }
    glBegin(GL_LINES);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[0], yy[0], zz[0]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[1], yy[1], zz[1]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[3], yy[3], zz[3]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glVertex3d(xx[2], yy[2], zz[2]);
    glVertex3d(xx[4], yy[4], zz[4]);
    glEnd();
    break;
  }
}

void SaturateValues(int saturate, double min, double max,
                    double *v1, double *v2, int nbnod)
{
  if(saturate) {
    for(int i = 0; i < nbnod; i++) {
      if(v1[i] > max)
        v2[i] = max;
      else if(v1[i] < min)
        v2[i] = min;
      else
        v2[i] = v1[i];
    }
  }
  else {
    for(int i = 0; i < nbnod; i++) {
      v2[i] = v1[i];
    }
  }
}

#define REORDER2(e,f)	                			\
    Xp[0] = X[e]; Yp[0] = Y[e]; Zp[0] = Z[e]; Val[0] = vv[e];	\
    Xp[1] = X[f]; Yp[1] = Y[f]; Zp[1] = Z[f]; Val[1] = vv[f]

#define REORDER3(e,f,g)  	        			\
    Xp[0] = X[e]; Yp[0] = Y[e]; Zp[0] = Z[e]; Val[0] = vv[e];	\
    Xp[1] = X[f]; Yp[1] = Y[f]; Zp[1] = Z[f]; Val[1] = vv[f];	\
    Xp[2] = X[g]; Yp[2] = Y[g]; Zp[2] = Z[g]; Val[2] = vv[g]

#define REORDER4(e,f,g,h)	        			\
    Xp[0] = X[e]; Yp[0] = Y[e]; Zp[0] = Z[e]; Val[0] = vv[e];	\
    Xp[1] = X[f]; Yp[1] = Y[f]; Zp[1] = Z[f]; Val[1] = vv[f];	\
    Xp[2] = X[g]; Yp[2] = Y[g]; Zp[2] = Z[g]; Val[2] = vv[g];	\
    Xp[3] = X[h]; Yp[3] = Y[h]; Zp[3] = Z[h]; Val[3] = vv[h]

#define REORDER6(e,f,g,h,i,j)	        			\
    Xp[0] = X[e]; Yp[0] = Y[e]; Zp[0] = Z[e]; Val[0] = vv[e];	\
    Xp[1] = X[f]; Yp[1] = Y[f]; Zp[1] = Z[f]; Val[1] = vv[f];	\
    Xp[2] = X[g]; Yp[2] = Y[g]; Zp[2] = Z[g]; Val[2] = vv[g];	\
    Xp[3] = X[h]; Yp[3] = Y[h]; Zp[3] = Z[h]; Val[3] = vv[h];   \
    Xp[4] = X[i]; Yp[4] = Y[i]; Zp[4] = Z[i]; Val[4] = vv[i];   \
    Xp[5] = X[j]; Yp[5] = Y[j]; Zp[5] = Z[j]; Val[5] = vv[j]

// Scalar Elements

void Draw_ScalarPoint(Post_View * View, int preproNormals,
                      double ValMin, double ValMax,
                      double *X, double *Y, double *Z, double *V)
{
  double d;
  char Num[100];

  if(View->Boundary > 0)
    return;

  d = V[View->TimeStep];

  if(View->SaturateValues) {
    if(d > ValMax)
      d = ValMax;
    else if(d < ValMin)
      d = ValMin;
  }

  double Raise[3][8];
  for(int i = 0; i < 3; i++)
    Raise[i][0] = View->Raise[i] * d;

  if(View->ShowElement)
    Draw_ElementBoundary(POINT, View, X, Y, Z, Raise);

  if(d >= ValMin && d <= ValMax) {
    PaletteContinuous(View, ValMin, ValMax, d);
    if(View->IntervalsType == DRAW_POST_NUMERIC) {
      glRasterPos3d(X[0] + Raise[0][0], Y[0] + Raise[1][0], Z[0] + Raise[2][0]);
      sprintf(Num, View->Format, d);
      Draw_String(Num);
    }
    else
      Draw_Point(View->PointType, View->PointSize, X, Y, Z, Raise, View->Light);
  }
}

void Draw_ScalarLine(Post_View * View, int preproNormals,
                     double ValMin, double ValMax,
                     double *X, double *Y, double *Z, double *V)
{
  int nb = 0;
  double d;
  double Xp[5], Yp[5], Zp[5], Vp[5], Val[5], thev;
  char Num[100];

  double *vv = &V[2 * View->TimeStep];

  if(View->Boundary > 0) {
    View->Boundary--;
    int ts = View->TimeStep;
    View->TimeStep = 0;
    Draw_ScalarPoint(View, 0, ValMin, ValMax, &X[0], &Y[0], &Z[0], &vv[0]); // 0
    Draw_ScalarPoint(View, 0, ValMin, ValMax, &X[1], &Y[1], &Z[1], &vv[1]); // 1
    View->TimeStep = ts;
    View->Boundary++;
    return;
  }

  SaturateValues(View->SaturateValues, ValMin, ValMax, vv, Val, 2);

  double Raise[3][8];
  for(int i = 0; i < 3; i++)
    for(int k = 0; k < 2; k++)
      Raise[i][k] = View->Raise[i] * Val[k];

  if(View->ShowElement)
    Draw_ElementBoundary(LINE, View, X, Y, Z, Raise);

  if(View->IntervalsType == DRAW_POST_NUMERIC) {
    d = (Val[0] + Val[1]) / 2.;
    if(d >= ValMin && d <= ValMax) {
      PaletteContinuous(View, ValMin, ValMax, d);
      sprintf(Num, View->Format, d);
      glRasterPos3d((X[0] + Raise[0][0] + X[1] + Raise[0][1]) / 2.,
                    (Y[0] + Raise[1][0] + Y[1] + Raise[1][1]) / 2.,
                    (Z[0] + Raise[2][0] + Z[1] + Raise[2][1]) / 2.);
      Draw_String(Num);
    }
  }

  if(View->IntervalsType == DRAW_POST_CONTINUOUS) {
    if(Val[0] >= ValMin && Val[0] <= ValMax &&
       Val[1] >= ValMin && Val[1] <= ValMax) {
      if(View->LineType) {
	// not perfect...
	PaletteContinuous(View, ValMin, ValMax, Val[0]);
	Draw_Line(View->LineType, View->LineWidth, X, Y, Z, Raise, View->Light);
      }
      else {
	glBegin(GL_LINES);
	PaletteContinuous(View, ValMin, ValMax, Val[0]);
	glVertex3d(X[0] + Raise[0][0], Y[0] + Raise[1][0], Z[0] + Raise[2][0]);
	PaletteContinuous(View, ValMin, ValMax, Val[1]);
	glVertex3d(X[1] + Raise[0][1], Y[1] + Raise[1][1], Z[1] + Raise[2][1]);
	glEnd();
      }
    }
    else {
      // FIXME: todo
    }
  }

  if(View->IntervalsType == DRAW_POST_DISCRETE) {
    for(int k = 0; k < View->NbIso; k++) {
      PaletteDiscrete(View, View->NbIso, k);
      CutLine1D(X, Y, Z, &Val[0],
		View->GVFI(ValMin, ValMax, View->NbIso + 1, k),
		View->GVFI(ValMin, ValMax, View->NbIso + 1, k + 1),
		Xp, Yp, Zp, &nb, Vp);
      if(nb == 2) {
	for(int i = 0; i < 3; i++)
	  for(int l = 0; l < 2; l++)
	    Raise[i][l] = View->Raise[i] * Vp[l];
	Draw_Line(View->LineType, View->LineWidth, Xp, Yp, Zp, Raise, View->Light);
      }
      if(ValMin == ValMax)
	break;
    }
  }

  if(View->IntervalsType == DRAW_POST_ISO) {
    for(int k = 0; k < View->NbIso; k++) {
      PaletteDiscrete(View, View->NbIso, k);
      thev = View->GVFI(ValMin, ValMax, View->NbIso, k);
      CutLine0D(X, Y, Z, &Val[0], thev, Xp, Yp, Zp, &nb);
      if(nb) {
	for(int i = 0; i < 3; i++)
	  Raise[i][0] = View->Raise[i] * thev;
	Draw_Point(View->PointType, View->PointSize, Xp, Yp, Zp, Raise, View->Light);
      }
      if(ValMin == ValMax)
	break;
    }
  }

}

void Draw_ScalarTriangle(Post_View * View, int preproNormals,
                         double ValMin, double ValMax,
                         double *X, double *Y, double *Z, double *V)
{
  int nb = 0;
  double d;
  double x1x0, y1y0, z1z0, x2x0, y2y0, z2z0, nn[3], norms[30];
  double Xp[10], Yp[10], Zp[10], Vp[10], xx[10], yy[10], zz[10], Val[3], thev;
  char Num[100];

  double *vv = &V[3 * View->TimeStep];

  if(!preproNormals && View->Boundary > 0) {
    View->Boundary--;
    int ts = View->TimeStep;
    View->TimeStep = 0;
    Draw_ScalarLine(View, 0, ValMin, ValMax, &X[0], &Y[0], &Z[0], &vv[0]); // 01
    Draw_ScalarLine(View, 0, ValMin, ValMax, &X[1], &Y[1], &Z[1], &vv[1]); // 12
    REORDER2(0, 2);
    Draw_ScalarLine(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 02
    View->TimeStep = ts;
    View->Boundary++;
    return;
  }

  SaturateValues(View->SaturateValues, ValMin, ValMax, vv, Val, 3);

  double Raise[3][8];
  for(int i = 0; i < 3; i++)
    for(int k = 0; k < 3; k++)
      Raise[i][k] = View->Raise[i] * Val[k];

  if(preproNormals || 
     (View->Light && 
      (!View->TriVertexArray || (View->TriVertexArray && View->TriVertexArray->fill)))) {
    x1x0 = (X[1] + Raise[0][1]) - (X[0] + Raise[0][0]);
    y1y0 = (Y[1] + Raise[1][1]) - (Y[0] + Raise[1][0]);
    z1z0 = (Z[1] + Raise[2][1]) - (Z[0] + Raise[2][0]);
    x2x0 = (X[2] + Raise[0][2]) - (X[0] + Raise[0][0]);
    y2y0 = (Y[2] + Raise[1][2]) - (Y[0] + Raise[1][0]);
    z2z0 = (Z[2] + Raise[2][2]) - (Z[0] + Raise[2][0]);
    nn[0] = y1y0 * z2z0 - z1z0 * y2y0;
    nn[1] = z1z0 * x2x0 - x1x0 * z2z0;
    nn[2] = x1x0 * y2y0 - y1y0 * x2x0;
    norme(nn);
  }

  if(!preproNormals && View->ShowElement)
    Draw_ElementBoundary(TRIANGLE, View, X, Y, Z, Raise);

  if(!preproNormals && View->IntervalsType == DRAW_POST_NUMERIC) {
    d = (Val[0] + Val[1] + Val[2]) / 3.;
    if(d >= ValMin && d <= ValMax) {
      PaletteContinuous(View, ValMin, ValMax, d);
      sprintf(Num, View->Format, d);
      glRasterPos3d((X[0] + Raise[0][0] + X[1] + Raise[0][1] + X[2] + Raise[0][2]) / 3.,
                    (Y[0] + Raise[1][0] + Y[1] + Raise[1][1] + Y[2] + Raise[1][2]) / 3.,
                    (Z[0] + Raise[2][0] + Z[1] + Raise[2][1] + Z[2] + Raise[2][2]) / 3.);
      Draw_String(Num);
    }
  }

  if(View->IntervalsType == DRAW_POST_CONTINUOUS &&
     (preproNormals || !View->TriVertexArray ||
      (View->TriVertexArray && View->TriVertexArray->fill))) {

    if(Val[0] >= ValMin && Val[0] <= ValMax &&
       Val[1] >= ValMin && Val[1] <= ValMax &&
       Val[2] >= ValMin && Val[2] <= ValMax) {
      for(int i = 0; i < 3; i++) {
	xx[i] = X[i] + Raise[0][i];
	yy[i] = Y[i] + Raise[1][i];
	zz[i] = Z[i] + Raise[2][i];
      }
      if(preproNormals){
	for(int i = 0; i < 3; i++)
	  View->normals->add(xx[i], yy[i], zz[i], nn[0], nn[1], nn[2]);
	return;
      }
      for(int i = 0; i < 3; i++) {
	norms[3 * i] = nn[0];
	norms[3 * i + 1] = nn[1];
	norms[3 * i + 2] = nn[2];
      }
      if(View->SmoothNormals)
	for(int i = 0; i < 3; i++)
	  View->normals->get(xx[i], yy[i], zz[i], norms[3*i], norms[3*i+1], norms[3*i+2],
			     View->AngleSmoothNormals);
     
      if(View->TriVertexArray && View->TriVertexArray->fill){
	unsigned int col;
	for(int i = 0; i < 3; i++){
	  col = PaletteContinuous(View, ValMin, ValMax, Val[i]);
	  View->TriVertexArray->add(xx[i], yy[i], zz[i], 
				    norms[3*i], norms[3*i+1], norms[3*i+2], col);
	}
	View->TriVertexArray->num++;
      }
      else{
	if(View->Light) glEnable(GL_LIGHTING);
	if(View->ShowElement) glEnable(GL_POLYGON_OFFSET_FILL);
	glBegin(GL_TRIANGLES);
	for(int i = 0; i < 3; i++){
	  PaletteContinuous(View, ValMin, ValMax, Val[i]);
	  if(View->Light) glNormal3dv(&norms[3*i]);
	  glVertex3d(xx[i], yy[i], zz[i]);
	}
	glEnd();
	glDisable(GL_POLYGON_OFFSET_FILL);
	glDisable(GL_LIGHTING);
      }
    }
    else {
      CutTriangle2D(X, Y, Z, Val, ValMin, ValMax, Xp, Yp, Zp, &nb, Vp);
      if(nb >= 3) {
	for(int i = 0; i < nb; i++) {
	  xx[i] = Xp[i] + View->Raise[0] * Vp[i];
	  yy[i] = Yp[i] + View->Raise[1] * Vp[i];
	  zz[i] = Zp[i] + View->Raise[2] * Vp[i];
	}
	if(preproNormals){
	  for(int i = 0; i < nb; i++)
	    View->normals->add(xx[i], yy[i], zz[i], nn[0], nn[1], nn[2]);
	  return;
	}
	for(int i = 0; i < nb; i++) {
	  norms[3 * i] = nn[0];
	  norms[3 * i + 1] = nn[1];
	  norms[3 * i + 2] = nn[2];
	}
	if(View->SmoothNormals)
	  for(int i = 0; i < nb; i++)
	    View->normals->get(xx[i], yy[i], zz[i], norms[3*i], norms[3*i+1], norms[3*i+2],
			       View->AngleSmoothNormals);
	
	if(View->TriVertexArray && View->TriVertexArray->fill){
	  for(int i = 2; i < nb; i++) {
	    unsigned int col;
	    col = PaletteContinuous(View, ValMin, ValMax, Vp[0]);
	    View->TriVertexArray->add(xx[0], yy[0], zz[0], 
				      norms[0], norms[1], norms[2], col);
	    col = PaletteContinuous(View, ValMin, ValMax, Vp[i-1]);
	    View->TriVertexArray->add(xx[i-1], yy[i-1], zz[i-1],
				      norms[3*(i-1)], norms[3*(i-1)+1], norms[3*(i-1)+2], col);
	    col = PaletteContinuous(View, ValMin, ValMax, Vp[i]);
	    View->TriVertexArray->add(xx[i], yy[i], zz[i], 
				      norms[3*i], norms[3*i+1], norms[3*i+2], col);
	    View->TriVertexArray->num++;	    
	  }
	}
	else{
	  if(View->Light) glEnable(GL_LIGHTING);
	  if(View->ShowElement) glEnable(GL_POLYGON_OFFSET_FILL);
	  glBegin(GL_POLYGON);
	  for(int i = 0; i < nb; i++) {
	    PaletteContinuous(View, ValMin, ValMax, Vp[i]);
	    if(View->Light) glNormal3dv(&norms[3*i]);
	    glVertex3d(xx[i], yy[i], zz[i]);
	  }
	  glEnd();
	  glDisable(GL_POLYGON_OFFSET_FILL);
	  glDisable(GL_LIGHTING);
	}
      }
    }
  }

  if(View->IntervalsType == DRAW_POST_DISCRETE &&
     (preproNormals || !View->TriVertexArray || 
      (View->TriVertexArray && View->TriVertexArray->fill))) {
    for(int k = 0; k < View->NbIso; k++) {
      unsigned int col = PaletteDiscrete(View, View->NbIso, k);
      CutTriangle2D(X, Y, Z, Val,
		    View->GVFI(ValMin, ValMax, View->NbIso + 1, k),
		    View->GVFI(ValMin, ValMax, View->NbIso + 1, k + 1),
		    Xp, Yp, Zp, &nb, Vp);
      if(nb >= 3) {
	for(int i = 0; i < nb; i++) {
	  xx[i] = Xp[i] + View->Raise[0] * Vp[i];
	  yy[i] = Yp[i] + View->Raise[1] * Vp[i];
	  zz[i] = Zp[i] + View->Raise[2] * Vp[i];
	}
	if(preproNormals){
	  for(int i = 0; i < nb; i++)
	    View->normals->add(xx[i], yy[i], zz[i], nn[0], nn[1], nn[2]);
	}
	else{
	  for(int i = 0; i < nb; i++) {
	    norms[3 * i] = nn[0];
	    norms[3 * i + 1] = nn[1];
	    norms[3 * i + 2] = nn[2];
	  }
	  if(View->SmoothNormals)
	    for(int i = 0; i < nb; i++)
	      View->normals->get(xx[i], yy[i], zz[i], norms[3*i], norms[3*i+1], norms[3*i+2],
				 View->AngleSmoothNormals);

	  if(View->TriVertexArray && View->TriVertexArray->fill){
	    for(int i = 2; i < nb; i++) {
	      View->TriVertexArray->add(xx[0], yy[0], zz[0], 
					norms[0], norms[1], norms[2], col);
	      View->TriVertexArray->add(xx[i-1], yy[i-1], zz[i-1],
					norms[3*(i-1)], norms[3*(i-1)+1], norms[3*(i-1)+2], col);
	      View->TriVertexArray->add(xx[i], yy[i], zz[i],
					norms[3*i], norms[3*i+1], norms[3*i+2], col);
	      View->TriVertexArray->num++;
	    }
	  }
	  else{
	    if(View->Light) glEnable(GL_LIGHTING);
	    if(View->ShowElement) glEnable(GL_POLYGON_OFFSET_FILL);
	    glBegin(GL_POLYGON);
	    for(int i = 0; i < nb; i++){
	      if(View->Light) glNormal3dv(&norms[3*i]);
	      glVertex3d(xx[i], yy[i], zz[i]);
	    }
	    glEnd();
	    glDisable(GL_POLYGON_OFFSET_FILL);
	    glDisable(GL_LIGHTING);
	  }
	}
      }
      if(ValMin == ValMax) 
	break;
    }
  }
  
  if(!preproNormals && View->IntervalsType == DRAW_POST_ISO) {
    for(int k = 0; k < View->NbIso; k++) {
      PaletteDiscrete(View, View->NbIso, k);
      thev = View->GVFI(ValMin, ValMax, View->NbIso, k);
      CutTriangle1D(X, Y, Z, Val, thev, Xp, Yp, Zp, &nb);
      if(nb == 2) {
	for(int i = 0; i < 3; i++)
	  for(int l = 0; l < 2; l++)
	    Raise[i][l] = View->Raise[i] * thev;
	Draw_Line(View->LineType, View->LineWidth, Xp, Yp, Zp,
		  Raise, View->Light);
      }
      if(ValMin == ValMax) 
	break;
    }
  }
  
}

void Draw_ScalarTetrahedron(Post_View * View, int preproNormals,
                            double ValMin, double ValMax,
                            double *X, double *Y, double *Z, double *V)
{
  double d, Xp[4], Yp[4], Zp[4];
  char Num[100];
  double Val[4];

  double *vv = &V[4 * View->TimeStep];

  if(!preproNormals && View->Boundary > 0) {
    View->Boundary--;
    int ts = View->TimeStep;
    View->TimeStep = 0;
    REORDER3(0, 2, 1);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 021
    REORDER3(0, 1, 3);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 013
    REORDER3(0, 3, 2);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 032
    REORDER3(3, 1, 2);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 312
    View->TimeStep = ts;
    View->Boundary++;
    return;
  }

  SaturateValues(View->SaturateValues, ValMin, ValMax, vv, Val, 4);

  double Raise[3][8];
  for(int i = 0; i < 3; i++)
    for(int k = 0; k < 4; k++)
      Raise[i][k] = View->Raise[i] * Val[k];

  if(!preproNormals && View->ShowElement)
    Draw_ElementBoundary(TETRAHEDRON, View, X, Y, Z, Raise);

  if(!preproNormals && View->IntervalsType == DRAW_POST_NUMERIC) {
    d = 0.25 * (Val[0] + Val[1] + Val[2] + Val[3]);
    if(d >= ValMin && d <= ValMax) {
      PaletteContinuous(View, ValMin, ValMax, d);
      sprintf(Num, View->Format, d);
      glRasterPos3d(0.25 * (X[0] + Raise[0][0] + X[1] + Raise[0][1] +
                            X[2] + Raise[0][2] + X[3] + Raise[0][3]),
                    0.25 * (Y[0] + Raise[1][0] + Y[1] + Raise[1][1] +
                            Y[2] + Raise[1][2] + Y[3] + Raise[1][3]),
                    0.25 * (Z[0] + Raise[2][0] + Z[1] + Raise[2][1] +
                            Z[2] + Raise[2][2] + Z[3] + Raise[2][3]));
      Draw_String(Num);
    }
  }
  else if(!View->TriVertexArray || (View->TriVertexArray && View->TriVertexArray->fill)){
    for(int k = 0; k < View->NbIso; k++) {
      unsigned int col = PaletteDiscrete(View, View->NbIso, k);
      IsoSimplex(View, preproNormals, X, Y, Z, Val,
                 View->GVFI(ValMin, ValMax, View->NbIso, k), col);
      if(ValMin == ValMax)
	break;
    }
  }
}

void Draw_ScalarQuadrangle(Post_View * View, int preproNormals,
                           double ValMin, double ValMax,
                           double *X, double *Y, double *Z, double *V)
{
  int ts, show = 0;
  double Val[4], Xp[4], Yp[4], Zp[4];
  double *vv = &V[4 * View->TimeStep];

  ts = View->TimeStep;
  View->TimeStep = 0;

  if(!preproNormals && View->Boundary > 0) {
    View->Boundary--;
    Draw_ScalarLine(View, 0, ValMin, ValMax, &X[0], &Y[0], &Z[0], &vv[0]); // 01
    Draw_ScalarLine(View, 0, ValMin, ValMax, &X[1], &Y[1], &Z[1], &vv[1]); // 12
    Draw_ScalarLine(View, 0, ValMin, ValMax, &X[2], &Y[2], &Z[2], &vv[2]); // 23
    REORDER2(0, 3);
    Draw_ScalarLine(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 03
    View->TimeStep = ts;
    View->Boundary++;
    return;
  }

  show = View->ShowElement;
  View->ShowElement = 0;

  if(!preproNormals && show) {
    SaturateValues(View->SaturateValues, ValMin, ValMax, vv, Val, 4);
    double Raise[3][8];
    for(int i = 0; i < 3; i++)
      for(int k = 0; k < 4; k++)
	Raise[i][k] = View->Raise[i] * Val[k];
    Draw_ElementBoundary(QUADRANGLE, View, X, Y, Z, Raise);
  }

  Draw_ScalarTriangle(View, preproNormals, ValMin, ValMax, X, Y, Z, vv); // 012
  REORDER3(0, 2, 3);
  Draw_ScalarTriangle(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val); // 023

  View->TimeStep = ts;
  View->ShowElement = show;
}

void Draw_ScalarHexahedron(Post_View * View, int preproNormals,
                           double ValMin, double ValMax,
                           double *X, double *Y, double *Z, double *V)
{
  int ts, show = 0;
  double Val[8], Xp[8], Yp[8], Zp[8];
  double *vv = &V[8 * View->TimeStep];

  ts = View->TimeStep;
  View->TimeStep = 0;

  if(!preproNormals && View->Boundary > 0) {
    View->Boundary--;
    REORDER4(0, 1, 5, 4);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 0154
    REORDER4(0, 3, 2, 1);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 0321
    REORDER4(0, 4, 7, 3);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 0473
    REORDER4(1, 2, 6, 5);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 1265
    REORDER4(2, 3, 7, 6);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val); // 2376
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, &X[4], &Y[4], &Z[4], &vv[4]); // 4567
    View->TimeStep = ts;
    View->Boundary++;
    return;
  }

  show = View->ShowElement;
  View->ShowElement = 0;

  if(!preproNormals && show) {
    SaturateValues(View->SaturateValues, ValMin, ValMax, vv, Val, 8);
    double Raise[3][8];
    for(int i = 0; i < 3; i++)
      for(int k = 0; k < 8; k++)
	Raise[i][k] = View->Raise[i] * Val[k];
    Draw_ElementBoundary(HEXAHEDRON, View, X, Y, Z, Raise);
  }

  REORDER6(0, 1, 3, 4, 5, 7);
  Draw_ScalarPrism(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);
  REORDER6(1, 2, 3, 5, 6, 7);
  Draw_ScalarPrism(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);

  View->TimeStep = ts;
  View->ShowElement = show;
}

void Draw_ScalarPrism(Post_View * View, int preproNormals,
                      double ValMin, double ValMax,
                      double *X, double *Y, double *Z, double *V)
{
  int ts, show = 0;
  double Val[6], Xp[6], Yp[6], Zp[6];
  double *vv = &V[6 * View->TimeStep];

  ts = View->TimeStep;
  View->TimeStep = 0;

  if(!preproNormals && View->Boundary > 0) {
    View->Boundary--;
    REORDER4(0, 1, 4, 3);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    REORDER3(0, 2, 1);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    REORDER4(0, 3, 5, 2);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    REORDER4(1, 2, 5, 4);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, &X[3], &Y[3], &Z[3], &V[3]);
    View->TimeStep = ts;
    View->Boundary++;
    return;
  }

  show = View->ShowElement;
  View->ShowElement = 0;

  if(!preproNormals && show) {
    SaturateValues(View->SaturateValues, ValMin, ValMax, vv, Val, 6);
    double Raise[3][8];
    for(int i = 0; i < 3; i++)
      for(int k = 0; k < 6; k++)
	Raise[i][k] = View->Raise[i] * Val[k];
    Draw_ElementBoundary(PRISM, View, X, Y, Z, Raise);
  }

  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, X, Y, Z, vv); // 0123
  REORDER4(3, 4, 5, 2);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val); // 3452
  REORDER4(1, 2, 4, 3);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val); // 1243

  View->TimeStep = ts;
  View->ShowElement = show;
}

void Draw_ScalarPyramid(Post_View * View, int preproNormals,
                        double ValMin, double ValMax,
                        double *X, double *Y, double *Z, double *V)
{
  int ts, show = 0;
  double Val[5], Xp[5], Yp[5], Zp[5];
  double *vv = &V[5 * View->TimeStep];

  ts = View->TimeStep;
  View->TimeStep = 0;

  if(!preproNormals && View->Boundary > 0) {
    View->Boundary--;
    REORDER4(0, 3, 2, 1);
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    REORDER3(0, 1, 4);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    REORDER3(1, 2, 4);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    REORDER3(2, 3, 4);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    REORDER3(3, 0, 4);
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, Xp, Yp, Zp, Val);
    View->TimeStep = ts;
    View->Boundary++;
    return;
  }

  show = View->ShowElement;
  View->ShowElement = 0;

  if(!preproNormals && show) {
    SaturateValues(View->SaturateValues, ValMin, ValMax, vv, Val, 6);
    double Raise[3][8];
    for(int i = 0; i < 3; i++)
      for(int k = 0; k < 5; k++)
	Raise[i][k] = View->Raise[i] * Val[k];
    Draw_ElementBoundary(PYRAMID, View, X, Y, Z, Raise);
  }

  REORDER4(0, 1, 2, 4);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);
  REORDER4(2, 3, 0, 4);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);

  View->TimeStep = ts;
  View->ShowElement = show;
}

// Vector Elements

void Draw_VectorElement(int type, Post_View * View,
                        double ValMin, double ValMax, 
                        double *X, double *Y, double *Z, double *V)
{
  int nbnod = 0;
  double fact, xx[8], yy[8], zz[8], xc = 0., yc = 0., zc = 0.;
  double Val[8][3], d[8];
  double dx = 0., dy = 0., dz = 0., dd;
  char Num[100];

  switch (type) {
  case POINT: nbnod = 1; break;
  case LINE: nbnod = 2; break;
  case TRIANGLE: nbnod = 3; break;
  case QUADRANGLE: nbnod = 4; break;
  case TETRAHEDRON: nbnod = 4; break;
  case HEXAHEDRON: nbnod = 8; break;
  case PRISM: nbnod = 6; break;
  case PYRAMID: nbnod = 5; break;
  }

  for(int k = 0; k < nbnod; k++) {
    Val[k][0] = V[3 * nbnod * View->TimeStep + 3 * k];
    Val[k][1] = V[3 * nbnod * View->TimeStep + 3 * k + 1];
    Val[k][2] = V[3 * nbnod * View->TimeStep + 3 * k + 2];
    d[k] = sqrt(Val[k][0] * Val[k][0] + Val[k][1] * Val[k][1] +	Val[k][2] * Val[k][2]);
  }

  double Raise[3][8];
  for(int i = 0; i < 3; i++)
    for(int k = 0; k < nbnod; k++)
      Raise[i][k] = View->Raise[i] * d[k];

  if(View->VectorType == DRAW_POST_DISPLACEMENT) {

    fact = View->DisplacementFactor;
    for(int k = 0; k < nbnod; k++) {
      xx[k] = X[k] + fact * Val[k][0] + Raise[0][k];
      yy[k] = Y[k] + fact * Val[k][1] + Raise[1][k];
      zz[k] = Z[k] + fact * Val[k][2] + Raise[2][k];
    }

    int ts = View->TimeStep;
    View->TimeStep = 0;
    switch (type) {
    case POINT:
      Draw_ScalarPoint(View, 0, ValMin, ValMax, xx, yy, zz, d);
      if(ts) {  //draw trajectory
        if(View->LineType) {
          double dx2, dy2, dz2, XX[2], YY[2], ZZ[2];
	  // warning, warning...
	  Raise[0][1] = Raise[0][0];
	  Raise[1][1] = Raise[1][0];
	  Raise[2][1] = Raise[2][0];
          for(int j = 0; j < ts; j++) {
            dx = V[3 * (ts - j)];
            dy = V[3 * (ts - j) + 1];
            dz = V[3 * (ts - j) + 2];
            dx2 = V[3 * (ts - j - 1)];
            dy2 = V[3 * (ts - j - 1) + 1];
            dz2 = V[3 * (ts - j - 1) + 2];
            dd = sqrt(dx * dx + dy * dy + dz * dz);
            // not perfect...
            PaletteContinuous(View, ValMin, ValMax, dd);
            XX[0] = X[0] + fact * dx;
            XX[1] = X[0] + fact * dx2;
            YY[0] = Y[0] + fact * dy;
            YY[1] = Y[0] + fact * dy2;
            ZZ[0] = Z[0] + fact * dz;
            ZZ[1] = Z[0] + fact * dz2;
            Draw_Line(View->LineType, View->LineWidth, XX, YY, ZZ, Raise, View->Light);
          }
        }
        else {
          glBegin(GL_LINE_STRIP);
          for(int j = 0; j < ts + 1; j++) {
            dx = V[3 * (ts - j)];
            dy = V[3 * (ts - j) + 1];
            dz = V[3 * (ts - j) + 2];
            dd = sqrt(dx * dx + dy * dy + dz * dz);
            PaletteContinuous(View, ValMin, ValMax, dd);
            glVertex3d(X[0] + fact * dx + Raise[0][0],
                       Y[0] + fact * dy + Raise[1][0],
                       Z[0] + fact * dz + Raise[2][0]);
          }
          glEnd();
        }
      }
      break;
    case LINE:
      Draw_ScalarLine(View, 0, ValMin, ValMax, xx, yy, zz, d);
      break;
    case TRIANGLE:
      Draw_ScalarTriangle(View, 0, ValMin, ValMax, xx, yy, zz, d);
      break;
    case TETRAHEDRON:
      Draw_ScalarTetrahedron(View, 0, ValMin, ValMax, xx, yy, zz, d);
      break;
    case QUADRANGLE:
      Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, xx, yy, zz, d);
      break;
    case HEXAHEDRON:
      Draw_ScalarHexahedron(View, 0, ValMin, ValMax, xx, yy, zz, d);
      break;
    case PRISM:
      Draw_ScalarPrism(View, 0, ValMin, ValMax, xx, yy, zz, d);
      break;
    case PYRAMID:
      Draw_ScalarPyramid(View, 0, ValMin, ValMax, xx, yy, zz, d);
      break;
    }
    View->TimeStep = ts;
    return;
  }

  if(View->ShowElement)
    Draw_ElementBoundary(type, View, X, Y, Z, Raise);

  if(View->ArrowLocation == DRAW_POST_LOCATE_COG ||
     View->IntervalsType == DRAW_POST_NUMERIC) {
    for(int k = 0; k < nbnod; k++) {
      dx += Val[k][0];
      xc += X[k] + Raise[0][k];
      dy += Val[k][1];
      yc += Y[k] + Raise[1][k];
      dz += Val[k][2];
      zc += Z[k] + Raise[2][k];
    }
    dx /= (double)nbnod;
    xc /= (double)nbnod;
    dy /= (double)nbnod;
    yc /= (double)nbnod;
    dz /= (double)nbnod;
    zc /= (double)nbnod;
    dd = sqrt(dx * dx + dy * dy + dz * dz);

    // allow for some roundoff error due to the computation at the barycenter
    if(dd != 0.0 && dd >= ValMin * (1. - 1.e-15) && dd <= ValMax * (1. + 1.e-15)) {
      if(View->IntervalsType == DRAW_POST_CONTINUOUS)
	PaletteContinuous(View, ValMin, ValMax, dd);
      else
	PaletteDiscrete(View, View->NbIso,
			View->GIFV(ValMin, ValMax, View->NbIso, dd));
      if(View->IntervalsType == DRAW_POST_NUMERIC) {
        glRasterPos3d(xc, yc, zc);
        sprintf(Num, View->Format, dd);
        Draw_String(Num);
      }
      else {
        fact = CTX.pixel_equiv_x / CTX.s[0] * View->ArrowSize / ValMax;
        if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin > 0) {
          dx /= dd;
          dy /= dd;
          dz /= dd;
          dd = log10(dd / ValMin);
          dx *= dd;
          dy *= dd;
          dz *= dd;
        }
	for(int i = 0; i < 3; i++)
	  Raise[i][0] = View->Raise[i] * dd;
        Draw_Vector(View->VectorType, View->IntervalsType != DRAW_POST_ISO,
		    View->ArrowRelHeadRadius, View->ArrowRelStemLength,
		    View->ArrowRelStemRadius, xc, yc, zc, 
		    fact * dx, fact * dy, fact * dz, Raise, View->Light);
      }
    }
  }
  else {
    for(int k = 0; k < nbnod; k++) {
      if(d[k] != 0.0 && d[k] >= ValMin && d[k] <= ValMax) {
	if(View->IntervalsType == DRAW_POST_CONTINUOUS)
	  PaletteContinuous(View, ValMin, ValMax, d[k]);
	else
	  PaletteDiscrete(View, View->NbIso,
			  View->GIFV(ValMin, ValMax, View->NbIso, d[k]));
        fact = CTX.pixel_equiv_x / CTX.s[0] * View->ArrowSize / ValMax;
        if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin > 0) {
          Val[k][0] /= d[k];
          Val[k][1] /= d[k];
          Val[k][2] /= d[k];
          d[k] = log10(d[k] / ValMin);
          Val[k][0] *= d[k];
          Val[k][1] *= d[k];
          Val[k][2] *= d[k];
        }
	for(int i = 0; i < 3; i++)
	  Raise[i][0] = View->Raise[i] * d[k];
        Draw_Vector(View->VectorType, View->IntervalsType != DRAW_POST_ISO,
		    View->ArrowRelHeadRadius, View->ArrowRelStemLength,
		    View->ArrowRelStemRadius, X[k], Y[k], Z[k], 
		    fact * Val[k][0], fact * Val[k][1], fact * Val[k][2], 
		    Raise, View->Light);
      }
    }
  }
}

#define ARGS Post_View *View, 			\
             double ValMin, double ValMax, 	\
             double *X, double *Y, double *Z, double *V

void Draw_VectorPoint(ARGS)
{
  Draw_VectorElement(POINT, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorLine(ARGS)
{
  Draw_VectorElement(LINE, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorTriangle(ARGS)
{
  Draw_VectorElement(TRIANGLE, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorTetrahedron(ARGS)
{
  Draw_VectorElement(TETRAHEDRON, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorQuadrangle(ARGS)
{
  Draw_VectorElement(QUADRANGLE, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorHexahedron(ARGS)
{
  Draw_VectorElement(HEXAHEDRON, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorPrism(ARGS)
{
  Draw_VectorElement(PRISM, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorPyramid(ARGS)
{
  Draw_VectorElement(PYRAMID, View, ValMin, ValMax, X, Y, Z, V);
}

#undef ARGS

// Tensor Elements

void Draw_TensorElement(int type, Post_View * View,
                        double ValMin, double ValMax,
                        double *X, double *Y, double *Z, double *V)
{
  int nbnod = 0;

  switch (type) {
  case POINT: nbnod = 1; break;
  case LINE: nbnod = 2; break;
  case TRIANGLE: nbnod = 3; break;
  case QUADRANGLE: nbnod = 4; break;
  case TETRAHEDRON: nbnod = 4; break;
  case HEXAHEDRON: nbnod = 8; break;
  case PRISM: nbnod = 6; break;
  case PYRAMID: nbnod = 5; break;
  }

  /// By lack of any current better solution, tensors are displayed as
  /// their Von Mises invariant (J2 invariant); this will simply call
  /// the scalar function...

  // View->TensorType == DRAW_POST_VONMISES 
  int ts = View->TimeStep;
  View->TimeStep = 0;

  double V_VonMises[8];
  for(int i = 0; i < nbnod; i++){
    V_VonMises[i] = ComputeVonMises(V + 9*(i + nbnod * ts));
  }

  switch (type) {
  case POINT:
    Draw_ScalarPoint(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  case LINE:
    Draw_ScalarLine(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  case TRIANGLE:
    Draw_ScalarTriangle(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  case QUADRANGLE:
    Draw_ScalarQuadrangle(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  case TETRAHEDRON:
    Draw_ScalarTetrahedron(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  case HEXAHEDRON:
    Draw_ScalarHexahedron(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  case PRISM:
    Draw_ScalarPrism(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  case PYRAMID:
    Draw_ScalarPyramid(View, 0, ValMin, ValMax, X, Y, Z, V_VonMises);
    break;
  }

  View->TimeStep = ts;
}

#define ARGS Post_View *View, 			\
             double ValMin, double ValMax, 	\
             double *X, double *Y, double *Z, double *V

void Draw_TensorPoint(ARGS)
{
  Draw_TensorElement(POINT, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorLine(ARGS)
{
  Draw_TensorElement(LINE, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorTriangle(ARGS)
{
  Draw_TensorElement(TRIANGLE, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorTetrahedron(ARGS)
{
  Draw_TensorElement(TETRAHEDRON, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorQuadrangle(ARGS)
{
  Draw_TensorElement(QUADRANGLE, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorHexahedron(ARGS)
{
  Draw_TensorElement(HEXAHEDRON, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorPrism(ARGS)
{
  Draw_TensorElement(PRISM, View, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorPyramid(ARGS)
{
  Draw_TensorElement(PYRAMID, View, ValMin, ValMax, X, Y, Z, V);
}

#undef ARGS
