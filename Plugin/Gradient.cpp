// $Id: Gradient.cpp,v 1.11 2008-02-17 08:48:06 geuzaine Exp $
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

#include "Gradient.h"
#include "ShapeFunctions.h"

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

PView *GMSH_GradientPlugin::execute(PView *v)
{
  int iView = (int)GradientOptions_Number[0].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView(true);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  int nts = data1->getNumTimeSteps();
  gradient(data1->NbSL, data1->SL, &data2->NbVL, data2->VL, 1, 2, 1, nts);
  gradient(data1->NbST, data1->ST, &data2->NbVT, data2->VT, 2, 3, 1, nts);
  gradient(data1->NbSQ, data1->SQ, &data2->NbVQ, data2->VQ, 2, 4, 1, nts);
  gradient(data1->NbSS, data1->SS, &data2->NbVS, data2->VS, 3, 4, 1, nts);
  gradient(data1->NbSH, data1->SH, &data2->NbVH, data2->VH, 3, 8, 1, nts);
  gradient(data1->NbSI, data1->SI, &data2->NbVI, data2->VI, 3, 6, 1, nts);
  gradient(data1->NbSY, data1->SY, &data2->NbVY, data2->VY, 3, 5, 1, nts);

  gradient(data1->NbVL, data1->VL, &data2->NbTL, data2->TL, 1, 2, 3, nts);
  gradient(data1->NbVT, data1->VT, &data2->NbTT, data2->TT, 2, 3, 3, nts);
  gradient(data1->NbVQ, data1->VQ, &data2->NbTQ, data2->TQ, 2, 4, 3, nts);
  gradient(data1->NbVS, data1->VS, &data2->NbTS, data2->TS, 3, 4, 3, nts);
  gradient(data1->NbVH, data1->VH, &data2->NbTH, data2->TH, 3, 8, 3, nts);
  gradient(data1->NbVI, data1->VI, &data2->NbTI, data2->TI, 3, 6, 3, nts);
  gradient(data1->NbVY, data1->VY, &data2->NbTY, data2->TY, 3, 5, 3, nts);

  for(int i = 0; i < List_Nbr(data1->Time); i++)
    List_Add(data2->Time, List_Pointer(data1->Time, i));
  data2->setName(data1->getName() + "_Gradient");
  data2->setFileName(data1->getName() + "_Gradient.pos");
  data2->finalize();
  
  return v2;
}
