// $Id: Lambda2.cpp,v 1.3 2004-12-07 04:52:27 geuzaine Exp $
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
#include "Lambda2.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include <algorithm>
#include <functional>
#include <math.h>
#include <stdio.h>

extern Context_T CTX;

StringXNumber Lambda2Options_Number[] = {
  {GMSH_FULLRC, "Eigenvalue", NULL, 2.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterLambda2Plugin()
  {
    return new GMSH_Lambda2Plugin();
  }
}

GMSH_Lambda2Plugin::GMSH_Lambda2Plugin()
{
  ;
}

void GMSH_Lambda2Plugin::getName(char *name) const
{
  strcpy(name, "Lambda2");
}

void GMSH_Lambda2Plugin::getInfos(char *author, char *copyright,
				   char *help_text) const
{
  strcpy(author, "E. Marchandise");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Lambda2) computes\n"
	 "the  eigenvalues Lambda (1,2,3)\n"
	 "of the tensor S_ik S_kj + Om_ik Om_kj,\n"
	 "where S_ij = 0.5 (ui,j + uj,i)) and\n"
	 "Om_ij = 0.5 (ui,j - uj,i) are respectively\n"
	 "the symmetric and antisymmetric parts\n"
	 "of the velocity gradient tensor.\n"
	 "Vortices are well-represented by regions\n"
	 "where Lambda (2) is negative.\n"
	 "If `iView' < 0, the plugin is run\n"
	 "on the current view.\n"
	 "\n"
	 "Plugin(Lambda2) creates one noew view.\n");
}

int GMSH_Lambda2Plugin::getNbOptions() const
{
  return sizeof(Lambda2Options_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_Lambda2Plugin::getOption(int iopt)
{
  return &Lambda2Options_Number[iopt];
}

void GMSH_Lambda2Plugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Lambda2 failed...");
}

static void eigen(List_T *inList, int inNb, 
		  List_T *outListScalar, int *outNbScalar,
		  int nbTime, int nbNod, int nbComp, int lam)
{
  if(!inNb)
    return;
  
  int outNbComp, *outNb;
  List_T *outList;
  
  outNbComp = 1;
  outNb = outNbScalar;
  outList = outListScalar;
  
  int nb = List_Nbr(inList) / inNb;
  
  //boucle sur les elements
  //-----------------------
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(outList, List_Pointer_Fast(inList, i + j));
    
    for(int j = 0; j < nbTime; j++){
      
      double *v = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
					      nbNod * nbComp * j + nbComp * 0);
      double GradVel[3][3];
      GradVel[0][0] = v[0]; GradVel[0][1] = v[1]; GradVel[0][2] = v[2];
      GradVel[1][0] = v[3]; GradVel[1][1] = v[4]; GradVel[1][2] = v[5];
      GradVel[2][0] = v[6]; GradVel[2][1] = v[7]; GradVel[2][2] = v[8];
      
      //par element
      //------------
      
      //calcul partie sym et antisymetrique
      double sym[3][3];
      double asym[3][3];
      for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
          sym[i][j]  = 0.5*(GradVel[i][j]+GradVel[j][i]);
          asym[i][j] = 0.5*(GradVel[i][j]-GradVel[j][i]);
        }
      }
      double a[3][3];
      for(int i=0; i<3; i++)
        for(int j=0; j<3; j++){
          a[i][j] = 0.0;
          for(int k=0; k<3; k++)
            a[i][j] += sym[i][k]*sym[k][j] + asym[i][k]*asym[k][j];
        }
      
      //calcul de lambda avec tri
      double lambda[3];
      eigenvalue(a, lambda);
      
      double res;
      for(int k = 0; k < nbNod; k++){
        for(int l = 0; l < outNbComp; l++){
	  res = lambda[lam-1];
	  List_Add(outList, &res);
	}
      }
    }
    (*outNb)++;
  }
}

Post_View *GMSH_Lambda2Plugin::execute(Post_View * v)
{
  int ev = (int)Lambda2Options_Number[0].def;
  int iView = (int)Lambda2Options_Number[1].def;
  
  if(iView < 0)
    iView = v ? v->Index : 0;
  
  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);  
  Post_View *v2 = BeginView(1);

  eigen(v1->TT, v1->NbTT, v2->ST, &v2->NbSS, v1->NbTimeStep, 3, 9, ev);
  eigen(v1->TS, v1->NbTS, v2->SS, &v2->NbSS, v1->NbTimeStep, 4, 9, ev);
  
  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_Extract", v1->Name);
  sprintf(filename, "%s_Extract.pos", v1->Name);
  EndView(v2, 1, filename, name);
  return v2;
}
