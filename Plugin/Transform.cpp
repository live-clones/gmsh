// $Id: Transform.cpp,v 1.38 2008-03-20 11:44:14 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include "Transform.h"

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
  {GMSH_FULLRC, "Ty", NULL, 0.}, // cannot use T2 (reserved token in parser)
  {GMSH_FULLRC, "Tz", NULL, 0.}, // cannot use T3 (reserved token in parser)
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

static void transform_list(PViewDataList *data, List_T *list, int nbList, 
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
#if 1
      transform(mat, v, &x[j], &y[j], &z[j]);
#else
      // for saku
      double alpha = mat[0][0];
      double d = sqrt(v[0] * v[0] + v[1] * v[1]);
      x[j] = cos(2 * M_PI / alpha * atan2(v[1], v[0])) * alpha / (2 * M_PI) * d;
      y[j] = sin(2 * M_PI / alpha * atan2(v[1], v[0])) * alpha / (2 * M_PI) * d;
      z[j] = cos(asin(alpha / (2 * M_PI))) * d;
#endif
    }
    if(copy){
      for(int j = 0; j < nb; j++)
        copy[j] = x[j];
      for(int j = 0; j < nbVert; j++){
        x[j] = copy[nbVert - j - 1];
        x[nbVert + j] = copy[2 * nbVert - j - 1];
        x[2 * nbVert + j] = copy[3 * nbVert - j - 1];
      }
      for(int ts = 0; ts < data->getNumTimeSteps(); ts++){
        for(int j = 0; j < nbVert; j++){
          for(int k = 0; k < nbComp; k++){
            x[3 * nbVert + nbComp * nbVert * ts + nbComp * j + k] = 
              copy[3 * nbVert + nbComp * nbVert * ts + nbComp * (nbVert - j - 1) + k];
          }
        }
      }
    }
  }

  if(copy) delete [] copy;
}

PView *GMSH_TransformPlugin::execute(PView *v)
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

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  transform_list(data1, data1->SP, data1->NbSP, 1, 1, mat, swap);
  transform_list(data1, data1->SL, data1->NbSL, 2, 1, mat, swap);
  transform_list(data1, data1->ST, data1->NbST, 3, 1, mat, swap);
  transform_list(data1, data1->SQ, data1->NbSQ, 4, 1, mat, swap);
  transform_list(data1, data1->SS, data1->NbSS, 4, 1, mat, swap);
  transform_list(data1, data1->SH, data1->NbSH, 8, 1, mat, swap);
  transform_list(data1, data1->SI, data1->NbSI, 6, 1, mat, swap);
  transform_list(data1, data1->SY, data1->NbSY, 5, 1, mat, swap);

  transform_list(data1, data1->VP, data1->NbVP, 1, 3, mat, swap);
  transform_list(data1, data1->VL, data1->NbVL, 2, 3, mat, swap);
  transform_list(data1, data1->VT, data1->NbVT, 3, 3, mat, swap);
  transform_list(data1, data1->VQ, data1->NbVQ, 4, 3, mat, swap);
  transform_list(data1, data1->VS, data1->NbVS, 4, 3, mat, swap);
  transform_list(data1, data1->VH, data1->NbVH, 8, 3, mat, swap);
  transform_list(data1, data1->VI, data1->NbVI, 6, 3, mat, swap);
  transform_list(data1, data1->VY, data1->NbVY, 5, 3, mat, swap);

  transform_list(data1, data1->TP, data1->NbTP, 1, 9, mat, swap);
  transform_list(data1, data1->TL, data1->NbTL, 2, 9, mat, swap);
  transform_list(data1, data1->TT, data1->NbTT, 3, 9, mat, swap);
  transform_list(data1, data1->TQ, data1->NbTQ, 4, 9, mat, swap);
  transform_list(data1, data1->TS, data1->NbTS, 4, 9, mat, swap);
  transform_list(data1, data1->TH, data1->NbTH, 8, 9, mat, swap);
  transform_list(data1, data1->TI, data1->NbTI, 6, 9, mat, swap);
  transform_list(data1, data1->TY, data1->NbTY, 5, 9, mat, swap);

  data1->finalize();

  v1->setChanged(true);
  return v1;
}
