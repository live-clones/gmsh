// $Id: PostElement.cpp,v 1.50 2004-10-26 01:04:53 geuzaine Exp $
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

  if(View->Boundary > 0 || preproNormals)
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
  double Xp[5], Yp[5], Zp[5], Vp[5], Val[5];
  char Num[100];

  if(preproNormals)
    return;

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
      if(ValMin == ValMax)
	k = View->NbIso / 2;
      PaletteDiscrete(View, View->NbIso, k);
      CutLine(X, Y, Z, &Val[0],
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
      if(ValMin == ValMax)
	k = View->NbIso / 2;
      PaletteDiscrete(View, View->NbIso, k);
      IsoLine(View, X, Y, Z, &Val[0],
	      View->GVFI(ValMin, ValMax, View->NbIso, k));
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
  double Xp[10], Yp[10], Zp[10], Vp[10], xx[10], yy[10], zz[10], Val[3];
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
      CutTriangle(X, Y, Z, Val, ValMin, ValMax, Xp, Yp, Zp, &nb, Vp);
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
      if(ValMin == ValMax)
	k = View->NbIso / 2;
      unsigned int col = PaletteDiscrete(View, View->NbIso, k);
      CutTriangle(X, Y, Z, Val,
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
      if(ValMin == ValMax)
	k = View->NbIso / 2;
      PaletteDiscrete(View, View->NbIso, k);
      IsoTriangle(View, X, Y, Z, Val,
		  View->GVFI(ValMin, ValMax, View->NbIso, k));
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
      if(ValMin == ValMax)
	k = View->NbIso / 2;
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

void Draw_ScalarElement(int type, Post_View * View, int preproNormals,
                        double ValMin, double ValMax, 
                        double *X, double *Y, double *Z, double *V)
{
  switch(type){
  case POINT:
    Draw_ScalarPoint(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case LINE:
    Draw_ScalarLine(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case TRIANGLE:
    Draw_ScalarTriangle(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case QUADRANGLE:
    Draw_ScalarQuadrangle(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case TETRAHEDRON:
    Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case HEXAHEDRON:
    Draw_ScalarHexahedron(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case PRISM:
    Draw_ScalarPrism(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case PYRAMID:
    Draw_ScalarPyramid(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  }
}

int GetDataFromOtherView(int type, int nbnod, Post_View *v, int *nbcomp,
			 double *norm, double **vals, int *vectype)
{
  static int error1 = -1;
  static int error2 = -1;
  Post_View *v2 = v->ExternalView;
  int num = v->ExternalElementIndex;

  if(!v2){
    if(error1 != v->Num){
      Msg(GERROR, "Nonexistent external view");
      error1 = v->Num;
    }
    return 0;
  }

  int nbelm = 0, comp = 0;
  List_T *l;
  switch (type) {
  case POINT: 
    if(v->NbVP == v2->NbSP){ nbelm = v2->NbSP; l = v2->SP; comp = 1; }
    else if(v->NbVP == v2->NbVP){ nbelm = v2->NbVP; l = v2->VP; comp = 3; }
    else if(v->NbVP == v2->NbTP){ nbelm = v2->NbTP; l = v2->TP; comp = 9; }
    break;
  case LINE: 
    if(v->NbVL == v2->NbSL){ nbelm = v2->NbSL; l = v2->SL; comp = 1; } 
    else if(v->NbVL == v2->NbVL){ nbelm = v2->NbVL; l = v2->VL; comp = 3; } 
    else if(v->NbVL == v2->NbTL){ nbelm = v2->NbTL; l = v2->TL; comp = 9; } 
    break;
  case TRIANGLE: 
    if(v->NbVT == v2->NbST){ nbelm = v2->NbST; l = v2->ST; comp = 1;  } 
    else if(v->NbVT == v2->NbVT){ nbelm = v2->NbVT; l = v2->VT; comp = 3;  } 
    else if(v->NbVT == v2->NbTT){ nbelm = v2->NbTT; l = v2->TT; comp = 9;  } 
    break;
  case QUADRANGLE: 
    if(v->NbVQ == v2->NbSQ){ nbelm = v2->NbSQ; l = v2->SQ; comp = 1;  } 
    else if(v->NbVQ == v2->NbVQ){ nbelm = v2->NbVQ; l = v2->VQ; comp = 3;  } 
    else if(v->NbVQ == v2->NbTQ){ nbelm = v2->NbTQ; l = v2->TQ; comp = 9;  } 
    break;
  case TETRAHEDRON: 
    if(v->NbVS == v2->NbSS){ nbelm = v2->NbSS; l = v2->SS; comp = 1;  } 
    else if(v->NbVS == v2->NbVS){ nbelm = v2->NbVS; l = v2->VS; comp = 3;  } 
    else if(v->NbVS == v2->NbTS){ nbelm = v2->NbTS; l = v2->TS; comp = 9;  } 
    break;
  case HEXAHEDRON:
    if(v->NbVH == v2->NbSH){ nbelm = v2->NbSH; l = v2->SH; comp = 1;  }
    else if(v->NbVH == v2->NbVH){ nbelm = v2->NbVH; l = v2->VH; comp = 3;  }
    else if(v->NbVH == v2->NbTH){ nbelm = v2->NbTH; l = v2->TH; comp = 9;  }
    break;
  case PRISM:
    if(v->NbVI == v2->NbSI){ nbelm = v2->NbSI; l = v2->SI; comp = 1;  }
    else if(v->NbVI == v2->NbVI){ nbelm = v2->NbVI; l = v2->VI; comp = 3;  }
    else if(v->NbVI == v2->NbTI){ nbelm = v2->NbTI; l = v2->TI; comp = 9;  }
    break;
  case PYRAMID: 
    if(v->NbVY == v2->NbSY){ nbelm = v2->NbSY; l = v2->SY; comp = 1;  } 
    else if(v->NbVY == v2->NbVY){ nbelm = v2->NbVY; l = v2->VY; comp = 3;  } 
    else if(v->NbVY == v2->NbTY){ nbelm = v2->NbTY; l = v2->TY; comp = 9;  } 
    break;
  }

  if(!nbelm || num < 0 || v2->NbTimeStep != v->NbTimeStep){
    if(error2 != v->Num){
      Msg(GERROR, "Incompatible external view");
      error2 = v->Num;
    }
    return 0;
  }

  int nb = List_Nbr(l) / nbelm;
  double *vv = (double *)List_Pointer(l, num * nb + 3 * nbnod + 
				      comp * nbnod * v->TimeStep);
  for(int k = 0; k < nbnod; k++){
    if(comp == 1)
      norm[k] = vv[k];
    else if(comp == 3)
      norm[k] = sqrt(vv[3*k] * vv[3*k] + 
		     vv[3*k+1] * vv[3*k+1] + 
		     vv[3*k+2] * vv[3*k+2]);
    else if(comp == 9)
      norm[k] = ComputeVonMises(vv + 9*k);
  }

  *vals = vv;
  
  switch (v->RangeType) {
  case DRAW_POST_RANGE_DEFAULT:
    v->ExternalMin = v2->Min;
    v->ExternalMax = v2->Max;
    break;
  case DRAW_POST_RANGE_CUSTOM: // yes, take the values from v!
    v->ExternalMin = v->CustomMin;
    v->ExternalMax = v->CustomMax;
    break;
  case DRAW_POST_RANGE_PER_STEP:
    if(v->TimeStepMin && v->TimeStepMax){
      v->ExternalMin = v2->TimeStepMin[v->TimeStep];
      v->ExternalMax = v2->TimeStepMax[v->TimeStep];
    }
    else{
      v->ExternalMin = v2->Min;
      v->ExternalMax = v2->Max;
    }
    break;
  }

  if(v2->VectorType == DRAW_POST_DISPLACEMENT)
    *vectype = DRAW_POST_ARROW3D; // avoid recursion
  else
    *vectype = v2->VectorType;
  *nbcomp = comp;

  return 1;
}

// Vector Elements

void Draw_VectorElement(int type, Post_View * View, int preproNormals,
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

  double Val[8][3], norm[8];
  for(int k = 0; k < nbnod; k++) {
    Val[k][0] = V[3 * nbnod * View->TimeStep + 3 * k];
    Val[k][1] = V[3 * nbnod * View->TimeStep + 3 * k + 1];
    Val[k][2] = V[3 * nbnod * View->TimeStep + 3 * k + 2];
    norm[k] = sqrt(Val[k][0] * Val[k][0] + Val[k][1] * Val[k][1] + Val[k][2] * Val[k][2]);
  }

  int ext_nbcomp = 1, ext_vectype = DRAW_POST_ARROW3D;
  double *ext_vals = &V[3 * nbnod * View->TimeStep];
  double ext_min = ValMin, ext_max = ValMax, ext_norm[8];
  for(int k = 0; k < nbnod; k++)
    ext_norm[k] = norm[k];
  
  if(View->ExternalViewIndex >= 0){
    GetDataFromOtherView(type, nbnod, View, &ext_nbcomp, ext_norm, &ext_vals, &ext_vectype);
    ext_min = View->ExternalMin;
    ext_max = View->ExternalMax;
  }

  double Raise[3][8];
  for(int i = 0; i < 3; i++)
    for(int k = 0; k < nbnod; k++)
      Raise[i][k] = View->Raise[i] * norm[k];

  if(View->VectorType == DRAW_POST_DISPLACEMENT){

    double fact = View->DisplacementFactor;
    double xx[8], yy[8], zz[8];
    for(int k = 0; k < nbnod; k++) {
      xx[k] = X[k] + fact * Val[k][0] + Raise[0][k];
      yy[k] = Y[k] + fact * Val[k][1] + Raise[1][k];
      zz[k] = Z[k] + fact * Val[k][2] + Raise[2][k];
    }
    
    int ts = View->TimeStep;
    View->TimeStep = 0;
    int vt = View->VectorType;
    View->VectorType = ext_vectype;
    
    if(ext_nbcomp == 1){
      Draw_ScalarElement(type, View, preproNormals, ext_min, ext_max, xx, yy, zz, ext_norm);
      if(type == POINT && ts > 0) {  // draw point "trajectory"
	if(View->LineType) {
	  double dx, dy, dz, dx2, dy2, dz2, XX[2], YY[2], ZZ[2];
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
	    double dd = sqrt(dx * dx + dy * dy + dz * dz);
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
	    double dx = V[3 * (ts - j)];
	    double dy = V[3 * (ts - j) + 1];
	    double dz = V[3 * (ts - j) + 2];
	    double dd = sqrt(dx * dx + dy * dy + dz * dz);
	    PaletteContinuous(View, ValMin, ValMax, dd);
	    glVertex3d(X[0] + fact * dx + Raise[0][0],
		       Y[0] + fact * dy + Raise[1][0],
		       Z[0] + fact * dz + Raise[2][0]);
	  }
	  glEnd();
	}
      }
    }
    else if(ext_nbcomp == 3){
      Draw_VectorElement(type, View, preproNormals, ext_min, ext_max, xx, yy, zz, ext_vals);
    }
    else if(ext_nbcomp == 9){
      Draw_TensorElement(type, View, preproNormals, ext_min, ext_max, xx, yy, zz, ext_vals);
    }

    View->TimeStep = ts;
    View->VectorType = vt;
    return;
  }

  if(preproNormals)
    return;

  if(View->ShowElement)
    Draw_ElementBoundary(type, View, X, Y, Z, Raise);

  if(View->ArrowLocation == DRAW_POST_LOCATE_COG ||
     View->IntervalsType == DRAW_POST_NUMERIC) {
    double dd = 0., ext_dd = 0., dx = 0., dy = 0., dz = 0.;
    double xc = 0., yc = 0., zc = 0.;
    for(int k = 0; k < nbnod; k++) {
      dd += norm[k];
      ext_dd += ext_norm[k];
      dx += Val[k][0];
      dy += Val[k][1];
      dz += Val[k][2];
      xc += X[k] + Raise[0][k];
      yc += Y[k] + Raise[1][k];
      zc += Z[k] + Raise[2][k];
    }
    dd /= (double)nbnod;
    ext_dd /= (double)nbnod;
    dx /= (double)nbnod;
    dy /= (double)nbnod;
    dz /= (double)nbnod;
    xc /= (double)nbnod;
    yc /= (double)nbnod;
    zc /= (double)nbnod;

    // allow for some roundoff error due to the computation at the barycenter
    if(ext_dd != 0.0 && 
       ext_dd >= ext_min * (1. - 1.e-15) && 
       ext_dd <= ext_max * (1. + 1.e-15)) {
      if(View->IntervalsType == DRAW_POST_CONTINUOUS)
	PaletteContinuous(View, ext_min, ext_max, ext_dd);
      else
	PaletteDiscrete(View, View->NbIso,
			View->GIFV(ext_min, ext_max, View->NbIso, ext_dd));
      if(View->IntervalsType == DRAW_POST_NUMERIC) {
	char Num[100];
        glRasterPos3d(xc, yc, zc);
        sprintf(Num, View->Format, ext_dd);
        Draw_String(Num);
      }
      else {
        double fact = CTX.pixel_equiv_x / CTX.s[0] * View->ArrowSize / 
	  (View->ArrowSizeProportional ? ValMax : dd);
        if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin > 0) {
          dx /= dd;
          dy /= dd;
          dz /= dd;
          dd = log10(dd / ValMin);
          dx *= dd;
          dy *= dd;
          dz *= dd;
        }
        Draw_Vector(View->VectorType, View->IntervalsType != DRAW_POST_ISO,
		    View->ArrowRelHeadRadius, View->ArrowRelStemLength,
		    View->ArrowRelStemRadius, xc, yc, zc, 
		    fact * dx, fact * dy, fact * dz, NULL, View->Light);
      }
    }
  }
  else {
    for(int k = 0; k < nbnod; k++) {
      if(ext_norm[k] != 0.0 && ext_norm[k] >= ext_min && ext_norm[k] <= ext_max) {
	if(View->IntervalsType == DRAW_POST_CONTINUOUS)
	  PaletteContinuous(View, ext_min, ext_max, ext_norm[k]);
	else
	  PaletteDiscrete(View, View->NbIso,
			  View->GIFV(ext_min, ext_max, View->NbIso, ext_norm[k]));
        double fact = CTX.pixel_equiv_x / CTX.s[0] * View->ArrowSize /
	  (View->ArrowSizeProportional ? ValMax : norm[k]);
        if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin > 0) {
          Val[k][0] /= norm[k];
          Val[k][1] /= norm[k];
          Val[k][2] /= norm[k];
          norm[k] = log10(norm[k] / ValMin);
          Val[k][0] *= norm[k];
          Val[k][1] *= norm[k];
          Val[k][2] *= norm[k];
        }
	for(int i = 0; i < 3; i++)
	  Raise[i][0] = View->Raise[i] * norm[k];
        Draw_Vector(View->VectorType, View->IntervalsType != DRAW_POST_ISO,
		    View->ArrowRelHeadRadius, View->ArrowRelStemLength,
		    View->ArrowRelStemRadius, X[k], Y[k], Z[k], 
		    fact * Val[k][0], fact * Val[k][1], fact * Val[k][2], 
		    Raise, View->Light);
      }
    }
  }
}

#define ARGS Post_View *View, int preproNormals, \
             double ValMin, double ValMax, 	 \
             double *X, double *Y, double *Z, double *V

void Draw_VectorPoint(ARGS)
{
  Draw_VectorElement(POINT, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorLine(ARGS)
{
  Draw_VectorElement(LINE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorTriangle(ARGS)
{
  Draw_VectorElement(TRIANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorTetrahedron(ARGS)
{
  Draw_VectorElement(TETRAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorQuadrangle(ARGS)
{
  Draw_VectorElement(QUADRANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorHexahedron(ARGS)
{
  Draw_VectorElement(HEXAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorPrism(ARGS)
{
  Draw_VectorElement(PRISM, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorPyramid(ARGS)
{
  Draw_VectorElement(PYRAMID, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

#undef ARGS

// Tensor Elements

void Draw_TensorElement(int type, Post_View * View, int preproNormals,
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

  Draw_ScalarElement(type, View, preproNormals, ValMin, ValMax, X, Y, Z, V_VonMises);

  View->TimeStep = ts;
}

#define ARGS Post_View *View, int preproNormals, \
             double ValMin, double ValMax, 	 \
             double *X, double *Y, double *Z, double *V

void Draw_TensorPoint(ARGS)
{
  Draw_TensorElement(POINT, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorLine(ARGS)
{
  Draw_TensorElement(LINE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorTriangle(ARGS)
{
  Draw_TensorElement(TRIANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorTetrahedron(ARGS)
{
  Draw_TensorElement(TETRAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorQuadrangle(ARGS)
{
  Draw_TensorElement(QUADRANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorHexahedron(ARGS)
{
  Draw_TensorElement(HEXAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorPrism(ARGS)
{
  Draw_TensorElement(PRISM, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorPyramid(ARGS)
{
  Draw_TensorElement(PYRAMID, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

#undef ARGS
