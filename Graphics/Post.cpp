// $Id: Post.cpp,v 1.89 2004-12-31 21:12:40 geuzaine Exp $
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
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Context.h"
#include "gl2ps.h"

extern Context_T CTX;

// Give Value from Index

double GiveValueFromIndex_Lin(double ValMin, double ValMax, int NbIso, int Iso)
{
  if(NbIso == 1)
    return (ValMax + ValMin) / 2.;
  return ValMin + Iso * (ValMax - ValMin) / (NbIso - 1.);
}

double GiveValueFromIndex_Log(double ValMin, double ValMax, int NbIso, int Iso)
{
  if(NbIso == 1)
    return (ValMax + ValMin) / 2.;
  if(ValMin <= 0.)
    return 0.;
  return pow(10., log10(ValMin)
	     + Iso * (log10(ValMax) - log10(ValMin)) / (NbIso - 1.));
}

double GiveValueFromIndex_DoubleLog(double ValMin, double ValMax, int NbIso,
                                    int Iso)
{
  if(NbIso == 1)
    return (ValMax + ValMin) / 2.;
  if(ValMin <= 0.)
    return 0.;

  double Iso2 = Iso / 2.;
  double NbIso2 = NbIso / 2.;

  return pow(10., log10(ValMin) 
	     + Iso2 * (log10(ValMax) - log10(ValMin)) / (NbIso2 - 1.));
}

// Give Index From Value

int GiveIndexFromValue_Lin(double ValMin, double ValMax, int NbIso,
                           double Val)
{
  if(ValMin == ValMax)
    return NbIso / 2;
  return (int)((Val - ValMin) * (NbIso - 1) / (ValMax - ValMin));
}

int GiveIndexFromValue_Log(double ValMin, double ValMax, int NbIso,
                           double Val)
{
  if(ValMin == ValMax)
    return NbIso / 2;
  if(ValMin <= 0.)
    return 0;
  return (int)((log10(Val) - log10(ValMin)) * (NbIso - 1) / 
	       (log10(ValMax) - log10(ValMin)));
}

int GiveIndexFromValue_DoubleLog(double ValMin, double ValMax, int NbIso,
                                 double Val)
{
  // JF: this is obviously wrong...
  if(ValMin == ValMax)
    return NbIso / 2;
  if(ValMin <= 0.)
    return 0;
  return (int)((log10(Val) - log10(ValMin)) * (NbIso - 1) / 
	       (log10(ValMax) - log10(ValMin)));
}


// Color Palette

unsigned int PaletteContinuous(Post_View * v, double min, double max, double val)
{       /* val in [min,max] */
  int index = v->GIFV(min, max, v->CT.size, val);
  glColor4ubv((GLubyte *) & v->CT.table[index]);
  return v->CT.table[index];
}

unsigned int PaletteContinuousLinear(Post_View * v, double min, double max, double val)
{       /* val in [min,max] */
  int index = GiveIndexFromValue_Lin(min, max, v->CT.size, val);
  glColor4ubv((GLubyte *) & v->CT.table[index]);
  return v->CT.table[index];
}

unsigned int PaletteDiscrete(Post_View * v, int nbi, int i)
{       /* i in [0,nbi-1] */
  int index;

  index = (nbi == 1) ?
    v->CT.size / 2 : (int)(i / (double)(nbi - 1) * (v->CT.size - 1) + 0.5);

  glColor4ubv((GLubyte *) & v->CT.table[index]);
  return v->CT.table[index];
}

// Get values from a compatible external view (i.e., a view that has
// the same number of elements as the {type,refcomp} list in the
// reference view, and the same number of time steps)

int GetValuesFromExternalView(Post_View *v, int type, int refcomp, 
			      int *nbcomp, double **vals, int viewIndex)
{
  Post_View **vv = (Post_View **) List_Pointer_Test(CTX.post.list, viewIndex);  

  if(!vv){
    if(!v->ExternalElementIndex)
      Msg(GERROR, "Nonexistent external view: drawing self instead");
    return 0;
  }

  Post_View *v2 = *vv;
  int nbelm = 0, comp = 0, nbnod = 0, ref;
  List_T *l = NULL;

  switch(type){
  case POST_POINT:
    nbnod = 1;
    ref = (refcomp == 1) ? v->NbSP : ((refcomp == 3) ? v->NbVP : v->NbTP);
    if(ref == v2->NbSP){ nbelm = v2->NbSP; l = v2->SP; comp = 1; }
    else if(ref == v2->NbVP){ nbelm = v2->NbVP; l = v2->VP; comp = 3; }
    else if(ref == v2->NbTP){ nbelm = v2->NbTP; l = v2->TP; comp = 9; }
    break;
  case POST_LINE:
    nbnod = 2;
    ref = (refcomp == 1) ? v->NbSL : ((refcomp == 3) ? v->NbVL : v->NbTL);
    if(ref == v2->NbSL){ nbelm = v2->NbSL; l = v2->SL; comp = 1; } 
    else if(ref == v2->NbVL){ nbelm = v2->NbVL; l = v2->VL; comp = 3; } 
    else if(ref == v2->NbTL){ nbelm = v2->NbTL; l = v2->TL; comp = 9; } 
    break;
  case POST_TRIANGLE:
    nbnod = 3;
    ref = (refcomp == 1) ? v->NbST : ((refcomp == 3) ? v->NbVT : v->NbTT);
    if(ref == v2->NbST){ nbelm = v2->NbST; l = v2->ST; comp = 1;  } 
    else if(ref == v2->NbVT){ nbelm = v2->NbVT; l = v2->VT; comp = 3;  } 
    else if(ref == v2->NbTT){ nbelm = v2->NbTT; l = v2->TT; comp = 9;  } 
    break;
  case POST_QUADRANGLE:
    nbnod = 4;
    ref = (refcomp == 1) ? v->NbSQ : ((refcomp == 3) ? v->NbVQ : v->NbTQ);
    if(ref == v2->NbSQ){ nbelm = v2->NbSQ; l = v2->SQ; comp = 1;  } 
    else if(ref == v2->NbVQ){ nbelm = v2->NbVQ; l = v2->VQ; comp = 3;  } 
    else if(ref == v2->NbTQ){ nbelm = v2->NbTQ; l = v2->TQ; comp = 9;  } 
    break;
  case POST_TETRAHEDRON:
    nbnod = 4;
    ref = (refcomp == 1) ? v->NbSS : ((refcomp == 3) ? v->NbVS : v->NbTS);
    if(ref == v2->NbSS){ nbelm = v2->NbSS; l = v2->SS; comp = 1;  } 
    else if(ref == v2->NbVS){ nbelm = v2->NbVS; l = v2->VS; comp = 3;  } 
    else if(ref == v2->NbTS){ nbelm = v2->NbTS; l = v2->TS; comp = 9;  } 
    break;
  case POST_HEXAHEDRON:
    nbnod = 8;
    ref = (refcomp == 1) ? v->NbSH : ((refcomp == 3) ? v->NbVH : v->NbTH);
    if(ref == v2->NbSH){ nbelm = v2->NbSH; l = v2->SH; comp = 1;  }
    else if(ref == v2->NbVH){ nbelm = v2->NbVH; l = v2->VH; comp = 3;  }
    else if(ref == v2->NbTH){ nbelm = v2->NbTH; l = v2->TH; comp = 9;  }
    break;
  case POST_PRISM:
    nbnod = 6;
    ref = (refcomp == 1) ? v->NbSI : ((refcomp == 3) ? v->NbVI : v->NbTI);
    if(ref == v2->NbSI){ nbelm = v2->NbSI; l = v2->SI; comp = 1;  }
    else if(ref == v2->NbVI){ nbelm = v2->NbVI; l = v2->VI; comp = 3;  }
    else if(ref == v2->NbTI){ nbelm = v2->NbTI; l = v2->TI; comp = 9;  }
    break;
  case POST_PYRAMID:
    nbnod = 5;
    ref = (refcomp == 1) ? v->NbSY : ((refcomp == 3) ? v->NbVY : v->NbTY);
    if(ref == v2->NbSY){ nbelm = v2->NbSY; l = v2->SY; comp = 1;  } 
    else if(ref == v2->NbVY){ nbelm = v2->NbVY; l = v2->VY; comp = 3;  } 
    else if(ref == v2->NbTY){ nbelm = v2->NbTY; l = v2->TY; comp = 9;  } 
    break;
  }

  if(!l || !nbelm || v2->NbTimeStep != v->NbTimeStep ||
     v->ExternalElementIndex < 0 || v->ExternalElementIndex >= nbelm){
    if(!v->ExternalElementIndex)
      Msg(GERROR, "Incompatible external view: drawing self instead");
    return 0;
  }

  int nb = List_Nbr(l) / nbelm;
  *nbcomp = comp;
  *vals = (double *)List_Pointer(l, v->ExternalElementIndex * nb + 
				 3 * nbnod + comp * nbnod * v->TimeStep);
  return 1;
}

// Compute node coordinates taking Offset, Raise and Explode into account

void Get_Coords(Post_View *v, int type, int nbnod, int nbcomp,
                double *x1, double *y1, double *z1, double *vals,
                double *x2, double *y2, double *z2)
{
  int i;
  double xc = 0., yc = 0., zc = 0.;

  if(v->Explode == 1.) {
    for(i = 0; i < nbnod; i++) {
      x2[i] = x1[i] + v->Offset[0];
      y2[i] = y1[i] + v->Offset[1];
      z2[i] = z1[i] + v->Offset[2];
    }
  }
  else {
    for(i = 0; i < nbnod; i++) {
      xc += x1[i];
      yc += y1[i];
      zc += z1[i];
    }
    xc /= (double)nbnod;
    yc /= (double)nbnod;
    zc /= (double)nbnod;
    for(i = 0; i < nbnod; i++) {
      x2[i] = xc + v->Explode * (x1[i] - xc) + v->Offset[0];
      y2[i] = yc + v->Explode * (y1[i] - yc) + v->Offset[1];
      z2[i] = zc + v->Explode * (z1[i] - zc) + v->Offset[2];
    }
  }

  if(v->Raise[0] || v->Raise[1] || v->Raise[2]){
    for(int k = 0; k < nbnod; k++){
      double norm = 0.;
      if(nbcomp == 1)
	norm = vals[k];
      else if(nbcomp == 3)
	norm = sqrt(vals[3*k] * vals[3*k] + 
		    vals[3*k+1] * vals[3*k+1] + 
		    vals[3*k+2] * vals[3*k+2]);
      else if(nbcomp == 9)
	norm = ComputeVonMises(vals + 9*k);
      x2[k] += v->Raise[0] * norm;
      y2[k] += v->Raise[1] * norm;
      z2[k] += v->Raise[2] * norm;
    }
  }

  if(v->UseGenRaise){
    int ext_nbcomp = nbcomp;
    double *ext_vals = vals;
    if(v->ViewIndexForGenRaise >= 0)
      GetValuesFromExternalView(v, type, nbcomp, &ext_nbcomp, &ext_vals, 
				v->ViewIndexForGenRaise);
    ApplyGeneralizedRaise(v, nbnod, ext_nbcomp, ext_vals, x2, y2, z2);
  }
}

// Compare barycenters with viewpoint (eye)

static double storedEye[3] = { 0., 0., 0. };

int changedEye()
{
  double zeye = 100 * CTX.lc, tmp[3];
  tmp[0] = CTX.rot[2] * zeye;
  tmp[1] = CTX.rot[6] * zeye;
  tmp[2] = CTX.rot[10] * zeye;
  if(fabs(tmp[0] - storedEye[0]) > 1.e-3 ||
     fabs(tmp[1] - storedEye[1]) > 1.e-3 ||
     fabs(tmp[2] - storedEye[2]) > 1.e-3) {
    storedEye[0] = tmp[0];
    storedEye[1] = tmp[1];
    storedEye[2] = tmp[2];
    Msg(DEBUG, "New eye = (%g %g %g)", tmp[0], tmp[1], tmp[2]);
    return 1;
  }
  return 0;
}

int compareEye(double *q, double *w, int nbnodes)
{
  double d, dq, dw, cgq[3] = { 0., 0., 0. }, cgw[3] = { 0., 0., 0.};
  for(int i = 0; i < nbnodes; i++) {
    cgq[0] += q[i];
    cgq[1] += q[i + nbnodes];
    cgq[2] += q[i + 2 * nbnodes];
    cgw[0] += w[i];
    cgw[1] += w[i + nbnodes];
    cgw[2] += w[i + 2 * nbnodes];
  }
  prosca(storedEye, cgq, &dq);
  prosca(storedEye, cgw, &dw);
  d = dq - dw;
  if(d > 0)
    return 1;
  if(d < 0)
    return -1;
  return 0;
}

int compareEye3Nodes(const void *a, const void *b)
{
  return compareEye((double *)a, (double *)b, 3);
}

int compareEye4Nodes(const void *a, const void *b)
{
  return compareEye((double *)a, (double *)b, 4);
}

int compareEye5Nodes(const void *a, const void *b)
{
  return compareEye((double *)a, (double *)b, 5);
}

int compareEye6Nodes(const void *a, const void *b)
{
  return compareEye((double *)a, (double *)b, 6);
}

int compareEye8Nodes(const void *a, const void *b)
{
  return compareEye((double *)a, (double *)b, 8);
}

// Draw_Post

void Draw_List(Post_View * v, double ValMin, double ValMax, int type,
	       List_T * list, int nbelm, int nbnod, int nbcomp,
	       void (*draw) (Post_View *, int, double, double, double *, 
			     double *, double *, double *))
{
  int i, nb;
  double X[8], Y[8], Z[8];

  if(nbelm) {
    nb = List_Nbr(list) / nbelm;

    if(v->Light && v->SmoothNormals && v->Changed) {
      Msg(DEBUG, "Preprocessing of normals in View[%d]", v->Index);
      v->ExternalElementIndex = 0;
      for(i = 0; i < List_Nbr(list); i += nb) {
        Get_Coords(v, type, nbnod, nbcomp,
                   (double *)List_Pointer_Fast(list, i),
                   (double *)List_Pointer_Fast(list, i + nbnod),
                   (double *)List_Pointer_Fast(list, i + 2 * nbnod), 
		   (double *)List_Pointer_Fast(list, i + 3 * nbnod +
					       v->TimeStep * nbnod * nbcomp),
		   X, Y, Z);
        draw(v, 1, ValMin, ValMax, X, Y, Z,
             (double *)List_Pointer_Fast(list, i + 3 * nbnod));
	v->ExternalElementIndex++;
      }
    }

    v->ExternalElementIndex = 0;
    for(i = 0; i < List_Nbr(list); i += nb) {
      Get_Coords(v, type, nbnod, nbcomp,
                 (double *)List_Pointer_Fast(list, i),
                 (double *)List_Pointer_Fast(list, i + nbnod),
                 (double *)List_Pointer_Fast(list, i + 2 * nbnod),
		 (double *)List_Pointer_Fast(list, i + 3 * nbnod +
					     v->TimeStep * nbnod * nbcomp),
		 X, Y, Z);
      draw(v, 0, ValMin, ValMax, X, Y, Z,
           (double *)List_Pointer_Fast(list, i + 3 * nbnod));
      v->ExternalElementIndex++;
    }
  }
}

void Draw_Post(void)
{
  int nb;
  double ValMin = 0., ValMax = 0.;
  Post_View *v;

  if(!CTX.post.list)
    return;

  if(CTX.draw_bbox || !CTX.post.draw) {  // draw only the bbox of the visible views
    for(int iView = 0; iView < List_Nbr(CTX.post.list); iView++) {
      v = *(Post_View **) List_Pointer(CTX.post.list, iView);
      if(v->Visible && v->Type == DRAW_POST_3D) {
        glColor4ubv((GLubyte *) & CTX.color.fg);
	glLineWidth(CTX.line_width);
        glBegin(GL_LINE_LOOP);
        glVertex3d(v->BBox[0], v->BBox[2], v->BBox[4]);
        glVertex3d(v->BBox[1], v->BBox[2], v->BBox[4]);
        glVertex3d(v->BBox[1], v->BBox[3], v->BBox[4]);
        glVertex3d(v->BBox[0], v->BBox[3], v->BBox[4]);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex3d(v->BBox[0], v->BBox[2], v->BBox[5]);
        glVertex3d(v->BBox[1], v->BBox[2], v->BBox[5]);
        glVertex3d(v->BBox[1], v->BBox[3], v->BBox[5]);
        glVertex3d(v->BBox[0], v->BBox[3], v->BBox[5]);
        glEnd();
        glBegin(GL_LINES);
        glVertex3d(v->BBox[0], v->BBox[2], v->BBox[4]);
        glVertex3d(v->BBox[0], v->BBox[2], v->BBox[5]);
        glVertex3d(v->BBox[1], v->BBox[2], v->BBox[4]);
        glVertex3d(v->BBox[1], v->BBox[2], v->BBox[5]);
        glVertex3d(v->BBox[1], v->BBox[3], v->BBox[4]);
        glVertex3d(v->BBox[1], v->BBox[3], v->BBox[5]);
        glVertex3d(v->BBox[0], v->BBox[3], v->BBox[4]);
        glVertex3d(v->BBox[0], v->BBox[3], v->BBox[5]);
        glEnd();
	char label[256];
	double offset = 0.5 * CTX.gl_fontsize * CTX.pixel_equiv_x;
	glRasterPos3d(v->BBox[0] + offset / CTX.s[0], 
		      v->BBox[2] + offset / CTX.s[0], 
		      v->BBox[4] + offset / CTX.s[0]);
	sprintf(label, "(%g,%g,%g)", v->BBox[0], v->BBox[2], v->BBox[4]);
	Draw_String(label);
	glRasterPos3d(v->BBox[1] + offset / CTX.s[0], 
		      v->BBox[3] + offset / CTX.s[0], 
		      v->BBox[5] + offset / CTX.s[0]);
	sprintf(label, "(%g,%g,%g)", v->BBox[1], v->BBox[3], v->BBox[5]);
	Draw_String(label);

	for(int i = 0; i < 6; i++)
	  if(CTX.clip[i] & (1<<(2+iView)))
	    Draw_PlaneInBoundingBox(v->BBox[0], v->BBox[2], v->BBox[4],
				    v->BBox[1], v->BBox[3], v->BBox[5],
				    CTX.clip_plane[i][0], CTX.clip_plane[i][1], 
				    CTX.clip_plane[i][2], CTX.clip_plane[i][3]);
      }
    }
  }

  if(!CTX.post.draw)
    return;

  for(int iView = 0; iView < List_Nbr(CTX.post.list); iView++) {

    v = *(Post_View **) List_Pointer(CTX.post.list, iView);

    if(v->Visible && !v->Dirty) {

      glPointSize(v->PointSize);
      gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);
      
      glLineWidth(v->LineWidth);
      gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

      if(v->LightTwoSide)
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
      else
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

      for(int i = 0; i < 6; i++)
	if(CTX.clip[i] & (1<<(2+iView))) 
	  glEnable((GLenum)(GL_CLIP_PLANE0 + i));
	else
	  glDisable((GLenum)(GL_CLIP_PLANE0 + i));
      
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
      v->ExternalMin = ValMin;
      v->ExternalMax = ValMax;
      
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

      if(v->Light && v->SmoothNormals && v->Changed)
	v->reset_normals();

      if(v->UseGenRaise)
	InitGeneralizedRaise(v);

      // initialize alpha blending for transparency
      if(CTX.alpha && ColorTable_IsAlpha(&v->CT)){
	if(v->FakeTransparency){
	  // simple additive blending "a la xpost":
	  glBlendFunc(GL_SRC_ALPHA, GL_ONE); // glBlendEquation(GL_FUNC_ADD);
	  // maximum intensity projection "a la volsuite":
	  // glBlendFunc(GL_ONE, GL_ONE); // glBlendEquation(GL_MAX);
	  glEnable(GL_BLEND);
	  glDisable(GL_DEPTH_TEST);
	}
	else{
	  // real translucent blending (requires back-to-front traversal)
	  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // glBlendEquation(GL_FUNC_ADD);
	  glEnable(GL_BLEND);
	  // if we don't use vertex arrays, do the sorting here - it's
	  // incorrect for hybrid views (use Plugin(DecomposeInSimplex)
	  // for that)
	  if(!CTX.post.vertex_arrays && v->DrawScalars && 
	     (changedEye() || v->Changed)) {
	    Msg(DEBUG, "Sorting View[%d] for transparency (NO vertex array)", v->Index);
	    if(v->NbST && v->DrawTriangles) {
	      nb = List_Nbr(v->ST) / v->NbST;
	      qsort(v->ST->array, v->NbST, nb * sizeof(double), compareEye3Nodes);
	    }
	    if(v->NbSQ && v->DrawQuadrangles) {
	      nb = List_Nbr(v->SQ) / v->NbSQ;
	      qsort(v->SQ->array, v->NbSQ, nb * sizeof(double), compareEye4Nodes);
	    }
	    if(v->NbSS && v->DrawTetrahedra) {
	      nb = List_Nbr(v->SS) / v->NbSS;
	      qsort(v->SS->array, v->NbSS, nb * sizeof(double), compareEye4Nodes);
	    }
	    if(v->NbSH && v->DrawHexahedra) {
	      nb = List_Nbr(v->SH) / v->NbSH;
	      qsort(v->SH->array, v->NbSH, nb * sizeof(double), compareEye8Nodes);
	    }
	    if(v->NbSI && v->DrawPrisms) {
	      nb = List_Nbr(v->SI) / v->NbSI;
	      qsort(v->SI->array, v->NbSI, nb * sizeof(double), compareEye6Nodes);
	    }
	    if(v->NbSY && v->DrawPyramids) {
	      nb = List_Nbr(v->SY) / v->NbSY;
	      qsort(v->SY->array, v->NbSY, nb * sizeof(double), compareEye5Nodes);
	    }
	  }
	}
      }

      if(v->DrawPoints) {
	if(v->Type == DRAW_POST_3D && v->DrawScalars)
	  Draw_List(v, ValMin, ValMax, POST_POINT, v->SP, v->NbSP, 1, 1, 
		    Draw_ScalarPoint);
	if(v->DrawVectors)
	  Draw_List(v, ValMin, ValMax, POST_POINT, v->VP, v->NbVP, 1, 3, 
		    Draw_VectorPoint);
	if(v->DrawTensors)
	  Draw_List(v, ValMin, ValMax, POST_POINT, v->TP, v->NbTP, 1, 9, 
		    Draw_TensorPoint);
      }
      if(v->DrawLines) {
	if(v->DrawScalars)
	  Draw_List(v, ValMin, ValMax, POST_LINE, v->SL, v->NbSL, 2, 1,
		    Draw_ScalarLine);
	if(v->DrawVectors)
	  Draw_List(v, ValMin, ValMax, POST_LINE, v->VL, v->NbVL, 2, 3, 
		    Draw_VectorLine);
	if(v->DrawTensors)
	  Draw_List(v, ValMin, ValMax, POST_LINE, v->TL, v->NbTL, 2, 9, 
		    Draw_TensorLine);
      }

      for(int pass = 0; pass < 2; pass++){
	int skip_2d = 0, skip_3d = 0;
	if(pass == 0){
	  if(CTX.post.vertex_arrays){
	    if(v->Changed){
	      Msg(DEBUG, "regenerate View[%d] vertex array", v->Index);
	      if(v->TriVertexArray) delete v->TriVertexArray;
	      v->TriVertexArray = new VertexArray(3, 10000);
	      v->TriVertexArray->fill = 1;
	      goto pass_0;
	    }
	  }
	  goto pass_1;
	}
	else{
	  // don't even enter the classic data path if we don't have to
	  if(v->TriVertexArray){
	    if(v->Boundary < 1 && !v->ShowElement && !v->Normals &&
	       v->IntervalsType != DRAW_POST_NUMERIC && v->IntervalsType != DRAW_POST_ISO){
	      Msg(DEBUG, "View[%d]: skiping 2D scalar pass alltogether", v->Index);
	      skip_2d = 1;
	    }
	    if(v->Boundary < 2 && !v->ShowElement &&
	       v->IntervalsType != DRAW_POST_NUMERIC && v->IntervalsType != DRAW_POST_ISO){
	      Msg(DEBUG, "View[%d]: skiping 3D scalar pass alltogether", v->Index);
	      skip_3d = 1;
	    }
	  }
	}

      pass_0:
	if(v->DrawTriangles) {
	  if(!skip_2d && v->DrawScalars)
	    Draw_List(v, ValMin, ValMax, POST_TRIANGLE, v->ST, v->NbST, 3, 1,
		      Draw_ScalarTriangle);
	  if(v->DrawVectors)
	    Draw_List(v, ValMin, ValMax, POST_TRIANGLE, v->VT, v->NbVT, 3, 3,
		      Draw_VectorTriangle);
	  if(v->DrawTensors)
	    Draw_List(v, ValMin, ValMax, POST_TRIANGLE, v->TT, v->NbTT, 3, 9,
		      Draw_TensorTriangle);
	}
	if(v->DrawQuadrangles) {
	  if(!skip_2d && v->DrawScalars)
	    Draw_List(v, ValMin, ValMax, POST_QUADRANGLE, v->SQ, v->NbSQ, 4, 1,
		      Draw_ScalarQuadrangle);
	  if(v->DrawVectors)
	    Draw_List(v, ValMin, ValMax, POST_QUADRANGLE, v->VQ, v->NbVQ, 4, 3,
		      Draw_VectorQuadrangle);
	  if(v->DrawTensors)
	    Draw_List(v, ValMin, ValMax, POST_QUADRANGLE, v->TQ, v->NbTQ, 4, 9,
		      Draw_TensorQuadrangle);
	}
	if(v->DrawTetrahedra) {
	  if(!skip_3d && v->DrawScalars)
	    Draw_List(v, ValMin, ValMax, POST_TETRAHEDRON, v->SS, v->NbSS, 4, 1,
		      Draw_ScalarTetrahedron);
	  if(v->DrawVectors)
	    Draw_List(v, ValMin, ValMax, POST_TETRAHEDRON, v->VS, v->NbVS, 4, 3,
		      Draw_VectorTetrahedron);
	  if(v->DrawTensors)
	    Draw_List(v, ValMin, ValMax, POST_TETRAHEDRON, v->TS, v->NbTS, 4, 9,
		      Draw_TensorTetrahedron);
	}
	if(v->DrawHexahedra) {
	  if(!skip_3d && v->DrawScalars)
	    Draw_List(v, ValMin, ValMax, POST_HEXAHEDRON, v->SH, v->NbSH, 8, 1,
		      Draw_ScalarHexahedron);
	  if(v->DrawVectors)
	    Draw_List(v, ValMin, ValMax, POST_HEXAHEDRON, v->VH, v->NbVH, 8, 3,
		      Draw_VectorHexahedron);
	  if(v->DrawTensors)
	    Draw_List(v, ValMin, ValMax, POST_HEXAHEDRON, v->TH, v->NbTH, 8, 9,
		      Draw_TensorHexahedron);
	}
	if(v->DrawPrisms) {
	  if(!skip_3d && v->DrawScalars)
	    Draw_List(v, ValMin, ValMax, POST_PRISM, v->SI, v->NbSI, 6, 1,
		      Draw_ScalarPrism);
	  if(v->DrawVectors)
	    Draw_List(v, ValMin, ValMax, POST_PRISM, v->VI, v->NbVI, 6, 3,
		      Draw_VectorPrism);
	  if(v->DrawTensors)
	    Draw_List(v, ValMin, ValMax, POST_PRISM, v->TI, v->NbTI, 6, 9,
		      Draw_TensorPrism);
	}
	if(v->DrawPyramids) {
	  if(!skip_3d && v->DrawScalars)
	    Draw_List(v, ValMin, ValMax, POST_PYRAMID, v->SY, v->NbSY, 5, 1,
		      Draw_ScalarPyramid);
	  if(v->DrawVectors)
	    Draw_List(v, ValMin, ValMax, POST_PYRAMID, v->VY, v->NbVY, 5, 3,
		      Draw_VectorPyramid);
	  if(v->DrawTensors)
	    Draw_List(v, ValMin, ValMax, POST_PYRAMID, v->TY, v->NbTY, 5, 9,
		      Draw_TensorPyramid);
	}

      pass_1:
	if(v->TriVertexArray && v->TriVertexArray->fill){
	  Msg(DEBUG, "View[%d]; %d tris in vertex array", v->Index, v->TriVertexArray->num);
	  v->TriVertexArray->fill = 0;
	}
      }

      if(v->TriVertexArray && v->TriVertexArray->num){

	if(CTX.alpha && ColorTable_IsAlpha(&v->CT) && !v->FakeTransparency &&
	   (changedEye() || v->Changed)){
	  Msg(DEBUG, "Sorting View[%d] for transparency (WITH vertex array)", v->Index);
	  v->TriVertexArray->sort(storedEye);
	}

	glVertexPointer(3, GL_FLOAT, 0, v->TriVertexArray->vertices->array);
	glNormalPointer(GL_FLOAT, 0, v->TriVertexArray->normals->array);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, v->TriVertexArray->colors->array);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	if(v->Light)
	  glEnable(GL_LIGHTING);
	else
	  glDisableClientState(GL_NORMAL_ARRAY);
	if(CTX.polygon_offset_factor || CTX.polygon_offset_units)
	  glEnable(GL_POLYGON_OFFSET_FILL);
	glDrawArrays(GL_TRIANGLES, 0, 3 * v->TriVertexArray->num);
	glDisable(GL_POLYGON_OFFSET_FILL);
	glDisable(GL_LIGHTING);
      
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
      }

      if(v->DrawStrings) {
	glColor4ubv((GLubyte *) & v->color.text3d);
	Draw_Text2D3D(3, v->TimeStep, v->NbT3, v->T3D, v->T3C);
      }

      // reset alpha blending
      if(CTX.alpha){
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
      }

      for(int i = 0; i < 6; i++)
	glDisable((GLenum)(GL_CLIP_PLANE0 + i));

      v->Changed = 0;
    }
  }
}
