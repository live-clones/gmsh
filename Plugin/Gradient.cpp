// $Id: Gradient.cpp,v 1.2 2004-11-26 16:16:39 geuzaine Exp $
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
#include "Gradient.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include <algorithm>
#include <functional>
#include <math.h>
#include <stdio.h>

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

int GMSH_GradientPlugin::getNbOptions() const
{
  return sizeof(GradientOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_GradientPlugin::getOption(int iopt)
{
  return &GradientOptions_Number[iopt];
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
  strcpy(author, "E. Marchandise");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Gradient) computes XXX\n"
	 "If `iView' < 0, the plugin is run\n"
	 "on the current view.\n"
	 "\n"
	 "Plugin(Gradient) creates one new view.\n");
}

void GMSH_GradientPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Gradient failed...");
}

static void computeGradient(List_T *inList, int inNb, 
			    List_T *outListVector, int *outNbVector, 
			    int nbTime, int nbNod, int nbComp)
{
  if(!inNb)
    return;
  
  int outNbComp, *outNb;
  List_T *outList;
  
  outNbComp = 1;
  outNb = outNbVector;
  outList = outListVector;

  int MAX_NOD = 4; 
  int MAX_COMP= 3;

  int nb = List_Nbr(inList) / inNb;
  
  // on parcourt les elements
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    
    double *yy = (double *)List_Pointer_Fast(inList, i + nbNod);
  
    if(yy[0] > 0){
      for(int j = 0; j < 3 * nbNod; j++)
	List_Add(outList, List_Pointer_Fast(inList, i + j));
      
      for(int t = 0; t < nbTime; t++){
	
	//on lit vecteurs positions et vitesses
	//-------------------------------------
	double *x = (double *)List_Pointer_Fast(inList, i);
	double *y = (double *)List_Pointer_Fast(inList, i + nbNod);
	double *z = (double *)List_Pointer_Fast(inList, i + 2 * nbNod);
	double val[MAX_COMP][MAX_NOD];
	for(int k = 0; k < nbNod; k++){
	  double *v = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
						  nbNod * nbComp * t + nbComp * k);
	  for(int l = 0; l < nbComp; l++){
	    val[l][k] = v[l];
	  }
	}
	
	//on calcule le gradient des fonctions de forme
	//---------------------------------------------
	double GradPhi_x[4][3];
	double GradPhi_ksi[4][3];
	double dx_dksi[3][3];
	double dksi_dx[3][3];
	double det;
	
	//triangles  
	//+++++++++  
	if (nbNod == 3){
	  double a[3], b[3], cross[3];
	  a[0]= x[1]-x[0]; a[1]= y[1]-y[0]; a[2]= z[1]-z[0];
	  b[0]= x[2]-x[0]; b[1]= y[2]-y[0]; b[2]= z[2]-z[0];
	  prodve(a, b, cross);
	  dx_dksi[0][0] = x[1] - x[0]; dx_dksi[0][1] = x[2]-x[0]; dx_dksi[0][2] = cross[0];
	  dx_dksi[1][0] = y[1] - y[0]; dx_dksi[1][1] = y[2]-y[0]; dx_dksi[1][2] = cross[1];
	  dx_dksi[2][0] = z[1] - z[0]; dx_dksi[2][1] = z[2]-z[0]; dx_dksi[2][2] = cross[2];
	  inv3x3(dx_dksi, dksi_dx, &det);
	  
	  GradPhi_ksi[0][0]= -1;  GradPhi_ksi[0][1]= -1;  GradPhi_ksi[0][2]= 0;  
	  GradPhi_ksi[1][0]=  1;  GradPhi_ksi[1][1]=  0;  GradPhi_ksi[1][2]= 0;
	  GradPhi_ksi[2][0]=  0;  GradPhi_ksi[2][1]=  1;  GradPhi_ksi[2][2]= 0;
	}
	
	//tetraedre
	//++++++++++
	if (nbNod == 4){
	  dx_dksi[0][0] = x[1] - x[0]; dx_dksi[0][1] = x[2]-x[0]; dx_dksi[0][2] = x[3]-x[0];
	  dx_dksi[1][0] = y[1] - y[0]; dx_dksi[1][1] = y[2]-y[0]; dx_dksi[1][2] = y[3]-y[0];
	  dx_dksi[2][0] = z[1] - z[0]; dx_dksi[2][1] = z[2]-z[0]; dx_dksi[2][2] = z[3]-z[0];   
	  inv3x3(dx_dksi, dksi_dx, &det);
	  GradPhi_ksi[0][0]= -1;  GradPhi_ksi[0][1]= -1; GradPhi_ksi[0][2]= -1; 
	  GradPhi_ksi[1][0]=  1;  GradPhi_ksi[1][1]=  0; GradPhi_ksi[1][2]=  0; 
	  GradPhi_ksi[2][0]=  0;  GradPhi_ksi[2][1]=  1; GradPhi_ksi[2][2]=  0; 
	  GradPhi_ksi[3][0]=  0;  GradPhi_ksi[3][1]=  0; GradPhi_ksi[3][2]=  1; 
	}
	
	for(int k = 0; k < nbNod ; k++){
	  for(int l = 0; l < 3; l++){
	    GradPhi_x[k][l] = 0.0;
	    for(int m = 0; m < 3; m++){
	      GradPhi_x[k][l] += GradPhi_ksi[k][m] * dksi_dx[l][m];
	    }
	  }
	}
	
	//on calcule le gradient des vitesses
	//----------------------------------
	
	//par noeud on a max 9 composantes
	double res, grad[3][3], sym[3][3], asym[3][3];
	//    for(int l = outNbComp; l < 9; l++)
	//      d[l] = 0.0;
	for(int k = 0; k < nbComp; k++){
	  for(int l = 0; l < 3; l++){
	    grad[k][l] = 0.0;
	    for(int m = 0; m < nbNod; m++){
	      grad[k][l] +=  val[k][m]* GradPhi_x[m][l];
	    }
	  }
	}
	
	for(int k=0; k<nbComp; k++){
	  for(int l=0; l<3; l++){
	    sym[k][l]  = 0.5*(grad[k][l]+grad[l][k]);
	    asym[k][l] = 0.5*(grad[k][l]-grad[l][k]);
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
	
	for(int k = 0; k < nbNod; k++){
	  for(int l = 0; l < outNbComp; l++){
	    res = lambda[1];
	    List_Add(outList, &res);
	  }
	}  
      }
      (*outNb)++;
    }
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

  // points
  //--------
  //  computeGradient( v1->SP, v1->NbSP,  v2->VP, &v2->NbVP, v1->NbTimeStep, 1, 1);
  //  computeGradient( v1->VP, v1->NbVP,  v2->TP, &v2->NbTP, v1->NbTimeStep, 1, 3);
  
  // lines
  //-------			                                  
  // computeGradient( v1->SL, v1->NbSL,  v2->VL, &v2->NbVL, v1->NbTimeStep, 2, 1);
  // computeGradient( v1->VL, v1->NbVL,  v2->TL, &v2->NbTL, v1->NbTimeStep, 2, 3);
  
  // triangles			                                  
  //------------
  //  computeGradient( v1->ST, v1->NbST,  v2->VT, &v2->NbVT, v1->NbTimeStep, 3, 1);
  //  computeGradient( v1->VT, v1->NbVT,  v2->TT, &v2->NbTT, v1->NbTimeStep, 3, 3);

  // tets
  //------			                                  
  //  computeGradient( v1->SS, v1->NbSS,  v2->VS, &v2->NbVS, v1->NbTimeStep, 4, 1);
  computeGradient( v1->VS, v1->NbVS,  v2->SS, &v2->NbSS, v1->NbTimeStep, 4, 3);
  
  /*
  // quadrangles		                                  
  //-----------
  computeGradient( v1->SQ, v1->NbSQ,  v2->VQ, &v2->NbVQ, v1->NbTimeStep, 4, 1);
  computeGradient( v1->VQ, v1->NbVQ,  v2->VQ, &v2->NbVQ, v1->NbTimeStep, 4, 3);
  computeGradient( v1->TQ, v1->NbTQ,  v2->VQ, &v2->NbVQ, v1->NbTimeStep, 4, 9);
  // hexas
  //--------			                                  
  computeGradient( v1->SH, v1->NbSH,  v2->VH, &v2->NbVH, v1->NbTimeStep, 8, 1);
  computeGradient( v1->VH, v1->NbVH,  v2->VH, &v2->NbVH, v1->NbTimeStep, 8, 3);
  computeGradient( v1->TH, v1->NbTH,  v2->VH, &v2->NbVH, v1->NbTimeStep, 8, 9);
  // prisms			                                  
  //--------
  computeGradient( v1->SI, v1->NbSI,  v2->VI, &v2->NbVI, v1->NbTimeStep, 6, 1);
  computeGradient( v1->VI, v1->NbVI,  v2->VI, &v2->NbVI, v1->NbTimeStep, 6, 3);
  computeGradient( v1->TI, v1->NbTI,  v2->VI, &v2->NbVI, v1->NbTimeStep, 6, 9);
  // pyramids
  //----------			                                  
  computeGradient( v1->SY, v1->NbSY,  v2->VY, &v2->NbVY, v1->NbTimeStep, 5, 1);
  computeGradient( v1->VY, v1->NbVY,  v2->VY, &v2->NbVY, v1->NbTimeStep, 5, 3);
  computeGradient( v1->TY, v1->NbTY,  v2->VY, &v2->NbVY, v1->NbTimeStep, 5, 9);
  */
  
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
