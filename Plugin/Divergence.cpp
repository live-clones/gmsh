// $Id: Divergence.cpp,v 1.3 2006-11-27 22:22:32 geuzaine Exp $
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
#include "Divergence.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include "ShapeFunctions.h"

extern Context_T CTX;

StringXNumber DivergenceOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDivergencePlugin()
  {
    return new GMSH_DivergencePlugin();
  }
}

GMSH_DivergencePlugin::GMSH_DivergencePlugin()
{
  ;
}

void GMSH_DivergencePlugin::getName(char *name) const
{
  strcpy(name, "Divergence");
}

void GMSH_DivergencePlugin::getInfos(char *author, char *copyright,
				    char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
	 "Plugin(Divergence) computes the divergence of the\n"
	 "field in the view `iView'. If `iView' < 0, the plugin\n"
	 "is run on the current view.\n"
	 "\n"
	 "Plugin(Divergence) creates one new view.\n");
}

int GMSH_DivergencePlugin::getNbOptions() const
{
  return sizeof(DivergenceOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DivergencePlugin::getOption(int iopt)
{
  return &DivergenceOptions_Number[iopt];
}

void GMSH_DivergencePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Divergence failed...");
}

static void divergence(int inNb, List_T *inList, int *outNb, List_T *outList, 
		     int dim, int nbNod, int nbTime)
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
      double *val = (double *)List_Pointer(inList, i + 3 * nbNod + nbNod * 3 * j);
      for(int k = 0; k < nbNod; k++){
	double u, v, w;
	element->getNode(k, u, v, w);
	double f = element->interpolateDiv(val, u, v, w, 3);
	List_Add(outList, &f);
      }
    }
    delete element;
    (*outNb)++;
  }
}

Post_View *GMSH_DivergencePlugin::execute(Post_View * v)
{
  int iView = (int)DivergenceOptions_Number[0].def;
  
  if(iView < 0)
    iView = v ? v->Index : 0;
  
  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }
  
  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *v2 = BeginView(1);

  divergence(v1->NbVL, v1->VL, &v2->NbSL, v2->SL, 1, 2, v1->NbTimeStep);
  divergence(v1->NbVT, v1->VT, &v2->NbST, v2->ST, 2, 3, v1->NbTimeStep);
  divergence(v1->NbVQ, v1->VQ, &v2->NbSQ, v2->SQ, 2, 4, v1->NbTimeStep);
  divergence(v1->NbVS, v1->VS, &v2->NbSS, v2->SS, 3, 4, v1->NbTimeStep);
  divergence(v1->NbVH, v1->VH, &v2->NbSH, v2->SH, 3, 8, v1->NbTimeStep);
  divergence(v1->NbVI, v1->VI, &v2->NbSI, v2->SI, 3, 6, v1->NbTimeStep);
  divergence(v1->NbVY, v1->VY, &v2->NbSY, v2->SY, 3, 5, v1->NbTimeStep);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_Divergence", v1->Name);
  sprintf(filename, "%s_Divergence.pos", v1->Name);
  EndView(v2, 1, filename, name);
  
  return v2;
}
