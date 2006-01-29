// $Id: ExtractElements.cpp,v 1.4 2006-01-29 23:25:20 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "ExtractElements.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"

extern Context_T CTX;

StringXNumber ExtractElementsOptions_Number[] = {
  {GMSH_FULLRC, "MinVal", NULL, 0.},
  {GMSH_FULLRC, "MaxVal", NULL, 1.},
  {GMSH_FULLRC, "TimeStep", NULL, 0.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractElementsPlugin()
  {
    return new GMSH_ExtractElementsPlugin();
  }
}

GMSH_ExtractElementsPlugin::GMSH_ExtractElementsPlugin()
{
  ;
}

void GMSH_ExtractElementsPlugin::getName(char *name) const
{
  strcpy(name, "Extract Elements");
}

void GMSH_ExtractElementsPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(ExtractElements) extracts the elements\n"
	 "from the view `iView' whose `TimeStep'-th values\n"
	 "(averaged by element) are comprised between\n"
	 "`MinVal' and `MaxVal'. If `iView' < 0, the plugin\n"
	 "is run on the current view.\n"
	 "\n"
	 "Plugin(ExtractElements) creates one new view.\n");
}

int GMSH_ExtractElementsPlugin::getNbOptions() const
{
  return sizeof(ExtractElementsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractElementsPlugin::getOption(int iopt)
{
  return &ExtractElementsOptions_Number[iopt];
}

void GMSH_ExtractElementsPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "ExtractElements failed...");
}

static void extract(List_T *inList, int inNb, 
		    List_T *outList, int *outNb, 
		    int timeStep, int nbNod, int nbComp)
{
  double MinVal = ExtractElementsOptions_Number[0].def;
  double MaxVal = ExtractElementsOptions_Number[1].def;

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    double *vals = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
					       timeStep * nbNod * nbComp);
    double d = 0.;
    for(int k = 0; k < nbNod; k++) {
      double *v = &vals[nbComp * k];
      switch(nbComp) {
      case 1: // scalar
	d += v[0];
	break;
      case 3 : // vector
	d += sqrt(DSQR(v[0]) + DSQR(v[1]) + DSQR(v[2]));
	break;
      case 9 : // tensor
	d += ComputeVonMises(v);
	break;
      }
    }
    d /= (double)nbNod;
    // We use '>=' and '<' so that we can do segmentation without
    // worrying about roudoff errors
    if(d >= MinVal && d < MaxVal){
      for(int j = 0; j < nb; j++)
	List_Add(outList, List_Pointer_Fast(inList, i + j));
      (*outNb)++;
    }
  }
}

Post_View *GMSH_ExtractElementsPlugin::execute(Post_View * v)
{
  int step = (int)ExtractElementsOptions_Number[2].def;
  int iView = (int)ExtractElementsOptions_Number[3].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *v2 = BeginView(1);

  if(step < 0 || step > v1->NbTimeStep-1){
    Msg(GERROR, "Invalid time step (%d) in View[%d]: using first step instead",
	step, v1->Num);
    step = 0;
  }

  // points
  extract(v1->SP, v1->NbSP, v2->SP, &v2->NbSP, step, 1, 1);
  extract(v1->VP, v1->NbVP, v2->SP, &v2->NbSP, step, 1, 3);
  extract(v1->TP, v1->NbTP, v2->SP, &v2->NbSP, step, 1, 9);
  // lines			                	
  extract(v1->SL, v1->NbSL, v2->SL, &v2->NbSL, step, 2, 1);
  extract(v1->VL, v1->NbVL, v2->SL, &v2->NbSL, step, 2, 3);
  extract(v1->TL, v1->NbTL, v2->SL, &v2->NbSL, step, 2, 9);
  // triangles			                	
  extract(v1->ST, v1->NbST, v2->ST, &v2->NbST, step, 3, 1);
  extract(v1->VT, v1->NbVT, v2->ST, &v2->NbST, step, 3, 3);
  extract(v1->TT, v1->NbTT, v2->ST, &v2->NbST, step, 3, 9);
  // quadrangles		                	
  extract(v1->SQ, v1->NbSQ, v2->SQ, &v2->NbSQ, step, 4, 1);
  extract(v1->VQ, v1->NbVQ, v2->SQ, &v2->NbSQ, step, 4, 3);
  extract(v1->TQ, v1->NbTQ, v2->SQ, &v2->NbSQ, step, 4, 9);
  // tets			                	
  extract(v1->SS, v1->NbSS, v2->SS, &v2->NbSS, step, 4, 1);
  extract(v1->VS, v1->NbVS, v2->SS, &v2->NbSS, step, 4, 3);
  extract(v1->TS, v1->NbTS, v2->SS, &v2->NbSS, step, 4, 9);
  // hexas			                	
  extract(v1->SH, v1->NbSH, v2->SH, &v2->NbSH, step, 8, 1);
  extract(v1->VH, v1->NbVH, v2->SH, &v2->NbSH, step, 8, 3);
  extract(v1->TH, v1->NbTH, v2->SH, &v2->NbSH, step, 8, 9);
  // prisms			                	
  extract(v1->SI, v1->NbSI, v2->SI, &v2->NbSI, step, 6, 1);
  extract(v1->VI, v1->NbVI, v2->SI, &v2->NbSI, step, 6, 3);
  extract(v1->TI, v1->NbTI, v2->SI, &v2->NbSI, step, 6, 9);
  // pyramids			                	
  extract(v1->SY, v1->NbSY, v2->SY, &v2->NbSY, step, 5, 1);
  extract(v1->VY, v1->NbVY, v2->SY, &v2->NbSY, step, 5, 3);
  extract(v1->TY, v1->NbTY, v2->SY, &v2->NbSY, step, 5, 9);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));

  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_ExtractElements", v1->Name);
  sprintf(filename, "%s_ExtractElements.pos", v1->Name);
  EndView(v2, 1, filename, name);
  return v2;
}
