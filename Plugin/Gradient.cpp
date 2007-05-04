// $Id: Gradient.cpp,v 1.8 2007-05-04 10:45:09 geuzaine Exp $
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
#include "Gradient.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include "ShapeFunctions.h"

extern Context_T CTX;

StringXNumber GradientOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterGradientPlugin()
  {
    return new GMSH_GradientPlugin();
  }
}

GMSH_GradientPlugin::GMSH_GradientPlugin()
{
  ;
}

void GMSH_GradientPlugin::getName(char *name) const
{
  strcpy(name, "Gradient");
}

void GMSH_GradientPlugin::getInfos(char *author, char *copyright,
				    char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
	 "Plugin(Gradient) computes the gradient of the\n"
	 "field in the view `iView'. If `iView' < 0, the\n"
	 "plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Gradient) creates one new view.\n");
}

int GMSH_GradientPlugin::getNbOptions() const
{
  return sizeof(GradientOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_GradientPlugin::getOption(int iopt)
{
  return &GradientOptions_Number[iopt];
}

void GMSH_GradientPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Gradient failed...");
}

static void gradient(int inNb, List_T *inList, int *outNb, List_T *outList, 
		     int dim, int nbNod, int nbComp, int nbTime)
{
  if(!inNb) return;
  
  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    double *x = (double *)List_Pointer_Fast(inList, i);
    double *y = (double *)List_Pointer_Fast(inList, i + nbNod);
    double *z = (double *)List_Pointer_Fast(inList, i + 2 * nbNod);
    elementFactory factory;
    element *element = factory.create(nbNod, dim, x, y, z);
    if(!element) return;
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(outList, &x[j]);
    for(int j = 0; j < nbTime; j++){
      double *val = (double *)List_Pointer(inList, i + 3 * nbNod + nbNod * nbComp * j);
      for(int k = 0; k < nbNod; k++){
	double u, v, w, f[3];
	element->getNode(k, u, v, w);
	for(int l = 0; l < nbComp; l++){
	  element->interpolateGrad(val+l, u, v, w, f, nbComp);
	  List_Add(outList, &f[0]);
	  List_Add(outList, &f[1]);
	  List_Add(outList, &f[2]);
	}
      }
    }
    delete element;
    (*outNb)++;
  }
}

Post_View *GMSH_GradientPlugin::execute(Post_View * v)
{
  int iView = (int)GradientOptions_Number[0].def;
  
  if(iView < 0)
    iView = v ? v->Index : 0;
  
  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }
  
  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *v2 = BeginView(1);
  
  gradient(v1->NbSL, v1->SL, &v2->NbVL, v2->VL, 1, 2, 1, v1->NbTimeStep);
  gradient(v1->NbST, v1->ST, &v2->NbVT, v2->VT, 2, 3, 1, v1->NbTimeStep);
  gradient(v1->NbSQ, v1->SQ, &v2->NbVQ, v2->VQ, 2, 4, 1, v1->NbTimeStep);
  gradient(v1->NbSS, v1->SS, &v2->NbVS, v2->VS, 3, 4, 1, v1->NbTimeStep);
  gradient(v1->NbSH, v1->SH, &v2->NbVH, v2->VH, 3, 8, 1, v1->NbTimeStep);
  gradient(v1->NbSI, v1->SI, &v2->NbVI, v2->VI, 3, 6, 1, v1->NbTimeStep);
  gradient(v1->NbSY, v1->SY, &v2->NbVY, v2->VY, 3, 5, 1, v1->NbTimeStep);

  gradient(v1->NbVL, v1->VL, &v2->NbTL, v2->TL, 1, 2, 3, v1->NbTimeStep);
  gradient(v1->NbVT, v1->VT, &v2->NbTT, v2->TT, 2, 3, 3, v1->NbTimeStep);
  gradient(v1->NbVQ, v1->VQ, &v2->NbTQ, v2->TQ, 2, 4, 3, v1->NbTimeStep);
  gradient(v1->NbVS, v1->VS, &v2->NbTS, v2->TS, 3, 4, 3, v1->NbTimeStep);
  gradient(v1->NbVH, v1->VH, &v2->NbTH, v2->TH, 3, 8, 3, v1->NbTimeStep);
  gradient(v1->NbVI, v1->VI, &v2->NbTI, v2->TI, 3, 6, 3, v1->NbTimeStep);
  gradient(v1->NbVY, v1->VY, &v2->NbTY, v2->TY, 3, 5, 3, v1->NbTimeStep);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_Gradient", v1->Name);
  sprintf(filename, "%s_Gradient.pos", v1->Name);
  EndView(v2, 1, filename, name);
  
  return v2;
}
