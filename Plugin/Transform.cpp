// $Id: Transform.cpp,v 1.34 2007-05-04 10:45:09 geuzaine Exp $
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

#include "Plugin.h"
#include "Transform.h"
#include "List.h"
#include "Views.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber TransformOptions_Number[] = {
  {GMSH_FULLRC, "A11", NULL, 1.},
  {GMSH_FULLRC, "A12", NULL, 0.},
  {GMSH_FULLRC, "A13", NULL, 0.},
  {GMSH_FULLRC, "A21", NULL, 0.},
  {GMSH_FULLRC, "A22", NULL, 1.},
  {GMSH_FULLRC, "A23", NULL, 0.},
  {GMSH_FULLRC, "A31", NULL, 0.},
  {GMSH_FULLRC, "A32", NULL, 0.},
  {GMSH_FULLRC, "A33", NULL, 1.},
  {GMSH_FULLRC, "Tx", NULL, 0.}, 
  {GMSH_FULLRC, "Ty", NULL, 0.}, // cannot use T2 (reserve token in parser)
  {GMSH_FULLRC, "Tz", NULL, 0.}, // cannot use T3 (reserve token in parser)
  {GMSH_FULLRC, "SwapOrientation", NULL, 0.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformPlugin()
  {
    return new GMSH_TransformPlugin();
  }
}


GMSH_TransformPlugin::GMSH_TransformPlugin()
{
  ;
}

void GMSH_TransformPlugin::getName(char *name) const
{
  strcpy(name, "Transform");
}

void GMSH_TransformPlugin::getInfos(char *author, char *copyright,
                                    char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Transform) transforms the homogeneous\n"
	 "node coordinates (x,y,z,1) of the elements in\n"
	 "the view `iView' by the matrix\n"
         "[`A11' `A12' `A13' `Tx']\n"
	 "[`A21' `A22' `A23' `Ty']\n"
	 "[`A31' `A32' `A33' `Tz'].\n"
	 "If `SwapOrientation' is set, the orientation of the\n"
	 "elements is reversed. If `iView' < 0, the plugin\n"
	 "is run on the current view.\n"
	 "\n"
	 "Plugin(Transform) is executed in-place.\n");
}

int GMSH_TransformPlugin::getNbOptions() const
{
  return sizeof(TransformOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TransformPlugin::getOption(int iopt)
{
  return &TransformOptions_Number[iopt];
}

void GMSH_TransformPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Transform failed...");
}

// Transformation

static void transform(double mat[3][4], double v[3],
                      double *x, double *y, double *z)
{
  *x = mat[0][0] * v[0] + mat[0][1] * v[1] + mat[0][2] * v[2] + mat[0][3];
  *y = mat[1][0] * v[0] + mat[1][1] * v[1] + mat[1][2] * v[2] + mat[1][3];
  *z = mat[2][0] * v[0] + mat[2][1] * v[1] + mat[2][2] * v[2] + mat[2][3];
}

static void transform_list(Post_View *view, List_T *list, int nbList, 
			   int nbVert, int nbComp, double mat[3][4], int swap)
{
  if(!nbList) return;

  int nb = List_Nbr(list) / nbList;
  double *copy = NULL;
  if(swap) copy = new double[nb];

  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbVert);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbVert);
    for(int j = 0; j < nbVert; j++) {
      double v[3] = { x[j], y[j], z[j] };
      transform(mat, v, &x[j], &y[j], &z[j]);
      if(x[j] < view->BBox[0]) view->BBox[0] = x[j];
      if(x[j] > view->BBox[1]) view->BBox[1] = x[j];
      if(y[j] < view->BBox[2]) view->BBox[2] = y[j];
      if(y[j] > view->BBox[3]) view->BBox[3] = y[j];
      if(z[j] < view->BBox[4]) view->BBox[4] = z[j];
      if(z[j] > view->BBox[5]) view->BBox[5] = z[j];
    }
    if(copy){
      for(int j = 0; j < nb; j++)
	copy[j] = x[j];
      for(int j = 0; j < nbVert; j++){
	x[j] = copy[nbVert-j-1];
	x[nbVert+j] = copy[2*nbVert-j-1];
	x[2*nbVert+j] = copy[3*nbVert-j-1];
      }
      for(int ts = 0; ts < view->NbTimeStep; ts++){
	for(int j = 0; j < nbVert; j++){
	  for(int k = 0; k < nbComp; k++){
	    x[3*nbVert+nbComp*nbVert*ts+nbComp*j+k] = 
	      copy[3*nbVert+nbComp*nbVert*ts+nbComp*(nbVert-j-1)+k];
	  }
	}
      }
    }
  }

  if(copy) delete [] copy;
}

Post_View *GMSH_TransformPlugin::execute(Post_View * v)
{
  double mat[3][4];

  mat[0][0] = TransformOptions_Number[0].def;
  mat[0][1] = TransformOptions_Number[1].def;
  mat[0][2] = TransformOptions_Number[2].def;
  mat[1][0] = TransformOptions_Number[3].def;
  mat[1][1] = TransformOptions_Number[4].def;
  mat[1][2] = TransformOptions_Number[5].def;
  mat[2][0] = TransformOptions_Number[6].def;
  mat[2][1] = TransformOptions_Number[7].def;
  mat[2][2] = TransformOptions_Number[8].def;

  mat[0][3] = TransformOptions_Number[9].def;
  mat[1][3] = TransformOptions_Number[10].def;
  mat[2][3] = TransformOptions_Number[11].def;

  int swap = (int)TransformOptions_Number[12].def;
  int iView = (int)TransformOptions_Number[13].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  for(int i = 0; i < 3; i++) {
    v1->BBox[2 * i] = VAL_INF;
    v1->BBox[2 * i + 1] = -VAL_INF;
  }

  transform_list(v1, v1->SP, v1->NbSP, 1, 1, mat, swap);
  transform_list(v1, v1->SL, v1->NbSL, 2, 1, mat, swap);
  transform_list(v1, v1->ST, v1->NbST, 3, 1, mat, swap);
  transform_list(v1, v1->SQ, v1->NbSQ, 4, 1, mat, swap);
  transform_list(v1, v1->SS, v1->NbSS, 4, 1, mat, swap);
  transform_list(v1, v1->SH, v1->NbSH, 8, 1, mat, swap);
  transform_list(v1, v1->SI, v1->NbSI, 6, 1, mat, swap);
  transform_list(v1, v1->SY, v1->NbSY, 5, 1, mat, swap);

  transform_list(v1, v1->VP, v1->NbVP, 1, 3, mat, swap);
  transform_list(v1, v1->VL, v1->NbVL, 2, 3, mat, swap);
  transform_list(v1, v1->VT, v1->NbVT, 3, 3, mat, swap);
  transform_list(v1, v1->VQ, v1->NbVQ, 4, 3, mat, swap);
  transform_list(v1, v1->VS, v1->NbVS, 4, 3, mat, swap);
  transform_list(v1, v1->VH, v1->NbVH, 8, 3, mat, swap);
  transform_list(v1, v1->VI, v1->NbVI, 6, 3, mat, swap);
  transform_list(v1, v1->VY, v1->NbVY, 5, 3, mat, swap);

  transform_list(v1, v1->TP, v1->NbTP, 1, 9, mat, swap);
  transform_list(v1, v1->TL, v1->NbTL, 2, 9, mat, swap);
  transform_list(v1, v1->TT, v1->NbTT, 3, 9, mat, swap);
  transform_list(v1, v1->TQ, v1->NbTQ, 4, 9, mat, swap);
  transform_list(v1, v1->TS, v1->NbTS, 4, 9, mat, swap);
  transform_list(v1, v1->TH, v1->NbTH, 8, 9, mat, swap);
  transform_list(v1, v1->TI, v1->NbTI, 6, 9, mat, swap);
  transform_list(v1, v1->TY, v1->NbTY, 5, 9, mat, swap);

  v1->Changed = 1;

  return v1;
}
