// $Id: PostElement.cpp,v 1.65 2005-05-21 17:27:04 geuzaine Exp $
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

extern Context_T CTX;

void Draw_ElementBoundary(int type, Post_View * View, 
			  double *X, double *Y, double *Z)
{
  switch (type) {
  case POST_POINT:
    glColor4ubv((GLubyte *) & View->color.point);
    Draw_Point(View->PointType, View->PointSize, X, Y, Z, View->Light);
    break;
  case POST_LINE:
    glColor4ubv((GLubyte *) & View->color.line);
    Draw_Line(0, View->LineWidth, X, Y, Z, View->Light);
    break;
  case POST_TRIANGLE:
    glColor4ubv((GLubyte *) & View->color.triangle);
    glBegin(GL_LINE_LOOP);
    for(int k = 0; k < 3; k++)
      glVertex3d(X[k], Y[k], Z[k]);
    glEnd();
    break;
  case POST_TETRAHEDRON:
    glColor4ubv((GLubyte *) & View->color.tetrahedron);
    glBegin(GL_LINES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[3], Y[3], Z[3]);
    glEnd();
    break;
  case POST_QUADRANGLE:
    glColor4ubv((GLubyte *) & View->color.quadrangle);
    glBegin(GL_LINE_LOOP);
    for(int k = 0; k < 4; k++)
      glVertex3d(X[k], Y[k], Z[k]);
    glEnd();
    break;
  case POST_HEXAHEDRON:
    glColor4ubv((GLubyte *) & View->color.hexahedron);
    glBegin(GL_LINES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[5], Y[5], Z[5]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[6], Y[6], Z[6]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[7], Y[7], Z[7]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[5], Y[5], Z[5]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[7], Y[7], Z[7]);
    glVertex3d(X[5], Y[5], Z[5]);
    glVertex3d(X[6], Y[6], Z[6]);
    glVertex3d(X[6], Y[6], Z[6]);
    glVertex3d(X[7], Y[7], Z[7]);
    glEnd();
    break;
  case POST_PRISM:
    glColor4ubv((GLubyte *) & View->color.prism);
    glBegin(GL_LINES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[5], Y[5], Z[5]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[5], Y[5], Z[5]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[5], Y[5], Z[5]);
    glEnd();
    break;
  case POST_PYRAMID:
    glColor4ubv((GLubyte *) & View->color.pyramid);
    glBegin(GL_LINES);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[0], Y[0], Z[0]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[1], Y[1], Z[1]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[3], Y[3], Z[3]);
    glVertex3d(X[4], Y[4], Z[4]);
    glVertex3d(X[2], Y[2], Z[2]);
    glVertex3d(X[4], Y[4], Z[4]);
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

  if(View->ShowElement)
    Draw_ElementBoundary(POST_POINT, View, X, Y, Z);

  if(d >= ValMin && d <= ValMax) {
    PaletteContinuous(View, ValMin, ValMax, d);
    if(View->IntervalsType == DRAW_POST_NUMERIC) {
      glRasterPos3d(X[0], Y[0], Z[0]);
      sprintf(Num, View->Format, d);
      Draw_String(Num);
    }
    else
      Draw_Point(View->PointType, View->PointSize, X, Y, Z, View->Light);
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

  if(View->ShowElement)
    Draw_ElementBoundary(POST_LINE, View, X, Y, Z);

  if(View->Tangents){
    double t[3] = { X[1] - X[0], Y[1] - Y[0], Z[1] - Z[0] };
    norme(t);
    t[0] *= View->Tangents * CTX.pixel_equiv_x / CTX.s[0];
    t[1] *= View->Tangents * CTX.pixel_equiv_x / CTX.s[1];
    t[2] *= View->Tangents * CTX.pixel_equiv_x / CTX.s[2];
    glColor4ubv((GLubyte *) & View->color.tangents);
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
		(X[0] + X[1]) / 2., (Y[0] + Y[1]) / 2.,	(Z[0] + Z[1]) / 2.,
		t[0], t[1], t[2], View->Light);
  }
  
  if(View->IntervalsType == DRAW_POST_NUMERIC) {
    if(View->GlyphLocation == DRAW_POST_LOCATE_COG){
      d = (Val[0] + Val[1]) / 2.;
      if(d >= ValMin && d <= ValMax) {
	PaletteContinuous(View, ValMin, ValMax, d);
	sprintf(Num, View->Format, d);
	glRasterPos3d((X[0] + X[1]) / 2., (Y[0] + Y[1]) / 2., (Z[0] + Z[1]) / 2.);
	Draw_String(Num);
      }
    }
    else{
      for(int i = 0; i < 2; i++){
	if(Val[i] >= ValMin && Val[i] <= ValMax) {
	  PaletteContinuous(View, ValMin, ValMax, Val[i]);
	  sprintf(Num, View->Format, Val[i]);
	  glRasterPos3d(X[i], Y[i], Z[i]);
	  Draw_String(Num);
	}
      }
    }
  }

  if(View->IntervalsType == DRAW_POST_CONTINUOUS) {
    if(Val[0] >= ValMin && Val[0] <= ValMax &&
       Val[1] >= ValMin && Val[1] <= ValMax) {
      if(View->LineType) {
	// not perfect...
	PaletteContinuous(View, ValMin, ValMax, Val[0]);
	Draw_Line(View->LineType, View->LineWidth, X, Y, Z, View->Light);
      }
      else {
	glBegin(GL_LINES);
	PaletteContinuous(View, ValMin, ValMax, Val[0]);
	glVertex3d(X[0], Y[0], Z[0]);
	PaletteContinuous(View, ValMin, ValMax, Val[1]);
	glVertex3d(X[1], Y[1], Z[1]);
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
      if(nb == 2)
	Draw_Line(View->LineType, View->LineWidth, Xp, Yp, Zp, View->Light);
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
  double nn[3], norms[30];
  double Xp[10], Yp[10], Zp[10], Vp[10], Val[3];
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

  if(preproNormals || View->Normals ||
     (View->Light && 
      (!View->TriVertexArray || (View->TriVertexArray && View->TriVertexArray->fill)))) {
    normal3points(X[0], Y[0], Z[0], X[1], Y[1], Z[1], X[2], Y[2], Z[2], nn);
  }

  if(!preproNormals && View->ShowElement)
    Draw_ElementBoundary(POST_TRIANGLE, View, X, Y, Z);

  if(!preproNormals && View->Normals){
    double t[3] = { nn[0], nn[1], nn[2] };
    t[0] *= View->Normals * CTX.pixel_equiv_x / CTX.s[0];
    t[1] *= View->Normals * CTX.pixel_equiv_x / CTX.s[1];
    t[2] *= View->Normals * CTX.pixel_equiv_x / CTX.s[2];
    glColor4ubv((GLubyte *) & View->color.normals);
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
		(X[0] + X[1] + X[2]) / 3.,
		(Y[0] + Y[1] + Y[2]) / 3.,
		(Z[0] + Z[1] + Z[2]) / 3.,
		t[0], t[1], t[2], View->Light);
  }
  
  if(!preproNormals && View->IntervalsType == DRAW_POST_NUMERIC) {
    if(View->GlyphLocation == DRAW_POST_LOCATE_COG){
      d = (Val[0] + Val[1] + Val[2]) / 3.;
      if(d >= ValMin && d <= ValMax) {
	PaletteContinuous(View, ValMin, ValMax, d);
	sprintf(Num, View->Format, d);
	glRasterPos3d((X[0] + X[1] + X[2]) / 3.,
		      (Y[0] + Y[1] + Y[2]) / 3.,
		      (Z[0] + Z[1] + Z[2]) / 3.);
	Draw_String(Num);
      }
    }
    else{
      for(int i = 0; i < 3; i++){
	if(Val[i] >= ValMin && Val[i] <= ValMax) {
	  PaletteContinuous(View, ValMin, ValMax, Val[i]);
	  sprintf(Num, View->Format, Val[i]);
	  glRasterPos3d(X[i], Y[i], Z[i]);
	  Draw_String(Num);
	}
      }
    }
  }

  if(View->IntervalsType == DRAW_POST_CONTINUOUS &&
     (preproNormals || !View->TriVertexArray ||
      (View->TriVertexArray && View->TriVertexArray->fill))) {

    if(Val[0] >= ValMin && Val[0] <= ValMax &&
       Val[1] >= ValMin && Val[1] <= ValMax &&
       Val[2] >= ValMin && Val[2] <= ValMax) {
      if(preproNormals){
	for(int i = 0; i < 3; i++)
	  View->normals->add(X[i], Y[i], Z[i], nn[0], nn[1], nn[2]);
	return;
      }
      for(int i = 0; i < 3; i++) {
	norms[3 * i] = nn[0];
	norms[3 * i + 1] = nn[1];
	norms[3 * i + 2] = nn[2];
      }
      if(View->SmoothNormals)
	for(int i = 0; i < 3; i++)
	  View->normals->get(X[i], Y[i], Z[i], norms[3*i], norms[3*i+1], norms[3*i+2],
			     View->AngleSmoothNormals);
     
      if(View->TriVertexArray && View->TriVertexArray->fill){
	unsigned int col;
	for(int i = 0; i < 3; i++){
	  col = PaletteContinuous(View, ValMin, ValMax, Val[i]);
	  View->TriVertexArray->add(X[i], Y[i], Z[i], 
				    norms[3*i], norms[3*i+1], norms[3*i+2], col);
	}
	View->TriVertexArray->num++;
      }
      else{
	if(View->Light) glEnable(GL_LIGHTING);
	if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
	glBegin(GL_TRIANGLES);
	for(int i = 0; i < 3; i++){
	  PaletteContinuous(View, ValMin, ValMax, Val[i]);
	  if(View->Light) glNormal3dv(&norms[3*i]);
	  glVertex3d(X[i], Y[i], Z[i]);
	}
	glEnd();
	glDisable(GL_POLYGON_OFFSET_FILL);
	glDisable(GL_LIGHTING);
      }
    }
    else {
      CutTriangle(X, Y, Z, Val, ValMin, ValMax, Xp, Yp, Zp, &nb, Vp);
      if(nb >= 3) {
	if(preproNormals){
	  for(int i = 0; i < nb; i++)
	    View->normals->add(Xp[i], Yp[i], Zp[i], nn[0], nn[1], nn[2]);
	  return;
	}
	for(int i = 0; i < nb; i++) {
	  norms[3 * i] = nn[0];
	  norms[3 * i + 1] = nn[1];
	  norms[3 * i + 2] = nn[2];
	}
	if(View->SmoothNormals)
	  for(int i = 0; i < nb; i++)
	    View->normals->get(Xp[i], Yp[i], Zp[i], norms[3*i], norms[3*i+1], norms[3*i+2],
			       View->AngleSmoothNormals);
	
	if(View->TriVertexArray && View->TriVertexArray->fill){
	  for(int i = 2; i < nb; i++) {
	    unsigned int col;
	    col = PaletteContinuous(View, ValMin, ValMax, Vp[0]);
	    View->TriVertexArray->add(Xp[0], Yp[0], Zp[0], 
				      norms[0], norms[1], norms[2], col);
	    col = PaletteContinuous(View, ValMin, ValMax, Vp[i-1]);
	    View->TriVertexArray->add(Xp[i-1], Yp[i-1], Zp[i-1],
				      norms[3*(i-1)], norms[3*(i-1)+1], norms[3*(i-1)+2], col);
	    col = PaletteContinuous(View, ValMin, ValMax, Vp[i]);
	    View->TriVertexArray->add(Xp[i], Yp[i], Zp[i], 
				      norms[3*i], norms[3*i+1], norms[3*i+2], col);
	    View->TriVertexArray->num++;	    
	  }
	}
	else{
	  if(View->Light) glEnable(GL_LIGHTING);
	  if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
	  glBegin(GL_POLYGON);
	  for(int i = 0; i < nb; i++) {
	    PaletteContinuous(View, ValMin, ValMax, Vp[i]);
	    if(View->Light) glNormal3dv(&norms[3*i]);
	    glVertex3d(Xp[i], Yp[i], Zp[i]);
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
	if(preproNormals){
	  for(int i = 0; i < nb; i++)
	    View->normals->add(Xp[i], Yp[i], Zp[i], nn[0], nn[1], nn[2]);
	}
	else{
	  for(int i = 0; i < nb; i++) {
	    norms[3 * i] = nn[0];
	    norms[3 * i + 1] = nn[1];
	    norms[3 * i + 2] = nn[2];
	  }
	  if(View->SmoothNormals)
	    for(int i = 0; i < nb; i++)
	      View->normals->get(Xp[i], Yp[i], Zp[i], norms[3*i], norms[3*i+1], norms[3*i+2],
				 View->AngleSmoothNormals);

	  if(View->TriVertexArray && View->TriVertexArray->fill){
	    for(int i = 2; i < nb; i++) {
	      View->TriVertexArray->add(Xp[0], Yp[0], Zp[0], 
					norms[0], norms[1], norms[2], col);
	      View->TriVertexArray->add(Xp[i-1], Yp[i-1], Zp[i-1],
					norms[3*(i-1)], norms[3*(i-1)+1], norms[3*(i-1)+2], col);
	      View->TriVertexArray->add(Xp[i], Yp[i], Zp[i],
					norms[3*i], norms[3*i+1], norms[3*i+2], col);
	      View->TriVertexArray->num++;
	    }
	  }
	  else{
	    if(View->Light) glEnable(GL_LIGHTING);
	    if(CTX.polygon_offset) glEnable(GL_POLYGON_OFFSET_FILL);
	    glBegin(GL_POLYGON);
	    for(int i = 0; i < nb; i++){
	      if(View->Light) glNormal3dv(&norms[3*i]);
	      glVertex3d(Xp[i], Yp[i], Zp[i]);
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
  
  if(!preproNormals && View->IntervalsType == DRAW_POST_ISO &&
     (!View->LinVertexArray || (View->LinVertexArray && View->LinVertexArray->fill) ||
      View->LineType)){
    for(int k = 0; k < View->NbIso; k++) {
      if(ValMin == ValMax)
	k = View->NbIso / 2;
      unsigned int col = PaletteDiscrete(View, View->NbIso, k);
      IsoTriangle(View, X, Y, Z, Val,
		  View->GVFI(ValMin, ValMax, View->NbIso, k), col);
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

  if(!preproNormals && View->ShowElement)
    Draw_ElementBoundary(POST_TETRAHEDRON, View, X, Y, Z);

  if(!preproNormals && View->IntervalsType == DRAW_POST_NUMERIC) {
    if(View->GlyphLocation == DRAW_POST_LOCATE_COG){
      d = 0.25 * (Val[0] + Val[1] + Val[2] + Val[3]);
      if(d >= ValMin && d <= ValMax) {
	PaletteContinuous(View, ValMin, ValMax, d);
	sprintf(Num, View->Format, d);
	glRasterPos3d(0.25 * (X[0] + X[1] + X[2] + X[3]),
		      0.25 * (Y[0] + Y[1] + Y[2] + Y[3]),
		      0.25 * (Z[0] + Z[1] + Z[2] + Z[3]));
	Draw_String(Num);
      }
    }
    else{
      for(int i = 0; i < 4; i++){
	if(Val[i] >= ValMin && Val[i] <= ValMax) {
	  PaletteContinuous(View, ValMin, ValMax, Val[i]);
	  sprintf(Num, View->Format, Val[i]);
	  glRasterPos3d(X[i], Y[i], Z[i]);
	  Draw_String(Num);
	}
      }
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
    Draw_ElementBoundary(POST_QUADRANGLE, View, X, Y, Z);
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
    Draw_ElementBoundary(POST_HEXAHEDRON, View, X, Y, Z);
  }

  // 6-tet subdivision whose edges match on each pair of opposite faces
  REORDER4(0, 1, 3, 7);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);
  REORDER4(0, 4, 1, 7);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);
  REORDER4(1, 4, 5, 7);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);

  REORDER4(1, 2, 3, 7);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);
  REORDER4(1, 6, 2, 7);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);
  REORDER4(1, 5, 6, 7);
  Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, Xp, Yp, Zp, Val);

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
    Draw_ElementBoundary(POST_PRISM, View, X, Y, Z);
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
    Draw_ElementBoundary(POST_PYRAMID, View, X, Y, Z);
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
  case POST_POINT:
    Draw_ScalarPoint(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case POST_LINE:
    Draw_ScalarLine(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case POST_TRIANGLE:
    Draw_ScalarTriangle(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case POST_QUADRANGLE:
    Draw_ScalarQuadrangle(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case POST_TETRAHEDRON:
    Draw_ScalarTetrahedron(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case POST_HEXAHEDRON:
    Draw_ScalarHexahedron(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case POST_PRISM:
    Draw_ScalarPrism(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  case POST_PYRAMID:
    Draw_ScalarPyramid(View, preproNormals, ValMin, ValMax, X, Y, Z, V);
    break;
  }
}

// Vector Elements

void Draw_VectorElement(int type, Post_View * View, int preproNormals,
                        double ValMin, double ValMax, 
                        double *X, double *Y, double *Z, double *V)
{
  int nbnod = 0;
  switch (type) {
  case POST_POINT: nbnod = 1; break;
  case POST_LINE: nbnod = 2; break;
  case POST_TRIANGLE: nbnod = 3; break;
  case POST_QUADRANGLE: nbnod = 4; break;
  case POST_TETRAHEDRON: nbnod = 4; break;
  case POST_HEXAHEDRON: nbnod = 8; break;
  case POST_PRISM: nbnod = 6; break;
  case POST_PYRAMID: nbnod = 5; break;
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

  if(View->ExternalViewIndex >= 0 &&
     GetValuesFromExternalView(View, type, 3, &ext_nbcomp, &ext_vals, 
			       View->ExternalViewIndex)){
    for(int k = 0; k < nbnod; k++){
      if(ext_nbcomp == 1)
	ext_norm[k] = ext_vals[k];
      else if(ext_nbcomp == 3)
	ext_norm[k] = sqrt(ext_vals[3*k] * ext_vals[3*k] + 
			   ext_vals[3*k+1] * ext_vals[3*k+1] + 
			   ext_vals[3*k+2] * ext_vals[3*k+2]);
      else if(ext_nbcomp == 9)
	ext_norm[k] = ComputeVonMises(ext_vals + 9*k);
    }
    Post_View *v2 = *(Post_View**)List_Pointer_Fast(CTX.post.list, 
						    View->ExternalViewIndex);
    switch (View->RangeType) {
    case DRAW_POST_RANGE_DEFAULT:
      View->ExternalMin = v2->Min;
      View->ExternalMax = v2->Max;
      break;
    case DRAW_POST_RANGE_CUSTOM: // yes, take the values from View!
      View->ExternalMin = View->CustomMin;
      View->ExternalMax = View->CustomMax;
      break;
    case DRAW_POST_RANGE_PER_STEP:
      if(View->TimeStepMin && View->TimeStepMax){
	View->ExternalMin = v2->TimeStepMin[View->TimeStep];
	View->ExternalMax = v2->TimeStepMax[View->TimeStep];
      }
      else{
	View->ExternalMin = v2->Min;
	View->ExternalMax = v2->Max;
      }
      break;
    }
    ext_min = View->ExternalMin;
    ext_max = View->ExternalMax;
    if(v2->VectorType == DRAW_POST_DISPLACEMENT)
      ext_vectype = DRAW_POST_ARROW3D; // avoid recursion
    else
      ext_vectype = v2->VectorType;
  }

  if(View->VectorType == DRAW_POST_DISPLACEMENT){

    double fact = View->DisplacementFactor;
    double xx[8], yy[8], zz[8];
    for(int k = 0; k < nbnod; k++) {
      xx[k] = X[k] + fact * Val[k][0];
      yy[k] = Y[k] + fact * Val[k][1];
      zz[k] = Z[k] + fact * Val[k][2];
      // update the dynamic bounding box
      if(xx[k] < View->TmpBBox[0]) View->TmpBBox[0] = xx[k];
      if(xx[k] > View->TmpBBox[1]) View->TmpBBox[1] = xx[k];
      if(yy[k] < View->TmpBBox[2]) View->TmpBBox[2] = yy[k];
      if(yy[k] > View->TmpBBox[3]) View->TmpBBox[3] = yy[k];
      if(zz[k] < View->TmpBBox[4]) View->TmpBBox[4] = zz[k];
      if(zz[k] > View->TmpBBox[5]) View->TmpBBox[5] = zz[k];
    }
    
    int ts = View->TimeStep;
    View->TimeStep = 0;
    int vt = View->VectorType;
    View->VectorType = ext_vectype;
    
    if(ext_nbcomp == 1){
      Draw_ScalarElement(type, View, preproNormals, ext_min, ext_max, xx, yy, zz, ext_norm);
      if(type == POST_POINT && ts > 0) {  // draw point "trajectory"
	if(View->LineType) {
	  double dx, dy, dz, dx2, dy2, dz2, XX[2], YY[2], ZZ[2];
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
	    Draw_Line(View->LineType, View->LineWidth, XX, YY, ZZ, View->Light);
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
	    glVertex3d(X[0] + fact * dx,
		       Y[0] + fact * dy,
		       Z[0] + fact * dz);
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
    Draw_ElementBoundary(type, View, X, Y, Z);

  double xc = 0., yc = 0., zc = 0.;
  if(View->Normals || View->Tangents || View->GlyphLocation == DRAW_POST_LOCATE_COG){
    for(int k = 0; k < nbnod; k++) {
      xc += X[k];
      yc += Y[k];
      zc += Z[k];
    }
    xc /= (double)nbnod;
    yc /= (double)nbnod;
    zc /= (double)nbnod;
  }

  if(View->Normals && (type == POST_TRIANGLE || type == POST_QUADRANGLE)){
    double nn[3];
    normal3points(X[0], Y[0], Z[0], X[1], Y[1], Z[1], X[2], Y[2], Z[2], nn);
    nn[0] *= View->Normals * CTX.pixel_equiv_x / CTX.s[0];
    nn[1] *= View->Normals * CTX.pixel_equiv_x / CTX.s[1];
    nn[2] *= View->Normals * CTX.pixel_equiv_x / CTX.s[2];
    glColor4ubv((GLubyte *) & View->color.normals);
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
		xc, yc, zc, nn[0], nn[1], nn[2], View->Light);
  }

  if(View->Tangents && (type == POST_LINE)){
    double t[3] = { X[1] - X[0], Y[1] - Y[0], Z[1] - Z[0] };
    norme(t);
    t[0] *= View->Tangents * CTX.pixel_equiv_x / CTX.s[0];
    t[1] *= View->Tangents * CTX.pixel_equiv_x / CTX.s[1];
    t[2] *= View->Tangents * CTX.pixel_equiv_x / CTX.s[2];
    glColor4ubv((GLubyte *) & View->color.tangents);
    Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
		CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
		xc, yc, zc, t[0], t[1], t[2], View->Light);
  }

  if(View->GlyphLocation == DRAW_POST_LOCATE_COG) {
    double dd = 0., ext_dd = 0., dx = 0., dy = 0., dz = 0.;
    for(int k = 0; k < nbnod; k++) {
      dx += Val[k][0];
      dy += Val[k][1];
      dz += Val[k][2];
      // Warning: in the case of a vector view, ext_dd represents the
      // average of the magnitudes of the vectors at the nodes, NOT
      // the magnitude of the vector average.
      ext_dd += ext_norm[k];
    }
    dx /= (double)nbnod;
    dy /= (double)nbnod;
    dz /= (double)nbnod;
    ext_dd /= (double)nbnod;
    dd = sqrt(dx*dx + dy*dy + dz*dz);
    // allow for some roundoff error due to the computation at the barycenter
    if(dd != 0.0 && ext_dd != 0.0 && 
       ext_dd >= ext_min * (1. - 1.e-15) && 
       ext_dd <= ext_max * (1. + 1.e-15)) {
      if(View->IntervalsType == DRAW_POST_CONTINUOUS)
	PaletteContinuous(View, ext_min, ext_max, ext_dd);
      else
	PaletteDiscrete(View, View->NbIso,
			View->GIFV(ext_min, ext_max, View->NbIso, ext_dd));
      if(View->IntervalsType == DRAW_POST_NUMERIC) {
	char Num[100], Numx[100], Numy[100], Numz[100];
        glRasterPos3d(xc, yc, zc);
        sprintf(Numx, View->Format, dx);
        sprintf(Numy, View->Format, dy);
        sprintf(Numz, View->Format, dz);
        sprintf(Num, "(%s,%s,%s)", Numx, Numy, Numz);
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
		    fact * dx, fact * dy, fact * dz, View->Light);
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
	if(View->IntervalsType == DRAW_POST_NUMERIC) {
	  char Num[100], Numx[100], Numy[100], Numz[100];
	  glRasterPos3d(X[k], Y[k], Z[k]);
	  sprintf(Numx, View->Format, Val[k][0]);
	  sprintf(Numy, View->Format, Val[k][1]);
	  sprintf(Numz, View->Format, Val[k][2]);
	  sprintf(Num, "(%s,%s,%s)", Numx, Numy, Numz);
	  Draw_String(Num);
	}
	else{
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
	  Draw_Vector(View->VectorType, View->IntervalsType != DRAW_POST_ISO,
		      View->ArrowRelHeadRadius, View->ArrowRelStemLength,
		      View->ArrowRelStemRadius, X[k], Y[k], Z[k], 
		      fact * Val[k][0], fact * Val[k][1], fact * Val[k][2], 
		      View->Light);
	}
      }
    }
  }
}

#define ARGS Post_View *View, int preproNormals, \
             double ValMin, double ValMax, 	 \
             double *X, double *Y, double *Z, double *V

void Draw_VectorPoint(ARGS)
{
  Draw_VectorElement(POST_POINT, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorLine(ARGS)
{
  Draw_VectorElement(POST_LINE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorTriangle(ARGS)
{
  Draw_VectorElement(POST_TRIANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorTetrahedron(ARGS)
{
  Draw_VectorElement(POST_TETRAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorQuadrangle(ARGS)
{
  Draw_VectorElement(POST_QUADRANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorHexahedron(ARGS)
{
  Draw_VectorElement(POST_HEXAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorPrism(ARGS)
{
  Draw_VectorElement(POST_PRISM, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_VectorPyramid(ARGS)
{
  Draw_VectorElement(POST_PYRAMID, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

#undef ARGS

// Tensor Elements

void Draw_TensorElement(int type, Post_View * View, int preproNormals,
                        double ValMin, double ValMax,
                        double *X, double *Y, double *Z, double *V)
{
  int nbnod = 0;

  switch (type) {
  case POST_POINT: nbnod = 1; break;
  case POST_LINE: nbnod = 2; break;
  case POST_TRIANGLE: nbnod = 3; break;
  case POST_QUADRANGLE: nbnod = 4; break;
  case POST_TETRAHEDRON: nbnod = 4; break;
  case POST_HEXAHEDRON: nbnod = 8; break;
  case POST_PRISM: nbnod = 6; break;
  case POST_PYRAMID: nbnod = 5; break;
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
  Draw_TensorElement(POST_POINT, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorLine(ARGS)
{
  Draw_TensorElement(POST_LINE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorTriangle(ARGS)
{
  Draw_TensorElement(POST_TRIANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorTetrahedron(ARGS)
{
  Draw_TensorElement(POST_TETRAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorQuadrangle(ARGS)
{
  Draw_TensorElement(POST_QUADRANGLE, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorHexahedron(ARGS)
{
  Draw_TensorElement(POST_HEXAHEDRON, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorPrism(ARGS)
{
  Draw_TensorElement(POST_PRISM, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

void Draw_TensorPyramid(ARGS)
{
  Draw_TensorElement(POST_PYRAMID, View, preproNormals, ValMin, ValMax, X, Y, Z, V);
}

#undef ARGS
