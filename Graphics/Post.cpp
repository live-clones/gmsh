// $Id: Post.cpp,v 1.50 2004-01-13 12:39:45 geuzaine Exp $
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
// Please report all bugs and problems to "gmsh@geuz.org".

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

static double Raise[3][8];
static double RaiseFactor[3];

// Give Value from Index

double GiveValueFromIndex_Lin(double ValMin, double ValMax, int NbIso,
                              int Iso)
{
  if(NbIso == 1)
    return (ValMax + ValMin) / 2.;
  return ValMin + Iso * (ValMax - ValMin) / (NbIso - 1.);
}

double GiveValueFromIndex_Log(double ValMin, double ValMax, int NbIso,
                              int Iso)
{
  if(NbIso == 1)
    return (ValMax + ValMin) / 2.;
  if(ValMin <= 0.)
    return 0.;
  return pow(10.,
             log10(ValMin) + Iso * (log10(ValMax) - log10(ValMin)) / (NbIso -
                                                                      1.));
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

  return pow(10.,
             log10(ValMin) + Iso2 * (log10(ValMax) -
                                     log10(ValMin)) / (NbIso2 - 1.));

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
  return (int)((log10(Val) - log10(ValMin)) * (NbIso - 1) / (log10(ValMax) -
                                                             log10(ValMin)));
}

int GiveIndexFromValue_DoubleLog(double ValMin, double ValMax, int NbIso,
                                 double Val)
{
  if(ValMin == ValMax)
    return NbIso / 2;
  if(ValMin <= 0.)
    return 0;
  return (int)((log10(Val) - log10(ValMin)) * (NbIso - 1) / (log10(ValMax) -
                                                             log10(ValMin)));
}


// Color Palette

void Palette1(Post_View * v, int nbi, int i)
{       /* i in [0,nbi-1] */
  int index;

  index = (nbi == 1) ?
    v->CT.size / 2 : (int)(i / (double)(nbi - 1) * (v->CT.size - 1) + 0.5);

  glColor4ubv((GLubyte *) & v->CT.table[index]);
}

void Palette2(Post_View * v, double min, double max, double val)
{       /* val in [min,max] */
  int index;

  index = (min == max) ?
    v->CT.size / 2 :
    (int)((val - min) / (max - min) * (v->CT.size - 1) + 0.5);

  glColor4ubv((GLubyte *) & v->CT.table[index]);
}

void RaiseFill(int i, double Val, double ValMin, double Raise[3][8])
{
  int j;
  for(j = 0; j < 3; j++)
    Raise[j][i] = (Val - ValMin) * RaiseFactor[j];
}


// Compute node coordinates taking Offset and Explode into account

void Get_Coords(double Explode, double *Offset, int nbnod,
                double *x1, double *y1, double *z1,
                double *x2, double *y2, double *z2)
{
  int i;
  double xc = 0., yc = 0., zc = 0.;

  if(Explode == 1) {
    for(i = 0; i < nbnod; i++) {
      x2[i] = x1[i] + Offset[0];
      y2[i] = y1[i] + Offset[1];
      z2[i] = z1[i] + Offset[2];
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
      x2[i] = xc + Explode * (x1[i] - xc) + Offset[0];
      y2[i] = yc + Explode * (y1[i] - yc) + Offset[1];
      z2[i] = zc + Explode * (z1[i] - zc) + Offset[2];
    }
  }
}

// Compare barycenters with viewpoint (eye)

static double storedEye[3] = { 0., 0., 0. };

int changedEye()
{
  double zeye = 100 * CTX.lc, tmp[3];
  tmp[0] = CTX.rot[0][2] * zeye;
  tmp[1] = CTX.rot[1][2] * zeye;
  tmp[2] = CTX.rot[2][2] * zeye;
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

// to be rigorous, we should take Raise into account

int compareEye(double *q, double *w, int nbnodes)
{
  double d, dq, dw, cgq[3] = { 0., 0., 0. }, cgw[3] =
  {
  0., 0., 0.};
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

void Draw_ScalarList(Post_View * v, double ValMin, double ValMax,
                     double Raise[3][8], List_T * list, int nbelm, int nbnod,
                     int smoothnormals, void (*draw) (Post_View *, int,
                                                      double, double,
                                                      double[3][8], double *,
                                                      double *, double *,
                                                      double *))
{
  int i, nb;
  double X[8], Y[8], Z[8];

  if(nbelm && v->DrawScalars) {
    nb = List_Nbr(list) / nbelm;
    if(smoothnormals && v->Light && v->SmoothNormals && v->Changed &&
       v->IntervalsType != DRAW_POST_ISO) {
      v->reset_normals(); 
      // we might save some normal stuff by checking if the change
      // actually changed the "geometry"... Should put e.g. Change=2
      // if timestep changed, etc.
      Msg(DEBUG, "Preprocessing of normals in view %d", v->Num);
      for(i = 0; i < List_Nbr(list); i += nb) {
        Get_Coords(v->Explode, v->Offset, nbnod,
                   (double *)List_Pointer_Fast(list, i),
                   (double *)List_Pointer_Fast(list, i + nbnod),
                   (double *)List_Pointer_Fast(list, i + 2 * nbnod), X, Y, Z);
        draw(v, 1, ValMin, ValMax, Raise, X, Y, Z,
             (double *)List_Pointer_Fast(list, i + 3 * nbnod));
      }
    }
    for(i = 0; i < List_Nbr(list); i += nb) {
      Get_Coords(v->Explode, v->Offset, nbnod,
                 (double *)List_Pointer_Fast(list, i),
                 (double *)List_Pointer_Fast(list, i + nbnod),
                 (double *)List_Pointer_Fast(list, i + 2 * nbnod), X, Y, Z);
      draw(v, 0, ValMin, ValMax, Raise, X, Y, Z,
           (double *)List_Pointer_Fast(list, i + 3 * nbnod));
    }
  }
}

void Draw_VectorList(Post_View * v, double ValMin, double ValMax,
                     double Raise[3][8], List_T * list, int nbelm, int nbnod,
                     void (*draw) (Post_View *, double, double, double[3][8],
                                   double *, double *, double *, double *))
{
  int i, nb;
  double X[8], Y[8], Z[8];

  if(nbelm && v->DrawVectors) {
    nb = List_Nbr(list) / nbelm;
    for(i = 0; i < List_Nbr(list); i += nb) {
      Get_Coords(v->Explode, v->Offset, nbnod,
                 (double *)List_Pointer_Fast(list, i),
                 (double *)List_Pointer_Fast(list, i + nbnod),
                 (double *)List_Pointer_Fast(list, i + 2 * nbnod), X, Y, Z);
      draw(v, ValMin, ValMax, Raise, X, Y, Z,
           (double *)List_Pointer_Fast(list, i + 3 * nbnod));
    }
  }
}

void Draw_TensorList(Post_View * v, double ValMin, double ValMax,
                     double Raise[3][8], List_T * list, int nbelm, int nbnod,
                     void (*draw) (Post_View *, double, double, double[3][8],
                                   double *, double *, double *, double *))
{
  int i, nb;
  double X[8], Y[8], Z[8];

  if(nbelm && v->DrawTensors) {
    nb = List_Nbr(list) / nbelm;
    for(i = 0; i < List_Nbr(list); i += nb) {
      Get_Coords(v->Explode, v->Offset, nbnod,
                 (double *)List_Pointer_Fast(list, i),
                 (double *)List_Pointer_Fast(list, i + nbnod),
                 (double *)List_Pointer_Fast(list, i + 2 * nbnod), X, Y, Z);
      draw(v, ValMin, ValMax, Raise, X, Y, Z,
           (double *)List_Pointer_Fast(list, i + 3 * nbnod));
    }
  }
}

void Draw_Post(void)
{
  int iView, j, k, nb;
  double ValMin = 0., ValMax = 0., AbsMax;
  Post_View *v;

  if(!CTX.post.list)
    return;

  if(!CTX.post.draw) {  // draw only the bbox of the visible views
    for(iView = 0; iView < List_Nbr(CTX.post.list); iView++) {
      v = (Post_View *) List_Pointer(CTX.post.list, iView);
      if(v->Visible && v->Type == DRAW_POST_3D) {
        glColor4ubv((GLubyte *) & CTX.color.fg);
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
      }
    }
    return;
  }

  for(iView = 0; iView < List_Nbr(CTX.post.list); iView++) {

    v = (Post_View *) List_Pointer(CTX.post.list, iView);

    if(v->Visible && !v->Dirty) {

      // Sort the data % eye for transparency. Hybrid views (e.g. tri
      // + qua) or multiple views will be sorted incorrectly... You
      // can use Plugin(DecomposeInSimplex) and/or View->Combine for
      // this.

      if(CTX.alpha && ColorTable_IsAlpha(&v->CT) && 
	 (changedEye() || v->Changed)) {
        Msg(DEBUG, "Sorting view %d", v->Num);

        if(v->DrawScalars) {

          if(v->IntervalsType != DRAW_POST_ISO) {

            if(v->NbST && v->DrawTriangles) {
              nb = List_Nbr(v->ST) / v->NbST;
              qsort(v->ST->array, v->NbST, nb * sizeof(double),
                    compareEye3Nodes);
              v->Changed = 1;
            }
            if(v->NbSQ && v->DrawQuadrangles) {
              nb = List_Nbr(v->SQ) / v->NbSQ;
              qsort(v->SQ->array, v->NbSQ, nb * sizeof(double),
                    compareEye4Nodes);
              v->Changed = 1;
            }

          }

          // The following is of course not rigorous: we should store
          // the triangles generated during the iso computation, and
          // sort these... But this is better than doing nothing. If
          // you want a rigorous sorting of the iso-surfaces, just use
          // Plugin(CutMap).

          if(v->NbSS && v->DrawTetrahedra) {
            nb = List_Nbr(v->SS) / v->NbSS;
            qsort(v->SS->array, v->NbSS, nb * sizeof(double),
                  compareEye4Nodes);
            v->Changed = 1;
          }
          if(v->NbSH && v->DrawHexahedra) {
            nb = List_Nbr(v->SH) / v->NbSH;
            qsort(v->SH->array, v->NbSH, nb * sizeof(double),
                  compareEye8Nodes);
            v->Changed = 1;
          }
          if(v->NbSI && v->DrawPrisms) {
            nb = List_Nbr(v->SI) / v->NbSI;
            qsort(v->SI->array, v->NbSI, nb * sizeof(double),
                  compareEye6Nodes);
            v->Changed = 1;
          }
          if(v->NbSY && v->DrawPyramids) {
            nb = List_Nbr(v->SY) / v->NbSY;
            qsort(v->SY->array, v->NbSY, nb * sizeof(double),
                  compareEye5Nodes);
            v->Changed = 1;
          }

        }

      }

      if(CTX.post.display_lists && !v->Changed && v->DisplayListNum > 0) {

        Msg(DEBUG, "Call display List %d", v->DisplayListNum);
        glCallList(v->DisplayListNum);

      }
      else {

        if(CTX.post.display_lists) {
          if(v->DisplayListNum > 0) {
            Msg(DEBUG, "Delete display List %d", v->DisplayListNum);
            glDeleteLists(v->DisplayListNum, 1);
          }
          else {
            v->DisplayListNum = glGenLists(1);
            Msg(DEBUG, "Gen display list -> %d", v->DisplayListNum);
          }

          if(v->DisplayListNum > 0) {
            Msg(DEBUG, "New display List %d", v->DisplayListNum);
            glNewList(v->DisplayListNum, GL_COMPILE_AND_EXECUTE);
          }
          else
            Msg(GERROR, "Unable to create display list");
        }

        glPointSize(v->PointSize);
        gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

        glLineWidth(v->LineWidth);
        gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

        if(v->Light)
          InitShading();
        else
          InitNoShading();

        if(v->ShowElement)
          glEnable(GL_POLYGON_OFFSET_FILL);

        // force this
        if(v->IntervalsType == DRAW_POST_CONTINUOUS) {
          glShadeModel(GL_SMOOTH);
          glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
        }
        else {  // there is a bug in CutTriangle2D!! See Iso.cpp
          glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
        }

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
          ValMin = v->TimeStepMin[v->TimeStep];
          ValMax = v->TimeStepMax[v->TimeStep];
          break;
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

        AbsMax = DMAX(fabs(ValMin), fabs(ValMax));
        AbsMax = (AbsMax == 0.) ? 1. : AbsMax;

        for(j = 0; j < 3; j++) {
          RaiseFactor[j] = v->Raise[j] / AbsMax;
          for(k = 0; k < 5; k++)
            Raise[j][k] = 0.;
        }

        // Points
        if(v->DrawPoints) {
          if(v->Type == DRAW_POST_3D)
            Draw_ScalarList(v, ValMin, ValMax, Raise, v->SP, v->NbSP, 1, 0,
                            Draw_ScalarPoint);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VP, v->NbVP, 1,
                          Draw_VectorPoint);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TP, v->NbTP, 1,
                          Draw_TensorPoint);
        }

        // Lines
        if(v->DrawLines) {
          Draw_ScalarList(v, ValMin, ValMax, Raise, v->SL, v->NbSL, 2, 0,
                          Draw_ScalarLine);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VL, v->NbVL, 2,
                          Draw_VectorLine);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TL, v->NbTL, 2,
                          Draw_TensorLine);
        }

        // Triangles
        if(v->DrawTriangles) {
          Draw_ScalarList(v, ValMin, ValMax, Raise, v->ST, v->NbST, 3, 1,
                          Draw_ScalarTriangle);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VT, v->NbVT, 3,
                          Draw_VectorTriangle);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TT, v->NbTT, 3,
                          Draw_TensorTriangle);
        }

        // Quadrangles
        if(v->DrawQuadrangles) {
          Draw_ScalarList(v, ValMin, ValMax, Raise, v->SQ, v->NbSQ, 4, 1,
                          Draw_ScalarQuadrangle);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VQ, v->NbVQ, 4,
                          Draw_VectorQuadrangle);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TQ, v->NbTQ, 4,
                          Draw_TensorQuadrangle);
        }

        // Tetrahedra
        if(v->DrawTetrahedra) {
          Draw_ScalarList(v, ValMin, ValMax, Raise, v->SS, v->NbSS, 4, 1,
                          Draw_ScalarTetrahedron);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VS, v->NbVS, 4,
                          Draw_VectorTetrahedron);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TS, v->NbTS, 4,
                          Draw_TensorTetrahedron);
        }

        // Hexahedra
        if(v->DrawHexahedra) {
          Draw_ScalarList(v, ValMin, ValMax, Raise, v->SH, v->NbSH, 8, 1,
                          Draw_ScalarHexahedron);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VH, v->NbVH, 8,
                          Draw_VectorHexahedron);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TH, v->NbTH, 8,
                          Draw_TensorHexahedron);
        }

        // Prisms
        if(v->DrawPrisms) {
          Draw_ScalarList(v, ValMin, ValMax, Raise, v->SI, v->NbSI, 6, 1,
                          Draw_ScalarPrism);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VI, v->NbVI, 6,
                          Draw_VectorPrism);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TI, v->NbTI, 6,
                          Draw_TensorPrism);
        }

        // Pyramids
        if(v->DrawPyramids) {
          Draw_ScalarList(v, ValMin, ValMax, Raise, v->SY, v->NbSY, 5, 1,
                          Draw_ScalarPyramid);
          Draw_VectorList(v, ValMin, ValMax, Raise, v->VY, v->NbVY, 5,
                          Draw_VectorPyramid);
          Draw_TensorList(v, ValMin, ValMax, Raise, v->TY, v->NbTY, 5,
                          Draw_TensorPyramid);
        }

        // Strings
        if(v->DrawStrings) {
          glColor4ubv((GLubyte *) & CTX.color.text);
          Draw_Text2D3D(3, v->TimeStep, v->NbT3, v->T3D, v->T3C);
        }

        if(CTX.post.display_lists)
          glEndList();

        v->Changed = 0;

        if(v->ShowElement || v->VectorType == DRAW_POST_DISPLACEMENT)
          glDisable(GL_POLYGON_OFFSET_FILL);

      }

    }

  }

  // go back to default shading for the scale
  InitNoShading();

}
