// $Id: Eigenvectors.cpp,v 1.3 2004-12-14 20:05:43 geuzaine Exp $
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

#include "Plugin.h"
#include "Eigenvectors.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"
#include "Numeric.h"
#include "EigSolve.h"

extern Context_T CTX;

StringXNumber EigenvectorsOptions_Number[] = {
  {GMSH_FULLRC, "ScaleByEigenvalues", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvectorsPlugin()
  {
    return new GMSH_EigenvectorsPlugin();
  }
}

GMSH_EigenvectorsPlugin::GMSH_EigenvectorsPlugin()
{
  ;
}

void GMSH_EigenvectorsPlugin::getName(char *name) const
{
  strcpy(name, "Eigenvectors");
}

void GMSH_EigenvectorsPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Eigenvectors) computes the three\n"
	 "(right) eigenvectors of each tensor in the\n"
	 "view `iView' and sorts them according to\n"
	 "the value of the associated eigenvalues.\n"
	 "If `ScaleByEigenvalues' is set, each\n"
	 "eigenvector is scaled by its associated\n"
	 "eigenvalue. The plugin gives an error if\n"
	 "the eigenvectors are complex. If `iView'\n"
	 "< 0, the plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Eigenvectors) creates three new\n"
	 "vector views.\n");
}

int GMSH_EigenvectorsPlugin::getNbOptions() const
{
  return sizeof(EigenvectorsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvectorsPlugin::getOption(int iopt)
{
  return &EigenvectorsOptions_Number[iopt];
}

void GMSH_EigenvectorsPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Eigenvectors failed...");
}

static int nonzero(double v[3])
{
  for(int i = 0; i < 3; i++)
    if(fabs(v[i]) > 1.e-16) return 1;
  return 0;
}

static void eigenvectors(List_T *inList, int inNb, 
			 int nbNod, int nbTime, int scale,
			 List_T *minList, int *minNb, 
			 List_T *midList, int *midNb, 
			 List_T *maxList, int *maxNb)
{
  if(!inNb) return;

  int nbcomplex = 0;

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++){
      List_Add(minList, List_Pointer_Fast(inList, i + j));
      List_Add(midList, List_Pointer_Fast(inList, i + j));
      List_Add(maxList, List_Pointer_Fast(inList, i + j));
    }
    for(int j = 0; j < nbTime; j++){
      for(int k = 0; k < nbNod; k++){
	double *val = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
						  nbNod * 9 * j + 9 * k);
	double wr[3], wi[3], B[9];
	if(!EigSolve3x3(val, wr, wi, B))
	  Msg(GERROR, "Eigensolver failed to converge");
	nbcomplex += nonzero(wi); 
	if(!scale)
	  wr[0] = wr[1] = wr[2] = 1.;
	for(int l = 0; l < 3; l++){
	  double res;
	  // wrong if there are complex eigenvals (B contains both
	  // real and imag parts: cf. explanation in EigSolve.cpp)
	  res = wr[0] * B[l]; List_Add(minList, &res);
	  res = wr[1] * B[3+l]; List_Add(midList, &res);
	  res = wr[2] * B[6+l]; List_Add(maxList, &res);
	}
      }
    }
    (*minNb)++;
    (*midNb)++;
    (*maxNb)++;
  }

  if(nbcomplex)
    Msg(GERROR, "%d tensors have complex eigenvalues/eigenvectors", nbcomplex);
}

Post_View *GMSH_EigenvectorsPlugin::execute(Post_View * v)
{
  int scale = (int)EigenvectorsOptions_Number[0].def;
  int iView = (int)EigenvectorsOptions_Number[1].def;

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

  eigenvectors(v1->TP, v1->NbTP, 1, v1->NbTimeStep, scale,
	       min->VP, &min->NbVP, mid->VP, &mid->NbVP, max->VP, &max->NbVP);
  eigenvectors(v1->TL, v1->NbTL, 2, v1->NbTimeStep, scale,
	       min->VL, &min->NbVL, mid->VL, &mid->NbVL, max->VL, &max->NbVL);
  eigenvectors(v1->TT, v1->NbTT, 3, v1->NbTimeStep, scale,
	       min->VT, &min->NbVT, mid->VT, &mid->NbVT, max->VT, &max->NbVT);
  eigenvectors(v1->TQ, v1->NbTQ, 4, v1->NbTimeStep, scale,
	       min->VQ, &min->NbVQ, mid->VQ, &mid->NbVQ, max->VQ, &max->NbVQ);
  eigenvectors(v1->TS, v1->NbTS, 4, v1->NbTimeStep, scale,
	       min->VS, &min->NbVS, mid->VS, &mid->NbVS, max->VS, &max->NbVS);
  eigenvectors(v1->TH, v1->NbTH, 8, v1->NbTimeStep, scale,
	       min->VH, &min->NbVH, mid->VH, &mid->NbVH, max->VH, &max->NbVH);
  eigenvectors(v1->TI, v1->NbTI, 6, v1->NbTimeStep, scale,
	       min->VI, &min->NbVI, mid->VI, &mid->NbVI, max->VI, &max->NbVI);
  eigenvectors(v1->TY, v1->NbTY, 5, v1->NbTimeStep, scale,
	       min->VY, &min->NbVY, mid->VY, &mid->NbVY, max->VY, &max->NbVY);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++){
    List_Add(min->Time, List_Pointer(v1->Time, i));
    List_Add(mid->Time, List_Pointer(v1->Time, i));
    List_Add(max->Time, List_Pointer(v1->Time, i));
  }
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_MinEigenvectors", v1->Name);
  sprintf(filename, "%s_MinEigenvectors.pos", v1->Name);
  EndView(min, 1, filename, name);
  sprintf(name, "%s_MidEigenvector", v1->Name);
  sprintf(filename, "%s_MidEigenvectors.pos", v1->Name);
  EndView(mid, 1, filename, name);
  sprintf(name, "%s_MaxEigenvector", v1->Name);
  sprintf(filename, "%s_MaxEigenvectors.pos", v1->Name);
  EndView(max, 1, filename, name);

  return NULL;
}
