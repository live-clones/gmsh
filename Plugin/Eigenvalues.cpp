// $Id: Eigenvalues.cpp,v 1.1 2005-01-09 02:18:59 geuzaine Exp $
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

#include "Plugin.h"
#include "Eigenvalues.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber EigenvaluesOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvaluesPlugin()
  {
    return new GMSH_EigenvaluesPlugin();
  }
}

GMSH_EigenvaluesPlugin::GMSH_EigenvaluesPlugin()
{
  ;
}

void GMSH_EigenvaluesPlugin::getName(char *name) const
{
  strcpy(name, "Eigenvalues");
}

void GMSH_EigenvaluesPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Eigenvalues) computes the three real\n"
	 "eigenvalues of each tensor in the view `iView'.\n"
	 "If `iView' < 0, the plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Eigenvalues) creates three new scalar views.\n");
}

int GMSH_EigenvaluesPlugin::getNbOptions() const
{
  return sizeof(EigenvaluesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvaluesPlugin::getOption(int iopt)
{
  return &EigenvaluesOptions_Number[iopt];
}

void GMSH_EigenvaluesPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Eigenvalues failed...");
}

static void eigenvalues(List_T *inList, int inNb, 
			int nbNod, int nbTime,
			List_T *minList, int *minNb, 
			List_T *midList, int *midNb, 
			List_T *maxList, int *maxNb)
{
  if(!inNb) return;

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++){
      List_Add(minList, List_Pointer_Fast(inList, i + j));
      List_Add(midList, List_Pointer_Fast(inList, i + j));
      List_Add(maxList, List_Pointer_Fast(inList, i + j));
    }
    for(int j = 0; j < nbTime; j++){
      for(int k = 0; k < nbNod; k++){
	double *v = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
						nbNod * 9 * j + 9 * k);
	double w[3], A[3][3] = { {v[0], v[1], v[2]},
				 {v[3], v[4], v[5]},
				 {v[6], v[7], v[8]} };
	eigenvalue(A, w);
	for(int l = 0; l < 3; l++){
	  List_Add(minList, &w[2]);
	  List_Add(midList, &w[1]);
	  List_Add(maxList, &w[0]);
	}
      }
    }
    (*minNb)++;
    (*midNb)++;
    (*maxNb)++;
  }
}

Post_View *GMSH_EigenvaluesPlugin::execute(Post_View * v)
{
  int iView = (int)EigenvaluesOptions_Number[0].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *min = BeginView(1);
  Post_View *mid = BeginView(1);
  Post_View *max = BeginView(1);

  eigenvalues(v1->TP, v1->NbTP, 1, v1->NbTimeStep,
	      min->SP, &min->NbSP, mid->SP, &mid->NbSP, max->SP, &max->NbSP);
  eigenvalues(v1->TL, v1->NbTL, 2, v1->NbTimeStep,
	      min->SL, &min->NbSL, mid->SL, &mid->NbSL, max->SL, &max->NbSL);
  eigenvalues(v1->TT, v1->NbTT, 3, v1->NbTimeStep,
	      min->ST, &min->NbST, mid->ST, &mid->NbST, max->ST, &max->NbST);
  eigenvalues(v1->TQ, v1->NbTQ, 4, v1->NbTimeStep,
	      min->SQ, &min->NbSQ, mid->SQ, &mid->NbSQ, max->SQ, &max->NbSQ);
  eigenvalues(v1->TS, v1->NbTS, 4, v1->NbTimeStep,
	      min->SS, &min->NbSS, mid->SS, &mid->NbSS, max->SS, &max->NbSS);
  eigenvalues(v1->TH, v1->NbTH, 8, v1->NbTimeStep,
	      min->SH, &min->NbSH, mid->SH, &mid->NbSH, max->SH, &max->NbSH);
  eigenvalues(v1->TI, v1->NbTI, 6, v1->NbTimeStep,
	      min->SI, &min->NbSI, mid->SI, &mid->NbSI, max->SI, &max->NbSI);
  eigenvalues(v1->TY, v1->NbTY, 5, v1->NbTimeStep,
	      min->SY, &min->NbSY, mid->SY, &mid->NbSY, max->SY, &max->NbSY);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++){
    List_Add(min->Time, List_Pointer(v1->Time, i));
    List_Add(mid->Time, List_Pointer(v1->Time, i));
    List_Add(max->Time, List_Pointer(v1->Time, i));
  }
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_MinEigenvalues", v1->Name);
  sprintf(filename, "%s_MinEigenvalues.pos", v1->Name);
  EndView(min, 1, filename, name);
  sprintf(name, "%s_MidEigenvalue", v1->Name);
  sprintf(filename, "%s_MidEigenvalues.pos", v1->Name);
  EndView(mid, 1, filename, name);
  sprintf(name, "%s_MaxEigenvalue", v1->Name);
  sprintf(filename, "%s_MaxEigenvalues.pos", v1->Name);
  EndView(max, 1, filename, name);

  return NULL;
}
