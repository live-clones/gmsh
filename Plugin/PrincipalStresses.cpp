// $Id: PrincipalStresses.cpp,v 1.5 2004-12-08 16:56:47 geuzaine Exp $
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
#include "PrincipalStresses.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber PrincipalStressesOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterPrincipalStressesPlugin()
  {
    return new GMSH_PrincipalStressesPlugin();
  }
}

GMSH_PrincipalStressesPlugin::GMSH_PrincipalStressesPlugin()
{
  ;
}

void GMSH_PrincipalStressesPlugin::getName(char *name) const
{
  strcpy(name, "Principal Stresses");
}

void GMSH_PrincipalStressesPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(PrincipalStresses) computes the min,\n"
	 "mid and max principal stresses from the tensor\n"
	 "view `iView'. If `iView' < 0, the plugin is run on\n"
	 "the current view.\n"
	 "\n"
	 "Plugin(PrincipalStresses) creates three new\n"
	 "views.\n");
}

int GMSH_PrincipalStressesPlugin::getNbOptions() const
{
  return sizeof(PrincipalStressesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_PrincipalStressesPlugin::getOption(int iopt)
{
  return &PrincipalStressesOptions_Number[iopt];
}

void GMSH_PrincipalStressesPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "PrincipalStresses failed...");
}

static int nonzero(double v[3])
{
  for(int i = 0; i < 3; i++)
    if(fabs(v[i]) > 1.e-15) return 1;
  return 0;
}

static void principal_stresses(List_T *inList, int inNb, int nbNod, int nbTime,
			       List_T *minList, int *minNb, 
			       List_T *midList, int *midNb, 
			       List_T *maxList, int *maxNb)
{
  if(!inNb) return;

  int itmp[3], nbcomplex = 0;
  double wr[3], wi[3], dtmp[3];
  double **A = new double*[3];
  double **B = new double*[3];
  for(int i = 0; i < 3; i++){
    A[i] = new double[3];
    B[i] = new double[3];
  }

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
	A[0][0] = val[0]; A[0][1] = val[1]; A[0][2] = val[2];
	A[1][0] = val[3]; A[1][1] = val[4]; A[1][2] = val[5];
	A[2][0] = val[6]; A[2][1] = val[7]; A[2][2] = val[8];
	EigSolve(3, A, wr, wi, B, itmp, dtmp);
	EigSort(3, wr, wi, B);
	nbcomplex += nonzero(wi); 
	//printf("djf=%g %g %g\n", wr[0], wr[1], wr[2]);
	//printf("vec1=%g %g %g\n", B[0][0], B[1][0], B[2][0]);
	//printf("vec1=%g %g %g\n", B[0][1], B[1][1], B[2][1]);
	//printf("vec1=%g %g %g\n", B[0][2], B[1][2], B[2][2]);
	for(int l = 0; l < 3; l++){
	  double res;
	  // wrong if there are complex eigenvals (B contains both
	  // real and imag parts: cf. explanation in EigSolve.cpp)
	  res = wr[0] * B[l][0]; List_Add(minList, &res);
	  res = wr[1] * B[l][1]; List_Add(midList, &res);
	  res = wr[2] * B[l][2]; List_Add(maxList, &res);
	}
      }
    }
    (*minNb)++;
    (*midNb)++;
    (*maxNb)++;
  }

  for(int i = 0; i < 3; i++){
    delete [] A[i];
    delete [] B[i];
  }
  delete [] A;
  delete [] B;

  if(nbcomplex)
    Msg(GERROR, "%d tensors have complex eigenvalues/eigenvectors", nbcomplex);
}

Post_View *GMSH_PrincipalStressesPlugin::execute(Post_View * v)
{
  int iView = (int)PrincipalStressesOptions_Number[0].def;

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

  principal_stresses(v1->TP, v1->NbTP, 1, v1->NbTimeStep,
 		     min->VP, &min->NbVP, mid->VP, &mid->NbVP, max->VP, &max->NbVP);
  principal_stresses(v1->TL, v1->NbTL, 2, v1->NbTimeStep,
		     min->VL, &min->NbVL, mid->VL, &mid->NbVL, max->VL, &max->NbVL);
  principal_stresses(v1->TT, v1->NbTT, 3, v1->NbTimeStep,
		     min->VT, &min->NbVT, mid->VT, &mid->NbVT, max->VT, &max->NbVT);
  principal_stresses(v1->TQ, v1->NbTQ, 4, v1->NbTimeStep,
		     min->VQ, &min->NbVQ, mid->VQ, &mid->NbVQ, max->VQ, &max->NbVQ);
  principal_stresses(v1->TS, v1->NbTS, 4, v1->NbTimeStep,
		     min->VS, &min->NbVS, mid->VS, &mid->NbVS, max->VS, &max->NbVS);
  principal_stresses(v1->TH, v1->NbTH, 8, v1->NbTimeStep,
		     min->VH, &min->NbVH, mid->VH, &mid->NbVH, max->VH, &max->NbVH);
  principal_stresses(v1->TI, v1->NbTI, 6, v1->NbTimeStep,
		     min->VI, &min->NbVI, mid->VI, &mid->NbVI, max->VI, &max->NbVI);
  principal_stresses(v1->TY, v1->NbTY, 5, v1->NbTimeStep,
		     min->VY, &min->NbVY, mid->VY, &mid->NbVY, max->VY, &max->NbVY);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++){
    List_Add(min->Time, List_Pointer(v1->Time, i));
    List_Add(mid->Time, List_Pointer(v1->Time, i));
    List_Add(max->Time, List_Pointer(v1->Time, i));
  }
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_MinPrincipalStress", v1->Name);
  sprintf(filename, "%s_MinPrincipalStress.pos", v1->Name);
  EndView(min, 1, filename, name);
  sprintf(name, "%s_MidPrincipalStress", v1->Name);
  sprintf(filename, "%s_MidPrincipalStress.pos", v1->Name);
  EndView(mid, 1, filename, name);
  sprintf(name, "%s_MaxPrincipalStress", v1->Name);
  sprintf(filename, "%s_MaxPrincipalStress.pos", v1->Name);
  EndView(max, 1, filename, name);

  return NULL;
}
